//  File test/oglplus/enums/binding_query.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_binding_query

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_binding_query_tests)

BOOST_AUTO_TEST_CASE(enum_binding_query_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	binding_query x;
	(void)x;

#ifdef GL_ARRAY_BUFFER_BINDING
	x = ev.array_buffer_binding;
	BOOST_CHECK(x == ev.array_buffer_binding);
# ifdef GL_ATOMIC_COUNTER_BUFFER_BINDING
	BOOST_CHECK(x != ev.atomic_counter_buffer_binding);
# endif
# ifdef GL_BUFFER_BINDING
	BOOST_CHECK(x != ev.buffer_binding);
# endif
# ifdef GL_COPY_READ_BUFFER_BINDING
	BOOST_CHECK(x != ev.copy_read_buffer_binding);
# endif
# ifdef GL_COPY_WRITE_BUFFER_BINDING
	BOOST_CHECK(x != ev.copy_write_buffer_binding);
# endif
# ifdef GL_CURRENT_PROGRAM
	BOOST_CHECK(x != ev.current_program);
# endif
# ifdef GL_DISPATCH_INDIRECT_BUFFER_BINDING
	BOOST_CHECK(x != ev.dispatch_indirect_buffer_binding);
# endif
# ifdef GL_DRAW_FRAMEBUFFER_BINDING
	BOOST_CHECK(x != ev.draw_framebuffer_binding);
# endif
# ifdef GL_DRAW_INDIRECT_BUFFER_BINDING
	BOOST_CHECK(x != ev.draw_indirect_buffer_binding);
# endif
# ifdef GL_ELEMENT_ARRAY_BUFFER_BINDING
	BOOST_CHECK(x != ev.element_array_buffer_binding);
# endif
# ifdef GL_PARAMETER_BUFFER_BINDING_ARB
	BOOST_CHECK(x != ev.parameter_buffer_binding);
# endif
# ifdef GL_PIXEL_PACK_BUFFER_BINDING
	BOOST_CHECK(x != ev.pixel_pack_buffer_binding);
# endif
# ifdef GL_PIXEL_UNPACK_BUFFER_BINDING
	BOOST_CHECK(x != ev.pixel_unpack_buffer_binding);
# endif
# ifdef GL_QUERY_BUFFER_BINDING
	BOOST_CHECK(x != ev.query_buffer_binding);
# endif
# ifdef GL_RENDERBUFFER_BINDING
	BOOST_CHECK(x != ev.renderbuffer_binding);
# endif
# ifdef GL_SAMPLER_BINDING
	BOOST_CHECK(x != ev.sampler_binding);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_BINDING
	BOOST_CHECK(x != ev.shader_storage_buffer_binding);
# endif
# ifdef GL_TEXTURE_BINDING_1D
	BOOST_CHECK(x != ev.texture_binding_1d);
# endif
# ifdef GL_TEXTURE_BINDING_1D_ARRAY
	BOOST_CHECK(x != ev.texture_binding_1d_array);
# endif
# ifdef GL_TEXTURE_BINDING_2D
	BOOST_CHECK(x != ev.texture_binding_2d);
# endif
# ifdef GL_TEXTURE_BINDING_2D_ARRAY
	BOOST_CHECK(x != ev.texture_binding_2d_array);
# endif
# ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.texture_binding_2d_multisample);
# endif
# ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.texture_binding_2d_multisample_array);
# endif
# ifdef GL_TEXTURE_BINDING_3D
	BOOST_CHECK(x != ev.texture_binding_3d);
# endif
# ifdef GL_TEXTURE_BINDING_BUFFER
	BOOST_CHECK(x != ev.texture_binding_buffer);
# endif
# ifdef GL_TEXTURE_BINDING_CUBE_MAP
	BOOST_CHECK(x != ev.texture_binding_cube_map);
# endif
# ifdef GL_TEXTURE_BINDING_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.texture_binding_cube_map_array);
# endif
# ifdef GL_TEXTURE_BINDING_RECTANGLE
	BOOST_CHECK(x != ev.texture_binding_rectangle);
# endif
# ifdef GL_TEXTURE_BUFFER_BINDING
	BOOST_CHECK(x != ev.texture_buffer_binding);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BINDING
	BOOST_CHECK(x != ev.transform_feedback_binding);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_BINDING
	BOOST_CHECK(x != ev.transform_feedback_buffer_binding);
# endif
# ifdef GL_UNIFORM_BUFFER_BINDING
	BOOST_CHECK(x != ev.uniform_buffer_binding);
# endif
# ifdef GL_VERTEX_ARRAY_BINDING
	BOOST_CHECK(x != ev.vertex_array_binding);
# endif
#endif

#ifdef GL_ATOMIC_COUNTER_BUFFER_BINDING
	x = ev.atomic_counter_buffer_binding;
	BOOST_CHECK(x == ev.atomic_counter_buffer_binding);
# ifdef GL_BUFFER_BINDING
	BOOST_CHECK(x != ev.buffer_binding);
# endif
# ifdef GL_COPY_READ_BUFFER_BINDING
	BOOST_CHECK(x != ev.copy_read_buffer_binding);
# endif
# ifdef GL_COPY_WRITE_BUFFER_BINDING
	BOOST_CHECK(x != ev.copy_write_buffer_binding);
# endif
# ifdef GL_CURRENT_PROGRAM
	BOOST_CHECK(x != ev.current_program);
# endif
# ifdef GL_DISPATCH_INDIRECT_BUFFER_BINDING
	BOOST_CHECK(x != ev.dispatch_indirect_buffer_binding);
# endif
# ifdef GL_DRAW_FRAMEBUFFER_BINDING
	BOOST_CHECK(x != ev.draw_framebuffer_binding);
# endif
# ifdef GL_DRAW_INDIRECT_BUFFER_BINDING
	BOOST_CHECK(x != ev.draw_indirect_buffer_binding);
# endif
# ifdef GL_ELEMENT_ARRAY_BUFFER_BINDING
	BOOST_CHECK(x != ev.element_array_buffer_binding);
# endif
# ifdef GL_PARAMETER_BUFFER_BINDING_ARB
	BOOST_CHECK(x != ev.parameter_buffer_binding);
# endif
# ifdef GL_PIXEL_PACK_BUFFER_BINDING
	BOOST_CHECK(x != ev.pixel_pack_buffer_binding);
# endif
# ifdef GL_PIXEL_UNPACK_BUFFER_BINDING
	BOOST_CHECK(x != ev.pixel_unpack_buffer_binding);
# endif
# ifdef GL_QUERY_BUFFER_BINDING
	BOOST_CHECK(x != ev.query_buffer_binding);
# endif
# ifdef GL_RENDERBUFFER_BINDING
	BOOST_CHECK(x != ev.renderbuffer_binding);
# endif
# ifdef GL_SAMPLER_BINDING
	BOOST_CHECK(x != ev.sampler_binding);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_BINDING
	BOOST_CHECK(x != ev.shader_storage_buffer_binding);
# endif
# ifdef GL_TEXTURE_BINDING_1D
	BOOST_CHECK(x != ev.texture_binding_1d);
# endif
# ifdef GL_TEXTURE_BINDING_1D_ARRAY
	BOOST_CHECK(x != ev.texture_binding_1d_array);
# endif
# ifdef GL_TEXTURE_BINDING_2D
	BOOST_CHECK(x != ev.texture_binding_2d);
# endif
# ifdef GL_TEXTURE_BINDING_2D_ARRAY
	BOOST_CHECK(x != ev.texture_binding_2d_array);
# endif
# ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.texture_binding_2d_multisample);
# endif
# ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.texture_binding_2d_multisample_array);
# endif
# ifdef GL_TEXTURE_BINDING_3D
	BOOST_CHECK(x != ev.texture_binding_3d);
# endif
# ifdef GL_TEXTURE_BINDING_BUFFER
	BOOST_CHECK(x != ev.texture_binding_buffer);
# endif
# ifdef GL_TEXTURE_BINDING_CUBE_MAP
	BOOST_CHECK(x != ev.texture_binding_cube_map);
# endif
# ifdef GL_TEXTURE_BINDING_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.texture_binding_cube_map_array);
# endif
# ifdef GL_TEXTURE_BINDING_RECTANGLE
	BOOST_CHECK(x != ev.texture_binding_rectangle);
# endif
# ifdef GL_TEXTURE_BUFFER_BINDING
	BOOST_CHECK(x != ev.texture_buffer_binding);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BINDING
	BOOST_CHECK(x != ev.transform_feedback_binding);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_BINDING
	BOOST_CHECK(x != ev.transform_feedback_buffer_binding);
# endif
# ifdef GL_UNIFORM_BUFFER_BINDING
	BOOST_CHECK(x != ev.uniform_buffer_binding);
# endif
# ifdef GL_VERTEX_ARRAY_BINDING
	BOOST_CHECK(x != ev.vertex_array_binding);
# endif
#endif

#ifdef GL_BUFFER_BINDING
	x = ev.buffer_binding;
	BOOST_CHECK(x == ev.buffer_binding);
# ifdef GL_COPY_READ_BUFFER_BINDING
	BOOST_CHECK(x != ev.copy_read_buffer_binding);
# endif
# ifdef GL_COPY_WRITE_BUFFER_BINDING
	BOOST_CHECK(x != ev.copy_write_buffer_binding);
# endif
# ifdef GL_CURRENT_PROGRAM
	BOOST_CHECK(x != ev.current_program);
# endif
# ifdef GL_DISPATCH_INDIRECT_BUFFER_BINDING
	BOOST_CHECK(x != ev.dispatch_indirect_buffer_binding);
# endif
# ifdef GL_DRAW_FRAMEBUFFER_BINDING
	BOOST_CHECK(x != ev.draw_framebuffer_binding);
# endif
# ifdef GL_DRAW_INDIRECT_BUFFER_BINDING
	BOOST_CHECK(x != ev.draw_indirect_buffer_binding);
# endif
# ifdef GL_ELEMENT_ARRAY_BUFFER_BINDING
	BOOST_CHECK(x != ev.element_array_buffer_binding);
# endif
# ifdef GL_PARAMETER_BUFFER_BINDING_ARB
	BOOST_CHECK(x != ev.parameter_buffer_binding);
# endif
# ifdef GL_PIXEL_PACK_BUFFER_BINDING
	BOOST_CHECK(x != ev.pixel_pack_buffer_binding);
# endif
# ifdef GL_PIXEL_UNPACK_BUFFER_BINDING
	BOOST_CHECK(x != ev.pixel_unpack_buffer_binding);
# endif
# ifdef GL_QUERY_BUFFER_BINDING
	BOOST_CHECK(x != ev.query_buffer_binding);
# endif
# ifdef GL_RENDERBUFFER_BINDING
	BOOST_CHECK(x != ev.renderbuffer_binding);
# endif
# ifdef GL_SAMPLER_BINDING
	BOOST_CHECK(x != ev.sampler_binding);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_BINDING
	BOOST_CHECK(x != ev.shader_storage_buffer_binding);
# endif
# ifdef GL_TEXTURE_BINDING_1D
	BOOST_CHECK(x != ev.texture_binding_1d);
# endif
# ifdef GL_TEXTURE_BINDING_1D_ARRAY
	BOOST_CHECK(x != ev.texture_binding_1d_array);
# endif
# ifdef GL_TEXTURE_BINDING_2D
	BOOST_CHECK(x != ev.texture_binding_2d);
# endif
# ifdef GL_TEXTURE_BINDING_2D_ARRAY
	BOOST_CHECK(x != ev.texture_binding_2d_array);
# endif
# ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.texture_binding_2d_multisample);
# endif
# ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.texture_binding_2d_multisample_array);
# endif
# ifdef GL_TEXTURE_BINDING_3D
	BOOST_CHECK(x != ev.texture_binding_3d);
# endif
# ifdef GL_TEXTURE_BINDING_BUFFER
	BOOST_CHECK(x != ev.texture_binding_buffer);
# endif
# ifdef GL_TEXTURE_BINDING_CUBE_MAP
	BOOST_CHECK(x != ev.texture_binding_cube_map);
# endif
# ifdef GL_TEXTURE_BINDING_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.texture_binding_cube_map_array);
# endif
# ifdef GL_TEXTURE_BINDING_RECTANGLE
	BOOST_CHECK(x != ev.texture_binding_rectangle);
# endif
# ifdef GL_TEXTURE_BUFFER_BINDING
	BOOST_CHECK(x != ev.texture_buffer_binding);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BINDING
	BOOST_CHECK(x != ev.transform_feedback_binding);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_BINDING
	BOOST_CHECK(x != ev.transform_feedback_buffer_binding);
# endif
# ifdef GL_UNIFORM_BUFFER_BINDING
	BOOST_CHECK(x != ev.uniform_buffer_binding);
# endif
# ifdef GL_VERTEX_ARRAY_BINDING
	BOOST_CHECK(x != ev.vertex_array_binding);
# endif
#endif

#ifdef GL_COPY_READ_BUFFER_BINDING
	x = ev.copy_read_buffer_binding;
	BOOST_CHECK(x == ev.copy_read_buffer_binding);
# ifdef GL_COPY_WRITE_BUFFER_BINDING
	BOOST_CHECK(x != ev.copy_write_buffer_binding);
# endif
# ifdef GL_CURRENT_PROGRAM
	BOOST_CHECK(x != ev.current_program);
# endif
# ifdef GL_DISPATCH_INDIRECT_BUFFER_BINDING
	BOOST_CHECK(x != ev.dispatch_indirect_buffer_binding);
# endif
# ifdef GL_DRAW_FRAMEBUFFER_BINDING
	BOOST_CHECK(x != ev.draw_framebuffer_binding);
# endif
# ifdef GL_DRAW_INDIRECT_BUFFER_BINDING
	BOOST_CHECK(x != ev.draw_indirect_buffer_binding);
# endif
# ifdef GL_ELEMENT_ARRAY_BUFFER_BINDING
	BOOST_CHECK(x != ev.element_array_buffer_binding);
# endif
# ifdef GL_PARAMETER_BUFFER_BINDING_ARB
	BOOST_CHECK(x != ev.parameter_buffer_binding);
# endif
# ifdef GL_PIXEL_PACK_BUFFER_BINDING
	BOOST_CHECK(x != ev.pixel_pack_buffer_binding);
# endif
# ifdef GL_PIXEL_UNPACK_BUFFER_BINDING
	BOOST_CHECK(x != ev.pixel_unpack_buffer_binding);
# endif
# ifdef GL_QUERY_BUFFER_BINDING
	BOOST_CHECK(x != ev.query_buffer_binding);
# endif
# ifdef GL_RENDERBUFFER_BINDING
	BOOST_CHECK(x != ev.renderbuffer_binding);
# endif
# ifdef GL_SAMPLER_BINDING
	BOOST_CHECK(x != ev.sampler_binding);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_BINDING
	BOOST_CHECK(x != ev.shader_storage_buffer_binding);
# endif
# ifdef GL_TEXTURE_BINDING_1D
	BOOST_CHECK(x != ev.texture_binding_1d);
# endif
# ifdef GL_TEXTURE_BINDING_1D_ARRAY
	BOOST_CHECK(x != ev.texture_binding_1d_array);
# endif
# ifdef GL_TEXTURE_BINDING_2D
	BOOST_CHECK(x != ev.texture_binding_2d);
# endif
# ifdef GL_TEXTURE_BINDING_2D_ARRAY
	BOOST_CHECK(x != ev.texture_binding_2d_array);
# endif
# ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.texture_binding_2d_multisample);
# endif
# ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.texture_binding_2d_multisample_array);
# endif
# ifdef GL_TEXTURE_BINDING_3D
	BOOST_CHECK(x != ev.texture_binding_3d);
# endif
# ifdef GL_TEXTURE_BINDING_BUFFER
	BOOST_CHECK(x != ev.texture_binding_buffer);
# endif
# ifdef GL_TEXTURE_BINDING_CUBE_MAP
	BOOST_CHECK(x != ev.texture_binding_cube_map);
# endif
# ifdef GL_TEXTURE_BINDING_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.texture_binding_cube_map_array);
# endif
# ifdef GL_TEXTURE_BINDING_RECTANGLE
	BOOST_CHECK(x != ev.texture_binding_rectangle);
# endif
# ifdef GL_TEXTURE_BUFFER_BINDING
	BOOST_CHECK(x != ev.texture_buffer_binding);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BINDING
	BOOST_CHECK(x != ev.transform_feedback_binding);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_BINDING
	BOOST_CHECK(x != ev.transform_feedback_buffer_binding);
# endif
# ifdef GL_UNIFORM_BUFFER_BINDING
	BOOST_CHECK(x != ev.uniform_buffer_binding);
# endif
# ifdef GL_VERTEX_ARRAY_BINDING
	BOOST_CHECK(x != ev.vertex_array_binding);
# endif
#endif

#ifdef GL_COPY_WRITE_BUFFER_BINDING
	x = ev.copy_write_buffer_binding;
	BOOST_CHECK(x == ev.copy_write_buffer_binding);
# ifdef GL_CURRENT_PROGRAM
	BOOST_CHECK(x != ev.current_program);
# endif
# ifdef GL_DISPATCH_INDIRECT_BUFFER_BINDING
	BOOST_CHECK(x != ev.dispatch_indirect_buffer_binding);
# endif
# ifdef GL_DRAW_FRAMEBUFFER_BINDING
	BOOST_CHECK(x != ev.draw_framebuffer_binding);
# endif
# ifdef GL_DRAW_INDIRECT_BUFFER_BINDING
	BOOST_CHECK(x != ev.draw_indirect_buffer_binding);
# endif
# ifdef GL_ELEMENT_ARRAY_BUFFER_BINDING
	BOOST_CHECK(x != ev.element_array_buffer_binding);
# endif
# ifdef GL_PARAMETER_BUFFER_BINDING_ARB
	BOOST_CHECK(x != ev.parameter_buffer_binding);
# endif
# ifdef GL_PIXEL_PACK_BUFFER_BINDING
	BOOST_CHECK(x != ev.pixel_pack_buffer_binding);
# endif
# ifdef GL_PIXEL_UNPACK_BUFFER_BINDING
	BOOST_CHECK(x != ev.pixel_unpack_buffer_binding);
# endif
# ifdef GL_QUERY_BUFFER_BINDING
	BOOST_CHECK(x != ev.query_buffer_binding);
# endif
# ifdef GL_RENDERBUFFER_BINDING
	BOOST_CHECK(x != ev.renderbuffer_binding);
# endif
# ifdef GL_SAMPLER_BINDING
	BOOST_CHECK(x != ev.sampler_binding);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_BINDING
	BOOST_CHECK(x != ev.shader_storage_buffer_binding);
# endif
# ifdef GL_TEXTURE_BINDING_1D
	BOOST_CHECK(x != ev.texture_binding_1d);
# endif
# ifdef GL_TEXTURE_BINDING_1D_ARRAY
	BOOST_CHECK(x != ev.texture_binding_1d_array);
# endif
# ifdef GL_TEXTURE_BINDING_2D
	BOOST_CHECK(x != ev.texture_binding_2d);
# endif
# ifdef GL_TEXTURE_BINDING_2D_ARRAY
	BOOST_CHECK(x != ev.texture_binding_2d_array);
# endif
# ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.texture_binding_2d_multisample);
# endif
# ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.texture_binding_2d_multisample_array);
# endif
# ifdef GL_TEXTURE_BINDING_3D
	BOOST_CHECK(x != ev.texture_binding_3d);
# endif
# ifdef GL_TEXTURE_BINDING_BUFFER
	BOOST_CHECK(x != ev.texture_binding_buffer);
# endif
# ifdef GL_TEXTURE_BINDING_CUBE_MAP
	BOOST_CHECK(x != ev.texture_binding_cube_map);
# endif
# ifdef GL_TEXTURE_BINDING_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.texture_binding_cube_map_array);
# endif
# ifdef GL_TEXTURE_BINDING_RECTANGLE
	BOOST_CHECK(x != ev.texture_binding_rectangle);
# endif
# ifdef GL_TEXTURE_BUFFER_BINDING
	BOOST_CHECK(x != ev.texture_buffer_binding);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BINDING
	BOOST_CHECK(x != ev.transform_feedback_binding);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_BINDING
	BOOST_CHECK(x != ev.transform_feedback_buffer_binding);
# endif
# ifdef GL_UNIFORM_BUFFER_BINDING
	BOOST_CHECK(x != ev.uniform_buffer_binding);
# endif
# ifdef GL_VERTEX_ARRAY_BINDING
	BOOST_CHECK(x != ev.vertex_array_binding);
# endif
#endif

#ifdef GL_CURRENT_PROGRAM
	x = ev.current_program;
	BOOST_CHECK(x == ev.current_program);
# ifdef GL_DISPATCH_INDIRECT_BUFFER_BINDING
	BOOST_CHECK(x != ev.dispatch_indirect_buffer_binding);
# endif
# ifdef GL_DRAW_FRAMEBUFFER_BINDING
	BOOST_CHECK(x != ev.draw_framebuffer_binding);
# endif
# ifdef GL_DRAW_INDIRECT_BUFFER_BINDING
	BOOST_CHECK(x != ev.draw_indirect_buffer_binding);
# endif
# ifdef GL_ELEMENT_ARRAY_BUFFER_BINDING
	BOOST_CHECK(x != ev.element_array_buffer_binding);
# endif
# ifdef GL_PARAMETER_BUFFER_BINDING_ARB
	BOOST_CHECK(x != ev.parameter_buffer_binding);
# endif
# ifdef GL_PIXEL_PACK_BUFFER_BINDING
	BOOST_CHECK(x != ev.pixel_pack_buffer_binding);
# endif
# ifdef GL_PIXEL_UNPACK_BUFFER_BINDING
	BOOST_CHECK(x != ev.pixel_unpack_buffer_binding);
# endif
# ifdef GL_QUERY_BUFFER_BINDING
	BOOST_CHECK(x != ev.query_buffer_binding);
# endif
# ifdef GL_RENDERBUFFER_BINDING
	BOOST_CHECK(x != ev.renderbuffer_binding);
# endif
# ifdef GL_SAMPLER_BINDING
	BOOST_CHECK(x != ev.sampler_binding);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_BINDING
	BOOST_CHECK(x != ev.shader_storage_buffer_binding);
# endif
# ifdef GL_TEXTURE_BINDING_1D
	BOOST_CHECK(x != ev.texture_binding_1d);
# endif
# ifdef GL_TEXTURE_BINDING_1D_ARRAY
	BOOST_CHECK(x != ev.texture_binding_1d_array);
# endif
# ifdef GL_TEXTURE_BINDING_2D
	BOOST_CHECK(x != ev.texture_binding_2d);
# endif
# ifdef GL_TEXTURE_BINDING_2D_ARRAY
	BOOST_CHECK(x != ev.texture_binding_2d_array);
# endif
# ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.texture_binding_2d_multisample);
# endif
# ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.texture_binding_2d_multisample_array);
# endif
# ifdef GL_TEXTURE_BINDING_3D
	BOOST_CHECK(x != ev.texture_binding_3d);
# endif
# ifdef GL_TEXTURE_BINDING_BUFFER
	BOOST_CHECK(x != ev.texture_binding_buffer);
# endif
# ifdef GL_TEXTURE_BINDING_CUBE_MAP
	BOOST_CHECK(x != ev.texture_binding_cube_map);
# endif
# ifdef GL_TEXTURE_BINDING_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.texture_binding_cube_map_array);
# endif
# ifdef GL_TEXTURE_BINDING_RECTANGLE
	BOOST_CHECK(x != ev.texture_binding_rectangle);
# endif
# ifdef GL_TEXTURE_BUFFER_BINDING
	BOOST_CHECK(x != ev.texture_buffer_binding);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BINDING
	BOOST_CHECK(x != ev.transform_feedback_binding);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_BINDING
	BOOST_CHECK(x != ev.transform_feedback_buffer_binding);
# endif
# ifdef GL_UNIFORM_BUFFER_BINDING
	BOOST_CHECK(x != ev.uniform_buffer_binding);
# endif
# ifdef GL_VERTEX_ARRAY_BINDING
	BOOST_CHECK(x != ev.vertex_array_binding);
# endif
#endif

#ifdef GL_DISPATCH_INDIRECT_BUFFER_BINDING
	x = ev.dispatch_indirect_buffer_binding;
	BOOST_CHECK(x == ev.dispatch_indirect_buffer_binding);
# ifdef GL_DRAW_FRAMEBUFFER_BINDING
	BOOST_CHECK(x != ev.draw_framebuffer_binding);
# endif
# ifdef GL_DRAW_INDIRECT_BUFFER_BINDING
	BOOST_CHECK(x != ev.draw_indirect_buffer_binding);
# endif
# ifdef GL_ELEMENT_ARRAY_BUFFER_BINDING
	BOOST_CHECK(x != ev.element_array_buffer_binding);
# endif
# ifdef GL_PARAMETER_BUFFER_BINDING_ARB
	BOOST_CHECK(x != ev.parameter_buffer_binding);
# endif
# ifdef GL_PIXEL_PACK_BUFFER_BINDING
	BOOST_CHECK(x != ev.pixel_pack_buffer_binding);
# endif
# ifdef GL_PIXEL_UNPACK_BUFFER_BINDING
	BOOST_CHECK(x != ev.pixel_unpack_buffer_binding);
# endif
# ifdef GL_QUERY_BUFFER_BINDING
	BOOST_CHECK(x != ev.query_buffer_binding);
# endif
# ifdef GL_RENDERBUFFER_BINDING
	BOOST_CHECK(x != ev.renderbuffer_binding);
# endif
# ifdef GL_SAMPLER_BINDING
	BOOST_CHECK(x != ev.sampler_binding);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_BINDING
	BOOST_CHECK(x != ev.shader_storage_buffer_binding);
# endif
# ifdef GL_TEXTURE_BINDING_1D
	BOOST_CHECK(x != ev.texture_binding_1d);
# endif
# ifdef GL_TEXTURE_BINDING_1D_ARRAY
	BOOST_CHECK(x != ev.texture_binding_1d_array);
# endif
# ifdef GL_TEXTURE_BINDING_2D
	BOOST_CHECK(x != ev.texture_binding_2d);
# endif
# ifdef GL_TEXTURE_BINDING_2D_ARRAY
	BOOST_CHECK(x != ev.texture_binding_2d_array);
# endif
# ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.texture_binding_2d_multisample);
# endif
# ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.texture_binding_2d_multisample_array);
# endif
# ifdef GL_TEXTURE_BINDING_3D
	BOOST_CHECK(x != ev.texture_binding_3d);
# endif
# ifdef GL_TEXTURE_BINDING_BUFFER
	BOOST_CHECK(x != ev.texture_binding_buffer);
# endif
# ifdef GL_TEXTURE_BINDING_CUBE_MAP
	BOOST_CHECK(x != ev.texture_binding_cube_map);
# endif
# ifdef GL_TEXTURE_BINDING_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.texture_binding_cube_map_array);
# endif
# ifdef GL_TEXTURE_BINDING_RECTANGLE
	BOOST_CHECK(x != ev.texture_binding_rectangle);
# endif
# ifdef GL_TEXTURE_BUFFER_BINDING
	BOOST_CHECK(x != ev.texture_buffer_binding);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BINDING
	BOOST_CHECK(x != ev.transform_feedback_binding);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_BINDING
	BOOST_CHECK(x != ev.transform_feedback_buffer_binding);
# endif
# ifdef GL_UNIFORM_BUFFER_BINDING
	BOOST_CHECK(x != ev.uniform_buffer_binding);
# endif
# ifdef GL_VERTEX_ARRAY_BINDING
	BOOST_CHECK(x != ev.vertex_array_binding);
# endif
#endif

#ifdef GL_DRAW_FRAMEBUFFER_BINDING
	x = ev.draw_framebuffer_binding;
	BOOST_CHECK(x == ev.draw_framebuffer_binding);
# ifdef GL_DRAW_INDIRECT_BUFFER_BINDING
	BOOST_CHECK(x != ev.draw_indirect_buffer_binding);
# endif
# ifdef GL_ELEMENT_ARRAY_BUFFER_BINDING
	BOOST_CHECK(x != ev.element_array_buffer_binding);
# endif
# ifdef GL_PARAMETER_BUFFER_BINDING_ARB
	BOOST_CHECK(x != ev.parameter_buffer_binding);
# endif
# ifdef GL_PIXEL_PACK_BUFFER_BINDING
	BOOST_CHECK(x != ev.pixel_pack_buffer_binding);
# endif
# ifdef GL_PIXEL_UNPACK_BUFFER_BINDING
	BOOST_CHECK(x != ev.pixel_unpack_buffer_binding);
# endif
# ifdef GL_QUERY_BUFFER_BINDING
	BOOST_CHECK(x != ev.query_buffer_binding);
# endif
# ifdef GL_RENDERBUFFER_BINDING
	BOOST_CHECK(x != ev.renderbuffer_binding);
# endif
# ifdef GL_SAMPLER_BINDING
	BOOST_CHECK(x != ev.sampler_binding);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_BINDING
	BOOST_CHECK(x != ev.shader_storage_buffer_binding);
# endif
# ifdef GL_TEXTURE_BINDING_1D
	BOOST_CHECK(x != ev.texture_binding_1d);
# endif
# ifdef GL_TEXTURE_BINDING_1D_ARRAY
	BOOST_CHECK(x != ev.texture_binding_1d_array);
# endif
# ifdef GL_TEXTURE_BINDING_2D
	BOOST_CHECK(x != ev.texture_binding_2d);
# endif
# ifdef GL_TEXTURE_BINDING_2D_ARRAY
	BOOST_CHECK(x != ev.texture_binding_2d_array);
# endif
# ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.texture_binding_2d_multisample);
# endif
# ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.texture_binding_2d_multisample_array);
# endif
# ifdef GL_TEXTURE_BINDING_3D
	BOOST_CHECK(x != ev.texture_binding_3d);
# endif
# ifdef GL_TEXTURE_BINDING_BUFFER
	BOOST_CHECK(x != ev.texture_binding_buffer);
# endif
# ifdef GL_TEXTURE_BINDING_CUBE_MAP
	BOOST_CHECK(x != ev.texture_binding_cube_map);
# endif
# ifdef GL_TEXTURE_BINDING_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.texture_binding_cube_map_array);
# endif
# ifdef GL_TEXTURE_BINDING_RECTANGLE
	BOOST_CHECK(x != ev.texture_binding_rectangle);
# endif
# ifdef GL_TEXTURE_BUFFER_BINDING
	BOOST_CHECK(x != ev.texture_buffer_binding);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BINDING
	BOOST_CHECK(x != ev.transform_feedback_binding);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_BINDING
	BOOST_CHECK(x != ev.transform_feedback_buffer_binding);
# endif
# ifdef GL_UNIFORM_BUFFER_BINDING
	BOOST_CHECK(x != ev.uniform_buffer_binding);
# endif
# ifdef GL_VERTEX_ARRAY_BINDING
	BOOST_CHECK(x != ev.vertex_array_binding);
# endif
#endif

#ifdef GL_DRAW_INDIRECT_BUFFER_BINDING
	x = ev.draw_indirect_buffer_binding;
	BOOST_CHECK(x == ev.draw_indirect_buffer_binding);
# ifdef GL_ELEMENT_ARRAY_BUFFER_BINDING
	BOOST_CHECK(x != ev.element_array_buffer_binding);
# endif
# ifdef GL_PARAMETER_BUFFER_BINDING_ARB
	BOOST_CHECK(x != ev.parameter_buffer_binding);
# endif
# ifdef GL_PIXEL_PACK_BUFFER_BINDING
	BOOST_CHECK(x != ev.pixel_pack_buffer_binding);
# endif
# ifdef GL_PIXEL_UNPACK_BUFFER_BINDING
	BOOST_CHECK(x != ev.pixel_unpack_buffer_binding);
# endif
# ifdef GL_QUERY_BUFFER_BINDING
	BOOST_CHECK(x != ev.query_buffer_binding);
# endif
# ifdef GL_RENDERBUFFER_BINDING
	BOOST_CHECK(x != ev.renderbuffer_binding);
# endif
# ifdef GL_SAMPLER_BINDING
	BOOST_CHECK(x != ev.sampler_binding);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_BINDING
	BOOST_CHECK(x != ev.shader_storage_buffer_binding);
# endif
# ifdef GL_TEXTURE_BINDING_1D
	BOOST_CHECK(x != ev.texture_binding_1d);
# endif
# ifdef GL_TEXTURE_BINDING_1D_ARRAY
	BOOST_CHECK(x != ev.texture_binding_1d_array);
# endif
# ifdef GL_TEXTURE_BINDING_2D
	BOOST_CHECK(x != ev.texture_binding_2d);
# endif
# ifdef GL_TEXTURE_BINDING_2D_ARRAY
	BOOST_CHECK(x != ev.texture_binding_2d_array);
# endif
# ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.texture_binding_2d_multisample);
# endif
# ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.texture_binding_2d_multisample_array);
# endif
# ifdef GL_TEXTURE_BINDING_3D
	BOOST_CHECK(x != ev.texture_binding_3d);
# endif
# ifdef GL_TEXTURE_BINDING_BUFFER
	BOOST_CHECK(x != ev.texture_binding_buffer);
# endif
# ifdef GL_TEXTURE_BINDING_CUBE_MAP
	BOOST_CHECK(x != ev.texture_binding_cube_map);
# endif
# ifdef GL_TEXTURE_BINDING_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.texture_binding_cube_map_array);
# endif
# ifdef GL_TEXTURE_BINDING_RECTANGLE
	BOOST_CHECK(x != ev.texture_binding_rectangle);
# endif
# ifdef GL_TEXTURE_BUFFER_BINDING
	BOOST_CHECK(x != ev.texture_buffer_binding);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BINDING
	BOOST_CHECK(x != ev.transform_feedback_binding);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_BINDING
	BOOST_CHECK(x != ev.transform_feedback_buffer_binding);
# endif
# ifdef GL_UNIFORM_BUFFER_BINDING
	BOOST_CHECK(x != ev.uniform_buffer_binding);
# endif
# ifdef GL_VERTEX_ARRAY_BINDING
	BOOST_CHECK(x != ev.vertex_array_binding);
# endif
#endif

#ifdef GL_ELEMENT_ARRAY_BUFFER_BINDING
	x = ev.element_array_buffer_binding;
	BOOST_CHECK(x == ev.element_array_buffer_binding);
# ifdef GL_PARAMETER_BUFFER_BINDING_ARB
	BOOST_CHECK(x != ev.parameter_buffer_binding);
# endif
# ifdef GL_PIXEL_PACK_BUFFER_BINDING
	BOOST_CHECK(x != ev.pixel_pack_buffer_binding);
# endif
# ifdef GL_PIXEL_UNPACK_BUFFER_BINDING
	BOOST_CHECK(x != ev.pixel_unpack_buffer_binding);
# endif
# ifdef GL_QUERY_BUFFER_BINDING
	BOOST_CHECK(x != ev.query_buffer_binding);
# endif
# ifdef GL_RENDERBUFFER_BINDING
	BOOST_CHECK(x != ev.renderbuffer_binding);
# endif
# ifdef GL_SAMPLER_BINDING
	BOOST_CHECK(x != ev.sampler_binding);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_BINDING
	BOOST_CHECK(x != ev.shader_storage_buffer_binding);
# endif
# ifdef GL_TEXTURE_BINDING_1D
	BOOST_CHECK(x != ev.texture_binding_1d);
# endif
# ifdef GL_TEXTURE_BINDING_1D_ARRAY
	BOOST_CHECK(x != ev.texture_binding_1d_array);
# endif
# ifdef GL_TEXTURE_BINDING_2D
	BOOST_CHECK(x != ev.texture_binding_2d);
# endif
# ifdef GL_TEXTURE_BINDING_2D_ARRAY
	BOOST_CHECK(x != ev.texture_binding_2d_array);
# endif
# ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.texture_binding_2d_multisample);
# endif
# ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.texture_binding_2d_multisample_array);
# endif
# ifdef GL_TEXTURE_BINDING_3D
	BOOST_CHECK(x != ev.texture_binding_3d);
# endif
# ifdef GL_TEXTURE_BINDING_BUFFER
	BOOST_CHECK(x != ev.texture_binding_buffer);
# endif
# ifdef GL_TEXTURE_BINDING_CUBE_MAP
	BOOST_CHECK(x != ev.texture_binding_cube_map);
# endif
# ifdef GL_TEXTURE_BINDING_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.texture_binding_cube_map_array);
# endif
# ifdef GL_TEXTURE_BINDING_RECTANGLE
	BOOST_CHECK(x != ev.texture_binding_rectangle);
# endif
# ifdef GL_TEXTURE_BUFFER_BINDING
	BOOST_CHECK(x != ev.texture_buffer_binding);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BINDING
	BOOST_CHECK(x != ev.transform_feedback_binding);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_BINDING
	BOOST_CHECK(x != ev.transform_feedback_buffer_binding);
# endif
# ifdef GL_UNIFORM_BUFFER_BINDING
	BOOST_CHECK(x != ev.uniform_buffer_binding);
# endif
# ifdef GL_VERTEX_ARRAY_BINDING
	BOOST_CHECK(x != ev.vertex_array_binding);
# endif
#endif

#ifdef GL_PARAMETER_BUFFER_BINDING_ARB
	x = ev.parameter_buffer_binding;
	BOOST_CHECK(x == ev.parameter_buffer_binding);
# ifdef GL_PIXEL_PACK_BUFFER_BINDING
	BOOST_CHECK(x != ev.pixel_pack_buffer_binding);
# endif
# ifdef GL_PIXEL_UNPACK_BUFFER_BINDING
	BOOST_CHECK(x != ev.pixel_unpack_buffer_binding);
# endif
# ifdef GL_QUERY_BUFFER_BINDING
	BOOST_CHECK(x != ev.query_buffer_binding);
# endif
# ifdef GL_RENDERBUFFER_BINDING
	BOOST_CHECK(x != ev.renderbuffer_binding);
# endif
# ifdef GL_SAMPLER_BINDING
	BOOST_CHECK(x != ev.sampler_binding);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_BINDING
	BOOST_CHECK(x != ev.shader_storage_buffer_binding);
# endif
# ifdef GL_TEXTURE_BINDING_1D
	BOOST_CHECK(x != ev.texture_binding_1d);
# endif
# ifdef GL_TEXTURE_BINDING_1D_ARRAY
	BOOST_CHECK(x != ev.texture_binding_1d_array);
# endif
# ifdef GL_TEXTURE_BINDING_2D
	BOOST_CHECK(x != ev.texture_binding_2d);
# endif
# ifdef GL_TEXTURE_BINDING_2D_ARRAY
	BOOST_CHECK(x != ev.texture_binding_2d_array);
# endif
# ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.texture_binding_2d_multisample);
# endif
# ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.texture_binding_2d_multisample_array);
# endif
# ifdef GL_TEXTURE_BINDING_3D
	BOOST_CHECK(x != ev.texture_binding_3d);
# endif
# ifdef GL_TEXTURE_BINDING_BUFFER
	BOOST_CHECK(x != ev.texture_binding_buffer);
# endif
# ifdef GL_TEXTURE_BINDING_CUBE_MAP
	BOOST_CHECK(x != ev.texture_binding_cube_map);
# endif
# ifdef GL_TEXTURE_BINDING_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.texture_binding_cube_map_array);
# endif
# ifdef GL_TEXTURE_BINDING_RECTANGLE
	BOOST_CHECK(x != ev.texture_binding_rectangle);
# endif
# ifdef GL_TEXTURE_BUFFER_BINDING
	BOOST_CHECK(x != ev.texture_buffer_binding);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BINDING
	BOOST_CHECK(x != ev.transform_feedback_binding);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_BINDING
	BOOST_CHECK(x != ev.transform_feedback_buffer_binding);
# endif
# ifdef GL_UNIFORM_BUFFER_BINDING
	BOOST_CHECK(x != ev.uniform_buffer_binding);
# endif
# ifdef GL_VERTEX_ARRAY_BINDING
	BOOST_CHECK(x != ev.vertex_array_binding);
# endif
#endif

#ifdef GL_PIXEL_PACK_BUFFER_BINDING
	x = ev.pixel_pack_buffer_binding;
	BOOST_CHECK(x == ev.pixel_pack_buffer_binding);
# ifdef GL_PIXEL_UNPACK_BUFFER_BINDING
	BOOST_CHECK(x != ev.pixel_unpack_buffer_binding);
# endif
# ifdef GL_QUERY_BUFFER_BINDING
	BOOST_CHECK(x != ev.query_buffer_binding);
# endif
# ifdef GL_RENDERBUFFER_BINDING
	BOOST_CHECK(x != ev.renderbuffer_binding);
# endif
# ifdef GL_SAMPLER_BINDING
	BOOST_CHECK(x != ev.sampler_binding);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_BINDING
	BOOST_CHECK(x != ev.shader_storage_buffer_binding);
# endif
# ifdef GL_TEXTURE_BINDING_1D
	BOOST_CHECK(x != ev.texture_binding_1d);
# endif
# ifdef GL_TEXTURE_BINDING_1D_ARRAY
	BOOST_CHECK(x != ev.texture_binding_1d_array);
# endif
# ifdef GL_TEXTURE_BINDING_2D
	BOOST_CHECK(x != ev.texture_binding_2d);
# endif
# ifdef GL_TEXTURE_BINDING_2D_ARRAY
	BOOST_CHECK(x != ev.texture_binding_2d_array);
# endif
# ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.texture_binding_2d_multisample);
# endif
# ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.texture_binding_2d_multisample_array);
# endif
# ifdef GL_TEXTURE_BINDING_3D
	BOOST_CHECK(x != ev.texture_binding_3d);
# endif
# ifdef GL_TEXTURE_BINDING_BUFFER
	BOOST_CHECK(x != ev.texture_binding_buffer);
# endif
# ifdef GL_TEXTURE_BINDING_CUBE_MAP
	BOOST_CHECK(x != ev.texture_binding_cube_map);
# endif
# ifdef GL_TEXTURE_BINDING_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.texture_binding_cube_map_array);
# endif
# ifdef GL_TEXTURE_BINDING_RECTANGLE
	BOOST_CHECK(x != ev.texture_binding_rectangle);
# endif
# ifdef GL_TEXTURE_BUFFER_BINDING
	BOOST_CHECK(x != ev.texture_buffer_binding);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BINDING
	BOOST_CHECK(x != ev.transform_feedback_binding);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_BINDING
	BOOST_CHECK(x != ev.transform_feedback_buffer_binding);
# endif
# ifdef GL_UNIFORM_BUFFER_BINDING
	BOOST_CHECK(x != ev.uniform_buffer_binding);
# endif
# ifdef GL_VERTEX_ARRAY_BINDING
	BOOST_CHECK(x != ev.vertex_array_binding);
# endif
#endif

#ifdef GL_PIXEL_UNPACK_BUFFER_BINDING
	x = ev.pixel_unpack_buffer_binding;
	BOOST_CHECK(x == ev.pixel_unpack_buffer_binding);
# ifdef GL_QUERY_BUFFER_BINDING
	BOOST_CHECK(x != ev.query_buffer_binding);
# endif
# ifdef GL_RENDERBUFFER_BINDING
	BOOST_CHECK(x != ev.renderbuffer_binding);
# endif
# ifdef GL_SAMPLER_BINDING
	BOOST_CHECK(x != ev.sampler_binding);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_BINDING
	BOOST_CHECK(x != ev.shader_storage_buffer_binding);
# endif
# ifdef GL_TEXTURE_BINDING_1D
	BOOST_CHECK(x != ev.texture_binding_1d);
# endif
# ifdef GL_TEXTURE_BINDING_1D_ARRAY
	BOOST_CHECK(x != ev.texture_binding_1d_array);
# endif
# ifdef GL_TEXTURE_BINDING_2D
	BOOST_CHECK(x != ev.texture_binding_2d);
# endif
# ifdef GL_TEXTURE_BINDING_2D_ARRAY
	BOOST_CHECK(x != ev.texture_binding_2d_array);
# endif
# ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.texture_binding_2d_multisample);
# endif
# ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.texture_binding_2d_multisample_array);
# endif
# ifdef GL_TEXTURE_BINDING_3D
	BOOST_CHECK(x != ev.texture_binding_3d);
# endif
# ifdef GL_TEXTURE_BINDING_BUFFER
	BOOST_CHECK(x != ev.texture_binding_buffer);
# endif
# ifdef GL_TEXTURE_BINDING_CUBE_MAP
	BOOST_CHECK(x != ev.texture_binding_cube_map);
# endif
# ifdef GL_TEXTURE_BINDING_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.texture_binding_cube_map_array);
# endif
# ifdef GL_TEXTURE_BINDING_RECTANGLE
	BOOST_CHECK(x != ev.texture_binding_rectangle);
# endif
# ifdef GL_TEXTURE_BUFFER_BINDING
	BOOST_CHECK(x != ev.texture_buffer_binding);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BINDING
	BOOST_CHECK(x != ev.transform_feedback_binding);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_BINDING
	BOOST_CHECK(x != ev.transform_feedback_buffer_binding);
# endif
# ifdef GL_UNIFORM_BUFFER_BINDING
	BOOST_CHECK(x != ev.uniform_buffer_binding);
# endif
# ifdef GL_VERTEX_ARRAY_BINDING
	BOOST_CHECK(x != ev.vertex_array_binding);
# endif
#endif

#ifdef GL_QUERY_BUFFER_BINDING
	x = ev.query_buffer_binding;
	BOOST_CHECK(x == ev.query_buffer_binding);
# ifdef GL_RENDERBUFFER_BINDING
	BOOST_CHECK(x != ev.renderbuffer_binding);
# endif
# ifdef GL_SAMPLER_BINDING
	BOOST_CHECK(x != ev.sampler_binding);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_BINDING
	BOOST_CHECK(x != ev.shader_storage_buffer_binding);
# endif
# ifdef GL_TEXTURE_BINDING_1D
	BOOST_CHECK(x != ev.texture_binding_1d);
# endif
# ifdef GL_TEXTURE_BINDING_1D_ARRAY
	BOOST_CHECK(x != ev.texture_binding_1d_array);
# endif
# ifdef GL_TEXTURE_BINDING_2D
	BOOST_CHECK(x != ev.texture_binding_2d);
# endif
# ifdef GL_TEXTURE_BINDING_2D_ARRAY
	BOOST_CHECK(x != ev.texture_binding_2d_array);
# endif
# ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.texture_binding_2d_multisample);
# endif
# ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.texture_binding_2d_multisample_array);
# endif
# ifdef GL_TEXTURE_BINDING_3D
	BOOST_CHECK(x != ev.texture_binding_3d);
# endif
# ifdef GL_TEXTURE_BINDING_BUFFER
	BOOST_CHECK(x != ev.texture_binding_buffer);
# endif
# ifdef GL_TEXTURE_BINDING_CUBE_MAP
	BOOST_CHECK(x != ev.texture_binding_cube_map);
# endif
# ifdef GL_TEXTURE_BINDING_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.texture_binding_cube_map_array);
# endif
# ifdef GL_TEXTURE_BINDING_RECTANGLE
	BOOST_CHECK(x != ev.texture_binding_rectangle);
# endif
# ifdef GL_TEXTURE_BUFFER_BINDING
	BOOST_CHECK(x != ev.texture_buffer_binding);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BINDING
	BOOST_CHECK(x != ev.transform_feedback_binding);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_BINDING
	BOOST_CHECK(x != ev.transform_feedback_buffer_binding);
# endif
# ifdef GL_UNIFORM_BUFFER_BINDING
	BOOST_CHECK(x != ev.uniform_buffer_binding);
# endif
# ifdef GL_VERTEX_ARRAY_BINDING
	BOOST_CHECK(x != ev.vertex_array_binding);
# endif
#endif

#ifdef GL_RENDERBUFFER_BINDING
	x = ev.renderbuffer_binding;
	BOOST_CHECK(x == ev.renderbuffer_binding);
# ifdef GL_SAMPLER_BINDING
	BOOST_CHECK(x != ev.sampler_binding);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_BINDING
	BOOST_CHECK(x != ev.shader_storage_buffer_binding);
# endif
# ifdef GL_TEXTURE_BINDING_1D
	BOOST_CHECK(x != ev.texture_binding_1d);
# endif
# ifdef GL_TEXTURE_BINDING_1D_ARRAY
	BOOST_CHECK(x != ev.texture_binding_1d_array);
# endif
# ifdef GL_TEXTURE_BINDING_2D
	BOOST_CHECK(x != ev.texture_binding_2d);
# endif
# ifdef GL_TEXTURE_BINDING_2D_ARRAY
	BOOST_CHECK(x != ev.texture_binding_2d_array);
# endif
# ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.texture_binding_2d_multisample);
# endif
# ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.texture_binding_2d_multisample_array);
# endif
# ifdef GL_TEXTURE_BINDING_3D
	BOOST_CHECK(x != ev.texture_binding_3d);
# endif
# ifdef GL_TEXTURE_BINDING_BUFFER
	BOOST_CHECK(x != ev.texture_binding_buffer);
# endif
# ifdef GL_TEXTURE_BINDING_CUBE_MAP
	BOOST_CHECK(x != ev.texture_binding_cube_map);
# endif
# ifdef GL_TEXTURE_BINDING_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.texture_binding_cube_map_array);
# endif
# ifdef GL_TEXTURE_BINDING_RECTANGLE
	BOOST_CHECK(x != ev.texture_binding_rectangle);
# endif
# ifdef GL_TEXTURE_BUFFER_BINDING
	BOOST_CHECK(x != ev.texture_buffer_binding);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BINDING
	BOOST_CHECK(x != ev.transform_feedback_binding);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_BINDING
	BOOST_CHECK(x != ev.transform_feedback_buffer_binding);
# endif
# ifdef GL_UNIFORM_BUFFER_BINDING
	BOOST_CHECK(x != ev.uniform_buffer_binding);
# endif
# ifdef GL_VERTEX_ARRAY_BINDING
	BOOST_CHECK(x != ev.vertex_array_binding);
# endif
#endif

#ifdef GL_SAMPLER_BINDING
	x = ev.sampler_binding;
	BOOST_CHECK(x == ev.sampler_binding);
# ifdef GL_SHADER_STORAGE_BUFFER_BINDING
	BOOST_CHECK(x != ev.shader_storage_buffer_binding);
# endif
# ifdef GL_TEXTURE_BINDING_1D
	BOOST_CHECK(x != ev.texture_binding_1d);
# endif
# ifdef GL_TEXTURE_BINDING_1D_ARRAY
	BOOST_CHECK(x != ev.texture_binding_1d_array);
# endif
# ifdef GL_TEXTURE_BINDING_2D
	BOOST_CHECK(x != ev.texture_binding_2d);
# endif
# ifdef GL_TEXTURE_BINDING_2D_ARRAY
	BOOST_CHECK(x != ev.texture_binding_2d_array);
# endif
# ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.texture_binding_2d_multisample);
# endif
# ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.texture_binding_2d_multisample_array);
# endif
# ifdef GL_TEXTURE_BINDING_3D
	BOOST_CHECK(x != ev.texture_binding_3d);
# endif
# ifdef GL_TEXTURE_BINDING_BUFFER
	BOOST_CHECK(x != ev.texture_binding_buffer);
# endif
# ifdef GL_TEXTURE_BINDING_CUBE_MAP
	BOOST_CHECK(x != ev.texture_binding_cube_map);
# endif
# ifdef GL_TEXTURE_BINDING_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.texture_binding_cube_map_array);
# endif
# ifdef GL_TEXTURE_BINDING_RECTANGLE
	BOOST_CHECK(x != ev.texture_binding_rectangle);
# endif
# ifdef GL_TEXTURE_BUFFER_BINDING
	BOOST_CHECK(x != ev.texture_buffer_binding);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BINDING
	BOOST_CHECK(x != ev.transform_feedback_binding);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_BINDING
	BOOST_CHECK(x != ev.transform_feedback_buffer_binding);
# endif
# ifdef GL_UNIFORM_BUFFER_BINDING
	BOOST_CHECK(x != ev.uniform_buffer_binding);
# endif
# ifdef GL_VERTEX_ARRAY_BINDING
	BOOST_CHECK(x != ev.vertex_array_binding);
# endif
#endif

#ifdef GL_SHADER_STORAGE_BUFFER_BINDING
	x = ev.shader_storage_buffer_binding;
	BOOST_CHECK(x == ev.shader_storage_buffer_binding);
# ifdef GL_TEXTURE_BINDING_1D
	BOOST_CHECK(x != ev.texture_binding_1d);
# endif
# ifdef GL_TEXTURE_BINDING_1D_ARRAY
	BOOST_CHECK(x != ev.texture_binding_1d_array);
# endif
# ifdef GL_TEXTURE_BINDING_2D
	BOOST_CHECK(x != ev.texture_binding_2d);
# endif
# ifdef GL_TEXTURE_BINDING_2D_ARRAY
	BOOST_CHECK(x != ev.texture_binding_2d_array);
# endif
# ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.texture_binding_2d_multisample);
# endif
# ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.texture_binding_2d_multisample_array);
# endif
# ifdef GL_TEXTURE_BINDING_3D
	BOOST_CHECK(x != ev.texture_binding_3d);
# endif
# ifdef GL_TEXTURE_BINDING_BUFFER
	BOOST_CHECK(x != ev.texture_binding_buffer);
# endif
# ifdef GL_TEXTURE_BINDING_CUBE_MAP
	BOOST_CHECK(x != ev.texture_binding_cube_map);
# endif
# ifdef GL_TEXTURE_BINDING_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.texture_binding_cube_map_array);
# endif
# ifdef GL_TEXTURE_BINDING_RECTANGLE
	BOOST_CHECK(x != ev.texture_binding_rectangle);
# endif
# ifdef GL_TEXTURE_BUFFER_BINDING
	BOOST_CHECK(x != ev.texture_buffer_binding);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BINDING
	BOOST_CHECK(x != ev.transform_feedback_binding);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_BINDING
	BOOST_CHECK(x != ev.transform_feedback_buffer_binding);
# endif
# ifdef GL_UNIFORM_BUFFER_BINDING
	BOOST_CHECK(x != ev.uniform_buffer_binding);
# endif
# ifdef GL_VERTEX_ARRAY_BINDING
	BOOST_CHECK(x != ev.vertex_array_binding);
# endif
#endif

#ifdef GL_TEXTURE_BINDING_1D
	x = ev.texture_binding_1d;
	BOOST_CHECK(x == ev.texture_binding_1d);
# ifdef GL_TEXTURE_BINDING_1D_ARRAY
	BOOST_CHECK(x != ev.texture_binding_1d_array);
# endif
# ifdef GL_TEXTURE_BINDING_2D
	BOOST_CHECK(x != ev.texture_binding_2d);
# endif
# ifdef GL_TEXTURE_BINDING_2D_ARRAY
	BOOST_CHECK(x != ev.texture_binding_2d_array);
# endif
# ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.texture_binding_2d_multisample);
# endif
# ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.texture_binding_2d_multisample_array);
# endif
# ifdef GL_TEXTURE_BINDING_3D
	BOOST_CHECK(x != ev.texture_binding_3d);
# endif
# ifdef GL_TEXTURE_BINDING_BUFFER
	BOOST_CHECK(x != ev.texture_binding_buffer);
# endif
# ifdef GL_TEXTURE_BINDING_CUBE_MAP
	BOOST_CHECK(x != ev.texture_binding_cube_map);
# endif
# ifdef GL_TEXTURE_BINDING_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.texture_binding_cube_map_array);
# endif
# ifdef GL_TEXTURE_BINDING_RECTANGLE
	BOOST_CHECK(x != ev.texture_binding_rectangle);
# endif
# ifdef GL_TEXTURE_BUFFER_BINDING
	BOOST_CHECK(x != ev.texture_buffer_binding);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BINDING
	BOOST_CHECK(x != ev.transform_feedback_binding);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_BINDING
	BOOST_CHECK(x != ev.transform_feedback_buffer_binding);
# endif
# ifdef GL_UNIFORM_BUFFER_BINDING
	BOOST_CHECK(x != ev.uniform_buffer_binding);
# endif
# ifdef GL_VERTEX_ARRAY_BINDING
	BOOST_CHECK(x != ev.vertex_array_binding);
# endif
#endif

#ifdef GL_TEXTURE_BINDING_1D_ARRAY
	x = ev.texture_binding_1d_array;
	BOOST_CHECK(x == ev.texture_binding_1d_array);
# ifdef GL_TEXTURE_BINDING_2D
	BOOST_CHECK(x != ev.texture_binding_2d);
# endif
# ifdef GL_TEXTURE_BINDING_2D_ARRAY
	BOOST_CHECK(x != ev.texture_binding_2d_array);
# endif
# ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.texture_binding_2d_multisample);
# endif
# ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.texture_binding_2d_multisample_array);
# endif
# ifdef GL_TEXTURE_BINDING_3D
	BOOST_CHECK(x != ev.texture_binding_3d);
# endif
# ifdef GL_TEXTURE_BINDING_BUFFER
	BOOST_CHECK(x != ev.texture_binding_buffer);
# endif
# ifdef GL_TEXTURE_BINDING_CUBE_MAP
	BOOST_CHECK(x != ev.texture_binding_cube_map);
# endif
# ifdef GL_TEXTURE_BINDING_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.texture_binding_cube_map_array);
# endif
# ifdef GL_TEXTURE_BINDING_RECTANGLE
	BOOST_CHECK(x != ev.texture_binding_rectangle);
# endif
# ifdef GL_TEXTURE_BUFFER_BINDING
	BOOST_CHECK(x != ev.texture_buffer_binding);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BINDING
	BOOST_CHECK(x != ev.transform_feedback_binding);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_BINDING
	BOOST_CHECK(x != ev.transform_feedback_buffer_binding);
# endif
# ifdef GL_UNIFORM_BUFFER_BINDING
	BOOST_CHECK(x != ev.uniform_buffer_binding);
# endif
# ifdef GL_VERTEX_ARRAY_BINDING
	BOOST_CHECK(x != ev.vertex_array_binding);
# endif
#endif

#ifdef GL_TEXTURE_BINDING_2D
	x = ev.texture_binding_2d;
	BOOST_CHECK(x == ev.texture_binding_2d);
# ifdef GL_TEXTURE_BINDING_2D_ARRAY
	BOOST_CHECK(x != ev.texture_binding_2d_array);
# endif
# ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.texture_binding_2d_multisample);
# endif
# ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.texture_binding_2d_multisample_array);
# endif
# ifdef GL_TEXTURE_BINDING_3D
	BOOST_CHECK(x != ev.texture_binding_3d);
# endif
# ifdef GL_TEXTURE_BINDING_BUFFER
	BOOST_CHECK(x != ev.texture_binding_buffer);
# endif
# ifdef GL_TEXTURE_BINDING_CUBE_MAP
	BOOST_CHECK(x != ev.texture_binding_cube_map);
# endif
# ifdef GL_TEXTURE_BINDING_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.texture_binding_cube_map_array);
# endif
# ifdef GL_TEXTURE_BINDING_RECTANGLE
	BOOST_CHECK(x != ev.texture_binding_rectangle);
# endif
# ifdef GL_TEXTURE_BUFFER_BINDING
	BOOST_CHECK(x != ev.texture_buffer_binding);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BINDING
	BOOST_CHECK(x != ev.transform_feedback_binding);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_BINDING
	BOOST_CHECK(x != ev.transform_feedback_buffer_binding);
# endif
# ifdef GL_UNIFORM_BUFFER_BINDING
	BOOST_CHECK(x != ev.uniform_buffer_binding);
# endif
# ifdef GL_VERTEX_ARRAY_BINDING
	BOOST_CHECK(x != ev.vertex_array_binding);
# endif
#endif

#ifdef GL_TEXTURE_BINDING_2D_ARRAY
	x = ev.texture_binding_2d_array;
	BOOST_CHECK(x == ev.texture_binding_2d_array);
# ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE
	BOOST_CHECK(x != ev.texture_binding_2d_multisample);
# endif
# ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.texture_binding_2d_multisample_array);
# endif
# ifdef GL_TEXTURE_BINDING_3D
	BOOST_CHECK(x != ev.texture_binding_3d);
# endif
# ifdef GL_TEXTURE_BINDING_BUFFER
	BOOST_CHECK(x != ev.texture_binding_buffer);
# endif
# ifdef GL_TEXTURE_BINDING_CUBE_MAP
	BOOST_CHECK(x != ev.texture_binding_cube_map);
# endif
# ifdef GL_TEXTURE_BINDING_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.texture_binding_cube_map_array);
# endif
# ifdef GL_TEXTURE_BINDING_RECTANGLE
	BOOST_CHECK(x != ev.texture_binding_rectangle);
# endif
# ifdef GL_TEXTURE_BUFFER_BINDING
	BOOST_CHECK(x != ev.texture_buffer_binding);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BINDING
	BOOST_CHECK(x != ev.transform_feedback_binding);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_BINDING
	BOOST_CHECK(x != ev.transform_feedback_buffer_binding);
# endif
# ifdef GL_UNIFORM_BUFFER_BINDING
	BOOST_CHECK(x != ev.uniform_buffer_binding);
# endif
# ifdef GL_VERTEX_ARRAY_BINDING
	BOOST_CHECK(x != ev.vertex_array_binding);
# endif
#endif

#ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE
	x = ev.texture_binding_2d_multisample;
	BOOST_CHECK(x == ev.texture_binding_2d_multisample);
# ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY
	BOOST_CHECK(x != ev.texture_binding_2d_multisample_array);
# endif
# ifdef GL_TEXTURE_BINDING_3D
	BOOST_CHECK(x != ev.texture_binding_3d);
# endif
# ifdef GL_TEXTURE_BINDING_BUFFER
	BOOST_CHECK(x != ev.texture_binding_buffer);
# endif
# ifdef GL_TEXTURE_BINDING_CUBE_MAP
	BOOST_CHECK(x != ev.texture_binding_cube_map);
# endif
# ifdef GL_TEXTURE_BINDING_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.texture_binding_cube_map_array);
# endif
# ifdef GL_TEXTURE_BINDING_RECTANGLE
	BOOST_CHECK(x != ev.texture_binding_rectangle);
# endif
# ifdef GL_TEXTURE_BUFFER_BINDING
	BOOST_CHECK(x != ev.texture_buffer_binding);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BINDING
	BOOST_CHECK(x != ev.transform_feedback_binding);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_BINDING
	BOOST_CHECK(x != ev.transform_feedback_buffer_binding);
# endif
# ifdef GL_UNIFORM_BUFFER_BINDING
	BOOST_CHECK(x != ev.uniform_buffer_binding);
# endif
# ifdef GL_VERTEX_ARRAY_BINDING
	BOOST_CHECK(x != ev.vertex_array_binding);
# endif
#endif

#ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY
	x = ev.texture_binding_2d_multisample_array;
	BOOST_CHECK(x == ev.texture_binding_2d_multisample_array);
# ifdef GL_TEXTURE_BINDING_3D
	BOOST_CHECK(x != ev.texture_binding_3d);
# endif
# ifdef GL_TEXTURE_BINDING_BUFFER
	BOOST_CHECK(x != ev.texture_binding_buffer);
# endif
# ifdef GL_TEXTURE_BINDING_CUBE_MAP
	BOOST_CHECK(x != ev.texture_binding_cube_map);
# endif
# ifdef GL_TEXTURE_BINDING_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.texture_binding_cube_map_array);
# endif
# ifdef GL_TEXTURE_BINDING_RECTANGLE
	BOOST_CHECK(x != ev.texture_binding_rectangle);
# endif
# ifdef GL_TEXTURE_BUFFER_BINDING
	BOOST_CHECK(x != ev.texture_buffer_binding);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BINDING
	BOOST_CHECK(x != ev.transform_feedback_binding);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_BINDING
	BOOST_CHECK(x != ev.transform_feedback_buffer_binding);
# endif
# ifdef GL_UNIFORM_BUFFER_BINDING
	BOOST_CHECK(x != ev.uniform_buffer_binding);
# endif
# ifdef GL_VERTEX_ARRAY_BINDING
	BOOST_CHECK(x != ev.vertex_array_binding);
# endif
#endif

#ifdef GL_TEXTURE_BINDING_3D
	x = ev.texture_binding_3d;
	BOOST_CHECK(x == ev.texture_binding_3d);
# ifdef GL_TEXTURE_BINDING_BUFFER
	BOOST_CHECK(x != ev.texture_binding_buffer);
# endif
# ifdef GL_TEXTURE_BINDING_CUBE_MAP
	BOOST_CHECK(x != ev.texture_binding_cube_map);
# endif
# ifdef GL_TEXTURE_BINDING_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.texture_binding_cube_map_array);
# endif
# ifdef GL_TEXTURE_BINDING_RECTANGLE
	BOOST_CHECK(x != ev.texture_binding_rectangle);
# endif
# ifdef GL_TEXTURE_BUFFER_BINDING
	BOOST_CHECK(x != ev.texture_buffer_binding);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BINDING
	BOOST_CHECK(x != ev.transform_feedback_binding);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_BINDING
	BOOST_CHECK(x != ev.transform_feedback_buffer_binding);
# endif
# ifdef GL_UNIFORM_BUFFER_BINDING
	BOOST_CHECK(x != ev.uniform_buffer_binding);
# endif
# ifdef GL_VERTEX_ARRAY_BINDING
	BOOST_CHECK(x != ev.vertex_array_binding);
# endif
#endif

#ifdef GL_TEXTURE_BINDING_BUFFER
	x = ev.texture_binding_buffer;
	BOOST_CHECK(x == ev.texture_binding_buffer);
# ifdef GL_TEXTURE_BINDING_CUBE_MAP
	BOOST_CHECK(x != ev.texture_binding_cube_map);
# endif
# ifdef GL_TEXTURE_BINDING_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.texture_binding_cube_map_array);
# endif
# ifdef GL_TEXTURE_BINDING_RECTANGLE
	BOOST_CHECK(x != ev.texture_binding_rectangle);
# endif
# ifdef GL_TEXTURE_BUFFER_BINDING
	BOOST_CHECK(x != ev.texture_buffer_binding);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BINDING
	BOOST_CHECK(x != ev.transform_feedback_binding);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_BINDING
	BOOST_CHECK(x != ev.transform_feedback_buffer_binding);
# endif
# ifdef GL_UNIFORM_BUFFER_BINDING
	BOOST_CHECK(x != ev.uniform_buffer_binding);
# endif
# ifdef GL_VERTEX_ARRAY_BINDING
	BOOST_CHECK(x != ev.vertex_array_binding);
# endif
#endif

#ifdef GL_TEXTURE_BINDING_CUBE_MAP
	x = ev.texture_binding_cube_map;
	BOOST_CHECK(x == ev.texture_binding_cube_map);
# ifdef GL_TEXTURE_BINDING_CUBE_MAP_ARRAY
	BOOST_CHECK(x != ev.texture_binding_cube_map_array);
# endif
# ifdef GL_TEXTURE_BINDING_RECTANGLE
	BOOST_CHECK(x != ev.texture_binding_rectangle);
# endif
# ifdef GL_TEXTURE_BUFFER_BINDING
	BOOST_CHECK(x != ev.texture_buffer_binding);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BINDING
	BOOST_CHECK(x != ev.transform_feedback_binding);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_BINDING
	BOOST_CHECK(x != ev.transform_feedback_buffer_binding);
# endif
# ifdef GL_UNIFORM_BUFFER_BINDING
	BOOST_CHECK(x != ev.uniform_buffer_binding);
# endif
# ifdef GL_VERTEX_ARRAY_BINDING
	BOOST_CHECK(x != ev.vertex_array_binding);
# endif
#endif

#ifdef GL_TEXTURE_BINDING_CUBE_MAP_ARRAY
	x = ev.texture_binding_cube_map_array;
	BOOST_CHECK(x == ev.texture_binding_cube_map_array);
# ifdef GL_TEXTURE_BINDING_RECTANGLE
	BOOST_CHECK(x != ev.texture_binding_rectangle);
# endif
# ifdef GL_TEXTURE_BUFFER_BINDING
	BOOST_CHECK(x != ev.texture_buffer_binding);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BINDING
	BOOST_CHECK(x != ev.transform_feedback_binding);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_BINDING
	BOOST_CHECK(x != ev.transform_feedback_buffer_binding);
# endif
# ifdef GL_UNIFORM_BUFFER_BINDING
	BOOST_CHECK(x != ev.uniform_buffer_binding);
# endif
# ifdef GL_VERTEX_ARRAY_BINDING
	BOOST_CHECK(x != ev.vertex_array_binding);
# endif
#endif

#ifdef GL_TEXTURE_BINDING_RECTANGLE
	x = ev.texture_binding_rectangle;
	BOOST_CHECK(x == ev.texture_binding_rectangle);
# ifdef GL_TEXTURE_BUFFER_BINDING
	BOOST_CHECK(x != ev.texture_buffer_binding);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BINDING
	BOOST_CHECK(x != ev.transform_feedback_binding);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_BINDING
	BOOST_CHECK(x != ev.transform_feedback_buffer_binding);
# endif
# ifdef GL_UNIFORM_BUFFER_BINDING
	BOOST_CHECK(x != ev.uniform_buffer_binding);
# endif
# ifdef GL_VERTEX_ARRAY_BINDING
	BOOST_CHECK(x != ev.vertex_array_binding);
# endif
#endif

#ifdef GL_TEXTURE_BUFFER_BINDING
	x = ev.texture_buffer_binding;
	BOOST_CHECK(x == ev.texture_buffer_binding);
# ifdef GL_TRANSFORM_FEEDBACK_BINDING
	BOOST_CHECK(x != ev.transform_feedback_binding);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_BINDING
	BOOST_CHECK(x != ev.transform_feedback_buffer_binding);
# endif
# ifdef GL_UNIFORM_BUFFER_BINDING
	BOOST_CHECK(x != ev.uniform_buffer_binding);
# endif
# ifdef GL_VERTEX_ARRAY_BINDING
	BOOST_CHECK(x != ev.vertex_array_binding);
# endif
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BINDING
	x = ev.transform_feedback_binding;
	BOOST_CHECK(x == ev.transform_feedback_binding);
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_BINDING
	BOOST_CHECK(x != ev.transform_feedback_buffer_binding);
# endif
# ifdef GL_UNIFORM_BUFFER_BINDING
	BOOST_CHECK(x != ev.uniform_buffer_binding);
# endif
# ifdef GL_VERTEX_ARRAY_BINDING
	BOOST_CHECK(x != ev.vertex_array_binding);
# endif
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_BINDING
	x = ev.transform_feedback_buffer_binding;
	BOOST_CHECK(x == ev.transform_feedback_buffer_binding);
# ifdef GL_UNIFORM_BUFFER_BINDING
	BOOST_CHECK(x != ev.uniform_buffer_binding);
# endif
# ifdef GL_VERTEX_ARRAY_BINDING
	BOOST_CHECK(x != ev.vertex_array_binding);
# endif
#endif

#ifdef GL_UNIFORM_BUFFER_BINDING
	x = ev.uniform_buffer_binding;
	BOOST_CHECK(x == ev.uniform_buffer_binding);
# ifdef GL_VERTEX_ARRAY_BINDING
	BOOST_CHECK(x != ev.vertex_array_binding);
# endif
#endif

#ifdef GL_VERTEX_ARRAY_BINDING
	x = ev.vertex_array_binding;
	BOOST_CHECK(x == ev.vertex_array_binding);
#endif
}

BOOST_AUTO_TEST_CASE(enum_binding_query_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	binding_query x;
	(void)x;

#ifdef GL_ARRAY_BUFFER_BINDING
	x = ev.array_buffer_binding;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ARRAY_BUFFER_BINDING"
	) == 0);
#endif

#ifdef GL_ATOMIC_COUNTER_BUFFER_BINDING
	x = ev.atomic_counter_buffer_binding;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ATOMIC_COUNTER_BUFFER_BINDING"
	) == 0);
#endif

#ifdef GL_BUFFER_BINDING
	x = ev.buffer_binding;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"BUFFER_BINDING"
	) == 0);
#endif

#ifdef GL_COPY_READ_BUFFER_BINDING
	x = ev.copy_read_buffer_binding;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"COPY_READ_BUFFER_BINDING"
	) == 0);
#endif

#ifdef GL_COPY_WRITE_BUFFER_BINDING
	x = ev.copy_write_buffer_binding;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"COPY_WRITE_BUFFER_BINDING"
	) == 0);
#endif

#ifdef GL_CURRENT_PROGRAM
	x = ev.current_program;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"CURRENT_PROGRAM"
	) == 0);
#endif

#ifdef GL_DISPATCH_INDIRECT_BUFFER_BINDING
	x = ev.dispatch_indirect_buffer_binding;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DISPATCH_INDIRECT_BUFFER_BINDING"
	) == 0);
#endif

#ifdef GL_DRAW_FRAMEBUFFER_BINDING
	x = ev.draw_framebuffer_binding;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DRAW_FRAMEBUFFER_BINDING"
	) == 0);
#endif

#ifdef GL_DRAW_INDIRECT_BUFFER_BINDING
	x = ev.draw_indirect_buffer_binding;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DRAW_INDIRECT_BUFFER_BINDING"
	) == 0);
#endif

#ifdef GL_ELEMENT_ARRAY_BUFFER_BINDING
	x = ev.element_array_buffer_binding;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ELEMENT_ARRAY_BUFFER_BINDING"
	) == 0);
#endif

#ifdef GL_PARAMETER_BUFFER_BINDING_ARB
	x = ev.parameter_buffer_binding;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PARAMETER_BUFFER_BINDING_ARB"
	) == 0);
#endif

#ifdef GL_PIXEL_PACK_BUFFER_BINDING
	x = ev.pixel_pack_buffer_binding;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PIXEL_PACK_BUFFER_BINDING"
	) == 0);
#endif

#ifdef GL_PIXEL_UNPACK_BUFFER_BINDING
	x = ev.pixel_unpack_buffer_binding;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PIXEL_UNPACK_BUFFER_BINDING"
	) == 0);
#endif

#ifdef GL_QUERY_BUFFER_BINDING
	x = ev.query_buffer_binding;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"QUERY_BUFFER_BINDING"
	) == 0);
#endif

#ifdef GL_RENDERBUFFER_BINDING
	x = ev.renderbuffer_binding;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RENDERBUFFER_BINDING"
	) == 0);
#endif

#ifdef GL_SAMPLER_BINDING
	x = ev.sampler_binding;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SAMPLER_BINDING"
	) == 0);
#endif

#ifdef GL_SHADER_STORAGE_BUFFER_BINDING
	x = ev.shader_storage_buffer_binding;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SHADER_STORAGE_BUFFER_BINDING"
	) == 0);
#endif

#ifdef GL_TEXTURE_BINDING_1D
	x = ev.texture_binding_1d;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_BINDING_1D"
	) == 0);
#endif

#ifdef GL_TEXTURE_BINDING_1D_ARRAY
	x = ev.texture_binding_1d_array;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_BINDING_1D_ARRAY"
	) == 0);
#endif

#ifdef GL_TEXTURE_BINDING_2D
	x = ev.texture_binding_2d;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_BINDING_2D"
	) == 0);
#endif

#ifdef GL_TEXTURE_BINDING_2D_ARRAY
	x = ev.texture_binding_2d_array;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_BINDING_2D_ARRAY"
	) == 0);
#endif

#ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE
	x = ev.texture_binding_2d_multisample;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_BINDING_2D_MULTISAMPLE"
	) == 0);
#endif

#ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY
	x = ev.texture_binding_2d_multisample_array;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY"
	) == 0);
#endif

#ifdef GL_TEXTURE_BINDING_3D
	x = ev.texture_binding_3d;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_BINDING_3D"
	) == 0);
#endif

#ifdef GL_TEXTURE_BINDING_BUFFER
	x = ev.texture_binding_buffer;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_BINDING_BUFFER"
	) == 0);
#endif

#ifdef GL_TEXTURE_BINDING_CUBE_MAP
	x = ev.texture_binding_cube_map;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_BINDING_CUBE_MAP"
	) == 0);
#endif

#ifdef GL_TEXTURE_BINDING_CUBE_MAP_ARRAY
	x = ev.texture_binding_cube_map_array;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_BINDING_CUBE_MAP_ARRAY"
	) == 0);
#endif

#ifdef GL_TEXTURE_BINDING_RECTANGLE
	x = ev.texture_binding_rectangle;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_BINDING_RECTANGLE"
	) == 0);
#endif

#ifdef GL_TEXTURE_BUFFER_BINDING
	x = ev.texture_buffer_binding;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_BUFFER_BINDING"
	) == 0);
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BINDING
	x = ev.transform_feedback_binding;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TRANSFORM_FEEDBACK_BINDING"
	) == 0);
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_BINDING
	x = ev.transform_feedback_buffer_binding;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TRANSFORM_FEEDBACK_BUFFER_BINDING"
	) == 0);
#endif

#ifdef GL_UNIFORM_BUFFER_BINDING
	x = ev.uniform_buffer_binding;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"UNIFORM_BUFFER_BINDING"
	) == 0);
#endif

#ifdef GL_VERTEX_ARRAY_BINDING
	x = ev.vertex_array_binding;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"VERTEX_ARRAY_BINDING"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_binding_query_range)
{
	using namespace oglplus;
	auto count = enum_value_range<binding_query>().size();

#ifdef GL_ARRAY_BUFFER_BINDING
{
	--count;
	auto r = enum_value_range<binding_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		binding_query(GL_ARRAY_BUFFER_BINDING)
	) != r.end());
}
#endif

#ifdef GL_ATOMIC_COUNTER_BUFFER_BINDING
{
	--count;
	auto r = enum_value_range<binding_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		binding_query(GL_ATOMIC_COUNTER_BUFFER_BINDING)
	) != r.end());
}
#endif

#ifdef GL_BUFFER_BINDING
{
	--count;
	auto r = enum_value_range<binding_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		binding_query(GL_BUFFER_BINDING)
	) != r.end());
}
#endif

#ifdef GL_COPY_READ_BUFFER_BINDING
{
	--count;
	auto r = enum_value_range<binding_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		binding_query(GL_COPY_READ_BUFFER_BINDING)
	) != r.end());
}
#endif

#ifdef GL_COPY_WRITE_BUFFER_BINDING
{
	--count;
	auto r = enum_value_range<binding_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		binding_query(GL_COPY_WRITE_BUFFER_BINDING)
	) != r.end());
}
#endif

#ifdef GL_CURRENT_PROGRAM
{
	--count;
	auto r = enum_value_range<binding_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		binding_query(GL_CURRENT_PROGRAM)
	) != r.end());
}
#endif

#ifdef GL_DISPATCH_INDIRECT_BUFFER_BINDING
{
	--count;
	auto r = enum_value_range<binding_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		binding_query(GL_DISPATCH_INDIRECT_BUFFER_BINDING)
	) != r.end());
}
#endif

#ifdef GL_DRAW_FRAMEBUFFER_BINDING
{
	--count;
	auto r = enum_value_range<binding_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		binding_query(GL_DRAW_FRAMEBUFFER_BINDING)
	) != r.end());
}
#endif

#ifdef GL_DRAW_INDIRECT_BUFFER_BINDING
{
	--count;
	auto r = enum_value_range<binding_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		binding_query(GL_DRAW_INDIRECT_BUFFER_BINDING)
	) != r.end());
}
#endif

#ifdef GL_ELEMENT_ARRAY_BUFFER_BINDING
{
	--count;
	auto r = enum_value_range<binding_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		binding_query(GL_ELEMENT_ARRAY_BUFFER_BINDING)
	) != r.end());
}
#endif

#ifdef GL_PARAMETER_BUFFER_BINDING_ARB
{
	--count;
	auto r = enum_value_range<binding_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		binding_query(GL_PARAMETER_BUFFER_BINDING_ARB)
	) != r.end());
}
#endif

#ifdef GL_PIXEL_PACK_BUFFER_BINDING
{
	--count;
	auto r = enum_value_range<binding_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		binding_query(GL_PIXEL_PACK_BUFFER_BINDING)
	) != r.end());
}
#endif

#ifdef GL_PIXEL_UNPACK_BUFFER_BINDING
{
	--count;
	auto r = enum_value_range<binding_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		binding_query(GL_PIXEL_UNPACK_BUFFER_BINDING)
	) != r.end());
}
#endif

#ifdef GL_QUERY_BUFFER_BINDING
{
	--count;
	auto r = enum_value_range<binding_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		binding_query(GL_QUERY_BUFFER_BINDING)
	) != r.end());
}
#endif

#ifdef GL_RENDERBUFFER_BINDING
{
	--count;
	auto r = enum_value_range<binding_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		binding_query(GL_RENDERBUFFER_BINDING)
	) != r.end());
}
#endif

#ifdef GL_SAMPLER_BINDING
{
	--count;
	auto r = enum_value_range<binding_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		binding_query(GL_SAMPLER_BINDING)
	) != r.end());
}
#endif

#ifdef GL_SHADER_STORAGE_BUFFER_BINDING
{
	--count;
	auto r = enum_value_range<binding_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		binding_query(GL_SHADER_STORAGE_BUFFER_BINDING)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_BINDING_1D
{
	--count;
	auto r = enum_value_range<binding_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		binding_query(GL_TEXTURE_BINDING_1D)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_BINDING_1D_ARRAY
{
	--count;
	auto r = enum_value_range<binding_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		binding_query(GL_TEXTURE_BINDING_1D_ARRAY)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_BINDING_2D
{
	--count;
	auto r = enum_value_range<binding_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		binding_query(GL_TEXTURE_BINDING_2D)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_BINDING_2D_ARRAY
{
	--count;
	auto r = enum_value_range<binding_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		binding_query(GL_TEXTURE_BINDING_2D_ARRAY)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE
{
	--count;
	auto r = enum_value_range<binding_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		binding_query(GL_TEXTURE_BINDING_2D_MULTISAMPLE)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY
{
	--count;
	auto r = enum_value_range<binding_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		binding_query(GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_BINDING_3D
{
	--count;
	auto r = enum_value_range<binding_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		binding_query(GL_TEXTURE_BINDING_3D)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_BINDING_BUFFER
{
	--count;
	auto r = enum_value_range<binding_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		binding_query(GL_TEXTURE_BINDING_BUFFER)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_BINDING_CUBE_MAP
{
	--count;
	auto r = enum_value_range<binding_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		binding_query(GL_TEXTURE_BINDING_CUBE_MAP)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_BINDING_CUBE_MAP_ARRAY
{
	--count;
	auto r = enum_value_range<binding_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		binding_query(GL_TEXTURE_BINDING_CUBE_MAP_ARRAY)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_BINDING_RECTANGLE
{
	--count;
	auto r = enum_value_range<binding_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		binding_query(GL_TEXTURE_BINDING_RECTANGLE)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_BUFFER_BINDING
{
	--count;
	auto r = enum_value_range<binding_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		binding_query(GL_TEXTURE_BUFFER_BINDING)
	) != r.end());
}
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BINDING
{
	--count;
	auto r = enum_value_range<binding_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		binding_query(GL_TRANSFORM_FEEDBACK_BINDING)
	) != r.end());
}
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_BINDING
{
	--count;
	auto r = enum_value_range<binding_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		binding_query(GL_TRANSFORM_FEEDBACK_BUFFER_BINDING)
	) != r.end());
}
#endif

#ifdef GL_UNIFORM_BUFFER_BINDING
{
	--count;
	auto r = enum_value_range<binding_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		binding_query(GL_UNIFORM_BUFFER_BINDING)
	) != r.end());
}
#endif

#ifdef GL_VERTEX_ARRAY_BINDING
{
	--count;
	auto r = enum_value_range<binding_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		binding_query(GL_VERTEX_ARRAY_BINDING)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_binding_query_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	binding_query x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_ARRAY_BUFFER_BINDING
	x = ev.array_buffer_binding;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.array_buffer_binding);
#endif

#ifdef GL_ATOMIC_COUNTER_BUFFER_BINDING
	x = ev.atomic_counter_buffer_binding;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.atomic_counter_buffer_binding);
#endif

#ifdef GL_BUFFER_BINDING
	x = ev.buffer_binding;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.buffer_binding);
#endif

#ifdef GL_COPY_READ_BUFFER_BINDING
	x = ev.copy_read_buffer_binding;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.copy_read_buffer_binding);
#endif

#ifdef GL_COPY_WRITE_BUFFER_BINDING
	x = ev.copy_write_buffer_binding;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.copy_write_buffer_binding);
#endif

#ifdef GL_CURRENT_PROGRAM
	x = ev.current_program;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.current_program);
#endif

#ifdef GL_DISPATCH_INDIRECT_BUFFER_BINDING
	x = ev.dispatch_indirect_buffer_binding;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.dispatch_indirect_buffer_binding);
#endif

#ifdef GL_DRAW_FRAMEBUFFER_BINDING
	x = ev.draw_framebuffer_binding;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.draw_framebuffer_binding);
#endif

#ifdef GL_DRAW_INDIRECT_BUFFER_BINDING
	x = ev.draw_indirect_buffer_binding;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.draw_indirect_buffer_binding);
#endif

#ifdef GL_ELEMENT_ARRAY_BUFFER_BINDING
	x = ev.element_array_buffer_binding;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.element_array_buffer_binding);
#endif

#ifdef GL_PARAMETER_BUFFER_BINDING_ARB
	x = ev.parameter_buffer_binding;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.parameter_buffer_binding);
#endif

#ifdef GL_PIXEL_PACK_BUFFER_BINDING
	x = ev.pixel_pack_buffer_binding;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.pixel_pack_buffer_binding);
#endif

#ifdef GL_PIXEL_UNPACK_BUFFER_BINDING
	x = ev.pixel_unpack_buffer_binding;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.pixel_unpack_buffer_binding);
#endif

#ifdef GL_QUERY_BUFFER_BINDING
	x = ev.query_buffer_binding;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.query_buffer_binding);
#endif

#ifdef GL_RENDERBUFFER_BINDING
	x = ev.renderbuffer_binding;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.renderbuffer_binding);
#endif

#ifdef GL_SAMPLER_BINDING
	x = ev.sampler_binding;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.sampler_binding);
#endif

#ifdef GL_SHADER_STORAGE_BUFFER_BINDING
	x = ev.shader_storage_buffer_binding;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.shader_storage_buffer_binding);
#endif

#ifdef GL_TEXTURE_BINDING_1D
	x = ev.texture_binding_1d;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_binding_1d);
#endif

#ifdef GL_TEXTURE_BINDING_1D_ARRAY
	x = ev.texture_binding_1d_array;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_binding_1d_array);
#endif

#ifdef GL_TEXTURE_BINDING_2D
	x = ev.texture_binding_2d;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_binding_2d);
#endif

#ifdef GL_TEXTURE_BINDING_2D_ARRAY
	x = ev.texture_binding_2d_array;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_binding_2d_array);
#endif

#ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE
	x = ev.texture_binding_2d_multisample;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_binding_2d_multisample);
#endif

#ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY
	x = ev.texture_binding_2d_multisample_array;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_binding_2d_multisample_array);
#endif

#ifdef GL_TEXTURE_BINDING_3D
	x = ev.texture_binding_3d;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_binding_3d);
#endif

#ifdef GL_TEXTURE_BINDING_BUFFER
	x = ev.texture_binding_buffer;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_binding_buffer);
#endif

#ifdef GL_TEXTURE_BINDING_CUBE_MAP
	x = ev.texture_binding_cube_map;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_binding_cube_map);
#endif

#ifdef GL_TEXTURE_BINDING_CUBE_MAP_ARRAY
	x = ev.texture_binding_cube_map_array;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_binding_cube_map_array);
#endif

#ifdef GL_TEXTURE_BINDING_RECTANGLE
	x = ev.texture_binding_rectangle;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_binding_rectangle);
#endif

#ifdef GL_TEXTURE_BUFFER_BINDING
	x = ev.texture_buffer_binding;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_buffer_binding);
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BINDING
	x = ev.transform_feedback_binding;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.transform_feedback_binding);
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_BINDING
	x = ev.transform_feedback_buffer_binding;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.transform_feedback_buffer_binding);
#endif

#ifdef GL_UNIFORM_BUFFER_BINDING
	x = ev.uniform_buffer_binding;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.uniform_buffer_binding);
#endif

#ifdef GL_VERTEX_ARRAY_BINDING
	x = ev.vertex_array_binding;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.vertex_array_binding);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
