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
basic_alut_c_api<ApiTraits>::basic_alut_c_api(api_traits& traits)
  : GetError("GetError", traits, *this)
  , GetErrorString("GetErrorString", traits, *this)
  , Init("Init", traits, *this)
  , InitWithoutContext("InitWithoutContext", traits, *this)
  , CreateBufferFromFile("CreateBufferFromFile", traits, *this)
  , CreateBufferFromFileImage("CreateBufferFromFileImage", traits, *this)
  , CreateBufferHelloWorld("CreateBufferHelloWorld", traits, *this)
  , CreateBufferWaveform("CreateBufferWaveform", traits, *this)
  , Exit("Exit", traits, *this) {}
//------------------------------------------------------------------------------
} // namespace eagine::oalp
