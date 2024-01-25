# 单个目标定义
std_msgs/Header header

jsk_recognition_msgs/BoundingBox box
float32 velocity
float64 angle       # Angle [0 to 2*PI), allow rotated rects
geometry_msgs/Pose pose # 单目标位置信息
int32 obj_lane_number

string label
float32 score
int32 x
int32 y
int32 width
int32 height
float32 frenet_length
float32 frenet_distance
float32 dis_to_leftBounding
float32 dis_to_rightBounding

uint32 id   # 单目标id