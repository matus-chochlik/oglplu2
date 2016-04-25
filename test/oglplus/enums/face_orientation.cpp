//  File test/oglplus/enums/face_orientation.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_face_orientation

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_face_orientation_tests)

BOOST_AUTO_TEST_CASE(enum_face_orientation_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	face_orientation x;
	(void)x;

#ifdef GL_CCW
	x = ev.ccw;
	BOOST_CHECK(x == ev.ccw);
# ifdef GL_CW
	BOOST_CHECK(x != ev.cw);
# endif
#endif

#ifdef GL_CW
	x = ev.cw;
	BOOST_CHECK(x == ev.cw);
#endif
}

BOOST_AUTO_TEST_CASE(enum_face_orientation_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	face_orientation x;
	(void)x;

#ifdef GL_CCW
	x = ev.ccw;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"CCW"
	) == 0);
#endif

#ifdef GL_CW
	x = ev.cw;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"CW"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_face_orientation_range)
{
	using namespace oglplus;
	auto count = enum_value_range<face_orientation>().size();

#ifdef GL_CCW
{
	--count;
	auto r = enum_value_range<face_orientation>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		face_orientation(GL_CCW)
	) != r.end());
}
#endif

#ifdef GL_CW
{
	--count;
	auto r = enum_value_range<face_orientation>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		face_orientation(GL_CW)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_face_orientation_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	face_orientation x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_CCW
	x = ev.ccw;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.ccw);
#endif

#ifdef GL_CW
	x = ev.cw;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.cw);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
