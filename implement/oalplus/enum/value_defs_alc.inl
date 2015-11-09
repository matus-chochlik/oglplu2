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
const enum_value<
	ALCenum,
	ALC_FREQUENCY,
	mp_list<oalplus::context_attrib>
> enum_value::frequency;
#endif

#ifdef ALC_INVALID_CONTEXT
const enum_value<
	ALCenum,
	ALC_INVALID_CONTEXT,
	mp_list<oalplus::alc_error_code>
> enum_value::invalid_context;
#endif

#ifdef ALC_INVALID_DEVICE
const enum_value<
	ALCenum,
	ALC_INVALID_DEVICE,
	mp_list<oalplus::alc_error_code>
> enum_value::invalid_device;
#endif

#ifdef ALC_INVALID_ENUM
const enum_value<
	ALCenum,
	ALC_INVALID_ENUM,
	mp_list<oalplus::alc_error_code>
> enum_value::invalid_enum;
#endif

#ifdef ALC_INVALID_VALUE
const enum_value<
	ALCenum,
	ALC_INVALID_VALUE,
	mp_list<oalplus::alc_error_code>
> enum_value::invalid_value;
#endif

#ifdef ALC_MONO_SOURCES
const enum_value<
	ALCenum,
	ALC_MONO_SOURCES,
	mp_list<oalplus::context_attrib>
> enum_value::mono_sources;
#endif

#ifdef ALC_NO_ERROR
const enum_value<
	ALCenum,
	ALC_NO_ERROR,
	mp_list<oalplus::alc_error_code>
> enum_value::no_error;
#endif

#ifdef ALC_OUT_OF_MEMORY
const enum_value<
	ALCenum,
	ALC_OUT_OF_MEMORY,
	mp_list<oalplus::alc_error_code>
> enum_value::out_of_memory;
#endif

#ifdef ALC_REFRESH
const enum_value<
	ALCenum,
	ALC_REFRESH,
	mp_list<oalplus::context_attrib>
> enum_value::refresh;
#endif

#ifdef ALC_STEREO_SOURCES
const enum_value<
	ALCenum,
	ALC_STEREO_SOURCES,
	mp_list<oalplus::context_attrib>
> enum_value::stereo_sources;
#endif

#ifdef ALC_SYNC
const enum_value<
	ALCenum,
	ALC_SYNC,
	mp_list<oalplus::context_attrib>
> enum_value::sync;
#endif

} // namespace oalplus

#endif // include guard
