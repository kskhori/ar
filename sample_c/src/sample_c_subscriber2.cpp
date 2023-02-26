#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sample_c/sample_message.h"

void chatterCallback(const sample_c::sample_message &msg) {
  // 受信したデータを出力する
  ROS_INFO("I heard: message = [%s], count = [%d]", msg.message.c_str(), msg.count);
}

int main(int argc, char **argv) {
  // 初期化し、ノードの名前を"sample_c_subscriber"とする
  ros::init(argc, argv, "sample_c_subscriber");
  ros::NodeHandle n;
  // "sample_topic"というトピックからデータを受信する
  ros::Subscriber subscriber = n.subscribe("sample_topic", 1000, chatterCallback);

  ros::spin();

  return 0;
}
