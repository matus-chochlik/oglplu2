//  File test/oglplus/enums/old_matrix_mode.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_old_matrix_mode

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_old_matrix_mode_tests)

BOOST_AUTO_TEST_CASE(enum_old_matrix_mode_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	old_matrix_mode x;
	(void)x;

#ifdef GL_COLOR
	x = ev.color;
	BOOST_CHECK(x == ev.color);
# ifdef GL_MODELVIEW
	BOOST_CHECK(x != ev.modelview);
# endif
# ifdef GL_PROJECTION
	BOOST_CHECK(x != ev.projection);
# endif
# ifdef GL_TEXTURE
	BOOST_CHECK(x != ev.texture);
# endif
#endif

#ifdef GL_MODELVIEW
	x = ev.modelview;
	BOOST_CHECK(x == ev.modelview);
# ifdef GL_PROJECTION
	BOOST_CHECK(x != ev.projection);
# endif
# ifdef GL_TEXTURE
	BOOST_CHECK(x != ev.texture);
# endif
#endif

#ifdef GL_PROJECTION
	x = ev.projection;
	BOOST_CHECK(x == ev.projection);
# ifdef GL_TEXTURE
	BOOST_CHECK(x != ev.texture);
# endif
#endif

#ifdef GL_TEXTURE
	x = ev.texture;
	BOOST_CHECK(x == ev.texture);
#endif
}

BOOST_AUTO_TEST_CASE(enum_old_matrix_mode_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	old_matrix_mode x;
	(void)x;

#ifdef GL_COLOR
	x = ev.color;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"COLOR"
	) == 0);
#endif

#ifdef GL_MODELVIEW
	x = ev.modelview;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MODELVIEW"
	) == 0);
#endif

#ifdef GL_PROJECTION
	x = ev.projection;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PROJECTION"
	) == 0);
#endif

#ifdef GL_TEXTURE
	x = ev.texture;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_old_matrix_mode_range)
{
	using namespace oglplus;
	auto count = enum_value_range<old_matrix_mode>().size();

#ifdef GL_COLOR
{
	--count;
	auto r = enum_value_range<old_matrix_mode>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		old_matrix_mode(GL_COLOR)
	) != r.end());
}
#endif

#ifdef GL_MODELVIEW
{
	--count;
	auto r = enum_value_range<old_matrix_mode>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		old_matrix_mode(GL_MODELVIEW)
	) != r.end());
}
#endif

#ifdef GL_PROJECTION
{
	--count;
	auto r = enum_value_range<old_matrix_mode>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		old_matrix_mode(GL_PROJECTION)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE
{
	--count;
	auto r = enum_value_range<old_matrix_mode>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		old_matrix_mode(GL_TEXTURE)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_old_matrix_mode_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	old_matrix_mode x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_COLOR
	x = ev.color;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.color);
#endif

#ifdef GL_MODELVIEW
	x = ev.modelview;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.modelview);
#endif

#ifdef GL_PROJECTION
	x = ev.projection;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.projection);
#endif

#ifdef GL_TEXTURE
	x = ev.texture;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
