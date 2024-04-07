;; Auto-generated. Do not edit!


(when (boundp 'custom_msgs::DetectedObject)
  (if (not (find-package "CUSTOM_MSGS"))
    (make-package "CUSTOM_MSGS"))
  (shadow 'DetectedObject (find-package "CUSTOM_MSGS")))
(unless (find-package "CUSTOM_MSGS::DETECTEDOBJECT")
  (make-package "CUSTOM_MSGS::DETECTEDOBJECT"))

(in-package "ROS")
;;//! \htmlinclude DetectedObject.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))
(if (not (find-package "JSK_RECOGNITION_MSGS"))
  (ros::roseus-add-msgs "jsk_recognition_msgs"))
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass custom_msgs::DetectedObject
  :super ros::object
  :slots (_header _box _velocity _angle _pose _obj_lane_number _label _score _x _y _width _height _frenet_length _frenet_distance _dis_to_leftBounding _dis_to_rightBounding _id ))

(defmethod custom_msgs::DetectedObject
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:box __box) (instance jsk_recognition_msgs::BoundingBox :init))
    ((:velocity __velocity) 0.0)
    ((:angle __angle) 0.0)
    ((:pose __pose) (instance geometry_msgs::Pose :init))
    ((:obj_lane_number __obj_lane_number) 0)
    ((:label __label) "")
    ((:score __score) 0.0)
    ((:x __x) 0)
    ((:y __y) 0)
    ((:width __width) 0)
    ((:height __height) 0)
    ((:frenet_length __frenet_length) 0.0)
    ((:frenet_distance __frenet_distance) 0.0)
    ((:dis_to_leftBounding __dis_to_leftBounding) 0.0)
    ((:dis_to_rightBounding __dis_to_rightBounding) 0.0)
    ((:id __id) 0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _box __box)
   (setq _velocity (float __velocity))
   (setq _angle (float __angle))
   (setq _pose __pose)
   (setq _obj_lane_number (round __obj_lane_number))
   (setq _label (string __label))
   (setq _score (float __score))
   (setq _x (round __x))
   (setq _y (round __y))
   (setq _width (round __width))
   (setq _height (round __height))
   (setq _frenet_length (float __frenet_length))
   (setq _frenet_distance (float __frenet_distance))
   (setq _dis_to_leftBounding (float __dis_to_leftBounding))
   (setq _dis_to_rightBounding (float __dis_to_rightBounding))
   (setq _id (round __id))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:box
   (&rest __box)
   (if (keywordp (car __box))
       (send* _box __box)
     (progn
       (if __box (setq _box (car __box)))
       _box)))
  (:velocity
   (&optional __velocity)
   (if __velocity (setq _velocity __velocity)) _velocity)
  (:angle
   (&optional __angle)
   (if __angle (setq _angle __angle)) _angle)
  (:pose
   (&rest __pose)
   (if (keywordp (car __pose))
       (send* _pose __pose)
     (progn
       (if __pose (setq _pose (car __pose)))
       _pose)))
  (:obj_lane_number
   (&optional __obj_lane_number)
   (if __obj_lane_number (setq _obj_lane_number __obj_lane_number)) _obj_lane_number)
  (:label
   (&optional __label)
   (if __label (setq _label __label)) _label)
  (:score
   (&optional __score)
   (if __score (setq _score __score)) _score)
  (:x
   (&optional __x)
   (if __x (setq _x __x)) _x)
  (:y
   (&optional __y)
   (if __y (setq _y __y)) _y)
  (:width
   (&optional __width)
   (if __width (setq _width __width)) _width)
  (:height
   (&optional __height)
   (if __height (setq _height __height)) _height)
  (:frenet_length
   (&optional __frenet_length)
   (if __frenet_length (setq _frenet_length __frenet_length)) _frenet_length)
  (:frenet_distance
   (&optional __frenet_distance)
   (if __frenet_distance (setq _frenet_distance __frenet_distance)) _frenet_distance)
  (:dis_to_leftBounding
   (&optional __dis_to_leftBounding)
   (if __dis_to_leftBounding (setq _dis_to_leftBounding __dis_to_leftBounding)) _dis_to_leftBounding)
  (:dis_to_rightBounding
   (&optional __dis_to_rightBounding)
   (if __dis_to_rightBounding (setq _dis_to_rightBounding __dis_to_rightBounding)) _dis_to_rightBounding)
  (:id
   (&optional __id)
   (if __id (setq _id __id)) _id)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; jsk_recognition_msgs/BoundingBox _box
    (send _box :serialization-length)
    ;; float32 _velocity
    4
    ;; float64 _angle
    8
    ;; geometry_msgs/Pose _pose
    (send _pose :serialization-length)
    ;; int32 _obj_lane_number
    4
    ;; string _label
    4 (length _label)
    ;; float32 _score
    4
    ;; int32 _x
    4
    ;; int32 _y
    4
    ;; int32 _width
    4
    ;; int32 _height
    4
    ;; float32 _frenet_length
    4
    ;; float32 _frenet_distance
    4
    ;; float32 _dis_to_leftBounding
    4
    ;; float32 _dis_to_rightBounding
    4
    ;; uint32 _id
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; jsk_recognition_msgs/BoundingBox _box
       (send _box :serialize s)
     ;; float32 _velocity
       (sys::poke _velocity (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float64 _angle
       (sys::poke _angle (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; geometry_msgs/Pose _pose
       (send _pose :serialize s)
     ;; int32 _obj_lane_number
       (write-long _obj_lane_number s)
     ;; string _label
       (write-long (length _label) s) (princ _label s)
     ;; float32 _score
       (sys::poke _score (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; int32 _x
       (write-long _x s)
     ;; int32 _y
       (write-long _y s)
     ;; int32 _width
       (write-long _width s)
     ;; int32 _height
       (write-long _height s)
     ;; float32 _frenet_length
       (sys::poke _frenet_length (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _frenet_distance
       (sys::poke _frenet_distance (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _dis_to_leftBounding
       (sys::poke _dis_to_leftBounding (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _dis_to_rightBounding
       (sys::poke _dis_to_rightBounding (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; uint32 _id
       (write-long _id s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; jsk_recognition_msgs/BoundingBox _box
     (send _box :deserialize buf ptr-) (incf ptr- (send _box :serialization-length))
   ;; float32 _velocity
     (setq _velocity (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float64 _angle
     (setq _angle (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; geometry_msgs/Pose _pose
     (send _pose :deserialize buf ptr-) (incf ptr- (send _pose :serialization-length))
   ;; int32 _obj_lane_number
     (setq _obj_lane_number (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; string _label
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _label (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; float32 _score
     (setq _score (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; int32 _x
     (setq _x (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _y
     (setq _y (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _width
     (setq _width (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _height
     (setq _height (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; float32 _frenet_length
     (setq _frenet_length (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _frenet_distance
     (setq _frenet_distance (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _dis_to_leftBounding
     (setq _dis_to_leftBounding (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _dis_to_rightBounding
     (setq _dis_to_rightBounding (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; uint32 _id
     (setq _id (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get custom_msgs::DetectedObject :md5sum-) "5db790854edad95e35e6a0a9a78bb615")
(setf (get custom_msgs::DetectedObject :datatype-) "custom_msgs/DetectedObject")
(setf (get custom_msgs::DetectedObject :definition-)
      "# 单个目标定义
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



(provide :custom_msgs/DetectedObject "5db790854edad95e35e6a0a9a78bb615")


