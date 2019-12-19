/**
 *  @file oalplus/alc_api/constants.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OALPLUS_ALC_API_CONSTANTS_HPP
#define OALPLUS_ALC_API_CONSTANTS_HPP

#include "c_api.hpp"
#include "enum_types.hpp"

namespace eagine {
namespace oalp {
//------------------------------------------------------------------------------
template <typename ApiTraits>
struct basic_alc_constants {
public:
    using enum_type = typename alc_types::enum_type;
    using enum_type_i = identity<enum_type>;
    template <enum_type value>
    using enum_type_c = std::integral_constant<enum_type, value>;

    opt_c_api_constant<
      mp_list<alc_error_code>,
#ifdef ALC_NO_ERROR
      enum_type_c<ALC_NO_ERROR>>
#else
      enum_type_i>
#endif
      no_error;

    opt_c_api_constant<
      mp_list<alc_error_code>,
#ifdef ALC_INVALID_DEVICE
      enum_type_c<ALC_INVALID_DEVICE>>
#else
      enum_type_i>
#endif
      invalid_device;

    opt_c_api_constant<
      mp_list<alc_error_code>,
#ifdef ALC_INVALID_CONTEXT
      enum_type_c<ALC_INVALID_CONTEXT>>
#else
      enum_type_i>
#endif
      invalid_context;

    opt_c_api_constant<
      mp_list<alc_error_code>,
#ifdef ALC_INVALID_ENUM
      enum_type_c<ALC_INVALID_ENUM>>
#else
      enum_type_i>
#endif
      invalid_enum;

    opt_c_api_constant<
      mp_list<alc_error_code>,
#ifdef ALC_INVALID_VALUE
      enum_type_c<ALC_INVALID_VALUE>>
#else
      enum_type_i>
#endif
      invalid_value;

    opt_c_api_constant<
      mp_list<alc_error_code>,
#ifdef ALC_OUT_OF_MEMORY
      enum_type_c<ALC_OUT_OF_MEMORY>>
#else
      enum_type_i>
#endif
      out_of_memory;

    opt_c_api_constant<
      mp_list<alc_string_query>,
#ifdef ALC_DEVICE_SPECIFIER
      enum_type_c<ALC_DEVICE_SPECIFIER>>
#else
      enum_type_i>
#endif
      device_specifier;

    opt_c_api_constant<
      mp_list<alc_string_query>,
#ifdef ALC_CAPTURE_DEVICE_SPECIFIER
      enum_type_c<ALC_CAPTURE_DEVICE_SPECIFIER>>
#else
      enum_type_i>
#endif
      capture_device_specifier;

    opt_c_api_constant<
      mp_list<alc_string_query>,
#ifdef ALC_DEFAULT_DEVICE_SPECIFIER
      enum_type_c<ALC_DEFAULT_DEVICE_SPECIFIER>>
#else
      enum_type_i>
#endif
      default_device_specifier;

    opt_c_api_constant<
      mp_list<alc_string_query>,
#ifdef ALC_CAPTURE_DEFAULT_DEVICE_SPECIFIER
      enum_type_c<ALC_CAPTURE_DEFAULT_DEVICE_SPECIFIER>>
#else
      enum_type_i>
#endif
      capture_default_device_specifier;

    const dynamic_c_api_constant<mp_list<alc_string_query>, enum_type>
      all_devices_specifier;

    const dynamic_c_api_constant<mp_list<alc_string_query>, enum_type>
      default_all_devices_specifier;

    opt_c_api_constant<
      mp_list<alc_string_query>,
#ifdef ALC_EXTENSIONS
      enum_type_c<ALC_EXTENSIONS>>
#else
      enum_type_i>
#endif
      extensions;

    opt_c_api_constant<
      mp_list<alc_integer_query>,
#ifdef ALC_MAJOR_VERSION
      enum_type_c<ALC_MAJOR_VERSION>>
#else
      enum_type_i>
#endif
      major_version;

    opt_c_api_constant<
      mp_list<alc_integer_query>,
#ifdef ALC_MINOR_VERSION
      enum_type_c<ALC_MINOR_VERSION>>
#else
      enum_type_i>
#endif
      minor_version;

    opt_c_api_constant<
      mp_list<alc_integer_query>,
#ifdef ALC_CAPTURE_SAMPLES
      enum_type_c<ALC_CAPTURE_SAMPLES>>
#else
      enum_type_i>
#endif
      capture_samples;

    opt_c_api_constant<
      mp_list<context_attrib>,
#ifdef ALC_FREQUENCY
      enum_type_c<ALC_FREQUENCY>>
#else
      enum_type_i>
#endif
      frequency;

    opt_c_api_constant<
      mp_list<context_attrib>,
#ifdef ALC_REFRESH
      enum_type_c<ALC_REFRESH>>
#else
      enum_type_i>
#endif
      refresh;

    opt_c_api_constant<
      mp_list<context_attrib>,
#ifdef ALC_SYNC
      enum_type_c<ALC_SYNC>>
#else
      enum_type_i>
#endif
      sync;

    opt_c_api_constant<
      mp_list<context_attrib>,
#ifdef ALC_MONO_SOURCES
      enum_type_c<ALC_MONO_SOURCES>>
#else
      enum_type_i>
#endif
      mono_sources;

    opt_c_api_constant<
      mp_list<context_attrib>,
#ifdef ALC_STEREO_SOURCES
      enum_type_c<ALC_STEREO_SOURCES>>
#else
      enum_type_i>
#endif
      stereo_sources;

    const dynamic_c_api_constant<mp_list<context_attrib>, enum_type> hrtf_soft;

    const dynamic_c_api_constant<mp_list<context_attrib>, enum_type>
      hrtf_id_soft;

    const dynamic_c_api_constant<mp_list<alc_string_query>, enum_type>
      hrtf_specifier_soft;

    basic_alc_constants(ApiTraits& traits, basic_alc_c_api<ApiTraits>& api)
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
          "DEFAULT_CAPTURE_DEVICE_SPECIFIER", traits, api)
      , all_devices_specifier("ALL_DEVICES_SPECIFIER", traits, api)
      , default_all_devices_specifier(
          "DEFAULT_ALL_DEVICES_SPECIFIER", traits, api)
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
      , hrtf_specifier_soft("HRTF_SPECIFIER_SOFT", traits, api) {
    }
};
//------------------------------------------------------------------------------
} // namespace oalp
} // namespace eagine

#endif // OALPLUS_ALC_API_CONSTANTS_HPP

