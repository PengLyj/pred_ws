// Auto-generated. Do not edit!

// (in-package custom_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let TrajPredSingle = require('./TrajPredSingle.js');
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class TrajPredArray {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.num_objects = null;
      this.objects = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('num_objects')) {
        this.num_objects = initObj.num_objects
      }
      else {
        this.num_objects = 0;
      }
      if (initObj.hasOwnProperty('objects')) {
        this.objects = initObj.objects
      }
      else {
        this.objects = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type TrajPredArray
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [num_objects]
    bufferOffset = _serializer.uint32(obj.num_objects, buffer, bufferOffset);
    // Serialize message field [objects]
    // Serialize the length for message field [objects]
    bufferOffset = _serializer.uint32(obj.objects.length, buffer, bufferOffset);
    obj.objects.forEach((val) => {
      bufferOffset = TrajPredSingle.serialize(val, buffer, bufferOffset);
    });
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type TrajPredArray
    let len;
    let data = new TrajPredArray(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [num_objects]
    data.num_objects = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [objects]
    // Deserialize array length for message field [objects]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.objects = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.objects[i] = TrajPredSingle.deserialize(buffer, bufferOffset)
    }
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    object.objects.forEach((val) => {
      length += TrajPredSingle.getMessageSize(val);
    });
    return length + 8;
  }

  static datatype() {
    // Returns string type for a message object
    return 'custom_msgs/TrajPredArray';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '4ff05079708ce4a441a936a27a5d1121';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # 当前时刻下多目标的轨迹序列
    std_msgs/Header header
    uint32 num_objects # 序列长度，即目标的历史/未来轨迹序列长度
    TrajPredSingle[] objects    # 轨迹序列
    
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
    MSG: custom_msgs/TrajPredSingle
    # 当前时刻下单目标轨迹序列
    std_msgs/Header header
    uint32 array_len # 序列长度，即目标的历史/未来轨迹序列长度
    DetectedObject[] objects    # 轨迹序列
    uint32 id # 目标ID
    
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
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new TrajPredArray(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.num_objects !== undefined) {
      resolved.num_objects = msg.num_objects;
    }
    else {
      resolved.num_objects = 0
    }

    if (msg.objects !== undefined) {
      resolved.objects = new Array(msg.objects.length);
      for (let i = 0; i < resolved.objects.length; ++i) {
        resolved.objects[i] = TrajPredSingle.Resolve(msg.objects[i]);
      }
    }
    else {
      resolved.objects = []
    }

    return resolved;
    }
};

module.exports = TrajPredArray;
