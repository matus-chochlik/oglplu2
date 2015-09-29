//  File test/oglplus/enums/memory_barrier_bits.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_memory_barrier_bits

#include <boost/test/unit_test.hpp>
#include "common.hpp"

BOOST_AUTO_TEST_SUITE(enum_memory_barrier_bits)

BOOST_AUTO_TEST_CASE(enum_memory_barrier_bits_values)
{
	using namespace oglplus;
	enum_values ev;
	memory_barrier_bits x;

#ifdef GL_ALL_BARRIER_BITS
	x = ev.all_barrier_bits;
	BOOST_CHECK(x == ev.all_barrier_bits);
# ifdef GL_ATOMIC_COUNTER_BARRIER_BIT
	BOOST_CHECK(x != ev.atomic_counter_barrier_bit);
# endif
# ifdef GL_BUFFER_UPDATE_BARRIER_BIT
	BOOST_CHECK(x != ev.buffer_update_barrier_bit);
# endif
# ifdef GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT
	BOOST_CHECK(x != ev.client_mapped_buffer_barrier_bit);
# endif
# ifdef GL_COMMAND_BARRIER_BIT
	BOOST_CHECK(x != ev.command_barrier_bit);
# endif
# ifdef GL_ELEMENT_ARRAY_BARRIER_BIT
	BOOST_CHECK(x != ev.element_array_barrier_bit);
# endif
# ifdef GL_FRAMEBUFFER_BARRIER_BIT
	BOOST_CHECK(x != ev.framebuffer_barrier_bit);
# endif
# ifdef GL_PIXEL_BUFFER_BARRIER_BIT
	BOOST_CHECK(x != ev.pixel_buffer_barrier_bit);
# endif
# ifdef GL_SHADER_IMAGE_ACCESS_BARRIER_BIT
	BOOST_CHECK(x != ev.shader_image_access_barrier_bit);
# endif
# ifdef GL_SHADER_STORAGE_BARRIER_BIT
	BOOST_CHECK(x != ev.shader_storage_barrier_bit);
# endif
# ifdef GL_TEXTURE_FETCH_BARRIER_BIT
	BOOST_CHECK(x != ev.texture_fetch_barrier_bit);
# endif
# ifdef GL_TEXTURE_UPDATE_BARRIER_BIT
	BOOST_CHECK(x != ev.texture_update_barrier_bit);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BARRIER_BIT
	BOOST_CHECK(x != ev.transform_feedback_barrier_bit);
# endif
# ifdef GL_UNIFORM_BARRIER_BIT
	BOOST_CHECK(x != ev.uniform_barrier_bit);
# endif
# ifdef GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT
	BOOST_CHECK(x != ev.vertex_attrib_array_barrier_bit);
# endif
#endif

#ifdef GL_ATOMIC_COUNTER_BARRIER_BIT
	x = ev.atomic_counter_barrier_bit;
# ifdef GL_ALL_BARRIER_BITS
	BOOST_CHECK(x != ev.all_barrier_bits);
# endif
	BOOST_CHECK(x == ev.atomic_counter_barrier_bit);
# ifdef GL_BUFFER_UPDATE_BARRIER_BIT
	BOOST_CHECK(x != ev.buffer_update_barrier_bit);
# endif
# ifdef GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT
	BOOST_CHECK(x != ev.client_mapped_buffer_barrier_bit);
# endif
# ifdef GL_COMMAND_BARRIER_BIT
	BOOST_CHECK(x != ev.command_barrier_bit);
# endif
# ifdef GL_ELEMENT_ARRAY_BARRIER_BIT
	BOOST_CHECK(x != ev.element_array_barrier_bit);
# endif
# ifdef GL_FRAMEBUFFER_BARRIER_BIT
	BOOST_CHECK(x != ev.framebuffer_barrier_bit);
# endif
# ifdef GL_PIXEL_BUFFER_BARRIER_BIT
	BOOST_CHECK(x != ev.pixel_buffer_barrier_bit);
# endif
# ifdef GL_SHADER_IMAGE_ACCESS_BARRIER_BIT
	BOOST_CHECK(x != ev.shader_image_access_barrier_bit);
# endif
# ifdef GL_SHADER_STORAGE_BARRIER_BIT
	BOOST_CHECK(x != ev.shader_storage_barrier_bit);
# endif
# ifdef GL_TEXTURE_FETCH_BARRIER_BIT
	BOOST_CHECK(x != ev.texture_fetch_barrier_bit);
# endif
# ifdef GL_TEXTURE_UPDATE_BARRIER_BIT
	BOOST_CHECK(x != ev.texture_update_barrier_bit);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BARRIER_BIT
	BOOST_CHECK(x != ev.transform_feedback_barrier_bit);
# endif
# ifdef GL_UNIFORM_BARRIER_BIT
	BOOST_CHECK(x != ev.uniform_barrier_bit);
# endif
# ifdef GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT
	BOOST_CHECK(x != ev.vertex_attrib_array_barrier_bit);
# endif
#endif

#ifdef GL_BUFFER_UPDATE_BARRIER_BIT
	x = ev.buffer_update_barrier_bit;
# ifdef GL_ALL_BARRIER_BITS
	BOOST_CHECK(x != ev.all_barrier_bits);
# endif
# ifdef GL_ATOMIC_COUNTER_BARRIER_BIT
	BOOST_CHECK(x != ev.atomic_counter_barrier_bit);
# endif
	BOOST_CHECK(x == ev.buffer_update_barrier_bit);
# ifdef GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT
	BOOST_CHECK(x != ev.client_mapped_buffer_barrier_bit);
# endif
# ifdef GL_COMMAND_BARRIER_BIT
	BOOST_CHECK(x != ev.command_barrier_bit);
# endif
# ifdef GL_ELEMENT_ARRAY_BARRIER_BIT
	BOOST_CHECK(x != ev.element_array_barrier_bit);
# endif
# ifdef GL_FRAMEBUFFER_BARRIER_BIT
	BOOST_CHECK(x != ev.framebuffer_barrier_bit);
# endif
# ifdef GL_PIXEL_BUFFER_BARRIER_BIT
	BOOST_CHECK(x != ev.pixel_buffer_barrier_bit);
# endif
# ifdef GL_SHADER_IMAGE_ACCESS_BARRIER_BIT
	BOOST_CHECK(x != ev.shader_image_access_barrier_bit);
# endif
# ifdef GL_SHADER_STORAGE_BARRIER_BIT
	BOOST_CHECK(x != ev.shader_storage_barrier_bit);
# endif
# ifdef GL_TEXTURE_FETCH_BARRIER_BIT
	BOOST_CHECK(x != ev.texture_fetch_barrier_bit);
# endif
# ifdef GL_TEXTURE_UPDATE_BARRIER_BIT
	BOOST_CHECK(x != ev.texture_update_barrier_bit);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BARRIER_BIT
	BOOST_CHECK(x != ev.transform_feedback_barrier_bit);
# endif
# ifdef GL_UNIFORM_BARRIER_BIT
	BOOST_CHECK(x != ev.uniform_barrier_bit);
# endif
# ifdef GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT
	BOOST_CHECK(x != ev.vertex_attrib_array_barrier_bit);
# endif
#endif

#ifdef GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT
	x = ev.client_mapped_buffer_barrier_bit;
# ifdef GL_ALL_BARRIER_BITS
	BOOST_CHECK(x != ev.all_barrier_bits);
# endif
# ifdef GL_ATOMIC_COUNTER_BARRIER_BIT
	BOOST_CHECK(x != ev.atomic_counter_barrier_bit);
# endif
# ifdef GL_BUFFER_UPDATE_BARRIER_BIT
	BOOST_CHECK(x != ev.buffer_update_barrier_bit);
# endif
	BOOST_CHECK(x == ev.client_mapped_buffer_barrier_bit);
# ifdef GL_COMMAND_BARRIER_BIT
	BOOST_CHECK(x != ev.command_barrier_bit);
# endif
# ifdef GL_ELEMENT_ARRAY_BARRIER_BIT
	BOOST_CHECK(x != ev.element_array_barrier_bit);
# endif
# ifdef GL_FRAMEBUFFER_BARRIER_BIT
	BOOST_CHECK(x != ev.framebuffer_barrier_bit);
# endif
# ifdef GL_PIXEL_BUFFER_BARRIER_BIT
	BOOST_CHECK(x != ev.pixel_buffer_barrier_bit);
# endif
# ifdef GL_SHADER_IMAGE_ACCESS_BARRIER_BIT
	BOOST_CHECK(x != ev.shader_image_access_barrier_bit);
# endif
# ifdef GL_SHADER_STORAGE_BARRIER_BIT
	BOOST_CHECK(x != ev.shader_storage_barrier_bit);
# endif
# ifdef GL_TEXTURE_FETCH_BARRIER_BIT
	BOOST_CHECK(x != ev.texture_fetch_barrier_bit);
# endif
# ifdef GL_TEXTURE_UPDATE_BARRIER_BIT
	BOOST_CHECK(x != ev.texture_update_barrier_bit);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BARRIER_BIT
	BOOST_CHECK(x != ev.transform_feedback_barrier_bit);
# endif
# ifdef GL_UNIFORM_BARRIER_BIT
	BOOST_CHECK(x != ev.uniform_barrier_bit);
# endif
# ifdef GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT
	BOOST_CHECK(x != ev.vertex_attrib_array_barrier_bit);
# endif
#endif

#ifdef GL_COMMAND_BARRIER_BIT
	x = ev.command_barrier_bit;
# ifdef GL_ALL_BARRIER_BITS
	BOOST_CHECK(x != ev.all_barrier_bits);
# endif
# ifdef GL_ATOMIC_COUNTER_BARRIER_BIT
	BOOST_CHECK(x != ev.atomic_counter_barrier_bit);
# endif
# ifdef GL_BUFFER_UPDATE_BARRIER_BIT
	BOOST_CHECK(x != ev.buffer_update_barrier_bit);
# endif
# ifdef GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT
	BOOST_CHECK(x != ev.client_mapped_buffer_barrier_bit);
# endif
	BOOST_CHECK(x == ev.command_barrier_bit);
# ifdef GL_ELEMENT_ARRAY_BARRIER_BIT
	BOOST_CHECK(x != ev.element_array_barrier_bit);
# endif
# ifdef GL_FRAMEBUFFER_BARRIER_BIT
	BOOST_CHECK(x != ev.framebuffer_barrier_bit);
# endif
# ifdef GL_PIXEL_BUFFER_BARRIER_BIT
	BOOST_CHECK(x != ev.pixel_buffer_barrier_bit);
# endif
# ifdef GL_SHADER_IMAGE_ACCESS_BARRIER_BIT
	BOOST_CHECK(x != ev.shader_image_access_barrier_bit);
# endif
# ifdef GL_SHADER_STORAGE_BARRIER_BIT
	BOOST_CHECK(x != ev.shader_storage_barrier_bit);
# endif
# ifdef GL_TEXTURE_FETCH_BARRIER_BIT
	BOOST_CHECK(x != ev.texture_fetch_barrier_bit);
# endif
# ifdef GL_TEXTURE_UPDATE_BARRIER_BIT
	BOOST_CHECK(x != ev.texture_update_barrier_bit);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BARRIER_BIT
	BOOST_CHECK(x != ev.transform_feedback_barrier_bit);
# endif
# ifdef GL_UNIFORM_BARRIER_BIT
	BOOST_CHECK(x != ev.uniform_barrier_bit);
# endif
# ifdef GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT
	BOOST_CHECK(x != ev.vertex_attrib_array_barrier_bit);
# endif
#endif

#ifdef GL_ELEMENT_ARRAY_BARRIER_BIT
	x = ev.element_array_barrier_bit;
# ifdef GL_ALL_BARRIER_BITS
	BOOST_CHECK(x != ev.all_barrier_bits);
# endif
# ifdef GL_ATOMIC_COUNTER_BARRIER_BIT
	BOOST_CHECK(x != ev.atomic_counter_barrier_bit);
# endif
# ifdef GL_BUFFER_UPDATE_BARRIER_BIT
	BOOST_CHECK(x != ev.buffer_update_barrier_bit);
# endif
# ifdef GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT
	BOOST_CHECK(x != ev.client_mapped_buffer_barrier_bit);
# endif
# ifdef GL_COMMAND_BARRIER_BIT
	BOOST_CHECK(x != ev.command_barrier_bit);
# endif
	BOOST_CHECK(x == ev.element_array_barrier_bit);
# ifdef GL_FRAMEBUFFER_BARRIER_BIT
	BOOST_CHECK(x != ev.framebuffer_barrier_bit);
# endif
# ifdef GL_PIXEL_BUFFER_BARRIER_BIT
	BOOST_CHECK(x != ev.pixel_buffer_barrier_bit);
# endif
# ifdef GL_SHADER_IMAGE_ACCESS_BARRIER_BIT
	BOOST_CHECK(x != ev.shader_image_access_barrier_bit);
# endif
# ifdef GL_SHADER_STORAGE_BARRIER_BIT
	BOOST_CHECK(x != ev.shader_storage_barrier_bit);
# endif
# ifdef GL_TEXTURE_FETCH_BARRIER_BIT
	BOOST_CHECK(x != ev.texture_fetch_barrier_bit);
# endif
# ifdef GL_TEXTURE_UPDATE_BARRIER_BIT
	BOOST_CHECK(x != ev.texture_update_barrier_bit);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BARRIER_BIT
	BOOST_CHECK(x != ev.transform_feedback_barrier_bit);
# endif
# ifdef GL_UNIFORM_BARRIER_BIT
	BOOST_CHECK(x != ev.uniform_barrier_bit);
# endif
# ifdef GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT
	BOOST_CHECK(x != ev.vertex_attrib_array_barrier_bit);
# endif
#endif

#ifdef GL_FRAMEBUFFER_BARRIER_BIT
	x = ev.framebuffer_barrier_bit;
# ifdef GL_ALL_BARRIER_BITS
	BOOST_CHECK(x != ev.all_barrier_bits);
# endif
# ifdef GL_ATOMIC_COUNTER_BARRIER_BIT
	BOOST_CHECK(x != ev.atomic_counter_barrier_bit);
# endif
# ifdef GL_BUFFER_UPDATE_BARRIER_BIT
	BOOST_CHECK(x != ev.buffer_update_barrier_bit);
# endif
# ifdef GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT
	BOOST_CHECK(x != ev.client_mapped_buffer_barrier_bit);
# endif
# ifdef GL_COMMAND_BARRIER_BIT
	BOOST_CHECK(x != ev.command_barrier_bit);
# endif
# ifdef GL_ELEMENT_ARRAY_BARRIER_BIT
	BOOST_CHECK(x != ev.element_array_barrier_bit);
# endif
	BOOST_CHECK(x == ev.framebuffer_barrier_bit);
# ifdef GL_PIXEL_BUFFER_BARRIER_BIT
	BOOST_CHECK(x != ev.pixel_buffer_barrier_bit);
# endif
# ifdef GL_SHADER_IMAGE_ACCESS_BARRIER_BIT
	BOOST_CHECK(x != ev.shader_image_access_barrier_bit);
# endif
# ifdef GL_SHADER_STORAGE_BARRIER_BIT
	BOOST_CHECK(x != ev.shader_storage_barrier_bit);
# endif
# ifdef GL_TEXTURE_FETCH_BARRIER_BIT
	BOOST_CHECK(x != ev.texture_fetch_barrier_bit);
# endif
# ifdef GL_TEXTURE_UPDATE_BARRIER_BIT
	BOOST_CHECK(x != ev.texture_update_barrier_bit);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BARRIER_BIT
	BOOST_CHECK(x != ev.transform_feedback_barrier_bit);
# endif
# ifdef GL_UNIFORM_BARRIER_BIT
	BOOST_CHECK(x != ev.uniform_barrier_bit);
# endif
# ifdef GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT
	BOOST_CHECK(x != ev.vertex_attrib_array_barrier_bit);
# endif
#endif

#ifdef GL_PIXEL_BUFFER_BARRIER_BIT
	x = ev.pixel_buffer_barrier_bit;
# ifdef GL_ALL_BARRIER_BITS
	BOOST_CHECK(x != ev.all_barrier_bits);
# endif
# ifdef GL_ATOMIC_COUNTER_BARRIER_BIT
	BOOST_CHECK(x != ev.atomic_counter_barrier_bit);
# endif
# ifdef GL_BUFFER_UPDATE_BARRIER_BIT
	BOOST_CHECK(x != ev.buffer_update_barrier_bit);
# endif
# ifdef GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT
	BOOST_CHECK(x != ev.client_mapped_buffer_barrier_bit);
# endif
# ifdef GL_COMMAND_BARRIER_BIT
	BOOST_CHECK(x != ev.command_barrier_bit);
# endif
# ifdef GL_ELEMENT_ARRAY_BARRIER_BIT
	BOOST_CHECK(x != ev.element_array_barrier_bit);
# endif
# ifdef GL_FRAMEBUFFER_BARRIER_BIT
	BOOST_CHECK(x != ev.framebuffer_barrier_bit);
# endif
	BOOST_CHECK(x == ev.pixel_buffer_barrier_bit);
# ifdef GL_SHADER_IMAGE_ACCESS_BARRIER_BIT
	BOOST_CHECK(x != ev.shader_image_access_barrier_bit);
# endif
# ifdef GL_SHADER_STORAGE_BARRIER_BIT
	BOOST_CHECK(x != ev.shader_storage_barrier_bit);
# endif
# ifdef GL_TEXTURE_FETCH_BARRIER_BIT
	BOOST_CHECK(x != ev.texture_fetch_barrier_bit);
# endif
# ifdef GL_TEXTURE_UPDATE_BARRIER_BIT
	BOOST_CHECK(x != ev.texture_update_barrier_bit);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BARRIER_BIT
	BOOST_CHECK(x != ev.transform_feedback_barrier_bit);
# endif
# ifdef GL_UNIFORM_BARRIER_BIT
	BOOST_CHECK(x != ev.uniform_barrier_bit);
# endif
# ifdef GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT
	BOOST_CHECK(x != ev.vertex_attrib_array_barrier_bit);
# endif
#endif

#ifdef GL_SHADER_IMAGE_ACCESS_BARRIER_BIT
	x = ev.shader_image_access_barrier_bit;
# ifdef GL_ALL_BARRIER_BITS
	BOOST_CHECK(x != ev.all_barrier_bits);
# endif
# ifdef GL_ATOMIC_COUNTER_BARRIER_BIT
	BOOST_CHECK(x != ev.atomic_counter_barrier_bit);
# endif
# ifdef GL_BUFFER_UPDATE_BARRIER_BIT
	BOOST_CHECK(x != ev.buffer_update_barrier_bit);
# endif
# ifdef GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT
	BOOST_CHECK(x != ev.client_mapped_buffer_barrier_bit);
# endif
# ifdef GL_COMMAND_BARRIER_BIT
	BOOST_CHECK(x != ev.command_barrier_bit);
# endif
# ifdef GL_ELEMENT_ARRAY_BARRIER_BIT
	BOOST_CHECK(x != ev.element_array_barrier_bit);
# endif
# ifdef GL_FRAMEBUFFER_BARRIER_BIT
	BOOST_CHECK(x != ev.framebuffer_barrier_bit);
# endif
# ifdef GL_PIXEL_BUFFER_BARRIER_BIT
	BOOST_CHECK(x != ev.pixel_buffer_barrier_bit);
# endif
	BOOST_CHECK(x == ev.shader_image_access_barrier_bit);
# ifdef GL_SHADER_STORAGE_BARRIER_BIT
	BOOST_CHECK(x != ev.shader_storage_barrier_bit);
# endif
# ifdef GL_TEXTURE_FETCH_BARRIER_BIT
	BOOST_CHECK(x != ev.texture_fetch_barrier_bit);
# endif
# ifdef GL_TEXTURE_UPDATE_BARRIER_BIT
	BOOST_CHECK(x != ev.texture_update_barrier_bit);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BARRIER_BIT
	BOOST_CHECK(x != ev.transform_feedback_barrier_bit);
# endif
# ifdef GL_UNIFORM_BARRIER_BIT
	BOOST_CHECK(x != ev.uniform_barrier_bit);
# endif
# ifdef GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT
	BOOST_CHECK(x != ev.vertex_attrib_array_barrier_bit);
# endif
#endif

#ifdef GL_SHADER_STORAGE_BARRIER_BIT
	x = ev.shader_storage_barrier_bit;
# ifdef GL_ALL_BARRIER_BITS
	BOOST_CHECK(x != ev.all_barrier_bits);
# endif
# ifdef GL_ATOMIC_COUNTER_BARRIER_BIT
	BOOST_CHECK(x != ev.atomic_counter_barrier_bit);
# endif
# ifdef GL_BUFFER_UPDATE_BARRIER_BIT
	BOOST_CHECK(x != ev.buffer_update_barrier_bit);
# endif
# ifdef GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT
	BOOST_CHECK(x != ev.client_mapped_buffer_barrier_bit);
# endif
# ifdef GL_COMMAND_BARRIER_BIT
	BOOST_CHECK(x != ev.command_barrier_bit);
# endif
# ifdef GL_ELEMENT_ARRAY_BARRIER_BIT
	BOOST_CHECK(x != ev.element_array_barrier_bit);
# endif
# ifdef GL_FRAMEBUFFER_BARRIER_BIT
	BOOST_CHECK(x != ev.framebuffer_barrier_bit);
# endif
# ifdef GL_PIXEL_BUFFER_BARRIER_BIT
	BOOST_CHECK(x != ev.pixel_buffer_barrier_bit);
# endif
# ifdef GL_SHADER_IMAGE_ACCESS_BARRIER_BIT
	BOOST_CHECK(x != ev.shader_image_access_barrier_bit);
# endif
	BOOST_CHECK(x == ev.shader_storage_barrier_bit);
# ifdef GL_TEXTURE_FETCH_BARRIER_BIT
	BOOST_CHECK(x != ev.texture_fetch_barrier_bit);
# endif
# ifdef GL_TEXTURE_UPDATE_BARRIER_BIT
	BOOST_CHECK(x != ev.texture_update_barrier_bit);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BARRIER_BIT
	BOOST_CHECK(x != ev.transform_feedback_barrier_bit);
# endif
# ifdef GL_UNIFORM_BARRIER_BIT
	BOOST_CHECK(x != ev.uniform_barrier_bit);
# endif
# ifdef GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT
	BOOST_CHECK(x != ev.vertex_attrib_array_barrier_bit);
# endif
#endif

#ifdef GL_TEXTURE_FETCH_BARRIER_BIT
	x = ev.texture_fetch_barrier_bit;
# ifdef GL_ALL_BARRIER_BITS
	BOOST_CHECK(x != ev.all_barrier_bits);
# endif
# ifdef GL_ATOMIC_COUNTER_BARRIER_BIT
	BOOST_CHECK(x != ev.atomic_counter_barrier_bit);
# endif
# ifdef GL_BUFFER_UPDATE_BARRIER_BIT
	BOOST_CHECK(x != ev.buffer_update_barrier_bit);
# endif
# ifdef GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT
	BOOST_CHECK(x != ev.client_mapped_buffer_barrier_bit);
# endif
# ifdef GL_COMMAND_BARRIER_BIT
	BOOST_CHECK(x != ev.command_barrier_bit);
# endif
# ifdef GL_ELEMENT_ARRAY_BARRIER_BIT
	BOOST_CHECK(x != ev.element_array_barrier_bit);
# endif
# ifdef GL_FRAMEBUFFER_BARRIER_BIT
	BOOST_CHECK(x != ev.framebuffer_barrier_bit);
# endif
# ifdef GL_PIXEL_BUFFER_BARRIER_BIT
	BOOST_CHECK(x != ev.pixel_buffer_barrier_bit);
# endif
# ifdef GL_SHADER_IMAGE_ACCESS_BARRIER_BIT
	BOOST_CHECK(x != ev.shader_image_access_barrier_bit);
# endif
# ifdef GL_SHADER_STORAGE_BARRIER_BIT
	BOOST_CHECK(x != ev.shader_storage_barrier_bit);
# endif
	BOOST_CHECK(x == ev.texture_fetch_barrier_bit);
# ifdef GL_TEXTURE_UPDATE_BARRIER_BIT
	BOOST_CHECK(x != ev.texture_update_barrier_bit);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BARRIER_BIT
	BOOST_CHECK(x != ev.transform_feedback_barrier_bit);
# endif
# ifdef GL_UNIFORM_BARRIER_BIT
	BOOST_CHECK(x != ev.uniform_barrier_bit);
# endif
# ifdef GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT
	BOOST_CHECK(x != ev.vertex_attrib_array_barrier_bit);
# endif
#endif

#ifdef GL_TEXTURE_UPDATE_BARRIER_BIT
	x = ev.texture_update_barrier_bit;
# ifdef GL_ALL_BARRIER_BITS
	BOOST_CHECK(x != ev.all_barrier_bits);
# endif
# ifdef GL_ATOMIC_COUNTER_BARRIER_BIT
	BOOST_CHECK(x != ev.atomic_counter_barrier_bit);
# endif
# ifdef GL_BUFFER_UPDATE_BARRIER_BIT
	BOOST_CHECK(x != ev.buffer_update_barrier_bit);
# endif
# ifdef GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT
	BOOST_CHECK(x != ev.client_mapped_buffer_barrier_bit);
# endif
# ifdef GL_COMMAND_BARRIER_BIT
	BOOST_CHECK(x != ev.command_barrier_bit);
# endif
# ifdef GL_ELEMENT_ARRAY_BARRIER_BIT
	BOOST_CHECK(x != ev.element_array_barrier_bit);
# endif
# ifdef GL_FRAMEBUFFER_BARRIER_BIT
	BOOST_CHECK(x != ev.framebuffer_barrier_bit);
# endif
# ifdef GL_PIXEL_BUFFER_BARRIER_BIT
	BOOST_CHECK(x != ev.pixel_buffer_barrier_bit);
# endif
# ifdef GL_SHADER_IMAGE_ACCESS_BARRIER_BIT
	BOOST_CHECK(x != ev.shader_image_access_barrier_bit);
# endif
# ifdef GL_SHADER_STORAGE_BARRIER_BIT
	BOOST_CHECK(x != ev.shader_storage_barrier_bit);
# endif
# ifdef GL_TEXTURE_FETCH_BARRIER_BIT
	BOOST_CHECK(x != ev.texture_fetch_barrier_bit);
# endif
	BOOST_CHECK(x == ev.texture_update_barrier_bit);
# ifdef GL_TRANSFORM_FEEDBACK_BARRIER_BIT
	BOOST_CHECK(x != ev.transform_feedback_barrier_bit);
# endif
# ifdef GL_UNIFORM_BARRIER_BIT
	BOOST_CHECK(x != ev.uniform_barrier_bit);
# endif
# ifdef GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT
	BOOST_CHECK(x != ev.vertex_attrib_array_barrier_bit);
# endif
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BARRIER_BIT
	x = ev.transform_feedback_barrier_bit;
# ifdef GL_ALL_BARRIER_BITS
	BOOST_CHECK(x != ev.all_barrier_bits);
# endif
# ifdef GL_ATOMIC_COUNTER_BARRIER_BIT
	BOOST_CHECK(x != ev.atomic_counter_barrier_bit);
# endif
# ifdef GL_BUFFER_UPDATE_BARRIER_BIT
	BOOST_CHECK(x != ev.buffer_update_barrier_bit);
# endif
# ifdef GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT
	BOOST_CHECK(x != ev.client_mapped_buffer_barrier_bit);
# endif
# ifdef GL_COMMAND_BARRIER_BIT
	BOOST_CHECK(x != ev.command_barrier_bit);
# endif
# ifdef GL_ELEMENT_ARRAY_BARRIER_BIT
	BOOST_CHECK(x != ev.element_array_barrier_bit);
# endif
# ifdef GL_FRAMEBUFFER_BARRIER_BIT
	BOOST_CHECK(x != ev.framebuffer_barrier_bit);
# endif
# ifdef GL_PIXEL_BUFFER_BARRIER_BIT
	BOOST_CHECK(x != ev.pixel_buffer_barrier_bit);
# endif
# ifdef GL_SHADER_IMAGE_ACCESS_BARRIER_BIT
	BOOST_CHECK(x != ev.shader_image_access_barrier_bit);
# endif
# ifdef GL_SHADER_STORAGE_BARRIER_BIT
	BOOST_CHECK(x != ev.shader_storage_barrier_bit);
# endif
# ifdef GL_TEXTURE_FETCH_BARRIER_BIT
	BOOST_CHECK(x != ev.texture_fetch_barrier_bit);
# endif
# ifdef GL_TEXTURE_UPDATE_BARRIER_BIT
	BOOST_CHECK(x != ev.texture_update_barrier_bit);
# endif
	BOOST_CHECK(x == ev.transform_feedback_barrier_bit);
# ifdef GL_UNIFORM_BARRIER_BIT
	BOOST_CHECK(x != ev.uniform_barrier_bit);
# endif
# ifdef GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT
	BOOST_CHECK(x != ev.vertex_attrib_array_barrier_bit);
# endif
#endif

#ifdef GL_UNIFORM_BARRIER_BIT
	x = ev.uniform_barrier_bit;
# ifdef GL_ALL_BARRIER_BITS
	BOOST_CHECK(x != ev.all_barrier_bits);
# endif
# ifdef GL_ATOMIC_COUNTER_BARRIER_BIT
	BOOST_CHECK(x != ev.atomic_counter_barrier_bit);
# endif
# ifdef GL_BUFFER_UPDATE_BARRIER_BIT
	BOOST_CHECK(x != ev.buffer_update_barrier_bit);
# endif
# ifdef GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT
	BOOST_CHECK(x != ev.client_mapped_buffer_barrier_bit);
# endif
# ifdef GL_COMMAND_BARRIER_BIT
	BOOST_CHECK(x != ev.command_barrier_bit);
# endif
# ifdef GL_ELEMENT_ARRAY_BARRIER_BIT
	BOOST_CHECK(x != ev.element_array_barrier_bit);
# endif
# ifdef GL_FRAMEBUFFER_BARRIER_BIT
	BOOST_CHECK(x != ev.framebuffer_barrier_bit);
# endif
# ifdef GL_PIXEL_BUFFER_BARRIER_BIT
	BOOST_CHECK(x != ev.pixel_buffer_barrier_bit);
# endif
# ifdef GL_SHADER_IMAGE_ACCESS_BARRIER_BIT
	BOOST_CHECK(x != ev.shader_image_access_barrier_bit);
# endif
# ifdef GL_SHADER_STORAGE_BARRIER_BIT
	BOOST_CHECK(x != ev.shader_storage_barrier_bit);
# endif
# ifdef GL_TEXTURE_FETCH_BARRIER_BIT
	BOOST_CHECK(x != ev.texture_fetch_barrier_bit);
# endif
# ifdef GL_TEXTURE_UPDATE_BARRIER_BIT
	BOOST_CHECK(x != ev.texture_update_barrier_bit);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BARRIER_BIT
	BOOST_CHECK(x != ev.transform_feedback_barrier_bit);
# endif
	BOOST_CHECK(x == ev.uniform_barrier_bit);
# ifdef GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT
	BOOST_CHECK(x != ev.vertex_attrib_array_barrier_bit);
# endif
#endif

#ifdef GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT
	x = ev.vertex_attrib_array_barrier_bit;
# ifdef GL_ALL_BARRIER_BITS
	BOOST_CHECK(x != ev.all_barrier_bits);
# endif
# ifdef GL_ATOMIC_COUNTER_BARRIER_BIT
	BOOST_CHECK(x != ev.atomic_counter_barrier_bit);
# endif
# ifdef GL_BUFFER_UPDATE_BARRIER_BIT
	BOOST_CHECK(x != ev.buffer_update_barrier_bit);
# endif
# ifdef GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT
	BOOST_CHECK(x != ev.client_mapped_buffer_barrier_bit);
# endif
# ifdef GL_COMMAND_BARRIER_BIT
	BOOST_CHECK(x != ev.command_barrier_bit);
# endif
# ifdef GL_ELEMENT_ARRAY_BARRIER_BIT
	BOOST_CHECK(x != ev.element_array_barrier_bit);
# endif
# ifdef GL_FRAMEBUFFER_BARRIER_BIT
	BOOST_CHECK(x != ev.framebuffer_barrier_bit);
# endif
# ifdef GL_PIXEL_BUFFER_BARRIER_BIT
	BOOST_CHECK(x != ev.pixel_buffer_barrier_bit);
# endif
# ifdef GL_SHADER_IMAGE_ACCESS_BARRIER_BIT
	BOOST_CHECK(x != ev.shader_image_access_barrier_bit);
# endif
# ifdef GL_SHADER_STORAGE_BARRIER_BIT
	BOOST_CHECK(x != ev.shader_storage_barrier_bit);
# endif
# ifdef GL_TEXTURE_FETCH_BARRIER_BIT
	BOOST_CHECK(x != ev.texture_fetch_barrier_bit);
# endif
# ifdef GL_TEXTURE_UPDATE_BARRIER_BIT
	BOOST_CHECK(x != ev.texture_update_barrier_bit);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BARRIER_BIT
	BOOST_CHECK(x != ev.transform_feedback_barrier_bit);
# endif
# ifdef GL_UNIFORM_BARRIER_BIT
	BOOST_CHECK(x != ev.uniform_barrier_bit);
# endif
	BOOST_CHECK(x == ev.vertex_attrib_array_barrier_bit);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
