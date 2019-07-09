// Generated by gencpp from file simulator/simulator_set_light_position.msg
// DO NOT EDIT!


#ifndef SIMULATOR_MESSAGE_SIMULATOR_SET_LIGHT_POSITION_H
#define SIMULATOR_MESSAGE_SIMULATOR_SET_LIGHT_POSITION_H

#include <ros/service_traits.h>


#include <simulator/simulator_set_light_positionRequest.h>
#include <simulator/simulator_set_light_positionResponse.h>


namespace simulator
{

struct simulator_set_light_position
{

typedef simulator_set_light_positionRequest Request;
typedef simulator_set_light_positionResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct simulator_set_light_position
} // namespace simulator


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::simulator::simulator_set_light_position > {
  static const char* value()
  {
    return "d56d73ee632c8aa7c9431df2ebbb2712";
  }

  static const char* value(const ::simulator::simulator_set_light_position&) { return value(); }
};

template<>
struct DataType< ::simulator::simulator_set_light_position > {
  static const char* value()
  {
    return "simulator/simulator_set_light_position";
  }

  static const char* value(const ::simulator::simulator_set_light_position&) { return value(); }
};


// service_traits::MD5Sum< ::simulator::simulator_set_light_positionRequest> should match 
// service_traits::MD5Sum< ::simulator::simulator_set_light_position > 
template<>
struct MD5Sum< ::simulator::simulator_set_light_positionRequest>
{
  static const char* value()
  {
    return MD5Sum< ::simulator::simulator_set_light_position >::value();
  }
  static const char* value(const ::simulator::simulator_set_light_positionRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::simulator::simulator_set_light_positionRequest> should match 
// service_traits::DataType< ::simulator::simulator_set_light_position > 
template<>
struct DataType< ::simulator::simulator_set_light_positionRequest>
{
  static const char* value()
  {
    return DataType< ::simulator::simulator_set_light_position >::value();
  }
  static const char* value(const ::simulator::simulator_set_light_positionRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::simulator::simulator_set_light_positionResponse> should match 
// service_traits::MD5Sum< ::simulator::simulator_set_light_position > 
template<>
struct MD5Sum< ::simulator::simulator_set_light_positionResponse>
{
  static const char* value()
  {
    return MD5Sum< ::simulator::simulator_set_light_position >::value();
  }
  static const char* value(const ::simulator::simulator_set_light_positionResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::simulator::simulator_set_light_positionResponse> should match 
// service_traits::DataType< ::simulator::simulator_set_light_position > 
template<>
struct DataType< ::simulator::simulator_set_light_positionResponse>
{
  static const char* value()
  {
    return DataType< ::simulator::simulator_set_light_position >::value();
  }
  static const char* value(const ::simulator::simulator_set_light_positionResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // SIMULATOR_MESSAGE_SIMULATOR_SET_LIGHT_POSITION_H
