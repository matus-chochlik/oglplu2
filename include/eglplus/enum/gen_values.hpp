//  File include/eglplus/enum/gen_values.hpp
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
#ifndef EGLPLUS_EGL_GEN_ENUM_VALUES_HPP
#define EGLPLUS_EGL_GEN_ENUM_VALUES_HPP

#include "gen_types.hpp"
#include "../utils/mp_list.hpp"

namespace eglplus {
struct generated_enum_values {

#ifdef EGL_ALPHA_MASK_SIZE
static constexpr const enum_value<
	EGLenum,
	EGL_ALPHA_MASK_SIZE,
	mp_list<eglplus::config_attrib>
> alpha_mask_size = {};
#endif

#ifdef EGL_ALPHA_SIZE
static constexpr const enum_value<
	EGLenum,
	EGL_ALPHA_SIZE,
	mp_list<eglplus::config_attrib>
> alpha_size = {};
#endif

#ifdef EGL_BACK_BUFFER
static constexpr const enum_value<
	EGLenum,
	EGL_BACK_BUFFER,
	mp_list<eglplus::render_buffer>
> back_buffer = {};
#endif

#ifdef EGL_BAD_ACCESS
static constexpr const enum_value<
	EGLenum,
	EGL_BAD_ACCESS,
	mp_list<eglplus::error_code>
> bad_access = {};
#endif

#ifdef EGL_BAD_ALLOC
static constexpr const enum_value<
	EGLenum,
	EGL_BAD_ALLOC,
	mp_list<eglplus::error_code>
> bad_alloc = {};
#endif

#ifdef EGL_BAD_ATTRIBUTE
static constexpr const enum_value<
	EGLenum,
	EGL_BAD_ATTRIBUTE,
	mp_list<eglplus::error_code>
> bad_attribute = {};
#endif

#ifdef EGL_BAD_CONFIG
static constexpr const enum_value<
	EGLenum,
	EGL_BAD_CONFIG,
	mp_list<eglplus::error_code>
> bad_config = {};
#endif

#ifdef EGL_BAD_CONTEXT
static constexpr const enum_value<
	EGLenum,
	EGL_BAD_CONTEXT,
	mp_list<eglplus::error_code>
> bad_context = {};
#endif

#ifdef EGL_BAD_CURRENT_SURFACE
static constexpr const enum_value<
	EGLenum,
	EGL_BAD_CURRENT_SURFACE,
	mp_list<eglplus::error_code>
> bad_current_surface = {};
#endif

#ifdef EGL_BAD_DISPLAY
static constexpr const enum_value<
	EGLenum,
	EGL_BAD_DISPLAY,
	mp_list<eglplus::error_code>
> bad_display = {};
#endif

#ifdef EGL_BAD_MATCH
static constexpr const enum_value<
	EGLenum,
	EGL_BAD_MATCH,
	mp_list<eglplus::error_code>
> bad_match = {};
#endif

#ifdef EGL_BAD_NATIVE_PIXMAP
static constexpr const enum_value<
	EGLenum,
	EGL_BAD_NATIVE_PIXMAP,
	mp_list<eglplus::error_code>
> bad_native_pixmap = {};
#endif

#ifdef EGL_BAD_NATIVE_WINDOW
static constexpr const enum_value<
	EGLenum,
	EGL_BAD_NATIVE_WINDOW,
	mp_list<eglplus::error_code>
> bad_native_window = {};
#endif

#ifdef EGL_BAD_PARAMETER
static constexpr const enum_value<
	EGLenum,
	EGL_BAD_PARAMETER,
	mp_list<eglplus::error_code>
> bad_parameter = {};
#endif

#ifdef EGL_BAD_SURFACE
static constexpr const enum_value<
	EGLenum,
	EGL_BAD_SURFACE,
	mp_list<eglplus::error_code>
> bad_surface = {};
#endif

#ifdef EGL_BIND_TO_TEXTURE_RGB
static constexpr const enum_value<
	EGLenum,
	EGL_BIND_TO_TEXTURE_RGB,
	mp_list<eglplus::config_attrib>
> bind_to_texture_rgb = {};
#endif

#ifdef EGL_BIND_TO_TEXTURE_RGBA
static constexpr const enum_value<
	EGLenum,
	EGL_BIND_TO_TEXTURE_RGBA,
	mp_list<eglplus::config_attrib>
> bind_to_texture_rgba = {};
#endif

#ifdef EGL_BLUE_SIZE
static constexpr const enum_value<
	EGLenum,
	EGL_BLUE_SIZE,
	mp_list<eglplus::config_attrib>
> blue_size = {};
#endif

#ifdef EGL_BUFFER_DESTROYED
static constexpr const enum_value<
	EGLenum,
	EGL_BUFFER_DESTROYED,
	mp_list<eglplus::swap_behavior>
> buffer_destroyed = {};
#endif

#ifdef EGL_BUFFER_PRESERVED
static constexpr const enum_value<
	EGLenum,
	EGL_BUFFER_PRESERVED,
	mp_list<eglplus::swap_behavior>
> buffer_preserved = {};
#endif

#ifdef EGL_BUFFER_SIZE
static constexpr const enum_value<
	EGLenum,
	EGL_BUFFER_SIZE,
	mp_list<eglplus::config_attrib>
> buffer_size = {};
#endif

#ifdef EGL_CLIENT_APIS
static constexpr const enum_value<
	EGLenum,
	EGL_CLIENT_APIS,
	mp_list<eglplus::string_query>
> client_apis = {};
#endif

#ifdef EGL_COLOR_BUFFER_TYPE
static constexpr const enum_value<
	EGLenum,
	EGL_COLOR_BUFFER_TYPE,
	mp_list<eglplus::config_attrib>
> color_buffer_type = {};
#endif

#ifdef EGL_CONFIG_CAVEAT
static constexpr const enum_value<
	EGLenum,
	EGL_CONFIG_CAVEAT,
	mp_list<eglplus::config_attrib>
> config_caveat = {};
#endif

#ifdef EGL_CONFIG_ID
static constexpr const enum_value<
	EGLenum,
	EGL_CONFIG_ID,
	mp_list<eglplus::config_attrib,eglplus::surface_attrib>
> config_id = {};
#endif

#ifdef EGL_CONFORMANT
static constexpr const enum_value<
	EGLenum,
	EGL_CONFORMANT,
	mp_list<eglplus::config_attrib>
> conformant = {};
#endif

#ifdef EGL_CONTEXT_FLAGS
static constexpr const enum_value<
	EGLenum,
	EGL_CONTEXT_FLAGS,
	mp_list<eglplus::context_attrib>
> context_flags = {};
#endif

#ifdef EGL_CONTEXT_LOST
static constexpr const enum_value<
	EGLenum,
	EGL_CONTEXT_LOST,
	mp_list<eglplus::error_code>
> context_lost = {};
#endif

#ifdef EGL_CONTEXT_MAJOR_VERSION
static constexpr const enum_value<
	EGLenum,
	EGL_CONTEXT_MAJOR_VERSION,
	mp_list<eglplus::context_attrib>
> context_major_version = {};
#endif

#ifdef EGL_CONTEXT_MINOR_VERSION
static constexpr const enum_value<
	EGLenum,
	EGL_CONTEXT_MINOR_VERSION,
	mp_list<eglplus::context_attrib>
> context_minor_version = {};
#endif

#ifdef EGL_CONTEXT_OPENGL_COMPATIBILITY_PROFILE_BIT
static constexpr const enum_value<
	EGLenum,
	EGL_CONTEXT_OPENGL_COMPATIBILITY_PROFILE_BIT,
	mp_list<eglplus::opengl_profile_bit>
> context_opengl_compatibility_profile_bit = {};
#endif

#ifdef EGL_CONTEXT_OPENGL_CORE_PROFILE_BIT
static constexpr const enum_value<
	EGLenum,
	EGL_CONTEXT_OPENGL_CORE_PROFILE_BIT,
	mp_list<eglplus::opengl_profile_bit>
> context_opengl_core_profile_bit = {};
#endif

#ifdef EGL_CONTEXT_OPENGL_DEBUG_BIT
static constexpr const enum_value<
	EGLenum,
	EGL_CONTEXT_OPENGL_DEBUG_BIT,
	mp_list<eglplus::context_flag>
> context_opengl_debug_bit = {};
#endif

#ifdef EGL_CONTEXT_OPENGL_FORWARD_COMPATIBLE_BIT
static constexpr const enum_value<
	EGLenum,
	EGL_CONTEXT_OPENGL_FORWARD_COMPATIBLE_BIT,
	mp_list<eglplus::context_flag>
> context_opengl_forward_compatible_bit = {};
#endif

#ifdef EGL_CONTEXT_OPENGL_PROFILE_MASK
static constexpr const enum_value<
	EGLenum,
	EGL_CONTEXT_OPENGL_PROFILE_MASK,
	mp_list<eglplus::context_attrib>
> context_opengl_profile_mask = {};
#endif

#ifdef EGL_CONTEXT_OPENGL_RESET_NOTIFICATION_STRATEGY
static constexpr const enum_value<
	EGLenum,
	EGL_CONTEXT_OPENGL_RESET_NOTIFICATION_STRATEGY,
	mp_list<eglplus::context_attrib>
> context_opengl_reset_notification_strategy = {};
#endif

#ifdef EGL_CONTEXT_OPENGL_ROBUST_ACCESS_BIT
static constexpr const enum_value<
	EGLenum,
	EGL_CONTEXT_OPENGL_ROBUST_ACCESS_BIT,
	mp_list<eglplus::context_flag>
> context_opengl_robust_access_bit = {};
#endif

#ifdef EGL_DEPTH_SIZE
static constexpr const enum_value<
	EGLenum,
	EGL_DEPTH_SIZE,
	mp_list<eglplus::config_attrib>
> depth_size = {};
#endif

#ifdef EGL_EXTENSIONS
static constexpr const enum_value<
	EGLenum,
	EGL_EXTENSIONS,
	mp_list<eglplus::string_query>
> extensions = {};
#endif

#ifdef EGL_GL_COLORSPACE
static constexpr const enum_value<
	EGLenum,
	EGL_GL_COLORSPACE,
	mp_list<eglplus::surface_attrib>
> gl_colorspace = {};
#endif

#ifdef EGL_GL_COLORSPACE_LINEAR
static constexpr const enum_value<
	EGLenum,
	EGL_GL_COLORSPACE_LINEAR,
	mp_list<eglplus::gl_colorspace>
> gl_colorspace_linear = {};
#endif

#ifdef EGL_GL_COLORSPACE_sRGB
static constexpr const enum_value<
	EGLenum,
	EGL_GL_COLORSPACE_sRGB,
	mp_list<eglplus::gl_colorspace>
> gl_colorspace_srgb = {};
#endif

#ifdef EGL_GREEN_SIZE
static constexpr const enum_value<
	EGLenum,
	EGL_GREEN_SIZE,
	mp_list<eglplus::config_attrib>
> green_size = {};
#endif

#ifdef EGL_HEIGHT
static constexpr const enum_value<
	EGLenum,
	EGL_HEIGHT,
	mp_list<eglplus::surface_attrib>
> height = {};
#endif

#ifdef EGL_HORIZONTAL_RESOLUTION
static constexpr const enum_value<
	EGLenum,
	EGL_HORIZONTAL_RESOLUTION,
	mp_list<eglplus::surface_attrib>
> horizontal_resolution = {};
#endif

#ifdef EGL_LARGEST_PBUFFER
static constexpr const enum_value<
	EGLenum,
	EGL_LARGEST_PBUFFER,
	mp_list<eglplus::surface_attrib>
> largest_pbuffer = {};
#endif

#ifdef EGL_LEVEL
static constexpr const enum_value<
	EGLenum,
	EGL_LEVEL,
	mp_list<eglplus::config_attrib>
> level = {};
#endif

#ifdef EGL_LOSE_CONTEXT_ON_RESET
static constexpr const enum_value<
	EGLenum,
	EGL_LOSE_CONTEXT_ON_RESET,
	mp_list<eglplus::opengl_rns>
> lose_context_on_reset = {};
#endif

#ifdef EGL_LUMINANCE_BUFFER
static constexpr const enum_value<
	EGLenum,
	EGL_LUMINANCE_BUFFER,
	mp_list<eglplus::color_buffer_type>
> luminance_buffer = {};
#endif

#ifdef EGL_LUMINANCE_SIZE
static constexpr const enum_value<
	EGLenum,
	EGL_LUMINANCE_SIZE,
	mp_list<eglplus::config_attrib>
> luminance_size = {};
#endif

#ifdef EGL_MAX_PBUFFER_HEIGHT
static constexpr const enum_value<
	EGLenum,
	EGL_MAX_PBUFFER_HEIGHT,
	mp_list<eglplus::config_attrib>
> max_pbuffer_height = {};
#endif

#ifdef EGL_MAX_PBUFFER_PIXELS
static constexpr const enum_value<
	EGLenum,
	EGL_MAX_PBUFFER_PIXELS,
	mp_list<eglplus::config_attrib>
> max_pbuffer_pixels = {};
#endif

#ifdef EGL_MAX_PBUFFER_WIDTH
static constexpr const enum_value<
	EGLenum,
	EGL_MAX_PBUFFER_WIDTH,
	mp_list<eglplus::config_attrib>
> max_pbuffer_width = {};
#endif

#ifdef EGL_MAX_SWAP_INTERVAL
static constexpr const enum_value<
	EGLenum,
	EGL_MAX_SWAP_INTERVAL,
	mp_list<eglplus::config_attrib>
> max_swap_interval = {};
#endif

#ifdef EGL_MIN_SWAP_INTERVAL
static constexpr const enum_value<
	EGLenum,
	EGL_MIN_SWAP_INTERVAL,
	mp_list<eglplus::config_attrib>
> min_swap_interval = {};
#endif

#ifdef EGL_MIPMAP_LEVEL
static constexpr const enum_value<
	EGLenum,
	EGL_MIPMAP_LEVEL,
	mp_list<eglplus::surface_attrib>
> mipmap_level = {};
#endif

#ifdef EGL_MIPMAP_TEXTURE
static constexpr const enum_value<
	EGLenum,
	EGL_MIPMAP_TEXTURE,
	mp_list<eglplus::surface_attrib>
> mipmap_texture = {};
#endif

#ifdef EGL_MULTISAMPLE_RESOLVE
static constexpr const enum_value<
	EGLenum,
	EGL_MULTISAMPLE_RESOLVE,
	mp_list<eglplus::surface_attrib>
> multisample_resolve = {};
#endif

#ifdef EGL_MULTISAMPLE_RESOLVE_BOX
static constexpr const enum_value<
	EGLenum,
	EGL_MULTISAMPLE_RESOLVE_BOX,
	mp_list<eglplus::multisample_resolve>
> multisample_resolve_box = {};
#endif

#ifdef EGL_MULTISAMPLE_RESOLVE_BOX_BIT
static constexpr const enum_value<
	EGLenum,
	EGL_MULTISAMPLE_RESOLVE_BOX_BIT,
	mp_list<eglplus::surface_type_bit>
> multisample_resolve_box_bit = {};
#endif

#ifdef EGL_MULTISAMPLE_RESOLVE_DEFAULT
static constexpr const enum_value<
	EGLenum,
	EGL_MULTISAMPLE_RESOLVE_DEFAULT,
	mp_list<eglplus::multisample_resolve>
> multisample_resolve_default = {};
#endif

#ifdef EGL_NATIVE_RENDERABLE
static constexpr const enum_value<
	EGLenum,
	EGL_NATIVE_RENDERABLE,
	mp_list<eglplus::config_attrib>
> native_renderable = {};
#endif

#ifdef EGL_NATIVE_VISUAL_ID
static constexpr const enum_value<
	EGLenum,
	EGL_NATIVE_VISUAL_ID,
	mp_list<eglplus::config_attrib>
> native_visual_id = {};
#endif

#ifdef EGL_NATIVE_VISUAL_TYPE
static constexpr const enum_value<
	EGLenum,
	EGL_NATIVE_VISUAL_TYPE,
	mp_list<eglplus::config_attrib>
> native_visual_type = {};
#endif

#ifdef EGL_NO_RESET_NOTIFICATION
static constexpr const enum_value<
	EGLenum,
	EGL_NO_RESET_NOTIFICATION,
	mp_list<eglplus::opengl_rns>
> no_reset_notification = {};
#endif

#ifdef EGL_NO_TEXTURE
static constexpr const enum_value<
	EGLenum,
	EGL_NO_TEXTURE,
	mp_list<eglplus::texture_target,eglplus::texture_format>
> no_texture = {};
#endif

#ifdef EGL_NON_CONFORMANT_CONFIG
static constexpr const enum_value<
	EGLenum,
	EGL_NON_CONFORMANT_CONFIG,
	mp_list<eglplus::config_caveat>
> non_conformant_config = {};
#endif

#ifdef EGL_NONE
static constexpr const enum_value<
	EGLenum,
	EGL_NONE,
	mp_list<eglplus::rendering_api,eglplus::config_caveat,eglplus::transparent_type>
> none = {};
#endif

#ifdef EGL_NOT_INITIALIZED
static constexpr const enum_value<
	EGLenum,
	EGL_NOT_INITIALIZED,
	mp_list<eglplus::error_code>
> not_initialized = {};
#endif

#ifdef EGL_OPENGL_API
static constexpr const enum_value<
	EGLenum,
	EGL_OPENGL_API,
	mp_list<eglplus::rendering_api>
> opengl_api = {};
#endif

#ifdef EGL_OPENGL_BIT
static constexpr const enum_value<
	EGLenum,
	EGL_OPENGL_BIT,
	mp_list<eglplus::renderable_type_bit>
> opengl_bit = {};
#endif

#ifdef EGL_OPENGL_ES2_BIT
static constexpr const enum_value<
	EGLenum,
	EGL_OPENGL_ES2_BIT,
	mp_list<eglplus::renderable_type_bit>
> opengl_es2_bit = {};
#endif

#ifdef EGL_OPENGL_ES3_BIT
static constexpr const enum_value<
	EGLenum,
	EGL_OPENGL_ES3_BIT,
	mp_list<eglplus::renderable_type_bit>
> opengl_es3_bit = {};
#endif

#ifdef EGL_OPENGL_ES_API
static constexpr const enum_value<
	EGLenum,
	EGL_OPENGL_ES_API,
	mp_list<eglplus::rendering_api>
> opengl_es_api = {};
#endif

#ifdef EGL_OPENGL_ES_BIT
static constexpr const enum_value<
	EGLenum,
	EGL_OPENGL_ES_BIT,
	mp_list<eglplus::renderable_type_bit>
> opengl_es_bit = {};
#endif

#ifdef EGL_OPENVG_API
static constexpr const enum_value<
	EGLenum,
	EGL_OPENVG_API,
	mp_list<eglplus::rendering_api>
> openvg_api = {};
#endif

#ifdef EGL_OPENVG_BIT
static constexpr const enum_value<
	EGLenum,
	EGL_OPENVG_BIT,
	mp_list<eglplus::renderable_type_bit>
> openvg_bit = {};
#endif

#ifdef EGL_PBUFFER_BIT
static constexpr const enum_value<
	EGLenum,
	EGL_PBUFFER_BIT,
	mp_list<eglplus::surface_type_bit>
> pbuffer_bit = {};
#endif

#ifdef EGL_PIXEL_ASPECT_RATIO
static constexpr const enum_value<
	EGLenum,
	EGL_PIXEL_ASPECT_RATIO,
	mp_list<eglplus::surface_attrib>
> pixel_aspect_ratio = {};
#endif

#ifdef EGL_PIXMAP_BIT
static constexpr const enum_value<
	EGLenum,
	EGL_PIXMAP_BIT,
	mp_list<eglplus::surface_type_bit>
> pixmap_bit = {};
#endif

#ifdef EGL_RED_SIZE
static constexpr const enum_value<
	EGLenum,
	EGL_RED_SIZE,
	mp_list<eglplus::config_attrib>
> red_size = {};
#endif

#ifdef EGL_RENDER_BUFFER
static constexpr const enum_value<
	EGLenum,
	EGL_RENDER_BUFFER,
	mp_list<eglplus::surface_attrib>
> render_buffer = {};
#endif

#ifdef EGL_RENDERABLE_TYPE
static constexpr const enum_value<
	EGLenum,
	EGL_RENDERABLE_TYPE,
	mp_list<eglplus::config_attrib>
> renderable_type = {};
#endif

#ifdef EGL_RGB_BUFFER
static constexpr const enum_value<
	EGLenum,
	EGL_RGB_BUFFER,
	mp_list<eglplus::color_buffer_type>
> rgb_buffer = {};
#endif

#ifdef EGL_SAMPLE_BUFFERS
static constexpr const enum_value<
	EGLenum,
	EGL_SAMPLE_BUFFERS,
	mp_list<eglplus::config_attrib>
> sample_buffers = {};
#endif

#ifdef EGL_SAMPLES
static constexpr const enum_value<
	EGLenum,
	EGL_SAMPLES,
	mp_list<eglplus::config_attrib>
> samples = {};
#endif

#ifdef EGL_SINGLE_BUFFER
static constexpr const enum_value<
	EGLenum,
	EGL_SINGLE_BUFFER,
	mp_list<eglplus::render_buffer>
> single_buffer = {};
#endif

#ifdef EGL_SLOW_CONFIG
static constexpr const enum_value<
	EGLenum,
	EGL_SLOW_CONFIG,
	mp_list<eglplus::config_caveat>
> slow_config = {};
#endif

#ifdef EGL_STENCIL_SIZE
static constexpr const enum_value<
	EGLenum,
	EGL_STENCIL_SIZE,
	mp_list<eglplus::config_attrib>
> stencil_size = {};
#endif

#ifdef EGL_SURFACE_TYPE
static constexpr const enum_value<
	EGLenum,
	EGL_SURFACE_TYPE,
	mp_list<eglplus::config_attrib>
> surface_type = {};
#endif

#ifdef EGL_SWAP_BEHAVIOR
static constexpr const enum_value<
	EGLenum,
	EGL_SWAP_BEHAVIOR,
	mp_list<eglplus::surface_attrib>
> swap_behavior = {};
#endif

#ifdef EGL_SWAP_BEHAVIOR_PRESERVED_BIT
static constexpr const enum_value<
	EGLenum,
	EGL_SWAP_BEHAVIOR_PRESERVED_BIT,
	mp_list<eglplus::surface_type_bit>
> swap_behavior_preserved_bit = {};
#endif

#ifdef EGL_TEXTURE_2D
static constexpr const enum_value<
	EGLenum,
	EGL_TEXTURE_2D,
	mp_list<eglplus::texture_target>
> texture_2d = {};
#endif

#ifdef EGL_TEXTURE_FORMAT
static constexpr const enum_value<
	EGLenum,
	EGL_TEXTURE_FORMAT,
	mp_list<eglplus::surface_attrib>
> texture_format = {};
#endif

#ifdef EGL_TEXTURE_RGB
static constexpr const enum_value<
	EGLenum,
	EGL_TEXTURE_RGB,
	mp_list<eglplus::texture_format>
> texture_rgb = {};
#endif

#ifdef EGL_TEXTURE_RGBA
static constexpr const enum_value<
	EGLenum,
	EGL_TEXTURE_RGBA,
	mp_list<eglplus::texture_format>
> texture_rgba = {};
#endif

#ifdef EGL_TEXTURE_TARGET
static constexpr const enum_value<
	EGLenum,
	EGL_TEXTURE_TARGET,
	mp_list<eglplus::surface_attrib>
> texture_target = {};
#endif

#ifdef EGL_TRANSPARENT_BLUE_VALUE
static constexpr const enum_value<
	EGLenum,
	EGL_TRANSPARENT_BLUE_VALUE,
	mp_list<eglplus::config_attrib>
> transparent_blue_value = {};
#endif

#ifdef EGL_TRANSPARENT_GREEN_VALUE
static constexpr const enum_value<
	EGLenum,
	EGL_TRANSPARENT_GREEN_VALUE,
	mp_list<eglplus::config_attrib>
> transparent_green_value = {};
#endif

#ifdef EGL_TRANSPARENT_RED_VALUE
static constexpr const enum_value<
	EGLenum,
	EGL_TRANSPARENT_RED_VALUE,
	mp_list<eglplus::config_attrib>
> transparent_red_value = {};
#endif

#ifdef EGL_TRANSPARENT_RGB
static constexpr const enum_value<
	EGLenum,
	EGL_TRANSPARENT_RGB,
	mp_list<eglplus::transparent_type>
> transparent_rgb = {};
#endif

#ifdef EGL_TRANSPARENT_TYPE
static constexpr const enum_value<
	EGLenum,
	EGL_TRANSPARENT_TYPE,
	mp_list<eglplus::config_attrib>
> transparent_type = {};
#endif

#ifdef EGL_VENDOR
static constexpr const enum_value<
	EGLenum,
	EGL_VENDOR,
	mp_list<eglplus::string_query>
> vendor = {};
#endif

#ifdef EGL_VERSION
static constexpr const enum_value<
	EGLenum,
	EGL_VERSION,
	mp_list<eglplus::string_query>
> version = {};
#endif

#ifdef EGL_VERTICAL_RESOLUTION
static constexpr const enum_value<
	EGLenum,
	EGL_VERTICAL_RESOLUTION,
	mp_list<eglplus::surface_attrib>
> vertical_resolution = {};
#endif

#ifdef EGL_VG_ALPHA_FORMAT
static constexpr const enum_value<
	EGLenum,
	EGL_VG_ALPHA_FORMAT,
	mp_list<eglplus::surface_attrib>
> vg_alpha_format = {};
#endif

#ifdef EGL_VG_ALPHA_FORMAT_NONPRE
static constexpr const enum_value<
	EGLenum,
	EGL_VG_ALPHA_FORMAT_NONPRE,
	mp_list<eglplus::vg_alpha_format>
> vg_alpha_format_nonpre = {};
#endif

#ifdef EGL_VG_ALPHA_FORMAT_PRE
static constexpr const enum_value<
	EGLenum,
	EGL_VG_ALPHA_FORMAT_PRE,
	mp_list<eglplus::vg_alpha_format>
> vg_alpha_format_pre = {};
#endif

#ifdef EGL_VG_ALPHA_FORMAT_PRE_BIT
static constexpr const enum_value<
	EGLenum,
	EGL_VG_ALPHA_FORMAT_PRE_BIT,
	mp_list<eglplus::surface_type_bit>
> vg_alpha_format_pre_bit = {};
#endif

#ifdef EGL_VG_COLORSPACE
static constexpr const enum_value<
	EGLenum,
	EGL_VG_COLORSPACE,
	mp_list<eglplus::surface_attrib>
> vg_colorspace = {};
#endif

#ifdef EGL_VG_COLORSPACE_LINEAR
static constexpr const enum_value<
	EGLenum,
	EGL_VG_COLORSPACE_LINEAR,
	mp_list<eglplus::vg_colorspace>
> vg_colorspace_linear = {};
#endif

#ifdef EGL_VG_COLORSPACE_LINEAR_BIT
static constexpr const enum_value<
	EGLenum,
	EGL_VG_COLORSPACE_LINEAR_BIT,
	mp_list<eglplus::surface_type_bit>
> vg_colorspace_linear_bit = {};
#endif

#ifdef EGL_VG_COLORSPACE_sRGB
static constexpr const enum_value<
	EGLenum,
	EGL_VG_COLORSPACE_sRGB,
	mp_list<eglplus::vg_colorspace>
> vg_colorspace_srgb = {};
#endif

#ifdef EGL_WIDTH
static constexpr const enum_value<
	EGLenum,
	EGL_WIDTH,
	mp_list<eglplus::surface_attrib>
> width = {};
#endif

#ifdef EGL_WINDOW_BIT
static constexpr const enum_value<
	EGLenum,
	EGL_WINDOW_BIT,
	mp_list<eglplus::surface_type_bit>
> window_bit = {};
#endif

};// struct enum_values
} // namespace eglplus

#endif // include guard
