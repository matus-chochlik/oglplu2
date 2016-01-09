//  File test/oglplus/enums/transform_feedback_parameter.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_transform_feedback_parameter

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_transform_feedback_parameter_tests)

BOOST_AUTO_TEST_CASE(enum_transform_feedback_parameter_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	transform_feedback_parameter x;
	(void)x;

#ifdef GL_TRANSFORM_FEEDBACK_ACTIVE
	x = ev.transform_feedback_active;
	BOOST_CHECK(x == ev.transform_feedback_active);
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_BINDING
	BOOST_CHECK(x != ev.transform_feedback_buffer_binding);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_PAUSED
	BOOST_CHECK(x != ev.transform_feedback_paused);
# endif
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_BINDING
	x = ev.transform_feedback_buffer_binding;
	BOOST_CHECK(x == ev.transform_feedback_buffer_binding);
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_PAUSED
	BOOST_CHECK(x != ev.transform_feedback_paused);
# endif
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	x = ev.transform_feedback_buffer_size;
	BOOST_CHECK(x == ev.transform_feedback_buffer_size);
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_PAUSED
	BOOST_CHECK(x != ev.transform_feedback_paused);
# endif
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	x = ev.transform_feedback_buffer_start;
	BOOST_CHECK(x == ev.transform_feedback_buffer_start);
# ifdef GL_TRANSFORM_FEEDBACK_PAUSED
	BOOST_CHECK(x != ev.transform_feedback_paused);
# endif
#endif

#ifdef GL_TRANSFORM_FEEDBACK_PAUSED
	x = ev.transform_feedback_paused;
	BOOST_CHECK(x == ev.transform_feedback_paused);
#endif
}

BOOST_AUTO_TEST_CASE(enum_transform_feedback_parameter_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	transform_feedback_parameter x;
	(void)x;

#ifdef GL_TRANSFORM_FEEDBACK_ACTIVE
	x = ev.transform_feedback_active;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TRANSFORM_FEEDBACK_ACTIVE"
	) == 0);
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_BINDING
	x = ev.transform_feedback_buffer_binding;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TRANSFORM_FEEDBACK_BUFFER_BINDING"
	) == 0);
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	x = ev.transform_feedback_buffer_size;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TRANSFORM_FEEDBACK_BUFFER_SIZE"
	) == 0);
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	x = ev.transform_feedback_buffer_start;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TRANSFORM_FEEDBACK_BUFFER_START"
	) == 0);
#endif

#ifdef GL_TRANSFORM_FEEDBACK_PAUSED
	x = ev.transform_feedback_paused;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TRANSFORM_FEEDBACK_PAUSED"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_transform_feedback_parameter_range)
{
	using namespace oglplus;
	auto count = enum_value_range<transform_feedback_parameter>().size();

#ifdef GL_TRANSFORM_FEEDBACK_ACTIVE
{
	--count;
	auto r = enum_value_range<transform_feedback_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		transform_feedback_parameter(GL_TRANSFORM_FEEDBACK_ACTIVE)
	) != r.end());
}
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_BINDING
{
	--count;
	auto r = enum_value_range<transform_feedback_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		transform_feedback_parameter(GL_TRANSFORM_FEEDBACK_BUFFER_BINDING)
	) != r.end());
}
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
{
	--count;
	auto r = enum_value_range<transform_feedback_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		transform_feedback_parameter(GL_TRANSFORM_FEEDBACK_BUFFER_SIZE)
	) != r.end());
}
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
{
	--count;
	auto r = enum_value_range<transform_feedback_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		transform_feedback_parameter(GL_TRANSFORM_FEEDBACK_BUFFER_START)
	) != r.end());
}
#endif

#ifdef GL_TRANSFORM_FEEDBACK_PAUSED
{
	--count;
	auto r = enum_value_range<transform_feedback_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		transform_feedback_parameter(GL_TRANSFORM_FEEDBACK_PAUSED)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_transform_feedback_parameter_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	transform_feedback_parameter x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_TRANSFORM_FEEDBACK_ACTIVE
	x = ev.transform_feedback_active;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.transform_feedback_active);
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_BINDING
	x = ev.transform_feedback_buffer_binding;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.transform_feedback_buffer_binding);
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	x = ev.transform_feedback_buffer_size;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.transform_feedback_buffer_size);
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	x = ev.transform_feedback_buffer_start;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.transform_feedback_buffer_start);
#endif

#ifdef GL_TRANSFORM_FEEDBACK_PAUSED
	x = ev.transform_feedback_paused;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.transform_feedback_paused);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
