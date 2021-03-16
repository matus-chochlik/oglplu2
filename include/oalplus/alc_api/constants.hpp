/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef OALPLUS_ALC_API_CONSTANTS_HPP
#define OALPLUS_ALC_API_CONSTANTS_HPP

#include "c_api.hpp"
#include "enum_types.hpp"

namespace eagine::oalp {
//------------------------------------------------------------------------------
/// @brief Class wrapping the constants from the ALC API.
/// @ingroup al_api_wrap
/// @see basic_alc_c_api
/// @see basic_alc_operations
template <typename ApiTraits>
class basic_alc_constants {
public:
    using enum_type = typename alc_types::enum_type;
    using enum_type_i = type_identity<enum_type>;
    template <enum_type value>
    using enum_type_c = std::integral_constant<enum_type, value>;

    /// @var no_error
    /// @alcconstwrap{NO_ERROR}
    opt_c_api_constant<
      mp_list<alc_error_code>,
#ifdef ALC_NO_ERROR
      enum_type_c<ALC_NO_ERROR>>
#else
      enum_type_i>
#endif
      no_error;

    /// @var invalid_device
    /// @alcconstwrap{INVALID_DEVICE}
    opt_c_api_constant<
      mp_list<alc_error_code>,
#ifdef ALC_INVALID_DEVICE
      enum_type_c<ALC_INVALID_DEVICE>>
#else
      enum_type_i>
#endif
      invalid_device;

    /// @var invalid_context
    /// @alcconstwrap{INVALID_CONTEXT}
    opt_c_api_constant<
      mp_list<alc_error_code>,
#ifdef ALC_INVALID_CONTEXT
      enum_type_c<ALC_INVALID_CONTEXT>>
#else
      enum_type_i>
#endif
      invalid_context;

    /// @var invalid_enum
    /// @alcconstwrap{INVALID_ENUM}
    opt_c_api_constant<
      mp_list<alc_error_code>,
#ifdef ALC_INVALID_ENUM
      enum_type_c<ALC_INVALID_ENUM>>
#else
      enum_type_i>
#endif
      invalid_enum;

    /// @var invalid_value
    /// @alcconstwrap{INVALID_VALUE}
    opt_c_api_constant<
      mp_list<alc_error_code>,
#ifdef ALC_INVALID_VALUE
      enum_type_c<ALC_INVALID_VALUE>>
#else
      enum_type_i>
#endif
      invalid_value;

    /// @var out_of_memory
    /// @alcconstwrap{OUT_OF_MEMORY}
    opt_c_api_constant<
      mp_list<alc_error_code>,
#ifdef ALC_OUT_OF_MEMORY
      enum_type_c<ALC_OUT_OF_MEMORY>>
#else
      enum_type_i>
#endif
      out_of_memory;

    /// @var device_specifier
    /// @alcconstwrap{DEVICE_SPECIFIER}
    opt_c_api_constant<
      mp_list<alc_string_query>,
#ifdef ALC_DEVICE_SPECIFIER
      enum_type_c<ALC_DEVICE_SPECIFIER>>
#else
      enum_type_i>
#endif
      device_specifier;

    /// @var capture_device_specifier
    /// @alcconstwrap{CAPTURE_DEVICE_SPECIFIER}
    opt_c_api_constant<
      mp_list<alc_string_query>,
#ifdef ALC_CAPTURE_DEVICE_SPECIFIER
      enum_type_c<ALC_CAPTURE_DEVICE_SPECIFIER>>
#else
      enum_type_i>
#endif
      capture_device_specifier;

    /// @var default_device_specifier
    /// @alcconstwrap{DEFAULT_DEVICE_SPECIFIER}
    opt_c_api_constant<
      mp_list<alc_string_query>,
#ifdef ALC_DEFAULT_DEVICE_SPECIFIER
      enum_type_c<ALC_DEFAULT_DEVICE_SPECIFIER>>
#else
      enum_type_i>
#endif
      default_device_specifier;

    /// @var capture_default_device_specifier
    /// @alcconstwrap{CAPTURE_DEFAULT_DEVICE_SPECIFIER}
    opt_c_api_constant<
      mp_list<alc_string_query>,
#ifdef ALC_CAPTURE_DEFAULT_DEVICE_SPECIFIER
      enum_type_c<ALC_CAPTURE_DEFAULT_DEVICE_SPECIFIER>>
#else
      enum_type_i>
#endif
      capture_default_device_specifier;

    /// @var all_devices_specifier
    /// @alcconstwrap{ALL_DEVICES_SPECIFIER}
    const dynamic_c_api_constant<mp_list<alc_string_query>, enum_type>
      all_devices_specifier;

    /// @var default_all_devices_specifier
    /// @alcconstwrap{DEFAULT_ALL_DEVICES_SPECIFIER}
    const dynamic_c_api_constant<mp_list<alc_string_query>, enum_type>
      default_all_devices_specifier;

    /// @var extensions
    /// @alcconstwrap{EXTENSIONS}
    opt_c_api_constant<
      mp_list<alc_string_query>,
#ifdef ALC_EXTENSIONS
      enum_type_c<ALC_EXTENSIONS>>
#else
      enum_type_i>
#endif
      extensions;

    /// @var major_version
    /// @alcconstwrap{MAJOR_VERSION}
    opt_c_api_constant<
      mp_list<alc_integer_query>,
#ifdef ALC_MAJOR_VERSION
      enum_type_c<ALC_MAJOR_VERSION>>
#else
      enum_type_i>
#endif
      major_version;

    /// @var minor_version
    /// @alcconstwrap{MINOR_VERSION}
    opt_c_api_constant<
      mp_list<alc_integer_query>,
#ifdef ALC_MINOR_VERSION
      enum_type_c<ALC_MINOR_VERSION>>
#else
      enum_type_i>
#endif
      minor_version;

    /// @var capture_samples
    /// @alcconstwrap{CAPTURE_SAMPLES}
    opt_c_api_constant<
      mp_list<alc_integer_query>,
#ifdef ALC_CAPTURE_SAMPLES
      enum_type_c<ALC_CAPTURE_SAMPLES>>
#else
      enum_type_i>
#endif
      capture_samples;

    /// @var frequency
    /// @alcconstwrap{FREQUENCY}
    opt_c_api_constant<
      mp_list<context_attribute>,
#ifdef ALC_FREQUENCY
      enum_type_c<ALC_FREQUENCY>>
#else
      enum_type_i>
#endif
      frequency;

    /// @var refresh
    /// @alcconstwrap{REFRESH}
    opt_c_api_constant<
      mp_list<context_attribute>,
#ifdef ALC_REFRESH
      enum_type_c<ALC_REFRESH>>
#else
      enum_type_i>
#endif
      refresh;

    /// @var sync
    /// @alcconstwrap{SYNC}
    opt_c_api_constant<
      mp_list<context_attribute>,
#ifdef ALC_SYNC
      enum_type_c<ALC_SYNC>>
#else
      enum_type_i>
#endif
      sync;

    /// @var mono_sources
    /// @alcconstwrap{MONO_SOURCES}
    opt_c_api_constant<
      mp_list<context_attribute>,
#ifdef ALC_MONO_SOURCES
      enum_type_c<ALC_MONO_SOURCES>>
#else
      enum_type_i>
#endif
      mono_sources;

    /// @var stereo_sources
    /// @alcconstwrap{STEREO_SOURCES}
    opt_c_api_constant<
      mp_list<context_attribute>,
#ifdef ALC_STEREO_SOURCES
      enum_type_c<ALC_STEREO_SOURCES>>
#else
      enum_type_i>
#endif
      stereo_sources;

    /// @var hrtf_soft
    /// @alcconstwrap{HRTF_SOFT}
    const dynamic_c_api_constant<mp_list<context_attribute>, enum_type>
      hrtf_soft;

    /// @var hrtf_id_soft
    /// @alcconstwrap{HRTF_ID_SOFT}
    const dynamic_c_api_constant<mp_list<context_attribute>, enum_type>
      hrtf_id_soft;

    /// @var hrtf_specifier_soft
    /// @alcconstwrap{HRTF_SPECIFIER_SOFT}
    const dynamic_c_api_constant<mp_list<alc_string_query>, enum_type>
      hrtf_specifier_soft;

    basic_alc_constants(ApiTraits& traits, basic_alc_c_api<ApiTraits>& api);
};
//------------------------------------------------------------------------------
} // namespace eagine::oalp

#endif // OALPLUS_ALC_API_CONSTANTS_HPP
