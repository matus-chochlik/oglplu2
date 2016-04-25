//  File test/oglplus/enums/transform_feedback_primitive_type.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_transform_feedback_primitive_type

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_transform_feedback_primitive_type_tests)

BOOST_AUTO_TEST_CASE(enum_transform_feedback_primitive_type_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	transform_feedback_primitive_type x;
	(void)x;

#ifdef GL_LINES
	x = ev.lines;
	BOOST_CHECK(x == ev.lines);
# ifdef GL_POINTS
	BOOST_CHECK(x != ev.points);
# endif
# ifdef GL_TRIANGLES
	BOOST_CHECK(x != ev.triangles);
# endif
#endif

#ifdef GL_POINTS
	x = ev.points;
	BOOST_CHECK(x == ev.points);
# ifdef GL_TRIANGLES
	BOOST_CHECK(x != ev.triangles);
# endif
#endif

#ifdef GL_TRIANGLES
	x = ev.triangles;
	BOOST_CHECK(x == ev.triangles);
#endif
}

BOOST_AUTO_TEST_CASE(enum_transform_feedback_primitive_type_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	transform_feedback_primitive_type x;
	(void)x;

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

#ifdef GL_TRIANGLES
	x = ev.triangles;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TRIANGLES"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_transform_feedback_primitive_type_range)
{
	using namespace oglplus;
	auto count = enum_value_range<transform_feedback_primitive_type>().size();

#ifdef GL_LINES
{
	--count;
	auto r = enum_value_range<transform_feedback_primitive_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		transform_feedback_primitive_type(GL_LINES)
	) != r.end());
}
#endif

#ifdef GL_POINTS
{
	--count;
	auto r = enum_value_range<transform_feedback_primitive_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		transform_feedback_primitive_type(GL_POINTS)
	) != r.end());
}
#endif

#ifdef GL_TRIANGLES
{
	--count;
	auto r = enum_value_range<transform_feedback_primitive_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		transform_feedback_primitive_type(GL_TRIANGLES)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_transform_feedback_primitive_type_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	transform_feedback_primitive_type x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

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
