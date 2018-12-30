// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: section.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "section.pb.h"

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

const ::google::protobuf::Descriptor* Section_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Section_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_section_2eproto() {
  protobuf_AddDesc_section_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "section.proto");
  GOOGLE_CHECK(file != NULL);
  Section_descriptor_ = file->message_type(0);
  static const int Section_offsets_[16] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Section, id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Section, tile_ids_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Section, refline_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Section, borders_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Section, lanes_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Section, stoplines_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Section, speedbumps_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Section, poles_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Section, boards_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Section, zones_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Section, lane_markings_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Section, traffic_lights_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Section, traffic_signs_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Section, parking_spaces_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Section, pred_indices_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Section, succ_indices_),
  };
  Section_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Section_descriptor_,
      Section::default_instance_,
      Section_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Section, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Section, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Section));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_section_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Section_descriptor_, &Section::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_section_2eproto() {
  delete Section::default_instance_;
  delete Section_reflection_;
}

void protobuf_AddDesc_section_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::hdmap_proto::protobuf_AddDesc_id_2eproto();
  ::hdmap_proto::protobuf_AddDesc_geometry_2eproto();
  ::hdmap_proto::protobuf_AddDesc_object_2eproto();
  ::hdmap_proto::protobuf_AddDesc_lane_5fmarking_2eproto();
  ::hdmap_proto::protobuf_AddDesc_traffic_5fsign_2eproto();
  ::hdmap_proto::protobuf_AddDesc_traffic_5flight_2eproto();
  ::hdmap_proto::protobuf_AddDesc_lane_2eproto();
  ::hdmap_proto::protobuf_AddDesc_parking_5fspace_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\rsection.proto\022\013hdmap_proto\032\010id.proto\032\016"
    "geometry.proto\032\014object.proto\032\022lane_marki"
    "ng.proto\032\022traffic_sign.proto\032\023traffic_li"
    "ght.proto\032\nlane.proto\032\023parking_space.pro"
    "to\"\345\004\n\007Section\022\033\n\002id\030\001 \002(\0132\017.hdmap_proto"
    ".Id\022!\n\010tile_ids\030\002 \003(\0132\017.hdmap_proto.Id\022\""
    "\n\007refline\030\003 \001(\0132\021.hdmap_proto.Lane\022\"\n\007bo"
    "rders\030\004 \003(\0132\021.hdmap_proto.Lane\022 \n\005lanes\030"
    "\005 \003(\0132\021.hdmap_proto.Lane\022(\n\tstoplines\030\006 "
    "\003(\0132\025.hdmap_proto.StopLine\022*\n\nspeedbumps"
    "\030\007 \003(\0132\026.hdmap_proto.SpeedBump\022 \n\005poles\030"
    "\010 \003(\0132\021.hdmap_proto.Pole\022\"\n\006boards\030\t \003(\013"
    "2\022.hdmap_proto.Board\022 \n\005zones\030\n \003(\0132\021.hd"
    "map_proto.Zone\022/\n\rlane_markings\030\013 \003(\0132\030."
    "hdmap_proto.LaneMarking\0221\n\016traffic_light"
    "s\030\014 \003(\0132\031.hdmap_proto.TrafficLight\022/\n\rtr"
    "affic_signs\030\r \003(\0132\030.hdmap_proto.TrafficS"
    "ign\0221\n\016parking_spaces\030\016 \003(\0132\031.hdmap_prot"
    "o.ParkingSpace\022\024\n\014pred_indices\030\024 \003(\r\022\024\n\014"
    "succ_indices\030\025 \003(\r", 778);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "section.proto", &protobuf_RegisterTypes);
  Section::default_instance_ = new Section();
  Section::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_section_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_section_2eproto {
  StaticDescriptorInitializer_section_2eproto() {
    protobuf_AddDesc_section_2eproto();
  }
} static_descriptor_initializer_section_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int Section::kIdFieldNumber;
const int Section::kTileIdsFieldNumber;
const int Section::kReflineFieldNumber;
const int Section::kBordersFieldNumber;
const int Section::kLanesFieldNumber;
const int Section::kStoplinesFieldNumber;
const int Section::kSpeedbumpsFieldNumber;
const int Section::kPolesFieldNumber;
const int Section::kBoardsFieldNumber;
const int Section::kZonesFieldNumber;
const int Section::kLaneMarkingsFieldNumber;
const int Section::kTrafficLightsFieldNumber;
const int Section::kTrafficSignsFieldNumber;
const int Section::kParkingSpacesFieldNumber;
const int Section::kPredIndicesFieldNumber;
const int Section::kSuccIndicesFieldNumber;
#endif  // !_MSC_VER

Section::Section()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:hdmap_proto.Section)
}

void Section::InitAsDefaultInstance() {
  id_ = const_cast< ::hdmap_proto::Id*>(&::hdmap_proto::Id::default_instance());
  refline_ = const_cast< ::hdmap_proto::Lane*>(&::hdmap_proto::Lane::default_instance());
}

Section::Section(const Section& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:hdmap_proto.Section)
}

void Section::SharedCtor() {
  _cached_size_ = 0;
  id_ = NULL;
  refline_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Section::~Section() {
  // @@protoc_insertion_point(destructor:hdmap_proto.Section)
  SharedDtor();
}

void Section::SharedDtor() {
  if (this != default_instance_) {
    delete id_;
    delete refline_;
  }
}

void Section::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Section::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Section_descriptor_;
}

const Section& Section::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_section_2eproto();
  return *default_instance_;
}

Section* Section::default_instance_ = NULL;

Section* Section::New() const {
  return new Section;
}

void Section::Clear() {
  if (_has_bits_[0 / 32] & 5) {
    if (has_id()) {
      if (id_ != NULL) id_->::hdmap_proto::Id::Clear();
    }
    if (has_refline()) {
      if (refline_ != NULL) refline_->::hdmap_proto::Lane::Clear();
    }
  }
  tile_ids_.Clear();
  borders_.Clear();
  lanes_.Clear();
  stoplines_.Clear();
  speedbumps_.Clear();
  poles_.Clear();
  boards_.Clear();
  zones_.Clear();
  lane_markings_.Clear();
  traffic_lights_.Clear();
  traffic_signs_.Clear();
  parking_spaces_.Clear();
  pred_indices_.Clear();
  succ_indices_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Section::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:hdmap_proto.Section)
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
        if (input->ExpectTag(26)) goto parse_refline;
        break;
      }

      // optional .hdmap_proto.Lane refline = 3;
      case 3: {
        if (tag == 26) {
         parse_refline:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_refline()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(34)) goto parse_borders;
        break;
      }

      // repeated .hdmap_proto.Lane borders = 4;
      case 4: {
        if (tag == 34) {
         parse_borders:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_borders()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(34)) goto parse_borders;
        if (input->ExpectTag(42)) goto parse_lanes;
        break;
      }

      // repeated .hdmap_proto.Lane lanes = 5;
      case 5: {
        if (tag == 42) {
         parse_lanes:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_lanes()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(42)) goto parse_lanes;
        if (input->ExpectTag(50)) goto parse_stoplines;
        break;
      }

      // repeated .hdmap_proto.StopLine stoplines = 6;
      case 6: {
        if (tag == 50) {
         parse_stoplines:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_stoplines()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(50)) goto parse_stoplines;
        if (input->ExpectTag(58)) goto parse_speedbumps;
        break;
      }

      // repeated .hdmap_proto.SpeedBump speedbumps = 7;
      case 7: {
        if (tag == 58) {
         parse_speedbumps:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_speedbumps()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(58)) goto parse_speedbumps;
        if (input->ExpectTag(66)) goto parse_poles;
        break;
      }

      // repeated .hdmap_proto.Pole poles = 8;
      case 8: {
        if (tag == 66) {
         parse_poles:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_poles()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(66)) goto parse_poles;
        if (input->ExpectTag(74)) goto parse_boards;
        break;
      }

      // repeated .hdmap_proto.Board boards = 9;
      case 9: {
        if (tag == 74) {
         parse_boards:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_boards()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(74)) goto parse_boards;
        if (input->ExpectTag(82)) goto parse_zones;
        break;
      }

      // repeated .hdmap_proto.Zone zones = 10;
      case 10: {
        if (tag == 82) {
         parse_zones:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_zones()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(82)) goto parse_zones;
        if (input->ExpectTag(90)) goto parse_lane_markings;
        break;
      }

      // repeated .hdmap_proto.LaneMarking lane_markings = 11;
      case 11: {
        if (tag == 90) {
         parse_lane_markings:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_lane_markings()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(90)) goto parse_lane_markings;
        if (input->ExpectTag(98)) goto parse_traffic_lights;
        break;
      }

      // repeated .hdmap_proto.TrafficLight traffic_lights = 12;
      case 12: {
        if (tag == 98) {
         parse_traffic_lights:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_traffic_lights()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(98)) goto parse_traffic_lights;
        if (input->ExpectTag(106)) goto parse_traffic_signs;
        break;
      }

      // repeated .hdmap_proto.TrafficSign traffic_signs = 13;
      case 13: {
        if (tag == 106) {
         parse_traffic_signs:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_traffic_signs()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(106)) goto parse_traffic_signs;
        if (input->ExpectTag(114)) goto parse_parking_spaces;
        break;
      }

      // repeated .hdmap_proto.ParkingSpace parking_spaces = 14;
      case 14: {
        if (tag == 114) {
         parse_parking_spaces:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_parking_spaces()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(114)) goto parse_parking_spaces;
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
  // @@protoc_insertion_point(parse_success:hdmap_proto.Section)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:hdmap_proto.Section)
  return false;
#undef DO_
}

void Section::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:hdmap_proto.Section)
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

  // optional .hdmap_proto.Lane refline = 3;
  if (has_refline()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      3, this->refline(), output);
  }

  // repeated .hdmap_proto.Lane borders = 4;
  for (int i = 0; i < this->borders_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      4, this->borders(i), output);
  }

  // repeated .hdmap_proto.Lane lanes = 5;
  for (int i = 0; i < this->lanes_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      5, this->lanes(i), output);
  }

  // repeated .hdmap_proto.StopLine stoplines = 6;
  for (int i = 0; i < this->stoplines_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      6, this->stoplines(i), output);
  }

  // repeated .hdmap_proto.SpeedBump speedbumps = 7;
  for (int i = 0; i < this->speedbumps_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      7, this->speedbumps(i), output);
  }

  // repeated .hdmap_proto.Pole poles = 8;
  for (int i = 0; i < this->poles_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      8, this->poles(i), output);
  }

  // repeated .hdmap_proto.Board boards = 9;
  for (int i = 0; i < this->boards_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      9, this->boards(i), output);
  }

  // repeated .hdmap_proto.Zone zones = 10;
  for (int i = 0; i < this->zones_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      10, this->zones(i), output);
  }

  // repeated .hdmap_proto.LaneMarking lane_markings = 11;
  for (int i = 0; i < this->lane_markings_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      11, this->lane_markings(i), output);
  }

  // repeated .hdmap_proto.TrafficLight traffic_lights = 12;
  for (int i = 0; i < this->traffic_lights_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      12, this->traffic_lights(i), output);
  }

  // repeated .hdmap_proto.TrafficSign traffic_signs = 13;
  for (int i = 0; i < this->traffic_signs_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      13, this->traffic_signs(i), output);
  }

  // repeated .hdmap_proto.ParkingSpace parking_spaces = 14;
  for (int i = 0; i < this->parking_spaces_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      14, this->parking_spaces(i), output);
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
  // @@protoc_insertion_point(serialize_end:hdmap_proto.Section)
}

::google::protobuf::uint8* Section::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:hdmap_proto.Section)
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

  // optional .hdmap_proto.Lane refline = 3;
  if (has_refline()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        3, this->refline(), target);
  }

  // repeated .hdmap_proto.Lane borders = 4;
  for (int i = 0; i < this->borders_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        4, this->borders(i), target);
  }

  // repeated .hdmap_proto.Lane lanes = 5;
  for (int i = 0; i < this->lanes_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        5, this->lanes(i), target);
  }

  // repeated .hdmap_proto.StopLine stoplines = 6;
  for (int i = 0; i < this->stoplines_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        6, this->stoplines(i), target);
  }

  // repeated .hdmap_proto.SpeedBump speedbumps = 7;
  for (int i = 0; i < this->speedbumps_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        7, this->speedbumps(i), target);
  }

  // repeated .hdmap_proto.Pole poles = 8;
  for (int i = 0; i < this->poles_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        8, this->poles(i), target);
  }

  // repeated .hdmap_proto.Board boards = 9;
  for (int i = 0; i < this->boards_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        9, this->boards(i), target);
  }

  // repeated .hdmap_proto.Zone zones = 10;
  for (int i = 0; i < this->zones_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        10, this->zones(i), target);
  }

  // repeated .hdmap_proto.LaneMarking lane_markings = 11;
  for (int i = 0; i < this->lane_markings_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        11, this->lane_markings(i), target);
  }

  // repeated .hdmap_proto.TrafficLight traffic_lights = 12;
  for (int i = 0; i < this->traffic_lights_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        12, this->traffic_lights(i), target);
  }

  // repeated .hdmap_proto.TrafficSign traffic_signs = 13;
  for (int i = 0; i < this->traffic_signs_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        13, this->traffic_signs(i), target);
  }

  // repeated .hdmap_proto.ParkingSpace parking_spaces = 14;
  for (int i = 0; i < this->parking_spaces_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        14, this->parking_spaces(i), target);
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
  // @@protoc_insertion_point(serialize_to_array_end:hdmap_proto.Section)
  return target;
}

int Section::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required .hdmap_proto.Id id = 1;
    if (has_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->id());
    }

    // optional .hdmap_proto.Lane refline = 3;
    if (has_refline()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->refline());
    }

  }
  // repeated .hdmap_proto.Id tile_ids = 2;
  total_size += 1 * this->tile_ids_size();
  for (int i = 0; i < this->tile_ids_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->tile_ids(i));
  }

  // repeated .hdmap_proto.Lane borders = 4;
  total_size += 1 * this->borders_size();
  for (int i = 0; i < this->borders_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->borders(i));
  }

  // repeated .hdmap_proto.Lane lanes = 5;
  total_size += 1 * this->lanes_size();
  for (int i = 0; i < this->lanes_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->lanes(i));
  }

  // repeated .hdmap_proto.StopLine stoplines = 6;
  total_size += 1 * this->stoplines_size();
  for (int i = 0; i < this->stoplines_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->stoplines(i));
  }

  // repeated .hdmap_proto.SpeedBump speedbumps = 7;
  total_size += 1 * this->speedbumps_size();
  for (int i = 0; i < this->speedbumps_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->speedbumps(i));
  }

  // repeated .hdmap_proto.Pole poles = 8;
  total_size += 1 * this->poles_size();
  for (int i = 0; i < this->poles_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->poles(i));
  }

  // repeated .hdmap_proto.Board boards = 9;
  total_size += 1 * this->boards_size();
  for (int i = 0; i < this->boards_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->boards(i));
  }

  // repeated .hdmap_proto.Zone zones = 10;
  total_size += 1 * this->zones_size();
  for (int i = 0; i < this->zones_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->zones(i));
  }

  // repeated .hdmap_proto.LaneMarking lane_markings = 11;
  total_size += 1 * this->lane_markings_size();
  for (int i = 0; i < this->lane_markings_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->lane_markings(i));
  }

  // repeated .hdmap_proto.TrafficLight traffic_lights = 12;
  total_size += 1 * this->traffic_lights_size();
  for (int i = 0; i < this->traffic_lights_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->traffic_lights(i));
  }

  // repeated .hdmap_proto.TrafficSign traffic_signs = 13;
  total_size += 1 * this->traffic_signs_size();
  for (int i = 0; i < this->traffic_signs_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->traffic_signs(i));
  }

  // repeated .hdmap_proto.ParkingSpace parking_spaces = 14;
  total_size += 1 * this->parking_spaces_size();
  for (int i = 0; i < this->parking_spaces_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->parking_spaces(i));
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

void Section::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Section* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Section*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Section::MergeFrom(const Section& from) {
  GOOGLE_CHECK_NE(&from, this);
  tile_ids_.MergeFrom(from.tile_ids_);
  borders_.MergeFrom(from.borders_);
  lanes_.MergeFrom(from.lanes_);
  stoplines_.MergeFrom(from.stoplines_);
  speedbumps_.MergeFrom(from.speedbumps_);
  poles_.MergeFrom(from.poles_);
  boards_.MergeFrom(from.boards_);
  zones_.MergeFrom(from.zones_);
  lane_markings_.MergeFrom(from.lane_markings_);
  traffic_lights_.MergeFrom(from.traffic_lights_);
  traffic_signs_.MergeFrom(from.traffic_signs_);
  parking_spaces_.MergeFrom(from.parking_spaces_);
  pred_indices_.MergeFrom(from.pred_indices_);
  succ_indices_.MergeFrom(from.succ_indices_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_id()) {
      mutable_id()->::hdmap_proto::Id::MergeFrom(from.id());
    }
    if (from.has_refline()) {
      mutable_refline()->::hdmap_proto::Lane::MergeFrom(from.refline());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Section::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Section::CopyFrom(const Section& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Section::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  if (has_id()) {
    if (!this->id().IsInitialized()) return false;
  }
  if (!::google::protobuf::internal::AllAreInitialized(this->tile_ids())) return false;
  if (has_refline()) {
    if (!this->refline().IsInitialized()) return false;
  }
  if (!::google::protobuf::internal::AllAreInitialized(this->borders())) return false;
  if (!::google::protobuf::internal::AllAreInitialized(this->lanes())) return false;
  if (!::google::protobuf::internal::AllAreInitialized(this->stoplines())) return false;
  if (!::google::protobuf::internal::AllAreInitialized(this->speedbumps())) return false;
  if (!::google::protobuf::internal::AllAreInitialized(this->poles())) return false;
  if (!::google::protobuf::internal::AllAreInitialized(this->boards())) return false;
  if (!::google::protobuf::internal::AllAreInitialized(this->zones())) return false;
  if (!::google::protobuf::internal::AllAreInitialized(this->lane_markings())) return false;
  if (!::google::protobuf::internal::AllAreInitialized(this->traffic_lights())) return false;
  if (!::google::protobuf::internal::AllAreInitialized(this->traffic_signs())) return false;
  if (!::google::protobuf::internal::AllAreInitialized(this->parking_spaces())) return false;
  return true;
}

void Section::Swap(Section* other) {
  if (other != this) {
    std::swap(id_, other->id_);
    tile_ids_.Swap(&other->tile_ids_);
    std::swap(refline_, other->refline_);
    borders_.Swap(&other->borders_);
    lanes_.Swap(&other->lanes_);
    stoplines_.Swap(&other->stoplines_);
    speedbumps_.Swap(&other->speedbumps_);
    poles_.Swap(&other->poles_);
    boards_.Swap(&other->boards_);
    zones_.Swap(&other->zones_);
    lane_markings_.Swap(&other->lane_markings_);
    traffic_lights_.Swap(&other->traffic_lights_);
    traffic_signs_.Swap(&other->traffic_signs_);
    parking_spaces_.Swap(&other->parking_spaces_);
    pred_indices_.Swap(&other->pred_indices_);
    succ_indices_.Swap(&other->succ_indices_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Section::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Section_descriptor_;
  metadata.reflection = Section_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace hdmap_proto

// @@protoc_insertion_point(global_scope)