// Generated by gencpp from file custom_msgs/MOT.msg
// DO NOT EDIT!


#ifndef CUSTOM_MSGS_MESSAGE_MOT_H
#define CUSTOM_MSGS_MESSAGE_MOT_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <std_msgs/Float32MultiArray.h>

namespace custom_msgs
{
template <class ContainerAllocator>
struct MOT_
{
  typedef MOT_<ContainerAllocator> Type;

  MOT_()
    : header()
    , num(0)
    , array()  {
    }
  MOT_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , num(0)
    , array(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef int32_t _num_type;
  _num_type num;

   typedef std::vector< ::std_msgs::Float32MultiArray_<ContainerAllocator> , typename std::allocator_traits<ContainerAllocator>::template rebind_alloc< ::std_msgs::Float32MultiArray_<ContainerAllocator> >> _array_type;
  _array_type array;





  typedef boost::shared_ptr< ::custom_msgs::MOT_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::custom_msgs::MOT_<ContainerAllocator> const> ConstPtr;

}; // struct MOT_

typedef ::custom_msgs::MOT_<std::allocator<void> > MOT;

typedef boost::shared_ptr< ::custom_msgs::MOT > MOTPtr;
typedef boost::shared_ptr< ::custom_msgs::MOT const> MOTConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::custom_msgs::MOT_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::custom_msgs::MOT_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::custom_msgs::MOT_<ContainerAllocator1> & lhs, const ::custom_msgs::MOT_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.num == rhs.num &&
    lhs.array == rhs.array;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::custom_msgs::MOT_<ContainerAllocator1> & lhs, const ::custom_msgs::MOT_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace custom_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::custom_msgs::MOT_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::custom_msgs::MOT_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::custom_msgs::MOT_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::custom_msgs::MOT_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::custom_msgs::MOT_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::custom_msgs::MOT_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::custom_msgs::MOT_<ContainerAllocator> >
{
  static const char* value()
  {
    return "8d34b3cd50c5972122d057a82374fbc4";
  }

  static const char* value(const ::custom_msgs::MOT_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x8d34b3cd50c59721ULL;
  static const uint64_t static_value2 = 0x22d057a82374fbc4ULL;
};

template<class ContainerAllocator>
struct DataType< ::custom_msgs::MOT_<ContainerAllocator> >
{
  static const char* value()
  {
    return "custom_msgs/MOT";
  }

  static const char* value(const ::custom_msgs::MOT_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::custom_msgs::MOT_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# MOT.msg\n"
"std_msgs/Header header\n"
"int32 num\n"
"std_msgs/Float32MultiArray[] array\n"
"\n"
"# float32 posx\n"
"# float32 posy\n"
"# int32 id\n"
"# int32 size\n"
"\n"
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
"MSG: std_msgs/Float32MultiArray\n"
"# Please look at the MultiArrayLayout message definition for\n"
"# documentation on all multiarrays.\n"
"\n"
"MultiArrayLayout  layout        # specification of data layout\n"
"float32[]         data          # array of data\n"
"\n"
"\n"
"================================================================================\n"
"MSG: std_msgs/MultiArrayLayout\n"
"# The multiarray declares a generic multi-dimensional array of a\n"
"# particular data type.  Dimensions are ordered from outer most\n"
"# to inner most.\n"
"\n"
"MultiArrayDimension[] dim # Array of dimension properties\n"
"uint32 data_offset        # padding elements at front of data\n"
"\n"
"# Accessors should ALWAYS be written in terms of dimension stride\n"
"# and specified outer-most dimension first.\n"
"# \n"
"# multiarray(i,j,k) = data[data_offset + dim_stride[1]*i + dim_stride[2]*j + k]\n"
"#\n"
"# A standard, 3-channel 640x480 image with interleaved color channels\n"
"# would be specified as:\n"
"#\n"
"# dim[0].label  = \"height\"\n"
"# dim[0].size   = 480\n"
"# dim[0].stride = 3*640*480 = 921600  (note dim[0] stride is just size of image)\n"
"# dim[1].label  = \"width\"\n"
"# dim[1].size   = 640\n"
"# dim[1].stride = 3*640 = 1920\n"
"# dim[2].label  = \"channel\"\n"
"# dim[2].size   = 3\n"
"# dim[2].stride = 3\n"
"#\n"
"# multiarray(i,j,k) refers to the ith row, jth column, and kth channel.\n"
"\n"
"================================================================================\n"
"MSG: std_msgs/MultiArrayDimension\n"
"string label   # label of given dimension\n"
"uint32 size    # size of given dimension (in type units)\n"
"uint32 stride  # stride of given dimension\n"
;
  }

  static const char* value(const ::custom_msgs::MOT_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::custom_msgs::MOT_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.num);
      stream.next(m.array);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct MOT_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::custom_msgs::MOT_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::custom_msgs::MOT_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "num: ";
    Printer<int32_t>::stream(s, indent + "  ", v.num);
    s << indent << "array[]" << std::endl;
    for (size_t i = 0; i < v.array.size(); ++i)
    {
      s << indent << "  array[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::std_msgs::Float32MultiArray_<ContainerAllocator> >::stream(s, indent + "    ", v.array[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // CUSTOM_MSGS_MESSAGE_MOT_H
