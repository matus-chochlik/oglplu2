//  File test/oglplus/enums/old_primitive_type.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_old_primitive_type

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_old_primitive_type_tests)

BOOST_AUTO_TEST_CASE(enum_old_primitive_type_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	old_primitive_type x;
	(void)x;

#ifdef GL_LINE_LOOP
	x = ev.line_loop;
	BOOST_CHECK(x == ev.line_loop);
# ifdef GL_LINE_STRIP
	BOOST_CHECK(x != ev.line_strip);
# endif
# ifdef GL_LINES
	BOOST_CHECK(x != ev.lines);
# endif
# ifdef GL_POINTS
	BOOST_CHECK(x != ev.points);
# endif
# ifdef GL_POLYGON
	BOOST_CHECK(x != ev.polygon);
# endif
# ifdef GL_QUAD_STRIP
	BOOST_CHECK(x != ev.quad_strip);
# endif
# ifdef GL_QUADS
	BOOST_CHECK(x != ev.quads);
# endif
# ifdef GL_TRIANGLE_FAN
	BOOST_CHECK(x != ev.triangle_fan);
# endif
# ifdef GL_TRIANGLE_STRIP
	BOOST_CHECK(x != ev.triangle_strip);
# endif
# ifdef GL_TRIANGLES
	BOOST_CHECK(x != ev.triangles);
# endif
#endif

#ifdef GL_LINE_STRIP
	x = ev.line_strip;
	BOOST_CHECK(x == ev.line_strip);
# ifdef GL_LINES
	BOOST_CHECK(x != ev.lines);
# endif
# ifdef GL_POINTS
	BOOST_CHECK(x != ev.points);
# endif
# ifdef GL_POLYGON
	BOOST_CHECK(x != ev.polygon);
# endif
# ifdef GL_QUAD_STRIP
	BOOST_CHECK(x != ev.quad_strip);
# endif
# ifdef GL_QUADS
	BOOST_CHECK(x != ev.quads);
# endif
# ifdef GL_TRIANGLE_FAN
	BOOST_CHECK(x != ev.triangle_fan);
# endif
# ifdef GL_TRIANGLE_STRIP
	BOOST_CHECK(x != ev.triangle_strip);
# endif
# ifdef GL_TRIANGLES
	BOOST_CHECK(x != ev.triangles);
# endif
#endif

#ifdef GL_LINES
	x = ev.lines;
	BOOST_CHECK(x == ev.lines);
# ifdef GL_POINTS
	BOOST_CHECK(x != ev.points);
# endif
# ifdef GL_POLYGON
	BOOST_CHECK(x != ev.polygon);
# endif
# ifdef GL_QUAD_STRIP
	BOOST_CHECK(x != ev.quad_strip);
# endif
# ifdef GL_QUADS
	BOOST_CHECK(x != ev.quads);
# endif
# ifdef GL_TRIANGLE_FAN
	BOOST_CHECK(x != ev.triangle_fan);
# endif
# ifdef GL_TRIANGLE_STRIP
	BOOST_CHECK(x != ev.triangle_strip);
# endif
# ifdef GL_TRIANGLES
	BOOST_CHECK(x != ev.triangles);
# endif
#endif

#ifdef GL_POINTS
	x = ev.points;
	BOOST_CHECK(x == ev.points);
# ifdef GL_POLYGON
	BOOST_CHECK(x != ev.polygon);
# endif
# ifdef GL_QUAD_STRIP
	BOOST_CHECK(x != ev.quad_strip);
# endif
# ifdef GL_QUADS
	BOOST_CHECK(x != ev.quads);
# endif
# ifdef GL_TRIANGLE_FAN
	BOOST_CHECK(x != ev.triangle_fan);
# endif
# ifdef GL_TRIANGLE_STRIP
	BOOST_CHECK(x != ev.triangle_strip);
# endif
# ifdef GL_TRIANGLES
	BOOST_CHECK(x != ev.triangles);
# endif
#endif

#ifdef GL_POLYGON
	x = ev.polygon;
	BOOST_CHECK(x == ev.polygon);
# ifdef GL_QUAD_STRIP
	BOOST_CHECK(x != ev.quad_strip);
# endif
# ifdef GL_QUADS
	BOOST_CHECK(x != ev.quads);
# endif
# ifdef GL_TRIANGLE_FAN
	BOOST_CHECK(x != ev.triangle_fan);
# endif
# ifdef GL_TRIANGLE_STRIP
	BOOST_CHECK(x != ev.triangle_strip);
# endif
# ifdef GL_TRIANGLES
	BOOST_CHECK(x != ev.triangles);
# endif
#endif

#ifdef GL_QUAD_STRIP
	x = ev.quad_strip;
	BOOST_CHECK(x == ev.quad_strip);
# ifdef GL_QUADS
	BOOST_CHECK(x != ev.quads);
# endif
# ifdef GL_TRIANGLE_FAN
	BOOST_CHECK(x != ev.triangle_fan);
# endif
# ifdef GL_TRIANGLE_STRIP
	BOOST_CHECK(x != ev.triangle_strip);
# endif
# ifdef GL_TRIANGLES
	BOOST_CHECK(x != ev.triangles);
# endif
#endif

#ifdef GL_QUADS
	x = ev.quads;
	BOOST_CHECK(x == ev.quads);
# ifdef GL_TRIANGLE_FAN
	BOOST_CHECK(x != ev.triangle_fan);
# endif
# ifdef GL_TRIANGLE_STRIP
	BOOST_CHECK(x != ev.triangle_strip);
# endif
# ifdef GL_TRIANGLES
	BOOST_CHECK(x != ev.triangles);
# endif
#endif

#ifdef GL_TRIANGLE_FAN
	x = ev.triangle_fan;
	BOOST_CHECK(x == ev.triangle_fan);
# ifdef GL_TRIANGLE_STRIP
	BOOST_CHECK(x != ev.triangle_strip);
# endif
# ifdef GL_TRIANGLES
	BOOST_CHECK(x != ev.triangles);
# endif
#endif

#ifdef GL_TRIANGLE_STRIP
	x = ev.triangle_strip;
	BOOST_CHECK(x == ev.triangle_strip);
# ifdef GL_TRIANGLES
	BOOST_CHECK(x != ev.triangles);
# endif
#endif

#ifdef GL_TRIANGLES
	x = ev.triangles;
	BOOST_CHECK(x == ev.triangles);
#endif
}

BOOST_AUTO_TEST_CASE(enum_old_primitive_type_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	old_primitive_type x;
	(void)x;

#ifdef GL_LINE_LOOP
	x = ev.line_loop;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"LINE_LOOP"
	) == 0);
#endif

#ifdef GL_LINE_STRIP
	x = ev.line_strip;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"LINE_STRIP"
	) == 0);
#endif

#ifdef GL_LINES
	x = ev.lines;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"LINES"
	) == 0);
#endif

#ifdef GL_POINTS
	x = ev.points;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"POINTS"
	) == 0);
#endif

#ifdef GL_POLYGON
	x = ev.polygon;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"POLYGON"
	) == 0);
#endif

#ifdef GL_QUAD_STRIP
	x = ev.quad_strip;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"QUAD_STRIP"
	) == 0);
#endif

#ifdef GL_QUADS
	x = ev.quads;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"QUADS"
	) == 0);
#endif

#ifdef GL_TRIANGLE_FAN
	x = ev.triangle_fan;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TRIANGLE_FAN"
	) == 0);
#endif

#ifdef GL_TRIANGLE_STRIP
	x = ev.triangle_strip;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TRIANGLE_STRIP"
	) == 0);
#endif

#ifdef GL_TRIANGLES
	x = ev.triangles;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TRIANGLES"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_old_primitive_type_range)
{
	using namespace oglplus;
	auto count = enum_value_range<old_primitive_type>().size();

#ifdef GL_LINE_LOOP
{
	--count;
	auto r = enum_value_range<old_primitive_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		old_primitive_type(GL_LINE_LOOP)
	) != r.end());
}
#endif

#ifdef GL_LINE_STRIP
{
	--count;
	auto r = enum_value_range<old_primitive_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		old_primitive_type(GL_LINE_STRIP)
	) != r.end());
}
#endif

#ifdef GL_LINES
{
	--count;
	auto r = enum_value_range<old_primitive_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		old_primitive_type(GL_LINES)
	) != r.end());
}
#endif

#ifdef GL_POINTS
{
	--count;
	auto r = enum_value_range<old_primitive_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		old_primitive_type(GL_POINTS)
	) != r.end());
}
#endif

#ifdef GL_POLYGON
{
	--count;
	auto r = enum_value_range<old_primitive_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		old_primitive_type(GL_POLYGON)
	) != r.end());
}
#endif

#ifdef GL_QUAD_STRIP
{
	--count;
	auto r = enum_value_range<old_primitive_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		old_primitive_type(GL_QUAD_STRIP)
	) != r.end());
}
#endif

#ifdef GL_QUADS
{
	--count;
	auto r = enum_value_range<old_primitive_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		old_primitive_type(GL_QUADS)
	) != r.end());
}
#endif

#ifdef GL_TRIANGLE_FAN
{
	--count;
	auto r = enum_value_range<old_primitive_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		old_primitive_type(GL_TRIANGLE_FAN)
	) != r.end());
}
#endif

#ifdef GL_TRIANGLE_STRIP
{
	--count;
	auto r = enum_value_range<old_primitive_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		old_primitive_type(GL_TRIANGLE_STRIP)
	) != r.end());
}
#endif

#ifdef GL_TRIANGLES
{
	--count;
	auto r = enum_value_range<old_primitive_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		old_primitive_type(GL_TRIANGLES)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_old_primitive_type_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	old_primitive_type x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_LINE_LOOP
	x = ev.line_loop;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.line_loop);
#endif

#ifdef GL_LINE_STRIP
	x = ev.line_strip;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.line_strip);
#endif

#ifdef GL_LINES
	x = ev.lines;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.lines);
#endif

#ifdef GL_POINTS
	x = ev.points;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.points);
#endif

#ifdef GL_POLYGON
	x = ev.polygon;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.polygon);
#endif

#ifdef GL_QUAD_STRIP
	x = ev.quad_strip;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.quad_strip);
#endif

#ifdef GL_QUADS
	x = ev.quads;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.quads);
#endif

#ifdef GL_TRIANGLE_FAN
	x = ev.triangle_fan;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.triangle_fan);
#endif

#ifdef GL_TRIANGLE_STRIP
	x = ev.triangle_strip;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.triangle_strip);
#endif

#ifdef GL_TRIANGLES
	x = ev.triangles;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.triangles);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
