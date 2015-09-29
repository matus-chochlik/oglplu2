//  File test/oglplus/enums/texture_target.cpp
//
//  Automatically generated file, DO NOT modify manually.
//  Edit the enumeration source files in 'source/enums/oglplus'
//  or the 'source/enums/make_enum.py' script instead.
//
//  Copyright Matus Chochlik.
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt
//
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE OGLPLUS_texture_target

#include <boost/test/unit_test.hpp>
#include "common.hpp"

BOOST_AUTO_TEST_SUITE(enum_texture_target)

BOOST_AUTO_TEST_CASE(enum_texture_target_values)
{
	using namespace oglplus;
	enum_values ev;
	texture_target x;

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
# ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_X
	BOOST_CHECK(x != ev.texture_cube_map_negative_x);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_Y
	BOOST_CHECK(x != ev.texture_cube_map_negative_y);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_Z
	BOOST_CHECK(x != ev.texture_cube_map_negative_z);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_X
	BOOST_CHECK(x != ev.texture_cube_map_positive_x);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_Y
	BOOST_CHECK(x != ev.texture_cube_map_positive_y);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_Z
	BOOST_CHECK(x != ev.texture_cube_map_positive_z);
# endif
# ifdef GL_TEXTURE_RECTANGLE
	BOOST_CHECK(x != ev.texture_rectangle);
# endif
#endif

#ifdef GL_TEXTURE_1D_ARRAY
	x = ev.texture_1d_array;
# ifdef GL_TEXTURE_1D
	BOOST_CHECK(x != ev.texture_1d);
# endif
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
# ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_X
	BOOST_CHECK(x != ev.texture_cube_map_negative_x);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_Y
	BOOST_CHECK(x != ev.texture_cube_map_negative_y);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_Z
	BOOST_CHECK(x != ev.texture_cube_map_negative_z);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_X
	BOOST_CHECK(x != ev.texture_cube_map_positive_x);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_Y
	BOOST_CHECK(x != ev.texture_cube_map_positive_y);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_Z
	BOOST_CHECK(x != ev.texture_cube_map_positive_z);
# endif
# ifdef GL_TEXTURE_RECTANGLE
	BOOST_CHECK(x != ev.texture_rectangle);
# endif
#endif

#ifdef GL_TEXTURE_2D
	x = ev.texture_2d;
# ifdef GL_TEXTURE_1D
	BOOST_CHECK(x != ev.texture_1d);
# endif
# ifdef GL_TEXTURE_1D_ARRAY
	BOOST_CHECK(x != ev.texture_1d_array);
# endif
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
# ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_X
	BOOST_CHECK(x != ev.texture_cube_map_negative_x);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_Y
	BOOST_CHECK(x != ev.texture_cube_map_negative_y);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_Z
	BOOST_CHECK(x != ev.texture_cube_map_negative_z);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_X
	BOOST_CHECK(x != ev.texture_cube_map_positive_x);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_Y
	BOOST_CHECK(x != ev.texture_cube_map_positive_y);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_Z
	BOOST_CHECK(x != ev.texture_cube_map_positive_z);
# endif
# ifdef GL_TEXTURE_RECTANGLE
	BOOST_CHECK(x != ev.texture_rectangle);
# endif
#endif

#ifdef GL_TEXTURE_2D_ARRAY
	x = ev.texture_2d_array;
# ifdef GL_TEXTURE_1D
	BOOST_CHECK(x != ev.texture_1d);
# endif
# ifdef GL_TEXTURE_1D_ARRAY
	BOOST_CHECK(x != ev.texture_1d_array);
# endif
# ifdef GL_TEXTURE_2D
	BOOST_CHECK(x != ev.texture_2d);
# endif
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
# ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_X
	BOOST_CHECK(x != ev.texture_cube_map_negative_x);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_Y
	BOOST_CHECK(x != ev.texture_cube_map_negative_y);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_Z
	BOOST_CHECK(x != ev.texture_cube_map_negative_z);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_X
	BOOST_CHECK(x != ev.texture_cube_map_positive_x);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_Y
	BOOST_CHECK(x != ev.texture_cube_map_positive_y);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_Z
	BOOST_CHECK(x != ev.texture_cube_map_positive_z);
# endif
# ifdef GL_TEXTURE_RECTANGLE
	BOOST_CHECK(x != ev.texture_rectangle);
# endif
#endif

#ifdef GL_TEXTURE_2D_MULTISAMPLE
	x = ev.texture_2d_multisample;
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
# ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_X
	BOOST_CHECK(x != ev.texture_cube_map_negative_x);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_Y
	BOOST_CHECK(x != ev.texture_cube_map_negative_y);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_Z
	BOOST_CHECK(x != ev.texture_cube_map_negative_z);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_X
	BOOST_CHECK(x != ev.texture_cube_map_positive_x);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_Y
	BOOST_CHECK(x != ev.texture_cube_map_positive_y);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_Z
	BOOST_CHECK(x != ev.texture_cube_map_positive_z);
# endif
# ifdef GL_TEXTURE_RECTANGLE
	BOOST_CHECK(x != ev.texture_rectangle);
# endif
#endif

#ifdef GL_TEXTURE_2D_MULTISAMPLE_ARRAY
	x = ev.texture_2d_multisample_array;
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
# ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_X
	BOOST_CHECK(x != ev.texture_cube_map_negative_x);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_Y
	BOOST_CHECK(x != ev.texture_cube_map_negative_y);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_Z
	BOOST_CHECK(x != ev.texture_cube_map_negative_z);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_X
	BOOST_CHECK(x != ev.texture_cube_map_positive_x);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_Y
	BOOST_CHECK(x != ev.texture_cube_map_positive_y);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_Z
	BOOST_CHECK(x != ev.texture_cube_map_positive_z);
# endif
# ifdef GL_TEXTURE_RECTANGLE
	BOOST_CHECK(x != ev.texture_rectangle);
# endif
#endif

#ifdef GL_TEXTURE_3D
	x = ev.texture_3d;
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
# ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_X
	BOOST_CHECK(x != ev.texture_cube_map_negative_x);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_Y
	BOOST_CHECK(x != ev.texture_cube_map_negative_y);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_Z
	BOOST_CHECK(x != ev.texture_cube_map_negative_z);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_X
	BOOST_CHECK(x != ev.texture_cube_map_positive_x);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_Y
	BOOST_CHECK(x != ev.texture_cube_map_positive_y);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_Z
	BOOST_CHECK(x != ev.texture_cube_map_positive_z);
# endif
# ifdef GL_TEXTURE_RECTANGLE
	BOOST_CHECK(x != ev.texture_rectangle);
# endif
#endif

#ifdef GL_TEXTURE_BUFFER
	x = ev.texture_buffer;
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
	BOOST_CHECK(x == ev.texture_buffer);
# ifdef GL_TEXTURE_CUBE_MAP
	BOOST_CHECK(x != ev.texture_cube_map);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.texture_cube_map_array);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_X
	BOOST_CHECK(x != ev.texture_cube_map_negative_x);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_Y
	BOOST_CHECK(x != ev.texture_cube_map_negative_y);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_Z
	BOOST_CHECK(x != ev.texture_cube_map_negative_z);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_X
	BOOST_CHECK(x != ev.texture_cube_map_positive_x);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_Y
	BOOST_CHECK(x != ev.texture_cube_map_positive_y);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_Z
	BOOST_CHECK(x != ev.texture_cube_map_positive_z);
# endif
# ifdef GL_TEXTURE_RECTANGLE
	BOOST_CHECK(x != ev.texture_rectangle);
# endif
#endif

#ifdef GL_TEXTURE_CUBE_MAP
	x = ev.texture_cube_map;
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
	BOOST_CHECK(x == ev.texture_cube_map);
# ifdef GL_TEXTURE_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.texture_cube_map_array);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_X
	BOOST_CHECK(x != ev.texture_cube_map_negative_x);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_Y
	BOOST_CHECK(x != ev.texture_cube_map_negative_y);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_Z
	BOOST_CHECK(x != ev.texture_cube_map_negative_z);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_X
	BOOST_CHECK(x != ev.texture_cube_map_positive_x);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_Y
	BOOST_CHECK(x != ev.texture_cube_map_positive_y);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_Z
	BOOST_CHECK(x != ev.texture_cube_map_positive_z);
# endif
# ifdef GL_TEXTURE_RECTANGLE
	BOOST_CHECK(x != ev.texture_rectangle);
# endif
#endif

#ifdef GL_TEXTURE_CUBE_MAP_ARRAY
	x = ev.texture_cube_map_array;
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
	BOOST_CHECK(x == ev.texture_cube_map_array);
# ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_X
	BOOST_CHECK(x != ev.texture_cube_map_negative_x);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_Y
	BOOST_CHECK(x != ev.texture_cube_map_negative_y);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_Z
	BOOST_CHECK(x != ev.texture_cube_map_negative_z);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_X
	BOOST_CHECK(x != ev.texture_cube_map_positive_x);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_Y
	BOOST_CHECK(x != ev.texture_cube_map_positive_y);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_Z
	BOOST_CHECK(x != ev.texture_cube_map_positive_z);
# endif
# ifdef GL_TEXTURE_RECTANGLE
	BOOST_CHECK(x != ev.texture_rectangle);
# endif
#endif

#ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_X
	x = ev.texture_cube_map_negative_x;
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
	BOOST_CHECK(x == ev.texture_cube_map_negative_x);
# ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_Y
	BOOST_CHECK(x != ev.texture_cube_map_negative_y);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_Z
	BOOST_CHECK(x != ev.texture_cube_map_negative_z);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_X
	BOOST_CHECK(x != ev.texture_cube_map_positive_x);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_Y
	BOOST_CHECK(x != ev.texture_cube_map_positive_y);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_Z
	BOOST_CHECK(x != ev.texture_cube_map_positive_z);
# endif
# ifdef GL_TEXTURE_RECTANGLE
	BOOST_CHECK(x != ev.texture_rectangle);
# endif
#endif

#ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_Y
	x = ev.texture_cube_map_negative_y;
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
# ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_X
	BOOST_CHECK(x != ev.texture_cube_map_negative_x);
# endif
	BOOST_CHECK(x == ev.texture_cube_map_negative_y);
# ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_Z
	BOOST_CHECK(x != ev.texture_cube_map_negative_z);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_X
	BOOST_CHECK(x != ev.texture_cube_map_positive_x);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_Y
	BOOST_CHECK(x != ev.texture_cube_map_positive_y);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_Z
	BOOST_CHECK(x != ev.texture_cube_map_positive_z);
# endif
# ifdef GL_TEXTURE_RECTANGLE
	BOOST_CHECK(x != ev.texture_rectangle);
# endif
#endif

#ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_Z
	x = ev.texture_cube_map_negative_z;
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
# ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_X
	BOOST_CHECK(x != ev.texture_cube_map_negative_x);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_Y
	BOOST_CHECK(x != ev.texture_cube_map_negative_y);
# endif
	BOOST_CHECK(x == ev.texture_cube_map_negative_z);
# ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_X
	BOOST_CHECK(x != ev.texture_cube_map_positive_x);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_Y
	BOOST_CHECK(x != ev.texture_cube_map_positive_y);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_Z
	BOOST_CHECK(x != ev.texture_cube_map_positive_z);
# endif
# ifdef GL_TEXTURE_RECTANGLE
	BOOST_CHECK(x != ev.texture_rectangle);
# endif
#endif

#ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_X
	x = ev.texture_cube_map_positive_x;
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
# ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_X
	BOOST_CHECK(x != ev.texture_cube_map_negative_x);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_Y
	BOOST_CHECK(x != ev.texture_cube_map_negative_y);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_Z
	BOOST_CHECK(x != ev.texture_cube_map_negative_z);
# endif
	BOOST_CHECK(x == ev.texture_cube_map_positive_x);
# ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_Y
	BOOST_CHECK(x != ev.texture_cube_map_positive_y);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_Z
	BOOST_CHECK(x != ev.texture_cube_map_positive_z);
# endif
# ifdef GL_TEXTURE_RECTANGLE
	BOOST_CHECK(x != ev.texture_rectangle);
# endif
#endif

#ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_Y
	x = ev.texture_cube_map_positive_y;
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
# ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_X
	BOOST_CHECK(x != ev.texture_cube_map_negative_x);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_Y
	BOOST_CHECK(x != ev.texture_cube_map_negative_y);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_Z
	BOOST_CHECK(x != ev.texture_cube_map_negative_z);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_X
	BOOST_CHECK(x != ev.texture_cube_map_positive_x);
# endif
	BOOST_CHECK(x == ev.texture_cube_map_positive_y);
# ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_Z
	BOOST_CHECK(x != ev.texture_cube_map_positive_z);
# endif
# ifdef GL_TEXTURE_RECTANGLE
	BOOST_CHECK(x != ev.texture_rectangle);
# endif
#endif

#ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_Z
	x = ev.texture_cube_map_positive_z;
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
# ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_X
	BOOST_CHECK(x != ev.texture_cube_map_negative_x);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_Y
	BOOST_CHECK(x != ev.texture_cube_map_negative_y);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_Z
	BOOST_CHECK(x != ev.texture_cube_map_negative_z);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_X
	BOOST_CHECK(x != ev.texture_cube_map_positive_x);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_Y
	BOOST_CHECK(x != ev.texture_cube_map_positive_y);
# endif
	BOOST_CHECK(x == ev.texture_cube_map_positive_z);
# ifdef GL_TEXTURE_RECTANGLE
	BOOST_CHECK(x != ev.texture_rectangle);
# endif
#endif

#ifdef GL_TEXTURE_RECTANGLE
	x = ev.texture_rectangle;
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
# ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_X
	BOOST_CHECK(x != ev.texture_cube_map_negative_x);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_Y
	BOOST_CHECK(x != ev.texture_cube_map_negative_y);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_Z
	BOOST_CHECK(x != ev.texture_cube_map_negative_z);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_X
	BOOST_CHECK(x != ev.texture_cube_map_positive_x);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_Y
	BOOST_CHECK(x != ev.texture_cube_map_positive_y);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_Z
	BOOST_CHECK(x != ev.texture_cube_map_positive_z);
# endif
	BOOST_CHECK(x == ev.texture_rectangle);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
