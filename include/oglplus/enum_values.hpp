//  File include/oglplus/enum_values.hpp
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
#ifndef OGLPLUS_ENUM_VALUES_HPP
#define OGLPLUS_ENUM_VALUES_HPP

#include "enum_types.hpp"

namespace oglplus {
struct enum_values {

#ifdef GL_ALPHA
static constexpr const enum_value<
	GLenum,
	GL_ALPHA,
	mp_list<texture_swizzle>
> alpha = {};
#endif

#ifdef GL_ALREADY_SIGNALED
static constexpr const enum_value<
	GLenum,
	GL_ALREADY_SIGNALED,
	mp_list<sync_wait_result>
> already_signaled = {};
#endif

#ifdef GL_ALWAYS
static constexpr const enum_value<
	GLenum,
	GL_ALWAYS,
	mp_list<compare_function>
> always = {};
#endif

#ifdef GL_AND
static constexpr const enum_value<
	GLenum,
	GL_AND,
	mp_list<color_logic_operation>
> and_ = {};
#endif

#ifdef GL_AND_INVERTED
static constexpr const enum_value<
	GLenum,
	GL_AND_INVERTED,
	mp_list<color_logic_operation>
> and_inverted = {};
#endif

#ifdef GL_AND_REVERSE
static constexpr const enum_value<
	GLenum,
	GL_AND_REVERSE,
	mp_list<color_logic_operation>
> and_reverse = {};
#endif

#ifdef GL_ARRAY_BUFFER
static constexpr const enum_value<
	GLenum,
	GL_ARRAY_BUFFER,
	mp_list<buffer_target>
> array_buffer = {};
#endif

#ifdef GL_ATOMIC_COUNTER_BUFFER
static constexpr const enum_value<
	GLenum,
	GL_ATOMIC_COUNTER_BUFFER,
	mp_list<buffer_target>
> atomic_counter_buffer = {};
#endif

#ifdef GL_BACK
static constexpr const enum_value<
	GLenum,
	GL_BACK,
	mp_list<color_buffer,single_face,face>
> back = {};
#endif

#ifdef GL_BACK_LEFT
static constexpr const enum_value<
	GLenum,
	GL_BACK_LEFT,
	mp_list<color_buffer>
> back_left = {};
#endif

#ifdef GL_BACK_RIGHT
static constexpr const enum_value<
	GLenum,
	GL_BACK_RIGHT,
	mp_list<color_buffer>
> back_right = {};
#endif

#ifdef GL_BGR
static constexpr const enum_value<
	GLenum,
	GL_BGR,
	mp_list<pixel_data_format>
> bgr = {};
#endif

#ifdef GL_BGR_INTEGER
static constexpr const enum_value<
	GLenum,
	GL_BGR_INTEGER,
	mp_list<pixel_data_format>
> bgr_integer = {};
#endif

#ifdef GL_BGRA
static constexpr const enum_value<
	GLenum,
	GL_BGRA,
	mp_list<pixel_data_format>
> bgra = {};
#endif

#ifdef GL_BGRA_INTEGER
static constexpr const enum_value<
	GLenum,
	GL_BGRA_INTEGER,
	mp_list<pixel_data_format>
> bgra_integer = {};
#endif

#ifdef GL_BLEND
static constexpr const enum_value<
	GLenum,
	GL_BLEND,
	mp_list<capability>
> blend = {};
#endif

#ifdef GL_BLEND_ADVANCED_COHERENT_KHR
static constexpr const enum_value<
	GLenum,
	GL_BLEND_ADVANCED_COHERENT_KHR,
	mp_list<capability>
> blend_advanced_coherent = {};
#endif

#ifdef GL_BLUE
static constexpr const enum_value<
	GLenum,
	GL_BLUE,
	mp_list<texture_swizzle,pixel_data_format>
> blue = {};
#endif

#ifdef GL_BLUE_INTEGER
static constexpr const enum_value<
	GLenum,
	GL_BLUE_INTEGER,
	mp_list<pixel_data_format>
> blue_integer = {};
#endif

#ifdef GL_BUFFER
static constexpr const enum_value<
	GLenum,
	GL_BUFFER,
	mp_list<object_type>
> buffer = {};
#endif

#ifdef GL_BYTE
static constexpr const enum_value<
	GLenum,
	GL_BYTE,
	mp_list<data_type>
> byte_ = {};
#endif

#ifdef GL_CCW
static constexpr const enum_value<
	GLenum,
	GL_CCW,
	mp_list<face_orientation>
> ccw = {};
#endif

#ifdef GL_CLAMP_TO_BORDER
static constexpr const enum_value<
	GLenum,
	GL_CLAMP_TO_BORDER,
	mp_list<texture_wrap>
> clamp_to_border = {};
#endif

#ifdef GL_CLAMP_TO_EDGE
static constexpr const enum_value<
	GLenum,
	GL_CLAMP_TO_EDGE,
	mp_list<texture_wrap>
> clamp_to_edge = {};
#endif

#ifdef GL_CLEAR
static constexpr const enum_value<
	GLenum,
	GL_CLEAR,
	mp_list<color_logic_operation>
> clear = {};
#endif

#ifdef GL_CLIP_DISTANCE0
static constexpr const enum_value<
	GLenum,
	GL_CLIP_DISTANCE0,
	mp_list<functionality>
> clip_distance = {};
#endif

#ifdef GL_COLOR_BUFFER_BIT
static constexpr const enum_value<
	GLbitfield,
	GL_COLOR_BUFFER_BIT,
	mp_list<buffer_select_bit>
> color_buffer_bit = {};
#endif

#ifdef GL_COLOR_LOGIC_OP
static constexpr const enum_value<
	GLenum,
	GL_COLOR_LOGIC_OP,
	mp_list<capability>
> color_logic_op = {};
#endif

#ifdef GL_COMPRESSED_R11_EAC
static constexpr const enum_value<
	GLenum,
	GL_COMPRESSED_R11_EAC,
	mp_list<pixel_data_internal_format>
> compressed_r11_eac = {};
#endif

#ifdef GL_COMPRESSED_RED
static constexpr const enum_value<
	GLenum,
	GL_COMPRESSED_RED,
	mp_list<pixel_data_internal_format>
> compressed_red = {};
#endif

#ifdef GL_COMPRESSED_RED_RGTC1
static constexpr const enum_value<
	GLenum,
	GL_COMPRESSED_RED_RGTC1,
	mp_list<pixel_data_internal_format>
> compressed_red_rgtc1 = {};
#endif

#ifdef GL_COMPRESSED_RG
static constexpr const enum_value<
	GLenum,
	GL_COMPRESSED_RG,
	mp_list<pixel_data_internal_format>
> compressed_rg = {};
#endif

#ifdef GL_COMPRESSED_RG11_EAC
static constexpr const enum_value<
	GLenum,
	GL_COMPRESSED_RG11_EAC,
	mp_list<pixel_data_internal_format>
> compressed_rg11_eac = {};
#endif

#ifdef GL_COMPRESSED_RG_RGTC2
static constexpr const enum_value<
	GLenum,
	GL_COMPRESSED_RG_RGTC2,
	mp_list<pixel_data_internal_format>
> compressed_rg_rgtc2 = {};
#endif

#ifdef GL_COMPRESSED_RGB
static constexpr const enum_value<
	GLenum,
	GL_COMPRESSED_RGB,
	mp_list<pixel_data_internal_format>
> compressed_rgb = {};
#endif

#ifdef GL_COMPRESSED_RGB8_ETC2
static constexpr const enum_value<
	GLenum,
	GL_COMPRESSED_RGB8_ETC2,
	mp_list<pixel_data_internal_format>
> compressed_rgb8_etc2 = {};
#endif

#ifdef GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2
static constexpr const enum_value<
	GLenum,
	GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2,
	mp_list<pixel_data_internal_format>
> compressed_rgb8_punchthrough_alpha1_etc2 = {};
#endif

#ifdef GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT
static constexpr const enum_value<
	GLenum,
	GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT,
	mp_list<pixel_data_internal_format>
> compressed_rgb_bptc_signed_float = {};
#endif

#ifdef GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT
static constexpr const enum_value<
	GLenum,
	GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT,
	mp_list<pixel_data_internal_format>
> compressed_rgb_bptc_unsigned_float = {};
#endif

#ifdef GL_COMPRESSED_RGBA
static constexpr const enum_value<
	GLenum,
	GL_COMPRESSED_RGBA,
	mp_list<pixel_data_internal_format>
> compressed_rgba = {};
#endif

#ifdef GL_COMPRESSED_RGBA8_ETC2_EAC
static constexpr const enum_value<
	GLenum,
	GL_COMPRESSED_RGBA8_ETC2_EAC,
	mp_list<pixel_data_internal_format>
> compressed_rgba8_etc2_eac = {};
#endif

#ifdef GL_COMPRESSED_RGBA_BPTC_UNORM
static constexpr const enum_value<
	GLenum,
	GL_COMPRESSED_RGBA_BPTC_UNORM,
	mp_list<pixel_data_internal_format>
> compressed_rgba_bptc_unorm = {};
#endif

#ifdef GL_COMPRESSED_SIGNED_R11_EAC
static constexpr const enum_value<
	GLenum,
	GL_COMPRESSED_SIGNED_R11_EAC,
	mp_list<pixel_data_internal_format>
> compressed_signed_r11_eac = {};
#endif

#ifdef GL_COMPRESSED_SIGNED_RED_RGTC1
static constexpr const enum_value<
	GLenum,
	GL_COMPRESSED_SIGNED_RED_RGTC1,
	mp_list<pixel_data_internal_format>
> compressed_signed_red_rgtc1 = {};
#endif

#ifdef GL_COMPRESSED_SIGNED_RG11_EAC
static constexpr const enum_value<
	GLenum,
	GL_COMPRESSED_SIGNED_RG11_EAC,
	mp_list<pixel_data_internal_format>
> compressed_signed_rg11_eac = {};
#endif

#ifdef GL_COMPRESSED_SIGNED_RG_RGTC2
static constexpr const enum_value<
	GLenum,
	GL_COMPRESSED_SIGNED_RG_RGTC2,
	mp_list<pixel_data_internal_format>
> compressed_signed_rg_rgtc2 = {};
#endif

#ifdef GL_COMPRESSED_SRGB
static constexpr const enum_value<
	GLenum,
	GL_COMPRESSED_SRGB,
	mp_list<pixel_data_internal_format>
> compressed_srgb = {};
#endif

#ifdef GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC
static constexpr const enum_value<
	GLenum,
	GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC,
	mp_list<pixel_data_internal_format>
> compressed_srgb8_alpha8_etc2_eac = {};
#endif

#ifdef GL_COMPRESSED_SRGB8_ETC2
static constexpr const enum_value<
	GLenum,
	GL_COMPRESSED_SRGB8_ETC2,
	mp_list<pixel_data_internal_format>
> compressed_srgb8_etc2 = {};
#endif

#ifdef GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2
static constexpr const enum_value<
	GLenum,
	GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2,
	mp_list<pixel_data_internal_format>
> compressed_srgb8_punchthrough_alpha1_etc2 = {};
#endif

#ifdef GL_COMPRESSED_SRGB_ALPHA
static constexpr const enum_value<
	GLenum,
	GL_COMPRESSED_SRGB_ALPHA,
	mp_list<pixel_data_internal_format>
> compressed_srgb_alpha = {};
#endif

#ifdef GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM
static constexpr const enum_value<
	GLenum,
	GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM,
	mp_list<pixel_data_internal_format>
> compressed_srgb_alpha_bptc_unorm = {};
#endif

#ifdef GL_COMPUTE_SHADER
static constexpr const enum_value<
	GLenum,
	GL_COMPUTE_SHADER,
	mp_list<shader_type>
> compute_shader = {};
#endif

#ifdef GL_CONDITION_SATISFIED
static constexpr const enum_value<
	GLenum,
	GL_CONDITION_SATISFIED,
	mp_list<sync_wait_result>
> condition_satisfied = {};
#endif

#ifdef GL_CONTEXT_LOST
static constexpr const enum_value<
	GLenum,
	GL_CONTEXT_LOST,
	mp_list<error_code>
> context_lost = {};
#endif

#ifdef GL_COPY
static constexpr const enum_value<
	GLenum,
	GL_COPY,
	mp_list<color_logic_operation>
> copy = {};
#endif

#ifdef GL_COPY_INVERTED
static constexpr const enum_value<
	GLenum,
	GL_COPY_INVERTED,
	mp_list<color_logic_operation>
> copy_inverted = {};
#endif

#ifdef GL_COPY_READ_BUFFER
static constexpr const enum_value<
	GLenum,
	GL_COPY_READ_BUFFER,
	mp_list<buffer_target>
> copy_read_buffer = {};
#endif

#ifdef GL_COPY_WRITE_BUFFER
static constexpr const enum_value<
	GLenum,
	GL_COPY_WRITE_BUFFER,
	mp_list<buffer_target>
> copy_write_buffer = {};
#endif

#ifdef GL_CULL_FACE
static constexpr const enum_value<
	GLenum,
	GL_CULL_FACE,
	mp_list<capability>
> cull_face = {};
#endif

#ifdef GL_CW
static constexpr const enum_value<
	GLenum,
	GL_CW,
	mp_list<face_orientation>
> cw = {};
#endif

#ifdef GL_DEBUG_OUTPUT_SYNCHRONOUS
static constexpr const enum_value<
	GLenum,
	GL_DEBUG_OUTPUT_SYNCHRONOUS,
	mp_list<capability>
> debug_output_synchronous = {};
#endif

#ifdef GL_DECR
static constexpr const enum_value<
	GLenum,
	GL_DECR,
	mp_list<stencil_operation>
> decr = {};
#endif

#ifdef GL_DECR_WRAP
static constexpr const enum_value<
	GLenum,
	GL_DECR_WRAP,
	mp_list<stencil_operation>
> decr_wrap = {};
#endif

#ifdef GL_DEPTH24_STENCIL8
static constexpr const enum_value<
	GLenum,
	GL_DEPTH24_STENCIL8,
	mp_list<pixel_data_internal_format>
> depth24_stencil8 = {};
#endif

#ifdef GL_DEPTH32F_STENCIL8
static constexpr const enum_value<
	GLenum,
	GL_DEPTH32F_STENCIL8,
	mp_list<pixel_data_internal_format>
> depth32f_stencil8 = {};
#endif

#ifdef GL_DEPTH_BUFFER_BIT
static constexpr const enum_value<
	GLbitfield,
	GL_DEPTH_BUFFER_BIT,
	mp_list<buffer_select_bit>
> depth_buffer_bit = {};
#endif

#ifdef GL_DEPTH_COMPONENT
static constexpr const enum_value<
	GLenum,
	GL_DEPTH_COMPONENT,
	mp_list<pixel_data_format,pixel_data_internal_format>
> depth_component = {};
#endif

#ifdef GL_DEPTH_COMPONENT16
static constexpr const enum_value<
	GLenum,
	GL_DEPTH_COMPONENT16,
	mp_list<pixel_data_internal_format>
> depth_component16 = {};
#endif

#ifdef GL_DEPTH_COMPONENT24
static constexpr const enum_value<
	GLenum,
	GL_DEPTH_COMPONENT24,
	mp_list<pixel_data_internal_format>
> depth_component24 = {};
#endif

#ifdef GL_DEPTH_COMPONENT32
static constexpr const enum_value<
	GLenum,
	GL_DEPTH_COMPONENT32,
	mp_list<pixel_data_internal_format>
> depth_component32 = {};
#endif

#ifdef GL_DEPTH_COMPONENT32F
static constexpr const enum_value<
	GLenum,
	GL_DEPTH_COMPONENT32F,
	mp_list<pixel_data_internal_format>
> depth_component32f = {};
#endif

#ifdef GL_DEPTH_STENCIL
static constexpr const enum_value<
	GLenum,
	GL_DEPTH_STENCIL,
	mp_list<pixel_data_format,pixel_data_internal_format>
> depth_stencil = {};
#endif

#ifdef GL_DEPTH_TEST
static constexpr const enum_value<
	GLenum,
	GL_DEPTH_TEST,
	mp_list<capability>
> depth_test = {};
#endif

#ifdef GL_DISPATCH_INDIRECT_BUFFER
static constexpr const enum_value<
	GLenum,
	GL_DISPATCH_INDIRECT_BUFFER,
	mp_list<buffer_target>
> dispatch_indirect_buffer = {};
#endif

#ifdef GL_DITHER
static constexpr const enum_value<
	GLenum,
	GL_DITHER,
	mp_list<capability>
> dither = {};
#endif

#ifdef GL_DONT_CARE
static constexpr const enum_value<
	GLenum,
	GL_DONT_CARE,
	mp_list<hint_option>
> dont_care = {};
#endif

#ifdef GL_DOUBLE
static constexpr const enum_value<
	GLenum,
	GL_DOUBLE,
	mp_list<data_type>
> double_ = {};
#endif

#ifdef GL_DRAW_INDIRECT_BUFFER
static constexpr const enum_value<
	GLenum,
	GL_DRAW_INDIRECT_BUFFER,
	mp_list<buffer_target>
> draw_indirect_buffer = {};
#endif

#ifdef GL_DYNAMIC_COPY
static constexpr const enum_value<
	GLenum,
	GL_DYNAMIC_COPY,
	mp_list<buffer_usage>
> dynamic_copy = {};
#endif

#ifdef GL_DYNAMIC_DRAW
static constexpr const enum_value<
	GLenum,
	GL_DYNAMIC_DRAW,
	mp_list<buffer_usage>
> dynamic_draw = {};
#endif

#ifdef GL_DYNAMIC_READ
static constexpr const enum_value<
	GLenum,
	GL_DYNAMIC_READ,
	mp_list<buffer_usage>
> dynamic_read = {};
#endif

#ifdef GL_ELEMENT_ARRAY_BUFFER
static constexpr const enum_value<
	GLenum,
	GL_ELEMENT_ARRAY_BUFFER,
	mp_list<buffer_target>
> element_array_buffer = {};
#endif

#ifdef GL_EQUAL
static constexpr const enum_value<
	GLenum,
	GL_EQUAL,
	mp_list<compare_function>
> equal = {};
#endif

#ifdef GL_EQUIV
static constexpr const enum_value<
	GLenum,
	GL_EQUIV,
	mp_list<color_logic_operation>
> equiv = {};
#endif

#ifdef GL_EXTERNAL_VIRTUAL_MEMORY_BUFFER_AMD
static constexpr const enum_value<
	GLenum,
	GL_EXTERNAL_VIRTUAL_MEMORY_BUFFER_AMD,
	mp_list<buffer_target>
> external_virtual_memory_buffer = {};
#endif

#ifdef GL_FASTEST
static constexpr const enum_value<
	GLenum,
	GL_FASTEST,
	mp_list<hint_option>
> fastest = {};
#endif

#ifdef GL_FIXED
static constexpr const enum_value<
	GLenum,
	GL_FIXED,
	mp_list<data_type>
> fixed = {};
#endif

#ifdef GL_FLOAT
static constexpr const enum_value<
	GLenum,
	GL_FLOAT,
	mp_list<data_type>
> float_ = {};
#endif

#ifdef GL_FRAGMENT_COVERAGE_TO_COLOR_NV
static constexpr const enum_value<
	GLenum,
	GL_FRAGMENT_COVERAGE_TO_COLOR_NV,
	mp_list<capability>
> fragment_coverage_to_color = {};
#endif

#ifdef GL_FRAGMENT_SHADER
static constexpr const enum_value<
	GLenum,
	GL_FRAGMENT_SHADER,
	mp_list<shader_type>
> fragment_shader = {};
#endif

#ifdef GL_FRAGMENT_SHADER_DERIVATIVE_HINT
static constexpr const enum_value<
	GLenum,
	GL_FRAGMENT_SHADER_DERIVATIVE_HINT,
	mp_list<hint_target>
> fragment_shader_derivative_hint = {};
#endif

#ifdef GL_FRAMEBUFFER
static constexpr const enum_value<
	GLenum,
	GL_FRAMEBUFFER,
	mp_list<object_type>
> framebuffer = {};
#endif

#ifdef GL_FRAMEBUFFER_SRGB
static constexpr const enum_value<
	GLenum,
	GL_FRAMEBUFFER_SRGB,
	mp_list<capability>
> framebuffer_srgb = {};
#endif

#ifdef GL_FRONT
static constexpr const enum_value<
	GLenum,
	GL_FRONT,
	mp_list<color_buffer,single_face,face>
> front = {};
#endif

#ifdef GL_FRONT_AND_BACK
static constexpr const enum_value<
	GLenum,
	GL_FRONT_AND_BACK,
	mp_list<color_buffer,face>
> front_and_back = {};
#endif

#ifdef GL_FRONT_LEFT
static constexpr const enum_value<
	GLenum,
	GL_FRONT_LEFT,
	mp_list<color_buffer>
> front_left = {};
#endif

#ifdef GL_FRONT_RIGHT
static constexpr const enum_value<
	GLenum,
	GL_FRONT_RIGHT,
	mp_list<color_buffer>
> front_right = {};
#endif

#ifdef GL_GEOMETRY_SHADER
static constexpr const enum_value<
	GLenum,
	GL_GEOMETRY_SHADER,
	mp_list<shader_type>
> geometry_shader = {};
#endif

#ifdef GL_GEQUAL
static constexpr const enum_value<
	GLenum,
	GL_GEQUAL,
	mp_list<compare_function>
> gequal = {};
#endif

#ifdef GL_GREATER
static constexpr const enum_value<
	GLenum,
	GL_GREATER,
	mp_list<compare_function>
> greater = {};
#endif

#ifdef GL_GREEN
static constexpr const enum_value<
	GLenum,
	GL_GREEN,
	mp_list<texture_swizzle,pixel_data_format>
> green = {};
#endif

#ifdef GL_GREEN_INTEGER
static constexpr const enum_value<
	GLenum,
	GL_GREEN_INTEGER,
	mp_list<pixel_data_format>
> green_integer = {};
#endif

#ifdef GL_HALF_FLOAT
static constexpr const enum_value<
	GLenum,
	GL_HALF_FLOAT,
	mp_list<data_type>
> half_float = {};
#endif

#ifdef GL_HIGH_FLOAT
static constexpr const enum_value<
	GLenum,
	GL_HIGH_FLOAT,
	mp_list<precision_type>
> high_float = {};
#endif

#ifdef GL_HIGH_INT
static constexpr const enum_value<
	GLenum,
	GL_HIGH_INT,
	mp_list<precision_type>
> high_int = {};
#endif

#ifdef GL_INCR
static constexpr const enum_value<
	GLenum,
	GL_INCR,
	mp_list<stencil_operation>
> incr = {};
#endif

#ifdef GL_INCR_WRAP
static constexpr const enum_value<
	GLenum,
	GL_INCR_WRAP,
	mp_list<stencil_operation>
> incr_wrap = {};
#endif

#ifdef GL_INT
static constexpr const enum_value<
	GLenum,
	GL_INT,
	mp_list<data_type>
> int_ = {};
#endif

#ifdef GL_INTERLEAVED_ATTRIBS
static constexpr const enum_value<
	GLenum,
	GL_INTERLEAVED_ATTRIBS,
	mp_list<transform_feedback_mode>
> interleaved_attribs = {};
#endif

#ifdef GL_INVALID_ENUM
static constexpr const enum_value<
	GLenum,
	GL_INVALID_ENUM,
	mp_list<error_code>
> invalid_enum = {};
#endif

#ifdef GL_INVALID_FRAMEBUFFER_OPERATION
static constexpr const enum_value<
	GLenum,
	GL_INVALID_FRAMEBUFFER_OPERATION,
	mp_list<error_code>
> invalid_framebuffer_operation = {};
#endif

#ifdef GL_INVALID_OPERATION
static constexpr const enum_value<
	GLenum,
	GL_INVALID_OPERATION,
	mp_list<error_code>
> invalid_operation = {};
#endif

#ifdef GL_INVALID_VALUE
static constexpr const enum_value<
	GLenum,
	GL_INVALID_VALUE,
	mp_list<error_code>
> invalid_value = {};
#endif

#ifdef GL_INVERT
static constexpr const enum_value<
	GLenum,
	GL_INVERT,
	mp_list<color_logic_operation,stencil_operation>
> invert = {};
#endif

#ifdef GL_KEEP
static constexpr const enum_value<
	GLenum,
	GL_KEEP,
	mp_list<stencil_operation>
> keep = {};
#endif

#ifdef GL_LEFT
static constexpr const enum_value<
	GLenum,
	GL_LEFT,
	mp_list<color_buffer>
> left = {};
#endif

#ifdef GL_LEQUAL
static constexpr const enum_value<
	GLenum,
	GL_LEQUAL,
	mp_list<compare_function>
> lequal = {};
#endif

#ifdef GL_LESS
static constexpr const enum_value<
	GLenum,
	GL_LESS,
	mp_list<compare_function>
> less = {};
#endif

#ifdef GL_LINE_LOOP
static constexpr const enum_value<
	GLenum,
	GL_LINE_LOOP,
	mp_list<primitive_type>
> line_loop = {};
#endif

#ifdef GL_LINE_SMOOTH
static constexpr const enum_value<
	GLenum,
	GL_LINE_SMOOTH,
	mp_list<capability>
> line_smooth = {};
#endif

#ifdef GL_LINE_SMOOTH_HINT
static constexpr const enum_value<
	GLenum,
	GL_LINE_SMOOTH_HINT,
	mp_list<hint_target>
> line_smooth_hint = {};
#endif

#ifdef GL_LINE_STRIP
static constexpr const enum_value<
	GLenum,
	GL_LINE_STRIP,
	mp_list<primitive_type>
> line_strip = {};
#endif

#ifdef GL_LINE_STRIP_ADJACENCY
static constexpr const enum_value<
	GLenum,
	GL_LINE_STRIP_ADJACENCY,
	mp_list<primitive_type>
> line_strip_adjacency = {};
#endif

#ifdef GL_LINEAR
static constexpr const enum_value<
	GLenum,
	GL_LINEAR,
	mp_list<texture_mag_filter,blit_filter,texture_filter,texture_min_filter>
> linear = {};
#endif

#ifdef GL_LINEAR_MIPMAP_LINEAR
static constexpr const enum_value<
	GLenum,
	GL_LINEAR_MIPMAP_LINEAR,
	mp_list<texture_min_filter>
> linear_mipmap_linear = {};
#endif

#ifdef GL_LINEAR_MIPMAP_NEAREST
static constexpr const enum_value<
	GLenum,
	GL_LINEAR_MIPMAP_NEAREST,
	mp_list<texture_min_filter>
> linear_mipmap_nearest = {};
#endif

#ifdef GL_LINES
static constexpr const enum_value<
	GLenum,
	GL_LINES,
	mp_list<primitive_type,transform_feedback_primitive_type>
> lines = {};
#endif

#ifdef GL_LINES_ADJACENCY
static constexpr const enum_value<
	GLenum,
	GL_LINES_ADJACENCY,
	mp_list<primitive_type>
> lines_adjacency = {};
#endif

#ifdef GL_LOW_FLOAT
static constexpr const enum_value<
	GLenum,
	GL_LOW_FLOAT,
	mp_list<precision_type>
> low_float = {};
#endif

#ifdef GL_LOW_INT
static constexpr const enum_value<
	GLenum,
	GL_LOW_INT,
	mp_list<precision_type>
> low_int = {};
#endif

#ifdef GL_MEDIUM_FLOAT
static constexpr const enum_value<
	GLenum,
	GL_MEDIUM_FLOAT,
	mp_list<precision_type>
> medium_float = {};
#endif

#ifdef GL_MEDIUM_INT
static constexpr const enum_value<
	GLenum,
	GL_MEDIUM_INT,
	mp_list<precision_type>
> medium_int = {};
#endif

#ifdef GL_MIRROR_CLAMP_TO_EDGE
static constexpr const enum_value<
	GLenum,
	GL_MIRROR_CLAMP_TO_EDGE,
	mp_list<texture_wrap>
> mirror_clamp_to_edge = {};
#endif

#ifdef GL_MIRRORED_REPEAT
static constexpr const enum_value<
	GLenum,
	GL_MIRRORED_REPEAT,
	mp_list<texture_wrap>
> mirrored_repeat = {};
#endif

#ifdef GL_MULTISAMPLE
static constexpr const enum_value<
	GLenum,
	GL_MULTISAMPLE,
	mp_list<capability>
> multisample = {};
#endif

#ifdef GL_NAND
static constexpr const enum_value<
	GLenum,
	GL_NAND,
	mp_list<color_logic_operation>
> nand = {};
#endif

#ifdef GL_NEAREST
static constexpr const enum_value<
	GLenum,
	GL_NEAREST,
	mp_list<texture_mag_filter,blit_filter,texture_filter,texture_min_filter>
> nearest = {};
#endif

#ifdef GL_NEAREST_MIPMAP_LINEAR
static constexpr const enum_value<
	GLenum,
	GL_NEAREST_MIPMAP_LINEAR,
	mp_list<texture_min_filter>
> nearest_mipmap_linear = {};
#endif

#ifdef GL_NEAREST_MIPMAP_NEAREST
static constexpr const enum_value<
	GLenum,
	GL_NEAREST_MIPMAP_NEAREST,
	mp_list<texture_min_filter>
> nearest_mipmap_nearest = {};
#endif

#ifdef GL_NEVER
static constexpr const enum_value<
	GLenum,
	GL_NEVER,
	mp_list<compare_function>
> never = {};
#endif

#ifdef GL_NICEST
static constexpr const enum_value<
	GLenum,
	GL_NICEST,
	mp_list<hint_option>
> nicest = {};
#endif

#ifdef GL_NO_ERROR
static constexpr const enum_value<
	GLenum,
	GL_NO_ERROR,
	mp_list<error_code>
> no_error = {};
#endif

#ifdef GL_NONE
static constexpr const enum_value<
	GLenum,
	GL_NONE,
	mp_list<color_buffer,object_type>
> none = {};
#endif

#ifdef GL_NOOP
static constexpr const enum_value<
	GLenum,
	GL_NOOP,
	mp_list<color_logic_operation>
> noop = {};
#endif

#ifdef GL_NOR
static constexpr const enum_value<
	GLenum,
	GL_NOR,
	mp_list<color_logic_operation>
> nor = {};
#endif

#ifdef GL_NOTEQUAL
static constexpr const enum_value<
	GLenum,
	GL_NOTEQUAL,
	mp_list<compare_function>
> notequal = {};
#endif

#ifdef GL_ONE
static constexpr const enum_value<
	GLenum,
	GL_ONE,
	mp_list<texture_swizzle>
> one = {};
#endif

#ifdef GL_OR
static constexpr const enum_value<
	GLenum,
	GL_OR,
	mp_list<color_logic_operation>
> or_ = {};
#endif

#ifdef GL_OR_INVERTED
static constexpr const enum_value<
	GLenum,
	GL_OR_INVERTED,
	mp_list<color_logic_operation>
> or_inverted = {};
#endif

#ifdef GL_OR_REVERSE
static constexpr const enum_value<
	GLenum,
	GL_OR_REVERSE,
	mp_list<color_logic_operation>
> or_reverse = {};
#endif

#ifdef GL_OUT_OF_MEMORY
static constexpr const enum_value<
	GLenum,
	GL_OUT_OF_MEMORY,
	mp_list<error_code>
> out_of_memory = {};
#endif

#ifdef GL_PARAMETER_BUFFER_ARB
static constexpr const enum_value<
	GLenum,
	GL_PARAMETER_BUFFER_ARB,
	mp_list<buffer_target>
> parameter_buffer = {};
#endif

#ifdef GL_PATCHES
static constexpr const enum_value<
	GLenum,
	GL_PATCHES,
	mp_list<primitive_type>
> patches = {};
#endif

#ifdef GL_PIXEL_PACK_BUFFER
static constexpr const enum_value<
	GLenum,
	GL_PIXEL_PACK_BUFFER,
	mp_list<buffer_target>
> pixel_pack_buffer = {};
#endif

#ifdef GL_PIXEL_UNPACK_BUFFER
static constexpr const enum_value<
	GLenum,
	GL_PIXEL_UNPACK_BUFFER,
	mp_list<buffer_target>
> pixel_unpack_buffer = {};
#endif

#ifdef GL_POINTS
static constexpr const enum_value<
	GLenum,
	GL_POINTS,
	mp_list<primitive_type,transform_feedback_primitive_type>
> points = {};
#endif

#ifdef GL_POLYGON_OFFSET_FILL
static constexpr const enum_value<
	GLenum,
	GL_POLYGON_OFFSET_FILL,
	mp_list<capability>
> polygon_offset_fill = {};
#endif

#ifdef GL_POLYGON_OFFSET_LINE
static constexpr const enum_value<
	GLenum,
	GL_POLYGON_OFFSET_LINE,
	mp_list<capability>
> polygon_offset_line = {};
#endif

#ifdef GL_POLYGON_OFFSET_POINT
static constexpr const enum_value<
	GLenum,
	GL_POLYGON_OFFSET_POINT,
	mp_list<capability>
> polygon_offset_point = {};
#endif

#ifdef GL_POLYGON_SMOOTH
static constexpr const enum_value<
	GLenum,
	GL_POLYGON_SMOOTH,
	mp_list<capability>
> polygon_smooth = {};
#endif

#ifdef GL_POLYGON_SMOOTH_HINT
static constexpr const enum_value<
	GLenum,
	GL_POLYGON_SMOOTH_HINT,
	mp_list<hint_target>
> polygon_smooth_hint = {};
#endif

#ifdef GL_PRIMITIVE_RESTART
static constexpr const enum_value<
	GLenum,
	GL_PRIMITIVE_RESTART,
	mp_list<capability>
> primitive_restart = {};
#endif

#ifdef GL_PROGRAM
static constexpr const enum_value<
	GLenum,
	GL_PROGRAM,
	mp_list<object_type>
> program = {};
#endif

#ifdef GL_PROGRAM_PIPELINE
static constexpr const enum_value<
	GLenum,
	GL_PROGRAM_PIPELINE,
	mp_list<object_type>
> program_pipeline = {};
#endif

#ifdef GL_PROGRAM_POINT_SIZE
static constexpr const enum_value<
	GLenum,
	GL_PROGRAM_POINT_SIZE,
	mp_list<capability>
> program_point_size = {};
#endif

#ifdef GL_QUERY
static constexpr const enum_value<
	GLenum,
	GL_QUERY,
	mp_list<object_type>
> query = {};
#endif

#ifdef GL_QUERY_BUFFER
static constexpr const enum_value<
	GLenum,
	GL_QUERY_BUFFER,
	mp_list<buffer_target>
> query_buffer = {};
#endif

#ifdef GL_QUERY_BY_REGION_NO_WAIT
static constexpr const enum_value<
	GLenum,
	GL_QUERY_BY_REGION_NO_WAIT,
	mp_list<conditional_render_mode>
> query_by_region_no_wait = {};
#endif

#ifdef GL_QUERY_BY_REGION_NO_WAIT_INVERTED
static constexpr const enum_value<
	GLenum,
	GL_QUERY_BY_REGION_NO_WAIT_INVERTED,
	mp_list<conditional_render_mode>
> query_by_region_no_wait_inverted = {};
#endif

#ifdef GL_QUERY_BY_REGION_WAIT
static constexpr const enum_value<
	GLenum,
	GL_QUERY_BY_REGION_WAIT,
	mp_list<conditional_render_mode>
> query_by_region_wait = {};
#endif

#ifdef GL_QUERY_BY_REGION_WAIT_INVERTED
static constexpr const enum_value<
	GLenum,
	GL_QUERY_BY_REGION_WAIT_INVERTED,
	mp_list<conditional_render_mode>
> query_by_region_wait_inverted = {};
#endif

#ifdef GL_QUERY_NO_WAIT
static constexpr const enum_value<
	GLenum,
	GL_QUERY_NO_WAIT,
	mp_list<conditional_render_mode>
> query_no_wait = {};
#endif

#ifdef GL_QUERY_NO_WAIT_INVERTED
static constexpr const enum_value<
	GLenum,
	GL_QUERY_NO_WAIT_INVERTED,
	mp_list<conditional_render_mode>
> query_no_wait_inverted = {};
#endif

#ifdef GL_QUERY_WAIT
static constexpr const enum_value<
	GLenum,
	GL_QUERY_WAIT,
	mp_list<conditional_render_mode>
> query_wait = {};
#endif

#ifdef GL_QUERY_WAIT_INVERTED
static constexpr const enum_value<
	GLenum,
	GL_QUERY_WAIT_INVERTED,
	mp_list<conditional_render_mode>
> query_wait_inverted = {};
#endif

#ifdef GL_R11F_G11F_B10F
static constexpr const enum_value<
	GLenum,
	GL_R11F_G11F_B10F,
	mp_list<pixel_data_internal_format>
> r11f_g11f_b10f = {};
#endif

#ifdef GL_R16
static constexpr const enum_value<
	GLenum,
	GL_R16,
	mp_list<pixel_data_internal_format>
> r16 = {};
#endif

#ifdef GL_R16_SNORM
static constexpr const enum_value<
	GLenum,
	GL_R16_SNORM,
	mp_list<pixel_data_internal_format>
> r16_snorm = {};
#endif

#ifdef GL_R16F
static constexpr const enum_value<
	GLenum,
	GL_R16F,
	mp_list<pixel_data_internal_format>
> r16f = {};
#endif

#ifdef GL_R16I
static constexpr const enum_value<
	GLenum,
	GL_R16I,
	mp_list<pixel_data_internal_format>
> r16i = {};
#endif

#ifdef GL_R16UI
static constexpr const enum_value<
	GLenum,
	GL_R16UI,
	mp_list<pixel_data_internal_format>
> r16ui = {};
#endif

#ifdef GL_R32F
static constexpr const enum_value<
	GLenum,
	GL_R32F,
	mp_list<pixel_data_internal_format>
> r32f = {};
#endif

#ifdef GL_R32I
static constexpr const enum_value<
	GLenum,
	GL_R32I,
	mp_list<pixel_data_internal_format>
> r32i = {};
#endif

#ifdef GL_R32UI
static constexpr const enum_value<
	GLenum,
	GL_R32UI,
	mp_list<pixel_data_internal_format>
> r32ui = {};
#endif

#ifdef GL_R3_G3_B2
static constexpr const enum_value<
	GLenum,
	GL_R3_G3_B2,
	mp_list<pixel_data_internal_format>
> r3_g3_b2 = {};
#endif

#ifdef GL_R8
static constexpr const enum_value<
	GLenum,
	GL_R8,
	mp_list<pixel_data_internal_format>
> r8 = {};
#endif

#ifdef GL_R8_SNORM
static constexpr const enum_value<
	GLenum,
	GL_R8_SNORM,
	mp_list<pixel_data_internal_format>
> r8_snorm = {};
#endif

#ifdef GL_R8I
static constexpr const enum_value<
	GLenum,
	GL_R8I,
	mp_list<pixel_data_internal_format>
> r8i = {};
#endif

#ifdef GL_R8UI
static constexpr const enum_value<
	GLenum,
	GL_R8UI,
	mp_list<pixel_data_internal_format>
> r8ui = {};
#endif

#ifdef GL_RASTERIZER_DISCARD
static constexpr const enum_value<
	GLenum,
	GL_RASTERIZER_DISCARD,
	mp_list<capability>
> rasterizer_discard = {};
#endif

#ifdef GL_READ_ONLY
static constexpr const enum_value<
	GLenum,
	GL_READ_ONLY,
	mp_list<access_specifier>
> read_only = {};
#endif

#ifdef GL_READ_WRITE
static constexpr const enum_value<
	GLenum,
	GL_READ_WRITE,
	mp_list<access_specifier>
> read_write = {};
#endif

#ifdef GL_RED
static constexpr const enum_value<
	GLenum,
	GL_RED,
	mp_list<texture_swizzle,pixel_data_format,pixel_data_internal_format>
> red = {};
#endif

#ifdef GL_RED_INTEGER
static constexpr const enum_value<
	GLenum,
	GL_RED_INTEGER,
	mp_list<pixel_data_format>
> red_integer = {};
#endif

#ifdef GL_RENDERBUFFER
static constexpr const enum_value<
	GLenum,
	GL_RENDERBUFFER,
	mp_list<object_type>
> renderbuffer = {};
#endif

#ifdef GL_RENDERER
static constexpr const enum_value<
	GLenum,
	GL_RENDERER,
	mp_list<string_query>
> renderer = {};
#endif

#ifdef GL_REPEAT
static constexpr const enum_value<
	GLenum,
	GL_REPEAT,
	mp_list<texture_wrap>
> repeat = {};
#endif

#ifdef GL_REPLACE
static constexpr const enum_value<
	GLenum,
	GL_REPLACE,
	mp_list<stencil_operation>
> replace = {};
#endif

#ifdef GL_RG
static constexpr const enum_value<
	GLenum,
	GL_RG,
	mp_list<pixel_data_format,pixel_data_internal_format>
> rg = {};
#endif

#ifdef GL_RG16
static constexpr const enum_value<
	GLenum,
	GL_RG16,
	mp_list<pixel_data_internal_format>
> rg16 = {};
#endif

#ifdef GL_RG16_SNORM
static constexpr const enum_value<
	GLenum,
	GL_RG16_SNORM,
	mp_list<pixel_data_internal_format>
> rg16_snorm = {};
#endif

#ifdef GL_RG16F
static constexpr const enum_value<
	GLenum,
	GL_RG16F,
	mp_list<pixel_data_internal_format>
> rg16f = {};
#endif

#ifdef GL_RG16I
static constexpr const enum_value<
	GLenum,
	GL_RG16I,
	mp_list<pixel_data_internal_format>
> rg16i = {};
#endif

#ifdef GL_RG16UI
static constexpr const enum_value<
	GLenum,
	GL_RG16UI,
	mp_list<pixel_data_internal_format>
> rg16ui = {};
#endif

#ifdef GL_RG32F
static constexpr const enum_value<
	GLenum,
	GL_RG32F,
	mp_list<pixel_data_internal_format>
> rg32f = {};
#endif

#ifdef GL_RG32I
static constexpr const enum_value<
	GLenum,
	GL_RG32I,
	mp_list<pixel_data_internal_format>
> rg32i = {};
#endif

#ifdef GL_RG32UI
static constexpr const enum_value<
	GLenum,
	GL_RG32UI,
	mp_list<pixel_data_internal_format>
> rg32ui = {};
#endif

#ifdef GL_RG8
static constexpr const enum_value<
	GLenum,
	GL_RG8,
	mp_list<pixel_data_internal_format>
> rg8 = {};
#endif

#ifdef GL_RG8_SNORM
static constexpr const enum_value<
	GLenum,
	GL_RG8_SNORM,
	mp_list<pixel_data_internal_format>
> rg8_snorm = {};
#endif

#ifdef GL_RG8I
static constexpr const enum_value<
	GLenum,
	GL_RG8I,
	mp_list<pixel_data_internal_format>
> rg8i = {};
#endif

#ifdef GL_RG8UI
static constexpr const enum_value<
	GLenum,
	GL_RG8UI,
	mp_list<pixel_data_internal_format>
> rg8ui = {};
#endif

#ifdef GL_RG_INTEGER
static constexpr const enum_value<
	GLenum,
	GL_RG_INTEGER,
	mp_list<pixel_data_format>
> rg_integer = {};
#endif

#ifdef GL_RGB
static constexpr const enum_value<
	GLenum,
	GL_RGB,
	mp_list<pixel_data_format,pixel_data_internal_format>
> rgb = {};
#endif

#ifdef GL_RGB10
static constexpr const enum_value<
	GLenum,
	GL_RGB10,
	mp_list<pixel_data_internal_format>
> rgb10 = {};
#endif

#ifdef GL_RGB10_A2
static constexpr const enum_value<
	GLenum,
	GL_RGB10_A2,
	mp_list<pixel_data_internal_format>
> rgb10_a2 = {};
#endif

#ifdef GL_RGB10_A2UI
static constexpr const enum_value<
	GLenum,
	GL_RGB10_A2UI,
	mp_list<pixel_data_internal_format>
> rgb10_a2ui = {};
#endif

#ifdef GL_RGB12
static constexpr const enum_value<
	GLenum,
	GL_RGB12,
	mp_list<pixel_data_internal_format>
> rgb12 = {};
#endif

#ifdef GL_RGB16
static constexpr const enum_value<
	GLenum,
	GL_RGB16,
	mp_list<pixel_data_internal_format>
> rgb16 = {};
#endif

#ifdef GL_RGB16_SNORM
static constexpr const enum_value<
	GLenum,
	GL_RGB16_SNORM,
	mp_list<pixel_data_internal_format>
> rgb16_snorm = {};
#endif

#ifdef GL_RGB16F
static constexpr const enum_value<
	GLenum,
	GL_RGB16F,
	mp_list<pixel_data_internal_format>
> rgb16f = {};
#endif

#ifdef GL_RGB16I
static constexpr const enum_value<
	GLenum,
	GL_RGB16I,
	mp_list<pixel_data_internal_format>
> rgb16i = {};
#endif

#ifdef GL_RGB16UI
static constexpr const enum_value<
	GLenum,
	GL_RGB16UI,
	mp_list<pixel_data_internal_format>
> rgb16ui = {};
#endif

#ifdef GL_RGB32F
static constexpr const enum_value<
	GLenum,
	GL_RGB32F,
	mp_list<pixel_data_internal_format>
> rgb32f = {};
#endif

#ifdef GL_RGB32I
static constexpr const enum_value<
	GLenum,
	GL_RGB32I,
	mp_list<pixel_data_internal_format>
> rgb32i = {};
#endif

#ifdef GL_RGB32UI
static constexpr const enum_value<
	GLenum,
	GL_RGB32UI,
	mp_list<pixel_data_internal_format>
> rgb32ui = {};
#endif

#ifdef GL_RGB4
static constexpr const enum_value<
	GLenum,
	GL_RGB4,
	mp_list<pixel_data_internal_format>
> rgb4 = {};
#endif

#ifdef GL_RGB5
static constexpr const enum_value<
	GLenum,
	GL_RGB5,
	mp_list<pixel_data_internal_format>
> rgb5 = {};
#endif

#ifdef GL_RGB5_A1
static constexpr const enum_value<
	GLenum,
	GL_RGB5_A1,
	mp_list<pixel_data_internal_format>
> rgb5_a1 = {};
#endif

#ifdef GL_RGB8
static constexpr const enum_value<
	GLenum,
	GL_RGB8,
	mp_list<pixel_data_internal_format>
> rgb8 = {};
#endif

#ifdef GL_RGB8_SNORM
static constexpr const enum_value<
	GLenum,
	GL_RGB8_SNORM,
	mp_list<pixel_data_internal_format>
> rgb8_snorm = {};
#endif

#ifdef GL_RGB8I
static constexpr const enum_value<
	GLenum,
	GL_RGB8I,
	mp_list<pixel_data_internal_format>
> rgb8i = {};
#endif

#ifdef GL_RGB8UI
static constexpr const enum_value<
	GLenum,
	GL_RGB8UI,
	mp_list<pixel_data_internal_format>
> rgb8ui = {};
#endif

#ifdef GL_RGB9_E5
static constexpr const enum_value<
	GLenum,
	GL_RGB9_E5,
	mp_list<pixel_data_internal_format>
> rgb9_e5 = {};
#endif

#ifdef GL_RGB_INTEGER
static constexpr const enum_value<
	GLenum,
	GL_RGB_INTEGER,
	mp_list<pixel_data_format>
> rgb_integer = {};
#endif

#ifdef GL_RGBA
static constexpr const enum_value<
	GLenum,
	GL_RGBA,
	mp_list<pixel_data_format,pixel_data_internal_format>
> rgba = {};
#endif

#ifdef GL_RGBA12
static constexpr const enum_value<
	GLenum,
	GL_RGBA12,
	mp_list<pixel_data_internal_format>
> rgba12 = {};
#endif

#ifdef GL_RGBA16
static constexpr const enum_value<
	GLenum,
	GL_RGBA16,
	mp_list<pixel_data_internal_format>
> rgba16 = {};
#endif

#ifdef GL_RGBA16_SNORM
static constexpr const enum_value<
	GLenum,
	GL_RGBA16_SNORM,
	mp_list<pixel_data_internal_format>
> rgba16_snorm = {};
#endif

#ifdef GL_RGBA16F
static constexpr const enum_value<
	GLenum,
	GL_RGBA16F,
	mp_list<pixel_data_internal_format>
> rgba16f = {};
#endif

#ifdef GL_RGBA16I
static constexpr const enum_value<
	GLenum,
	GL_RGBA16I,
	mp_list<pixel_data_internal_format>
> rgba16i = {};
#endif

#ifdef GL_RGBA16UI
static constexpr const enum_value<
	GLenum,
	GL_RGBA16UI,
	mp_list<pixel_data_internal_format>
> rgba16ui = {};
#endif

#ifdef GL_RGBA2
static constexpr const enum_value<
	GLenum,
	GL_RGBA2,
	mp_list<pixel_data_internal_format>
> rgba2 = {};
#endif

#ifdef GL_RGBA32F
static constexpr const enum_value<
	GLenum,
	GL_RGBA32F,
	mp_list<pixel_data_internal_format>
> rgba32f = {};
#endif

#ifdef GL_RGBA32I
static constexpr const enum_value<
	GLenum,
	GL_RGBA32I,
	mp_list<pixel_data_internal_format>
> rgba32i = {};
#endif

#ifdef GL_RGBA32UI
static constexpr const enum_value<
	GLenum,
	GL_RGBA32UI,
	mp_list<pixel_data_internal_format>
> rgba32ui = {};
#endif

#ifdef GL_RGBA4
static constexpr const enum_value<
	GLenum,
	GL_RGBA4,
	mp_list<pixel_data_internal_format>
> rgba4 = {};
#endif

#ifdef GL_RGBA8
static constexpr const enum_value<
	GLenum,
	GL_RGBA8,
	mp_list<pixel_data_internal_format>
> rgba8 = {};
#endif

#ifdef GL_RGBA8_SNORM
static constexpr const enum_value<
	GLenum,
	GL_RGBA8_SNORM,
	mp_list<pixel_data_internal_format>
> rgba8_snorm = {};
#endif

#ifdef GL_RGBA8I
static constexpr const enum_value<
	GLenum,
	GL_RGBA8I,
	mp_list<pixel_data_internal_format>
> rgba8i = {};
#endif

#ifdef GL_RGBA8UI
static constexpr const enum_value<
	GLenum,
	GL_RGBA8UI,
	mp_list<pixel_data_internal_format>
> rgba8ui = {};
#endif

#ifdef GL_RGBA_INTEGER
static constexpr const enum_value<
	GLenum,
	GL_RGBA_INTEGER,
	mp_list<pixel_data_format>
> rgba_integer = {};
#endif

#ifdef GL_RIGHT
static constexpr const enum_value<
	GLenum,
	GL_RIGHT,
	mp_list<color_buffer>
> right = {};
#endif

#ifdef GL_SAMPLE_ALPHA_TO_COVERAGE
static constexpr const enum_value<
	GLenum,
	GL_SAMPLE_ALPHA_TO_COVERAGE,
	mp_list<capability>
> sample_alpha_to_coverage = {};
#endif

#ifdef GL_SAMPLE_ALPHA_TO_ONE
static constexpr const enum_value<
	GLenum,
	GL_SAMPLE_ALPHA_TO_ONE,
	mp_list<capability>
> sample_alpha_to_one = {};
#endif

#ifdef GL_SAMPLE_COVERAGE
static constexpr const enum_value<
	GLenum,
	GL_SAMPLE_COVERAGE,
	mp_list<capability>
> sample_coverage = {};
#endif

#ifdef GL_SAMPLE_MASK
static constexpr const enum_value<
	GLenum,
	GL_SAMPLE_MASK,
	mp_list<capability>
> sample_mask = {};
#endif

#ifdef GL_SAMPLE_SHADING
static constexpr const enum_value<
	GLenum,
	GL_SAMPLE_SHADING,
	mp_list<capability>
> sample_shading = {};
#endif

#ifdef GL_SAMPLER
static constexpr const enum_value<
	GLenum,
	GL_SAMPLER,
	mp_list<object_type>
> sampler = {};
#endif

#ifdef GL_SCISSOR_TEST
static constexpr const enum_value<
	GLenum,
	GL_SCISSOR_TEST,
	mp_list<capability>
> scissor_test = {};
#endif

#ifdef GL_SEPARATE_ATTRIBS
static constexpr const enum_value<
	GLenum,
	GL_SEPARATE_ATTRIBS,
	mp_list<transform_feedback_mode>
> separate_attribs = {};
#endif

#ifdef GL_SET
static constexpr const enum_value<
	GLenum,
	GL_SET,
	mp_list<color_logic_operation>
> set = {};
#endif

#ifdef GL_SHADER
static constexpr const enum_value<
	GLenum,
	GL_SHADER,
	mp_list<object_type>
> shader = {};
#endif

#ifdef GL_SHADER_STORAGE_BUFFER
static constexpr const enum_value<
	GLenum,
	GL_SHADER_STORAGE_BUFFER,
	mp_list<buffer_target>
> shader_storage_buffer = {};
#endif

#ifdef GL_SHADING_LANGUAGE_VERSION
static constexpr const enum_value<
	GLenum,
	GL_SHADING_LANGUAGE_VERSION,
	mp_list<string_query>
> shading_language_version = {};
#endif

#ifdef GL_SHORT
static constexpr const enum_value<
	GLenum,
	GL_SHORT,
	mp_list<data_type>
> short_ = {};
#endif

#ifdef GL_SIGNALED
static constexpr const enum_value<
	GLenum,
	GL_SIGNALED,
	mp_list<sync_status>
> signaled = {};
#endif

#ifdef GL_SRGB8
static constexpr const enum_value<
	GLenum,
	GL_SRGB8,
	mp_list<pixel_data_internal_format>
> srgb8 = {};
#endif

#ifdef GL_SRGB8_ALPHA8
static constexpr const enum_value<
	GLenum,
	GL_SRGB8_ALPHA8,
	mp_list<pixel_data_internal_format>
> srgb8_alpha8 = {};
#endif

#ifdef GL_STACK_OVERFLOW
static constexpr const enum_value<
	GLenum,
	GL_STACK_OVERFLOW,
	mp_list<error_code>
> stack_overflow = {};
#endif

#ifdef GL_STACK_UNDERFLOW
static constexpr const enum_value<
	GLenum,
	GL_STACK_UNDERFLOW,
	mp_list<error_code>
> stack_underflow = {};
#endif

#ifdef GL_STATIC_COPY
static constexpr const enum_value<
	GLenum,
	GL_STATIC_COPY,
	mp_list<buffer_usage>
> static_copy = {};
#endif

#ifdef GL_STATIC_DRAW
static constexpr const enum_value<
	GLenum,
	GL_STATIC_DRAW,
	mp_list<buffer_usage>
> static_draw = {};
#endif

#ifdef GL_STATIC_READ
static constexpr const enum_value<
	GLenum,
	GL_STATIC_READ,
	mp_list<buffer_usage>
> static_read = {};
#endif

#ifdef GL_STENCIL_BUFFER_BIT
static constexpr const enum_value<
	GLbitfield,
	GL_STENCIL_BUFFER_BIT,
	mp_list<buffer_select_bit>
> stencil_buffer_bit = {};
#endif

#ifdef GL_STENCIL_INDEX
static constexpr const enum_value<
	GLenum,
	GL_STENCIL_INDEX,
	mp_list<pixel_data_format>
> stencil_index = {};
#endif

#ifdef GL_STENCIL_INDEX8
static constexpr const enum_value<
	GLenum,
	GL_STENCIL_INDEX8,
	mp_list<pixel_data_internal_format>
> stencil_index8 = {};
#endif

#ifdef GL_STENCIL_TEST
static constexpr const enum_value<
	GLenum,
	GL_STENCIL_TEST,
	mp_list<capability>
> stencil_test = {};
#endif

#ifdef GL_STREAM_COPY
static constexpr const enum_value<
	GLenum,
	GL_STREAM_COPY,
	mp_list<buffer_usage>
> stream_copy = {};
#endif

#ifdef GL_STREAM_DRAW
static constexpr const enum_value<
	GLenum,
	GL_STREAM_DRAW,
	mp_list<buffer_usage>
> stream_draw = {};
#endif

#ifdef GL_STREAM_RASTERIZATION_AMD
static constexpr const enum_value<
	GLenum,
	GL_STREAM_RASTERIZATION_AMD,
	mp_list<capability>
> stream_rasterization = {};
#endif

#ifdef GL_STREAM_READ
static constexpr const enum_value<
	GLenum,
	GL_STREAM_READ,
	mp_list<buffer_usage>
> stream_read = {};
#endif

#ifdef GL_SYNC_FENCE
static constexpr const enum_value<
	GLenum,
	GL_SYNC_FENCE,
	mp_list<sync_type>
> sync_fence = {};
#endif

#ifdef GL_SYNC_GPU_COMMANDS_COMPLETE
static constexpr const enum_value<
	GLenum,
	GL_SYNC_GPU_COMMANDS_COMPLETE,
	mp_list<sync_condition>
> sync_gpu_commands_complete = {};
#endif

#ifdef GL_TABLE_TOO_LARGE
static constexpr const enum_value<
	GLenum,
	GL_TABLE_TOO_LARGE,
	mp_list<error_code>
> table_too_large = {};
#endif

#ifdef GL_TESS_CONTROL_SHADER
static constexpr const enum_value<
	GLenum,
	GL_TESS_CONTROL_SHADER,
	mp_list<shader_type>
> tess_control_shader = {};
#endif

#ifdef GL_TESS_EVALUATION_SHADER
static constexpr const enum_value<
	GLenum,
	GL_TESS_EVALUATION_SHADER,
	mp_list<shader_type>
> tess_evaluation_shader = {};
#endif

#ifdef GL_TEXTURE
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE,
	mp_list<object_type>
> texture = {};
#endif

#ifdef GL_TEXTURE_1D
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_1D,
	mp_list<texture_target>
> texture_1d = {};
#endif

#ifdef GL_TEXTURE_1D_ARRAY
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_1D_ARRAY,
	mp_list<texture_target>
> texture_1d_array = {};
#endif

#ifdef GL_TEXTURE_2D
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_2D,
	mp_list<texture_target>
> texture_2d = {};
#endif

#ifdef GL_TEXTURE_2D_ARRAY
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_2D_ARRAY,
	mp_list<texture_target>
> texture_2d_array = {};
#endif

#ifdef GL_TEXTURE_2D_MULTISAMPLE
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_2D_MULTISAMPLE,
	mp_list<texture_target>
> texture_2d_multisample = {};
#endif

#ifdef GL_TEXTURE_2D_MULTISAMPLE_ARRAY
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_2D_MULTISAMPLE_ARRAY,
	mp_list<texture_target>
> texture_2d_multisample_array = {};
#endif

#ifdef GL_TEXTURE_3D
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_3D,
	mp_list<texture_target>
> texture_3d = {};
#endif

#ifdef GL_TEXTURE_BUFFER
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_BUFFER,
	mp_list<texture_target,buffer_target>
> texture_buffer = {};
#endif

#ifdef GL_TEXTURE_COMPRESSION_HINT
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_COMPRESSION_HINT,
	mp_list<hint_target>
> texture_compression_hint = {};
#endif

#ifdef GL_TEXTURE_CUBE_MAP
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_CUBE_MAP,
	mp_list<texture_target>
> texture_cube_map = {};
#endif

#ifdef GL_TEXTURE_CUBE_MAP_ARRAY
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_CUBE_MAP_ARRAY,
	mp_list<texture_target>
> texture_cube_map_array = {};
#endif

#ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_X
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_CUBE_MAP_NEGATIVE_X,
	mp_list<texture_target>
> texture_cube_map_negative_x = {};
#endif

#ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_Y
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_CUBE_MAP_NEGATIVE_Y,
	mp_list<texture_target>
> texture_cube_map_negative_y = {};
#endif

#ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_Z
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_CUBE_MAP_NEGATIVE_Z,
	mp_list<texture_target>
> texture_cube_map_negative_z = {};
#endif

#ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_X
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_CUBE_MAP_POSITIVE_X,
	mp_list<texture_target>
> texture_cube_map_positive_x = {};
#endif

#ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_Y
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_CUBE_MAP_POSITIVE_Y,
	mp_list<texture_target>
> texture_cube_map_positive_y = {};
#endif

#ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_Z
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_CUBE_MAP_POSITIVE_Z,
	mp_list<texture_target>
> texture_cube_map_positive_z = {};
#endif

#ifdef GL_TEXTURE_CUBE_MAP_SEAMLESS
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_CUBE_MAP_SEAMLESS,
	mp_list<capability>
> texture_cube_map_seamless = {};
#endif

#ifdef GL_TEXTURE_RECTANGLE
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_RECTANGLE,
	mp_list<texture_target>
> texture_rectangle = {};
#endif

#ifdef GL_TEXTURE_SWIZZLE_A
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_SWIZZLE_A,
	mp_list<texture_swizzle_coord>
> texture_swizzle_a = {};
#endif

#ifdef GL_TEXTURE_SWIZZLE_B
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_SWIZZLE_B,
	mp_list<texture_swizzle_coord>
> texture_swizzle_b = {};
#endif

#ifdef GL_TEXTURE_SWIZZLE_G
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_SWIZZLE_G,
	mp_list<texture_swizzle_coord>
> texture_swizzle_g = {};
#endif

#ifdef GL_TEXTURE_SWIZZLE_R
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_SWIZZLE_R,
	mp_list<texture_swizzle_coord>
> texture_swizzle_r = {};
#endif

#ifdef GL_TEXTURE_SWIZZLE_RGBA
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_SWIZZLE_RGBA,
	mp_list<texture_swizzle_coord>
> texture_swizzle_rgba = {};
#endif

#ifdef GL_TEXTURE_WRAP_R
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_WRAP_R,
	mp_list<texture_wrap_coord>
> texture_wrap_r = {};
#endif

#ifdef GL_TEXTURE_WRAP_S
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_WRAP_S,
	mp_list<texture_wrap_coord>
> texture_wrap_s = {};
#endif

#ifdef GL_TEXTURE_WRAP_T
static constexpr const enum_value<
	GLenum,
	GL_TEXTURE_WRAP_T,
	mp_list<texture_wrap_coord>
> texture_wrap_t = {};
#endif

#ifdef GL_TIMEOUT_EXPIRED
static constexpr const enum_value<
	GLenum,
	GL_TIMEOUT_EXPIRED,
	mp_list<sync_wait_result>
> timeout_expired = {};
#endif

#ifdef GL_TRANSFORM_FEEDBACK
static constexpr const enum_value<
	GLenum,
	GL_TRANSFORM_FEEDBACK,
	mp_list<transform_feedback_target,object_type>
> transform_feedback = {};
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BUFFER
static constexpr const enum_value<
	GLenum,
	GL_TRANSFORM_FEEDBACK_BUFFER,
	mp_list<buffer_target>
> transform_feedback_buffer = {};
#endif

#ifdef GL_TRIANGLE_FAN
static constexpr const enum_value<
	GLenum,
	GL_TRIANGLE_FAN,
	mp_list<primitive_type>
> triangle_fan = {};
#endif

#ifdef GL_TRIANGLE_STRIP
static constexpr const enum_value<
	GLenum,
	GL_TRIANGLE_STRIP,
	mp_list<primitive_type>
> triangle_strip = {};
#endif

#ifdef GL_TRIANGLE_STRIP_ADJACENCY
static constexpr const enum_value<
	GLenum,
	GL_TRIANGLE_STRIP_ADJACENCY,
	mp_list<primitive_type>
> triangle_strip_adjacency = {};
#endif

#ifdef GL_TRIANGLES
static constexpr const enum_value<
	GLenum,
	GL_TRIANGLES,
	mp_list<primitive_type,transform_feedback_primitive_type>
> triangles = {};
#endif

#ifdef GL_TRIANGLES_ADJACENCY
static constexpr const enum_value<
	GLenum,
	GL_TRIANGLES_ADJACENCY,
	mp_list<primitive_type>
> triangles_adjacency = {};
#endif

#ifdef GL_UNIFORM_BUFFER
static constexpr const enum_value<
	GLenum,
	GL_UNIFORM_BUFFER,
	mp_list<buffer_target>
> uniform_buffer = {};
#endif

#ifdef GL_UNSIGNALED
static constexpr const enum_value<
	GLenum,
	GL_UNSIGNALED,
	mp_list<sync_status>
> unsignaled = {};
#endif

#ifdef GL_UNSIGNED_BYTE
static constexpr const enum_value<
	GLenum,
	GL_UNSIGNED_BYTE,
	mp_list<data_type>
> unsigned_byte = {};
#endif

#ifdef GL_UNSIGNED_INT
static constexpr const enum_value<
	GLenum,
	GL_UNSIGNED_INT,
	mp_list<data_type>
> unsigned_int = {};
#endif

#ifdef GL_UNSIGNED_SHORT
static constexpr const enum_value<
	GLenum,
	GL_UNSIGNED_SHORT,
	mp_list<data_type>
> unsigned_short = {};
#endif

#ifdef GL_VENDOR
static constexpr const enum_value<
	GLenum,
	GL_VENDOR,
	mp_list<string_query>
> vendor = {};
#endif

#ifdef GL_VERSION
static constexpr const enum_value<
	GLenum,
	GL_VERSION,
	mp_list<string_query>
> version = {};
#endif

#ifdef GL_VERTEX_ARRAY
static constexpr const enum_value<
	GLenum,
	GL_VERTEX_ARRAY,
	mp_list<object_type>
> vertex_array = {};
#endif

#ifdef GL_VERTEX_SHADER
static constexpr const enum_value<
	GLenum,
	GL_VERTEX_SHADER,
	mp_list<shader_type>
> vertex_shader = {};
#endif

#ifdef GL_WAIT_FAILED
static constexpr const enum_value<
	GLenum,
	GL_WAIT_FAILED,
	mp_list<sync_wait_result>
> wait_failed = {};
#endif

#ifdef GL_WRITE_ONLY
static constexpr const enum_value<
	GLenum,
	GL_WRITE_ONLY,
	mp_list<access_specifier>
> write_only = {};
#endif

#ifdef GL_XOR
static constexpr const enum_value<
	GLenum,
	GL_XOR,
	mp_list<color_logic_operation>
> xor_ = {};
#endif

#ifdef GL_ZERO
static constexpr const enum_value<
	GLenum,
	GL_ZERO,
	mp_list<texture_swizzle,stencil_operation>
> zero = {};
#endif

};// struct enum_values
} // namespace oglplus

#endif // include guard
