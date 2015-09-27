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

struct blit_filter
 : enum_class<blit_filter, GLenum>
{ using enum_class<blit_filter, GLenum>::enum_class; };

struct buffer_select_bit
 : enum_class<buffer_select_bit, GLbitfield>
{ using enum_class<buffer_select_bit, GLbitfield>::enum_class; };

struct buffer_target
 : enum_class<buffer_target, GLenum>
{ using enum_class<buffer_target, GLenum>::enum_class; };

struct buffer_usage
 : enum_class<buffer_usage, GLenum>
{ using enum_class<buffer_usage, GLenum>::enum_class; };

struct capability
 : enum_class<capability, GLenum>
{ using enum_class<capability, GLenum>::enum_class; };

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

struct data_type
 : enum_class<data_type, GLenum>
{ using enum_class<data_type, GLenum>::enum_class; };

struct error_code
 : enum_class<error_code, GLenum>
{ using enum_class<error_code, GLenum>::enum_class; };

struct face
 : enum_class<face, GLenum>
{ using enum_class<face, GLenum>::enum_class; };

struct face_orientation
 : enum_class<face_orientation, GLenum>
{ using enum_class<face_orientation, GLenum>::enum_class; };

struct functionality
 : enum_class<functionality, GLenum>
{ using enum_class<functionality, GLenum>::enum_class; };

struct hint_option
 : enum_class<hint_option, GLenum>
{ using enum_class<hint_option, GLenum>::enum_class; };

struct hint_target
 : enum_class<hint_target, GLenum>
{ using enum_class<hint_target, GLenum>::enum_class; };

struct object_type
 : enum_class<object_type, GLenum>
{ using enum_class<object_type, GLenum>::enum_class; };

struct pixel_data_format
 : enum_class<pixel_data_format, GLenum>
{ using enum_class<pixel_data_format, GLenum>::enum_class; };

struct pixel_data_internal_format
 : enum_class<pixel_data_internal_format, GLenum>
{ using enum_class<pixel_data_internal_format, GLenum>::enum_class; };

struct precision_type
 : enum_class<precision_type, GLenum>
{ using enum_class<precision_type, GLenum>::enum_class; };

struct primitive_type
 : enum_class<primitive_type, GLenum>
{ using enum_class<primitive_type, GLenum>::enum_class; };

struct shader_type
 : enum_class<shader_type, GLenum>
{ using enum_class<shader_type, GLenum>::enum_class; };

struct single_face
 : enum_class<single_face, GLenum>
{ using enum_class<single_face, GLenum>::enum_class; };

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
