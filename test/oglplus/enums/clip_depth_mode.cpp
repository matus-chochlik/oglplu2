//  File test/oglplus/enums/clip_depth_mode.cpp
//
//  Automatically generated file, DO NOT modify manually.
//  Edit the enumeration source files in 'source/enums/oglplus'
//  or the 'source/enums/make_enum.py' script instead.
//
//  Copyright Matus Chochlik.
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt
//
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE OGLPLUS_clip_depth_mode

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_clip_depth_mode)

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
# ifdef GL_NEGATIVE_ONE_TO_ONE
	BOOST_CHECK(x != ev.negative_one_to_one);
# endif
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

BOOST_AUTO_TEST_SUITE_END()
