//  File include/oalplus/enum/values.hpp
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
#ifndef OALPLUS_AL_ENUM_VALUES_HPP
#define OALPLUS_AL_ENUM_VALUES_HPP

#include "types.hpp"
#include "../utils/mp_list.hpp"

namespace oalplus {
struct enum_values {

#ifdef AL_BITS
static constexpr const enum_value<
	ALenum,
	mp_list<oalplus::buffer_parameter>
> bits = {AL_BITS};
#endif

#ifdef AL_CHANNELS
static constexpr const enum_value<
	ALenum,
	mp_list<oalplus::buffer_parameter>
> channels = {AL_CHANNELS};
#endif

#ifdef AL_EXPONENT_DISTANCE
static constexpr const enum_value<
	ALenum,
	mp_list<oalplus::distance_model>
> exponent_distance = {AL_EXPONENT_DISTANCE};
#endif

#ifdef AL_EXPONENT_DISTANCE_CLAMPED
static constexpr const enum_value<
	ALenum,
	mp_list<oalplus::distance_model>
> exponent_distance_clamped = {AL_EXPONENT_DISTANCE_CLAMPED};
#endif

#ifdef AL_EXTENSIONS
static constexpr const enum_value<
	ALenum,
	mp_list<oalplus::string_query>
> extensions = {AL_EXTENSIONS};
#endif

#ifdef AL_FORMAT_MONO16
static constexpr const enum_value<
	ALenum,
	mp_list<oalplus::data_format>
> format_mono16 = {AL_FORMAT_MONO16};
#endif

#ifdef AL_FORMAT_MONO8
static constexpr const enum_value<
	ALenum,
	mp_list<oalplus::data_format>
> format_mono8 = {AL_FORMAT_MONO8};
#endif

#ifdef AL_FORMAT_STEREO16
static constexpr const enum_value<
	ALenum,
	mp_list<oalplus::data_format>
> format_stereo16 = {AL_FORMAT_STEREO16};
#endif

#ifdef AL_FORMAT_STEREO8
static constexpr const enum_value<
	ALenum,
	mp_list<oalplus::data_format>
> format_stereo8 = {AL_FORMAT_STEREO8};
#endif

#ifdef AL_FREQUENCY
static constexpr const enum_value<
	ALenum,
	mp_list<oalplus::buffer_parameter>
> frequency = {AL_FREQUENCY};
#endif

#ifdef AL_INITIAL
static constexpr const enum_value<
	ALenum,
	mp_list<oalplus::source_state>
> initial = {AL_INITIAL};
#endif

#ifdef AL_INVALID_ENUM
static constexpr const enum_value<
	ALenum,
	mp_list<oalplus::al_error_code>
> invalid_enum = {AL_INVALID_ENUM};
#endif

#ifdef AL_INVALID_NAME
static constexpr const enum_value<
	ALenum,
	mp_list<oalplus::al_error_code>
> invalid_name = {AL_INVALID_NAME};
#endif

#ifdef AL_INVALID_OPERATION
static constexpr const enum_value<
	ALenum,
	mp_list<oalplus::al_error_code>
> invalid_operation = {AL_INVALID_OPERATION};
#endif

#ifdef AL_INVALID_VALUE
static constexpr const enum_value<
	ALenum,
	mp_list<oalplus::al_error_code>
> invalid_value = {AL_INVALID_VALUE};
#endif

#ifdef AL_INVERSE_DISTANCE
static constexpr const enum_value<
	ALenum,
	mp_list<oalplus::distance_model>
> inverse_distance = {AL_INVERSE_DISTANCE};
#endif

#ifdef AL_INVERSE_DISTANCE_CLAMPED
static constexpr const enum_value<
	ALenum,
	mp_list<oalplus::distance_model>
> inverse_distance_clamped = {AL_INVERSE_DISTANCE_CLAMPED};
#endif

#ifdef AL_LINEAR_DISTANCE
static constexpr const enum_value<
	ALenum,
	mp_list<oalplus::distance_model>
> linear_distance = {AL_LINEAR_DISTANCE};
#endif

#ifdef AL_LINEAR_DISTANCE_CLAMPED
static constexpr const enum_value<
	ALenum,
	mp_list<oalplus::distance_model>
> linear_distance_clamped = {AL_LINEAR_DISTANCE_CLAMPED};
#endif

#ifdef AL_NO_ERROR
static constexpr const enum_value<
	ALenum,
	mp_list<oalplus::al_error_code>
> no_error = {AL_NO_ERROR};
#endif

#ifdef AL_NONE
static constexpr const enum_value<
	ALenum,
	mp_list<oalplus::distance_model>
> none = {AL_NONE};
#endif

#ifdef AL_OUT_OF_MEMORY
static constexpr const enum_value<
	ALenum,
	mp_list<oalplus::al_error_code>
> out_of_memory = {AL_OUT_OF_MEMORY};
#endif

#ifdef AL_PAUSED
static constexpr const enum_value<
	ALenum,
	mp_list<oalplus::source_state>
> paused = {AL_PAUSED};
#endif

#ifdef AL_PLAYING
static constexpr const enum_value<
	ALenum,
	mp_list<oalplus::source_state>
> playing = {AL_PLAYING};
#endif

#ifdef AL_RENDERER
static constexpr const enum_value<
	ALenum,
	mp_list<oalplus::string_query>
> renderer = {AL_RENDERER};
#endif

#ifdef AL_SIZE
static constexpr const enum_value<
	ALenum,
	mp_list<oalplus::buffer_parameter>
> size = {AL_SIZE};
#endif

#ifdef AL_STATIC
static constexpr const enum_value<
	ALenum,
	mp_list<oalplus::source_type>
> static_ = {AL_STATIC};
#endif

#ifdef AL_STOPPED
static constexpr const enum_value<
	ALenum,
	mp_list<oalplus::source_state>
> stopped = {AL_STOPPED};
#endif

#ifdef AL_STREAMING
static constexpr const enum_value<
	ALenum,
	mp_list<oalplus::source_type>
> streaming = {AL_STREAMING};
#endif

#ifdef AL_UNDETERMINED
static constexpr const enum_value<
	ALenum,
	mp_list<oalplus::source_type>
> undetermined = {AL_UNDETERMINED};
#endif

#ifdef AL_VENDOR
static constexpr const enum_value<
	ALenum,
	mp_list<oalplus::string_query>
> vendor = {AL_VENDOR};
#endif

#ifdef AL_VERSION
static constexpr const enum_value<
	ALenum,
	mp_list<oalplus::string_query>
> version = {AL_VERSION};
#endif

};// struct enum_values
} // namespace oalplus

#endif // include guard
