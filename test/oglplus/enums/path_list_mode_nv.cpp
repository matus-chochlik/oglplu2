//  File test/oglplus/enums/path_list_mode_nv.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_path_list_mode_nv

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_path_list_mode_nv_tests)

BOOST_AUTO_TEST_CASE(enum_path_list_mode_nv_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	path_list_mode_nv x;
	(void)x;

#ifdef GL_ACCUM_ADJACENT_PAIRS_NV
	x = ev.accum_adjacent_pairs_nv;
	BOOST_CHECK(x == ev.accum_adjacent_pairs_nv);
# ifdef GL_ADJACENT_PAIRS_NV
	BOOST_CHECK(x != ev.adjacent_pairs_nv);
# endif
# ifdef GL_FIRST_TO_REST_NV
	BOOST_CHECK(x != ev.first_to_rest_nv);
# endif
#endif

#ifdef GL_ADJACENT_PAIRS_NV
	x = ev.adjacent_pairs_nv;
	BOOST_CHECK(x == ev.adjacent_pairs_nv);
# ifdef GL_FIRST_TO_REST_NV
	BOOST_CHECK(x != ev.first_to_rest_nv);
# endif
#endif

#ifdef GL_FIRST_TO_REST_NV
	x = ev.first_to_rest_nv;
	BOOST_CHECK(x == ev.first_to_rest_nv);
#endif
}

BOOST_AUTO_TEST_CASE(enum_path_list_mode_nv_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	path_list_mode_nv x;
	(void)x;

#ifdef GL_ACCUM_ADJACENT_PAIRS_NV
	x = ev.accum_adjacent_pairs_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ACCUM_ADJACENT_PAIRS_NV"
	) == 0);
#endif

#ifdef GL_ADJACENT_PAIRS_NV
	x = ev.adjacent_pairs_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ADJACENT_PAIRS_NV"
	) == 0);
#endif

#ifdef GL_FIRST_TO_REST_NV
	x = ev.first_to_rest_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"FIRST_TO_REST_NV"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_path_list_mode_nv_range)
{
	using namespace oglplus;
	auto count = enum_value_range<path_list_mode_nv>().size();

#ifdef GL_ACCUM_ADJACENT_PAIRS_NV
{
	--count;
	auto r = enum_value_range<path_list_mode_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_list_mode_nv(GL_ACCUM_ADJACENT_PAIRS_NV)
	) != r.end());
}
#endif

#ifdef GL_ADJACENT_PAIRS_NV
{
	--count;
	auto r = enum_value_range<path_list_mode_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_list_mode_nv(GL_ADJACENT_PAIRS_NV)
	) != r.end());
}
#endif

#ifdef GL_FIRST_TO_REST_NV
{
	--count;
	auto r = enum_value_range<path_list_mode_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_list_mode_nv(GL_FIRST_TO_REST_NV)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_path_list_mode_nv_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	path_list_mode_nv x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_ACCUM_ADJACENT_PAIRS_NV
	x = ev.accum_adjacent_pairs_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.accum_adjacent_pairs_nv);
#endif

#ifdef GL_ADJACENT_PAIRS_NV
	x = ev.adjacent_pairs_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.adjacent_pairs_nv);
#endif

#ifdef GL_FIRST_TO_REST_NV
	x = ev.first_to_rest_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.first_to_rest_nv);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
