//  File test/eglplus/enums/render_buffer.cpp
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
#define BOOST_TEST_MODULE EGLPLUS_render_buffer

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_render_buffer_tests)

BOOST_AUTO_TEST_CASE(enum_render_buffer_values)
{
	using namespace eglplus;
	enum_values ev;
	(void)ev;
	render_buffer x;
	(void)x;

#ifdef EGL_BACK_BUFFER
	x = ev.back_buffer;
	BOOST_CHECK(x == ev.back_buffer);
# ifdef EGL_SINGLE_BUFFER
	BOOST_CHECK(x != ev.single_buffer);
# endif
#endif

#ifdef EGL_SINGLE_BUFFER
	x = ev.single_buffer;
	BOOST_CHECK(x == ev.single_buffer);
#endif
}

BOOST_AUTO_TEST_CASE(enum_render_buffer_names)
{
	using namespace eglplus;
	enum_values ev;
	(void)ev;
	render_buffer x;
	(void)x;

#ifdef EGL_BACK_BUFFER
	x = ev.back_buffer;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"BACK_BUFFER"
	) == 0);
#endif

#ifdef EGL_SINGLE_BUFFER
	x = ev.single_buffer;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SINGLE_BUFFER"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_render_buffer_range)
{
	using namespace eglplus;
	auto count = enum_value_range<render_buffer>().size();

#ifdef EGL_BACK_BUFFER
{
	--count;
	auto r = enum_value_range<render_buffer>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		render_buffer(EGL_BACK_BUFFER)
	) != r.end());
}
#endif

#ifdef EGL_SINGLE_BUFFER
{
	--count;
	auto r = enum_value_range<render_buffer>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		render_buffer(EGL_SINGLE_BUFFER)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_render_buffer_any)
{
	using namespace eglplus;
	enum_values ev;
	(void)ev;
	render_buffer x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef EGL_BACK_BUFFER
	x = ev.back_buffer;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.back_buffer);
#endif

#ifdef EGL_SINGLE_BUFFER
	x = ev.single_buffer;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.single_buffer);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
