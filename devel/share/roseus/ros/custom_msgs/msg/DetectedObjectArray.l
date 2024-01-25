;; Auto-generated. Do not edit!


(when (boundp 'custom_msgs::DetectedObjectArray)
  (if (not (find-package "CUSTOM_MSGS"))
    (make-package "CUSTOM_MSGS"))
  (shadow 'DetectedObjectArray (find-package "CUSTOM_MSGS")))
(unless (find-package "CUSTOM_MSGS::DETECTEDOBJECTARRAY")
  (make-package "CUSTOM_MSGS::DETECTEDOBJECTARRAY"))

(in-package "ROS")
;;//! \htmlinclude DetectedObjectArray.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass custom_msgs::DetectedObjectArray
  :super ros::object
  :slots (_header _objects _vel_lane_number _speed_limit _num ))

(defmethod custom_msgs::DetectedObjectArray
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:objects __objects) ())
    ((:vel_lane_number __vel_lane_number) 0)
    ((:speed_limit __speed_limit) 0.0)
    ((:num __num) 0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _objects __objects)
   (setq _vel_lane_number (round __vel_lane_number))
   (setq _speed_limit (float __speed_limit))
   (setq _num (round __num))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:objects
   (&rest __objects)
   (if (keywordp (car __objects))
       (send* _objects __objects)
     (progn
       (if __objects (setq _objects (car __objects)))
       _objects)))
  (:vel_lane_number
   (&optional __vel_lane_number)
   (if __vel_lane_number (setq _vel_lane_number __vel_lane_number)) _vel_lane_number)
  (:speed_limit
   (&optional __speed_limit)
   (if __speed_limit (setq _speed_limit __speed_limit)) _speed_limit)
  (:num
   (&optional __num)
   (if __num (setq _num __num)) _num)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; custom_msgs/DetectedObject[] _objects
    (apply #'+ (send-all _objects :serialization-length)) 4
    ;; int32 _vel_lane_number
    4
    ;; float32 _speed_limit
    4
    ;; uint32 _num
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; custom_msgs/DetectedObject[] _objects
     (write-long (length _objects) s)
     (dolist (elem _objects)
       (send elem :serialize s)
       )
     ;; int32 _vel_lane_number
       (write-long _vel_lane_number s)
     ;; float32 _speed_limit
       (sys::poke _speed_limit (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; uint32 _num
       (write-long _num s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; custom_msgs/DetectedObject[] _objects
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _objects (let (r) (dotimes (i n) (push (instance custom_msgs::DetectedObject :init) r)) r))
     (dolist (elem- _objects)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;; int32 _vel_lane_number
     (setq _vel_lane_number (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; float32 _speed_limit
     (setq _speed_limit (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; uint32 _num
     (setq _num (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get custom_msgs::DetectedObjectArray :md5sum-) "f0b9809ba26357a84292b034d6b7ce98")
(setf (get custom_msgs::DetectedObjectArray :datatype-) "custom_msgs/DetectedObjectArray")
(setf (get custom_msgs::DetectedObjectArray :definition-)
      "# 单帧多个目标的集合
std_msgs/Header header
DetectedObject[] objects
int32 vel_lane_number
float32 speed_limit
uint32 num
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
geometry_msgs/Pose pose
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

uint32 id
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



(provide :custom_msgs/DetectedObjectArray "f0b9809ba26357a84292b034d6b7ce98")


