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
#include <eagine/diagnostic.hpp>
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
/// @brief Class wrapping the C-functions from the EGL API.
/// @ingroup egl_api_wrap
/// @see basic_egl_constants
/// @see basic_egl_operations
template <typename ApiTraits>
class basic_egl_c_api {
public:
    using this_api = basic_egl_c_api;

    /// @brief Alias for the API traits policy type passed as template argument.
    using api_traits = ApiTraits;

    static constexpr bool has_api = egl_types::has_api;

    /// @brief Untyped non-const pointer type.
    using void_ptr_type = typename egl_types::void_ptr_type;

    /// @brief Alias for time duration type.
    using time_type = typename egl_types::time_type;

    /// @brief Alias for sync type.
    using sync_type = typename egl_types::sync_type;

    /// @brief Alias for enumeration type.
    using enum_type = typename egl_types::enum_type;

    /// @brief Alias for boolean type.
    using bool_type = typename egl_types::bool_type;

    /// @brief Alias for string character type.
    using char_type = typename egl_types::char_type;

    /// @brief Alias for signed integer type.
    using int_type = typename egl_types::int_type;

    /// @brief Alias for device handle type.
    using device_type = typename egl_types::device_type;

    /// @brief Alias for native display handle type.
    using native_display_type = typename egl_types::native_display_type;

    /// @brief Alias for native window handle type.
    using native_window_type = typename egl_types::native_window_type;

    /// @brief Alias for native pixmap handle type.
    using native_pixmap_type = typename egl_types::native_pixmap_type;

    /// @brief Alias for client buffer handle type.
    using client_buffer_type = typename egl_types::client_buffer_type;

    /// @brief Alias for display handle type.
    using display_type = typename egl_types::display_type;

    /// @brief Alias for surface handle type.
    using surface_type = typename egl_types::surface_type;

    /// @brief Alias for config handle type.
    using config_type = typename egl_types::config_type;

    /// @brief Alias for attribute type.
    using attrib_type = typename egl_types::attrib_type;

    /// @brief Alias for context handle type.
    using context_type = typename egl_types::context_type;

    /// @brief Alias for stream handle type.
    using stream_type = typename egl_types::stream_type;

    /// @brief Alias for output layer handle type.
    using output_layer_type = typename egl_types::output_layer_type;

    /// @brief Alias for output port handle type.
    using output_port_type = typename egl_types::output_port_type;

    /// @brief Alias for image handle type.
    using image_type = typename egl_types::image_type;

#ifdef __GNUC__
    EAGINE_DIAG_PUSH()
    EAGINE_DIAG_OFF(address)
#endif

    /// @brief Alias for EGL C-API function wrapper template.
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
    EAGINE_DIAG_POP()
#endif

    /// @var GetError
    /// @eglfuncwrap{GetError}
    egl_api_function<int_type(), EGLPLUS_EGL_STATIC_FUNC(GetError)> GetError;

    /// @var GetProcAddress
    /// @eglfuncwrap{GetProcAddress}
    egl_api_function<
      void (*(const char_type*))(),
      EGLPLUS_EGL_STATIC_FUNC(GetProcAddress)>
      GetProcAddress;

    /// @var QueryDevices
    /// @eglfuncwrap{QueryDevices}
    egl_api_function<bool_type(int_type, device_type, int_type*), nullptr>
      QueryDevices;

    /// @var QueryDeviceString
    /// @eglfuncwrap{QueryDeviceString}
    egl_api_function<const char_type*(device_type, int_type), nullptr>
      QueryDeviceString;

    /// @var GetPlatformDisplay
    /// @eglfuncwrap{GetPlatformDisplay}
    egl_api_function<
      display_type(enum_type, void_ptr_type, const attrib_type*),
      EGLPLUS_EGL_STATIC_FUNC(GetPlatformDisplay)>
      GetPlatformDisplay;

    /// @var GetDisplay
    /// @eglfuncwrap{GetDisplay}
    egl_api_function<
      display_type(native_display_type),
      EGLPLUS_EGL_STATIC_FUNC(GetDisplay)>
      GetDisplay;

    /// @var GetDisplayDriverName
    /// @eglfuncwrap{GetDisplayDriverName}
    egl_api_function<const char_type*(display_type), nullptr>
      GetDisplayDriverName;

    /// @var Initialize
    /// @eglfuncwrap{Initialize}
    egl_api_function<
      bool_type(display_type, int_type*, int_type*),
      EGLPLUS_EGL_STATIC_FUNC(Initialize)>
      Initialize;

    /// @var Terminate
    /// @eglfuncwrap{Terminate}
    egl_api_function<bool_type(display_type), EGLPLUS_EGL_STATIC_FUNC(Terminate)>
      Terminate;

    /// @var QueryString
    /// @eglfuncwrap{QueryString}
    egl_api_function<
      const char_type*(display_type, int_type),
      EGLPLUS_EGL_STATIC_FUNC(QueryString)>
      QueryString;

    /// @var GetConfigs
    /// @eglfuncwrap{GetConfigs}
    egl_api_function<
      bool_type(display_type, config_type*, int_type, int_type*),
      EGLPLUS_EGL_STATIC_FUNC(GetConfigs)>
      GetConfigs;

    /// @var ChooseConfig
    /// @eglfuncwrap{ChooseConfig}
    egl_api_function<
      bool_type(display_type, const int_type*, config_type*, int_type, int_type*),
      EGLPLUS_EGL_STATIC_FUNC(ChooseConfig)>
      ChooseConfig;

    /// @var GetConfigAttrib
    /// @eglfuncwrap{GetConfigAttrib}
    egl_api_function<
      bool_type(display_type, config_type, int_type, int_type*),
      EGLPLUS_EGL_STATIC_FUNC(GetConfigAttrib)>
      GetConfigAttrib;

    /// @var CreatePlatformWindowSurface
    /// @eglfuncwrap{CreatePlatformWindowSurface}
    egl_api_function<
      surface_type(display_type, config_type, void_ptr_type, const attrib_type*),
      EGLPLUS_EGL_STATIC_FUNC(CreatePlatformWindowSurface)>
      CreatePlatformWindowSurface;

    /// @var CreateWindowSurface
    /// @eglfuncwrap{CreateWindowSurface}
    egl_api_function<
      surface_type(display_type, config_type, native_window_type, const int_type*),
      EGLPLUS_EGL_STATIC_FUNC(CreateWindowSurface)>
      CreateWindowSurface;

    /// @var CreatePbufferSurface
    /// @eglfuncwrap{CreatePbufferSurface}
    egl_api_function<
      surface_type(display_type, config_type, const int_type*),
      EGLPLUS_EGL_STATIC_FUNC(CreatePbufferSurface)>
      CreatePbufferSurface;

    /// @var CreatePlatformPixmapSurface
    /// @eglfuncwrap{CreatePlatformPixmapSurface}
    egl_api_function<
      surface_type(display_type, config_type, void_ptr_type, const attrib_type*),
      EGLPLUS_EGL_STATIC_FUNC(CreatePlatformPixmapSurface)>
      CreatePlatformPixmapSurface;

    /// @var CreatePixmapSurface
    /// @eglfuncwrap{CreatePixmapSurface}
    egl_api_function<
      surface_type(display_type, config_type, native_pixmap_type, const int_type*),
      EGLPLUS_EGL_STATIC_FUNC(CreatePixmapSurface)>
      CreatePixmapSurface;

    /// @var CreateStreamProducerSurface
    /// @eglfuncwrap{CreateStreamProducerSurface}
    egl_api_function<
      surface_type(display_type, config_type, stream_type, const int_type*),
      nullptr>
      CreateStreamProducerSurface;

    /// @var DestroySurface
    /// @eglfuncwrap{DestroySurface}
    egl_api_function<
      bool_type(display_type, surface_type),
      EGLPLUS_EGL_STATIC_FUNC(DestroySurface)>
      DestroySurface;

    /// @var GetCurrentSurface
    /// @eglfuncwrap{GetCurrentSurface}
    egl_api_function<
      surface_type(int_type),
      EGLPLUS_EGL_STATIC_FUNC(GetCurrentSurface)>
      GetCurrentSurface;

    /// @var SurfaceAttrib
    /// @eglfuncwrap{SurfaceAttrib}
    egl_api_function<
      bool_type(display_type, surface_type, int_type, int_type),
      EGLPLUS_EGL_STATIC_FUNC(SurfaceAttrib)>
      SurfaceAttrib;

    /// @var QuerySurface
    /// @eglfuncwrap{QuerySurface}
    egl_api_function<
      bool_type(display_type, surface_type, int_type, int_type*),
      EGLPLUS_EGL_STATIC_FUNC(QuerySurface)>
      QuerySurface;

    /// @var CreateStream
    /// @eglfuncwrap{CreateStream}
    egl_api_function<surface_type(display_type, const int_type*), nullptr>
      CreateStream;

    /// @var DestroyStream
    /// @eglfuncwrap{DestroyStream}
    egl_api_function<surface_type(display_type, stream_type), nullptr>
      DestroyStream;

    /// @var StreamAttrib
    /// @eglfuncwrap{StreamAttrib}
    egl_api_function<
      bool_type(display_type, stream_type, int_type, int_type),
      nullptr>
      StreamAttrib;

    /// @var QueryStream
    /// @eglfuncwrap{QueryStream}
    egl_api_function<
      bool_type(display_type, stream_type, int_type, int_type*),
      nullptr>
      QueryStream;

    /// @var StreamConsumerGLTextureExternal
    /// @eglfuncwrap{StreamConsumerGLTextureExternal}
    egl_api_function<bool_type(display_type, stream_type), nullptr>
      StreamConsumerGLTextureExternal;

    /// @var StreamConsumerAcquire
    /// @eglfuncwrap{GetErrorsumerAcquire}
    egl_api_function<bool_type(display_type, stream_type), nullptr>
      StreamConsumerAcquire;

    /// @var StreamConsumerRelease
    /// @eglfuncwrap{StreamConsumerRelease}
    egl_api_function<bool_type(display_type, stream_type), nullptr>
      StreamConsumerRelease;

    /// @var GetOutputLayers
    /// @eglfuncwrap{GetOutputLayers}
    egl_api_function<
      bool_type(
        display_type,
        const attrib_type*,
        output_layer_type*,
        int_type,
        int_type*),
      nullptr>
      GetOutputLayers;

    /// @var OutputLayerAttrib
    /// @eglfuncwrap{OutputLayerAttrib}
    egl_api_function<
      bool_type(display_type, output_layer_type, int_type, attrib_type),
      nullptr>
      OutputLayerAttrib;

    /// @var QueryOutputLayerAttrib
    /// @eglfuncwrap{QueryOutputLayerAttrib}
    egl_api_function<
      bool_type(display_type, output_layer_type, int_type, attrib_type*),
      nullptr>
      QueryOutputLayerAttrib;

    /// @var QueryOutputLayerString
    /// @eglfuncwrap{QueryOutputLayerString}
    egl_api_function<
      const char_type*(display_type, output_layer_type, int_type),
      nullptr>
      QueryOutputLayerString;

    /// @var GetOutputPorts
    /// @eglfuncwrap{GetOutputPorts}
    egl_api_function<
      bool_type(
        display_type,
        const attrib_type*,
        output_port_type*,
        int_type,
        int_type*),
      nullptr>
      GetOutputPorts;

    /// @var OutputPortAttrib
    /// @eglfuncwrap{OutputPortAttrib}
    egl_api_function<
      bool_type(display_type, output_port_type, int_type, attrib_type),
      nullptr>
      OutputPortAttrib;

    /// @var QueryOutputPortAttrib
    /// @eglfuncwrap{QueryOutputPortAttrib}
    egl_api_function<
      bool_type(display_type, output_port_type, int_type, attrib_type*),
      nullptr>
      QueryOutputPortAttrib;

    /// @var QueryOutputPortString
    /// @eglfuncwrap{QueryOutputPortString}
    egl_api_function<
      const char_type*(display_type, output_port_type, int_type),
      nullptr>
      QueryOutputPortString;

    /// @var BindTexImage
    /// @eglfuncwrap{BindTexImage}
    egl_api_function<
      bool_type(display_type, surface_type, int_type),
      EGLPLUS_EGL_STATIC_FUNC(BindTexImage)>
      BindTexImage;

    /// @var ReleaseTexImage
    /// @eglfuncwrap{ReleaseTexImage}
    egl_api_function<
      bool_type(display_type, surface_type, int_type),
      EGLPLUS_EGL_STATIC_FUNC(ReleaseTexImage)>
      ReleaseTexImage;

    /// @var BindAPI
    /// @eglfuncwrap{BindAPI}
    egl_api_function<bool_type(enum_type), EGLPLUS_EGL_STATIC_FUNC(BindAPI)>
      BindAPI;

    /// @var QueryAPI
    /// @eglfuncwrap{QueryAPI}
    egl_api_function<enum_type(), EGLPLUS_EGL_STATIC_FUNC(QueryAPI)> QueryAPI;

    /// @var CreateContext
    /// @eglfuncwrap{CreateContext}
    egl_api_function<
      context_type(display_type, config_type, context_type, const int_type*),
      EGLPLUS_EGL_STATIC_FUNC(CreateContext)>
      CreateContext;

    /// @var DestroyContext
    /// @eglfuncwrap{DestroyContext}
    egl_api_function<
      bool_type(display_type, context_type),
      EGLPLUS_EGL_STATIC_FUNC(DestroyContext)>
      DestroyContext;

    /// @var MakeCurrent
    /// @eglfuncwrap{MakeCurrent}
    egl_api_function<
      bool_type(display_type, surface_type, surface_type, context_type),
      EGLPLUS_EGL_STATIC_FUNC(MakeCurrent)>
      MakeCurrent;

    /// @var GetCurrentContext
    /// @eglfuncwrap{GetCurrentContext}
    egl_api_function<context_type(), EGLPLUS_EGL_STATIC_FUNC(GetCurrentContext)>
      GetCurrentContext;

    /// @var QueryContext
    /// @eglfuncwrap{QueryContext}
    egl_api_function<
      bool_type(display_type, context_type, int_type, int_type*),
      EGLPLUS_EGL_STATIC_FUNC(QueryContext)>
      QueryContext;

    /// @var WaitClient
    /// @eglfuncwrap{WaitClient}
    egl_api_function<bool_type(), EGLPLUS_EGL_STATIC_FUNC(WaitClient)>
      WaitClient;

    /// @var WaitNative
    /// @eglfuncwrap{WaitNative}
    egl_api_function<bool_type(int_type), EGLPLUS_EGL_STATIC_FUNC(WaitNative)>
      WaitNative;

    /// @var CreateSync
    /// @eglfuncwrap{CreateSync}
    egl_api_function<
      sync_type(display_type, enum_type, const attrib_type*),
      EGLPLUS_EGL_STATIC_FUNC(CreateSync)>
      CreateSync;

    /// @var ClientWaitSync
    /// @eglfuncwrap{ClientWaitSync}
    egl_api_function<
      int_type(display_type, sync_type, int_type, time_type),
      EGLPLUS_EGL_STATIC_FUNC(ClientWaitSync)>
      ClientWaitSync;

    /// @var WaitSync
    /// @eglfuncwrap{WaitSync}
    egl_api_function<
      bool_type(display_type, sync_type, int_type),
      EGLPLUS_EGL_STATIC_FUNC(WaitSync)>
      WaitSync;

    /// @var GetSyncAttrib
    /// @eglfuncwrap{GetSyncAttrib}
    egl_api_function<
      bool_type(display_type, sync_type, int_type, attrib_type*),
      EGLPLUS_EGL_STATIC_FUNC(GetSyncAttrib)>
      GetSyncAttrib;

    /// @var DestroySync
    /// @eglfuncwrap{DestroySync}
    egl_api_function<
      bool_type(display_type, sync_type),
      EGLPLUS_EGL_STATIC_FUNC(DestroySync)>
      DestroySync;

    /// @var CreateImage
    /// @eglfuncwrap{CreateImage}
    egl_api_function<
      image_type(
        display_type,
        context_type,
        enum_type,
        client_buffer_type,
        const attrib_type*),
      EGLPLUS_EGL_STATIC_FUNC(CreateImage)>
      CreateImage;

    /// @var DestroyImage
    /// @eglfuncwrap{DestroyImage}
    egl_api_function<
      bool_type(display_type, image_type),
      EGLPLUS_EGL_STATIC_FUNC(DestroyImage)>
      DestroyImage;

    /// @var CopyBuffers
    /// @eglfuncwrap{CopyBuffers}
    egl_api_function<
      bool_type(display_type, surface_type, native_pixmap_type),
      EGLPLUS_EGL_STATIC_FUNC(CopyBuffers)>
      CopyBuffers;

    /// @var SwapInterval
    /// @eglfuncwrap{SwapInterval}
    egl_api_function<
      bool_type(display_type, int_type),
      EGLPLUS_EGL_STATIC_FUNC(SwapInterval)>
      SwapInterval;

    /// @var SwapBuffers
    /// @eglfuncwrap{SwapBuffers}
    egl_api_function<
      bool_type(display_type, surface_type),
      EGLPLUS_EGL_STATIC_FUNC(SwapBuffers)>
      SwapBuffers;

    /// @var SwapBuffersWithDamage
    /// @eglfuncwrap{SwapBuffersWithDamage}
    egl_api_function<
      bool_type(display_type, surface_type, const int_type*, int_type),
      nullptr>
      SwapBuffersWithDamage;

    /// @var ReleaseThread
    /// @eglfuncwrap{ReleaseThread}
    egl_api_function<bool_type(), EGLPLUS_EGL_STATIC_FUNC(ReleaseThread)>
      ReleaseThread;

    basic_egl_c_api(api_traits& traits);
};
//------------------------------------------------------------------------------
/// @brief Alias for the default EGL operations wrapper instantiation.
/// @ingroup egl_api_wrap
using egl_c_api = basic_egl_c_api<egl_api_traits>;
//------------------------------------------------------------------------------
} // namespace eagine::eglp

#endif // EGLPLUS_EGL_API_C_API_HPP
