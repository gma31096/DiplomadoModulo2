// Generated by gencpp from file simulator/simulator_parametersRequest.msg
// DO NOT EDIT!


#ifndef SIMULATOR_MESSAGE_SIMULATOR_PARAMETERSREQUEST_H
#define SIMULATOR_MESSAGE_SIMULATOR_PARAMETERSREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace simulator
{
template <class ContainerAllocator>
struct simulator_parametersRequest_
{
  typedef simulator_parametersRequest_<ContainerAllocator> Type;

  simulator_parametersRequest_()
    : request(false)  {
    }
  simulator_parametersRequest_(const ContainerAllocator& _alloc)
    : request(false)  {
  (void)_alloc;
    }



   typedef uint8_t _request_type;
  _request_type request;




  typedef boost::shared_ptr< ::simulator::simulator_parametersRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::simulator::simulator_parametersRequest_<ContainerAllocator> const> ConstPtr;

}; // struct simulator_parametersRequest_

typedef ::simulator::simulator_parametersRequest_<std::allocator<void> > simulator_parametersRequest;

typedef boost::shared_ptr< ::simulator::simulator_parametersRequest > simulator_parametersRequestPtr;
typedef boost::shared_ptr< ::simulator::simulator_parametersRequest const> simulator_parametersRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::simulator::simulator_parametersRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::simulator::simulator_parametersRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace simulator

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'sensor_msgs': ['/opt/ros/indigo/share/sensor_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'simulator': ['/home/gerardo/catkin_ws/src/simulator/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::simulator::simulator_parametersRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::simulator::simulator_parametersRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::simulator::simulator_parametersRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::simulator::simulator_parametersRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::simulator::simulator_parametersRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::simulator::simulator_parametersRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::simulator::simulator_parametersRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "6f7e5ad6ab0ddf42c5727a195315a470";
  }

  static const char* value(const ::simulator::simulator_parametersRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x6f7e5ad6ab0ddf42ULL;
  static const uint64_t static_value2 = 0xc5727a195315a470ULL;
};

template<class ContainerAllocator>
struct DataType< ::simulator::simulator_parametersRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "simulator/simulator_parametersRequest";
  }

  static const char* value(const ::simulator::simulator_parametersRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::simulator::simulator_parametersRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bool request\n\
";
  }

  static const char* value(const ::simulator::simulator_parametersRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::simulator::simulator_parametersRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.request);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct simulator_parametersRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::simulator::simulator_parametersRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::simulator::simulator_parametersRequest_<ContainerAllocator>& v)
  {
    s << indent << "request: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.request);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SIMULATOR_MESSAGE_SIMULATOR_PARAMETERSREQUEST_H
