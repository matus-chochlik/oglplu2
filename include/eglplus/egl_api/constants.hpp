/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef EGLPLUS_EGL_API_CONSTANTS_HPP
#define EGLPLUS_EGL_API_CONSTANTS_HPP

#include "c_api.hpp"
#include "enum_types.hpp"

namespace eagine::eglp {
//------------------------------------------------------------------------------
/// @brief Class wrapping the constants from the EGL API.
/// @ingroup egl_api_wrap
/// @see basic_egl_c_api
/// @see basic_egl_operations
template <typename ApiTraits>
class basic_egl_constants {
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

    /// @var success
    /// @eglconstwrap{SUCCESS}
    opt_c_api_constant<
      mp_list<error_code>,
#ifdef EGL_SUCCESS
      int_type_c<EGL_SUCCESS>>
#else
      int_type_i>
#endif
      success;

    /// @var not_initialized
    /// @eglconstwrap{NOT_INITIALIZED}
    opt_c_api_constant<
      mp_list<error_code>,
#ifdef EGL_NOT_INITIALIZED
      int_type_c<EGL_NOT_INITIALIZED>>
#else
      int_type_i>
#endif
      not_initialized;

    /// @var bad_access
    /// @eglconstwrap{BAD_ACCESS}
    opt_c_api_constant<
      mp_list<error_code>,
#ifdef EGL_BAD_ACCESS
      int_type_c<EGL_BAD_ACCESS>>
#else
      int_type_i>
#endif
      bad_access;

    /// @var bad_alloc
    /// @eglconstwrap{BAD_ALLOC}
    opt_c_api_constant<
      mp_list<error_code>,
#ifdef EGL_BAD_ALLOC
      int_type_c<EGL_BAD_ALLOC>>
#else
      int_type_i>
#endif
      bad_alloc;

    /// @var bad_attribute
    /// @eglconstwrap{BAD_ATTRIBUTE}
    opt_c_api_constant<
      mp_list<error_code>,
#ifdef EGL_BAD_ATTRIBUTE
      int_type_c<EGL_BAD_ATTRIBUTE>>
#else
      int_type_i>
#endif
      bad_attribute;

    /// @var bad_context
    /// @eglconstwrap{BAD_CONTEXT}
    opt_c_api_constant<
      mp_list<error_code>,
#ifdef EGL_BAD_CONTEXT
      int_type_c<EGL_BAD_CONTEXT>>
#else
      int_type_i>
#endif
      bad_context;

    /// @var bad_config
    /// @eglconstwrap{BAD_CONFIG}
    opt_c_api_constant<
      mp_list<error_code>,
#ifdef EGL_BAD_CONFIG
      int_type_c<EGL_BAD_CONFIG>>
#else
      int_type_i>
#endif
      bad_config;

    /// @var bad_current_surface
    /// @eglconstwrap{BAD_CURRENT_SURFACE}
    opt_c_api_constant<
      mp_list<error_code>,
#ifdef EGL_BAD_CURRENT_SURFACE
      int_type_c<EGL_BAD_CURRENT_SURFACE>>
#else
      int_type_i>
#endif
      bad_current_surface;

    /// @var bad_display
    /// @eglconstwrap{BAD_DISPLAY}
    opt_c_api_constant<
      mp_list<error_code>,
#ifdef EGL_BAD_DISPLAY
      int_type_c<EGL_BAD_DISPLAY>>
#else
      int_type_i>
#endif
      bad_display;

    /// @var bad_surface
    /// @eglconstwrap{BAD_SURFACE}
    opt_c_api_constant<
      mp_list<error_code>,
#ifdef EGL_BAD_SURFACE
      int_type_c<EGL_BAD_SURFACE>>
#else
      int_type_i>
#endif
      bad_surface;

    /// @var bad_match
    /// @eglconstwrap{BAD_MATCH}
    opt_c_api_constant<
      mp_list<error_code>,
#ifdef EGL_BAD_MATCH
      int_type_c<EGL_BAD_MATCH>>
#else
      int_type_i>
#endif
      bad_match;

    /// @var bad_parameter
    /// @eglconstwrap{BAD_PARAMETER}
    opt_c_api_constant<
      mp_list<error_code>,
#ifdef EGL_BAD_PARAMETER
      int_type_c<EGL_BAD_PARAMETER>>
#else
      int_type_i>
#endif
      bad_parameter;

    /// @var bad_native_pixmap
    /// @eglconstwrap{BAD_NATIVE_PIXMAP}
    opt_c_api_constant<
      mp_list<error_code>,
#ifdef EGL_BAD_NATIVE_PIXMAP
      int_type_c<EGL_BAD_NATIVE_PIXMAP>>
#else
      int_type_i>
#endif
      bad_native_pixmap;

    /// @var bad_native_window
    /// @eglconstwrap{BAD_NATIVE_WINDOW}
    opt_c_api_constant<
      mp_list<error_code>,
#ifdef EGL_BAD_NATIVE_WINDOW
      int_type_c<EGL_BAD_NATIVE_WINDOW>>
#else
      int_type_i>
#endif
      bad_native_window;

    /// @var context_lost
    /// @eglconstwrap{CONTEXT_LOST}
    opt_c_api_constant<
      mp_list<error_code>,
#ifdef EGL_CONTEXT_LOST
      int_type_c<EGL_CONTEXT_LOST>>
#else
      int_type_i>
#endif
      context_lost;

    /// @var true_
    /// @eglconstwrap{TRUE}
    opt_c_api_constant<
      mp_list<eglp::true_false>,
#ifdef EGL_TRUE
      enum_type_c<EGL_TRUE>>
#else
      enum_type_i>
#endif
      true_;

    /// @var false_
    /// @eglconstwrap{FALSE}
    opt_c_api_constant<
      mp_list<eglp::true_false>,
#ifdef EGL_FALSE
      enum_type_c<EGL_FALSE>>
#else
      enum_type_i>
#endif
      false_;

    /// @var platform_device
    /// @eglconstwrap{PLATFORM_DEVICE_EXT}
    opt_c_api_constant<
      mp_list<platform>,
#ifdef EGL_PLATFORM_DEVICE_EXT
      int_type_c<EGL_PLATFORM_DEVICE_EXT>
#else
      int_type_i>
#endif
      >
      platform_device;

    /// @var platform_x11
    /// @eglconstwrap{PLATFORM_X11_EXT}
    opt_c_api_constant<mp_list<platform>, int_type_c<0x31D5>> platform_x11;

    /// @var platform_xcb
    /// @eglconstwrap{PLATFORM_XCB_EXT}
    opt_c_api_constant<mp_list<platform>, int_type_c<0x31DC>> platform_xcb;

    /// @var platform_wayland
    /// @eglconstwrap{PLATFORM_WAYLAND}
    opt_c_api_constant<mp_list<platform>, int_type_c<0x31D8>> platform_wayland;

    /// @var platform_gbm_mesa
    /// @eglconstwrap{PLATFORM_GBM_MESA}
    opt_c_api_constant<mp_list<platform>, int_type_c<0x31D7>> platform_gbm_mesa;

    /// @var platform_surfaceless
    /// @eglconstwrap{PLATFORM_SURFACELESS_EXT}
    opt_c_api_constant<mp_list<platform>, int_type_c<0x31DD>>
      platform_surfaceless;

    /// @var platform_android
    /// @eglconstwrap{PLATFORM_ANDROID_EXT}
    opt_c_api_constant<mp_list<platform>, int_type_c<0x3141>> platform_android;

    /// @var client_apis
    /// @eglconstwrap{CLIENT_APIS}
    opt_c_api_constant<
      mp_list<string_query>,
#ifdef EGL_CLIENT_APIS
      int_type_c<EGL_CLIENT_APIS>>
#else
      int_type_i>
#endif
      client_apis;

    /// @var vendor
    /// @eglconstwrap{VENDOR}
    opt_c_api_constant<
      mp_list<string_query>,
#ifdef EGL_VENDOR
      int_type_c<EGL_VENDOR>>
#else
      int_type_i>
#endif
      vendor;

    /// @var version
    /// @eglconstwrap{VERSION}
    opt_c_api_constant<
      mp_list<string_query>,
#ifdef EGL_VERSION
      int_type_c<EGL_VERSION>>
#else
      int_type_i>
#endif
      version;

    /// @var renderer
    /// @eglconstwrap{RENDERER}
    opt_c_api_constant<mp_list<device_string_query>, int_type_c<0x335E>>
      renderer;

    /// @var extensions
    /// @eglconstwrap{EXTENSIONS}
    opt_c_api_constant<
      mp_list<string_query, device_string_query>,
#ifdef EGL_EXTENSIONS
      int_type_c<EGL_EXTENSIONS>>
#else
      int_type_i>
#endif
      extensions;

    /// @var drm_device_file
    /// @eglconstwrap{DRM_DEVICE_FILE_EXT}
    opt_c_api_constant<
      mp_list<string_query, device_string_query>,
      int_type_c<0x3233>>
      drm_device_file;

    /// @var drm_device_file
    /// @eglconstwrap{DRM_DEVICE_FILE_EXT}
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
      int_type_c<EGL_GL_COLORSPACE>,
#else
      int_type_i,
#endif
      eglp::gl_colorspace>
      gl_colorspace;

    opt_c_api_constant<
      mp_list<surface_attribute>,
#ifdef EGL_TEXTURE_TARGET
      int_type_c<EGL_TEXTURE_TARGET>,
#else
      int_type_i,
#endif
      eglp::texture_target>
      texture_target;

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

    opt_c_api_constant<mp_list<image_attribute>, int_type_c<0x30D2>>
      image_preserved;

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

    basic_egl_constants(ApiTraits& traits, basic_egl_c_api<ApiTraits>& api);
};
//------------------------------------------------------------------------------
} // namespace eagine::eglp

#endif // EGLPLUS_EGL_API_CONSTANTS_HPP
