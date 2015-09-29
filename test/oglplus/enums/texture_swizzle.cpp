//  File test/oglplus/enums/texture_swizzle.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_texture_swizzle

#include <boost/test/unit_test.hpp>
#include "common.hpp"

BOOST_AUTO_TEST_SUITE(enum_texture_swizzle)

BOOST_AUTO_TEST_CASE(enum_texture_swizzle_values)
{
	using namespace oglplus;
	enum_values ev;
	texture_swizzle x;

#ifdef GL_ALPHA
	x = ev.alpha;
	BOOST_CHECK(x == ev.alpha);
# ifdef GL_BLUE
	BOOST_CHECK(x != ev.blue);
# endif
# ifdef GL_GREEN
	BOOST_CHECK(x != ev.green);
# endif
# ifdef GL_ONE
	BOOST_CHECK(x != ev.one);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_ZERO
	BOOST_CHECK(x != ev.zero);
# endif
#endif

#ifdef GL_BLUE
	x = ev.blue;
# ifdef GL_ALPHA
	BOOST_CHECK(x != ev.alpha);
# endif
	BOOST_CHECK(x == ev.blue);
# ifdef GL_GREEN
	BOOST_CHECK(x != ev.green);
# endif
# ifdef GL_ONE
	BOOST_CHECK(x != ev.one);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_ZERO
	BOOST_CHECK(x != ev.zero);
# endif
#endif

#ifdef GL_GREEN
	x = ev.green;
# ifdef GL_ALPHA
	BOOST_CHECK(x != ev.alpha);
# endif
# ifdef GL_BLUE
	BOOST_CHECK(x != ev.blue);
# endif
	BOOST_CHECK(x == ev.green);
# ifdef GL_ONE
	BOOST_CHECK(x != ev.one);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_ZERO
	BOOST_CHECK(x != ev.zero);
# endif
#endif

#ifdef GL_ONE
	x = ev.one;
# ifdef GL_ALPHA
	BOOST_CHECK(x != ev.alpha);
# endif
# ifdef GL_BLUE
	BOOST_CHECK(x != ev.blue);
# endif
# ifdef GL_GREEN
	BOOST_CHECK(x != ev.green);
# endif
	BOOST_CHECK(x == ev.one);
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_ZERO
	BOOST_CHECK(x != ev.zero);
# endif
#endif

#ifdef GL_RED
	x = ev.red;
# ifdef GL_ALPHA
	BOOST_CHECK(x != ev.alpha);
# endif
# ifdef GL_BLUE
	BOOST_CHECK(x != ev.blue);
# endif
# ifdef GL_GREEN
	BOOST_CHECK(x != ev.green);
# endif
# ifdef GL_ONE
	BOOST_CHECK(x != ev.one);
# endif
	BOOST_CHECK(x == ev.red);
# ifdef GL_ZERO
	BOOST_CHECK(x != ev.zero);
# endif
#endif

#ifdef GL_ZERO
	x = ev.zero;
# ifdef GL_ALPHA
	BOOST_CHECK(x != ev.alpha);
# endif
# ifdef GL_BLUE
	BOOST_CHECK(x != ev.blue);
# endif
# ifdef GL_GREEN
	BOOST_CHECK(x != ev.green);
# endif
# ifdef GL_ONE
	BOOST_CHECK(x != ev.one);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
	BOOST_CHECK(x == ev.zero);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
