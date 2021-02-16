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
basic_egl_constants<ApiTraits>::basic_egl_constants(
  ApiTraits& traits,
  basic_egl_c_api<ApiTraits>& api)
  : success("SUCCESS", traits, api)
  , not_initialized("NOT_INITIALIZED", traits, api)
  , bad_access("BAD_ACCESS", traits, api)
  , bad_alloc("BAD_ALLOC", traits, api)
  , bad_attribute("BAD_ATTRIBUTE", traits, api)
  , bad_context("BAD_CONTEXT", traits, api)
  , bad_config("BAD_CONFIG", traits, api)
  , bad_current_surface("BAD_CURRENT_SURFACE", traits, api)
  , bad_display("BAD_DISPLAY", traits, api)
  , bad_surface("BAD_SURFACE", traits, api)
  , bad_match("BAD_MATCH", traits, api)
  , bad_parameter("BAD_PARAMETER", traits, api)
  , bad_native_pixmap("BAD_NATIVE_PIXMAP", traits, api)
  , bad_native_window("BAD_NATIVE_WINDOW", traits, api)
  , context_lost("CONTEXT_LOST", traits, api)
  , true_("TRUE", traits, api)
  , false_("FALSE", traits, api)
  , platform_device("PLATFORM_DEVICE_EXT", traits, api)
  , platform_x11("PLATFORM_X11_EXT", traits, api)
  , platform_xcb("PLATFORM_XCB_EXT", traits, api)
  , platform_wayland("PLATFORM_WAYLAND_EXT", traits, api)
  , platform_gbm_mesa("PLATFORM_GBM_MESA", traits, api)
  , platform_surfaceless("PLATFORM_SURFACELESS_MESA", traits, api)
  , platform_android("PLATFORM_ANDROID_KHR", traits, api)
  , client_apis("CLIENT_APIS", traits, api)
  , vendor("VENDOR", traits, api)
  , version("VERSION", traits, api)
  , renderer("RENDERER_EXT", traits, api)
  , extensions("EXTENSIONS", traits, api)
  , drm_device_file("DRM_DEVICE_FILE_EXT", traits, api)
  , drm_master_fd("DRM_MASTER_FD_EXT", traits, api)
  , config_id("CONFIG_ID", traits, api)
  , conformant("CONFORMANT", traits, api)
  , surface_type("SURFACE_TYPE", traits, api)
  , renderable_type("RENDERABLE_TYPE", traits, api)
  , color_buffer_type("RENDERABLE_TYPE", traits, api)
  , buffer_size("BUFFER_SIZE", traits, api)
  , red_size("RED_SIZE", traits, api)
  , green_size("GREEN_SIZE", traits, api)
  , blue_size("BLUE_SIZE", traits, api)
  , luminance_size("LUMINANCE_SIZE", traits, api)
  , alpha_size("ALPHA_SIZE", traits, api)
  , alpha_mask_size("ALPHA_MASK_SIZE", traits, api)
  , depth_size("DEPTH_SIZE", traits, api)
  , stencil_size("STENCIL_SIZE", traits, api)
  , sample_buffers("SAMPLE_BUFFERS", traits, api)
  , samples("SAMPLES", traits, api)
  , transparent_type("TRANSPARENT_TYPE", traits, api)
  , transparent_red_value("TRANSPARENT_RED_VALUE", traits, api)
  , transparent_green_value("TRANSPARENT_GREEN_VALUE", traits, api)
  , transparent_blue_value("TRANSPARENT_BLUE_VALUE", traits, api)
  , color_component_type("COLOR_COMPONENT_TYPE_EXT", traits, api)
  , level("LEVEL", traits, api)
  , pbuffer_width("PBUFFER_WIDTH", traits, api)
  , pbuffer_height("PBUFFER_HEIGHT", traits, api)
  , pbuffer_pixels("PBUFFER_PIXELS", traits, api)
  , max_swap_interval("MAX_SWAP_INTERVAL", traits, api)
  , min_swap_interval("MIN_SWAP_INTERVAL", traits, api)
  , width("WIDTH", traits, api)
  , height("HEIGHT", traits, api)
  , largest_pbuffer("LARGEST_PBUFFER", traits, api)
  , gl_colorspace("GL_COLORSPACE", traits, api)
  , texture_target("TEXTURE_TARGET", traits, api)
  , mipmap_level("MIPMAP_LEVEL", traits, api)
  , multisample_resolve("MULTISAMPLE_RESOLVE", traits, api)
  , swap_behavior("SWAP_BEHAVIOR", traits, api)
  , context_major_version("CONTEXT_MAJOR_VERSION", traits, api)
  , context_minor_version("CONTEXT_MINOR_VERSION", traits, api)
  , context_opengl_profile_mask("CONTEXT_OPENGL_PROFILE_MASK", traits, api)
  , context_opengl_forward_compatible(
      "CONTEXT_OPENGL_FORWARD_COMPATIBLE",
      traits,
      api)
  , context_opengl_debug("CONTEXT_OPENGL_DEBUG", traits, api)
  , context_opengl_robust_access("CONTEXT_OPENGL_ROBUST_ACCESS", traits, api)
  , window_bit("WINDOW_BIT", traits, api)
  , pixmap_bit("PIXMAP_BIT", traits, api)
  , pbuffer_bit("PBUFFER_BIT", traits, api)
  , stream_bit("STREAM_BIT_KHR", traits, api)
  , multisample_resolve_box_bit("MULTISAMPLE_RESOLVE_BOX_BIT", traits, api)
  , swap_behavior_preserved_bit("SWAP_BEHAVIOR_PRESERVED_BIT", traits, api)
  , vg_colorspace_linear_bit("VG_COLORSPACE_LINEAR_BIT", traits, api)
  , vg_alpha_format_pre_bit_bit("VG_ALPHA_FORMAT_PRE_BIT_BIT", traits, api)
  , consumer_latency_usec("CONSUMER_LATENCY_USEC_KHR", traits, api)
  , consumer_acquire_timeout_usec(
      "CONSUMER_ACQUIRE_TIMEOUT_USEC_KHR",
      traits,
      api)
  , producer_frame("PRODUCER_FRAME_KHR", traits, api)
  , consumer_frame("CONSUMER_FRAME_KHR", traits, api)
  , stream_state("STREAM_STATE_KHR", traits, api)
  , stream_state_created("STREAM_STATE_CREATED_KHR", traits, api)
  , stream_state_connecting("STREAM_STATE_CONNECTING_KHR", traits, api)
  , stream_state_empty("STREAM_STATE_EMPTY_KHR", traits, api)
  , stream_state_new_frame_available(
      "STREAM_STATE_NEW_FRAME_AVAILABLE_KHR",
      traits,
      api)
  , stream_state_old_frame_available(
      "STREAM_STATE_OLD_FRAME_AVAILABLE_KHR",
      traits,
      api)
  , stream_state_disconnected("STREAM_STATE_DISCONNECTED_KHR", traits, api)
  , image_preserved("IMAGE_PRESERVED_KHR", traits, api)
  , opengl_bit("OPENGL_BIT", traits, api)
  , opengl_es_bit("OPENGL_ES_BIT", traits, api)
  , opengl_es2_bit("OPENGL_ES2_BIT", traits, api)
  , opengl_es3_bit("OPENGL_ES3_BIT", traits, api)
  , openvg_bit("OPENVG_BIT", traits, api)
  , opengl_api("OPENGL_API", traits, api)
  , opengl_es_api("OPENGL_ES_API", traits, api)
  , openvg_api("OPENVG_API", traits, api)
  , context_opengl_core_profile_bit(
      "CONTEXT_OPENGL_CORE_PROFILE_BIT",
      traits,
      api)
  , context_opengl_compatibility_profile_bit(
      "CONTEXT_OPENGL_COMPATIBILITY_PROFILE_BIT",
      traits,
      api)
  , rgb_buffer("RGB_BUFFER", traits, api)
  , luminance_buffer("LUMINANCE_BUFFER", traits, api)
  , color_component_type_fixed("COLOR_COMPONENT_TYPE_FIXED_EXT", traits, api)
  , color_component_type_float("COLOR_COMPONENT_TYPE_FLOAT_EXT", traits, api)
  , read("READ", traits, api)
  , draw("DRAW", traits, api)
  , sync_fence("sync_fence", traits, api)
  , sync_cl_event("sync_cl_event", traits, api)
  , no_texture("no_texture", traits, api)
  , texture_2d("texture_rgba", traits, api)
  , texture_rgb("texture_rgb", traits, api)
  , texture_rgba("texture_rgba", traits, api)
  , gl_colorspace_linear("gl_colorspace_linear", traits, api)
  , gl_colorspace_srgb("gl_colorspace_srgb", traits, api)
  , none("NONE", traits, api) {}
//------------------------------------------------------------------------------
} // namespace eagine::eglp

