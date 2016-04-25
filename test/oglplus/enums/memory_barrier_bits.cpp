//  File test/oglplus/enums/memory_barrier_bits.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_memory_barrier_bits

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_memory_barrier_bits_tests)

BOOST_AUTO_TEST_CASE(enum_memory_barrier_bits_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	memory_barrier_bits x;
	(void)x;

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
# ifdef GL_SHADER_GLOBAL_ACCESS_BARRIER_BIT_NV
	BOOST_CHECK(x != ev.shader_global_access_barrier_bit_nv);
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
# ifdef GL_SHADER_GLOBAL_ACCESS_BARRIER_BIT_NV
	BOOST_CHECK(x != ev.shader_global_access_barrier_bit_nv);
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
# ifdef GL_SHADER_GLOBAL_ACCESS_BARRIER_BIT_NV
	BOOST_CHECK(x != ev.shader_global_access_barrier_bit_nv);
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
# ifdef GL_SHADER_GLOBAL_ACCESS_BARRIER_BIT_NV
	BOOST_CHECK(x != ev.shader_global_access_barrier_bit_nv);
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
# ifdef GL_SHADER_GLOBAL_ACCESS_BARRIER_BIT_NV
	BOOST_CHECK(x != ev.shader_global_access_barrier_bit_nv);
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
	BOOST_CHECK(x == ev.element_array_barrier_bit);
# ifdef GL_FRAMEBUFFER_BARRIER_BIT
	BOOST_CHECK(x != ev.framebuffer_barrier_bit);
# endif
# ifdef GL_PIXEL_BUFFER_BARRIER_BIT
	BOOST_CHECK(x != ev.pixel_buffer_barrier_bit);
# endif
# ifdef GL_SHADER_GLOBAL_ACCESS_BARRIER_BIT_NV
	BOOST_CHECK(x != ev.shader_global_access_barrier_bit_nv);
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
	BOOST_CHECK(x == ev.framebuffer_barrier_bit);
# ifdef GL_PIXEL_BUFFER_BARRIER_BIT
	BOOST_CHECK(x != ev.pixel_buffer_barrier_bit);
# endif
# ifdef GL_SHADER_GLOBAL_ACCESS_BARRIER_BIT_NV
	BOOST_CHECK(x != ev.shader_global_access_barrier_bit_nv);
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
	BOOST_CHECK(x == ev.pixel_buffer_barrier_bit);
# ifdef GL_SHADER_GLOBAL_ACCESS_BARRIER_BIT_NV
	BOOST_CHECK(x != ev.shader_global_access_barrier_bit_nv);
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

#ifdef GL_SHADER_GLOBAL_ACCESS_BARRIER_BIT_NV
	x = ev.shader_global_access_barrier_bit_nv;
	BOOST_CHECK(x == ev.shader_global_access_barrier_bit_nv);
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
	BOOST_CHECK(x == ev.uniform_barrier_bit);
# ifdef GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT
	BOOST_CHECK(x != ev.vertex_attrib_array_barrier_bit);
# endif
#endif

#ifdef GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT
	x = ev.vertex_attrib_array_barrier_bit;
	BOOST_CHECK(x == ev.vertex_attrib_array_barrier_bit);
#endif
}

BOOST_AUTO_TEST_CASE(enum_memory_barrier_bits_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	memory_barrier_bits x;
	(void)x;

#ifdef GL_ALL_BARRIER_BITS
	x = ev.all_barrier_bits;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ALL_BARRIER_BITS"
	) == 0);
#endif

#ifdef GL_ATOMIC_COUNTER_BARRIER_BIT
	x = ev.atomic_counter_barrier_bit;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ATOMIC_COUNTER_BARRIER_BIT"
	) == 0);
#endif

#ifdef GL_BUFFER_UPDATE_BARRIER_BIT
	x = ev.buffer_update_barrier_bit;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"BUFFER_UPDATE_BARRIER_BIT"
	) == 0);
#endif

#ifdef GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT
	x = ev.client_mapped_buffer_barrier_bit;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"CLIENT_MAPPED_BUFFER_BARRIER_BIT"
	) == 0);
#endif

#ifdef GL_COMMAND_BARRIER_BIT
	x = ev.command_barrier_bit;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"COMMAND_BARRIER_BIT"
	) == 0);
#endif

#ifdef GL_ELEMENT_ARRAY_BARRIER_BIT
	x = ev.element_array_barrier_bit;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ELEMENT_ARRAY_BARRIER_BIT"
	) == 0);
#endif

#ifdef GL_FRAMEBUFFER_BARRIER_BIT
	x = ev.framebuffer_barrier_bit;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"FRAMEBUFFER_BARRIER_BIT"
	) == 0);
#endif

#ifdef GL_PIXEL_BUFFER_BARRIER_BIT
	x = ev.pixel_buffer_barrier_bit;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PIXEL_BUFFER_BARRIER_BIT"
	) == 0);
#endif

#ifdef GL_SHADER_GLOBAL_ACCESS_BARRIER_BIT_NV
	x = ev.shader_global_access_barrier_bit_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SHADER_GLOBAL_ACCESS_BARRIER_BIT_NV"
	) == 0);
#endif

#ifdef GL_SHADER_IMAGE_ACCESS_BARRIER_BIT
	x = ev.shader_image_access_barrier_bit;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SHADER_IMAGE_ACCESS_BARRIER_BIT"
	) == 0);
#endif

#ifdef GL_SHADER_STORAGE_BARRIER_BIT
	x = ev.shader_storage_barrier_bit;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SHADER_STORAGE_BARRIER_BIT"
	) == 0);
#endif

#ifdef GL_TEXTURE_FETCH_BARRIER_BIT
	x = ev.texture_fetch_barrier_bit;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_FETCH_BARRIER_BIT"
	) == 0);
#endif

#ifdef GL_TEXTURE_UPDATE_BARRIER_BIT
	x = ev.texture_update_barrier_bit;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_UPDATE_BARRIER_BIT"
	) == 0);
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BARRIER_BIT
	x = ev.transform_feedback_barrier_bit;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TRANSFORM_FEEDBACK_BARRIER_BIT"
	) == 0);
#endif

#ifdef GL_UNIFORM_BARRIER_BIT
	x = ev.uniform_barrier_bit;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"UNIFORM_BARRIER_BIT"
	) == 0);
#endif

#ifdef GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT
	x = ev.vertex_attrib_array_barrier_bit;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"VERTEX_ATTRIB_ARRAY_BARRIER_BIT"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_memory_barrier_bits_range)
{
	using namespace oglplus;
	auto count = enum_value_range<memory_barrier_bits>().size();

#ifdef GL_ALL_BARRIER_BITS
{
	--count;
	auto r = enum_value_range<memory_barrier_bits>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		memory_barrier_bits(GL_ALL_BARRIER_BITS)
	) != r.end());
}
#endif

#ifdef GL_ATOMIC_COUNTER_BARRIER_BIT
{
	--count;
	auto r = enum_value_range<memory_barrier_bits>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		memory_barrier_bits(GL_ATOMIC_COUNTER_BARRIER_BIT)
	) != r.end());
}
#endif

#ifdef GL_BUFFER_UPDATE_BARRIER_BIT
{
	--count;
	auto r = enum_value_range<memory_barrier_bits>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		memory_barrier_bits(GL_BUFFER_UPDATE_BARRIER_BIT)
	) != r.end());
}
#endif

#ifdef GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT
{
	--count;
	auto r = enum_value_range<memory_barrier_bits>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		memory_barrier_bits(GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT)
	) != r.end());
}
#endif

#ifdef GL_COMMAND_BARRIER_BIT
{
	--count;
	auto r = enum_value_range<memory_barrier_bits>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		memory_barrier_bits(GL_COMMAND_BARRIER_BIT)
	) != r.end());
}
#endif

#ifdef GL_ELEMENT_ARRAY_BARRIER_BIT
{
	--count;
	auto r = enum_value_range<memory_barrier_bits>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		memory_barrier_bits(GL_ELEMENT_ARRAY_BARRIER_BIT)
	) != r.end());
}
#endif

#ifdef GL_FRAMEBUFFER_BARRIER_BIT
{
	--count;
	auto r = enum_value_range<memory_barrier_bits>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		memory_barrier_bits(GL_FRAMEBUFFER_BARRIER_BIT)
	) != r.end());
}
#endif

#ifdef GL_PIXEL_BUFFER_BARRIER_BIT
{
	--count;
	auto r = enum_value_range<memory_barrier_bits>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		memory_barrier_bits(GL_PIXEL_BUFFER_BARRIER_BIT)
	) != r.end());
}
#endif

#ifdef GL_SHADER_GLOBAL_ACCESS_BARRIER_BIT_NV
{
	--count;
	auto r = enum_value_range<memory_barrier_bits>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		memory_barrier_bits(GL_SHADER_GLOBAL_ACCESS_BARRIER_BIT_NV)
	) != r.end());
}
#endif

#ifdef GL_SHADER_IMAGE_ACCESS_BARRIER_BIT
{
	--count;
	auto r = enum_value_range<memory_barrier_bits>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		memory_barrier_bits(GL_SHADER_IMAGE_ACCESS_BARRIER_BIT)
	) != r.end());
}
#endif

#ifdef GL_SHADER_STORAGE_BARRIER_BIT
{
	--count;
	auto r = enum_value_range<memory_barrier_bits>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		memory_barrier_bits(GL_SHADER_STORAGE_BARRIER_BIT)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_FETCH_BARRIER_BIT
{
	--count;
	auto r = enum_value_range<memory_barrier_bits>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		memory_barrier_bits(GL_TEXTURE_FETCH_BARRIER_BIT)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_UPDATE_BARRIER_BIT
{
	--count;
	auto r = enum_value_range<memory_barrier_bits>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		memory_barrier_bits(GL_TEXTURE_UPDATE_BARRIER_BIT)
	) != r.end());
}
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BARRIER_BIT
{
	--count;
	auto r = enum_value_range<memory_barrier_bits>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		memory_barrier_bits(GL_TRANSFORM_FEEDBACK_BARRIER_BIT)
	) != r.end());
}
#endif

#ifdef GL_UNIFORM_BARRIER_BIT
{
	--count;
	auto r = enum_value_range<memory_barrier_bits>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		memory_barrier_bits(GL_UNIFORM_BARRIER_BIT)
	) != r.end());
}
#endif

#ifdef GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT
{
	--count;
	auto r = enum_value_range<memory_barrier_bits>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		memory_barrier_bits(GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_memory_barrier_bits_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	memory_barrier_bits x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_ALL_BARRIER_BITS
	x = ev.all_barrier_bits;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.all_barrier_bits);
#endif

#ifdef GL_ATOMIC_COUNTER_BARRIER_BIT
	x = ev.atomic_counter_barrier_bit;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.atomic_counter_barrier_bit);
#endif

#ifdef GL_BUFFER_UPDATE_BARRIER_BIT
	x = ev.buffer_update_barrier_bit;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.buffer_update_barrier_bit);
#endif

#ifdef GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT
	x = ev.client_mapped_buffer_barrier_bit;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.client_mapped_buffer_barrier_bit);
#endif

#ifdef GL_COMMAND_BARRIER_BIT
	x = ev.command_barrier_bit;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.command_barrier_bit);
#endif

#ifdef GL_ELEMENT_ARRAY_BARRIER_BIT
	x = ev.element_array_barrier_bit;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.element_array_barrier_bit);
#endif

#ifdef GL_FRAMEBUFFER_BARRIER_BIT
	x = ev.framebuffer_barrier_bit;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.framebuffer_barrier_bit);
#endif

#ifdef GL_PIXEL_BUFFER_BARRIER_BIT
	x = ev.pixel_buffer_barrier_bit;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.pixel_buffer_barrier_bit);
#endif

#ifdef GL_SHADER_GLOBAL_ACCESS_BARRIER_BIT_NV
	x = ev.shader_global_access_barrier_bit_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.shader_global_access_barrier_bit_nv);
#endif

#ifdef GL_SHADER_IMAGE_ACCESS_BARRIER_BIT
	x = ev.shader_image_access_barrier_bit;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.shader_image_access_barrier_bit);
#endif

#ifdef GL_SHADER_STORAGE_BARRIER_BIT
	x = ev.shader_storage_barrier_bit;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.shader_storage_barrier_bit);
#endif

#ifdef GL_TEXTURE_FETCH_BARRIER_BIT
	x = ev.texture_fetch_barrier_bit;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_fetch_barrier_bit);
#endif

#ifdef GL_TEXTURE_UPDATE_BARRIER_BIT
	x = ev.texture_update_barrier_bit;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_update_barrier_bit);
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BARRIER_BIT
	x = ev.transform_feedback_barrier_bit;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.transform_feedback_barrier_bit);
#endif

#ifdef GL_UNIFORM_BARRIER_BIT
	x = ev.uniform_barrier_bit;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.uniform_barrier_bit);
#endif

#ifdef GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT
	x = ev.vertex_attrib_array_barrier_bit;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.vertex_attrib_array_barrier_bit);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
