#include <geometry_msgs/Pose.h>
#include <nav_msgs/OccupancyGrid.h>
#include <turtlebot_2dnav/restrictCostmap.h>
#include <turtlebot_2dnav/fake_bound.h>
#include <turtlebot_2dnav/recalculateBound.h>
#include <ros/ros.h>



class CostmapRes
{
  public:
    CostmapRes();
    void ProcessCostmap();

  private:
    ros::NodeHandle nh;
    ros::NodeHandle n;
    ros::Subscriber costmap_sub_;
    ros::ServiceServer restrict_server;
    ros::ServiceServer recalculate_server;
    ros::Publisher bound_pub;

    struct Bound
    {
      geometry_msgs::Point point_left_min;
      geometry_msgs::Point point_right_min;
      geometry_msgs::Point point_left_max;
      geometry_msgs::Point point_right_max;
      geometry_msgs::Point center_point;

      bool vertical;
      int count = 0;
      int size_count = 0;
      int index = -1;
      //in case that the bound give as center a
      int center_LETHAL = 1;
      bool matched = false;
      bool recalculateleft = true;
      bool recalculateright = true;
      bool exit = false;

      bool center_found = false;

      //bounds can be restriction or just checks (persons)
      bool restriction = true;
    };



    bool RestrictService(turtlebot_2dnav::restrictCostmap::Request &req,
                                turtlebot_2dnav::restrictCostmap::Response &res);
    bool RecalculateService (turtlebot_2dnav::recalculateBound::Request &req,
                         turtlebot_2dnav::recalculateBound::Response &res);

    unsigned int getIndex(geometry_msgs::Point point);
    geometry_msgs::Point indexToCostmap(unsigned int index);
    geometry_msgs::Point CostmapToMap(geometry_msgs::Point point);
    geometry_msgs::Point MapToCostmap(geometry_msgs::Point point);
    void ProcessCostmap(const nav_msgs::OccupancyGrid::ConstPtr& msg);
    int findInCostmap(bool obstacle, const nav_msgs::OccupancyGrid::ConstPtr& msg,
                                  geometry_msgs::Point costmap_coords, int max_count,
                                  bool perpendicular, bool positiveDirection);

    bool checkifCorner(geometry_msgs::Point costmap_coords, const nav_msgs::OccupancyGrid::ConstPtr& msg, bool positiveDirection, int n_points);
    bool needUpdate(geometry_msgs::Point l_min, geometry_msgs::Point l_max, geometry_msgs::Point r_min, geometry_msgs::Point r_max);
    bool isEqual(geometry_msgs::Point p1, geometry_msgs::Point p2);
    bool matchBound(const nav_msgs::OccupancyGrid::ConstPtr& msg);
    void resetBound(Bound &actual_bound);


    Bound restringed_zone;
    std::vector<Bound> queue;
    std::vector<Bound> recalculatequeue;
    turtlebot_2dnav::fake_bound bound_;

    unsigned char value;

    int index = 0;

    bool canRecalculate = false;
    unsigned int size_in_cells_x;
    unsigned int size_in_cells_y;
    double resolution = 0.095;
    double origin_x;
    double origin_y;
    unsigned char* costmap_data;

    bool unknown_limit = false;
    bool center_found;

    //add all of this as a parameter?
    int max_count_findPerpendicularObstacle = 0.5 / resolution;
    int max_count_findParalelObstacle = 5 / resolution;
    int max_count_findLimits = 15;
    int min_count_size = 0.8 / resolution;

    int max_iteration = 10;

    int waiting = 0;
    int wait_count = 5;

    // special values:
    unsigned char NO_OBSTACLE = 0; // NO obstacle
    unsigned char INSCRIBED_OBSTACLE = 99;   // INSCRIBED obstacle
    unsigned char LETHAL_OBSTACLE = 100;  // LETHAL obstacle
    unsigned char UNKNOWN = -1;  // UNKNOWN


};
