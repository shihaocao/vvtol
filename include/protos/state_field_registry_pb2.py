# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: include/protos/state_field_registry.proto

import sys
_b=sys.version_info[0]<3 and (lambda x:x) or (lambda x:x.encode('latin1'))
from google.protobuf.internal import enum_type_wrapper
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()




DESCRIPTOR = _descriptor.FileDescriptor(
  name='include/protos/state_field_registry.proto',
  package='',
  syntax='proto3',
  serialized_options=None,
  serialized_pb=_b('\n)include/protos/state_field_registry.proto\" \n\x08Vector3f\x12\x14\n\x08\x65lements\x18\x01 \x03(\x02\x42\x02\x10\x01\" \n\x08Vector4f\x12\x14\n\x08\x65lements\x18\x01 \x03(\x02\x42\x02\x10\x01\"\x8c\x04\n\x12StateFieldRegistry\x12$\n\x1ctime_t_average_cycle_time_us\x18\x01 \x01(\x02\x12%\n\x1dtime_t_control_cycle_limit_us\x18\x02 \x01(\x05\x12 \n\x18time_t_last_cycle_end_us\x18\x03 \x01(\r\x12\x1c\n\x14last_transition_ccno\x18\x04 \x01(\x04\x12\x1d\n\x15mcl_control_cycle_num\x18\x05 \x01(\x04\x12#\n\x08mc_state\x18\x06 \x01(\x0e\x32\x11.MainControlState\x12*\n\x0ftarget_mc_state\x18\x07 \x01(\x0e\x32\x11.MainControlState\x12#\n\tgnc_state\x18\x08 \x01(\x0e\x32\x10.GncControlState\x12*\n\x10target_gnc_state\x18\t \x01(\x0e\x32\x10.GncControlState\x12\'\n\x14imu_linear_acc_vec_f\x18\n \x01(\x0b\x32\t.Vector3f\x12 \n\rimu_acc_vec_f\x18\x0b \x01(\x0b\x32\t.Vector3f\x12\x1e\n\x0bimu_gyr_vec\x18\x0c \x01(\x0b\x32\t.Vector3f\x12 \n\rimu_euler_vec\x18\r \x01(\x0b\x32\t.Vector4f\x12\x1b\n\x08imu_quat\x18\x0e \x01(\x0b\x32\t.Vector4f* \n\x10MainControlState\x12\x0c\n\x08MC_EMPTY\x10\x00* \n\x0fGncControlState\x12\r\n\tGNC_EMPTY\x10\x00\x62\x06proto3')
)

_MAINCONTROLSTATE = _descriptor.EnumDescriptor(
  name='MainControlState',
  full_name='MainControlState',
  filename=None,
  file=DESCRIPTOR,
  values=[
    _descriptor.EnumValueDescriptor(
      name='MC_EMPTY', index=0, number=0,
      serialized_options=None,
      type=None),
  ],
  containing_type=None,
  serialized_options=None,
  serialized_start=640,
  serialized_end=672,
)
_sym_db.RegisterEnumDescriptor(_MAINCONTROLSTATE)

MainControlState = enum_type_wrapper.EnumTypeWrapper(_MAINCONTROLSTATE)
_GNCCONTROLSTATE = _descriptor.EnumDescriptor(
  name='GncControlState',
  full_name='GncControlState',
  filename=None,
  file=DESCRIPTOR,
  values=[
    _descriptor.EnumValueDescriptor(
      name='GNC_EMPTY', index=0, number=0,
      serialized_options=None,
      type=None),
  ],
  containing_type=None,
  serialized_options=None,
  serialized_start=674,
  serialized_end=706,
)
_sym_db.RegisterEnumDescriptor(_GNCCONTROLSTATE)

GncControlState = enum_type_wrapper.EnumTypeWrapper(_GNCCONTROLSTATE)
MC_EMPTY = 0
GNC_EMPTY = 0



_VECTOR3F = _descriptor.Descriptor(
  name='Vector3f',
  full_name='Vector3f',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='elements', full_name='Vector3f.elements', index=0,
      number=1, type=2, cpp_type=6, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=_b('\020\001'), file=DESCRIPTOR),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=45,
  serialized_end=77,
)


_VECTOR4F = _descriptor.Descriptor(
  name='Vector4f',
  full_name='Vector4f',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='elements', full_name='Vector4f.elements', index=0,
      number=1, type=2, cpp_type=6, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=_b('\020\001'), file=DESCRIPTOR),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=79,
  serialized_end=111,
)


_STATEFIELDREGISTRY = _descriptor.Descriptor(
  name='StateFieldRegistry',
  full_name='StateFieldRegistry',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='time_t_average_cycle_time_us', full_name='StateFieldRegistry.time_t_average_cycle_time_us', index=0,
      number=1, type=2, cpp_type=6, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='time_t_control_cycle_limit_us', full_name='StateFieldRegistry.time_t_control_cycle_limit_us', index=1,
      number=2, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='time_t_last_cycle_end_us', full_name='StateFieldRegistry.time_t_last_cycle_end_us', index=2,
      number=3, type=13, cpp_type=3, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='last_transition_ccno', full_name='StateFieldRegistry.last_transition_ccno', index=3,
      number=4, type=4, cpp_type=4, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='mcl_control_cycle_num', full_name='StateFieldRegistry.mcl_control_cycle_num', index=4,
      number=5, type=4, cpp_type=4, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='mc_state', full_name='StateFieldRegistry.mc_state', index=5,
      number=6, type=14, cpp_type=8, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='target_mc_state', full_name='StateFieldRegistry.target_mc_state', index=6,
      number=7, type=14, cpp_type=8, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='gnc_state', full_name='StateFieldRegistry.gnc_state', index=7,
      number=8, type=14, cpp_type=8, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='target_gnc_state', full_name='StateFieldRegistry.target_gnc_state', index=8,
      number=9, type=14, cpp_type=8, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='imu_linear_acc_vec_f', full_name='StateFieldRegistry.imu_linear_acc_vec_f', index=9,
      number=10, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='imu_acc_vec_f', full_name='StateFieldRegistry.imu_acc_vec_f', index=10,
      number=11, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='imu_gyr_vec', full_name='StateFieldRegistry.imu_gyr_vec', index=11,
      number=12, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='imu_euler_vec', full_name='StateFieldRegistry.imu_euler_vec', index=12,
      number=13, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='imu_quat', full_name='StateFieldRegistry.imu_quat', index=13,
      number=14, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=114,
  serialized_end=638,
)

_STATEFIELDREGISTRY.fields_by_name['mc_state'].enum_type = _MAINCONTROLSTATE
_STATEFIELDREGISTRY.fields_by_name['target_mc_state'].enum_type = _MAINCONTROLSTATE
_STATEFIELDREGISTRY.fields_by_name['gnc_state'].enum_type = _GNCCONTROLSTATE
_STATEFIELDREGISTRY.fields_by_name['target_gnc_state'].enum_type = _GNCCONTROLSTATE
_STATEFIELDREGISTRY.fields_by_name['imu_linear_acc_vec_f'].message_type = _VECTOR3F
_STATEFIELDREGISTRY.fields_by_name['imu_acc_vec_f'].message_type = _VECTOR3F
_STATEFIELDREGISTRY.fields_by_name['imu_gyr_vec'].message_type = _VECTOR3F
_STATEFIELDREGISTRY.fields_by_name['imu_euler_vec'].message_type = _VECTOR4F
_STATEFIELDREGISTRY.fields_by_name['imu_quat'].message_type = _VECTOR4F
DESCRIPTOR.message_types_by_name['Vector3f'] = _VECTOR3F
DESCRIPTOR.message_types_by_name['Vector4f'] = _VECTOR4F
DESCRIPTOR.message_types_by_name['StateFieldRegistry'] = _STATEFIELDREGISTRY
DESCRIPTOR.enum_types_by_name['MainControlState'] = _MAINCONTROLSTATE
DESCRIPTOR.enum_types_by_name['GncControlState'] = _GNCCONTROLSTATE
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

Vector3f = _reflection.GeneratedProtocolMessageType('Vector3f', (_message.Message,), dict(
  DESCRIPTOR = _VECTOR3F,
  __module__ = 'include.protos.state_field_registry_pb2'
  # @@protoc_insertion_point(class_scope:Vector3f)
  ))
_sym_db.RegisterMessage(Vector3f)

Vector4f = _reflection.GeneratedProtocolMessageType('Vector4f', (_message.Message,), dict(
  DESCRIPTOR = _VECTOR4F,
  __module__ = 'include.protos.state_field_registry_pb2'
  # @@protoc_insertion_point(class_scope:Vector4f)
  ))
_sym_db.RegisterMessage(Vector4f)

StateFieldRegistry = _reflection.GeneratedProtocolMessageType('StateFieldRegistry', (_message.Message,), dict(
  DESCRIPTOR = _STATEFIELDREGISTRY,
  __module__ = 'include.protos.state_field_registry_pb2'
  # @@protoc_insertion_point(class_scope:StateFieldRegistry)
  ))
_sym_db.RegisterMessage(StateFieldRegistry)


_VECTOR3F.fields_by_name['elements']._options = None
_VECTOR4F.fields_by_name['elements']._options = None
# @@protoc_insertion_point(module_scope)
