// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: lane.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "lane.pb.h"

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

const ::google::protobuf::Descriptor* Lane_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Lane_reflection_ = NULL;
const ::google::protobuf::EnumDescriptor* Lane_LaneFunction_descriptor_ = NULL;
const ::google::protobuf::EnumDescriptor* Lane_LaneDirection_descriptor_ = NULL;
const ::google::protobuf::EnumDescriptor* Lane_LaneStyle_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_lane_2eproto() {
  protobuf_AddDesc_lane_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "lane.proto");
  GOOGLE_CHECK(file != NULL);
  Lane_descriptor_ = file->message_type(0);
  static const int Lane_offsets_[11] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Lane, id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Lane, tile_ids_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Lane, function_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Lane, direction_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Lane, style_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Lane, lines_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Lane, lane_markings_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Lane, traffic_lights_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Lane, traffic_signs_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Lane, pred_indices_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Lane, succ_indices_),
  };
  Lane_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Lane_descriptor_,
      Lane::default_instance_,
      Lane_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Lane, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Lane, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Lane));
  Lane_LaneFunction_descriptor_ = Lane_descriptor_->enum_type(0);
  Lane_LaneDirection_descriptor_ = Lane_descriptor_->enum_type(1);
  Lane_LaneStyle_descriptor_ = Lane_descriptor_->enum_type(2);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_lane_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Lane_descriptor_, &Lane::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_lane_2eproto() {
  delete Lane::default_instance_;
  delete Lane_reflection_;
}

void protobuf_AddDesc_lane_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::hdmap_proto::protobuf_AddDesc_id_2eproto();
  ::hdmap_proto::protobuf_AddDesc_geometry_2eproto();
  ::hdmap_proto::protobuf_AddDesc_lane_5fmarking_2eproto();
  ::hdmap_proto::protobuf_AddDesc_traffic_5flight_2eproto();
  ::hdmap_proto::protobuf_AddDesc_traffic_5fsign_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\nlane.proto\022\013hdmap_proto\032\010id.proto\032\016geo"
    "metry.proto\032\022lane_marking.proto\032\023traffic"
    "_light.proto\032\022traffic_sign.proto\"\213\006\n\004Lan"
    "e\022\033\n\002id\030\001 \002(\0132\017.hdmap_proto.Id\022!\n\010tile_i"
    "ds\030\002 \003(\0132\017.hdmap_proto.Id\0220\n\010function\030\004 "
    "\001(\0162\036.hdmap_proto.Lane.LaneFunction\0222\n\td"
    "irection\030\005 \001(\0162\037.hdmap_proto.Lane.LaneDi"
    "rection\022*\n\005style\030\006 \001(\0162\033.hdmap_proto.Lan"
    "e.LaneStyle\022%\n\005lines\030\007 \003(\0132\026.hdmap_proto"
    ".CurveLine\022/\n\rlane_markings\030\010 \003(\0132\030.hdma"
    "p_proto.LaneMarking\0221\n\016traffic_lights\030\t "
    "\003(\0132\031.hdmap_proto.TrafficLight\022/\n\rtraffi"
    "c_signs\030\n \003(\0132\030.hdmap_proto.TrafficSign\022"
    "\024\n\014pred_indices\030\024 \003(\r\022\024\n\014succ_indices\030\025 "
    "\003(\r\"Q\n\014LaneFunction\022\010\n\004NONE\020\000\022\020\n\014CITY_DR"
    "IVING\020\001\022\n\n\006BIKING\020\002\022\014\n\010SIDEWALK\020\003\022\013\n\007PAR"
    "KING\020\004\";\n\rLaneDirection\022\013\n\007FORWARD\020\001\022\014\n\010"
    "BACKWARD\020\002\022\017\n\013BIDIRECTION\020\003\"\270\001\n\tLaneStyl"
    "e\022\013\n\007UNKNOWN\020\000\022\026\n\022DOTTED_YELLOW_LINE\020\001\022\027"
    "\n\023DOTTED_YELLOW_BLANK\020\002\022\025\n\021DOTTED_WHITE_"
    "LINE\020\003\022\026\n\022DOTTED_WHITE_BLANK\020\004\022\020\n\014SOLID_"
    "YELLOW\020\005\022\017\n\013SOLID_WHITE\020\006\022\021\n\rDOUBLE_YELL"
    "OW\020\007\022\010\n\004CURB\020\010", 894);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "lane.proto", &protobuf_RegisterTypes);
  Lane::default_instance_ = new Lane();
  Lane::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_lane_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_lane_2eproto {
  StaticDescriptorInitializer_lane_2eproto() {
    protobuf_AddDesc_lane_2eproto();
  }
} static_descriptor_initializer_lane_2eproto_;

// ===================================================================

const ::google::protobuf::EnumDescriptor* Lane_LaneFunction_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Lane_LaneFunction_descriptor_;
}
bool Lane_LaneFunction_IsValid(int value) {
  switch(value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
      return true;
    default:
      return false;
  }
}

#ifndef _MSC_VER
const Lane_LaneFunction Lane::NONE;
const Lane_LaneFunction Lane::CITY_DRIVING;
const Lane_LaneFunction Lane::BIKING;
const Lane_LaneFunction Lane::SIDEWALK;
const Lane_LaneFunction Lane::PARKING;
const Lane_LaneFunction Lane::LaneFunction_MIN;
const Lane_LaneFunction Lane::LaneFunction_MAX;
const int Lane::LaneFunction_ARRAYSIZE;
#endif  // _MSC_VER
const ::google::protobuf::EnumDescriptor* Lane_LaneDirection_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Lane_LaneDirection_descriptor_;
}
bool Lane_LaneDirection_IsValid(int value) {
  switch(value) {
    case 1:
    case 2:
    case 3:
      return true;
    default:
      return false;
  }
}

#ifndef _MSC_VER
const Lane_LaneDirection Lane::FORWARD;
const Lane_LaneDirection Lane::BACKWARD;
const Lane_LaneDirection Lane::BIDIRECTION;
const Lane_LaneDirection Lane::LaneDirection_MIN;
const Lane_LaneDirection Lane::LaneDirection_MAX;
const int Lane::LaneDirection_ARRAYSIZE;
#endif  // _MSC_VER
const ::google::protobuf::EnumDescriptor* Lane_LaneStyle_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Lane_LaneStyle_descriptor_;
}
bool Lane_LaneStyle_IsValid(int value) {
  switch(value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
      return true;
    default:
      return false;
  }
}

#ifndef _MSC_VER
const Lane_LaneStyle Lane::UNKNOWN;
const Lane_LaneStyle Lane::DOTTED_YELLOW_LINE;
const Lane_LaneStyle Lane::DOTTED_YELLOW_BLANK;
const Lane_LaneStyle Lane::DOTTED_WHITE_LINE;
const Lane_LaneStyle Lane::DOTTED_WHITE_BLANK;
const Lane_LaneStyle Lane::SOLID_YELLOW;
const Lane_LaneStyle Lane::SOLID_WHITE;
const Lane_LaneStyle Lane::DOUBLE_YELLOW;
const Lane_LaneStyle Lane::CURB;
const Lane_LaneStyle Lane::LaneStyle_MIN;
const Lane_LaneStyle Lane::LaneStyle_MAX;
const int Lane::LaneStyle_ARRAYSIZE;
#endif  // _MSC_VER
#ifndef _MSC_VER
const int Lane::kIdFieldNumber;
const int Lane::kTileIdsFieldNumber;
const int Lane::kFunctionFieldNumber;
const int Lane::kDirectionFieldNumber;
const int Lane::kStyleFieldNumber;
const int Lane::kLinesFieldNumber;
const int Lane::kLaneMarkingsFieldNumber;
const int Lane::kTrafficLightsFieldNumber;
const int Lane::kTrafficSignsFieldNumber;
const int Lane::kPredIndicesFieldNumber;
const int Lane::kSuccIndicesFieldNumber;
#endif  // !_MSC_VER

Lane::Lane()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:hdmap_proto.Lane)
}

void Lane::InitAsDefaultInstance() {
  id_ = const_cast< ::hdmap_proto::Id*>(&::hdmap_proto::Id::default_instance());
}

Lane::Lane(const Lane& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:hdmap_proto.Lane)
}

void Lane::SharedCtor() {
  _cached_size_ = 0;
  id_ = NULL;
  function_ = 0;
  direction_ = 1;
  style_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Lane::~Lane() {
  // @@protoc_insertion_point(destructor:hdmap_proto.Lane)
  SharedDtor();
}

void Lane::SharedDtor() {
  if (this != default_instance_) {
    delete id_;
  }
}

void Lane::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Lane::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Lane_descriptor_;
}

const Lane& Lane::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_lane_2eproto();
  return *default_instance_;
}

Lane* Lane::default_instance_ = NULL;

Lane* Lane::New() const {
  return new Lane;
}

void Lane::Clear() {
  if (_has_bits_[0 / 32] & 29) {
    if (has_id()) {
      if (id_ != NULL) id_->::hdmap_proto::Id::Clear();
    }
    function_ = 0;
    direction_ = 1;
    style_ = 0;
  }
  tile_ids_.Clear();
  lines_.Clear();
  lane_markings_.Clear();
  traffic_lights_.Clear();
  traffic_signs_.Clear();
  pred_indices_.Clear();
  succ_indices_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Lane::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:hdmap_proto.Lane)
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
        if (input->ExpectTag(32)) goto parse_function;
        break;
      }

      // optional .hdmap_proto.Lane.LaneFunction function = 4;
      case 4: {
        if (tag == 32) {
         parse_function:
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::hdmap_proto::Lane_LaneFunction_IsValid(value)) {
            set_function(static_cast< ::hdmap_proto::Lane_LaneFunction >(value));
          } else {
            mutable_unknown_fields()->AddVarint(4, value);
          }
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(40)) goto parse_direction;
        break;
      }

      // optional .hdmap_proto.Lane.LaneDirection direction = 5;
      case 5: {
        if (tag == 40) {
         parse_direction:
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::hdmap_proto::Lane_LaneDirection_IsValid(value)) {
            set_direction(static_cast< ::hdmap_proto::Lane_LaneDirection >(value));
          } else {
            mutable_unknown_fields()->AddVarint(5, value);
          }
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(48)) goto parse_style;
        break;
      }

      // optional .hdmap_proto.Lane.LaneStyle style = 6;
      case 6: {
        if (tag == 48) {
         parse_style:
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::hdmap_proto::Lane_LaneStyle_IsValid(value)) {
            set_style(static_cast< ::hdmap_proto::Lane_LaneStyle >(value));
          } else {
            mutable_unknown_fields()->AddVarint(6, value);
          }
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(58)) goto parse_lines;
        break;
      }

      // repeated .hdmap_proto.CurveLine lines = 7;
      case 7: {
        if (tag == 58) {
         parse_lines:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_lines()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(58)) goto parse_lines;
        if (input->ExpectTag(66)) goto parse_lane_markings;
        break;
      }

      // repeated .hdmap_proto.LaneMarking lane_markings = 8;
      case 8: {
        if (tag == 66) {
         parse_lane_markings:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_lane_markings()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(66)) goto parse_lane_markings;
        if (input->ExpectTag(74)) goto parse_traffic_lights;
        break;
      }

      // repeated .hdmap_proto.TrafficLight traffic_lights = 9;
      case 9: {
        if (tag == 74) {
         parse_traffic_lights:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_traffic_lights()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(74)) goto parse_traffic_lights;
        if (input->ExpectTag(82)) goto parse_traffic_signs;
        break;
      }

      // repeated .hdmap_proto.TrafficSign traffic_signs = 10;
      case 10: {
        if (tag == 82) {
         parse_traffic_signs:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_traffic_signs()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(82)) goto parse_traffic_signs;
        if (input->ExpectTag(160)) goto parse_pred_indices;
        break;
      }

      // repeated uint32 pred_indices = 20;
      case 20: {
        if (tag == 160) {
         parse_pred_indices:
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 2, 160, input, this->mutable_pred_indices())));
        } else if (tag == 162) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitiveNoInline<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, this->mutable_pred_indices())));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(160)) goto parse_pred_indices;
        if (input->ExpectTag(168)) goto parse_succ_indices;
        break;
      }

      // repeated uint32 succ_indices = 21;
      case 21: {
        if (tag == 168) {
         parse_succ_indices:
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 2, 168, input, this->mutable_succ_indices())));
        } else if (tag == 170) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitiveNoInline<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, this->mutable_succ_indices())));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(168)) goto parse_succ_indices;
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
  // @@protoc_insertion_point(parse_success:hdmap_proto.Lane)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:hdmap_proto.Lane)
  return false;
#undef DO_
}

void Lane::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:hdmap_proto.Lane)
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

  // optional .hdmap_proto.Lane.LaneFunction function = 4;
  if (has_function()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      4, this->function(), output);
  }

  // optional .hdmap_proto.Lane.LaneDirection direction = 5;
  if (has_direction()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      5, this->direction(), output);
  }

  // optional .hdmap_proto.Lane.LaneStyle style = 6;
  if (has_style()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      6, this->style(), output);
  }

  // repeated .hdmap_proto.CurveLine lines = 7;
  for (int i = 0; i < this->lines_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      7, this->lines(i), output);
  }

  // repeated .hdmap_proto.LaneMarking lane_markings = 8;
  for (int i = 0; i < this->lane_markings_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      8, this->lane_markings(i), output);
  }

  // repeated .hdmap_proto.TrafficLight traffic_lights = 9;
  for (int i = 0; i < this->traffic_lights_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      9, this->traffic_lights(i), output);
  }

  // repeated .hdmap_proto.TrafficSign traffic_signs = 10;
  for (int i = 0; i < this->traffic_signs_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      10, this->traffic_signs(i), output);
  }

  // repeated uint32 pred_indices = 20;
  for (int i = 0; i < this->pred_indices_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(
      20, this->pred_indices(i), output);
  }

  // repeated uint32 succ_indices = 21;
  for (int i = 0; i < this->succ_indices_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(
      21, this->succ_indices(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:hdmap_proto.Lane)
}

::google::protobuf::uint8* Lane::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:hdmap_proto.Lane)
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

  // optional .hdmap_proto.Lane.LaneFunction function = 4;
  if (has_function()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      4, this->function(), target);
  }

  // optional .hdmap_proto.Lane.LaneDirection direction = 5;
  if (has_direction()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      5, this->direction(), target);
  }

  // optional .hdmap_proto.Lane.LaneStyle style = 6;
  if (has_style()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      6, this->style(), target);
  }

  // repeated .hdmap_proto.CurveLine lines = 7;
  for (int i = 0; i < this->lines_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        7, this->lines(i), target);
  }

  // repeated .hdmap_proto.LaneMarking lane_markings = 8;
  for (int i = 0; i < this->lane_markings_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        8, this->lane_markings(i), target);
  }

  // repeated .hdmap_proto.TrafficLight traffic_lights = 9;
  for (int i = 0; i < this->traffic_lights_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        9, this->traffic_lights(i), target);
  }

  // repeated .hdmap_proto.TrafficSign traffic_signs = 10;
  for (int i = 0; i < this->traffic_signs_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        10, this->traffic_signs(i), target);
  }

  // repeated uint32 pred_indices = 20;
  for (int i = 0; i < this->pred_indices_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteUInt32ToArray(20, this->pred_indices(i), target);
  }

  // repeated uint32 succ_indices = 21;
  for (int i = 0; i < this->succ_indices_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteUInt32ToArray(21, this->succ_indices(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:hdmap_proto.Lane)
  return target;
}

int Lane::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required .hdmap_proto.Id id = 1;
    if (has_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->id());
    }

    // optional .hdmap_proto.Lane.LaneFunction function = 4;
    if (has_function()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->function());
    }

    // optional .hdmap_proto.Lane.LaneDirection direction = 5;
    if (has_direction()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->direction());
    }

    // optional .hdmap_proto.Lane.LaneStyle style = 6;
    if (has_style()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->style());
    }

  }
  // repeated .hdmap_proto.Id tile_ids = 2;
  total_size += 1 * this->tile_ids_size();
  for (int i = 0; i < this->tile_ids_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->tile_ids(i));
  }

  // repeated .hdmap_proto.CurveLine lines = 7;
  total_size += 1 * this->lines_size();
  for (int i = 0; i < this->lines_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->lines(i));
  }

  // repeated .hdmap_proto.LaneMarking lane_markings = 8;
  total_size += 1 * this->lane_markings_size();
  for (int i = 0; i < this->lane_markings_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->lane_markings(i));
  }

  // repeated .hdmap_proto.TrafficLight traffic_lights = 9;
  total_size += 1 * this->traffic_lights_size();
  for (int i = 0; i < this->traffic_lights_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->traffic_lights(i));
  }

  // repeated .hdmap_proto.TrafficSign traffic_signs = 10;
  total_size += 1 * this->traffic_signs_size();
  for (int i = 0; i < this->traffic_signs_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->traffic_signs(i));
  }

  // repeated uint32 pred_indices = 20;
  {
    int data_size = 0;
    for (int i = 0; i < this->pred_indices_size(); i++) {
      data_size += ::google::protobuf::internal::WireFormatLite::
        UInt32Size(this->pred_indices(i));
    }
    total_size += 2 * this->pred_indices_size() + data_size;
  }

  // repeated uint32 succ_indices = 21;
  {
    int data_size = 0;
    for (int i = 0; i < this->succ_indices_size(); i++) {
      data_size += ::google::protobuf::internal::WireFormatLite::
        UInt32Size(this->succ_indices(i));
    }
    total_size += 2 * this->succ_indices_size() + data_size;
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

void Lane::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Lane* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Lane*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Lane::MergeFrom(const Lane& from) {
  GOOGLE_CHECK_NE(&from, this);
  tile_ids_.MergeFrom(from.tile_ids_);
  lines_.MergeFrom(from.lines_);
  lane_markings_.MergeFrom(from.lane_markings_);
  traffic_lights_.MergeFrom(from.traffic_lights_);
  traffic_signs_.MergeFrom(from.traffic_signs_);
  pred_indices_.MergeFrom(from.pred_indices_);
  succ_indices_.MergeFrom(from.succ_indices_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_id()) {
      mutable_id()->::hdmap_proto::Id::MergeFrom(from.id());
    }
    if (from.has_function()) {
      set_function(from.function());
    }
    if (from.has_direction()) {
      set_direction(from.direction());
    }
    if (from.has_style()) {
      set_style(from.style());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Lane::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Lane::CopyFrom(const Lane& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Lane::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  if (has_id()) {
    if (!this->id().IsInitialized()) return false;
  }
  if (!::google::protobuf::internal::AllAreInitialized(this->tile_ids())) return false;
  if (!::google::protobuf::internal::AllAreInitialized(this->lines())) return false;
  if (!::google::protobuf::internal::AllAreInitialized(this->lane_markings())) return false;
  if (!::google::protobuf::internal::AllAreInitialized(this->traffic_lights())) return false;
  if (!::google::protobuf::internal::AllAreInitialized(this->traffic_signs())) return false;
  return true;
}

void Lane::Swap(Lane* other) {
  if (other != this) {
    std::swap(id_, other->id_);
    tile_ids_.Swap(&other->tile_ids_);
    std::swap(function_, other->function_);
    std::swap(direction_, other->direction_);
    std::swap(style_, other->style_);
    lines_.Swap(&other->lines_);
    lane_markings_.Swap(&other->lane_markings_);
    traffic_lights_.Swap(&other->traffic_lights_);
    traffic_signs_.Swap(&other->traffic_signs_);
    pred_indices_.Swap(&other->pred_indices_);
    succ_indices_.Swap(&other->succ_indices_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Lane::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Lane_descriptor_;
  metadata.reflection = Lane_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace hdmap_proto

// @@protoc_insertion_point(global_scope)