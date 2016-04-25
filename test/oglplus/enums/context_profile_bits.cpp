//  File test/oglplus/enums/context_profile_bits.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_context_profile_bits

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_context_profile_bits_tests)

BOOST_AUTO_TEST_CASE(enum_context_profile_bits_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	context_profile_bits x;
	(void)x;

#ifdef GL_CONTEXT_COMPATIBILITY_PROFILE_BIT
	x = ev.context_compatibility_profile_bit;
	BOOST_CHECK(x == ev.context_compatibility_profile_bit);
# ifdef GL_CONTEXT_CORE_PROFILE_BIT
	BOOST_CHECK(x != ev.context_core_profile_bit);
# endif
#endif

#ifdef GL_CONTEXT_CORE_PROFILE_BIT
	x = ev.context_core_profile_bit;
	BOOST_CHECK(x == ev.context_core_profile_bit);
#endif
}

BOOST_AUTO_TEST_CASE(enum_context_profile_bits_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	context_profile_bits x;
	(void)x;

#ifdef GL_CONTEXT_COMPATIBILITY_PROFILE_BIT
	x = ev.context_compatibility_profile_bit;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"CONTEXT_COMPATIBILITY_PROFILE_BIT"
	) == 0);
#endif

#ifdef GL_CONTEXT_CORE_PROFILE_BIT
	x = ev.context_core_profile_bit;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"CONTEXT_CORE_PROFILE_BIT"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_context_profile_bits_range)
{
	using namespace oglplus;
	auto count = enum_value_range<context_profile_bits>().size();

#ifdef GL_CONTEXT_COMPATIBILITY_PROFILE_BIT
{
	--count;
	auto r = enum_value_range<context_profile_bits>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		context_profile_bits(GL_CONTEXT_COMPATIBILITY_PROFILE_BIT)
	) != r.end());
}
#endif

#ifdef GL_CONTEXT_CORE_PROFILE_BIT
{
	--count;
	auto r = enum_value_range<context_profile_bits>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		context_profile_bits(GL_CONTEXT_CORE_PROFILE_BIT)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_context_profile_bits_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	context_profile_bits x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_CONTEXT_COMPATIBILITY_PROFILE_BIT
	x = ev.context_compatibility_profile_bit;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.context_compatibility_profile_bit);
#endif

#ifdef GL_CONTEXT_CORE_PROFILE_BIT
	x = ev.context_core_profile_bit;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.context_core_profile_bit);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
