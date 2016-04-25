//  File test/oglplus/enums/clip_origin.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_clip_origin

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_clip_origin_tests)

BOOST_AUTO_TEST_CASE(enum_clip_origin_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	clip_origin x;
	(void)x;

#ifdef GL_LOWER_LEFT
	x = ev.lower_left;
	BOOST_CHECK(x == ev.lower_left);
# ifdef GL_UPPER_LEFT
	BOOST_CHECK(x != ev.upper_left);
# endif
#endif

#ifdef GL_UPPER_LEFT
	x = ev.upper_left;
	BOOST_CHECK(x == ev.upper_left);
#endif
}

BOOST_AUTO_TEST_CASE(enum_clip_origin_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	clip_origin x;
	(void)x;

#ifdef GL_LOWER_LEFT
	x = ev.lower_left;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"LOWER_LEFT"
	) == 0);
#endif

#ifdef GL_UPPER_LEFT
	x = ev.upper_left;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"UPPER_LEFT"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_clip_origin_range)
{
	using namespace oglplus;
	auto count = enum_value_range<clip_origin>().size();

#ifdef GL_LOWER_LEFT
{
	--count;
	auto r = enum_value_range<clip_origin>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		clip_origin(GL_LOWER_LEFT)
	) != r.end());
}
#endif

#ifdef GL_UPPER_LEFT
{
	--count;
	auto r = enum_value_range<clip_origin>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		clip_origin(GL_UPPER_LEFT)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_clip_origin_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	clip_origin x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_LOWER_LEFT
	x = ev.lower_left;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.lower_left);
#endif

#ifdef GL_UPPER_LEFT
	x = ev.upper_left;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.upper_left);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
