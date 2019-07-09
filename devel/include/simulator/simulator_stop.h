// Generated by gencpp from file simulator/simulator_stop.msg
// DO NOT EDIT!


#ifndef SIMULATOR_MESSAGE_SIMULATOR_STOP_H
#define SIMULATOR_MESSAGE_SIMULATOR_STOP_H

#include <ros/service_traits.h>


#include <simulator/simulator_stopRequest.h>
#include <simulator/simulator_stopResponse.h>


namespace simulator
{

struct simulator_stop
{

typedef simulator_stopRequest Request;
typedef simulator_stopResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct simulator_stop
} // namespace simulator


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::simulator::simulator_stop > {
  static const char* value()
  {
    return "095e4397fe01973ad978411bb58eda37";
  }

  static const char* value(const ::simulator::simulator_stop&) { return value(); }
};

template<>
struct DataType< ::simulator::simulator_stop > {
  static const char* value()
  {
    return "simulator/simulator_stop";
  }

  static const char* value(const ::simulator::simulator_stop&) { return value(); }
};


// service_traits::MD5Sum< ::simulator::simulator_stopRequest> should match 
// service_traits::MD5Sum< ::simulator::simulator_stop > 
template<>
struct MD5Sum< ::simulator::simulator_stopRequest>
{
  static const char* value()
  {
    return MD5Sum< ::simulator::simulator_stop >::value();
  }
  static const char* value(const ::simulator::simulator_stopRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::simulator::simulator_stopRequest> should match 
// service_traits::DataType< ::simulator::simulator_stop > 
template<>
struct DataType< ::simulator::simulator_stopRequest>
{
  static const char* value()
  {
    return DataType< ::simulator::simulator_stop >::value();
  }
  static const char* value(const ::simulator::simulator_stopRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::simulator::simulator_stopResponse> should match 
// service_traits::MD5Sum< ::simulator::simulator_stop > 
template<>
struct MD5Sum< ::simulator::simulator_stopResponse>
{
  static const char* value()
  {
    return MD5Sum< ::simulator::simulator_stop >::value();
  }
  static const char* value(const ::simulator::simulator_stopResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::simulator::simulator_stopResponse> should match 
// service_traits::DataType< ::simulator::simulator_stop > 
template<>
struct DataType< ::simulator::simulator_stopResponse>
{
  static const char* value()
  {
    return DataType< ::simulator::simulator_stop >::value();
  }
  static const char* value(const ::simulator::simulator_stopResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // SIMULATOR_MESSAGE_SIMULATOR_STOP_H