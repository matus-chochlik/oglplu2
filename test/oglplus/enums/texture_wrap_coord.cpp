//  File test/oglplus/enums/texture_wrap_coord.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_texture_wrap_coord

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_texture_wrap_coord_tests)

BOOST_AUTO_TEST_CASE(enum_texture_wrap_coord_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	texture_wrap_coord x;
	(void)x;

#ifdef GL_TEXTURE_WRAP_R
	x = ev.texture_wrap_r;
	BOOST_CHECK(x == ev.texture_wrap_r);
# ifdef GL_TEXTURE_WRAP_S
	BOOST_CHECK(x != ev.texture_wrap_s);
# endif
# ifdef GL_TEXTURE_WRAP_T
	BOOST_CHECK(x != ev.texture_wrap_t);
# endif
#endif

#ifdef GL_TEXTURE_WRAP_S
	x = ev.texture_wrap_s;
	BOOST_CHECK(x == ev.texture_wrap_s);
# ifdef GL_TEXTURE_WRAP_T
	BOOST_CHECK(x != ev.texture_wrap_t);
# endif
#endif

#ifdef GL_TEXTURE_WRAP_T
	x = ev.texture_wrap_t;
	BOOST_CHECK(x == ev.texture_wrap_t);
#endif
}

BOOST_AUTO_TEST_CASE(enum_texture_wrap_coord_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	texture_wrap_coord x;
	(void)x;

#ifdef GL_TEXTURE_WRAP_R
	x = ev.texture_wrap_r;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_WRAP_R"
	) == 0);
#endif

#ifdef GL_TEXTURE_WRAP_S
	x = ev.texture_wrap_s;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_WRAP_S"
	) == 0);
#endif

#ifdef GL_TEXTURE_WRAP_T
	x = ev.texture_wrap_t;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_WRAP_T"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_texture_wrap_coord_range)
{
	using namespace oglplus;
	auto count = enum_value_range<texture_wrap_coord>().size();

#ifdef GL_TEXTURE_WRAP_R
{
	--count;
	auto r = enum_value_range<texture_wrap_coord>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		texture_wrap_coord(GL_TEXTURE_WRAP_R)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_WRAP_S
{
	--count;
	auto r = enum_value_range<texture_wrap_coord>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		texture_wrap_coord(GL_TEXTURE_WRAP_S)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_WRAP_T
{
	--count;
	auto r = enum_value_range<texture_wrap_coord>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		texture_wrap_coord(GL_TEXTURE_WRAP_T)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_texture_wrap_coord_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	texture_wrap_coord x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_TEXTURE_WRAP_R
	x = ev.texture_wrap_r;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_wrap_r);
#endif

#ifdef GL_TEXTURE_WRAP_S
	x = ev.texture_wrap_s;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_wrap_s);
#endif

#ifdef GL_TEXTURE_WRAP_T
	x = ev.texture_wrap_t;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_wrap_t);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
