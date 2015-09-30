//  File test/oglplus/enums/context_profile_bits.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_context_profile_bits

#include <boost/test/unit_test.hpp>
#include "common.hpp"

BOOST_AUTO_TEST_SUITE(enum_context_profile_bits)

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
# ifdef GL_CONTEXT_COMPATIBILITY_PROFILE_BIT
	BOOST_CHECK(x != ev.context_compatibility_profile_bit);
# endif
	BOOST_CHECK(x == ev.context_core_profile_bit);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
