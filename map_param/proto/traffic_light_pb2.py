# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: traffic_light.proto

import sys
_b=sys.version_info[0]<3 and (lambda x:x) or (lambda x:x.encode('latin1'))
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
from google.protobuf import descriptor_pb2
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()


import id_pb2
import geometry_pb2


DESCRIPTOR = _descriptor.FileDescriptor(
  name='traffic_light.proto',
  package='hdmap_proto',
  serialized_pb=_b('\n\x13traffic_light.proto\x12\x0bhdmap_proto\x1a\x08id.proto\x1a\x0egeometry.proto\"\xef\x03\n\x0cTrafficLight\x12\x1b\n\x02id\x18\x01 \x02(\x0b\x32\x0f.hdmap_proto.Id\x12 \n\x07tile_id\x18\x02 \x03(\x0b\x32\x0f.hdmap_proto.Id\x12\x38\n\x04type\x18\x03 \x01(\x0e\x32*.hdmap_proto.TrafficLight.TrafficLightType\x12%\n\x06\x63ircle\x18\x04 \x01(\x0b\x32\x13.hdmap_proto.CircleH\x00\x12!\n\x04rect\x18\x05 \x01(\x0b\x32\x11.hdmap_proto.RectH\x00\x12:\n\x05state\x18\x06 \x01(\x0e\x32+.hdmap_proto.TrafficLight.TrafficLightState\x12!\n\x08link_ids\x18\x07 \x03(\x0b\x32\x0f.hdmap_proto.Id\"e\n\x10TrafficLightType\x12\x08\n\x04NONE\x10\x00\x12\n\n\x06\x43IRCLE\x10\x01\x12\t\n\x05\x43ROSS\x10\x02\x12\x0e\n\nPEDESTRIAN\x10\x03\x12\x0b\n\x07\x42ICYCLE\x10\x04\x12\t\n\x05\x41RROW\x10\x05\x12\x08\n\x04TIME\x10\x06\"J\n\x11TrafficLightState\x12\x0b\n\x07UNKNOWN\x10\x00\x12\x07\n\x03RED\x10\x01\x12\t\n\x05GREEN\x10\x02\x12\x08\n\x04\x42LUE\x10\x03\x12\n\n\x06YELLOW\x10\x04\x42\n\n\x08geometry')
  ,
  dependencies=[id_pb2.DESCRIPTOR,geometry_pb2.DESCRIPTOR,])
_sym_db.RegisterFileDescriptor(DESCRIPTOR)



_TRAFFICLIGHT_TRAFFICLIGHTTYPE = _descriptor.EnumDescriptor(
  name='TrafficLightType',
  full_name='hdmap_proto.TrafficLight.TrafficLightType',
  filename=None,
  file=DESCRIPTOR,
  values=[
    _descriptor.EnumValueDescriptor(
      name='NONE', index=0, number=0,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='CIRCLE', index=1, number=1,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='CROSS', index=2, number=2,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='PEDESTRIAN', index=3, number=3,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='BICYCLE', index=4, number=4,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='ARROW', index=5, number=5,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='TIME', index=6, number=6,
      options=None,
      type=None),
  ],
  containing_type=None,
  options=None,
  serialized_start=369,
  serialized_end=470,
)
_sym_db.RegisterEnumDescriptor(_TRAFFICLIGHT_TRAFFICLIGHTTYPE)

_TRAFFICLIGHT_TRAFFICLIGHTSTATE = _descriptor.EnumDescriptor(
  name='TrafficLightState',
  full_name='hdmap_proto.TrafficLight.TrafficLightState',
  filename=None,
  file=DESCRIPTOR,
  values=[
    _descriptor.EnumValueDescriptor(
      name='UNKNOWN', index=0, number=0,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='RED', index=1, number=1,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='GREEN', index=2, number=2,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='BLUE', index=3, number=3,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='YELLOW', index=4, number=4,
      options=None,
      type=None),
  ],
  containing_type=None,
  options=None,
  serialized_start=472,
  serialized_end=546,
)
_sym_db.RegisterEnumDescriptor(_TRAFFICLIGHT_TRAFFICLIGHTSTATE)


_TRAFFICLIGHT = _descriptor.Descriptor(
  name='TrafficLight',
  full_name='hdmap_proto.TrafficLight',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='id', full_name='hdmap_proto.TrafficLight.id', index=0,
      number=1, type=11, cpp_type=10, label=2,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='tile_id', full_name='hdmap_proto.TrafficLight.tile_id', index=1,
      number=2, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='type', full_name='hdmap_proto.TrafficLight.type', index=2,
      number=3, type=14, cpp_type=8, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='circle', full_name='hdmap_proto.TrafficLight.circle', index=3,
      number=4, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='rect', full_name='hdmap_proto.TrafficLight.rect', index=4,
      number=5, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='state', full_name='hdmap_proto.TrafficLight.state', index=5,
      number=6, type=14, cpp_type=8, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='link_ids', full_name='hdmap_proto.TrafficLight.link_ids', index=6,
      number=7, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
    _TRAFFICLIGHT_TRAFFICLIGHTTYPE,
    _TRAFFICLIGHT_TRAFFICLIGHTSTATE,
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  oneofs=[
    _descriptor.OneofDescriptor(
      name='geometry', full_name='hdmap_proto.TrafficLight.geometry',
      index=0, containing_type=None, fields=[]),
  ],
  serialized_start=63,
  serialized_end=558,
)

_TRAFFICLIGHT.fields_by_name['id'].message_type = id_pb2._ID
_TRAFFICLIGHT.fields_by_name['tile_id'].message_type = id_pb2._ID
_TRAFFICLIGHT.fields_by_name['type'].enum_type = _TRAFFICLIGHT_TRAFFICLIGHTTYPE
_TRAFFICLIGHT.fields_by_name['circle'].message_type = geometry_pb2._CIRCLE
_TRAFFICLIGHT.fields_by_name['rect'].message_type = geometry_pb2._RECT
_TRAFFICLIGHT.fields_by_name['state'].enum_type = _TRAFFICLIGHT_TRAFFICLIGHTSTATE
_TRAFFICLIGHT.fields_by_name['link_ids'].message_type = id_pb2._ID
_TRAFFICLIGHT_TRAFFICLIGHTTYPE.containing_type = _TRAFFICLIGHT
_TRAFFICLIGHT_TRAFFICLIGHTSTATE.containing_type = _TRAFFICLIGHT
_TRAFFICLIGHT.oneofs_by_name['geometry'].fields.append(
  _TRAFFICLIGHT.fields_by_name['circle'])
_TRAFFICLIGHT.fields_by_name['circle'].containing_oneof = _TRAFFICLIGHT.oneofs_by_name['geometry']
_TRAFFICLIGHT.oneofs_by_name['geometry'].fields.append(
  _TRAFFICLIGHT.fields_by_name['rect'])
_TRAFFICLIGHT.fields_by_name['rect'].containing_oneof = _TRAFFICLIGHT.oneofs_by_name['geometry']
DESCRIPTOR.message_types_by_name['TrafficLight'] = _TRAFFICLIGHT

TrafficLight = _reflection.GeneratedProtocolMessageType('TrafficLight', (_message.Message,), dict(
  DESCRIPTOR = _TRAFFICLIGHT,
  __module__ = 'traffic_light_pb2'
  # @@protoc_insertion_point(class_scope:hdmap_proto.TrafficLight)
  ))
_sym_db.RegisterMessage(TrafficLight)


# @@protoc_insertion_point(module_scope)
