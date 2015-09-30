//  File test/oglplus/enums/texture_wrap_coord.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_texture_wrap_coord

#include <boost/test/unit_test.hpp>
#include "common.hpp"

BOOST_AUTO_TEST_SUITE(enum_texture_wrap_coord)

BOOST_AUTO_TEST_CASE(enum_texture_wrap_coord_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	texture_wrap_coord x;
	(void)x;

#ifdef GL_TEXTURE_WRAP_R
	x = ev.texture_wrap_r;
	BOOST_CHECK(x == ev.texture_wrap_r);
# ifdef GL_TEXTURE_WRAP_S
	BOOST_CHECK(x != ev.texture_wrap_s);
# endif
# ifdef GL_TEXTURE_WRAP_T
	BOOST_CHECK(x != ev.texture_wrap_t);
# endif
#endif

#ifdef GL_TEXTURE_WRAP_S
	x = ev.texture_wrap_s;
# ifdef GL_TEXTURE_WRAP_R
	BOOST_CHECK(x != ev.texture_wrap_r);
# endif
	BOOST_CHECK(x == ev.texture_wrap_s);
# ifdef GL_TEXTURE_WRAP_T
	BOOST_CHECK(x != ev.texture_wrap_t);
# endif
#endif

#ifdef GL_TEXTURE_WRAP_T
	x = ev.texture_wrap_t;
# ifdef GL_TEXTURE_WRAP_R
	BOOST_CHECK(x != ev.texture_wrap_r);
# endif
# ifdef GL_TEXTURE_WRAP_S
	BOOST_CHECK(x != ev.texture_wrap_s);
# endif
	BOOST_CHECK(x == ev.texture_wrap_t);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
