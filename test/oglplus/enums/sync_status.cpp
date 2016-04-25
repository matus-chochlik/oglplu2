//  File test/oglplus/enums/sync_status.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_sync_status

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_sync_status_tests)

BOOST_AUTO_TEST_CASE(enum_sync_status_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	sync_status x;
	(void)x;

#ifdef GL_SIGNALED
	x = ev.signaled;
	BOOST_CHECK(x == ev.signaled);
# ifdef GL_UNSIGNALED
	BOOST_CHECK(x != ev.unsignaled);
# endif
#endif

#ifdef GL_UNSIGNALED
	x = ev.unsignaled;
	BOOST_CHECK(x == ev.unsignaled);
#endif
}

BOOST_AUTO_TEST_CASE(enum_sync_status_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	sync_status x;
	(void)x;

#ifdef GL_SIGNALED
	x = ev.signaled;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SIGNALED"
	) == 0);
#endif

#ifdef GL_UNSIGNALED
	x = ev.unsignaled;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"UNSIGNALED"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_sync_status_range)
{
	using namespace oglplus;
	auto count = enum_value_range<sync_status>().size();

#ifdef GL_SIGNALED
{
	--count;
	auto r = enum_value_range<sync_status>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		sync_status(GL_SIGNALED)
	) != r.end());
}
#endif

#ifdef GL_UNSIGNALED
{
	--count;
	auto r = enum_value_range<sync_status>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		sync_status(GL_UNSIGNALED)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_sync_status_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	sync_status x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_SIGNALED
	x = ev.signaled;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.signaled);
#endif

#ifdef GL_UNSIGNALED
	x = ev.unsignaled;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.unsignaled);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
