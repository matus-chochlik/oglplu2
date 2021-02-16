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
basic_alut_constants<ApiTraits>::basic_alut_constants(
  ApiTraits& traits,
  basic_alut_c_api<ApiTraits>& api)
  : no_error("ERROR_NO_ERROR", traits, api)
  , waveform_sine("WAVEFORM_SINE", traits, api)
  , waveform_square("WAVEFORM_SQUARE", traits, api)
  , waveform_sawtooth("WAVEFORM_SAWTOOTH", traits, api)
  , waveform_whitenoise("WAVEFORM_WHITENOISE", traits, api)
  , waveform_impulse("WAVEFORM_IMPULSE", traits, api) {}
//------------------------------------------------------------------------------
} // namespace eagine::oalp

