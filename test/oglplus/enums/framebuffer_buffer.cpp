//  File test/oglplus/enums/framebuffer_buffer.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_framebuffer_buffer

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_framebuffer_buffer_tests)

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
	BOOST_CHECK(x == ev.depth_stencil);
# ifdef GL_STENCIL
	BOOST_CHECK(x != ev.stencil);
# endif
#endif

#ifdef GL_STENCIL
	x = ev.stencil;
	BOOST_CHECK(x == ev.stencil);
#endif
}

BOOST_AUTO_TEST_CASE(enum_framebuffer_buffer_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	framebuffer_buffer x;
	(void)x;

#ifdef GL_COLOR
	x = ev.color;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"COLOR"
	) == 0);
#endif

#ifdef GL_DEPTH
	x = ev.depth;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DEPTH"
	) == 0);
#endif

#ifdef GL_DEPTH_STENCIL
	x = ev.depth_stencil;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DEPTH_STENCIL"
	) == 0);
#endif

#ifdef GL_STENCIL
	x = ev.stencil;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"STENCIL"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_framebuffer_buffer_range)
{
	using namespace oglplus;
	auto count = enum_value_range<framebuffer_buffer>().size();

#ifdef GL_COLOR
{
	--count;
	auto r = enum_value_range<framebuffer_buffer>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		framebuffer_buffer(GL_COLOR)
	) != r.end());
}
#endif

#ifdef GL_DEPTH
{
	--count;
	auto r = enum_value_range<framebuffer_buffer>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		framebuffer_buffer(GL_DEPTH)
	) != r.end());
}
#endif

#ifdef GL_DEPTH_STENCIL
{
	--count;
	auto r = enum_value_range<framebuffer_buffer>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		framebuffer_buffer(GL_DEPTH_STENCIL)
	) != r.end());
}
#endif

#ifdef GL_STENCIL
{
	--count;
	auto r = enum_value_range<framebuffer_buffer>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		framebuffer_buffer(GL_STENCIL)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_framebuffer_buffer_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	framebuffer_buffer x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_COLOR
	x = ev.color;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.color);
#endif

#ifdef GL_DEPTH
	x = ev.depth;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.depth);
#endif

#ifdef GL_DEPTH_STENCIL
	x = ev.depth_stencil;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.depth_stencil);
#endif

#ifdef GL_STENCIL
	x = ev.stencil;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.stencil);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
