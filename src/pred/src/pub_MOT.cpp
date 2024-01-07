/*
代替MOT，作离线测试;
发布MOT结果
*/

#include "ros/ros.h"
#include "custom_msgs/MOT.h"
#include <cstdlib> // For rand()


int main(int argc, char **argv) {
    ros::init(argc, argv, "pub_MOT");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<custom_msgs::MOT>("pub_MOT", 10);
    ros::Rate loop_rate(20);  // 设置发布频率为20Hz

    while (ros::ok()) {
        custom_msgs::MOT msg;
        // msg.timestamp = ros::Time::now().toSec();
        int num = rand()%10;

        std_msgs::Float32MultiArray sub_array_msg;
        std::vector<float> sub_array_data;

        for (int j = 0; j < num; j ++) {
            float posx = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
            float posy = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
            int id = rand() % 10;
            int size = num;

            sub_array_data.push_back(posx);
            sub_array_data.push_back(posy);
            sub_array_data.push_back(id);
            // sub_array_data.push_back(size);
            sub_array_msg.data = sub_array_data;
            
        }
        msg.num = num;
        msg.array.push_back(sub_array_msg);
        msg.header.stamp = ros::Time::now(); // 设置消息头时间戳为当前时间
        msg.header.frame_id = "pub_dataset"; // 设置消息头的坐标系名称

        pub.publish(msg);
        loop_rate.sleep();
    }

    return 0;
}
