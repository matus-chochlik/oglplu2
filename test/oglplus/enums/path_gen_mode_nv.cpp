//  File test/oglplus/enums/path_gen_mode_nv.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_path_gen_mode_nv

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_path_gen_mode_nv_tests)

BOOST_AUTO_TEST_CASE(enum_path_gen_mode_nv_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	path_gen_mode_nv x;
	(void)x;

#ifdef GL_EYE_LINEAR
	x = ev.eye_linear;
	BOOST_CHECK(x == ev.eye_linear);
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_OBJECT_LINEAR
	BOOST_CHECK(x != ev.object_linear);
# endif
# ifdef GL_PATH_OBJECT_BOUNDING_BOX_NV
	BOOST_CHECK(x != ev.path_object_bounding_box_nv);
# endif
#endif

#ifdef GL_NONE
	x = ev.none;
	BOOST_CHECK(x == ev.none);
# ifdef GL_OBJECT_LINEAR
	BOOST_CHECK(x != ev.object_linear);
# endif
# ifdef GL_PATH_OBJECT_BOUNDING_BOX_NV
	BOOST_CHECK(x != ev.path_object_bounding_box_nv);
# endif
#endif

#ifdef GL_OBJECT_LINEAR
	x = ev.object_linear;
	BOOST_CHECK(x == ev.object_linear);
# ifdef GL_PATH_OBJECT_BOUNDING_BOX_NV
	BOOST_CHECK(x != ev.path_object_bounding_box_nv);
# endif
#endif

#ifdef GL_PATH_OBJECT_BOUNDING_BOX_NV
	x = ev.path_object_bounding_box_nv;
	BOOST_CHECK(x == ev.path_object_bounding_box_nv);
#endif
}

BOOST_AUTO_TEST_CASE(enum_path_gen_mode_nv_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	path_gen_mode_nv x;
	(void)x;

#ifdef GL_EYE_LINEAR
	x = ev.eye_linear;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"EYE_LINEAR"
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

#ifdef GL_OBJECT_LINEAR
	x = ev.object_linear;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"OBJECT_LINEAR"
	) == 0);
#endif

#ifdef GL_PATH_OBJECT_BOUNDING_BOX_NV
	x = ev.path_object_bounding_box_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PATH_OBJECT_BOUNDING_BOX_NV"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_path_gen_mode_nv_range)
{
	using namespace oglplus;
	auto count = enum_value_range<path_gen_mode_nv>().size();

#ifdef GL_EYE_LINEAR
{
	--count;
	auto r = enum_value_range<path_gen_mode_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_gen_mode_nv(GL_EYE_LINEAR)
	) != r.end());
}
#endif

#ifdef GL_NONE
{
	--count;
	auto r = enum_value_range<path_gen_mode_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_gen_mode_nv(GL_NONE)
	) != r.end());
}
#endif

#ifdef GL_OBJECT_LINEAR
{
	--count;
	auto r = enum_value_range<path_gen_mode_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_gen_mode_nv(GL_OBJECT_LINEAR)
	) != r.end());
}
#endif

#ifdef GL_PATH_OBJECT_BOUNDING_BOX_NV
{
	--count;
	auto r = enum_value_range<path_gen_mode_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_gen_mode_nv(GL_PATH_OBJECT_BOUNDING_BOX_NV)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_path_gen_mode_nv_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	path_gen_mode_nv x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_EYE_LINEAR
	x = ev.eye_linear;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.eye_linear);
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

#ifdef GL_OBJECT_LINEAR
	x = ev.object_linear;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.object_linear);
#endif

#ifdef GL_PATH_OBJECT_BOUNDING_BOX_NV
	x = ev.path_object_bounding_box_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.path_object_bounding_box_nv);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
