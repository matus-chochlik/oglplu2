/**
 *  @file eglplus/egl_api/config.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EGLPLUS_EGL_API_CONFIG_HPP
#define EGLPLUS_EGL_API_CONFIG_HPP

#include "../config/basic.hpp"

#ifndef EGLPLUS_HAS_EGL
#if defined(EGL_SUCCESS)
#define EGLPLUS_HAS_EGL 1
#else
#define EGLPLUS_HAS_EGL 0
#endif
#endif // EGLPLUS_HAS_EGL

#if !EGLPLUS_HAS_EGL
#include <eagine/nothing.hpp>
#include <cstdint>
#endif

namespace eagine {
namespace eglp {
//------------------------------------------------------------------------------
struct egl_types {
    using char_type = char;
    using void_ptr_type = void*;
#if EGLPLUS_HAS_EGL
    static constexpr bool has_api = true;
    using native_display_type = EGLNativeDisplayType;
    using native_window_type = EGLNativeWindowType;
    using native_pixmap_type = EGLNativePixmapType;
    using client_buffer_type = EGLClientBuffer;
    using display_type = EGLDisplay;
    using config_type = EGLConfig;
    using attrib_type = EGLAttrib;
    using context_type = EGLContext;
    using surface_type = EGLSurface;
    using image_type = EGLImage;
    using sync_type = EGLSync;
    using time_type = EGLTime;
    using bool_type = EGLBoolean;
    using enum_type = EGLenum;
    using int_type = EGLint;
#else
    static constexpr bool has_api = false;
    using native_display_type = nothing_t;
    using native_window_type = nothing_t;
    using native_pixmap_type = nothing_t;
    using client_buffer_type = nothing_t;
    using display_type = nothing_t;
    using config_type = nothing_t;
    using attrib_type = std::intptr_t;
    using context_type = nothing_t;
    using surface_type = nothing_t;
    using image_type = nothing_t;
    using sync_type = nothing_t;
    using time_type = nothing_t;
    using bool_type = bool;
    using enum_type = int;
    using int_type = int;
#endif
};
//------------------------------------------------------------------------------
} // namespace eglp
} // namespace eagine

#endif // EGLPLUS_EGL_API_CONFIG_HPP

