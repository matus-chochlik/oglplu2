/// @file eglplus/egl_api/output_port_attribs.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef EGLPLUS_EGL_API_OUTPUT_PORT_ATTRIBS_HPP
#define EGLPLUS_EGL_API_OUTPUT_PORT_ATTRIBS_HPP

#include "config.hpp"
#include "enum_types.hpp"
#include <eagine/key_val_list.hpp>

namespace eagine::eglp {

struct output_port_attrib_traits {
    using key_type = output_port_attribute;
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
using output_port_attributes = key_value_list<output_port_attrib_traits, N>;

using output_port_attribute_value =
  key_value_list_element<output_port_attrib_traits>;

static constexpr auto
operator|(output_port_attribute key, egl_types::int_type value) noexcept
  -> output_port_attribute_value {
    return {key, value};
}

static constexpr auto operator|(output_port_attribute key, bool value) noexcept
  -> output_port_attribute_value {
#if defined(EGL_TRUE) && defined(EGL_FALSE)
    return {key, value ? EGL_TRUE : EGL_FALSE};
#else
    return {key, value ? 1 : 0};
#endif
}

} // namespace eagine::eglp

#endif // EGLPLUS_EGL_API_OUTPUT_PORT_ATTRIBS_HPP
