# include "pred_utils.h"
# include "ros/ros.h"
# include <iostream>
# include <algorithm>
#include "custom_msgs/DetectedObject.h"
#include "custom_msgs/DetectedObjectArray.h"
#include "custom_msgs/TrajPredArray.h"
#include "custom_msgs/TrajPredSingle.h"


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

//处理8帧数据为id,vector<x,y,timestamp>格式
void processMsg2(const custom_msgs::DetectedObjectArray& one_frame_msg, std::map<int, std::vector<std::pair<std::pair<float, float>, ros::Time>>>& bank){
    int num_obj = 0 ;
    for (const auto& item : one_frame_msg.objects) {    // 该帧的单个目标
        ros::Time timestamp = one_frame_msg.header.stamp;

        std::vector<float> person;
        float x = item.pose.position.x; //  x
        float y = item.pose.position.x; //  y
        int id = item.id; //  id

        if (bank.find(id) != bank.end()) {
            bank[id].push_back({{x, y}, timestamp});
        } else {
            bank[id] = {{{x, y}, timestamp}};
        }
        num_obj++;
    }
    std::cout << "包含" << num_obj << " 个目标"<< std::endl;
}

//处理8帧数据为id,custom_msgs::DetectedObjectArray格式
void processMsg3(const custom_msgs::DetectedObjectArray& one_frame_msg, custom_msgs::TrajPredArray& bank){
    int num_obj = 0 ;
    for (const auto& item : one_frame_msg.objects) {    // 该帧的单个目标
        ros::Time timestamp = one_frame_msg.header.stamp;

        std::vector<float> person;
        float x = item.pose.position.x; //  x
        float y = item.pose.position.y; //  y
        int id = item.id; //  id
        //已存在的id
        std::vector<uint32_t> ids;
        // 遍历TrajPredArray中的所有TrajPredSingle对象
        for (const auto& single_traj_pred : bank.objects) {
            ids.push_back(single_traj_pred.id);
        }
        
        if (std::find(ids.begin(), ids.end(), id) == ids.end()){
            custom_msgs::TrajPredSingle temp;
            temp.id = id;
            temp.objects.push_back(item);
            bank.objects.push_back(temp);
        } else {
            for (auto& single_traj_pred : bank.objects) {
                if (single_traj_pred.id == id) {
                    single_traj_pred.objects.push_back(item);
                }
            }
        }
        num_obj++;
    }
    std::cout << "包含" << num_obj << " 个目标"<< std::endl;
}


void linearInterpolationAndAppend2(custom_msgs::TrajPredArray& bank, std::size_t targetSize) {
    for (auto& single_traj_pred : bank.objects) {
        if (single_traj_pred.objects.size() >= targetSize) {
            return;  // 不需要进行插值和补全
        }

        // 如果需要插值，计算每个维度的增量
        float xIncrement = (single_traj_pred.objects.back().pose.position.x - single_traj_pred.objects.front().pose.position.x) / (targetSize - single_traj_pred.objects.size());
        float yIncrement = (single_traj_pred.objects.back().pose.position.y - single_traj_pred.objects.front().pose.position.y) / (targetSize - single_traj_pred.objects.size());

        // 计算序号的增量
        int sequenceIncrement = 1;

        // 进行插值
        for (std::size_t i = single_traj_pred.objects.size(); i < targetSize; ++i) {
            float newX = single_traj_pred.objects.back().pose.position.x + i * xIncrement;
            float newY = single_traj_pred.objects.back().pose.position.y + i * yIncrement;
            ros::Duration durationIncrement(sequenceIncrement);
            // 将新的数据点添加到 value 中，序号递增
            custom_msgs::DetectedObject temp;
            temp.pose.position.x = newX;
            temp.pose.position.y = newY;
            temp.header.stamp = single_traj_pred.objects.back().header.stamp + durationIncrement;
            single_traj_pred.objects.push_back(temp);
        }
        std::cout << "已执行插值和补全\n" << std::endl;
    }
}