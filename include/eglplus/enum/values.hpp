//  File include/eglplus/enum/values.hpp
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
#ifndef EGLPLUS_EGL_ENUM_VALUES_HPP
#define EGLPLUS_EGL_ENUM_VALUES_HPP

#include "../utils/mp_list.hpp"
#include "types.hpp"

namespace eglplus {
struct enum_values {

#ifdef EGL_ALPHA_MASK_SIZE
    static constexpr const enum_value<EGLenum, mp_list<eglplus::config_attrib>>
      alpha_mask_size = {EGL_ALPHA_MASK_SIZE};
#endif

#ifdef EGL_ALPHA_SIZE
    static constexpr const enum_value<EGLenum, mp_list<eglplus::config_attrib>>
      alpha_size = {EGL_ALPHA_SIZE};
#endif

#ifdef EGL_BACK_BUFFER
    static constexpr const enum_value<EGLenum, mp_list<eglplus::render_buffer>>
      back_buffer = {EGL_BACK_BUFFER};
#endif

#ifdef EGL_BAD_ACCESS
    static constexpr const enum_value<EGLenum, mp_list<eglplus::error_code>>
      bad_access = {EGL_BAD_ACCESS};
#endif

#ifdef EGL_BAD_ALLOC
    static constexpr const enum_value<EGLenum, mp_list<eglplus::error_code>>
      bad_alloc = {EGL_BAD_ALLOC};
#endif

#ifdef EGL_BAD_ATTRIBUTE
    static constexpr const enum_value<EGLenum, mp_list<eglplus::error_code>>
      bad_attribute = {EGL_BAD_ATTRIBUTE};
#endif

#ifdef EGL_BAD_CONFIG
    static constexpr const enum_value<EGLenum, mp_list<eglplus::error_code>>
      bad_config = {EGL_BAD_CONFIG};
#endif

#ifdef EGL_BAD_CONTEXT
    static constexpr const enum_value<EGLenum, mp_list<eglplus::error_code>>
      bad_context = {EGL_BAD_CONTEXT};
#endif

#ifdef EGL_BAD_CURRENT_SURFACE
    static constexpr const enum_value<EGLenum, mp_list<eglplus::error_code>>
      bad_current_surface = {EGL_BAD_CURRENT_SURFACE};
#endif

#ifdef EGL_BAD_DISPLAY
    static constexpr const enum_value<EGLenum, mp_list<eglplus::error_code>>
      bad_display = {EGL_BAD_DISPLAY};
#endif

#ifdef EGL_BAD_MATCH
    static constexpr const enum_value<EGLenum, mp_list<eglplus::error_code>>
      bad_match = {EGL_BAD_MATCH};
#endif

#ifdef EGL_BAD_NATIVE_PIXMAP
    static constexpr const enum_value<EGLenum, mp_list<eglplus::error_code>>
      bad_native_pixmap = {EGL_BAD_NATIVE_PIXMAP};
#endif

#ifdef EGL_BAD_NATIVE_WINDOW
    static constexpr const enum_value<EGLenum, mp_list<eglplus::error_code>>
      bad_native_window = {EGL_BAD_NATIVE_WINDOW};
#endif

#ifdef EGL_BAD_PARAMETER
    static constexpr const enum_value<EGLenum, mp_list<eglplus::error_code>>
      bad_parameter = {EGL_BAD_PARAMETER};
#endif

#ifdef EGL_BAD_SURFACE
    static constexpr const enum_value<EGLenum, mp_list<eglplus::error_code>>
      bad_surface = {EGL_BAD_SURFACE};
#endif

#ifdef EGL_BIND_TO_TEXTURE_RGB
    static constexpr const enum_value<EGLenum, mp_list<eglplus::config_attrib>>
      bind_to_texture_rgb = {EGL_BIND_TO_TEXTURE_RGB};
#endif

#ifdef EGL_BIND_TO_TEXTURE_RGBA
    static constexpr const enum_value<EGLenum, mp_list<eglplus::config_attrib>>
      bind_to_texture_rgba = {EGL_BIND_TO_TEXTURE_RGBA};
#endif

#ifdef EGL_BLUE_SIZE
    static constexpr const enum_value<EGLenum, mp_list<eglplus::config_attrib>>
      blue_size = {EGL_BLUE_SIZE};
#endif

#ifdef EGL_BUFFER_DESTROYED
    static constexpr const enum_value<EGLenum, mp_list<eglplus::swap_behavior>>
      buffer_destroyed = {EGL_BUFFER_DESTROYED};
#endif

#ifdef EGL_BUFFER_PRESERVED
    static constexpr const enum_value<EGLenum, mp_list<eglplus::swap_behavior>>
      buffer_preserved = {EGL_BUFFER_PRESERVED};
#endif

#ifdef EGL_BUFFER_SIZE
    static constexpr const enum_value<EGLenum, mp_list<eglplus::config_attrib>>
      buffer_size = {EGL_BUFFER_SIZE};
#endif

#ifdef EGL_CLIENT_APIS
    static constexpr const enum_value<EGLenum, mp_list<eglplus::string_query>>
      client_apis = {EGL_CLIENT_APIS};
#endif

#ifdef EGL_COLOR_BUFFER_TYPE
    static constexpr const enum_value<EGLenum, mp_list<eglplus::config_attrib>>
      color_buffer_type = {EGL_COLOR_BUFFER_TYPE};
#endif

#ifdef EGL_CONFIG_CAVEAT
    static constexpr const enum_value<EGLenum, mp_list<eglplus::config_attrib>>
      config_caveat = {EGL_CONFIG_CAVEAT};
#endif

#ifdef EGL_CONFIG_ID
    static constexpr const enum_value<
      EGLenum,
      mp_list<eglplus::config_attrib, eglplus::surface_attrib>>
      config_id = {EGL_CONFIG_ID};
#endif

#ifdef EGL_CONFORMANT
    static constexpr const enum_value<EGLenum, mp_list<eglplus::config_attrib>>
      conformant = {EGL_CONFORMANT};
#endif

#ifdef EGL_CONTEXT_FLAGS
    static constexpr const enum_value<EGLenum, mp_list<eglplus::context_attrib>>
      context_flags = {EGL_CONTEXT_FLAGS};
#endif

#ifdef EGL_CONTEXT_LOST
    static constexpr const enum_value<EGLenum, mp_list<eglplus::error_code>>
      context_lost = {EGL_CONTEXT_LOST};
#endif

#ifdef EGL_CONTEXT_MAJOR_VERSION
    static constexpr const enum_value<EGLenum, mp_list<eglplus::context_attrib>>
      context_major_version = {EGL_CONTEXT_MAJOR_VERSION};
#endif

#ifdef EGL_CONTEXT_MINOR_VERSION
    static constexpr const enum_value<EGLenum, mp_list<eglplus::context_attrib>>
      context_minor_version = {EGL_CONTEXT_MINOR_VERSION};
#endif

#ifdef EGL_CONTEXT_OPENGL_COMPATIBILITY_PROFILE_BIT
    static constexpr const enum_value<
      EGLenum,
      mp_list<eglplus::opengl_profile_bit>>
      context_opengl_compatibility_profile_bit = {
        EGL_CONTEXT_OPENGL_COMPATIBILITY_PROFILE_BIT};
#endif

#ifdef EGL_CONTEXT_OPENGL_CORE_PROFILE_BIT
    static constexpr const enum_value<
      EGLenum,
      mp_list<eglplus::opengl_profile_bit>>
      context_opengl_core_profile_bit = {EGL_CONTEXT_OPENGL_CORE_PROFILE_BIT};
#endif

#ifdef EGL_CONTEXT_OPENGL_DEBUG_BIT
    static constexpr const enum_value<EGLenum, mp_list<eglplus::context_flag>>
      context_opengl_debug_bit = {EGL_CONTEXT_OPENGL_DEBUG_BIT};
#endif

#ifdef EGL_CONTEXT_OPENGL_FORWARD_COMPATIBLE_BIT
    static constexpr const enum_value<EGLenum, mp_list<eglplus::context_flag>>
      context_opengl_forward_compatible_bit = {
        EGL_CONTEXT_OPENGL_FORWARD_COMPATIBLE_BIT};
#endif

#ifdef EGL_CONTEXT_OPENGL_PROFILE_MASK
    static constexpr const enum_value<EGLenum, mp_list<eglplus::context_attrib>>
      context_opengl_profile_mask = {EGL_CONTEXT_OPENGL_PROFILE_MASK};
#endif

#ifdef EGL_CONTEXT_OPENGL_RESET_NOTIFICATION_STRATEGY
    static constexpr const enum_value<EGLenum, mp_list<eglplus::context_attrib>>
      context_opengl_reset_notification_strategy = {
        EGL_CONTEXT_OPENGL_RESET_NOTIFICATION_STRATEGY};
#endif

#ifdef EGL_CONTEXT_OPENGL_ROBUST_ACCESS_BIT
    static constexpr const enum_value<EGLenum, mp_list<eglplus::context_flag>>
      context_opengl_robust_access_bit = {EGL_CONTEXT_OPENGL_ROBUST_ACCESS_BIT};
#endif

#ifdef EGL_DEPTH_SIZE
    static constexpr const enum_value<EGLenum, mp_list<eglplus::config_attrib>>
      depth_size = {EGL_DEPTH_SIZE};
#endif

#ifdef EGL_EXTENSIONS
    static constexpr const enum_value<EGLenum, mp_list<eglplus::string_query>>
      extensions = {EGL_EXTENSIONS};
#endif

#ifdef EGL_GL_COLORSPACE
    static constexpr const enum_value<EGLenum, mp_list<eglplus::surface_attrib>>
      gl_colorspace = {EGL_GL_COLORSPACE};
#endif

#ifdef EGL_GL_COLORSPACE_LINEAR
    static constexpr const enum_value<EGLenum, mp_list<eglplus::gl_colorspace>>
      gl_colorspace_linear = {EGL_GL_COLORSPACE_LINEAR};
#endif

#ifdef EGL_GL_COLORSPACE_sRGB
    static constexpr const enum_value<EGLenum, mp_list<eglplus::gl_colorspace>>
      gl_colorspace_srgb = {EGL_GL_COLORSPACE_sRGB};
#endif

#ifdef EGL_GREEN_SIZE
    static constexpr const enum_value<EGLenum, mp_list<eglplus::config_attrib>>
      green_size = {EGL_GREEN_SIZE};
#endif

#ifdef EGL_HEIGHT
    static constexpr const enum_value<EGLenum, mp_list<eglplus::surface_attrib>>
      height = {EGL_HEIGHT};
#endif

#ifdef EGL_HORIZONTAL_RESOLUTION
    static constexpr const enum_value<EGLenum, mp_list<eglplus::surface_attrib>>
      horizontal_resolution = {EGL_HORIZONTAL_RESOLUTION};
#endif

#ifdef EGL_LARGEST_PBUFFER
    static constexpr const enum_value<EGLenum, mp_list<eglplus::surface_attrib>>
      largest_pbuffer = {EGL_LARGEST_PBUFFER};
#endif

#ifdef EGL_LEVEL
    static constexpr const enum_value<EGLenum, mp_list<eglplus::config_attrib>>
      level = {EGL_LEVEL};
#endif

#ifdef EGL_LOSE_CONTEXT_ON_RESET
    static constexpr const enum_value<EGLenum, mp_list<eglplus::opengl_rns>>
      lose_context_on_reset = {EGL_LOSE_CONTEXT_ON_RESET};
#endif

#ifdef EGL_LUMINANCE_BUFFER
    static constexpr const enum_value<
      EGLenum,
      mp_list<eglplus::color_buffer_type>>
      luminance_buffer = {EGL_LUMINANCE_BUFFER};
#endif

#ifdef EGL_LUMINANCE_SIZE
    static constexpr const enum_value<EGLenum, mp_list<eglplus::config_attrib>>
      luminance_size = {EGL_LUMINANCE_SIZE};
#endif

#ifdef EGL_MAX_PBUFFER_HEIGHT
    static constexpr const enum_value<EGLenum, mp_list<eglplus::config_attrib>>
      max_pbuffer_height = {EGL_MAX_PBUFFER_HEIGHT};
#endif

#ifdef EGL_MAX_PBUFFER_PIXELS
    static constexpr const enum_value<EGLenum, mp_list<eglplus::config_attrib>>
      max_pbuffer_pixels = {EGL_MAX_PBUFFER_PIXELS};
#endif

#ifdef EGL_MAX_PBUFFER_WIDTH
    static constexpr const enum_value<EGLenum, mp_list<eglplus::config_attrib>>
      max_pbuffer_width = {EGL_MAX_PBUFFER_WIDTH};
#endif

#ifdef EGL_MAX_SWAP_INTERVAL
    static constexpr const enum_value<EGLenum, mp_list<eglplus::config_attrib>>
      max_swap_interval = {EGL_MAX_SWAP_INTERVAL};
#endif

#ifdef EGL_MIN_SWAP_INTERVAL
    static constexpr const enum_value<EGLenum, mp_list<eglplus::config_attrib>>
      min_swap_interval = {EGL_MIN_SWAP_INTERVAL};
#endif

#ifdef EGL_MIPMAP_LEVEL
    static constexpr const enum_value<EGLenum, mp_list<eglplus::surface_attrib>>
      mipmap_level = {EGL_MIPMAP_LEVEL};
#endif

#ifdef EGL_MIPMAP_TEXTURE
    static constexpr const enum_value<EGLenum, mp_list<eglplus::surface_attrib>>
      mipmap_texture = {EGL_MIPMAP_TEXTURE};
#endif

#ifdef EGL_MULTISAMPLE_RESOLVE
    static constexpr const enum_value<EGLenum, mp_list<eglplus::surface_attrib>>
      multisample_resolve = {EGL_MULTISAMPLE_RESOLVE};
#endif

#ifdef EGL_MULTISAMPLE_RESOLVE_BOX
    static constexpr const enum_value<
      EGLenum,
      mp_list<eglplus::multisample_resolve>>
      multisample_resolve_box = {EGL_MULTISAMPLE_RESOLVE_BOX};
#endif

#ifdef EGL_MULTISAMPLE_RESOLVE_BOX_BIT
    static constexpr const enum_value<
      EGLenum,
      mp_list<eglplus::surface_type_bit>>
      multisample_resolve_box_bit = {EGL_MULTISAMPLE_RESOLVE_BOX_BIT};
#endif

#ifdef EGL_MULTISAMPLE_RESOLVE_DEFAULT
    static constexpr const enum_value<
      EGLenum,
      mp_list<eglplus::multisample_resolve>>
      multisample_resolve_default = {EGL_MULTISAMPLE_RESOLVE_DEFAULT};
#endif

#ifdef EGL_NATIVE_RENDERABLE
    static constexpr const enum_value<EGLenum, mp_list<eglplus::config_attrib>>
      native_renderable = {EGL_NATIVE_RENDERABLE};
#endif

#ifdef EGL_NATIVE_VISUAL_ID
    static constexpr const enum_value<EGLenum, mp_list<eglplus::config_attrib>>
      native_visual_id = {EGL_NATIVE_VISUAL_ID};
#endif

#ifdef EGL_NATIVE_VISUAL_TYPE
    static constexpr const enum_value<EGLenum, mp_list<eglplus::config_attrib>>
      native_visual_type = {EGL_NATIVE_VISUAL_TYPE};
#endif

#ifdef EGL_NO_RESET_NOTIFICATION
    static constexpr const enum_value<EGLenum, mp_list<eglplus::opengl_rns>>
      no_reset_notification = {EGL_NO_RESET_NOTIFICATION};
#endif

#ifdef EGL_NO_TEXTURE
    static constexpr const enum_value<
      EGLenum,
      mp_list<eglplus::texture_target, eglplus::texture_format>>
      no_texture = {EGL_NO_TEXTURE};
#endif

#ifdef EGL_NON_CONFORMANT_CONFIG
    static constexpr const enum_value<EGLenum, mp_list<eglplus::config_caveat>>
      non_conformant_config = {EGL_NON_CONFORMANT_CONFIG};
#endif

#ifdef EGL_NONE
    static constexpr const enum_value<
      EGLenum,
      mp_list<
        eglplus::rendering_api,
        eglplus::config_caveat,
        eglplus::transparent_type>>
      none = {EGL_NONE};
#endif

#ifdef EGL_NOT_INITIALIZED
    static constexpr const enum_value<EGLenum, mp_list<eglplus::error_code>>
      not_initialized = {EGL_NOT_INITIALIZED};
#endif

#ifdef EGL_OPENGL_API
    static constexpr const enum_value<EGLenum, mp_list<eglplus::rendering_api>>
      opengl_api = {EGL_OPENGL_API};
#endif

#ifdef EGL_OPENGL_BIT
    static constexpr const enum_value<
      EGLenum,
      mp_list<eglplus::renderable_type_bit>>
      opengl_bit = {EGL_OPENGL_BIT};
#endif

#ifdef EGL_OPENGL_ES2_BIT
    static constexpr const enum_value<
      EGLenum,
      mp_list<eglplus::renderable_type_bit>>
      opengl_es2_bit = {EGL_OPENGL_ES2_BIT};
#endif

#ifdef EGL_OPENGL_ES3_BIT
    static constexpr const enum_value<
      EGLenum,
      mp_list<eglplus::renderable_type_bit>>
      opengl_es3_bit = {EGL_OPENGL_ES3_BIT};
#endif

#ifdef EGL_OPENGL_ES_API
    static constexpr const enum_value<EGLenum, mp_list<eglplus::rendering_api>>
      opengl_es_api = {EGL_OPENGL_ES_API};
#endif

#ifdef EGL_OPENGL_ES_BIT
    static constexpr const enum_value<
      EGLenum,
      mp_list<eglplus::renderable_type_bit>>
      opengl_es_bit = {EGL_OPENGL_ES_BIT};
#endif

#ifdef EGL_OPENVG_API
    static constexpr const enum_value<EGLenum, mp_list<eglplus::rendering_api>>
      openvg_api = {EGL_OPENVG_API};
#endif

#ifdef EGL_OPENVG_BIT
    static constexpr const enum_value<
      EGLenum,
      mp_list<eglplus::renderable_type_bit>>
      openvg_bit = {EGL_OPENVG_BIT};
#endif

#ifdef EGL_PBUFFER_BIT
    static constexpr const enum_value<
      EGLenum,
      mp_list<eglplus::surface_type_bit>>
      pbuffer_bit = {EGL_PBUFFER_BIT};
#endif

#ifdef EGL_PIXEL_ASPECT_RATIO
    static constexpr const enum_value<EGLenum, mp_list<eglplus::surface_attrib>>
      pixel_aspect_ratio = {EGL_PIXEL_ASPECT_RATIO};
#endif

#ifdef EGL_PIXMAP_BIT
    static constexpr const enum_value<
      EGLenum,
      mp_list<eglplus::surface_type_bit>>
      pixmap_bit = {EGL_PIXMAP_BIT};
#endif

#ifdef EGL_RED_SIZE
    static constexpr const enum_value<EGLenum, mp_list<eglplus::config_attrib>>
      red_size = {EGL_RED_SIZE};
#endif

#ifdef EGL_RENDER_BUFFER
    static constexpr const enum_value<EGLenum, mp_list<eglplus::surface_attrib>>
      render_buffer = {EGL_RENDER_BUFFER};
#endif

#ifdef EGL_RENDERABLE_TYPE
    static constexpr const enum_value<EGLenum, mp_list<eglplus::config_attrib>>
      renderable_type = {EGL_RENDERABLE_TYPE};
#endif

#ifdef EGL_RGB_BUFFER
    static constexpr const enum_value<
      EGLenum,
      mp_list<eglplus::color_buffer_type>>
      rgb_buffer = {EGL_RGB_BUFFER};
#endif

#ifdef EGL_SAMPLE_BUFFERS
    static constexpr const enum_value<EGLenum, mp_list<eglplus::config_attrib>>
      sample_buffers = {EGL_SAMPLE_BUFFERS};
#endif

#ifdef EGL_SAMPLES
    static constexpr const enum_value<EGLenum, mp_list<eglplus::config_attrib>>
      samples = {EGL_SAMPLES};
#endif

#ifdef EGL_SINGLE_BUFFER
    static constexpr const enum_value<EGLenum, mp_list<eglplus::render_buffer>>
      single_buffer = {EGL_SINGLE_BUFFER};
#endif

#ifdef EGL_SLOW_CONFIG
    static constexpr const enum_value<EGLenum, mp_list<eglplus::config_caveat>>
      slow_config = {EGL_SLOW_CONFIG};
#endif

#ifdef EGL_STENCIL_SIZE
    static constexpr const enum_value<EGLenum, mp_list<eglplus::config_attrib>>
      stencil_size = {EGL_STENCIL_SIZE};
#endif

#ifdef EGL_SURFACE_TYPE
    static constexpr const enum_value<EGLenum, mp_list<eglplus::config_attrib>>
      surface_type = {EGL_SURFACE_TYPE};
#endif

#ifdef EGL_SWAP_BEHAVIOR
    static constexpr const enum_value<EGLenum, mp_list<eglplus::surface_attrib>>
      swap_behavior = {EGL_SWAP_BEHAVIOR};
#endif

#ifdef EGL_SWAP_BEHAVIOR_PRESERVED_BIT
    static constexpr const enum_value<
      EGLenum,
      mp_list<eglplus::surface_type_bit>>
      swap_behavior_preserved_bit = {EGL_SWAP_BEHAVIOR_PRESERVED_BIT};
#endif

#ifdef EGL_TEXTURE_2D
    static constexpr const enum_value<EGLenum, mp_list<eglplus::texture_target>>
      texture_2d = {EGL_TEXTURE_2D};
#endif

#ifdef EGL_TEXTURE_FORMAT
    static constexpr const enum_value<EGLenum, mp_list<eglplus::surface_attrib>>
      texture_format = {EGL_TEXTURE_FORMAT};
#endif

#ifdef EGL_TEXTURE_RGB
    static constexpr const enum_value<EGLenum, mp_list<eglplus::texture_format>>
      texture_rgb = {EGL_TEXTURE_RGB};
#endif

#ifdef EGL_TEXTURE_RGBA
    static constexpr const enum_value<EGLenum, mp_list<eglplus::texture_format>>
      texture_rgba = {EGL_TEXTURE_RGBA};
#endif

#ifdef EGL_TEXTURE_TARGET
    static constexpr const enum_value<EGLenum, mp_list<eglplus::surface_attrib>>
      texture_target = {EGL_TEXTURE_TARGET};
#endif

#ifdef EGL_TRANSPARENT_BLUE_VALUE
    static constexpr const enum_value<EGLenum, mp_list<eglplus::config_attrib>>
      transparent_blue_value = {EGL_TRANSPARENT_BLUE_VALUE};
#endif

#ifdef EGL_TRANSPARENT_GREEN_VALUE
    static constexpr const enum_value<EGLenum, mp_list<eglplus::config_attrib>>
      transparent_green_value = {EGL_TRANSPARENT_GREEN_VALUE};
#endif

#ifdef EGL_TRANSPARENT_RED_VALUE
    static constexpr const enum_value<EGLenum, mp_list<eglplus::config_attrib>>
      transparent_red_value = {EGL_TRANSPARENT_RED_VALUE};
#endif

#ifdef EGL_TRANSPARENT_RGB
    static constexpr const enum_value<
      EGLenum,
      mp_list<eglplus::transparent_type>>
      transparent_rgb = {EGL_TRANSPARENT_RGB};
#endif

#ifdef EGL_TRANSPARENT_TYPE
    static constexpr const enum_value<EGLenum, mp_list<eglplus::config_attrib>>
      transparent_type = {EGL_TRANSPARENT_TYPE};
#endif

#ifdef EGL_VENDOR
    static constexpr const enum_value<EGLenum, mp_list<eglplus::string_query>>
      vendor = {EGL_VENDOR};
#endif

#ifdef EGL_VERSION
    static constexpr const enum_value<EGLenum, mp_list<eglplus::string_query>>
      version = {EGL_VERSION};
#endif

#ifdef EGL_VERTICAL_RESOLUTION
    static constexpr const enum_value<EGLenum, mp_list<eglplus::surface_attrib>>
      vertical_resolution = {EGL_VERTICAL_RESOLUTION};
#endif

#ifdef EGL_VG_ALPHA_FORMAT
    static constexpr const enum_value<EGLenum, mp_list<eglplus::surface_attrib>>
      vg_alpha_format = {EGL_VG_ALPHA_FORMAT};
#endif

#ifdef EGL_VG_ALPHA_FORMAT_NONPRE
    static constexpr const enum_value<
      EGLenum,
      mp_list<eglplus::vg_alpha_format>>
      vg_alpha_format_nonpre = {EGL_VG_ALPHA_FORMAT_NONPRE};
#endif

#ifdef EGL_VG_ALPHA_FORMAT_PRE
    static constexpr const enum_value<
      EGLenum,
      mp_list<eglplus::vg_alpha_format>>
      vg_alpha_format_pre = {EGL_VG_ALPHA_FORMAT_PRE};
#endif

#ifdef EGL_VG_ALPHA_FORMAT_PRE_BIT
    static constexpr const enum_value<
      EGLenum,
      mp_list<eglplus::surface_type_bit>>
      vg_alpha_format_pre_bit = {EGL_VG_ALPHA_FORMAT_PRE_BIT};
#endif

#ifdef EGL_VG_COLORSPACE
    static constexpr const enum_value<EGLenum, mp_list<eglplus::surface_attrib>>
      vg_colorspace = {EGL_VG_COLORSPACE};
#endif

#ifdef EGL_VG_COLORSPACE_LINEAR
    static constexpr const enum_value<EGLenum, mp_list<eglplus::vg_colorspace>>
      vg_colorspace_linear = {EGL_VG_COLORSPACE_LINEAR};
#endif

#ifdef EGL_VG_COLORSPACE_LINEAR_BIT
    static constexpr const enum_value<
      EGLenum,
      mp_list<eglplus::surface_type_bit>>
      vg_colorspace_linear_bit = {EGL_VG_COLORSPACE_LINEAR_BIT};
#endif

#ifdef EGL_VG_COLORSPACE_sRGB
    static constexpr const enum_value<EGLenum, mp_list<eglplus::vg_colorspace>>
      vg_colorspace_srgb = {EGL_VG_COLORSPACE_sRGB};
#endif

#ifdef EGL_WIDTH
    static constexpr const enum_value<EGLenum, mp_list<eglplus::surface_attrib>>
      width = {EGL_WIDTH};
#endif

#ifdef EGL_WINDOW_BIT
    static constexpr const enum_value<
      EGLenum,
      mp_list<eglplus::surface_type_bit>>
      window_bit = {EGL_WINDOW_BIT};
#endif

}; // struct enum_values
} // namespace eglplus

#endif // include guard
