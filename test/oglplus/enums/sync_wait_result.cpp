//  File test/oglplus/enums/sync_wait_result.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_sync_wait_result

#include <boost/test/unit_test.hpp>
#include "common.hpp"

BOOST_AUTO_TEST_SUITE(enum_sync_wait_result)

BOOST_AUTO_TEST_CASE(enum_sync_wait_result_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	sync_wait_result x;
	(void)x;

#ifdef GL_ALREADY_SIGNALED
	x = ev.already_signaled;
	BOOST_CHECK(x == ev.already_signaled);
# ifdef GL_CONDITION_SATISFIED
	BOOST_CHECK(x != ev.condition_satisfied);
# endif
# ifdef GL_TIMEOUT_EXPIRED
	BOOST_CHECK(x != ev.timeout_expired);
# endif
# ifdef GL_WAIT_FAILED
	BOOST_CHECK(x != ev.wait_failed);
# endif
#endif

#ifdef GL_CONDITION_SATISFIED
	x = ev.condition_satisfied;
# ifdef GL_ALREADY_SIGNALED
	BOOST_CHECK(x != ev.already_signaled);
# endif
	BOOST_CHECK(x == ev.condition_satisfied);
# ifdef GL_TIMEOUT_EXPIRED
	BOOST_CHECK(x != ev.timeout_expired);
# endif
# ifdef GL_WAIT_FAILED
	BOOST_CHECK(x != ev.wait_failed);
# endif
#endif

#ifdef GL_TIMEOUT_EXPIRED
	x = ev.timeout_expired;
# ifdef GL_ALREADY_SIGNALED
	BOOST_CHECK(x != ev.already_signaled);
# endif
# ifdef GL_CONDITION_SATISFIED
	BOOST_CHECK(x != ev.condition_satisfied);
# endif
	BOOST_CHECK(x == ev.timeout_expired);
# ifdef GL_WAIT_FAILED
	BOOST_CHECK(x != ev.wait_failed);
# endif
#endif

#ifdef GL_WAIT_FAILED
	x = ev.wait_failed;
# ifdef GL_ALREADY_SIGNALED
	BOOST_CHECK(x != ev.already_signaled);
# endif
# ifdef GL_CONDITION_SATISFIED
	BOOST_CHECK(x != ev.condition_satisfied);
# endif
# ifdef GL_TIMEOUT_EXPIRED
	BOOST_CHECK(x != ev.timeout_expired);
# endif
	BOOST_CHECK(x == ev.wait_failed);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
