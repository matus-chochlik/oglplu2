//  File test/oglplus/enums/transform_feedback_target.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_transform_feedback_target

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_transform_feedback_target)

BOOST_AUTO_TEST_CASE(enum_transform_feedback_target_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	transform_feedback_target x;
	(void)x;

#ifdef GL_TRANSFORM_FEEDBACK
	x = ev.transform_feedback;
	BOOST_CHECK(x == ev.transform_feedback);
#endif
}

BOOST_AUTO_TEST_CASE(enum_transform_feedback_target_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	transform_feedback_target x;
	(void)x;

#ifdef GL_TRANSFORM_FEEDBACK
	x = ev.transform_feedback;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TRANSFORM_FEEDBACK"
	) == 0);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
