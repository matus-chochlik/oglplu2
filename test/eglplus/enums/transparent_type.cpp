//  File test/eglplus/enums/transparent_type.cpp
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
#define BOOST_TEST_MODULE EGLPLUS_transparent_type

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_transparent_type_tests)

BOOST_AUTO_TEST_CASE(enum_transparent_type_values)
{
	using namespace eglplus;
	enum_values ev;
	(void)ev;
	transparent_type x;
	(void)x;

#ifdef EGL_NONE
	x = ev.none;
	BOOST_CHECK(x == ev.none);
# ifdef EGL_TRANSPARENT_RGB
	BOOST_CHECK(x != ev.transparent_rgb);
# endif
#endif

#ifdef EGL_TRANSPARENT_RGB
	x = ev.transparent_rgb;
	BOOST_CHECK(x == ev.transparent_rgb);
#endif
}

BOOST_AUTO_TEST_CASE(enum_transparent_type_names)
{
	using namespace eglplus;
	enum_values ev;
	(void)ev;
	transparent_type x;
	(void)x;

#ifdef EGL_NONE
	x = ev.none;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"NONE"
	) == 0);
#endif

#ifdef EGL_TRANSPARENT_RGB
	x = ev.transparent_rgb;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TRANSPARENT_RGB"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_transparent_type_range)
{
	using namespace eglplus;
	auto count = enum_value_range<transparent_type>().size();

#ifdef EGL_NONE
{
	--count;
	auto r = enum_value_range<transparent_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		transparent_type(EGL_NONE)
	) != r.end());
}
#endif

#ifdef EGL_TRANSPARENT_RGB
{
	--count;
	auto r = enum_value_range<transparent_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		transparent_type(EGL_TRANSPARENT_RGB)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_transparent_type_any)
{
	using namespace eglplus;
	enum_values ev;
	(void)ev;
	transparent_type x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef EGL_NONE
	x = ev.none;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.none);
#endif

#ifdef EGL_TRANSPARENT_RGB
	x = ev.transparent_rgb;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.transparent_rgb);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
