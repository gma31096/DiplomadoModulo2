// Generated by gencpp from file clips_ros/planning_cmdRequest.msg
// DO NOT EDIT!


#ifndef CLIPS_ROS_MESSAGE_PLANNING_CMDREQUEST_H
#define CLIPS_ROS_MESSAGE_PLANNING_CMDREQUEST_H


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
struct planning_cmdRequest_
{
  typedef planning_cmdRequest_<ContainerAllocator> Type;

  planning_cmdRequest_()
    : params()
    , name()  {
    }
  planning_cmdRequest_(const ContainerAllocator& _alloc)
    : params(_alloc)
    , name(_alloc)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _params_type;
  _params_type params;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _name_type;
  _name_type name;




  typedef boost::shared_ptr< ::clips_ros::planning_cmdRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::clips_ros::planning_cmdRequest_<ContainerAllocator> const> ConstPtr;

}; // struct planning_cmdRequest_

typedef ::clips_ros::planning_cmdRequest_<std::allocator<void> > planning_cmdRequest;

typedef boost::shared_ptr< ::clips_ros::planning_cmdRequest > planning_cmdRequestPtr;
typedef boost::shared_ptr< ::clips_ros::planning_cmdRequest const> planning_cmdRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::clips_ros::planning_cmdRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::clips_ros::planning_cmdRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace clips_ros

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'clips_ros': ['/home/gerardo/catkin_ws/src/clips_ros/msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::clips_ros::planning_cmdRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::clips_ros::planning_cmdRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::clips_ros::planning_cmdRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::clips_ros::planning_cmdRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::clips_ros::planning_cmdRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::clips_ros::planning_cmdRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::clips_ros::planning_cmdRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "6f06fa99b3a7a624255764732217776c";
  }

  static const char* value(const ::clips_ros::planning_cmdRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x6f06fa99b3a7a624ULL;
  static const uint64_t static_value2 = 0x255764732217776cULL;
};

template<class ContainerAllocator>
struct DataType< ::clips_ros::planning_cmdRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "clips_ros/planning_cmdRequest";
  }

  static const char* value(const ::clips_ros::planning_cmdRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::clips_ros::planning_cmdRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string params\n\
string name\n\
";
  }

  static const char* value(const ::clips_ros::planning_cmdRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::clips_ros::planning_cmdRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.params);
      stream.next(m.name);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct planning_cmdRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::clips_ros::planning_cmdRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::clips_ros::planning_cmdRequest_<ContainerAllocator>& v)
  {
    s << indent << "params: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.params);
    s << indent << "name: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.name);
  }
};

} // namespace message_operations
} // namespace ros

#endif // CLIPS_ROS_MESSAGE_PLANNING_CMDREQUEST_H
