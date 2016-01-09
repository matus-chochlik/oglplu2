//  File test/eglplus/enums/config_attrib.cpp
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
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EGLPLUS_config_attrib

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_config_attrib_tests)

BOOST_AUTO_TEST_CASE(enum_config_attrib_values)
{
	using namespace eglplus;
	enum_values ev;
	(void)ev;
	config_attrib x;
	(void)x;

#ifdef EGL_ALPHA_MASK_SIZE
	x = ev.alpha_mask_size;
	BOOST_CHECK(x == ev.alpha_mask_size);
# ifdef EGL_ALPHA_SIZE
	BOOST_CHECK(x != ev.alpha_size);
# endif
# ifdef EGL_BIND_TO_TEXTURE_RGB
	BOOST_CHECK(x != ev.bind_to_texture_rgb);
# endif
# ifdef EGL_BIND_TO_TEXTURE_RGBA
	BOOST_CHECK(x != ev.bind_to_texture_rgba);
# endif
# ifdef EGL_BLUE_SIZE
	BOOST_CHECK(x != ev.blue_size);
# endif
# ifdef EGL_BUFFER_SIZE
	BOOST_CHECK(x != ev.buffer_size);
# endif
# ifdef EGL_COLOR_BUFFER_TYPE
	BOOST_CHECK(x != ev.color_buffer_type);
# endif
# ifdef EGL_CONFIG_CAVEAT
	BOOST_CHECK(x != ev.config_caveat);
# endif
# ifdef EGL_CONFIG_ID
	BOOST_CHECK(x != ev.config_id);
# endif
# ifdef EGL_CONFORMANT
	BOOST_CHECK(x != ev.conformant);
# endif
# ifdef EGL_DEPTH_SIZE
	BOOST_CHECK(x != ev.depth_size);
# endif
# ifdef EGL_GREEN_SIZE
	BOOST_CHECK(x != ev.green_size);
# endif
# ifdef EGL_LEVEL
	BOOST_CHECK(x != ev.level);
# endif
# ifdef EGL_LUMINANCE_SIZE
	BOOST_CHECK(x != ev.luminance_size);
# endif
# ifdef EGL_MAX_PBUFFER_HEIGHT
	BOOST_CHECK(x != ev.max_pbuffer_height);
# endif
# ifdef EGL_MAX_PBUFFER_PIXELS
	BOOST_CHECK(x != ev.max_pbuffer_pixels);
# endif
# ifdef EGL_MAX_PBUFFER_WIDTH
	BOOST_CHECK(x != ev.max_pbuffer_width);
# endif
# ifdef EGL_MAX_SWAP_INTERVAL
	BOOST_CHECK(x != ev.max_swap_interval);
# endif
# ifdef EGL_MIN_SWAP_INTERVAL
	BOOST_CHECK(x != ev.min_swap_interval);
# endif
# ifdef EGL_NATIVE_RENDERABLE
	BOOST_CHECK(x != ev.native_renderable);
# endif
# ifdef EGL_NATIVE_VISUAL_ID
	BOOST_CHECK(x != ev.native_visual_id);
# endif
# ifdef EGL_NATIVE_VISUAL_TYPE
	BOOST_CHECK(x != ev.native_visual_type);
# endif
# ifdef EGL_RED_SIZE
	BOOST_CHECK(x != ev.red_size);
# endif
# ifdef EGL_RENDERABLE_TYPE
	BOOST_CHECK(x != ev.renderable_type);
# endif
# ifdef EGL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef EGL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef EGL_STENCIL_SIZE
	BOOST_CHECK(x != ev.stencil_size);
# endif
# ifdef EGL_SURFACE_TYPE
	BOOST_CHECK(x != ev.surface_type);
# endif
# ifdef EGL_TRANSPARENT_BLUE_VALUE
	BOOST_CHECK(x != ev.transparent_blue_value);
# endif
# ifdef EGL_TRANSPARENT_GREEN_VALUE
	BOOST_CHECK(x != ev.transparent_green_value);
# endif
# ifdef EGL_TRANSPARENT_RED_VALUE
	BOOST_CHECK(x != ev.transparent_red_value);
# endif
# ifdef EGL_TRANSPARENT_TYPE
	BOOST_CHECK(x != ev.transparent_type);
# endif
#endif

#ifdef EGL_ALPHA_SIZE
	x = ev.alpha_size;
	BOOST_CHECK(x == ev.alpha_size);
# ifdef EGL_BIND_TO_TEXTURE_RGB
	BOOST_CHECK(x != ev.bind_to_texture_rgb);
# endif
# ifdef EGL_BIND_TO_TEXTURE_RGBA
	BOOST_CHECK(x != ev.bind_to_texture_rgba);
# endif
# ifdef EGL_BLUE_SIZE
	BOOST_CHECK(x != ev.blue_size);
# endif
# ifdef EGL_BUFFER_SIZE
	BOOST_CHECK(x != ev.buffer_size);
# endif
# ifdef EGL_COLOR_BUFFER_TYPE
	BOOST_CHECK(x != ev.color_buffer_type);
# endif
# ifdef EGL_CONFIG_CAVEAT
	BOOST_CHECK(x != ev.config_caveat);
# endif
# ifdef EGL_CONFIG_ID
	BOOST_CHECK(x != ev.config_id);
# endif
# ifdef EGL_CONFORMANT
	BOOST_CHECK(x != ev.conformant);
# endif
# ifdef EGL_DEPTH_SIZE
	BOOST_CHECK(x != ev.depth_size);
# endif
# ifdef EGL_GREEN_SIZE
	BOOST_CHECK(x != ev.green_size);
# endif
# ifdef EGL_LEVEL
	BOOST_CHECK(x != ev.level);
# endif
# ifdef EGL_LUMINANCE_SIZE
	BOOST_CHECK(x != ev.luminance_size);
# endif
# ifdef EGL_MAX_PBUFFER_HEIGHT
	BOOST_CHECK(x != ev.max_pbuffer_height);
# endif
# ifdef EGL_MAX_PBUFFER_PIXELS
	BOOST_CHECK(x != ev.max_pbuffer_pixels);
# endif
# ifdef EGL_MAX_PBUFFER_WIDTH
	BOOST_CHECK(x != ev.max_pbuffer_width);
# endif
# ifdef EGL_MAX_SWAP_INTERVAL
	BOOST_CHECK(x != ev.max_swap_interval);
# endif
# ifdef EGL_MIN_SWAP_INTERVAL
	BOOST_CHECK(x != ev.min_swap_interval);
# endif
# ifdef EGL_NATIVE_RENDERABLE
	BOOST_CHECK(x != ev.native_renderable);
# endif
# ifdef EGL_NATIVE_VISUAL_ID
	BOOST_CHECK(x != ev.native_visual_id);
# endif
# ifdef EGL_NATIVE_VISUAL_TYPE
	BOOST_CHECK(x != ev.native_visual_type);
# endif
# ifdef EGL_RED_SIZE
	BOOST_CHECK(x != ev.red_size);
# endif
# ifdef EGL_RENDERABLE_TYPE
	BOOST_CHECK(x != ev.renderable_type);
# endif
# ifdef EGL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef EGL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef EGL_STENCIL_SIZE
	BOOST_CHECK(x != ev.stencil_size);
# endif
# ifdef EGL_SURFACE_TYPE
	BOOST_CHECK(x != ev.surface_type);
# endif
# ifdef EGL_TRANSPARENT_BLUE_VALUE
	BOOST_CHECK(x != ev.transparent_blue_value);
# endif
# ifdef EGL_TRANSPARENT_GREEN_VALUE
	BOOST_CHECK(x != ev.transparent_green_value);
# endif
# ifdef EGL_TRANSPARENT_RED_VALUE
	BOOST_CHECK(x != ev.transparent_red_value);
# endif
# ifdef EGL_TRANSPARENT_TYPE
	BOOST_CHECK(x != ev.transparent_type);
# endif
#endif

#ifdef EGL_BIND_TO_TEXTURE_RGB
	x = ev.bind_to_texture_rgb;
	BOOST_CHECK(x == ev.bind_to_texture_rgb);
# ifdef EGL_BIND_TO_TEXTURE_RGBA
	BOOST_CHECK(x != ev.bind_to_texture_rgba);
# endif
# ifdef EGL_BLUE_SIZE
	BOOST_CHECK(x != ev.blue_size);
# endif
# ifdef EGL_BUFFER_SIZE
	BOOST_CHECK(x != ev.buffer_size);
# endif
# ifdef EGL_COLOR_BUFFER_TYPE
	BOOST_CHECK(x != ev.color_buffer_type);
# endif
# ifdef EGL_CONFIG_CAVEAT
	BOOST_CHECK(x != ev.config_caveat);
# endif
# ifdef EGL_CONFIG_ID
	BOOST_CHECK(x != ev.config_id);
# endif
# ifdef EGL_CONFORMANT
	BOOST_CHECK(x != ev.conformant);
# endif
# ifdef EGL_DEPTH_SIZE
	BOOST_CHECK(x != ev.depth_size);
# endif
# ifdef EGL_GREEN_SIZE
	BOOST_CHECK(x != ev.green_size);
# endif
# ifdef EGL_LEVEL
	BOOST_CHECK(x != ev.level);
# endif
# ifdef EGL_LUMINANCE_SIZE
	BOOST_CHECK(x != ev.luminance_size);
# endif
# ifdef EGL_MAX_PBUFFER_HEIGHT
	BOOST_CHECK(x != ev.max_pbuffer_height);
# endif
# ifdef EGL_MAX_PBUFFER_PIXELS
	BOOST_CHECK(x != ev.max_pbuffer_pixels);
# endif
# ifdef EGL_MAX_PBUFFER_WIDTH
	BOOST_CHECK(x != ev.max_pbuffer_width);
# endif
# ifdef EGL_MAX_SWAP_INTERVAL
	BOOST_CHECK(x != ev.max_swap_interval);
# endif
# ifdef EGL_MIN_SWAP_INTERVAL
	BOOST_CHECK(x != ev.min_swap_interval);
# endif
# ifdef EGL_NATIVE_RENDERABLE
	BOOST_CHECK(x != ev.native_renderable);
# endif
# ifdef EGL_NATIVE_VISUAL_ID
	BOOST_CHECK(x != ev.native_visual_id);
# endif
# ifdef EGL_NATIVE_VISUAL_TYPE
	BOOST_CHECK(x != ev.native_visual_type);
# endif
# ifdef EGL_RED_SIZE
	BOOST_CHECK(x != ev.red_size);
# endif
# ifdef EGL_RENDERABLE_TYPE
	BOOST_CHECK(x != ev.renderable_type);
# endif
# ifdef EGL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef EGL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef EGL_STENCIL_SIZE
	BOOST_CHECK(x != ev.stencil_size);
# endif
# ifdef EGL_SURFACE_TYPE
	BOOST_CHECK(x != ev.surface_type);
# endif
# ifdef EGL_TRANSPARENT_BLUE_VALUE
	BOOST_CHECK(x != ev.transparent_blue_value);
# endif
# ifdef EGL_TRANSPARENT_GREEN_VALUE
	BOOST_CHECK(x != ev.transparent_green_value);
# endif
# ifdef EGL_TRANSPARENT_RED_VALUE
	BOOST_CHECK(x != ev.transparent_red_value);
# endif
# ifdef EGL_TRANSPARENT_TYPE
	BOOST_CHECK(x != ev.transparent_type);
# endif
#endif

#ifdef EGL_BIND_TO_TEXTURE_RGBA
	x = ev.bind_to_texture_rgba;
	BOOST_CHECK(x == ev.bind_to_texture_rgba);
# ifdef EGL_BLUE_SIZE
	BOOST_CHECK(x != ev.blue_size);
# endif
# ifdef EGL_BUFFER_SIZE
	BOOST_CHECK(x != ev.buffer_size);
# endif
# ifdef EGL_COLOR_BUFFER_TYPE
	BOOST_CHECK(x != ev.color_buffer_type);
# endif
# ifdef EGL_CONFIG_CAVEAT
	BOOST_CHECK(x != ev.config_caveat);
# endif
# ifdef EGL_CONFIG_ID
	BOOST_CHECK(x != ev.config_id);
# endif
# ifdef EGL_CONFORMANT
	BOOST_CHECK(x != ev.conformant);
# endif
# ifdef EGL_DEPTH_SIZE
	BOOST_CHECK(x != ev.depth_size);
# endif
# ifdef EGL_GREEN_SIZE
	BOOST_CHECK(x != ev.green_size);
# endif
# ifdef EGL_LEVEL
	BOOST_CHECK(x != ev.level);
# endif
# ifdef EGL_LUMINANCE_SIZE
	BOOST_CHECK(x != ev.luminance_size);
# endif
# ifdef EGL_MAX_PBUFFER_HEIGHT
	BOOST_CHECK(x != ev.max_pbuffer_height);
# endif
# ifdef EGL_MAX_PBUFFER_PIXELS
	BOOST_CHECK(x != ev.max_pbuffer_pixels);
# endif
# ifdef EGL_MAX_PBUFFER_WIDTH
	BOOST_CHECK(x != ev.max_pbuffer_width);
# endif
# ifdef EGL_MAX_SWAP_INTERVAL
	BOOST_CHECK(x != ev.max_swap_interval);
# endif
# ifdef EGL_MIN_SWAP_INTERVAL
	BOOST_CHECK(x != ev.min_swap_interval);
# endif
# ifdef EGL_NATIVE_RENDERABLE
	BOOST_CHECK(x != ev.native_renderable);
# endif
# ifdef EGL_NATIVE_VISUAL_ID
	BOOST_CHECK(x != ev.native_visual_id);
# endif
# ifdef EGL_NATIVE_VISUAL_TYPE
	BOOST_CHECK(x != ev.native_visual_type);
# endif
# ifdef EGL_RED_SIZE
	BOOST_CHECK(x != ev.red_size);
# endif
# ifdef EGL_RENDERABLE_TYPE
	BOOST_CHECK(x != ev.renderable_type);
# endif
# ifdef EGL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef EGL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef EGL_STENCIL_SIZE
	BOOST_CHECK(x != ev.stencil_size);
# endif
# ifdef EGL_SURFACE_TYPE
	BOOST_CHECK(x != ev.surface_type);
# endif
# ifdef EGL_TRANSPARENT_BLUE_VALUE
	BOOST_CHECK(x != ev.transparent_blue_value);
# endif
# ifdef EGL_TRANSPARENT_GREEN_VALUE
	BOOST_CHECK(x != ev.transparent_green_value);
# endif
# ifdef EGL_TRANSPARENT_RED_VALUE
	BOOST_CHECK(x != ev.transparent_red_value);
# endif
# ifdef EGL_TRANSPARENT_TYPE
	BOOST_CHECK(x != ev.transparent_type);
# endif
#endif

#ifdef EGL_BLUE_SIZE
	x = ev.blue_size;
	BOOST_CHECK(x == ev.blue_size);
# ifdef EGL_BUFFER_SIZE
	BOOST_CHECK(x != ev.buffer_size);
# endif
# ifdef EGL_COLOR_BUFFER_TYPE
	BOOST_CHECK(x != ev.color_buffer_type);
# endif
# ifdef EGL_CONFIG_CAVEAT
	BOOST_CHECK(x != ev.config_caveat);
# endif
# ifdef EGL_CONFIG_ID
	BOOST_CHECK(x != ev.config_id);
# endif
# ifdef EGL_CONFORMANT
	BOOST_CHECK(x != ev.conformant);
# endif
# ifdef EGL_DEPTH_SIZE
	BOOST_CHECK(x != ev.depth_size);
# endif
# ifdef EGL_GREEN_SIZE
	BOOST_CHECK(x != ev.green_size);
# endif
# ifdef EGL_LEVEL
	BOOST_CHECK(x != ev.level);
# endif
# ifdef EGL_LUMINANCE_SIZE
	BOOST_CHECK(x != ev.luminance_size);
# endif
# ifdef EGL_MAX_PBUFFER_HEIGHT
	BOOST_CHECK(x != ev.max_pbuffer_height);
# endif
# ifdef EGL_MAX_PBUFFER_PIXELS
	BOOST_CHECK(x != ev.max_pbuffer_pixels);
# endif
# ifdef EGL_MAX_PBUFFER_WIDTH
	BOOST_CHECK(x != ev.max_pbuffer_width);
# endif
# ifdef EGL_MAX_SWAP_INTERVAL
	BOOST_CHECK(x != ev.max_swap_interval);
# endif
# ifdef EGL_MIN_SWAP_INTERVAL
	BOOST_CHECK(x != ev.min_swap_interval);
# endif
# ifdef EGL_NATIVE_RENDERABLE
	BOOST_CHECK(x != ev.native_renderable);
# endif
# ifdef EGL_NATIVE_VISUAL_ID
	BOOST_CHECK(x != ev.native_visual_id);
# endif
# ifdef EGL_NATIVE_VISUAL_TYPE
	BOOST_CHECK(x != ev.native_visual_type);
# endif
# ifdef EGL_RED_SIZE
	BOOST_CHECK(x != ev.red_size);
# endif
# ifdef EGL_RENDERABLE_TYPE
	BOOST_CHECK(x != ev.renderable_type);
# endif
# ifdef EGL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef EGL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef EGL_STENCIL_SIZE
	BOOST_CHECK(x != ev.stencil_size);
# endif
# ifdef EGL_SURFACE_TYPE
	BOOST_CHECK(x != ev.surface_type);
# endif
# ifdef EGL_TRANSPARENT_BLUE_VALUE
	BOOST_CHECK(x != ev.transparent_blue_value);
# endif
# ifdef EGL_TRANSPARENT_GREEN_VALUE
	BOOST_CHECK(x != ev.transparent_green_value);
# endif
# ifdef EGL_TRANSPARENT_RED_VALUE
	BOOST_CHECK(x != ev.transparent_red_value);
# endif
# ifdef EGL_TRANSPARENT_TYPE
	BOOST_CHECK(x != ev.transparent_type);
# endif
#endif

#ifdef EGL_BUFFER_SIZE
	x = ev.buffer_size;
	BOOST_CHECK(x == ev.buffer_size);
# ifdef EGL_COLOR_BUFFER_TYPE
	BOOST_CHECK(x != ev.color_buffer_type);
# endif
# ifdef EGL_CONFIG_CAVEAT
	BOOST_CHECK(x != ev.config_caveat);
# endif
# ifdef EGL_CONFIG_ID
	BOOST_CHECK(x != ev.config_id);
# endif
# ifdef EGL_CONFORMANT
	BOOST_CHECK(x != ev.conformant);
# endif
# ifdef EGL_DEPTH_SIZE
	BOOST_CHECK(x != ev.depth_size);
# endif
# ifdef EGL_GREEN_SIZE
	BOOST_CHECK(x != ev.green_size);
# endif
# ifdef EGL_LEVEL
	BOOST_CHECK(x != ev.level);
# endif
# ifdef EGL_LUMINANCE_SIZE
	BOOST_CHECK(x != ev.luminance_size);
# endif
# ifdef EGL_MAX_PBUFFER_HEIGHT
	BOOST_CHECK(x != ev.max_pbuffer_height);
# endif
# ifdef EGL_MAX_PBUFFER_PIXELS
	BOOST_CHECK(x != ev.max_pbuffer_pixels);
# endif
# ifdef EGL_MAX_PBUFFER_WIDTH
	BOOST_CHECK(x != ev.max_pbuffer_width);
# endif
# ifdef EGL_MAX_SWAP_INTERVAL
	BOOST_CHECK(x != ev.max_swap_interval);
# endif
# ifdef EGL_MIN_SWAP_INTERVAL
	BOOST_CHECK(x != ev.min_swap_interval);
# endif
# ifdef EGL_NATIVE_RENDERABLE
	BOOST_CHECK(x != ev.native_renderable);
# endif
# ifdef EGL_NATIVE_VISUAL_ID
	BOOST_CHECK(x != ev.native_visual_id);
# endif
# ifdef EGL_NATIVE_VISUAL_TYPE
	BOOST_CHECK(x != ev.native_visual_type);
# endif
# ifdef EGL_RED_SIZE
	BOOST_CHECK(x != ev.red_size);
# endif
# ifdef EGL_RENDERABLE_TYPE
	BOOST_CHECK(x != ev.renderable_type);
# endif
# ifdef EGL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef EGL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef EGL_STENCIL_SIZE
	BOOST_CHECK(x != ev.stencil_size);
# endif
# ifdef EGL_SURFACE_TYPE
	BOOST_CHECK(x != ev.surface_type);
# endif
# ifdef EGL_TRANSPARENT_BLUE_VALUE
	BOOST_CHECK(x != ev.transparent_blue_value);
# endif
# ifdef EGL_TRANSPARENT_GREEN_VALUE
	BOOST_CHECK(x != ev.transparent_green_value);
# endif
# ifdef EGL_TRANSPARENT_RED_VALUE
	BOOST_CHECK(x != ev.transparent_red_value);
# endif
# ifdef EGL_TRANSPARENT_TYPE
	BOOST_CHECK(x != ev.transparent_type);
# endif
#endif

#ifdef EGL_COLOR_BUFFER_TYPE
	x = ev.color_buffer_type;
	BOOST_CHECK(x == ev.color_buffer_type);
# ifdef EGL_CONFIG_CAVEAT
	BOOST_CHECK(x != ev.config_caveat);
# endif
# ifdef EGL_CONFIG_ID
	BOOST_CHECK(x != ev.config_id);
# endif
# ifdef EGL_CONFORMANT
	BOOST_CHECK(x != ev.conformant);
# endif
# ifdef EGL_DEPTH_SIZE
	BOOST_CHECK(x != ev.depth_size);
# endif
# ifdef EGL_GREEN_SIZE
	BOOST_CHECK(x != ev.green_size);
# endif
# ifdef EGL_LEVEL
	BOOST_CHECK(x != ev.level);
# endif
# ifdef EGL_LUMINANCE_SIZE
	BOOST_CHECK(x != ev.luminance_size);
# endif
# ifdef EGL_MAX_PBUFFER_HEIGHT
	BOOST_CHECK(x != ev.max_pbuffer_height);
# endif
# ifdef EGL_MAX_PBUFFER_PIXELS
	BOOST_CHECK(x != ev.max_pbuffer_pixels);
# endif
# ifdef EGL_MAX_PBUFFER_WIDTH
	BOOST_CHECK(x != ev.max_pbuffer_width);
# endif
# ifdef EGL_MAX_SWAP_INTERVAL
	BOOST_CHECK(x != ev.max_swap_interval);
# endif
# ifdef EGL_MIN_SWAP_INTERVAL
	BOOST_CHECK(x != ev.min_swap_interval);
# endif
# ifdef EGL_NATIVE_RENDERABLE
	BOOST_CHECK(x != ev.native_renderable);
# endif
# ifdef EGL_NATIVE_VISUAL_ID
	BOOST_CHECK(x != ev.native_visual_id);
# endif
# ifdef EGL_NATIVE_VISUAL_TYPE
	BOOST_CHECK(x != ev.native_visual_type);
# endif
# ifdef EGL_RED_SIZE
	BOOST_CHECK(x != ev.red_size);
# endif
# ifdef EGL_RENDERABLE_TYPE
	BOOST_CHECK(x != ev.renderable_type);
# endif
# ifdef EGL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef EGL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef EGL_STENCIL_SIZE
	BOOST_CHECK(x != ev.stencil_size);
# endif
# ifdef EGL_SURFACE_TYPE
	BOOST_CHECK(x != ev.surface_type);
# endif
# ifdef EGL_TRANSPARENT_BLUE_VALUE
	BOOST_CHECK(x != ev.transparent_blue_value);
# endif
# ifdef EGL_TRANSPARENT_GREEN_VALUE
	BOOST_CHECK(x != ev.transparent_green_value);
# endif
# ifdef EGL_TRANSPARENT_RED_VALUE
	BOOST_CHECK(x != ev.transparent_red_value);
# endif
# ifdef EGL_TRANSPARENT_TYPE
	BOOST_CHECK(x != ev.transparent_type);
# endif
#endif

#ifdef EGL_CONFIG_CAVEAT
	x = ev.config_caveat;
	BOOST_CHECK(x == ev.config_caveat);
# ifdef EGL_CONFIG_ID
	BOOST_CHECK(x != ev.config_id);
# endif
# ifdef EGL_CONFORMANT
	BOOST_CHECK(x != ev.conformant);
# endif
# ifdef EGL_DEPTH_SIZE
	BOOST_CHECK(x != ev.depth_size);
# endif
# ifdef EGL_GREEN_SIZE
	BOOST_CHECK(x != ev.green_size);
# endif
# ifdef EGL_LEVEL
	BOOST_CHECK(x != ev.level);
# endif
# ifdef EGL_LUMINANCE_SIZE
	BOOST_CHECK(x != ev.luminance_size);
# endif
# ifdef EGL_MAX_PBUFFER_HEIGHT
	BOOST_CHECK(x != ev.max_pbuffer_height);
# endif
# ifdef EGL_MAX_PBUFFER_PIXELS
	BOOST_CHECK(x != ev.max_pbuffer_pixels);
# endif
# ifdef EGL_MAX_PBUFFER_WIDTH
	BOOST_CHECK(x != ev.max_pbuffer_width);
# endif
# ifdef EGL_MAX_SWAP_INTERVAL
	BOOST_CHECK(x != ev.max_swap_interval);
# endif
# ifdef EGL_MIN_SWAP_INTERVAL
	BOOST_CHECK(x != ev.min_swap_interval);
# endif
# ifdef EGL_NATIVE_RENDERABLE
	BOOST_CHECK(x != ev.native_renderable);
# endif
# ifdef EGL_NATIVE_VISUAL_ID
	BOOST_CHECK(x != ev.native_visual_id);
# endif
# ifdef EGL_NATIVE_VISUAL_TYPE
	BOOST_CHECK(x != ev.native_visual_type);
# endif
# ifdef EGL_RED_SIZE
	BOOST_CHECK(x != ev.red_size);
# endif
# ifdef EGL_RENDERABLE_TYPE
	BOOST_CHECK(x != ev.renderable_type);
# endif
# ifdef EGL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef EGL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef EGL_STENCIL_SIZE
	BOOST_CHECK(x != ev.stencil_size);
# endif
# ifdef EGL_SURFACE_TYPE
	BOOST_CHECK(x != ev.surface_type);
# endif
# ifdef EGL_TRANSPARENT_BLUE_VALUE
	BOOST_CHECK(x != ev.transparent_blue_value);
# endif
# ifdef EGL_TRANSPARENT_GREEN_VALUE
	BOOST_CHECK(x != ev.transparent_green_value);
# endif
# ifdef EGL_TRANSPARENT_RED_VALUE
	BOOST_CHECK(x != ev.transparent_red_value);
# endif
# ifdef EGL_TRANSPARENT_TYPE
	BOOST_CHECK(x != ev.transparent_type);
# endif
#endif

#ifdef EGL_CONFIG_ID
	x = ev.config_id;
	BOOST_CHECK(x == ev.config_id);
# ifdef EGL_CONFORMANT
	BOOST_CHECK(x != ev.conformant);
# endif
# ifdef EGL_DEPTH_SIZE
	BOOST_CHECK(x != ev.depth_size);
# endif
# ifdef EGL_GREEN_SIZE
	BOOST_CHECK(x != ev.green_size);
# endif
# ifdef EGL_LEVEL
	BOOST_CHECK(x != ev.level);
# endif
# ifdef EGL_LUMINANCE_SIZE
	BOOST_CHECK(x != ev.luminance_size);
# endif
# ifdef EGL_MAX_PBUFFER_HEIGHT
	BOOST_CHECK(x != ev.max_pbuffer_height);
# endif
# ifdef EGL_MAX_PBUFFER_PIXELS
	BOOST_CHECK(x != ev.max_pbuffer_pixels);
# endif
# ifdef EGL_MAX_PBUFFER_WIDTH
	BOOST_CHECK(x != ev.max_pbuffer_width);
# endif
# ifdef EGL_MAX_SWAP_INTERVAL
	BOOST_CHECK(x != ev.max_swap_interval);
# endif
# ifdef EGL_MIN_SWAP_INTERVAL
	BOOST_CHECK(x != ev.min_swap_interval);
# endif
# ifdef EGL_NATIVE_RENDERABLE
	BOOST_CHECK(x != ev.native_renderable);
# endif
# ifdef EGL_NATIVE_VISUAL_ID
	BOOST_CHECK(x != ev.native_visual_id);
# endif
# ifdef EGL_NATIVE_VISUAL_TYPE
	BOOST_CHECK(x != ev.native_visual_type);
# endif
# ifdef EGL_RED_SIZE
	BOOST_CHECK(x != ev.red_size);
# endif
# ifdef EGL_RENDERABLE_TYPE
	BOOST_CHECK(x != ev.renderable_type);
# endif
# ifdef EGL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef EGL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef EGL_STENCIL_SIZE
	BOOST_CHECK(x != ev.stencil_size);
# endif
# ifdef EGL_SURFACE_TYPE
	BOOST_CHECK(x != ev.surface_type);
# endif
# ifdef EGL_TRANSPARENT_BLUE_VALUE
	BOOST_CHECK(x != ev.transparent_blue_value);
# endif
# ifdef EGL_TRANSPARENT_GREEN_VALUE
	BOOST_CHECK(x != ev.transparent_green_value);
# endif
# ifdef EGL_TRANSPARENT_RED_VALUE
	BOOST_CHECK(x != ev.transparent_red_value);
# endif
# ifdef EGL_TRANSPARENT_TYPE
	BOOST_CHECK(x != ev.transparent_type);
# endif
#endif

#ifdef EGL_CONFORMANT
	x = ev.conformant;
	BOOST_CHECK(x == ev.conformant);
# ifdef EGL_DEPTH_SIZE
	BOOST_CHECK(x != ev.depth_size);
# endif
# ifdef EGL_GREEN_SIZE
	BOOST_CHECK(x != ev.green_size);
# endif
# ifdef EGL_LEVEL
	BOOST_CHECK(x != ev.level);
# endif
# ifdef EGL_LUMINANCE_SIZE
	BOOST_CHECK(x != ev.luminance_size);
# endif
# ifdef EGL_MAX_PBUFFER_HEIGHT
	BOOST_CHECK(x != ev.max_pbuffer_height);
# endif
# ifdef EGL_MAX_PBUFFER_PIXELS
	BOOST_CHECK(x != ev.max_pbuffer_pixels);
# endif
# ifdef EGL_MAX_PBUFFER_WIDTH
	BOOST_CHECK(x != ev.max_pbuffer_width);
# endif
# ifdef EGL_MAX_SWAP_INTERVAL
	BOOST_CHECK(x != ev.max_swap_interval);
# endif
# ifdef EGL_MIN_SWAP_INTERVAL
	BOOST_CHECK(x != ev.min_swap_interval);
# endif
# ifdef EGL_NATIVE_RENDERABLE
	BOOST_CHECK(x != ev.native_renderable);
# endif
# ifdef EGL_NATIVE_VISUAL_ID
	BOOST_CHECK(x != ev.native_visual_id);
# endif
# ifdef EGL_NATIVE_VISUAL_TYPE
	BOOST_CHECK(x != ev.native_visual_type);
# endif
# ifdef EGL_RED_SIZE
	BOOST_CHECK(x != ev.red_size);
# endif
# ifdef EGL_RENDERABLE_TYPE
	BOOST_CHECK(x != ev.renderable_type);
# endif
# ifdef EGL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef EGL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef EGL_STENCIL_SIZE
	BOOST_CHECK(x != ev.stencil_size);
# endif
# ifdef EGL_SURFACE_TYPE
	BOOST_CHECK(x != ev.surface_type);
# endif
# ifdef EGL_TRANSPARENT_BLUE_VALUE
	BOOST_CHECK(x != ev.transparent_blue_value);
# endif
# ifdef EGL_TRANSPARENT_GREEN_VALUE
	BOOST_CHECK(x != ev.transparent_green_value);
# endif
# ifdef EGL_TRANSPARENT_RED_VALUE
	BOOST_CHECK(x != ev.transparent_red_value);
# endif
# ifdef EGL_TRANSPARENT_TYPE
	BOOST_CHECK(x != ev.transparent_type);
# endif
#endif

#ifdef EGL_DEPTH_SIZE
	x = ev.depth_size;
	BOOST_CHECK(x == ev.depth_size);
# ifdef EGL_GREEN_SIZE
	BOOST_CHECK(x != ev.green_size);
# endif
# ifdef EGL_LEVEL
	BOOST_CHECK(x != ev.level);
# endif
# ifdef EGL_LUMINANCE_SIZE
	BOOST_CHECK(x != ev.luminance_size);
# endif
# ifdef EGL_MAX_PBUFFER_HEIGHT
	BOOST_CHECK(x != ev.max_pbuffer_height);
# endif
# ifdef EGL_MAX_PBUFFER_PIXELS
	BOOST_CHECK(x != ev.max_pbuffer_pixels);
# endif
# ifdef EGL_MAX_PBUFFER_WIDTH
	BOOST_CHECK(x != ev.max_pbuffer_width);
# endif
# ifdef EGL_MAX_SWAP_INTERVAL
	BOOST_CHECK(x != ev.max_swap_interval);
# endif
# ifdef EGL_MIN_SWAP_INTERVAL
	BOOST_CHECK(x != ev.min_swap_interval);
# endif
# ifdef EGL_NATIVE_RENDERABLE
	BOOST_CHECK(x != ev.native_renderable);
# endif
# ifdef EGL_NATIVE_VISUAL_ID
	BOOST_CHECK(x != ev.native_visual_id);
# endif
# ifdef EGL_NATIVE_VISUAL_TYPE
	BOOST_CHECK(x != ev.native_visual_type);
# endif
# ifdef EGL_RED_SIZE
	BOOST_CHECK(x != ev.red_size);
# endif
# ifdef EGL_RENDERABLE_TYPE
	BOOST_CHECK(x != ev.renderable_type);
# endif
# ifdef EGL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef EGL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef EGL_STENCIL_SIZE
	BOOST_CHECK(x != ev.stencil_size);
# endif
# ifdef EGL_SURFACE_TYPE
	BOOST_CHECK(x != ev.surface_type);
# endif
# ifdef EGL_TRANSPARENT_BLUE_VALUE
	BOOST_CHECK(x != ev.transparent_blue_value);
# endif
# ifdef EGL_TRANSPARENT_GREEN_VALUE
	BOOST_CHECK(x != ev.transparent_green_value);
# endif
# ifdef EGL_TRANSPARENT_RED_VALUE
	BOOST_CHECK(x != ev.transparent_red_value);
# endif
# ifdef EGL_TRANSPARENT_TYPE
	BOOST_CHECK(x != ev.transparent_type);
# endif
#endif

#ifdef EGL_GREEN_SIZE
	x = ev.green_size;
	BOOST_CHECK(x == ev.green_size);
# ifdef EGL_LEVEL
	BOOST_CHECK(x != ev.level);
# endif
# ifdef EGL_LUMINANCE_SIZE
	BOOST_CHECK(x != ev.luminance_size);
# endif
# ifdef EGL_MAX_PBUFFER_HEIGHT
	BOOST_CHECK(x != ev.max_pbuffer_height);
# endif
# ifdef EGL_MAX_PBUFFER_PIXELS
	BOOST_CHECK(x != ev.max_pbuffer_pixels);
# endif
# ifdef EGL_MAX_PBUFFER_WIDTH
	BOOST_CHECK(x != ev.max_pbuffer_width);
# endif
# ifdef EGL_MAX_SWAP_INTERVAL
	BOOST_CHECK(x != ev.max_swap_interval);
# endif
# ifdef EGL_MIN_SWAP_INTERVAL
	BOOST_CHECK(x != ev.min_swap_interval);
# endif
# ifdef EGL_NATIVE_RENDERABLE
	BOOST_CHECK(x != ev.native_renderable);
# endif
# ifdef EGL_NATIVE_VISUAL_ID
	BOOST_CHECK(x != ev.native_visual_id);
# endif
# ifdef EGL_NATIVE_VISUAL_TYPE
	BOOST_CHECK(x != ev.native_visual_type);
# endif
# ifdef EGL_RED_SIZE
	BOOST_CHECK(x != ev.red_size);
# endif
# ifdef EGL_RENDERABLE_TYPE
	BOOST_CHECK(x != ev.renderable_type);
# endif
# ifdef EGL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef EGL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef EGL_STENCIL_SIZE
	BOOST_CHECK(x != ev.stencil_size);
# endif
# ifdef EGL_SURFACE_TYPE
	BOOST_CHECK(x != ev.surface_type);
# endif
# ifdef EGL_TRANSPARENT_BLUE_VALUE
	BOOST_CHECK(x != ev.transparent_blue_value);
# endif
# ifdef EGL_TRANSPARENT_GREEN_VALUE
	BOOST_CHECK(x != ev.transparent_green_value);
# endif
# ifdef EGL_TRANSPARENT_RED_VALUE
	BOOST_CHECK(x != ev.transparent_red_value);
# endif
# ifdef EGL_TRANSPARENT_TYPE
	BOOST_CHECK(x != ev.transparent_type);
# endif
#endif

#ifdef EGL_LEVEL
	x = ev.level;
	BOOST_CHECK(x == ev.level);
# ifdef EGL_LUMINANCE_SIZE
	BOOST_CHECK(x != ev.luminance_size);
# endif
# ifdef EGL_MAX_PBUFFER_HEIGHT
	BOOST_CHECK(x != ev.max_pbuffer_height);
# endif
# ifdef EGL_MAX_PBUFFER_PIXELS
	BOOST_CHECK(x != ev.max_pbuffer_pixels);
# endif
# ifdef EGL_MAX_PBUFFER_WIDTH
	BOOST_CHECK(x != ev.max_pbuffer_width);
# endif
# ifdef EGL_MAX_SWAP_INTERVAL
	BOOST_CHECK(x != ev.max_swap_interval);
# endif
# ifdef EGL_MIN_SWAP_INTERVAL
	BOOST_CHECK(x != ev.min_swap_interval);
# endif
# ifdef EGL_NATIVE_RENDERABLE
	BOOST_CHECK(x != ev.native_renderable);
# endif
# ifdef EGL_NATIVE_VISUAL_ID
	BOOST_CHECK(x != ev.native_visual_id);
# endif
# ifdef EGL_NATIVE_VISUAL_TYPE
	BOOST_CHECK(x != ev.native_visual_type);
# endif
# ifdef EGL_RED_SIZE
	BOOST_CHECK(x != ev.red_size);
# endif
# ifdef EGL_RENDERABLE_TYPE
	BOOST_CHECK(x != ev.renderable_type);
# endif
# ifdef EGL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef EGL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef EGL_STENCIL_SIZE
	BOOST_CHECK(x != ev.stencil_size);
# endif
# ifdef EGL_SURFACE_TYPE
	BOOST_CHECK(x != ev.surface_type);
# endif
# ifdef EGL_TRANSPARENT_BLUE_VALUE
	BOOST_CHECK(x != ev.transparent_blue_value);
# endif
# ifdef EGL_TRANSPARENT_GREEN_VALUE
	BOOST_CHECK(x != ev.transparent_green_value);
# endif
# ifdef EGL_TRANSPARENT_RED_VALUE
	BOOST_CHECK(x != ev.transparent_red_value);
# endif
# ifdef EGL_TRANSPARENT_TYPE
	BOOST_CHECK(x != ev.transparent_type);
# endif
#endif

#ifdef EGL_LUMINANCE_SIZE
	x = ev.luminance_size;
	BOOST_CHECK(x == ev.luminance_size);
# ifdef EGL_MAX_PBUFFER_HEIGHT
	BOOST_CHECK(x != ev.max_pbuffer_height);
# endif
# ifdef EGL_MAX_PBUFFER_PIXELS
	BOOST_CHECK(x != ev.max_pbuffer_pixels);
# endif
# ifdef EGL_MAX_PBUFFER_WIDTH
	BOOST_CHECK(x != ev.max_pbuffer_width);
# endif
# ifdef EGL_MAX_SWAP_INTERVAL
	BOOST_CHECK(x != ev.max_swap_interval);
# endif
# ifdef EGL_MIN_SWAP_INTERVAL
	BOOST_CHECK(x != ev.min_swap_interval);
# endif
# ifdef EGL_NATIVE_RENDERABLE
	BOOST_CHECK(x != ev.native_renderable);
# endif
# ifdef EGL_NATIVE_VISUAL_ID
	BOOST_CHECK(x != ev.native_visual_id);
# endif
# ifdef EGL_NATIVE_VISUAL_TYPE
	BOOST_CHECK(x != ev.native_visual_type);
# endif
# ifdef EGL_RED_SIZE
	BOOST_CHECK(x != ev.red_size);
# endif
# ifdef EGL_RENDERABLE_TYPE
	BOOST_CHECK(x != ev.renderable_type);
# endif
# ifdef EGL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef EGL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef EGL_STENCIL_SIZE
	BOOST_CHECK(x != ev.stencil_size);
# endif
# ifdef EGL_SURFACE_TYPE
	BOOST_CHECK(x != ev.surface_type);
# endif
# ifdef EGL_TRANSPARENT_BLUE_VALUE
	BOOST_CHECK(x != ev.transparent_blue_value);
# endif
# ifdef EGL_TRANSPARENT_GREEN_VALUE
	BOOST_CHECK(x != ev.transparent_green_value);
# endif
# ifdef EGL_TRANSPARENT_RED_VALUE
	BOOST_CHECK(x != ev.transparent_red_value);
# endif
# ifdef EGL_TRANSPARENT_TYPE
	BOOST_CHECK(x != ev.transparent_type);
# endif
#endif

#ifdef EGL_MAX_PBUFFER_HEIGHT
	x = ev.max_pbuffer_height;
	BOOST_CHECK(x == ev.max_pbuffer_height);
# ifdef EGL_MAX_PBUFFER_PIXELS
	BOOST_CHECK(x != ev.max_pbuffer_pixels);
# endif
# ifdef EGL_MAX_PBUFFER_WIDTH
	BOOST_CHECK(x != ev.max_pbuffer_width);
# endif
# ifdef EGL_MAX_SWAP_INTERVAL
	BOOST_CHECK(x != ev.max_swap_interval);
# endif
# ifdef EGL_MIN_SWAP_INTERVAL
	BOOST_CHECK(x != ev.min_swap_interval);
# endif
# ifdef EGL_NATIVE_RENDERABLE
	BOOST_CHECK(x != ev.native_renderable);
# endif
# ifdef EGL_NATIVE_VISUAL_ID
	BOOST_CHECK(x != ev.native_visual_id);
# endif
# ifdef EGL_NATIVE_VISUAL_TYPE
	BOOST_CHECK(x != ev.native_visual_type);
# endif
# ifdef EGL_RED_SIZE
	BOOST_CHECK(x != ev.red_size);
# endif
# ifdef EGL_RENDERABLE_TYPE
	BOOST_CHECK(x != ev.renderable_type);
# endif
# ifdef EGL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef EGL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef EGL_STENCIL_SIZE
	BOOST_CHECK(x != ev.stencil_size);
# endif
# ifdef EGL_SURFACE_TYPE
	BOOST_CHECK(x != ev.surface_type);
# endif
# ifdef EGL_TRANSPARENT_BLUE_VALUE
	BOOST_CHECK(x != ev.transparent_blue_value);
# endif
# ifdef EGL_TRANSPARENT_GREEN_VALUE
	BOOST_CHECK(x != ev.transparent_green_value);
# endif
# ifdef EGL_TRANSPARENT_RED_VALUE
	BOOST_CHECK(x != ev.transparent_red_value);
# endif
# ifdef EGL_TRANSPARENT_TYPE
	BOOST_CHECK(x != ev.transparent_type);
# endif
#endif

#ifdef EGL_MAX_PBUFFER_PIXELS
	x = ev.max_pbuffer_pixels;
	BOOST_CHECK(x == ev.max_pbuffer_pixels);
# ifdef EGL_MAX_PBUFFER_WIDTH
	BOOST_CHECK(x != ev.max_pbuffer_width);
# endif
# ifdef EGL_MAX_SWAP_INTERVAL
	BOOST_CHECK(x != ev.max_swap_interval);
# endif
# ifdef EGL_MIN_SWAP_INTERVAL
	BOOST_CHECK(x != ev.min_swap_interval);
# endif
# ifdef EGL_NATIVE_RENDERABLE
	BOOST_CHECK(x != ev.native_renderable);
# endif
# ifdef EGL_NATIVE_VISUAL_ID
	BOOST_CHECK(x != ev.native_visual_id);
# endif
# ifdef EGL_NATIVE_VISUAL_TYPE
	BOOST_CHECK(x != ev.native_visual_type);
# endif
# ifdef EGL_RED_SIZE
	BOOST_CHECK(x != ev.red_size);
# endif
# ifdef EGL_RENDERABLE_TYPE
	BOOST_CHECK(x != ev.renderable_type);
# endif
# ifdef EGL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef EGL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef EGL_STENCIL_SIZE
	BOOST_CHECK(x != ev.stencil_size);
# endif
# ifdef EGL_SURFACE_TYPE
	BOOST_CHECK(x != ev.surface_type);
# endif
# ifdef EGL_TRANSPARENT_BLUE_VALUE
	BOOST_CHECK(x != ev.transparent_blue_value);
# endif
# ifdef EGL_TRANSPARENT_GREEN_VALUE
	BOOST_CHECK(x != ev.transparent_green_value);
# endif
# ifdef EGL_TRANSPARENT_RED_VALUE
	BOOST_CHECK(x != ev.transparent_red_value);
# endif
# ifdef EGL_TRANSPARENT_TYPE
	BOOST_CHECK(x != ev.transparent_type);
# endif
#endif

#ifdef EGL_MAX_PBUFFER_WIDTH
	x = ev.max_pbuffer_width;
	BOOST_CHECK(x == ev.max_pbuffer_width);
# ifdef EGL_MAX_SWAP_INTERVAL
	BOOST_CHECK(x != ev.max_swap_interval);
# endif
# ifdef EGL_MIN_SWAP_INTERVAL
	BOOST_CHECK(x != ev.min_swap_interval);
# endif
# ifdef EGL_NATIVE_RENDERABLE
	BOOST_CHECK(x != ev.native_renderable);
# endif
# ifdef EGL_NATIVE_VISUAL_ID
	BOOST_CHECK(x != ev.native_visual_id);
# endif
# ifdef EGL_NATIVE_VISUAL_TYPE
	BOOST_CHECK(x != ev.native_visual_type);
# endif
# ifdef EGL_RED_SIZE
	BOOST_CHECK(x != ev.red_size);
# endif
# ifdef EGL_RENDERABLE_TYPE
	BOOST_CHECK(x != ev.renderable_type);
# endif
# ifdef EGL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef EGL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef EGL_STENCIL_SIZE
	BOOST_CHECK(x != ev.stencil_size);
# endif
# ifdef EGL_SURFACE_TYPE
	BOOST_CHECK(x != ev.surface_type);
# endif
# ifdef EGL_TRANSPARENT_BLUE_VALUE
	BOOST_CHECK(x != ev.transparent_blue_value);
# endif
# ifdef EGL_TRANSPARENT_GREEN_VALUE
	BOOST_CHECK(x != ev.transparent_green_value);
# endif
# ifdef EGL_TRANSPARENT_RED_VALUE
	BOOST_CHECK(x != ev.transparent_red_value);
# endif
# ifdef EGL_TRANSPARENT_TYPE
	BOOST_CHECK(x != ev.transparent_type);
# endif
#endif

#ifdef EGL_MAX_SWAP_INTERVAL
	x = ev.max_swap_interval;
	BOOST_CHECK(x == ev.max_swap_interval);
# ifdef EGL_MIN_SWAP_INTERVAL
	BOOST_CHECK(x != ev.min_swap_interval);
# endif
# ifdef EGL_NATIVE_RENDERABLE
	BOOST_CHECK(x != ev.native_renderable);
# endif
# ifdef EGL_NATIVE_VISUAL_ID
	BOOST_CHECK(x != ev.native_visual_id);
# endif
# ifdef EGL_NATIVE_VISUAL_TYPE
	BOOST_CHECK(x != ev.native_visual_type);
# endif
# ifdef EGL_RED_SIZE
	BOOST_CHECK(x != ev.red_size);
# endif
# ifdef EGL_RENDERABLE_TYPE
	BOOST_CHECK(x != ev.renderable_type);
# endif
# ifdef EGL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef EGL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef EGL_STENCIL_SIZE
	BOOST_CHECK(x != ev.stencil_size);
# endif
# ifdef EGL_SURFACE_TYPE
	BOOST_CHECK(x != ev.surface_type);
# endif
# ifdef EGL_TRANSPARENT_BLUE_VALUE
	BOOST_CHECK(x != ev.transparent_blue_value);
# endif
# ifdef EGL_TRANSPARENT_GREEN_VALUE
	BOOST_CHECK(x != ev.transparent_green_value);
# endif
# ifdef EGL_TRANSPARENT_RED_VALUE
	BOOST_CHECK(x != ev.transparent_red_value);
# endif
# ifdef EGL_TRANSPARENT_TYPE
	BOOST_CHECK(x != ev.transparent_type);
# endif
#endif

#ifdef EGL_MIN_SWAP_INTERVAL
	x = ev.min_swap_interval;
	BOOST_CHECK(x == ev.min_swap_interval);
# ifdef EGL_NATIVE_RENDERABLE
	BOOST_CHECK(x != ev.native_renderable);
# endif
# ifdef EGL_NATIVE_VISUAL_ID
	BOOST_CHECK(x != ev.native_visual_id);
# endif
# ifdef EGL_NATIVE_VISUAL_TYPE
	BOOST_CHECK(x != ev.native_visual_type);
# endif
# ifdef EGL_RED_SIZE
	BOOST_CHECK(x != ev.red_size);
# endif
# ifdef EGL_RENDERABLE_TYPE
	BOOST_CHECK(x != ev.renderable_type);
# endif
# ifdef EGL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef EGL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef EGL_STENCIL_SIZE
	BOOST_CHECK(x != ev.stencil_size);
# endif
# ifdef EGL_SURFACE_TYPE
	BOOST_CHECK(x != ev.surface_type);
# endif
# ifdef EGL_TRANSPARENT_BLUE_VALUE
	BOOST_CHECK(x != ev.transparent_blue_value);
# endif
# ifdef EGL_TRANSPARENT_GREEN_VALUE
	BOOST_CHECK(x != ev.transparent_green_value);
# endif
# ifdef EGL_TRANSPARENT_RED_VALUE
	BOOST_CHECK(x != ev.transparent_red_value);
# endif
# ifdef EGL_TRANSPARENT_TYPE
	BOOST_CHECK(x != ev.transparent_type);
# endif
#endif

#ifdef EGL_NATIVE_RENDERABLE
	x = ev.native_renderable;
	BOOST_CHECK(x == ev.native_renderable);
# ifdef EGL_NATIVE_VISUAL_ID
	BOOST_CHECK(x != ev.native_visual_id);
# endif
# ifdef EGL_NATIVE_VISUAL_TYPE
	BOOST_CHECK(x != ev.native_visual_type);
# endif
# ifdef EGL_RED_SIZE
	BOOST_CHECK(x != ev.red_size);
# endif
# ifdef EGL_RENDERABLE_TYPE
	BOOST_CHECK(x != ev.renderable_type);
# endif
# ifdef EGL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef EGL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef EGL_STENCIL_SIZE
	BOOST_CHECK(x != ev.stencil_size);
# endif
# ifdef EGL_SURFACE_TYPE
	BOOST_CHECK(x != ev.surface_type);
# endif
# ifdef EGL_TRANSPARENT_BLUE_VALUE
	BOOST_CHECK(x != ev.transparent_blue_value);
# endif
# ifdef EGL_TRANSPARENT_GREEN_VALUE
	BOOST_CHECK(x != ev.transparent_green_value);
# endif
# ifdef EGL_TRANSPARENT_RED_VALUE
	BOOST_CHECK(x != ev.transparent_red_value);
# endif
# ifdef EGL_TRANSPARENT_TYPE
	BOOST_CHECK(x != ev.transparent_type);
# endif
#endif

#ifdef EGL_NATIVE_VISUAL_ID
	x = ev.native_visual_id;
	BOOST_CHECK(x == ev.native_visual_id);
# ifdef EGL_NATIVE_VISUAL_TYPE
	BOOST_CHECK(x != ev.native_visual_type);
# endif
# ifdef EGL_RED_SIZE
	BOOST_CHECK(x != ev.red_size);
# endif
# ifdef EGL_RENDERABLE_TYPE
	BOOST_CHECK(x != ev.renderable_type);
# endif
# ifdef EGL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef EGL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef EGL_STENCIL_SIZE
	BOOST_CHECK(x != ev.stencil_size);
# endif
# ifdef EGL_SURFACE_TYPE
	BOOST_CHECK(x != ev.surface_type);
# endif
# ifdef EGL_TRANSPARENT_BLUE_VALUE
	BOOST_CHECK(x != ev.transparent_blue_value);
# endif
# ifdef EGL_TRANSPARENT_GREEN_VALUE
	BOOST_CHECK(x != ev.transparent_green_value);
# endif
# ifdef EGL_TRANSPARENT_RED_VALUE
	BOOST_CHECK(x != ev.transparent_red_value);
# endif
# ifdef EGL_TRANSPARENT_TYPE
	BOOST_CHECK(x != ev.transparent_type);
# endif
#endif

#ifdef EGL_NATIVE_VISUAL_TYPE
	x = ev.native_visual_type;
	BOOST_CHECK(x == ev.native_visual_type);
# ifdef EGL_RED_SIZE
	BOOST_CHECK(x != ev.red_size);
# endif
# ifdef EGL_RENDERABLE_TYPE
	BOOST_CHECK(x != ev.renderable_type);
# endif
# ifdef EGL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef EGL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef EGL_STENCIL_SIZE
	BOOST_CHECK(x != ev.stencil_size);
# endif
# ifdef EGL_SURFACE_TYPE
	BOOST_CHECK(x != ev.surface_type);
# endif
# ifdef EGL_TRANSPARENT_BLUE_VALUE
	BOOST_CHECK(x != ev.transparent_blue_value);
# endif
# ifdef EGL_TRANSPARENT_GREEN_VALUE
	BOOST_CHECK(x != ev.transparent_green_value);
# endif
# ifdef EGL_TRANSPARENT_RED_VALUE
	BOOST_CHECK(x != ev.transparent_red_value);
# endif
# ifdef EGL_TRANSPARENT_TYPE
	BOOST_CHECK(x != ev.transparent_type);
# endif
#endif

#ifdef EGL_RED_SIZE
	x = ev.red_size;
	BOOST_CHECK(x == ev.red_size);
# ifdef EGL_RENDERABLE_TYPE
	BOOST_CHECK(x != ev.renderable_type);
# endif
# ifdef EGL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef EGL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef EGL_STENCIL_SIZE
	BOOST_CHECK(x != ev.stencil_size);
# endif
# ifdef EGL_SURFACE_TYPE
	BOOST_CHECK(x != ev.surface_type);
# endif
# ifdef EGL_TRANSPARENT_BLUE_VALUE
	BOOST_CHECK(x != ev.transparent_blue_value);
# endif
# ifdef EGL_TRANSPARENT_GREEN_VALUE
	BOOST_CHECK(x != ev.transparent_green_value);
# endif
# ifdef EGL_TRANSPARENT_RED_VALUE
	BOOST_CHECK(x != ev.transparent_red_value);
# endif
# ifdef EGL_TRANSPARENT_TYPE
	BOOST_CHECK(x != ev.transparent_type);
# endif
#endif

#ifdef EGL_RENDERABLE_TYPE
	x = ev.renderable_type;
	BOOST_CHECK(x == ev.renderable_type);
# ifdef EGL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef EGL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef EGL_STENCIL_SIZE
	BOOST_CHECK(x != ev.stencil_size);
# endif
# ifdef EGL_SURFACE_TYPE
	BOOST_CHECK(x != ev.surface_type);
# endif
# ifdef EGL_TRANSPARENT_BLUE_VALUE
	BOOST_CHECK(x != ev.transparent_blue_value);
# endif
# ifdef EGL_TRANSPARENT_GREEN_VALUE
	BOOST_CHECK(x != ev.transparent_green_value);
# endif
# ifdef EGL_TRANSPARENT_RED_VALUE
	BOOST_CHECK(x != ev.transparent_red_value);
# endif
# ifdef EGL_TRANSPARENT_TYPE
	BOOST_CHECK(x != ev.transparent_type);
# endif
#endif

#ifdef EGL_SAMPLE_BUFFERS
	x = ev.sample_buffers;
	BOOST_CHECK(x == ev.sample_buffers);
# ifdef EGL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef EGL_STENCIL_SIZE
	BOOST_CHECK(x != ev.stencil_size);
# endif
# ifdef EGL_SURFACE_TYPE
	BOOST_CHECK(x != ev.surface_type);
# endif
# ifdef EGL_TRANSPARENT_BLUE_VALUE
	BOOST_CHECK(x != ev.transparent_blue_value);
# endif
# ifdef EGL_TRANSPARENT_GREEN_VALUE
	BOOST_CHECK(x != ev.transparent_green_value);
# endif
# ifdef EGL_TRANSPARENT_RED_VALUE
	BOOST_CHECK(x != ev.transparent_red_value);
# endif
# ifdef EGL_TRANSPARENT_TYPE
	BOOST_CHECK(x != ev.transparent_type);
# endif
#endif

#ifdef EGL_SAMPLES
	x = ev.samples;
	BOOST_CHECK(x == ev.samples);
# ifdef EGL_STENCIL_SIZE
	BOOST_CHECK(x != ev.stencil_size);
# endif
# ifdef EGL_SURFACE_TYPE
	BOOST_CHECK(x != ev.surface_type);
# endif
# ifdef EGL_TRANSPARENT_BLUE_VALUE
	BOOST_CHECK(x != ev.transparent_blue_value);
# endif
# ifdef EGL_TRANSPARENT_GREEN_VALUE
	BOOST_CHECK(x != ev.transparent_green_value);
# endif
# ifdef EGL_TRANSPARENT_RED_VALUE
	BOOST_CHECK(x != ev.transparent_red_value);
# endif
# ifdef EGL_TRANSPARENT_TYPE
	BOOST_CHECK(x != ev.transparent_type);
# endif
#endif

#ifdef EGL_STENCIL_SIZE
	x = ev.stencil_size;
	BOOST_CHECK(x == ev.stencil_size);
# ifdef EGL_SURFACE_TYPE
	BOOST_CHECK(x != ev.surface_type);
# endif
# ifdef EGL_TRANSPARENT_BLUE_VALUE
	BOOST_CHECK(x != ev.transparent_blue_value);
# endif
# ifdef EGL_TRANSPARENT_GREEN_VALUE
	BOOST_CHECK(x != ev.transparent_green_value);
# endif
# ifdef EGL_TRANSPARENT_RED_VALUE
	BOOST_CHECK(x != ev.transparent_red_value);
# endif
# ifdef EGL_TRANSPARENT_TYPE
	BOOST_CHECK(x != ev.transparent_type);
# endif
#endif

#ifdef EGL_SURFACE_TYPE
	x = ev.surface_type;
	BOOST_CHECK(x == ev.surface_type);
# ifdef EGL_TRANSPARENT_BLUE_VALUE
	BOOST_CHECK(x != ev.transparent_blue_value);
# endif
# ifdef EGL_TRANSPARENT_GREEN_VALUE
	BOOST_CHECK(x != ev.transparent_green_value);
# endif
# ifdef EGL_TRANSPARENT_RED_VALUE
	BOOST_CHECK(x != ev.transparent_red_value);
# endif
# ifdef EGL_TRANSPARENT_TYPE
	BOOST_CHECK(x != ev.transparent_type);
# endif
#endif

#ifdef EGL_TRANSPARENT_BLUE_VALUE
	x = ev.transparent_blue_value;
	BOOST_CHECK(x == ev.transparent_blue_value);
# ifdef EGL_TRANSPARENT_GREEN_VALUE
	BOOST_CHECK(x != ev.transparent_green_value);
# endif
# ifdef EGL_TRANSPARENT_RED_VALUE
	BOOST_CHECK(x != ev.transparent_red_value);
# endif
# ifdef EGL_TRANSPARENT_TYPE
	BOOST_CHECK(x != ev.transparent_type);
# endif
#endif

#ifdef EGL_TRANSPARENT_GREEN_VALUE
	x = ev.transparent_green_value;
	BOOST_CHECK(x == ev.transparent_green_value);
# ifdef EGL_TRANSPARENT_RED_VALUE
	BOOST_CHECK(x != ev.transparent_red_value);
# endif
# ifdef EGL_TRANSPARENT_TYPE
	BOOST_CHECK(x != ev.transparent_type);
# endif
#endif

#ifdef EGL_TRANSPARENT_RED_VALUE
	x = ev.transparent_red_value;
	BOOST_CHECK(x == ev.transparent_red_value);
# ifdef EGL_TRANSPARENT_TYPE
	BOOST_CHECK(x != ev.transparent_type);
# endif
#endif

#ifdef EGL_TRANSPARENT_TYPE
	x = ev.transparent_type;
	BOOST_CHECK(x == ev.transparent_type);
#endif
}

BOOST_AUTO_TEST_CASE(enum_config_attrib_names)
{
	using namespace eglplus;
	enum_values ev;
	(void)ev;
	config_attrib x;
	(void)x;

#ifdef EGL_ALPHA_MASK_SIZE
	x = ev.alpha_mask_size;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ALPHA_MASK_SIZE"
	) == 0);
#endif

#ifdef EGL_ALPHA_SIZE
	x = ev.alpha_size;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ALPHA_SIZE"
	) == 0);
#endif

#ifdef EGL_BIND_TO_TEXTURE_RGB
	x = ev.bind_to_texture_rgb;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"BIND_TO_TEXTURE_RGB"
	) == 0);
#endif

#ifdef EGL_BIND_TO_TEXTURE_RGBA
	x = ev.bind_to_texture_rgba;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"BIND_TO_TEXTURE_RGBA"
	) == 0);
#endif

#ifdef EGL_BLUE_SIZE
	x = ev.blue_size;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"BLUE_SIZE"
	) == 0);
#endif

#ifdef EGL_BUFFER_SIZE
	x = ev.buffer_size;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"BUFFER_SIZE"
	) == 0);
#endif

#ifdef EGL_COLOR_BUFFER_TYPE
	x = ev.color_buffer_type;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"COLOR_BUFFER_TYPE"
	) == 0);
#endif

#ifdef EGL_CONFIG_CAVEAT
	x = ev.config_caveat;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"CONFIG_CAVEAT"
	) == 0);
#endif

#ifdef EGL_CONFIG_ID
	x = ev.config_id;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"CONFIG_ID"
	) == 0);
#endif

#ifdef EGL_CONFORMANT
	x = ev.conformant;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"CONFORMANT"
	) == 0);
#endif

#ifdef EGL_DEPTH_SIZE
	x = ev.depth_size;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DEPTH_SIZE"
	) == 0);
#endif

#ifdef EGL_GREEN_SIZE
	x = ev.green_size;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"GREEN_SIZE"
	) == 0);
#endif

#ifdef EGL_LEVEL
	x = ev.level;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"LEVEL"
	) == 0);
#endif

#ifdef EGL_LUMINANCE_SIZE
	x = ev.luminance_size;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"LUMINANCE_SIZE"
	) == 0);
#endif

#ifdef EGL_MAX_PBUFFER_HEIGHT
	x = ev.max_pbuffer_height;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_PBUFFER_HEIGHT"
	) == 0);
#endif

#ifdef EGL_MAX_PBUFFER_PIXELS
	x = ev.max_pbuffer_pixels;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_PBUFFER_PIXELS"
	) == 0);
#endif

#ifdef EGL_MAX_PBUFFER_WIDTH
	x = ev.max_pbuffer_width;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_PBUFFER_WIDTH"
	) == 0);
#endif

#ifdef EGL_MAX_SWAP_INTERVAL
	x = ev.max_swap_interval;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_SWAP_INTERVAL"
	) == 0);
#endif

#ifdef EGL_MIN_SWAP_INTERVAL
	x = ev.min_swap_interval;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MIN_SWAP_INTERVAL"
	) == 0);
#endif

#ifdef EGL_NATIVE_RENDERABLE
	x = ev.native_renderable;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"NATIVE_RENDERABLE"
	) == 0);
#endif

#ifdef EGL_NATIVE_VISUAL_ID
	x = ev.native_visual_id;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"NATIVE_VISUAL_ID"
	) == 0);
#endif

#ifdef EGL_NATIVE_VISUAL_TYPE
	x = ev.native_visual_type;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"NATIVE_VISUAL_TYPE"
	) == 0);
#endif

#ifdef EGL_RED_SIZE
	x = ev.red_size;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RED_SIZE"
	) == 0);
#endif

#ifdef EGL_RENDERABLE_TYPE
	x = ev.renderable_type;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RENDERABLE_TYPE"
	) == 0);
#endif

#ifdef EGL_SAMPLE_BUFFERS
	x = ev.sample_buffers;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SAMPLE_BUFFERS"
	) == 0);
#endif

#ifdef EGL_SAMPLES
	x = ev.samples;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SAMPLES"
	) == 0);
#endif

#ifdef EGL_STENCIL_SIZE
	x = ev.stencil_size;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"STENCIL_SIZE"
	) == 0);
#endif

#ifdef EGL_SURFACE_TYPE
	x = ev.surface_type;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SURFACE_TYPE"
	) == 0);
#endif

#ifdef EGL_TRANSPARENT_BLUE_VALUE
	x = ev.transparent_blue_value;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TRANSPARENT_BLUE_VALUE"
	) == 0);
#endif

#ifdef EGL_TRANSPARENT_GREEN_VALUE
	x = ev.transparent_green_value;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TRANSPARENT_GREEN_VALUE"
	) == 0);
#endif

#ifdef EGL_TRANSPARENT_RED_VALUE
	x = ev.transparent_red_value;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TRANSPARENT_RED_VALUE"
	) == 0);
#endif

#ifdef EGL_TRANSPARENT_TYPE
	x = ev.transparent_type;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TRANSPARENT_TYPE"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_config_attrib_range)
{
	using namespace eglplus;
	auto count = enum_value_range<config_attrib>().size();

#ifdef EGL_ALPHA_MASK_SIZE
{
	--count;
	auto r = enum_value_range<config_attrib>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		config_attrib(EGL_ALPHA_MASK_SIZE)
	) != r.end());
}
#endif

#ifdef EGL_ALPHA_SIZE
{
	--count;
	auto r = enum_value_range<config_attrib>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		config_attrib(EGL_ALPHA_SIZE)
	) != r.end());
}
#endif

#ifdef EGL_BIND_TO_TEXTURE_RGB
{
	--count;
	auto r = enum_value_range<config_attrib>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		config_attrib(EGL_BIND_TO_TEXTURE_RGB)
	) != r.end());
}
#endif

#ifdef EGL_BIND_TO_TEXTURE_RGBA
{
	--count;
	auto r = enum_value_range<config_attrib>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		config_attrib(EGL_BIND_TO_TEXTURE_RGBA)
	) != r.end());
}
#endif

#ifdef EGL_BLUE_SIZE
{
	--count;
	auto r = enum_value_range<config_attrib>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		config_attrib(EGL_BLUE_SIZE)
	) != r.end());
}
#endif

#ifdef EGL_BUFFER_SIZE
{
	--count;
	auto r = enum_value_range<config_attrib>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		config_attrib(EGL_BUFFER_SIZE)
	) != r.end());
}
#endif

#ifdef EGL_COLOR_BUFFER_TYPE
{
	--count;
	auto r = enum_value_range<config_attrib>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		config_attrib(EGL_COLOR_BUFFER_TYPE)
	) != r.end());
}
#endif

#ifdef EGL_CONFIG_CAVEAT
{
	--count;
	auto r = enum_value_range<config_attrib>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		config_attrib(EGL_CONFIG_CAVEAT)
	) != r.end());
}
#endif

#ifdef EGL_CONFIG_ID
{
	--count;
	auto r = enum_value_range<config_attrib>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		config_attrib(EGL_CONFIG_ID)
	) != r.end());
}
#endif

#ifdef EGL_CONFORMANT
{
	--count;
	auto r = enum_value_range<config_attrib>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		config_attrib(EGL_CONFORMANT)
	) != r.end());
}
#endif

#ifdef EGL_DEPTH_SIZE
{
	--count;
	auto r = enum_value_range<config_attrib>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		config_attrib(EGL_DEPTH_SIZE)
	) != r.end());
}
#endif

#ifdef EGL_GREEN_SIZE
{
	--count;
	auto r = enum_value_range<config_attrib>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		config_attrib(EGL_GREEN_SIZE)
	) != r.end());
}
#endif

#ifdef EGL_LEVEL
{
	--count;
	auto r = enum_value_range<config_attrib>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		config_attrib(EGL_LEVEL)
	) != r.end());
}
#endif

#ifdef EGL_LUMINANCE_SIZE
{
	--count;
	auto r = enum_value_range<config_attrib>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		config_attrib(EGL_LUMINANCE_SIZE)
	) != r.end());
}
#endif

#ifdef EGL_MAX_PBUFFER_HEIGHT
{
	--count;
	auto r = enum_value_range<config_attrib>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		config_attrib(EGL_MAX_PBUFFER_HEIGHT)
	) != r.end());
}
#endif

#ifdef EGL_MAX_PBUFFER_PIXELS
{
	--count;
	auto r = enum_value_range<config_attrib>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		config_attrib(EGL_MAX_PBUFFER_PIXELS)
	) != r.end());
}
#endif

#ifdef EGL_MAX_PBUFFER_WIDTH
{
	--count;
	auto r = enum_value_range<config_attrib>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		config_attrib(EGL_MAX_PBUFFER_WIDTH)
	) != r.end());
}
#endif

#ifdef EGL_MAX_SWAP_INTERVAL
{
	--count;
	auto r = enum_value_range<config_attrib>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		config_attrib(EGL_MAX_SWAP_INTERVAL)
	) != r.end());
}
#endif

#ifdef EGL_MIN_SWAP_INTERVAL
{
	--count;
	auto r = enum_value_range<config_attrib>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		config_attrib(EGL_MIN_SWAP_INTERVAL)
	) != r.end());
}
#endif

#ifdef EGL_NATIVE_RENDERABLE
{
	--count;
	auto r = enum_value_range<config_attrib>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		config_attrib(EGL_NATIVE_RENDERABLE)
	) != r.end());
}
#endif

#ifdef EGL_NATIVE_VISUAL_ID
{
	--count;
	auto r = enum_value_range<config_attrib>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		config_attrib(EGL_NATIVE_VISUAL_ID)
	) != r.end());
}
#endif

#ifdef EGL_NATIVE_VISUAL_TYPE
{
	--count;
	auto r = enum_value_range<config_attrib>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		config_attrib(EGL_NATIVE_VISUAL_TYPE)
	) != r.end());
}
#endif

#ifdef EGL_RED_SIZE
{
	--count;
	auto r = enum_value_range<config_attrib>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		config_attrib(EGL_RED_SIZE)
	) != r.end());
}
#endif

#ifdef EGL_RENDERABLE_TYPE
{
	--count;
	auto r = enum_value_range<config_attrib>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		config_attrib(EGL_RENDERABLE_TYPE)
	) != r.end());
}
#endif

#ifdef EGL_SAMPLE_BUFFERS
{
	--count;
	auto r = enum_value_range<config_attrib>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		config_attrib(EGL_SAMPLE_BUFFERS)
	) != r.end());
}
#endif

#ifdef EGL_SAMPLES
{
	--count;
	auto r = enum_value_range<config_attrib>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		config_attrib(EGL_SAMPLES)
	) != r.end());
}
#endif

#ifdef EGL_STENCIL_SIZE
{
	--count;
	auto r = enum_value_range<config_attrib>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		config_attrib(EGL_STENCIL_SIZE)
	) != r.end());
}
#endif

#ifdef EGL_SURFACE_TYPE
{
	--count;
	auto r = enum_value_range<config_attrib>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		config_attrib(EGL_SURFACE_TYPE)
	) != r.end());
}
#endif

#ifdef EGL_TRANSPARENT_BLUE_VALUE
{
	--count;
	auto r = enum_value_range<config_attrib>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		config_attrib(EGL_TRANSPARENT_BLUE_VALUE)
	) != r.end());
}
#endif

#ifdef EGL_TRANSPARENT_GREEN_VALUE
{
	--count;
	auto r = enum_value_range<config_attrib>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		config_attrib(EGL_TRANSPARENT_GREEN_VALUE)
	) != r.end());
}
#endif

#ifdef EGL_TRANSPARENT_RED_VALUE
{
	--count;
	auto r = enum_value_range<config_attrib>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		config_attrib(EGL_TRANSPARENT_RED_VALUE)
	) != r.end());
}
#endif

#ifdef EGL_TRANSPARENT_TYPE
{
	--count;
	auto r = enum_value_range<config_attrib>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		config_attrib(EGL_TRANSPARENT_TYPE)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_config_attrib_any)
{
	using namespace eglplus;
	enum_values ev;
	(void)ev;
	config_attrib x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef EGL_ALPHA_MASK_SIZE
	x = ev.alpha_mask_size;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.alpha_mask_size);
#endif

#ifdef EGL_ALPHA_SIZE
	x = ev.alpha_size;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.alpha_size);
#endif

#ifdef EGL_BIND_TO_TEXTURE_RGB
	x = ev.bind_to_texture_rgb;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.bind_to_texture_rgb);
#endif

#ifdef EGL_BIND_TO_TEXTURE_RGBA
	x = ev.bind_to_texture_rgba;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.bind_to_texture_rgba);
#endif

#ifdef EGL_BLUE_SIZE
	x = ev.blue_size;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.blue_size);
#endif

#ifdef EGL_BUFFER_SIZE
	x = ev.buffer_size;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.buffer_size);
#endif

#ifdef EGL_COLOR_BUFFER_TYPE
	x = ev.color_buffer_type;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.color_buffer_type);
#endif

#ifdef EGL_CONFIG_CAVEAT
	x = ev.config_caveat;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.config_caveat);
#endif

#ifdef EGL_CONFIG_ID
	x = ev.config_id;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.config_id);
#endif

#ifdef EGL_CONFORMANT
	x = ev.conformant;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.conformant);
#endif

#ifdef EGL_DEPTH_SIZE
	x = ev.depth_size;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.depth_size);
#endif

#ifdef EGL_GREEN_SIZE
	x = ev.green_size;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.green_size);
#endif

#ifdef EGL_LEVEL
	x = ev.level;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.level);
#endif

#ifdef EGL_LUMINANCE_SIZE
	x = ev.luminance_size;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.luminance_size);
#endif

#ifdef EGL_MAX_PBUFFER_HEIGHT
	x = ev.max_pbuffer_height;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_pbuffer_height);
#endif

#ifdef EGL_MAX_PBUFFER_PIXELS
	x = ev.max_pbuffer_pixels;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_pbuffer_pixels);
#endif

#ifdef EGL_MAX_PBUFFER_WIDTH
	x = ev.max_pbuffer_width;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_pbuffer_width);
#endif

#ifdef EGL_MAX_SWAP_INTERVAL
	x = ev.max_swap_interval;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_swap_interval);
#endif

#ifdef EGL_MIN_SWAP_INTERVAL
	x = ev.min_swap_interval;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.min_swap_interval);
#endif

#ifdef EGL_NATIVE_RENDERABLE
	x = ev.native_renderable;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.native_renderable);
#endif

#ifdef EGL_NATIVE_VISUAL_ID
	x = ev.native_visual_id;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.native_visual_id);
#endif

#ifdef EGL_NATIVE_VISUAL_TYPE
	x = ev.native_visual_type;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.native_visual_type);
#endif

#ifdef EGL_RED_SIZE
	x = ev.red_size;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.red_size);
#endif

#ifdef EGL_RENDERABLE_TYPE
	x = ev.renderable_type;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.renderable_type);
#endif

#ifdef EGL_SAMPLE_BUFFERS
	x = ev.sample_buffers;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.sample_buffers);
#endif

#ifdef EGL_SAMPLES
	x = ev.samples;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.samples);
#endif

#ifdef EGL_STENCIL_SIZE
	x = ev.stencil_size;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.stencil_size);
#endif

#ifdef EGL_SURFACE_TYPE
	x = ev.surface_type;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.surface_type);
#endif

#ifdef EGL_TRANSPARENT_BLUE_VALUE
	x = ev.transparent_blue_value;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.transparent_blue_value);
#endif

#ifdef EGL_TRANSPARENT_GREEN_VALUE
	x = ev.transparent_green_value;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.transparent_green_value);
#endif

#ifdef EGL_TRANSPARENT_RED_VALUE
	x = ev.transparent_red_value;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.transparent_red_value);
#endif

#ifdef EGL_TRANSPARENT_TYPE
	x = ev.transparent_type;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.transparent_type);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
