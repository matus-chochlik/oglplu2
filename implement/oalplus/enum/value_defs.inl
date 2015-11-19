//  File implement/oalplus/enum/value_defs.inl
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

#ifdef AL_EXPONENT_DISTANCE
const enum_value<
	ALenum,
	AL_EXPONENT_DISTANCE,
	mp_list<oalplus::distance_model>
> enum_values::exponent_distance;
#endif

#ifdef AL_EXPONENT_DISTANCE_CLAMPED
const enum_value<
	ALenum,
	AL_EXPONENT_DISTANCE_CLAMPED,
	mp_list<oalplus::distance_model>
> enum_values::exponent_distance_clamped;
#endif

#ifdef AL_EXTENSIONS
const enum_value<
	ALenum,
	AL_EXTENSIONS,
	mp_list<oalplus::string_query>
> enum_values::extensions;
#endif

#ifdef AL_FORMAT_MONO16
const enum_value<
	ALenum,
	AL_FORMAT_MONO16,
	mp_list<oalplus::data_format>
> enum_values::format_mono16;
#endif

#ifdef AL_FORMAT_MONO8
const enum_value<
	ALenum,
	AL_FORMAT_MONO8,
	mp_list<oalplus::data_format>
> enum_values::format_mono8;
#endif

#ifdef AL_FORMAT_STEREO16
const enum_value<
	ALenum,
	AL_FORMAT_STEREO16,
	mp_list<oalplus::data_format>
> enum_values::format_stereo16;
#endif

#ifdef AL_FORMAT_STEREO8
const enum_value<
	ALenum,
	AL_FORMAT_STEREO8,
	mp_list<oalplus::data_format>
> enum_values::format_stereo8;
#endif

#ifdef AL_INITIAL
const enum_value<
	ALenum,
	AL_INITIAL,
	mp_list<oalplus::source_state>
> enum_values::initial;
#endif

#ifdef AL_INVALID_ENUM
const enum_value<
	ALenum,
	AL_INVALID_ENUM,
	mp_list<oalplus::al_error_code>
> enum_values::invalid_enum;
#endif

#ifdef AL_INVALID_NAME
const enum_value<
	ALenum,
	AL_INVALID_NAME,
	mp_list<oalplus::al_error_code>
> enum_values::invalid_name;
#endif

#ifdef AL_INVALID_OPERATION
const enum_value<
	ALenum,
	AL_INVALID_OPERATION,
	mp_list<oalplus::al_error_code>
> enum_values::invalid_operation;
#endif

#ifdef AL_INVALID_VALUE
const enum_value<
	ALenum,
	AL_INVALID_VALUE,
	mp_list<oalplus::al_error_code>
> enum_values::invalid_value;
#endif

#ifdef AL_INVERSE_DISTANCE
const enum_value<
	ALenum,
	AL_INVERSE_DISTANCE,
	mp_list<oalplus::distance_model>
> enum_values::inverse_distance;
#endif

#ifdef AL_INVERSE_DISTANCE_CLAMPED
const enum_value<
	ALenum,
	AL_INVERSE_DISTANCE_CLAMPED,
	mp_list<oalplus::distance_model>
> enum_values::inverse_distance_clamped;
#endif

#ifdef AL_LINEAR_DISTANCE
const enum_value<
	ALenum,
	AL_LINEAR_DISTANCE,
	mp_list<oalplus::distance_model>
> enum_values::linear_distance;
#endif

#ifdef AL_LINEAR_DISTANCE_CLAMPED
const enum_value<
	ALenum,
	AL_LINEAR_DISTANCE_CLAMPED,
	mp_list<oalplus::distance_model>
> enum_values::linear_distance_clamped;
#endif

#ifdef AL_NO_ERROR
const enum_value<
	ALenum,
	AL_NO_ERROR,
	mp_list<oalplus::al_error_code>
> enum_values::no_error;
#endif

#ifdef AL_NONE
const enum_value<
	ALenum,
	AL_NONE,
	mp_list<oalplus::distance_model>
> enum_values::none;
#endif

#ifdef AL_OUT_OF_MEMORY
const enum_value<
	ALenum,
	AL_OUT_OF_MEMORY,
	mp_list<oalplus::al_error_code>
> enum_values::out_of_memory;
#endif

#ifdef AL_PAUSED
const enum_value<
	ALenum,
	AL_PAUSED,
	mp_list<oalplus::source_state>
> enum_values::paused;
#endif

#ifdef AL_PLAYING
const enum_value<
	ALenum,
	AL_PLAYING,
	mp_list<oalplus::source_state>
> enum_values::playing;
#endif

#ifdef AL_RENDERER
const enum_value<
	ALenum,
	AL_RENDERER,
	mp_list<oalplus::string_query>
> enum_values::renderer;
#endif

#ifdef AL_STATIC
const enum_value<
	ALenum,
	AL_STATIC,
	mp_list<oalplus::source_type>
> enum_values::static_;
#endif

#ifdef AL_STOPPED
const enum_value<
	ALenum,
	AL_STOPPED,
	mp_list<oalplus::source_state>
> enum_values::stopped;
#endif

#ifdef AL_STREAMING
const enum_value<
	ALenum,
	AL_STREAMING,
	mp_list<oalplus::source_type>
> enum_values::streaming;
#endif

#ifdef AL_UNDETERMINED
const enum_value<
	ALenum,
	AL_UNDETERMINED,
	mp_list<oalplus::source_type>
> enum_values::undetermined;
#endif

#ifdef AL_VENDOR
const enum_value<
	ALenum,
	AL_VENDOR,
	mp_list<oalplus::string_query>
> enum_values::vendor;
#endif

#ifdef AL_VERSION
const enum_value<
	ALenum,
	AL_VERSION,
	mp_list<oalplus::string_query>
> enum_values::version;
#endif

} // namespace oalplus
