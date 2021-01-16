/**
 *  @file eglplus/egl_api/constants.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EGLPLUS_EGL_API_CONSTANTS_HPP
#define EGLPLUS_EGL_API_CONSTANTS_HPP

#include "c_api.hpp"
#include "enum_types.hpp"

namespace eagine::eglp {
//------------------------------------------------------------------------------
template <typename ApiTraits>
struct basic_egl_constants {
public:
    // NOLINTNEXTLINE(hicpp-use-nullptr,modernize-use-nullptr)
    static constexpr const typename egl_types::config_type no_config{0};

    static constexpr const typename egl_types::int_type dont_care{
#ifdef EGL_DONT_CARE
      EGL_DONT_CARE
#else
      0
#endif
    };

    using enum_type = typename egl_types::enum_type;
    using enum_type_i = type_identity<enum_type>;
    template <enum_type value>
    using enum_type_c = std::integral_constant<enum_type, value>;

    using int_type = typename egl_types::int_type;
    using int_type_i = type_identity<int_type>;
    template <int_type value>
    using int_type_c = std::integral_constant<int_type, value>;

    opt_c_api_constant<
      mp_list<error_code>,
#ifdef EGL_SUCCESS
      int_type_c<EGL_SUCCESS>>
#else
      int_type_i>
#endif
      success;

    opt_c_api_constant<
      mp_list<error_code>,
#ifdef EGL_NOT_INITIALIZED
      int_type_c<EGL_NOT_INITIALIZED>>
#else
      int_type_i>
#endif
      not_initialized;

    opt_c_api_constant<
      mp_list<error_code>,
#ifdef EGL_BAD_ACCESS
      int_type_c<EGL_BAD_ACCESS>>
#else
      int_type_i>
#endif
      bad_access;

    opt_c_api_constant<
      mp_list<error_code>,
#ifdef EGL_BAD_ALLOC
      int_type_c<EGL_BAD_ALLOC>>
#else
      int_type_i>
#endif
      bad_alloc;

    opt_c_api_constant<
      mp_list<error_code>,
#ifdef EGL_BAD_ATTRIBUTE
      int_type_c<EGL_BAD_ATTRIBUTE>>
#else
      int_type_i>
#endif
      bad_attribute;

    opt_c_api_constant<
      mp_list<error_code>,
#ifdef EGL_BAD_CONTEXT
      int_type_c<EGL_BAD_CONTEXT>>
#else
      int_type_i>
#endif
      bad_context;

    opt_c_api_constant<
      mp_list<error_code>,
#ifdef EGL_BAD_CONFIG
      int_type_c<EGL_BAD_CONFIG>>
#else
      int_type_i>
#endif
      bad_config;

    opt_c_api_constant<
      mp_list<error_code>,
#ifdef EGL_BAD_CURRENT_SURFACE
      int_type_c<EGL_BAD_CURRENT_SURFACE>>
#else
      int_type_i>
#endif
      bad_current_surface;

    opt_c_api_constant<
      mp_list<error_code>,
#ifdef EGL_BAD_DISPLAY
      int_type_c<EGL_BAD_DISPLAY>>
#else
      int_type_i>
#endif
      bad_display;

    opt_c_api_constant<
      mp_list<error_code>,
#ifdef EGL_BAD_SURFACE
      int_type_c<EGL_BAD_SURFACE>>
#else
      int_type_i>
#endif
      bad_surface;

    opt_c_api_constant<
      mp_list<error_code>,
#ifdef EGL_BAD_MATCH
      int_type_c<EGL_BAD_MATCH>>
#else
      int_type_i>
#endif
      bad_match;

    opt_c_api_constant<
      mp_list<error_code>,
#ifdef EGL_BAD_PARAMETER
      int_type_c<EGL_BAD_PARAMETER>>
#else
      int_type_i>
#endif
      bad_parameter;

    opt_c_api_constant<
      mp_list<error_code>,
#ifdef EGL_BAD_NATIVE_PIXMAP
      int_type_c<EGL_BAD_NATIVE_PIXMAP>>
#else
      int_type_i>
#endif
      bad_native_pixmap;

    opt_c_api_constant<
      mp_list<error_code>,
#ifdef EGL_BAD_NATIVE_WINDOW
      int_type_c<EGL_BAD_NATIVE_WINDOW>>
#else
      int_type_i>
#endif
      bad_native_window;

    opt_c_api_constant<
      mp_list<error_code>,
#ifdef EGL_CONTEXT_LOST
      int_type_c<EGL_CONTEXT_LOST>>
#else
      int_type_i>
#endif
      context_lost;

    opt_c_api_constant<
      mp_list<platform>,
#ifdef EGL_PLATFORM_DEVICE_EXT
      int_type_c<EGL_PLATFORM_DEVICE_EXT>
#else
      int_type_i>
#endif
      >
      platform_device;

    opt_c_api_constant<mp_list<platform>, int_type_c<0x31D5>> platform_x11;
    opt_c_api_constant<mp_list<platform>, int_type_c<0x31DC>> platform_xcb;
    opt_c_api_constant<mp_list<platform>, int_type_c<0x31D8>> platform_wayland;
    opt_c_api_constant<mp_list<platform>, int_type_c<0x31D7>> platform_gbm_mesa;
    opt_c_api_constant<mp_list<platform>, int_type_c<0x31DD>>
      platform_surfaceless;
    opt_c_api_constant<mp_list<platform>, int_type_c<0x3141>> platform_android;

    opt_c_api_constant<
      mp_list<string_query>,
#ifdef EGL_CLIENT_APIS
      int_type_c<EGL_CLIENT_APIS>>
#else
      int_type_i>
#endif
      client_apis;

    opt_c_api_constant<
      mp_list<string_query>,
#ifdef EGL_VENDOR
      int_type_c<EGL_VENDOR>>
#else
      int_type_i>
#endif
      vendor;

    opt_c_api_constant<
      mp_list<string_query>,
#ifdef EGL_VERSION
      int_type_c<EGL_VERSION>>
#else
      int_type_i>
#endif
      version;

    opt_c_api_constant<
      mp_list<string_query, device_string_query>,
#ifdef EGL_EXTENSIONS
      int_type_c<EGL_EXTENSIONS>>
#else
      int_type_i>
#endif
      extensions;

    opt_c_api_constant<
      mp_list<string_query, device_string_query>,
      int_type_c<0x3233>>
      drm_device_file;

    opt_c_api_constant<mp_list<platform_attribute>, int_type_c<0x333C>>
      drm_master_fd;

    opt_c_api_constant<
      mp_list<config_attribute>,
#ifdef EGL_CONFIG_ID
      int_type_c<EGL_CONFIG_ID>>
#else
      int_type_i>
#endif
      config_id;

    opt_c_api_constant<
      mp_list<config_attribute>,
#ifdef EGL_CONFORMANT
      int_type_c<EGL_CONFORMANT>>
#else
      int_type_i>
#endif
      conformant;

    opt_c_api_constant<
      mp_list<config_attribute>,
#ifdef EGL_SURFACE_TYPE
      int_type_c<EGL_SURFACE_TYPE>>
#else
      int_type_i>
#endif
      surface_type;

    opt_c_api_constant<
      mp_list<config_attribute>,
#ifdef EGL_RENDERABLE_TYPE
      int_type_c<EGL_RENDERABLE_TYPE>>
#else
      int_type_i>
#endif
      renderable_type;

    opt_c_api_constant<
      mp_list<config_attribute>,
#ifdef EGL_COLOR_BUFFER_TYPE
      int_type_c<EGL_COLOR_BUFFER_TYPE>>
#else
      int_type_i>
#endif
      color_buffer_type;

    opt_c_api_constant<
      mp_list<config_attribute>,
#ifdef EGL_BUFFER_SIZE
      int_type_c<EGL_BUFFER_SIZE>>
#else
      int_type_i>
#endif
      buffer_size;

    opt_c_api_constant<
      mp_list<config_attribute>,
#ifdef EGL_RED_SIZE
      int_type_c<EGL_RED_SIZE>>
#else
      int_type_i>
#endif
      red_size;

    opt_c_api_constant<
      mp_list<config_attribute>,
#ifdef EGL_GREEN_SIZE
      int_type_c<EGL_GREEN_SIZE>>
#else
      int_type_i>
#endif
      green_size;

    opt_c_api_constant<
      mp_list<config_attribute>,
#ifdef EGL_BLUE_SIZE
      int_type_c<EGL_BLUE_SIZE>>
#else
      int_type_i>
#endif
      blue_size;

    opt_c_api_constant<
      mp_list<config_attribute>,
#ifdef EGL_LUMINANCE_SIZE
      int_type_c<EGL_LUMINANCE_SIZE>>
#else
      int_type_i>
#endif
      luminance_size;

    opt_c_api_constant<
      mp_list<config_attribute>,
#ifdef EGL_ALPHA_SIZE
      int_type_c<EGL_ALPHA_SIZE>>
#else
      int_type_i>
#endif
      alpha_size;

    opt_c_api_constant<
      mp_list<config_attribute>,
#ifdef EGL_ALPHA_MASK_SIZE
      int_type_c<EGL_ALPHA_MASK_SIZE>>
#else
      int_type_i>
#endif
      alpha_mask_size;

    opt_c_api_constant<
      mp_list<config_attribute>,
#ifdef EGL_DEPTH_SIZE
      int_type_c<EGL_DEPTH_SIZE>>
#else
      int_type_i>
#endif
      depth_size;

    opt_c_api_constant<
      mp_list<config_attribute>,
#ifdef EGL_STENCIL_SIZE
      int_type_c<EGL_STENCIL_SIZE>>
#else
      int_type_i>
#endif
      stencil_size;

    opt_c_api_constant<
      mp_list<config_attribute>,
#ifdef EGL_SAMPLE_BUFFERS
      int_type_c<EGL_SAMPLE_BUFFERS>>
#else
      int_type_i>
#endif
      sample_buffers;

    opt_c_api_constant<
      mp_list<config_attribute>,
#ifdef EGL_SAMPLES
      int_type_c<EGL_SAMPLES>>
#else
      int_type_i>
#endif
      samples;

    opt_c_api_constant<
      mp_list<config_attribute>,
#ifdef EGL_TRANSPARENT_TYPE
      int_type_c<EGL_TRANSPARENT_TYPE>>
#else
      int_type_i>
#endif
      transparent_type;

    opt_c_api_constant<
      mp_list<config_attribute>,
#ifdef EGL_TRANSPARENT_RED_VALUE
      int_type_c<EGL_TRANSPARENT_RED_VALUE>>
#else
      int_type_i>
#endif
      transparent_red_value;

    opt_c_api_constant<
      mp_list<config_attribute>,
#ifdef EGL_TRANSPARENT_GREEN_VALUE
      int_type_c<EGL_TRANSPARENT_GREEN_VALUE>>
#else
      int_type_i>
#endif
      transparent_green_value;

    opt_c_api_constant<
      mp_list<config_attribute>,
#ifdef EGL_TRANSPARENT_BLUE_VALUE
      int_type_c<EGL_TRANSPARENT_BLUE_VALUE>>
#else
      int_type_i>
#endif
      transparent_blue_value;

    opt_c_api_constant<mp_list<config_attribute>, int_type_c<0x3339>>
      color_component_type;

    opt_c_api_constant<
      mp_list<config_attribute>,
#ifdef EGL_LEVEL
      int_type_c<EGL_LEVEL>>
#else
      int_type_i>
#endif
      level;

    opt_c_api_constant<
      mp_list<config_attribute>,
#ifdef EGL_PBUFFER_WIDTH
      int_type_c<EGL_PBUFFER_WIDTH>>
#else
      int_type_i>
#endif
      pbuffer_width;

    opt_c_api_constant<
      mp_list<config_attribute>,
#ifdef EGL_PBUFFER_HEIGHT
      int_type_c<EGL_PBUFFER_HEIGHT>>
#else
      int_type_i>
#endif
      pbuffer_height;

    opt_c_api_constant<
      mp_list<config_attribute>,
#ifdef EGL_PBUFFER_PIXELS
      int_type_c<EGL_PBUFFER_PIXELS>>
#else
      int_type_i>
#endif
      pbuffer_pixels;

    opt_c_api_constant<
      mp_list<config_attribute>,
#ifdef EGL_MAX_SWAP_INTERVAL
      int_type_c<EGL_MAX_SWAP_INTERVAL>>
#else
      int_type_i>
#endif
      max_swap_interval;

    opt_c_api_constant<
      mp_list<config_attribute>,
#ifdef EGL_MIN_SWAP_INTERVAL
      int_type_c<EGL_MIN_SWAP_INTERVAL>>
#else
      int_type_i>
#endif
      min_swap_interval;

    opt_c_api_constant<
      mp_list<surface_attribute>,
#ifdef EGL_WIDTH
      int_type_c<EGL_WIDTH>>
#else
      int_type_i>
#endif
      width;

    opt_c_api_constant<
      mp_list<surface_attribute>,
#ifdef EGL_HEIGHT
      int_type_c<EGL_HEIGHT>>
#else
      int_type_i>
#endif
      height;

    opt_c_api_constant<
      mp_list<surface_attribute>,
#ifdef EGL_LARGEST_PBUFFER
      int_type_c<EGL_LARGEST_PBUFFER>>
#else
      int_type_i>
#endif
      largest_pbuffer;

    opt_c_api_constant<
      mp_list<surface_attribute>,
#ifdef EGL_GL_COLORSPACE
      int_type_c<EGL_GL_COLORSPACE>>
#else
      int_type_i>
#endif
      gl_colorspace;

    opt_c_api_constant<
      mp_list<surface_attribute>,
#ifdef EGL_MIPMAP_LEVEL
      int_type_c<EGL_MIPMAP_LEVEL>>
#else
      int_type_i>
#endif
      mipmap_level;

    opt_c_api_constant<
      mp_list<surface_attribute>,
#ifdef EGL_MULTISAMPLE_RESOLVE
      int_type_c<EGL_MULTISAMPLE_RESOLVE>>
#else
      int_type_i>
#endif
      multisample_resolve;

    opt_c_api_constant<
      mp_list<surface_attribute>,
#ifdef EGL_SWAP_BEHAVIOR
      int_type_c<EGL_SWAP_BEHAVIOR>>
#else
      int_type_i>
#endif
      swap_behavior;

    opt_c_api_constant<
      mp_list<context_attribute>,
#ifdef EGL_CONTEXT_MAJOR_VERSION
      int_type_c<EGL_CONTEXT_MAJOR_VERSION>>
#else
      int_type_i>
#endif
      context_major_version;

    opt_c_api_constant<
      mp_list<context_attribute>,
#ifdef EGL_CONTEXT_MINOR_VERSION
      int_type_c<EGL_CONTEXT_MINOR_VERSION>>
#else
      int_type_i>
#endif
      context_minor_version;

    opt_c_api_constant<
      mp_list<context_attribute>,
#ifdef EGL_CONTEXT_OPENGL_PROFILE_MASK
      int_type_c<EGL_CONTEXT_OPENGL_PROFILE_MASK>>
#else
      int_type_i>
#endif
      context_opengl_profile_mask;

    opt_c_api_constant<
      mp_list<context_attribute>,
#ifdef EGL_CONTEXT_OPENGL_FORWARD_COMPATIBLE
      int_type_c<EGL_CONTEXT_OPENGL_FORWARD_COMPATIBLE>>
#else
      int_type_i>
#endif
      context_opengl_forward_compatible;

    opt_c_api_constant<
      mp_list<context_attribute>,
#ifdef EGL_CONTEXT_OPENGL_DEBUG
      int_type_c<EGL_CONTEXT_OPENGL_DEBUG>>
#else
      int_type_i>
#endif
      context_opengl_debug;

    opt_c_api_constant<
      mp_list<context_attribute>,
#ifdef EGL_CONTEXT_OPENGL_ROBUST_ACCESS
      int_type_c<EGL_CONTEXT_OPENGL_ROBUST_ACCESS>>
#else
      int_type_i>
#endif
      context_opengl_robust_access;

    opt_c_api_constant<
      mp_list<surface_type_bit>,
#ifdef EGL_WINDOW_BIT
      int_type_c<EGL_WINDOW_BIT>>
#else
      int_type_i>
#endif
      window_bit;

    opt_c_api_constant<
      mp_list<surface_type_bit>,
#ifdef EGL_PIXMAP_BIT
      int_type_c<EGL_PIXMAP_BIT>>
#else
      int_type_i>
#endif
      pixmap_bit;

    opt_c_api_constant<
      mp_list<surface_type_bit>,
#ifdef EGL_PBUFFER_BIT
      int_type_c<EGL_PBUFFER_BIT>>
#else
      int_type_i>
#endif
      pbuffer_bit;

    opt_c_api_constant<mp_list<surface_type_bit>, int_type_c<0x0800>> stream_bit;

    opt_c_api_constant<
      mp_list<surface_type_bit>,
#ifdef EGL_MULTISAMPLE_RESOLVE_BOX_BIT
      int_type_c<EGL_MULTISAMPLE_RESOLVE_BOX_BIT>>
#else
      int_type_i>
#endif
      multisample_resolve_box_bit;

    opt_c_api_constant<
      mp_list<surface_type_bit>,
#ifdef EGL_SWAP_BEHAVIOR_PRESERVED_BIT
      int_type_c<EGL_SWAP_BEHAVIOR_PRESERVED_BIT>>
#else
      int_type_i>
#endif
      swap_behavior_preserved_bit;

    opt_c_api_constant<
      mp_list<surface_type_bit>,
#ifdef EGL_VG_COLORSPACE_LINEAR_BIT
      int_type_c<EGL_VG_COLORSPACE_LINEAR_BIT>>
#else
      int_type_i>
#endif
      vg_colorspace_linear_bit;

    opt_c_api_constant<
      mp_list<surface_type_bit>,
#ifdef EGL_VG_ALPHA_FORMAT_PRE_BIT_BIT
      int_type_c<EGL_VG_ALPHA_FORMAT_PRE_BIT_BIT>>
#else
      int_type_i>
#endif
      vg_alpha_format_pre_bit_bit;

    opt_c_api_constant<mp_list<stream_attribute>, int_type_c<0x3210>>
      consumer_latency_usec;

    opt_c_api_constant<mp_list<stream_attribute>, int_type_c<0x321E>>
      consumer_acquire_timeout_usec;

    opt_c_api_constant<mp_list<stream_attribute>, int_type_c<0x3212>>
      producer_frame;

    opt_c_api_constant<mp_list<stream_attribute>, int_type_c<0x3213>>
      consumer_frame;

    opt_c_api_constant<mp_list<stream_attribute>, int_type_c<0x3214>>
      stream_state;

    opt_c_api_constant<mp_list<eglp::stream_state>, int_type_c<0x3215>>
      stream_state_created;

    opt_c_api_constant<mp_list<eglp::stream_state>, int_type_c<0x3216>>
      stream_state_connecting;

    opt_c_api_constant<mp_list<eglp::stream_state>, int_type_c<0x3217>>
      stream_state_empty;

    opt_c_api_constant<mp_list<eglp::stream_state>, int_type_c<0x3218>>
      stream_state_new_frame_available;

    opt_c_api_constant<mp_list<eglp::stream_state>, int_type_c<0x3219>>
      stream_state_old_frame_available;

    opt_c_api_constant<mp_list<eglp::stream_state>, int_type_c<0x321A>>
      stream_state_disconnected;

    opt_c_api_constant<
      mp_list<client_api_bit, renderable_type_bit>,
#ifdef EGL_OPENGL_BIT
      int_type_c<EGL_OPENGL_BIT>>
#else
      int_type_i>
#endif
      opengl_bit;

    opt_c_api_constant<
      mp_list<client_api_bit, renderable_type_bit>,
#ifdef EGL_OPENGL_ES_BIT
      int_type_c<EGL_OPENGL_ES_BIT>>
#else
      int_type_i>
#endif
      opengl_es_bit;

    opt_c_api_constant<
      mp_list<client_api_bit, renderable_type_bit>,
#ifdef EGL_OPENGL_ES2_BIT
      int_type_c<EGL_OPENGL_ES2_BIT>>
#else
      int_type_i>
#endif
      opengl_es2_bit;

    opt_c_api_constant<
      mp_list<client_api_bit, renderable_type_bit>,
#ifdef EGL_OPENGL_ES3_BIT
      int_type_c<EGL_OPENGL_ES3_BIT>>
#else
      int_type_i>
#endif
      opengl_es3_bit;

    opt_c_api_constant<
      mp_list<client_api_bit, renderable_type_bit>,
#ifdef EGL_OPENVG_BIT
      int_type_c<EGL_OPENVG_BIT>>
#else
      int_type_i>
#endif
      openvg_bit;

    opt_c_api_constant<
      mp_list<client_api>,
#ifdef EGL_OPENGL_API
      int_type_c<EGL_OPENGL_API>>
#else
      int_type_i>
#endif
      opengl_api;

    opt_c_api_constant<
      mp_list<client_api>,
#ifdef EGL_OPENGL_ES_API
      int_type_c<EGL_OPENGL_ES_API>>
#else
      int_type_i>
#endif
      opengl_es_api;

    opt_c_api_constant<
      mp_list<client_api>,
#ifdef EGL_OPENVG_API
      int_type_c<EGL_OPENVG_API>>
#else
      int_type_i>
#endif
      openvg_api;

    opt_c_api_constant<
      mp_list<eglp::context_opengl_profile_bit>,
#ifdef EGL_CONTEXT_OPENGL_CORE_PROFILE_BIT
      int_type_c<EGL_CONTEXT_OPENGL_CORE_PROFILE_BIT>>
#else
      int_type_i>
#endif
      context_opengl_core_profile_bit;

    opt_c_api_constant<
      mp_list<eglp::context_opengl_profile_bit>,
#ifdef EGL_CONTEXT_OPENGL_COMPATIBILITY_PROFILE_BIT
      int_type_c<EGL_CONTEXT_OPENGL_COMPATIBILITY_PROFILE_BIT>>
#else
      int_type_i>
#endif
      context_opengl_compatibility_profile_bit;

    opt_c_api_constant<
      mp_list<eglp::color_buffer_type>,
#ifdef EGL_RGB_BUFFER
      int_type_c<EGL_RGB_BUFFER>>
#else
      int_type_i>
#endif
      rgb_buffer;

    opt_c_api_constant<
      mp_list<eglp::color_buffer_type>,
#ifdef EGL_LUMINANCE_BUFFER
      int_type_c<EGL_LUMINANCE_BUFFER>>
#else
      int_type_i>
#endif
      luminance_buffer;

    opt_c_api_constant<mp_list<eglp::color_component_type>, int_type_c<0x333A>>
      color_component_type_fixed;

    opt_c_api_constant<mp_list<eglp::color_component_type>, int_type_c<0x333B>>
      color_component_type_float;

    opt_c_api_constant<
      mp_list<eglp::read_draw>,
#ifdef EGL_READ
      int_type_c<EGL_READ>>
#else
      int_type_i>
#endif
      read;

    opt_c_api_constant<
      mp_list<eglp::read_draw>,
#ifdef EGL_DRAW
      int_type_c<EGL_DRAW>>
#else
      int_type_i>
#endif
      draw;

    opt_c_api_constant<
      mp_list<eglp::sync_type>,
#ifdef EGL_SYNC_FENCE
      int_type_c<EGL_SYNC_FENCE>>
#else
      int_type_i>
#endif
      sync_fence;

    opt_c_api_constant<
      mp_list<eglp::sync_type>,
#ifdef EGL_SYNC_CL_EVENT
      int_type_c<EGL_SYNC_CL_EVENT>>
#else
      int_type_i>
#endif
      sync_cl_event;

    opt_c_api_constant<
      mp_list<eglp::texture_format, eglp::texture_target>,
#ifdef EGL_NO_TEXTURE
      int_type_c<EGL_NO_TEXTURE>>
#else
      int_type_i>
#endif
      no_texture;

    opt_c_api_constant<
      mp_list<eglp::texture_target>,
#ifdef EGL_TEXTURE_2D
      int_type_c<EGL_TEXTURE_2D>>
#else
      int_type_i>
#endif
      texture_2d;

    opt_c_api_constant<
      mp_list<eglp::texture_format>,
#ifdef EGL_TEXTURE_RGB
      int_type_c<EGL_TEXTURE_RGB>>
#else
      int_type_i>
#endif
      texture_rgb;

    opt_c_api_constant<
      mp_list<eglp::texture_format>,
#ifdef EGL_TEXTURE_RGBA
      int_type_c<EGL_TEXTURE_RGBA>>
#else
      int_type_i>
#endif
      texture_rgba;

    opt_c_api_constant<
      mp_list<eglp::gl_colorspace>,
#ifdef EGL_GL_COLORSPACE_LINEAR
      int_type_c<EGL_GL_COLORSPACE_LINEAR>>
#else
      int_type_i>
#endif
      gl_colorspace_linear;

    opt_c_api_constant<
      mp_list<eglp::gl_colorspace>,
#ifdef EGL_GL_COLORSPACE_SRGB
      int_type_c<EGL_GL_COLORSPACE_SRGB>>
#else
      int_type_i>
#endif
      gl_colorspace_srgb;

    opt_c_api_constant<
      mp_list<eglp::config_caveat>,
#ifdef EGL_NONE
      int_type_c<EGL_NONE>>
#else
      int_type_i>
#endif
      none;

    basic_egl_constants(ApiTraits& traits, basic_egl_c_api<ApiTraits>& api)
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
};
//------------------------------------------------------------------------------
} // namespace eagine::eglp

#endif // EGLPLUS_EGL_API_CONSTANTS_HPP
