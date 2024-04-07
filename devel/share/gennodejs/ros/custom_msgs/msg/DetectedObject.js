// Auto-generated. Do not edit!

// (in-package custom_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let std_msgs = _finder('std_msgs');
let geometry_msgs = _finder('geometry_msgs');
let jsk_recognition_msgs = _finder('jsk_recognition_msgs');

//-----------------------------------------------------------

class DetectedObject {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.box = null;
      this.velocity = null;
      this.angle = null;
      this.pose = null;
      this.obj_lane_number = null;
      this.label = null;
      this.score = null;
      this.x = null;
      this.y = null;
      this.width = null;
      this.height = null;
      this.frenet_length = null;
      this.frenet_distance = null;
      this.dis_to_leftBounding = null;
      this.dis_to_rightBounding = null;
      this.id = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('box')) {
        this.box = initObj.box
      }
      else {
        this.box = new jsk_recognition_msgs.msg.BoundingBox();
      }
      if (initObj.hasOwnProperty('velocity')) {
        this.velocity = initObj.velocity
      }
      else {
        this.velocity = 0.0;
      }
      if (initObj.hasOwnProperty('angle')) {
        this.angle = initObj.angle
      }
      else {
        this.angle = 0.0;
      }
      if (initObj.hasOwnProperty('pose')) {
        this.pose = initObj.pose
      }
      else {
        this.pose = new geometry_msgs.msg.Pose();
      }
      if (initObj.hasOwnProperty('obj_lane_number')) {
        this.obj_lane_number = initObj.obj_lane_number
      }
      else {
        this.obj_lane_number = 0;
      }
      if (initObj.hasOwnProperty('label')) {
        this.label = initObj.label
      }
      else {
        this.label = '';
      }
      if (initObj.hasOwnProperty('score')) {
        this.score = initObj.score
      }
      else {
        this.score = 0.0;
      }
      if (initObj.hasOwnProperty('x')) {
        this.x = initObj.x
      }
      else {
        this.x = 0;
      }
      if (initObj.hasOwnProperty('y')) {
        this.y = initObj.y
      }
      else {
        this.y = 0;
      }
      if (initObj.hasOwnProperty('width')) {
        this.width = initObj.width
      }
      else {
        this.width = 0;
      }
      if (initObj.hasOwnProperty('height')) {
        this.height = initObj.height
      }
      else {
        this.height = 0;
      }
      if (initObj.hasOwnProperty('frenet_length')) {
        this.frenet_length = initObj.frenet_length
      }
      else {
        this.frenet_length = 0.0;
      }
      if (initObj.hasOwnProperty('frenet_distance')) {
        this.frenet_distance = initObj.frenet_distance
      }
      else {
        this.frenet_distance = 0.0;
      }
      if (initObj.hasOwnProperty('dis_to_leftBounding')) {
        this.dis_to_leftBounding = initObj.dis_to_leftBounding
      }
      else {
        this.dis_to_leftBounding = 0.0;
      }
      if (initObj.hasOwnProperty('dis_to_rightBounding')) {
        this.dis_to_rightBounding = initObj.dis_to_rightBounding
      }
      else {
        this.dis_to_rightBounding = 0.0;
      }
      if (initObj.hasOwnProperty('id')) {
        this.id = initObj.id
      }
      else {
        this.id = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type DetectedObject
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [box]
    bufferOffset = jsk_recognition_msgs.msg.BoundingBox.serialize(obj.box, buffer, bufferOffset);
    // Serialize message field [velocity]
    bufferOffset = _serializer.float32(obj.velocity, buffer, bufferOffset);
    // Serialize message field [angle]
    bufferOffset = _serializer.float64(obj.angle, buffer, bufferOffset);
    // Serialize message field [pose]
    bufferOffset = geometry_msgs.msg.Pose.serialize(obj.pose, buffer, bufferOffset);
    // Serialize message field [obj_lane_number]
    bufferOffset = _serializer.int32(obj.obj_lane_number, buffer, bufferOffset);
    // Serialize message field [label]
    bufferOffset = _serializer.string(obj.label, buffer, bufferOffset);
    // Serialize message field [score]
    bufferOffset = _serializer.float32(obj.score, buffer, bufferOffset);
    // Serialize message field [x]
    bufferOffset = _serializer.int32(obj.x, buffer, bufferOffset);
    // Serialize message field [y]
    bufferOffset = _serializer.int32(obj.y, buffer, bufferOffset);
    // Serialize message field [width]
    bufferOffset = _serializer.int32(obj.width, buffer, bufferOffset);
    // Serialize message field [height]
    bufferOffset = _serializer.int32(obj.height, buffer, bufferOffset);
    // Serialize message field [frenet_length]
    bufferOffset = _serializer.float32(obj.frenet_length, buffer, bufferOffset);
    // Serialize message field [frenet_distance]
    bufferOffset = _serializer.float32(obj.frenet_distance, buffer, bufferOffset);
    // Serialize message field [dis_to_leftBounding]
    bufferOffset = _serializer.float32(obj.dis_to_leftBounding, buffer, bufferOffset);
    // Serialize message field [dis_to_rightBounding]
    bufferOffset = _serializer.float32(obj.dis_to_rightBounding, buffer, bufferOffset);
    // Serialize message field [id]
    bufferOffset = _serializer.uint32(obj.id, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type DetectedObject
    let len;
    let data = new DetectedObject(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [box]
    data.box = jsk_recognition_msgs.msg.BoundingBox.deserialize(buffer, bufferOffset);
    // Deserialize message field [velocity]
    data.velocity = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [angle]
    data.angle = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [pose]
    data.pose = geometry_msgs.msg.Pose.deserialize(buffer, bufferOffset);
    // Deserialize message field [obj_lane_number]
    data.obj_lane_number = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [label]
    data.label = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [score]
    data.score = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [x]
    data.x = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [y]
    data.y = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [width]
    data.width = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [height]
    data.height = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [frenet_length]
    data.frenet_length = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [frenet_distance]
    data.frenet_distance = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [dis_to_leftBounding]
    data.dis_to_leftBounding = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [dis_to_rightBounding]
    data.dis_to_rightBounding = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [id]
    data.id = _deserializer.uint32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    length += jsk_recognition_msgs.msg.BoundingBox.getMessageSize(object.box);
    length += _getByteLength(object.label);
    return length + 116;
  }

  static datatype() {
    // Returns string type for a message object
    return 'custom_msgs/DetectedObject';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '5db790854edad95e35e6a0a9a78bb615';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
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
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new DetectedObject(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.box !== undefined) {
      resolved.box = jsk_recognition_msgs.msg.BoundingBox.Resolve(msg.box)
    }
    else {
      resolved.box = new jsk_recognition_msgs.msg.BoundingBox()
    }

    if (msg.velocity !== undefined) {
      resolved.velocity = msg.velocity;
    }
    else {
      resolved.velocity = 0.0
    }

    if (msg.angle !== undefined) {
      resolved.angle = msg.angle;
    }
    else {
      resolved.angle = 0.0
    }

    if (msg.pose !== undefined) {
      resolved.pose = geometry_msgs.msg.Pose.Resolve(msg.pose)
    }
    else {
      resolved.pose = new geometry_msgs.msg.Pose()
    }

    if (msg.obj_lane_number !== undefined) {
      resolved.obj_lane_number = msg.obj_lane_number;
    }
    else {
      resolved.obj_lane_number = 0
    }

    if (msg.label !== undefined) {
      resolved.label = msg.label;
    }
    else {
      resolved.label = ''
    }

    if (msg.score !== undefined) {
      resolved.score = msg.score;
    }
    else {
      resolved.score = 0.0
    }

    if (msg.x !== undefined) {
      resolved.x = msg.x;
    }
    else {
      resolved.x = 0
    }

    if (msg.y !== undefined) {
      resolved.y = msg.y;
    }
    else {
      resolved.y = 0
    }

    if (msg.width !== undefined) {
      resolved.width = msg.width;
    }
    else {
      resolved.width = 0
    }

    if (msg.height !== undefined) {
      resolved.height = msg.height;
    }
    else {
      resolved.height = 0
    }

    if (msg.frenet_length !== undefined) {
      resolved.frenet_length = msg.frenet_length;
    }
    else {
      resolved.frenet_length = 0.0
    }

    if (msg.frenet_distance !== undefined) {
      resolved.frenet_distance = msg.frenet_distance;
    }
    else {
      resolved.frenet_distance = 0.0
    }

    if (msg.dis_to_leftBounding !== undefined) {
      resolved.dis_to_leftBounding = msg.dis_to_leftBounding;
    }
    else {
      resolved.dis_to_leftBounding = 0.0
    }

    if (msg.dis_to_rightBounding !== undefined) {
      resolved.dis_to_rightBounding = msg.dis_to_rightBounding;
    }
    else {
      resolved.dis_to_rightBounding = 0.0
    }

    if (msg.id !== undefined) {
      resolved.id = msg.id;
    }
    else {
      resolved.id = 0
    }

    return resolved;
    }
};

module.exports = DetectedObject;
