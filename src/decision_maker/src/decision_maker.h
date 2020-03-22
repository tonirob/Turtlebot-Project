#ifndef decision_maker_H
#define decision_maker_H

#include <ros/ros.h>
#include <poi_database/ROI.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <explore_lite/greedyAction.h>
#include <actionlib/client/simple_action_client.h>
#include <tf/transform_listener.h>
#include <turtlebot_2dnav/returnCost.h>

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;
typedef actionlib::SimpleActionClient<explore_lite::greedyAction> ExploreGreedyClient;

class Decision{
  public:

    Decision();

    void process();

  protected:

    ros::NodeHandle nh;
    ros::NodeHandle n;

    ros::Subscriber ROI_sub;
    ros::ServiceClient cost_client;

    tf::TransformListener listener;

    MoveBaseClient acMove;
    ExploreGreedyClient acGreedy;

    void getActualPose();

    void setGoalPose(float posx, float posy, float orientationz, float orientationw);

    void ROI_callBack(poi_database::ROI);

    void doneCb(const actionlib::SimpleClientGoalState& state);

  private:

    std::string type;

    bool new_roi_received = false;
    bool isMoving = false;

    int i = 0;

    geometry_msgs::PoseStamped actualPose;
    geometry_msgs::PoseStamped goalPose;

    move_base_msgs::MoveBaseGoal goal;
    explore_lite::greedyGoal greedy;
    turtlebot_2dnav::returnCost cost_request;

    std::vector<poi_database::ROI *> received_ROIs;
    std::vector<poi_database::ROI> database_r;
    std::vector<poi_database::ROI> database_e;
    std::vector<poi_database::ROI> database_p;
    std::vector<poi_database::ROI> *database_ptr;


};

#endif
