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

BOOST_AUTO_TEST_SUITE(enum_blend_equation_tests)

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
	BOOST_CHECK(x == ev.max);
# ifdef GL_MIN
	BOOST_CHECK(x != ev.min);
# endif
#endif

#ifdef GL_MIN
	x = ev.min;
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
	auto count = enum_value_range<blend_equation>().size();

#ifdef GL_FUNC_ADD
{
	--count;
	auto r = enum_value_range<blend_equation>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		blend_equation(GL_FUNC_ADD)
	) != r.end());
}
#endif

#ifdef GL_FUNC_REVERSE_SUBTRACT
{
	--count;
	auto r = enum_value_range<blend_equation>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		blend_equation(GL_FUNC_REVERSE_SUBTRACT)
	) != r.end());
}
#endif

#ifdef GL_FUNC_SUBTRACT
{
	--count;
	auto r = enum_value_range<blend_equation>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		blend_equation(GL_FUNC_SUBTRACT)
	) != r.end());
}
#endif

#ifdef GL_MAX
{
	--count;
	auto r = enum_value_range<blend_equation>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		blend_equation(GL_MAX)
	) != r.end());
}
#endif

#ifdef GL_MIN
{
	--count;
	auto r = enum_value_range<blend_equation>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		blend_equation(GL_MIN)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_blend_equation_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	blend_equation x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_FUNC_ADD
	x = ev.func_add;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.func_add);
#endif

#ifdef GL_FUNC_REVERSE_SUBTRACT
	x = ev.func_reverse_subtract;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.func_reverse_subtract);
#endif

#ifdef GL_FUNC_SUBTRACT
	x = ev.func_subtract;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.func_subtract);
#endif

#ifdef GL_MAX
	x = ev.max;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max);
#endif

#ifdef GL_MIN
	x = ev.min;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.min);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
