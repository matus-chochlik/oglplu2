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

namespace eagine {
namespace eglp {
//------------------------------------------------------------------------------
template <typename ApiTraits>
struct basic_egl_constants {
public:
    using enum_type = typename egl_types::enum_type;
    using enum_type_i = identity<enum_type>;
    template <enum_type value>
    using enum_type_c = std::integral_constant<enum_type, value>;

    using int_type = typename egl_types::int_type;
    using int_type_i = identity<int_type>;
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
      mp_list<string_query>,
#ifdef EGL_EXTENSIONS
      int_type_c<EGL_EXTENSIONS>>
#else
      int_type_i>
#endif
      extensions;

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

    opt_c_api_constant<
      mp_list<client_api_bit>,
#ifdef EGL_OPENGL_BIT
      int_type_c<EGL_OPENGL_BIT>>
#else
      int_type_i>
#endif
      opengl_bit;

    opt_c_api_constant<
      mp_list<client_api_bit>,
#ifdef EGL_OPENGL_ES_BIT
      int_type_c<EGL_OPENGL_ES_BIT>>
#else
      int_type_i>
#endif
      opengl_es_bit;

    opt_c_api_constant<
      mp_list<client_api_bit>,
#ifdef EGL_OPENGL_ES2_BIT
      int_type_c<EGL_OPENGL_ES2_BIT>>
#else
      int_type_i>
#endif
      opengl_es2_bit;

    opt_c_api_constant<
      mp_list<client_api_bit>,
#ifdef EGL_OPENGL_ES3_BIT
      int_type_c<EGL_OPENGL_ES3_BIT>>
#else
      int_type_i>
#endif
      opengl_es3_bit;

    opt_c_api_constant<
      mp_list<client_api_bit>,
#ifdef EGL_OPENVG_BIT
      int_type_c<EGL_OPENVG_BIT>>
#else
      int_type_i>
#endif
      openvg_bit;

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
      , client_apis("CLIENT_APIS", traits, api)
      , vendor("VENDOR", traits, api)
      , version("VERSION", traits, api)
      , extensions("EXTENSIONS", traits, api)
      , config_id("CONFIG_ID", traits, api)
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
      , level("LEVEL", traits, api)
      , pbuffer_width("PBUFFER_WIDTH", traits, api)
      , pbuffer_height("PBUFFER_HEIGHT", traits, api)
      , pbuffer_pixels("PBUFFER_PIXELS", traits, api)
      , max_swap_interval("MAX_SWAP_INTERVAL", traits, api)
      , min_swap_interval("MIN_SWAP_INTERVAL", traits, api)
      , window_bit("WINDOW_BIT", traits, api)
      , pixmap_bit("PIXMAP_BIT", traits, api)
      , pbuffer_bit("PBUFFER_BIT", traits, api)
      , opengl_bit("OPENGL_BIT", traits, api)
      , opengl_es_bit("OPENGL_ES_BIT", traits, api)
      , opengl_es2_bit("OPENGL_ES2_BIT", traits, api)
      , opengl_es3_bit("OPENGL_ES3_BIT", traits, api)
      , openvg_bit("OPENVG_BIT", traits, api)
      , none("NONE", traits, api) {
    }
};
//------------------------------------------------------------------------------
} // namespace eglp
} // namespace eagine

#endif // EGLPLUS_EGL_API_CONSTANTS_HPP

