//  File test/oglplus/enums/path_font_style_nv.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_path_font_style_nv

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_path_font_style_nv_tests)

BOOST_AUTO_TEST_CASE(enum_path_font_style_nv_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	path_font_style_nv x;
	(void)x;

#ifdef GL_BOLD_BIT_NV
	x = ev.bold_bit_nv;
	BOOST_CHECK(x == ev.bold_bit_nv);
# ifdef GL_ITALIC_BIT_NV
	BOOST_CHECK(x != ev.italic_bit_nv);
# endif
#endif

#ifdef GL_ITALIC_BIT_NV
	x = ev.italic_bit_nv;
	BOOST_CHECK(x == ev.italic_bit_nv);
#endif
}

BOOST_AUTO_TEST_CASE(enum_path_font_style_nv_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	path_font_style_nv x;
	(void)x;

#ifdef GL_BOLD_BIT_NV
	x = ev.bold_bit_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"BOLD_BIT_NV"
	) == 0);
#endif

#ifdef GL_ITALIC_BIT_NV
	x = ev.italic_bit_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ITALIC_BIT_NV"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_path_font_style_nv_range)
{
	using namespace oglplus;
	auto count = enum_value_range<path_font_style_nv>().size();

#ifdef GL_BOLD_BIT_NV
{
	--count;
	auto r = enum_value_range<path_font_style_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_font_style_nv(GL_BOLD_BIT_NV)
	) != r.end());
}
#endif

#ifdef GL_ITALIC_BIT_NV
{
	--count;
	auto r = enum_value_range<path_font_style_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_font_style_nv(GL_ITALIC_BIT_NV)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_path_font_style_nv_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	path_font_style_nv x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_BOLD_BIT_NV
	x = ev.bold_bit_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.bold_bit_nv);
#endif

#ifdef GL_ITALIC_BIT_NV
	x = ev.italic_bit_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.italic_bit_nv);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
