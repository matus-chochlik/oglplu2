//  File implement/oglplus/enum_value_range.inl
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
#include <oglplus/config/basic.hpp>
#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)

namespace oglplus {

OGLPLUS_LIB_FUNC
std::pair<const void*, std::size_t>
get_enum_value_range(const any_enum_class& aec)
noexcept
{
	switch(aec._type_id)
	{
		case 0: /* access_specifier */
		{
			static const GLenum vr[] = {
#ifdef GL_READ_ONLY
				GL_READ_ONLY,
#endif
#ifdef GL_READ_WRITE
				GL_READ_WRITE,
#endif
#ifdef GL_WRITE_ONLY
				GL_WRITE_ONLY,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 1: /* blend_equation */
		{
			static const GLenum vr[] = {
#ifdef GL_FUNC_ADD
				GL_FUNC_ADD,
#endif
#ifdef GL_FUNC_REVERSE_SUBTRACT
				GL_FUNC_REVERSE_SUBTRACT,
#endif
#ifdef GL_FUNC_SUBTRACT
				GL_FUNC_SUBTRACT,
#endif
#ifdef GL_MAX
				GL_MAX,
#endif
#ifdef GL_MIN
				GL_MIN,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 2: /* blend_equation_advanced */
		{
			static const GLenum vr[] = {
#ifdef GL_COLORBURN_KHR
				GL_COLORBURN_KHR,
#endif
#ifdef GL_COLORDODGE_KHR
				GL_COLORDODGE_KHR,
#endif
#ifdef GL_DARKEN_KHR
				GL_DARKEN_KHR,
#endif
#ifdef GL_DIFFERENCE_KHR
				GL_DIFFERENCE_KHR,
#endif
#ifdef GL_EXCLUSION_KHR
				GL_EXCLUSION_KHR,
#endif
#ifdef GL_HARDLIGHT_KHR
				GL_HARDLIGHT_KHR,
#endif
#ifdef GL_HSL_COLOR_KHR
				GL_HSL_COLOR_KHR,
#endif
#ifdef GL_HSL_HUE_KHR
				GL_HSL_HUE_KHR,
#endif
#ifdef GL_HSL_LUMINOSITY_KHR
				GL_HSL_LUMINOSITY_KHR,
#endif
#ifdef GL_HSL_SATURATION_KHR
				GL_HSL_SATURATION_KHR,
#endif
#ifdef GL_LIGHTEN_KHR
				GL_LIGHTEN_KHR,
#endif
#ifdef GL_MULTIPLY_KHR
				GL_MULTIPLY_KHR,
#endif
#ifdef GL_OVERLAY_KHR
				GL_OVERLAY_KHR,
#endif
#ifdef GL_SCREEN_KHR
				GL_SCREEN_KHR,
#endif
#ifdef GL_SOFTLIGHT_KHR
				GL_SOFTLIGHT_KHR,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 3: /* blend_function */
		{
			static const GLenum vr[] = {
#ifdef GL_CONSTANT_ALPHA
				GL_CONSTANT_ALPHA,
#endif
#ifdef GL_CONSTANT_COLOR
				GL_CONSTANT_COLOR,
#endif
#ifdef GL_DST_ALPHA
				GL_DST_ALPHA,
#endif
#ifdef GL_DST_COLOR
				GL_DST_COLOR,
#endif
#ifdef GL_ONE
				GL_ONE,
#endif
#ifdef GL_ONE_MINUS_CONSTANT_ALPHA
				GL_ONE_MINUS_CONSTANT_ALPHA,
#endif
#ifdef GL_ONE_MINUS_CONSTANT_COLOR
				GL_ONE_MINUS_CONSTANT_COLOR,
#endif
#ifdef GL_ONE_MINUS_DST_ALPHA
				GL_ONE_MINUS_DST_ALPHA,
#endif
#ifdef GL_ONE_MINUS_DST_COLOR
				GL_ONE_MINUS_DST_COLOR,
#endif
#ifdef GL_ONE_MINUS_SRC1_ALPHA
				GL_ONE_MINUS_SRC1_ALPHA,
#endif
#ifdef GL_ONE_MINUS_SRC1_COLOR
				GL_ONE_MINUS_SRC1_COLOR,
#endif
#ifdef GL_ONE_MINUS_SRC_ALPHA
				GL_ONE_MINUS_SRC_ALPHA,
#endif
#ifdef GL_ONE_MINUS_SRC_COLOR
				GL_ONE_MINUS_SRC_COLOR,
#endif
#ifdef GL_SRC1_ALPHA
				GL_SRC1_ALPHA,
#endif
#ifdef GL_SRC1_COLOR
				GL_SRC1_COLOR,
#endif
#ifdef GL_SRC_ALPHA
				GL_SRC_ALPHA,
#endif
#ifdef GL_SRC_ALPHA_SATURATE
				GL_SRC_ALPHA_SATURATE,
#endif
#ifdef GL_SRC_COLOR
				GL_SRC_COLOR,
#endif
#ifdef GL_ZERO
				GL_ZERO,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 4: /* blit_filter */
		{
			static const GLenum vr[] = {
#ifdef GL_LINEAR
				GL_LINEAR,
#endif
#ifdef GL_NEAREST
				GL_NEAREST,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 5: /* buffer_indexed_target */
		{
			static const GLenum vr[] = {
#ifdef GL_ATOMIC_COUNTER_BUFFER
				GL_ATOMIC_COUNTER_BUFFER,
#endif
#ifdef GL_SHADER_STORAGE_BUFFER
				GL_SHADER_STORAGE_BUFFER,
#endif
#ifdef GL_TRANSFORM_FEEDBACK_BUFFER
				GL_TRANSFORM_FEEDBACK_BUFFER,
#endif
#ifdef GL_UNIFORM_BUFFER
				GL_UNIFORM_BUFFER,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 6: /* buffer_map_access */
		{
			static const GLbitfield vr[] = {
#ifdef GL_MAP_COHERENT_BIT
				GL_MAP_COHERENT_BIT,
#endif
#ifdef GL_MAP_FLUSH_EXPLICIT_BIT
				GL_MAP_FLUSH_EXPLICIT_BIT,
#endif
#ifdef GL_MAP_INVALIDATE_BUFFER_BIT
				GL_MAP_INVALIDATE_BUFFER_BIT,
#endif
#ifdef GL_MAP_INVALIDATE_RANGE_BIT
				GL_MAP_INVALIDATE_RANGE_BIT,
#endif
#ifdef GL_MAP_PERSISTENT_BIT
				GL_MAP_PERSISTENT_BIT,
#endif
#ifdef GL_MAP_READ_BIT
				GL_MAP_READ_BIT,
#endif
#ifdef GL_MAP_UNSYNCHRONIZED_BIT
				GL_MAP_UNSYNCHRONIZED_BIT,
#endif
#ifdef GL_MAP_WRITE_BIT
				GL_MAP_WRITE_BIT,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 7: /* buffer_select_bits */
		{
			static const GLbitfield vr[] = {
#ifdef GL_COLOR_BUFFER_BIT
				GL_COLOR_BUFFER_BIT,
#endif
#ifdef GL_DEPTH_BUFFER_BIT
				GL_DEPTH_BUFFER_BIT,
#endif
#ifdef GL_STENCIL_BUFFER_BIT
				GL_STENCIL_BUFFER_BIT,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 8: /* buffer_storage_bits */
		{
			static const GLbitfield vr[] = {
#ifdef GL_CLIENT_STORAGE_BIT
				GL_CLIENT_STORAGE_BIT,
#endif
#ifdef GL_DYNAMIC_STORAGE_BIT
				GL_DYNAMIC_STORAGE_BIT,
#endif
#ifdef GL_MAP_COHERENT_BIT
				GL_MAP_COHERENT_BIT,
#endif
#ifdef GL_MAP_PERSISTENT_BIT
				GL_MAP_PERSISTENT_BIT,
#endif
#ifdef GL_MAP_READ_BIT
				GL_MAP_READ_BIT,
#endif
#ifdef GL_MAP_WRITE_BIT
				GL_MAP_WRITE_BIT,
#endif
#ifdef GL_SPARSE_STORAGE_BIT_ARB
				GL_SPARSE_STORAGE_BIT_ARB,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 9: /* buffer_target */
		{
			static const GLenum vr[] = {
#ifdef GL_ARRAY_BUFFER
				GL_ARRAY_BUFFER,
#endif
#ifdef GL_ATOMIC_COUNTER_BUFFER
				GL_ATOMIC_COUNTER_BUFFER,
#endif
#ifdef GL_COPY_READ_BUFFER
				GL_COPY_READ_BUFFER,
#endif
#ifdef GL_COPY_WRITE_BUFFER
				GL_COPY_WRITE_BUFFER,
#endif
#ifdef GL_DISPATCH_INDIRECT_BUFFER
				GL_DISPATCH_INDIRECT_BUFFER,
#endif
#ifdef GL_DRAW_INDIRECT_BUFFER
				GL_DRAW_INDIRECT_BUFFER,
#endif
#ifdef GL_ELEMENT_ARRAY_BUFFER
				GL_ELEMENT_ARRAY_BUFFER,
#endif
#ifdef GL_EXTERNAL_VIRTUAL_MEMORY_BUFFER_AMD
				GL_EXTERNAL_VIRTUAL_MEMORY_BUFFER_AMD,
#endif
#ifdef GL_PARAMETER_BUFFER_ARB
				GL_PARAMETER_BUFFER_ARB,
#endif
#ifdef GL_PIXEL_PACK_BUFFER
				GL_PIXEL_PACK_BUFFER,
#endif
#ifdef GL_PIXEL_UNPACK_BUFFER
				GL_PIXEL_UNPACK_BUFFER,
#endif
#ifdef GL_QUERY_BUFFER
				GL_QUERY_BUFFER,
#endif
#ifdef GL_SHADER_STORAGE_BUFFER
				GL_SHADER_STORAGE_BUFFER,
#endif
#ifdef GL_TEXTURE_BUFFER
				GL_TEXTURE_BUFFER,
#endif
#ifdef GL_TRANSFORM_FEEDBACK_BUFFER
				GL_TRANSFORM_FEEDBACK_BUFFER,
#endif
#ifdef GL_UNIFORM_BUFFER
				GL_UNIFORM_BUFFER,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 10: /* buffer_usage */
		{
			static const GLenum vr[] = {
#ifdef GL_DYNAMIC_COPY
				GL_DYNAMIC_COPY,
#endif
#ifdef GL_DYNAMIC_DRAW
				GL_DYNAMIC_DRAW,
#endif
#ifdef GL_DYNAMIC_READ
				GL_DYNAMIC_READ,
#endif
#ifdef GL_STATIC_COPY
				GL_STATIC_COPY,
#endif
#ifdef GL_STATIC_DRAW
				GL_STATIC_DRAW,
#endif
#ifdef GL_STATIC_READ
				GL_STATIC_READ,
#endif
#ifdef GL_STREAM_COPY
				GL_STREAM_COPY,
#endif
#ifdef GL_STREAM_DRAW
				GL_STREAM_DRAW,
#endif
#ifdef GL_STREAM_READ
				GL_STREAM_READ,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 11: /* capability */
		{
			static const GLenum vr[] = {
#ifdef GL_BLEND
				GL_BLEND,
#endif
#ifdef GL_BLEND_ADVANCED_COHERENT_KHR
				GL_BLEND_ADVANCED_COHERENT_KHR,
#endif
#ifdef GL_COLOR_LOGIC_OP
				GL_COLOR_LOGIC_OP,
#endif
#ifdef GL_CULL_FACE
				GL_CULL_FACE,
#endif
#ifdef GL_DEBUG_OUTPUT_SYNCHRONOUS
				GL_DEBUG_OUTPUT_SYNCHRONOUS,
#endif
#ifdef GL_DEPTH_TEST
				GL_DEPTH_TEST,
#endif
#ifdef GL_DITHER
				GL_DITHER,
#endif
#ifdef GL_FRAGMENT_COVERAGE_TO_COLOR_NV
				GL_FRAGMENT_COVERAGE_TO_COLOR_NV,
#endif
#ifdef GL_FRAMEBUFFER_SRGB
				GL_FRAMEBUFFER_SRGB,
#endif
#ifdef GL_LINE_SMOOTH
				GL_LINE_SMOOTH,
#endif
#ifdef GL_MULTISAMPLE
				GL_MULTISAMPLE,
#endif
#ifdef GL_POLYGON_OFFSET_FILL
				GL_POLYGON_OFFSET_FILL,
#endif
#ifdef GL_POLYGON_OFFSET_LINE
				GL_POLYGON_OFFSET_LINE,
#endif
#ifdef GL_POLYGON_OFFSET_POINT
				GL_POLYGON_OFFSET_POINT,
#endif
#ifdef GL_POLYGON_SMOOTH
				GL_POLYGON_SMOOTH,
#endif
#ifdef GL_PRIMITIVE_RESTART
				GL_PRIMITIVE_RESTART,
#endif
#ifdef GL_PROGRAM_POINT_SIZE
				GL_PROGRAM_POINT_SIZE,
#endif
#ifdef GL_RASTERIZER_DISCARD
				GL_RASTERIZER_DISCARD,
#endif
#ifdef GL_SAMPLE_ALPHA_TO_COVERAGE
				GL_SAMPLE_ALPHA_TO_COVERAGE,
#endif
#ifdef GL_SAMPLE_ALPHA_TO_ONE
				GL_SAMPLE_ALPHA_TO_ONE,
#endif
#ifdef GL_SAMPLE_COVERAGE
				GL_SAMPLE_COVERAGE,
#endif
#ifdef GL_SAMPLE_MASK
				GL_SAMPLE_MASK,
#endif
#ifdef GL_SAMPLE_SHADING
				GL_SAMPLE_SHADING,
#endif
#ifdef GL_SCISSOR_TEST
				GL_SCISSOR_TEST,
#endif
#ifdef GL_STENCIL_TEST
				GL_STENCIL_TEST,
#endif
#ifdef GL_STREAM_RASTERIZATION_AMD
				GL_STREAM_RASTERIZATION_AMD,
#endif
#ifdef GL_TEXTURE_CUBE_MAP_SEAMLESS
				GL_TEXTURE_CUBE_MAP_SEAMLESS,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 12: /* clip_depth_mode */
		{
			static const GLenum vr[] = {
#ifdef GL_NEGATIVE_ONE_TO_ONE
				GL_NEGATIVE_ONE_TO_ONE,
#endif
#ifdef GL_ZERO_TO_ONE
				GL_ZERO_TO_ONE,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 13: /* clip_origin */
		{
			static const GLenum vr[] = {
#ifdef GL_LOWER_LEFT
				GL_LOWER_LEFT,
#endif
#ifdef GL_UPPER_LEFT
				GL_UPPER_LEFT,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 14: /* color_buffer */
		{
			static const GLenum vr[] = {
#ifdef GL_BACK
				GL_BACK,
#endif
#ifdef GL_BACK_LEFT
				GL_BACK_LEFT,
#endif
#ifdef GL_BACK_RIGHT
				GL_BACK_RIGHT,
#endif
#ifdef GL_FRONT
				GL_FRONT,
#endif
#ifdef GL_FRONT_AND_BACK
				GL_FRONT_AND_BACK,
#endif
#ifdef GL_FRONT_LEFT
				GL_FRONT_LEFT,
#endif
#ifdef GL_FRONT_RIGHT
				GL_FRONT_RIGHT,
#endif
#ifdef GL_LEFT
				GL_LEFT,
#endif
#ifdef GL_NONE
				GL_NONE,
#endif
#ifdef GL_RIGHT
				GL_RIGHT,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 15: /* color_logic_operation */
		{
			static const GLenum vr[] = {
#ifdef GL_AND
				GL_AND,
#endif
#ifdef GL_AND_INVERTED
				GL_AND_INVERTED,
#endif
#ifdef GL_AND_REVERSE
				GL_AND_REVERSE,
#endif
#ifdef GL_CLEAR
				GL_CLEAR,
#endif
#ifdef GL_COPY
				GL_COPY,
#endif
#ifdef GL_COPY_INVERTED
				GL_COPY_INVERTED,
#endif
#ifdef GL_EQUIV
				GL_EQUIV,
#endif
#ifdef GL_INVERT
				GL_INVERT,
#endif
#ifdef GL_NAND
				GL_NAND,
#endif
#ifdef GL_NOOP
				GL_NOOP,
#endif
#ifdef GL_NOR
				GL_NOR,
#endif
#ifdef GL_OR
				GL_OR,
#endif
#ifdef GL_OR_INVERTED
				GL_OR_INVERTED,
#endif
#ifdef GL_OR_REVERSE
				GL_OR_REVERSE,
#endif
#ifdef GL_SET
				GL_SET,
#endif
#ifdef GL_XOR
				GL_XOR,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 16: /* compare_function */
		{
			static const GLenum vr[] = {
#ifdef GL_ALWAYS
				GL_ALWAYS,
#endif
#ifdef GL_EQUAL
				GL_EQUAL,
#endif
#ifdef GL_GEQUAL
				GL_GEQUAL,
#endif
#ifdef GL_GREATER
				GL_GREATER,
#endif
#ifdef GL_LEQUAL
				GL_LEQUAL,
#endif
#ifdef GL_LESS
				GL_LESS,
#endif
#ifdef GL_NEVER
				GL_NEVER,
#endif
#ifdef GL_NOTEQUAL
				GL_NOTEQUAL,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 17: /* conditional_render_mode */
		{
			static const GLenum vr[] = {
#ifdef GL_QUERY_BY_REGION_NO_WAIT
				GL_QUERY_BY_REGION_NO_WAIT,
#endif
#ifdef GL_QUERY_BY_REGION_NO_WAIT_INVERTED
				GL_QUERY_BY_REGION_NO_WAIT_INVERTED,
#endif
#ifdef GL_QUERY_BY_REGION_WAIT
				GL_QUERY_BY_REGION_WAIT,
#endif
#ifdef GL_QUERY_BY_REGION_WAIT_INVERTED
				GL_QUERY_BY_REGION_WAIT_INVERTED,
#endif
#ifdef GL_QUERY_NO_WAIT
				GL_QUERY_NO_WAIT,
#endif
#ifdef GL_QUERY_NO_WAIT_INVERTED
				GL_QUERY_NO_WAIT_INVERTED,
#endif
#ifdef GL_QUERY_WAIT
				GL_QUERY_WAIT,
#endif
#ifdef GL_QUERY_WAIT_INVERTED
				GL_QUERY_WAIT_INVERTED,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 18: /* context_flag_bits */
		{
			static const GLbitfield vr[] = {
#ifdef GL_CONTEXT_FLAG_DEBUG_BIT
				GL_CONTEXT_FLAG_DEBUG_BIT,
#endif
#ifdef GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT
				GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT,
#endif
#ifdef GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT_ARB
				GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT_ARB,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 19: /* context_profile_bits */
		{
			static const GLbitfield vr[] = {
#ifdef GL_CONTEXT_COMPATIBILITY_PROFILE_BIT
				GL_CONTEXT_COMPATIBILITY_PROFILE_BIT,
#endif
#ifdef GL_CONTEXT_CORE_PROFILE_BIT
				GL_CONTEXT_CORE_PROFILE_BIT,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 20: /* context_release_behavior */
		{
			static const GLenum vr[] = {
#ifdef GL_CONTEXT_RELEASE_BEHAVIOR_FLUSH
				GL_CONTEXT_RELEASE_BEHAVIOR_FLUSH,
#endif
#ifdef GL_NONE
				GL_NONE,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 21: /* data_type */
		{
			static const GLenum vr[] = {
#ifdef GL_BYTE
				GL_BYTE,
#endif
#ifdef GL_DOUBLE
				GL_DOUBLE,
#endif
#ifdef GL_FIXED
				GL_FIXED,
#endif
#ifdef GL_FLOAT
				GL_FLOAT,
#endif
#ifdef GL_HALF_FLOAT
				GL_HALF_FLOAT,
#endif
#ifdef GL_INT
				GL_INT,
#endif
#ifdef GL_SHORT
				GL_SHORT,
#endif
#ifdef GL_UNSIGNED_BYTE
				GL_UNSIGNED_BYTE,
#endif
#ifdef GL_UNSIGNED_INT
				GL_UNSIGNED_INT,
#endif
#ifdef GL_UNSIGNED_SHORT
				GL_UNSIGNED_SHORT,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 22: /* debug_output_severity */
		{
			static const GLenum vr[] = {
#ifdef GL_DEBUG_SEVERITY_HIGH
				GL_DEBUG_SEVERITY_HIGH,
#endif
#ifdef GL_DEBUG_SEVERITY_LOW
				GL_DEBUG_SEVERITY_LOW,
#endif
#ifdef GL_DEBUG_SEVERITY_MEDIUM
				GL_DEBUG_SEVERITY_MEDIUM,
#endif
#ifdef GL_DEBUG_SEVERITY_NOTIFICATION
				GL_DEBUG_SEVERITY_NOTIFICATION,
#endif
#ifdef GL_DONT_CARE
				GL_DONT_CARE,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 23: /* debug_output_source */
		{
			static const GLenum vr[] = {
#ifdef GL_DEBUG_SOURCE_API
				GL_DEBUG_SOURCE_API,
#endif
#ifdef GL_DEBUG_SOURCE_APPLICATION
				GL_DEBUG_SOURCE_APPLICATION,
#endif
#ifdef GL_DEBUG_SOURCE_OTHER
				GL_DEBUG_SOURCE_OTHER,
#endif
#ifdef GL_DEBUG_SOURCE_SHADER_COMPILER
				GL_DEBUG_SOURCE_SHADER_COMPILER,
#endif
#ifdef GL_DEBUG_SOURCE_THIRD_PARTY
				GL_DEBUG_SOURCE_THIRD_PARTY,
#endif
#ifdef GL_DEBUG_SOURCE_WINDOW_SYSTEM
				GL_DEBUG_SOURCE_WINDOW_SYSTEM,
#endif
#ifdef GL_DONT_CARE
				GL_DONT_CARE,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 24: /* debug_output_type */
		{
			static const GLenum vr[] = {
#ifdef GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR
				GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR,
#endif
#ifdef GL_DEBUG_TYPE_ERROR
				GL_DEBUG_TYPE_ERROR,
#endif
#ifdef GL_DEBUG_TYPE_MARKER
				GL_DEBUG_TYPE_MARKER,
#endif
#ifdef GL_DEBUG_TYPE_OTHER
				GL_DEBUG_TYPE_OTHER,
#endif
#ifdef GL_DEBUG_TYPE_PERFORMANCE
				GL_DEBUG_TYPE_PERFORMANCE,
#endif
#ifdef GL_DEBUG_TYPE_POP_GROUP
				GL_DEBUG_TYPE_POP_GROUP,
#endif
#ifdef GL_DEBUG_TYPE_PORTABILITY
				GL_DEBUG_TYPE_PORTABILITY,
#endif
#ifdef GL_DEBUG_TYPE_PUSH_GROUP
				GL_DEBUG_TYPE_PUSH_GROUP,
#endif
#ifdef GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR
				GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR,
#endif
#ifdef GL_DONT_CARE
				GL_DONT_CARE,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 25: /* error_code */
		{
			static const GLenum vr[] = {
#ifdef GL_CONTEXT_LOST
				GL_CONTEXT_LOST,
#endif
#ifdef GL_INVALID_ENUM
				GL_INVALID_ENUM,
#endif
#ifdef GL_INVALID_FRAMEBUFFER_OPERATION
				GL_INVALID_FRAMEBUFFER_OPERATION,
#endif
#ifdef GL_INVALID_OPERATION
				GL_INVALID_OPERATION,
#endif
#ifdef GL_INVALID_VALUE
				GL_INVALID_VALUE,
#endif
#ifdef GL_NO_ERROR
				GL_NO_ERROR,
#endif
#ifdef GL_OUT_OF_MEMORY
				GL_OUT_OF_MEMORY,
#endif
#ifdef GL_STACK_OVERFLOW
				GL_STACK_OVERFLOW,
#endif
#ifdef GL_STACK_UNDERFLOW
				GL_STACK_UNDERFLOW,
#endif
#ifdef GL_TABLE_TOO_LARGE
				GL_TABLE_TOO_LARGE,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 26: /* face */
		{
			static const GLenum vr[] = {
#ifdef GL_BACK
				GL_BACK,
#endif
#ifdef GL_FRONT
				GL_FRONT,
#endif
#ifdef GL_FRONT_AND_BACK
				GL_FRONT_AND_BACK,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 27: /* face_orientation */
		{
			static const GLenum vr[] = {
#ifdef GL_CCW
				GL_CCW,
#endif
#ifdef GL_CW
				GL_CW,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 28: /* framebuffer_attachment */
		{
			static const GLenum vr[] = {
#ifdef GL_COLOR_ATTACHMENT0
				GL_COLOR_ATTACHMENT0,
#endif
#ifdef GL_COLOR_ATTACHMENT1
				GL_COLOR_ATTACHMENT1,
#endif
#ifdef GL_COLOR_ATTACHMENT10
				GL_COLOR_ATTACHMENT10,
#endif
#ifdef GL_COLOR_ATTACHMENT11
				GL_COLOR_ATTACHMENT11,
#endif
#ifdef GL_COLOR_ATTACHMENT12
				GL_COLOR_ATTACHMENT12,
#endif
#ifdef GL_COLOR_ATTACHMENT13
				GL_COLOR_ATTACHMENT13,
#endif
#ifdef GL_COLOR_ATTACHMENT14
				GL_COLOR_ATTACHMENT14,
#endif
#ifdef GL_COLOR_ATTACHMENT15
				GL_COLOR_ATTACHMENT15,
#endif
#ifdef GL_COLOR_ATTACHMENT2
				GL_COLOR_ATTACHMENT2,
#endif
#ifdef GL_COLOR_ATTACHMENT3
				GL_COLOR_ATTACHMENT3,
#endif
#ifdef GL_COLOR_ATTACHMENT4
				GL_COLOR_ATTACHMENT4,
#endif
#ifdef GL_COLOR_ATTACHMENT5
				GL_COLOR_ATTACHMENT5,
#endif
#ifdef GL_COLOR_ATTACHMENT6
				GL_COLOR_ATTACHMENT6,
#endif
#ifdef GL_COLOR_ATTACHMENT7
				GL_COLOR_ATTACHMENT7,
#endif
#ifdef GL_COLOR_ATTACHMENT8
				GL_COLOR_ATTACHMENT8,
#endif
#ifdef GL_COLOR_ATTACHMENT9
				GL_COLOR_ATTACHMENT9,
#endif
#ifdef GL_DEPTH_ATTACHMENT
				GL_DEPTH_ATTACHMENT,
#endif
#ifdef GL_DEPTH_STENCIL_ATTACHMENT
				GL_DEPTH_STENCIL_ATTACHMENT,
#endif
#ifdef GL_STENCIL_ATTACHMENT
				GL_STENCIL_ATTACHMENT,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 29: /* framebuffer_buffer */
		{
			static const GLenum vr[] = {
#ifdef GL_COLOR
				GL_COLOR,
#endif
#ifdef GL_DEPTH
				GL_DEPTH,
#endif
#ifdef GL_DEPTH_STENCIL
				GL_DEPTH_STENCIL,
#endif
#ifdef GL_STENCIL
				GL_STENCIL,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 30: /* framebuffer_status */
		{
			static const GLenum vr[] = {
#ifdef GL_FRAMEBUFFER_COMPLETE
				GL_FRAMEBUFFER_COMPLETE,
#endif
#ifdef GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT
				GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT,
#endif
#ifdef GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS
				GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS,
#endif
#ifdef GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT
				GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT,
#endif
#ifdef GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE
				GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE,
#endif
#ifdef GL_FRAMEBUFFER_UNDEFINED
				GL_FRAMEBUFFER_UNDEFINED,
#endif
#ifdef GL_FRAMEBUFFER_UNSUPPORTED
				GL_FRAMEBUFFER_UNSUPPORTED,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 31: /* framebuffer_target */
		{
			static const GLenum vr[] = {
#ifdef GL_DRAW_FRAMEBUFFER
				GL_DRAW_FRAMEBUFFER,
#endif
#ifdef GL_READ_FRAMEBUFFER
				GL_READ_FRAMEBUFFER,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 32: /* functionality */
		{
			static const GLenum vr[] = {
#ifdef GL_CLIP_DISTANCE0
				GL_CLIP_DISTANCE0,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 33: /* graphics_reset_status */
		{
			static const GLenum vr[] = {
#ifdef GL_GUILTY_CONTEXT_RESET
				GL_GUILTY_CONTEXT_RESET,
#endif
#ifdef GL_INNOCENT_CONTEXT_RESET
				GL_INNOCENT_CONTEXT_RESET,
#endif
#ifdef GL_NO_ERROR
				GL_NO_ERROR,
#endif
#ifdef GL_UNKNOWN_CONTEXT_RESET
				GL_UNKNOWN_CONTEXT_RESET,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 34: /* hint_option */
		{
			static const GLenum vr[] = {
#ifdef GL_DONT_CARE
				GL_DONT_CARE,
#endif
#ifdef GL_FASTEST
				GL_FASTEST,
#endif
#ifdef GL_NICEST
				GL_NICEST,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 35: /* hint_target */
		{
			static const GLenum vr[] = {
#ifdef GL_FRAGMENT_SHADER_DERIVATIVE_HINT
				GL_FRAGMENT_SHADER_DERIVATIVE_HINT,
#endif
#ifdef GL_LINE_SMOOTH_HINT
				GL_LINE_SMOOTH_HINT,
#endif
#ifdef GL_POLYGON_SMOOTH_HINT
				GL_POLYGON_SMOOTH_HINT,
#endif
#ifdef GL_TEXTURE_COMPRESSION_HINT
				GL_TEXTURE_COMPRESSION_HINT,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 36: /* image_unit_format */
		{
			static const GLenum vr[] = {
#ifdef GL_R11F_G11F_B10F
				GL_R11F_G11F_B10F,
#endif
#ifdef GL_R16
				GL_R16,
#endif
#ifdef GL_R16F
				GL_R16F,
#endif
#ifdef GL_R16I
				GL_R16I,
#endif
#ifdef GL_R16UI
				GL_R16UI,
#endif
#ifdef GL_R16_SNORM
				GL_R16_SNORM,
#endif
#ifdef GL_R32F
				GL_R32F,
#endif
#ifdef GL_R32I
				GL_R32I,
#endif
#ifdef GL_R32UI
				GL_R32UI,
#endif
#ifdef GL_R8
				GL_R8,
#endif
#ifdef GL_R8I
				GL_R8I,
#endif
#ifdef GL_R8UI
				GL_R8UI,
#endif
#ifdef GL_R8_SNORM
				GL_R8_SNORM,
#endif
#ifdef GL_RG16
				GL_RG16,
#endif
#ifdef GL_RG16F
				GL_RG16F,
#endif
#ifdef GL_RG16I
				GL_RG16I,
#endif
#ifdef GL_RG16UI
				GL_RG16UI,
#endif
#ifdef GL_RG16_SNORM
				GL_RG16_SNORM,
#endif
#ifdef GL_RG32F
				GL_RG32F,
#endif
#ifdef GL_RG32I
				GL_RG32I,
#endif
#ifdef GL_RG32UI
				GL_RG32UI,
#endif
#ifdef GL_RG8
				GL_RG8,
#endif
#ifdef GL_RG8I
				GL_RG8I,
#endif
#ifdef GL_RG8UI
				GL_RG8UI,
#endif
#ifdef GL_RG8_SNORM
				GL_RG8_SNORM,
#endif
#ifdef GL_RGB10_A2
				GL_RGB10_A2,
#endif
#ifdef GL_RGB10_A2UI
				GL_RGB10_A2UI,
#endif
#ifdef GL_RGBA16
				GL_RGBA16,
#endif
#ifdef GL_RGBA16F
				GL_RGBA16F,
#endif
#ifdef GL_RGBA16I
				GL_RGBA16I,
#endif
#ifdef GL_RGBA16UI
				GL_RGBA16UI,
#endif
#ifdef GL_RGBA16_SNORM
				GL_RGBA16_SNORM,
#endif
#ifdef GL_RGBA32F
				GL_RGBA32F,
#endif
#ifdef GL_RGBA32I
				GL_RGBA32I,
#endif
#ifdef GL_RGBA32UI
				GL_RGBA32UI,
#endif
#ifdef GL_RGBA8
				GL_RGBA8,
#endif
#ifdef GL_RGBA8I
				GL_RGBA8I,
#endif
#ifdef GL_RGBA8UI
				GL_RGBA8UI,
#endif
#ifdef GL_RGBA8_SNORM
				GL_RGBA8_SNORM,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 37: /* limit_query */
		{
			static const GLenum vr[] = {
#ifdef GL_MAX_3D_TEXTURE_SIZE
				GL_MAX_3D_TEXTURE_SIZE,
#endif
#ifdef GL_MAX_ARRAY_TEXTURE_LAYERS
				GL_MAX_ARRAY_TEXTURE_LAYERS,
#endif
#ifdef GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS
				GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS,
#endif
#ifdef GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE
				GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE,
#endif
#ifdef GL_MAX_CLIP_DISTANCES
				GL_MAX_CLIP_DISTANCES,
#endif
#ifdef GL_MAX_COLOR_ATTACHMENTS
				GL_MAX_COLOR_ATTACHMENTS,
#endif
#ifdef GL_MAX_COLOR_TEXTURE_SAMPLES
				GL_MAX_COLOR_TEXTURE_SAMPLES,
#endif
#ifdef GL_MAX_COMBINED_ATOMIC_COUNTERS
				GL_MAX_COMBINED_ATOMIC_COUNTERS,
#endif
#ifdef GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS
				GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS,
#endif
#ifdef GL_MAX_COMBINED_CLIP_AND_CULL_DISTANCES
				GL_MAX_COMBINED_CLIP_AND_CULL_DISTANCES,
#endif
#ifdef GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS
				GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS,
#endif
#ifdef GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS
				GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS,
#endif
#ifdef GL_MAX_COMBINED_IMAGE_UNIFORMS
				GL_MAX_COMBINED_IMAGE_UNIFORMS,
#endif
#ifdef GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS
				GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS,
#endif
#ifdef GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS
				GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS,
#endif
#ifdef GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS
				GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS,
#endif
#ifdef GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS
				GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS,
#endif
#ifdef GL_MAX_COMBINED_UNIFORM_BLOCKS
				GL_MAX_COMBINED_UNIFORM_BLOCKS,
#endif
#ifdef GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS
				GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS,
#endif
#ifdef GL_MAX_COMPUTE_SHARED_MEMORY_SIZE
				GL_MAX_COMPUTE_SHARED_MEMORY_SIZE,
#endif
#ifdef GL_MAX_COMPUTE_WORK_GROUP_COUNT
				GL_MAX_COMPUTE_WORK_GROUP_COUNT,
#endif
#ifdef GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS
				GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS,
#endif
#ifdef GL_MAX_COMPUTE_WORK_GROUP_SIZE
				GL_MAX_COMPUTE_WORK_GROUP_SIZE,
#endif
#ifdef GL_MAX_CUBE_MAP_TEXTURE_SIZE
				GL_MAX_CUBE_MAP_TEXTURE_SIZE,
#endif
#ifdef GL_MAX_CULL_DISTANCES
				GL_MAX_CULL_DISTANCES,
#endif
#ifdef GL_MAX_DEPTH_TEXTURE_SAMPLES
				GL_MAX_DEPTH_TEXTURE_SAMPLES,
#endif
#ifdef GL_MAX_DRAW_BUFFERS
				GL_MAX_DRAW_BUFFERS,
#endif
#ifdef GL_MAX_DUAL_SOURCE_DRAW_BUFFERS
				GL_MAX_DUAL_SOURCE_DRAW_BUFFERS,
#endif
#ifdef GL_MAX_ELEMENTS_INDICES
				GL_MAX_ELEMENTS_INDICES,
#endif
#ifdef GL_MAX_ELEMENTS_VERTICES
				GL_MAX_ELEMENTS_VERTICES,
#endif
#ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTERS
				GL_MAX_FRAGMENT_ATOMIC_COUNTERS,
#endif
#ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS
				GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS,
#endif
#ifdef GL_MAX_FRAGMENT_IMAGE_UNIFORMS
				GL_MAX_FRAGMENT_IMAGE_UNIFORMS,
#endif
#ifdef GL_MAX_FRAGMENT_INPUT_COMPONENTS
				GL_MAX_FRAGMENT_INPUT_COMPONENTS,
#endif
#ifdef GL_MAX_FRAGMENT_INTERPOLATION_OFFSET
				GL_MAX_FRAGMENT_INTERPOLATION_OFFSET,
#endif
#ifdef GL_MAX_FRAGMENT_UNIFORM_BLOCKS
				GL_MAX_FRAGMENT_UNIFORM_BLOCKS,
#endif
#ifdef GL_MAX_FRAGMENT_UNIFORM_COMPONENTS
				GL_MAX_FRAGMENT_UNIFORM_COMPONENTS,
#endif
#ifdef GL_MAX_FRAGMENT_UNIFORM_VECTORS
				GL_MAX_FRAGMENT_UNIFORM_VECTORS,
#endif
#ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTERS
				GL_MAX_GEOMETRY_ATOMIC_COUNTERS,
#endif
#ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS
				GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS,
#endif
#ifdef GL_MAX_GEOMETRY_IMAGE_UNIFORMS
				GL_MAX_GEOMETRY_IMAGE_UNIFORMS,
#endif
#ifdef GL_MAX_GEOMETRY_INPUT_COMPONENTS
				GL_MAX_GEOMETRY_INPUT_COMPONENTS,
#endif
#ifdef GL_MAX_GEOMETRY_OUTPUT_COMPONENTS
				GL_MAX_GEOMETRY_OUTPUT_COMPONENTS,
#endif
#ifdef GL_MAX_GEOMETRY_OUTPUT_VERTICES
				GL_MAX_GEOMETRY_OUTPUT_VERTICES,
#endif
#ifdef GL_MAX_GEOMETRY_SHADER_INVOCATIONS
				GL_MAX_GEOMETRY_SHADER_INVOCATIONS,
#endif
#ifdef GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS
				GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS,
#endif
#ifdef GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS
				GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS,
#endif
#ifdef GL_MAX_GEOMETRY_UNIFORM_BLOCKS
				GL_MAX_GEOMETRY_UNIFORM_BLOCKS,
#endif
#ifdef GL_MAX_GEOMETRY_UNIFORM_COMPONENTS
				GL_MAX_GEOMETRY_UNIFORM_COMPONENTS,
#endif
#ifdef GL_MAX_IMAGE_SAMPLES
				GL_MAX_IMAGE_SAMPLES,
#endif
#ifdef GL_MAX_IMAGE_UNITS
				GL_MAX_IMAGE_UNITS,
#endif
#ifdef GL_MAX_INTEGER_SAMPLES
				GL_MAX_INTEGER_SAMPLES,
#endif
#ifdef GL_MAX_PATCH_VERTICES
				GL_MAX_PATCH_VERTICES,
#endif
#ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
				GL_MAX_PROGRAM_TEXEL_OFFSET,
#endif
#ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
				GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET,
#endif
#ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
				GL_MAX_RECTANGLE_TEXTURE_SIZE,
#endif
#ifdef GL_MAX_RENDERBUFFER_SIZE
				GL_MAX_RENDERBUFFER_SIZE,
#endif
#ifdef GL_MAX_SAMPLES
				GL_MAX_SAMPLES,
#endif
#ifdef GL_MAX_SAMPLE_MASK_WORDS
				GL_MAX_SAMPLE_MASK_WORDS,
#endif
#ifdef GL_MAX_SERVER_WAIT_TIMEOUT
				GL_MAX_SERVER_WAIT_TIMEOUT,
#endif
#ifdef GL_MAX_SUBROUTINES
				GL_MAX_SUBROUTINES,
#endif
#ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
				GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS,
#endif
#ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
				GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS,
#endif
#ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
				GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS,
#endif
#ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
				GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS,
#endif
#ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
				GL_MAX_TESS_CONTROL_INPUT_COMPONENTS,
#endif
#ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
				GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS,
#endif
#ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
				GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS,
#endif
#ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
				GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS,
#endif
#ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
				GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS,
#endif
#ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
				GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS,
#endif
#ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
				GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS,
#endif
#ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
				GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS,
#endif
#ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
				GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS,
#endif
#ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
				GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS,
#endif
#ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
				GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS,
#endif
#ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
				GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS,
#endif
#ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
				GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS,
#endif
#ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
				GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS,
#endif
#ifdef GL_MAX_TESS_GEN_LEVEL
				GL_MAX_TESS_GEN_LEVEL,
#endif
#ifdef GL_MAX_TESS_PATCH_COMPONENTS
				GL_MAX_TESS_PATCH_COMPONENTS,
#endif
#ifdef GL_MAX_TEXTURE_BUFFER_SIZE
				GL_MAX_TEXTURE_BUFFER_SIZE,
#endif
#ifdef GL_MAX_TEXTURE_IMAGE_UNITS
				GL_MAX_TEXTURE_IMAGE_UNITS,
#endif
#ifdef GL_MAX_TEXTURE_LOD_BIAS
				GL_MAX_TEXTURE_LOD_BIAS,
#endif
#ifdef GL_MAX_TEXTURE_SIZE
				GL_MAX_TEXTURE_SIZE,
#endif
#ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
				GL_MAX_TRANSFORM_FEEDBACK_BUFFERS,
#endif
#ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
				GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS,
#endif
#ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
				GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS,
#endif
#ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
				GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS,
#endif
#ifdef GL_MAX_UNIFORM_BLOCK_SIZE
				GL_MAX_UNIFORM_BLOCK_SIZE,
#endif
#ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
				GL_MAX_UNIFORM_BUFFER_BINDINGS,
#endif
#ifdef GL_MAX_VARYING_COMPONENTS
				GL_MAX_VARYING_COMPONENTS,
#endif
#ifdef GL_MAX_VARYING_VECTORS
				GL_MAX_VARYING_VECTORS,
#endif
#ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
				GL_MAX_VERTEX_ATOMIC_COUNTERS,
#endif
#ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
				GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS,
#endif
#ifdef GL_MAX_VERTEX_ATTRIBS
				GL_MAX_VERTEX_ATTRIBS,
#endif
#ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
				GL_MAX_VERTEX_IMAGE_UNIFORMS,
#endif
#ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
				GL_MAX_VERTEX_OUTPUT_COMPONENTS,
#endif
#ifdef GL_MAX_VERTEX_STREAMS
				GL_MAX_VERTEX_STREAMS,
#endif
#ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
				GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS,
#endif
#ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
				GL_MAX_VERTEX_UNIFORM_BLOCKS,
#endif
#ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
				GL_MAX_VERTEX_UNIFORM_COMPONENTS,
#endif
#ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
				GL_MAX_VERTEX_UNIFORM_VECTORS,
#endif
#ifdef GL_MAX_VIEWPORTS
				GL_MAX_VIEWPORTS,
#endif
#ifdef GL_MAX_VIEWPORT_DIMS
				GL_MAX_VIEWPORT_DIMS,
#endif
#ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
				GL_MIN_FRAGMENT_INTERPOLATION_OFFSET,
#endif
#ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
				GL_MIN_MAP_BUFFER_ALIGNMENT,
#endif
#ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
				GL_MIN_PROGRAM_TEXEL_OFFSET,
#endif
#ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
				GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 38: /* memory_barrier_bits */
		{
			static const GLbitfield vr[] = {
#ifdef GL_ALL_BARRIER_BITS
				GL_ALL_BARRIER_BITS,
#endif
#ifdef GL_ATOMIC_COUNTER_BARRIER_BIT
				GL_ATOMIC_COUNTER_BARRIER_BIT,
#endif
#ifdef GL_BUFFER_UPDATE_BARRIER_BIT
				GL_BUFFER_UPDATE_BARRIER_BIT,
#endif
#ifdef GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT
				GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT,
#endif
#ifdef GL_COMMAND_BARRIER_BIT
				GL_COMMAND_BARRIER_BIT,
#endif
#ifdef GL_ELEMENT_ARRAY_BARRIER_BIT
				GL_ELEMENT_ARRAY_BARRIER_BIT,
#endif
#ifdef GL_FRAMEBUFFER_BARRIER_BIT
				GL_FRAMEBUFFER_BARRIER_BIT,
#endif
#ifdef GL_PIXEL_BUFFER_BARRIER_BIT
				GL_PIXEL_BUFFER_BARRIER_BIT,
#endif
#ifdef GL_SHADER_IMAGE_ACCESS_BARRIER_BIT
				GL_SHADER_IMAGE_ACCESS_BARRIER_BIT,
#endif
#ifdef GL_SHADER_STORAGE_BARRIER_BIT
				GL_SHADER_STORAGE_BARRIER_BIT,
#endif
#ifdef GL_TEXTURE_FETCH_BARRIER_BIT
				GL_TEXTURE_FETCH_BARRIER_BIT,
#endif
#ifdef GL_TEXTURE_UPDATE_BARRIER_BIT
				GL_TEXTURE_UPDATE_BARRIER_BIT,
#endif
#ifdef GL_TRANSFORM_FEEDBACK_BARRIER_BIT
				GL_TRANSFORM_FEEDBACK_BARRIER_BIT,
#endif
#ifdef GL_UNIFORM_BARRIER_BIT
				GL_UNIFORM_BARRIER_BIT,
#endif
#ifdef GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT
				GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 39: /* named_string_type */
		{
			static const GLenum vr[] = {
#ifdef GL_SHADER_INCLUDE_ARB
				GL_SHADER_INCLUDE_ARB,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 40: /* object_type */
		{
			static const GLenum vr[] = {
#ifdef GL_BUFFER
				GL_BUFFER,
#endif
#ifdef GL_FRAMEBUFFER
				GL_FRAMEBUFFER,
#endif
#ifdef GL_NONE
				GL_NONE,
#endif
#ifdef GL_PROGRAM
				GL_PROGRAM,
#endif
#ifdef GL_PROGRAM_PIPELINE
				GL_PROGRAM_PIPELINE,
#endif
#ifdef GL_QUERY
				GL_QUERY,
#endif
#ifdef GL_RENDERBUFFER
				GL_RENDERBUFFER,
#endif
#ifdef GL_SAMPLER
				GL_SAMPLER,
#endif
#ifdef GL_SHADER
				GL_SHADER,
#endif
#ifdef GL_TEXTURE
				GL_TEXTURE,
#endif
#ifdef GL_TRANSFORM_FEEDBACK
				GL_TRANSFORM_FEEDBACK,
#endif
#ifdef GL_VERTEX_ARRAY
				GL_VERTEX_ARRAY,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 41: /* patch_parameter */
		{
			static const GLenum vr[] = {
#ifdef GL_PATCH_DEFAULT_INNER_LEVEL
				GL_PATCH_DEFAULT_INNER_LEVEL,
#endif
#ifdef GL_PATCH_DEFAULT_OUTER_LEVEL
				GL_PATCH_DEFAULT_OUTER_LEVEL,
#endif
#ifdef GL_PATCH_VERTICES
				GL_PATCH_VERTICES,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 42: /* pixel_data_format */
		{
			static const GLenum vr[] = {
#ifdef GL_BGR
				GL_BGR,
#endif
#ifdef GL_BGRA
				GL_BGRA,
#endif
#ifdef GL_BGRA_INTEGER
				GL_BGRA_INTEGER,
#endif
#ifdef GL_BGR_INTEGER
				GL_BGR_INTEGER,
#endif
#ifdef GL_BLUE
				GL_BLUE,
#endif
#ifdef GL_BLUE_INTEGER
				GL_BLUE_INTEGER,
#endif
#ifdef GL_DEPTH_COMPONENT
				GL_DEPTH_COMPONENT,
#endif
#ifdef GL_DEPTH_STENCIL
				GL_DEPTH_STENCIL,
#endif
#ifdef GL_GREEN
				GL_GREEN,
#endif
#ifdef GL_GREEN_INTEGER
				GL_GREEN_INTEGER,
#endif
#ifdef GL_RED
				GL_RED,
#endif
#ifdef GL_RED_INTEGER
				GL_RED_INTEGER,
#endif
#ifdef GL_RG
				GL_RG,
#endif
#ifdef GL_RGB
				GL_RGB,
#endif
#ifdef GL_RGBA
				GL_RGBA,
#endif
#ifdef GL_RGBA_INTEGER
				GL_RGBA_INTEGER,
#endif
#ifdef GL_RGB_INTEGER
				GL_RGB_INTEGER,
#endif
#ifdef GL_RG_INTEGER
				GL_RG_INTEGER,
#endif
#ifdef GL_STENCIL_INDEX
				GL_STENCIL_INDEX,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 43: /* pixel_data_internal_format */
		{
			static const GLenum vr[] = {
#ifdef GL_COMPRESSED_R11_EAC
				GL_COMPRESSED_R11_EAC,
#endif
#ifdef GL_COMPRESSED_RED
				GL_COMPRESSED_RED,
#endif
#ifdef GL_COMPRESSED_RED_RGTC1
				GL_COMPRESSED_RED_RGTC1,
#endif
#ifdef GL_COMPRESSED_RG
				GL_COMPRESSED_RG,
#endif
#ifdef GL_COMPRESSED_RG11_EAC
				GL_COMPRESSED_RG11_EAC,
#endif
#ifdef GL_COMPRESSED_RGB
				GL_COMPRESSED_RGB,
#endif
#ifdef GL_COMPRESSED_RGB8_ETC2
				GL_COMPRESSED_RGB8_ETC2,
#endif
#ifdef GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2
				GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2,
#endif
#ifdef GL_COMPRESSED_RGBA
				GL_COMPRESSED_RGBA,
#endif
#ifdef GL_COMPRESSED_RGBA8_ETC2_EAC
				GL_COMPRESSED_RGBA8_ETC2_EAC,
#endif
#ifdef GL_COMPRESSED_RGBA_BPTC_UNORM
				GL_COMPRESSED_RGBA_BPTC_UNORM,
#endif
#ifdef GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT
				GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT,
#endif
#ifdef GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT
				GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT,
#endif
#ifdef GL_COMPRESSED_RG_RGTC2
				GL_COMPRESSED_RG_RGTC2,
#endif
#ifdef GL_COMPRESSED_SIGNED_R11_EAC
				GL_COMPRESSED_SIGNED_R11_EAC,
#endif
#ifdef GL_COMPRESSED_SIGNED_RED_RGTC1
				GL_COMPRESSED_SIGNED_RED_RGTC1,
#endif
#ifdef GL_COMPRESSED_SIGNED_RG11_EAC
				GL_COMPRESSED_SIGNED_RG11_EAC,
#endif
#ifdef GL_COMPRESSED_SIGNED_RG_RGTC2
				GL_COMPRESSED_SIGNED_RG_RGTC2,
#endif
#ifdef GL_COMPRESSED_SRGB
				GL_COMPRESSED_SRGB,
#endif
#ifdef GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC
				GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC,
#endif
#ifdef GL_COMPRESSED_SRGB8_ETC2
				GL_COMPRESSED_SRGB8_ETC2,
#endif
#ifdef GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2
				GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2,
#endif
#ifdef GL_COMPRESSED_SRGB_ALPHA
				GL_COMPRESSED_SRGB_ALPHA,
#endif
#ifdef GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM
				GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM,
#endif
#ifdef GL_DEPTH24_STENCIL8
				GL_DEPTH24_STENCIL8,
#endif
#ifdef GL_DEPTH32F_STENCIL8
				GL_DEPTH32F_STENCIL8,
#endif
#ifdef GL_DEPTH_COMPONENT
				GL_DEPTH_COMPONENT,
#endif
#ifdef GL_DEPTH_COMPONENT16
				GL_DEPTH_COMPONENT16,
#endif
#ifdef GL_DEPTH_COMPONENT24
				GL_DEPTH_COMPONENT24,
#endif
#ifdef GL_DEPTH_COMPONENT32
				GL_DEPTH_COMPONENT32,
#endif
#ifdef GL_DEPTH_COMPONENT32F
				GL_DEPTH_COMPONENT32F,
#endif
#ifdef GL_DEPTH_STENCIL
				GL_DEPTH_STENCIL,
#endif
#ifdef GL_R11F_G11F_B10F
				GL_R11F_G11F_B10F,
#endif
#ifdef GL_R16
				GL_R16,
#endif
#ifdef GL_R16F
				GL_R16F,
#endif
#ifdef GL_R16I
				GL_R16I,
#endif
#ifdef GL_R16UI
				GL_R16UI,
#endif
#ifdef GL_R16_SNORM
				GL_R16_SNORM,
#endif
#ifdef GL_R32F
				GL_R32F,
#endif
#ifdef GL_R32I
				GL_R32I,
#endif
#ifdef GL_R32UI
				GL_R32UI,
#endif
#ifdef GL_R3_G3_B2
				GL_R3_G3_B2,
#endif
#ifdef GL_R8
				GL_R8,
#endif
#ifdef GL_R8I
				GL_R8I,
#endif
#ifdef GL_R8UI
				GL_R8UI,
#endif
#ifdef GL_R8_SNORM
				GL_R8_SNORM,
#endif
#ifdef GL_RED
				GL_RED,
#endif
#ifdef GL_RG
				GL_RG,
#endif
#ifdef GL_RG16
				GL_RG16,
#endif
#ifdef GL_RG16F
				GL_RG16F,
#endif
#ifdef GL_RG16I
				GL_RG16I,
#endif
#ifdef GL_RG16UI
				GL_RG16UI,
#endif
#ifdef GL_RG16_SNORM
				GL_RG16_SNORM,
#endif
#ifdef GL_RG32F
				GL_RG32F,
#endif
#ifdef GL_RG32I
				GL_RG32I,
#endif
#ifdef GL_RG32UI
				GL_RG32UI,
#endif
#ifdef GL_RG8
				GL_RG8,
#endif
#ifdef GL_RG8I
				GL_RG8I,
#endif
#ifdef GL_RG8UI
				GL_RG8UI,
#endif
#ifdef GL_RG8_SNORM
				GL_RG8_SNORM,
#endif
#ifdef GL_RGB
				GL_RGB,
#endif
#ifdef GL_RGB10
				GL_RGB10,
#endif
#ifdef GL_RGB10_A2
				GL_RGB10_A2,
#endif
#ifdef GL_RGB10_A2UI
				GL_RGB10_A2UI,
#endif
#ifdef GL_RGB12
				GL_RGB12,
#endif
#ifdef GL_RGB16
				GL_RGB16,
#endif
#ifdef GL_RGB16F
				GL_RGB16F,
#endif
#ifdef GL_RGB16I
				GL_RGB16I,
#endif
#ifdef GL_RGB16UI
				GL_RGB16UI,
#endif
#ifdef GL_RGB16_SNORM
				GL_RGB16_SNORM,
#endif
#ifdef GL_RGB32F
				GL_RGB32F,
#endif
#ifdef GL_RGB32I
				GL_RGB32I,
#endif
#ifdef GL_RGB32UI
				GL_RGB32UI,
#endif
#ifdef GL_RGB4
				GL_RGB4,
#endif
#ifdef GL_RGB5
				GL_RGB5,
#endif
#ifdef GL_RGB5_A1
				GL_RGB5_A1,
#endif
#ifdef GL_RGB8
				GL_RGB8,
#endif
#ifdef GL_RGB8I
				GL_RGB8I,
#endif
#ifdef GL_RGB8UI
				GL_RGB8UI,
#endif
#ifdef GL_RGB8_SNORM
				GL_RGB8_SNORM,
#endif
#ifdef GL_RGB9_E5
				GL_RGB9_E5,
#endif
#ifdef GL_RGBA
				GL_RGBA,
#endif
#ifdef GL_RGBA12
				GL_RGBA12,
#endif
#ifdef GL_RGBA16
				GL_RGBA16,
#endif
#ifdef GL_RGBA16F
				GL_RGBA16F,
#endif
#ifdef GL_RGBA16I
				GL_RGBA16I,
#endif
#ifdef GL_RGBA16UI
				GL_RGBA16UI,
#endif
#ifdef GL_RGBA16_SNORM
				GL_RGBA16_SNORM,
#endif
#ifdef GL_RGBA2
				GL_RGBA2,
#endif
#ifdef GL_RGBA32F
				GL_RGBA32F,
#endif
#ifdef GL_RGBA32I
				GL_RGBA32I,
#endif
#ifdef GL_RGBA32UI
				GL_RGBA32UI,
#endif
#ifdef GL_RGBA4
				GL_RGBA4,
#endif
#ifdef GL_RGBA8
				GL_RGBA8,
#endif
#ifdef GL_RGBA8I
				GL_RGBA8I,
#endif
#ifdef GL_RGBA8UI
				GL_RGBA8UI,
#endif
#ifdef GL_RGBA8_SNORM
				GL_RGBA8_SNORM,
#endif
#ifdef GL_SRGB8
				GL_SRGB8,
#endif
#ifdef GL_SRGB8_ALPHA8
				GL_SRGB8_ALPHA8,
#endif
#ifdef GL_STENCIL_INDEX8
				GL_STENCIL_INDEX8,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 44: /* pixel_data_type */
		{
			static const GLenum vr[] = {
#ifdef GL_BYTE
				GL_BYTE,
#endif
#ifdef GL_FLOAT
				GL_FLOAT,
#endif
#ifdef GL_FLOAT_32_UNSIGNED_INT_24_8_REV
				GL_FLOAT_32_UNSIGNED_INT_24_8_REV,
#endif
#ifdef GL_HALF_FLOAT
				GL_HALF_FLOAT,
#endif
#ifdef GL_INT
				GL_INT,
#endif
#ifdef GL_SHORT
				GL_SHORT,
#endif
#ifdef GL_UNSIGNED_BYTE
				GL_UNSIGNED_BYTE,
#endif
#ifdef GL_UNSIGNED_BYTE_2_3_3_REV
				GL_UNSIGNED_BYTE_2_3_3_REV,
#endif
#ifdef GL_UNSIGNED_BYTE_3_3_2
				GL_UNSIGNED_BYTE_3_3_2,
#endif
#ifdef GL_UNSIGNED_INT
				GL_UNSIGNED_INT,
#endif
#ifdef GL_UNSIGNED_INT_10F_11F_11F_REV
				GL_UNSIGNED_INT_10F_11F_11F_REV,
#endif
#ifdef GL_UNSIGNED_INT_10_10_10_2
				GL_UNSIGNED_INT_10_10_10_2,
#endif
#ifdef GL_UNSIGNED_INT_24_8
				GL_UNSIGNED_INT_24_8,
#endif
#ifdef GL_UNSIGNED_INT_2_10_10_10_REV
				GL_UNSIGNED_INT_2_10_10_10_REV,
#endif
#ifdef GL_UNSIGNED_INT_5_9_9_9_REV
				GL_UNSIGNED_INT_5_9_9_9_REV,
#endif
#ifdef GL_UNSIGNED_INT_8_8_8_8
				GL_UNSIGNED_INT_8_8_8_8,
#endif
#ifdef GL_UNSIGNED_INT_8_8_8_8_REV
				GL_UNSIGNED_INT_8_8_8_8_REV,
#endif
#ifdef GL_UNSIGNED_SHORT
				GL_UNSIGNED_SHORT,
#endif
#ifdef GL_UNSIGNED_SHORT_1_5_5_5_REV
				GL_UNSIGNED_SHORT_1_5_5_5_REV,
#endif
#ifdef GL_UNSIGNED_SHORT_4_4_4_4
				GL_UNSIGNED_SHORT_4_4_4_4,
#endif
#ifdef GL_UNSIGNED_SHORT_4_4_4_4_REV
				GL_UNSIGNED_SHORT_4_4_4_4_REV,
#endif
#ifdef GL_UNSIGNED_SHORT_5_5_5_1
				GL_UNSIGNED_SHORT_5_5_5_1,
#endif
#ifdef GL_UNSIGNED_SHORT_5_6_5
				GL_UNSIGNED_SHORT_5_6_5,
#endif
#ifdef GL_UNSIGNED_SHORT_5_6_5_REV
				GL_UNSIGNED_SHORT_5_6_5_REV,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 45: /* pixel_parameter */
		{
			static const GLenum vr[] = {
#ifdef GL_PACK_ALIGNMENT
				GL_PACK_ALIGNMENT,
#endif
#ifdef GL_PACK_COMPRESSED_BLOCK_DEPTH
				GL_PACK_COMPRESSED_BLOCK_DEPTH,
#endif
#ifdef GL_PACK_COMPRESSED_BLOCK_HEIGHT
				GL_PACK_COMPRESSED_BLOCK_HEIGHT,
#endif
#ifdef GL_PACK_COMPRESSED_BLOCK_SIZE
				GL_PACK_COMPRESSED_BLOCK_SIZE,
#endif
#ifdef GL_PACK_COMPRESSED_BLOCK_WIDTH
				GL_PACK_COMPRESSED_BLOCK_WIDTH,
#endif
#ifdef GL_PACK_IMAGE_HEIGHT
				GL_PACK_IMAGE_HEIGHT,
#endif
#ifdef GL_PACK_LSB_FIRST
				GL_PACK_LSB_FIRST,
#endif
#ifdef GL_PACK_ROW_LENGTH
				GL_PACK_ROW_LENGTH,
#endif
#ifdef GL_PACK_SKIP_IMAGES
				GL_PACK_SKIP_IMAGES,
#endif
#ifdef GL_PACK_SKIP_PIXELS
				GL_PACK_SKIP_PIXELS,
#endif
#ifdef GL_PACK_SKIP_ROWS
				GL_PACK_SKIP_ROWS,
#endif
#ifdef GL_PACK_SWAP_BYTES
				GL_PACK_SWAP_BYTES,
#endif
#ifdef GL_UNPACK_ALIGNMENT
				GL_UNPACK_ALIGNMENT,
#endif
#ifdef GL_UNPACK_COMPRESSED_BLOCK_DEPTH
				GL_UNPACK_COMPRESSED_BLOCK_DEPTH,
#endif
#ifdef GL_UNPACK_COMPRESSED_BLOCK_HEIGHT
				GL_UNPACK_COMPRESSED_BLOCK_HEIGHT,
#endif
#ifdef GL_UNPACK_COMPRESSED_BLOCK_SIZE
				GL_UNPACK_COMPRESSED_BLOCK_SIZE,
#endif
#ifdef GL_UNPACK_COMPRESSED_BLOCK_WIDTH
				GL_UNPACK_COMPRESSED_BLOCK_WIDTH,
#endif
#ifdef GL_UNPACK_IMAGE_HEIGHT
				GL_UNPACK_IMAGE_HEIGHT,
#endif
#ifdef GL_UNPACK_LSB_FIRST
				GL_UNPACK_LSB_FIRST,
#endif
#ifdef GL_UNPACK_ROW_LENGTH
				GL_UNPACK_ROW_LENGTH,
#endif
#ifdef GL_UNPACK_SKIP_IMAGES
				GL_UNPACK_SKIP_IMAGES,
#endif
#ifdef GL_UNPACK_SKIP_PIXELS
				GL_UNPACK_SKIP_PIXELS,
#endif
#ifdef GL_UNPACK_SKIP_ROWS
				GL_UNPACK_SKIP_ROWS,
#endif
#ifdef GL_UNPACK_SWAP_BYTES
				GL_UNPACK_SWAP_BYTES,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 46: /* polygon_mode */
		{
			static const GLenum vr[] = {
#ifdef GL_FILL
				GL_FILL,
#endif
#ifdef GL_FILL_RECTANGLE_NV
				GL_FILL_RECTANGLE_NV,
#endif
#ifdef GL_LINE
				GL_LINE,
#endif
#ifdef GL_POINT
				GL_POINT,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 47: /* precision_type */
		{
			static const GLenum vr[] = {
#ifdef GL_HIGH_FLOAT
				GL_HIGH_FLOAT,
#endif
#ifdef GL_HIGH_INT
				GL_HIGH_INT,
#endif
#ifdef GL_LOW_FLOAT
				GL_LOW_FLOAT,
#endif
#ifdef GL_LOW_INT
				GL_LOW_INT,
#endif
#ifdef GL_MEDIUM_FLOAT
				GL_MEDIUM_FLOAT,
#endif
#ifdef GL_MEDIUM_INT
				GL_MEDIUM_INT,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 48: /* primitive_type */
		{
			static const GLenum vr[] = {
#ifdef GL_LINES
				GL_LINES,
#endif
#ifdef GL_LINES_ADJACENCY
				GL_LINES_ADJACENCY,
#endif
#ifdef GL_LINE_LOOP
				GL_LINE_LOOP,
#endif
#ifdef GL_LINE_STRIP
				GL_LINE_STRIP,
#endif
#ifdef GL_LINE_STRIP_ADJACENCY
				GL_LINE_STRIP_ADJACENCY,
#endif
#ifdef GL_PATCHES
				GL_PATCHES,
#endif
#ifdef GL_POINTS
				GL_POINTS,
#endif
#ifdef GL_TRIANGLES
				GL_TRIANGLES,
#endif
#ifdef GL_TRIANGLES_ADJACENCY
				GL_TRIANGLES_ADJACENCY,
#endif
#ifdef GL_TRIANGLE_FAN
				GL_TRIANGLE_FAN,
#endif
#ifdef GL_TRIANGLE_STRIP
				GL_TRIANGLE_STRIP,
#endif
#ifdef GL_TRIANGLE_STRIP_ADJACENCY
				GL_TRIANGLE_STRIP_ADJACENCY,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 49: /* program_interface */
		{
			static const GLenum vr[] = {
#ifdef GL_ATOMIC_COUNTER_BUFFER
				GL_ATOMIC_COUNTER_BUFFER,
#endif
#ifdef GL_BUFFER_VARIABLE
				GL_BUFFER_VARIABLE,
#endif
#ifdef GL_COMPUTE_SUBROUTINE
				GL_COMPUTE_SUBROUTINE,
#endif
#ifdef GL_COMPUTE_SUBROUTINE_UNIFORM
				GL_COMPUTE_SUBROUTINE_UNIFORM,
#endif
#ifdef GL_FRAGMENT_SUBROUTINE
				GL_FRAGMENT_SUBROUTINE,
#endif
#ifdef GL_FRAGMENT_SUBROUTINE_UNIFORM
				GL_FRAGMENT_SUBROUTINE_UNIFORM,
#endif
#ifdef GL_GEOMETRY_SUBROUTINE
				GL_GEOMETRY_SUBROUTINE,
#endif
#ifdef GL_GEOMETRY_SUBROUTINE_UNIFORM
				GL_GEOMETRY_SUBROUTINE_UNIFORM,
#endif
#ifdef GL_PROGRAM_INPUT
				GL_PROGRAM_INPUT,
#endif
#ifdef GL_PROGRAM_OUTPUT
				GL_PROGRAM_OUTPUT,
#endif
#ifdef GL_SHADER_STORAGE_BLOCK
				GL_SHADER_STORAGE_BLOCK,
#endif
#ifdef GL_TESS_CONTROL_SUBROUTINE
				GL_TESS_CONTROL_SUBROUTINE,
#endif
#ifdef GL_TESS_CONTROL_SUBROUTINE_UNIFORM
				GL_TESS_CONTROL_SUBROUTINE_UNIFORM,
#endif
#ifdef GL_TESS_EVALUATION_SUBROUTINE
				GL_TESS_EVALUATION_SUBROUTINE,
#endif
#ifdef GL_TESS_EVALUATION_SUBROUTINE_UNIFORM
				GL_TESS_EVALUATION_SUBROUTINE_UNIFORM,
#endif
#ifdef GL_TRANSFORM_FEEDEBACK_VARYING
				GL_TRANSFORM_FEEDEBACK_VARYING,
#endif
#ifdef GL_UNIFORM
				GL_UNIFORM,
#endif
#ifdef GL_UNIFORM_BLOCK
				GL_UNIFORM_BLOCK,
#endif
#ifdef GL_VERTEX_SUBROUTINE
				GL_VERTEX_SUBROUTINE,
#endif
#ifdef GL_VERTEX_SUBROUTINE_UNIFORM
				GL_VERTEX_SUBROUTINE_UNIFORM,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 50: /* program_pipeline_stage */
		{
			static const GLbitfield vr[] = {
#ifdef GL_ALL_SHADER_BITS
				GL_ALL_SHADER_BITS,
#endif
#ifdef GL_COMPUTE_SHADER_BIT
				GL_COMPUTE_SHADER_BIT,
#endif
#ifdef GL_FRAGMENT_SHADER_BIT
				GL_FRAGMENT_SHADER_BIT,
#endif
#ifdef GL_GEOMETRY_SHADER_BIT
				GL_GEOMETRY_SHADER_BIT,
#endif
#ifdef GL_TESS_CONTROL_SHADER_BIT
				GL_TESS_CONTROL_SHADER_BIT,
#endif
#ifdef GL_TESS_EVALUATION_SHADER_BIT
				GL_TESS_EVALUATION_SHADER_BIT,
#endif
#ifdef GL_VERTEX_SHADER_BIT
				GL_VERTEX_SHADER_BIT,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 51: /* program_resource_property */
		{
			static const GLenum vr[] = {
#ifdef GL_ACTIVE_VARIABLES
				GL_ACTIVE_VARIABLES,
#endif
#ifdef GL_ARRAY_SIZE
				GL_ARRAY_SIZE,
#endif
#ifdef GL_ARRAY_STRIDE
				GL_ARRAY_STRIDE,
#endif
#ifdef GL_ATOMIC_COUNTER_BUFFER_INDEX
				GL_ATOMIC_COUNTER_BUFFER_INDEX,
#endif
#ifdef GL_BLOCK_INDEX
				GL_BLOCK_INDEX,
#endif
#ifdef GL_BUFFER_BINDING
				GL_BUFFER_BINDING,
#endif
#ifdef GL_BUFFER_DATA_SIZE
				GL_BUFFER_DATA_SIZE,
#endif
#ifdef GL_COMPATIBLE_SUBROUTINES
				GL_COMPATIBLE_SUBROUTINES,
#endif
#ifdef GL_IS_PER_PATCH
				GL_IS_PER_PATCH,
#endif
#ifdef GL_IS_ROW_MAJOR
				GL_IS_ROW_MAJOR,
#endif
#ifdef GL_LOCATION
				GL_LOCATION,
#endif
#ifdef GL_LOCATION_COMPONENT
				GL_LOCATION_COMPONENT,
#endif
#ifdef GL_LOCATION_INDEX
				GL_LOCATION_INDEX,
#endif
#ifdef GL_MATRIX_STRIDE
				GL_MATRIX_STRIDE,
#endif
#ifdef GL_NUM_ACTIVE_VARIABLES
				GL_NUM_ACTIVE_VARIABLES,
#endif
#ifdef GL_NUM_COMPATIBLE_SUBROUTINES
				GL_NUM_COMPATIBLE_SUBROUTINES,
#endif
#ifdef GL_OFFSET
				GL_OFFSET,
#endif
#ifdef GL_REFERENCED_BY_COMPUTE_SHADER
				GL_REFERENCED_BY_COMPUTE_SHADER,
#endif
#ifdef GL_REFERENCED_BY_FRAGMENT_SHADER
				GL_REFERENCED_BY_FRAGMENT_SHADER,
#endif
#ifdef GL_REFERENCED_BY_GEOMETRY_SHADER
				GL_REFERENCED_BY_GEOMETRY_SHADER,
#endif
#ifdef GL_REFERENCED_BY_TESS_CONTROL_SHADER
				GL_REFERENCED_BY_TESS_CONTROL_SHADER,
#endif
#ifdef GL_REFERENCED_BY_TESS_EVALUATION_SHADER
				GL_REFERENCED_BY_TESS_EVALUATION_SHADER,
#endif
#ifdef GL_REFERENCED_BY_VERTEX_SHADER
				GL_REFERENCED_BY_VERTEX_SHADER,
#endif
#ifdef GL_TOP_LEVEL_ARRAY_SIZE
				GL_TOP_LEVEL_ARRAY_SIZE,
#endif
#ifdef GL_TOP_LEVEL_ARRAY_STRIDE
				GL_TOP_LEVEL_ARRAY_STRIDE,
#endif
#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_INDEX
				GL_TRANSFORM_FEEDBACK_BUFFER_INDEX,
#endif
#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE
				GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 52: /* provoke_mode */
		{
			static const GLenum vr[] = {
#ifdef GL_FIRST_VERTEX_CONVENTION
				GL_FIRST_VERTEX_CONVENTION,
#endif
#ifdef GL_LAST_VERTEX_CONVENTION
				GL_LAST_VERTEX_CONVENTION,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 53: /* query_target */
		{
			static const GLenum vr[] = {
#ifdef GL_ANY_SAMPLES_PASSED
				GL_ANY_SAMPLES_PASSED,
#endif
#ifdef GL_CLIPPING_INPUT_PRIMITIVES_ARB
				GL_CLIPPING_INPUT_PRIMITIVES_ARB,
#endif
#ifdef GL_CLIPPING_OUTPUT_PRIMITIVES_ARB
				GL_CLIPPING_OUTPUT_PRIMITIVES_ARB,
#endif
#ifdef GL_COMPUTE_SHADER_INVOCATIONS_ARB
				GL_COMPUTE_SHADER_INVOCATIONS_ARB,
#endif
#ifdef GL_FRAGMENT_SHADER_INVOCATIONS_ARB
				GL_FRAGMENT_SHADER_INVOCATIONS_ARB,
#endif
#ifdef GL_GEOMETRY_SHADER_INVOCATIONS
				GL_GEOMETRY_SHADER_INVOCATIONS,
#endif
#ifdef GL_GEOMETRY_SHADER_PRIMITIVES_EMITTED_ARB
				GL_GEOMETRY_SHADER_PRIMITIVES_EMITTED_ARB,
#endif
#ifdef GL_PRIMITIVES_GENERATED
				GL_PRIMITIVES_GENERATED,
#endif
#ifdef GL_PRIMITIVES_SUBMITTED_ARB
				GL_PRIMITIVES_SUBMITTED_ARB,
#endif
#ifdef GL_SAMPLES_PASSED
				GL_SAMPLES_PASSED,
#endif
#ifdef GL_TESS_CONTROL_SHADER_PATCHES_ARB
				GL_TESS_CONTROL_SHADER_PATCHES_ARB,
#endif
#ifdef GL_TESS_EVALUATION_SHADER_INVOCATIONS_ARB
				GL_TESS_EVALUATION_SHADER_INVOCATIONS_ARB,
#endif
#ifdef GL_TIMESTAMP
				GL_TIMESTAMP,
#endif
#ifdef GL_TIME_ELAPSED
				GL_TIME_ELAPSED,
#endif
#ifdef GL_TRANSFORM_FEEDBACK_OVERFLOW_ARB
				GL_TRANSFORM_FEEDBACK_OVERFLOW_ARB,
#endif
#ifdef GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN
				GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN,
#endif
#ifdef GL_TRANSFORM_FEEDBACK_STREAM_OVERFLOW_ARB
				GL_TRANSFORM_FEEDBACK_STREAM_OVERFLOW_ARB,
#endif
#ifdef GL_VERTEX_SHADER_INVOCATIONS_ARB
				GL_VERTEX_SHADER_INVOCATIONS_ARB,
#endif
#ifdef GL_VERTICES_SUBMITTED_ARB
				GL_VERTICES_SUBMITTED_ARB,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 54: /* renderbuffer_target */
		{
			static const GLenum vr[] = {
#ifdef GL_RENDERBUFFER
				GL_RENDERBUFFER,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 55: /* reset_notification_strategy */
		{
			static const GLenum vr[] = {
#ifdef GL_LOSE_CONTEXT_ON_RESET
				GL_LOSE_CONTEXT_ON_RESET,
#endif
#ifdef GL_NO_RESET_NOTIFICATION
				GL_NO_RESET_NOTIFICATION,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 56: /* shader_type */
		{
			static const GLenum vr[] = {
#ifdef GL_COMPUTE_SHADER
				GL_COMPUTE_SHADER,
#endif
#ifdef GL_FRAGMENT_SHADER
				GL_FRAGMENT_SHADER,
#endif
#ifdef GL_GEOMETRY_SHADER
				GL_GEOMETRY_SHADER,
#endif
#ifdef GL_TESS_CONTROL_SHADER
				GL_TESS_CONTROL_SHADER,
#endif
#ifdef GL_TESS_EVALUATION_SHADER
				GL_TESS_EVALUATION_SHADER,
#endif
#ifdef GL_VERTEX_SHADER
				GL_VERTEX_SHADER,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 57: /* single_face */
		{
			static const GLenum vr[] = {
#ifdef GL_BACK
				GL_BACK,
#endif
#ifdef GL_FRONT
				GL_FRONT,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 58: /* sl_data_type */
		{
			static const GLenum vr[] = {
#ifdef GL_BOOL
				GL_BOOL,
#endif
#ifdef GL_BOOL_VEC2
				GL_BOOL_VEC2,
#endif
#ifdef GL_BOOL_VEC3
				GL_BOOL_VEC3,
#endif
#ifdef GL_BOOL_VEC4
				GL_BOOL_VEC4,
#endif
#ifdef GL_DOUBLE
				GL_DOUBLE,
#endif
#ifdef GL_DOUBLE_MAT2
				GL_DOUBLE_MAT2,
#endif
#ifdef GL_DOUBLE_MAT2x3
				GL_DOUBLE_MAT2x3,
#endif
#ifdef GL_DOUBLE_MAT2x4
				GL_DOUBLE_MAT2x4,
#endif
#ifdef GL_DOUBLE_MAT3
				GL_DOUBLE_MAT3,
#endif
#ifdef GL_DOUBLE_MAT3x2
				GL_DOUBLE_MAT3x2,
#endif
#ifdef GL_DOUBLE_MAT3x4
				GL_DOUBLE_MAT3x4,
#endif
#ifdef GL_DOUBLE_MAT4
				GL_DOUBLE_MAT4,
#endif
#ifdef GL_DOUBLE_MAT4x2
				GL_DOUBLE_MAT4x2,
#endif
#ifdef GL_DOUBLE_MAT4x3
				GL_DOUBLE_MAT4x3,
#endif
#ifdef GL_DOUBLE_VEC2
				GL_DOUBLE_VEC2,
#endif
#ifdef GL_DOUBLE_VEC3
				GL_DOUBLE_VEC3,
#endif
#ifdef GL_DOUBLE_VEC4
				GL_DOUBLE_VEC4,
#endif
#ifdef GL_FLOAT
				GL_FLOAT,
#endif
#ifdef GL_FLOAT_MAT2
				GL_FLOAT_MAT2,
#endif
#ifdef GL_FLOAT_MAT2x3
				GL_FLOAT_MAT2x3,
#endif
#ifdef GL_FLOAT_MAT2x4
				GL_FLOAT_MAT2x4,
#endif
#ifdef GL_FLOAT_MAT3
				GL_FLOAT_MAT3,
#endif
#ifdef GL_FLOAT_MAT3x2
				GL_FLOAT_MAT3x2,
#endif
#ifdef GL_FLOAT_MAT3x4
				GL_FLOAT_MAT3x4,
#endif
#ifdef GL_FLOAT_MAT4
				GL_FLOAT_MAT4,
#endif
#ifdef GL_FLOAT_MAT4x2
				GL_FLOAT_MAT4x2,
#endif
#ifdef GL_FLOAT_MAT4x3
				GL_FLOAT_MAT4x3,
#endif
#ifdef GL_FLOAT_VEC2
				GL_FLOAT_VEC2,
#endif
#ifdef GL_FLOAT_VEC3
				GL_FLOAT_VEC3,
#endif
#ifdef GL_FLOAT_VEC4
				GL_FLOAT_VEC4,
#endif
#ifdef GL_IMAGE_1D
				GL_IMAGE_1D,
#endif
#ifdef GL_IMAGE_1D_ARRAY
				GL_IMAGE_1D_ARRAY,
#endif
#ifdef GL_IMAGE_2D
				GL_IMAGE_2D,
#endif
#ifdef GL_IMAGE_2D_ARRAY
				GL_IMAGE_2D_ARRAY,
#endif
#ifdef GL_IMAGE_2D_MULTISAMPLE
				GL_IMAGE_2D_MULTISAMPLE,
#endif
#ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
				GL_IMAGE_2D_MULTISAMPLE_ARRAY,
#endif
#ifdef GL_IMAGE_2D_RECT
				GL_IMAGE_2D_RECT,
#endif
#ifdef GL_IMAGE_3D
				GL_IMAGE_3D,
#endif
#ifdef GL_IMAGE_BUFFER
				GL_IMAGE_BUFFER,
#endif
#ifdef GL_IMAGE_CUBE
				GL_IMAGE_CUBE,
#endif
#ifdef GL_INT
				GL_INT,
#endif
#ifdef GL_INT_IMAGE_1D
				GL_INT_IMAGE_1D,
#endif
#ifdef GL_INT_IMAGE_1D_ARRAY
				GL_INT_IMAGE_1D_ARRAY,
#endif
#ifdef GL_INT_IMAGE_2D
				GL_INT_IMAGE_2D,
#endif
#ifdef GL_INT_IMAGE_2D_ARRAY
				GL_INT_IMAGE_2D_ARRAY,
#endif
#ifdef GL_INT_IMAGE_2D_MULTISAMPLE
				GL_INT_IMAGE_2D_MULTISAMPLE,
#endif
#ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
				GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY,
#endif
#ifdef GL_INT_IMAGE_2D_RECT
				GL_INT_IMAGE_2D_RECT,
#endif
#ifdef GL_INT_IMAGE_3D
				GL_INT_IMAGE_3D,
#endif
#ifdef GL_INT_IMAGE_BUFFER
				GL_INT_IMAGE_BUFFER,
#endif
#ifdef GL_INT_IMAGE_CUBE
				GL_INT_IMAGE_CUBE,
#endif
#ifdef GL_INT_SAMPLER_1D
				GL_INT_SAMPLER_1D,
#endif
#ifdef GL_INT_SAMPLER_1D_ARRAY
				GL_INT_SAMPLER_1D_ARRAY,
#endif
#ifdef GL_INT_SAMPLER_2D
				GL_INT_SAMPLER_2D,
#endif
#ifdef GL_INT_SAMPLER_2D_ARRAY
				GL_INT_SAMPLER_2D_ARRAY,
#endif
#ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
				GL_INT_SAMPLER_2D_MULTISAMPLE,
#endif
#ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
				GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY,
#endif
#ifdef GL_INT_SAMPLER_2D_RECT
				GL_INT_SAMPLER_2D_RECT,
#endif
#ifdef GL_INT_SAMPLER_3D
				GL_INT_SAMPLER_3D,
#endif
#ifdef GL_INT_SAMPLER_BUFFER
				GL_INT_SAMPLER_BUFFER,
#endif
#ifdef GL_INT_SAMPLER_CUBE
				GL_INT_SAMPLER_CUBE,
#endif
#ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
				GL_INT_SAMPLER_CUBE_MAP_ARRAY,
#endif
#ifdef GL_INT_VEC2
				GL_INT_VEC2,
#endif
#ifdef GL_INT_VEC3
				GL_INT_VEC3,
#endif
#ifdef GL_INT_VEC4
				GL_INT_VEC4,
#endif
#ifdef GL_NONE
				GL_NONE,
#endif
#ifdef GL_SAMPLER_1D
				GL_SAMPLER_1D,
#endif
#ifdef GL_SAMPLER_1D_ARRAY
				GL_SAMPLER_1D_ARRAY,
#endif
#ifdef GL_SAMPLER_1D_ARRAY_SHADOW
				GL_SAMPLER_1D_ARRAY_SHADOW,
#endif
#ifdef GL_SAMPLER_1D_SHADOW
				GL_SAMPLER_1D_SHADOW,
#endif
#ifdef GL_SAMPLER_2D
				GL_SAMPLER_2D,
#endif
#ifdef GL_SAMPLER_2D_ARRAY
				GL_SAMPLER_2D_ARRAY,
#endif
#ifdef GL_SAMPLER_2D_ARRAY_SHADOW
				GL_SAMPLER_2D_ARRAY_SHADOW,
#endif
#ifdef GL_SAMPLER_2D_MULTISAMPLE
				GL_SAMPLER_2D_MULTISAMPLE,
#endif
#ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
				GL_SAMPLER_2D_MULTISAMPLE_ARRAY,
#endif
#ifdef GL_SAMPLER_2D_RECT
				GL_SAMPLER_2D_RECT,
#endif
#ifdef GL_SAMPLER_2D_RECT_SHADOW
				GL_SAMPLER_2D_RECT_SHADOW,
#endif
#ifdef GL_SAMPLER_2D_SHADOW
				GL_SAMPLER_2D_SHADOW,
#endif
#ifdef GL_SAMPLER_3D
				GL_SAMPLER_3D,
#endif
#ifdef GL_SAMPLER_BUFFER
				GL_SAMPLER_BUFFER,
#endif
#ifdef GL_SAMPLER_CUBE
				GL_SAMPLER_CUBE,
#endif
#ifdef GL_SAMPLER_CUBE_MAP_ARRAY
				GL_SAMPLER_CUBE_MAP_ARRAY,
#endif
#ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
				GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW,
#endif
#ifdef GL_SAMPLER_CUBE_SHADOW
				GL_SAMPLER_CUBE_SHADOW,
#endif
#ifdef GL_UNSIGNED_INT
				GL_UNSIGNED_INT,
#endif
#ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
				GL_UNSIGNED_INT_ATOMIC_COUNTER,
#endif
#ifdef GL_UNSIGNED_INT_IMAGE_1D
				GL_UNSIGNED_INT_IMAGE_1D,
#endif
#ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
				GL_UNSIGNED_INT_IMAGE_1D_ARRAY,
#endif
#ifdef GL_UNSIGNED_INT_IMAGE_2D
				GL_UNSIGNED_INT_IMAGE_2D,
#endif
#ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
				GL_UNSIGNED_INT_IMAGE_2D_ARRAY,
#endif
#ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
				GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE,
#endif
#ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
				GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY,
#endif
#ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
				GL_UNSIGNED_INT_IMAGE_2D_RECT,
#endif
#ifdef GL_UNSIGNED_INT_IMAGE_3D
				GL_UNSIGNED_INT_IMAGE_3D,
#endif
#ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
				GL_UNSIGNED_INT_IMAGE_BUFFER,
#endif
#ifdef GL_UNSIGNED_INT_IMAGE_CUBE
				GL_UNSIGNED_INT_IMAGE_CUBE,
#endif
#ifdef GL_UNSIGNED_INT_SAMPLER_1D
				GL_UNSIGNED_INT_SAMPLER_1D,
#endif
#ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
				GL_UNSIGNED_INT_SAMPLER_1D_ARRAY,
#endif
#ifdef GL_UNSIGNED_INT_SAMPLER_2D
				GL_UNSIGNED_INT_SAMPLER_2D,
#endif
#ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
				GL_UNSIGNED_INT_SAMPLER_2D_ARRAY,
#endif
#ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
				GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE,
#endif
#ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
				GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY,
#endif
#ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
				GL_UNSIGNED_INT_SAMPLER_2D_RECT,
#endif
#ifdef GL_UNSIGNED_INT_SAMPLER_3D
				GL_UNSIGNED_INT_SAMPLER_3D,
#endif
#ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
				GL_UNSIGNED_INT_SAMPLER_BUFFER,
#endif
#ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
				GL_UNSIGNED_INT_SAMPLER_CUBE,
#endif
#ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
				GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY,
#endif
#ifdef GL_UNSIGNED_INT_VEC2
				GL_UNSIGNED_INT_VEC2,
#endif
#ifdef GL_UNSIGNED_INT_VEC3
				GL_UNSIGNED_INT_VEC3,
#endif
#ifdef GL_UNSIGNED_INT_VEC4
				GL_UNSIGNED_INT_VEC4,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 59: /* stencil_operation */
		{
			static const GLenum vr[] = {
#ifdef GL_DECR
				GL_DECR,
#endif
#ifdef GL_DECR_WRAP
				GL_DECR_WRAP,
#endif
#ifdef GL_INCR
				GL_INCR,
#endif
#ifdef GL_INCR_WRAP
				GL_INCR_WRAP,
#endif
#ifdef GL_INVERT
				GL_INVERT,
#endif
#ifdef GL_KEEP
				GL_KEEP,
#endif
#ifdef GL_REPLACE
				GL_REPLACE,
#endif
#ifdef GL_ZERO
				GL_ZERO,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 60: /* string_query */
		{
			static const GLenum vr[] = {
#ifdef GL_RENDERER
				GL_RENDERER,
#endif
#ifdef GL_SHADING_LANGUAGE_VERSION
				GL_SHADING_LANGUAGE_VERSION,
#endif
#ifdef GL_VENDOR
				GL_VENDOR,
#endif
#ifdef GL_VERSION
				GL_VERSION,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 61: /* sync_condition */
		{
			static const GLenum vr[] = {
#ifdef GL_SYNC_GPU_COMMANDS_COMPLETE
				GL_SYNC_GPU_COMMANDS_COMPLETE,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 62: /* sync_status */
		{
			static const GLenum vr[] = {
#ifdef GL_SIGNALED
				GL_SIGNALED,
#endif
#ifdef GL_UNSIGNALED
				GL_UNSIGNALED,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 63: /* sync_type */
		{
			static const GLenum vr[] = {
#ifdef GL_SYNC_FENCE
				GL_SYNC_FENCE,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 64: /* sync_wait_result */
		{
			static const GLenum vr[] = {
#ifdef GL_ALREADY_SIGNALED
				GL_ALREADY_SIGNALED,
#endif
#ifdef GL_CONDITION_SATISFIED
				GL_CONDITION_SATISFIED,
#endif
#ifdef GL_TIMEOUT_EXPIRED
				GL_TIMEOUT_EXPIRED,
#endif
#ifdef GL_WAIT_FAILED
				GL_WAIT_FAILED,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 65: /* tess_gen_primitive_spacing */
		{
			static const GLenum vr[] = {
#ifdef GL_EQUAL
				GL_EQUAL,
#endif
#ifdef GL_FRACTIONAL_EVEN
				GL_FRACTIONAL_EVEN,
#endif
#ifdef GL_FRACTIONAL_ODD
				GL_FRACTIONAL_ODD,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 66: /* tess_gen_primitive_type */
		{
			static const GLenum vr[] = {
#ifdef GL_ISOLINES
				GL_ISOLINES,
#endif
#ifdef GL_QUADS
				GL_QUADS,
#endif
#ifdef GL_TRIANGLES
				GL_TRIANGLES,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 67: /* texture_compare_mode */
		{
			static const GLenum vr[] = {
#ifdef GL_COMPARE_REF_TO_TEXTURE
				GL_COMPARE_REF_TO_TEXTURE,
#endif
#ifdef GL_NONE
				GL_NONE,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 68: /* texture_filter */
		{
			static const GLenum vr[] = {
#ifdef GL_LINEAR
				GL_LINEAR,
#endif
#ifdef GL_NEAREST
				GL_NEAREST,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 69: /* texture_mag_filter */
		{
			static const GLenum vr[] = {
#ifdef GL_LINEAR
				GL_LINEAR,
#endif
#ifdef GL_NEAREST
				GL_NEAREST,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 70: /* texture_min_filter */
		{
			static const GLenum vr[] = {
#ifdef GL_LINEAR
				GL_LINEAR,
#endif
#ifdef GL_LINEAR_MIPMAP_LINEAR
				GL_LINEAR_MIPMAP_LINEAR,
#endif
#ifdef GL_LINEAR_MIPMAP_NEAREST
				GL_LINEAR_MIPMAP_NEAREST,
#endif
#ifdef GL_NEAREST
				GL_NEAREST,
#endif
#ifdef GL_NEAREST_MIPMAP_LINEAR
				GL_NEAREST_MIPMAP_LINEAR,
#endif
#ifdef GL_NEAREST_MIPMAP_NEAREST
				GL_NEAREST_MIPMAP_NEAREST,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 71: /* texture_swizzle */
		{
			static const GLenum vr[] = {
#ifdef GL_ALPHA
				GL_ALPHA,
#endif
#ifdef GL_BLUE
				GL_BLUE,
#endif
#ifdef GL_GREEN
				GL_GREEN,
#endif
#ifdef GL_ONE
				GL_ONE,
#endif
#ifdef GL_RED
				GL_RED,
#endif
#ifdef GL_ZERO
				GL_ZERO,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 72: /* texture_swizzle_coord */
		{
			static const GLenum vr[] = {
#ifdef GL_TEXTURE_SWIZZLE_A
				GL_TEXTURE_SWIZZLE_A,
#endif
#ifdef GL_TEXTURE_SWIZZLE_B
				GL_TEXTURE_SWIZZLE_B,
#endif
#ifdef GL_TEXTURE_SWIZZLE_G
				GL_TEXTURE_SWIZZLE_G,
#endif
#ifdef GL_TEXTURE_SWIZZLE_R
				GL_TEXTURE_SWIZZLE_R,
#endif
#ifdef GL_TEXTURE_SWIZZLE_RGBA
				GL_TEXTURE_SWIZZLE_RGBA,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 73: /* texture_target */
		{
			static const GLenum vr[] = {
#ifdef GL_TEXTURE_1D
				GL_TEXTURE_1D,
#endif
#ifdef GL_TEXTURE_1D_ARRAY
				GL_TEXTURE_1D_ARRAY,
#endif
#ifdef GL_TEXTURE_2D
				GL_TEXTURE_2D,
#endif
#ifdef GL_TEXTURE_2D_ARRAY
				GL_TEXTURE_2D_ARRAY,
#endif
#ifdef GL_TEXTURE_2D_MULTISAMPLE
				GL_TEXTURE_2D_MULTISAMPLE,
#endif
#ifdef GL_TEXTURE_2D_MULTISAMPLE_ARRAY
				GL_TEXTURE_2D_MULTISAMPLE_ARRAY,
#endif
#ifdef GL_TEXTURE_3D
				GL_TEXTURE_3D,
#endif
#ifdef GL_TEXTURE_BUFFER
				GL_TEXTURE_BUFFER,
#endif
#ifdef GL_TEXTURE_CUBE_MAP
				GL_TEXTURE_CUBE_MAP,
#endif
#ifdef GL_TEXTURE_CUBE_MAP_ARRAY
				GL_TEXTURE_CUBE_MAP_ARRAY,
#endif
#ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_X
				GL_TEXTURE_CUBE_MAP_NEGATIVE_X,
#endif
#ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_Y
				GL_TEXTURE_CUBE_MAP_NEGATIVE_Y,
#endif
#ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_Z
				GL_TEXTURE_CUBE_MAP_NEGATIVE_Z,
#endif
#ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_X
				GL_TEXTURE_CUBE_MAP_POSITIVE_X,
#endif
#ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_Y
				GL_TEXTURE_CUBE_MAP_POSITIVE_Y,
#endif
#ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_Z
				GL_TEXTURE_CUBE_MAP_POSITIVE_Z,
#endif
#ifdef GL_TEXTURE_RECTANGLE
				GL_TEXTURE_RECTANGLE,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 74: /* texture_wrap */
		{
			static const GLenum vr[] = {
#ifdef GL_CLAMP_TO_BORDER
				GL_CLAMP_TO_BORDER,
#endif
#ifdef GL_CLAMP_TO_EDGE
				GL_CLAMP_TO_EDGE,
#endif
#ifdef GL_MIRRORED_REPEAT
				GL_MIRRORED_REPEAT,
#endif
#ifdef GL_MIRROR_CLAMP_TO_EDGE
				GL_MIRROR_CLAMP_TO_EDGE,
#endif
#ifdef GL_REPEAT
				GL_REPEAT,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 75: /* texture_wrap_coord */
		{
			static const GLenum vr[] = {
#ifdef GL_TEXTURE_WRAP_R
				GL_TEXTURE_WRAP_R,
#endif
#ifdef GL_TEXTURE_WRAP_S
				GL_TEXTURE_WRAP_S,
#endif
#ifdef GL_TEXTURE_WRAP_T
				GL_TEXTURE_WRAP_T,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 76: /* transform_feedback_mode */
		{
			static const GLenum vr[] = {
#ifdef GL_INTERLEAVED_ATTRIBS
				GL_INTERLEAVED_ATTRIBS,
#endif
#ifdef GL_SEPARATE_ATTRIBS
				GL_SEPARATE_ATTRIBS,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 77: /* transform_feedback_primitive_type */
		{
			static const GLenum vr[] = {
#ifdef GL_LINES
				GL_LINES,
#endif
#ifdef GL_POINTS
				GL_POINTS,
#endif
#ifdef GL_TRIANGLES
				GL_TRIANGLES,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 78: /* transform_feedback_target */
		{
			static const GLenum vr[] = {
#ifdef GL_TRANSFORM_FEEDBACK
				GL_TRANSFORM_FEEDBACK,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
	default:;
	}

	(void)aec;
	return {nullptr, 0};
}

} // namespace oglplus
#endif
