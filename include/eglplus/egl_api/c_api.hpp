/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
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

namespace eagine::eglp {
//------------------------------------------------------------------------------
template <typename ApiTraits>
class basic_egl_c_api {
public:
    using this_api = basic_egl_c_api;
    using api_traits = ApiTraits;

    static constexpr bool has_api = egl_types::has_api;
    using void_ptr_type = typename egl_types::void_ptr_type;
    using time_type = typename egl_types::time_type;
    using sync_type = typename egl_types::sync_type;
    using enum_type = typename egl_types::enum_type;
    using bool_type = typename egl_types::bool_type;
    using char_type = typename egl_types::char_type;
    using int_type = typename egl_types::int_type;
    using device_type = typename egl_types::device_type;
    using native_display_type = typename egl_types::native_display_type;
    using native_window_type = typename egl_types::native_window_type;
    using native_pixmap_type = typename egl_types::native_pixmap_type;
    using client_buffer_type = typename egl_types::client_buffer_type;
    using display_type = typename egl_types::display_type;
    using surface_type = typename egl_types::surface_type;
    using config_type = typename egl_types::config_type;
    using attrib_type = typename egl_types::attrib_type;
    using context_type = typename egl_types::context_type;
    using stream_type = typename egl_types::stream_type;
    using output_layer_type = typename egl_types::output_layer_type;
    using output_port_type = typename egl_types::output_port_type;
    using image_type = typename egl_types::image_type;

#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Waddress"
#endif
    template <
      typename Signature,
      c_api_function_ptr<api_traits, nothing_t, Signature> Function>
    using egl_api_function = eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      Signature,
      Function,
      has_api,
      bool(Function)>;
#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif

    egl_api_function<int_type(), EGLPLUS_EGL_STATIC_FUNC(GetError)> GetError;

    egl_api_function<
      void (*(const char_type*))(),
      EGLPLUS_EGL_STATIC_FUNC(GetProcAddress)>
      GetProcAddress;

    egl_api_function<bool_type(int_type, device_type, int_type*), nullptr>
      QueryDevices;

    egl_api_function<const char_type*(device_type, int_type), nullptr>
      QueryDeviceString;

    egl_api_function<
      display_type(enum_type, void_ptr_type, const attrib_type*),
      EGLPLUS_EGL_STATIC_FUNC(GetPlatformDisplay)>
      GetPlatformDisplay;

    egl_api_function<
      display_type(native_display_type),
      EGLPLUS_EGL_STATIC_FUNC(GetDisplay)>
      GetDisplay;

    egl_api_function<const char_type*(display_type), nullptr>
      GetDisplayDriverName;

    egl_api_function<
      bool_type(display_type, int_type*, int_type*),
      EGLPLUS_EGL_STATIC_FUNC(Initialize)>
      Initialize;

    egl_api_function<bool_type(display_type), EGLPLUS_EGL_STATIC_FUNC(Terminate)>
      Terminate;

    egl_api_function<
      const char_type*(display_type, int_type),
      EGLPLUS_EGL_STATIC_FUNC(QueryString)>
      QueryString;

    egl_api_function<
      bool_type(display_type, config_type*, int_type, int_type*),
      EGLPLUS_EGL_STATIC_FUNC(GetConfigs)>
      GetConfigs;

    egl_api_function<
      bool_type(display_type, const int_type*, config_type*, int_type, int_type*),
      EGLPLUS_EGL_STATIC_FUNC(ChooseConfig)>
      ChooseConfig;

    egl_api_function<
      bool_type(display_type, config_type, int_type, int_type*),
      EGLPLUS_EGL_STATIC_FUNC(GetConfigAttrib)>
      GetConfigAttrib;

    egl_api_function<
      surface_type(display_type, config_type, void_ptr_type, const attrib_type*),
      EGLPLUS_EGL_STATIC_FUNC(CreatePlatformWindowSurface)>
      CreatePlatformWindowSurface;

    egl_api_function<
      surface_type(display_type, config_type, native_window_type, const int_type*),
      EGLPLUS_EGL_STATIC_FUNC(CreateWindowSurface)>
      CreateWindowSurface;

    egl_api_function<
      surface_type(display_type, config_type, const int_type*),
      EGLPLUS_EGL_STATIC_FUNC(CreatePbufferSurface)>
      CreatePbufferSurface;

    egl_api_function<
      surface_type(display_type, config_type, void_ptr_type, const attrib_type*),
      EGLPLUS_EGL_STATIC_FUNC(CreatePlatformPixmapSurface)>
      CreatePlatformPixmapSurface;

    egl_api_function<
      surface_type(display_type, config_type, native_pixmap_type, const int_type*),
      EGLPLUS_EGL_STATIC_FUNC(CreatePixmapSurface)>
      CreatePixmapSurface;

    egl_api_function<
      surface_type(display_type, config_type, stream_type, const int_type*),
      nullptr>
      CreateStreamProducerSurface;

    egl_api_function<
      bool_type(display_type, surface_type),
      EGLPLUS_EGL_STATIC_FUNC(DestroySurface)>
      DestroySurface;

    egl_api_function<
      surface_type(int_type),
      EGLPLUS_EGL_STATIC_FUNC(GetCurrentSurface)>
      GetCurrentSurface;

    egl_api_function<
      bool_type(display_type, surface_type, int_type, int_type),
      EGLPLUS_EGL_STATIC_FUNC(SurfaceAttrib)>
      SurfaceAttrib;

    egl_api_function<
      bool_type(display_type, surface_type, int_type, int_type*),
      EGLPLUS_EGL_STATIC_FUNC(QuerySurface)>
      QuerySurface;

    egl_api_function<surface_type(display_type, const int_type*), nullptr>
      CreateStream;

    egl_api_function<surface_type(display_type, stream_type), nullptr>
      DestroyStream;

    egl_api_function<
      bool_type(display_type, stream_type, int_type, int_type),
      nullptr>
      StreamAttrib;

    egl_api_function<
      bool_type(display_type, stream_type, int_type, int_type*),
      nullptr>
      QueryStream;

    egl_api_function<bool_type(display_type, stream_type), nullptr>
      StreamConsumerGLTextureExternal;

    egl_api_function<bool_type(display_type, stream_type), nullptr>
      StreamConsumerAcquire;

    egl_api_function<bool_type(display_type, stream_type), nullptr>
      StreamConsumerRelease;

    egl_api_function<
      bool_type(
        display_type,
        const attrib_type*,
        output_layer_type*,
        int_type,
        int_type*),
      nullptr>
      GetOutputLayers;

    egl_api_function<
      bool_type(display_type, output_layer_type, int_type, attrib_type),
      nullptr>
      OutputLayerAttrib;

    egl_api_function<
      bool_type(display_type, output_layer_type, int_type, attrib_type*),
      nullptr>
      QueryOutputLayerAttrib;

    egl_api_function<
      const char_type*(display_type, output_layer_type, int_type),
      nullptr>
      QueryOutputLayerString;

    egl_api_function<
      bool_type(
        display_type,
        const attrib_type*,
        output_port_type*,
        int_type,
        int_type*),
      nullptr>
      GetOutputPorts;

    egl_api_function<
      bool_type(display_type, output_port_type, int_type, attrib_type),
      nullptr>
      OutputPortAttrib;

    egl_api_function<
      bool_type(display_type, output_port_type, int_type, attrib_type*),
      nullptr>
      QueryOutputPortAttrib;

    egl_api_function<
      const char_type*(display_type, output_port_type, int_type),
      nullptr>
      QueryOutputPortString;

    egl_api_function<
      bool_type(display_type, surface_type, int_type),
      EGLPLUS_EGL_STATIC_FUNC(BindTexImage)>
      BindTexImage;

    egl_api_function<
      bool_type(display_type, surface_type, int_type),
      EGLPLUS_EGL_STATIC_FUNC(ReleaseTexImage)>
      ReleaseTexImage;

    egl_api_function<bool_type(enum_type), EGLPLUS_EGL_STATIC_FUNC(BindAPI)>
      BindAPI;

    egl_api_function<enum_type(), EGLPLUS_EGL_STATIC_FUNC(QueryAPI)> QueryAPI;

    egl_api_function<
      context_type(display_type, config_type, context_type, const int_type*),
      EGLPLUS_EGL_STATIC_FUNC(CreateContext)>
      CreateContext;

    egl_api_function<
      bool_type(display_type, context_type),
      EGLPLUS_EGL_STATIC_FUNC(DestroyContext)>
      DestroyContext;

    egl_api_function<
      bool_type(display_type, surface_type, surface_type, context_type),
      EGLPLUS_EGL_STATIC_FUNC(MakeCurrent)>
      MakeCurrent;

    egl_api_function<context_type(), EGLPLUS_EGL_STATIC_FUNC(GetCurrentContext)>
      GetCurrentContext;

    egl_api_function<
      bool_type(display_type, context_type, int_type, int_type*),
      EGLPLUS_EGL_STATIC_FUNC(QueryContext)>
      QueryContext;

    egl_api_function<bool_type(), EGLPLUS_EGL_STATIC_FUNC(WaitClient)>
      WaitClient;

    egl_api_function<bool_type(int_type), EGLPLUS_EGL_STATIC_FUNC(WaitNative)>
      WaitNative;

    egl_api_function<
      sync_type(display_type, enum_type, const attrib_type*),
      EGLPLUS_EGL_STATIC_FUNC(CreateSync)>
      CreateSync;

    egl_api_function<
      int_type(display_type, sync_type, int_type, time_type),
      EGLPLUS_EGL_STATIC_FUNC(ClientWaitSync)>
      ClientWaitSync;

    egl_api_function<
      bool_type(display_type, sync_type, int_type),
      EGLPLUS_EGL_STATIC_FUNC(WaitSync)>
      WaitSync;

    egl_api_function<
      bool_type(display_type, sync_type, int_type, attrib_type*),
      EGLPLUS_EGL_STATIC_FUNC(GetSyncAttrib)>
      GetSyncAttrib;

    egl_api_function<
      bool_type(display_type, sync_type),
      EGLPLUS_EGL_STATIC_FUNC(DestroySync)>
      DestroySync;

    egl_api_function<
      image_type(
        display_type,
        context_type,
        enum_type,
        client_buffer_type,
        const attrib_type*),
      EGLPLUS_EGL_STATIC_FUNC(CreateImage)>
      CreateImage;

    egl_api_function<
      bool_type(display_type, image_type),
      EGLPLUS_EGL_STATIC_FUNC(DestroyImage)>
      DestroyImage;

    egl_api_function<
      bool_type(display_type, surface_type, native_pixmap_type),
      EGLPLUS_EGL_STATIC_FUNC(CopyBuffers)>
      CopyBuffers;

    egl_api_function<
      bool_type(display_type, int_type),
      EGLPLUS_EGL_STATIC_FUNC(SwapInterval)>
      SwapInterval;

    egl_api_function<
      bool_type(display_type, surface_type),
      EGLPLUS_EGL_STATIC_FUNC(SwapBuffers)>
      SwapBuffers;

    egl_api_function<
      bool_type(display_type, surface_type, const int_type*, int_type),
      nullptr>
      SwapBuffersWithDamage;

    egl_api_function<bool_type(), EGLPLUS_EGL_STATIC_FUNC(ReleaseThread)>
      ReleaseThread;

    basic_egl_c_api(api_traits& traits);
};
//------------------------------------------------------------------------------
using egl_c_api = basic_egl_c_api<egl_api_traits>;
//------------------------------------------------------------------------------
} // namespace eagine::eglp

#endif // EGLPLUS_EGL_API_C_API_HPP
