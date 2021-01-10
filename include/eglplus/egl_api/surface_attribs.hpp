/**
 *  @file eglplus/egl_api/surface_attribs.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EGLPLUS_EGL_API_SURFACE_ATTRIBS_HPP
#define EGLPLUS_EGL_API_SURFACE_ATTRIBS_HPP

#include "config.hpp"
#include "enum_types.hpp"
#include <eagine/key_val_list.hpp>

namespace eagine::eglp {

struct surface_attrib_traits {
    using key_type = surface_attribute;
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
using surface_attributes = key_value_list<surface_attrib_traits, N>;

using surface_attribute_value = key_value_list_element<surface_attrib_traits>;

static constexpr inline auto
operator|(surface_attribute key, egl_types::int_type value) noexcept
  -> surface_attribute_value {
    return {key, value};
}

static constexpr inline auto
operator|(surface_attribute key, texture_format value) noexcept
  -> surface_attribute_value {
    return {key, egl_types::int_type(value)};
}

static constexpr inline auto
operator|(surface_attribute key, texture_target value) noexcept
  -> surface_attribute_value {
    return {key, egl_types::int_type(value)};
}

static constexpr inline auto
operator|(surface_attribute key, gl_colorspace value) noexcept
  -> surface_attribute_value {
    return {key, egl_types::int_type(value)};
}

#if defined(EGL_TRUE) && defined(EGL_FALSE)
static constexpr inline auto
operator|(surface_attribute key, bool value) noexcept
  -> surface_attribute_value {
    return {key, value ? EGL_TRUE : EGL_FALSE};
}
#endif

} // namespace eagine::eglp

#endif // EGLPLUS_EGL_API_SURFACE_ATTRIBS_HPP