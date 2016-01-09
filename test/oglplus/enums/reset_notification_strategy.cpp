//  File test/oglplus/enums/reset_notification_strategy.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_reset_notification_strategy

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_reset_notification_strategy_tests)

BOOST_AUTO_TEST_CASE(enum_reset_notification_strategy_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	reset_notification_strategy x;
	(void)x;

#ifdef GL_LOSE_CONTEXT_ON_RESET
	x = ev.lose_context_on_reset;
	BOOST_CHECK(x == ev.lose_context_on_reset);
# ifdef GL_NO_RESET_NOTIFICATION
	BOOST_CHECK(x != ev.no_reset_notification);
# endif
#endif

#ifdef GL_NO_RESET_NOTIFICATION
	x = ev.no_reset_notification;
	BOOST_CHECK(x == ev.no_reset_notification);
#endif
}

BOOST_AUTO_TEST_CASE(enum_reset_notification_strategy_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	reset_notification_strategy x;
	(void)x;

#ifdef GL_LOSE_CONTEXT_ON_RESET
	x = ev.lose_context_on_reset;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"LOSE_CONTEXT_ON_RESET"
	) == 0);
#endif

#ifdef GL_NO_RESET_NOTIFICATION
	x = ev.no_reset_notification;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"NO_RESET_NOTIFICATION"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_reset_notification_strategy_range)
{
	using namespace oglplus;
	auto count = enum_value_range<reset_notification_strategy>().size();

#ifdef GL_LOSE_CONTEXT_ON_RESET
{
	--count;
	auto r = enum_value_range<reset_notification_strategy>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		reset_notification_strategy(GL_LOSE_CONTEXT_ON_RESET)
	) != r.end());
}
#endif

#ifdef GL_NO_RESET_NOTIFICATION
{
	--count;
	auto r = enum_value_range<reset_notification_strategy>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		reset_notification_strategy(GL_NO_RESET_NOTIFICATION)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_reset_notification_strategy_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	reset_notification_strategy x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_LOSE_CONTEXT_ON_RESET
	x = ev.lose_context_on_reset;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.lose_context_on_reset);
#endif

#ifdef GL_NO_RESET_NOTIFICATION
	x = ev.no_reset_notification;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.no_reset_notification);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
