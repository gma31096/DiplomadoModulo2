// Generated by gencpp from file clips_ros/clearKDBRequest.msg
// DO NOT EDIT!


#ifndef CLIPS_ROS_MESSAGE_CLEARKDBREQUEST_H
#define CLIPS_ROS_MESSAGE_CLEARKDBREQUEST_H


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
struct clearKDBRequest_
{
  typedef clearKDBRequest_<ContainerAllocator> Type;

  clearKDBRequest_()
    : clear(false)  {
    }
  clearKDBRequest_(const ContainerAllocator& _alloc)
    : clear(false)  {
  (void)_alloc;
    }



   typedef uint8_t _clear_type;
  _clear_type clear;




  typedef boost::shared_ptr< ::clips_ros::clearKDBRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::clips_ros::clearKDBRequest_<ContainerAllocator> const> ConstPtr;

}; // struct clearKDBRequest_

typedef ::clips_ros::clearKDBRequest_<std::allocator<void> > clearKDBRequest;

typedef boost::shared_ptr< ::clips_ros::clearKDBRequest > clearKDBRequestPtr;
typedef boost::shared_ptr< ::clips_ros::clearKDBRequest const> clearKDBRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::clips_ros::clearKDBRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::clips_ros::clearKDBRequest_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::clips_ros::clearKDBRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::clips_ros::clearKDBRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::clips_ros::clearKDBRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::clips_ros::clearKDBRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::clips_ros::clearKDBRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::clips_ros::clearKDBRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::clips_ros::clearKDBRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "0f13874ec47789a29a9f87f75379435d";
  }

  static const char* value(const ::clips_ros::clearKDBRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x0f13874ec47789a2ULL;
  static const uint64_t static_value2 = 0x9a9f87f75379435dULL;
};

template<class ContainerAllocator>
struct DataType< ::clips_ros::clearKDBRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "clips_ros/clearKDBRequest";
  }

  static const char* value(const ::clips_ros::clearKDBRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::clips_ros::clearKDBRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bool clear\n\
";
  }

  static const char* value(const ::clips_ros::clearKDBRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::clips_ros::clearKDBRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.clear);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct clearKDBRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::clips_ros::clearKDBRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::clips_ros::clearKDBRequest_<ContainerAllocator>& v)
  {
    s << indent << "clear: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.clear);
  }
};

} // namespace message_operations
} // namespace ros

#endif // CLIPS_ROS_MESSAGE_CLEARKDBREQUEST_H
