//  File test/oglplus/enums/path_color_nv.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_path_color_nv

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_path_color_nv_tests)

BOOST_AUTO_TEST_CASE(enum_path_color_nv_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	path_color_nv x;
	(void)x;

#ifdef GL_PRIMARY_COLOR_NV
	x = ev.primary_color_nv;
	BOOST_CHECK(x == ev.primary_color_nv);
# ifdef GL_SECONDARY_COLOR_NV
	BOOST_CHECK(x != ev.secondary_color_nv);
# endif
#endif

#ifdef GL_SECONDARY_COLOR_NV
	x = ev.secondary_color_nv;
	BOOST_CHECK(x == ev.secondary_color_nv);
#endif
}

BOOST_AUTO_TEST_CASE(enum_path_color_nv_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	path_color_nv x;
	(void)x;

#ifdef GL_PRIMARY_COLOR_NV
	x = ev.primary_color_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PRIMARY_COLOR_NV"
	) == 0);
#endif

#ifdef GL_SECONDARY_COLOR_NV
	x = ev.secondary_color_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SECONDARY_COLOR_NV"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_path_color_nv_range)
{
	using namespace oglplus;
	auto count = enum_value_range<path_color_nv>().size();

#ifdef GL_PRIMARY_COLOR_NV
{
	--count;
	auto r = enum_value_range<path_color_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_color_nv(GL_PRIMARY_COLOR_NV)
	) != r.end());
}
#endif

#ifdef GL_SECONDARY_COLOR_NV
{
	--count;
	auto r = enum_value_range<path_color_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_color_nv(GL_SECONDARY_COLOR_NV)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_path_color_nv_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	path_color_nv x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_PRIMARY_COLOR_NV
	x = ev.primary_color_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.primary_color_nv);
#endif

#ifdef GL_SECONDARY_COLOR_NV
	x = ev.secondary_color_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.secondary_color_nv);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
