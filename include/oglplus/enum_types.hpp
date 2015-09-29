//  File include/oglplus/enum_types.hpp
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
#ifndef OGLPLUS_ENUM_TYPES_HPP
#define OGLPLUS_ENUM_TYPES_HPP

#include "utils/enum_class.hpp"

namespace oglplus {

struct access_specifier
 : enum_class<access_specifier, GLenum>
{ using enum_class<access_specifier, GLenum>::enum_class; };

struct blend_equation
 : enum_class<blend_equation, GLenum>
{ using enum_class<blend_equation, GLenum>::enum_class; };

struct blend_equation_advanced
 : enum_class<blend_equation_advanced, GLenum>
{ using enum_class<blend_equation_advanced, GLenum>::enum_class; };

struct blend_function
 : enum_class<blend_function, GLenum>
{ using enum_class<blend_function, GLenum>::enum_class; };

struct blit_filter
 : enum_class<blit_filter, GLenum>
{ using enum_class<blit_filter, GLenum>::enum_class; };

struct buffer_indexed_target
 : enum_class<buffer_indexed_target, GLenum>
{ using enum_class<buffer_indexed_target, GLenum>::enum_class; };

struct buffer_map_access
 : enum_class<buffer_map_access, GLbitfield>
{ using enum_class<buffer_map_access, GLbitfield>::enum_class; };

struct buffer_select_bits
 : enum_class<buffer_select_bits, GLbitfield>
{ using enum_class<buffer_select_bits, GLbitfield>::enum_class; };

struct buffer_storage_bits
 : enum_class<buffer_storage_bits, GLbitfield>
{ using enum_class<buffer_storage_bits, GLbitfield>::enum_class; };

struct buffer_target
 : enum_class<buffer_target, GLenum>
{ using enum_class<buffer_target, GLenum>::enum_class; };

struct buffer_usage
 : enum_class<buffer_usage, GLenum>
{ using enum_class<buffer_usage, GLenum>::enum_class; };

struct capability
 : enum_class<capability, GLenum>
{ using enum_class<capability, GLenum>::enum_class; };

struct clip_depth_mode
 : enum_class<clip_depth_mode, GLenum>
{ using enum_class<clip_depth_mode, GLenum>::enum_class; };

struct clip_origin
 : enum_class<clip_origin, GLenum>
{ using enum_class<clip_origin, GLenum>::enum_class; };

struct color_buffer
 : enum_class<color_buffer, GLenum>
{ using enum_class<color_buffer, GLenum>::enum_class; };

struct color_logic_operation
 : enum_class<color_logic_operation, GLenum>
{ using enum_class<color_logic_operation, GLenum>::enum_class; };

struct compare_function
 : enum_class<compare_function, GLenum>
{ using enum_class<compare_function, GLenum>::enum_class; };

struct conditional_render_mode
 : enum_class<conditional_render_mode, GLenum>
{ using enum_class<conditional_render_mode, GLenum>::enum_class; };

struct context_flag_bits
 : enum_class<context_flag_bits, GLbitfield>
{ using enum_class<context_flag_bits, GLbitfield>::enum_class; };

struct context_profile_bits
 : enum_class<context_profile_bits, GLbitfield>
{ using enum_class<context_profile_bits, GLbitfield>::enum_class; };

struct context_release_behavior
 : enum_class<context_release_behavior, GLenum>
{ using enum_class<context_release_behavior, GLenum>::enum_class; };

struct data_type
 : enum_class<data_type, GLenum>
{ using enum_class<data_type, GLenum>::enum_class; };

struct debug_output_severity
 : enum_class<debug_output_severity, GLenum>
{ using enum_class<debug_output_severity, GLenum>::enum_class; };

struct debug_output_source
 : enum_class<debug_output_source, GLenum>
{ using enum_class<debug_output_source, GLenum>::enum_class; };

struct debug_output_type
 : enum_class<debug_output_type, GLenum>
{ using enum_class<debug_output_type, GLenum>::enum_class; };

struct error_code
 : enum_class<error_code, GLenum>
{ using enum_class<error_code, GLenum>::enum_class; };

struct face
 : enum_class<face, GLenum>
{ using enum_class<face, GLenum>::enum_class; };

struct face_orientation
 : enum_class<face_orientation, GLenum>
{ using enum_class<face_orientation, GLenum>::enum_class; };

struct framebuffer_attachment
 : enum_class<framebuffer_attachment, GLenum>
{ using enum_class<framebuffer_attachment, GLenum>::enum_class; };

struct framebuffer_buffer
 : enum_class<framebuffer_buffer, GLenum>
{ using enum_class<framebuffer_buffer, GLenum>::enum_class; };

struct framebuffer_status
 : enum_class<framebuffer_status, GLenum>
{ using enum_class<framebuffer_status, GLenum>::enum_class; };

struct framebuffer_target
 : enum_class<framebuffer_target, GLenum>
{ using enum_class<framebuffer_target, GLenum>::enum_class; };

struct functionality
 : enum_class<functionality, GLenum>
{ using enum_class<functionality, GLenum>::enum_class; };

struct graphics_reset_status
 : enum_class<graphics_reset_status, GLenum>
{ using enum_class<graphics_reset_status, GLenum>::enum_class; };

struct hint_option
 : enum_class<hint_option, GLenum>
{ using enum_class<hint_option, GLenum>::enum_class; };

struct hint_target
 : enum_class<hint_target, GLenum>
{ using enum_class<hint_target, GLenum>::enum_class; };

struct image_unit_format
 : enum_class<image_unit_format, GLenum>
{ using enum_class<image_unit_format, GLenum>::enum_class; };

struct limit_query
 : enum_class<limit_query, GLenum>
{ using enum_class<limit_query, GLenum>::enum_class; };

struct memory_barrier_bits
 : enum_class<memory_barrier_bits, GLbitfield>
{ using enum_class<memory_barrier_bits, GLbitfield>::enum_class; };

struct named_string_type
 : enum_class<named_string_type, GLenum>
{ using enum_class<named_string_type, GLenum>::enum_class; };

struct object_type
 : enum_class<object_type, GLenum>
{ using enum_class<object_type, GLenum>::enum_class; };

struct patch_parameter
 : enum_class<patch_parameter, GLenum>
{ using enum_class<patch_parameter, GLenum>::enum_class; };

struct pixel_data_format
 : enum_class<pixel_data_format, GLenum>
{ using enum_class<pixel_data_format, GLenum>::enum_class; };

struct pixel_data_internal_format
 : enum_class<pixel_data_internal_format, GLenum>
{ using enum_class<pixel_data_internal_format, GLenum>::enum_class; };

struct pixel_data_type
 : enum_class<pixel_data_type, GLenum>
{ using enum_class<pixel_data_type, GLenum>::enum_class; };

struct pixel_parameter
 : enum_class<pixel_parameter, GLenum>
{ using enum_class<pixel_parameter, GLenum>::enum_class; };

struct polygon_mode
 : enum_class<polygon_mode, GLenum>
{ using enum_class<polygon_mode, GLenum>::enum_class; };

struct precision_type
 : enum_class<precision_type, GLenum>
{ using enum_class<precision_type, GLenum>::enum_class; };

struct primitive_type
 : enum_class<primitive_type, GLenum>
{ using enum_class<primitive_type, GLenum>::enum_class; };

struct program_interface
 : enum_class<program_interface, GLenum>
{ using enum_class<program_interface, GLenum>::enum_class; };

struct program_pipeline_stage
 : enum_class<program_pipeline_stage, GLbitfield>
{ using enum_class<program_pipeline_stage, GLbitfield>::enum_class; };

struct program_resource_property
 : enum_class<program_resource_property, GLenum>
{ using enum_class<program_resource_property, GLenum>::enum_class; };

struct provoke_mode
 : enum_class<provoke_mode, GLenum>
{ using enum_class<provoke_mode, GLenum>::enum_class; };

struct query_target
 : enum_class<query_target, GLenum>
{ using enum_class<query_target, GLenum>::enum_class; };

struct renderbuffer_target
 : enum_class<renderbuffer_target, GLenum>
{ using enum_class<renderbuffer_target, GLenum>::enum_class; };

struct reset_notification_strategy
 : enum_class<reset_notification_strategy, GLenum>
{ using enum_class<reset_notification_strategy, GLenum>::enum_class; };

struct shader_type
 : enum_class<shader_type, GLenum>
{ using enum_class<shader_type, GLenum>::enum_class; };

struct single_face
 : enum_class<single_face, GLenum>
{ using enum_class<single_face, GLenum>::enum_class; };

struct sl_data_type
 : enum_class<sl_data_type, GLenum>
{ using enum_class<sl_data_type, GLenum>::enum_class; };

struct stencil_operation
 : enum_class<stencil_operation, GLenum>
{ using enum_class<stencil_operation, GLenum>::enum_class; };

struct string_query
 : enum_class<string_query, GLenum>
{ using enum_class<string_query, GLenum>::enum_class; };

struct sync_condition
 : enum_class<sync_condition, GLenum>
{ using enum_class<sync_condition, GLenum>::enum_class; };

struct sync_status
 : enum_class<sync_status, GLenum>
{ using enum_class<sync_status, GLenum>::enum_class; };

struct sync_type
 : enum_class<sync_type, GLenum>
{ using enum_class<sync_type, GLenum>::enum_class; };

struct sync_wait_result
 : enum_class<sync_wait_result, GLenum>
{ using enum_class<sync_wait_result, GLenum>::enum_class; };

struct tess_gen_primitive_spacing
 : enum_class<tess_gen_primitive_spacing, GLenum>
{ using enum_class<tess_gen_primitive_spacing, GLenum>::enum_class; };

struct tess_gen_primitive_type
 : enum_class<tess_gen_primitive_type, GLenum>
{ using enum_class<tess_gen_primitive_type, GLenum>::enum_class; };

struct texture_compare_mode
 : enum_class<texture_compare_mode, GLenum>
{ using enum_class<texture_compare_mode, GLenum>::enum_class; };

struct texture_filter
 : enum_class<texture_filter, GLenum>
{ using enum_class<texture_filter, GLenum>::enum_class; };

struct texture_mag_filter
 : enum_class<texture_mag_filter, GLenum>
{ using enum_class<texture_mag_filter, GLenum>::enum_class; };

struct texture_min_filter
 : enum_class<texture_min_filter, GLenum>
{ using enum_class<texture_min_filter, GLenum>::enum_class; };

struct texture_swizzle
 : enum_class<texture_swizzle, GLenum>
{ using enum_class<texture_swizzle, GLenum>::enum_class; };

struct texture_swizzle_coord
 : enum_class<texture_swizzle_coord, GLenum>
{ using enum_class<texture_swizzle_coord, GLenum>::enum_class; };

struct texture_target
 : enum_class<texture_target, GLenum>
{ using enum_class<texture_target, GLenum>::enum_class; };

struct texture_wrap
 : enum_class<texture_wrap, GLenum>
{ using enum_class<texture_wrap, GLenum>::enum_class; };

struct texture_wrap_coord
 : enum_class<texture_wrap_coord, GLenum>
{ using enum_class<texture_wrap_coord, GLenum>::enum_class; };

struct transform_feedback_mode
 : enum_class<transform_feedback_mode, GLenum>
{ using enum_class<transform_feedback_mode, GLenum>::enum_class; };

struct transform_feedback_primitive_type
 : enum_class<transform_feedback_primitive_type, GLenum>
{ using enum_class<transform_feedback_primitive_type, GLenum>::enum_class; };

struct transform_feedback_target
 : enum_class<transform_feedback_target, GLenum>
{ using enum_class<transform_feedback_target, GLenum>::enum_class; };

} // namespace oglplus

#endif // include guard
