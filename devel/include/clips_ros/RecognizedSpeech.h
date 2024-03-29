// Generated by gencpp from file clips_ros/RecognizedSpeech.msg
// DO NOT EDIT!


#ifndef CLIPS_ROS_MESSAGE_RECOGNIZEDSPEECH_H
#define CLIPS_ROS_MESSAGE_RECOGNIZEDSPEECH_H


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
struct RecognizedSpeech_
{
  typedef RecognizedSpeech_<ContainerAllocator> Type;

  RecognizedSpeech_()
    : hypothesis()
    , confidences()  {
    }
  RecognizedSpeech_(const ContainerAllocator& _alloc)
    : hypothesis(_alloc)
    , confidences(_alloc)  {
  (void)_alloc;
    }



   typedef std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > , typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::other >  _hypothesis_type;
  _hypothesis_type hypothesis;

   typedef std::vector<float, typename ContainerAllocator::template rebind<float>::other >  _confidences_type;
  _confidences_type confidences;




  typedef boost::shared_ptr< ::clips_ros::RecognizedSpeech_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::clips_ros::RecognizedSpeech_<ContainerAllocator> const> ConstPtr;

}; // struct RecognizedSpeech_

typedef ::clips_ros::RecognizedSpeech_<std::allocator<void> > RecognizedSpeech;

typedef boost::shared_ptr< ::clips_ros::RecognizedSpeech > RecognizedSpeechPtr;
typedef boost::shared_ptr< ::clips_ros::RecognizedSpeech const> RecognizedSpeechConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::clips_ros::RecognizedSpeech_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::clips_ros::RecognizedSpeech_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::clips_ros::RecognizedSpeech_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::clips_ros::RecognizedSpeech_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::clips_ros::RecognizedSpeech_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::clips_ros::RecognizedSpeech_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::clips_ros::RecognizedSpeech_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::clips_ros::RecognizedSpeech_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::clips_ros::RecognizedSpeech_<ContainerAllocator> >
{
  static const char* value()
  {
    return "b2cc166e4fd867bfc13e04afeee883be";
  }

  static const char* value(const ::clips_ros::RecognizedSpeech_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xb2cc166e4fd867bfULL;
  static const uint64_t static_value2 = 0xc13e04afeee883beULL;
};

template<class ContainerAllocator>
struct DataType< ::clips_ros::RecognizedSpeech_<ContainerAllocator> >
{
  static const char* value()
  {
    return "clips_ros/RecognizedSpeech";
  }

  static const char* value(const ::clips_ros::RecognizedSpeech_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::clips_ros::RecognizedSpeech_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string[] hypothesis\n\
float32[] confidences\n\
";
  }

  static const char* value(const ::clips_ros::RecognizedSpeech_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::clips_ros::RecognizedSpeech_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.hypothesis);
      stream.next(m.confidences);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct RecognizedSpeech_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::clips_ros::RecognizedSpeech_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::clips_ros::RecognizedSpeech_<ContainerAllocator>& v)
  {
    s << indent << "hypothesis[]" << std::endl;
    for (size_t i = 0; i < v.hypothesis.size(); ++i)
    {
      s << indent << "  hypothesis[" << i << "]: ";
      Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.hypothesis[i]);
    }
    s << indent << "confidences[]" << std::endl;
    for (size_t i = 0; i < v.confidences.size(); ++i)
    {
      s << indent << "  confidences[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.confidences[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // CLIPS_ROS_MESSAGE_RECOGNIZEDSPEECH_H
