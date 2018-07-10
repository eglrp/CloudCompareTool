# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: traffic_sign.proto

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
  name='traffic_sign.proto',
  package='hdmap_proto',
  serialized_pb=_b('\n\x12traffic_sign.proto\x12\x0bhdmap_proto\x1a\x08id.proto\x1a\x0egeometry.proto\"\xcc\x14\n\x0bTrafficSign\x12\x1b\n\x02id\x18\x01 \x02(\x0b\x32\x0f.hdmap_proto.Id\x12 \n\x07tile_id\x18\x02 \x03(\x0b\x32\x0f.hdmap_proto.Id\x12\x36\n\x04type\x18\x04 \x01(\x0e\x32(.hdmap_proto.TrafficSign.TrafficSignType\x12%\n\x06\x63ircle\x18\x05 \x01(\x0b\x32\x13.hdmap_proto.CircleH\x00\x12!\n\x04rect\x18\x06 \x01(\x0b\x32\x11.hdmap_proto.RectH\x00\x12!\n\x04\x63ube\x18\x07 \x01(\x0b\x32\x11.hdmap_proto.CubeH\x00\x12\'\n\x07polygon\x18\x08 \x01(\x0b\x32\x14.hdmap_proto.PolygonH\x00\x12\r\n\x05value\x18\t \x01(\x02\x12!\n\x08link_ids\x18\n \x03(\x0b\x32\x0f.hdmap_proto.Id\"\xf1\x11\n\x0fTrafficSignType\x12\x0b\n\x07UNKNOWN\x10\x00\x12\x0e\n\nP_Stop_For\x10\x01\x12\x0e\n\nP_Slow_For\x10\x02\x12\x0e\n\nP_Give_Way\x10\x03\x12\x0b\n\x07P_Noway\x10\x04\x12\x0e\n\nP_No_Entry\x10\x05\x12\x10\n\x0cP_No_Parking\x10\x06\x12\x15\n\x11P_No_Long_Parking\x10\x07\x12\x13\n\x0fP_Parking_Check\x10\x08\x12\x0e\n\nP_No_Motor\x10\t\x12\x13\n\x0fP_No_Motorcycle\x10\n\x12\x0e\n\nP_No_Truck\x10\x0b\x12\x16\n\x12P_No_Moto_Tricycle\x10\x0c\x12\x0c\n\x08P_No_Bus\x10\r\x12\x0c\n\x08P_No_Car\x10\x0e\x12\x10\n\x0cP_No_Trailer\x10\x0f\x12\x10\n\x0cP_No_Tractor\x10\x10\x12\x17\n\x13P_No_Cargo_Tricycle\x10\x11\x12\x12\n\x0eP_No_Non_Motor\x10\x12\x12\x17\n\x13P_No_Animal_Vehicle\x10\x13\x12\x16\n\x12P_No_Human_Vehicle\x10\x14\x12\x1d\n\x19P_No_Human_Cargo_Triangle\x10\x15\x12!\n\x1dP_No_Human_Passenger_Triangle\x10\x16\x12\x0e\n\nP_No_Human\x10\x17\x12\x12\n\x0eP_No_Left_Turn\x10\x18\x12\x13\n\x0fP_No_Right_Turn\x10\x19\x12\x18\n\x14P_No_Left_Right_Turn\x10\x1a\x12\x0f\n\x0bP_No_Foward\x10\x1b\x12\x15\n\x11P_No_Forward_Left\x10\x1c\x12\x16\n\x12P_No_Forward_Right\x10\x1d\x12\x0f\n\x0bP_No_Return\x10\x1e\x12\x10\n\x0cP_No_Horning\x10\x1f\x12\x10\n\x0cP_Height_Lim\x10 \x12\x0f\n\x0bP_Width_Lim\x10!\x12\x10\n\x0cP_Weight_Lim\x10\"\x12\x16\n\x12P_Weight_Lim_wheel\x10#\x12\x0f\n\x0bP_Speed_Lim\x10$\x12\x13\n\x0fP_Speed_Lim_Rev\x10%\x12\x10\n\x0cP_No_Passing\x10&\x12\x12\n\x0eP_No_Dangerous\x10\'\x12\x0c\n\x08P_Custom\x10(\x12\x0b\n\x07P_Other\x10)\x12\x0c\n\x08W_T_Shap\x10*\x12\x11\n\rW_T_Shap_Left\x10+\x12\x12\n\x0eW_T_Shap_Right\x10,\x12\r\n\tW_T_Shaps\x10-\x12\x0b\n\x07W_Cross\x10.\x12\x0c\n\x08W_Circle\x10/\x12\x0c\n\x08W_Y_Left\x10\x30\x12\r\n\tW_Y_Right\x10\x31\x12\r\n\tW_YB_Left\x10\x32\x12\x0e\n\nW_YB_Right\x10\x33\x12\x0f\n\x0bW_Left_Turn\x10\x34\x12\x10\n\x0cW_Right_Turn\x10\x35\x12\r\n\tW_RL_Turn\x10\x36\x12\r\n\tW_LR_Turn\x10\x37\x12\x15\n\x11W_Continuous_Turn\x10\x38\x12\x08\n\x04W_Up\x10\x39\x12\n\n\x06W_Down\x10:\x12\x15\n\x11W_Continuous_Down\x10;\x12\x14\n\x10W_Accident_Prone\x10<\x12\x0c\n\x08W_Danger\x10=\x12\x11\n\rW_Left_Narrow\x10>\x12\x12\n\x0eW_Right_Narrow\x10?\x12\x0f\n\x0bW_LR_Narrow\x10@\x12\x13\n\x0fW_Narrow_Bridge\x10\x41\x12\n\n\x06W_Slip\x10\x42\x12\x10\n\x0cW_Pedestrain\x10\x43\x12\x0e\n\nW_Children\x10\x44\x12\x0b\n\x07W_Cycle\x10\x45\x12\x0e\n\nW_Disabled\x10\x46\x12\x0f\n\x0bW_Side_Wind\x10G\x12\x0e\n\nW_Domestic\x10H\x12\x0c\n\x08W_Animal\x10I\x12\x0c\n\x08W_Tunnel\x10J\x12\x16\n\x12W_Tunnel_Headlight\x10K\x12\x13\n\x0fW_Traffic_Light\x10L\x12\x12\n\x0eW_Left_Falling\x10M\x12\x13\n\x0fW_Right_Falling\x10N\x12\x10\n\x0cW_Mount_Left\x10O\x12\x11\n\rW_Mount_Right\x10P\x12\r\n\tW_Village\x10Q\x12\x0f\n\x0bW_Dam_Right\x10R\x12\x0e\n\nW_Dam_Left\x10S\x12\x0b\n\x07W_Ferry\x10T\x12\n\n\x06W_Ford\x10U\x12\n\n\x06W_Slow\x10V\x12\x11\n\rW_Hump_Bridge\x10W\x12\x0b\n\x07W_Bumpy\x10X\x12\n\n\x06W_Bump\x10Y\x12\x0f\n\x0bW_Low_Lying\x10Z\x12\r\n\tW_Working\x10[\x12\x15\n\x11W_Guarded_Railway\x10\\\x12\r\n\tW_Railway\x10]\x12\x13\n\x0fW_Detour_Around\x10^\x12\x11\n\rW_Detour_Left\x10_\x12\x12\n\x0eW_Detour_Right\x10`\x12\x10\n\x0cW_Merge_Left\x10\x61\x12\x11\n\rW_Merge_Right\x10\x62\x12\r\n\tW_Two_Way\x10\x63\x12\x0b\n\x07W_Tidal\x10\x64\x12\x13\n\x0fW_Keep_Distance\x10\x65\x12\x18\n\x14W_Cross_Intersection\x10\x66\x12\x14\n\x10W_T_Intersection\x10g\x12\x13\n\x0fW_Vehicle_Queue\x10h\x12\t\n\x05W_Ice\x10i\x12\n\n\x06W_Rain\x10j\x12\t\n\x05W_Fog\x10k\x12\x11\n\rW_Bad_Weather\x10l\x12\x0b\n\x07W_Other\x10m\x12\r\n\tI_Forward\x10n\x12\x0f\n\x0bI_Left_Turn\x10o\x12\x10\n\x0cI_Right_Turn\x10p\x12\x12\n\x0eI_Forward_Left\x10q\x12\x13\n\x0fI_Forward_Right\x10r\x12\x10\n\x0cI_Left_Right\x10s\x12\x0b\n\x07I_Right\x10t\x12\n\n\x06I_Left\x10u\x12\x19\n\x15I_Forward_Left_Stereo\x10v\x12\x1a\n\x16I_Forward_Right_Stereo\x10w\x12\x0c\n\x08I_Circle\x10x\x12\n\n\x06I_Walk\x10y\x12\n\n\x06I_Honk\x10z\x12\x13\n\x0fI_Min_Speed_Lim\x10{\x12\x0c\n\x08I_Motors\x10|\x12\x10\n\x0cI_Non_Motors\x10}\x12\x16\n\x12I_Pedestrian_Cross\x10~\x12\x0b\n\x07I_Other\x10\x7f\x42\n\n\x08geometry')
  ,
  dependencies=[id_pb2.DESCRIPTOR,geometry_pb2.DESCRIPTOR,])
_sym_db.RegisterFileDescriptor(DESCRIPTOR)



_TRAFFICSIGN_TRAFFICSIGNTYPE = _descriptor.EnumDescriptor(
  name='TrafficSignType',
  full_name='hdmap_proto.TrafficSign.TrafficSignType',
  filename=None,
  file=DESCRIPTOR,
  values=[
    _descriptor.EnumValueDescriptor(
      name='UNKNOWN', index=0, number=0,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='P_Stop_For', index=1, number=1,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='P_Slow_For', index=2, number=2,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='P_Give_Way', index=3, number=3,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='P_Noway', index=4, number=4,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='P_No_Entry', index=5, number=5,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='P_No_Parking', index=6, number=6,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='P_No_Long_Parking', index=7, number=7,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='P_Parking_Check', index=8, number=8,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='P_No_Motor', index=9, number=9,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='P_No_Motorcycle', index=10, number=10,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='P_No_Truck', index=11, number=11,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='P_No_Moto_Tricycle', index=12, number=12,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='P_No_Bus', index=13, number=13,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='P_No_Car', index=14, number=14,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='P_No_Trailer', index=15, number=15,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='P_No_Tractor', index=16, number=16,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='P_No_Cargo_Tricycle', index=17, number=17,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='P_No_Non_Motor', index=18, number=18,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='P_No_Animal_Vehicle', index=19, number=19,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='P_No_Human_Vehicle', index=20, number=20,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='P_No_Human_Cargo_Triangle', index=21, number=21,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='P_No_Human_Passenger_Triangle', index=22, number=22,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='P_No_Human', index=23, number=23,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='P_No_Left_Turn', index=24, number=24,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='P_No_Right_Turn', index=25, number=25,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='P_No_Left_Right_Turn', index=26, number=26,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='P_No_Foward', index=27, number=27,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='P_No_Forward_Left', index=28, number=28,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='P_No_Forward_Right', index=29, number=29,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='P_No_Return', index=30, number=30,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='P_No_Horning', index=31, number=31,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='P_Height_Lim', index=32, number=32,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='P_Width_Lim', index=33, number=33,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='P_Weight_Lim', index=34, number=34,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='P_Weight_Lim_wheel', index=35, number=35,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='P_Speed_Lim', index=36, number=36,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='P_Speed_Lim_Rev', index=37, number=37,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='P_No_Passing', index=38, number=38,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='P_No_Dangerous', index=39, number=39,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='P_Custom', index=40, number=40,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='P_Other', index=41, number=41,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_T_Shap', index=42, number=42,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_T_Shap_Left', index=43, number=43,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_T_Shap_Right', index=44, number=44,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_T_Shaps', index=45, number=45,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_Cross', index=46, number=46,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_Circle', index=47, number=47,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_Y_Left', index=48, number=48,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_Y_Right', index=49, number=49,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_YB_Left', index=50, number=50,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_YB_Right', index=51, number=51,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_Left_Turn', index=52, number=52,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_Right_Turn', index=53, number=53,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_RL_Turn', index=54, number=54,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_LR_Turn', index=55, number=55,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_Continuous_Turn', index=56, number=56,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_Up', index=57, number=57,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_Down', index=58, number=58,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_Continuous_Down', index=59, number=59,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_Accident_Prone', index=60, number=60,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_Danger', index=61, number=61,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_Left_Narrow', index=62, number=62,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_Right_Narrow', index=63, number=63,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_LR_Narrow', index=64, number=64,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_Narrow_Bridge', index=65, number=65,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_Slip', index=66, number=66,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_Pedestrain', index=67, number=67,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_Children', index=68, number=68,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_Cycle', index=69, number=69,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_Disabled', index=70, number=70,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_Side_Wind', index=71, number=71,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_Domestic', index=72, number=72,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_Animal', index=73, number=73,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_Tunnel', index=74, number=74,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_Tunnel_Headlight', index=75, number=75,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_Traffic_Light', index=76, number=76,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_Left_Falling', index=77, number=77,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_Right_Falling', index=78, number=78,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_Mount_Left', index=79, number=79,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_Mount_Right', index=80, number=80,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_Village', index=81, number=81,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_Dam_Right', index=82, number=82,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_Dam_Left', index=83, number=83,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_Ferry', index=84, number=84,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_Ford', index=85, number=85,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_Slow', index=86, number=86,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_Hump_Bridge', index=87, number=87,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_Bumpy', index=88, number=88,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_Bump', index=89, number=89,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_Low_Lying', index=90, number=90,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_Working', index=91, number=91,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_Guarded_Railway', index=92, number=92,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_Railway', index=93, number=93,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_Detour_Around', index=94, number=94,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_Detour_Left', index=95, number=95,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_Detour_Right', index=96, number=96,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_Merge_Left', index=97, number=97,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_Merge_Right', index=98, number=98,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_Two_Way', index=99, number=99,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_Tidal', index=100, number=100,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_Keep_Distance', index=101, number=101,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_Cross_Intersection', index=102, number=102,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_T_Intersection', index=103, number=103,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_Vehicle_Queue', index=104, number=104,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_Ice', index=105, number=105,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_Rain', index=106, number=106,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_Fog', index=107, number=107,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_Bad_Weather', index=108, number=108,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='W_Other', index=109, number=109,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='I_Forward', index=110, number=110,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='I_Left_Turn', index=111, number=111,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='I_Right_Turn', index=112, number=112,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='I_Forward_Left', index=113, number=113,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='I_Forward_Right', index=114, number=114,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='I_Left_Right', index=115, number=115,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='I_Right', index=116, number=116,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='I_Left', index=117, number=117,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='I_Forward_Left_Stereo', index=118, number=118,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='I_Forward_Right_Stereo', index=119, number=119,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='I_Circle', index=120, number=120,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='I_Walk', index=121, number=121,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='I_Honk', index=122, number=122,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='I_Min_Speed_Lim', index=123, number=123,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='I_Motors', index=124, number=124,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='I_Non_Motors', index=125, number=125,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='I_Pedestrian_Cross', index=126, number=126,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='I_Other', index=127, number=127,
      options=None,
      type=None),
  ],
  containing_type=None,
  options=None,
  serialized_start=397,
  serialized_end=2686,
)
_sym_db.RegisterEnumDescriptor(_TRAFFICSIGN_TRAFFICSIGNTYPE)


_TRAFFICSIGN = _descriptor.Descriptor(
  name='TrafficSign',
  full_name='hdmap_proto.TrafficSign',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='id', full_name='hdmap_proto.TrafficSign.id', index=0,
      number=1, type=11, cpp_type=10, label=2,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='tile_id', full_name='hdmap_proto.TrafficSign.tile_id', index=1,
      number=2, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='type', full_name='hdmap_proto.TrafficSign.type', index=2,
      number=4, type=14, cpp_type=8, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='circle', full_name='hdmap_proto.TrafficSign.circle', index=3,
      number=5, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='rect', full_name='hdmap_proto.TrafficSign.rect', index=4,
      number=6, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='cube', full_name='hdmap_proto.TrafficSign.cube', index=5,
      number=7, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='polygon', full_name='hdmap_proto.TrafficSign.polygon', index=6,
      number=8, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='value', full_name='hdmap_proto.TrafficSign.value', index=7,
      number=9, type=2, cpp_type=6, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='link_ids', full_name='hdmap_proto.TrafficSign.link_ids', index=8,
      number=10, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
    _TRAFFICSIGN_TRAFFICSIGNTYPE,
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  oneofs=[
    _descriptor.OneofDescriptor(
      name='geometry', full_name='hdmap_proto.TrafficSign.geometry',
      index=0, containing_type=None, fields=[]),
  ],
  serialized_start=62,
  serialized_end=2698,
)

_TRAFFICSIGN.fields_by_name['id'].message_type = id_pb2._ID
_TRAFFICSIGN.fields_by_name['tile_id'].message_type = id_pb2._ID
_TRAFFICSIGN.fields_by_name['type'].enum_type = _TRAFFICSIGN_TRAFFICSIGNTYPE
_TRAFFICSIGN.fields_by_name['circle'].message_type = geometry_pb2._CIRCLE
_TRAFFICSIGN.fields_by_name['rect'].message_type = geometry_pb2._RECT
_TRAFFICSIGN.fields_by_name['cube'].message_type = geometry_pb2._CUBE
_TRAFFICSIGN.fields_by_name['polygon'].message_type = geometry_pb2._POLYGON
_TRAFFICSIGN.fields_by_name['link_ids'].message_type = id_pb2._ID
_TRAFFICSIGN_TRAFFICSIGNTYPE.containing_type = _TRAFFICSIGN
_TRAFFICSIGN.oneofs_by_name['geometry'].fields.append(
  _TRAFFICSIGN.fields_by_name['circle'])
_TRAFFICSIGN.fields_by_name['circle'].containing_oneof = _TRAFFICSIGN.oneofs_by_name['geometry']
_TRAFFICSIGN.oneofs_by_name['geometry'].fields.append(
  _TRAFFICSIGN.fields_by_name['rect'])
_TRAFFICSIGN.fields_by_name['rect'].containing_oneof = _TRAFFICSIGN.oneofs_by_name['geometry']
_TRAFFICSIGN.oneofs_by_name['geometry'].fields.append(
  _TRAFFICSIGN.fields_by_name['cube'])
_TRAFFICSIGN.fields_by_name['cube'].containing_oneof = _TRAFFICSIGN.oneofs_by_name['geometry']
_TRAFFICSIGN.oneofs_by_name['geometry'].fields.append(
  _TRAFFICSIGN.fields_by_name['polygon'])
_TRAFFICSIGN.fields_by_name['polygon'].containing_oneof = _TRAFFICSIGN.oneofs_by_name['geometry']
DESCRIPTOR.message_types_by_name['TrafficSign'] = _TRAFFICSIGN

TrafficSign = _reflection.GeneratedProtocolMessageType('TrafficSign', (_message.Message,), dict(
  DESCRIPTOR = _TRAFFICSIGN,
  __module__ = 'traffic_sign_pb2'
  # @@protoc_insertion_point(class_scope:hdmap_proto.TrafficSign)
  ))
_sym_db.RegisterMessage(TrafficSign)


# @@protoc_insertion_point(module_scope)
