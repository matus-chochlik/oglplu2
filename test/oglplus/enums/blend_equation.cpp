//  File test/oglplus/enums/blend_equation.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_blend_equation

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_blend_equation)

BOOST_AUTO_TEST_CASE(enum_blend_equation_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	blend_equation x;
	(void)x;

#ifdef GL_FUNC_ADD
	x = ev.func_add;
	BOOST_CHECK(x == ev.func_add);
# ifdef GL_FUNC_REVERSE_SUBTRACT
	BOOST_CHECK(x != ev.func_reverse_subtract);
# endif
# ifdef GL_FUNC_SUBTRACT
	BOOST_CHECK(x != ev.func_subtract);
# endif
# ifdef GL_MAX
	BOOST_CHECK(x != ev.max);
# endif
# ifdef GL_MIN
	BOOST_CHECK(x != ev.min);
# endif
#endif

#ifdef GL_FUNC_REVERSE_SUBTRACT
	x = ev.func_reverse_subtract;
# ifdef GL_FUNC_ADD
	BOOST_CHECK(x != ev.func_add);
# endif
	BOOST_CHECK(x == ev.func_reverse_subtract);
# ifdef GL_FUNC_SUBTRACT
	BOOST_CHECK(x != ev.func_subtract);
# endif
# ifdef GL_MAX
	BOOST_CHECK(x != ev.max);
# endif
# ifdef GL_MIN
	BOOST_CHECK(x != ev.min);
# endif
#endif

#ifdef GL_FUNC_SUBTRACT
	x = ev.func_subtract;
# ifdef GL_FUNC_ADD
	BOOST_CHECK(x != ev.func_add);
# endif
# ifdef GL_FUNC_REVERSE_SUBTRACT
	BOOST_CHECK(x != ev.func_reverse_subtract);
# endif
	BOOST_CHECK(x == ev.func_subtract);
# ifdef GL_MAX
	BOOST_CHECK(x != ev.max);
# endif
# ifdef GL_MIN
	BOOST_CHECK(x != ev.min);
# endif
#endif

#ifdef GL_MAX
	x = ev.max;
# ifdef GL_FUNC_ADD
	BOOST_CHECK(x != ev.func_add);
# endif
# ifdef GL_FUNC_REVERSE_SUBTRACT
	BOOST_CHECK(x != ev.func_reverse_subtract);
# endif
# ifdef GL_FUNC_SUBTRACT
	BOOST_CHECK(x != ev.func_subtract);
# endif
	BOOST_CHECK(x == ev.max);
# ifdef GL_MIN
	BOOST_CHECK(x != ev.min);
# endif
#endif

#ifdef GL_MIN
	x = ev.min;
# ifdef GL_FUNC_ADD
	BOOST_CHECK(x != ev.func_add);
# endif
# ifdef GL_FUNC_REVERSE_SUBTRACT
	BOOST_CHECK(x != ev.func_reverse_subtract);
# endif
# ifdef GL_FUNC_SUBTRACT
	BOOST_CHECK(x != ev.func_subtract);
# endif
# ifdef GL_MAX
	BOOST_CHECK(x != ev.max);
# endif
	BOOST_CHECK(x == ev.min);
#endif
}

BOOST_AUTO_TEST_CASE(enum_blend_equation_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	blend_equation x;
	(void)x;

#ifdef GL_FUNC_ADD
	x = ev.func_add;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"FUNC_ADD"
	) == 0);
#endif

#ifdef GL_FUNC_REVERSE_SUBTRACT
	x = ev.func_reverse_subtract;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"FUNC_REVERSE_SUBTRACT"
	) == 0);
#endif

#ifdef GL_FUNC_SUBTRACT
	x = ev.func_subtract;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"FUNC_SUBTRACT"
	) == 0);
#endif

#ifdef GL_MAX
	x = ev.max;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX"
	) == 0);
#endif

#ifdef GL_MIN
	x = ev.min;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MIN"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_blend_equation_range)
{
	using namespace oglplus;
	blend_equation x;
	(void)x;
	auto count = enum_value_range(x).size();

#ifdef GL_FUNC_ADD
{
	--count;
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_FUNC_ADD
	) != r.end());
}
#endif

#ifdef GL_FUNC_REVERSE_SUBTRACT
{
	--count;
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_FUNC_REVERSE_SUBTRACT
	) != r.end());
}
#endif

#ifdef GL_FUNC_SUBTRACT
{
	--count;
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_FUNC_SUBTRACT
	) != r.end());
}
#endif

#ifdef GL_MAX
{
	--count;
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_MAX
	) != r.end());
}
#endif

#ifdef GL_MIN
{
	--count;
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_MIN
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_SUITE_END()
