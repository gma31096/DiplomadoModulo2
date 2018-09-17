# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from simulator/Parameters.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class Parameters(genpy.Message):
  _md5sum = "755c9aa110b0db29409f1bf3fac9c8f0"
  _type = "simulator/Parameters"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """float32 robot_x
float32 robot_y
float32 robot_theta
float32 robot_radio
float32 robot_max_advance
float32 robot_turn_angle
int32 laser_num_sensors
float32 laser_origin
float32 laser_range
float32 laser_value
string world_name
bool noise
"""
  __slots__ = ['robot_x','robot_y','robot_theta','robot_radio','robot_max_advance','robot_turn_angle','laser_num_sensors','laser_origin','laser_range','laser_value','world_name','noise']
  _slot_types = ['float32','float32','float32','float32','float32','float32','int32','float32','float32','float32','string','bool']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       robot_x,robot_y,robot_theta,robot_radio,robot_max_advance,robot_turn_angle,laser_num_sensors,laser_origin,laser_range,laser_value,world_name,noise

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(Parameters, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.robot_x is None:
        self.robot_x = 0.
      if self.robot_y is None:
        self.robot_y = 0.
      if self.robot_theta is None:
        self.robot_theta = 0.
      if self.robot_radio is None:
        self.robot_radio = 0.
      if self.robot_max_advance is None:
        self.robot_max_advance = 0.
      if self.robot_turn_angle is None:
        self.robot_turn_angle = 0.
      if self.laser_num_sensors is None:
        self.laser_num_sensors = 0
      if self.laser_origin is None:
        self.laser_origin = 0.
      if self.laser_range is None:
        self.laser_range = 0.
      if self.laser_value is None:
        self.laser_value = 0.
      if self.world_name is None:
        self.world_name = ''
      if self.noise is None:
        self.noise = False
    else:
      self.robot_x = 0.
      self.robot_y = 0.
      self.robot_theta = 0.
      self.robot_radio = 0.
      self.robot_max_advance = 0.
      self.robot_turn_angle = 0.
      self.laser_num_sensors = 0
      self.laser_origin = 0.
      self.laser_range = 0.
      self.laser_value = 0.
      self.world_name = ''
      self.noise = False

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
      _x = self
      buff.write(_struct_6fi3f.pack(_x.robot_x, _x.robot_y, _x.robot_theta, _x.robot_radio, _x.robot_max_advance, _x.robot_turn_angle, _x.laser_num_sensors, _x.laser_origin, _x.laser_range, _x.laser_value))
      _x = self.world_name
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      if python3:
        buff.write(struct.pack('<I%sB'%length, length, *_x))
      else:
        buff.write(struct.pack('<I%ss'%length, length, _x))
      buff.write(_struct_B.pack(self.noise))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
      _x = self
      start = end
      end += 40
      (_x.robot_x, _x.robot_y, _x.robot_theta, _x.robot_radio, _x.robot_max_advance, _x.robot_turn_angle, _x.laser_num_sensors, _x.laser_origin, _x.laser_range, _x.laser_value,) = _struct_6fi3f.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.world_name = str[start:end].decode('utf-8')
      else:
        self.world_name = str[start:end]
      start = end
      end += 1
      (self.noise,) = _struct_B.unpack(str[start:end])
      self.noise = bool(self.noise)
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
      _x = self
      buff.write(_struct_6fi3f.pack(_x.robot_x, _x.robot_y, _x.robot_theta, _x.robot_radio, _x.robot_max_advance, _x.robot_turn_angle, _x.laser_num_sensors, _x.laser_origin, _x.laser_range, _x.laser_value))
      _x = self.world_name
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      if python3:
        buff.write(struct.pack('<I%sB'%length, length, *_x))
      else:
        buff.write(struct.pack('<I%ss'%length, length, _x))
      buff.write(_struct_B.pack(self.noise))
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
      _x = self
      start = end
      end += 40
      (_x.robot_x, _x.robot_y, _x.robot_theta, _x.robot_radio, _x.robot_max_advance, _x.robot_turn_angle, _x.laser_num_sensors, _x.laser_origin, _x.laser_range, _x.laser_value,) = _struct_6fi3f.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.world_name = str[start:end].decode('utf-8')
      else:
        self.world_name = str[start:end]
      start = end
      end += 1
      (self.noise,) = _struct_B.unpack(str[start:end])
      self.noise = bool(self.noise)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
_struct_B = struct.Struct("<B")
_struct_6fi3f = struct.Struct("<6fi3f")
