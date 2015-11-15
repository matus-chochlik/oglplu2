//  File implement/oglplus/enum/value_defs.inl
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

namespace oglplus {

#ifdef GL_ACCUM_ADJACENT_PAIRS_NV
const enum_value<
	GLenum,
	GL_ACCUM_ADJACENT_PAIRS_NV,
	mp_list<oglplus::path_list_mode_nv>
> enum_value::accum_adjacent_pairs_nv;
#endif

#ifdef GL_ACTIVE_ATTRIBUTE_MAX_LENGTH
const enum_value<
	GLenum,
	GL_ACTIVE_ATTRIBUTE_MAX_LENGTH,
	mp_list<oglplus::program_parameter>
> enum_value::active_attribute_max_length;
#endif

#ifdef GL_ACTIVE_ATTRIBUTES
const enum_value<
	GLenum,
	GL_ACTIVE_ATTRIBUTES,
	mp_list<oglplus::program_parameter>
> enum_value::active_attributes;
#endif

#ifdef GL_ACTIVE_PROGRAM
const enum_value<
	GLenum,
	GL_ACTIVE_PROGRAM,
	mp_list<oglplus::program_pipeline_parameter>
> enum_value::active_program;
#endif

#ifdef GL_ACTIVE_UNIFORM_MAX_LENGTH
const enum_value<
	GLenum,
	GL_ACTIVE_UNIFORM_MAX_LENGTH,
	mp_list<oglplus::program_parameter>
> enum_value::active_uniform_max_length;
#endif

#ifdef GL_ACTIVE_UNIFORMS
const enum_value<
	GLenum,
	GL_ACTIVE_UNIFORMS,
	mp_list<oglplus::program_parameter>
> enum_value::active_uniforms;
#endif

#ifdef GL_ACTIVE_VARIABLES
const enum_value<
	GLenum,
	GL_ACTIVE_VARIABLES,
	mp_list<oglplus::program_resource_property>
> enum_value::active_variables;
#endif

#ifdef GL_ADJACENT_PAIRS_NV
const enum_value<
	GLenum,
	GL_ADJACENT_PAIRS_NV,
	mp_list<oglplus::path_list_mode_nv>
> enum_value::adjacent_pairs_nv;
#endif

#ifdef GL_AFFINE_2D_NV
const enum_value<
	GLenum,
	GL_AFFINE_2D_NV,
	mp_list<oglplus::path_transform_type_nv>
> enum_value::affine_2d_nv;
#endif

#ifdef GL_AFFINE_3D_NV
const enum_value<
	GLenum,
	GL_AFFINE_3D_NV,
	mp_list<oglplus::path_transform_type_nv>
> enum_value::affine_3d_nv;
#endif

#ifdef GL_ALIASED_LINE_WIDTH_RANGE
const enum_value<
	GLenum,
	GL_ALIASED_LINE_WIDTH_RANGE,
	mp_list<oglplus::numeric_query>
> enum_value::aliased_line_width_range;
#endif

#ifdef GL_ALL_BARRIER_BITS
const enum_value<
	GLbitfield,
	GL_ALL_BARRIER_BITS,
	mp_list<oglplus::memory_barrier_bits>
> enum_value::all_barrier_bits;
#endif

#ifdef GL_ALL_SHADER_BITS
const enum_value<
	GLbitfield,
	GL_ALL_SHADER_BITS,
	mp_list<oglplus::program_pipeline_stage>
> enum_value::all_shader_bits;
#endif

#ifdef GL_ALPHA
const enum_value<
	GLenum,
	GL_ALPHA,
	mp_list<oglplus::path_color_format_nv,oglplus::texture_swizzle_mode>
> enum_value::alpha;
#endif

#ifdef GL_ALREADY_SIGNALED
const enum_value<
	GLenum,
	GL_ALREADY_SIGNALED,
	mp_list<oglplus::sync_wait_result>
> enum_value::already_signaled;
#endif

#ifdef GL_ALWAYS
const enum_value<
	GLenum,
	GL_ALWAYS,
	mp_list<oglplus::compare_function>
> enum_value::always;
#endif

#ifdef GL_AND
const enum_value<
	GLenum,
	GL_AND,
	mp_list<oglplus::color_logic_operation>
> enum_value::and_;
#endif

#ifdef GL_AND_INVERTED
const enum_value<
	GLenum,
	GL_AND_INVERTED,
	mp_list<oglplus::color_logic_operation>
> enum_value::and_inverted;
#endif

#ifdef GL_AND_REVERSE
const enum_value<
	GLenum,
	GL_AND_REVERSE,
	mp_list<oglplus::color_logic_operation>
> enum_value::and_reverse;
#endif

#ifdef GL_ANY_SAMPLES_PASSED
const enum_value<
	GLenum,
	GL_ANY_SAMPLES_PASSED,
	mp_list<oglplus::query_target>
> enum_value::any_samples_passed;
#endif

#ifdef GL_ARC_TO_NV
const enum_value<
	GLubyte,
	GL_ARC_TO_NV,
	mp_list<oglplus::path_command_nv>
> enum_value::arc_to_nv;
#endif

#ifdef GL_ARRAY_BUFFER
const enum_value<
	GLenum,
	GL_ARRAY_BUFFER,
	mp_list<oglplus::buffer_target>
> enum_value::array_buffer;
#endif

#ifdef GL_ARRAY_BUFFER_BINDING
const enum_value<
	GLenum,
	GL_ARRAY_BUFFER_BINDING,
	mp_list<oglplus::binding_query>
> enum_value::array_buffer_binding;
#endif

#ifdef GL_ARRAY_SIZE
const enum_value<
	GLenum,
	GL_ARRAY_SIZE,
	mp_list<oglplus::program_resource_property>
> enum_value::array_size;
#endif

#ifdef GL_ARRAY_STRIDE
const enum_value<
	GLenum,
	GL_ARRAY_STRIDE,
	mp_list<oglplus::program_resource_property>
> enum_value::array_stride;
#endif

#ifdef GL_ATOMIC_COUNTER_BARRIER_BIT
const enum_value<
	GLbitfield,
	GL_ATOMIC_COUNTER_BARRIER_BIT,
	mp_list<oglplus::memory_barrier_bits>
> enum_value::atomic_counter_barrier_bit;
#endif

#ifdef GL_ATOMIC_COUNTER_BUFFER
const enum_value<
	GLenum,
	GL_ATOMIC_COUNTER_BUFFER,
	mp_list<oglplus::buffer_indexed_target,oglplus::buffer_target,oglplus::program_interface>
> enum_value::atomic_counter_buffer;
#endif

#ifdef GL_ATOMIC_COUNTER_BUFFER_BINDING
const enum_value<
	GLenum,
	GL_ATOMIC_COUNTER_BUFFER_BINDING,
	mp_list<oglplus::binding_query>
> enum_value::atomic_counter_buffer_binding;
#endif

#ifdef GL_ATOMIC_COUNTER_BUFFER_INDEX
const enum_value<
	GLenum,
	GL_ATOMIC_COUNTER_BUFFER_INDEX,
	mp_list<oglplus::program_resource_property>
> enum_value::atomic_counter_buffer_index;
#endif

#ifdef GL_ATTACHED_SHADERS
const enum_value<
	GLenum,
	GL_ATTACHED_SHADERS,
	mp_list<oglplus::program_parameter>
> enum_value::attached_shaders;
#endif

#ifdef GL_BACK
const enum_value<
	GLenum,
	GL_BACK,
	mp_list<oglplus::color_buffer,oglplus::single_face,oglplus::face>
> enum_value::back;
#endif

#ifdef GL_BACK_LEFT
const enum_value<
	GLenum,
	GL_BACK_LEFT,
	mp_list<oglplus::color_buffer>
> enum_value::back_left;
#endif

#ifdef GL_BACK_RIGHT
const enum_value<
	GLenum,
	GL_BACK_RIGHT,
	mp_list<oglplus::color_buffer>
> enum_value::back_right;
#endif

#ifdef GL_BEVEL_NV
const enum_value<
	GLenum,
	GL_BEVEL_NV,
	mp_list<oglplus::path_join_style_nv>
> enum_value::bevel_nv;
#endif

#ifdef GL_BGR
const enum_value<
	GLenum,
	GL_BGR,
	mp_list<oglplus::pixel_data_format>
> enum_value::bgr;
#endif

#ifdef GL_BGR_INTEGER
const enum_value<
	GLenum,
	GL_BGR_INTEGER,
	mp_list<oglplus::pixel_data_format>
> enum_value::bgr_integer;
#endif

#ifdef GL_BGRA
const enum_value<
	GLenum,
	GL_BGRA,
	mp_list<oglplus::pixel_data_format>
> enum_value::bgra;
#endif

#ifdef GL_BGRA_INTEGER
const enum_value<
	GLenum,
	GL_BGRA_INTEGER,
	mp_list<oglplus::pixel_data_format>
> enum_value::bgra_integer;
#endif

#ifdef GL_BLEND
const enum_value<
	GLenum,
	GL_BLEND,
	mp_list<oglplus::capability>
> enum_value::blend;
#endif

#ifdef GL_BLEND_ADVANCED_COHERENT_KHR
const enum_value<
	GLenum,
	GL_BLEND_ADVANCED_COHERENT_KHR,
	mp_list<oglplus::capability>
> enum_value::blend_advanced_coherent;
#endif

#ifdef GL_BLEND_COLOR
const enum_value<
	GLenum,
	GL_BLEND_COLOR,
	mp_list<oglplus::numeric_query>
> enum_value::blend_color;
#endif

#ifdef GL_BLEND_DST_ALPHA
const enum_value<
	GLenum,
	GL_BLEND_DST_ALPHA,
	mp_list<oglplus::numeric_query>
> enum_value::blend_dst_alpha;
#endif

#ifdef GL_BLEND_DST_RGB
const enum_value<
	GLenum,
	GL_BLEND_DST_RGB,
	mp_list<oglplus::numeric_query>
> enum_value::blend_dst_rgb;
#endif

#ifdef GL_BLEND_EQUATION_ALPHA
const enum_value<
	GLenum,
	GL_BLEND_EQUATION_ALPHA,
	mp_list<oglplus::numeric_query>
> enum_value::blend_equation_alpha;
#endif

#ifdef GL_BLEND_EQUATION_RGB
const enum_value<
	GLenum,
	GL_BLEND_EQUATION_RGB,
	mp_list<oglplus::numeric_query>
> enum_value::blend_equation_rgb;
#endif

#ifdef GL_BLEND_SRC_ALPHA
const enum_value<
	GLenum,
	GL_BLEND_SRC_ALPHA,
	mp_list<oglplus::numeric_query>
> enum_value::blend_src_alpha;
#endif

#ifdef GL_BLEND_SRC_RGB
const enum_value<
	GLenum,
	GL_BLEND_SRC_RGB,
	mp_list<oglplus::numeric_query>
> enum_value::blend_src_rgb;
#endif

#ifdef GL_BLOCK_INDEX
const enum_value<
	GLenum,
	GL_BLOCK_INDEX,
	mp_list<oglplus::program_resource_property>
> enum_value::block_index;
#endif

#ifdef GL_BLUE
const enum_value<
	GLenum,
	GL_BLUE,
	mp_list<oglplus::texture_swizzle_mode,oglplus::pixel_data_format>
> enum_value::blue;
#endif

#ifdef GL_BLUE_INTEGER
const enum_value<
	GLenum,
	GL_BLUE_INTEGER,
	mp_list<oglplus::pixel_data_format>
> enum_value::blue_integer;
#endif

#ifdef GL_BOLD_BIT_NV
const enum_value<
	GLbitfield,
	GL_BOLD_BIT_NV,
	mp_list<oglplus::path_font_style_nv>
> enum_value::bold_bit_nv;
#endif

#ifdef GL_BOOL
const enum_value<
	GLenum,
	GL_BOOL,
	mp_list<oglplus::sl_data_type>
> enum_value::bool_;
#endif

#ifdef GL_BOOL_VEC2
const enum_value<
	GLenum,
	GL_BOOL_VEC2,
	mp_list<oglplus::sl_data_type>
> enum_value::bool_vec2;
#endif

#ifdef GL_BOOL_VEC3
const enum_value<
	GLenum,
	GL_BOOL_VEC3,
	mp_list<oglplus::sl_data_type>
> enum_value::bool_vec3;
#endif

#ifdef GL_BOOL_VEC4
const enum_value<
	GLenum,
	GL_BOOL_VEC4,
	mp_list<oglplus::sl_data_type>
> enum_value::bool_vec4;
#endif

#ifdef GL_BOUNDING_BOX_NV
const enum_value<
	GLenum,
	GL_BOUNDING_BOX_NV,
	mp_list<oglplus::path_stroke_cover_mode_nv,oglplus::path_fill_cover_mode_nv>
> enum_value::bounding_box_nv;
#endif

#ifdef GL_BOUNDING_BOX_OF_BOUNDING_BOXES_NV
const enum_value<
	GLenum,
	GL_BOUNDING_BOX_OF_BOUNDING_BOXES_NV,
	mp_list<oglplus::path_stroke_cover_mode_nv,oglplus::path_fill_cover_mode_nv>
> enum_value::bounding_box_of_bounding_boxes_nv;
#endif

#ifdef GL_BUFFER
const enum_value<
	GLenum,
	GL_BUFFER,
	mp_list<oglplus::object_type>
> enum_value::buffer;
#endif

#ifdef GL_BUFFER_ACCESS
const enum_value<
	GLenum,
	GL_BUFFER_ACCESS,
	mp_list<oglplus::buffer_parameter>
> enum_value::buffer_access;
#endif

#ifdef GL_BUFFER_ACCESS_FLAGS
const enum_value<
	GLenum,
	GL_BUFFER_ACCESS_FLAGS,
	mp_list<oglplus::buffer_parameter>
> enum_value::buffer_access_flags;
#endif

#ifdef GL_BUFFER_BINDING
const enum_value<
	GLenum,
	GL_BUFFER_BINDING,
	mp_list<oglplus::program_resource_property,oglplus::binding_query>
> enum_value::buffer_binding;
#endif

#ifdef GL_BUFFER_DATA_SIZE
const enum_value<
	GLenum,
	GL_BUFFER_DATA_SIZE,
	mp_list<oglplus::program_resource_property>
> enum_value::buffer_data_size;
#endif

#ifdef GL_BUFFER_IMMUTABLE_STORAGE
const enum_value<
	GLenum,
	GL_BUFFER_IMMUTABLE_STORAGE,
	mp_list<oglplus::buffer_parameter>
> enum_value::buffer_immutable_storage;
#endif

#ifdef GL_BUFFER_MAP_LENGTH
const enum_value<
	GLenum,
	GL_BUFFER_MAP_LENGTH,
	mp_list<oglplus::buffer_parameter>
> enum_value::buffer_map_length;
#endif

#ifdef GL_BUFFER_MAP_OFFSET
const enum_value<
	GLenum,
	GL_BUFFER_MAP_OFFSET,
	mp_list<oglplus::buffer_parameter>
> enum_value::buffer_map_offset;
#endif

#ifdef GL_BUFFER_MAPPED
const enum_value<
	GLenum,
	GL_BUFFER_MAPPED,
	mp_list<oglplus::buffer_parameter>
> enum_value::buffer_mapped;
#endif

#ifdef GL_BUFFER_SIZE
const enum_value<
	GLenum,
	GL_BUFFER_SIZE,
	mp_list<oglplus::buffer_parameter>
> enum_value::buffer_size;
#endif

#ifdef GL_BUFFER_STORAGE_FLAGS
const enum_value<
	GLenum,
	GL_BUFFER_STORAGE_FLAGS,
	mp_list<oglplus::buffer_parameter>
> enum_value::buffer_storage_flags;
#endif

#ifdef GL_BUFFER_UPDATE_BARRIER_BIT
const enum_value<
	GLbitfield,
	GL_BUFFER_UPDATE_BARRIER_BIT,
	mp_list<oglplus::memory_barrier_bits>
> enum_value::buffer_update_barrier_bit;
#endif

#ifdef GL_BUFFER_USAGE
const enum_value<
	GLenum,
	GL_BUFFER_USAGE,
	mp_list<oglplus::buffer_parameter>
> enum_value::buffer_usage;
#endif

#ifdef GL_BUFFER_VARIABLE
const enum_value<
	GLenum,
	GL_BUFFER_VARIABLE,
	mp_list<oglplus::program_interface>
> enum_value::buffer_variable;
#endif

#ifdef GL_BYTE
const enum_value<
	GLenum,
	GL_BYTE,
	mp_list<oglplus::pixel_data_type,oglplus::data_type>
> enum_value::byte_;
#endif

#ifdef GL_CCW
const enum_value<
	GLenum,
	GL_CCW,
	mp_list<oglplus::face_orientation>
> enum_value::ccw;
#endif

#ifdef GL_CIRCULAR_CCW_ARC_TO_NV
const enum_value<
	GLubyte,
	GL_CIRCULAR_CCW_ARC_TO_NV,
	mp_list<oglplus::path_command_nv>
> enum_value::circular_ccw_arc_to_nv;
#endif

#ifdef GL_CIRCULAR_CW_ARC_TO_NV
const enum_value<
	GLubyte,
	GL_CIRCULAR_CW_ARC_TO_NV,
	mp_list<oglplus::path_command_nv>
> enum_value::circular_cw_arc_to_nv;
#endif

#ifdef GL_CIRCULAR_TANGENT_ARC_TO_NV
const enum_value<
	GLubyte,
	GL_CIRCULAR_TANGENT_ARC_TO_NV,
	mp_list<oglplus::path_command_nv>
> enum_value::circular_tangent_arc_to_nv;
#endif

#ifdef GL_CLAMP_TO_BORDER
const enum_value<
	GLenum,
	GL_CLAMP_TO_BORDER,
	mp_list<oglplus::texture_wrap_mode>
> enum_value::clamp_to_border;
#endif

#ifdef GL_CLAMP_TO_EDGE
const enum_value<
	GLenum,
	GL_CLAMP_TO_EDGE,
	mp_list<oglplus::texture_wrap_mode>
> enum_value::clamp_to_edge;
#endif

#ifdef GL_CLEAR
const enum_value<
	GLenum,
	GL_CLEAR,
	mp_list<oglplus::color_logic_operation>
> enum_value::clear;
#endif

#ifdef GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT
const enum_value<
	GLbitfield,
	GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT,
	mp_list<oglplus::memory_barrier_bits>
> enum_value::client_mapped_buffer_barrier_bit;
#endif

#ifdef GL_CLIENT_STORAGE_BIT
const enum_value<
	GLbitfield,
	GL_CLIENT_STORAGE_BIT,
	mp_list<oglplus::buffer_storage_bits>
> enum_value::client_storage_bit;
#endif

#ifdef GL_CLIP_DISTANCE0
const enum_value<
	GLenum,
	GL_CLIP_DISTANCE0,
	mp_list<oglplus::indexed_value_base>
> enum_value::clip_distance0;
#endif

#ifdef GL_CLIPPING_INPUT_PRIMITIVES_ARB
const enum_value<
	GLenum,
	GL_CLIPPING_INPUT_PRIMITIVES_ARB,
	mp_list<oglplus::query_target>
> enum_value::clipping_input_primitives;
#endif

#ifdef GL_CLIPPING_OUTPUT_PRIMITIVES_ARB
const enum_value<
	GLenum,
	GL_CLIPPING_OUTPUT_PRIMITIVES_ARB,
	mp_list<oglplus::query_target>
> enum_value::clipping_output_primitives;
#endif

#ifdef GL_CLOSE_PATH_NV
const enum_value<
	GLubyte,
	GL_CLOSE_PATH_NV,
	mp_list<oglplus::path_command_nv>
> enum_value::close_path_nv;
#endif

#ifdef GL_COLOR
const enum_value<
	GLenum,
	GL_COLOR,
	mp_list<oglplus::framebuffer_buffer,oglplus::old_matrix_mode>
> enum_value::color;
#endif

#ifdef GL_COLOR_ATTACHMENT0
const enum_value<
	GLenum,
	GL_COLOR_ATTACHMENT0,
	mp_list<oglplus::indexed_value_base>
> enum_value::color_attachment0;
#endif

#ifdef GL_COLOR_BUFFER_BIT
const enum_value<
	GLbitfield,
	GL_COLOR_BUFFER_BIT,
	mp_list<oglplus::buffer_select_bits>
> enum_value::color_buffer_bit;
#endif

#ifdef GL_COLOR_CLEAR_VALUE
const enum_value<
	GLenum,
	GL_COLOR_CLEAR_VALUE,
	mp_list<oglplus::numeric_query>
> enum_value::color_clear_value;
#endif

#ifdef GL_COLOR_LOGIC_OP
const enum_value<
	GLenum,
	GL_COLOR_LOGIC_OP,
	mp_list<oglplus::capability>
> enum_value::color_logic_op;
#endif

#ifdef GL_COLOR_WRITEMASK
const enum_value<
	GLenum,
	GL_COLOR_WRITEMASK,
	mp_list<oglplus::numeric_query>
> enum_value::color_writemask;
#endif

#ifdef GL_COLORBURN_KHR
const enum_value<
	GLenum,
	GL_COLORBURN_KHR,
	mp_list<oglplus::blend_equation_advanced>
> enum_value::colorburn_khr;
#endif

#ifdef GL_COLORDODGE_KHR
const enum_value<
	GLenum,
	GL_COLORDODGE_KHR,
	mp_list<oglplus::blend_equation_advanced>
> enum_value::colordodge_khr;
#endif

#ifdef GL_COMMAND_BARRIER_BIT
const enum_value<
	GLbitfield,
	GL_COMMAND_BARRIER_BIT,
	mp_list<oglplus::memory_barrier_bits>
> enum_value::command_barrier_bit;
#endif

#ifdef GL_COMPARE_REF_TO_TEXTURE
const enum_value<
	GLenum,
	GL_COMPARE_REF_TO_TEXTURE,
	mp_list<oglplus::texture_compare_mode>
> enum_value::compare_ref_to_texture;
#endif

#ifdef GL_COMPATIBLE_SUBROUTINES
const enum_value<
	GLenum,
	GL_COMPATIBLE_SUBROUTINES,
	mp_list<oglplus::program_resource_property>
> enum_value::compatible_subroutines;
#endif

#ifdef GL_COMPILE_STATUS
const enum_value<
	GLenum,
	GL_COMPILE_STATUS,
	mp_list<oglplus::shader_parameter>
> enum_value::compile_status;
#endif

#ifdef GL_COMPRESSED_R11_EAC
const enum_value<
	GLenum,
	GL_COMPRESSED_R11_EAC,
	mp_list<oglplus::pixel_data_internal_format>
> enum_value::compressed_r11_eac;
#endif

#ifdef GL_COMPRESSED_RED
const enum_value<
	GLenum,
	GL_COMPRESSED_RED,
	mp_list<oglplus::pixel_data_internal_format>
> enum_value::compressed_red;
#endif

#ifdef GL_COMPRESSED_RED_RGTC1
const enum_value<
	GLenum,
	GL_COMPRESSED_RED_RGTC1,
	mp_list<oglplus::pixel_data_internal_format>
> enum_value::compressed_red_rgtc1;
#endif

#ifdef GL_COMPRESSED_RG
const enum_value<
	GLenum,
	GL_COMPRESSED_RG,
	mp_list<oglplus::pixel_data_internal_format>
> enum_value::compressed_rg;
#endif

#ifdef GL_COMPRESSED_RG11_EAC
const enum_value<
	GLenum,
	GL_COMPRESSED_RG11_EAC,
	mp_list<oglplus::pixel_data_internal_format>
> enum_value::compressed_rg11_eac;
#endif

#ifdef GL_COMPRESSED_RG_RGTC2
const enum_value<
	GLenum,
	GL_COMPRESSED_RG_RGTC2,
	mp_list<oglplus::pixel_data_internal_format>
> enum_value::compressed_rg_rgtc2;
#endif

#ifdef GL_COMPRESSED_RGB
const enum_value<
	GLenum,
	GL_COMPRESSED_RGB,
	mp_list<oglplus::pixel_data_internal_format>
> enum_value::compressed_rgb;
#endif

#ifdef GL_COMPRESSED_RGB8_ETC2
const enum_value<
	GLenum,
	GL_COMPRESSED_RGB8_ETC2,
	mp_list<oglplus::pixel_data_internal_format>
> enum_value::compressed_rgb8_etc2;
#endif

#ifdef GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2
const enum_value<
	GLenum,
	GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2,
	mp_list<oglplus::pixel_data_internal_format>
> enum_value::compressed_rgb8_punchthrough_alpha1_etc2;
#endif

#ifdef GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT
const enum_value<
	GLenum,
	GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT,
	mp_list<oglplus::pixel_data_internal_format>
> enum_value::compressed_rgb_bptc_signed_float;
#endif

#ifdef GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT
const enum_value<
	GLenum,
	GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT,
	mp_list<oglplus::pixel_data_internal_format>
> enum_value::compressed_rgb_bptc_unsigned_float;
#endif

#ifdef GL_COMPRESSED_RGBA
const enum_value<
	GLenum,
	GL_COMPRESSED_RGBA,
	mp_list<oglplus::pixel_data_internal_format>
> enum_value::compressed_rgba;
#endif

#ifdef GL_COMPRESSED_RGBA8_ETC2_EAC
const enum_value<
	GLenum,
	GL_COMPRESSED_RGBA8_ETC2_EAC,
	mp_list<oglplus::pixel_data_internal_format>
> enum_value::compressed_rgba8_etc2_eac;
#endif

#ifdef GL_COMPRESSED_RGBA_BPTC_UNORM
const enum_value<
	GLenum,
	GL_COMPRESSED_RGBA_BPTC_UNORM,
	mp_list<oglplus::pixel_data_internal_format>
> enum_value::compressed_rgba_bptc_unorm;
#endif

#ifdef GL_COMPRESSED_SIGNED_R11_EAC
const enum_value<
	GLenum,
	GL_COMPRESSED_SIGNED_R11_EAC,
	mp_list<oglplus::pixel_data_internal_format>
> enum_value::compressed_signed_r11_eac;
#endif

#ifdef GL_COMPRESSED_SIGNED_RED_RGTC1
const enum_value<
	GLenum,
	GL_COMPRESSED_SIGNED_RED_RGTC1,
	mp_list<oglplus::pixel_data_internal_format>
> enum_value::compressed_signed_red_rgtc1;
#endif

#ifdef GL_COMPRESSED_SIGNED_RG11_EAC
const enum_value<
	GLenum,
	GL_COMPRESSED_SIGNED_RG11_EAC,
	mp_list<oglplus::pixel_data_internal_format>
> enum_value::compressed_signed_rg11_eac;
#endif

#ifdef GL_COMPRESSED_SIGNED_RG_RGTC2
const enum_value<
	GLenum,
	GL_COMPRESSED_SIGNED_RG_RGTC2,
	mp_list<oglplus::pixel_data_internal_format>
> enum_value::compressed_signed_rg_rgtc2;
#endif

#ifdef GL_COMPRESSED_SRGB
const enum_value<
	GLenum,
	GL_COMPRESSED_SRGB,
	mp_list<oglplus::pixel_data_internal_format>
> enum_value::compressed_srgb;
#endif

#ifdef GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC
const enum_value<
	GLenum,
	GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC,
	mp_list<oglplus::pixel_data_internal_format>
> enum_value::compressed_srgb8_alpha8_etc2_eac;
#endif

#ifdef GL_COMPRESSED_SRGB8_ETC2
const enum_value<
	GLenum,
	GL_COMPRESSED_SRGB8_ETC2,
	mp_list<oglplus::pixel_data_internal_format>
> enum_value::compressed_srgb8_etc2;
#endif

#ifdef GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2
const enum_value<
	GLenum,
	GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2,
	mp_list<oglplus::pixel_data_internal_format>
> enum_value::compressed_srgb8_punchthrough_alpha1_etc2;
#endif

#ifdef GL_COMPRESSED_SRGB_ALPHA
const enum_value<
	GLenum,
	GL_COMPRESSED_SRGB_ALPHA,
	mp_list<oglplus::pixel_data_internal_format>
> enum_value::compressed_srgb_alpha;
#endif

#ifdef GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM
const enum_value<
	GLenum,
	GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM,
	mp_list<oglplus::pixel_data_internal_format>
> enum_value::compressed_srgb_alpha_bptc_unorm;
#endif

#ifdef GL_COMPRESSED_TEXTURE_FORMATS
const enum_value<
	GLenum,
	GL_COMPRESSED_TEXTURE_FORMATS,
	mp_list<oglplus::numeric_query>
> enum_value::compressed_texture_formats;
#endif

#ifdef GL_COMPUTE_SHADER
const enum_value<
	GLenum,
	GL_COMPUTE_SHADER,
	mp_list<oglplus::shader_type>
> enum_value::compute_shader;
#endif

#ifdef GL_COMPUTE_SHADER_BIT
const enum_value<
	GLbitfield,
	GL_COMPUTE_SHADER_BIT,
	mp_list<oglplus::program_pipeline_stage>
> enum_value::compute_shader_bit;
#endif

#ifdef GL_COMPUTE_SHADER_INVOCATIONS_ARB
const enum_value<
	GLenum,
	GL_COMPUTE_SHADER_INVOCATIONS_ARB,
	mp_list<oglplus::query_target>
> enum_value::compute_shader_invocations;
#endif

#ifdef GL_COMPUTE_SUBROUTINE
const enum_value<
	GLenum,
	GL_COMPUTE_SUBROUTINE,
	mp_list<oglplus::program_interface>
> enum_value::compute_subroutine;
#endif

#ifdef GL_COMPUTE_SUBROUTINE_UNIFORM
const enum_value<
	GLenum,
	GL_COMPUTE_SUBROUTINE_UNIFORM,
	mp_list<oglplus::program_interface>
> enum_value::compute_subroutine_uniform;
#endif

#ifdef GL_CONDITION_SATISFIED
const enum_value<
	GLenum,
	GL_CONDITION_SATISFIED,
	mp_list<oglplus::sync_wait_result>
> enum_value::condition_satisfied;
#endif

#ifdef GL_CONSTANT_ALPHA
const enum_value<
	GLenum,
	GL_CONSTANT_ALPHA,
	mp_list<oglplus::blend_function>
> enum_value::constant_alpha;
#endif

#ifdef GL_CONSTANT_COLOR
const enum_value<
	GLenum,
	GL_CONSTANT_COLOR,
	mp_list<oglplus::blend_function>
> enum_value::constant_color;
#endif

#ifdef GL_CONTEXT_COMPATIBILITY_PROFILE_BIT
const enum_value<
	GLbitfield,
	GL_CONTEXT_COMPATIBILITY_PROFILE_BIT,
	mp_list<oglplus::context_profile_bits>
> enum_value::context_compatibility_profile_bit;
#endif

#ifdef GL_CONTEXT_CORE_PROFILE_BIT
const enum_value<
	GLbitfield,
	GL_CONTEXT_CORE_PROFILE_BIT,
	mp_list<oglplus::context_profile_bits>
> enum_value::context_core_profile_bit;
#endif

#ifdef GL_CONTEXT_FLAG_DEBUG_BIT
const enum_value<
	GLbitfield,
	GL_CONTEXT_FLAG_DEBUG_BIT,
	mp_list<oglplus::context_flag_bits>
> enum_value::context_flag_debug_bit;
#endif

#ifdef GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT
const enum_value<
	GLbitfield,
	GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT,
	mp_list<oglplus::context_flag_bits>
> enum_value::context_flag_forward_compatible_bit;
#endif

#ifdef GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT_ARB
const enum_value<
	GLbitfield,
	GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT_ARB,
	mp_list<oglplus::context_flag_bits>
> enum_value::context_flag_robust_access_bit;
#endif

#ifdef GL_CONTEXT_FLAGS
const enum_value<
	GLenum,
	GL_CONTEXT_FLAGS,
	mp_list<oglplus::numeric_query>
> enum_value::context_flags;
#endif

#ifdef GL_CONTEXT_LOST
const enum_value<
	GLenum,
	GL_CONTEXT_LOST,
	mp_list<oglplus::error_code>
> enum_value::context_lost;
#endif

#ifdef GL_CONTEXT_RELEASE_BEHAVIOR_FLUSH
const enum_value<
	GLenum,
	GL_CONTEXT_RELEASE_BEHAVIOR_FLUSH,
	mp_list<oglplus::context_release_behavior>
> enum_value::context_release_behavior_flush;
#endif

#ifdef GL_CONVEX_HULL_NV
const enum_value<
	GLenum,
	GL_CONVEX_HULL_NV,
	mp_list<oglplus::path_stroke_cover_mode_nv,oglplus::path_fill_cover_mode_nv>
> enum_value::convex_hull_nv;
#endif

#ifdef GL_COPY
const enum_value<
	GLenum,
	GL_COPY,
	mp_list<oglplus::color_logic_operation>
> enum_value::copy;
#endif

#ifdef GL_COPY_INVERTED
const enum_value<
	GLenum,
	GL_COPY_INVERTED,
	mp_list<oglplus::color_logic_operation>
> enum_value::copy_inverted;
#endif

#ifdef GL_COPY_READ_BUFFER
const enum_value<
	GLenum,
	GL_COPY_READ_BUFFER,
	mp_list<oglplus::buffer_target>
> enum_value::copy_read_buffer;
#endif

#ifdef GL_COPY_READ_BUFFER_BINDING
const enum_value<
	GLenum,
	GL_COPY_READ_BUFFER_BINDING,
	mp_list<oglplus::binding_query>
> enum_value::copy_read_buffer_binding;
#endif

#ifdef GL_COPY_WRITE_BUFFER
const enum_value<
	GLenum,
	GL_COPY_WRITE_BUFFER,
	mp_list<oglplus::buffer_target>
> enum_value::copy_write_buffer;
#endif

#ifdef GL_COPY_WRITE_BUFFER_BINDING
const enum_value<
	GLenum,
	GL_COPY_WRITE_BUFFER_BINDING,
	mp_list<oglplus::binding_query>
> enum_value::copy_write_buffer_binding;
#endif

#ifdef GL_COUNT_DOWN_NV
const enum_value<
	GLenum,
	GL_COUNT_DOWN_NV,
	mp_list<oglplus::path_fill_mode_nv>
> enum_value::count_down_nv;
#endif

#ifdef GL_COUNT_UP_NV
const enum_value<
	GLenum,
	GL_COUNT_UP_NV,
	mp_list<oglplus::path_fill_mode_nv>
> enum_value::count_up_nv;
#endif

#ifdef GL_CUBIC_CURVE_TO_NV
const enum_value<
	GLubyte,
	GL_CUBIC_CURVE_TO_NV,
	mp_list<oglplus::path_command_nv>
> enum_value::cubic_curve_to_nv;
#endif

#ifdef GL_CULL_FACE
const enum_value<
	GLenum,
	GL_CULL_FACE,
	mp_list<oglplus::capability>
> enum_value::cull_face;
#endif

#ifdef GL_CURRENT_PROGRAM
const enum_value<
	GLenum,
	GL_CURRENT_PROGRAM,
	mp_list<oglplus::binding_query>
> enum_value::current_program;
#endif

#ifdef GL_CW
const enum_value<
	GLenum,
	GL_CW,
	mp_list<oglplus::face_orientation>
> enum_value::cw;
#endif

#ifdef GL_DARKEN_KHR
const enum_value<
	GLenum,
	GL_DARKEN_KHR,
	mp_list<oglplus::blend_equation_advanced>
> enum_value::darken_khr;
#endif

#ifdef GL_DEBUG_GROUP_STACK_DEPTH
const enum_value<
	GLenum,
	GL_DEBUG_GROUP_STACK_DEPTH,
	mp_list<oglplus::numeric_query>
> enum_value::debug_group_stack_depth;
#endif

#ifdef GL_DEBUG_OUTPUT_SYNCHRONOUS
const enum_value<
	GLenum,
	GL_DEBUG_OUTPUT_SYNCHRONOUS,
	mp_list<oglplus::capability>
> enum_value::debug_output_synchronous;
#endif

#ifdef GL_DEBUG_SEVERITY_HIGH
const enum_value<
	GLenum,
	GL_DEBUG_SEVERITY_HIGH,
	mp_list<oglplus::debug_output_severity>
> enum_value::debug_severity_high;
#endif

#ifdef GL_DEBUG_SEVERITY_LOW
const enum_value<
	GLenum,
	GL_DEBUG_SEVERITY_LOW,
	mp_list<oglplus::debug_output_severity>
> enum_value::debug_severity_low;
#endif

#ifdef GL_DEBUG_SEVERITY_MEDIUM
const enum_value<
	GLenum,
	GL_DEBUG_SEVERITY_MEDIUM,
	mp_list<oglplus::debug_output_severity>
> enum_value::debug_severity_medium;
#endif

#ifdef GL_DEBUG_SEVERITY_NOTIFICATION
const enum_value<
	GLenum,
	GL_DEBUG_SEVERITY_NOTIFICATION,
	mp_list<oglplus::debug_output_severity>
> enum_value::debug_severity_notification;
#endif

#ifdef GL_DEBUG_SOURCE_API
const enum_value<
	GLenum,
	GL_DEBUG_SOURCE_API,
	mp_list<oglplus::debug_output_source>
> enum_value::debug_source_api;
#endif

#ifdef GL_DEBUG_SOURCE_APPLICATION
const enum_value<
	GLenum,
	GL_DEBUG_SOURCE_APPLICATION,
	mp_list<oglplus::debug_output_source>
> enum_value::debug_source_application;
#endif

#ifdef GL_DEBUG_SOURCE_OTHER
const enum_value<
	GLenum,
	GL_DEBUG_SOURCE_OTHER,
	mp_list<oglplus::debug_output_source>
> enum_value::debug_source_other;
#endif

#ifdef GL_DEBUG_SOURCE_SHADER_COMPILER
const enum_value<
	GLenum,
	GL_DEBUG_SOURCE_SHADER_COMPILER,
	mp_list<oglplus::debug_output_source>
> enum_value::debug_source_shader_compiler;
#endif

#ifdef GL_DEBUG_SOURCE_THIRD_PARTY
const enum_value<
	GLenum,
	GL_DEBUG_SOURCE_THIRD_PARTY,
	mp_list<oglplus::debug_output_source>
> enum_value::debug_source_third_party;
#endif

#ifdef GL_DEBUG_SOURCE_WINDOW_SYSTEM
const enum_value<
	GLenum,
	GL_DEBUG_SOURCE_WINDOW_SYSTEM,
	mp_list<oglplus::debug_output_source>
> enum_value::debug_source_window_system;
#endif

#ifdef GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR
const enum_value<
	GLenum,
	GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR,
	mp_list<oglplus::debug_output_type>
> enum_value::debug_type_deprecated_behavior;
#endif

#ifdef GL_DEBUG_TYPE_ERROR
const enum_value<
	GLenum,
	GL_DEBUG_TYPE_ERROR,
	mp_list<oglplus::debug_output_type>
> enum_value::debug_type_error;
#endif

#ifdef GL_DEBUG_TYPE_MARKER
const enum_value<
	GLenum,
	GL_DEBUG_TYPE_MARKER,
	mp_list<oglplus::debug_output_type>
> enum_value::debug_type_marker;
#endif

#ifdef GL_DEBUG_TYPE_OTHER
const enum_value<
	GLenum,
	GL_DEBUG_TYPE_OTHER,
	mp_list<oglplus::debug_output_type>
> enum_value::debug_type_other;
#endif

#ifdef GL_DEBUG_TYPE_PERFORMANCE
const enum_value<
	GLenum,
	GL_DEBUG_TYPE_PERFORMANCE,
	mp_list<oglplus::debug_output_type>
> enum_value::debug_type_performance;
#endif

#ifdef GL_DEBUG_TYPE_POP_GROUP
const enum_value<
	GLenum,
	GL_DEBUG_TYPE_POP_GROUP,
	mp_list<oglplus::debug_output_type>
> enum_value::debug_type_pop_group;
#endif

#ifdef GL_DEBUG_TYPE_PORTABILITY
const enum_value<
	GLenum,
	GL_DEBUG_TYPE_PORTABILITY,
	mp_list<oglplus::debug_output_type>
> enum_value::debug_type_portability;
#endif

#ifdef GL_DEBUG_TYPE_PUSH_GROUP
const enum_value<
	GLenum,
	GL_DEBUG_TYPE_PUSH_GROUP,
	mp_list<oglplus::debug_output_type>
> enum_value::debug_type_push_group;
#endif

#ifdef GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR
const enum_value<
	GLenum,
	GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR,
	mp_list<oglplus::debug_output_type>
> enum_value::debug_type_undefined_behavior;
#endif

#ifdef GL_DECR
const enum_value<
	GLenum,
	GL_DECR,
	mp_list<oglplus::stencil_operation>
> enum_value::decr;
#endif

#ifdef GL_DECR_WRAP
const enum_value<
	GLenum,
	GL_DECR_WRAP,
	mp_list<oglplus::stencil_operation>
> enum_value::decr_wrap;
#endif

#ifdef GL_DELETE_STATUS
const enum_value<
	GLenum,
	GL_DELETE_STATUS,
	mp_list<oglplus::program_parameter,oglplus::shader_parameter>
> enum_value::delete_status;
#endif

#ifdef GL_DEPTH
const enum_value<
	GLenum,
	GL_DEPTH,
	mp_list<oglplus::framebuffer_buffer>
> enum_value::depth;
#endif

#ifdef GL_DEPTH24_STENCIL8
const enum_value<
	GLenum,
	GL_DEPTH24_STENCIL8,
	mp_list<oglplus::pixel_data_internal_format>
> enum_value::depth24_stencil8;
#endif

#ifdef GL_DEPTH32F_STENCIL8
const enum_value<
	GLenum,
	GL_DEPTH32F_STENCIL8,
	mp_list<oglplus::pixel_data_internal_format>
> enum_value::depth32f_stencil8;
#endif

#ifdef GL_DEPTH_ATTACHMENT
const enum_value<
	GLenum,
	GL_DEPTH_ATTACHMENT,
	mp_list<oglplus::framebuffer_other_attachment>
> enum_value::depth_attachment;
#endif

#ifdef GL_DEPTH_BUFFER_BIT
const enum_value<
	GLbitfield,
	GL_DEPTH_BUFFER_BIT,
	mp_list<oglplus::buffer_select_bits>
> enum_value::depth_buffer_bit;
#endif

#ifdef GL_DEPTH_CLEAR_VALUE
const enum_value<
	GLenum,
	GL_DEPTH_CLEAR_VALUE,
	mp_list<oglplus::numeric_query>
> enum_value::depth_clear_value;
#endif

#ifdef GL_DEPTH_COMPONENT
const enum_value<
	GLenum,
	GL_DEPTH_COMPONENT,
	mp_list<oglplus::pixel_data_format,oglplus::pixel_data_internal_format>
> enum_value::depth_component;
#endif

#ifdef GL_DEPTH_COMPONENT16
const enum_value<
	GLenum,
	GL_DEPTH_COMPONENT16,
	mp_list<oglplus::pixel_data_internal_format>
> enum_value::depth_component16;
#endif

#ifdef GL_DEPTH_COMPONENT24
const enum_value<
	GLenum,
	GL_DEPTH_COMPONENT24,
	mp_list<oglplus::pixel_data_internal_format>
> enum_value::depth_component24;
#endif

#ifdef GL_DEPTH_COMPONENT32
const enum_value<
	GLenum,
	GL_DEPTH_COMPONENT32,
	mp_list<oglplus::pixel_data_internal_format>
> enum_value::depth_component32;
#endif

#ifdef GL_DEPTH_COMPONENT32F
const enum_value<
	GLenum,
	GL_DEPTH_COMPONENT32F,
	mp_list<oglplus::pixel_data_internal_format>
> enum_value::depth_component32f;
#endif

#ifdef GL_DEPTH_FUNC
const enum_value<
	GLenum,
	GL_DEPTH_FUNC,
	mp_list<oglplus::numeric_query>
> enum_value::depth_func;
#endif

#ifdef GL_DEPTH_RANGE
const enum_value<
	GLenum,
	GL_DEPTH_RANGE,
	mp_list<oglplus::numeric_query>
> enum_value::depth_range;
#endif

#ifdef GL_DEPTH_STENCIL
const enum_value<
	GLenum,
	GL_DEPTH_STENCIL,
	mp_list<oglplus::framebuffer_buffer,oglplus::pixel_data_format,oglplus::pixel_data_internal_format>
> enum_value::depth_stencil;
#endif

#ifdef GL_DEPTH_STENCIL_ATTACHMENT
const enum_value<
	GLenum,
	GL_DEPTH_STENCIL_ATTACHMENT,
	mp_list<oglplus::framebuffer_other_attachment>
> enum_value::depth_stencil_attachment;
#endif

#ifdef GL_DEPTH_STENCIL_TEXTURE_MODE
const enum_value<
	GLenum,
	GL_DEPTH_STENCIL_TEXTURE_MODE,
	mp_list<oglplus::texture_parameter>
> enum_value::depth_stencil_texture_mode;
#endif

#ifdef GL_DEPTH_TEST
const enum_value<
	GLenum,
	GL_DEPTH_TEST,
	mp_list<oglplus::capability>
> enum_value::depth_test;
#endif

#ifdef GL_DEPTH_WRITEMASK
const enum_value<
	GLenum,
	GL_DEPTH_WRITEMASK,
	mp_list<oglplus::numeric_query>
> enum_value::depth_writemask;
#endif

#ifdef GL_DIFFERENCE_KHR
const enum_value<
	GLenum,
	GL_DIFFERENCE_KHR,
	mp_list<oglplus::blend_equation_advanced>
> enum_value::difference_khr;
#endif

#ifdef GL_DISPATCH_INDIRECT_BUFFER
const enum_value<
	GLenum,
	GL_DISPATCH_INDIRECT_BUFFER,
	mp_list<oglplus::buffer_target>
> enum_value::dispatch_indirect_buffer;
#endif

#ifdef GL_DISPATCH_INDIRECT_BUFFER_BINDING
const enum_value<
	GLenum,
	GL_DISPATCH_INDIRECT_BUFFER_BINDING,
	mp_list<oglplus::binding_query>
> enum_value::dispatch_indirect_buffer_binding;
#endif

#ifdef GL_DITHER
const enum_value<
	GLenum,
	GL_DITHER,
	mp_list<oglplus::capability>
> enum_value::dither;
#endif

#ifdef GL_DONT_CARE
const enum_value<
	GLenum,
	GL_DONT_CARE,
	mp_list<oglplus::debug_output_source,oglplus::debug_output_type,oglplus::hint_option,oglplus::debug_output_severity>
> enum_value::dont_care;
#endif

#ifdef GL_DOUBLE
const enum_value<
	GLenum,
	GL_DOUBLE,
	mp_list<oglplus::sl_data_type,oglplus::pixel_data_type,oglplus::data_type>
> enum_value::double_;
#endif

#ifdef GL_DOUBLE_MAT2
const enum_value<
	GLenum,
	GL_DOUBLE_MAT2,
	mp_list<oglplus::sl_data_type>
> enum_value::double_mat2;
#endif

#ifdef GL_DOUBLE_MAT2x3
const enum_value<
	GLenum,
	GL_DOUBLE_MAT2x3,
	mp_list<oglplus::sl_data_type>
> enum_value::double_mat2x3;
#endif

#ifdef GL_DOUBLE_MAT2x4
const enum_value<
	GLenum,
	GL_DOUBLE_MAT2x4,
	mp_list<oglplus::sl_data_type>
> enum_value::double_mat2x4;
#endif

#ifdef GL_DOUBLE_MAT3
const enum_value<
	GLenum,
	GL_DOUBLE_MAT3,
	mp_list<oglplus::sl_data_type>
> enum_value::double_mat3;
#endif

#ifdef GL_DOUBLE_MAT3x2
const enum_value<
	GLenum,
	GL_DOUBLE_MAT3x2,
	mp_list<oglplus::sl_data_type>
> enum_value::double_mat3x2;
#endif

#ifdef GL_DOUBLE_MAT3x4
const enum_value<
	GLenum,
	GL_DOUBLE_MAT3x4,
	mp_list<oglplus::sl_data_type>
> enum_value::double_mat3x4;
#endif

#ifdef GL_DOUBLE_MAT4
const enum_value<
	GLenum,
	GL_DOUBLE_MAT4,
	mp_list<oglplus::sl_data_type>
> enum_value::double_mat4;
#endif

#ifdef GL_DOUBLE_MAT4x2
const enum_value<
	GLenum,
	GL_DOUBLE_MAT4x2,
	mp_list<oglplus::sl_data_type>
> enum_value::double_mat4x2;
#endif

#ifdef GL_DOUBLE_MAT4x3
const enum_value<
	GLenum,
	GL_DOUBLE_MAT4x3,
	mp_list<oglplus::sl_data_type>
> enum_value::double_mat4x3;
#endif

#ifdef GL_DOUBLE_VEC2
const enum_value<
	GLenum,
	GL_DOUBLE_VEC2,
	mp_list<oglplus::sl_data_type>
> enum_value::double_vec2;
#endif

#ifdef GL_DOUBLE_VEC3
const enum_value<
	GLenum,
	GL_DOUBLE_VEC3,
	mp_list<oglplus::sl_data_type>
> enum_value::double_vec3;
#endif

#ifdef GL_DOUBLE_VEC4
const enum_value<
	GLenum,
	GL_DOUBLE_VEC4,
	mp_list<oglplus::sl_data_type>
> enum_value::double_vec4;
#endif

#ifdef GL_DOUBLEBUFFER
const enum_value<
	GLenum,
	GL_DOUBLEBUFFER,
	mp_list<oglplus::numeric_query>
> enum_value::doublebuffer;
#endif

#ifdef GL_DRAW_BUFFER
const enum_value<
	GLenum,
	GL_DRAW_BUFFER,
	mp_list<oglplus::numeric_query>
> enum_value::draw_buffer;
#endif

#ifdef GL_DRAW_BUFFER0
const enum_value<
	GLenum,
	GL_DRAW_BUFFER0,
	mp_list<oglplus::indexed_value_base>
> enum_value::draw_buffer0;
#endif

#ifdef GL_DRAW_FRAMEBUFFER
const enum_value<
	GLenum,
	GL_DRAW_FRAMEBUFFER,
	mp_list<oglplus::framebuffer_target>
> enum_value::draw_framebuffer;
#endif

#ifdef GL_DRAW_FRAMEBUFFER_BINDING
const enum_value<
	GLenum,
	GL_DRAW_FRAMEBUFFER_BINDING,
	mp_list<oglplus::binding_query>
> enum_value::draw_framebuffer_binding;
#endif

#ifdef GL_DRAW_INDIRECT_BUFFER
const enum_value<
	GLenum,
	GL_DRAW_INDIRECT_BUFFER,
	mp_list<oglplus::buffer_target>
> enum_value::draw_indirect_buffer;
#endif

#ifdef GL_DRAW_INDIRECT_BUFFER_BINDING
const enum_value<
	GLenum,
	GL_DRAW_INDIRECT_BUFFER_BINDING,
	mp_list<oglplus::binding_query>
> enum_value::draw_indirect_buffer_binding;
#endif

#ifdef GL_DST_ALPHA
const enum_value<
	GLenum,
	GL_DST_ALPHA,
	mp_list<oglplus::blend_function>
> enum_value::dst_alpha;
#endif

#ifdef GL_DST_COLOR
const enum_value<
	GLenum,
	GL_DST_COLOR,
	mp_list<oglplus::blend_function>
> enum_value::dst_color;
#endif

#ifdef GL_DUP_FIRST_CUBIC_CURVE_TO_NV
const enum_value<
	GLubyte,
	GL_DUP_FIRST_CUBIC_CURVE_TO_NV,
	mp_list<oglplus::path_command_nv>
> enum_value::dup_first_cubic_curve_to_nv;
#endif

#ifdef GL_DUP_LAST_CUBIC_CURVE_TO_NV
const enum_value<
	GLubyte,
	GL_DUP_LAST_CUBIC_CURVE_TO_NV,
	mp_list<oglplus::path_command_nv>
> enum_value::dup_last_cubic_curve_to_nv;
#endif

#ifdef GL_DYNAMIC_COPY
const enum_value<
	GLenum,
	GL_DYNAMIC_COPY,
	mp_list<oglplus::buffer_usage>
> enum_value::dynamic_copy;
#endif

#ifdef GL_DYNAMIC_DRAW
const enum_value<
	GLenum,
	GL_DYNAMIC_DRAW,
	mp_list<oglplus::buffer_usage>
> enum_value::dynamic_draw;
#endif

#ifdef GL_DYNAMIC_READ
const enum_value<
	GLenum,
	GL_DYNAMIC_READ,
	mp_list<oglplus::buffer_usage>
> enum_value::dynamic_read;
#endif

#ifdef GL_DYNAMIC_STORAGE_BIT
const enum_value<
	GLbitfield,
	GL_DYNAMIC_STORAGE_BIT,
	mp_list<oglplus::buffer_storage_bits>
> enum_value::dynamic_storage_bit;
#endif

#ifdef GL_ELEMENT_ARRAY_BARRIER_BIT
const enum_value<
	GLbitfield,
	GL_ELEMENT_ARRAY_BARRIER_BIT,
	mp_list<oglplus::memory_barrier_bits>
> enum_value::element_array_barrier_bit;
#endif

#ifdef GL_ELEMENT_ARRAY_BUFFER
const enum_value<
	GLenum,
	GL_ELEMENT_ARRAY_BUFFER,
	mp_list<oglplus::buffer_target>
> enum_value::element_array_buffer;
#endif

#ifdef GL_ELEMENT_ARRAY_BUFFER_BINDING
const enum_value<
	GLenum,
	GL_ELEMENT_ARRAY_BUFFER_BINDING,
	mp_list<oglplus::binding_query>
> enum_value::element_array_buffer_binding;
#endif

#ifdef GL_EQUAL
const enum_value<
	GLenum,
	GL_EQUAL,
	mp_list<oglplus::compare_function,oglplus::tess_gen_primitive_spacing>
> enum_value::equal;
#endif

#ifdef GL_EQUIV
const enum_value<
	GLenum,
	GL_EQUIV,
	mp_list<oglplus::color_logic_operation>
> enum_value::equiv;
#endif

#ifdef GL_EXCLUSION_KHR
const enum_value<
	GLenum,
	GL_EXCLUSION_KHR,
	mp_list<oglplus::blend_equation_advanced>
> enum_value::exclusion_khr;
#endif

#ifdef GL_EXTERNAL_VIRTUAL_MEMORY_BUFFER_AMD
const enum_value<
	GLenum,
	GL_EXTERNAL_VIRTUAL_MEMORY_BUFFER_AMD,
	mp_list<oglplus::buffer_target>
> enum_value::external_virtual_memory_buffer;
#endif

#ifdef GL_EYE_LINEAR
const enum_value<
	GLenum,
	GL_EYE_LINEAR,
	mp_list<oglplus::path_gen_mode_nv>
> enum_value::eye_linear;
#endif

#ifdef GL_FALSE
const enum_value<
	GLboolean,
	GL_FALSE,
	mp_list<oglplus::true_false>
> enum_value::false_;
#endif

#ifdef GL_FASTEST
const enum_value<
	GLenum,
	GL_FASTEST,
	mp_list<oglplus::hint_option>
> enum_value::fastest;
#endif

#ifdef GL_FILE_NAME_NV
const enum_value<
	GLenum,
	GL_FILE_NAME_NV,
	mp_list<oglplus::path_font_target_nv>
> enum_value::file_name_nv;
#endif

#ifdef GL_FILL
const enum_value<
	GLenum,
	GL_FILL,
	mp_list<oglplus::polygon_mode>
> enum_value::fill;
#endif

#ifdef GL_FILL_RECTANGLE_NV
const enum_value<
	GLenum,
	GL_FILL_RECTANGLE_NV,
	mp_list<oglplus::polygon_mode>
> enum_value::fill_rectangle;
#endif

#ifdef GL_FIRST_TO_REST_NV
const enum_value<
	GLenum,
	GL_FIRST_TO_REST_NV,
	mp_list<oglplus::path_list_mode_nv>
> enum_value::first_to_rest_nv;
#endif

#ifdef GL_FIRST_VERTEX_CONVENTION
const enum_value<
	GLenum,
	GL_FIRST_VERTEX_CONVENTION,
	mp_list<oglplus::provoke_mode>
> enum_value::first_vertex_convention;
#endif

#ifdef GL_FIXED
const enum_value<
	GLenum,
	GL_FIXED,
	mp_list<oglplus::data_type>
> enum_value::fixed;
#endif

#ifdef GL_FLAT
const enum_value<
	GLenum,
	GL_FLAT,
	mp_list<oglplus::path_cap_style_nv>
> enum_value::flat;
#endif

#ifdef GL_FLOAT
const enum_value<
	GLenum,
	GL_FLOAT,
	mp_list<oglplus::sl_data_type,oglplus::pixel_data_type,oglplus::data_type>
> enum_value::float_;
#endif

#ifdef GL_FLOAT_32_UNSIGNED_INT_24_8_REV
const enum_value<
	GLenum,
	GL_FLOAT_32_UNSIGNED_INT_24_8_REV,
	mp_list<oglplus::pixel_data_type>
> enum_value::float_32_unsigned_int_24_8_rev;
#endif

#ifdef GL_FLOAT_MAT2
const enum_value<
	GLenum,
	GL_FLOAT_MAT2,
	mp_list<oglplus::sl_data_type>
> enum_value::float_mat2;
#endif

#ifdef GL_FLOAT_MAT2x3
const enum_value<
	GLenum,
	GL_FLOAT_MAT2x3,
	mp_list<oglplus::sl_data_type>
> enum_value::float_mat2x3;
#endif

#ifdef GL_FLOAT_MAT2x4
const enum_value<
	GLenum,
	GL_FLOAT_MAT2x4,
	mp_list<oglplus::sl_data_type>
> enum_value::float_mat2x4;
#endif

#ifdef GL_FLOAT_MAT3
const enum_value<
	GLenum,
	GL_FLOAT_MAT3,
	mp_list<oglplus::sl_data_type>
> enum_value::float_mat3;
#endif

#ifdef GL_FLOAT_MAT3x2
const enum_value<
	GLenum,
	GL_FLOAT_MAT3x2,
	mp_list<oglplus::sl_data_type>
> enum_value::float_mat3x2;
#endif

#ifdef GL_FLOAT_MAT3x4
const enum_value<
	GLenum,
	GL_FLOAT_MAT3x4,
	mp_list<oglplus::sl_data_type>
> enum_value::float_mat3x4;
#endif

#ifdef GL_FLOAT_MAT4
const enum_value<
	GLenum,
	GL_FLOAT_MAT4,
	mp_list<oglplus::sl_data_type>
> enum_value::float_mat4;
#endif

#ifdef GL_FLOAT_MAT4x2
const enum_value<
	GLenum,
	GL_FLOAT_MAT4x2,
	mp_list<oglplus::sl_data_type>
> enum_value::float_mat4x2;
#endif

#ifdef GL_FLOAT_MAT4x3
const enum_value<
	GLenum,
	GL_FLOAT_MAT4x3,
	mp_list<oglplus::sl_data_type>
> enum_value::float_mat4x3;
#endif

#ifdef GL_FLOAT_VEC2
const enum_value<
	GLenum,
	GL_FLOAT_VEC2,
	mp_list<oglplus::sl_data_type>
> enum_value::float_vec2;
#endif

#ifdef GL_FLOAT_VEC3
const enum_value<
	GLenum,
	GL_FLOAT_VEC3,
	mp_list<oglplus::sl_data_type>
> enum_value::float_vec3;
#endif

#ifdef GL_FLOAT_VEC4
const enum_value<
	GLenum,
	GL_FLOAT_VEC4,
	mp_list<oglplus::sl_data_type>
> enum_value::float_vec4;
#endif

#ifdef GL_FONT_ASCENDER_BIT_NV
const enum_value<
	GLbitfield,
	GL_FONT_ASCENDER_BIT_NV,
	mp_list<oglplus::path_metric_query_nv>
> enum_value::font_ascender_bit_nv;
#endif

#ifdef GL_FONT_DESCENDER_BIT_NV
const enum_value<
	GLbitfield,
	GL_FONT_DESCENDER_BIT_NV,
	mp_list<oglplus::path_metric_query_nv>
> enum_value::font_descender_bit_nv;
#endif

#ifdef GL_FONT_HAS_KERNING_BIT_NV
const enum_value<
	GLbitfield,
	GL_FONT_HAS_KERNING_BIT_NV,
	mp_list<oglplus::path_metric_query_nv>
> enum_value::font_has_kerning_bit_nv;
#endif

#ifdef GL_FONT_HEIGHT_BIT_NV
const enum_value<
	GLbitfield,
	GL_FONT_HEIGHT_BIT_NV,
	mp_list<oglplus::path_metric_query_nv>
> enum_value::font_height_bit_nv;
#endif

#ifdef GL_FONT_MAX_ADVANCE_HEIGHT_BIT_NV
const enum_value<
	GLbitfield,
	GL_FONT_MAX_ADVANCE_HEIGHT_BIT_NV,
	mp_list<oglplus::path_metric_query_nv>
> enum_value::font_max_advance_height_bit_nv;
#endif

#ifdef GL_FONT_MAX_ADVANCE_WIDTH_BIT_NV
const enum_value<
	GLbitfield,
	GL_FONT_MAX_ADVANCE_WIDTH_BIT_NV,
	mp_list<oglplus::path_metric_query_nv>
> enum_value::font_max_advance_width_bit_nv;
#endif

#ifdef GL_FONT_UNDERLINE_POSITION_BIT_NV
const enum_value<
	GLbitfield,
	GL_FONT_UNDERLINE_POSITION_BIT_NV,
	mp_list<oglplus::path_metric_query_nv>
> enum_value::font_underline_position_bit_nv;
#endif

#ifdef GL_FONT_UNDERLINE_THICKNESS_BIT_NV
const enum_value<
	GLbitfield,
	GL_FONT_UNDERLINE_THICKNESS_BIT_NV,
	mp_list<oglplus::path_metric_query_nv>
> enum_value::font_underline_thickness_bit_nv;
#endif

#ifdef GL_FONT_UNITS_PER_EM_BIT_NV
const enum_value<
	GLbitfield,
	GL_FONT_UNITS_PER_EM_BIT_NV,
	mp_list<oglplus::path_metric_query_nv>
> enum_value::font_units_per_em_bit_nv;
#endif

#ifdef GL_FONT_X_MAX_BOUNDS_BIT_NV
const enum_value<
	GLbitfield,
	GL_FONT_X_MAX_BOUNDS_BIT_NV,
	mp_list<oglplus::path_metric_query_nv>
> enum_value::font_x_max_bounds_bit_nv;
#endif

#ifdef GL_FONT_X_MIN_BOUNDS_BIT_NV
const enum_value<
	GLbitfield,
	GL_FONT_X_MIN_BOUNDS_BIT_NV,
	mp_list<oglplus::path_metric_query_nv>
> enum_value::font_x_min_bounds_bit_nv;
#endif

#ifdef GL_FONT_Y_MAX_BOUNDS_BIT_NV
const enum_value<
	GLbitfield,
	GL_FONT_Y_MAX_BOUNDS_BIT_NV,
	mp_list<oglplus::path_metric_query_nv>
> enum_value::font_y_max_bounds_bit_nv;
#endif

#ifdef GL_FONT_Y_MIN_BOUNDS_BIT_NV
const enum_value<
	GLbitfield,
	GL_FONT_Y_MIN_BOUNDS_BIT_NV,
	mp_list<oglplus::path_metric_query_nv>
> enum_value::font_y_min_bounds_bit_nv;
#endif

#ifdef GL_FRACTIONAL_EVEN
const enum_value<
	GLenum,
	GL_FRACTIONAL_EVEN,
	mp_list<oglplus::tess_gen_primitive_spacing>
> enum_value::fractional_even;
#endif

#ifdef GL_FRACTIONAL_ODD
const enum_value<
	GLenum,
	GL_FRACTIONAL_ODD,
	mp_list<oglplus::tess_gen_primitive_spacing>
> enum_value::fractional_odd;
#endif

#ifdef GL_FRAGMENT_COVERAGE_TO_COLOR_NV
const enum_value<
	GLenum,
	GL_FRAGMENT_COVERAGE_TO_COLOR_NV,
	mp_list<oglplus::capability>
> enum_value::fragment_coverage_to_color;
#endif

#ifdef GL_FRAGMENT_SHADER
const enum_value<
	GLenum,
	GL_FRAGMENT_SHADER,
	mp_list<oglplus::shader_type,oglplus::program_pipeline_parameter>
> enum_value::fragment_shader;
#endif

#ifdef GL_FRAGMENT_SHADER_BIT
const enum_value<
	GLbitfield,
	GL_FRAGMENT_SHADER_BIT,
	mp_list<oglplus::program_pipeline_stage>
> enum_value::fragment_shader_bit;
#endif

#ifdef GL_FRAGMENT_SHADER_DERIVATIVE_HINT
const enum_value<
	GLenum,
	GL_FRAGMENT_SHADER_DERIVATIVE_HINT,
	mp_list<oglplus::hint_target,oglplus::numeric_query>
> enum_value::fragment_shader_derivative_hint;
#endif

#ifdef GL_FRAGMENT_SHADER_INVOCATIONS_ARB
const enum_value<
	GLenum,
	GL_FRAGMENT_SHADER_INVOCATIONS_ARB,
	mp_list<oglplus::query_target>
> enum_value::fragment_shader_invocations;
#endif

#ifdef GL_FRAGMENT_SUBROUTINE
const enum_value<
	GLenum,
	GL_FRAGMENT_SUBROUTINE,
	mp_list<oglplus::program_interface>
> enum_value::fragment_subroutine;
#endif

#ifdef GL_FRAGMENT_SUBROUTINE_UNIFORM
const enum_value<
	GLenum,
	GL_FRAGMENT_SUBROUTINE_UNIFORM,
	mp_list<oglplus::program_interface>
> enum_value::fragment_subroutine_uniform;
#endif

#ifdef GL_FRAMEBUFFER
const enum_value<
	GLenum,
	GL_FRAMEBUFFER,
	mp_list<oglplus::object_type>
> enum_value::framebuffer;
#endif

#ifdef GL_FRAMEBUFFER_BARRIER_BIT
const enum_value<
	GLbitfield,
	GL_FRAMEBUFFER_BARRIER_BIT,
	mp_list<oglplus::memory_barrier_bits>
> enum_value::framebuffer_barrier_bit;
#endif

#ifdef GL_FRAMEBUFFER_COMPLETE
const enum_value<
	GLenum,
	GL_FRAMEBUFFER_COMPLETE,
	mp_list<oglplus::framebuffer_status>
> enum_value::framebuffer_complete;
#endif

#ifdef GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT
const enum_value<
	GLenum,
	GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT,
	mp_list<oglplus::framebuffer_status>
> enum_value::framebuffer_incomplete_attachment;
#endif

#ifdef GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS
const enum_value<
	GLenum,
	GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS,
	mp_list<oglplus::framebuffer_status>
> enum_value::framebuffer_incomplete_layer_targets;
#endif

#ifdef GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT
const enum_value<
	GLenum,
	GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT,
	mp_list<oglplus::framebuffer_status>
> enum_value::framebuffer_incomplete_missing_attachment;
#endif

#ifdef GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE
const enum_value<
	GLenum,
	GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE,
	mp_list<oglplus::framebuffer_status>
> enum_value::framebuffer_incomplete_multisample;
#endif

#ifdef GL_FRAMEBUFFER_SRGB
const enum_value<
	GLenum,
	GL_FRAMEBUFFER_SRGB,
	mp_list<oglplus::capability>
> enum_value::framebuffer_srgb;
#endif

#ifdef GL_FRAMEBUFFER_UNDEFINED
const enum_value<
	GLenum,
	GL_FRAMEBUFFER_UNDEFINED,
	mp_list<oglplus::framebuffer_status>
> enum_value::framebuffer_undefined;
#endif

#ifdef GL_FRAMEBUFFER_UNSUPPORTED
const enum_value<
	GLenum,
	GL_FRAMEBUFFER_UNSUPPORTED,
	mp_list<oglplus::framebuffer_status>
> enum_value::framebuffer_unsupported;
#endif

#ifdef GL_FRONT
const enum_value<
	GLenum,
	GL_FRONT,
	mp_list<oglplus::color_buffer,oglplus::single_face,oglplus::face>
> enum_value::front;
#endif

#ifdef GL_FRONT_AND_BACK
const enum_value<
	GLenum,
	GL_FRONT_AND_BACK,
	mp_list<oglplus::color_buffer,oglplus::face>
> enum_value::front_and_back;
#endif

#ifdef GL_FRONT_LEFT
const enum_value<
	GLenum,
	GL_FRONT_LEFT,
	mp_list<oglplus::color_buffer>
> enum_value::front_left;
#endif

#ifdef GL_FRONT_RIGHT
const enum_value<
	GLenum,
	GL_FRONT_RIGHT,
	mp_list<oglplus::color_buffer>
> enum_value::front_right;
#endif

#ifdef GL_FUNC_ADD
const enum_value<
	GLenum,
	GL_FUNC_ADD,
	mp_list<oglplus::blend_equation>
> enum_value::func_add;
#endif

#ifdef GL_FUNC_REVERSE_SUBTRACT
const enum_value<
	GLenum,
	GL_FUNC_REVERSE_SUBTRACT,
	mp_list<oglplus::blend_equation>
> enum_value::func_reverse_subtract;
#endif

#ifdef GL_FUNC_SUBTRACT
const enum_value<
	GLenum,
	GL_FUNC_SUBTRACT,
	mp_list<oglplus::blend_equation>
> enum_value::func_subtract;
#endif

#ifdef GL_GEOMETRY_SHADER
const enum_value<
	GLenum,
	GL_GEOMETRY_SHADER,
	mp_list<oglplus::shader_type,oglplus::program_pipeline_parameter>
> enum_value::geometry_shader;
#endif

#ifdef GL_GEOMETRY_SHADER_BIT
const enum_value<
	GLbitfield,
	GL_GEOMETRY_SHADER_BIT,
	mp_list<oglplus::program_pipeline_stage>
> enum_value::geometry_shader_bit;
#endif

#ifdef GL_GEOMETRY_SHADER_INVOCATIONS
const enum_value<
	GLenum,
	GL_GEOMETRY_SHADER_INVOCATIONS,
	mp_list<oglplus::query_target>
> enum_value::geometry_shader_invocations;
#endif

#ifdef GL_GEOMETRY_SHADER_PRIMITIVES_EMITTED_ARB
const enum_value<
	GLenum,
	GL_GEOMETRY_SHADER_PRIMITIVES_EMITTED_ARB,
	mp_list<oglplus::query_target>
> enum_value::geometry_shader_primitives_emitted;
#endif

#ifdef GL_GEOMETRY_SUBROUTINE
const enum_value<
	GLenum,
	GL_GEOMETRY_SUBROUTINE,
	mp_list<oglplus::program_interface>
> enum_value::geometry_subroutine;
#endif

#ifdef GL_GEOMETRY_SUBROUTINE_UNIFORM
const enum_value<
	GLenum,
	GL_GEOMETRY_SUBROUTINE_UNIFORM,
	mp_list<oglplus::program_interface>
> enum_value::geometry_subroutine_uniform;
#endif

#ifdef GL_GEQUAL
const enum_value<
	GLenum,
	GL_GEQUAL,
	mp_list<oglplus::compare_function>
> enum_value::gequal;
#endif

#ifdef GL_GLYPH_HAS_KERNING_BIT_NV
const enum_value<
	GLbitfield,
	GL_GLYPH_HAS_KERNING_BIT_NV,
	mp_list<oglplus::path_metric_query_nv>
> enum_value::glyph_has_kerning_bit_nv;
#endif

#ifdef GL_GLYPH_HEIGHT_BIT_NV
const enum_value<
	GLbitfield,
	GL_GLYPH_HEIGHT_BIT_NV,
	mp_list<oglplus::path_metric_query_nv>
> enum_value::glyph_height_bit_nv;
#endif

#ifdef GL_GLYPH_HORIZONTAL_BEARING_ADVANCE_BIT_NV
const enum_value<
	GLbitfield,
	GL_GLYPH_HORIZONTAL_BEARING_ADVANCE_BIT_NV,
	mp_list<oglplus::path_metric_query_nv>
> enum_value::glyph_horizontal_bearing_advance_bit_nv;
#endif

#ifdef GL_GLYPH_HORIZONTAL_BEARING_X_BIT_NV
const enum_value<
	GLbitfield,
	GL_GLYPH_HORIZONTAL_BEARING_X_BIT_NV,
	mp_list<oglplus::path_metric_query_nv>
> enum_value::glyph_horizontal_bearing_x_bit_nv;
#endif

#ifdef GL_GLYPH_HORIZONTAL_BEARING_Y_BIT_NV
const enum_value<
	GLbitfield,
	GL_GLYPH_HORIZONTAL_BEARING_Y_BIT_NV,
	mp_list<oglplus::path_metric_query_nv>
> enum_value::glyph_horizontal_bearing_y_bit_nv;
#endif

#ifdef GL_GLYPH_VERTICAL_BEARING_ADVANCE_BIT_NV
const enum_value<
	GLbitfield,
	GL_GLYPH_VERTICAL_BEARING_ADVANCE_BIT_NV,
	mp_list<oglplus::path_metric_query_nv>
> enum_value::glyph_vertical_bearing_advance_bit_nv;
#endif

#ifdef GL_GLYPH_VERTICAL_BEARING_X_BIT_NV
const enum_value<
	GLbitfield,
	GL_GLYPH_VERTICAL_BEARING_X_BIT_NV,
	mp_list<oglplus::path_metric_query_nv>
> enum_value::glyph_vertical_bearing_x_bit_nv;
#endif

#ifdef GL_GLYPH_VERTICAL_BEARING_Y_BIT_NV
const enum_value<
	GLbitfield,
	GL_GLYPH_VERTICAL_BEARING_Y_BIT_NV,
	mp_list<oglplus::path_metric_query_nv>
> enum_value::glyph_vertical_bearing_y_bit_nv;
#endif

#ifdef GL_GLYPH_WIDTH_BIT_NV
const enum_value<
	GLbitfield,
	GL_GLYPH_WIDTH_BIT_NV,
	mp_list<oglplus::path_metric_query_nv>
> enum_value::glyph_width_bit_nv;
#endif

#ifdef GL_GREATER
const enum_value<
	GLenum,
	GL_GREATER,
	mp_list<oglplus::compare_function>
> enum_value::greater;
#endif

#ifdef GL_GREEN
const enum_value<
	GLenum,
	GL_GREEN,
	mp_list<oglplus::texture_swizzle_mode,oglplus::pixel_data_format>
> enum_value::green;
#endif

#ifdef GL_GREEN_INTEGER
const enum_value<
	GLenum,
	GL_GREEN_INTEGER,
	mp_list<oglplus::pixel_data_format>
> enum_value::green_integer;
#endif

#ifdef GL_GUILTY_CONTEXT_RESET
const enum_value<
	GLenum,
	GL_GUILTY_CONTEXT_RESET,
	mp_list<oglplus::graphics_reset_status>
> enum_value::guilty_context_reset;
#endif

#ifdef GL_HALF_FLOAT
const enum_value<
	GLenum,
	GL_HALF_FLOAT,
	mp_list<oglplus::pixel_data_type,oglplus::data_type>
> enum_value::half_float;
#endif

#ifdef GL_HARDLIGHT_KHR
const enum_value<
	GLenum,
	GL_HARDLIGHT_KHR,
	mp_list<oglplus::blend_equation_advanced>
> enum_value::hardlight_khr;
#endif

#ifdef GL_HIGH_FLOAT
const enum_value<
	GLenum,
	GL_HIGH_FLOAT,
	mp_list<oglplus::precision_type>
> enum_value::high_float;
#endif

#ifdef GL_HIGH_INT
const enum_value<
	GLenum,
	GL_HIGH_INT,
	mp_list<oglplus::precision_type>
> enum_value::high_int;
#endif

#ifdef GL_HORIZONTAL_LINE_TO_NV
const enum_value<
	GLubyte,
	GL_HORIZONTAL_LINE_TO_NV,
	mp_list<oglplus::path_command_nv>
> enum_value::horizontal_line_to_nv;
#endif

#ifdef GL_HSL_COLOR_KHR
const enum_value<
	GLenum,
	GL_HSL_COLOR_KHR,
	mp_list<oglplus::blend_equation_advanced>
> enum_value::hsl_color_khr;
#endif

#ifdef GL_HSL_HUE_KHR
const enum_value<
	GLenum,
	GL_HSL_HUE_KHR,
	mp_list<oglplus::blend_equation_advanced>
> enum_value::hsl_hue_khr;
#endif

#ifdef GL_HSL_LUMINOSITY_KHR
const enum_value<
	GLenum,
	GL_HSL_LUMINOSITY_KHR,
	mp_list<oglplus::blend_equation_advanced>
> enum_value::hsl_luminosity_khr;
#endif

#ifdef GL_HSL_SATURATION_KHR
const enum_value<
	GLenum,
	GL_HSL_SATURATION_KHR,
	mp_list<oglplus::blend_equation_advanced>
> enum_value::hsl_saturation_khr;
#endif

#ifdef GL_IMAGE_1D
const enum_value<
	GLenum,
	GL_IMAGE_1D,
	mp_list<oglplus::sl_data_type>
> enum_value::image_1d;
#endif

#ifdef GL_IMAGE_1D_ARRAY
const enum_value<
	GLenum,
	GL_IMAGE_1D_ARRAY,
	mp_list<oglplus::sl_data_type>
> enum_value::image_1d_array;
#endif

#ifdef GL_IMAGE_2D
const enum_value<
	GLenum,
	GL_IMAGE_2D,
	mp_list<oglplus::sl_data_type>
> enum_value::image_2d;
#endif

#ifdef GL_IMAGE_2D_ARRAY
const enum_value<
	GLenum,
	GL_IMAGE_2D_ARRAY,
	mp_list<oglplus::sl_data_type>
> enum_value::image_2d_array;
#endif

#ifdef GL_IMAGE_2D_MULTISAMPLE
const enum_value<
	GLenum,
	GL_IMAGE_2D_MULTISAMPLE,
	mp_list<oglplus::sl_data_type>
> enum_value::image_2d_multisample;
#endif

#ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
const enum_value<
	GLenum,
	GL_IMAGE_2D_MULTISAMPLE_ARRAY,
	mp_list<oglplus::sl_data_type>
> enum_value::image_2d_multisample_array;
#endif

#ifdef GL_IMAGE_2D_RECT
const enum_value<
	GLenum,
	GL_IMAGE_2D_RECT,
	mp_list<oglplus::sl_data_type>
> enum_value::image_2d_rect;
#endif

#ifdef GL_IMAGE_3D
const enum_value<
	GLenum,
	GL_IMAGE_3D,
	mp_list<oglplus::sl_data_type>
> enum_value::image_3d;
#endif

#ifdef GL_IMAGE_BUFFER
const enum_value<
	GLenum,
	GL_IMAGE_BUFFER,
	mp_list<oglplus::sl_data_type>
> enum_value::image_buffer;
#endif

#ifdef GL_IMAGE_CUBE
const enum_value<
	GLenum,
	GL_IMAGE_CUBE,
	mp_list<oglplus::sl_data_type>
> enum_value::image_cube;
#endif

#ifdef GL_IMAGE_FORMAT_COMPATIBILITY_TYPE
const enum_value<
	GLenum,
	GL_IMAGE_FORMAT_COMPATIBILITY_TYPE,
	mp_list<oglplus::texture_parameter>
> enum_value::image_format_compatibility_type;
#endif

#ifdef GL_IMPLEMENTATION_COLOR_READ_FORMAT
const enum_value<
	GLenum,
	GL_IMPLEMENTATION_COLOR_READ_FORMAT,
	mp_list<oglplus::numeric_query>
> enum_value::implementation_color_read_format;
#endif

#ifdef GL_IMPLEMENTATION_COLOR_READ_TYPE
const enum_value<
	GLenum,
	GL_IMPLEMENTATION_COLOR_READ_TYPE,
	mp_list<oglplus::numeric_query>
> enum_value::implementation_color_read_type;
#endif

#ifdef GL_INCR
const enum_value<
	GLenum,
	GL_INCR,
	mp_list<oglplus::stencil_operation>
> enum_value::incr;
#endif

#ifdef GL_INCR_WRAP
const enum_value<
	GLenum,
	GL_INCR_WRAP,
	mp_list<oglplus::stencil_operation>
> enum_value::incr_wrap;
#endif

#ifdef GL_INFO_LOG_LENGTH
const enum_value<
	GLenum,
	GL_INFO_LOG_LENGTH,
	mp_list<oglplus::shader_parameter,oglplus::program_parameter,oglplus::program_pipeline_parameter>
> enum_value::info_log_length;
#endif

#ifdef GL_INNOCENT_CONTEXT_RESET
const enum_value<
	GLenum,
	GL_INNOCENT_CONTEXT_RESET,
	mp_list<oglplus::graphics_reset_status>
> enum_value::innocent_context_reset;
#endif

#ifdef GL_INT
const enum_value<
	GLenum,
	GL_INT,
	mp_list<oglplus::sl_data_type,oglplus::pixel_data_type,oglplus::data_type>
> enum_value::int_;
#endif

#ifdef GL_INT_IMAGE_1D
const enum_value<
	GLenum,
	GL_INT_IMAGE_1D,
	mp_list<oglplus::sl_data_type>
> enum_value::int_image_1d;
#endif

#ifdef GL_INT_IMAGE_1D_ARRAY
const enum_value<
	GLenum,
	GL_INT_IMAGE_1D_ARRAY,
	mp_list<oglplus::sl_data_type>
> enum_value::int_image_1d_array;
#endif

#ifdef GL_INT_IMAGE_2D
const enum_value<
	GLenum,
	GL_INT_IMAGE_2D,
	mp_list<oglplus::sl_data_type>
> enum_value::int_image_2d;
#endif

#ifdef GL_INT_IMAGE_2D_ARRAY
const enum_value<
	GLenum,
	GL_INT_IMAGE_2D_ARRAY,
	mp_list<oglplus::sl_data_type>
> enum_value::int_image_2d_array;
#endif

#ifdef GL_INT_IMAGE_2D_MULTISAMPLE
const enum_value<
	GLenum,
	GL_INT_IMAGE_2D_MULTISAMPLE,
	mp_list<oglplus::sl_data_type>
> enum_value::int_image_2d_multisample;
#endif

#ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
const enum_value<
	GLenum,
	GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY,
	mp_list<oglplus::sl_data_type>
> enum_value::int_image_2d_multisample_array;
#endif

#ifdef GL_INT_IMAGE_2D_RECT
const enum_value<
	GLenum,
	GL_INT_IMAGE_2D_RECT,
	mp_list<oglplus::sl_data_type>
> enum_value::int_image_2d_rect;
#endif

#ifdef GL_INT_IMAGE_3D
const enum_value<
	GLenum,
	GL_INT_IMAGE_3D,
	mp_list<oglplus::sl_data_type>
> enum_value::int_image_3d;
#endif

#ifdef GL_INT_IMAGE_BUFFER
const enum_value<
	GLenum,
	GL_INT_IMAGE_BUFFER,
	mp_list<oglplus::sl_data_type>
> enum_value::int_image_buffer;
#endif

#ifdef GL_INT_IMAGE_CUBE
const enum_value<
	GLenum,
	GL_INT_IMAGE_CUBE,
	mp_list<oglplus::sl_data_type>
> enum_value::int_image_cube;
#endif

#ifdef GL_INT_SAMPLER_1D
const enum_value<
	GLenum,
	GL_INT_SAMPLER_1D,
	mp_list<oglplus::sl_data_type>
> enum_value::int_sampler_1d;
#endif

#ifdef GL_INT_SAMPLER_1D_ARRAY
const enum_value<
	GLenum,
	GL_INT_SAMPLER_1D_ARRAY,
	mp_list<oglplus::sl_data_type>
> enum_value::int_sampler_1d_array;
#endif

#ifdef GL_INT_SAMPLER_2D
const enum_value<
	GLenum,
	GL_INT_SAMPLER_2D,
	mp_list<oglplus::sl_data_type>
> enum_value::int_sampler_2d;
#endif

#ifdef GL_INT_SAMPLER_2D_ARRAY
const enum_value<
	GLenum,
	GL_INT_SAMPLER_2D_ARRAY,
	mp_list<oglplus::sl_data_type>
> enum_value::int_sampler_2d_array;
#endif

#ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
const enum_value<
	GLenum,
	GL_INT_SAMPLER_2D_MULTISAMPLE,
	mp_list<oglplus::sl_data_type>
> enum_value::int_sampler_2d_multisample;
#endif

#ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
const enum_value<
	GLenum,
	GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY,
	mp_list<oglplus::sl_data_type>
> enum_value::int_sampler_2d_multisample_array;
#endif

#ifdef GL_INT_SAMPLER_2D_RECT
const enum_value<
	GLenum,
	GL_INT_SAMPLER_2D_RECT,
	mp_list<oglplus::sl_data_type>
> enum_value::int_sampler_2d_rect;
#endif

#ifdef GL_INT_SAMPLER_3D
const enum_value<
	GLenum,
	GL_INT_SAMPLER_3D,
	mp_list<oglplus::sl_data_type>
> enum_value::int_sampler_3d;
#endif

#ifdef GL_INT_SAMPLER_BUFFER
const enum_value<
	GLenum,
	GL_INT_SAMPLER_BUFFER,
	mp_list<oglplus::sl_data_type>
> enum_value::int_sampler_buffer;
#endif

#ifdef GL_INT_SAMPLER_CUBE
const enum_value<
	GLenum,
	GL_INT_SAMPLER_CUBE,
	mp_list<oglplus::sl_data_type>
> enum_value::int_sampler_cube;
#endif

#ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
const enum_value<
	GLenum,
	GL_INT_SAMPLER_CUBE_MAP_ARRAY,
	mp_list<oglplus::sl_data_type>
> enum_value::int_sampler_cube_map_array;
#endif

#ifdef GL_INT_VEC2
const enum_value<
	GLenum,
	GL_INT_VEC2,
	mp_list<oglplus::sl_data_type>
> enum_value::int_vec2;
#endif

#ifdef GL_INT_VEC3
const enum_value<
	GLenum,
	GL_INT_VEC3,
	mp_list<oglplus::sl_data_type>
> enum_value::int_vec3;
#endif

#ifdef GL_INT_VEC4
const enum_value<
	GLenum,
	GL_INT_VEC4,
	mp_list<oglplus::sl_data_type>
> enum_value::int_vec4;
#endif

#ifdef GL_INTENSITY
const enum_value<
	GLenum,
	GL_INTENSITY,
	mp_list<oglplus::path_color_format_nv>
> enum_value::intensity;
#endif

#ifdef GL_INTERLEAVED_ATTRIBS
const enum_value<
	GLenum,
	GL_INTERLEAVED_ATTRIBS,
	mp_list<oglplus::transform_feedback_mode>
> enum_value::interleaved_attribs;
#endif

#ifdef GL_INVALID_ENUM
const enum_value<
	GLenum,
	GL_INVALID_ENUM,
	mp_list<oglplus::error_code>
> enum_value::invalid_enum;
#endif

#ifdef GL_INVALID_FRAMEBUFFER_OPERATION
const enum_value<
	GLenum,
	GL_INVALID_FRAMEBUFFER_OPERATION,
	mp_list<oglplus::error_code>
> enum_value::invalid_framebuffer_operation;
#endif

#ifdef GL_INVALID_OPERATION
const enum_value<
	GLenum,
	GL_INVALID_OPERATION,
	mp_list<oglplus::error_code>
> enum_value::invalid_operation;
#endif

#ifdef GL_INVALID_VALUE
const enum_value<
	GLenum,
	GL_INVALID_VALUE,
	mp_list<oglplus::error_code>
> enum_value::invalid_value;
#endif

#ifdef GL_INVERT
const enum_value<
	GLenum,
	GL_INVERT,
	mp_list<oglplus::path_fill_mode_nv,oglplus::color_logic_operation,oglplus::stencil_operation>
> enum_value::invert;
#endif

#ifdef GL_IS_PER_PATCH
const enum_value<
	GLenum,
	GL_IS_PER_PATCH,
	mp_list<oglplus::program_resource_property>
> enum_value::is_per_patch;
#endif

#ifdef GL_IS_ROW_MAJOR
const enum_value<
	GLenum,
	GL_IS_ROW_MAJOR,
	mp_list<oglplus::program_resource_property>
> enum_value::is_row_major;
#endif

#ifdef GL_ISOLINES
const enum_value<
	GLenum,
	GL_ISOLINES,
	mp_list<oglplus::tess_gen_primitive_type>
> enum_value::isolines;
#endif

#ifdef GL_ITALIC_BIT_NV
const enum_value<
	GLbitfield,
	GL_ITALIC_BIT_NV,
	mp_list<oglplus::path_font_style_nv>
> enum_value::italic_bit_nv;
#endif

#ifdef GL_KEEP
const enum_value<
	GLenum,
	GL_KEEP,
	mp_list<oglplus::stencil_operation>
> enum_value::keep;
#endif

#ifdef GL_LARGE_CCW_ARC_TO_NV
const enum_value<
	GLubyte,
	GL_LARGE_CCW_ARC_TO_NV,
	mp_list<oglplus::path_command_nv>
> enum_value::large_ccw_arc_to_nv;
#endif

#ifdef GL_LARGE_CW_ARC_TO_NV
const enum_value<
	GLubyte,
	GL_LARGE_CW_ARC_TO_NV,
	mp_list<oglplus::path_command_nv>
> enum_value::large_cw_arc_to_nv;
#endif

#ifdef GL_LAST_VERTEX_CONVENTION
const enum_value<
	GLenum,
	GL_LAST_VERTEX_CONVENTION,
	mp_list<oglplus::provoke_mode>
> enum_value::last_vertex_convention;
#endif

#ifdef GL_LAYER_PROVOKING_VERTEX
const enum_value<
	GLenum,
	GL_LAYER_PROVOKING_VERTEX,
	mp_list<oglplus::numeric_query>
> enum_value::layer_provoking_vertex;
#endif

#ifdef GL_LEFT
const enum_value<
	GLenum,
	GL_LEFT,
	mp_list<oglplus::color_buffer>
> enum_value::left;
#endif

#ifdef GL_LEQUAL
const enum_value<
	GLenum,
	GL_LEQUAL,
	mp_list<oglplus::compare_function>
> enum_value::lequal;
#endif

#ifdef GL_LESS
const enum_value<
	GLenum,
	GL_LESS,
	mp_list<oglplus::compare_function>
> enum_value::less;
#endif

#ifdef GL_LIGHTEN_KHR
const enum_value<
	GLenum,
	GL_LIGHTEN_KHR,
	mp_list<oglplus::blend_equation_advanced>
> enum_value::lighten_khr;
#endif

#ifdef GL_LINE
const enum_value<
	GLenum,
	GL_LINE,
	mp_list<oglplus::polygon_mode>
> enum_value::line;
#endif

#ifdef GL_LINE_LOOP
const enum_value<
	GLenum,
	GL_LINE_LOOP,
	mp_list<oglplus::primitive_type,oglplus::old_primitive_type>
> enum_value::line_loop;
#endif

#ifdef GL_LINE_SMOOTH
const enum_value<
	GLenum,
	GL_LINE_SMOOTH,
	mp_list<oglplus::capability>
> enum_value::line_smooth;
#endif

#ifdef GL_LINE_SMOOTH_HINT
const enum_value<
	GLenum,
	GL_LINE_SMOOTH_HINT,
	mp_list<oglplus::hint_target,oglplus::numeric_query>
> enum_value::line_smooth_hint;
#endif

#ifdef GL_LINE_STRIP
const enum_value<
	GLenum,
	GL_LINE_STRIP,
	mp_list<oglplus::primitive_type,oglplus::old_primitive_type>
> enum_value::line_strip;
#endif

#ifdef GL_LINE_STRIP_ADJACENCY
const enum_value<
	GLenum,
	GL_LINE_STRIP_ADJACENCY,
	mp_list<oglplus::primitive_type>
> enum_value::line_strip_adjacency;
#endif

#ifdef GL_LINE_TO_NV
const enum_value<
	GLubyte,
	GL_LINE_TO_NV,
	mp_list<oglplus::path_command_nv>
> enum_value::line_to_nv;
#endif

#ifdef GL_LINE_WIDTH
const enum_value<
	GLenum,
	GL_LINE_WIDTH,
	mp_list<oglplus::numeric_query>
> enum_value::line_width;
#endif

#ifdef GL_LINEAR
const enum_value<
	GLenum,
	GL_LINEAR,
	mp_list<oglplus::texture_mag_filter,oglplus::blit_filter,oglplus::texture_filter,oglplus::texture_min_filter>
> enum_value::linear;
#endif

#ifdef GL_LINEAR_MIPMAP_LINEAR
const enum_value<
	GLenum,
	GL_LINEAR_MIPMAP_LINEAR,
	mp_list<oglplus::texture_min_filter>
> enum_value::linear_mipmap_linear;
#endif

#ifdef GL_LINEAR_MIPMAP_NEAREST
const enum_value<
	GLenum,
	GL_LINEAR_MIPMAP_NEAREST,
	mp_list<oglplus::texture_min_filter>
> enum_value::linear_mipmap_nearest;
#endif

#ifdef GL_LINES
const enum_value<
	GLenum,
	GL_LINES,
	mp_list<oglplus::primitive_type,oglplus::old_primitive_type,oglplus::transform_feedback_primitive_type>
> enum_value::lines;
#endif

#ifdef GL_LINES_ADJACENCY
const enum_value<
	GLenum,
	GL_LINES_ADJACENCY,
	mp_list<oglplus::primitive_type>
> enum_value::lines_adjacency;
#endif

#ifdef GL_LINK_STATUS
const enum_value<
	GLenum,
	GL_LINK_STATUS,
	mp_list<oglplus::program_parameter>
> enum_value::link_status;
#endif

#ifdef GL_LOCATION
const enum_value<
	GLenum,
	GL_LOCATION,
	mp_list<oglplus::program_resource_property>
> enum_value::location;
#endif

#ifdef GL_LOCATION_COMPONENT
const enum_value<
	GLenum,
	GL_LOCATION_COMPONENT,
	mp_list<oglplus::program_resource_property>
> enum_value::location_component;
#endif

#ifdef GL_LOCATION_INDEX
const enum_value<
	GLenum,
	GL_LOCATION_INDEX,
	mp_list<oglplus::program_resource_property>
> enum_value::location_index;
#endif

#ifdef GL_LOGIC_OP_MODE
const enum_value<
	GLenum,
	GL_LOGIC_OP_MODE,
	mp_list<oglplus::numeric_query>
> enum_value::logic_op_mode;
#endif

#ifdef GL_LOSE_CONTEXT_ON_RESET
const enum_value<
	GLenum,
	GL_LOSE_CONTEXT_ON_RESET,
	mp_list<oglplus::reset_notification_strategy>
> enum_value::lose_context_on_reset;
#endif

#ifdef GL_LOW_FLOAT
const enum_value<
	GLenum,
	GL_LOW_FLOAT,
	mp_list<oglplus::precision_type>
> enum_value::low_float;
#endif

#ifdef GL_LOW_INT
const enum_value<
	GLenum,
	GL_LOW_INT,
	mp_list<oglplus::precision_type>
> enum_value::low_int;
#endif

#ifdef GL_LOWER_LEFT
const enum_value<
	GLenum,
	GL_LOWER_LEFT,
	mp_list<oglplus::clip_origin>
> enum_value::lower_left;
#endif

#ifdef GL_LUMINANCE
const enum_value<
	GLenum,
	GL_LUMINANCE,
	mp_list<oglplus::path_color_format_nv>
> enum_value::luminance;
#endif

#ifdef GL_LUMINANCE_ALPHA
const enum_value<
	GLenum,
	GL_LUMINANCE_ALPHA,
	mp_list<oglplus::path_color_format_nv>
> enum_value::luminance_alpha;
#endif

#ifdef GL_MAP_COHERENT_BIT
const enum_value<
	GLbitfield,
	GL_MAP_COHERENT_BIT,
	mp_list<oglplus::buffer_storage_bits,oglplus::buffer_map_access>
> enum_value::map_coherent_bit;
#endif

#ifdef GL_MAP_FLUSH_EXPLICIT_BIT
const enum_value<
	GLbitfield,
	GL_MAP_FLUSH_EXPLICIT_BIT,
	mp_list<oglplus::buffer_map_access>
> enum_value::map_flush_explicit_bit;
#endif

#ifdef GL_MAP_INVALIDATE_BUFFER_BIT
const enum_value<
	GLbitfield,
	GL_MAP_INVALIDATE_BUFFER_BIT,
	mp_list<oglplus::buffer_map_access>
> enum_value::map_invalidate_buffer_bit;
#endif

#ifdef GL_MAP_INVALIDATE_RANGE_BIT
const enum_value<
	GLbitfield,
	GL_MAP_INVALIDATE_RANGE_BIT,
	mp_list<oglplus::buffer_map_access>
> enum_value::map_invalidate_range_bit;
#endif

#ifdef GL_MAP_PERSISTENT_BIT
const enum_value<
	GLbitfield,
	GL_MAP_PERSISTENT_BIT,
	mp_list<oglplus::buffer_storage_bits,oglplus::buffer_map_access>
> enum_value::map_persistent_bit;
#endif

#ifdef GL_MAP_READ_BIT
const enum_value<
	GLbitfield,
	GL_MAP_READ_BIT,
	mp_list<oglplus::buffer_storage_bits,oglplus::buffer_map_access>
> enum_value::map_read_bit;
#endif

#ifdef GL_MAP_UNSYNCHRONIZED_BIT
const enum_value<
	GLbitfield,
	GL_MAP_UNSYNCHRONIZED_BIT,
	mp_list<oglplus::buffer_map_access>
> enum_value::map_unsynchronized_bit;
#endif

#ifdef GL_MAP_WRITE_BIT
const enum_value<
	GLbitfield,
	GL_MAP_WRITE_BIT,
	mp_list<oglplus::buffer_storage_bits,oglplus::buffer_map_access>
> enum_value::map_write_bit;
#endif

#ifdef GL_MATRIX_STRIDE
const enum_value<
	GLenum,
	GL_MATRIX_STRIDE,
	mp_list<oglplus::program_resource_property>
> enum_value::matrix_stride;
#endif

#ifdef GL_MAX
const enum_value<
	GLenum,
	GL_MAX,
	mp_list<oglplus::blend_equation>
> enum_value::max;
#endif

#ifdef GL_MAX_3D_TEXTURE_SIZE
const enum_value<
	GLenum,
	GL_MAX_3D_TEXTURE_SIZE,
	mp_list<oglplus::limit_query>
> enum_value::max_3d_texture_size;
#endif

#ifdef GL_MAX_ARRAY_TEXTURE_LAYERS
const enum_value<
	GLenum,
	GL_MAX_ARRAY_TEXTURE_LAYERS,
	mp_list<oglplus::limit_query>
> enum_value::max_array_texture_layers;
#endif

#ifdef GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS
const enum_value<
	GLenum,
	GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS,
	mp_list<oglplus::limit_query>
> enum_value::max_atomic_counter_buffer_bindings;
#endif

#ifdef GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE
const enum_value<
	GLenum,
	GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE,
	mp_list<oglplus::limit_query>
> enum_value::max_atomic_counter_buffer_size;
#endif

#ifdef GL_MAX_CLIP_DISTANCES
const enum_value<
	GLenum,
	GL_MAX_CLIP_DISTANCES,
	mp_list<oglplus::limit_query>
> enum_value::max_clip_distances;
#endif

#ifdef GL_MAX_COLOR_ATTACHMENTS
const enum_value<
	GLenum,
	GL_MAX_COLOR_ATTACHMENTS,
	mp_list<oglplus::limit_query>
> enum_value::max_color_attachments;
#endif

#ifdef GL_MAX_COLOR_TEXTURE_SAMPLES
const enum_value<
	GLenum,
	GL_MAX_COLOR_TEXTURE_SAMPLES,
	mp_list<oglplus::limit_query>
> enum_value::max_color_texture_samples;
#endif

#ifdef GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS
const enum_value<
	GLenum,
	GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS,
	mp_list<oglplus::limit_query>
> enum_value::max_combined_atomic_counter_buffers;
#endif

#ifdef GL_MAX_COMBINED_ATOMIC_COUNTERS
const enum_value<
	GLenum,
	GL_MAX_COMBINED_ATOMIC_COUNTERS,
	mp_list<oglplus::limit_query>
> enum_value::max_combined_atomic_counters;
#endif

#ifdef GL_MAX_COMBINED_CLIP_AND_CULL_DISTANCES
const enum_value<
	GLenum,
	GL_MAX_COMBINED_CLIP_AND_CULL_DISTANCES,
	mp_list<oglplus::limit_query>
> enum_value::max_combined_clip_and_cull_distances;
#endif

#ifdef GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS
const enum_value<
	GLenum,
	GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS,
	mp_list<oglplus::limit_query>
> enum_value::max_combined_fragment_uniform_components;
#endif

#ifdef GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS
const enum_value<
	GLenum,
	GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS,
	mp_list<oglplus::limit_query>
> enum_value::max_combined_geometry_uniform_components;
#endif

#ifdef GL_MAX_COMBINED_IMAGE_UNIFORMS
const enum_value<
	GLenum,
	GL_MAX_COMBINED_IMAGE_UNIFORMS,
	mp_list<oglplus::limit_query>
> enum_value::max_combined_image_uniforms;
#endif

#ifdef GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS
const enum_value<
	GLenum,
	GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS,
	mp_list<oglplus::limit_query>
> enum_value::max_combined_image_units_and_fragment_outputs;
#endif

#ifdef GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS
const enum_value<
	GLenum,
	GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS,
	mp_list<oglplus::limit_query>
> enum_value::max_combined_tess_control_uniform_components;
#endif

#ifdef GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS
const enum_value<
	GLenum,
	GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS,
	mp_list<oglplus::limit_query>
> enum_value::max_combined_tess_evaluation_uniform_components;
#endif

#ifdef GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS
const enum_value<
	GLenum,
	GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS,
	mp_list<oglplus::limit_query>
> enum_value::max_combined_texture_image_units;
#endif

#ifdef GL_MAX_COMBINED_UNIFORM_BLOCKS
const enum_value<
	GLenum,
	GL_MAX_COMBINED_UNIFORM_BLOCKS,
	mp_list<oglplus::limit_query>
> enum_value::max_combined_uniform_blocks;
#endif

#ifdef GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS
const enum_value<
	GLenum,
	GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS,
	mp_list<oglplus::limit_query>
> enum_value::max_combined_vertex_uniform_components;
#endif

#ifdef GL_MAX_COMPUTE_SHARED_MEMORY_SIZE
const enum_value<
	GLenum,
	GL_MAX_COMPUTE_SHARED_MEMORY_SIZE,
	mp_list<oglplus::limit_query>
> enum_value::max_compute_shared_memory_size;
#endif

#ifdef GL_MAX_COMPUTE_WORK_GROUP_COUNT
const enum_value<
	GLenum,
	GL_MAX_COMPUTE_WORK_GROUP_COUNT,
	mp_list<oglplus::limit_query>
> enum_value::max_compute_work_group_count;
#endif

#ifdef GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS
const enum_value<
	GLenum,
	GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS,
	mp_list<oglplus::limit_query>
> enum_value::max_compute_work_group_invocations;
#endif

#ifdef GL_MAX_COMPUTE_WORK_GROUP_SIZE
const enum_value<
	GLenum,
	GL_MAX_COMPUTE_WORK_GROUP_SIZE,
	mp_list<oglplus::limit_query>
> enum_value::max_compute_work_group_size;
#endif

#ifdef GL_MAX_CUBE_MAP_TEXTURE_SIZE
const enum_value<
	GLenum,
	GL_MAX_CUBE_MAP_TEXTURE_SIZE,
	mp_list<oglplus::limit_query>
> enum_value::max_cube_map_texture_size;
#endif

#ifdef GL_MAX_CULL_DISTANCES
const enum_value<
	GLenum,
	GL_MAX_CULL_DISTANCES,
	mp_list<oglplus::limit_query>
> enum_value::max_cull_distances;
#endif

#ifdef GL_MAX_DEPTH_TEXTURE_SAMPLES
const enum_value<
	GLenum,
	GL_MAX_DEPTH_TEXTURE_SAMPLES,
	mp_list<oglplus::limit_query>
> enum_value::max_depth_texture_samples;
#endif

#ifdef GL_MAX_DRAW_BUFFERS
const enum_value<
	GLenum,
	GL_MAX_DRAW_BUFFERS,
	mp_list<oglplus::limit_query>
> enum_value::max_draw_buffers;
#endif

#ifdef GL_MAX_DUAL_SOURCE_DRAW_BUFFERS
const enum_value<
	GLenum,
	GL_MAX_DUAL_SOURCE_DRAW_BUFFERS,
	mp_list<oglplus::limit_query>
> enum_value::max_dual_source_draw_buffers;
#endif

#ifdef GL_MAX_ELEMENTS_INDICES
const enum_value<
	GLenum,
	GL_MAX_ELEMENTS_INDICES,
	mp_list<oglplus::limit_query>
> enum_value::max_elements_indices;
#endif

#ifdef GL_MAX_ELEMENTS_VERTICES
const enum_value<
	GLenum,
	GL_MAX_ELEMENTS_VERTICES,
	mp_list<oglplus::limit_query>
> enum_value::max_elements_vertices;
#endif

#ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS
const enum_value<
	GLenum,
	GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS,
	mp_list<oglplus::limit_query>
> enum_value::max_fragment_atomic_counter_buffers;
#endif

#ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTERS
const enum_value<
	GLenum,
	GL_MAX_FRAGMENT_ATOMIC_COUNTERS,
	mp_list<oglplus::limit_query>
> enum_value::max_fragment_atomic_counters;
#endif

#ifdef GL_MAX_FRAGMENT_IMAGE_UNIFORMS
const enum_value<
	GLenum,
	GL_MAX_FRAGMENT_IMAGE_UNIFORMS,
	mp_list<oglplus::limit_query>
> enum_value::max_fragment_image_uniforms;
#endif

#ifdef GL_MAX_FRAGMENT_INPUT_COMPONENTS
const enum_value<
	GLenum,
	GL_MAX_FRAGMENT_INPUT_COMPONENTS,
	mp_list<oglplus::limit_query>
> enum_value::max_fragment_input_components;
#endif

#ifdef GL_MAX_FRAGMENT_INTERPOLATION_OFFSET
const enum_value<
	GLenum,
	GL_MAX_FRAGMENT_INTERPOLATION_OFFSET,
	mp_list<oglplus::limit_query>
> enum_value::max_fragment_interpolation_offset;
#endif

#ifdef GL_MAX_FRAGMENT_UNIFORM_BLOCKS
const enum_value<
	GLenum,
	GL_MAX_FRAGMENT_UNIFORM_BLOCKS,
	mp_list<oglplus::limit_query>
> enum_value::max_fragment_uniform_blocks;
#endif

#ifdef GL_MAX_FRAGMENT_UNIFORM_COMPONENTS
const enum_value<
	GLenum,
	GL_MAX_FRAGMENT_UNIFORM_COMPONENTS,
	mp_list<oglplus::limit_query>
> enum_value::max_fragment_uniform_components;
#endif

#ifdef GL_MAX_FRAGMENT_UNIFORM_VECTORS
const enum_value<
	GLenum,
	GL_MAX_FRAGMENT_UNIFORM_VECTORS,
	mp_list<oglplus::limit_query>
> enum_value::max_fragment_uniform_vectors;
#endif

#ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS
const enum_value<
	GLenum,
	GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS,
	mp_list<oglplus::limit_query>
> enum_value::max_geometry_atomic_counter_buffers;
#endif

#ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTERS
const enum_value<
	GLenum,
	GL_MAX_GEOMETRY_ATOMIC_COUNTERS,
	mp_list<oglplus::limit_query>
> enum_value::max_geometry_atomic_counters;
#endif

#ifdef GL_MAX_GEOMETRY_IMAGE_UNIFORMS
const enum_value<
	GLenum,
	GL_MAX_GEOMETRY_IMAGE_UNIFORMS,
	mp_list<oglplus::limit_query>
> enum_value::max_geometry_image_uniforms;
#endif

#ifdef GL_MAX_GEOMETRY_INPUT_COMPONENTS
const enum_value<
	GLenum,
	GL_MAX_GEOMETRY_INPUT_COMPONENTS,
	mp_list<oglplus::limit_query>
> enum_value::max_geometry_input_components;
#endif

#ifdef GL_MAX_GEOMETRY_OUTPUT_COMPONENTS
const enum_value<
	GLenum,
	GL_MAX_GEOMETRY_OUTPUT_COMPONENTS,
	mp_list<oglplus::limit_query>
> enum_value::max_geometry_output_components;
#endif

#ifdef GL_MAX_GEOMETRY_OUTPUT_VERTICES
const enum_value<
	GLenum,
	GL_MAX_GEOMETRY_OUTPUT_VERTICES,
	mp_list<oglplus::limit_query>
> enum_value::max_geometry_output_vertices;
#endif

#ifdef GL_MAX_GEOMETRY_SHADER_INVOCATIONS
const enum_value<
	GLenum,
	GL_MAX_GEOMETRY_SHADER_INVOCATIONS,
	mp_list<oglplus::limit_query>
> enum_value::max_geometry_shader_invocations;
#endif

#ifdef GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS
const enum_value<
	GLenum,
	GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS,
	mp_list<oglplus::limit_query>
> enum_value::max_geometry_texture_image_units;
#endif

#ifdef GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS
const enum_value<
	GLenum,
	GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS,
	mp_list<oglplus::limit_query>
> enum_value::max_geometry_total_output_components;
#endif

#ifdef GL_MAX_GEOMETRY_UNIFORM_BLOCKS
const enum_value<
	GLenum,
	GL_MAX_GEOMETRY_UNIFORM_BLOCKS,
	mp_list<oglplus::limit_query>
> enum_value::max_geometry_uniform_blocks;
#endif

#ifdef GL_MAX_GEOMETRY_UNIFORM_COMPONENTS
const enum_value<
	GLenum,
	GL_MAX_GEOMETRY_UNIFORM_COMPONENTS,
	mp_list<oglplus::limit_query>
> enum_value::max_geometry_uniform_components;
#endif

#ifdef GL_MAX_IMAGE_SAMPLES
const enum_value<
	GLenum,
	GL_MAX_IMAGE_SAMPLES,
	mp_list<oglplus::limit_query>
> enum_value::max_image_samples;
#endif

#ifdef GL_MAX_IMAGE_UNITS
const enum_value<
	GLenum,
	GL_MAX_IMAGE_UNITS,
	mp_list<oglplus::limit_query>
> enum_value::max_image_units;
#endif

#ifdef GL_MAX_INTEGER_SAMPLES
const enum_value<
	GLenum,
	GL_MAX_INTEGER_SAMPLES,
	mp_list<oglplus::limit_query>
> enum_value::max_integer_samples;
#endif

#ifdef GL_MAX_PATCH_VERTICES
const enum_value<
	GLenum,
	GL_MAX_PATCH_VERTICES,
	mp_list<oglplus::limit_query>
> enum_value::max_patch_vertices;
#endif

#ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
const enum_value<
	GLenum,
	GL_MAX_PROGRAM_TEXEL_OFFSET,
	mp_list<oglplus::limit_query>
> enum_value::max_program_texel_offset;
#endif

#ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
const enum_value<
	GLenum,
	GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET,
	mp_list<oglplus::limit_query>
> enum_value::max_program_texture_gather_offset;
#endif

#ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
const enum_value<
	GLenum,
	GL_MAX_RECTANGLE_TEXTURE_SIZE,
	mp_list<oglplus::limit_query>
> enum_value::max_rectangle_texture_size;
#endif

#ifdef GL_MAX_RENDERBUFFER_SIZE
const enum_value<
	GLenum,
	GL_MAX_RENDERBUFFER_SIZE,
	mp_list<oglplus::limit_query>
> enum_value::max_renderbuffer_size;
#endif

#ifdef GL_MAX_SAMPLE_MASK_WORDS
const enum_value<
	GLenum,
	GL_MAX_SAMPLE_MASK_WORDS,
	mp_list<oglplus::limit_query>
> enum_value::max_sample_mask_words;
#endif

#ifdef GL_MAX_SAMPLES
const enum_value<
	GLenum,
	GL_MAX_SAMPLES,
	mp_list<oglplus::limit_query>
> enum_value::max_samples;
#endif

#ifdef GL_MAX_SERVER_WAIT_TIMEOUT
const enum_value<
	GLenum,
	GL_MAX_SERVER_WAIT_TIMEOUT,
	mp_list<oglplus::limit_query>
> enum_value::max_server_wait_timeout;
#endif

#ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
const enum_value<
	GLenum,
	GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS,
	mp_list<oglplus::limit_query>
> enum_value::max_subroutine_uniform_locations;
#endif

#ifdef GL_MAX_SUBROUTINES
const enum_value<
	GLenum,
	GL_MAX_SUBROUTINES,
	mp_list<oglplus::limit_query>
> enum_value::max_subroutines;
#endif

#ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
const enum_value<
	GLenum,
	GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS,
	mp_list<oglplus::limit_query>
> enum_value::max_tess_control_atomic_counter_buffers;
#endif

#ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
const enum_value<
	GLenum,
	GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS,
	mp_list<oglplus::limit_query>
> enum_value::max_tess_control_atomic_counters;
#endif

#ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
const enum_value<
	GLenum,
	GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS,
	mp_list<oglplus::limit_query>
> enum_value::max_tess_control_image_uniforms;
#endif

#ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
const enum_value<
	GLenum,
	GL_MAX_TESS_CONTROL_INPUT_COMPONENTS,
	mp_list<oglplus::limit_query>
> enum_value::max_tess_control_input_components;
#endif

#ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
const enum_value<
	GLenum,
	GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS,
	mp_list<oglplus::limit_query>
> enum_value::max_tess_control_output_components;
#endif

#ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
const enum_value<
	GLenum,
	GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS,
	mp_list<oglplus::limit_query>
> enum_value::max_tess_control_texture_image_units;
#endif

#ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
const enum_value<
	GLenum,
	GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS,
	mp_list<oglplus::limit_query>
> enum_value::max_tess_control_total_output_components;
#endif

#ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
const enum_value<
	GLenum,
	GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS,
	mp_list<oglplus::limit_query>
> enum_value::max_tess_control_uniform_blocks;
#endif

#ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
const enum_value<
	GLenum,
	GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS,
	mp_list<oglplus::limit_query>
> enum_value::max_tess_control_uniform_components;
#endif

#ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
const enum_value<
	GLenum,
	GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS,
	mp_list<oglplus::limit_query>
> enum_value::max_tess_evaluation_atomic_counter_buffers;
#endif

#ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
const enum_value<
	GLenum,
	GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS,
	mp_list<oglplus::limit_query>
> enum_value::max_tess_evaluation_atomic_counters;
#endif

#ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
const enum_value<
	GLenum,
	GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS,
	mp_list<oglplus::limit_query>
> enum_value::max_tess_evaluation_image_uniforms;
#endif

#ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
const enum_value<
	GLenum,
	GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS,
	mp_list<oglplus::limit_query>
> enum_value::max_tess_evaluation_input_components;
#endif

#ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
const enum_value<
	GLenum,
	GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS,
	mp_list<oglplus::limit_query>
> enum_value::max_tess_evaluation_output_components;
#endif

#ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
const enum_value<
	GLenum,
	GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS,
	mp_list<oglplus::limit_query>
> enum_value::max_tess_evaluation_texture_image_units;
#endif

#ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
const enum_value<
	GLenum,
	GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS,
	mp_list<oglplus::limit_query>
> enum_value::max_tess_evaluation_uniform_blocks;
#endif

#ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
const enum_value<
	GLenum,
	GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS,
	mp_list<oglplus::limit_query>
> enum_value::max_tess_evaluation_uniform_components;
#endif

#ifdef GL_MAX_TESS_GEN_LEVEL
const enum_value<
	GLenum,
	GL_MAX_TESS_GEN_LEVEL,
	mp_list<oglplus::limit_query>
> enum_value::max_tess_gen_level;
#endif

#ifdef GL_MAX_TESS_PATCH_COMPONENTS
const enum_value<
	GLenum,
	GL_MAX_TESS_PATCH_COMPONENTS,
	mp_list<oglplus::limit_query>
> enum_value::max_tess_patch_components;
#endif

#ifdef GL_MAX_TEXTURE_BUFFER_SIZE
const enum_value<
	GLenum,
	GL_MAX_TEXTURE_BUFFER_SIZE,
	mp_list<oglplus::limit_query>
> enum_value::max_texture_buffer_size;
#endif

#ifdef GL_MAX_TEXTURE_IMAGE_UNITS
const enum_value<
	GLenum,
	GL_MAX_TEXTURE_IMAGE_UNITS,
	mp_list<oglplus::limit_query>
> enum_value::max_texture_image_units;
#endif

#ifdef GL_MAX_TEXTURE_LOD_BIAS
const enum_value<
	GLenum,
	GL_MAX_TEXTURE_LOD_BIAS,
	mp_list<oglplus::limit_query>
> enum_value::max_texture_lod_bias;
#endif

#ifdef GL_MAX_TEXTURE_SIZE
const enum_value<
	GLenum,
	GL_MAX_TEXTURE_SIZE,
	mp_list<oglplus::limit_query>
> enum_value::max_texture_size;
#endif

#ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
const enum_value<
	GLenum,
	GL_MAX_TRANSFORM_FEEDBACK_BUFFERS,
	mp_list<oglplus::limit_query>
> enum_value::max_transform_feedback_buffers;
#endif

#ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
const enum_value<
	GLenum,
	GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS,
	mp_list<oglplus::limit_query>
> enum_value::max_transform_feedback_interleaved_components;
#endif

#ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
const enum_value<
	GLenum,
	GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS,
	mp_list<oglplus::limit_query>
> enum_value::max_transform_feedback_separate_attribs;
#endif

#ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
const enum_value<
	GLenum,
	GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS,
	mp_list<oglplus::limit_query>
> enum_value::max_transform_feedback_separate_components;
#endif

#ifdef GL_MAX_UNIFORM_BLOCK_SIZE
const enum_value<
	GLenum,
	GL_MAX_UNIFORM_BLOCK_SIZE,
	mp_list<oglplus::limit_query>
> enum_value::max_uniform_block_size;
#endif

#ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
const enum_value<
	GLenum,
	GL_MAX_UNIFORM_BUFFER_BINDINGS,
	mp_list<oglplus::limit_query>
> enum_value::max_uniform_buffer_bindings;
#endif

#ifdef GL_MAX_VARYING_COMPONENTS
const enum_value<
	GLenum,
	GL_MAX_VARYING_COMPONENTS,
	mp_list<oglplus::limit_query>
> enum_value::max_varying_components;
#endif

#ifdef GL_MAX_VARYING_VECTORS
const enum_value<
	GLenum,
	GL_MAX_VARYING_VECTORS,
	mp_list<oglplus::limit_query>
> enum_value::max_varying_vectors;
#endif

#ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
const enum_value<
	GLenum,
	GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS,
	mp_list<oglplus::limit_query>
> enum_value::max_vertex_atomic_counter_buffers;
#endif

#ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
const enum_value<
	GLenum,
	GL_MAX_VERTEX_ATOMIC_COUNTERS,
	mp_list<oglplus::limit_query>
> enum_value::max_vertex_atomic_counters;
#endif

#ifdef GL_MAX_VERTEX_ATTRIBS
const enum_value<
	GLenum,
	GL_MAX_VERTEX_ATTRIBS,
	mp_list<oglplus::limit_query>
> enum_value::max_vertex_attribs;
#endif

#ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
const enum_value<
	GLenum,
	GL_MAX_VERTEX_IMAGE_UNIFORMS,
	mp_list<oglplus::limit_query>
> enum_value::max_vertex_image_uniforms;
#endif

#ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
const enum_value<
	GLenum,
	GL_MAX_VERTEX_OUTPUT_COMPONENTS,
	mp_list<oglplus::limit_query>
> enum_value::max_vertex_output_components;
#endif

#ifdef GL_MAX_VERTEX_STREAMS
const enum_value<
	GLenum,
	GL_MAX_VERTEX_STREAMS,
	mp_list<oglplus::limit_query>
> enum_value::max_vertex_streams;
#endif

#ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
const enum_value<
	GLenum,
	GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS,
	mp_list<oglplus::limit_query>
> enum_value::max_vertex_texture_image_units;
#endif

#ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
const enum_value<
	GLenum,
	GL_MAX_VERTEX_UNIFORM_BLOCKS,
	mp_list<oglplus::limit_query>
> enum_value::max_vertex_uniform_blocks;
#endif

#ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
const enum_value<
	GLenum,
	GL_MAX_VERTEX_UNIFORM_COMPONENTS,
	mp_list<oglplus::limit_query>
> enum_value::max_vertex_uniform_components;
#endif

#ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
const enum_value<
	GLenum,
	GL_MAX_VERTEX_UNIFORM_VECTORS,
	mp_list<oglplus::limit_query>
> enum_value::max_vertex_uniform_vectors;
#endif

#ifdef GL_MAX_VIEWPORT_DIMS
const enum_value<
	GLenum,
	GL_MAX_VIEWPORT_DIMS,
	mp_list<oglplus::limit_query>
> enum_value::max_viewport_dims;
#endif

#ifdef GL_MAX_VIEWPORTS
const enum_value<
	GLenum,
	GL_MAX_VIEWPORTS,
	mp_list<oglplus::limit_query>
> enum_value::max_viewports;
#endif

#ifdef GL_MEDIUM_FLOAT
const enum_value<
	GLenum,
	GL_MEDIUM_FLOAT,
	mp_list<oglplus::precision_type>
> enum_value::medium_float;
#endif

#ifdef GL_MEDIUM_INT
const enum_value<
	GLenum,
	GL_MEDIUM_INT,
	mp_list<oglplus::precision_type>
> enum_value::medium_int;
#endif

#ifdef GL_MIN
const enum_value<
	GLenum,
	GL_MIN,
	mp_list<oglplus::blend_equation>
> enum_value::min;
#endif

#ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
const enum_value<
	GLenum,
	GL_MIN_FRAGMENT_INTERPOLATION_OFFSET,
	mp_list<oglplus::limit_query>
> enum_value::min_fragment_interpolation_offset;
#endif

#ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
const enum_value<
	GLenum,
	GL_MIN_MAP_BUFFER_ALIGNMENT,
	mp_list<oglplus::limit_query>
> enum_value::min_map_buffer_alignment;
#endif

#ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
const enum_value<
	GLenum,
	GL_MIN_PROGRAM_TEXEL_OFFSET,
	mp_list<oglplus::limit_query>
> enum_value::min_program_texel_offset;
#endif

#ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
const enum_value<
	GLenum,
	GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET,
	mp_list<oglplus::limit_query>
> enum_value::min_program_texture_gather_offset;
#endif

#ifdef GL_MIRROR_CLAMP_TO_EDGE
const enum_value<
	GLenum,
	GL_MIRROR_CLAMP_TO_EDGE,
	mp_list<oglplus::texture_wrap_mode>
> enum_value::mirror_clamp_to_edge;
#endif

#ifdef GL_MIRRORED_REPEAT
const enum_value<
	GLenum,
	GL_MIRRORED_REPEAT,
	mp_list<oglplus::texture_wrap_mode>
> enum_value::mirrored_repeat;
#endif

#ifdef GL_MITER_REVERT_NV
const enum_value<
	GLenum,
	GL_MITER_REVERT_NV,
	mp_list<oglplus::path_join_style_nv>
> enum_value::miter_revert_nv;
#endif

#ifdef GL_MITER_TRUNCATE_NV
const enum_value<
	GLenum,
	GL_MITER_TRUNCATE_NV,
	mp_list<oglplus::path_join_style_nv>
> enum_value::miter_truncate_nv;
#endif

#ifdef GL_MODELVIEW
const enum_value<
	GLenum,
	GL_MODELVIEW,
	mp_list<oglplus::old_matrix_mode>
> enum_value::modelview;
#endif

#ifdef GL_MOVE_TO_CONTINUES_NV
const enum_value<
	GLenum,
	GL_MOVE_TO_CONTINUES_NV,
	mp_list<oglplus::path_dash_offset_reset_nv>
> enum_value::move_to_continues_nv;
#endif

#ifdef GL_MOVE_TO_NV
const enum_value<
	GLubyte,
	GL_MOVE_TO_NV,
	mp_list<oglplus::path_command_nv>
> enum_value::move_to_nv;
#endif

#ifdef GL_MOVE_TO_RESET_NV
const enum_value<
	GLenum,
	GL_MOVE_TO_RESET_NV,
	mp_list<oglplus::path_dash_offset_reset_nv>
> enum_value::move_to_reset_nv;
#endif

#ifdef GL_MULTIPLY_KHR
const enum_value<
	GLenum,
	GL_MULTIPLY_KHR,
	mp_list<oglplus::blend_equation_advanced>
> enum_value::multiply_khr;
#endif

#ifdef GL_MULTISAMPLE
const enum_value<
	GLenum,
	GL_MULTISAMPLE,
	mp_list<oglplus::capability>
> enum_value::multisample;
#endif

#ifdef GL_NAND
const enum_value<
	GLenum,
	GL_NAND,
	mp_list<oglplus::color_logic_operation>
> enum_value::nand;
#endif

#ifdef GL_NEAREST
const enum_value<
	GLenum,
	GL_NEAREST,
	mp_list<oglplus::texture_mag_filter,oglplus::blit_filter,oglplus::texture_filter,oglplus::texture_min_filter>
> enum_value::nearest;
#endif

#ifdef GL_NEAREST_MIPMAP_LINEAR
const enum_value<
	GLenum,
	GL_NEAREST_MIPMAP_LINEAR,
	mp_list<oglplus::texture_min_filter>
> enum_value::nearest_mipmap_linear;
#endif

#ifdef GL_NEAREST_MIPMAP_NEAREST
const enum_value<
	GLenum,
	GL_NEAREST_MIPMAP_NEAREST,
	mp_list<oglplus::texture_min_filter>
> enum_value::nearest_mipmap_nearest;
#endif

#ifdef GL_NEGATIVE_ONE_TO_ONE
const enum_value<
	GLenum,
	GL_NEGATIVE_ONE_TO_ONE,
	mp_list<oglplus::clip_depth_mode>
> enum_value::negative_one_to_one;
#endif

#ifdef GL_NEVER
const enum_value<
	GLenum,
	GL_NEVER,
	mp_list<oglplus::compare_function>
> enum_value::never;
#endif

#ifdef GL_NICEST
const enum_value<
	GLenum,
	GL_NICEST,
	mp_list<oglplus::hint_option>
> enum_value::nicest;
#endif

#ifdef GL_NO_ERROR
const enum_value<
	GLenum,
	GL_NO_ERROR,
	mp_list<oglplus::graphics_reset_status,oglplus::error_code>
> enum_value::no_error;
#endif

#ifdef GL_NO_RESET_NOTIFICATION
const enum_value<
	GLenum,
	GL_NO_RESET_NOTIFICATION,
	mp_list<oglplus::reset_notification_strategy>
> enum_value::no_reset_notification;
#endif

#ifdef GL_NONE
const enum_value<
	GLenum,
	GL_NONE,
	mp_list<oglplus::sl_data_type,oglplus::context_release_behavior,oglplus::color_buffer,oglplus::object_type,oglplus::texture_compare_mode,oglplus::path_transform_type_nv,oglplus::path_join_style_nv,oglplus::path_gen_mode_nv>
> enum_value::none;
#endif

#ifdef GL_NOOP
const enum_value<
	GLenum,
	GL_NOOP,
	mp_list<oglplus::color_logic_operation>
> enum_value::noop;
#endif

#ifdef GL_NOR
const enum_value<
	GLenum,
	GL_NOR,
	mp_list<oglplus::color_logic_operation>
> enum_value::nor;
#endif

#ifdef GL_NOTEQUAL
const enum_value<
	GLenum,
	GL_NOTEQUAL,
	mp_list<oglplus::compare_function>
> enum_value::notequal;
#endif

#ifdef GL_NUM_ACTIVE_VARIABLES
const enum_value<
	GLenum,
	GL_NUM_ACTIVE_VARIABLES,
	mp_list<oglplus::program_resource_property>
> enum_value::num_active_variables;
#endif

#ifdef GL_NUM_COMPATIBLE_SUBROUTINES
const enum_value<
	GLenum,
	GL_NUM_COMPATIBLE_SUBROUTINES,
	mp_list<oglplus::program_resource_property>
> enum_value::num_compatible_subroutines;
#endif

#ifdef GL_NUM_COMPRESSED_TEXTURE_FORMATS
const enum_value<
	GLenum,
	GL_NUM_COMPRESSED_TEXTURE_FORMATS,
	mp_list<oglplus::numeric_query>
> enum_value::num_compressed_texture_formats;
#endif

#ifdef GL_NUM_EXTENSIONS
const enum_value<
	GLenum,
	GL_NUM_EXTENSIONS,
	mp_list<oglplus::numeric_query>
> enum_value::num_extensions;
#endif

#ifdef GL_NUM_PROGRAM_BINARY_FORMATS
const enum_value<
	GLenum,
	GL_NUM_PROGRAM_BINARY_FORMATS,
	mp_list<oglplus::numeric_query>
> enum_value::num_program_binary_formats;
#endif

#ifdef GL_NUM_SHADER_BINARY_FORMATS
const enum_value<
	GLenum,
	GL_NUM_SHADER_BINARY_FORMATS,
	mp_list<oglplus::numeric_query>
> enum_value::num_shader_binary_formats;
#endif

#ifdef GL_OBJECT_LINEAR
const enum_value<
	GLenum,
	GL_OBJECT_LINEAR,
	mp_list<oglplus::path_gen_mode_nv>
> enum_value::object_linear;
#endif

#ifdef GL_OFFSET
const enum_value<
	GLenum,
	GL_OFFSET,
	mp_list<oglplus::program_resource_property>
> enum_value::offset;
#endif

#ifdef GL_ONE
const enum_value<
	GLenum,
	GL_ONE,
	mp_list<oglplus::blend_function,oglplus::texture_swizzle_mode>
> enum_value::one;
#endif

#ifdef GL_ONE_MINUS_CONSTANT_ALPHA
const enum_value<
	GLenum,
	GL_ONE_MINUS_CONSTANT_ALPHA,
	mp_list<oglplus::blend_function>
> enum_value::one_minus_constant_alpha;
#endif

#ifdef GL_ONE_MINUS_CONSTANT_COLOR
const enum_value<
	GLenum,
	GL_ONE_MINUS_CONSTANT_COLOR,
	mp_list<oglplus::blend_function>
> enum_value::one_minus_constant_color;
#endif

#ifdef GL_ONE_MINUS_DST_ALPHA
const enum_value<
	GLenum,
	GL_ONE_MINUS_DST_ALPHA,
	mp_list<oglplus::blend_function>
> enum_value::one_minus_dst_alpha;
#endif

#ifdef GL_ONE_MINUS_DST_COLOR
const enum_value<
	GLenum,
	GL_ONE_MINUS_DST_COLOR,
	mp_list<oglplus::blend_function>
> enum_value::one_minus_dst_color;
#endif

#ifdef GL_ONE_MINUS_SRC1_ALPHA
const enum_value<
	GLenum,
	GL_ONE_MINUS_SRC1_ALPHA,
	mp_list<oglplus::blend_function>
> enum_value::one_minus_src1_alpha;
#endif

#ifdef GL_ONE_MINUS_SRC1_COLOR
const enum_value<
	GLenum,
	GL_ONE_MINUS_SRC1_COLOR,
	mp_list<oglplus::blend_function>
> enum_value::one_minus_src1_color;
#endif

#ifdef GL_ONE_MINUS_SRC_ALPHA
const enum_value<
	GLenum,
	GL_ONE_MINUS_SRC_ALPHA,
	mp_list<oglplus::blend_function>
> enum_value::one_minus_src_alpha;
#endif

#ifdef GL_ONE_MINUS_SRC_COLOR
const enum_value<
	GLenum,
	GL_ONE_MINUS_SRC_COLOR,
	mp_list<oglplus::blend_function>
> enum_value::one_minus_src_color;
#endif

#ifdef GL_OR
const enum_value<
	GLenum,
	GL_OR,
	mp_list<oglplus::color_logic_operation>
> enum_value::or_;
#endif

#ifdef GL_OR_INVERTED
const enum_value<
	GLenum,
	GL_OR_INVERTED,
	mp_list<oglplus::color_logic_operation>
> enum_value::or_inverted;
#endif

#ifdef GL_OR_REVERSE
const enum_value<
	GLenum,
	GL_OR_REVERSE,
	mp_list<oglplus::color_logic_operation>
> enum_value::or_reverse;
#endif

#ifdef GL_OUT_OF_MEMORY
const enum_value<
	GLenum,
	GL_OUT_OF_MEMORY,
	mp_list<oglplus::error_code>
> enum_value::out_of_memory;
#endif

#ifdef GL_OVERLAY_KHR
const enum_value<
	GLenum,
	GL_OVERLAY_KHR,
	mp_list<oglplus::blend_equation_advanced>
> enum_value::overlay_khr;
#endif

#ifdef GL_PACK_ALIGNMENT
const enum_value<
	GLenum,
	GL_PACK_ALIGNMENT,
	mp_list<oglplus::numeric_query,oglplus::pixel_parameter>
> enum_value::pack_alignment;
#endif

#ifdef GL_PACK_COMPRESSED_BLOCK_DEPTH
const enum_value<
	GLenum,
	GL_PACK_COMPRESSED_BLOCK_DEPTH,
	mp_list<oglplus::pixel_parameter>
> enum_value::pack_compressed_block_depth;
#endif

#ifdef GL_PACK_COMPRESSED_BLOCK_HEIGHT
const enum_value<
	GLenum,
	GL_PACK_COMPRESSED_BLOCK_HEIGHT,
	mp_list<oglplus::pixel_parameter>
> enum_value::pack_compressed_block_height;
#endif

#ifdef GL_PACK_COMPRESSED_BLOCK_SIZE
const enum_value<
	GLenum,
	GL_PACK_COMPRESSED_BLOCK_SIZE,
	mp_list<oglplus::pixel_parameter>
> enum_value::pack_compressed_block_size;
#endif

#ifdef GL_PACK_COMPRESSED_BLOCK_WIDTH
const enum_value<
	GLenum,
	GL_PACK_COMPRESSED_BLOCK_WIDTH,
	mp_list<oglplus::pixel_parameter>
> enum_value::pack_compressed_block_width;
#endif

#ifdef GL_PACK_IMAGE_HEIGHT
const enum_value<
	GLenum,
	GL_PACK_IMAGE_HEIGHT,
	mp_list<oglplus::numeric_query,oglplus::pixel_parameter>
> enum_value::pack_image_height;
#endif

#ifdef GL_PACK_LSB_FIRST
const enum_value<
	GLenum,
	GL_PACK_LSB_FIRST,
	mp_list<oglplus::numeric_query,oglplus::pixel_parameter>
> enum_value::pack_lsb_first;
#endif

#ifdef GL_PACK_ROW_LENGTH
const enum_value<
	GLenum,
	GL_PACK_ROW_LENGTH,
	mp_list<oglplus::numeric_query,oglplus::pixel_parameter>
> enum_value::pack_row_length;
#endif

#ifdef GL_PACK_SKIP_IMAGES
const enum_value<
	GLenum,
	GL_PACK_SKIP_IMAGES,
	mp_list<oglplus::numeric_query,oglplus::pixel_parameter>
> enum_value::pack_skip_images;
#endif

#ifdef GL_PACK_SKIP_PIXELS
const enum_value<
	GLenum,
	GL_PACK_SKIP_PIXELS,
	mp_list<oglplus::numeric_query,oglplus::pixel_parameter>
> enum_value::pack_skip_pixels;
#endif

#ifdef GL_PACK_SKIP_ROWS
const enum_value<
	GLenum,
	GL_PACK_SKIP_ROWS,
	mp_list<oglplus::numeric_query,oglplus::pixel_parameter>
> enum_value::pack_skip_rows;
#endif

#ifdef GL_PACK_SWAP_BYTES
const enum_value<
	GLenum,
	GL_PACK_SWAP_BYTES,
	mp_list<oglplus::numeric_query,oglplus::pixel_parameter>
> enum_value::pack_swap_bytes;
#endif

#ifdef GL_PARAMETER_BUFFER_ARB
const enum_value<
	GLenum,
	GL_PARAMETER_BUFFER_ARB,
	mp_list<oglplus::buffer_target>
> enum_value::parameter_buffer;
#endif

#ifdef GL_PARAMETER_BUFFER_BINDING_ARB
const enum_value<
	GLenum,
	GL_PARAMETER_BUFFER_BINDING_ARB,
	mp_list<oglplus::binding_query>
> enum_value::parameter_buffer_binding;
#endif

#ifdef GL_PATCH_DEFAULT_INNER_LEVEL
const enum_value<
	GLenum,
	GL_PATCH_DEFAULT_INNER_LEVEL,
	mp_list<oglplus::patch_parameter>
> enum_value::patch_default_inner_level;
#endif

#ifdef GL_PATCH_DEFAULT_OUTER_LEVEL
const enum_value<
	GLenum,
	GL_PATCH_DEFAULT_OUTER_LEVEL,
	mp_list<oglplus::patch_parameter>
> enum_value::patch_default_outer_level;
#endif

#ifdef GL_PATCH_VERTICES
const enum_value<
	GLenum,
	GL_PATCH_VERTICES,
	mp_list<oglplus::patch_parameter>
> enum_value::patch_vertices;
#endif

#ifdef GL_PATCHES
const enum_value<
	GLenum,
	GL_PATCHES,
	mp_list<oglplus::primitive_type>
> enum_value::patches;
#endif

#ifdef GL_PATH_CLIENT_LENGTH_NV
const enum_value<
	GLenum,
	GL_PATH_CLIENT_LENGTH_NV,
	mp_list<oglplus::path_parameter_nv>
> enum_value::path_client_length_nv;
#endif

#ifdef GL_PATH_COMMAND_COUNT_NV
const enum_value<
	GLenum,
	GL_PATH_COMMAND_COUNT_NV,
	mp_list<oglplus::path_parameter_nv>
> enum_value::path_command_count_nv;
#endif

#ifdef GL_PATH_COMPUTED_LENGTH_NV
const enum_value<
	GLenum,
	GL_PATH_COMPUTED_LENGTH_NV,
	mp_list<oglplus::path_parameter_nv>
> enum_value::path_computed_length_nv;
#endif

#ifdef GL_PATH_COORD_COUNT_NV
const enum_value<
	GLenum,
	GL_PATH_COORD_COUNT_NV,
	mp_list<oglplus::path_parameter_nv>
> enum_value::path_coord_count_nv;
#endif

#ifdef GL_PATH_DASH_ARRAY_COUNT_NV
const enum_value<
	GLenum,
	GL_PATH_DASH_ARRAY_COUNT_NV,
	mp_list<oglplus::path_parameter_nv>
> enum_value::path_dash_array_count_nv;
#endif

#ifdef GL_PATH_DASH_OFFSET_NV
const enum_value<
	GLenum,
	GL_PATH_DASH_OFFSET_NV,
	mp_list<oglplus::path_parameter_nv>
> enum_value::path_dash_offset_nv;
#endif

#ifdef GL_PATH_DASH_OFFSET_RESET_NV
const enum_value<
	GLenum,
	GL_PATH_DASH_OFFSET_RESET_NV,
	mp_list<oglplus::path_parameter_nv>
> enum_value::path_dash_offset_reset_nv;
#endif

#ifdef GL_PATH_FILL_BOUNDING_BOX_NV
const enum_value<
	GLenum,
	GL_PATH_FILL_BOUNDING_BOX_NV,
	mp_list<oglplus::path_parameter_nv>
> enum_value::path_fill_bounding_box_nv;
#endif

#ifdef GL_PATH_FILL_COVER_MODE_NV
const enum_value<
	GLenum,
	GL_PATH_FILL_COVER_MODE_NV,
	mp_list<oglplus::path_fill_cover_mode_nv,oglplus::path_parameter_nv>
> enum_value::path_fill_cover_mode_nv;
#endif

#ifdef GL_PATH_FILL_MASK_NV
const enum_value<
	GLenum,
	GL_PATH_FILL_MASK_NV,
	mp_list<oglplus::path_parameter_nv>
> enum_value::path_fill_mask_nv;
#endif

#ifdef GL_PATH_FILL_MODE_NV
const enum_value<
	GLenum,
	GL_PATH_FILL_MODE_NV,
	mp_list<oglplus::path_fill_mode_nv,oglplus::path_parameter_nv>
> enum_value::path_fill_mode_nv;
#endif

#ifdef GL_PATH_FORMAT_PS_NV
const enum_value<
	GLenum,
	GL_PATH_FORMAT_PS_NV,
	mp_list<oglplus::path_format_nv>
> enum_value::path_format_ps_nv;
#endif

#ifdef GL_PATH_FORMAT_SVG_NV
const enum_value<
	GLenum,
	GL_PATH_FORMAT_SVG_NV,
	mp_list<oglplus::path_format_nv>
> enum_value::path_format_svg_nv;
#endif

#ifdef GL_PATH_INITIAL_DASH_CAP_NV
const enum_value<
	GLenum,
	GL_PATH_INITIAL_DASH_CAP_NV,
	mp_list<oglplus::path_parameter_nv>
> enum_value::path_initial_dash_cap_nv;
#endif

#ifdef GL_PATH_INITIAL_END_CAP_NV
const enum_value<
	GLenum,
	GL_PATH_INITIAL_END_CAP_NV,
	mp_list<oglplus::path_parameter_nv>
> enum_value::path_initial_end_cap_nv;
#endif

#ifdef GL_PATH_JOIN_STYLE_NV
const enum_value<
	GLenum,
	GL_PATH_JOIN_STYLE_NV,
	mp_list<oglplus::path_parameter_nv>
> enum_value::path_join_style_nv;
#endif

#ifdef GL_PATH_MITER_LIMIT_NV
const enum_value<
	GLenum,
	GL_PATH_MITER_LIMIT_NV,
	mp_list<oglplus::path_parameter_nv>
> enum_value::path_miter_limit_nv;
#endif

#ifdef GL_PATH_OBJECT_BOUNDING_BOX_NV
const enum_value<
	GLenum,
	GL_PATH_OBJECT_BOUNDING_BOX_NV,
	mp_list<oglplus::path_parameter_nv,oglplus::path_gen_mode_nv>
> enum_value::path_object_bounding_box_nv;
#endif

#ifdef GL_PATH_STROKE_BOUND_NV
const enum_value<
	GLenum,
	GL_PATH_STROKE_BOUND_NV,
	mp_list<oglplus::path_parameter_nv>
> enum_value::path_stroke_bound_nv;
#endif

#ifdef GL_PATH_STROKE_BOUNDING_BOX_NV
const enum_value<
	GLenum,
	GL_PATH_STROKE_BOUNDING_BOX_NV,
	mp_list<oglplus::path_parameter_nv>
> enum_value::path_stroke_bounding_box_nv;
#endif

#ifdef GL_PATH_STROKE_COVER_MODE_NV
const enum_value<
	GLenum,
	GL_PATH_STROKE_COVER_MODE_NV,
	mp_list<oglplus::path_stroke_cover_mode_nv,oglplus::path_parameter_nv>
> enum_value::path_stroke_cover_mode_nv;
#endif

#ifdef GL_PATH_STROKE_MASK_NV
const enum_value<
	GLenum,
	GL_PATH_STROKE_MASK_NV,
	mp_list<oglplus::path_parameter_nv>
> enum_value::path_stroke_mask_nv;
#endif

#ifdef GL_PATH_STROKE_WIDTH_NV
const enum_value<
	GLenum,
	GL_PATH_STROKE_WIDTH_NV,
	mp_list<oglplus::path_parameter_nv>
> enum_value::path_stroke_width_nv;
#endif

#ifdef GL_PATH_TERMINAL_DASH_CAP_NV
const enum_value<
	GLenum,
	GL_PATH_TERMINAL_DASH_CAP_NV,
	mp_list<oglplus::path_parameter_nv>
> enum_value::path_terminal_dash_cap_nv;
#endif

#ifdef GL_PATH_TERMINAL_END_CAP_NV
const enum_value<
	GLenum,
	GL_PATH_TERMINAL_END_CAP_NV,
	mp_list<oglplus::path_parameter_nv>
> enum_value::path_terminal_end_cap_nv;
#endif

#ifdef GL_PIXEL_BUFFER_BARRIER_BIT
const enum_value<
	GLbitfield,
	GL_PIXEL_BUFFER_BARRIER_BIT,
	mp_list<oglplus::memory_barrier_bits>
> enum_value::pixel_buffer_barrier_bit;
#endif

#ifdef GL_PIXEL_PACK_BUFFER
const enum_value<
	GLenum,
	GL_PIXEL_PACK_BUFFER,
	mp_list<oglplus::buffer_target>
> enum_value::pixel_pack_buffer;
#endif

#ifdef GL_PIXEL_PACK_BUFFER_BINDING
const enum_value<
	GLenum,
	GL_PIXEL_PACK_BUFFER_BINDING,
	mp_list<oglplus::binding_query>
> enum_value::pixel_pack_buffer_binding;
#endif

#ifdef GL_PIXEL_UNPACK_BUFFER
const enum_value<
	GLenum,
	GL_PIXEL_UNPACK_BUFFER,
	mp_list<oglplus::buffer_target>
> enum_value::pixel_unpack_buffer;
#endif

#ifdef GL_PIXEL_UNPACK_BUFFER_BINDING
const enum_value<
	GLenum,
	GL_PIXEL_UNPACK_BUFFER_BINDING,
	mp_list<oglplus::binding_query>
> enum_value::pixel_unpack_buffer_binding;
#endif

#ifdef GL_POINT
const enum_value<
	GLenum,
	GL_POINT,
	mp_list<oglplus::polygon_mode>
> enum_value::point;
#endif

#ifdef GL_POINT_FADE_THRESHOLD_SIZE
const enum_value<
	GLenum,
	GL_POINT_FADE_THRESHOLD_SIZE,
	mp_list<oglplus::numeric_query>
> enum_value::point_fade_threshold_size;
#endif

#ifdef GL_POINT_SIZE
const enum_value<
	GLenum,
	GL_POINT_SIZE,
	mp_list<oglplus::numeric_query>
> enum_value::point_size;
#endif

#ifdef GL_POINT_SIZE_GRANULARITY
const enum_value<
	GLenum,
	GL_POINT_SIZE_GRANULARITY,
	mp_list<oglplus::numeric_query>
> enum_value::point_size_granularity;
#endif

#ifdef GL_POINT_SIZE_RANGE
const enum_value<
	GLenum,
	GL_POINT_SIZE_RANGE,
	mp_list<oglplus::numeric_query>
> enum_value::point_size_range;
#endif

#ifdef GL_POINTS
const enum_value<
	GLenum,
	GL_POINTS,
	mp_list<oglplus::primitive_type,oglplus::old_primitive_type,oglplus::transform_feedback_primitive_type>
> enum_value::points;
#endif

#ifdef GL_POLYGON
const enum_value<
	GLenum,
	GL_POLYGON,
	mp_list<oglplus::old_primitive_type>
> enum_value::polygon;
#endif

#ifdef GL_POLYGON_OFFSET_FACTOR
const enum_value<
	GLenum,
	GL_POLYGON_OFFSET_FACTOR,
	mp_list<oglplus::numeric_query>
> enum_value::polygon_offset_factor;
#endif

#ifdef GL_POLYGON_OFFSET_FILL
const enum_value<
	GLenum,
	GL_POLYGON_OFFSET_FILL,
	mp_list<oglplus::capability>
> enum_value::polygon_offset_fill;
#endif

#ifdef GL_POLYGON_OFFSET_LINE
const enum_value<
	GLenum,
	GL_POLYGON_OFFSET_LINE,
	mp_list<oglplus::capability>
> enum_value::polygon_offset_line;
#endif

#ifdef GL_POLYGON_OFFSET_POINT
const enum_value<
	GLenum,
	GL_POLYGON_OFFSET_POINT,
	mp_list<oglplus::capability>
> enum_value::polygon_offset_point;
#endif

#ifdef GL_POLYGON_OFFSET_UNITS
const enum_value<
	GLenum,
	GL_POLYGON_OFFSET_UNITS,
	mp_list<oglplus::numeric_query>
> enum_value::polygon_offset_units;
#endif

#ifdef GL_POLYGON_SMOOTH
const enum_value<
	GLenum,
	GL_POLYGON_SMOOTH,
	mp_list<oglplus::capability>
> enum_value::polygon_smooth;
#endif

#ifdef GL_POLYGON_SMOOTH_HINT
const enum_value<
	GLenum,
	GL_POLYGON_SMOOTH_HINT,
	mp_list<oglplus::hint_target,oglplus::numeric_query>
> enum_value::polygon_smooth_hint;
#endif

#ifdef GL_PRIMARY_COLOR_NV
const enum_value<
	GLenum,
	GL_PRIMARY_COLOR_NV,
	mp_list<oglplus::path_color_nv>
> enum_value::primary_color_nv;
#endif

#ifdef GL_PRIMITIVE_RESTART
const enum_value<
	GLenum,
	GL_PRIMITIVE_RESTART,
	mp_list<oglplus::capability>
> enum_value::primitive_restart;
#endif

#ifdef GL_PRIMITIVE_RESTART_INDEX
const enum_value<
	GLenum,
	GL_PRIMITIVE_RESTART_INDEX,
	mp_list<oglplus::numeric_query>
> enum_value::primitive_restart_index;
#endif

#ifdef GL_PRIMITIVES_GENERATED
const enum_value<
	GLenum,
	GL_PRIMITIVES_GENERATED,
	mp_list<oglplus::query_target>
> enum_value::primitives_generated;
#endif

#ifdef GL_PRIMITIVES_SUBMITTED_ARB
const enum_value<
	GLenum,
	GL_PRIMITIVES_SUBMITTED_ARB,
	mp_list<oglplus::query_target>
> enum_value::primitives_submitted;
#endif

#ifdef GL_PROGRAM
const enum_value<
	GLenum,
	GL_PROGRAM,
	mp_list<oglplus::object_type>
> enum_value::program;
#endif

#ifdef GL_PROGRAM_BINARY_FORMATS
const enum_value<
	GLenum,
	GL_PROGRAM_BINARY_FORMATS,
	mp_list<oglplus::numeric_query>
> enum_value::program_binary_formats;
#endif

#ifdef GL_PROGRAM_INPUT
const enum_value<
	GLenum,
	GL_PROGRAM_INPUT,
	mp_list<oglplus::program_interface>
> enum_value::program_input;
#endif

#ifdef GL_PROGRAM_OUTPUT
const enum_value<
	GLenum,
	GL_PROGRAM_OUTPUT,
	mp_list<oglplus::program_interface>
> enum_value::program_output;
#endif

#ifdef GL_PROGRAM_PIPELINE
const enum_value<
	GLenum,
	GL_PROGRAM_PIPELINE,
	mp_list<oglplus::object_type>
> enum_value::program_pipeline;
#endif

#ifdef GL_PROGRAM_POINT_SIZE
const enum_value<
	GLenum,
	GL_PROGRAM_POINT_SIZE,
	mp_list<oglplus::capability,oglplus::numeric_query>
> enum_value::program_point_size;
#endif

#ifdef GL_PROJECTION
const enum_value<
	GLenum,
	GL_PROJECTION,
	mp_list<oglplus::old_matrix_mode>
> enum_value::projection;
#endif

#ifdef GL_PROVOKING_VERTEX
const enum_value<
	GLenum,
	GL_PROVOKING_VERTEX,
	mp_list<oglplus::numeric_query>
> enum_value::provoking_vertex;
#endif

#ifdef GL_QUAD_STRIP
const enum_value<
	GLenum,
	GL_QUAD_STRIP,
	mp_list<oglplus::old_primitive_type>
> enum_value::quad_strip;
#endif

#ifdef GL_QUADRATIC_CURVE_TO_NV
const enum_value<
	GLubyte,
	GL_QUADRATIC_CURVE_TO_NV,
	mp_list<oglplus::path_command_nv>
> enum_value::quadratic_curve_to_nv;
#endif

#ifdef GL_QUADS
const enum_value<
	GLenum,
	GL_QUADS,
	mp_list<oglplus::old_primitive_type,oglplus::tess_gen_primitive_type>
> enum_value::quads;
#endif

#ifdef GL_QUERY
const enum_value<
	GLenum,
	GL_QUERY,
	mp_list<oglplus::object_type>
> enum_value::query;
#endif

#ifdef GL_QUERY_BUFFER
const enum_value<
	GLenum,
	GL_QUERY_BUFFER,
	mp_list<oglplus::buffer_target>
> enum_value::query_buffer;
#endif

#ifdef GL_QUERY_BUFFER_BINDING
const enum_value<
	GLenum,
	GL_QUERY_BUFFER_BINDING,
	mp_list<oglplus::binding_query>
> enum_value::query_buffer_binding;
#endif

#ifdef GL_QUERY_BY_REGION_NO_WAIT
const enum_value<
	GLenum,
	GL_QUERY_BY_REGION_NO_WAIT,
	mp_list<oglplus::conditional_render_mode>
> enum_value::query_by_region_no_wait;
#endif

#ifdef GL_QUERY_BY_REGION_NO_WAIT_INVERTED
const enum_value<
	GLenum,
	GL_QUERY_BY_REGION_NO_WAIT_INVERTED,
	mp_list<oglplus::conditional_render_mode>
> enum_value::query_by_region_no_wait_inverted;
#endif

#ifdef GL_QUERY_BY_REGION_WAIT
const enum_value<
	GLenum,
	GL_QUERY_BY_REGION_WAIT,
	mp_list<oglplus::conditional_render_mode>
> enum_value::query_by_region_wait;
#endif

#ifdef GL_QUERY_BY_REGION_WAIT_INVERTED
const enum_value<
	GLenum,
	GL_QUERY_BY_REGION_WAIT_INVERTED,
	mp_list<oglplus::conditional_render_mode>
> enum_value::query_by_region_wait_inverted;
#endif

#ifdef GL_QUERY_NO_WAIT
const enum_value<
	GLenum,
	GL_QUERY_NO_WAIT,
	mp_list<oglplus::conditional_render_mode>
> enum_value::query_no_wait;
#endif

#ifdef GL_QUERY_NO_WAIT_INVERTED
const enum_value<
	GLenum,
	GL_QUERY_NO_WAIT_INVERTED,
	mp_list<oglplus::conditional_render_mode>
> enum_value::query_no_wait_inverted;
#endif

#ifdef GL_QUERY_WAIT
const enum_value<
	GLenum,
	GL_QUERY_WAIT,
	mp_list<oglplus::conditional_render_mode>
> enum_value::query_wait;
#endif

#ifdef GL_QUERY_WAIT_INVERTED
const enum_value<
	GLenum,
	GL_QUERY_WAIT_INVERTED,
	mp_list<oglplus::conditional_render_mode>
> enum_value::query_wait_inverted;
#endif

#ifdef GL_R11F_G11F_B10F
const enum_value<
	GLenum,
	GL_R11F_G11F_B10F,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> enum_value::r11f_g11f_b10f;
#endif

#ifdef GL_R16
const enum_value<
	GLenum,
	GL_R16,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> enum_value::r16;
#endif

#ifdef GL_R16_SNORM
const enum_value<
	GLenum,
	GL_R16_SNORM,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> enum_value::r16_snorm;
#endif

#ifdef GL_R16F
const enum_value<
	GLenum,
	GL_R16F,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> enum_value::r16f;
#endif

#ifdef GL_R16I
const enum_value<
	GLenum,
	GL_R16I,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> enum_value::r16i;
#endif

#ifdef GL_R16UI
const enum_value<
	GLenum,
	GL_R16UI,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> enum_value::r16ui;
#endif

#ifdef GL_R32F
const enum_value<
	GLenum,
	GL_R32F,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> enum_value::r32f;
#endif

#ifdef GL_R32I
const enum_value<
	GLenum,
	GL_R32I,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> enum_value::r32i;
#endif

#ifdef GL_R32UI
const enum_value<
	GLenum,
	GL_R32UI,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> enum_value::r32ui;
#endif

#ifdef GL_R3_G3_B2
const enum_value<
	GLenum,
	GL_R3_G3_B2,
	mp_list<oglplus::pixel_data_internal_format>
> enum_value::r3_g3_b2;
#endif

#ifdef GL_R8
const enum_value<
	GLenum,
	GL_R8,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> enum_value::r8;
#endif

#ifdef GL_R8_SNORM
const enum_value<
	GLenum,
	GL_R8_SNORM,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> enum_value::r8_snorm;
#endif

#ifdef GL_R8I
const enum_value<
	GLenum,
	GL_R8I,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> enum_value::r8i;
#endif

#ifdef GL_R8UI
const enum_value<
	GLenum,
	GL_R8UI,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> enum_value::r8ui;
#endif

#ifdef GL_RASTERIZER_DISCARD
const enum_value<
	GLenum,
	GL_RASTERIZER_DISCARD,
	mp_list<oglplus::capability>
> enum_value::rasterizer_discard;
#endif

#ifdef GL_READ_BUFFER
const enum_value<
	GLenum,
	GL_READ_BUFFER,
	mp_list<oglplus::numeric_query>
> enum_value::read_buffer;
#endif

#ifdef GL_READ_FRAMEBUFFER
const enum_value<
	GLenum,
	GL_READ_FRAMEBUFFER,
	mp_list<oglplus::framebuffer_target>
> enum_value::read_framebuffer;
#endif

#ifdef GL_READ_ONLY
const enum_value<
	GLenum,
	GL_READ_ONLY,
	mp_list<oglplus::access_specifier>
> enum_value::read_only;
#endif

#ifdef GL_READ_WRITE
const enum_value<
	GLenum,
	GL_READ_WRITE,
	mp_list<oglplus::access_specifier>
> enum_value::read_write;
#endif

#ifdef GL_RECT_NV
const enum_value<
	GLubyte,
	GL_RECT_NV,
	mp_list<oglplus::path_command_nv>
> enum_value::rect_nv;
#endif

#ifdef GL_RED
const enum_value<
	GLenum,
	GL_RED,
	mp_list<oglplus::texture_swizzle_mode,oglplus::pixel_data_format,oglplus::pixel_data_internal_format>
> enum_value::red;
#endif

#ifdef GL_RED_INTEGER
const enum_value<
	GLenum,
	GL_RED_INTEGER,
	mp_list<oglplus::pixel_data_format>
> enum_value::red_integer;
#endif

#ifdef GL_REFERENCED_BY_COMPUTE_SHADER
const enum_value<
	GLenum,
	GL_REFERENCED_BY_COMPUTE_SHADER,
	mp_list<oglplus::program_resource_property>
> enum_value::referenced_by_compute_shader;
#endif

#ifdef GL_REFERENCED_BY_FRAGMENT_SHADER
const enum_value<
	GLenum,
	GL_REFERENCED_BY_FRAGMENT_SHADER,
	mp_list<oglplus::program_resource_property>
> enum_value::referenced_by_fragment_shader;
#endif

#ifdef GL_REFERENCED_BY_GEOMETRY_SHADER
const enum_value<
	GLenum,
	GL_REFERENCED_BY_GEOMETRY_SHADER,
	mp_list<oglplus::program_resource_property>
> enum_value::referenced_by_geometry_shader;
#endif

#ifdef GL_REFERENCED_BY_TESS_CONTROL_SHADER
const enum_value<
	GLenum,
	GL_REFERENCED_BY_TESS_CONTROL_SHADER,
	mp_list<oglplus::program_resource_property>
> enum_value::referenced_by_tess_control_shader;
#endif

#ifdef GL_REFERENCED_BY_TESS_EVALUATION_SHADER
const enum_value<
	GLenum,
	GL_REFERENCED_BY_TESS_EVALUATION_SHADER,
	mp_list<oglplus::program_resource_property>
> enum_value::referenced_by_tess_evaluation_shader;
#endif

#ifdef GL_REFERENCED_BY_VERTEX_SHADER
const enum_value<
	GLenum,
	GL_REFERENCED_BY_VERTEX_SHADER,
	mp_list<oglplus::program_resource_property>
> enum_value::referenced_by_vertex_shader;
#endif

#ifdef GL_RELATIVE_ARC_TO_NV
const enum_value<
	GLubyte,
	GL_RELATIVE_ARC_TO_NV,
	mp_list<oglplus::path_command_nv>
> enum_value::relative_arc_to_nv;
#endif

#ifdef GL_RELATIVE_CUBIC_CURVE_TO_NV
const enum_value<
	GLubyte,
	GL_RELATIVE_CUBIC_CURVE_TO_NV,
	mp_list<oglplus::path_command_nv>
> enum_value::relative_cubic_curve_to_nv;
#endif

#ifdef GL_RELATIVE_HORIZONTAL_LINE_TO_NV
const enum_value<
	GLubyte,
	GL_RELATIVE_HORIZONTAL_LINE_TO_NV,
	mp_list<oglplus::path_command_nv>
> enum_value::relative_horizontal_line_to_nv;
#endif

#ifdef GL_RELATIVE_LARGE_CCW_ARC_TO_NV
const enum_value<
	GLubyte,
	GL_RELATIVE_LARGE_CCW_ARC_TO_NV,
	mp_list<oglplus::path_command_nv>
> enum_value::relative_large_ccw_arc_to_nv;
#endif

#ifdef GL_RELATIVE_LARGE_CW_ARC_TO_NV
const enum_value<
	GLubyte,
	GL_RELATIVE_LARGE_CW_ARC_TO_NV,
	mp_list<oglplus::path_command_nv>
> enum_value::relative_large_cw_arc_to_nv;
#endif

#ifdef GL_RELATIVE_LINE_TO_NV
const enum_value<
	GLubyte,
	GL_RELATIVE_LINE_TO_NV,
	mp_list<oglplus::path_command_nv>
> enum_value::relative_line_to_nv;
#endif

#ifdef GL_RELATIVE_MOVE_TO_NV
const enum_value<
	GLubyte,
	GL_RELATIVE_MOVE_TO_NV,
	mp_list<oglplus::path_command_nv>
> enum_value::relative_move_to_nv;
#endif

#ifdef GL_RELATIVE_QUADRATIC_CURVE_TO_NV
const enum_value<
	GLubyte,
	GL_RELATIVE_QUADRATIC_CURVE_TO_NV,
	mp_list<oglplus::path_command_nv>
> enum_value::relative_quadratic_curve_to_nv;
#endif

#ifdef GL_RELATIVE_SMALL_CCW_ARC_TO_NV
const enum_value<
	GLubyte,
	GL_RELATIVE_SMALL_CCW_ARC_TO_NV,
	mp_list<oglplus::path_command_nv>
> enum_value::relative_small_ccw_arc_to_nv;
#endif

#ifdef GL_RELATIVE_SMALL_CW_ARC_TO_NV
const enum_value<
	GLubyte,
	GL_RELATIVE_SMALL_CW_ARC_TO_NV,
	mp_list<oglplus::path_command_nv>
> enum_value::relative_small_cw_arc_to_nv;
#endif

#ifdef GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV
const enum_value<
	GLubyte,
	GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV,
	mp_list<oglplus::path_command_nv>
> enum_value::relative_smooth_cubic_curve_to_nv;
#endif

#ifdef GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV
const enum_value<
	GLubyte,
	GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV,
	mp_list<oglplus::path_command_nv>
> enum_value::relative_smooth_quadratic_curve_to_nv;
#endif

#ifdef GL_RELATIVE_VERTICAL_LINE_TO_NV
const enum_value<
	GLubyte,
	GL_RELATIVE_VERTICAL_LINE_TO_NV,
	mp_list<oglplus::path_command_nv>
> enum_value::relative_vertical_line_to_nv;
#endif

#ifdef GL_RENDERBUFFER
const enum_value<
	GLenum,
	GL_RENDERBUFFER,
	mp_list<oglplus::object_type,oglplus::renderbuffer_target>
> enum_value::renderbuffer;
#endif

#ifdef GL_RENDERBUFFER_ALPHA_SIZE
const enum_value<
	GLenum,
	GL_RENDERBUFFER_ALPHA_SIZE,
	mp_list<oglplus::renderbuffer_parameter>
> enum_value::renderbuffer_alpha_size;
#endif

#ifdef GL_RENDERBUFFER_BINDING
const enum_value<
	GLenum,
	GL_RENDERBUFFER_BINDING,
	mp_list<oglplus::binding_query>
> enum_value::renderbuffer_binding;
#endif

#ifdef GL_RENDERBUFFER_BLUE_SIZE
const enum_value<
	GLenum,
	GL_RENDERBUFFER_BLUE_SIZE,
	mp_list<oglplus::renderbuffer_parameter>
> enum_value::renderbuffer_blue_size;
#endif

#ifdef GL_RENDERBUFFER_DEPTH_SIZE
const enum_value<
	GLenum,
	GL_RENDERBUFFER_DEPTH_SIZE,
	mp_list<oglplus::renderbuffer_parameter>
> enum_value::renderbuffer_depth_size;
#endif

#ifdef GL_RENDERBUFFER_GREEN_SIZE
const enum_value<
	GLenum,
	GL_RENDERBUFFER_GREEN_SIZE,
	mp_list<oglplus::renderbuffer_parameter>
> enum_value::renderbuffer_green_size;
#endif

#ifdef GL_RENDERBUFFER_HEIGHT
const enum_value<
	GLenum,
	GL_RENDERBUFFER_HEIGHT,
	mp_list<oglplus::renderbuffer_parameter>
> enum_value::renderbuffer_height;
#endif

#ifdef GL_RENDERBUFFER_INTERNAL_FORMAT
const enum_value<
	GLenum,
	GL_RENDERBUFFER_INTERNAL_FORMAT,
	mp_list<oglplus::renderbuffer_parameter>
> enum_value::renderbuffer_internal_format;
#endif

#ifdef GL_RENDERBUFFER_RED_SIZE
const enum_value<
	GLenum,
	GL_RENDERBUFFER_RED_SIZE,
	mp_list<oglplus::renderbuffer_parameter>
> enum_value::renderbuffer_red_size;
#endif

#ifdef GL_RENDERBUFFER_SAMPLES
const enum_value<
	GLenum,
	GL_RENDERBUFFER_SAMPLES,
	mp_list<oglplus::renderbuffer_parameter>
> enum_value::renderbuffer_samples;
#endif

#ifdef GL_RENDERBUFFER_STENCIL_SIZE
const enum_value<
	GLenum,
	GL_RENDERBUFFER_STENCIL_SIZE,
	mp_list<oglplus::renderbuffer_parameter>
> enum_value::renderbuffer_stencil_size;
#endif

#ifdef GL_RENDERBUFFER_WIDTH
const enum_value<
	GLenum,
	GL_RENDERBUFFER_WIDTH,
	mp_list<oglplus::renderbuffer_parameter>
> enum_value::renderbuffer_width;
#endif

#ifdef GL_RENDERER
const enum_value<
	GLenum,
	GL_RENDERER,
	mp_list<oglplus::string_query>
> enum_value::renderer;
#endif

#ifdef GL_REPEAT
const enum_value<
	GLenum,
	GL_REPEAT,
	mp_list<oglplus::texture_wrap_mode>
> enum_value::repeat;
#endif

#ifdef GL_REPLACE
const enum_value<
	GLenum,
	GL_REPLACE,
	mp_list<oglplus::stencil_operation>
> enum_value::replace;
#endif

#ifdef GL_RESTART_PATH_NV
const enum_value<
	GLubyte,
	GL_RESTART_PATH_NV,
	mp_list<oglplus::path_command_nv>
> enum_value::restart_path_nv;
#endif

#ifdef GL_RG
const enum_value<
	GLenum,
	GL_RG,
	mp_list<oglplus::pixel_data_format,oglplus::pixel_data_internal_format>
> enum_value::rg;
#endif

#ifdef GL_RG16
const enum_value<
	GLenum,
	GL_RG16,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> enum_value::rg16;
#endif

#ifdef GL_RG16_SNORM
const enum_value<
	GLenum,
	GL_RG16_SNORM,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> enum_value::rg16_snorm;
#endif

#ifdef GL_RG16F
const enum_value<
	GLenum,
	GL_RG16F,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> enum_value::rg16f;
#endif

#ifdef GL_RG16I
const enum_value<
	GLenum,
	GL_RG16I,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> enum_value::rg16i;
#endif

#ifdef GL_RG16UI
const enum_value<
	GLenum,
	GL_RG16UI,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> enum_value::rg16ui;
#endif

#ifdef GL_RG32F
const enum_value<
	GLenum,
	GL_RG32F,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> enum_value::rg32f;
#endif

#ifdef GL_RG32I
const enum_value<
	GLenum,
	GL_RG32I,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> enum_value::rg32i;
#endif

#ifdef GL_RG32UI
const enum_value<
	GLenum,
	GL_RG32UI,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> enum_value::rg32ui;
#endif

#ifdef GL_RG8
const enum_value<
	GLenum,
	GL_RG8,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> enum_value::rg8;
#endif

#ifdef GL_RG8_SNORM
const enum_value<
	GLenum,
	GL_RG8_SNORM,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> enum_value::rg8_snorm;
#endif

#ifdef GL_RG8I
const enum_value<
	GLenum,
	GL_RG8I,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> enum_value::rg8i;
#endif

#ifdef GL_RG8UI
const enum_value<
	GLenum,
	GL_RG8UI,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> enum_value::rg8ui;
#endif

#ifdef GL_RG_INTEGER
const enum_value<
	GLenum,
	GL_RG_INTEGER,
	mp_list<oglplus::pixel_data_format>
> enum_value::rg_integer;
#endif

#ifdef GL_RGB
const enum_value<
	GLenum,
	GL_RGB,
	mp_list<oglplus::path_color_format_nv,oglplus::pixel_data_format,oglplus::pixel_data_internal_format>
> enum_value::rgb;
#endif

#ifdef GL_RGB10
const enum_value<
	GLenum,
	GL_RGB10,
	mp_list<oglplus::pixel_data_internal_format>
> enum_value::rgb10;
#endif

#ifdef GL_RGB10_A2
const enum_value<
	GLenum,
	GL_RGB10_A2,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> enum_value::rgb10_a2;
#endif

#ifdef GL_RGB10_A2UI
const enum_value<
	GLenum,
	GL_RGB10_A2UI,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> enum_value::rgb10_a2ui;
#endif

#ifdef GL_RGB12
const enum_value<
	GLenum,
	GL_RGB12,
	mp_list<oglplus::pixel_data_internal_format>
> enum_value::rgb12;
#endif

#ifdef GL_RGB16
const enum_value<
	GLenum,
	GL_RGB16,
	mp_list<oglplus::pixel_data_internal_format>
> enum_value::rgb16;
#endif

#ifdef GL_RGB16_SNORM
const enum_value<
	GLenum,
	GL_RGB16_SNORM,
	mp_list<oglplus::pixel_data_internal_format>
> enum_value::rgb16_snorm;
#endif

#ifdef GL_RGB16F
const enum_value<
	GLenum,
	GL_RGB16F,
	mp_list<oglplus::pixel_data_internal_format>
> enum_value::rgb16f;
#endif

#ifdef GL_RGB16I
const enum_value<
	GLenum,
	GL_RGB16I,
	mp_list<oglplus::pixel_data_internal_format>
> enum_value::rgb16i;
#endif

#ifdef GL_RGB16UI
const enum_value<
	GLenum,
	GL_RGB16UI,
	mp_list<oglplus::pixel_data_internal_format>
> enum_value::rgb16ui;
#endif

#ifdef GL_RGB32F
const enum_value<
	GLenum,
	GL_RGB32F,
	mp_list<oglplus::pixel_data_internal_format>
> enum_value::rgb32f;
#endif

#ifdef GL_RGB32I
const enum_value<
	GLenum,
	GL_RGB32I,
	mp_list<oglplus::pixel_data_internal_format>
> enum_value::rgb32i;
#endif

#ifdef GL_RGB32UI
const enum_value<
	GLenum,
	GL_RGB32UI,
	mp_list<oglplus::pixel_data_internal_format>
> enum_value::rgb32ui;
#endif

#ifdef GL_RGB4
const enum_value<
	GLenum,
	GL_RGB4,
	mp_list<oglplus::pixel_data_internal_format>
> enum_value::rgb4;
#endif

#ifdef GL_RGB5
const enum_value<
	GLenum,
	GL_RGB5,
	mp_list<oglplus::pixel_data_internal_format>
> enum_value::rgb5;
#endif

#ifdef GL_RGB5_A1
const enum_value<
	GLenum,
	GL_RGB5_A1,
	mp_list<oglplus::pixel_data_internal_format>
> enum_value::rgb5_a1;
#endif

#ifdef GL_RGB8
const enum_value<
	GLenum,
	GL_RGB8,
	mp_list<oglplus::pixel_data_internal_format>
> enum_value::rgb8;
#endif

#ifdef GL_RGB8_SNORM
const enum_value<
	GLenum,
	GL_RGB8_SNORM,
	mp_list<oglplus::pixel_data_internal_format>
> enum_value::rgb8_snorm;
#endif

#ifdef GL_RGB8I
const enum_value<
	GLenum,
	GL_RGB8I,
	mp_list<oglplus::pixel_data_internal_format>
> enum_value::rgb8i;
#endif

#ifdef GL_RGB8UI
const enum_value<
	GLenum,
	GL_RGB8UI,
	mp_list<oglplus::pixel_data_internal_format>
> enum_value::rgb8ui;
#endif

#ifdef GL_RGB9_E5
const enum_value<
	GLenum,
	GL_RGB9_E5,
	mp_list<oglplus::pixel_data_internal_format>
> enum_value::rgb9_e5;
#endif

#ifdef GL_RGB_INTEGER
const enum_value<
	GLenum,
	GL_RGB_INTEGER,
	mp_list<oglplus::pixel_data_format>
> enum_value::rgb_integer;
#endif

#ifdef GL_RGBA
const enum_value<
	GLenum,
	GL_RGBA,
	mp_list<oglplus::path_color_format_nv,oglplus::pixel_data_format,oglplus::pixel_data_internal_format>
> enum_value::rgba;
#endif

#ifdef GL_RGBA12
const enum_value<
	GLenum,
	GL_RGBA12,
	mp_list<oglplus::pixel_data_internal_format>
> enum_value::rgba12;
#endif

#ifdef GL_RGBA16
const enum_value<
	GLenum,
	GL_RGBA16,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> enum_value::rgba16;
#endif

#ifdef GL_RGBA16_SNORM
const enum_value<
	GLenum,
	GL_RGBA16_SNORM,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> enum_value::rgba16_snorm;
#endif

#ifdef GL_RGBA16F
const enum_value<
	GLenum,
	GL_RGBA16F,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> enum_value::rgba16f;
#endif

#ifdef GL_RGBA16I
const enum_value<
	GLenum,
	GL_RGBA16I,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> enum_value::rgba16i;
#endif

#ifdef GL_RGBA16UI
const enum_value<
	GLenum,
	GL_RGBA16UI,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> enum_value::rgba16ui;
#endif

#ifdef GL_RGBA2
const enum_value<
	GLenum,
	GL_RGBA2,
	mp_list<oglplus::pixel_data_internal_format>
> enum_value::rgba2;
#endif

#ifdef GL_RGBA32F
const enum_value<
	GLenum,
	GL_RGBA32F,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> enum_value::rgba32f;
#endif

#ifdef GL_RGBA32I
const enum_value<
	GLenum,
	GL_RGBA32I,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> enum_value::rgba32i;
#endif

#ifdef GL_RGBA32UI
const enum_value<
	GLenum,
	GL_RGBA32UI,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> enum_value::rgba32ui;
#endif

#ifdef GL_RGBA4
const enum_value<
	GLenum,
	GL_RGBA4,
	mp_list<oglplus::pixel_data_internal_format>
> enum_value::rgba4;
#endif

#ifdef GL_RGBA8
const enum_value<
	GLenum,
	GL_RGBA8,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> enum_value::rgba8;
#endif

#ifdef GL_RGBA8_SNORM
const enum_value<
	GLenum,
	GL_RGBA8_SNORM,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> enum_value::rgba8_snorm;
#endif

#ifdef GL_RGBA8I
const enum_value<
	GLenum,
	GL_RGBA8I,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> enum_value::rgba8i;
#endif

#ifdef GL_RGBA8UI
const enum_value<
	GLenum,
	GL_RGBA8UI,
	mp_list<oglplus::pixel_data_internal_format,oglplus::image_unit_format>
> enum_value::rgba8ui;
#endif

#ifdef GL_RGBA_INTEGER
const enum_value<
	GLenum,
	GL_RGBA_INTEGER,
	mp_list<oglplus::pixel_data_format>
> enum_value::rgba_integer;
#endif

#ifdef GL_RIGHT
const enum_value<
	GLenum,
	GL_RIGHT,
	mp_list<oglplus::color_buffer>
> enum_value::right;
#endif

#ifdef GL_ROUND_NV
const enum_value<
	GLenum,
	GL_ROUND_NV,
	mp_list<oglplus::path_cap_style_nv,oglplus::path_join_style_nv>
> enum_value::round_nv;
#endif

#ifdef GL_SAMPLE_ALPHA_TO_COVERAGE
const enum_value<
	GLenum,
	GL_SAMPLE_ALPHA_TO_COVERAGE,
	mp_list<oglplus::capability>
> enum_value::sample_alpha_to_coverage;
#endif

#ifdef GL_SAMPLE_ALPHA_TO_ONE
const enum_value<
	GLenum,
	GL_SAMPLE_ALPHA_TO_ONE,
	mp_list<oglplus::capability>
> enum_value::sample_alpha_to_one;
#endif

#ifdef GL_SAMPLE_BUFFERS
const enum_value<
	GLenum,
	GL_SAMPLE_BUFFERS,
	mp_list<oglplus::numeric_query>
> enum_value::sample_buffers;
#endif

#ifdef GL_SAMPLE_COVERAGE
const enum_value<
	GLenum,
	GL_SAMPLE_COVERAGE,
	mp_list<oglplus::capability>
> enum_value::sample_coverage;
#endif

#ifdef GL_SAMPLE_COVERAGE_INVERT
const enum_value<
	GLenum,
	GL_SAMPLE_COVERAGE_INVERT,
	mp_list<oglplus::numeric_query>
> enum_value::sample_coverage_invert;
#endif

#ifdef GL_SAMPLE_COVERAGE_VALUE
const enum_value<
	GLenum,
	GL_SAMPLE_COVERAGE_VALUE,
	mp_list<oglplus::numeric_query>
> enum_value::sample_coverage_value;
#endif

#ifdef GL_SAMPLE_MASK
const enum_value<
	GLenum,
	GL_SAMPLE_MASK,
	mp_list<oglplus::capability>
> enum_value::sample_mask;
#endif

#ifdef GL_SAMPLE_SHADING
const enum_value<
	GLenum,
	GL_SAMPLE_SHADING,
	mp_list<oglplus::capability>
> enum_value::sample_shading;
#endif

#ifdef GL_SAMPLER
const enum_value<
	GLenum,
	GL_SAMPLER,
	mp_list<oglplus::object_type>
> enum_value::sampler;
#endif

#ifdef GL_SAMPLER_1D
const enum_value<
	GLenum,
	GL_SAMPLER_1D,
	mp_list<oglplus::sl_data_type>
> enum_value::sampler_1d;
#endif

#ifdef GL_SAMPLER_1D_ARRAY
const enum_value<
	GLenum,
	GL_SAMPLER_1D_ARRAY,
	mp_list<oglplus::sl_data_type>
> enum_value::sampler_1d_array;
#endif

#ifdef GL_SAMPLER_1D_ARRAY_SHADOW
const enum_value<
	GLenum,
	GL_SAMPLER_1D_ARRAY_SHADOW,
	mp_list<oglplus::sl_data_type>
> enum_value::sampler_1d_array_shadow;
#endif

#ifdef GL_SAMPLER_1D_SHADOW
const enum_value<
	GLenum,
	GL_SAMPLER_1D_SHADOW,
	mp_list<oglplus::sl_data_type>
> enum_value::sampler_1d_shadow;
#endif

#ifdef GL_SAMPLER_2D
const enum_value<
	GLenum,
	GL_SAMPLER_2D,
	mp_list<oglplus::sl_data_type>
> enum_value::sampler_2d;
#endif

#ifdef GL_SAMPLER_2D_ARRAY
const enum_value<
	GLenum,
	GL_SAMPLER_2D_ARRAY,
	mp_list<oglplus::sl_data_type>
> enum_value::sampler_2d_array;
#endif

#ifdef GL_SAMPLER_2D_ARRAY_SHADOW
const enum_value<
	GLenum,
	GL_SAMPLER_2D_ARRAY_SHADOW,
	mp_list<oglplus::sl_data_type>
> enum_value::sampler_2d_array_shadow;
#endif

#ifdef GL_SAMPLER_2D_MULTISAMPLE
const enum_value<
	GLenum,
	GL_SAMPLER_2D_MULTISAMPLE,
	mp_list<oglplus::sl_data_type>
> enum_value::sampler_2d_multisample;
#endif

#ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
const enum_value<
	GLenum,
	GL_SAMPLER_2D_MULTISAMPLE_ARRAY,
	mp_list<oglplus::sl_data_type>
> enum_value::sampler_2d_multisample_array;
#endif

#ifdef GL_SAMPLER_2D_RECT
const enum_value<
	GLenum,
	GL_SAMPLER_2D_RECT,
	mp_list<oglplus::sl_data_type>
> enum_value::sampler_2d_rect;
#endif

#ifdef GL_SAMPLER_2D_RECT_SHADOW
const enum_value<
	GLenum,
	GL_SAMPLER_2D_RECT_SHADOW,
	mp_list<oglplus::sl_data_type>
> enum_value::sampler_2d_rect_shadow;
#endif

#ifdef GL_SAMPLER_2D_SHADOW
const enum_value<
	GLenum,
	GL_SAMPLER_2D_SHADOW,
	mp_list<oglplus::sl_data_type>
> enum_value::sampler_2d_shadow;
#endif

#ifdef GL_SAMPLER_3D
const enum_value<
	GLenum,
	GL_SAMPLER_3D,
	mp_list<oglplus::sl_data_type>
> enum_value::sampler_3d;
#endif

#ifdef GL_SAMPLER_BINDING
const enum_value<
	GLenum,
	GL_SAMPLER_BINDING,
	mp_list<oglplus::binding_query>
> enum_value::sampler_binding;
#endif

#ifdef GL_SAMPLER_BUFFER
const enum_value<
	GLenum,
	GL_SAMPLER_BUFFER,
	mp_list<oglplus::sl_data_type>
> enum_value::sampler_buffer;
#endif

#ifdef GL_SAMPLER_CUBE
const enum_value<
	GLenum,
	GL_SAMPLER_CUBE,
	mp_list<oglplus::sl_data_type>
> enum_value::sampler_cube;
#endif

#ifdef GL_SAMPLER_CUBE_MAP_ARRAY
const enum_value<
	GLenum,
	GL_SAMPLER_CUBE_MAP_ARRAY,
	mp_list<oglplus::sl_data_type>
> enum_value::sampler_cube_map_array;
#endif

#ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
const enum_value<
	GLenum,
	GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW,
	mp_list<oglplus::sl_data_type>
> enum_value::sampler_cube_map_array_shadow;
#endif

#ifdef GL_SAMPLER_CUBE_SHADOW
const enum_value<
	GLenum,
	GL_SAMPLER_CUBE_SHADOW,
	mp_list<oglplus::sl_data_type>
> enum_value::sampler_cube_shadow;
#endif

#ifdef GL_SAMPLES
const enum_value<
	GLenum,
	GL_SAMPLES,
	mp_list<oglplus::numeric_query>
> enum_value::samples;
#endif

#ifdef GL_SAMPLES_PASSED
const enum_value<
	GLenum,
	GL_SAMPLES_PASSED,
	mp_list<oglplus::query_target>
> enum_value::samples_passed;
#endif

#ifdef GL_SCISSOR_BOX
const enum_value<
	GLenum,
	GL_SCISSOR_BOX,
	mp_list<oglplus::numeric_query>
> enum_value::scissor_box;
#endif

#ifdef GL_SCISSOR_TEST
const enum_value<
	GLenum,
	GL_SCISSOR_TEST,
	mp_list<oglplus::capability>
> enum_value::scissor_test;
#endif

#ifdef GL_SCREEN_KHR
const enum_value<
	GLenum,
	GL_SCREEN_KHR,
	mp_list<oglplus::blend_equation_advanced>
> enum_value::screen_khr;
#endif

#ifdef GL_SECONDARY_COLOR_NV
const enum_value<
	GLenum,
	GL_SECONDARY_COLOR_NV,
	mp_list<oglplus::path_color_nv>
> enum_value::secondary_color_nv;
#endif

#ifdef GL_SEPARATE_ATTRIBS
const enum_value<
	GLenum,
	GL_SEPARATE_ATTRIBS,
	mp_list<oglplus::transform_feedback_mode>
> enum_value::separate_attribs;
#endif

#ifdef GL_SET
const enum_value<
	GLenum,
	GL_SET,
	mp_list<oglplus::color_logic_operation>
> enum_value::set;
#endif

#ifdef GL_SHADER
const enum_value<
	GLenum,
	GL_SHADER,
	mp_list<oglplus::object_type>
> enum_value::shader;
#endif

#ifdef GL_SHADER_COMPILER
const enum_value<
	GLenum,
	GL_SHADER_COMPILER,
	mp_list<oglplus::numeric_query>
> enum_value::shader_compiler;
#endif

#ifdef GL_SHADER_IMAGE_ACCESS_BARRIER_BIT
const enum_value<
	GLbitfield,
	GL_SHADER_IMAGE_ACCESS_BARRIER_BIT,
	mp_list<oglplus::memory_barrier_bits>
> enum_value::shader_image_access_barrier_bit;
#endif

#ifdef GL_SHADER_INCLUDE_ARB
const enum_value<
	GLenum,
	GL_SHADER_INCLUDE_ARB,
	mp_list<oglplus::named_string_type>
> enum_value::shader_include;
#endif

#ifdef GL_SHADER_SOURCE_LENGTH
const enum_value<
	GLenum,
	GL_SHADER_SOURCE_LENGTH,
	mp_list<oglplus::shader_parameter>
> enum_value::shader_source_length;
#endif

#ifdef GL_SHADER_STORAGE_BARRIER_BIT
const enum_value<
	GLbitfield,
	GL_SHADER_STORAGE_BARRIER_BIT,
	mp_list<oglplus::memory_barrier_bits>
> enum_value::shader_storage_barrier_bit;
#endif

#ifdef GL_SHADER_STORAGE_BLOCK
const enum_value<
	GLenum,
	GL_SHADER_STORAGE_BLOCK,
	mp_list<oglplus::program_interface>
> enum_value::shader_storage_block;
#endif

#ifdef GL_SHADER_STORAGE_BUFFER
const enum_value<
	GLenum,
	GL_SHADER_STORAGE_BUFFER,
	mp_list<oglplus::buffer_indexed_target,oglplus::buffer_target>
> enum_value::shader_storage_buffer;
#endif

#ifdef GL_SHADER_STORAGE_BUFFER_BINDING
const enum_value<
	GLenum,
	GL_SHADER_STORAGE_BUFFER_BINDING,
	mp_list<oglplus::binding_query>
> enum_value::shader_storage_buffer_binding;
#endif

#ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
const enum_value<
	GLenum,
	GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT,
	mp_list<oglplus::numeric_query>
> enum_value::shader_storage_buffer_offset_alignment;
#endif

#ifdef GL_SHADER_STORAGE_BUFFER_SIZE
const enum_value<
	GLenum,
	GL_SHADER_STORAGE_BUFFER_SIZE,
	mp_list<oglplus::numeric_query>
> enum_value::shader_storage_buffer_size;
#endif

#ifdef GL_SHADER_STORAGE_BUFFER_START
const enum_value<
	GLenum,
	GL_SHADER_STORAGE_BUFFER_START,
	mp_list<oglplus::numeric_query>
> enum_value::shader_storage_buffer_start;
#endif

#ifdef GL_SHADER_TYPE
const enum_value<
	GLenum,
	GL_SHADER_TYPE,
	mp_list<oglplus::shader_parameter>
> enum_value::shader_type;
#endif

#ifdef GL_SHADING_LANGUAGE_VERSION
const enum_value<
	GLenum,
	GL_SHADING_LANGUAGE_VERSION,
	mp_list<oglplus::string_query>
> enum_value::shading_language_version;
#endif

#ifdef GL_SHORT
const enum_value<
	GLenum,
	GL_SHORT,
	mp_list<oglplus::pixel_data_type,oglplus::data_type>
> enum_value::short_;
#endif

#ifdef GL_SIGNALED
const enum_value<
	GLenum,
	GL_SIGNALED,
	mp_list<oglplus::sync_status>
> enum_value::signaled;
#endif

#ifdef GL_SKIP_MISSING_GLYPH_NV
const enum_value<
	GLenum,
	GL_SKIP_MISSING_GLYPH_NV,
	mp_list<oglplus::path_missing_glyph_nv>
> enum_value::skip_missing_glyph_nv;
#endif

#ifdef GL_SMALL_CCW_ARC_TO_NV
const enum_value<
	GLubyte,
	GL_SMALL_CCW_ARC_TO_NV,
	mp_list<oglplus::path_command_nv>
> enum_value::small_ccw_arc_to_nv;
#endif

#ifdef GL_SMALL_CW_ARC_TO_NV
const enum_value<
	GLubyte,
	GL_SMALL_CW_ARC_TO_NV,
	mp_list<oglplus::path_command_nv>
> enum_value::small_cw_arc_to_nv;
#endif

#ifdef GL_SMOOTH_CUBIC_CURVE_TO_NV
const enum_value<
	GLubyte,
	GL_SMOOTH_CUBIC_CURVE_TO_NV,
	mp_list<oglplus::path_command_nv>
> enum_value::smooth_cubic_curve_to_nv;
#endif

#ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
const enum_value<
	GLenum,
	GL_SMOOTH_LINE_WIDTH_GRANULARITY,
	mp_list<oglplus::numeric_query>
> enum_value::smooth_line_width_granularity;
#endif

#ifdef GL_SMOOTH_LINE_WIDTH_RANGE
const enum_value<
	GLenum,
	GL_SMOOTH_LINE_WIDTH_RANGE,
	mp_list<oglplus::numeric_query>
> enum_value::smooth_line_width_range;
#endif

#ifdef GL_SMOOTH_QUADRATIC_CURVE_TO_NV
const enum_value<
	GLubyte,
	GL_SMOOTH_QUADRATIC_CURVE_TO_NV,
	mp_list<oglplus::path_command_nv>
> enum_value::smooth_quadratic_curve_to_nv;
#endif

#ifdef GL_SOFTLIGHT_KHR
const enum_value<
	GLenum,
	GL_SOFTLIGHT_KHR,
	mp_list<oglplus::blend_equation_advanced>
> enum_value::softlight_khr;
#endif

#ifdef GL_SPARSE_STORAGE_BIT_ARB
const enum_value<
	GLbitfield,
	GL_SPARSE_STORAGE_BIT_ARB,
	mp_list<oglplus::buffer_storage_bits>
> enum_value::sparse_storage_bit;
#endif

#ifdef GL_SQUARE_NV
const enum_value<
	GLenum,
	GL_SQUARE_NV,
	mp_list<oglplus::path_cap_style_nv>
> enum_value::square_nv;
#endif

#ifdef GL_SRC1_ALPHA
const enum_value<
	GLenum,
	GL_SRC1_ALPHA,
	mp_list<oglplus::blend_function>
> enum_value::src1_alpha;
#endif

#ifdef GL_SRC1_COLOR
const enum_value<
	GLenum,
	GL_SRC1_COLOR,
	mp_list<oglplus::blend_function>
> enum_value::src1_color;
#endif

#ifdef GL_SRC_ALPHA
const enum_value<
	GLenum,
	GL_SRC_ALPHA,
	mp_list<oglplus::blend_function>
> enum_value::src_alpha;
#endif

#ifdef GL_SRC_ALPHA_SATURATE
const enum_value<
	GLenum,
	GL_SRC_ALPHA_SATURATE,
	mp_list<oglplus::blend_function>
> enum_value::src_alpha_saturate;
#endif

#ifdef GL_SRC_COLOR
const enum_value<
	GLenum,
	GL_SRC_COLOR,
	mp_list<oglplus::blend_function>
> enum_value::src_color;
#endif

#ifdef GL_SRGB8
const enum_value<
	GLenum,
	GL_SRGB8,
	mp_list<oglplus::pixel_data_internal_format>
> enum_value::srgb8;
#endif

#ifdef GL_SRGB8_ALPHA8
const enum_value<
	GLenum,
	GL_SRGB8_ALPHA8,
	mp_list<oglplus::pixel_data_internal_format>
> enum_value::srgb8_alpha8;
#endif

#ifdef GL_STACK_OVERFLOW
const enum_value<
	GLenum,
	GL_STACK_OVERFLOW,
	mp_list<oglplus::error_code>
> enum_value::stack_overflow;
#endif

#ifdef GL_STACK_UNDERFLOW
const enum_value<
	GLenum,
	GL_STACK_UNDERFLOW,
	mp_list<oglplus::error_code>
> enum_value::stack_underflow;
#endif

#ifdef GL_STANDARD_FONT_NAME_NV
const enum_value<
	GLenum,
	GL_STANDARD_FONT_NAME_NV,
	mp_list<oglplus::path_font_target_nv>
> enum_value::standard_font_name_nv;
#endif

#ifdef GL_STATIC_COPY
const enum_value<
	GLenum,
	GL_STATIC_COPY,
	mp_list<oglplus::buffer_usage>
> enum_value::static_copy;
#endif

#ifdef GL_STATIC_DRAW
const enum_value<
	GLenum,
	GL_STATIC_DRAW,
	mp_list<oglplus::buffer_usage>
> enum_value::static_draw;
#endif

#ifdef GL_STATIC_READ
const enum_value<
	GLenum,
	GL_STATIC_READ,
	mp_list<oglplus::buffer_usage>
> enum_value::static_read;
#endif

#ifdef GL_STENCIL
const enum_value<
	GLenum,
	GL_STENCIL,
	mp_list<oglplus::framebuffer_buffer>
> enum_value::stencil;
#endif

#ifdef GL_STENCIL_ATTACHMENT
const enum_value<
	GLenum,
	GL_STENCIL_ATTACHMENT,
	mp_list<oglplus::framebuffer_other_attachment>
> enum_value::stencil_attachment;
#endif

#ifdef GL_STENCIL_BACK_FAIL
const enum_value<
	GLenum,
	GL_STENCIL_BACK_FAIL,
	mp_list<oglplus::numeric_query>
> enum_value::stencil_back_fail;
#endif

#ifdef GL_STENCIL_BACK_FUNC
const enum_value<
	GLenum,
	GL_STENCIL_BACK_FUNC,
	mp_list<oglplus::numeric_query>
> enum_value::stencil_back_func;
#endif

#ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
const enum_value<
	GLenum,
	GL_STENCIL_BACK_PASS_DEPTH_FAIL,
	mp_list<oglplus::numeric_query>
> enum_value::stencil_back_pass_depth_fail;
#endif

#ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
const enum_value<
	GLenum,
	GL_STENCIL_BACK_PASS_DEPTH_PASS,
	mp_list<oglplus::numeric_query>
> enum_value::stencil_back_pass_depth_pass;
#endif

#ifdef GL_STENCIL_BACK_REF
const enum_value<
	GLenum,
	GL_STENCIL_BACK_REF,
	mp_list<oglplus::numeric_query>
> enum_value::stencil_back_ref;
#endif

#ifdef GL_STENCIL_BACK_VALUE_MASK
const enum_value<
	GLenum,
	GL_STENCIL_BACK_VALUE_MASK,
	mp_list<oglplus::numeric_query>
> enum_value::stencil_back_value_mask;
#endif

#ifdef GL_STENCIL_BACK_WRITEMASK
const enum_value<
	GLenum,
	GL_STENCIL_BACK_WRITEMASK,
	mp_list<oglplus::numeric_query>
> enum_value::stencil_back_writemask;
#endif

#ifdef GL_STENCIL_BUFFER_BIT
const enum_value<
	GLbitfield,
	GL_STENCIL_BUFFER_BIT,
	mp_list<oglplus::buffer_select_bits>
> enum_value::stencil_buffer_bit;
#endif

#ifdef GL_STENCIL_CLEAR_VALUE
const enum_value<
	GLenum,
	GL_STENCIL_CLEAR_VALUE,
	mp_list<oglplus::numeric_query>
> enum_value::stencil_clear_value;
#endif

#ifdef GL_STENCIL_FAIL
const enum_value<
	GLenum,
	GL_STENCIL_FAIL,
	mp_list<oglplus::numeric_query>
> enum_value::stencil_fail;
#endif

#ifdef GL_STENCIL_FUNC
const enum_value<
	GLenum,
	GL_STENCIL_FUNC,
	mp_list<oglplus::numeric_query>
> enum_value::stencil_func;
#endif

#ifdef GL_STENCIL_INDEX
const enum_value<
	GLenum,
	GL_STENCIL_INDEX,
	mp_list<oglplus::pixel_data_format>
> enum_value::stencil_index;
#endif

#ifdef GL_STENCIL_INDEX8
const enum_value<
	GLenum,
	GL_STENCIL_INDEX8,
	mp_list<oglplus::pixel_data_internal_format>
> enum_value::stencil_index8;
#endif

#ifdef GL_STENCIL_PASS_DEPTH_FAIL
const enum_value<
	GLenum,
	GL_STENCIL_PASS_DEPTH_FAIL,
	mp_list<oglplus::numeric_query>
> enum_value::stencil_pass_depth_fail;
#endif

#ifdef GL_STENCIL_PASS_DEPTH_PASS
const enum_value<
	GLenum,
	GL_STENCIL_PASS_DEPTH_PASS,
	mp_list<oglplus::numeric_query>
> enum_value::stencil_pass_depth_pass;
#endif

#ifdef GL_STENCIL_REF
const enum_value<
	GLenum,
	GL_STENCIL_REF,
	mp_list<oglplus::numeric_query>
> enum_value::stencil_ref;
#endif

#ifdef GL_STENCIL_TEST
const enum_value<
	GLenum,
	GL_STENCIL_TEST,
	mp_list<oglplus::capability>
> enum_value::stencil_test;
#endif

#ifdef GL_STENCIL_VALUE_MASK
const enum_value<
	GLenum,
	GL_STENCIL_VALUE_MASK,
	mp_list<oglplus::numeric_query>
> enum_value::stencil_value_mask;
#endif

#ifdef GL_STENCIL_WRITEMASK
const enum_value<
	GLenum,
	GL_STENCIL_WRITEMASK,
	mp_list<oglplus::numeric_query>
> enum_value::stencil_writemask;
#endif

#ifdef GL_STEREO
const enum_value<
	GLenum,
	GL_STEREO,
	mp_list<oglplus::numeric_query>
> enum_value::stereo;
#endif

#ifdef GL_STREAM_COPY
const enum_value<
	GLenum,
	GL_STREAM_COPY,
	mp_list<oglplus::buffer_usage>
> enum_value::stream_copy;
#endif

#ifdef GL_STREAM_DRAW
const enum_value<
	GLenum,
	GL_STREAM_DRAW,
	mp_list<oglplus::buffer_usage>
> enum_value::stream_draw;
#endif

#ifdef GL_STREAM_RASTERIZATION_AMD
const enum_value<
	GLenum,
	GL_STREAM_RASTERIZATION_AMD,
	mp_list<oglplus::capability>
> enum_value::stream_rasterization;
#endif

#ifdef GL_STREAM_READ
const enum_value<
	GLenum,
	GL_STREAM_READ,
	mp_list<oglplus::buffer_usage>
> enum_value::stream_read;
#endif

#ifdef GL_SUBPIXEL_BITS
const enum_value<
	GLenum,
	GL_SUBPIXEL_BITS,
	mp_list<oglplus::numeric_query>
> enum_value::subpixel_bits;
#endif

#ifdef GL_SYNC_FENCE
const enum_value<
	GLenum,
	GL_SYNC_FENCE,
	mp_list<oglplus::sync_type>
> enum_value::sync_fence;
#endif

#ifdef GL_SYNC_GPU_COMMANDS_COMPLETE
const enum_value<
	GLenum,
	GL_SYNC_GPU_COMMANDS_COMPLETE,
	mp_list<oglplus::sync_condition>
> enum_value::sync_gpu_commands_complete;
#endif

#ifdef GL_SYSTEM_FONT_NAME_NV
const enum_value<
	GLenum,
	GL_SYSTEM_FONT_NAME_NV,
	mp_list<oglplus::path_font_target_nv>
> enum_value::system_font_name_nv;
#endif

#ifdef GL_TABLE_TOO_LARGE
const enum_value<
	GLenum,
	GL_TABLE_TOO_LARGE,
	mp_list<oglplus::error_code>
> enum_value::table_too_large;
#endif

#ifdef GL_TESS_CONTROL_SHADER
const enum_value<
	GLenum,
	GL_TESS_CONTROL_SHADER,
	mp_list<oglplus::shader_type,oglplus::program_pipeline_parameter>
> enum_value::tess_control_shader;
#endif

#ifdef GL_TESS_CONTROL_SHADER_BIT
const enum_value<
	GLbitfield,
	GL_TESS_CONTROL_SHADER_BIT,
	mp_list<oglplus::program_pipeline_stage>
> enum_value::tess_control_shader_bit;
#endif

#ifdef GL_TESS_CONTROL_SHADER_PATCHES_ARB
const enum_value<
	GLenum,
	GL_TESS_CONTROL_SHADER_PATCHES_ARB,
	mp_list<oglplus::query_target>
> enum_value::tess_control_shader_patches;
#endif

#ifdef GL_TESS_CONTROL_SUBROUTINE
const enum_value<
	GLenum,
	GL_TESS_CONTROL_SUBROUTINE,
	mp_list<oglplus::program_interface>
> enum_value::tess_control_subroutine;
#endif

#ifdef GL_TESS_CONTROL_SUBROUTINE_UNIFORM
const enum_value<
	GLenum,
	GL_TESS_CONTROL_SUBROUTINE_UNIFORM,
	mp_list<oglplus::program_interface>
> enum_value::tess_control_subroutine_uniform;
#endif

#ifdef GL_TESS_EVALUATION_SHADER
const enum_value<
	GLenum,
	GL_TESS_EVALUATION_SHADER,
	mp_list<oglplus::shader_type,oglplus::program_pipeline_parameter>
> enum_value::tess_evaluation_shader;
#endif

#ifdef GL_TESS_EVALUATION_SHADER_BIT
const enum_value<
	GLbitfield,
	GL_TESS_EVALUATION_SHADER_BIT,
	mp_list<oglplus::program_pipeline_stage>
> enum_value::tess_evaluation_shader_bit;
#endif

#ifdef GL_TESS_EVALUATION_SHADER_INVOCATIONS_ARB
const enum_value<
	GLenum,
	GL_TESS_EVALUATION_SHADER_INVOCATIONS_ARB,
	mp_list<oglplus::query_target>
> enum_value::tess_evaluation_shader_invocations;
#endif

#ifdef GL_TESS_EVALUATION_SUBROUTINE
const enum_value<
	GLenum,
	GL_TESS_EVALUATION_SUBROUTINE,
	mp_list<oglplus::program_interface>
> enum_value::tess_evaluation_subroutine;
#endif

#ifdef GL_TESS_EVALUATION_SUBROUTINE_UNIFORM
const enum_value<
	GLenum,
	GL_TESS_EVALUATION_SUBROUTINE_UNIFORM,
	mp_list<oglplus::program_interface>
> enum_value::tess_evaluation_subroutine_uniform;
#endif

#ifdef GL_TEXTURE
const enum_value<
	GLenum,
	GL_TEXTURE,
	mp_list<oglplus::old_matrix_mode,oglplus::object_type>
> enum_value::texture;
#endif

#ifdef GL_TEXTURE0
const enum_value<
	GLenum,
	GL_TEXTURE0,
	mp_list<oglplus::indexed_value_base>
> enum_value::texture0;
#endif

#ifdef GL_TEXTURE_1D
const enum_value<
	GLenum,
	GL_TEXTURE_1D,
	mp_list<oglplus::texture_target>
> enum_value::texture_1d;
#endif

#ifdef GL_TEXTURE_1D_ARRAY
const enum_value<
	GLenum,
	GL_TEXTURE_1D_ARRAY,
	mp_list<oglplus::texture_target>
> enum_value::texture_1d_array;
#endif

#ifdef GL_TEXTURE_2D
const enum_value<
	GLenum,
	GL_TEXTURE_2D,
	mp_list<oglplus::texture_target>
> enum_value::texture_2d;
#endif

#ifdef GL_TEXTURE_2D_ARRAY
const enum_value<
	GLenum,
	GL_TEXTURE_2D_ARRAY,
	mp_list<oglplus::texture_target>
> enum_value::texture_2d_array;
#endif

#ifdef GL_TEXTURE_2D_MULTISAMPLE
const enum_value<
	GLenum,
	GL_TEXTURE_2D_MULTISAMPLE,
	mp_list<oglplus::texture_target>
> enum_value::texture_2d_multisample;
#endif

#ifdef GL_TEXTURE_2D_MULTISAMPLE_ARRAY
const enum_value<
	GLenum,
	GL_TEXTURE_2D_MULTISAMPLE_ARRAY,
	mp_list<oglplus::texture_target>
> enum_value::texture_2d_multisample_array;
#endif

#ifdef GL_TEXTURE_3D
const enum_value<
	GLenum,
	GL_TEXTURE_3D,
	mp_list<oglplus::texture_target>
> enum_value::texture_3d;
#endif

#ifdef GL_TEXTURE_BASE_LEVEL
const enum_value<
	GLenum,
	GL_TEXTURE_BASE_LEVEL,
	mp_list<oglplus::texture_parameter>
> enum_value::texture_base_level;
#endif

#ifdef GL_TEXTURE_BINDING_1D
const enum_value<
	GLenum,
	GL_TEXTURE_BINDING_1D,
	mp_list<oglplus::binding_query>
> enum_value::texture_binding_1d;
#endif

#ifdef GL_TEXTURE_BINDING_1D_ARRAY
const enum_value<
	GLenum,
	GL_TEXTURE_BINDING_1D_ARRAY,
	mp_list<oglplus::binding_query>
> enum_value::texture_binding_1d_array;
#endif

#ifdef GL_TEXTURE_BINDING_2D
const enum_value<
	GLenum,
	GL_TEXTURE_BINDING_2D,
	mp_list<oglplus::binding_query>
> enum_value::texture_binding_2d;
#endif

#ifdef GL_TEXTURE_BINDING_2D_ARRAY
const enum_value<
	GLenum,
	GL_TEXTURE_BINDING_2D_ARRAY,
	mp_list<oglplus::binding_query>
> enum_value::texture_binding_2d_array;
#endif

#ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE
const enum_value<
	GLenum,
	GL_TEXTURE_BINDING_2D_MULTISAMPLE,
	mp_list<oglplus::binding_query>
> enum_value::texture_binding_2d_multisample;
#endif

#ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY
const enum_value<
	GLenum,
	GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY,
	mp_list<oglplus::binding_query>
> enum_value::texture_binding_2d_multisample_array;
#endif

#ifdef GL_TEXTURE_BINDING_3D
const enum_value<
	GLenum,
	GL_TEXTURE_BINDING_3D,
	mp_list<oglplus::binding_query>
> enum_value::texture_binding_3d;
#endif

#ifdef GL_TEXTURE_BINDING_BUFFER
const enum_value<
	GLenum,
	GL_TEXTURE_BINDING_BUFFER,
	mp_list<oglplus::binding_query>
> enum_value::texture_binding_buffer;
#endif

#ifdef GL_TEXTURE_BINDING_CUBE_MAP
const enum_value<
	GLenum,
	GL_TEXTURE_BINDING_CUBE_MAP,
	mp_list<oglplus::binding_query>
> enum_value::texture_binding_cube_map;
#endif

#ifdef GL_TEXTURE_BINDING_CUBE_MAP_ARRAY
const enum_value<
	GLenum,
	GL_TEXTURE_BINDING_CUBE_MAP_ARRAY,
	mp_list<oglplus::binding_query>
> enum_value::texture_binding_cube_map_array;
#endif

#ifdef GL_TEXTURE_BINDING_RECTANGLE
const enum_value<
	GLenum,
	GL_TEXTURE_BINDING_RECTANGLE,
	mp_list<oglplus::binding_query>
> enum_value::texture_binding_rectangle;
#endif

#ifdef GL_TEXTURE_BORDER_COLOR
const enum_value<
	GLenum,
	GL_TEXTURE_BORDER_COLOR,
	mp_list<oglplus::texture_parameter,oglplus::sampler_parameter>
> enum_value::texture_border_color;
#endif

#ifdef GL_TEXTURE_BUFFER
const enum_value<
	GLenum,
	GL_TEXTURE_BUFFER,
	mp_list<oglplus::texture_target,oglplus::buffer_target>
> enum_value::texture_buffer;
#endif

#ifdef GL_TEXTURE_BUFFER_BINDING
const enum_value<
	GLenum,
	GL_TEXTURE_BUFFER_BINDING,
	mp_list<oglplus::binding_query>
> enum_value::texture_buffer_binding;
#endif

#ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
const enum_value<
	GLenum,
	GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT,
	mp_list<oglplus::numeric_query>
> enum_value::texture_buffer_offset_alignment;
#endif

#ifdef GL_TEXTURE_COMPARE_FUNC
const enum_value<
	GLenum,
	GL_TEXTURE_COMPARE_FUNC,
	mp_list<oglplus::texture_parameter,oglplus::sampler_parameter>
> enum_value::texture_compare_func;
#endif

#ifdef GL_TEXTURE_COMPARE_MODE
const enum_value<
	GLenum,
	GL_TEXTURE_COMPARE_MODE,
	mp_list<oglplus::texture_parameter,oglplus::sampler_parameter>
> enum_value::texture_compare_mode;
#endif

#ifdef GL_TEXTURE_COMPRESSION_HINT
const enum_value<
	GLenum,
	GL_TEXTURE_COMPRESSION_HINT,
	mp_list<oglplus::hint_target,oglplus::numeric_query>
> enum_value::texture_compression_hint;
#endif

#ifdef GL_TEXTURE_CUBE_MAP
const enum_value<
	GLenum,
	GL_TEXTURE_CUBE_MAP,
	mp_list<oglplus::texture_target>
> enum_value::texture_cube_map;
#endif

#ifdef GL_TEXTURE_CUBE_MAP_ARRAY
const enum_value<
	GLenum,
	GL_TEXTURE_CUBE_MAP_ARRAY,
	mp_list<oglplus::texture_target>
> enum_value::texture_cube_map_array;
#endif

#ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_X
const enum_value<
	GLenum,
	GL_TEXTURE_CUBE_MAP_NEGATIVE_X,
	mp_list<oglplus::texture_target>
> enum_value::texture_cube_map_negative_x;
#endif

#ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_Y
const enum_value<
	GLenum,
	GL_TEXTURE_CUBE_MAP_NEGATIVE_Y,
	mp_list<oglplus::texture_target>
> enum_value::texture_cube_map_negative_y;
#endif

#ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_Z
const enum_value<
	GLenum,
	GL_TEXTURE_CUBE_MAP_NEGATIVE_Z,
	mp_list<oglplus::texture_target>
> enum_value::texture_cube_map_negative_z;
#endif

#ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_X
const enum_value<
	GLenum,
	GL_TEXTURE_CUBE_MAP_POSITIVE_X,
	mp_list<oglplus::texture_target>
> enum_value::texture_cube_map_positive_x;
#endif

#ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_Y
const enum_value<
	GLenum,
	GL_TEXTURE_CUBE_MAP_POSITIVE_Y,
	mp_list<oglplus::texture_target>
> enum_value::texture_cube_map_positive_y;
#endif

#ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_Z
const enum_value<
	GLenum,
	GL_TEXTURE_CUBE_MAP_POSITIVE_Z,
	mp_list<oglplus::texture_target>
> enum_value::texture_cube_map_positive_z;
#endif

#ifdef GL_TEXTURE_CUBE_MAP_SEAMLESS
const enum_value<
	GLenum,
	GL_TEXTURE_CUBE_MAP_SEAMLESS,
	mp_list<oglplus::capability>
> enum_value::texture_cube_map_seamless;
#endif

#ifdef GL_TEXTURE_FETCH_BARRIER_BIT
const enum_value<
	GLbitfield,
	GL_TEXTURE_FETCH_BARRIER_BIT,
	mp_list<oglplus::memory_barrier_bits>
> enum_value::texture_fetch_barrier_bit;
#endif

#ifdef GL_TEXTURE_IMMUTABLE_FORMAT
const enum_value<
	GLenum,
	GL_TEXTURE_IMMUTABLE_FORMAT,
	mp_list<oglplus::texture_parameter>
> enum_value::texture_immutable_format;
#endif

#ifdef GL_TEXTURE_IMMUTABLE_LEVELS
const enum_value<
	GLenum,
	GL_TEXTURE_IMMUTABLE_LEVELS,
	mp_list<oglplus::texture_parameter>
> enum_value::texture_immutable_levels;
#endif

#ifdef GL_TEXTURE_LOD_BIAS
const enum_value<
	GLenum,
	GL_TEXTURE_LOD_BIAS,
	mp_list<oglplus::texture_parameter,oglplus::sampler_parameter>
> enum_value::texture_lod_bias;
#endif

#ifdef GL_TEXTURE_MAG_FILTER
const enum_value<
	GLenum,
	GL_TEXTURE_MAG_FILTER,
	mp_list<oglplus::texture_parameter,oglplus::sampler_parameter>
> enum_value::texture_mag_filter;
#endif

#ifdef GL_TEXTURE_MAX_LEVEL
const enum_value<
	GLenum,
	GL_TEXTURE_MAX_LEVEL,
	mp_list<oglplus::texture_parameter>
> enum_value::texture_max_level;
#endif

#ifdef GL_TEXTURE_MAX_LOD
const enum_value<
	GLenum,
	GL_TEXTURE_MAX_LOD,
	mp_list<oglplus::texture_parameter,oglplus::sampler_parameter>
> enum_value::texture_max_lod;
#endif

#ifdef GL_TEXTURE_MIN_FILTER
const enum_value<
	GLenum,
	GL_TEXTURE_MIN_FILTER,
	mp_list<oglplus::texture_parameter,oglplus::sampler_parameter>
> enum_value::texture_min_filter;
#endif

#ifdef GL_TEXTURE_MIN_LOD
const enum_value<
	GLenum,
	GL_TEXTURE_MIN_LOD,
	mp_list<oglplus::texture_parameter,oglplus::sampler_parameter>
> enum_value::texture_min_lod;
#endif

#ifdef GL_TEXTURE_RECTANGLE
const enum_value<
	GLenum,
	GL_TEXTURE_RECTANGLE,
	mp_list<oglplus::texture_target>
> enum_value::texture_rectangle;
#endif

#ifdef GL_TEXTURE_SWIZZLE_A
const enum_value<
	GLenum,
	GL_TEXTURE_SWIZZLE_A,
	mp_list<oglplus::texture_parameter,oglplus::texture_swizzle_coord>
> enum_value::texture_swizzle_a;
#endif

#ifdef GL_TEXTURE_SWIZZLE_B
const enum_value<
	GLenum,
	GL_TEXTURE_SWIZZLE_B,
	mp_list<oglplus::texture_parameter,oglplus::texture_swizzle_coord>
> enum_value::texture_swizzle_b;
#endif

#ifdef GL_TEXTURE_SWIZZLE_G
const enum_value<
	GLenum,
	GL_TEXTURE_SWIZZLE_G,
	mp_list<oglplus::texture_parameter,oglplus::texture_swizzle_coord>
> enum_value::texture_swizzle_g;
#endif

#ifdef GL_TEXTURE_SWIZZLE_R
const enum_value<
	GLenum,
	GL_TEXTURE_SWIZZLE_R,
	mp_list<oglplus::texture_parameter,oglplus::texture_swizzle_coord>
> enum_value::texture_swizzle_r;
#endif

#ifdef GL_TEXTURE_SWIZZLE_RGBA
const enum_value<
	GLenum,
	GL_TEXTURE_SWIZZLE_RGBA,
	mp_list<oglplus::texture_parameter,oglplus::texture_swizzle_coord>
> enum_value::texture_swizzle_rgba;
#endif

#ifdef GL_TEXTURE_TARGET
const enum_value<
	GLenum,
	GL_TEXTURE_TARGET,
	mp_list<oglplus::texture_parameter>
> enum_value::texture_target;
#endif

#ifdef GL_TEXTURE_UPDATE_BARRIER_BIT
const enum_value<
	GLbitfield,
	GL_TEXTURE_UPDATE_BARRIER_BIT,
	mp_list<oglplus::memory_barrier_bits>
> enum_value::texture_update_barrier_bit;
#endif

#ifdef GL_TEXTURE_VIEW_MIN_LAYER
const enum_value<
	GLenum,
	GL_TEXTURE_VIEW_MIN_LAYER,
	mp_list<oglplus::texture_parameter>
> enum_value::texture_view_min_layer;
#endif

#ifdef GL_TEXTURE_VIEW_MIN_LEVEL
const enum_value<
	GLenum,
	GL_TEXTURE_VIEW_MIN_LEVEL,
	mp_list<oglplus::texture_parameter>
> enum_value::texture_view_min_level;
#endif

#ifdef GL_TEXTURE_VIEW_NUM_LAYERS
const enum_value<
	GLenum,
	GL_TEXTURE_VIEW_NUM_LAYERS,
	mp_list<oglplus::texture_parameter>
> enum_value::texture_view_num_layers;
#endif

#ifdef GL_TEXTURE_VIEW_NUM_LEVELS
const enum_value<
	GLenum,
	GL_TEXTURE_VIEW_NUM_LEVELS,
	mp_list<oglplus::texture_parameter>
> enum_value::texture_view_num_levels;
#endif

#ifdef GL_TEXTURE_WRAP_R
const enum_value<
	GLenum,
	GL_TEXTURE_WRAP_R,
	mp_list<oglplus::texture_parameter,oglplus::sampler_parameter,oglplus::texture_wrap_coord>
> enum_value::texture_wrap_r;
#endif

#ifdef GL_TEXTURE_WRAP_S
const enum_value<
	GLenum,
	GL_TEXTURE_WRAP_S,
	mp_list<oglplus::texture_parameter,oglplus::sampler_parameter,oglplus::texture_wrap_coord>
> enum_value::texture_wrap_s;
#endif

#ifdef GL_TEXTURE_WRAP_T
const enum_value<
	GLenum,
	GL_TEXTURE_WRAP_T,
	mp_list<oglplus::texture_parameter,oglplus::sampler_parameter,oglplus::texture_wrap_coord>
> enum_value::texture_wrap_t;
#endif

#ifdef GL_TIME_ELAPSED
const enum_value<
	GLenum,
	GL_TIME_ELAPSED,
	mp_list<oglplus::query_target>
> enum_value::time_elapsed;
#endif

#ifdef GL_TIMEOUT_EXPIRED
const enum_value<
	GLenum,
	GL_TIMEOUT_EXPIRED,
	mp_list<oglplus::sync_wait_result>
> enum_value::timeout_expired;
#endif

#ifdef GL_TIMESTAMP
const enum_value<
	GLenum,
	GL_TIMESTAMP,
	mp_list<oglplus::query_target,oglplus::numeric_query>
> enum_value::timestamp;
#endif

#ifdef GL_TOP_LEVEL_ARRAY_SIZE
const enum_value<
	GLenum,
	GL_TOP_LEVEL_ARRAY_SIZE,
	mp_list<oglplus::program_resource_property>
> enum_value::top_level_array_size;
#endif

#ifdef GL_TOP_LEVEL_ARRAY_STRIDE
const enum_value<
	GLenum,
	GL_TOP_LEVEL_ARRAY_STRIDE,
	mp_list<oglplus::program_resource_property>
> enum_value::top_level_array_stride;
#endif

#ifdef GL_TRANSFORM_FEEDBACK
const enum_value<
	GLenum,
	GL_TRANSFORM_FEEDBACK,
	mp_list<oglplus::transform_feedback_target,oglplus::object_type>
> enum_value::transform_feedback;
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BARRIER_BIT
const enum_value<
	GLbitfield,
	GL_TRANSFORM_FEEDBACK_BARRIER_BIT,
	mp_list<oglplus::memory_barrier_bits>
> enum_value::transform_feedback_barrier_bit;
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BINDING
const enum_value<
	GLenum,
	GL_TRANSFORM_FEEDBACK_BINDING,
	mp_list<oglplus::binding_query>
> enum_value::transform_feedback_binding;
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BUFFER
const enum_value<
	GLenum,
	GL_TRANSFORM_FEEDBACK_BUFFER,
	mp_list<oglplus::buffer_indexed_target,oglplus::buffer_target>
> enum_value::transform_feedback_buffer;
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_BINDING
const enum_value<
	GLenum,
	GL_TRANSFORM_FEEDBACK_BUFFER_BINDING,
	mp_list<oglplus::binding_query>
> enum_value::transform_feedback_buffer_binding;
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_INDEX
const enum_value<
	GLenum,
	GL_TRANSFORM_FEEDBACK_BUFFER_INDEX,
	mp_list<oglplus::program_resource_property>
> enum_value::transform_feedback_buffer_index;
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
const enum_value<
	GLenum,
	GL_TRANSFORM_FEEDBACK_BUFFER_SIZE,
	mp_list<oglplus::numeric_query>
> enum_value::transform_feedback_buffer_size;
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
const enum_value<
	GLenum,
	GL_TRANSFORM_FEEDBACK_BUFFER_START,
	mp_list<oglplus::numeric_query>
> enum_value::transform_feedback_buffer_start;
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE
const enum_value<
	GLenum,
	GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE,
	mp_list<oglplus::program_resource_property>
> enum_value::transform_feedback_buffer_stride;
#endif

#ifdef GL_TRANSFORM_FEEDBACK_OVERFLOW_ARB
const enum_value<
	GLenum,
	GL_TRANSFORM_FEEDBACK_OVERFLOW_ARB,
	mp_list<oglplus::query_target>
> enum_value::transform_feedback_overflow;
#endif

#ifdef GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN
const enum_value<
	GLenum,
	GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN,
	mp_list<oglplus::query_target>
> enum_value::transform_feedback_primitives_written;
#endif

#ifdef GL_TRANSFORM_FEEDBACK_STREAM_OVERFLOW_ARB
const enum_value<
	GLenum,
	GL_TRANSFORM_FEEDBACK_STREAM_OVERFLOW_ARB,
	mp_list<oglplus::query_target>
> enum_value::transform_feedback_stream_overflow;
#endif

#ifdef GL_TRANSFORM_FEEDEBACK_VARYING
const enum_value<
	GLenum,
	GL_TRANSFORM_FEEDEBACK_VARYING,
	mp_list<oglplus::program_interface>
> enum_value::transform_feedeback_varying;
#endif

#ifdef GL_TRANSLATE_2D_NV
const enum_value<
	GLenum,
	GL_TRANSLATE_2D_NV,
	mp_list<oglplus::path_transform_type_nv>
> enum_value::translate_2d_nv;
#endif

#ifdef GL_TRANSLATE_3D_NV
const enum_value<
	GLenum,
	GL_TRANSLATE_3D_NV,
	mp_list<oglplus::path_transform_type_nv>
> enum_value::translate_3d_nv;
#endif

#ifdef GL_TRANSLATE_X_NV
const enum_value<
	GLenum,
	GL_TRANSLATE_X_NV,
	mp_list<oglplus::path_transform_type_nv>
> enum_value::translate_x_nv;
#endif

#ifdef GL_TRANSLATE_Y_NV
const enum_value<
	GLenum,
	GL_TRANSLATE_Y_NV,
	mp_list<oglplus::path_transform_type_nv>
> enum_value::translate_y_nv;
#endif

#ifdef GL_TRANSPOSE_AFFINE_2D_NV
const enum_value<
	GLenum,
	GL_TRANSPOSE_AFFINE_2D_NV,
	mp_list<oglplus::path_transform_type_nv>
> enum_value::transpose_affine_2d_nv;
#endif

#ifdef GL_TRANSPOSE_AFFINE_3D_NV
const enum_value<
	GLenum,
	GL_TRANSPOSE_AFFINE_3D_NV,
	mp_list<oglplus::path_transform_type_nv>
> enum_value::transpose_affine_3d_nv;
#endif

#ifdef GL_TRIANGLE_FAN
const enum_value<
	GLenum,
	GL_TRIANGLE_FAN,
	mp_list<oglplus::primitive_type,oglplus::old_primitive_type>
> enum_value::triangle_fan;
#endif

#ifdef GL_TRIANGLE_STRIP
const enum_value<
	GLenum,
	GL_TRIANGLE_STRIP,
	mp_list<oglplus::primitive_type,oglplus::old_primitive_type>
> enum_value::triangle_strip;
#endif

#ifdef GL_TRIANGLE_STRIP_ADJACENCY
const enum_value<
	GLenum,
	GL_TRIANGLE_STRIP_ADJACENCY,
	mp_list<oglplus::primitive_type>
> enum_value::triangle_strip_adjacency;
#endif

#ifdef GL_TRIANGLES
const enum_value<
	GLenum,
	GL_TRIANGLES,
	mp_list<oglplus::primitive_type,oglplus::old_primitive_type,oglplus::transform_feedback_primitive_type,oglplus::tess_gen_primitive_type>
> enum_value::triangles;
#endif

#ifdef GL_TRIANGLES_ADJACENCY
const enum_value<
	GLenum,
	GL_TRIANGLES_ADJACENCY,
	mp_list<oglplus::primitive_type>
> enum_value::triangles_adjacency;
#endif

#ifdef GL_TRIANGULAR_NV
const enum_value<
	GLenum,
	GL_TRIANGULAR_NV,
	mp_list<oglplus::path_cap_style_nv>
> enum_value::triangular_nv;
#endif

#ifdef GL_TRUE
const enum_value<
	GLboolean,
	GL_TRUE,
	mp_list<oglplus::true_false>
> enum_value::true_;
#endif

#ifdef GL_UNIFORM
const enum_value<
	GLenum,
	GL_UNIFORM,
	mp_list<oglplus::program_interface>
> enum_value::uniform;
#endif

#ifdef GL_UNIFORM_BARRIER_BIT
const enum_value<
	GLbitfield,
	GL_UNIFORM_BARRIER_BIT,
	mp_list<oglplus::memory_barrier_bits>
> enum_value::uniform_barrier_bit;
#endif

#ifdef GL_UNIFORM_BLOCK
const enum_value<
	GLenum,
	GL_UNIFORM_BLOCK,
	mp_list<oglplus::program_interface>
> enum_value::uniform_block;
#endif

#ifdef GL_UNIFORM_BUFFER
const enum_value<
	GLenum,
	GL_UNIFORM_BUFFER,
	mp_list<oglplus::buffer_indexed_target,oglplus::buffer_target>
> enum_value::uniform_buffer;
#endif

#ifdef GL_UNIFORM_BUFFER_BINDING
const enum_value<
	GLenum,
	GL_UNIFORM_BUFFER_BINDING,
	mp_list<oglplus::binding_query>
> enum_value::uniform_buffer_binding;
#endif

#ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
const enum_value<
	GLenum,
	GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT,
	mp_list<oglplus::numeric_query>
> enum_value::uniform_buffer_offset_alignment;
#endif

#ifdef GL_UNIFORM_BUFFER_SIZE
const enum_value<
	GLenum,
	GL_UNIFORM_BUFFER_SIZE,
	mp_list<oglplus::numeric_query>
> enum_value::uniform_buffer_size;
#endif

#ifdef GL_UNIFORM_BUFFER_START
const enum_value<
	GLenum,
	GL_UNIFORM_BUFFER_START,
	mp_list<oglplus::numeric_query>
> enum_value::uniform_buffer_start;
#endif

#ifdef GL_UNKNOWN_CONTEXT_RESET
const enum_value<
	GLenum,
	GL_UNKNOWN_CONTEXT_RESET,
	mp_list<oglplus::graphics_reset_status>
> enum_value::unknown_context_reset;
#endif

#ifdef GL_UNPACK_ALIGNMENT
const enum_value<
	GLenum,
	GL_UNPACK_ALIGNMENT,
	mp_list<oglplus::numeric_query,oglplus::pixel_parameter>
> enum_value::unpack_alignment;
#endif

#ifdef GL_UNPACK_COMPRESSED_BLOCK_DEPTH
const enum_value<
	GLenum,
	GL_UNPACK_COMPRESSED_BLOCK_DEPTH,
	mp_list<oglplus::pixel_parameter>
> enum_value::unpack_compressed_block_depth;
#endif

#ifdef GL_UNPACK_COMPRESSED_BLOCK_HEIGHT
const enum_value<
	GLenum,
	GL_UNPACK_COMPRESSED_BLOCK_HEIGHT,
	mp_list<oglplus::pixel_parameter>
> enum_value::unpack_compressed_block_height;
#endif

#ifdef GL_UNPACK_COMPRESSED_BLOCK_SIZE
const enum_value<
	GLenum,
	GL_UNPACK_COMPRESSED_BLOCK_SIZE,
	mp_list<oglplus::pixel_parameter>
> enum_value::unpack_compressed_block_size;
#endif

#ifdef GL_UNPACK_COMPRESSED_BLOCK_WIDTH
const enum_value<
	GLenum,
	GL_UNPACK_COMPRESSED_BLOCK_WIDTH,
	mp_list<oglplus::pixel_parameter>
> enum_value::unpack_compressed_block_width;
#endif

#ifdef GL_UNPACK_IMAGE_HEIGHT
const enum_value<
	GLenum,
	GL_UNPACK_IMAGE_HEIGHT,
	mp_list<oglplus::numeric_query,oglplus::pixel_parameter>
> enum_value::unpack_image_height;
#endif

#ifdef GL_UNPACK_LSB_FIRST
const enum_value<
	GLenum,
	GL_UNPACK_LSB_FIRST,
	mp_list<oglplus::numeric_query,oglplus::pixel_parameter>
> enum_value::unpack_lsb_first;
#endif

#ifdef GL_UNPACK_ROW_LENGTH
const enum_value<
	GLenum,
	GL_UNPACK_ROW_LENGTH,
	mp_list<oglplus::numeric_query,oglplus::pixel_parameter>
> enum_value::unpack_row_length;
#endif

#ifdef GL_UNPACK_SKIP_IMAGES
const enum_value<
	GLenum,
	GL_UNPACK_SKIP_IMAGES,
	mp_list<oglplus::numeric_query,oglplus::pixel_parameter>
> enum_value::unpack_skip_images;
#endif

#ifdef GL_UNPACK_SKIP_PIXELS
const enum_value<
	GLenum,
	GL_UNPACK_SKIP_PIXELS,
	mp_list<oglplus::numeric_query,oglplus::pixel_parameter>
> enum_value::unpack_skip_pixels;
#endif

#ifdef GL_UNPACK_SKIP_ROWS
const enum_value<
	GLenum,
	GL_UNPACK_SKIP_ROWS,
	mp_list<oglplus::numeric_query,oglplus::pixel_parameter>
> enum_value::unpack_skip_rows;
#endif

#ifdef GL_UNPACK_SWAP_BYTES
const enum_value<
	GLenum,
	GL_UNPACK_SWAP_BYTES,
	mp_list<oglplus::numeric_query,oglplus::pixel_parameter>
> enum_value::unpack_swap_bytes;
#endif

#ifdef GL_UNSIGNALED
const enum_value<
	GLenum,
	GL_UNSIGNALED,
	mp_list<oglplus::sync_status>
> enum_value::unsignaled;
#endif

#ifdef GL_UNSIGNED_BYTE
const enum_value<
	GLenum,
	GL_UNSIGNED_BYTE,
	mp_list<oglplus::index_type,oglplus::pixel_data_type,oglplus::data_type>
> enum_value::unsigned_byte;
#endif

#ifdef GL_UNSIGNED_BYTE_2_3_3_REV
const enum_value<
	GLenum,
	GL_UNSIGNED_BYTE_2_3_3_REV,
	mp_list<oglplus::pixel_data_type>
> enum_value::unsigned_byte_2_3_3_rev;
#endif

#ifdef GL_UNSIGNED_BYTE_3_3_2
const enum_value<
	GLenum,
	GL_UNSIGNED_BYTE_3_3_2,
	mp_list<oglplus::pixel_data_type>
> enum_value::unsigned_byte_3_3_2;
#endif

#ifdef GL_UNSIGNED_INT
const enum_value<
	GLenum,
	GL_UNSIGNED_INT,
	mp_list<oglplus::index_type,oglplus::sl_data_type,oglplus::pixel_data_type,oglplus::data_type>
> enum_value::unsigned_int;
#endif

#ifdef GL_UNSIGNED_INT_10_10_10_2
const enum_value<
	GLenum,
	GL_UNSIGNED_INT_10_10_10_2,
	mp_list<oglplus::pixel_data_type>
> enum_value::unsigned_int_10_10_10_2;
#endif

#ifdef GL_UNSIGNED_INT_10F_11F_11F_REV
const enum_value<
	GLenum,
	GL_UNSIGNED_INT_10F_11F_11F_REV,
	mp_list<oglplus::pixel_data_type>
> enum_value::unsigned_int_10f_11f_11f_rev;
#endif

#ifdef GL_UNSIGNED_INT_24_8
const enum_value<
	GLenum,
	GL_UNSIGNED_INT_24_8,
	mp_list<oglplus::pixel_data_type>
> enum_value::unsigned_int_24_8;
#endif

#ifdef GL_UNSIGNED_INT_2_10_10_10_REV
const enum_value<
	GLenum,
	GL_UNSIGNED_INT_2_10_10_10_REV,
	mp_list<oglplus::pixel_data_type>
> enum_value::unsigned_int_2_10_10_10_rev;
#endif

#ifdef GL_UNSIGNED_INT_5_9_9_9_REV
const enum_value<
	GLenum,
	GL_UNSIGNED_INT_5_9_9_9_REV,
	mp_list<oglplus::pixel_data_type>
> enum_value::unsigned_int_5_9_9_9_rev;
#endif

#ifdef GL_UNSIGNED_INT_8_8_8_8
const enum_value<
	GLenum,
	GL_UNSIGNED_INT_8_8_8_8,
	mp_list<oglplus::pixel_data_type>
> enum_value::unsigned_int_8_8_8_8;
#endif

#ifdef GL_UNSIGNED_INT_8_8_8_8_REV
const enum_value<
	GLenum,
	GL_UNSIGNED_INT_8_8_8_8_REV,
	mp_list<oglplus::pixel_data_type>
> enum_value::unsigned_int_8_8_8_8_rev;
#endif

#ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
const enum_value<
	GLenum,
	GL_UNSIGNED_INT_ATOMIC_COUNTER,
	mp_list<oglplus::sl_data_type>
> enum_value::unsigned_int_atomic_counter;
#endif

#ifdef GL_UNSIGNED_INT_IMAGE_1D
const enum_value<
	GLenum,
	GL_UNSIGNED_INT_IMAGE_1D,
	mp_list<oglplus::sl_data_type>
> enum_value::unsigned_int_image_1d;
#endif

#ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
const enum_value<
	GLenum,
	GL_UNSIGNED_INT_IMAGE_1D_ARRAY,
	mp_list<oglplus::sl_data_type>
> enum_value::unsigned_int_image_1d_array;
#endif

#ifdef GL_UNSIGNED_INT_IMAGE_2D
const enum_value<
	GLenum,
	GL_UNSIGNED_INT_IMAGE_2D,
	mp_list<oglplus::sl_data_type>
> enum_value::unsigned_int_image_2d;
#endif

#ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
const enum_value<
	GLenum,
	GL_UNSIGNED_INT_IMAGE_2D_ARRAY,
	mp_list<oglplus::sl_data_type>
> enum_value::unsigned_int_image_2d_array;
#endif

#ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
const enum_value<
	GLenum,
	GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE,
	mp_list<oglplus::sl_data_type>
> enum_value::unsigned_int_image_2d_multisample;
#endif

#ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
const enum_value<
	GLenum,
	GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY,
	mp_list<oglplus::sl_data_type>
> enum_value::unsigned_int_image_2d_multisample_array;
#endif

#ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
const enum_value<
	GLenum,
	GL_UNSIGNED_INT_IMAGE_2D_RECT,
	mp_list<oglplus::sl_data_type>
> enum_value::unsigned_int_image_2d_rect;
#endif

#ifdef GL_UNSIGNED_INT_IMAGE_3D
const enum_value<
	GLenum,
	GL_UNSIGNED_INT_IMAGE_3D,
	mp_list<oglplus::sl_data_type>
> enum_value::unsigned_int_image_3d;
#endif

#ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
const enum_value<
	GLenum,
	GL_UNSIGNED_INT_IMAGE_BUFFER,
	mp_list<oglplus::sl_data_type>
> enum_value::unsigned_int_image_buffer;
#endif

#ifdef GL_UNSIGNED_INT_IMAGE_CUBE
const enum_value<
	GLenum,
	GL_UNSIGNED_INT_IMAGE_CUBE,
	mp_list<oglplus::sl_data_type>
> enum_value::unsigned_int_image_cube;
#endif

#ifdef GL_UNSIGNED_INT_SAMPLER_1D
const enum_value<
	GLenum,
	GL_UNSIGNED_INT_SAMPLER_1D,
	mp_list<oglplus::sl_data_type>
> enum_value::unsigned_int_sampler_1d;
#endif

#ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
const enum_value<
	GLenum,
	GL_UNSIGNED_INT_SAMPLER_1D_ARRAY,
	mp_list<oglplus::sl_data_type>
> enum_value::unsigned_int_sampler_1d_array;
#endif

#ifdef GL_UNSIGNED_INT_SAMPLER_2D
const enum_value<
	GLenum,
	GL_UNSIGNED_INT_SAMPLER_2D,
	mp_list<oglplus::sl_data_type>
> enum_value::unsigned_int_sampler_2d;
#endif

#ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
const enum_value<
	GLenum,
	GL_UNSIGNED_INT_SAMPLER_2D_ARRAY,
	mp_list<oglplus::sl_data_type>
> enum_value::unsigned_int_sampler_2d_array;
#endif

#ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
const enum_value<
	GLenum,
	GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE,
	mp_list<oglplus::sl_data_type>
> enum_value::unsigned_int_sampler_2d_multisample;
#endif

#ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
const enum_value<
	GLenum,
	GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY,
	mp_list<oglplus::sl_data_type>
> enum_value::unsigned_int_sampler_2d_multisample_array;
#endif

#ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
const enum_value<
	GLenum,
	GL_UNSIGNED_INT_SAMPLER_2D_RECT,
	mp_list<oglplus::sl_data_type>
> enum_value::unsigned_int_sampler_2d_rect;
#endif

#ifdef GL_UNSIGNED_INT_SAMPLER_3D
const enum_value<
	GLenum,
	GL_UNSIGNED_INT_SAMPLER_3D,
	mp_list<oglplus::sl_data_type>
> enum_value::unsigned_int_sampler_3d;
#endif

#ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
const enum_value<
	GLenum,
	GL_UNSIGNED_INT_SAMPLER_BUFFER,
	mp_list<oglplus::sl_data_type>
> enum_value::unsigned_int_sampler_buffer;
#endif

#ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
const enum_value<
	GLenum,
	GL_UNSIGNED_INT_SAMPLER_CUBE,
	mp_list<oglplus::sl_data_type>
> enum_value::unsigned_int_sampler_cube;
#endif

#ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
const enum_value<
	GLenum,
	GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY,
	mp_list<oglplus::sl_data_type>
> enum_value::unsigned_int_sampler_cube_map_array;
#endif

#ifdef GL_UNSIGNED_INT_VEC2
const enum_value<
	GLenum,
	GL_UNSIGNED_INT_VEC2,
	mp_list<oglplus::sl_data_type>
> enum_value::unsigned_int_vec2;
#endif

#ifdef GL_UNSIGNED_INT_VEC3
const enum_value<
	GLenum,
	GL_UNSIGNED_INT_VEC3,
	mp_list<oglplus::sl_data_type>
> enum_value::unsigned_int_vec3;
#endif

#ifdef GL_UNSIGNED_INT_VEC4
const enum_value<
	GLenum,
	GL_UNSIGNED_INT_VEC4,
	mp_list<oglplus::sl_data_type>
> enum_value::unsigned_int_vec4;
#endif

#ifdef GL_UNSIGNED_SHORT
const enum_value<
	GLenum,
	GL_UNSIGNED_SHORT,
	mp_list<oglplus::index_type,oglplus::pixel_data_type,oglplus::data_type>
> enum_value::unsigned_short;
#endif

#ifdef GL_UNSIGNED_SHORT_1_5_5_5_REV
const enum_value<
	GLenum,
	GL_UNSIGNED_SHORT_1_5_5_5_REV,
	mp_list<oglplus::pixel_data_type>
> enum_value::unsigned_short_1_5_5_5_rev;
#endif

#ifdef GL_UNSIGNED_SHORT_4_4_4_4
const enum_value<
	GLenum,
	GL_UNSIGNED_SHORT_4_4_4_4,
	mp_list<oglplus::pixel_data_type>
> enum_value::unsigned_short_4_4_4_4;
#endif

#ifdef GL_UNSIGNED_SHORT_4_4_4_4_REV
const enum_value<
	GLenum,
	GL_UNSIGNED_SHORT_4_4_4_4_REV,
	mp_list<oglplus::pixel_data_type>
> enum_value::unsigned_short_4_4_4_4_rev;
#endif

#ifdef GL_UNSIGNED_SHORT_5_5_5_1
const enum_value<
	GLenum,
	GL_UNSIGNED_SHORT_5_5_5_1,
	mp_list<oglplus::pixel_data_type>
> enum_value::unsigned_short_5_5_5_1;
#endif

#ifdef GL_UNSIGNED_SHORT_5_6_5
const enum_value<
	GLenum,
	GL_UNSIGNED_SHORT_5_6_5,
	mp_list<oglplus::pixel_data_type>
> enum_value::unsigned_short_5_6_5;
#endif

#ifdef GL_UNSIGNED_SHORT_5_6_5_REV
const enum_value<
	GLenum,
	GL_UNSIGNED_SHORT_5_6_5_REV,
	mp_list<oglplus::pixel_data_type>
> enum_value::unsigned_short_5_6_5_rev;
#endif

#ifdef GL_UPPER_LEFT
const enum_value<
	GLenum,
	GL_UPPER_LEFT,
	mp_list<oglplus::clip_origin>
> enum_value::upper_left;
#endif

#ifdef GL_USE_MISSING_GLYPH_NV
const enum_value<
	GLenum,
	GL_USE_MISSING_GLYPH_NV,
	mp_list<oglplus::path_missing_glyph_nv>
> enum_value::use_missing_glyph_nv;
#endif

#ifdef GL_UTF16_NV
const enum_value<
	GLenum,
	GL_UTF16_NV,
	mp_list<oglplus::path_text_encoding_nv>
> enum_value::utf16_nv;
#endif

#ifdef GL_UTF8_NV
const enum_value<
	GLenum,
	GL_UTF8_NV,
	mp_list<oglplus::path_text_encoding_nv>
> enum_value::utf8_nv;
#endif

#ifdef GL_VALIDATE_STATUS
const enum_value<
	GLenum,
	GL_VALIDATE_STATUS,
	mp_list<oglplus::program_parameter>
> enum_value::validate_status;
#endif

#ifdef GL_VENDOR
const enum_value<
	GLenum,
	GL_VENDOR,
	mp_list<oglplus::string_query>
> enum_value::vendor;
#endif

#ifdef GL_VERSION
const enum_value<
	GLenum,
	GL_VERSION,
	mp_list<oglplus::string_query>
> enum_value::version;
#endif

#ifdef GL_VERTEX_ARRAY
const enum_value<
	GLenum,
	GL_VERTEX_ARRAY,
	mp_list<oglplus::object_type>
> enum_value::vertex_array;
#endif

#ifdef GL_VERTEX_ARRAY_BINDING
const enum_value<
	GLenum,
	GL_VERTEX_ARRAY_BINDING,
	mp_list<oglplus::binding_query>
> enum_value::vertex_array_binding;
#endif

#ifdef GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT
const enum_value<
	GLbitfield,
	GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT,
	mp_list<oglplus::memory_barrier_bits>
> enum_value::vertex_attrib_array_barrier_bit;
#endif

#ifdef GL_VERTEX_SHADER
const enum_value<
	GLenum,
	GL_VERTEX_SHADER,
	mp_list<oglplus::shader_type,oglplus::program_pipeline_parameter>
> enum_value::vertex_shader;
#endif

#ifdef GL_VERTEX_SHADER_BIT
const enum_value<
	GLbitfield,
	GL_VERTEX_SHADER_BIT,
	mp_list<oglplus::program_pipeline_stage>
> enum_value::vertex_shader_bit;
#endif

#ifdef GL_VERTEX_SHADER_INVOCATIONS_ARB
const enum_value<
	GLenum,
	GL_VERTEX_SHADER_INVOCATIONS_ARB,
	mp_list<oglplus::query_target>
> enum_value::vertex_shader_invocations;
#endif

#ifdef GL_VERTEX_SUBROUTINE
const enum_value<
	GLenum,
	GL_VERTEX_SUBROUTINE,
	mp_list<oglplus::program_interface>
> enum_value::vertex_subroutine;
#endif

#ifdef GL_VERTEX_SUBROUTINE_UNIFORM
const enum_value<
	GLenum,
	GL_VERTEX_SUBROUTINE_UNIFORM,
	mp_list<oglplus::program_interface>
> enum_value::vertex_subroutine_uniform;
#endif

#ifdef GL_VERTICAL_LINE_TO_NV
const enum_value<
	GLubyte,
	GL_VERTICAL_LINE_TO_NV,
	mp_list<oglplus::path_command_nv>
> enum_value::vertical_line_to_nv;
#endif

#ifdef GL_VERTICES_SUBMITTED_ARB
const enum_value<
	GLenum,
	GL_VERTICES_SUBMITTED_ARB,
	mp_list<oglplus::query_target>
> enum_value::vertices_submitted;
#endif

#ifdef GL_VIEWPORT
const enum_value<
	GLenum,
	GL_VIEWPORT,
	mp_list<oglplus::numeric_query>
> enum_value::viewport;
#endif

#ifdef GL_VIEWPORT_BOUNDS_RANGE
const enum_value<
	GLenum,
	GL_VIEWPORT_BOUNDS_RANGE,
	mp_list<oglplus::numeric_query>
> enum_value::viewport_bounds_range;
#endif

#ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
const enum_value<
	GLenum,
	GL_VIEWPORT_INDEX_PROVOKING_VERTEX,
	mp_list<oglplus::numeric_query>
> enum_value::viewport_index_provoking_vertex;
#endif

#ifdef GL_VIEWPORT_SUBPIXEL_BITS
const enum_value<
	GLenum,
	GL_VIEWPORT_SUBPIXEL_BITS,
	mp_list<oglplus::numeric_query>
> enum_value::viewport_subpixel_bits;
#endif

#ifdef GL_WAIT_FAILED
const enum_value<
	GLenum,
	GL_WAIT_FAILED,
	mp_list<oglplus::sync_wait_result>
> enum_value::wait_failed;
#endif

#ifdef GL_WRITE_ONLY
const enum_value<
	GLenum,
	GL_WRITE_ONLY,
	mp_list<oglplus::access_specifier>
> enum_value::write_only;
#endif

#ifdef GL_XOR
const enum_value<
	GLenum,
	GL_XOR,
	mp_list<oglplus::color_logic_operation>
> enum_value::xor_;
#endif

#ifdef GL_ZERO
const enum_value<
	GLenum,
	GL_ZERO,
	mp_list<oglplus::blend_function,oglplus::texture_swizzle_mode,oglplus::stencil_operation>
> enum_value::zero;
#endif

#ifdef GL_ZERO_TO_ONE
const enum_value<
	GLenum,
	GL_ZERO_TO_ONE,
	mp_list<oglplus::clip_depth_mode>
> enum_value::zero_to_one;
#endif

} // namespace oglplus

#endif // include guard
