# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: lib/nanopb/state_field_registry.proto

import sys
_b=sys.version_info[0]<3 and (lambda x:x) or (lambda x:x.encode('latin1'))
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()




DESCRIPTOR = _descriptor.FileDescriptor(
  name='lib/nanopb/state_field_registry.proto',
  package='',
  syntax='proto3',
  serialized_options=None,
  serialized_pb=_b('\n%lib/nanopb/state_field_registry.proto\"\"\n\nSFVector3f\x12\x14\n\x08\x65lements\x18\x01 \x03(\x02\x42\x02\x10\x01\"\"\n\nSFVector4f\x12\x14\n\x08\x65lements\x18\x01 \x03(\x02\x42\x02\x10\x01\"\xea\x08\n\x12StateFieldRegistry\x12%\n\x1dtime_t_control_cycle_limit_us\x18\x02 \x01(\x05\x12 \n\x18time_t_last_cycle_end_us\x18\x03 \x01(\r\x12\x1c\n\x14last_transition_ccno\x18\x04 \x01(\x04\x12)\n\x14imu_linear_acc_vec_f\x18\n \x01(\x0b\x32\x0b.SFVector3f\x12\"\n\rimu_acc_vec_f\x18\x0b \x01(\x0b\x32\x0b.SFVector3f\x12 \n\x0bimu_gyr_vec\x18\x0c \x01(\x0b\x32\x0b.SFVector3f\x12\"\n\rimu_euler_vec\x18\r \x01(\x0b\x32\x0b.SFVector4f\x12\x1d\n\x08imu_quat\x18\x0e \x01(\x0b\x32\x0b.SFVector4f\x12\x12\n\nfin_py_cmd\x18\x10 \x01(\x02\x12\x12\n\nfin_ny_cmd\x18\x11 \x01(\x02\x12\x12\n\nfin_px_cmd\x18\x12 \x01(\x02\x12\x12\n\nfin_nx_cmd\x18\x13 \x01(\x02\x12\x17\n\x0flower_motor_cmd\x18\x14 \x01(\x02\x12$\n\x1ctime_t_average_cycle_time_us\x18\x15 \x01(\x02\x12\x1d\n\x15mcl_control_cycle_num\x18\x16 \x01(\x04\x12\x10\n\x08mc_state\x18\x17 \x01(\x05\x12\x17\n\x0ftarget_mc_state\x18\x18 \x01(\x05\x12\x11\n\tgnc_state\x18\x19 \x01(\x05\x12\x18\n\x10target_gnc_state\x18\x1a \x01(\x05\x12\'\n\x12imu_linear_acc_vec\x18\x1b \x01(\x0b\x32\x0b.SFVector3f\x12.\n\x19gnc_global_target_error_f\x18\x1c \x01(\x0b\x32\x0b.SFVector3f\x12,\n\x17gnc_global_target_pos_f\x18\x1d \x01(\x0b\x32\x0b.SFVector3f\x12,\n\x17gnc_global_linear_pos_f\x18\x1e \x01(\x0b\x32\x0b.SFVector3f\x12,\n\x17gnc_global_linear_vel_f\x18\x1f \x01(\x0b\x32\x0b.SFVector3f\x12,\n\x17gnc_global_linear_acc_f\x18  \x01(\x0b\x32\x0b.SFVector3f\x12$\n\x0fgnc_global_quat\x18! \x01(\x0b\x32\x0b.SFVector3f\x12%\n\x10gnc_euler_angles\x18\" \x01(\x0b\x32\x0b.SFVector3f\x12,\n\x17sim_global_linear_pos_f\x18# \x01(\x0b\x32\x0b.SFVector3f\x12,\n\x17sim_global_linear_vel_f\x18$ \x01(\x0b\x32\x0b.SFVector3f\x12,\n\x17sim_global_linear_acc_f\x18% \x01(\x0b\x32\x0b.SFVector3f\x12$\n\x0fsim_global_quat\x18& \x01(\x0b\x32\x0b.SFVector3f\x12%\n\x10sim_euler_angles\x18\' \x01(\x0b\x32\x0b.SFVector3fb\x06proto3')
)




_SFVECTOR3F = _descriptor.Descriptor(
  name='SFVector3f',
  full_name='SFVector3f',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='elements', full_name='SFVector3f.elements', index=0,
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
  serialized_start=41,
  serialized_end=75,
)


_SFVECTOR4F = _descriptor.Descriptor(
  name='SFVector4f',
  full_name='SFVector4f',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='elements', full_name='SFVector4f.elements', index=0,
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
  serialized_start=77,
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
      name='time_t_control_cycle_limit_us', full_name='StateFieldRegistry.time_t_control_cycle_limit_us', index=0,
      number=2, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='time_t_last_cycle_end_us', full_name='StateFieldRegistry.time_t_last_cycle_end_us', index=1,
      number=3, type=13, cpp_type=3, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='last_transition_ccno', full_name='StateFieldRegistry.last_transition_ccno', index=2,
      number=4, type=4, cpp_type=4, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='imu_linear_acc_vec_f', full_name='StateFieldRegistry.imu_linear_acc_vec_f', index=3,
      number=10, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='imu_acc_vec_f', full_name='StateFieldRegistry.imu_acc_vec_f', index=4,
      number=11, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='imu_gyr_vec', full_name='StateFieldRegistry.imu_gyr_vec', index=5,
      number=12, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='imu_euler_vec', full_name='StateFieldRegistry.imu_euler_vec', index=6,
      number=13, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='imu_quat', full_name='StateFieldRegistry.imu_quat', index=7,
      number=14, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='fin_py_cmd', full_name='StateFieldRegistry.fin_py_cmd', index=8,
      number=16, type=2, cpp_type=6, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='fin_ny_cmd', full_name='StateFieldRegistry.fin_ny_cmd', index=9,
      number=17, type=2, cpp_type=6, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='fin_px_cmd', full_name='StateFieldRegistry.fin_px_cmd', index=10,
      number=18, type=2, cpp_type=6, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='fin_nx_cmd', full_name='StateFieldRegistry.fin_nx_cmd', index=11,
      number=19, type=2, cpp_type=6, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='lower_motor_cmd', full_name='StateFieldRegistry.lower_motor_cmd', index=12,
      number=20, type=2, cpp_type=6, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='time_t_average_cycle_time_us', full_name='StateFieldRegistry.time_t_average_cycle_time_us', index=13,
      number=21, type=2, cpp_type=6, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='mcl_control_cycle_num', full_name='StateFieldRegistry.mcl_control_cycle_num', index=14,
      number=22, type=4, cpp_type=4, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='mc_state', full_name='StateFieldRegistry.mc_state', index=15,
      number=23, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='target_mc_state', full_name='StateFieldRegistry.target_mc_state', index=16,
      number=24, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='gnc_state', full_name='StateFieldRegistry.gnc_state', index=17,
      number=25, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='target_gnc_state', full_name='StateFieldRegistry.target_gnc_state', index=18,
      number=26, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='imu_linear_acc_vec', full_name='StateFieldRegistry.imu_linear_acc_vec', index=19,
      number=27, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='gnc_global_target_error_f', full_name='StateFieldRegistry.gnc_global_target_error_f', index=20,
      number=28, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='gnc_global_target_pos_f', full_name='StateFieldRegistry.gnc_global_target_pos_f', index=21,
      number=29, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='gnc_global_linear_pos_f', full_name='StateFieldRegistry.gnc_global_linear_pos_f', index=22,
      number=30, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='gnc_global_linear_vel_f', full_name='StateFieldRegistry.gnc_global_linear_vel_f', index=23,
      number=31, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='gnc_global_linear_acc_f', full_name='StateFieldRegistry.gnc_global_linear_acc_f', index=24,
      number=32, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='gnc_global_quat', full_name='StateFieldRegistry.gnc_global_quat', index=25,
      number=33, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='gnc_euler_angles', full_name='StateFieldRegistry.gnc_euler_angles', index=26,
      number=34, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='sim_global_linear_pos_f', full_name='StateFieldRegistry.sim_global_linear_pos_f', index=27,
      number=35, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='sim_global_linear_vel_f', full_name='StateFieldRegistry.sim_global_linear_vel_f', index=28,
      number=36, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='sim_global_linear_acc_f', full_name='StateFieldRegistry.sim_global_linear_acc_f', index=29,
      number=37, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='sim_global_quat', full_name='StateFieldRegistry.sim_global_quat', index=30,
      number=38, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='sim_euler_angles', full_name='StateFieldRegistry.sim_euler_angles', index=31,
      number=39, type=11, cpp_type=10, label=1,
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
  serialized_end=1244,
)

_STATEFIELDREGISTRY.fields_by_name['imu_linear_acc_vec_f'].message_type = _SFVECTOR3F
_STATEFIELDREGISTRY.fields_by_name['imu_acc_vec_f'].message_type = _SFVECTOR3F
_STATEFIELDREGISTRY.fields_by_name['imu_gyr_vec'].message_type = _SFVECTOR3F
_STATEFIELDREGISTRY.fields_by_name['imu_euler_vec'].message_type = _SFVECTOR4F
_STATEFIELDREGISTRY.fields_by_name['imu_quat'].message_type = _SFVECTOR4F
_STATEFIELDREGISTRY.fields_by_name['imu_linear_acc_vec'].message_type = _SFVECTOR3F
_STATEFIELDREGISTRY.fields_by_name['gnc_global_target_error_f'].message_type = _SFVECTOR3F
_STATEFIELDREGISTRY.fields_by_name['gnc_global_target_pos_f'].message_type = _SFVECTOR3F
_STATEFIELDREGISTRY.fields_by_name['gnc_global_linear_pos_f'].message_type = _SFVECTOR3F
_STATEFIELDREGISTRY.fields_by_name['gnc_global_linear_vel_f'].message_type = _SFVECTOR3F
_STATEFIELDREGISTRY.fields_by_name['gnc_global_linear_acc_f'].message_type = _SFVECTOR3F
_STATEFIELDREGISTRY.fields_by_name['gnc_global_quat'].message_type = _SFVECTOR3F
_STATEFIELDREGISTRY.fields_by_name['gnc_euler_angles'].message_type = _SFVECTOR3F
_STATEFIELDREGISTRY.fields_by_name['sim_global_linear_pos_f'].message_type = _SFVECTOR3F
_STATEFIELDREGISTRY.fields_by_name['sim_global_linear_vel_f'].message_type = _SFVECTOR3F
_STATEFIELDREGISTRY.fields_by_name['sim_global_linear_acc_f'].message_type = _SFVECTOR3F
_STATEFIELDREGISTRY.fields_by_name['sim_global_quat'].message_type = _SFVECTOR3F
_STATEFIELDREGISTRY.fields_by_name['sim_euler_angles'].message_type = _SFVECTOR3F
DESCRIPTOR.message_types_by_name['SFVector3f'] = _SFVECTOR3F
DESCRIPTOR.message_types_by_name['SFVector4f'] = _SFVECTOR4F
DESCRIPTOR.message_types_by_name['StateFieldRegistry'] = _STATEFIELDREGISTRY
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

SFVector3f = _reflection.GeneratedProtocolMessageType('SFVector3f', (_message.Message,), dict(
  DESCRIPTOR = _SFVECTOR3F,
  __module__ = 'lib.nanopb.state_field_registry_pb2'
  # @@protoc_insertion_point(class_scope:SFVector3f)
  ))
_sym_db.RegisterMessage(SFVector3f)

SFVector4f = _reflection.GeneratedProtocolMessageType('SFVector4f', (_message.Message,), dict(
  DESCRIPTOR = _SFVECTOR4F,
  __module__ = 'lib.nanopb.state_field_registry_pb2'
  # @@protoc_insertion_point(class_scope:SFVector4f)
  ))
_sym_db.RegisterMessage(SFVector4f)

StateFieldRegistry = _reflection.GeneratedProtocolMessageType('StateFieldRegistry', (_message.Message,), dict(
  DESCRIPTOR = _STATEFIELDREGISTRY,
  __module__ = 'lib.nanopb.state_field_registry_pb2'
  # @@protoc_insertion_point(class_scope:StateFieldRegistry)
  ))
_sym_db.RegisterMessage(StateFieldRegistry)


_SFVECTOR3F.fields_by_name['elements']._options = None
_SFVECTOR4F.fields_by_name['elements']._options = None
# @@protoc_insertion_point(module_scope)
