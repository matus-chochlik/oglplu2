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
      mp_list<al_numeric_query>,
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
      mp_list<oalp::distance_model>,
#ifdef AL_NONE
      enum_type_c<AL_NONE>>
#else
      enum_type_i>
#endif
      none;

    basic_al_constants(ApiTraits& traits, basic_al_c_api<ApiTraits>& api)
      : no_error("NO_ERROR", traits, api)
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
      , none("NONE", traits, api) {
    }
};
//------------------------------------------------------------------------------
} // namespace oalp
} // namespace eagine

#endif // OALPLUS_AL_API_CONSTANTS_HPP

