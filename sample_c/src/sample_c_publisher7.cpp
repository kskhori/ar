#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sample_c/sample_message.h"
#include <sstream>

#include "geometry_msgs/Twist.h"
#include "visualization_msgs/Marker.h"


class vel_cal{
 public:
  vel_cal();
  ~vel_cal();
  void chatterCallback(const visualization_msgs::Marker& marker);
  void MoveVector(float linear_x, int cnt);
  void timerCallback(const ros::TimerEvent&);

 private:
  ros::Publisher twist_pub;
  ros::Subscriber marker_sub;
  ros::Timer timer;
  ros::NodeHandle nh;
};


 vel_cal::vel_cal(){
  twist_pub = nh.advertise<geometry_msgs::Twist>("cmd_vel", 1000);
  marker_sub = nh.subscribe("visualization_marker", 1, &vel_cal::chatterCallback, this);

  timer = nh.createTimer(ros::Duration(0.1), &vel_cal::timerCallback, this);

  geometry_msgs::Twist twist;
  visualization_msgs::Marker marker;

  twist.linear.x = marker.pose.position.z;
  twist.linear.y = 0.0;
  twist.linear.z = 0.0;
  twist.angular.x = 0.0;
  twist.angular.y = 0.0;
  twist.angular.z = 0.0;

  
  twist_pub.publish(twist);
 }

 vel_cal::~vel_cal(){

 }


 void vel_cal::chatterCallback(const visualization_msgs::Marker& marker){
  ROS_INFO("I heard: message = [%f]", marker.pose.position.z);

  int i, cnt;
  float a;
  a = marker.pose.position.z;
  cnt = 10;

  geometry_msgs::Twist twist;
  ros::Rate loop_rate(10);
  
  for(i = 0; i < cnt; i++){
   twist.linear.x = a;
   twist_pub.publish(twist);
   loop_rate.sleep();
  }
 }



 void vel_cal::timerCallback(const ros::TimerEvent&){
  const visualization_msgs::Marker marker;
  //MoveVector(0.2, 10);

 }


 void vel_cal::MoveVector(float linear_z, int cnt){
  int i;
  geometry_msgs::Twist twist;
  ros::Rate loop_rate(10);
  
  for(i = 0; i < cnt; i++){
   twist.linear.x = linear_z;
   twist_pub.publish(twist);
   loop_rate.sleep();
  }
 }

int main(int argc, char **argv) {
  ros::init(argc, argv, "sample_c_publisher");
  vel_cal vel_cal;
  ros::spin();

  return 0;
}

