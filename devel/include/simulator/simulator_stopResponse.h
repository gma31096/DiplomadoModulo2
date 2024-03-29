// Generated by gencpp from file simulator/simulator_stopResponse.msg
// DO NOT EDIT!


#ifndef SIMULATOR_MESSAGE_SIMULATOR_STOPRESPONSE_H
#define SIMULATOR_MESSAGE_SIMULATOR_STOPRESPONSE_H


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
struct simulator_stopResponse_
{
  typedef simulator_stopResponse_<ContainerAllocator> Type;

  simulator_stopResponse_()
    : resp(false)  {
    }
  simulator_stopResponse_(const ContainerAllocator& _alloc)
    : resp(false)  {
  (void)_alloc;
    }



   typedef uint8_t _resp_type;
  _resp_type resp;




  typedef boost::shared_ptr< ::simulator::simulator_stopResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::simulator::simulator_stopResponse_<ContainerAllocator> const> ConstPtr;

}; // struct simulator_stopResponse_

typedef ::simulator::simulator_stopResponse_<std::allocator<void> > simulator_stopResponse;

typedef boost::shared_ptr< ::simulator::simulator_stopResponse > simulator_stopResponsePtr;
typedef boost::shared_ptr< ::simulator::simulator_stopResponse const> simulator_stopResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::simulator::simulator_stopResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::simulator::simulator_stopResponse_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::simulator::simulator_stopResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::simulator::simulator_stopResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::simulator::simulator_stopResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::simulator::simulator_stopResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::simulator::simulator_stopResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::simulator::simulator_stopResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::simulator::simulator_stopResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "e3a98d806e1c4fee01a17d597e27ea8e";
  }

  static const char* value(const ::simulator::simulator_stopResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xe3a98d806e1c4feeULL;
  static const uint64_t static_value2 = 0x01a17d597e27ea8eULL;
};

template<class ContainerAllocator>
struct DataType< ::simulator::simulator_stopResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "simulator/simulator_stopResponse";
  }

  static const char* value(const ::simulator::simulator_stopResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::simulator::simulator_stopResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bool resp\n\
";
  }

  static const char* value(const ::simulator::simulator_stopResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::simulator::simulator_stopResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.resp);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct simulator_stopResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::simulator::simulator_stopResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::simulator::simulator_stopResponse_<ContainerAllocator>& v)
  {
    s << indent << "resp: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.resp);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SIMULATOR_MESSAGE_SIMULATOR_STOPRESPONSE_H
