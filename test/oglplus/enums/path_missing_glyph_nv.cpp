//  File test/oglplus/enums/path_missing_glyph_nv.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_path_missing_glyph_nv

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_path_missing_glyph_nv_tests)

BOOST_AUTO_TEST_CASE(enum_path_missing_glyph_nv_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	path_missing_glyph_nv x;
	(void)x;

#ifdef GL_SKIP_MISSING_GLYPH_NV
	x = ev.skip_missing_glyph_nv;
	BOOST_CHECK(x == ev.skip_missing_glyph_nv);
# ifdef GL_USE_MISSING_GLYPH_NV
	BOOST_CHECK(x != ev.use_missing_glyph_nv);
# endif
#endif

#ifdef GL_USE_MISSING_GLYPH_NV
	x = ev.use_missing_glyph_nv;
	BOOST_CHECK(x == ev.use_missing_glyph_nv);
#endif
}

BOOST_AUTO_TEST_CASE(enum_path_missing_glyph_nv_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	path_missing_glyph_nv x;
	(void)x;

#ifdef GL_SKIP_MISSING_GLYPH_NV
	x = ev.skip_missing_glyph_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SKIP_MISSING_GLYPH_NV"
	) == 0);
#endif

#ifdef GL_USE_MISSING_GLYPH_NV
	x = ev.use_missing_glyph_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"USE_MISSING_GLYPH_NV"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_path_missing_glyph_nv_range)
{
	using namespace oglplus;
	auto count = enum_value_range<path_missing_glyph_nv>().size();

#ifdef GL_SKIP_MISSING_GLYPH_NV
{
	--count;
	auto r = enum_value_range<path_missing_glyph_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_missing_glyph_nv(GL_SKIP_MISSING_GLYPH_NV)
	) != r.end());
}
#endif

#ifdef GL_USE_MISSING_GLYPH_NV
{
	--count;
	auto r = enum_value_range<path_missing_glyph_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_missing_glyph_nv(GL_USE_MISSING_GLYPH_NV)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_path_missing_glyph_nv_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	path_missing_glyph_nv x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_SKIP_MISSING_GLYPH_NV
	x = ev.skip_missing_glyph_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.skip_missing_glyph_nv);
#endif

#ifdef GL_USE_MISSING_GLYPH_NV
	x = ev.use_missing_glyph_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.use_missing_glyph_nv);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
