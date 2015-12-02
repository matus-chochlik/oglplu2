//  File implement/eglplus/enum/value_defs.inl
//
//  Automatically generated file, DO NOT modify manually.
//  Edit the enumeration source files in 'source/enums/eglplus'
//  or the 'source/enums/make_enum.py' script instead.
//
//  Copyright Matus Chochlik.
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//   http://www.boost.org/LICENSE_1_0.txt
//

namespace eglplus {

#ifdef EGL_ALPHA_MASK_SIZE
const enum_value<
	EGLenum,
	mp_list<eglplus::config_attrib>
> enum_values::alpha_mask_size;
#endif

#ifdef EGL_ALPHA_SIZE
const enum_value<
	EGLenum,
	mp_list<eglplus::config_attrib>
> enum_values::alpha_size;
#endif

#ifdef EGL_BACK_BUFFER
const enum_value<
	EGLenum,
	mp_list<eglplus::render_buffer>
> enum_values::back_buffer;
#endif

#ifdef EGL_BAD_ACCESS
const enum_value<
	EGLenum,
	mp_list<eglplus::error_code>
> enum_values::bad_access;
#endif

#ifdef EGL_BAD_ALLOC
const enum_value<
	EGLenum,
	mp_list<eglplus::error_code>
> enum_values::bad_alloc;
#endif

#ifdef EGL_BAD_ATTRIBUTE
const enum_value<
	EGLenum,
	mp_list<eglplus::error_code>
> enum_values::bad_attribute;
#endif

#ifdef EGL_BAD_CONFIG
const enum_value<
	EGLenum,
	mp_list<eglplus::error_code>
> enum_values::bad_config;
#endif

#ifdef EGL_BAD_CONTEXT
const enum_value<
	EGLenum,
	mp_list<eglplus::error_code>
> enum_values::bad_context;
#endif

#ifdef EGL_BAD_CURRENT_SURFACE
const enum_value<
	EGLenum,
	mp_list<eglplus::error_code>
> enum_values::bad_current_surface;
#endif

#ifdef EGL_BAD_DISPLAY
const enum_value<
	EGLenum,
	mp_list<eglplus::error_code>
> enum_values::bad_display;
#endif

#ifdef EGL_BAD_MATCH
const enum_value<
	EGLenum,
	mp_list<eglplus::error_code>
> enum_values::bad_match;
#endif

#ifdef EGL_BAD_NATIVE_PIXMAP
const enum_value<
	EGLenum,
	mp_list<eglplus::error_code>
> enum_values::bad_native_pixmap;
#endif

#ifdef EGL_BAD_NATIVE_WINDOW
const enum_value<
	EGLenum,
	mp_list<eglplus::error_code>
> enum_values::bad_native_window;
#endif

#ifdef EGL_BAD_PARAMETER
const enum_value<
	EGLenum,
	mp_list<eglplus::error_code>
> enum_values::bad_parameter;
#endif

#ifdef EGL_BAD_SURFACE
const enum_value<
	EGLenum,
	mp_list<eglplus::error_code>
> enum_values::bad_surface;
#endif

#ifdef EGL_BIND_TO_TEXTURE_RGB
const enum_value<
	EGLenum,
	mp_list<eglplus::config_attrib>
> enum_values::bind_to_texture_rgb;
#endif

#ifdef EGL_BIND_TO_TEXTURE_RGBA
const enum_value<
	EGLenum,
	mp_list<eglplus::config_attrib>
> enum_values::bind_to_texture_rgba;
#endif

#ifdef EGL_BLUE_SIZE
const enum_value<
	EGLenum,
	mp_list<eglplus::config_attrib>
> enum_values::blue_size;
#endif

#ifdef EGL_BUFFER_DESTROYED
const enum_value<
	EGLenum,
	mp_list<eglplus::swap_behavior>
> enum_values::buffer_destroyed;
#endif

#ifdef EGL_BUFFER_PRESERVED
const enum_value<
	EGLenum,
	mp_list<eglplus::swap_behavior>
> enum_values::buffer_preserved;
#endif

#ifdef EGL_BUFFER_SIZE
const enum_value<
	EGLenum,
	mp_list<eglplus::config_attrib>
> enum_values::buffer_size;
#endif

#ifdef EGL_CLIENT_APIS
const enum_value<
	EGLenum,
	mp_list<eglplus::string_query>
> enum_values::client_apis;
#endif

#ifdef EGL_COLOR_BUFFER_TYPE
const enum_value<
	EGLenum,
	mp_list<eglplus::config_attrib>
> enum_values::color_buffer_type;
#endif

#ifdef EGL_CONFIG_CAVEAT
const enum_value<
	EGLenum,
	mp_list<eglplus::config_attrib>
> enum_values::config_caveat;
#endif

#ifdef EGL_CONFIG_ID
const enum_value<
	EGLenum,
	mp_list<eglplus::config_attrib,eglplus::surface_attrib>
> enum_values::config_id;
#endif

#ifdef EGL_CONFORMANT
const enum_value<
	EGLenum,
	mp_list<eglplus::config_attrib>
> enum_values::conformant;
#endif

#ifdef EGL_CONTEXT_FLAGS
const enum_value<
	EGLenum,
	mp_list<eglplus::context_attrib>
> enum_values::context_flags;
#endif

#ifdef EGL_CONTEXT_LOST
const enum_value<
	EGLenum,
	mp_list<eglplus::error_code>
> enum_values::context_lost;
#endif

#ifdef EGL_CONTEXT_MAJOR_VERSION
const enum_value<
	EGLenum,
	mp_list<eglplus::context_attrib>
> enum_values::context_major_version;
#endif

#ifdef EGL_CONTEXT_MINOR_VERSION
const enum_value<
	EGLenum,
	mp_list<eglplus::context_attrib>
> enum_values::context_minor_version;
#endif

#ifdef EGL_CONTEXT_OPENGL_COMPATIBILITY_PROFILE_BIT
const enum_value<
	EGLenum,
	mp_list<eglplus::opengl_profile_bit>
> enum_values::context_opengl_compatibility_profile_bit;
#endif

#ifdef EGL_CONTEXT_OPENGL_CORE_PROFILE_BIT
const enum_value<
	EGLenum,
	mp_list<eglplus::opengl_profile_bit>
> enum_values::context_opengl_core_profile_bit;
#endif

#ifdef EGL_CONTEXT_OPENGL_DEBUG_BIT
const enum_value<
	EGLenum,
	mp_list<eglplus::context_flag>
> enum_values::context_opengl_debug_bit;
#endif

#ifdef EGL_CONTEXT_OPENGL_FORWARD_COMPATIBLE_BIT
const enum_value<
	EGLenum,
	mp_list<eglplus::context_flag>
> enum_values::context_opengl_forward_compatible_bit;
#endif

#ifdef EGL_CONTEXT_OPENGL_PROFILE_MASK
const enum_value<
	EGLenum,
	mp_list<eglplus::context_attrib>
> enum_values::context_opengl_profile_mask;
#endif

#ifdef EGL_CONTEXT_OPENGL_RESET_NOTIFICATION_STRATEGY
const enum_value<
	EGLenum,
	mp_list<eglplus::context_attrib>
> enum_values::context_opengl_reset_notification_strategy;
#endif

#ifdef EGL_CONTEXT_OPENGL_ROBUST_ACCESS_BIT
const enum_value<
	EGLenum,
	mp_list<eglplus::context_flag>
> enum_values::context_opengl_robust_access_bit;
#endif

#ifdef EGL_DEPTH_SIZE
const enum_value<
	EGLenum,
	mp_list<eglplus::config_attrib>
> enum_values::depth_size;
#endif

#ifdef EGL_EXTENSIONS
const enum_value<
	EGLenum,
	mp_list<eglplus::string_query>
> enum_values::extensions;
#endif

#ifdef EGL_GL_COLORSPACE
const enum_value<
	EGLenum,
	mp_list<eglplus::surface_attrib>
> enum_values::gl_colorspace;
#endif

#ifdef EGL_GL_COLORSPACE_LINEAR
const enum_value<
	EGLenum,
	mp_list<eglplus::gl_colorspace>
> enum_values::gl_colorspace_linear;
#endif

#ifdef EGL_GL_COLORSPACE_sRGB
const enum_value<
	EGLenum,
	mp_list<eglplus::gl_colorspace>
> enum_values::gl_colorspace_srgb;
#endif

#ifdef EGL_GREEN_SIZE
const enum_value<
	EGLenum,
	mp_list<eglplus::config_attrib>
> enum_values::green_size;
#endif

#ifdef EGL_HEIGHT
const enum_value<
	EGLenum,
	mp_list<eglplus::surface_attrib>
> enum_values::height;
#endif

#ifdef EGL_HORIZONTAL_RESOLUTION
const enum_value<
	EGLenum,
	mp_list<eglplus::surface_attrib>
> enum_values::horizontal_resolution;
#endif

#ifdef EGL_LARGEST_PBUFFER
const enum_value<
	EGLenum,
	mp_list<eglplus::surface_attrib>
> enum_values::largest_pbuffer;
#endif

#ifdef EGL_LEVEL
const enum_value<
	EGLenum,
	mp_list<eglplus::config_attrib>
> enum_values::level;
#endif

#ifdef EGL_LOSE_CONTEXT_ON_RESET
const enum_value<
	EGLenum,
	mp_list<eglplus::opengl_rns>
> enum_values::lose_context_on_reset;
#endif

#ifdef EGL_LUMINANCE_BUFFER
const enum_value<
	EGLenum,
	mp_list<eglplus::color_buffer_type>
> enum_values::luminance_buffer;
#endif

#ifdef EGL_LUMINANCE_SIZE
const enum_value<
	EGLenum,
	mp_list<eglplus::config_attrib>
> enum_values::luminance_size;
#endif

#ifdef EGL_MAX_PBUFFER_HEIGHT
const enum_value<
	EGLenum,
	mp_list<eglplus::config_attrib>
> enum_values::max_pbuffer_height;
#endif

#ifdef EGL_MAX_PBUFFER_PIXELS
const enum_value<
	EGLenum,
	mp_list<eglplus::config_attrib>
> enum_values::max_pbuffer_pixels;
#endif

#ifdef EGL_MAX_PBUFFER_WIDTH
const enum_value<
	EGLenum,
	mp_list<eglplus::config_attrib>
> enum_values::max_pbuffer_width;
#endif

#ifdef EGL_MAX_SWAP_INTERVAL
const enum_value<
	EGLenum,
	mp_list<eglplus::config_attrib>
> enum_values::max_swap_interval;
#endif

#ifdef EGL_MIN_SWAP_INTERVAL
const enum_value<
	EGLenum,
	mp_list<eglplus::config_attrib>
> enum_values::min_swap_interval;
#endif

#ifdef EGL_MIPMAP_LEVEL
const enum_value<
	EGLenum,
	mp_list<eglplus::surface_attrib>
> enum_values::mipmap_level;
#endif

#ifdef EGL_MIPMAP_TEXTURE
const enum_value<
	EGLenum,
	mp_list<eglplus::surface_attrib>
> enum_values::mipmap_texture;
#endif

#ifdef EGL_MULTISAMPLE_RESOLVE
const enum_value<
	EGLenum,
	mp_list<eglplus::surface_attrib>
> enum_values::multisample_resolve;
#endif

#ifdef EGL_MULTISAMPLE_RESOLVE_BOX
const enum_value<
	EGLenum,
	mp_list<eglplus::multisample_resolve>
> enum_values::multisample_resolve_box;
#endif

#ifdef EGL_MULTISAMPLE_RESOLVE_BOX_BIT
const enum_value<
	EGLenum,
	mp_list<eglplus::surface_type_bit>
> enum_values::multisample_resolve_box_bit;
#endif

#ifdef EGL_MULTISAMPLE_RESOLVE_DEFAULT
const enum_value<
	EGLenum,
	mp_list<eglplus::multisample_resolve>
> enum_values::multisample_resolve_default;
#endif

#ifdef EGL_NATIVE_RENDERABLE
const enum_value<
	EGLenum,
	mp_list<eglplus::config_attrib>
> enum_values::native_renderable;
#endif

#ifdef EGL_NATIVE_VISUAL_ID
const enum_value<
	EGLenum,
	mp_list<eglplus::config_attrib>
> enum_values::native_visual_id;
#endif

#ifdef EGL_NATIVE_VISUAL_TYPE
const enum_value<
	EGLenum,
	mp_list<eglplus::config_attrib>
> enum_values::native_visual_type;
#endif

#ifdef EGL_NO_RESET_NOTIFICATION
const enum_value<
	EGLenum,
	mp_list<eglplus::opengl_rns>
> enum_values::no_reset_notification;
#endif

#ifdef EGL_NO_TEXTURE
const enum_value<
	EGLenum,
	mp_list<eglplus::texture_target,eglplus::texture_format>
> enum_values::no_texture;
#endif

#ifdef EGL_NON_CONFORMANT_CONFIG
const enum_value<
	EGLenum,
	mp_list<eglplus::config_caveat>
> enum_values::non_conformant_config;
#endif

#ifdef EGL_NONE
const enum_value<
	EGLenum,
	mp_list<eglplus::rendering_api,eglplus::config_caveat,eglplus::transparent_type>
> enum_values::none;
#endif

#ifdef EGL_NOT_INITIALIZED
const enum_value<
	EGLenum,
	mp_list<eglplus::error_code>
> enum_values::not_initialized;
#endif

#ifdef EGL_OPENGL_API
const enum_value<
	EGLenum,
	mp_list<eglplus::rendering_api>
> enum_values::opengl_api;
#endif

#ifdef EGL_OPENGL_BIT
const enum_value<
	EGLenum,
	mp_list<eglplus::renderable_type_bit>
> enum_values::opengl_bit;
#endif

#ifdef EGL_OPENGL_ES2_BIT
const enum_value<
	EGLenum,
	mp_list<eglplus::renderable_type_bit>
> enum_values::opengl_es2_bit;
#endif

#ifdef EGL_OPENGL_ES3_BIT
const enum_value<
	EGLenum,
	mp_list<eglplus::renderable_type_bit>
> enum_values::opengl_es3_bit;
#endif

#ifdef EGL_OPENGL_ES_API
const enum_value<
	EGLenum,
	mp_list<eglplus::rendering_api>
> enum_values::opengl_es_api;
#endif

#ifdef EGL_OPENGL_ES_BIT
const enum_value<
	EGLenum,
	mp_list<eglplus::renderable_type_bit>
> enum_values::opengl_es_bit;
#endif

#ifdef EGL_OPENVG_API
const enum_value<
	EGLenum,
	mp_list<eglplus::rendering_api>
> enum_values::openvg_api;
#endif

#ifdef EGL_OPENVG_BIT
const enum_value<
	EGLenum,
	mp_list<eglplus::renderable_type_bit>
> enum_values::openvg_bit;
#endif

#ifdef EGL_PBUFFER_BIT
const enum_value<
	EGLenum,
	mp_list<eglplus::surface_type_bit>
> enum_values::pbuffer_bit;
#endif

#ifdef EGL_PIXEL_ASPECT_RATIO
const enum_value<
	EGLenum,
	mp_list<eglplus::surface_attrib>
> enum_values::pixel_aspect_ratio;
#endif

#ifdef EGL_PIXMAP_BIT
const enum_value<
	EGLenum,
	mp_list<eglplus::surface_type_bit>
> enum_values::pixmap_bit;
#endif

#ifdef EGL_RED_SIZE
const enum_value<
	EGLenum,
	mp_list<eglplus::config_attrib>
> enum_values::red_size;
#endif

#ifdef EGL_RENDER_BUFFER
const enum_value<
	EGLenum,
	mp_list<eglplus::surface_attrib>
> enum_values::render_buffer;
#endif

#ifdef EGL_RENDERABLE_TYPE
const enum_value<
	EGLenum,
	mp_list<eglplus::config_attrib>
> enum_values::renderable_type;
#endif

#ifdef EGL_RGB_BUFFER
const enum_value<
	EGLenum,
	mp_list<eglplus::color_buffer_type>
> enum_values::rgb_buffer;
#endif

#ifdef EGL_SAMPLE_BUFFERS
const enum_value<
	EGLenum,
	mp_list<eglplus::config_attrib>
> enum_values::sample_buffers;
#endif

#ifdef EGL_SAMPLES
const enum_value<
	EGLenum,
	mp_list<eglplus::config_attrib>
> enum_values::samples;
#endif

#ifdef EGL_SINGLE_BUFFER
const enum_value<
	EGLenum,
	mp_list<eglplus::render_buffer>
> enum_values::single_buffer;
#endif

#ifdef EGL_SLOW_CONFIG
const enum_value<
	EGLenum,
	mp_list<eglplus::config_caveat>
> enum_values::slow_config;
#endif

#ifdef EGL_STENCIL_SIZE
const enum_value<
	EGLenum,
	mp_list<eglplus::config_attrib>
> enum_values::stencil_size;
#endif

#ifdef EGL_SURFACE_TYPE
const enum_value<
	EGLenum,
	mp_list<eglplus::config_attrib>
> enum_values::surface_type;
#endif

#ifdef EGL_SWAP_BEHAVIOR
const enum_value<
	EGLenum,
	mp_list<eglplus::surface_attrib>
> enum_values::swap_behavior;
#endif

#ifdef EGL_SWAP_BEHAVIOR_PRESERVED_BIT
const enum_value<
	EGLenum,
	mp_list<eglplus::surface_type_bit>
> enum_values::swap_behavior_preserved_bit;
#endif

#ifdef EGL_TEXTURE_2D
const enum_value<
	EGLenum,
	mp_list<eglplus::texture_target>
> enum_values::texture_2d;
#endif

#ifdef EGL_TEXTURE_FORMAT
const enum_value<
	EGLenum,
	mp_list<eglplus::surface_attrib>
> enum_values::texture_format;
#endif

#ifdef EGL_TEXTURE_RGB
const enum_value<
	EGLenum,
	mp_list<eglplus::texture_format>
> enum_values::texture_rgb;
#endif

#ifdef EGL_TEXTURE_RGBA
const enum_value<
	EGLenum,
	mp_list<eglplus::texture_format>
> enum_values::texture_rgba;
#endif

#ifdef EGL_TEXTURE_TARGET
const enum_value<
	EGLenum,
	mp_list<eglplus::surface_attrib>
> enum_values::texture_target;
#endif

#ifdef EGL_TRANSPARENT_BLUE_VALUE
const enum_value<
	EGLenum,
	mp_list<eglplus::config_attrib>
> enum_values::transparent_blue_value;
#endif

#ifdef EGL_TRANSPARENT_GREEN_VALUE
const enum_value<
	EGLenum,
	mp_list<eglplus::config_attrib>
> enum_values::transparent_green_value;
#endif

#ifdef EGL_TRANSPARENT_RED_VALUE
const enum_value<
	EGLenum,
	mp_list<eglplus::config_attrib>
> enum_values::transparent_red_value;
#endif

#ifdef EGL_TRANSPARENT_RGB
const enum_value<
	EGLenum,
	mp_list<eglplus::transparent_type>
> enum_values::transparent_rgb;
#endif

#ifdef EGL_TRANSPARENT_TYPE
const enum_value<
	EGLenum,
	mp_list<eglplus::config_attrib>
> enum_values::transparent_type;
#endif

#ifdef EGL_VENDOR
const enum_value<
	EGLenum,
	mp_list<eglplus::string_query>
> enum_values::vendor;
#endif

#ifdef EGL_VERSION
const enum_value<
	EGLenum,
	mp_list<eglplus::string_query>
> enum_values::version;
#endif

#ifdef EGL_VERTICAL_RESOLUTION
const enum_value<
	EGLenum,
	mp_list<eglplus::surface_attrib>
> enum_values::vertical_resolution;
#endif

#ifdef EGL_VG_ALPHA_FORMAT
const enum_value<
	EGLenum,
	mp_list<eglplus::surface_attrib>
> enum_values::vg_alpha_format;
#endif

#ifdef EGL_VG_ALPHA_FORMAT_NONPRE
const enum_value<
	EGLenum,
	mp_list<eglplus::vg_alpha_format>
> enum_values::vg_alpha_format_nonpre;
#endif

#ifdef EGL_VG_ALPHA_FORMAT_PRE
const enum_value<
	EGLenum,
	mp_list<eglplus::vg_alpha_format>
> enum_values::vg_alpha_format_pre;
#endif

#ifdef EGL_VG_ALPHA_FORMAT_PRE_BIT
const enum_value<
	EGLenum,
	mp_list<eglplus::surface_type_bit>
> enum_values::vg_alpha_format_pre_bit;
#endif

#ifdef EGL_VG_COLORSPACE
const enum_value<
	EGLenum,
	mp_list<eglplus::surface_attrib>
> enum_values::vg_colorspace;
#endif

#ifdef EGL_VG_COLORSPACE_LINEAR
const enum_value<
	EGLenum,
	mp_list<eglplus::vg_colorspace>
> enum_values::vg_colorspace_linear;
#endif

#ifdef EGL_VG_COLORSPACE_LINEAR_BIT
const enum_value<
	EGLenum,
	mp_list<eglplus::surface_type_bit>
> enum_values::vg_colorspace_linear_bit;
#endif

#ifdef EGL_VG_COLORSPACE_sRGB
const enum_value<
	EGLenum,
	mp_list<eglplus::vg_colorspace>
> enum_values::vg_colorspace_srgb;
#endif

#ifdef EGL_WIDTH
const enum_value<
	EGLenum,
	mp_list<eglplus::surface_attrib>
> enum_values::width;
#endif

#ifdef EGL_WINDOW_BIT
const enum_value<
	EGLenum,
	mp_list<eglplus::surface_type_bit>
> enum_values::window_bit;
#endif

} // namespace eglplus
