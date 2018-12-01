//  File test/boost_test/oglplus/enums/pixel_transfer_parameter.cpp
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
#include "common.hpp"
#define BOOST_TEST_MODULE OGLPLUS_pixel_transfer_parameter

#include <cstring>
#include "../../unit_test_begin.inl"

BOOST_AUTO_TEST_SUITE(enum_pixel_transfer_parameter_tests)

BOOST_AUTO_TEST_CASE(enum_pixel_transfer_parameter_values) {
    using namespace oglplus;
    enum_values ev;
    EAGINE_MAYBE_UNUSED(ev);
    pixel_transfer_parameter x;
    EAGINE_MAYBE_UNUSED(x);

#ifdef GL_ALPHA_BIAS
    x = ev.alpha_bias;
    BOOST_CHECK(x == ev.alpha_bias);
#ifdef GL_ALPHA_SCALE
    BOOST_CHECK(x != ev.alpha_scale);
#endif
#ifdef GL_BLUE_BIAS
    BOOST_CHECK(x != ev.blue_bias);
#endif
#ifdef GL_BLUE_SCALE
    BOOST_CHECK(x != ev.blue_scale);
#endif
#ifdef GL_DEPTH_BIAS
    BOOST_CHECK(x != ev.depth_bias);
#endif
#ifdef GL_DEPTH_SCALE
    BOOST_CHECK(x != ev.depth_scale);
#endif
#ifdef GL_GREEN_BIAS
    BOOST_CHECK(x != ev.green_bias);
#endif
#ifdef GL_GREEN_SCALE
    BOOST_CHECK(x != ev.green_scale);
#endif
#ifdef GL_INDEX_OFFSET
    BOOST_CHECK(x != ev.index_offset);
#endif
#ifdef GL_INDEX_SHIFT
    BOOST_CHECK(x != ev.index_shift);
#endif
#ifdef GL_MAP_COLOR
    BOOST_CHECK(x != ev.map_color);
#endif
#ifdef GL_MAP_STENCIL
    BOOST_CHECK(x != ev.map_stencil);
#endif
#ifdef GL_POST_COLOR_MATRIX_ALPHA_BIAS
    BOOST_CHECK(x != ev.post_color_matrix_alpha_bias);
#endif
#ifdef GL_POST_COLOR_MATRIX_ALPHA_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_alpha_scale);
#endif
#ifdef GL_POST_COLOR_MATRIX_BLUE_BIAS
    BOOST_CHECK(x != ev.post_color_matrix_blue_bias);
#endif
#ifdef GL_POST_COLOR_MATRIX_BLUE_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_blue_scale);
#endif
#ifdef GL_POST_COLOR_MATRIX_GREEN_BIAS
    BOOST_CHECK(x != ev.post_color_matrix_green_bias);
#endif
#ifdef GL_POST_COLOR_MATRIX_GREEN_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_green_scale);
#endif
#ifdef GL_POST_COLOR_MATRIX_RED_BIAS
    BOOST_CHECK(x != ev.post_color_matrix_red_bias);
#endif
#ifdef GL_POST_COLOR_MATRIX_RED_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_red_scale);
#endif
#ifdef GL_POST_CONVOLUTION_ALPHA_BIAS
    BOOST_CHECK(x != ev.post_convolution_alpha_bias);
#endif
#ifdef GL_POST_CONVOLUTION_ALPHA_SCALE
    BOOST_CHECK(x != ev.post_convolution_alpha_scale);
#endif
#ifdef GL_POST_CONVOLUTION_BLUE_BIAS
    BOOST_CHECK(x != ev.post_convolution_blue_bias);
#endif
#ifdef GL_POST_CONVOLUTION_BLUE_SCALE
    BOOST_CHECK(x != ev.post_convolution_blue_scale);
#endif
#ifdef GL_POST_CONVOLUTION_GREEN_BIAS
    BOOST_CHECK(x != ev.post_convolution_green_bias);
#endif
#ifdef GL_POST_CONVOLUTION_GREEN_SCALE
    BOOST_CHECK(x != ev.post_convolution_green_scale);
#endif
#ifdef GL_POST_CONVOLUTION_RED_BIAS
    BOOST_CHECK(x != ev.post_convolution_red_bias);
#endif
#ifdef GL_POST_CONVOLUTION_RED_SCALE
    BOOST_CHECK(x != ev.post_convolution_red_scale);
#endif
#ifdef GL_RED_BIAS
    BOOST_CHECK(x != ev.red_bias);
#endif
#ifdef GL_RED_SCALE
    BOOST_CHECK(x != ev.red_scale);
#endif
#endif

#ifdef GL_ALPHA_SCALE
    x = ev.alpha_scale;
    BOOST_CHECK(x == ev.alpha_scale);
#ifdef GL_BLUE_BIAS
    BOOST_CHECK(x != ev.blue_bias);
#endif
#ifdef GL_BLUE_SCALE
    BOOST_CHECK(x != ev.blue_scale);
#endif
#ifdef GL_DEPTH_BIAS
    BOOST_CHECK(x != ev.depth_bias);
#endif
#ifdef GL_DEPTH_SCALE
    BOOST_CHECK(x != ev.depth_scale);
#endif
#ifdef GL_GREEN_BIAS
    BOOST_CHECK(x != ev.green_bias);
#endif
#ifdef GL_GREEN_SCALE
    BOOST_CHECK(x != ev.green_scale);
#endif
#ifdef GL_INDEX_OFFSET
    BOOST_CHECK(x != ev.index_offset);
#endif
#ifdef GL_INDEX_SHIFT
    BOOST_CHECK(x != ev.index_shift);
#endif
#ifdef GL_MAP_COLOR
    BOOST_CHECK(x != ev.map_color);
#endif
#ifdef GL_MAP_STENCIL
    BOOST_CHECK(x != ev.map_stencil);
#endif
#ifdef GL_POST_COLOR_MATRIX_ALPHA_BIAS
    BOOST_CHECK(x != ev.post_color_matrix_alpha_bias);
#endif
#ifdef GL_POST_COLOR_MATRIX_ALPHA_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_alpha_scale);
#endif
#ifdef GL_POST_COLOR_MATRIX_BLUE_BIAS
    BOOST_CHECK(x != ev.post_color_matrix_blue_bias);
#endif
#ifdef GL_POST_COLOR_MATRIX_BLUE_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_blue_scale);
#endif
#ifdef GL_POST_COLOR_MATRIX_GREEN_BIAS
    BOOST_CHECK(x != ev.post_color_matrix_green_bias);
#endif
#ifdef GL_POST_COLOR_MATRIX_GREEN_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_green_scale);
#endif
#ifdef GL_POST_COLOR_MATRIX_RED_BIAS
    BOOST_CHECK(x != ev.post_color_matrix_red_bias);
#endif
#ifdef GL_POST_COLOR_MATRIX_RED_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_red_scale);
#endif
#ifdef GL_POST_CONVOLUTION_ALPHA_BIAS
    BOOST_CHECK(x != ev.post_convolution_alpha_bias);
#endif
#ifdef GL_POST_CONVOLUTION_ALPHA_SCALE
    BOOST_CHECK(x != ev.post_convolution_alpha_scale);
#endif
#ifdef GL_POST_CONVOLUTION_BLUE_BIAS
    BOOST_CHECK(x != ev.post_convolution_blue_bias);
#endif
#ifdef GL_POST_CONVOLUTION_BLUE_SCALE
    BOOST_CHECK(x != ev.post_convolution_blue_scale);
#endif
#ifdef GL_POST_CONVOLUTION_GREEN_BIAS
    BOOST_CHECK(x != ev.post_convolution_green_bias);
#endif
#ifdef GL_POST_CONVOLUTION_GREEN_SCALE
    BOOST_CHECK(x != ev.post_convolution_green_scale);
#endif
#ifdef GL_POST_CONVOLUTION_RED_BIAS
    BOOST_CHECK(x != ev.post_convolution_red_bias);
#endif
#ifdef GL_POST_CONVOLUTION_RED_SCALE
    BOOST_CHECK(x != ev.post_convolution_red_scale);
#endif
#ifdef GL_RED_BIAS
    BOOST_CHECK(x != ev.red_bias);
#endif
#ifdef GL_RED_SCALE
    BOOST_CHECK(x != ev.red_scale);
#endif
#endif

#ifdef GL_BLUE_BIAS
    x = ev.blue_bias;
    BOOST_CHECK(x == ev.blue_bias);
#ifdef GL_BLUE_SCALE
    BOOST_CHECK(x != ev.blue_scale);
#endif
#ifdef GL_DEPTH_BIAS
    BOOST_CHECK(x != ev.depth_bias);
#endif
#ifdef GL_DEPTH_SCALE
    BOOST_CHECK(x != ev.depth_scale);
#endif
#ifdef GL_GREEN_BIAS
    BOOST_CHECK(x != ev.green_bias);
#endif
#ifdef GL_GREEN_SCALE
    BOOST_CHECK(x != ev.green_scale);
#endif
#ifdef GL_INDEX_OFFSET
    BOOST_CHECK(x != ev.index_offset);
#endif
#ifdef GL_INDEX_SHIFT
    BOOST_CHECK(x != ev.index_shift);
#endif
#ifdef GL_MAP_COLOR
    BOOST_CHECK(x != ev.map_color);
#endif
#ifdef GL_MAP_STENCIL
    BOOST_CHECK(x != ev.map_stencil);
#endif
#ifdef GL_POST_COLOR_MATRIX_ALPHA_BIAS
    BOOST_CHECK(x != ev.post_color_matrix_alpha_bias);
#endif
#ifdef GL_POST_COLOR_MATRIX_ALPHA_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_alpha_scale);
#endif
#ifdef GL_POST_COLOR_MATRIX_BLUE_BIAS
    BOOST_CHECK(x != ev.post_color_matrix_blue_bias);
#endif
#ifdef GL_POST_COLOR_MATRIX_BLUE_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_blue_scale);
#endif
#ifdef GL_POST_COLOR_MATRIX_GREEN_BIAS
    BOOST_CHECK(x != ev.post_color_matrix_green_bias);
#endif
#ifdef GL_POST_COLOR_MATRIX_GREEN_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_green_scale);
#endif
#ifdef GL_POST_COLOR_MATRIX_RED_BIAS
    BOOST_CHECK(x != ev.post_color_matrix_red_bias);
#endif
#ifdef GL_POST_COLOR_MATRIX_RED_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_red_scale);
#endif
#ifdef GL_POST_CONVOLUTION_ALPHA_BIAS
    BOOST_CHECK(x != ev.post_convolution_alpha_bias);
#endif
#ifdef GL_POST_CONVOLUTION_ALPHA_SCALE
    BOOST_CHECK(x != ev.post_convolution_alpha_scale);
#endif
#ifdef GL_POST_CONVOLUTION_BLUE_BIAS
    BOOST_CHECK(x != ev.post_convolution_blue_bias);
#endif
#ifdef GL_POST_CONVOLUTION_BLUE_SCALE
    BOOST_CHECK(x != ev.post_convolution_blue_scale);
#endif
#ifdef GL_POST_CONVOLUTION_GREEN_BIAS
    BOOST_CHECK(x != ev.post_convolution_green_bias);
#endif
#ifdef GL_POST_CONVOLUTION_GREEN_SCALE
    BOOST_CHECK(x != ev.post_convolution_green_scale);
#endif
#ifdef GL_POST_CONVOLUTION_RED_BIAS
    BOOST_CHECK(x != ev.post_convolution_red_bias);
#endif
#ifdef GL_POST_CONVOLUTION_RED_SCALE
    BOOST_CHECK(x != ev.post_convolution_red_scale);
#endif
#ifdef GL_RED_BIAS
    BOOST_CHECK(x != ev.red_bias);
#endif
#ifdef GL_RED_SCALE
    BOOST_CHECK(x != ev.red_scale);
#endif
#endif

#ifdef GL_BLUE_SCALE
    x = ev.blue_scale;
    BOOST_CHECK(x == ev.blue_scale);
#ifdef GL_DEPTH_BIAS
    BOOST_CHECK(x != ev.depth_bias);
#endif
#ifdef GL_DEPTH_SCALE
    BOOST_CHECK(x != ev.depth_scale);
#endif
#ifdef GL_GREEN_BIAS
    BOOST_CHECK(x != ev.green_bias);
#endif
#ifdef GL_GREEN_SCALE
    BOOST_CHECK(x != ev.green_scale);
#endif
#ifdef GL_INDEX_OFFSET
    BOOST_CHECK(x != ev.index_offset);
#endif
#ifdef GL_INDEX_SHIFT
    BOOST_CHECK(x != ev.index_shift);
#endif
#ifdef GL_MAP_COLOR
    BOOST_CHECK(x != ev.map_color);
#endif
#ifdef GL_MAP_STENCIL
    BOOST_CHECK(x != ev.map_stencil);
#endif
#ifdef GL_POST_COLOR_MATRIX_ALPHA_BIAS
    BOOST_CHECK(x != ev.post_color_matrix_alpha_bias);
#endif
#ifdef GL_POST_COLOR_MATRIX_ALPHA_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_alpha_scale);
#endif
#ifdef GL_POST_COLOR_MATRIX_BLUE_BIAS
    BOOST_CHECK(x != ev.post_color_matrix_blue_bias);
#endif
#ifdef GL_POST_COLOR_MATRIX_BLUE_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_blue_scale);
#endif
#ifdef GL_POST_COLOR_MATRIX_GREEN_BIAS
    BOOST_CHECK(x != ev.post_color_matrix_green_bias);
#endif
#ifdef GL_POST_COLOR_MATRIX_GREEN_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_green_scale);
#endif
#ifdef GL_POST_COLOR_MATRIX_RED_BIAS
    BOOST_CHECK(x != ev.post_color_matrix_red_bias);
#endif
#ifdef GL_POST_COLOR_MATRIX_RED_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_red_scale);
#endif
#ifdef GL_POST_CONVOLUTION_ALPHA_BIAS
    BOOST_CHECK(x != ev.post_convolution_alpha_bias);
#endif
#ifdef GL_POST_CONVOLUTION_ALPHA_SCALE
    BOOST_CHECK(x != ev.post_convolution_alpha_scale);
#endif
#ifdef GL_POST_CONVOLUTION_BLUE_BIAS
    BOOST_CHECK(x != ev.post_convolution_blue_bias);
#endif
#ifdef GL_POST_CONVOLUTION_BLUE_SCALE
    BOOST_CHECK(x != ev.post_convolution_blue_scale);
#endif
#ifdef GL_POST_CONVOLUTION_GREEN_BIAS
    BOOST_CHECK(x != ev.post_convolution_green_bias);
#endif
#ifdef GL_POST_CONVOLUTION_GREEN_SCALE
    BOOST_CHECK(x != ev.post_convolution_green_scale);
#endif
#ifdef GL_POST_CONVOLUTION_RED_BIAS
    BOOST_CHECK(x != ev.post_convolution_red_bias);
#endif
#ifdef GL_POST_CONVOLUTION_RED_SCALE
    BOOST_CHECK(x != ev.post_convolution_red_scale);
#endif
#ifdef GL_RED_BIAS
    BOOST_CHECK(x != ev.red_bias);
#endif
#ifdef GL_RED_SCALE
    BOOST_CHECK(x != ev.red_scale);
#endif
#endif

#ifdef GL_DEPTH_BIAS
    x = ev.depth_bias;
    BOOST_CHECK(x == ev.depth_bias);
#ifdef GL_DEPTH_SCALE
    BOOST_CHECK(x != ev.depth_scale);
#endif
#ifdef GL_GREEN_BIAS
    BOOST_CHECK(x != ev.green_bias);
#endif
#ifdef GL_GREEN_SCALE
    BOOST_CHECK(x != ev.green_scale);
#endif
#ifdef GL_INDEX_OFFSET
    BOOST_CHECK(x != ev.index_offset);
#endif
#ifdef GL_INDEX_SHIFT
    BOOST_CHECK(x != ev.index_shift);
#endif
#ifdef GL_MAP_COLOR
    BOOST_CHECK(x != ev.map_color);
#endif
#ifdef GL_MAP_STENCIL
    BOOST_CHECK(x != ev.map_stencil);
#endif
#ifdef GL_POST_COLOR_MATRIX_ALPHA_BIAS
    BOOST_CHECK(x != ev.post_color_matrix_alpha_bias);
#endif
#ifdef GL_POST_COLOR_MATRIX_ALPHA_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_alpha_scale);
#endif
#ifdef GL_POST_COLOR_MATRIX_BLUE_BIAS
    BOOST_CHECK(x != ev.post_color_matrix_blue_bias);
#endif
#ifdef GL_POST_COLOR_MATRIX_BLUE_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_blue_scale);
#endif
#ifdef GL_POST_COLOR_MATRIX_GREEN_BIAS
    BOOST_CHECK(x != ev.post_color_matrix_green_bias);
#endif
#ifdef GL_POST_COLOR_MATRIX_GREEN_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_green_scale);
#endif
#ifdef GL_POST_COLOR_MATRIX_RED_BIAS
    BOOST_CHECK(x != ev.post_color_matrix_red_bias);
#endif
#ifdef GL_POST_COLOR_MATRIX_RED_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_red_scale);
#endif
#ifdef GL_POST_CONVOLUTION_ALPHA_BIAS
    BOOST_CHECK(x != ev.post_convolution_alpha_bias);
#endif
#ifdef GL_POST_CONVOLUTION_ALPHA_SCALE
    BOOST_CHECK(x != ev.post_convolution_alpha_scale);
#endif
#ifdef GL_POST_CONVOLUTION_BLUE_BIAS
    BOOST_CHECK(x != ev.post_convolution_blue_bias);
#endif
#ifdef GL_POST_CONVOLUTION_BLUE_SCALE
    BOOST_CHECK(x != ev.post_convolution_blue_scale);
#endif
#ifdef GL_POST_CONVOLUTION_GREEN_BIAS
    BOOST_CHECK(x != ev.post_convolution_green_bias);
#endif
#ifdef GL_POST_CONVOLUTION_GREEN_SCALE
    BOOST_CHECK(x != ev.post_convolution_green_scale);
#endif
#ifdef GL_POST_CONVOLUTION_RED_BIAS
    BOOST_CHECK(x != ev.post_convolution_red_bias);
#endif
#ifdef GL_POST_CONVOLUTION_RED_SCALE
    BOOST_CHECK(x != ev.post_convolution_red_scale);
#endif
#ifdef GL_RED_BIAS
    BOOST_CHECK(x != ev.red_bias);
#endif
#ifdef GL_RED_SCALE
    BOOST_CHECK(x != ev.red_scale);
#endif
#endif

#ifdef GL_DEPTH_SCALE
    x = ev.depth_scale;
    BOOST_CHECK(x == ev.depth_scale);
#ifdef GL_GREEN_BIAS
    BOOST_CHECK(x != ev.green_bias);
#endif
#ifdef GL_GREEN_SCALE
    BOOST_CHECK(x != ev.green_scale);
#endif
#ifdef GL_INDEX_OFFSET
    BOOST_CHECK(x != ev.index_offset);
#endif
#ifdef GL_INDEX_SHIFT
    BOOST_CHECK(x != ev.index_shift);
#endif
#ifdef GL_MAP_COLOR
    BOOST_CHECK(x != ev.map_color);
#endif
#ifdef GL_MAP_STENCIL
    BOOST_CHECK(x != ev.map_stencil);
#endif
#ifdef GL_POST_COLOR_MATRIX_ALPHA_BIAS
    BOOST_CHECK(x != ev.post_color_matrix_alpha_bias);
#endif
#ifdef GL_POST_COLOR_MATRIX_ALPHA_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_alpha_scale);
#endif
#ifdef GL_POST_COLOR_MATRIX_BLUE_BIAS
    BOOST_CHECK(x != ev.post_color_matrix_blue_bias);
#endif
#ifdef GL_POST_COLOR_MATRIX_BLUE_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_blue_scale);
#endif
#ifdef GL_POST_COLOR_MATRIX_GREEN_BIAS
    BOOST_CHECK(x != ev.post_color_matrix_green_bias);
#endif
#ifdef GL_POST_COLOR_MATRIX_GREEN_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_green_scale);
#endif
#ifdef GL_POST_COLOR_MATRIX_RED_BIAS
    BOOST_CHECK(x != ev.post_color_matrix_red_bias);
#endif
#ifdef GL_POST_COLOR_MATRIX_RED_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_red_scale);
#endif
#ifdef GL_POST_CONVOLUTION_ALPHA_BIAS
    BOOST_CHECK(x != ev.post_convolution_alpha_bias);
#endif
#ifdef GL_POST_CONVOLUTION_ALPHA_SCALE
    BOOST_CHECK(x != ev.post_convolution_alpha_scale);
#endif
#ifdef GL_POST_CONVOLUTION_BLUE_BIAS
    BOOST_CHECK(x != ev.post_convolution_blue_bias);
#endif
#ifdef GL_POST_CONVOLUTION_BLUE_SCALE
    BOOST_CHECK(x != ev.post_convolution_blue_scale);
#endif
#ifdef GL_POST_CONVOLUTION_GREEN_BIAS
    BOOST_CHECK(x != ev.post_convolution_green_bias);
#endif
#ifdef GL_POST_CONVOLUTION_GREEN_SCALE
    BOOST_CHECK(x != ev.post_convolution_green_scale);
#endif
#ifdef GL_POST_CONVOLUTION_RED_BIAS
    BOOST_CHECK(x != ev.post_convolution_red_bias);
#endif
#ifdef GL_POST_CONVOLUTION_RED_SCALE
    BOOST_CHECK(x != ev.post_convolution_red_scale);
#endif
#ifdef GL_RED_BIAS
    BOOST_CHECK(x != ev.red_bias);
#endif
#ifdef GL_RED_SCALE
    BOOST_CHECK(x != ev.red_scale);
#endif
#endif

#ifdef GL_GREEN_BIAS
    x = ev.green_bias;
    BOOST_CHECK(x == ev.green_bias);
#ifdef GL_GREEN_SCALE
    BOOST_CHECK(x != ev.green_scale);
#endif
#ifdef GL_INDEX_OFFSET
    BOOST_CHECK(x != ev.index_offset);
#endif
#ifdef GL_INDEX_SHIFT
    BOOST_CHECK(x != ev.index_shift);
#endif
#ifdef GL_MAP_COLOR
    BOOST_CHECK(x != ev.map_color);
#endif
#ifdef GL_MAP_STENCIL
    BOOST_CHECK(x != ev.map_stencil);
#endif
#ifdef GL_POST_COLOR_MATRIX_ALPHA_BIAS
    BOOST_CHECK(x != ev.post_color_matrix_alpha_bias);
#endif
#ifdef GL_POST_COLOR_MATRIX_ALPHA_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_alpha_scale);
#endif
#ifdef GL_POST_COLOR_MATRIX_BLUE_BIAS
    BOOST_CHECK(x != ev.post_color_matrix_blue_bias);
#endif
#ifdef GL_POST_COLOR_MATRIX_BLUE_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_blue_scale);
#endif
#ifdef GL_POST_COLOR_MATRIX_GREEN_BIAS
    BOOST_CHECK(x != ev.post_color_matrix_green_bias);
#endif
#ifdef GL_POST_COLOR_MATRIX_GREEN_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_green_scale);
#endif
#ifdef GL_POST_COLOR_MATRIX_RED_BIAS
    BOOST_CHECK(x != ev.post_color_matrix_red_bias);
#endif
#ifdef GL_POST_COLOR_MATRIX_RED_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_red_scale);
#endif
#ifdef GL_POST_CONVOLUTION_ALPHA_BIAS
    BOOST_CHECK(x != ev.post_convolution_alpha_bias);
#endif
#ifdef GL_POST_CONVOLUTION_ALPHA_SCALE
    BOOST_CHECK(x != ev.post_convolution_alpha_scale);
#endif
#ifdef GL_POST_CONVOLUTION_BLUE_BIAS
    BOOST_CHECK(x != ev.post_convolution_blue_bias);
#endif
#ifdef GL_POST_CONVOLUTION_BLUE_SCALE
    BOOST_CHECK(x != ev.post_convolution_blue_scale);
#endif
#ifdef GL_POST_CONVOLUTION_GREEN_BIAS
    BOOST_CHECK(x != ev.post_convolution_green_bias);
#endif
#ifdef GL_POST_CONVOLUTION_GREEN_SCALE
    BOOST_CHECK(x != ev.post_convolution_green_scale);
#endif
#ifdef GL_POST_CONVOLUTION_RED_BIAS
    BOOST_CHECK(x != ev.post_convolution_red_bias);
#endif
#ifdef GL_POST_CONVOLUTION_RED_SCALE
    BOOST_CHECK(x != ev.post_convolution_red_scale);
#endif
#ifdef GL_RED_BIAS
    BOOST_CHECK(x != ev.red_bias);
#endif
#ifdef GL_RED_SCALE
    BOOST_CHECK(x != ev.red_scale);
#endif
#endif

#ifdef GL_GREEN_SCALE
    x = ev.green_scale;
    BOOST_CHECK(x == ev.green_scale);
#ifdef GL_INDEX_OFFSET
    BOOST_CHECK(x != ev.index_offset);
#endif
#ifdef GL_INDEX_SHIFT
    BOOST_CHECK(x != ev.index_shift);
#endif
#ifdef GL_MAP_COLOR
    BOOST_CHECK(x != ev.map_color);
#endif
#ifdef GL_MAP_STENCIL
    BOOST_CHECK(x != ev.map_stencil);
#endif
#ifdef GL_POST_COLOR_MATRIX_ALPHA_BIAS
    BOOST_CHECK(x != ev.post_color_matrix_alpha_bias);
#endif
#ifdef GL_POST_COLOR_MATRIX_ALPHA_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_alpha_scale);
#endif
#ifdef GL_POST_COLOR_MATRIX_BLUE_BIAS
    BOOST_CHECK(x != ev.post_color_matrix_blue_bias);
#endif
#ifdef GL_POST_COLOR_MATRIX_BLUE_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_blue_scale);
#endif
#ifdef GL_POST_COLOR_MATRIX_GREEN_BIAS
    BOOST_CHECK(x != ev.post_color_matrix_green_bias);
#endif
#ifdef GL_POST_COLOR_MATRIX_GREEN_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_green_scale);
#endif
#ifdef GL_POST_COLOR_MATRIX_RED_BIAS
    BOOST_CHECK(x != ev.post_color_matrix_red_bias);
#endif
#ifdef GL_POST_COLOR_MATRIX_RED_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_red_scale);
#endif
#ifdef GL_POST_CONVOLUTION_ALPHA_BIAS
    BOOST_CHECK(x != ev.post_convolution_alpha_bias);
#endif
#ifdef GL_POST_CONVOLUTION_ALPHA_SCALE
    BOOST_CHECK(x != ev.post_convolution_alpha_scale);
#endif
#ifdef GL_POST_CONVOLUTION_BLUE_BIAS
    BOOST_CHECK(x != ev.post_convolution_blue_bias);
#endif
#ifdef GL_POST_CONVOLUTION_BLUE_SCALE
    BOOST_CHECK(x != ev.post_convolution_blue_scale);
#endif
#ifdef GL_POST_CONVOLUTION_GREEN_BIAS
    BOOST_CHECK(x != ev.post_convolution_green_bias);
#endif
#ifdef GL_POST_CONVOLUTION_GREEN_SCALE
    BOOST_CHECK(x != ev.post_convolution_green_scale);
#endif
#ifdef GL_POST_CONVOLUTION_RED_BIAS
    BOOST_CHECK(x != ev.post_convolution_red_bias);
#endif
#ifdef GL_POST_CONVOLUTION_RED_SCALE
    BOOST_CHECK(x != ev.post_convolution_red_scale);
#endif
#ifdef GL_RED_BIAS
    BOOST_CHECK(x != ev.red_bias);
#endif
#ifdef GL_RED_SCALE
    BOOST_CHECK(x != ev.red_scale);
#endif
#endif

#ifdef GL_INDEX_OFFSET
    x = ev.index_offset;
    BOOST_CHECK(x == ev.index_offset);
#ifdef GL_INDEX_SHIFT
    BOOST_CHECK(x != ev.index_shift);
#endif
#ifdef GL_MAP_COLOR
    BOOST_CHECK(x != ev.map_color);
#endif
#ifdef GL_MAP_STENCIL
    BOOST_CHECK(x != ev.map_stencil);
#endif
#ifdef GL_POST_COLOR_MATRIX_ALPHA_BIAS
    BOOST_CHECK(x != ev.post_color_matrix_alpha_bias);
#endif
#ifdef GL_POST_COLOR_MATRIX_ALPHA_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_alpha_scale);
#endif
#ifdef GL_POST_COLOR_MATRIX_BLUE_BIAS
    BOOST_CHECK(x != ev.post_color_matrix_blue_bias);
#endif
#ifdef GL_POST_COLOR_MATRIX_BLUE_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_blue_scale);
#endif
#ifdef GL_POST_COLOR_MATRIX_GREEN_BIAS
    BOOST_CHECK(x != ev.post_color_matrix_green_bias);
#endif
#ifdef GL_POST_COLOR_MATRIX_GREEN_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_green_scale);
#endif
#ifdef GL_POST_COLOR_MATRIX_RED_BIAS
    BOOST_CHECK(x != ev.post_color_matrix_red_bias);
#endif
#ifdef GL_POST_COLOR_MATRIX_RED_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_red_scale);
#endif
#ifdef GL_POST_CONVOLUTION_ALPHA_BIAS
    BOOST_CHECK(x != ev.post_convolution_alpha_bias);
#endif
#ifdef GL_POST_CONVOLUTION_ALPHA_SCALE
    BOOST_CHECK(x != ev.post_convolution_alpha_scale);
#endif
#ifdef GL_POST_CONVOLUTION_BLUE_BIAS
    BOOST_CHECK(x != ev.post_convolution_blue_bias);
#endif
#ifdef GL_POST_CONVOLUTION_BLUE_SCALE
    BOOST_CHECK(x != ev.post_convolution_blue_scale);
#endif
#ifdef GL_POST_CONVOLUTION_GREEN_BIAS
    BOOST_CHECK(x != ev.post_convolution_green_bias);
#endif
#ifdef GL_POST_CONVOLUTION_GREEN_SCALE
    BOOST_CHECK(x != ev.post_convolution_green_scale);
#endif
#ifdef GL_POST_CONVOLUTION_RED_BIAS
    BOOST_CHECK(x != ev.post_convolution_red_bias);
#endif
#ifdef GL_POST_CONVOLUTION_RED_SCALE
    BOOST_CHECK(x != ev.post_convolution_red_scale);
#endif
#ifdef GL_RED_BIAS
    BOOST_CHECK(x != ev.red_bias);
#endif
#ifdef GL_RED_SCALE
    BOOST_CHECK(x != ev.red_scale);
#endif
#endif

#ifdef GL_INDEX_SHIFT
    x = ev.index_shift;
    BOOST_CHECK(x == ev.index_shift);
#ifdef GL_MAP_COLOR
    BOOST_CHECK(x != ev.map_color);
#endif
#ifdef GL_MAP_STENCIL
    BOOST_CHECK(x != ev.map_stencil);
#endif
#ifdef GL_POST_COLOR_MATRIX_ALPHA_BIAS
    BOOST_CHECK(x != ev.post_color_matrix_alpha_bias);
#endif
#ifdef GL_POST_COLOR_MATRIX_ALPHA_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_alpha_scale);
#endif
#ifdef GL_POST_COLOR_MATRIX_BLUE_BIAS
    BOOST_CHECK(x != ev.post_color_matrix_blue_bias);
#endif
#ifdef GL_POST_COLOR_MATRIX_BLUE_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_blue_scale);
#endif
#ifdef GL_POST_COLOR_MATRIX_GREEN_BIAS
    BOOST_CHECK(x != ev.post_color_matrix_green_bias);
#endif
#ifdef GL_POST_COLOR_MATRIX_GREEN_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_green_scale);
#endif
#ifdef GL_POST_COLOR_MATRIX_RED_BIAS
    BOOST_CHECK(x != ev.post_color_matrix_red_bias);
#endif
#ifdef GL_POST_COLOR_MATRIX_RED_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_red_scale);
#endif
#ifdef GL_POST_CONVOLUTION_ALPHA_BIAS
    BOOST_CHECK(x != ev.post_convolution_alpha_bias);
#endif
#ifdef GL_POST_CONVOLUTION_ALPHA_SCALE
    BOOST_CHECK(x != ev.post_convolution_alpha_scale);
#endif
#ifdef GL_POST_CONVOLUTION_BLUE_BIAS
    BOOST_CHECK(x != ev.post_convolution_blue_bias);
#endif
#ifdef GL_POST_CONVOLUTION_BLUE_SCALE
    BOOST_CHECK(x != ev.post_convolution_blue_scale);
#endif
#ifdef GL_POST_CONVOLUTION_GREEN_BIAS
    BOOST_CHECK(x != ev.post_convolution_green_bias);
#endif
#ifdef GL_POST_CONVOLUTION_GREEN_SCALE
    BOOST_CHECK(x != ev.post_convolution_green_scale);
#endif
#ifdef GL_POST_CONVOLUTION_RED_BIAS
    BOOST_CHECK(x != ev.post_convolution_red_bias);
#endif
#ifdef GL_POST_CONVOLUTION_RED_SCALE
    BOOST_CHECK(x != ev.post_convolution_red_scale);
#endif
#ifdef GL_RED_BIAS
    BOOST_CHECK(x != ev.red_bias);
#endif
#ifdef GL_RED_SCALE
    BOOST_CHECK(x != ev.red_scale);
#endif
#endif

#ifdef GL_MAP_COLOR
    x = ev.map_color;
    BOOST_CHECK(x == ev.map_color);
#ifdef GL_MAP_STENCIL
    BOOST_CHECK(x != ev.map_stencil);
#endif
#ifdef GL_POST_COLOR_MATRIX_ALPHA_BIAS
    BOOST_CHECK(x != ev.post_color_matrix_alpha_bias);
#endif
#ifdef GL_POST_COLOR_MATRIX_ALPHA_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_alpha_scale);
#endif
#ifdef GL_POST_COLOR_MATRIX_BLUE_BIAS
    BOOST_CHECK(x != ev.post_color_matrix_blue_bias);
#endif
#ifdef GL_POST_COLOR_MATRIX_BLUE_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_blue_scale);
#endif
#ifdef GL_POST_COLOR_MATRIX_GREEN_BIAS
    BOOST_CHECK(x != ev.post_color_matrix_green_bias);
#endif
#ifdef GL_POST_COLOR_MATRIX_GREEN_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_green_scale);
#endif
#ifdef GL_POST_COLOR_MATRIX_RED_BIAS
    BOOST_CHECK(x != ev.post_color_matrix_red_bias);
#endif
#ifdef GL_POST_COLOR_MATRIX_RED_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_red_scale);
#endif
#ifdef GL_POST_CONVOLUTION_ALPHA_BIAS
    BOOST_CHECK(x != ev.post_convolution_alpha_bias);
#endif
#ifdef GL_POST_CONVOLUTION_ALPHA_SCALE
    BOOST_CHECK(x != ev.post_convolution_alpha_scale);
#endif
#ifdef GL_POST_CONVOLUTION_BLUE_BIAS
    BOOST_CHECK(x != ev.post_convolution_blue_bias);
#endif
#ifdef GL_POST_CONVOLUTION_BLUE_SCALE
    BOOST_CHECK(x != ev.post_convolution_blue_scale);
#endif
#ifdef GL_POST_CONVOLUTION_GREEN_BIAS
    BOOST_CHECK(x != ev.post_convolution_green_bias);
#endif
#ifdef GL_POST_CONVOLUTION_GREEN_SCALE
    BOOST_CHECK(x != ev.post_convolution_green_scale);
#endif
#ifdef GL_POST_CONVOLUTION_RED_BIAS
    BOOST_CHECK(x != ev.post_convolution_red_bias);
#endif
#ifdef GL_POST_CONVOLUTION_RED_SCALE
    BOOST_CHECK(x != ev.post_convolution_red_scale);
#endif
#ifdef GL_RED_BIAS
    BOOST_CHECK(x != ev.red_bias);
#endif
#ifdef GL_RED_SCALE
    BOOST_CHECK(x != ev.red_scale);
#endif
#endif

#ifdef GL_MAP_STENCIL
    x = ev.map_stencil;
    BOOST_CHECK(x == ev.map_stencil);
#ifdef GL_POST_COLOR_MATRIX_ALPHA_BIAS
    BOOST_CHECK(x != ev.post_color_matrix_alpha_bias);
#endif
#ifdef GL_POST_COLOR_MATRIX_ALPHA_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_alpha_scale);
#endif
#ifdef GL_POST_COLOR_MATRIX_BLUE_BIAS
    BOOST_CHECK(x != ev.post_color_matrix_blue_bias);
#endif
#ifdef GL_POST_COLOR_MATRIX_BLUE_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_blue_scale);
#endif
#ifdef GL_POST_COLOR_MATRIX_GREEN_BIAS
    BOOST_CHECK(x != ev.post_color_matrix_green_bias);
#endif
#ifdef GL_POST_COLOR_MATRIX_GREEN_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_green_scale);
#endif
#ifdef GL_POST_COLOR_MATRIX_RED_BIAS
    BOOST_CHECK(x != ev.post_color_matrix_red_bias);
#endif
#ifdef GL_POST_COLOR_MATRIX_RED_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_red_scale);
#endif
#ifdef GL_POST_CONVOLUTION_ALPHA_BIAS
    BOOST_CHECK(x != ev.post_convolution_alpha_bias);
#endif
#ifdef GL_POST_CONVOLUTION_ALPHA_SCALE
    BOOST_CHECK(x != ev.post_convolution_alpha_scale);
#endif
#ifdef GL_POST_CONVOLUTION_BLUE_BIAS
    BOOST_CHECK(x != ev.post_convolution_blue_bias);
#endif
#ifdef GL_POST_CONVOLUTION_BLUE_SCALE
    BOOST_CHECK(x != ev.post_convolution_blue_scale);
#endif
#ifdef GL_POST_CONVOLUTION_GREEN_BIAS
    BOOST_CHECK(x != ev.post_convolution_green_bias);
#endif
#ifdef GL_POST_CONVOLUTION_GREEN_SCALE
    BOOST_CHECK(x != ev.post_convolution_green_scale);
#endif
#ifdef GL_POST_CONVOLUTION_RED_BIAS
    BOOST_CHECK(x != ev.post_convolution_red_bias);
#endif
#ifdef GL_POST_CONVOLUTION_RED_SCALE
    BOOST_CHECK(x != ev.post_convolution_red_scale);
#endif
#ifdef GL_RED_BIAS
    BOOST_CHECK(x != ev.red_bias);
#endif
#ifdef GL_RED_SCALE
    BOOST_CHECK(x != ev.red_scale);
#endif
#endif

#ifdef GL_POST_COLOR_MATRIX_ALPHA_BIAS
    x = ev.post_color_matrix_alpha_bias;
    BOOST_CHECK(x == ev.post_color_matrix_alpha_bias);
#ifdef GL_POST_COLOR_MATRIX_ALPHA_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_alpha_scale);
#endif
#ifdef GL_POST_COLOR_MATRIX_BLUE_BIAS
    BOOST_CHECK(x != ev.post_color_matrix_blue_bias);
#endif
#ifdef GL_POST_COLOR_MATRIX_BLUE_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_blue_scale);
#endif
#ifdef GL_POST_COLOR_MATRIX_GREEN_BIAS
    BOOST_CHECK(x != ev.post_color_matrix_green_bias);
#endif
#ifdef GL_POST_COLOR_MATRIX_GREEN_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_green_scale);
#endif
#ifdef GL_POST_COLOR_MATRIX_RED_BIAS
    BOOST_CHECK(x != ev.post_color_matrix_red_bias);
#endif
#ifdef GL_POST_COLOR_MATRIX_RED_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_red_scale);
#endif
#ifdef GL_POST_CONVOLUTION_ALPHA_BIAS
    BOOST_CHECK(x != ev.post_convolution_alpha_bias);
#endif
#ifdef GL_POST_CONVOLUTION_ALPHA_SCALE
    BOOST_CHECK(x != ev.post_convolution_alpha_scale);
#endif
#ifdef GL_POST_CONVOLUTION_BLUE_BIAS
    BOOST_CHECK(x != ev.post_convolution_blue_bias);
#endif
#ifdef GL_POST_CONVOLUTION_BLUE_SCALE
    BOOST_CHECK(x != ev.post_convolution_blue_scale);
#endif
#ifdef GL_POST_CONVOLUTION_GREEN_BIAS
    BOOST_CHECK(x != ev.post_convolution_green_bias);
#endif
#ifdef GL_POST_CONVOLUTION_GREEN_SCALE
    BOOST_CHECK(x != ev.post_convolution_green_scale);
#endif
#ifdef GL_POST_CONVOLUTION_RED_BIAS
    BOOST_CHECK(x != ev.post_convolution_red_bias);
#endif
#ifdef GL_POST_CONVOLUTION_RED_SCALE
    BOOST_CHECK(x != ev.post_convolution_red_scale);
#endif
#ifdef GL_RED_BIAS
    BOOST_CHECK(x != ev.red_bias);
#endif
#ifdef GL_RED_SCALE
    BOOST_CHECK(x != ev.red_scale);
#endif
#endif

#ifdef GL_POST_COLOR_MATRIX_ALPHA_SCALE
    x = ev.post_color_matrix_alpha_scale;
    BOOST_CHECK(x == ev.post_color_matrix_alpha_scale);
#ifdef GL_POST_COLOR_MATRIX_BLUE_BIAS
    BOOST_CHECK(x != ev.post_color_matrix_blue_bias);
#endif
#ifdef GL_POST_COLOR_MATRIX_BLUE_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_blue_scale);
#endif
#ifdef GL_POST_COLOR_MATRIX_GREEN_BIAS
    BOOST_CHECK(x != ev.post_color_matrix_green_bias);
#endif
#ifdef GL_POST_COLOR_MATRIX_GREEN_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_green_scale);
#endif
#ifdef GL_POST_COLOR_MATRIX_RED_BIAS
    BOOST_CHECK(x != ev.post_color_matrix_red_bias);
#endif
#ifdef GL_POST_COLOR_MATRIX_RED_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_red_scale);
#endif
#ifdef GL_POST_CONVOLUTION_ALPHA_BIAS
    BOOST_CHECK(x != ev.post_convolution_alpha_bias);
#endif
#ifdef GL_POST_CONVOLUTION_ALPHA_SCALE
    BOOST_CHECK(x != ev.post_convolution_alpha_scale);
#endif
#ifdef GL_POST_CONVOLUTION_BLUE_BIAS
    BOOST_CHECK(x != ev.post_convolution_blue_bias);
#endif
#ifdef GL_POST_CONVOLUTION_BLUE_SCALE
    BOOST_CHECK(x != ev.post_convolution_blue_scale);
#endif
#ifdef GL_POST_CONVOLUTION_GREEN_BIAS
    BOOST_CHECK(x != ev.post_convolution_green_bias);
#endif
#ifdef GL_POST_CONVOLUTION_GREEN_SCALE
    BOOST_CHECK(x != ev.post_convolution_green_scale);
#endif
#ifdef GL_POST_CONVOLUTION_RED_BIAS
    BOOST_CHECK(x != ev.post_convolution_red_bias);
#endif
#ifdef GL_POST_CONVOLUTION_RED_SCALE
    BOOST_CHECK(x != ev.post_convolution_red_scale);
#endif
#ifdef GL_RED_BIAS
    BOOST_CHECK(x != ev.red_bias);
#endif
#ifdef GL_RED_SCALE
    BOOST_CHECK(x != ev.red_scale);
#endif
#endif

#ifdef GL_POST_COLOR_MATRIX_BLUE_BIAS
    x = ev.post_color_matrix_blue_bias;
    BOOST_CHECK(x == ev.post_color_matrix_blue_bias);
#ifdef GL_POST_COLOR_MATRIX_BLUE_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_blue_scale);
#endif
#ifdef GL_POST_COLOR_MATRIX_GREEN_BIAS
    BOOST_CHECK(x != ev.post_color_matrix_green_bias);
#endif
#ifdef GL_POST_COLOR_MATRIX_GREEN_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_green_scale);
#endif
#ifdef GL_POST_COLOR_MATRIX_RED_BIAS
    BOOST_CHECK(x != ev.post_color_matrix_red_bias);
#endif
#ifdef GL_POST_COLOR_MATRIX_RED_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_red_scale);
#endif
#ifdef GL_POST_CONVOLUTION_ALPHA_BIAS
    BOOST_CHECK(x != ev.post_convolution_alpha_bias);
#endif
#ifdef GL_POST_CONVOLUTION_ALPHA_SCALE
    BOOST_CHECK(x != ev.post_convolution_alpha_scale);
#endif
#ifdef GL_POST_CONVOLUTION_BLUE_BIAS
    BOOST_CHECK(x != ev.post_convolution_blue_bias);
#endif
#ifdef GL_POST_CONVOLUTION_BLUE_SCALE
    BOOST_CHECK(x != ev.post_convolution_blue_scale);
#endif
#ifdef GL_POST_CONVOLUTION_GREEN_BIAS
    BOOST_CHECK(x != ev.post_convolution_green_bias);
#endif
#ifdef GL_POST_CONVOLUTION_GREEN_SCALE
    BOOST_CHECK(x != ev.post_convolution_green_scale);
#endif
#ifdef GL_POST_CONVOLUTION_RED_BIAS
    BOOST_CHECK(x != ev.post_convolution_red_bias);
#endif
#ifdef GL_POST_CONVOLUTION_RED_SCALE
    BOOST_CHECK(x != ev.post_convolution_red_scale);
#endif
#ifdef GL_RED_BIAS
    BOOST_CHECK(x != ev.red_bias);
#endif
#ifdef GL_RED_SCALE
    BOOST_CHECK(x != ev.red_scale);
#endif
#endif

#ifdef GL_POST_COLOR_MATRIX_BLUE_SCALE
    x = ev.post_color_matrix_blue_scale;
    BOOST_CHECK(x == ev.post_color_matrix_blue_scale);
#ifdef GL_POST_COLOR_MATRIX_GREEN_BIAS
    BOOST_CHECK(x != ev.post_color_matrix_green_bias);
#endif
#ifdef GL_POST_COLOR_MATRIX_GREEN_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_green_scale);
#endif
#ifdef GL_POST_COLOR_MATRIX_RED_BIAS
    BOOST_CHECK(x != ev.post_color_matrix_red_bias);
#endif
#ifdef GL_POST_COLOR_MATRIX_RED_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_red_scale);
#endif
#ifdef GL_POST_CONVOLUTION_ALPHA_BIAS
    BOOST_CHECK(x != ev.post_convolution_alpha_bias);
#endif
#ifdef GL_POST_CONVOLUTION_ALPHA_SCALE
    BOOST_CHECK(x != ev.post_convolution_alpha_scale);
#endif
#ifdef GL_POST_CONVOLUTION_BLUE_BIAS
    BOOST_CHECK(x != ev.post_convolution_blue_bias);
#endif
#ifdef GL_POST_CONVOLUTION_BLUE_SCALE
    BOOST_CHECK(x != ev.post_convolution_blue_scale);
#endif
#ifdef GL_POST_CONVOLUTION_GREEN_BIAS
    BOOST_CHECK(x != ev.post_convolution_green_bias);
#endif
#ifdef GL_POST_CONVOLUTION_GREEN_SCALE
    BOOST_CHECK(x != ev.post_convolution_green_scale);
#endif
#ifdef GL_POST_CONVOLUTION_RED_BIAS
    BOOST_CHECK(x != ev.post_convolution_red_bias);
#endif
#ifdef GL_POST_CONVOLUTION_RED_SCALE
    BOOST_CHECK(x != ev.post_convolution_red_scale);
#endif
#ifdef GL_RED_BIAS
    BOOST_CHECK(x != ev.red_bias);
#endif
#ifdef GL_RED_SCALE
    BOOST_CHECK(x != ev.red_scale);
#endif
#endif

#ifdef GL_POST_COLOR_MATRIX_GREEN_BIAS
    x = ev.post_color_matrix_green_bias;
    BOOST_CHECK(x == ev.post_color_matrix_green_bias);
#ifdef GL_POST_COLOR_MATRIX_GREEN_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_green_scale);
#endif
#ifdef GL_POST_COLOR_MATRIX_RED_BIAS
    BOOST_CHECK(x != ev.post_color_matrix_red_bias);
#endif
#ifdef GL_POST_COLOR_MATRIX_RED_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_red_scale);
#endif
#ifdef GL_POST_CONVOLUTION_ALPHA_BIAS
    BOOST_CHECK(x != ev.post_convolution_alpha_bias);
#endif
#ifdef GL_POST_CONVOLUTION_ALPHA_SCALE
    BOOST_CHECK(x != ev.post_convolution_alpha_scale);
#endif
#ifdef GL_POST_CONVOLUTION_BLUE_BIAS
    BOOST_CHECK(x != ev.post_convolution_blue_bias);
#endif
#ifdef GL_POST_CONVOLUTION_BLUE_SCALE
    BOOST_CHECK(x != ev.post_convolution_blue_scale);
#endif
#ifdef GL_POST_CONVOLUTION_GREEN_BIAS
    BOOST_CHECK(x != ev.post_convolution_green_bias);
#endif
#ifdef GL_POST_CONVOLUTION_GREEN_SCALE
    BOOST_CHECK(x != ev.post_convolution_green_scale);
#endif
#ifdef GL_POST_CONVOLUTION_RED_BIAS
    BOOST_CHECK(x != ev.post_convolution_red_bias);
#endif
#ifdef GL_POST_CONVOLUTION_RED_SCALE
    BOOST_CHECK(x != ev.post_convolution_red_scale);
#endif
#ifdef GL_RED_BIAS
    BOOST_CHECK(x != ev.red_bias);
#endif
#ifdef GL_RED_SCALE
    BOOST_CHECK(x != ev.red_scale);
#endif
#endif

#ifdef GL_POST_COLOR_MATRIX_GREEN_SCALE
    x = ev.post_color_matrix_green_scale;
    BOOST_CHECK(x == ev.post_color_matrix_green_scale);
#ifdef GL_POST_COLOR_MATRIX_RED_BIAS
    BOOST_CHECK(x != ev.post_color_matrix_red_bias);
#endif
#ifdef GL_POST_COLOR_MATRIX_RED_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_red_scale);
#endif
#ifdef GL_POST_CONVOLUTION_ALPHA_BIAS
    BOOST_CHECK(x != ev.post_convolution_alpha_bias);
#endif
#ifdef GL_POST_CONVOLUTION_ALPHA_SCALE
    BOOST_CHECK(x != ev.post_convolution_alpha_scale);
#endif
#ifdef GL_POST_CONVOLUTION_BLUE_BIAS
    BOOST_CHECK(x != ev.post_convolution_blue_bias);
#endif
#ifdef GL_POST_CONVOLUTION_BLUE_SCALE
    BOOST_CHECK(x != ev.post_convolution_blue_scale);
#endif
#ifdef GL_POST_CONVOLUTION_GREEN_BIAS
    BOOST_CHECK(x != ev.post_convolution_green_bias);
#endif
#ifdef GL_POST_CONVOLUTION_GREEN_SCALE
    BOOST_CHECK(x != ev.post_convolution_green_scale);
#endif
#ifdef GL_POST_CONVOLUTION_RED_BIAS
    BOOST_CHECK(x != ev.post_convolution_red_bias);
#endif
#ifdef GL_POST_CONVOLUTION_RED_SCALE
    BOOST_CHECK(x != ev.post_convolution_red_scale);
#endif
#ifdef GL_RED_BIAS
    BOOST_CHECK(x != ev.red_bias);
#endif
#ifdef GL_RED_SCALE
    BOOST_CHECK(x != ev.red_scale);
#endif
#endif

#ifdef GL_POST_COLOR_MATRIX_RED_BIAS
    x = ev.post_color_matrix_red_bias;
    BOOST_CHECK(x == ev.post_color_matrix_red_bias);
#ifdef GL_POST_COLOR_MATRIX_RED_SCALE
    BOOST_CHECK(x != ev.post_color_matrix_red_scale);
#endif
#ifdef GL_POST_CONVOLUTION_ALPHA_BIAS
    BOOST_CHECK(x != ev.post_convolution_alpha_bias);
#endif
#ifdef GL_POST_CONVOLUTION_ALPHA_SCALE
    BOOST_CHECK(x != ev.post_convolution_alpha_scale);
#endif
#ifdef GL_POST_CONVOLUTION_BLUE_BIAS
    BOOST_CHECK(x != ev.post_convolution_blue_bias);
#endif
#ifdef GL_POST_CONVOLUTION_BLUE_SCALE
    BOOST_CHECK(x != ev.post_convolution_blue_scale);
#endif
#ifdef GL_POST_CONVOLUTION_GREEN_BIAS
    BOOST_CHECK(x != ev.post_convolution_green_bias);
#endif
#ifdef GL_POST_CONVOLUTION_GREEN_SCALE
    BOOST_CHECK(x != ev.post_convolution_green_scale);
#endif
#ifdef GL_POST_CONVOLUTION_RED_BIAS
    BOOST_CHECK(x != ev.post_convolution_red_bias);
#endif
#ifdef GL_POST_CONVOLUTION_RED_SCALE
    BOOST_CHECK(x != ev.post_convolution_red_scale);
#endif
#ifdef GL_RED_BIAS
    BOOST_CHECK(x != ev.red_bias);
#endif
#ifdef GL_RED_SCALE
    BOOST_CHECK(x != ev.red_scale);
#endif
#endif

#ifdef GL_POST_COLOR_MATRIX_RED_SCALE
    x = ev.post_color_matrix_red_scale;
    BOOST_CHECK(x == ev.post_color_matrix_red_scale);
#ifdef GL_POST_CONVOLUTION_ALPHA_BIAS
    BOOST_CHECK(x != ev.post_convolution_alpha_bias);
#endif
#ifdef GL_POST_CONVOLUTION_ALPHA_SCALE
    BOOST_CHECK(x != ev.post_convolution_alpha_scale);
#endif
#ifdef GL_POST_CONVOLUTION_BLUE_BIAS
    BOOST_CHECK(x != ev.post_convolution_blue_bias);
#endif
#ifdef GL_POST_CONVOLUTION_BLUE_SCALE
    BOOST_CHECK(x != ev.post_convolution_blue_scale);
#endif
#ifdef GL_POST_CONVOLUTION_GREEN_BIAS
    BOOST_CHECK(x != ev.post_convolution_green_bias);
#endif
#ifdef GL_POST_CONVOLUTION_GREEN_SCALE
    BOOST_CHECK(x != ev.post_convolution_green_scale);
#endif
#ifdef GL_POST_CONVOLUTION_RED_BIAS
    BOOST_CHECK(x != ev.post_convolution_red_bias);
#endif
#ifdef GL_POST_CONVOLUTION_RED_SCALE
    BOOST_CHECK(x != ev.post_convolution_red_scale);
#endif
#ifdef GL_RED_BIAS
    BOOST_CHECK(x != ev.red_bias);
#endif
#ifdef GL_RED_SCALE
    BOOST_CHECK(x != ev.red_scale);
#endif
#endif

#ifdef GL_POST_CONVOLUTION_ALPHA_BIAS
    x = ev.post_convolution_alpha_bias;
    BOOST_CHECK(x == ev.post_convolution_alpha_bias);
#ifdef GL_POST_CONVOLUTION_ALPHA_SCALE
    BOOST_CHECK(x != ev.post_convolution_alpha_scale);
#endif
#ifdef GL_POST_CONVOLUTION_BLUE_BIAS
    BOOST_CHECK(x != ev.post_convolution_blue_bias);
#endif
#ifdef GL_POST_CONVOLUTION_BLUE_SCALE
    BOOST_CHECK(x != ev.post_convolution_blue_scale);
#endif
#ifdef GL_POST_CONVOLUTION_GREEN_BIAS
    BOOST_CHECK(x != ev.post_convolution_green_bias);
#endif
#ifdef GL_POST_CONVOLUTION_GREEN_SCALE
    BOOST_CHECK(x != ev.post_convolution_green_scale);
#endif
#ifdef GL_POST_CONVOLUTION_RED_BIAS
    BOOST_CHECK(x != ev.post_convolution_red_bias);
#endif
#ifdef GL_POST_CONVOLUTION_RED_SCALE
    BOOST_CHECK(x != ev.post_convolution_red_scale);
#endif
#ifdef GL_RED_BIAS
    BOOST_CHECK(x != ev.red_bias);
#endif
#ifdef GL_RED_SCALE
    BOOST_CHECK(x != ev.red_scale);
#endif
#endif

#ifdef GL_POST_CONVOLUTION_ALPHA_SCALE
    x = ev.post_convolution_alpha_scale;
    BOOST_CHECK(x == ev.post_convolution_alpha_scale);
#ifdef GL_POST_CONVOLUTION_BLUE_BIAS
    BOOST_CHECK(x != ev.post_convolution_blue_bias);
#endif
#ifdef GL_POST_CONVOLUTION_BLUE_SCALE
    BOOST_CHECK(x != ev.post_convolution_blue_scale);
#endif
#ifdef GL_POST_CONVOLUTION_GREEN_BIAS
    BOOST_CHECK(x != ev.post_convolution_green_bias);
#endif
#ifdef GL_POST_CONVOLUTION_GREEN_SCALE
    BOOST_CHECK(x != ev.post_convolution_green_scale);
#endif
#ifdef GL_POST_CONVOLUTION_RED_BIAS
    BOOST_CHECK(x != ev.post_convolution_red_bias);
#endif
#ifdef GL_POST_CONVOLUTION_RED_SCALE
    BOOST_CHECK(x != ev.post_convolution_red_scale);
#endif
#ifdef GL_RED_BIAS
    BOOST_CHECK(x != ev.red_bias);
#endif
#ifdef GL_RED_SCALE
    BOOST_CHECK(x != ev.red_scale);
#endif
#endif

#ifdef GL_POST_CONVOLUTION_BLUE_BIAS
    x = ev.post_convolution_blue_bias;
    BOOST_CHECK(x == ev.post_convolution_blue_bias);
#ifdef GL_POST_CONVOLUTION_BLUE_SCALE
    BOOST_CHECK(x != ev.post_convolution_blue_scale);
#endif
#ifdef GL_POST_CONVOLUTION_GREEN_BIAS
    BOOST_CHECK(x != ev.post_convolution_green_bias);
#endif
#ifdef GL_POST_CONVOLUTION_GREEN_SCALE
    BOOST_CHECK(x != ev.post_convolution_green_scale);
#endif
#ifdef GL_POST_CONVOLUTION_RED_BIAS
    BOOST_CHECK(x != ev.post_convolution_red_bias);
#endif
#ifdef GL_POST_CONVOLUTION_RED_SCALE
    BOOST_CHECK(x != ev.post_convolution_red_scale);
#endif
#ifdef GL_RED_BIAS
    BOOST_CHECK(x != ev.red_bias);
#endif
#ifdef GL_RED_SCALE
    BOOST_CHECK(x != ev.red_scale);
#endif
#endif

#ifdef GL_POST_CONVOLUTION_BLUE_SCALE
    x = ev.post_convolution_blue_scale;
    BOOST_CHECK(x == ev.post_convolution_blue_scale);
#ifdef GL_POST_CONVOLUTION_GREEN_BIAS
    BOOST_CHECK(x != ev.post_convolution_green_bias);
#endif
#ifdef GL_POST_CONVOLUTION_GREEN_SCALE
    BOOST_CHECK(x != ev.post_convolution_green_scale);
#endif
#ifdef GL_POST_CONVOLUTION_RED_BIAS
    BOOST_CHECK(x != ev.post_convolution_red_bias);
#endif
#ifdef GL_POST_CONVOLUTION_RED_SCALE
    BOOST_CHECK(x != ev.post_convolution_red_scale);
#endif
#ifdef GL_RED_BIAS
    BOOST_CHECK(x != ev.red_bias);
#endif
#ifdef GL_RED_SCALE
    BOOST_CHECK(x != ev.red_scale);
#endif
#endif

#ifdef GL_POST_CONVOLUTION_GREEN_BIAS
    x = ev.post_convolution_green_bias;
    BOOST_CHECK(x == ev.post_convolution_green_bias);
#ifdef GL_POST_CONVOLUTION_GREEN_SCALE
    BOOST_CHECK(x != ev.post_convolution_green_scale);
#endif
#ifdef GL_POST_CONVOLUTION_RED_BIAS
    BOOST_CHECK(x != ev.post_convolution_red_bias);
#endif
#ifdef GL_POST_CONVOLUTION_RED_SCALE
    BOOST_CHECK(x != ev.post_convolution_red_scale);
#endif
#ifdef GL_RED_BIAS
    BOOST_CHECK(x != ev.red_bias);
#endif
#ifdef GL_RED_SCALE
    BOOST_CHECK(x != ev.red_scale);
#endif
#endif

#ifdef GL_POST_CONVOLUTION_GREEN_SCALE
    x = ev.post_convolution_green_scale;
    BOOST_CHECK(x == ev.post_convolution_green_scale);
#ifdef GL_POST_CONVOLUTION_RED_BIAS
    BOOST_CHECK(x != ev.post_convolution_red_bias);
#endif
#ifdef GL_POST_CONVOLUTION_RED_SCALE
    BOOST_CHECK(x != ev.post_convolution_red_scale);
#endif
#ifdef GL_RED_BIAS
    BOOST_CHECK(x != ev.red_bias);
#endif
#ifdef GL_RED_SCALE
    BOOST_CHECK(x != ev.red_scale);
#endif
#endif

#ifdef GL_POST_CONVOLUTION_RED_BIAS
    x = ev.post_convolution_red_bias;
    BOOST_CHECK(x == ev.post_convolution_red_bias);
#ifdef GL_POST_CONVOLUTION_RED_SCALE
    BOOST_CHECK(x != ev.post_convolution_red_scale);
#endif
#ifdef GL_RED_BIAS
    BOOST_CHECK(x != ev.red_bias);
#endif
#ifdef GL_RED_SCALE
    BOOST_CHECK(x != ev.red_scale);
#endif
#endif

#ifdef GL_POST_CONVOLUTION_RED_SCALE
    x = ev.post_convolution_red_scale;
    BOOST_CHECK(x == ev.post_convolution_red_scale);
#ifdef GL_RED_BIAS
    BOOST_CHECK(x != ev.red_bias);
#endif
#ifdef GL_RED_SCALE
    BOOST_CHECK(x != ev.red_scale);
#endif
#endif

#ifdef GL_RED_BIAS
    x = ev.red_bias;
    BOOST_CHECK(x == ev.red_bias);
#ifdef GL_RED_SCALE
    BOOST_CHECK(x != ev.red_scale);
#endif
#endif

#ifdef GL_RED_SCALE
    x = ev.red_scale;
    BOOST_CHECK(x == ev.red_scale);
#endif
}

BOOST_AUTO_TEST_CASE(enum_pixel_transfer_parameter_names) {
    using namespace oglplus;
    enum_values ev;
    EAGINE_MAYBE_UNUSED(ev);
    pixel_transfer_parameter x;
    EAGINE_MAYBE_UNUSED(x);

#ifdef GL_ALPHA_BIAS
    x = ev.alpha_bias;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(std::strcmp(enum_value_name(x).data(), "ALPHA_BIAS") == 0);
#endif

#ifdef GL_ALPHA_SCALE
    x = ev.alpha_scale;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(std::strcmp(enum_value_name(x).data(), "ALPHA_SCALE") == 0);
#endif

#ifdef GL_BLUE_BIAS
    x = ev.blue_bias;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(std::strcmp(enum_value_name(x).data(), "BLUE_BIAS") == 0);
#endif

#ifdef GL_BLUE_SCALE
    x = ev.blue_scale;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(std::strcmp(enum_value_name(x).data(), "BLUE_SCALE") == 0);
#endif

#ifdef GL_DEPTH_BIAS
    x = ev.depth_bias;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(std::strcmp(enum_value_name(x).data(), "DEPTH_BIAS") == 0);
#endif

#ifdef GL_DEPTH_SCALE
    x = ev.depth_scale;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(std::strcmp(enum_value_name(x).data(), "DEPTH_SCALE") == 0);
#endif

#ifdef GL_GREEN_BIAS
    x = ev.green_bias;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(std::strcmp(enum_value_name(x).data(), "GREEN_BIAS") == 0);
#endif

#ifdef GL_GREEN_SCALE
    x = ev.green_scale;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(std::strcmp(enum_value_name(x).data(), "GREEN_SCALE") == 0);
#endif

#ifdef GL_INDEX_OFFSET
    x = ev.index_offset;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(std::strcmp(enum_value_name(x).data(), "INDEX_OFFSET") == 0);
#endif

#ifdef GL_INDEX_SHIFT
    x = ev.index_shift;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(std::strcmp(enum_value_name(x).data(), "INDEX_SHIFT") == 0);
#endif

#ifdef GL_MAP_COLOR
    x = ev.map_color;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(std::strcmp(enum_value_name(x).data(), "MAP_COLOR") == 0);
#endif

#ifdef GL_MAP_STENCIL
    x = ev.map_stencil;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(std::strcmp(enum_value_name(x).data(), "MAP_STENCIL") == 0);
#endif

#ifdef GL_POST_COLOR_MATRIX_ALPHA_BIAS
    x = ev.post_color_matrix_alpha_bias;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "POST_COLOR_MATRIX_ALPHA_BIAS") ==
      0);
#endif

#ifdef GL_POST_COLOR_MATRIX_ALPHA_SCALE
    x = ev.post_color_matrix_alpha_scale;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "POST_COLOR_MATRIX_ALPHA_SCALE") ==
      0);
#endif

#ifdef GL_POST_COLOR_MATRIX_BLUE_BIAS
    x = ev.post_color_matrix_blue_bias;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "POST_COLOR_MATRIX_BLUE_BIAS") ==
      0);
#endif

#ifdef GL_POST_COLOR_MATRIX_BLUE_SCALE
    x = ev.post_color_matrix_blue_scale;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "POST_COLOR_MATRIX_BLUE_SCALE") ==
      0);
#endif

#ifdef GL_POST_COLOR_MATRIX_GREEN_BIAS
    x = ev.post_color_matrix_green_bias;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "POST_COLOR_MATRIX_GREEN_BIAS") ==
      0);
#endif

#ifdef GL_POST_COLOR_MATRIX_GREEN_SCALE
    x = ev.post_color_matrix_green_scale;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "POST_COLOR_MATRIX_GREEN_SCALE") ==
      0);
#endif

#ifdef GL_POST_COLOR_MATRIX_RED_BIAS
    x = ev.post_color_matrix_red_bias;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "POST_COLOR_MATRIX_RED_BIAS") ==
      0);
#endif

#ifdef GL_POST_COLOR_MATRIX_RED_SCALE
    x = ev.post_color_matrix_red_scale;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "POST_COLOR_MATRIX_RED_SCALE") ==
      0);
#endif

#ifdef GL_POST_CONVOLUTION_ALPHA_BIAS
    x = ev.post_convolution_alpha_bias;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "POST_CONVOLUTION_ALPHA_BIAS") ==
      0);
#endif

#ifdef GL_POST_CONVOLUTION_ALPHA_SCALE
    x = ev.post_convolution_alpha_scale;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "POST_CONVOLUTION_ALPHA_SCALE") ==
      0);
#endif

#ifdef GL_POST_CONVOLUTION_BLUE_BIAS
    x = ev.post_convolution_blue_bias;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "POST_CONVOLUTION_BLUE_BIAS") ==
      0);
#endif

#ifdef GL_POST_CONVOLUTION_BLUE_SCALE
    x = ev.post_convolution_blue_scale;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "POST_CONVOLUTION_BLUE_SCALE") ==
      0);
#endif

#ifdef GL_POST_CONVOLUTION_GREEN_BIAS
    x = ev.post_convolution_green_bias;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "POST_CONVOLUTION_GREEN_BIAS") ==
      0);
#endif

#ifdef GL_POST_CONVOLUTION_GREEN_SCALE
    x = ev.post_convolution_green_scale;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "POST_CONVOLUTION_GREEN_SCALE") ==
      0);
#endif

#ifdef GL_POST_CONVOLUTION_RED_BIAS
    x = ev.post_convolution_red_bias;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "POST_CONVOLUTION_RED_BIAS") == 0);
#endif

#ifdef GL_POST_CONVOLUTION_RED_SCALE
    x = ev.post_convolution_red_scale;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "POST_CONVOLUTION_RED_SCALE") ==
      0);
#endif

#ifdef GL_RED_BIAS
    x = ev.red_bias;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(std::strcmp(enum_value_name(x).data(), "RED_BIAS") == 0);
#endif

#ifdef GL_RED_SCALE
    x = ev.red_scale;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(std::strcmp(enum_value_name(x).data(), "RED_SCALE") == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_pixel_transfer_parameter_range) {
    using namespace oglplus;
    auto count = enum_value_range<pixel_transfer_parameter>().size();

#ifdef GL_ALPHA_BIAS
    {
        --count;
        auto r = enum_value_range<pixel_transfer_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(), r.end(), pixel_transfer_parameter(GL_ALPHA_BIAS)) !=
          r.end());
    }
#endif

#ifdef GL_ALPHA_SCALE
    {
        --count;
        auto r = enum_value_range<pixel_transfer_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(), r.end(), pixel_transfer_parameter(GL_ALPHA_SCALE)) !=
          r.end());
    }
#endif

#ifdef GL_BLUE_BIAS
    {
        --count;
        auto r = enum_value_range<pixel_transfer_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(), r.end(), pixel_transfer_parameter(GL_BLUE_BIAS)) !=
          r.end());
    }
#endif

#ifdef GL_BLUE_SCALE
    {
        --count;
        auto r = enum_value_range<pixel_transfer_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(), r.end(), pixel_transfer_parameter(GL_BLUE_SCALE)) !=
          r.end());
    }
#endif

#ifdef GL_DEPTH_BIAS
    {
        --count;
        auto r = enum_value_range<pixel_transfer_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(), r.end(), pixel_transfer_parameter(GL_DEPTH_BIAS)) !=
          r.end());
    }
#endif

#ifdef GL_DEPTH_SCALE
    {
        --count;
        auto r = enum_value_range<pixel_transfer_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(), r.end(), pixel_transfer_parameter(GL_DEPTH_SCALE)) !=
          r.end());
    }
#endif

#ifdef GL_GREEN_BIAS
    {
        --count;
        auto r = enum_value_range<pixel_transfer_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(), r.end(), pixel_transfer_parameter(GL_GREEN_BIAS)) !=
          r.end());
    }
#endif

#ifdef GL_GREEN_SCALE
    {
        --count;
        auto r = enum_value_range<pixel_transfer_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(), r.end(), pixel_transfer_parameter(GL_GREEN_SCALE)) !=
          r.end());
    }
#endif

#ifdef GL_INDEX_OFFSET
    {
        --count;
        auto r = enum_value_range<pixel_transfer_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(), r.end(), pixel_transfer_parameter(GL_INDEX_OFFSET)) !=
          r.end());
    }
#endif

#ifdef GL_INDEX_SHIFT
    {
        --count;
        auto r = enum_value_range<pixel_transfer_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(), r.end(), pixel_transfer_parameter(GL_INDEX_SHIFT)) !=
          r.end());
    }
#endif

#ifdef GL_MAP_COLOR
    {
        --count;
        auto r = enum_value_range<pixel_transfer_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(), r.end(), pixel_transfer_parameter(GL_MAP_COLOR)) !=
          r.end());
    }
#endif

#ifdef GL_MAP_STENCIL
    {
        --count;
        auto r = enum_value_range<pixel_transfer_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(), r.end(), pixel_transfer_parameter(GL_MAP_STENCIL)) !=
          r.end());
    }
#endif

#ifdef GL_POST_COLOR_MATRIX_ALPHA_BIAS
    {
        --count;
        auto r = enum_value_range<pixel_transfer_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            pixel_transfer_parameter(GL_POST_COLOR_MATRIX_ALPHA_BIAS)) !=
          r.end());
    }
#endif

#ifdef GL_POST_COLOR_MATRIX_ALPHA_SCALE
    {
        --count;
        auto r = enum_value_range<pixel_transfer_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            pixel_transfer_parameter(GL_POST_COLOR_MATRIX_ALPHA_SCALE)) !=
          r.end());
    }
#endif

#ifdef GL_POST_COLOR_MATRIX_BLUE_BIAS
    {
        --count;
        auto r = enum_value_range<pixel_transfer_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            pixel_transfer_parameter(GL_POST_COLOR_MATRIX_BLUE_BIAS)) !=
          r.end());
    }
#endif

#ifdef GL_POST_COLOR_MATRIX_BLUE_SCALE
    {
        --count;
        auto r = enum_value_range<pixel_transfer_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            pixel_transfer_parameter(GL_POST_COLOR_MATRIX_BLUE_SCALE)) !=
          r.end());
    }
#endif

#ifdef GL_POST_COLOR_MATRIX_GREEN_BIAS
    {
        --count;
        auto r = enum_value_range<pixel_transfer_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            pixel_transfer_parameter(GL_POST_COLOR_MATRIX_GREEN_BIAS)) !=
          r.end());
    }
#endif

#ifdef GL_POST_COLOR_MATRIX_GREEN_SCALE
    {
        --count;
        auto r = enum_value_range<pixel_transfer_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            pixel_transfer_parameter(GL_POST_COLOR_MATRIX_GREEN_SCALE)) !=
          r.end());
    }
#endif

#ifdef GL_POST_COLOR_MATRIX_RED_BIAS
    {
        --count;
        auto r = enum_value_range<pixel_transfer_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            pixel_transfer_parameter(GL_POST_COLOR_MATRIX_RED_BIAS)) !=
          r.end());
    }
#endif

#ifdef GL_POST_COLOR_MATRIX_RED_SCALE
    {
        --count;
        auto r = enum_value_range<pixel_transfer_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            pixel_transfer_parameter(GL_POST_COLOR_MATRIX_RED_SCALE)) !=
          r.end());
    }
#endif

#ifdef GL_POST_CONVOLUTION_ALPHA_BIAS
    {
        --count;
        auto r = enum_value_range<pixel_transfer_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            pixel_transfer_parameter(GL_POST_CONVOLUTION_ALPHA_BIAS)) !=
          r.end());
    }
#endif

#ifdef GL_POST_CONVOLUTION_ALPHA_SCALE
    {
        --count;
        auto r = enum_value_range<pixel_transfer_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            pixel_transfer_parameter(GL_POST_CONVOLUTION_ALPHA_SCALE)) !=
          r.end());
    }
#endif

#ifdef GL_POST_CONVOLUTION_BLUE_BIAS
    {
        --count;
        auto r = enum_value_range<pixel_transfer_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            pixel_transfer_parameter(GL_POST_CONVOLUTION_BLUE_BIAS)) !=
          r.end());
    }
#endif

#ifdef GL_POST_CONVOLUTION_BLUE_SCALE
    {
        --count;
        auto r = enum_value_range<pixel_transfer_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            pixel_transfer_parameter(GL_POST_CONVOLUTION_BLUE_SCALE)) !=
          r.end());
    }
#endif

#ifdef GL_POST_CONVOLUTION_GREEN_BIAS
    {
        --count;
        auto r = enum_value_range<pixel_transfer_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            pixel_transfer_parameter(GL_POST_CONVOLUTION_GREEN_BIAS)) !=
          r.end());
    }
#endif

#ifdef GL_POST_CONVOLUTION_GREEN_SCALE
    {
        --count;
        auto r = enum_value_range<pixel_transfer_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            pixel_transfer_parameter(GL_POST_CONVOLUTION_GREEN_SCALE)) !=
          r.end());
    }
#endif

#ifdef GL_POST_CONVOLUTION_RED_BIAS
    {
        --count;
        auto r = enum_value_range<pixel_transfer_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            pixel_transfer_parameter(GL_POST_CONVOLUTION_RED_BIAS)) != r.end());
    }
#endif

#ifdef GL_POST_CONVOLUTION_RED_SCALE
    {
        --count;
        auto r = enum_value_range<pixel_transfer_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            pixel_transfer_parameter(GL_POST_CONVOLUTION_RED_SCALE)) !=
          r.end());
    }
#endif

#ifdef GL_RED_BIAS
    {
        --count;
        auto r = enum_value_range<pixel_transfer_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(), r.end(), pixel_transfer_parameter(GL_RED_BIAS)) !=
          r.end());
    }
#endif

#ifdef GL_RED_SCALE
    {
        --count;
        auto r = enum_value_range<pixel_transfer_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(), r.end(), pixel_transfer_parameter(GL_RED_SCALE)) !=
          r.end());
    }
#endif
    BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_pixel_transfer_parameter_any) {
    using namespace oglplus;
    enum_values ev;
    EAGINE_MAYBE_UNUSED(ev);
    pixel_transfer_parameter x, y;
    EAGINE_MAYBE_UNUSED(x);
    EAGINE_MAYBE_UNUSED(y);
    any_enum_value a;
    EAGINE_MAYBE_UNUSED(a);

#ifdef GL_ALPHA_BIAS
    x = ev.alpha_bias;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.alpha_bias);
#endif

#ifdef GL_ALPHA_SCALE
    x = ev.alpha_scale;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.alpha_scale);
#endif

#ifdef GL_BLUE_BIAS
    x = ev.blue_bias;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.blue_bias);
#endif

#ifdef GL_BLUE_SCALE
    x = ev.blue_scale;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.blue_scale);
#endif

#ifdef GL_DEPTH_BIAS
    x = ev.depth_bias;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.depth_bias);
#endif

#ifdef GL_DEPTH_SCALE
    x = ev.depth_scale;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.depth_scale);
#endif

#ifdef GL_GREEN_BIAS
    x = ev.green_bias;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.green_bias);
#endif

#ifdef GL_GREEN_SCALE
    x = ev.green_scale;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.green_scale);
#endif

#ifdef GL_INDEX_OFFSET
    x = ev.index_offset;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.index_offset);
#endif

#ifdef GL_INDEX_SHIFT
    x = ev.index_shift;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.index_shift);
#endif

#ifdef GL_MAP_COLOR
    x = ev.map_color;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.map_color);
#endif

#ifdef GL_MAP_STENCIL
    x = ev.map_stencil;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.map_stencil);
#endif

#ifdef GL_POST_COLOR_MATRIX_ALPHA_BIAS
    x = ev.post_color_matrix_alpha_bias;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.post_color_matrix_alpha_bias);
#endif

#ifdef GL_POST_COLOR_MATRIX_ALPHA_SCALE
    x = ev.post_color_matrix_alpha_scale;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.post_color_matrix_alpha_scale);
#endif

#ifdef GL_POST_COLOR_MATRIX_BLUE_BIAS
    x = ev.post_color_matrix_blue_bias;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.post_color_matrix_blue_bias);
#endif

#ifdef GL_POST_COLOR_MATRIX_BLUE_SCALE
    x = ev.post_color_matrix_blue_scale;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.post_color_matrix_blue_scale);
#endif

#ifdef GL_POST_COLOR_MATRIX_GREEN_BIAS
    x = ev.post_color_matrix_green_bias;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.post_color_matrix_green_bias);
#endif

#ifdef GL_POST_COLOR_MATRIX_GREEN_SCALE
    x = ev.post_color_matrix_green_scale;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.post_color_matrix_green_scale);
#endif

#ifdef GL_POST_COLOR_MATRIX_RED_BIAS
    x = ev.post_color_matrix_red_bias;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.post_color_matrix_red_bias);
#endif

#ifdef GL_POST_COLOR_MATRIX_RED_SCALE
    x = ev.post_color_matrix_red_scale;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.post_color_matrix_red_scale);
#endif

#ifdef GL_POST_CONVOLUTION_ALPHA_BIAS
    x = ev.post_convolution_alpha_bias;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.post_convolution_alpha_bias);
#endif

#ifdef GL_POST_CONVOLUTION_ALPHA_SCALE
    x = ev.post_convolution_alpha_scale;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.post_convolution_alpha_scale);
#endif

#ifdef GL_POST_CONVOLUTION_BLUE_BIAS
    x = ev.post_convolution_blue_bias;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.post_convolution_blue_bias);
#endif

#ifdef GL_POST_CONVOLUTION_BLUE_SCALE
    x = ev.post_convolution_blue_scale;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.post_convolution_blue_scale);
#endif

#ifdef GL_POST_CONVOLUTION_GREEN_BIAS
    x = ev.post_convolution_green_bias;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.post_convolution_green_bias);
#endif

#ifdef GL_POST_CONVOLUTION_GREEN_SCALE
    x = ev.post_convolution_green_scale;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.post_convolution_green_scale);
#endif

#ifdef GL_POST_CONVOLUTION_RED_BIAS
    x = ev.post_convolution_red_bias;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.post_convolution_red_bias);
#endif

#ifdef GL_POST_CONVOLUTION_RED_SCALE
    x = ev.post_convolution_red_scale;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.post_convolution_red_scale);
#endif

#ifdef GL_RED_BIAS
    x = ev.red_bias;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.red_bias);
#endif

#ifdef GL_RED_SCALE
    x = ev.red_scale;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.red_scale);
#endif
}

BOOST_AUTO_TEST_SUITE_END()

#include "../../unit_test_end.inl"
