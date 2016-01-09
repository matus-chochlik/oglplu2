//  File test/oglplus/enums/debug_output_severity.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_debug_output_severity

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_debug_output_severity_tests)

BOOST_AUTO_TEST_CASE(enum_debug_output_severity_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	debug_output_severity x;
	(void)x;

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
	BOOST_CHECK(x == ev.debug_severity_notification);
# ifdef GL_DONT_CARE
	BOOST_CHECK(x != ev.dont_care);
# endif
#endif

#ifdef GL_DONT_CARE
	x = ev.dont_care;
	BOOST_CHECK(x == ev.dont_care);
#endif
}

BOOST_AUTO_TEST_CASE(enum_debug_output_severity_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	debug_output_severity x;
	(void)x;

#ifdef GL_DEBUG_SEVERITY_HIGH
	x = ev.debug_severity_high;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DEBUG_SEVERITY_HIGH"
	) == 0);
#endif

#ifdef GL_DEBUG_SEVERITY_LOW
	x = ev.debug_severity_low;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DEBUG_SEVERITY_LOW"
	) == 0);
#endif

#ifdef GL_DEBUG_SEVERITY_MEDIUM
	x = ev.debug_severity_medium;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DEBUG_SEVERITY_MEDIUM"
	) == 0);
#endif

#ifdef GL_DEBUG_SEVERITY_NOTIFICATION
	x = ev.debug_severity_notification;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DEBUG_SEVERITY_NOTIFICATION"
	) == 0);
#endif

#ifdef GL_DONT_CARE
	x = ev.dont_care;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DONT_CARE"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_debug_output_severity_range)
{
	using namespace oglplus;
	auto count = enum_value_range<debug_output_severity>().size();

#ifdef GL_DEBUG_SEVERITY_HIGH
{
	--count;
	auto r = enum_value_range<debug_output_severity>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		debug_output_severity(GL_DEBUG_SEVERITY_HIGH)
	) != r.end());
}
#endif

#ifdef GL_DEBUG_SEVERITY_LOW
{
	--count;
	auto r = enum_value_range<debug_output_severity>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		debug_output_severity(GL_DEBUG_SEVERITY_LOW)
	) != r.end());
}
#endif

#ifdef GL_DEBUG_SEVERITY_MEDIUM
{
	--count;
	auto r = enum_value_range<debug_output_severity>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		debug_output_severity(GL_DEBUG_SEVERITY_MEDIUM)
	) != r.end());
}
#endif

#ifdef GL_DEBUG_SEVERITY_NOTIFICATION
{
	--count;
	auto r = enum_value_range<debug_output_severity>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		debug_output_severity(GL_DEBUG_SEVERITY_NOTIFICATION)
	) != r.end());
}
#endif

#ifdef GL_DONT_CARE
{
	--count;
	auto r = enum_value_range<debug_output_severity>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		debug_output_severity(GL_DONT_CARE)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_debug_output_severity_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	debug_output_severity x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_DEBUG_SEVERITY_HIGH
	x = ev.debug_severity_high;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.debug_severity_high);
#endif

#ifdef GL_DEBUG_SEVERITY_LOW
	x = ev.debug_severity_low;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.debug_severity_low);
#endif

#ifdef GL_DEBUG_SEVERITY_MEDIUM
	x = ev.debug_severity_medium;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.debug_severity_medium);
#endif

#ifdef GL_DEBUG_SEVERITY_NOTIFICATION
	x = ev.debug_severity_notification;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.debug_severity_notification);
#endif

#ifdef GL_DONT_CARE
	x = ev.dont_care;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.dont_care);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
