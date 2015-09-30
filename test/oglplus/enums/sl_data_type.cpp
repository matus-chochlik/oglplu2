//  File test/oglplus/enums/sl_data_type.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_sl_data_type

#include <boost/test/unit_test.hpp>
#include "common.hpp"

BOOST_AUTO_TEST_SUITE(enum_sl_data_type)

BOOST_AUTO_TEST_CASE(enum_sl_data_type_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	sl_data_type x;
	(void)x;

#ifdef GL_BOOL
	x = ev.bool_;
	BOOST_CHECK(x == ev.bool_);
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_BOOL_VEC2
	x = ev.bool_vec2;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
	BOOST_CHECK(x == ev.bool_vec2);
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_BOOL_VEC3
	x = ev.bool_vec3;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
	BOOST_CHECK(x == ev.bool_vec3);
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_BOOL_VEC4
	x = ev.bool_vec4;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
	BOOST_CHECK(x == ev.bool_vec4);
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_DOUBLE
	x = ev.double_;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
	BOOST_CHECK(x == ev.double_);
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_DOUBLE_MAT2
	x = ev.double_mat2;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
	BOOST_CHECK(x == ev.double_mat2);
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_DOUBLE_MAT2x3
	x = ev.double_mat2x3;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
	BOOST_CHECK(x == ev.double_mat2x3);
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_DOUBLE_MAT2x4
	x = ev.double_mat2x4;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
	BOOST_CHECK(x == ev.double_mat2x4);
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_DOUBLE_MAT3
	x = ev.double_mat3;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
	BOOST_CHECK(x == ev.double_mat3);
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_DOUBLE_MAT3x2
	x = ev.double_mat3x2;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
	BOOST_CHECK(x == ev.double_mat3x2);
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_DOUBLE_MAT3x4
	x = ev.double_mat3x4;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
	BOOST_CHECK(x == ev.double_mat3x4);
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_DOUBLE_MAT4
	x = ev.double_mat4;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
	BOOST_CHECK(x == ev.double_mat4);
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_DOUBLE_MAT4x2
	x = ev.double_mat4x2;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
	BOOST_CHECK(x == ev.double_mat4x2);
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_DOUBLE_MAT4x3
	x = ev.double_mat4x3;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
	BOOST_CHECK(x == ev.double_mat4x3);
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_DOUBLE_VEC2
	x = ev.double_vec2;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
	BOOST_CHECK(x == ev.double_vec2);
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_DOUBLE_VEC3
	x = ev.double_vec3;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
	BOOST_CHECK(x == ev.double_vec3);
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_DOUBLE_VEC4
	x = ev.double_vec4;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
	BOOST_CHECK(x == ev.double_vec4);
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_FLOAT
	x = ev.float_;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
	BOOST_CHECK(x == ev.float_);
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_FLOAT_MAT2
	x = ev.float_mat2;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
	BOOST_CHECK(x == ev.float_mat2);
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_FLOAT_MAT2x3
	x = ev.float_mat2x3;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
	BOOST_CHECK(x == ev.float_mat2x3);
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_FLOAT_MAT2x4
	x = ev.float_mat2x4;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
	BOOST_CHECK(x == ev.float_mat2x4);
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_FLOAT_MAT3
	x = ev.float_mat3;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
	BOOST_CHECK(x == ev.float_mat3);
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_FLOAT_MAT3x2
	x = ev.float_mat3x2;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
	BOOST_CHECK(x == ev.float_mat3x2);
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_FLOAT_MAT3x4
	x = ev.float_mat3x4;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
	BOOST_CHECK(x == ev.float_mat3x4);
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_FLOAT_MAT4
	x = ev.float_mat4;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
	BOOST_CHECK(x == ev.float_mat4);
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_FLOAT_MAT4x2
	x = ev.float_mat4x2;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
	BOOST_CHECK(x == ev.float_mat4x2);
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_FLOAT_MAT4x3
	x = ev.float_mat4x3;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
	BOOST_CHECK(x == ev.float_mat4x3);
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_FLOAT_VEC2
	x = ev.float_vec2;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
	BOOST_CHECK(x == ev.float_vec2);
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_FLOAT_VEC3
	x = ev.float_vec3;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
	BOOST_CHECK(x == ev.float_vec3);
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_FLOAT_VEC4
	x = ev.float_vec4;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
	BOOST_CHECK(x == ev.float_vec4);
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_IMAGE_1D
	x = ev.image_1d;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
	BOOST_CHECK(x == ev.image_1d);
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_IMAGE_1D_ARRAY
	x = ev.image_1d_array;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
	BOOST_CHECK(x == ev.image_1d_array);
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_IMAGE_2D
	x = ev.image_2d;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
	BOOST_CHECK(x == ev.image_2d);
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_IMAGE_2D_ARRAY
	x = ev.image_2d_array;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
	BOOST_CHECK(x == ev.image_2d_array);
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_IMAGE_2D_MULTISAMPLE
	x = ev.image_2d_multisample;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
	BOOST_CHECK(x == ev.image_2d_multisample);
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	x = ev.image_2d_multisample_array;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
	BOOST_CHECK(x == ev.image_2d_multisample_array);
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_IMAGE_2D_RECT
	x = ev.image_2d_rect;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
	BOOST_CHECK(x == ev.image_2d_rect);
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_IMAGE_3D
	x = ev.image_3d;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
	BOOST_CHECK(x == ev.image_3d);
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_IMAGE_BUFFER
	x = ev.image_buffer;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
	BOOST_CHECK(x == ev.image_buffer);
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_IMAGE_CUBE
	x = ev.image_cube;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
	BOOST_CHECK(x == ev.image_cube);
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_INT
	x = ev.int_;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
	BOOST_CHECK(x == ev.int_);
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_INT_IMAGE_1D
	x = ev.int_image_1d;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
	BOOST_CHECK(x == ev.int_image_1d);
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_INT_IMAGE_1D_ARRAY
	x = ev.int_image_1d_array;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
	BOOST_CHECK(x == ev.int_image_1d_array);
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_INT_IMAGE_2D
	x = ev.int_image_2d;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
	BOOST_CHECK(x == ev.int_image_2d);
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_INT_IMAGE_2D_ARRAY
	x = ev.int_image_2d_array;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
	BOOST_CHECK(x == ev.int_image_2d_array);
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	x = ev.int_image_2d_multisample;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
	BOOST_CHECK(x == ev.int_image_2d_multisample);
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	x = ev.int_image_2d_multisample_array;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
	BOOST_CHECK(x == ev.int_image_2d_multisample_array);
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_INT_IMAGE_2D_RECT
	x = ev.int_image_2d_rect;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
	BOOST_CHECK(x == ev.int_image_2d_rect);
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_INT_IMAGE_3D
	x = ev.int_image_3d;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
	BOOST_CHECK(x == ev.int_image_3d);
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_INT_IMAGE_BUFFER
	x = ev.int_image_buffer;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
	BOOST_CHECK(x == ev.int_image_buffer);
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_INT_IMAGE_CUBE
	x = ev.int_image_cube;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
	BOOST_CHECK(x == ev.int_image_cube);
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_INT_SAMPLER_1D
	x = ev.int_sampler_1d;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
	BOOST_CHECK(x == ev.int_sampler_1d);
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_INT_SAMPLER_1D_ARRAY
	x = ev.int_sampler_1d_array;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
	BOOST_CHECK(x == ev.int_sampler_1d_array);
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_INT_SAMPLER_2D
	x = ev.int_sampler_2d;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
	BOOST_CHECK(x == ev.int_sampler_2d);
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_INT_SAMPLER_2D_ARRAY
	x = ev.int_sampler_2d_array;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
	BOOST_CHECK(x == ev.int_sampler_2d_array);
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	x = ev.int_sampler_2d_multisample;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
	BOOST_CHECK(x == ev.int_sampler_2d_multisample);
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	x = ev.int_sampler_2d_multisample_array;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
	BOOST_CHECK(x == ev.int_sampler_2d_multisample_array);
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_INT_SAMPLER_2D_RECT
	x = ev.int_sampler_2d_rect;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
	BOOST_CHECK(x == ev.int_sampler_2d_rect);
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_INT_SAMPLER_3D
	x = ev.int_sampler_3d;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
	BOOST_CHECK(x == ev.int_sampler_3d);
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_INT_SAMPLER_BUFFER
	x = ev.int_sampler_buffer;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
	BOOST_CHECK(x == ev.int_sampler_buffer);
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_INT_SAMPLER_CUBE
	x = ev.int_sampler_cube;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
	BOOST_CHECK(x == ev.int_sampler_cube);
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	x = ev.int_sampler_cube_map_array;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
	BOOST_CHECK(x == ev.int_sampler_cube_map_array);
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_INT_VEC2
	x = ev.int_vec2;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
	BOOST_CHECK(x == ev.int_vec2);
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_INT_VEC3
	x = ev.int_vec3;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
	BOOST_CHECK(x == ev.int_vec3);
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_INT_VEC4
	x = ev.int_vec4;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
	BOOST_CHECK(x == ev.int_vec4);
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_NONE
	x = ev.none;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
	BOOST_CHECK(x == ev.none);
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_SAMPLER_1D
	x = ev.sampler_1d;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
	BOOST_CHECK(x == ev.sampler_1d);
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_SAMPLER_1D_ARRAY
	x = ev.sampler_1d_array;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
	BOOST_CHECK(x == ev.sampler_1d_array);
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	x = ev.sampler_1d_array_shadow;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
	BOOST_CHECK(x == ev.sampler_1d_array_shadow);
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_SAMPLER_1D_SHADOW
	x = ev.sampler_1d_shadow;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
	BOOST_CHECK(x == ev.sampler_1d_shadow);
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_SAMPLER_2D
	x = ev.sampler_2d;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
	BOOST_CHECK(x == ev.sampler_2d);
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_SAMPLER_2D_ARRAY
	x = ev.sampler_2d_array;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
	BOOST_CHECK(x == ev.sampler_2d_array);
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	x = ev.sampler_2d_array_shadow;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
	BOOST_CHECK(x == ev.sampler_2d_array_shadow);
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_SAMPLER_2D_MULTISAMPLE
	x = ev.sampler_2d_multisample;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
	BOOST_CHECK(x == ev.sampler_2d_multisample);
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	x = ev.sampler_2d_multisample_array;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
	BOOST_CHECK(x == ev.sampler_2d_multisample_array);
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_SAMPLER_2D_RECT
	x = ev.sampler_2d_rect;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
	BOOST_CHECK(x == ev.sampler_2d_rect);
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_SAMPLER_2D_RECT_SHADOW
	x = ev.sampler_2d_rect_shadow;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
	BOOST_CHECK(x == ev.sampler_2d_rect_shadow);
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_SAMPLER_2D_SHADOW
	x = ev.sampler_2d_shadow;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
	BOOST_CHECK(x == ev.sampler_2d_shadow);
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_SAMPLER_3D
	x = ev.sampler_3d;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
	BOOST_CHECK(x == ev.sampler_3d);
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_SAMPLER_BUFFER
	x = ev.sampler_buffer;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
	BOOST_CHECK(x == ev.sampler_buffer);
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_SAMPLER_CUBE
	x = ev.sampler_cube;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
	BOOST_CHECK(x == ev.sampler_cube);
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	x = ev.sampler_cube_map_array;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
	BOOST_CHECK(x == ev.sampler_cube_map_array);
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	x = ev.sampler_cube_map_array_shadow;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
	BOOST_CHECK(x == ev.sampler_cube_map_array_shadow);
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_SAMPLER_CUBE_SHADOW
	x = ev.sampler_cube_shadow;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
	BOOST_CHECK(x == ev.sampler_cube_shadow);
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_UNSIGNED_INT
	x = ev.unsigned_int;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
	BOOST_CHECK(x == ev.unsigned_int);
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	x = ev.unsigned_int_atomic_counter;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
	BOOST_CHECK(x == ev.unsigned_int_atomic_counter);
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_UNSIGNED_INT_IMAGE_1D
	x = ev.unsigned_int_image_1d;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
	BOOST_CHECK(x == ev.unsigned_int_image_1d);
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	x = ev.unsigned_int_image_1d_array;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
	BOOST_CHECK(x == ev.unsigned_int_image_1d_array);
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_UNSIGNED_INT_IMAGE_2D
	x = ev.unsigned_int_image_2d;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
	BOOST_CHECK(x == ev.unsigned_int_image_2d);
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	x = ev.unsigned_int_image_2d_array;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
	BOOST_CHECK(x == ev.unsigned_int_image_2d_array);
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	x = ev.unsigned_int_image_2d_multisample;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
	BOOST_CHECK(x == ev.unsigned_int_image_2d_multisample);
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	x = ev.unsigned_int_image_2d_multisample_array;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
	BOOST_CHECK(x == ev.unsigned_int_image_2d_multisample_array);
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	x = ev.unsigned_int_image_2d_rect;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
	BOOST_CHECK(x == ev.unsigned_int_image_2d_rect);
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_UNSIGNED_INT_IMAGE_3D
	x = ev.unsigned_int_image_3d;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
	BOOST_CHECK(x == ev.unsigned_int_image_3d);
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	x = ev.unsigned_int_image_buffer;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
	BOOST_CHECK(x == ev.unsigned_int_image_buffer);
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	x = ev.unsigned_int_image_cube;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
	BOOST_CHECK(x == ev.unsigned_int_image_cube);
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_UNSIGNED_INT_SAMPLER_1D
	x = ev.unsigned_int_sampler_1d;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
	BOOST_CHECK(x == ev.unsigned_int_sampler_1d);
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	x = ev.unsigned_int_sampler_1d_array;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
	BOOST_CHECK(x == ev.unsigned_int_sampler_1d_array);
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_UNSIGNED_INT_SAMPLER_2D
	x = ev.unsigned_int_sampler_2d;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
	BOOST_CHECK(x == ev.unsigned_int_sampler_2d);
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	x = ev.unsigned_int_sampler_2d_array;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
	BOOST_CHECK(x == ev.unsigned_int_sampler_2d_array);
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	x = ev.unsigned_int_sampler_2d_multisample;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
	BOOST_CHECK(x == ev.unsigned_int_sampler_2d_multisample);
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	x = ev.unsigned_int_sampler_2d_multisample_array;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
	BOOST_CHECK(x == ev.unsigned_int_sampler_2d_multisample_array);
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	x = ev.unsigned_int_sampler_2d_rect;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
	BOOST_CHECK(x == ev.unsigned_int_sampler_2d_rect);
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_UNSIGNED_INT_SAMPLER_3D
	x = ev.unsigned_int_sampler_3d;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
	BOOST_CHECK(x == ev.unsigned_int_sampler_3d);
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	x = ev.unsigned_int_sampler_buffer;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
	BOOST_CHECK(x == ev.unsigned_int_sampler_buffer);
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	x = ev.unsigned_int_sampler_cube;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
	BOOST_CHECK(x == ev.unsigned_int_sampler_cube);
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	x = ev.unsigned_int_sampler_cube_map_array;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
	BOOST_CHECK(x == ev.unsigned_int_sampler_cube_map_array);
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_UNSIGNED_INT_VEC2
	x = ev.unsigned_int_vec2;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
	BOOST_CHECK(x == ev.unsigned_int_vec2);
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_UNSIGNED_INT_VEC3
	x = ev.unsigned_int_vec3;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
	BOOST_CHECK(x == ev.unsigned_int_vec3);
# ifdef GL_UNSIGNED_INT_VEC4
	BOOST_CHECK(x != ev.unsigned_int_vec4);
# endif
#endif

#ifdef GL_UNSIGNED_INT_VEC4
	x = ev.unsigned_int_vec4;
# ifdef GL_BOOL
	BOOST_CHECK(x != ev.bool_);
# endif
# ifdef GL_BOOL_VEC2
	BOOST_CHECK(x != ev.bool_vec2);
# endif
# ifdef GL_BOOL_VEC3
	BOOST_CHECK(x != ev.bool_vec3);
# endif
# ifdef GL_BOOL_VEC4
	BOOST_CHECK(x != ev.bool_vec4);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_DOUBLE_MAT2
	BOOST_CHECK(x != ev.double_mat2);
# endif
# ifdef GL_DOUBLE_MAT2x3
	BOOST_CHECK(x != ev.double_mat2x3);
# endif
# ifdef GL_DOUBLE_MAT2x4
	BOOST_CHECK(x != ev.double_mat2x4);
# endif
# ifdef GL_DOUBLE_MAT3
	BOOST_CHECK(x != ev.double_mat3);
# endif
# ifdef GL_DOUBLE_MAT3x2
	BOOST_CHECK(x != ev.double_mat3x2);
# endif
# ifdef GL_DOUBLE_MAT3x4
	BOOST_CHECK(x != ev.double_mat3x4);
# endif
# ifdef GL_DOUBLE_MAT4
	BOOST_CHECK(x != ev.double_mat4);
# endif
# ifdef GL_DOUBLE_MAT4x2
	BOOST_CHECK(x != ev.double_mat4x2);
# endif
# ifdef GL_DOUBLE_MAT4x3
	BOOST_CHECK(x != ev.double_mat4x3);
# endif
# ifdef GL_DOUBLE_VEC2
	BOOST_CHECK(x != ev.double_vec2);
# endif
# ifdef GL_DOUBLE_VEC3
	BOOST_CHECK(x != ev.double_vec3);
# endif
# ifdef GL_DOUBLE_VEC4
	BOOST_CHECK(x != ev.double_vec4);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_MAT2
	BOOST_CHECK(x != ev.float_mat2);
# endif
# ifdef GL_FLOAT_MAT2x3
	BOOST_CHECK(x != ev.float_mat2x3);
# endif
# ifdef GL_FLOAT_MAT2x4
	BOOST_CHECK(x != ev.float_mat2x4);
# endif
# ifdef GL_FLOAT_MAT3
	BOOST_CHECK(x != ev.float_mat3);
# endif
# ifdef GL_FLOAT_MAT3x2
	BOOST_CHECK(x != ev.float_mat3x2);
# endif
# ifdef GL_FLOAT_MAT3x4
	BOOST_CHECK(x != ev.float_mat3x4);
# endif
# ifdef GL_FLOAT_MAT4
	BOOST_CHECK(x != ev.float_mat4);
# endif
# ifdef GL_FLOAT_MAT4x2
	BOOST_CHECK(x != ev.float_mat4x2);
# endif
# ifdef GL_FLOAT_MAT4x3
	BOOST_CHECK(x != ev.float_mat4x3);
# endif
# ifdef GL_FLOAT_VEC2
	BOOST_CHECK(x != ev.float_vec2);
# endif
# ifdef GL_FLOAT_VEC3
	BOOST_CHECK(x != ev.float_vec3);
# endif
# ifdef GL_FLOAT_VEC4
	BOOST_CHECK(x != ev.float_vec4);
# endif
# ifdef GL_IMAGE_1D
	BOOST_CHECK(x != ev.image_1d);
# endif
# ifdef GL_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.image_1d_array);
# endif
# ifdef GL_IMAGE_2D
	BOOST_CHECK(x != ev.image_2d);
# endif
# ifdef GL_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.image_2d_array);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.image_2d_multisample);
# endif
# ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.image_2d_multisample_array);
# endif
# ifdef GL_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.image_2d_rect);
# endif
# ifdef GL_IMAGE_3D
	BOOST_CHECK(x != ev.image_3d);
# endif
# ifdef GL_IMAGE_BUFFER
	BOOST_CHECK(x != ev.image_buffer);
# endif
# ifdef GL_IMAGE_CUBE
	BOOST_CHECK(x != ev.image_cube);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_INT_IMAGE_1D
	BOOST_CHECK(x != ev.int_image_1d);
# endif
# ifdef GL_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.int_image_1d_array);
# endif
# ifdef GL_INT_IMAGE_2D
	BOOST_CHECK(x != ev.int_image_2d);
# endif
# ifdef GL_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_array);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_image_2d_multisample);
# endif
# ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_image_2d_multisample_array);
# endif
# ifdef GL_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.int_image_2d_rect);
# endif
# ifdef GL_INT_IMAGE_3D
	BOOST_CHECK(x != ev.int_image_3d);
# endif
# ifdef GL_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.int_image_buffer);
# endif
# ifdef GL_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.int_image_cube);
# endif
# ifdef GL_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.int_sampler_1d);
# endif
# ifdef GL_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_1d_array);
# endif
# ifdef GL_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.int_sampler_2d);
# endif
# ifdef GL_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_array);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.int_sampler_2d_multisample);
# endif
# ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.int_sampler_2d_multisample_array);
# endif
# ifdef GL_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.int_sampler_2d_rect);
# endif
# ifdef GL_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.int_sampler_3d);
# endif
# ifdef GL_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.int_sampler_buffer);
# endif
# ifdef GL_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.int_sampler_cube);
# endif
# ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.int_sampler_cube_map_array);
# endif
# ifdef GL_INT_VEC2
	BOOST_CHECK(x != ev.int_vec2);
# endif
# ifdef GL_INT_VEC3
	BOOST_CHECK(x != ev.int_vec3);
# endif
# ifdef GL_INT_VEC4
	BOOST_CHECK(x != ev.int_vec4);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_SAMPLER_1D
	BOOST_CHECK(x != ev.sampler_1d);
# endif
# ifdef GL_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.sampler_1d_array);
# endif
# ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_array_shadow);
# endif
# ifdef GL_SAMPLER_1D_SHADOW
	BOOST_CHECK(x != ev.sampler_1d_shadow);
# endif
# ifdef GL_SAMPLER_2D
	BOOST_CHECK(x != ev.sampler_2d);
# endif
# ifdef GL_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_array);
# endif
# ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_array_shadow);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.sampler_2d_multisample);
# endif
# ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.sampler_2d_multisample_array);
# endif
# ifdef GL_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.sampler_2d_rect);
# endif
# ifdef GL_SAMPLER_2D_RECT_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_rect_shadow);
# endif
# ifdef GL_SAMPLER_2D_SHADOW
	BOOST_CHECK(x != ev.sampler_2d_shadow);
# endif
# ifdef GL_SAMPLER_3D
	BOOST_CHECK(x != ev.sampler_3d);
# endif
# ifdef GL_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.sampler_buffer);
# endif
# ifdef GL_SAMPLER_CUBE
	BOOST_CHECK(x != ev.sampler_cube);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.sampler_cube_map_array);
# endif
# ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_map_array_shadow);
# endif
# ifdef GL_SAMPLER_CUBE_SHADOW
	BOOST_CHECK(x != ev.sampler_cube_shadow);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	BOOST_CHECK(x != ev.unsigned_int_atomic_counter);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D
	BOOST_CHECK(x != ev.unsigned_int_image_1d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D
	BOOST_CHECK(x != ev.unsigned_int_image_2d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_image_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_image_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_3D
	BOOST_CHECK(x != ev.unsigned_int_image_3d);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_image_buffer);
# endif
# ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	BOOST_CHECK(x != ev.unsigned_int_image_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_1d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_multisample_array);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	BOOST_CHECK(x != ev.unsigned_int_sampler_2d_rect);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_3D
	BOOST_CHECK(x != ev.unsigned_int_sampler_3d);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	BOOST_CHECK(x != ev.unsigned_int_sampler_buffer);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube);
# endif
# ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.unsigned_int_sampler_cube_map_array);
# endif
# ifdef GL_UNSIGNED_INT_VEC2
	BOOST_CHECK(x != ev.unsigned_int_vec2);
# endif
# ifdef GL_UNSIGNED_INT_VEC3
	BOOST_CHECK(x != ev.unsigned_int_vec3);
# endif
	BOOST_CHECK(x == ev.unsigned_int_vec4);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
