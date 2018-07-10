# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: geometry.proto

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


DESCRIPTOR = _descriptor.FileDescriptor(
  name='geometry.proto',
  package='hdmap_proto',
  serialized_pb=_b('\n\x0egeometry.proto\x12\x0bhdmap_proto\x1a\x08id.proto\"(\n\x05Point\x12\t\n\x01x\x18\x01 \x02(\x01\x12\t\n\x01y\x18\x02 \x02(\x01\x12\t\n\x01z\x18\x03 \x02(\x01\")\n\x06Normal\x12\t\n\x01x\x18\x01 \x02(\x02\x12\t\n\x01y\x18\x02 \x02(\x02\x12\t\n\x01z\x18\x03 \x02(\x02\"Q\n\x0bLineSegment\x12!\n\x05start\x18\x01 \x02(\x0b\x32\x12.hdmap_proto.Point\x12\x1f\n\x03\x65nd\x18\x02 \x02(\x0b\x32\x12.hdmap_proto.Point\"B\n\x08\x43ylinder\x12&\n\x04line\x18\x01 \x02(\x0b\x32\x18.hdmap_proto.LineSegment\x12\x0e\n\x06radius\x18\x02 \x02(\x02\"a\n\x06\x43ircle\x12\"\n\x06\x63\x65nter\x18\x01 \x02(\x0b\x32\x12.hdmap_proto.Point\x12#\n\x06normal\x18\x02 \x02(\x0b\x32\x13.hdmap_proto.Normal\x12\x0e\n\x06radius\x18\x03 \x02(\x02\".\n\x08PolyLine\x12\"\n\x06points\x18\x01 \x03(\x0b\x32\x12.hdmap_proto.Point\"*\n\x04Rect\x12\"\n\x06points\x18\x01 \x03(\x0b\x32\x12.hdmap_proto.Point\"*\n\x04\x43ube\x12\"\n\x06points\x18\x01 \x03(\x0b\x32\x12.hdmap_proto.Point\"-\n\x07Polygon\x12\"\n\x06points\x18\x01 \x03(\x0b\x32\x12.hdmap_proto.Point\"\x7f\n\x0c\x43urveControl\x12!\n\x05point\x18\x01 \x02(\x0b\x32\x12.hdmap_proto.Point\x12%\n\tpre_point\x18\x02 \x02(\x0b\x32\x12.hdmap_proto.Point\x12%\n\tsuc_point\x18\x03 \x02(\x0b\x32\x12.hdmap_proto.Point\"4\n\x05\x43urve\x12+\n\x08\x63ontrols\x18\x01 \x03(\x0b\x32\x19.hdmap_proto.CurveControl\"t\n\x0bParkingSlot\x12\x1b\n\x02id\x18\x01 \x02(\x0b\x32\x0f.hdmap_proto.Id\x12%\n\x07polygon\x18\x02 \x02(\x0b\x32\x14.hdmap_proto.Polygon\x12!\n\x08link_ids\x18\x03 \x03(\x0b\x32\x0f.hdmap_proto.Id')
  ,
  dependencies=[id_pb2.DESCRIPTOR,])
_sym_db.RegisterFileDescriptor(DESCRIPTOR)




_POINT = _descriptor.Descriptor(
  name='Point',
  full_name='hdmap_proto.Point',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='x', full_name='hdmap_proto.Point.x', index=0,
      number=1, type=1, cpp_type=5, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='y', full_name='hdmap_proto.Point.y', index=1,
      number=2, type=1, cpp_type=5, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='z', full_name='hdmap_proto.Point.z', index=2,
      number=3, type=1, cpp_type=5, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=41,
  serialized_end=81,
)


_NORMAL = _descriptor.Descriptor(
  name='Normal',
  full_name='hdmap_proto.Normal',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='x', full_name='hdmap_proto.Normal.x', index=0,
      number=1, type=2, cpp_type=6, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='y', full_name='hdmap_proto.Normal.y', index=1,
      number=2, type=2, cpp_type=6, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='z', full_name='hdmap_proto.Normal.z', index=2,
      number=3, type=2, cpp_type=6, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=83,
  serialized_end=124,
)


_LINESEGMENT = _descriptor.Descriptor(
  name='LineSegment',
  full_name='hdmap_proto.LineSegment',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='start', full_name='hdmap_proto.LineSegment.start', index=0,
      number=1, type=11, cpp_type=10, label=2,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='end', full_name='hdmap_proto.LineSegment.end', index=1,
      number=2, type=11, cpp_type=10, label=2,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=126,
  serialized_end=207,
)


_CYLINDER = _descriptor.Descriptor(
  name='Cylinder',
  full_name='hdmap_proto.Cylinder',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='line', full_name='hdmap_proto.Cylinder.line', index=0,
      number=1, type=11, cpp_type=10, label=2,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='radius', full_name='hdmap_proto.Cylinder.radius', index=1,
      number=2, type=2, cpp_type=6, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=209,
  serialized_end=275,
)


_CIRCLE = _descriptor.Descriptor(
  name='Circle',
  full_name='hdmap_proto.Circle',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='center', full_name='hdmap_proto.Circle.center', index=0,
      number=1, type=11, cpp_type=10, label=2,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='normal', full_name='hdmap_proto.Circle.normal', index=1,
      number=2, type=11, cpp_type=10, label=2,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='radius', full_name='hdmap_proto.Circle.radius', index=2,
      number=3, type=2, cpp_type=6, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=277,
  serialized_end=374,
)


_POLYLINE = _descriptor.Descriptor(
  name='PolyLine',
  full_name='hdmap_proto.PolyLine',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='points', full_name='hdmap_proto.PolyLine.points', index=0,
      number=1, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=376,
  serialized_end=422,
)


_RECT = _descriptor.Descriptor(
  name='Rect',
  full_name='hdmap_proto.Rect',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='points', full_name='hdmap_proto.Rect.points', index=0,
      number=1, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=424,
  serialized_end=466,
)


_CUBE = _descriptor.Descriptor(
  name='Cube',
  full_name='hdmap_proto.Cube',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='points', full_name='hdmap_proto.Cube.points', index=0,
      number=1, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=468,
  serialized_end=510,
)


_POLYGON = _descriptor.Descriptor(
  name='Polygon',
  full_name='hdmap_proto.Polygon',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='points', full_name='hdmap_proto.Polygon.points', index=0,
      number=1, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=512,
  serialized_end=557,
)


_CURVECONTROL = _descriptor.Descriptor(
  name='CurveControl',
  full_name='hdmap_proto.CurveControl',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='point', full_name='hdmap_proto.CurveControl.point', index=0,
      number=1, type=11, cpp_type=10, label=2,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='pre_point', full_name='hdmap_proto.CurveControl.pre_point', index=1,
      number=2, type=11, cpp_type=10, label=2,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='suc_point', full_name='hdmap_proto.CurveControl.suc_point', index=2,
      number=3, type=11, cpp_type=10, label=2,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=559,
  serialized_end=686,
)


_CURVE = _descriptor.Descriptor(
  name='Curve',
  full_name='hdmap_proto.Curve',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='controls', full_name='hdmap_proto.Curve.controls', index=0,
      number=1, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=688,
  serialized_end=740,
)


_PARKINGSLOT = _descriptor.Descriptor(
  name='ParkingSlot',
  full_name='hdmap_proto.ParkingSlot',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='id', full_name='hdmap_proto.ParkingSlot.id', index=0,
      number=1, type=11, cpp_type=10, label=2,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='polygon', full_name='hdmap_proto.ParkingSlot.polygon', index=1,
      number=2, type=11, cpp_type=10, label=2,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='link_ids', full_name='hdmap_proto.ParkingSlot.link_ids', index=2,
      number=3, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=742,
  serialized_end=858,
)

_LINESEGMENT.fields_by_name['start'].message_type = _POINT
_LINESEGMENT.fields_by_name['end'].message_type = _POINT
_CYLINDER.fields_by_name['line'].message_type = _LINESEGMENT
_CIRCLE.fields_by_name['center'].message_type = _POINT
_CIRCLE.fields_by_name['normal'].message_type = _NORMAL
_POLYLINE.fields_by_name['points'].message_type = _POINT
_RECT.fields_by_name['points'].message_type = _POINT
_CUBE.fields_by_name['points'].message_type = _POINT
_POLYGON.fields_by_name['points'].message_type = _POINT
_CURVECONTROL.fields_by_name['point'].message_type = _POINT
_CURVECONTROL.fields_by_name['pre_point'].message_type = _POINT
_CURVECONTROL.fields_by_name['suc_point'].message_type = _POINT
_CURVE.fields_by_name['controls'].message_type = _CURVECONTROL
_PARKINGSLOT.fields_by_name['id'].message_type = id_pb2._ID
_PARKINGSLOT.fields_by_name['polygon'].message_type = _POLYGON
_PARKINGSLOT.fields_by_name['link_ids'].message_type = id_pb2._ID
DESCRIPTOR.message_types_by_name['Point'] = _POINT
DESCRIPTOR.message_types_by_name['Normal'] = _NORMAL
DESCRIPTOR.message_types_by_name['LineSegment'] = _LINESEGMENT
DESCRIPTOR.message_types_by_name['Cylinder'] = _CYLINDER
DESCRIPTOR.message_types_by_name['Circle'] = _CIRCLE
DESCRIPTOR.message_types_by_name['PolyLine'] = _POLYLINE
DESCRIPTOR.message_types_by_name['Rect'] = _RECT
DESCRIPTOR.message_types_by_name['Cube'] = _CUBE
DESCRIPTOR.message_types_by_name['Polygon'] = _POLYGON
DESCRIPTOR.message_types_by_name['CurveControl'] = _CURVECONTROL
DESCRIPTOR.message_types_by_name['Curve'] = _CURVE
DESCRIPTOR.message_types_by_name['ParkingSlot'] = _PARKINGSLOT

Point = _reflection.GeneratedProtocolMessageType('Point', (_message.Message,), dict(
  DESCRIPTOR = _POINT,
  __module__ = 'geometry_pb2'
  # @@protoc_insertion_point(class_scope:hdmap_proto.Point)
  ))
_sym_db.RegisterMessage(Point)

Normal = _reflection.GeneratedProtocolMessageType('Normal', (_message.Message,), dict(
  DESCRIPTOR = _NORMAL,
  __module__ = 'geometry_pb2'
  # @@protoc_insertion_point(class_scope:hdmap_proto.Normal)
  ))
_sym_db.RegisterMessage(Normal)

LineSegment = _reflection.GeneratedProtocolMessageType('LineSegment', (_message.Message,), dict(
  DESCRIPTOR = _LINESEGMENT,
  __module__ = 'geometry_pb2'
  # @@protoc_insertion_point(class_scope:hdmap_proto.LineSegment)
  ))
_sym_db.RegisterMessage(LineSegment)

Cylinder = _reflection.GeneratedProtocolMessageType('Cylinder', (_message.Message,), dict(
  DESCRIPTOR = _CYLINDER,
  __module__ = 'geometry_pb2'
  # @@protoc_insertion_point(class_scope:hdmap_proto.Cylinder)
  ))
_sym_db.RegisterMessage(Cylinder)

Circle = _reflection.GeneratedProtocolMessageType('Circle', (_message.Message,), dict(
  DESCRIPTOR = _CIRCLE,
  __module__ = 'geometry_pb2'
  # @@protoc_insertion_point(class_scope:hdmap_proto.Circle)
  ))
_sym_db.RegisterMessage(Circle)

PolyLine = _reflection.GeneratedProtocolMessageType('PolyLine', (_message.Message,), dict(
  DESCRIPTOR = _POLYLINE,
  __module__ = 'geometry_pb2'
  # @@protoc_insertion_point(class_scope:hdmap_proto.PolyLine)
  ))
_sym_db.RegisterMessage(PolyLine)

Rect = _reflection.GeneratedProtocolMessageType('Rect', (_message.Message,), dict(
  DESCRIPTOR = _RECT,
  __module__ = 'geometry_pb2'
  # @@protoc_insertion_point(class_scope:hdmap_proto.Rect)
  ))
_sym_db.RegisterMessage(Rect)

Cube = _reflection.GeneratedProtocolMessageType('Cube', (_message.Message,), dict(
  DESCRIPTOR = _CUBE,
  __module__ = 'geometry_pb2'
  # @@protoc_insertion_point(class_scope:hdmap_proto.Cube)
  ))
_sym_db.RegisterMessage(Cube)

Polygon = _reflection.GeneratedProtocolMessageType('Polygon', (_message.Message,), dict(
  DESCRIPTOR = _POLYGON,
  __module__ = 'geometry_pb2'
  # @@protoc_insertion_point(class_scope:hdmap_proto.Polygon)
  ))
_sym_db.RegisterMessage(Polygon)

CurveControl = _reflection.GeneratedProtocolMessageType('CurveControl', (_message.Message,), dict(
  DESCRIPTOR = _CURVECONTROL,
  __module__ = 'geometry_pb2'
  # @@protoc_insertion_point(class_scope:hdmap_proto.CurveControl)
  ))
_sym_db.RegisterMessage(CurveControl)

Curve = _reflection.GeneratedProtocolMessageType('Curve', (_message.Message,), dict(
  DESCRIPTOR = _CURVE,
  __module__ = 'geometry_pb2'
  # @@protoc_insertion_point(class_scope:hdmap_proto.Curve)
  ))
_sym_db.RegisterMessage(Curve)

ParkingSlot = _reflection.GeneratedProtocolMessageType('ParkingSlot', (_message.Message,), dict(
  DESCRIPTOR = _PARKINGSLOT,
  __module__ = 'geometry_pb2'
  # @@protoc_insertion_point(class_scope:hdmap_proto.ParkingSlot)
  ))
_sym_db.RegisterMessage(ParkingSlot)


# @@protoc_insertion_point(module_scope)
