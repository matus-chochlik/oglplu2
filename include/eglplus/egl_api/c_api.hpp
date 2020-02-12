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
    using time_type = typename egl_types::time_type;
    using sync_type = typename egl_types::sync_type;
    using enum_type = typename egl_types::enum_type;
    using bool_type = typename egl_types::bool_type;
    using char_type = typename egl_types::char_type;
    using int_type = typename egl_types::int_type;
    using native_display_type = typename egl_types::native_display_type;
    using native_window_type = typename egl_types::native_window_type;
    using native_pixmap_type = typename egl_types::native_pixmap_type;
    using client_buffer_type = typename egl_types::client_buffer_type;
    using display_type = typename egl_types::display_type;
    using surface_type = typename egl_types::surface_type;
    using config_type = typename egl_types::config_type;
    using attrib_type = typename egl_types::attrib_type;
    using context_type = typename egl_types::context_type;
    using image_type = typename egl_types::image_type;

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
      surface_type(
        display_type, config_type, void_ptr_type, const attrib_type*),
      EGLPLUS_EGL_STATIC_FUNC(CreatePlatformWindowSurface),
      has_api>
      CreatePlatformWindowSurface;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      surface_type(
        display_type, config_type, native_window_type, const int_type*),
      EGLPLUS_EGL_STATIC_FUNC(CreateWindowSurface),
      has_api>
      CreateWindowSurface;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      surface_type(display_type, config_type, const int_type*),
      EGLPLUS_EGL_STATIC_FUNC(CreatePbufferSurface),
      has_api>
      CreatePbufferSurface;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      surface_type(
        display_type, config_type, void_ptr_type, const attrib_type*),
      EGLPLUS_EGL_STATIC_FUNC(CreatePlatformPixmapSurface),
      has_api>
      CreatePlatformPixmapSurface;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      surface_type(
        display_type, config_type, native_pixmap_type, const int_type*),
      EGLPLUS_EGL_STATIC_FUNC(CreatePixmapSurface),
      has_api>
      CreatePixmapSurface;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      bool_type(display_type, surface_type),
      EGLPLUS_EGL_STATIC_FUNC(DestroySurface),
      has_api>
      DestroySurface;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      surface_type(int_type),
      EGLPLUS_EGL_STATIC_FUNC(GetCurrentSurface),
      has_api>
      GetCurrentSurface;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      bool_type(display_type, surface_type, int_type, int_type),
      EGLPLUS_EGL_STATIC_FUNC(SurfaceAttrib),
      has_api>
      SurfaceAttrib;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      bool_type(display_type, surface_type, int_type, int_type*),
      EGLPLUS_EGL_STATIC_FUNC(QuerySurface),
      has_api>
      QuerySurface;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      bool_type(display_type, surface_type, int_type),
      EGLPLUS_EGL_STATIC_FUNC(BindTexImage),
      has_api>
      BindTexImage;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      bool_type(display_type, surface_type, int_type),
      EGLPLUS_EGL_STATIC_FUNC(ReleaseTexImage),
      has_api>
      ReleaseTexImage;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      bool_type(enum_type),
      EGLPLUS_EGL_STATIC_FUNC(BindAPI),
      has_api>
      BindAPI;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      enum_type(),
      EGLPLUS_EGL_STATIC_FUNC(QueryAPI),
      has_api>
      QueryAPI;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      context_type(display_type, config_type, context_type, const int_type*),
      EGLPLUS_EGL_STATIC_FUNC(CreateContext),
      has_api>
      CreateContext;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      bool_type(display_type, context_type),
      EGLPLUS_EGL_STATIC_FUNC(DestroyContext),
      has_api>
      DestroyContext;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      bool_type(display_type, surface_type, surface_type, context_type),
      EGLPLUS_EGL_STATIC_FUNC(MakeCurrent),
      has_api>
      MakeCurrent;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      context_type(),
      EGLPLUS_EGL_STATIC_FUNC(GetCurrentContext),
      has_api>
      GetCurrentContext;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      bool_type(display_type, context_type, int_type, int_type*),
      EGLPLUS_EGL_STATIC_FUNC(QueryContext),
      has_api>
      QueryContext;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      bool_type(),
      EGLPLUS_EGL_STATIC_FUNC(WaitClient),
      has_api>
      WaitClient;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      bool_type(int_type),
      EGLPLUS_EGL_STATIC_FUNC(WaitNative),
      has_api>
      WaitNative;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      sync_type(display_type, enum_type, const attrib_type*),
      EGLPLUS_EGL_STATIC_FUNC(CreateSync),
      has_api>
      CreateSync;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      int_type(display_type, sync_type, int_type, time_type),
      EGLPLUS_EGL_STATIC_FUNC(ClientWaitSync),
      has_api>
      ClientWaitSync;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      bool_type(display_type, sync_type, int_type),
      EGLPLUS_EGL_STATIC_FUNC(WaitSync),
      has_api>
      WaitSync;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      bool_type(display_type, sync_type, int_type, attrib_type*),
      EGLPLUS_EGL_STATIC_FUNC(GetSyncAttrib),
      has_api>
      GetSyncAttrib;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      bool_type(display_type, sync_type),
      EGLPLUS_EGL_STATIC_FUNC(DestroySync),
      has_api>
      DestroySync;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      image_type(
        display_type,
        context_type,
        enum_type,
        client_buffer_type,
        const attrib_type*),
      EGLPLUS_EGL_STATIC_FUNC(CreateImage),
      has_api>
      CreateImage;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      bool_type(display_type, image_type),
      EGLPLUS_EGL_STATIC_FUNC(DestroyImage),
      has_api>
      DestroyImage;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      bool_type(display_type, surface_type, native_pixmap_type),
      EGLPLUS_EGL_STATIC_FUNC(CopyBuffers),
      has_api>
      CopyBuffers;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      bool_type(display_type, int_type),
      EGLPLUS_EGL_STATIC_FUNC(SwapInterval),
      has_api>
      SwapInterval;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      bool_type(display_type, surface_type),
      EGLPLUS_EGL_STATIC_FUNC(SwapBuffers),
      has_api>
      SwapBuffers;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      bool_type(),
      EGLPLUS_EGL_STATIC_FUNC(ReleaseThread),
      has_api>
      ReleaseThread;

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
      , CreatePlatformWindowSurface(
          "CreatePlatformWindowSurface", traits, *this)
      , CreateWindowSurface("CreateWindowSurface", traits, *this)
      , CreatePbufferSurface("CreatePbufferSurface", traits, *this)
      , CreatePlatformPixmapSurface(
          "CreatePlatformPixmapSurface", traits, *this)
      , CreatePixmapSurface("CreatePixmapSurface", traits, *this)
      , DestroySurface("DestroySurface", traits, *this)
      , GetCurrentSurface("GetCurrentSurface", traits, *this)
      , SurfaceAttrib("SurfaceAttrib", traits, *this)
      , QuerySurface("QuerySurface", traits, *this)
      , BindTexImage("BindTexImage", traits, *this)
      , ReleaseTexImage("ReleaseTexImage", traits, *this)
      , BindAPI("BindAPI", traits, *this)
      , QueryAPI("QueryAPI", traits, *this)
      , CreateContext("CreateContext", traits, *this)
      , DestroyContext("DestroyContext", traits, *this)
      , MakeCurrent("MakeCurrent", traits, *this)
      , GetCurrentContext("GetCurrentContext", traits, *this)
      , QueryContext("QueryContext", traits, *this)
      , WaitClient("WaitClient", traits, *this)
      , WaitNative("WaitNative", traits, *this)
      , CreateSync("CreateSync", traits, *this)
      , ClientWaitSync("ClientWaitSync", traits, *this)
      , WaitSync("WaitSync", traits, *this)
      , GetSyncAttrib("GetSyncAttrib", traits, *this)
      , DestroySync("DestroySync", traits, *this)
      , CreateImage("CreateImage", traits, *this)
      , DestroyImage("DestroyImage", traits, *this)
      , CopyBuffers("CopyBuffers", traits, *this)
      , SwapInterval("SwapInterval", traits, *this)
      , SwapBuffers("SwapBuffers", traits, *this)
      , ReleaseThread("ReleaseThread", traits, *this) {
    }
};
//------------------------------------------------------------------------------
using egl_c_api = basic_egl_c_api<egl_api_traits>;
//------------------------------------------------------------------------------
} // namespace eglp
} // namespace eagine

#endif // EGLPLUS_EGL_API_C_API_HPP

