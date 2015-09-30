//  File test/oglplus/enums/provoke_mode.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_provoke_mode

#include <boost/test/unit_test.hpp>
#include "common.hpp"

BOOST_AUTO_TEST_SUITE(enum_provoke_mode)

BOOST_AUTO_TEST_CASE(enum_provoke_mode_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	provoke_mode x;
	(void)x;

#ifdef GL_FIRST_VERTEX_CONVENTION
	x = ev.first_vertex_convention;
	BOOST_CHECK(x == ev.first_vertex_convention);
# ifdef GL_LAST_VERTEX_CONVENTION
	BOOST_CHECK(x != ev.last_vertex_convention);
# endif
#endif

#ifdef GL_LAST_VERTEX_CONVENTION
	x = ev.last_vertex_convention;
# ifdef GL_FIRST_VERTEX_CONVENTION
	BOOST_CHECK(x != ev.first_vertex_convention);
# endif
	BOOST_CHECK(x == ev.last_vertex_convention);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
