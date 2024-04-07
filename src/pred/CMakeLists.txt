cmake_minimum_required(VERSION 3.0.2)
project(pred)
SET(CMAKE_BUILD_TYPE "RelWithDebInfo")
 
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  custom_msgs
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES pred
  CATKIN_DEPENDS roscpp rospy std_msgs
  DEPENDS system_lib
)

# message(STATUS "*************PROJECT_SOURCE_DIR*****************8: ${PROJECT_SOURCE_DIR}")
# message(STATUS "*************catkin_INCLUDE_DIRS*****************8:${catkin_INCLUDE_DIRS}")


# set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)  # ${PROJECT_SOURCE_DIR}为/home/plyj/20240103foshan/pred_ws/src/pred
add_library(pred_utils SHARED src/pred_utils.cpp src/model_CVM.cpp) # 但是catkinmalke会将生成的库加入到devel/lib下面
###########
## Build ##
###########

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
  ${PROJECT_SOURCE_DIR}/include/pred
)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/devel/lib/)
# link_libraries(${CMAKE_CURRENT_SOURCE_DIR}/devel/lib/libpred_utils.a)

add_executable(pub_MOT src/pub_MOT.cpp)
add_executable(sub_MOT src/sub_MOT.cpp)
add_executable(sub_MOT2 src/sub_MOT2.cpp)
add_executable(full_obs_traj src/full_obs_traj.cpp)



target_link_libraries(pub_MOT  ${catkin_LIBRARIES})
target_link_libraries(sub_MOT  ${catkin_LIBRARIES})
target_link_libraries(sub_MOT2  ${catkin_LIBRARIES})
target_link_libraries(full_obs_traj  ${catkin_LIBRARIES})
target_link_libraries(sub_MOT  pred_utils)
target_link_libraries(sub_MOT2  pred_utils)
target_link_libraries(full_obs_traj  pred_utils)

