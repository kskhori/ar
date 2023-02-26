// Generated by gencpp from file sample_c/sample_message.msg
// DO NOT EDIT!


#ifndef SAMPLE_C_MESSAGE_SAMPLE_MESSAGE_H
#define SAMPLE_C_MESSAGE_SAMPLE_MESSAGE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace sample_c
{
template <class ContainerAllocator>
struct sample_message_
{
  typedef sample_message_<ContainerAllocator> Type;

  sample_message_()
    : message()
    , count(0)  {
    }
  sample_message_(const ContainerAllocator& _alloc)
    : message(_alloc)
    , count(0)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _message_type;
  _message_type message;

   typedef uint32_t _count_type;
  _count_type count;





  typedef boost::shared_ptr< ::sample_c::sample_message_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::sample_c::sample_message_<ContainerAllocator> const> ConstPtr;

}; // struct sample_message_

typedef ::sample_c::sample_message_<std::allocator<void> > sample_message;

typedef boost::shared_ptr< ::sample_c::sample_message > sample_messagePtr;
typedef boost::shared_ptr< ::sample_c::sample_message const> sample_messageConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::sample_c::sample_message_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::sample_c::sample_message_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace sample_c

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'sample_c': ['/home/srd-gtune/catkin_ws/src/ar/sample_c/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::sample_c::sample_message_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::sample_c::sample_message_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sample_c::sample_message_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sample_c::sample_message_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sample_c::sample_message_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sample_c::sample_message_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::sample_c::sample_message_<ContainerAllocator> >
{
  static const char* value()
  {
    return "89498e8c3e7e4e4d3ec5e32aa108f04d";
  }

  static const char* value(const ::sample_c::sample_message_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x89498e8c3e7e4e4dULL;
  static const uint64_t static_value2 = 0x3ec5e32aa108f04dULL;
};

template<class ContainerAllocator>
struct DataType< ::sample_c::sample_message_<ContainerAllocator> >
{
  static const char* value()
  {
    return "sample_c/sample_message";
  }

  static const char* value(const ::sample_c::sample_message_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::sample_c::sample_message_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string message\n\
uint32 count\n\
";
  }

  static const char* value(const ::sample_c::sample_message_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::sample_c::sample_message_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.message);
      stream.next(m.count);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct sample_message_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::sample_c::sample_message_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::sample_c::sample_message_<ContainerAllocator>& v)
  {
    s << indent << "message: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.message);
    s << indent << "count: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.count);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SAMPLE_C_MESSAGE_SAMPLE_MESSAGE_H
