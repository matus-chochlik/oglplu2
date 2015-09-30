//  File test/oglplus/enums/sync_condition.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_sync_condition

#include <boost/test/unit_test.hpp>
#include "common.hpp"

BOOST_AUTO_TEST_SUITE(enum_sync_condition)

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

BOOST_AUTO_TEST_SUITE_END()
