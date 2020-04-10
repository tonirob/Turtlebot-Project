#include <costmap_restrictor.h>

CostmapRes::CostmapRes() :
  nh(ros::this_node::getName())
  {
  std::string costmap_topic;
  std::string footprint_topic;
  nh.param("costmap_topic", costmap_topic, std::string("costmap"));
  restrict_server = nh.advertiseService("restrict", &CostmapRes::RestrictService, this);
  costmap_sub_ = n.subscribe(costmap_topic, 1000, &CostmapRes::ProcessCostmap, this);
  bound_pub = nh.advertise<turtlebot_2dnav::fake_bound>("fake_bound", 10);

}


void CostmapRes::ProcessCostmap(const nav_msgs::OccupancyGrid::ConstPtr& msg)
{
  size_in_cells_x = msg->info.width;
  size_in_cells_y = msg->info.height;
  resolution = msg->info.resolution;
  origin_x = msg->info.origin.position.x;
  origin_y = msg->info.origin.position.y;

  if(queue.size() > 0)
  {
    bool last_left_state = queue[0].recalculateleft;
    bool last_right_state = queue[0].recalculateright;
    //get costmap coords of center
    geometry_msgs::Point costmap_coords = MapToCostmap(queue[0].center_point);

    //findInCostmap parameters:
        // - obstacle/limit
        // - costmap ptr
        // - costmap coords
        // - max_count in the loop
        // - perpendicular / paralel
        // - left / right

    int count = 0;
    //FIND THE OBSTACLE IN COSTMAP!
    if(!queue[0].matched)
    {
      count = findInCostmap(true, msg, costmap_coords, max_count_findPerpendicularObstacle, true, true);
      if( count == max_count_findPerpendicularObstacle) count = findInCostmap(true, msg, costmap_coords, max_count_findPerpendicularObstacle, true, false);
      //reset the costmap coords of the center!
      if( count < max_count_findPerpendicularObstacle)
      {
        costmap_coords = MapToCostmap(queue[0].center_point);
        ROS_INFO("CENTER FOUND");
      }
      else ROS_INFO("CENTER NOT FOUND");
      //FIND LIMITS OF THE SELECTED OBSTACLE

      //left limit
      findInCostmap(false, msg, costmap_coords, max_count_findLimits, false, true);
      //check if corner?
      bool left_corner;
      if(queue[0].vertical)
      {
        left_corner = checkifCorner( MapToCostmap(queue[0].point_left_max), msg, true, 5);
        //try the other direction
        if (!left_corner) left_corner = checkifCorner( MapToCostmap(queue[0].point_left_max), msg, false, 5);
      }
      else
      {
        left_corner = checkifCorner( MapToCostmap(queue[0].point_left_min), msg, true, 5);
        if (!left_corner) left_corner = checkifCorner( MapToCostmap(queue[0].point_left_min), msg, false, 5);
      }
      //IF IS A CORNER DONT NEED TO RECALCULATE LIMITS!
      if (left_corner)
      {
        ROS_INFO("IS LEFT CORNER!");
        queue[0].recalculateleft = false;
        if(queue[0].vertical) queue[0].point_left_min = queue[0].point_left_max;
        else queue[0].point_left_max = queue[0].point_left_min;
      }

      //right limit
      findInCostmap(false, msg, costmap_coords, max_count_findLimits, false, false);
      //Check if corner?
      bool right_corner;
      if(queue[0].vertical)
      {
        right_corner = checkifCorner( MapToCostmap(queue[0].point_right_min), msg, true, 5);
        //try the other direction
        if (!right_corner) left_corner = checkifCorner( MapToCostmap(queue[0].point_right_min), msg, false, 5);
      }
      else
      {
        right_corner = checkifCorner( MapToCostmap(queue[0].point_right_max), msg, true, 5);
        if (!right_corner) right_corner = checkifCorner( MapToCostmap(queue[0].point_right_max), msg, false, 5);
      }
      //IF IS A CORNER DONT NEED TO RECALCULATE LIMITS!
      if (right_corner)
      {
        ROS_INFO("IS RIGHT CORNER!");
        queue[0].recalculateright = false;
        if(queue[0].vertical) queue[0].point_right_max = queue[0].point_right_min;
        else queue[0].point_right_min = queue[0].point_right_max;
      }
    }

    //FIND THE CLOSER OBSTACLE IN LEFT DIRECTION
    if(queue[0].recalculateleft)
    {
      if (queue[0].vertical)
      {
        //IF IS A RESIZE START COUNTING FROM THE LIMIT
        if(queue[0].index != -1) costmap_coords = MapToCostmap(queue[0].point_left_min);
        else costmap_coords = MapToCostmap(queue[0].point_left_max);
      }
      else
      {
        if(queue[0].index != -1) costmap_coords = MapToCostmap(queue[0].point_left_max);
        else costmap_coords = MapToCostmap(queue[0].point_left_min);
      }
      count = findInCostmap(true, msg, costmap_coords, max_count_findParalelObstacle, false, true);
      if ( count < max_count_findParalelObstacle && !unknown_limit)
      {
        queue[0].recalculateleft = false;
        ROS_INFO("NO NEED TO RECALCULATE LEFT");
      }
    }
    //FIND THE CLOSER OBSTACLE IN RIGHT DIRECTION
    if(queue[0].recalculateright)
    {
      //ROS_INFO("CALCULATING RIGHT");
      if (queue[0].vertical)
      {
        //IF IS A RESIZE START COUNTING FROM THE LIMIT
        if(queue[0].index != -1) costmap_coords = MapToCostmap(queue[0].point_right_max);
        else costmap_coords = MapToCostmap(queue[0].point_right_min);
      }
      else
      {
        if(queue[0].index != -1) costmap_coords = MapToCostmap(queue[0].point_right_min);
        else costmap_coords = MapToCostmap(queue[0].point_right_max);
      }
      count = findInCostmap(true, msg, costmap_coords, max_count_findParalelObstacle, false, false);
      if ( count < max_count_findParalelObstacle && !unknown_limit)
      {
        queue[0].recalculateright = false;
        ROS_INFO("NO NEED TO RECALCULATE RIGHT");
      }
    }

    bound_.index = queue[0].index;
    bound_.pointleftmin = queue[0].point_left_min;
    bound_.pointleftmax = queue[0].point_left_max;
    bound_.pointrightmin = queue[0].point_right_min;
    bound_.pointrightmax = queue[0].point_right_max;
    bound_.isvertical = queue[0].vertical;

    //IF FIRST PROCESS
    if (queue[0].index  == -1)
    {
      queue[0].index = index;
      bound_.index = queue[0].index;
      bound_.resize = false;
      bound_pub.publish(bound_);
      index++;
    }

    //IF ANY UPDATE ON ONE SIDES (and not first time) PUBLISH
    else if( (last_left_state && !queue[0].recalculateleft) || (last_right_state && !queue[0].recalculateright) )
    {
      ROS_INFO("PUBLISHING UPDATE!");
      bound_.resize = true;
      bound_pub.publish(bound_);
    }

    if (queue[0].recalculateleft || queue[0].recalculateright) std::rotate(queue.begin(), queue.begin() + 1, queue.end());
    else queue.erase( queue.begin() );
  }
}


bool CostmapRes::RestrictService(turtlebot_2dnav::restrictCostmap::Request &req,
                                        turtlebot_2dnav::restrictCostmap::Response &res)
{
  //ROS_INFO("RECEIVED!");
  bound_.exit = req.exit;
  restringed_zone.vertical = req.isvertical;
  restringed_zone.center_point = req.Point;
  restringed_zone.size = req.size;

  //Number of cells for the limit search 0.5 as tolerance!
  max_count_findLimits = 15;
  queue.insert(queue.begin(), restringed_zone);
  res.received = true;
  return res.received;
}

int CostmapRes::findInCostmap(bool obstacle, const nav_msgs::OccupancyGrid::ConstPtr& msg,
                              geometry_msgs::Point costmap_coords, int max_count,
                              bool perpendicular, bool positiveDirection)
{
  //ROS_INFO("IN OBSTACLES");
  int count = 0;
  int acum = 0;
  unknown_limit = false;

  auto index_ = getIndex( costmap_coords );
  auto value = msg->data[index_];

  //in this case positive direction means (left and up)
  if (positiveDirection) acum = 1;
  else acum = -1;


  //FIND OBSTACLE (PERPENDICULAR)
  if(obstacle)
  {
    if (perpendicular)
    {
      while (value != LETHAL_OBSTACLE && count < max_count)
      {
        count++;
        if(queue[0].vertical) costmap_coords.y += acum;
        else costmap_coords.x += acum;
        index_ = getIndex(costmap_coords);
        value = msg->data[index_];
      }
      if (count < max_count)
      {
        queue[0].center_point = CostmapToMap( indexToCostmap(index_) );
        queue[0].matched = true;
        geometry_msgs::Point point1 = indexToCostmap(index_);
      }
    }

    //NOW FINDING THE CLOSER OBSTACLE AT PARALEL DIRECTION
    else
    {
      //ROS_INFO("IN");
      //ROS_INFO("value: %c",value);
      while (value != LETHAL_OBSTACLE && value != -1 && count < max_count)
      {
        count++;
        if(queue[0].vertical) costmap_coords.x -= acum;
        else costmap_coords.y += acum;
        index_ = getIndex(costmap_coords);
        value = msg->data[index_];
      }
      if (value == -1)
      {
        ROS_INFO("UNKNOWN END");
        unknown_limit = true;
        geometry_msgs::Point unkP = CostmapToMap( indexToCostmap(index_) );
        ROS_INFO("Point x: %f", unkP.x);
        ROS_INFO("Point y: %f", unkP.y);
      }
      //UPDATE THE LIMIT OF THE OBSTACLE FOUND
      if (positiveDirection)
      {
        if (queue[0].vertical) queue[0].point_left_min = CostmapToMap( indexToCostmap(index_) );
        else queue[0].point_left_max = CostmapToMap( indexToCostmap(index_) );
      }
      else
      {
        if (queue[0].vertical) queue[0].point_right_max = CostmapToMap( indexToCostmap(index_) );
        else queue[0].point_right_min = CostmapToMap( indexToCostmap(index_) );
      }
    }
  }

  //FIND LIMIT (PARALEL)
  else
  {
    while (value == LETHAL_OBSTACLE && count < max_count)
    {
      count++;
      if(queue[0].vertical) costmap_coords.x -= acum;
      else costmap_coords.y += acum;
      index_ = getIndex(costmap_coords);
      value = msg->data[index_];
    }
    if(count == max_count) ROS_INFO ("UNFINISHED OBJECT");


    //UPDATE THE LIMIT OF THE OBSTACLE FOUND
    if (positiveDirection)
    {
      if (queue[0].vertical) queue[0].point_left_max = CostmapToMap( indexToCostmap(index_) );
      else queue[0].point_left_min = CostmapToMap( indexToCostmap(index_) );
    }
    else
    {
      if (queue[0].vertical) queue[0].point_right_min = CostmapToMap( indexToCostmap(index_) );
      else queue[0].point_right_max = CostmapToMap( indexToCostmap(index_) );
    }
  }
  return count;
}

bool CostmapRes::checkifCorner(geometry_msgs::Point costmap_coords, const nav_msgs::OccupancyGrid::ConstPtr& msg, bool positiveDirection, int n_points)
{
  //SAME AS IN FIND IN COSTMAP BUT NOT MODIFYING POINTS ONLY CHECKING
  int count = 0;
  int acum = 0;
  if (positiveDirection) acum = 1;
  else acum = -1;
  auto index_ = getIndex( costmap_coords );
  auto value = msg->data[index_];
  bool corner = false;

  while (value == LETHAL_OBSTACLE && count < n_points)
  {
    count++;
    if(queue[0].vertical) costmap_coords.y += acum;
    else costmap_coords.x += acum;
    index_ = getIndex(costmap_coords);
    value = msg->data[index_];
  }
  if (count == n_points) corner = true;
  return corner;
}


geometry_msgs::Point CostmapRes::MapToCostmap(geometry_msgs::Point point)
{
  geometry_msgs::Point costmap_point;
  costmap_point.x = (int)((point.x - origin_x) / resolution);
  costmap_point.y = (int)((point.y - origin_y) / resolution);
  return costmap_point;
}

unsigned int CostmapRes::getIndex(geometry_msgs::Point point)
{
  unsigned int mx = (unsigned int) point.x;
  unsigned int my = (unsigned int) point.y;
  unsigned int index = my * size_in_cells_x + mx;
  return index;
}

geometry_msgs::Point CostmapRes::indexToCostmap(unsigned int index)
{
  geometry_msgs::Point costmap_coord;
  costmap_coord.y = index / size_in_cells_x;
  costmap_coord.x = index - (costmap_coord.y * size_in_cells_x);
  return costmap_coord;
}

geometry_msgs::Point CostmapRes::CostmapToMap(geometry_msgs::Point point)
{
  geometry_msgs::Point map_point;
  map_point.x = origin_x + (point.x + 0.5) * resolution;
  map_point.y = origin_y + (point.y + 0.5) * resolution;
  return map_point;
}