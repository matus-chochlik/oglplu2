/**
 *  @file oalplus/alut_api/constants.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OALPLUS_ALUT_API_CONSTANTS_HPP
#define OALPLUS_ALUT_API_CONSTANTS_HPP

#include "c_api.hpp"
#include "enum_types.hpp"

namespace eagine::oalp {
//------------------------------------------------------------------------------
template <typename ApiTraits>
class basic_alut_constants {
public:
    using enum_type = typename alut_types::enum_type;
    using enum_type_i = type_identity<enum_type>;
    template <enum_type value>
    using enum_type_c = std::integral_constant<enum_type, value>;

    opt_c_api_constant<
      mp_list<alut_error_code>,
#ifdef ALUT_ERROR_NO_ERROR
      enum_type_c<ALUT_ERROR_NO_ERROR>>
#else
      enum_type_i>
#endif
      no_error;

    opt_c_api_constant<
      mp_list<waveform_function>,
#ifdef ALUT_WAVEFORM_SINE
      enum_type_c<ALUT_WAVEFORM_SINE>>
#else
      enum_type_i>
#endif
      waveform_sine;

    opt_c_api_constant<
      mp_list<waveform_function>,
#ifdef ALUT_WAVEFORM_SQUARE
      enum_type_c<ALUT_WAVEFORM_SQUARE>>
#else
      enum_type_i>
#endif
      waveform_square;

    opt_c_api_constant<
      mp_list<waveform_function>,
#ifdef ALUT_WAVEFORM_SAWTOOTH
      enum_type_c<ALUT_WAVEFORM_SAWTOOTH>>
#else
      enum_type_i>
#endif
      waveform_sawtooth;

    opt_c_api_constant<
      mp_list<waveform_function>,
#ifdef ALUT_WAVEFORM_WHITENOISE
      enum_type_c<ALUT_WAVEFORM_WHITENOISE>>
#else
      enum_type_i>
#endif
      waveform_whitenoise;

    opt_c_api_constant<
      mp_list<waveform_function>,
#ifdef ALUT_WAVEFORM_IMPULSE
      enum_type_c<ALUT_WAVEFORM_IMPULSE>>
#else
      enum_type_i>
#endif
      waveform_impulse;

    basic_alut_constants(ApiTraits& traits, basic_alut_c_api<ApiTraits>& api);
};
//------------------------------------------------------------------------------
} // namespace eagine::oalp

#endif // OALPLUS_ALUT_API_CONSTANTS_HPP
