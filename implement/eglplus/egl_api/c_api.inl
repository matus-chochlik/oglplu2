/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

namespace eagine::eglp {
//------------------------------------------------------------------------------
template <typename ApiTraits>
basic_egl_c_api<ApiTraits>::basic_egl_c_api(api_traits& traits)
  : GetError("GetError", traits, *this)
  , GetProcAddress("GetProcAddress", traits, *this)
  , QueryDevices("QueryDevicesEXT", traits, *this)
  , QueryDeviceString("QueryDeviceStringEXT", traits, *this)
  , GetPlatformDisplay("GetPlatformDisplay", traits, *this)
  , GetDisplay("GetDisplay", traits, *this)
  , GetDisplayDriverName("GetDisplayDriverName", traits, *this)
  , Initialize("Initialize", traits, *this)
  , Terminate("Terminate", traits, *this)
  , QueryString("QueryString", traits, *this)
  , GetConfigs("GetConfigs", traits, *this)
  , ChooseConfig("ChooseConfig", traits, *this)
  , GetConfigAttrib("GetConfigAttrib", traits, *this)
  , CreatePlatformWindowSurface("CreatePlatformWindowSurface", traits, *this)
  , CreateWindowSurface("CreateWindowSurface", traits, *this)
  , CreatePbufferSurface("CreatePbufferSurface", traits, *this)
  , CreatePlatformPixmapSurface("CreatePlatformPixmapSurface", traits, *this)
  , CreatePixmapSurface("CreatePixmapSurface", traits, *this)
  , CreateStreamProducerSurface("CreateStreamProducerSurfaceKHR", traits, *this)
  , DestroySurface("DestroySurface", traits, *this)
  , GetCurrentSurface("GetCurrentSurface", traits, *this)
  , SurfaceAttrib("SurfaceAttrib", traits, *this)
  , QuerySurface("QuerySurface", traits, *this)
  , CreateStream("CreateStreamKHR", traits, *this)
  , DestroyStream("DestroyStreamKHR", traits, *this)
  , StreamAttrib("StreamAttribKHR", traits, *this)
  , QueryStream("QueryStream", traits, *this)
  , StreamConsumerGLTextureExternal(
      "StreamConsumerGLTextureExternalKHR",
      traits,
      *this)
  , StreamConsumerAcquire("StreamConsumerAcquireKHR", traits, *this)
  , StreamConsumerRelease("StreamConsumerReleaseKHR", traits, *this)
  , GetOutputLayers("GetOutputLayersEXT", traits, *this)
  , OutputLayerAttrib("OutputLayerAttribEXT", traits, *this)
  , QueryOutputLayerAttrib("QueryOutputLayerAttribEXT", traits, *this)
  , QueryOutputLayerString("QueryOutputLayerStringEXT", traits, *this)
  , GetOutputPorts("GetOutputPortsEXT", traits, *this)
  , OutputPortAttrib("OutputPortAttribEXT", traits, *this)
  , QueryOutputPortAttrib("QueryOutputPortAttribEXT", traits, *this)
  , QueryOutputPortString("QueryOutputPortStringEXT", traits, *this)
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
  , SwapBuffersWithDamage("SwapBuffersWithDamageEXT", traits, *this)
  , ReleaseThread("ReleaseThread", traits, *this) {}
//------------------------------------------------------------------------------
} // namespace eagine::eglp

