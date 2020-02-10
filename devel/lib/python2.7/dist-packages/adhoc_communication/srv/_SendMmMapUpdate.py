# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from adhoc_communication/SendMmMapUpdateRequest.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import geometry_msgs.msg
import nav_msgs.msg
import genpy
import adhoc_communication.msg
import std_msgs.msg

class SendMmMapUpdateRequest(genpy.Message):
  _md5sum = "358f53a665e7b365236ba40e32cd5280"
  _type = "adhoc_communication/SendMmMapUpdateRequest"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """string dst_robot
string topic
adhoc_communication/MmMapUpdate map_update

================================================================================
MSG: adhoc_communication/MmMapUpdate
string src_robot
int32[] update_numbers
nav_msgs/OccupancyGrid map

================================================================================
MSG: nav_msgs/OccupancyGrid
# This represents a 2-D grid map, in which each cell represents the probability of
# occupancy.

Header header 

#MetaData for the map
MapMetaData info

# The map data, in row-major order, starting with (0,0).  Occupancy
# probabilities are in the range [0,100].  Unknown is -1.
int8[] data

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
string frame_id

================================================================================
MSG: nav_msgs/MapMetaData
# This hold basic information about the characterists of the OccupancyGrid

# The time at which the map was loaded
time map_load_time
# The map resolution [m/cell]
float32 resolution
# Map width [cells]
uint32 width
# Map height [cells]
uint32 height
# The origin of the map [m, m, rad].  This is the real-world pose of the
# cell (0,0) in the map.
geometry_msgs/Pose origin
================================================================================
MSG: geometry_msgs/Pose
# A representation of pose in free space, composed of position and orientation. 
Point position
Quaternion orientation

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

================================================================================
MSG: geometry_msgs/Quaternion
# This represents an orientation in free space in quaternion form.

float64 x
float64 y
float64 z
float64 w
"""
  __slots__ = ['dst_robot','topic','map_update']
  _slot_types = ['string','string','adhoc_communication/MmMapUpdate']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       dst_robot,topic,map_update

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(SendMmMapUpdateRequest, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.dst_robot is None:
        self.dst_robot = ''
      if self.topic is None:
        self.topic = ''
      if self.map_update is None:
        self.map_update = adhoc_communication.msg.MmMapUpdate()
    else:
      self.dst_robot = ''
      self.topic = ''
      self.map_update = adhoc_communication.msg.MmMapUpdate()

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self.dst_robot
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self.topic
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self.map_update.src_robot
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      length = len(self.map_update.update_numbers)
      buff.write(_struct_I.pack(length))
      pattern = '<%si'%length
      buff.write(struct.pack(pattern, *self.map_update.update_numbers))
      _x = self
      buff.write(_get_struct_3I().pack(_x.map_update.map.header.seq, _x.map_update.map.header.stamp.secs, _x.map_update.map.header.stamp.nsecs))
      _x = self.map_update.map.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_get_struct_2If2I7d().pack(_x.map_update.map.info.map_load_time.secs, _x.map_update.map.info.map_load_time.nsecs, _x.map_update.map.info.resolution, _x.map_update.map.info.width, _x.map_update.map.info.height, _x.map_update.map.info.origin.position.x, _x.map_update.map.info.origin.position.y, _x.map_update.map.info.origin.position.z, _x.map_update.map.info.origin.orientation.x, _x.map_update.map.info.origin.orientation.y, _x.map_update.map.info.origin.orientation.z, _x.map_update.map.info.origin.orientation.w))
      length = len(self.map_update.map.data)
      buff.write(_struct_I.pack(length))
      pattern = '<%sb'%length
      buff.write(struct.pack(pattern, *self.map_update.map.data))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      if self.map_update is None:
        self.map_update = adhoc_communication.msg.MmMapUpdate()
      end = 0
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.dst_robot = str[start:end].decode('utf-8')
      else:
        self.dst_robot = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.topic = str[start:end].decode('utf-8')
      else:
        self.topic = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.map_update.src_robot = str[start:end].decode('utf-8')
      else:
        self.map_update.src_robot = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      pattern = '<%si'%length
      start = end
      end += struct.calcsize(pattern)
      self.map_update.update_numbers = struct.unpack(pattern, str[start:end])
      _x = self
      start = end
      end += 12
      (_x.map_update.map.header.seq, _x.map_update.map.header.stamp.secs, _x.map_update.map.header.stamp.nsecs,) = _get_struct_3I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.map_update.map.header.frame_id = str[start:end].decode('utf-8')
      else:
        self.map_update.map.header.frame_id = str[start:end]
      _x = self
      start = end
      end += 76
      (_x.map_update.map.info.map_load_time.secs, _x.map_update.map.info.map_load_time.nsecs, _x.map_update.map.info.resolution, _x.map_update.map.info.width, _x.map_update.map.info.height, _x.map_update.map.info.origin.position.x, _x.map_update.map.info.origin.position.y, _x.map_update.map.info.origin.position.z, _x.map_update.map.info.origin.orientation.x, _x.map_update.map.info.origin.orientation.y, _x.map_update.map.info.origin.orientation.z, _x.map_update.map.info.origin.orientation.w,) = _get_struct_2If2I7d().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      pattern = '<%sb'%length
      start = end
      end += struct.calcsize(pattern)
      self.map_update.map.data = struct.unpack(pattern, str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self.dst_robot
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self.topic
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self.map_update.src_robot
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      length = len(self.map_update.update_numbers)
      buff.write(_struct_I.pack(length))
      pattern = '<%si'%length
      buff.write(self.map_update.update_numbers.tostring())
      _x = self
      buff.write(_get_struct_3I().pack(_x.map_update.map.header.seq, _x.map_update.map.header.stamp.secs, _x.map_update.map.header.stamp.nsecs))
      _x = self.map_update.map.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_get_struct_2If2I7d().pack(_x.map_update.map.info.map_load_time.secs, _x.map_update.map.info.map_load_time.nsecs, _x.map_update.map.info.resolution, _x.map_update.map.info.width, _x.map_update.map.info.height, _x.map_update.map.info.origin.position.x, _x.map_update.map.info.origin.position.y, _x.map_update.map.info.origin.position.z, _x.map_update.map.info.origin.orientation.x, _x.map_update.map.info.origin.orientation.y, _x.map_update.map.info.origin.orientation.z, _x.map_update.map.info.origin.orientation.w))
      length = len(self.map_update.map.data)
      buff.write(_struct_I.pack(length))
      pattern = '<%sb'%length
      buff.write(self.map_update.map.data.tostring())
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      if self.map_update is None:
        self.map_update = adhoc_communication.msg.MmMapUpdate()
      end = 0
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.dst_robot = str[start:end].decode('utf-8')
      else:
        self.dst_robot = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.topic = str[start:end].decode('utf-8')
      else:
        self.topic = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.map_update.src_robot = str[start:end].decode('utf-8')
      else:
        self.map_update.src_robot = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      pattern = '<%si'%length
      start = end
      end += struct.calcsize(pattern)
      self.map_update.update_numbers = numpy.frombuffer(str[start:end], dtype=numpy.int32, count=length)
      _x = self
      start = end
      end += 12
      (_x.map_update.map.header.seq, _x.map_update.map.header.stamp.secs, _x.map_update.map.header.stamp.nsecs,) = _get_struct_3I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.map_update.map.header.frame_id = str[start:end].decode('utf-8')
      else:
        self.map_update.map.header.frame_id = str[start:end]
      _x = self
      start = end
      end += 76
      (_x.map_update.map.info.map_load_time.secs, _x.map_update.map.info.map_load_time.nsecs, _x.map_update.map.info.resolution, _x.map_update.map.info.width, _x.map_update.map.info.height, _x.map_update.map.info.origin.position.x, _x.map_update.map.info.origin.position.y, _x.map_update.map.info.origin.position.z, _x.map_update.map.info.origin.orientation.x, _x.map_update.map.info.origin.orientation.y, _x.map_update.map.info.origin.orientation.z, _x.map_update.map.info.origin.orientation.w,) = _get_struct_2If2I7d().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      pattern = '<%sb'%length
      start = end
      end += struct.calcsize(pattern)
      self.map_update.map.data = numpy.frombuffer(str[start:end], dtype=numpy.int8, count=length)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_3I = None
def _get_struct_3I():
    global _struct_3I
    if _struct_3I is None:
        _struct_3I = struct.Struct("<3I")
    return _struct_3I
_struct_2If2I7d = None
def _get_struct_2If2I7d():
    global _struct_2If2I7d
    if _struct_2If2I7d is None:
        _struct_2If2I7d = struct.Struct("<2If2I7d")
    return _struct_2If2I7d
# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from adhoc_communication/SendMmMapUpdateResponse.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class SendMmMapUpdateResponse(genpy.Message):
  _md5sum = "284aa12dd9e9e760802ac9f38036ea5e"
  _type = "adhoc_communication/SendMmMapUpdateResponse"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """uint8 status

"""
  __slots__ = ['status']
  _slot_types = ['uint8']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       status

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(SendMmMapUpdateResponse, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.status is None:
        self.status = 0
    else:
      self.status = 0

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      buff.write(_get_struct_B().pack(self.status))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
      start = end
      end += 1
      (self.status,) = _get_struct_B().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      buff.write(_get_struct_B().pack(self.status))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      end = 0
      start = end
      end += 1
      (self.status,) = _get_struct_B().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_B = None
def _get_struct_B():
    global _struct_B
    if _struct_B is None:
        _struct_B = struct.Struct("<B")
    return _struct_B
class SendMmMapUpdate(object):
  _type          = 'adhoc_communication/SendMmMapUpdate'
  _md5sum = '6887084fcfdf3574f5698c6a4c7aeeb6'
  _request_class  = SendMmMapUpdateRequest
  _response_class = SendMmMapUpdateResponse
