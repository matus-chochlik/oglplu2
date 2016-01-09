//  File test/oglplus/enums/error_code.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_error_code

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_error_code_tests)

BOOST_AUTO_TEST_CASE(enum_error_code_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	error_code x;
	(void)x;

#ifdef GL_CONTEXT_LOST
	x = ev.context_lost;
	BOOST_CHECK(x == ev.context_lost);
# ifdef GL_INVALID_ENUM
	BOOST_CHECK(x != ev.invalid_enum);
# endif
# ifdef GL_INVALID_FRAMEBUFFER_OPERATION
	BOOST_CHECK(x != ev.invalid_framebuffer_operation);
# endif
# ifdef GL_INVALID_OPERATION
	BOOST_CHECK(x != ev.invalid_operation);
# endif
# ifdef GL_INVALID_VALUE
	BOOST_CHECK(x != ev.invalid_value);
# endif
# ifdef GL_NO_ERROR
	BOOST_CHECK(x != ev.no_error);
# endif
# ifdef GL_OUT_OF_MEMORY
	BOOST_CHECK(x != ev.out_of_memory);
# endif
# ifdef GL_STACK_OVERFLOW
	BOOST_CHECK(x != ev.stack_overflow);
# endif
# ifdef GL_STACK_UNDERFLOW
	BOOST_CHECK(x != ev.stack_underflow);
# endif
# ifdef GL_TABLE_TOO_LARGE
	BOOST_CHECK(x != ev.table_too_large);
# endif
#endif

#ifdef GL_INVALID_ENUM
	x = ev.invalid_enum;
	BOOST_CHECK(x == ev.invalid_enum);
# ifdef GL_INVALID_FRAMEBUFFER_OPERATION
	BOOST_CHECK(x != ev.invalid_framebuffer_operation);
# endif
# ifdef GL_INVALID_OPERATION
	BOOST_CHECK(x != ev.invalid_operation);
# endif
# ifdef GL_INVALID_VALUE
	BOOST_CHECK(x != ev.invalid_value);
# endif
# ifdef GL_NO_ERROR
	BOOST_CHECK(x != ev.no_error);
# endif
# ifdef GL_OUT_OF_MEMORY
	BOOST_CHECK(x != ev.out_of_memory);
# endif
# ifdef GL_STACK_OVERFLOW
	BOOST_CHECK(x != ev.stack_overflow);
# endif
# ifdef GL_STACK_UNDERFLOW
	BOOST_CHECK(x != ev.stack_underflow);
# endif
# ifdef GL_TABLE_TOO_LARGE
	BOOST_CHECK(x != ev.table_too_large);
# endif
#endif

#ifdef GL_INVALID_FRAMEBUFFER_OPERATION
	x = ev.invalid_framebuffer_operation;
	BOOST_CHECK(x == ev.invalid_framebuffer_operation);
# ifdef GL_INVALID_OPERATION
	BOOST_CHECK(x != ev.invalid_operation);
# endif
# ifdef GL_INVALID_VALUE
	BOOST_CHECK(x != ev.invalid_value);
# endif
# ifdef GL_NO_ERROR
	BOOST_CHECK(x != ev.no_error);
# endif
# ifdef GL_OUT_OF_MEMORY
	BOOST_CHECK(x != ev.out_of_memory);
# endif
# ifdef GL_STACK_OVERFLOW
	BOOST_CHECK(x != ev.stack_overflow);
# endif
# ifdef GL_STACK_UNDERFLOW
	BOOST_CHECK(x != ev.stack_underflow);
# endif
# ifdef GL_TABLE_TOO_LARGE
	BOOST_CHECK(x != ev.table_too_large);
# endif
#endif

#ifdef GL_INVALID_OPERATION
	x = ev.invalid_operation;
	BOOST_CHECK(x == ev.invalid_operation);
# ifdef GL_INVALID_VALUE
	BOOST_CHECK(x != ev.invalid_value);
# endif
# ifdef GL_NO_ERROR
	BOOST_CHECK(x != ev.no_error);
# endif
# ifdef GL_OUT_OF_MEMORY
	BOOST_CHECK(x != ev.out_of_memory);
# endif
# ifdef GL_STACK_OVERFLOW
	BOOST_CHECK(x != ev.stack_overflow);
# endif
# ifdef GL_STACK_UNDERFLOW
	BOOST_CHECK(x != ev.stack_underflow);
# endif
# ifdef GL_TABLE_TOO_LARGE
	BOOST_CHECK(x != ev.table_too_large);
# endif
#endif

#ifdef GL_INVALID_VALUE
	x = ev.invalid_value;
	BOOST_CHECK(x == ev.invalid_value);
# ifdef GL_NO_ERROR
	BOOST_CHECK(x != ev.no_error);
# endif
# ifdef GL_OUT_OF_MEMORY
	BOOST_CHECK(x != ev.out_of_memory);
# endif
# ifdef GL_STACK_OVERFLOW
	BOOST_CHECK(x != ev.stack_overflow);
# endif
# ifdef GL_STACK_UNDERFLOW
	BOOST_CHECK(x != ev.stack_underflow);
# endif
# ifdef GL_TABLE_TOO_LARGE
	BOOST_CHECK(x != ev.table_too_large);
# endif
#endif

#ifdef GL_NO_ERROR
	x = ev.no_error;
	BOOST_CHECK(x == ev.no_error);
# ifdef GL_OUT_OF_MEMORY
	BOOST_CHECK(x != ev.out_of_memory);
# endif
# ifdef GL_STACK_OVERFLOW
	BOOST_CHECK(x != ev.stack_overflow);
# endif
# ifdef GL_STACK_UNDERFLOW
	BOOST_CHECK(x != ev.stack_underflow);
# endif
# ifdef GL_TABLE_TOO_LARGE
	BOOST_CHECK(x != ev.table_too_large);
# endif
#endif

#ifdef GL_OUT_OF_MEMORY
	x = ev.out_of_memory;
	BOOST_CHECK(x == ev.out_of_memory);
# ifdef GL_STACK_OVERFLOW
	BOOST_CHECK(x != ev.stack_overflow);
# endif
# ifdef GL_STACK_UNDERFLOW
	BOOST_CHECK(x != ev.stack_underflow);
# endif
# ifdef GL_TABLE_TOO_LARGE
	BOOST_CHECK(x != ev.table_too_large);
# endif
#endif

#ifdef GL_STACK_OVERFLOW
	x = ev.stack_overflow;
	BOOST_CHECK(x == ev.stack_overflow);
# ifdef GL_STACK_UNDERFLOW
	BOOST_CHECK(x != ev.stack_underflow);
# endif
# ifdef GL_TABLE_TOO_LARGE
	BOOST_CHECK(x != ev.table_too_large);
# endif
#endif

#ifdef GL_STACK_UNDERFLOW
	x = ev.stack_underflow;
	BOOST_CHECK(x == ev.stack_underflow);
# ifdef GL_TABLE_TOO_LARGE
	BOOST_CHECK(x != ev.table_too_large);
# endif
#endif

#ifdef GL_TABLE_TOO_LARGE
	x = ev.table_too_large;
	BOOST_CHECK(x == ev.table_too_large);
#endif
}

BOOST_AUTO_TEST_CASE(enum_error_code_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	error_code x;
	(void)x;

#ifdef GL_CONTEXT_LOST
	x = ev.context_lost;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"CONTEXT_LOST"
	) == 0);
#endif

#ifdef GL_INVALID_ENUM
	x = ev.invalid_enum;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"INVALID_ENUM"
	) == 0);
#endif

#ifdef GL_INVALID_FRAMEBUFFER_OPERATION
	x = ev.invalid_framebuffer_operation;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"INVALID_FRAMEBUFFER_OPERATION"
	) == 0);
#endif

#ifdef GL_INVALID_OPERATION
	x = ev.invalid_operation;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"INVALID_OPERATION"
	) == 0);
#endif

#ifdef GL_INVALID_VALUE
	x = ev.invalid_value;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"INVALID_VALUE"
	) == 0);
#endif

#ifdef GL_NO_ERROR
	x = ev.no_error;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"NO_ERROR"
	) == 0);
#endif

#ifdef GL_OUT_OF_MEMORY
	x = ev.out_of_memory;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"OUT_OF_MEMORY"
	) == 0);
#endif

#ifdef GL_STACK_OVERFLOW
	x = ev.stack_overflow;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"STACK_OVERFLOW"
	) == 0);
#endif

#ifdef GL_STACK_UNDERFLOW
	x = ev.stack_underflow;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"STACK_UNDERFLOW"
	) == 0);
#endif

#ifdef GL_TABLE_TOO_LARGE
	x = ev.table_too_large;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TABLE_TOO_LARGE"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_error_code_range)
{
	using namespace oglplus;
	auto count = enum_value_range<error_code>().size();

#ifdef GL_CONTEXT_LOST
{
	--count;
	auto r = enum_value_range<error_code>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		error_code(GL_CONTEXT_LOST)
	) != r.end());
}
#endif

#ifdef GL_INVALID_ENUM
{
	--count;
	auto r = enum_value_range<error_code>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		error_code(GL_INVALID_ENUM)
	) != r.end());
}
#endif

#ifdef GL_INVALID_FRAMEBUFFER_OPERATION
{
	--count;
	auto r = enum_value_range<error_code>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		error_code(GL_INVALID_FRAMEBUFFER_OPERATION)
	) != r.end());
}
#endif

#ifdef GL_INVALID_OPERATION
{
	--count;
	auto r = enum_value_range<error_code>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		error_code(GL_INVALID_OPERATION)
	) != r.end());
}
#endif

#ifdef GL_INVALID_VALUE
{
	--count;
	auto r = enum_value_range<error_code>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		error_code(GL_INVALID_VALUE)
	) != r.end());
}
#endif

#ifdef GL_NO_ERROR
{
	--count;
	auto r = enum_value_range<error_code>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		error_code(GL_NO_ERROR)
	) != r.end());
}
#endif

#ifdef GL_OUT_OF_MEMORY
{
	--count;
	auto r = enum_value_range<error_code>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		error_code(GL_OUT_OF_MEMORY)
	) != r.end());
}
#endif

#ifdef GL_STACK_OVERFLOW
{
	--count;
	auto r = enum_value_range<error_code>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		error_code(GL_STACK_OVERFLOW)
	) != r.end());
}
#endif

#ifdef GL_STACK_UNDERFLOW
{
	--count;
	auto r = enum_value_range<error_code>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		error_code(GL_STACK_UNDERFLOW)
	) != r.end());
}
#endif

#ifdef GL_TABLE_TOO_LARGE
{
	--count;
	auto r = enum_value_range<error_code>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		error_code(GL_TABLE_TOO_LARGE)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_error_code_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	error_code x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_CONTEXT_LOST
	x = ev.context_lost;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.context_lost);
#endif

#ifdef GL_INVALID_ENUM
	x = ev.invalid_enum;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.invalid_enum);
#endif

#ifdef GL_INVALID_FRAMEBUFFER_OPERATION
	x = ev.invalid_framebuffer_operation;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.invalid_framebuffer_operation);
#endif

#ifdef GL_INVALID_OPERATION
	x = ev.invalid_operation;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.invalid_operation);
#endif

#ifdef GL_INVALID_VALUE
	x = ev.invalid_value;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.invalid_value);
#endif

#ifdef GL_NO_ERROR
	x = ev.no_error;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.no_error);
#endif

#ifdef GL_OUT_OF_MEMORY
	x = ev.out_of_memory;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.out_of_memory);
#endif

#ifdef GL_STACK_OVERFLOW
	x = ev.stack_overflow;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.stack_overflow);
#endif

#ifdef GL_STACK_UNDERFLOW
	x = ev.stack_underflow;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.stack_underflow);
#endif

#ifdef GL_TABLE_TOO_LARGE
	x = ev.table_too_large;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.table_too_large);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
