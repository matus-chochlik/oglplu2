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
basic_egl_operations<ApiTraits>::basic_egl_operations(api_traits& traits)
  : c_api{traits}
  , EXT_device_base("EXT_device_base", traits, *this)
  , EXT_device_enumeration("EXT_device_enumeration", traits, *this)
  , EXT_device_query("EXT_device_query", traits, *this)
  , EXT_device_query_name("EXT_device_query_name", traits, *this)
  , EXT_device_drm("EXT_device_drm", traits, *this)
  , MESA_device_software("MESA_device_software", traits, *this)
  , EXT_platform_base("EXT_platform_base", traits, *this)
  , EXT_platform_device("EXT_platform_device", traits, *this)
  , EXT_platform_x11("EXT_platform_x11", traits, *this)
  , EXT_platform_xcb("EXT_platform_xcb", traits, *this)
  , EXT_platform_wayland("EXT_platform_wayland", traits, *this)
  , KHR_platform_gbm("KHR_platform_gbm", traits, *this)
  , MESA_platform_surfaceless("MESA_platform_surfaceless", traits, *this)
  , EXT_create_context_robustness("EXT_create_context_robustness", traits, *this)
  , EXT_swap_buffers_with_damage("EXT_swap_buffers_with_damage", traits, *this)
  , EXT_output_base("EXT_output_base", traits, *this)
  , EXT_output_drm("EXT_output_drm", traits, *this)
  , EXT_stream_consumer_egloutput("EXT_stream_consumer_egloutput", traits, *this)
  , EXT_pixel_format_float("EXT_pixel_format_float", traits, *this)
  , MESA_configless_context("MESA_configless_context", traits, *this)
  , MESA_query_driver("MESA_query_driver", traits, *this)
  , query_devices("query_devices", traits, *this)
  , query_device_string("query_device_string", traits, *this)
  , get_platform_display("get_platform_display", traits, *this)
  , get_display("get_display", traits, *this)
  , get_display_driver_name("get_display_driver_name", traits, *this)
  , initialize("initialize", traits, *this)
  , terminate("terminate", traits, *this)
  , get_configs("get_configs", traits, *this)
  , choose_config("choose_config", traits, *this)
  , get_config_attrib("get_config_attrib", traits, *this)
  , create_window_surface("create_window_surface", traits, *this)
  , create_pbuffer_surface("create_pbuffer_surface", traits, *this)
  , create_pixmap_surface("create_pixmap_surface", traits, *this)
  , destroy_surface("destroy_surface", traits, *this)
  , get_current_surface("get_current_surface", traits, *this)
  , surface_attrib("surface_attrib", traits, *this)
  , query_surface("query_surface", traits, *this)
  , create_stream("create_stream", traits, *this)
  , destroy_stream("destroy_stream", traits, *this)
  , stream_attrib("stream_attrib", traits, *this)
  , query_stream("query_stream", traits, *this)
  , stream_consumer_gl_texture_external(
      "consumer_gl_texture_external",
      traits,
      *this)
  , stream_consumer_acquire("stream_consumer_acquire", traits, *this)
  , stream_consumer_release("stream_consumer_release", traits, *this)
  , get_output_layers("get_output_layers", traits, *this)
  , output_layer_attrib("output_layer_attrib", traits, *this)
  , query_output_layer_attrib("query_output_layer_attrib", traits, *this)
  , query_output_layer_string("query_output_layer_string", traits, *this)
  , get_output_ports("get_output_ports", traits, *this)
  , output_port_attrib("output_port_attrib", traits, *this)
  , query_output_port_attrib("query_output_port_attrib", traits, *this)
  , query_output_port_string("query_output_port_string", traits, *this)
  , create_image("create_image", traits, *this)
  , destroy_image("destroy_image", traits, *this)
  , bind_api("bind_api", traits, *this)
  , query_api("query_api", traits, *this)
  , create_context("create_context", traits, *this)
  , destroy_context("destroy_context", traits, *this)
  , make_current("make_current", traits, *this)
  , get_current_context("get_current_context", traits, *this)
  , wait_client("wait_client", traits, *this)
  , wait_native("wait_native", traits, *this)
  , create_sync("create_sync", traits, *this)
  , client_wait_sync("client_wait_sync", traits, *this)
  , wait_sync("wait_sync", traits, *this)
  , destroy_sync("destroy_sync", traits, *this)
  , query_string("query_string", traits, *this)
  , swap_interval("swap_interval", traits, *this)
  , swap_buffers("swap_buffers", traits, *this)
  , swap_buffers_with_damage("swap_buffers_with_damage", traits, *this)
  , release_thread("release_thread", traits, *this) {}
//------------------------------------------------------------------------------
} // namespace eagine::eglp
