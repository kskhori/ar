#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sample_c/sample_message.h"
#include <sstream>

#include "geometry_msgs/Twist.h"
#include "std_msgs/Int32.h"
#include "std_msgs/Float64.h"
#include "trajectory_msgs/JointTrajectory.h"
#include "trajectory_msgs/JointTrajectoryPoint.h"
#include "visualization_msgs/Marker.h"


class vel_cal{
 public:
  vel_cal();
  ~vel_cal();
  void chatterCallback(const std_msgs::Int32& marker);
  void MoveVector(float linear_x, int cnt);
  void timerCallback(const ros::TimerEvent&);

 private:
  ros::Publisher twist_pub;
  ros::Subscriber marker_sub;
  ros::NodeHandle nh;
};

 vel_cal::vel_cal(){
//  twist_pub = nh.advertise<geometry_msgs::Twist>("cmd_vel", 1000);
  twist_pub = nh.advertise<trajectory_msgs::JointTrajectory>("seed_controller/command", 1000);
  marker_sub = nh.subscribe("thk_slider_des", 1, &vel_cal::chatterCallback, this);

  trajectory_msgs::JointTrajectory twist;
// std::vector<trajectory_msgs::msg::JointTrajectoryPoint> points;

  std_msgs::Int32 marker;

//  twist.linear.x = 0.0;

//  twist_pub.publish(twist);
 }

 vel_cal::~vel_cal(){
 }

 void vel_cal::chatterCallback(const std_msgs::Int32& marker){


  std::stringstream ss;
  int i, cnt;
  cnt = 100;

  trajectory_msgs::JointTrajectory twist;
  ros::Rate loop_rate(1000);
  
  for(i = 0; i < cnt; i++){
   twist.header.seq = cnt;

   ROS_INFO("I heard: message = [%d]", marker.data);
   twist.points.resize(1);
   twist.points[0].positions.resize(1);

   twist.joint_names = {"THK_PCS9S330"};
   float des = float(marker.data/26400000.0*330.0);
   twist.points[0].positions[0] = des;
   twist.points[0].time_from_start = ros::Duration(0.2);
  }

   twist_pub.publish(twist);
   loop_rate.sleep();
  
 }

int main(int argc, char **argv) {
  ros::init(argc, argv, "seed_command_publisher2");
  vel_cal vel_cal;
  ros::spin();

  return 0;
}

