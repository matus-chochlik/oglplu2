//  File include/oglplus/enum/types.hpp
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
#ifndef OGLPLUS_GL_ENUM_TYPES_HPP
#define OGLPLUS_GL_ENUM_TYPES_HPP

#include "../utils/enum_class.hpp"

namespace oglplus {

struct access_specifier
 : enum_class<access_specifier, GLenum, 0>
{ using enum_class::enum_class; };

struct binding_query
 : enum_class<binding_query, GLenum, 1>
{ using enum_class::enum_class; };

struct blend_equation
 : enum_class<blend_equation, GLenum, 2>
{ using enum_class::enum_class; };

struct blend_equation_advanced
 : enum_class<blend_equation_advanced, GLenum, 3>
{ using enum_class::enum_class; };

struct blend_function
 : enum_class<blend_function, GLenum, 4>
{ using enum_class::enum_class; };

struct blit_filter
 : enum_class<blit_filter, GLenum, 5>
{ using enum_class::enum_class; };

struct buffer_indexed_target
 : enum_class<buffer_indexed_target, GLenum, 6>
{ using enum_class::enum_class; };

struct buffer_map_access
 : enum_class<buffer_map_access, GLbitfield, 7>
{ using enum_class::enum_class; };

struct buffer_parameter
 : enum_class<buffer_parameter, GLenum, 8>
{ using enum_class::enum_class; };

struct buffer_select_bits
 : enum_class<buffer_select_bits, GLbitfield, 9>
{ using enum_class::enum_class; };

struct buffer_storage_bits
 : enum_class<buffer_storage_bits, GLbitfield, 10>
{ using enum_class::enum_class; };

struct buffer_target
 : enum_class<buffer_target, GLenum, 11>
{ using enum_class::enum_class; };

struct buffer_usage
 : enum_class<buffer_usage, GLenum, 12>
{ using enum_class::enum_class; };

struct capability
 : enum_class<capability, GLenum, 13>
{ using enum_class::enum_class; };

struct client_capability
 : enum_class<client_capability, GLenum, 14>
{ using enum_class::enum_class; };

struct clip_depth_mode
 : enum_class<clip_depth_mode, GLenum, 15>
{ using enum_class::enum_class; };

struct clip_origin
 : enum_class<clip_origin, GLenum, 16>
{ using enum_class::enum_class; };

struct color_buffer
 : enum_class<color_buffer, GLenum, 17>
{ using enum_class::enum_class; };

struct color_logic_operation
 : enum_class<color_logic_operation, GLenum, 18>
{ using enum_class::enum_class; };

struct command_token_nv
 : enum_class<command_token_nv, GLenum, 19>
{ using enum_class::enum_class; };

struct compare_function
 : enum_class<compare_function, GLenum, 20>
{ using enum_class::enum_class; };

struct conditional_render_mode
 : enum_class<conditional_render_mode, GLenum, 21>
{ using enum_class::enum_class; };

struct context_flag_bits
 : enum_class<context_flag_bits, GLbitfield, 22>
{ using enum_class::enum_class; };

struct context_profile_bits
 : enum_class<context_profile_bits, GLbitfield, 23>
{ using enum_class::enum_class; };

struct context_release_behavior
 : enum_class<context_release_behavior, GLenum, 24>
{ using enum_class::enum_class; };

struct data_type
 : enum_class<data_type, GLenum, 25>
{ using enum_class::enum_class; };

struct debug_output_severity
 : enum_class<debug_output_severity, GLenum, 26>
{ using enum_class::enum_class; };

struct debug_output_source
 : enum_class<debug_output_source, GLenum, 27>
{ using enum_class::enum_class; };

struct debug_output_type
 : enum_class<debug_output_type, GLenum, 28>
{ using enum_class::enum_class; };

struct error_code
 : enum_class<error_code, GLenum, 29>
{ using enum_class::enum_class; };

struct face
 : enum_class<face, GLenum, 30>
{ using enum_class::enum_class; };

struct face_orientation
 : enum_class<face_orientation, GLenum, 31>
{ using enum_class::enum_class; };

struct framebuffer_buffer
 : enum_class<framebuffer_buffer, GLenum, 32>
{ using enum_class::enum_class; };

struct framebuffer_other_attachment
 : enum_class<framebuffer_other_attachment, GLenum, 33>
{ using enum_class::enum_class; };

struct framebuffer_status
 : enum_class<framebuffer_status, GLenum, 34>
{ using enum_class::enum_class; };

struct framebuffer_target
 : enum_class<framebuffer_target, GLenum, 35>
{ using enum_class::enum_class; };

struct graphics_reset_status
 : enum_class<graphics_reset_status, GLenum, 36>
{ using enum_class::enum_class; };

struct hint_option
 : enum_class<hint_option, GLenum, 37>
{ using enum_class::enum_class; };

struct hint_target
 : enum_class<hint_target, GLenum, 38>
{ using enum_class::enum_class; };

struct image_unit_format
 : enum_class<image_unit_format, GLenum, 39>
{ using enum_class::enum_class; };

struct index_type
 : enum_class<index_type, GLenum, 40>
{ using enum_class::enum_class; };

struct indexed_value_base
 : enum_class<indexed_value_base, GLenum, 41>
{ using enum_class::enum_class; };

struct limit_query
 : enum_class<limit_query, GLenum, 42>
{ using enum_class::enum_class; };

struct memory_barrier_bits
 : enum_class<memory_barrier_bits, GLbitfield, 43>
{ using enum_class::enum_class; };

struct named_string_param
 : enum_class<named_string_param, GLenum, 44>
{ using enum_class::enum_class; };

struct named_string_type
 : enum_class<named_string_type, GLenum, 45>
{ using enum_class::enum_class; };

struct numeric_query
 : enum_class<numeric_query, GLenum, 46>
{ using enum_class::enum_class; };

struct object_type
 : enum_class<object_type, GLenum, 47>
{ using enum_class::enum_class; };

struct old_matrix_mode
 : enum_class<old_matrix_mode, GLenum, 48>
{ using enum_class::enum_class; };

struct old_primitive_type
 : enum_class<old_primitive_type, GLenum, 49>
{ using enum_class::enum_class; };

struct patch_parameter
 : enum_class<patch_parameter, GLenum, 50>
{ using enum_class::enum_class; };

struct path_cap_style_nv
 : enum_class<path_cap_style_nv, GLenum, 51>
{ using enum_class::enum_class; };

struct path_color_format_nv
 : enum_class<path_color_format_nv, GLenum, 52>
{ using enum_class::enum_class; };

struct path_color_nv
 : enum_class<path_color_nv, GLenum, 53>
{ using enum_class::enum_class; };

struct path_command_nv
 : enum_class<path_command_nv, GLubyte, 54>
{ using enum_class::enum_class; };

struct path_dash_offset_reset_nv
 : enum_class<path_dash_offset_reset_nv, GLenum, 55>
{ using enum_class::enum_class; };

struct path_fill_cover_mode_nv
 : enum_class<path_fill_cover_mode_nv, GLenum, 56>
{ using enum_class::enum_class; };

struct path_fill_mode_nv
 : enum_class<path_fill_mode_nv, GLenum, 57>
{ using enum_class::enum_class; };

struct path_font_style_nv
 : enum_class<path_font_style_nv, GLbitfield, 58>
{ using enum_class::enum_class; };

struct path_font_target_nv
 : enum_class<path_font_target_nv, GLenum, 59>
{ using enum_class::enum_class; };

struct path_format_nv
 : enum_class<path_format_nv, GLenum, 60>
{ using enum_class::enum_class; };

struct path_gen_mode_nv
 : enum_class<path_gen_mode_nv, GLenum, 61>
{ using enum_class::enum_class; };

struct path_join_style_nv
 : enum_class<path_join_style_nv, GLenum, 62>
{ using enum_class::enum_class; };

struct path_list_mode_nv
 : enum_class<path_list_mode_nv, GLenum, 63>
{ using enum_class::enum_class; };

struct path_metric_query_nv
 : enum_class<path_metric_query_nv, GLbitfield, 64>
{ using enum_class::enum_class; };

struct path_missing_glyph_nv
 : enum_class<path_missing_glyph_nv, GLenum, 65>
{ using enum_class::enum_class; };

struct path_parameter_nv
 : enum_class<path_parameter_nv, GLenum, 66>
{ using enum_class::enum_class; };

struct path_stroke_cover_mode_nv
 : enum_class<path_stroke_cover_mode_nv, GLenum, 67>
{ using enum_class::enum_class; };

struct path_text_encoding_nv
 : enum_class<path_text_encoding_nv, GLenum, 68>
{ using enum_class::enum_class; };

struct path_transform_type_nv
 : enum_class<path_transform_type_nv, GLenum, 69>
{ using enum_class::enum_class; };

struct pixel_data_format
 : enum_class<pixel_data_format, GLenum, 70>
{ using enum_class::enum_class; };

struct pixel_data_internal_format
 : enum_class<pixel_data_internal_format, GLenum, 71>
{ using enum_class::enum_class; };

struct pixel_data_type
 : enum_class<pixel_data_type, GLenum, 72>
{ using enum_class::enum_class; };

struct pixel_parameter
 : enum_class<pixel_parameter, GLenum, 73>
{ using enum_class::enum_class; };

struct point_parameter
 : enum_class<point_parameter, GLenum, 74>
{ using enum_class::enum_class; };

struct polygon_mode
 : enum_class<polygon_mode, GLenum, 75>
{ using enum_class::enum_class; };

struct precision_type
 : enum_class<precision_type, GLenum, 76>
{ using enum_class::enum_class; };

struct primitive_type
 : enum_class<primitive_type, GLenum, 77>
{ using enum_class::enum_class; };

struct program_interface
 : enum_class<program_interface, GLenum, 78>
{ using enum_class::enum_class; };

struct program_parameter
 : enum_class<program_parameter, GLenum, 79>
{ using enum_class::enum_class; };

struct program_pipeline_parameter
 : enum_class<program_pipeline_parameter, GLenum, 80>
{ using enum_class::enum_class; };

struct program_pipeline_stage
 : enum_class<program_pipeline_stage, GLbitfield, 81>
{ using enum_class::enum_class; };

struct program_resource_property
 : enum_class<program_resource_property, GLenum, 82>
{ using enum_class::enum_class; };

struct provoke_mode
 : enum_class<provoke_mode, GLenum, 83>
{ using enum_class::enum_class; };

struct query_parameter
 : enum_class<query_parameter, GLenum, 84>
{ using enum_class::enum_class; };

struct query_target
 : enum_class<query_target, GLenum, 85>
{ using enum_class::enum_class; };

struct renderbuffer_parameter
 : enum_class<renderbuffer_parameter, GLenum, 86>
{ using enum_class::enum_class; };

struct renderbuffer_target
 : enum_class<renderbuffer_target, GLenum, 87>
{ using enum_class::enum_class; };

struct reset_notification_strategy
 : enum_class<reset_notification_strategy, GLenum, 88>
{ using enum_class::enum_class; };

struct sampler_parameter
 : enum_class<sampler_parameter, GLenum, 89>
{ using enum_class::enum_class; };

struct shader_parameter
 : enum_class<shader_parameter, GLenum, 90>
{ using enum_class::enum_class; };

struct shader_type
 : enum_class<shader_type, GLenum, 91>
{ using enum_class::enum_class; };

struct single_face
 : enum_class<single_face, GLenum, 92>
{ using enum_class::enum_class; };

struct sl_data_type
 : enum_class<sl_data_type, GLenum, 93>
{ using enum_class::enum_class; };

struct stencil_operation
 : enum_class<stencil_operation, GLenum, 94>
{ using enum_class::enum_class; };

struct string_query
 : enum_class<string_query, GLenum, 95>
{ using enum_class::enum_class; };

struct sync_condition
 : enum_class<sync_condition, GLenum, 96>
{ using enum_class::enum_class; };

struct sync_status
 : enum_class<sync_status, GLenum, 97>
{ using enum_class::enum_class; };

struct sync_type
 : enum_class<sync_type, GLenum, 98>
{ using enum_class::enum_class; };

struct sync_wait_result
 : enum_class<sync_wait_result, GLenum, 99>
{ using enum_class::enum_class; };

struct tess_gen_primitive_spacing
 : enum_class<tess_gen_primitive_spacing, GLenum, 100>
{ using enum_class::enum_class; };

struct tess_gen_primitive_type
 : enum_class<tess_gen_primitive_type, GLenum, 101>
{ using enum_class::enum_class; };

struct texture_compare_mode
 : enum_class<texture_compare_mode, GLenum, 102>
{ using enum_class::enum_class; };

struct texture_filter
 : enum_class<texture_filter, GLenum, 103>
{ using enum_class::enum_class; };

struct texture_mag_filter
 : enum_class<texture_mag_filter, GLenum, 104>
{ using enum_class::enum_class; };

struct texture_min_filter
 : enum_class<texture_min_filter, GLenum, 105>
{ using enum_class::enum_class; };

struct texture_parameter
 : enum_class<texture_parameter, GLenum, 106>
{ using enum_class::enum_class; };

struct texture_swizzle_coord
 : enum_class<texture_swizzle_coord, GLenum, 107>
{ using enum_class::enum_class; };

struct texture_swizzle_mode
 : enum_class<texture_swizzle_mode, GLenum, 108>
{ using enum_class::enum_class; };

struct texture_target
 : enum_class<texture_target, GLenum, 109>
{ using enum_class::enum_class; };

struct texture_wrap_coord
 : enum_class<texture_wrap_coord, GLenum, 110>
{ using enum_class::enum_class; };

struct texture_wrap_mode
 : enum_class<texture_wrap_mode, GLenum, 111>
{ using enum_class::enum_class; };

struct transform_feedback_mode
 : enum_class<transform_feedback_mode, GLenum, 112>
{ using enum_class::enum_class; };

struct transform_feedback_parameter
 : enum_class<transform_feedback_parameter, GLenum, 113>
{ using enum_class::enum_class; };

struct transform_feedback_primitive_type
 : enum_class<transform_feedback_primitive_type, GLenum, 114>
{ using enum_class::enum_class; };

struct transform_feedback_target
 : enum_class<transform_feedback_target, GLenum, 115>
{ using enum_class::enum_class; };

struct true_false
 : enum_class<true_false, GLboolean, 116>
{ using enum_class::enum_class; };

struct unified_array_address_nv
 : enum_class<unified_array_address_nv, GLenum, 117>
{ using enum_class::enum_class; };

} // namespace oglplus

#endif // include guard
