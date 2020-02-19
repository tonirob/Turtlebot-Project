// Generated by gencpp from file astra_camera/SetUVCGainRequest.msg
// DO NOT EDIT!


#ifndef ASTRA_CAMERA_MESSAGE_SETUVCGAINREQUEST_H
#define ASTRA_CAMERA_MESSAGE_SETUVCGAINREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace astra_camera
{
template <class ContainerAllocator>
struct SetUVCGainRequest_
{
  typedef SetUVCGainRequest_<ContainerAllocator> Type;

  SetUVCGainRequest_()
    : gain(0)  {
    }
  SetUVCGainRequest_(const ContainerAllocator& _alloc)
    : gain(0)  {
  (void)_alloc;
    }



   typedef int32_t _gain_type;
  _gain_type gain;





  typedef boost::shared_ptr< ::astra_camera::SetUVCGainRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::astra_camera::SetUVCGainRequest_<ContainerAllocator> const> ConstPtr;

}; // struct SetUVCGainRequest_

typedef ::astra_camera::SetUVCGainRequest_<std::allocator<void> > SetUVCGainRequest;

typedef boost::shared_ptr< ::astra_camera::SetUVCGainRequest > SetUVCGainRequestPtr;
typedef boost::shared_ptr< ::astra_camera::SetUVCGainRequest const> SetUVCGainRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::astra_camera::SetUVCGainRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::astra_camera::SetUVCGainRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace astra_camera

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'sensor_msgs': ['/opt/ros/melodic/share/sensor_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/melodic/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/melodic/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::astra_camera::SetUVCGainRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::astra_camera::SetUVCGainRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::astra_camera::SetUVCGainRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::astra_camera::SetUVCGainRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::astra_camera::SetUVCGainRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::astra_camera::SetUVCGainRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::astra_camera::SetUVCGainRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "164d2201bda8580473ff7023ba27f703";
  }

  static const char* value(const ::astra_camera::SetUVCGainRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x164d2201bda85804ULL;
  static const uint64_t static_value2 = 0x73ff7023ba27f703ULL;
};

template<class ContainerAllocator>
struct DataType< ::astra_camera::SetUVCGainRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "astra_camera/SetUVCGainRequest";
  }

  static const char* value(const ::astra_camera::SetUVCGainRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::astra_camera::SetUVCGainRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int32 gain\n"
;
  }

  static const char* value(const ::astra_camera::SetUVCGainRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::astra_camera::SetUVCGainRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.gain);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SetUVCGainRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::astra_camera::SetUVCGainRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::astra_camera::SetUVCGainRequest_<ContainerAllocator>& v)
  {
    s << indent << "gain: ";
    Printer<int32_t>::stream(s, indent + "  ", v.gain);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ASTRA_CAMERA_MESSAGE_SETUVCGAINREQUEST_H
