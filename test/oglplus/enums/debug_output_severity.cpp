//  File test/oglplus/enums/debug_output_severity.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_debug_output_severity

#include <boost/test/unit_test.hpp>
#include "common.hpp"

BOOST_AUTO_TEST_SUITE(enum_debug_output_severity)

BOOST_AUTO_TEST_CASE(enum_debug_output_severity_values)
{
	using namespace oglplus;
	enum_values ev;
	debug_output_severity x;

#ifdef GL_DEBUG_SEVERITY_HIGH
	x = ev.debug_severity_high;
	BOOST_CHECK(x == ev.debug_severity_high);
# ifdef GL_DEBUG_SEVERITY_LOW
	BOOST_CHECK(x != ev.debug_severity_low);
# endif
# ifdef GL_DEBUG_SEVERITY_MEDIUM
	BOOST_CHECK(x != ev.debug_severity_medium);
# endif
# ifdef GL_DEBUG_SEVERITY_NOTIFICATION
	BOOST_CHECK(x != ev.debug_severity_notification);
# endif
# ifdef GL_DONT_CARE
	BOOST_CHECK(x != ev.dont_care);
# endif
#endif

#ifdef GL_DEBUG_SEVERITY_LOW
	x = ev.debug_severity_low;
# ifdef GL_DEBUG_SEVERITY_HIGH
	BOOST_CHECK(x != ev.debug_severity_high);
# endif
	BOOST_CHECK(x == ev.debug_severity_low);
# ifdef GL_DEBUG_SEVERITY_MEDIUM
	BOOST_CHECK(x != ev.debug_severity_medium);
# endif
# ifdef GL_DEBUG_SEVERITY_NOTIFICATION
	BOOST_CHECK(x != ev.debug_severity_notification);
# endif
# ifdef GL_DONT_CARE
	BOOST_CHECK(x != ev.dont_care);
# endif
#endif

#ifdef GL_DEBUG_SEVERITY_MEDIUM
	x = ev.debug_severity_medium;
# ifdef GL_DEBUG_SEVERITY_HIGH
	BOOST_CHECK(x != ev.debug_severity_high);
# endif
# ifdef GL_DEBUG_SEVERITY_LOW
	BOOST_CHECK(x != ev.debug_severity_low);
# endif
	BOOST_CHECK(x == ev.debug_severity_medium);
# ifdef GL_DEBUG_SEVERITY_NOTIFICATION
	BOOST_CHECK(x != ev.debug_severity_notification);
# endif
# ifdef GL_DONT_CARE
	BOOST_CHECK(x != ev.dont_care);
# endif
#endif

#ifdef GL_DEBUG_SEVERITY_NOTIFICATION
	x = ev.debug_severity_notification;
# ifdef GL_DEBUG_SEVERITY_HIGH
	BOOST_CHECK(x != ev.debug_severity_high);
# endif
# ifdef GL_DEBUG_SEVERITY_LOW
	BOOST_CHECK(x != ev.debug_severity_low);
# endif
# ifdef GL_DEBUG_SEVERITY_MEDIUM
	BOOST_CHECK(x != ev.debug_severity_medium);
# endif
	BOOST_CHECK(x == ev.debug_severity_notification);
# ifdef GL_DONT_CARE
	BOOST_CHECK(x != ev.dont_care);
# endif
#endif

#ifdef GL_DONT_CARE
	x = ev.dont_care;
# ifdef GL_DEBUG_SEVERITY_HIGH
	BOOST_CHECK(x != ev.debug_severity_high);
# endif
# ifdef GL_DEBUG_SEVERITY_LOW
	BOOST_CHECK(x != ev.debug_severity_low);
# endif
# ifdef GL_DEBUG_SEVERITY_MEDIUM
	BOOST_CHECK(x != ev.debug_severity_medium);
# endif
# ifdef GL_DEBUG_SEVERITY_NOTIFICATION
	BOOST_CHECK(x != ev.debug_severity_notification);
# endif
	BOOST_CHECK(x == ev.dont_care);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
