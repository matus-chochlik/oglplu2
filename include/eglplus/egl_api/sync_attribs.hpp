/**
 *  @file eglplus/egl_api/sync_attribs.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EGLPLUS_EGL_API_SYNC_ATTRIBS_HPP
#define EGLPLUS_EGL_API_SYNC_ATTRIBS_HPP

#include "config.hpp"
#include "enum_types.hpp"
#include <eagine/key_val_list.hpp>

namespace eagine::eglp {

struct sync_attrib_traits {
    using key_type = sync_attribute;
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
using sync_attributes = key_value_list<sync_attrib_traits, N>;

using sync_attribute_value = key_value_list_element<sync_attrib_traits>;

static constexpr inline auto
operator|(sync_attribute key, egl_types::int_type value) noexcept
  -> sync_attribute_value {
    return {key, value};
}

static constexpr inline auto operator|(sync_attribute key, bool value) noexcept
  -> sync_attribute_value {
#if defined(EGL_TRUE) && defined(EGL_FALSE)
    return {key, value ? EGL_TRUE : EGL_FALSE};
#else
    return {key, value ? 1 : 0};
#endif
}

} // namespace eagine::eglp

#endif // EGLPLUS_EGL_API_SYNC_ATTRIBS_HPP
