/**
 *  @file oalplus/al_api/constants.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OALPLUS_AL_API_CONSTANTS_HPP
#define OALPLUS_AL_API_CONSTANTS_HPP

#include "c_api.hpp"
#include "enum_types.hpp"

namespace eagine {
namespace oalp {
//------------------------------------------------------------------------------
template <typename ApiTraits>
struct basic_al_constants {
public:
    using enum_type = typename al_types::enum_type;
    using enum_type_i = identity<enum_type>;
    template <enum_type value>
    using enum_type_c = std::integral_constant<enum_type, value>;

    opt_c_api_constant<
      mp_list<al_error_code>,
#ifdef AL_NO_ERROR
      enum_type_c<AL_NO_ERROR>>
#else
      enum_type_i>
#endif
      no_error;

    opt_c_api_constant<
      mp_list<al_error_code>,
#ifdef AL_INVALID_NAME
      enum_type_c<AL_INVALID_NAME>>
#else
      enum_type_i>
#endif
      invalid_name;

    opt_c_api_constant<
      mp_list<al_error_code>,
#ifdef AL_INVALID_ENUM
      enum_type_c<AL_INVALID_ENUM>>
#else
      enum_type_i>
#endif
      invalid_enum;

    opt_c_api_constant<
      mp_list<al_error_code>,
#ifdef AL_INVALID_OPERATION
      enum_type_c<AL_INVALID_OPERATION>>
#else
      enum_type_i>
#endif
      invalid_operation;

    opt_c_api_constant<
      mp_list<al_error_code>,
#ifdef AL_OUT_OF_MEMORY
      enum_type_c<AL_OUT_OF_MEMORY>>
#else
      enum_type_i>
#endif
      out_of_memory;

    opt_c_api_constant<
      mp_list<al_string_query>,
#ifdef AL_VERSION
      enum_type_c<AL_VERSION>>
#else
      enum_type_i>
#endif
      version;

    opt_c_api_constant<
      mp_list<al_string_query>,
#ifdef AL_RENDERER
      enum_type_c<AL_RENDERER>>
#else
      enum_type_i>
#endif
      renderer;

    opt_c_api_constant<
      mp_list<al_string_query>,
#ifdef AL_VENDOR
      enum_type_c<AL_VENDOR>>
#else
      enum_type_i>
#endif
      vendor;

    opt_c_api_constant<
      mp_list<al_string_query>,
#ifdef AL_EXTENSIONS
      enum_type_c<AL_EXTENSIONS>>
#else
      enum_type_i>
#endif
      extensions;

    opt_c_api_constant<
      mp_list<al_numeric_query>,
#ifdef AL_DOPPLER_FACTOR
      enum_type_c<AL_DOPPLER_FACTOR>>
#else
      enum_type_i>
#endif
      doppler_factor;

    opt_c_api_constant<
      mp_list<al_numeric_query>,
#ifdef AL_SPEED_OF_SOUND
      enum_type_c<AL_SPEED_OF_SOUND>>
#else
      enum_type_i>
#endif
      speed_of_sound;

    opt_c_api_constant<
      mp_list<al_integer_query>,
#ifdef AL_DISTANCE_MODEL
      enum_type_c<AL_DISTANCE_MODEL>>
#else
      enum_type_i>
#endif
      distance_model;

    opt_c_api_constant<
      mp_list<oalp::distance_model>,
#ifdef AL_INVERSE_DISTANCE
      enum_type_c<AL_INVERSE_DISTANCE>>
#else
      enum_type_i>
#endif
      inverse_distance;

    opt_c_api_constant<
      mp_list<oalp::distance_model>,
#ifdef AL_INVERSE_DISTANCE_CLAMPED
      enum_type_c<AL_INVERSE_DISTANCE_CLAMPED>>
#else
      enum_type_i>
#endif
      inverse_distance_clamped;

    opt_c_api_constant<
      mp_list<oalp::distance_model>,
#ifdef AL_LINEAR_DISTANCE
      enum_type_c<AL_LINEAR_DISTANCE>>
#else
      enum_type_i>
#endif
      linear_distance;

    opt_c_api_constant<
      mp_list<oalp::distance_model>,
#ifdef AL_LINEAR_DISTANCE_CLAMPED
      enum_type_c<AL_LINEAR_DISTANCE_CLAMPED>>
#else
      enum_type_i>
#endif
      linear_distance_clamped;

    opt_c_api_constant<
      mp_list<oalp::distance_model>,
#ifdef AL_EXPONENT_DISTANCE
      enum_type_c<AL_EXPONENT_DISTANCE>>
#else
      enum_type_i>
#endif
      exponent_distance;

    opt_c_api_constant<
      mp_list<oalp::distance_model>,
#ifdef AL_EXPONENT_DISTANCE_CLAMPED
      enum_type_c<AL_EXPONENT_DISTANCE_CLAMPED>>
#else
      enum_type_i>
#endif
      exponent_distance_clamped;

    opt_c_api_constant<
      mp_list<listener_attribute, source_attribute>,
#ifdef AL_POSITION
      enum_type_c<AL_POSITION>>
#else
      enum_type_i>
#endif
      position;

    opt_c_api_constant<
      mp_list<listener_attribute, source_attribute>,
#ifdef AL_VELOCITY
      enum_type_c<AL_VELOCITY>>
#else
      enum_type_i>
#endif
      velocity;

    opt_c_api_constant<
      mp_list<listener_attribute, source_attribute>,
#ifdef AL_GAIN
      enum_type_c<AL_GAIN>>
#else
      enum_type_i>
#endif
      gain;

    opt_c_api_constant<
      mp_list<listener_attribute>,
#ifdef AL_ORIENTATION
      enum_type_c<AL_ORIENTATION>>
#else
      enum_type_i>
#endif
      orientation;

    opt_c_api_constant<
      mp_list<source_attribute>,
#ifdef AL_SOURCE_STATE
      enum_type_c<AL_SOURCE_STATE>>
#else
      enum_type_i>
#endif
      source_state;

    dynamic_c_api_constant<mp_list<listener_attribute>, enum_type>
      meters_per_unit;

    dynamic_c_api_constant<mp_list<source_attribute>, enum_type> direct_filter;

    dynamic_c_api_constant<mp_list<source_attribute>, enum_type>
      auxiliary_send_filter;

    dynamic_c_api_constant<mp_list<source_attribute>, enum_type>
      air_absorption_factor;

    dynamic_c_api_constant<mp_list<source_attribute>, enum_type>
      room_rolloff_factor;

    dynamic_c_api_constant<mp_list<source_attribute>, enum_type>
      cone_outer_gainhf;

    dynamic_c_api_constant<mp_list<source_attribute>, enum_type>
      direct_filter_gainhf_auto;

    dynamic_c_api_constant<mp_list<source_attribute>, enum_type>
      auxiliary_send_filter_gain_auto;

    dynamic_c_api_constant<mp_list<source_attribute>, enum_type>
      auxiliary_send_filter_gainhf_auto;

    opt_c_api_constant<
      mp_list<buffer_attribute>,
#ifdef AL_FREQUENCY
      enum_type_c<AL_FREQUENCY>>
#else
      enum_type_i>
#endif
      frequency;

    opt_c_api_constant<
      mp_list<buffer_attribute>,
#ifdef AL_SIZE
      enum_type_c<AL_SIZE>>
#else
      enum_type_i>
#endif
      size;

    opt_c_api_constant<
      mp_list<buffer_attribute>,
#ifdef AL_BITS
      enum_type_c<AL_BITS>>
#else
      enum_type_i>
#endif
      bits;

    opt_c_api_constant<
      mp_list<buffer_attribute>,
#ifdef AL_CHANNELS
      enum_type_c<AL_CHANNELS>>
#else
      enum_type_i>
#endif
      channels;

    opt_c_api_constant<
      mp_list<oalp::source_state>,
#ifdef AL_INITIAL
      enum_type_c<AL_INITIAL>>
#else
      enum_type_i>
#endif
      initial;

    opt_c_api_constant<
      mp_list<oalp::source_state>,
#ifdef AL_PLAYING
      enum_type_c<AL_PLAYING>>
#else
      enum_type_i>
#endif
      playing;

    opt_c_api_constant<
      mp_list<oalp::source_state>,
#ifdef AL_PAUSED
      enum_type_c<AL_PAUSED>>
#else
      enum_type_i>
#endif
      paused;

    opt_c_api_constant<
      mp_list<oalp::source_state>,
#ifdef AL_STOPPED
      enum_type_c<AL_STOPPED>>
#else
      enum_type_i>
#endif
      stopped;

    opt_c_api_constant<
      mp_list<oalp::distance_model>,
#ifdef AL_NONE
      enum_type_c<AL_NONE>>
#else
      enum_type_i>
#endif
      none;

    basic_al_constants(ApiTraits& traits, basic_al_c_api<ApiTraits>& api)
      : no_error("NO_ERROR", traits, api)
      , invalid_name("INVALID_NAME", traits, api)
      , invalid_enum("INVALID_ENUM", traits, api)
      , invalid_operation("INVALID_OPERATION", traits, api)
      , out_of_memory("OUT_OF_MEMORY", traits, api)
      , version("VERSION", traits, api)
      , renderer("RENDERER", traits, api)
      , vendor("VENDOR", traits, api)
      , extensions("EXTENSIONS", traits, api)
      , doppler_factor("DOPPLER_FACTOR", traits, api)
      , speed_of_sound("SPEED_OF_SOUND", traits, api)
      , distance_model("DISTANCE_MODEL", traits, api)
      , inverse_distance("INVERSE_DISTANCE", traits, api)
      , inverse_distance_clamped("INVERSE_DISTANCE_CLAMPED", traits, api)
      , linear_distance("LINEAR_DISTANCE", traits, api)
      , linear_distance_clamped("LINEAR_DISTANCE_CLAMPED", traits, api)
      , exponent_distance("EXPONENT_DISTANCE", traits, api)
      , exponent_distance_clamped("EXPONENT_DISTANCE_CLAMPED", traits, api)
      , position("POSITION", traits, api)
      , velocity("VELOCITY", traits, api)
      , gain("GAIN", traits, api)
      , orientation("ORIENTATION", traits, api)
      , source_state("SOURCE_STATE", traits, api)
      , meters_per_unit("METERS_PER_UNIT", traits, api)
      , direct_filter("DIRECT_FILTER", traits, api)
      , auxiliary_send_filter("AUXILIARY_SEND_FILTER", traits, api)
      , air_absorption_factor("AIR_ABSORPTION_FACTOR", traits, api)
      , room_rolloff_factor("ROOM_ROLLOFF_FACTOR", traits, api)
      , cone_outer_gainhf("CONE_OUTER_GAINHF", traits, api)
      , direct_filter_gainhf_auto("DIRECT_FILTER_GAINHF_AUTO", traits, api)
      , auxiliary_send_filter_gain_auto(
          "AUXILIARY_SEND_FILTER_GAIN_AUTO", traits, api)
      , auxiliary_send_filter_gainhf_auto(
          "AUXILIARY_SEND_FILTER_GAINHF_AUTO", traits, api)
      , frequency("FREQUENCY", traits, api)
      , size("SIZE", traits, api)
      , bits("BITS", traits, api)
      , channels("CHANNELS", traits, api)
      , initial("INITIAL", traits, api)
      , playing("PLAYING", traits, api)
      , paused("PAUSED", traits, api)
      , stopped("STOPPED", traits, api)
      , none("NONE", traits, api) {
    }
};
//------------------------------------------------------------------------------
} // namespace oalp
} // namespace eagine

#endif // OALPLUS_AL_API_CONSTANTS_HPP

