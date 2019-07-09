// Generated by gencpp from file simulator/simulator_object_interaction.msg
// DO NOT EDIT!


#ifndef SIMULATOR_MESSAGE_SIMULATOR_OBJECT_INTERACTION_H
#define SIMULATOR_MESSAGE_SIMULATOR_OBJECT_INTERACTION_H

#include <ros/service_traits.h>


#include <simulator/simulator_object_interactionRequest.h>
#include <simulator/simulator_object_interactionResponse.h>


namespace simulator
{

struct simulator_object_interaction
{

typedef simulator_object_interactionRequest Request;
typedef simulator_object_interactionResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct simulator_object_interaction
} // namespace simulator


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::simulator::simulator_object_interaction > {
  static const char* value()
  {
    return "5f2d08a4b7005ec192d2f5e0b480a776";
  }

  static const char* value(const ::simulator::simulator_object_interaction&) { return value(); }
};

template<>
struct DataType< ::simulator::simulator_object_interaction > {
  static const char* value()
  {
    return "simulator/simulator_object_interaction";
  }

  static const char* value(const ::simulator::simulator_object_interaction&) { return value(); }
};


// service_traits::MD5Sum< ::simulator::simulator_object_interactionRequest> should match 
// service_traits::MD5Sum< ::simulator::simulator_object_interaction > 
template<>
struct MD5Sum< ::simulator::simulator_object_interactionRequest>
{
  static const char* value()
  {
    return MD5Sum< ::simulator::simulator_object_interaction >::value();
  }
  static const char* value(const ::simulator::simulator_object_interactionRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::simulator::simulator_object_interactionRequest> should match 
// service_traits::DataType< ::simulator::simulator_object_interaction > 
template<>
struct DataType< ::simulator::simulator_object_interactionRequest>
{
  static const char* value()
  {
    return DataType< ::simulator::simulator_object_interaction >::value();
  }
  static const char* value(const ::simulator::simulator_object_interactionRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::simulator::simulator_object_interactionResponse> should match 
// service_traits::MD5Sum< ::simulator::simulator_object_interaction > 
template<>
struct MD5Sum< ::simulator::simulator_object_interactionResponse>
{
  static const char* value()
  {
    return MD5Sum< ::simulator::simulator_object_interaction >::value();
  }
  static const char* value(const ::simulator::simulator_object_interactionResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::simulator::simulator_object_interactionResponse> should match 
// service_traits::DataType< ::simulator::simulator_object_interaction > 
template<>
struct DataType< ::simulator::simulator_object_interactionResponse>
{
  static const char* value()
  {
    return DataType< ::simulator::simulator_object_interaction >::value();
  }
  static const char* value(const ::simulator::simulator_object_interactionResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // SIMULATOR_MESSAGE_SIMULATOR_OBJECT_INTERACTION_H
