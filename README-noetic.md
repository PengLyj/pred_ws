ubuntu20.04-plyj
# ADV-Foshan-code
当前版本为20240104

高精度地图相关依赖
https://p25mh5oghf.feishu.cn/docx/doxcn40oSxG7k9FpgPN8NwiUDPd
sudo apt-get install ros-noetic-rospack ros-noetic-catkin ros-noetic-mrt-cmake-modules
sudo apt-get install libboost-dev libeigen3-dev libgeographic-dev libpugixml-dev libpython2-dev libboost-python-dev catkin-tools

sudo apt install ros-noetic-lanelet2

决策相关依赖
sudo apt-get install ros-noetic-costmap-converter

其他
sudo apt-get install ros-noetic-jsk-recognition-msgs 
sudo apt-get install ros-noetic-jsk-rviz-plugins

编译
先只保留src的daisch_ifs2000_driver和msgs包
然后catkin_make
然后把剩余的放回来
catkin_make到成功编译为止

git remote update origin --prune

data/bag 文件夹里的文件地址：
https://172-17-20-60.fsxhconnect.direct.quickconnect.to:5001/index.cgi?launchApp=SYNO.SDS.App.FileStation3.Instance&launchParam=openfile%3D%252FDATA%252Fbag%252F%25E4%25BB%25A3%25E7%25A0%2581%25E5%25BA%2593%25E4%25B8%25AD%25E7%259A%2584bag%252F

lattice相关依赖
sudo apt-get install ros-noetic-uuid-msgs
sudo apt-get install ros-noetic-autoware-msgs

# sudo apt-get install ros-noetic-astuff-sensor-msgs 此操作暂未可行
# 参考https://github.com/astuff/astuff_sensor_msgs
sudo apt-get install ros-noetic-shape-msgs
cd src
git clone https://github.com/astuff/astuff_sensor_msgs
# 去掉编译ibeo_msgs等编译报错的功能包
 

# 遇到empy导致的无法编译
sudo ln -s /usr/bin/empy3 /usr/bin/empy

# 遇到ModuleNotFoundError: No module named 'em'
sudo apt-get install python3-empy
或者pip3 install empy==3.3.4
# 若安装后仍不存在em，确认下vscode中的python编译器是否与终端中的python版本一致，若不一致则设置为一致，并重启VSCODE

# https://b79oxri837.feishu.cn/docx/doxcnwgUoRGzvpa5sAXgkZN3BzN
# 遇到error: the value of ‘NrDims’ is not usable in a constant expression
# 在使用pcl_ros的CMakeists.txt里添加以下两行
set(_python_version 3.8)
set(CMAKE_CXX_STANDARD 14)

# 单独编译方式（重新全部编译的话，需要删除/devel 和/build
catkin_make -DCATKIN_WHITELIST_PACKAGES="euclidean_cluster"
# 编译过程依赖关系报错，则反复编译直到成功