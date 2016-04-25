//  File test/eglplus/enums/context_flag.cpp
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
#define BOOST_TEST_MODULE EGLPLUS_context_flag

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_context_flag_tests)

BOOST_AUTO_TEST_CASE(enum_context_flag_values)
{
	using namespace eglplus;
	enum_values ev;
	(void)ev;
	context_flag x;
	(void)x;

#ifdef EGL_CONTEXT_OPENGL_DEBUG_BIT
	x = ev.context_opengl_debug_bit;
	BOOST_CHECK(x == ev.context_opengl_debug_bit);
# ifdef EGL_CONTEXT_OPENGL_FORWARD_COMPATIBLE_BIT
	BOOST_CHECK(x != ev.context_opengl_forward_compatible_bit);
# endif
# ifdef EGL_CONTEXT_OPENGL_ROBUST_ACCESS_BIT
	BOOST_CHECK(x != ev.context_opengl_robust_access_bit);
# endif
#endif

#ifdef EGL_CONTEXT_OPENGL_FORWARD_COMPATIBLE_BIT
	x = ev.context_opengl_forward_compatible_bit;
	BOOST_CHECK(x == ev.context_opengl_forward_compatible_bit);
# ifdef EGL_CONTEXT_OPENGL_ROBUST_ACCESS_BIT
	BOOST_CHECK(x != ev.context_opengl_robust_access_bit);
# endif
#endif

#ifdef EGL_CONTEXT_OPENGL_ROBUST_ACCESS_BIT
	x = ev.context_opengl_robust_access_bit;
	BOOST_CHECK(x == ev.context_opengl_robust_access_bit);
#endif
}

BOOST_AUTO_TEST_CASE(enum_context_flag_names)
{
	using namespace eglplus;
	enum_values ev;
	(void)ev;
	context_flag x;
	(void)x;

#ifdef EGL_CONTEXT_OPENGL_DEBUG_BIT
	x = ev.context_opengl_debug_bit;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"CONTEXT_OPENGL_DEBUG_BIT"
	) == 0);
#endif

#ifdef EGL_CONTEXT_OPENGL_FORWARD_COMPATIBLE_BIT
	x = ev.context_opengl_forward_compatible_bit;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"CONTEXT_OPENGL_FORWARD_COMPATIBLE_BIT"
	) == 0);
#endif

#ifdef EGL_CONTEXT_OPENGL_ROBUST_ACCESS_BIT
	x = ev.context_opengl_robust_access_bit;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"CONTEXT_OPENGL_ROBUST_ACCESS_BIT"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_context_flag_range)
{
	using namespace eglplus;
	auto count = enum_value_range<context_flag>().size();

#ifdef EGL_CONTEXT_OPENGL_DEBUG_BIT
{
	--count;
	auto r = enum_value_range<context_flag>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		context_flag(EGL_CONTEXT_OPENGL_DEBUG_BIT)
	) != r.end());
}
#endif

#ifdef EGL_CONTEXT_OPENGL_FORWARD_COMPATIBLE_BIT
{
	--count;
	auto r = enum_value_range<context_flag>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		context_flag(EGL_CONTEXT_OPENGL_FORWARD_COMPATIBLE_BIT)
	) != r.end());
}
#endif

#ifdef EGL_CONTEXT_OPENGL_ROBUST_ACCESS_BIT
{
	--count;
	auto r = enum_value_range<context_flag>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		context_flag(EGL_CONTEXT_OPENGL_ROBUST_ACCESS_BIT)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_context_flag_any)
{
	using namespace eglplus;
	enum_values ev;
	(void)ev;
	context_flag x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef EGL_CONTEXT_OPENGL_DEBUG_BIT
	x = ev.context_opengl_debug_bit;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.context_opengl_debug_bit);
#endif

#ifdef EGL_CONTEXT_OPENGL_FORWARD_COMPATIBLE_BIT
	x = ev.context_opengl_forward_compatible_bit;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.context_opengl_forward_compatible_bit);
#endif

#ifdef EGL_CONTEXT_OPENGL_ROBUST_ACCESS_BIT
	x = ev.context_opengl_robust_access_bit;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.context_opengl_robust_access_bit);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
