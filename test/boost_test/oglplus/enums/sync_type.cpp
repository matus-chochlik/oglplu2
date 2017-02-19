//  File test/boost_test/oglplus/enums/sync_type.cpp
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
#include "common.hpp"
#define BOOST_TEST_MODULE OGLPLUS_sync_type

#include "../../unit_test.inl"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_sync_type_tests)

BOOST_AUTO_TEST_CASE(enum_sync_type_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	sync_type x;
	(void)x;

#ifdef GL_SYNC_FENCE
	x = ev.sync_fence;
	BOOST_CHECK(x == ev.sync_fence);
#endif
}

BOOST_AUTO_TEST_CASE(enum_sync_type_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	sync_type x;
	(void)x;

#ifdef GL_SYNC_FENCE
	x = ev.sync_fence;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SYNC_FENCE"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_sync_type_range)
{
	using namespace oglplus;
	auto count = enum_value_range<sync_type>().size();

#ifdef GL_SYNC_FENCE
{
	--count;
	auto r = enum_value_range<sync_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		sync_type(GL_SYNC_FENCE)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_sync_type_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	sync_type x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_SYNC_FENCE
	x = ev.sync_fence;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.sync_fence);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
