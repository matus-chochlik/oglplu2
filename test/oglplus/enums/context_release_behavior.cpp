//  File test/oglplus/enums/context_release_behavior.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_context_release_behavior

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_context_release_behavior_tests)

BOOST_AUTO_TEST_CASE(enum_context_release_behavior_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	context_release_behavior x;
	(void)x;

#ifdef GL_CONTEXT_RELEASE_BEHAVIOR_FLUSH
	x = ev.context_release_behavior_flush;
	BOOST_CHECK(x == ev.context_release_behavior_flush);
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
#endif

#ifdef GL_NONE
	x = ev.none;
	BOOST_CHECK(x == ev.none);
#endif
}

BOOST_AUTO_TEST_CASE(enum_context_release_behavior_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	context_release_behavior x;
	(void)x;

#ifdef GL_CONTEXT_RELEASE_BEHAVIOR_FLUSH
	x = ev.context_release_behavior_flush;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"CONTEXT_RELEASE_BEHAVIOR_FLUSH"
	) == 0);
#endif

#ifdef GL_NONE
	x = ev.none;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"NONE"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_context_release_behavior_range)
{
	using namespace oglplus;
	auto count = enum_value_range<context_release_behavior>().size();

#ifdef GL_CONTEXT_RELEASE_BEHAVIOR_FLUSH
{
	--count;
	auto r = enum_value_range<context_release_behavior>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		context_release_behavior(GL_CONTEXT_RELEASE_BEHAVIOR_FLUSH)
	) != r.end());
}
#endif

#ifdef GL_NONE
{
	--count;
	auto r = enum_value_range<context_release_behavior>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		context_release_behavior(GL_NONE)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_context_release_behavior_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	context_release_behavior x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_CONTEXT_RELEASE_BEHAVIOR_FLUSH
	x = ev.context_release_behavior_flush;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.context_release_behavior_flush);
#endif

#ifdef GL_NONE
	x = ev.none;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.none);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
