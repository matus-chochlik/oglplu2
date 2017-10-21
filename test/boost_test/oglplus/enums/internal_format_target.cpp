//  File test/boost_test/oglplus/enums/internal_format_target.cpp
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
#include "common.hpp"
#define BOOST_TEST_MODULE OGLPLUS_internal_format_target

#include "../../unit_test_begin.inl"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_internal_format_target_tests)

BOOST_AUTO_TEST_CASE(enum_internal_format_target_values)
{
	using namespace oglplus;
	enum_values ev;
	EAGINE_MAYBE_UNUSED(ev);
	internal_format_target x;
	EAGINE_MAYBE_UNUSED(x);

#ifdef GL_RENDERBUFFER
	x = ev.renderbuffer;
	BOOST_CHECK(x == ev.renderbuffer);
# ifdef GL_TEXTURE_1D
	BOOST_CHECK(x != ev.texture_1d);
# endif
# ifdef GL_TEXTURE_1D_ARRAY
	BOOST_CHECK(x != ev.texture_1d_array);
# endif
# ifdef GL_TEXTURE_2D
	BOOST_CHECK(x != ev.texture_2d);
# endif
# ifdef GL_TEXTURE_2D_ARRAY
	BOOST_CHECK(x != ev.texture_2d_array);
# endif
# ifdef GL_TEXTURE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.texture_2d_multisample);
# endif
# ifdef GL_TEXTURE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.texture_2d_multisample_array);
# endif
# ifdef GL_TEXTURE_3D
	BOOST_CHECK(x != ev.texture_3d);
# endif
# ifdef GL_TEXTURE_BUFFER
	BOOST_CHECK(x != ev.texture_buffer);
# endif
# ifdef GL_TEXTURE_CUBE_MAP
	BOOST_CHECK(x != ev.texture_cube_map);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.texture_cube_map_array);
# endif
# ifdef GL_TEXTURE_RECTANGLE
	BOOST_CHECK(x != ev.texture_rectangle);
# endif
#endif

#ifdef GL_TEXTURE_1D
	x = ev.texture_1d;
	BOOST_CHECK(x == ev.texture_1d);
# ifdef GL_TEXTURE_1D_ARRAY
	BOOST_CHECK(x != ev.texture_1d_array);
# endif
# ifdef GL_TEXTURE_2D
	BOOST_CHECK(x != ev.texture_2d);
# endif
# ifdef GL_TEXTURE_2D_ARRAY
	BOOST_CHECK(x != ev.texture_2d_array);
# endif
# ifdef GL_TEXTURE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.texture_2d_multisample);
# endif
# ifdef GL_TEXTURE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.texture_2d_multisample_array);
# endif
# ifdef GL_TEXTURE_3D
	BOOST_CHECK(x != ev.texture_3d);
# endif
# ifdef GL_TEXTURE_BUFFER
	BOOST_CHECK(x != ev.texture_buffer);
# endif
# ifdef GL_TEXTURE_CUBE_MAP
	BOOST_CHECK(x != ev.texture_cube_map);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.texture_cube_map_array);
# endif
# ifdef GL_TEXTURE_RECTANGLE
	BOOST_CHECK(x != ev.texture_rectangle);
# endif
#endif

#ifdef GL_TEXTURE_1D_ARRAY
	x = ev.texture_1d_array;
	BOOST_CHECK(x == ev.texture_1d_array);
# ifdef GL_TEXTURE_2D
	BOOST_CHECK(x != ev.texture_2d);
# endif
# ifdef GL_TEXTURE_2D_ARRAY
	BOOST_CHECK(x != ev.texture_2d_array);
# endif
# ifdef GL_TEXTURE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.texture_2d_multisample);
# endif
# ifdef GL_TEXTURE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.texture_2d_multisample_array);
# endif
# ifdef GL_TEXTURE_3D
	BOOST_CHECK(x != ev.texture_3d);
# endif
# ifdef GL_TEXTURE_BUFFER
	BOOST_CHECK(x != ev.texture_buffer);
# endif
# ifdef GL_TEXTURE_CUBE_MAP
	BOOST_CHECK(x != ev.texture_cube_map);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.texture_cube_map_array);
# endif
# ifdef GL_TEXTURE_RECTANGLE
	BOOST_CHECK(x != ev.texture_rectangle);
# endif
#endif

#ifdef GL_TEXTURE_2D
	x = ev.texture_2d;
	BOOST_CHECK(x == ev.texture_2d);
# ifdef GL_TEXTURE_2D_ARRAY
	BOOST_CHECK(x != ev.texture_2d_array);
# endif
# ifdef GL_TEXTURE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.texture_2d_multisample);
# endif
# ifdef GL_TEXTURE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.texture_2d_multisample_array);
# endif
# ifdef GL_TEXTURE_3D
	BOOST_CHECK(x != ev.texture_3d);
# endif
# ifdef GL_TEXTURE_BUFFER
	BOOST_CHECK(x != ev.texture_buffer);
# endif
# ifdef GL_TEXTURE_CUBE_MAP
	BOOST_CHECK(x != ev.texture_cube_map);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.texture_cube_map_array);
# endif
# ifdef GL_TEXTURE_RECTANGLE
	BOOST_CHECK(x != ev.texture_rectangle);
# endif
#endif

#ifdef GL_TEXTURE_2D_ARRAY
	x = ev.texture_2d_array;
	BOOST_CHECK(x == ev.texture_2d_array);
# ifdef GL_TEXTURE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.texture_2d_multisample);
# endif
# ifdef GL_TEXTURE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.texture_2d_multisample_array);
# endif
# ifdef GL_TEXTURE_3D
	BOOST_CHECK(x != ev.texture_3d);
# endif
# ifdef GL_TEXTURE_BUFFER
	BOOST_CHECK(x != ev.texture_buffer);
# endif
# ifdef GL_TEXTURE_CUBE_MAP
	BOOST_CHECK(x != ev.texture_cube_map);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.texture_cube_map_array);
# endif
# ifdef GL_TEXTURE_RECTANGLE
	BOOST_CHECK(x != ev.texture_rectangle);
# endif
#endif

#ifdef GL_TEXTURE_2D_MULTISAMPLE
	x = ev.texture_2d_multisample;
	BOOST_CHECK(x == ev.texture_2d_multisample);
# ifdef GL_TEXTURE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.texture_2d_multisample_array);
# endif
# ifdef GL_TEXTURE_3D
	BOOST_CHECK(x != ev.texture_3d);
# endif
# ifdef GL_TEXTURE_BUFFER
	BOOST_CHECK(x != ev.texture_buffer);
# endif
# ifdef GL_TEXTURE_CUBE_MAP
	BOOST_CHECK(x != ev.texture_cube_map);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.texture_cube_map_array);
# endif
# ifdef GL_TEXTURE_RECTANGLE
	BOOST_CHECK(x != ev.texture_rectangle);
# endif
#endif

#ifdef GL_TEXTURE_2D_MULTISAMPLE_ARRAY
	x = ev.texture_2d_multisample_array;
	BOOST_CHECK(x == ev.texture_2d_multisample_array);
# ifdef GL_TEXTURE_3D
	BOOST_CHECK(x != ev.texture_3d);
# endif
# ifdef GL_TEXTURE_BUFFER
	BOOST_CHECK(x != ev.texture_buffer);
# endif
# ifdef GL_TEXTURE_CUBE_MAP
	BOOST_CHECK(x != ev.texture_cube_map);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.texture_cube_map_array);
# endif
# ifdef GL_TEXTURE_RECTANGLE
	BOOST_CHECK(x != ev.texture_rectangle);
# endif
#endif

#ifdef GL_TEXTURE_3D
	x = ev.texture_3d;
	BOOST_CHECK(x == ev.texture_3d);
# ifdef GL_TEXTURE_BUFFER
	BOOST_CHECK(x != ev.texture_buffer);
# endif
# ifdef GL_TEXTURE_CUBE_MAP
	BOOST_CHECK(x != ev.texture_cube_map);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.texture_cube_map_array);
# endif
# ifdef GL_TEXTURE_RECTANGLE
	BOOST_CHECK(x != ev.texture_rectangle);
# endif
#endif

#ifdef GL_TEXTURE_BUFFER
	x = ev.texture_buffer;
	BOOST_CHECK(x == ev.texture_buffer);
# ifdef GL_TEXTURE_CUBE_MAP
	BOOST_CHECK(x != ev.texture_cube_map);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.texture_cube_map_array);
# endif
# ifdef GL_TEXTURE_RECTANGLE
	BOOST_CHECK(x != ev.texture_rectangle);
# endif
#endif

#ifdef GL_TEXTURE_CUBE_MAP
	x = ev.texture_cube_map;
	BOOST_CHECK(x == ev.texture_cube_map);
# ifdef GL_TEXTURE_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.texture_cube_map_array);
# endif
# ifdef GL_TEXTURE_RECTANGLE
	BOOST_CHECK(x != ev.texture_rectangle);
# endif
#endif

#ifdef GL_TEXTURE_CUBE_MAP_ARRAY
	x = ev.texture_cube_map_array;
	BOOST_CHECK(x == ev.texture_cube_map_array);
# ifdef GL_TEXTURE_RECTANGLE
	BOOST_CHECK(x != ev.texture_rectangle);
# endif
#endif

#ifdef GL_TEXTURE_RECTANGLE
	x = ev.texture_rectangle;
	BOOST_CHECK(x == ev.texture_rectangle);
#endif
}

BOOST_AUTO_TEST_CASE(enum_internal_format_target_names)
{
	using namespace oglplus;
	enum_values ev;
	EAGINE_MAYBE_UNUSED(ev);
	internal_format_target x;
	EAGINE_MAYBE_UNUSED(x);

#ifdef GL_RENDERBUFFER
	x = ev.renderbuffer;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RENDERBUFFER"
	) == 0);
#endif

#ifdef GL_TEXTURE_1D
	x = ev.texture_1d;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_1D"
	) == 0);
#endif

#ifdef GL_TEXTURE_1D_ARRAY
	x = ev.texture_1d_array;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_1D_ARRAY"
	) == 0);
#endif

#ifdef GL_TEXTURE_2D
	x = ev.texture_2d;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_2D"
	) == 0);
#endif

#ifdef GL_TEXTURE_2D_ARRAY
	x = ev.texture_2d_array;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_2D_ARRAY"
	) == 0);
#endif

#ifdef GL_TEXTURE_2D_MULTISAMPLE
	x = ev.texture_2d_multisample;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_2D_MULTISAMPLE"
	) == 0);
#endif

#ifdef GL_TEXTURE_2D_MULTISAMPLE_ARRAY
	x = ev.texture_2d_multisample_array;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_2D_MULTISAMPLE_ARRAY"
	) == 0);
#endif

#ifdef GL_TEXTURE_3D
	x = ev.texture_3d;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_3D"
	) == 0);
#endif

#ifdef GL_TEXTURE_BUFFER
	x = ev.texture_buffer;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_BUFFER"
	) == 0);
#endif

#ifdef GL_TEXTURE_CUBE_MAP
	x = ev.texture_cube_map;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_CUBE_MAP"
	) == 0);
#endif

#ifdef GL_TEXTURE_CUBE_MAP_ARRAY
	x = ev.texture_cube_map_array;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_CUBE_MAP_ARRAY"
	) == 0);
#endif

#ifdef GL_TEXTURE_RECTANGLE
	x = ev.texture_rectangle;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_RECTANGLE"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_internal_format_target_range)
{
	using namespace oglplus;
	auto count = enum_value_range<internal_format_target>().size();

#ifdef GL_RENDERBUFFER
{
	--count;
	auto r = enum_value_range<internal_format_target>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		internal_format_target(GL_RENDERBUFFER)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_1D
{
	--count;
	auto r = enum_value_range<internal_format_target>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		internal_format_target(GL_TEXTURE_1D)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_1D_ARRAY
{
	--count;
	auto r = enum_value_range<internal_format_target>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		internal_format_target(GL_TEXTURE_1D_ARRAY)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_2D
{
	--count;
	auto r = enum_value_range<internal_format_target>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		internal_format_target(GL_TEXTURE_2D)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_2D_ARRAY
{
	--count;
	auto r = enum_value_range<internal_format_target>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		internal_format_target(GL_TEXTURE_2D_ARRAY)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_2D_MULTISAMPLE
{
	--count;
	auto r = enum_value_range<internal_format_target>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		internal_format_target(GL_TEXTURE_2D_MULTISAMPLE)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_2D_MULTISAMPLE_ARRAY
{
	--count;
	auto r = enum_value_range<internal_format_target>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		internal_format_target(GL_TEXTURE_2D_MULTISAMPLE_ARRAY)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_3D
{
	--count;
	auto r = enum_value_range<internal_format_target>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		internal_format_target(GL_TEXTURE_3D)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_BUFFER
{
	--count;
	auto r = enum_value_range<internal_format_target>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		internal_format_target(GL_TEXTURE_BUFFER)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_CUBE_MAP
{
	--count;
	auto r = enum_value_range<internal_format_target>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		internal_format_target(GL_TEXTURE_CUBE_MAP)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_CUBE_MAP_ARRAY
{
	--count;
	auto r = enum_value_range<internal_format_target>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		internal_format_target(GL_TEXTURE_CUBE_MAP_ARRAY)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_RECTANGLE
{
	--count;
	auto r = enum_value_range<internal_format_target>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		internal_format_target(GL_TEXTURE_RECTANGLE)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_internal_format_target_any)
{
	using namespace oglplus;
	enum_values ev;
	EAGINE_MAYBE_UNUSED(ev);
	internal_format_target x, y;
	EAGINE_MAYBE_UNUSED(x);
	EAGINE_MAYBE_UNUSED(y);
	any_enum_value a;
	EAGINE_MAYBE_UNUSED(a);

#ifdef GL_RENDERBUFFER
	x = ev.renderbuffer;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.renderbuffer);
#endif

#ifdef GL_TEXTURE_1D
	x = ev.texture_1d;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_1d);
#endif

#ifdef GL_TEXTURE_1D_ARRAY
	x = ev.texture_1d_array;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_1d_array);
#endif

#ifdef GL_TEXTURE_2D
	x = ev.texture_2d;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_2d);
#endif

#ifdef GL_TEXTURE_2D_ARRAY
	x = ev.texture_2d_array;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_2d_array);
#endif

#ifdef GL_TEXTURE_2D_MULTISAMPLE
	x = ev.texture_2d_multisample;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_2d_multisample);
#endif

#ifdef GL_TEXTURE_2D_MULTISAMPLE_ARRAY
	x = ev.texture_2d_multisample_array;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_2d_multisample_array);
#endif

#ifdef GL_TEXTURE_3D
	x = ev.texture_3d;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_3d);
#endif

#ifdef GL_TEXTURE_BUFFER
	x = ev.texture_buffer;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_buffer);
#endif

#ifdef GL_TEXTURE_CUBE_MAP
	x = ev.texture_cube_map;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_cube_map);
#endif

#ifdef GL_TEXTURE_CUBE_MAP_ARRAY
	x = ev.texture_cube_map_array;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_cube_map_array);
#endif

#ifdef GL_TEXTURE_RECTANGLE
	x = ev.texture_rectangle;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_rectangle);
#endif
}

BOOST_AUTO_TEST_SUITE_END()

#include "../../unit_test_end.inl"
