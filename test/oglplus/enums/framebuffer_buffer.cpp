//  File test/oglplus/enums/framebuffer_buffer.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_framebuffer_buffer

#include <boost/test/unit_test.hpp>
#include "common.hpp"

BOOST_AUTO_TEST_SUITE(enum_framebuffer_buffer)

BOOST_AUTO_TEST_CASE(enum_framebuffer_buffer_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	framebuffer_buffer x;
	(void)x;

#ifdef GL_COLOR
	x = ev.color;
	BOOST_CHECK(x == ev.color);
# ifdef GL_DEPTH
	BOOST_CHECK(x != ev.depth);
# endif
# ifdef GL_DEPTH_STENCIL
	BOOST_CHECK(x != ev.depth_stencil);
# endif
# ifdef GL_STENCIL
	BOOST_CHECK(x != ev.stencil);
# endif
#endif

#ifdef GL_DEPTH
	x = ev.depth;
# ifdef GL_COLOR
	BOOST_CHECK(x != ev.color);
# endif
	BOOST_CHECK(x == ev.depth);
# ifdef GL_DEPTH_STENCIL
	BOOST_CHECK(x != ev.depth_stencil);
# endif
# ifdef GL_STENCIL
	BOOST_CHECK(x != ev.stencil);
# endif
#endif

#ifdef GL_DEPTH_STENCIL
	x = ev.depth_stencil;
# ifdef GL_COLOR
	BOOST_CHECK(x != ev.color);
# endif
# ifdef GL_DEPTH
	BOOST_CHECK(x != ev.depth);
# endif
	BOOST_CHECK(x == ev.depth_stencil);
# ifdef GL_STENCIL
	BOOST_CHECK(x != ev.stencil);
# endif
#endif

#ifdef GL_STENCIL
	x = ev.stencil;
# ifdef GL_COLOR
	BOOST_CHECK(x != ev.color);
# endif
# ifdef GL_DEPTH
	BOOST_CHECK(x != ev.depth);
# endif
# ifdef GL_DEPTH_STENCIL
	BOOST_CHECK(x != ev.depth_stencil);
# endif
	BOOST_CHECK(x == ev.stencil);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
