/**
 *  @file oglplus/gl_api/constants.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_GL_API_CONSTANTS_HPP
#define OGLPLUS_GL_API_CONSTANTS_HPP

#include "c_api.hpp"
#include "enum_types.hpp"

namespace eagine {
namespace oglp {
//------------------------------------------------------------------------------
template <typename ApiTraits>
struct basic_gl_constants {
public:
    using enum_type = typename gl_types::enum_type;
    using enum_type_i = identity<enum_type>;
    template <enum_type value>
    using enum_type_c = std::integral_constant<enum_type, value>;

    using bitfield_type = typename gl_types::bitfield_type;
    using bitfield_type_i = identity<bitfield_type>;
    template <bitfield_type value>
    using bitfield_type_c = std::integral_constant<bitfield_type, value>;

    opt_c_api_constant<
      mp_list<error_code, graphics_reset_status>,
#ifdef GL_NO_ERROR
      enum_type_c<GL_NO_ERROR>>
#else
      enum_type_i>
#endif
      no_error;

    opt_c_api_constant<
      mp_list<error_code>,
#ifdef GL_INVALID_ENUM
      enum_type_c<GL_INVALID_ENUM>>
#else
      enum_type_i>
#endif
      invalid_enum;

    opt_c_api_constant<
      mp_list<error_code>,
#ifdef GL_INVALID_VALUE
      enum_type_c<GL_INVALID_VALUE>>
#else
      enum_type_i>
#endif
      invalid_value;

    opt_c_api_constant<
      mp_list<error_code>,
#ifdef GL_INVALID_OPERATION
      enum_type_c<GL_INVALID_OPERATION>>
#else
      enum_type_i>
#endif
      invalid_operation;

    opt_c_api_constant<
      mp_list<error_code>,
#ifdef GL_INVALID_FRAMEBUFFER_OPERATION
      enum_type_c<GL_INVALID_FRAMEBUFFER_OPERATION>>
#else
      enum_type_i>
#endif
      invalid_framebuffer_operation;

    opt_c_api_constant<
      mp_list<error_code>,
#ifdef GL_STACK_OVERFLOW
      enum_type_c<GL_STACK_OVERFLOW>>
#else
      enum_type_i>
#endif
      stack_overflow;

    opt_c_api_constant<
      mp_list<error_code>,
#ifdef GL_STACK_UNDERFLOW
      enum_type_c<GL_STACK_UNDERFLOW>>
#else
      enum_type_i>
#endif
      stack_underflow;

    opt_c_api_constant<
      mp_list<error_code>,
#ifdef GL_TABLE_TOO_LARGE
      enum_type_c<GL_TABLE_TOO_LARGE>>
#else
      enum_type_i>
#endif
      table_too_large;

    opt_c_api_constant<
      mp_list<error_code>,
#ifdef GL_CONTEXT_LOST
      enum_type_c<GL_CONTEXT_LOST>>
#else
      enum_type_i>
#endif
      context_lost;

    opt_c_api_constant<
      mp_list<error_code>,
#ifdef GL_OUT_OF_MEMORY
      enum_type_c<GL_OUT_OF_MEMORY>>
#else
      enum_type_i>
#endif
      out_of_memory;

    opt_c_api_constant<
      mp_list<graphics_reset_status>,
#ifdef GL_GUILTY_CONTEXT_RESET
      enum_type_c<GL_GUILTY_CONTEXT_RESET>>
#else
      enum_type_i>
#endif
      guilty_context_reset;

    opt_c_api_constant<
      mp_list<graphics_reset_status>,
#ifdef GL_INNOCENT_CONTEXT_RESET
      enum_type_c<GL_INNOCENT_CONTEXT_RESET>>
#else
      enum_type_i>
#endif
      innocent_context_reset;

    opt_c_api_constant<
      mp_list<graphics_reset_status>,
#ifdef GL_UNKNOWN_CONTEXT_RESET
      enum_type_c<GL_UNKNOWN_CONTEXT_RESET>>
#else
      enum_type_i>
#endif
      unknown_context_reset;

    opt_c_api_constant<
      mp_list<memory_barrier_bit>,
#ifdef GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT
      bitfield_type_c<GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT>>
#else
      bitfield_type_i>
#endif
      vertex_attrib_array_barrier_bit;

    opt_c_api_constant<
      mp_list<memory_barrier_bit>,
#ifdef GL_ELEMENT_ARRAY_BARRIER_BIT
      bitfield_type_c<GL_ELEMENT_ARRAY_BARRIER_BIT>>
#else
      bitfield_type_i>
#endif
      element_array_barrier_bit;

    opt_c_api_constant<
      mp_list<memory_barrier_bit>,
#ifdef GL_UNIFORM_BARRIER_BIT
      bitfield_type_c<GL_UNIFORM_BARRIER_BIT>>
#else
      bitfield_type_i>
#endif
      uniform_barrier_bit;

    opt_c_api_constant<
      mp_list<memory_barrier_bit>,
#ifdef GL_TEXTURE_FETCH_BARRIER_BIT
      bitfield_type_c<GL_TEXTURE_FETCH_BARRIER_BIT>>
#else
      bitfield_type_i>
#endif
      texture_fetch_barrier_bit;

    opt_c_api_constant<
      mp_list<memory_barrier_bit>,
#ifdef GL_SHADER_IMAGE_ACCESS_BARRIER_BIT
      bitfield_type_c<GL_SHADER_IMAGE_ACCESS_BARRIER_BIT>>
#else
      bitfield_type_i>
#endif
      shader_image_access_barrier_bit;

    opt_c_api_constant<
      mp_list<memory_barrier_bit>,
#ifdef GL_COMMAND_BARRIER_BIT
      bitfield_type_c<GL_COMMAND_BARRIER_BIT>>
#else
      bitfield_type_i>
#endif
      command_barrier_bit;

    opt_c_api_constant<
      mp_list<memory_barrier_bit>,
#ifdef GL_PIXEL_BUFFER_BARRIER_BIT
      bitfield_type_c<GL_PIXEL_BUFFER_BARRIER_BIT>>
#else
      bitfield_type_i>
#endif
      pixel_buffer_barrier_bit;

    opt_c_api_constant<
      mp_list<memory_barrier_bit>,
#ifdef GL_TEXTURE_UPDATE_BARRIER_BIT
      bitfield_type_c<GL_TEXTURE_UPDATE_BARRIER_BIT>>
#else
      bitfield_type_i>
#endif
      texture_update_barrier_bit;

    opt_c_api_constant<
      mp_list<memory_barrier_bit>,
#ifdef GL_BUFFER_UPDATE_BARRIER_BIT
      bitfield_type_c<GL_BUFFER_UPDATE_BARRIER_BIT>>
#else
      bitfield_type_i>
#endif
      buffer_update_barrier_bit;

    opt_c_api_constant<
      mp_list<memory_barrier_bit>,
#ifdef GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT
      bitfield_type_c<GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT>>
#else
      bitfield_type_i>
#endif
      client_mapped_buffer_barrier_bit;

    opt_c_api_constant<
      mp_list<memory_barrier_bit>,
#ifdef GL_QUERY_BUFFER_BARRIER_BIT
      bitfield_type_c<GL_QUERY_BUFFER_BARRIER_BIT>>
#else
      bitfield_type_i>
#endif
      query_buffer_barrier_bit;

    opt_c_api_constant<
      mp_list<memory_barrier_bit>,
#ifdef GL_FRAMEBUFFER_BARRIER_BIT
      bitfield_type_c<GL_FRAMEBUFFER_BARRIER_BIT>>
#else
      bitfield_type_i>
#endif
      framebuffer_barrier_bit;

    opt_c_api_constant<
      mp_list<memory_barrier_bit>,
#ifdef GL_TRANSFORM_FEEDBACK_BARRIER_BIT
      bitfield_type_c<GL_TRANSFORM_FEEDBACK_BARRIER_BIT>>
#else
      bitfield_type_i>
#endif
      transform_feedback_barrier_bit;

    opt_c_api_constant<
      mp_list<memory_barrier_bit>,
#ifdef GL_ATOMIC_COUNTER_BARRIER_BIT
      bitfield_type_c<GL_ATOMIC_COUNTER_BARRIER_BIT>>
#else
      bitfield_type_i>
#endif
      atomic_counter_barrier_bit;

    opt_c_api_constant<
      mp_list<memory_barrier_bit>,
#ifdef GL_SHADER_STORAGE_BARRIER_BIT
      bitfield_type_c<GL_SHADER_STORAGE_BARRIER_BIT>>
#else
      bitfield_type_i>
#endif
      shader_storage_barrier_bit;

    opt_c_api_constant<
      mp_list<memory_barrier_bit>,
#ifdef GL_ALL_BARRIER_BITS
      bitfield_type_c<GL_ALL_BARRIER_BITS>>
#else
      bitfield_type_i>
#endif
      all_barrier_bits;

    opt_c_api_constant<
      mp_list<shader_type>,
#ifdef GL_VERTEX_SHADER
      enum_type_c<GL_VERTEX_SHADER>>
#else
      enum_type_i>
#endif
      vertex_shader;

    opt_c_api_constant<
      mp_list<shader_type>,
#ifdef GL_TESS_CONTROL_SHADER
      enum_type_c<GL_TESS_CONTROL_SHADER>>
#else
      enum_type_i>
#endif
      tess_control_shader;

    opt_c_api_constant<
      mp_list<shader_type>,
#ifdef GL_TESS_EVALUATION_SHADER
      enum_type_c<GL_TESS_EVALUATION_SHADER>>
#else
      enum_type_i>
#endif
      tess_evaluation_shader;

    opt_c_api_constant<
      mp_list<shader_type>,
#ifdef GL_GEOMETRY_SHADER
      enum_type_c<GL_GEOMETRY_SHADER>>
#else
      enum_type_i>
#endif
      geometry_shader;

    opt_c_api_constant<
      mp_list<shader_type>,
#ifdef GL_FRAGMENT_SHADER
      enum_type_c<GL_FRAGMENT_SHADER>>
#else
      enum_type_i>
#endif
      fragment_shader;

    opt_c_api_constant<
      mp_list<shader_type>,
#ifdef GL_COMPUTE_SHADER
      enum_type_c<GL_COMPUTE_SHADER>>
#else
      enum_type_i>
#endif
      compute_shader;

    opt_c_api_constant<
      mp_list<buffer_target>,
#ifdef GL_ARRAY_BUFFER
      enum_type_c<GL_ARRAY_BUFFER>>
#else
      enum_type_i>
#endif
      array_buffer;

    opt_c_api_constant<
      mp_list<buffer_target, program_interface>,
#ifdef GL_ATOMIC_COUNTER_BUFFER
      enum_type_c<GL_ATOMIC_COUNTER_BUFFER>>
#else
      enum_type_i>
#endif
      atomic_counter_buffer;

    opt_c_api_constant<
      mp_list<buffer_target>,
#ifdef GL_COPY_READ_BUFFER
      enum_type_c<GL_COPY_READ_BUFFER>>
#else
      enum_type_i>
#endif
      copy_read_buffer;

    opt_c_api_constant<
      mp_list<buffer_target>,
#ifdef GL_COPY_WRITE_BUFFER
      enum_type_c<GL_COPY_WRITE_BUFFER>>
#else
      enum_type_i>
#endif
      copy_write_buffer;

    opt_c_api_constant<
      mp_list<buffer_target>,
#ifdef GL_DISPATCH_INDIRECT_BUFFER
      enum_type_c<GL_DISPATCH_INDIRECT_BUFFER>>
#else
      enum_type_i>
#endif
      dispatch_indirect_buffer;

    opt_c_api_constant<
      mp_list<buffer_target>,
#ifdef GL_DRAW_INDIRECT_BUFFER
      enum_type_c<GL_DRAW_INDIRECT_BUFFER>>
#else
      enum_type_i>
#endif
      draw_indirect_buffer;

    opt_c_api_constant<
      mp_list<buffer_target>,
#ifdef GL_ELEMENT_ARRAY_BUFFER
      enum_type_c<GL_ELEMENT_ARRAY_BUFFER>>
#else
      enum_type_i>
#endif
      element_array_buffer;

    opt_c_api_constant<
      mp_list<buffer_target>,
#ifdef GL_PARAMETER_BUFFER
      enum_type_c<GL_PARAMETER_BUFFER>>
#else
      enum_type_i>
#endif
      parameter_buffer;

    opt_c_api_constant<
      mp_list<buffer_target>,
#ifdef GL_PIXEL_PACK_BUFFER
      enum_type_c<GL_PIXEL_PACK_BUFFER>>
#else
      enum_type_i>
#endif
      pixel_pack_buffer;

    opt_c_api_constant<
      mp_list<buffer_target>,
#ifdef GL_PIXEL_UNPACK_BUFFER
      enum_type_c<GL_PIXEL_UNPACK_BUFFER>>
#else
      enum_type_i>
#endif
      pixel_unpack_buffer;

    opt_c_api_constant<
      mp_list<buffer_target>,
#ifdef GL_QUERY_BUFFER
      enum_type_c<GL_QUERY_BUFFER>>
#else
      enum_type_i>
#endif
      query_buffer;

    opt_c_api_constant<
      mp_list<buffer_target>,
#ifdef GL_SHADER_STORAGE_BUFFER
      enum_type_c<GL_SHADER_STORAGE_BUFFER>>
#else
      enum_type_i>
#endif
      shader_storage_buffer;

    opt_c_api_constant<
      mp_list<buffer_target>,
#ifdef GL_TEXTURE_BUFFER
      enum_type_c<GL_TEXTURE_BUFFER>>
#else
      enum_type_i>
#endif
      texture_buffer;

    opt_c_api_constant<
      mp_list<buffer_target, program_interface>,
#ifdef GL_TRANSFORM_FEEDBACK_BUFFER
      enum_type_c<GL_TRANSFORM_FEEDBACK_BUFFER>>
#else
      enum_type_i>
#endif
      transform_feedback_buffer;

    opt_c_api_constant<
      mp_list<buffer_target>,
#ifdef GL_UNIFORM_BUFFER
      enum_type_c<GL_UNIFORM_BUFFER>>
#else
      enum_type_i>
#endif
      uniform_buffer;

    opt_c_api_constant<
      mp_list<buffer_usage>,
#ifdef GL_STREAM_DRAW
      enum_type_c<GL_STREAM_DRAW>>
#else
      enum_type_i>
#endif
      stream_draw;

    opt_c_api_constant<
      mp_list<buffer_usage>,
#ifdef GL_STREAM_READ
      enum_type_c<GL_STREAM_READ>>
#else
      enum_type_i>
#endif
      stream_read;

    opt_c_api_constant<
      mp_list<buffer_usage>,
#ifdef GL_STREAM_COPY
      enum_type_c<GL_STREAM_COPY>>
#else
      enum_type_i>
#endif
      stream_copy;

    opt_c_api_constant<
      mp_list<buffer_usage>,
#ifdef GL_STATIC_DRAW
      enum_type_c<GL_STATIC_DRAW>>
#else
      enum_type_i>
#endif
      static_draw;

    opt_c_api_constant<
      mp_list<buffer_usage>,
#ifdef GL_STATIC_READ
      enum_type_c<GL_STATIC_READ>>
#else
      enum_type_i>
#endif
      static_read;

    opt_c_api_constant<
      mp_list<buffer_usage>,
#ifdef GL_STATIC_COPY
      enum_type_c<GL_STATIC_COPY>>
#else
      enum_type_i>
#endif
      static_copy;

    opt_c_api_constant<
      mp_list<buffer_usage>,
#ifdef GL_DYNAMIC_DRAW
      enum_type_c<GL_DYNAMIC_DRAW>>
#else
      enum_type_i>
#endif
      dynamic_draw;

    opt_c_api_constant<
      mp_list<buffer_usage>,
#ifdef GL_DYNAMIC_READ
      enum_type_c<GL_DYNAMIC_READ>>
#else
      enum_type_i>
#endif
      dynamic_read;

    opt_c_api_constant<
      mp_list<buffer_usage>,
#ifdef GL_DYNAMIC_COPY
      enum_type_c<GL_DYNAMIC_COPY>>
#else
      enum_type_i>
#endif
      dynamic_copy;

    opt_c_api_constant<
      mp_list<buffer_map_access_bit>,
#ifdef GL_MAP_READ_BIT
      bitfield_type_c<GL_MAP_READ_BIT>>
#else
      bitfield_type_i>
#endif
      map_read_bit;

    opt_c_api_constant<
      mp_list<buffer_map_access_bit>,
#ifdef GL_MAP_WRITE_BIT
      bitfield_type_c<GL_MAP_WRITE_BIT>>
#else
      bitfield_type_i>
#endif
      map_write_bit;

    opt_c_api_constant<
      mp_list<buffer_map_access_bit>,
#ifdef GL_MAP_PERSISTENT_BIT
      bitfield_type_c<GL_MAP_PERSISTENT_BIT>>
#else
      bitfield_type_i>
#endif
      map_persistent_bit;

    opt_c_api_constant<
      mp_list<buffer_map_access_bit>,
#ifdef GL_MAP_COHERENT_BIT
      bitfield_type_c<GL_MAP_COHERENT_BIT>>
#else
      bitfield_type_i>
#endif
      map_coherent_bit;

    opt_c_api_constant<
      mp_list<program_interface>,
#ifdef GL_UNIFORM
      enum_type_c<GL_UNIFORM>>
#else
      enum_type_i>
#endif
      uniform;

    opt_c_api_constant<
      mp_list<program_interface>,
#ifdef GL_UNIFORM_BLOCK
      enum_type_c<GL_UNIFORM_BLOCK>>
#else
      enum_type_i>
#endif
      uniform_block;

    opt_c_api_constant<
      mp_list<program_interface>,
#ifdef GL_PROGRAM_INPUT
      enum_type_c<GL_PROGRAM_INPUT>>
#else
      enum_type_i>
#endif
      program_input;

    opt_c_api_constant<
      mp_list<program_interface>,
#ifdef GL_PROGRAM_OUTPUT
      enum_type_c<GL_PROGRAM_OUTPUT>>
#else
      enum_type_i>
#endif
      program_output;

    opt_c_api_constant<
      mp_list<program_interface>,
#ifdef GL_VERTEX_SUBROUTINE
      enum_type_c<GL_VERTEX_SUBROUTINE>>
#else
      enum_type_i>
#endif
      vertex_subroutine;

    opt_c_api_constant<
      mp_list<program_interface>,
#ifdef GL_TESS_CONTROL_SUBROUTINE
      enum_type_c<GL_TESS_CONTROL_SUBROUTINE>>
#else
      enum_type_i>
#endif
      tess_control_subroutine;

    opt_c_api_constant<
      mp_list<program_interface>,
#ifdef GL_TESS_EVALUATION_SUBROUTINE
      enum_type_c<GL_TESS_EVALUATION_SUBROUTINE>>
#else
      enum_type_i>
#endif
      tess_evaluation_subroutine;

    opt_c_api_constant<
      mp_list<program_interface>,
#ifdef GL_GEOMETRY_SUBROUTINE
      enum_type_c<GL_GEOMETRY_SUBROUTINE>>
#else
      enum_type_i>
#endif
      geometry_subroutine;

    opt_c_api_constant<
      mp_list<program_interface>,
#ifdef GL_FRAGMENT_SUBROUTINE
      enum_type_c<GL_FRAGMENT_SUBROUTINE>>
#else
      enum_type_i>
#endif
      fragment_subroutine;

    opt_c_api_constant<
      mp_list<program_interface>,
#ifdef GL_COMPUTE_SUBROUTINE
      enum_type_c<GL_COMPUTE_SUBROUTINE>>
#else
      enum_type_i>
#endif
      compute_subroutine;

    opt_c_api_constant<
      mp_list<program_interface>,
#ifdef GL_VERTEX_SUBROUTINE_UNIFORM
      enum_type_c<GL_VERTEX_SUBROUTINE_UNIFORM>>
#else
      enum_type_i>
#endif
      vertex_subroutine_uniform;

    opt_c_api_constant<
      mp_list<program_interface>,
#ifdef GL_TESS_CONTROL_SUBROUTINE_UNIFORM
      enum_type_c<GL_TESS_CONTROL_SUBROUTINE_UNIFORM>>
#else
      enum_type_i>
#endif
      tess_control_subroutine_uniform;

    opt_c_api_constant<
      mp_list<program_interface>,
#ifdef GL_TESS_EVALUATION_SUBROUTINE_UNIFORM
      enum_type_c<GL_TESS_EVALUATION_SUBROUTINE_UNIFORM>>
#else
      enum_type_i>
#endif
      tess_evaluation_subroutine_uniform;

    opt_c_api_constant<
      mp_list<program_interface>,
#ifdef GL_GEOMETRY_SUBROUTINE_UNIFORM
      enum_type_c<GL_GEOMETRY_SUBROUTINE_UNIFORM>>
#else
      enum_type_i>
#endif
      geometry_subroutine_uniform;

    opt_c_api_constant<
      mp_list<program_interface>,
#ifdef GL_FRAGMENT_SUBROUTINE_UNIFORM
      enum_type_c<GL_FRAGMENT_SUBROUTINE_UNIFORM>>
#else
      enum_type_i>
#endif
      fragment_subroutine_uniform;

    opt_c_api_constant<
      mp_list<program_interface>,
#ifdef GL_COMPUTE_SUBROUTINE_UNIFORM
      enum_type_c<GL_COMPUTE_SUBROUTINE_UNIFORM>>
#else
      enum_type_i>
#endif
      compute_subroutine_uniform;

    opt_c_api_constant<
      mp_list<program_interface>,
#ifdef GL_TRANSFORM_FEEDBACK_VARYING
      enum_type_c<GL_TRANSFORM_FEEDBACK_VARYING>>
#else
      enum_type_i>
#endif
      transform_feedback_varying;

    opt_c_api_constant<
      mp_list<program_interface>,
#ifdef GL_BUFFER_VARIABLE
      enum_type_c<GL_BUFFER_VARIABLE>>
#else
      enum_type_i>
#endif
      buffer_variable;

    opt_c_api_constant<
      mp_list<program_interface>,
#ifdef GL_BUFFER_STORAGE_BLOCK
      enum_type_c<GL_BUFFER_STORAGE_BLOCK>>
#else
      enum_type_i>
#endif
      buffer_storage_block;

    opt_c_api_constant<
      mp_list<program_property>,
#ifdef GL_BUFFER_BINDING
      enum_type_c<GL_BUFFER_BINDING>>
#else
      enum_type_i>
#endif
      buffer_binding;

    opt_c_api_constant<
      mp_list<program_property>,
#ifdef GL_ACTIVE_VARIABLES
      enum_type_c<GL_ACTIVE_VARIABLES>>
#else
      enum_type_i>
#endif
      active_variables;

    opt_c_api_constant<
      mp_list<program_property>,
#ifdef GL_NUM_ACTIVE_VARIABLES
      enum_type_c<GL_NUM_ACTIVE_VARIABLES>>
#else
      enum_type_i>
#endif
      num_active_variables;

    opt_c_api_constant<
      mp_list<program_property>,
#ifdef GL_ARRAY_SIZE
      enum_type_c<GL_ARRAY_SIZE>>
#else
      enum_type_i>
#endif
      array_size;

    opt_c_api_constant<
      mp_list<program_property>,
#ifdef GL_ARRAY_STRIDE
      enum_type_c<GL_ARRAY_STRIDE>>
#else
      enum_type_i>
#endif
      array_stride;

    opt_c_api_constant<
      mp_list<program_property>,
#ifdef GL_BLOCK_INDEX
      enum_type_c<GL_BLOCK_INDEX>>
#else
      enum_type_i>
#endif
      block_index;

    opt_c_api_constant<
      mp_list<program_property>,
#ifdef GL_IS_ROW_MAJOR
      enum_type_c<GL_IS_ROW_MAJOR>>
#else
      enum_type_i>
#endif
      is_row_major;

    opt_c_api_constant<
      mp_list<program_property>,
#ifdef GL_MATRIX_STRIDE
      enum_type_c<GL_MATRIX_STRIDE>>
#else
      enum_type_i>
#endif
      matrix_stride;

    opt_c_api_constant<
      mp_list<program_property>,
#ifdef GL_ATOMIC_COUNTER_BUFFER_INDEX
      enum_type_c<GL_ATOMIC_COUNTER_BUFFER_INDEX>>
#else
      enum_type_i>
#endif
      atomic_counter_buffer_index;

    opt_c_api_constant<
      mp_list<program_property>,
#ifdef GL_BUFFER_DATA_SIZE
      enum_type_c<GL_BUFFER_DATA_SIZE>>
#else
      enum_type_i>
#endif
      buffer_data_size;

    opt_c_api_constant<
      mp_list<program_property>,
#ifdef GL_NUM_COMPATIBLE_SUBROUTINES
      enum_type_c<GL_NUM_COMPATIBLE_SUBROUTINES>>
#else
      enum_type_i>
#endif
      num_compatible_subroutines;

    opt_c_api_constant<
      mp_list<program_property>,
#ifdef GL_COMPATIBLE_SUBROUTINES
      enum_type_c<GL_COMPATIBLE_SUBROUTINES>>
#else
      enum_type_i>
#endif
      compatible_subroutines;

    opt_c_api_constant<
      mp_list<program_property>,
#ifdef GL_IS_PER_PATCH
      enum_type_c<GL_IS_PER_PATCH>>
#else
      enum_type_i>
#endif
      is_per_patch;

    opt_c_api_constant<
      mp_list<program_property>,
#ifdef GL_LOCATION
      enum_type_c<GL_LOCATION>>
#else
      enum_type_i>
#endif
      location;

    opt_c_api_constant<
      mp_list<program_property>,
#ifdef GL_LOCATION_COMPONENT
      enum_type_c<GL_LOCATION_COMPONENT>>
#else
      enum_type_i>
#endif
      location_component;

    opt_c_api_constant<
      mp_list<program_property>,
#ifdef GL_LOCATION_INDEX
      enum_type_c<GL_LOCATION_INDEX>>
#else
      enum_type_i>
#endif
      location_index;

    opt_c_api_constant<
      mp_list<program_property>,
#ifdef GL_NAME_LENGTH
      enum_type_c<GL_NAME_LENGTH>>
#else
      enum_type_i>
#endif
      name_length;

    opt_c_api_constant<
      mp_list<program_property>,
#ifdef GL_OFFSET
      enum_type_c<GL_OFFSET>>
#else
      enum_type_i>
#endif
      offset;

    opt_c_api_constant<
      mp_list<program_property>,
#ifdef GL_REFERENCED_BY_VERTEX_SHADER
      enum_type_c<GL_REFERENCED_BY_VERTEX_SHADER>>
#else
      enum_type_i>
#endif
      referenced_by_vertex_shader;

    opt_c_api_constant<
      mp_list<program_property>,
#ifdef GL_REFERENCED_BY_TESS_CONTROL_SHADER
      enum_type_c<GL_REFERENCED_BY_TESS_CONTROL_SHADER>>
#else
      enum_type_i>
#endif
      referenced_by_tess_control_shader;

    opt_c_api_constant<
      mp_list<program_property>,
#ifdef GL_REFERENCED_BY_TESS_EVALUATION_SHADER
      enum_type_c<GL_REFERENCED_BY_TESS_EVALUATION_SHADER>>
#else
      enum_type_i>
#endif
      referenced_by_tess_evaluation_shader;

    opt_c_api_constant<
      mp_list<program_property>,
#ifdef GL_REFERENCED_BY_GEOMETRY_SHADER
      enum_type_c<GL_REFERENCED_BY_GEOMETRY_SHADER>>
#else
      enum_type_i>
#endif
      referenced_by_geometry_shader;

    opt_c_api_constant<
      mp_list<program_property>,
#ifdef GL_REFERENCED_BY_FRAGMENT_SHADER
      enum_type_c<GL_REFERENCED_BY_FRAGMENT_SHADER>>
#else
      enum_type_i>
#endif
      referenced_by_fragment_shader;

    opt_c_api_constant<
      mp_list<program_property>,
#ifdef GL_REFERENCED_BY_COMPUTE_SHADER
      enum_type_c<GL_REFERENCED_BY_COMPUTE_SHADER>>
#else
      enum_type_i>
#endif
      referenced_by_compute_shader;

    opt_c_api_constant<
      mp_list<program_property>,
#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_INDEX
      enum_type_c<GL_TRANSFORM_FEEDBACK_BUFFER_INDEX>>
#else
      enum_type_i>
#endif
      transform_feedback_buffer_index;

    opt_c_api_constant<
      mp_list<program_property>,
#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE
      enum_type_c<GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE>>
#else
      enum_type_i>
#endif
      transform_feedback_buffer_stride;

    opt_c_api_constant<
      mp_list<program_property>,
#ifdef GL_TOP_LEVEL_ARRAY_SIZE
      enum_type_c<GL_TOP_LEVEL_ARRAY_SIZE>>
#else
      enum_type_i>
#endif
      top_level_array_size;

    opt_c_api_constant<
      mp_list<program_property>,
#ifdef GL_TOP_LEVEL_ARRAY_STRIDE
      enum_type_c<GL_TOP_LEVEL_ARRAY_STRIDE>>
#else
      enum_type_i>
#endif
      top_level_array_stride;

    opt_c_api_constant<
      mp_list<program_property>,
#ifdef GL_TYPE
      enum_type_c<GL_TYPE>>
#else
      enum_type_i>
#endif
      type;

    opt_c_api_constant<
      mp_list<capability>,
#ifdef GL_BLEND
      enum_type_c<GL_BLEND>>
#else
      enum_type_i>
#endif
      blend;

    opt_c_api_constant<
      mp_list<capability>,
#ifdef GL_CULL_FACE
      enum_type_c<GL_CULL_FACE>>
#else
      enum_type_i>
#endif
      cull_face;

    opt_c_api_constant<
      mp_list<capability>,
#ifdef GL_DEPTH_CLAMP
      enum_type_c<GL_DEPTH_CLAMP>>
#else
      enum_type_i>
#endif
      depth_clamp;

    opt_c_api_constant<
      mp_list<capability>,
#ifdef GL_DEPTH_TEST
      enum_type_c<GL_DEPTH_TEST>>
#else
      enum_type_i>
#endif
      depth_test;

    opt_c_api_constant<
      mp_list<capability>,
#ifdef GL_SCISSOR_TEST
      enum_type_c<GL_SCISSOR_TEST>>
#else
      enum_type_i>
#endif
      scissor_test;

    opt_c_api_constant<
      mp_list<capability>,
#ifdef GL_STENCIL_TEST
      enum_type_c<GL_STENCIL_TEST>>
#else
      enum_type_i>
#endif
      stencil_test;

    opt_c_api_constant<
      mp_list<capability>,
#ifdef GL_MULTISAMPLE
      enum_type_c<GL_MULTISAMPLE>>
#else
      enum_type_i>
#endif
      multisample;

    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
      enum_type_c<GL_MAX_VERTEX_UNIFORM_BLOCKS>>
#else
      enum_type_i>
#endif
      max_vertex_uniform_blocks;

    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
      enum_type_c<GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS>>
#else
      enum_type_i>
#endif
      max_tess_control_uniform_blocks;

    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
      enum_type_c<GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS>>
#else
      enum_type_i>
#endif
      max_tess_evaluation_uniform_blocks;

    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_MAX_GEOMETRY_UNIFORM_BLOCKS
      enum_type_c<GL_MAX_GEOMETRY_UNIFORM_BLOCKS>>
#else
      enum_type_i>
#endif
      max_geometry_uniform_blocks;

    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_MAX_FRAGMENT_UNIFORM_BLOCKS
      enum_type_c<GL_MAX_FRAGMENT_UNIFORM_BLOCKS>>
#else
      enum_type_i>
#endif
      max_fragment_uniform_blocks;

    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_MAX_COMPUTE_UNIFORM_BLOCKS
      enum_type_c<GL_MAX_COMPUTE_UNIFORM_BLOCKS>>
#else
      enum_type_i>
#endif
      max_compute_uniform_blocks;

    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_MAX_COMBINED_UNIFORM_BLOCKS
      enum_type_c<GL_MAX_COMBINED_UNIFORM_BLOCKS>>
#else
      enum_type_i>
#endif
      max_combined_uniform_blocks;

    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_MAX_UNIFORM_BLOCK_SIZE
      enum_type_c<GL_MAX_UNIFORM_BLOCK_SIZE>>
#else
      enum_type_i>
#endif
      max_uniform_block_size;

    opt_c_api_constant<
      mp_list<string_query>,
#ifdef GL_VENDOR
      enum_type_c<GL_VENDOR>>
#else
      enum_type_i>
#endif
      vendor;

    opt_c_api_constant<
      mp_list<string_query>,
#ifdef GL_RENDERER
      enum_type_c<GL_RENDERER>>
#else
      enum_type_i>
#endif
      renderer;

    opt_c_api_constant<
      mp_list<string_query>,
#ifdef GL_VERSION
      enum_type_c<GL_VERSION>>
#else
      enum_type_i>
#endif
      version;

    opt_c_api_constant<
      mp_list<string_query>,
#ifdef GL_SHADING_LANGUAGE_VERSION
      enum_type_c<GL_SHADING_LANGUAGE_VERSION>>
#else
      enum_type_i>
#endif
      shading_language_version;

    opt_c_api_constant<
      mp_list<string_query>,
#ifdef GL_EXTENSIONS
      enum_type_c<GL_EXTENSIONS>>
#else
      enum_type_i>
#endif
      extensions;

    opt_c_api_constant<
      mp_list<buffer_clear_bit>,
#ifdef GL_COLOR_BUFFER_BIT
      bitfield_type_c<GL_COLOR_BUFFER_BIT>>
#else
      bitfield_type_i>
#endif
      color_buffer_bit;

    opt_c_api_constant<
      mp_list<buffer_clear_bit>,
#ifdef GL_DEPTH_BUFFER_BIT
      bitfield_type_c<GL_DEPTH_BUFFER_BIT>>
#else
      bitfield_type_i>
#endif
      depth_buffer_bit;

    opt_c_api_constant<
      mp_list<buffer_clear_bit>,
#ifdef GL_STENCIL_BUFFER_BIT
      bitfield_type_c<GL_STENCIL_BUFFER_BIT>>
#else
      bitfield_type_i>
#endif
      stencil_buffer_bit;

    opt_c_api_constant<
      mp_list<texture_compare_mode>,
#ifdef GL_NONE
      bitfield_type_c<GL_NONE>>
#else
      bitfield_type_i>
#endif
      none;

    basic_gl_constants(ApiTraits& traits, basic_gl_c_api<ApiTraits>& api)
      : no_error("NO_ERROR", traits, api)
      , invalid_enum("INVALID_ENUM", traits, api)
      , invalid_value("INVALID_VALUE", traits, api)
      , invalid_operation("INVALID_OPERATION", traits, api)
      , invalid_framebuffer_operation(
          "INVALID_FRAMEBUFFER_OPERATION", traits, api)
      , stack_overflow("STACK_OVERFLOW", traits, api)
      , stack_underflow("STACK_UNDERFLOW", traits, api)
      , table_too_large("TABLE_TOO_LARGE", traits, api)
      , context_lost("CONTEXT_LOST", traits, api)
      , out_of_memory("OUT_OF_MEMORY", traits, api)
      , guilty_context_reset("GUILTY_CONTEXT_RESET", traits, api)
      , innocent_context_reset("INNOCENT_CONTEXT_RESET", traits, api)
      , unknown_context_reset("UNKNOWN_CONTEXT_RESET", traits, api)
      , vertex_attrib_array_barrier_bit(
          "VERTEX_ATTRIB_ARRAY_BARRIER_BIT", traits, api)
      , element_array_barrier_bit("ELEMENT_ARRAY_BARRIER_BIT", traits, api)
      , uniform_barrier_bit("UNIFORM_BARRIER_BIT", traits, api)
      , texture_fetch_barrier_bit("TEXTURE_FETCH_BARRIER_BIT", traits, api)
      , shader_image_access_barrier_bit(
          "SHADER_IMAGE_ACCESS_BARRIER_BIT", traits, api)
      , command_barrier_bit("COMMAND_BARRIER_BIT", traits, api)
      , pixel_buffer_barrier_bit("PIXEL_BUFFER_BARRIER_BIT", traits, api)
      , texture_update_barrier_bit("TEXTURE_UPDATE_BARRIER_BIT", traits, api)
      , buffer_update_barrier_bit("BUFFER_UPDATE_BARRIER_BIT", traits, api)
      , client_mapped_buffer_barrier_bit(
          "CLIENT_MAPPED_BUFFER_BARRIER_BIT", traits, api)
      , query_buffer_barrier_bit("QUERY_BUFFER_BARRIER_BIT", traits, api)
      , framebuffer_barrier_bit("FRAMEBUFFER_BARRIER_BIT", traits, api)
      , transform_feedback_barrier_bit(
          "TRANSFORM_FEEDBACK_BARRIER_BIT", traits, api)
      , atomic_counter_barrier_bit("ATOMIC_COUNTER_BARRIER_BIT", traits, api)
      , shader_storage_barrier_bit("SHADER_STORAGE_BARRIER_BIT", traits, api)
      , all_barrier_bits("ALL_BARRIER_BITS", traits, api)
      , vertex_shader("VERTEX_SHADER", traits, api)
      , tess_control_shader("TESS_CONTROL_SHADER", traits, api)
      , tess_evaluation_shader("TESS_EVALUATION_SHADER", traits, api)
      , geometry_shader("GEOMETRY_SHADER", traits, api)
      , fragment_shader("FRAGMENT_SHADER", traits, api)
      , compute_shader("COMPUTE_SHADER", traits, api)
      , array_buffer("ARRAY_BUFFER", traits, api)
      , atomic_counter_buffer("ATOMIC_COUNTER_BUFFER", traits, api)
      , copy_read_buffer("COPY_READ_BUFFER", traits, api)
      , copy_write_buffer("COPY_WRITE_BUFFER", traits, api)
      , dispatch_indirect_buffer("DISPATCH_INDIRECT_BUFFER", traits, api)
      , draw_indirect_buffer("DRAW_INDIRECT_BUFFER", traits, api)
      , element_array_buffer("ELEMENT_ARRAY_BUFFER", traits, api)
      , parameter_buffer("PARAMETER_BUFFER", traits, api)
      , pixel_pack_buffer("PIXEL_PACK_BUFFER", traits, api)
      , pixel_unpack_buffer("PIXEL_UNPACK_BUFFER", traits, api)
      , query_buffer("QUERY_BUFFER", traits, api)
      , shader_storage_buffer("SHADER_STORAGE_BUFFER", traits, api)
      , texture_buffer("TEXTURE_BUFFER", traits, api)
      , transform_feedback_buffer("TRANSFORM_FEEDBACK_BUFFER", traits, api)
      , uniform_buffer("UNIFORM_BUFFER", traits, api)
      , stream_draw("STREAM_DRAW", traits, api)
      , stream_read("STREAM_READ", traits, api)
      , stream_copy("STREAM_COPY", traits, api)
      , static_draw("STATIC_DRAW", traits, api)
      , static_read("STATIC_READ", traits, api)
      , static_copy("STATIC_COPY", traits, api)
      , dynamic_draw("DYNAMIC_DRAW", traits, api)
      , dynamic_read("DYNAMIC_READ", traits, api)
      , dynamic_copy("DYNAMIC_COPY", traits, api)
      , map_read_bit("MAP_READ_BIT", traits, api)
      , map_write_bit("MAP_WRITE_BIT", traits, api)
      , map_persistent_bit("MAP_PERSISTENT_BIT", traits, api)
      , map_coherent_bit("MAP_COHERENT_BIT", traits, api)
      , uniform("UNIFORM", traits, api)
      , uniform_block("UNIFORM_BLOCK", traits, api)
      , program_input("PROGRAM_INPUT", traits, api)
      , program_output("PROGRAM_OUTPUT", traits, api)
      , vertex_subroutine("VERTEX_SUBROUTINE", traits, api)
      , tess_control_subroutine("TESS_CONTROL_SUBROUTINE", traits, api)
      , tess_evaluation_subroutine("TESS_EVALUATION_SUBROUTINE", traits, api)
      , geometry_subroutine("GEOMETRY_SUBROUTINE", traits, api)
      , fragment_subroutine("FRAGMENT_SUBROUTINE", traits, api)
      , compute_subroutine("COMPUTE_SUBROUTINE", traits, api)
      , vertex_subroutine_uniform("VERTEX_SUBROUTINE_UNIFORM", traits, api)
      , tess_control_subroutine_uniform(
          "TESS_CONTROL_SUBROUTINE_UNIFORM", traits, api)
      , tess_evaluation_subroutine_uniform(
          "TESS_EVALUATION_SUBROUTINE_UNIFORM", traits, api)
      , geometry_subroutine_uniform("GEOMETRY_SUBROUTINE_UNIFORM", traits, api)
      , fragment_subroutine_uniform("FRAGMENT_SUBROUTINE_UNIFORM", traits, api)
      , compute_subroutine_uniform("COMPUTE_SUBROUTINE_UNIFORM", traits, api)
      , transform_feedback_varying("GL_TRANSFORM_FEEDBACK_VARYING", traits, api)
      , buffer_variable("BUFFER_VARIABLE", traits, api)
      , buffer_storage_block("BUFFER_STORAGE_BLOCK", traits, api)
      , buffer_binding("BUFFER_BINDING", traits, api)
      , active_variables("ACTIVE_VARIABLES", traits, api)
      , num_active_variables("NUM_ACTIVE_VARIABLES", traits, api)
      , array_size("ARRAY_SIZE", traits, api)
      , array_stride("ARRAY_STRIDE", traits, api)
      , block_index("BLOCK_INDEX", traits, api)
      , is_row_major("IS_ROW_MAJOR", traits, api)
      , matrix_stride("MATRIX_STRIDE", traits, api)
      , atomic_counter_buffer_index("ATOMIC_COUNTER_BUFFER_INDEX", traits, api)
      , buffer_data_size("BUFFER_DATA_SIZE", traits, api)
      , num_compatible_subroutines("NUM_COMPATIBLE_SUBROUTINES", traits, api)
      , compatible_subroutines("COMPATIBLE_SUBROUTINES", traits, api)
      , is_per_patch("IS_PER_PATCH", traits, api)
      , location("LOCATION", traits, api)
      , location_component("LOCATION_COMPONENT", traits, api)
      , location_index("LOCATION_INDEX", traits, api)
      , name_length("NAME_LENGTH", traits, api)
      , offset("OFFSET", traits, api)
      , referenced_by_vertex_shader("REFERENCED_BY_VERTEX_SHADER", traits, api)
      , referenced_by_tess_control_shader(
          "REFERENCED_BY_TESS_CONTROL_SHADER", traits, api)
      , referenced_by_tess_evaluation_shader(
          "REFERENCED_BY_TESS_EVALUATION_SHADER", traits, api)
      , referenced_by_geometry_shader(
          "REFERENCED_BY_GEOMETRY_SHADER", traits, api)
      , referenced_by_fragment_shader(
          "REFERENCED_BY_FRAGMENT_SHADER", traits, api)
      , referenced_by_compute_shader(
          "REFERENCED_BY_COMPUTE_SHADER", traits, api)
      , transform_feedback_buffer_index(
          "TRANSFORM_FEEDBACK_BUFFER_INDEX", traits, api)
      , transform_feedback_buffer_stride(
          "TRANSFORM_FEEDBACK_BUFFER_STRIDE", traits, api)
      , top_level_array_size("TOP_LEVEL_ARRAY_SIZE", traits, api)
      , top_level_array_stride("TOP_LEVEL_ARRAY_STRIDE", traits, api)
      , type("TYPE", traits, api)
      , blend("BLEND", traits, api)
      , cull_face("CULL_FACE", traits, api)
      , depth_clamp("DEPTH_CLAMP", traits, api)
      , depth_test("DEPTH_TEST", traits, api)
      , scissor_test("SCISSOR_TEST", traits, api)
      , stencil_test("STENCIL_TEST", traits, api)
      , multisample("MULTISAMPLE", traits, api)
      , max_vertex_uniform_blocks("MAX_VERTEX_UNIFORM_BLOCKS", traits, api)
      , max_tess_control_uniform_blocks(
          "MAX_TESS_CONTROL_UNIFORM_BLOCKS", traits, api)
      , max_tess_evaluation_uniform_blocks(
          "MAX_TESS_EVALUATION_UNIFORM_BLOCKS", traits, api)
      , max_geometry_uniform_blocks("MAX_GEOMETRY_UNIFORM_BLOCKS", traits, api)
      , max_fragment_uniform_blocks("MAX_FRAGMENT_UNIFORM_BLOCKS", traits, api)
      , max_compute_uniform_blocks("MAX_COMPUTE_UNIFORM_BLOCKS", traits, api)
      , max_combined_uniform_blocks("MAX_COMBINED_UNIFORM_BLOCKS", traits, api)
      , max_uniform_block_size("MAX_UNIFORM_BLOCK_SIZE", traits, api)
      , vendor("VENDOR", traits, api)
      , renderer("RENDERER", traits, api)
      , version("VERSION", traits, api)
      , shading_language_version("SHADING_LANGUAGE_VERSION", traits, api)
      , extensions("EXTENSIONS", traits, api)
      , color_buffer_bit("COLOR_BUFFER_BIT", traits, api)
      , depth_buffer_bit("DEPTH_BUFFER_BIT", traits, api)
      , stencil_buffer_bit("STENCIL_BUFFER_BIT", traits, api)
      , none("NONE", traits, api) {
    }
};
//------------------------------------------------------------------------------
} // namespace oglp
} // namespace eagine

#endif // OGLPLUS_GL_API_CONSTANTS_HPP

