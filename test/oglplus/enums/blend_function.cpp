//  File test/oglplus/enums/blend_function.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_blend_function

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_blend_function)

BOOST_AUTO_TEST_CASE(enum_blend_function_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	blend_function x;
	(void)x;

#ifdef GL_CONSTANT_ALPHA
	x = ev.constant_alpha;
	BOOST_CHECK(x == ev.constant_alpha);
# ifdef GL_CONSTANT_COLOR
	BOOST_CHECK(x != ev.constant_color);
# endif
# ifdef GL_DST_ALPHA
	BOOST_CHECK(x != ev.dst_alpha);
# endif
# ifdef GL_DST_COLOR
	BOOST_CHECK(x != ev.dst_color);
# endif
# ifdef GL_ONE
	BOOST_CHECK(x != ev.one);
# endif
# ifdef GL_ONE_MINUS_CONSTANT_ALPHA
	BOOST_CHECK(x != ev.one_minus_constant_alpha);
# endif
# ifdef GL_ONE_MINUS_CONSTANT_COLOR
	BOOST_CHECK(x != ev.one_minus_constant_color);
# endif
# ifdef GL_ONE_MINUS_DST_ALPHA
	BOOST_CHECK(x != ev.one_minus_dst_alpha);
# endif
# ifdef GL_ONE_MINUS_DST_COLOR
	BOOST_CHECK(x != ev.one_minus_dst_color);
# endif
# ifdef GL_ONE_MINUS_SRC1_ALPHA
	BOOST_CHECK(x != ev.one_minus_src1_alpha);
# endif
# ifdef GL_ONE_MINUS_SRC1_COLOR
	BOOST_CHECK(x != ev.one_minus_src1_color);
# endif
# ifdef GL_ONE_MINUS_SRC_ALPHA
	BOOST_CHECK(x != ev.one_minus_src_alpha);
# endif
# ifdef GL_ONE_MINUS_SRC_COLOR
	BOOST_CHECK(x != ev.one_minus_src_color);
# endif
# ifdef GL_SRC1_ALPHA
	BOOST_CHECK(x != ev.src1_alpha);
# endif
# ifdef GL_SRC1_COLOR
	BOOST_CHECK(x != ev.src1_color);
# endif
# ifdef GL_SRC_ALPHA
	BOOST_CHECK(x != ev.src_alpha);
# endif
# ifdef GL_SRC_ALPHA_SATURATE
	BOOST_CHECK(x != ev.src_alpha_saturate);
# endif
# ifdef GL_SRC_COLOR
	BOOST_CHECK(x != ev.src_color);
# endif
# ifdef GL_ZERO
	BOOST_CHECK(x != ev.zero);
# endif
#endif

#ifdef GL_CONSTANT_COLOR
	x = ev.constant_color;
# ifdef GL_CONSTANT_ALPHA
	BOOST_CHECK(x != ev.constant_alpha);
# endif
	BOOST_CHECK(x == ev.constant_color);
# ifdef GL_DST_ALPHA
	BOOST_CHECK(x != ev.dst_alpha);
# endif
# ifdef GL_DST_COLOR
	BOOST_CHECK(x != ev.dst_color);
# endif
# ifdef GL_ONE
	BOOST_CHECK(x != ev.one);
# endif
# ifdef GL_ONE_MINUS_CONSTANT_ALPHA
	BOOST_CHECK(x != ev.one_minus_constant_alpha);
# endif
# ifdef GL_ONE_MINUS_CONSTANT_COLOR
	BOOST_CHECK(x != ev.one_minus_constant_color);
# endif
# ifdef GL_ONE_MINUS_DST_ALPHA
	BOOST_CHECK(x != ev.one_minus_dst_alpha);
# endif
# ifdef GL_ONE_MINUS_DST_COLOR
	BOOST_CHECK(x != ev.one_minus_dst_color);
# endif
# ifdef GL_ONE_MINUS_SRC1_ALPHA
	BOOST_CHECK(x != ev.one_minus_src1_alpha);
# endif
# ifdef GL_ONE_MINUS_SRC1_COLOR
	BOOST_CHECK(x != ev.one_minus_src1_color);
# endif
# ifdef GL_ONE_MINUS_SRC_ALPHA
	BOOST_CHECK(x != ev.one_minus_src_alpha);
# endif
# ifdef GL_ONE_MINUS_SRC_COLOR
	BOOST_CHECK(x != ev.one_minus_src_color);
# endif
# ifdef GL_SRC1_ALPHA
	BOOST_CHECK(x != ev.src1_alpha);
# endif
# ifdef GL_SRC1_COLOR
	BOOST_CHECK(x != ev.src1_color);
# endif
# ifdef GL_SRC_ALPHA
	BOOST_CHECK(x != ev.src_alpha);
# endif
# ifdef GL_SRC_ALPHA_SATURATE
	BOOST_CHECK(x != ev.src_alpha_saturate);
# endif
# ifdef GL_SRC_COLOR
	BOOST_CHECK(x != ev.src_color);
# endif
# ifdef GL_ZERO
	BOOST_CHECK(x != ev.zero);
# endif
#endif

#ifdef GL_DST_ALPHA
	x = ev.dst_alpha;
# ifdef GL_CONSTANT_ALPHA
	BOOST_CHECK(x != ev.constant_alpha);
# endif
# ifdef GL_CONSTANT_COLOR
	BOOST_CHECK(x != ev.constant_color);
# endif
	BOOST_CHECK(x == ev.dst_alpha);
# ifdef GL_DST_COLOR
	BOOST_CHECK(x != ev.dst_color);
# endif
# ifdef GL_ONE
	BOOST_CHECK(x != ev.one);
# endif
# ifdef GL_ONE_MINUS_CONSTANT_ALPHA
	BOOST_CHECK(x != ev.one_minus_constant_alpha);
# endif
# ifdef GL_ONE_MINUS_CONSTANT_COLOR
	BOOST_CHECK(x != ev.one_minus_constant_color);
# endif
# ifdef GL_ONE_MINUS_DST_ALPHA
	BOOST_CHECK(x != ev.one_minus_dst_alpha);
# endif
# ifdef GL_ONE_MINUS_DST_COLOR
	BOOST_CHECK(x != ev.one_minus_dst_color);
# endif
# ifdef GL_ONE_MINUS_SRC1_ALPHA
	BOOST_CHECK(x != ev.one_minus_src1_alpha);
# endif
# ifdef GL_ONE_MINUS_SRC1_COLOR
	BOOST_CHECK(x != ev.one_minus_src1_color);
# endif
# ifdef GL_ONE_MINUS_SRC_ALPHA
	BOOST_CHECK(x != ev.one_minus_src_alpha);
# endif
# ifdef GL_ONE_MINUS_SRC_COLOR
	BOOST_CHECK(x != ev.one_minus_src_color);
# endif
# ifdef GL_SRC1_ALPHA
	BOOST_CHECK(x != ev.src1_alpha);
# endif
# ifdef GL_SRC1_COLOR
	BOOST_CHECK(x != ev.src1_color);
# endif
# ifdef GL_SRC_ALPHA
	BOOST_CHECK(x != ev.src_alpha);
# endif
# ifdef GL_SRC_ALPHA_SATURATE
	BOOST_CHECK(x != ev.src_alpha_saturate);
# endif
# ifdef GL_SRC_COLOR
	BOOST_CHECK(x != ev.src_color);
# endif
# ifdef GL_ZERO
	BOOST_CHECK(x != ev.zero);
# endif
#endif

#ifdef GL_DST_COLOR
	x = ev.dst_color;
# ifdef GL_CONSTANT_ALPHA
	BOOST_CHECK(x != ev.constant_alpha);
# endif
# ifdef GL_CONSTANT_COLOR
	BOOST_CHECK(x != ev.constant_color);
# endif
# ifdef GL_DST_ALPHA
	BOOST_CHECK(x != ev.dst_alpha);
# endif
	BOOST_CHECK(x == ev.dst_color);
# ifdef GL_ONE
	BOOST_CHECK(x != ev.one);
# endif
# ifdef GL_ONE_MINUS_CONSTANT_ALPHA
	BOOST_CHECK(x != ev.one_minus_constant_alpha);
# endif
# ifdef GL_ONE_MINUS_CONSTANT_COLOR
	BOOST_CHECK(x != ev.one_minus_constant_color);
# endif
# ifdef GL_ONE_MINUS_DST_ALPHA
	BOOST_CHECK(x != ev.one_minus_dst_alpha);
# endif
# ifdef GL_ONE_MINUS_DST_COLOR
	BOOST_CHECK(x != ev.one_minus_dst_color);
# endif
# ifdef GL_ONE_MINUS_SRC1_ALPHA
	BOOST_CHECK(x != ev.one_minus_src1_alpha);
# endif
# ifdef GL_ONE_MINUS_SRC1_COLOR
	BOOST_CHECK(x != ev.one_minus_src1_color);
# endif
# ifdef GL_ONE_MINUS_SRC_ALPHA
	BOOST_CHECK(x != ev.one_minus_src_alpha);
# endif
# ifdef GL_ONE_MINUS_SRC_COLOR
	BOOST_CHECK(x != ev.one_minus_src_color);
# endif
# ifdef GL_SRC1_ALPHA
	BOOST_CHECK(x != ev.src1_alpha);
# endif
# ifdef GL_SRC1_COLOR
	BOOST_CHECK(x != ev.src1_color);
# endif
# ifdef GL_SRC_ALPHA
	BOOST_CHECK(x != ev.src_alpha);
# endif
# ifdef GL_SRC_ALPHA_SATURATE
	BOOST_CHECK(x != ev.src_alpha_saturate);
# endif
# ifdef GL_SRC_COLOR
	BOOST_CHECK(x != ev.src_color);
# endif
# ifdef GL_ZERO
	BOOST_CHECK(x != ev.zero);
# endif
#endif

#ifdef GL_ONE
	x = ev.one;
# ifdef GL_CONSTANT_ALPHA
	BOOST_CHECK(x != ev.constant_alpha);
# endif
# ifdef GL_CONSTANT_COLOR
	BOOST_CHECK(x != ev.constant_color);
# endif
# ifdef GL_DST_ALPHA
	BOOST_CHECK(x != ev.dst_alpha);
# endif
# ifdef GL_DST_COLOR
	BOOST_CHECK(x != ev.dst_color);
# endif
	BOOST_CHECK(x == ev.one);
# ifdef GL_ONE_MINUS_CONSTANT_ALPHA
	BOOST_CHECK(x != ev.one_minus_constant_alpha);
# endif
# ifdef GL_ONE_MINUS_CONSTANT_COLOR
	BOOST_CHECK(x != ev.one_minus_constant_color);
# endif
# ifdef GL_ONE_MINUS_DST_ALPHA
	BOOST_CHECK(x != ev.one_minus_dst_alpha);
# endif
# ifdef GL_ONE_MINUS_DST_COLOR
	BOOST_CHECK(x != ev.one_minus_dst_color);
# endif
# ifdef GL_ONE_MINUS_SRC1_ALPHA
	BOOST_CHECK(x != ev.one_minus_src1_alpha);
# endif
# ifdef GL_ONE_MINUS_SRC1_COLOR
	BOOST_CHECK(x != ev.one_minus_src1_color);
# endif
# ifdef GL_ONE_MINUS_SRC_ALPHA
	BOOST_CHECK(x != ev.one_minus_src_alpha);
# endif
# ifdef GL_ONE_MINUS_SRC_COLOR
	BOOST_CHECK(x != ev.one_minus_src_color);
# endif
# ifdef GL_SRC1_ALPHA
	BOOST_CHECK(x != ev.src1_alpha);
# endif
# ifdef GL_SRC1_COLOR
	BOOST_CHECK(x != ev.src1_color);
# endif
# ifdef GL_SRC_ALPHA
	BOOST_CHECK(x != ev.src_alpha);
# endif
# ifdef GL_SRC_ALPHA_SATURATE
	BOOST_CHECK(x != ev.src_alpha_saturate);
# endif
# ifdef GL_SRC_COLOR
	BOOST_CHECK(x != ev.src_color);
# endif
# ifdef GL_ZERO
	BOOST_CHECK(x != ev.zero);
# endif
#endif

#ifdef GL_ONE_MINUS_CONSTANT_ALPHA
	x = ev.one_minus_constant_alpha;
# ifdef GL_CONSTANT_ALPHA
	BOOST_CHECK(x != ev.constant_alpha);
# endif
# ifdef GL_CONSTANT_COLOR
	BOOST_CHECK(x != ev.constant_color);
# endif
# ifdef GL_DST_ALPHA
	BOOST_CHECK(x != ev.dst_alpha);
# endif
# ifdef GL_DST_COLOR
	BOOST_CHECK(x != ev.dst_color);
# endif
# ifdef GL_ONE
	BOOST_CHECK(x != ev.one);
# endif
	BOOST_CHECK(x == ev.one_minus_constant_alpha);
# ifdef GL_ONE_MINUS_CONSTANT_COLOR
	BOOST_CHECK(x != ev.one_minus_constant_color);
# endif
# ifdef GL_ONE_MINUS_DST_ALPHA
	BOOST_CHECK(x != ev.one_minus_dst_alpha);
# endif
# ifdef GL_ONE_MINUS_DST_COLOR
	BOOST_CHECK(x != ev.one_minus_dst_color);
# endif
# ifdef GL_ONE_MINUS_SRC1_ALPHA
	BOOST_CHECK(x != ev.one_minus_src1_alpha);
# endif
# ifdef GL_ONE_MINUS_SRC1_COLOR
	BOOST_CHECK(x != ev.one_minus_src1_color);
# endif
# ifdef GL_ONE_MINUS_SRC_ALPHA
	BOOST_CHECK(x != ev.one_minus_src_alpha);
# endif
# ifdef GL_ONE_MINUS_SRC_COLOR
	BOOST_CHECK(x != ev.one_minus_src_color);
# endif
# ifdef GL_SRC1_ALPHA
	BOOST_CHECK(x != ev.src1_alpha);
# endif
# ifdef GL_SRC1_COLOR
	BOOST_CHECK(x != ev.src1_color);
# endif
# ifdef GL_SRC_ALPHA
	BOOST_CHECK(x != ev.src_alpha);
# endif
# ifdef GL_SRC_ALPHA_SATURATE
	BOOST_CHECK(x != ev.src_alpha_saturate);
# endif
# ifdef GL_SRC_COLOR
	BOOST_CHECK(x != ev.src_color);
# endif
# ifdef GL_ZERO
	BOOST_CHECK(x != ev.zero);
# endif
#endif

#ifdef GL_ONE_MINUS_CONSTANT_COLOR
	x = ev.one_minus_constant_color;
# ifdef GL_CONSTANT_ALPHA
	BOOST_CHECK(x != ev.constant_alpha);
# endif
# ifdef GL_CONSTANT_COLOR
	BOOST_CHECK(x != ev.constant_color);
# endif
# ifdef GL_DST_ALPHA
	BOOST_CHECK(x != ev.dst_alpha);
# endif
# ifdef GL_DST_COLOR
	BOOST_CHECK(x != ev.dst_color);
# endif
# ifdef GL_ONE
	BOOST_CHECK(x != ev.one);
# endif
# ifdef GL_ONE_MINUS_CONSTANT_ALPHA
	BOOST_CHECK(x != ev.one_minus_constant_alpha);
# endif
	BOOST_CHECK(x == ev.one_minus_constant_color);
# ifdef GL_ONE_MINUS_DST_ALPHA
	BOOST_CHECK(x != ev.one_minus_dst_alpha);
# endif
# ifdef GL_ONE_MINUS_DST_COLOR
	BOOST_CHECK(x != ev.one_minus_dst_color);
# endif
# ifdef GL_ONE_MINUS_SRC1_ALPHA
	BOOST_CHECK(x != ev.one_minus_src1_alpha);
# endif
# ifdef GL_ONE_MINUS_SRC1_COLOR
	BOOST_CHECK(x != ev.one_minus_src1_color);
# endif
# ifdef GL_ONE_MINUS_SRC_ALPHA
	BOOST_CHECK(x != ev.one_minus_src_alpha);
# endif
# ifdef GL_ONE_MINUS_SRC_COLOR
	BOOST_CHECK(x != ev.one_minus_src_color);
# endif
# ifdef GL_SRC1_ALPHA
	BOOST_CHECK(x != ev.src1_alpha);
# endif
# ifdef GL_SRC1_COLOR
	BOOST_CHECK(x != ev.src1_color);
# endif
# ifdef GL_SRC_ALPHA
	BOOST_CHECK(x != ev.src_alpha);
# endif
# ifdef GL_SRC_ALPHA_SATURATE
	BOOST_CHECK(x != ev.src_alpha_saturate);
# endif
# ifdef GL_SRC_COLOR
	BOOST_CHECK(x != ev.src_color);
# endif
# ifdef GL_ZERO
	BOOST_CHECK(x != ev.zero);
# endif
#endif

#ifdef GL_ONE_MINUS_DST_ALPHA
	x = ev.one_minus_dst_alpha;
# ifdef GL_CONSTANT_ALPHA
	BOOST_CHECK(x != ev.constant_alpha);
# endif
# ifdef GL_CONSTANT_COLOR
	BOOST_CHECK(x != ev.constant_color);
# endif
# ifdef GL_DST_ALPHA
	BOOST_CHECK(x != ev.dst_alpha);
# endif
# ifdef GL_DST_COLOR
	BOOST_CHECK(x != ev.dst_color);
# endif
# ifdef GL_ONE
	BOOST_CHECK(x != ev.one);
# endif
# ifdef GL_ONE_MINUS_CONSTANT_ALPHA
	BOOST_CHECK(x != ev.one_minus_constant_alpha);
# endif
# ifdef GL_ONE_MINUS_CONSTANT_COLOR
	BOOST_CHECK(x != ev.one_minus_constant_color);
# endif
	BOOST_CHECK(x == ev.one_minus_dst_alpha);
# ifdef GL_ONE_MINUS_DST_COLOR
	BOOST_CHECK(x != ev.one_minus_dst_color);
# endif
# ifdef GL_ONE_MINUS_SRC1_ALPHA
	BOOST_CHECK(x != ev.one_minus_src1_alpha);
# endif
# ifdef GL_ONE_MINUS_SRC1_COLOR
	BOOST_CHECK(x != ev.one_minus_src1_color);
# endif
# ifdef GL_ONE_MINUS_SRC_ALPHA
	BOOST_CHECK(x != ev.one_minus_src_alpha);
# endif
# ifdef GL_ONE_MINUS_SRC_COLOR
	BOOST_CHECK(x != ev.one_minus_src_color);
# endif
# ifdef GL_SRC1_ALPHA
	BOOST_CHECK(x != ev.src1_alpha);
# endif
# ifdef GL_SRC1_COLOR
	BOOST_CHECK(x != ev.src1_color);
# endif
# ifdef GL_SRC_ALPHA
	BOOST_CHECK(x != ev.src_alpha);
# endif
# ifdef GL_SRC_ALPHA_SATURATE
	BOOST_CHECK(x != ev.src_alpha_saturate);
# endif
# ifdef GL_SRC_COLOR
	BOOST_CHECK(x != ev.src_color);
# endif
# ifdef GL_ZERO
	BOOST_CHECK(x != ev.zero);
# endif
#endif

#ifdef GL_ONE_MINUS_DST_COLOR
	x = ev.one_minus_dst_color;
# ifdef GL_CONSTANT_ALPHA
	BOOST_CHECK(x != ev.constant_alpha);
# endif
# ifdef GL_CONSTANT_COLOR
	BOOST_CHECK(x != ev.constant_color);
# endif
# ifdef GL_DST_ALPHA
	BOOST_CHECK(x != ev.dst_alpha);
# endif
# ifdef GL_DST_COLOR
	BOOST_CHECK(x != ev.dst_color);
# endif
# ifdef GL_ONE
	BOOST_CHECK(x != ev.one);
# endif
# ifdef GL_ONE_MINUS_CONSTANT_ALPHA
	BOOST_CHECK(x != ev.one_minus_constant_alpha);
# endif
# ifdef GL_ONE_MINUS_CONSTANT_COLOR
	BOOST_CHECK(x != ev.one_minus_constant_color);
# endif
# ifdef GL_ONE_MINUS_DST_ALPHA
	BOOST_CHECK(x != ev.one_minus_dst_alpha);
# endif
	BOOST_CHECK(x == ev.one_minus_dst_color);
# ifdef GL_ONE_MINUS_SRC1_ALPHA
	BOOST_CHECK(x != ev.one_minus_src1_alpha);
# endif
# ifdef GL_ONE_MINUS_SRC1_COLOR
	BOOST_CHECK(x != ev.one_minus_src1_color);
# endif
# ifdef GL_ONE_MINUS_SRC_ALPHA
	BOOST_CHECK(x != ev.one_minus_src_alpha);
# endif
# ifdef GL_ONE_MINUS_SRC_COLOR
	BOOST_CHECK(x != ev.one_minus_src_color);
# endif
# ifdef GL_SRC1_ALPHA
	BOOST_CHECK(x != ev.src1_alpha);
# endif
# ifdef GL_SRC1_COLOR
	BOOST_CHECK(x != ev.src1_color);
# endif
# ifdef GL_SRC_ALPHA
	BOOST_CHECK(x != ev.src_alpha);
# endif
# ifdef GL_SRC_ALPHA_SATURATE
	BOOST_CHECK(x != ev.src_alpha_saturate);
# endif
# ifdef GL_SRC_COLOR
	BOOST_CHECK(x != ev.src_color);
# endif
# ifdef GL_ZERO
	BOOST_CHECK(x != ev.zero);
# endif
#endif

#ifdef GL_ONE_MINUS_SRC1_ALPHA
	x = ev.one_minus_src1_alpha;
# ifdef GL_CONSTANT_ALPHA
	BOOST_CHECK(x != ev.constant_alpha);
# endif
# ifdef GL_CONSTANT_COLOR
	BOOST_CHECK(x != ev.constant_color);
# endif
# ifdef GL_DST_ALPHA
	BOOST_CHECK(x != ev.dst_alpha);
# endif
# ifdef GL_DST_COLOR
	BOOST_CHECK(x != ev.dst_color);
# endif
# ifdef GL_ONE
	BOOST_CHECK(x != ev.one);
# endif
# ifdef GL_ONE_MINUS_CONSTANT_ALPHA
	BOOST_CHECK(x != ev.one_minus_constant_alpha);
# endif
# ifdef GL_ONE_MINUS_CONSTANT_COLOR
	BOOST_CHECK(x != ev.one_minus_constant_color);
# endif
# ifdef GL_ONE_MINUS_DST_ALPHA
	BOOST_CHECK(x != ev.one_minus_dst_alpha);
# endif
# ifdef GL_ONE_MINUS_DST_COLOR
	BOOST_CHECK(x != ev.one_minus_dst_color);
# endif
	BOOST_CHECK(x == ev.one_minus_src1_alpha);
# ifdef GL_ONE_MINUS_SRC1_COLOR
	BOOST_CHECK(x != ev.one_minus_src1_color);
# endif
# ifdef GL_ONE_MINUS_SRC_ALPHA
	BOOST_CHECK(x != ev.one_minus_src_alpha);
# endif
# ifdef GL_ONE_MINUS_SRC_COLOR
	BOOST_CHECK(x != ev.one_minus_src_color);
# endif
# ifdef GL_SRC1_ALPHA
	BOOST_CHECK(x != ev.src1_alpha);
# endif
# ifdef GL_SRC1_COLOR
	BOOST_CHECK(x != ev.src1_color);
# endif
# ifdef GL_SRC_ALPHA
	BOOST_CHECK(x != ev.src_alpha);
# endif
# ifdef GL_SRC_ALPHA_SATURATE
	BOOST_CHECK(x != ev.src_alpha_saturate);
# endif
# ifdef GL_SRC_COLOR
	BOOST_CHECK(x != ev.src_color);
# endif
# ifdef GL_ZERO
	BOOST_CHECK(x != ev.zero);
# endif
#endif

#ifdef GL_ONE_MINUS_SRC1_COLOR
	x = ev.one_minus_src1_color;
# ifdef GL_CONSTANT_ALPHA
	BOOST_CHECK(x != ev.constant_alpha);
# endif
# ifdef GL_CONSTANT_COLOR
	BOOST_CHECK(x != ev.constant_color);
# endif
# ifdef GL_DST_ALPHA
	BOOST_CHECK(x != ev.dst_alpha);
# endif
# ifdef GL_DST_COLOR
	BOOST_CHECK(x != ev.dst_color);
# endif
# ifdef GL_ONE
	BOOST_CHECK(x != ev.one);
# endif
# ifdef GL_ONE_MINUS_CONSTANT_ALPHA
	BOOST_CHECK(x != ev.one_minus_constant_alpha);
# endif
# ifdef GL_ONE_MINUS_CONSTANT_COLOR
	BOOST_CHECK(x != ev.one_minus_constant_color);
# endif
# ifdef GL_ONE_MINUS_DST_ALPHA
	BOOST_CHECK(x != ev.one_minus_dst_alpha);
# endif
# ifdef GL_ONE_MINUS_DST_COLOR
	BOOST_CHECK(x != ev.one_minus_dst_color);
# endif
# ifdef GL_ONE_MINUS_SRC1_ALPHA
	BOOST_CHECK(x != ev.one_minus_src1_alpha);
# endif
	BOOST_CHECK(x == ev.one_minus_src1_color);
# ifdef GL_ONE_MINUS_SRC_ALPHA
	BOOST_CHECK(x != ev.one_minus_src_alpha);
# endif
# ifdef GL_ONE_MINUS_SRC_COLOR
	BOOST_CHECK(x != ev.one_minus_src_color);
# endif
# ifdef GL_SRC1_ALPHA
	BOOST_CHECK(x != ev.src1_alpha);
# endif
# ifdef GL_SRC1_COLOR
	BOOST_CHECK(x != ev.src1_color);
# endif
# ifdef GL_SRC_ALPHA
	BOOST_CHECK(x != ev.src_alpha);
# endif
# ifdef GL_SRC_ALPHA_SATURATE
	BOOST_CHECK(x != ev.src_alpha_saturate);
# endif
# ifdef GL_SRC_COLOR
	BOOST_CHECK(x != ev.src_color);
# endif
# ifdef GL_ZERO
	BOOST_CHECK(x != ev.zero);
# endif
#endif

#ifdef GL_ONE_MINUS_SRC_ALPHA
	x = ev.one_minus_src_alpha;
# ifdef GL_CONSTANT_ALPHA
	BOOST_CHECK(x != ev.constant_alpha);
# endif
# ifdef GL_CONSTANT_COLOR
	BOOST_CHECK(x != ev.constant_color);
# endif
# ifdef GL_DST_ALPHA
	BOOST_CHECK(x != ev.dst_alpha);
# endif
# ifdef GL_DST_COLOR
	BOOST_CHECK(x != ev.dst_color);
# endif
# ifdef GL_ONE
	BOOST_CHECK(x != ev.one);
# endif
# ifdef GL_ONE_MINUS_CONSTANT_ALPHA
	BOOST_CHECK(x != ev.one_minus_constant_alpha);
# endif
# ifdef GL_ONE_MINUS_CONSTANT_COLOR
	BOOST_CHECK(x != ev.one_minus_constant_color);
# endif
# ifdef GL_ONE_MINUS_DST_ALPHA
	BOOST_CHECK(x != ev.one_minus_dst_alpha);
# endif
# ifdef GL_ONE_MINUS_DST_COLOR
	BOOST_CHECK(x != ev.one_minus_dst_color);
# endif
# ifdef GL_ONE_MINUS_SRC1_ALPHA
	BOOST_CHECK(x != ev.one_minus_src1_alpha);
# endif
# ifdef GL_ONE_MINUS_SRC1_COLOR
	BOOST_CHECK(x != ev.one_minus_src1_color);
# endif
	BOOST_CHECK(x == ev.one_minus_src_alpha);
# ifdef GL_ONE_MINUS_SRC_COLOR
	BOOST_CHECK(x != ev.one_minus_src_color);
# endif
# ifdef GL_SRC1_ALPHA
	BOOST_CHECK(x != ev.src1_alpha);
# endif
# ifdef GL_SRC1_COLOR
	BOOST_CHECK(x != ev.src1_color);
# endif
# ifdef GL_SRC_ALPHA
	BOOST_CHECK(x != ev.src_alpha);
# endif
# ifdef GL_SRC_ALPHA_SATURATE
	BOOST_CHECK(x != ev.src_alpha_saturate);
# endif
# ifdef GL_SRC_COLOR
	BOOST_CHECK(x != ev.src_color);
# endif
# ifdef GL_ZERO
	BOOST_CHECK(x != ev.zero);
# endif
#endif

#ifdef GL_ONE_MINUS_SRC_COLOR
	x = ev.one_minus_src_color;
# ifdef GL_CONSTANT_ALPHA
	BOOST_CHECK(x != ev.constant_alpha);
# endif
# ifdef GL_CONSTANT_COLOR
	BOOST_CHECK(x != ev.constant_color);
# endif
# ifdef GL_DST_ALPHA
	BOOST_CHECK(x != ev.dst_alpha);
# endif
# ifdef GL_DST_COLOR
	BOOST_CHECK(x != ev.dst_color);
# endif
# ifdef GL_ONE
	BOOST_CHECK(x != ev.one);
# endif
# ifdef GL_ONE_MINUS_CONSTANT_ALPHA
	BOOST_CHECK(x != ev.one_minus_constant_alpha);
# endif
# ifdef GL_ONE_MINUS_CONSTANT_COLOR
	BOOST_CHECK(x != ev.one_minus_constant_color);
# endif
# ifdef GL_ONE_MINUS_DST_ALPHA
	BOOST_CHECK(x != ev.one_minus_dst_alpha);
# endif
# ifdef GL_ONE_MINUS_DST_COLOR
	BOOST_CHECK(x != ev.one_minus_dst_color);
# endif
# ifdef GL_ONE_MINUS_SRC1_ALPHA
	BOOST_CHECK(x != ev.one_minus_src1_alpha);
# endif
# ifdef GL_ONE_MINUS_SRC1_COLOR
	BOOST_CHECK(x != ev.one_minus_src1_color);
# endif
# ifdef GL_ONE_MINUS_SRC_ALPHA
	BOOST_CHECK(x != ev.one_minus_src_alpha);
# endif
	BOOST_CHECK(x == ev.one_minus_src_color);
# ifdef GL_SRC1_ALPHA
	BOOST_CHECK(x != ev.src1_alpha);
# endif
# ifdef GL_SRC1_COLOR
	BOOST_CHECK(x != ev.src1_color);
# endif
# ifdef GL_SRC_ALPHA
	BOOST_CHECK(x != ev.src_alpha);
# endif
# ifdef GL_SRC_ALPHA_SATURATE
	BOOST_CHECK(x != ev.src_alpha_saturate);
# endif
# ifdef GL_SRC_COLOR
	BOOST_CHECK(x != ev.src_color);
# endif
# ifdef GL_ZERO
	BOOST_CHECK(x != ev.zero);
# endif
#endif

#ifdef GL_SRC1_ALPHA
	x = ev.src1_alpha;
# ifdef GL_CONSTANT_ALPHA
	BOOST_CHECK(x != ev.constant_alpha);
# endif
# ifdef GL_CONSTANT_COLOR
	BOOST_CHECK(x != ev.constant_color);
# endif
# ifdef GL_DST_ALPHA
	BOOST_CHECK(x != ev.dst_alpha);
# endif
# ifdef GL_DST_COLOR
	BOOST_CHECK(x != ev.dst_color);
# endif
# ifdef GL_ONE
	BOOST_CHECK(x != ev.one);
# endif
# ifdef GL_ONE_MINUS_CONSTANT_ALPHA
	BOOST_CHECK(x != ev.one_minus_constant_alpha);
# endif
# ifdef GL_ONE_MINUS_CONSTANT_COLOR
	BOOST_CHECK(x != ev.one_minus_constant_color);
# endif
# ifdef GL_ONE_MINUS_DST_ALPHA
	BOOST_CHECK(x != ev.one_minus_dst_alpha);
# endif
# ifdef GL_ONE_MINUS_DST_COLOR
	BOOST_CHECK(x != ev.one_minus_dst_color);
# endif
# ifdef GL_ONE_MINUS_SRC1_ALPHA
	BOOST_CHECK(x != ev.one_minus_src1_alpha);
# endif
# ifdef GL_ONE_MINUS_SRC1_COLOR
	BOOST_CHECK(x != ev.one_minus_src1_color);
# endif
# ifdef GL_ONE_MINUS_SRC_ALPHA
	BOOST_CHECK(x != ev.one_minus_src_alpha);
# endif
# ifdef GL_ONE_MINUS_SRC_COLOR
	BOOST_CHECK(x != ev.one_minus_src_color);
# endif
	BOOST_CHECK(x == ev.src1_alpha);
# ifdef GL_SRC1_COLOR
	BOOST_CHECK(x != ev.src1_color);
# endif
# ifdef GL_SRC_ALPHA
	BOOST_CHECK(x != ev.src_alpha);
# endif
# ifdef GL_SRC_ALPHA_SATURATE
	BOOST_CHECK(x != ev.src_alpha_saturate);
# endif
# ifdef GL_SRC_COLOR
	BOOST_CHECK(x != ev.src_color);
# endif
# ifdef GL_ZERO
	BOOST_CHECK(x != ev.zero);
# endif
#endif

#ifdef GL_SRC1_COLOR
	x = ev.src1_color;
# ifdef GL_CONSTANT_ALPHA
	BOOST_CHECK(x != ev.constant_alpha);
# endif
# ifdef GL_CONSTANT_COLOR
	BOOST_CHECK(x != ev.constant_color);
# endif
# ifdef GL_DST_ALPHA
	BOOST_CHECK(x != ev.dst_alpha);
# endif
# ifdef GL_DST_COLOR
	BOOST_CHECK(x != ev.dst_color);
# endif
# ifdef GL_ONE
	BOOST_CHECK(x != ev.one);
# endif
# ifdef GL_ONE_MINUS_CONSTANT_ALPHA
	BOOST_CHECK(x != ev.one_minus_constant_alpha);
# endif
# ifdef GL_ONE_MINUS_CONSTANT_COLOR
	BOOST_CHECK(x != ev.one_minus_constant_color);
# endif
# ifdef GL_ONE_MINUS_DST_ALPHA
	BOOST_CHECK(x != ev.one_minus_dst_alpha);
# endif
# ifdef GL_ONE_MINUS_DST_COLOR
	BOOST_CHECK(x != ev.one_minus_dst_color);
# endif
# ifdef GL_ONE_MINUS_SRC1_ALPHA
	BOOST_CHECK(x != ev.one_minus_src1_alpha);
# endif
# ifdef GL_ONE_MINUS_SRC1_COLOR
	BOOST_CHECK(x != ev.one_minus_src1_color);
# endif
# ifdef GL_ONE_MINUS_SRC_ALPHA
	BOOST_CHECK(x != ev.one_minus_src_alpha);
# endif
# ifdef GL_ONE_MINUS_SRC_COLOR
	BOOST_CHECK(x != ev.one_minus_src_color);
# endif
# ifdef GL_SRC1_ALPHA
	BOOST_CHECK(x != ev.src1_alpha);
# endif
	BOOST_CHECK(x == ev.src1_color);
# ifdef GL_SRC_ALPHA
	BOOST_CHECK(x != ev.src_alpha);
# endif
# ifdef GL_SRC_ALPHA_SATURATE
	BOOST_CHECK(x != ev.src_alpha_saturate);
# endif
# ifdef GL_SRC_COLOR
	BOOST_CHECK(x != ev.src_color);
# endif
# ifdef GL_ZERO
	BOOST_CHECK(x != ev.zero);
# endif
#endif

#ifdef GL_SRC_ALPHA
	x = ev.src_alpha;
# ifdef GL_CONSTANT_ALPHA
	BOOST_CHECK(x != ev.constant_alpha);
# endif
# ifdef GL_CONSTANT_COLOR
	BOOST_CHECK(x != ev.constant_color);
# endif
# ifdef GL_DST_ALPHA
	BOOST_CHECK(x != ev.dst_alpha);
# endif
# ifdef GL_DST_COLOR
	BOOST_CHECK(x != ev.dst_color);
# endif
# ifdef GL_ONE
	BOOST_CHECK(x != ev.one);
# endif
# ifdef GL_ONE_MINUS_CONSTANT_ALPHA
	BOOST_CHECK(x != ev.one_minus_constant_alpha);
# endif
# ifdef GL_ONE_MINUS_CONSTANT_COLOR
	BOOST_CHECK(x != ev.one_minus_constant_color);
# endif
# ifdef GL_ONE_MINUS_DST_ALPHA
	BOOST_CHECK(x != ev.one_minus_dst_alpha);
# endif
# ifdef GL_ONE_MINUS_DST_COLOR
	BOOST_CHECK(x != ev.one_minus_dst_color);
# endif
# ifdef GL_ONE_MINUS_SRC1_ALPHA
	BOOST_CHECK(x != ev.one_minus_src1_alpha);
# endif
# ifdef GL_ONE_MINUS_SRC1_COLOR
	BOOST_CHECK(x != ev.one_minus_src1_color);
# endif
# ifdef GL_ONE_MINUS_SRC_ALPHA
	BOOST_CHECK(x != ev.one_minus_src_alpha);
# endif
# ifdef GL_ONE_MINUS_SRC_COLOR
	BOOST_CHECK(x != ev.one_minus_src_color);
# endif
# ifdef GL_SRC1_ALPHA
	BOOST_CHECK(x != ev.src1_alpha);
# endif
# ifdef GL_SRC1_COLOR
	BOOST_CHECK(x != ev.src1_color);
# endif
	BOOST_CHECK(x == ev.src_alpha);
# ifdef GL_SRC_ALPHA_SATURATE
	BOOST_CHECK(x != ev.src_alpha_saturate);
# endif
# ifdef GL_SRC_COLOR
	BOOST_CHECK(x != ev.src_color);
# endif
# ifdef GL_ZERO
	BOOST_CHECK(x != ev.zero);
# endif
#endif

#ifdef GL_SRC_ALPHA_SATURATE
	x = ev.src_alpha_saturate;
# ifdef GL_CONSTANT_ALPHA
	BOOST_CHECK(x != ev.constant_alpha);
# endif
# ifdef GL_CONSTANT_COLOR
	BOOST_CHECK(x != ev.constant_color);
# endif
# ifdef GL_DST_ALPHA
	BOOST_CHECK(x != ev.dst_alpha);
# endif
# ifdef GL_DST_COLOR
	BOOST_CHECK(x != ev.dst_color);
# endif
# ifdef GL_ONE
	BOOST_CHECK(x != ev.one);
# endif
# ifdef GL_ONE_MINUS_CONSTANT_ALPHA
	BOOST_CHECK(x != ev.one_minus_constant_alpha);
# endif
# ifdef GL_ONE_MINUS_CONSTANT_COLOR
	BOOST_CHECK(x != ev.one_minus_constant_color);
# endif
# ifdef GL_ONE_MINUS_DST_ALPHA
	BOOST_CHECK(x != ev.one_minus_dst_alpha);
# endif
# ifdef GL_ONE_MINUS_DST_COLOR
	BOOST_CHECK(x != ev.one_minus_dst_color);
# endif
# ifdef GL_ONE_MINUS_SRC1_ALPHA
	BOOST_CHECK(x != ev.one_minus_src1_alpha);
# endif
# ifdef GL_ONE_MINUS_SRC1_COLOR
	BOOST_CHECK(x != ev.one_minus_src1_color);
# endif
# ifdef GL_ONE_MINUS_SRC_ALPHA
	BOOST_CHECK(x != ev.one_minus_src_alpha);
# endif
# ifdef GL_ONE_MINUS_SRC_COLOR
	BOOST_CHECK(x != ev.one_minus_src_color);
# endif
# ifdef GL_SRC1_ALPHA
	BOOST_CHECK(x != ev.src1_alpha);
# endif
# ifdef GL_SRC1_COLOR
	BOOST_CHECK(x != ev.src1_color);
# endif
# ifdef GL_SRC_ALPHA
	BOOST_CHECK(x != ev.src_alpha);
# endif
	BOOST_CHECK(x == ev.src_alpha_saturate);
# ifdef GL_SRC_COLOR
	BOOST_CHECK(x != ev.src_color);
# endif
# ifdef GL_ZERO
	BOOST_CHECK(x != ev.zero);
# endif
#endif

#ifdef GL_SRC_COLOR
	x = ev.src_color;
# ifdef GL_CONSTANT_ALPHA
	BOOST_CHECK(x != ev.constant_alpha);
# endif
# ifdef GL_CONSTANT_COLOR
	BOOST_CHECK(x != ev.constant_color);
# endif
# ifdef GL_DST_ALPHA
	BOOST_CHECK(x != ev.dst_alpha);
# endif
# ifdef GL_DST_COLOR
	BOOST_CHECK(x != ev.dst_color);
# endif
# ifdef GL_ONE
	BOOST_CHECK(x != ev.one);
# endif
# ifdef GL_ONE_MINUS_CONSTANT_ALPHA
	BOOST_CHECK(x != ev.one_minus_constant_alpha);
# endif
# ifdef GL_ONE_MINUS_CONSTANT_COLOR
	BOOST_CHECK(x != ev.one_minus_constant_color);
# endif
# ifdef GL_ONE_MINUS_DST_ALPHA
	BOOST_CHECK(x != ev.one_minus_dst_alpha);
# endif
# ifdef GL_ONE_MINUS_DST_COLOR
	BOOST_CHECK(x != ev.one_minus_dst_color);
# endif
# ifdef GL_ONE_MINUS_SRC1_ALPHA
	BOOST_CHECK(x != ev.one_minus_src1_alpha);
# endif
# ifdef GL_ONE_MINUS_SRC1_COLOR
	BOOST_CHECK(x != ev.one_minus_src1_color);
# endif
# ifdef GL_ONE_MINUS_SRC_ALPHA
	BOOST_CHECK(x != ev.one_minus_src_alpha);
# endif
# ifdef GL_ONE_MINUS_SRC_COLOR
	BOOST_CHECK(x != ev.one_minus_src_color);
# endif
# ifdef GL_SRC1_ALPHA
	BOOST_CHECK(x != ev.src1_alpha);
# endif
# ifdef GL_SRC1_COLOR
	BOOST_CHECK(x != ev.src1_color);
# endif
# ifdef GL_SRC_ALPHA
	BOOST_CHECK(x != ev.src_alpha);
# endif
# ifdef GL_SRC_ALPHA_SATURATE
	BOOST_CHECK(x != ev.src_alpha_saturate);
# endif
	BOOST_CHECK(x == ev.src_color);
# ifdef GL_ZERO
	BOOST_CHECK(x != ev.zero);
# endif
#endif

#ifdef GL_ZERO
	x = ev.zero;
# ifdef GL_CONSTANT_ALPHA
	BOOST_CHECK(x != ev.constant_alpha);
# endif
# ifdef GL_CONSTANT_COLOR
	BOOST_CHECK(x != ev.constant_color);
# endif
# ifdef GL_DST_ALPHA
	BOOST_CHECK(x != ev.dst_alpha);
# endif
# ifdef GL_DST_COLOR
	BOOST_CHECK(x != ev.dst_color);
# endif
# ifdef GL_ONE
	BOOST_CHECK(x != ev.one);
# endif
# ifdef GL_ONE_MINUS_CONSTANT_ALPHA
	BOOST_CHECK(x != ev.one_minus_constant_alpha);
# endif
# ifdef GL_ONE_MINUS_CONSTANT_COLOR
	BOOST_CHECK(x != ev.one_minus_constant_color);
# endif
# ifdef GL_ONE_MINUS_DST_ALPHA
	BOOST_CHECK(x != ev.one_minus_dst_alpha);
# endif
# ifdef GL_ONE_MINUS_DST_COLOR
	BOOST_CHECK(x != ev.one_minus_dst_color);
# endif
# ifdef GL_ONE_MINUS_SRC1_ALPHA
	BOOST_CHECK(x != ev.one_minus_src1_alpha);
# endif
# ifdef GL_ONE_MINUS_SRC1_COLOR
	BOOST_CHECK(x != ev.one_minus_src1_color);
# endif
# ifdef GL_ONE_MINUS_SRC_ALPHA
	BOOST_CHECK(x != ev.one_minus_src_alpha);
# endif
# ifdef GL_ONE_MINUS_SRC_COLOR
	BOOST_CHECK(x != ev.one_minus_src_color);
# endif
# ifdef GL_SRC1_ALPHA
	BOOST_CHECK(x != ev.src1_alpha);
# endif
# ifdef GL_SRC1_COLOR
	BOOST_CHECK(x != ev.src1_color);
# endif
# ifdef GL_SRC_ALPHA
	BOOST_CHECK(x != ev.src_alpha);
# endif
# ifdef GL_SRC_ALPHA_SATURATE
	BOOST_CHECK(x != ev.src_alpha_saturate);
# endif
# ifdef GL_SRC_COLOR
	BOOST_CHECK(x != ev.src_color);
# endif
	BOOST_CHECK(x == ev.zero);
#endif
}

BOOST_AUTO_TEST_CASE(enum_blend_function_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	blend_function x;
	(void)x;

#ifdef GL_CONSTANT_ALPHA
	x = ev.constant_alpha;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"CONSTANT_ALPHA"
	) == 0);
#endif

#ifdef GL_CONSTANT_COLOR
	x = ev.constant_color;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"CONSTANT_COLOR"
	) == 0);
#endif

#ifdef GL_DST_ALPHA
	x = ev.dst_alpha;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DST_ALPHA"
	) == 0);
#endif

#ifdef GL_DST_COLOR
	x = ev.dst_color;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DST_COLOR"
	) == 0);
#endif

#ifdef GL_ONE
	x = ev.one;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ONE"
	) == 0);
#endif

#ifdef GL_ONE_MINUS_CONSTANT_ALPHA
	x = ev.one_minus_constant_alpha;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ONE_MINUS_CONSTANT_ALPHA"
	) == 0);
#endif

#ifdef GL_ONE_MINUS_CONSTANT_COLOR
	x = ev.one_minus_constant_color;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ONE_MINUS_CONSTANT_COLOR"
	) == 0);
#endif

#ifdef GL_ONE_MINUS_DST_ALPHA
	x = ev.one_minus_dst_alpha;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ONE_MINUS_DST_ALPHA"
	) == 0);
#endif

#ifdef GL_ONE_MINUS_DST_COLOR
	x = ev.one_minus_dst_color;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ONE_MINUS_DST_COLOR"
	) == 0);
#endif

#ifdef GL_ONE_MINUS_SRC1_ALPHA
	x = ev.one_minus_src1_alpha;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ONE_MINUS_SRC1_ALPHA"
	) == 0);
#endif

#ifdef GL_ONE_MINUS_SRC1_COLOR
	x = ev.one_minus_src1_color;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ONE_MINUS_SRC1_COLOR"
	) == 0);
#endif

#ifdef GL_ONE_MINUS_SRC_ALPHA
	x = ev.one_minus_src_alpha;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ONE_MINUS_SRC_ALPHA"
	) == 0);
#endif

#ifdef GL_ONE_MINUS_SRC_COLOR
	x = ev.one_minus_src_color;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ONE_MINUS_SRC_COLOR"
	) == 0);
#endif

#ifdef GL_SRC1_ALPHA
	x = ev.src1_alpha;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SRC1_ALPHA"
	) == 0);
#endif

#ifdef GL_SRC1_COLOR
	x = ev.src1_color;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SRC1_COLOR"
	) == 0);
#endif

#ifdef GL_SRC_ALPHA
	x = ev.src_alpha;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SRC_ALPHA"
	) == 0);
#endif

#ifdef GL_SRC_ALPHA_SATURATE
	x = ev.src_alpha_saturate;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SRC_ALPHA_SATURATE"
	) == 0);
#endif

#ifdef GL_SRC_COLOR
	x = ev.src_color;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SRC_COLOR"
	) == 0);
#endif

#ifdef GL_ZERO
	x = ev.zero;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ZERO"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_blend_function_range)
{
	using namespace oglplus;
	blend_function x;
	(void)x;
	auto count = enum_value_range(x).size();

#ifdef GL_CONSTANT_ALPHA
{
	--count;
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_CONSTANT_ALPHA
	) != r.end());
}
#endif

#ifdef GL_CONSTANT_COLOR
{
	--count;
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_CONSTANT_COLOR
	) != r.end());
}
#endif

#ifdef GL_DST_ALPHA
{
	--count;
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_DST_ALPHA
	) != r.end());
}
#endif

#ifdef GL_DST_COLOR
{
	--count;
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_DST_COLOR
	) != r.end());
}
#endif

#ifdef GL_ONE
{
	--count;
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_ONE
	) != r.end());
}
#endif

#ifdef GL_ONE_MINUS_CONSTANT_ALPHA
{
	--count;
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_ONE_MINUS_CONSTANT_ALPHA
	) != r.end());
}
#endif

#ifdef GL_ONE_MINUS_CONSTANT_COLOR
{
	--count;
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_ONE_MINUS_CONSTANT_COLOR
	) != r.end());
}
#endif

#ifdef GL_ONE_MINUS_DST_ALPHA
{
	--count;
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_ONE_MINUS_DST_ALPHA
	) != r.end());
}
#endif

#ifdef GL_ONE_MINUS_DST_COLOR
{
	--count;
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_ONE_MINUS_DST_COLOR
	) != r.end());
}
#endif

#ifdef GL_ONE_MINUS_SRC1_ALPHA
{
	--count;
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_ONE_MINUS_SRC1_ALPHA
	) != r.end());
}
#endif

#ifdef GL_ONE_MINUS_SRC1_COLOR
{
	--count;
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_ONE_MINUS_SRC1_COLOR
	) != r.end());
}
#endif

#ifdef GL_ONE_MINUS_SRC_ALPHA
{
	--count;
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_ONE_MINUS_SRC_ALPHA
	) != r.end());
}
#endif

#ifdef GL_ONE_MINUS_SRC_COLOR
{
	--count;
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_ONE_MINUS_SRC_COLOR
	) != r.end());
}
#endif

#ifdef GL_SRC1_ALPHA
{
	--count;
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_SRC1_ALPHA
	) != r.end());
}
#endif

#ifdef GL_SRC1_COLOR
{
	--count;
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_SRC1_COLOR
	) != r.end());
}
#endif

#ifdef GL_SRC_ALPHA
{
	--count;
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_SRC_ALPHA
	) != r.end());
}
#endif

#ifdef GL_SRC_ALPHA_SATURATE
{
	--count;
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_SRC_ALPHA_SATURATE
	) != r.end());
}
#endif

#ifdef GL_SRC_COLOR
{
	--count;
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_SRC_COLOR
	) != r.end());
}
#endif

#ifdef GL_ZERO
{
	--count;
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_ZERO
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_SUITE_END()
