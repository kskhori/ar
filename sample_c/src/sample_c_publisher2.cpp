#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sample_c/sample_message.h"  // 生成したメッセージのヘッダファイル
#include <sstream>

int main(int argc, char **argv) {
  // 初期化し、ノードの名前を"sample_c_publisher"とする
  ros::init(argc, argv, "sample_c_publisher");
  ros::NodeHandle n;
  // メッセージを"sample_topic"というトピックに送信する
  ros::Publisher publisher = n.advertise<sample_c::sample_message>("sample_topic", 1000);
  // 1秒間に2回データを送信する
  ros::Rate loop_rate(2);

  int count = 0;
  while (ros::ok()) {
    std::stringstream ss;
    ss << "hello world " << count;
    ROS_INFO("message = %s, count = %d", ss.str().c_str(), count);

    // 送信するメッセージの作成
    sample_c::sample_message msg;
    msg.message = ss.str();
    msg.count = count;

    // 送信
    publisher.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }

  return 0;
}

