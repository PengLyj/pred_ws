; Auto-generated. Do not edit!


(cl:in-package custom_msgs-msg)


;//! \htmlinclude TrajPredSingle.msg.html

(cl:defclass <TrajPredSingle> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (array_len
    :reader array_len
    :initarg :array_len
    :type cl:integer
    :initform 0)
   (objects
    :reader objects
    :initarg :objects
    :type (cl:vector custom_msgs-msg:DetectedObject)
   :initform (cl:make-array 0 :element-type 'custom_msgs-msg:DetectedObject :initial-element (cl:make-instance 'custom_msgs-msg:DetectedObject)))
   (id
    :reader id
    :initarg :id
    :type cl:integer
    :initform 0))
)

(cl:defclass TrajPredSingle (<TrajPredSingle>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <TrajPredSingle>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'TrajPredSingle)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name custom_msgs-msg:<TrajPredSingle> is deprecated: use custom_msgs-msg:TrajPredSingle instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <TrajPredSingle>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msgs-msg:header-val is deprecated.  Use custom_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'array_len-val :lambda-list '(m))
(cl:defmethod array_len-val ((m <TrajPredSingle>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msgs-msg:array_len-val is deprecated.  Use custom_msgs-msg:array_len instead.")
  (array_len m))

(cl:ensure-generic-function 'objects-val :lambda-list '(m))
(cl:defmethod objects-val ((m <TrajPredSingle>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msgs-msg:objects-val is deprecated.  Use custom_msgs-msg:objects instead.")
  (objects m))

(cl:ensure-generic-function 'id-val :lambda-list '(m))
(cl:defmethod id-val ((m <TrajPredSingle>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msgs-msg:id-val is deprecated.  Use custom_msgs-msg:id instead.")
  (id m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <TrajPredSingle>) ostream)
  "Serializes a message object of type '<TrajPredSingle>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'array_len)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'array_len)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'array_len)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'array_len)) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'objects))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'objects))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'id)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'id)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'id)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'id)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <TrajPredSingle>) istream)
  "Deserializes a message object of type '<TrajPredSingle>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'array_len)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'array_len)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'array_len)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'array_len)) (cl:read-byte istream))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'objects) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'objects)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'custom_msgs-msg:DetectedObject))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'id)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'id)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'id)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'id)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<TrajPredSingle>)))
  "Returns string type for a message object of type '<TrajPredSingle>"
  "custom_msgs/TrajPredSingle")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'TrajPredSingle)))
  "Returns string type for a message object of type 'TrajPredSingle"
  "custom_msgs/TrajPredSingle")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<TrajPredSingle>)))
  "Returns md5sum for a message object of type '<TrajPredSingle>"
  "10e9f71602422d72b4d2dcbad941f70d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'TrajPredSingle)))
  "Returns md5sum for a message object of type 'TrajPredSingle"
  "10e9f71602422d72b4d2dcbad941f70d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<TrajPredSingle>)))
  "Returns full string definition for message of type '<TrajPredSingle>"
  (cl:format cl:nil "# 当前时刻下单目标轨迹序列~%std_msgs/Header header~%uint32 array_len # 序列长度，即目标的历史/未来轨迹序列长度~%DetectedObject[] objects    # 轨迹序列~%uint32 id # 目标ID~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: custom_msgs/DetectedObject~%# 单个目标定义~%std_msgs/Header header~%~%jsk_recognition_msgs/BoundingBox box~%float32 velocity~%float64 angle       # Angle [0 to 2*PI), allow rotated rects~%geometry_msgs/Pose pose # 单目标位置信息~%int32 obj_lane_number~%~%string label~%float32 score~%int32 x~%int32 y~%int32 width~%int32 height~%float32 frenet_length~%float32 frenet_distance~%float32 dis_to_leftBounding~%float32 dis_to_rightBounding~%~%uint32 id   # 单目标id~%================================================================================~%MSG: jsk_recognition_msgs/BoundingBox~%# BoundingBox represents a oriented bounding box.~%Header header~%geometry_msgs/Pose pose~%geometry_msgs/Vector3 dimensions  # size of bounding box (x, y, z)~%# You can use this field to hold value such as likelihood~%float32 value~%uint32 label~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'TrajPredSingle)))
  "Returns full string definition for message of type 'TrajPredSingle"
  (cl:format cl:nil "# 当前时刻下单目标轨迹序列~%std_msgs/Header header~%uint32 array_len # 序列长度，即目标的历史/未来轨迹序列长度~%DetectedObject[] objects    # 轨迹序列~%uint32 id # 目标ID~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: custom_msgs/DetectedObject~%# 单个目标定义~%std_msgs/Header header~%~%jsk_recognition_msgs/BoundingBox box~%float32 velocity~%float64 angle       # Angle [0 to 2*PI), allow rotated rects~%geometry_msgs/Pose pose # 单目标位置信息~%int32 obj_lane_number~%~%string label~%float32 score~%int32 x~%int32 y~%int32 width~%int32 height~%float32 frenet_length~%float32 frenet_distance~%float32 dis_to_leftBounding~%float32 dis_to_rightBounding~%~%uint32 id   # 单目标id~%================================================================================~%MSG: jsk_recognition_msgs/BoundingBox~%# BoundingBox represents a oriented bounding box.~%Header header~%geometry_msgs/Pose pose~%geometry_msgs/Vector3 dimensions  # size of bounding box (x, y, z)~%# You can use this field to hold value such as likelihood~%float32 value~%uint32 label~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <TrajPredSingle>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'objects) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <TrajPredSingle>))
  "Converts a ROS message object to a list"
  (cl:list 'TrajPredSingle
    (cl:cons ':header (header msg))
    (cl:cons ':array_len (array_len msg))
    (cl:cons ':objects (objects msg))
    (cl:cons ':id (id msg))
))
