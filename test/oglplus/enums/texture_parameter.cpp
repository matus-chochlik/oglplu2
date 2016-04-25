//  File test/oglplus/enums/texture_parameter.cpp
//
//  Automatically generated file, DO NOT modify manually.
//  Edit the enumeration source files in 'source/enums/oglplus'
//  or the 'source/enums/make_enum.py' script instead.
//
//  Copyright Matus Chochlik.
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//   http://www.boost.org/LICENSE_1_0.txt
//
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE OGLPLUS_texture_parameter

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_texture_parameter_tests)

BOOST_AUTO_TEST_CASE(enum_texture_parameter_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	texture_parameter x;
	(void)x;

#ifdef GL_DEPTH_STENCIL_TEXTURE_MODE
	x = ev.depth_stencil_texture_mode;
	BOOST_CHECK(x == ev.depth_stencil_texture_mode);
# ifdef GL_IMAGE_FORMAT_COMPATIBILITY_TYPE
	BOOST_CHECK(x != ev.image_format_compatibility_type);
# endif
# ifdef GL_TEXTURE_BASE_LEVEL
	BOOST_CHECK(x != ev.texture_base_level);
# endif
# ifdef GL_TEXTURE_BORDER_COLOR
	BOOST_CHECK(x != ev.texture_border_color);
# endif
# ifdef GL_TEXTURE_COMPARE_FUNC
	BOOST_CHECK(x != ev.texture_compare_func);
# endif
# ifdef GL_TEXTURE_COMPARE_MODE
	BOOST_CHECK(x != ev.texture_compare_mode);
# endif
# ifdef GL_TEXTURE_IMMUTABLE_FORMAT
	BOOST_CHECK(x != ev.texture_immutable_format);
# endif
# ifdef GL_TEXTURE_IMMUTABLE_LEVELS
	BOOST_CHECK(x != ev.texture_immutable_levels);
# endif
# ifdef GL_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.texture_lod_bias);
# endif
# ifdef GL_TEXTURE_MAG_FILTER
	BOOST_CHECK(x != ev.texture_mag_filter);
# endif
# ifdef GL_TEXTURE_MAX_LEVEL
	BOOST_CHECK(x != ev.texture_max_level);
# endif
# ifdef GL_TEXTURE_MAX_LOD
	BOOST_CHECK(x != ev.texture_max_lod);
# endif
# ifdef GL_TEXTURE_MIN_FILTER
	BOOST_CHECK(x != ev.texture_min_filter);
# endif
# ifdef GL_TEXTURE_MIN_LOD
	BOOST_CHECK(x != ev.texture_min_lod);
# endif
# ifdef GL_TEXTURE_SWIZZLE_A
	BOOST_CHECK(x != ev.texture_swizzle_a);
# endif
# ifdef GL_TEXTURE_SWIZZLE_B
	BOOST_CHECK(x != ev.texture_swizzle_b);
# endif
# ifdef GL_TEXTURE_SWIZZLE_G
	BOOST_CHECK(x != ev.texture_swizzle_g);
# endif
# ifdef GL_TEXTURE_SWIZZLE_R
	BOOST_CHECK(x != ev.texture_swizzle_r);
# endif
# ifdef GL_TEXTURE_SWIZZLE_RGBA
	BOOST_CHECK(x != ev.texture_swizzle_rgba);
# endif
# ifdef GL_TEXTURE_TARGET
	BOOST_CHECK(x != ev.texture_target);
# endif
# ifdef GL_TEXTURE_VIEW_MIN_LAYER
	BOOST_CHECK(x != ev.texture_view_min_layer);
# endif
# ifdef GL_TEXTURE_VIEW_MIN_LEVEL
	BOOST_CHECK(x != ev.texture_view_min_level);
# endif
# ifdef GL_TEXTURE_VIEW_NUM_LAYERS
	BOOST_CHECK(x != ev.texture_view_num_layers);
# endif
# ifdef GL_TEXTURE_VIEW_NUM_LEVELS
	BOOST_CHECK(x != ev.texture_view_num_levels);
# endif
# ifdef GL_TEXTURE_WRAP_R
	BOOST_CHECK(x != ev.texture_wrap_r);
# endif
# ifdef GL_TEXTURE_WRAP_S
	BOOST_CHECK(x != ev.texture_wrap_s);
# endif
# ifdef GL_TEXTURE_WRAP_T
	BOOST_CHECK(x != ev.texture_wrap_t);
# endif
#endif

#ifdef GL_IMAGE_FORMAT_COMPATIBILITY_TYPE
	x = ev.image_format_compatibility_type;
	BOOST_CHECK(x == ev.image_format_compatibility_type);
# ifdef GL_TEXTURE_BASE_LEVEL
	BOOST_CHECK(x != ev.texture_base_level);
# endif
# ifdef GL_TEXTURE_BORDER_COLOR
	BOOST_CHECK(x != ev.texture_border_color);
# endif
# ifdef GL_TEXTURE_COMPARE_FUNC
	BOOST_CHECK(x != ev.texture_compare_func);
# endif
# ifdef GL_TEXTURE_COMPARE_MODE
	BOOST_CHECK(x != ev.texture_compare_mode);
# endif
# ifdef GL_TEXTURE_IMMUTABLE_FORMAT
	BOOST_CHECK(x != ev.texture_immutable_format);
# endif
# ifdef GL_TEXTURE_IMMUTABLE_LEVELS
	BOOST_CHECK(x != ev.texture_immutable_levels);
# endif
# ifdef GL_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.texture_lod_bias);
# endif
# ifdef GL_TEXTURE_MAG_FILTER
	BOOST_CHECK(x != ev.texture_mag_filter);
# endif
# ifdef GL_TEXTURE_MAX_LEVEL
	BOOST_CHECK(x != ev.texture_max_level);
# endif
# ifdef GL_TEXTURE_MAX_LOD
	BOOST_CHECK(x != ev.texture_max_lod);
# endif
# ifdef GL_TEXTURE_MIN_FILTER
	BOOST_CHECK(x != ev.texture_min_filter);
# endif
# ifdef GL_TEXTURE_MIN_LOD
	BOOST_CHECK(x != ev.texture_min_lod);
# endif
# ifdef GL_TEXTURE_SWIZZLE_A
	BOOST_CHECK(x != ev.texture_swizzle_a);
# endif
# ifdef GL_TEXTURE_SWIZZLE_B
	BOOST_CHECK(x != ev.texture_swizzle_b);
# endif
# ifdef GL_TEXTURE_SWIZZLE_G
	BOOST_CHECK(x != ev.texture_swizzle_g);
# endif
# ifdef GL_TEXTURE_SWIZZLE_R
	BOOST_CHECK(x != ev.texture_swizzle_r);
# endif
# ifdef GL_TEXTURE_SWIZZLE_RGBA
	BOOST_CHECK(x != ev.texture_swizzle_rgba);
# endif
# ifdef GL_TEXTURE_TARGET
	BOOST_CHECK(x != ev.texture_target);
# endif
# ifdef GL_TEXTURE_VIEW_MIN_LAYER
	BOOST_CHECK(x != ev.texture_view_min_layer);
# endif
# ifdef GL_TEXTURE_VIEW_MIN_LEVEL
	BOOST_CHECK(x != ev.texture_view_min_level);
# endif
# ifdef GL_TEXTURE_VIEW_NUM_LAYERS
	BOOST_CHECK(x != ev.texture_view_num_layers);
# endif
# ifdef GL_TEXTURE_VIEW_NUM_LEVELS
	BOOST_CHECK(x != ev.texture_view_num_levels);
# endif
# ifdef GL_TEXTURE_WRAP_R
	BOOST_CHECK(x != ev.texture_wrap_r);
# endif
# ifdef GL_TEXTURE_WRAP_S
	BOOST_CHECK(x != ev.texture_wrap_s);
# endif
# ifdef GL_TEXTURE_WRAP_T
	BOOST_CHECK(x != ev.texture_wrap_t);
# endif
#endif

#ifdef GL_TEXTURE_BASE_LEVEL
	x = ev.texture_base_level;
	BOOST_CHECK(x == ev.texture_base_level);
# ifdef GL_TEXTURE_BORDER_COLOR
	BOOST_CHECK(x != ev.texture_border_color);
# endif
# ifdef GL_TEXTURE_COMPARE_FUNC
	BOOST_CHECK(x != ev.texture_compare_func);
# endif
# ifdef GL_TEXTURE_COMPARE_MODE
	BOOST_CHECK(x != ev.texture_compare_mode);
# endif
# ifdef GL_TEXTURE_IMMUTABLE_FORMAT
	BOOST_CHECK(x != ev.texture_immutable_format);
# endif
# ifdef GL_TEXTURE_IMMUTABLE_LEVELS
	BOOST_CHECK(x != ev.texture_immutable_levels);
# endif
# ifdef GL_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.texture_lod_bias);
# endif
# ifdef GL_TEXTURE_MAG_FILTER
	BOOST_CHECK(x != ev.texture_mag_filter);
# endif
# ifdef GL_TEXTURE_MAX_LEVEL
	BOOST_CHECK(x != ev.texture_max_level);
# endif
# ifdef GL_TEXTURE_MAX_LOD
	BOOST_CHECK(x != ev.texture_max_lod);
# endif
# ifdef GL_TEXTURE_MIN_FILTER
	BOOST_CHECK(x != ev.texture_min_filter);
# endif
# ifdef GL_TEXTURE_MIN_LOD
	BOOST_CHECK(x != ev.texture_min_lod);
# endif
# ifdef GL_TEXTURE_SWIZZLE_A
	BOOST_CHECK(x != ev.texture_swizzle_a);
# endif
# ifdef GL_TEXTURE_SWIZZLE_B
	BOOST_CHECK(x != ev.texture_swizzle_b);
# endif
# ifdef GL_TEXTURE_SWIZZLE_G
	BOOST_CHECK(x != ev.texture_swizzle_g);
# endif
# ifdef GL_TEXTURE_SWIZZLE_R
	BOOST_CHECK(x != ev.texture_swizzle_r);
# endif
# ifdef GL_TEXTURE_SWIZZLE_RGBA
	BOOST_CHECK(x != ev.texture_swizzle_rgba);
# endif
# ifdef GL_TEXTURE_TARGET
	BOOST_CHECK(x != ev.texture_target);
# endif
# ifdef GL_TEXTURE_VIEW_MIN_LAYER
	BOOST_CHECK(x != ev.texture_view_min_layer);
# endif
# ifdef GL_TEXTURE_VIEW_MIN_LEVEL
	BOOST_CHECK(x != ev.texture_view_min_level);
# endif
# ifdef GL_TEXTURE_VIEW_NUM_LAYERS
	BOOST_CHECK(x != ev.texture_view_num_layers);
# endif
# ifdef GL_TEXTURE_VIEW_NUM_LEVELS
	BOOST_CHECK(x != ev.texture_view_num_levels);
# endif
# ifdef GL_TEXTURE_WRAP_R
	BOOST_CHECK(x != ev.texture_wrap_r);
# endif
# ifdef GL_TEXTURE_WRAP_S
	BOOST_CHECK(x != ev.texture_wrap_s);
# endif
# ifdef GL_TEXTURE_WRAP_T
	BOOST_CHECK(x != ev.texture_wrap_t);
# endif
#endif

#ifdef GL_TEXTURE_BORDER_COLOR
	x = ev.texture_border_color;
	BOOST_CHECK(x == ev.texture_border_color);
# ifdef GL_TEXTURE_COMPARE_FUNC
	BOOST_CHECK(x != ev.texture_compare_func);
# endif
# ifdef GL_TEXTURE_COMPARE_MODE
	BOOST_CHECK(x != ev.texture_compare_mode);
# endif
# ifdef GL_TEXTURE_IMMUTABLE_FORMAT
	BOOST_CHECK(x != ev.texture_immutable_format);
# endif
# ifdef GL_TEXTURE_IMMUTABLE_LEVELS
	BOOST_CHECK(x != ev.texture_immutable_levels);
# endif
# ifdef GL_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.texture_lod_bias);
# endif
# ifdef GL_TEXTURE_MAG_FILTER
	BOOST_CHECK(x != ev.texture_mag_filter);
# endif
# ifdef GL_TEXTURE_MAX_LEVEL
	BOOST_CHECK(x != ev.texture_max_level);
# endif
# ifdef GL_TEXTURE_MAX_LOD
	BOOST_CHECK(x != ev.texture_max_lod);
# endif
# ifdef GL_TEXTURE_MIN_FILTER
	BOOST_CHECK(x != ev.texture_min_filter);
# endif
# ifdef GL_TEXTURE_MIN_LOD
	BOOST_CHECK(x != ev.texture_min_lod);
# endif
# ifdef GL_TEXTURE_SWIZZLE_A
	BOOST_CHECK(x != ev.texture_swizzle_a);
# endif
# ifdef GL_TEXTURE_SWIZZLE_B
	BOOST_CHECK(x != ev.texture_swizzle_b);
# endif
# ifdef GL_TEXTURE_SWIZZLE_G
	BOOST_CHECK(x != ev.texture_swizzle_g);
# endif
# ifdef GL_TEXTURE_SWIZZLE_R
	BOOST_CHECK(x != ev.texture_swizzle_r);
# endif
# ifdef GL_TEXTURE_SWIZZLE_RGBA
	BOOST_CHECK(x != ev.texture_swizzle_rgba);
# endif
# ifdef GL_TEXTURE_TARGET
	BOOST_CHECK(x != ev.texture_target);
# endif
# ifdef GL_TEXTURE_VIEW_MIN_LAYER
	BOOST_CHECK(x != ev.texture_view_min_layer);
# endif
# ifdef GL_TEXTURE_VIEW_MIN_LEVEL
	BOOST_CHECK(x != ev.texture_view_min_level);
# endif
# ifdef GL_TEXTURE_VIEW_NUM_LAYERS
	BOOST_CHECK(x != ev.texture_view_num_layers);
# endif
# ifdef GL_TEXTURE_VIEW_NUM_LEVELS
	BOOST_CHECK(x != ev.texture_view_num_levels);
# endif
# ifdef GL_TEXTURE_WRAP_R
	BOOST_CHECK(x != ev.texture_wrap_r);
# endif
# ifdef GL_TEXTURE_WRAP_S
	BOOST_CHECK(x != ev.texture_wrap_s);
# endif
# ifdef GL_TEXTURE_WRAP_T
	BOOST_CHECK(x != ev.texture_wrap_t);
# endif
#endif

#ifdef GL_TEXTURE_COMPARE_FUNC
	x = ev.texture_compare_func;
	BOOST_CHECK(x == ev.texture_compare_func);
# ifdef GL_TEXTURE_COMPARE_MODE
	BOOST_CHECK(x != ev.texture_compare_mode);
# endif
# ifdef GL_TEXTURE_IMMUTABLE_FORMAT
	BOOST_CHECK(x != ev.texture_immutable_format);
# endif
# ifdef GL_TEXTURE_IMMUTABLE_LEVELS
	BOOST_CHECK(x != ev.texture_immutable_levels);
# endif
# ifdef GL_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.texture_lod_bias);
# endif
# ifdef GL_TEXTURE_MAG_FILTER
	BOOST_CHECK(x != ev.texture_mag_filter);
# endif
# ifdef GL_TEXTURE_MAX_LEVEL
	BOOST_CHECK(x != ev.texture_max_level);
# endif
# ifdef GL_TEXTURE_MAX_LOD
	BOOST_CHECK(x != ev.texture_max_lod);
# endif
# ifdef GL_TEXTURE_MIN_FILTER
	BOOST_CHECK(x != ev.texture_min_filter);
# endif
# ifdef GL_TEXTURE_MIN_LOD
	BOOST_CHECK(x != ev.texture_min_lod);
# endif
# ifdef GL_TEXTURE_SWIZZLE_A
	BOOST_CHECK(x != ev.texture_swizzle_a);
# endif
# ifdef GL_TEXTURE_SWIZZLE_B
	BOOST_CHECK(x != ev.texture_swizzle_b);
# endif
# ifdef GL_TEXTURE_SWIZZLE_G
	BOOST_CHECK(x != ev.texture_swizzle_g);
# endif
# ifdef GL_TEXTURE_SWIZZLE_R
	BOOST_CHECK(x != ev.texture_swizzle_r);
# endif
# ifdef GL_TEXTURE_SWIZZLE_RGBA
	BOOST_CHECK(x != ev.texture_swizzle_rgba);
# endif
# ifdef GL_TEXTURE_TARGET
	BOOST_CHECK(x != ev.texture_target);
# endif
# ifdef GL_TEXTURE_VIEW_MIN_LAYER
	BOOST_CHECK(x != ev.texture_view_min_layer);
# endif
# ifdef GL_TEXTURE_VIEW_MIN_LEVEL
	BOOST_CHECK(x != ev.texture_view_min_level);
# endif
# ifdef GL_TEXTURE_VIEW_NUM_LAYERS
	BOOST_CHECK(x != ev.texture_view_num_layers);
# endif
# ifdef GL_TEXTURE_VIEW_NUM_LEVELS
	BOOST_CHECK(x != ev.texture_view_num_levels);
# endif
# ifdef GL_TEXTURE_WRAP_R
	BOOST_CHECK(x != ev.texture_wrap_r);
# endif
# ifdef GL_TEXTURE_WRAP_S
	BOOST_CHECK(x != ev.texture_wrap_s);
# endif
# ifdef GL_TEXTURE_WRAP_T
	BOOST_CHECK(x != ev.texture_wrap_t);
# endif
#endif

#ifdef GL_TEXTURE_COMPARE_MODE
	x = ev.texture_compare_mode;
	BOOST_CHECK(x == ev.texture_compare_mode);
# ifdef GL_TEXTURE_IMMUTABLE_FORMAT
	BOOST_CHECK(x != ev.texture_immutable_format);
# endif
# ifdef GL_TEXTURE_IMMUTABLE_LEVELS
	BOOST_CHECK(x != ev.texture_immutable_levels);
# endif
# ifdef GL_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.texture_lod_bias);
# endif
# ifdef GL_TEXTURE_MAG_FILTER
	BOOST_CHECK(x != ev.texture_mag_filter);
# endif
# ifdef GL_TEXTURE_MAX_LEVEL
	BOOST_CHECK(x != ev.texture_max_level);
# endif
# ifdef GL_TEXTURE_MAX_LOD
	BOOST_CHECK(x != ev.texture_max_lod);
# endif
# ifdef GL_TEXTURE_MIN_FILTER
	BOOST_CHECK(x != ev.texture_min_filter);
# endif
# ifdef GL_TEXTURE_MIN_LOD
	BOOST_CHECK(x != ev.texture_min_lod);
# endif
# ifdef GL_TEXTURE_SWIZZLE_A
	BOOST_CHECK(x != ev.texture_swizzle_a);
# endif
# ifdef GL_TEXTURE_SWIZZLE_B
	BOOST_CHECK(x != ev.texture_swizzle_b);
# endif
# ifdef GL_TEXTURE_SWIZZLE_G
	BOOST_CHECK(x != ev.texture_swizzle_g);
# endif
# ifdef GL_TEXTURE_SWIZZLE_R
	BOOST_CHECK(x != ev.texture_swizzle_r);
# endif
# ifdef GL_TEXTURE_SWIZZLE_RGBA
	BOOST_CHECK(x != ev.texture_swizzle_rgba);
# endif
# ifdef GL_TEXTURE_TARGET
	BOOST_CHECK(x != ev.texture_target);
# endif
# ifdef GL_TEXTURE_VIEW_MIN_LAYER
	BOOST_CHECK(x != ev.texture_view_min_layer);
# endif
# ifdef GL_TEXTURE_VIEW_MIN_LEVEL
	BOOST_CHECK(x != ev.texture_view_min_level);
# endif
# ifdef GL_TEXTURE_VIEW_NUM_LAYERS
	BOOST_CHECK(x != ev.texture_view_num_layers);
# endif
# ifdef GL_TEXTURE_VIEW_NUM_LEVELS
	BOOST_CHECK(x != ev.texture_view_num_levels);
# endif
# ifdef GL_TEXTURE_WRAP_R
	BOOST_CHECK(x != ev.texture_wrap_r);
# endif
# ifdef GL_TEXTURE_WRAP_S
	BOOST_CHECK(x != ev.texture_wrap_s);
# endif
# ifdef GL_TEXTURE_WRAP_T
	BOOST_CHECK(x != ev.texture_wrap_t);
# endif
#endif

#ifdef GL_TEXTURE_IMMUTABLE_FORMAT
	x = ev.texture_immutable_format;
	BOOST_CHECK(x == ev.texture_immutable_format);
# ifdef GL_TEXTURE_IMMUTABLE_LEVELS
	BOOST_CHECK(x != ev.texture_immutable_levels);
# endif
# ifdef GL_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.texture_lod_bias);
# endif
# ifdef GL_TEXTURE_MAG_FILTER
	BOOST_CHECK(x != ev.texture_mag_filter);
# endif
# ifdef GL_TEXTURE_MAX_LEVEL
	BOOST_CHECK(x != ev.texture_max_level);
# endif
# ifdef GL_TEXTURE_MAX_LOD
	BOOST_CHECK(x != ev.texture_max_lod);
# endif
# ifdef GL_TEXTURE_MIN_FILTER
	BOOST_CHECK(x != ev.texture_min_filter);
# endif
# ifdef GL_TEXTURE_MIN_LOD
	BOOST_CHECK(x != ev.texture_min_lod);
# endif
# ifdef GL_TEXTURE_SWIZZLE_A
	BOOST_CHECK(x != ev.texture_swizzle_a);
# endif
# ifdef GL_TEXTURE_SWIZZLE_B
	BOOST_CHECK(x != ev.texture_swizzle_b);
# endif
# ifdef GL_TEXTURE_SWIZZLE_G
	BOOST_CHECK(x != ev.texture_swizzle_g);
# endif
# ifdef GL_TEXTURE_SWIZZLE_R
	BOOST_CHECK(x != ev.texture_swizzle_r);
# endif
# ifdef GL_TEXTURE_SWIZZLE_RGBA
	BOOST_CHECK(x != ev.texture_swizzle_rgba);
# endif
# ifdef GL_TEXTURE_TARGET
	BOOST_CHECK(x != ev.texture_target);
# endif
# ifdef GL_TEXTURE_VIEW_MIN_LAYER
	BOOST_CHECK(x != ev.texture_view_min_layer);
# endif
# ifdef GL_TEXTURE_VIEW_MIN_LEVEL
	BOOST_CHECK(x != ev.texture_view_min_level);
# endif
# ifdef GL_TEXTURE_VIEW_NUM_LAYERS
	BOOST_CHECK(x != ev.texture_view_num_layers);
# endif
# ifdef GL_TEXTURE_VIEW_NUM_LEVELS
	BOOST_CHECK(x != ev.texture_view_num_levels);
# endif
# ifdef GL_TEXTURE_WRAP_R
	BOOST_CHECK(x != ev.texture_wrap_r);
# endif
# ifdef GL_TEXTURE_WRAP_S
	BOOST_CHECK(x != ev.texture_wrap_s);
# endif
# ifdef GL_TEXTURE_WRAP_T
	BOOST_CHECK(x != ev.texture_wrap_t);
# endif
#endif

#ifdef GL_TEXTURE_IMMUTABLE_LEVELS
	x = ev.texture_immutable_levels;
	BOOST_CHECK(x == ev.texture_immutable_levels);
# ifdef GL_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.texture_lod_bias);
# endif
# ifdef GL_TEXTURE_MAG_FILTER
	BOOST_CHECK(x != ev.texture_mag_filter);
# endif
# ifdef GL_TEXTURE_MAX_LEVEL
	BOOST_CHECK(x != ev.texture_max_level);
# endif
# ifdef GL_TEXTURE_MAX_LOD
	BOOST_CHECK(x != ev.texture_max_lod);
# endif
# ifdef GL_TEXTURE_MIN_FILTER
	BOOST_CHECK(x != ev.texture_min_filter);
# endif
# ifdef GL_TEXTURE_MIN_LOD
	BOOST_CHECK(x != ev.texture_min_lod);
# endif
# ifdef GL_TEXTURE_SWIZZLE_A
	BOOST_CHECK(x != ev.texture_swizzle_a);
# endif
# ifdef GL_TEXTURE_SWIZZLE_B
	BOOST_CHECK(x != ev.texture_swizzle_b);
# endif
# ifdef GL_TEXTURE_SWIZZLE_G
	BOOST_CHECK(x != ev.texture_swizzle_g);
# endif
# ifdef GL_TEXTURE_SWIZZLE_R
	BOOST_CHECK(x != ev.texture_swizzle_r);
# endif
# ifdef GL_TEXTURE_SWIZZLE_RGBA
	BOOST_CHECK(x != ev.texture_swizzle_rgba);
# endif
# ifdef GL_TEXTURE_TARGET
	BOOST_CHECK(x != ev.texture_target);
# endif
# ifdef GL_TEXTURE_VIEW_MIN_LAYER
	BOOST_CHECK(x != ev.texture_view_min_layer);
# endif
# ifdef GL_TEXTURE_VIEW_MIN_LEVEL
	BOOST_CHECK(x != ev.texture_view_min_level);
# endif
# ifdef GL_TEXTURE_VIEW_NUM_LAYERS
	BOOST_CHECK(x != ev.texture_view_num_layers);
# endif
# ifdef GL_TEXTURE_VIEW_NUM_LEVELS
	BOOST_CHECK(x != ev.texture_view_num_levels);
# endif
# ifdef GL_TEXTURE_WRAP_R
	BOOST_CHECK(x != ev.texture_wrap_r);
# endif
# ifdef GL_TEXTURE_WRAP_S
	BOOST_CHECK(x != ev.texture_wrap_s);
# endif
# ifdef GL_TEXTURE_WRAP_T
	BOOST_CHECK(x != ev.texture_wrap_t);
# endif
#endif

#ifdef GL_TEXTURE_LOD_BIAS
	x = ev.texture_lod_bias;
	BOOST_CHECK(x == ev.texture_lod_bias);
# ifdef GL_TEXTURE_MAG_FILTER
	BOOST_CHECK(x != ev.texture_mag_filter);
# endif
# ifdef GL_TEXTURE_MAX_LEVEL
	BOOST_CHECK(x != ev.texture_max_level);
# endif
# ifdef GL_TEXTURE_MAX_LOD
	BOOST_CHECK(x != ev.texture_max_lod);
# endif
# ifdef GL_TEXTURE_MIN_FILTER
	BOOST_CHECK(x != ev.texture_min_filter);
# endif
# ifdef GL_TEXTURE_MIN_LOD
	BOOST_CHECK(x != ev.texture_min_lod);
# endif
# ifdef GL_TEXTURE_SWIZZLE_A
	BOOST_CHECK(x != ev.texture_swizzle_a);
# endif
# ifdef GL_TEXTURE_SWIZZLE_B
	BOOST_CHECK(x != ev.texture_swizzle_b);
# endif
# ifdef GL_TEXTURE_SWIZZLE_G
	BOOST_CHECK(x != ev.texture_swizzle_g);
# endif
# ifdef GL_TEXTURE_SWIZZLE_R
	BOOST_CHECK(x != ev.texture_swizzle_r);
# endif
# ifdef GL_TEXTURE_SWIZZLE_RGBA
	BOOST_CHECK(x != ev.texture_swizzle_rgba);
# endif
# ifdef GL_TEXTURE_TARGET
	BOOST_CHECK(x != ev.texture_target);
# endif
# ifdef GL_TEXTURE_VIEW_MIN_LAYER
	BOOST_CHECK(x != ev.texture_view_min_layer);
# endif
# ifdef GL_TEXTURE_VIEW_MIN_LEVEL
	BOOST_CHECK(x != ev.texture_view_min_level);
# endif
# ifdef GL_TEXTURE_VIEW_NUM_LAYERS
	BOOST_CHECK(x != ev.texture_view_num_layers);
# endif
# ifdef GL_TEXTURE_VIEW_NUM_LEVELS
	BOOST_CHECK(x != ev.texture_view_num_levels);
# endif
# ifdef GL_TEXTURE_WRAP_R
	BOOST_CHECK(x != ev.texture_wrap_r);
# endif
# ifdef GL_TEXTURE_WRAP_S
	BOOST_CHECK(x != ev.texture_wrap_s);
# endif
# ifdef GL_TEXTURE_WRAP_T
	BOOST_CHECK(x != ev.texture_wrap_t);
# endif
#endif

#ifdef GL_TEXTURE_MAG_FILTER
	x = ev.texture_mag_filter;
	BOOST_CHECK(x == ev.texture_mag_filter);
# ifdef GL_TEXTURE_MAX_LEVEL
	BOOST_CHECK(x != ev.texture_max_level);
# endif
# ifdef GL_TEXTURE_MAX_LOD
	BOOST_CHECK(x != ev.texture_max_lod);
# endif
# ifdef GL_TEXTURE_MIN_FILTER
	BOOST_CHECK(x != ev.texture_min_filter);
# endif
# ifdef GL_TEXTURE_MIN_LOD
	BOOST_CHECK(x != ev.texture_min_lod);
# endif
# ifdef GL_TEXTURE_SWIZZLE_A
	BOOST_CHECK(x != ev.texture_swizzle_a);
# endif
# ifdef GL_TEXTURE_SWIZZLE_B
	BOOST_CHECK(x != ev.texture_swizzle_b);
# endif
# ifdef GL_TEXTURE_SWIZZLE_G
	BOOST_CHECK(x != ev.texture_swizzle_g);
# endif
# ifdef GL_TEXTURE_SWIZZLE_R
	BOOST_CHECK(x != ev.texture_swizzle_r);
# endif
# ifdef GL_TEXTURE_SWIZZLE_RGBA
	BOOST_CHECK(x != ev.texture_swizzle_rgba);
# endif
# ifdef GL_TEXTURE_TARGET
	BOOST_CHECK(x != ev.texture_target);
# endif
# ifdef GL_TEXTURE_VIEW_MIN_LAYER
	BOOST_CHECK(x != ev.texture_view_min_layer);
# endif
# ifdef GL_TEXTURE_VIEW_MIN_LEVEL
	BOOST_CHECK(x != ev.texture_view_min_level);
# endif
# ifdef GL_TEXTURE_VIEW_NUM_LAYERS
	BOOST_CHECK(x != ev.texture_view_num_layers);
# endif
# ifdef GL_TEXTURE_VIEW_NUM_LEVELS
	BOOST_CHECK(x != ev.texture_view_num_levels);
# endif
# ifdef GL_TEXTURE_WRAP_R
	BOOST_CHECK(x != ev.texture_wrap_r);
# endif
# ifdef GL_TEXTURE_WRAP_S
	BOOST_CHECK(x != ev.texture_wrap_s);
# endif
# ifdef GL_TEXTURE_WRAP_T
	BOOST_CHECK(x != ev.texture_wrap_t);
# endif
#endif

#ifdef GL_TEXTURE_MAX_LEVEL
	x = ev.texture_max_level;
	BOOST_CHECK(x == ev.texture_max_level);
# ifdef GL_TEXTURE_MAX_LOD
	BOOST_CHECK(x != ev.texture_max_lod);
# endif
# ifdef GL_TEXTURE_MIN_FILTER
	BOOST_CHECK(x != ev.texture_min_filter);
# endif
# ifdef GL_TEXTURE_MIN_LOD
	BOOST_CHECK(x != ev.texture_min_lod);
# endif
# ifdef GL_TEXTURE_SWIZZLE_A
	BOOST_CHECK(x != ev.texture_swizzle_a);
# endif
# ifdef GL_TEXTURE_SWIZZLE_B
	BOOST_CHECK(x != ev.texture_swizzle_b);
# endif
# ifdef GL_TEXTURE_SWIZZLE_G
	BOOST_CHECK(x != ev.texture_swizzle_g);
# endif
# ifdef GL_TEXTURE_SWIZZLE_R
	BOOST_CHECK(x != ev.texture_swizzle_r);
# endif
# ifdef GL_TEXTURE_SWIZZLE_RGBA
	BOOST_CHECK(x != ev.texture_swizzle_rgba);
# endif
# ifdef GL_TEXTURE_TARGET
	BOOST_CHECK(x != ev.texture_target);
# endif
# ifdef GL_TEXTURE_VIEW_MIN_LAYER
	BOOST_CHECK(x != ev.texture_view_min_layer);
# endif
# ifdef GL_TEXTURE_VIEW_MIN_LEVEL
	BOOST_CHECK(x != ev.texture_view_min_level);
# endif
# ifdef GL_TEXTURE_VIEW_NUM_LAYERS
	BOOST_CHECK(x != ev.texture_view_num_layers);
# endif
# ifdef GL_TEXTURE_VIEW_NUM_LEVELS
	BOOST_CHECK(x != ev.texture_view_num_levels);
# endif
# ifdef GL_TEXTURE_WRAP_R
	BOOST_CHECK(x != ev.texture_wrap_r);
# endif
# ifdef GL_TEXTURE_WRAP_S
	BOOST_CHECK(x != ev.texture_wrap_s);
# endif
# ifdef GL_TEXTURE_WRAP_T
	BOOST_CHECK(x != ev.texture_wrap_t);
# endif
#endif

#ifdef GL_TEXTURE_MAX_LOD
	x = ev.texture_max_lod;
	BOOST_CHECK(x == ev.texture_max_lod);
# ifdef GL_TEXTURE_MIN_FILTER
	BOOST_CHECK(x != ev.texture_min_filter);
# endif
# ifdef GL_TEXTURE_MIN_LOD
	BOOST_CHECK(x != ev.texture_min_lod);
# endif
# ifdef GL_TEXTURE_SWIZZLE_A
	BOOST_CHECK(x != ev.texture_swizzle_a);
# endif
# ifdef GL_TEXTURE_SWIZZLE_B
	BOOST_CHECK(x != ev.texture_swizzle_b);
# endif
# ifdef GL_TEXTURE_SWIZZLE_G
	BOOST_CHECK(x != ev.texture_swizzle_g);
# endif
# ifdef GL_TEXTURE_SWIZZLE_R
	BOOST_CHECK(x != ev.texture_swizzle_r);
# endif
# ifdef GL_TEXTURE_SWIZZLE_RGBA
	BOOST_CHECK(x != ev.texture_swizzle_rgba);
# endif
# ifdef GL_TEXTURE_TARGET
	BOOST_CHECK(x != ev.texture_target);
# endif
# ifdef GL_TEXTURE_VIEW_MIN_LAYER
	BOOST_CHECK(x != ev.texture_view_min_layer);
# endif
# ifdef GL_TEXTURE_VIEW_MIN_LEVEL
	BOOST_CHECK(x != ev.texture_view_min_level);
# endif
# ifdef GL_TEXTURE_VIEW_NUM_LAYERS
	BOOST_CHECK(x != ev.texture_view_num_layers);
# endif
# ifdef GL_TEXTURE_VIEW_NUM_LEVELS
	BOOST_CHECK(x != ev.texture_view_num_levels);
# endif
# ifdef GL_TEXTURE_WRAP_R
	BOOST_CHECK(x != ev.texture_wrap_r);
# endif
# ifdef GL_TEXTURE_WRAP_S
	BOOST_CHECK(x != ev.texture_wrap_s);
# endif
# ifdef GL_TEXTURE_WRAP_T
	BOOST_CHECK(x != ev.texture_wrap_t);
# endif
#endif

#ifdef GL_TEXTURE_MIN_FILTER
	x = ev.texture_min_filter;
	BOOST_CHECK(x == ev.texture_min_filter);
# ifdef GL_TEXTURE_MIN_LOD
	BOOST_CHECK(x != ev.texture_min_lod);
# endif
# ifdef GL_TEXTURE_SWIZZLE_A
	BOOST_CHECK(x != ev.texture_swizzle_a);
# endif
# ifdef GL_TEXTURE_SWIZZLE_B
	BOOST_CHECK(x != ev.texture_swizzle_b);
# endif
# ifdef GL_TEXTURE_SWIZZLE_G
	BOOST_CHECK(x != ev.texture_swizzle_g);
# endif
# ifdef GL_TEXTURE_SWIZZLE_R
	BOOST_CHECK(x != ev.texture_swizzle_r);
# endif
# ifdef GL_TEXTURE_SWIZZLE_RGBA
	BOOST_CHECK(x != ev.texture_swizzle_rgba);
# endif
# ifdef GL_TEXTURE_TARGET
	BOOST_CHECK(x != ev.texture_target);
# endif
# ifdef GL_TEXTURE_VIEW_MIN_LAYER
	BOOST_CHECK(x != ev.texture_view_min_layer);
# endif
# ifdef GL_TEXTURE_VIEW_MIN_LEVEL
	BOOST_CHECK(x != ev.texture_view_min_level);
# endif
# ifdef GL_TEXTURE_VIEW_NUM_LAYERS
	BOOST_CHECK(x != ev.texture_view_num_layers);
# endif
# ifdef GL_TEXTURE_VIEW_NUM_LEVELS
	BOOST_CHECK(x != ev.texture_view_num_levels);
# endif
# ifdef GL_TEXTURE_WRAP_R
	BOOST_CHECK(x != ev.texture_wrap_r);
# endif
# ifdef GL_TEXTURE_WRAP_S
	BOOST_CHECK(x != ev.texture_wrap_s);
# endif
# ifdef GL_TEXTURE_WRAP_T
	BOOST_CHECK(x != ev.texture_wrap_t);
# endif
#endif

#ifdef GL_TEXTURE_MIN_LOD
	x = ev.texture_min_lod;
	BOOST_CHECK(x == ev.texture_min_lod);
# ifdef GL_TEXTURE_SWIZZLE_A
	BOOST_CHECK(x != ev.texture_swizzle_a);
# endif
# ifdef GL_TEXTURE_SWIZZLE_B
	BOOST_CHECK(x != ev.texture_swizzle_b);
# endif
# ifdef GL_TEXTURE_SWIZZLE_G
	BOOST_CHECK(x != ev.texture_swizzle_g);
# endif
# ifdef GL_TEXTURE_SWIZZLE_R
	BOOST_CHECK(x != ev.texture_swizzle_r);
# endif
# ifdef GL_TEXTURE_SWIZZLE_RGBA
	BOOST_CHECK(x != ev.texture_swizzle_rgba);
# endif
# ifdef GL_TEXTURE_TARGET
	BOOST_CHECK(x != ev.texture_target);
# endif
# ifdef GL_TEXTURE_VIEW_MIN_LAYER
	BOOST_CHECK(x != ev.texture_view_min_layer);
# endif
# ifdef GL_TEXTURE_VIEW_MIN_LEVEL
	BOOST_CHECK(x != ev.texture_view_min_level);
# endif
# ifdef GL_TEXTURE_VIEW_NUM_LAYERS
	BOOST_CHECK(x != ev.texture_view_num_layers);
# endif
# ifdef GL_TEXTURE_VIEW_NUM_LEVELS
	BOOST_CHECK(x != ev.texture_view_num_levels);
# endif
# ifdef GL_TEXTURE_WRAP_R
	BOOST_CHECK(x != ev.texture_wrap_r);
# endif
# ifdef GL_TEXTURE_WRAP_S
	BOOST_CHECK(x != ev.texture_wrap_s);
# endif
# ifdef GL_TEXTURE_WRAP_T
	BOOST_CHECK(x != ev.texture_wrap_t);
# endif
#endif

#ifdef GL_TEXTURE_SWIZZLE_A
	x = ev.texture_swizzle_a;
	BOOST_CHECK(x == ev.texture_swizzle_a);
# ifdef GL_TEXTURE_SWIZZLE_B
	BOOST_CHECK(x != ev.texture_swizzle_b);
# endif
# ifdef GL_TEXTURE_SWIZZLE_G
	BOOST_CHECK(x != ev.texture_swizzle_g);
# endif
# ifdef GL_TEXTURE_SWIZZLE_R
	BOOST_CHECK(x != ev.texture_swizzle_r);
# endif
# ifdef GL_TEXTURE_SWIZZLE_RGBA
	BOOST_CHECK(x != ev.texture_swizzle_rgba);
# endif
# ifdef GL_TEXTURE_TARGET
	BOOST_CHECK(x != ev.texture_target);
# endif
# ifdef GL_TEXTURE_VIEW_MIN_LAYER
	BOOST_CHECK(x != ev.texture_view_min_layer);
# endif
# ifdef GL_TEXTURE_VIEW_MIN_LEVEL
	BOOST_CHECK(x != ev.texture_view_min_level);
# endif
# ifdef GL_TEXTURE_VIEW_NUM_LAYERS
	BOOST_CHECK(x != ev.texture_view_num_layers);
# endif
# ifdef GL_TEXTURE_VIEW_NUM_LEVELS
	BOOST_CHECK(x != ev.texture_view_num_levels);
# endif
# ifdef GL_TEXTURE_WRAP_R
	BOOST_CHECK(x != ev.texture_wrap_r);
# endif
# ifdef GL_TEXTURE_WRAP_S
	BOOST_CHECK(x != ev.texture_wrap_s);
# endif
# ifdef GL_TEXTURE_WRAP_T
	BOOST_CHECK(x != ev.texture_wrap_t);
# endif
#endif

#ifdef GL_TEXTURE_SWIZZLE_B
	x = ev.texture_swizzle_b;
	BOOST_CHECK(x == ev.texture_swizzle_b);
# ifdef GL_TEXTURE_SWIZZLE_G
	BOOST_CHECK(x != ev.texture_swizzle_g);
# endif
# ifdef GL_TEXTURE_SWIZZLE_R
	BOOST_CHECK(x != ev.texture_swizzle_r);
# endif
# ifdef GL_TEXTURE_SWIZZLE_RGBA
	BOOST_CHECK(x != ev.texture_swizzle_rgba);
# endif
# ifdef GL_TEXTURE_TARGET
	BOOST_CHECK(x != ev.texture_target);
# endif
# ifdef GL_TEXTURE_VIEW_MIN_LAYER
	BOOST_CHECK(x != ev.texture_view_min_layer);
# endif
# ifdef GL_TEXTURE_VIEW_MIN_LEVEL
	BOOST_CHECK(x != ev.texture_view_min_level);
# endif
# ifdef GL_TEXTURE_VIEW_NUM_LAYERS
	BOOST_CHECK(x != ev.texture_view_num_layers);
# endif
# ifdef GL_TEXTURE_VIEW_NUM_LEVELS
	BOOST_CHECK(x != ev.texture_view_num_levels);
# endif
# ifdef GL_TEXTURE_WRAP_R
	BOOST_CHECK(x != ev.texture_wrap_r);
# endif
# ifdef GL_TEXTURE_WRAP_S
	BOOST_CHECK(x != ev.texture_wrap_s);
# endif
# ifdef GL_TEXTURE_WRAP_T
	BOOST_CHECK(x != ev.texture_wrap_t);
# endif
#endif

#ifdef GL_TEXTURE_SWIZZLE_G
	x = ev.texture_swizzle_g;
	BOOST_CHECK(x == ev.texture_swizzle_g);
# ifdef GL_TEXTURE_SWIZZLE_R
	BOOST_CHECK(x != ev.texture_swizzle_r);
# endif
# ifdef GL_TEXTURE_SWIZZLE_RGBA
	BOOST_CHECK(x != ev.texture_swizzle_rgba);
# endif
# ifdef GL_TEXTURE_TARGET
	BOOST_CHECK(x != ev.texture_target);
# endif
# ifdef GL_TEXTURE_VIEW_MIN_LAYER
	BOOST_CHECK(x != ev.texture_view_min_layer);
# endif
# ifdef GL_TEXTURE_VIEW_MIN_LEVEL
	BOOST_CHECK(x != ev.texture_view_min_level);
# endif
# ifdef GL_TEXTURE_VIEW_NUM_LAYERS
	BOOST_CHECK(x != ev.texture_view_num_layers);
# endif
# ifdef GL_TEXTURE_VIEW_NUM_LEVELS
	BOOST_CHECK(x != ev.texture_view_num_levels);
# endif
# ifdef GL_TEXTURE_WRAP_R
	BOOST_CHECK(x != ev.texture_wrap_r);
# endif
# ifdef GL_TEXTURE_WRAP_S
	BOOST_CHECK(x != ev.texture_wrap_s);
# endif
# ifdef GL_TEXTURE_WRAP_T
	BOOST_CHECK(x != ev.texture_wrap_t);
# endif
#endif

#ifdef GL_TEXTURE_SWIZZLE_R
	x = ev.texture_swizzle_r;
	BOOST_CHECK(x == ev.texture_swizzle_r);
# ifdef GL_TEXTURE_SWIZZLE_RGBA
	BOOST_CHECK(x != ev.texture_swizzle_rgba);
# endif
# ifdef GL_TEXTURE_TARGET
	BOOST_CHECK(x != ev.texture_target);
# endif
# ifdef GL_TEXTURE_VIEW_MIN_LAYER
	BOOST_CHECK(x != ev.texture_view_min_layer);
# endif
# ifdef GL_TEXTURE_VIEW_MIN_LEVEL
	BOOST_CHECK(x != ev.texture_view_min_level);
# endif
# ifdef GL_TEXTURE_VIEW_NUM_LAYERS
	BOOST_CHECK(x != ev.texture_view_num_layers);
# endif
# ifdef GL_TEXTURE_VIEW_NUM_LEVELS
	BOOST_CHECK(x != ev.texture_view_num_levels);
# endif
# ifdef GL_TEXTURE_WRAP_R
	BOOST_CHECK(x != ev.texture_wrap_r);
# endif
# ifdef GL_TEXTURE_WRAP_S
	BOOST_CHECK(x != ev.texture_wrap_s);
# endif
# ifdef GL_TEXTURE_WRAP_T
	BOOST_CHECK(x != ev.texture_wrap_t);
# endif
#endif

#ifdef GL_TEXTURE_SWIZZLE_RGBA
	x = ev.texture_swizzle_rgba;
	BOOST_CHECK(x == ev.texture_swizzle_rgba);
# ifdef GL_TEXTURE_TARGET
	BOOST_CHECK(x != ev.texture_target);
# endif
# ifdef GL_TEXTURE_VIEW_MIN_LAYER
	BOOST_CHECK(x != ev.texture_view_min_layer);
# endif
# ifdef GL_TEXTURE_VIEW_MIN_LEVEL
	BOOST_CHECK(x != ev.texture_view_min_level);
# endif
# ifdef GL_TEXTURE_VIEW_NUM_LAYERS
	BOOST_CHECK(x != ev.texture_view_num_layers);
# endif
# ifdef GL_TEXTURE_VIEW_NUM_LEVELS
	BOOST_CHECK(x != ev.texture_view_num_levels);
# endif
# ifdef GL_TEXTURE_WRAP_R
	BOOST_CHECK(x != ev.texture_wrap_r);
# endif
# ifdef GL_TEXTURE_WRAP_S
	BOOST_CHECK(x != ev.texture_wrap_s);
# endif
# ifdef GL_TEXTURE_WRAP_T
	BOOST_CHECK(x != ev.texture_wrap_t);
# endif
#endif

#ifdef GL_TEXTURE_TARGET
	x = ev.texture_target;
	BOOST_CHECK(x == ev.texture_target);
# ifdef GL_TEXTURE_VIEW_MIN_LAYER
	BOOST_CHECK(x != ev.texture_view_min_layer);
# endif
# ifdef GL_TEXTURE_VIEW_MIN_LEVEL
	BOOST_CHECK(x != ev.texture_view_min_level);
# endif
# ifdef GL_TEXTURE_VIEW_NUM_LAYERS
	BOOST_CHECK(x != ev.texture_view_num_layers);
# endif
# ifdef GL_TEXTURE_VIEW_NUM_LEVELS
	BOOST_CHECK(x != ev.texture_view_num_levels);
# endif
# ifdef GL_TEXTURE_WRAP_R
	BOOST_CHECK(x != ev.texture_wrap_r);
# endif
# ifdef GL_TEXTURE_WRAP_S
	BOOST_CHECK(x != ev.texture_wrap_s);
# endif
# ifdef GL_TEXTURE_WRAP_T
	BOOST_CHECK(x != ev.texture_wrap_t);
# endif
#endif

#ifdef GL_TEXTURE_VIEW_MIN_LAYER
	x = ev.texture_view_min_layer;
	BOOST_CHECK(x == ev.texture_view_min_layer);
# ifdef GL_TEXTURE_VIEW_MIN_LEVEL
	BOOST_CHECK(x != ev.texture_view_min_level);
# endif
# ifdef GL_TEXTURE_VIEW_NUM_LAYERS
	BOOST_CHECK(x != ev.texture_view_num_layers);
# endif
# ifdef GL_TEXTURE_VIEW_NUM_LEVELS
	BOOST_CHECK(x != ev.texture_view_num_levels);
# endif
# ifdef GL_TEXTURE_WRAP_R
	BOOST_CHECK(x != ev.texture_wrap_r);
# endif
# ifdef GL_TEXTURE_WRAP_S
	BOOST_CHECK(x != ev.texture_wrap_s);
# endif
# ifdef GL_TEXTURE_WRAP_T
	BOOST_CHECK(x != ev.texture_wrap_t);
# endif
#endif

#ifdef GL_TEXTURE_VIEW_MIN_LEVEL
	x = ev.texture_view_min_level;
	BOOST_CHECK(x == ev.texture_view_min_level);
# ifdef GL_TEXTURE_VIEW_NUM_LAYERS
	BOOST_CHECK(x != ev.texture_view_num_layers);
# endif
# ifdef GL_TEXTURE_VIEW_NUM_LEVELS
	BOOST_CHECK(x != ev.texture_view_num_levels);
# endif
# ifdef GL_TEXTURE_WRAP_R
	BOOST_CHECK(x != ev.texture_wrap_r);
# endif
# ifdef GL_TEXTURE_WRAP_S
	BOOST_CHECK(x != ev.texture_wrap_s);
# endif
# ifdef GL_TEXTURE_WRAP_T
	BOOST_CHECK(x != ev.texture_wrap_t);
# endif
#endif

#ifdef GL_TEXTURE_VIEW_NUM_LAYERS
	x = ev.texture_view_num_layers;
	BOOST_CHECK(x == ev.texture_view_num_layers);
# ifdef GL_TEXTURE_VIEW_NUM_LEVELS
	BOOST_CHECK(x != ev.texture_view_num_levels);
# endif
# ifdef GL_TEXTURE_WRAP_R
	BOOST_CHECK(x != ev.texture_wrap_r);
# endif
# ifdef GL_TEXTURE_WRAP_S
	BOOST_CHECK(x != ev.texture_wrap_s);
# endif
# ifdef GL_TEXTURE_WRAP_T
	BOOST_CHECK(x != ev.texture_wrap_t);
# endif
#endif

#ifdef GL_TEXTURE_VIEW_NUM_LEVELS
	x = ev.texture_view_num_levels;
	BOOST_CHECK(x == ev.texture_view_num_levels);
# ifdef GL_TEXTURE_WRAP_R
	BOOST_CHECK(x != ev.texture_wrap_r);
# endif
# ifdef GL_TEXTURE_WRAP_S
	BOOST_CHECK(x != ev.texture_wrap_s);
# endif
# ifdef GL_TEXTURE_WRAP_T
	BOOST_CHECK(x != ev.texture_wrap_t);
# endif
#endif

#ifdef GL_TEXTURE_WRAP_R
	x = ev.texture_wrap_r;
	BOOST_CHECK(x == ev.texture_wrap_r);
# ifdef GL_TEXTURE_WRAP_S
	BOOST_CHECK(x != ev.texture_wrap_s);
# endif
# ifdef GL_TEXTURE_WRAP_T
	BOOST_CHECK(x != ev.texture_wrap_t);
# endif
#endif

#ifdef GL_TEXTURE_WRAP_S
	x = ev.texture_wrap_s;
	BOOST_CHECK(x == ev.texture_wrap_s);
# ifdef GL_TEXTURE_WRAP_T
	BOOST_CHECK(x != ev.texture_wrap_t);
# endif
#endif

#ifdef GL_TEXTURE_WRAP_T
	x = ev.texture_wrap_t;
	BOOST_CHECK(x == ev.texture_wrap_t);
#endif
}

BOOST_AUTO_TEST_CASE(enum_texture_parameter_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	texture_parameter x;
	(void)x;

#ifdef GL_DEPTH_STENCIL_TEXTURE_MODE
	x = ev.depth_stencil_texture_mode;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DEPTH_STENCIL_TEXTURE_MODE"
	) == 0);
#endif

#ifdef GL_IMAGE_FORMAT_COMPATIBILITY_TYPE
	x = ev.image_format_compatibility_type;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"IMAGE_FORMAT_COMPATIBILITY_TYPE"
	) == 0);
#endif

#ifdef GL_TEXTURE_BASE_LEVEL
	x = ev.texture_base_level;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_BASE_LEVEL"
	) == 0);
#endif

#ifdef GL_TEXTURE_BORDER_COLOR
	x = ev.texture_border_color;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_BORDER_COLOR"
	) == 0);
#endif

#ifdef GL_TEXTURE_COMPARE_FUNC
	x = ev.texture_compare_func;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_COMPARE_FUNC"
	) == 0);
#endif

#ifdef GL_TEXTURE_COMPARE_MODE
	x = ev.texture_compare_mode;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_COMPARE_MODE"
	) == 0);
#endif

#ifdef GL_TEXTURE_IMMUTABLE_FORMAT
	x = ev.texture_immutable_format;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_IMMUTABLE_FORMAT"
	) == 0);
#endif

#ifdef GL_TEXTURE_IMMUTABLE_LEVELS
	x = ev.texture_immutable_levels;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_IMMUTABLE_LEVELS"
	) == 0);
#endif

#ifdef GL_TEXTURE_LOD_BIAS
	x = ev.texture_lod_bias;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_LOD_BIAS"
	) == 0);
#endif

#ifdef GL_TEXTURE_MAG_FILTER
	x = ev.texture_mag_filter;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_MAG_FILTER"
	) == 0);
#endif

#ifdef GL_TEXTURE_MAX_LEVEL
	x = ev.texture_max_level;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_MAX_LEVEL"
	) == 0);
#endif

#ifdef GL_TEXTURE_MAX_LOD
	x = ev.texture_max_lod;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_MAX_LOD"
	) == 0);
#endif

#ifdef GL_TEXTURE_MIN_FILTER
	x = ev.texture_min_filter;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_MIN_FILTER"
	) == 0);
#endif

#ifdef GL_TEXTURE_MIN_LOD
	x = ev.texture_min_lod;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_MIN_LOD"
	) == 0);
#endif

#ifdef GL_TEXTURE_SWIZZLE_A
	x = ev.texture_swizzle_a;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_SWIZZLE_A"
	) == 0);
#endif

#ifdef GL_TEXTURE_SWIZZLE_B
	x = ev.texture_swizzle_b;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_SWIZZLE_B"
	) == 0);
#endif

#ifdef GL_TEXTURE_SWIZZLE_G
	x = ev.texture_swizzle_g;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_SWIZZLE_G"
	) == 0);
#endif

#ifdef GL_TEXTURE_SWIZZLE_R
	x = ev.texture_swizzle_r;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_SWIZZLE_R"
	) == 0);
#endif

#ifdef GL_TEXTURE_SWIZZLE_RGBA
	x = ev.texture_swizzle_rgba;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_SWIZZLE_RGBA"
	) == 0);
#endif

#ifdef GL_TEXTURE_TARGET
	x = ev.texture_target;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_TARGET"
	) == 0);
#endif

#ifdef GL_TEXTURE_VIEW_MIN_LAYER
	x = ev.texture_view_min_layer;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_VIEW_MIN_LAYER"
	) == 0);
#endif

#ifdef GL_TEXTURE_VIEW_MIN_LEVEL
	x = ev.texture_view_min_level;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_VIEW_MIN_LEVEL"
	) == 0);
#endif

#ifdef GL_TEXTURE_VIEW_NUM_LAYERS
	x = ev.texture_view_num_layers;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_VIEW_NUM_LAYERS"
	) == 0);
#endif

#ifdef GL_TEXTURE_VIEW_NUM_LEVELS
	x = ev.texture_view_num_levels;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_VIEW_NUM_LEVELS"
	) == 0);
#endif

#ifdef GL_TEXTURE_WRAP_R
	x = ev.texture_wrap_r;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_WRAP_R"
	) == 0);
#endif

#ifdef GL_TEXTURE_WRAP_S
	x = ev.texture_wrap_s;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_WRAP_S"
	) == 0);
#endif

#ifdef GL_TEXTURE_WRAP_T
	x = ev.texture_wrap_t;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_WRAP_T"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_texture_parameter_range)
{
	using namespace oglplus;
	auto count = enum_value_range<texture_parameter>().size();

#ifdef GL_DEPTH_STENCIL_TEXTURE_MODE
{
	--count;
	auto r = enum_value_range<texture_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		texture_parameter(GL_DEPTH_STENCIL_TEXTURE_MODE)
	) != r.end());
}
#endif

#ifdef GL_IMAGE_FORMAT_COMPATIBILITY_TYPE
{
	--count;
	auto r = enum_value_range<texture_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		texture_parameter(GL_IMAGE_FORMAT_COMPATIBILITY_TYPE)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_BASE_LEVEL
{
	--count;
	auto r = enum_value_range<texture_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		texture_parameter(GL_TEXTURE_BASE_LEVEL)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_BORDER_COLOR
{
	--count;
	auto r = enum_value_range<texture_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		texture_parameter(GL_TEXTURE_BORDER_COLOR)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_COMPARE_FUNC
{
	--count;
	auto r = enum_value_range<texture_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		texture_parameter(GL_TEXTURE_COMPARE_FUNC)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_COMPARE_MODE
{
	--count;
	auto r = enum_value_range<texture_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		texture_parameter(GL_TEXTURE_COMPARE_MODE)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_IMMUTABLE_FORMAT
{
	--count;
	auto r = enum_value_range<texture_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		texture_parameter(GL_TEXTURE_IMMUTABLE_FORMAT)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_IMMUTABLE_LEVELS
{
	--count;
	auto r = enum_value_range<texture_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		texture_parameter(GL_TEXTURE_IMMUTABLE_LEVELS)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_LOD_BIAS
{
	--count;
	auto r = enum_value_range<texture_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		texture_parameter(GL_TEXTURE_LOD_BIAS)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_MAG_FILTER
{
	--count;
	auto r = enum_value_range<texture_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		texture_parameter(GL_TEXTURE_MAG_FILTER)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_MAX_LEVEL
{
	--count;
	auto r = enum_value_range<texture_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		texture_parameter(GL_TEXTURE_MAX_LEVEL)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_MAX_LOD
{
	--count;
	auto r = enum_value_range<texture_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		texture_parameter(GL_TEXTURE_MAX_LOD)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_MIN_FILTER
{
	--count;
	auto r = enum_value_range<texture_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		texture_parameter(GL_TEXTURE_MIN_FILTER)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_MIN_LOD
{
	--count;
	auto r = enum_value_range<texture_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		texture_parameter(GL_TEXTURE_MIN_LOD)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_SWIZZLE_A
{
	--count;
	auto r = enum_value_range<texture_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		texture_parameter(GL_TEXTURE_SWIZZLE_A)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_SWIZZLE_B
{
	--count;
	auto r = enum_value_range<texture_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		texture_parameter(GL_TEXTURE_SWIZZLE_B)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_SWIZZLE_G
{
	--count;
	auto r = enum_value_range<texture_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		texture_parameter(GL_TEXTURE_SWIZZLE_G)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_SWIZZLE_R
{
	--count;
	auto r = enum_value_range<texture_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		texture_parameter(GL_TEXTURE_SWIZZLE_R)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_SWIZZLE_RGBA
{
	--count;
	auto r = enum_value_range<texture_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		texture_parameter(GL_TEXTURE_SWIZZLE_RGBA)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_TARGET
{
	--count;
	auto r = enum_value_range<texture_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		texture_parameter(GL_TEXTURE_TARGET)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_VIEW_MIN_LAYER
{
	--count;
	auto r = enum_value_range<texture_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		texture_parameter(GL_TEXTURE_VIEW_MIN_LAYER)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_VIEW_MIN_LEVEL
{
	--count;
	auto r = enum_value_range<texture_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		texture_parameter(GL_TEXTURE_VIEW_MIN_LEVEL)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_VIEW_NUM_LAYERS
{
	--count;
	auto r = enum_value_range<texture_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		texture_parameter(GL_TEXTURE_VIEW_NUM_LAYERS)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_VIEW_NUM_LEVELS
{
	--count;
	auto r = enum_value_range<texture_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		texture_parameter(GL_TEXTURE_VIEW_NUM_LEVELS)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_WRAP_R
{
	--count;
	auto r = enum_value_range<texture_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		texture_parameter(GL_TEXTURE_WRAP_R)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_WRAP_S
{
	--count;
	auto r = enum_value_range<texture_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		texture_parameter(GL_TEXTURE_WRAP_S)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_WRAP_T
{
	--count;
	auto r = enum_value_range<texture_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		texture_parameter(GL_TEXTURE_WRAP_T)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_texture_parameter_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	texture_parameter x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_DEPTH_STENCIL_TEXTURE_MODE
	x = ev.depth_stencil_texture_mode;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.depth_stencil_texture_mode);
#endif

#ifdef GL_IMAGE_FORMAT_COMPATIBILITY_TYPE
	x = ev.image_format_compatibility_type;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.image_format_compatibility_type);
#endif

#ifdef GL_TEXTURE_BASE_LEVEL
	x = ev.texture_base_level;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_base_level);
#endif

#ifdef GL_TEXTURE_BORDER_COLOR
	x = ev.texture_border_color;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_border_color);
#endif

#ifdef GL_TEXTURE_COMPARE_FUNC
	x = ev.texture_compare_func;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_compare_func);
#endif

#ifdef GL_TEXTURE_COMPARE_MODE
	x = ev.texture_compare_mode;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_compare_mode);
#endif

#ifdef GL_TEXTURE_IMMUTABLE_FORMAT
	x = ev.texture_immutable_format;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_immutable_format);
#endif

#ifdef GL_TEXTURE_IMMUTABLE_LEVELS
	x = ev.texture_immutable_levels;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_immutable_levels);
#endif

#ifdef GL_TEXTURE_LOD_BIAS
	x = ev.texture_lod_bias;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_lod_bias);
#endif

#ifdef GL_TEXTURE_MAG_FILTER
	x = ev.texture_mag_filter;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_mag_filter);
#endif

#ifdef GL_TEXTURE_MAX_LEVEL
	x = ev.texture_max_level;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_max_level);
#endif

#ifdef GL_TEXTURE_MAX_LOD
	x = ev.texture_max_lod;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_max_lod);
#endif

#ifdef GL_TEXTURE_MIN_FILTER
	x = ev.texture_min_filter;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_min_filter);
#endif

#ifdef GL_TEXTURE_MIN_LOD
	x = ev.texture_min_lod;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_min_lod);
#endif

#ifdef GL_TEXTURE_SWIZZLE_A
	x = ev.texture_swizzle_a;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_swizzle_a);
#endif

#ifdef GL_TEXTURE_SWIZZLE_B
	x = ev.texture_swizzle_b;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_swizzle_b);
#endif

#ifdef GL_TEXTURE_SWIZZLE_G
	x = ev.texture_swizzle_g;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_swizzle_g);
#endif

#ifdef GL_TEXTURE_SWIZZLE_R
	x = ev.texture_swizzle_r;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_swizzle_r);
#endif

#ifdef GL_TEXTURE_SWIZZLE_RGBA
	x = ev.texture_swizzle_rgba;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_swizzle_rgba);
#endif

#ifdef GL_TEXTURE_TARGET
	x = ev.texture_target;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_target);
#endif

#ifdef GL_TEXTURE_VIEW_MIN_LAYER
	x = ev.texture_view_min_layer;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_view_min_layer);
#endif

#ifdef GL_TEXTURE_VIEW_MIN_LEVEL
	x = ev.texture_view_min_level;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_view_min_level);
#endif

#ifdef GL_TEXTURE_VIEW_NUM_LAYERS
	x = ev.texture_view_num_layers;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_view_num_layers);
#endif

#ifdef GL_TEXTURE_VIEW_NUM_LEVELS
	x = ev.texture_view_num_levels;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_view_num_levels);
#endif

#ifdef GL_TEXTURE_WRAP_R
	x = ev.texture_wrap_r;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_wrap_r);
#endif

#ifdef GL_TEXTURE_WRAP_S
	x = ev.texture_wrap_s;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_wrap_s);
#endif

#ifdef GL_TEXTURE_WRAP_T
	x = ev.texture_wrap_t;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_wrap_t);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
