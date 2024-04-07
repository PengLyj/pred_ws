# 当前时刻下多目标的轨迹序列
std_msgs/Header header
uint32 num_objects # 序列长度，即目标的历史/未来轨迹序列长度
TrajPredSingle[] objects    # 轨迹序列
