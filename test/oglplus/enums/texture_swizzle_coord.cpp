//  File test/oglplus/enums/texture_swizzle_coord.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_texture_swizzle_coord

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_texture_swizzle_coord_tests)

BOOST_AUTO_TEST_CASE(enum_texture_swizzle_coord_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	texture_swizzle_coord x;
	(void)x;

#ifdef GL_TEXTURE_SWIZZLE_A
	x = ev.texture_swizzle_a;
	BOOST_CHECK(x == ev.texture_swizzle_a);
# ifdef GL_TEXTURE_SWIZZLE_B
	BOOST_CHECK(x != ev.texture_swizzle_b);
# endif
# ifdef GL_TEXTURE_SWIZZLE_G
	BOOST_CHECK(x != ev.texture_swizzle_g);
# endif
# ifdef GL_TEXTURE_SWIZZLE_R
	BOOST_CHECK(x != ev.texture_swizzle_r);
# endif
# ifdef GL_TEXTURE_SWIZZLE_RGBA
	BOOST_CHECK(x != ev.texture_swizzle_rgba);
# endif
#endif

#ifdef GL_TEXTURE_SWIZZLE_B
	x = ev.texture_swizzle_b;
	BOOST_CHECK(x == ev.texture_swizzle_b);
# ifdef GL_TEXTURE_SWIZZLE_G
	BOOST_CHECK(x != ev.texture_swizzle_g);
# endif
# ifdef GL_TEXTURE_SWIZZLE_R
	BOOST_CHECK(x != ev.texture_swizzle_r);
# endif
# ifdef GL_TEXTURE_SWIZZLE_RGBA
	BOOST_CHECK(x != ev.texture_swizzle_rgba);
# endif
#endif

#ifdef GL_TEXTURE_SWIZZLE_G
	x = ev.texture_swizzle_g;
	BOOST_CHECK(x == ev.texture_swizzle_g);
# ifdef GL_TEXTURE_SWIZZLE_R
	BOOST_CHECK(x != ev.texture_swizzle_r);
# endif
# ifdef GL_TEXTURE_SWIZZLE_RGBA
	BOOST_CHECK(x != ev.texture_swizzle_rgba);
# endif
#endif

#ifdef GL_TEXTURE_SWIZZLE_R
	x = ev.texture_swizzle_r;
	BOOST_CHECK(x == ev.texture_swizzle_r);
# ifdef GL_TEXTURE_SWIZZLE_RGBA
	BOOST_CHECK(x != ev.texture_swizzle_rgba);
# endif
#endif

#ifdef GL_TEXTURE_SWIZZLE_RGBA
	x = ev.texture_swizzle_rgba;
	BOOST_CHECK(x == ev.texture_swizzle_rgba);
#endif
}

BOOST_AUTO_TEST_CASE(enum_texture_swizzle_coord_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	texture_swizzle_coord x;
	(void)x;

#ifdef GL_TEXTURE_SWIZZLE_A
	x = ev.texture_swizzle_a;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_SWIZZLE_A"
	) == 0);
#endif

#ifdef GL_TEXTURE_SWIZZLE_B
	x = ev.texture_swizzle_b;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_SWIZZLE_B"
	) == 0);
#endif

#ifdef GL_TEXTURE_SWIZZLE_G
	x = ev.texture_swizzle_g;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_SWIZZLE_G"
	) == 0);
#endif

#ifdef GL_TEXTURE_SWIZZLE_R
	x = ev.texture_swizzle_r;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_SWIZZLE_R"
	) == 0);
#endif

#ifdef GL_TEXTURE_SWIZZLE_RGBA
	x = ev.texture_swizzle_rgba;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_SWIZZLE_RGBA"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_texture_swizzle_coord_range)
{
	using namespace oglplus;
	auto count = enum_value_range<texture_swizzle_coord>().size();

#ifdef GL_TEXTURE_SWIZZLE_A
{
	--count;
	auto r = enum_value_range<texture_swizzle_coord>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		texture_swizzle_coord(GL_TEXTURE_SWIZZLE_A)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_SWIZZLE_B
{
	--count;
	auto r = enum_value_range<texture_swizzle_coord>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		texture_swizzle_coord(GL_TEXTURE_SWIZZLE_B)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_SWIZZLE_G
{
	--count;
	auto r = enum_value_range<texture_swizzle_coord>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		texture_swizzle_coord(GL_TEXTURE_SWIZZLE_G)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_SWIZZLE_R
{
	--count;
	auto r = enum_value_range<texture_swizzle_coord>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		texture_swizzle_coord(GL_TEXTURE_SWIZZLE_R)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_SWIZZLE_RGBA
{
	--count;
	auto r = enum_value_range<texture_swizzle_coord>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		texture_swizzle_coord(GL_TEXTURE_SWIZZLE_RGBA)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_texture_swizzle_coord_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	texture_swizzle_coord x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_TEXTURE_SWIZZLE_A
	x = ev.texture_swizzle_a;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_swizzle_a);
#endif

#ifdef GL_TEXTURE_SWIZZLE_B
	x = ev.texture_swizzle_b;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_swizzle_b);
#endif

#ifdef GL_TEXTURE_SWIZZLE_G
	x = ev.texture_swizzle_g;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_swizzle_g);
#endif

#ifdef GL_TEXTURE_SWIZZLE_R
	x = ev.texture_swizzle_r;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_swizzle_r);
#endif

#ifdef GL_TEXTURE_SWIZZLE_RGBA
	x = ev.texture_swizzle_rgba;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_swizzle_rgba);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
