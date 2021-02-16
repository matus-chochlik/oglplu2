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
basic_alc_c_api<ApiTraits>::basic_alc_c_api(api_traits& traits)
  : GetError("GetError", traits, *this)
  , GetProcAddress("GetProcAddress", traits, *this)
  , GetEnumValue("GetEnumValue", traits, *this)
  , OpenDevice("OpenDevice", traits, *this)
  , CaptureOpenDevice("CaptureOpenDevice", traits, *this)
  , CloseDevice("CloseDevice", traits, *this)
  , CaptureCloseDevice("CaptureCloseDevice", traits, *this)
  , GetString("GetString", traits, *this)
  , GetIntegerv("GetIntegerv", traits, *this)
  , IsExtensionPresent("IsExtensionPresent", traits, *this)
  , CreateContext("CreateContext", traits, *this)
  , ProcessContext("ProcessContext", traits, *this)
  , SuspendContext("SuspendContext", traits, *this)
  , DestroyContext("DestroyContext", traits, *this)
  , MakeContextCurrent("MakeContextCurrent", traits, *this)
  , GetCurrentContext("GetCurrentContext", traits, *this)
  , GetContextsDevice("GetContextsDevice", traits, *this)
  , CaptureStart("CaptureStart", traits, *this)
  , CaptureStop("CaptureStop", traits, *this)
  , CaptureSamples("CaptureSamples", traits, *this) {}
//------------------------------------------------------------------------------
} // namespace eagine::oalp

