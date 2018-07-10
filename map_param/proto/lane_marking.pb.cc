// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: lane_marking.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "lane_marking.pb.h"

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

const ::google::protobuf::Descriptor* LaneMarking_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  LaneMarking_reflection_ = NULL;
const ::google::protobuf::EnumDescriptor* LaneMarking_Type_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_lane_5fmarking_2eproto() {
  protobuf_AddDesc_lane_5fmarking_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "lane_marking.proto");
  GOOGLE_CHECK(file != NULL);
  LaneMarking_descriptor_ = file->message_type(0);
  static const int LaneMarking_offsets_[6] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LaneMarking, id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LaneMarking, tile_ids_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LaneMarking, type_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LaneMarking, polygon_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LaneMarking, value_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LaneMarking, link_ids_),
  };
  LaneMarking_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      LaneMarking_descriptor_,
      LaneMarking::default_instance_,
      LaneMarking_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LaneMarking, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LaneMarking, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(LaneMarking));
  LaneMarking_Type_descriptor_ = LaneMarking_descriptor_->enum_type(0);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_lane_5fmarking_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    LaneMarking_descriptor_, &LaneMarking::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_lane_5fmarking_2eproto() {
  delete LaneMarking::default_instance_;
  delete LaneMarking_reflection_;
}

void protobuf_AddDesc_lane_5fmarking_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::hdmap_proto::protobuf_AddDesc_id_2eproto();
  ::hdmap_proto::protobuf_AddDesc_geometry_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\022lane_marking.proto\022\013hdmap_proto\032\010id.pr"
    "oto\032\016geometry.proto\"\251\004\n\013LaneMarking\022\033\n\002i"
    "d\030\001 \002(\0132\017.hdmap_proto.Id\022!\n\010tile_ids\030\002 \003"
    "(\0132\017.hdmap_proto.Id\022+\n\004type\030\003 \001(\0162\035.hdma"
    "p_proto.LaneMarking.Type\022%\n\007polygon\030\004 \002("
    "\0132\024.hdmap_proto.Polygon\022\r\n\005value\030\005 \001(\002\022!"
    "\n\010link_ids\030\006 \003(\0132\017.hdmap_proto.Id\"\323\002\n\004Ty"
    "pe\022\013\n\007UNKNOWN\020\000\022\016\n\nARROW_LEFT\020\001\022\021\n\rARROW"
    "_FORWARD\020\002\022\017\n\013ARROW_RIGHT\020\003\022\032\n\026ARROW_LEF"
    "T_AND_FORWARD\020\004\022\033\n\027ARROW_RIGHT_AND_FORWA"
    "RD\020\005\022\030\n\024ARROW_LEFT_AND_RIGHT\020\006\022\020\n\014ARROW_"
    "U_TURN\020\007\022\034\n\030ARROW_U_TURN_AND_FORWARD\020\010\022\031"
    "\n\025ARROW_U_TURN_AND_LEFT\020\t\022\024\n\020ARROW_MERGE"
    "_LEFT\020\n\022\025\n\021ARROW_MERGE_RIGHT\020\013\022\024\n\020CROSSW"
    "ALK_NOTICE\020\014\022\023\n\017SPEED_LIMIT_LOW\020\r\022\024\n\020SPE"
    "ED_LIMIT_HIGH\020\016", 615);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "lane_marking.proto", &protobuf_RegisterTypes);
  LaneMarking::default_instance_ = new LaneMarking();
  LaneMarking::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_lane_5fmarking_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_lane_5fmarking_2eproto {
  StaticDescriptorInitializer_lane_5fmarking_2eproto() {
    protobuf_AddDesc_lane_5fmarking_2eproto();
  }
} static_descriptor_initializer_lane_5fmarking_2eproto_;

// ===================================================================

const ::google::protobuf::EnumDescriptor* LaneMarking_Type_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return LaneMarking_Type_descriptor_;
}
bool LaneMarking_Type_IsValid(int value) {
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
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
      return true;
    default:
      return false;
  }
}

#ifndef _MSC_VER
const LaneMarking_Type LaneMarking::UNKNOWN;
const LaneMarking_Type LaneMarking::ARROW_LEFT;
const LaneMarking_Type LaneMarking::ARROW_FORWARD;
const LaneMarking_Type LaneMarking::ARROW_RIGHT;
const LaneMarking_Type LaneMarking::ARROW_LEFT_AND_FORWARD;
const LaneMarking_Type LaneMarking::ARROW_RIGHT_AND_FORWARD;
const LaneMarking_Type LaneMarking::ARROW_LEFT_AND_RIGHT;
const LaneMarking_Type LaneMarking::ARROW_U_TURN;
const LaneMarking_Type LaneMarking::ARROW_U_TURN_AND_FORWARD;
const LaneMarking_Type LaneMarking::ARROW_U_TURN_AND_LEFT;
const LaneMarking_Type LaneMarking::ARROW_MERGE_LEFT;
const LaneMarking_Type LaneMarking::ARROW_MERGE_RIGHT;
const LaneMarking_Type LaneMarking::CROSSWALK_NOTICE;
const LaneMarking_Type LaneMarking::SPEED_LIMIT_LOW;
const LaneMarking_Type LaneMarking::SPEED_LIMIT_HIGH;
const LaneMarking_Type LaneMarking::Type_MIN;
const LaneMarking_Type LaneMarking::Type_MAX;
const int LaneMarking::Type_ARRAYSIZE;
#endif  // _MSC_VER
#ifndef _MSC_VER
const int LaneMarking::kIdFieldNumber;
const int LaneMarking::kTileIdsFieldNumber;
const int LaneMarking::kTypeFieldNumber;
const int LaneMarking::kPolygonFieldNumber;
const int LaneMarking::kValueFieldNumber;
const int LaneMarking::kLinkIdsFieldNumber;
#endif  // !_MSC_VER

LaneMarking::LaneMarking()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:hdmap_proto.LaneMarking)
}

void LaneMarking::InitAsDefaultInstance() {
  id_ = const_cast< ::hdmap_proto::Id*>(&::hdmap_proto::Id::default_instance());
  polygon_ = const_cast< ::hdmap_proto::Polygon*>(&::hdmap_proto::Polygon::default_instance());
}

LaneMarking::LaneMarking(const LaneMarking& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:hdmap_proto.LaneMarking)
}

void LaneMarking::SharedCtor() {
  _cached_size_ = 0;
  id_ = NULL;
  type_ = 0;
  polygon_ = NULL;
  value_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

LaneMarking::~LaneMarking() {
  // @@protoc_insertion_point(destructor:hdmap_proto.LaneMarking)
  SharedDtor();
}

void LaneMarking::SharedDtor() {
  if (this != default_instance_) {
    delete id_;
    delete polygon_;
  }
}

void LaneMarking::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* LaneMarking::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return LaneMarking_descriptor_;
}

const LaneMarking& LaneMarking::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_lane_5fmarking_2eproto();
  return *default_instance_;
}

LaneMarking* LaneMarking::default_instance_ = NULL;

LaneMarking* LaneMarking::New() const {
  return new LaneMarking;
}

void LaneMarking::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<LaneMarking*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 29) {
    ZR_(type_, value_);
    if (has_id()) {
      if (id_ != NULL) id_->::hdmap_proto::Id::Clear();
    }
    if (has_polygon()) {
      if (polygon_ != NULL) polygon_->::hdmap_proto::Polygon::Clear();
    }
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  tile_ids_.Clear();
  link_ids_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool LaneMarking::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:hdmap_proto.LaneMarking)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
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
        if (input->ExpectTag(24)) goto parse_type;
        break;
      }

      // optional .hdmap_proto.LaneMarking.Type type = 3;
      case 3: {
        if (tag == 24) {
         parse_type:
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::hdmap_proto::LaneMarking_Type_IsValid(value)) {
            set_type(static_cast< ::hdmap_proto::LaneMarking_Type >(value));
          } else {
            mutable_unknown_fields()->AddVarint(3, value);
          }
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(34)) goto parse_polygon;
        break;
      }

      // required .hdmap_proto.Polygon polygon = 4;
      case 4: {
        if (tag == 34) {
         parse_polygon:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_polygon()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(45)) goto parse_value;
        break;
      }

      // optional float value = 5;
      case 5: {
        if (tag == 45) {
         parse_value:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &value_)));
          set_has_value();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(50)) goto parse_link_ids;
        break;
      }

      // repeated .hdmap_proto.Id link_ids = 6;
      case 6: {
        if (tag == 50) {
         parse_link_ids:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_link_ids()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(50)) goto parse_link_ids;
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
  // @@protoc_insertion_point(parse_success:hdmap_proto.LaneMarking)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:hdmap_proto.LaneMarking)
  return false;
#undef DO_
}

void LaneMarking::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:hdmap_proto.LaneMarking)
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

  // optional .hdmap_proto.LaneMarking.Type type = 3;
  if (has_type()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      3, this->type(), output);
  }

  // required .hdmap_proto.Polygon polygon = 4;
  if (has_polygon()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      4, this->polygon(), output);
  }

  // optional float value = 5;
  if (has_value()) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(5, this->value(), output);
  }

  // repeated .hdmap_proto.Id link_ids = 6;
  for (int i = 0; i < this->link_ids_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      6, this->link_ids(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:hdmap_proto.LaneMarking)
}

::google::protobuf::uint8* LaneMarking::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:hdmap_proto.LaneMarking)
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

  // optional .hdmap_proto.LaneMarking.Type type = 3;
  if (has_type()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      3, this->type(), target);
  }

  // required .hdmap_proto.Polygon polygon = 4;
  if (has_polygon()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        4, this->polygon(), target);
  }

  // optional float value = 5;
  if (has_value()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFloatToArray(5, this->value(), target);
  }

  // repeated .hdmap_proto.Id link_ids = 6;
  for (int i = 0; i < this->link_ids_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        6, this->link_ids(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:hdmap_proto.LaneMarking)
  return target;
}

int LaneMarking::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required .hdmap_proto.Id id = 1;
    if (has_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->id());
    }

    // optional .hdmap_proto.LaneMarking.Type type = 3;
    if (has_type()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->type());
    }

    // required .hdmap_proto.Polygon polygon = 4;
    if (has_polygon()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->polygon());
    }

    // optional float value = 5;
    if (has_value()) {
      total_size += 1 + 4;
    }

  }
  // repeated .hdmap_proto.Id tile_ids = 2;
  total_size += 1 * this->tile_ids_size();
  for (int i = 0; i < this->tile_ids_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->tile_ids(i));
  }

  // repeated .hdmap_proto.Id link_ids = 6;
  total_size += 1 * this->link_ids_size();
  for (int i = 0; i < this->link_ids_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->link_ids(i));
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

void LaneMarking::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const LaneMarking* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const LaneMarking*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void LaneMarking::MergeFrom(const LaneMarking& from) {
  GOOGLE_CHECK_NE(&from, this);
  tile_ids_.MergeFrom(from.tile_ids_);
  link_ids_.MergeFrom(from.link_ids_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_id()) {
      mutable_id()->::hdmap_proto::Id::MergeFrom(from.id());
    }
    if (from.has_type()) {
      set_type(from.type());
    }
    if (from.has_polygon()) {
      mutable_polygon()->::hdmap_proto::Polygon::MergeFrom(from.polygon());
    }
    if (from.has_value()) {
      set_value(from.value());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void LaneMarking::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void LaneMarking::CopyFrom(const LaneMarking& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool LaneMarking::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000009) != 0x00000009) return false;

  if (has_id()) {
    if (!this->id().IsInitialized()) return false;
  }
  if (!::google::protobuf::internal::AllAreInitialized(this->tile_ids())) return false;
  if (has_polygon()) {
    if (!this->polygon().IsInitialized()) return false;
  }
  if (!::google::protobuf::internal::AllAreInitialized(this->link_ids())) return false;
  return true;
}

void LaneMarking::Swap(LaneMarking* other) {
  if (other != this) {
    std::swap(id_, other->id_);
    tile_ids_.Swap(&other->tile_ids_);
    std::swap(type_, other->type_);
    std::swap(polygon_, other->polygon_);
    std::swap(value_, other->value_);
    link_ids_.Swap(&other->link_ids_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata LaneMarking::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = LaneMarking_descriptor_;
  metadata.reflection = LaneMarking_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace hdmap_proto

// @@protoc_insertion_point(global_scope)
