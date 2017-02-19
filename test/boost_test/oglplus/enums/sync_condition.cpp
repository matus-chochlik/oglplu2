//  File test/boost_test/oglplus/enums/sync_condition.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_sync_condition

#include "../../unit_test.inl"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_sync_condition_tests)

BOOST_AUTO_TEST_CASE(enum_sync_condition_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	sync_condition x;
	(void)x;

#ifdef GL_SYNC_GPU_COMMANDS_COMPLETE
	x = ev.sync_gpu_commands_complete;
	BOOST_CHECK(x == ev.sync_gpu_commands_complete);
#endif
}

BOOST_AUTO_TEST_CASE(enum_sync_condition_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	sync_condition x;
	(void)x;

#ifdef GL_SYNC_GPU_COMMANDS_COMPLETE
	x = ev.sync_gpu_commands_complete;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SYNC_GPU_COMMANDS_COMPLETE"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_sync_condition_range)
{
	using namespace oglplus;
	auto count = enum_value_range<sync_condition>().size();

#ifdef GL_SYNC_GPU_COMMANDS_COMPLETE
{
	--count;
	auto r = enum_value_range<sync_condition>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		sync_condition(GL_SYNC_GPU_COMMANDS_COMPLETE)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_sync_condition_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	sync_condition x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_SYNC_GPU_COMMANDS_COMPLETE
	x = ev.sync_gpu_commands_complete;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.sync_gpu_commands_complete);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
