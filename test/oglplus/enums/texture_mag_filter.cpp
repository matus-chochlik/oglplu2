//  File test/oglplus/enums/texture_mag_filter.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_texture_mag_filter

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_texture_mag_filter_tests)

BOOST_AUTO_TEST_CASE(enum_texture_mag_filter_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	texture_mag_filter x;
	(void)x;

#ifdef GL_LINEAR
	x = ev.linear;
	BOOST_CHECK(x == ev.linear);
# ifdef GL_NEAREST
	BOOST_CHECK(x != ev.nearest);
# endif
#endif

#ifdef GL_NEAREST
	x = ev.nearest;
	BOOST_CHECK(x == ev.nearest);
#endif
}

BOOST_AUTO_TEST_CASE(enum_texture_mag_filter_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	texture_mag_filter x;
	(void)x;

#ifdef GL_LINEAR
	x = ev.linear;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"LINEAR"
	) == 0);
#endif

#ifdef GL_NEAREST
	x = ev.nearest;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"NEAREST"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_texture_mag_filter_range)
{
	using namespace oglplus;
	auto count = enum_value_range<texture_mag_filter>().size();

#ifdef GL_LINEAR
{
	--count;
	auto r = enum_value_range<texture_mag_filter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		texture_mag_filter(GL_LINEAR)
	) != r.end());
}
#endif

#ifdef GL_NEAREST
{
	--count;
	auto r = enum_value_range<texture_mag_filter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		texture_mag_filter(GL_NEAREST)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_texture_mag_filter_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	texture_mag_filter x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_LINEAR
	x = ev.linear;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.linear);
#endif

#ifdef GL_NEAREST
	x = ev.nearest;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.nearest);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
