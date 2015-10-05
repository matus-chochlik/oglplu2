//  File test/oglplus/enums/program_resource_property.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_program_resource_property

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_program_resource_property)

BOOST_AUTO_TEST_CASE(enum_program_resource_property_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	program_resource_property x;
	(void)x;

#ifdef GL_ACTIVE_VARIABLES
	x = ev.active_variables;
	BOOST_CHECK(x == ev.active_variables);
# ifdef GL_ARRAY_SIZE
	BOOST_CHECK(x != ev.array_size);
# endif
# ifdef GL_ARRAY_STRIDE
	BOOST_CHECK(x != ev.array_stride);
# endif
# ifdef GL_ATOMIC_COUNTER_BUFFER_INDEX
	BOOST_CHECK(x != ev.atomic_counter_buffer_index);
# endif
# ifdef GL_BLOCK_INDEX
	BOOST_CHECK(x != ev.block_index);
# endif
# ifdef GL_BUFFER_BINDING
	BOOST_CHECK(x != ev.buffer_binding);
# endif
# ifdef GL_BUFFER_DATA_SIZE
	BOOST_CHECK(x != ev.buffer_data_size);
# endif
# ifdef GL_COMPATIBLE_SUBROUTINES
	BOOST_CHECK(x != ev.compatible_subroutines);
# endif
# ifdef GL_IS_PER_PATCH
	BOOST_CHECK(x != ev.is_per_patch);
# endif
# ifdef GL_IS_ROW_MAJOR
	BOOST_CHECK(x != ev.is_row_major);
# endif
# ifdef GL_LOCATION
	BOOST_CHECK(x != ev.location);
# endif
# ifdef GL_LOCATION_COMPONENT
	BOOST_CHECK(x != ev.location_component);
# endif
# ifdef GL_LOCATION_INDEX
	BOOST_CHECK(x != ev.location_index);
# endif
# ifdef GL_MATRIX_STRIDE
	BOOST_CHECK(x != ev.matrix_stride);
# endif
# ifdef GL_NUM_ACTIVE_VARIABLES
	BOOST_CHECK(x != ev.num_active_variables);
# endif
# ifdef GL_NUM_COMPATIBLE_SUBROUTINES
	BOOST_CHECK(x != ev.num_compatible_subroutines);
# endif
# ifdef GL_OFFSET
	BOOST_CHECK(x != ev.offset);
# endif
# ifdef GL_REFERENCED_BY_COMPUTE_SHADER
	BOOST_CHECK(x != ev.referenced_by_compute_shader);
# endif
# ifdef GL_REFERENCED_BY_FRAGMENT_SHADER
	BOOST_CHECK(x != ev.referenced_by_fragment_shader);
# endif
# ifdef GL_REFERENCED_BY_GEOMETRY_SHADER
	BOOST_CHECK(x != ev.referenced_by_geometry_shader);
# endif
# ifdef GL_REFERENCED_BY_TESS_CONTROL_SHADER
	BOOST_CHECK(x != ev.referenced_by_tess_control_shader);
# endif
# ifdef GL_REFERENCED_BY_TESS_EVALUATION_SHADER
	BOOST_CHECK(x != ev.referenced_by_tess_evaluation_shader);
# endif
# ifdef GL_REFERENCED_BY_VERTEX_SHADER
	BOOST_CHECK(x != ev.referenced_by_vertex_shader);
# endif
# ifdef GL_TOP_LEVEL_ARRAY_SIZE
	BOOST_CHECK(x != ev.top_level_array_size);
# endif
# ifdef GL_TOP_LEVEL_ARRAY_STRIDE
	BOOST_CHECK(x != ev.top_level_array_stride);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_INDEX
	BOOST_CHECK(x != ev.transform_feedback_buffer_index);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE
	BOOST_CHECK(x != ev.transform_feedback_buffer_stride);
# endif
#endif

#ifdef GL_ARRAY_SIZE
	x = ev.array_size;
# ifdef GL_ACTIVE_VARIABLES
	BOOST_CHECK(x != ev.active_variables);
# endif
	BOOST_CHECK(x == ev.array_size);
# ifdef GL_ARRAY_STRIDE
	BOOST_CHECK(x != ev.array_stride);
# endif
# ifdef GL_ATOMIC_COUNTER_BUFFER_INDEX
	BOOST_CHECK(x != ev.atomic_counter_buffer_index);
# endif
# ifdef GL_BLOCK_INDEX
	BOOST_CHECK(x != ev.block_index);
# endif
# ifdef GL_BUFFER_BINDING
	BOOST_CHECK(x != ev.buffer_binding);
# endif
# ifdef GL_BUFFER_DATA_SIZE
	BOOST_CHECK(x != ev.buffer_data_size);
# endif
# ifdef GL_COMPATIBLE_SUBROUTINES
	BOOST_CHECK(x != ev.compatible_subroutines);
# endif
# ifdef GL_IS_PER_PATCH
	BOOST_CHECK(x != ev.is_per_patch);
# endif
# ifdef GL_IS_ROW_MAJOR
	BOOST_CHECK(x != ev.is_row_major);
# endif
# ifdef GL_LOCATION
	BOOST_CHECK(x != ev.location);
# endif
# ifdef GL_LOCATION_COMPONENT
	BOOST_CHECK(x != ev.location_component);
# endif
# ifdef GL_LOCATION_INDEX
	BOOST_CHECK(x != ev.location_index);
# endif
# ifdef GL_MATRIX_STRIDE
	BOOST_CHECK(x != ev.matrix_stride);
# endif
# ifdef GL_NUM_ACTIVE_VARIABLES
	BOOST_CHECK(x != ev.num_active_variables);
# endif
# ifdef GL_NUM_COMPATIBLE_SUBROUTINES
	BOOST_CHECK(x != ev.num_compatible_subroutines);
# endif
# ifdef GL_OFFSET
	BOOST_CHECK(x != ev.offset);
# endif
# ifdef GL_REFERENCED_BY_COMPUTE_SHADER
	BOOST_CHECK(x != ev.referenced_by_compute_shader);
# endif
# ifdef GL_REFERENCED_BY_FRAGMENT_SHADER
	BOOST_CHECK(x != ev.referenced_by_fragment_shader);
# endif
# ifdef GL_REFERENCED_BY_GEOMETRY_SHADER
	BOOST_CHECK(x != ev.referenced_by_geometry_shader);
# endif
# ifdef GL_REFERENCED_BY_TESS_CONTROL_SHADER
	BOOST_CHECK(x != ev.referenced_by_tess_control_shader);
# endif
# ifdef GL_REFERENCED_BY_TESS_EVALUATION_SHADER
	BOOST_CHECK(x != ev.referenced_by_tess_evaluation_shader);
# endif
# ifdef GL_REFERENCED_BY_VERTEX_SHADER
	BOOST_CHECK(x != ev.referenced_by_vertex_shader);
# endif
# ifdef GL_TOP_LEVEL_ARRAY_SIZE
	BOOST_CHECK(x != ev.top_level_array_size);
# endif
# ifdef GL_TOP_LEVEL_ARRAY_STRIDE
	BOOST_CHECK(x != ev.top_level_array_stride);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_INDEX
	BOOST_CHECK(x != ev.transform_feedback_buffer_index);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE
	BOOST_CHECK(x != ev.transform_feedback_buffer_stride);
# endif
#endif

#ifdef GL_ARRAY_STRIDE
	x = ev.array_stride;
# ifdef GL_ACTIVE_VARIABLES
	BOOST_CHECK(x != ev.active_variables);
# endif
# ifdef GL_ARRAY_SIZE
	BOOST_CHECK(x != ev.array_size);
# endif
	BOOST_CHECK(x == ev.array_stride);
# ifdef GL_ATOMIC_COUNTER_BUFFER_INDEX
	BOOST_CHECK(x != ev.atomic_counter_buffer_index);
# endif
# ifdef GL_BLOCK_INDEX
	BOOST_CHECK(x != ev.block_index);
# endif
# ifdef GL_BUFFER_BINDING
	BOOST_CHECK(x != ev.buffer_binding);
# endif
# ifdef GL_BUFFER_DATA_SIZE
	BOOST_CHECK(x != ev.buffer_data_size);
# endif
# ifdef GL_COMPATIBLE_SUBROUTINES
	BOOST_CHECK(x != ev.compatible_subroutines);
# endif
# ifdef GL_IS_PER_PATCH
	BOOST_CHECK(x != ev.is_per_patch);
# endif
# ifdef GL_IS_ROW_MAJOR
	BOOST_CHECK(x != ev.is_row_major);
# endif
# ifdef GL_LOCATION
	BOOST_CHECK(x != ev.location);
# endif
# ifdef GL_LOCATION_COMPONENT
	BOOST_CHECK(x != ev.location_component);
# endif
# ifdef GL_LOCATION_INDEX
	BOOST_CHECK(x != ev.location_index);
# endif
# ifdef GL_MATRIX_STRIDE
	BOOST_CHECK(x != ev.matrix_stride);
# endif
# ifdef GL_NUM_ACTIVE_VARIABLES
	BOOST_CHECK(x != ev.num_active_variables);
# endif
# ifdef GL_NUM_COMPATIBLE_SUBROUTINES
	BOOST_CHECK(x != ev.num_compatible_subroutines);
# endif
# ifdef GL_OFFSET
	BOOST_CHECK(x != ev.offset);
# endif
# ifdef GL_REFERENCED_BY_COMPUTE_SHADER
	BOOST_CHECK(x != ev.referenced_by_compute_shader);
# endif
# ifdef GL_REFERENCED_BY_FRAGMENT_SHADER
	BOOST_CHECK(x != ev.referenced_by_fragment_shader);
# endif
# ifdef GL_REFERENCED_BY_GEOMETRY_SHADER
	BOOST_CHECK(x != ev.referenced_by_geometry_shader);
# endif
# ifdef GL_REFERENCED_BY_TESS_CONTROL_SHADER
	BOOST_CHECK(x != ev.referenced_by_tess_control_shader);
# endif
# ifdef GL_REFERENCED_BY_TESS_EVALUATION_SHADER
	BOOST_CHECK(x != ev.referenced_by_tess_evaluation_shader);
# endif
# ifdef GL_REFERENCED_BY_VERTEX_SHADER
	BOOST_CHECK(x != ev.referenced_by_vertex_shader);
# endif
# ifdef GL_TOP_LEVEL_ARRAY_SIZE
	BOOST_CHECK(x != ev.top_level_array_size);
# endif
# ifdef GL_TOP_LEVEL_ARRAY_STRIDE
	BOOST_CHECK(x != ev.top_level_array_stride);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_INDEX
	BOOST_CHECK(x != ev.transform_feedback_buffer_index);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE
	BOOST_CHECK(x != ev.transform_feedback_buffer_stride);
# endif
#endif

#ifdef GL_ATOMIC_COUNTER_BUFFER_INDEX
	x = ev.atomic_counter_buffer_index;
# ifdef GL_ACTIVE_VARIABLES
	BOOST_CHECK(x != ev.active_variables);
# endif
# ifdef GL_ARRAY_SIZE
	BOOST_CHECK(x != ev.array_size);
# endif
# ifdef GL_ARRAY_STRIDE
	BOOST_CHECK(x != ev.array_stride);
# endif
	BOOST_CHECK(x == ev.atomic_counter_buffer_index);
# ifdef GL_BLOCK_INDEX
	BOOST_CHECK(x != ev.block_index);
# endif
# ifdef GL_BUFFER_BINDING
	BOOST_CHECK(x != ev.buffer_binding);
# endif
# ifdef GL_BUFFER_DATA_SIZE
	BOOST_CHECK(x != ev.buffer_data_size);
# endif
# ifdef GL_COMPATIBLE_SUBROUTINES
	BOOST_CHECK(x != ev.compatible_subroutines);
# endif
# ifdef GL_IS_PER_PATCH
	BOOST_CHECK(x != ev.is_per_patch);
# endif
# ifdef GL_IS_ROW_MAJOR
	BOOST_CHECK(x != ev.is_row_major);
# endif
# ifdef GL_LOCATION
	BOOST_CHECK(x != ev.location);
# endif
# ifdef GL_LOCATION_COMPONENT
	BOOST_CHECK(x != ev.location_component);
# endif
# ifdef GL_LOCATION_INDEX
	BOOST_CHECK(x != ev.location_index);
# endif
# ifdef GL_MATRIX_STRIDE
	BOOST_CHECK(x != ev.matrix_stride);
# endif
# ifdef GL_NUM_ACTIVE_VARIABLES
	BOOST_CHECK(x != ev.num_active_variables);
# endif
# ifdef GL_NUM_COMPATIBLE_SUBROUTINES
	BOOST_CHECK(x != ev.num_compatible_subroutines);
# endif
# ifdef GL_OFFSET
	BOOST_CHECK(x != ev.offset);
# endif
# ifdef GL_REFERENCED_BY_COMPUTE_SHADER
	BOOST_CHECK(x != ev.referenced_by_compute_shader);
# endif
# ifdef GL_REFERENCED_BY_FRAGMENT_SHADER
	BOOST_CHECK(x != ev.referenced_by_fragment_shader);
# endif
# ifdef GL_REFERENCED_BY_GEOMETRY_SHADER
	BOOST_CHECK(x != ev.referenced_by_geometry_shader);
# endif
# ifdef GL_REFERENCED_BY_TESS_CONTROL_SHADER
	BOOST_CHECK(x != ev.referenced_by_tess_control_shader);
# endif
# ifdef GL_REFERENCED_BY_TESS_EVALUATION_SHADER
	BOOST_CHECK(x != ev.referenced_by_tess_evaluation_shader);
# endif
# ifdef GL_REFERENCED_BY_VERTEX_SHADER
	BOOST_CHECK(x != ev.referenced_by_vertex_shader);
# endif
# ifdef GL_TOP_LEVEL_ARRAY_SIZE
	BOOST_CHECK(x != ev.top_level_array_size);
# endif
# ifdef GL_TOP_LEVEL_ARRAY_STRIDE
	BOOST_CHECK(x != ev.top_level_array_stride);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_INDEX
	BOOST_CHECK(x != ev.transform_feedback_buffer_index);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE
	BOOST_CHECK(x != ev.transform_feedback_buffer_stride);
# endif
#endif

#ifdef GL_BLOCK_INDEX
	x = ev.block_index;
# ifdef GL_ACTIVE_VARIABLES
	BOOST_CHECK(x != ev.active_variables);
# endif
# ifdef GL_ARRAY_SIZE
	BOOST_CHECK(x != ev.array_size);
# endif
# ifdef GL_ARRAY_STRIDE
	BOOST_CHECK(x != ev.array_stride);
# endif
# ifdef GL_ATOMIC_COUNTER_BUFFER_INDEX
	BOOST_CHECK(x != ev.atomic_counter_buffer_index);
# endif
	BOOST_CHECK(x == ev.block_index);
# ifdef GL_BUFFER_BINDING
	BOOST_CHECK(x != ev.buffer_binding);
# endif
# ifdef GL_BUFFER_DATA_SIZE
	BOOST_CHECK(x != ev.buffer_data_size);
# endif
# ifdef GL_COMPATIBLE_SUBROUTINES
	BOOST_CHECK(x != ev.compatible_subroutines);
# endif
# ifdef GL_IS_PER_PATCH
	BOOST_CHECK(x != ev.is_per_patch);
# endif
# ifdef GL_IS_ROW_MAJOR
	BOOST_CHECK(x != ev.is_row_major);
# endif
# ifdef GL_LOCATION
	BOOST_CHECK(x != ev.location);
# endif
# ifdef GL_LOCATION_COMPONENT
	BOOST_CHECK(x != ev.location_component);
# endif
# ifdef GL_LOCATION_INDEX
	BOOST_CHECK(x != ev.location_index);
# endif
# ifdef GL_MATRIX_STRIDE
	BOOST_CHECK(x != ev.matrix_stride);
# endif
# ifdef GL_NUM_ACTIVE_VARIABLES
	BOOST_CHECK(x != ev.num_active_variables);
# endif
# ifdef GL_NUM_COMPATIBLE_SUBROUTINES
	BOOST_CHECK(x != ev.num_compatible_subroutines);
# endif
# ifdef GL_OFFSET
	BOOST_CHECK(x != ev.offset);
# endif
# ifdef GL_REFERENCED_BY_COMPUTE_SHADER
	BOOST_CHECK(x != ev.referenced_by_compute_shader);
# endif
# ifdef GL_REFERENCED_BY_FRAGMENT_SHADER
	BOOST_CHECK(x != ev.referenced_by_fragment_shader);
# endif
# ifdef GL_REFERENCED_BY_GEOMETRY_SHADER
	BOOST_CHECK(x != ev.referenced_by_geometry_shader);
# endif
# ifdef GL_REFERENCED_BY_TESS_CONTROL_SHADER
	BOOST_CHECK(x != ev.referenced_by_tess_control_shader);
# endif
# ifdef GL_REFERENCED_BY_TESS_EVALUATION_SHADER
	BOOST_CHECK(x != ev.referenced_by_tess_evaluation_shader);
# endif
# ifdef GL_REFERENCED_BY_VERTEX_SHADER
	BOOST_CHECK(x != ev.referenced_by_vertex_shader);
# endif
# ifdef GL_TOP_LEVEL_ARRAY_SIZE
	BOOST_CHECK(x != ev.top_level_array_size);
# endif
# ifdef GL_TOP_LEVEL_ARRAY_STRIDE
	BOOST_CHECK(x != ev.top_level_array_stride);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_INDEX
	BOOST_CHECK(x != ev.transform_feedback_buffer_index);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE
	BOOST_CHECK(x != ev.transform_feedback_buffer_stride);
# endif
#endif

#ifdef GL_BUFFER_BINDING
	x = ev.buffer_binding;
# ifdef GL_ACTIVE_VARIABLES
	BOOST_CHECK(x != ev.active_variables);
# endif
# ifdef GL_ARRAY_SIZE
	BOOST_CHECK(x != ev.array_size);
# endif
# ifdef GL_ARRAY_STRIDE
	BOOST_CHECK(x != ev.array_stride);
# endif
# ifdef GL_ATOMIC_COUNTER_BUFFER_INDEX
	BOOST_CHECK(x != ev.atomic_counter_buffer_index);
# endif
# ifdef GL_BLOCK_INDEX
	BOOST_CHECK(x != ev.block_index);
# endif
	BOOST_CHECK(x == ev.buffer_binding);
# ifdef GL_BUFFER_DATA_SIZE
	BOOST_CHECK(x != ev.buffer_data_size);
# endif
# ifdef GL_COMPATIBLE_SUBROUTINES
	BOOST_CHECK(x != ev.compatible_subroutines);
# endif
# ifdef GL_IS_PER_PATCH
	BOOST_CHECK(x != ev.is_per_patch);
# endif
# ifdef GL_IS_ROW_MAJOR
	BOOST_CHECK(x != ev.is_row_major);
# endif
# ifdef GL_LOCATION
	BOOST_CHECK(x != ev.location);
# endif
# ifdef GL_LOCATION_COMPONENT
	BOOST_CHECK(x != ev.location_component);
# endif
# ifdef GL_LOCATION_INDEX
	BOOST_CHECK(x != ev.location_index);
# endif
# ifdef GL_MATRIX_STRIDE
	BOOST_CHECK(x != ev.matrix_stride);
# endif
# ifdef GL_NUM_ACTIVE_VARIABLES
	BOOST_CHECK(x != ev.num_active_variables);
# endif
# ifdef GL_NUM_COMPATIBLE_SUBROUTINES
	BOOST_CHECK(x != ev.num_compatible_subroutines);
# endif
# ifdef GL_OFFSET
	BOOST_CHECK(x != ev.offset);
# endif
# ifdef GL_REFERENCED_BY_COMPUTE_SHADER
	BOOST_CHECK(x != ev.referenced_by_compute_shader);
# endif
# ifdef GL_REFERENCED_BY_FRAGMENT_SHADER
	BOOST_CHECK(x != ev.referenced_by_fragment_shader);
# endif
# ifdef GL_REFERENCED_BY_GEOMETRY_SHADER
	BOOST_CHECK(x != ev.referenced_by_geometry_shader);
# endif
# ifdef GL_REFERENCED_BY_TESS_CONTROL_SHADER
	BOOST_CHECK(x != ev.referenced_by_tess_control_shader);
# endif
# ifdef GL_REFERENCED_BY_TESS_EVALUATION_SHADER
	BOOST_CHECK(x != ev.referenced_by_tess_evaluation_shader);
# endif
# ifdef GL_REFERENCED_BY_VERTEX_SHADER
	BOOST_CHECK(x != ev.referenced_by_vertex_shader);
# endif
# ifdef GL_TOP_LEVEL_ARRAY_SIZE
	BOOST_CHECK(x != ev.top_level_array_size);
# endif
# ifdef GL_TOP_LEVEL_ARRAY_STRIDE
	BOOST_CHECK(x != ev.top_level_array_stride);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_INDEX
	BOOST_CHECK(x != ev.transform_feedback_buffer_index);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE
	BOOST_CHECK(x != ev.transform_feedback_buffer_stride);
# endif
#endif

#ifdef GL_BUFFER_DATA_SIZE
	x = ev.buffer_data_size;
# ifdef GL_ACTIVE_VARIABLES
	BOOST_CHECK(x != ev.active_variables);
# endif
# ifdef GL_ARRAY_SIZE
	BOOST_CHECK(x != ev.array_size);
# endif
# ifdef GL_ARRAY_STRIDE
	BOOST_CHECK(x != ev.array_stride);
# endif
# ifdef GL_ATOMIC_COUNTER_BUFFER_INDEX
	BOOST_CHECK(x != ev.atomic_counter_buffer_index);
# endif
# ifdef GL_BLOCK_INDEX
	BOOST_CHECK(x != ev.block_index);
# endif
# ifdef GL_BUFFER_BINDING
	BOOST_CHECK(x != ev.buffer_binding);
# endif
	BOOST_CHECK(x == ev.buffer_data_size);
# ifdef GL_COMPATIBLE_SUBROUTINES
	BOOST_CHECK(x != ev.compatible_subroutines);
# endif
# ifdef GL_IS_PER_PATCH
	BOOST_CHECK(x != ev.is_per_patch);
# endif
# ifdef GL_IS_ROW_MAJOR
	BOOST_CHECK(x != ev.is_row_major);
# endif
# ifdef GL_LOCATION
	BOOST_CHECK(x != ev.location);
# endif
# ifdef GL_LOCATION_COMPONENT
	BOOST_CHECK(x != ev.location_component);
# endif
# ifdef GL_LOCATION_INDEX
	BOOST_CHECK(x != ev.location_index);
# endif
# ifdef GL_MATRIX_STRIDE
	BOOST_CHECK(x != ev.matrix_stride);
# endif
# ifdef GL_NUM_ACTIVE_VARIABLES
	BOOST_CHECK(x != ev.num_active_variables);
# endif
# ifdef GL_NUM_COMPATIBLE_SUBROUTINES
	BOOST_CHECK(x != ev.num_compatible_subroutines);
# endif
# ifdef GL_OFFSET
	BOOST_CHECK(x != ev.offset);
# endif
# ifdef GL_REFERENCED_BY_COMPUTE_SHADER
	BOOST_CHECK(x != ev.referenced_by_compute_shader);
# endif
# ifdef GL_REFERENCED_BY_FRAGMENT_SHADER
	BOOST_CHECK(x != ev.referenced_by_fragment_shader);
# endif
# ifdef GL_REFERENCED_BY_GEOMETRY_SHADER
	BOOST_CHECK(x != ev.referenced_by_geometry_shader);
# endif
# ifdef GL_REFERENCED_BY_TESS_CONTROL_SHADER
	BOOST_CHECK(x != ev.referenced_by_tess_control_shader);
# endif
# ifdef GL_REFERENCED_BY_TESS_EVALUATION_SHADER
	BOOST_CHECK(x != ev.referenced_by_tess_evaluation_shader);
# endif
# ifdef GL_REFERENCED_BY_VERTEX_SHADER
	BOOST_CHECK(x != ev.referenced_by_vertex_shader);
# endif
# ifdef GL_TOP_LEVEL_ARRAY_SIZE
	BOOST_CHECK(x != ev.top_level_array_size);
# endif
# ifdef GL_TOP_LEVEL_ARRAY_STRIDE
	BOOST_CHECK(x != ev.top_level_array_stride);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_INDEX
	BOOST_CHECK(x != ev.transform_feedback_buffer_index);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE
	BOOST_CHECK(x != ev.transform_feedback_buffer_stride);
# endif
#endif

#ifdef GL_COMPATIBLE_SUBROUTINES
	x = ev.compatible_subroutines;
# ifdef GL_ACTIVE_VARIABLES
	BOOST_CHECK(x != ev.active_variables);
# endif
# ifdef GL_ARRAY_SIZE
	BOOST_CHECK(x != ev.array_size);
# endif
# ifdef GL_ARRAY_STRIDE
	BOOST_CHECK(x != ev.array_stride);
# endif
# ifdef GL_ATOMIC_COUNTER_BUFFER_INDEX
	BOOST_CHECK(x != ev.atomic_counter_buffer_index);
# endif
# ifdef GL_BLOCK_INDEX
	BOOST_CHECK(x != ev.block_index);
# endif
# ifdef GL_BUFFER_BINDING
	BOOST_CHECK(x != ev.buffer_binding);
# endif
# ifdef GL_BUFFER_DATA_SIZE
	BOOST_CHECK(x != ev.buffer_data_size);
# endif
	BOOST_CHECK(x == ev.compatible_subroutines);
# ifdef GL_IS_PER_PATCH
	BOOST_CHECK(x != ev.is_per_patch);
# endif
# ifdef GL_IS_ROW_MAJOR
	BOOST_CHECK(x != ev.is_row_major);
# endif
# ifdef GL_LOCATION
	BOOST_CHECK(x != ev.location);
# endif
# ifdef GL_LOCATION_COMPONENT
	BOOST_CHECK(x != ev.location_component);
# endif
# ifdef GL_LOCATION_INDEX
	BOOST_CHECK(x != ev.location_index);
# endif
# ifdef GL_MATRIX_STRIDE
	BOOST_CHECK(x != ev.matrix_stride);
# endif
# ifdef GL_NUM_ACTIVE_VARIABLES
	BOOST_CHECK(x != ev.num_active_variables);
# endif
# ifdef GL_NUM_COMPATIBLE_SUBROUTINES
	BOOST_CHECK(x != ev.num_compatible_subroutines);
# endif
# ifdef GL_OFFSET
	BOOST_CHECK(x != ev.offset);
# endif
# ifdef GL_REFERENCED_BY_COMPUTE_SHADER
	BOOST_CHECK(x != ev.referenced_by_compute_shader);
# endif
# ifdef GL_REFERENCED_BY_FRAGMENT_SHADER
	BOOST_CHECK(x != ev.referenced_by_fragment_shader);
# endif
# ifdef GL_REFERENCED_BY_GEOMETRY_SHADER
	BOOST_CHECK(x != ev.referenced_by_geometry_shader);
# endif
# ifdef GL_REFERENCED_BY_TESS_CONTROL_SHADER
	BOOST_CHECK(x != ev.referenced_by_tess_control_shader);
# endif
# ifdef GL_REFERENCED_BY_TESS_EVALUATION_SHADER
	BOOST_CHECK(x != ev.referenced_by_tess_evaluation_shader);
# endif
# ifdef GL_REFERENCED_BY_VERTEX_SHADER
	BOOST_CHECK(x != ev.referenced_by_vertex_shader);
# endif
# ifdef GL_TOP_LEVEL_ARRAY_SIZE
	BOOST_CHECK(x != ev.top_level_array_size);
# endif
# ifdef GL_TOP_LEVEL_ARRAY_STRIDE
	BOOST_CHECK(x != ev.top_level_array_stride);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_INDEX
	BOOST_CHECK(x != ev.transform_feedback_buffer_index);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE
	BOOST_CHECK(x != ev.transform_feedback_buffer_stride);
# endif
#endif

#ifdef GL_IS_PER_PATCH
	x = ev.is_per_patch;
# ifdef GL_ACTIVE_VARIABLES
	BOOST_CHECK(x != ev.active_variables);
# endif
# ifdef GL_ARRAY_SIZE
	BOOST_CHECK(x != ev.array_size);
# endif
# ifdef GL_ARRAY_STRIDE
	BOOST_CHECK(x != ev.array_stride);
# endif
# ifdef GL_ATOMIC_COUNTER_BUFFER_INDEX
	BOOST_CHECK(x != ev.atomic_counter_buffer_index);
# endif
# ifdef GL_BLOCK_INDEX
	BOOST_CHECK(x != ev.block_index);
# endif
# ifdef GL_BUFFER_BINDING
	BOOST_CHECK(x != ev.buffer_binding);
# endif
# ifdef GL_BUFFER_DATA_SIZE
	BOOST_CHECK(x != ev.buffer_data_size);
# endif
# ifdef GL_COMPATIBLE_SUBROUTINES
	BOOST_CHECK(x != ev.compatible_subroutines);
# endif
	BOOST_CHECK(x == ev.is_per_patch);
# ifdef GL_IS_ROW_MAJOR
	BOOST_CHECK(x != ev.is_row_major);
# endif
# ifdef GL_LOCATION
	BOOST_CHECK(x != ev.location);
# endif
# ifdef GL_LOCATION_COMPONENT
	BOOST_CHECK(x != ev.location_component);
# endif
# ifdef GL_LOCATION_INDEX
	BOOST_CHECK(x != ev.location_index);
# endif
# ifdef GL_MATRIX_STRIDE
	BOOST_CHECK(x != ev.matrix_stride);
# endif
# ifdef GL_NUM_ACTIVE_VARIABLES
	BOOST_CHECK(x != ev.num_active_variables);
# endif
# ifdef GL_NUM_COMPATIBLE_SUBROUTINES
	BOOST_CHECK(x != ev.num_compatible_subroutines);
# endif
# ifdef GL_OFFSET
	BOOST_CHECK(x != ev.offset);
# endif
# ifdef GL_REFERENCED_BY_COMPUTE_SHADER
	BOOST_CHECK(x != ev.referenced_by_compute_shader);
# endif
# ifdef GL_REFERENCED_BY_FRAGMENT_SHADER
	BOOST_CHECK(x != ev.referenced_by_fragment_shader);
# endif
# ifdef GL_REFERENCED_BY_GEOMETRY_SHADER
	BOOST_CHECK(x != ev.referenced_by_geometry_shader);
# endif
# ifdef GL_REFERENCED_BY_TESS_CONTROL_SHADER
	BOOST_CHECK(x != ev.referenced_by_tess_control_shader);
# endif
# ifdef GL_REFERENCED_BY_TESS_EVALUATION_SHADER
	BOOST_CHECK(x != ev.referenced_by_tess_evaluation_shader);
# endif
# ifdef GL_REFERENCED_BY_VERTEX_SHADER
	BOOST_CHECK(x != ev.referenced_by_vertex_shader);
# endif
# ifdef GL_TOP_LEVEL_ARRAY_SIZE
	BOOST_CHECK(x != ev.top_level_array_size);
# endif
# ifdef GL_TOP_LEVEL_ARRAY_STRIDE
	BOOST_CHECK(x != ev.top_level_array_stride);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_INDEX
	BOOST_CHECK(x != ev.transform_feedback_buffer_index);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE
	BOOST_CHECK(x != ev.transform_feedback_buffer_stride);
# endif
#endif

#ifdef GL_IS_ROW_MAJOR
	x = ev.is_row_major;
# ifdef GL_ACTIVE_VARIABLES
	BOOST_CHECK(x != ev.active_variables);
# endif
# ifdef GL_ARRAY_SIZE
	BOOST_CHECK(x != ev.array_size);
# endif
# ifdef GL_ARRAY_STRIDE
	BOOST_CHECK(x != ev.array_stride);
# endif
# ifdef GL_ATOMIC_COUNTER_BUFFER_INDEX
	BOOST_CHECK(x != ev.atomic_counter_buffer_index);
# endif
# ifdef GL_BLOCK_INDEX
	BOOST_CHECK(x != ev.block_index);
# endif
# ifdef GL_BUFFER_BINDING
	BOOST_CHECK(x != ev.buffer_binding);
# endif
# ifdef GL_BUFFER_DATA_SIZE
	BOOST_CHECK(x != ev.buffer_data_size);
# endif
# ifdef GL_COMPATIBLE_SUBROUTINES
	BOOST_CHECK(x != ev.compatible_subroutines);
# endif
# ifdef GL_IS_PER_PATCH
	BOOST_CHECK(x != ev.is_per_patch);
# endif
	BOOST_CHECK(x == ev.is_row_major);
# ifdef GL_LOCATION
	BOOST_CHECK(x != ev.location);
# endif
# ifdef GL_LOCATION_COMPONENT
	BOOST_CHECK(x != ev.location_component);
# endif
# ifdef GL_LOCATION_INDEX
	BOOST_CHECK(x != ev.location_index);
# endif
# ifdef GL_MATRIX_STRIDE
	BOOST_CHECK(x != ev.matrix_stride);
# endif
# ifdef GL_NUM_ACTIVE_VARIABLES
	BOOST_CHECK(x != ev.num_active_variables);
# endif
# ifdef GL_NUM_COMPATIBLE_SUBROUTINES
	BOOST_CHECK(x != ev.num_compatible_subroutines);
# endif
# ifdef GL_OFFSET
	BOOST_CHECK(x != ev.offset);
# endif
# ifdef GL_REFERENCED_BY_COMPUTE_SHADER
	BOOST_CHECK(x != ev.referenced_by_compute_shader);
# endif
# ifdef GL_REFERENCED_BY_FRAGMENT_SHADER
	BOOST_CHECK(x != ev.referenced_by_fragment_shader);
# endif
# ifdef GL_REFERENCED_BY_GEOMETRY_SHADER
	BOOST_CHECK(x != ev.referenced_by_geometry_shader);
# endif
# ifdef GL_REFERENCED_BY_TESS_CONTROL_SHADER
	BOOST_CHECK(x != ev.referenced_by_tess_control_shader);
# endif
# ifdef GL_REFERENCED_BY_TESS_EVALUATION_SHADER
	BOOST_CHECK(x != ev.referenced_by_tess_evaluation_shader);
# endif
# ifdef GL_REFERENCED_BY_VERTEX_SHADER
	BOOST_CHECK(x != ev.referenced_by_vertex_shader);
# endif
# ifdef GL_TOP_LEVEL_ARRAY_SIZE
	BOOST_CHECK(x != ev.top_level_array_size);
# endif
# ifdef GL_TOP_LEVEL_ARRAY_STRIDE
	BOOST_CHECK(x != ev.top_level_array_stride);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_INDEX
	BOOST_CHECK(x != ev.transform_feedback_buffer_index);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE
	BOOST_CHECK(x != ev.transform_feedback_buffer_stride);
# endif
#endif

#ifdef GL_LOCATION
	x = ev.location;
# ifdef GL_ACTIVE_VARIABLES
	BOOST_CHECK(x != ev.active_variables);
# endif
# ifdef GL_ARRAY_SIZE
	BOOST_CHECK(x != ev.array_size);
# endif
# ifdef GL_ARRAY_STRIDE
	BOOST_CHECK(x != ev.array_stride);
# endif
# ifdef GL_ATOMIC_COUNTER_BUFFER_INDEX
	BOOST_CHECK(x != ev.atomic_counter_buffer_index);
# endif
# ifdef GL_BLOCK_INDEX
	BOOST_CHECK(x != ev.block_index);
# endif
# ifdef GL_BUFFER_BINDING
	BOOST_CHECK(x != ev.buffer_binding);
# endif
# ifdef GL_BUFFER_DATA_SIZE
	BOOST_CHECK(x != ev.buffer_data_size);
# endif
# ifdef GL_COMPATIBLE_SUBROUTINES
	BOOST_CHECK(x != ev.compatible_subroutines);
# endif
# ifdef GL_IS_PER_PATCH
	BOOST_CHECK(x != ev.is_per_patch);
# endif
# ifdef GL_IS_ROW_MAJOR
	BOOST_CHECK(x != ev.is_row_major);
# endif
	BOOST_CHECK(x == ev.location);
# ifdef GL_LOCATION_COMPONENT
	BOOST_CHECK(x != ev.location_component);
# endif
# ifdef GL_LOCATION_INDEX
	BOOST_CHECK(x != ev.location_index);
# endif
# ifdef GL_MATRIX_STRIDE
	BOOST_CHECK(x != ev.matrix_stride);
# endif
# ifdef GL_NUM_ACTIVE_VARIABLES
	BOOST_CHECK(x != ev.num_active_variables);
# endif
# ifdef GL_NUM_COMPATIBLE_SUBROUTINES
	BOOST_CHECK(x != ev.num_compatible_subroutines);
# endif
# ifdef GL_OFFSET
	BOOST_CHECK(x != ev.offset);
# endif
# ifdef GL_REFERENCED_BY_COMPUTE_SHADER
	BOOST_CHECK(x != ev.referenced_by_compute_shader);
# endif
# ifdef GL_REFERENCED_BY_FRAGMENT_SHADER
	BOOST_CHECK(x != ev.referenced_by_fragment_shader);
# endif
# ifdef GL_REFERENCED_BY_GEOMETRY_SHADER
	BOOST_CHECK(x != ev.referenced_by_geometry_shader);
# endif
# ifdef GL_REFERENCED_BY_TESS_CONTROL_SHADER
	BOOST_CHECK(x != ev.referenced_by_tess_control_shader);
# endif
# ifdef GL_REFERENCED_BY_TESS_EVALUATION_SHADER
	BOOST_CHECK(x != ev.referenced_by_tess_evaluation_shader);
# endif
# ifdef GL_REFERENCED_BY_VERTEX_SHADER
	BOOST_CHECK(x != ev.referenced_by_vertex_shader);
# endif
# ifdef GL_TOP_LEVEL_ARRAY_SIZE
	BOOST_CHECK(x != ev.top_level_array_size);
# endif
# ifdef GL_TOP_LEVEL_ARRAY_STRIDE
	BOOST_CHECK(x != ev.top_level_array_stride);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_INDEX
	BOOST_CHECK(x != ev.transform_feedback_buffer_index);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE
	BOOST_CHECK(x != ev.transform_feedback_buffer_stride);
# endif
#endif

#ifdef GL_LOCATION_COMPONENT
	x = ev.location_component;
# ifdef GL_ACTIVE_VARIABLES
	BOOST_CHECK(x != ev.active_variables);
# endif
# ifdef GL_ARRAY_SIZE
	BOOST_CHECK(x != ev.array_size);
# endif
# ifdef GL_ARRAY_STRIDE
	BOOST_CHECK(x != ev.array_stride);
# endif
# ifdef GL_ATOMIC_COUNTER_BUFFER_INDEX
	BOOST_CHECK(x != ev.atomic_counter_buffer_index);
# endif
# ifdef GL_BLOCK_INDEX
	BOOST_CHECK(x != ev.block_index);
# endif
# ifdef GL_BUFFER_BINDING
	BOOST_CHECK(x != ev.buffer_binding);
# endif
# ifdef GL_BUFFER_DATA_SIZE
	BOOST_CHECK(x != ev.buffer_data_size);
# endif
# ifdef GL_COMPATIBLE_SUBROUTINES
	BOOST_CHECK(x != ev.compatible_subroutines);
# endif
# ifdef GL_IS_PER_PATCH
	BOOST_CHECK(x != ev.is_per_patch);
# endif
# ifdef GL_IS_ROW_MAJOR
	BOOST_CHECK(x != ev.is_row_major);
# endif
# ifdef GL_LOCATION
	BOOST_CHECK(x != ev.location);
# endif
	BOOST_CHECK(x == ev.location_component);
# ifdef GL_LOCATION_INDEX
	BOOST_CHECK(x != ev.location_index);
# endif
# ifdef GL_MATRIX_STRIDE
	BOOST_CHECK(x != ev.matrix_stride);
# endif
# ifdef GL_NUM_ACTIVE_VARIABLES
	BOOST_CHECK(x != ev.num_active_variables);
# endif
# ifdef GL_NUM_COMPATIBLE_SUBROUTINES
	BOOST_CHECK(x != ev.num_compatible_subroutines);
# endif
# ifdef GL_OFFSET
	BOOST_CHECK(x != ev.offset);
# endif
# ifdef GL_REFERENCED_BY_COMPUTE_SHADER
	BOOST_CHECK(x != ev.referenced_by_compute_shader);
# endif
# ifdef GL_REFERENCED_BY_FRAGMENT_SHADER
	BOOST_CHECK(x != ev.referenced_by_fragment_shader);
# endif
# ifdef GL_REFERENCED_BY_GEOMETRY_SHADER
	BOOST_CHECK(x != ev.referenced_by_geometry_shader);
# endif
# ifdef GL_REFERENCED_BY_TESS_CONTROL_SHADER
	BOOST_CHECK(x != ev.referenced_by_tess_control_shader);
# endif
# ifdef GL_REFERENCED_BY_TESS_EVALUATION_SHADER
	BOOST_CHECK(x != ev.referenced_by_tess_evaluation_shader);
# endif
# ifdef GL_REFERENCED_BY_VERTEX_SHADER
	BOOST_CHECK(x != ev.referenced_by_vertex_shader);
# endif
# ifdef GL_TOP_LEVEL_ARRAY_SIZE
	BOOST_CHECK(x != ev.top_level_array_size);
# endif
# ifdef GL_TOP_LEVEL_ARRAY_STRIDE
	BOOST_CHECK(x != ev.top_level_array_stride);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_INDEX
	BOOST_CHECK(x != ev.transform_feedback_buffer_index);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE
	BOOST_CHECK(x != ev.transform_feedback_buffer_stride);
# endif
#endif

#ifdef GL_LOCATION_INDEX
	x = ev.location_index;
# ifdef GL_ACTIVE_VARIABLES
	BOOST_CHECK(x != ev.active_variables);
# endif
# ifdef GL_ARRAY_SIZE
	BOOST_CHECK(x != ev.array_size);
# endif
# ifdef GL_ARRAY_STRIDE
	BOOST_CHECK(x != ev.array_stride);
# endif
# ifdef GL_ATOMIC_COUNTER_BUFFER_INDEX
	BOOST_CHECK(x != ev.atomic_counter_buffer_index);
# endif
# ifdef GL_BLOCK_INDEX
	BOOST_CHECK(x != ev.block_index);
# endif
# ifdef GL_BUFFER_BINDING
	BOOST_CHECK(x != ev.buffer_binding);
# endif
# ifdef GL_BUFFER_DATA_SIZE
	BOOST_CHECK(x != ev.buffer_data_size);
# endif
# ifdef GL_COMPATIBLE_SUBROUTINES
	BOOST_CHECK(x != ev.compatible_subroutines);
# endif
# ifdef GL_IS_PER_PATCH
	BOOST_CHECK(x != ev.is_per_patch);
# endif
# ifdef GL_IS_ROW_MAJOR
	BOOST_CHECK(x != ev.is_row_major);
# endif
# ifdef GL_LOCATION
	BOOST_CHECK(x != ev.location);
# endif
# ifdef GL_LOCATION_COMPONENT
	BOOST_CHECK(x != ev.location_component);
# endif
	BOOST_CHECK(x == ev.location_index);
# ifdef GL_MATRIX_STRIDE
	BOOST_CHECK(x != ev.matrix_stride);
# endif
# ifdef GL_NUM_ACTIVE_VARIABLES
	BOOST_CHECK(x != ev.num_active_variables);
# endif
# ifdef GL_NUM_COMPATIBLE_SUBROUTINES
	BOOST_CHECK(x != ev.num_compatible_subroutines);
# endif
# ifdef GL_OFFSET
	BOOST_CHECK(x != ev.offset);
# endif
# ifdef GL_REFERENCED_BY_COMPUTE_SHADER
	BOOST_CHECK(x != ev.referenced_by_compute_shader);
# endif
# ifdef GL_REFERENCED_BY_FRAGMENT_SHADER
	BOOST_CHECK(x != ev.referenced_by_fragment_shader);
# endif
# ifdef GL_REFERENCED_BY_GEOMETRY_SHADER
	BOOST_CHECK(x != ev.referenced_by_geometry_shader);
# endif
# ifdef GL_REFERENCED_BY_TESS_CONTROL_SHADER
	BOOST_CHECK(x != ev.referenced_by_tess_control_shader);
# endif
# ifdef GL_REFERENCED_BY_TESS_EVALUATION_SHADER
	BOOST_CHECK(x != ev.referenced_by_tess_evaluation_shader);
# endif
# ifdef GL_REFERENCED_BY_VERTEX_SHADER
	BOOST_CHECK(x != ev.referenced_by_vertex_shader);
# endif
# ifdef GL_TOP_LEVEL_ARRAY_SIZE
	BOOST_CHECK(x != ev.top_level_array_size);
# endif
# ifdef GL_TOP_LEVEL_ARRAY_STRIDE
	BOOST_CHECK(x != ev.top_level_array_stride);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_INDEX
	BOOST_CHECK(x != ev.transform_feedback_buffer_index);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE
	BOOST_CHECK(x != ev.transform_feedback_buffer_stride);
# endif
#endif

#ifdef GL_MATRIX_STRIDE
	x = ev.matrix_stride;
# ifdef GL_ACTIVE_VARIABLES
	BOOST_CHECK(x != ev.active_variables);
# endif
# ifdef GL_ARRAY_SIZE
	BOOST_CHECK(x != ev.array_size);
# endif
# ifdef GL_ARRAY_STRIDE
	BOOST_CHECK(x != ev.array_stride);
# endif
# ifdef GL_ATOMIC_COUNTER_BUFFER_INDEX
	BOOST_CHECK(x != ev.atomic_counter_buffer_index);
# endif
# ifdef GL_BLOCK_INDEX
	BOOST_CHECK(x != ev.block_index);
# endif
# ifdef GL_BUFFER_BINDING
	BOOST_CHECK(x != ev.buffer_binding);
# endif
# ifdef GL_BUFFER_DATA_SIZE
	BOOST_CHECK(x != ev.buffer_data_size);
# endif
# ifdef GL_COMPATIBLE_SUBROUTINES
	BOOST_CHECK(x != ev.compatible_subroutines);
# endif
# ifdef GL_IS_PER_PATCH
	BOOST_CHECK(x != ev.is_per_patch);
# endif
# ifdef GL_IS_ROW_MAJOR
	BOOST_CHECK(x != ev.is_row_major);
# endif
# ifdef GL_LOCATION
	BOOST_CHECK(x != ev.location);
# endif
# ifdef GL_LOCATION_COMPONENT
	BOOST_CHECK(x != ev.location_component);
# endif
# ifdef GL_LOCATION_INDEX
	BOOST_CHECK(x != ev.location_index);
# endif
	BOOST_CHECK(x == ev.matrix_stride);
# ifdef GL_NUM_ACTIVE_VARIABLES
	BOOST_CHECK(x != ev.num_active_variables);
# endif
# ifdef GL_NUM_COMPATIBLE_SUBROUTINES
	BOOST_CHECK(x != ev.num_compatible_subroutines);
# endif
# ifdef GL_OFFSET
	BOOST_CHECK(x != ev.offset);
# endif
# ifdef GL_REFERENCED_BY_COMPUTE_SHADER
	BOOST_CHECK(x != ev.referenced_by_compute_shader);
# endif
# ifdef GL_REFERENCED_BY_FRAGMENT_SHADER
	BOOST_CHECK(x != ev.referenced_by_fragment_shader);
# endif
# ifdef GL_REFERENCED_BY_GEOMETRY_SHADER
	BOOST_CHECK(x != ev.referenced_by_geometry_shader);
# endif
# ifdef GL_REFERENCED_BY_TESS_CONTROL_SHADER
	BOOST_CHECK(x != ev.referenced_by_tess_control_shader);
# endif
# ifdef GL_REFERENCED_BY_TESS_EVALUATION_SHADER
	BOOST_CHECK(x != ev.referenced_by_tess_evaluation_shader);
# endif
# ifdef GL_REFERENCED_BY_VERTEX_SHADER
	BOOST_CHECK(x != ev.referenced_by_vertex_shader);
# endif
# ifdef GL_TOP_LEVEL_ARRAY_SIZE
	BOOST_CHECK(x != ev.top_level_array_size);
# endif
# ifdef GL_TOP_LEVEL_ARRAY_STRIDE
	BOOST_CHECK(x != ev.top_level_array_stride);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_INDEX
	BOOST_CHECK(x != ev.transform_feedback_buffer_index);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE
	BOOST_CHECK(x != ev.transform_feedback_buffer_stride);
# endif
#endif

#ifdef GL_NUM_ACTIVE_VARIABLES
	x = ev.num_active_variables;
# ifdef GL_ACTIVE_VARIABLES
	BOOST_CHECK(x != ev.active_variables);
# endif
# ifdef GL_ARRAY_SIZE
	BOOST_CHECK(x != ev.array_size);
# endif
# ifdef GL_ARRAY_STRIDE
	BOOST_CHECK(x != ev.array_stride);
# endif
# ifdef GL_ATOMIC_COUNTER_BUFFER_INDEX
	BOOST_CHECK(x != ev.atomic_counter_buffer_index);
# endif
# ifdef GL_BLOCK_INDEX
	BOOST_CHECK(x != ev.block_index);
# endif
# ifdef GL_BUFFER_BINDING
	BOOST_CHECK(x != ev.buffer_binding);
# endif
# ifdef GL_BUFFER_DATA_SIZE
	BOOST_CHECK(x != ev.buffer_data_size);
# endif
# ifdef GL_COMPATIBLE_SUBROUTINES
	BOOST_CHECK(x != ev.compatible_subroutines);
# endif
# ifdef GL_IS_PER_PATCH
	BOOST_CHECK(x != ev.is_per_patch);
# endif
# ifdef GL_IS_ROW_MAJOR
	BOOST_CHECK(x != ev.is_row_major);
# endif
# ifdef GL_LOCATION
	BOOST_CHECK(x != ev.location);
# endif
# ifdef GL_LOCATION_COMPONENT
	BOOST_CHECK(x != ev.location_component);
# endif
# ifdef GL_LOCATION_INDEX
	BOOST_CHECK(x != ev.location_index);
# endif
# ifdef GL_MATRIX_STRIDE
	BOOST_CHECK(x != ev.matrix_stride);
# endif
	BOOST_CHECK(x == ev.num_active_variables);
# ifdef GL_NUM_COMPATIBLE_SUBROUTINES
	BOOST_CHECK(x != ev.num_compatible_subroutines);
# endif
# ifdef GL_OFFSET
	BOOST_CHECK(x != ev.offset);
# endif
# ifdef GL_REFERENCED_BY_COMPUTE_SHADER
	BOOST_CHECK(x != ev.referenced_by_compute_shader);
# endif
# ifdef GL_REFERENCED_BY_FRAGMENT_SHADER
	BOOST_CHECK(x != ev.referenced_by_fragment_shader);
# endif
# ifdef GL_REFERENCED_BY_GEOMETRY_SHADER
	BOOST_CHECK(x != ev.referenced_by_geometry_shader);
# endif
# ifdef GL_REFERENCED_BY_TESS_CONTROL_SHADER
	BOOST_CHECK(x != ev.referenced_by_tess_control_shader);
# endif
# ifdef GL_REFERENCED_BY_TESS_EVALUATION_SHADER
	BOOST_CHECK(x != ev.referenced_by_tess_evaluation_shader);
# endif
# ifdef GL_REFERENCED_BY_VERTEX_SHADER
	BOOST_CHECK(x != ev.referenced_by_vertex_shader);
# endif
# ifdef GL_TOP_LEVEL_ARRAY_SIZE
	BOOST_CHECK(x != ev.top_level_array_size);
# endif
# ifdef GL_TOP_LEVEL_ARRAY_STRIDE
	BOOST_CHECK(x != ev.top_level_array_stride);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_INDEX
	BOOST_CHECK(x != ev.transform_feedback_buffer_index);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE
	BOOST_CHECK(x != ev.transform_feedback_buffer_stride);
# endif
#endif

#ifdef GL_NUM_COMPATIBLE_SUBROUTINES
	x = ev.num_compatible_subroutines;
# ifdef GL_ACTIVE_VARIABLES
	BOOST_CHECK(x != ev.active_variables);
# endif
# ifdef GL_ARRAY_SIZE
	BOOST_CHECK(x != ev.array_size);
# endif
# ifdef GL_ARRAY_STRIDE
	BOOST_CHECK(x != ev.array_stride);
# endif
# ifdef GL_ATOMIC_COUNTER_BUFFER_INDEX
	BOOST_CHECK(x != ev.atomic_counter_buffer_index);
# endif
# ifdef GL_BLOCK_INDEX
	BOOST_CHECK(x != ev.block_index);
# endif
# ifdef GL_BUFFER_BINDING
	BOOST_CHECK(x != ev.buffer_binding);
# endif
# ifdef GL_BUFFER_DATA_SIZE
	BOOST_CHECK(x != ev.buffer_data_size);
# endif
# ifdef GL_COMPATIBLE_SUBROUTINES
	BOOST_CHECK(x != ev.compatible_subroutines);
# endif
# ifdef GL_IS_PER_PATCH
	BOOST_CHECK(x != ev.is_per_patch);
# endif
# ifdef GL_IS_ROW_MAJOR
	BOOST_CHECK(x != ev.is_row_major);
# endif
# ifdef GL_LOCATION
	BOOST_CHECK(x != ev.location);
# endif
# ifdef GL_LOCATION_COMPONENT
	BOOST_CHECK(x != ev.location_component);
# endif
# ifdef GL_LOCATION_INDEX
	BOOST_CHECK(x != ev.location_index);
# endif
# ifdef GL_MATRIX_STRIDE
	BOOST_CHECK(x != ev.matrix_stride);
# endif
# ifdef GL_NUM_ACTIVE_VARIABLES
	BOOST_CHECK(x != ev.num_active_variables);
# endif
	BOOST_CHECK(x == ev.num_compatible_subroutines);
# ifdef GL_OFFSET
	BOOST_CHECK(x != ev.offset);
# endif
# ifdef GL_REFERENCED_BY_COMPUTE_SHADER
	BOOST_CHECK(x != ev.referenced_by_compute_shader);
# endif
# ifdef GL_REFERENCED_BY_FRAGMENT_SHADER
	BOOST_CHECK(x != ev.referenced_by_fragment_shader);
# endif
# ifdef GL_REFERENCED_BY_GEOMETRY_SHADER
	BOOST_CHECK(x != ev.referenced_by_geometry_shader);
# endif
# ifdef GL_REFERENCED_BY_TESS_CONTROL_SHADER
	BOOST_CHECK(x != ev.referenced_by_tess_control_shader);
# endif
# ifdef GL_REFERENCED_BY_TESS_EVALUATION_SHADER
	BOOST_CHECK(x != ev.referenced_by_tess_evaluation_shader);
# endif
# ifdef GL_REFERENCED_BY_VERTEX_SHADER
	BOOST_CHECK(x != ev.referenced_by_vertex_shader);
# endif
# ifdef GL_TOP_LEVEL_ARRAY_SIZE
	BOOST_CHECK(x != ev.top_level_array_size);
# endif
# ifdef GL_TOP_LEVEL_ARRAY_STRIDE
	BOOST_CHECK(x != ev.top_level_array_stride);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_INDEX
	BOOST_CHECK(x != ev.transform_feedback_buffer_index);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE
	BOOST_CHECK(x != ev.transform_feedback_buffer_stride);
# endif
#endif

#ifdef GL_OFFSET
	x = ev.offset;
# ifdef GL_ACTIVE_VARIABLES
	BOOST_CHECK(x != ev.active_variables);
# endif
# ifdef GL_ARRAY_SIZE
	BOOST_CHECK(x != ev.array_size);
# endif
# ifdef GL_ARRAY_STRIDE
	BOOST_CHECK(x != ev.array_stride);
# endif
# ifdef GL_ATOMIC_COUNTER_BUFFER_INDEX
	BOOST_CHECK(x != ev.atomic_counter_buffer_index);
# endif
# ifdef GL_BLOCK_INDEX
	BOOST_CHECK(x != ev.block_index);
# endif
# ifdef GL_BUFFER_BINDING
	BOOST_CHECK(x != ev.buffer_binding);
# endif
# ifdef GL_BUFFER_DATA_SIZE
	BOOST_CHECK(x != ev.buffer_data_size);
# endif
# ifdef GL_COMPATIBLE_SUBROUTINES
	BOOST_CHECK(x != ev.compatible_subroutines);
# endif
# ifdef GL_IS_PER_PATCH
	BOOST_CHECK(x != ev.is_per_patch);
# endif
# ifdef GL_IS_ROW_MAJOR
	BOOST_CHECK(x != ev.is_row_major);
# endif
# ifdef GL_LOCATION
	BOOST_CHECK(x != ev.location);
# endif
# ifdef GL_LOCATION_COMPONENT
	BOOST_CHECK(x != ev.location_component);
# endif
# ifdef GL_LOCATION_INDEX
	BOOST_CHECK(x != ev.location_index);
# endif
# ifdef GL_MATRIX_STRIDE
	BOOST_CHECK(x != ev.matrix_stride);
# endif
# ifdef GL_NUM_ACTIVE_VARIABLES
	BOOST_CHECK(x != ev.num_active_variables);
# endif
# ifdef GL_NUM_COMPATIBLE_SUBROUTINES
	BOOST_CHECK(x != ev.num_compatible_subroutines);
# endif
	BOOST_CHECK(x == ev.offset);
# ifdef GL_REFERENCED_BY_COMPUTE_SHADER
	BOOST_CHECK(x != ev.referenced_by_compute_shader);
# endif
# ifdef GL_REFERENCED_BY_FRAGMENT_SHADER
	BOOST_CHECK(x != ev.referenced_by_fragment_shader);
# endif
# ifdef GL_REFERENCED_BY_GEOMETRY_SHADER
	BOOST_CHECK(x != ev.referenced_by_geometry_shader);
# endif
# ifdef GL_REFERENCED_BY_TESS_CONTROL_SHADER
	BOOST_CHECK(x != ev.referenced_by_tess_control_shader);
# endif
# ifdef GL_REFERENCED_BY_TESS_EVALUATION_SHADER
	BOOST_CHECK(x != ev.referenced_by_tess_evaluation_shader);
# endif
# ifdef GL_REFERENCED_BY_VERTEX_SHADER
	BOOST_CHECK(x != ev.referenced_by_vertex_shader);
# endif
# ifdef GL_TOP_LEVEL_ARRAY_SIZE
	BOOST_CHECK(x != ev.top_level_array_size);
# endif
# ifdef GL_TOP_LEVEL_ARRAY_STRIDE
	BOOST_CHECK(x != ev.top_level_array_stride);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_INDEX
	BOOST_CHECK(x != ev.transform_feedback_buffer_index);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE
	BOOST_CHECK(x != ev.transform_feedback_buffer_stride);
# endif
#endif

#ifdef GL_REFERENCED_BY_COMPUTE_SHADER
	x = ev.referenced_by_compute_shader;
# ifdef GL_ACTIVE_VARIABLES
	BOOST_CHECK(x != ev.active_variables);
# endif
# ifdef GL_ARRAY_SIZE
	BOOST_CHECK(x != ev.array_size);
# endif
# ifdef GL_ARRAY_STRIDE
	BOOST_CHECK(x != ev.array_stride);
# endif
# ifdef GL_ATOMIC_COUNTER_BUFFER_INDEX
	BOOST_CHECK(x != ev.atomic_counter_buffer_index);
# endif
# ifdef GL_BLOCK_INDEX
	BOOST_CHECK(x != ev.block_index);
# endif
# ifdef GL_BUFFER_BINDING
	BOOST_CHECK(x != ev.buffer_binding);
# endif
# ifdef GL_BUFFER_DATA_SIZE
	BOOST_CHECK(x != ev.buffer_data_size);
# endif
# ifdef GL_COMPATIBLE_SUBROUTINES
	BOOST_CHECK(x != ev.compatible_subroutines);
# endif
# ifdef GL_IS_PER_PATCH
	BOOST_CHECK(x != ev.is_per_patch);
# endif
# ifdef GL_IS_ROW_MAJOR
	BOOST_CHECK(x != ev.is_row_major);
# endif
# ifdef GL_LOCATION
	BOOST_CHECK(x != ev.location);
# endif
# ifdef GL_LOCATION_COMPONENT
	BOOST_CHECK(x != ev.location_component);
# endif
# ifdef GL_LOCATION_INDEX
	BOOST_CHECK(x != ev.location_index);
# endif
# ifdef GL_MATRIX_STRIDE
	BOOST_CHECK(x != ev.matrix_stride);
# endif
# ifdef GL_NUM_ACTIVE_VARIABLES
	BOOST_CHECK(x != ev.num_active_variables);
# endif
# ifdef GL_NUM_COMPATIBLE_SUBROUTINES
	BOOST_CHECK(x != ev.num_compatible_subroutines);
# endif
# ifdef GL_OFFSET
	BOOST_CHECK(x != ev.offset);
# endif
	BOOST_CHECK(x == ev.referenced_by_compute_shader);
# ifdef GL_REFERENCED_BY_FRAGMENT_SHADER
	BOOST_CHECK(x != ev.referenced_by_fragment_shader);
# endif
# ifdef GL_REFERENCED_BY_GEOMETRY_SHADER
	BOOST_CHECK(x != ev.referenced_by_geometry_shader);
# endif
# ifdef GL_REFERENCED_BY_TESS_CONTROL_SHADER
	BOOST_CHECK(x != ev.referenced_by_tess_control_shader);
# endif
# ifdef GL_REFERENCED_BY_TESS_EVALUATION_SHADER
	BOOST_CHECK(x != ev.referenced_by_tess_evaluation_shader);
# endif
# ifdef GL_REFERENCED_BY_VERTEX_SHADER
	BOOST_CHECK(x != ev.referenced_by_vertex_shader);
# endif
# ifdef GL_TOP_LEVEL_ARRAY_SIZE
	BOOST_CHECK(x != ev.top_level_array_size);
# endif
# ifdef GL_TOP_LEVEL_ARRAY_STRIDE
	BOOST_CHECK(x != ev.top_level_array_stride);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_INDEX
	BOOST_CHECK(x != ev.transform_feedback_buffer_index);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE
	BOOST_CHECK(x != ev.transform_feedback_buffer_stride);
# endif
#endif

#ifdef GL_REFERENCED_BY_FRAGMENT_SHADER
	x = ev.referenced_by_fragment_shader;
# ifdef GL_ACTIVE_VARIABLES
	BOOST_CHECK(x != ev.active_variables);
# endif
# ifdef GL_ARRAY_SIZE
	BOOST_CHECK(x != ev.array_size);
# endif
# ifdef GL_ARRAY_STRIDE
	BOOST_CHECK(x != ev.array_stride);
# endif
# ifdef GL_ATOMIC_COUNTER_BUFFER_INDEX
	BOOST_CHECK(x != ev.atomic_counter_buffer_index);
# endif
# ifdef GL_BLOCK_INDEX
	BOOST_CHECK(x != ev.block_index);
# endif
# ifdef GL_BUFFER_BINDING
	BOOST_CHECK(x != ev.buffer_binding);
# endif
# ifdef GL_BUFFER_DATA_SIZE
	BOOST_CHECK(x != ev.buffer_data_size);
# endif
# ifdef GL_COMPATIBLE_SUBROUTINES
	BOOST_CHECK(x != ev.compatible_subroutines);
# endif
# ifdef GL_IS_PER_PATCH
	BOOST_CHECK(x != ev.is_per_patch);
# endif
# ifdef GL_IS_ROW_MAJOR
	BOOST_CHECK(x != ev.is_row_major);
# endif
# ifdef GL_LOCATION
	BOOST_CHECK(x != ev.location);
# endif
# ifdef GL_LOCATION_COMPONENT
	BOOST_CHECK(x != ev.location_component);
# endif
# ifdef GL_LOCATION_INDEX
	BOOST_CHECK(x != ev.location_index);
# endif
# ifdef GL_MATRIX_STRIDE
	BOOST_CHECK(x != ev.matrix_stride);
# endif
# ifdef GL_NUM_ACTIVE_VARIABLES
	BOOST_CHECK(x != ev.num_active_variables);
# endif
# ifdef GL_NUM_COMPATIBLE_SUBROUTINES
	BOOST_CHECK(x != ev.num_compatible_subroutines);
# endif
# ifdef GL_OFFSET
	BOOST_CHECK(x != ev.offset);
# endif
# ifdef GL_REFERENCED_BY_COMPUTE_SHADER
	BOOST_CHECK(x != ev.referenced_by_compute_shader);
# endif
	BOOST_CHECK(x == ev.referenced_by_fragment_shader);
# ifdef GL_REFERENCED_BY_GEOMETRY_SHADER
	BOOST_CHECK(x != ev.referenced_by_geometry_shader);
# endif
# ifdef GL_REFERENCED_BY_TESS_CONTROL_SHADER
	BOOST_CHECK(x != ev.referenced_by_tess_control_shader);
# endif
# ifdef GL_REFERENCED_BY_TESS_EVALUATION_SHADER
	BOOST_CHECK(x != ev.referenced_by_tess_evaluation_shader);
# endif
# ifdef GL_REFERENCED_BY_VERTEX_SHADER
	BOOST_CHECK(x != ev.referenced_by_vertex_shader);
# endif
# ifdef GL_TOP_LEVEL_ARRAY_SIZE
	BOOST_CHECK(x != ev.top_level_array_size);
# endif
# ifdef GL_TOP_LEVEL_ARRAY_STRIDE
	BOOST_CHECK(x != ev.top_level_array_stride);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_INDEX
	BOOST_CHECK(x != ev.transform_feedback_buffer_index);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE
	BOOST_CHECK(x != ev.transform_feedback_buffer_stride);
# endif
#endif

#ifdef GL_REFERENCED_BY_GEOMETRY_SHADER
	x = ev.referenced_by_geometry_shader;
# ifdef GL_ACTIVE_VARIABLES
	BOOST_CHECK(x != ev.active_variables);
# endif
# ifdef GL_ARRAY_SIZE
	BOOST_CHECK(x != ev.array_size);
# endif
# ifdef GL_ARRAY_STRIDE
	BOOST_CHECK(x != ev.array_stride);
# endif
# ifdef GL_ATOMIC_COUNTER_BUFFER_INDEX
	BOOST_CHECK(x != ev.atomic_counter_buffer_index);
# endif
# ifdef GL_BLOCK_INDEX
	BOOST_CHECK(x != ev.block_index);
# endif
# ifdef GL_BUFFER_BINDING
	BOOST_CHECK(x != ev.buffer_binding);
# endif
# ifdef GL_BUFFER_DATA_SIZE
	BOOST_CHECK(x != ev.buffer_data_size);
# endif
# ifdef GL_COMPATIBLE_SUBROUTINES
	BOOST_CHECK(x != ev.compatible_subroutines);
# endif
# ifdef GL_IS_PER_PATCH
	BOOST_CHECK(x != ev.is_per_patch);
# endif
# ifdef GL_IS_ROW_MAJOR
	BOOST_CHECK(x != ev.is_row_major);
# endif
# ifdef GL_LOCATION
	BOOST_CHECK(x != ev.location);
# endif
# ifdef GL_LOCATION_COMPONENT
	BOOST_CHECK(x != ev.location_component);
# endif
# ifdef GL_LOCATION_INDEX
	BOOST_CHECK(x != ev.location_index);
# endif
# ifdef GL_MATRIX_STRIDE
	BOOST_CHECK(x != ev.matrix_stride);
# endif
# ifdef GL_NUM_ACTIVE_VARIABLES
	BOOST_CHECK(x != ev.num_active_variables);
# endif
# ifdef GL_NUM_COMPATIBLE_SUBROUTINES
	BOOST_CHECK(x != ev.num_compatible_subroutines);
# endif
# ifdef GL_OFFSET
	BOOST_CHECK(x != ev.offset);
# endif
# ifdef GL_REFERENCED_BY_COMPUTE_SHADER
	BOOST_CHECK(x != ev.referenced_by_compute_shader);
# endif
# ifdef GL_REFERENCED_BY_FRAGMENT_SHADER
	BOOST_CHECK(x != ev.referenced_by_fragment_shader);
# endif
	BOOST_CHECK(x == ev.referenced_by_geometry_shader);
# ifdef GL_REFERENCED_BY_TESS_CONTROL_SHADER
	BOOST_CHECK(x != ev.referenced_by_tess_control_shader);
# endif
# ifdef GL_REFERENCED_BY_TESS_EVALUATION_SHADER
	BOOST_CHECK(x != ev.referenced_by_tess_evaluation_shader);
# endif
# ifdef GL_REFERENCED_BY_VERTEX_SHADER
	BOOST_CHECK(x != ev.referenced_by_vertex_shader);
# endif
# ifdef GL_TOP_LEVEL_ARRAY_SIZE
	BOOST_CHECK(x != ev.top_level_array_size);
# endif
# ifdef GL_TOP_LEVEL_ARRAY_STRIDE
	BOOST_CHECK(x != ev.top_level_array_stride);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_INDEX
	BOOST_CHECK(x != ev.transform_feedback_buffer_index);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE
	BOOST_CHECK(x != ev.transform_feedback_buffer_stride);
# endif
#endif

#ifdef GL_REFERENCED_BY_TESS_CONTROL_SHADER
	x = ev.referenced_by_tess_control_shader;
# ifdef GL_ACTIVE_VARIABLES
	BOOST_CHECK(x != ev.active_variables);
# endif
# ifdef GL_ARRAY_SIZE
	BOOST_CHECK(x != ev.array_size);
# endif
# ifdef GL_ARRAY_STRIDE
	BOOST_CHECK(x != ev.array_stride);
# endif
# ifdef GL_ATOMIC_COUNTER_BUFFER_INDEX
	BOOST_CHECK(x != ev.atomic_counter_buffer_index);
# endif
# ifdef GL_BLOCK_INDEX
	BOOST_CHECK(x != ev.block_index);
# endif
# ifdef GL_BUFFER_BINDING
	BOOST_CHECK(x != ev.buffer_binding);
# endif
# ifdef GL_BUFFER_DATA_SIZE
	BOOST_CHECK(x != ev.buffer_data_size);
# endif
# ifdef GL_COMPATIBLE_SUBROUTINES
	BOOST_CHECK(x != ev.compatible_subroutines);
# endif
# ifdef GL_IS_PER_PATCH
	BOOST_CHECK(x != ev.is_per_patch);
# endif
# ifdef GL_IS_ROW_MAJOR
	BOOST_CHECK(x != ev.is_row_major);
# endif
# ifdef GL_LOCATION
	BOOST_CHECK(x != ev.location);
# endif
# ifdef GL_LOCATION_COMPONENT
	BOOST_CHECK(x != ev.location_component);
# endif
# ifdef GL_LOCATION_INDEX
	BOOST_CHECK(x != ev.location_index);
# endif
# ifdef GL_MATRIX_STRIDE
	BOOST_CHECK(x != ev.matrix_stride);
# endif
# ifdef GL_NUM_ACTIVE_VARIABLES
	BOOST_CHECK(x != ev.num_active_variables);
# endif
# ifdef GL_NUM_COMPATIBLE_SUBROUTINES
	BOOST_CHECK(x != ev.num_compatible_subroutines);
# endif
# ifdef GL_OFFSET
	BOOST_CHECK(x != ev.offset);
# endif
# ifdef GL_REFERENCED_BY_COMPUTE_SHADER
	BOOST_CHECK(x != ev.referenced_by_compute_shader);
# endif
# ifdef GL_REFERENCED_BY_FRAGMENT_SHADER
	BOOST_CHECK(x != ev.referenced_by_fragment_shader);
# endif
# ifdef GL_REFERENCED_BY_GEOMETRY_SHADER
	BOOST_CHECK(x != ev.referenced_by_geometry_shader);
# endif
	BOOST_CHECK(x == ev.referenced_by_tess_control_shader);
# ifdef GL_REFERENCED_BY_TESS_EVALUATION_SHADER
	BOOST_CHECK(x != ev.referenced_by_tess_evaluation_shader);
# endif
# ifdef GL_REFERENCED_BY_VERTEX_SHADER
	BOOST_CHECK(x != ev.referenced_by_vertex_shader);
# endif
# ifdef GL_TOP_LEVEL_ARRAY_SIZE
	BOOST_CHECK(x != ev.top_level_array_size);
# endif
# ifdef GL_TOP_LEVEL_ARRAY_STRIDE
	BOOST_CHECK(x != ev.top_level_array_stride);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_INDEX
	BOOST_CHECK(x != ev.transform_feedback_buffer_index);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE
	BOOST_CHECK(x != ev.transform_feedback_buffer_stride);
# endif
#endif

#ifdef GL_REFERENCED_BY_TESS_EVALUATION_SHADER
	x = ev.referenced_by_tess_evaluation_shader;
# ifdef GL_ACTIVE_VARIABLES
	BOOST_CHECK(x != ev.active_variables);
# endif
# ifdef GL_ARRAY_SIZE
	BOOST_CHECK(x != ev.array_size);
# endif
# ifdef GL_ARRAY_STRIDE
	BOOST_CHECK(x != ev.array_stride);
# endif
# ifdef GL_ATOMIC_COUNTER_BUFFER_INDEX
	BOOST_CHECK(x != ev.atomic_counter_buffer_index);
# endif
# ifdef GL_BLOCK_INDEX
	BOOST_CHECK(x != ev.block_index);
# endif
# ifdef GL_BUFFER_BINDING
	BOOST_CHECK(x != ev.buffer_binding);
# endif
# ifdef GL_BUFFER_DATA_SIZE
	BOOST_CHECK(x != ev.buffer_data_size);
# endif
# ifdef GL_COMPATIBLE_SUBROUTINES
	BOOST_CHECK(x != ev.compatible_subroutines);
# endif
# ifdef GL_IS_PER_PATCH
	BOOST_CHECK(x != ev.is_per_patch);
# endif
# ifdef GL_IS_ROW_MAJOR
	BOOST_CHECK(x != ev.is_row_major);
# endif
# ifdef GL_LOCATION
	BOOST_CHECK(x != ev.location);
# endif
# ifdef GL_LOCATION_COMPONENT
	BOOST_CHECK(x != ev.location_component);
# endif
# ifdef GL_LOCATION_INDEX
	BOOST_CHECK(x != ev.location_index);
# endif
# ifdef GL_MATRIX_STRIDE
	BOOST_CHECK(x != ev.matrix_stride);
# endif
# ifdef GL_NUM_ACTIVE_VARIABLES
	BOOST_CHECK(x != ev.num_active_variables);
# endif
# ifdef GL_NUM_COMPATIBLE_SUBROUTINES
	BOOST_CHECK(x != ev.num_compatible_subroutines);
# endif
# ifdef GL_OFFSET
	BOOST_CHECK(x != ev.offset);
# endif
# ifdef GL_REFERENCED_BY_COMPUTE_SHADER
	BOOST_CHECK(x != ev.referenced_by_compute_shader);
# endif
# ifdef GL_REFERENCED_BY_FRAGMENT_SHADER
	BOOST_CHECK(x != ev.referenced_by_fragment_shader);
# endif
# ifdef GL_REFERENCED_BY_GEOMETRY_SHADER
	BOOST_CHECK(x != ev.referenced_by_geometry_shader);
# endif
# ifdef GL_REFERENCED_BY_TESS_CONTROL_SHADER
	BOOST_CHECK(x != ev.referenced_by_tess_control_shader);
# endif
	BOOST_CHECK(x == ev.referenced_by_tess_evaluation_shader);
# ifdef GL_REFERENCED_BY_VERTEX_SHADER
	BOOST_CHECK(x != ev.referenced_by_vertex_shader);
# endif
# ifdef GL_TOP_LEVEL_ARRAY_SIZE
	BOOST_CHECK(x != ev.top_level_array_size);
# endif
# ifdef GL_TOP_LEVEL_ARRAY_STRIDE
	BOOST_CHECK(x != ev.top_level_array_stride);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_INDEX
	BOOST_CHECK(x != ev.transform_feedback_buffer_index);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE
	BOOST_CHECK(x != ev.transform_feedback_buffer_stride);
# endif
#endif

#ifdef GL_REFERENCED_BY_VERTEX_SHADER
	x = ev.referenced_by_vertex_shader;
# ifdef GL_ACTIVE_VARIABLES
	BOOST_CHECK(x != ev.active_variables);
# endif
# ifdef GL_ARRAY_SIZE
	BOOST_CHECK(x != ev.array_size);
# endif
# ifdef GL_ARRAY_STRIDE
	BOOST_CHECK(x != ev.array_stride);
# endif
# ifdef GL_ATOMIC_COUNTER_BUFFER_INDEX
	BOOST_CHECK(x != ev.atomic_counter_buffer_index);
# endif
# ifdef GL_BLOCK_INDEX
	BOOST_CHECK(x != ev.block_index);
# endif
# ifdef GL_BUFFER_BINDING
	BOOST_CHECK(x != ev.buffer_binding);
# endif
# ifdef GL_BUFFER_DATA_SIZE
	BOOST_CHECK(x != ev.buffer_data_size);
# endif
# ifdef GL_COMPATIBLE_SUBROUTINES
	BOOST_CHECK(x != ev.compatible_subroutines);
# endif
# ifdef GL_IS_PER_PATCH
	BOOST_CHECK(x != ev.is_per_patch);
# endif
# ifdef GL_IS_ROW_MAJOR
	BOOST_CHECK(x != ev.is_row_major);
# endif
# ifdef GL_LOCATION
	BOOST_CHECK(x != ev.location);
# endif
# ifdef GL_LOCATION_COMPONENT
	BOOST_CHECK(x != ev.location_component);
# endif
# ifdef GL_LOCATION_INDEX
	BOOST_CHECK(x != ev.location_index);
# endif
# ifdef GL_MATRIX_STRIDE
	BOOST_CHECK(x != ev.matrix_stride);
# endif
# ifdef GL_NUM_ACTIVE_VARIABLES
	BOOST_CHECK(x != ev.num_active_variables);
# endif
# ifdef GL_NUM_COMPATIBLE_SUBROUTINES
	BOOST_CHECK(x != ev.num_compatible_subroutines);
# endif
# ifdef GL_OFFSET
	BOOST_CHECK(x != ev.offset);
# endif
# ifdef GL_REFERENCED_BY_COMPUTE_SHADER
	BOOST_CHECK(x != ev.referenced_by_compute_shader);
# endif
# ifdef GL_REFERENCED_BY_FRAGMENT_SHADER
	BOOST_CHECK(x != ev.referenced_by_fragment_shader);
# endif
# ifdef GL_REFERENCED_BY_GEOMETRY_SHADER
	BOOST_CHECK(x != ev.referenced_by_geometry_shader);
# endif
# ifdef GL_REFERENCED_BY_TESS_CONTROL_SHADER
	BOOST_CHECK(x != ev.referenced_by_tess_control_shader);
# endif
# ifdef GL_REFERENCED_BY_TESS_EVALUATION_SHADER
	BOOST_CHECK(x != ev.referenced_by_tess_evaluation_shader);
# endif
	BOOST_CHECK(x == ev.referenced_by_vertex_shader);
# ifdef GL_TOP_LEVEL_ARRAY_SIZE
	BOOST_CHECK(x != ev.top_level_array_size);
# endif
# ifdef GL_TOP_LEVEL_ARRAY_STRIDE
	BOOST_CHECK(x != ev.top_level_array_stride);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_INDEX
	BOOST_CHECK(x != ev.transform_feedback_buffer_index);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE
	BOOST_CHECK(x != ev.transform_feedback_buffer_stride);
# endif
#endif

#ifdef GL_TOP_LEVEL_ARRAY_SIZE
	x = ev.top_level_array_size;
# ifdef GL_ACTIVE_VARIABLES
	BOOST_CHECK(x != ev.active_variables);
# endif
# ifdef GL_ARRAY_SIZE
	BOOST_CHECK(x != ev.array_size);
# endif
# ifdef GL_ARRAY_STRIDE
	BOOST_CHECK(x != ev.array_stride);
# endif
# ifdef GL_ATOMIC_COUNTER_BUFFER_INDEX
	BOOST_CHECK(x != ev.atomic_counter_buffer_index);
# endif
# ifdef GL_BLOCK_INDEX
	BOOST_CHECK(x != ev.block_index);
# endif
# ifdef GL_BUFFER_BINDING
	BOOST_CHECK(x != ev.buffer_binding);
# endif
# ifdef GL_BUFFER_DATA_SIZE
	BOOST_CHECK(x != ev.buffer_data_size);
# endif
# ifdef GL_COMPATIBLE_SUBROUTINES
	BOOST_CHECK(x != ev.compatible_subroutines);
# endif
# ifdef GL_IS_PER_PATCH
	BOOST_CHECK(x != ev.is_per_patch);
# endif
# ifdef GL_IS_ROW_MAJOR
	BOOST_CHECK(x != ev.is_row_major);
# endif
# ifdef GL_LOCATION
	BOOST_CHECK(x != ev.location);
# endif
# ifdef GL_LOCATION_COMPONENT
	BOOST_CHECK(x != ev.location_component);
# endif
# ifdef GL_LOCATION_INDEX
	BOOST_CHECK(x != ev.location_index);
# endif
# ifdef GL_MATRIX_STRIDE
	BOOST_CHECK(x != ev.matrix_stride);
# endif
# ifdef GL_NUM_ACTIVE_VARIABLES
	BOOST_CHECK(x != ev.num_active_variables);
# endif
# ifdef GL_NUM_COMPATIBLE_SUBROUTINES
	BOOST_CHECK(x != ev.num_compatible_subroutines);
# endif
# ifdef GL_OFFSET
	BOOST_CHECK(x != ev.offset);
# endif
# ifdef GL_REFERENCED_BY_COMPUTE_SHADER
	BOOST_CHECK(x != ev.referenced_by_compute_shader);
# endif
# ifdef GL_REFERENCED_BY_FRAGMENT_SHADER
	BOOST_CHECK(x != ev.referenced_by_fragment_shader);
# endif
# ifdef GL_REFERENCED_BY_GEOMETRY_SHADER
	BOOST_CHECK(x != ev.referenced_by_geometry_shader);
# endif
# ifdef GL_REFERENCED_BY_TESS_CONTROL_SHADER
	BOOST_CHECK(x != ev.referenced_by_tess_control_shader);
# endif
# ifdef GL_REFERENCED_BY_TESS_EVALUATION_SHADER
	BOOST_CHECK(x != ev.referenced_by_tess_evaluation_shader);
# endif
# ifdef GL_REFERENCED_BY_VERTEX_SHADER
	BOOST_CHECK(x != ev.referenced_by_vertex_shader);
# endif
	BOOST_CHECK(x == ev.top_level_array_size);
# ifdef GL_TOP_LEVEL_ARRAY_STRIDE
	BOOST_CHECK(x != ev.top_level_array_stride);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_INDEX
	BOOST_CHECK(x != ev.transform_feedback_buffer_index);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE
	BOOST_CHECK(x != ev.transform_feedback_buffer_stride);
# endif
#endif

#ifdef GL_TOP_LEVEL_ARRAY_STRIDE
	x = ev.top_level_array_stride;
# ifdef GL_ACTIVE_VARIABLES
	BOOST_CHECK(x != ev.active_variables);
# endif
# ifdef GL_ARRAY_SIZE
	BOOST_CHECK(x != ev.array_size);
# endif
# ifdef GL_ARRAY_STRIDE
	BOOST_CHECK(x != ev.array_stride);
# endif
# ifdef GL_ATOMIC_COUNTER_BUFFER_INDEX
	BOOST_CHECK(x != ev.atomic_counter_buffer_index);
# endif
# ifdef GL_BLOCK_INDEX
	BOOST_CHECK(x != ev.block_index);
# endif
# ifdef GL_BUFFER_BINDING
	BOOST_CHECK(x != ev.buffer_binding);
# endif
# ifdef GL_BUFFER_DATA_SIZE
	BOOST_CHECK(x != ev.buffer_data_size);
# endif
# ifdef GL_COMPATIBLE_SUBROUTINES
	BOOST_CHECK(x != ev.compatible_subroutines);
# endif
# ifdef GL_IS_PER_PATCH
	BOOST_CHECK(x != ev.is_per_patch);
# endif
# ifdef GL_IS_ROW_MAJOR
	BOOST_CHECK(x != ev.is_row_major);
# endif
# ifdef GL_LOCATION
	BOOST_CHECK(x != ev.location);
# endif
# ifdef GL_LOCATION_COMPONENT
	BOOST_CHECK(x != ev.location_component);
# endif
# ifdef GL_LOCATION_INDEX
	BOOST_CHECK(x != ev.location_index);
# endif
# ifdef GL_MATRIX_STRIDE
	BOOST_CHECK(x != ev.matrix_stride);
# endif
# ifdef GL_NUM_ACTIVE_VARIABLES
	BOOST_CHECK(x != ev.num_active_variables);
# endif
# ifdef GL_NUM_COMPATIBLE_SUBROUTINES
	BOOST_CHECK(x != ev.num_compatible_subroutines);
# endif
# ifdef GL_OFFSET
	BOOST_CHECK(x != ev.offset);
# endif
# ifdef GL_REFERENCED_BY_COMPUTE_SHADER
	BOOST_CHECK(x != ev.referenced_by_compute_shader);
# endif
# ifdef GL_REFERENCED_BY_FRAGMENT_SHADER
	BOOST_CHECK(x != ev.referenced_by_fragment_shader);
# endif
# ifdef GL_REFERENCED_BY_GEOMETRY_SHADER
	BOOST_CHECK(x != ev.referenced_by_geometry_shader);
# endif
# ifdef GL_REFERENCED_BY_TESS_CONTROL_SHADER
	BOOST_CHECK(x != ev.referenced_by_tess_control_shader);
# endif
# ifdef GL_REFERENCED_BY_TESS_EVALUATION_SHADER
	BOOST_CHECK(x != ev.referenced_by_tess_evaluation_shader);
# endif
# ifdef GL_REFERENCED_BY_VERTEX_SHADER
	BOOST_CHECK(x != ev.referenced_by_vertex_shader);
# endif
# ifdef GL_TOP_LEVEL_ARRAY_SIZE
	BOOST_CHECK(x != ev.top_level_array_size);
# endif
	BOOST_CHECK(x == ev.top_level_array_stride);
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_INDEX
	BOOST_CHECK(x != ev.transform_feedback_buffer_index);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE
	BOOST_CHECK(x != ev.transform_feedback_buffer_stride);
# endif
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_INDEX
	x = ev.transform_feedback_buffer_index;
# ifdef GL_ACTIVE_VARIABLES
	BOOST_CHECK(x != ev.active_variables);
# endif
# ifdef GL_ARRAY_SIZE
	BOOST_CHECK(x != ev.array_size);
# endif
# ifdef GL_ARRAY_STRIDE
	BOOST_CHECK(x != ev.array_stride);
# endif
# ifdef GL_ATOMIC_COUNTER_BUFFER_INDEX
	BOOST_CHECK(x != ev.atomic_counter_buffer_index);
# endif
# ifdef GL_BLOCK_INDEX
	BOOST_CHECK(x != ev.block_index);
# endif
# ifdef GL_BUFFER_BINDING
	BOOST_CHECK(x != ev.buffer_binding);
# endif
# ifdef GL_BUFFER_DATA_SIZE
	BOOST_CHECK(x != ev.buffer_data_size);
# endif
# ifdef GL_COMPATIBLE_SUBROUTINES
	BOOST_CHECK(x != ev.compatible_subroutines);
# endif
# ifdef GL_IS_PER_PATCH
	BOOST_CHECK(x != ev.is_per_patch);
# endif
# ifdef GL_IS_ROW_MAJOR
	BOOST_CHECK(x != ev.is_row_major);
# endif
# ifdef GL_LOCATION
	BOOST_CHECK(x != ev.location);
# endif
# ifdef GL_LOCATION_COMPONENT
	BOOST_CHECK(x != ev.location_component);
# endif
# ifdef GL_LOCATION_INDEX
	BOOST_CHECK(x != ev.location_index);
# endif
# ifdef GL_MATRIX_STRIDE
	BOOST_CHECK(x != ev.matrix_stride);
# endif
# ifdef GL_NUM_ACTIVE_VARIABLES
	BOOST_CHECK(x != ev.num_active_variables);
# endif
# ifdef GL_NUM_COMPATIBLE_SUBROUTINES
	BOOST_CHECK(x != ev.num_compatible_subroutines);
# endif
# ifdef GL_OFFSET
	BOOST_CHECK(x != ev.offset);
# endif
# ifdef GL_REFERENCED_BY_COMPUTE_SHADER
	BOOST_CHECK(x != ev.referenced_by_compute_shader);
# endif
# ifdef GL_REFERENCED_BY_FRAGMENT_SHADER
	BOOST_CHECK(x != ev.referenced_by_fragment_shader);
# endif
# ifdef GL_REFERENCED_BY_GEOMETRY_SHADER
	BOOST_CHECK(x != ev.referenced_by_geometry_shader);
# endif
# ifdef GL_REFERENCED_BY_TESS_CONTROL_SHADER
	BOOST_CHECK(x != ev.referenced_by_tess_control_shader);
# endif
# ifdef GL_REFERENCED_BY_TESS_EVALUATION_SHADER
	BOOST_CHECK(x != ev.referenced_by_tess_evaluation_shader);
# endif
# ifdef GL_REFERENCED_BY_VERTEX_SHADER
	BOOST_CHECK(x != ev.referenced_by_vertex_shader);
# endif
# ifdef GL_TOP_LEVEL_ARRAY_SIZE
	BOOST_CHECK(x != ev.top_level_array_size);
# endif
# ifdef GL_TOP_LEVEL_ARRAY_STRIDE
	BOOST_CHECK(x != ev.top_level_array_stride);
# endif
	BOOST_CHECK(x == ev.transform_feedback_buffer_index);
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE
	BOOST_CHECK(x != ev.transform_feedback_buffer_stride);
# endif
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE
	x = ev.transform_feedback_buffer_stride;
# ifdef GL_ACTIVE_VARIABLES
	BOOST_CHECK(x != ev.active_variables);
# endif
# ifdef GL_ARRAY_SIZE
	BOOST_CHECK(x != ev.array_size);
# endif
# ifdef GL_ARRAY_STRIDE
	BOOST_CHECK(x != ev.array_stride);
# endif
# ifdef GL_ATOMIC_COUNTER_BUFFER_INDEX
	BOOST_CHECK(x != ev.atomic_counter_buffer_index);
# endif
# ifdef GL_BLOCK_INDEX
	BOOST_CHECK(x != ev.block_index);
# endif
# ifdef GL_BUFFER_BINDING
	BOOST_CHECK(x != ev.buffer_binding);
# endif
# ifdef GL_BUFFER_DATA_SIZE
	BOOST_CHECK(x != ev.buffer_data_size);
# endif
# ifdef GL_COMPATIBLE_SUBROUTINES
	BOOST_CHECK(x != ev.compatible_subroutines);
# endif
# ifdef GL_IS_PER_PATCH
	BOOST_CHECK(x != ev.is_per_patch);
# endif
# ifdef GL_IS_ROW_MAJOR
	BOOST_CHECK(x != ev.is_row_major);
# endif
# ifdef GL_LOCATION
	BOOST_CHECK(x != ev.location);
# endif
# ifdef GL_LOCATION_COMPONENT
	BOOST_CHECK(x != ev.location_component);
# endif
# ifdef GL_LOCATION_INDEX
	BOOST_CHECK(x != ev.location_index);
# endif
# ifdef GL_MATRIX_STRIDE
	BOOST_CHECK(x != ev.matrix_stride);
# endif
# ifdef GL_NUM_ACTIVE_VARIABLES
	BOOST_CHECK(x != ev.num_active_variables);
# endif
# ifdef GL_NUM_COMPATIBLE_SUBROUTINES
	BOOST_CHECK(x != ev.num_compatible_subroutines);
# endif
# ifdef GL_OFFSET
	BOOST_CHECK(x != ev.offset);
# endif
# ifdef GL_REFERENCED_BY_COMPUTE_SHADER
	BOOST_CHECK(x != ev.referenced_by_compute_shader);
# endif
# ifdef GL_REFERENCED_BY_FRAGMENT_SHADER
	BOOST_CHECK(x != ev.referenced_by_fragment_shader);
# endif
# ifdef GL_REFERENCED_BY_GEOMETRY_SHADER
	BOOST_CHECK(x != ev.referenced_by_geometry_shader);
# endif
# ifdef GL_REFERENCED_BY_TESS_CONTROL_SHADER
	BOOST_CHECK(x != ev.referenced_by_tess_control_shader);
# endif
# ifdef GL_REFERENCED_BY_TESS_EVALUATION_SHADER
	BOOST_CHECK(x != ev.referenced_by_tess_evaluation_shader);
# endif
# ifdef GL_REFERENCED_BY_VERTEX_SHADER
	BOOST_CHECK(x != ev.referenced_by_vertex_shader);
# endif
# ifdef GL_TOP_LEVEL_ARRAY_SIZE
	BOOST_CHECK(x != ev.top_level_array_size);
# endif
# ifdef GL_TOP_LEVEL_ARRAY_STRIDE
	BOOST_CHECK(x != ev.top_level_array_stride);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_INDEX
	BOOST_CHECK(x != ev.transform_feedback_buffer_index);
# endif
	BOOST_CHECK(x == ev.transform_feedback_buffer_stride);
#endif
}

BOOST_AUTO_TEST_CASE(enum_program_resource_property_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	program_resource_property x;
	(void)x;

#ifdef GL_ACTIVE_VARIABLES
	x = ev.active_variables;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ACTIVE_VARIABLES"
	) == 0);
#endif

#ifdef GL_ARRAY_SIZE
	x = ev.array_size;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ARRAY_SIZE"
	) == 0);
#endif

#ifdef GL_ARRAY_STRIDE
	x = ev.array_stride;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ARRAY_STRIDE"
	) == 0);
#endif

#ifdef GL_ATOMIC_COUNTER_BUFFER_INDEX
	x = ev.atomic_counter_buffer_index;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ATOMIC_COUNTER_BUFFER_INDEX"
	) == 0);
#endif

#ifdef GL_BLOCK_INDEX
	x = ev.block_index;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"BLOCK_INDEX"
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

#ifdef GL_BUFFER_DATA_SIZE
	x = ev.buffer_data_size;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"BUFFER_DATA_SIZE"
	) == 0);
#endif

#ifdef GL_COMPATIBLE_SUBROUTINES
	x = ev.compatible_subroutines;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"COMPATIBLE_SUBROUTINES"
	) == 0);
#endif

#ifdef GL_IS_PER_PATCH
	x = ev.is_per_patch;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"IS_PER_PATCH"
	) == 0);
#endif

#ifdef GL_IS_ROW_MAJOR
	x = ev.is_row_major;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"IS_ROW_MAJOR"
	) == 0);
#endif

#ifdef GL_LOCATION
	x = ev.location;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"LOCATION"
	) == 0);
#endif

#ifdef GL_LOCATION_COMPONENT
	x = ev.location_component;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"LOCATION_COMPONENT"
	) == 0);
#endif

#ifdef GL_LOCATION_INDEX
	x = ev.location_index;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"LOCATION_INDEX"
	) == 0);
#endif

#ifdef GL_MATRIX_STRIDE
	x = ev.matrix_stride;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MATRIX_STRIDE"
	) == 0);
#endif

#ifdef GL_NUM_ACTIVE_VARIABLES
	x = ev.num_active_variables;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"NUM_ACTIVE_VARIABLES"
	) == 0);
#endif

#ifdef GL_NUM_COMPATIBLE_SUBROUTINES
	x = ev.num_compatible_subroutines;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"NUM_COMPATIBLE_SUBROUTINES"
	) == 0);
#endif

#ifdef GL_OFFSET
	x = ev.offset;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"OFFSET"
	) == 0);
#endif

#ifdef GL_REFERENCED_BY_COMPUTE_SHADER
	x = ev.referenced_by_compute_shader;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"REFERENCED_BY_COMPUTE_SHADER"
	) == 0);
#endif

#ifdef GL_REFERENCED_BY_FRAGMENT_SHADER
	x = ev.referenced_by_fragment_shader;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"REFERENCED_BY_FRAGMENT_SHADER"
	) == 0);
#endif

#ifdef GL_REFERENCED_BY_GEOMETRY_SHADER
	x = ev.referenced_by_geometry_shader;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"REFERENCED_BY_GEOMETRY_SHADER"
	) == 0);
#endif

#ifdef GL_REFERENCED_BY_TESS_CONTROL_SHADER
	x = ev.referenced_by_tess_control_shader;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"REFERENCED_BY_TESS_CONTROL_SHADER"
	) == 0);
#endif

#ifdef GL_REFERENCED_BY_TESS_EVALUATION_SHADER
	x = ev.referenced_by_tess_evaluation_shader;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"REFERENCED_BY_TESS_EVALUATION_SHADER"
	) == 0);
#endif

#ifdef GL_REFERENCED_BY_VERTEX_SHADER
	x = ev.referenced_by_vertex_shader;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"REFERENCED_BY_VERTEX_SHADER"
	) == 0);
#endif

#ifdef GL_TOP_LEVEL_ARRAY_SIZE
	x = ev.top_level_array_size;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TOP_LEVEL_ARRAY_SIZE"
	) == 0);
#endif

#ifdef GL_TOP_LEVEL_ARRAY_STRIDE
	x = ev.top_level_array_stride;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TOP_LEVEL_ARRAY_STRIDE"
	) == 0);
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_INDEX
	x = ev.transform_feedback_buffer_index;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TRANSFORM_FEEDBACK_BUFFER_INDEX"
	) == 0);
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE
	x = ev.transform_feedback_buffer_stride;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TRANSFORM_FEEDBACK_BUFFER_STRIDE"
	) == 0);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
