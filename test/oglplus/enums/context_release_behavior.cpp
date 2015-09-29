//  File test/oglplus/enums/context_release_behavior.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_context_release_behavior

#include <boost/test/unit_test.hpp>
#include "common.hpp"

BOOST_AUTO_TEST_SUITE(enum_context_release_behavior)

BOOST_AUTO_TEST_CASE(enum_context_release_behavior_values)
{
	using namespace oglplus;
	enum_values ev;
	context_release_behavior x;

#ifdef GL_CONTEXT_RELEASE_BEHAVIOR_FLUSH
	x = ev.context_release_behavior_flush;
	BOOST_CHECK(x == ev.context_release_behavior_flush);
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
#endif

#ifdef GL_NONE
	x = ev.none;
# ifdef GL_CONTEXT_RELEASE_BEHAVIOR_FLUSH
	BOOST_CHECK(x != ev.context_release_behavior_flush);
# endif
	BOOST_CHECK(x == ev.none);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
