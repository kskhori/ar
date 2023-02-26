#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sample_c/sample_message.h"  // 生成したメッセージのヘッダファイル
#include <sstream>

#include "geometry_msgs/Twist.h"
#include "visualization_msgs/Marker.h"



class Minic{
 public:
  Minic();
 private:
  void chatterCallback(const visualization_msgs::Marker& msg);
  ros::NodeHandle nh;
  ros::Publisher twist_pub_;
  ros::Subscriber pose_sub_;
};

Minic::Minic(){

  twist_pub_ = nh.advertise<geometry_msgs::Twist>("cmd_vel", 1000);
  pose_sub_ = nh.subscribe<visualization_msgs::Marker>("visualization_marker", 1000, &Minic::chatterCallback, this);
}



void Minic::chatterCallback(const visualization_msgs::Marker& msg){
  geometry_msgs::Twist twist;
  twist.linear.x = 0.2;
  twist_pub_.publish(twist);
}


int main(int argc, char **argv) {
  // 初期化し、ノードの名前を"sample_c_publisher"とする
  ros::init(argc, argv, "sample_c_publisher");
  Minic Minic();
  ros::spin();
}

