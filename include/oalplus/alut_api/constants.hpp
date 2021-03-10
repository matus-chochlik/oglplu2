/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef OALPLUS_ALUT_API_CONSTANTS_HPP
#define OALPLUS_ALUT_API_CONSTANTS_HPP

#include "c_api.hpp"
#include "enum_types.hpp"

namespace eagine::oalp {
//------------------------------------------------------------------------------
/// @brief Class wrapping the constants from the ALUT API.
/// @ingroup al_api_wrap
/// @see basic_alut_c_api
/// @see basic_alut_operations
template <typename ApiTraits>
class basic_alut_constants {
public:
    using enum_type = typename alut_types::enum_type;
    using enum_type_i = type_identity<enum_type>;
    template <enum_type value>
    using enum_type_c = std::integral_constant<enum_type, value>;

    /// @var no_error
    /// @alutconstwrap{NO_ERROR}
    opt_c_api_constant<
      mp_list<alut_error_code>,
#ifdef ALUT_ERROR_NO_ERROR
      enum_type_c<ALUT_ERROR_NO_ERROR>>
#else
      enum_type_i>
#endif
      no_error;

    /// @var waveform_sine
    /// @alutconstwrap{WAVEFORM_SINE}
    opt_c_api_constant<
      mp_list<waveform_function>,
#ifdef ALUT_WAVEFORM_SINE
      enum_type_c<ALUT_WAVEFORM_SINE>>
#else
      enum_type_i>
#endif
      waveform_sine;

    /// @var waveform_square
    /// @alutconstwrap{WAVEFORM_SQUARE}
    opt_c_api_constant<
      mp_list<waveform_function>,
#ifdef ALUT_WAVEFORM_SQUARE
      enum_type_c<ALUT_WAVEFORM_SQUARE>>
#else
      enum_type_i>
#endif
      waveform_square;

    /// @var waveform_sawtooth
    /// @alutconstwrap{WAVEFORM_SAWTOOTH}
    opt_c_api_constant<
      mp_list<waveform_function>,
#ifdef ALUT_WAVEFORM_SAWTOOTH
      enum_type_c<ALUT_WAVEFORM_SAWTOOTH>>
#else
      enum_type_i>
#endif
      waveform_sawtooth;

    /// @var waveform_whitenoise
    /// @alutconstwrap{WAVEFORM_WHITENOISE}
    opt_c_api_constant<
      mp_list<waveform_function>,
#ifdef ALUT_WAVEFORM_WHITENOISE
      enum_type_c<ALUT_WAVEFORM_WHITENOISE>>
#else
      enum_type_i>
#endif
      waveform_whitenoise;

    /// @var waveform_impulse
    /// @alutconstwrap{WAVEFORM_IMPULSE}
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
