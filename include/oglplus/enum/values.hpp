//  File include/oglplus/enum/values.hpp
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
#ifndef OGLPLUS_GL_ENUM_VALUES_HPP
#define OGLPLUS_GL_ENUM_VALUES_HPP

#include "../utils/mp_list.hpp"
#include "types.hpp"

namespace oglplus {
struct enum_values {

#ifdef GL_ACCUM_ADJACENT_PAIRS_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::path_list_mode_nv>>
      accum_adjacent_pairs_nv = {GL_ACCUM_ADJACENT_PAIRS_NV};
#endif

#ifdef GL_ACTIVE_ATOMIC_COUNTER_BUFFERS
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_parameter>>
      active_atomic_counter_buffers = {GL_ACTIVE_ATOMIC_COUNTER_BUFFERS};
#endif

#ifdef GL_ACTIVE_ATTRIBUTE_MAX_LENGTH
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_parameter>>
      active_attribute_max_length = {GL_ACTIVE_ATTRIBUTE_MAX_LENGTH};
#endif

#ifdef GL_ACTIVE_ATTRIBUTES
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_parameter>>
      active_attributes = {GL_ACTIVE_ATTRIBUTES};
#endif

#ifdef GL_ACTIVE_PROGRAM
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_pipeline_parameter>>
      active_program = {GL_ACTIVE_PROGRAM};
#endif

#ifdef GL_ACTIVE_UNIFORM_MAX_LENGTH
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_parameter>>
      active_uniform_max_length = {GL_ACTIVE_UNIFORM_MAX_LENGTH};
#endif

#ifdef GL_ACTIVE_UNIFORMS
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_parameter>>
      active_uniforms = {GL_ACTIVE_UNIFORMS};
#endif

#ifdef GL_ACTIVE_VARIABLES
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_resource_property>>
      active_variables = {GL_ACTIVE_VARIABLES};
#endif

#ifdef GL_ADJACENT_PAIRS_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::path_list_mode_nv>>
      adjacent_pairs_nv = {GL_ADJACENT_PAIRS_NV};
#endif

#ifdef GL_AFFINE_2D_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::path_transform_type_nv>>
      affine_2d_nv = {GL_AFFINE_2D_NV};
#endif

#ifdef GL_AFFINE_3D_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::path_transform_type_nv>>
      affine_3d_nv = {GL_AFFINE_3D_NV};
#endif

#ifdef GL_ALIASED_LINE_WIDTH_RANGE
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      aliased_line_width_range = {GL_ALIASED_LINE_WIDTH_RANGE};
#endif

#ifdef GL_ALL_BARRIER_BITS
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::memory_barrier_bits>>
      all_barrier_bits = {GL_ALL_BARRIER_BITS};
#endif

#ifdef GL_ALL_SHADER_BITS
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::program_pipeline_stage>>
      all_shader_bits = {GL_ALL_SHADER_BITS};
#endif

#ifdef GL_ALPHA
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::path_color_format_nv, oglplus::texture_swizzle_mode>>
      alpha = {GL_ALPHA};
#endif

#ifdef GL_ALPHA_BIAS
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_transfer_parameter>>
      alpha_bias = {GL_ALPHA_BIAS};
#endif

#ifdef GL_ALPHA_REF_COMMAND_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::command_token_nv>>
      alpha_ref_command_nv = {GL_ALPHA_REF_COMMAND_NV};
#endif

#ifdef GL_ALPHA_SCALE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_transfer_parameter>>
      alpha_scale = {GL_ALPHA_SCALE};
#endif

#ifdef GL_ALREADY_SIGNALED
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::sync_wait_result>>
      already_signaled = {GL_ALREADY_SIGNALED};
#endif

#ifdef GL_ALWAYS
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::compare_function>>
      always = {GL_ALWAYS};
#endif

#ifdef GL_AND
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::color_logic_operation>>
      and_ = {GL_AND};
#endif

#ifdef GL_AND_INVERTED
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::color_logic_operation>>
      and_inverted = {GL_AND_INVERTED};
#endif

#ifdef GL_AND_REVERSE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::color_logic_operation>>
      and_reverse = {GL_AND_REVERSE};
#endif

#ifdef GL_ANY_SAMPLES_PASSED
    static constexpr const enum_value<GLenum, mp_list<oglplus::query_target>>
      any_samples_passed = {GL_ANY_SAMPLES_PASSED};
#endif

#ifdef GL_ANY_SAMPLES_PASSED_CONSERVATIVE
    static constexpr const enum_value<GLenum, mp_list<oglplus::query_target>>
      any_samples_passed_conservative = {GL_ANY_SAMPLES_PASSED_CONSERVATIVE};
#endif

#ifdef GL_ARC_TO_NV
    static constexpr const enum_value<
      GLubyte,
      mp_list<oglplus::path_command_nv>>
      arc_to_nv = {GL_ARC_TO_NV};
#endif

#ifdef GL_ARRAY_BUFFER
    static constexpr const enum_value<GLenum, mp_list<oglplus::buffer_target>>
      array_buffer = {GL_ARRAY_BUFFER};
#endif

#ifdef GL_ARRAY_BUFFER_BINDING
    static constexpr const enum_value<GLenum, mp_list<oglplus::binding_query>>
      array_buffer_binding = {GL_ARRAY_BUFFER_BINDING};
#endif

#ifdef GL_ARRAY_SIZE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_resource_property>>
      array_size = {GL_ARRAY_SIZE};
#endif

#ifdef GL_ARRAY_STRIDE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_resource_property>>
      array_stride = {GL_ARRAY_STRIDE};
#endif

#ifdef GL_ATOMIC_COUNTER_BARRIER_BIT
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::memory_barrier_bits>>
      atomic_counter_barrier_bit = {GL_ATOMIC_COUNTER_BARRIER_BIT};
#endif

#ifdef GL_ATOMIC_COUNTER_BUFFER
    static constexpr const enum_value<
      GLenum,
      mp_list<
        oglplus::buffer_indexed_target,
        oglplus::buffer_target,
        oglplus::program_interface>>
      atomic_counter_buffer = {GL_ATOMIC_COUNTER_BUFFER};
#endif

#ifdef GL_ATOMIC_COUNTER_BUFFER_BINDING
    static constexpr const enum_value<GLenum, mp_list<oglplus::binding_query>>
      atomic_counter_buffer_binding = {GL_ATOMIC_COUNTER_BUFFER_BINDING};
#endif

#ifdef GL_ATOMIC_COUNTER_BUFFER_INDEX
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_resource_property>>
      atomic_counter_buffer_index = {GL_ATOMIC_COUNTER_BUFFER_INDEX};
#endif

#ifdef GL_ATTACHED_SHADERS
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_parameter>>
      attached_shaders = {GL_ATTACHED_SHADERS};
#endif

#ifdef GL_ATTRIBUTE_ADDRESS_COMMAND_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::command_token_nv>>
      attribute_address_command_nv = {GL_ATTRIBUTE_ADDRESS_COMMAND_NV};
#endif

#ifdef GL_AUTO_GENERATE_MIPMAP
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      auto_generate_mipmap = {GL_AUTO_GENERATE_MIPMAP};
#endif

#ifdef GL_BACK
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::color_buffer, oglplus::single_face, oglplus::face>>
      back = {GL_BACK};
#endif

#ifdef GL_BACK_LEFT
    static constexpr const enum_value<GLenum, mp_list<oglplus::color_buffer>>
      back_left = {GL_BACK_LEFT};
#endif

#ifdef GL_BACK_RIGHT
    static constexpr const enum_value<GLenum, mp_list<oglplus::color_buffer>>
      back_right = {GL_BACK_RIGHT};
#endif

#ifdef GL_BEVEL_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::path_join_style_nv>>
      bevel_nv = {GL_BEVEL_NV};
#endif

#ifdef GL_BGR
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_format>>
      bgr = {GL_BGR};
#endif

#ifdef GL_BGR_INTEGER
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_format>>
      bgr_integer = {GL_BGR_INTEGER};
#endif

#ifdef GL_BGRA
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_format>>
      bgra = {GL_BGRA};
#endif

#ifdef GL_BGRA_INTEGER
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_format>>
      bgra_integer = {GL_BGRA_INTEGER};
#endif

#ifdef GL_BLEND
    static constexpr const enum_value<GLenum, mp_list<oglplus::capability>>
      blend = {GL_BLEND};
#endif

#ifdef GL_BLEND_ADVANCED_COHERENT_KHR
    static constexpr const enum_value<GLenum, mp_list<oglplus::capability>>
      blend_advanced_coherent = {GL_BLEND_ADVANCED_COHERENT_KHR};
#endif

#ifdef GL_BLEND_COLOR
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      blend_color = {GL_BLEND_COLOR};
#endif

#ifdef GL_BLEND_COLOR_COMMAND_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::command_token_nv>>
      blend_color_command_nv = {GL_BLEND_COLOR_COMMAND_NV};
#endif

#ifdef GL_BLEND_DST_ALPHA
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      blend_dst_alpha = {GL_BLEND_DST_ALPHA};
#endif

#ifdef GL_BLEND_DST_RGB
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      blend_dst_rgb = {GL_BLEND_DST_RGB};
#endif

#ifdef GL_BLEND_EQUATION_ALPHA
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      blend_equation_alpha = {GL_BLEND_EQUATION_ALPHA};
#endif

#ifdef GL_BLEND_EQUATION_RGB
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      blend_equation_rgb = {GL_BLEND_EQUATION_RGB};
#endif

#ifdef GL_BLEND_SRC_ALPHA
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      blend_src_alpha = {GL_BLEND_SRC_ALPHA};
#endif

#ifdef GL_BLEND_SRC_RGB
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      blend_src_rgb = {GL_BLEND_SRC_RGB};
#endif

#ifdef GL_BLOCK_INDEX
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_resource_property>>
      block_index = {GL_BLOCK_INDEX};
#endif

#ifdef GL_BLUE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::texture_swizzle_mode, oglplus::pixel_data_format>>
      blue = {GL_BLUE};
#endif

#ifdef GL_BLUE_BIAS
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_transfer_parameter>>
      blue_bias = {GL_BLUE_BIAS};
#endif

#ifdef GL_BLUE_INTEGER
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_format>>
      blue_integer = {GL_BLUE_INTEGER};
#endif

#ifdef GL_BLUE_SCALE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_transfer_parameter>>
      blue_scale = {GL_BLUE_SCALE};
#endif

#ifdef GL_BOLD_BIT_NV
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::path_font_style_nv>>
      bold_bit_nv = {GL_BOLD_BIT_NV};
#endif

#ifdef GL_BOOL
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      bool_ = {GL_BOOL};
#endif

#ifdef GL_BOOL_VEC2
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      bool_vec2 = {GL_BOOL_VEC2};
#endif

#ifdef GL_BOOL_VEC3
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      bool_vec3 = {GL_BOOL_VEC3};
#endif

#ifdef GL_BOOL_VEC4
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      bool_vec4 = {GL_BOOL_VEC4};
#endif

#ifdef GL_BOUNDING_BOX_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<
        oglplus::path_stroke_cover_mode_nv,
        oglplus::path_fill_cover_mode_nv>>
      bounding_box_nv = {GL_BOUNDING_BOX_NV};
#endif

#ifdef GL_BOUNDING_BOX_OF_BOUNDING_BOXES_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<
        oglplus::path_stroke_cover_mode_nv,
        oglplus::path_fill_cover_mode_nv>>
      bounding_box_of_bounding_boxes_nv = {
        GL_BOUNDING_BOX_OF_BOUNDING_BOXES_NV};
#endif

#ifdef GL_BUFFER
    static constexpr const enum_value<GLenum, mp_list<oglplus::object_type>>
      buffer = {GL_BUFFER};
#endif

#ifdef GL_BUFFER_ACCESS
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::buffer_parameter>>
      buffer_access = {GL_BUFFER_ACCESS};
#endif

#ifdef GL_BUFFER_ACCESS_FLAGS
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::buffer_parameter>>
      buffer_access_flags = {GL_BUFFER_ACCESS_FLAGS};
#endif

#ifdef GL_BUFFER_BINDING
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_resource_property, oglplus::binding_query>>
      buffer_binding = {GL_BUFFER_BINDING};
#endif

#ifdef GL_BUFFER_DATA_SIZE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_resource_property>>
      buffer_data_size = {GL_BUFFER_DATA_SIZE};
#endif

#ifdef GL_BUFFER_IMMUTABLE_STORAGE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::buffer_parameter>>
      buffer_immutable_storage = {GL_BUFFER_IMMUTABLE_STORAGE};
#endif

#ifdef GL_BUFFER_MAP_LENGTH
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::buffer_parameter>>
      buffer_map_length = {GL_BUFFER_MAP_LENGTH};
#endif

#ifdef GL_BUFFER_MAP_OFFSET
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::buffer_parameter>>
      buffer_map_offset = {GL_BUFFER_MAP_OFFSET};
#endif

#ifdef GL_BUFFER_MAPPED
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::buffer_parameter>>
      buffer_mapped = {GL_BUFFER_MAPPED};
#endif

#ifdef GL_BUFFER_SIZE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::buffer_parameter>>
      buffer_size = {GL_BUFFER_SIZE};
#endif

#ifdef GL_BUFFER_STORAGE_FLAGS
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::buffer_parameter>>
      buffer_storage_flags = {GL_BUFFER_STORAGE_FLAGS};
#endif

#ifdef GL_BUFFER_UPDATE_BARRIER_BIT
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::memory_barrier_bits>>
      buffer_update_barrier_bit = {GL_BUFFER_UPDATE_BARRIER_BIT};
#endif

#ifdef GL_BUFFER_USAGE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::buffer_parameter>>
      buffer_usage = {GL_BUFFER_USAGE};
#endif

#ifdef GL_BUFFER_VARIABLE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_interface>>
      buffer_variable = {GL_BUFFER_VARIABLE};
#endif

#ifdef GL_BYTE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_type, oglplus::data_type>>
      byte_ = {GL_BYTE};
#endif

#ifdef GL_CAVEAT_SUPPORT
    static constexpr const enum_value<GLenum, mp_list<oglplus::support_level>>
      caveat_support = {GL_CAVEAT_SUPPORT};
#endif

#ifdef GL_CCW
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::face_orientation>>
      ccw = {GL_CCW};
#endif

#ifdef GL_CIRCULAR_CCW_ARC_TO_NV
    static constexpr const enum_value<
      GLubyte,
      mp_list<oglplus::path_command_nv>>
      circular_ccw_arc_to_nv = {GL_CIRCULAR_CCW_ARC_TO_NV};
#endif

#ifdef GL_CIRCULAR_CW_ARC_TO_NV
    static constexpr const enum_value<
      GLubyte,
      mp_list<oglplus::path_command_nv>>
      circular_cw_arc_to_nv = {GL_CIRCULAR_CW_ARC_TO_NV};
#endif

#ifdef GL_CIRCULAR_TANGENT_ARC_TO_NV
    static constexpr const enum_value<
      GLubyte,
      mp_list<oglplus::path_command_nv>>
      circular_tangent_arc_to_nv = {GL_CIRCULAR_TANGENT_ARC_TO_NV};
#endif

#ifdef GL_CLAMP_READ_COLOR
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::clamp_color_target>>
      clamp_read_color = {GL_CLAMP_READ_COLOR};
#endif

#ifdef GL_CLAMP_TO_BORDER
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::texture_wrap_mode>>
      clamp_to_border = {GL_CLAMP_TO_BORDER};
#endif

#ifdef GL_CLAMP_TO_EDGE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::texture_wrap_mode>>
      clamp_to_edge = {GL_CLAMP_TO_EDGE};
#endif

#ifdef GL_CLEAR
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::color_logic_operation>>
      clear = {GL_CLEAR};
#endif

#ifdef GL_CLEAR_BUFFER
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      clear_buffer = {GL_CLEAR_BUFFER};
#endif

#ifdef GL_CLEAR_TEXTURE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      clear_texture = {GL_CLEAR_TEXTURE};
#endif

#ifdef GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::memory_barrier_bits>>
      client_mapped_buffer_barrier_bit = {GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT};
#endif

#ifdef GL_CLIENT_STORAGE_BIT
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::buffer_storage_bits>>
      client_storage_bit = {GL_CLIENT_STORAGE_BIT};
#endif

#ifdef GL_CLIP_DISTANCE0
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::indexed_value_base>>
      clip_distance0 = {GL_CLIP_DISTANCE0};
#endif

#ifdef GL_CLIPPING_INPUT_PRIMITIVES_ARB
    static constexpr const enum_value<GLenum, mp_list<oglplus::query_target>>
      clipping_input_primitives = {GL_CLIPPING_INPUT_PRIMITIVES_ARB};
#endif

#ifdef GL_CLIPPING_OUTPUT_PRIMITIVES_ARB
    static constexpr const enum_value<GLenum, mp_list<oglplus::query_target>>
      clipping_output_primitives = {GL_CLIPPING_OUTPUT_PRIMITIVES_ARB};
#endif

#ifdef GL_CLOSE_PATH_NV
    static constexpr const enum_value<
      GLubyte,
      mp_list<oglplus::path_command_nv>>
      close_path_nv = {GL_CLOSE_PATH_NV};
#endif

#ifdef GL_COLOR
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::framebuffer_buffer, oglplus::old_matrix_mode>>
      color = {GL_COLOR};
#endif

#ifdef GL_COLOR_ARRAY
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::client_capability>>
      color_array = {GL_COLOR_ARRAY};
#endif

#ifdef GL_COLOR_ARRAY_ADDRESS_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::unified_array_address_nv>>
      color_array_address_nv = {GL_COLOR_ARRAY_ADDRESS_NV};
#endif

#ifdef GL_COLOR_ATTACHMENT0
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::indexed_value_base>>
      color_attachment0 = {GL_COLOR_ATTACHMENT0};
#endif

#ifdef GL_COLOR_BUFFER_BIT
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::buffer_select_bits>>
      color_buffer_bit = {GL_COLOR_BUFFER_BIT};
#endif

#ifdef GL_COLOR_CLEAR_VALUE
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      color_clear_value = {GL_COLOR_CLEAR_VALUE};
#endif

#ifdef GL_COLOR_COMPONENTS
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      color_components = {GL_COLOR_COMPONENTS};
#endif

#ifdef GL_COLOR_ENCODING
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      color_encoding = {GL_COLOR_ENCODING};
#endif

#ifdef GL_COLOR_LOGIC_OP
    static constexpr const enum_value<GLenum, mp_list<oglplus::capability>>
      color_logic_op = {GL_COLOR_LOGIC_OP};
#endif

#ifdef GL_COLOR_RENDERABLE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      color_renderable = {GL_COLOR_RENDERABLE};
#endif

#ifdef GL_COLOR_WRITEMASK
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      color_writemask = {GL_COLOR_WRITEMASK};
#endif

#ifdef GL_COLORBURN_KHR
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::blend_equation_advanced>>
      colorburn_khr = {GL_COLORBURN_KHR};
#endif

#ifdef GL_COLORDODGE_KHR
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::blend_equation_advanced>>
      colordodge_khr = {GL_COLORDODGE_KHR};
#endif

#ifdef GL_COMMAND_BARRIER_BIT
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::memory_barrier_bits>>
      command_barrier_bit = {GL_COMMAND_BARRIER_BIT};
#endif

#ifdef GL_COMPARE_REF_TO_TEXTURE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::texture_compare_mode>>
      compare_ref_to_texture = {GL_COMPARE_REF_TO_TEXTURE};
#endif

#ifdef GL_COMPATIBLE_SUBROUTINES
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_resource_property>>
      compatible_subroutines = {GL_COMPATIBLE_SUBROUTINES};
#endif

#ifdef GL_COMPILE_STATUS
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::shader_parameter>>
      compile_status = {GL_COMPILE_STATUS};
#endif

#ifdef GL_COMPRESSED_R11_EAC
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_internal_format>>
      compressed_r11_eac = {GL_COMPRESSED_R11_EAC};
#endif

#ifdef GL_COMPRESSED_RED
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_internal_format>>
      compressed_red = {GL_COMPRESSED_RED};
#endif

#ifdef GL_COMPRESSED_RED_RGTC1
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_internal_format>>
      compressed_red_rgtc1 = {GL_COMPRESSED_RED_RGTC1};
#endif

#ifdef GL_COMPRESSED_RG
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_internal_format>>
      compressed_rg = {GL_COMPRESSED_RG};
#endif

#ifdef GL_COMPRESSED_RG11_EAC
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_internal_format>>
      compressed_rg11_eac = {GL_COMPRESSED_RG11_EAC};
#endif

#ifdef GL_COMPRESSED_RG_RGTC2
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_internal_format>>
      compressed_rg_rgtc2 = {GL_COMPRESSED_RG_RGTC2};
#endif

#ifdef GL_COMPRESSED_RGB
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_internal_format>>
      compressed_rgb = {GL_COMPRESSED_RGB};
#endif

#ifdef GL_COMPRESSED_RGB8_ETC2
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_internal_format>>
      compressed_rgb8_etc2 = {GL_COMPRESSED_RGB8_ETC2};
#endif

#ifdef GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_internal_format>>
      compressed_rgb8_punchthrough_alpha1_etc2 = {
        GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2};
#endif

#ifdef GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_internal_format>>
      compressed_rgb_bptc_signed_float = {GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT};
#endif

#ifdef GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_internal_format>>
      compressed_rgb_bptc_unsigned_float = {
        GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT};
#endif

#ifdef GL_COMPRESSED_RGBA
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_internal_format>>
      compressed_rgba = {GL_COMPRESSED_RGBA};
#endif

#ifdef GL_COMPRESSED_RGBA8_ETC2_EAC
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_internal_format>>
      compressed_rgba8_etc2_eac = {GL_COMPRESSED_RGBA8_ETC2_EAC};
#endif

#ifdef GL_COMPRESSED_RGBA_BPTC_UNORM
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_internal_format>>
      compressed_rgba_bptc_unorm = {GL_COMPRESSED_RGBA_BPTC_UNORM};
#endif

#ifdef GL_COMPRESSED_SIGNED_R11_EAC
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_internal_format>>
      compressed_signed_r11_eac = {GL_COMPRESSED_SIGNED_R11_EAC};
#endif

#ifdef GL_COMPRESSED_SIGNED_RED_RGTC1
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_internal_format>>
      compressed_signed_red_rgtc1 = {GL_COMPRESSED_SIGNED_RED_RGTC1};
#endif

#ifdef GL_COMPRESSED_SIGNED_RG11_EAC
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_internal_format>>
      compressed_signed_rg11_eac = {GL_COMPRESSED_SIGNED_RG11_EAC};
#endif

#ifdef GL_COMPRESSED_SIGNED_RG_RGTC2
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_internal_format>>
      compressed_signed_rg_rgtc2 = {GL_COMPRESSED_SIGNED_RG_RGTC2};
#endif

#ifdef GL_COMPRESSED_SRGB
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_internal_format>>
      compressed_srgb = {GL_COMPRESSED_SRGB};
#endif

#ifdef GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_internal_format>>
      compressed_srgb8_alpha8_etc2_eac = {GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC};
#endif

#ifdef GL_COMPRESSED_SRGB8_ETC2
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_internal_format>>
      compressed_srgb8_etc2 = {GL_COMPRESSED_SRGB8_ETC2};
#endif

#ifdef GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_internal_format>>
      compressed_srgb8_punchthrough_alpha1_etc2 = {
        GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2};
#endif

#ifdef GL_COMPRESSED_SRGB_ALPHA
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_internal_format>>
      compressed_srgb_alpha = {GL_COMPRESSED_SRGB_ALPHA};
#endif

#ifdef GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_internal_format>>
      compressed_srgb_alpha_bptc_unorm = {GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM};
#endif

#ifdef GL_COMPRESSED_TEXTURE_FORMATS
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      compressed_texture_formats = {GL_COMPRESSED_TEXTURE_FORMATS};
#endif

#ifdef GL_COMPUTE_SHADER
    static constexpr const enum_value<GLenum, mp_list<oglplus::shader_type>>
      compute_shader = {GL_COMPUTE_SHADER};
#endif

#ifdef GL_COMPUTE_SHADER_BIT
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::program_pipeline_stage>>
      compute_shader_bit = {GL_COMPUTE_SHADER_BIT};
#endif

#ifdef GL_COMPUTE_SHADER_INVOCATIONS_ARB
    static constexpr const enum_value<GLenum, mp_list<oglplus::query_target>>
      compute_shader_invocations = {GL_COMPUTE_SHADER_INVOCATIONS_ARB};
#endif

#ifdef GL_COMPUTE_SUBROUTINE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_interface>>
      compute_subroutine = {GL_COMPUTE_SUBROUTINE};
#endif

#ifdef GL_COMPUTE_SUBROUTINE_UNIFORM
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_interface>>
      compute_subroutine_uniform = {GL_COMPUTE_SUBROUTINE_UNIFORM};
#endif

#ifdef GL_COMPUTE_TEXTURE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      compute_texture = {GL_COMPUTE_TEXTURE};
#endif

#ifdef GL_COMPUTE_WORK_GROUP_SIZE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_parameter>>
      compute_work_group_size = {GL_COMPUTE_WORK_GROUP_SIZE};
#endif

#ifdef GL_CONDITION_SATISFIED
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::sync_wait_result>>
      condition_satisfied = {GL_CONDITION_SATISFIED};
#endif

#ifdef GL_CONSTANT_ALPHA
    static constexpr const enum_value<GLenum, mp_list<oglplus::blend_function>>
      constant_alpha = {GL_CONSTANT_ALPHA};
#endif

#ifdef GL_CONSTANT_COLOR
    static constexpr const enum_value<GLenum, mp_list<oglplus::blend_function>>
      constant_color = {GL_CONSTANT_COLOR};
#endif

#ifdef GL_CONTEXT_COMPATIBILITY_PROFILE_BIT
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::context_profile_bits>>
      context_compatibility_profile_bit = {
        GL_CONTEXT_COMPATIBILITY_PROFILE_BIT};
#endif

#ifdef GL_CONTEXT_CORE_PROFILE_BIT
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::context_profile_bits>>
      context_core_profile_bit = {GL_CONTEXT_CORE_PROFILE_BIT};
#endif

#ifdef GL_CONTEXT_FLAG_DEBUG_BIT
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::context_flag_bits>>
      context_flag_debug_bit = {GL_CONTEXT_FLAG_DEBUG_BIT};
#endif

#ifdef GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::context_flag_bits>>
      context_flag_forward_compatible_bit = {
        GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT};
#endif

#ifdef GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT_ARB
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::context_flag_bits>>
      context_flag_robust_access_bit = {GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT_ARB};
#endif

#ifdef GL_CONTEXT_FLAGS
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      context_flags = {GL_CONTEXT_FLAGS};
#endif

#ifdef GL_CONTEXT_LOST
    static constexpr const enum_value<GLenum, mp_list<oglplus::error_code>>
      context_lost = {GL_CONTEXT_LOST};
#endif

#ifdef GL_CONTEXT_RELEASE_BEHAVIOR_FLUSH
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::context_release_behavior>>
      context_release_behavior_flush = {GL_CONTEXT_RELEASE_BEHAVIOR_FLUSH};
#endif

#ifdef GL_CONVEX_HULL_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<
        oglplus::path_stroke_cover_mode_nv,
        oglplus::path_fill_cover_mode_nv>>
      convex_hull_nv = {GL_CONVEX_HULL_NV};
#endif

#ifdef GL_COPY
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::color_logic_operation>>
      copy = {GL_COPY};
#endif

#ifdef GL_COPY_INVERTED
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::color_logic_operation>>
      copy_inverted = {GL_COPY_INVERTED};
#endif

#ifdef GL_COPY_READ_BUFFER
    static constexpr const enum_value<GLenum, mp_list<oglplus::buffer_target>>
      copy_read_buffer = {GL_COPY_READ_BUFFER};
#endif

#ifdef GL_COPY_READ_BUFFER_BINDING
    static constexpr const enum_value<GLenum, mp_list<oglplus::binding_query>>
      copy_read_buffer_binding = {GL_COPY_READ_BUFFER_BINDING};
#endif

#ifdef GL_COPY_WRITE_BUFFER
    static constexpr const enum_value<GLenum, mp_list<oglplus::buffer_target>>
      copy_write_buffer = {GL_COPY_WRITE_BUFFER};
#endif

#ifdef GL_COPY_WRITE_BUFFER_BINDING
    static constexpr const enum_value<GLenum, mp_list<oglplus::binding_query>>
      copy_write_buffer_binding = {GL_COPY_WRITE_BUFFER_BINDING};
#endif

#ifdef GL_COUNT_DOWN_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::path_fill_mode_nv>>
      count_down_nv = {GL_COUNT_DOWN_NV};
#endif

#ifdef GL_COUNT_UP_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::path_fill_mode_nv>>
      count_up_nv = {GL_COUNT_UP_NV};
#endif

#ifdef GL_CUBIC_CURVE_TO_NV
    static constexpr const enum_value<
      GLubyte,
      mp_list<oglplus::path_command_nv>>
      cubic_curve_to_nv = {GL_CUBIC_CURVE_TO_NV};
#endif

#ifdef GL_CULL_FACE
    static constexpr const enum_value<GLenum, mp_list<oglplus::capability>>
      cull_face = {GL_CULL_FACE};
#endif

#ifdef GL_CURRENT_PROGRAM
    static constexpr const enum_value<GLenum, mp_list<oglplus::binding_query>>
      current_program = {GL_CURRENT_PROGRAM};
#endif

#ifdef GL_CW
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::face_orientation>>
      cw = {GL_CW};
#endif

#ifdef GL_DARKEN_KHR
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::blend_equation_advanced>>
      darken_khr = {GL_DARKEN_KHR};
#endif

#ifdef GL_DEBUG_GROUP_STACK_DEPTH
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      debug_group_stack_depth = {GL_DEBUG_GROUP_STACK_DEPTH};
#endif

#ifdef GL_DEBUG_OUTPUT_SYNCHRONOUS
    static constexpr const enum_value<GLenum, mp_list<oglplus::capability>>
      debug_output_synchronous = {GL_DEBUG_OUTPUT_SYNCHRONOUS};
#endif

#ifdef GL_DEBUG_SEVERITY_HIGH
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::debug_output_severity>>
      debug_severity_high = {GL_DEBUG_SEVERITY_HIGH};
#endif

#ifdef GL_DEBUG_SEVERITY_LOW
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::debug_output_severity>>
      debug_severity_low = {GL_DEBUG_SEVERITY_LOW};
#endif

#ifdef GL_DEBUG_SEVERITY_MEDIUM
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::debug_output_severity>>
      debug_severity_medium = {GL_DEBUG_SEVERITY_MEDIUM};
#endif

#ifdef GL_DEBUG_SEVERITY_NOTIFICATION
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::debug_output_severity>>
      debug_severity_notification = {GL_DEBUG_SEVERITY_NOTIFICATION};
#endif

#ifdef GL_DEBUG_SOURCE_API
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::debug_output_source>>
      debug_source_api = {GL_DEBUG_SOURCE_API};
#endif

#ifdef GL_DEBUG_SOURCE_APPLICATION
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::debug_output_source>>
      debug_source_application = {GL_DEBUG_SOURCE_APPLICATION};
#endif

#ifdef GL_DEBUG_SOURCE_OTHER
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::debug_output_source>>
      debug_source_other = {GL_DEBUG_SOURCE_OTHER};
#endif

#ifdef GL_DEBUG_SOURCE_SHADER_COMPILER
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::debug_output_source>>
      debug_source_shader_compiler = {GL_DEBUG_SOURCE_SHADER_COMPILER};
#endif

#ifdef GL_DEBUG_SOURCE_THIRD_PARTY
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::debug_output_source>>
      debug_source_third_party = {GL_DEBUG_SOURCE_THIRD_PARTY};
#endif

#ifdef GL_DEBUG_SOURCE_WINDOW_SYSTEM
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::debug_output_source>>
      debug_source_window_system = {GL_DEBUG_SOURCE_WINDOW_SYSTEM};
#endif

#ifdef GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::debug_output_type>>
      debug_type_deprecated_behavior = {GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR};
#endif

#ifdef GL_DEBUG_TYPE_ERROR
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::debug_output_type>>
      debug_type_error = {GL_DEBUG_TYPE_ERROR};
#endif

#ifdef GL_DEBUG_TYPE_MARKER
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::debug_output_type>>
      debug_type_marker = {GL_DEBUG_TYPE_MARKER};
#endif

#ifdef GL_DEBUG_TYPE_OTHER
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::debug_output_type>>
      debug_type_other = {GL_DEBUG_TYPE_OTHER};
#endif

#ifdef GL_DEBUG_TYPE_PERFORMANCE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::debug_output_type>>
      debug_type_performance = {GL_DEBUG_TYPE_PERFORMANCE};
#endif

#ifdef GL_DEBUG_TYPE_POP_GROUP
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::debug_output_type>>
      debug_type_pop_group = {GL_DEBUG_TYPE_POP_GROUP};
#endif

#ifdef GL_DEBUG_TYPE_PORTABILITY
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::debug_output_type>>
      debug_type_portability = {GL_DEBUG_TYPE_PORTABILITY};
#endif

#ifdef GL_DEBUG_TYPE_PUSH_GROUP
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::debug_output_type>>
      debug_type_push_group = {GL_DEBUG_TYPE_PUSH_GROUP};
#endif

#ifdef GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::debug_output_type>>
      debug_type_undefined_behavior = {GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR};
#endif

#ifdef GL_DECR
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::stencil_operation>>
      decr = {GL_DECR};
#endif

#ifdef GL_DECR_WRAP
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::stencil_operation>>
      decr_wrap = {GL_DECR_WRAP};
#endif

#ifdef GL_DELETE_STATUS
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_parameter, oglplus::shader_parameter>>
      delete_status = {GL_DELETE_STATUS};
#endif

#ifdef GL_DEPTH
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::framebuffer_buffer>>
      depth = {GL_DEPTH};
#endif

#ifdef GL_DEPTH24_STENCIL8
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_internal_format>>
      depth24_stencil8 = {GL_DEPTH24_STENCIL8};
#endif

#ifdef GL_DEPTH32F_STENCIL8
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_internal_format>>
      depth32f_stencil8 = {GL_DEPTH32F_STENCIL8};
#endif

#ifdef GL_DEPTH_ATTACHMENT
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::framebuffer_other_attachment>>
      depth_attachment = {GL_DEPTH_ATTACHMENT};
#endif

#ifdef GL_DEPTH_BIAS
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_transfer_parameter>>
      depth_bias = {GL_DEPTH_BIAS};
#endif

#ifdef GL_DEPTH_BUFFER_BIT
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::buffer_select_bits>>
      depth_buffer_bit = {GL_DEPTH_BUFFER_BIT};
#endif

#ifdef GL_DEPTH_CLEAR_VALUE
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      depth_clear_value = {GL_DEPTH_CLEAR_VALUE};
#endif

#ifdef GL_DEPTH_COMPONENT
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_format, oglplus::pixel_data_internal_format>>
      depth_component = {GL_DEPTH_COMPONENT};
#endif

#ifdef GL_DEPTH_COMPONENT16
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_internal_format>>
      depth_component16 = {GL_DEPTH_COMPONENT16};
#endif

#ifdef GL_DEPTH_COMPONENT24
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_internal_format>>
      depth_component24 = {GL_DEPTH_COMPONENT24};
#endif

#ifdef GL_DEPTH_COMPONENT32
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_internal_format>>
      depth_component32 = {GL_DEPTH_COMPONENT32};
#endif

#ifdef GL_DEPTH_COMPONENT32F
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_internal_format>>
      depth_component32f = {GL_DEPTH_COMPONENT32F};
#endif

#ifdef GL_DEPTH_COMPONENTS
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      depth_components = {GL_DEPTH_COMPONENTS};
#endif

#ifdef GL_DEPTH_FUNC
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      depth_func = {GL_DEPTH_FUNC};
#endif

#ifdef GL_DEPTH_RANGE
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      depth_range = {GL_DEPTH_RANGE};
#endif

#ifdef GL_DEPTH_RENDERABLE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      depth_renderable = {GL_DEPTH_RENDERABLE};
#endif

#ifdef GL_DEPTH_SCALE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_transfer_parameter>>
      depth_scale = {GL_DEPTH_SCALE};
#endif

#ifdef GL_DEPTH_STENCIL
    static constexpr const enum_value<
      GLenum,
      mp_list<
        oglplus::framebuffer_buffer,
        oglplus::pixel_data_format,
        oglplus::pixel_data_internal_format>>
      depth_stencil = {GL_DEPTH_STENCIL};
#endif

#ifdef GL_DEPTH_STENCIL_ATTACHMENT
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::framebuffer_other_attachment>>
      depth_stencil_attachment = {GL_DEPTH_STENCIL_ATTACHMENT};
#endif

#ifdef GL_DEPTH_STENCIL_TEXTURE_MODE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::texture_parameter>>
      depth_stencil_texture_mode = {GL_DEPTH_STENCIL_TEXTURE_MODE};
#endif

#ifdef GL_DEPTH_TEST
    static constexpr const enum_value<GLenum, mp_list<oglplus::capability>>
      depth_test = {GL_DEPTH_TEST};
#endif

#ifdef GL_DEPTH_WRITEMASK
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      depth_writemask = {GL_DEPTH_WRITEMASK};
#endif

#ifdef GL_DIFFERENCE_KHR
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::blend_equation_advanced>>
      difference_khr = {GL_DIFFERENCE_KHR};
#endif

#ifdef GL_DISPATCH_INDIRECT_BUFFER
    static constexpr const enum_value<GLenum, mp_list<oglplus::buffer_target>>
      dispatch_indirect_buffer = {GL_DISPATCH_INDIRECT_BUFFER};
#endif

#ifdef GL_DISPATCH_INDIRECT_BUFFER_BINDING
    static constexpr const enum_value<GLenum, mp_list<oglplus::binding_query>>
      dispatch_indirect_buffer_binding = {GL_DISPATCH_INDIRECT_BUFFER_BINDING};
#endif

#ifdef GL_DITHER
    static constexpr const enum_value<GLenum, mp_list<oglplus::capability>>
      dither = {GL_DITHER};
#endif

#ifdef GL_DONT_CARE
    static constexpr const enum_value<
      GLenum,
      mp_list<
        oglplus::debug_output_source,
        oglplus::debug_output_type,
        oglplus::debug_output_severity,
        oglplus::hint_option>>
      dont_care = {GL_DONT_CARE};
#endif

#ifdef GL_DOUBLE
    static constexpr const enum_value<
      GLenum,
      mp_list<
        oglplus::sl_data_type,
        oglplus::pixel_data_type,
        oglplus::data_type>>
      double_ = {GL_DOUBLE};
#endif

#ifdef GL_DOUBLE_MAT2
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      double_mat2 = {GL_DOUBLE_MAT2};
#endif

#ifdef GL_DOUBLE_MAT2x3
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      double_mat2x3 = {GL_DOUBLE_MAT2x3};
#endif

#ifdef GL_DOUBLE_MAT2x4
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      double_mat2x4 = {GL_DOUBLE_MAT2x4};
#endif

#ifdef GL_DOUBLE_MAT3
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      double_mat3 = {GL_DOUBLE_MAT3};
#endif

#ifdef GL_DOUBLE_MAT3x2
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      double_mat3x2 = {GL_DOUBLE_MAT3x2};
#endif

#ifdef GL_DOUBLE_MAT3x4
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      double_mat3x4 = {GL_DOUBLE_MAT3x4};
#endif

#ifdef GL_DOUBLE_MAT4
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      double_mat4 = {GL_DOUBLE_MAT4};
#endif

#ifdef GL_DOUBLE_MAT4x2
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      double_mat4x2 = {GL_DOUBLE_MAT4x2};
#endif

#ifdef GL_DOUBLE_MAT4x3
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      double_mat4x3 = {GL_DOUBLE_MAT4x3};
#endif

#ifdef GL_DOUBLE_VEC2
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      double_vec2 = {GL_DOUBLE_VEC2};
#endif

#ifdef GL_DOUBLE_VEC3
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      double_vec3 = {GL_DOUBLE_VEC3};
#endif

#ifdef GL_DOUBLE_VEC4
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      double_vec4 = {GL_DOUBLE_VEC4};
#endif

#ifdef GL_DOUBLEBUFFER
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      doublebuffer = {GL_DOUBLEBUFFER};
#endif

#ifdef GL_DRAW_ARRAYS_COMMAND_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::command_token_nv>>
      draw_arrays_command_nv = {GL_DRAW_ARRAYS_COMMAND_NV};
#endif

#ifdef GL_DRAW_ARRAYS_INSTANCED_COMMAND_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::command_token_nv>>
      draw_arrays_instanced_command_nv = {GL_DRAW_ARRAYS_INSTANCED_COMMAND_NV};
#endif

#ifdef GL_DRAW_ARRAYS_STRIP_COMMAND_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::command_token_nv>>
      draw_arrays_strip_command_nv = {GL_DRAW_ARRAYS_STRIP_COMMAND_NV};
#endif

#ifdef GL_DRAW_BUFFER
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      draw_buffer = {GL_DRAW_BUFFER};
#endif

#ifdef GL_DRAW_BUFFER0
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::indexed_value_base>>
      draw_buffer0 = {GL_DRAW_BUFFER0};
#endif

#ifdef GL_DRAW_ELEMENTS_COMMAND_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::command_token_nv>>
      draw_elements_command_nv = {GL_DRAW_ELEMENTS_COMMAND_NV};
#endif

#ifdef GL_DRAW_ELEMENTS_INSTANCED_COMMAND_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::command_token_nv>>
      draw_elements_instanced_command_nv = {
        GL_DRAW_ELEMENTS_INSTANCED_COMMAND_NV};
#endif

#ifdef GL_DRAW_ELEMENTS_STRIP_COMMAND_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::command_token_nv>>
      draw_elements_strip_command_nv = {GL_DRAW_ELEMENTS_STRIP_COMMAND_NV};
#endif

#ifdef GL_DRAW_FRAMEBUFFER
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::framebuffer_target>>
      draw_framebuffer = {GL_DRAW_FRAMEBUFFER};
#endif

#ifdef GL_DRAW_FRAMEBUFFER_BINDING
    static constexpr const enum_value<GLenum, mp_list<oglplus::binding_query>>
      draw_framebuffer_binding = {GL_DRAW_FRAMEBUFFER_BINDING};
#endif

#ifdef GL_DRAW_INDIRECT_BUFFER
    static constexpr const enum_value<GLenum, mp_list<oglplus::buffer_target>>
      draw_indirect_buffer = {GL_DRAW_INDIRECT_BUFFER};
#endif

#ifdef GL_DRAW_INDIRECT_BUFFER_BINDING
    static constexpr const enum_value<GLenum, mp_list<oglplus::binding_query>>
      draw_indirect_buffer_binding = {GL_DRAW_INDIRECT_BUFFER_BINDING};
#endif

#ifdef GL_DST_ALPHA
    static constexpr const enum_value<GLenum, mp_list<oglplus::blend_function>>
      dst_alpha = {GL_DST_ALPHA};
#endif

#ifdef GL_DST_COLOR
    static constexpr const enum_value<GLenum, mp_list<oglplus::blend_function>>
      dst_color = {GL_DST_COLOR};
#endif

#ifdef GL_DUP_FIRST_CUBIC_CURVE_TO_NV
    static constexpr const enum_value<
      GLubyte,
      mp_list<oglplus::path_command_nv>>
      dup_first_cubic_curve_to_nv = {GL_DUP_FIRST_CUBIC_CURVE_TO_NV};
#endif

#ifdef GL_DUP_LAST_CUBIC_CURVE_TO_NV
    static constexpr const enum_value<
      GLubyte,
      mp_list<oglplus::path_command_nv>>
      dup_last_cubic_curve_to_nv = {GL_DUP_LAST_CUBIC_CURVE_TO_NV};
#endif

#ifdef GL_DYNAMIC_COPY
    static constexpr const enum_value<GLenum, mp_list<oglplus::buffer_usage>>
      dynamic_copy = {GL_DYNAMIC_COPY};
#endif

#ifdef GL_DYNAMIC_DRAW
    static constexpr const enum_value<GLenum, mp_list<oglplus::buffer_usage>>
      dynamic_draw = {GL_DYNAMIC_DRAW};
#endif

#ifdef GL_DYNAMIC_READ
    static constexpr const enum_value<GLenum, mp_list<oglplus::buffer_usage>>
      dynamic_read = {GL_DYNAMIC_READ};
#endif

#ifdef GL_DYNAMIC_STORAGE_BIT
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::buffer_storage_bits>>
      dynamic_storage_bit = {GL_DYNAMIC_STORAGE_BIT};
#endif

#ifdef GL_EDGE_FLAG_ARRAY
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::client_capability>>
      edge_flag_array = {GL_EDGE_FLAG_ARRAY};
#endif

#ifdef GL_EDGE_FLAG_ARRAY_ADDRESS_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::unified_array_address_nv>>
      edge_flag_array_address_nv = {GL_EDGE_FLAG_ARRAY_ADDRESS_NV};
#endif

#ifdef GL_ELEMENT_ADDRESS_COMMAND_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::command_token_nv>>
      element_address_command_nv = {GL_ELEMENT_ADDRESS_COMMAND_NV};
#endif

#ifdef GL_ELEMENT_ARRAY_ADDRESS_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::unified_array_address_nv>>
      element_array_address_nv = {GL_ELEMENT_ARRAY_ADDRESS_NV};
#endif

#ifdef GL_ELEMENT_ARRAY_BARRIER_BIT
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::memory_barrier_bits>>
      element_array_barrier_bit = {GL_ELEMENT_ARRAY_BARRIER_BIT};
#endif

#ifdef GL_ELEMENT_ARRAY_BUFFER
    static constexpr const enum_value<GLenum, mp_list<oglplus::buffer_target>>
      element_array_buffer = {GL_ELEMENT_ARRAY_BUFFER};
#endif

#ifdef GL_ELEMENT_ARRAY_BUFFER_BINDING
    static constexpr const enum_value<GLenum, mp_list<oglplus::binding_query>>
      element_array_buffer_binding = {GL_ELEMENT_ARRAY_BUFFER_BINDING};
#endif

#ifdef GL_ELEMENT_ARRAY_UNIFIED_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::client_capability>>
      element_array_unified_nv = {GL_ELEMENT_ARRAY_UNIFIED_NV};
#endif

#ifdef GL_EQUAL
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::compare_function, oglplus::tess_gen_primitive_spacing>>
      equal = {GL_EQUAL};
#endif

#ifdef GL_EQUIV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::color_logic_operation>>
      equiv = {GL_EQUIV};
#endif

#ifdef GL_EXCLUSION_KHR
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::blend_equation_advanced>>
      exclusion_khr = {GL_EXCLUSION_KHR};
#endif

#ifdef GL_EXTERNAL_VIRTUAL_MEMORY_BUFFER_AMD
    static constexpr const enum_value<GLenum, mp_list<oglplus::buffer_target>>
      external_virtual_memory_buffer = {GL_EXTERNAL_VIRTUAL_MEMORY_BUFFER_AMD};
#endif

#ifdef GL_EYE_LINEAR
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::path_gen_mode_nv>>
      eye_linear = {GL_EYE_LINEAR};
#endif

#ifdef GL_FALSE
    static constexpr const enum_value<GLboolean, mp_list<oglplus::true_false>>
      false_ = {GL_FALSE};
#endif

#ifdef GL_FASTEST
    static constexpr const enum_value<GLenum, mp_list<oglplus::hint_option>>
      fastest = {GL_FASTEST};
#endif

#ifdef GL_FILE_NAME_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::path_font_target_nv>>
      file_name_nv = {GL_FILE_NAME_NV};
#endif

#ifdef GL_FILL
    static constexpr const enum_value<GLenum, mp_list<oglplus::polygon_mode>>
      fill = {GL_FILL};
#endif

#ifdef GL_FILL_RECTANGLE_NV
    static constexpr const enum_value<GLenum, mp_list<oglplus::polygon_mode>>
      fill_rectangle = {GL_FILL_RECTANGLE_NV};
#endif

#ifdef GL_FILTER
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      filter = {GL_FILTER};
#endif

#ifdef GL_FIRST_TO_REST_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::path_list_mode_nv>>
      first_to_rest_nv = {GL_FIRST_TO_REST_NV};
#endif

#ifdef GL_FIRST_VERTEX_CONVENTION
    static constexpr const enum_value<GLenum, mp_list<oglplus::provoke_mode>>
      first_vertex_convention = {GL_FIRST_VERTEX_CONVENTION};
#endif

#ifdef GL_FIXED
    static constexpr const enum_value<GLenum, mp_list<oglplus::data_type>>
      fixed = {GL_FIXED};
#endif

#ifdef GL_FLAT
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::path_cap_style_nv>>
      flat = {GL_FLAT};
#endif

#ifdef GL_FLOAT
    static constexpr const enum_value<
      GLenum,
      mp_list<
        oglplus::sl_data_type,
        oglplus::pixel_data_type,
        oglplus::data_type>>
      float_ = {GL_FLOAT};
#endif

#ifdef GL_FLOAT_32_UNSIGNED_INT_24_8_REV
    static constexpr const enum_value<GLenum, mp_list<oglplus::pixel_data_type>>
      float_32_unsigned_int_24_8_rev = {GL_FLOAT_32_UNSIGNED_INT_24_8_REV};
#endif

#ifdef GL_FLOAT_MAT2
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      float_mat2 = {GL_FLOAT_MAT2};
#endif

#ifdef GL_FLOAT_MAT2x3
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      float_mat2x3 = {GL_FLOAT_MAT2x3};
#endif

#ifdef GL_FLOAT_MAT2x4
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      float_mat2x4 = {GL_FLOAT_MAT2x4};
#endif

#ifdef GL_FLOAT_MAT3
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      float_mat3 = {GL_FLOAT_MAT3};
#endif

#ifdef GL_FLOAT_MAT3x2
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      float_mat3x2 = {GL_FLOAT_MAT3x2};
#endif

#ifdef GL_FLOAT_MAT3x4
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      float_mat3x4 = {GL_FLOAT_MAT3x4};
#endif

#ifdef GL_FLOAT_MAT4
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      float_mat4 = {GL_FLOAT_MAT4};
#endif

#ifdef GL_FLOAT_MAT4x2
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      float_mat4x2 = {GL_FLOAT_MAT4x2};
#endif

#ifdef GL_FLOAT_MAT4x3
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      float_mat4x3 = {GL_FLOAT_MAT4x3};
#endif

#ifdef GL_FLOAT_VEC2
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      float_vec2 = {GL_FLOAT_VEC2};
#endif

#ifdef GL_FLOAT_VEC3
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      float_vec3 = {GL_FLOAT_VEC3};
#endif

#ifdef GL_FLOAT_VEC4
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      float_vec4 = {GL_FLOAT_VEC4};
#endif

#ifdef GL_FOG_COORD_ARRAY
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::client_capability>>
      fog_coord_array = {GL_FOG_COORD_ARRAY};
#endif

#ifdef GL_FOG_COORD_ARRAY_ADDRESS_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::unified_array_address_nv>>
      fog_coord_array_address_nv = {GL_FOG_COORD_ARRAY_ADDRESS_NV};
#endif

#ifdef GL_FONT_ASCENDER_BIT_NV
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::path_metric_query_nv>>
      font_ascender_bit_nv = {GL_FONT_ASCENDER_BIT_NV};
#endif

#ifdef GL_FONT_DESCENDER_BIT_NV
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::path_metric_query_nv>>
      font_descender_bit_nv = {GL_FONT_DESCENDER_BIT_NV};
#endif

#ifdef GL_FONT_HAS_KERNING_BIT_NV
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::path_metric_query_nv>>
      font_has_kerning_bit_nv = {GL_FONT_HAS_KERNING_BIT_NV};
#endif

#ifdef GL_FONT_HEIGHT_BIT_NV
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::path_metric_query_nv>>
      font_height_bit_nv = {GL_FONT_HEIGHT_BIT_NV};
#endif

#ifdef GL_FONT_MAX_ADVANCE_HEIGHT_BIT_NV
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::path_metric_query_nv>>
      font_max_advance_height_bit_nv = {GL_FONT_MAX_ADVANCE_HEIGHT_BIT_NV};
#endif

#ifdef GL_FONT_MAX_ADVANCE_WIDTH_BIT_NV
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::path_metric_query_nv>>
      font_max_advance_width_bit_nv = {GL_FONT_MAX_ADVANCE_WIDTH_BIT_NV};
#endif

#ifdef GL_FONT_UNDERLINE_POSITION_BIT_NV
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::path_metric_query_nv>>
      font_underline_position_bit_nv = {GL_FONT_UNDERLINE_POSITION_BIT_NV};
#endif

#ifdef GL_FONT_UNDERLINE_THICKNESS_BIT_NV
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::path_metric_query_nv>>
      font_underline_thickness_bit_nv = {GL_FONT_UNDERLINE_THICKNESS_BIT_NV};
#endif

#ifdef GL_FONT_UNITS_PER_EM_BIT_NV
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::path_metric_query_nv>>
      font_units_per_em_bit_nv = {GL_FONT_UNITS_PER_EM_BIT_NV};
#endif

#ifdef GL_FONT_X_MAX_BOUNDS_BIT_NV
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::path_metric_query_nv>>
      font_x_max_bounds_bit_nv = {GL_FONT_X_MAX_BOUNDS_BIT_NV};
#endif

#ifdef GL_FONT_X_MIN_BOUNDS_BIT_NV
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::path_metric_query_nv>>
      font_x_min_bounds_bit_nv = {GL_FONT_X_MIN_BOUNDS_BIT_NV};
#endif

#ifdef GL_FONT_Y_MAX_BOUNDS_BIT_NV
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::path_metric_query_nv>>
      font_y_max_bounds_bit_nv = {GL_FONT_Y_MAX_BOUNDS_BIT_NV};
#endif

#ifdef GL_FONT_Y_MIN_BOUNDS_BIT_NV
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::path_metric_query_nv>>
      font_y_min_bounds_bit_nv = {GL_FONT_Y_MIN_BOUNDS_BIT_NV};
#endif

#ifdef GL_FRACTIONAL_EVEN
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::tess_gen_primitive_spacing>>
      fractional_even = {GL_FRACTIONAL_EVEN};
#endif

#ifdef GL_FRACTIONAL_ODD
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::tess_gen_primitive_spacing>>
      fractional_odd = {GL_FRACTIONAL_ODD};
#endif

#ifdef GL_FRAGMENT_COVERAGE_TO_COLOR_NV
    static constexpr const enum_value<GLenum, mp_list<oglplus::capability>>
      fragment_coverage_to_color = {GL_FRAGMENT_COVERAGE_TO_COLOR_NV};
#endif

#ifdef GL_FRAGMENT_SHADER
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::shader_type, oglplus::program_pipeline_parameter>>
      fragment_shader = {GL_FRAGMENT_SHADER};
#endif

#ifdef GL_FRAGMENT_SHADER_BIT
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::program_pipeline_stage>>
      fragment_shader_bit = {GL_FRAGMENT_SHADER_BIT};
#endif

#ifdef GL_FRAGMENT_SHADER_DERIVATIVE_HINT
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::hint_target, oglplus::numeric_query>>
      fragment_shader_derivative_hint = {GL_FRAGMENT_SHADER_DERIVATIVE_HINT};
#endif

#ifdef GL_FRAGMENT_SHADER_INVOCATIONS_ARB
    static constexpr const enum_value<GLenum, mp_list<oglplus::query_target>>
      fragment_shader_invocations = {GL_FRAGMENT_SHADER_INVOCATIONS_ARB};
#endif

#ifdef GL_FRAGMENT_SUBROUTINE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_interface>>
      fragment_subroutine = {GL_FRAGMENT_SUBROUTINE};
#endif

#ifdef GL_FRAGMENT_SUBROUTINE_UNIFORM
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_interface>>
      fragment_subroutine_uniform = {GL_FRAGMENT_SUBROUTINE_UNIFORM};
#endif

#ifdef GL_FRAGMENT_TEXTURE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      fragment_texture = {GL_FRAGMENT_TEXTURE};
#endif

#ifdef GL_FRAMEBUFFER
    static constexpr const enum_value<GLenum, mp_list<oglplus::object_type>>
      framebuffer = {GL_FRAMEBUFFER};
#endif

#ifdef GL_FRAMEBUFFER_BARRIER_BIT
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::memory_barrier_bits>>
      framebuffer_barrier_bit = {GL_FRAMEBUFFER_BARRIER_BIT};
#endif

#ifdef GL_FRAMEBUFFER_BLEND
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      framebuffer_blend = {GL_FRAMEBUFFER_BLEND};
#endif

#ifdef GL_FRAMEBUFFER_COMPLETE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::framebuffer_status>>
      framebuffer_complete = {GL_FRAMEBUFFER_COMPLETE};
#endif

#ifdef GL_FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::framebuffer_parameter>>
      framebuffer_default_fixed_sample_locations = {
        GL_FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS};
#endif

#ifdef GL_FRAMEBUFFER_DEFAULT_HEIGHT
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::framebuffer_parameter>>
      framebuffer_default_height = {GL_FRAMEBUFFER_DEFAULT_HEIGHT};
#endif

#ifdef GL_FRAMEBUFFER_DEFAULT_LAYERS
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::framebuffer_parameter>>
      framebuffer_default_layers = {GL_FRAMEBUFFER_DEFAULT_LAYERS};
#endif

#ifdef GL_FRAMEBUFFER_DEFAULT_SAMPLES
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::framebuffer_parameter>>
      framebuffer_default_samples = {GL_FRAMEBUFFER_DEFAULT_SAMPLES};
#endif

#ifdef GL_FRAMEBUFFER_DEFAULT_WIDTH
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::framebuffer_parameter>>
      framebuffer_default_width = {GL_FRAMEBUFFER_DEFAULT_WIDTH};
#endif

#ifdef GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::framebuffer_status>>
      framebuffer_incomplete_attachment = {
        GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT};
#endif

#ifdef GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::framebuffer_status>>
      framebuffer_incomplete_layer_targets = {
        GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS};
#endif

#ifdef GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::framebuffer_status>>
      framebuffer_incomplete_missing_attachment = {
        GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT};
#endif

#ifdef GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::framebuffer_status>>
      framebuffer_incomplete_multisample = {
        GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE};
#endif

#ifdef GL_FRAMEBUFFER_RENDERABLE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      framebuffer_renderable = {GL_FRAMEBUFFER_RENDERABLE};
#endif

#ifdef GL_FRAMEBUFFER_RENDERABLE_LAYERED
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      framebuffer_renderable_layered = {GL_FRAMEBUFFER_RENDERABLE_LAYERED};
#endif

#ifdef GL_FRAMEBUFFER_SRGB
    static constexpr const enum_value<GLenum, mp_list<oglplus::capability>>
      framebuffer_srgb = {GL_FRAMEBUFFER_SRGB};
#endif

#ifdef GL_FRAMEBUFFER_UNDEFINED
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::framebuffer_status>>
      framebuffer_undefined = {GL_FRAMEBUFFER_UNDEFINED};
#endif

#ifdef GL_FRAMEBUFFER_UNSUPPORTED
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::framebuffer_status>>
      framebuffer_unsupported = {GL_FRAMEBUFFER_UNSUPPORTED};
#endif

#ifdef GL_FRONT
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::color_buffer, oglplus::single_face, oglplus::face>>
      front = {GL_FRONT};
#endif

#ifdef GL_FRONT_AND_BACK
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::color_buffer, oglplus::face>>
      front_and_back = {GL_FRONT_AND_BACK};
#endif

#ifdef GL_FRONT_FACE_COMMAND_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::command_token_nv>>
      front_face_command_nv = {GL_FRONT_FACE_COMMAND_NV};
#endif

#ifdef GL_FRONT_LEFT
    static constexpr const enum_value<GLenum, mp_list<oglplus::color_buffer>>
      front_left = {GL_FRONT_LEFT};
#endif

#ifdef GL_FRONT_RIGHT
    static constexpr const enum_value<GLenum, mp_list<oglplus::color_buffer>>
      front_right = {GL_FRONT_RIGHT};
#endif

#ifdef GL_FULL_SUPPORT
    static constexpr const enum_value<GLenum, mp_list<oglplus::support_level>>
      full_support = {GL_FULL_SUPPORT};
#endif

#ifdef GL_FUNC_ADD
    static constexpr const enum_value<GLenum, mp_list<oglplus::blend_equation>>
      func_add = {GL_FUNC_ADD};
#endif

#ifdef GL_FUNC_REVERSE_SUBTRACT
    static constexpr const enum_value<GLenum, mp_list<oglplus::blend_equation>>
      func_reverse_subtract = {GL_FUNC_REVERSE_SUBTRACT};
#endif

#ifdef GL_FUNC_SUBTRACT
    static constexpr const enum_value<GLenum, mp_list<oglplus::blend_equation>>
      func_subtract = {GL_FUNC_SUBTRACT};
#endif

#ifdef GL_GENERATE_MIPMAP
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      generate_mipmap = {GL_GENERATE_MIPMAP};
#endif

#ifdef GL_GEOMETRY_INPUT_TYPE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_parameter>>
      geometry_input_type = {GL_GEOMETRY_INPUT_TYPE};
#endif

#ifdef GL_GEOMETRY_OUTPUT_TYPE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_parameter>>
      geometry_output_type = {GL_GEOMETRY_OUTPUT_TYPE};
#endif

#ifdef GL_GEOMETRY_SHADER
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::shader_type, oglplus::program_pipeline_parameter>>
      geometry_shader = {GL_GEOMETRY_SHADER};
#endif

#ifdef GL_GEOMETRY_SHADER_BIT
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::program_pipeline_stage>>
      geometry_shader_bit = {GL_GEOMETRY_SHADER_BIT};
#endif

#ifdef GL_GEOMETRY_SHADER_INVOCATIONS
    static constexpr const enum_value<GLenum, mp_list<oglplus::query_target>>
      geometry_shader_invocations = {GL_GEOMETRY_SHADER_INVOCATIONS};
#endif

#ifdef GL_GEOMETRY_SHADER_PRIMITIVES_EMITTED_ARB
    static constexpr const enum_value<GLenum, mp_list<oglplus::query_target>>
      geometry_shader_primitives_emitted = {
        GL_GEOMETRY_SHADER_PRIMITIVES_EMITTED_ARB};
#endif

#ifdef GL_GEOMETRY_SUBROUTINE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_interface>>
      geometry_subroutine = {GL_GEOMETRY_SUBROUTINE};
#endif

#ifdef GL_GEOMETRY_SUBROUTINE_UNIFORM
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_interface>>
      geometry_subroutine_uniform = {GL_GEOMETRY_SUBROUTINE_UNIFORM};
#endif

#ifdef GL_GEOMETRY_TEXTURE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      geometry_texture = {GL_GEOMETRY_TEXTURE};
#endif

#ifdef GL_GEOMETRY_VERTICES_OUT
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_parameter>>
      geometry_vertices_out = {GL_GEOMETRY_VERTICES_OUT};
#endif

#ifdef GL_GEQUAL
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::compare_function>>
      gequal = {GL_GEQUAL};
#endif

#ifdef GL_GET_TEXTURE_IMAGE_FORMAT
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      get_texture_image_format = {GL_GET_TEXTURE_IMAGE_FORMAT};
#endif

#ifdef GL_GET_TEXTURE_IMAGE_TYPE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      get_texture_image_type = {GL_GET_TEXTURE_IMAGE_TYPE};
#endif

#ifdef GL_GLYPH_HAS_KERNING_BIT_NV
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::path_metric_query_nv>>
      glyph_has_kerning_bit_nv = {GL_GLYPH_HAS_KERNING_BIT_NV};
#endif

#ifdef GL_GLYPH_HEIGHT_BIT_NV
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::path_metric_query_nv>>
      glyph_height_bit_nv = {GL_GLYPH_HEIGHT_BIT_NV};
#endif

#ifdef GL_GLYPH_HORIZONTAL_BEARING_ADVANCE_BIT_NV
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::path_metric_query_nv>>
      glyph_horizontal_bearing_advance_bit_nv = {
        GL_GLYPH_HORIZONTAL_BEARING_ADVANCE_BIT_NV};
#endif

#ifdef GL_GLYPH_HORIZONTAL_BEARING_X_BIT_NV
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::path_metric_query_nv>>
      glyph_horizontal_bearing_x_bit_nv = {
        GL_GLYPH_HORIZONTAL_BEARING_X_BIT_NV};
#endif

#ifdef GL_GLYPH_HORIZONTAL_BEARING_Y_BIT_NV
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::path_metric_query_nv>>
      glyph_horizontal_bearing_y_bit_nv = {
        GL_GLYPH_HORIZONTAL_BEARING_Y_BIT_NV};
#endif

#ifdef GL_GLYPH_VERTICAL_BEARING_ADVANCE_BIT_NV
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::path_metric_query_nv>>
      glyph_vertical_bearing_advance_bit_nv = {
        GL_GLYPH_VERTICAL_BEARING_ADVANCE_BIT_NV};
#endif

#ifdef GL_GLYPH_VERTICAL_BEARING_X_BIT_NV
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::path_metric_query_nv>>
      glyph_vertical_bearing_x_bit_nv = {GL_GLYPH_VERTICAL_BEARING_X_BIT_NV};
#endif

#ifdef GL_GLYPH_VERTICAL_BEARING_Y_BIT_NV
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::path_metric_query_nv>>
      glyph_vertical_bearing_y_bit_nv = {GL_GLYPH_VERTICAL_BEARING_Y_BIT_NV};
#endif

#ifdef GL_GLYPH_WIDTH_BIT_NV
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::path_metric_query_nv>>
      glyph_width_bit_nv = {GL_GLYPH_WIDTH_BIT_NV};
#endif

#ifdef GL_GREATER
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::compare_function>>
      greater = {GL_GREATER};
#endif

#ifdef GL_GREEN
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::texture_swizzle_mode, oglplus::pixel_data_format>>
      green = {GL_GREEN};
#endif

#ifdef GL_GREEN_BIAS
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_transfer_parameter>>
      green_bias = {GL_GREEN_BIAS};
#endif

#ifdef GL_GREEN_INTEGER
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_format>>
      green_integer = {GL_GREEN_INTEGER};
#endif

#ifdef GL_GREEN_SCALE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_transfer_parameter>>
      green_scale = {GL_GREEN_SCALE};
#endif

#ifdef GL_GUILTY_CONTEXT_RESET
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::graphics_reset_status>>
      guilty_context_reset = {GL_GUILTY_CONTEXT_RESET};
#endif

#ifdef GL_HALF_FLOAT
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_type, oglplus::data_type>>
      half_float = {GL_HALF_FLOAT};
#endif

#ifdef GL_HARDLIGHT_KHR
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::blend_equation_advanced>>
      hardlight_khr = {GL_HARDLIGHT_KHR};
#endif

#ifdef GL_HIGH_FLOAT
    static constexpr const enum_value<GLenum, mp_list<oglplus::precision_type>>
      high_float = {GL_HIGH_FLOAT};
#endif

#ifdef GL_HIGH_INT
    static constexpr const enum_value<GLenum, mp_list<oglplus::precision_type>>
      high_int = {GL_HIGH_INT};
#endif

#ifdef GL_HORIZONTAL_LINE_TO_NV
    static constexpr const enum_value<
      GLubyte,
      mp_list<oglplus::path_command_nv>>
      horizontal_line_to_nv = {GL_HORIZONTAL_LINE_TO_NV};
#endif

#ifdef GL_HSL_COLOR_KHR
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::blend_equation_advanced>>
      hsl_color_khr = {GL_HSL_COLOR_KHR};
#endif

#ifdef GL_HSL_HUE_KHR
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::blend_equation_advanced>>
      hsl_hue_khr = {GL_HSL_HUE_KHR};
#endif

#ifdef GL_HSL_LUMINOSITY_KHR
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::blend_equation_advanced>>
      hsl_luminosity_khr = {GL_HSL_LUMINOSITY_KHR};
#endif

#ifdef GL_HSL_SATURATION_KHR
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::blend_equation_advanced>>
      hsl_saturation_khr = {GL_HSL_SATURATION_KHR};
#endif

#ifdef GL_IMAGE_1D
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      image_1d = {GL_IMAGE_1D};
#endif

#ifdef GL_IMAGE_1D_ARRAY
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      image_1d_array = {GL_IMAGE_1D_ARRAY};
#endif

#ifdef GL_IMAGE_2D
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      image_2d = {GL_IMAGE_2D};
#endif

#ifdef GL_IMAGE_2D_ARRAY
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      image_2d_array = {GL_IMAGE_2D_ARRAY};
#endif

#ifdef GL_IMAGE_2D_MULTISAMPLE
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      image_2d_multisample = {GL_IMAGE_2D_MULTISAMPLE};
#endif

#ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      image_2d_multisample_array = {GL_IMAGE_2D_MULTISAMPLE_ARRAY};
#endif

#ifdef GL_IMAGE_2D_RECT
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      image_2d_rect = {GL_IMAGE_2D_RECT};
#endif

#ifdef GL_IMAGE_3D
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      image_3d = {GL_IMAGE_3D};
#endif

#ifdef GL_IMAGE_BUFFER
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      image_buffer = {GL_IMAGE_BUFFER};
#endif

#ifdef GL_IMAGE_CLASS_10_10_10_2
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::image_compatibility_class>>
      image_class_10_10_10_2 = {GL_IMAGE_CLASS_10_10_10_2};
#endif

#ifdef GL_IMAGE_CLASS_11_11_10
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::image_compatibility_class>>
      image_class_11_11_10 = {GL_IMAGE_CLASS_11_11_10};
#endif

#ifdef GL_IMAGE_CLASS_1_X_16
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::image_compatibility_class>>
      image_class_1_x_16 = {GL_IMAGE_CLASS_1_X_16};
#endif

#ifdef GL_IMAGE_CLASS_1_X_32
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::image_compatibility_class>>
      image_class_1_x_32 = {GL_IMAGE_CLASS_1_X_32};
#endif

#ifdef GL_IMAGE_CLASS_1_X_8
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::image_compatibility_class>>
      image_class_1_x_8 = {GL_IMAGE_CLASS_1_X_8};
#endif

#ifdef GL_IMAGE_CLASS_2_X_16
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::image_compatibility_class>>
      image_class_2_x_16 = {GL_IMAGE_CLASS_2_X_16};
#endif

#ifdef GL_IMAGE_CLASS_2_X_32
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::image_compatibility_class>>
      image_class_2_x_32 = {GL_IMAGE_CLASS_2_X_32};
#endif

#ifdef GL_IMAGE_CLASS_2_X_8
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::image_compatibility_class>>
      image_class_2_x_8 = {GL_IMAGE_CLASS_2_X_8};
#endif

#ifdef GL_IMAGE_CLASS_4_X_16
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::image_compatibility_class>>
      image_class_4_x_16 = {GL_IMAGE_CLASS_4_X_16};
#endif

#ifdef GL_IMAGE_CLASS_4_X_32
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::image_compatibility_class>>
      image_class_4_x_32 = {GL_IMAGE_CLASS_4_X_32};
#endif

#ifdef GL_IMAGE_CLASS_4_X_8
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::image_compatibility_class>>
      image_class_4_x_8 = {GL_IMAGE_CLASS_4_X_8};
#endif

#ifdef GL_IMAGE_COMPATIBILITY_CLASS
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      image_compatibility_class = {GL_IMAGE_COMPATIBILITY_CLASS};
#endif

#ifdef GL_IMAGE_CUBE
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      image_cube = {GL_IMAGE_CUBE};
#endif

#ifdef GL_IMAGE_FORMAT_COMPATIBILITY_TYPE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::texture_parameter, oglplus::internal_format_parameter>>
      image_format_compatibility_type = {GL_IMAGE_FORMAT_COMPATIBILITY_TYPE};
#endif

#ifdef GL_IMAGE_PIXEL_FORMAT
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      image_pixel_format = {GL_IMAGE_PIXEL_FORMAT};
#endif

#ifdef GL_IMAGE_PIXEL_TYPE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      image_pixel_type = {GL_IMAGE_PIXEL_TYPE};
#endif

#ifdef GL_IMAGE_TEXEL_SIZE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      image_texel_size = {GL_IMAGE_TEXEL_SIZE};
#endif

#ifdef GL_IMPLEMENTATION_COLOR_READ_FORMAT
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      implementation_color_read_format = {GL_IMPLEMENTATION_COLOR_READ_FORMAT};
#endif

#ifdef GL_IMPLEMENTATION_COLOR_READ_TYPE
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      implementation_color_read_type = {GL_IMPLEMENTATION_COLOR_READ_TYPE};
#endif

#ifdef GL_INCR
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::stencil_operation>>
      incr = {GL_INCR};
#endif

#ifdef GL_INCR_WRAP
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::stencil_operation>>
      incr_wrap = {GL_INCR_WRAP};
#endif

#ifdef GL_INDEX_ARRAY
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::client_capability>>
      index_array = {GL_INDEX_ARRAY};
#endif

#ifdef GL_INDEX_ARRAY_ADDRESS_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::unified_array_address_nv>>
      index_array_address_nv = {GL_INDEX_ARRAY_ADDRESS_NV};
#endif

#ifdef GL_INDEX_OFFSET
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_transfer_parameter>>
      index_offset = {GL_INDEX_OFFSET};
#endif

#ifdef GL_INDEX_SHIFT
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_transfer_parameter>>
      index_shift = {GL_INDEX_SHIFT};
#endif

#ifdef GL_INFO_LOG_LENGTH
    static constexpr const enum_value<
      GLenum,
      mp_list<
        oglplus::shader_parameter,
        oglplus::program_parameter,
        oglplus::program_pipeline_parameter>>
      info_log_length = {GL_INFO_LOG_LENGTH};
#endif

#ifdef GL_INNOCENT_CONTEXT_RESET
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::graphics_reset_status>>
      innocent_context_reset = {GL_INNOCENT_CONTEXT_RESET};
#endif

#ifdef GL_INT
    static constexpr const enum_value<
      GLenum,
      mp_list<
        oglplus::sl_data_type,
        oglplus::pixel_data_type,
        oglplus::data_type>>
      int_ = {GL_INT};
#endif

#ifdef GL_INT_IMAGE_1D
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      int_image_1d = {GL_INT_IMAGE_1D};
#endif

#ifdef GL_INT_IMAGE_1D_ARRAY
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      int_image_1d_array = {GL_INT_IMAGE_1D_ARRAY};
#endif

#ifdef GL_INT_IMAGE_2D
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      int_image_2d = {GL_INT_IMAGE_2D};
#endif

#ifdef GL_INT_IMAGE_2D_ARRAY
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      int_image_2d_array = {GL_INT_IMAGE_2D_ARRAY};
#endif

#ifdef GL_INT_IMAGE_2D_MULTISAMPLE
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      int_image_2d_multisample = {GL_INT_IMAGE_2D_MULTISAMPLE};
#endif

#ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      int_image_2d_multisample_array = {GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY};
#endif

#ifdef GL_INT_IMAGE_2D_RECT
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      int_image_2d_rect = {GL_INT_IMAGE_2D_RECT};
#endif

#ifdef GL_INT_IMAGE_3D
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      int_image_3d = {GL_INT_IMAGE_3D};
#endif

#ifdef GL_INT_IMAGE_BUFFER
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      int_image_buffer = {GL_INT_IMAGE_BUFFER};
#endif

#ifdef GL_INT_IMAGE_CUBE
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      int_image_cube = {GL_INT_IMAGE_CUBE};
#endif

#ifdef GL_INT_SAMPLER_1D
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      int_sampler_1d = {GL_INT_SAMPLER_1D};
#endif

#ifdef GL_INT_SAMPLER_1D_ARRAY
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      int_sampler_1d_array = {GL_INT_SAMPLER_1D_ARRAY};
#endif

#ifdef GL_INT_SAMPLER_2D
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      int_sampler_2d = {GL_INT_SAMPLER_2D};
#endif

#ifdef GL_INT_SAMPLER_2D_ARRAY
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      int_sampler_2d_array = {GL_INT_SAMPLER_2D_ARRAY};
#endif

#ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      int_sampler_2d_multisample = {GL_INT_SAMPLER_2D_MULTISAMPLE};
#endif

#ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      int_sampler_2d_multisample_array = {GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY};
#endif

#ifdef GL_INT_SAMPLER_2D_RECT
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      int_sampler_2d_rect = {GL_INT_SAMPLER_2D_RECT};
#endif

#ifdef GL_INT_SAMPLER_3D
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      int_sampler_3d = {GL_INT_SAMPLER_3D};
#endif

#ifdef GL_INT_SAMPLER_BUFFER
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      int_sampler_buffer = {GL_INT_SAMPLER_BUFFER};
#endif

#ifdef GL_INT_SAMPLER_CUBE
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      int_sampler_cube = {GL_INT_SAMPLER_CUBE};
#endif

#ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      int_sampler_cube_map_array = {GL_INT_SAMPLER_CUBE_MAP_ARRAY};
#endif

#ifdef GL_INT_VEC2
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      int_vec2 = {GL_INT_VEC2};
#endif

#ifdef GL_INT_VEC3
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      int_vec3 = {GL_INT_VEC3};
#endif

#ifdef GL_INT_VEC4
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      int_vec4 = {GL_INT_VEC4};
#endif

#ifdef GL_INTENSITY
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::path_color_format_nv>>
      intensity = {GL_INTENSITY};
#endif

#ifdef GL_INTERLEAVED_ATTRIBS
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::transform_feedback_mode>>
      interleaved_attribs = {GL_INTERLEAVED_ATTRIBS};
#endif

#ifdef GL_INTERNALFORMAT_ALPHA_SIZE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      internalformat_alpha_size = {GL_INTERNALFORMAT_ALPHA_SIZE};
#endif

#ifdef GL_INTERNALFORMAT_ALPHA_TYPE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      internalformat_alpha_type = {GL_INTERNALFORMAT_ALPHA_TYPE};
#endif

#ifdef GL_INTERNALFORMAT_BLUE_SIZE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      internalformat_blue_size = {GL_INTERNALFORMAT_BLUE_SIZE};
#endif

#ifdef GL_INTERNALFORMAT_BLUE_TYPE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      internalformat_blue_type = {GL_INTERNALFORMAT_BLUE_TYPE};
#endif

#ifdef GL_INTERNALFORMAT_DEPTH_SIZE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      internalformat_depth_size = {GL_INTERNALFORMAT_DEPTH_SIZE};
#endif

#ifdef GL_INTERNALFORMAT_DEPTH_TYPE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      internalformat_depth_type = {GL_INTERNALFORMAT_DEPTH_TYPE};
#endif

#ifdef GL_INTERNALFORMAT_GREEN_SIZE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      internalformat_green_size = {GL_INTERNALFORMAT_GREEN_SIZE};
#endif

#ifdef GL_INTERNALFORMAT_GREEN_TYPE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      internalformat_green_type = {GL_INTERNALFORMAT_GREEN_TYPE};
#endif

#ifdef GL_INTERNALFORMAT_PREFERRED
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      internalformat_preferred = {GL_INTERNALFORMAT_PREFERRED};
#endif

#ifdef GL_INTERNALFORMAT_RED_SIZE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      internalformat_red_size = {GL_INTERNALFORMAT_RED_SIZE};
#endif

#ifdef GL_INTERNALFORMAT_RED_TYPE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      internalformat_red_type = {GL_INTERNALFORMAT_RED_TYPE};
#endif

#ifdef GL_INTERNALFORMAT_SHARED_SIZE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      internalformat_shared_size = {GL_INTERNALFORMAT_SHARED_SIZE};
#endif

#ifdef GL_INTERNALFORMAT_STENCIL_SIZE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      internalformat_stencil_size = {GL_INTERNALFORMAT_STENCIL_SIZE};
#endif

#ifdef GL_INTERNALFORMAT_STENCIL_TYPE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      internalformat_stencil_type = {GL_INTERNALFORMAT_STENCIL_TYPE};
#endif

#ifdef GL_INTERNALFORMAT_SUPPORTED
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      internalformat_supported = {GL_INTERNALFORMAT_SUPPORTED};
#endif

#ifdef GL_INVALID_ENUM
    static constexpr const enum_value<GLenum, mp_list<oglplus::error_code>>
      invalid_enum = {GL_INVALID_ENUM};
#endif

#ifdef GL_INVALID_FRAMEBUFFER_OPERATION
    static constexpr const enum_value<GLenum, mp_list<oglplus::error_code>>
      invalid_framebuffer_operation = {GL_INVALID_FRAMEBUFFER_OPERATION};
#endif

#ifdef GL_INVALID_OPERATION
    static constexpr const enum_value<GLenum, mp_list<oglplus::error_code>>
      invalid_operation = {GL_INVALID_OPERATION};
#endif

#ifdef GL_INVALID_VALUE
    static constexpr const enum_value<GLenum, mp_list<oglplus::error_code>>
      invalid_value = {GL_INVALID_VALUE};
#endif

#ifdef GL_INVERT
    static constexpr const enum_value<
      GLenum,
      mp_list<
        oglplus::path_fill_mode_nv,
        oglplus::color_logic_operation,
        oglplus::stencil_operation>>
      invert = {GL_INVERT};
#endif

#ifdef GL_IS_PER_PATCH
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_resource_property>>
      is_per_patch = {GL_IS_PER_PATCH};
#endif

#ifdef GL_IS_ROW_MAJOR
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_resource_property>>
      is_row_major = {GL_IS_ROW_MAJOR};
#endif

#ifdef GL_ISOLINES
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::tess_gen_primitive_type>>
      isolines = {GL_ISOLINES};
#endif

#ifdef GL_ITALIC_BIT_NV
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::path_font_style_nv>>
      italic_bit_nv = {GL_ITALIC_BIT_NV};
#endif

#ifdef GL_KEEP
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::stencil_operation>>
      keep = {GL_KEEP};
#endif

#ifdef GL_LARGE_CCW_ARC_TO_NV
    static constexpr const enum_value<
      GLubyte,
      mp_list<oglplus::path_command_nv>>
      large_ccw_arc_to_nv = {GL_LARGE_CCW_ARC_TO_NV};
#endif

#ifdef GL_LARGE_CW_ARC_TO_NV
    static constexpr const enum_value<
      GLubyte,
      mp_list<oglplus::path_command_nv>>
      large_cw_arc_to_nv = {GL_LARGE_CW_ARC_TO_NV};
#endif

#ifdef GL_LAST_VERTEX_CONVENTION
    static constexpr const enum_value<GLenum, mp_list<oglplus::provoke_mode>>
      last_vertex_convention = {GL_LAST_VERTEX_CONVENTION};
#endif

#ifdef GL_LAYER_PROVOKING_VERTEX
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      layer_provoking_vertex = {GL_LAYER_PROVOKING_VERTEX};
#endif

#ifdef GL_LEFT
    static constexpr const enum_value<GLenum, mp_list<oglplus::color_buffer>>
      left = {GL_LEFT};
#endif

#ifdef GL_LEQUAL
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::compare_function>>
      lequal = {GL_LEQUAL};
#endif

#ifdef GL_LESS
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::compare_function>>
      less = {GL_LESS};
#endif

#ifdef GL_LIGHTEN_KHR
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::blend_equation_advanced>>
      lighten_khr = {GL_LIGHTEN_KHR};
#endif

#ifdef GL_LINE
    static constexpr const enum_value<GLenum, mp_list<oglplus::polygon_mode>>
      line = {GL_LINE};
#endif

#ifdef GL_LINE_LOOP
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::primitive_type, oglplus::old_primitive_type>>
      line_loop = {GL_LINE_LOOP};
#endif

#ifdef GL_LINE_SMOOTH
    static constexpr const enum_value<GLenum, mp_list<oglplus::capability>>
      line_smooth = {GL_LINE_SMOOTH};
#endif

#ifdef GL_LINE_SMOOTH_HINT
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::hint_target, oglplus::numeric_query>>
      line_smooth_hint = {GL_LINE_SMOOTH_HINT};
#endif

#ifdef GL_LINE_STRIP
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::primitive_type, oglplus::old_primitive_type>>
      line_strip = {GL_LINE_STRIP};
#endif

#ifdef GL_LINE_STRIP_ADJACENCY
    static constexpr const enum_value<GLenum, mp_list<oglplus::primitive_type>>
      line_strip_adjacency = {GL_LINE_STRIP_ADJACENCY};
#endif

#ifdef GL_LINE_TO_NV
    static constexpr const enum_value<
      GLubyte,
      mp_list<oglplus::path_command_nv>>
      line_to_nv = {GL_LINE_TO_NV};
#endif

#ifdef GL_LINE_WIDTH
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      line_width = {GL_LINE_WIDTH};
#endif

#ifdef GL_LINE_WIDTH_COMMAND_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::command_token_nv>>
      line_width_command_nv = {GL_LINE_WIDTH_COMMAND_NV};
#endif

#ifdef GL_LINEAR
    static constexpr const enum_value<
      GLenum,
      mp_list<
        oglplus::texture_mag_filter,
        oglplus::blit_filter,
        oglplus::texture_filter,
        oglplus::texture_min_filter>>
      linear = {GL_LINEAR};
#endif

#ifdef GL_LINEAR_MIPMAP_LINEAR
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::texture_min_filter>>
      linear_mipmap_linear = {GL_LINEAR_MIPMAP_LINEAR};
#endif

#ifdef GL_LINEAR_MIPMAP_NEAREST
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::texture_min_filter>>
      linear_mipmap_nearest = {GL_LINEAR_MIPMAP_NEAREST};
#endif

#ifdef GL_LINES
    static constexpr const enum_value<
      GLenum,
      mp_list<
        oglplus::primitive_type,
        oglplus::old_primitive_type,
        oglplus::transform_feedback_primitive_type>>
      lines = {GL_LINES};
#endif

#ifdef GL_LINES_ADJACENCY
    static constexpr const enum_value<GLenum, mp_list<oglplus::primitive_type>>
      lines_adjacency = {GL_LINES_ADJACENCY};
#endif

#ifdef GL_LINK_STATUS
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_parameter>>
      link_status = {GL_LINK_STATUS};
#endif

#ifdef GL_LOCATION
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_resource_property>>
      location = {GL_LOCATION};
#endif

#ifdef GL_LOCATION_COMPONENT
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_resource_property>>
      location_component = {GL_LOCATION_COMPONENT};
#endif

#ifdef GL_LOCATION_INDEX
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_resource_property>>
      location_index = {GL_LOCATION_INDEX};
#endif

#ifdef GL_LOGIC_OP_MODE
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      logic_op_mode = {GL_LOGIC_OP_MODE};
#endif

#ifdef GL_LOSE_CONTEXT_ON_RESET
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::reset_notification_strategy>>
      lose_context_on_reset = {GL_LOSE_CONTEXT_ON_RESET};
#endif

#ifdef GL_LOW_FLOAT
    static constexpr const enum_value<GLenum, mp_list<oglplus::precision_type>>
      low_float = {GL_LOW_FLOAT};
#endif

#ifdef GL_LOW_INT
    static constexpr const enum_value<GLenum, mp_list<oglplus::precision_type>>
      low_int = {GL_LOW_INT};
#endif

#ifdef GL_LOWER_LEFT
    static constexpr const enum_value<GLenum, mp_list<oglplus::clip_origin>>
      lower_left = {GL_LOWER_LEFT};
#endif

#ifdef GL_LUMINANCE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::path_color_format_nv>>
      luminance = {GL_LUMINANCE};
#endif

#ifdef GL_LUMINANCE_ALPHA
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::path_color_format_nv>>
      luminance_alpha = {GL_LUMINANCE_ALPHA};
#endif

#ifdef GL_MAP_COHERENT_BIT
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::buffer_storage_bits, oglplus::buffer_map_access>>
      map_coherent_bit = {GL_MAP_COHERENT_BIT};
#endif

#ifdef GL_MAP_COLOR
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_transfer_parameter>>
      map_color = {GL_MAP_COLOR};
#endif

#ifdef GL_MAP_FLUSH_EXPLICIT_BIT
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::buffer_map_access>>
      map_flush_explicit_bit = {GL_MAP_FLUSH_EXPLICIT_BIT};
#endif

#ifdef GL_MAP_INVALIDATE_BUFFER_BIT
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::buffer_map_access>>
      map_invalidate_buffer_bit = {GL_MAP_INVALIDATE_BUFFER_BIT};
#endif

#ifdef GL_MAP_INVALIDATE_RANGE_BIT
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::buffer_map_access>>
      map_invalidate_range_bit = {GL_MAP_INVALIDATE_RANGE_BIT};
#endif

#ifdef GL_MAP_PERSISTENT_BIT
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::buffer_storage_bits, oglplus::buffer_map_access>>
      map_persistent_bit = {GL_MAP_PERSISTENT_BIT};
#endif

#ifdef GL_MAP_READ_BIT
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::buffer_storage_bits, oglplus::buffer_map_access>>
      map_read_bit = {GL_MAP_READ_BIT};
#endif

#ifdef GL_MAP_STENCIL
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_transfer_parameter>>
      map_stencil = {GL_MAP_STENCIL};
#endif

#ifdef GL_MAP_UNSYNCHRONIZED_BIT
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::buffer_map_access>>
      map_unsynchronized_bit = {GL_MAP_UNSYNCHRONIZED_BIT};
#endif

#ifdef GL_MAP_WRITE_BIT
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::buffer_storage_bits, oglplus::buffer_map_access>>
      map_write_bit = {GL_MAP_WRITE_BIT};
#endif

#ifdef GL_MATRIX_STRIDE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_resource_property>>
      matrix_stride = {GL_MATRIX_STRIDE};
#endif

#ifdef GL_MAX
    static constexpr const enum_value<GLenum, mp_list<oglplus::blend_equation>>
      max = {GL_MAX};
#endif

#ifdef GL_MAX_3D_TEXTURE_SIZE
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_3d_texture_size = {GL_MAX_3D_TEXTURE_SIZE};
#endif

#ifdef GL_MAX_ARRAY_TEXTURE_LAYERS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_array_texture_layers = {GL_MAX_ARRAY_TEXTURE_LAYERS};
#endif

#ifdef GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_atomic_counter_buffer_bindings = {
        GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS};
#endif

#ifdef GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_atomic_counter_buffer_size = {GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE};
#endif

#ifdef GL_MAX_CLIP_DISTANCES
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_clip_distances = {GL_MAX_CLIP_DISTANCES};
#endif

#ifdef GL_MAX_COLOR_ATTACHMENTS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_color_attachments = {GL_MAX_COLOR_ATTACHMENTS};
#endif

#ifdef GL_MAX_COLOR_TEXTURE_SAMPLES
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_color_texture_samples = {GL_MAX_COLOR_TEXTURE_SAMPLES};
#endif

#ifdef GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_combined_atomic_counter_buffers = {
        GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS};
#endif

#ifdef GL_MAX_COMBINED_ATOMIC_COUNTERS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_combined_atomic_counters = {GL_MAX_COMBINED_ATOMIC_COUNTERS};
#endif

#ifdef GL_MAX_COMBINED_CLIP_AND_CULL_DISTANCES
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_combined_clip_and_cull_distances = {
        GL_MAX_COMBINED_CLIP_AND_CULL_DISTANCES};
#endif

#ifdef GL_MAX_COMBINED_DIMENSIONS
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      max_combined_dimensions = {GL_MAX_COMBINED_DIMENSIONS};
#endif

#ifdef GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_combined_fragment_uniform_components = {
        GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS};
#endif

#ifdef GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_combined_geometry_uniform_components = {
        GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS};
#endif

#ifdef GL_MAX_COMBINED_IMAGE_UNIFORMS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_combined_image_uniforms = {GL_MAX_COMBINED_IMAGE_UNIFORMS};
#endif

#ifdef GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_combined_image_units_and_fragment_outputs = {
        GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS};
#endif

#ifdef GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_combined_tess_control_uniform_components = {
        GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS};
#endif

#ifdef GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_combined_tess_evaluation_uniform_components = {
        GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS};
#endif

#ifdef GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_combined_texture_image_units = {GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS};
#endif

#ifdef GL_MAX_COMBINED_UNIFORM_BLOCKS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_combined_uniform_blocks = {GL_MAX_COMBINED_UNIFORM_BLOCKS};
#endif

#ifdef GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_combined_vertex_uniform_components = {
        GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS};
#endif

#ifdef GL_MAX_COMPUTE_SHARED_MEMORY_SIZE
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_compute_shared_memory_size = {GL_MAX_COMPUTE_SHARED_MEMORY_SIZE};
#endif

#ifdef GL_MAX_COMPUTE_WORK_GROUP_COUNT
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_compute_work_group_count = {GL_MAX_COMPUTE_WORK_GROUP_COUNT};
#endif

#ifdef GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_compute_work_group_invocations = {
        GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS};
#endif

#ifdef GL_MAX_COMPUTE_WORK_GROUP_SIZE
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_compute_work_group_size = {GL_MAX_COMPUTE_WORK_GROUP_SIZE};
#endif

#ifdef GL_MAX_CUBE_MAP_TEXTURE_SIZE
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_cube_map_texture_size = {GL_MAX_CUBE_MAP_TEXTURE_SIZE};
#endif

#ifdef GL_MAX_CULL_DISTANCES
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_cull_distances = {GL_MAX_CULL_DISTANCES};
#endif

#ifdef GL_MAX_DEPTH
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      max_depth = {GL_MAX_DEPTH};
#endif

#ifdef GL_MAX_DEPTH_TEXTURE_SAMPLES
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_depth_texture_samples = {GL_MAX_DEPTH_TEXTURE_SAMPLES};
#endif

#ifdef GL_MAX_DRAW_BUFFERS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_draw_buffers = {GL_MAX_DRAW_BUFFERS};
#endif

#ifdef GL_MAX_DUAL_SOURCE_DRAW_BUFFERS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_dual_source_draw_buffers = {GL_MAX_DUAL_SOURCE_DRAW_BUFFERS};
#endif

#ifdef GL_MAX_ELEMENTS_INDICES
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_elements_indices = {GL_MAX_ELEMENTS_INDICES};
#endif

#ifdef GL_MAX_ELEMENTS_VERTICES
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_elements_vertices = {GL_MAX_ELEMENTS_VERTICES};
#endif

#ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_fragment_atomic_counter_buffers = {
        GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS};
#endif

#ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTERS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_fragment_atomic_counters = {GL_MAX_FRAGMENT_ATOMIC_COUNTERS};
#endif

#ifdef GL_MAX_FRAGMENT_IMAGE_UNIFORMS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_fragment_image_uniforms = {GL_MAX_FRAGMENT_IMAGE_UNIFORMS};
#endif

#ifdef GL_MAX_FRAGMENT_INPUT_COMPONENTS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_fragment_input_components = {GL_MAX_FRAGMENT_INPUT_COMPONENTS};
#endif

#ifdef GL_MAX_FRAGMENT_INTERPOLATION_OFFSET
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_fragment_interpolation_offset = {
        GL_MAX_FRAGMENT_INTERPOLATION_OFFSET};
#endif

#ifdef GL_MAX_FRAGMENT_UNIFORM_BLOCKS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_fragment_uniform_blocks = {GL_MAX_FRAGMENT_UNIFORM_BLOCKS};
#endif

#ifdef GL_MAX_FRAGMENT_UNIFORM_COMPONENTS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_fragment_uniform_components = {GL_MAX_FRAGMENT_UNIFORM_COMPONENTS};
#endif

#ifdef GL_MAX_FRAGMENT_UNIFORM_VECTORS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_fragment_uniform_vectors = {GL_MAX_FRAGMENT_UNIFORM_VECTORS};
#endif

#ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_geometry_atomic_counter_buffers = {
        GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS};
#endif

#ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTERS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_geometry_atomic_counters = {GL_MAX_GEOMETRY_ATOMIC_COUNTERS};
#endif

#ifdef GL_MAX_GEOMETRY_IMAGE_UNIFORMS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_geometry_image_uniforms = {GL_MAX_GEOMETRY_IMAGE_UNIFORMS};
#endif

#ifdef GL_MAX_GEOMETRY_INPUT_COMPONENTS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_geometry_input_components = {GL_MAX_GEOMETRY_INPUT_COMPONENTS};
#endif

#ifdef GL_MAX_GEOMETRY_OUTPUT_COMPONENTS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_geometry_output_components = {GL_MAX_GEOMETRY_OUTPUT_COMPONENTS};
#endif

#ifdef GL_MAX_GEOMETRY_OUTPUT_VERTICES
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_geometry_output_vertices = {GL_MAX_GEOMETRY_OUTPUT_VERTICES};
#endif

#ifdef GL_MAX_GEOMETRY_SHADER_INVOCATIONS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_geometry_shader_invocations = {GL_MAX_GEOMETRY_SHADER_INVOCATIONS};
#endif

#ifdef GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_geometry_texture_image_units = {GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS};
#endif

#ifdef GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_geometry_total_output_components = {
        GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS};
#endif

#ifdef GL_MAX_GEOMETRY_UNIFORM_BLOCKS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_geometry_uniform_blocks = {GL_MAX_GEOMETRY_UNIFORM_BLOCKS};
#endif

#ifdef GL_MAX_GEOMETRY_UNIFORM_COMPONENTS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_geometry_uniform_components = {GL_MAX_GEOMETRY_UNIFORM_COMPONENTS};
#endif

#ifdef GL_MAX_HEIGHT
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      max_height = {GL_MAX_HEIGHT};
#endif

#ifdef GL_MAX_IMAGE_SAMPLES
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_image_samples = {GL_MAX_IMAGE_SAMPLES};
#endif

#ifdef GL_MAX_IMAGE_UNITS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_image_units = {GL_MAX_IMAGE_UNITS};
#endif

#ifdef GL_MAX_INTEGER_SAMPLES
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_integer_samples = {GL_MAX_INTEGER_SAMPLES};
#endif

#ifdef GL_MAX_LAYERS
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      max_layers = {GL_MAX_LAYERS};
#endif

#ifdef GL_MAX_PATCH_VERTICES
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_patch_vertices = {GL_MAX_PATCH_VERTICES};
#endif

#ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_program_texel_offset = {GL_MAX_PROGRAM_TEXEL_OFFSET};
#endif

#ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_program_texture_gather_offset = {
        GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET};
#endif

#ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_rectangle_texture_size = {GL_MAX_RECTANGLE_TEXTURE_SIZE};
#endif

#ifdef GL_MAX_RENDERBUFFER_SIZE
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_renderbuffer_size = {GL_MAX_RENDERBUFFER_SIZE};
#endif

#ifdef GL_MAX_SAMPLE_MASK_WORDS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_sample_mask_words = {GL_MAX_SAMPLE_MASK_WORDS};
#endif

#ifdef GL_MAX_SAMPLES
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_samples = {GL_MAX_SAMPLES};
#endif

#ifdef GL_MAX_SERVER_WAIT_TIMEOUT
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_server_wait_timeout = {GL_MAX_SERVER_WAIT_TIMEOUT};
#endif

#ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_subroutine_uniform_locations = {GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS};
#endif

#ifdef GL_MAX_SUBROUTINES
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_subroutines = {GL_MAX_SUBROUTINES};
#endif

#ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_tess_control_atomic_counter_buffers = {
        GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS};
#endif

#ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_tess_control_atomic_counters = {GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS};
#endif

#ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_tess_control_image_uniforms = {GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS};
#endif

#ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_tess_control_input_components = {
        GL_MAX_TESS_CONTROL_INPUT_COMPONENTS};
#endif

#ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_tess_control_output_components = {
        GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS};
#endif

#ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_tess_control_texture_image_units = {
        GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS};
#endif

#ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_tess_control_total_output_components = {
        GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS};
#endif

#ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_tess_control_uniform_blocks = {GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS};
#endif

#ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_tess_control_uniform_components = {
        GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS};
#endif

#ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_tess_evaluation_atomic_counter_buffers = {
        GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS};
#endif

#ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_tess_evaluation_atomic_counters = {
        GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS};
#endif

#ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_tess_evaluation_image_uniforms = {
        GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS};
#endif

#ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_tess_evaluation_input_components = {
        GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS};
#endif

#ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_tess_evaluation_output_components = {
        GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS};
#endif

#ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_tess_evaluation_texture_image_units = {
        GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS};
#endif

#ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_tess_evaluation_uniform_blocks = {
        GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS};
#endif

#ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_tess_evaluation_uniform_components = {
        GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS};
#endif

#ifdef GL_MAX_TESS_GEN_LEVEL
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_tess_gen_level = {GL_MAX_TESS_GEN_LEVEL};
#endif

#ifdef GL_MAX_TESS_PATCH_COMPONENTS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_tess_patch_components = {GL_MAX_TESS_PATCH_COMPONENTS};
#endif

#ifdef GL_MAX_TEXTURE_BUFFER_SIZE
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_texture_buffer_size = {GL_MAX_TEXTURE_BUFFER_SIZE};
#endif

#ifdef GL_MAX_TEXTURE_IMAGE_UNITS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_texture_image_units = {GL_MAX_TEXTURE_IMAGE_UNITS};
#endif

#ifdef GL_MAX_TEXTURE_LOD_BIAS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_texture_lod_bias = {GL_MAX_TEXTURE_LOD_BIAS};
#endif

#ifdef GL_MAX_TEXTURE_SIZE
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_texture_size = {GL_MAX_TEXTURE_SIZE};
#endif

#ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_transform_feedback_buffers = {GL_MAX_TRANSFORM_FEEDBACK_BUFFERS};
#endif

#ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_transform_feedback_interleaved_components = {
        GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS};
#endif

#ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_transform_feedback_separate_attribs = {
        GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS};
#endif

#ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_transform_feedback_separate_components = {
        GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS};
#endif

#ifdef GL_MAX_UNIFORM_BLOCK_SIZE
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_uniform_block_size = {GL_MAX_UNIFORM_BLOCK_SIZE};
#endif

#ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_uniform_buffer_bindings = {GL_MAX_UNIFORM_BUFFER_BINDINGS};
#endif

#ifdef GL_MAX_VARYING_COMPONENTS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_varying_components = {GL_MAX_VARYING_COMPONENTS};
#endif

#ifdef GL_MAX_VARYING_VECTORS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_varying_vectors = {GL_MAX_VARYING_VECTORS};
#endif

#ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_vertex_atomic_counter_buffers = {
        GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS};
#endif

#ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_vertex_atomic_counters = {GL_MAX_VERTEX_ATOMIC_COUNTERS};
#endif

#ifdef GL_MAX_VERTEX_ATTRIBS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_vertex_attribs = {GL_MAX_VERTEX_ATTRIBS};
#endif

#ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_vertex_image_uniforms = {GL_MAX_VERTEX_IMAGE_UNIFORMS};
#endif

#ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_vertex_output_components = {GL_MAX_VERTEX_OUTPUT_COMPONENTS};
#endif

#ifdef GL_MAX_VERTEX_STREAMS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_vertex_streams = {GL_MAX_VERTEX_STREAMS};
#endif

#ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_vertex_texture_image_units = {GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS};
#endif

#ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_vertex_uniform_blocks = {GL_MAX_VERTEX_UNIFORM_BLOCKS};
#endif

#ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_vertex_uniform_components = {GL_MAX_VERTEX_UNIFORM_COMPONENTS};
#endif

#ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_vertex_uniform_vectors = {GL_MAX_VERTEX_UNIFORM_VECTORS};
#endif

#ifdef GL_MAX_VIEWPORT_DIMS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_viewport_dims = {GL_MAX_VIEWPORT_DIMS};
#endif

#ifdef GL_MAX_VIEWPORTS
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      max_viewports = {GL_MAX_VIEWPORTS};
#endif

#ifdef GL_MAX_WIDTH
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      max_width = {GL_MAX_WIDTH};
#endif

#ifdef GL_MEDIUM_FLOAT
    static constexpr const enum_value<GLenum, mp_list<oglplus::precision_type>>
      medium_float = {GL_MEDIUM_FLOAT};
#endif

#ifdef GL_MEDIUM_INT
    static constexpr const enum_value<GLenum, mp_list<oglplus::precision_type>>
      medium_int = {GL_MEDIUM_INT};
#endif

#ifdef GL_MIN
    static constexpr const enum_value<GLenum, mp_list<oglplus::blend_equation>>
      min = {GL_MIN};
#endif

#ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      min_fragment_interpolation_offset = {
        GL_MIN_FRAGMENT_INTERPOLATION_OFFSET};
#endif

#ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      min_map_buffer_alignment = {GL_MIN_MAP_BUFFER_ALIGNMENT};
#endif

#ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      min_program_texel_offset = {GL_MIN_PROGRAM_TEXEL_OFFSET};
#endif

#ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
    static constexpr const enum_value<GLenum, mp_list<oglplus::limit_query>>
      min_program_texture_gather_offset = {
        GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET};
#endif

#ifdef GL_MIPMAP
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      mipmap = {GL_MIPMAP};
#endif

#ifdef GL_MIRROR_CLAMP_TO_EDGE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::texture_wrap_mode>>
      mirror_clamp_to_edge = {GL_MIRROR_CLAMP_TO_EDGE};
#endif

#ifdef GL_MIRRORED_REPEAT
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::texture_wrap_mode>>
      mirrored_repeat = {GL_MIRRORED_REPEAT};
#endif

#ifdef GL_MITER_REVERT_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::path_join_style_nv>>
      miter_revert_nv = {GL_MITER_REVERT_NV};
#endif

#ifdef GL_MITER_TRUNCATE_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::path_join_style_nv>>
      miter_truncate_nv = {GL_MITER_TRUNCATE_NV};
#endif

#ifdef GL_MODELVIEW
    static constexpr const enum_value<GLenum, mp_list<oglplus::old_matrix_mode>>
      modelview = {GL_MODELVIEW};
#endif

#ifdef GL_MOVE_TO_CONTINUES_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::path_dash_offset_reset_nv>>
      move_to_continues_nv = {GL_MOVE_TO_CONTINUES_NV};
#endif

#ifdef GL_MOVE_TO_NV
    static constexpr const enum_value<
      GLubyte,
      mp_list<oglplus::path_command_nv>>
      move_to_nv = {GL_MOVE_TO_NV};
#endif

#ifdef GL_MOVE_TO_RESET_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::path_dash_offset_reset_nv>>
      move_to_reset_nv = {GL_MOVE_TO_RESET_NV};
#endif

#ifdef GL_MULTIPLY_KHR
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::blend_equation_advanced>>
      multiply_khr = {GL_MULTIPLY_KHR};
#endif

#ifdef GL_MULTISAMPLE
    static constexpr const enum_value<GLenum, mp_list<oglplus::capability>>
      multisample = {GL_MULTISAMPLE};
#endif

#ifdef GL_NAMED_STRING_LENGTH_ARB
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::named_string_param>>
      named_string_length = {GL_NAMED_STRING_LENGTH_ARB};
#endif

#ifdef GL_NAMED_STRING_TYPE_ARB
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::named_string_param>>
      named_string_type = {GL_NAMED_STRING_TYPE_ARB};
#endif

#ifdef GL_NAND
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::color_logic_operation>>
      nand = {GL_NAND};
#endif

#ifdef GL_NEAREST
    static constexpr const enum_value<
      GLenum,
      mp_list<
        oglplus::texture_mag_filter,
        oglplus::blit_filter,
        oglplus::texture_filter,
        oglplus::texture_min_filter>>
      nearest = {GL_NEAREST};
#endif

#ifdef GL_NEAREST_MIPMAP_LINEAR
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::texture_min_filter>>
      nearest_mipmap_linear = {GL_NEAREST_MIPMAP_LINEAR};
#endif

#ifdef GL_NEAREST_MIPMAP_NEAREST
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::texture_min_filter>>
      nearest_mipmap_nearest = {GL_NEAREST_MIPMAP_NEAREST};
#endif

#ifdef GL_NEGATIVE_ONE_TO_ONE
    static constexpr const enum_value<GLenum, mp_list<oglplus::clip_depth_mode>>
      negative_one_to_one = {GL_NEGATIVE_ONE_TO_ONE};
#endif

#ifdef GL_NEVER
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::compare_function>>
      never = {GL_NEVER};
#endif

#ifdef GL_NICEST
    static constexpr const enum_value<GLenum, mp_list<oglplus::hint_option>>
      nicest = {GL_NICEST};
#endif

#ifdef GL_NO_ERROR
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::graphics_reset_status, oglplus::error_code>>
      no_error = {GL_NO_ERROR};
#endif

#ifdef GL_NO_RESET_NOTIFICATION
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::reset_notification_strategy>>
      no_reset_notification = {GL_NO_RESET_NOTIFICATION};
#endif

#ifdef GL_NONE
    static constexpr const enum_value<
      GLenum,
      mp_list<
        oglplus::sl_data_type,
        oglplus::context_release_behavior,
        oglplus::support_level,
        oglplus::color_buffer,
        oglplus::object_type,
        oglplus::texture_compare_mode,
        oglplus::path_transform_type_nv,
        oglplus::path_join_style_nv,
        oglplus::path_gen_mode_nv>>
      none = {GL_NONE};
#endif

#ifdef GL_NOOP
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::color_logic_operation>>
      noop = {GL_NOOP};
#endif

#ifdef GL_NOP_COMMAND_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::command_token_nv>>
      nop_command_nv = {GL_NOP_COMMAND_NV};
#endif

#ifdef GL_NOR
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::color_logic_operation>>
      nor = {GL_NOR};
#endif

#ifdef GL_NORMAL_ARRAY
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::client_capability>>
      normal_array = {GL_NORMAL_ARRAY};
#endif

#ifdef GL_NORMAL_ARRAY_ADDRESS_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::unified_array_address_nv>>
      normal_array_address_nv = {GL_NORMAL_ARRAY_ADDRESS_NV};
#endif

#ifdef GL_NOTEQUAL
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::compare_function>>
      notequal = {GL_NOTEQUAL};
#endif

#ifdef GL_NUM_ACTIVE_VARIABLES
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_resource_property>>
      num_active_variables = {GL_NUM_ACTIVE_VARIABLES};
#endif

#ifdef GL_NUM_COMPATIBLE_SUBROUTINES
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_resource_property>>
      num_compatible_subroutines = {GL_NUM_COMPATIBLE_SUBROUTINES};
#endif

#ifdef GL_NUM_COMPRESSED_TEXTURE_FORMATS
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      num_compressed_texture_formats = {GL_NUM_COMPRESSED_TEXTURE_FORMATS};
#endif

#ifdef GL_NUM_EXTENSIONS
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      num_extensions = {GL_NUM_EXTENSIONS};
#endif

#ifdef GL_NUM_PROGRAM_BINARY_FORMATS
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      num_program_binary_formats = {GL_NUM_PROGRAM_BINARY_FORMATS};
#endif

#ifdef GL_NUM_SAMPLE_COUNTS
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      num_sample_counts = {GL_NUM_SAMPLE_COUNTS};
#endif

#ifdef GL_NUM_SHADER_BINARY_FORMATS
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      num_shader_binary_formats = {GL_NUM_SHADER_BINARY_FORMATS};
#endif

#ifdef GL_OBJECT_LINEAR
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::path_gen_mode_nv>>
      object_linear = {GL_OBJECT_LINEAR};
#endif

#ifdef GL_OBJECT_TYPE
    static constexpr const enum_value<GLenum, mp_list<oglplus::sync_parameter>>
      object_type = {GL_OBJECT_TYPE};
#endif

#ifdef GL_OFFSET
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_resource_property>>
      offset = {GL_OFFSET};
#endif

#ifdef GL_ONE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::blend_function, oglplus::texture_swizzle_mode>>
      one = {GL_ONE};
#endif

#ifdef GL_ONE_MINUS_CONSTANT_ALPHA
    static constexpr const enum_value<GLenum, mp_list<oglplus::blend_function>>
      one_minus_constant_alpha = {GL_ONE_MINUS_CONSTANT_ALPHA};
#endif

#ifdef GL_ONE_MINUS_CONSTANT_COLOR
    static constexpr const enum_value<GLenum, mp_list<oglplus::blend_function>>
      one_minus_constant_color = {GL_ONE_MINUS_CONSTANT_COLOR};
#endif

#ifdef GL_ONE_MINUS_DST_ALPHA
    static constexpr const enum_value<GLenum, mp_list<oglplus::blend_function>>
      one_minus_dst_alpha = {GL_ONE_MINUS_DST_ALPHA};
#endif

#ifdef GL_ONE_MINUS_DST_COLOR
    static constexpr const enum_value<GLenum, mp_list<oglplus::blend_function>>
      one_minus_dst_color = {GL_ONE_MINUS_DST_COLOR};
#endif

#ifdef GL_ONE_MINUS_SRC1_ALPHA
    static constexpr const enum_value<GLenum, mp_list<oglplus::blend_function>>
      one_minus_src1_alpha = {GL_ONE_MINUS_SRC1_ALPHA};
#endif

#ifdef GL_ONE_MINUS_SRC1_COLOR
    static constexpr const enum_value<GLenum, mp_list<oglplus::blend_function>>
      one_minus_src1_color = {GL_ONE_MINUS_SRC1_COLOR};
#endif

#ifdef GL_ONE_MINUS_SRC_ALPHA
    static constexpr const enum_value<GLenum, mp_list<oglplus::blend_function>>
      one_minus_src_alpha = {GL_ONE_MINUS_SRC_ALPHA};
#endif

#ifdef GL_ONE_MINUS_SRC_COLOR
    static constexpr const enum_value<GLenum, mp_list<oglplus::blend_function>>
      one_minus_src_color = {GL_ONE_MINUS_SRC_COLOR};
#endif

#ifdef GL_OR
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::color_logic_operation>>
      or_ = {GL_OR};
#endif

#ifdef GL_OR_INVERTED
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::color_logic_operation>>
      or_inverted = {GL_OR_INVERTED};
#endif

#ifdef GL_OR_REVERSE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::color_logic_operation>>
      or_reverse = {GL_OR_REVERSE};
#endif

#ifdef GL_OUT_OF_MEMORY
    static constexpr const enum_value<GLenum, mp_list<oglplus::error_code>>
      out_of_memory = {GL_OUT_OF_MEMORY};
#endif

#ifdef GL_OVERLAY_KHR
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::blend_equation_advanced>>
      overlay_khr = {GL_OVERLAY_KHR};
#endif

#ifdef GL_PACK_ALIGNMENT
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::numeric_query, oglplus::pixel_parameter>>
      pack_alignment = {GL_PACK_ALIGNMENT};
#endif

#ifdef GL_PACK_COMPRESSED_BLOCK_DEPTH
    static constexpr const enum_value<GLenum, mp_list<oglplus::pixel_parameter>>
      pack_compressed_block_depth = {GL_PACK_COMPRESSED_BLOCK_DEPTH};
#endif

#ifdef GL_PACK_COMPRESSED_BLOCK_HEIGHT
    static constexpr const enum_value<GLenum, mp_list<oglplus::pixel_parameter>>
      pack_compressed_block_height = {GL_PACK_COMPRESSED_BLOCK_HEIGHT};
#endif

#ifdef GL_PACK_COMPRESSED_BLOCK_SIZE
    static constexpr const enum_value<GLenum, mp_list<oglplus::pixel_parameter>>
      pack_compressed_block_size = {GL_PACK_COMPRESSED_BLOCK_SIZE};
#endif

#ifdef GL_PACK_COMPRESSED_BLOCK_WIDTH
    static constexpr const enum_value<GLenum, mp_list<oglplus::pixel_parameter>>
      pack_compressed_block_width = {GL_PACK_COMPRESSED_BLOCK_WIDTH};
#endif

#ifdef GL_PACK_IMAGE_HEIGHT
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::numeric_query, oglplus::pixel_parameter>>
      pack_image_height = {GL_PACK_IMAGE_HEIGHT};
#endif

#ifdef GL_PACK_LSB_FIRST
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::numeric_query, oglplus::pixel_parameter>>
      pack_lsb_first = {GL_PACK_LSB_FIRST};
#endif

#ifdef GL_PACK_ROW_LENGTH
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::numeric_query, oglplus::pixel_parameter>>
      pack_row_length = {GL_PACK_ROW_LENGTH};
#endif

#ifdef GL_PACK_SKIP_IMAGES
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::numeric_query, oglplus::pixel_parameter>>
      pack_skip_images = {GL_PACK_SKIP_IMAGES};
#endif

#ifdef GL_PACK_SKIP_PIXELS
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::numeric_query, oglplus::pixel_parameter>>
      pack_skip_pixels = {GL_PACK_SKIP_PIXELS};
#endif

#ifdef GL_PACK_SKIP_ROWS
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::numeric_query, oglplus::pixel_parameter>>
      pack_skip_rows = {GL_PACK_SKIP_ROWS};
#endif

#ifdef GL_PACK_SWAP_BYTES
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::numeric_query, oglplus::pixel_parameter>>
      pack_swap_bytes = {GL_PACK_SWAP_BYTES};
#endif

#ifdef GL_PARAMETER_BUFFER_ARB
    static constexpr const enum_value<GLenum, mp_list<oglplus::buffer_target>>
      parameter_buffer = {GL_PARAMETER_BUFFER_ARB};
#endif

#ifdef GL_PARAMETER_BUFFER_BINDING_ARB
    static constexpr const enum_value<GLenum, mp_list<oglplus::binding_query>>
      parameter_buffer_binding = {GL_PARAMETER_BUFFER_BINDING_ARB};
#endif

#ifdef GL_PATCH_DEFAULT_INNER_LEVEL
    static constexpr const enum_value<GLenum, mp_list<oglplus::patch_parameter>>
      patch_default_inner_level = {GL_PATCH_DEFAULT_INNER_LEVEL};
#endif

#ifdef GL_PATCH_DEFAULT_OUTER_LEVEL
    static constexpr const enum_value<GLenum, mp_list<oglplus::patch_parameter>>
      patch_default_outer_level = {GL_PATCH_DEFAULT_OUTER_LEVEL};
#endif

#ifdef GL_PATCH_VERTICES
    static constexpr const enum_value<GLenum, mp_list<oglplus::patch_parameter>>
      patch_vertices = {GL_PATCH_VERTICES};
#endif

#ifdef GL_PATCHES
    static constexpr const enum_value<GLenum, mp_list<oglplus::primitive_type>>
      patches = {GL_PATCHES};
#endif

#ifdef GL_PATH_CLIENT_LENGTH_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::path_parameter_nv>>
      path_client_length_nv = {GL_PATH_CLIENT_LENGTH_NV};
#endif

#ifdef GL_PATH_COMMAND_COUNT_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::path_parameter_nv>>
      path_command_count_nv = {GL_PATH_COMMAND_COUNT_NV};
#endif

#ifdef GL_PATH_COMPUTED_LENGTH_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::path_parameter_nv>>
      path_computed_length_nv = {GL_PATH_COMPUTED_LENGTH_NV};
#endif

#ifdef GL_PATH_COORD_COUNT_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::path_parameter_nv>>
      path_coord_count_nv = {GL_PATH_COORD_COUNT_NV};
#endif

#ifdef GL_PATH_DASH_ARRAY_COUNT_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::path_parameter_nv>>
      path_dash_array_count_nv = {GL_PATH_DASH_ARRAY_COUNT_NV};
#endif

#ifdef GL_PATH_DASH_OFFSET_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::path_parameter_nv>>
      path_dash_offset_nv = {GL_PATH_DASH_OFFSET_NV};
#endif

#ifdef GL_PATH_DASH_OFFSET_RESET_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::path_parameter_nv>>
      path_dash_offset_reset_nv = {GL_PATH_DASH_OFFSET_RESET_NV};
#endif

#ifdef GL_PATH_FILL_BOUNDING_BOX_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::path_parameter_nv>>
      path_fill_bounding_box_nv = {GL_PATH_FILL_BOUNDING_BOX_NV};
#endif

#ifdef GL_PATH_FILL_COVER_MODE_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::path_parameter_nv, oglplus::path_fill_cover_mode_nv>>
      path_fill_cover_mode_nv = {GL_PATH_FILL_COVER_MODE_NV};
#endif

#ifdef GL_PATH_FILL_MASK_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::path_parameter_nv>>
      path_fill_mask_nv = {GL_PATH_FILL_MASK_NV};
#endif

#ifdef GL_PATH_FILL_MODE_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::path_fill_mode_nv, oglplus::path_parameter_nv>>
      path_fill_mode_nv = {GL_PATH_FILL_MODE_NV};
#endif

#ifdef GL_PATH_FORMAT_PS_NV
    static constexpr const enum_value<GLenum, mp_list<oglplus::path_format_nv>>
      path_format_ps_nv = {GL_PATH_FORMAT_PS_NV};
#endif

#ifdef GL_PATH_FORMAT_SVG_NV
    static constexpr const enum_value<GLenum, mp_list<oglplus::path_format_nv>>
      path_format_svg_nv = {GL_PATH_FORMAT_SVG_NV};
#endif

#ifdef GL_PATH_INITIAL_DASH_CAP_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::path_parameter_nv>>
      path_initial_dash_cap_nv = {GL_PATH_INITIAL_DASH_CAP_NV};
#endif

#ifdef GL_PATH_INITIAL_END_CAP_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::path_parameter_nv>>
      path_initial_end_cap_nv = {GL_PATH_INITIAL_END_CAP_NV};
#endif

#ifdef GL_PATH_JOIN_STYLE_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::path_parameter_nv>>
      path_join_style_nv = {GL_PATH_JOIN_STYLE_NV};
#endif

#ifdef GL_PATH_MITER_LIMIT_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::path_parameter_nv>>
      path_miter_limit_nv = {GL_PATH_MITER_LIMIT_NV};
#endif

#ifdef GL_PATH_OBJECT_BOUNDING_BOX_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::path_parameter_nv, oglplus::path_gen_mode_nv>>
      path_object_bounding_box_nv = {GL_PATH_OBJECT_BOUNDING_BOX_NV};
#endif

#ifdef GL_PATH_STROKE_BOUND_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::path_parameter_nv>>
      path_stroke_bound_nv = {GL_PATH_STROKE_BOUND_NV};
#endif

#ifdef GL_PATH_STROKE_BOUNDING_BOX_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::path_parameter_nv>>
      path_stroke_bounding_box_nv = {GL_PATH_STROKE_BOUNDING_BOX_NV};
#endif

#ifdef GL_PATH_STROKE_COVER_MODE_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::path_stroke_cover_mode_nv, oglplus::path_parameter_nv>>
      path_stroke_cover_mode_nv = {GL_PATH_STROKE_COVER_MODE_NV};
#endif

#ifdef GL_PATH_STROKE_MASK_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::path_parameter_nv>>
      path_stroke_mask_nv = {GL_PATH_STROKE_MASK_NV};
#endif

#ifdef GL_PATH_STROKE_WIDTH_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::path_parameter_nv>>
      path_stroke_width_nv = {GL_PATH_STROKE_WIDTH_NV};
#endif

#ifdef GL_PATH_TERMINAL_DASH_CAP_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::path_parameter_nv>>
      path_terminal_dash_cap_nv = {GL_PATH_TERMINAL_DASH_CAP_NV};
#endif

#ifdef GL_PATH_TERMINAL_END_CAP_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::path_parameter_nv>>
      path_terminal_end_cap_nv = {GL_PATH_TERMINAL_END_CAP_NV};
#endif

#ifdef GL_PIXEL_BUFFER_BARRIER_BIT
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::memory_barrier_bits>>
      pixel_buffer_barrier_bit = {GL_PIXEL_BUFFER_BARRIER_BIT};
#endif

#ifdef GL_PIXEL_PACK_BUFFER
    static constexpr const enum_value<GLenum, mp_list<oglplus::buffer_target>>
      pixel_pack_buffer = {GL_PIXEL_PACK_BUFFER};
#endif

#ifdef GL_PIXEL_PACK_BUFFER_BINDING
    static constexpr const enum_value<GLenum, mp_list<oglplus::binding_query>>
      pixel_pack_buffer_binding = {GL_PIXEL_PACK_BUFFER_BINDING};
#endif

#ifdef GL_PIXEL_UNPACK_BUFFER
    static constexpr const enum_value<GLenum, mp_list<oglplus::buffer_target>>
      pixel_unpack_buffer = {GL_PIXEL_UNPACK_BUFFER};
#endif

#ifdef GL_PIXEL_UNPACK_BUFFER_BINDING
    static constexpr const enum_value<GLenum, mp_list<oglplus::binding_query>>
      pixel_unpack_buffer_binding = {GL_PIXEL_UNPACK_BUFFER_BINDING};
#endif

#ifdef GL_POINT
    static constexpr const enum_value<GLenum, mp_list<oglplus::polygon_mode>>
      point = {GL_POINT};
#endif

#ifdef GL_POINT_FADE_THRESHOLD_SIZE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::point_parameter, oglplus::numeric_query>>
      point_fade_threshold_size = {GL_POINT_FADE_THRESHOLD_SIZE};
#endif

#ifdef GL_POINT_SIZE
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      point_size = {GL_POINT_SIZE};
#endif

#ifdef GL_POINT_SIZE_GRANULARITY
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      point_size_granularity = {GL_POINT_SIZE_GRANULARITY};
#endif

#ifdef GL_POINT_SIZE_MAX
    static constexpr const enum_value<GLenum, mp_list<oglplus::point_parameter>>
      point_size_max = {GL_POINT_SIZE_MAX};
#endif

#ifdef GL_POINT_SIZE_MIN
    static constexpr const enum_value<GLenum, mp_list<oglplus::point_parameter>>
      point_size_min = {GL_POINT_SIZE_MIN};
#endif

#ifdef GL_POINT_SIZE_RANGE
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      point_size_range = {GL_POINT_SIZE_RANGE};
#endif

#ifdef GL_POINT_SPRITE_COORD_ORIGIN
    static constexpr const enum_value<GLenum, mp_list<oglplus::point_parameter>>
      point_sprite_coord_origin = {GL_POINT_SPRITE_COORD_ORIGIN};
#endif

#ifdef GL_POINTS
    static constexpr const enum_value<
      GLenum,
      mp_list<
        oglplus::primitive_type,
        oglplus::old_primitive_type,
        oglplus::transform_feedback_primitive_type>>
      points = {GL_POINTS};
#endif

#ifdef GL_POLYGON
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::old_primitive_type>>
      polygon = {GL_POLYGON};
#endif

#ifdef GL_POLYGON_OFFSET_COMMAND_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::command_token_nv>>
      polygon_offset_command_nv = {GL_POLYGON_OFFSET_COMMAND_NV};
#endif

#ifdef GL_POLYGON_OFFSET_FACTOR
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      polygon_offset_factor = {GL_POLYGON_OFFSET_FACTOR};
#endif

#ifdef GL_POLYGON_OFFSET_FILL
    static constexpr const enum_value<GLenum, mp_list<oglplus::capability>>
      polygon_offset_fill = {GL_POLYGON_OFFSET_FILL};
#endif

#ifdef GL_POLYGON_OFFSET_LINE
    static constexpr const enum_value<GLenum, mp_list<oglplus::capability>>
      polygon_offset_line = {GL_POLYGON_OFFSET_LINE};
#endif

#ifdef GL_POLYGON_OFFSET_POINT
    static constexpr const enum_value<GLenum, mp_list<oglplus::capability>>
      polygon_offset_point = {GL_POLYGON_OFFSET_POINT};
#endif

#ifdef GL_POLYGON_OFFSET_UNITS
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      polygon_offset_units = {GL_POLYGON_OFFSET_UNITS};
#endif

#ifdef GL_POLYGON_SMOOTH
    static constexpr const enum_value<GLenum, mp_list<oglplus::capability>>
      polygon_smooth = {GL_POLYGON_SMOOTH};
#endif

#ifdef GL_POLYGON_SMOOTH_HINT
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::hint_target, oglplus::numeric_query>>
      polygon_smooth_hint = {GL_POLYGON_SMOOTH_HINT};
#endif

#ifdef GL_POST_COLOR_MATRIX_ALPHA_BIAS
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_transfer_parameter>>
      post_color_matrix_alpha_bias = {GL_POST_COLOR_MATRIX_ALPHA_BIAS};
#endif

#ifdef GL_POST_COLOR_MATRIX_ALPHA_SCALE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_transfer_parameter>>
      post_color_matrix_alpha_scale = {GL_POST_COLOR_MATRIX_ALPHA_SCALE};
#endif

#ifdef GL_POST_COLOR_MATRIX_BLUE_BIAS
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_transfer_parameter>>
      post_color_matrix_blue_bias = {GL_POST_COLOR_MATRIX_BLUE_BIAS};
#endif

#ifdef GL_POST_COLOR_MATRIX_BLUE_SCALE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_transfer_parameter>>
      post_color_matrix_blue_scale = {GL_POST_COLOR_MATRIX_BLUE_SCALE};
#endif

#ifdef GL_POST_COLOR_MATRIX_GREEN_BIAS
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_transfer_parameter>>
      post_color_matrix_green_bias = {GL_POST_COLOR_MATRIX_GREEN_BIAS};
#endif

#ifdef GL_POST_COLOR_MATRIX_GREEN_SCALE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_transfer_parameter>>
      post_color_matrix_green_scale = {GL_POST_COLOR_MATRIX_GREEN_SCALE};
#endif

#ifdef GL_POST_COLOR_MATRIX_RED_BIAS
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_transfer_parameter>>
      post_color_matrix_red_bias = {GL_POST_COLOR_MATRIX_RED_BIAS};
#endif

#ifdef GL_POST_COLOR_MATRIX_RED_SCALE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_transfer_parameter>>
      post_color_matrix_red_scale = {GL_POST_COLOR_MATRIX_RED_SCALE};
#endif

#ifdef GL_POST_CONVOLUTION_ALPHA_BIAS
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_transfer_parameter>>
      post_convolution_alpha_bias = {GL_POST_CONVOLUTION_ALPHA_BIAS};
#endif

#ifdef GL_POST_CONVOLUTION_ALPHA_SCALE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_transfer_parameter>>
      post_convolution_alpha_scale = {GL_POST_CONVOLUTION_ALPHA_SCALE};
#endif

#ifdef GL_POST_CONVOLUTION_BLUE_BIAS
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_transfer_parameter>>
      post_convolution_blue_bias = {GL_POST_CONVOLUTION_BLUE_BIAS};
#endif

#ifdef GL_POST_CONVOLUTION_BLUE_SCALE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_transfer_parameter>>
      post_convolution_blue_scale = {GL_POST_CONVOLUTION_BLUE_SCALE};
#endif

#ifdef GL_POST_CONVOLUTION_GREEN_BIAS
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_transfer_parameter>>
      post_convolution_green_bias = {GL_POST_CONVOLUTION_GREEN_BIAS};
#endif

#ifdef GL_POST_CONVOLUTION_GREEN_SCALE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_transfer_parameter>>
      post_convolution_green_scale = {GL_POST_CONVOLUTION_GREEN_SCALE};
#endif

#ifdef GL_POST_CONVOLUTION_RED_BIAS
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_transfer_parameter>>
      post_convolution_red_bias = {GL_POST_CONVOLUTION_RED_BIAS};
#endif

#ifdef GL_POST_CONVOLUTION_RED_SCALE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_transfer_parameter>>
      post_convolution_red_scale = {GL_POST_CONVOLUTION_RED_SCALE};
#endif

#ifdef GL_PRIMARY_COLOR_NV
    static constexpr const enum_value<GLenum, mp_list<oglplus::path_color_nv>>
      primary_color_nv = {GL_PRIMARY_COLOR_NV};
#endif

#ifdef GL_PRIMITIVE_RESTART
    static constexpr const enum_value<GLenum, mp_list<oglplus::capability>>
      primitive_restart = {GL_PRIMITIVE_RESTART};
#endif

#ifdef GL_PRIMITIVE_RESTART_INDEX
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      primitive_restart_index = {GL_PRIMITIVE_RESTART_INDEX};
#endif

#ifdef GL_PRIMITIVES_GENERATED
    static constexpr const enum_value<GLenum, mp_list<oglplus::query_target>>
      primitives_generated = {GL_PRIMITIVES_GENERATED};
#endif

#ifdef GL_PRIMITIVES_SUBMITTED_ARB
    static constexpr const enum_value<GLenum, mp_list<oglplus::query_target>>
      primitives_submitted = {GL_PRIMITIVES_SUBMITTED_ARB};
#endif

#ifdef GL_PROGRAM
    static constexpr const enum_value<GLenum, mp_list<oglplus::object_type>>
      program = {GL_PROGRAM};
#endif

#ifdef GL_PROGRAM_BINARY_FORMATS
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      program_binary_formats = {GL_PROGRAM_BINARY_FORMATS};
#endif

#ifdef GL_PROGRAM_BINARY_LENGTH
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_parameter>>
      program_binary_length = {GL_PROGRAM_BINARY_LENGTH};
#endif

#ifdef GL_PROGRAM_INPUT
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_interface>>
      program_input = {GL_PROGRAM_INPUT};
#endif

#ifdef GL_PROGRAM_OUTPUT
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_interface>>
      program_output = {GL_PROGRAM_OUTPUT};
#endif

#ifdef GL_PROGRAM_PIPELINE
    static constexpr const enum_value<GLenum, mp_list<oglplus::object_type>>
      program_pipeline = {GL_PROGRAM_PIPELINE};
#endif

#ifdef GL_PROGRAM_POINT_SIZE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::capability, oglplus::numeric_query>>
      program_point_size = {GL_PROGRAM_POINT_SIZE};
#endif

#ifdef GL_PROJECTION
    static constexpr const enum_value<GLenum, mp_list<oglplus::old_matrix_mode>>
      projection = {GL_PROJECTION};
#endif

#ifdef GL_PROVOKING_VERTEX
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      provoking_vertex = {GL_PROVOKING_VERTEX};
#endif

#ifdef GL_QUAD_STRIP
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::old_primitive_type>>
      quad_strip = {GL_QUAD_STRIP};
#endif

#ifdef GL_QUADRATIC_CURVE_TO_NV
    static constexpr const enum_value<
      GLubyte,
      mp_list<oglplus::path_command_nv>>
      quadratic_curve_to_nv = {GL_QUADRATIC_CURVE_TO_NV};
#endif

#ifdef GL_QUADS
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::old_primitive_type, oglplus::tess_gen_primitive_type>>
      quads = {GL_QUADS};
#endif

#ifdef GL_QUERY
    static constexpr const enum_value<GLenum, mp_list<oglplus::object_type>>
      query = {GL_QUERY};
#endif

#ifdef GL_QUERY_BUFFER
    static constexpr const enum_value<GLenum, mp_list<oglplus::buffer_target>>
      query_buffer = {GL_QUERY_BUFFER};
#endif

#ifdef GL_QUERY_BUFFER_BINDING
    static constexpr const enum_value<GLenum, mp_list<oglplus::binding_query>>
      query_buffer_binding = {GL_QUERY_BUFFER_BINDING};
#endif

#ifdef GL_QUERY_BY_REGION_NO_WAIT
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::conditional_render_mode>>
      query_by_region_no_wait = {GL_QUERY_BY_REGION_NO_WAIT};
#endif

#ifdef GL_QUERY_BY_REGION_NO_WAIT_INVERTED
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::conditional_render_mode>>
      query_by_region_no_wait_inverted = {GL_QUERY_BY_REGION_NO_WAIT_INVERTED};
#endif

#ifdef GL_QUERY_BY_REGION_WAIT
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::conditional_render_mode>>
      query_by_region_wait = {GL_QUERY_BY_REGION_WAIT};
#endif

#ifdef GL_QUERY_BY_REGION_WAIT_INVERTED
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::conditional_render_mode>>
      query_by_region_wait_inverted = {GL_QUERY_BY_REGION_WAIT_INVERTED};
#endif

#ifdef GL_QUERY_NO_WAIT
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::conditional_render_mode>>
      query_no_wait = {GL_QUERY_NO_WAIT};
#endif

#ifdef GL_QUERY_NO_WAIT_INVERTED
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::conditional_render_mode>>
      query_no_wait_inverted = {GL_QUERY_NO_WAIT_INVERTED};
#endif

#ifdef GL_QUERY_RESULT
    static constexpr const enum_value<GLenum, mp_list<oglplus::query_parameter>>
      query_result = {GL_QUERY_RESULT};
#endif

#ifdef GL_QUERY_RESULT_AVAILABLE
    static constexpr const enum_value<GLenum, mp_list<oglplus::query_parameter>>
      query_result_available = {GL_QUERY_RESULT_AVAILABLE};
#endif

#ifdef GL_QUERY_WAIT
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::conditional_render_mode>>
      query_wait = {GL_QUERY_WAIT};
#endif

#ifdef GL_QUERY_WAIT_INVERTED
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::conditional_render_mode>>
      query_wait_inverted = {GL_QUERY_WAIT_INVERTED};
#endif

#ifdef GL_R11F_G11F_B10F
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::image_unit_format, oglplus::pixel_data_internal_format>>
      r11f_g11f_b10f = {GL_R11F_G11F_B10F};
#endif

#ifdef GL_R16
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::image_unit_format, oglplus::pixel_data_internal_format>>
      r16 = {GL_R16};
#endif

#ifdef GL_R16_SNORM
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::image_unit_format, oglplus::pixel_data_internal_format>>
      r16_snorm = {GL_R16_SNORM};
#endif

#ifdef GL_R16F
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::image_unit_format, oglplus::pixel_data_internal_format>>
      r16f = {GL_R16F};
#endif

#ifdef GL_R16I
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::image_unit_format, oglplus::pixel_data_internal_format>>
      r16i = {GL_R16I};
#endif

#ifdef GL_R16UI
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::image_unit_format, oglplus::pixel_data_internal_format>>
      r16ui = {GL_R16UI};
#endif

#ifdef GL_R32F
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::image_unit_format, oglplus::pixel_data_internal_format>>
      r32f = {GL_R32F};
#endif

#ifdef GL_R32I
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::image_unit_format, oglplus::pixel_data_internal_format>>
      r32i = {GL_R32I};
#endif

#ifdef GL_R32UI
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::image_unit_format, oglplus::pixel_data_internal_format>>
      r32ui = {GL_R32UI};
#endif

#ifdef GL_R3_G3_B2
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_internal_format>>
      r3_g3_b2 = {GL_R3_G3_B2};
#endif

#ifdef GL_R8
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::image_unit_format, oglplus::pixel_data_internal_format>>
      r8 = {GL_R8};
#endif

#ifdef GL_R8_SNORM
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::image_unit_format, oglplus::pixel_data_internal_format>>
      r8_snorm = {GL_R8_SNORM};
#endif

#ifdef GL_R8I
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::image_unit_format, oglplus::pixel_data_internal_format>>
      r8i = {GL_R8I};
#endif

#ifdef GL_R8UI
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::image_unit_format, oglplus::pixel_data_internal_format>>
      r8ui = {GL_R8UI};
#endif

#ifdef GL_RASTERIZER_DISCARD
    static constexpr const enum_value<GLenum, mp_list<oglplus::capability>>
      rasterizer_discard = {GL_RASTERIZER_DISCARD};
#endif

#ifdef GL_READ_BUFFER
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      read_buffer = {GL_READ_BUFFER};
#endif

#ifdef GL_READ_FRAMEBUFFER
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::framebuffer_target>>
      read_framebuffer = {GL_READ_FRAMEBUFFER};
#endif

#ifdef GL_READ_ONLY
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::access_specifier>>
      read_only = {GL_READ_ONLY};
#endif

#ifdef GL_READ_PIXELS
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      read_pixels = {GL_READ_PIXELS};
#endif

#ifdef GL_READ_PIXELS_FORMAT
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      read_pixels_format = {GL_READ_PIXELS_FORMAT};
#endif

#ifdef GL_READ_PIXELS_TYPE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      read_pixels_type = {GL_READ_PIXELS_TYPE};
#endif

#ifdef GL_READ_WRITE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::access_specifier>>
      read_write = {GL_READ_WRITE};
#endif

#ifdef GL_RECT_NV
    static constexpr const enum_value<
      GLubyte,
      mp_list<oglplus::path_command_nv>>
      rect_nv = {GL_RECT_NV};
#endif

#ifdef GL_RED
    static constexpr const enum_value<
      GLenum,
      mp_list<
        oglplus::texture_swizzle_mode,
        oglplus::pixel_data_format,
        oglplus::pixel_data_internal_format>>
      red = {GL_RED};
#endif

#ifdef GL_RED_BIAS
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_transfer_parameter>>
      red_bias = {GL_RED_BIAS};
#endif

#ifdef GL_RED_INTEGER
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_format>>
      red_integer = {GL_RED_INTEGER};
#endif

#ifdef GL_RED_SCALE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_transfer_parameter>>
      red_scale = {GL_RED_SCALE};
#endif

#ifdef GL_REFERENCED_BY_COMPUTE_SHADER
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_resource_property>>
      referenced_by_compute_shader = {GL_REFERENCED_BY_COMPUTE_SHADER};
#endif

#ifdef GL_REFERENCED_BY_FRAGMENT_SHADER
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_resource_property>>
      referenced_by_fragment_shader = {GL_REFERENCED_BY_FRAGMENT_SHADER};
#endif

#ifdef GL_REFERENCED_BY_GEOMETRY_SHADER
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_resource_property>>
      referenced_by_geometry_shader = {GL_REFERENCED_BY_GEOMETRY_SHADER};
#endif

#ifdef GL_REFERENCED_BY_TESS_CONTROL_SHADER
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_resource_property>>
      referenced_by_tess_control_shader = {
        GL_REFERENCED_BY_TESS_CONTROL_SHADER};
#endif

#ifdef GL_REFERENCED_BY_TESS_EVALUATION_SHADER
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_resource_property>>
      referenced_by_tess_evaluation_shader = {
        GL_REFERENCED_BY_TESS_EVALUATION_SHADER};
#endif

#ifdef GL_REFERENCED_BY_VERTEX_SHADER
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_resource_property>>
      referenced_by_vertex_shader = {GL_REFERENCED_BY_VERTEX_SHADER};
#endif

#ifdef GL_RELATIVE_ARC_TO_NV
    static constexpr const enum_value<
      GLubyte,
      mp_list<oglplus::path_command_nv>>
      relative_arc_to_nv = {GL_RELATIVE_ARC_TO_NV};
#endif

#ifdef GL_RELATIVE_CUBIC_CURVE_TO_NV
    static constexpr const enum_value<
      GLubyte,
      mp_list<oglplus::path_command_nv>>
      relative_cubic_curve_to_nv = {GL_RELATIVE_CUBIC_CURVE_TO_NV};
#endif

#ifdef GL_RELATIVE_HORIZONTAL_LINE_TO_NV
    static constexpr const enum_value<
      GLubyte,
      mp_list<oglplus::path_command_nv>>
      relative_horizontal_line_to_nv = {GL_RELATIVE_HORIZONTAL_LINE_TO_NV};
#endif

#ifdef GL_RELATIVE_LARGE_CCW_ARC_TO_NV
    static constexpr const enum_value<
      GLubyte,
      mp_list<oglplus::path_command_nv>>
      relative_large_ccw_arc_to_nv = {GL_RELATIVE_LARGE_CCW_ARC_TO_NV};
#endif

#ifdef GL_RELATIVE_LARGE_CW_ARC_TO_NV
    static constexpr const enum_value<
      GLubyte,
      mp_list<oglplus::path_command_nv>>
      relative_large_cw_arc_to_nv = {GL_RELATIVE_LARGE_CW_ARC_TO_NV};
#endif

#ifdef GL_RELATIVE_LINE_TO_NV
    static constexpr const enum_value<
      GLubyte,
      mp_list<oglplus::path_command_nv>>
      relative_line_to_nv = {GL_RELATIVE_LINE_TO_NV};
#endif

#ifdef GL_RELATIVE_MOVE_TO_NV
    static constexpr const enum_value<
      GLubyte,
      mp_list<oglplus::path_command_nv>>
      relative_move_to_nv = {GL_RELATIVE_MOVE_TO_NV};
#endif

#ifdef GL_RELATIVE_QUADRATIC_CURVE_TO_NV
    static constexpr const enum_value<
      GLubyte,
      mp_list<oglplus::path_command_nv>>
      relative_quadratic_curve_to_nv = {GL_RELATIVE_QUADRATIC_CURVE_TO_NV};
#endif

#ifdef GL_RELATIVE_SMALL_CCW_ARC_TO_NV
    static constexpr const enum_value<
      GLubyte,
      mp_list<oglplus::path_command_nv>>
      relative_small_ccw_arc_to_nv = {GL_RELATIVE_SMALL_CCW_ARC_TO_NV};
#endif

#ifdef GL_RELATIVE_SMALL_CW_ARC_TO_NV
    static constexpr const enum_value<
      GLubyte,
      mp_list<oglplus::path_command_nv>>
      relative_small_cw_arc_to_nv = {GL_RELATIVE_SMALL_CW_ARC_TO_NV};
#endif

#ifdef GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV
    static constexpr const enum_value<
      GLubyte,
      mp_list<oglplus::path_command_nv>>
      relative_smooth_cubic_curve_to_nv = {
        GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV};
#endif

#ifdef GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV
    static constexpr const enum_value<
      GLubyte,
      mp_list<oglplus::path_command_nv>>
      relative_smooth_quadratic_curve_to_nv = {
        GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV};
#endif

#ifdef GL_RELATIVE_VERTICAL_LINE_TO_NV
    static constexpr const enum_value<
      GLubyte,
      mp_list<oglplus::path_command_nv>>
      relative_vertical_line_to_nv = {GL_RELATIVE_VERTICAL_LINE_TO_NV};
#endif

#ifdef GL_RENDERBUFFER
    static constexpr const enum_value<
      GLenum,
      mp_list<
        oglplus::object_type,
        oglplus::renderbuffer_target,
        oglplus::internal_format_target>>
      renderbuffer = {GL_RENDERBUFFER};
#endif

#ifdef GL_RENDERBUFFER_ALPHA_SIZE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::renderbuffer_parameter>>
      renderbuffer_alpha_size = {GL_RENDERBUFFER_ALPHA_SIZE};
#endif

#ifdef GL_RENDERBUFFER_BINDING
    static constexpr const enum_value<GLenum, mp_list<oglplus::binding_query>>
      renderbuffer_binding = {GL_RENDERBUFFER_BINDING};
#endif

#ifdef GL_RENDERBUFFER_BLUE_SIZE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::renderbuffer_parameter>>
      renderbuffer_blue_size = {GL_RENDERBUFFER_BLUE_SIZE};
#endif

#ifdef GL_RENDERBUFFER_DEPTH_SIZE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::renderbuffer_parameter>>
      renderbuffer_depth_size = {GL_RENDERBUFFER_DEPTH_SIZE};
#endif

#ifdef GL_RENDERBUFFER_GREEN_SIZE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::renderbuffer_parameter>>
      renderbuffer_green_size = {GL_RENDERBUFFER_GREEN_SIZE};
#endif

#ifdef GL_RENDERBUFFER_HEIGHT
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::renderbuffer_parameter>>
      renderbuffer_height = {GL_RENDERBUFFER_HEIGHT};
#endif

#ifdef GL_RENDERBUFFER_INTERNAL_FORMAT
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::renderbuffer_parameter>>
      renderbuffer_internal_format = {GL_RENDERBUFFER_INTERNAL_FORMAT};
#endif

#ifdef GL_RENDERBUFFER_RED_SIZE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::renderbuffer_parameter>>
      renderbuffer_red_size = {GL_RENDERBUFFER_RED_SIZE};
#endif

#ifdef GL_RENDERBUFFER_SAMPLES
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::renderbuffer_parameter>>
      renderbuffer_samples = {GL_RENDERBUFFER_SAMPLES};
#endif

#ifdef GL_RENDERBUFFER_STENCIL_SIZE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::renderbuffer_parameter>>
      renderbuffer_stencil_size = {GL_RENDERBUFFER_STENCIL_SIZE};
#endif

#ifdef GL_RENDERBUFFER_WIDTH
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::renderbuffer_parameter>>
      renderbuffer_width = {GL_RENDERBUFFER_WIDTH};
#endif

#ifdef GL_RENDERER
    static constexpr const enum_value<GLenum, mp_list<oglplus::string_query>>
      renderer = {GL_RENDERER};
#endif

#ifdef GL_REPEAT
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::texture_wrap_mode>>
      repeat = {GL_REPEAT};
#endif

#ifdef GL_REPLACE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::stencil_operation>>
      replace = {GL_REPLACE};
#endif

#ifdef GL_RESTART_PATH_NV
    static constexpr const enum_value<
      GLubyte,
      mp_list<oglplus::path_command_nv>>
      restart_path_nv = {GL_RESTART_PATH_NV};
#endif

#ifdef GL_RG
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_format, oglplus::pixel_data_internal_format>>
      rg = {GL_RG};
#endif

#ifdef GL_RG16
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::image_unit_format, oglplus::pixel_data_internal_format>>
      rg16 = {GL_RG16};
#endif

#ifdef GL_RG16_SNORM
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::image_unit_format, oglplus::pixel_data_internal_format>>
      rg16_snorm = {GL_RG16_SNORM};
#endif

#ifdef GL_RG16F
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::image_unit_format, oglplus::pixel_data_internal_format>>
      rg16f = {GL_RG16F};
#endif

#ifdef GL_RG16I
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::image_unit_format, oglplus::pixel_data_internal_format>>
      rg16i = {GL_RG16I};
#endif

#ifdef GL_RG16UI
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::image_unit_format, oglplus::pixel_data_internal_format>>
      rg16ui = {GL_RG16UI};
#endif

#ifdef GL_RG32F
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::image_unit_format, oglplus::pixel_data_internal_format>>
      rg32f = {GL_RG32F};
#endif

#ifdef GL_RG32I
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::image_unit_format, oglplus::pixel_data_internal_format>>
      rg32i = {GL_RG32I};
#endif

#ifdef GL_RG32UI
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::image_unit_format, oglplus::pixel_data_internal_format>>
      rg32ui = {GL_RG32UI};
#endif

#ifdef GL_RG8
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::image_unit_format, oglplus::pixel_data_internal_format>>
      rg8 = {GL_RG8};
#endif

#ifdef GL_RG8_SNORM
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::image_unit_format, oglplus::pixel_data_internal_format>>
      rg8_snorm = {GL_RG8_SNORM};
#endif

#ifdef GL_RG8I
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::image_unit_format, oglplus::pixel_data_internal_format>>
      rg8i = {GL_RG8I};
#endif

#ifdef GL_RG8UI
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::image_unit_format, oglplus::pixel_data_internal_format>>
      rg8ui = {GL_RG8UI};
#endif

#ifdef GL_RG_INTEGER
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_format>>
      rg_integer = {GL_RG_INTEGER};
#endif

#ifdef GL_RGB
    static constexpr const enum_value<
      GLenum,
      mp_list<
        oglplus::path_color_format_nv,
        oglplus::pixel_data_format,
        oglplus::pixel_data_internal_format>>
      rgb = {GL_RGB};
#endif

#ifdef GL_RGB10
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_internal_format>>
      rgb10 = {GL_RGB10};
#endif

#ifdef GL_RGB10_A2
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::image_unit_format, oglplus::pixel_data_internal_format>>
      rgb10_a2 = {GL_RGB10_A2};
#endif

#ifdef GL_RGB10_A2UI
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::image_unit_format, oglplus::pixel_data_internal_format>>
      rgb10_a2ui = {GL_RGB10_A2UI};
#endif

#ifdef GL_RGB12
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_internal_format>>
      rgb12 = {GL_RGB12};
#endif

#ifdef GL_RGB16
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_internal_format>>
      rgb16 = {GL_RGB16};
#endif

#ifdef GL_RGB16_SNORM
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_internal_format>>
      rgb16_snorm = {GL_RGB16_SNORM};
#endif

#ifdef GL_RGB16F
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_internal_format>>
      rgb16f = {GL_RGB16F};
#endif

#ifdef GL_RGB16I
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_internal_format>>
      rgb16i = {GL_RGB16I};
#endif

#ifdef GL_RGB16UI
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_internal_format>>
      rgb16ui = {GL_RGB16UI};
#endif

#ifdef GL_RGB32F
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_internal_format>>
      rgb32f = {GL_RGB32F};
#endif

#ifdef GL_RGB32I
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_internal_format>>
      rgb32i = {GL_RGB32I};
#endif

#ifdef GL_RGB32UI
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_internal_format>>
      rgb32ui = {GL_RGB32UI};
#endif

#ifdef GL_RGB4
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_internal_format>>
      rgb4 = {GL_RGB4};
#endif

#ifdef GL_RGB5
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_internal_format>>
      rgb5 = {GL_RGB5};
#endif

#ifdef GL_RGB5_A1
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_internal_format>>
      rgb5_a1 = {GL_RGB5_A1};
#endif

#ifdef GL_RGB8
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_internal_format>>
      rgb8 = {GL_RGB8};
#endif

#ifdef GL_RGB8_SNORM
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_internal_format>>
      rgb8_snorm = {GL_RGB8_SNORM};
#endif

#ifdef GL_RGB8I
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_internal_format>>
      rgb8i = {GL_RGB8I};
#endif

#ifdef GL_RGB8UI
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_internal_format>>
      rgb8ui = {GL_RGB8UI};
#endif

#ifdef GL_RGB9_E5
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_internal_format>>
      rgb9_e5 = {GL_RGB9_E5};
#endif

#ifdef GL_RGB_INTEGER
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_format>>
      rgb_integer = {GL_RGB_INTEGER};
#endif

#ifdef GL_RGBA
    static constexpr const enum_value<
      GLenum,
      mp_list<
        oglplus::path_color_format_nv,
        oglplus::pixel_data_format,
        oglplus::pixel_data_internal_format>>
      rgba = {GL_RGBA};
#endif

#ifdef GL_RGBA12
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_internal_format>>
      rgba12 = {GL_RGBA12};
#endif

#ifdef GL_RGBA16
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::image_unit_format, oglplus::pixel_data_internal_format>>
      rgba16 = {GL_RGBA16};
#endif

#ifdef GL_RGBA16_SNORM
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::image_unit_format, oglplus::pixel_data_internal_format>>
      rgba16_snorm = {GL_RGBA16_SNORM};
#endif

#ifdef GL_RGBA16F
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::image_unit_format, oglplus::pixel_data_internal_format>>
      rgba16f = {GL_RGBA16F};
#endif

#ifdef GL_RGBA16I
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::image_unit_format, oglplus::pixel_data_internal_format>>
      rgba16i = {GL_RGBA16I};
#endif

#ifdef GL_RGBA16UI
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::image_unit_format, oglplus::pixel_data_internal_format>>
      rgba16ui = {GL_RGBA16UI};
#endif

#ifdef GL_RGBA2
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_internal_format>>
      rgba2 = {GL_RGBA2};
#endif

#ifdef GL_RGBA32F
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::image_unit_format, oglplus::pixel_data_internal_format>>
      rgba32f = {GL_RGBA32F};
#endif

#ifdef GL_RGBA32I
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::image_unit_format, oglplus::pixel_data_internal_format>>
      rgba32i = {GL_RGBA32I};
#endif

#ifdef GL_RGBA32UI
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::image_unit_format, oglplus::pixel_data_internal_format>>
      rgba32ui = {GL_RGBA32UI};
#endif

#ifdef GL_RGBA4
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_internal_format>>
      rgba4 = {GL_RGBA4};
#endif

#ifdef GL_RGBA8
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::image_unit_format, oglplus::pixel_data_internal_format>>
      rgba8 = {GL_RGBA8};
#endif

#ifdef GL_RGBA8_SNORM
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::image_unit_format, oglplus::pixel_data_internal_format>>
      rgba8_snorm = {GL_RGBA8_SNORM};
#endif

#ifdef GL_RGBA8I
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::image_unit_format, oglplus::pixel_data_internal_format>>
      rgba8i = {GL_RGBA8I};
#endif

#ifdef GL_RGBA8UI
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::image_unit_format, oglplus::pixel_data_internal_format>>
      rgba8ui = {GL_RGBA8UI};
#endif

#ifdef GL_RGBA_INTEGER
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_format>>
      rgba_integer = {GL_RGBA_INTEGER};
#endif

#ifdef GL_RIGHT
    static constexpr const enum_value<GLenum, mp_list<oglplus::color_buffer>>
      right = {GL_RIGHT};
#endif

#ifdef GL_ROUND_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::path_cap_style_nv, oglplus::path_join_style_nv>>
      round_nv = {GL_ROUND_NV};
#endif

#ifdef GL_SAMPLE_ALPHA_TO_COVERAGE
    static constexpr const enum_value<GLenum, mp_list<oglplus::capability>>
      sample_alpha_to_coverage = {GL_SAMPLE_ALPHA_TO_COVERAGE};
#endif

#ifdef GL_SAMPLE_ALPHA_TO_ONE
    static constexpr const enum_value<GLenum, mp_list<oglplus::capability>>
      sample_alpha_to_one = {GL_SAMPLE_ALPHA_TO_ONE};
#endif

#ifdef GL_SAMPLE_BUFFERS
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      sample_buffers = {GL_SAMPLE_BUFFERS};
#endif

#ifdef GL_SAMPLE_COVERAGE
    static constexpr const enum_value<GLenum, mp_list<oglplus::capability>>
      sample_coverage = {GL_SAMPLE_COVERAGE};
#endif

#ifdef GL_SAMPLE_COVERAGE_INVERT
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      sample_coverage_invert = {GL_SAMPLE_COVERAGE_INVERT};
#endif

#ifdef GL_SAMPLE_COVERAGE_VALUE
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      sample_coverage_value = {GL_SAMPLE_COVERAGE_VALUE};
#endif

#ifdef GL_SAMPLE_MASK
    static constexpr const enum_value<GLenum, mp_list<oglplus::capability>>
      sample_mask = {GL_SAMPLE_MASK};
#endif

#ifdef GL_SAMPLE_SHADING
    static constexpr const enum_value<GLenum, mp_list<oglplus::capability>>
      sample_shading = {GL_SAMPLE_SHADING};
#endif

#ifdef GL_SAMPLER
    static constexpr const enum_value<GLenum, mp_list<oglplus::object_type>>
      sampler = {GL_SAMPLER};
#endif

#ifdef GL_SAMPLER_1D
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      sampler_1d = {GL_SAMPLER_1D};
#endif

#ifdef GL_SAMPLER_1D_ARRAY
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      sampler_1d_array = {GL_SAMPLER_1D_ARRAY};
#endif

#ifdef GL_SAMPLER_1D_ARRAY_SHADOW
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      sampler_1d_array_shadow = {GL_SAMPLER_1D_ARRAY_SHADOW};
#endif

#ifdef GL_SAMPLER_1D_SHADOW
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      sampler_1d_shadow = {GL_SAMPLER_1D_SHADOW};
#endif

#ifdef GL_SAMPLER_2D
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      sampler_2d = {GL_SAMPLER_2D};
#endif

#ifdef GL_SAMPLER_2D_ARRAY
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      sampler_2d_array = {GL_SAMPLER_2D_ARRAY};
#endif

#ifdef GL_SAMPLER_2D_ARRAY_SHADOW
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      sampler_2d_array_shadow = {GL_SAMPLER_2D_ARRAY_SHADOW};
#endif

#ifdef GL_SAMPLER_2D_MULTISAMPLE
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      sampler_2d_multisample = {GL_SAMPLER_2D_MULTISAMPLE};
#endif

#ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      sampler_2d_multisample_array = {GL_SAMPLER_2D_MULTISAMPLE_ARRAY};
#endif

#ifdef GL_SAMPLER_2D_RECT
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      sampler_2d_rect = {GL_SAMPLER_2D_RECT};
#endif

#ifdef GL_SAMPLER_2D_RECT_SHADOW
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      sampler_2d_rect_shadow = {GL_SAMPLER_2D_RECT_SHADOW};
#endif

#ifdef GL_SAMPLER_2D_SHADOW
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      sampler_2d_shadow = {GL_SAMPLER_2D_SHADOW};
#endif

#ifdef GL_SAMPLER_3D
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      sampler_3d = {GL_SAMPLER_3D};
#endif

#ifdef GL_SAMPLER_BINDING
    static constexpr const enum_value<GLenum, mp_list<oglplus::binding_query>>
      sampler_binding = {GL_SAMPLER_BINDING};
#endif

#ifdef GL_SAMPLER_BUFFER
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      sampler_buffer = {GL_SAMPLER_BUFFER};
#endif

#ifdef GL_SAMPLER_CUBE
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      sampler_cube = {GL_SAMPLER_CUBE};
#endif

#ifdef GL_SAMPLER_CUBE_MAP_ARRAY
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      sampler_cube_map_array = {GL_SAMPLER_CUBE_MAP_ARRAY};
#endif

#ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      sampler_cube_map_array_shadow = {GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW};
#endif

#ifdef GL_SAMPLER_CUBE_SHADOW
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      sampler_cube_shadow = {GL_SAMPLER_CUBE_SHADOW};
#endif

#ifdef GL_SAMPLES
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::numeric_query, oglplus::internal_format_parameter>>
      samples = {GL_SAMPLES};
#endif

#ifdef GL_SAMPLES_PASSED
    static constexpr const enum_value<GLenum, mp_list<oglplus::query_target>>
      samples_passed = {GL_SAMPLES_PASSED};
#endif

#ifdef GL_SCISSOR_BOX
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      scissor_box = {GL_SCISSOR_BOX};
#endif

#ifdef GL_SCISSOR_COMMAND_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::command_token_nv>>
      scissor_command_nv = {GL_SCISSOR_COMMAND_NV};
#endif

#ifdef GL_SCISSOR_TEST
    static constexpr const enum_value<GLenum, mp_list<oglplus::capability>>
      scissor_test = {GL_SCISSOR_TEST};
#endif

#ifdef GL_SCREEN_KHR
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::blend_equation_advanced>>
      screen_khr = {GL_SCREEN_KHR};
#endif

#ifdef GL_SECONDARY_COLOR_ARRAY
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::client_capability>>
      secondary_color_array = {GL_SECONDARY_COLOR_ARRAY};
#endif

#ifdef GL_SECONDARY_COLOR_ARRAY_ADDRESS_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::unified_array_address_nv>>
      secondary_color_array_address_nv = {GL_SECONDARY_COLOR_ARRAY_ADDRESS_NV};
#endif

#ifdef GL_SECONDARY_COLOR_NV
    static constexpr const enum_value<GLenum, mp_list<oglplus::path_color_nv>>
      secondary_color_nv = {GL_SECONDARY_COLOR_NV};
#endif

#ifdef GL_SEPARATE_ATTRIBS
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::transform_feedback_mode>>
      separate_attribs = {GL_SEPARATE_ATTRIBS};
#endif

#ifdef GL_SET
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::color_logic_operation>>
      set = {GL_SET};
#endif

#ifdef GL_SHADER
    static constexpr const enum_value<GLenum, mp_list<oglplus::object_type>>
      shader = {GL_SHADER};
#endif

#ifdef GL_SHADER_COMPILER
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      shader_compiler = {GL_SHADER_COMPILER};
#endif

#ifdef GL_SHADER_GLOBAL_ACCESS_BARRIER_BIT_NV
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::memory_barrier_bits>>
      shader_global_access_barrier_bit_nv = {
        GL_SHADER_GLOBAL_ACCESS_BARRIER_BIT_NV};
#endif

#ifdef GL_SHADER_IMAGE_ACCESS_BARRIER_BIT
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::memory_barrier_bits>>
      shader_image_access_barrier_bit = {GL_SHADER_IMAGE_ACCESS_BARRIER_BIT};
#endif

#ifdef GL_SHADER_IMAGE_ATOMIC
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      shader_image_atomic = {GL_SHADER_IMAGE_ATOMIC};
#endif

#ifdef GL_SHADER_IMAGE_LOAD
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      shader_image_load = {GL_SHADER_IMAGE_LOAD};
#endif

#ifdef GL_SHADER_IMAGE_STORE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      shader_image_store = {GL_SHADER_IMAGE_STORE};
#endif

#ifdef GL_SHADER_INCLUDE_ARB
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::named_string_type>>
      shader_include = {GL_SHADER_INCLUDE_ARB};
#endif

#ifdef GL_SHADER_SOURCE_LENGTH
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::shader_parameter>>
      shader_source_length = {GL_SHADER_SOURCE_LENGTH};
#endif

#ifdef GL_SHADER_STORAGE_BARRIER_BIT
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::memory_barrier_bits>>
      shader_storage_barrier_bit = {GL_SHADER_STORAGE_BARRIER_BIT};
#endif

#ifdef GL_SHADER_STORAGE_BLOCK
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_interface>>
      shader_storage_block = {GL_SHADER_STORAGE_BLOCK};
#endif

#ifdef GL_SHADER_STORAGE_BUFFER
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::buffer_indexed_target, oglplus::buffer_target>>
      shader_storage_buffer = {GL_SHADER_STORAGE_BUFFER};
#endif

#ifdef GL_SHADER_STORAGE_BUFFER_BINDING
    static constexpr const enum_value<GLenum, mp_list<oglplus::binding_query>>
      shader_storage_buffer_binding = {GL_SHADER_STORAGE_BUFFER_BINDING};
#endif

#ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      shader_storage_buffer_offset_alignment = {
        GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT};
#endif

#ifdef GL_SHADER_STORAGE_BUFFER_SIZE
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      shader_storage_buffer_size = {GL_SHADER_STORAGE_BUFFER_SIZE};
#endif

#ifdef GL_SHADER_STORAGE_BUFFER_START
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      shader_storage_buffer_start = {GL_SHADER_STORAGE_BUFFER_START};
#endif

#ifdef GL_SHADER_TYPE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::shader_parameter>>
      shader_type = {GL_SHADER_TYPE};
#endif

#ifdef GL_SHADING_LANGUAGE_VERSION
    static constexpr const enum_value<GLenum, mp_list<oglplus::string_query>>
      shading_language_version = {GL_SHADING_LANGUAGE_VERSION};
#endif

#ifdef GL_SHORT
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_type, oglplus::data_type>>
      short_ = {GL_SHORT};
#endif

#ifdef GL_SIGNALED
    static constexpr const enum_value<GLenum, mp_list<oglplus::sync_status>>
      signaled = {GL_SIGNALED};
#endif

#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      simultaneous_texture_and_depth_test = {
        GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST};
#endif

#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      simultaneous_texture_and_depth_write = {
        GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE};
#endif

#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      simultaneous_texture_and_stencil_test = {
        GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST};
#endif

#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      simultaneous_texture_and_stencil_write = {
        GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE};
#endif

#ifdef GL_SKIP_MISSING_GLYPH_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::path_missing_glyph_nv>>
      skip_missing_glyph_nv = {GL_SKIP_MISSING_GLYPH_NV};
#endif

#ifdef GL_SMALL_CCW_ARC_TO_NV
    static constexpr const enum_value<
      GLubyte,
      mp_list<oglplus::path_command_nv>>
      small_ccw_arc_to_nv = {GL_SMALL_CCW_ARC_TO_NV};
#endif

#ifdef GL_SMALL_CW_ARC_TO_NV
    static constexpr const enum_value<
      GLubyte,
      mp_list<oglplus::path_command_nv>>
      small_cw_arc_to_nv = {GL_SMALL_CW_ARC_TO_NV};
#endif

#ifdef GL_SMOOTH_CUBIC_CURVE_TO_NV
    static constexpr const enum_value<
      GLubyte,
      mp_list<oglplus::path_command_nv>>
      smooth_cubic_curve_to_nv = {GL_SMOOTH_CUBIC_CURVE_TO_NV};
#endif

#ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      smooth_line_width_granularity = {GL_SMOOTH_LINE_WIDTH_GRANULARITY};
#endif

#ifdef GL_SMOOTH_LINE_WIDTH_RANGE
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      smooth_line_width_range = {GL_SMOOTH_LINE_WIDTH_RANGE};
#endif

#ifdef GL_SMOOTH_QUADRATIC_CURVE_TO_NV
    static constexpr const enum_value<
      GLubyte,
      mp_list<oglplus::path_command_nv>>
      smooth_quadratic_curve_to_nv = {GL_SMOOTH_QUADRATIC_CURVE_TO_NV};
#endif

#ifdef GL_SOFTLIGHT_KHR
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::blend_equation_advanced>>
      softlight_khr = {GL_SOFTLIGHT_KHR};
#endif

#ifdef GL_SPARSE_STORAGE_BIT_ARB
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::buffer_storage_bits>>
      sparse_storage_bit = {GL_SPARSE_STORAGE_BIT_ARB};
#endif

#ifdef GL_SQUARE_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::path_cap_style_nv>>
      square_nv = {GL_SQUARE_NV};
#endif

#ifdef GL_SRC1_ALPHA
    static constexpr const enum_value<GLenum, mp_list<oglplus::blend_function>>
      src1_alpha = {GL_SRC1_ALPHA};
#endif

#ifdef GL_SRC1_COLOR
    static constexpr const enum_value<GLenum, mp_list<oglplus::blend_function>>
      src1_color = {GL_SRC1_COLOR};
#endif

#ifdef GL_SRC_ALPHA
    static constexpr const enum_value<GLenum, mp_list<oglplus::blend_function>>
      src_alpha = {GL_SRC_ALPHA};
#endif

#ifdef GL_SRC_ALPHA_SATURATE
    static constexpr const enum_value<GLenum, mp_list<oglplus::blend_function>>
      src_alpha_saturate = {GL_SRC_ALPHA_SATURATE};
#endif

#ifdef GL_SRC_COLOR
    static constexpr const enum_value<GLenum, mp_list<oglplus::blend_function>>
      src_color = {GL_SRC_COLOR};
#endif

#ifdef GL_SRGB8
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_internal_format>>
      srgb8 = {GL_SRGB8};
#endif

#ifdef GL_SRGB8_ALPHA8
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_internal_format>>
      srgb8_alpha8 = {GL_SRGB8_ALPHA8};
#endif

#ifdef GL_SRGB_READ
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      srgb_read = {GL_SRGB_READ};
#endif

#ifdef GL_SRGB_WRITE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      srgb_write = {GL_SRGB_WRITE};
#endif

#ifdef GL_STACK_OVERFLOW
    static constexpr const enum_value<GLenum, mp_list<oglplus::error_code>>
      stack_overflow = {GL_STACK_OVERFLOW};
#endif

#ifdef GL_STACK_UNDERFLOW
    static constexpr const enum_value<GLenum, mp_list<oglplus::error_code>>
      stack_underflow = {GL_STACK_UNDERFLOW};
#endif

#ifdef GL_STANDARD_FONT_NAME_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::path_font_target_nv>>
      standard_font_name_nv = {GL_STANDARD_FONT_NAME_NV};
#endif

#ifdef GL_STATIC_COPY
    static constexpr const enum_value<GLenum, mp_list<oglplus::buffer_usage>>
      static_copy = {GL_STATIC_COPY};
#endif

#ifdef GL_STATIC_DRAW
    static constexpr const enum_value<GLenum, mp_list<oglplus::buffer_usage>>
      static_draw = {GL_STATIC_DRAW};
#endif

#ifdef GL_STATIC_READ
    static constexpr const enum_value<GLenum, mp_list<oglplus::buffer_usage>>
      static_read = {GL_STATIC_READ};
#endif

#ifdef GL_STENCIL
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::framebuffer_buffer>>
      stencil = {GL_STENCIL};
#endif

#ifdef GL_STENCIL_ATTACHMENT
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::framebuffer_other_attachment>>
      stencil_attachment = {GL_STENCIL_ATTACHMENT};
#endif

#ifdef GL_STENCIL_BACK_FAIL
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      stencil_back_fail = {GL_STENCIL_BACK_FAIL};
#endif

#ifdef GL_STENCIL_BACK_FUNC
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      stencil_back_func = {GL_STENCIL_BACK_FUNC};
#endif

#ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      stencil_back_pass_depth_fail = {GL_STENCIL_BACK_PASS_DEPTH_FAIL};
#endif

#ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      stencil_back_pass_depth_pass = {GL_STENCIL_BACK_PASS_DEPTH_PASS};
#endif

#ifdef GL_STENCIL_BACK_REF
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      stencil_back_ref = {GL_STENCIL_BACK_REF};
#endif

#ifdef GL_STENCIL_BACK_VALUE_MASK
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      stencil_back_value_mask = {GL_STENCIL_BACK_VALUE_MASK};
#endif

#ifdef GL_STENCIL_BACK_WRITEMASK
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      stencil_back_writemask = {GL_STENCIL_BACK_WRITEMASK};
#endif

#ifdef GL_STENCIL_BUFFER_BIT
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::buffer_select_bits>>
      stencil_buffer_bit = {GL_STENCIL_BUFFER_BIT};
#endif

#ifdef GL_STENCIL_CLEAR_VALUE
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      stencil_clear_value = {GL_STENCIL_CLEAR_VALUE};
#endif

#ifdef GL_STENCIL_COMPONENTS
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      stencil_components = {GL_STENCIL_COMPONENTS};
#endif

#ifdef GL_STENCIL_FAIL
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      stencil_fail = {GL_STENCIL_FAIL};
#endif

#ifdef GL_STENCIL_FUNC
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      stencil_func = {GL_STENCIL_FUNC};
#endif

#ifdef GL_STENCIL_INDEX
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_format>>
      stencil_index = {GL_STENCIL_INDEX};
#endif

#ifdef GL_STENCIL_INDEX8
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::pixel_data_internal_format>>
      stencil_index8 = {GL_STENCIL_INDEX8};
#endif

#ifdef GL_STENCIL_PASS_DEPTH_FAIL
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      stencil_pass_depth_fail = {GL_STENCIL_PASS_DEPTH_FAIL};
#endif

#ifdef GL_STENCIL_PASS_DEPTH_PASS
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      stencil_pass_depth_pass = {GL_STENCIL_PASS_DEPTH_PASS};
#endif

#ifdef GL_STENCIL_REF
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      stencil_ref = {GL_STENCIL_REF};
#endif

#ifdef GL_STENCIL_REF_COMMAND_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::command_token_nv>>
      stencil_ref_command_nv = {GL_STENCIL_REF_COMMAND_NV};
#endif

#ifdef GL_STENCIL_RENDERABLE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      stencil_renderable = {GL_STENCIL_RENDERABLE};
#endif

#ifdef GL_STENCIL_TEST
    static constexpr const enum_value<GLenum, mp_list<oglplus::capability>>
      stencil_test = {GL_STENCIL_TEST};
#endif

#ifdef GL_STENCIL_VALUE_MASK
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      stencil_value_mask = {GL_STENCIL_VALUE_MASK};
#endif

#ifdef GL_STENCIL_WRITEMASK
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      stencil_writemask = {GL_STENCIL_WRITEMASK};
#endif

#ifdef GL_STEREO
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      stereo = {GL_STEREO};
#endif

#ifdef GL_STREAM_COPY
    static constexpr const enum_value<GLenum, mp_list<oglplus::buffer_usage>>
      stream_copy = {GL_STREAM_COPY};
#endif

#ifdef GL_STREAM_DRAW
    static constexpr const enum_value<GLenum, mp_list<oglplus::buffer_usage>>
      stream_draw = {GL_STREAM_DRAW};
#endif

#ifdef GL_STREAM_RASTERIZATION_AMD
    static constexpr const enum_value<GLenum, mp_list<oglplus::capability>>
      stream_rasterization = {GL_STREAM_RASTERIZATION_AMD};
#endif

#ifdef GL_STREAM_READ
    static constexpr const enum_value<GLenum, mp_list<oglplus::buffer_usage>>
      stream_read = {GL_STREAM_READ};
#endif

#ifdef GL_SUBPIXEL_BITS
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      subpixel_bits = {GL_SUBPIXEL_BITS};
#endif

#ifdef GL_SYNC_CONDITION
    static constexpr const enum_value<GLenum, mp_list<oglplus::sync_parameter>>
      sync_condition = {GL_SYNC_CONDITION};
#endif

#ifdef GL_SYNC_FENCE
    static constexpr const enum_value<GLenum, mp_list<oglplus::sync_type>>
      sync_fence = {GL_SYNC_FENCE};
#endif

#ifdef GL_SYNC_GPU_COMMANDS_COMPLETE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::sync_condition, oglplus::sync_parameter>>
      sync_gpu_commands_complete = {GL_SYNC_GPU_COMMANDS_COMPLETE};
#endif

#ifdef GL_SYNC_STATUS
    static constexpr const enum_value<GLenum, mp_list<oglplus::sync_parameter>>
      sync_status = {GL_SYNC_STATUS};
#endif

#ifdef GL_SYSTEM_FONT_NAME_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::path_font_target_nv>>
      system_font_name_nv = {GL_SYSTEM_FONT_NAME_NV};
#endif

#ifdef GL_TABLE_TOO_LARGE
    static constexpr const enum_value<GLenum, mp_list<oglplus::error_code>>
      table_too_large = {GL_TABLE_TOO_LARGE};
#endif

#ifdef GL_TERMINATE_SEQUENCE_COMMAND_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::command_token_nv>>
      terminate_sequence_command_nv = {GL_TERMINATE_SEQUENCE_COMMAND_NV};
#endif

#ifdef GL_TESS_CONTROL_SHADER
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::shader_type, oglplus::program_pipeline_parameter>>
      tess_control_shader = {GL_TESS_CONTROL_SHADER};
#endif

#ifdef GL_TESS_CONTROL_SHADER_BIT
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::program_pipeline_stage>>
      tess_control_shader_bit = {GL_TESS_CONTROL_SHADER_BIT};
#endif

#ifdef GL_TESS_CONTROL_SHADER_PATCHES_ARB
    static constexpr const enum_value<GLenum, mp_list<oglplus::query_target>>
      tess_control_shader_patches = {GL_TESS_CONTROL_SHADER_PATCHES_ARB};
#endif

#ifdef GL_TESS_CONTROL_SUBROUTINE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_interface>>
      tess_control_subroutine = {GL_TESS_CONTROL_SUBROUTINE};
#endif

#ifdef GL_TESS_CONTROL_SUBROUTINE_UNIFORM
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_interface>>
      tess_control_subroutine_uniform = {GL_TESS_CONTROL_SUBROUTINE_UNIFORM};
#endif

#ifdef GL_TESS_CONTROL_TEXTURE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      tess_control_texture = {GL_TESS_CONTROL_TEXTURE};
#endif

#ifdef GL_TESS_EVALUATION_SHADER
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::shader_type, oglplus::program_pipeline_parameter>>
      tess_evaluation_shader = {GL_TESS_EVALUATION_SHADER};
#endif

#ifdef GL_TESS_EVALUATION_SHADER_BIT
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::program_pipeline_stage>>
      tess_evaluation_shader_bit = {GL_TESS_EVALUATION_SHADER_BIT};
#endif

#ifdef GL_TESS_EVALUATION_SHADER_INVOCATIONS_ARB
    static constexpr const enum_value<GLenum, mp_list<oglplus::query_target>>
      tess_evaluation_shader_invocations = {
        GL_TESS_EVALUATION_SHADER_INVOCATIONS_ARB};
#endif

#ifdef GL_TESS_EVALUATION_SUBROUTINE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_interface>>
      tess_evaluation_subroutine = {GL_TESS_EVALUATION_SUBROUTINE};
#endif

#ifdef GL_TESS_EVALUATION_SUBROUTINE_UNIFORM
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_interface>>
      tess_evaluation_subroutine_uniform = {
        GL_TESS_EVALUATION_SUBROUTINE_UNIFORM};
#endif

#ifdef GL_TESS_EVALUATION_TEXTURE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      tess_evaluation_texture = {GL_TESS_EVALUATION_TEXTURE};
#endif

#ifdef GL_TEXTURE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::old_matrix_mode, oglplus::object_type>>
      texture = {GL_TEXTURE};
#endif

#ifdef GL_TEXTURE0
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::indexed_value_base>>
      texture0 = {GL_TEXTURE0};
#endif

#ifdef GL_TEXTURE_1D
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::texture_target, oglplus::internal_format_target>>
      texture_1d = {GL_TEXTURE_1D};
#endif

#ifdef GL_TEXTURE_1D_ARRAY
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::texture_target, oglplus::internal_format_target>>
      texture_1d_array = {GL_TEXTURE_1D_ARRAY};
#endif

#ifdef GL_TEXTURE_2D
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::texture_target, oglplus::internal_format_target>>
      texture_2d = {GL_TEXTURE_2D};
#endif

#ifdef GL_TEXTURE_2D_ARRAY
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::texture_target, oglplus::internal_format_target>>
      texture_2d_array = {GL_TEXTURE_2D_ARRAY};
#endif

#ifdef GL_TEXTURE_2D_MULTISAMPLE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::texture_target, oglplus::internal_format_target>>
      texture_2d_multisample = {GL_TEXTURE_2D_MULTISAMPLE};
#endif

#ifdef GL_TEXTURE_2D_MULTISAMPLE_ARRAY
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::texture_target, oglplus::internal_format_target>>
      texture_2d_multisample_array = {GL_TEXTURE_2D_MULTISAMPLE_ARRAY};
#endif

#ifdef GL_TEXTURE_3D
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::texture_target, oglplus::internal_format_target>>
      texture_3d = {GL_TEXTURE_3D};
#endif

#ifdef GL_TEXTURE_BASE_LEVEL
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::texture_parameter>>
      texture_base_level = {GL_TEXTURE_BASE_LEVEL};
#endif

#ifdef GL_TEXTURE_BINDING_1D
    static constexpr const enum_value<GLenum, mp_list<oglplus::binding_query>>
      texture_binding_1d = {GL_TEXTURE_BINDING_1D};
#endif

#ifdef GL_TEXTURE_BINDING_1D_ARRAY
    static constexpr const enum_value<GLenum, mp_list<oglplus::binding_query>>
      texture_binding_1d_array = {GL_TEXTURE_BINDING_1D_ARRAY};
#endif

#ifdef GL_TEXTURE_BINDING_2D
    static constexpr const enum_value<GLenum, mp_list<oglplus::binding_query>>
      texture_binding_2d = {GL_TEXTURE_BINDING_2D};
#endif

#ifdef GL_TEXTURE_BINDING_2D_ARRAY
    static constexpr const enum_value<GLenum, mp_list<oglplus::binding_query>>
      texture_binding_2d_array = {GL_TEXTURE_BINDING_2D_ARRAY};
#endif

#ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE
    static constexpr const enum_value<GLenum, mp_list<oglplus::binding_query>>
      texture_binding_2d_multisample = {GL_TEXTURE_BINDING_2D_MULTISAMPLE};
#endif

#ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY
    static constexpr const enum_value<GLenum, mp_list<oglplus::binding_query>>
      texture_binding_2d_multisample_array = {
        GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY};
#endif

#ifdef GL_TEXTURE_BINDING_3D
    static constexpr const enum_value<GLenum, mp_list<oglplus::binding_query>>
      texture_binding_3d = {GL_TEXTURE_BINDING_3D};
#endif

#ifdef GL_TEXTURE_BINDING_BUFFER
    static constexpr const enum_value<GLenum, mp_list<oglplus::binding_query>>
      texture_binding_buffer = {GL_TEXTURE_BINDING_BUFFER};
#endif

#ifdef GL_TEXTURE_BINDING_CUBE_MAP
    static constexpr const enum_value<GLenum, mp_list<oglplus::binding_query>>
      texture_binding_cube_map = {GL_TEXTURE_BINDING_CUBE_MAP};
#endif

#ifdef GL_TEXTURE_BINDING_CUBE_MAP_ARRAY
    static constexpr const enum_value<GLenum, mp_list<oglplus::binding_query>>
      texture_binding_cube_map_array = {GL_TEXTURE_BINDING_CUBE_MAP_ARRAY};
#endif

#ifdef GL_TEXTURE_BINDING_RECTANGLE
    static constexpr const enum_value<GLenum, mp_list<oglplus::binding_query>>
      texture_binding_rectangle = {GL_TEXTURE_BINDING_RECTANGLE};
#endif

#ifdef GL_TEXTURE_BORDER_COLOR
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::texture_parameter, oglplus::sampler_parameter>>
      texture_border_color = {GL_TEXTURE_BORDER_COLOR};
#endif

#ifdef GL_TEXTURE_BUFFER
    static constexpr const enum_value<
      GLenum,
      mp_list<
        oglplus::texture_target,
        oglplus::buffer_target,
        oglplus::internal_format_target>>
      texture_buffer = {GL_TEXTURE_BUFFER};
#endif

#ifdef GL_TEXTURE_BUFFER_BINDING
    static constexpr const enum_value<GLenum, mp_list<oglplus::binding_query>>
      texture_buffer_binding = {GL_TEXTURE_BUFFER_BINDING};
#endif

#ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      texture_buffer_offset_alignment = {GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT};
#endif

#ifdef GL_TEXTURE_COMPARE_FUNC
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::texture_parameter, oglplus::sampler_parameter>>
      texture_compare_func = {GL_TEXTURE_COMPARE_FUNC};
#endif

#ifdef GL_TEXTURE_COMPARE_MODE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::texture_parameter, oglplus::sampler_parameter>>
      texture_compare_mode = {GL_TEXTURE_COMPARE_MODE};
#endif

#ifdef GL_TEXTURE_COMPRESSED
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      texture_compressed = {GL_TEXTURE_COMPRESSED};
#endif

#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      texture_compressed_block_height = {GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT};
#endif

#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      texture_compressed_block_size = {GL_TEXTURE_COMPRESSED_BLOCK_SIZE};
#endif

#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      texture_compressed_block_width = {GL_TEXTURE_COMPRESSED_BLOCK_WIDTH};
#endif

#ifdef GL_TEXTURE_COMPRESSION_HINT
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::hint_target, oglplus::numeric_query>>
      texture_compression_hint = {GL_TEXTURE_COMPRESSION_HINT};
#endif

#ifdef GL_TEXTURE_COORD_ARRAY
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::client_capability>>
      texture_coord_array = {GL_TEXTURE_COORD_ARRAY};
#endif

#ifdef GL_TEXTURE_COORD_ARRAY_ADDRESS_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::unified_array_address_nv>>
      texture_coord_array_address_nv = {GL_TEXTURE_COORD_ARRAY_ADDRESS_NV};
#endif

#ifdef GL_TEXTURE_CUBE_MAP
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::texture_target, oglplus::internal_format_target>>
      texture_cube_map = {GL_TEXTURE_CUBE_MAP};
#endif

#ifdef GL_TEXTURE_CUBE_MAP_ARRAY
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::texture_target, oglplus::internal_format_target>>
      texture_cube_map_array = {GL_TEXTURE_CUBE_MAP_ARRAY};
#endif

#ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_X
    static constexpr const enum_value<GLenum, mp_list<oglplus::texture_target>>
      texture_cube_map_negative_x = {GL_TEXTURE_CUBE_MAP_NEGATIVE_X};
#endif

#ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_Y
    static constexpr const enum_value<GLenum, mp_list<oglplus::texture_target>>
      texture_cube_map_negative_y = {GL_TEXTURE_CUBE_MAP_NEGATIVE_Y};
#endif

#ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_Z
    static constexpr const enum_value<GLenum, mp_list<oglplus::texture_target>>
      texture_cube_map_negative_z = {GL_TEXTURE_CUBE_MAP_NEGATIVE_Z};
#endif

#ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_X
    static constexpr const enum_value<GLenum, mp_list<oglplus::texture_target>>
      texture_cube_map_positive_x = {GL_TEXTURE_CUBE_MAP_POSITIVE_X};
#endif

#ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_Y
    static constexpr const enum_value<GLenum, mp_list<oglplus::texture_target>>
      texture_cube_map_positive_y = {GL_TEXTURE_CUBE_MAP_POSITIVE_Y};
#endif

#ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_Z
    static constexpr const enum_value<GLenum, mp_list<oglplus::texture_target>>
      texture_cube_map_positive_z = {GL_TEXTURE_CUBE_MAP_POSITIVE_Z};
#endif

#ifdef GL_TEXTURE_CUBE_MAP_SEAMLESS
    static constexpr const enum_value<GLenum, mp_list<oglplus::capability>>
      texture_cube_map_seamless = {GL_TEXTURE_CUBE_MAP_SEAMLESS};
#endif

#ifdef GL_TEXTURE_FETCH_BARRIER_BIT
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::memory_barrier_bits>>
      texture_fetch_barrier_bit = {GL_TEXTURE_FETCH_BARRIER_BIT};
#endif

#ifdef GL_TEXTURE_GATHER
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      texture_gather = {GL_TEXTURE_GATHER};
#endif

#ifdef GL_TEXTURE_GATHER_SHADOW
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      texture_gather_shadow = {GL_TEXTURE_GATHER_SHADOW};
#endif

#ifdef GL_TEXTURE_IMAGE_FORMAT
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      texture_image_format = {GL_TEXTURE_IMAGE_FORMAT};
#endif

#ifdef GL_TEXTURE_IMAGE_TYPE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      texture_image_type = {GL_TEXTURE_IMAGE_TYPE};
#endif

#ifdef GL_TEXTURE_IMMUTABLE_FORMAT
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::texture_parameter>>
      texture_immutable_format = {GL_TEXTURE_IMMUTABLE_FORMAT};
#endif

#ifdef GL_TEXTURE_IMMUTABLE_LEVELS
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::texture_parameter>>
      texture_immutable_levels = {GL_TEXTURE_IMMUTABLE_LEVELS};
#endif

#ifdef GL_TEXTURE_LOD_BIAS
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::texture_parameter, oglplus::sampler_parameter>>
      texture_lod_bias = {GL_TEXTURE_LOD_BIAS};
#endif

#ifdef GL_TEXTURE_MAG_FILTER
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::texture_parameter, oglplus::sampler_parameter>>
      texture_mag_filter = {GL_TEXTURE_MAG_FILTER};
#endif

#ifdef GL_TEXTURE_MAX_LEVEL
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::texture_parameter>>
      texture_max_level = {GL_TEXTURE_MAX_LEVEL};
#endif

#ifdef GL_TEXTURE_MAX_LOD
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::texture_parameter, oglplus::sampler_parameter>>
      texture_max_lod = {GL_TEXTURE_MAX_LOD};
#endif

#ifdef GL_TEXTURE_MIN_FILTER
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::texture_parameter, oglplus::sampler_parameter>>
      texture_min_filter = {GL_TEXTURE_MIN_FILTER};
#endif

#ifdef GL_TEXTURE_MIN_LOD
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::texture_parameter, oglplus::sampler_parameter>>
      texture_min_lod = {GL_TEXTURE_MIN_LOD};
#endif

#ifdef GL_TEXTURE_RECTANGLE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::texture_target, oglplus::internal_format_target>>
      texture_rectangle = {GL_TEXTURE_RECTANGLE};
#endif

#ifdef GL_TEXTURE_SHADOW
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      texture_shadow = {GL_TEXTURE_SHADOW};
#endif

#ifdef GL_TEXTURE_SWIZZLE_A
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::texture_parameter, oglplus::texture_swizzle_coord>>
      texture_swizzle_a = {GL_TEXTURE_SWIZZLE_A};
#endif

#ifdef GL_TEXTURE_SWIZZLE_B
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::texture_parameter, oglplus::texture_swizzle_coord>>
      texture_swizzle_b = {GL_TEXTURE_SWIZZLE_B};
#endif

#ifdef GL_TEXTURE_SWIZZLE_G
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::texture_parameter, oglplus::texture_swizzle_coord>>
      texture_swizzle_g = {GL_TEXTURE_SWIZZLE_G};
#endif

#ifdef GL_TEXTURE_SWIZZLE_R
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::texture_parameter, oglplus::texture_swizzle_coord>>
      texture_swizzle_r = {GL_TEXTURE_SWIZZLE_R};
#endif

#ifdef GL_TEXTURE_SWIZZLE_RGBA
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::texture_parameter, oglplus::texture_swizzle_coord>>
      texture_swizzle_rgba = {GL_TEXTURE_SWIZZLE_RGBA};
#endif

#ifdef GL_TEXTURE_TARGET
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::texture_parameter>>
      texture_target = {GL_TEXTURE_TARGET};
#endif

#ifdef GL_TEXTURE_UPDATE_BARRIER_BIT
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::memory_barrier_bits>>
      texture_update_barrier_bit = {GL_TEXTURE_UPDATE_BARRIER_BIT};
#endif

#ifdef GL_TEXTURE_VIEW
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      texture_view = {GL_TEXTURE_VIEW};
#endif

#ifdef GL_TEXTURE_VIEW_MIN_LAYER
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::texture_parameter>>
      texture_view_min_layer = {GL_TEXTURE_VIEW_MIN_LAYER};
#endif

#ifdef GL_TEXTURE_VIEW_MIN_LEVEL
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::texture_parameter>>
      texture_view_min_level = {GL_TEXTURE_VIEW_MIN_LEVEL};
#endif

#ifdef GL_TEXTURE_VIEW_NUM_LAYERS
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::texture_parameter>>
      texture_view_num_layers = {GL_TEXTURE_VIEW_NUM_LAYERS};
#endif

#ifdef GL_TEXTURE_VIEW_NUM_LEVELS
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::texture_parameter>>
      texture_view_num_levels = {GL_TEXTURE_VIEW_NUM_LEVELS};
#endif

#ifdef GL_TEXTURE_WRAP_R
    static constexpr const enum_value<
      GLenum,
      mp_list<
        oglplus::texture_wrap_coord,
        oglplus::sampler_parameter,
        oglplus::texture_parameter>>
      texture_wrap_r = {GL_TEXTURE_WRAP_R};
#endif

#ifdef GL_TEXTURE_WRAP_S
    static constexpr const enum_value<
      GLenum,
      mp_list<
        oglplus::texture_wrap_coord,
        oglplus::sampler_parameter,
        oglplus::texture_parameter>>
      texture_wrap_s = {GL_TEXTURE_WRAP_S};
#endif

#ifdef GL_TEXTURE_WRAP_T
    static constexpr const enum_value<
      GLenum,
      mp_list<
        oglplus::texture_wrap_coord,
        oglplus::sampler_parameter,
        oglplus::texture_parameter>>
      texture_wrap_t = {GL_TEXTURE_WRAP_T};
#endif

#ifdef GL_TIME_ELAPSED
    static constexpr const enum_value<GLenum, mp_list<oglplus::query_target>>
      time_elapsed = {GL_TIME_ELAPSED};
#endif

#ifdef GL_TIMEOUT_EXPIRED
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::sync_wait_result>>
      timeout_expired = {GL_TIMEOUT_EXPIRED};
#endif

#ifdef GL_TIMESTAMP
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::query_target, oglplus::numeric_query>>
      timestamp = {GL_TIMESTAMP};
#endif

#ifdef GL_TOP_LEVEL_ARRAY_SIZE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_resource_property>>
      top_level_array_size = {GL_TOP_LEVEL_ARRAY_SIZE};
#endif

#ifdef GL_TOP_LEVEL_ARRAY_STRIDE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_resource_property>>
      top_level_array_stride = {GL_TOP_LEVEL_ARRAY_STRIDE};
#endif

#ifdef GL_TRANSFORM_FEEDBACK
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::object_type, oglplus::transform_feedback_target>>
      transform_feedback = {GL_TRANSFORM_FEEDBACK};
#endif

#ifdef GL_TRANSFORM_FEEDBACK_ACTIVE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::transform_feedback_parameter>>
      transform_feedback_active = {GL_TRANSFORM_FEEDBACK_ACTIVE};
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BARRIER_BIT
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::memory_barrier_bits>>
      transform_feedback_barrier_bit = {GL_TRANSFORM_FEEDBACK_BARRIER_BIT};
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BINDING
    static constexpr const enum_value<GLenum, mp_list<oglplus::binding_query>>
      transform_feedback_binding = {GL_TRANSFORM_FEEDBACK_BINDING};
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BUFFER
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::buffer_indexed_target, oglplus::buffer_target>>
      transform_feedback_buffer = {GL_TRANSFORM_FEEDBACK_BUFFER};
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_BINDING
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::transform_feedback_parameter, oglplus::binding_query>>
      transform_feedback_buffer_binding = {
        GL_TRANSFORM_FEEDBACK_BUFFER_BINDING};
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_INDEX
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_resource_property>>
      transform_feedback_buffer_index = {GL_TRANSFORM_FEEDBACK_BUFFER_INDEX};
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_MODE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_parameter>>
      transform_feedback_buffer_mode = {GL_TRANSFORM_FEEDBACK_BUFFER_MODE};
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::transform_feedback_parameter, oglplus::numeric_query>>
      transform_feedback_buffer_size = {GL_TRANSFORM_FEEDBACK_BUFFER_SIZE};
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::transform_feedback_parameter, oglplus::numeric_query>>
      transform_feedback_buffer_start = {GL_TRANSFORM_FEEDBACK_BUFFER_START};
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_resource_property>>
      transform_feedback_buffer_stride = {GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE};
#endif

#ifdef GL_TRANSFORM_FEEDBACK_OVERFLOW_ARB
    static constexpr const enum_value<GLenum, mp_list<oglplus::query_target>>
      transform_feedback_overflow = {GL_TRANSFORM_FEEDBACK_OVERFLOW_ARB};
#endif

#ifdef GL_TRANSFORM_FEEDBACK_PAUSED
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::transform_feedback_parameter>>
      transform_feedback_paused = {GL_TRANSFORM_FEEDBACK_PAUSED};
#endif

#ifdef GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN
    static constexpr const enum_value<GLenum, mp_list<oglplus::query_target>>
      transform_feedback_primitives_written = {
        GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN};
#endif

#ifdef GL_TRANSFORM_FEEDBACK_STREAM_OVERFLOW_ARB
    static constexpr const enum_value<GLenum, mp_list<oglplus::query_target>>
      transform_feedback_stream_overflow = {
        GL_TRANSFORM_FEEDBACK_STREAM_OVERFLOW_ARB};
#endif

#ifdef GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_parameter>>
      transform_feedback_varying_max_length = {
        GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH};
#endif

#ifdef GL_TRANSFORM_FEEDBACK_VARYINGS
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_parameter>>
      transform_feedback_varyings = {GL_TRANSFORM_FEEDBACK_VARYINGS};
#endif

#ifdef GL_TRANSFORM_FEEDEBACK_VARYING
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_interface>>
      transform_feedeback_varying = {GL_TRANSFORM_FEEDEBACK_VARYING};
#endif

#ifdef GL_TRANSLATE_2D_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::path_transform_type_nv>>
      translate_2d_nv = {GL_TRANSLATE_2D_NV};
#endif

#ifdef GL_TRANSLATE_3D_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::path_transform_type_nv>>
      translate_3d_nv = {GL_TRANSLATE_3D_NV};
#endif

#ifdef GL_TRANSLATE_X_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::path_transform_type_nv>>
      translate_x_nv = {GL_TRANSLATE_X_NV};
#endif

#ifdef GL_TRANSLATE_Y_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::path_transform_type_nv>>
      translate_y_nv = {GL_TRANSLATE_Y_NV};
#endif

#ifdef GL_TRANSPOSE_AFFINE_2D_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::path_transform_type_nv>>
      transpose_affine_2d_nv = {GL_TRANSPOSE_AFFINE_2D_NV};
#endif

#ifdef GL_TRANSPOSE_AFFINE_3D_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::path_transform_type_nv>>
      transpose_affine_3d_nv = {GL_TRANSPOSE_AFFINE_3D_NV};
#endif

#ifdef GL_TRIANGLE_FAN
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::primitive_type, oglplus::old_primitive_type>>
      triangle_fan = {GL_TRIANGLE_FAN};
#endif

#ifdef GL_TRIANGLE_STRIP
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::primitive_type, oglplus::old_primitive_type>>
      triangle_strip = {GL_TRIANGLE_STRIP};
#endif

#ifdef GL_TRIANGLE_STRIP_ADJACENCY
    static constexpr const enum_value<GLenum, mp_list<oglplus::primitive_type>>
      triangle_strip_adjacency = {GL_TRIANGLE_STRIP_ADJACENCY};
#endif

#ifdef GL_TRIANGLES
    static constexpr const enum_value<
      GLenum,
      mp_list<
        oglplus::primitive_type,
        oglplus::old_primitive_type,
        oglplus::transform_feedback_primitive_type,
        oglplus::tess_gen_primitive_type>>
      triangles = {GL_TRIANGLES};
#endif

#ifdef GL_TRIANGLES_ADJACENCY
    static constexpr const enum_value<GLenum, mp_list<oglplus::primitive_type>>
      triangles_adjacency = {GL_TRIANGLES_ADJACENCY};
#endif

#ifdef GL_TRIANGULAR_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::path_cap_style_nv>>
      triangular_nv = {GL_TRIANGULAR_NV};
#endif

#ifdef GL_TRUE
    static constexpr const enum_value<GLboolean, mp_list<oglplus::true_false>>
      true_ = {GL_TRUE};
#endif

#ifdef GL_UNIFORM
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_interface>>
      uniform = {GL_UNIFORM};
#endif

#ifdef GL_UNIFORM_ADDRESS_COMMAND_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::command_token_nv>>
      uniform_address_command_nv = {GL_UNIFORM_ADDRESS_COMMAND_NV};
#endif

#ifdef GL_UNIFORM_BARRIER_BIT
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::memory_barrier_bits>>
      uniform_barrier_bit = {GL_UNIFORM_BARRIER_BIT};
#endif

#ifdef GL_UNIFORM_BLOCK
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_interface>>
      uniform_block = {GL_UNIFORM_BLOCK};
#endif

#ifdef GL_UNIFORM_BUFFER
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::buffer_indexed_target, oglplus::buffer_target>>
      uniform_buffer = {GL_UNIFORM_BUFFER};
#endif

#ifdef GL_UNIFORM_BUFFER_ADDRESS_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::unified_array_address_nv>>
      uniform_buffer_address_nv = {GL_UNIFORM_BUFFER_ADDRESS_NV};
#endif

#ifdef GL_UNIFORM_BUFFER_BINDING
    static constexpr const enum_value<GLenum, mp_list<oglplus::binding_query>>
      uniform_buffer_binding = {GL_UNIFORM_BUFFER_BINDING};
#endif

#ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      uniform_buffer_offset_alignment = {GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT};
#endif

#ifdef GL_UNIFORM_BUFFER_SIZE
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      uniform_buffer_size = {GL_UNIFORM_BUFFER_SIZE};
#endif

#ifdef GL_UNIFORM_BUFFER_START
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      uniform_buffer_start = {GL_UNIFORM_BUFFER_START};
#endif

#ifdef GL_UNIFORM_BUFFER_UNIFIED_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::client_capability>>
      uniform_buffer_unified_nv = {GL_UNIFORM_BUFFER_UNIFIED_NV};
#endif

#ifdef GL_UNKNOWN_CONTEXT_RESET
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::graphics_reset_status>>
      unknown_context_reset = {GL_UNKNOWN_CONTEXT_RESET};
#endif

#ifdef GL_UNPACK_ALIGNMENT
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::numeric_query, oglplus::pixel_parameter>>
      unpack_alignment = {GL_UNPACK_ALIGNMENT};
#endif

#ifdef GL_UNPACK_COMPRESSED_BLOCK_DEPTH
    static constexpr const enum_value<GLenum, mp_list<oglplus::pixel_parameter>>
      unpack_compressed_block_depth = {GL_UNPACK_COMPRESSED_BLOCK_DEPTH};
#endif

#ifdef GL_UNPACK_COMPRESSED_BLOCK_HEIGHT
    static constexpr const enum_value<GLenum, mp_list<oglplus::pixel_parameter>>
      unpack_compressed_block_height = {GL_UNPACK_COMPRESSED_BLOCK_HEIGHT};
#endif

#ifdef GL_UNPACK_COMPRESSED_BLOCK_SIZE
    static constexpr const enum_value<GLenum, mp_list<oglplus::pixel_parameter>>
      unpack_compressed_block_size = {GL_UNPACK_COMPRESSED_BLOCK_SIZE};
#endif

#ifdef GL_UNPACK_COMPRESSED_BLOCK_WIDTH
    static constexpr const enum_value<GLenum, mp_list<oglplus::pixel_parameter>>
      unpack_compressed_block_width = {GL_UNPACK_COMPRESSED_BLOCK_WIDTH};
#endif

#ifdef GL_UNPACK_IMAGE_HEIGHT
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::numeric_query, oglplus::pixel_parameter>>
      unpack_image_height = {GL_UNPACK_IMAGE_HEIGHT};
#endif

#ifdef GL_UNPACK_LSB_FIRST
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::numeric_query, oglplus::pixel_parameter>>
      unpack_lsb_first = {GL_UNPACK_LSB_FIRST};
#endif

#ifdef GL_UNPACK_ROW_LENGTH
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::numeric_query, oglplus::pixel_parameter>>
      unpack_row_length = {GL_UNPACK_ROW_LENGTH};
#endif

#ifdef GL_UNPACK_SKIP_IMAGES
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::numeric_query, oglplus::pixel_parameter>>
      unpack_skip_images = {GL_UNPACK_SKIP_IMAGES};
#endif

#ifdef GL_UNPACK_SKIP_PIXELS
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::numeric_query, oglplus::pixel_parameter>>
      unpack_skip_pixels = {GL_UNPACK_SKIP_PIXELS};
#endif

#ifdef GL_UNPACK_SKIP_ROWS
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::numeric_query, oglplus::pixel_parameter>>
      unpack_skip_rows = {GL_UNPACK_SKIP_ROWS};
#endif

#ifdef GL_UNPACK_SWAP_BYTES
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::numeric_query, oglplus::pixel_parameter>>
      unpack_swap_bytes = {GL_UNPACK_SWAP_BYTES};
#endif

#ifdef GL_UNSIGNALED
    static constexpr const enum_value<GLenum, mp_list<oglplus::sync_status>>
      unsignaled = {GL_UNSIGNALED};
#endif

#ifdef GL_UNSIGNED_BYTE
    static constexpr const enum_value<
      GLenum,
      mp_list<
        oglplus::index_type,
        oglplus::pixel_data_type,
        oglplus::data_type>>
      unsigned_byte = {GL_UNSIGNED_BYTE};
#endif

#ifdef GL_UNSIGNED_BYTE_2_3_3_REV
    static constexpr const enum_value<GLenum, mp_list<oglplus::pixel_data_type>>
      unsigned_byte_2_3_3_rev = {GL_UNSIGNED_BYTE_2_3_3_REV};
#endif

#ifdef GL_UNSIGNED_BYTE_3_3_2
    static constexpr const enum_value<GLenum, mp_list<oglplus::pixel_data_type>>
      unsigned_byte_3_3_2 = {GL_UNSIGNED_BYTE_3_3_2};
#endif

#ifdef GL_UNSIGNED_INT
    static constexpr const enum_value<
      GLenum,
      mp_list<
        oglplus::index_type,
        oglplus::sl_data_type,
        oglplus::pixel_data_type,
        oglplus::data_type>>
      unsigned_int = {GL_UNSIGNED_INT};
#endif

#ifdef GL_UNSIGNED_INT_10_10_10_2
    static constexpr const enum_value<GLenum, mp_list<oglplus::pixel_data_type>>
      unsigned_int_10_10_10_2 = {GL_UNSIGNED_INT_10_10_10_2};
#endif

#ifdef GL_UNSIGNED_INT_10F_11F_11F_REV
    static constexpr const enum_value<GLenum, mp_list<oglplus::pixel_data_type>>
      unsigned_int_10f_11f_11f_rev = {GL_UNSIGNED_INT_10F_11F_11F_REV};
#endif

#ifdef GL_UNSIGNED_INT_24_8
    static constexpr const enum_value<GLenum, mp_list<oglplus::pixel_data_type>>
      unsigned_int_24_8 = {GL_UNSIGNED_INT_24_8};
#endif

#ifdef GL_UNSIGNED_INT_2_10_10_10_REV
    static constexpr const enum_value<GLenum, mp_list<oglplus::pixel_data_type>>
      unsigned_int_2_10_10_10_rev = {GL_UNSIGNED_INT_2_10_10_10_REV};
#endif

#ifdef GL_UNSIGNED_INT_5_9_9_9_REV
    static constexpr const enum_value<GLenum, mp_list<oglplus::pixel_data_type>>
      unsigned_int_5_9_9_9_rev = {GL_UNSIGNED_INT_5_9_9_9_REV};
#endif

#ifdef GL_UNSIGNED_INT_8_8_8_8
    static constexpr const enum_value<GLenum, mp_list<oglplus::pixel_data_type>>
      unsigned_int_8_8_8_8 = {GL_UNSIGNED_INT_8_8_8_8};
#endif

#ifdef GL_UNSIGNED_INT_8_8_8_8_REV
    static constexpr const enum_value<GLenum, mp_list<oglplus::pixel_data_type>>
      unsigned_int_8_8_8_8_rev = {GL_UNSIGNED_INT_8_8_8_8_REV};
#endif

#ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      unsigned_int_atomic_counter = {GL_UNSIGNED_INT_ATOMIC_COUNTER};
#endif

#ifdef GL_UNSIGNED_INT_IMAGE_1D
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      unsigned_int_image_1d = {GL_UNSIGNED_INT_IMAGE_1D};
#endif

#ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      unsigned_int_image_1d_array = {GL_UNSIGNED_INT_IMAGE_1D_ARRAY};
#endif

#ifdef GL_UNSIGNED_INT_IMAGE_2D
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      unsigned_int_image_2d = {GL_UNSIGNED_INT_IMAGE_2D};
#endif

#ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      unsigned_int_image_2d_array = {GL_UNSIGNED_INT_IMAGE_2D_ARRAY};
#endif

#ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      unsigned_int_image_2d_multisample = {
        GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE};
#endif

#ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      unsigned_int_image_2d_multisample_array = {
        GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY};
#endif

#ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      unsigned_int_image_2d_rect = {GL_UNSIGNED_INT_IMAGE_2D_RECT};
#endif

#ifdef GL_UNSIGNED_INT_IMAGE_3D
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      unsigned_int_image_3d = {GL_UNSIGNED_INT_IMAGE_3D};
#endif

#ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      unsigned_int_image_buffer = {GL_UNSIGNED_INT_IMAGE_BUFFER};
#endif

#ifdef GL_UNSIGNED_INT_IMAGE_CUBE
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      unsigned_int_image_cube = {GL_UNSIGNED_INT_IMAGE_CUBE};
#endif

#ifdef GL_UNSIGNED_INT_SAMPLER_1D
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      unsigned_int_sampler_1d = {GL_UNSIGNED_INT_SAMPLER_1D};
#endif

#ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      unsigned_int_sampler_1d_array = {GL_UNSIGNED_INT_SAMPLER_1D_ARRAY};
#endif

#ifdef GL_UNSIGNED_INT_SAMPLER_2D
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      unsigned_int_sampler_2d = {GL_UNSIGNED_INT_SAMPLER_2D};
#endif

#ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      unsigned_int_sampler_2d_array = {GL_UNSIGNED_INT_SAMPLER_2D_ARRAY};
#endif

#ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      unsigned_int_sampler_2d_multisample = {
        GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE};
#endif

#ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      unsigned_int_sampler_2d_multisample_array = {
        GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY};
#endif

#ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      unsigned_int_sampler_2d_rect = {GL_UNSIGNED_INT_SAMPLER_2D_RECT};
#endif

#ifdef GL_UNSIGNED_INT_SAMPLER_3D
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      unsigned_int_sampler_3d = {GL_UNSIGNED_INT_SAMPLER_3D};
#endif

#ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      unsigned_int_sampler_buffer = {GL_UNSIGNED_INT_SAMPLER_BUFFER};
#endif

#ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      unsigned_int_sampler_cube = {GL_UNSIGNED_INT_SAMPLER_CUBE};
#endif

#ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      unsigned_int_sampler_cube_map_array = {
        GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY};
#endif

#ifdef GL_UNSIGNED_INT_VEC2
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      unsigned_int_vec2 = {GL_UNSIGNED_INT_VEC2};
#endif

#ifdef GL_UNSIGNED_INT_VEC3
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      unsigned_int_vec3 = {GL_UNSIGNED_INT_VEC3};
#endif

#ifdef GL_UNSIGNED_INT_VEC4
    static constexpr const enum_value<GLenum, mp_list<oglplus::sl_data_type>>
      unsigned_int_vec4 = {GL_UNSIGNED_INT_VEC4};
#endif

#ifdef GL_UNSIGNED_SHORT
    static constexpr const enum_value<
      GLenum,
      mp_list<
        oglplus::index_type,
        oglplus::pixel_data_type,
        oglplus::data_type>>
      unsigned_short = {GL_UNSIGNED_SHORT};
#endif

#ifdef GL_UNSIGNED_SHORT_1_5_5_5_REV
    static constexpr const enum_value<GLenum, mp_list<oglplus::pixel_data_type>>
      unsigned_short_1_5_5_5_rev = {GL_UNSIGNED_SHORT_1_5_5_5_REV};
#endif

#ifdef GL_UNSIGNED_SHORT_4_4_4_4
    static constexpr const enum_value<GLenum, mp_list<oglplus::pixel_data_type>>
      unsigned_short_4_4_4_4 = {GL_UNSIGNED_SHORT_4_4_4_4};
#endif

#ifdef GL_UNSIGNED_SHORT_4_4_4_4_REV
    static constexpr const enum_value<GLenum, mp_list<oglplus::pixel_data_type>>
      unsigned_short_4_4_4_4_rev = {GL_UNSIGNED_SHORT_4_4_4_4_REV};
#endif

#ifdef GL_UNSIGNED_SHORT_5_5_5_1
    static constexpr const enum_value<GLenum, mp_list<oglplus::pixel_data_type>>
      unsigned_short_5_5_5_1 = {GL_UNSIGNED_SHORT_5_5_5_1};
#endif

#ifdef GL_UNSIGNED_SHORT_5_6_5
    static constexpr const enum_value<GLenum, mp_list<oglplus::pixel_data_type>>
      unsigned_short_5_6_5 = {GL_UNSIGNED_SHORT_5_6_5};
#endif

#ifdef GL_UNSIGNED_SHORT_5_6_5_REV
    static constexpr const enum_value<GLenum, mp_list<oglplus::pixel_data_type>>
      unsigned_short_5_6_5_rev = {GL_UNSIGNED_SHORT_5_6_5_REV};
#endif

#ifdef GL_UPPER_LEFT
    static constexpr const enum_value<GLenum, mp_list<oglplus::clip_origin>>
      upper_left = {GL_UPPER_LEFT};
#endif

#ifdef GL_USE_MISSING_GLYPH_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::path_missing_glyph_nv>>
      use_missing_glyph_nv = {GL_USE_MISSING_GLYPH_NV};
#endif

#ifdef GL_UTF16_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::path_text_encoding_nv>>
      utf16_nv = {GL_UTF16_NV};
#endif

#ifdef GL_UTF8_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::path_text_encoding_nv>>
      utf8_nv = {GL_UTF8_NV};
#endif

#ifdef GL_VALIDATE_STATUS
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_parameter>>
      validate_status = {GL_VALIDATE_STATUS};
#endif

#ifdef GL_VENDOR
    static constexpr const enum_value<GLenum, mp_list<oglplus::string_query>>
      vendor = {GL_VENDOR};
#endif

#ifdef GL_VERSION
    static constexpr const enum_value<GLenum, mp_list<oglplus::string_query>>
      version = {GL_VERSION};
#endif

#ifdef GL_VERTEX_ARRAY
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::client_capability, oglplus::object_type>>
      vertex_array = {GL_VERTEX_ARRAY};
#endif

#ifdef GL_VERTEX_ARRAY_ADDRESS_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::unified_array_address_nv>>
      vertex_array_address_nv = {GL_VERTEX_ARRAY_ADDRESS_NV};
#endif

#ifdef GL_VERTEX_ARRAY_BINDING
    static constexpr const enum_value<GLenum, mp_list<oglplus::binding_query>>
      vertex_array_binding = {GL_VERTEX_ARRAY_BINDING};
#endif

#ifdef GL_VERTEX_ATTRIB_ARRAY_ADDRESS_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::unified_array_address_nv>>
      vertex_attrib_array_address_nv = {GL_VERTEX_ATTRIB_ARRAY_ADDRESS_NV};
#endif

#ifdef GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::memory_barrier_bits>>
      vertex_attrib_array_barrier_bit = {GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT};
#endif

#ifdef GL_VERTEX_ATTRIB_ARRAY_UNIFIED_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::client_capability>>
      vertex_attrib_array_unified_nv = {GL_VERTEX_ATTRIB_ARRAY_UNIFIED_NV};
#endif

#ifdef GL_VERTEX_SHADER
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::shader_type, oglplus::program_pipeline_parameter>>
      vertex_shader = {GL_VERTEX_SHADER};
#endif

#ifdef GL_VERTEX_SHADER_BIT
    static constexpr const enum_value<
      GLbitfield,
      mp_list<oglplus::program_pipeline_stage>>
      vertex_shader_bit = {GL_VERTEX_SHADER_BIT};
#endif

#ifdef GL_VERTEX_SHADER_INVOCATIONS_ARB
    static constexpr const enum_value<GLenum, mp_list<oglplus::query_target>>
      vertex_shader_invocations = {GL_VERTEX_SHADER_INVOCATIONS_ARB};
#endif

#ifdef GL_VERTEX_SUBROUTINE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_interface>>
      vertex_subroutine = {GL_VERTEX_SUBROUTINE};
#endif

#ifdef GL_VERTEX_SUBROUTINE_UNIFORM
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::program_interface>>
      vertex_subroutine_uniform = {GL_VERTEX_SUBROUTINE_UNIFORM};
#endif

#ifdef GL_VERTEX_TEXTURE
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      vertex_texture = {GL_VERTEX_TEXTURE};
#endif

#ifdef GL_VERTICAL_LINE_TO_NV
    static constexpr const enum_value<
      GLubyte,
      mp_list<oglplus::path_command_nv>>
      vertical_line_to_nv = {GL_VERTICAL_LINE_TO_NV};
#endif

#ifdef GL_VERTICES_SUBMITTED_ARB
    static constexpr const enum_value<GLenum, mp_list<oglplus::query_target>>
      vertices_submitted = {GL_VERTICES_SUBMITTED_ARB};
#endif

#ifdef GL_VIEW_CLASS_128_BITS
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::view_compatibility_class>>
      view_class_128_bits = {GL_VIEW_CLASS_128_BITS};
#endif

#ifdef GL_VIEW_CLASS_16_BITS
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::view_compatibility_class>>
      view_class_16_bits = {GL_VIEW_CLASS_16_BITS};
#endif

#ifdef GL_VIEW_CLASS_24_BITS
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::view_compatibility_class>>
      view_class_24_bits = {GL_VIEW_CLASS_24_BITS};
#endif

#ifdef GL_VIEW_CLASS_32_BITS
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::view_compatibility_class>>
      view_class_32_bits = {GL_VIEW_CLASS_32_BITS};
#endif

#ifdef GL_VIEW_CLASS_48_BITS
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::view_compatibility_class>>
      view_class_48_bits = {GL_VIEW_CLASS_48_BITS};
#endif

#ifdef GL_VIEW_CLASS_64_BITS
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::view_compatibility_class>>
      view_class_64_bits = {GL_VIEW_CLASS_64_BITS};
#endif

#ifdef GL_VIEW_CLASS_8_BITS
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::view_compatibility_class>>
      view_class_8_bits = {GL_VIEW_CLASS_8_BITS};
#endif

#ifdef GL_VIEW_CLASS_96_BITS
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::view_compatibility_class>>
      view_class_96_bits = {GL_VIEW_CLASS_96_BITS};
#endif

#ifdef GL_VIEW_CLASS_BPTC_FLOAT
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::view_compatibility_class>>
      view_class_bptc_float = {GL_VIEW_CLASS_BPTC_FLOAT};
#endif

#ifdef GL_VIEW_CLASS_BPTC_UNORM
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::view_compatibility_class>>
      view_class_bptc_unorm = {GL_VIEW_CLASS_BPTC_UNORM};
#endif

#ifdef GL_VIEW_CLASS_RGTC1_RED
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::view_compatibility_class>>
      view_class_rgtc1_red = {GL_VIEW_CLASS_RGTC1_RED};
#endif

#ifdef GL_VIEW_CLASS_RGTC2_RG
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::view_compatibility_class>>
      view_class_rgtc2_rg = {GL_VIEW_CLASS_RGTC2_RG};
#endif

#ifdef GL_VIEW_CLASS_S3TC_DXT1_RGB
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::view_compatibility_class>>
      view_class_s3tc_dxt1_rgb = {GL_VIEW_CLASS_S3TC_DXT1_RGB};
#endif

#ifdef GL_VIEW_CLASS_S3TC_DXT1_RGBA
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::view_compatibility_class>>
      view_class_s3tc_dxt1_rgba = {GL_VIEW_CLASS_S3TC_DXT1_RGBA};
#endif

#ifdef GL_VIEW_CLASS_S3TC_DXT3_RGBA
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::view_compatibility_class>>
      view_class_s3tc_dxt3_rgba = {GL_VIEW_CLASS_S3TC_DXT3_RGBA};
#endif

#ifdef GL_VIEW_CLASS_S3TC_DXT5_RGBA
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::view_compatibility_class>>
      view_class_s3tc_dxt5_rgba = {GL_VIEW_CLASS_S3TC_DXT5_RGBA};
#endif

#ifdef GL_VIEW_COMPATIBILITY_CLASS
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::internal_format_parameter>>
      view_compatibility_class = {GL_VIEW_COMPATIBILITY_CLASS};
#endif

#ifdef GL_VIEWPORT
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      viewport = {GL_VIEWPORT};
#endif

#ifdef GL_VIEWPORT_BOUNDS_RANGE
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      viewport_bounds_range = {GL_VIEWPORT_BOUNDS_RANGE};
#endif

#ifdef GL_VIEWPORT_COMMAND_NV
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::command_token_nv>>
      viewport_command_nv = {GL_VIEWPORT_COMMAND_NV};
#endif

#ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      viewport_index_provoking_vertex = {GL_VIEWPORT_INDEX_PROVOKING_VERTEX};
#endif

#ifdef GL_VIEWPORT_SUBPIXEL_BITS
    static constexpr const enum_value<GLenum, mp_list<oglplus::numeric_query>>
      viewport_subpixel_bits = {GL_VIEWPORT_SUBPIXEL_BITS};
#endif

#ifdef GL_WAIT_FAILED
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::sync_wait_result>>
      wait_failed = {GL_WAIT_FAILED};
#endif

#ifdef GL_WRITE_ONLY
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::access_specifier>>
      write_only = {GL_WRITE_ONLY};
#endif

#ifdef GL_XOR
    static constexpr const enum_value<
      GLenum,
      mp_list<oglplus::color_logic_operation>>
      xor_ = {GL_XOR};
#endif

#ifdef GL_ZERO
    static constexpr const enum_value<
      GLenum,
      mp_list<
        oglplus::blend_function,
        oglplus::texture_swizzle_mode,
        oglplus::stencil_operation>>
      zero = {GL_ZERO};
#endif

#ifdef GL_ZERO_TO_ONE
    static constexpr const enum_value<GLenum, mp_list<oglplus::clip_depth_mode>>
      zero_to_one = {GL_ZERO_TO_ONE};
#endif

}; // struct enum_values
} // namespace oglplus

#endif // OGLPLUS_GL_ENUM_VALUES_HPP
