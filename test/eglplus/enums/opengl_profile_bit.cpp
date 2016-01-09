//  File test/eglplus/enums/opengl_profile_bit.cpp
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
#define BOOST_TEST_MODULE EGLPLUS_opengl_profile_bit

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_opengl_profile_bit_tests)

BOOST_AUTO_TEST_CASE(enum_opengl_profile_bit_values)
{
	using namespace eglplus;
	enum_values ev;
	(void)ev;
	opengl_profile_bit x;
	(void)x;

#ifdef EGL_CONTEXT_OPENGL_COMPATIBILITY_PROFILE_BIT
	x = ev.context_opengl_compatibility_profile_bit;
	BOOST_CHECK(x == ev.context_opengl_compatibility_profile_bit);
# ifdef EGL_CONTEXT_OPENGL_CORE_PROFILE_BIT
	BOOST_CHECK(x != ev.context_opengl_core_profile_bit);
# endif
#endif

#ifdef EGL_CONTEXT_OPENGL_CORE_PROFILE_BIT
	x = ev.context_opengl_core_profile_bit;
	BOOST_CHECK(x == ev.context_opengl_core_profile_bit);
#endif
}

BOOST_AUTO_TEST_CASE(enum_opengl_profile_bit_names)
{
	using namespace eglplus;
	enum_values ev;
	(void)ev;
	opengl_profile_bit x;
	(void)x;

#ifdef EGL_CONTEXT_OPENGL_COMPATIBILITY_PROFILE_BIT
	x = ev.context_opengl_compatibility_profile_bit;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"CONTEXT_OPENGL_COMPATIBILITY_PROFILE_BIT"
	) == 0);
#endif

#ifdef EGL_CONTEXT_OPENGL_CORE_PROFILE_BIT
	x = ev.context_opengl_core_profile_bit;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"CONTEXT_OPENGL_CORE_PROFILE_BIT"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_opengl_profile_bit_range)
{
	using namespace eglplus;
	auto count = enum_value_range<opengl_profile_bit>().size();

#ifdef EGL_CONTEXT_OPENGL_COMPATIBILITY_PROFILE_BIT
{
	--count;
	auto r = enum_value_range<opengl_profile_bit>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		opengl_profile_bit(EGL_CONTEXT_OPENGL_COMPATIBILITY_PROFILE_BIT)
	) != r.end());
}
#endif

#ifdef EGL_CONTEXT_OPENGL_CORE_PROFILE_BIT
{
	--count;
	auto r = enum_value_range<opengl_profile_bit>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		opengl_profile_bit(EGL_CONTEXT_OPENGL_CORE_PROFILE_BIT)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_opengl_profile_bit_any)
{
	using namespace eglplus;
	enum_values ev;
	(void)ev;
	opengl_profile_bit x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef EGL_CONTEXT_OPENGL_COMPATIBILITY_PROFILE_BIT
	x = ev.context_opengl_compatibility_profile_bit;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.context_opengl_compatibility_profile_bit);
#endif

#ifdef EGL_CONTEXT_OPENGL_CORE_PROFILE_BIT
	x = ev.context_opengl_core_profile_bit;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.context_opengl_core_profile_bit);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
