// Generated by gencpp from file simulator/simulator_baseRequest.msg
// DO NOT EDIT!


#ifndef SIMULATOR_MESSAGE_SIMULATOR_BASEREQUEST_H
#define SIMULATOR_MESSAGE_SIMULATOR_BASEREQUEST_H


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
struct simulator_baseRequest_
{
  typedef simulator_baseRequest_<ContainerAllocator> Type;

  simulator_baseRequest_()
    : theta(0.0)
    , distance(0.0)
    , x1(0.0)
    , y1(0.0)
    , new_simulation(0)  {
    }
  simulator_baseRequest_(const ContainerAllocator& _alloc)
    : theta(0.0)
    , distance(0.0)
    , x1(0.0)
    , y1(0.0)
    , new_simulation(0)  {
  (void)_alloc;
    }



   typedef float _theta_type;
  _theta_type theta;

   typedef float _distance_type;
  _distance_type distance;

   typedef float _x1_type;
  _x1_type x1;

   typedef float _y1_type;
  _y1_type y1;

   typedef int32_t _new_simulation_type;
  _new_simulation_type new_simulation;




  typedef boost::shared_ptr< ::simulator::simulator_baseRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::simulator::simulator_baseRequest_<ContainerAllocator> const> ConstPtr;

}; // struct simulator_baseRequest_

typedef ::simulator::simulator_baseRequest_<std::allocator<void> > simulator_baseRequest;

typedef boost::shared_ptr< ::simulator::simulator_baseRequest > simulator_baseRequestPtr;
typedef boost::shared_ptr< ::simulator::simulator_baseRequest const> simulator_baseRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::simulator::simulator_baseRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::simulator::simulator_baseRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace simulator

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'simulator': ['/home/diego/catkin_ws/src/simulator/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::simulator::simulator_baseRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::simulator::simulator_baseRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::simulator::simulator_baseRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::simulator::simulator_baseRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::simulator::simulator_baseRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::simulator::simulator_baseRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::simulator::simulator_baseRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "b479603405130a3c6f5c654e918df66b";
  }

  static const char* value(const ::simulator::simulator_baseRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xb479603405130a3cULL;
  static const uint64_t static_value2 = 0x6f5c654e918df66bULL;
};

template<class ContainerAllocator>
struct DataType< ::simulator::simulator_baseRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "simulator/simulator_baseRequest";
  }

  static const char* value(const ::simulator::simulator_baseRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::simulator::simulator_baseRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32 theta\n\
float32 distance\n\
float32 x1\n\
float32 y1\n\
int32 new_simulation\n\
";
  }

  static const char* value(const ::simulator::simulator_baseRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::simulator::simulator_baseRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.theta);
      stream.next(m.distance);
      stream.next(m.x1);
      stream.next(m.y1);
      stream.next(m.new_simulation);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct simulator_baseRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::simulator::simulator_baseRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::simulator::simulator_baseRequest_<ContainerAllocator>& v)
  {
    s << indent << "theta: ";
    Printer<float>::stream(s, indent + "  ", v.theta);
    s << indent << "distance: ";
    Printer<float>::stream(s, indent + "  ", v.distance);
    s << indent << "x1: ";
    Printer<float>::stream(s, indent + "  ", v.x1);
    s << indent << "y1: ";
    Printer<float>::stream(s, indent + "  ", v.y1);
    s << indent << "new_simulation: ";
    Printer<int32_t>::stream(s, indent + "  ", v.new_simulation);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SIMULATOR_MESSAGE_SIMULATOR_BASEREQUEST_H
