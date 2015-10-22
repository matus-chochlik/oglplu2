//  File include/oalplus/enum/gen_values_alc.hpp
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
#ifndef OALPLUS_ALC_GEN_ENUM_VALUES_HPP
#define OALPLUS_ALC_GEN_ENUM_VALUES_HPP

#include "gen_types_alc.hpp"
#include "../utils/mp_list.hpp"

namespace oalplus {
struct generated_enum_values_alc {

#ifdef ALC_FREQUENCY
static constexpr const enum_value<
	ALCenum,
	ALC_FREQUENCY,
	mp_list<oalplus::context_attrib>
> frequency = {};
#endif

#ifdef ALC_INVALID_CONTEXT
static constexpr const enum_value<
	ALCenum,
	ALC_INVALID_CONTEXT,
	mp_list<oalplus::alc_error_code>
> invalid_context = {};
#endif

#ifdef ALC_INVALID_DEVICE
static constexpr const enum_value<
	ALCenum,
	ALC_INVALID_DEVICE,
	mp_list<oalplus::alc_error_code>
> invalid_device = {};
#endif

#ifdef ALC_INVALID_ENUM
static constexpr const enum_value<
	ALCenum,
	ALC_INVALID_ENUM,
	mp_list<oalplus::alc_error_code>
> invalid_enum = {};
#endif

#ifdef ALC_INVALID_VALUE
static constexpr const enum_value<
	ALCenum,
	ALC_INVALID_VALUE,
	mp_list<oalplus::alc_error_code>
> invalid_value = {};
#endif

#ifdef ALC_MONO_SOURCES
static constexpr const enum_value<
	ALCenum,
	ALC_MONO_SOURCES,
	mp_list<oalplus::context_attrib>
> mono_sources = {};
#endif

#ifdef ALC_NO_ERROR
static constexpr const enum_value<
	ALCenum,
	ALC_NO_ERROR,
	mp_list<oalplus::alc_error_code>
> no_error = {};
#endif

#ifdef ALC_OUT_OF_MEMORY
static constexpr const enum_value<
	ALCenum,
	ALC_OUT_OF_MEMORY,
	mp_list<oalplus::alc_error_code>
> out_of_memory = {};
#endif

#ifdef ALC_REFRESH
static constexpr const enum_value<
	ALCenum,
	ALC_REFRESH,
	mp_list<oalplus::context_attrib>
> refresh = {};
#endif

#ifdef ALC_STEREO_SOURCES
static constexpr const enum_value<
	ALCenum,
	ALC_STEREO_SOURCES,
	mp_list<oalplus::context_attrib>
> stereo_sources = {};
#endif

#ifdef ALC_SYNC
static constexpr const enum_value<
	ALCenum,
	ALC_SYNC,
	mp_list<oalplus::context_attrib>
> sync = {};
#endif

};// struct enum_values
} // namespace oalplus

#endif // include guard
