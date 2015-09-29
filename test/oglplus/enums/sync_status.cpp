//  File test/oglplus/enums/sync_status.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_sync_status

#include <boost/test/unit_test.hpp>
#include "common.hpp"

BOOST_AUTO_TEST_SUITE(enum_sync_status)

BOOST_AUTO_TEST_CASE(enum_sync_status_values)
{
	using namespace oglplus;
	enum_values ev;
	sync_status x;

#ifdef GL_SIGNALED
	x = ev.signaled;
	BOOST_CHECK(x == ev.signaled);
# ifdef GL_UNSIGNALED
	BOOST_CHECK(x != ev.unsignaled);
# endif
#endif

#ifdef GL_UNSIGNALED
	x = ev.unsignaled;
# ifdef GL_SIGNALED
	BOOST_CHECK(x != ev.signaled);
# endif
	BOOST_CHECK(x == ev.unsignaled);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
