// Generated by gencpp from file custom_msgs/DetectedObject.msg
// DO NOT EDIT!


#ifndef CUSTOM_MSGS_MESSAGE_DETECTEDOBJECT_H
#define CUSTOM_MSGS_MESSAGE_DETECTEDOBJECT_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <jsk_recognition_msgs/BoundingBox.h>
#include <geometry_msgs/Pose.h>

namespace custom_msgs
{
template <class ContainerAllocator>
struct DetectedObject_
{
  typedef DetectedObject_<ContainerAllocator> Type;

  DetectedObject_()
    : header()
    , box()
    , velocity(0.0)
    , angle(0.0)
    , pose()
    , obj_lane_number(0)
    , label()
    , score(0.0)
    , x(0)
    , y(0)
    , width(0)
    , height(0)
    , frenet_length(0.0)
    , frenet_distance(0.0)
    , dis_to_leftBounding(0.0)
    , dis_to_rightBounding(0.0)
    , id(0)  {
    }
  DetectedObject_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , box(_alloc)
    , velocity(0.0)
    , angle(0.0)
    , pose(_alloc)
    , obj_lane_number(0)
    , label(_alloc)
    , score(0.0)
    , x(0)
    , y(0)
    , width(0)
    , height(0)
    , frenet_length(0.0)
    , frenet_distance(0.0)
    , dis_to_leftBounding(0.0)
    , dis_to_rightBounding(0.0)
    , id(0)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef  ::jsk_recognition_msgs::BoundingBox_<ContainerAllocator>  _box_type;
  _box_type box;

   typedef float _velocity_type;
  _velocity_type velocity;

   typedef double _angle_type;
  _angle_type angle;

   typedef  ::geometry_msgs::Pose_<ContainerAllocator>  _pose_type;
  _pose_type pose;

   typedef int32_t _obj_lane_number_type;
  _obj_lane_number_type obj_lane_number;

   typedef std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> _label_type;
  _label_type label;

   typedef float _score_type;
  _score_type score;

   typedef int32_t _x_type;
  _x_type x;

   typedef int32_t _y_type;
  _y_type y;

   typedef int32_t _width_type;
  _width_type width;

   typedef int32_t _height_type;
  _height_type height;

   typedef float _frenet_length_type;
  _frenet_length_type frenet_length;

   typedef float _frenet_distance_type;
  _frenet_distance_type frenet_distance;

   typedef float _dis_to_leftBounding_type;
  _dis_to_leftBounding_type dis_to_leftBounding;

   typedef float _dis_to_rightBounding_type;
  _dis_to_rightBounding_type dis_to_rightBounding;

   typedef uint32_t _id_type;
  _id_type id;





  typedef boost::shared_ptr< ::custom_msgs::DetectedObject_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::custom_msgs::DetectedObject_<ContainerAllocator> const> ConstPtr;

}; // struct DetectedObject_

typedef ::custom_msgs::DetectedObject_<std::allocator<void> > DetectedObject;

typedef boost::shared_ptr< ::custom_msgs::DetectedObject > DetectedObjectPtr;
typedef boost::shared_ptr< ::custom_msgs::DetectedObject const> DetectedObjectConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::custom_msgs::DetectedObject_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::custom_msgs::DetectedObject_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::custom_msgs::DetectedObject_<ContainerAllocator1> & lhs, const ::custom_msgs::DetectedObject_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.box == rhs.box &&
    lhs.velocity == rhs.velocity &&
    lhs.angle == rhs.angle &&
    lhs.pose == rhs.pose &&
    lhs.obj_lane_number == rhs.obj_lane_number &&
    lhs.label == rhs.label &&
    lhs.score == rhs.score &&
    lhs.x == rhs.x &&
    lhs.y == rhs.y &&
    lhs.width == rhs.width &&
    lhs.height == rhs.height &&
    lhs.frenet_length == rhs.frenet_length &&
    lhs.frenet_distance == rhs.frenet_distance &&
    lhs.dis_to_leftBounding == rhs.dis_to_leftBounding &&
    lhs.dis_to_rightBounding == rhs.dis_to_rightBounding &&
    lhs.id == rhs.id;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::custom_msgs::DetectedObject_<ContainerAllocator1> & lhs, const ::custom_msgs::DetectedObject_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace custom_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::custom_msgs::DetectedObject_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::custom_msgs::DetectedObject_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::custom_msgs::DetectedObject_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::custom_msgs::DetectedObject_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::custom_msgs::DetectedObject_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::custom_msgs::DetectedObject_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::custom_msgs::DetectedObject_<ContainerAllocator> >
{
  static const char* value()
  {
    return "5db790854edad95e35e6a0a9a78bb615";
  }

  static const char* value(const ::custom_msgs::DetectedObject_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x5db790854edad95eULL;
  static const uint64_t static_value2 = 0x35e6a0a9a78bb615ULL;
};

template<class ContainerAllocator>
struct DataType< ::custom_msgs::DetectedObject_<ContainerAllocator> >
{
  static const char* value()
  {
    return "custom_msgs/DetectedObject";
  }

  static const char* value(const ::custom_msgs::DetectedObject_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::custom_msgs::DetectedObject_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# 单个目标定义\n"
"std_msgs/Header header\n"
"\n"
"jsk_recognition_msgs/BoundingBox box\n"
"float32 velocity\n"
"float64 angle       # Angle [0 to 2*PI), allow rotated rects\n"
"geometry_msgs/Pose pose # 单目标位置信息\n"
"int32 obj_lane_number\n"
"\n"
"string label\n"
"float32 score\n"
"int32 x\n"
"int32 y\n"
"int32 width\n"
"int32 height\n"
"float32 frenet_length\n"
"float32 frenet_distance\n"
"float32 dis_to_leftBounding\n"
"float32 dis_to_rightBounding\n"
"\n"
"uint32 id   # 单目标id\n"
"================================================================================\n"
"MSG: std_msgs/Header\n"
"# Standard metadata for higher-level stamped data types.\n"
"# This is generally used to communicate timestamped data \n"
"# in a particular coordinate frame.\n"
"# \n"
"# sequence ID: consecutively increasing ID \n"
"uint32 seq\n"
"#Two-integer timestamp that is expressed as:\n"
"# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n"
"# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n"
"# time-handling sugar is provided by the client library\n"
"time stamp\n"
"#Frame this data is associated with\n"
"string frame_id\n"
"\n"
"================================================================================\n"
"MSG: jsk_recognition_msgs/BoundingBox\n"
"# BoundingBox represents a oriented bounding box.\n"
"Header header\n"
"geometry_msgs/Pose pose\n"
"geometry_msgs/Vector3 dimensions  # size of bounding box (x, y, z)\n"
"# You can use this field to hold value such as likelihood\n"
"float32 value\n"
"uint32 label\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Pose\n"
"# A representation of pose in free space, composed of position and orientation. \n"
"Point position\n"
"Quaternion orientation\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Point\n"
"# This contains the position of a point in free space\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Quaternion\n"
"# This represents an orientation in free space in quaternion form.\n"
"\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"float64 w\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Vector3\n"
"# This represents a vector in free space. \n"
"# It is only meant to represent a direction. Therefore, it does not\n"
"# make sense to apply a translation to it (e.g., when applying a \n"
"# generic rigid transformation to a Vector3, tf2 will only apply the\n"
"# rotation). If you want your data to be translatable too, use the\n"
"# geometry_msgs/Point message instead.\n"
"\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
;
  }

  static const char* value(const ::custom_msgs::DetectedObject_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::custom_msgs::DetectedObject_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.box);
      stream.next(m.velocity);
      stream.next(m.angle);
      stream.next(m.pose);
      stream.next(m.obj_lane_number);
      stream.next(m.label);
      stream.next(m.score);
      stream.next(m.x);
      stream.next(m.y);
      stream.next(m.width);
      stream.next(m.height);
      stream.next(m.frenet_length);
      stream.next(m.frenet_distance);
      stream.next(m.dis_to_leftBounding);
      stream.next(m.dis_to_rightBounding);
      stream.next(m.id);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct DetectedObject_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::custom_msgs::DetectedObject_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::custom_msgs::DetectedObject_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "box: ";
    s << std::endl;
    Printer< ::jsk_recognition_msgs::BoundingBox_<ContainerAllocator> >::stream(s, indent + "  ", v.box);
    s << indent << "velocity: ";
    Printer<float>::stream(s, indent + "  ", v.velocity);
    s << indent << "angle: ";
    Printer<double>::stream(s, indent + "  ", v.angle);
    s << indent << "pose: ";
    s << std::endl;
    Printer< ::geometry_msgs::Pose_<ContainerAllocator> >::stream(s, indent + "  ", v.pose);
    s << indent << "obj_lane_number: ";
    Printer<int32_t>::stream(s, indent + "  ", v.obj_lane_number);
    s << indent << "label: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>::stream(s, indent + "  ", v.label);
    s << indent << "score: ";
    Printer<float>::stream(s, indent + "  ", v.score);
    s << indent << "x: ";
    Printer<int32_t>::stream(s, indent + "  ", v.x);
    s << indent << "y: ";
    Printer<int32_t>::stream(s, indent + "  ", v.y);
    s << indent << "width: ";
    Printer<int32_t>::stream(s, indent + "  ", v.width);
    s << indent << "height: ";
    Printer<int32_t>::stream(s, indent + "  ", v.height);
    s << indent << "frenet_length: ";
    Printer<float>::stream(s, indent + "  ", v.frenet_length);
    s << indent << "frenet_distance: ";
    Printer<float>::stream(s, indent + "  ", v.frenet_distance);
    s << indent << "dis_to_leftBounding: ";
    Printer<float>::stream(s, indent + "  ", v.dis_to_leftBounding);
    s << indent << "dis_to_rightBounding: ";
    Printer<float>::stream(s, indent + "  ", v.dis_to_rightBounding);
    s << indent << "id: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.id);
  }
};

} // namespace message_operations
} // namespace ros

#endif // CUSTOM_MSGS_MESSAGE_DETECTEDOBJECT_H
