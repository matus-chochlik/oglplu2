//  File test/oglplus/enums/blend_equation.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_blend_equation

#include <boost/test/unit_test.hpp>
#include "common.hpp"

BOOST_AUTO_TEST_SUITE(enum_blend_equation)

BOOST_AUTO_TEST_CASE(enum_blend_equation_values)
{
	using namespace oglplus;
	enum_values ev;
	blend_equation x;

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

BOOST_AUTO_TEST_SUITE_END()
