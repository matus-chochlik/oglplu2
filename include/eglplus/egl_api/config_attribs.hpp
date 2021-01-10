/**
 *  @file eglplus/egl_api/config_attribs.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EGLPLUS_EGL_API_CONFIG_ATTRIBS_HPP
#define EGLPLUS_EGL_API_CONFIG_ATTRIBS_HPP

#include "config.hpp"
#include "enum_types.hpp"
#include <eagine/key_val_list.hpp>

namespace eagine::eglp {

struct config_attrib_traits {
    using key_type = config_attribute;
    using conv_type = egl_types::int_type;
    using value_type = egl_types::int_type;

    static constexpr auto terminator() noexcept -> egl_types::int_type {
#ifdef EGL_NONE
        return EGL_NONE;
#else
        return 0;
#endif
    }
};

template <std::size_t N>
using config_attributes = key_value_list<config_attrib_traits, N>;

using config_attribute_value = key_value_list_element<config_attrib_traits>;

static constexpr inline auto
operator|(config_attribute key, egl_types::int_type value) noexcept
  -> config_attribute_value {
    return {key, value};
}

static constexpr inline auto
operator|(config_attribute key, color_buffer_type value) noexcept
  -> config_attribute_value {
    return {key, egl_types::int_type(value)};
}

static constexpr inline auto
operator|(config_attribute key, enum_bitfield<surface_type_bit> value) noexcept
  -> config_attribute_value {
    return {key, egl_types::int_type(value)};
}

static constexpr inline auto operator|(
  config_attribute key,
  enum_bitfield<renderable_type_bit> value) noexcept -> config_attribute_value {
    return {key, egl_types::int_type(value)};
}

#if defined(EGL_TRUE) && defined(EGL_FALSE)
static constexpr inline auto
operator|(config_attribute key, bool value) noexcept -> config_attribute_value {
    return {key, value ? EGL_TRUE : EGL_FALSE};
}
#endif

} // namespace eagine::eglp

#endif // EGLPLUS_EGL_API_CONFIG_ATTRIBS_HPP
