#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sample_c/sample_message.h"  // 生成したメッセージのヘッダファイル
#include <sstream>

#include "geometry_msgs/Twist.h"
#include "visualization_msgs/Marker.h"


void chatterCallback(const visualization_msgs::Marker &msg){

  ros::NodeHandle n;


  ros::Subscriber subscriber = n.subscribe("visualization_marker", 1, chatterCallback, this);
  // 受信したデータを出力する
  ROS_INFO("I heard: message = [%f]", msg.pose.position.z);
  ros::Publisher publisher = n.advertise<geometry_msgs::Twist>("cmd_vel", 1000);

  // 1秒間に10回データを送信する
  ros::Rate loop_rate(10);

  // 送信するメッセージの作成
  geometry_msgs::Twist twist;
  twist.linear.x = 0.0;
  twist.linear.y = 0.0;
  twist.linear.z = 0.0;
  twist.angular.x = 0.0;
  twist.angular.y = 0.0;
  twist.angular.z = 0.0;

  if (msg.pose.position.z > 0.5){
   twist.linear.x = 0.2;
  }

  publisher.publish(twist);
}


int main(int argc, char **argv) {
  // 初期化し、ノードの名前を"sample_c_publisher"とする
  ros::init(argc, argv, "sample_c_publisher");
   ros::spin();

  return 0;
}

