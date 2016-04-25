//  File test/oglplus/enums/path_join_style_nv.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_path_join_style_nv

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_path_join_style_nv_tests)

BOOST_AUTO_TEST_CASE(enum_path_join_style_nv_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	path_join_style_nv x;
	(void)x;

#ifdef GL_BEVEL_NV
	x = ev.bevel_nv;
	BOOST_CHECK(x == ev.bevel_nv);
# ifdef GL_MITER_REVERT_NV
	BOOST_CHECK(x != ev.miter_revert_nv);
# endif
# ifdef GL_MITER_TRUNCATE_NV
	BOOST_CHECK(x != ev.miter_truncate_nv);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_ROUND_NV
	BOOST_CHECK(x != ev.round_nv);
# endif
#endif

#ifdef GL_MITER_REVERT_NV
	x = ev.miter_revert_nv;
	BOOST_CHECK(x == ev.miter_revert_nv);
# ifdef GL_MITER_TRUNCATE_NV
	BOOST_CHECK(x != ev.miter_truncate_nv);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_ROUND_NV
	BOOST_CHECK(x != ev.round_nv);
# endif
#endif

#ifdef GL_MITER_TRUNCATE_NV
	x = ev.miter_truncate_nv;
	BOOST_CHECK(x == ev.miter_truncate_nv);
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_ROUND_NV
	BOOST_CHECK(x != ev.round_nv);
# endif
#endif

#ifdef GL_NONE
	x = ev.none;
	BOOST_CHECK(x == ev.none);
# ifdef GL_ROUND_NV
	BOOST_CHECK(x != ev.round_nv);
# endif
#endif

#ifdef GL_ROUND_NV
	x = ev.round_nv;
	BOOST_CHECK(x == ev.round_nv);
#endif
}

BOOST_AUTO_TEST_CASE(enum_path_join_style_nv_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	path_join_style_nv x;
	(void)x;

#ifdef GL_BEVEL_NV
	x = ev.bevel_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"BEVEL_NV"
	) == 0);
#endif

#ifdef GL_MITER_REVERT_NV
	x = ev.miter_revert_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MITER_REVERT_NV"
	) == 0);
#endif

#ifdef GL_MITER_TRUNCATE_NV
	x = ev.miter_truncate_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MITER_TRUNCATE_NV"
	) == 0);
#endif

#ifdef GL_NONE
	x = ev.none;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"NONE"
	) == 0);
#endif

#ifdef GL_ROUND_NV
	x = ev.round_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ROUND_NV"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_path_join_style_nv_range)
{
	using namespace oglplus;
	auto count = enum_value_range<path_join_style_nv>().size();

#ifdef GL_BEVEL_NV
{
	--count;
	auto r = enum_value_range<path_join_style_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_join_style_nv(GL_BEVEL_NV)
	) != r.end());
}
#endif

#ifdef GL_MITER_REVERT_NV
{
	--count;
	auto r = enum_value_range<path_join_style_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_join_style_nv(GL_MITER_REVERT_NV)
	) != r.end());
}
#endif

#ifdef GL_MITER_TRUNCATE_NV
{
	--count;
	auto r = enum_value_range<path_join_style_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_join_style_nv(GL_MITER_TRUNCATE_NV)
	) != r.end());
}
#endif

#ifdef GL_NONE
{
	--count;
	auto r = enum_value_range<path_join_style_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_join_style_nv(GL_NONE)
	) != r.end());
}
#endif

#ifdef GL_ROUND_NV
{
	--count;
	auto r = enum_value_range<path_join_style_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_join_style_nv(GL_ROUND_NV)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_path_join_style_nv_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	path_join_style_nv x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_BEVEL_NV
	x = ev.bevel_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.bevel_nv);
#endif

#ifdef GL_MITER_REVERT_NV
	x = ev.miter_revert_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.miter_revert_nv);
#endif

#ifdef GL_MITER_TRUNCATE_NV
	x = ev.miter_truncate_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.miter_truncate_nv);
#endif

#ifdef GL_NONE
	x = ev.none;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.none);
#endif

#ifdef GL_ROUND_NV
	x = ev.round_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.round_nv);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
