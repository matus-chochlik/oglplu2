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

#ifdef AL_BITS
constexpr const enum_value<
	ALenum,
	mp_list<oalplus::buffer_parameter>
> enum_values::bits;
#endif

#ifdef AL_CHANNELS
constexpr const enum_value<
	ALenum,
	mp_list<oalplus::buffer_parameter>
> enum_values::channels;
#endif

#ifdef AL_EXPONENT_DISTANCE
constexpr const enum_value<
	ALenum,
	mp_list<oalplus::distance_model>
> enum_values::exponent_distance;
#endif

#ifdef AL_EXPONENT_DISTANCE_CLAMPED
constexpr const enum_value<
	ALenum,
	mp_list<oalplus::distance_model>
> enum_values::exponent_distance_clamped;
#endif

#ifdef AL_EXTENSIONS
constexpr const enum_value<
	ALenum,
	mp_list<oalplus::string_query>
> enum_values::extensions;
#endif

#ifdef AL_FORMAT_MONO16
constexpr const enum_value<
	ALenum,
	mp_list<oalplus::data_format>
> enum_values::format_mono16;
#endif

#ifdef AL_FORMAT_MONO8
constexpr const enum_value<
	ALenum,
	mp_list<oalplus::data_format>
> enum_values::format_mono8;
#endif

#ifdef AL_FORMAT_STEREO16
constexpr const enum_value<
	ALenum,
	mp_list<oalplus::data_format>
> enum_values::format_stereo16;
#endif

#ifdef AL_FORMAT_STEREO8
constexpr const enum_value<
	ALenum,
	mp_list<oalplus::data_format>
> enum_values::format_stereo8;
#endif

#ifdef AL_FREQUENCY
constexpr const enum_value<
	ALenum,
	mp_list<oalplus::buffer_parameter>
> enum_values::frequency;
#endif

#ifdef AL_INITIAL
constexpr const enum_value<
	ALenum,
	mp_list<oalplus::source_state>
> enum_values::initial;
#endif

#ifdef AL_INVALID_ENUM
constexpr const enum_value<
	ALenum,
	mp_list<oalplus::al_error_code>
> enum_values::invalid_enum;
#endif

#ifdef AL_INVALID_NAME
constexpr const enum_value<
	ALenum,
	mp_list<oalplus::al_error_code>
> enum_values::invalid_name;
#endif

#ifdef AL_INVALID_OPERATION
constexpr const enum_value<
	ALenum,
	mp_list<oalplus::al_error_code>
> enum_values::invalid_operation;
#endif

#ifdef AL_INVALID_VALUE
constexpr const enum_value<
	ALenum,
	mp_list<oalplus::al_error_code>
> enum_values::invalid_value;
#endif

#ifdef AL_INVERSE_DISTANCE
constexpr const enum_value<
	ALenum,
	mp_list<oalplus::distance_model>
> enum_values::inverse_distance;
#endif

#ifdef AL_INVERSE_DISTANCE_CLAMPED
constexpr const enum_value<
	ALenum,
	mp_list<oalplus::distance_model>
> enum_values::inverse_distance_clamped;
#endif

#ifdef AL_LINEAR_DISTANCE
constexpr const enum_value<
	ALenum,
	mp_list<oalplus::distance_model>
> enum_values::linear_distance;
#endif

#ifdef AL_LINEAR_DISTANCE_CLAMPED
constexpr const enum_value<
	ALenum,
	mp_list<oalplus::distance_model>
> enum_values::linear_distance_clamped;
#endif

#ifdef AL_NO_ERROR
constexpr const enum_value<
	ALenum,
	mp_list<oalplus::al_error_code>
> enum_values::no_error;
#endif

#ifdef AL_NONE
constexpr const enum_value<
	ALenum,
	mp_list<oalplus::distance_model>
> enum_values::none;
#endif

#ifdef AL_OUT_OF_MEMORY
constexpr const enum_value<
	ALenum,
	mp_list<oalplus::al_error_code>
> enum_values::out_of_memory;
#endif

#ifdef AL_PAUSED
constexpr const enum_value<
	ALenum,
	mp_list<oalplus::source_state>
> enum_values::paused;
#endif

#ifdef AL_PLAYING
constexpr const enum_value<
	ALenum,
	mp_list<oalplus::source_state>
> enum_values::playing;
#endif

#ifdef AL_RENDERER
constexpr const enum_value<
	ALenum,
	mp_list<oalplus::string_query>
> enum_values::renderer;
#endif

#ifdef AL_SIZE
constexpr const enum_value<
	ALenum,
	mp_list<oalplus::buffer_parameter>
> enum_values::size;
#endif

#ifdef AL_STATIC
constexpr const enum_value<
	ALenum,
	mp_list<oalplus::source_type>
> enum_values::static_;
#endif

#ifdef AL_STOPPED
constexpr const enum_value<
	ALenum,
	mp_list<oalplus::source_state>
> enum_values::stopped;
#endif

#ifdef AL_STREAMING
constexpr const enum_value<
	ALenum,
	mp_list<oalplus::source_type>
> enum_values::streaming;
#endif

#ifdef AL_UNDETERMINED
constexpr const enum_value<
	ALenum,
	mp_list<oalplus::source_type>
> enum_values::undetermined;
#endif

#ifdef AL_VENDOR
constexpr const enum_value<
	ALenum,
	mp_list<oalplus::string_query>
> enum_values::vendor;
#endif

#ifdef AL_VERSION
constexpr const enum_value<
	ALenum,
	mp_list<oalplus::string_query>
> enum_values::version;
#endif

} // namespace oalplus
