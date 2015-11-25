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

#include "types.hpp"
#include "../utils/mp_list.hpp"

namespace oglplus {
struct enum_values {

#ifdef GL_ACCUM_ADJACENT_PAIRS_NV
static constexpr const enum_value<
	GLenum,
	GL_ACCUM_ADJACENT_PAIRS_NV,
	mp_list<oglplus::path_list_mode_nv>
> accum_adjacent_pairs_nv = {};
#endif

#ifdef GL_ACTIVE_ATTRIBUTE_MAX_LENGTH
static constexpr const enum_value<
	GLenum,
	GL_ACTIVE_ATTRIBUTE_MAX_LENGTH,
	mp_list<oglplus::program_parameter>
> active_attribute_max_length = {};
#endif

#ifdef GL_ACTIVE_ATTRIBUTES
static constexpr const enum_value<
	GLenum,
	GL_ACTIVE_ATTRIBUTES,
	mp_list<oglplus::program_parameter>
> active_attributes = {};
#endif

#ifdef GL_ACTIVE_PROGRAM
static constexpr const enum_value<
	GLenum,
	GL_ACTIVE_PROGRAM,
	mp_list<oglplus::program_pipeline_parameter>
> active_program = {};
#endif

#ifdef GL_ACTIVE_UNIFORM_MAX_LENGTH
static constexpr const enum_value<
	GLenum,
	GL_ACTIVE_UNIFORM_MAX_LENGTH,
	mp_list<oglplus::program_parameter>
> active_uniform_max_length = {};
#endif

#ifdef GL_ACTIVE_UNIFORMS
static constexpr const enum_value<
	GLenum,
	GL_ACTIVE_UNIFORMS,
	mp_list<oglplus::program_parameter>
> active_uniforms = {};
#endif

#ifdef GL_ACTIVE_VARIABLES
static constexpr const enum_value<
	GLenum,
	GL_ACTIVE_VARIABLES,
	mp_list<oglplus::program_resource_property>
> active_variables = {};
#endif

#ifdef GL_ADJACENT_PAIRS_NV
static constexpr const enum_value<
	GLenum,
	GL_ADJACENT_PAIRS_NV,
	mp_list<oglplus::path_list_mode_nv>
> adjacent_pairs_nv = {};
#endif

#ifdef GL_AFFINE_2D_NV
static constexpr const enum_value<
	GLenum,
	GL_AFFINE_2D_NV,
	mp_list<oglplus::path_transform_type_nv>
> affine_2d_nv = {};
#endif

#ifdef GL_AFFINE_3D_NV
static constexpr const enum_value<
	GLenum,
	GL_AFFINE_3D_NV,
	mp_list<oglplus::path_transform_type_nv>
> affine_3d_nv = {};
#endif

#ifdef GL_ALIASED_LINE_WIDTH_RANGE
static constexpr const enum_value<
	GLenum,
	GL_ALIASED_LINE_WIDTH_RANGE,
	mp_list<oglplus::numeric_query>
> aliased_line_width_range = {};
#endif

#ifdef GL_ALL_BARRIER_BITS
static constexpr const enum_value<
	GLbitfield,
	GL_ALL_BARRIER_BITS,
	mp_list<oglplus::memory_barrier_bits>
> all_barrier_bits = {};
#endif

#ifdef GL_ALL_SHADER_BITS
static constexpr const enum_value<
	GLbitfield,
	GL_ALL_SHADER_BITS,
	mp_list<oglplus::program_pipeline_stage>
> all_shader_bits = {};
#endif

#ifdef GL_ALPHA
static constexpr const enum_value<
	GLenum,
	GL_ALPHA,
	mp_list<oglplus::path_color_format_nv,oglplus::texture_swizzle_mode>
> alpha = {};
#endif

#ifdef GL_ALREADY_SIGNALED
static constexpr const enum_value<
	GLenum,
	GL_ALREADY_SIGNALED,
	mp_list<oglplus::sync_wait_result>
> already_signaled = {};
#endif

#ifdef GL_ALWAYS
static constexpr const enum_value<
	GLenum,
	GL_ALWAYS,
	mp_list<oglplus::compare_function>
> always = {};
#endif

#ifdef GL_AND
static constexpr const enum_value<
	GLenum,
	GL_AND,
	mp_list<oglplus::color_logic_operation>
> and_ = {};
#endif

#ifdef GL_AND_INVERTED
static constexpr const enum_value<
	GLenum,
	GL_AND_INVERTED,
	mp_list<oglplus::color_logic_operation>
> and_inverted = {};
#endif

#ifdef GL_AND_REVERSE
static constexpr const enum_value<
	GLenum,
	GL_AND_REVERSE,
	mp_list<oglplus::color_logic_operation>
> and_reverse = {};
#endif

#ifdef GL_ANY_SAMPLES_PASSED
static constexpr const enum_value<
	GLenum,
	GL_ANY_SAMPLES_PASSED,
	mp_list<oglplus::query_target>
> any_samples_passed = {};
#endif

#ifdef GL_ARC_TO_NV
static constexpr const enum_value<
	GLubyte,
	GL_ARC_TO_NV,
	mp_list<oglplus::path_command_nv>
> arc_to_nv = {};
#endif

#ifdef GL_ARRAY_BUFFER
static constexpr const enum_value<
	GLenum,
	GL_ARRAY_BUFFER,
	mp_list<oglplus::buffer_target>
> array_buffer = {};
#endif

#ifdef GL_ARRAY_BUFFER_BINDING
static constexpr const enum_value<
	GLenum,
	GL_ARRAY_BUFFER_BINDING,
	mp_list<oglplus::binding_query>
> array_buffer_binding = {};
#endif

#ifdef GL_ARRAY_SIZE
static constexpr const enum_value<
	GLenum,
	GL_ARRAY_SIZE,
	mp_list<oglplus::program_resource_property>
> array_size = {};
#endif

#ifdef GL_ARRAY_STRIDE
static constexpr const enum_value<
	GLenum,
	GL_ARRAY_STRIDE,
	mp_list<oglplus::program_resource_property>
> array_stride = {};
#endif

#ifdef GL_ATOMIC_COUNTER_BARRIER_BIT
static constexpr const enum_value<
	GLbitfield,
	GL_ATOMIC_COUNTER_BARRIER_BIT,
	mp_list<oglplus::memory_barrier_bits>
> atomic_counter_barrier_bit = {};
#endif

#ifdef GL_ATOMIC_COUNTER_BUFFER
static constexpr const enum_value<
	GLenum,
	GL_ATOMIC_COUNTER_BUFFER,
	mp_list<oglplus::buffer_indexed_target,oglplus::buffer_target,oglplus::program_interface>
> atomic_counter_buffer = {};
#endif

#ifdef GL_ATOMIC_COUNTER_BUFFER_BINDING
static constexpr const enum_value<
	GLenum,
	GL_ATOMIC_COUNTER_BUFFER_BINDING,
	mp_list<oglplus::binding_query>
> atomic_counter_buffer_binding = {};
#endif

#ifdef GL_ATOMIC_COUNTER_BUFFER_INDEX
static constexpr const enum_value<
	GLenum,
	GL_ATOMIC_COUNTER_BUFFER_INDEX,
	mp_list<oglplus::program_resource_property>
> atomic_counter_buffer_index = {};
#endif

#ifdef GL_ATTACHED_SHADERS
static constexpr const enum_value<
	GLenum,
	GL_ATTACHED_SHADERS,
	mp_list<oglplus::program_parameter>
> attached_shaders = {};
#endif

#ifdef GL_BACK
static constexpr const enum_value<
	GLenum,
	GL_BACK,
	mp_list<oglplus::color_buffer,oglplus::single_face,oglplus::face>
> back = {};
#endif

#ifdef GL_BACK_LEFT
static constexpr const enum_value<
	GLenum,
	GL_BACK_LEFT,
	mp_list<oglplus::color_buffer>
> back_left = {};
#endif

#ifdef GL_BACK_RIGHT
static constexpr const enum_value<
	GLenum,
	GL_BACK_RIGHT,
	mp_list<oglplus::color_buffer>
> back_right = {};
#endif

#ifdef GL_BEVEL_NV
static constexpr const enum_value<
	GLenum,
	GL_BEVEL_NV,
	mp_list<oglplus::path_join_style_nv>
> bevel_nv = {};
#endif

#ifdef GL_BGR
static constexpr const enum_value<
	GLenum,
	GL_BGR,
	mp_list<oglplus::pixel_data_format>
> bgr = {};
#endif

#ifdef GL_BGR_INTEGER
static constexpr const enum_value<
	GLenum,
	GL_BGR_INTEGER,
	mp_list<oglplus::pixel_data_format>
> bgr_integer = {};
#endif

#ifdef GL_BGRA
static constexpr const enum_value<
	GLenum,
	GL_BGRA,
	mp_list<oglplus::pixel_data_format>
> bgra = {};
#endif

#ifdef GL_BGRA_INTEGER
static constexpr const enum_value<
	GLenum,
	GL_BGRA_INTEGER,
	mp_list<oglplus::pixel_data_format>
> bgra_integer = {};
#endif

#ifdef GL_BLEND
static constexpr const enum_value<
	GLenum,
	GL_BLEND,
	mp_list<oglplus::capability>
> blend = {};
#endif

#ifdef GL_BLEND_ADVANCED_COHERENT_KHR
static constexpr const enum_value<
	GLenum,
	GL_BLEND_ADVANCED_COHERENT_KHR,
	mp_list<oglplus::capability>
> blend_advanced_coherent = {};
#endif

#ifdef GL_BLEND_COLOR
static constexpr const enum_value<
	GLenum,
	GL_BLEND_COLOR,
	mp_list<oglplus::numeric_query>
> blend_color = {};
#endif

#ifdef GL_BLEND_DST_ALPHA
static constexpr const enum_value<
	GLenum,
	GL_BLEND_DST_ALPHA,
	mp_list<oglplus::numeric_query>
> blend_dst_alpha = {};
#endif

#ifdef GL_BLEND_DST_RGB
static constexpr const enum_value<
	GLenum,
	GL_BLEND_DST_RGB,
	mp_list<oglplus::numeric_query>
> blend_dst_rgb = {};
#endif

#ifdef GL_BLEND_EQUATION_ALPHA
static constexpr const enum_value<
	GLenum,
	GL_BLEND_EQUATION_ALPHA,
	mp_list<oglplus::numeric_query>
> blend_equation_alpha = {};
#endif

#ifdef GL_BLEND_EQUATION_RGB
static constexpr const enum_value<
	GLenum,
	GL_BLEND_EQUATION_RGB,
	mp_list<oglplus::numeric_query>
> blend_equation_rgb = {};
#endif

#ifdef GL_BLEND_SRC_ALPHA
static constexpr const enum_value<
	GLenum,
	GL_BLEND_SRC_ALPHA,
	mp_list<oglplus::numeric_query>
> blend_src_alpha = {};
#endif

#ifdef GL_BLEND_SRC_RGB
static constexpr const enum_value<
	GLenum,
	GL_BLEND_SRC_RGB,
	mp_list<oglplus::numeric_query>
> blend_src_rgb = {};
#endif

#ifdef GL_BLOCK_INDEX
static constexpr const enum_value<
	GLenum,
	GL_BLOCK_INDEX,
	mp_list<oglplus::program_resource_property>
> block_index = {};
#endif

#ifdef GL_BLUE
static constexpr const enum_value<
	GLenum,
	GL_BLUE,
	mp_list<oglplus::texture_swizzle_mode,oglplus::pixel_data_format>
> blue = {};
#endif

#ifdef GL_BLUE_INTEGER
static constexpr const enum_value<
	GLenum,
	GL_BLUE_INTEGER,
	mp_list<oglplus::pixel_data_format>
> blue_integer = {};
#endif

#ifdef GL_BOLD_BIT_NV
static constexpr const enum_value<
	GLbitfield,
	GL_BOLD_BIT_NV,
	mp_list<oglplus::path_font_style_nv>
> bold_bit_nv = {};
#endif

#ifdef GL_BOOL
static constexpr const enum_value<
	GLenum,
	GL_BOOL,
	mp_list<oglplus::sl_data_type>
> bool_ = {};
#endif

#ifdef GL_BOOL_VEC2
static constexpr const enum_value<
	GLenum,
	GL_BOOL_VEC2,
	mp_list<oglplus::sl_data_type>
> bool_vec2 = {};
#endif

#ifdef GL_BOOL_VEC3
static constexpr const enum_value<
	GLenum,
	GL_BOOL_VEC3,
	mp_list<oglplus::sl_data_type>
> bool_vec3 = {};
#endif

#ifdef GL_BOOL_VEC4
static constexpr const enum_value<
	GLenum,
	GL_BOOL_VEC4,
	mp_list<oglplus::sl_data_type>
> bool_vec4 = {};
#endif

#ifdef GL_BOUNDING_BOX_NV
static constexpr const enum_value<
	GLenum,
	GL_BOUNDING_BOX_NV,
	mp_list<oglplus::path_stroke_cover_mode_nv,oglplus::path_fill_cover_mode_nv>
> bounding_box_nv = {};
#endif

#ifdef GL_BOUNDING_BOX_OF_BOUNDING_BOXES_NV
static constexpr const enum_value<
	GLenum,
	GL_BOUNDING_BOX_OF_BOUNDING_BOXES_NV,
	mp_list<oglplus::path_stroke_cover_mode_nv,oglplus::path_fill_cover_mode_nv>
> bounding_box_of_bounding_boxes_nv = {};
#endif

#ifdef GL_BUFFER
static constexpr const enum_value<
	GLenum,
	GL_BUFFER,
	mp_list<oglplus::object_type>
> buffer = {};
#endif

#ifdef GL_BUFFER_ACCESS
static constexpr const enum_value<
	GLenum,
	GL_BUFFER_ACCESS,
	mp_list<oglplus::buffer_parameter>
> buffer_access = {};
#endif

#ifdef GL_BUFFER_ACCESS_FLAGS
static constexpr const enum_value<
	GLenum,
	GL_BUFFER_ACCESS_FLAGS,
	mp_list<oglplus::buffer_parameter>
> buffer_access_flags = {};
#endif

#ifdef GL_BUFFER_BINDING
static constexpr const enum_value<
	GLenum,
	GL_BUFFER_BINDING,
	mp_list<oglplus::program_resource_property,oglplus::binding_query>
> buffer_binding = {};
#endif

#ifdef GL_BUFFER_DATA_SIZE
static constexpr const enum_value<
	GLenum,
	GL_BUFFER_DATA_SIZE,
	mp_list<oglplus::program_resource_property>
> buffer_data_size = {};
#endif

#ifdef GL_BUFFER_IMMUTABLE_STORAGE
static constexpr const enum_value<
	GLenum,
	GL_BUFFER_IMMUTABLE_STORAGE,
	mp_list<oglplus::buffer_parameter>
> buffer_immutable_storage = {};
#endif

#ifdef GL_BUFFER_MAP_LENGTH
static constexpr const enum_value<
	GLenum,
	GL_BUFFER_MAP_LENGTH,
	mp_list<oglplus::buffer_parameter>
> buffer_map_length = {};
#endif

#ifdef GL_BUFFER_MAP_OFFSET
static constexpr const enum_value<
	GLenum,
	GL_BUFFER_MAP_OFFSET,
	mp_list<oglplus::buffer_parameter>
> buffer_map_offset = {};
#endif

#ifdef GL_BUFFER_MAPPED
static constexpr const enum_value<
	GLenum,
	GL_BUFFER_MAPPED,
	mp_list<oglplus::buffer_parameter>
> buffer_mapped = {};
#endif

#ifdef GL_BUFFER_SIZE
static constexpr const enum_value<
	GLenum,
	GL_BUFFER_SIZE,
	mp_list<oglplus::buffer_parameter>
> buffer_size = {};
#endif

#ifdef GL_BUFFER_STORAGE_FLAGS
static constexpr const enum_value<
	GLenum,
	GL_BUFFER_STORAGE_FLAGS,
	mp_list<oglplus::buffer_parameter>
> buffer_storage_flags = {};
#endif

#ifdef GL_BUFFER_UPDATE_BARRIER_BIT
static constexpr const enum_value<
	GLbitfield,
	GL_BUFFER_UPDATE_BARRIER_BIT,
	mp_list<oglplus::memory_barrier_bits>
> buffer_update_barrier_bit = {};
#endif

#ifdef GL_BUFFER_USAGE
static constexpr const enum_value<
	GLenum,
	GL_BUFFER_USAGE,
	mp_list<oglplus::buffer_parameter>
> buffer_usage = {};
#endif

#ifdef GL_BUFFER_VARIABLE
static constexpr const enum_value<
	GLenum,
	GL_BUFFER_VARIABLE,
	mp_list<oglplus::program_interface>
> buffer_variable = {};
#endif

#ifdef GL_BYTE
static constexpr const enum_value<
	GLenum,
	GL_BYTE,
	mp_list<oglplus::pixel_data_type,oglplus::data_type>
> byte_ = {};
#endif

#ifdef GL_CCW
static constexpr const enum_value<
	GLenum,
	GL_CCW,
	mp_list<oglplus::face_orientation>
> ccw = {};
#endif

#ifdef GL_CIRCULAR_CCW_ARC_TO_NV
static constexpr const enum_value<
	GLubyte,
	GL_CIRCULAR_CCW_ARC_TO_NV,
	mp_list<oglplus::path_command_nv>
> circular_ccw_arc_to_nv = {};
#endif

#ifdef GL_CIRCULAR_CW_ARC_TO_NV
static constexpr const enum_value<
	GLubyte,
	GL_CIRCULAR_CW_ARC_TO_NV,
	mp_list<oglplus::path_command_nv>
> circular_cw_arc_to_nv = {};
#endif

#ifdef GL_CIRCULAR_TANGENT_ARC_TO_NV
static constexpr const enum_value<
	GLubyte,
	GL_CIRCULAR_TANGENT_ARC_TO_NV,
	mp_list<oglplus::path_command_nv>
> circular_tangent_arc_to_nv = {};
#endif

#ifdef GL_CLAMP_TO_BORDER
static constexpr const enum_value<
	GLenum,
	GL_CLAMP_TO_BORDER,
	mp_list<oglplus::texture_wrap_mode>
> clamp_to_border = {};
#endif

#ifdef GL_CLAMP_TO_EDGE
static constexpr const enum_value<
	GLenum,
	GL_CLAMP_TO_EDGE,
	mp_list<oglplus::texture_wrap_mode>
> clamp_to_edge = {};
#endif

#ifdef GL_CLEAR
static constexpr const enum_value<
	GLenum,
	GL_CLEAR,
	mp_list<oglplus::color_logic_operation>
> clear = {};
#endif

#ifdef GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT
static constexpr const enum_value<
	GLbitfield,
	GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT,
	mp_list<oglplus::memory_barrier_bits>
> client_mapped_buffer_barrier_bit = {};
#endif

#ifdef GL_CLIENT_STORAGE_BIT
static constexpr const enum_value<
	GLbitfield,
	GL_CLIENT_STORAGE_BIT,
	mp_list<oglplus::buffer_storage_bits>
> client_storage_bit = {};
#endif

#ifdef GL_CLIP_DISTANCE0
static constexpr const enum_value<
	GLenum,
	GL_CLIP_DISTANCE0,
	mp_list<oglplus::indexed_value_base>
> clip_distance0 = {};
#endif

#ifdef GL_CLIPPING_INPUT_PRIMITIVES_ARB
static constexpr const enum_value<
	GLenum,
	GL_CLIPPING_INPUT_PRIMITIVES_ARB,
	mp_list<oglplus::query_target>
> clipping_input_primitives = {};
#endif

#ifdef GL_CLIPPING_OUTPUT_PRIMITIVES_ARB
static constexpr const enum_value<
	GLenum,
	GL_CLIPPING_OUTPUT_PRIMITIVES_ARB,
	mp_list<oglplus::query_target>
> clipping_output_primitives = {};
#endif

#ifdef GL_CLOSE_PATH_NV
static constexpr const enum_value<
	GLubyte,
	GL_CLOSE_PATH_NV,
	mp_list<oglplus::path_command_nv>
> close_path_nv = {};
#endif

#ifdef GL_COLOR
static constexpr const enum_value<
	GLenum,
	GL_COLOR,
	mp_list<oglplus::framebuffer_buffer,oglplus::old_matrix_mode>
> color = {};
#endif

#ifdef GL_COLOR_ATTACHMENT0
static constexpr const enum_value<
	GLenum,
	GL_COLOR_ATTACHMENT0,
	mp_list<oglplus::indexed_value_base>
> color_attachment0 = {};
#endif

#ifdef GL_COLOR_BUFFER_BIT
static constexpr const enum_value<
	GLbitfield,
	GL_COLOR_BUFFER_BIT,
	mp_list<oglplus::buffer_select_bits>
> color_buffer_bit = {};
#endif

#ifdef GL_COLOR_CLEAR_VALUE
static constexpr const enum_value<
	GLenum,
	GL_COLOR_CLEAR_VALUE,
	mp_list<oglplus::numeric_query>
> color_clear_value = {};
#endif

#ifdef GL_COLOR_LOGIC_OP
static constexpr const enum_value<
	GLenum,
	GL_COLOR_LOGIC_OP,
	mp_list<oglplus::capability>
> color_logic_op = {};
#endif

#ifdef GL_COLOR_WRITEMASK
static constexpr const enum_value<
	GLenum,
	GL_COLOR_WRITEMASK,
	mp_list<oglplus::numeric_query>
> color_writemask = {};
#endif

#ifdef GL_COLORBURN_KHR
static constexpr const enum_value<
	GLenum,
	GL_COLORBURN_KHR,
	mp_list<oglplus::blend_equation_advanced>
> colorburn_khr = {};
#endif

#ifdef GL_COLORDODGE_KHR
static constexpr const enum_value<
	GLenum,
	GL_COLORDODGE_KHR,
	mp_list<oglplus::blend_equation_advanced>
> colordodge_khr = {};
#endif

#ifdef GL_COMMAND_BARRIER_BIT
static constexpr const enum_value<
	GLbitfield,
	GL_COMMAND_BARRIER_BIT,
	mp_list<oglplus::memory_barrier_bits>
> command_barrier_bit = {};
#endif

#ifdef GL_COMPARE_REF_TO_TEXTURE
static constexpr const enum_value<
	GLenum,
	GL_COMPARE_REF_TO_TEXTURE,
	mp_list<oglplus::texture_compare_mode>
> compare_ref_to_texture = {};
#endif

#ifdef GL_COMPATIBLE_SUBROUTINES
static constexpr const enum_value<
	GLenum,
	GL_COMPATIBLE_SUBROUTINES,
	mp_list<oglplus::program_resource_property>
> compatible_subroutines = {};
#endif

#ifdef GL_COMPILE_STATUS
static constexpr const enum_value<
	GLenum,
	GL_COMPILE_STATUS,
	mp_list<oglplus::shader_parameter>
> compile_status = {};
#endif

#ifdef GL_COMPRESSED_R11_EAC
static constexpr const enum_value<
	GLenum,
	GL_COMPRESSED_R11_EAC,
	mp_list<oglplus::pixel_data_internal_format>
> compressed_r11_eac = {};
#endif

#ifdef GL_COMPRESSED_RED
static constexpr const enum_value<
	GLenum,
	GL_COMPRESSED_RED,
	mp_list<oglplus::pixel_data_internal_format>
> compressed_red = {};
#endif

#ifdef GL_COMPRESSED_RED_RGTC1
static constexpr const enum_value<
	GLenum,
	GL_COMPRESSED_RED_RGTC1,
	mp_list<oglplus::pixel_data_internal_format>
> compressed_red_rgtc1 = {};
#endif

#ifdef GL_COMPRESSED_RG
static constexpr const enum_value<
	GLenum,
	GL_COMPRESSED_RG,
	mp_list<oglplus::pixel_data_internal_format>
> compressed_rg = {};
#endif

#ifdef GL_COMPRESSED_RG11_EAC
static constexpr const enum_value<
	GLenum,
	GL_COMPRESSED_RG11_EAC,
	mp_list<oglplus::pixel_data_internal_format>
> compressed_rg11_eac = {};
#endif

#ifdef GL_COMPRESSED_RG_RGTC2
static constexpr const enum_value<
	GLenum,
	GL_COMPRESSED_RG_RGTC2,
	mp_list<oglplus::pixel_data_internal_format>
> compressed_rg_rgtc2 = {};
#endif

#ifdef GL_COMPRESSED_RGB
static constexpr const enum_value<
	GLenum,
	GL_COMPRESSED_RGB,
	mp_list<oglplus::pixel_data_internal_format>
> compressed_rgb = {};
#endif

#ifdef GL_COMPRESSED_RGB8_ETC2
static constexpr const enum_value<
	GLenum,
	GL_COMPRESSED_RGB8_ETC2,
	mp_list<oglplus::pixel_data_internal_format>
> compressed_rgb8_etc2 = {};
#endif

#ifdef GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2
static constexpr const enum_value<
	GLenum,
	GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2,
	mp_list<oglplus::pixel_data_internal_format>
> compressed_rgb8_punchthrough_alpha1_etc2 = {};
#endif

#ifdef GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT
static constexpr const enum_value<
	GLenum,
	GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT,
	mp_list<oglplus::pixel_data_internal_format>
> compressed_rgb_bptc_signed_float = {};
#endif

#ifdef GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT
static constexpr const enum_value<
	GLenum,
	GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT,
	mp_list<oglplus::pixel_data_internal_format>
> compressed_rgb_bptc_unsigned_float = {};
#endif

#ifdef GL_COMPRESSED_RGBA
static constexpr const enum_value<
	GLenum,
	GL_COMPRESSED_RGBA,
	mp_list<oglplus::pixel_data_internal_format>
> compressed_rgba = {};
#endif

#ifdef GL_COMPRESSED_RGBA8_ETC2_EAC
static constexpr const enum_value<
	GLenum,
	GL_COMPRESSED_RGBA8_ETC2_EAC,
	mp_list<oglplus::pixel_data_internal_format>
> compressed_rgba8_etc2_eac = {};
#endif

#ifdef GL_COMPRESSED_RGBA_BPTC_UNORM
static constexpr const enum_value<
	GLenum,
	GL_COMPRESSED_RGBA_BPTC_UNORM,
	mp_list<oglplus::pixel_data_internal_format>
> compressed_rgba_bptc_unorm = {};
#endif

#ifdef GL_COMPRESSED_SIGNED_R11_EAC
static constexpr const enum_value<
	GLenum,
	GL_COMPRESSED_SIGNED_R11_EAC,
	mp_list<oglplus::pixel_data_internal_format>
> compressed_signed_r11_eac = {};
#endif

#ifdef GL_COMPRESSED_SIGNED_RED_RGTC1
static constexpr const enum_value<
	GLenum,
	GL_COMPRESSED_SIGNED_RED_RGTC1,
	mp_list<oglplus::pixel_data_internal_format>
> compressed_signed_red_rgtc1 = {};
#endif

#ifdef GL_COMPRESSED_SIGNED_RG11_EAC
static constexpr const enum_value<
	GLenum,
	GL_COMPRESSED_SIGNED_RG11_EAC,
	mp_list<oglplus::pixel_data_internal_format>
> compressed_signed_rg11_eac = {};
#endif

#ifdef GL_COMPRESSED_SIGNED_RG_RGTC2
static constexpr const enum_value<
	GLenum,
	GL_COMPRESSED_SIGNED_RG_RGTC2,
	mp_list<oglplus::pixel_data_internal_format>
> compressed_signed_rg_rgtc2 = {};
#endif

#ifdef GL_COMPRESSED_SRGB
static constexpr const enum_value<
	GLenum,
	GL_COMPRESSED_SRGB,
	mp_list<oglplus::pixel_data_internal_format>
> compressed_srgb = {};
#endif

#ifdef GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC
static constexpr const enum_value<
	GLenum,
	GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC,
	mp_list<oglplus::pixel_data_internal_format>
> compressed_srgb8_alpha8_etc2_eac = {};
#endif

#ifdef GL_COMPRESSED_SRGB8_ETC2
static constexpr const enum_value<
	GLenum,
	GL_COMPRESSED_SRGB8_ETC2,
	mp_list<oglplus::pixel_data_internal_format>
> compressed_srgb8_etc2 = {};
#endif

#ifdef GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2
static constexpr const enum_value<
	GLenum,
	GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2,
	mp_list<oglplus::pixel_data_internal_format>
> compressed_srgb8_punchthrough_alpha1_etc2 = {};
#endif

#ifdef GL_COMPRESSED_SRGB_ALPHA
static constexpr const enum_value<
	GLenum,
	GL_COMPRESSED_SRGB_ALPHA,
	mp_list<oglplus::pixel_data_internal_format>
> compressed_srgb_alpha = {};
#endif

#ifdef GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM
static constexpr const enum_value<
	GLenum,
	GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM,
	mp_list<oglplus::pixel_data_internal_format>
> compressed_srgb_alpha_bptc_unorm = {};
#endif

#ifdef GL_COMPRESSED_TEXTURE_FORMATS
static constexpr const enum_value<
	GLenum,
	GL_COMPRESSED_TEXTURE_FORMATS,
	mp_list<oglplus::numeric_query>
> compressed_texture_formats = {};
#endif

#ifdef GL_COMPUTE_SHADER
static constexpr const enum_value<
	GLenum,
	GL_COMPUTE_SHADER,
	mp_list<oglplus::shader_type>
> compute_shader = {};
#endif

#ifdef GL_COMPUTE_SHADER_BIT
static constexpr const enum_value<
	GLbitfield,
	GL_COMPUTE_SHADER_BIT,
	mp_list<oglplus::program_pipeline_stage>
> compute_shader_bit = {};
#endif

#ifdef GL_COMPUTE_SHADER_INVOCATIONS_ARB
static constexpr const enum_value<
	GLenum,
	GL_COMPUTE_SHADER_INVOCATIONS_ARB,
	mp_list<oglplus::query_target>
> compute_shader_invocations = {};
#endif

#ifdef GL_COMPUTE_SUBROUTINE
static constexpr const enum_value<
	GLenum,
	GL_COMPUTE_SUBROUTINE,
	mp_list<oglplus::program_interface>
> compute_subroutine = {};
#endif

#ifdef GL_COMPUTE_SUBROUTINE_UNIFORM
static constexpr const enum_value<
	GLenum,
	GL_COMPUTE_SUBROUTINE_UNIFORM,
	mp_list<oglplus::program_interface>
> compute_subroutine_uniform = {};
#endif

#ifdef GL_CONDITION_SATISFIED
static constexpr const enum_value<
	GLenum,
	GL_CONDITION_SATISFIED,
	mp_list<oglplus::sync_wait_result>
> condition_satisfied = {};
#endif

#ifdef GL_CONSTANT_ALPHA
static constexpr const enum_value<
	GLenum,
	GL_CONSTANT_ALPHA,
	mp_list<oglplus::blend_function>
> constant_alpha = {};
#endif

#ifdef GL_CONSTANT_COLOR
static constexpr const enum_value<
	GLenum,
	GL_CONSTANT_COLOR,
	mp_list<oglplus::blend_function>
> constant_color = {};
#endif

#ifdef GL_CONTEXT_COMPATIBILITY_PROFILE_BIT
static constexpr const enum_value<
	GLbitfield,
	GL_CONTEXT_COMPATIBILITY_PROFILE_BIT,
	mp_list<oglplus::context_profile_bits>
> context_compatibility_profile_bit = {};
#endif

#ifdef GL_CONTEXT_CORE_PROFILE_BIT
static constexpr const enum_value<
	GLbitfield,
	GL_CONTEXT_CORE_PROFILE_BIT,
	mp_list<oglplus::context_profile_bits>
> context_core_profile_bit = {};
#endif

#ifdef GL_CONTEXT_FLAG_DEBUG_BIT
static constexpr const enum_value<
	GLbitfield,
	GL_CONTEXT_FLAG_DEBUG_BIT,
	mp_list<oglplus::context_flag_bits>
> context_flag_debug_bit = {};
#endif

#ifdef GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT
static constexpr const enum_value<
	GLbitfield,
	GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT,
	mp_list<oglplus::context_flag_bits>
> context_flag_forward_compatible_bit = {};
#endif

#ifdef GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT_ARB
static constexpr const enum_value<
	GLbitfield,
	GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT_ARB,
	mp_list<oglplus::context_flag_bits>
> context_flag_robust_access_bit = {};
#endif

#ifdef GL_CONTEXT_FLAGS
static constexpr const enum_value<
	GLenum,
	GL_CONTEXT_FLAGS,
	mp_list<oglplus::numeric_query>
> context_flags = {};
#endif

#ifdef GL_CONTEXT_LOST
static constexpr const enum_value<
	GLenum,
	GL_CONTEXT_LOST,
	mp_list<oglplus::error_code>
> context_lost = {};
#endif

#ifdef GL_CONTEXT_RELEASE_BEHAVIOR_FLUSH
static constexpr const enum_value<
	GLenum,
	GL_CONTEXT_RELEASE_BEHAVIOR_FLUSH,
	mp_list<oglplus::context_release_behavior>
> context_release_behavior_flush = {};
#endif

#ifdef GL_CONVEX_HULL_NV
static constexpr const enum_value<
	GLenum,
	GL_CONVEX_HULL_NV,
	mp_list<oglplus::path_stroke_cover_mode_nv,oglplus::path_fill_cover_mode_nv>
> convex_hull_nv = {};
#endif

#ifdef GL_COPY
static constexpr const enum_value<
	GLenum,
	GL_COPY,
	mp_list<oglplus::color_logic_operation>
> copy = {};
#endif

#ifdef GL_COPY_INVERTED
static constexpr const enum_value<
	GLenum,
	GL_COPY_INVERTED,
	mp_list<oglplus::color_logic_operation>
> copy_inverted = {};
#endif

#ifdef GL_COPY_READ_BUFFER
static constexpr const enum_value<
	GLenum,
	GL_COPY_READ_BUFFER,
	mp_list<oglplus::buffer_target>
> copy_read_buffer = {};
#endif

#ifdef GL_COPY_READ_BUFFER_BINDING
static constexpr const enum_value<
	GLenum,
	GL_COPY_READ_BUFFER_BINDING,
	mp_list<oglplus::binding_query>
> copy_read_buffer_binding = {};
#endif

#ifdef GL_COPY_WRITE_BUFFER
static constexpr const enum_value<
	GLenum,
	GL_COPY_WRITE_BUFFER,
	mp_list<oglplus::buffer_target>
> copy_write_buffer = {};
#endif

#ifdef GL_COPY_WRITE_BUFFER_BINDING
static constexpr const enum_value<
	GLenum,
	GL_COPY_WRITE_BUFFER_BINDING,
	mp_list<oglplus::binding_query>
> copy_write_buffer_binding = {};
#endif

#ifdef GL_COUNT_DOWN_NV
static constexpr const enum_value<
	GLenum,
	GL_COUNT_DOWN_NV,
	mp_list<oglplus::path_fill_mode_nv>
> count_down_nv = {};
#endif

#ifdef GL_COUNT_UP_NV
static constexpr const enum_value<
	GLenum,
	GL_COUNT_UP_NV,
	mp_list<oglplus::path_fill_mode_nv>
> count_up_nv = {};
#endif

#ifdef GL_CUBIC_CURVE_TO_NV
static constexpr const enum_value<
	GLubyte,
	GL_CUBIC_CURVE_TO_NV,
	mp_list<oglplus::path_command_nv>
> cubic_curve_to_nv = {};
#endif

#ifdef GL_CULL_FACE
static constexpr const enum_value<
	GLenum,
	GL_CULL_FACE,
	mp_list<oglplus::capability>
> cull_face = {};
#endif

#ifdef GL_CURRENT_PROGRAM
static constexpr const enum_value<
	GLenum,
	GL_CURRENT_PROGRAM,
	mp_list<oglplus::binding_query>
> current_program = {};
#endif

#ifdef GL_CW
static constexpr const enum_value<
	GLenum,
	GL_CW,
	mp_list<oglplus::face_orientation>
> cw = {};
#endif

#ifdef GL_DARKEN_KHR
static constexpr const enum_value<
	GLenum,
	GL_DARKEN_KHR,
	mp_list<oglplus::blend_equation_advanced>
> darken_khr = {};
#endif

#ifdef GL_DEBUG_GROUP_STACK_DEPTH
static constexpr const enum_value<
	GLenum,
	GL_DEBUG_GROUP_STACK_DEPTH,
	mp_list<oglplus::numeric_query>
> debug_group_stack_depth = {};
#endif

#ifdef GL_DEBUG_OUTPUT_SYNCHRONOUS
static constexpr const enum_value<
	GLenum,
	GL_DEBUG_OUTPUT_SYNCHRONOUS,
	mp_list<oglplus::capability>
> debug_output_synchronous = {};
#endif

#ifdef GL_DEBUG_SEVERITY_HIGH
static constexpr const enum_value<
	GLenum,
	GL_DEBUG_SEVERITY_HIGH,
	mp_list<oglplus::debug_output_severity>
> debug_severity_high = {};
#endif

#ifdef GL_DEBUG_SEVERITY_LOW
static constexpr const enum_value<
	GLenum,
	GL_DEBUG_SEVERITY_LOW,
	mp_list<oglplus::debug_output_severity>
> debug_severity_low = {};
#endif

#ifdef GL_DEBUG_SEVERITY_MEDIUM
static constexpr const enum_value<
	GLenum,
	GL_DEBUG_SEVERITY_MEDIUM,
	mp_list<oglplus::debug_output_severity>
> debug_severity_medium = {};
#endif

#ifdef GL_DEBUG_SEVERITY_NOTIFICATION
static constexpr const enum_value<
	GLenum,
	GL_DEBUG_SEVERITY_NOTIFICATION,
	mp_list<oglplus::debug_output_severity>
> debug_severity_notification = {};
#endif

#ifdef GL_DEBUG_SOURCE_API
static constexpr const enum_value<
	GLenum,
	GL_DEBUG_SOURCE_API,
	mp_list<oglplus::debug_output_source>
> debug_source_api = {};
#endif

#ifdef GL_DEBUG_SOURCE_APPLICATION
static constexpr const enum_value<
	GLenum,
	GL_DEBUG_SOURCE_APPLICATION,
	mp_list<oglplus::debug_output_source>
> debug_source_application = {};
#endif

#ifdef GL_DEBUG_SOURCE_OTHER
static constexpr const enum_value<
	GLenum,
	GL_DEBUG_SOURCE_OTHER,
	mp_list<oglplus::debug_output_source>
> debug_source_other = {};
#endif

#ifdef GL_DEBUG_SOURCE_SHADER_COMPILER
static constexpr const enum_value<
	GLenum,
	GL_DEBUG_SOURCE_SHADER_COMPILER,
	mp_list<oglplus::debug_output_source>
> debug_source_shader_compiler = {};
#endif

#ifdef GL_DEBUG_SOURCE_THIRD_PARTY
static constexpr const enum_value<
	GLenum,
	GL_DEBUG_SOURCE_THIRD_PARTY,
	mp_list<oglplus::debug_output_source>
> debug_source_third_party = {};
#endif

#ifdef GL_DEBUG_SOURCE_WINDOW_SYSTEM
static constexpr const enum_value<
	GLenum,
	GL_DEBUG_SOURCE_WINDOW_SYSTEM,
	mp_list<oglplus::debug_output_source>
> debug_source_window_system = {};
#endif

#ifdef GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR
static constexpr const enum_value<
	GLenum,
	GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR,
	mp_list<oglplus::debug_output_type>
> debug_type_deprecated_behavior = {};
#endif

#ifdef GL_DEBUG_TYPE_ERROR
static constexpr const enum_value<
	GLenum,
	GL_DEBUG_TYPE_ERROR,
	mp_list<oglplus::debug_output_type>
> debug_type_error = {};
#endif

#ifdef GL_DEBUG_TYPE_MARKER
static constexpr const enum_value<
	GLenum,
	GL_DEBUG_TYPE_MARKER,
	mp_list<oglplus::debug_output_type>
> debug_type_marker = {};
#endif

#ifdef GL_DEBUG_TYPE_OTHER
static constexpr const enum_value<
	GLenum,
	GL_DEBUG_TYPE_OTHER,
	mp_list<oglplus::debug_output_type>
> debug_type_other = {};
#endif

#ifdef GL_DEBUG_TYPE_PERFORMANCE
static constexpr const enum_value<
	GLenum,
	GL_DEBUG_TYPE_PERFORMANCE,
	mp_list<oglplus::debug_output_type>
> debug_type_performance = {};
#endif

#ifdef GL_DEBUG_TYPE_POP_GROUP
static constexpr const enum_value<
	GLenum,
	GL_DEBUG_TYPE_POP_GROUP,
	mp_list<oglplus::debug_output_type>
> debug_type_pop_group = {};
#endif

#ifdef GL_DEBUG_TYPE_PORTABILITY
static constexpr const enum_value<
	GLenum,
	GL_DEBUG_TYPE_PORTABILITY,
	mp_list<oglplus::debug_output_type>
> debug_type_portability = {};
#endif

#ifdef GL_DEBUG_TYPE_PUSH_GROUP
static constexpr const enum_value<
	GLenum,
	GL_DEBUG_TYPE_PUSH_GROUP,
	mp_list<oglplus::debug_output_type>
> debug_type_push_group = {};
#endif

#ifdef GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR
static constexpr const enum_value<
	GLenum,
	GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR,
	mp_list<oglplus::debug_output_type>
> debug_type_undefined_behavior = {};
#endif

#ifdef GL_DECR
static constexpr const enum_value<
	GLenum,
	GL_DECR,
	mp_list<oglplus::stencil_operation>
> decr = {};
#endif

#ifdef GL_DECR_WRAP
static constexpr const enum_value<
	GLenum,
	GL_DECR_WRAP,
	mp_list<oglplus::stencil_operation>
> decr_wrap = {};
#endif

#ifdef GL_DELETE_STATUS
static constexpr const enum_value<
	GLenum,
	GL_DELETE_STATUS,
	mp_list<oglplus::program_parameter,oglplus::shader_parameter>
> delete_status = {};
#endif

#ifdef GL_DEPTH
static constexpr const enum_value<
	GLenum,
	GL_DEPTH,
	mp_list<oglplus::framebuffer_buffer>
> depth = {};
#endif

#ifdef GL_DEPTH24_STENCIL8
static constexpr const enum_value<
	GLenum,
	GL_DEPTH24_STENCIL8,
	mp_list<oglplus::pixel_data_internal_format>
> depth24_stencil8 = {};
#endif

#ifdef GL_DEPTH32F_STENCIL8
static constexpr const enum_value<
	GLenum,
	GL_DEPTH32F_STENCIL8,
	mp_list<oglplus::pixel_data_internal_format>
> depth32f_stencil8 = {};
#endif

#ifdef GL_DEPTH_ATTACHMENT
static constexpr const enum_value<
	GLenum,
	GL_DEPTH_ATTACHMENT,
	mp_list<oglplus::framebuffer_other_attachment>
> depth_attachment = {};
#endif

#ifdef GL_DEPTH_BUFFER_BIT
static constexpr const enum_value<
	GLbitfield,
	GL_DEPTH_BUFFER_BIT,
	mp_list<oglplus::buffer_select_bits>
> depth_buffer_bit = {};
#endif

#ifdef GL_DEPTH_CLEAR_VALUE
static constexpr const enum_value<
	GLenum,
	GL_DEPTH_CLEAR_VALUE,
	mp_list<oglplus::numeric_query>
> depth_clear_value = {};
#endif

#ifdef GL_DEPTH_COMPONENT
static constexpr const enum_value<
	GLenum,
	GL_DEPTH_COMPONENT,
	mp_list<oglplus::pixel_data_format,oglplus::pixel_data_internal_format>
> depth_component = {};
#endif

#ifdef GL_DEPTH_COMPONENT16
static constexpr const enum_value<
	GLenum,
	GL_DEPTH_COMPONENT16,
	mp_list<oglplus::pixel_data_internal_format>
> depth_component16 = {};
#endif

#ifdef GL_DEPTH_COMPONENT24
static constexpr const enum_value<
	GLenum,
	GL_DEPTH_COMPONENT24,
	mp_list<oglplus::pixel_data_internal_format>
> depth_component24 = {};
#endif

#ifdef GL_DEPTH_COMPONENT32
static constexpr const enum_value<
	GLenum,
	GL_DEPTH_COMPONENT32,
	mp_list<oglplus::pixel_data_internal_format>
> depth_component32 = {};
#endif

#ifdef GL_DEPTH_COMPONENT32F
static constexpr const enum_value<
	GLenum,
	GL_DEPTH_COMPONENT32F,
	mp_list<oglplus::pixel_data_internal_format>
> depth_component32f = {};
#endif

#ifdef GL_DEPTH_FUNC
static constexpr const enum_value<
	GLenum,
	GL_DEPTH_FUNC,
	mp_list<oglplus::numeric_query>
> depth_func = {};
#endif

#ifdef GL_DEPTH_RANGE
static constexpr const enum_value<
	GLenum,
	GL_DEPTH_RANGE,
	mp_list<oglplus::numeric_query>
> depth_range = {};
#endif

#ifdef GL_DEPTH_STENCIL
static constexpr const enum_value<
	GLenum,
	GL_DEPTH_STENCIL,
	mp_list<oglplus::framebuffer_buffer,oglplus::pixel_data_format,oglplus::pixel_data_internal_format>
> depth_stencil = {};
#endif

#ifdef GL_DEPTH_STENCIL_ATTACHMENT
static constexpr const enum_value<
	GLenum,
	GL_DEPTH_STENCIL_ATTACHMENT,
	mp_list<oglplus::framebuffer_other_attachment>
> depth_stencil_attachment = {};
#endif

#ifdef GL_DEPTH_STENCIL_TEXTURE_MODE
static constexpr const enum_value<
	GLenum,
	GL_DEPTH_STENCIL_TEXTURE_MODE,
	mp_list<oglplus::texture_parameter>
> depth_stencil_texture_mode = {};
#endif

#ifdef GL_DEPTH_TEST
static constexpr const enum_value<
	GLenum,
	GL_DEPTH_TEST,
	mp_list<oglplus::capability>
> depth_test = {};
#endif

#ifdef GL_DEPTH_WRITEMASK
static constexpr const enum_value<
	GLenum,
	GL_DEPTH_WRITEMASK,
	mp_list<oglplus::numeric_query>
> depth_writemask = {};
#endif

#ifdef GL_DIFFERENCE_KHR
static constexpr const enum_value<
	GLenum,
	GL_DIFFERENCE_KHR,
	mp_list<oglplus::blend_equation_advanced>
> difference_khr = {};
#endif

#ifdef GL_DISPATCH_INDIRECT_BUFFER
static constexpr const enum_value<
	GLenum,
	GL_DISPATCH_INDIRECT_BUFFER,
	mp_list<oglplus::buffer_target>
> dispatch_indirect_buffer = {};
#endif

#ifdef GL_DISPATCH_INDIRECT_BUFFER_BINDING
static constexpr const enum_value<
	GLenum,
	GL_DISPATCH_INDIRECT_BUFFER_BINDING,
	mp_list<oglplus::binding_query>
> dispatch_indirect_buffer_binding = {};
#endif

#ifdef GL_DITHER
static constexpr const enum_value<
	GLenum,
	GL_DITHER,
	mp_list<oglplus::capability>
> dither = {};
#endif

#ifdef GL_DONT_CARE
static constexpr const enum_value<
	GLenum,
	GL_DONT_CARE,
	mp_list<oglplus::debug_output_source,oglplus::debug_output_type,oglplus::hint_option,oglplus::debug_output_severity>
> dont_care = {};
#endif

#ifdef GL_DOUBLE
static constexpr const enum_value<
	GLenum,
	GL_DOUBLE,
	mp_list<oglplus::sl_data_type,oglplus::pixel_data_type,oglplus::data_type>
> double_ = {};
#endif

#ifdef GL_DOUBLE_MAT2
static constexpr const enum_value<
	GLenum,
	GL_DOUBLE_MAT2,
	mp_list<oglplus::sl_data_type>
> double_mat2 = {};
#endif

#ifdef GL_DOUBLE_MAT2x3
static constexpr const enum_value<
	GLenum,
	GL_DOUBLE_MAT2x3,
	mp_list<oglplus::sl_data_type>
> double_mat2x3 = {};
#endif

#ifdef GL_DOUBLE_MAT2x4
static constexpr const enum_value<
	GLenum,
	GL_DOUBLE_MAT2x4,
	mp_list<oglplus::sl_data_type>
> double_mat2x4 = {};
#endif

#ifdef GL_DOUBLE_MAT3
static constexpr const enum_value<
	GLenum,
	GL_DOUBLE_MAT3,
	mp_list<oglplus::sl_data_type>
> double_mat3 = {};
#endif

#ifdef GL_DOUBLE_MAT3x2
static constexpr const enum_value<
	GLenum,
	GL_DOUBLE_MAT3x2,
	mp_list<oglplus::sl_data_type>
> double_mat3x2 = {};
#endif

#ifdef GL_DOUBLE_MAT3x4
static constexpr const enum_value<
	GLenum,
	GL_DOUBLE_MAT3x4,
	mp_list<oglplus::sl_data_type>
> double_mat3x4 = {};
#endif

#ifdef GL_DOUBLE_MAT4
static constexpr const enum_value<
	GLenum,
	GL_DOUBLE_MAT4,
	mp_list<oglplus::sl_data_type>
> double_mat4 = {};
#endif

#ifdef GL_DOUBLE_MAT4x2
static constexpr const enum_value<
	GLenum,
	GL_DOUBLE_MAT4x2,
	mp_list<oglplus::sl_data_type>
> double_mat4x2 = {};
#endif

#ifdef GL_DOUBLE_MAT4x3
static constexpr const enum_value<
	GLenum,
	GL_DOUBLE_MAT4x3,
	mp_list<oglplus::sl_data_type>
> double_mat4x3 = {};
#endif

#ifdef GL_DOUBLE_VEC2
static constexpr const enum_value<
	GLenum,
	GL_DOUBLE_VEC2,
	mp_list<oglplus::sl_data_type>
> double_vec2 = {};
#endif

#ifdef GL_DOUBLE_VEC3
static constexpr const enum_value<
	GLenum,
	GL_DOUBLE_VEC3,
	mp_list<oglplus::sl_data_type>
> double_vec3 = {};
#endif

#ifdef GL_DOUBLE_VEC4
static constexpr const enum_value<
	GLenum,
	GL_DOUBLE_VEC4,
	mp_list<oglplus::sl_data_type>
> double_vec4 = {};
#endif

#ifdef GL_DOUBLEBUFFER
static constexpr const enum_value<
	GLenum,
	GL_DOUBLEBUFFER,
	mp_list<oglplus::numeric_query>
> doublebuffer = {};
#endif

#ifdef GL_DRAW_BUFFER
static constexpr const enum_value<
	GLenum,
	GL_DRAW_BUFFER,
	mp_list<oglplus::numeric_query>
> draw_buffer = {};
#endif

#ifdef GL_DRAW_BUFFER0
static constexpr const enum_value<
	GLenum,
	GL_DRAW_BUFFER0,
	mp_list<oglplus::indexed_value_base>
> draw_buffer0 = {};
#endif

#ifdef GL_DRAW_FRAMEBUFFER
static constexpr const enum_value<
	GLenum,
	GL_DRAW_FRAMEBUFFER,
	mp_list<oglplus::framebuffer_target>
> draw_framebuffer = {};
#endif

#ifdef GL_DRAW_FRAMEBUFFER_BINDING
static constexpr const enum_value<
	GLenum,
	GL_DRAW_FRAMEBUFFER_BINDING,
	mp_list<oglplus::binding_query>
> draw_framebuffer_binding = {};
#endif

#ifdef GL_DRAW_INDIRECT_BUFFER
static constexpr const enum_value<
	GLenum,
	GL_DRAW_INDIRECT_BUFFER,
	mp_list<oglplus::buffer_target>
> draw_indirect_buffer = {};
#endif

#ifdef GL_DRAW_INDIRECT_BUFFER_BINDING
static constexpr const enum_value<
	GLenum,
	GL_DRAW_INDIRECT_BUFFER_BINDING,
	mp_list<oglplus::binding_query>
> draw_indirect_buffer_binding = {};
#endif

#ifdef GL_DST_ALPHA
static constexpr const enum_value<
	GLenum,
	GL_DST_ALPHA,
	mp_list<oglplus::blend_function>
> dst_alpha = {};
#endif

#ifdef GL_DST_COLOR
static constexpr const enum_value<
	GLenum,
	GL_DST_COLOR,
	mp_list<oglplus::blend_function>
> dst_color = {};
#endif

#ifdef GL_DUP_FIRST_CUBIC_CURVE_TO_NV
static constexpr const enum_value<
	GLubyte,
	GL_DUP_FIRST_CUBIC_CURVE_TO_NV,
	mp_list<oglplus::path_command_nv>
> dup_first_cubic_curve_to_nv = {};
#endif

#ifdef GL_DUP_LAST_CUBIC_CURVE_TO_NV
static constexpr const enum_value<
	GLubyte,
	GL_DUP_LAST_CUBIC_CURVE_TO_NV,
	mp_list<oglplus::path_command_nv>
> dup_last_cubic_curve_to_nv = {};
#endif

#ifdef GL_DYNAMIC_COPY
static constexpr const enum_value<
	GLenum,
	GL_DYNAMIC_COPY,
	mp_list<oglplus::buffer_usage>
> dynamic_copy = {};
#endif

#ifdef GL_DYNAMIC_DRAW
static constexpr const enum_value<
	GLenum,
	GL_DYNAMIC_DRAW,
	mp_list<oglplus::buffer_usage>
> dynamic_draw = {};
#endif

#ifdef GL_DYNAMIC_READ
static constexpr const enum_value<
	GLenum,
	GL_DYNAMIC_READ,
	mp_list<oglplus::buffer_usage>
> dynamic_read = {};
#endif

#ifdef GL_DYNAMIC_STORAGE_BIT
static constexpr const enum_value<
	GLbitfield,
	GL_DYNAMIC_STORAGE_BIT,
	mp_list<oglplus::buffer_storage_bits>
> dynamic_storage_bit = {};
#endif

#ifdef GL_ELEMENT_ARRAY_BARRIER_BIT
static constexpr const enum_value<
	GLbitfield,
	GL_ELEMENT_ARRAY_BARRIER_BIT,
	mp_list<oglplus::memory_barrier_bits>
> element_array_barrier_bit = {};
#endif

#ifdef GL_ELEMENT_ARRAY_BUFFER
static constexpr const enum_value<
	GLenum,
	GL_ELEMENT_ARRAY_BUFFER,
	mp_list<oglplus::buffer_target>
> element_array_buffer = {};
#endif

#ifdef GL_ELEMENT_ARRAY_BUFFER_BINDING
static constexpr const enum_value<
	GLenum,
	GL_ELEMENT_ARRAY_BUFFER_BINDING,
	mp_list<oglplus::binding_query>
> element_array_buffer_binding = {};
#endif

#ifdef GL_EQUAL
static constexpr const enum_value<
	GLenum,
	GL_EQUAL,
	mp_list<oglplus::compare_function,oglplus::tess_gen_primitive_spacing>
> equal = {};
#endif

#ifdef GL_EQUIV
static constexpr const enum_value<
	GLenum,
	GL_EQUIV,
	mp_list<oglplus::color_logic_operation>
> equiv = {};
#endif

#ifdef GL_EXCLUSION_KHR
static constexpr const enum_value<
	GLenum,
	GL_EXCLUSION_KHR,
	mp_list<oglplus::blend_equation_advanced>
> exclusion_khr = {};
#endif

#ifdef GL_EXTERNAL_VIRTUAL_MEMORY_BUFFER_AMD
static constexpr const enum_value<
	GLenum,
	GL_EXTERNAL_VIRTUAL_MEMORY_BUFFER_AMD,
	mp_list<oglplus::buffer_target>
> external_virtual_memory_buffer = {};
#endif

#ifdef GL_EYE_LINEAR
static constexpr const enum_value<
	GLenum,
	GL_EYE_LINEAR,
	mp_list<oglplus::path_gen_mode_nv>
> eye_linear = {};
#endif

#ifdef GL_FALSE
static constexpr const enum_value<
	GLboolean,
	GL_FALSE,
	mp_list<oglplus::true_false>
> false_ = {};
#endif

#ifdef GL_FASTEST
static constexpr const enum_value<
	GLenum,
	GL_FASTEST,
	mp_list<oglplus::hint_option>
> fastest = {};
#endif

#ifdef GL_FILE_NAME_NV
static constexpr const enum_value<
	GLenum,
	GL_FILE_NAME_NV,
	mp_list<oglplus::path_font_target_nv>
> file_name_nv = {};
#endif

#ifdef GL_FILL
static constexpr const enum_value<
	GLenum,
	GL_FILL,
	mp_list<oglplus::polygon_mode>
> fill = {};
#endif

#ifdef GL_FILL_RECTANGLE_NV
static constexpr const enum_value<
	GLenum,
	GL_FILL_RECTANGLE_NV,
	mp_list<oglplus::polygon_mode>
> fill_rectangle = {};
#endif

#ifdef GL_FIRST_TO_REST_NV
static constexpr const enum_value<
	GLenum,
	GL_FIRST_TO_REST_NV,
	mp_list<oglplus::path_list_mode_nv>
> first_to_rest_nv = {};
#endif

#ifdef GL_FIRST_VERTEX_CONVENTION
static constexpr const enum_value<
	GLenum,
	GL_FIRST_VERTEX_CONVENTION,
	mp_list<oglplus::provoke_mode>
> first_vertex_convention = {};
#endif

#ifdef GL_FIXED
static constexpr const enum_value<
	GLenum,
	GL_FIXED,
	mp_list<oglplus::data_type>
> fixed = {};
#endif

#ifdef GL_FLAT
static constexpr const enum_value<
	GLenum,
	GL_FLAT,
	mp_list<oglplus::path_cap_style_nv>
> flat = {};
#endif

#ifdef GL_FLOAT
static constexpr const enum_value<
	GLenum,
	GL_FLOAT,
	mp_list<oglplus::sl_data_type,oglplus::pixel_data_type,oglplus::data_type>
> float_ = {};
#endif

#ifdef GL_FLOAT_32_UNSIGNED_INT_24_8_REV
static constexpr const enum_value<
	GLenum,
	GL_FLOAT_32_UNSIGNED_INT_24_8_REV,
	mp_list<oglplus::pixel_data_type>
> float_32_unsigned_int_24_8_rev = {};
#endif

#ifdef GL_FLOAT_MAT2
static constexpr const enum_value<
	GLenum,
	GL_FLOAT_MAT2,
	mp_list<oglplus::sl_data_type>
> float_mat2 = {};
#endif

#ifdef GL_FLOAT_MAT2x3
static constexpr const enum_value<
	GLenum,
	GL_FLOAT_MAT2x3,
	mp_list<oglplus::sl_data_type>
> float_mat2x3 = {};
#endif

#ifdef GL_FLOAT_MAT2x4
static constexpr const enum_value<
	GLenum,
	GL_FLOAT_MAT2x4,
	mp_list<oglplus::sl_data_type>
> float_mat2x4 = {};
#endif

#ifdef GL_FLOAT_MAT3
static constexpr const enum_value<
	GLenum,
	GL_FLOAT_MAT3,
	mp_list<oglplus::sl_data_type>
> float_mat3 = {};
#endif

#ifdef GL_FLOAT_MAT3x2
static constexpr const enum_value<
	GLenum,
	GL_FLOAT_MAT3x2,
	mp_list<oglplus::sl_data_type>
> float_mat3x2 = {};
#endif

#ifdef GL_FLOAT_MAT3x4
static constexpr const enum_value<
	GLenum,
	GL_FLOAT_MAT3x4,
	mp_list<oglplus::sl_data_type>
> float_mat3x4 = {};
#endif

#ifdef GL_FLOAT_MAT4
static constexpr const enum_value<
	GLenum,
	GL_FLOAT_MAT4,
	mp_list<oglplus::sl_data_type>
> float_mat4 = {};
#endif

#ifdef GL_FLOAT_MAT4x2
static constexpr const enum_value<
	GLenum,
	GL_FLOAT_MAT4x2,
	mp_list<oglplus::sl_data_type>
> float_mat4x2 = {};
#endif

#ifdef GL_FLOAT_MAT4x3
static constexpr const enum_value<
	GLenum,
	GL_FLOAT_MAT4x3,
	mp_list<oglplus::sl_data_type>
> float_mat4x3 = {};
#endif

#ifdef GL_FLOAT_VEC2
static constexpr const enum_value<
	GLenum,
	GL_FLOAT_VEC2,
	mp_list<oglplus::sl_data_type>
> float_vec2 = {};
#endif

#ifdef GL_FLOAT_VEC3
static constexpr const enum_value<
	GLenum,
	GL_FLOAT_VEC3,
	mp_list<oglplus::sl_data_type>
> float_vec3 = {};
#endif

#ifdef GL_FLOAT_VEC4
static constexpr const enum_value<
	GLenum,
	GL_FLOAT_VEC4,
	mp_list<oglplus::sl_data_type>
> float_vec4 = {};
#endif

#ifdef GL_FONT_ASCENDER_BIT_NV
static constexpr const enum_value<
	GLbitfield,
	GL_FONT_ASCENDER_BIT_NV,
	mp_list<oglplus::path_metric_query_nv>
> font_ascender_bit_nv = {};
#endif

#ifdef GL_FONT_DESCENDER_BIT_NV
static constexpr const enum_value<
	GLbitfield,
	GL_FONT_DESCENDER_BIT_NV,
	mp_list<oglplus::path_metric_query_nv>
> font_descender_bit_nv = {};
#endif

#ifdef GL_FONT_HAS_KERNING_BIT_NV
static constexpr const enum_value<
	GLbitfield,
	GL_FONT_HAS_KERNING_BIT_NV,
	mp_list<oglplus::path_metric_query_nv>
> font_has_kerning_bit_nv = {};
#endif

#ifdef GL_FONT_HEIGHT_BIT_NV
static constexpr const enum_value<
	GLbitfield,
	GL_FONT_HEIGHT_BIT_NV,
	mp_list<oglplus::path_metric_query_nv>
> font_height_bit_nv = {};
#endif

#ifdef GL_FONT_MAX_ADVANCE_HEIGHT_BIT_NV
static constexpr const enum_value<
	GLbitfield,
	GL_FONT_MAX_ADVANCE_HEIGHT_BIT_NV,
	mp_list<oglplus::path_metric_query_nv>
> font_max_advance_height_bit_nv = {};
#endif

#ifdef GL_FONT_MAX_ADVANCE_WIDTH_BIT_NV
static constexpr const enum_value<
	GLbitfield,
	GL_FONT_MAX_ADVANCE_WIDTH_BIT_NV,
	mp_list<oglplus::path_metric_query_nv>
> font_max_advance_width_bit_nv = {};
#endif

#ifdef GL_FONT_UNDERLINE_POSITION_BIT_NV
static constexpr const enum_value<
	GLbitfield,
	GL_FONT_UNDERLINE_POSITION_BIT_NV,
	mp_list<oglplus::path_metric_query_nv>
> font_underline_position_bit_nv = {};
#endif

#ifdef GL_FONT_UNDERLINE_THICKNESS_BIT_NV
static constexpr const enum_value<
	GLbitfield,
	GL_FONT_UNDERLINE_THICKNESS_BIT_NV,
	mp_list<oglplus::path_metric_query_nv>
> font_underline_thickness_bit_nv = {};
#endif

#ifdef GL_FONT_UNITS_PER_EM_BIT_NV
static constexpr const enum_value<
	GLbitfield,
	GL_FONT_UNITS_PER_EM_BIT_NV,
	mp_list<oglplus::path_metric_query_nv>
> font_units_per_em_bit_nv = {};
#endif

#ifdef GL_FONT_X_MAX_BOUNDS_BIT_NV
static constexpr const enum_value<
	GLbitfield,
	GL_FONT_X_MAX_BOUNDS_BIT_NV,
	mp_list<oglplus::path_metric_query_nv>
> font_x_max_bounds_bit_nv = {};
#endif

#ifdef GL_FONT_X_MIN_BOUNDS_BIT_NV
static constexpr const enum_value<
	GLbitfield,
	GL_FONT_X_MIN_BOUNDS_BIT_NV,
	mp_list<oglplus::path_metric_query_nv>
> font_x_min_bounds_bit_nv = {};
#endif

#ifdef GL_FONT_Y_MAX_BOUNDS_BIT_NV
static constexpr const enum_value<
	GLbitfield,
	GL_FONT_Y_MAX_BOUNDS_BIT_NV,
	mp_list<oglplus::path_metric_query_nv>
> font_y_max_bounds_bit_nv = {};
#endif

#ifdef GL_FONT_Y_MIN_BOUNDS_BIT_NV
static constexpr const enum_value<
	GLbitfield,
	GL_FONT_Y_MIN_BOUNDS_BIT_NV,
	mp_list<oglplus::path_metric_query_nv>
> font_y_min_bounds_bit_nv = {};
#endif

#ifdef GL_FRACTIONAL_EVEN
static constexpr const enum_value<
	GLenum,
	GL_FRACTIONAL_EVEN,
	mp_list<oglplus::tess_gen_primitive_spacing>
> fractional_even = {};
#endif

#ifdef GL_FRACTIONAL_ODD
static constexpr const enum_value<
	GLenum,
	GL_FRACTIONAL_ODD,
	mp_list<oglplus::tess_gen_primitive_spacing>
> fractional_odd = {};
#endif

#ifdef GL_FRAGMENT_COVERAGE_TO_COLOR_NV
static constexpr const enum_value<
	GLenum,
	GL_FRAGMENT_COVERAGE_TO_COLOR_NV,
	mp_list<oglplus::capability>
> fragment_coverage_to_color = {};
#endif

#ifdef GL_FRAGMENT_SHADER
static constexpr const enum_value<
	GLenum,
	GL_FRAGMENT_SHADER,
	mp_list<oglplus::shader_type,oglplus::program_pipeline_parameter>
> fragment_shader = {};
#endif

#ifdef GL_FRAGMENT_SHADER_BIT
static constexpr const enum_value<
	GLbitfield,
	GL_FRAGMENT_SHADER_BIT,
	mp_list<oglplus::program_pipeline_stage>
> fragment_shader_bit = {};
#endif

#ifdef GL_FRAGMENT_SHADER_DERIVATIVE_HINT
static constexpr const enum_value<
	GLenum,
	GL_FRAGMENT_SHADER_DERIVATIVE_HINT,
	mp_list<oglplus::hint_target,oglplus::numeric_query>
> fragment_shader_derivative_hint = {};
#endif

#ifdef GL_FRAGMENT_SHADER_INVOCATIONS_ARB
static constexpr const enum_value<
	GLenum,
	GL_FRAGMENT_SHADER_INVOCATIONS_ARB,
	mp_list<oglplus::query_target>
> fragment_shader_invocations = {};
#endif

#ifdef GL_FRAGMENT_SUBROUTINE
static constexpr const enum_value<
	GLenum,
	GL_FRAGMENT_SUBROUTINE,
	mp_list<oglplus::program_interface>
> fragment_subroutine = {};
#endif

#ifdef GL_FRAGMENT_SUBROUTINE_UNIFORM
static constexpr const enum_value<
	GLenum,
	GL_FRAGMENT_SUBROUTINE_UNIFORM,
	mp_list<oglplus::program_interface>
> fragment_subroutine_uniform = {};
#endif

#ifdef GL_FRAMEBUFFER
static constexpr const enum_value<
	GLenum,
	GL_FRAMEBUFFER,
	mp_list<oglplus::object_type>
> framebuffer = {};
#endif

#ifdef GL_FRAMEBUFFER_BARRIER_BIT
static constexpr const enum_value<
	GLbitfield,
	GL_FRAMEBUFFER_BARRIER_BIT,
	mp_list<oglplus::memory_barrier_bits>
> framebuffer_barrier_bit = {};
#endif

#ifdef GL_FRAMEBUFFER_COMPLETE
static constexpr const enum_value<
	GLenum,
	GL_FRAMEBUFFER_COMPLETE,
	mp_list<oglplus::framebuffer_status>
> framebuffer_complete = {};
#endif

#ifdef GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT
static constexpr const enum_value<
	GLenum,
	GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT,
	mp_list<oglplus::framebuffer_status>
> framebuffer_incomplete_attachment = {};
#endif

#ifdef GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS
static constexpr const enum_value<
	GLenum,
	GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS,
	mp_list<oglplus::framebuffer_status>
> framebuffer_incomplete_layer_targets = {};
#endif

#ifdef GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT
static constexpr const enum_value<
	GLenum,
	GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT,
	mp_list<oglplus::framebuffer_status>
> framebuffer_incomplete_missing_attachment = {};
#endif

#ifdef GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE
static constexpr const enum_value<
	GLenum,
	GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE,
	mp_list<oglplus::framebuffer_status>
> framebuffer_incomplete_multisample = {};
#endif

#ifdef GL_FRAMEBUFFER_SRGB
static constexpr const enum_value<
	GLenum,
	GL_FRAMEBUFFER_SRGB,
	mp_list<oglplus::capability>
> framebuffer_srgb = {};
#endif

#ifdef GL_FRAMEBUFFER_UNDEFINED
static constexpr const enum_value<
	GLenum,
	GL_FRAMEBUFFER_UNDEFINED,
	mp_list<oglplus::framebuffer_status>
> framebuffer_undefined = {};
#endif

#ifdef GL_FRAMEBUFFER_UNSUPPORTED
static constexpr const enum_value<
	GLenum,
	GL_FRAMEBUFFER_UNSUPPORTED,
	mp_list<oglplus::framebuffer_status>
> framebuffer_unsupported = {};
#endif

#ifdef GL_FRONT
static constexpr const enum_value<
	GLenum,
	GL_FRONT,
	mp_list<oglplus::color_buffer,oglplus::single_face,oglplus::face>
> front = {};
#endif

#ifdef GL_FRONT_AND_BACK
static constexpr const enum_value<
	GLenum,
	GL_FRONT_AND_BACK,
	mp_list<oglplus::color_buffer,oglplus::face>
> front_and_back = {};
#endif

#ifdef GL_FRONT_LEFT
static constexpr const enum_value<
	GLenum,
	GL_FRONT_LEFT,
	mp_list<oglplus::color_buffer>
> front_left = {};
#endif

#ifdef GL_FRONT_RIGHT
static constexpr const enum_value<
	GLenum,
	GL_FRONT_RIGHT,
	mp_list<oglplus::color_buffer>
> front_right = {};
#endif

#ifdef GL_FUNC_ADD
static constexpr const enum_value<
	GLenum,
	GL_FUNC_ADD,
	mp_list<oglplus::blend_equation>
> func_add = {};
#endif

#ifdef GL_FUNC_REVERSE_SUBTRACT
static constexpr const enum_value<
	GLenum,
	GL_FUNC_REVERSE_SUBTRACT,
	mp_list<oglplus::blend_equation>
> func_reverse_subtract = {};
#endif

#ifdef GL_FUNC_SUBTRACT
static constexpr const enum_value<
	GLenum,
	GL_FUNC_SUBTRACT,
	mp_list<oglplus::blend_equation>
> func_subtract = {};
#endif

#ifdef GL_GEOMETRY_SHADER
static constexpr const enum_value<
	GLenum,
	GL_GEOMETRY_SHADER,
	mp_list<oglplus::shader_type,oglplus::program_pipeline_parameter>
> geometry_shader = {};
#endif

#ifdef GL_GEOMETRY_SHADER_BIT
static constexpr const enum_value<
	GLbitfield,
	GL_GEOMETRY_SHADER_BIT,
	mp_list<oglplus::program_pipeline_stage>
> geometry_shader_bit = {};
#endif

#ifdef GL_GEOMETRY_SHADER_INVOCATIONS
static constexpr const enum_value<
	GLenum,
	GL_GEOMETRY_SHADER_INVOCATIONS,
	mp_list<oglplus::query_target>
> geometry_shader_invocations = {};
#endif

#ifdef GL_GEOMETRY_SHADER_PRIMITIVES_EMITTED_ARB
static constexpr const enum_value<
	GLenum,
	GL_GEOMETRY_SHADER_PRIMITIVES_EMITTED_ARB,
	mp_list<oglplus::query_target>
> geometry_shader_primitives_emitted = {};
#endif

#ifdef GL_GEOMETRY_SUBROUTINE
static constexpr const enum_value<
	GLenum,
	GL_GEOMETRY_SUBROUTINE,
	mp_list<oglplus::program_interface>
> geometry_subroutine = {};
#endif

#ifdef GL_GEOMETRY_SUBROUTINE_UNIFORM
static constexpr const enum_value<
	GLenum,
	GL_GEOMETRY_SUBROUTINE_UNIFORM,
	mp_list<oglplus::program_interface>
> geometry_subroutine_uniform = {};
#endif

#ifdef GL_GEQUAL
static constexpr const enum_value<
	GLenum,
	GL_GEQUAL,
	mp_list<oglplus::compare_function>
> gequal = {};
#endif

#ifdef GL_GLYPH_HAS_KERNING_BIT_NV
static constexpr const enum_value<
	GLbitfield,
	GL_GLYPH_HAS_KERNING_BIT_NV,
	mp_list<oglplus::path_metric_query_nv>
> glyph_has_kerning_bit_nv = {};
#endif

#ifdef GL_GLYPH_HEIGHT_BIT_NV
static constexpr const enum_value<
	GLbitfield,
	GL_GLYPH_HEIGHT_BIT_NV,
	mp_list<oglplus::path_metric_query_nv>
> glyph_height_bit_nv = {};
#endif

#ifdef GL_GLYPH_HORIZONTAL_BEARING_ADVANCE_BIT_NV
static constexpr const enum_value<
	GLbitfield,
	GL_GLYPH_HORIZONTAL_BEARING_ADVANCE_BIT_NV,
	mp_list<oglplus::path_metric_query_nv>
> glyph_horizontal_bearing_advance_bit_nv = {};
#endif

#ifdef GL_GLYPH_HORIZONTAL_BEARING_X_BIT_NV
static constexpr const enum_value<
	GLbitfield,
	GL_GLYPH_HORIZONTAL_BEARING_X_BIT_NV,
	mp_list<oglplus::path_metric_query_nv>
> glyph_horizontal_bearing_x_bit_nv = {};
#endif

#ifdef GL_GLYPH_HORIZONTAL_BEARING_Y_BIT_NV
static constexpr const enum_value<
	GLbitfield,
	GL_GLYPH_HORIZONTAL_BEARING_Y_BIT_NV,
	mp_list<oglplus::path_metric_query_nv>
> glyph_horizontal_bearing_y_bit_nv = {};
#endif

#ifdef GL_GLYPH_VERTICAL_BEARING_ADVANCE_BIT_NV
static constexpr const enum_value<
	GLbitfield,
	GL_GLYPH_VERTICAL_BEARING_ADVANCE_BIT_NV,
	mp_list<oglplus::path_metric_query_nv>
> glyph_vertical_bearing_advance_bit_nv = {};
#endif

#ifdef GL_GLYPH_VERTICAL_BEARING_X_BIT_NV
static constexpr const enum_value<
	GLbitfield,
	GL_GLYPH_VERTICAL_BEARING_X_BIT_NV,
	mp_list<oglplus::path_metric_query_nv>
> glyph_vertical_bearing_x_bit_nv = {};
#endif

#ifdef GL_GLYPH_VERTICAL_BEARING_Y_BIT_NV
static constexpr const enum_value<
	GLbitfield,
	GL_GLYPH_VERTICAL_BEARING_Y_BIT_NV,
	mp_list<oglplus::path_metric_query_nv>
> glyph_vertical_bearing_y_bit_nv = {};
#endif

#ifdef GL_GLYPH_WIDTH_BIT_NV
static constexpr const enum_value<
	GLbitfield,
	GL_GLYPH_WIDTH_BIT_NV,
	mp_list<oglplus::path_metric_query_nv>
> glyph_width_bit_nv = {};
#endif

#ifdef GL_GREATER
static constexpr const enum_value<
	GLenum,
	GL_GREATER,
	mp_list<oglplus::compare_function>
> greater = {};
#endif

#ifdef GL_GREEN
static constexpr const enum_value<
	GLenum,
	GL_GREEN,
	mp_list<oglplus::texture_swizzle_mode,oglplus::pixel_data_format>
> green = {};
#endif

#ifdef GL_GREEN_INTEGER
static constexpr const enum_value<
	GLenum,
	GL_GREEN_INTEGER,
	mp_list<oglplus::pixel_data_format>
> green_integer = {};
#endif

#ifdef GL_GUILTY_CONTEXT_RESET
static constexpr const enum_value<
	GLenum,
	GL_GUILTY_CONTEXT_RESET,
	mp_list<oglplus::graphics_reset_status>
> guilty_context_reset = {};
#endif

#ifdef GL_HALF_FLOAT
static constexpr const enum_value<
	GLenum,
	GL_HALF_FLOAT,
	mp_list<oglplus::pixel_data_type,oglplus::data_type>
> half_float = {};
#endif

#ifdef GL_HARDLIGHT_KHR
static constexpr const enum_value<
	GLenum,
	GL_HARDLIGHT_KHR,
	mp_list<oglplus::blend_equation_advanced>
> hardlight_khr = {};
#endif

#ifdef GL_HIGH_FLOAT
static constexpr const enum_value<
	GLenum,
	GL_HIGH_FLOAT,
	mp_list<oglplus::precision_type>
> high_float = {};
#endif

#ifdef GL_HIGH_INT
static constexpr const enum_value<
	GLenum,
	GL_HIGH_INT,
	mp_list<oglplus::precision_type>
> high_int = {};
#endif

#ifdef GL_HORIZONTAL_LINE_TO_NV
static constexpr const enum_value<
	GLubyte,
	GL_HORIZONTAL_LINE_TO_NV,
	mp_list<oglplus::path_command_nv>
> horizontal_line_to_nv = {};
#endif

#ifdef GL_HSL_COLOR_KHR
static constexpr const enum_value<
	GLenum,
	GL_HSL_COLOR_KHR,
	mp_list<oglplus::blend_equation_advanced>
> hsl_color_khr = {};
#endif

#ifdef GL_HSL_HUE_KHR
static constexpr const enum_value<
	GLenum,
	GL_HSL_HUE_KHR,
	mp_list<oglplus::blend_equation_advanced>
> hsl_hue_khr = {};
#endif

#ifdef GL_HSL_LUMINOSITY_KHR
static constexpr const enum_value<
	GLenum,
	GL_HSL_LUMINOSITY_KHR,
	mp_list<oglplus::blend_equation_advanced>
> hsl_luminosity_khr = {};
#endif

#ifdef GL_HSL_SATURATION_KHR
static constexpr const enum_value<
	GLenum,
	GL_HSL_SATURATION_KHR,
	mp_list<oglplus::blend_equation_advanced>
> hsl_saturation_khr = {};
#endif

#ifdef GL_IMAGE_1D
static constexpr const enum_value<
	GLenum,
	GL_IMAGE_1D,
	mp_list<oglplus::sl_data_type>
> image_1d = {};
#endif

#ifdef GL_IMAGE_1D_ARRAY
static constexpr const enum_value<
	GLenum,
	GL_IMAGE_1D_ARRAY,
	mp_list<oglplus::sl_data_type>
> image_1d_array = {};
#endif

#ifdef GL_IMAGE_2D
static constexpr const enum_value<
	GLenum,
	GL_IMAGE_2D,
	mp_list<oglplus::sl_data_type>
> image_2d = {};
#endif

#ifdef GL_IMAGE_2D_ARRAY
static constexpr const enum_value<
	GLenum,
	GL_IMAGE_2D_ARRAY,
	mp_list<oglplus::sl_data_type>
> image_2d_array = {};
#endif

#ifdef GL_IMAGE_2D_MULTISAMPLE
static constexpr const enum_value<
	GLenum,
	GL_IMAGE_2D_MULTISAMPLE,
	mp_list<oglplus::sl_data_type>
> image_2d_multisample = {};
#endif

#ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
static constexpr const enum_value<
	GLenum,
	GL_IMAGE_2D_MULTISAMPLE_ARRAY,
	mp_list<oglplus::sl_data_type>
> image_2d_multisample_array = {};
#endif

#ifdef GL_IMAGE_2D_RECT
static constexpr const enum_value<
	GLenum,
	GL_IMAGE_2D_RECT,
	mp_list<oglplus::sl_data_type>
> image_2d_rect = {};
#endif

#ifdef GL_IMAGE_3D
static constexpr const enum_value<
	GLenum,
	GL_IMAGE_3D,
	mp_list<oglplus::sl_data_type>
> image_3d = {};
#endif

#ifdef GL_IMAGE_BUFFER
static constexpr const enum_value<
	GLenum,
	GL_IMAGE_BUFFER,
	mp_list<oglplus::sl_data_type>
> image_buffer = {};
#endif

#ifdef GL_IMAGE_CUBE
static constexpr const enum_value<
	GLenum,
	GL_IMAGE_CUBE,
	mp_list<oglplus::sl_data_type>
> image_cube = {};
#endif

#ifdef GL_IMAGE_FORMAT_COMPATIBILITY_TYPE
static constexpr const enum_value<
	GLenum,
	GL_IMAGE_FORMAT_COMPATIBILITY_TYPE,
	mp_list<oglplus::texture_parameter>
> image_format_compatibility_type = {};
#endif

#ifdef GL_IMPLEMENTATION_COLOR_READ_FORMAT
static constexpr const enum_value<
	GLenum,
	GL_IMPLEMENTATION_COLOR_READ_FORMAT,
	mp_list<oglplus::numeric_query>
> implementation_color_read_format = {};
#endif

#ifdef GL_IMPLEMENTATION_COLOR_READ_TYPE
static constexpr const enum_value<
	GLenum,
	GL_IMPLEMENTATION_COLOR_READ_TYPE,
	mp_list<oglplus::numeric_query>
> implementation_color_read_type = {};
#endif

#ifdef GL_INCR
static constexpr const enum_value<
	GLenum,
	GL_INCR,
	mp_list<oglplus::stencil_operation>
> incr = {};
#endif

#ifdef GL_INCR_WRAP
static constexpr const enum_value<
	GLenum,
	GL_INCR_WRAP,
	mp_list<oglplus::stencil_operation>
> incr_wrap = {};
#endif

#ifdef GL_INFO_LOG_LENGTH
static constexpr const enum_value<
	GLenum,
	GL_INFO_LOG_LENGTH,
	mp_list<oglplus::shader_parameter,oglplus::program_parameter,oglplus::program_pipeline_parameter>
> info_log_length = {};
#endif

#ifdef GL_INNOCENT_CONTEXT_RESET
static constexpr const enum_value<
	GLenum,
	GL_INNOCENT_CONTEXT_RESET,
	mp_list<oglplus::graphics_reset_status>
> innocent_context_reset = {};
#endif

#ifdef GL_INT
static constexpr const enum_value<
	GLenum,
	GL_INT,
	mp_list<oglplus::sl_data_type,oglplus::pixel_data_type,oglplus::data_type>
> int_ = {};
#endif

#ifdef GL_INT_IMAGE_1D
static constexpr const enum_value<
	GLenum,
	GL_INT_IMAGE_1D,
	mp_list<oglplus::sl_data_type>
> int_image_1d = {};
#endif

#ifdef GL_INT_IMAGE_1D_ARRAY
static constexpr const enum_value<
	GLenum,
	GL_INT_IMAGE_1D_ARRAY,
	mp_list<oglplus::sl_data_type>
> int_image_1d_array = {};
#endif

#ifdef GL_INT_IMAGE_2D
static constexpr const enum_value<
	GLenum,
	GL_INT_IMAGE_2D,
	mp_list<oglplus::sl_data_type>
> int_image_2d = {};
#endif

#ifdef GL_INT_IMAGE_2D_ARRAY
static constexpr const enum_value<
	GLenum,
	GL_INT_IMAGE_2D_ARRAY,
	mp_list<oglplus::sl_data_type>
> int_image_2d_array = {};
#endif

#ifdef GL_INT_IMAGE_2D_MULTISAMPLE
static constexpr const enum_value<
	GLenum,
	GL_INT_IMAGE_2D_MULTISAMPLE,
	mp_list<oglplus::sl_data_type>
> int_image_2d_multisample = {};
#endif

#ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
static constexpr const enum_value<
	GLenum,
	GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY,
	mp_list<oglplus::sl_data_type>
> int_image_2d_multisample_array = {};
#endif

#ifdef GL_INT_IMAGE_2D_RECT
static constexpr const enum_value<
	GLenum,
	GL_INT_IMAGE_2D_RECT,
	mp_list<oglplus::sl_data_type>
> int_image_2d_rect = {};
#endif

#ifdef GL_INT_IMAGE_3D
static constexpr const enum_value<
	GLenum,
	GL_INT_IMAGE_3D,
	mp_list<oglplus::sl_data_type>
> int_image_3d = {};
#endif

#ifdef GL_INT_IMAGE_BUFFER
static constexpr const enum_value<
	GLenum,
	GL_INT_IMAGE_BUFFER,
	mp_list<oglplus::sl_data_type>
> int_image_buffer = {};
#endif

#ifdef GL_INT_IMAGE_CUBE
static constexpr const enum_value<
	GLenum,
	GL_INT_IMAGE_CUBE,
	mp_list<oglplus::sl_data_type>
> int_image_cube = {};
#endif

#ifdef GL_INT_SAMPLER_1D
static constexpr const enum_value<
	GLenum,
	GL_INT_SAMPLER_1D,
	mp_list<oglplus::sl_data_type>
> int_sampler_1d = {};
#endif

#ifdef GL_INT_SAMPLER_1D_ARRAY
static constexpr const enum_value<
	GLenum,
	GL_INT_SAMPLER_1D_ARRAY,
	mp_list<oglplus::sl_data_type>
> int_sampler_1d_array = {};
#endif

#ifdef GL_INT_SAMPLER_2D
static constexpr const enum_value<
	GLenum,
	GL_INT_SAMPLER_2D,
	mp_list<oglplus::sl_data_type>
> int_sampler_2d = {};
#endif

#ifdef GL_INT_SAMPLER_2D_ARRAY
static constexpr const enum_value<
	GLenum,
	GL_INT_SAMPLER_2D_ARRAY,
	mp_list<oglplus::sl_data_type>
> int_sampler_2d_array = {};
#endif

#ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
static constexpr const enum_value<
	GLenum,
	GL_INT_SAMPLER_2D_MULTISAMPLE,
	mp_list<oglplus::sl_data_type>
> int_sampler_2d_multisample = {};
#endif

#ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
static constexpr const enum_value<
	GLenum,
	GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY,
	mp_list<oglplus::sl_data_type>
> int_sampler_2d_multisample_array = {};
#endif

#ifdef GL_INT_SAMPLER_2D_RECT
static constexpr const enum_value<
	GLenum,
	GL_INT_SAMPLER_2D_RECT,
	mp_list<oglplus::sl_data_type>
> int_sampler_2d_rect = {};
#endif

#ifdef GL_INT_SAMPLER_3D
static constexpr const enum_value<
	GLenum,
	GL_INT_SAMPLER_3D,
	mp_list<oglplus::sl_data_type>
> int_sampler_3d = {};
#endif

#ifdef GL_INT_SAMPLER_BUFFER
static constexpr const enum_value<
	GLenum,
	GL_INT_SAMPLER_BUFFER,
	mp_list<oglplus::sl_data_type>
> int_sampler_buffer = {};
#endif

#ifdef GL_INT_SAMPLER_CUBE
static constexpr const enum_value<
	GLenum,
	GL_INT_SAMPLER_CUBE,
	mp_list<oglplus::sl_data_type>
> int_sampler_cube = {};
#endif

#ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
static constexpr const enum_value<
	GLenum,
	GL_INT_SAMPLER_CUBE_MAP_ARRAY,
	mp_list<oglplus::sl_data_type>
> int_sampler_cube_map_array = {};
#endif

#ifdef GL_INT_VEC2
static constexpr const enum_value<
	GLenum,
	GL_INT_VEC2,
	mp_list<oglplus::sl_data_type>
> int_vec2 = {};
#endif

#ifdef GL_INT_VEC3
static constexpr const enum_value<
	GLenum,
	GL_INT_VEC3,
	mp_list<oglplus::sl_data_type>
> int_vec3 = {};
#endif

#ifdef GL_INT_VEC4
static constexpr const enum_value<
	GLenum,
	GL_INT_VEC4,
	mp_list<oglplus::sl_data_type>
> int_vec4 = {};
#endif

#ifdef GL_INTENSITY
static constexpr const enum_value<
	GLenum,
	GL_INTENSITY,
	mp_list<oglplus::path_color_format_nv>
> intensity = {};
#endif

#ifdef GL_INTERLEAVED_ATTRIBS
static constexpr const enum_value<
	GLenum,
	GL_INTERLEAVED_ATTRIBS,
	mp_list<oglplus::transform_feedback_mode>
> interleaved_attribs = {};
#endif

#ifdef GL_INVALID_ENUM
static constexpr const enum_value<
	GLenum,
	GL_INVALID_ENUM,
	mp_list<oglplus::error_code>
> invalid_enum = {};
#endif

#ifdef GL_INVALID_FRAMEBUFFER_OPERATION
static constexpr const enum_value<
	GLenum,
	GL_INVALID_FRAMEBUFFER_OPERATION,
	mp_list<oglplus::error_code>
> invalid_framebuffer_operation = {};
#endif

#ifdef GL_INVALID_OPERATION
static constexpr const enum_value<
	GLenum,
	GL_INVALID_OPERATION,
	mp_list<oglplus::error_code>
> invalid_operation = {};
#endif

#ifdef GL_INVALID_VALUE
static constexpr const enum_value<
	GLenum,
	GL_INVALID_VALUE,
	mp_list<oglplus::error_code>
> invalid_value = {};
#endif

#ifdef GL_INVERT
static constexpr const enum_value<
	GLenum,
	GL_INVERT,
	mp_list<oglplus::path_fill_mode_nv,oglplus::color_logic_operation,oglplus::stencil_operation>
> invert = {};
#endif

#ifdef GL_IS_PER_PATCH
static constexpr const enum_value<
	GLenum,
	GL_IS_PER_PATCH,
	mp_list<oglplus::program_resource_property>
> is_per_patch = {};
#endif

#ifdef GL_IS_ROW_MAJOR
static constexpr const enum_value<
	GLenum,
	GL_IS_ROW_MAJOR,
	mp_list<oglplus::program_resource_property>
> is_row_major = {};
#endif

#ifdef GL_ISOLINES
static constexpr const enum_value<
	GLenum,
	GL_ISOLINES,
	mp_list<oglplus::tess_gen_primitive_type>
> isolines = {};
#endif

#ifdef GL_ITALIC_BIT_NV
static constexpr const enum_value<
	GLbitfield,
	GL_ITALIC_BIT_NV,
	mp_list<oglplus::path_font_style_nv>
> italic_bit_nv = {};
#endif

#ifdef GL_KEEP
static constexpr const enum_value<
	GLenum,
	GL_KEEP,
	mp_list<oglplus::stencil_operation>
> keep = {};
#endif

#ifdef GL_LARGE_CCW_ARC_TO_NV
static constexpr const enum_value<
	GLubyte,
	GL_LARGE_CCW_ARC_TO_NV,
	mp_list<oglplus::path_command_nv>
> large_ccw_arc_to_nv = {};
#endif

#ifdef GL_LARGE_CW_ARC_TO_NV
static constexpr const enum_value<
	GLubyte,
	GL_LARGE_CW_ARC_TO_NV,
	mp_list<oglplus::path_command_nv>
> large_cw_arc_to_nv = {};
#endif

#ifdef GL_LAST_VERTEX_CONVENTION
static constexpr const enum_value<
	GLenum,
	GL_LAST_VERTEX_CONVENTION,
	mp_list<oglplus::provoke_mode>
> last_vertex_convention = {};
#endif

#ifdef GL_LAYER_PROVOKING_VERTEX
static constexpr const enum_value<
	GLenum,
	GL_LAYER_PROVOKING_VERTEX,
	mp_list<oglplus::numeric_query>
> layer_provoking_vertex = {};
#endif

#ifdef GL_LEFT
static constexpr const enum_value<
	GLenum,
	GL_LEFT,
	mp_list<oglplus::color_buffer>
> left = {};
#endif

#ifdef GL_LEQUAL
static constexpr const enum_value<
	GLenum,
	GL_LEQUAL,
	mp_list<oglplus::compare_function>
> lequal = {};
#endif

#ifdef GL_LESS
static constexpr const enum_value<
	GLenum,
	GL_LESS,
	mp_list<oglplus::compare_function>
> less = {};
#endif

#ifdef GL_LIGHTEN_KHR
static constexpr const enum_value<
	GLenum,
	GL_LIGHTEN_KHR,
	mp_list<oglplus::blend_equation_advanced>
> lighten_khr = {};
#endif

#ifdef GL_LINE
static constexpr const enum_value<
	GLenum,
	GL_LINE,
	mp_list<oglplus::polygon_mode>
> line = {};
#endif

#ifdef GL_LINE_LOOP
static constexpr const enum_value<
	GLenum,
	GL_LINE_LOOP,
	mp_list<oglplus::primitive_type,oglplus::old_primitive_type>
> line_loop = {};
#endif

#ifdef GL_LINE_SMOOTH
static constexpr const enum_value<
	GLenum,
	GL_LINE_SMOOTH,
	mp_list<oglplus::capability>
> line_smooth = {};
#endif

#ifdef GL_LINE_SMOOTH_HINT
static constexpr const enum_value<
	GLenum,
	GL_LINE_SMOOTH_HINT,
	mp_list<oglplus::hint_target,oglplus::numeric_query>
> line_smooth_hint = {};
#endif

#ifdef GL_LINE_STRIP
static constexpr const enum_value<
	GLenum,
	GL_LINE_STRIP,
	mp_list<oglplus::primitive_type,oglplus::old_primitive_type>
> line_strip = {};
#endif

#ifdef GL_LINE_STRIP_ADJACENCY
static constexpr const enum_value<
	GLenum,
	GL_LINE_STRIP_ADJACENCY,
	mp_list<oglplus::primitive_type>
> line_strip_adjacency = {};
#endif

#ifdef GL_LINE_TO_NV
static constexpr const enum_value<
	GLubyte,
	GL_LINE_TO_NV,
	mp_list<oglplus::path_command_nv>
> line_to_nv = {};
#endif

#ifdef GL_LINE_WIDTH
static constexpr const enum_value<
	GLenum,
	GL_LINE_WIDTH,
	mp_list<oglplus::numeric_query>
> line_width = {};
#endif

#ifdef GL_LINEAR
static constexpr const enum_value<
	GLenum,
	GL_LINEAR,
	mp_list<oglplus::texture_mag_filter,oglplus::blit_filter,oglplus::texture_filter,oglplus::texture_min_filter>
> linear = {};
#endif

#ifdef GL_LINEAR_MIPMAP_LINEAR
static constexpr const enum_value<
	GLenum,
	GL_LINEAR_MIPMAP_LINEAR,
	mp_list<oglplus::texture_min_filter>
> linear_mipmap_linear = {};
#endif

#ifdef GL_LINEAR_MIPMAP_NEAREST
static constexpr const enum_value<
	GLenum,
	GL_LINEAR_MIPMAP_NEAREST,
	mp_list<oglplus::texture_min_filter>
> linear_mipmap_nearest = {};
#endif

#ifdef GL_LINES
static constexpr const enum_value<
	GLenum,
	GL_LINES,
	mp_list<oglplus::primitive_type,oglplus::old_primitive_type,oglplus::transform_feedback_primitive_type>
> lines = {};
#endif

#ifdef GL_LINES_ADJACENCY
static constexpr const enum_value<
	GLenum,
	GL_LINES_ADJACENCY,
	mp_list<oglplus::primitive_type>
> lines_adjacency = {};
#endif

#ifdef GL_LINK_STATUS
static constexpr const enum_value<
	GLenum,
	GL_LINK_STATUS,
	mp_list<oglplus::program_parameter>
> link_status = {};
#endif

#ifdef GL_LOCATION
static constexpr const enum_value<
	GLenum,
	GL_LOCATION,
	mp_list<oglplus::program_resource_property>
> location = {};
#endif

#ifdef GL_LOCATION_COMPONENT
static constexpr const enum_value<
	GLenum,
	GL_LOCATION_COMPONENT,
	mp_list<oglplus::program_resource_property>
> location_component = {};
#endif

#ifdef GL_LOCATION_INDEX
static constexpr const enum_value<
	GLenum,
	GL_LOCATION_INDEX,
	mp_list<oglplus::program_resource_property>
> location_index = {};
#endif

#ifdef GL_LOGIC_OP_MODE
static constexpr const enum_value<
	GLenum,
	GL_LOGIC_OP_MODE,
	mp_list<oglplus::numeric_query>
> logic_op_mode = {};
#endif

#ifdef GL_LOSE_CONTEXT_ON_RESET
static constexpr const enum_value<
	GLenum,
	GL_LOSE_CONTEXT_ON_RESET,
	mp_list<oglplus::reset_notification_strategy>
> lose_context_on_reset = {};
#endif

#ifdef GL_LOW_FLOAT
static constexpr const enum_value<
	GLenum,
	GL_LOW_FLOAT,
	mp_list<oglplus::precision_type>
> low_float = {};
#endif

#ifdef GL_LOW_INT
static constexpr const enum_value<
	GLenum,
	GL_LOW_INT,
	mp_list<oglplus::precision_type>
> low_int = {};
#endif

#ifdef GL_LOWER_LEFT
static constexpr const enum_value<
	GLenum,
	GL_LOWER_LEFT,
	mp_list<oglplus::clip_origin>
> lower_left = {};
#endif

#ifdef GL_LUMINANCE
static constexpr const enum_value<
	GLenum,
	GL_LUMINANCE,
	mp_list<oglplus::path_color_format_nv>
> luminance = {};
#endif

#ifdef GL_LUMINANCE_ALPHA
static constexpr const enum_value<
	GLenum,
	GL_LUMINANCE_ALPHA,
	mp_list<oglplus::path_color_format_nv>
> luminance_alpha = {};
#endif

#ifdef GL_MAP_COHERENT_BIT
static constexpr const enum_value<
	GLbitfield,
	GL_MAP_COHERENT_BIT,
	mp_list<oglplus::buffer_storage_bits,oglplus::buffer_map_access>
> map_coherent_bit = {};
#endif

#ifdef GL_MAP_FLUSH_EXPLICIT_BIT
static constexpr const enum_value<
	GLbitfield,
	GL_MAP_FLUSH_EXPLICIT_BIT,
	mp_list<oglplus::buffer_map_access>
> map_flush_explicit_bit = {};
#endif

#ifdef GL_MAP_INVALIDATE_BUFFER_BIT
static constexpr const enum_value<
	GLbitfield,
	GL_MAP_INVALIDATE_BUFFER_BIT,
	mp_list<oglplus::buffer_map_access>
> map_invalidate_buffer_bit = {};
#endif

#ifdef GL_MAP_INVALIDATE_RANGE_BIT
static constexpr const enum_value<
	GLbitfield,
	GL_MAP_INVALIDATE_RANGE_BIT,
	mp_list<oglplus::buffer_map_access>
> map_invalidate_range_bit = {};
#endif

#ifdef GL_MAP_PERSISTENT_BIT
static constexpr const enum_value<
	GLbitfield,
	GL_MAP_PERSISTENT_BIT,
	mp_list<oglplus::buffer_storage_bits,oglplus::buffer_map_access>
> map_persistent_bit = {};
#endif

#ifdef GL_MAP_READ_BIT
static constexpr const enum_value<
	GLbitfield,
	GL_MAP_READ_BIT,
	mp_list<oglplus::buffer_storage_bits,oglplus::buffer_map_access>
> map_read_bit = {};
#endif

#ifdef GL_MAP_UNSYNCHRONIZED_BIT
static constexpr const enum_value<
	GLbitfield,
	GL_MAP_UNSYNCHRONIZED_BIT,
	mp_list<oglplus::buffer_map_access>
> map_unsynchronized_bit = {};
#endif

#ifdef GL_MAP_WRITE_BIT
static constexpr const enum_value<
	GLbitfield,
	GL_MAP_WRITE_BIT,
	mp_list<oglplus::buffer_storage_bits,oglplus::buffer_map_access>
> map_write_bit = {};
#endif

#ifdef GL_MATRIX_STRIDE
static constexpr const enum_value<
	GLenum,
	GL_MATRIX_STRIDE,
	mp_list<oglplus::program_resource_property>
> matrix_stride = {};
#endif

#ifdef GL_MAX
static constexpr const enum_value<
	GLenum,
	GL_MAX,
	mp_list<oglplus::blend_equation>
> max = {};
#endif

#ifdef GL_MAX_3D_TEXTURE_SIZE
static constexpr const enum_value<
	GLenum,
	GL_MAX_3D_TEXTURE_SIZE,
	mp_list<oglplus::limit_query>
> max_3d_texture_size = {};
#endif

#ifdef GL_MAX_ARRAY_TEXTURE_LAYERS
static constexpr const enum_value<
	GLenum,
	GL_MAX_ARRAY_TEXTURE_LAYERS,
	mp_list<oglplus::limit_query>
> max_array_texture_layers = {};
#endif

#ifdef GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS
static constexpr const enum_value<
	GLenum,
	GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS,
	mp_list<oglplus::limit_query>
> max_atomic_counter_buffer_bindings = {};
#endif

#ifdef GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE
static constexpr const enum_value<
	GLenum,
	GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE,
	mp_list<oglplus::limit_query>
> max_atomic_counter_buffer_size = {};
#endif

#ifdef GL_MAX_CLIP_DISTANCES
static constexpr const enum_value<
	GLenum,
	GL_MAX_CLIP_DISTANCES,
	mp_list<oglplus::limit_query>
> max_clip_distances = {};
#endif

#ifdef GL_MAX_COLOR_ATTACHMENTS
static constexpr const enum_value<
	GLenum,
	GL_MAX_COLOR_ATTACHMENTS,
	mp_list<oglplus::limit_query>
> max_color_attachments = {};
#endif

#ifdef GL_MAX_COLOR_TEXTURE_SAMPLES
static constexpr const enum_value<
	GLenum,
	GL_MAX_COLOR_TEXTURE_SAMPLES,
	mp_list<oglplus::limit_query>
> max_color_texture_samples = {};
#endif

#ifdef GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS
static constexpr const enum_value<
	GLenum,
	GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS,
	mp_list<oglplus::limit_query>
> max_combined_atomic_counter_buffers = {};
#endif

#ifdef GL_MAX_COMBINED_ATOMIC_COUNTERS
static constexpr const enum_value<
	GLenum,
	GL_MAX_COMBINED_ATOMIC_COUNTERS,
	mp_list<oglplus::limit_query>
> max_combined_atomic_counters = {};
#endif

#ifdef GL_MAX_COMBINED_CLIP_AND_CULL_DISTANCES
static constexpr const enum_value<
	GLenum,
	GL_MAX_COMBINED_CLIP_AND_CULL_DISTANCES,
	mp_list<oglplus::limit_query>
> max_combined_clip_and_cull_distances = {};
#endif

#ifdef GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS
static constexpr const enum_value<
	GLenum,
	GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS,
	mp_list<oglplus::limit_query>
> max_combined_fragment_uniform_components = {};
#endif

#ifdef GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS
static constexpr const enum_value<
	GLenum,
	GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS,
	mp_list<oglplus::limit_query>
> max_combined_geometry_uniform_components = {};
#endif

#ifdef GL_MAX_COMBINED_IMAGE_UNIFORMS
static constexpr const enum_value<
	GLenum,
	GL_MAX_COMBINED_IMAGE_UNIFORMS,
	mp_list<oglplus::limit_query>
> max_combined_image_uniforms = {};
#endif

#ifdef GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS
static constexpr const enum_value<
	GLenum,
	GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS,
	mp_list<oglplus::limit_query>
> max_combined_image_units_and_fragment_outputs = {};
#endif

#ifdef GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS
static constexpr const enum_value<
	GLenum,
	GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS,
	mp_list<oglplus::limit_query>
> max_combined_tess_control_uniform_components = {};
#endif

#ifdef GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS
static constexpr const enum_value<
	GLenum,
	GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS,
	mp_list<oglplus::limit_query>
> max_combined_tess_evaluation_uniform_components = {};
#endif

#ifdef GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS
static constexpr const enum_value<
	GLenum,
	GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS,
	mp_list<oglplus::limit_query>
> max_combined_texture_image_units = {};
#endif

#ifdef GL_MAX_COMBINED_UNIFORM_BLOCKS
static constexpr const enum_value<
	GLenum,
	GL_MAX_COMBINED_UNIFORM_BLOCKS,
	mp_list<oglplus::limit_query>
> max_combined_uniform_blocks = {};
#endif

#ifdef GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS
static constexpr const enum_value<
	GLenum,
	GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS,
	mp_list<oglplus::limit_query>
> max_combined_vertex_uniform_components = {};
#endif

#ifdef GL_MAX_COMPUTE_SHARED_MEMORY_SIZE
static constexpr const enum_value<
	GLenum,
	GL_MAX_COMPUTE_SHARED_MEMORY_SIZE,
	mp_list<oglplus::limit_query>
> max_compute_shared_memory_size = {};
#endif

#ifdef GL_MAX_COMPUTE_WORK_GROUP_COUNT
static constexpr const enum_value<
	GLenum,
	GL_MAX_COMPUTE_WORK_GROUP_COUNT,
	mp_list<oglplus::limit_query>
> max_compute_work_group_count = {};
#endif

#ifdef GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS
static constexpr const enum_value<
	GLenum,
	GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS,
	mp_list<oglplus::limit_query>
> max_compute_work_group_invocations = {};
#endif

#ifdef GL_MAX_COMPUTE_WORK_GROUP_SIZE
static constexpr const enum_value<
	GLenum,
	GL_MAX_COMPUTE_WORK_GROUP_SIZE,
	mp_list<oglplus::limit_query>
> max_compute_work_group_size = {};
#endif

#ifdef GL_MAX_CUBE_MAP_TEXTURE_SIZE
static constexpr const enum_value<
	GLenum,
	GL_MAX_CUBE_MAP_TEXTURE_SIZE,
	mp_list<oglplus::limit_query>
> max_cube_map_texture_size = {};
#endif

#ifdef GL_MAX_CULL_DISTANCES
static constexpr const enum_value<
	GLenum,
	GL_MAX_CULL_DISTANCES,
	mp_list<oglplus::limit_query>
> max_cull_distances = {};
#endif

#ifdef GL_MAX_DEPTH_TEXTURE_SAMPLES
static constexpr const enum_value<
	GLenum,
	GL_MAX_DEPTH_TEXTURE_SAMPLES,
	mp_list<oglplus::limit_query>
> max_depth_texture_samples = {};
#endif

#ifdef GL_MAX_DRAW_BUFFERS
static constexpr const enum_value<
	GLenum,
	GL_MAX_DRAW_BUFFERS,
	mp_list<oglplus::limit_query>
> max_draw_buffers = {};
#endif

#ifdef GL_MAX_DUAL_SOURCE_DRAW_BUFFERS
static constexpr const enum_value<
	GLenum,
	GL_MAX_DUAL_SOURCE_DRAW_BUFFERS,
	mp_list<oglplus::limit_query>
> max_dual_source_draw_buffers = {};
#endif

#ifdef GL_MAX_ELEMENTS_INDICES
static constexpr const enum_value<
	GLenum,
	GL_MAX_ELEMENTS_INDICES,
	mp_list<oglplus::limit_query>
> max_elements_indices = {};
#endif

#ifdef GL_MAX_ELEMENTS_VERTICES
static constexpr const enum_value<
	GLenum,
	GL_MAX_ELEMENTS_VERTICES,
	mp_list<oglplus::limit_query>
> max_elements_vertices = {};
#endif

#ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS
static constexpr const enum_value<
	GLenum,
	GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS,
	mp_list<oglplus::limit_query>
> max_fragment_atomic_counter_buffers = {};
#endif

#ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTERS
static constexpr const enum_value<
	GLenum,
	GL_MAX_FRAGMENT_ATOMIC_COUNTERS,
	mp_list<oglplus::limit_query>
> max_fragment_atomic_counters = {};
#endif

#ifdef GL_MAX_FRAGMENT_IMAGE_UNIFORMS
static constexpr const enum_value<
	GLenum,
	GL_MAX_FRAGMENT_IMAGE_UNIFORMS,
	mp_list<oglplus::limit_query>
> max_fragment_image_uniforms = {};
#endif

#ifdef GL_MAX_FRAGMENT_INPUT_COMPONENTS
static constexpr const enum_value<
	GLenum,
	GL_MAX_FRAGMENT_INPUT_COMPONENTS,
	mp_list<oglplus::limit_query>
> max_fragment_input_components = {};
#endif

#ifdef GL_MAX_FRAGMENT_INTERPOLATION_OFFSET
static constexpr const enum_value<
	GLenum,
	GL_MAX_FRAGMENT_INTERPOLATION_OFFSET,
	mp_list<oglplus::limit_query>
> max_fragment_interpolation_offset = {};
#endif

#ifdef GL_MAX_FRAGMENT_UNIFORM_BLOCKS
static constexpr const enum_value<
	GLenum,
	GL_MAX_FRAGMENT_UNIFORM_BLOCKS,
	mp_list<oglplus::limit_query>
> max_fragment_uniform_blocks = {};
#endif

#ifdef GL_MAX_FRAGMENT_UNIFORM_COMPONENTS
static constexpr const enum_value<
	GLenum,
	GL_MAX_FRAGMENT_UNIFORM_COMPONENTS,
	mp_list<oglplus::limit_query>
> max_fragment_uniform_components = {};
#endif

#ifdef GL_MAX_FRAGMENT_UNIFORM_VECTORS
static constexpr const enum_value<
	GLenum,
	GL_MAX_FRAGMENT_UNIFORM_VECTORS,
	mp_list<oglplus::limit_query>
> max_fragment_uniform_vectors = {};
#endif

#ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS
static constexpr const enum_value<
	GLenum,
	GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS,
	mp_list<oglplus::limit_query>
> max_geometry_atomic_counter_buffers = {};
#endif

#ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTERS
static constexpr const enum_value<
	GLenum,
	GL_MAX_GEOMETRY_ATOMIC_COUNTERS,
	mp_list<oglplus::limit_query>
> max_geometry_atomic_counters = {};
#endif

#ifdef GL_MAX_GEOMETRY_IMAGE_UNIFORMS
static constexpr const enum_value<
	GLenum,
	GL_MAX_GEOMETRY_IMAGE_UNIFORMS,
	mp_list<oglplus::limit_query>
> max_geometry_image_uniforms = {};
#endif

#ifdef GL_MAX_GEOMETRY_INPUT_COMPONENTS
static constexpr const enum_value<
	GLenum,
	GL_MAX_GEOMETRY_INPUT_COMPONENTS,
	mp_list<oglplus::limit_query>
> max_geometry_input_components = {};
#endif

#ifdef GL_MAX_GEOMETRY_OUTPUT_COMPONENTS
static constexpr const enum_value<
	GLenum,
	GL_MAX_GEOMETRY_OUTPUT_COMPONENTS,
	mp_list<oglplus::limit_query>
> max_geometry_output_components = {};
#endif

#ifdef GL_MAX_GEOMETRY_OUTPUT_VERTICES
static constexpr const enum_value<
	GLenum,
	GL_MAX_GEOMETRY_OUTPUT_VERTICES,
	mp_list<oglplus::limit_query>
> max_geometry_output_vertices = {};
#endif

#ifdef GL_MAX_GEOMETRY_SHADER_INVOCATIONS
static constexpr const enum_value<
	GLenum,
	GL_MAX_GEOMETRY_SHADER_INVOCATIONS,
	mp_list<oglplus::limit_query>
> max_geometry_shader_invocations = {};
#endif

#ifdef GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS
static constexpr const enum_value<
	GLenum,
	GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS,
	mp_list<oglplus::limit_query>
> max_geometry_texture_image_units = {};
#endif

#ifdef GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS
static constexpr const enum_value<
	GLenum,
	GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS,
	mp_list<oglplus::limit_query>
> max_geometry_total_output_components = {};
#endif

#ifdef GL_MAX_GEOMETRY_UNIFORM_BLOCKS
static constexpr const enum_value<
	GLenum,
	GL_MAX_GEOMETRY_UNIFORM_BLOCKS,
	mp_list<oglplus::limit_query>
> max_geometry_uniform_blocks = {};
#endif

#ifdef GL_MAX_GEOMETRY_UNIFORM_COMPONENTS
static constexpr const enum_value<
	GLenum,
	GL_MAX_GEOMETRY_UNIFORM_COMPONENTS,
	mp_list<oglplus::limit_query>
> max_geometry_uniform_components = {};
#endif

#ifdef GL_MAX_IMAGE_SAMPLES
static constexpr const enum_value<
	GLenum,
	GL_MAX_IMAGE_SAMPLES,
	mp_list<oglplus::limit_query>
> max_image_samples = {};
#endif

#ifdef GL_MAX_IMAGE_UNITS
static constexpr const enum_value<
	GLenum,
	GL_MAX_IMAGE_UNITS,
	mp_list<oglplus::limit_query>
> max_image_units = {};
#endif

#ifdef GL_MAX_INTEGER_SAMPLES
static constexpr const enum_value<
	GLenum,
	GL_MAX_INTEGER_SAMPLES,
	mp_list<oglplus::limit_query>
> max_integer_samples = {};
#endif

#ifdef GL_MAX_PATCH_VERTICES
static constexpr const enum_value<
	GLenum,
	GL_MAX_PATCH_VERTICES,
	mp_list<oglplus::limit_query>
> max_patch_vertices = {};
#endif

#ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
static constexpr const enum_value<
	GLenum,
	GL_MAX_PROGRAM_TEXEL_OFFSET,
	mp_list<oglplus::limit_query>
> max_program_texel_offset = {};
#endif

#ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
static constexpr const enum_value<
	GLenum,
	GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET,
	mp_list<oglplus::limit_query>
> max_program_texture_gather_offset = {};
#endif

#ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
static constexpr const enum_value<
	GLenum,
	GL_MAX_RECTANGLE_TEXTURE_SIZE,
	mp_list<oglplus::limit_query>
> max_rectangle_texture_size = {};
#endif

#ifdef GL_MAX_RENDERBUFFER_SIZE
static constexpr const enum_value<
	GLenum,
	GL_MAX_RENDERBUFFER_SIZE,
	mp_list<oglplus::limit_query>
> max_renderbuffer_size = {};
#endif

#ifdef GL_MAX_SAMPLE_MASK_WORDS
static constexpr const enum_value<
	GLenum,
	GL_MAX_SAMPLE_MASK_WORDS,
	mp_list<oglplus::limit_query>
> max_sample_mask_words = {};
#endif

#ifdef GL_MAX_SAMPLES
static constexpr const enum_value<
	GLenum,
	GL_MAX_SAMPLES,
	mp_list<oglplus::limit_query>
> max_samples = {};
#endif

#ifdef GL_MAX_SERVER_WAIT_TIMEOUT
static constexpr const enum_value<
	GLenum,
	GL_MAX_SERVER_WAIT_TIMEOUT,
	mp_list<oglplus::limit_query>
> max_server_wait_timeout = {};
#endif

#ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
static constexpr const enum_value<
	GLenum,
	GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS,
	mp_list<oglplus::limit_query>
> max_subroutine_uniform_locations = {};
#endif

#ifdef GL_MAX_SUBROUTINES
static constexpr const enum_value<
	GLenum,
	GL_MAX_SUBROUTINES,
	mp_list<oglplus::limit_query>
> max_subroutines = {};
#endif

#ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
static constexpr const enum_value<
	GLenum,
	GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS,
	mp_list<oglplus::limit_query>
> max_tess_control_atomic_counter_buffers = {};
#endif

#ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
static constexpr const enum_value<
	GLenum,
	GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS,
	mp_list<oglplus::limit_query>
> max_tess_control_atomic_counters = {};
#endif

#ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
static constexpr const enum_value<
	GLenum,
	GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS,
	mp_list<oglplus::limit_query>
> max_tess_control_image_uniforms = {};
#endif

#ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
static constexpr const enum_value<
	GLenum,
	GL_MAX_TESS_CONTROL_INPUT_COMPONENTS,
	mp_list<oglplus::limit_query>
> max_tess_control_input_components = {};
#endif

#ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
static constexpr const enum_value<
	GLenum,
	GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS,
	mp_list<oglplus::limit_query>
> max_tess_control_output_components = {};
#endif

#ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
static constexpr const enum_value<
	GLenum,
	GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS,
	mp_list<oglplus::limit_query>
> max_tess_control_texture_image_units = {};
#endif

#ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
static constexpr const enum_value<
	GLenum,
	GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS,
	mp_list<oglplus::limit_query>
> max_tess_control_total_output_components = {};
#endif

#ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
static constexpr const enum_value<
	GLenum,
	GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS,
	mp_list<oglplus::limit_query>
> max_tess_control_uniform_blocks = {};
#endif

#ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
static constexpr const enum_value<
	GLenum,
	GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS,
	mp_list<oglplus::limit_query>
> max_tess_control_uniform_components = {};
#endif

#ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
static constexpr const enum_value<
	GLenum,
	GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS,
	mp_list<oglplus::limit_query>
> max_tess_evaluation_atomic_counter_buffers = {};
#endif

#ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
static constexpr const enum_value<
	GLenum,
	GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS,
	mp_list<oglplus::limit_query>
> max_tess_evaluation_atomic_counters = {};
#endif

#ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
static constexpr const enum_value<
	GLenum,
	GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS,
	mp_list<oglplus::limit_query>
> max_tess_evaluation_image_uniforms = {};
#endif

#ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
static constexpr const enum_value<
	GLenum,
	GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS,
	mp_list<oglplus::limit_query>
> max_tess_evaluation_input_components = {};
#endif

#ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
static constexpr const enum_value<
	GLenum,
	GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS,
	mp_list<oglplus::limit_query>
> max_tess_evaluation_output_components = {};
#endif

#ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
static constexpr const enum_value<
	GLenum,
	GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS,
	mp_list<oglplus::limit_query>
> max_tess_evaluation_texture_image_units = {};
#endif

#ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
static constexpr const enum_value<
	GLenum,
	GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS,
	mp_list<oglplus::limit_query>
> max_tess_evaluation_uniform_blocks = {};
#endif

#ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
static constexpr const enum_value<
	GLenum,
	GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS,
	mp_list<oglplus::limit_query>
> max_tess_evaluation_uniform_components = {};
#endif

#ifdef GL_MAX_TESS_GEN_LEVEL
static constexpr const enum_value<
	GLenum,
	GL_MAX_TESS_GEN_LEVEL,
	mp_list<oglplus::limit_query>
> max_tess_gen_level = {};
#endif

#ifdef GL_MAX_TESS_PATCH_COMPONENTS
static constexpr const enum_value<
	GLenum,
	GL_MAX_TESS_PATCH_COMPONENTS,
	mp_list<oglplus::limit_query>
> max_tess_patch_components = {};
#endif

#ifdef GL_MAX_TEXTURE_BUFFER_SIZE
static constexpr const enum_value<
	GLenum,
	GL_MAX_TEXTURE_BUFFER_SIZE,
	mp_list<oglplus::limit_query>
> max_texture_buffer_size = {};
#endif

#ifdef GL_MAX_TEXTURE_IMAGE_UNITS
static constexpr const enum_value<
	GLenum,
	GL_MAX_TEXTURE_IMAGE_UNITS,
	mp_list<oglplus::limit_query>
> max_texture_image_units = {};
#endif

#ifdef GL_MAX_TEXTURE_LOD_BIAS
static constexpr const enum_value<
	GLenum,
	GL_MAX_TEXTURE_LOD_BIAS,
	mp_list<oglplus::limit_query>
> max_texture_lod_bias = {};
#endif

#ifdef GL_MAX_TEXTURE_SIZE
static constexpr const enum_value<
	GLenum,
	GL_MAX_TEXTURE_SIZE,
	mp_list<oglplus::limit_query>
> max_texture_size = {};
#endif

#ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
static constexpr const enum_value<
	GLenum,
	GL_MAX_TRANSFORM_FEEDBACK_BUFFERS,
	mp_list<oglplus::limit_query>
> max_transform_feedback_buffers = {};
#endif

#ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
static constexpr const enum_value<
	GLenum,
	GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS,
	mp_list<oglplus::limit_query>
> max_transform_feedback_interleaved_components = {};
#endif

#ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
static constexpr const enum_value<
	GLenum,
	GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS,
	mp_list<oglplus::limit_query>
> max_transform_feedback_separate_attribs = {};
#endif

#ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
static constexpr const enum_value<
	GLenum,
	GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS,
	mp_list<oglplus::limit_query>
> max_transform_feedback_separate_components = {};
#endif

#ifdef GL_MAX_UNIFORM_BLOCK_SIZE
static constexpr const enum_value<
	GLenum,
	GL_MAX_UNIFORM_BLOCK_SIZE,
	mp_list<oglplus::limit_query>
> max_uniform_block_size = {};
#endif

#ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
static constexpr const enum_value<
	GLenum,
	GL_MAX_UNIFORM_BUFFER_BINDINGS,
	mp_list<oglplus::limit_query>
> max_uniform_buffer_bindings = {};
#endif

#ifdef GL_MAX_VARYING_COMPONENTS
static constexpr const enum_value<
	GLenum,
	GL_MAX_VARYING_COMPONENTS,
	mp_list<oglplus::limit_query>
> max_varying_components = {};
#endif

#ifdef GL_MAX_VARYING_VECTORS
static constexpr const enum_value<
	GLenum,
	GL_MAX_VARYING_VECTORS,
	mp_list<oglplus::limit_query>
> max_varying_vectors = {};
#endif

#ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
static constexpr const enum_value<
	GLenum,
	GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS,
	mp_list<oglplus::limit_query>
> max_vertex_atomic_counter_buffers = {};
#endif

#ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
static constexpr const enum_value<
	GLenum,
	GL_MAX_VERTEX_ATOMIC_COUNTERS,
	mp_list<oglplus::limit_query>
> max_vertex_atomic_counters = {};
#endif

#ifdef GL_MAX_VERTEX_ATTRIBS
static constexpr const enum_value<
	GLenum,
	GL_MAX_VERTEX_ATTRIBS,
	mp_list<oglplus::limit_query>
> max_vertex_attribs = {};
#endif

#ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
static constexpr const enum_value<
	GLenum,
	GL_MAX_VERTEX_IMAGE_UNIFORMS,
	mp_list<oglplus::limit_query>
> max_vertex_image_uniforms = {};
#endif

#ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
static constexpr const enum_value<
	GLenum,
	GL_MAX_VERTEX_OUTPUT_COMPONENTS,
	mp_list<oglplus::limit_query>
> max_vertex_output_components = {};
#endif

#ifdef GL_MAX_VERTEX_STREAMS
static constexpr const enum_value<
	GLenum,
	GL_MAX_VERTEX_STREAMS,
	mp_list<oglplus::limit_query>
> max_vertex_streams = {};
#endif

#ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
static constexpr const enum_value<
	GLenum,
	GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS,
	mp_list<oglplus::limit_query>
> max_vertex_texture_image_units = {};
#endif

#ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
static constexpr const enum_value<
	GLenum,
	GL_MAX_VERTEX_UNIFORM_BLOCKS,
	mp_list<oglplus::limit_query>
> max_vertex_uniform_blocks = {};
#endif

#ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
static constexpr const enum_value<
	GLenum,
	GL_MAX_VERTEX_UNIFORM_COMPONENTS,
	mp_list<oglplus::limit_query>
> max_vertex_uniform_components = {};
#endif

#ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
static constexpr const enum_value<
	GLenum,
	GL_MAX_VERTEX_UNIFORM_VECTORS,
	mp_list<oglplus::limit_query>
> max_vertex_uniform_vectors = {};
#endif

#ifdef GL_MAX_VIEWPORT_DIMS
static constexpr const enum_value<
	GLenum,
	GL_MAX_VIEWPORT_DIMS,
	mp_list<oglplus::limit_query>
> max_viewport_dims = {};
#endif

#ifdef GL_MAX_VIEWPORTS
static constexpr const enum_value<
	GLenum,
	GL_MAX_VIEWPORTS,
	mp_list<oglplus::limit_query>
> max_viewports = {};
#endif

#ifdef GL_MEDIUM_FLOAT
static constexpr const enum_value<
	GLenum,
	GL_MEDIUM_FLOAT,
	mp_list<oglplus::precision_type>
> medium_float = {};
#endif

#ifdef GL_MEDIUM_INT
static constexpr const enum_value<
	GLenum,
	GL_MEDIUM_INT,
	mp_list<oglplus::precision_type>
> medium_int = {};
#endif

#ifdef GL_MIN
static constexpr const enum_value<
	GLenum,
	GL_MIN,
	mp_list<oglplus::blend_equation>
> min = {};
#endif

#ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
static constexpr const enum_value<
	GLenum,
	GL_MIN_FRAGMENT_INTERPOLATION_OFFSET,
	mp_list<oglplus::limit_query>
> min_fragment_interpolation_offset = {};
#endif

#ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
static constexpr const enum_value<
	GLenum,
	GL_MIN_MAP_BUFFER_ALIGNMENT,
	mp_list<oglplus::limit_query>
> min_map_buffer_alignment = {};
#endif

#ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
static constexpr const enum_value<
	GLenum,
	GL_MIN_PROGRAM_TEXEL_OFFSET,
	mp_list<oglplus::limit_query>
> min_program_texel_offset = {};
#endif

#ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
static constexpr const enum_value<
	GLenum,
	GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET,
	mp_list<oglplus::limit_query>
> min_program_texture_gather_offset = {};
#endif

#ifdef GL_MIRROR_CLAMP_TO_EDGE
static constexpr const enum_value<
	GLenum,
	GL_MIRROR_CLAMP_TO_EDGE,
	mp_list<oglplus::texture_wrap_mode>
> mirror_clamp_to_edge = {};
#endif

#ifdef GL_MIRRORED_REPEAT
static constexpr const enum_value<
	GLenum,
	GL_MIRRORED_REPEAT,
	mp_list<oglplus::texture_wrap_mode>
> mirrored_repeat = {};
#endif

#ifdef GL_MITER_REVERT_NV
static constexpr const enum_value<
	GLenum,
	GL_MITER_REVERT_NV,
	mp_list<oglplus::path_join_style_nv>
> miter_revert_nv = {};
#endif

#ifdef GL_MITER_TRUNCATE_NV
static constexpr const enum_value<
	GLenum,
	GL_MITER_TRUNCATE_NV,
	mp_list<oglplus::path_join_style_nv>
> miter_truncate_nv = {};
#endif

#ifdef GL_MODELVIEW
static constexpr const enum_value<
	GLenum,
	GL_MODELVIEW,
	mp_list<oglplus::old_matrix_mode>
> modelview = {};
#endif

#ifdef GL_MOVE_TO_CONTINUES_NV
static constexpr const enum_value<
	GLenum,
	GL_MOVE_TO_CONTINUES_NV,
	mp_list<oglplus::path_dash_offset_reset_nv>
> move_to_continues_nv = {};
#endif

#ifdef GL_MOVE_TO_NV
static constexpr const enum_value<
	GLubyte,
	GL_MOVE_TO_NV,
	mp_list<oglplus::path_command_nv>
> move_to_nv = {};
#endif

#ifdef GL_MOVE_TO_RESET_NV
static constexpr const enum_value<
	GLenum,
	GL_MOVE_TO_RESET_NV,
	mp_list<oglplus::path_dash_offset_reset_nv>
> move_to_reset_nv = {};
#endif

#ifdef GL_MULTIPLY_KHR
static constexpr const enum_value<
	GLenum,
	GL_MULTIPLY_KHR,
	mp_list<oglplus::blend_equation_advanced>
> multiply_khr = {};
#endif

#ifdef GL_MULTISAMPLE
static constexpr const enum_value<
	GLenum,
	GL_MULTISAMPLE,
	mp_list<oglplus::capability>
> multisample = {};
#endif

#ifdef GL_NAND
static constexpr const enum_value<
	GLenum,
	GL_NAND,
	mp_list<oglplus::color_logic_operation>
> nand = {};
#endif

#ifdef GL_NEAREST
static constexpr const enum_value<
	GLenum,
	GL_NEAREST,
	mp_list<oglplus::texture_mag_filter,oglplus::blit_filter,oglplus::texture_filter,oglplus::texture_min_filter>
> nearest = {};
#endif

#ifdef GL_NEAREST_MIPMAP_LINEAR
static constexpr const enum_value<
	GLenum,
	GL_NEAREST_MIPMAP_LINEAR,
	mp_list<oglplus::texture_min_filter>
> nearest_mipmap_linear = {};
#endif

#ifdef GL_NEAREST_MIPMAP_NEAREST
static constexpr const enum_value<
	GLenum,
	GL_NEAREST_MIPMAP_NEAREST,
	mp_list<oglplus::texture_min_filter>
> nearest_mipmap_nearest = {};
#endif

#ifdef GL_NEGATIVE_ONE_TO_ONE
static constexpr const enum_value<
	GLenum,
	GL_NEGATIVE_ONE_TO_ONE,
	mp_list<oglplus::clip_depth_mode>
> negative_one_to_one = {};
#endif

#ifdef GL_NEVER
static constexpr const enum_value<
	GLenum,
	GL_NEVER,
	mp_list<oglplus::compare_function>
> never = {};
#endif

#ifdef GL_NICEST
static constexpr const enum_value<
	GLenum,
	GL_NICEST,
	mp_list<oglplus::hint_option>
> nicest = {};
#endif

#ifdef GL_NO_ERROR
static constexpr const enum_value<
	GLenum,
	GL_NO_ERROR,
	mp_list<oglplus::graphics_reset_status,oglplus::error_code>
> no_error = {};
#endif

#ifdef GL_NO_RESET_NOTIFICATION
static constexpr const enum_value<
	GLenum,
	GL_NO_RESET_NOTIFICATION,
	mp_list<oglplus::reset_notification_strategy>
> no_reset_notification = {};
#endif

#ifdef GL_NONE
static constexpr const enum_value<
	GLenum,
	GL_NONE,
	mp_list<oglplus::sl_data_type,oglplus::context_release_behavior,oglplus::color_buffer,oglplus::object_type,oglplus::texture_compare_mode,oglplus::path_transform_type_nv,oglplus::path_join_style_nv,oglplus::path_gen_mode_nv>
> none = {};
#endif

#ifdef GL_NOOP
static constexpr const enum_value<
	GLenum,
	GL_NOOP,
	mp_list<oglplus::color_logic_operation>
> noop = {};
#endif

#ifdef GL_NOR
static constexpr const enum_value<
	GLenum,
	GL_NOR,
	mp_list<oglplus::color_logic_operation>
> nor = {};
#endif

#ifdef GL_NOTEQUAL
static constexpr const enum_value<
	GLenum,
	GL_NOTEQUAL,
	mp_list<oglplus::compare_function>
> notequal = {};
#endif

#ifdef GL_NUM_ACTIVE_VARIABLES
static constexpr const enum_value<
	GLenum,
	GL_NUM_ACTIVE_VARIABLES,
	mp_list<oglplus::program_resource_property>
> num_active_variables = {};
#endif

#ifdef GL_NUM_COMPATIBLE_SUBROUTINES
static constexpr const enum_value<
	GLenum,
	GL_NUM_COMPATIBLE_SUBROUTINES,
	mp_list<oglplus::program_resource_property>
> num_compatible_subroutines = {};
#endif

#ifdef GL_NUM_COMPRESSED_TEXTURE_FORMATS
static constexpr const enum_value<
	GLenum,
	GL_NUM_COMPRESSED_TEXTURE_FORMATS,
	mp_list<oglplus::numeric_query>
> num_compressed_texture_formats = {};
#endif

#ifdef GL_NUM_EXTENSIONS
static constexpr const enum_value<
	GLenum,
	GL_NUM_EXTENSIONS,
	mp_list<oglplus::numeric_query>
> num_extensions = {};
#endif

#ifdef GL_NUM_PROGRAM_BINARY_FORMATS
static constexpr const enum_value<
	GLenum,
	GL_NUM_PROGRAM_BINARY_FORMATS,
	mp_list<oglplus::numeric_query>
> num_program_binary_formats = {};
#endif

#ifdef GL_NUM_SHADER_BINARY_FORMATS
static constexpr const enum_value<
	GLenum,
	GL_NUM_SHADER_BINARY_FORMATS,
	mp_list<oglplus::numeric_query>
> num_shader_binary_formats = {};
#endif

#ifdef GL_OBJECT_LINEAR
static constexpr const enum_value<
	GLenum,
	GL_OBJECT_LINEAR,
	mp_list<oglplus::path_gen_mode_nv>
> object_linear = {};
#endif

#ifdef GL_OFFSET
static constexpr const enum_value<
	GLenum,
	GL_OFFSET,
	mp_list<oglplus::program_resource_property>
> offset = {};
#endif

#ifdef GL_ONE
static constexpr const enum_value<
	GLenum,
	GL_ONE,
	mp_list<oglplus::blend_function,oglplus::texture_swizzle_mode>
> one = {};
#endif

#ifdef GL_ONE_MINUS_CONSTANT_ALPHA
static constexpr const enum_value<
	GLenum,
	GL_ONE_MINUS_CONSTANT_ALPHA,
	mp_list<oglplus::blend_function>
> one_minus_constant_alpha = {};
#endif

#ifdef GL_ONE_MINUS_CONSTANT_COLOR
static constexpr const enum_value<
	GLenum,
	GL_ONE_MINUS_CONSTANT_COLOR,
	mp_list<oglplus::blend_function>
> one_minus_constant_color = {};
#endif

#ifdef GL_ONE_MINUS_DST_ALPHA
static constexpr const enum_value<
	GLenum,
	GL_ONE_MINUS_DST_ALPHA,
	mp_list<oglplus::blend_function>
> one_minus_dst_alpha = {};
#endif

#ifdef GL_ONE_MINUS_DST_COLOR
static constexpr const enum_value<
	GLenum,
	GL_ONE_MINUS_DST_COLOR,
	mp_list<oglplus::blend_function>
> one_minus_dst_color = {};
#endif

#ifdef GL_ONE_MINUS_SRC1_ALPHA
static constexpr const enum_value<
	GLenum,
	GL_ONE_MINUS_SRC1_ALPHA,
	mp_list<oglplus::blend_function>
> one_minus_src1_alpha = {};
#endif

#ifdef GL_ONE_MINUS_SRC1_COLOR
static constexpr const enum_value<
	GLenum,
	GL_ONE_MINUS_SRC1_COLOR,
	mp_list<oglplus::blend_function>
> one_minus_src1_color = {};
#endif

#ifdef GL_ONE_MINUS_SRC_ALPHA
static constexpr const enum_value<
	GLenum,
	GL_ONE_MINUS_SRC_ALPHA,
	mp_list<oglplus::blend_function>
> one_minus_src_alpha = {};
#endif

#ifdef GL_ONE_MINUS_SRC_COLOR
static constexpr const enum_value<
	GLenum,
	GL_ONE_MINUS_SRC_COLOR,
	mp_list<oglplus::blend_function>
> one_minus_src_color = {};
#endif

#ifdef GL_OR
static constexpr const enum_value<
	GLenum,
	GL_OR,
	mp_list<oglplus::color_logic_operation>
> or_ = {};
#endif

#ifdef GL_OR_INVERTED
static constexpr const enum_value<
	GLenum,
	GL_OR_INVERTED,
	mp_list<oglplus::color_logic_operation>
> or_inverted = {};
#endif

#ifdef GL_OR_REVERSE
static constexpr const enum_value<
	GLenum,
	GL_OR_REVERSE,
	mp_list<oglplus::color_logic_operation>
> or_reverse = {};
#endif

#ifdef GL_OUT_OF_MEMORY
static constexpr const enum_value<
	GLenum,
	GL_OUT_OF_MEMORY,
	mp_list<oglplus::error_code>
> out_of_memory = {};
#endif

#ifdef GL_OVERLAY_KHR
static constexpr const enum_value<
	GLenum,
	GL_OVERLAY_KHR,
	mp_list<oglplus::blend_equation_advanced>
> overlay_khr = {};
#endif

#ifdef GL_PACK_ALIGNMENT
static constexpr const enum_value<
	GLenum,
	GL_PACK_ALIGNMENT,
	mp_list<oglplus::numeric_query,oglplus::pixel_parameter>
> pack_alignment = {};
#endif

#ifdef GL_PACK_COMPRESSED_BLOCK_DEPTH
static constexpr const enum_value<
	GLenum,
	GL_PACK_COMPRESSED_BLOCK_DEPTH,
	mp_list<oglplus::pixel_parameter>
> pack_compressed_block_depth = {};
#endif

#ifdef GL_PACK_COMPRESSED_BLOCK_HEIGHT
static constexpr const enum_value<
	GLenum,
	GL_PACK_COMPRESSED_BLOCK_HEIGHT,
	mp_list<oglplus::pixel_parameter>
> pack_compressed_block_height = {};
#endif

#ifdef GL_PACK_COMPRESSED_BLOCK_SIZE
static constexpr const enum_value<
	GLenum,
	GL_PACK_COMPRESSED_BLOCK_SIZE,
	mp_list<oglplus::pixel_parameter>
> pack_compressed_block_size = {};
#endif

#ifdef GL_PACK_COMPRESSED_BLOCK_WIDTH
static constexpr const enum_value<
	GLenum,
	GL_PACK_COMPRESSED_BLOCK_WIDTH,
	mp_list<oglplus::pixel_parameter>
> pack_compressed_block_width = {};
#endif

#ifdef GL_PACK_IMAGE_HEIGHT
static constexpr const enum_value<
	GLenum,
	GL_PACK_IMAGE_HEIGHT,
	mp_list<oglplus::numeric_query,oglplus::pixel_parameter>
> pack_image_height = {};
#endif

#ifdef GL_PACK_LSB_FIRST
static constexpr const enum_value<
	GLenum,
	GL_PACK_LSB_FIRST,
	mp_list<oglplus::numeric_query,oglplus::pixel_parameter>
> pack_lsb_first = {};
#endif

#ifdef GL_PACK_ROW_LENGTH
static constexpr const enum_value<
	GLenum,
	GL_PACK_ROW_LENGTH,
	mp_list<oglplus::numeric_query,oglplus::pixel_parameter>
> pack_row_length = {};
#endif

#ifdef GL_PACK_SKIP_IMAGES
static constexpr const enum_value<
	GLenum,
	GL_PACK_SKIP_IMAGES,
	mp_list<oglplus::numeric_query,oglplus::pixel_parameter>
> pack_skip_images = {};
#endif

#ifdef GL_PACK_SKIP_PIXELS
static constexpr const enum_value<
	GLenum,
	GL_PACK_SKIP_PIXELS,
	mp_list<oglplus::numeric_query,oglplus::pixel_parameter>
> pack_skip_pixels = {};
#endif

#ifdef GL_PACK_SKIP_ROWS
static constexpr const enum_value<
	GLenum,
	GL_PACK_SKIP_ROWS,
	mp_list<oglplus::numeric_query,oglplus::pixel_parameter>
> pack_skip_rows = {};
#endif

#ifdef GL_PACK_SWAP_BYTES
static constexpr const enum_value<
	GLenum,
	GL_PACK_SWAP_BYTES,
	mp_list<oglplus::numeric_query,oglplus::pixel_parameter>
> pack_swap_bytes = {};
#endif

#ifdef GL_PARAMETER_BUFFER_ARB
static constexpr const enum_value<
	GLenum,
	GL_PARAMETER_BUFFER_ARB,
	mp_list<oglplus::buffer_target>
> parameter_buffer = {};
#endif

#ifdef GL_PARAMETER_BUFFER_BINDING_ARB
static constexpr const enum_value<
	GLenum,
	GL_PARAMETER_BUFFER_BINDING_ARB,
	mp_list<oglplus::binding_query>
> parameter_buffer_binding = {};
#endif

#ifdef GL_PATCH_DEFAULT_INNER_LEVEL
static constexpr const enum_value<
	GLenum,
	GL_PATCH_DEFAULT_INNER_LEVEL,
	mp_list<oglplus::patch_parameter>
> patch_default_inner_level = {};
#endif

#ifdef GL_PATCH_DEFAULT_OUTER_LEVEL
static constexpr const enum_value<
	GLenum,
	GL_PATCH_DEFAULT_OUTER_LEVEL,
	mp_list<oglplus::patch_parameter>
> patch_default_outer_level = {};
#endif

#ifdef GL_PATCH_VERTICES
static constexpr const enum_value<
	GLenum,
	GL_PATCH_VERTICES,
	mp_list<oglplus::patch_parameter>
> patch_vertices = {};
#endif

#ifdef GL_PATCHES
static constexpr const enum_value<
	GLenum,
	GL_PATCHES,
	mp_list<oglplus::primitive_type>
> patches = {};
#endif

#ifdef GL_PATH_CLIENT_LENGTH_NV
static constexpr const enum_value<
	GLenum,
	GL_PATH_CLIENT_LENGTH_NV,
	mp_list<oglplus::path_parameter_nv>
> path_client_length_nv = {};
#endif

#ifdef GL_PATH_COMMAND_COUNT_NV
static constexpr const enum_value<
	GLenum,
	GL_PATH_COMMAND_COUNT_NV,
	mp_list<oglplus::path_parameter_nv>
> path_command_count_nv = {};
#endif

#ifdef GL_PATH_COMPUTED_LENGTH_NV
static constexpr const enum_value<
	GLenum,
	GL_PATH_COMPUTED_LENGTH_NV,
	mp_list<oglplus::path_parameter_nv>
> path_computed_length_nv = {};
#endif

#ifdef GL_PATH_COORD_COUNT_NV
static constexpr const enum_value<
	GLenum,
	GL_PATH_COORD_COUNT_NV,
	mp_list<oglplus::path_parameter_nv>
> path_coord_count_nv = {};
#endif

#ifdef GL_PATH_DASH_ARRAY_COUNT_NV
static constexpr const enum_value<
	GLenum,
	GL_PATH_DASH_ARRAY_COUNT_NV,
	mp_list<oglplus::path_parameter_nv>
> path_dash_array_count_nv = {};
#endif

#ifdef GL_PATH_DASH_OFFSET_NV
static constexpr const enum_value<
	GLenum,
	GL_PATH_DASH_OFFSET_NV,
	mp_list<oglplus::path_parameter_nv>
> path_dash_offset_nv = {};
#endif

#ifdef GL_PATH_DASH_OFFSET_RESET_NV
static constexpr const enum_value<
	GLenum,
	GL_PATH_DASH_OFFSET_RESET_NV,
	mp_list<oglplus::path_parameter_nv>
> path_dash_offset_reset_nv = {};
#endif

#ifdef GL_PATH_FILL_BOUNDING_BOX_NV
static constexpr const enum_value<
	GLenum,
	GL_PATH_FILL_BOUNDING_BOX_NV,
	mp_list<oglplus::path_parameter_nv>
> path_fill_bounding_box_nv = {};
#endif

#ifdef GL_PATH_FILL_COVER_MODE_NV
static constexpr const enum_value<
	GLenum,
	GL_PATH_FILL_COVER_MODE_NV,
	mp_list<oglplus::path_fill_cover_mode_nv,oglplus::path_parameter_nv>
> path_fill_cover_mode_nv = {};
#endif

#ifdef GL_PATH_FILL_MASK_NV
static constexpr const enum_value<
	GLenum,
	GL_PATH_FILL_MASK_NV,
	mp_list<oglplus::path_parameter_nv>
> path_fill_mask_nv = {};
#endif

#ifdef GL_PATH_FILL_MODE_NV
static constexpr const enum_value<
	GLenum,
	GL_PATH_FILL_MODE_NV,
	mp_list<oglplus::path_fill_mode_nv,oglplus::path_parameter_nv>
> path_fill_mode_nv = {};
#endif

#ifdef GL_PATH_FORMAT_PS_NV
static constexpr const enum_value<
	GLenum,
	GL_PATH_FORMAT_PS_NV,
	mp_list<oglplus::path_format_nv>
> path_format_ps_nv = {};
#endif

#ifdef GL_PATH_FORMAT_SVG_NV
static constexpr const enum_value<
	GLenum,
	GL_PATH_FORMAT_SVG_NV,
	mp_list<oglplus::path_format_nv>
> path_format_svg_nv = {};
#endif

#ifdef GL_PATH_INITIAL_DASH_CAP_NV
static constexpr const enum_value<
	GLenum,
	GL_PATH_INITIAL_DASH_CAP_NV,
	mp_list<oglplus::path_parameter_nv>
> path_initial_dash_cap_nv = {};
#endif

#ifdef GL_PATH_INITIAL_END_CAP_NV
static constexpr const enum_value<
	GLenum,
	GL_PATH_INITIAL_END_CAP_NV,
	mp_list<oglplus::path_parameter_nv>
> path_initial_end_cap_nv = {};
#endif

#ifdef GL_PATH_JOIN_STYLE_NV
static constexpr const enum_value<
	GLenum,
	GL_PATH_JOIN_STYLE_NV,
	mp_list<oglplus::path_parameter_nv>
> path_join_style_nv = {};
#endif

#ifdef GL_PATH_MITER_LIMIT_NV
static constexpr const enum_value<
	GLenum,
	GL_PATH_MITER_LIMIT_NV,
	mp_list<oglplus::path_parameter_nv>
> path_miter_limit_nv = {};
#endif

#ifdef GL_PATH_OBJECT_BOUNDING_BOX_NV
static constexpr const enum_value<
	GLenum,
	GL_PATH_OBJECT_BOUNDING_BOX_NV,
	mp_list<oglplus::path_parameter_nv,oglplus::path_gen_mode_nv>
> path_object_bounding_box_nv = {};
#endif

#ifdef GL_PATH_STROKE_BOUND_NV
static constexpr const enum_value<
	GLenum,
	GL_PATH_STROKE_BOUND_NV,
	mp_list<oglplus::path_parameter_nv>
> path_stroke_bound_nv = {};
#endif

#ifdef GL_PATH_STROKE_BOUNDING_BOX_NV
static constexpr const enum_value<
	GLenum,
	GL_PATH_STROKE_BOUNDING_BOX_NV,
	mp_list<oglplus::path_parameter_nv>
> path_stroke_bounding_box_nv = {};
#endif

#ifdef GL_PATH_STROKE_COVER_MODE_NV
static constexpr const enum_value<
	GLenum,
	GL_PATH_STROKE_COVER_MODE_NV,
	mp_list<oglplus::path_stroke_cover_mode_nv,oglplus::path_parameter_nv>
> path_stroke_cover_mode_nv = {};
#endif

#ifdef GL_PATH_STROKE_MASK_NV
static constexpr const enum_value<
	GLenum,
	GL_PATH_STROKE_MASK_NV,
	mp_list<oglplus::path_parameter_nv>
> path_stroke_mask_nv = {};
#endif

#ifdef GL_PATH_STROKE_WIDTH_NV
static constexpr const enum_value<
	GLenum,
	GL_PATH_STROKE_WIDTH_NV,
	mp_list<oglplus::path_parameter_nv>
> path_stroke_width_nv = {};
#endif

#ifdef GL_PATH_TERMINAL_DASH_CAP_NV
static constexpr const enum_value<
	GLenum,
	GL_PATH_TERMINAL_DASH_CAP_NV,
	mp_list<oglplus::path_parameter_nv>
> path_terminal_dash_cap_nv = {};
#endif

#ifdef GL_PATH_TERMINAL_END_CAP_NV
static constexpr const enum_value<
	GLenum,
	GL_PATH_TERMINAL_END_CAP_NV,
	mp_list<oglplus::path_parameter_nv>
> path_terminal_end_cap_nv = {};
#endif

#ifdef GL_PIXEL_BUFFER_BARRIER_BIT
static constexpr const enum_value<
	GLbitfield,
	GL_PIXEL_BUFFER_BARRIER_BIT,
	mp_list<oglplus::memory_barrier_bits>
> pixel_buffer_barrier_bit = {};
#endif

#ifdef GL_PIXEL_PACK_BUFFER
static constexpr const enum_value<
	GLenum,
	GL_PIXEL_PACK_BUFFER,
	mp_list<oglplus::buffer_target>
> pixel_pack_buffer = {};
#endif

#ifdef GL_PIXEL_PACK_BUFFER_BINDING
static constexpr const enum_value<
	GLenum,
	GL_PIXEL_PACK_BUFFER_BINDING,
	mp_list<oglplus::binding_query>
> pixel_pack_buffer_binding = {};
#endif

#ifdef GL_PIXEL_UNPACK_BUFFER
static constexpr const enum_value<
	GLenum,
	GL_PIXEL_UNPACK_BUFFER,
	mp_list<oglplus::buffer_target>
> pixel_unpack_buffer = {};
#endif

#ifdef GL_PIXEL_UNPACK_BUFFER_BINDING
static constexpr const enum_value<
	GLenum,
	GL_PIXEL_UNPACK_BUFFER_BINDING,
	mp_list<oglplus::binding_query>
> pixel_unpack_buffer_binding = {};
#endif

#ifdef GL_POINT
static constexpr const enum_value<
	GLenum,
	GL_POINT,
	mp_list<oglplus::polygon_mode>
> point = {};
#endif

#ifdef GL_POINT_FADE_THRESHOLD_SIZE
static constexpr const enum_value<
	GLenum,
	GL_POINT_FADE_THRESHOLD_SIZE,
	mp_list<oglplus::numeric_query>
> point_fade_threshold_size = {};
#endif

#ifdef GL_POINT_SIZE
static constexpr const enum_value<
	GLenum,
	GL_POINT_SIZE,
	mp_list<oglplus::numeric_query>
> point_size = {};
#endif

#ifdef GL_POINT_SIZE_GRANULARITY
static constexpr const enum_value<
	GLenum,
	GL_POINT_SIZE_GRANULARITY,
	mp_list<oglplus::numeric_query>
> point_size_granularity = {};
#endif

#ifdef GL_POINT_SIZE_RANGE
static constexpr const enum_value<
	GLenum,
	GL_POINT_SIZE_RANGE,
	mp_list<oglplus::numeric_query>
> point_size_range = {};
#endif

#ifdef GL_POINTS
static constexpr const enum_value<
	GLenum,
	GL_POINTS,
	mp_list<oglplus::primitive_type,oglplus::old_primitive_type,oglplus::transform_feedback_primitive_type>
> points = {};
#endif

#ifdef GL_POLYGON
static constexpr const enum_value<
	GLenum,
	GL_POLYGON,
	mp_list<oglplus::old_primitive_type>
> polygon = {};
#endif

#ifdef GL_POLYGON_OFFSET_FACTOR
static constexpr const enum_value<
	GLenum,
	GL_POLYGON_OFFSET_FACTOR,
	mp_list<oglplus::numeric_query>
> polygon_offset_factor = {};
#endif

#ifdef GL_POLYGON_OFFSET_FILL
static constexpr const enum_value<
	GLenum,
	GL_POLYGON_OFFSET_FILL,
	mp_list<oglplus::capability>
> polygon_offset_fill = {};
#endif

#ifdef GL_POLYGON_OFFSET_LINE
static constexpr const enum_value<
	GLenum,
	GL_POLYGON_OFFSET_LINE,
	mp_list<oglplus::capability>
> polygon_offset_line = {};
#endif

#ifdef GL_POLYGON_OFFSET_POINT
static constexpr const enum_value<
	GLenum,
	GL_POLYGON_OFFSET_POINT,
	mp_list<oglplus::capability>
> polygon_offset_point = {};
#endif

#ifdef GL_POLYGON_OFFSET_UNITS
static constexpr const enum_value<
	GLenum,
	GL_POLYGON_OFFSET_UNITS,
	mp_list<oglplus::numeric_query>
> polygon_offset_units = {};
#endif

#ifdef GL_POLYGON_SMOOTH
static constexpr const enum_value<
	GLenum,
	GL_POLYGON_SMOOTH,
	mp_list<oglplus::capability>
> polygon_smooth = {};
#endif

#ifdef GL_POLYGON_SMOOTH_HINT
static constexpr const enum_value<
	GLenum,
	GL_POLYGON_SMOOTH_HINT,
	mp_list<oglplus::hint_target,oglplus::numeric_query>
> polygon_smooth_hint = {};
#endif

#ifdef GL_PRIMARY_COLOR_NV
static constexpr const enum_value<
	GLenum,
	GL_PRIMARY_COLOR_NV,
	mp_list<oglplus::path_color_nv>
> primary_color_nv = {};
#endif

#ifdef GL_PRIMITIVE_RESTART
static constexpr const enum_value<
	GLenum,
	GL_PRIMITIVE_RESTART,
	mp_list<oglplus::capability>
> primitive_restart = {};
#endif

#ifdef GL_PRIMITIVE_RESTART_INDEX
static constexpr const enum_value<
	GLenum,
	GL_PRIMITIVE_RESTART_INDEX,
	mp_list<oglplus::numeric_query>
> primitive_restart_index = {};
#endif

#ifdef GL_PRIMITIVES_GENERATED
static constexpr const enum_value<
	GLenum,
	GL_PRIMITIVES_GENERATED,
	mp_list<oglplus::query_target>
> primitives_generated = {};
#endif

#ifdef GL_PRIMITIVES_SUBMITTED_ARB
static constexpr const enum_value<
	GLenum,
	GL_PRIMITIVES_SUBMITTED_ARB,
	mp_list<oglplus::query_target>
> primitives_submitted = {};
#endif

#ifdef GL_PROGRAM
static constexpr const enum_value<
	GLenum,
	GL_PROGRAM,
	mp_list<oglplus::object_type>
> program = {};
#endif

#ifdef GL_PROGRAM_BINARY_FORMATS
static constexpr const enum_value<
	GLenum,
	GL_PROGRAM_BINARY_FORMATS,
	mp_list<oglplus::numeric_query>
> program_binary_formats = {};
#endif

#ifdef GL_PROGRAM_INPUT
static constexpr const enum_value<
	GLenum,
	GL_PROGRAM_INPUT,
	mp_list<oglplus::program_interface>
> program_input = {};
#endif

#ifdef GL_PROGRAM_OUTPUT
static constexpr const enum_value<
	GLenum,
	GL_PROGRAM_OUTPUT,
	mp_list<oglplus::program_interface>
> program_output = {};
#endif

#ifdef GL_PROGRAM_PIPELINE
static constexpr const enum_value<
	GLenum,
	GL_PROGRAM_PIPELINE,
	mp_list<oglplus::object_type>
> program_pipeline = {};
#endif

#ifdef GL_PROGRAM_POINT_SIZE
static constexpr const enum_value<
	GLenum,
	GL_PROGRAM_POINT_SIZE,
	mp_list<oglplus::capability,oglplus::numeric_query>
> program_point_size = {};
#endif

#ifdef GL_PROJECTION
static constexpr const enum_value<
	GLenum,
	GL_PROJECTION,
	mp_list<oglplus::old_matrix_mode>
> projection = {};
#endif

#ifdef GL_PROVOKING_VERTEX
static constexpr const enum_value<
	GLenum,
	GL_PROVOKING_VERTEX,
	mp_list<oglplus::numeric_query>
> provoking_vertex = {};
#endif

#ifdef GL_QUAD_STRIP
static constexpr const enum_value<
	GLenum,
	GL_QUAD_STRIP,
	mp_list<oglplus::old_primitive_type>
> quad_strip = {};
#endif

#ifdef GL_QUADRATIC_CURVE_TO_NV
static constexpr const enum_value<
	GLubyte,
	GL_QUADRATIC_CURVE_TO_NV,
	mp_list<oglplus::path_command_nv>
> quadratic_curve_to_nv = {};
#endif

#ifdef GL_QUADS
static constexpr const enum_value<
	GLenum,
	GL_QUADS,
	mp_list<oglplus::old_primitive_type,oglplus::tess_gen_primitive_type>
> quads = {};
#endif

#ifdef GL_QUERY
static constexpr const enum_value<
	GLenum,
	GL_QUERY,
	mp_list<oglplus::object_type>
> query = {};
#endif

#ifdef GL_QUERY_BUFFER
static constexpr const enum_value<
	GLenum,
	GL_QUERY_BUFFER,
	mp_list<oglplus::buffer_target>
> query_buffer = {};
#endif

#ifdef GL_QUERY_BUFFER_BINDING
static constexpr const enum_value<
	GLenum,
	GL_QUERY_BUFFER_BINDING,
	mp_list<oglplus::binding_query>
> query_buffer_binding = {};
#endif

#ifdef GL_QUERY_BY_REGION_NO_WAIT
static constexpr const enum_value<
	GLenum,
	GL_QUERY_BY_REGION_NO_WAIT,
	mp_list<oglplus::conditional_render_mode>
> query_by_region_no_wait = {};
#endif

#ifdef GL_QUERY_BY_REGION_NO_WAIT_INVERTED
static constexpr const enum_value<
	GLenum,
	GL_QUERY_BY_REGION_NO_WAIT_INVERTED,
	mp_list<oglplus::conditional_render_mode>
> query_by_region_no_wait_inverted = {};
#endif

#ifdef GL_QUERY_BY_REGION_WAIT
static constexpr const enum_value<
	GLenum,
	GL_QUERY_BY_REGION_WAIT,
	mp_list<oglplus::conditional_render_mode>
> query_by_region_wait = {};
#endif

#ifdef GL_QUERY_BY_REGION_WAIT_INVERTED
static constexpr const enum_value<
	GLenum,
	GL_QUERY_BY_REGION_WAIT_INVERTED,
	mp_list<oglplus::conditional_render_mode>
> query_by_region_wait_inverted = {};
#endif

#ifdef GL_QUERY_NO_WAIT
static constexpr const enum_value<
	GLenum,
	GL_QUERY_NO_WAIT,
	mp_list<oglplus::conditional_render_mode>
> query_no_wait = {};
#endif

#ifdef GL_QUERY_NO_WAIT_INVERTED
static constexpr const enum_value<
	GLenum,
	GL_QUERY_NO_WAIT_INVERTED,
	mp_list<oglplus::conditional_render_mode>
> query_no_wait_inverted = {};
#endif

#ifdef GL_QUERY_RESULT
static constexpr const enum_value<
	GLenum,
	GL_QUERY_RESULT,
	mp_list<oglplus::query_parameter>
> query_result = {};
#endif

#ifdef GL_QUERY_RESULT_AVAILABLE
static constexpr const enum_value<
	GLenum,
	GL_QUERY_RESULT_AVAILABLE,
	mp_list<oglplus::query_parameter>
> query_result_available = {};
#endif

#ifdef GL_QUERY_WAIT
static constexpr const enum_value<
	GLenum,
	GL_QUERY_WAIT,
	mp_list<oglplus::conditional_render_mode>
> query_wait = {};
#endif

#ifdef GL_QUERY_WAIT_INVERTED
static constexpr const enum_value<
	GLenum,
	GL_QUERY_WAIT_INVERTED,
	mp_list<oglplus::conditional_render_mode>
> query_wait_inverted = {};
#endif

#ifdef GL_R11F_G11F_B10F
static constexpr const enum_value<
	GLenum,
	GL_R11F_G11F_B10F,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> r11f_g11f_b10f = {};
#endif

#ifdef GL_R16
static constexpr const enum_value<
	GLenum,
	GL_R16,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> r16 = {};
#endif

#ifdef GL_R16_SNORM
static constexpr const enum_value<
	GLenum,
	GL_R16_SNORM,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> r16_snorm = {};
#endif

#ifdef GL_R16F
static constexpr const enum_value<
	GLenum,
	GL_R16F,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> r16f = {};
#endif

#ifdef GL_R16I
static constexpr const enum_value<
	GLenum,
	GL_R16I,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> r16i = {};
#endif

#ifdef GL_R16UI
static constexpr const enum_value<
	GLenum,
	GL_R16UI,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> r16ui = {};
#endif

#ifdef GL_R32F
static constexpr const enum_value<
	GLenum,
	GL_R32F,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> r32f = {};
#endif

#ifdef GL_R32I
static constexpr const enum_value<
	GLenum,
	GL_R32I,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> r32i = {};
#endif

#ifdef GL_R32UI
static constexpr const enum_value<
	GLenum,
	GL_R32UI,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> r32ui = {};
#endif

#ifdef GL_R3_G3_B2
static constexpr const enum_value<
	GLenum,
	GL_R3_G3_B2,
	mp_list<oglplus::pixel_data_internal_format>
> r3_g3_b2 = {};
#endif

#ifdef GL_R8
static constexpr const enum_value<
	GLenum,
	GL_R8,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> r8 = {};
#endif

#ifdef GL_R8_SNORM
static constexpr const enum_value<
	GLenum,
	GL_R8_SNORM,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> r8_snorm = {};
#endif

#ifdef GL_R8I
static constexpr const enum_value<
	GLenum,
	GL_R8I,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> r8i = {};
#endif

#ifdef GL_R8UI
static constexpr const enum_value<
	GLenum,
	GL_R8UI,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> r8ui = {};
#endif

#ifdef GL_RASTERIZER_DISCARD
static constexpr const enum_value<
	GLenum,
	GL_RASTERIZER_DISCARD,
	mp_list<oglplus::capability>
> rasterizer_discard = {};
#endif

#ifdef GL_READ_BUFFER
static constexpr const enum_value<
	GLenum,
	GL_READ_BUFFER,
	mp_list<oglplus::numeric_query>
> read_buffer = {};
#endif

#ifdef GL_READ_FRAMEBUFFER
static constexpr const enum_value<
	GLenum,
	GL_READ_FRAMEBUFFER,
	mp_list<oglplus::framebuffer_target>
> read_framebuffer = {};
#endif

#ifdef GL_READ_ONLY
static constexpr const enum_value<
	GLenum,
	GL_READ_ONLY,
	mp_list<oglplus::access_specifier>
> read_only = {};
#endif

#ifdef GL_READ_WRITE
static constexpr const enum_value<
	GLenum,
	GL_READ_WRITE,
	mp_list<oglplus::access_specifier>
> read_write = {};
#endif

#ifdef GL_RECT_NV
static constexpr const enum_value<
	GLubyte,
	GL_RECT_NV,
	mp_list<oglplus::path_command_nv>
> rect_nv = {};
#endif

#ifdef GL_RED
static constexpr const enum_value<
	GLenum,
	GL_RED,
	mp_list<oglplus::texture_swizzle_mode,oglplus::pixel_data_format,oglplus::pixel_data_internal_format>
> red = {};
#endif

#ifdef GL_RED_INTEGER
static constexpr const enum_value<
	GLenum,
	GL_RED_INTEGER,
	mp_list<oglplus::pixel_data_format>
> red_integer = {};
#endif

#ifdef GL_REFERENCED_BY_COMPUTE_SHADER
static constexpr const enum_value<
	GLenum,
	GL_REFERENCED_BY_COMPUTE_SHADER,
	mp_list<oglplus::program_resource_property>
> referenced_by_compute_shader = {};
#endif

#ifdef GL_REFERENCED_BY_FRAGMENT_SHADER
static constexpr const enum_value<
	GLenum,
	GL_REFERENCED_BY_FRAGMENT_SHADER,
	mp_list<oglplus::program_resource_property>
> referenced_by_fragment_shader = {};
#endif

#ifdef GL_REFERENCED_BY_GEOMETRY_SHADER
static constexpr const enum_value<
	GLenum,
	GL_REFERENCED_BY_GEOMETRY_SHADER,
	mp_list<oglplus::program_resource_property>
> referenced_by_geometry_shader = {};
#endif

#ifdef GL_REFERENCED_BY_TESS_CONTROL_SHADER
static constexpr const enum_value<
	GLenum,
	GL_REFERENCED_BY_TESS_CONTROL_SHADER,
	mp_list<oglplus::program_resource_property>
> referenced_by_tess_control_shader = {};
#endif

#ifdef GL_REFERENCED_BY_TESS_EVALUATION_SHADER
static constexpr const enum_value<
	GLenum,
	GL_REFERENCED_BY_TESS_EVALUATION_SHADER,
	mp_list<oglplus::program_resource_property>
> referenced_by_tess_evaluation_shader = {};
#endif

#ifdef GL_REFERENCED_BY_VERTEX_SHADER
static constexpr const enum_value<
	GLenum,
	GL_REFERENCED_BY_VERTEX_SHADER,
	mp_list<oglplus::program_resource_property>
> referenced_by_vertex_shader = {};
#endif

#ifdef GL_RELATIVE_ARC_TO_NV
static constexpr const enum_value<
	GLubyte,
	GL_RELATIVE_ARC_TO_NV,
	mp_list<oglplus::path_command_nv>
> relative_arc_to_nv = {};
#endif

#ifdef GL_RELATIVE_CUBIC_CURVE_TO_NV
static constexpr const enum_value<
	GLubyte,
	GL_RELATIVE_CUBIC_CURVE_TO_NV,
	mp_list<oglplus::path_command_nv>
> relative_cubic_curve_to_nv = {};
#endif

#ifdef GL_RELATIVE_HORIZONTAL_LINE_TO_NV
static constexpr const enum_value<
	GLubyte,
	GL_RELATIVE_HORIZONTAL_LINE_TO_NV,
	mp_list<oglplus::path_command_nv>
> relative_horizontal_line_to_nv = {};
#endif

#ifdef GL_RELATIVE_LARGE_CCW_ARC_TO_NV
static constexpr const enum_value<
	GLubyte,
	GL_RELATIVE_LARGE_CCW_ARC_TO_NV,
	mp_list<oglplus::path_command_nv>
> relative_large_ccw_arc_to_nv = {};
#endif

#ifdef GL_RELATIVE_LARGE_CW_ARC_TO_NV
static constexpr const enum_value<
	GLubyte,
	GL_RELATIVE_LARGE_CW_ARC_TO_NV,
	mp_list<oglplus::path_command_nv>
> relative_large_cw_arc_to_nv = {};
#endif

#ifdef GL_RELATIVE_LINE_TO_NV
static constexpr const enum_value<
	GLubyte,
	GL_RELATIVE_LINE_TO_NV,
	mp_list<oglplus::path_command_nv>
> relative_line_to_nv = {};
#endif

#ifdef GL_RELATIVE_MOVE_TO_NV
static constexpr const enum_value<
	GLubyte,
	GL_RELATIVE_MOVE_TO_NV,
	mp_list<oglplus::path_command_nv>
> relative_move_to_nv = {};
#endif

#ifdef GL_RELATIVE_QUADRATIC_CURVE_TO_NV
static constexpr const enum_value<
	GLubyte,
	GL_RELATIVE_QUADRATIC_CURVE_TO_NV,
	mp_list<oglplus::path_command_nv>
> relative_quadratic_curve_to_nv = {};
#endif

#ifdef GL_RELATIVE_SMALL_CCW_ARC_TO_NV
static constexpr const enum_value<
	GLubyte,
	GL_RELATIVE_SMALL_CCW_ARC_TO_NV,
	mp_list<oglplus::path_command_nv>
> relative_small_ccw_arc_to_nv = {};
#endif

#ifdef GL_RELATIVE_SMALL_CW_ARC_TO_NV
static constexpr const enum_value<
	GLubyte,
	GL_RELATIVE_SMALL_CW_ARC_TO_NV,
	mp_list<oglplus::path_command_nv>
> relative_small_cw_arc_to_nv = {};
#endif

#ifdef GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV
static constexpr const enum_value<
	GLubyte,
	GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV,
	mp_list<oglplus::path_command_nv>
> relative_smooth_cubic_curve_to_nv = {};
#endif

#ifdef GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV
static constexpr const enum_value<
	GLubyte,
	GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV,
	mp_list<oglplus::path_command_nv>
> relative_smooth_quadratic_curve_to_nv = {};
#endif

#ifdef GL_RELATIVE_VERTICAL_LINE_TO_NV
static constexpr const enum_value<
	GLubyte,
	GL_RELATIVE_VERTICAL_LINE_TO_NV,
	mp_list<oglplus::path_command_nv>
> relative_vertical_line_to_nv = {};
#endif

#ifdef GL_RENDERBUFFER
static constexpr const enum_value<
	GLenum,
	GL_RENDERBUFFER,
	mp_list<oglplus::object_type,oglplus::renderbuffer_target>
> renderbuffer = {};
#endif

#ifdef GL_RENDERBUFFER_ALPHA_SIZE
static constexpr const enum_value<
	GLenum,
	GL_RENDERBUFFER_ALPHA_SIZE,
	mp_list<oglplus::renderbuffer_parameter>
> renderbuffer_alpha_size = {};
#endif

#ifdef GL_RENDERBUFFER_BINDING
static constexpr const enum_value<
	GLenum,
	GL_RENDERBUFFER_BINDING,
	mp_list<oglplus::binding_query>
> renderbuffer_binding = {};
#endif

#ifdef GL_RENDERBUFFER_BLUE_SIZE
static constexpr const enum_value<
	GLenum,
	GL_RENDERBUFFER_BLUE_SIZE,
	mp_list<oglplus::renderbuffer_parameter>
> renderbuffer_blue_size = {};
#endif

#ifdef GL_RENDERBUFFER_DEPTH_SIZE
static constexpr const enum_value<
	GLenum,
	GL_RENDERBUFFER_DEPTH_SIZE,
	mp_list<oglplus::renderbuffer_parameter>
> renderbuffer_depth_size = {};
#endif

#ifdef GL_RENDERBUFFER_GREEN_SIZE
static constexpr const enum_value<
	GLenum,
	GL_RENDERBUFFER_GREEN_SIZE,
	mp_list<oglplus::renderbuffer_parameter>
> renderbuffer_green_size = {};
#endif

#ifdef GL_RENDERBUFFER_HEIGHT
static constexpr const enum_value<
	GLenum,
	GL_RENDERBUFFER_HEIGHT,
	mp_list<oglplus::renderbuffer_parameter>
> renderbuffer_height = {};
#endif

#ifdef GL_RENDERBUFFER_INTERNAL_FORMAT
static constexpr const enum_value<
	GLenum,
	GL_RENDERBUFFER_INTERNAL_FORMAT,
	mp_list<oglplus::renderbuffer_parameter>
> renderbuffer_internal_format = {};
#endif

#ifdef GL_RENDERBUFFER_RED_SIZE
static constexpr const enum_value<
	GLenum,
	GL_RENDERBUFFER_RED_SIZE,
	mp_list<oglplus::renderbuffer_parameter>
> renderbuffer_red_size = {};
#endif

#ifdef GL_RENDERBUFFER_SAMPLES
static constexpr const enum_value<
	GLenum,
	GL_RENDERBUFFER_SAMPLES,
	mp_list<oglplus::renderbuffer_parameter>
> renderbuffer_samples = {};
#endif

#ifdef GL_RENDERBUFFER_STENCIL_SIZE
static constexpr const enum_value<
	GLenum,
	GL_RENDERBUFFER_STENCIL_SIZE,
	mp_list<oglplus::renderbuffer_parameter>
> renderbuffer_stencil_size = {};
#endif

#ifdef GL_RENDERBUFFER_WIDTH
static constexpr const enum_value<
	GLenum,
	GL_RENDERBUFFER_WIDTH,
	mp_list<oglplus::renderbuffer_parameter>
> renderbuffer_width = {};
#endif

#ifdef GL_RENDERER
static constexpr const enum_value<
	GLenum,
	GL_RENDERER,
	mp_list<oglplus::string_query>
> renderer = {};
#endif

#ifdef GL_REPEAT
static constexpr const enum_value<
	GLenum,
	GL_REPEAT,
	mp_list<oglplus::texture_wrap_mode>
> repeat = {};
#endif

#ifdef GL_REPLACE
static constexpr const enum_value<
	GLenum,
	GL_REPLACE,
	mp_list<oglplus::stencil_operation>
> replace = {};
#endif

#ifdef GL_RESTART_PATH_NV
static constexpr const enum_value<
	GLubyte,
	GL_RESTART_PATH_NV,
	mp_list<oglplus::path_command_nv>
> restart_path_nv = {};
#endif

#ifdef GL_RG
static constexpr const enum_value<
	GLenum,
	GL_RG,
	mp_list<oglplus::pixel_data_format,oglplus::pixel_data_internal_format>
> rg = {};
#endif

#ifdef GL_RG16
static constexpr const enum_value<
	GLenum,
	GL_RG16,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> rg16 = {};
#endif

#ifdef GL_RG16_SNORM
static constexpr const enum_value<
	GLenum,
	GL_RG16_SNORM,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> rg16_snorm = {};
#endif

#ifdef GL_RG16F
static constexpr const enum_value<
	GLenum,
	GL_RG16F,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> rg16f = {};
#endif

#ifdef GL_RG16I
static constexpr const enum_value<
	GLenum,
	GL_RG16I,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> rg16i = {};
#endif

#ifdef GL_RG16UI
static constexpr const enum_value<
	GLenum,
	GL_RG16UI,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> rg16ui = {};
#endif

#ifdef GL_RG32F
static constexpr const enum_value<
	GLenum,
	GL_RG32F,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> rg32f = {};
#endif

#ifdef GL_RG32I
static constexpr const enum_value<
	GLenum,
	GL_RG32I,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> rg32i = {};
#endif

#ifdef GL_RG32UI
static constexpr const enum_value<
	GLenum,
	GL_RG32UI,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> rg32ui = {};
#endif

#ifdef GL_RG8
static constexpr const enum_value<
	GLenum,
	GL_RG8,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> rg8 = {};
#endif

#ifdef GL_RG8_SNORM
static constexpr const enum_value<
	GLenum,
	GL_RG8_SNORM,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> rg8_snorm = {};
#endif

#ifdef GL_RG8I
static constexpr const enum_value<
	GLenum,
	GL_RG8I,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> rg8i = {};
#endif

#ifdef GL_RG8UI
static constexpr const enum_value<
	GLenum,
	GL_RG8UI,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> rg8ui = {};
#endif

#ifdef GL_RG_INTEGER
static constexpr const enum_value<
	GLenum,
	GL_RG_INTEGER,
	mp_list<oglplus::pixel_data_format>
> rg_integer = {};
#endif

#ifdef GL_RGB
static constexpr const enum_value<
	GLenum,
	GL_RGB,
	mp_list<oglplus::path_color_format_nv,oglplus::pixel_data_format,oglplus::pixel_data_internal_format>
> rgb = {};
#endif

#ifdef GL_RGB10
static constexpr const enum_value<
	GLenum,
	GL_RGB10,
	mp_list<oglplus::pixel_data_internal_format>
> rgb10 = {};
#endif

#ifdef GL_RGB10_A2
static constexpr const enum_value<
	GLenum,
	GL_RGB10_A2,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> rgb10_a2 = {};
#endif

#ifdef GL_RGB10_A2UI
static constexpr const enum_value<
	GLenum,
	GL_RGB10_A2UI,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> rgb10_a2ui = {};
#endif

#ifdef GL_RGB12
static constexpr const enum_value<
	GLenum,
	GL_RGB12,
	mp_list<oglplus::pixel_data_internal_format>
> rgb12 = {};
#endif

#ifdef GL_RGB16
static constexpr const enum_value<
	GLenum,
	GL_RGB16,
	mp_list<oglplus::pixel_data_internal_format>
> rgb16 = {};
#endif

#ifdef GL_RGB16_SNORM
static constexpr const enum_value<
	GLenum,
	GL_RGB16_SNORM,
	mp_list<oglplus::pixel_data_internal_format>
> rgb16_snorm = {};
#endif

#ifdef GL_RGB16F
static constexpr const enum_value<
	GLenum,
	GL_RGB16F,
	mp_list<oglplus::pixel_data_internal_format>
> rgb16f = {};
#endif

#ifdef GL_RGB16I
static constexpr const enum_value<
	GLenum,
	GL_RGB16I,
	mp_list<oglplus::pixel_data_internal_format>
> rgb16i = {};
#endif

#ifdef GL_RGB16UI
static constexpr const enum_value<
	GLenum,
	GL_RGB16UI,
	mp_list<oglplus::pixel_data_internal_format>
> rgb16ui = {};
#endif

#ifdef GL_RGB32F
static constexpr const enum_value<
	GLenum,
	GL_RGB32F,
	mp_list<oglplus::pixel_data_internal_format>
> rgb32f = {};
#endif

#ifdef GL_RGB32I
static constexpr const enum_value<
	GLenum,
	GL_RGB32I,
	mp_list<oglplus::pixel_data_internal_format>
> rgb32i = {};
#endif

#ifdef GL_RGB32UI
static constexpr const enum_value<
	GLenum,
	GL_RGB32UI,
	mp_list<oglplus::pixel_data_internal_format>
> rgb32ui = {};
#endif

#ifdef GL_RGB4
static constexpr const enum_value<
	GLenum,
	GL_RGB4,
	mp_list<oglplus::pixel_data_internal_format>
> rgb4 = {};
#endif

#ifdef GL_RGB5
static constexpr const enum_value<
	GLenum,
	GL_RGB5,
	mp_list<oglplus::pixel_data_internal_format>
> rgb5 = {};
#endif

#ifdef GL_RGB5_A1
static constexpr const enum_value<
	GLenum,
	GL_RGB5_A1,
	mp_list<oglplus::pixel_data_internal_format>
> rgb5_a1 = {};
#endif

#ifdef GL_RGB8
static constexpr const enum_value<
	GLenum,
	GL_RGB8,
	mp_list<oglplus::pixel_data_internal_format>
> rgb8 = {};
#endif

#ifdef GL_RGB8_SNORM
static constexpr const enum_value<
	GLenum,
	GL_RGB8_SNORM,
	mp_list<oglplus::pixel_data_internal_format>
> rgb8_snorm = {};
#endif

#ifdef GL_RGB8I
static constexpr const enum_value<
	GLenum,
	GL_RGB8I,
	mp_list<oglplus::pixel_data_internal_format>
> rgb8i = {};
#endif

#ifdef GL_RGB8UI
static constexpr const enum_value<
	GLenum,
	GL_RGB8UI,
	mp_list<oglplus::pixel_data_internal_format>
> rgb8ui = {};
#endif

#ifdef GL_RGB9_E5
static constexpr const enum_value<
	GLenum,
	GL_RGB9_E5,
	mp_list<oglplus::pixel_data_internal_format>
> rgb9_e5 = {};
#endif

#ifdef GL_RGB_INTEGER
static constexpr const enum_value<
	GLenum,
	GL_RGB_INTEGER,
	mp_list<oglplus::pixel_data_format>
> rgb_integer = {};
#endif

#ifdef GL_RGBA
static constexpr const enum_value<
	GLenum,
	GL_RGBA,
	mp_list<oglplus::path_color_format_nv,oglplus::pixel_data_format,oglplus::pixel_data_internal_format>
> rgba = {};
#endif

#ifdef GL_RGBA12
static constexpr const enum_value<
	GLenum,
	GL_RGBA12,
	mp_list<oglplus::pixel_data_internal_format>
> rgba12 = {};
#endif

#ifdef GL_RGBA16
static constexpr const enum_value<
	GLenum,
	GL_RGBA16,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> rgba16 = {};
#endif

#ifdef GL_RGBA16_SNORM
static constexpr const enum_value<
	GLenum,
	GL_RGBA16_SNORM,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> rgba16_snorm = {};
#endif

#ifdef GL_RGBA16F
static constexpr const enum_value<
	GLenum,
	GL_RGBA16F,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> rgba16f = {};
#endif

#ifdef GL_RGBA16I
static constexpr const enum_value<
	GLenum,
	GL_RGBA16I,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> rgba16i = {};
#endif

#ifdef GL_RGBA16UI
static constexpr const enum_value<
	GLenum,
	GL_RGBA16UI,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> rgba16ui = {};
#endif

#ifdef GL_RGBA2
static constexpr const enum_value<
	GLenum,
	GL_RGBA2,
	mp_list<oglplus::pixel_data_internal_format>
> rgba2 = {};
#endif

#ifdef GL_RGBA32F
static constexpr const enum_value<
	GLenum,
	GL_RGBA32F,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> rgba32f = {};
#endif

#ifdef GL_RGBA32I
static constexpr const enum_value<
	GLenum,
	GL_RGBA32I,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> rgba32i = {};
#endif

#ifdef GL_RGBA32UI
static constexpr const enum_value<
	GLenum,
	GL_RGBA32UI,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> rgba32ui = {};
#endif

#ifdef GL_RGBA4
static constexpr const enum_value<
	GLenum,
	GL_RGBA4,
	mp_list<oglplus::pixel_data_internal_format>
> rgba4 = {};
#endif

#ifdef GL_RGBA8
static constexpr const enum_value<
	GLenum,
	GL_RGBA8,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> rgba8 = {};
#endif

#ifdef GL_RGBA8_SNORM
static constexpr const enum_value<
	GLenum,
	GL_RGBA8_SNORM,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> rgba8_snorm = {};
#endif

#ifdef GL_RGBA8I
static constexpr const enum_value<
	GLenum,
	GL_RGBA8I,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> rgba8i = {};
#endif

#ifdef GL_RGBA8UI
static constexpr const enum_value<
	GLenum,
	GL_RGBA8UI,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> rgba8ui = {};
#endif

#ifdef GL_RGBA_INTEGER
static constexpr const enum_value<
	GLenum,
	GL_RGBA_INTEGER,
	mp_list<oglplus::pixel_data_format>
> rgba_integer = {};
#endif

#ifdef GL_RIGHT
static constexpr const enum_value<
	GLenum,
	GL_RIGHT,
	mp_list<oglplus::color_buffer>
> right = {};
#endif

#ifdef GL_ROUND_NV
static constexpr const enum_value<
	GLenum,
	GL_ROUND_NV,
	mp_list<oglplus::path_cap_style_nv,oglplus::path_join_style_nv>
> round_nv = {};
#endif

#ifdef GL_SAMPLE_ALPHA_TO_COVERAGE
static constexpr const enum_value<
	GLenum,
	GL_SAMPLE_ALPHA_TO_COVERAGE,
	mp_list<oglplus::capability>
> sample_alpha_to_coverage = {};
#endif

#ifdef GL_SAMPLE_ALPHA_TO_ONE
static constexpr const enum_value<
	GLenum,
	GL_SAMPLE_ALPHA_TO_ONE,
	mp_list<oglplus::capability>
> sample_alpha_to_one = {};
#endif

#ifdef GL_SAMPLE_BUFFERS
static constexpr const enum_value<
	GLenum,
	GL_SAMPLE_BUFFERS,
	mp_list<oglplus::numeric_query>
> sample_buffers = {};
#endif

#ifdef GL_SAMPLE_COVERAGE
static constexpr const enum_value<
	GLenum,
	GL_SAMPLE_COVERAGE,
	mp_list<oglplus::capability>
> sample_coverage = {};
#endif

#ifdef GL_SAMPLE_COVERAGE_INVERT
static constexpr const enum_value<
	GLenum,
	GL_SAMPLE_COVERAGE_INVERT,
	mp_list<oglplus::numeric_query>
> sample_coverage_invert = {};
#endif

#ifdef GL_SAMPLE_COVERAGE_VALUE
static constexpr const enum_value<
	GLenum,
	GL_SAMPLE_COVERAGE_VALUE,
	mp_list<oglplus::numeric_query>
> sample_coverage_value = {};
#endif

#ifdef GL_SAMPLE_MASK
static constexpr const enum_value<
	GLenum,
	GL_SAMPLE_MASK,
	mp_list<oglplus::capability>
> sample_mask = {};
#endif

#ifdef GL_SAMPLE_SHADING
static constexpr const enum_value<
	GLenum,
	GL_SAMPLE_SHADING,
	mp_list<oglplus::capability>
> sample_shading = {};
#endif

#ifdef GL_SAMPLER
static constexpr const enum_value<
	GLenum,
	GL_SAMPLER,
	mp_list<oglplus::object_type>
> sampler = {};
#endif

#ifdef GL_SAMPLER_1D
static constexpr const enum_value<
	GLenum,
	GL_SAMPLER_1D,
	mp_list<oglplus::sl_data_type>
> sampler_1d = {};
#endif

#ifdef GL_SAMPLER_1D_ARRAY
static constexpr const enum_value<
	GLenum,
	GL_SAMPLER_1D_ARRAY,
	mp_list<oglplus::sl_data_type>
> sampler_1d_array = {};
#endif

#ifdef GL_SAMPLER_1D_ARRAY_SHADOW
static constexpr const enum_value<
	GLenum,
	GL_SAMPLER_1D_ARRAY_SHADOW,
	mp_list<oglplus::sl_data_type>
> sampler_1d_array_shadow = {};
#endif

#ifdef GL_SAMPLER_1D_SHADOW
static constexpr const enum_value<
	GLenum,
	GL_SAMPLER_1D_SHADOW,
	mp_list<oglplus::sl_data_type>
> sampler_1d_shadow = {};
#endif

#ifdef GL_SAMPLER_2D
static constexpr const enum_value<
	GLenum,
	GL_SAMPLER_2D,
	mp_list<oglplus::sl_data_type>
> sampler_2d = {};
#endif

#ifdef GL_SAMPLER_2D_ARRAY
static constexpr const enum_value<
	GLenum,
	GL_SAMPLER_2D_ARRAY,
	mp_list<oglplus::sl_data_type>
> sampler_2d_array = {};
#endif

#ifdef GL_SAMPLER_2D_ARRAY_SHADOW
static constexpr const enum_value<
	GLenum,
	GL_SAMPLER_2D_ARRAY_SHADOW,
	mp_list<oglplus::sl_data_type>
> sampler_2d_array_shadow = {};
#endif

#ifdef GL_SAMPLER_2D_MULTISAMPLE
static constexpr const enum_value<
	GLenum,
	GL_SAMPLER_2D_MULTISAMPLE,
	mp_list<oglplus::sl_data_type>
> sampler_2d_multisample = {};
#endif

#ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
static constexpr const enum_value<
	GLenum,
	GL_SAMPLER_2D_MULTISAMPLE_ARRAY,
	mp_list<oglplus::sl_data_type>
> sampler_2d_multisample_array = {};
#endif

#ifdef GL_SAMPLER_2D_RECT
static constexpr const enum_value<
	GLenum,
	GL_SAMPLER_2D_RECT,
	mp_list<oglplus::sl_data_type>
> sampler_2d_rect = {};
#endif

#ifdef GL_SAMPLER_2D_RECT_SHADOW
static constexpr const enum_value<
	GLenum,
	GL_SAMPLER_2D_RECT_SHADOW,
	mp_list<oglplus::sl_data_type>
> sampler_2d_rect_shadow = {};
#endif

#ifdef GL_SAMPLER_2D_SHADOW
static constexpr const enum_value<
	GLenum,
	GL_SAMPLER_2D_SHADOW,
	mp_list<oglplus::sl_data_type>
> sampler_2d_shadow = {};
#endif

#ifdef GL_SAMPLER_3D
static constexpr const enum_value<
	GLenum,
	GL_SAMPLER_3D,
	mp_list<oglplus::sl_data_type>
> sampler_3d = {};
#endif

#ifdef GL_SAMPLER_BINDING
static constexpr const enum_value<
	GLenum,
	GL_SAMPLER_BINDING,
	mp_list<oglplus::binding_query>
> sampler_binding = {};
#endif

#ifdef GL_SAMPLER_BUFFER
static constexpr const enum_value<
	GLenum,
	GL_SAMPLER_BUFFER,
	mp_list<oglplus::sl_data_type>
> sampler_buffer = {};
#endif

#ifdef GL_SAMPLER_CUBE
static constexpr const enum_value<
	GLenum,
	GL_SAMPLER_CUBE,
	mp_list<oglplus::sl_data_type>
> sampler_cube = {};
#endif

#ifdef GL_SAMPLER_CUBE_MAP_ARRAY
static constexpr const enum_value<
	GLenum,
	GL_SAMPLER_CUBE_MAP_ARRAY,
	mp_list<oglplus::sl_data_type>
> sampler_cube_map_array = {};
#endif

#ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
static constexpr const enum_value<
	GLenum,
	GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW,
	mp_list<oglplus::sl_data_type>
> sampler_cube_map_array_shadow = {};
#endif

#ifdef GL_SAMPLER_CUBE_SHADOW
static constexpr const enum_value<
	GLenum,
	GL_SAMPLER_CUBE_SHADOW,
	mp_list<oglplus::sl_data_type>
> sampler_cube_shadow = {};
#endif

#ifdef GL_SAMPLES
static constexpr const enum_value<
	GLenum,
	GL_SAMPLES,
	mp_list<oglplus::numeric_query>
> samples = {};
#endif

#ifdef GL_SAMPLES_PASSED
static constexpr const enum_value<
	GLenum,
	GL_SAMPLES_PASSED,
	mp_list<oglplus::query_target>
> samples_passed = {};
#endif

#ifdef GL_SCISSOR_BOX
static constexpr const enum_value<
	GLenum,
	GL_SCISSOR_BOX,
	mp_list<oglplus::numeric_query>
> scissor_box = {};
#endif

#ifdef GL_SCISSOR_TEST
static constexpr const enum_value<
	GLenum,
	GL_SCISSOR_TEST,
	mp_list<oglplus::capability>
> scissor_test = {};
#endif

#ifdef GL_SCREEN_KHR
static constexpr const enum_value<
	GLenum,
	GL_SCREEN_KHR,
	mp_list<oglplus::blend_equation_advanced>
> screen_khr = {};
#endif

#ifdef GL_SECONDARY_COLOR_NV
static constexpr const enum_value<
	GLenum,
	GL_SECONDARY_COLOR_NV,
	mp_list<oglplus::path_color_nv>
> secondary_color_nv = {};
#endif

#ifdef GL_SEPARATE_ATTRIBS
static constexpr const enum_value<
	GLenum,
	GL_SEPARATE_ATTRIBS,
	mp_list<oglplus::transform_feedback_mode>
> separate_attribs = {};
#endif

#ifdef GL_SET
static constexpr const enum_value<
	GLenum,
	GL_SET,
	mp_list<oglplus::color_logic_operation>
> set = {};
#endif

#ifdef GL_SHADER
static constexpr const enum_value<
	GLenum,
	GL_SHADER,
	mp_list<oglplus::object_type>
> shader = {};
#endif

#ifdef GL_SHADER_COMPILER
static constexpr const enum_value<
	GLenum,
	GL_SHADER_COMPILER,
	mp_list<oglplus::numeric_query>
> shader_compiler = {};
#endif

#ifdef GL_SHADER_IMAGE_ACCESS_BARRIER_BIT
static constexpr const enum_value<
	GLbitfield,
	GL_SHADER_IMAGE_ACCESS_BARRIER_BIT,
	mp_list<oglplus::memory_barrier_bits>
> shader_image_access_barrier_bit = {};
#endif

#ifdef GL_SHADER_INCLUDE_ARB
static constexpr const enum_value<
	GLenum,
	GL_SHADER_INCLUDE_ARB,
	mp_list<oglplus::named_string_type>
> shader_include = {};
#endif

#ifdef GL_SHADER_SOURCE_LENGTH
static constexpr const enum_value<
	GLenum,
	GL_SHADER_SOURCE_LENGTH,
	mp_list<oglplus::shader_parameter>
> shader_source_length = {};
#endif

#ifdef GL_SHADER_STORAGE_BARRIER_BIT
static constexpr const enum_value<
	GLbitfield,
	GL_SHADER_STORAGE_BARRIER_BIT,
	mp_list<oglplus::memory_barrier_bits>
> shader_storage_barrier_bit = {};
#endif

#ifdef GL_SHADER_STORAGE_BLOCK
static constexpr const enum_value<
	GLenum,
	GL_SHADER_STORAGE_BLOCK,
	mp_list<oglplus::program_interface>
> shader_storage_block = {};
#endif

#ifdef GL_SHADER_STORAGE_BUFFER
static constexpr const enum_value<
	GLenum,
	GL_SHADER_STORAGE_BUFFER,
	mp_list<oglplus::buffer_indexed_target,oglplus::buffer_target>
> shader_storage_buffer = {};
#endif

#ifdef GL_SHADER_STORAGE_BUFFER_BINDING
static constexpr const enum_value<
	GLenum,
	GL_SHADER_STORAGE_BUFFER_BINDING,
	mp_list<oglplus::binding_query>
> shader_storage_buffer_binding = {};
#endif

#ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
static constexpr const enum_value<
	GLenum,
	GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT,
	mp_list<oglplus::numeric_query>
> shader_storage_buffer_offset_alignment = {};
#endif

#ifdef GL_SHADER_STORAGE_BUFFER_SIZE
static constexpr const enum_value<
	GLenum,
	GL_SHADER_STORAGE_BUFFER_SIZE,
	mp_list<oglplus::numeric_query>
> shader_storage_buffer_size = {};
#endif

#ifdef GL_SHADER_STORAGE_BUFFER_START
static constexpr const enum_value<
	GLenum,
	GL_SHADER_STORAGE_BUFFER_START,
	mp_list<oglplus::numeric_query>
> shader_storage_buffer_start = {};
#endif

#ifdef GL_SHADER_TYPE
static constexpr const enum_value<
	GLenum,
	GL_SHADER_TYPE,
	mp_list<oglplus::shader_parameter>
> shader_type = {};
#endif

#ifdef GL_SHADING_LANGUAGE_VERSION
static constexpr const enum_value<
	GLenum,
	GL_SHADING_LANGUAGE_VERSION,
	mp_list<oglplus::string_query>
> shading_language_version = {};
#endif

#ifdef GL_SHORT
static constexpr const enum_value<
	GLenum,
	GL_SHORT,
	mp_list<oglplus::pixel_data_type,oglplus::data_type>
> short_ = {};
#endif

#ifdef GL_SIGNALED
static constexpr const enum_value<
	GLenum,
	GL_SIGNALED,
	mp_list<oglplus::sync_status>
> signaled = {};
#endif

#ifdef GL_SKIP_MISSING_GLYPH_NV
static constexpr const enum_value<
	GLenum,
	GL_SKIP_MISSING_GLYPH_NV,
	mp_list<oglplus::path_missing_glyph_nv>
> skip_missing_glyph_nv = {};
#endif

#ifdef GL_SMALL_CCW_ARC_TO_NV
static constexpr const enum_value<
	GLubyte,
	GL_SMALL_CCW_ARC_TO_NV,
	mp_list<oglplus::path_command_nv>
> small_ccw_arc_to_nv = {};
#endif

#ifdef GL_SMALL_CW_ARC_TO_NV
static constexpr const enum_value<
	GLubyte,
	GL_SMALL_CW_ARC_TO_NV,
	mp_list<oglplus::path_command_nv>
> small_cw_arc_to_nv = {};
#endif

#ifdef GL_SMOOTH_CUBIC_CURVE_TO_NV
static constexpr const enum_value<
	GLubyte,
	GL_SMOOTH_CUBIC_CURVE_TO_NV,
	mp_list<oglplus::path_command_nv>
> smooth_cubic_curve_to_nv = {};
#endif

#ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
static constexpr const enum_value<
	GLenum,
	GL_SMOOTH_LINE_WIDTH_GRANULARITY,
	mp_list<oglplus::numeric_query>
> smooth_line_width_granularity = {};
#endif

#ifdef GL_SMOOTH_LINE_WIDTH_RANGE
static constexpr const enum_value<
	GLenum,
	GL_SMOOTH_LINE_WIDTH_RANGE,
	mp_list<oglplus::numeric_query>
> smooth_line_width_range = {};
#endif

#ifdef GL_SMOOTH_QUADRATIC_CURVE_TO_NV
static constexpr const enum_value<
	GLubyte,
	GL_SMOOTH_QUADRATIC_CURVE_TO_NV,
	mp_list<oglplus::path_command_nv>
> smooth_quadratic_curve_to_nv = {};
#endif

#ifdef GL_SOFTLIGHT_KHR
static constexpr const enum_value<
	GLenum,
	GL_SOFTLIGHT_KHR,
	mp_list<oglplus::blend_equation_advanced>
> softlight_khr = {};
#endif

#ifdef GL_SPARSE_STORAGE_BIT_ARB
static constexpr const enum_value<
	GLbitfield,
	GL_SPARSE_STORAGE_BIT_ARB,
	mp_list<oglplus::buffer_storage_bits>
> sparse_storage_bit = {};
#endif

#ifdef GL_SQUARE_NV
static constexpr const enum_value<
	GLenum,
	GL_SQUARE_NV,
	mp_list<oglplus::path_cap_style_nv>
> square_nv = {};
#endif

#ifdef GL_SRC1_ALPHA
static constexpr const enum_value<
	GLenum,
	GL_SRC1_ALPHA,
	mp_list<oglplus::blend_function>
> src1_alpha = {};
#endif

#ifdef GL_SRC1_COLOR
static constexpr const enum_value<
	GLenum,
	GL_SRC1_COLOR,
	mp_list<oglplus::blend_function>
> src1_color = {};
#endif

#ifdef GL_SRC_ALPHA
static constexpr const enum_value<
	GLenum,
	GL_SRC_ALPHA,
	mp_list<oglplus::blend_function>
> src_alpha = {};
#endif

#ifdef GL_SRC_ALPHA_SATURATE
static constexpr const enum_value<
	GLenum,
	GL_SRC_ALPHA_SATURATE,
	mp_list<oglplus::blend_function>
> src_alpha_saturate = {};
#endif

#ifdef GL_SRC_COLOR
static constexpr const enum_value<
	GLenum,
	GL_SRC_COLOR,
	mp_list<oglplus::blend_function>
> src_color = {};
#endif

#ifdef GL_SRGB8
static constexpr const enum_value<
	GLenum,
	GL_SRGB8,
	mp_list<oglplus::pixel_data_internal_format>
> srgb8 = {};
#endif

#ifdef GL_SRGB8_ALPHA8
static constexpr const enum_value<
	GLenum,
	GL_SRGB8_ALPHA8,
	mp_list<oglplus::pixel_data_internal_format>
> srgb8_alpha8 = {};
#endif

#ifdef GL_STACK_OVERFLOW
static constexpr const enum_value<
	GLenum,
	GL_STACK_OVERFLOW,
	mp_list<oglplus::error_code>
> stack_overflow = {};
#endif

#ifdef GL_STACK_UNDERFLOW
static constexpr const enum_value<
	GLenum,
	GL_STACK_UNDERFLOW,
	mp_list<oglplus::error_code>
> stack_underflow = {};
#endif

#ifdef GL_STANDARD_FONT_NAME_NV
static constexpr const enum_value<
	GLenum,
	GL_STANDARD_FONT_NAME_NV,
	mp_list<oglplus::path_font_target_nv>
> standard_font_name_nv = {};
#endif

#ifdef GL_STATIC_COPY
static constexpr const enum_value<
	GLenum,
	GL_STATIC_COPY,
	mp_list<oglplus::buffer_usage>
> static_copy = {};
#endif

#ifdef GL_STATIC_DRAW
static constexpr const enum_value<
	GLenum,
	GL_STATIC_DRAW,
	mp_list<oglplus::buffer_usage>
> static_draw = {};
#endif

#ifdef GL_STATIC_READ
static constexpr const enum_value<
	GLenum,
	GL_STATIC_READ,
	mp_list<oglplus::buffer_usage>
> static_read = {};
#endif

#ifdef GL_STENCIL
static constexpr const enum_value<
	GLenum,
	GL_STENCIL,
	mp_list<oglplus::framebuffer_buffer>
> stencil = {};
#endif

#ifdef GL_STENCIL_ATTACHMENT
static constexpr const enum_value<
	GLenum,
	GL_STENCIL_ATTACHMENT,
	mp_list<oglplus::framebuffer_other_attachment>
> stencil_attachment = {};
#endif

#ifdef GL_STENCIL_BACK_FAIL
static constexpr const enum_value<
	GLenum,
	GL_STENCIL_BACK_FAIL,
	mp_list<oglplus::numeric_query>
> stencil_back_fail = {};
#endif

#ifdef GL_STENCIL_BACK_FUNC
static constexpr const enum_value<
	GLenum,
	GL_STENCIL_BACK_FUNC,
	mp_list<oglplus::numeric_query>
> stencil_back_func = {};
#endif

#ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
static constexpr const enum_value<
	GLenum,
	GL_STENCIL_BACK_PASS_DEPTH_FAIL,
	mp_list<oglplus::numeric_query>
> stencil_back_pass_depth_fail = {};
#endif

#ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
static constexpr const enum_value<
	GLenum,
	GL_STENCIL_BACK_PASS_DEPTH_PASS,
	mp_list<oglplus::numeric_query>
> stencil_back_pass_depth_pass = {};
#endif

#ifdef GL_STENCIL_BACK_REF
static constexpr const enum_value<
	GLenum,
	GL_STENCIL_BACK_REF,
	mp_list<oglplus::numeric_query>
> stencil_back_ref = {};
#endif

#ifdef GL_STENCIL_BACK_VALUE_MASK
static constexpr const enum_value<
	GLenum,
	GL_STENCIL_BACK_VALUE_MASK,
	mp_list<oglplus::numeric_query>
> stencil_back_value_mask = {};
#endif

#ifdef GL_STENCIL_BACK_WRITEMASK
static constexpr const enum_value<
	GLenum,
	GL_STENCIL_BACK_WRITEMASK,
	mp_list<oglplus::numeric_query>
> stencil_back_writemask = {};
#endif

#ifdef GL_STENCIL_BUFFER_BIT
static constexpr const enum_value<
	GLbitfield,
	GL_STENCIL_BUFFER_BIT,
	mp_list<oglplus::buffer_select_bits>
> stencil_buffer_bit = {};
#endif

#ifdef GL_STENCIL_CLEAR_VALUE
static constexpr const enum_value<
	GLenum,
	GL_STENCIL_CLEAR_VALUE,
	mp_list<oglplus::numeric_query>
> stencil_clear_value = {};
#endif

#ifdef GL_STENCIL_FAIL
static constexpr const enum_value<
	GLenum,
	GL_STENCIL_FAIL,
	mp_list<oglplus::numeric_query>
> stencil_fail = {};
#endif

#ifdef GL_STENCIL_FUNC
static constexpr const enum_value<
	GLenum,
	GL_STENCIL_FUNC,
	mp_list<oglplus::numeric_query>
> stencil_func = {};
#endif

#ifdef GL_STENCIL_INDEX
static constexpr const enum_value<
	GLenum,
	GL_STENCIL_INDEX,
	mp_list<oglplus::pixel_data_format>
> stencil_index = {};
#endif

#ifdef GL_STENCIL_INDEX8
static constexpr const enum_value<
	GLenum,
	GL_STENCIL_INDEX8,
	mp_list<oglplus::pixel_data_internal_format>
> stencil_index8 = {};
#endif

#ifdef GL_STENCIL_PASS_DEPTH_FAIL
static constexpr const enum_value<
	GLenum,
	GL_STENCIL_PASS_DEPTH_FAIL,
	mp_list<oglplus::numeric_query>
> stencil_pass_depth_fail = {};
#endif

#ifdef GL_STENCIL_PASS_DEPTH_PASS
static constexpr const enum_value<
	GLenum,
	GL_STENCIL_PASS_DEPTH_PASS,
	mp_list<oglplus::numeric_query>
> stencil_pass_depth_pass = {};
#endif

#ifdef GL_STENCIL_REF
static constexpr const enum_value<
	GLenum,
	GL_STENCIL_REF,
	mp_list<oglplus::numeric_query>
> stencil_ref = {};
#endif

#ifdef GL_STENCIL_TEST
static constexpr const enum_value<
	GLenum,
	GL_STENCIL_TEST,
	mp_list<oglplus::capability>
> stencil_test = {};
#endif

#ifdef GL_STENCIL_VALUE_MASK
static constexpr const enum_value<
	GLenum,
	GL_STENCIL_VALUE_MASK,
	mp_list<oglplus::numeric_query>
> stencil_value_mask = {};
#endif

#ifdef GL_STENCIL_WRITEMASK
static constexpr const enum_value<
	GLenum,
	GL_STENCIL_WRITEMASK,
	mp_list<oglplus::numeric_query>
> stencil_writemask = {};
#endif

#ifdef GL_STEREO
static constexpr const enum_value<
	GLenum,
	GL_STEREO,
	mp_list<oglplus::numeric_query>
> stereo = {};
#endif

#ifdef GL_STREAM_COPY
static constexpr const enum_value<
	GLenum,
	GL_STREAM_COPY,
	mp_list<oglplus::buffer_usage>
> stream_copy = {};
#endif

#ifdef GL_STREAM_DRAW
static constexpr const enum_value<
	GLenum,
	GL_STREAM_DRAW,
	mp_list<oglplus::buffer_usage>
> stream_draw = {};
#endif

#ifdef GL_STREAM_RASTERIZATION_AMD
static constexpr const enum_value<
	GLenum,
	GL_STREAM_RASTERIZATION_AMD,
	mp_list<oglplus::capability>
> stream_rasterization = {};
#endif

#ifdef GL_STREAM_READ
static constexpr const enum_value<
	GLenum,
	GL_STREAM_READ,
	mp_list<oglplus::buffer_usage>
> stream_read = {};
#endif

#ifdef GL_SUBPIXEL_BITS
static constexpr const enum_value<
	GLenum,
	GL_SUBPIXEL_BITS,
	mp_list<oglplus::numeric_query>
> subpixel_bits = {};
#endif

#ifdef GL_SYNC_FENCE
static constexpr const enum_value<
	GLenum,
	GL_SYNC_FENCE,
	mp_list<oglplus::sync_type>
> sync_fence = {};
#endif

#ifdef GL_SYNC_GPU_COMMANDS_COMPLETE
static constexpr const enum_value<
	GLenum,
	GL_SYNC_GPU_COMMANDS_COMPLETE,
	mp_list<oglplus::sync_condition>
> sync_gpu_commands_complete = {};
#endif

#ifdef GL_SYSTEM_FONT_NAME_NV
static constexpr const enum_value<
	GLenum,
	GL_SYSTEM_FONT_NAME_NV,
	mp_list<oglplus::path_font_target_nv>
> system_font_name_nv = {};
#endif

#ifdef GL_TABLE_TOO_LARGE
static constexpr const enum_value<
	GLenum,
	GL_TABLE_TOO_LARGE,
	mp_list<oglplus::error_code>
> table_too_large = {};
#endif

#ifdef GL_TESS_CONTROL_SHADER
static constexpr const enum_value<
	GLenum,
	GL_TESS_CONTROL_SHADER,
	mp_list<oglplus::shader_type,oglplus::program_pipeline_parameter>
> tess_control_shader = {};
#endif

#ifdef GL_TESS_CONTROL_SHADER_BIT
static constexpr const enum_value<
	GLbitfield,
	GL_TESS_CONTROL_SHADER_BIT,
	mp_list<oglplus::program_pipeline_stage>
> tess_control_shader_bit = {};
#endif

#ifdef GL_TESS_CONTROL_SHADER_PATCHES_ARB
static constexpr const enum_value<
	GLenum,
	GL_TESS_CONTROL_SHADER_PATCHES_ARB,
	mp_list<oglplus::query_target>
> tess_control_shader_patches = {};
#endif

#ifdef GL_TESS_CONTROL_SUBROUTINE
static constexpr const enum_value<
	GLenum,
	GL_TESS_CONTROL_SUBROUTINE,
	mp_list<oglplus::program_interface>
> tess_control_subroutine = {};
#endif

#ifdef GL_TESS_CONTROL_SUBROUTINE_UNIFORM
static constexpr const enum_value<
	GLenum,
	GL_TESS_CONTROL_SUBROUTINE_UNIFORM,
	mp_list<oglplus::program_interface>
> tess_control_subroutine_uniform = {};
#endif

#ifdef GL_TESS_EVALUATION_SHADER
static constexpr const enum_value<
	GLenum,
	GL_TESS_EVALUATION_SHADER,
	mp_list<oglplus::shader_type,oglplus::program_pipeline_parameter>
> tess_evaluation_shader = {};
#endif

#ifdef GL_TESS_EVALUATION_SHADER_BIT
static constexpr const enum_value<
	GLbitfield,
	GL_TESS_EVALUATION_SHADER_BIT,
	mp_list<oglplus::program_pipeline_stage>
> tess_evaluation_shader_bit = {};
#endif

#ifdef GL_TESS_EVALUATION_SHADER_INVOCATIONS_ARB
static constexpr const enum_value<
	GLenum,
	GL_TESS_EVALUATION_SHADER_INVOCATIONS_ARB,
	mp_list<oglplus::query_target>
> tess_evaluation_shader_invocations = {};
#endif

#ifdef GL_TESS_EVALUATION_SUBROUTINE
static constexpr const enum_value<
	GLenum,
	GL_TESS_EVALUATION_SUBROUTINE,
	mp_list<oglplus::program_interface>
> tess_evaluation_subroutine = {};
#endif

#ifdef GL_TESS_EVALUATION_SUBROUTINE_UNIFORM
static constexpr const enum_value<
	GLenum,
	GL_TESS_EVALUATION_SUBROUTINE_UNIFORM,
	mp_list<oglplus::program_interface>
> tess_evaluation_subroutine_uniform = {};
#endif

#ifdef GL_TEXTURE
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE,
	mp_list<oglplus::old_matrix_mode,oglplus::object_type>
> texture = {};
#endif

#ifdef GL_TEXTURE0
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE0,
	mp_list<oglplus::indexed_value_base>
> texture0 = {};
#endif

#ifdef GL_TEXTURE_1D
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_1D,
	mp_list<oglplus::texture_target>
> texture_1d = {};
#endif

#ifdef GL_TEXTURE_1D_ARRAY
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_1D_ARRAY,
	mp_list<oglplus::texture_target>
> texture_1d_array = {};
#endif

#ifdef GL_TEXTURE_2D
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_2D,
	mp_list<oglplus::texture_target>
> texture_2d = {};
#endif

#ifdef GL_TEXTURE_2D_ARRAY
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_2D_ARRAY,
	mp_list<oglplus::texture_target>
> texture_2d_array = {};
#endif

#ifdef GL_TEXTURE_2D_MULTISAMPLE
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_2D_MULTISAMPLE,
	mp_list<oglplus::texture_target>
> texture_2d_multisample = {};
#endif

#ifdef GL_TEXTURE_2D_MULTISAMPLE_ARRAY
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_2D_MULTISAMPLE_ARRAY,
	mp_list<oglplus::texture_target>
> texture_2d_multisample_array = {};
#endif

#ifdef GL_TEXTURE_3D
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_3D,
	mp_list<oglplus::texture_target>
> texture_3d = {};
#endif

#ifdef GL_TEXTURE_BASE_LEVEL
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_BASE_LEVEL,
	mp_list<oglplus::texture_parameter>
> texture_base_level = {};
#endif

#ifdef GL_TEXTURE_BINDING_1D
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_BINDING_1D,
	mp_list<oglplus::binding_query>
> texture_binding_1d = {};
#endif

#ifdef GL_TEXTURE_BINDING_1D_ARRAY
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_BINDING_1D_ARRAY,
	mp_list<oglplus::binding_query>
> texture_binding_1d_array = {};
#endif

#ifdef GL_TEXTURE_BINDING_2D
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_BINDING_2D,
	mp_list<oglplus::binding_query>
> texture_binding_2d = {};
#endif

#ifdef GL_TEXTURE_BINDING_2D_ARRAY
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_BINDING_2D_ARRAY,
	mp_list<oglplus::binding_query>
> texture_binding_2d_array = {};
#endif

#ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_BINDING_2D_MULTISAMPLE,
	mp_list<oglplus::binding_query>
> texture_binding_2d_multisample = {};
#endif

#ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY,
	mp_list<oglplus::binding_query>
> texture_binding_2d_multisample_array = {};
#endif

#ifdef GL_TEXTURE_BINDING_3D
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_BINDING_3D,
	mp_list<oglplus::binding_query>
> texture_binding_3d = {};
#endif

#ifdef GL_TEXTURE_BINDING_BUFFER
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_BINDING_BUFFER,
	mp_list<oglplus::binding_query>
> texture_binding_buffer = {};
#endif

#ifdef GL_TEXTURE_BINDING_CUBE_MAP
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_BINDING_CUBE_MAP,
	mp_list<oglplus::binding_query>
> texture_binding_cube_map = {};
#endif

#ifdef GL_TEXTURE_BINDING_CUBE_MAP_ARRAY
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_BINDING_CUBE_MAP_ARRAY,
	mp_list<oglplus::binding_query>
> texture_binding_cube_map_array = {};
#endif

#ifdef GL_TEXTURE_BINDING_RECTANGLE
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_BINDING_RECTANGLE,
	mp_list<oglplus::binding_query>
> texture_binding_rectangle = {};
#endif

#ifdef GL_TEXTURE_BORDER_COLOR
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_BORDER_COLOR,
	mp_list<oglplus::texture_parameter,oglplus::sampler_parameter>
> texture_border_color = {};
#endif

#ifdef GL_TEXTURE_BUFFER
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_BUFFER,
	mp_list<oglplus::texture_target,oglplus::buffer_target>
> texture_buffer = {};
#endif

#ifdef GL_TEXTURE_BUFFER_BINDING
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_BUFFER_BINDING,
	mp_list<oglplus::binding_query>
> texture_buffer_binding = {};
#endif

#ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT,
	mp_list<oglplus::numeric_query>
> texture_buffer_offset_alignment = {};
#endif

#ifdef GL_TEXTURE_COMPARE_FUNC
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_COMPARE_FUNC,
	mp_list<oglplus::texture_parameter,oglplus::sampler_parameter>
> texture_compare_func = {};
#endif

#ifdef GL_TEXTURE_COMPARE_MODE
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_COMPARE_MODE,
	mp_list<oglplus::texture_parameter,oglplus::sampler_parameter>
> texture_compare_mode = {};
#endif

#ifdef GL_TEXTURE_COMPRESSION_HINT
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_COMPRESSION_HINT,
	mp_list<oglplus::hint_target,oglplus::numeric_query>
> texture_compression_hint = {};
#endif

#ifdef GL_TEXTURE_CUBE_MAP
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_CUBE_MAP,
	mp_list<oglplus::texture_target>
> texture_cube_map = {};
#endif

#ifdef GL_TEXTURE_CUBE_MAP_ARRAY
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_CUBE_MAP_ARRAY,
	mp_list<oglplus::texture_target>
> texture_cube_map_array = {};
#endif

#ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_X
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_CUBE_MAP_NEGATIVE_X,
	mp_list<oglplus::texture_target>
> texture_cube_map_negative_x = {};
#endif

#ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_Y
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_CUBE_MAP_NEGATIVE_Y,
	mp_list<oglplus::texture_target>
> texture_cube_map_negative_y = {};
#endif

#ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_Z
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_CUBE_MAP_NEGATIVE_Z,
	mp_list<oglplus::texture_target>
> texture_cube_map_negative_z = {};
#endif

#ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_X
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_CUBE_MAP_POSITIVE_X,
	mp_list<oglplus::texture_target>
> texture_cube_map_positive_x = {};
#endif

#ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_Y
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_CUBE_MAP_POSITIVE_Y,
	mp_list<oglplus::texture_target>
> texture_cube_map_positive_y = {};
#endif

#ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_Z
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_CUBE_MAP_POSITIVE_Z,
	mp_list<oglplus::texture_target>
> texture_cube_map_positive_z = {};
#endif

#ifdef GL_TEXTURE_CUBE_MAP_SEAMLESS
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_CUBE_MAP_SEAMLESS,
	mp_list<oglplus::capability>
> texture_cube_map_seamless = {};
#endif

#ifdef GL_TEXTURE_FETCH_BARRIER_BIT
static constexpr const enum_value<
	GLbitfield,
	GL_TEXTURE_FETCH_BARRIER_BIT,
	mp_list<oglplus::memory_barrier_bits>
> texture_fetch_barrier_bit = {};
#endif

#ifdef GL_TEXTURE_IMMUTABLE_FORMAT
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_IMMUTABLE_FORMAT,
	mp_list<oglplus::texture_parameter>
> texture_immutable_format = {};
#endif

#ifdef GL_TEXTURE_IMMUTABLE_LEVELS
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_IMMUTABLE_LEVELS,
	mp_list<oglplus::texture_parameter>
> texture_immutable_levels = {};
#endif

#ifdef GL_TEXTURE_LOD_BIAS
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_LOD_BIAS,
	mp_list<oglplus::texture_parameter,oglplus::sampler_parameter>
> texture_lod_bias = {};
#endif

#ifdef GL_TEXTURE_MAG_FILTER
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_MAG_FILTER,
	mp_list<oglplus::texture_parameter,oglplus::sampler_parameter>
> texture_mag_filter = {};
#endif

#ifdef GL_TEXTURE_MAX_LEVEL
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_MAX_LEVEL,
	mp_list<oglplus::texture_parameter>
> texture_max_level = {};
#endif

#ifdef GL_TEXTURE_MAX_LOD
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_MAX_LOD,
	mp_list<oglplus::texture_parameter,oglplus::sampler_parameter>
> texture_max_lod = {};
#endif

#ifdef GL_TEXTURE_MIN_FILTER
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_MIN_FILTER,
	mp_list<oglplus::texture_parameter,oglplus::sampler_parameter>
> texture_min_filter = {};
#endif

#ifdef GL_TEXTURE_MIN_LOD
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_MIN_LOD,
	mp_list<oglplus::texture_parameter,oglplus::sampler_parameter>
> texture_min_lod = {};
#endif

#ifdef GL_TEXTURE_RECTANGLE
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_RECTANGLE,
	mp_list<oglplus::texture_target>
> texture_rectangle = {};
#endif

#ifdef GL_TEXTURE_SWIZZLE_A
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_SWIZZLE_A,
	mp_list<oglplus::texture_parameter,oglplus::texture_swizzle_coord>
> texture_swizzle_a = {};
#endif

#ifdef GL_TEXTURE_SWIZZLE_B
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_SWIZZLE_B,
	mp_list<oglplus::texture_parameter,oglplus::texture_swizzle_coord>
> texture_swizzle_b = {};
#endif

#ifdef GL_TEXTURE_SWIZZLE_G
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_SWIZZLE_G,
	mp_list<oglplus::texture_parameter,oglplus::texture_swizzle_coord>
> texture_swizzle_g = {};
#endif

#ifdef GL_TEXTURE_SWIZZLE_R
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_SWIZZLE_R,
	mp_list<oglplus::texture_parameter,oglplus::texture_swizzle_coord>
> texture_swizzle_r = {};
#endif

#ifdef GL_TEXTURE_SWIZZLE_RGBA
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_SWIZZLE_RGBA,
	mp_list<oglplus::texture_parameter,oglplus::texture_swizzle_coord>
> texture_swizzle_rgba = {};
#endif

#ifdef GL_TEXTURE_TARGET
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_TARGET,
	mp_list<oglplus::texture_parameter>
> texture_target = {};
#endif

#ifdef GL_TEXTURE_UPDATE_BARRIER_BIT
static constexpr const enum_value<
	GLbitfield,
	GL_TEXTURE_UPDATE_BARRIER_BIT,
	mp_list<oglplus::memory_barrier_bits>
> texture_update_barrier_bit = {};
#endif

#ifdef GL_TEXTURE_VIEW_MIN_LAYER
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_VIEW_MIN_LAYER,
	mp_list<oglplus::texture_parameter>
> texture_view_min_layer = {};
#endif

#ifdef GL_TEXTURE_VIEW_MIN_LEVEL
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_VIEW_MIN_LEVEL,
	mp_list<oglplus::texture_parameter>
> texture_view_min_level = {};
#endif

#ifdef GL_TEXTURE_VIEW_NUM_LAYERS
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_VIEW_NUM_LAYERS,
	mp_list<oglplus::texture_parameter>
> texture_view_num_layers = {};
#endif

#ifdef GL_TEXTURE_VIEW_NUM_LEVELS
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_VIEW_NUM_LEVELS,
	mp_list<oglplus::texture_parameter>
> texture_view_num_levels = {};
#endif

#ifdef GL_TEXTURE_WRAP_R
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_WRAP_R,
	mp_list<oglplus::texture_parameter,oglplus::sampler_parameter,oglplus::texture_wrap_coord>
> texture_wrap_r = {};
#endif

#ifdef GL_TEXTURE_WRAP_S
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_WRAP_S,
	mp_list<oglplus::texture_parameter,oglplus::sampler_parameter,oglplus::texture_wrap_coord>
> texture_wrap_s = {};
#endif

#ifdef GL_TEXTURE_WRAP_T
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_WRAP_T,
	mp_list<oglplus::texture_parameter,oglplus::sampler_parameter,oglplus::texture_wrap_coord>
> texture_wrap_t = {};
#endif

#ifdef GL_TIME_ELAPSED
static constexpr const enum_value<
	GLenum,
	GL_TIME_ELAPSED,
	mp_list<oglplus::query_target>
> time_elapsed = {};
#endif

#ifdef GL_TIMEOUT_EXPIRED
static constexpr const enum_value<
	GLenum,
	GL_TIMEOUT_EXPIRED,
	mp_list<oglplus::sync_wait_result>
> timeout_expired = {};
#endif

#ifdef GL_TIMESTAMP
static constexpr const enum_value<
	GLenum,
	GL_TIMESTAMP,
	mp_list<oglplus::query_target,oglplus::numeric_query>
> timestamp = {};
#endif

#ifdef GL_TOP_LEVEL_ARRAY_SIZE
static constexpr const enum_value<
	GLenum,
	GL_TOP_LEVEL_ARRAY_SIZE,
	mp_list<oglplus::program_resource_property>
> top_level_array_size = {};
#endif

#ifdef GL_TOP_LEVEL_ARRAY_STRIDE
static constexpr const enum_value<
	GLenum,
	GL_TOP_LEVEL_ARRAY_STRIDE,
	mp_list<oglplus::program_resource_property>
> top_level_array_stride = {};
#endif

#ifdef GL_TRANSFORM_FEEDBACK
static constexpr const enum_value<
	GLenum,
	GL_TRANSFORM_FEEDBACK,
	mp_list<oglplus::transform_feedback_target,oglplus::object_type>
> transform_feedback = {};
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BARRIER_BIT
static constexpr const enum_value<
	GLbitfield,
	GL_TRANSFORM_FEEDBACK_BARRIER_BIT,
	mp_list<oglplus::memory_barrier_bits>
> transform_feedback_barrier_bit = {};
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BINDING
static constexpr const enum_value<
	GLenum,
	GL_TRANSFORM_FEEDBACK_BINDING,
	mp_list<oglplus::binding_query>
> transform_feedback_binding = {};
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BUFFER
static constexpr const enum_value<
	GLenum,
	GL_TRANSFORM_FEEDBACK_BUFFER,
	mp_list<oglplus::buffer_indexed_target,oglplus::buffer_target>
> transform_feedback_buffer = {};
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_BINDING
static constexpr const enum_value<
	GLenum,
	GL_TRANSFORM_FEEDBACK_BUFFER_BINDING,
	mp_list<oglplus::binding_query>
> transform_feedback_buffer_binding = {};
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_INDEX
static constexpr const enum_value<
	GLenum,
	GL_TRANSFORM_FEEDBACK_BUFFER_INDEX,
	mp_list<oglplus::program_resource_property>
> transform_feedback_buffer_index = {};
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
static constexpr const enum_value<
	GLenum,
	GL_TRANSFORM_FEEDBACK_BUFFER_SIZE,
	mp_list<oglplus::numeric_query>
> transform_feedback_buffer_size = {};
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
static constexpr const enum_value<
	GLenum,
	GL_TRANSFORM_FEEDBACK_BUFFER_START,
	mp_list<oglplus::numeric_query>
> transform_feedback_buffer_start = {};
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE
static constexpr const enum_value<
	GLenum,
	GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE,
	mp_list<oglplus::program_resource_property>
> transform_feedback_buffer_stride = {};
#endif

#ifdef GL_TRANSFORM_FEEDBACK_OVERFLOW_ARB
static constexpr const enum_value<
	GLenum,
	GL_TRANSFORM_FEEDBACK_OVERFLOW_ARB,
	mp_list<oglplus::query_target>
> transform_feedback_overflow = {};
#endif

#ifdef GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN
static constexpr const enum_value<
	GLenum,
	GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN,
	mp_list<oglplus::query_target>
> transform_feedback_primitives_written = {};
#endif

#ifdef GL_TRANSFORM_FEEDBACK_STREAM_OVERFLOW_ARB
static constexpr const enum_value<
	GLenum,
	GL_TRANSFORM_FEEDBACK_STREAM_OVERFLOW_ARB,
	mp_list<oglplus::query_target>
> transform_feedback_stream_overflow = {};
#endif

#ifdef GL_TRANSFORM_FEEDEBACK_VARYING
static constexpr const enum_value<
	GLenum,
	GL_TRANSFORM_FEEDEBACK_VARYING,
	mp_list<oglplus::program_interface>
> transform_feedeback_varying = {};
#endif

#ifdef GL_TRANSLATE_2D_NV
static constexpr const enum_value<
	GLenum,
	GL_TRANSLATE_2D_NV,
	mp_list<oglplus::path_transform_type_nv>
> translate_2d_nv = {};
#endif

#ifdef GL_TRANSLATE_3D_NV
static constexpr const enum_value<
	GLenum,
	GL_TRANSLATE_3D_NV,
	mp_list<oglplus::path_transform_type_nv>
> translate_3d_nv = {};
#endif

#ifdef GL_TRANSLATE_X_NV
static constexpr const enum_value<
	GLenum,
	GL_TRANSLATE_X_NV,
	mp_list<oglplus::path_transform_type_nv>
> translate_x_nv = {};
#endif

#ifdef GL_TRANSLATE_Y_NV
static constexpr const enum_value<
	GLenum,
	GL_TRANSLATE_Y_NV,
	mp_list<oglplus::path_transform_type_nv>
> translate_y_nv = {};
#endif

#ifdef GL_TRANSPOSE_AFFINE_2D_NV
static constexpr const enum_value<
	GLenum,
	GL_TRANSPOSE_AFFINE_2D_NV,
	mp_list<oglplus::path_transform_type_nv>
> transpose_affine_2d_nv = {};
#endif

#ifdef GL_TRANSPOSE_AFFINE_3D_NV
static constexpr const enum_value<
	GLenum,
	GL_TRANSPOSE_AFFINE_3D_NV,
	mp_list<oglplus::path_transform_type_nv>
> transpose_affine_3d_nv = {};
#endif

#ifdef GL_TRIANGLE_FAN
static constexpr const enum_value<
	GLenum,
	GL_TRIANGLE_FAN,
	mp_list<oglplus::primitive_type,oglplus::old_primitive_type>
> triangle_fan = {};
#endif

#ifdef GL_TRIANGLE_STRIP
static constexpr const enum_value<
	GLenum,
	GL_TRIANGLE_STRIP,
	mp_list<oglplus::primitive_type,oglplus::old_primitive_type>
> triangle_strip = {};
#endif

#ifdef GL_TRIANGLE_STRIP_ADJACENCY
static constexpr const enum_value<
	GLenum,
	GL_TRIANGLE_STRIP_ADJACENCY,
	mp_list<oglplus::primitive_type>
> triangle_strip_adjacency = {};
#endif

#ifdef GL_TRIANGLES
static constexpr const enum_value<
	GLenum,
	GL_TRIANGLES,
	mp_list<oglplus::primitive_type,oglplus::old_primitive_type,oglplus::transform_feedback_primitive_type,oglplus::tess_gen_primitive_type>
> triangles = {};
#endif

#ifdef GL_TRIANGLES_ADJACENCY
static constexpr const enum_value<
	GLenum,
	GL_TRIANGLES_ADJACENCY,
	mp_list<oglplus::primitive_type>
> triangles_adjacency = {};
#endif

#ifdef GL_TRIANGULAR_NV
static constexpr const enum_value<
	GLenum,
	GL_TRIANGULAR_NV,
	mp_list<oglplus::path_cap_style_nv>
> triangular_nv = {};
#endif

#ifdef GL_TRUE
static constexpr const enum_value<
	GLboolean,
	GL_TRUE,
	mp_list<oglplus::true_false>
> true_ = {};
#endif

#ifdef GL_UNIFORM
static constexpr const enum_value<
	GLenum,
	GL_UNIFORM,
	mp_list<oglplus::program_interface>
> uniform = {};
#endif

#ifdef GL_UNIFORM_BARRIER_BIT
static constexpr const enum_value<
	GLbitfield,
	GL_UNIFORM_BARRIER_BIT,
	mp_list<oglplus::memory_barrier_bits>
> uniform_barrier_bit = {};
#endif

#ifdef GL_UNIFORM_BLOCK
static constexpr const enum_value<
	GLenum,
	GL_UNIFORM_BLOCK,
	mp_list<oglplus::program_interface>
> uniform_block = {};
#endif

#ifdef GL_UNIFORM_BUFFER
static constexpr const enum_value<
	GLenum,
	GL_UNIFORM_BUFFER,
	mp_list<oglplus::buffer_indexed_target,oglplus::buffer_target>
> uniform_buffer = {};
#endif

#ifdef GL_UNIFORM_BUFFER_BINDING
static constexpr const enum_value<
	GLenum,
	GL_UNIFORM_BUFFER_BINDING,
	mp_list<oglplus::binding_query>
> uniform_buffer_binding = {};
#endif

#ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
static constexpr const enum_value<
	GLenum,
	GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT,
	mp_list<oglplus::numeric_query>
> uniform_buffer_offset_alignment = {};
#endif

#ifdef GL_UNIFORM_BUFFER_SIZE
static constexpr const enum_value<
	GLenum,
	GL_UNIFORM_BUFFER_SIZE,
	mp_list<oglplus::numeric_query>
> uniform_buffer_size = {};
#endif

#ifdef GL_UNIFORM_BUFFER_START
static constexpr const enum_value<
	GLenum,
	GL_UNIFORM_BUFFER_START,
	mp_list<oglplus::numeric_query>
> uniform_buffer_start = {};
#endif

#ifdef GL_UNKNOWN_CONTEXT_RESET
static constexpr const enum_value<
	GLenum,
	GL_UNKNOWN_CONTEXT_RESET,
	mp_list<oglplus::graphics_reset_status>
> unknown_context_reset = {};
#endif

#ifdef GL_UNPACK_ALIGNMENT
static constexpr const enum_value<
	GLenum,
	GL_UNPACK_ALIGNMENT,
	mp_list<oglplus::numeric_query,oglplus::pixel_parameter>
> unpack_alignment = {};
#endif

#ifdef GL_UNPACK_COMPRESSED_BLOCK_DEPTH
static constexpr const enum_value<
	GLenum,
	GL_UNPACK_COMPRESSED_BLOCK_DEPTH,
	mp_list<oglplus::pixel_parameter>
> unpack_compressed_block_depth = {};
#endif

#ifdef GL_UNPACK_COMPRESSED_BLOCK_HEIGHT
static constexpr const enum_value<
	GLenum,
	GL_UNPACK_COMPRESSED_BLOCK_HEIGHT,
	mp_list<oglplus::pixel_parameter>
> unpack_compressed_block_height = {};
#endif

#ifdef GL_UNPACK_COMPRESSED_BLOCK_SIZE
static constexpr const enum_value<
	GLenum,
	GL_UNPACK_COMPRESSED_BLOCK_SIZE,
	mp_list<oglplus::pixel_parameter>
> unpack_compressed_block_size = {};
#endif

#ifdef GL_UNPACK_COMPRESSED_BLOCK_WIDTH
static constexpr const enum_value<
	GLenum,
	GL_UNPACK_COMPRESSED_BLOCK_WIDTH,
	mp_list<oglplus::pixel_parameter>
> unpack_compressed_block_width = {};
#endif

#ifdef GL_UNPACK_IMAGE_HEIGHT
static constexpr const enum_value<
	GLenum,
	GL_UNPACK_IMAGE_HEIGHT,
	mp_list<oglplus::numeric_query,oglplus::pixel_parameter>
> unpack_image_height = {};
#endif

#ifdef GL_UNPACK_LSB_FIRST
static constexpr const enum_value<
	GLenum,
	GL_UNPACK_LSB_FIRST,
	mp_list<oglplus::numeric_query,oglplus::pixel_parameter>
> unpack_lsb_first = {};
#endif

#ifdef GL_UNPACK_ROW_LENGTH
static constexpr const enum_value<
	GLenum,
	GL_UNPACK_ROW_LENGTH,
	mp_list<oglplus::numeric_query,oglplus::pixel_parameter>
> unpack_row_length = {};
#endif

#ifdef GL_UNPACK_SKIP_IMAGES
static constexpr const enum_value<
	GLenum,
	GL_UNPACK_SKIP_IMAGES,
	mp_list<oglplus::numeric_query,oglplus::pixel_parameter>
> unpack_skip_images = {};
#endif

#ifdef GL_UNPACK_SKIP_PIXELS
static constexpr const enum_value<
	GLenum,
	GL_UNPACK_SKIP_PIXELS,
	mp_list<oglplus::numeric_query,oglplus::pixel_parameter>
> unpack_skip_pixels = {};
#endif

#ifdef GL_UNPACK_SKIP_ROWS
static constexpr const enum_value<
	GLenum,
	GL_UNPACK_SKIP_ROWS,
	mp_list<oglplus::numeric_query,oglplus::pixel_parameter>
> unpack_skip_rows = {};
#endif

#ifdef GL_UNPACK_SWAP_BYTES
static constexpr const enum_value<
	GLenum,
	GL_UNPACK_SWAP_BYTES,
	mp_list<oglplus::numeric_query,oglplus::pixel_parameter>
> unpack_swap_bytes = {};
#endif

#ifdef GL_UNSIGNALED
static constexpr const enum_value<
	GLenum,
	GL_UNSIGNALED,
	mp_list<oglplus::sync_status>
> unsignaled = {};
#endif

#ifdef GL_UNSIGNED_BYTE
static constexpr const enum_value<
	GLenum,
	GL_UNSIGNED_BYTE,
	mp_list<oglplus::index_type,oglplus::pixel_data_type,oglplus::data_type>
> unsigned_byte = {};
#endif

#ifdef GL_UNSIGNED_BYTE_2_3_3_REV
static constexpr const enum_value<
	GLenum,
	GL_UNSIGNED_BYTE_2_3_3_REV,
	mp_list<oglplus::pixel_data_type>
> unsigned_byte_2_3_3_rev = {};
#endif

#ifdef GL_UNSIGNED_BYTE_3_3_2
static constexpr const enum_value<
	GLenum,
	GL_UNSIGNED_BYTE_3_3_2,
	mp_list<oglplus::pixel_data_type>
> unsigned_byte_3_3_2 = {};
#endif

#ifdef GL_UNSIGNED_INT
static constexpr const enum_value<
	GLenum,
	GL_UNSIGNED_INT,
	mp_list<oglplus::index_type,oglplus::sl_data_type,oglplus::pixel_data_type,oglplus::data_type>
> unsigned_int = {};
#endif

#ifdef GL_UNSIGNED_INT_10_10_10_2
static constexpr const enum_value<
	GLenum,
	GL_UNSIGNED_INT_10_10_10_2,
	mp_list<oglplus::pixel_data_type>
> unsigned_int_10_10_10_2 = {};
#endif

#ifdef GL_UNSIGNED_INT_10F_11F_11F_REV
static constexpr const enum_value<
	GLenum,
	GL_UNSIGNED_INT_10F_11F_11F_REV,
	mp_list<oglplus::pixel_data_type>
> unsigned_int_10f_11f_11f_rev = {};
#endif

#ifdef GL_UNSIGNED_INT_24_8
static constexpr const enum_value<
	GLenum,
	GL_UNSIGNED_INT_24_8,
	mp_list<oglplus::pixel_data_type>
> unsigned_int_24_8 = {};
#endif

#ifdef GL_UNSIGNED_INT_2_10_10_10_REV
static constexpr const enum_value<
	GLenum,
	GL_UNSIGNED_INT_2_10_10_10_REV,
	mp_list<oglplus::pixel_data_type>
> unsigned_int_2_10_10_10_rev = {};
#endif

#ifdef GL_UNSIGNED_INT_5_9_9_9_REV
static constexpr const enum_value<
	GLenum,
	GL_UNSIGNED_INT_5_9_9_9_REV,
	mp_list<oglplus::pixel_data_type>
> unsigned_int_5_9_9_9_rev = {};
#endif

#ifdef GL_UNSIGNED_INT_8_8_8_8
static constexpr const enum_value<
	GLenum,
	GL_UNSIGNED_INT_8_8_8_8,
	mp_list<oglplus::pixel_data_type>
> unsigned_int_8_8_8_8 = {};
#endif

#ifdef GL_UNSIGNED_INT_8_8_8_8_REV
static constexpr const enum_value<
	GLenum,
	GL_UNSIGNED_INT_8_8_8_8_REV,
	mp_list<oglplus::pixel_data_type>
> unsigned_int_8_8_8_8_rev = {};
#endif

#ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
static constexpr const enum_value<
	GLenum,
	GL_UNSIGNED_INT_ATOMIC_COUNTER,
	mp_list<oglplus::sl_data_type>
> unsigned_int_atomic_counter = {};
#endif

#ifdef GL_UNSIGNED_INT_IMAGE_1D
static constexpr const enum_value<
	GLenum,
	GL_UNSIGNED_INT_IMAGE_1D,
	mp_list<oglplus::sl_data_type>
> unsigned_int_image_1d = {};
#endif

#ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
static constexpr const enum_value<
	GLenum,
	GL_UNSIGNED_INT_IMAGE_1D_ARRAY,
	mp_list<oglplus::sl_data_type>
> unsigned_int_image_1d_array = {};
#endif

#ifdef GL_UNSIGNED_INT_IMAGE_2D
static constexpr const enum_value<
	GLenum,
	GL_UNSIGNED_INT_IMAGE_2D,
	mp_list<oglplus::sl_data_type>
> unsigned_int_image_2d = {};
#endif

#ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
static constexpr const enum_value<
	GLenum,
	GL_UNSIGNED_INT_IMAGE_2D_ARRAY,
	mp_list<oglplus::sl_data_type>
> unsigned_int_image_2d_array = {};
#endif

#ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
static constexpr const enum_value<
	GLenum,
	GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE,
	mp_list<oglplus::sl_data_type>
> unsigned_int_image_2d_multisample = {};
#endif

#ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
static constexpr const enum_value<
	GLenum,
	GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY,
	mp_list<oglplus::sl_data_type>
> unsigned_int_image_2d_multisample_array = {};
#endif

#ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
static constexpr const enum_value<
	GLenum,
	GL_UNSIGNED_INT_IMAGE_2D_RECT,
	mp_list<oglplus::sl_data_type>
> unsigned_int_image_2d_rect = {};
#endif

#ifdef GL_UNSIGNED_INT_IMAGE_3D
static constexpr const enum_value<
	GLenum,
	GL_UNSIGNED_INT_IMAGE_3D,
	mp_list<oglplus::sl_data_type>
> unsigned_int_image_3d = {};
#endif

#ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
static constexpr const enum_value<
	GLenum,
	GL_UNSIGNED_INT_IMAGE_BUFFER,
	mp_list<oglplus::sl_data_type>
> unsigned_int_image_buffer = {};
#endif

#ifdef GL_UNSIGNED_INT_IMAGE_CUBE
static constexpr const enum_value<
	GLenum,
	GL_UNSIGNED_INT_IMAGE_CUBE,
	mp_list<oglplus::sl_data_type>
> unsigned_int_image_cube = {};
#endif

#ifdef GL_UNSIGNED_INT_SAMPLER_1D
static constexpr const enum_value<
	GLenum,
	GL_UNSIGNED_INT_SAMPLER_1D,
	mp_list<oglplus::sl_data_type>
> unsigned_int_sampler_1d = {};
#endif

#ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
static constexpr const enum_value<
	GLenum,
	GL_UNSIGNED_INT_SAMPLER_1D_ARRAY,
	mp_list<oglplus::sl_data_type>
> unsigned_int_sampler_1d_array = {};
#endif

#ifdef GL_UNSIGNED_INT_SAMPLER_2D
static constexpr const enum_value<
	GLenum,
	GL_UNSIGNED_INT_SAMPLER_2D,
	mp_list<oglplus::sl_data_type>
> unsigned_int_sampler_2d = {};
#endif

#ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
static constexpr const enum_value<
	GLenum,
	GL_UNSIGNED_INT_SAMPLER_2D_ARRAY,
	mp_list<oglplus::sl_data_type>
> unsigned_int_sampler_2d_array = {};
#endif

#ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
static constexpr const enum_value<
	GLenum,
	GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE,
	mp_list<oglplus::sl_data_type>
> unsigned_int_sampler_2d_multisample = {};
#endif

#ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
static constexpr const enum_value<
	GLenum,
	GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY,
	mp_list<oglplus::sl_data_type>
> unsigned_int_sampler_2d_multisample_array = {};
#endif

#ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
static constexpr const enum_value<
	GLenum,
	GL_UNSIGNED_INT_SAMPLER_2D_RECT,
	mp_list<oglplus::sl_data_type>
> unsigned_int_sampler_2d_rect = {};
#endif

#ifdef GL_UNSIGNED_INT_SAMPLER_3D
static constexpr const enum_value<
	GLenum,
	GL_UNSIGNED_INT_SAMPLER_3D,
	mp_list<oglplus::sl_data_type>
> unsigned_int_sampler_3d = {};
#endif

#ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
static constexpr const enum_value<
	GLenum,
	GL_UNSIGNED_INT_SAMPLER_BUFFER,
	mp_list<oglplus::sl_data_type>
> unsigned_int_sampler_buffer = {};
#endif

#ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
static constexpr const enum_value<
	GLenum,
	GL_UNSIGNED_INT_SAMPLER_CUBE,
	mp_list<oglplus::sl_data_type>
> unsigned_int_sampler_cube = {};
#endif

#ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
static constexpr const enum_value<
	GLenum,
	GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY,
	mp_list<oglplus::sl_data_type>
> unsigned_int_sampler_cube_map_array = {};
#endif

#ifdef GL_UNSIGNED_INT_VEC2
static constexpr const enum_value<
	GLenum,
	GL_UNSIGNED_INT_VEC2,
	mp_list<oglplus::sl_data_type>
> unsigned_int_vec2 = {};
#endif

#ifdef GL_UNSIGNED_INT_VEC3
static constexpr const enum_value<
	GLenum,
	GL_UNSIGNED_INT_VEC3,
	mp_list<oglplus::sl_data_type>
> unsigned_int_vec3 = {};
#endif

#ifdef GL_UNSIGNED_INT_VEC4
static constexpr const enum_value<
	GLenum,
	GL_UNSIGNED_INT_VEC4,
	mp_list<oglplus::sl_data_type>
> unsigned_int_vec4 = {};
#endif

#ifdef GL_UNSIGNED_SHORT
static constexpr const enum_value<
	GLenum,
	GL_UNSIGNED_SHORT,
	mp_list<oglplus::index_type,oglplus::pixel_data_type,oglplus::data_type>
> unsigned_short = {};
#endif

#ifdef GL_UNSIGNED_SHORT_1_5_5_5_REV
static constexpr const enum_value<
	GLenum,
	GL_UNSIGNED_SHORT_1_5_5_5_REV,
	mp_list<oglplus::pixel_data_type>
> unsigned_short_1_5_5_5_rev = {};
#endif

#ifdef GL_UNSIGNED_SHORT_4_4_4_4
static constexpr const enum_value<
	GLenum,
	GL_UNSIGNED_SHORT_4_4_4_4,
	mp_list<oglplus::pixel_data_type>
> unsigned_short_4_4_4_4 = {};
#endif

#ifdef GL_UNSIGNED_SHORT_4_4_4_4_REV
static constexpr const enum_value<
	GLenum,
	GL_UNSIGNED_SHORT_4_4_4_4_REV,
	mp_list<oglplus::pixel_data_type>
> unsigned_short_4_4_4_4_rev = {};
#endif

#ifdef GL_UNSIGNED_SHORT_5_5_5_1
static constexpr const enum_value<
	GLenum,
	GL_UNSIGNED_SHORT_5_5_5_1,
	mp_list<oglplus::pixel_data_type>
> unsigned_short_5_5_5_1 = {};
#endif

#ifdef GL_UNSIGNED_SHORT_5_6_5
static constexpr const enum_value<
	GLenum,
	GL_UNSIGNED_SHORT_5_6_5,
	mp_list<oglplus::pixel_data_type>
> unsigned_short_5_6_5 = {};
#endif

#ifdef GL_UNSIGNED_SHORT_5_6_5_REV
static constexpr const enum_value<
	GLenum,
	GL_UNSIGNED_SHORT_5_6_5_REV,
	mp_list<oglplus::pixel_data_type>
> unsigned_short_5_6_5_rev = {};
#endif

#ifdef GL_UPPER_LEFT
static constexpr const enum_value<
	GLenum,
	GL_UPPER_LEFT,
	mp_list<oglplus::clip_origin>
> upper_left = {};
#endif

#ifdef GL_USE_MISSING_GLYPH_NV
static constexpr const enum_value<
	GLenum,
	GL_USE_MISSING_GLYPH_NV,
	mp_list<oglplus::path_missing_glyph_nv>
> use_missing_glyph_nv = {};
#endif

#ifdef GL_UTF16_NV
static constexpr const enum_value<
	GLenum,
	GL_UTF16_NV,
	mp_list<oglplus::path_text_encoding_nv>
> utf16_nv = {};
#endif

#ifdef GL_UTF8_NV
static constexpr const enum_value<
	GLenum,
	GL_UTF8_NV,
	mp_list<oglplus::path_text_encoding_nv>
> utf8_nv = {};
#endif

#ifdef GL_VALIDATE_STATUS
static constexpr const enum_value<
	GLenum,
	GL_VALIDATE_STATUS,
	mp_list<oglplus::program_parameter>
> validate_status = {};
#endif

#ifdef GL_VENDOR
static constexpr const enum_value<
	GLenum,
	GL_VENDOR,
	mp_list<oglplus::string_query>
> vendor = {};
#endif

#ifdef GL_VERSION
static constexpr const enum_value<
	GLenum,
	GL_VERSION,
	mp_list<oglplus::string_query>
> version = {};
#endif

#ifdef GL_VERTEX_ARRAY
static constexpr const enum_value<
	GLenum,
	GL_VERTEX_ARRAY,
	mp_list<oglplus::object_type>
> vertex_array = {};
#endif

#ifdef GL_VERTEX_ARRAY_BINDING
static constexpr const enum_value<
	GLenum,
	GL_VERTEX_ARRAY_BINDING,
	mp_list<oglplus::binding_query>
> vertex_array_binding = {};
#endif

#ifdef GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT
static constexpr const enum_value<
	GLbitfield,
	GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT,
	mp_list<oglplus::memory_barrier_bits>
> vertex_attrib_array_barrier_bit = {};
#endif

#ifdef GL_VERTEX_SHADER
static constexpr const enum_value<
	GLenum,
	GL_VERTEX_SHADER,
	mp_list<oglplus::shader_type,oglplus::program_pipeline_parameter>
> vertex_shader = {};
#endif

#ifdef GL_VERTEX_SHADER_BIT
static constexpr const enum_value<
	GLbitfield,
	GL_VERTEX_SHADER_BIT,
	mp_list<oglplus::program_pipeline_stage>
> vertex_shader_bit = {};
#endif

#ifdef GL_VERTEX_SHADER_INVOCATIONS_ARB
static constexpr const enum_value<
	GLenum,
	GL_VERTEX_SHADER_INVOCATIONS_ARB,
	mp_list<oglplus::query_target>
> vertex_shader_invocations = {};
#endif

#ifdef GL_VERTEX_SUBROUTINE
static constexpr const enum_value<
	GLenum,
	GL_VERTEX_SUBROUTINE,
	mp_list<oglplus::program_interface>
> vertex_subroutine = {};
#endif

#ifdef GL_VERTEX_SUBROUTINE_UNIFORM
static constexpr const enum_value<
	GLenum,
	GL_VERTEX_SUBROUTINE_UNIFORM,
	mp_list<oglplus::program_interface>
> vertex_subroutine_uniform = {};
#endif

#ifdef GL_VERTICAL_LINE_TO_NV
static constexpr const enum_value<
	GLubyte,
	GL_VERTICAL_LINE_TO_NV,
	mp_list<oglplus::path_command_nv>
> vertical_line_to_nv = {};
#endif

#ifdef GL_VERTICES_SUBMITTED_ARB
static constexpr const enum_value<
	GLenum,
	GL_VERTICES_SUBMITTED_ARB,
	mp_list<oglplus::query_target>
> vertices_submitted = {};
#endif

#ifdef GL_VIEWPORT
static constexpr const enum_value<
	GLenum,
	GL_VIEWPORT,
	mp_list<oglplus::numeric_query>
> viewport = {};
#endif

#ifdef GL_VIEWPORT_BOUNDS_RANGE
static constexpr const enum_value<
	GLenum,
	GL_VIEWPORT_BOUNDS_RANGE,
	mp_list<oglplus::numeric_query>
> viewport_bounds_range = {};
#endif

#ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
static constexpr const enum_value<
	GLenum,
	GL_VIEWPORT_INDEX_PROVOKING_VERTEX,
	mp_list<oglplus::numeric_query>
> viewport_index_provoking_vertex = {};
#endif

#ifdef GL_VIEWPORT_SUBPIXEL_BITS
static constexpr const enum_value<
	GLenum,
	GL_VIEWPORT_SUBPIXEL_BITS,
	mp_list<oglplus::numeric_query>
> viewport_subpixel_bits = {};
#endif

#ifdef GL_WAIT_FAILED
static constexpr const enum_value<
	GLenum,
	GL_WAIT_FAILED,
	mp_list<oglplus::sync_wait_result>
> wait_failed = {};
#endif

#ifdef GL_WRITE_ONLY
static constexpr const enum_value<
	GLenum,
	GL_WRITE_ONLY,
	mp_list<oglplus::access_specifier>
> write_only = {};
#endif

#ifdef GL_XOR
static constexpr const enum_value<
	GLenum,
	GL_XOR,
	mp_list<oglplus::color_logic_operation>
> xor_ = {};
#endif

#ifdef GL_ZERO
static constexpr const enum_value<
	GLenum,
	GL_ZERO,
	mp_list<oglplus::blend_function,oglplus::texture_swizzle_mode,oglplus::stencil_operation>
> zero = {};
#endif

#ifdef GL_ZERO_TO_ONE
static constexpr const enum_value<
	GLenum,
	GL_ZERO_TO_ONE,
	mp_list<oglplus::clip_depth_mode>
> zero_to_one = {};
#endif

};// struct enum_values
} // namespace oglplus

#endif // include guard
