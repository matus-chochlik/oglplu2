//  File test/oglplus/enums/limit_query.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_limit_query

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_limit_query_tests)

BOOST_AUTO_TEST_CASE(enum_limit_query_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	limit_query x;
	(void)x;

#ifdef GL_MAX_3D_TEXTURE_SIZE
	x = ev.max_3d_texture_size;
	BOOST_CHECK(x == ev.max_3d_texture_size);
# ifdef GL_MAX_ARRAY_TEXTURE_LAYERS
	BOOST_CHECK(x != ev.max_array_texture_layers);
# endif
# ifdef GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_atomic_counter_buffer_bindings);
# endif
# ifdef GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_atomic_counter_buffer_size);
# endif
# ifdef GL_MAX_CLIP_DISTANCES
	BOOST_CHECK(x != ev.max_clip_distances);
# endif
# ifdef GL_MAX_COLOR_ATTACHMENTS
	BOOST_CHECK(x != ev.max_color_attachments);
# endif
# ifdef GL_MAX_COLOR_TEXTURE_SAMPLES
	BOOST_CHECK(x != ev.max_color_texture_samples);
# endif
# ifdef GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_combined_atomic_counter_buffers);
# endif
# ifdef GL_MAX_COMBINED_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_combined_atomic_counters);
# endif
# ifdef GL_MAX_COMBINED_CLIP_AND_CULL_DISTANCES
	BOOST_CHECK(x != ev.max_combined_clip_and_cull_distances);
# endif
# ifdef GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_fragment_uniform_components);
# endif
# ifdef GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_geometry_uniform_components);
# endif
# ifdef GL_MAX_COMBINED_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_combined_image_uniforms);
# endif
# ifdef GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS
	BOOST_CHECK(x != ev.max_combined_image_units_and_fragment_outputs);
# endif
# ifdef GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_tess_control_uniform_components);
# endif
# ifdef GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_combined_texture_image_units);
# endif
# ifdef GL_MAX_COMBINED_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_combined_uniform_blocks);
# endif
# ifdef GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_vertex_uniform_components);
# endif
# ifdef GL_MAX_COMPUTE_SHARED_MEMORY_SIZE
	BOOST_CHECK(x != ev.max_compute_shared_memory_size);
# endif
# ifdef GL_MAX_COMPUTE_WORK_GROUP_COUNT
	BOOST_CHECK(x != ev.max_compute_work_group_count);
# endif
# ifdef GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS
	BOOST_CHECK(x != ev.max_compute_work_group_invocations);
# endif
# ifdef GL_MAX_COMPUTE_WORK_GROUP_SIZE
	BOOST_CHECK(x != ev.max_compute_work_group_size);
# endif
# ifdef GL_MAX_CUBE_MAP_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_cube_map_texture_size);
# endif
# ifdef GL_MAX_CULL_DISTANCES
	BOOST_CHECK(x != ev.max_cull_distances);
# endif
# ifdef GL_MAX_DEPTH_TEXTURE_SAMPLES
	BOOST_CHECK(x != ev.max_depth_texture_samples);
# endif
# ifdef GL_MAX_DRAW_BUFFERS
	BOOST_CHECK(x != ev.max_draw_buffers);
# endif
# ifdef GL_MAX_DUAL_SOURCE_DRAW_BUFFERS
	BOOST_CHECK(x != ev.max_dual_source_draw_buffers);
# endif
# ifdef GL_MAX_ELEMENTS_INDICES
	BOOST_CHECK(x != ev.max_elements_indices);
# endif
# ifdef GL_MAX_ELEMENTS_VERTICES
	BOOST_CHECK(x != ev.max_elements_vertices);
# endif
# ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_fragment_atomic_counter_buffers);
# endif
# ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_fragment_atomic_counters);
# endif
# ifdef GL_MAX_FRAGMENT_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_fragment_image_uniforms);
# endif
# ifdef GL_MAX_FRAGMENT_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_input_components);
# endif
# ifdef GL_MAX_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.max_fragment_interpolation_offset);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_fragment_uniform_blocks);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_uniform_components);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_fragment_uniform_vectors);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counter_buffers);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counters);
# endif
# ifdef GL_MAX_GEOMETRY_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_geometry_image_uniforms);
# endif
# ifdef GL_MAX_GEOMETRY_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_input_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_VERTICES
	BOOST_CHECK(x != ev.max_geometry_output_vertices);
# endif
# ifdef GL_MAX_GEOMETRY_SHADER_INVOCATIONS
	BOOST_CHECK(x != ev.max_geometry_shader_invocations);
# endif
# ifdef GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_geometry_texture_image_units);
# endif
# ifdef GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_total_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_geometry_uniform_blocks);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_uniform_components);
# endif
# ifdef GL_MAX_IMAGE_SAMPLES
	BOOST_CHECK(x != ev.max_image_samples);
# endif
# ifdef GL_MAX_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_image_units);
# endif
# ifdef GL_MAX_INTEGER_SAMPLES
	BOOST_CHECK(x != ev.max_integer_samples);
# endif
# ifdef GL_MAX_PATCH_VERTICES
	BOOST_CHECK(x != ev.max_patch_vertices);
# endif
# ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.max_program_texel_offset);
# endif
# ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.max_program_texture_gather_offset);
# endif
# ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_rectangle_texture_size);
# endif
# ifdef GL_MAX_RENDERBUFFER_SIZE
	BOOST_CHECK(x != ev.max_renderbuffer_size);
# endif
# ifdef GL_MAX_SAMPLE_MASK_WORDS
	BOOST_CHECK(x != ev.max_sample_mask_words);
# endif
# ifdef GL_MAX_SAMPLES
	BOOST_CHECK(x != ev.max_samples);
# endif
# ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	BOOST_CHECK(x != ev.max_server_wait_timeout);
# endif
# ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	BOOST_CHECK(x != ev.max_subroutine_uniform_locations);
# endif
# ifdef GL_MAX_SUBROUTINES
	BOOST_CHECK(x != ev.max_subroutines);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_ARRAY_TEXTURE_LAYERS
	x = ev.max_array_texture_layers;
	BOOST_CHECK(x == ev.max_array_texture_layers);
# ifdef GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_atomic_counter_buffer_bindings);
# endif
# ifdef GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_atomic_counter_buffer_size);
# endif
# ifdef GL_MAX_CLIP_DISTANCES
	BOOST_CHECK(x != ev.max_clip_distances);
# endif
# ifdef GL_MAX_COLOR_ATTACHMENTS
	BOOST_CHECK(x != ev.max_color_attachments);
# endif
# ifdef GL_MAX_COLOR_TEXTURE_SAMPLES
	BOOST_CHECK(x != ev.max_color_texture_samples);
# endif
# ifdef GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_combined_atomic_counter_buffers);
# endif
# ifdef GL_MAX_COMBINED_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_combined_atomic_counters);
# endif
# ifdef GL_MAX_COMBINED_CLIP_AND_CULL_DISTANCES
	BOOST_CHECK(x != ev.max_combined_clip_and_cull_distances);
# endif
# ifdef GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_fragment_uniform_components);
# endif
# ifdef GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_geometry_uniform_components);
# endif
# ifdef GL_MAX_COMBINED_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_combined_image_uniforms);
# endif
# ifdef GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS
	BOOST_CHECK(x != ev.max_combined_image_units_and_fragment_outputs);
# endif
# ifdef GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_tess_control_uniform_components);
# endif
# ifdef GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_combined_texture_image_units);
# endif
# ifdef GL_MAX_COMBINED_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_combined_uniform_blocks);
# endif
# ifdef GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_vertex_uniform_components);
# endif
# ifdef GL_MAX_COMPUTE_SHARED_MEMORY_SIZE
	BOOST_CHECK(x != ev.max_compute_shared_memory_size);
# endif
# ifdef GL_MAX_COMPUTE_WORK_GROUP_COUNT
	BOOST_CHECK(x != ev.max_compute_work_group_count);
# endif
# ifdef GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS
	BOOST_CHECK(x != ev.max_compute_work_group_invocations);
# endif
# ifdef GL_MAX_COMPUTE_WORK_GROUP_SIZE
	BOOST_CHECK(x != ev.max_compute_work_group_size);
# endif
# ifdef GL_MAX_CUBE_MAP_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_cube_map_texture_size);
# endif
# ifdef GL_MAX_CULL_DISTANCES
	BOOST_CHECK(x != ev.max_cull_distances);
# endif
# ifdef GL_MAX_DEPTH_TEXTURE_SAMPLES
	BOOST_CHECK(x != ev.max_depth_texture_samples);
# endif
# ifdef GL_MAX_DRAW_BUFFERS
	BOOST_CHECK(x != ev.max_draw_buffers);
# endif
# ifdef GL_MAX_DUAL_SOURCE_DRAW_BUFFERS
	BOOST_CHECK(x != ev.max_dual_source_draw_buffers);
# endif
# ifdef GL_MAX_ELEMENTS_INDICES
	BOOST_CHECK(x != ev.max_elements_indices);
# endif
# ifdef GL_MAX_ELEMENTS_VERTICES
	BOOST_CHECK(x != ev.max_elements_vertices);
# endif
# ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_fragment_atomic_counter_buffers);
# endif
# ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_fragment_atomic_counters);
# endif
# ifdef GL_MAX_FRAGMENT_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_fragment_image_uniforms);
# endif
# ifdef GL_MAX_FRAGMENT_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_input_components);
# endif
# ifdef GL_MAX_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.max_fragment_interpolation_offset);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_fragment_uniform_blocks);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_uniform_components);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_fragment_uniform_vectors);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counter_buffers);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counters);
# endif
# ifdef GL_MAX_GEOMETRY_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_geometry_image_uniforms);
# endif
# ifdef GL_MAX_GEOMETRY_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_input_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_VERTICES
	BOOST_CHECK(x != ev.max_geometry_output_vertices);
# endif
# ifdef GL_MAX_GEOMETRY_SHADER_INVOCATIONS
	BOOST_CHECK(x != ev.max_geometry_shader_invocations);
# endif
# ifdef GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_geometry_texture_image_units);
# endif
# ifdef GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_total_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_geometry_uniform_blocks);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_uniform_components);
# endif
# ifdef GL_MAX_IMAGE_SAMPLES
	BOOST_CHECK(x != ev.max_image_samples);
# endif
# ifdef GL_MAX_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_image_units);
# endif
# ifdef GL_MAX_INTEGER_SAMPLES
	BOOST_CHECK(x != ev.max_integer_samples);
# endif
# ifdef GL_MAX_PATCH_VERTICES
	BOOST_CHECK(x != ev.max_patch_vertices);
# endif
# ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.max_program_texel_offset);
# endif
# ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.max_program_texture_gather_offset);
# endif
# ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_rectangle_texture_size);
# endif
# ifdef GL_MAX_RENDERBUFFER_SIZE
	BOOST_CHECK(x != ev.max_renderbuffer_size);
# endif
# ifdef GL_MAX_SAMPLE_MASK_WORDS
	BOOST_CHECK(x != ev.max_sample_mask_words);
# endif
# ifdef GL_MAX_SAMPLES
	BOOST_CHECK(x != ev.max_samples);
# endif
# ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	BOOST_CHECK(x != ev.max_server_wait_timeout);
# endif
# ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	BOOST_CHECK(x != ev.max_subroutine_uniform_locations);
# endif
# ifdef GL_MAX_SUBROUTINES
	BOOST_CHECK(x != ev.max_subroutines);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS
	x = ev.max_atomic_counter_buffer_bindings;
	BOOST_CHECK(x == ev.max_atomic_counter_buffer_bindings);
# ifdef GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_atomic_counter_buffer_size);
# endif
# ifdef GL_MAX_CLIP_DISTANCES
	BOOST_CHECK(x != ev.max_clip_distances);
# endif
# ifdef GL_MAX_COLOR_ATTACHMENTS
	BOOST_CHECK(x != ev.max_color_attachments);
# endif
# ifdef GL_MAX_COLOR_TEXTURE_SAMPLES
	BOOST_CHECK(x != ev.max_color_texture_samples);
# endif
# ifdef GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_combined_atomic_counter_buffers);
# endif
# ifdef GL_MAX_COMBINED_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_combined_atomic_counters);
# endif
# ifdef GL_MAX_COMBINED_CLIP_AND_CULL_DISTANCES
	BOOST_CHECK(x != ev.max_combined_clip_and_cull_distances);
# endif
# ifdef GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_fragment_uniform_components);
# endif
# ifdef GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_geometry_uniform_components);
# endif
# ifdef GL_MAX_COMBINED_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_combined_image_uniforms);
# endif
# ifdef GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS
	BOOST_CHECK(x != ev.max_combined_image_units_and_fragment_outputs);
# endif
# ifdef GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_tess_control_uniform_components);
# endif
# ifdef GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_combined_texture_image_units);
# endif
# ifdef GL_MAX_COMBINED_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_combined_uniform_blocks);
# endif
# ifdef GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_vertex_uniform_components);
# endif
# ifdef GL_MAX_COMPUTE_SHARED_MEMORY_SIZE
	BOOST_CHECK(x != ev.max_compute_shared_memory_size);
# endif
# ifdef GL_MAX_COMPUTE_WORK_GROUP_COUNT
	BOOST_CHECK(x != ev.max_compute_work_group_count);
# endif
# ifdef GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS
	BOOST_CHECK(x != ev.max_compute_work_group_invocations);
# endif
# ifdef GL_MAX_COMPUTE_WORK_GROUP_SIZE
	BOOST_CHECK(x != ev.max_compute_work_group_size);
# endif
# ifdef GL_MAX_CUBE_MAP_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_cube_map_texture_size);
# endif
# ifdef GL_MAX_CULL_DISTANCES
	BOOST_CHECK(x != ev.max_cull_distances);
# endif
# ifdef GL_MAX_DEPTH_TEXTURE_SAMPLES
	BOOST_CHECK(x != ev.max_depth_texture_samples);
# endif
# ifdef GL_MAX_DRAW_BUFFERS
	BOOST_CHECK(x != ev.max_draw_buffers);
# endif
# ifdef GL_MAX_DUAL_SOURCE_DRAW_BUFFERS
	BOOST_CHECK(x != ev.max_dual_source_draw_buffers);
# endif
# ifdef GL_MAX_ELEMENTS_INDICES
	BOOST_CHECK(x != ev.max_elements_indices);
# endif
# ifdef GL_MAX_ELEMENTS_VERTICES
	BOOST_CHECK(x != ev.max_elements_vertices);
# endif
# ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_fragment_atomic_counter_buffers);
# endif
# ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_fragment_atomic_counters);
# endif
# ifdef GL_MAX_FRAGMENT_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_fragment_image_uniforms);
# endif
# ifdef GL_MAX_FRAGMENT_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_input_components);
# endif
# ifdef GL_MAX_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.max_fragment_interpolation_offset);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_fragment_uniform_blocks);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_uniform_components);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_fragment_uniform_vectors);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counter_buffers);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counters);
# endif
# ifdef GL_MAX_GEOMETRY_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_geometry_image_uniforms);
# endif
# ifdef GL_MAX_GEOMETRY_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_input_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_VERTICES
	BOOST_CHECK(x != ev.max_geometry_output_vertices);
# endif
# ifdef GL_MAX_GEOMETRY_SHADER_INVOCATIONS
	BOOST_CHECK(x != ev.max_geometry_shader_invocations);
# endif
# ifdef GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_geometry_texture_image_units);
# endif
# ifdef GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_total_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_geometry_uniform_blocks);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_uniform_components);
# endif
# ifdef GL_MAX_IMAGE_SAMPLES
	BOOST_CHECK(x != ev.max_image_samples);
# endif
# ifdef GL_MAX_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_image_units);
# endif
# ifdef GL_MAX_INTEGER_SAMPLES
	BOOST_CHECK(x != ev.max_integer_samples);
# endif
# ifdef GL_MAX_PATCH_VERTICES
	BOOST_CHECK(x != ev.max_patch_vertices);
# endif
# ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.max_program_texel_offset);
# endif
# ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.max_program_texture_gather_offset);
# endif
# ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_rectangle_texture_size);
# endif
# ifdef GL_MAX_RENDERBUFFER_SIZE
	BOOST_CHECK(x != ev.max_renderbuffer_size);
# endif
# ifdef GL_MAX_SAMPLE_MASK_WORDS
	BOOST_CHECK(x != ev.max_sample_mask_words);
# endif
# ifdef GL_MAX_SAMPLES
	BOOST_CHECK(x != ev.max_samples);
# endif
# ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	BOOST_CHECK(x != ev.max_server_wait_timeout);
# endif
# ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	BOOST_CHECK(x != ev.max_subroutine_uniform_locations);
# endif
# ifdef GL_MAX_SUBROUTINES
	BOOST_CHECK(x != ev.max_subroutines);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE
	x = ev.max_atomic_counter_buffer_size;
	BOOST_CHECK(x == ev.max_atomic_counter_buffer_size);
# ifdef GL_MAX_CLIP_DISTANCES
	BOOST_CHECK(x != ev.max_clip_distances);
# endif
# ifdef GL_MAX_COLOR_ATTACHMENTS
	BOOST_CHECK(x != ev.max_color_attachments);
# endif
# ifdef GL_MAX_COLOR_TEXTURE_SAMPLES
	BOOST_CHECK(x != ev.max_color_texture_samples);
# endif
# ifdef GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_combined_atomic_counter_buffers);
# endif
# ifdef GL_MAX_COMBINED_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_combined_atomic_counters);
# endif
# ifdef GL_MAX_COMBINED_CLIP_AND_CULL_DISTANCES
	BOOST_CHECK(x != ev.max_combined_clip_and_cull_distances);
# endif
# ifdef GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_fragment_uniform_components);
# endif
# ifdef GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_geometry_uniform_components);
# endif
# ifdef GL_MAX_COMBINED_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_combined_image_uniforms);
# endif
# ifdef GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS
	BOOST_CHECK(x != ev.max_combined_image_units_and_fragment_outputs);
# endif
# ifdef GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_tess_control_uniform_components);
# endif
# ifdef GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_combined_texture_image_units);
# endif
# ifdef GL_MAX_COMBINED_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_combined_uniform_blocks);
# endif
# ifdef GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_vertex_uniform_components);
# endif
# ifdef GL_MAX_COMPUTE_SHARED_MEMORY_SIZE
	BOOST_CHECK(x != ev.max_compute_shared_memory_size);
# endif
# ifdef GL_MAX_COMPUTE_WORK_GROUP_COUNT
	BOOST_CHECK(x != ev.max_compute_work_group_count);
# endif
# ifdef GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS
	BOOST_CHECK(x != ev.max_compute_work_group_invocations);
# endif
# ifdef GL_MAX_COMPUTE_WORK_GROUP_SIZE
	BOOST_CHECK(x != ev.max_compute_work_group_size);
# endif
# ifdef GL_MAX_CUBE_MAP_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_cube_map_texture_size);
# endif
# ifdef GL_MAX_CULL_DISTANCES
	BOOST_CHECK(x != ev.max_cull_distances);
# endif
# ifdef GL_MAX_DEPTH_TEXTURE_SAMPLES
	BOOST_CHECK(x != ev.max_depth_texture_samples);
# endif
# ifdef GL_MAX_DRAW_BUFFERS
	BOOST_CHECK(x != ev.max_draw_buffers);
# endif
# ifdef GL_MAX_DUAL_SOURCE_DRAW_BUFFERS
	BOOST_CHECK(x != ev.max_dual_source_draw_buffers);
# endif
# ifdef GL_MAX_ELEMENTS_INDICES
	BOOST_CHECK(x != ev.max_elements_indices);
# endif
# ifdef GL_MAX_ELEMENTS_VERTICES
	BOOST_CHECK(x != ev.max_elements_vertices);
# endif
# ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_fragment_atomic_counter_buffers);
# endif
# ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_fragment_atomic_counters);
# endif
# ifdef GL_MAX_FRAGMENT_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_fragment_image_uniforms);
# endif
# ifdef GL_MAX_FRAGMENT_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_input_components);
# endif
# ifdef GL_MAX_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.max_fragment_interpolation_offset);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_fragment_uniform_blocks);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_uniform_components);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_fragment_uniform_vectors);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counter_buffers);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counters);
# endif
# ifdef GL_MAX_GEOMETRY_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_geometry_image_uniforms);
# endif
# ifdef GL_MAX_GEOMETRY_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_input_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_VERTICES
	BOOST_CHECK(x != ev.max_geometry_output_vertices);
# endif
# ifdef GL_MAX_GEOMETRY_SHADER_INVOCATIONS
	BOOST_CHECK(x != ev.max_geometry_shader_invocations);
# endif
# ifdef GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_geometry_texture_image_units);
# endif
# ifdef GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_total_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_geometry_uniform_blocks);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_uniform_components);
# endif
# ifdef GL_MAX_IMAGE_SAMPLES
	BOOST_CHECK(x != ev.max_image_samples);
# endif
# ifdef GL_MAX_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_image_units);
# endif
# ifdef GL_MAX_INTEGER_SAMPLES
	BOOST_CHECK(x != ev.max_integer_samples);
# endif
# ifdef GL_MAX_PATCH_VERTICES
	BOOST_CHECK(x != ev.max_patch_vertices);
# endif
# ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.max_program_texel_offset);
# endif
# ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.max_program_texture_gather_offset);
# endif
# ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_rectangle_texture_size);
# endif
# ifdef GL_MAX_RENDERBUFFER_SIZE
	BOOST_CHECK(x != ev.max_renderbuffer_size);
# endif
# ifdef GL_MAX_SAMPLE_MASK_WORDS
	BOOST_CHECK(x != ev.max_sample_mask_words);
# endif
# ifdef GL_MAX_SAMPLES
	BOOST_CHECK(x != ev.max_samples);
# endif
# ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	BOOST_CHECK(x != ev.max_server_wait_timeout);
# endif
# ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	BOOST_CHECK(x != ev.max_subroutine_uniform_locations);
# endif
# ifdef GL_MAX_SUBROUTINES
	BOOST_CHECK(x != ev.max_subroutines);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_CLIP_DISTANCES
	x = ev.max_clip_distances;
	BOOST_CHECK(x == ev.max_clip_distances);
# ifdef GL_MAX_COLOR_ATTACHMENTS
	BOOST_CHECK(x != ev.max_color_attachments);
# endif
# ifdef GL_MAX_COLOR_TEXTURE_SAMPLES
	BOOST_CHECK(x != ev.max_color_texture_samples);
# endif
# ifdef GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_combined_atomic_counter_buffers);
# endif
# ifdef GL_MAX_COMBINED_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_combined_atomic_counters);
# endif
# ifdef GL_MAX_COMBINED_CLIP_AND_CULL_DISTANCES
	BOOST_CHECK(x != ev.max_combined_clip_and_cull_distances);
# endif
# ifdef GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_fragment_uniform_components);
# endif
# ifdef GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_geometry_uniform_components);
# endif
# ifdef GL_MAX_COMBINED_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_combined_image_uniforms);
# endif
# ifdef GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS
	BOOST_CHECK(x != ev.max_combined_image_units_and_fragment_outputs);
# endif
# ifdef GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_tess_control_uniform_components);
# endif
# ifdef GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_combined_texture_image_units);
# endif
# ifdef GL_MAX_COMBINED_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_combined_uniform_blocks);
# endif
# ifdef GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_vertex_uniform_components);
# endif
# ifdef GL_MAX_COMPUTE_SHARED_MEMORY_SIZE
	BOOST_CHECK(x != ev.max_compute_shared_memory_size);
# endif
# ifdef GL_MAX_COMPUTE_WORK_GROUP_COUNT
	BOOST_CHECK(x != ev.max_compute_work_group_count);
# endif
# ifdef GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS
	BOOST_CHECK(x != ev.max_compute_work_group_invocations);
# endif
# ifdef GL_MAX_COMPUTE_WORK_GROUP_SIZE
	BOOST_CHECK(x != ev.max_compute_work_group_size);
# endif
# ifdef GL_MAX_CUBE_MAP_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_cube_map_texture_size);
# endif
# ifdef GL_MAX_CULL_DISTANCES
	BOOST_CHECK(x != ev.max_cull_distances);
# endif
# ifdef GL_MAX_DEPTH_TEXTURE_SAMPLES
	BOOST_CHECK(x != ev.max_depth_texture_samples);
# endif
# ifdef GL_MAX_DRAW_BUFFERS
	BOOST_CHECK(x != ev.max_draw_buffers);
# endif
# ifdef GL_MAX_DUAL_SOURCE_DRAW_BUFFERS
	BOOST_CHECK(x != ev.max_dual_source_draw_buffers);
# endif
# ifdef GL_MAX_ELEMENTS_INDICES
	BOOST_CHECK(x != ev.max_elements_indices);
# endif
# ifdef GL_MAX_ELEMENTS_VERTICES
	BOOST_CHECK(x != ev.max_elements_vertices);
# endif
# ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_fragment_atomic_counter_buffers);
# endif
# ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_fragment_atomic_counters);
# endif
# ifdef GL_MAX_FRAGMENT_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_fragment_image_uniforms);
# endif
# ifdef GL_MAX_FRAGMENT_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_input_components);
# endif
# ifdef GL_MAX_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.max_fragment_interpolation_offset);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_fragment_uniform_blocks);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_uniform_components);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_fragment_uniform_vectors);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counter_buffers);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counters);
# endif
# ifdef GL_MAX_GEOMETRY_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_geometry_image_uniforms);
# endif
# ifdef GL_MAX_GEOMETRY_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_input_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_VERTICES
	BOOST_CHECK(x != ev.max_geometry_output_vertices);
# endif
# ifdef GL_MAX_GEOMETRY_SHADER_INVOCATIONS
	BOOST_CHECK(x != ev.max_geometry_shader_invocations);
# endif
# ifdef GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_geometry_texture_image_units);
# endif
# ifdef GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_total_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_geometry_uniform_blocks);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_uniform_components);
# endif
# ifdef GL_MAX_IMAGE_SAMPLES
	BOOST_CHECK(x != ev.max_image_samples);
# endif
# ifdef GL_MAX_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_image_units);
# endif
# ifdef GL_MAX_INTEGER_SAMPLES
	BOOST_CHECK(x != ev.max_integer_samples);
# endif
# ifdef GL_MAX_PATCH_VERTICES
	BOOST_CHECK(x != ev.max_patch_vertices);
# endif
# ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.max_program_texel_offset);
# endif
# ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.max_program_texture_gather_offset);
# endif
# ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_rectangle_texture_size);
# endif
# ifdef GL_MAX_RENDERBUFFER_SIZE
	BOOST_CHECK(x != ev.max_renderbuffer_size);
# endif
# ifdef GL_MAX_SAMPLE_MASK_WORDS
	BOOST_CHECK(x != ev.max_sample_mask_words);
# endif
# ifdef GL_MAX_SAMPLES
	BOOST_CHECK(x != ev.max_samples);
# endif
# ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	BOOST_CHECK(x != ev.max_server_wait_timeout);
# endif
# ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	BOOST_CHECK(x != ev.max_subroutine_uniform_locations);
# endif
# ifdef GL_MAX_SUBROUTINES
	BOOST_CHECK(x != ev.max_subroutines);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_COLOR_ATTACHMENTS
	x = ev.max_color_attachments;
	BOOST_CHECK(x == ev.max_color_attachments);
# ifdef GL_MAX_COLOR_TEXTURE_SAMPLES
	BOOST_CHECK(x != ev.max_color_texture_samples);
# endif
# ifdef GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_combined_atomic_counter_buffers);
# endif
# ifdef GL_MAX_COMBINED_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_combined_atomic_counters);
# endif
# ifdef GL_MAX_COMBINED_CLIP_AND_CULL_DISTANCES
	BOOST_CHECK(x != ev.max_combined_clip_and_cull_distances);
# endif
# ifdef GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_fragment_uniform_components);
# endif
# ifdef GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_geometry_uniform_components);
# endif
# ifdef GL_MAX_COMBINED_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_combined_image_uniforms);
# endif
# ifdef GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS
	BOOST_CHECK(x != ev.max_combined_image_units_and_fragment_outputs);
# endif
# ifdef GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_tess_control_uniform_components);
# endif
# ifdef GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_combined_texture_image_units);
# endif
# ifdef GL_MAX_COMBINED_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_combined_uniform_blocks);
# endif
# ifdef GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_vertex_uniform_components);
# endif
# ifdef GL_MAX_COMPUTE_SHARED_MEMORY_SIZE
	BOOST_CHECK(x != ev.max_compute_shared_memory_size);
# endif
# ifdef GL_MAX_COMPUTE_WORK_GROUP_COUNT
	BOOST_CHECK(x != ev.max_compute_work_group_count);
# endif
# ifdef GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS
	BOOST_CHECK(x != ev.max_compute_work_group_invocations);
# endif
# ifdef GL_MAX_COMPUTE_WORK_GROUP_SIZE
	BOOST_CHECK(x != ev.max_compute_work_group_size);
# endif
# ifdef GL_MAX_CUBE_MAP_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_cube_map_texture_size);
# endif
# ifdef GL_MAX_CULL_DISTANCES
	BOOST_CHECK(x != ev.max_cull_distances);
# endif
# ifdef GL_MAX_DEPTH_TEXTURE_SAMPLES
	BOOST_CHECK(x != ev.max_depth_texture_samples);
# endif
# ifdef GL_MAX_DRAW_BUFFERS
	BOOST_CHECK(x != ev.max_draw_buffers);
# endif
# ifdef GL_MAX_DUAL_SOURCE_DRAW_BUFFERS
	BOOST_CHECK(x != ev.max_dual_source_draw_buffers);
# endif
# ifdef GL_MAX_ELEMENTS_INDICES
	BOOST_CHECK(x != ev.max_elements_indices);
# endif
# ifdef GL_MAX_ELEMENTS_VERTICES
	BOOST_CHECK(x != ev.max_elements_vertices);
# endif
# ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_fragment_atomic_counter_buffers);
# endif
# ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_fragment_atomic_counters);
# endif
# ifdef GL_MAX_FRAGMENT_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_fragment_image_uniforms);
# endif
# ifdef GL_MAX_FRAGMENT_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_input_components);
# endif
# ifdef GL_MAX_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.max_fragment_interpolation_offset);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_fragment_uniform_blocks);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_uniform_components);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_fragment_uniform_vectors);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counter_buffers);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counters);
# endif
# ifdef GL_MAX_GEOMETRY_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_geometry_image_uniforms);
# endif
# ifdef GL_MAX_GEOMETRY_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_input_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_VERTICES
	BOOST_CHECK(x != ev.max_geometry_output_vertices);
# endif
# ifdef GL_MAX_GEOMETRY_SHADER_INVOCATIONS
	BOOST_CHECK(x != ev.max_geometry_shader_invocations);
# endif
# ifdef GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_geometry_texture_image_units);
# endif
# ifdef GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_total_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_geometry_uniform_blocks);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_uniform_components);
# endif
# ifdef GL_MAX_IMAGE_SAMPLES
	BOOST_CHECK(x != ev.max_image_samples);
# endif
# ifdef GL_MAX_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_image_units);
# endif
# ifdef GL_MAX_INTEGER_SAMPLES
	BOOST_CHECK(x != ev.max_integer_samples);
# endif
# ifdef GL_MAX_PATCH_VERTICES
	BOOST_CHECK(x != ev.max_patch_vertices);
# endif
# ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.max_program_texel_offset);
# endif
# ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.max_program_texture_gather_offset);
# endif
# ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_rectangle_texture_size);
# endif
# ifdef GL_MAX_RENDERBUFFER_SIZE
	BOOST_CHECK(x != ev.max_renderbuffer_size);
# endif
# ifdef GL_MAX_SAMPLE_MASK_WORDS
	BOOST_CHECK(x != ev.max_sample_mask_words);
# endif
# ifdef GL_MAX_SAMPLES
	BOOST_CHECK(x != ev.max_samples);
# endif
# ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	BOOST_CHECK(x != ev.max_server_wait_timeout);
# endif
# ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	BOOST_CHECK(x != ev.max_subroutine_uniform_locations);
# endif
# ifdef GL_MAX_SUBROUTINES
	BOOST_CHECK(x != ev.max_subroutines);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_COLOR_TEXTURE_SAMPLES
	x = ev.max_color_texture_samples;
	BOOST_CHECK(x == ev.max_color_texture_samples);
# ifdef GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_combined_atomic_counter_buffers);
# endif
# ifdef GL_MAX_COMBINED_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_combined_atomic_counters);
# endif
# ifdef GL_MAX_COMBINED_CLIP_AND_CULL_DISTANCES
	BOOST_CHECK(x != ev.max_combined_clip_and_cull_distances);
# endif
# ifdef GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_fragment_uniform_components);
# endif
# ifdef GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_geometry_uniform_components);
# endif
# ifdef GL_MAX_COMBINED_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_combined_image_uniforms);
# endif
# ifdef GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS
	BOOST_CHECK(x != ev.max_combined_image_units_and_fragment_outputs);
# endif
# ifdef GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_tess_control_uniform_components);
# endif
# ifdef GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_combined_texture_image_units);
# endif
# ifdef GL_MAX_COMBINED_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_combined_uniform_blocks);
# endif
# ifdef GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_vertex_uniform_components);
# endif
# ifdef GL_MAX_COMPUTE_SHARED_MEMORY_SIZE
	BOOST_CHECK(x != ev.max_compute_shared_memory_size);
# endif
# ifdef GL_MAX_COMPUTE_WORK_GROUP_COUNT
	BOOST_CHECK(x != ev.max_compute_work_group_count);
# endif
# ifdef GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS
	BOOST_CHECK(x != ev.max_compute_work_group_invocations);
# endif
# ifdef GL_MAX_COMPUTE_WORK_GROUP_SIZE
	BOOST_CHECK(x != ev.max_compute_work_group_size);
# endif
# ifdef GL_MAX_CUBE_MAP_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_cube_map_texture_size);
# endif
# ifdef GL_MAX_CULL_DISTANCES
	BOOST_CHECK(x != ev.max_cull_distances);
# endif
# ifdef GL_MAX_DEPTH_TEXTURE_SAMPLES
	BOOST_CHECK(x != ev.max_depth_texture_samples);
# endif
# ifdef GL_MAX_DRAW_BUFFERS
	BOOST_CHECK(x != ev.max_draw_buffers);
# endif
# ifdef GL_MAX_DUAL_SOURCE_DRAW_BUFFERS
	BOOST_CHECK(x != ev.max_dual_source_draw_buffers);
# endif
# ifdef GL_MAX_ELEMENTS_INDICES
	BOOST_CHECK(x != ev.max_elements_indices);
# endif
# ifdef GL_MAX_ELEMENTS_VERTICES
	BOOST_CHECK(x != ev.max_elements_vertices);
# endif
# ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_fragment_atomic_counter_buffers);
# endif
# ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_fragment_atomic_counters);
# endif
# ifdef GL_MAX_FRAGMENT_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_fragment_image_uniforms);
# endif
# ifdef GL_MAX_FRAGMENT_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_input_components);
# endif
# ifdef GL_MAX_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.max_fragment_interpolation_offset);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_fragment_uniform_blocks);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_uniform_components);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_fragment_uniform_vectors);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counter_buffers);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counters);
# endif
# ifdef GL_MAX_GEOMETRY_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_geometry_image_uniforms);
# endif
# ifdef GL_MAX_GEOMETRY_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_input_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_VERTICES
	BOOST_CHECK(x != ev.max_geometry_output_vertices);
# endif
# ifdef GL_MAX_GEOMETRY_SHADER_INVOCATIONS
	BOOST_CHECK(x != ev.max_geometry_shader_invocations);
# endif
# ifdef GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_geometry_texture_image_units);
# endif
# ifdef GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_total_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_geometry_uniform_blocks);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_uniform_components);
# endif
# ifdef GL_MAX_IMAGE_SAMPLES
	BOOST_CHECK(x != ev.max_image_samples);
# endif
# ifdef GL_MAX_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_image_units);
# endif
# ifdef GL_MAX_INTEGER_SAMPLES
	BOOST_CHECK(x != ev.max_integer_samples);
# endif
# ifdef GL_MAX_PATCH_VERTICES
	BOOST_CHECK(x != ev.max_patch_vertices);
# endif
# ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.max_program_texel_offset);
# endif
# ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.max_program_texture_gather_offset);
# endif
# ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_rectangle_texture_size);
# endif
# ifdef GL_MAX_RENDERBUFFER_SIZE
	BOOST_CHECK(x != ev.max_renderbuffer_size);
# endif
# ifdef GL_MAX_SAMPLE_MASK_WORDS
	BOOST_CHECK(x != ev.max_sample_mask_words);
# endif
# ifdef GL_MAX_SAMPLES
	BOOST_CHECK(x != ev.max_samples);
# endif
# ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	BOOST_CHECK(x != ev.max_server_wait_timeout);
# endif
# ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	BOOST_CHECK(x != ev.max_subroutine_uniform_locations);
# endif
# ifdef GL_MAX_SUBROUTINES
	BOOST_CHECK(x != ev.max_subroutines);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS
	x = ev.max_combined_atomic_counter_buffers;
	BOOST_CHECK(x == ev.max_combined_atomic_counter_buffers);
# ifdef GL_MAX_COMBINED_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_combined_atomic_counters);
# endif
# ifdef GL_MAX_COMBINED_CLIP_AND_CULL_DISTANCES
	BOOST_CHECK(x != ev.max_combined_clip_and_cull_distances);
# endif
# ifdef GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_fragment_uniform_components);
# endif
# ifdef GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_geometry_uniform_components);
# endif
# ifdef GL_MAX_COMBINED_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_combined_image_uniforms);
# endif
# ifdef GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS
	BOOST_CHECK(x != ev.max_combined_image_units_and_fragment_outputs);
# endif
# ifdef GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_tess_control_uniform_components);
# endif
# ifdef GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_combined_texture_image_units);
# endif
# ifdef GL_MAX_COMBINED_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_combined_uniform_blocks);
# endif
# ifdef GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_vertex_uniform_components);
# endif
# ifdef GL_MAX_COMPUTE_SHARED_MEMORY_SIZE
	BOOST_CHECK(x != ev.max_compute_shared_memory_size);
# endif
# ifdef GL_MAX_COMPUTE_WORK_GROUP_COUNT
	BOOST_CHECK(x != ev.max_compute_work_group_count);
# endif
# ifdef GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS
	BOOST_CHECK(x != ev.max_compute_work_group_invocations);
# endif
# ifdef GL_MAX_COMPUTE_WORK_GROUP_SIZE
	BOOST_CHECK(x != ev.max_compute_work_group_size);
# endif
# ifdef GL_MAX_CUBE_MAP_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_cube_map_texture_size);
# endif
# ifdef GL_MAX_CULL_DISTANCES
	BOOST_CHECK(x != ev.max_cull_distances);
# endif
# ifdef GL_MAX_DEPTH_TEXTURE_SAMPLES
	BOOST_CHECK(x != ev.max_depth_texture_samples);
# endif
# ifdef GL_MAX_DRAW_BUFFERS
	BOOST_CHECK(x != ev.max_draw_buffers);
# endif
# ifdef GL_MAX_DUAL_SOURCE_DRAW_BUFFERS
	BOOST_CHECK(x != ev.max_dual_source_draw_buffers);
# endif
# ifdef GL_MAX_ELEMENTS_INDICES
	BOOST_CHECK(x != ev.max_elements_indices);
# endif
# ifdef GL_MAX_ELEMENTS_VERTICES
	BOOST_CHECK(x != ev.max_elements_vertices);
# endif
# ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_fragment_atomic_counter_buffers);
# endif
# ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_fragment_atomic_counters);
# endif
# ifdef GL_MAX_FRAGMENT_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_fragment_image_uniforms);
# endif
# ifdef GL_MAX_FRAGMENT_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_input_components);
# endif
# ifdef GL_MAX_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.max_fragment_interpolation_offset);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_fragment_uniform_blocks);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_uniform_components);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_fragment_uniform_vectors);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counter_buffers);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counters);
# endif
# ifdef GL_MAX_GEOMETRY_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_geometry_image_uniforms);
# endif
# ifdef GL_MAX_GEOMETRY_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_input_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_VERTICES
	BOOST_CHECK(x != ev.max_geometry_output_vertices);
# endif
# ifdef GL_MAX_GEOMETRY_SHADER_INVOCATIONS
	BOOST_CHECK(x != ev.max_geometry_shader_invocations);
# endif
# ifdef GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_geometry_texture_image_units);
# endif
# ifdef GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_total_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_geometry_uniform_blocks);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_uniform_components);
# endif
# ifdef GL_MAX_IMAGE_SAMPLES
	BOOST_CHECK(x != ev.max_image_samples);
# endif
# ifdef GL_MAX_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_image_units);
# endif
# ifdef GL_MAX_INTEGER_SAMPLES
	BOOST_CHECK(x != ev.max_integer_samples);
# endif
# ifdef GL_MAX_PATCH_VERTICES
	BOOST_CHECK(x != ev.max_patch_vertices);
# endif
# ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.max_program_texel_offset);
# endif
# ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.max_program_texture_gather_offset);
# endif
# ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_rectangle_texture_size);
# endif
# ifdef GL_MAX_RENDERBUFFER_SIZE
	BOOST_CHECK(x != ev.max_renderbuffer_size);
# endif
# ifdef GL_MAX_SAMPLE_MASK_WORDS
	BOOST_CHECK(x != ev.max_sample_mask_words);
# endif
# ifdef GL_MAX_SAMPLES
	BOOST_CHECK(x != ev.max_samples);
# endif
# ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	BOOST_CHECK(x != ev.max_server_wait_timeout);
# endif
# ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	BOOST_CHECK(x != ev.max_subroutine_uniform_locations);
# endif
# ifdef GL_MAX_SUBROUTINES
	BOOST_CHECK(x != ev.max_subroutines);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_COMBINED_ATOMIC_COUNTERS
	x = ev.max_combined_atomic_counters;
	BOOST_CHECK(x == ev.max_combined_atomic_counters);
# ifdef GL_MAX_COMBINED_CLIP_AND_CULL_DISTANCES
	BOOST_CHECK(x != ev.max_combined_clip_and_cull_distances);
# endif
# ifdef GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_fragment_uniform_components);
# endif
# ifdef GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_geometry_uniform_components);
# endif
# ifdef GL_MAX_COMBINED_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_combined_image_uniforms);
# endif
# ifdef GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS
	BOOST_CHECK(x != ev.max_combined_image_units_and_fragment_outputs);
# endif
# ifdef GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_tess_control_uniform_components);
# endif
# ifdef GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_combined_texture_image_units);
# endif
# ifdef GL_MAX_COMBINED_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_combined_uniform_blocks);
# endif
# ifdef GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_vertex_uniform_components);
# endif
# ifdef GL_MAX_COMPUTE_SHARED_MEMORY_SIZE
	BOOST_CHECK(x != ev.max_compute_shared_memory_size);
# endif
# ifdef GL_MAX_COMPUTE_WORK_GROUP_COUNT
	BOOST_CHECK(x != ev.max_compute_work_group_count);
# endif
# ifdef GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS
	BOOST_CHECK(x != ev.max_compute_work_group_invocations);
# endif
# ifdef GL_MAX_COMPUTE_WORK_GROUP_SIZE
	BOOST_CHECK(x != ev.max_compute_work_group_size);
# endif
# ifdef GL_MAX_CUBE_MAP_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_cube_map_texture_size);
# endif
# ifdef GL_MAX_CULL_DISTANCES
	BOOST_CHECK(x != ev.max_cull_distances);
# endif
# ifdef GL_MAX_DEPTH_TEXTURE_SAMPLES
	BOOST_CHECK(x != ev.max_depth_texture_samples);
# endif
# ifdef GL_MAX_DRAW_BUFFERS
	BOOST_CHECK(x != ev.max_draw_buffers);
# endif
# ifdef GL_MAX_DUAL_SOURCE_DRAW_BUFFERS
	BOOST_CHECK(x != ev.max_dual_source_draw_buffers);
# endif
# ifdef GL_MAX_ELEMENTS_INDICES
	BOOST_CHECK(x != ev.max_elements_indices);
# endif
# ifdef GL_MAX_ELEMENTS_VERTICES
	BOOST_CHECK(x != ev.max_elements_vertices);
# endif
# ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_fragment_atomic_counter_buffers);
# endif
# ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_fragment_atomic_counters);
# endif
# ifdef GL_MAX_FRAGMENT_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_fragment_image_uniforms);
# endif
# ifdef GL_MAX_FRAGMENT_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_input_components);
# endif
# ifdef GL_MAX_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.max_fragment_interpolation_offset);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_fragment_uniform_blocks);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_uniform_components);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_fragment_uniform_vectors);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counter_buffers);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counters);
# endif
# ifdef GL_MAX_GEOMETRY_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_geometry_image_uniforms);
# endif
# ifdef GL_MAX_GEOMETRY_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_input_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_VERTICES
	BOOST_CHECK(x != ev.max_geometry_output_vertices);
# endif
# ifdef GL_MAX_GEOMETRY_SHADER_INVOCATIONS
	BOOST_CHECK(x != ev.max_geometry_shader_invocations);
# endif
# ifdef GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_geometry_texture_image_units);
# endif
# ifdef GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_total_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_geometry_uniform_blocks);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_uniform_components);
# endif
# ifdef GL_MAX_IMAGE_SAMPLES
	BOOST_CHECK(x != ev.max_image_samples);
# endif
# ifdef GL_MAX_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_image_units);
# endif
# ifdef GL_MAX_INTEGER_SAMPLES
	BOOST_CHECK(x != ev.max_integer_samples);
# endif
# ifdef GL_MAX_PATCH_VERTICES
	BOOST_CHECK(x != ev.max_patch_vertices);
# endif
# ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.max_program_texel_offset);
# endif
# ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.max_program_texture_gather_offset);
# endif
# ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_rectangle_texture_size);
# endif
# ifdef GL_MAX_RENDERBUFFER_SIZE
	BOOST_CHECK(x != ev.max_renderbuffer_size);
# endif
# ifdef GL_MAX_SAMPLE_MASK_WORDS
	BOOST_CHECK(x != ev.max_sample_mask_words);
# endif
# ifdef GL_MAX_SAMPLES
	BOOST_CHECK(x != ev.max_samples);
# endif
# ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	BOOST_CHECK(x != ev.max_server_wait_timeout);
# endif
# ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	BOOST_CHECK(x != ev.max_subroutine_uniform_locations);
# endif
# ifdef GL_MAX_SUBROUTINES
	BOOST_CHECK(x != ev.max_subroutines);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_COMBINED_CLIP_AND_CULL_DISTANCES
	x = ev.max_combined_clip_and_cull_distances;
	BOOST_CHECK(x == ev.max_combined_clip_and_cull_distances);
# ifdef GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_fragment_uniform_components);
# endif
# ifdef GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_geometry_uniform_components);
# endif
# ifdef GL_MAX_COMBINED_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_combined_image_uniforms);
# endif
# ifdef GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS
	BOOST_CHECK(x != ev.max_combined_image_units_and_fragment_outputs);
# endif
# ifdef GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_tess_control_uniform_components);
# endif
# ifdef GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_combined_texture_image_units);
# endif
# ifdef GL_MAX_COMBINED_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_combined_uniform_blocks);
# endif
# ifdef GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_vertex_uniform_components);
# endif
# ifdef GL_MAX_COMPUTE_SHARED_MEMORY_SIZE
	BOOST_CHECK(x != ev.max_compute_shared_memory_size);
# endif
# ifdef GL_MAX_COMPUTE_WORK_GROUP_COUNT
	BOOST_CHECK(x != ev.max_compute_work_group_count);
# endif
# ifdef GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS
	BOOST_CHECK(x != ev.max_compute_work_group_invocations);
# endif
# ifdef GL_MAX_COMPUTE_WORK_GROUP_SIZE
	BOOST_CHECK(x != ev.max_compute_work_group_size);
# endif
# ifdef GL_MAX_CUBE_MAP_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_cube_map_texture_size);
# endif
# ifdef GL_MAX_CULL_DISTANCES
	BOOST_CHECK(x != ev.max_cull_distances);
# endif
# ifdef GL_MAX_DEPTH_TEXTURE_SAMPLES
	BOOST_CHECK(x != ev.max_depth_texture_samples);
# endif
# ifdef GL_MAX_DRAW_BUFFERS
	BOOST_CHECK(x != ev.max_draw_buffers);
# endif
# ifdef GL_MAX_DUAL_SOURCE_DRAW_BUFFERS
	BOOST_CHECK(x != ev.max_dual_source_draw_buffers);
# endif
# ifdef GL_MAX_ELEMENTS_INDICES
	BOOST_CHECK(x != ev.max_elements_indices);
# endif
# ifdef GL_MAX_ELEMENTS_VERTICES
	BOOST_CHECK(x != ev.max_elements_vertices);
# endif
# ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_fragment_atomic_counter_buffers);
# endif
# ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_fragment_atomic_counters);
# endif
# ifdef GL_MAX_FRAGMENT_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_fragment_image_uniforms);
# endif
# ifdef GL_MAX_FRAGMENT_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_input_components);
# endif
# ifdef GL_MAX_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.max_fragment_interpolation_offset);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_fragment_uniform_blocks);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_uniform_components);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_fragment_uniform_vectors);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counter_buffers);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counters);
# endif
# ifdef GL_MAX_GEOMETRY_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_geometry_image_uniforms);
# endif
# ifdef GL_MAX_GEOMETRY_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_input_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_VERTICES
	BOOST_CHECK(x != ev.max_geometry_output_vertices);
# endif
# ifdef GL_MAX_GEOMETRY_SHADER_INVOCATIONS
	BOOST_CHECK(x != ev.max_geometry_shader_invocations);
# endif
# ifdef GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_geometry_texture_image_units);
# endif
# ifdef GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_total_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_geometry_uniform_blocks);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_uniform_components);
# endif
# ifdef GL_MAX_IMAGE_SAMPLES
	BOOST_CHECK(x != ev.max_image_samples);
# endif
# ifdef GL_MAX_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_image_units);
# endif
# ifdef GL_MAX_INTEGER_SAMPLES
	BOOST_CHECK(x != ev.max_integer_samples);
# endif
# ifdef GL_MAX_PATCH_VERTICES
	BOOST_CHECK(x != ev.max_patch_vertices);
# endif
# ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.max_program_texel_offset);
# endif
# ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.max_program_texture_gather_offset);
# endif
# ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_rectangle_texture_size);
# endif
# ifdef GL_MAX_RENDERBUFFER_SIZE
	BOOST_CHECK(x != ev.max_renderbuffer_size);
# endif
# ifdef GL_MAX_SAMPLE_MASK_WORDS
	BOOST_CHECK(x != ev.max_sample_mask_words);
# endif
# ifdef GL_MAX_SAMPLES
	BOOST_CHECK(x != ev.max_samples);
# endif
# ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	BOOST_CHECK(x != ev.max_server_wait_timeout);
# endif
# ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	BOOST_CHECK(x != ev.max_subroutine_uniform_locations);
# endif
# ifdef GL_MAX_SUBROUTINES
	BOOST_CHECK(x != ev.max_subroutines);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS
	x = ev.max_combined_fragment_uniform_components;
	BOOST_CHECK(x == ev.max_combined_fragment_uniform_components);
# ifdef GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_geometry_uniform_components);
# endif
# ifdef GL_MAX_COMBINED_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_combined_image_uniforms);
# endif
# ifdef GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS
	BOOST_CHECK(x != ev.max_combined_image_units_and_fragment_outputs);
# endif
# ifdef GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_tess_control_uniform_components);
# endif
# ifdef GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_combined_texture_image_units);
# endif
# ifdef GL_MAX_COMBINED_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_combined_uniform_blocks);
# endif
# ifdef GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_vertex_uniform_components);
# endif
# ifdef GL_MAX_COMPUTE_SHARED_MEMORY_SIZE
	BOOST_CHECK(x != ev.max_compute_shared_memory_size);
# endif
# ifdef GL_MAX_COMPUTE_WORK_GROUP_COUNT
	BOOST_CHECK(x != ev.max_compute_work_group_count);
# endif
# ifdef GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS
	BOOST_CHECK(x != ev.max_compute_work_group_invocations);
# endif
# ifdef GL_MAX_COMPUTE_WORK_GROUP_SIZE
	BOOST_CHECK(x != ev.max_compute_work_group_size);
# endif
# ifdef GL_MAX_CUBE_MAP_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_cube_map_texture_size);
# endif
# ifdef GL_MAX_CULL_DISTANCES
	BOOST_CHECK(x != ev.max_cull_distances);
# endif
# ifdef GL_MAX_DEPTH_TEXTURE_SAMPLES
	BOOST_CHECK(x != ev.max_depth_texture_samples);
# endif
# ifdef GL_MAX_DRAW_BUFFERS
	BOOST_CHECK(x != ev.max_draw_buffers);
# endif
# ifdef GL_MAX_DUAL_SOURCE_DRAW_BUFFERS
	BOOST_CHECK(x != ev.max_dual_source_draw_buffers);
# endif
# ifdef GL_MAX_ELEMENTS_INDICES
	BOOST_CHECK(x != ev.max_elements_indices);
# endif
# ifdef GL_MAX_ELEMENTS_VERTICES
	BOOST_CHECK(x != ev.max_elements_vertices);
# endif
# ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_fragment_atomic_counter_buffers);
# endif
# ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_fragment_atomic_counters);
# endif
# ifdef GL_MAX_FRAGMENT_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_fragment_image_uniforms);
# endif
# ifdef GL_MAX_FRAGMENT_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_input_components);
# endif
# ifdef GL_MAX_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.max_fragment_interpolation_offset);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_fragment_uniform_blocks);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_uniform_components);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_fragment_uniform_vectors);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counter_buffers);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counters);
# endif
# ifdef GL_MAX_GEOMETRY_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_geometry_image_uniforms);
# endif
# ifdef GL_MAX_GEOMETRY_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_input_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_VERTICES
	BOOST_CHECK(x != ev.max_geometry_output_vertices);
# endif
# ifdef GL_MAX_GEOMETRY_SHADER_INVOCATIONS
	BOOST_CHECK(x != ev.max_geometry_shader_invocations);
# endif
# ifdef GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_geometry_texture_image_units);
# endif
# ifdef GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_total_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_geometry_uniform_blocks);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_uniform_components);
# endif
# ifdef GL_MAX_IMAGE_SAMPLES
	BOOST_CHECK(x != ev.max_image_samples);
# endif
# ifdef GL_MAX_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_image_units);
# endif
# ifdef GL_MAX_INTEGER_SAMPLES
	BOOST_CHECK(x != ev.max_integer_samples);
# endif
# ifdef GL_MAX_PATCH_VERTICES
	BOOST_CHECK(x != ev.max_patch_vertices);
# endif
# ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.max_program_texel_offset);
# endif
# ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.max_program_texture_gather_offset);
# endif
# ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_rectangle_texture_size);
# endif
# ifdef GL_MAX_RENDERBUFFER_SIZE
	BOOST_CHECK(x != ev.max_renderbuffer_size);
# endif
# ifdef GL_MAX_SAMPLE_MASK_WORDS
	BOOST_CHECK(x != ev.max_sample_mask_words);
# endif
# ifdef GL_MAX_SAMPLES
	BOOST_CHECK(x != ev.max_samples);
# endif
# ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	BOOST_CHECK(x != ev.max_server_wait_timeout);
# endif
# ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	BOOST_CHECK(x != ev.max_subroutine_uniform_locations);
# endif
# ifdef GL_MAX_SUBROUTINES
	BOOST_CHECK(x != ev.max_subroutines);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS
	x = ev.max_combined_geometry_uniform_components;
	BOOST_CHECK(x == ev.max_combined_geometry_uniform_components);
# ifdef GL_MAX_COMBINED_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_combined_image_uniforms);
# endif
# ifdef GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS
	BOOST_CHECK(x != ev.max_combined_image_units_and_fragment_outputs);
# endif
# ifdef GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_tess_control_uniform_components);
# endif
# ifdef GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_combined_texture_image_units);
# endif
# ifdef GL_MAX_COMBINED_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_combined_uniform_blocks);
# endif
# ifdef GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_vertex_uniform_components);
# endif
# ifdef GL_MAX_COMPUTE_SHARED_MEMORY_SIZE
	BOOST_CHECK(x != ev.max_compute_shared_memory_size);
# endif
# ifdef GL_MAX_COMPUTE_WORK_GROUP_COUNT
	BOOST_CHECK(x != ev.max_compute_work_group_count);
# endif
# ifdef GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS
	BOOST_CHECK(x != ev.max_compute_work_group_invocations);
# endif
# ifdef GL_MAX_COMPUTE_WORK_GROUP_SIZE
	BOOST_CHECK(x != ev.max_compute_work_group_size);
# endif
# ifdef GL_MAX_CUBE_MAP_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_cube_map_texture_size);
# endif
# ifdef GL_MAX_CULL_DISTANCES
	BOOST_CHECK(x != ev.max_cull_distances);
# endif
# ifdef GL_MAX_DEPTH_TEXTURE_SAMPLES
	BOOST_CHECK(x != ev.max_depth_texture_samples);
# endif
# ifdef GL_MAX_DRAW_BUFFERS
	BOOST_CHECK(x != ev.max_draw_buffers);
# endif
# ifdef GL_MAX_DUAL_SOURCE_DRAW_BUFFERS
	BOOST_CHECK(x != ev.max_dual_source_draw_buffers);
# endif
# ifdef GL_MAX_ELEMENTS_INDICES
	BOOST_CHECK(x != ev.max_elements_indices);
# endif
# ifdef GL_MAX_ELEMENTS_VERTICES
	BOOST_CHECK(x != ev.max_elements_vertices);
# endif
# ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_fragment_atomic_counter_buffers);
# endif
# ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_fragment_atomic_counters);
# endif
# ifdef GL_MAX_FRAGMENT_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_fragment_image_uniforms);
# endif
# ifdef GL_MAX_FRAGMENT_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_input_components);
# endif
# ifdef GL_MAX_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.max_fragment_interpolation_offset);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_fragment_uniform_blocks);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_uniform_components);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_fragment_uniform_vectors);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counter_buffers);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counters);
# endif
# ifdef GL_MAX_GEOMETRY_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_geometry_image_uniforms);
# endif
# ifdef GL_MAX_GEOMETRY_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_input_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_VERTICES
	BOOST_CHECK(x != ev.max_geometry_output_vertices);
# endif
# ifdef GL_MAX_GEOMETRY_SHADER_INVOCATIONS
	BOOST_CHECK(x != ev.max_geometry_shader_invocations);
# endif
# ifdef GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_geometry_texture_image_units);
# endif
# ifdef GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_total_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_geometry_uniform_blocks);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_uniform_components);
# endif
# ifdef GL_MAX_IMAGE_SAMPLES
	BOOST_CHECK(x != ev.max_image_samples);
# endif
# ifdef GL_MAX_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_image_units);
# endif
# ifdef GL_MAX_INTEGER_SAMPLES
	BOOST_CHECK(x != ev.max_integer_samples);
# endif
# ifdef GL_MAX_PATCH_VERTICES
	BOOST_CHECK(x != ev.max_patch_vertices);
# endif
# ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.max_program_texel_offset);
# endif
# ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.max_program_texture_gather_offset);
# endif
# ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_rectangle_texture_size);
# endif
# ifdef GL_MAX_RENDERBUFFER_SIZE
	BOOST_CHECK(x != ev.max_renderbuffer_size);
# endif
# ifdef GL_MAX_SAMPLE_MASK_WORDS
	BOOST_CHECK(x != ev.max_sample_mask_words);
# endif
# ifdef GL_MAX_SAMPLES
	BOOST_CHECK(x != ev.max_samples);
# endif
# ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	BOOST_CHECK(x != ev.max_server_wait_timeout);
# endif
# ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	BOOST_CHECK(x != ev.max_subroutine_uniform_locations);
# endif
# ifdef GL_MAX_SUBROUTINES
	BOOST_CHECK(x != ev.max_subroutines);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_COMBINED_IMAGE_UNIFORMS
	x = ev.max_combined_image_uniforms;
	BOOST_CHECK(x == ev.max_combined_image_uniforms);
# ifdef GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS
	BOOST_CHECK(x != ev.max_combined_image_units_and_fragment_outputs);
# endif
# ifdef GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_tess_control_uniform_components);
# endif
# ifdef GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_combined_texture_image_units);
# endif
# ifdef GL_MAX_COMBINED_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_combined_uniform_blocks);
# endif
# ifdef GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_vertex_uniform_components);
# endif
# ifdef GL_MAX_COMPUTE_SHARED_MEMORY_SIZE
	BOOST_CHECK(x != ev.max_compute_shared_memory_size);
# endif
# ifdef GL_MAX_COMPUTE_WORK_GROUP_COUNT
	BOOST_CHECK(x != ev.max_compute_work_group_count);
# endif
# ifdef GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS
	BOOST_CHECK(x != ev.max_compute_work_group_invocations);
# endif
# ifdef GL_MAX_COMPUTE_WORK_GROUP_SIZE
	BOOST_CHECK(x != ev.max_compute_work_group_size);
# endif
# ifdef GL_MAX_CUBE_MAP_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_cube_map_texture_size);
# endif
# ifdef GL_MAX_CULL_DISTANCES
	BOOST_CHECK(x != ev.max_cull_distances);
# endif
# ifdef GL_MAX_DEPTH_TEXTURE_SAMPLES
	BOOST_CHECK(x != ev.max_depth_texture_samples);
# endif
# ifdef GL_MAX_DRAW_BUFFERS
	BOOST_CHECK(x != ev.max_draw_buffers);
# endif
# ifdef GL_MAX_DUAL_SOURCE_DRAW_BUFFERS
	BOOST_CHECK(x != ev.max_dual_source_draw_buffers);
# endif
# ifdef GL_MAX_ELEMENTS_INDICES
	BOOST_CHECK(x != ev.max_elements_indices);
# endif
# ifdef GL_MAX_ELEMENTS_VERTICES
	BOOST_CHECK(x != ev.max_elements_vertices);
# endif
# ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_fragment_atomic_counter_buffers);
# endif
# ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_fragment_atomic_counters);
# endif
# ifdef GL_MAX_FRAGMENT_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_fragment_image_uniforms);
# endif
# ifdef GL_MAX_FRAGMENT_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_input_components);
# endif
# ifdef GL_MAX_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.max_fragment_interpolation_offset);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_fragment_uniform_blocks);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_uniform_components);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_fragment_uniform_vectors);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counter_buffers);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counters);
# endif
# ifdef GL_MAX_GEOMETRY_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_geometry_image_uniforms);
# endif
# ifdef GL_MAX_GEOMETRY_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_input_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_VERTICES
	BOOST_CHECK(x != ev.max_geometry_output_vertices);
# endif
# ifdef GL_MAX_GEOMETRY_SHADER_INVOCATIONS
	BOOST_CHECK(x != ev.max_geometry_shader_invocations);
# endif
# ifdef GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_geometry_texture_image_units);
# endif
# ifdef GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_total_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_geometry_uniform_blocks);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_uniform_components);
# endif
# ifdef GL_MAX_IMAGE_SAMPLES
	BOOST_CHECK(x != ev.max_image_samples);
# endif
# ifdef GL_MAX_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_image_units);
# endif
# ifdef GL_MAX_INTEGER_SAMPLES
	BOOST_CHECK(x != ev.max_integer_samples);
# endif
# ifdef GL_MAX_PATCH_VERTICES
	BOOST_CHECK(x != ev.max_patch_vertices);
# endif
# ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.max_program_texel_offset);
# endif
# ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.max_program_texture_gather_offset);
# endif
# ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_rectangle_texture_size);
# endif
# ifdef GL_MAX_RENDERBUFFER_SIZE
	BOOST_CHECK(x != ev.max_renderbuffer_size);
# endif
# ifdef GL_MAX_SAMPLE_MASK_WORDS
	BOOST_CHECK(x != ev.max_sample_mask_words);
# endif
# ifdef GL_MAX_SAMPLES
	BOOST_CHECK(x != ev.max_samples);
# endif
# ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	BOOST_CHECK(x != ev.max_server_wait_timeout);
# endif
# ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	BOOST_CHECK(x != ev.max_subroutine_uniform_locations);
# endif
# ifdef GL_MAX_SUBROUTINES
	BOOST_CHECK(x != ev.max_subroutines);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS
	x = ev.max_combined_image_units_and_fragment_outputs;
	BOOST_CHECK(x == ev.max_combined_image_units_and_fragment_outputs);
# ifdef GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_tess_control_uniform_components);
# endif
# ifdef GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_combined_texture_image_units);
# endif
# ifdef GL_MAX_COMBINED_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_combined_uniform_blocks);
# endif
# ifdef GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_vertex_uniform_components);
# endif
# ifdef GL_MAX_COMPUTE_SHARED_MEMORY_SIZE
	BOOST_CHECK(x != ev.max_compute_shared_memory_size);
# endif
# ifdef GL_MAX_COMPUTE_WORK_GROUP_COUNT
	BOOST_CHECK(x != ev.max_compute_work_group_count);
# endif
# ifdef GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS
	BOOST_CHECK(x != ev.max_compute_work_group_invocations);
# endif
# ifdef GL_MAX_COMPUTE_WORK_GROUP_SIZE
	BOOST_CHECK(x != ev.max_compute_work_group_size);
# endif
# ifdef GL_MAX_CUBE_MAP_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_cube_map_texture_size);
# endif
# ifdef GL_MAX_CULL_DISTANCES
	BOOST_CHECK(x != ev.max_cull_distances);
# endif
# ifdef GL_MAX_DEPTH_TEXTURE_SAMPLES
	BOOST_CHECK(x != ev.max_depth_texture_samples);
# endif
# ifdef GL_MAX_DRAW_BUFFERS
	BOOST_CHECK(x != ev.max_draw_buffers);
# endif
# ifdef GL_MAX_DUAL_SOURCE_DRAW_BUFFERS
	BOOST_CHECK(x != ev.max_dual_source_draw_buffers);
# endif
# ifdef GL_MAX_ELEMENTS_INDICES
	BOOST_CHECK(x != ev.max_elements_indices);
# endif
# ifdef GL_MAX_ELEMENTS_VERTICES
	BOOST_CHECK(x != ev.max_elements_vertices);
# endif
# ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_fragment_atomic_counter_buffers);
# endif
# ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_fragment_atomic_counters);
# endif
# ifdef GL_MAX_FRAGMENT_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_fragment_image_uniforms);
# endif
# ifdef GL_MAX_FRAGMENT_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_input_components);
# endif
# ifdef GL_MAX_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.max_fragment_interpolation_offset);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_fragment_uniform_blocks);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_uniform_components);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_fragment_uniform_vectors);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counter_buffers);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counters);
# endif
# ifdef GL_MAX_GEOMETRY_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_geometry_image_uniforms);
# endif
# ifdef GL_MAX_GEOMETRY_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_input_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_VERTICES
	BOOST_CHECK(x != ev.max_geometry_output_vertices);
# endif
# ifdef GL_MAX_GEOMETRY_SHADER_INVOCATIONS
	BOOST_CHECK(x != ev.max_geometry_shader_invocations);
# endif
# ifdef GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_geometry_texture_image_units);
# endif
# ifdef GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_total_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_geometry_uniform_blocks);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_uniform_components);
# endif
# ifdef GL_MAX_IMAGE_SAMPLES
	BOOST_CHECK(x != ev.max_image_samples);
# endif
# ifdef GL_MAX_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_image_units);
# endif
# ifdef GL_MAX_INTEGER_SAMPLES
	BOOST_CHECK(x != ev.max_integer_samples);
# endif
# ifdef GL_MAX_PATCH_VERTICES
	BOOST_CHECK(x != ev.max_patch_vertices);
# endif
# ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.max_program_texel_offset);
# endif
# ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.max_program_texture_gather_offset);
# endif
# ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_rectangle_texture_size);
# endif
# ifdef GL_MAX_RENDERBUFFER_SIZE
	BOOST_CHECK(x != ev.max_renderbuffer_size);
# endif
# ifdef GL_MAX_SAMPLE_MASK_WORDS
	BOOST_CHECK(x != ev.max_sample_mask_words);
# endif
# ifdef GL_MAX_SAMPLES
	BOOST_CHECK(x != ev.max_samples);
# endif
# ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	BOOST_CHECK(x != ev.max_server_wait_timeout);
# endif
# ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	BOOST_CHECK(x != ev.max_subroutine_uniform_locations);
# endif
# ifdef GL_MAX_SUBROUTINES
	BOOST_CHECK(x != ev.max_subroutines);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS
	x = ev.max_combined_tess_control_uniform_components;
	BOOST_CHECK(x == ev.max_combined_tess_control_uniform_components);
# ifdef GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_combined_texture_image_units);
# endif
# ifdef GL_MAX_COMBINED_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_combined_uniform_blocks);
# endif
# ifdef GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_vertex_uniform_components);
# endif
# ifdef GL_MAX_COMPUTE_SHARED_MEMORY_SIZE
	BOOST_CHECK(x != ev.max_compute_shared_memory_size);
# endif
# ifdef GL_MAX_COMPUTE_WORK_GROUP_COUNT
	BOOST_CHECK(x != ev.max_compute_work_group_count);
# endif
# ifdef GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS
	BOOST_CHECK(x != ev.max_compute_work_group_invocations);
# endif
# ifdef GL_MAX_COMPUTE_WORK_GROUP_SIZE
	BOOST_CHECK(x != ev.max_compute_work_group_size);
# endif
# ifdef GL_MAX_CUBE_MAP_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_cube_map_texture_size);
# endif
# ifdef GL_MAX_CULL_DISTANCES
	BOOST_CHECK(x != ev.max_cull_distances);
# endif
# ifdef GL_MAX_DEPTH_TEXTURE_SAMPLES
	BOOST_CHECK(x != ev.max_depth_texture_samples);
# endif
# ifdef GL_MAX_DRAW_BUFFERS
	BOOST_CHECK(x != ev.max_draw_buffers);
# endif
# ifdef GL_MAX_DUAL_SOURCE_DRAW_BUFFERS
	BOOST_CHECK(x != ev.max_dual_source_draw_buffers);
# endif
# ifdef GL_MAX_ELEMENTS_INDICES
	BOOST_CHECK(x != ev.max_elements_indices);
# endif
# ifdef GL_MAX_ELEMENTS_VERTICES
	BOOST_CHECK(x != ev.max_elements_vertices);
# endif
# ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_fragment_atomic_counter_buffers);
# endif
# ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_fragment_atomic_counters);
# endif
# ifdef GL_MAX_FRAGMENT_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_fragment_image_uniforms);
# endif
# ifdef GL_MAX_FRAGMENT_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_input_components);
# endif
# ifdef GL_MAX_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.max_fragment_interpolation_offset);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_fragment_uniform_blocks);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_uniform_components);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_fragment_uniform_vectors);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counter_buffers);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counters);
# endif
# ifdef GL_MAX_GEOMETRY_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_geometry_image_uniforms);
# endif
# ifdef GL_MAX_GEOMETRY_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_input_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_VERTICES
	BOOST_CHECK(x != ev.max_geometry_output_vertices);
# endif
# ifdef GL_MAX_GEOMETRY_SHADER_INVOCATIONS
	BOOST_CHECK(x != ev.max_geometry_shader_invocations);
# endif
# ifdef GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_geometry_texture_image_units);
# endif
# ifdef GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_total_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_geometry_uniform_blocks);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_uniform_components);
# endif
# ifdef GL_MAX_IMAGE_SAMPLES
	BOOST_CHECK(x != ev.max_image_samples);
# endif
# ifdef GL_MAX_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_image_units);
# endif
# ifdef GL_MAX_INTEGER_SAMPLES
	BOOST_CHECK(x != ev.max_integer_samples);
# endif
# ifdef GL_MAX_PATCH_VERTICES
	BOOST_CHECK(x != ev.max_patch_vertices);
# endif
# ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.max_program_texel_offset);
# endif
# ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.max_program_texture_gather_offset);
# endif
# ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_rectangle_texture_size);
# endif
# ifdef GL_MAX_RENDERBUFFER_SIZE
	BOOST_CHECK(x != ev.max_renderbuffer_size);
# endif
# ifdef GL_MAX_SAMPLE_MASK_WORDS
	BOOST_CHECK(x != ev.max_sample_mask_words);
# endif
# ifdef GL_MAX_SAMPLES
	BOOST_CHECK(x != ev.max_samples);
# endif
# ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	BOOST_CHECK(x != ev.max_server_wait_timeout);
# endif
# ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	BOOST_CHECK(x != ev.max_subroutine_uniform_locations);
# endif
# ifdef GL_MAX_SUBROUTINES
	BOOST_CHECK(x != ev.max_subroutines);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS
	x = ev.max_combined_tess_evaluation_uniform_components;
	BOOST_CHECK(x == ev.max_combined_tess_evaluation_uniform_components);
# ifdef GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_combined_texture_image_units);
# endif
# ifdef GL_MAX_COMBINED_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_combined_uniform_blocks);
# endif
# ifdef GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_vertex_uniform_components);
# endif
# ifdef GL_MAX_COMPUTE_SHARED_MEMORY_SIZE
	BOOST_CHECK(x != ev.max_compute_shared_memory_size);
# endif
# ifdef GL_MAX_COMPUTE_WORK_GROUP_COUNT
	BOOST_CHECK(x != ev.max_compute_work_group_count);
# endif
# ifdef GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS
	BOOST_CHECK(x != ev.max_compute_work_group_invocations);
# endif
# ifdef GL_MAX_COMPUTE_WORK_GROUP_SIZE
	BOOST_CHECK(x != ev.max_compute_work_group_size);
# endif
# ifdef GL_MAX_CUBE_MAP_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_cube_map_texture_size);
# endif
# ifdef GL_MAX_CULL_DISTANCES
	BOOST_CHECK(x != ev.max_cull_distances);
# endif
# ifdef GL_MAX_DEPTH_TEXTURE_SAMPLES
	BOOST_CHECK(x != ev.max_depth_texture_samples);
# endif
# ifdef GL_MAX_DRAW_BUFFERS
	BOOST_CHECK(x != ev.max_draw_buffers);
# endif
# ifdef GL_MAX_DUAL_SOURCE_DRAW_BUFFERS
	BOOST_CHECK(x != ev.max_dual_source_draw_buffers);
# endif
# ifdef GL_MAX_ELEMENTS_INDICES
	BOOST_CHECK(x != ev.max_elements_indices);
# endif
# ifdef GL_MAX_ELEMENTS_VERTICES
	BOOST_CHECK(x != ev.max_elements_vertices);
# endif
# ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_fragment_atomic_counter_buffers);
# endif
# ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_fragment_atomic_counters);
# endif
# ifdef GL_MAX_FRAGMENT_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_fragment_image_uniforms);
# endif
# ifdef GL_MAX_FRAGMENT_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_input_components);
# endif
# ifdef GL_MAX_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.max_fragment_interpolation_offset);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_fragment_uniform_blocks);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_uniform_components);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_fragment_uniform_vectors);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counter_buffers);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counters);
# endif
# ifdef GL_MAX_GEOMETRY_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_geometry_image_uniforms);
# endif
# ifdef GL_MAX_GEOMETRY_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_input_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_VERTICES
	BOOST_CHECK(x != ev.max_geometry_output_vertices);
# endif
# ifdef GL_MAX_GEOMETRY_SHADER_INVOCATIONS
	BOOST_CHECK(x != ev.max_geometry_shader_invocations);
# endif
# ifdef GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_geometry_texture_image_units);
# endif
# ifdef GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_total_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_geometry_uniform_blocks);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_uniform_components);
# endif
# ifdef GL_MAX_IMAGE_SAMPLES
	BOOST_CHECK(x != ev.max_image_samples);
# endif
# ifdef GL_MAX_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_image_units);
# endif
# ifdef GL_MAX_INTEGER_SAMPLES
	BOOST_CHECK(x != ev.max_integer_samples);
# endif
# ifdef GL_MAX_PATCH_VERTICES
	BOOST_CHECK(x != ev.max_patch_vertices);
# endif
# ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.max_program_texel_offset);
# endif
# ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.max_program_texture_gather_offset);
# endif
# ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_rectangle_texture_size);
# endif
# ifdef GL_MAX_RENDERBUFFER_SIZE
	BOOST_CHECK(x != ev.max_renderbuffer_size);
# endif
# ifdef GL_MAX_SAMPLE_MASK_WORDS
	BOOST_CHECK(x != ev.max_sample_mask_words);
# endif
# ifdef GL_MAX_SAMPLES
	BOOST_CHECK(x != ev.max_samples);
# endif
# ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	BOOST_CHECK(x != ev.max_server_wait_timeout);
# endif
# ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	BOOST_CHECK(x != ev.max_subroutine_uniform_locations);
# endif
# ifdef GL_MAX_SUBROUTINES
	BOOST_CHECK(x != ev.max_subroutines);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS
	x = ev.max_combined_texture_image_units;
	BOOST_CHECK(x == ev.max_combined_texture_image_units);
# ifdef GL_MAX_COMBINED_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_combined_uniform_blocks);
# endif
# ifdef GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_vertex_uniform_components);
# endif
# ifdef GL_MAX_COMPUTE_SHARED_MEMORY_SIZE
	BOOST_CHECK(x != ev.max_compute_shared_memory_size);
# endif
# ifdef GL_MAX_COMPUTE_WORK_GROUP_COUNT
	BOOST_CHECK(x != ev.max_compute_work_group_count);
# endif
# ifdef GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS
	BOOST_CHECK(x != ev.max_compute_work_group_invocations);
# endif
# ifdef GL_MAX_COMPUTE_WORK_GROUP_SIZE
	BOOST_CHECK(x != ev.max_compute_work_group_size);
# endif
# ifdef GL_MAX_CUBE_MAP_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_cube_map_texture_size);
# endif
# ifdef GL_MAX_CULL_DISTANCES
	BOOST_CHECK(x != ev.max_cull_distances);
# endif
# ifdef GL_MAX_DEPTH_TEXTURE_SAMPLES
	BOOST_CHECK(x != ev.max_depth_texture_samples);
# endif
# ifdef GL_MAX_DRAW_BUFFERS
	BOOST_CHECK(x != ev.max_draw_buffers);
# endif
# ifdef GL_MAX_DUAL_SOURCE_DRAW_BUFFERS
	BOOST_CHECK(x != ev.max_dual_source_draw_buffers);
# endif
# ifdef GL_MAX_ELEMENTS_INDICES
	BOOST_CHECK(x != ev.max_elements_indices);
# endif
# ifdef GL_MAX_ELEMENTS_VERTICES
	BOOST_CHECK(x != ev.max_elements_vertices);
# endif
# ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_fragment_atomic_counter_buffers);
# endif
# ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_fragment_atomic_counters);
# endif
# ifdef GL_MAX_FRAGMENT_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_fragment_image_uniforms);
# endif
# ifdef GL_MAX_FRAGMENT_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_input_components);
# endif
# ifdef GL_MAX_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.max_fragment_interpolation_offset);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_fragment_uniform_blocks);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_uniform_components);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_fragment_uniform_vectors);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counter_buffers);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counters);
# endif
# ifdef GL_MAX_GEOMETRY_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_geometry_image_uniforms);
# endif
# ifdef GL_MAX_GEOMETRY_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_input_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_VERTICES
	BOOST_CHECK(x != ev.max_geometry_output_vertices);
# endif
# ifdef GL_MAX_GEOMETRY_SHADER_INVOCATIONS
	BOOST_CHECK(x != ev.max_geometry_shader_invocations);
# endif
# ifdef GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_geometry_texture_image_units);
# endif
# ifdef GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_total_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_geometry_uniform_blocks);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_uniform_components);
# endif
# ifdef GL_MAX_IMAGE_SAMPLES
	BOOST_CHECK(x != ev.max_image_samples);
# endif
# ifdef GL_MAX_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_image_units);
# endif
# ifdef GL_MAX_INTEGER_SAMPLES
	BOOST_CHECK(x != ev.max_integer_samples);
# endif
# ifdef GL_MAX_PATCH_VERTICES
	BOOST_CHECK(x != ev.max_patch_vertices);
# endif
# ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.max_program_texel_offset);
# endif
# ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.max_program_texture_gather_offset);
# endif
# ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_rectangle_texture_size);
# endif
# ifdef GL_MAX_RENDERBUFFER_SIZE
	BOOST_CHECK(x != ev.max_renderbuffer_size);
# endif
# ifdef GL_MAX_SAMPLE_MASK_WORDS
	BOOST_CHECK(x != ev.max_sample_mask_words);
# endif
# ifdef GL_MAX_SAMPLES
	BOOST_CHECK(x != ev.max_samples);
# endif
# ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	BOOST_CHECK(x != ev.max_server_wait_timeout);
# endif
# ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	BOOST_CHECK(x != ev.max_subroutine_uniform_locations);
# endif
# ifdef GL_MAX_SUBROUTINES
	BOOST_CHECK(x != ev.max_subroutines);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_COMBINED_UNIFORM_BLOCKS
	x = ev.max_combined_uniform_blocks;
	BOOST_CHECK(x == ev.max_combined_uniform_blocks);
# ifdef GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_combined_vertex_uniform_components);
# endif
# ifdef GL_MAX_COMPUTE_SHARED_MEMORY_SIZE
	BOOST_CHECK(x != ev.max_compute_shared_memory_size);
# endif
# ifdef GL_MAX_COMPUTE_WORK_GROUP_COUNT
	BOOST_CHECK(x != ev.max_compute_work_group_count);
# endif
# ifdef GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS
	BOOST_CHECK(x != ev.max_compute_work_group_invocations);
# endif
# ifdef GL_MAX_COMPUTE_WORK_GROUP_SIZE
	BOOST_CHECK(x != ev.max_compute_work_group_size);
# endif
# ifdef GL_MAX_CUBE_MAP_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_cube_map_texture_size);
# endif
# ifdef GL_MAX_CULL_DISTANCES
	BOOST_CHECK(x != ev.max_cull_distances);
# endif
# ifdef GL_MAX_DEPTH_TEXTURE_SAMPLES
	BOOST_CHECK(x != ev.max_depth_texture_samples);
# endif
# ifdef GL_MAX_DRAW_BUFFERS
	BOOST_CHECK(x != ev.max_draw_buffers);
# endif
# ifdef GL_MAX_DUAL_SOURCE_DRAW_BUFFERS
	BOOST_CHECK(x != ev.max_dual_source_draw_buffers);
# endif
# ifdef GL_MAX_ELEMENTS_INDICES
	BOOST_CHECK(x != ev.max_elements_indices);
# endif
# ifdef GL_MAX_ELEMENTS_VERTICES
	BOOST_CHECK(x != ev.max_elements_vertices);
# endif
# ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_fragment_atomic_counter_buffers);
# endif
# ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_fragment_atomic_counters);
# endif
# ifdef GL_MAX_FRAGMENT_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_fragment_image_uniforms);
# endif
# ifdef GL_MAX_FRAGMENT_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_input_components);
# endif
# ifdef GL_MAX_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.max_fragment_interpolation_offset);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_fragment_uniform_blocks);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_uniform_components);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_fragment_uniform_vectors);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counter_buffers);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counters);
# endif
# ifdef GL_MAX_GEOMETRY_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_geometry_image_uniforms);
# endif
# ifdef GL_MAX_GEOMETRY_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_input_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_VERTICES
	BOOST_CHECK(x != ev.max_geometry_output_vertices);
# endif
# ifdef GL_MAX_GEOMETRY_SHADER_INVOCATIONS
	BOOST_CHECK(x != ev.max_geometry_shader_invocations);
# endif
# ifdef GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_geometry_texture_image_units);
# endif
# ifdef GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_total_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_geometry_uniform_blocks);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_uniform_components);
# endif
# ifdef GL_MAX_IMAGE_SAMPLES
	BOOST_CHECK(x != ev.max_image_samples);
# endif
# ifdef GL_MAX_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_image_units);
# endif
# ifdef GL_MAX_INTEGER_SAMPLES
	BOOST_CHECK(x != ev.max_integer_samples);
# endif
# ifdef GL_MAX_PATCH_VERTICES
	BOOST_CHECK(x != ev.max_patch_vertices);
# endif
# ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.max_program_texel_offset);
# endif
# ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.max_program_texture_gather_offset);
# endif
# ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_rectangle_texture_size);
# endif
# ifdef GL_MAX_RENDERBUFFER_SIZE
	BOOST_CHECK(x != ev.max_renderbuffer_size);
# endif
# ifdef GL_MAX_SAMPLE_MASK_WORDS
	BOOST_CHECK(x != ev.max_sample_mask_words);
# endif
# ifdef GL_MAX_SAMPLES
	BOOST_CHECK(x != ev.max_samples);
# endif
# ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	BOOST_CHECK(x != ev.max_server_wait_timeout);
# endif
# ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	BOOST_CHECK(x != ev.max_subroutine_uniform_locations);
# endif
# ifdef GL_MAX_SUBROUTINES
	BOOST_CHECK(x != ev.max_subroutines);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS
	x = ev.max_combined_vertex_uniform_components;
	BOOST_CHECK(x == ev.max_combined_vertex_uniform_components);
# ifdef GL_MAX_COMPUTE_SHARED_MEMORY_SIZE
	BOOST_CHECK(x != ev.max_compute_shared_memory_size);
# endif
# ifdef GL_MAX_COMPUTE_WORK_GROUP_COUNT
	BOOST_CHECK(x != ev.max_compute_work_group_count);
# endif
# ifdef GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS
	BOOST_CHECK(x != ev.max_compute_work_group_invocations);
# endif
# ifdef GL_MAX_COMPUTE_WORK_GROUP_SIZE
	BOOST_CHECK(x != ev.max_compute_work_group_size);
# endif
# ifdef GL_MAX_CUBE_MAP_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_cube_map_texture_size);
# endif
# ifdef GL_MAX_CULL_DISTANCES
	BOOST_CHECK(x != ev.max_cull_distances);
# endif
# ifdef GL_MAX_DEPTH_TEXTURE_SAMPLES
	BOOST_CHECK(x != ev.max_depth_texture_samples);
# endif
# ifdef GL_MAX_DRAW_BUFFERS
	BOOST_CHECK(x != ev.max_draw_buffers);
# endif
# ifdef GL_MAX_DUAL_SOURCE_DRAW_BUFFERS
	BOOST_CHECK(x != ev.max_dual_source_draw_buffers);
# endif
# ifdef GL_MAX_ELEMENTS_INDICES
	BOOST_CHECK(x != ev.max_elements_indices);
# endif
# ifdef GL_MAX_ELEMENTS_VERTICES
	BOOST_CHECK(x != ev.max_elements_vertices);
# endif
# ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_fragment_atomic_counter_buffers);
# endif
# ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_fragment_atomic_counters);
# endif
# ifdef GL_MAX_FRAGMENT_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_fragment_image_uniforms);
# endif
# ifdef GL_MAX_FRAGMENT_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_input_components);
# endif
# ifdef GL_MAX_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.max_fragment_interpolation_offset);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_fragment_uniform_blocks);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_uniform_components);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_fragment_uniform_vectors);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counter_buffers);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counters);
# endif
# ifdef GL_MAX_GEOMETRY_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_geometry_image_uniforms);
# endif
# ifdef GL_MAX_GEOMETRY_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_input_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_VERTICES
	BOOST_CHECK(x != ev.max_geometry_output_vertices);
# endif
# ifdef GL_MAX_GEOMETRY_SHADER_INVOCATIONS
	BOOST_CHECK(x != ev.max_geometry_shader_invocations);
# endif
# ifdef GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_geometry_texture_image_units);
# endif
# ifdef GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_total_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_geometry_uniform_blocks);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_uniform_components);
# endif
# ifdef GL_MAX_IMAGE_SAMPLES
	BOOST_CHECK(x != ev.max_image_samples);
# endif
# ifdef GL_MAX_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_image_units);
# endif
# ifdef GL_MAX_INTEGER_SAMPLES
	BOOST_CHECK(x != ev.max_integer_samples);
# endif
# ifdef GL_MAX_PATCH_VERTICES
	BOOST_CHECK(x != ev.max_patch_vertices);
# endif
# ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.max_program_texel_offset);
# endif
# ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.max_program_texture_gather_offset);
# endif
# ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_rectangle_texture_size);
# endif
# ifdef GL_MAX_RENDERBUFFER_SIZE
	BOOST_CHECK(x != ev.max_renderbuffer_size);
# endif
# ifdef GL_MAX_SAMPLE_MASK_WORDS
	BOOST_CHECK(x != ev.max_sample_mask_words);
# endif
# ifdef GL_MAX_SAMPLES
	BOOST_CHECK(x != ev.max_samples);
# endif
# ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	BOOST_CHECK(x != ev.max_server_wait_timeout);
# endif
# ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	BOOST_CHECK(x != ev.max_subroutine_uniform_locations);
# endif
# ifdef GL_MAX_SUBROUTINES
	BOOST_CHECK(x != ev.max_subroutines);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_COMPUTE_SHARED_MEMORY_SIZE
	x = ev.max_compute_shared_memory_size;
	BOOST_CHECK(x == ev.max_compute_shared_memory_size);
# ifdef GL_MAX_COMPUTE_WORK_GROUP_COUNT
	BOOST_CHECK(x != ev.max_compute_work_group_count);
# endif
# ifdef GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS
	BOOST_CHECK(x != ev.max_compute_work_group_invocations);
# endif
# ifdef GL_MAX_COMPUTE_WORK_GROUP_SIZE
	BOOST_CHECK(x != ev.max_compute_work_group_size);
# endif
# ifdef GL_MAX_CUBE_MAP_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_cube_map_texture_size);
# endif
# ifdef GL_MAX_CULL_DISTANCES
	BOOST_CHECK(x != ev.max_cull_distances);
# endif
# ifdef GL_MAX_DEPTH_TEXTURE_SAMPLES
	BOOST_CHECK(x != ev.max_depth_texture_samples);
# endif
# ifdef GL_MAX_DRAW_BUFFERS
	BOOST_CHECK(x != ev.max_draw_buffers);
# endif
# ifdef GL_MAX_DUAL_SOURCE_DRAW_BUFFERS
	BOOST_CHECK(x != ev.max_dual_source_draw_buffers);
# endif
# ifdef GL_MAX_ELEMENTS_INDICES
	BOOST_CHECK(x != ev.max_elements_indices);
# endif
# ifdef GL_MAX_ELEMENTS_VERTICES
	BOOST_CHECK(x != ev.max_elements_vertices);
# endif
# ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_fragment_atomic_counter_buffers);
# endif
# ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_fragment_atomic_counters);
# endif
# ifdef GL_MAX_FRAGMENT_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_fragment_image_uniforms);
# endif
# ifdef GL_MAX_FRAGMENT_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_input_components);
# endif
# ifdef GL_MAX_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.max_fragment_interpolation_offset);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_fragment_uniform_blocks);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_uniform_components);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_fragment_uniform_vectors);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counter_buffers);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counters);
# endif
# ifdef GL_MAX_GEOMETRY_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_geometry_image_uniforms);
# endif
# ifdef GL_MAX_GEOMETRY_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_input_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_VERTICES
	BOOST_CHECK(x != ev.max_geometry_output_vertices);
# endif
# ifdef GL_MAX_GEOMETRY_SHADER_INVOCATIONS
	BOOST_CHECK(x != ev.max_geometry_shader_invocations);
# endif
# ifdef GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_geometry_texture_image_units);
# endif
# ifdef GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_total_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_geometry_uniform_blocks);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_uniform_components);
# endif
# ifdef GL_MAX_IMAGE_SAMPLES
	BOOST_CHECK(x != ev.max_image_samples);
# endif
# ifdef GL_MAX_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_image_units);
# endif
# ifdef GL_MAX_INTEGER_SAMPLES
	BOOST_CHECK(x != ev.max_integer_samples);
# endif
# ifdef GL_MAX_PATCH_VERTICES
	BOOST_CHECK(x != ev.max_patch_vertices);
# endif
# ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.max_program_texel_offset);
# endif
# ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.max_program_texture_gather_offset);
# endif
# ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_rectangle_texture_size);
# endif
# ifdef GL_MAX_RENDERBUFFER_SIZE
	BOOST_CHECK(x != ev.max_renderbuffer_size);
# endif
# ifdef GL_MAX_SAMPLE_MASK_WORDS
	BOOST_CHECK(x != ev.max_sample_mask_words);
# endif
# ifdef GL_MAX_SAMPLES
	BOOST_CHECK(x != ev.max_samples);
# endif
# ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	BOOST_CHECK(x != ev.max_server_wait_timeout);
# endif
# ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	BOOST_CHECK(x != ev.max_subroutine_uniform_locations);
# endif
# ifdef GL_MAX_SUBROUTINES
	BOOST_CHECK(x != ev.max_subroutines);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_COMPUTE_WORK_GROUP_COUNT
	x = ev.max_compute_work_group_count;
	BOOST_CHECK(x == ev.max_compute_work_group_count);
# ifdef GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS
	BOOST_CHECK(x != ev.max_compute_work_group_invocations);
# endif
# ifdef GL_MAX_COMPUTE_WORK_GROUP_SIZE
	BOOST_CHECK(x != ev.max_compute_work_group_size);
# endif
# ifdef GL_MAX_CUBE_MAP_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_cube_map_texture_size);
# endif
# ifdef GL_MAX_CULL_DISTANCES
	BOOST_CHECK(x != ev.max_cull_distances);
# endif
# ifdef GL_MAX_DEPTH_TEXTURE_SAMPLES
	BOOST_CHECK(x != ev.max_depth_texture_samples);
# endif
# ifdef GL_MAX_DRAW_BUFFERS
	BOOST_CHECK(x != ev.max_draw_buffers);
# endif
# ifdef GL_MAX_DUAL_SOURCE_DRAW_BUFFERS
	BOOST_CHECK(x != ev.max_dual_source_draw_buffers);
# endif
# ifdef GL_MAX_ELEMENTS_INDICES
	BOOST_CHECK(x != ev.max_elements_indices);
# endif
# ifdef GL_MAX_ELEMENTS_VERTICES
	BOOST_CHECK(x != ev.max_elements_vertices);
# endif
# ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_fragment_atomic_counter_buffers);
# endif
# ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_fragment_atomic_counters);
# endif
# ifdef GL_MAX_FRAGMENT_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_fragment_image_uniforms);
# endif
# ifdef GL_MAX_FRAGMENT_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_input_components);
# endif
# ifdef GL_MAX_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.max_fragment_interpolation_offset);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_fragment_uniform_blocks);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_uniform_components);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_fragment_uniform_vectors);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counter_buffers);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counters);
# endif
# ifdef GL_MAX_GEOMETRY_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_geometry_image_uniforms);
# endif
# ifdef GL_MAX_GEOMETRY_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_input_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_VERTICES
	BOOST_CHECK(x != ev.max_geometry_output_vertices);
# endif
# ifdef GL_MAX_GEOMETRY_SHADER_INVOCATIONS
	BOOST_CHECK(x != ev.max_geometry_shader_invocations);
# endif
# ifdef GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_geometry_texture_image_units);
# endif
# ifdef GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_total_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_geometry_uniform_blocks);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_uniform_components);
# endif
# ifdef GL_MAX_IMAGE_SAMPLES
	BOOST_CHECK(x != ev.max_image_samples);
# endif
# ifdef GL_MAX_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_image_units);
# endif
# ifdef GL_MAX_INTEGER_SAMPLES
	BOOST_CHECK(x != ev.max_integer_samples);
# endif
# ifdef GL_MAX_PATCH_VERTICES
	BOOST_CHECK(x != ev.max_patch_vertices);
# endif
# ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.max_program_texel_offset);
# endif
# ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.max_program_texture_gather_offset);
# endif
# ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_rectangle_texture_size);
# endif
# ifdef GL_MAX_RENDERBUFFER_SIZE
	BOOST_CHECK(x != ev.max_renderbuffer_size);
# endif
# ifdef GL_MAX_SAMPLE_MASK_WORDS
	BOOST_CHECK(x != ev.max_sample_mask_words);
# endif
# ifdef GL_MAX_SAMPLES
	BOOST_CHECK(x != ev.max_samples);
# endif
# ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	BOOST_CHECK(x != ev.max_server_wait_timeout);
# endif
# ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	BOOST_CHECK(x != ev.max_subroutine_uniform_locations);
# endif
# ifdef GL_MAX_SUBROUTINES
	BOOST_CHECK(x != ev.max_subroutines);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS
	x = ev.max_compute_work_group_invocations;
	BOOST_CHECK(x == ev.max_compute_work_group_invocations);
# ifdef GL_MAX_COMPUTE_WORK_GROUP_SIZE
	BOOST_CHECK(x != ev.max_compute_work_group_size);
# endif
# ifdef GL_MAX_CUBE_MAP_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_cube_map_texture_size);
# endif
# ifdef GL_MAX_CULL_DISTANCES
	BOOST_CHECK(x != ev.max_cull_distances);
# endif
# ifdef GL_MAX_DEPTH_TEXTURE_SAMPLES
	BOOST_CHECK(x != ev.max_depth_texture_samples);
# endif
# ifdef GL_MAX_DRAW_BUFFERS
	BOOST_CHECK(x != ev.max_draw_buffers);
# endif
# ifdef GL_MAX_DUAL_SOURCE_DRAW_BUFFERS
	BOOST_CHECK(x != ev.max_dual_source_draw_buffers);
# endif
# ifdef GL_MAX_ELEMENTS_INDICES
	BOOST_CHECK(x != ev.max_elements_indices);
# endif
# ifdef GL_MAX_ELEMENTS_VERTICES
	BOOST_CHECK(x != ev.max_elements_vertices);
# endif
# ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_fragment_atomic_counter_buffers);
# endif
# ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_fragment_atomic_counters);
# endif
# ifdef GL_MAX_FRAGMENT_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_fragment_image_uniforms);
# endif
# ifdef GL_MAX_FRAGMENT_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_input_components);
# endif
# ifdef GL_MAX_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.max_fragment_interpolation_offset);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_fragment_uniform_blocks);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_uniform_components);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_fragment_uniform_vectors);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counter_buffers);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counters);
# endif
# ifdef GL_MAX_GEOMETRY_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_geometry_image_uniforms);
# endif
# ifdef GL_MAX_GEOMETRY_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_input_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_VERTICES
	BOOST_CHECK(x != ev.max_geometry_output_vertices);
# endif
# ifdef GL_MAX_GEOMETRY_SHADER_INVOCATIONS
	BOOST_CHECK(x != ev.max_geometry_shader_invocations);
# endif
# ifdef GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_geometry_texture_image_units);
# endif
# ifdef GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_total_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_geometry_uniform_blocks);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_uniform_components);
# endif
# ifdef GL_MAX_IMAGE_SAMPLES
	BOOST_CHECK(x != ev.max_image_samples);
# endif
# ifdef GL_MAX_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_image_units);
# endif
# ifdef GL_MAX_INTEGER_SAMPLES
	BOOST_CHECK(x != ev.max_integer_samples);
# endif
# ifdef GL_MAX_PATCH_VERTICES
	BOOST_CHECK(x != ev.max_patch_vertices);
# endif
# ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.max_program_texel_offset);
# endif
# ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.max_program_texture_gather_offset);
# endif
# ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_rectangle_texture_size);
# endif
# ifdef GL_MAX_RENDERBUFFER_SIZE
	BOOST_CHECK(x != ev.max_renderbuffer_size);
# endif
# ifdef GL_MAX_SAMPLE_MASK_WORDS
	BOOST_CHECK(x != ev.max_sample_mask_words);
# endif
# ifdef GL_MAX_SAMPLES
	BOOST_CHECK(x != ev.max_samples);
# endif
# ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	BOOST_CHECK(x != ev.max_server_wait_timeout);
# endif
# ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	BOOST_CHECK(x != ev.max_subroutine_uniform_locations);
# endif
# ifdef GL_MAX_SUBROUTINES
	BOOST_CHECK(x != ev.max_subroutines);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_COMPUTE_WORK_GROUP_SIZE
	x = ev.max_compute_work_group_size;
	BOOST_CHECK(x == ev.max_compute_work_group_size);
# ifdef GL_MAX_CUBE_MAP_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_cube_map_texture_size);
# endif
# ifdef GL_MAX_CULL_DISTANCES
	BOOST_CHECK(x != ev.max_cull_distances);
# endif
# ifdef GL_MAX_DEPTH_TEXTURE_SAMPLES
	BOOST_CHECK(x != ev.max_depth_texture_samples);
# endif
# ifdef GL_MAX_DRAW_BUFFERS
	BOOST_CHECK(x != ev.max_draw_buffers);
# endif
# ifdef GL_MAX_DUAL_SOURCE_DRAW_BUFFERS
	BOOST_CHECK(x != ev.max_dual_source_draw_buffers);
# endif
# ifdef GL_MAX_ELEMENTS_INDICES
	BOOST_CHECK(x != ev.max_elements_indices);
# endif
# ifdef GL_MAX_ELEMENTS_VERTICES
	BOOST_CHECK(x != ev.max_elements_vertices);
# endif
# ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_fragment_atomic_counter_buffers);
# endif
# ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_fragment_atomic_counters);
# endif
# ifdef GL_MAX_FRAGMENT_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_fragment_image_uniforms);
# endif
# ifdef GL_MAX_FRAGMENT_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_input_components);
# endif
# ifdef GL_MAX_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.max_fragment_interpolation_offset);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_fragment_uniform_blocks);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_uniform_components);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_fragment_uniform_vectors);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counter_buffers);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counters);
# endif
# ifdef GL_MAX_GEOMETRY_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_geometry_image_uniforms);
# endif
# ifdef GL_MAX_GEOMETRY_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_input_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_VERTICES
	BOOST_CHECK(x != ev.max_geometry_output_vertices);
# endif
# ifdef GL_MAX_GEOMETRY_SHADER_INVOCATIONS
	BOOST_CHECK(x != ev.max_geometry_shader_invocations);
# endif
# ifdef GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_geometry_texture_image_units);
# endif
# ifdef GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_total_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_geometry_uniform_blocks);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_uniform_components);
# endif
# ifdef GL_MAX_IMAGE_SAMPLES
	BOOST_CHECK(x != ev.max_image_samples);
# endif
# ifdef GL_MAX_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_image_units);
# endif
# ifdef GL_MAX_INTEGER_SAMPLES
	BOOST_CHECK(x != ev.max_integer_samples);
# endif
# ifdef GL_MAX_PATCH_VERTICES
	BOOST_CHECK(x != ev.max_patch_vertices);
# endif
# ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.max_program_texel_offset);
# endif
# ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.max_program_texture_gather_offset);
# endif
# ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_rectangle_texture_size);
# endif
# ifdef GL_MAX_RENDERBUFFER_SIZE
	BOOST_CHECK(x != ev.max_renderbuffer_size);
# endif
# ifdef GL_MAX_SAMPLE_MASK_WORDS
	BOOST_CHECK(x != ev.max_sample_mask_words);
# endif
# ifdef GL_MAX_SAMPLES
	BOOST_CHECK(x != ev.max_samples);
# endif
# ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	BOOST_CHECK(x != ev.max_server_wait_timeout);
# endif
# ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	BOOST_CHECK(x != ev.max_subroutine_uniform_locations);
# endif
# ifdef GL_MAX_SUBROUTINES
	BOOST_CHECK(x != ev.max_subroutines);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_CUBE_MAP_TEXTURE_SIZE
	x = ev.max_cube_map_texture_size;
	BOOST_CHECK(x == ev.max_cube_map_texture_size);
# ifdef GL_MAX_CULL_DISTANCES
	BOOST_CHECK(x != ev.max_cull_distances);
# endif
# ifdef GL_MAX_DEPTH_TEXTURE_SAMPLES
	BOOST_CHECK(x != ev.max_depth_texture_samples);
# endif
# ifdef GL_MAX_DRAW_BUFFERS
	BOOST_CHECK(x != ev.max_draw_buffers);
# endif
# ifdef GL_MAX_DUAL_SOURCE_DRAW_BUFFERS
	BOOST_CHECK(x != ev.max_dual_source_draw_buffers);
# endif
# ifdef GL_MAX_ELEMENTS_INDICES
	BOOST_CHECK(x != ev.max_elements_indices);
# endif
# ifdef GL_MAX_ELEMENTS_VERTICES
	BOOST_CHECK(x != ev.max_elements_vertices);
# endif
# ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_fragment_atomic_counter_buffers);
# endif
# ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_fragment_atomic_counters);
# endif
# ifdef GL_MAX_FRAGMENT_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_fragment_image_uniforms);
# endif
# ifdef GL_MAX_FRAGMENT_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_input_components);
# endif
# ifdef GL_MAX_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.max_fragment_interpolation_offset);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_fragment_uniform_blocks);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_uniform_components);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_fragment_uniform_vectors);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counter_buffers);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counters);
# endif
# ifdef GL_MAX_GEOMETRY_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_geometry_image_uniforms);
# endif
# ifdef GL_MAX_GEOMETRY_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_input_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_VERTICES
	BOOST_CHECK(x != ev.max_geometry_output_vertices);
# endif
# ifdef GL_MAX_GEOMETRY_SHADER_INVOCATIONS
	BOOST_CHECK(x != ev.max_geometry_shader_invocations);
# endif
# ifdef GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_geometry_texture_image_units);
# endif
# ifdef GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_total_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_geometry_uniform_blocks);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_uniform_components);
# endif
# ifdef GL_MAX_IMAGE_SAMPLES
	BOOST_CHECK(x != ev.max_image_samples);
# endif
# ifdef GL_MAX_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_image_units);
# endif
# ifdef GL_MAX_INTEGER_SAMPLES
	BOOST_CHECK(x != ev.max_integer_samples);
# endif
# ifdef GL_MAX_PATCH_VERTICES
	BOOST_CHECK(x != ev.max_patch_vertices);
# endif
# ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.max_program_texel_offset);
# endif
# ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.max_program_texture_gather_offset);
# endif
# ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_rectangle_texture_size);
# endif
# ifdef GL_MAX_RENDERBUFFER_SIZE
	BOOST_CHECK(x != ev.max_renderbuffer_size);
# endif
# ifdef GL_MAX_SAMPLE_MASK_WORDS
	BOOST_CHECK(x != ev.max_sample_mask_words);
# endif
# ifdef GL_MAX_SAMPLES
	BOOST_CHECK(x != ev.max_samples);
# endif
# ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	BOOST_CHECK(x != ev.max_server_wait_timeout);
# endif
# ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	BOOST_CHECK(x != ev.max_subroutine_uniform_locations);
# endif
# ifdef GL_MAX_SUBROUTINES
	BOOST_CHECK(x != ev.max_subroutines);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_CULL_DISTANCES
	x = ev.max_cull_distances;
	BOOST_CHECK(x == ev.max_cull_distances);
# ifdef GL_MAX_DEPTH_TEXTURE_SAMPLES
	BOOST_CHECK(x != ev.max_depth_texture_samples);
# endif
# ifdef GL_MAX_DRAW_BUFFERS
	BOOST_CHECK(x != ev.max_draw_buffers);
# endif
# ifdef GL_MAX_DUAL_SOURCE_DRAW_BUFFERS
	BOOST_CHECK(x != ev.max_dual_source_draw_buffers);
# endif
# ifdef GL_MAX_ELEMENTS_INDICES
	BOOST_CHECK(x != ev.max_elements_indices);
# endif
# ifdef GL_MAX_ELEMENTS_VERTICES
	BOOST_CHECK(x != ev.max_elements_vertices);
# endif
# ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_fragment_atomic_counter_buffers);
# endif
# ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_fragment_atomic_counters);
# endif
# ifdef GL_MAX_FRAGMENT_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_fragment_image_uniforms);
# endif
# ifdef GL_MAX_FRAGMENT_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_input_components);
# endif
# ifdef GL_MAX_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.max_fragment_interpolation_offset);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_fragment_uniform_blocks);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_uniform_components);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_fragment_uniform_vectors);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counter_buffers);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counters);
# endif
# ifdef GL_MAX_GEOMETRY_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_geometry_image_uniforms);
# endif
# ifdef GL_MAX_GEOMETRY_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_input_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_VERTICES
	BOOST_CHECK(x != ev.max_geometry_output_vertices);
# endif
# ifdef GL_MAX_GEOMETRY_SHADER_INVOCATIONS
	BOOST_CHECK(x != ev.max_geometry_shader_invocations);
# endif
# ifdef GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_geometry_texture_image_units);
# endif
# ifdef GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_total_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_geometry_uniform_blocks);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_uniform_components);
# endif
# ifdef GL_MAX_IMAGE_SAMPLES
	BOOST_CHECK(x != ev.max_image_samples);
# endif
# ifdef GL_MAX_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_image_units);
# endif
# ifdef GL_MAX_INTEGER_SAMPLES
	BOOST_CHECK(x != ev.max_integer_samples);
# endif
# ifdef GL_MAX_PATCH_VERTICES
	BOOST_CHECK(x != ev.max_patch_vertices);
# endif
# ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.max_program_texel_offset);
# endif
# ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.max_program_texture_gather_offset);
# endif
# ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_rectangle_texture_size);
# endif
# ifdef GL_MAX_RENDERBUFFER_SIZE
	BOOST_CHECK(x != ev.max_renderbuffer_size);
# endif
# ifdef GL_MAX_SAMPLE_MASK_WORDS
	BOOST_CHECK(x != ev.max_sample_mask_words);
# endif
# ifdef GL_MAX_SAMPLES
	BOOST_CHECK(x != ev.max_samples);
# endif
# ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	BOOST_CHECK(x != ev.max_server_wait_timeout);
# endif
# ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	BOOST_CHECK(x != ev.max_subroutine_uniform_locations);
# endif
# ifdef GL_MAX_SUBROUTINES
	BOOST_CHECK(x != ev.max_subroutines);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_DEPTH_TEXTURE_SAMPLES
	x = ev.max_depth_texture_samples;
	BOOST_CHECK(x == ev.max_depth_texture_samples);
# ifdef GL_MAX_DRAW_BUFFERS
	BOOST_CHECK(x != ev.max_draw_buffers);
# endif
# ifdef GL_MAX_DUAL_SOURCE_DRAW_BUFFERS
	BOOST_CHECK(x != ev.max_dual_source_draw_buffers);
# endif
# ifdef GL_MAX_ELEMENTS_INDICES
	BOOST_CHECK(x != ev.max_elements_indices);
# endif
# ifdef GL_MAX_ELEMENTS_VERTICES
	BOOST_CHECK(x != ev.max_elements_vertices);
# endif
# ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_fragment_atomic_counter_buffers);
# endif
# ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_fragment_atomic_counters);
# endif
# ifdef GL_MAX_FRAGMENT_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_fragment_image_uniforms);
# endif
# ifdef GL_MAX_FRAGMENT_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_input_components);
# endif
# ifdef GL_MAX_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.max_fragment_interpolation_offset);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_fragment_uniform_blocks);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_uniform_components);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_fragment_uniform_vectors);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counter_buffers);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counters);
# endif
# ifdef GL_MAX_GEOMETRY_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_geometry_image_uniforms);
# endif
# ifdef GL_MAX_GEOMETRY_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_input_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_VERTICES
	BOOST_CHECK(x != ev.max_geometry_output_vertices);
# endif
# ifdef GL_MAX_GEOMETRY_SHADER_INVOCATIONS
	BOOST_CHECK(x != ev.max_geometry_shader_invocations);
# endif
# ifdef GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_geometry_texture_image_units);
# endif
# ifdef GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_total_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_geometry_uniform_blocks);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_uniform_components);
# endif
# ifdef GL_MAX_IMAGE_SAMPLES
	BOOST_CHECK(x != ev.max_image_samples);
# endif
# ifdef GL_MAX_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_image_units);
# endif
# ifdef GL_MAX_INTEGER_SAMPLES
	BOOST_CHECK(x != ev.max_integer_samples);
# endif
# ifdef GL_MAX_PATCH_VERTICES
	BOOST_CHECK(x != ev.max_patch_vertices);
# endif
# ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.max_program_texel_offset);
# endif
# ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.max_program_texture_gather_offset);
# endif
# ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_rectangle_texture_size);
# endif
# ifdef GL_MAX_RENDERBUFFER_SIZE
	BOOST_CHECK(x != ev.max_renderbuffer_size);
# endif
# ifdef GL_MAX_SAMPLE_MASK_WORDS
	BOOST_CHECK(x != ev.max_sample_mask_words);
# endif
# ifdef GL_MAX_SAMPLES
	BOOST_CHECK(x != ev.max_samples);
# endif
# ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	BOOST_CHECK(x != ev.max_server_wait_timeout);
# endif
# ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	BOOST_CHECK(x != ev.max_subroutine_uniform_locations);
# endif
# ifdef GL_MAX_SUBROUTINES
	BOOST_CHECK(x != ev.max_subroutines);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_DRAW_BUFFERS
	x = ev.max_draw_buffers;
	BOOST_CHECK(x == ev.max_draw_buffers);
# ifdef GL_MAX_DUAL_SOURCE_DRAW_BUFFERS
	BOOST_CHECK(x != ev.max_dual_source_draw_buffers);
# endif
# ifdef GL_MAX_ELEMENTS_INDICES
	BOOST_CHECK(x != ev.max_elements_indices);
# endif
# ifdef GL_MAX_ELEMENTS_VERTICES
	BOOST_CHECK(x != ev.max_elements_vertices);
# endif
# ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_fragment_atomic_counter_buffers);
# endif
# ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_fragment_atomic_counters);
# endif
# ifdef GL_MAX_FRAGMENT_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_fragment_image_uniforms);
# endif
# ifdef GL_MAX_FRAGMENT_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_input_components);
# endif
# ifdef GL_MAX_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.max_fragment_interpolation_offset);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_fragment_uniform_blocks);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_uniform_components);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_fragment_uniform_vectors);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counter_buffers);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counters);
# endif
# ifdef GL_MAX_GEOMETRY_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_geometry_image_uniforms);
# endif
# ifdef GL_MAX_GEOMETRY_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_input_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_VERTICES
	BOOST_CHECK(x != ev.max_geometry_output_vertices);
# endif
# ifdef GL_MAX_GEOMETRY_SHADER_INVOCATIONS
	BOOST_CHECK(x != ev.max_geometry_shader_invocations);
# endif
# ifdef GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_geometry_texture_image_units);
# endif
# ifdef GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_total_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_geometry_uniform_blocks);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_uniform_components);
# endif
# ifdef GL_MAX_IMAGE_SAMPLES
	BOOST_CHECK(x != ev.max_image_samples);
# endif
# ifdef GL_MAX_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_image_units);
# endif
# ifdef GL_MAX_INTEGER_SAMPLES
	BOOST_CHECK(x != ev.max_integer_samples);
# endif
# ifdef GL_MAX_PATCH_VERTICES
	BOOST_CHECK(x != ev.max_patch_vertices);
# endif
# ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.max_program_texel_offset);
# endif
# ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.max_program_texture_gather_offset);
# endif
# ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_rectangle_texture_size);
# endif
# ifdef GL_MAX_RENDERBUFFER_SIZE
	BOOST_CHECK(x != ev.max_renderbuffer_size);
# endif
# ifdef GL_MAX_SAMPLE_MASK_WORDS
	BOOST_CHECK(x != ev.max_sample_mask_words);
# endif
# ifdef GL_MAX_SAMPLES
	BOOST_CHECK(x != ev.max_samples);
# endif
# ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	BOOST_CHECK(x != ev.max_server_wait_timeout);
# endif
# ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	BOOST_CHECK(x != ev.max_subroutine_uniform_locations);
# endif
# ifdef GL_MAX_SUBROUTINES
	BOOST_CHECK(x != ev.max_subroutines);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_DUAL_SOURCE_DRAW_BUFFERS
	x = ev.max_dual_source_draw_buffers;
	BOOST_CHECK(x == ev.max_dual_source_draw_buffers);
# ifdef GL_MAX_ELEMENTS_INDICES
	BOOST_CHECK(x != ev.max_elements_indices);
# endif
# ifdef GL_MAX_ELEMENTS_VERTICES
	BOOST_CHECK(x != ev.max_elements_vertices);
# endif
# ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_fragment_atomic_counter_buffers);
# endif
# ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_fragment_atomic_counters);
# endif
# ifdef GL_MAX_FRAGMENT_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_fragment_image_uniforms);
# endif
# ifdef GL_MAX_FRAGMENT_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_input_components);
# endif
# ifdef GL_MAX_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.max_fragment_interpolation_offset);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_fragment_uniform_blocks);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_uniform_components);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_fragment_uniform_vectors);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counter_buffers);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counters);
# endif
# ifdef GL_MAX_GEOMETRY_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_geometry_image_uniforms);
# endif
# ifdef GL_MAX_GEOMETRY_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_input_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_VERTICES
	BOOST_CHECK(x != ev.max_geometry_output_vertices);
# endif
# ifdef GL_MAX_GEOMETRY_SHADER_INVOCATIONS
	BOOST_CHECK(x != ev.max_geometry_shader_invocations);
# endif
# ifdef GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_geometry_texture_image_units);
# endif
# ifdef GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_total_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_geometry_uniform_blocks);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_uniform_components);
# endif
# ifdef GL_MAX_IMAGE_SAMPLES
	BOOST_CHECK(x != ev.max_image_samples);
# endif
# ifdef GL_MAX_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_image_units);
# endif
# ifdef GL_MAX_INTEGER_SAMPLES
	BOOST_CHECK(x != ev.max_integer_samples);
# endif
# ifdef GL_MAX_PATCH_VERTICES
	BOOST_CHECK(x != ev.max_patch_vertices);
# endif
# ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.max_program_texel_offset);
# endif
# ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.max_program_texture_gather_offset);
# endif
# ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_rectangle_texture_size);
# endif
# ifdef GL_MAX_RENDERBUFFER_SIZE
	BOOST_CHECK(x != ev.max_renderbuffer_size);
# endif
# ifdef GL_MAX_SAMPLE_MASK_WORDS
	BOOST_CHECK(x != ev.max_sample_mask_words);
# endif
# ifdef GL_MAX_SAMPLES
	BOOST_CHECK(x != ev.max_samples);
# endif
# ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	BOOST_CHECK(x != ev.max_server_wait_timeout);
# endif
# ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	BOOST_CHECK(x != ev.max_subroutine_uniform_locations);
# endif
# ifdef GL_MAX_SUBROUTINES
	BOOST_CHECK(x != ev.max_subroutines);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_ELEMENTS_INDICES
	x = ev.max_elements_indices;
	BOOST_CHECK(x == ev.max_elements_indices);
# ifdef GL_MAX_ELEMENTS_VERTICES
	BOOST_CHECK(x != ev.max_elements_vertices);
# endif
# ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_fragment_atomic_counter_buffers);
# endif
# ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_fragment_atomic_counters);
# endif
# ifdef GL_MAX_FRAGMENT_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_fragment_image_uniforms);
# endif
# ifdef GL_MAX_FRAGMENT_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_input_components);
# endif
# ifdef GL_MAX_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.max_fragment_interpolation_offset);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_fragment_uniform_blocks);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_uniform_components);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_fragment_uniform_vectors);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counter_buffers);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counters);
# endif
# ifdef GL_MAX_GEOMETRY_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_geometry_image_uniforms);
# endif
# ifdef GL_MAX_GEOMETRY_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_input_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_VERTICES
	BOOST_CHECK(x != ev.max_geometry_output_vertices);
# endif
# ifdef GL_MAX_GEOMETRY_SHADER_INVOCATIONS
	BOOST_CHECK(x != ev.max_geometry_shader_invocations);
# endif
# ifdef GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_geometry_texture_image_units);
# endif
# ifdef GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_total_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_geometry_uniform_blocks);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_uniform_components);
# endif
# ifdef GL_MAX_IMAGE_SAMPLES
	BOOST_CHECK(x != ev.max_image_samples);
# endif
# ifdef GL_MAX_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_image_units);
# endif
# ifdef GL_MAX_INTEGER_SAMPLES
	BOOST_CHECK(x != ev.max_integer_samples);
# endif
# ifdef GL_MAX_PATCH_VERTICES
	BOOST_CHECK(x != ev.max_patch_vertices);
# endif
# ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.max_program_texel_offset);
# endif
# ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.max_program_texture_gather_offset);
# endif
# ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_rectangle_texture_size);
# endif
# ifdef GL_MAX_RENDERBUFFER_SIZE
	BOOST_CHECK(x != ev.max_renderbuffer_size);
# endif
# ifdef GL_MAX_SAMPLE_MASK_WORDS
	BOOST_CHECK(x != ev.max_sample_mask_words);
# endif
# ifdef GL_MAX_SAMPLES
	BOOST_CHECK(x != ev.max_samples);
# endif
# ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	BOOST_CHECK(x != ev.max_server_wait_timeout);
# endif
# ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	BOOST_CHECK(x != ev.max_subroutine_uniform_locations);
# endif
# ifdef GL_MAX_SUBROUTINES
	BOOST_CHECK(x != ev.max_subroutines);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_ELEMENTS_VERTICES
	x = ev.max_elements_vertices;
	BOOST_CHECK(x == ev.max_elements_vertices);
# ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_fragment_atomic_counter_buffers);
# endif
# ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_fragment_atomic_counters);
# endif
# ifdef GL_MAX_FRAGMENT_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_fragment_image_uniforms);
# endif
# ifdef GL_MAX_FRAGMENT_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_input_components);
# endif
# ifdef GL_MAX_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.max_fragment_interpolation_offset);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_fragment_uniform_blocks);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_uniform_components);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_fragment_uniform_vectors);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counter_buffers);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counters);
# endif
# ifdef GL_MAX_GEOMETRY_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_geometry_image_uniforms);
# endif
# ifdef GL_MAX_GEOMETRY_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_input_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_VERTICES
	BOOST_CHECK(x != ev.max_geometry_output_vertices);
# endif
# ifdef GL_MAX_GEOMETRY_SHADER_INVOCATIONS
	BOOST_CHECK(x != ev.max_geometry_shader_invocations);
# endif
# ifdef GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_geometry_texture_image_units);
# endif
# ifdef GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_total_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_geometry_uniform_blocks);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_uniform_components);
# endif
# ifdef GL_MAX_IMAGE_SAMPLES
	BOOST_CHECK(x != ev.max_image_samples);
# endif
# ifdef GL_MAX_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_image_units);
# endif
# ifdef GL_MAX_INTEGER_SAMPLES
	BOOST_CHECK(x != ev.max_integer_samples);
# endif
# ifdef GL_MAX_PATCH_VERTICES
	BOOST_CHECK(x != ev.max_patch_vertices);
# endif
# ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.max_program_texel_offset);
# endif
# ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.max_program_texture_gather_offset);
# endif
# ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_rectangle_texture_size);
# endif
# ifdef GL_MAX_RENDERBUFFER_SIZE
	BOOST_CHECK(x != ev.max_renderbuffer_size);
# endif
# ifdef GL_MAX_SAMPLE_MASK_WORDS
	BOOST_CHECK(x != ev.max_sample_mask_words);
# endif
# ifdef GL_MAX_SAMPLES
	BOOST_CHECK(x != ev.max_samples);
# endif
# ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	BOOST_CHECK(x != ev.max_server_wait_timeout);
# endif
# ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	BOOST_CHECK(x != ev.max_subroutine_uniform_locations);
# endif
# ifdef GL_MAX_SUBROUTINES
	BOOST_CHECK(x != ev.max_subroutines);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS
	x = ev.max_fragment_atomic_counter_buffers;
	BOOST_CHECK(x == ev.max_fragment_atomic_counter_buffers);
# ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_fragment_atomic_counters);
# endif
# ifdef GL_MAX_FRAGMENT_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_fragment_image_uniforms);
# endif
# ifdef GL_MAX_FRAGMENT_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_input_components);
# endif
# ifdef GL_MAX_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.max_fragment_interpolation_offset);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_fragment_uniform_blocks);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_uniform_components);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_fragment_uniform_vectors);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counter_buffers);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counters);
# endif
# ifdef GL_MAX_GEOMETRY_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_geometry_image_uniforms);
# endif
# ifdef GL_MAX_GEOMETRY_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_input_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_VERTICES
	BOOST_CHECK(x != ev.max_geometry_output_vertices);
# endif
# ifdef GL_MAX_GEOMETRY_SHADER_INVOCATIONS
	BOOST_CHECK(x != ev.max_geometry_shader_invocations);
# endif
# ifdef GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_geometry_texture_image_units);
# endif
# ifdef GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_total_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_geometry_uniform_blocks);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_uniform_components);
# endif
# ifdef GL_MAX_IMAGE_SAMPLES
	BOOST_CHECK(x != ev.max_image_samples);
# endif
# ifdef GL_MAX_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_image_units);
# endif
# ifdef GL_MAX_INTEGER_SAMPLES
	BOOST_CHECK(x != ev.max_integer_samples);
# endif
# ifdef GL_MAX_PATCH_VERTICES
	BOOST_CHECK(x != ev.max_patch_vertices);
# endif
# ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.max_program_texel_offset);
# endif
# ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.max_program_texture_gather_offset);
# endif
# ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_rectangle_texture_size);
# endif
# ifdef GL_MAX_RENDERBUFFER_SIZE
	BOOST_CHECK(x != ev.max_renderbuffer_size);
# endif
# ifdef GL_MAX_SAMPLE_MASK_WORDS
	BOOST_CHECK(x != ev.max_sample_mask_words);
# endif
# ifdef GL_MAX_SAMPLES
	BOOST_CHECK(x != ev.max_samples);
# endif
# ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	BOOST_CHECK(x != ev.max_server_wait_timeout);
# endif
# ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	BOOST_CHECK(x != ev.max_subroutine_uniform_locations);
# endif
# ifdef GL_MAX_SUBROUTINES
	BOOST_CHECK(x != ev.max_subroutines);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTERS
	x = ev.max_fragment_atomic_counters;
	BOOST_CHECK(x == ev.max_fragment_atomic_counters);
# ifdef GL_MAX_FRAGMENT_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_fragment_image_uniforms);
# endif
# ifdef GL_MAX_FRAGMENT_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_input_components);
# endif
# ifdef GL_MAX_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.max_fragment_interpolation_offset);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_fragment_uniform_blocks);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_uniform_components);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_fragment_uniform_vectors);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counter_buffers);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counters);
# endif
# ifdef GL_MAX_GEOMETRY_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_geometry_image_uniforms);
# endif
# ifdef GL_MAX_GEOMETRY_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_input_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_VERTICES
	BOOST_CHECK(x != ev.max_geometry_output_vertices);
# endif
# ifdef GL_MAX_GEOMETRY_SHADER_INVOCATIONS
	BOOST_CHECK(x != ev.max_geometry_shader_invocations);
# endif
# ifdef GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_geometry_texture_image_units);
# endif
# ifdef GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_total_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_geometry_uniform_blocks);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_uniform_components);
# endif
# ifdef GL_MAX_IMAGE_SAMPLES
	BOOST_CHECK(x != ev.max_image_samples);
# endif
# ifdef GL_MAX_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_image_units);
# endif
# ifdef GL_MAX_INTEGER_SAMPLES
	BOOST_CHECK(x != ev.max_integer_samples);
# endif
# ifdef GL_MAX_PATCH_VERTICES
	BOOST_CHECK(x != ev.max_patch_vertices);
# endif
# ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.max_program_texel_offset);
# endif
# ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.max_program_texture_gather_offset);
# endif
# ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_rectangle_texture_size);
# endif
# ifdef GL_MAX_RENDERBUFFER_SIZE
	BOOST_CHECK(x != ev.max_renderbuffer_size);
# endif
# ifdef GL_MAX_SAMPLE_MASK_WORDS
	BOOST_CHECK(x != ev.max_sample_mask_words);
# endif
# ifdef GL_MAX_SAMPLES
	BOOST_CHECK(x != ev.max_samples);
# endif
# ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	BOOST_CHECK(x != ev.max_server_wait_timeout);
# endif
# ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	BOOST_CHECK(x != ev.max_subroutine_uniform_locations);
# endif
# ifdef GL_MAX_SUBROUTINES
	BOOST_CHECK(x != ev.max_subroutines);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_FRAGMENT_IMAGE_UNIFORMS
	x = ev.max_fragment_image_uniforms;
	BOOST_CHECK(x == ev.max_fragment_image_uniforms);
# ifdef GL_MAX_FRAGMENT_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_input_components);
# endif
# ifdef GL_MAX_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.max_fragment_interpolation_offset);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_fragment_uniform_blocks);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_uniform_components);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_fragment_uniform_vectors);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counter_buffers);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counters);
# endif
# ifdef GL_MAX_GEOMETRY_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_geometry_image_uniforms);
# endif
# ifdef GL_MAX_GEOMETRY_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_input_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_VERTICES
	BOOST_CHECK(x != ev.max_geometry_output_vertices);
# endif
# ifdef GL_MAX_GEOMETRY_SHADER_INVOCATIONS
	BOOST_CHECK(x != ev.max_geometry_shader_invocations);
# endif
# ifdef GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_geometry_texture_image_units);
# endif
# ifdef GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_total_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_geometry_uniform_blocks);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_uniform_components);
# endif
# ifdef GL_MAX_IMAGE_SAMPLES
	BOOST_CHECK(x != ev.max_image_samples);
# endif
# ifdef GL_MAX_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_image_units);
# endif
# ifdef GL_MAX_INTEGER_SAMPLES
	BOOST_CHECK(x != ev.max_integer_samples);
# endif
# ifdef GL_MAX_PATCH_VERTICES
	BOOST_CHECK(x != ev.max_patch_vertices);
# endif
# ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.max_program_texel_offset);
# endif
# ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.max_program_texture_gather_offset);
# endif
# ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_rectangle_texture_size);
# endif
# ifdef GL_MAX_RENDERBUFFER_SIZE
	BOOST_CHECK(x != ev.max_renderbuffer_size);
# endif
# ifdef GL_MAX_SAMPLE_MASK_WORDS
	BOOST_CHECK(x != ev.max_sample_mask_words);
# endif
# ifdef GL_MAX_SAMPLES
	BOOST_CHECK(x != ev.max_samples);
# endif
# ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	BOOST_CHECK(x != ev.max_server_wait_timeout);
# endif
# ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	BOOST_CHECK(x != ev.max_subroutine_uniform_locations);
# endif
# ifdef GL_MAX_SUBROUTINES
	BOOST_CHECK(x != ev.max_subroutines);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_FRAGMENT_INPUT_COMPONENTS
	x = ev.max_fragment_input_components;
	BOOST_CHECK(x == ev.max_fragment_input_components);
# ifdef GL_MAX_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.max_fragment_interpolation_offset);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_fragment_uniform_blocks);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_uniform_components);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_fragment_uniform_vectors);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counter_buffers);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counters);
# endif
# ifdef GL_MAX_GEOMETRY_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_geometry_image_uniforms);
# endif
# ifdef GL_MAX_GEOMETRY_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_input_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_VERTICES
	BOOST_CHECK(x != ev.max_geometry_output_vertices);
# endif
# ifdef GL_MAX_GEOMETRY_SHADER_INVOCATIONS
	BOOST_CHECK(x != ev.max_geometry_shader_invocations);
# endif
# ifdef GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_geometry_texture_image_units);
# endif
# ifdef GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_total_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_geometry_uniform_blocks);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_uniform_components);
# endif
# ifdef GL_MAX_IMAGE_SAMPLES
	BOOST_CHECK(x != ev.max_image_samples);
# endif
# ifdef GL_MAX_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_image_units);
# endif
# ifdef GL_MAX_INTEGER_SAMPLES
	BOOST_CHECK(x != ev.max_integer_samples);
# endif
# ifdef GL_MAX_PATCH_VERTICES
	BOOST_CHECK(x != ev.max_patch_vertices);
# endif
# ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.max_program_texel_offset);
# endif
# ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.max_program_texture_gather_offset);
# endif
# ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_rectangle_texture_size);
# endif
# ifdef GL_MAX_RENDERBUFFER_SIZE
	BOOST_CHECK(x != ev.max_renderbuffer_size);
# endif
# ifdef GL_MAX_SAMPLE_MASK_WORDS
	BOOST_CHECK(x != ev.max_sample_mask_words);
# endif
# ifdef GL_MAX_SAMPLES
	BOOST_CHECK(x != ev.max_samples);
# endif
# ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	BOOST_CHECK(x != ev.max_server_wait_timeout);
# endif
# ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	BOOST_CHECK(x != ev.max_subroutine_uniform_locations);
# endif
# ifdef GL_MAX_SUBROUTINES
	BOOST_CHECK(x != ev.max_subroutines);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_FRAGMENT_INTERPOLATION_OFFSET
	x = ev.max_fragment_interpolation_offset;
	BOOST_CHECK(x == ev.max_fragment_interpolation_offset);
# ifdef GL_MAX_FRAGMENT_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_fragment_uniform_blocks);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_uniform_components);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_fragment_uniform_vectors);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counter_buffers);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counters);
# endif
# ifdef GL_MAX_GEOMETRY_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_geometry_image_uniforms);
# endif
# ifdef GL_MAX_GEOMETRY_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_input_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_VERTICES
	BOOST_CHECK(x != ev.max_geometry_output_vertices);
# endif
# ifdef GL_MAX_GEOMETRY_SHADER_INVOCATIONS
	BOOST_CHECK(x != ev.max_geometry_shader_invocations);
# endif
# ifdef GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_geometry_texture_image_units);
# endif
# ifdef GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_total_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_geometry_uniform_blocks);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_uniform_components);
# endif
# ifdef GL_MAX_IMAGE_SAMPLES
	BOOST_CHECK(x != ev.max_image_samples);
# endif
# ifdef GL_MAX_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_image_units);
# endif
# ifdef GL_MAX_INTEGER_SAMPLES
	BOOST_CHECK(x != ev.max_integer_samples);
# endif
# ifdef GL_MAX_PATCH_VERTICES
	BOOST_CHECK(x != ev.max_patch_vertices);
# endif
# ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.max_program_texel_offset);
# endif
# ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.max_program_texture_gather_offset);
# endif
# ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_rectangle_texture_size);
# endif
# ifdef GL_MAX_RENDERBUFFER_SIZE
	BOOST_CHECK(x != ev.max_renderbuffer_size);
# endif
# ifdef GL_MAX_SAMPLE_MASK_WORDS
	BOOST_CHECK(x != ev.max_sample_mask_words);
# endif
# ifdef GL_MAX_SAMPLES
	BOOST_CHECK(x != ev.max_samples);
# endif
# ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	BOOST_CHECK(x != ev.max_server_wait_timeout);
# endif
# ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	BOOST_CHECK(x != ev.max_subroutine_uniform_locations);
# endif
# ifdef GL_MAX_SUBROUTINES
	BOOST_CHECK(x != ev.max_subroutines);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_FRAGMENT_UNIFORM_BLOCKS
	x = ev.max_fragment_uniform_blocks;
	BOOST_CHECK(x == ev.max_fragment_uniform_blocks);
# ifdef GL_MAX_FRAGMENT_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_fragment_uniform_components);
# endif
# ifdef GL_MAX_FRAGMENT_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_fragment_uniform_vectors);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counter_buffers);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counters);
# endif
# ifdef GL_MAX_GEOMETRY_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_geometry_image_uniforms);
# endif
# ifdef GL_MAX_GEOMETRY_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_input_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_VERTICES
	BOOST_CHECK(x != ev.max_geometry_output_vertices);
# endif
# ifdef GL_MAX_GEOMETRY_SHADER_INVOCATIONS
	BOOST_CHECK(x != ev.max_geometry_shader_invocations);
# endif
# ifdef GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_geometry_texture_image_units);
# endif
# ifdef GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_total_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_geometry_uniform_blocks);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_uniform_components);
# endif
# ifdef GL_MAX_IMAGE_SAMPLES
	BOOST_CHECK(x != ev.max_image_samples);
# endif
# ifdef GL_MAX_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_image_units);
# endif
# ifdef GL_MAX_INTEGER_SAMPLES
	BOOST_CHECK(x != ev.max_integer_samples);
# endif
# ifdef GL_MAX_PATCH_VERTICES
	BOOST_CHECK(x != ev.max_patch_vertices);
# endif
# ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.max_program_texel_offset);
# endif
# ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.max_program_texture_gather_offset);
# endif
# ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_rectangle_texture_size);
# endif
# ifdef GL_MAX_RENDERBUFFER_SIZE
	BOOST_CHECK(x != ev.max_renderbuffer_size);
# endif
# ifdef GL_MAX_SAMPLE_MASK_WORDS
	BOOST_CHECK(x != ev.max_sample_mask_words);
# endif
# ifdef GL_MAX_SAMPLES
	BOOST_CHECK(x != ev.max_samples);
# endif
# ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	BOOST_CHECK(x != ev.max_server_wait_timeout);
# endif
# ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	BOOST_CHECK(x != ev.max_subroutine_uniform_locations);
# endif
# ifdef GL_MAX_SUBROUTINES
	BOOST_CHECK(x != ev.max_subroutines);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_FRAGMENT_UNIFORM_COMPONENTS
	x = ev.max_fragment_uniform_components;
	BOOST_CHECK(x == ev.max_fragment_uniform_components);
# ifdef GL_MAX_FRAGMENT_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_fragment_uniform_vectors);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counter_buffers);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counters);
# endif
# ifdef GL_MAX_GEOMETRY_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_geometry_image_uniforms);
# endif
# ifdef GL_MAX_GEOMETRY_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_input_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_VERTICES
	BOOST_CHECK(x != ev.max_geometry_output_vertices);
# endif
# ifdef GL_MAX_GEOMETRY_SHADER_INVOCATIONS
	BOOST_CHECK(x != ev.max_geometry_shader_invocations);
# endif
# ifdef GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_geometry_texture_image_units);
# endif
# ifdef GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_total_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_geometry_uniform_blocks);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_uniform_components);
# endif
# ifdef GL_MAX_IMAGE_SAMPLES
	BOOST_CHECK(x != ev.max_image_samples);
# endif
# ifdef GL_MAX_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_image_units);
# endif
# ifdef GL_MAX_INTEGER_SAMPLES
	BOOST_CHECK(x != ev.max_integer_samples);
# endif
# ifdef GL_MAX_PATCH_VERTICES
	BOOST_CHECK(x != ev.max_patch_vertices);
# endif
# ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.max_program_texel_offset);
# endif
# ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.max_program_texture_gather_offset);
# endif
# ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_rectangle_texture_size);
# endif
# ifdef GL_MAX_RENDERBUFFER_SIZE
	BOOST_CHECK(x != ev.max_renderbuffer_size);
# endif
# ifdef GL_MAX_SAMPLE_MASK_WORDS
	BOOST_CHECK(x != ev.max_sample_mask_words);
# endif
# ifdef GL_MAX_SAMPLES
	BOOST_CHECK(x != ev.max_samples);
# endif
# ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	BOOST_CHECK(x != ev.max_server_wait_timeout);
# endif
# ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	BOOST_CHECK(x != ev.max_subroutine_uniform_locations);
# endif
# ifdef GL_MAX_SUBROUTINES
	BOOST_CHECK(x != ev.max_subroutines);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_FRAGMENT_UNIFORM_VECTORS
	x = ev.max_fragment_uniform_vectors;
	BOOST_CHECK(x == ev.max_fragment_uniform_vectors);
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counter_buffers);
# endif
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counters);
# endif
# ifdef GL_MAX_GEOMETRY_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_geometry_image_uniforms);
# endif
# ifdef GL_MAX_GEOMETRY_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_input_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_VERTICES
	BOOST_CHECK(x != ev.max_geometry_output_vertices);
# endif
# ifdef GL_MAX_GEOMETRY_SHADER_INVOCATIONS
	BOOST_CHECK(x != ev.max_geometry_shader_invocations);
# endif
# ifdef GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_geometry_texture_image_units);
# endif
# ifdef GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_total_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_geometry_uniform_blocks);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_uniform_components);
# endif
# ifdef GL_MAX_IMAGE_SAMPLES
	BOOST_CHECK(x != ev.max_image_samples);
# endif
# ifdef GL_MAX_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_image_units);
# endif
# ifdef GL_MAX_INTEGER_SAMPLES
	BOOST_CHECK(x != ev.max_integer_samples);
# endif
# ifdef GL_MAX_PATCH_VERTICES
	BOOST_CHECK(x != ev.max_patch_vertices);
# endif
# ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.max_program_texel_offset);
# endif
# ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.max_program_texture_gather_offset);
# endif
# ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_rectangle_texture_size);
# endif
# ifdef GL_MAX_RENDERBUFFER_SIZE
	BOOST_CHECK(x != ev.max_renderbuffer_size);
# endif
# ifdef GL_MAX_SAMPLE_MASK_WORDS
	BOOST_CHECK(x != ev.max_sample_mask_words);
# endif
# ifdef GL_MAX_SAMPLES
	BOOST_CHECK(x != ev.max_samples);
# endif
# ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	BOOST_CHECK(x != ev.max_server_wait_timeout);
# endif
# ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	BOOST_CHECK(x != ev.max_subroutine_uniform_locations);
# endif
# ifdef GL_MAX_SUBROUTINES
	BOOST_CHECK(x != ev.max_subroutines);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS
	x = ev.max_geometry_atomic_counter_buffers;
	BOOST_CHECK(x == ev.max_geometry_atomic_counter_buffers);
# ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_geometry_atomic_counters);
# endif
# ifdef GL_MAX_GEOMETRY_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_geometry_image_uniforms);
# endif
# ifdef GL_MAX_GEOMETRY_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_input_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_VERTICES
	BOOST_CHECK(x != ev.max_geometry_output_vertices);
# endif
# ifdef GL_MAX_GEOMETRY_SHADER_INVOCATIONS
	BOOST_CHECK(x != ev.max_geometry_shader_invocations);
# endif
# ifdef GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_geometry_texture_image_units);
# endif
# ifdef GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_total_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_geometry_uniform_blocks);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_uniform_components);
# endif
# ifdef GL_MAX_IMAGE_SAMPLES
	BOOST_CHECK(x != ev.max_image_samples);
# endif
# ifdef GL_MAX_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_image_units);
# endif
# ifdef GL_MAX_INTEGER_SAMPLES
	BOOST_CHECK(x != ev.max_integer_samples);
# endif
# ifdef GL_MAX_PATCH_VERTICES
	BOOST_CHECK(x != ev.max_patch_vertices);
# endif
# ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.max_program_texel_offset);
# endif
# ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.max_program_texture_gather_offset);
# endif
# ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_rectangle_texture_size);
# endif
# ifdef GL_MAX_RENDERBUFFER_SIZE
	BOOST_CHECK(x != ev.max_renderbuffer_size);
# endif
# ifdef GL_MAX_SAMPLE_MASK_WORDS
	BOOST_CHECK(x != ev.max_sample_mask_words);
# endif
# ifdef GL_MAX_SAMPLES
	BOOST_CHECK(x != ev.max_samples);
# endif
# ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	BOOST_CHECK(x != ev.max_server_wait_timeout);
# endif
# ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	BOOST_CHECK(x != ev.max_subroutine_uniform_locations);
# endif
# ifdef GL_MAX_SUBROUTINES
	BOOST_CHECK(x != ev.max_subroutines);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTERS
	x = ev.max_geometry_atomic_counters;
	BOOST_CHECK(x == ev.max_geometry_atomic_counters);
# ifdef GL_MAX_GEOMETRY_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_geometry_image_uniforms);
# endif
# ifdef GL_MAX_GEOMETRY_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_input_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_VERTICES
	BOOST_CHECK(x != ev.max_geometry_output_vertices);
# endif
# ifdef GL_MAX_GEOMETRY_SHADER_INVOCATIONS
	BOOST_CHECK(x != ev.max_geometry_shader_invocations);
# endif
# ifdef GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_geometry_texture_image_units);
# endif
# ifdef GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_total_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_geometry_uniform_blocks);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_uniform_components);
# endif
# ifdef GL_MAX_IMAGE_SAMPLES
	BOOST_CHECK(x != ev.max_image_samples);
# endif
# ifdef GL_MAX_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_image_units);
# endif
# ifdef GL_MAX_INTEGER_SAMPLES
	BOOST_CHECK(x != ev.max_integer_samples);
# endif
# ifdef GL_MAX_PATCH_VERTICES
	BOOST_CHECK(x != ev.max_patch_vertices);
# endif
# ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.max_program_texel_offset);
# endif
# ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.max_program_texture_gather_offset);
# endif
# ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_rectangle_texture_size);
# endif
# ifdef GL_MAX_RENDERBUFFER_SIZE
	BOOST_CHECK(x != ev.max_renderbuffer_size);
# endif
# ifdef GL_MAX_SAMPLE_MASK_WORDS
	BOOST_CHECK(x != ev.max_sample_mask_words);
# endif
# ifdef GL_MAX_SAMPLES
	BOOST_CHECK(x != ev.max_samples);
# endif
# ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	BOOST_CHECK(x != ev.max_server_wait_timeout);
# endif
# ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	BOOST_CHECK(x != ev.max_subroutine_uniform_locations);
# endif
# ifdef GL_MAX_SUBROUTINES
	BOOST_CHECK(x != ev.max_subroutines);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_GEOMETRY_IMAGE_UNIFORMS
	x = ev.max_geometry_image_uniforms;
	BOOST_CHECK(x == ev.max_geometry_image_uniforms);
# ifdef GL_MAX_GEOMETRY_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_input_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_VERTICES
	BOOST_CHECK(x != ev.max_geometry_output_vertices);
# endif
# ifdef GL_MAX_GEOMETRY_SHADER_INVOCATIONS
	BOOST_CHECK(x != ev.max_geometry_shader_invocations);
# endif
# ifdef GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_geometry_texture_image_units);
# endif
# ifdef GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_total_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_geometry_uniform_blocks);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_uniform_components);
# endif
# ifdef GL_MAX_IMAGE_SAMPLES
	BOOST_CHECK(x != ev.max_image_samples);
# endif
# ifdef GL_MAX_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_image_units);
# endif
# ifdef GL_MAX_INTEGER_SAMPLES
	BOOST_CHECK(x != ev.max_integer_samples);
# endif
# ifdef GL_MAX_PATCH_VERTICES
	BOOST_CHECK(x != ev.max_patch_vertices);
# endif
# ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.max_program_texel_offset);
# endif
# ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.max_program_texture_gather_offset);
# endif
# ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_rectangle_texture_size);
# endif
# ifdef GL_MAX_RENDERBUFFER_SIZE
	BOOST_CHECK(x != ev.max_renderbuffer_size);
# endif
# ifdef GL_MAX_SAMPLE_MASK_WORDS
	BOOST_CHECK(x != ev.max_sample_mask_words);
# endif
# ifdef GL_MAX_SAMPLES
	BOOST_CHECK(x != ev.max_samples);
# endif
# ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	BOOST_CHECK(x != ev.max_server_wait_timeout);
# endif
# ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	BOOST_CHECK(x != ev.max_subroutine_uniform_locations);
# endif
# ifdef GL_MAX_SUBROUTINES
	BOOST_CHECK(x != ev.max_subroutines);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_GEOMETRY_INPUT_COMPONENTS
	x = ev.max_geometry_input_components;
	BOOST_CHECK(x == ev.max_geometry_input_components);
# ifdef GL_MAX_GEOMETRY_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_OUTPUT_VERTICES
	BOOST_CHECK(x != ev.max_geometry_output_vertices);
# endif
# ifdef GL_MAX_GEOMETRY_SHADER_INVOCATIONS
	BOOST_CHECK(x != ev.max_geometry_shader_invocations);
# endif
# ifdef GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_geometry_texture_image_units);
# endif
# ifdef GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_total_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_geometry_uniform_blocks);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_uniform_components);
# endif
# ifdef GL_MAX_IMAGE_SAMPLES
	BOOST_CHECK(x != ev.max_image_samples);
# endif
# ifdef GL_MAX_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_image_units);
# endif
# ifdef GL_MAX_INTEGER_SAMPLES
	BOOST_CHECK(x != ev.max_integer_samples);
# endif
# ifdef GL_MAX_PATCH_VERTICES
	BOOST_CHECK(x != ev.max_patch_vertices);
# endif
# ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.max_program_texel_offset);
# endif
# ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.max_program_texture_gather_offset);
# endif
# ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_rectangle_texture_size);
# endif
# ifdef GL_MAX_RENDERBUFFER_SIZE
	BOOST_CHECK(x != ev.max_renderbuffer_size);
# endif
# ifdef GL_MAX_SAMPLE_MASK_WORDS
	BOOST_CHECK(x != ev.max_sample_mask_words);
# endif
# ifdef GL_MAX_SAMPLES
	BOOST_CHECK(x != ev.max_samples);
# endif
# ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	BOOST_CHECK(x != ev.max_server_wait_timeout);
# endif
# ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	BOOST_CHECK(x != ev.max_subroutine_uniform_locations);
# endif
# ifdef GL_MAX_SUBROUTINES
	BOOST_CHECK(x != ev.max_subroutines);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_GEOMETRY_OUTPUT_COMPONENTS
	x = ev.max_geometry_output_components;
	BOOST_CHECK(x == ev.max_geometry_output_components);
# ifdef GL_MAX_GEOMETRY_OUTPUT_VERTICES
	BOOST_CHECK(x != ev.max_geometry_output_vertices);
# endif
# ifdef GL_MAX_GEOMETRY_SHADER_INVOCATIONS
	BOOST_CHECK(x != ev.max_geometry_shader_invocations);
# endif
# ifdef GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_geometry_texture_image_units);
# endif
# ifdef GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_total_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_geometry_uniform_blocks);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_uniform_components);
# endif
# ifdef GL_MAX_IMAGE_SAMPLES
	BOOST_CHECK(x != ev.max_image_samples);
# endif
# ifdef GL_MAX_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_image_units);
# endif
# ifdef GL_MAX_INTEGER_SAMPLES
	BOOST_CHECK(x != ev.max_integer_samples);
# endif
# ifdef GL_MAX_PATCH_VERTICES
	BOOST_CHECK(x != ev.max_patch_vertices);
# endif
# ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.max_program_texel_offset);
# endif
# ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.max_program_texture_gather_offset);
# endif
# ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_rectangle_texture_size);
# endif
# ifdef GL_MAX_RENDERBUFFER_SIZE
	BOOST_CHECK(x != ev.max_renderbuffer_size);
# endif
# ifdef GL_MAX_SAMPLE_MASK_WORDS
	BOOST_CHECK(x != ev.max_sample_mask_words);
# endif
# ifdef GL_MAX_SAMPLES
	BOOST_CHECK(x != ev.max_samples);
# endif
# ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	BOOST_CHECK(x != ev.max_server_wait_timeout);
# endif
# ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	BOOST_CHECK(x != ev.max_subroutine_uniform_locations);
# endif
# ifdef GL_MAX_SUBROUTINES
	BOOST_CHECK(x != ev.max_subroutines);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_GEOMETRY_OUTPUT_VERTICES
	x = ev.max_geometry_output_vertices;
	BOOST_CHECK(x == ev.max_geometry_output_vertices);
# ifdef GL_MAX_GEOMETRY_SHADER_INVOCATIONS
	BOOST_CHECK(x != ev.max_geometry_shader_invocations);
# endif
# ifdef GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_geometry_texture_image_units);
# endif
# ifdef GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_total_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_geometry_uniform_blocks);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_uniform_components);
# endif
# ifdef GL_MAX_IMAGE_SAMPLES
	BOOST_CHECK(x != ev.max_image_samples);
# endif
# ifdef GL_MAX_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_image_units);
# endif
# ifdef GL_MAX_INTEGER_SAMPLES
	BOOST_CHECK(x != ev.max_integer_samples);
# endif
# ifdef GL_MAX_PATCH_VERTICES
	BOOST_CHECK(x != ev.max_patch_vertices);
# endif
# ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.max_program_texel_offset);
# endif
# ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.max_program_texture_gather_offset);
# endif
# ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_rectangle_texture_size);
# endif
# ifdef GL_MAX_RENDERBUFFER_SIZE
	BOOST_CHECK(x != ev.max_renderbuffer_size);
# endif
# ifdef GL_MAX_SAMPLE_MASK_WORDS
	BOOST_CHECK(x != ev.max_sample_mask_words);
# endif
# ifdef GL_MAX_SAMPLES
	BOOST_CHECK(x != ev.max_samples);
# endif
# ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	BOOST_CHECK(x != ev.max_server_wait_timeout);
# endif
# ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	BOOST_CHECK(x != ev.max_subroutine_uniform_locations);
# endif
# ifdef GL_MAX_SUBROUTINES
	BOOST_CHECK(x != ev.max_subroutines);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_GEOMETRY_SHADER_INVOCATIONS
	x = ev.max_geometry_shader_invocations;
	BOOST_CHECK(x == ev.max_geometry_shader_invocations);
# ifdef GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_geometry_texture_image_units);
# endif
# ifdef GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_total_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_geometry_uniform_blocks);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_uniform_components);
# endif
# ifdef GL_MAX_IMAGE_SAMPLES
	BOOST_CHECK(x != ev.max_image_samples);
# endif
# ifdef GL_MAX_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_image_units);
# endif
# ifdef GL_MAX_INTEGER_SAMPLES
	BOOST_CHECK(x != ev.max_integer_samples);
# endif
# ifdef GL_MAX_PATCH_VERTICES
	BOOST_CHECK(x != ev.max_patch_vertices);
# endif
# ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.max_program_texel_offset);
# endif
# ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.max_program_texture_gather_offset);
# endif
# ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_rectangle_texture_size);
# endif
# ifdef GL_MAX_RENDERBUFFER_SIZE
	BOOST_CHECK(x != ev.max_renderbuffer_size);
# endif
# ifdef GL_MAX_SAMPLE_MASK_WORDS
	BOOST_CHECK(x != ev.max_sample_mask_words);
# endif
# ifdef GL_MAX_SAMPLES
	BOOST_CHECK(x != ev.max_samples);
# endif
# ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	BOOST_CHECK(x != ev.max_server_wait_timeout);
# endif
# ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	BOOST_CHECK(x != ev.max_subroutine_uniform_locations);
# endif
# ifdef GL_MAX_SUBROUTINES
	BOOST_CHECK(x != ev.max_subroutines);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS
	x = ev.max_geometry_texture_image_units;
	BOOST_CHECK(x == ev.max_geometry_texture_image_units);
# ifdef GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_total_output_components);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_geometry_uniform_blocks);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_uniform_components);
# endif
# ifdef GL_MAX_IMAGE_SAMPLES
	BOOST_CHECK(x != ev.max_image_samples);
# endif
# ifdef GL_MAX_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_image_units);
# endif
# ifdef GL_MAX_INTEGER_SAMPLES
	BOOST_CHECK(x != ev.max_integer_samples);
# endif
# ifdef GL_MAX_PATCH_VERTICES
	BOOST_CHECK(x != ev.max_patch_vertices);
# endif
# ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.max_program_texel_offset);
# endif
# ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.max_program_texture_gather_offset);
# endif
# ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_rectangle_texture_size);
# endif
# ifdef GL_MAX_RENDERBUFFER_SIZE
	BOOST_CHECK(x != ev.max_renderbuffer_size);
# endif
# ifdef GL_MAX_SAMPLE_MASK_WORDS
	BOOST_CHECK(x != ev.max_sample_mask_words);
# endif
# ifdef GL_MAX_SAMPLES
	BOOST_CHECK(x != ev.max_samples);
# endif
# ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	BOOST_CHECK(x != ev.max_server_wait_timeout);
# endif
# ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	BOOST_CHECK(x != ev.max_subroutine_uniform_locations);
# endif
# ifdef GL_MAX_SUBROUTINES
	BOOST_CHECK(x != ev.max_subroutines);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS
	x = ev.max_geometry_total_output_components;
	BOOST_CHECK(x == ev.max_geometry_total_output_components);
# ifdef GL_MAX_GEOMETRY_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_geometry_uniform_blocks);
# endif
# ifdef GL_MAX_GEOMETRY_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_uniform_components);
# endif
# ifdef GL_MAX_IMAGE_SAMPLES
	BOOST_CHECK(x != ev.max_image_samples);
# endif
# ifdef GL_MAX_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_image_units);
# endif
# ifdef GL_MAX_INTEGER_SAMPLES
	BOOST_CHECK(x != ev.max_integer_samples);
# endif
# ifdef GL_MAX_PATCH_VERTICES
	BOOST_CHECK(x != ev.max_patch_vertices);
# endif
# ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.max_program_texel_offset);
# endif
# ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.max_program_texture_gather_offset);
# endif
# ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_rectangle_texture_size);
# endif
# ifdef GL_MAX_RENDERBUFFER_SIZE
	BOOST_CHECK(x != ev.max_renderbuffer_size);
# endif
# ifdef GL_MAX_SAMPLE_MASK_WORDS
	BOOST_CHECK(x != ev.max_sample_mask_words);
# endif
# ifdef GL_MAX_SAMPLES
	BOOST_CHECK(x != ev.max_samples);
# endif
# ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	BOOST_CHECK(x != ev.max_server_wait_timeout);
# endif
# ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	BOOST_CHECK(x != ev.max_subroutine_uniform_locations);
# endif
# ifdef GL_MAX_SUBROUTINES
	BOOST_CHECK(x != ev.max_subroutines);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_GEOMETRY_UNIFORM_BLOCKS
	x = ev.max_geometry_uniform_blocks;
	BOOST_CHECK(x == ev.max_geometry_uniform_blocks);
# ifdef GL_MAX_GEOMETRY_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_geometry_uniform_components);
# endif
# ifdef GL_MAX_IMAGE_SAMPLES
	BOOST_CHECK(x != ev.max_image_samples);
# endif
# ifdef GL_MAX_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_image_units);
# endif
# ifdef GL_MAX_INTEGER_SAMPLES
	BOOST_CHECK(x != ev.max_integer_samples);
# endif
# ifdef GL_MAX_PATCH_VERTICES
	BOOST_CHECK(x != ev.max_patch_vertices);
# endif
# ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.max_program_texel_offset);
# endif
# ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.max_program_texture_gather_offset);
# endif
# ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_rectangle_texture_size);
# endif
# ifdef GL_MAX_RENDERBUFFER_SIZE
	BOOST_CHECK(x != ev.max_renderbuffer_size);
# endif
# ifdef GL_MAX_SAMPLE_MASK_WORDS
	BOOST_CHECK(x != ev.max_sample_mask_words);
# endif
# ifdef GL_MAX_SAMPLES
	BOOST_CHECK(x != ev.max_samples);
# endif
# ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	BOOST_CHECK(x != ev.max_server_wait_timeout);
# endif
# ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	BOOST_CHECK(x != ev.max_subroutine_uniform_locations);
# endif
# ifdef GL_MAX_SUBROUTINES
	BOOST_CHECK(x != ev.max_subroutines);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_GEOMETRY_UNIFORM_COMPONENTS
	x = ev.max_geometry_uniform_components;
	BOOST_CHECK(x == ev.max_geometry_uniform_components);
# ifdef GL_MAX_IMAGE_SAMPLES
	BOOST_CHECK(x != ev.max_image_samples);
# endif
# ifdef GL_MAX_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_image_units);
# endif
# ifdef GL_MAX_INTEGER_SAMPLES
	BOOST_CHECK(x != ev.max_integer_samples);
# endif
# ifdef GL_MAX_PATCH_VERTICES
	BOOST_CHECK(x != ev.max_patch_vertices);
# endif
# ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.max_program_texel_offset);
# endif
# ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.max_program_texture_gather_offset);
# endif
# ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_rectangle_texture_size);
# endif
# ifdef GL_MAX_RENDERBUFFER_SIZE
	BOOST_CHECK(x != ev.max_renderbuffer_size);
# endif
# ifdef GL_MAX_SAMPLE_MASK_WORDS
	BOOST_CHECK(x != ev.max_sample_mask_words);
# endif
# ifdef GL_MAX_SAMPLES
	BOOST_CHECK(x != ev.max_samples);
# endif
# ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	BOOST_CHECK(x != ev.max_server_wait_timeout);
# endif
# ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	BOOST_CHECK(x != ev.max_subroutine_uniform_locations);
# endif
# ifdef GL_MAX_SUBROUTINES
	BOOST_CHECK(x != ev.max_subroutines);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_IMAGE_SAMPLES
	x = ev.max_image_samples;
	BOOST_CHECK(x == ev.max_image_samples);
# ifdef GL_MAX_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_image_units);
# endif
# ifdef GL_MAX_INTEGER_SAMPLES
	BOOST_CHECK(x != ev.max_integer_samples);
# endif
# ifdef GL_MAX_PATCH_VERTICES
	BOOST_CHECK(x != ev.max_patch_vertices);
# endif
# ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.max_program_texel_offset);
# endif
# ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.max_program_texture_gather_offset);
# endif
# ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_rectangle_texture_size);
# endif
# ifdef GL_MAX_RENDERBUFFER_SIZE
	BOOST_CHECK(x != ev.max_renderbuffer_size);
# endif
# ifdef GL_MAX_SAMPLE_MASK_WORDS
	BOOST_CHECK(x != ev.max_sample_mask_words);
# endif
# ifdef GL_MAX_SAMPLES
	BOOST_CHECK(x != ev.max_samples);
# endif
# ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	BOOST_CHECK(x != ev.max_server_wait_timeout);
# endif
# ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	BOOST_CHECK(x != ev.max_subroutine_uniform_locations);
# endif
# ifdef GL_MAX_SUBROUTINES
	BOOST_CHECK(x != ev.max_subroutines);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_IMAGE_UNITS
	x = ev.max_image_units;
	BOOST_CHECK(x == ev.max_image_units);
# ifdef GL_MAX_INTEGER_SAMPLES
	BOOST_CHECK(x != ev.max_integer_samples);
# endif
# ifdef GL_MAX_PATCH_VERTICES
	BOOST_CHECK(x != ev.max_patch_vertices);
# endif
# ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.max_program_texel_offset);
# endif
# ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.max_program_texture_gather_offset);
# endif
# ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_rectangle_texture_size);
# endif
# ifdef GL_MAX_RENDERBUFFER_SIZE
	BOOST_CHECK(x != ev.max_renderbuffer_size);
# endif
# ifdef GL_MAX_SAMPLE_MASK_WORDS
	BOOST_CHECK(x != ev.max_sample_mask_words);
# endif
# ifdef GL_MAX_SAMPLES
	BOOST_CHECK(x != ev.max_samples);
# endif
# ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	BOOST_CHECK(x != ev.max_server_wait_timeout);
# endif
# ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	BOOST_CHECK(x != ev.max_subroutine_uniform_locations);
# endif
# ifdef GL_MAX_SUBROUTINES
	BOOST_CHECK(x != ev.max_subroutines);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_INTEGER_SAMPLES
	x = ev.max_integer_samples;
	BOOST_CHECK(x == ev.max_integer_samples);
# ifdef GL_MAX_PATCH_VERTICES
	BOOST_CHECK(x != ev.max_patch_vertices);
# endif
# ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.max_program_texel_offset);
# endif
# ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.max_program_texture_gather_offset);
# endif
# ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_rectangle_texture_size);
# endif
# ifdef GL_MAX_RENDERBUFFER_SIZE
	BOOST_CHECK(x != ev.max_renderbuffer_size);
# endif
# ifdef GL_MAX_SAMPLE_MASK_WORDS
	BOOST_CHECK(x != ev.max_sample_mask_words);
# endif
# ifdef GL_MAX_SAMPLES
	BOOST_CHECK(x != ev.max_samples);
# endif
# ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	BOOST_CHECK(x != ev.max_server_wait_timeout);
# endif
# ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	BOOST_CHECK(x != ev.max_subroutine_uniform_locations);
# endif
# ifdef GL_MAX_SUBROUTINES
	BOOST_CHECK(x != ev.max_subroutines);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_PATCH_VERTICES
	x = ev.max_patch_vertices;
	BOOST_CHECK(x == ev.max_patch_vertices);
# ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.max_program_texel_offset);
# endif
# ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.max_program_texture_gather_offset);
# endif
# ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_rectangle_texture_size);
# endif
# ifdef GL_MAX_RENDERBUFFER_SIZE
	BOOST_CHECK(x != ev.max_renderbuffer_size);
# endif
# ifdef GL_MAX_SAMPLE_MASK_WORDS
	BOOST_CHECK(x != ev.max_sample_mask_words);
# endif
# ifdef GL_MAX_SAMPLES
	BOOST_CHECK(x != ev.max_samples);
# endif
# ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	BOOST_CHECK(x != ev.max_server_wait_timeout);
# endif
# ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	BOOST_CHECK(x != ev.max_subroutine_uniform_locations);
# endif
# ifdef GL_MAX_SUBROUTINES
	BOOST_CHECK(x != ev.max_subroutines);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
	x = ev.max_program_texel_offset;
	BOOST_CHECK(x == ev.max_program_texel_offset);
# ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.max_program_texture_gather_offset);
# endif
# ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_rectangle_texture_size);
# endif
# ifdef GL_MAX_RENDERBUFFER_SIZE
	BOOST_CHECK(x != ev.max_renderbuffer_size);
# endif
# ifdef GL_MAX_SAMPLE_MASK_WORDS
	BOOST_CHECK(x != ev.max_sample_mask_words);
# endif
# ifdef GL_MAX_SAMPLES
	BOOST_CHECK(x != ev.max_samples);
# endif
# ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	BOOST_CHECK(x != ev.max_server_wait_timeout);
# endif
# ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	BOOST_CHECK(x != ev.max_subroutine_uniform_locations);
# endif
# ifdef GL_MAX_SUBROUTINES
	BOOST_CHECK(x != ev.max_subroutines);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
	x = ev.max_program_texture_gather_offset;
	BOOST_CHECK(x == ev.max_program_texture_gather_offset);
# ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_rectangle_texture_size);
# endif
# ifdef GL_MAX_RENDERBUFFER_SIZE
	BOOST_CHECK(x != ev.max_renderbuffer_size);
# endif
# ifdef GL_MAX_SAMPLE_MASK_WORDS
	BOOST_CHECK(x != ev.max_sample_mask_words);
# endif
# ifdef GL_MAX_SAMPLES
	BOOST_CHECK(x != ev.max_samples);
# endif
# ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	BOOST_CHECK(x != ev.max_server_wait_timeout);
# endif
# ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	BOOST_CHECK(x != ev.max_subroutine_uniform_locations);
# endif
# ifdef GL_MAX_SUBROUTINES
	BOOST_CHECK(x != ev.max_subroutines);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
	x = ev.max_rectangle_texture_size;
	BOOST_CHECK(x == ev.max_rectangle_texture_size);
# ifdef GL_MAX_RENDERBUFFER_SIZE
	BOOST_CHECK(x != ev.max_renderbuffer_size);
# endif
# ifdef GL_MAX_SAMPLE_MASK_WORDS
	BOOST_CHECK(x != ev.max_sample_mask_words);
# endif
# ifdef GL_MAX_SAMPLES
	BOOST_CHECK(x != ev.max_samples);
# endif
# ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	BOOST_CHECK(x != ev.max_server_wait_timeout);
# endif
# ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	BOOST_CHECK(x != ev.max_subroutine_uniform_locations);
# endif
# ifdef GL_MAX_SUBROUTINES
	BOOST_CHECK(x != ev.max_subroutines);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_RENDERBUFFER_SIZE
	x = ev.max_renderbuffer_size;
	BOOST_CHECK(x == ev.max_renderbuffer_size);
# ifdef GL_MAX_SAMPLE_MASK_WORDS
	BOOST_CHECK(x != ev.max_sample_mask_words);
# endif
# ifdef GL_MAX_SAMPLES
	BOOST_CHECK(x != ev.max_samples);
# endif
# ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	BOOST_CHECK(x != ev.max_server_wait_timeout);
# endif
# ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	BOOST_CHECK(x != ev.max_subroutine_uniform_locations);
# endif
# ifdef GL_MAX_SUBROUTINES
	BOOST_CHECK(x != ev.max_subroutines);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_SAMPLE_MASK_WORDS
	x = ev.max_sample_mask_words;
	BOOST_CHECK(x == ev.max_sample_mask_words);
# ifdef GL_MAX_SAMPLES
	BOOST_CHECK(x != ev.max_samples);
# endif
# ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	BOOST_CHECK(x != ev.max_server_wait_timeout);
# endif
# ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	BOOST_CHECK(x != ev.max_subroutine_uniform_locations);
# endif
# ifdef GL_MAX_SUBROUTINES
	BOOST_CHECK(x != ev.max_subroutines);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_SAMPLES
	x = ev.max_samples;
	BOOST_CHECK(x == ev.max_samples);
# ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	BOOST_CHECK(x != ev.max_server_wait_timeout);
# endif
# ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	BOOST_CHECK(x != ev.max_subroutine_uniform_locations);
# endif
# ifdef GL_MAX_SUBROUTINES
	BOOST_CHECK(x != ev.max_subroutines);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	x = ev.max_server_wait_timeout;
	BOOST_CHECK(x == ev.max_server_wait_timeout);
# ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	BOOST_CHECK(x != ev.max_subroutine_uniform_locations);
# endif
# ifdef GL_MAX_SUBROUTINES
	BOOST_CHECK(x != ev.max_subroutines);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	x = ev.max_subroutine_uniform_locations;
	BOOST_CHECK(x == ev.max_subroutine_uniform_locations);
# ifdef GL_MAX_SUBROUTINES
	BOOST_CHECK(x != ev.max_subroutines);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_SUBROUTINES
	x = ev.max_subroutines;
	BOOST_CHECK(x == ev.max_subroutines);
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	x = ev.max_tess_control_atomic_counter_buffers;
	BOOST_CHECK(x == ev.max_tess_control_atomic_counter_buffers);
# ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_control_atomic_counters);
# endif
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	x = ev.max_tess_control_atomic_counters;
	BOOST_CHECK(x == ev.max_tess_control_atomic_counters);
# ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_control_image_uniforms);
# endif
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	x = ev.max_tess_control_image_uniforms;
	BOOST_CHECK(x == ev.max_tess_control_image_uniforms);
# ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_input_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	x = ev.max_tess_control_input_components;
	BOOST_CHECK(x == ev.max_tess_control_input_components);
# ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	x = ev.max_tess_control_output_components;
	BOOST_CHECK(x == ev.max_tess_control_output_components);
# ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_control_texture_image_units);
# endif
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	x = ev.max_tess_control_texture_image_units;
	BOOST_CHECK(x == ev.max_tess_control_texture_image_units);
# ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_total_output_components);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	x = ev.max_tess_control_total_output_components;
	BOOST_CHECK(x == ev.max_tess_control_total_output_components);
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_control_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	x = ev.max_tess_control_uniform_blocks;
	BOOST_CHECK(x == ev.max_tess_control_uniform_blocks);
# ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_control_uniform_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	x = ev.max_tess_control_uniform_components;
	BOOST_CHECK(x == ev.max_tess_control_uniform_components);
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counter_buffers);
# endif
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	x = ev.max_tess_evaluation_atomic_counter_buffers;
	BOOST_CHECK(x == ev.max_tess_evaluation_atomic_counter_buffers);
# ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_tess_evaluation_atomic_counters);
# endif
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	x = ev.max_tess_evaluation_atomic_counters;
	BOOST_CHECK(x == ev.max_tess_evaluation_atomic_counters);
# ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_tess_evaluation_image_uniforms);
# endif
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	x = ev.max_tess_evaluation_image_uniforms;
	BOOST_CHECK(x == ev.max_tess_evaluation_image_uniforms);
# ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_input_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	x = ev.max_tess_evaluation_input_components;
	BOOST_CHECK(x == ev.max_tess_evaluation_input_components);
# ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_output_components);
# endif
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	x = ev.max_tess_evaluation_output_components;
	BOOST_CHECK(x == ev.max_tess_evaluation_output_components);
# ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_tess_evaluation_texture_image_units);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	x = ev.max_tess_evaluation_texture_image_units;
	BOOST_CHECK(x == ev.max_tess_evaluation_texture_image_units);
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_blocks);
# endif
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	x = ev.max_tess_evaluation_uniform_blocks;
	BOOST_CHECK(x == ev.max_tess_evaluation_uniform_blocks);
# ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_evaluation_uniform_components);
# endif
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	x = ev.max_tess_evaluation_uniform_components;
	BOOST_CHECK(x == ev.max_tess_evaluation_uniform_components);
# ifdef GL_MAX_TESS_GEN_LEVEL
	BOOST_CHECK(x != ev.max_tess_gen_level);
# endif
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_TESS_GEN_LEVEL
	x = ev.max_tess_gen_level;
	BOOST_CHECK(x == ev.max_tess_gen_level);
# ifdef GL_MAX_TESS_PATCH_COMPONENTS
	BOOST_CHECK(x != ev.max_tess_patch_components);
# endif
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_TESS_PATCH_COMPONENTS
	x = ev.max_tess_patch_components;
	BOOST_CHECK(x == ev.max_tess_patch_components);
# ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	BOOST_CHECK(x != ev.max_texture_buffer_size);
# endif
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	x = ev.max_texture_buffer_size;
	BOOST_CHECK(x == ev.max_texture_buffer_size);
# ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_texture_image_units);
# endif
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	x = ev.max_texture_image_units;
	BOOST_CHECK(x == ev.max_texture_image_units);
# ifdef GL_MAX_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.max_texture_lod_bias);
# endif
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_TEXTURE_LOD_BIAS
	x = ev.max_texture_lod_bias;
	BOOST_CHECK(x == ev.max_texture_lod_bias);
# ifdef GL_MAX_TEXTURE_SIZE
	BOOST_CHECK(x != ev.max_texture_size);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_TEXTURE_SIZE
	x = ev.max_texture_size;
	BOOST_CHECK(x == ev.max_texture_size);
# ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	BOOST_CHECK(x != ev.max_transform_feedback_buffers);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	x = ev.max_transform_feedback_buffers;
	BOOST_CHECK(x == ev.max_transform_feedback_buffers);
# ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_interleaved_components);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	x = ev.max_transform_feedback_interleaved_components;
	BOOST_CHECK(x == ev.max_transform_feedback_interleaved_components);
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_attribs);
# endif
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	x = ev.max_transform_feedback_separate_attribs;
	BOOST_CHECK(x == ev.max_transform_feedback_separate_attribs);
# ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	BOOST_CHECK(x != ev.max_transform_feedback_separate_components);
# endif
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	x = ev.max_transform_feedback_separate_components;
	BOOST_CHECK(x == ev.max_transform_feedback_separate_components);
# ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	BOOST_CHECK(x != ev.max_uniform_block_size);
# endif
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	x = ev.max_uniform_block_size;
	BOOST_CHECK(x == ev.max_uniform_block_size);
# ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	BOOST_CHECK(x != ev.max_uniform_buffer_bindings);
# endif
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	x = ev.max_uniform_buffer_bindings;
	BOOST_CHECK(x == ev.max_uniform_buffer_bindings);
# ifdef GL_MAX_VARYING_COMPONENTS
	BOOST_CHECK(x != ev.max_varying_components);
# endif
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_VARYING_COMPONENTS
	x = ev.max_varying_components;
	BOOST_CHECK(x == ev.max_varying_components);
# ifdef GL_MAX_VARYING_VECTORS
	BOOST_CHECK(x != ev.max_varying_vectors);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_VARYING_VECTORS
	x = ev.max_varying_vectors;
	BOOST_CHECK(x == ev.max_varying_vectors);
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counter_buffers);
# endif
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	x = ev.max_vertex_atomic_counter_buffers;
	BOOST_CHECK(x == ev.max_vertex_atomic_counter_buffers);
# ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	BOOST_CHECK(x != ev.max_vertex_atomic_counters);
# endif
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	x = ev.max_vertex_atomic_counters;
	BOOST_CHECK(x == ev.max_vertex_atomic_counters);
# ifdef GL_MAX_VERTEX_ATTRIBS
	BOOST_CHECK(x != ev.max_vertex_attribs);
# endif
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_VERTEX_ATTRIBS
	x = ev.max_vertex_attribs;
	BOOST_CHECK(x == ev.max_vertex_attribs);
# ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	BOOST_CHECK(x != ev.max_vertex_image_uniforms);
# endif
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	x = ev.max_vertex_image_uniforms;
	BOOST_CHECK(x == ev.max_vertex_image_uniforms);
# ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_output_components);
# endif
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	x = ev.max_vertex_output_components;
	BOOST_CHECK(x == ev.max_vertex_output_components);
# ifdef GL_MAX_VERTEX_STREAMS
	BOOST_CHECK(x != ev.max_vertex_streams);
# endif
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_VERTEX_STREAMS
	x = ev.max_vertex_streams;
	BOOST_CHECK(x == ev.max_vertex_streams);
# ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	BOOST_CHECK(x != ev.max_vertex_texture_image_units);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	x = ev.max_vertex_texture_image_units;
	BOOST_CHECK(x == ev.max_vertex_texture_image_units);
# ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	BOOST_CHECK(x != ev.max_vertex_uniform_blocks);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	x = ev.max_vertex_uniform_blocks;
	BOOST_CHECK(x == ev.max_vertex_uniform_blocks);
# ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	BOOST_CHECK(x != ev.max_vertex_uniform_components);
# endif
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	x = ev.max_vertex_uniform_components;
	BOOST_CHECK(x == ev.max_vertex_uniform_components);
# ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	BOOST_CHECK(x != ev.max_vertex_uniform_vectors);
# endif
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	x = ev.max_vertex_uniform_vectors;
	BOOST_CHECK(x == ev.max_vertex_uniform_vectors);
# ifdef GL_MAX_VIEWPORT_DIMS
	BOOST_CHECK(x != ev.max_viewport_dims);
# endif
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_VIEWPORT_DIMS
	x = ev.max_viewport_dims;
	BOOST_CHECK(x == ev.max_viewport_dims);
# ifdef GL_MAX_VIEWPORTS
	BOOST_CHECK(x != ev.max_viewports);
# endif
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MAX_VIEWPORTS
	x = ev.max_viewports;
	BOOST_CHECK(x == ev.max_viewports);
# ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	BOOST_CHECK(x != ev.min_fragment_interpolation_offset);
# endif
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	x = ev.min_fragment_interpolation_offset;
	BOOST_CHECK(x == ev.min_fragment_interpolation_offset);
# ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	BOOST_CHECK(x != ev.min_map_buffer_alignment);
# endif
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	x = ev.min_map_buffer_alignment;
	BOOST_CHECK(x == ev.min_map_buffer_alignment);
# ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	BOOST_CHECK(x != ev.min_program_texel_offset);
# endif
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	x = ev.min_program_texel_offset;
	BOOST_CHECK(x == ev.min_program_texel_offset);
# ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	BOOST_CHECK(x != ev.min_program_texture_gather_offset);
# endif
#endif

#ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	x = ev.min_program_texture_gather_offset;
	BOOST_CHECK(x == ev.min_program_texture_gather_offset);
#endif
}

BOOST_AUTO_TEST_CASE(enum_limit_query_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	limit_query x;
	(void)x;

#ifdef GL_MAX_3D_TEXTURE_SIZE
	x = ev.max_3d_texture_size;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_3D_TEXTURE_SIZE"
	) == 0);
#endif

#ifdef GL_MAX_ARRAY_TEXTURE_LAYERS
	x = ev.max_array_texture_layers;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_ARRAY_TEXTURE_LAYERS"
	) == 0);
#endif

#ifdef GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS
	x = ev.max_atomic_counter_buffer_bindings;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_ATOMIC_COUNTER_BUFFER_BINDINGS"
	) == 0);
#endif

#ifdef GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE
	x = ev.max_atomic_counter_buffer_size;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_ATOMIC_COUNTER_BUFFER_SIZE"
	) == 0);
#endif

#ifdef GL_MAX_CLIP_DISTANCES
	x = ev.max_clip_distances;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_CLIP_DISTANCES"
	) == 0);
#endif

#ifdef GL_MAX_COLOR_ATTACHMENTS
	x = ev.max_color_attachments;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_COLOR_ATTACHMENTS"
	) == 0);
#endif

#ifdef GL_MAX_COLOR_TEXTURE_SAMPLES
	x = ev.max_color_texture_samples;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_COLOR_TEXTURE_SAMPLES"
	) == 0);
#endif

#ifdef GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS
	x = ev.max_combined_atomic_counter_buffers;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_COMBINED_ATOMIC_COUNTER_BUFFERS"
	) == 0);
#endif

#ifdef GL_MAX_COMBINED_ATOMIC_COUNTERS
	x = ev.max_combined_atomic_counters;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_COMBINED_ATOMIC_COUNTERS"
	) == 0);
#endif

#ifdef GL_MAX_COMBINED_CLIP_AND_CULL_DISTANCES
	x = ev.max_combined_clip_and_cull_distances;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_COMBINED_CLIP_AND_CULL_DISTANCES"
	) == 0);
#endif

#ifdef GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS
	x = ev.max_combined_fragment_uniform_components;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS"
	) == 0);
#endif

#ifdef GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS
	x = ev.max_combined_geometry_uniform_components;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS"
	) == 0);
#endif

#ifdef GL_MAX_COMBINED_IMAGE_UNIFORMS
	x = ev.max_combined_image_uniforms;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_COMBINED_IMAGE_UNIFORMS"
	) == 0);
#endif

#ifdef GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS
	x = ev.max_combined_image_units_and_fragment_outputs;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS"
	) == 0);
#endif

#ifdef GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS
	x = ev.max_combined_tess_control_uniform_components;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS"
	) == 0);
#endif

#ifdef GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS
	x = ev.max_combined_tess_evaluation_uniform_components;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS"
	) == 0);
#endif

#ifdef GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS
	x = ev.max_combined_texture_image_units;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_COMBINED_TEXTURE_IMAGE_UNITS"
	) == 0);
#endif

#ifdef GL_MAX_COMBINED_UNIFORM_BLOCKS
	x = ev.max_combined_uniform_blocks;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_COMBINED_UNIFORM_BLOCKS"
	) == 0);
#endif

#ifdef GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS
	x = ev.max_combined_vertex_uniform_components;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS"
	) == 0);
#endif

#ifdef GL_MAX_COMPUTE_SHARED_MEMORY_SIZE
	x = ev.max_compute_shared_memory_size;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_COMPUTE_SHARED_MEMORY_SIZE"
	) == 0);
#endif

#ifdef GL_MAX_COMPUTE_WORK_GROUP_COUNT
	x = ev.max_compute_work_group_count;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_COMPUTE_WORK_GROUP_COUNT"
	) == 0);
#endif

#ifdef GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS
	x = ev.max_compute_work_group_invocations;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_COMPUTE_WORK_GROUP_INVOCATIONS"
	) == 0);
#endif

#ifdef GL_MAX_COMPUTE_WORK_GROUP_SIZE
	x = ev.max_compute_work_group_size;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_COMPUTE_WORK_GROUP_SIZE"
	) == 0);
#endif

#ifdef GL_MAX_CUBE_MAP_TEXTURE_SIZE
	x = ev.max_cube_map_texture_size;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_CUBE_MAP_TEXTURE_SIZE"
	) == 0);
#endif

#ifdef GL_MAX_CULL_DISTANCES
	x = ev.max_cull_distances;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_CULL_DISTANCES"
	) == 0);
#endif

#ifdef GL_MAX_DEPTH_TEXTURE_SAMPLES
	x = ev.max_depth_texture_samples;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_DEPTH_TEXTURE_SAMPLES"
	) == 0);
#endif

#ifdef GL_MAX_DRAW_BUFFERS
	x = ev.max_draw_buffers;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_DRAW_BUFFERS"
	) == 0);
#endif

#ifdef GL_MAX_DUAL_SOURCE_DRAW_BUFFERS
	x = ev.max_dual_source_draw_buffers;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_DUAL_SOURCE_DRAW_BUFFERS"
	) == 0);
#endif

#ifdef GL_MAX_ELEMENTS_INDICES
	x = ev.max_elements_indices;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_ELEMENTS_INDICES"
	) == 0);
#endif

#ifdef GL_MAX_ELEMENTS_VERTICES
	x = ev.max_elements_vertices;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_ELEMENTS_VERTICES"
	) == 0);
#endif

#ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS
	x = ev.max_fragment_atomic_counter_buffers;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS"
	) == 0);
#endif

#ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTERS
	x = ev.max_fragment_atomic_counters;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_FRAGMENT_ATOMIC_COUNTERS"
	) == 0);
#endif

#ifdef GL_MAX_FRAGMENT_IMAGE_UNIFORMS
	x = ev.max_fragment_image_uniforms;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_FRAGMENT_IMAGE_UNIFORMS"
	) == 0);
#endif

#ifdef GL_MAX_FRAGMENT_INPUT_COMPONENTS
	x = ev.max_fragment_input_components;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_FRAGMENT_INPUT_COMPONENTS"
	) == 0);
#endif

#ifdef GL_MAX_FRAGMENT_INTERPOLATION_OFFSET
	x = ev.max_fragment_interpolation_offset;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_FRAGMENT_INTERPOLATION_OFFSET"
	) == 0);
#endif

#ifdef GL_MAX_FRAGMENT_UNIFORM_BLOCKS
	x = ev.max_fragment_uniform_blocks;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_FRAGMENT_UNIFORM_BLOCKS"
	) == 0);
#endif

#ifdef GL_MAX_FRAGMENT_UNIFORM_COMPONENTS
	x = ev.max_fragment_uniform_components;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_FRAGMENT_UNIFORM_COMPONENTS"
	) == 0);
#endif

#ifdef GL_MAX_FRAGMENT_UNIFORM_VECTORS
	x = ev.max_fragment_uniform_vectors;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_FRAGMENT_UNIFORM_VECTORS"
	) == 0);
#endif

#ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS
	x = ev.max_geometry_atomic_counter_buffers;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS"
	) == 0);
#endif

#ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTERS
	x = ev.max_geometry_atomic_counters;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_GEOMETRY_ATOMIC_COUNTERS"
	) == 0);
#endif

#ifdef GL_MAX_GEOMETRY_IMAGE_UNIFORMS
	x = ev.max_geometry_image_uniforms;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_GEOMETRY_IMAGE_UNIFORMS"
	) == 0);
#endif

#ifdef GL_MAX_GEOMETRY_INPUT_COMPONENTS
	x = ev.max_geometry_input_components;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_GEOMETRY_INPUT_COMPONENTS"
	) == 0);
#endif

#ifdef GL_MAX_GEOMETRY_OUTPUT_COMPONENTS
	x = ev.max_geometry_output_components;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_GEOMETRY_OUTPUT_COMPONENTS"
	) == 0);
#endif

#ifdef GL_MAX_GEOMETRY_OUTPUT_VERTICES
	x = ev.max_geometry_output_vertices;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_GEOMETRY_OUTPUT_VERTICES"
	) == 0);
#endif

#ifdef GL_MAX_GEOMETRY_SHADER_INVOCATIONS
	x = ev.max_geometry_shader_invocations;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_GEOMETRY_SHADER_INVOCATIONS"
	) == 0);
#endif

#ifdef GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS
	x = ev.max_geometry_texture_image_units;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_GEOMETRY_TEXTURE_IMAGE_UNITS"
	) == 0);
#endif

#ifdef GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS
	x = ev.max_geometry_total_output_components;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS"
	) == 0);
#endif

#ifdef GL_MAX_GEOMETRY_UNIFORM_BLOCKS
	x = ev.max_geometry_uniform_blocks;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_GEOMETRY_UNIFORM_BLOCKS"
	) == 0);
#endif

#ifdef GL_MAX_GEOMETRY_UNIFORM_COMPONENTS
	x = ev.max_geometry_uniform_components;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_GEOMETRY_UNIFORM_COMPONENTS"
	) == 0);
#endif

#ifdef GL_MAX_IMAGE_SAMPLES
	x = ev.max_image_samples;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_IMAGE_SAMPLES"
	) == 0);
#endif

#ifdef GL_MAX_IMAGE_UNITS
	x = ev.max_image_units;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_IMAGE_UNITS"
	) == 0);
#endif

#ifdef GL_MAX_INTEGER_SAMPLES
	x = ev.max_integer_samples;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_INTEGER_SAMPLES"
	) == 0);
#endif

#ifdef GL_MAX_PATCH_VERTICES
	x = ev.max_patch_vertices;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_PATCH_VERTICES"
	) == 0);
#endif

#ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
	x = ev.max_program_texel_offset;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_PROGRAM_TEXEL_OFFSET"
	) == 0);
#endif

#ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
	x = ev.max_program_texture_gather_offset;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_PROGRAM_TEXTURE_GATHER_OFFSET"
	) == 0);
#endif

#ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
	x = ev.max_rectangle_texture_size;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_RECTANGLE_TEXTURE_SIZE"
	) == 0);
#endif

#ifdef GL_MAX_RENDERBUFFER_SIZE
	x = ev.max_renderbuffer_size;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_RENDERBUFFER_SIZE"
	) == 0);
#endif

#ifdef GL_MAX_SAMPLE_MASK_WORDS
	x = ev.max_sample_mask_words;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_SAMPLE_MASK_WORDS"
	) == 0);
#endif

#ifdef GL_MAX_SAMPLES
	x = ev.max_samples;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_SAMPLES"
	) == 0);
#endif

#ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	x = ev.max_server_wait_timeout;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_SERVER_WAIT_TIMEOUT"
	) == 0);
#endif

#ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	x = ev.max_subroutine_uniform_locations;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_SUBROUTINE_UNIFORM_LOCATIONS"
	) == 0);
#endif

#ifdef GL_MAX_SUBROUTINES
	x = ev.max_subroutines;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_SUBROUTINES"
	) == 0);
#endif

#ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	x = ev.max_tess_control_atomic_counter_buffers;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS"
	) == 0);
#endif

#ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	x = ev.max_tess_control_atomic_counters;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_TESS_CONTROL_ATOMIC_COUNTERS"
	) == 0);
#endif

#ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	x = ev.max_tess_control_image_uniforms;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_TESS_CONTROL_IMAGE_UNIFORMS"
	) == 0);
#endif

#ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	x = ev.max_tess_control_input_components;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_TESS_CONTROL_INPUT_COMPONENTS"
	) == 0);
#endif

#ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	x = ev.max_tess_control_output_components;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_TESS_CONTROL_OUTPUT_COMPONENTS"
	) == 0);
#endif

#ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	x = ev.max_tess_control_texture_image_units;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS"
	) == 0);
#endif

#ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	x = ev.max_tess_control_total_output_components;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS"
	) == 0);
#endif

#ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	x = ev.max_tess_control_uniform_blocks;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_TESS_CONTROL_UNIFORM_BLOCKS"
	) == 0);
#endif

#ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	x = ev.max_tess_control_uniform_components;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_TESS_CONTROL_UNIFORM_COMPONENTS"
	) == 0);
#endif

#ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	x = ev.max_tess_evaluation_atomic_counter_buffers;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS"
	) == 0);
#endif

#ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	x = ev.max_tess_evaluation_atomic_counters;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_TESS_EVALUATION_ATOMIC_COUNTERS"
	) == 0);
#endif

#ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	x = ev.max_tess_evaluation_image_uniforms;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_TESS_EVALUATION_IMAGE_UNIFORMS"
	) == 0);
#endif

#ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	x = ev.max_tess_evaluation_input_components;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_TESS_EVALUATION_INPUT_COMPONENTS"
	) == 0);
#endif

#ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	x = ev.max_tess_evaluation_output_components;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_TESS_EVALUATION_OUTPUT_COMPONENTS"
	) == 0);
#endif

#ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	x = ev.max_tess_evaluation_texture_image_units;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS"
	) == 0);
#endif

#ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	x = ev.max_tess_evaluation_uniform_blocks;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_TESS_EVALUATION_UNIFORM_BLOCKS"
	) == 0);
#endif

#ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	x = ev.max_tess_evaluation_uniform_components;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_TESS_EVALUATION_UNIFORM_COMPONENTS"
	) == 0);
#endif

#ifdef GL_MAX_TESS_GEN_LEVEL
	x = ev.max_tess_gen_level;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_TESS_GEN_LEVEL"
	) == 0);
#endif

#ifdef GL_MAX_TESS_PATCH_COMPONENTS
	x = ev.max_tess_patch_components;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_TESS_PATCH_COMPONENTS"
	) == 0);
#endif

#ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	x = ev.max_texture_buffer_size;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_TEXTURE_BUFFER_SIZE"
	) == 0);
#endif

#ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	x = ev.max_texture_image_units;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_TEXTURE_IMAGE_UNITS"
	) == 0);
#endif

#ifdef GL_MAX_TEXTURE_LOD_BIAS
	x = ev.max_texture_lod_bias;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_TEXTURE_LOD_BIAS"
	) == 0);
#endif

#ifdef GL_MAX_TEXTURE_SIZE
	x = ev.max_texture_size;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_TEXTURE_SIZE"
	) == 0);
#endif

#ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	x = ev.max_transform_feedback_buffers;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_TRANSFORM_FEEDBACK_BUFFERS"
	) == 0);
#endif

#ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	x = ev.max_transform_feedback_interleaved_components;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS"
	) == 0);
#endif

#ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	x = ev.max_transform_feedback_separate_attribs;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS"
	) == 0);
#endif

#ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	x = ev.max_transform_feedback_separate_components;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS"
	) == 0);
#endif

#ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	x = ev.max_uniform_block_size;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_UNIFORM_BLOCK_SIZE"
	) == 0);
#endif

#ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	x = ev.max_uniform_buffer_bindings;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_UNIFORM_BUFFER_BINDINGS"
	) == 0);
#endif

#ifdef GL_MAX_VARYING_COMPONENTS
	x = ev.max_varying_components;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_VARYING_COMPONENTS"
	) == 0);
#endif

#ifdef GL_MAX_VARYING_VECTORS
	x = ev.max_varying_vectors;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_VARYING_VECTORS"
	) == 0);
#endif

#ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	x = ev.max_vertex_atomic_counter_buffers;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_VERTEX_ATOMIC_COUNTER_BUFFERS"
	) == 0);
#endif

#ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	x = ev.max_vertex_atomic_counters;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_VERTEX_ATOMIC_COUNTERS"
	) == 0);
#endif

#ifdef GL_MAX_VERTEX_ATTRIBS
	x = ev.max_vertex_attribs;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_VERTEX_ATTRIBS"
	) == 0);
#endif

#ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	x = ev.max_vertex_image_uniforms;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_VERTEX_IMAGE_UNIFORMS"
	) == 0);
#endif

#ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	x = ev.max_vertex_output_components;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_VERTEX_OUTPUT_COMPONENTS"
	) == 0);
#endif

#ifdef GL_MAX_VERTEX_STREAMS
	x = ev.max_vertex_streams;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_VERTEX_STREAMS"
	) == 0);
#endif

#ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	x = ev.max_vertex_texture_image_units;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_VERTEX_TEXTURE_IMAGE_UNITS"
	) == 0);
#endif

#ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	x = ev.max_vertex_uniform_blocks;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_VERTEX_UNIFORM_BLOCKS"
	) == 0);
#endif

#ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	x = ev.max_vertex_uniform_components;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_VERTEX_UNIFORM_COMPONENTS"
	) == 0);
#endif

#ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	x = ev.max_vertex_uniform_vectors;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_VERTEX_UNIFORM_VECTORS"
	) == 0);
#endif

#ifdef GL_MAX_VIEWPORT_DIMS
	x = ev.max_viewport_dims;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_VIEWPORT_DIMS"
	) == 0);
#endif

#ifdef GL_MAX_VIEWPORTS
	x = ev.max_viewports;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAX_VIEWPORTS"
	) == 0);
#endif

#ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	x = ev.min_fragment_interpolation_offset;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MIN_FRAGMENT_INTERPOLATION_OFFSET"
	) == 0);
#endif

#ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	x = ev.min_map_buffer_alignment;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MIN_MAP_BUFFER_ALIGNMENT"
	) == 0);
#endif

#ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	x = ev.min_program_texel_offset;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MIN_PROGRAM_TEXEL_OFFSET"
	) == 0);
#endif

#ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	x = ev.min_program_texture_gather_offset;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MIN_PROGRAM_TEXTURE_GATHER_OFFSET"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_limit_query_range)
{
	using namespace oglplus;
	auto count = enum_value_range<limit_query>().size();

#ifdef GL_MAX_3D_TEXTURE_SIZE
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_3D_TEXTURE_SIZE)
	) != r.end());
}
#endif

#ifdef GL_MAX_ARRAY_TEXTURE_LAYERS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_ARRAY_TEXTURE_LAYERS)
	) != r.end());
}
#endif

#ifdef GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS)
	) != r.end());
}
#endif

#ifdef GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE)
	) != r.end());
}
#endif

#ifdef GL_MAX_CLIP_DISTANCES
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_CLIP_DISTANCES)
	) != r.end());
}
#endif

#ifdef GL_MAX_COLOR_ATTACHMENTS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_COLOR_ATTACHMENTS)
	) != r.end());
}
#endif

#ifdef GL_MAX_COLOR_TEXTURE_SAMPLES
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_COLOR_TEXTURE_SAMPLES)
	) != r.end());
}
#endif

#ifdef GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS)
	) != r.end());
}
#endif

#ifdef GL_MAX_COMBINED_ATOMIC_COUNTERS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_COMBINED_ATOMIC_COUNTERS)
	) != r.end());
}
#endif

#ifdef GL_MAX_COMBINED_CLIP_AND_CULL_DISTANCES
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_COMBINED_CLIP_AND_CULL_DISTANCES)
	) != r.end());
}
#endif

#ifdef GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS)
	) != r.end());
}
#endif

#ifdef GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS)
	) != r.end());
}
#endif

#ifdef GL_MAX_COMBINED_IMAGE_UNIFORMS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_COMBINED_IMAGE_UNIFORMS)
	) != r.end());
}
#endif

#ifdef GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS)
	) != r.end());
}
#endif

#ifdef GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS)
	) != r.end());
}
#endif

#ifdef GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS)
	) != r.end());
}
#endif

#ifdef GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS)
	) != r.end());
}
#endif

#ifdef GL_MAX_COMBINED_UNIFORM_BLOCKS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_COMBINED_UNIFORM_BLOCKS)
	) != r.end());
}
#endif

#ifdef GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS)
	) != r.end());
}
#endif

#ifdef GL_MAX_COMPUTE_SHARED_MEMORY_SIZE
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_COMPUTE_SHARED_MEMORY_SIZE)
	) != r.end());
}
#endif

#ifdef GL_MAX_COMPUTE_WORK_GROUP_COUNT
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_COMPUTE_WORK_GROUP_COUNT)
	) != r.end());
}
#endif

#ifdef GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS)
	) != r.end());
}
#endif

#ifdef GL_MAX_COMPUTE_WORK_GROUP_SIZE
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_COMPUTE_WORK_GROUP_SIZE)
	) != r.end());
}
#endif

#ifdef GL_MAX_CUBE_MAP_TEXTURE_SIZE
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_CUBE_MAP_TEXTURE_SIZE)
	) != r.end());
}
#endif

#ifdef GL_MAX_CULL_DISTANCES
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_CULL_DISTANCES)
	) != r.end());
}
#endif

#ifdef GL_MAX_DEPTH_TEXTURE_SAMPLES
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_DEPTH_TEXTURE_SAMPLES)
	) != r.end());
}
#endif

#ifdef GL_MAX_DRAW_BUFFERS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_DRAW_BUFFERS)
	) != r.end());
}
#endif

#ifdef GL_MAX_DUAL_SOURCE_DRAW_BUFFERS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_DUAL_SOURCE_DRAW_BUFFERS)
	) != r.end());
}
#endif

#ifdef GL_MAX_ELEMENTS_INDICES
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_ELEMENTS_INDICES)
	) != r.end());
}
#endif

#ifdef GL_MAX_ELEMENTS_VERTICES
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_ELEMENTS_VERTICES)
	) != r.end());
}
#endif

#ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS)
	) != r.end());
}
#endif

#ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTERS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_FRAGMENT_ATOMIC_COUNTERS)
	) != r.end());
}
#endif

#ifdef GL_MAX_FRAGMENT_IMAGE_UNIFORMS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_FRAGMENT_IMAGE_UNIFORMS)
	) != r.end());
}
#endif

#ifdef GL_MAX_FRAGMENT_INPUT_COMPONENTS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_FRAGMENT_INPUT_COMPONENTS)
	) != r.end());
}
#endif

#ifdef GL_MAX_FRAGMENT_INTERPOLATION_OFFSET
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_FRAGMENT_INTERPOLATION_OFFSET)
	) != r.end());
}
#endif

#ifdef GL_MAX_FRAGMENT_UNIFORM_BLOCKS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_FRAGMENT_UNIFORM_BLOCKS)
	) != r.end());
}
#endif

#ifdef GL_MAX_FRAGMENT_UNIFORM_COMPONENTS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_FRAGMENT_UNIFORM_COMPONENTS)
	) != r.end());
}
#endif

#ifdef GL_MAX_FRAGMENT_UNIFORM_VECTORS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_FRAGMENT_UNIFORM_VECTORS)
	) != r.end());
}
#endif

#ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS)
	) != r.end());
}
#endif

#ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTERS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_GEOMETRY_ATOMIC_COUNTERS)
	) != r.end());
}
#endif

#ifdef GL_MAX_GEOMETRY_IMAGE_UNIFORMS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_GEOMETRY_IMAGE_UNIFORMS)
	) != r.end());
}
#endif

#ifdef GL_MAX_GEOMETRY_INPUT_COMPONENTS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_GEOMETRY_INPUT_COMPONENTS)
	) != r.end());
}
#endif

#ifdef GL_MAX_GEOMETRY_OUTPUT_COMPONENTS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_GEOMETRY_OUTPUT_COMPONENTS)
	) != r.end());
}
#endif

#ifdef GL_MAX_GEOMETRY_OUTPUT_VERTICES
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_GEOMETRY_OUTPUT_VERTICES)
	) != r.end());
}
#endif

#ifdef GL_MAX_GEOMETRY_SHADER_INVOCATIONS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_GEOMETRY_SHADER_INVOCATIONS)
	) != r.end());
}
#endif

#ifdef GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS)
	) != r.end());
}
#endif

#ifdef GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS)
	) != r.end());
}
#endif

#ifdef GL_MAX_GEOMETRY_UNIFORM_BLOCKS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_GEOMETRY_UNIFORM_BLOCKS)
	) != r.end());
}
#endif

#ifdef GL_MAX_GEOMETRY_UNIFORM_COMPONENTS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_GEOMETRY_UNIFORM_COMPONENTS)
	) != r.end());
}
#endif

#ifdef GL_MAX_IMAGE_SAMPLES
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_IMAGE_SAMPLES)
	) != r.end());
}
#endif

#ifdef GL_MAX_IMAGE_UNITS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_IMAGE_UNITS)
	) != r.end());
}
#endif

#ifdef GL_MAX_INTEGER_SAMPLES
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_INTEGER_SAMPLES)
	) != r.end());
}
#endif

#ifdef GL_MAX_PATCH_VERTICES
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_PATCH_VERTICES)
	) != r.end());
}
#endif

#ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_PROGRAM_TEXEL_OFFSET)
	) != r.end());
}
#endif

#ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET)
	) != r.end());
}
#endif

#ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_RECTANGLE_TEXTURE_SIZE)
	) != r.end());
}
#endif

#ifdef GL_MAX_RENDERBUFFER_SIZE
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_RENDERBUFFER_SIZE)
	) != r.end());
}
#endif

#ifdef GL_MAX_SAMPLE_MASK_WORDS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_SAMPLE_MASK_WORDS)
	) != r.end());
}
#endif

#ifdef GL_MAX_SAMPLES
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_SAMPLES)
	) != r.end());
}
#endif

#ifdef GL_MAX_SERVER_WAIT_TIMEOUT
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_SERVER_WAIT_TIMEOUT)
	) != r.end());
}
#endif

#ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS)
	) != r.end());
}
#endif

#ifdef GL_MAX_SUBROUTINES
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_SUBROUTINES)
	) != r.end());
}
#endif

#ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS)
	) != r.end());
}
#endif

#ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS)
	) != r.end());
}
#endif

#ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS)
	) != r.end());
}
#endif

#ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_TESS_CONTROL_INPUT_COMPONENTS)
	) != r.end());
}
#endif

#ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS)
	) != r.end());
}
#endif

#ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS)
	) != r.end());
}
#endif

#ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS)
	) != r.end());
}
#endif

#ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS)
	) != r.end());
}
#endif

#ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS)
	) != r.end());
}
#endif

#ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS)
	) != r.end());
}
#endif

#ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS)
	) != r.end());
}
#endif

#ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS)
	) != r.end());
}
#endif

#ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS)
	) != r.end());
}
#endif

#ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS)
	) != r.end());
}
#endif

#ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS)
	) != r.end());
}
#endif

#ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS)
	) != r.end());
}
#endif

#ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS)
	) != r.end());
}
#endif

#ifdef GL_MAX_TESS_GEN_LEVEL
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_TESS_GEN_LEVEL)
	) != r.end());
}
#endif

#ifdef GL_MAX_TESS_PATCH_COMPONENTS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_TESS_PATCH_COMPONENTS)
	) != r.end());
}
#endif

#ifdef GL_MAX_TEXTURE_BUFFER_SIZE
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_TEXTURE_BUFFER_SIZE)
	) != r.end());
}
#endif

#ifdef GL_MAX_TEXTURE_IMAGE_UNITS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_TEXTURE_IMAGE_UNITS)
	) != r.end());
}
#endif

#ifdef GL_MAX_TEXTURE_LOD_BIAS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_TEXTURE_LOD_BIAS)
	) != r.end());
}
#endif

#ifdef GL_MAX_TEXTURE_SIZE
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_TEXTURE_SIZE)
	) != r.end());
}
#endif

#ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_TRANSFORM_FEEDBACK_BUFFERS)
	) != r.end());
}
#endif

#ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS)
	) != r.end());
}
#endif

#ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS)
	) != r.end());
}
#endif

#ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS)
	) != r.end());
}
#endif

#ifdef GL_MAX_UNIFORM_BLOCK_SIZE
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_UNIFORM_BLOCK_SIZE)
	) != r.end());
}
#endif

#ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_UNIFORM_BUFFER_BINDINGS)
	) != r.end());
}
#endif

#ifdef GL_MAX_VARYING_COMPONENTS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_VARYING_COMPONENTS)
	) != r.end());
}
#endif

#ifdef GL_MAX_VARYING_VECTORS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_VARYING_VECTORS)
	) != r.end());
}
#endif

#ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS)
	) != r.end());
}
#endif

#ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_VERTEX_ATOMIC_COUNTERS)
	) != r.end());
}
#endif

#ifdef GL_MAX_VERTEX_ATTRIBS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_VERTEX_ATTRIBS)
	) != r.end());
}
#endif

#ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_VERTEX_IMAGE_UNIFORMS)
	) != r.end());
}
#endif

#ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_VERTEX_OUTPUT_COMPONENTS)
	) != r.end());
}
#endif

#ifdef GL_MAX_VERTEX_STREAMS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_VERTEX_STREAMS)
	) != r.end());
}
#endif

#ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS)
	) != r.end());
}
#endif

#ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_VERTEX_UNIFORM_BLOCKS)
	) != r.end());
}
#endif

#ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_VERTEX_UNIFORM_COMPONENTS)
	) != r.end());
}
#endif

#ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_VERTEX_UNIFORM_VECTORS)
	) != r.end());
}
#endif

#ifdef GL_MAX_VIEWPORT_DIMS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_VIEWPORT_DIMS)
	) != r.end());
}
#endif

#ifdef GL_MAX_VIEWPORTS
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MAX_VIEWPORTS)
	) != r.end());
}
#endif

#ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MIN_FRAGMENT_INTERPOLATION_OFFSET)
	) != r.end());
}
#endif

#ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MIN_MAP_BUFFER_ALIGNMENT)
	) != r.end());
}
#endif

#ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MIN_PROGRAM_TEXEL_OFFSET)
	) != r.end());
}
#endif

#ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
{
	--count;
	auto r = enum_value_range<limit_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		limit_query(GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_limit_query_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	limit_query x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_MAX_3D_TEXTURE_SIZE
	x = ev.max_3d_texture_size;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_3d_texture_size);
#endif

#ifdef GL_MAX_ARRAY_TEXTURE_LAYERS
	x = ev.max_array_texture_layers;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_array_texture_layers);
#endif

#ifdef GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS
	x = ev.max_atomic_counter_buffer_bindings;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_atomic_counter_buffer_bindings);
#endif

#ifdef GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE
	x = ev.max_atomic_counter_buffer_size;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_atomic_counter_buffer_size);
#endif

#ifdef GL_MAX_CLIP_DISTANCES
	x = ev.max_clip_distances;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_clip_distances);
#endif

#ifdef GL_MAX_COLOR_ATTACHMENTS
	x = ev.max_color_attachments;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_color_attachments);
#endif

#ifdef GL_MAX_COLOR_TEXTURE_SAMPLES
	x = ev.max_color_texture_samples;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_color_texture_samples);
#endif

#ifdef GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS
	x = ev.max_combined_atomic_counter_buffers;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_combined_atomic_counter_buffers);
#endif

#ifdef GL_MAX_COMBINED_ATOMIC_COUNTERS
	x = ev.max_combined_atomic_counters;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_combined_atomic_counters);
#endif

#ifdef GL_MAX_COMBINED_CLIP_AND_CULL_DISTANCES
	x = ev.max_combined_clip_and_cull_distances;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_combined_clip_and_cull_distances);
#endif

#ifdef GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS
	x = ev.max_combined_fragment_uniform_components;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_combined_fragment_uniform_components);
#endif

#ifdef GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS
	x = ev.max_combined_geometry_uniform_components;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_combined_geometry_uniform_components);
#endif

#ifdef GL_MAX_COMBINED_IMAGE_UNIFORMS
	x = ev.max_combined_image_uniforms;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_combined_image_uniforms);
#endif

#ifdef GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS
	x = ev.max_combined_image_units_and_fragment_outputs;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_combined_image_units_and_fragment_outputs);
#endif

#ifdef GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS
	x = ev.max_combined_tess_control_uniform_components;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_combined_tess_control_uniform_components);
#endif

#ifdef GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS
	x = ev.max_combined_tess_evaluation_uniform_components;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_combined_tess_evaluation_uniform_components);
#endif

#ifdef GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS
	x = ev.max_combined_texture_image_units;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_combined_texture_image_units);
#endif

#ifdef GL_MAX_COMBINED_UNIFORM_BLOCKS
	x = ev.max_combined_uniform_blocks;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_combined_uniform_blocks);
#endif

#ifdef GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS
	x = ev.max_combined_vertex_uniform_components;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_combined_vertex_uniform_components);
#endif

#ifdef GL_MAX_COMPUTE_SHARED_MEMORY_SIZE
	x = ev.max_compute_shared_memory_size;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_compute_shared_memory_size);
#endif

#ifdef GL_MAX_COMPUTE_WORK_GROUP_COUNT
	x = ev.max_compute_work_group_count;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_compute_work_group_count);
#endif

#ifdef GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS
	x = ev.max_compute_work_group_invocations;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_compute_work_group_invocations);
#endif

#ifdef GL_MAX_COMPUTE_WORK_GROUP_SIZE
	x = ev.max_compute_work_group_size;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_compute_work_group_size);
#endif

#ifdef GL_MAX_CUBE_MAP_TEXTURE_SIZE
	x = ev.max_cube_map_texture_size;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_cube_map_texture_size);
#endif

#ifdef GL_MAX_CULL_DISTANCES
	x = ev.max_cull_distances;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_cull_distances);
#endif

#ifdef GL_MAX_DEPTH_TEXTURE_SAMPLES
	x = ev.max_depth_texture_samples;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_depth_texture_samples);
#endif

#ifdef GL_MAX_DRAW_BUFFERS
	x = ev.max_draw_buffers;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_draw_buffers);
#endif

#ifdef GL_MAX_DUAL_SOURCE_DRAW_BUFFERS
	x = ev.max_dual_source_draw_buffers;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_dual_source_draw_buffers);
#endif

#ifdef GL_MAX_ELEMENTS_INDICES
	x = ev.max_elements_indices;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_elements_indices);
#endif

#ifdef GL_MAX_ELEMENTS_VERTICES
	x = ev.max_elements_vertices;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_elements_vertices);
#endif

#ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS
	x = ev.max_fragment_atomic_counter_buffers;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_fragment_atomic_counter_buffers);
#endif

#ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTERS
	x = ev.max_fragment_atomic_counters;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_fragment_atomic_counters);
#endif

#ifdef GL_MAX_FRAGMENT_IMAGE_UNIFORMS
	x = ev.max_fragment_image_uniforms;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_fragment_image_uniforms);
#endif

#ifdef GL_MAX_FRAGMENT_INPUT_COMPONENTS
	x = ev.max_fragment_input_components;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_fragment_input_components);
#endif

#ifdef GL_MAX_FRAGMENT_INTERPOLATION_OFFSET
	x = ev.max_fragment_interpolation_offset;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_fragment_interpolation_offset);
#endif

#ifdef GL_MAX_FRAGMENT_UNIFORM_BLOCKS
	x = ev.max_fragment_uniform_blocks;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_fragment_uniform_blocks);
#endif

#ifdef GL_MAX_FRAGMENT_UNIFORM_COMPONENTS
	x = ev.max_fragment_uniform_components;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_fragment_uniform_components);
#endif

#ifdef GL_MAX_FRAGMENT_UNIFORM_VECTORS
	x = ev.max_fragment_uniform_vectors;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_fragment_uniform_vectors);
#endif

#ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS
	x = ev.max_geometry_atomic_counter_buffers;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_geometry_atomic_counter_buffers);
#endif

#ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTERS
	x = ev.max_geometry_atomic_counters;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_geometry_atomic_counters);
#endif

#ifdef GL_MAX_GEOMETRY_IMAGE_UNIFORMS
	x = ev.max_geometry_image_uniforms;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_geometry_image_uniforms);
#endif

#ifdef GL_MAX_GEOMETRY_INPUT_COMPONENTS
	x = ev.max_geometry_input_components;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_geometry_input_components);
#endif

#ifdef GL_MAX_GEOMETRY_OUTPUT_COMPONENTS
	x = ev.max_geometry_output_components;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_geometry_output_components);
#endif

#ifdef GL_MAX_GEOMETRY_OUTPUT_VERTICES
	x = ev.max_geometry_output_vertices;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_geometry_output_vertices);
#endif

#ifdef GL_MAX_GEOMETRY_SHADER_INVOCATIONS
	x = ev.max_geometry_shader_invocations;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_geometry_shader_invocations);
#endif

#ifdef GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS
	x = ev.max_geometry_texture_image_units;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_geometry_texture_image_units);
#endif

#ifdef GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS
	x = ev.max_geometry_total_output_components;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_geometry_total_output_components);
#endif

#ifdef GL_MAX_GEOMETRY_UNIFORM_BLOCKS
	x = ev.max_geometry_uniform_blocks;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_geometry_uniform_blocks);
#endif

#ifdef GL_MAX_GEOMETRY_UNIFORM_COMPONENTS
	x = ev.max_geometry_uniform_components;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_geometry_uniform_components);
#endif

#ifdef GL_MAX_IMAGE_SAMPLES
	x = ev.max_image_samples;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_image_samples);
#endif

#ifdef GL_MAX_IMAGE_UNITS
	x = ev.max_image_units;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_image_units);
#endif

#ifdef GL_MAX_INTEGER_SAMPLES
	x = ev.max_integer_samples;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_integer_samples);
#endif

#ifdef GL_MAX_PATCH_VERTICES
	x = ev.max_patch_vertices;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_patch_vertices);
#endif

#ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
	x = ev.max_program_texel_offset;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_program_texel_offset);
#endif

#ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
	x = ev.max_program_texture_gather_offset;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_program_texture_gather_offset);
#endif

#ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
	x = ev.max_rectangle_texture_size;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_rectangle_texture_size);
#endif

#ifdef GL_MAX_RENDERBUFFER_SIZE
	x = ev.max_renderbuffer_size;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_renderbuffer_size);
#endif

#ifdef GL_MAX_SAMPLE_MASK_WORDS
	x = ev.max_sample_mask_words;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_sample_mask_words);
#endif

#ifdef GL_MAX_SAMPLES
	x = ev.max_samples;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_samples);
#endif

#ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	x = ev.max_server_wait_timeout;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_server_wait_timeout);
#endif

#ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	x = ev.max_subroutine_uniform_locations;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_subroutine_uniform_locations);
#endif

#ifdef GL_MAX_SUBROUTINES
	x = ev.max_subroutines;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_subroutines);
#endif

#ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	x = ev.max_tess_control_atomic_counter_buffers;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_tess_control_atomic_counter_buffers);
#endif

#ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	x = ev.max_tess_control_atomic_counters;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_tess_control_atomic_counters);
#endif

#ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	x = ev.max_tess_control_image_uniforms;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_tess_control_image_uniforms);
#endif

#ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	x = ev.max_tess_control_input_components;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_tess_control_input_components);
#endif

#ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	x = ev.max_tess_control_output_components;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_tess_control_output_components);
#endif

#ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	x = ev.max_tess_control_texture_image_units;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_tess_control_texture_image_units);
#endif

#ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	x = ev.max_tess_control_total_output_components;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_tess_control_total_output_components);
#endif

#ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	x = ev.max_tess_control_uniform_blocks;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_tess_control_uniform_blocks);
#endif

#ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	x = ev.max_tess_control_uniform_components;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_tess_control_uniform_components);
#endif

#ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	x = ev.max_tess_evaluation_atomic_counter_buffers;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_tess_evaluation_atomic_counter_buffers);
#endif

#ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	x = ev.max_tess_evaluation_atomic_counters;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_tess_evaluation_atomic_counters);
#endif

#ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	x = ev.max_tess_evaluation_image_uniforms;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_tess_evaluation_image_uniforms);
#endif

#ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	x = ev.max_tess_evaluation_input_components;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_tess_evaluation_input_components);
#endif

#ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	x = ev.max_tess_evaluation_output_components;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_tess_evaluation_output_components);
#endif

#ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	x = ev.max_tess_evaluation_texture_image_units;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_tess_evaluation_texture_image_units);
#endif

#ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	x = ev.max_tess_evaluation_uniform_blocks;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_tess_evaluation_uniform_blocks);
#endif

#ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	x = ev.max_tess_evaluation_uniform_components;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_tess_evaluation_uniform_components);
#endif

#ifdef GL_MAX_TESS_GEN_LEVEL
	x = ev.max_tess_gen_level;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_tess_gen_level);
#endif

#ifdef GL_MAX_TESS_PATCH_COMPONENTS
	x = ev.max_tess_patch_components;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_tess_patch_components);
#endif

#ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	x = ev.max_texture_buffer_size;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_texture_buffer_size);
#endif

#ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	x = ev.max_texture_image_units;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_texture_image_units);
#endif

#ifdef GL_MAX_TEXTURE_LOD_BIAS
	x = ev.max_texture_lod_bias;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_texture_lod_bias);
#endif

#ifdef GL_MAX_TEXTURE_SIZE
	x = ev.max_texture_size;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_texture_size);
#endif

#ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	x = ev.max_transform_feedback_buffers;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_transform_feedback_buffers);
#endif

#ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	x = ev.max_transform_feedback_interleaved_components;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_transform_feedback_interleaved_components);
#endif

#ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	x = ev.max_transform_feedback_separate_attribs;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_transform_feedback_separate_attribs);
#endif

#ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	x = ev.max_transform_feedback_separate_components;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_transform_feedback_separate_components);
#endif

#ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	x = ev.max_uniform_block_size;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_uniform_block_size);
#endif

#ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	x = ev.max_uniform_buffer_bindings;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_uniform_buffer_bindings);
#endif

#ifdef GL_MAX_VARYING_COMPONENTS
	x = ev.max_varying_components;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_varying_components);
#endif

#ifdef GL_MAX_VARYING_VECTORS
	x = ev.max_varying_vectors;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_varying_vectors);
#endif

#ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	x = ev.max_vertex_atomic_counter_buffers;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_vertex_atomic_counter_buffers);
#endif

#ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	x = ev.max_vertex_atomic_counters;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_vertex_atomic_counters);
#endif

#ifdef GL_MAX_VERTEX_ATTRIBS
	x = ev.max_vertex_attribs;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_vertex_attribs);
#endif

#ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	x = ev.max_vertex_image_uniforms;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_vertex_image_uniforms);
#endif

#ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	x = ev.max_vertex_output_components;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_vertex_output_components);
#endif

#ifdef GL_MAX_VERTEX_STREAMS
	x = ev.max_vertex_streams;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_vertex_streams);
#endif

#ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	x = ev.max_vertex_texture_image_units;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_vertex_texture_image_units);
#endif

#ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	x = ev.max_vertex_uniform_blocks;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_vertex_uniform_blocks);
#endif

#ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	x = ev.max_vertex_uniform_components;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_vertex_uniform_components);
#endif

#ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	x = ev.max_vertex_uniform_vectors;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_vertex_uniform_vectors);
#endif

#ifdef GL_MAX_VIEWPORT_DIMS
	x = ev.max_viewport_dims;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_viewport_dims);
#endif

#ifdef GL_MAX_VIEWPORTS
	x = ev.max_viewports;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.max_viewports);
#endif

#ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	x = ev.min_fragment_interpolation_offset;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.min_fragment_interpolation_offset);
#endif

#ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	x = ev.min_map_buffer_alignment;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.min_map_buffer_alignment);
#endif

#ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	x = ev.min_program_texel_offset;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.min_program_texel_offset);
#endif

#ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	x = ev.min_program_texture_gather_offset;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.min_program_texture_gather_offset);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
