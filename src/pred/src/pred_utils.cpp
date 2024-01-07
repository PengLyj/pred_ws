# include "pred_utils.h"
# include "ros/ros.h"
# include <iostream>

//打印每帧数据对应时间
void printTimestamp(const std_msgs::Header& header) {
    ros::Time timestamp = header.stamp;

    int year = timestamp.toBoost().date().year();
    int month = timestamp.toBoost().date().month();
    int day = timestamp.toBoost().date().day();
    int hour = timestamp.toBoost().time_of_day().hours();
    int minute = timestamp.toBoost().time_of_day().minutes();
    int second = timestamp.toBoost().time_of_day().seconds();

    std::cout << "Timestamp: " << year << "/" << month << "/" << day << " " << hour << ":" << minute << ":" << second << std::endl;
}


//处理8帧数据为id,vector<x,y,timestamp>格式
void processMsg(const custom_msgs::MOT& one_frame_msg, std::map<int, std::vector<std::pair<std::pair<float, float>, ros::Time>>>& bank){
    for (const auto& item : one_frame_msg.array) {
        int num_obj = item.data.size()/3; //该帧数据包含的目标数量
        std::cout << "包含" << num_obj << " 个目标"<< std::endl;
        ros::Time timestamp = one_frame_msg.header.stamp;
        for (int j=0; j < item.data.size() ; j ){
            std::vector<float> person;
            float x = item.data[j++]; //  x
            float y = item.data[j++]; //  y
            int id = item.data[j++]; //  id

            if (bank.find(id) != bank.end()) {
                bank[id].push_back({{x, y}, timestamp});
            } else {
                bank[id] = {{{x, y}, timestamp}};
            }

        }
    }
}
