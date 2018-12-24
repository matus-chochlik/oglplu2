//  File implement/oalplus/enum/value_defs_alc.inl
//
//  Automatically generated file, DO NOT modify manually.
//  Edit the enumeration source files in 'source/enums/oalplus'
//  or the 'source/enums/make_enum.py' script instead.
//
//  Copyright Matus Chochlik.
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//   http://www.boost.org/LICENSE_1_0.txt
//

namespace oalplus {

#ifdef ALC_FREQUENCY
constexpr const enum_value<ALCenum, mp_list<oalplus::context_attrib>>
  enum_values_alc::frequency;
#endif

#ifdef ALC_INVALID_CONTEXT
constexpr const enum_value<ALCenum, mp_list<oalplus::alc_error_code>>
  enum_values_alc::invalid_context;
#endif

#ifdef ALC_INVALID_DEVICE
constexpr const enum_value<ALCenum, mp_list<oalplus::alc_error_code>>
  enum_values_alc::invalid_device;
#endif

#ifdef ALC_INVALID_ENUM
constexpr const enum_value<ALCenum, mp_list<oalplus::alc_error_code>>
  enum_values_alc::invalid_enum;
#endif

#ifdef ALC_INVALID_VALUE
constexpr const enum_value<ALCenum, mp_list<oalplus::alc_error_code>>
  enum_values_alc::invalid_value;
#endif

#ifdef ALC_MONO_SOURCES
constexpr const enum_value<ALCenum, mp_list<oalplus::context_attrib>>
  enum_values_alc::mono_sources;
#endif

#ifdef ALC_NO_ERROR
constexpr const enum_value<ALCenum, mp_list<oalplus::alc_error_code>>
  enum_values_alc::no_error;
#endif

#ifdef ALC_OUT_OF_MEMORY
constexpr const enum_value<ALCenum, mp_list<oalplus::alc_error_code>>
  enum_values_alc::out_of_memory;
#endif

#ifdef ALC_REFRESH
constexpr const enum_value<ALCenum, mp_list<oalplus::context_attrib>>
  enum_values_alc::refresh;
#endif

#ifdef ALC_STEREO_SOURCES
constexpr const enum_value<ALCenum, mp_list<oalplus::context_attrib>>
  enum_values_alc::stereo_sources;
#endif

#ifdef ALC_SYNC
constexpr const enum_value<ALCenum, mp_list<oalplus::context_attrib>>
  enum_values_alc::sync;
#endif

} // namespace oalplus
