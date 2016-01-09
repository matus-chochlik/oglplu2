//  File test/oglplus/enums/clip_depth_mode.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_clip_depth_mode

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_clip_depth_mode_tests)

BOOST_AUTO_TEST_CASE(enum_clip_depth_mode_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	clip_depth_mode x;
	(void)x;

#ifdef GL_NEGATIVE_ONE_TO_ONE
	x = ev.negative_one_to_one;
	BOOST_CHECK(x == ev.negative_one_to_one);
# ifdef GL_ZERO_TO_ONE
	BOOST_CHECK(x != ev.zero_to_one);
# endif
#endif

#ifdef GL_ZERO_TO_ONE
	x = ev.zero_to_one;
	BOOST_CHECK(x == ev.zero_to_one);
#endif
}

BOOST_AUTO_TEST_CASE(enum_clip_depth_mode_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	clip_depth_mode x;
	(void)x;

#ifdef GL_NEGATIVE_ONE_TO_ONE
	x = ev.negative_one_to_one;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"NEGATIVE_ONE_TO_ONE"
	) == 0);
#endif

#ifdef GL_ZERO_TO_ONE
	x = ev.zero_to_one;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ZERO_TO_ONE"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_clip_depth_mode_range)
{
	using namespace oglplus;
	auto count = enum_value_range<clip_depth_mode>().size();

#ifdef GL_NEGATIVE_ONE_TO_ONE
{
	--count;
	auto r = enum_value_range<clip_depth_mode>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		clip_depth_mode(GL_NEGATIVE_ONE_TO_ONE)
	) != r.end());
}
#endif

#ifdef GL_ZERO_TO_ONE
{
	--count;
	auto r = enum_value_range<clip_depth_mode>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		clip_depth_mode(GL_ZERO_TO_ONE)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_clip_depth_mode_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	clip_depth_mode x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_NEGATIVE_ONE_TO_ONE
	x = ev.negative_one_to_one;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.negative_one_to_one);
#endif

#ifdef GL_ZERO_TO_ONE
	x = ev.zero_to_one;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.zero_to_one);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
