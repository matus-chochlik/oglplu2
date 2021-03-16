/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef OALPLUS_AL_API_CONSTANTS_HPP
#define OALPLUS_AL_API_CONSTANTS_HPP

#include "c_api.hpp"
#include "enum_types.hpp"

namespace eagine::oalp {
//------------------------------------------------------------------------------
/// @brief Class wrapping the constants from the AL API.
/// @ingroup al_api_wrap
/// @see basic_al_c_api
/// @see basic_al_operations
template <typename ApiTraits>
class basic_al_constants {
public:
    using enum_type = typename al_types::enum_type;
    using enum_type_i = type_identity<enum_type>;
    template <enum_type value>
    using enum_type_c = std::integral_constant<enum_type, value>;

    /// @var no_error
    /// @alconstwrap{NO_ERROR}
    opt_c_api_constant<
      mp_list<al_error_code>,
#ifdef AL_NO_ERROR
      enum_type_c<AL_NO_ERROR>>
#else
      enum_type_i>
#endif
      no_error;

    /// @var invalid_name
    /// @alconstwrap{INVALID_NAME}
    opt_c_api_constant<
      mp_list<al_error_code>,
#ifdef AL_INVALID_NAME
      enum_type_c<AL_INVALID_NAME>>
#else
      enum_type_i>
#endif
      invalid_name;

    /// @var invalid_enum
    /// @alconstwrap{INVALID_ENUM}
    opt_c_api_constant<
      mp_list<al_error_code>,
#ifdef AL_INVALID_ENUM
      enum_type_c<AL_INVALID_ENUM>>
#else
      enum_type_i>
#endif
      invalid_enum;

    /// @var invalid_operation
    /// @alconstwrap{INVALID_OPERATION}
    opt_c_api_constant<
      mp_list<al_error_code>,
#ifdef AL_INVALID_OPERATION
      enum_type_c<AL_INVALID_OPERATION>>
#else
      enum_type_i>
#endif
      invalid_operation;

    /// @var out_of_memory
    /// @alconstwrap{OUT_OF_MEMORY}
    opt_c_api_constant<
      mp_list<al_error_code>,
#ifdef AL_OUT_OF_MEMORY
      enum_type_c<AL_OUT_OF_MEMORY>>
#else
      enum_type_i>
#endif
      out_of_memory;

    /// @var version
    /// @alconstwrap{VERSION}
    opt_c_api_constant<
      mp_list<al_string_query>,
#ifdef AL_VERSION
      enum_type_c<AL_VERSION>>
#else
      enum_type_i>
#endif
      version;

    /// @var renderer
    /// @alconstwrap{RENDERER}
    opt_c_api_constant<
      mp_list<al_string_query>,
#ifdef AL_RENDERER
      enum_type_c<AL_RENDERER>>
#else
      enum_type_i>
#endif
      renderer;

    /// @var vendor
    /// @alconstwrap{VENDOR}
    opt_c_api_constant<
      mp_list<al_string_query>,
#ifdef AL_VENDOR
      enum_type_c<AL_VENDOR>>
#else
      enum_type_i>
#endif
      vendor;

    /// @var extensions
    /// @alconstwrap{EXTENSIONS}
    opt_c_api_constant<
      mp_list<al_string_query>,
#ifdef AL_EXTENSIONS
      enum_type_c<AL_EXTENSIONS>>
#else
      enum_type_i>
#endif
      extensions;

    /// @var doppler_factor
    /// @alconstwrap{DOPPLER_FACTOR}
    opt_c_api_constant<
      mp_list<al_numeric_query>,
#ifdef AL_DOPPLER_FACTOR
      enum_type_c<AL_DOPPLER_FACTOR>>
#else
      enum_type_i>
#endif
      doppler_factor;

    /// @var speed_of_sound
    /// @alconstwrap{SPEED_OF_SOUND}
    opt_c_api_constant<
      mp_list<al_numeric_query>,
#ifdef AL_SPEED_OF_SOUND
      enum_type_c<AL_SPEED_OF_SOUND>>
#else
      enum_type_i>
#endif
      speed_of_sound;

    /// @var distance_model
    /// @alconstwrap{DISTANCE_MODEL}
    opt_c_api_constant<
      mp_list<al_integer_query>,
#ifdef AL_DISTANCE_MODEL
      enum_type_c<AL_DISTANCE_MODEL>,
#else
      enum_type_i,
#endif
      oalp::distance_model>
      distance_model;

    /// @var inverse_distance
    /// @alconstwrap{INVERSE_DISTANCE}
    opt_c_api_constant<
      mp_list<oalp::distance_model>,
#ifdef AL_INVERSE_DISTANCE
      enum_type_c<AL_INVERSE_DISTANCE>>
#else
      enum_type_i>
#endif
      inverse_distance;

    /// @var inverse_distance_clamped
    /// @alconstwrap{INVERSE_DISTANCE_CLAMPED}
    opt_c_api_constant<
      mp_list<oalp::distance_model>,
#ifdef AL_INVERSE_DISTANCE_CLAMPED
      enum_type_c<AL_INVERSE_DISTANCE_CLAMPED>>
#else
      enum_type_i>
#endif
      inverse_distance_clamped;

    /// @var linear_distance
    /// @alconstwrap{LINEAR_DISTANCE}
    opt_c_api_constant<
      mp_list<oalp::distance_model>,
#ifdef AL_LINEAR_DISTANCE
      enum_type_c<AL_LINEAR_DISTANCE>>
#else
      enum_type_i>
#endif
      linear_distance;

    /// @var linear_distance_clamped
    /// @alconstwrap{LINEAR_DISTANCE_CLAMPED}
    opt_c_api_constant<
      mp_list<oalp::distance_model>,
#ifdef AL_LINEAR_DISTANCE_CLAMPED
      enum_type_c<AL_LINEAR_DISTANCE_CLAMPED>>
#else
      enum_type_i>
#endif
      linear_distance_clamped;

    /// @var exponent_distance
    /// @alconstwrap{EXPONENT_DISTANCE}
    opt_c_api_constant<
      mp_list<oalp::distance_model>,
#ifdef AL_EXPONENT_DISTANCE
      enum_type_c<AL_EXPONENT_DISTANCE>>
#else
      enum_type_i>
#endif
      exponent_distance;

    /// @var exponent_distance_clamped
    /// @alconstwrap{EXPONENT_DISTANCE_CLAMPED}
    opt_c_api_constant<
      mp_list<oalp::distance_model>,
#ifdef AL_EXPONENT_DISTANCE_CLAMPED
      enum_type_c<AL_EXPONENT_DISTANCE_CLAMPED>>
#else
      enum_type_i>
#endif
      exponent_distance_clamped;

    /// @var source_state
    /// @alconstwrap{SOURCE_STATE}
    opt_c_api_constant<
      mp_list<source_attribute>,
#ifdef AL_SOURCE_STATE
      enum_type_c<AL_SOURCE_STATE>>
#else
      enum_type_i>
#endif
      source_state;

    /// @var source_type
    /// @alconstwrap{SOURCE_TYPE}
    opt_c_api_constant<
      mp_list<source_attribute>,
#ifdef AL_SOURCE_TYPE
      enum_type_c<AL_SOURCE_TYPE>>
#else
      enum_type_i>
#endif
      source_type;

    /// @var source_relative
    /// @alconstwrap{SOURCE_RELATIVE}
    opt_c_api_constant<
      mp_list<source_attribute>,
#ifdef AL_SOURCE_RELATIVE
      enum_type_c<AL_SOURCE_RELATIVE>>
#else
      enum_type_i>
#endif
      source_relative;

    /// @var looping
    /// @alconstwrap{LOOPING}
    opt_c_api_constant<
      mp_list<source_attribute>,
#ifdef AL_LOOPING
      enum_type_c<AL_LOOPING>>
#else
      enum_type_i>
#endif
      looping;

    /// @var position
    /// @alconstwrap{POSITION}
    opt_c_api_constant<
      mp_list<listener_attribute, source_attribute>,
#ifdef AL_POSITION
      enum_type_c<AL_POSITION>>
#else
      enum_type_i>
#endif
      position;

    /// @var velocity
    /// @alconstwrap{VELOCITY}
    opt_c_api_constant<
      mp_list<listener_attribute, source_attribute>,
#ifdef AL_VELOCITY
      enum_type_c<AL_VELOCITY>>
#else
      enum_type_i>
#endif
      velocity;

    /// @var gain
    /// @alconstwrap{GAIN}
    opt_c_api_constant<
      mp_list<listener_attribute, source_attribute>,
#ifdef AL_GAIN
      enum_type_c<AL_GAIN>>
#else
      enum_type_i>
#endif
      gain;

    /// @var min_gain
    /// @alconstwrap{MIN_GAIN}
    opt_c_api_constant<
      mp_list<source_attribute>,
#ifdef AL_MIN_GAIN
      enum_type_c<AL_MIN_GAIN>>
#else
      enum_type_i>
#endif
      min_gain;

    /// @var max_gain
    /// @alconstwrap{MAX_GAIN}
    opt_c_api_constant<
      mp_list<source_attribute>,
#ifdef AL_MAX_GAIN
      enum_type_c<AL_MAX_GAIN>>
#else
      enum_type_i>
#endif
      max_gain;

    /// @var rolloff_factor
    /// @alconstwrap{ROLLOFF_FACTOR}
    opt_c_api_constant<
      mp_list<source_attribute>,
#ifdef AL_ROLLOFF_FACTOR
      enum_type_c<AL_ROLLOFF_FACTOR>>
#else
      enum_type_i>
#endif
      rolloff_factor;

    /// @var reference_distance
    /// @alconstwrap{REFERENCE_DISTANCE}
    opt_c_api_constant<
      mp_list<source_attribute>,
#ifdef AL_REFERENCE_DISTANCE
      enum_type_c<AL_REFERENCE_DISTANCE>>
#else
      enum_type_i>
#endif
      reference_distance;

    /// @var min_distance
    /// @alconstwrap{MIN_DISTANCE}
    opt_c_api_constant<
      mp_list<source_attribute>,
#ifdef AL_MIN_DISTANCE
      enum_type_c<AL_MIN_DISTANCE>>
#else
      enum_type_i>
#endif
      min_distance;

    /// @var max_distance
    /// @alconstwrap{MAX_DISTANCE}
    opt_c_api_constant<
      mp_list<source_attribute>,
#ifdef AL_MAX_DISTANCE
      enum_type_c<AL_MAX_DISTANCE>>
#else
      enum_type_i>
#endif
      max_distance;

    /// @var direction
    /// @alconstwrap{DIRECTION}
    opt_c_api_constant<
      mp_list<source_attribute>,
#ifdef AL_DIRECTION
      enum_type_c<AL_DIRECTION>>
#else
      enum_type_i>
#endif
      direction;

    /// @var cone_inner_angle
    /// @alconstwrap{CONE_INNER_ANGLE}
    opt_c_api_constant<
      mp_list<source_attribute>,
#ifdef AL_CONE_INNER_ANGLE
      enum_type_c<AL_CONE_INNER_ANGLE>>
#else
      enum_type_i>
#endif
      cone_inner_angle;

    /// @var cone_outer_angle
    /// @alconstwrap{cone_outer_angle}
    opt_c_api_constant<
      mp_list<source_attribute>,
#ifdef AL_CONE_OUTER_ANGLE
      enum_type_c<AL_CONE_OUTER_ANGLE>>
#else
      enum_type_i>
#endif
      cone_outer_angle;

    /// @var cone_outer_gain
    /// @alconstwrap{CONE_OUTER_GAIN}
    opt_c_api_constant<
      mp_list<source_attribute>,
#ifdef AL_CONE_OUTER_GAIN
      enum_type_c<AL_CONE_OUTER_GAIN>>
#else
      enum_type_i>
#endif
      cone_outer_gain;

    /// @var sec_offset
    /// @alconstwrap{SEC_OFFSET}
    opt_c_api_constant<
      mp_list<source_attribute>,
#ifdef AL_SEC_OFFSET
      enum_type_c<AL_SEC_OFFSET>>
#else
      enum_type_i>
#endif
      sec_offset;

    /// @var sample_offset
    /// @alconstwrap{SAMPLE_OFFSET}
    opt_c_api_constant<
      mp_list<source_attribute>,
#ifdef AL_SAMPLE_OFFSET
      enum_type_c<AL_SAMPLE_OFFSET>>
#else
      enum_type_i>
#endif
      sample_offset;

    /// @var byte_offset
    /// @alconstwrap{BYTE_OFFSET}
    opt_c_api_constant<
      mp_list<source_attribute>,
#ifdef AL_BYTE_OFFSET
      enum_type_c<AL_BYTE_OFFSET>>
#else
      enum_type_i>
#endif
      byte_offset;

    /// @var orientation
    /// @alconstwrap{ORIENTATION}
    opt_c_api_constant<
      mp_list<listener_attribute>,
#ifdef AL_ORIENTATION
      enum_type_c<AL_ORIENTATION>>
#else
      enum_type_i>
#endif
      orientation;

    /// @var current_buffer
    /// @alconstwrap{CURRENT_BUFFER}
    opt_c_api_constant<
      mp_list<source_attribute>,
#ifdef AL_BUFFER
      enum_type_c<AL_BUFFER>>
#else
      enum_type_i>
#endif
      current_buffer;

    /// @var buffers_queued
    /// @alconstwrap{BUFFERS_QUEUED}
    opt_c_api_constant<
      mp_list<source_attribute>,
#ifdef AL_BUFFERS_QUEUED
      enum_type_c<AL_BUFFERS_QUEUED>>
#else
      enum_type_i>
#endif
      buffers_queued;

    /// @var buffers_processed
    /// @alconstwrap{BUFFERS_PROCESSED}
    opt_c_api_constant<
      mp_list<source_attribute>,
#ifdef AL_BUFFERS_PROCESSED
      enum_type_c<AL_BUFFERS_PROCESSED>>
#else
      enum_type_i>
#endif
      buffers_processed;

    /// @var meters_per_unit
    /// @alconstwrap{METERS_PER_UNIT}
    dynamic_c_api_constant<mp_list<listener_attribute>, enum_type>
      meters_per_unit;

    /// @var direct_filter`
    /// @alconstwrap{DIRECT_FILTER}
    dynamic_c_api_constant<mp_list<source_attribute>, enum_type> direct_filter;

    /// @var auxiliary_send_filter
    /// @alconstwrap{AUXILIARY_SEND_FILTER}
    dynamic_c_api_constant<mp_list<source_attribute>, enum_type>
      auxiliary_send_filter;

    /// @var air_absorption_factor
    /// @alconstwrap{AIR_ABSORPTION_FACTOR}
    dynamic_c_api_constant<mp_list<source_attribute>, enum_type>
      air_absorption_factor;

    /// @var room_rolloff_factor
    /// @alconstwrap{ROOM_ROLLOFF_FACTOR}
    dynamic_c_api_constant<mp_list<source_attribute>, enum_type>
      room_rolloff_factor;

    /// @var cone_outer_gainhf
    /// @alconstwrap{CONE_OUTER_GAINHF}
    dynamic_c_api_constant<mp_list<source_attribute>, enum_type>
      cone_outer_gainhf;

    /// @var direct_filter_gainhf_auto
    /// @alconstwrap{DIRECT_FILTER_GAINHF_AUTO}
    dynamic_c_api_constant<mp_list<source_attribute>, enum_type>
      direct_filter_gainhf_auto;

    /// @var auxiliary_send_filter_gain_auto
    /// @alconstwrap{AUXILIARY_SEND_FILTER_GAIN_AUTO}
    dynamic_c_api_constant<mp_list<source_attribute>, enum_type>
      auxiliary_send_filter_gain_auto;

    /// @var auxiliary_send_filter_gainhf_auto
    /// @alconstwrap{AUXILIARY_SEND_FILTER_GAINHF_AUTO}
    dynamic_c_api_constant<mp_list<source_attribute>, enum_type>
      auxiliary_send_filter_gainhf_auto;

    /// @var frequency
    /// @alconstwrap{FREQUENCY}
    opt_c_api_constant<
      mp_list<buffer_attribute>,
#ifdef AL_FREQUENCY
      enum_type_c<AL_FREQUENCY>>
#else
      enum_type_i>
#endif
      frequency;

    /// @var size
    /// @alconstwrap{SIZE}
    opt_c_api_constant<
      mp_list<buffer_attribute>,
#ifdef AL_SIZE
      enum_type_c<AL_SIZE>>
#else
      enum_type_i>
#endif
      size;

    /// @var bits
    /// @alconstwrap{BITS}
    opt_c_api_constant<
      mp_list<buffer_attribute>,
#ifdef AL_BITS
      enum_type_c<AL_BITS>>
#else
      enum_type_i>
#endif
      bits;

    /// @var channels
    /// @alconstwrap{CHANNELS}
    opt_c_api_constant<
      mp_list<buffer_attribute>,
#ifdef AL_CHANNELS
      enum_type_c<AL_CHANNELS>>
#else
      enum_type_i>
#endif
      channels;

    /// @var format_mono8
    /// @alconstwrap{FORMAT_MONO8}
    opt_c_api_constant<
      mp_list<buffer_format>,
#ifdef AL_FORMAT_MONO8
      enum_type_c<AL_FORMAT_MONO8>>
#else
      enum_type_i>
#endif
      format_mono8;

    /// @var format_mono16
    /// @alconstwrap{FORMAT_MONO16}
    opt_c_api_constant<
      mp_list<buffer_format>,
#ifdef AL_FORMAT_MONO16
      enum_type_c<AL_FORMAT_MONO16>>
#else
      enum_type_i>
#endif
      format_mono16;

    /// @var format_stereo8
    /// @alconstwrap{FORMAT_STEREO8}
    opt_c_api_constant<
      mp_list<buffer_format>,
#ifdef AL_FORMAT_STEREO8
      enum_type_c<AL_FORMAT_STEREO8>>
#else
      enum_type_i>
#endif
      format_stereo8;

    /// @var format_stereo16
    /// @alconstwrap{FORMAT_STEREO16}
    opt_c_api_constant<
      mp_list<buffer_format>,
#ifdef AL_FORMAT_STEREO16
      enum_type_c<AL_FORMAT_STEREO16>>
#else
      enum_type_i>
#endif
      format_stereo16;

    /// @var undetermined
    /// @alconstwrap{UNDETERMINED}
    opt_c_api_constant<
      mp_list<oalp::source_type>,
#ifdef AL_UNDETERMINED
      enum_type_c<AL_UNDETERMINED>>
#else
      enum_type_i>
#endif
      undetermined;

    /// @var static_
    /// @alconstwrap{STATIC}
    opt_c_api_constant<
      mp_list<oalp::source_type>,
#ifdef AL_STATIC
      enum_type_c<AL_STATIC>>
#else
      enum_type_i>
#endif
      static_;

    /// @var streaming
    /// @alconstwrap{STREAMING}
    opt_c_api_constant<
      mp_list<oalp::source_type>,
#ifdef AL_STREAMING
      enum_type_c<AL_STREAMING>>
#else
      enum_type_i>
#endif
      streaming;

    /// @var initial
    /// @alconstwrap{INITIAL}
    opt_c_api_constant<
      mp_list<oalp::source_state>,
#ifdef AL_INITIAL
      enum_type_c<AL_INITIAL>>
#else
      enum_type_i>
#endif
      initial;

    /// @var playing
    /// @alconstwrap{PLAYING}
    opt_c_api_constant<
      mp_list<oalp::source_state>,
#ifdef AL_PLAYING
      enum_type_c<AL_PLAYING>>
#else
      enum_type_i>
#endif
      playing;

    /// @var paused
    /// @alconstwrap{PAUSED}
    opt_c_api_constant<
      mp_list<oalp::source_state>,
#ifdef AL_PAUSED
      enum_type_c<AL_PAUSED>>
#else
      enum_type_i>
#endif
      paused;

    /// @var stopped
    /// @alconstwrap{STOPPED}
    opt_c_api_constant<
      mp_list<oalp::source_state>,
#ifdef AL_STOPPED
      enum_type_c<AL_STOPPED>>
#else
      enum_type_i>
#endif
      stopped;

    /// @var none
    /// @alconstwrap{NONE}
    opt_c_api_constant<
      mp_list<oalp::distance_model>,
#ifdef AL_NONE
      enum_type_c<AL_NONE>>
#else
      enum_type_i>
#endif
      none;

    basic_al_constants(ApiTraits& traits, basic_al_c_api<ApiTraits>& api);
};
//------------------------------------------------------------------------------
} // namespace eagine::oalp

#endif // OALPLUS_AL_API_CONSTANTS_HPP
