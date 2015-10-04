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
 : enum_class<access_specifier, GLenum, 0, 0>
{ using enum_class<access_specifier, GLenum, 0, 0>::enum_class; };

struct blend_equation
 : enum_class<blend_equation, GLenum, 0, 1>
{ using enum_class<blend_equation, GLenum, 0, 1>::enum_class; };

struct blend_equation_advanced
 : enum_class<blend_equation_advanced, GLenum, 0, 2>
{ using enum_class<blend_equation_advanced, GLenum, 0, 2>::enum_class; };

struct blend_function
 : enum_class<blend_function, GLenum, 0, 3>
{ using enum_class<blend_function, GLenum, 0, 3>::enum_class; };

struct blit_filter
 : enum_class<blit_filter, GLenum, 0, 4>
{ using enum_class<blit_filter, GLenum, 0, 4>::enum_class; };

struct buffer_indexed_target
 : enum_class<buffer_indexed_target, GLenum, 0, 5>
{ using enum_class<buffer_indexed_target, GLenum, 0, 5>::enum_class; };

struct buffer_map_access
 : enum_class<buffer_map_access, GLbitfield, 0, 6>
{ using enum_class<buffer_map_access, GLbitfield, 0, 6>::enum_class; };

struct buffer_select_bits
 : enum_class<buffer_select_bits, GLbitfield, 0, 7>
{ using enum_class<buffer_select_bits, GLbitfield, 0, 7>::enum_class; };

struct buffer_storage_bits
 : enum_class<buffer_storage_bits, GLbitfield, 0, 8>
{ using enum_class<buffer_storage_bits, GLbitfield, 0, 8>::enum_class; };

struct buffer_target
 : enum_class<buffer_target, GLenum, 0, 9>
{ using enum_class<buffer_target, GLenum, 0, 9>::enum_class; };

struct buffer_usage
 : enum_class<buffer_usage, GLenum, 0, 10>
{ using enum_class<buffer_usage, GLenum, 0, 10>::enum_class; };

struct capability
 : enum_class<capability, GLenum, 0, 11>
{ using enum_class<capability, GLenum, 0, 11>::enum_class; };

struct clip_depth_mode
 : enum_class<clip_depth_mode, GLenum, 0, 12>
{ using enum_class<clip_depth_mode, GLenum, 0, 12>::enum_class; };

struct clip_origin
 : enum_class<clip_origin, GLenum, 0, 13>
{ using enum_class<clip_origin, GLenum, 0, 13>::enum_class; };

struct color_buffer
 : enum_class<color_buffer, GLenum, 0, 14>
{ using enum_class<color_buffer, GLenum, 0, 14>::enum_class; };

struct color_logic_operation
 : enum_class<color_logic_operation, GLenum, 0, 15>
{ using enum_class<color_logic_operation, GLenum, 0, 15>::enum_class; };

struct compare_function
 : enum_class<compare_function, GLenum, 0, 16>
{ using enum_class<compare_function, GLenum, 0, 16>::enum_class; };

struct conditional_render_mode
 : enum_class<conditional_render_mode, GLenum, 0, 17>
{ using enum_class<conditional_render_mode, GLenum, 0, 17>::enum_class; };

struct context_flag_bits
 : enum_class<context_flag_bits, GLbitfield, 0, 18>
{ using enum_class<context_flag_bits, GLbitfield, 0, 18>::enum_class; };

struct context_profile_bits
 : enum_class<context_profile_bits, GLbitfield, 0, 19>
{ using enum_class<context_profile_bits, GLbitfield, 0, 19>::enum_class; };

struct context_release_behavior
 : enum_class<context_release_behavior, GLenum, 0, 20>
{ using enum_class<context_release_behavior, GLenum, 0, 20>::enum_class; };

struct data_type
 : enum_class<data_type, GLenum, 0, 21>
{ using enum_class<data_type, GLenum, 0, 21>::enum_class; };

struct debug_output_severity
 : enum_class<debug_output_severity, GLenum, 0, 22>
{ using enum_class<debug_output_severity, GLenum, 0, 22>::enum_class; };

struct debug_output_source
 : enum_class<debug_output_source, GLenum, 0, 23>
{ using enum_class<debug_output_source, GLenum, 0, 23>::enum_class; };

struct debug_output_type
 : enum_class<debug_output_type, GLenum, 0, 24>
{ using enum_class<debug_output_type, GLenum, 0, 24>::enum_class; };

struct error_code
 : enum_class<error_code, GLenum, 0, 25>
{ using enum_class<error_code, GLenum, 0, 25>::enum_class; };

struct face
 : enum_class<face, GLenum, 0, 26>
{ using enum_class<face, GLenum, 0, 26>::enum_class; };

struct face_orientation
 : enum_class<face_orientation, GLenum, 0, 27>
{ using enum_class<face_orientation, GLenum, 0, 27>::enum_class; };

struct framebuffer_attachment
 : enum_class<framebuffer_attachment, GLenum, 0, 28>
{ using enum_class<framebuffer_attachment, GLenum, 0, 28>::enum_class; };

struct framebuffer_buffer
 : enum_class<framebuffer_buffer, GLenum, 0, 29>
{ using enum_class<framebuffer_buffer, GLenum, 0, 29>::enum_class; };

struct framebuffer_status
 : enum_class<framebuffer_status, GLenum, 0, 30>
{ using enum_class<framebuffer_status, GLenum, 0, 30>::enum_class; };

struct framebuffer_target
 : enum_class<framebuffer_target, GLenum, 0, 31>
{ using enum_class<framebuffer_target, GLenum, 0, 31>::enum_class; };

struct functionality
 : enum_class<functionality, GLenum, 0, 32>
{ using enum_class<functionality, GLenum, 0, 32>::enum_class; };

struct graphics_reset_status
 : enum_class<graphics_reset_status, GLenum, 0, 33>
{ using enum_class<graphics_reset_status, GLenum, 0, 33>::enum_class; };

struct hint_option
 : enum_class<hint_option, GLenum, 0, 34>
{ using enum_class<hint_option, GLenum, 0, 34>::enum_class; };

struct hint_target
 : enum_class<hint_target, GLenum, 0, 35>
{ using enum_class<hint_target, GLenum, 0, 35>::enum_class; };

struct image_unit_format
 : enum_class<image_unit_format, GLenum, 0, 36>
{ using enum_class<image_unit_format, GLenum, 0, 36>::enum_class; };

struct limit_query
 : enum_class<limit_query, GLenum, 0, 37>
{ using enum_class<limit_query, GLenum, 0, 37>::enum_class; };

struct memory_barrier_bits
 : enum_class<memory_barrier_bits, GLbitfield, 0, 38>
{ using enum_class<memory_barrier_bits, GLbitfield, 0, 38>::enum_class; };

struct named_string_type
 : enum_class<named_string_type, GLenum, 0, 39>
{ using enum_class<named_string_type, GLenum, 0, 39>::enum_class; };

struct object_type
 : enum_class<object_type, GLenum, 0, 40>
{ using enum_class<object_type, GLenum, 0, 40>::enum_class; };

struct patch_parameter
 : enum_class<patch_parameter, GLenum, 0, 41>
{ using enum_class<patch_parameter, GLenum, 0, 41>::enum_class; };

struct pixel_data_format
 : enum_class<pixel_data_format, GLenum, 0, 42>
{ using enum_class<pixel_data_format, GLenum, 0, 42>::enum_class; };

struct pixel_data_internal_format
 : enum_class<pixel_data_internal_format, GLenum, 0, 43>
{ using enum_class<pixel_data_internal_format, GLenum, 0, 43>::enum_class; };

struct pixel_data_type
 : enum_class<pixel_data_type, GLenum, 0, 44>
{ using enum_class<pixel_data_type, GLenum, 0, 44>::enum_class; };

struct pixel_parameter
 : enum_class<pixel_parameter, GLenum, 0, 45>
{ using enum_class<pixel_parameter, GLenum, 0, 45>::enum_class; };

struct polygon_mode
 : enum_class<polygon_mode, GLenum, 0, 46>
{ using enum_class<polygon_mode, GLenum, 0, 46>::enum_class; };

struct precision_type
 : enum_class<precision_type, GLenum, 0, 47>
{ using enum_class<precision_type, GLenum, 0, 47>::enum_class; };

struct primitive_type
 : enum_class<primitive_type, GLenum, 0, 48>
{ using enum_class<primitive_type, GLenum, 0, 48>::enum_class; };

struct program_interface
 : enum_class<program_interface, GLenum, 0, 49>
{ using enum_class<program_interface, GLenum, 0, 49>::enum_class; };

struct program_pipeline_stage
 : enum_class<program_pipeline_stage, GLbitfield, 0, 50>
{ using enum_class<program_pipeline_stage, GLbitfield, 0, 50>::enum_class; };

struct program_resource_property
 : enum_class<program_resource_property, GLenum, 0, 51>
{ using enum_class<program_resource_property, GLenum, 0, 51>::enum_class; };

struct provoke_mode
 : enum_class<provoke_mode, GLenum, 0, 52>
{ using enum_class<provoke_mode, GLenum, 0, 52>::enum_class; };

struct query_target
 : enum_class<query_target, GLenum, 0, 53>
{ using enum_class<query_target, GLenum, 0, 53>::enum_class; };

struct renderbuffer_target
 : enum_class<renderbuffer_target, GLenum, 0, 54>
{ using enum_class<renderbuffer_target, GLenum, 0, 54>::enum_class; };

struct reset_notification_strategy
 : enum_class<reset_notification_strategy, GLenum, 0, 55>
{ using enum_class<reset_notification_strategy, GLenum, 0, 55>::enum_class; };

struct shader_type
 : enum_class<shader_type, GLenum, 0, 56>
{ using enum_class<shader_type, GLenum, 0, 56>::enum_class; };

struct single_face
 : enum_class<single_face, GLenum, 0, 57>
{ using enum_class<single_face, GLenum, 0, 57>::enum_class; };

struct sl_data_type
 : enum_class<sl_data_type, GLenum, 0, 58>
{ using enum_class<sl_data_type, GLenum, 0, 58>::enum_class; };

struct stencil_operation
 : enum_class<stencil_operation, GLenum, 0, 59>
{ using enum_class<stencil_operation, GLenum, 0, 59>::enum_class; };

struct string_query
 : enum_class<string_query, GLenum, 0, 60>
{ using enum_class<string_query, GLenum, 0, 60>::enum_class; };

struct sync_condition
 : enum_class<sync_condition, GLenum, 0, 61>
{ using enum_class<sync_condition, GLenum, 0, 61>::enum_class; };

struct sync_status
 : enum_class<sync_status, GLenum, 0, 62>
{ using enum_class<sync_status, GLenum, 0, 62>::enum_class; };

struct sync_type
 : enum_class<sync_type, GLenum, 0, 63>
{ using enum_class<sync_type, GLenum, 0, 63>::enum_class; };

struct sync_wait_result
 : enum_class<sync_wait_result, GLenum, 0, 64>
{ using enum_class<sync_wait_result, GLenum, 0, 64>::enum_class; };

struct tess_gen_primitive_spacing
 : enum_class<tess_gen_primitive_spacing, GLenum, 0, 65>
{ using enum_class<tess_gen_primitive_spacing, GLenum, 0, 65>::enum_class; };

struct tess_gen_primitive_type
 : enum_class<tess_gen_primitive_type, GLenum, 0, 66>
{ using enum_class<tess_gen_primitive_type, GLenum, 0, 66>::enum_class; };

struct texture_compare_mode
 : enum_class<texture_compare_mode, GLenum, 0, 67>
{ using enum_class<texture_compare_mode, GLenum, 0, 67>::enum_class; };

struct texture_filter
 : enum_class<texture_filter, GLenum, 0, 68>
{ using enum_class<texture_filter, GLenum, 0, 68>::enum_class; };

struct texture_mag_filter
 : enum_class<texture_mag_filter, GLenum, 0, 69>
{ using enum_class<texture_mag_filter, GLenum, 0, 69>::enum_class; };

struct texture_min_filter
 : enum_class<texture_min_filter, GLenum, 0, 70>
{ using enum_class<texture_min_filter, GLenum, 0, 70>::enum_class; };

struct texture_swizzle
 : enum_class<texture_swizzle, GLenum, 0, 71>
{ using enum_class<texture_swizzle, GLenum, 0, 71>::enum_class; };

struct texture_swizzle_coord
 : enum_class<texture_swizzle_coord, GLenum, 0, 72>
{ using enum_class<texture_swizzle_coord, GLenum, 0, 72>::enum_class; };

struct texture_target
 : enum_class<texture_target, GLenum, 0, 73>
{ using enum_class<texture_target, GLenum, 0, 73>::enum_class; };

struct texture_wrap
 : enum_class<texture_wrap, GLenum, 0, 74>
{ using enum_class<texture_wrap, GLenum, 0, 74>::enum_class; };

struct texture_wrap_coord
 : enum_class<texture_wrap_coord, GLenum, 0, 75>
{ using enum_class<texture_wrap_coord, GLenum, 0, 75>::enum_class; };

struct transform_feedback_mode
 : enum_class<transform_feedback_mode, GLenum, 0, 76>
{ using enum_class<transform_feedback_mode, GLenum, 0, 76>::enum_class; };

struct transform_feedback_primitive_type
 : enum_class<transform_feedback_primitive_type, GLenum, 0, 77>
{ using enum_class<transform_feedback_primitive_type, GLenum, 0, 77>::enum_class; };

struct transform_feedback_target
 : enum_class<transform_feedback_target, GLenum, 0, 78>
{ using enum_class<transform_feedback_target, GLenum, 0, 78>::enum_class; };

} // namespace oglplus

#endif // include guard
