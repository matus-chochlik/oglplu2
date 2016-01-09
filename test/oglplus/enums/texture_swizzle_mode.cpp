//  File test/oglplus/enums/texture_swizzle_mode.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_texture_swizzle_mode

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_texture_swizzle_mode_tests)

BOOST_AUTO_TEST_CASE(enum_texture_swizzle_mode_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	texture_swizzle_mode x;
	(void)x;

#ifdef GL_ALPHA
	x = ev.alpha;
	BOOST_CHECK(x == ev.alpha);
# ifdef GL_BLUE
	BOOST_CHECK(x != ev.blue);
# endif
# ifdef GL_GREEN
	BOOST_CHECK(x != ev.green);
# endif
# ifdef GL_ONE
	BOOST_CHECK(x != ev.one);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_ZERO
	BOOST_CHECK(x != ev.zero);
# endif
#endif

#ifdef GL_BLUE
	x = ev.blue;
	BOOST_CHECK(x == ev.blue);
# ifdef GL_GREEN
	BOOST_CHECK(x != ev.green);
# endif
# ifdef GL_ONE
	BOOST_CHECK(x != ev.one);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_ZERO
	BOOST_CHECK(x != ev.zero);
# endif
#endif

#ifdef GL_GREEN
	x = ev.green;
	BOOST_CHECK(x == ev.green);
# ifdef GL_ONE
	BOOST_CHECK(x != ev.one);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_ZERO
	BOOST_CHECK(x != ev.zero);
# endif
#endif

#ifdef GL_ONE
	x = ev.one;
	BOOST_CHECK(x == ev.one);
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_ZERO
	BOOST_CHECK(x != ev.zero);
# endif
#endif

#ifdef GL_RED
	x = ev.red;
	BOOST_CHECK(x == ev.red);
# ifdef GL_ZERO
	BOOST_CHECK(x != ev.zero);
# endif
#endif

#ifdef GL_ZERO
	x = ev.zero;
	BOOST_CHECK(x == ev.zero);
#endif
}

BOOST_AUTO_TEST_CASE(enum_texture_swizzle_mode_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	texture_swizzle_mode x;
	(void)x;

#ifdef GL_ALPHA
	x = ev.alpha;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ALPHA"
	) == 0);
#endif

#ifdef GL_BLUE
	x = ev.blue;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"BLUE"
	) == 0);
#endif

#ifdef GL_GREEN
	x = ev.green;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"GREEN"
	) == 0);
#endif

#ifdef GL_ONE
	x = ev.one;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ONE"
	) == 0);
#endif

#ifdef GL_RED
	x = ev.red;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RED"
	) == 0);
#endif

#ifdef GL_ZERO
	x = ev.zero;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ZERO"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_texture_swizzle_mode_range)
{
	using namespace oglplus;
	auto count = enum_value_range<texture_swizzle_mode>().size();

#ifdef GL_ALPHA
{
	--count;
	auto r = enum_value_range<texture_swizzle_mode>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		texture_swizzle_mode(GL_ALPHA)
	) != r.end());
}
#endif

#ifdef GL_BLUE
{
	--count;
	auto r = enum_value_range<texture_swizzle_mode>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		texture_swizzle_mode(GL_BLUE)
	) != r.end());
}
#endif

#ifdef GL_GREEN
{
	--count;
	auto r = enum_value_range<texture_swizzle_mode>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		texture_swizzle_mode(GL_GREEN)
	) != r.end());
}
#endif

#ifdef GL_ONE
{
	--count;
	auto r = enum_value_range<texture_swizzle_mode>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		texture_swizzle_mode(GL_ONE)
	) != r.end());
}
#endif

#ifdef GL_RED
{
	--count;
	auto r = enum_value_range<texture_swizzle_mode>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		texture_swizzle_mode(GL_RED)
	) != r.end());
}
#endif

#ifdef GL_ZERO
{
	--count;
	auto r = enum_value_range<texture_swizzle_mode>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		texture_swizzle_mode(GL_ZERO)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_texture_swizzle_mode_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	texture_swizzle_mode x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_ALPHA
	x = ev.alpha;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.alpha);
#endif

#ifdef GL_BLUE
	x = ev.blue;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.blue);
#endif

#ifdef GL_GREEN
	x = ev.green;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.green);
#endif

#ifdef GL_ONE
	x = ev.one;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.one);
#endif

#ifdef GL_RED
	x = ev.red;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.red);
#endif

#ifdef GL_ZERO
	x = ev.zero;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.zero);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
