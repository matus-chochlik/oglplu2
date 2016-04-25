//  File test/oglplus/enums/polygon_mode.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_polygon_mode

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_polygon_mode_tests)

BOOST_AUTO_TEST_CASE(enum_polygon_mode_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	polygon_mode x;
	(void)x;

#ifdef GL_FILL
	x = ev.fill;
	BOOST_CHECK(x == ev.fill);
# ifdef GL_FILL_RECTANGLE_NV
	BOOST_CHECK(x != ev.fill_rectangle);
# endif
# ifdef GL_LINE
	BOOST_CHECK(x != ev.line);
# endif
# ifdef GL_POINT
	BOOST_CHECK(x != ev.point);
# endif
#endif

#ifdef GL_FILL_RECTANGLE_NV
	x = ev.fill_rectangle;
	BOOST_CHECK(x == ev.fill_rectangle);
# ifdef GL_LINE
	BOOST_CHECK(x != ev.line);
# endif
# ifdef GL_POINT
	BOOST_CHECK(x != ev.point);
# endif
#endif

#ifdef GL_LINE
	x = ev.line;
	BOOST_CHECK(x == ev.line);
# ifdef GL_POINT
	BOOST_CHECK(x != ev.point);
# endif
#endif

#ifdef GL_POINT
	x = ev.point;
	BOOST_CHECK(x == ev.point);
#endif
}

BOOST_AUTO_TEST_CASE(enum_polygon_mode_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	polygon_mode x;
	(void)x;

#ifdef GL_FILL
	x = ev.fill;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"FILL"
	) == 0);
#endif

#ifdef GL_FILL_RECTANGLE_NV
	x = ev.fill_rectangle;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"FILL_RECTANGLE_NV"
	) == 0);
#endif

#ifdef GL_LINE
	x = ev.line;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"LINE"
	) == 0);
#endif

#ifdef GL_POINT
	x = ev.point;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"POINT"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_polygon_mode_range)
{
	using namespace oglplus;
	auto count = enum_value_range<polygon_mode>().size();

#ifdef GL_FILL
{
	--count;
	auto r = enum_value_range<polygon_mode>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		polygon_mode(GL_FILL)
	) != r.end());
}
#endif

#ifdef GL_FILL_RECTANGLE_NV
{
	--count;
	auto r = enum_value_range<polygon_mode>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		polygon_mode(GL_FILL_RECTANGLE_NV)
	) != r.end());
}
#endif

#ifdef GL_LINE
{
	--count;
	auto r = enum_value_range<polygon_mode>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		polygon_mode(GL_LINE)
	) != r.end());
}
#endif

#ifdef GL_POINT
{
	--count;
	auto r = enum_value_range<polygon_mode>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		polygon_mode(GL_POINT)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_polygon_mode_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	polygon_mode x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_FILL
	x = ev.fill;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.fill);
#endif

#ifdef GL_FILL_RECTANGLE_NV
	x = ev.fill_rectangle;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.fill_rectangle);
#endif

#ifdef GL_LINE
	x = ev.line;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.line);
#endif

#ifdef GL_POINT
	x = ev.point;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.point);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
