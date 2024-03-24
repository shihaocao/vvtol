// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: include/protos/state_field_registry.proto

#ifndef PROTOBUF_INCLUDED_include_2fprotos_2fstate_5ffield_5fregistry_2eproto
#define PROTOBUF_INCLUDED_include_2fprotos_2fstate_5ffield_5fregistry_2eproto

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3006001
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_include_2fprotos_2fstate_5ffield_5fregistry_2eproto 

namespace protobuf_include_2fprotos_2fstate_5ffield_5fregistry_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[3];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_include_2fprotos_2fstate_5ffield_5fregistry_2eproto
class StateFieldRegistry;
class StateFieldRegistryDefaultTypeInternal;
extern StateFieldRegistryDefaultTypeInternal _StateFieldRegistry_default_instance_;
class Vector3f;
class Vector3fDefaultTypeInternal;
extern Vector3fDefaultTypeInternal _Vector3f_default_instance_;
class Vector4f;
class Vector4fDefaultTypeInternal;
extern Vector4fDefaultTypeInternal _Vector4f_default_instance_;
namespace google {
namespace protobuf {
template<> ::StateFieldRegistry* Arena::CreateMaybeMessage<::StateFieldRegistry>(Arena*);
template<> ::Vector3f* Arena::CreateMaybeMessage<::Vector3f>(Arena*);
template<> ::Vector4f* Arena::CreateMaybeMessage<::Vector4f>(Arena*);
}  // namespace protobuf
}  // namespace google

enum MainControlState {
  MC_EMPTY = 0,
  MainControlState_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  MainControlState_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool MainControlState_IsValid(int value);
const MainControlState MainControlState_MIN = MC_EMPTY;
const MainControlState MainControlState_MAX = MC_EMPTY;
const int MainControlState_ARRAYSIZE = MainControlState_MAX + 1;

const ::google::protobuf::EnumDescriptor* MainControlState_descriptor();
inline const ::std::string& MainControlState_Name(MainControlState value) {
  return ::google::protobuf::internal::NameOfEnum(
    MainControlState_descriptor(), value);
}
inline bool MainControlState_Parse(
    const ::std::string& name, MainControlState* value) {
  return ::google::protobuf::internal::ParseNamedEnum<MainControlState>(
    MainControlState_descriptor(), name, value);
}
enum GncControlState {
  GNC_EMPTY = 0,
  GncControlState_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  GncControlState_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool GncControlState_IsValid(int value);
const GncControlState GncControlState_MIN = GNC_EMPTY;
const GncControlState GncControlState_MAX = GNC_EMPTY;
const int GncControlState_ARRAYSIZE = GncControlState_MAX + 1;

const ::google::protobuf::EnumDescriptor* GncControlState_descriptor();
inline const ::std::string& GncControlState_Name(GncControlState value) {
  return ::google::protobuf::internal::NameOfEnum(
    GncControlState_descriptor(), value);
}
inline bool GncControlState_Parse(
    const ::std::string& name, GncControlState* value) {
  return ::google::protobuf::internal::ParseNamedEnum<GncControlState>(
    GncControlState_descriptor(), name, value);
}
// ===================================================================

class Vector3f : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Vector3f) */ {
 public:
  Vector3f();
  virtual ~Vector3f();

  Vector3f(const Vector3f& from);

  inline Vector3f& operator=(const Vector3f& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Vector3f(Vector3f&& from) noexcept
    : Vector3f() {
    *this = ::std::move(from);
  }

  inline Vector3f& operator=(Vector3f&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const Vector3f& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Vector3f* internal_default_instance() {
    return reinterpret_cast<const Vector3f*>(
               &_Vector3f_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(Vector3f* other);
  friend void swap(Vector3f& a, Vector3f& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Vector3f* New() const final {
    return CreateMaybeMessage<Vector3f>(NULL);
  }

  Vector3f* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<Vector3f>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const Vector3f& from);
  void MergeFrom(const Vector3f& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Vector3f* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated float elements = 1 [packed = true];
  int elements_size() const;
  void clear_elements();
  static const int kElementsFieldNumber = 1;
  float elements(int index) const;
  void set_elements(int index, float value);
  void add_elements(float value);
  const ::google::protobuf::RepeatedField< float >&
      elements() const;
  ::google::protobuf::RepeatedField< float >*
      mutable_elements();

  // @@protoc_insertion_point(class_scope:Vector3f)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedField< float > elements_;
  mutable int _elements_cached_byte_size_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_include_2fprotos_2fstate_5ffield_5fregistry_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class Vector4f : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Vector4f) */ {
 public:
  Vector4f();
  virtual ~Vector4f();

  Vector4f(const Vector4f& from);

  inline Vector4f& operator=(const Vector4f& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Vector4f(Vector4f&& from) noexcept
    : Vector4f() {
    *this = ::std::move(from);
  }

  inline Vector4f& operator=(Vector4f&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const Vector4f& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Vector4f* internal_default_instance() {
    return reinterpret_cast<const Vector4f*>(
               &_Vector4f_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(Vector4f* other);
  friend void swap(Vector4f& a, Vector4f& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Vector4f* New() const final {
    return CreateMaybeMessage<Vector4f>(NULL);
  }

  Vector4f* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<Vector4f>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const Vector4f& from);
  void MergeFrom(const Vector4f& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Vector4f* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated float elements = 1 [packed = true];
  int elements_size() const;
  void clear_elements();
  static const int kElementsFieldNumber = 1;
  float elements(int index) const;
  void set_elements(int index, float value);
  void add_elements(float value);
  const ::google::protobuf::RepeatedField< float >&
      elements() const;
  ::google::protobuf::RepeatedField< float >*
      mutable_elements();

  // @@protoc_insertion_point(class_scope:Vector4f)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedField< float > elements_;
  mutable int _elements_cached_byte_size_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_include_2fprotos_2fstate_5ffield_5fregistry_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class StateFieldRegistry : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:StateFieldRegistry) */ {
 public:
  StateFieldRegistry();
  virtual ~StateFieldRegistry();

  StateFieldRegistry(const StateFieldRegistry& from);

  inline StateFieldRegistry& operator=(const StateFieldRegistry& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  StateFieldRegistry(StateFieldRegistry&& from) noexcept
    : StateFieldRegistry() {
    *this = ::std::move(from);
  }

  inline StateFieldRegistry& operator=(StateFieldRegistry&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const StateFieldRegistry& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const StateFieldRegistry* internal_default_instance() {
    return reinterpret_cast<const StateFieldRegistry*>(
               &_StateFieldRegistry_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  void Swap(StateFieldRegistry* other);
  friend void swap(StateFieldRegistry& a, StateFieldRegistry& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline StateFieldRegistry* New() const final {
    return CreateMaybeMessage<StateFieldRegistry>(NULL);
  }

  StateFieldRegistry* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<StateFieldRegistry>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const StateFieldRegistry& from);
  void MergeFrom(const StateFieldRegistry& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(StateFieldRegistry* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // .Vector3f imu_linear_acc_vec_f = 10;
  bool has_imu_linear_acc_vec_f() const;
  void clear_imu_linear_acc_vec_f();
  static const int kImuLinearAccVecFFieldNumber = 10;
  private:
  const ::Vector3f& _internal_imu_linear_acc_vec_f() const;
  public:
  const ::Vector3f& imu_linear_acc_vec_f() const;
  ::Vector3f* release_imu_linear_acc_vec_f();
  ::Vector3f* mutable_imu_linear_acc_vec_f();
  void set_allocated_imu_linear_acc_vec_f(::Vector3f* imu_linear_acc_vec_f);

  // .Vector3f imu_acc_vec_f = 11;
  bool has_imu_acc_vec_f() const;
  void clear_imu_acc_vec_f();
  static const int kImuAccVecFFieldNumber = 11;
  private:
  const ::Vector3f& _internal_imu_acc_vec_f() const;
  public:
  const ::Vector3f& imu_acc_vec_f() const;
  ::Vector3f* release_imu_acc_vec_f();
  ::Vector3f* mutable_imu_acc_vec_f();
  void set_allocated_imu_acc_vec_f(::Vector3f* imu_acc_vec_f);

  // .Vector3f imu_gyr_vec = 12;
  bool has_imu_gyr_vec() const;
  void clear_imu_gyr_vec();
  static const int kImuGyrVecFieldNumber = 12;
  private:
  const ::Vector3f& _internal_imu_gyr_vec() const;
  public:
  const ::Vector3f& imu_gyr_vec() const;
  ::Vector3f* release_imu_gyr_vec();
  ::Vector3f* mutable_imu_gyr_vec();
  void set_allocated_imu_gyr_vec(::Vector3f* imu_gyr_vec);

  // .Vector4f imu_euler_vec = 13;
  bool has_imu_euler_vec() const;
  void clear_imu_euler_vec();
  static const int kImuEulerVecFieldNumber = 13;
  private:
  const ::Vector4f& _internal_imu_euler_vec() const;
  public:
  const ::Vector4f& imu_euler_vec() const;
  ::Vector4f* release_imu_euler_vec();
  ::Vector4f* mutable_imu_euler_vec();
  void set_allocated_imu_euler_vec(::Vector4f* imu_euler_vec);

  // .Vector4f imu_quat = 14;
  bool has_imu_quat() const;
  void clear_imu_quat();
  static const int kImuQuatFieldNumber = 14;
  private:
  const ::Vector4f& _internal_imu_quat() const;
  public:
  const ::Vector4f& imu_quat() const;
  ::Vector4f* release_imu_quat();
  ::Vector4f* mutable_imu_quat();
  void set_allocated_imu_quat(::Vector4f* imu_quat);

  // float time_t_average_cycle_time_us = 1;
  void clear_time_t_average_cycle_time_us();
  static const int kTimeTAverageCycleTimeUsFieldNumber = 1;
  float time_t_average_cycle_time_us() const;
  void set_time_t_average_cycle_time_us(float value);

  // int32 time_t_control_cycle_limit_us = 2;
  void clear_time_t_control_cycle_limit_us();
  static const int kTimeTControlCycleLimitUsFieldNumber = 2;
  ::google::protobuf::int32 time_t_control_cycle_limit_us() const;
  void set_time_t_control_cycle_limit_us(::google::protobuf::int32 value);

  // uint64 last_transition_ccno = 4;
  void clear_last_transition_ccno();
  static const int kLastTransitionCcnoFieldNumber = 4;
  ::google::protobuf::uint64 last_transition_ccno() const;
  void set_last_transition_ccno(::google::protobuf::uint64 value);

  // uint32 time_t_last_cycle_end_us = 3;
  void clear_time_t_last_cycle_end_us();
  static const int kTimeTLastCycleEndUsFieldNumber = 3;
  ::google::protobuf::uint32 time_t_last_cycle_end_us() const;
  void set_time_t_last_cycle_end_us(::google::protobuf::uint32 value);

  // .MainControlState mc_state = 6;
  void clear_mc_state();
  static const int kMcStateFieldNumber = 6;
  ::MainControlState mc_state() const;
  void set_mc_state(::MainControlState value);

  // uint64 mcl_control_cycle_num = 5;
  void clear_mcl_control_cycle_num();
  static const int kMclControlCycleNumFieldNumber = 5;
  ::google::protobuf::uint64 mcl_control_cycle_num() const;
  void set_mcl_control_cycle_num(::google::protobuf::uint64 value);

  // .MainControlState target_mc_state = 7;
  void clear_target_mc_state();
  static const int kTargetMcStateFieldNumber = 7;
  ::MainControlState target_mc_state() const;
  void set_target_mc_state(::MainControlState value);

  // .GncControlState gnc_state = 8;
  void clear_gnc_state();
  static const int kGncStateFieldNumber = 8;
  ::GncControlState gnc_state() const;
  void set_gnc_state(::GncControlState value);

  // .GncControlState target_gnc_state = 9;
  void clear_target_gnc_state();
  static const int kTargetGncStateFieldNumber = 9;
  ::GncControlState target_gnc_state() const;
  void set_target_gnc_state(::GncControlState value);

  // @@protoc_insertion_point(class_scope:StateFieldRegistry)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::Vector3f* imu_linear_acc_vec_f_;
  ::Vector3f* imu_acc_vec_f_;
  ::Vector3f* imu_gyr_vec_;
  ::Vector4f* imu_euler_vec_;
  ::Vector4f* imu_quat_;
  float time_t_average_cycle_time_us_;
  ::google::protobuf::int32 time_t_control_cycle_limit_us_;
  ::google::protobuf::uint64 last_transition_ccno_;
  ::google::protobuf::uint32 time_t_last_cycle_end_us_;
  int mc_state_;
  ::google::protobuf::uint64 mcl_control_cycle_num_;
  int target_mc_state_;
  int gnc_state_;
  int target_gnc_state_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_include_2fprotos_2fstate_5ffield_5fregistry_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Vector3f

// repeated float elements = 1 [packed = true];
inline int Vector3f::elements_size() const {
  return elements_.size();
}
inline void Vector3f::clear_elements() {
  elements_.Clear();
}
inline float Vector3f::elements(int index) const {
  // @@protoc_insertion_point(field_get:Vector3f.elements)
  return elements_.Get(index);
}
inline void Vector3f::set_elements(int index, float value) {
  elements_.Set(index, value);
  // @@protoc_insertion_point(field_set:Vector3f.elements)
}
inline void Vector3f::add_elements(float value) {
  elements_.Add(value);
  // @@protoc_insertion_point(field_add:Vector3f.elements)
}
inline const ::google::protobuf::RepeatedField< float >&
Vector3f::elements() const {
  // @@protoc_insertion_point(field_list:Vector3f.elements)
  return elements_;
}
inline ::google::protobuf::RepeatedField< float >*
Vector3f::mutable_elements() {
  // @@protoc_insertion_point(field_mutable_list:Vector3f.elements)
  return &elements_;
}

// -------------------------------------------------------------------

// Vector4f

// repeated float elements = 1 [packed = true];
inline int Vector4f::elements_size() const {
  return elements_.size();
}
inline void Vector4f::clear_elements() {
  elements_.Clear();
}
inline float Vector4f::elements(int index) const {
  // @@protoc_insertion_point(field_get:Vector4f.elements)
  return elements_.Get(index);
}
inline void Vector4f::set_elements(int index, float value) {
  elements_.Set(index, value);
  // @@protoc_insertion_point(field_set:Vector4f.elements)
}
inline void Vector4f::add_elements(float value) {
  elements_.Add(value);
  // @@protoc_insertion_point(field_add:Vector4f.elements)
}
inline const ::google::protobuf::RepeatedField< float >&
Vector4f::elements() const {
  // @@protoc_insertion_point(field_list:Vector4f.elements)
  return elements_;
}
inline ::google::protobuf::RepeatedField< float >*
Vector4f::mutable_elements() {
  // @@protoc_insertion_point(field_mutable_list:Vector4f.elements)
  return &elements_;
}

// -------------------------------------------------------------------

// StateFieldRegistry

// float time_t_average_cycle_time_us = 1;
inline void StateFieldRegistry::clear_time_t_average_cycle_time_us() {
  time_t_average_cycle_time_us_ = 0;
}
inline float StateFieldRegistry::time_t_average_cycle_time_us() const {
  // @@protoc_insertion_point(field_get:StateFieldRegistry.time_t_average_cycle_time_us)
  return time_t_average_cycle_time_us_;
}
inline void StateFieldRegistry::set_time_t_average_cycle_time_us(float value) {
  
  time_t_average_cycle_time_us_ = value;
  // @@protoc_insertion_point(field_set:StateFieldRegistry.time_t_average_cycle_time_us)
}

// int32 time_t_control_cycle_limit_us = 2;
inline void StateFieldRegistry::clear_time_t_control_cycle_limit_us() {
  time_t_control_cycle_limit_us_ = 0;
}
inline ::google::protobuf::int32 StateFieldRegistry::time_t_control_cycle_limit_us() const {
  // @@protoc_insertion_point(field_get:StateFieldRegistry.time_t_control_cycle_limit_us)
  return time_t_control_cycle_limit_us_;
}
inline void StateFieldRegistry::set_time_t_control_cycle_limit_us(::google::protobuf::int32 value) {
  
  time_t_control_cycle_limit_us_ = value;
  // @@protoc_insertion_point(field_set:StateFieldRegistry.time_t_control_cycle_limit_us)
}

// uint32 time_t_last_cycle_end_us = 3;
inline void StateFieldRegistry::clear_time_t_last_cycle_end_us() {
  time_t_last_cycle_end_us_ = 0u;
}
inline ::google::protobuf::uint32 StateFieldRegistry::time_t_last_cycle_end_us() const {
  // @@protoc_insertion_point(field_get:StateFieldRegistry.time_t_last_cycle_end_us)
  return time_t_last_cycle_end_us_;
}
inline void StateFieldRegistry::set_time_t_last_cycle_end_us(::google::protobuf::uint32 value) {
  
  time_t_last_cycle_end_us_ = value;
  // @@protoc_insertion_point(field_set:StateFieldRegistry.time_t_last_cycle_end_us)
}

// uint64 last_transition_ccno = 4;
inline void StateFieldRegistry::clear_last_transition_ccno() {
  last_transition_ccno_ = GOOGLE_ULONGLONG(0);
}
inline ::google::protobuf::uint64 StateFieldRegistry::last_transition_ccno() const {
  // @@protoc_insertion_point(field_get:StateFieldRegistry.last_transition_ccno)
  return last_transition_ccno_;
}
inline void StateFieldRegistry::set_last_transition_ccno(::google::protobuf::uint64 value) {
  
  last_transition_ccno_ = value;
  // @@protoc_insertion_point(field_set:StateFieldRegistry.last_transition_ccno)
}

// uint64 mcl_control_cycle_num = 5;
inline void StateFieldRegistry::clear_mcl_control_cycle_num() {
  mcl_control_cycle_num_ = GOOGLE_ULONGLONG(0);
}
inline ::google::protobuf::uint64 StateFieldRegistry::mcl_control_cycle_num() const {
  // @@protoc_insertion_point(field_get:StateFieldRegistry.mcl_control_cycle_num)
  return mcl_control_cycle_num_;
}
inline void StateFieldRegistry::set_mcl_control_cycle_num(::google::protobuf::uint64 value) {
  
  mcl_control_cycle_num_ = value;
  // @@protoc_insertion_point(field_set:StateFieldRegistry.mcl_control_cycle_num)
}

// .MainControlState mc_state = 6;
inline void StateFieldRegistry::clear_mc_state() {
  mc_state_ = 0;
}
inline ::MainControlState StateFieldRegistry::mc_state() const {
  // @@protoc_insertion_point(field_get:StateFieldRegistry.mc_state)
  return static_cast< ::MainControlState >(mc_state_);
}
inline void StateFieldRegistry::set_mc_state(::MainControlState value) {
  
  mc_state_ = value;
  // @@protoc_insertion_point(field_set:StateFieldRegistry.mc_state)
}

// .MainControlState target_mc_state = 7;
inline void StateFieldRegistry::clear_target_mc_state() {
  target_mc_state_ = 0;
}
inline ::MainControlState StateFieldRegistry::target_mc_state() const {
  // @@protoc_insertion_point(field_get:StateFieldRegistry.target_mc_state)
  return static_cast< ::MainControlState >(target_mc_state_);
}
inline void StateFieldRegistry::set_target_mc_state(::MainControlState value) {
  
  target_mc_state_ = value;
  // @@protoc_insertion_point(field_set:StateFieldRegistry.target_mc_state)
}

// .GncControlState gnc_state = 8;
inline void StateFieldRegistry::clear_gnc_state() {
  gnc_state_ = 0;
}
inline ::GncControlState StateFieldRegistry::gnc_state() const {
  // @@protoc_insertion_point(field_get:StateFieldRegistry.gnc_state)
  return static_cast< ::GncControlState >(gnc_state_);
}
inline void StateFieldRegistry::set_gnc_state(::GncControlState value) {
  
  gnc_state_ = value;
  // @@protoc_insertion_point(field_set:StateFieldRegistry.gnc_state)
}

// .GncControlState target_gnc_state = 9;
inline void StateFieldRegistry::clear_target_gnc_state() {
  target_gnc_state_ = 0;
}
inline ::GncControlState StateFieldRegistry::target_gnc_state() const {
  // @@protoc_insertion_point(field_get:StateFieldRegistry.target_gnc_state)
  return static_cast< ::GncControlState >(target_gnc_state_);
}
inline void StateFieldRegistry::set_target_gnc_state(::GncControlState value) {
  
  target_gnc_state_ = value;
  // @@protoc_insertion_point(field_set:StateFieldRegistry.target_gnc_state)
}

// .Vector3f imu_linear_acc_vec_f = 10;
inline bool StateFieldRegistry::has_imu_linear_acc_vec_f() const {
  return this != internal_default_instance() && imu_linear_acc_vec_f_ != NULL;
}
inline void StateFieldRegistry::clear_imu_linear_acc_vec_f() {
  if (GetArenaNoVirtual() == NULL && imu_linear_acc_vec_f_ != NULL) {
    delete imu_linear_acc_vec_f_;
  }
  imu_linear_acc_vec_f_ = NULL;
}
inline const ::Vector3f& StateFieldRegistry::_internal_imu_linear_acc_vec_f() const {
  return *imu_linear_acc_vec_f_;
}
inline const ::Vector3f& StateFieldRegistry::imu_linear_acc_vec_f() const {
  const ::Vector3f* p = imu_linear_acc_vec_f_;
  // @@protoc_insertion_point(field_get:StateFieldRegistry.imu_linear_acc_vec_f)
  return p != NULL ? *p : *reinterpret_cast<const ::Vector3f*>(
      &::_Vector3f_default_instance_);
}
inline ::Vector3f* StateFieldRegistry::release_imu_linear_acc_vec_f() {
  // @@protoc_insertion_point(field_release:StateFieldRegistry.imu_linear_acc_vec_f)
  
  ::Vector3f* temp = imu_linear_acc_vec_f_;
  imu_linear_acc_vec_f_ = NULL;
  return temp;
}
inline ::Vector3f* StateFieldRegistry::mutable_imu_linear_acc_vec_f() {
  
  if (imu_linear_acc_vec_f_ == NULL) {
    auto* p = CreateMaybeMessage<::Vector3f>(GetArenaNoVirtual());
    imu_linear_acc_vec_f_ = p;
  }
  // @@protoc_insertion_point(field_mutable:StateFieldRegistry.imu_linear_acc_vec_f)
  return imu_linear_acc_vec_f_;
}
inline void StateFieldRegistry::set_allocated_imu_linear_acc_vec_f(::Vector3f* imu_linear_acc_vec_f) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete imu_linear_acc_vec_f_;
  }
  if (imu_linear_acc_vec_f) {
    ::google::protobuf::Arena* submessage_arena = NULL;
    if (message_arena != submessage_arena) {
      imu_linear_acc_vec_f = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, imu_linear_acc_vec_f, submessage_arena);
    }
    
  } else {
    
  }
  imu_linear_acc_vec_f_ = imu_linear_acc_vec_f;
  // @@protoc_insertion_point(field_set_allocated:StateFieldRegistry.imu_linear_acc_vec_f)
}

// .Vector3f imu_acc_vec_f = 11;
inline bool StateFieldRegistry::has_imu_acc_vec_f() const {
  return this != internal_default_instance() && imu_acc_vec_f_ != NULL;
}
inline void StateFieldRegistry::clear_imu_acc_vec_f() {
  if (GetArenaNoVirtual() == NULL && imu_acc_vec_f_ != NULL) {
    delete imu_acc_vec_f_;
  }
  imu_acc_vec_f_ = NULL;
}
inline const ::Vector3f& StateFieldRegistry::_internal_imu_acc_vec_f() const {
  return *imu_acc_vec_f_;
}
inline const ::Vector3f& StateFieldRegistry::imu_acc_vec_f() const {
  const ::Vector3f* p = imu_acc_vec_f_;
  // @@protoc_insertion_point(field_get:StateFieldRegistry.imu_acc_vec_f)
  return p != NULL ? *p : *reinterpret_cast<const ::Vector3f*>(
      &::_Vector3f_default_instance_);
}
inline ::Vector3f* StateFieldRegistry::release_imu_acc_vec_f() {
  // @@protoc_insertion_point(field_release:StateFieldRegistry.imu_acc_vec_f)
  
  ::Vector3f* temp = imu_acc_vec_f_;
  imu_acc_vec_f_ = NULL;
  return temp;
}
inline ::Vector3f* StateFieldRegistry::mutable_imu_acc_vec_f() {
  
  if (imu_acc_vec_f_ == NULL) {
    auto* p = CreateMaybeMessage<::Vector3f>(GetArenaNoVirtual());
    imu_acc_vec_f_ = p;
  }
  // @@protoc_insertion_point(field_mutable:StateFieldRegistry.imu_acc_vec_f)
  return imu_acc_vec_f_;
}
inline void StateFieldRegistry::set_allocated_imu_acc_vec_f(::Vector3f* imu_acc_vec_f) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete imu_acc_vec_f_;
  }
  if (imu_acc_vec_f) {
    ::google::protobuf::Arena* submessage_arena = NULL;
    if (message_arena != submessage_arena) {
      imu_acc_vec_f = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, imu_acc_vec_f, submessage_arena);
    }
    
  } else {
    
  }
  imu_acc_vec_f_ = imu_acc_vec_f;
  // @@protoc_insertion_point(field_set_allocated:StateFieldRegistry.imu_acc_vec_f)
}

// .Vector3f imu_gyr_vec = 12;
inline bool StateFieldRegistry::has_imu_gyr_vec() const {
  return this != internal_default_instance() && imu_gyr_vec_ != NULL;
}
inline void StateFieldRegistry::clear_imu_gyr_vec() {
  if (GetArenaNoVirtual() == NULL && imu_gyr_vec_ != NULL) {
    delete imu_gyr_vec_;
  }
  imu_gyr_vec_ = NULL;
}
inline const ::Vector3f& StateFieldRegistry::_internal_imu_gyr_vec() const {
  return *imu_gyr_vec_;
}
inline const ::Vector3f& StateFieldRegistry::imu_gyr_vec() const {
  const ::Vector3f* p = imu_gyr_vec_;
  // @@protoc_insertion_point(field_get:StateFieldRegistry.imu_gyr_vec)
  return p != NULL ? *p : *reinterpret_cast<const ::Vector3f*>(
      &::_Vector3f_default_instance_);
}
inline ::Vector3f* StateFieldRegistry::release_imu_gyr_vec() {
  // @@protoc_insertion_point(field_release:StateFieldRegistry.imu_gyr_vec)
  
  ::Vector3f* temp = imu_gyr_vec_;
  imu_gyr_vec_ = NULL;
  return temp;
}
inline ::Vector3f* StateFieldRegistry::mutable_imu_gyr_vec() {
  
  if (imu_gyr_vec_ == NULL) {
    auto* p = CreateMaybeMessage<::Vector3f>(GetArenaNoVirtual());
    imu_gyr_vec_ = p;
  }
  // @@protoc_insertion_point(field_mutable:StateFieldRegistry.imu_gyr_vec)
  return imu_gyr_vec_;
}
inline void StateFieldRegistry::set_allocated_imu_gyr_vec(::Vector3f* imu_gyr_vec) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete imu_gyr_vec_;
  }
  if (imu_gyr_vec) {
    ::google::protobuf::Arena* submessage_arena = NULL;
    if (message_arena != submessage_arena) {
      imu_gyr_vec = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, imu_gyr_vec, submessage_arena);
    }
    
  } else {
    
  }
  imu_gyr_vec_ = imu_gyr_vec;
  // @@protoc_insertion_point(field_set_allocated:StateFieldRegistry.imu_gyr_vec)
}

// .Vector4f imu_euler_vec = 13;
inline bool StateFieldRegistry::has_imu_euler_vec() const {
  return this != internal_default_instance() && imu_euler_vec_ != NULL;
}
inline void StateFieldRegistry::clear_imu_euler_vec() {
  if (GetArenaNoVirtual() == NULL && imu_euler_vec_ != NULL) {
    delete imu_euler_vec_;
  }
  imu_euler_vec_ = NULL;
}
inline const ::Vector4f& StateFieldRegistry::_internal_imu_euler_vec() const {
  return *imu_euler_vec_;
}
inline const ::Vector4f& StateFieldRegistry::imu_euler_vec() const {
  const ::Vector4f* p = imu_euler_vec_;
  // @@protoc_insertion_point(field_get:StateFieldRegistry.imu_euler_vec)
  return p != NULL ? *p : *reinterpret_cast<const ::Vector4f*>(
      &::_Vector4f_default_instance_);
}
inline ::Vector4f* StateFieldRegistry::release_imu_euler_vec() {
  // @@protoc_insertion_point(field_release:StateFieldRegistry.imu_euler_vec)
  
  ::Vector4f* temp = imu_euler_vec_;
  imu_euler_vec_ = NULL;
  return temp;
}
inline ::Vector4f* StateFieldRegistry::mutable_imu_euler_vec() {
  
  if (imu_euler_vec_ == NULL) {
    auto* p = CreateMaybeMessage<::Vector4f>(GetArenaNoVirtual());
    imu_euler_vec_ = p;
  }
  // @@protoc_insertion_point(field_mutable:StateFieldRegistry.imu_euler_vec)
  return imu_euler_vec_;
}
inline void StateFieldRegistry::set_allocated_imu_euler_vec(::Vector4f* imu_euler_vec) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete imu_euler_vec_;
  }
  if (imu_euler_vec) {
    ::google::protobuf::Arena* submessage_arena = NULL;
    if (message_arena != submessage_arena) {
      imu_euler_vec = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, imu_euler_vec, submessage_arena);
    }
    
  } else {
    
  }
  imu_euler_vec_ = imu_euler_vec;
  // @@protoc_insertion_point(field_set_allocated:StateFieldRegistry.imu_euler_vec)
}

// .Vector4f imu_quat = 14;
inline bool StateFieldRegistry::has_imu_quat() const {
  return this != internal_default_instance() && imu_quat_ != NULL;
}
inline void StateFieldRegistry::clear_imu_quat() {
  if (GetArenaNoVirtual() == NULL && imu_quat_ != NULL) {
    delete imu_quat_;
  }
  imu_quat_ = NULL;
}
inline const ::Vector4f& StateFieldRegistry::_internal_imu_quat() const {
  return *imu_quat_;
}
inline const ::Vector4f& StateFieldRegistry::imu_quat() const {
  const ::Vector4f* p = imu_quat_;
  // @@protoc_insertion_point(field_get:StateFieldRegistry.imu_quat)
  return p != NULL ? *p : *reinterpret_cast<const ::Vector4f*>(
      &::_Vector4f_default_instance_);
}
inline ::Vector4f* StateFieldRegistry::release_imu_quat() {
  // @@protoc_insertion_point(field_release:StateFieldRegistry.imu_quat)
  
  ::Vector4f* temp = imu_quat_;
  imu_quat_ = NULL;
  return temp;
}
inline ::Vector4f* StateFieldRegistry::mutable_imu_quat() {
  
  if (imu_quat_ == NULL) {
    auto* p = CreateMaybeMessage<::Vector4f>(GetArenaNoVirtual());
    imu_quat_ = p;
  }
  // @@protoc_insertion_point(field_mutable:StateFieldRegistry.imu_quat)
  return imu_quat_;
}
inline void StateFieldRegistry::set_allocated_imu_quat(::Vector4f* imu_quat) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete imu_quat_;
  }
  if (imu_quat) {
    ::google::protobuf::Arena* submessage_arena = NULL;
    if (message_arena != submessage_arena) {
      imu_quat = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, imu_quat, submessage_arena);
    }
    
  } else {
    
  }
  imu_quat_ = imu_quat;
  // @@protoc_insertion_point(field_set_allocated:StateFieldRegistry.imu_quat)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::MainControlState> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::MainControlState>() {
  return ::MainControlState_descriptor();
}
template <> struct is_proto_enum< ::GncControlState> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::GncControlState>() {
  return ::GncControlState_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_include_2fprotos_2fstate_5ffield_5fregistry_2eproto