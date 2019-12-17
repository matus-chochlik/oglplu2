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
    using enum_type = typename api_types::enum_type;
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

    const dynamic_c_api_constant<
      mp_list<alc_string_query>,
      api_types::enum_type>
      all_devices_specifier;

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

    basic_alc_constants(ApiTraits& traits, basic_alc_c_api<ApiTraits>& api)
      : no_error("NO_ERROR", traits, api)
      , invalid_device("INVALID_DEVICE", traits, api)
      , device_specifier("DEVICE_SPECIFIER", traits, api)
      , capture_device_specifier("CAPTURE_DEVICE_SPECIFIER", traits, api)
      , default_device_specifier("DEFAULT_DEVICE_SPECIFIER", traits, api)
      , capture_default_device_specifier(
          "DEFAULT_CAPTURE_DEVICE_SPECIFIER", traits, api)
      , all_devices_specifier("ALL_DEVICES_SPECIFIER", traits, api)
      , frequency("FREQUENCY", traits, api)
      , refresh("REFRESH", traits, api)
      , sync("SYNC", traits, api)
      , mono_sources("MONO_SOURCES", traits, api)
      , stereo_sources("STEREO_SOURCES", traits, api) {
    }
};
//------------------------------------------------------------------------------
using alc_constants = basic_alc_constants<alc_api_traits>;
//------------------------------------------------------------------------------
} // namespace oalp
} // namespace eagine

#endif // OALPLUS_ALC_API_CONSTANTS_HPP

