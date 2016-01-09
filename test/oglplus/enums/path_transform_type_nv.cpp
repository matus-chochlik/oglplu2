//  File test/oglplus/enums/path_transform_type_nv.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_path_transform_type_nv

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_path_transform_type_nv_tests)

BOOST_AUTO_TEST_CASE(enum_path_transform_type_nv_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	path_transform_type_nv x;
	(void)x;

#ifdef GL_AFFINE_2D_NV
	x = ev.affine_2d_nv;
	BOOST_CHECK(x == ev.affine_2d_nv);
# ifdef GL_AFFINE_3D_NV
	BOOST_CHECK(x != ev.affine_3d_nv);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_TRANSLATE_2D_NV
	BOOST_CHECK(x != ev.translate_2d_nv);
# endif
# ifdef GL_TRANSLATE_3D_NV
	BOOST_CHECK(x != ev.translate_3d_nv);
# endif
# ifdef GL_TRANSLATE_X_NV
	BOOST_CHECK(x != ev.translate_x_nv);
# endif
# ifdef GL_TRANSLATE_Y_NV
	BOOST_CHECK(x != ev.translate_y_nv);
# endif
# ifdef GL_TRANSPOSE_AFFINE_2D_NV
	BOOST_CHECK(x != ev.transpose_affine_2d_nv);
# endif
# ifdef GL_TRANSPOSE_AFFINE_3D_NV
	BOOST_CHECK(x != ev.transpose_affine_3d_nv);
# endif
#endif

#ifdef GL_AFFINE_3D_NV
	x = ev.affine_3d_nv;
	BOOST_CHECK(x == ev.affine_3d_nv);
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_TRANSLATE_2D_NV
	BOOST_CHECK(x != ev.translate_2d_nv);
# endif
# ifdef GL_TRANSLATE_3D_NV
	BOOST_CHECK(x != ev.translate_3d_nv);
# endif
# ifdef GL_TRANSLATE_X_NV
	BOOST_CHECK(x != ev.translate_x_nv);
# endif
# ifdef GL_TRANSLATE_Y_NV
	BOOST_CHECK(x != ev.translate_y_nv);
# endif
# ifdef GL_TRANSPOSE_AFFINE_2D_NV
	BOOST_CHECK(x != ev.transpose_affine_2d_nv);
# endif
# ifdef GL_TRANSPOSE_AFFINE_3D_NV
	BOOST_CHECK(x != ev.transpose_affine_3d_nv);
# endif
#endif

#ifdef GL_NONE
	x = ev.none;
	BOOST_CHECK(x == ev.none);
# ifdef GL_TRANSLATE_2D_NV
	BOOST_CHECK(x != ev.translate_2d_nv);
# endif
# ifdef GL_TRANSLATE_3D_NV
	BOOST_CHECK(x != ev.translate_3d_nv);
# endif
# ifdef GL_TRANSLATE_X_NV
	BOOST_CHECK(x != ev.translate_x_nv);
# endif
# ifdef GL_TRANSLATE_Y_NV
	BOOST_CHECK(x != ev.translate_y_nv);
# endif
# ifdef GL_TRANSPOSE_AFFINE_2D_NV
	BOOST_CHECK(x != ev.transpose_affine_2d_nv);
# endif
# ifdef GL_TRANSPOSE_AFFINE_3D_NV
	BOOST_CHECK(x != ev.transpose_affine_3d_nv);
# endif
#endif

#ifdef GL_TRANSLATE_2D_NV
	x = ev.translate_2d_nv;
	BOOST_CHECK(x == ev.translate_2d_nv);
# ifdef GL_TRANSLATE_3D_NV
	BOOST_CHECK(x != ev.translate_3d_nv);
# endif
# ifdef GL_TRANSLATE_X_NV
	BOOST_CHECK(x != ev.translate_x_nv);
# endif
# ifdef GL_TRANSLATE_Y_NV
	BOOST_CHECK(x != ev.translate_y_nv);
# endif
# ifdef GL_TRANSPOSE_AFFINE_2D_NV
	BOOST_CHECK(x != ev.transpose_affine_2d_nv);
# endif
# ifdef GL_TRANSPOSE_AFFINE_3D_NV
	BOOST_CHECK(x != ev.transpose_affine_3d_nv);
# endif
#endif

#ifdef GL_TRANSLATE_3D_NV
	x = ev.translate_3d_nv;
	BOOST_CHECK(x == ev.translate_3d_nv);
# ifdef GL_TRANSLATE_X_NV
	BOOST_CHECK(x != ev.translate_x_nv);
# endif
# ifdef GL_TRANSLATE_Y_NV
	BOOST_CHECK(x != ev.translate_y_nv);
# endif
# ifdef GL_TRANSPOSE_AFFINE_2D_NV
	BOOST_CHECK(x != ev.transpose_affine_2d_nv);
# endif
# ifdef GL_TRANSPOSE_AFFINE_3D_NV
	BOOST_CHECK(x != ev.transpose_affine_3d_nv);
# endif
#endif

#ifdef GL_TRANSLATE_X_NV
	x = ev.translate_x_nv;
	BOOST_CHECK(x == ev.translate_x_nv);
# ifdef GL_TRANSLATE_Y_NV
	BOOST_CHECK(x != ev.translate_y_nv);
# endif
# ifdef GL_TRANSPOSE_AFFINE_2D_NV
	BOOST_CHECK(x != ev.transpose_affine_2d_nv);
# endif
# ifdef GL_TRANSPOSE_AFFINE_3D_NV
	BOOST_CHECK(x != ev.transpose_affine_3d_nv);
# endif
#endif

#ifdef GL_TRANSLATE_Y_NV
	x = ev.translate_y_nv;
	BOOST_CHECK(x == ev.translate_y_nv);
# ifdef GL_TRANSPOSE_AFFINE_2D_NV
	BOOST_CHECK(x != ev.transpose_affine_2d_nv);
# endif
# ifdef GL_TRANSPOSE_AFFINE_3D_NV
	BOOST_CHECK(x != ev.transpose_affine_3d_nv);
# endif
#endif

#ifdef GL_TRANSPOSE_AFFINE_2D_NV
	x = ev.transpose_affine_2d_nv;
	BOOST_CHECK(x == ev.transpose_affine_2d_nv);
# ifdef GL_TRANSPOSE_AFFINE_3D_NV
	BOOST_CHECK(x != ev.transpose_affine_3d_nv);
# endif
#endif

#ifdef GL_TRANSPOSE_AFFINE_3D_NV
	x = ev.transpose_affine_3d_nv;
	BOOST_CHECK(x == ev.transpose_affine_3d_nv);
#endif
}

BOOST_AUTO_TEST_CASE(enum_path_transform_type_nv_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	path_transform_type_nv x;
	(void)x;

#ifdef GL_AFFINE_2D_NV
	x = ev.affine_2d_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"AFFINE_2D_NV"
	) == 0);
#endif

#ifdef GL_AFFINE_3D_NV
	x = ev.affine_3d_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"AFFINE_3D_NV"
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

#ifdef GL_TRANSLATE_2D_NV
	x = ev.translate_2d_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TRANSLATE_2D_NV"
	) == 0);
#endif

#ifdef GL_TRANSLATE_3D_NV
	x = ev.translate_3d_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TRANSLATE_3D_NV"
	) == 0);
#endif

#ifdef GL_TRANSLATE_X_NV
	x = ev.translate_x_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TRANSLATE_X_NV"
	) == 0);
#endif

#ifdef GL_TRANSLATE_Y_NV
	x = ev.translate_y_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TRANSLATE_Y_NV"
	) == 0);
#endif

#ifdef GL_TRANSPOSE_AFFINE_2D_NV
	x = ev.transpose_affine_2d_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TRANSPOSE_AFFINE_2D_NV"
	) == 0);
#endif

#ifdef GL_TRANSPOSE_AFFINE_3D_NV
	x = ev.transpose_affine_3d_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TRANSPOSE_AFFINE_3D_NV"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_path_transform_type_nv_range)
{
	using namespace oglplus;
	auto count = enum_value_range<path_transform_type_nv>().size();

#ifdef GL_AFFINE_2D_NV
{
	--count;
	auto r = enum_value_range<path_transform_type_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_transform_type_nv(GL_AFFINE_2D_NV)
	) != r.end());
}
#endif

#ifdef GL_AFFINE_3D_NV
{
	--count;
	auto r = enum_value_range<path_transform_type_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_transform_type_nv(GL_AFFINE_3D_NV)
	) != r.end());
}
#endif

#ifdef GL_NONE
{
	--count;
	auto r = enum_value_range<path_transform_type_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_transform_type_nv(GL_NONE)
	) != r.end());
}
#endif

#ifdef GL_TRANSLATE_2D_NV
{
	--count;
	auto r = enum_value_range<path_transform_type_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_transform_type_nv(GL_TRANSLATE_2D_NV)
	) != r.end());
}
#endif

#ifdef GL_TRANSLATE_3D_NV
{
	--count;
	auto r = enum_value_range<path_transform_type_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_transform_type_nv(GL_TRANSLATE_3D_NV)
	) != r.end());
}
#endif

#ifdef GL_TRANSLATE_X_NV
{
	--count;
	auto r = enum_value_range<path_transform_type_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_transform_type_nv(GL_TRANSLATE_X_NV)
	) != r.end());
}
#endif

#ifdef GL_TRANSLATE_Y_NV
{
	--count;
	auto r = enum_value_range<path_transform_type_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_transform_type_nv(GL_TRANSLATE_Y_NV)
	) != r.end());
}
#endif

#ifdef GL_TRANSPOSE_AFFINE_2D_NV
{
	--count;
	auto r = enum_value_range<path_transform_type_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_transform_type_nv(GL_TRANSPOSE_AFFINE_2D_NV)
	) != r.end());
}
#endif

#ifdef GL_TRANSPOSE_AFFINE_3D_NV
{
	--count;
	auto r = enum_value_range<path_transform_type_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_transform_type_nv(GL_TRANSPOSE_AFFINE_3D_NV)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_path_transform_type_nv_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	path_transform_type_nv x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_AFFINE_2D_NV
	x = ev.affine_2d_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.affine_2d_nv);
#endif

#ifdef GL_AFFINE_3D_NV
	x = ev.affine_3d_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.affine_3d_nv);
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

#ifdef GL_TRANSLATE_2D_NV
	x = ev.translate_2d_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.translate_2d_nv);
#endif

#ifdef GL_TRANSLATE_3D_NV
	x = ev.translate_3d_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.translate_3d_nv);
#endif

#ifdef GL_TRANSLATE_X_NV
	x = ev.translate_x_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.translate_x_nv);
#endif

#ifdef GL_TRANSLATE_Y_NV
	x = ev.translate_y_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.translate_y_nv);
#endif

#ifdef GL_TRANSPOSE_AFFINE_2D_NV
	x = ev.transpose_affine_2d_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.transpose_affine_2d_nv);
#endif

#ifdef GL_TRANSPOSE_AFFINE_3D_NV
	x = ev.transpose_affine_3d_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.transpose_affine_3d_nv);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
