//  File include/oalplus/enum/values_alc.hpp
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
#ifndef OALPLUS_ALC_ENUM_VALUES_HPP
#define OALPLUS_ALC_ENUM_VALUES_HPP

#include "types_alc.hpp"
#include "../utils/mp_list.hpp"

namespace oalplus {
struct enum_values_alc {

#ifdef ALC_FREQUENCY
static constexpr const enum_value<
	ALCenum,
	mp_list<oalplus::context_attrib>
> frequency = {ALC_FREQUENCY};
#endif

#ifdef ALC_INVALID_CONTEXT
static constexpr const enum_value<
	ALCenum,
	mp_list<oalplus::alc_error_code>
> invalid_context = {ALC_INVALID_CONTEXT};
#endif

#ifdef ALC_INVALID_DEVICE
static constexpr const enum_value<
	ALCenum,
	mp_list<oalplus::alc_error_code>
> invalid_device = {ALC_INVALID_DEVICE};
#endif

#ifdef ALC_INVALID_ENUM
static constexpr const enum_value<
	ALCenum,
	mp_list<oalplus::alc_error_code>
> invalid_enum = {ALC_INVALID_ENUM};
#endif

#ifdef ALC_INVALID_VALUE
static constexpr const enum_value<
	ALCenum,
	mp_list<oalplus::alc_error_code>
> invalid_value = {ALC_INVALID_VALUE};
#endif

#ifdef ALC_MONO_SOURCES
static constexpr const enum_value<
	ALCenum,
	mp_list<oalplus::context_attrib>
> mono_sources = {ALC_MONO_SOURCES};
#endif

#ifdef ALC_NO_ERROR
static constexpr const enum_value<
	ALCenum,
	mp_list<oalplus::alc_error_code>
> no_error = {ALC_NO_ERROR};
#endif

#ifdef ALC_OUT_OF_MEMORY
static constexpr const enum_value<
	ALCenum,
	mp_list<oalplus::alc_error_code>
> out_of_memory = {ALC_OUT_OF_MEMORY};
#endif

#ifdef ALC_REFRESH
static constexpr const enum_value<
	ALCenum,
	mp_list<oalplus::context_attrib>
> refresh = {ALC_REFRESH};
#endif

#ifdef ALC_STEREO_SOURCES
static constexpr const enum_value<
	ALCenum,
	mp_list<oalplus::context_attrib>
> stereo_sources = {ALC_STEREO_SOURCES};
#endif

#ifdef ALC_SYNC
static constexpr const enum_value<
	ALCenum,
	mp_list<oalplus::context_attrib>
> sync = {ALC_SYNC};
#endif

};// struct enum_values
} // namespace oalplus

#endif // include guard
