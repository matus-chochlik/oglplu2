//  File test/oglplus/enums/point_parameter.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_point_parameter

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_point_parameter_tests)

BOOST_AUTO_TEST_CASE(enum_point_parameter_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	point_parameter x;
	(void)x;

#ifdef GL_POINT_FADE_THRESHOLD_SIZE
	x = ev.point_fade_threshold_size;
	BOOST_CHECK(x == ev.point_fade_threshold_size);
# ifdef GL_POINT_SIZE_MAX
	BOOST_CHECK(x != ev.point_size_max);
# endif
# ifdef GL_POINT_SIZE_MIN
	BOOST_CHECK(x != ev.point_size_min);
# endif
# ifdef GL_POINT_SPRITE_COORD_ORIGIN
	BOOST_CHECK(x != ev.point_sprite_coord_origin);
# endif
#endif

#ifdef GL_POINT_SIZE_MAX
	x = ev.point_size_max;
	BOOST_CHECK(x == ev.point_size_max);
# ifdef GL_POINT_SIZE_MIN
	BOOST_CHECK(x != ev.point_size_min);
# endif
# ifdef GL_POINT_SPRITE_COORD_ORIGIN
	BOOST_CHECK(x != ev.point_sprite_coord_origin);
# endif
#endif

#ifdef GL_POINT_SIZE_MIN
	x = ev.point_size_min;
	BOOST_CHECK(x == ev.point_size_min);
# ifdef GL_POINT_SPRITE_COORD_ORIGIN
	BOOST_CHECK(x != ev.point_sprite_coord_origin);
# endif
#endif

#ifdef GL_POINT_SPRITE_COORD_ORIGIN
	x = ev.point_sprite_coord_origin;
	BOOST_CHECK(x == ev.point_sprite_coord_origin);
#endif
}

BOOST_AUTO_TEST_CASE(enum_point_parameter_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	point_parameter x;
	(void)x;

#ifdef GL_POINT_FADE_THRESHOLD_SIZE
	x = ev.point_fade_threshold_size;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"POINT_FADE_THRESHOLD_SIZE"
	) == 0);
#endif

#ifdef GL_POINT_SIZE_MAX
	x = ev.point_size_max;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"POINT_SIZE_MAX"
	) == 0);
#endif

#ifdef GL_POINT_SIZE_MIN
	x = ev.point_size_min;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"POINT_SIZE_MIN"
	) == 0);
#endif

#ifdef GL_POINT_SPRITE_COORD_ORIGIN
	x = ev.point_sprite_coord_origin;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"POINT_SPRITE_COORD_ORIGIN"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_point_parameter_range)
{
	using namespace oglplus;
	auto count = enum_value_range<point_parameter>().size();

#ifdef GL_POINT_FADE_THRESHOLD_SIZE
{
	--count;
	auto r = enum_value_range<point_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		point_parameter(GL_POINT_FADE_THRESHOLD_SIZE)
	) != r.end());
}
#endif

#ifdef GL_POINT_SIZE_MAX
{
	--count;
	auto r = enum_value_range<point_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		point_parameter(GL_POINT_SIZE_MAX)
	) != r.end());
}
#endif

#ifdef GL_POINT_SIZE_MIN
{
	--count;
	auto r = enum_value_range<point_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		point_parameter(GL_POINT_SIZE_MIN)
	) != r.end());
}
#endif

#ifdef GL_POINT_SPRITE_COORD_ORIGIN
{
	--count;
	auto r = enum_value_range<point_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		point_parameter(GL_POINT_SPRITE_COORD_ORIGIN)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_point_parameter_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	point_parameter x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_POINT_FADE_THRESHOLD_SIZE
	x = ev.point_fade_threshold_size;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.point_fade_threshold_size);
#endif

#ifdef GL_POINT_SIZE_MAX
	x = ev.point_size_max;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.point_size_max);
#endif

#ifdef GL_POINT_SIZE_MIN
	x = ev.point_size_min;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.point_size_min);
#endif

#ifdef GL_POINT_SPRITE_COORD_ORIGIN
	x = ev.point_sprite_coord_origin;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.point_sprite_coord_origin);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
