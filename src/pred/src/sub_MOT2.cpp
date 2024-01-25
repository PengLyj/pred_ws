/*
订阅MOT结果（采用离线数据替代），并持续存储到history_bank；
history_bank固定容量，并剔除旧数据，更新新数据；
返回history_bank的地址
*/

#include "ros/ros.h"
#include "std_msgs/Header.h"
#include "std_msgs/Float32MultiArray.h"
#include "custom_msgs/MOT.h"
#include "custom_msgs/DetectedObject.h"
#include "custom_msgs/DetectedObjectArray.h"
#include <deque>
#include <iostream>
#include "pred_utils.h"


#define MOT_PUB_FRAME 20    // MOT发布频率
#define FRAME_INTERVAL 0.4    // 单帧数据间隔时长
#define FRAME_GAP (MOT_PUB_FRAME * FRAME_INTERVAL)  // 单帧数据间隔订阅消息条数


class SubscriberPublisher {
public:
    SubscriberPublisher() : nh_(""), pub_(nh_.advertise<custom_msgs::MOT>("history_traj", 10))
    {
        sub_ = nh_.subscribe("pub_MOT2", 1000, &SubscriberPublisher::callback, this);//为保存3.2s数据，pub的频率为20hz，故至少需要缓存64条pub信息
        timer_ = nh_.createTimer(ros::Duration(0.4), &SubscriberPublisher::timerCallback, this);
        duration_3_2_seconds_ago_ = ros::Duration(3.2);
    }

    void callback(const custom_msgs::DetectedObjectArray::ConstPtr& msg) {
        // std::cout << "** callback **" << std::endl;
        // 将接收到的消息存储在 deque 中，保留最近的 3.2s数据（3.2s*20hz=64条数据）
        message_queue_.push_back(msg);
        // std::cout<<"存储一个"<< std:: endl;

        if (message_queue_.size() > 500) {
            message_queue_.pop_front();
            // std::cout<<"剔除一个"<< std:: endl;
        }
    }



void timerCallback(const ros::TimerEvent& event) {
    // 每0.4s执行一次
    // std::cout << "** timerCallback **" << std::endl;
    ros::Time current_time = ros::Time::now();
    float threshold = 0.1;
    // 每帧数据间隔FRAME_GAP条订阅消息，需要取8帧
    if (message_queue_.size() >= FRAME_GAP*8) {
        std::map<int, std::vector<std::pair<std::pair<float, float>, ros::Time>>> history_bank; // 用来修改保存格式 id,vector<x,y,timestamp>
        std::map<int, std::vector<std::pair<std::pair<float, float>, ros::Time>>> future_bank;  // 用来保存预测结果 id,vector<x,y,timestamp>
        // 寻找第一条消息的索引，使得第一条消息的时间戳与当前时间戳相同
        int first_msg_index = -1;
        for (size_t i = 0; i < message_queue_.size(); ++i) {
            // printTimestamp(message_queue_[i]->header);
            // printTimestamp(current_time);
            if (std::abs((message_queue_[i]->header.stamp - current_time).toSec()) < threshold) {
                first_msg_index = i;
                std::cout << "*************************************" << std::endl;
                std::cout << "当前时刻:";
                printTimestamp(message_queue_[i]->header);
                break;
            }
        }



        // 确保找到了第一条消息
        if (first_msg_index != -1) {
            // 每0.4秒间隔取一条消息，共取8帧，需每帧间隔FRAME_INTERVAL*MOT_PUB_FRAME条信息
            int frame_num = 0;
            for (int i = 0; i > -FRAME_GAP*8; i-=FRAME_GAP) {
                int index = first_msg_index + i;    // 上一帧对应index
                // std::cout <<"message_queue_.size() = " << message_queue_.size() <<std::endl;
                // std::cout <<"first_msg_index = " << first_msg_index <<std::endl;
                
                if (index < message_queue_.size()) {
                    // std::cout << "进入 " << i << std::endl;
                    // msg为message_queue_中第index帧数据，其中msg.objects包含多个目标
                    const auto& msg = message_queue_[index];
                    

                    // 处理为每个id对应的序列
                    custom_msgs::DetectedObjectArray one_frame_msg = *msg;
                    std::cout << "过去第" << frame_num << "帧数据";
                    processMsg2(one_frame_msg, history_bank);

                    //combined_msg应该包含8帧数据，每帧数据包含多条轨迹
                    //需要通过获取8帧数据的时间戳来确定是否间隔0.4s
                    std_msgs::Header header = msg->header;
                    printTimestamp(header);
                } 
                else {
                    // std::cout << "退出 " << i << std::endl;
                    break; // 队列中的消息不足8条
                }
                frame_num += 1;
            }

            // 输出处理后的数据id,vector<x,y,timestamp>
            for (const auto& entry : history_bank) {
                std::cout << "ID: " << entry.first << std::endl;
                for (const auto& value : entry.second) {
                    std::cout << "    X: " << value.first.first << ", Y: " << value.first.second
                            << ", Timestamp: " << value.second.sec << " seconds" << std::endl;
                }
            }
            // 预测
            model_CVM(history_bank, future_bank);
            for (const auto& entry : future_bank) {
                std::cout << "ID: " << entry.first << std::endl;
                for (const auto& value : entry.second) {
                    std::cout << "    X: " << value.first.first << ", Y: " << value.first.second
                            << ", Timestamp: " << value.second.sec << " seconds" << std::endl;
                }
            }
            
            
            std::cout << "*************************************" << std::endl;
        }
    }
}


private:
    ros::NodeHandle nh_;
    ros::Publisher pub_;
    ros::Subscriber sub_;
    ros::Timer timer_;
    ros::Duration duration_3_2_seconds_ago_;
    std::deque<custom_msgs::DetectedObjectArray::ConstPtr> message_queue_;
};

int main(int argc, char** argv) {
    ros::init(argc, argv, "subscriber_publisher_node");
    SubscriberPublisher sp;
    ros::spin();
    return 0;
}
