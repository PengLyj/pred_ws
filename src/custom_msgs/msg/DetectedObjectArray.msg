# 单帧所有目标的当前状态
std_msgs/Header header
DetectedObject[] objects    # 单帧多个目标的坐标集合
int32 vel_lane_number
float32 speed_limit
uint32 num  # 单帧目标数量