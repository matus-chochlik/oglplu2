//  File test/oglplus/enums/functionality.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_functionality

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_functionality)

BOOST_AUTO_TEST_CASE(enum_functionality_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	functionality x;
	(void)x;

#ifdef GL_CLIP_DISTANCE0
	x = ev.clip_distance;
	BOOST_CHECK(x == ev.clip_distance);
#endif
}

BOOST_AUTO_TEST_CASE(enum_functionality_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	functionality x;
	(void)x;

#ifdef GL_CLIP_DISTANCE0
	x = ev.clip_distance;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"CLIP_DISTANCE0"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_functionality_range)
{
	using namespace oglplus;
	functionality x;
	(void)x;
	auto count = enum_value_range(x).size();

#ifdef GL_CLIP_DISTANCE0
{
	--count;
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_CLIP_DISTANCE0
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_functionality_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	functionality x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_CLIP_DISTANCE0
	x = ev.clip_distance;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.clip_distance);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
