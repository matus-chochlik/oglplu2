//  File test/oglplus/enums/framebuffer_target.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_framebuffer_target

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_framebuffer_target)

BOOST_AUTO_TEST_CASE(enum_framebuffer_target_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	framebuffer_target x;
	(void)x;

#ifdef GL_DRAW_FRAMEBUFFER
	x = ev.draw_framebuffer;
	BOOST_CHECK(x == ev.draw_framebuffer);
# ifdef GL_READ_FRAMEBUFFER
	BOOST_CHECK(x != ev.read_framebuffer);
# endif
#endif

#ifdef GL_READ_FRAMEBUFFER
	x = ev.read_framebuffer;
# ifdef GL_DRAW_FRAMEBUFFER
	BOOST_CHECK(x != ev.draw_framebuffer);
# endif
	BOOST_CHECK(x == ev.read_framebuffer);
#endif
}

BOOST_AUTO_TEST_CASE(enum_framebuffer_target_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	framebuffer_target x;
	(void)x;

#ifdef GL_DRAW_FRAMEBUFFER
	x = ev.draw_framebuffer;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DRAW_FRAMEBUFFER"
	) == 0);
#endif

#ifdef GL_READ_FRAMEBUFFER
	x = ev.read_framebuffer;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"READ_FRAMEBUFFER"
	) == 0);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
