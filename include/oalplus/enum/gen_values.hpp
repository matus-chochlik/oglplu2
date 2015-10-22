//  File include/oalplus/enum/gen_values.hpp
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
#ifndef OALPLUS_AL_GEN_ENUM_VALUES_HPP
#define OALPLUS_AL_GEN_ENUM_VALUES_HPP

#include "gen_types.hpp"
#include "../utils/mp_list.hpp"

namespace oalplus {
struct generated_enum_values {

#ifdef AL_EXPONENT_DISTANCE
static constexpr const enum_value<
	ALenum,
	AL_EXPONENT_DISTANCE,
	mp_list<oalplus::distance_model>
> exponent_distance = {};
#endif

#ifdef AL_EXPONENT_DISTANCE_CLAMPED
static constexpr const enum_value<
	ALenum,
	AL_EXPONENT_DISTANCE_CLAMPED,
	mp_list<oalplus::distance_model>
> exponent_distance_clamped = {};
#endif

#ifdef AL_EXTENSIONS
static constexpr const enum_value<
	ALenum,
	AL_EXTENSIONS,
	mp_list<oalplus::string_query>
> extensions = {};
#endif

#ifdef AL_FORMAT_MONO16
static constexpr const enum_value<
	ALenum,
	AL_FORMAT_MONO16,
	mp_list<oalplus::data_format>
> format_mono16 = {};
#endif

#ifdef AL_FORMAT_MONO8
static constexpr const enum_value<
	ALenum,
	AL_FORMAT_MONO8,
	mp_list<oalplus::data_format>
> format_mono8 = {};
#endif

#ifdef AL_FORMAT_STEREO16
static constexpr const enum_value<
	ALenum,
	AL_FORMAT_STEREO16,
	mp_list<oalplus::data_format>
> format_stereo16 = {};
#endif

#ifdef AL_FORMAT_STEREO8
static constexpr const enum_value<
	ALenum,
	AL_FORMAT_STEREO8,
	mp_list<oalplus::data_format>
> format_stereo8 = {};
#endif

#ifdef AL_INITIAL
static constexpr const enum_value<
	ALenum,
	AL_INITIAL,
	mp_list<oalplus::source_state>
> initial = {};
#endif

#ifdef AL_INVALID_ENUM
static constexpr const enum_value<
	ALenum,
	AL_INVALID_ENUM,
	mp_list<oalplus::al_error_code>
> invalid_enum = {};
#endif

#ifdef AL_INVALID_NAME
static constexpr const enum_value<
	ALenum,
	AL_INVALID_NAME,
	mp_list<oalplus::al_error_code>
> invalid_name = {};
#endif

#ifdef AL_INVALID_OPERATION
static constexpr const enum_value<
	ALenum,
	AL_INVALID_OPERATION,
	mp_list<oalplus::al_error_code>
> invalid_operation = {};
#endif

#ifdef AL_INVALID_VALUE
static constexpr const enum_value<
	ALenum,
	AL_INVALID_VALUE,
	mp_list<oalplus::al_error_code>
> invalid_value = {};
#endif

#ifdef AL_INVERSE_DISTANCE
static constexpr const enum_value<
	ALenum,
	AL_INVERSE_DISTANCE,
	mp_list<oalplus::distance_model>
> inverse_distance = {};
#endif

#ifdef AL_INVERSE_DISTANCE_CLAMPED
static constexpr const enum_value<
	ALenum,
	AL_INVERSE_DISTANCE_CLAMPED,
	mp_list<oalplus::distance_model>
> inverse_distance_clamped = {};
#endif

#ifdef AL_LINEAR_DISTANCE
static constexpr const enum_value<
	ALenum,
	AL_LINEAR_DISTANCE,
	mp_list<oalplus::distance_model>
> linear_distance = {};
#endif

#ifdef AL_LINEAR_DISTANCE_CLAMPED
static constexpr const enum_value<
	ALenum,
	AL_LINEAR_DISTANCE_CLAMPED,
	mp_list<oalplus::distance_model>
> linear_distance_clamped = {};
#endif

#ifdef AL_NO_ERROR
static constexpr const enum_value<
	ALenum,
	AL_NO_ERROR,
	mp_list<oalplus::al_error_code>
> no_error = {};
#endif

#ifdef AL_NONE
static constexpr const enum_value<
	ALenum,
	AL_NONE,
	mp_list<oalplus::distance_model>
> none = {};
#endif

#ifdef AL_OUT_OF_MEMORY
static constexpr const enum_value<
	ALenum,
	AL_OUT_OF_MEMORY,
	mp_list<oalplus::al_error_code>
> out_of_memory = {};
#endif

#ifdef AL_PAUSED
static constexpr const enum_value<
	ALenum,
	AL_PAUSED,
	mp_list<oalplus::source_state>
> paused = {};
#endif

#ifdef AL_PLAYING
static constexpr const enum_value<
	ALenum,
	AL_PLAYING,
	mp_list<oalplus::source_state>
> playing = {};
#endif

#ifdef AL_RENDERER
static constexpr const enum_value<
	ALenum,
	AL_RENDERER,
	mp_list<oalplus::string_query>
> renderer = {};
#endif

#ifdef AL_STATIC
static constexpr const enum_value<
	ALenum,
	AL_STATIC,
	mp_list<oalplus::source_type>
> static_ = {};
#endif

#ifdef AL_STOPPED
static constexpr const enum_value<
	ALenum,
	AL_STOPPED,
	mp_list<oalplus::source_state>
> stopped = {};
#endif

#ifdef AL_STREAMING
static constexpr const enum_value<
	ALenum,
	AL_STREAMING,
	mp_list<oalplus::source_type>
> streaming = {};
#endif

#ifdef AL_UNDETERMINED
static constexpr const enum_value<
	ALenum,
	AL_UNDETERMINED,
	mp_list<oalplus::source_type>
> undetermined = {};
#endif

#ifdef AL_VENDOR
static constexpr const enum_value<
	ALenum,
	AL_VENDOR,
	mp_list<oalplus::string_query>
> vendor = {};
#endif

#ifdef AL_VERSION
static constexpr const enum_value<
	ALenum,
	AL_VERSION,
	mp_list<oalplus::string_query>
> version = {};
#endif

};// struct enum_values
} // namespace oalplus

#endif // include guard
