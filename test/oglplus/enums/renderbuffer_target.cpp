//  File test/oglplus/enums/renderbuffer_target.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_renderbuffer_target

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_renderbuffer_target_tests)

BOOST_AUTO_TEST_CASE(enum_renderbuffer_target_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	renderbuffer_target x;
	(void)x;

#ifdef GL_RENDERBUFFER
	x = ev.renderbuffer;
	BOOST_CHECK(x == ev.renderbuffer);
#endif
}

BOOST_AUTO_TEST_CASE(enum_renderbuffer_target_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	renderbuffer_target x;
	(void)x;

#ifdef GL_RENDERBUFFER
	x = ev.renderbuffer;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RENDERBUFFER"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_renderbuffer_target_range)
{
	using namespace oglplus;
	auto count = enum_value_range<renderbuffer_target>().size();

#ifdef GL_RENDERBUFFER
{
	--count;
	auto r = enum_value_range<renderbuffer_target>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		renderbuffer_target(GL_RENDERBUFFER)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_renderbuffer_target_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	renderbuffer_target x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_RENDERBUFFER
	x = ev.renderbuffer;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.renderbuffer);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
