//  File test/oglplus/enums/path_fill_mode_nv.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_path_fill_mode_nv

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_path_fill_mode_nv_tests)

BOOST_AUTO_TEST_CASE(enum_path_fill_mode_nv_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	path_fill_mode_nv x;
	(void)x;

#ifdef GL_COUNT_DOWN_NV
	x = ev.count_down_nv;
	BOOST_CHECK(x == ev.count_down_nv);
# ifdef GL_COUNT_UP_NV
	BOOST_CHECK(x != ev.count_up_nv);
# endif
# ifdef GL_INVERT
	BOOST_CHECK(x != ev.invert);
# endif
# ifdef GL_PATH_FILL_MODE_NV
	BOOST_CHECK(x != ev.path_fill_mode_nv);
# endif
#endif

#ifdef GL_COUNT_UP_NV
	x = ev.count_up_nv;
	BOOST_CHECK(x == ev.count_up_nv);
# ifdef GL_INVERT
	BOOST_CHECK(x != ev.invert);
# endif
# ifdef GL_PATH_FILL_MODE_NV
	BOOST_CHECK(x != ev.path_fill_mode_nv);
# endif
#endif

#ifdef GL_INVERT
	x = ev.invert;
	BOOST_CHECK(x == ev.invert);
# ifdef GL_PATH_FILL_MODE_NV
	BOOST_CHECK(x != ev.path_fill_mode_nv);
# endif
#endif

#ifdef GL_PATH_FILL_MODE_NV
	x = ev.path_fill_mode_nv;
	BOOST_CHECK(x == ev.path_fill_mode_nv);
#endif
}

BOOST_AUTO_TEST_CASE(enum_path_fill_mode_nv_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	path_fill_mode_nv x;
	(void)x;

#ifdef GL_COUNT_DOWN_NV
	x = ev.count_down_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"COUNT_DOWN_NV"
	) == 0);
#endif

#ifdef GL_COUNT_UP_NV
	x = ev.count_up_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"COUNT_UP_NV"
	) == 0);
#endif

#ifdef GL_INVERT
	x = ev.invert;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"INVERT"
	) == 0);
#endif

#ifdef GL_PATH_FILL_MODE_NV
	x = ev.path_fill_mode_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PATH_FILL_MODE_NV"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_path_fill_mode_nv_range)
{
	using namespace oglplus;
	auto count = enum_value_range<path_fill_mode_nv>().size();

#ifdef GL_COUNT_DOWN_NV
{
	--count;
	auto r = enum_value_range<path_fill_mode_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_fill_mode_nv(GL_COUNT_DOWN_NV)
	) != r.end());
}
#endif

#ifdef GL_COUNT_UP_NV
{
	--count;
	auto r = enum_value_range<path_fill_mode_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_fill_mode_nv(GL_COUNT_UP_NV)
	) != r.end());
}
#endif

#ifdef GL_INVERT
{
	--count;
	auto r = enum_value_range<path_fill_mode_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_fill_mode_nv(GL_INVERT)
	) != r.end());
}
#endif

#ifdef GL_PATH_FILL_MODE_NV
{
	--count;
	auto r = enum_value_range<path_fill_mode_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_fill_mode_nv(GL_PATH_FILL_MODE_NV)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_path_fill_mode_nv_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	path_fill_mode_nv x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_COUNT_DOWN_NV
	x = ev.count_down_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.count_down_nv);
#endif

#ifdef GL_COUNT_UP_NV
	x = ev.count_up_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.count_up_nv);
#endif

#ifdef GL_INVERT
	x = ev.invert;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.invert);
#endif

#ifdef GL_PATH_FILL_MODE_NV
	x = ev.path_fill_mode_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.path_fill_mode_nv);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
