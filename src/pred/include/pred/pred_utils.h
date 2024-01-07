#ifndef PRED_UTILS_H
#define PRED_UTILS_H

#include <ros/ros.h>
#include <std_msgs/Header.h>
#include <custom_msgs/MOT.h>

//打印每帧数据对应时间
void printTimestamp(const std_msgs::Header& header);

//处理8帧数据为id,vector<x,y,timestamp>格式
void processMsg(const custom_msgs::MOT& one_frame_msg, std::map<int, std::vector<std::pair<std::pair<float, float>, ros::Time>>>& bank);

//输入处理后8帧数据，调用预测模型输出12帧数据

#endif  // PRED_UTILS_H
