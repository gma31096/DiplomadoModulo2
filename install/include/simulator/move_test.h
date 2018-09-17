// Generated by gencpp from file simulator/move_test.msg
// DO NOT EDIT!


#ifndef SIMULATOR_MESSAGE_MOVE_TEST_H
#define SIMULATOR_MESSAGE_MOVE_TEST_H

#include <ros/service_traits.h>


#include <simulator/move_testRequest.h>
#include <simulator/move_testResponse.h>


namespace simulator
{

struct move_test
{

typedef move_testRequest Request;
typedef move_testResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct move_test
} // namespace simulator


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::simulator::move_test > {
  static const char* value()
  {
    return "aa748166a5bb70fc4aeb3cae4da517f9";
  }

  static const char* value(const ::simulator::move_test&) { return value(); }
};

template<>
struct DataType< ::simulator::move_test > {
  static const char* value()
  {
    return "simulator/move_test";
  }

  static const char* value(const ::simulator::move_test&) { return value(); }
};


// service_traits::MD5Sum< ::simulator::move_testRequest> should match 
// service_traits::MD5Sum< ::simulator::move_test > 
template<>
struct MD5Sum< ::simulator::move_testRequest>
{
  static const char* value()
  {
    return MD5Sum< ::simulator::move_test >::value();
  }
  static const char* value(const ::simulator::move_testRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::simulator::move_testRequest> should match 
// service_traits::DataType< ::simulator::move_test > 
template<>
struct DataType< ::simulator::move_testRequest>
{
  static const char* value()
  {
    return DataType< ::simulator::move_test >::value();
  }
  static const char* value(const ::simulator::move_testRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::simulator::move_testResponse> should match 
// service_traits::MD5Sum< ::simulator::move_test > 
template<>
struct MD5Sum< ::simulator::move_testResponse>
{
  static const char* value()
  {
    return MD5Sum< ::simulator::move_test >::value();
  }
  static const char* value(const ::simulator::move_testResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::simulator::move_testResponse> should match 
// service_traits::DataType< ::simulator::move_test > 
template<>
struct DataType< ::simulator::move_testResponse>
{
  static const char* value()
  {
    return DataType< ::simulator::move_test >::value();
  }
  static const char* value(const ::simulator::move_testResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // SIMULATOR_MESSAGE_MOVE_TEST_H