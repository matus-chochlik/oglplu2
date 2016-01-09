//  File test/eglplus/enums/color_buffer_type.cpp
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
#define BOOST_TEST_MODULE EGLPLUS_color_buffer_type

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_color_buffer_type_tests)

BOOST_AUTO_TEST_CASE(enum_color_buffer_type_values)
{
	using namespace eglplus;
	enum_values ev;
	(void)ev;
	color_buffer_type x;
	(void)x;

#ifdef EGL_LUMINANCE_BUFFER
	x = ev.luminance_buffer;
	BOOST_CHECK(x == ev.luminance_buffer);
# ifdef EGL_RGB_BUFFER
	BOOST_CHECK(x != ev.rgb_buffer);
# endif
#endif

#ifdef EGL_RGB_BUFFER
	x = ev.rgb_buffer;
	BOOST_CHECK(x == ev.rgb_buffer);
#endif
}

BOOST_AUTO_TEST_CASE(enum_color_buffer_type_names)
{
	using namespace eglplus;
	enum_values ev;
	(void)ev;
	color_buffer_type x;
	(void)x;

#ifdef EGL_LUMINANCE_BUFFER
	x = ev.luminance_buffer;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"LUMINANCE_BUFFER"
	) == 0);
#endif

#ifdef EGL_RGB_BUFFER
	x = ev.rgb_buffer;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RGB_BUFFER"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_color_buffer_type_range)
{
	using namespace eglplus;
	auto count = enum_value_range<color_buffer_type>().size();

#ifdef EGL_LUMINANCE_BUFFER
{
	--count;
	auto r = enum_value_range<color_buffer_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		color_buffer_type(EGL_LUMINANCE_BUFFER)
	) != r.end());
}
#endif

#ifdef EGL_RGB_BUFFER
{
	--count;
	auto r = enum_value_range<color_buffer_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		color_buffer_type(EGL_RGB_BUFFER)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_color_buffer_type_any)
{
	using namespace eglplus;
	enum_values ev;
	(void)ev;
	color_buffer_type x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef EGL_LUMINANCE_BUFFER
	x = ev.luminance_buffer;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.luminance_buffer);
#endif

#ifdef EGL_RGB_BUFFER
	x = ev.rgb_buffer;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.rgb_buffer);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
