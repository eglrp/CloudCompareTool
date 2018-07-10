// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: road.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "road.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace hdmap_proto {

namespace {

const ::google::protobuf::Descriptor* Road_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Road_reflection_ = NULL;
const ::google::protobuf::EnumDescriptor* Road_RoadType_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_road_2eproto() {
  protobuf_AddDesc_road_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "road.proto");
  GOOGLE_CHECK(file != NULL);
  Road_descriptor_ = file->message_type(0);
  static const int Road_offsets_[15] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Road, id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Road, tile_ids_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Road, type_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Road, reflines_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Road, lanes_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Road, stoplines_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Road, speedbumps_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Road, poles_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Road, boards_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Road, zones_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Road, lane_markings_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Road, traffic_lights_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Road, traffic_signs_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Road, predecessors_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Road, successors_),
  };
  Road_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Road_descriptor_,
      Road::default_instance_,
      Road_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Road, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Road, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Road));
  Road_RoadType_descriptor_ = Road_descriptor_->enum_type(0);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_road_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Road_descriptor_, &Road::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_road_2eproto() {
  delete Road::default_instance_;
  delete Road_reflection_;
}

void protobuf_AddDesc_road_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::hdmap_proto::protobuf_AddDesc_id_2eproto();
  ::hdmap_proto::protobuf_AddDesc_geometry_2eproto();
  ::hdmap_proto::protobuf_AddDesc_attribute_2eproto();
  ::hdmap_proto::protobuf_AddDesc_object_2eproto();
  ::hdmap_proto::protobuf_AddDesc_lane_5fmarking_2eproto();
  ::hdmap_proto::protobuf_AddDesc_traffic_5fsign_2eproto();
  ::hdmap_proto::protobuf_AddDesc_traffic_5flight_2eproto();
  ::hdmap_proto::protobuf_AddDesc_lane_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\nroad.proto\022\013hdmap_proto\032\010id.proto\032\016geo"
    "metry.proto\032\017attribute.proto\032\014object.pro"
    "to\032\022lane_marking.proto\032\022traffic_sign.pro"
    "to\032\023traffic_light.proto\032\nlane.proto\"\316\004\n\004"
    "Road\022\033\n\002id\030\001 \002(\0132\017.hdmap_proto.Id\022!\n\010til"
    "e_ids\030\002 \003(\0132\017.hdmap_proto.Id\022(\n\004type\030\004 \002"
    "(\0162\032.hdmap_proto.Road.RoadType\022#\n\010reflin"
    "es\030\005 \003(\0132\021.hdmap_proto.Lane\022 \n\005lanes\030\006 \003"
    "(\0132\021.hdmap_proto.Lane\022(\n\tstoplines\030\n \003(\013"
    "2\025.hdmap_proto.StopLine\022*\n\nspeedbumps\030\013 "
    "\003(\0132\026.hdmap_proto.SpeedBump\022 \n\005poles\030\014 \003"
    "(\0132\021.hdmap_proto.Pole\022\"\n\006boards\030\r \003(\0132\022."
    "hdmap_proto.Board\022 \n\005zones\030\016 \003(\0132\021.hdmap"
    "_proto.Zone\022/\n\rlane_markings\030\017 \003(\0132\030.hdm"
    "ap_proto.LaneMarking\0221\n\016traffic_lights\030\020"
    " \003(\0132\031.hdmap_proto.TrafficLight\0220\n\rtraff"
    "ic_signs\030\021 \003(\0132\031.hdmap_proto.TrafficLigh"
    "t\022\024\n\014predecessors\030\024 \003(\004\022\022\n\nsuccessors\030\025 "
    "\003(\004\"\027\n\010RoadType\022\013\n\007UNKNOWN\020\000", 748);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "road.proto", &protobuf_RegisterTypes);
  Road::default_instance_ = new Road();
  Road::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_road_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_road_2eproto {
  StaticDescriptorInitializer_road_2eproto() {
    protobuf_AddDesc_road_2eproto();
  }
} static_descriptor_initializer_road_2eproto_;

// ===================================================================

const ::google::protobuf::EnumDescriptor* Road_RoadType_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Road_RoadType_descriptor_;
}
bool Road_RoadType_IsValid(int value) {
  switch(value) {
    case 0:
      return true;
    default:
      return false;
  }
}

#ifndef _MSC_VER
const Road_RoadType Road::UNKNOWN;
const Road_RoadType Road::RoadType_MIN;
const Road_RoadType Road::RoadType_MAX;
const int Road::RoadType_ARRAYSIZE;
#endif  // _MSC_VER
#ifndef _MSC_VER
const int Road::kIdFieldNumber;
const int Road::kTileIdsFieldNumber;
const int Road::kTypeFieldNumber;
const int Road::kReflinesFieldNumber;
const int Road::kLanesFieldNumber;
const int Road::kStoplinesFieldNumber;
const int Road::kSpeedbumpsFieldNumber;
const int Road::kPolesFieldNumber;
const int Road::kBoardsFieldNumber;
const int Road::kZonesFieldNumber;
const int Road::kLaneMarkingsFieldNumber;
const int Road::kTrafficLightsFieldNumber;
const int Road::kTrafficSignsFieldNumber;
const int Road::kPredecessorsFieldNumber;
const int Road::kSuccessorsFieldNumber;
#endif  // !_MSC_VER

Road::Road()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:hdmap_proto.Road)
}

void Road::InitAsDefaultInstance() {
  id_ = const_cast< ::hdmap_proto::Id*>(&::hdmap_proto::Id::default_instance());
}

Road::Road(const Road& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:hdmap_proto.Road)
}

void Road::SharedCtor() {
  _cached_size_ = 0;
  id_ = NULL;
  type_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Road::~Road() {
  // @@protoc_insertion_point(destructor:hdmap_proto.Road)
  SharedDtor();
}

void Road::SharedDtor() {
  if (this != default_instance_) {
    delete id_;
  }
}

void Road::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Road::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Road_descriptor_;
}

const Road& Road::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_road_2eproto();
  return *default_instance_;
}

Road* Road::default_instance_ = NULL;

Road* Road::New() const {
  return new Road;
}

void Road::Clear() {
  if (_has_bits_[0 / 32] & 5) {
    if (has_id()) {
      if (id_ != NULL) id_->::hdmap_proto::Id::Clear();
    }
    type_ = 0;
  }
  tile_ids_.Clear();
  reflines_.Clear();
  lanes_.Clear();
  stoplines_.Clear();
  speedbumps_.Clear();
  poles_.Clear();
  boards_.Clear();
  zones_.Clear();
  lane_markings_.Clear();
  traffic_lights_.Clear();
  traffic_signs_.Clear();
  predecessors_.Clear();
  successors_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Road::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:hdmap_proto.Road)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(16383);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required .hdmap_proto.Id id = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_id()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_tile_ids;
        break;
      }

      // repeated .hdmap_proto.Id tile_ids = 2;
      case 2: {
        if (tag == 18) {
         parse_tile_ids:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_tile_ids()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_tile_ids;
        if (input->ExpectTag(32)) goto parse_type;
        break;
      }

      // required .hdmap_proto.Road.RoadType type = 4;
      case 4: {
        if (tag == 32) {
         parse_type:
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::hdmap_proto::Road_RoadType_IsValid(value)) {
            set_type(static_cast< ::hdmap_proto::Road_RoadType >(value));
          } else {
            mutable_unknown_fields()->AddVarint(4, value);
          }
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(42)) goto parse_reflines;
        break;
      }

      // repeated .hdmap_proto.Lane reflines = 5;
      case 5: {
        if (tag == 42) {
         parse_reflines:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_reflines()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(42)) goto parse_reflines;
        if (input->ExpectTag(50)) goto parse_lanes;
        break;
      }

      // repeated .hdmap_proto.Lane lanes = 6;
      case 6: {
        if (tag == 50) {
         parse_lanes:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_lanes()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(50)) goto parse_lanes;
        if (input->ExpectTag(82)) goto parse_stoplines;
        break;
      }

      // repeated .hdmap_proto.StopLine stoplines = 10;
      case 10: {
        if (tag == 82) {
         parse_stoplines:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_stoplines()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(82)) goto parse_stoplines;
        if (input->ExpectTag(90)) goto parse_speedbumps;
        break;
      }

      // repeated .hdmap_proto.SpeedBump speedbumps = 11;
      case 11: {
        if (tag == 90) {
         parse_speedbumps:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_speedbumps()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(90)) goto parse_speedbumps;
        if (input->ExpectTag(98)) goto parse_poles;
        break;
      }

      // repeated .hdmap_proto.Pole poles = 12;
      case 12: {
        if (tag == 98) {
         parse_poles:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_poles()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(98)) goto parse_poles;
        if (input->ExpectTag(106)) goto parse_boards;
        break;
      }

      // repeated .hdmap_proto.Board boards = 13;
      case 13: {
        if (tag == 106) {
         parse_boards:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_boards()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(106)) goto parse_boards;
        if (input->ExpectTag(114)) goto parse_zones;
        break;
      }

      // repeated .hdmap_proto.Zone zones = 14;
      case 14: {
        if (tag == 114) {
         parse_zones:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_zones()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(114)) goto parse_zones;
        if (input->ExpectTag(122)) goto parse_lane_markings;
        break;
      }

      // repeated .hdmap_proto.LaneMarking lane_markings = 15;
      case 15: {
        if (tag == 122) {
         parse_lane_markings:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_lane_markings()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(122)) goto parse_lane_markings;
        if (input->ExpectTag(130)) goto parse_traffic_lights;
        break;
      }

      // repeated .hdmap_proto.TrafficLight traffic_lights = 16;
      case 16: {
        if (tag == 130) {
         parse_traffic_lights:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_traffic_lights()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(130)) goto parse_traffic_lights;
        if (input->ExpectTag(138)) goto parse_traffic_signs;
        break;
      }

      // repeated .hdmap_proto.TrafficLight traffic_signs = 17;
      case 17: {
        if (tag == 138) {
         parse_traffic_signs:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_traffic_signs()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(138)) goto parse_traffic_signs;
        if (input->ExpectTag(160)) goto parse_predecessors;
        break;
      }

      // repeated uint64 predecessors = 20;
      case 20: {
        if (tag == 160) {
         parse_predecessors:
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 2, 160, input, this->mutable_predecessors())));
        } else if (tag == 162) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitiveNoInline<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, this->mutable_predecessors())));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(160)) goto parse_predecessors;
        if (input->ExpectTag(168)) goto parse_successors;
        break;
      }

      // repeated uint64 successors = 21;
      case 21: {
        if (tag == 168) {
         parse_successors:
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 2, 168, input, this->mutable_successors())));
        } else if (tag == 170) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitiveNoInline<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, this->mutable_successors())));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(168)) goto parse_successors;
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:hdmap_proto.Road)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:hdmap_proto.Road)
  return false;
#undef DO_
}

void Road::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:hdmap_proto.Road)
  // required .hdmap_proto.Id id = 1;
  if (has_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->id(), output);
  }

  // repeated .hdmap_proto.Id tile_ids = 2;
  for (int i = 0; i < this->tile_ids_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->tile_ids(i), output);
  }

  // required .hdmap_proto.Road.RoadType type = 4;
  if (has_type()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      4, this->type(), output);
  }

  // repeated .hdmap_proto.Lane reflines = 5;
  for (int i = 0; i < this->reflines_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      5, this->reflines(i), output);
  }

  // repeated .hdmap_proto.Lane lanes = 6;
  for (int i = 0; i < this->lanes_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      6, this->lanes(i), output);
  }

  // repeated .hdmap_proto.StopLine stoplines = 10;
  for (int i = 0; i < this->stoplines_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      10, this->stoplines(i), output);
  }

  // repeated .hdmap_proto.SpeedBump speedbumps = 11;
  for (int i = 0; i < this->speedbumps_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      11, this->speedbumps(i), output);
  }

  // repeated .hdmap_proto.Pole poles = 12;
  for (int i = 0; i < this->poles_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      12, this->poles(i), output);
  }

  // repeated .hdmap_proto.Board boards = 13;
  for (int i = 0; i < this->boards_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      13, this->boards(i), output);
  }

  // repeated .hdmap_proto.Zone zones = 14;
  for (int i = 0; i < this->zones_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      14, this->zones(i), output);
  }

  // repeated .hdmap_proto.LaneMarking lane_markings = 15;
  for (int i = 0; i < this->lane_markings_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      15, this->lane_markings(i), output);
  }

  // repeated .hdmap_proto.TrafficLight traffic_lights = 16;
  for (int i = 0; i < this->traffic_lights_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      16, this->traffic_lights(i), output);
  }

  // repeated .hdmap_proto.TrafficLight traffic_signs = 17;
  for (int i = 0; i < this->traffic_signs_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      17, this->traffic_signs(i), output);
  }

  // repeated uint64 predecessors = 20;
  for (int i = 0; i < this->predecessors_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(
      20, this->predecessors(i), output);
  }

  // repeated uint64 successors = 21;
  for (int i = 0; i < this->successors_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(
      21, this->successors(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:hdmap_proto.Road)
}

::google::protobuf::uint8* Road::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:hdmap_proto.Road)
  // required .hdmap_proto.Id id = 1;
  if (has_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->id(), target);
  }

  // repeated .hdmap_proto.Id tile_ids = 2;
  for (int i = 0; i < this->tile_ids_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->tile_ids(i), target);
  }

  // required .hdmap_proto.Road.RoadType type = 4;
  if (has_type()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      4, this->type(), target);
  }

  // repeated .hdmap_proto.Lane reflines = 5;
  for (int i = 0; i < this->reflines_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        5, this->reflines(i), target);
  }

  // repeated .hdmap_proto.Lane lanes = 6;
  for (int i = 0; i < this->lanes_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        6, this->lanes(i), target);
  }

  // repeated .hdmap_proto.StopLine stoplines = 10;
  for (int i = 0; i < this->stoplines_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        10, this->stoplines(i), target);
  }

  // repeated .hdmap_proto.SpeedBump speedbumps = 11;
  for (int i = 0; i < this->speedbumps_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        11, this->speedbumps(i), target);
  }

  // repeated .hdmap_proto.Pole poles = 12;
  for (int i = 0; i < this->poles_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        12, this->poles(i), target);
  }

  // repeated .hdmap_proto.Board boards = 13;
  for (int i = 0; i < this->boards_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        13, this->boards(i), target);
  }

  // repeated .hdmap_proto.Zone zones = 14;
  for (int i = 0; i < this->zones_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        14, this->zones(i), target);
  }

  // repeated .hdmap_proto.LaneMarking lane_markings = 15;
  for (int i = 0; i < this->lane_markings_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        15, this->lane_markings(i), target);
  }

  // repeated .hdmap_proto.TrafficLight traffic_lights = 16;
  for (int i = 0; i < this->traffic_lights_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        16, this->traffic_lights(i), target);
  }

  // repeated .hdmap_proto.TrafficLight traffic_signs = 17;
  for (int i = 0; i < this->traffic_signs_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        17, this->traffic_signs(i), target);
  }

  // repeated uint64 predecessors = 20;
  for (int i = 0; i < this->predecessors_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteUInt64ToArray(20, this->predecessors(i), target);
  }

  // repeated uint64 successors = 21;
  for (int i = 0; i < this->successors_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteUInt64ToArray(21, this->successors(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:hdmap_proto.Road)
  return target;
}

int Road::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required .hdmap_proto.Id id = 1;
    if (has_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->id());
    }

    // required .hdmap_proto.Road.RoadType type = 4;
    if (has_type()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->type());
    }

  }
  // repeated .hdmap_proto.Id tile_ids = 2;
  total_size += 1 * this->tile_ids_size();
  for (int i = 0; i < this->tile_ids_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->tile_ids(i));
  }

  // repeated .hdmap_proto.Lane reflines = 5;
  total_size += 1 * this->reflines_size();
  for (int i = 0; i < this->reflines_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->reflines(i));
  }

  // repeated .hdmap_proto.Lane lanes = 6;
  total_size += 1 * this->lanes_size();
  for (int i = 0; i < this->lanes_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->lanes(i));
  }

  // repeated .hdmap_proto.StopLine stoplines = 10;
  total_size += 1 * this->stoplines_size();
  for (int i = 0; i < this->stoplines_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->stoplines(i));
  }

  // repeated .hdmap_proto.SpeedBump speedbumps = 11;
  total_size += 1 * this->speedbumps_size();
  for (int i = 0; i < this->speedbumps_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->speedbumps(i));
  }

  // repeated .hdmap_proto.Pole poles = 12;
  total_size += 1 * this->poles_size();
  for (int i = 0; i < this->poles_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->poles(i));
  }

  // repeated .hdmap_proto.Board boards = 13;
  total_size += 1 * this->boards_size();
  for (int i = 0; i < this->boards_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->boards(i));
  }

  // repeated .hdmap_proto.Zone zones = 14;
  total_size += 1 * this->zones_size();
  for (int i = 0; i < this->zones_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->zones(i));
  }

  // repeated .hdmap_proto.LaneMarking lane_markings = 15;
  total_size += 1 * this->lane_markings_size();
  for (int i = 0; i < this->lane_markings_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->lane_markings(i));
  }

  // repeated .hdmap_proto.TrafficLight traffic_lights = 16;
  total_size += 2 * this->traffic_lights_size();
  for (int i = 0; i < this->traffic_lights_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->traffic_lights(i));
  }

  // repeated .hdmap_proto.TrafficLight traffic_signs = 17;
  total_size += 2 * this->traffic_signs_size();
  for (int i = 0; i < this->traffic_signs_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->traffic_signs(i));
  }

  // repeated uint64 predecessors = 20;
  {
    int data_size = 0;
    for (int i = 0; i < this->predecessors_size(); i++) {
      data_size += ::google::protobuf::internal::WireFormatLite::
        UInt64Size(this->predecessors(i));
    }
    total_size += 2 * this->predecessors_size() + data_size;
  }

  // repeated uint64 successors = 21;
  {
    int data_size = 0;
    for (int i = 0; i < this->successors_size(); i++) {
      data_size += ::google::protobuf::internal::WireFormatLite::
        UInt64Size(this->successors(i));
    }
    total_size += 2 * this->successors_size() + data_size;
  }

  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Road::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Road* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Road*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Road::MergeFrom(const Road& from) {
  GOOGLE_CHECK_NE(&from, this);
  tile_ids_.MergeFrom(from.tile_ids_);
  reflines_.MergeFrom(from.reflines_);
  lanes_.MergeFrom(from.lanes_);
  stoplines_.MergeFrom(from.stoplines_);
  speedbumps_.MergeFrom(from.speedbumps_);
  poles_.MergeFrom(from.poles_);
  boards_.MergeFrom(from.boards_);
  zones_.MergeFrom(from.zones_);
  lane_markings_.MergeFrom(from.lane_markings_);
  traffic_lights_.MergeFrom(from.traffic_lights_);
  traffic_signs_.MergeFrom(from.traffic_signs_);
  predecessors_.MergeFrom(from.predecessors_);
  successors_.MergeFrom(from.successors_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_id()) {
      mutable_id()->::hdmap_proto::Id::MergeFrom(from.id());
    }
    if (from.has_type()) {
      set_type(from.type());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Road::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Road::CopyFrom(const Road& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Road::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000005) != 0x00000005) return false;

  if (has_id()) {
    if (!this->id().IsInitialized()) return false;
  }
  if (!::google::protobuf::internal::AllAreInitialized(this->tile_ids())) return false;
  if (!::google::protobuf::internal::AllAreInitialized(this->reflines())) return false;
  if (!::google::protobuf::internal::AllAreInitialized(this->lanes())) return false;
  if (!::google::protobuf::internal::AllAreInitialized(this->stoplines())) return false;
  if (!::google::protobuf::internal::AllAreInitialized(this->speedbumps())) return false;
  if (!::google::protobuf::internal::AllAreInitialized(this->poles())) return false;
  if (!::google::protobuf::internal::AllAreInitialized(this->boards())) return false;
  if (!::google::protobuf::internal::AllAreInitialized(this->zones())) return false;
  if (!::google::protobuf::internal::AllAreInitialized(this->lane_markings())) return false;
  if (!::google::protobuf::internal::AllAreInitialized(this->traffic_lights())) return false;
  if (!::google::protobuf::internal::AllAreInitialized(this->traffic_signs())) return false;
  return true;
}

void Road::Swap(Road* other) {
  if (other != this) {
    std::swap(id_, other->id_);
    tile_ids_.Swap(&other->tile_ids_);
    std::swap(type_, other->type_);
    reflines_.Swap(&other->reflines_);
    lanes_.Swap(&other->lanes_);
    stoplines_.Swap(&other->stoplines_);
    speedbumps_.Swap(&other->speedbumps_);
    poles_.Swap(&other->poles_);
    boards_.Swap(&other->boards_);
    zones_.Swap(&other->zones_);
    lane_markings_.Swap(&other->lane_markings_);
    traffic_lights_.Swap(&other->traffic_lights_);
    traffic_signs_.Swap(&other->traffic_signs_);
    predecessors_.Swap(&other->predecessors_);
    successors_.Swap(&other->successors_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Road::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Road_descriptor_;
  metadata.reflection = Road_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace hdmap_proto

// @@protoc_insertion_point(global_scope)
