//  File test/boost_test/oglplus/enums/sync_parameter.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_sync_parameter

#include "../../unit_test_begin.inl"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_sync_parameter_tests)

BOOST_AUTO_TEST_CASE(enum_sync_parameter_values)
{
	using namespace oglplus;
	enum_values ev;
	EAGINE_MAYBE_UNUSED(ev);
	sync_parameter x;
	EAGINE_MAYBE_UNUSED(x);

#ifdef GL_OBJECT_TYPE
	x = ev.object_type;
	BOOST_CHECK(x == ev.object_type);
# ifdef GL_SYNC_CONDITION
	BOOST_CHECK(x != ev.sync_condition);
# endif
# ifdef GL_SYNC_GPU_COMMANDS_COMPLETE
	BOOST_CHECK(x != ev.sync_gpu_commands_complete);
# endif
# ifdef GL_SYNC_STATUS
	BOOST_CHECK(x != ev.sync_status);
# endif
#endif

#ifdef GL_SYNC_CONDITION
	x = ev.sync_condition;
	BOOST_CHECK(x == ev.sync_condition);
# ifdef GL_SYNC_GPU_COMMANDS_COMPLETE
	BOOST_CHECK(x != ev.sync_gpu_commands_complete);
# endif
# ifdef GL_SYNC_STATUS
	BOOST_CHECK(x != ev.sync_status);
# endif
#endif

#ifdef GL_SYNC_GPU_COMMANDS_COMPLETE
	x = ev.sync_gpu_commands_complete;
	BOOST_CHECK(x == ev.sync_gpu_commands_complete);
# ifdef GL_SYNC_STATUS
	BOOST_CHECK(x != ev.sync_status);
# endif
#endif

#ifdef GL_SYNC_STATUS
	x = ev.sync_status;
	BOOST_CHECK(x == ev.sync_status);
#endif
}

BOOST_AUTO_TEST_CASE(enum_sync_parameter_names)
{
	using namespace oglplus;
	enum_values ev;
	EAGINE_MAYBE_UNUSED(ev);
	sync_parameter x;
	EAGINE_MAYBE_UNUSED(x);

#ifdef GL_OBJECT_TYPE
	x = ev.object_type;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"OBJECT_TYPE"
	) == 0);
#endif

#ifdef GL_SYNC_CONDITION
	x = ev.sync_condition;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SYNC_CONDITION"
	) == 0);
#endif

#ifdef GL_SYNC_GPU_COMMANDS_COMPLETE
	x = ev.sync_gpu_commands_complete;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SYNC_GPU_COMMANDS_COMPLETE"
	) == 0);
#endif

#ifdef GL_SYNC_STATUS
	x = ev.sync_status;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SYNC_STATUS"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_sync_parameter_range)
{
	using namespace oglplus;
	auto count = enum_value_range<sync_parameter>().size();

#ifdef GL_OBJECT_TYPE
{
	--count;
	auto r = enum_value_range<sync_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		sync_parameter(GL_OBJECT_TYPE)
	) != r.end());
}
#endif

#ifdef GL_SYNC_CONDITION
{
	--count;
	auto r = enum_value_range<sync_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		sync_parameter(GL_SYNC_CONDITION)
	) != r.end());
}
#endif

#ifdef GL_SYNC_GPU_COMMANDS_COMPLETE
{
	--count;
	auto r = enum_value_range<sync_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		sync_parameter(GL_SYNC_GPU_COMMANDS_COMPLETE)
	) != r.end());
}
#endif

#ifdef GL_SYNC_STATUS
{
	--count;
	auto r = enum_value_range<sync_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		sync_parameter(GL_SYNC_STATUS)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_sync_parameter_any)
{
	using namespace oglplus;
	enum_values ev;
	EAGINE_MAYBE_UNUSED(ev);
	sync_parameter x, y;
	EAGINE_MAYBE_UNUSED(x);
	EAGINE_MAYBE_UNUSED(y);
	any_enum_value a;
	EAGINE_MAYBE_UNUSED(a);

#ifdef GL_OBJECT_TYPE
	x = ev.object_type;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.object_type);
#endif

#ifdef GL_SYNC_CONDITION
	x = ev.sync_condition;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.sync_condition);
#endif

#ifdef GL_SYNC_GPU_COMMANDS_COMPLETE
	x = ev.sync_gpu_commands_complete;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.sync_gpu_commands_complete);
#endif

#ifdef GL_SYNC_STATUS
	x = ev.sync_status;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.sync_status);
#endif
}

BOOST_AUTO_TEST_SUITE_END()

#include "../../unit_test_end.inl"
