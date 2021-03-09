/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef EGLPLUS_EGL_API_CONFIG_ATTRIBS_HPP
#define EGLPLUS_EGL_API_CONFIG_ATTRIBS_HPP

#include "config.hpp"
#include "enum_types.hpp"
#include <eagine/key_val_list.hpp>

namespace eagine::eglp {

/// @brief Traits for EGL configuration attribute key/value list traits.
/// @ingroup egl_api_wrap
struct config_attrib_traits {
    /// @brief Alias for the key type.
    using key_type = config_attribute;
    using conv_type = egl_types::int_type;
    /// @brief Alias for the value type.
    using value_type = egl_types::int_type;

    static constexpr auto terminator() noexcept -> egl_types::int_type {
#ifdef EGL_NONE
        return EGL_NONE;
#else
        return 0;
#endif
    }
};

/// @brief Alias for EGL configuration attribute key/value list.
/// @ingroup egl_api_wrap
template <std::size_t N>
using config_attributes = key_value_list<config_attrib_traits, N>;

/// @brief Alias for EGL config attribute list key/value pair.
/// @ingroup egl_api_wrap
/// @see config_attributes
using config_attribute_value = key_value_list_element<config_attrib_traits>;

/// @brief Concatenation operator for configuration attribute list key and value.
/// @ingroup egl_api_wrap
/// @relates config_attributes
static constexpr auto
operator|(config_attribute key, egl_types::int_type value) noexcept
  -> config_attribute_value {
    return {key, value};
}

/// @brief Concatenation operator for configuration attribute list key and value.
/// @ingroup egl_api_wrap
/// @relates config_attributes
static constexpr auto
operator|(config_attribute key, color_buffer_type value) noexcept
  -> config_attribute_value {
    return {key, egl_types::int_type(value)};
}

/// @brief Concatenation operator for configuration attribute list key and value.
/// @ingroup egl_api_wrap
/// @relates config_attributes
static constexpr auto
operator|(config_attribute key, enum_bitfield<surface_type_bit> value) noexcept
  -> config_attribute_value {
    return {key, egl_types::int_type(value)};
}

/// @brief Concatenation operator for configuration attribute list key and value.
/// @ingroup egl_api_wrap
/// @relates config_attributes
static constexpr auto operator|(
  config_attribute key,
  enum_bitfield<renderable_type_bit> value) noexcept -> config_attribute_value {
    return {key, egl_types::int_type(value)};
}

/// @brief Concatenation operator for configuration attribute list key and value.
/// @ingroup egl_api_wrap
/// @relates config_attributes
static constexpr auto operator|(config_attribute key, bool value) noexcept
  -> config_attribute_value {
#if defined(EGL_TRUE) && defined(EGL_FALSE)
    return {key, value ? EGL_TRUE : EGL_FALSE};
#else
    return {key, value ? 1 : 0};
#endif
}

} // namespace eagine::eglp

#endif // EGLPLUS_EGL_API_CONFIG_ATTRIBS_HPP
