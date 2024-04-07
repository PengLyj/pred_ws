;; Auto-generated. Do not edit!


(when (boundp 'custom_msgs::TrajPredSingle)
  (if (not (find-package "CUSTOM_MSGS"))
    (make-package "CUSTOM_MSGS"))
  (shadow 'TrajPredSingle (find-package "CUSTOM_MSGS")))
(unless (find-package "CUSTOM_MSGS::TRAJPREDSINGLE")
  (make-package "CUSTOM_MSGS::TRAJPREDSINGLE"))

(in-package "ROS")
;;//! \htmlinclude TrajPredSingle.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass custom_msgs::TrajPredSingle
  :super ros::object
  :slots (_header _array_len _objects _id ))

(defmethod custom_msgs::TrajPredSingle
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:array_len __array_len) 0)
    ((:objects __objects) ())
    ((:id __id) 0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _array_len (round __array_len))
   (setq _objects __objects)
   (setq _id (round __id))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:array_len
   (&optional __array_len)
   (if __array_len (setq _array_len __array_len)) _array_len)
  (:objects
   (&rest __objects)
   (if (keywordp (car __objects))
       (send* _objects __objects)
     (progn
       (if __objects (setq _objects (car __objects)))
       _objects)))
  (:id
   (&optional __id)
   (if __id (setq _id __id)) _id)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; uint32 _array_len
    4
    ;; custom_msgs/DetectedObject[] _objects
    (apply #'+ (send-all _objects :serialization-length)) 4
    ;; uint32 _id
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; uint32 _array_len
       (write-long _array_len s)
     ;; custom_msgs/DetectedObject[] _objects
     (write-long (length _objects) s)
     (dolist (elem _objects)
       (send elem :serialize s)
       )
     ;; uint32 _id
       (write-long _id s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; uint32 _array_len
     (setq _array_len (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; custom_msgs/DetectedObject[] _objects
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _objects (let (r) (dotimes (i n) (push (instance custom_msgs::DetectedObject :init) r)) r))
     (dolist (elem- _objects)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;; uint32 _id
     (setq _id (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get custom_msgs::TrajPredSingle :md5sum-) "10e9f71602422d72b4d2dcbad941f70d")
(setf (get custom_msgs::TrajPredSingle :datatype-) "custom_msgs/TrajPredSingle")
(setf (get custom_msgs::TrajPredSingle :definition-)
      "# 当前时刻下单目标轨迹序列
std_msgs/Header header
uint32 array_len # 序列长度，即目标的历史/未来轨迹序列长度
DetectedObject[] objects    # 轨迹序列
uint32 id # 目标ID

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
string frame_id

================================================================================
MSG: custom_msgs/DetectedObject
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
================================================================================
MSG: jsk_recognition_msgs/BoundingBox
# BoundingBox represents a oriented bounding box.
Header header
geometry_msgs/Pose pose
geometry_msgs/Vector3 dimensions  # size of bounding box (x, y, z)
# You can use this field to hold value such as likelihood
float32 value
uint32 label

================================================================================
MSG: geometry_msgs/Pose
# A representation of pose in free space, composed of position and orientation. 
Point position
Quaternion orientation

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

================================================================================
MSG: geometry_msgs/Quaternion
# This represents an orientation in free space in quaternion form.

float64 x
float64 y
float64 z
float64 w

================================================================================
MSG: geometry_msgs/Vector3
# This represents a vector in free space. 
# It is only meant to represent a direction. Therefore, it does not
# make sense to apply a translation to it (e.g., when applying a 
# generic rigid transformation to a Vector3, tf2 will only apply the
# rotation). If you want your data to be translatable too, use the
# geometry_msgs/Point message instead.

float64 x
float64 y
float64 z
")



(provide :custom_msgs/TrajPredSingle "10e9f71602422d72b4d2dcbad941f70d")


