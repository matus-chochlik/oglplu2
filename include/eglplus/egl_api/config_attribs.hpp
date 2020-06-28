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

namespace eagine {
namespace eglp {

struct config_attrib_traits {
    using key_type = config_attribute;
    using conv_type = egl_types::int_type;
    using value_type = egl_types::int_type;

    static constexpr inline egl_types::int_type terminator() noexcept {
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

static constexpr inline config_attribute_value operator|(
  config_attribute key, egl_types::int_type value) noexcept {
    return {key, value};
}

static constexpr inline config_attribute_value operator|(
  config_attribute key, enum_bitfield<surface_type_bit> value) noexcept {
    return {key, egl_types::int_type(value)};
}

static constexpr inline config_attribute_value operator|(
  config_attribute key, enum_bitfield<client_api_bit> value) noexcept {
    return {key, egl_types::int_type(value)};
}

#if defined(EGL_TRUE) && defined(EGL_FALSE)
static constexpr inline config_attribute_value operator|(
  config_attribute key, bool value) noexcept {
    return {key, value ? EGL_TRUE : EGL_FALSE};
}
#endif

} // namespace eglp
} // namespace eagine

#endif // EGLPLUS_EGL_API_CONFIG_ATTRIBS_HPP
