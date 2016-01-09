//  File test/oglplus/enums/sync_wait_result.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_sync_wait_result

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_sync_wait_result_tests)

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
	BOOST_CHECK(x == ev.timeout_expired);
# ifdef GL_WAIT_FAILED
	BOOST_CHECK(x != ev.wait_failed);
# endif
#endif

#ifdef GL_WAIT_FAILED
	x = ev.wait_failed;
	BOOST_CHECK(x == ev.wait_failed);
#endif
}

BOOST_AUTO_TEST_CASE(enum_sync_wait_result_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	sync_wait_result x;
	(void)x;

#ifdef GL_ALREADY_SIGNALED
	x = ev.already_signaled;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ALREADY_SIGNALED"
	) == 0);
#endif

#ifdef GL_CONDITION_SATISFIED
	x = ev.condition_satisfied;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"CONDITION_SATISFIED"
	) == 0);
#endif

#ifdef GL_TIMEOUT_EXPIRED
	x = ev.timeout_expired;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TIMEOUT_EXPIRED"
	) == 0);
#endif

#ifdef GL_WAIT_FAILED
	x = ev.wait_failed;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"WAIT_FAILED"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_sync_wait_result_range)
{
	using namespace oglplus;
	auto count = enum_value_range<sync_wait_result>().size();

#ifdef GL_ALREADY_SIGNALED
{
	--count;
	auto r = enum_value_range<sync_wait_result>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		sync_wait_result(GL_ALREADY_SIGNALED)
	) != r.end());
}
#endif

#ifdef GL_CONDITION_SATISFIED
{
	--count;
	auto r = enum_value_range<sync_wait_result>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		sync_wait_result(GL_CONDITION_SATISFIED)
	) != r.end());
}
#endif

#ifdef GL_TIMEOUT_EXPIRED
{
	--count;
	auto r = enum_value_range<sync_wait_result>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		sync_wait_result(GL_TIMEOUT_EXPIRED)
	) != r.end());
}
#endif

#ifdef GL_WAIT_FAILED
{
	--count;
	auto r = enum_value_range<sync_wait_result>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		sync_wait_result(GL_WAIT_FAILED)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_sync_wait_result_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	sync_wait_result x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_ALREADY_SIGNALED
	x = ev.already_signaled;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.already_signaled);
#endif

#ifdef GL_CONDITION_SATISFIED
	x = ev.condition_satisfied;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.condition_satisfied);
#endif

#ifdef GL_TIMEOUT_EXPIRED
	x = ev.timeout_expired;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.timeout_expired);
#endif

#ifdef GL_WAIT_FAILED
	x = ev.wait_failed;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.wait_failed);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
