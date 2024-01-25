/*
基于constant velocity model实现行人轨迹预测
获得read返回的模型输入序列；
处理序列，获得预测结果；
返回预测结果序列；
*/

#include "pred_utils.h"

// 线性差值和补全函数
void linearInterpolationAndAppend(std::vector<std::pair<std::pair<float, float>, ros::Time>>& value, std::size_t targetSize) {
    if (value.size() >= targetSize) {
        return;  // 不需要进行插值和补全
    }

    // 如果需要插值，计算每个维度的增量
    float xIncrement = (value.back().first.first - value.front().first.first) / (targetSize - value.size());
    float yIncrement = (value.back().first.second - value.front().first.second) / (targetSize - value.size());

    // 计算序号的增量
    int sequenceIncrement = 1;

    // 进行插值
    for (std::size_t i = value.size(); i < targetSize; ++i) {
        float newX = value.back().first.first + i * xIncrement;
        float newY = value.back().first.second + i * yIncrement;
        ros::Duration durationIncrement(sequenceIncrement);
        // 将新的数据点添加到 value 中，序号递增
        value.push_back(std::make_pair(std::make_pair(newX, newY), value.back().second + durationIncrement));
    }
}



void model_CVM(std::map<int, std::vector<std::pair<std::pair<float, float>, ros::Time>>>& history_bank, 
std::map<int, std::vector<std::pair<std::pair<float, float>, ros::Time>>>& future_bank){
    /*
    history_bank 包含过去8帧的数据，数据格式为id,vector<x,y,timestamp>，注意单个id下坐标对不一定满足8对
    future_bank 用于存储预测12帧的数据，数据格式为id,vector<x,y,timestamp>

    e.g.
    ID: 3
    X: 0.766617, Y: 0.196659, Timestamp: 1704940222 seconds
    X: 0.797059, Y: 0.822265, Timestamp: 1704940221 seconds
    X: 0.176973, Y: 0.599531, Timestamp: 1704940221 seconds
    X: 0.821938, Y: 0.231166, Timestamp: 1704940221 seconds
    X: 0.380289, Y: 0.740039, Timestamp: 1704940219 seconds
    注意：每帧间隔0.4s, 但由于ros的时间精度为s, 故5帧的时间间隔2s无法利用时间戳来查看，但由于保存时是按照顺序读写，故序列顺序已按照时间排序
    */
    std::cout << "model: model_CVM" << std::endl;

    
    // 使用迭代器遍历 history_bank
    for (auto it = history_bank.begin(); it != history_bank.end(); ++it) {
        int key = it->first;    //ID
        std::vector<std::pair<std::pair<float, float>, ros::Time>>& value = it->second;

        ros::Time time = value[0].second;

        // 获取 value 内的长度（元素数量）
        std::size_t valueSize = value.size();
        std::cout << "ID: " << key << ", Length of value: " << valueSize << std::endl;
        // 线性差值和补全到目标大小（8条），并保持原有数据不变
        linearInterpolationAndAppend(value, OBS_FRAMS);
        // 输出当前元素的ID和补全后的 value
        std::cout << "ID: " << key << ", Length of value after interpolation and append: " << value.size() << std::endl;

        // 创建一个数组来存储X、Y的值
        std::pair<float, float> xy_array[OBS_FRAMS+PRED_FRAMS];


        // 初始化数组
        for (int i = 0; i < OBS_FRAMS+PRED_FRAMS; ++i) {
            xy_array[i] = std::make_pair(0.0, 0.0);  // 初始值可以根据实际情况调整
        }

        // 将每行数据中的X、Y值添加到数组中
        int index = 0;
        for (const auto& data : value) {
            float x = data.first.first;
            float y = data.first.second;

            // 将X、Y值添加到数组中
            xy_array[index++] = std::make_pair(x, y);
            // std::cout << "x = " << x << ";y = " << y <<"; index = " << index <<std::endl;
        }

        

        
        //当前帧与前一帧的位移差值
        float dis_rel_x = xy_array[0].first - xy_array[1].first;
        float dis_rel_y = xy_array[0].second - xy_array[1].second;
        std::pair<int, std::vector<std::pair<std::pair<float, float>, ros::Time>>> future_pos;
        for (int i = OBS_FRAMS; i < OBS_FRAMS+PRED_FRAMS; ++i) {
            float x_last = xy_array[i-1].first;
            float y_last = xy_array[i-1].second;
            
            xy_array[i] = std::make_pair(x_last + dis_rel_x, y_last + dis_rel_y);  // 初始值可以根据实际情况调整


            future_pos.first = key;
            // future_pos.second[i].first = xy_array[i];
            // future_pos.second[i].second = time;
            future_pos.second.push_back(std::make_pair(xy_array[i], time));
            
        }
        future_bank.insert(future_pos);
        // index = 0;
        // for (int i = 0; i < OBS_FRAMS+PRED_FRAMS; ++i) {
        //     float x = xy_array[i].first;
        //     float y = xy_array[i].second;
        //     index += 1;
        //     std::cout << "x = " << x << ";y = " << y <<"; index = " << index <<std::endl;
        // }

        
    }

}
