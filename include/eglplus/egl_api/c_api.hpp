/**
 *  @file eglplus/egl_api/c_api.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EGLPLUS_EGL_API_C_API_HPP
#define EGLPLUS_EGL_API_C_API_HPP

#include "api_traits.hpp"
#include "config.hpp"
#include <eagine/nothing.hpp>
#include <eagine/preprocessor.hpp>

#ifndef EGLPLUS_EGL_STATIC_FUNC
#if EGLPLUS_HAS_EGL
#define EGLPLUS_EGL_STATIC_FUNC(NAME) &EAGINE_JOIN(::egl, NAME)
#else
#define EGLPLUS_EGL_STATIC_FUNC(NAME) nullptr
#endif
#endif

namespace eagine {
namespace eglp {
//------------------------------------------------------------------------------
template <typename Traits>
struct basic_egl_c_api {

    using this_api = basic_egl_c_api;
    using api_traits = Traits;

    static constexpr bool has_api = egl_types::has_api;
    using void_ptr_type = typename egl_types::void_ptr_type;
    using enum_type = typename egl_types::enum_type;
    using bool_type = typename egl_types::bool_type;
    using char_type = typename egl_types::char_type;
    using int_type = typename egl_types::int_type;
    using native_display_type = typename egl_types::native_display_type;
    using display_type = typename egl_types::display_type;
    using surface_type = typename egl_types::surface_type;
    using config_type = typename egl_types::config_type;
    using attrib_type = typename egl_types::attrib_type;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      int_type(),
      EGLPLUS_EGL_STATIC_FUNC(GetError),
      has_api>
      GetError;

    static constexpr bool success(int_type ec) noexcept {
#ifdef EGL_SUCCESS
        return ec == EGL_SUCCESS;
#else
        EAGINE_MAYBE_UNUSED(ec);
        return false;
#endif
    }

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      void (*(const char_type*))(),
      EGLPLUS_EGL_STATIC_FUNC(GetProcAddress),
      has_api>
      GetProcAddress;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      display_type(enum_type, void_ptr_type, const attrib_type*),
      EGLPLUS_EGL_STATIC_FUNC(GetPlatformDisplay),
      has_api>
      GetPlatformDisplay;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      display_type(native_display_type),
      EGLPLUS_EGL_STATIC_FUNC(GetDisplay),
      has_api>
      GetDisplay;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      bool_type(display_type, int_type*, int_type*),
      EGLPLUS_EGL_STATIC_FUNC(Initialize),
      has_api>
      Initialize;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      bool_type(display_type),
      EGLPLUS_EGL_STATIC_FUNC(Terminate),
      has_api>
      Terminate;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      const char_type*(display_type, int_type),
      EGLPLUS_EGL_STATIC_FUNC(QueryString),
      has_api>
      QueryString;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      bool_type(display_type, config_type*, int_type, int_type*),
      EGLPLUS_EGL_STATIC_FUNC(GetConfigs),
      has_api>
      GetConfigs;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      bool_type(
        display_type, const int_type*, config_type*, int_type, int_type*),
      EGLPLUS_EGL_STATIC_FUNC(ChooseConfig),
      has_api>
      ChooseConfig;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      bool_type(display_type, config_type, int_type, int_type*),
      EGLPLUS_EGL_STATIC_FUNC(GetConfigAttrib),
      has_api>
      GetConfigAttrib;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      bool_type(display_type, surface_type),
      EGLPLUS_EGL_STATIC_FUNC(SwapBuffers),
      has_api>
      SwapBuffers;

    constexpr basic_egl_c_api(api_traits& traits)
      : GetError("GetError", traits, *this)
      , GetProcAddress("GetEnumValue", traits, *this)
      , GetPlatformDisplay("GetPlatformDisplay", traits, *this)
      , GetDisplay("GetDisplay", traits, *this)
      , Initialize("Initialize", traits, *this)
      , Terminate("Terminate", traits, *this)
      , QueryString("QueryString", traits, *this)
      , GetConfigs("GetConfigs", traits, *this)
      , ChooseConfig("ChooseConfig", traits, *this)
      , GetConfigAttrib("GetConfigAttrib", traits, *this)
      , SwapBuffers("SwapBuffers", traits, *this) {
    }
};
//------------------------------------------------------------------------------
using egl_c_api = basic_egl_c_api<egl_api_traits>;
//------------------------------------------------------------------------------
} // namespace eglp
} // namespace eagine

#endif // EGLPLUS_EGL_API_C_API_HPP

