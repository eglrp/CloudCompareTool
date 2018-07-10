// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: road.proto

#ifndef PROTOBUF_road_2eproto__INCLUDED
#define PROTOBUF_road_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2006000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
#include "id.pb.h"
#include "geometry.pb.h"
#include "attribute.pb.h"
#include "object.pb.h"
#include "lane_marking.pb.h"
#include "traffic_sign.pb.h"
#include "traffic_light.pb.h"
#include "lane.pb.h"
// @@protoc_insertion_point(includes)

namespace hdmap_proto {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_road_2eproto();
void protobuf_AssignDesc_road_2eproto();
void protobuf_ShutdownFile_road_2eproto();

class Road;

enum Road_RoadType {
  Road_RoadType_UNKNOWN = 0
};
bool Road_RoadType_IsValid(int value);
const Road_RoadType Road_RoadType_RoadType_MIN = Road_RoadType_UNKNOWN;
const Road_RoadType Road_RoadType_RoadType_MAX = Road_RoadType_UNKNOWN;
const int Road_RoadType_RoadType_ARRAYSIZE = Road_RoadType_RoadType_MAX + 1;

const ::google::protobuf::EnumDescriptor* Road_RoadType_descriptor();
inline const ::std::string& Road_RoadType_Name(Road_RoadType value) {
  return ::google::protobuf::internal::NameOfEnum(
    Road_RoadType_descriptor(), value);
}
inline bool Road_RoadType_Parse(
    const ::std::string& name, Road_RoadType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<Road_RoadType>(
    Road_RoadType_descriptor(), name, value);
}
// ===================================================================

class Road : public ::google::protobuf::Message {
 public:
  Road();
  virtual ~Road();

  Road(const Road& from);

  inline Road& operator=(const Road& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Road& default_instance();

  void Swap(Road* other);

  // implements Message ----------------------------------------------

  Road* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Road& from);
  void MergeFrom(const Road& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  typedef Road_RoadType RoadType;
  static const RoadType UNKNOWN = Road_RoadType_UNKNOWN;
  static inline bool RoadType_IsValid(int value) {
    return Road_RoadType_IsValid(value);
  }
  static const RoadType RoadType_MIN =
    Road_RoadType_RoadType_MIN;
  static const RoadType RoadType_MAX =
    Road_RoadType_RoadType_MAX;
  static const int RoadType_ARRAYSIZE =
    Road_RoadType_RoadType_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  RoadType_descriptor() {
    return Road_RoadType_descriptor();
  }
  static inline const ::std::string& RoadType_Name(RoadType value) {
    return Road_RoadType_Name(value);
  }
  static inline bool RoadType_Parse(const ::std::string& name,
      RoadType* value) {
    return Road_RoadType_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  // required .hdmap_proto.Id id = 1;
  inline bool has_id() const;
  inline void clear_id();
  static const int kIdFieldNumber = 1;
  inline const ::hdmap_proto::Id& id() const;
  inline ::hdmap_proto::Id* mutable_id();
  inline ::hdmap_proto::Id* release_id();
  inline void set_allocated_id(::hdmap_proto::Id* id);

  // repeated .hdmap_proto.Id tile_ids = 2;
  inline int tile_ids_size() const;
  inline void clear_tile_ids();
  static const int kTileIdsFieldNumber = 2;
  inline const ::hdmap_proto::Id& tile_ids(int index) const;
  inline ::hdmap_proto::Id* mutable_tile_ids(int index);
  inline ::hdmap_proto::Id* add_tile_ids();
  inline const ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Id >&
      tile_ids() const;
  inline ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Id >*
      mutable_tile_ids();

  // required .hdmap_proto.Road.RoadType type = 4;
  inline bool has_type() const;
  inline void clear_type();
  static const int kTypeFieldNumber = 4;
  inline ::hdmap_proto::Road_RoadType type() const;
  inline void set_type(::hdmap_proto::Road_RoadType value);

  // repeated .hdmap_proto.Lane reflines = 5;
  inline int reflines_size() const;
  inline void clear_reflines();
  static const int kReflinesFieldNumber = 5;
  inline const ::hdmap_proto::Lane& reflines(int index) const;
  inline ::hdmap_proto::Lane* mutable_reflines(int index);
  inline ::hdmap_proto::Lane* add_reflines();
  inline const ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Lane >&
      reflines() const;
  inline ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Lane >*
      mutable_reflines();

  // repeated .hdmap_proto.Lane lanes = 6;
  inline int lanes_size() const;
  inline void clear_lanes();
  static const int kLanesFieldNumber = 6;
  inline const ::hdmap_proto::Lane& lanes(int index) const;
  inline ::hdmap_proto::Lane* mutable_lanes(int index);
  inline ::hdmap_proto::Lane* add_lanes();
  inline const ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Lane >&
      lanes() const;
  inline ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Lane >*
      mutable_lanes();

  // repeated .hdmap_proto.StopLine stoplines = 10;
  inline int stoplines_size() const;
  inline void clear_stoplines();
  static const int kStoplinesFieldNumber = 10;
  inline const ::hdmap_proto::StopLine& stoplines(int index) const;
  inline ::hdmap_proto::StopLine* mutable_stoplines(int index);
  inline ::hdmap_proto::StopLine* add_stoplines();
  inline const ::google::protobuf::RepeatedPtrField< ::hdmap_proto::StopLine >&
      stoplines() const;
  inline ::google::protobuf::RepeatedPtrField< ::hdmap_proto::StopLine >*
      mutable_stoplines();

  // repeated .hdmap_proto.SpeedBump speedbumps = 11;
  inline int speedbumps_size() const;
  inline void clear_speedbumps();
  static const int kSpeedbumpsFieldNumber = 11;
  inline const ::hdmap_proto::SpeedBump& speedbumps(int index) const;
  inline ::hdmap_proto::SpeedBump* mutable_speedbumps(int index);
  inline ::hdmap_proto::SpeedBump* add_speedbumps();
  inline const ::google::protobuf::RepeatedPtrField< ::hdmap_proto::SpeedBump >&
      speedbumps() const;
  inline ::google::protobuf::RepeatedPtrField< ::hdmap_proto::SpeedBump >*
      mutable_speedbumps();

  // repeated .hdmap_proto.Pole poles = 12;
  inline int poles_size() const;
  inline void clear_poles();
  static const int kPolesFieldNumber = 12;
  inline const ::hdmap_proto::Pole& poles(int index) const;
  inline ::hdmap_proto::Pole* mutable_poles(int index);
  inline ::hdmap_proto::Pole* add_poles();
  inline const ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Pole >&
      poles() const;
  inline ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Pole >*
      mutable_poles();

  // repeated .hdmap_proto.Board boards = 13;
  inline int boards_size() const;
  inline void clear_boards();
  static const int kBoardsFieldNumber = 13;
  inline const ::hdmap_proto::Board& boards(int index) const;
  inline ::hdmap_proto::Board* mutable_boards(int index);
  inline ::hdmap_proto::Board* add_boards();
  inline const ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Board >&
      boards() const;
  inline ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Board >*
      mutable_boards();

  // repeated .hdmap_proto.Zone zones = 14;
  inline int zones_size() const;
  inline void clear_zones();
  static const int kZonesFieldNumber = 14;
  inline const ::hdmap_proto::Zone& zones(int index) const;
  inline ::hdmap_proto::Zone* mutable_zones(int index);
  inline ::hdmap_proto::Zone* add_zones();
  inline const ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Zone >&
      zones() const;
  inline ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Zone >*
      mutable_zones();

  // repeated .hdmap_proto.LaneMarking lane_markings = 15;
  inline int lane_markings_size() const;
  inline void clear_lane_markings();
  static const int kLaneMarkingsFieldNumber = 15;
  inline const ::hdmap_proto::LaneMarking& lane_markings(int index) const;
  inline ::hdmap_proto::LaneMarking* mutable_lane_markings(int index);
  inline ::hdmap_proto::LaneMarking* add_lane_markings();
  inline const ::google::protobuf::RepeatedPtrField< ::hdmap_proto::LaneMarking >&
      lane_markings() const;
  inline ::google::protobuf::RepeatedPtrField< ::hdmap_proto::LaneMarking >*
      mutable_lane_markings();

  // repeated .hdmap_proto.TrafficLight traffic_lights = 16;
  inline int traffic_lights_size() const;
  inline void clear_traffic_lights();
  static const int kTrafficLightsFieldNumber = 16;
  inline const ::hdmap_proto::TrafficLight& traffic_lights(int index) const;
  inline ::hdmap_proto::TrafficLight* mutable_traffic_lights(int index);
  inline ::hdmap_proto::TrafficLight* add_traffic_lights();
  inline const ::google::protobuf::RepeatedPtrField< ::hdmap_proto::TrafficLight >&
      traffic_lights() const;
  inline ::google::protobuf::RepeatedPtrField< ::hdmap_proto::TrafficLight >*
      mutable_traffic_lights();

  // repeated .hdmap_proto.TrafficLight traffic_signs = 17;
  inline int traffic_signs_size() const;
  inline void clear_traffic_signs();
  static const int kTrafficSignsFieldNumber = 17;
  inline const ::hdmap_proto::TrafficLight& traffic_signs(int index) const;
  inline ::hdmap_proto::TrafficLight* mutable_traffic_signs(int index);
  inline ::hdmap_proto::TrafficLight* add_traffic_signs();
  inline const ::google::protobuf::RepeatedPtrField< ::hdmap_proto::TrafficLight >&
      traffic_signs() const;
  inline ::google::protobuf::RepeatedPtrField< ::hdmap_proto::TrafficLight >*
      mutable_traffic_signs();

  // repeated uint64 predecessors = 20;
  inline int predecessors_size() const;
  inline void clear_predecessors();
  static const int kPredecessorsFieldNumber = 20;
  inline ::google::protobuf::uint64 predecessors(int index) const;
  inline void set_predecessors(int index, ::google::protobuf::uint64 value);
  inline void add_predecessors(::google::protobuf::uint64 value);
  inline const ::google::protobuf::RepeatedField< ::google::protobuf::uint64 >&
      predecessors() const;
  inline ::google::protobuf::RepeatedField< ::google::protobuf::uint64 >*
      mutable_predecessors();

  // repeated uint64 successors = 21;
  inline int successors_size() const;
  inline void clear_successors();
  static const int kSuccessorsFieldNumber = 21;
  inline ::google::protobuf::uint64 successors(int index) const;
  inline void set_successors(int index, ::google::protobuf::uint64 value);
  inline void add_successors(::google::protobuf::uint64 value);
  inline const ::google::protobuf::RepeatedField< ::google::protobuf::uint64 >&
      successors() const;
  inline ::google::protobuf::RepeatedField< ::google::protobuf::uint64 >*
      mutable_successors();

  // @@protoc_insertion_point(class_scope:hdmap_proto.Road)
 private:
  inline void set_has_id();
  inline void clear_has_id();
  inline void set_has_type();
  inline void clear_has_type();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::hdmap_proto::Id* id_;
  ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Id > tile_ids_;
  ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Lane > reflines_;
  ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Lane > lanes_;
  ::google::protobuf::RepeatedPtrField< ::hdmap_proto::StopLine > stoplines_;
  ::google::protobuf::RepeatedPtrField< ::hdmap_proto::SpeedBump > speedbumps_;
  ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Pole > poles_;
  ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Board > boards_;
  ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Zone > zones_;
  ::google::protobuf::RepeatedPtrField< ::hdmap_proto::LaneMarking > lane_markings_;
  ::google::protobuf::RepeatedPtrField< ::hdmap_proto::TrafficLight > traffic_lights_;
  ::google::protobuf::RepeatedPtrField< ::hdmap_proto::TrafficLight > traffic_signs_;
  ::google::protobuf::RepeatedField< ::google::protobuf::uint64 > predecessors_;
  ::google::protobuf::RepeatedField< ::google::protobuf::uint64 > successors_;
  int type_;
  friend void  protobuf_AddDesc_road_2eproto();
  friend void protobuf_AssignDesc_road_2eproto();
  friend void protobuf_ShutdownFile_road_2eproto();

  void InitAsDefaultInstance();
  static Road* default_instance_;
};
// ===================================================================


// ===================================================================

// Road

// required .hdmap_proto.Id id = 1;
inline bool Road::has_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Road::set_has_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Road::clear_has_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Road::clear_id() {
  if (id_ != NULL) id_->::hdmap_proto::Id::Clear();
  clear_has_id();
}
inline const ::hdmap_proto::Id& Road::id() const {
  // @@protoc_insertion_point(field_get:hdmap_proto.Road.id)
  return id_ != NULL ? *id_ : *default_instance_->id_;
}
inline ::hdmap_proto::Id* Road::mutable_id() {
  set_has_id();
  if (id_ == NULL) id_ = new ::hdmap_proto::Id;
  // @@protoc_insertion_point(field_mutable:hdmap_proto.Road.id)
  return id_;
}
inline ::hdmap_proto::Id* Road::release_id() {
  clear_has_id();
  ::hdmap_proto::Id* temp = id_;
  id_ = NULL;
  return temp;
}
inline void Road::set_allocated_id(::hdmap_proto::Id* id) {
  delete id_;
  id_ = id;
  if (id) {
    set_has_id();
  } else {
    clear_has_id();
  }
  // @@protoc_insertion_point(field_set_allocated:hdmap_proto.Road.id)
}

// repeated .hdmap_proto.Id tile_ids = 2;
inline int Road::tile_ids_size() const {
  return tile_ids_.size();
}
inline void Road::clear_tile_ids() {
  tile_ids_.Clear();
}
inline const ::hdmap_proto::Id& Road::tile_ids(int index) const {
  // @@protoc_insertion_point(field_get:hdmap_proto.Road.tile_ids)
  return tile_ids_.Get(index);
}
inline ::hdmap_proto::Id* Road::mutable_tile_ids(int index) {
  // @@protoc_insertion_point(field_mutable:hdmap_proto.Road.tile_ids)
  return tile_ids_.Mutable(index);
}
inline ::hdmap_proto::Id* Road::add_tile_ids() {
  // @@protoc_insertion_point(field_add:hdmap_proto.Road.tile_ids)
  return tile_ids_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Id >&
Road::tile_ids() const {
  // @@protoc_insertion_point(field_list:hdmap_proto.Road.tile_ids)
  return tile_ids_;
}
inline ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Id >*
Road::mutable_tile_ids() {
  // @@protoc_insertion_point(field_mutable_list:hdmap_proto.Road.tile_ids)
  return &tile_ids_;
}

// required .hdmap_proto.Road.RoadType type = 4;
inline bool Road::has_type() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Road::set_has_type() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Road::clear_has_type() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Road::clear_type() {
  type_ = 0;
  clear_has_type();
}
inline ::hdmap_proto::Road_RoadType Road::type() const {
  // @@protoc_insertion_point(field_get:hdmap_proto.Road.type)
  return static_cast< ::hdmap_proto::Road_RoadType >(type_);
}
inline void Road::set_type(::hdmap_proto::Road_RoadType value) {
  assert(::hdmap_proto::Road_RoadType_IsValid(value));
  set_has_type();
  type_ = value;
  // @@protoc_insertion_point(field_set:hdmap_proto.Road.type)
}

// repeated .hdmap_proto.Lane reflines = 5;
inline int Road::reflines_size() const {
  return reflines_.size();
}
inline void Road::clear_reflines() {
  reflines_.Clear();
}
inline const ::hdmap_proto::Lane& Road::reflines(int index) const {
  // @@protoc_insertion_point(field_get:hdmap_proto.Road.reflines)
  return reflines_.Get(index);
}
inline ::hdmap_proto::Lane* Road::mutable_reflines(int index) {
  // @@protoc_insertion_point(field_mutable:hdmap_proto.Road.reflines)
  return reflines_.Mutable(index);
}
inline ::hdmap_proto::Lane* Road::add_reflines() {
  // @@protoc_insertion_point(field_add:hdmap_proto.Road.reflines)
  return reflines_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Lane >&
Road::reflines() const {
  // @@protoc_insertion_point(field_list:hdmap_proto.Road.reflines)
  return reflines_;
}
inline ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Lane >*
Road::mutable_reflines() {
  // @@protoc_insertion_point(field_mutable_list:hdmap_proto.Road.reflines)
  return &reflines_;
}

// repeated .hdmap_proto.Lane lanes = 6;
inline int Road::lanes_size() const {
  return lanes_.size();
}
inline void Road::clear_lanes() {
  lanes_.Clear();
}
inline const ::hdmap_proto::Lane& Road::lanes(int index) const {
  // @@protoc_insertion_point(field_get:hdmap_proto.Road.lanes)
  return lanes_.Get(index);
}
inline ::hdmap_proto::Lane* Road::mutable_lanes(int index) {
  // @@protoc_insertion_point(field_mutable:hdmap_proto.Road.lanes)
  return lanes_.Mutable(index);
}
inline ::hdmap_proto::Lane* Road::add_lanes() {
  // @@protoc_insertion_point(field_add:hdmap_proto.Road.lanes)
  return lanes_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Lane >&
Road::lanes() const {
  // @@protoc_insertion_point(field_list:hdmap_proto.Road.lanes)
  return lanes_;
}
inline ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Lane >*
Road::mutable_lanes() {
  // @@protoc_insertion_point(field_mutable_list:hdmap_proto.Road.lanes)
  return &lanes_;
}

// repeated .hdmap_proto.StopLine stoplines = 10;
inline int Road::stoplines_size() const {
  return stoplines_.size();
}
inline void Road::clear_stoplines() {
  stoplines_.Clear();
}
inline const ::hdmap_proto::StopLine& Road::stoplines(int index) const {
  // @@protoc_insertion_point(field_get:hdmap_proto.Road.stoplines)
  return stoplines_.Get(index);
}
inline ::hdmap_proto::StopLine* Road::mutable_stoplines(int index) {
  // @@protoc_insertion_point(field_mutable:hdmap_proto.Road.stoplines)
  return stoplines_.Mutable(index);
}
inline ::hdmap_proto::StopLine* Road::add_stoplines() {
  // @@protoc_insertion_point(field_add:hdmap_proto.Road.stoplines)
  return stoplines_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::hdmap_proto::StopLine >&
Road::stoplines() const {
  // @@protoc_insertion_point(field_list:hdmap_proto.Road.stoplines)
  return stoplines_;
}
inline ::google::protobuf::RepeatedPtrField< ::hdmap_proto::StopLine >*
Road::mutable_stoplines() {
  // @@protoc_insertion_point(field_mutable_list:hdmap_proto.Road.stoplines)
  return &stoplines_;
}

// repeated .hdmap_proto.SpeedBump speedbumps = 11;
inline int Road::speedbumps_size() const {
  return speedbumps_.size();
}
inline void Road::clear_speedbumps() {
  speedbumps_.Clear();
}
inline const ::hdmap_proto::SpeedBump& Road::speedbumps(int index) const {
  // @@protoc_insertion_point(field_get:hdmap_proto.Road.speedbumps)
  return speedbumps_.Get(index);
}
inline ::hdmap_proto::SpeedBump* Road::mutable_speedbumps(int index) {
  // @@protoc_insertion_point(field_mutable:hdmap_proto.Road.speedbumps)
  return speedbumps_.Mutable(index);
}
inline ::hdmap_proto::SpeedBump* Road::add_speedbumps() {
  // @@protoc_insertion_point(field_add:hdmap_proto.Road.speedbumps)
  return speedbumps_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::hdmap_proto::SpeedBump >&
Road::speedbumps() const {
  // @@protoc_insertion_point(field_list:hdmap_proto.Road.speedbumps)
  return speedbumps_;
}
inline ::google::protobuf::RepeatedPtrField< ::hdmap_proto::SpeedBump >*
Road::mutable_speedbumps() {
  // @@protoc_insertion_point(field_mutable_list:hdmap_proto.Road.speedbumps)
  return &speedbumps_;
}

// repeated .hdmap_proto.Pole poles = 12;
inline int Road::poles_size() const {
  return poles_.size();
}
inline void Road::clear_poles() {
  poles_.Clear();
}
inline const ::hdmap_proto::Pole& Road::poles(int index) const {
  // @@protoc_insertion_point(field_get:hdmap_proto.Road.poles)
  return poles_.Get(index);
}
inline ::hdmap_proto::Pole* Road::mutable_poles(int index) {
  // @@protoc_insertion_point(field_mutable:hdmap_proto.Road.poles)
  return poles_.Mutable(index);
}
inline ::hdmap_proto::Pole* Road::add_poles() {
  // @@protoc_insertion_point(field_add:hdmap_proto.Road.poles)
  return poles_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Pole >&
Road::poles() const {
  // @@protoc_insertion_point(field_list:hdmap_proto.Road.poles)
  return poles_;
}
inline ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Pole >*
Road::mutable_poles() {
  // @@protoc_insertion_point(field_mutable_list:hdmap_proto.Road.poles)
  return &poles_;
}

// repeated .hdmap_proto.Board boards = 13;
inline int Road::boards_size() const {
  return boards_.size();
}
inline void Road::clear_boards() {
  boards_.Clear();
}
inline const ::hdmap_proto::Board& Road::boards(int index) const {
  // @@protoc_insertion_point(field_get:hdmap_proto.Road.boards)
  return boards_.Get(index);
}
inline ::hdmap_proto::Board* Road::mutable_boards(int index) {
  // @@protoc_insertion_point(field_mutable:hdmap_proto.Road.boards)
  return boards_.Mutable(index);
}
inline ::hdmap_proto::Board* Road::add_boards() {
  // @@protoc_insertion_point(field_add:hdmap_proto.Road.boards)
  return boards_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Board >&
Road::boards() const {
  // @@protoc_insertion_point(field_list:hdmap_proto.Road.boards)
  return boards_;
}
inline ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Board >*
Road::mutable_boards() {
  // @@protoc_insertion_point(field_mutable_list:hdmap_proto.Road.boards)
  return &boards_;
}

// repeated .hdmap_proto.Zone zones = 14;
inline int Road::zones_size() const {
  return zones_.size();
}
inline void Road::clear_zones() {
  zones_.Clear();
}
inline const ::hdmap_proto::Zone& Road::zones(int index) const {
  // @@protoc_insertion_point(field_get:hdmap_proto.Road.zones)
  return zones_.Get(index);
}
inline ::hdmap_proto::Zone* Road::mutable_zones(int index) {
  // @@protoc_insertion_point(field_mutable:hdmap_proto.Road.zones)
  return zones_.Mutable(index);
}
inline ::hdmap_proto::Zone* Road::add_zones() {
  // @@protoc_insertion_point(field_add:hdmap_proto.Road.zones)
  return zones_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Zone >&
Road::zones() const {
  // @@protoc_insertion_point(field_list:hdmap_proto.Road.zones)
  return zones_;
}
inline ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Zone >*
Road::mutable_zones() {
  // @@protoc_insertion_point(field_mutable_list:hdmap_proto.Road.zones)
  return &zones_;
}

// repeated .hdmap_proto.LaneMarking lane_markings = 15;
inline int Road::lane_markings_size() const {
  return lane_markings_.size();
}
inline void Road::clear_lane_markings() {
  lane_markings_.Clear();
}
inline const ::hdmap_proto::LaneMarking& Road::lane_markings(int index) const {
  // @@protoc_insertion_point(field_get:hdmap_proto.Road.lane_markings)
  return lane_markings_.Get(index);
}
inline ::hdmap_proto::LaneMarking* Road::mutable_lane_markings(int index) {
  // @@protoc_insertion_point(field_mutable:hdmap_proto.Road.lane_markings)
  return lane_markings_.Mutable(index);
}
inline ::hdmap_proto::LaneMarking* Road::add_lane_markings() {
  // @@protoc_insertion_point(field_add:hdmap_proto.Road.lane_markings)
  return lane_markings_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::hdmap_proto::LaneMarking >&
Road::lane_markings() const {
  // @@protoc_insertion_point(field_list:hdmap_proto.Road.lane_markings)
  return lane_markings_;
}
inline ::google::protobuf::RepeatedPtrField< ::hdmap_proto::LaneMarking >*
Road::mutable_lane_markings() {
  // @@protoc_insertion_point(field_mutable_list:hdmap_proto.Road.lane_markings)
  return &lane_markings_;
}

// repeated .hdmap_proto.TrafficLight traffic_lights = 16;
inline int Road::traffic_lights_size() const {
  return traffic_lights_.size();
}
inline void Road::clear_traffic_lights() {
  traffic_lights_.Clear();
}
inline const ::hdmap_proto::TrafficLight& Road::traffic_lights(int index) const {
  // @@protoc_insertion_point(field_get:hdmap_proto.Road.traffic_lights)
  return traffic_lights_.Get(index);
}
inline ::hdmap_proto::TrafficLight* Road::mutable_traffic_lights(int index) {
  // @@protoc_insertion_point(field_mutable:hdmap_proto.Road.traffic_lights)
  return traffic_lights_.Mutable(index);
}
inline ::hdmap_proto::TrafficLight* Road::add_traffic_lights() {
  // @@protoc_insertion_point(field_add:hdmap_proto.Road.traffic_lights)
  return traffic_lights_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::hdmap_proto::TrafficLight >&
Road::traffic_lights() const {
  // @@protoc_insertion_point(field_list:hdmap_proto.Road.traffic_lights)
  return traffic_lights_;
}
inline ::google::protobuf::RepeatedPtrField< ::hdmap_proto::TrafficLight >*
Road::mutable_traffic_lights() {
  // @@protoc_insertion_point(field_mutable_list:hdmap_proto.Road.traffic_lights)
  return &traffic_lights_;
}

// repeated .hdmap_proto.TrafficLight traffic_signs = 17;
inline int Road::traffic_signs_size() const {
  return traffic_signs_.size();
}
inline void Road::clear_traffic_signs() {
  traffic_signs_.Clear();
}
inline const ::hdmap_proto::TrafficLight& Road::traffic_signs(int index) const {
  // @@protoc_insertion_point(field_get:hdmap_proto.Road.traffic_signs)
  return traffic_signs_.Get(index);
}
inline ::hdmap_proto::TrafficLight* Road::mutable_traffic_signs(int index) {
  // @@protoc_insertion_point(field_mutable:hdmap_proto.Road.traffic_signs)
  return traffic_signs_.Mutable(index);
}
inline ::hdmap_proto::TrafficLight* Road::add_traffic_signs() {
  // @@protoc_insertion_point(field_add:hdmap_proto.Road.traffic_signs)
  return traffic_signs_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::hdmap_proto::TrafficLight >&
Road::traffic_signs() const {
  // @@protoc_insertion_point(field_list:hdmap_proto.Road.traffic_signs)
  return traffic_signs_;
}
inline ::google::protobuf::RepeatedPtrField< ::hdmap_proto::TrafficLight >*
Road::mutable_traffic_signs() {
  // @@protoc_insertion_point(field_mutable_list:hdmap_proto.Road.traffic_signs)
  return &traffic_signs_;
}

// repeated uint64 predecessors = 20;
inline int Road::predecessors_size() const {
  return predecessors_.size();
}
inline void Road::clear_predecessors() {
  predecessors_.Clear();
}
inline ::google::protobuf::uint64 Road::predecessors(int index) const {
  // @@protoc_insertion_point(field_get:hdmap_proto.Road.predecessors)
  return predecessors_.Get(index);
}
inline void Road::set_predecessors(int index, ::google::protobuf::uint64 value) {
  predecessors_.Set(index, value);
  // @@protoc_insertion_point(field_set:hdmap_proto.Road.predecessors)
}
inline void Road::add_predecessors(::google::protobuf::uint64 value) {
  predecessors_.Add(value);
  // @@protoc_insertion_point(field_add:hdmap_proto.Road.predecessors)
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::uint64 >&
Road::predecessors() const {
  // @@protoc_insertion_point(field_list:hdmap_proto.Road.predecessors)
  return predecessors_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::uint64 >*
Road::mutable_predecessors() {
  // @@protoc_insertion_point(field_mutable_list:hdmap_proto.Road.predecessors)
  return &predecessors_;
}

// repeated uint64 successors = 21;
inline int Road::successors_size() const {
  return successors_.size();
}
inline void Road::clear_successors() {
  successors_.Clear();
}
inline ::google::protobuf::uint64 Road::successors(int index) const {
  // @@protoc_insertion_point(field_get:hdmap_proto.Road.successors)
  return successors_.Get(index);
}
inline void Road::set_successors(int index, ::google::protobuf::uint64 value) {
  successors_.Set(index, value);
  // @@protoc_insertion_point(field_set:hdmap_proto.Road.successors)
}
inline void Road::add_successors(::google::protobuf::uint64 value) {
  successors_.Add(value);
  // @@protoc_insertion_point(field_add:hdmap_proto.Road.successors)
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::uint64 >&
Road::successors() const {
  // @@protoc_insertion_point(field_list:hdmap_proto.Road.successors)
  return successors_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::uint64 >*
Road::mutable_successors() {
  // @@protoc_insertion_point(field_mutable_list:hdmap_proto.Road.successors)
  return &successors_;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace hdmap_proto

#ifndef SWIG
namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::hdmap_proto::Road_RoadType> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::hdmap_proto::Road_RoadType>() {
  return ::hdmap_proto::Road_RoadType_descriptor();
}

}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_road_2eproto__INCLUDED
