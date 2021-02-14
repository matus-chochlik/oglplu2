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
basic_alc_constants<ApiTraits>::basic_alc_constants(
  ApiTraits& traits,
  basic_alc_c_api<ApiTraits>& api)
  : no_error("NO_ERROR", traits, api)
  , invalid_device("INVALID_DEVICE", traits, api)
  , invalid_context("INVALID_CONTEXT", traits, api)
  , invalid_enum("INVALID_ENUM", traits, api)
  , invalid_value("INVALID_VALUE", traits, api)
  , out_of_memory("OUT_OF_MEMORY", traits, api)
  , device_specifier("DEVICE_SPECIFIER", traits, api)
  , capture_device_specifier("CAPTURE_DEVICE_SPECIFIER", traits, api)
  , default_device_specifier("DEFAULT_DEVICE_SPECIFIER", traits, api)
  , capture_default_device_specifier(
      "DEFAULT_CAPTURE_DEVICE_SPECIFIER",
      traits,
      api)
  , all_devices_specifier("ALL_DEVICES_SPECIFIER", traits, api)
  , default_all_devices_specifier("DEFAULT_ALL_DEVICES_SPECIFIER", traits, api)
  , extensions("EXTENSIONS", traits, api)
  , major_version("MAJOR_VERSION", traits, api)
  , minor_version("MINOR_VERSION", traits, api)
  , capture_samples("CAPTURE_SAMPLES", traits, api)
  , frequency("FREQUENCY", traits, api)
  , refresh("REFRESH", traits, api)
  , sync("SYNC", traits, api)
  , mono_sources("MONO_SOURCES", traits, api)
  , stereo_sources("STEREO_SOURCES", traits, api)
  , hrtf_soft("HRTF_SOFT", traits, api)
  , hrtf_id_soft("HRTF_ID_SOFT", traits, api)
  , hrtf_specifier_soft("HRTF_SPECIFIER_SOFT", traits, api) {}
//------------------------------------------------------------------------------
} // namespace eagine::oalp

