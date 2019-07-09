// Generated by gencpp from file clips_ros/clearKDB.msg
// DO NOT EDIT!


#ifndef CLIPS_ROS_MESSAGE_CLEARKDB_H
#define CLIPS_ROS_MESSAGE_CLEARKDB_H

#include <ros/service_traits.h>


#include <clips_ros/clearKDBRequest.h>
#include <clips_ros/clearKDBResponse.h>


namespace clips_ros
{

struct clearKDB
{

typedef clearKDBRequest Request;
typedef clearKDBResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct clearKDB
} // namespace clips_ros


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::clips_ros::clearKDB > {
  static const char* value()
  {
    return "c0cba2f76fe2be4cac55cc053705feaa";
  }

  static const char* value(const ::clips_ros::clearKDB&) { return value(); }
};

template<>
struct DataType< ::clips_ros::clearKDB > {
  static const char* value()
  {
    return "clips_ros/clearKDB";
  }

  static const char* value(const ::clips_ros::clearKDB&) { return value(); }
};


// service_traits::MD5Sum< ::clips_ros::clearKDBRequest> should match 
// service_traits::MD5Sum< ::clips_ros::clearKDB > 
template<>
struct MD5Sum< ::clips_ros::clearKDBRequest>
{
  static const char* value()
  {
    return MD5Sum< ::clips_ros::clearKDB >::value();
  }
  static const char* value(const ::clips_ros::clearKDBRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::clips_ros::clearKDBRequest> should match 
// service_traits::DataType< ::clips_ros::clearKDB > 
template<>
struct DataType< ::clips_ros::clearKDBRequest>
{
  static const char* value()
  {
    return DataType< ::clips_ros::clearKDB >::value();
  }
  static const char* value(const ::clips_ros::clearKDBRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::clips_ros::clearKDBResponse> should match 
// service_traits::MD5Sum< ::clips_ros::clearKDB > 
template<>
struct MD5Sum< ::clips_ros::clearKDBResponse>
{
  static const char* value()
  {
    return MD5Sum< ::clips_ros::clearKDB >::value();
  }
  static const char* value(const ::clips_ros::clearKDBResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::clips_ros::clearKDBResponse> should match 
// service_traits::DataType< ::clips_ros::clearKDB > 
template<>
struct DataType< ::clips_ros::clearKDBResponse>
{
  static const char* value()
  {
    return DataType< ::clips_ros::clearKDB >::value();
  }
  static const char* value(const ::clips_ros::clearKDBResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // CLIPS_ROS_MESSAGE_CLEARKDB_H