//  File test/eglplus/enums/gl_colorspace.cpp
//
//  Automatically generated file, DO NOT modify manually.
//  Edit the enumeration source files in 'source/enums/eglplus'
//  or the 'source/enums/make_enum.py' script instead.
//
//  Copyright Matus Chochlik.
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//   http://www.boost.org/LICENSE_1_0.txt
//
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EGLPLUS_gl_colorspace

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_gl_colorspace_tests)

BOOST_AUTO_TEST_CASE(enum_gl_colorspace_values)
{
	using namespace eglplus;
	enum_values ev;
	(void)ev;
	gl_colorspace x;
	(void)x;

#ifdef EGL_GL_COLORSPACE_LINEAR
	x = ev.gl_colorspace_linear;
	BOOST_CHECK(x == ev.gl_colorspace_linear);
# ifdef EGL_GL_COLORSPACE_sRGB
	BOOST_CHECK(x != ev.gl_colorspace_srgb);
# endif
#endif

#ifdef EGL_GL_COLORSPACE_sRGB
	x = ev.gl_colorspace_srgb;
	BOOST_CHECK(x == ev.gl_colorspace_srgb);
#endif
}

BOOST_AUTO_TEST_CASE(enum_gl_colorspace_names)
{
	using namespace eglplus;
	enum_values ev;
	(void)ev;
	gl_colorspace x;
	(void)x;

#ifdef EGL_GL_COLORSPACE_LINEAR
	x = ev.gl_colorspace_linear;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"GL_COLORSPACE_LINEAR"
	) == 0);
#endif

#ifdef EGL_GL_COLORSPACE_sRGB
	x = ev.gl_colorspace_srgb;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"GL_COLORSPACE_sRGB"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_gl_colorspace_range)
{
	using namespace eglplus;
	auto count = enum_value_range<gl_colorspace>().size();

#ifdef EGL_GL_COLORSPACE_LINEAR
{
	--count;
	auto r = enum_value_range<gl_colorspace>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		gl_colorspace(EGL_GL_COLORSPACE_LINEAR)
	) != r.end());
}
#endif

#ifdef EGL_GL_COLORSPACE_sRGB
{
	--count;
	auto r = enum_value_range<gl_colorspace>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		gl_colorspace(EGL_GL_COLORSPACE_sRGB)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_gl_colorspace_any)
{
	using namespace eglplus;
	enum_values ev;
	(void)ev;
	gl_colorspace x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef EGL_GL_COLORSPACE_LINEAR
	x = ev.gl_colorspace_linear;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.gl_colorspace_linear);
#endif

#ifdef EGL_GL_COLORSPACE_sRGB
	x = ev.gl_colorspace_srgb;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.gl_colorspace_srgb);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
