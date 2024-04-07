/*
代替MOT，作离线测试;
发布MOT结果
*/

#include "ros/ros.h"
#include "custom_msgs/MOT.h"
#include <cstdlib> // For rand()
#include "custom_msgs/DetectedObject.h"
#include "custom_msgs/DetectedObjectArray.h"


int main(int argc, char **argv) {
    ros::init(argc, argv, "pub_MOT");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<custom_msgs::MOT>("pub_MOT", 10);
    ros::Publisher pub2 = nh.advertise<custom_msgs::DetectedObjectArray>("pub_MOT2", 10);

    ros::Rate loop_rate(20);  // 设置发布频率为20Hz

    while (ros::ok()) {
        custom_msgs::MOT msg;
        custom_msgs::DetectedObjectArray object_array;
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
            sub_array_msg.data = sub_array_data;

            custom_msgs::DetectedObject object;
            object.pose.position.x = posx;
            object.pose.position.y = posy;
            object.pose.position.z = 0;
            object.id = id;
            object.angle = 0;
            object.velocity = 0;
            object_array.objects.push_back(object);

            
        }
        msg.num = num;
        msg.array.push_back(sub_array_msg);
        msg.header.stamp = ros::Time::now(); // 设置消息头时间戳为当前时间
        msg.header.frame_id = "pub_dataset"; // 设置消息头的坐标系名称

        object_array.num = num;
        object_array.header.stamp = ros::Time::now();
        object_array.header.frame_id = "pub_dataset"; // 设置消息头的坐标系名称
        pub.publish(msg);
        pub2.publish(object_array);
        loop_rate.sleep();
    }

    return 0;
}
