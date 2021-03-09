/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef EGLPLUS_EGL_API_SYNC_ATTRIBS_HPP
#define EGLPLUS_EGL_API_SYNC_ATTRIBS_HPP

#include "config.hpp"
#include "enum_types.hpp"
#include <eagine/key_val_list.hpp>

namespace eagine::eglp {

/// @brief Traits for EGL sync object key/value list traits.
/// @ingroup egl_api_wrap
struct sync_attrib_traits {
    /// @brief Alias for the key type.
    using key_type = sync_attribute;
    using conv_type = egl_types::attrib_type;
    /// @brief Alias for the value type.
    using value_type = egl_types::attrib_type;

    static constexpr auto terminator() noexcept -> value_type {
#ifdef EGL_NONE
        return EGL_NONE;
#else
        return 0;
#endif
    }
};

/// @brief Alias for EGL sync object attribute key/value list.
/// @ingroup egl_api_wrap
template <std::size_t N>
using sync_attributes = key_value_list<sync_attrib_traits, N>;

/// @brief Alias for EGL sync object attribute key/value list.
/// @ingroup egl_api_wrap
/// @see sync_attributes
using sync_attribute_value = key_value_list_element<sync_attrib_traits>;

/// @brief Concatenation operator for sync object attribute list key and value.
/// @ingroup egl_api_wrap
/// @relates sync_attributes
static constexpr auto
operator|(sync_attribute key, egl_types::int_type value) noexcept
  -> sync_attribute_value {
    return {key, value};
}

/// @brief Concatenation operator for sync object attribute list key and value.
/// @ingroup egl_api_wrap
/// @relates sync_attributes
static constexpr auto operator|(sync_attribute key, bool value) noexcept
  -> sync_attribute_value {
#if defined(EGL_TRUE) && defined(EGL_FALSE)
    return {key, value ? EGL_TRUE : EGL_FALSE};
#else
    return {key, value ? 1 : 0};
#endif
}

} // namespace eagine::eglp

#endif // EGLPLUS_EGL_API_SYNC_ATTRIBS_HPP
