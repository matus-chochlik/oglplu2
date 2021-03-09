/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef EGLPLUS_EGL_API_OUTPUT_LAYER_ATTRIBS_HPP
#define EGLPLUS_EGL_API_OUTPUT_LAYER_ATTRIBS_HPP

#include "config.hpp"
#include "enum_types.hpp"
#include <eagine/key_val_list.hpp>

namespace eagine::eglp {

/// @brief Traits for EGL output layer attribute key/value list traits.
/// @ingroup egl_api_wrap
struct output_layer_attrib_traits {
    /// @brief Alias for the key type.
    using key_type = output_layer_attribute;
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

/// @brief Alias for EGL output layer attribute key/value list.
/// @ingroup egl_api_wrap
template <std::size_t N>
using output_layer_attributes = key_value_list<output_layer_attrib_traits, N>;

/// @brief Alias for EGL output layer attribute list key/value pair.
/// @ingroup egl_api_wrap
/// @see output_layer_attributes
using output_layer_attribute_value =
  key_value_list_element<output_layer_attrib_traits>;

/// @brief Concatenation operator for output layer attribute list key and value.
/// @ingroup egl_api_wrap
/// @relates output_layer_attributes
static constexpr auto
operator|(output_layer_attribute key, egl_types::int_type value) noexcept
  -> output_layer_attribute_value {
    return {key, value};
}

/// @brief Concatenation operator for output layer attribute list key and value.
/// @ingroup egl_api_wrap
/// @relates output_layer_attributes
static constexpr auto operator|(output_layer_attribute key, bool value) noexcept
  -> output_layer_attribute_value {
#if defined(EGL_TRUE) && defined(EGL_FALSE)
    return {key, value ? EGL_TRUE : EGL_FALSE};
#else
    return {key, value ? 1 : 0};
#endif
}

} // namespace eagine::eglp

#endif // EGLPLUS_EGL_API_OUTPUT_LAYER_ATTRIBS_HPP
