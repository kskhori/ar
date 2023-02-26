#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sample_c/sample_message.h"  // 生成したメッセージのヘッダファイル
#include <sstream>

#include "geometry_msgs/Twist.h"

int main(int argc, char **argv) {
  // 初期化し、ノードの名前を"sample_c_publisher"とする
  ros::init(argc, argv, "sample_c_publisher");
  ros::NodeHandle n;
  // メッセージ(geometry_msgs/Twist)を"cmd_vel"というトピックに送信する
  ros::Publisher publisher = n.advertise<geometry_msgs::Twist>("cmd_vel", 1000);
  // 1秒間に10回データを送信する
  ros::Rate loop_rate(10);

  while (ros::ok()) {
    // 送信するメッセージの作成
    geometry_msgs::Twist msg;
    msg.linear.x = 0.2;
    // 送信
    publisher.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
  }

  return 0;
}

