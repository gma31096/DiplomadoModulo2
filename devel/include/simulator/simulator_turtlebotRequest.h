// Generated by gencpp from file simulator/simulator_turtlebotRequest.msg
// DO NOT EDIT!


#ifndef SIMULATOR_MESSAGE_SIMULATOR_TURTLEBOTREQUEST_H
#define SIMULATOR_MESSAGE_SIMULATOR_TURTLEBOTREQUEST_H


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
struct simulator_turtlebotRequest_
{
  typedef simulator_turtlebotRequest_<ContainerAllocator> Type;

  simulator_turtlebotRequest_()
    : theta(0.0)
    , distance(0.0)  {
    }
  simulator_turtlebotRequest_(const ContainerAllocator& _alloc)
    : theta(0.0)
    , distance(0.0)  {
  (void)_alloc;
    }



   typedef float _theta_type;
  _theta_type theta;

   typedef float _distance_type;
  _distance_type distance;




  typedef boost::shared_ptr< ::simulator::simulator_turtlebotRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::simulator::simulator_turtlebotRequest_<ContainerAllocator> const> ConstPtr;

}; // struct simulator_turtlebotRequest_

typedef ::simulator::simulator_turtlebotRequest_<std::allocator<void> > simulator_turtlebotRequest;

typedef boost::shared_ptr< ::simulator::simulator_turtlebotRequest > simulator_turtlebotRequestPtr;
typedef boost::shared_ptr< ::simulator::simulator_turtlebotRequest const> simulator_turtlebotRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::simulator::simulator_turtlebotRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::simulator::simulator_turtlebotRequest_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::simulator::simulator_turtlebotRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::simulator::simulator_turtlebotRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::simulator::simulator_turtlebotRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::simulator::simulator_turtlebotRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::simulator::simulator_turtlebotRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::simulator::simulator_turtlebotRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::simulator::simulator_turtlebotRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "428ccb9659c7d3f0c6c3a803af59d6ab";
  }

  static const char* value(const ::simulator::simulator_turtlebotRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x428ccb9659c7d3f0ULL;
  static const uint64_t static_value2 = 0xc6c3a803af59d6abULL;
};

template<class ContainerAllocator>
struct DataType< ::simulator::simulator_turtlebotRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "simulator/simulator_turtlebotRequest";
  }

  static const char* value(const ::simulator::simulator_turtlebotRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::simulator::simulator_turtlebotRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32 theta\n\
float32 distance\n\
";
  }

  static const char* value(const ::simulator::simulator_turtlebotRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::simulator::simulator_turtlebotRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.theta);
      stream.next(m.distance);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct simulator_turtlebotRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::simulator::simulator_turtlebotRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::simulator::simulator_turtlebotRequest_<ContainerAllocator>& v)
  {
    s << indent << "theta: ";
    Printer<float>::stream(s, indent + "  ", v.theta);
    s << indent << "distance: ";
    Printer<float>::stream(s, indent + "  ", v.distance);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SIMULATOR_MESSAGE_SIMULATOR_TURTLEBOTREQUEST_H