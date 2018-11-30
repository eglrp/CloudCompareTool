// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: geometry.proto

#ifndef PROTOBUF_geometry_2eproto__INCLUDED
#define PROTOBUF_geometry_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2006000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2006000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace hdmap_proto {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_geometry_2eproto();
void protobuf_AssignDesc_geometry_2eproto();
void protobuf_ShutdownFile_geometry_2eproto();

class Vector3d;
class Cylinder;
class Circle;
class CurveLine;
class Polygon;

// ===================================================================

class Vector3d : public ::google::protobuf::Message {
 public:
  Vector3d();
  virtual ~Vector3d();

  Vector3d(const Vector3d& from);

  inline Vector3d& operator=(const Vector3d& from) {
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
  static const Vector3d& default_instance();

  void Swap(Vector3d* other);

  // implements Message ----------------------------------------------

  Vector3d* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Vector3d& from);
  void MergeFrom(const Vector3d& from);
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

  // accessors -------------------------------------------------------

  // required double x = 1;
  inline bool has_x() const;
  inline void clear_x();
  static const int kXFieldNumber = 1;
  inline double x() const;
  inline void set_x(double value);

  // required double y = 2;
  inline bool has_y() const;
  inline void clear_y();
  static const int kYFieldNumber = 2;
  inline double y() const;
  inline void set_y(double value);

  // required double z = 3;
  inline bool has_z() const;
  inline void clear_z();
  static const int kZFieldNumber = 3;
  inline double z() const;
  inline void set_z(double value);

  // @@protoc_insertion_point(class_scope:hdmap_proto.Vector3d)
 private:
  inline void set_has_x();
  inline void clear_has_x();
  inline void set_has_y();
  inline void clear_has_y();
  inline void set_has_z();
  inline void clear_has_z();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  double x_;
  double y_;
  double z_;
  friend void  protobuf_AddDesc_geometry_2eproto();
  friend void protobuf_AssignDesc_geometry_2eproto();
  friend void protobuf_ShutdownFile_geometry_2eproto();

  void InitAsDefaultInstance();
  static Vector3d* default_instance_;
};
// -------------------------------------------------------------------

class Cylinder : public ::google::protobuf::Message {
 public:
  Cylinder();
  virtual ~Cylinder();

  Cylinder(const Cylinder& from);

  inline Cylinder& operator=(const Cylinder& from) {
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
  static const Cylinder& default_instance();

  void Swap(Cylinder* other);

  // implements Message ----------------------------------------------

  Cylinder* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Cylinder& from);
  void MergeFrom(const Cylinder& from);
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

  // accessors -------------------------------------------------------

  // repeated .hdmap_proto.Vector3d points = 1;
  inline int points_size() const;
  inline void clear_points();
  static const int kPointsFieldNumber = 1;
  inline const ::hdmap_proto::Vector3d& points(int index) const;
  inline ::hdmap_proto::Vector3d* mutable_points(int index);
  inline ::hdmap_proto::Vector3d* add_points();
  inline const ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Vector3d >&
      points() const;
  inline ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Vector3d >*
      mutable_points();

  // repeated .hdmap_proto.Vector3d pred_points = 2;
  inline int pred_points_size() const;
  inline void clear_pred_points();
  static const int kPredPointsFieldNumber = 2;
  inline const ::hdmap_proto::Vector3d& pred_points(int index) const;
  inline ::hdmap_proto::Vector3d* mutable_pred_points(int index);
  inline ::hdmap_proto::Vector3d* add_pred_points();
  inline const ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Vector3d >&
      pred_points() const;
  inline ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Vector3d >*
      mutable_pred_points();

  // repeated .hdmap_proto.Vector3d succ_points = 3;
  inline int succ_points_size() const;
  inline void clear_succ_points();
  static const int kSuccPointsFieldNumber = 3;
  inline const ::hdmap_proto::Vector3d& succ_points(int index) const;
  inline ::hdmap_proto::Vector3d* mutable_succ_points(int index);
  inline ::hdmap_proto::Vector3d* add_succ_points();
  inline const ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Vector3d >&
      succ_points() const;
  inline ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Vector3d >*
      mutable_succ_points();

  // optional float radius = 4;
  inline bool has_radius() const;
  inline void clear_radius();
  static const int kRadiusFieldNumber = 4;
  inline float radius() const;
  inline void set_radius(float value);

  // @@protoc_insertion_point(class_scope:hdmap_proto.Cylinder)
 private:
  inline void set_has_radius();
  inline void clear_has_radius();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Vector3d > points_;
  ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Vector3d > pred_points_;
  ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Vector3d > succ_points_;
  float radius_;
  friend void  protobuf_AddDesc_geometry_2eproto();
  friend void protobuf_AssignDesc_geometry_2eproto();
  friend void protobuf_ShutdownFile_geometry_2eproto();

  void InitAsDefaultInstance();
  static Cylinder* default_instance_;
};
// -------------------------------------------------------------------

class Circle : public ::google::protobuf::Message {
 public:
  Circle();
  virtual ~Circle();

  Circle(const Circle& from);

  inline Circle& operator=(const Circle& from) {
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
  static const Circle& default_instance();

  void Swap(Circle* other);

  // implements Message ----------------------------------------------

  Circle* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Circle& from);
  void MergeFrom(const Circle& from);
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

  // accessors -------------------------------------------------------

  // required .hdmap_proto.Vector3d center = 1;
  inline bool has_center() const;
  inline void clear_center();
  static const int kCenterFieldNumber = 1;
  inline const ::hdmap_proto::Vector3d& center() const;
  inline ::hdmap_proto::Vector3d* mutable_center();
  inline ::hdmap_proto::Vector3d* release_center();
  inline void set_allocated_center(::hdmap_proto::Vector3d* center);

  // required .hdmap_proto.Vector3d normal = 2;
  inline bool has_normal() const;
  inline void clear_normal();
  static const int kNormalFieldNumber = 2;
  inline const ::hdmap_proto::Vector3d& normal() const;
  inline ::hdmap_proto::Vector3d* mutable_normal();
  inline ::hdmap_proto::Vector3d* release_normal();
  inline void set_allocated_normal(::hdmap_proto::Vector3d* normal);

  // required float radius = 3;
  inline bool has_radius() const;
  inline void clear_radius();
  static const int kRadiusFieldNumber = 3;
  inline float radius() const;
  inline void set_radius(float value);

  // @@protoc_insertion_point(class_scope:hdmap_proto.Circle)
 private:
  inline void set_has_center();
  inline void clear_has_center();
  inline void set_has_normal();
  inline void clear_has_normal();
  inline void set_has_radius();
  inline void clear_has_radius();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::hdmap_proto::Vector3d* center_;
  ::hdmap_proto::Vector3d* normal_;
  float radius_;
  friend void  protobuf_AddDesc_geometry_2eproto();
  friend void protobuf_AssignDesc_geometry_2eproto();
  friend void protobuf_ShutdownFile_geometry_2eproto();

  void InitAsDefaultInstance();
  static Circle* default_instance_;
};
// -------------------------------------------------------------------

class CurveLine : public ::google::protobuf::Message {
 public:
  CurveLine();
  virtual ~CurveLine();

  CurveLine(const CurveLine& from);

  inline CurveLine& operator=(const CurveLine& from) {
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
  static const CurveLine& default_instance();

  void Swap(CurveLine* other);

  // implements Message ----------------------------------------------

  CurveLine* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const CurveLine& from);
  void MergeFrom(const CurveLine& from);
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

  // accessors -------------------------------------------------------

  // repeated .hdmap_proto.Vector3d points = 1;
  inline int points_size() const;
  inline void clear_points();
  static const int kPointsFieldNumber = 1;
  inline const ::hdmap_proto::Vector3d& points(int index) const;
  inline ::hdmap_proto::Vector3d* mutable_points(int index);
  inline ::hdmap_proto::Vector3d* add_points();
  inline const ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Vector3d >&
      points() const;
  inline ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Vector3d >*
      mutable_points();

  // repeated .hdmap_proto.Vector3d pred_points = 2;
  inline int pred_points_size() const;
  inline void clear_pred_points();
  static const int kPredPointsFieldNumber = 2;
  inline const ::hdmap_proto::Vector3d& pred_points(int index) const;
  inline ::hdmap_proto::Vector3d* mutable_pred_points(int index);
  inline ::hdmap_proto::Vector3d* add_pred_points();
  inline const ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Vector3d >&
      pred_points() const;
  inline ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Vector3d >*
      mutable_pred_points();

  // repeated .hdmap_proto.Vector3d succ_points = 3;
  inline int succ_points_size() const;
  inline void clear_succ_points();
  static const int kSuccPointsFieldNumber = 3;
  inline const ::hdmap_proto::Vector3d& succ_points(int index) const;
  inline ::hdmap_proto::Vector3d* mutable_succ_points(int index);
  inline ::hdmap_proto::Vector3d* add_succ_points();
  inline const ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Vector3d >&
      succ_points() const;
  inline ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Vector3d >*
      mutable_succ_points();

  // optional float width = 4;
  inline bool has_width() const;
  inline void clear_width();
  static const int kWidthFieldNumber = 4;
  inline float width() const;
  inline void set_width(float value);

  // @@protoc_insertion_point(class_scope:hdmap_proto.CurveLine)
 private:
  inline void set_has_width();
  inline void clear_has_width();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Vector3d > points_;
  ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Vector3d > pred_points_;
  ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Vector3d > succ_points_;
  float width_;
  friend void  protobuf_AddDesc_geometry_2eproto();
  friend void protobuf_AssignDesc_geometry_2eproto();
  friend void protobuf_ShutdownFile_geometry_2eproto();

  void InitAsDefaultInstance();
  static CurveLine* default_instance_;
};
// -------------------------------------------------------------------

class Polygon : public ::google::protobuf::Message {
 public:
  Polygon();
  virtual ~Polygon();

  Polygon(const Polygon& from);

  inline Polygon& operator=(const Polygon& from) {
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
  static const Polygon& default_instance();

  void Swap(Polygon* other);

  // implements Message ----------------------------------------------

  Polygon* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Polygon& from);
  void MergeFrom(const Polygon& from);
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

  // accessors -------------------------------------------------------

  // repeated .hdmap_proto.Vector3d points = 1;
  inline int points_size() const;
  inline void clear_points();
  static const int kPointsFieldNumber = 1;
  inline const ::hdmap_proto::Vector3d& points(int index) const;
  inline ::hdmap_proto::Vector3d* mutable_points(int index);
  inline ::hdmap_proto::Vector3d* add_points();
  inline const ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Vector3d >&
      points() const;
  inline ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Vector3d >*
      mutable_points();

  // optional float width = 2;
  inline bool has_width() const;
  inline void clear_width();
  static const int kWidthFieldNumber = 2;
  inline float width() const;
  inline void set_width(float value);

  // @@protoc_insertion_point(class_scope:hdmap_proto.Polygon)
 private:
  inline void set_has_width();
  inline void clear_has_width();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Vector3d > points_;
  float width_;
  friend void  protobuf_AddDesc_geometry_2eproto();
  friend void protobuf_AssignDesc_geometry_2eproto();
  friend void protobuf_ShutdownFile_geometry_2eproto();

  void InitAsDefaultInstance();
  static Polygon* default_instance_;
};
// ===================================================================


// ===================================================================

// Vector3d

// required double x = 1;
inline bool Vector3d::has_x() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Vector3d::set_has_x() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Vector3d::clear_has_x() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Vector3d::clear_x() {
  x_ = 0;
  clear_has_x();
}
inline double Vector3d::x() const {
  // @@protoc_insertion_point(field_get:hdmap_proto.Vector3d.x)
  return x_;
}
inline void Vector3d::set_x(double value) {
  set_has_x();
  x_ = value;
  // @@protoc_insertion_point(field_set:hdmap_proto.Vector3d.x)
}

// required double y = 2;
inline bool Vector3d::has_y() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Vector3d::set_has_y() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Vector3d::clear_has_y() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Vector3d::clear_y() {
  y_ = 0;
  clear_has_y();
}
inline double Vector3d::y() const {
  // @@protoc_insertion_point(field_get:hdmap_proto.Vector3d.y)
  return y_;
}
inline void Vector3d::set_y(double value) {
  set_has_y();
  y_ = value;
  // @@protoc_insertion_point(field_set:hdmap_proto.Vector3d.y)
}

// required double z = 3;
inline bool Vector3d::has_z() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Vector3d::set_has_z() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Vector3d::clear_has_z() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Vector3d::clear_z() {
  z_ = 0;
  clear_has_z();
}
inline double Vector3d::z() const {
  // @@protoc_insertion_point(field_get:hdmap_proto.Vector3d.z)
  return z_;
}
inline void Vector3d::set_z(double value) {
  set_has_z();
  z_ = value;
  // @@protoc_insertion_point(field_set:hdmap_proto.Vector3d.z)
}

// -------------------------------------------------------------------

// Cylinder

// repeated .hdmap_proto.Vector3d points = 1;
inline int Cylinder::points_size() const {
  return points_.size();
}
inline void Cylinder::clear_points() {
  points_.Clear();
}
inline const ::hdmap_proto::Vector3d& Cylinder::points(int index) const {
  // @@protoc_insertion_point(field_get:hdmap_proto.Cylinder.points)
  return points_.Get(index);
}
inline ::hdmap_proto::Vector3d* Cylinder::mutable_points(int index) {
  // @@protoc_insertion_point(field_mutable:hdmap_proto.Cylinder.points)
  return points_.Mutable(index);
}
inline ::hdmap_proto::Vector3d* Cylinder::add_points() {
  // @@protoc_insertion_point(field_add:hdmap_proto.Cylinder.points)
  return points_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Vector3d >&
Cylinder::points() const {
  // @@protoc_insertion_point(field_list:hdmap_proto.Cylinder.points)
  return points_;
}
inline ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Vector3d >*
Cylinder::mutable_points() {
  // @@protoc_insertion_point(field_mutable_list:hdmap_proto.Cylinder.points)
  return &points_;
}

// repeated .hdmap_proto.Vector3d pred_points = 2;
inline int Cylinder::pred_points_size() const {
  return pred_points_.size();
}
inline void Cylinder::clear_pred_points() {
  pred_points_.Clear();
}
inline const ::hdmap_proto::Vector3d& Cylinder::pred_points(int index) const {
  // @@protoc_insertion_point(field_get:hdmap_proto.Cylinder.pred_points)
  return pred_points_.Get(index);
}
inline ::hdmap_proto::Vector3d* Cylinder::mutable_pred_points(int index) {
  // @@protoc_insertion_point(field_mutable:hdmap_proto.Cylinder.pred_points)
  return pred_points_.Mutable(index);
}
inline ::hdmap_proto::Vector3d* Cylinder::add_pred_points() {
  // @@protoc_insertion_point(field_add:hdmap_proto.Cylinder.pred_points)
  return pred_points_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Vector3d >&
Cylinder::pred_points() const {
  // @@protoc_insertion_point(field_list:hdmap_proto.Cylinder.pred_points)
  return pred_points_;
}
inline ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Vector3d >*
Cylinder::mutable_pred_points() {
  // @@protoc_insertion_point(field_mutable_list:hdmap_proto.Cylinder.pred_points)
  return &pred_points_;
}

// repeated .hdmap_proto.Vector3d succ_points = 3;
inline int Cylinder::succ_points_size() const {
  return succ_points_.size();
}
inline void Cylinder::clear_succ_points() {
  succ_points_.Clear();
}
inline const ::hdmap_proto::Vector3d& Cylinder::succ_points(int index) const {
  // @@protoc_insertion_point(field_get:hdmap_proto.Cylinder.succ_points)
  return succ_points_.Get(index);
}
inline ::hdmap_proto::Vector3d* Cylinder::mutable_succ_points(int index) {
  // @@protoc_insertion_point(field_mutable:hdmap_proto.Cylinder.succ_points)
  return succ_points_.Mutable(index);
}
inline ::hdmap_proto::Vector3d* Cylinder::add_succ_points() {
  // @@protoc_insertion_point(field_add:hdmap_proto.Cylinder.succ_points)
  return succ_points_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Vector3d >&
Cylinder::succ_points() const {
  // @@protoc_insertion_point(field_list:hdmap_proto.Cylinder.succ_points)
  return succ_points_;
}
inline ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Vector3d >*
Cylinder::mutable_succ_points() {
  // @@protoc_insertion_point(field_mutable_list:hdmap_proto.Cylinder.succ_points)
  return &succ_points_;
}

// optional float radius = 4;
inline bool Cylinder::has_radius() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void Cylinder::set_has_radius() {
  _has_bits_[0] |= 0x00000008u;
}
inline void Cylinder::clear_has_radius() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void Cylinder::clear_radius() {
  radius_ = 0;
  clear_has_radius();
}
inline float Cylinder::radius() const {
  // @@protoc_insertion_point(field_get:hdmap_proto.Cylinder.radius)
  return radius_;
}
inline void Cylinder::set_radius(float value) {
  set_has_radius();
  radius_ = value;
  // @@protoc_insertion_point(field_set:hdmap_proto.Cylinder.radius)
}

// -------------------------------------------------------------------

// Circle

// required .hdmap_proto.Vector3d center = 1;
inline bool Circle::has_center() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Circle::set_has_center() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Circle::clear_has_center() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Circle::clear_center() {
  if (center_ != NULL) center_->::hdmap_proto::Vector3d::Clear();
  clear_has_center();
}
inline const ::hdmap_proto::Vector3d& Circle::center() const {
  // @@protoc_insertion_point(field_get:hdmap_proto.Circle.center)
  return center_ != NULL ? *center_ : *default_instance_->center_;
}
inline ::hdmap_proto::Vector3d* Circle::mutable_center() {
  set_has_center();
  if (center_ == NULL) center_ = new ::hdmap_proto::Vector3d;
  // @@protoc_insertion_point(field_mutable:hdmap_proto.Circle.center)
  return center_;
}
inline ::hdmap_proto::Vector3d* Circle::release_center() {
  clear_has_center();
  ::hdmap_proto::Vector3d* temp = center_;
  center_ = NULL;
  return temp;
}
inline void Circle::set_allocated_center(::hdmap_proto::Vector3d* center) {
  delete center_;
  center_ = center;
  if (center) {
    set_has_center();
  } else {
    clear_has_center();
  }
  // @@protoc_insertion_point(field_set_allocated:hdmap_proto.Circle.center)
}

// required .hdmap_proto.Vector3d normal = 2;
inline bool Circle::has_normal() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Circle::set_has_normal() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Circle::clear_has_normal() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Circle::clear_normal() {
  if (normal_ != NULL) normal_->::hdmap_proto::Vector3d::Clear();
  clear_has_normal();
}
inline const ::hdmap_proto::Vector3d& Circle::normal() const {
  // @@protoc_insertion_point(field_get:hdmap_proto.Circle.normal)
  return normal_ != NULL ? *normal_ : *default_instance_->normal_;
}
inline ::hdmap_proto::Vector3d* Circle::mutable_normal() {
  set_has_normal();
  if (normal_ == NULL) normal_ = new ::hdmap_proto::Vector3d;
  // @@protoc_insertion_point(field_mutable:hdmap_proto.Circle.normal)
  return normal_;
}
inline ::hdmap_proto::Vector3d* Circle::release_normal() {
  clear_has_normal();
  ::hdmap_proto::Vector3d* temp = normal_;
  normal_ = NULL;
  return temp;
}
inline void Circle::set_allocated_normal(::hdmap_proto::Vector3d* normal) {
  delete normal_;
  normal_ = normal;
  if (normal) {
    set_has_normal();
  } else {
    clear_has_normal();
  }
  // @@protoc_insertion_point(field_set_allocated:hdmap_proto.Circle.normal)
}

// required float radius = 3;
inline bool Circle::has_radius() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Circle::set_has_radius() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Circle::clear_has_radius() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Circle::clear_radius() {
  radius_ = 0;
  clear_has_radius();
}
inline float Circle::radius() const {
  // @@protoc_insertion_point(field_get:hdmap_proto.Circle.radius)
  return radius_;
}
inline void Circle::set_radius(float value) {
  set_has_radius();
  radius_ = value;
  // @@protoc_insertion_point(field_set:hdmap_proto.Circle.radius)
}

// -------------------------------------------------------------------

// CurveLine

// repeated .hdmap_proto.Vector3d points = 1;
inline int CurveLine::points_size() const {
  return points_.size();
}
inline void CurveLine::clear_points() {
  points_.Clear();
}
inline const ::hdmap_proto::Vector3d& CurveLine::points(int index) const {
  // @@protoc_insertion_point(field_get:hdmap_proto.CurveLine.points)
  return points_.Get(index);
}
inline ::hdmap_proto::Vector3d* CurveLine::mutable_points(int index) {
  // @@protoc_insertion_point(field_mutable:hdmap_proto.CurveLine.points)
  return points_.Mutable(index);
}
inline ::hdmap_proto::Vector3d* CurveLine::add_points() {
  // @@protoc_insertion_point(field_add:hdmap_proto.CurveLine.points)
  return points_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Vector3d >&
CurveLine::points() const {
  // @@protoc_insertion_point(field_list:hdmap_proto.CurveLine.points)
  return points_;
}
inline ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Vector3d >*
CurveLine::mutable_points() {
  // @@protoc_insertion_point(field_mutable_list:hdmap_proto.CurveLine.points)
  return &points_;
}

// repeated .hdmap_proto.Vector3d pred_points = 2;
inline int CurveLine::pred_points_size() const {
  return pred_points_.size();
}
inline void CurveLine::clear_pred_points() {
  pred_points_.Clear();
}
inline const ::hdmap_proto::Vector3d& CurveLine::pred_points(int index) const {
  // @@protoc_insertion_point(field_get:hdmap_proto.CurveLine.pred_points)
  return pred_points_.Get(index);
}
inline ::hdmap_proto::Vector3d* CurveLine::mutable_pred_points(int index) {
  // @@protoc_insertion_point(field_mutable:hdmap_proto.CurveLine.pred_points)
  return pred_points_.Mutable(index);
}
inline ::hdmap_proto::Vector3d* CurveLine::add_pred_points() {
  // @@protoc_insertion_point(field_add:hdmap_proto.CurveLine.pred_points)
  return pred_points_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Vector3d >&
CurveLine::pred_points() const {
  // @@protoc_insertion_point(field_list:hdmap_proto.CurveLine.pred_points)
  return pred_points_;
}
inline ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Vector3d >*
CurveLine::mutable_pred_points() {
  // @@protoc_insertion_point(field_mutable_list:hdmap_proto.CurveLine.pred_points)
  return &pred_points_;
}

// repeated .hdmap_proto.Vector3d succ_points = 3;
inline int CurveLine::succ_points_size() const {
  return succ_points_.size();
}
inline void CurveLine::clear_succ_points() {
  succ_points_.Clear();
}
inline const ::hdmap_proto::Vector3d& CurveLine::succ_points(int index) const {
  // @@protoc_insertion_point(field_get:hdmap_proto.CurveLine.succ_points)
  return succ_points_.Get(index);
}
inline ::hdmap_proto::Vector3d* CurveLine::mutable_succ_points(int index) {
  // @@protoc_insertion_point(field_mutable:hdmap_proto.CurveLine.succ_points)
  return succ_points_.Mutable(index);
}
inline ::hdmap_proto::Vector3d* CurveLine::add_succ_points() {
  // @@protoc_insertion_point(field_add:hdmap_proto.CurveLine.succ_points)
  return succ_points_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Vector3d >&
CurveLine::succ_points() const {
  // @@protoc_insertion_point(field_list:hdmap_proto.CurveLine.succ_points)
  return succ_points_;
}
inline ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Vector3d >*
CurveLine::mutable_succ_points() {
  // @@protoc_insertion_point(field_mutable_list:hdmap_proto.CurveLine.succ_points)
  return &succ_points_;
}

// optional float width = 4;
inline bool CurveLine::has_width() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void CurveLine::set_has_width() {
  _has_bits_[0] |= 0x00000008u;
}
inline void CurveLine::clear_has_width() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void CurveLine::clear_width() {
  width_ = 0;
  clear_has_width();
}
inline float CurveLine::width() const {
  // @@protoc_insertion_point(field_get:hdmap_proto.CurveLine.width)
  return width_;
}
inline void CurveLine::set_width(float value) {
  set_has_width();
  width_ = value;
  // @@protoc_insertion_point(field_set:hdmap_proto.CurveLine.width)
}

// -------------------------------------------------------------------

// Polygon

// repeated .hdmap_proto.Vector3d points = 1;
inline int Polygon::points_size() const {
  return points_.size();
}
inline void Polygon::clear_points() {
  points_.Clear();
}
inline const ::hdmap_proto::Vector3d& Polygon::points(int index) const {
  // @@protoc_insertion_point(field_get:hdmap_proto.Polygon.points)
  return points_.Get(index);
}
inline ::hdmap_proto::Vector3d* Polygon::mutable_points(int index) {
  // @@protoc_insertion_point(field_mutable:hdmap_proto.Polygon.points)
  return points_.Mutable(index);
}
inline ::hdmap_proto::Vector3d* Polygon::add_points() {
  // @@protoc_insertion_point(field_add:hdmap_proto.Polygon.points)
  return points_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Vector3d >&
Polygon::points() const {
  // @@protoc_insertion_point(field_list:hdmap_proto.Polygon.points)
  return points_;
}
inline ::google::protobuf::RepeatedPtrField< ::hdmap_proto::Vector3d >*
Polygon::mutable_points() {
  // @@protoc_insertion_point(field_mutable_list:hdmap_proto.Polygon.points)
  return &points_;
}

// optional float width = 2;
inline bool Polygon::has_width() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Polygon::set_has_width() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Polygon::clear_has_width() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Polygon::clear_width() {
  width_ = 0;
  clear_has_width();
}
inline float Polygon::width() const {
  // @@protoc_insertion_point(field_get:hdmap_proto.Polygon.width)
  return width_;
}
inline void Polygon::set_width(float value) {
  set_has_width();
  width_ = value;
  // @@protoc_insertion_point(field_set:hdmap_proto.Polygon.width)
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace hdmap_proto

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_geometry_2eproto__INCLUDED
