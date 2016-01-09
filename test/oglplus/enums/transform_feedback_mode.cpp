//  File test/oglplus/enums/transform_feedback_mode.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_transform_feedback_mode

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_transform_feedback_mode_tests)

BOOST_AUTO_TEST_CASE(enum_transform_feedback_mode_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	transform_feedback_mode x;
	(void)x;

#ifdef GL_INTERLEAVED_ATTRIBS
	x = ev.interleaved_attribs;
	BOOST_CHECK(x == ev.interleaved_attribs);
# ifdef GL_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.separate_attribs);
# endif
#endif

#ifdef GL_SEPARATE_ATTRIBS
	x = ev.separate_attribs;
	BOOST_CHECK(x == ev.separate_attribs);
#endif
}

BOOST_AUTO_TEST_CASE(enum_transform_feedback_mode_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	transform_feedback_mode x;
	(void)x;

#ifdef GL_INTERLEAVED_ATTRIBS
	x = ev.interleaved_attribs;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"INTERLEAVED_ATTRIBS"
	) == 0);
#endif

#ifdef GL_SEPARATE_ATTRIBS
	x = ev.separate_attribs;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SEPARATE_ATTRIBS"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_transform_feedback_mode_range)
{
	using namespace oglplus;
	auto count = enum_value_range<transform_feedback_mode>().size();

#ifdef GL_INTERLEAVED_ATTRIBS
{
	--count;
	auto r = enum_value_range<transform_feedback_mode>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		transform_feedback_mode(GL_INTERLEAVED_ATTRIBS)
	) != r.end());
}
#endif

#ifdef GL_SEPARATE_ATTRIBS
{
	--count;
	auto r = enum_value_range<transform_feedback_mode>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		transform_feedback_mode(GL_SEPARATE_ATTRIBS)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_transform_feedback_mode_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	transform_feedback_mode x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_INTERLEAVED_ATTRIBS
	x = ev.interleaved_attribs;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.interleaved_attribs);
#endif

#ifdef GL_SEPARATE_ATTRIBS
	x = ev.separate_attribs;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.separate_attribs);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
