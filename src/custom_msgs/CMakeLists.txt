cmake_minimum_required(VERSION 3.0.2)
project(custom_msgs)

find_package(catkin REQUIRED 
    COMPONENTS 
    roscpp 
    rospy 
    message_generation 
    std_msgs 
    geometry_msgs
    jsk_recognition_msgs
)

add_message_files(
    FILES
    MOT.msg
    DetectedObject.msg
    DetectedObjectArray.msg
    TrajPredSingle.msg
    TrajPredArray.msg
    # Message2.msg
)

#generate_messages必须在catkin_package前面
generate_messages(
    DEPENDENCIES
    std_msgs
    geometry_msgs
    jsk_recognition_msgs
)

catkin_package(

    CATKIN_DEPENDS message_runtime

)



include_directories(
# include
# ${catkin_INCLUDE_DIRS}
)

