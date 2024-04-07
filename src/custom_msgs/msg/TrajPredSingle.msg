# 当前时刻下单目标轨迹序列
std_msgs/Header header
uint32 array_len # 序列长度，即目标的历史/未来轨迹序列长度
DetectedObject[] objects    # 轨迹序列
uint32 id # 目标ID
