//  File test/eglplus/enums/texture_target.cpp
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
#define BOOST_TEST_MODULE EGLPLUS_texture_target

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_texture_target_tests)

BOOST_AUTO_TEST_CASE(enum_texture_target_values)
{
	using namespace eglplus;
	enum_values ev;
	(void)ev;
	texture_target x;
	(void)x;

#ifdef EGL_NO_TEXTURE
	x = ev.no_texture;
	BOOST_CHECK(x == ev.no_texture);
# ifdef EGL_TEXTURE_2D
	BOOST_CHECK(x != ev.texture_2d);
# endif
#endif

#ifdef EGL_TEXTURE_2D
	x = ev.texture_2d;
	BOOST_CHECK(x == ev.texture_2d);
#endif
}

BOOST_AUTO_TEST_CASE(enum_texture_target_names)
{
	using namespace eglplus;
	enum_values ev;
	(void)ev;
	texture_target x;
	(void)x;

#ifdef EGL_NO_TEXTURE
	x = ev.no_texture;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"NO_TEXTURE"
	) == 0);
#endif

#ifdef EGL_TEXTURE_2D
	x = ev.texture_2d;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_2D"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_texture_target_range)
{
	using namespace eglplus;
	auto count = enum_value_range<texture_target>().size();

#ifdef EGL_NO_TEXTURE
{
	--count;
	auto r = enum_value_range<texture_target>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		texture_target(EGL_NO_TEXTURE)
	) != r.end());
}
#endif

#ifdef EGL_TEXTURE_2D
{
	--count;
	auto r = enum_value_range<texture_target>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		texture_target(EGL_TEXTURE_2D)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_texture_target_any)
{
	using namespace eglplus;
	enum_values ev;
	(void)ev;
	texture_target x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef EGL_NO_TEXTURE
	x = ev.no_texture;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.no_texture);
#endif

#ifdef EGL_TEXTURE_2D
	x = ev.texture_2d;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_2d);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
