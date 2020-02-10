// Generated by gencpp from file openni2_camera/GetSerial.msg
// DO NOT EDIT!


#ifndef OPENNI2_CAMERA_MESSAGE_GETSERIAL_H
#define OPENNI2_CAMERA_MESSAGE_GETSERIAL_H

#include <ros/service_traits.h>


#include <openni2_camera/GetSerialRequest.h>
#include <openni2_camera/GetSerialResponse.h>


namespace openni2_camera
{

struct GetSerial
{

typedef GetSerialRequest Request;
typedef GetSerialResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct GetSerial
} // namespace openni2_camera


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::openni2_camera::GetSerial > {
  static const char* value()
  {
    return "fca40cf463282a80db4e2037c8a61741";
  }

  static const char* value(const ::openni2_camera::GetSerial&) { return value(); }
};

template<>
struct DataType< ::openni2_camera::GetSerial > {
  static const char* value()
  {
    return "openni2_camera/GetSerial";
  }

  static const char* value(const ::openni2_camera::GetSerial&) { return value(); }
};


// service_traits::MD5Sum< ::openni2_camera::GetSerialRequest> should match 
// service_traits::MD5Sum< ::openni2_camera::GetSerial > 
template<>
struct MD5Sum< ::openni2_camera::GetSerialRequest>
{
  static const char* value()
  {
    return MD5Sum< ::openni2_camera::GetSerial >::value();
  }
  static const char* value(const ::openni2_camera::GetSerialRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::openni2_camera::GetSerialRequest> should match 
// service_traits::DataType< ::openni2_camera::GetSerial > 
template<>
struct DataType< ::openni2_camera::GetSerialRequest>
{
  static const char* value()
  {
    return DataType< ::openni2_camera::GetSerial >::value();
  }
  static const char* value(const ::openni2_camera::GetSerialRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::openni2_camera::GetSerialResponse> should match 
// service_traits::MD5Sum< ::openni2_camera::GetSerial > 
template<>
struct MD5Sum< ::openni2_camera::GetSerialResponse>
{
  static const char* value()
  {
    return MD5Sum< ::openni2_camera::GetSerial >::value();
  }
  static const char* value(const ::openni2_camera::GetSerialResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::openni2_camera::GetSerialResponse> should match 
// service_traits::DataType< ::openni2_camera::GetSerial > 
template<>
struct DataType< ::openni2_camera::GetSerialResponse>
{
  static const char* value()
  {
    return DataType< ::openni2_camera::GetSerial >::value();
  }
  static const char* value(const ::openni2_camera::GetSerialResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // OPENNI2_CAMERA_MESSAGE_GETSERIAL_H
