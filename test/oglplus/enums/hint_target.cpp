//  File test/oglplus/enums/hint_target.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_hint_target

#include <boost/test/unit_test.hpp>
#include "common.hpp"

BOOST_AUTO_TEST_SUITE(enum_hint_target)

BOOST_AUTO_TEST_CASE(enum_hint_target_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	hint_target x;
	(void)x;

#ifdef GL_FRAGMENT_SHADER_DERIVATIVE_HINT
	x = ev.fragment_shader_derivative_hint;
	BOOST_CHECK(x == ev.fragment_shader_derivative_hint);
# ifdef GL_LINE_SMOOTH_HINT
	BOOST_CHECK(x != ev.line_smooth_hint);
# endif
# ifdef GL_POLYGON_SMOOTH_HINT
	BOOST_CHECK(x != ev.polygon_smooth_hint);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
#endif

#ifdef GL_LINE_SMOOTH_HINT
	x = ev.line_smooth_hint;
# ifdef GL_FRAGMENT_SHADER_DERIVATIVE_HINT
	BOOST_CHECK(x != ev.fragment_shader_derivative_hint);
# endif
	BOOST_CHECK(x == ev.line_smooth_hint);
# ifdef GL_POLYGON_SMOOTH_HINT
	BOOST_CHECK(x != ev.polygon_smooth_hint);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
#endif

#ifdef GL_POLYGON_SMOOTH_HINT
	x = ev.polygon_smooth_hint;
# ifdef GL_FRAGMENT_SHADER_DERIVATIVE_HINT
	BOOST_CHECK(x != ev.fragment_shader_derivative_hint);
# endif
# ifdef GL_LINE_SMOOTH_HINT
	BOOST_CHECK(x != ev.line_smooth_hint);
# endif
	BOOST_CHECK(x == ev.polygon_smooth_hint);
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
#endif

#ifdef GL_TEXTURE_COMPRESSION_HINT
	x = ev.texture_compression_hint;
# ifdef GL_FRAGMENT_SHADER_DERIVATIVE_HINT
	BOOST_CHECK(x != ev.fragment_shader_derivative_hint);
# endif
# ifdef GL_LINE_SMOOTH_HINT
	BOOST_CHECK(x != ev.line_smooth_hint);
# endif
# ifdef GL_POLYGON_SMOOTH_HINT
	BOOST_CHECK(x != ev.polygon_smooth_hint);
# endif
	BOOST_CHECK(x == ev.texture_compression_hint);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
