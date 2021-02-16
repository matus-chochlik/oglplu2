/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

namespace eagine::oalp {
//------------------------------------------------------------------------------
template <typename ApiTraits>
basic_al_constants<ApiTraits>::basic_al_constants(
  ApiTraits& traits,
  basic_al_c_api<ApiTraits>& api)
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
  , source_state("SOURCE_STATE", traits, api)
  , source_type("SOURCE_TYPE", traits, api)
  , source_relative("SOURCE_RELATIVE", traits, api)
  , looping("LOOPING", traits, api)
  , position("POSITION", traits, api)
  , velocity("VELOCITY", traits, api)
  , gain("GAIN", traits, api)
  , min_gain("MIN_GAIN", traits, api)
  , max_gain("MAX_GAIN", traits, api)
  , rolloff_factor("ROLLOFF_FACTOR", traits, api)
  , reference_distance("REFERENCE_DISTANCE", traits, api)
  , min_distance("MIN_DISTANCE", traits, api)
  , max_distance("MAX_DISTANCE", traits, api)
  , direction("DIRECTION", traits, api)
  , cone_inner_angle("CONE_INNER_ANGLE", traits, api)
  , cone_outer_angle("CONE_OUTER_ANGLE", traits, api)
  , cone_outer_gain("CONE_OUTER_GAIN", traits, api)
  , sec_offset("SEC_OFFSET", traits, api)
  , sample_offset("SAMPLE_OFFSET", traits, api)
  , byte_offset("BYTE_OFFSET", traits, api)
  , orientation("ORIENTATION", traits, api)
  , current_buffer("BUFFER", traits, api)
  , buffers_queued("BUFFERS_QUEUED", traits, api)
  , buffers_processed("BUFFERS_PROCESSED", traits, api)
  , meters_per_unit("METERS_PER_UNIT", traits, api)
  , direct_filter("DIRECT_FILTER", traits, api)
  , auxiliary_send_filter("AUXILIARY_SEND_FILTER", traits, api)
  , air_absorption_factor("AIR_ABSORPTION_FACTOR", traits, api)
  , room_rolloff_factor("ROOM_ROLLOFF_FACTOR", traits, api)
  , cone_outer_gainhf("CONE_OUTER_GAINHF", traits, api)
  , direct_filter_gainhf_auto("DIRECT_FILTER_GAINHF_AUTO", traits, api)
  , auxiliary_send_filter_gain_auto(
      "AUXILIARY_SEND_FILTER_GAIN_AUTO",
      traits,
      api)
  , auxiliary_send_filter_gainhf_auto(
      "AUXILIARY_SEND_FILTER_GAINHF_AUTO",
      traits,
      api)
  , frequency("FREQUENCY", traits, api)
  , size("SIZE", traits, api)
  , bits("BITS", traits, api)
  , channels("CHANNELS", traits, api)
  , format_mono8("FORMAT_MONO8", traits, api)
  , format_mono16("FORMAT_MONO16", traits, api)
  , format_stereo8("FORMAT_STEREO8", traits, api)
  , format_stereo16("FORMAT_STEREO16", traits, api)
  , undetermined("UNDETERMINED", traits, api)
  , static_("STATIC", traits, api)
  , streaming("STREAMING", traits, api)
  , initial("INITIAL", traits, api)
  , playing("PLAYING", traits, api)
  , paused("PAUSED", traits, api)
  , stopped("STOPPED", traits, api)
  , none("NONE", traits, api) {}
//------------------------------------------------------------------------------
} // namespace eagine::oalp

