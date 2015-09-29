//  File test/oglplus/enums/named_string_type.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_named_string_type

#include <boost/test/unit_test.hpp>
#include "common.hpp"

BOOST_AUTO_TEST_SUITE(enum_named_string_type)

BOOST_AUTO_TEST_CASE(enum_named_string_type_values)
{
	using namespace oglplus;
	enum_values ev;
	named_string_type x;

#ifdef GL_SHADER_INCLUDE_ARB
	x = ev.shader_include;
	BOOST_CHECK(x == ev.shader_include);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
