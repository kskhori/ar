#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sample_c/sample_message.h"

#include "visualization_msgs/Marker.h"

void chatterCallback(const visualization_msgs::Marker &msg){
  // 受信したデータを出力する
  ROS_INFO("I heard: message = [%f], count = []", msg.pose.position.z);
}

int main(int argc, char **argv) {
  // 初期化し、ノードの名前を"sample_c_subscriber"とする
  ros::init(argc, argv, "sample_c_subscriber");
  ros::NodeHandle n;
  // "sample_topic"というトピックからデータを受信する
  //ros::Subscriber subscriber = n.subscribe("sample_topic", 1000, chatterCallback);
  ros::Subscriber subscriber = n.subscribe("visualization_marker", 1000, chatterCallback);

  ros::spin();

  return 0;
}

