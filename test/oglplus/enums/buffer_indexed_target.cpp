//  File test/oglplus/enums/buffer_indexed_target.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_buffer_indexed_target

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_buffer_indexed_target_tests)

BOOST_AUTO_TEST_CASE(enum_buffer_indexed_target_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	buffer_indexed_target x;
	(void)x;

#ifdef GL_ATOMIC_COUNTER_BUFFER
	x = ev.atomic_counter_buffer;
	BOOST_CHECK(x == ev.atomic_counter_buffer);
# ifdef GL_SHADER_STORAGE_BUFFER
	BOOST_CHECK(x != ev.shader_storage_buffer);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER
	BOOST_CHECK(x != ev.transform_feedback_buffer);
# endif
# ifdef GL_UNIFORM_BUFFER
	BOOST_CHECK(x != ev.uniform_buffer);
# endif
#endif

#ifdef GL_SHADER_STORAGE_BUFFER
	x = ev.shader_storage_buffer;
	BOOST_CHECK(x == ev.shader_storage_buffer);
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER
	BOOST_CHECK(x != ev.transform_feedback_buffer);
# endif
# ifdef GL_UNIFORM_BUFFER
	BOOST_CHECK(x != ev.uniform_buffer);
# endif
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BUFFER
	x = ev.transform_feedback_buffer;
	BOOST_CHECK(x == ev.transform_feedback_buffer);
# ifdef GL_UNIFORM_BUFFER
	BOOST_CHECK(x != ev.uniform_buffer);
# endif
#endif

#ifdef GL_UNIFORM_BUFFER
	x = ev.uniform_buffer;
	BOOST_CHECK(x == ev.uniform_buffer);
#endif
}

BOOST_AUTO_TEST_CASE(enum_buffer_indexed_target_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	buffer_indexed_target x;
	(void)x;

#ifdef GL_ATOMIC_COUNTER_BUFFER
	x = ev.atomic_counter_buffer;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ATOMIC_COUNTER_BUFFER"
	) == 0);
#endif

#ifdef GL_SHADER_STORAGE_BUFFER
	x = ev.shader_storage_buffer;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SHADER_STORAGE_BUFFER"
	) == 0);
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BUFFER
	x = ev.transform_feedback_buffer;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TRANSFORM_FEEDBACK_BUFFER"
	) == 0);
#endif

#ifdef GL_UNIFORM_BUFFER
	x = ev.uniform_buffer;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"UNIFORM_BUFFER"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_buffer_indexed_target_range)
{
	using namespace oglplus;
	auto count = enum_value_range<buffer_indexed_target>().size();

#ifdef GL_ATOMIC_COUNTER_BUFFER
{
	--count;
	auto r = enum_value_range<buffer_indexed_target>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		buffer_indexed_target(GL_ATOMIC_COUNTER_BUFFER)
	) != r.end());
}
#endif

#ifdef GL_SHADER_STORAGE_BUFFER
{
	--count;
	auto r = enum_value_range<buffer_indexed_target>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		buffer_indexed_target(GL_SHADER_STORAGE_BUFFER)
	) != r.end());
}
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BUFFER
{
	--count;
	auto r = enum_value_range<buffer_indexed_target>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		buffer_indexed_target(GL_TRANSFORM_FEEDBACK_BUFFER)
	) != r.end());
}
#endif

#ifdef GL_UNIFORM_BUFFER
{
	--count;
	auto r = enum_value_range<buffer_indexed_target>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		buffer_indexed_target(GL_UNIFORM_BUFFER)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_buffer_indexed_target_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	buffer_indexed_target x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_ATOMIC_COUNTER_BUFFER
	x = ev.atomic_counter_buffer;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.atomic_counter_buffer);
#endif

#ifdef GL_SHADER_STORAGE_BUFFER
	x = ev.shader_storage_buffer;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.shader_storage_buffer);
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BUFFER
	x = ev.transform_feedback_buffer;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.transform_feedback_buffer);
#endif

#ifdef GL_UNIFORM_BUFFER
	x = ev.uniform_buffer;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.uniform_buffer);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
