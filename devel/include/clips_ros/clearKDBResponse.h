// Generated by gencpp from file clips_ros/clearKDBResponse.msg
// DO NOT EDIT!


#ifndef CLIPS_ROS_MESSAGE_CLEARKDBRESPONSE_H
#define CLIPS_ROS_MESSAGE_CLEARKDBRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace clips_ros
{
template <class ContainerAllocator>
struct clearKDBResponse_
{
  typedef clearKDBResponse_<ContainerAllocator> Type;

  clearKDBResponse_()
    : cleared(false)  {
    }
  clearKDBResponse_(const ContainerAllocator& _alloc)
    : cleared(false)  {
  (void)_alloc;
    }



   typedef uint8_t _cleared_type;
  _cleared_type cleared;




  typedef boost::shared_ptr< ::clips_ros::clearKDBResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::clips_ros::clearKDBResponse_<ContainerAllocator> const> ConstPtr;

}; // struct clearKDBResponse_

typedef ::clips_ros::clearKDBResponse_<std::allocator<void> > clearKDBResponse;

typedef boost::shared_ptr< ::clips_ros::clearKDBResponse > clearKDBResponsePtr;
typedef boost::shared_ptr< ::clips_ros::clearKDBResponse const> clearKDBResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::clips_ros::clearKDBResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::clips_ros::clearKDBResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace clips_ros

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'clips_ros': ['/home/gerardo/catkin_ws/src/clips_ros/msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::clips_ros::clearKDBResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::clips_ros::clearKDBResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::clips_ros::clearKDBResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::clips_ros::clearKDBResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::clips_ros::clearKDBResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::clips_ros::clearKDBResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::clips_ros::clearKDBResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "e19ee16a20ef206251e0359e9ec07ab5";
  }

  static const char* value(const ::clips_ros::clearKDBResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xe19ee16a20ef2062ULL;
  static const uint64_t static_value2 = 0x51e0359e9ec07ab5ULL;
};

template<class ContainerAllocator>
struct DataType< ::clips_ros::clearKDBResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "clips_ros/clearKDBResponse";
  }

  static const char* value(const ::clips_ros::clearKDBResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::clips_ros::clearKDBResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bool cleared\n\
\n\
";
  }

  static const char* value(const ::clips_ros::clearKDBResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::clips_ros::clearKDBResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.cleared);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct clearKDBResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::clips_ros::clearKDBResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::clips_ros::clearKDBResponse_<ContainerAllocator>& v)
  {
    s << indent << "cleared: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.cleared);
  }
};

} // namespace message_operations
} // namespace ros

#endif // CLIPS_ROS_MESSAGE_CLEARKDBRESPONSE_H