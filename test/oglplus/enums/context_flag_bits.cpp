//  File test/oglplus/enums/context_flag_bits.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_context_flag_bits

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_context_flag_bits_tests)

BOOST_AUTO_TEST_CASE(enum_context_flag_bits_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	context_flag_bits x;
	(void)x;

#ifdef GL_CONTEXT_FLAG_DEBUG_BIT
	x = ev.context_flag_debug_bit;
	BOOST_CHECK(x == ev.context_flag_debug_bit);
# ifdef GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT
	BOOST_CHECK(x != ev.context_flag_forward_compatible_bit);
# endif
# ifdef GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT_ARB
	BOOST_CHECK(x != ev.context_flag_robust_access_bit);
# endif
#endif

#ifdef GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT
	x = ev.context_flag_forward_compatible_bit;
	BOOST_CHECK(x == ev.context_flag_forward_compatible_bit);
# ifdef GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT_ARB
	BOOST_CHECK(x != ev.context_flag_robust_access_bit);
# endif
#endif

#ifdef GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT_ARB
	x = ev.context_flag_robust_access_bit;
	BOOST_CHECK(x == ev.context_flag_robust_access_bit);
#endif
}

BOOST_AUTO_TEST_CASE(enum_context_flag_bits_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	context_flag_bits x;
	(void)x;

#ifdef GL_CONTEXT_FLAG_DEBUG_BIT
	x = ev.context_flag_debug_bit;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"CONTEXT_FLAG_DEBUG_BIT"
	) == 0);
#endif

#ifdef GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT
	x = ev.context_flag_forward_compatible_bit;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT"
	) == 0);
#endif

#ifdef GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT_ARB
	x = ev.context_flag_robust_access_bit;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"CONTEXT_FLAG_ROBUST_ACCESS_BIT_ARB"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_context_flag_bits_range)
{
	using namespace oglplus;
	auto count = enum_value_range<context_flag_bits>().size();

#ifdef GL_CONTEXT_FLAG_DEBUG_BIT
{
	--count;
	auto r = enum_value_range<context_flag_bits>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		context_flag_bits(GL_CONTEXT_FLAG_DEBUG_BIT)
	) != r.end());
}
#endif

#ifdef GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT
{
	--count;
	auto r = enum_value_range<context_flag_bits>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		context_flag_bits(GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT)
	) != r.end());
}
#endif

#ifdef GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT_ARB
{
	--count;
	auto r = enum_value_range<context_flag_bits>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		context_flag_bits(GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT_ARB)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_context_flag_bits_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	context_flag_bits x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_CONTEXT_FLAG_DEBUG_BIT
	x = ev.context_flag_debug_bit;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.context_flag_debug_bit);
#endif

#ifdef GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT
	x = ev.context_flag_forward_compatible_bit;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.context_flag_forward_compatible_bit);
#endif

#ifdef GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT_ARB
	x = ev.context_flag_robust_access_bit;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.context_flag_robust_access_bit);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
