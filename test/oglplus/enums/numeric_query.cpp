//  File test/oglplus/enums/numeric_query.cpp
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
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE OGLPLUS_numeric_query

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_numeric_query_tests)

BOOST_AUTO_TEST_CASE(enum_numeric_query_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	numeric_query x;
	(void)x;

#ifdef GL_ALIASED_LINE_WIDTH_RANGE
	x = ev.aliased_line_width_range;
	BOOST_CHECK(x == ev.aliased_line_width_range);
# ifdef GL_BLEND_COLOR
	BOOST_CHECK(x != ev.blend_color);
# endif
# ifdef GL_BLEND_DST_ALPHA
	BOOST_CHECK(x != ev.blend_dst_alpha);
# endif
# ifdef GL_BLEND_DST_RGB
	BOOST_CHECK(x != ev.blend_dst_rgb);
# endif
# ifdef GL_BLEND_EQUATION_ALPHA
	BOOST_CHECK(x != ev.blend_equation_alpha);
# endif
# ifdef GL_BLEND_EQUATION_RGB
	BOOST_CHECK(x != ev.blend_equation_rgb);
# endif
# ifdef GL_BLEND_SRC_ALPHA
	BOOST_CHECK(x != ev.blend_src_alpha);
# endif
# ifdef GL_BLEND_SRC_RGB
	BOOST_CHECK(x != ev.blend_src_rgb);
# endif
# ifdef GL_COLOR_CLEAR_VALUE
	BOOST_CHECK(x != ev.color_clear_value);
# endif
# ifdef GL_COLOR_WRITEMASK
	BOOST_CHECK(x != ev.color_writemask);
# endif
# ifdef GL_COMPRESSED_TEXTURE_FORMATS
	BOOST_CHECK(x != ev.compressed_texture_formats);
# endif
# ifdef GL_CONTEXT_FLAGS
	BOOST_CHECK(x != ev.context_flags);
# endif
# ifdef GL_DEBUG_GROUP_STACK_DEPTH
	BOOST_CHECK(x != ev.debug_group_stack_depth);
# endif
# ifdef GL_DEPTH_CLEAR_VALUE
	BOOST_CHECK(x != ev.depth_clear_value);
# endif
# ifdef GL_DEPTH_FUNC
	BOOST_CHECK(x != ev.depth_func);
# endif
# ifdef GL_DEPTH_RANGE
	BOOST_CHECK(x != ev.depth_range);
# endif
# ifdef GL_DEPTH_WRITEMASK
	BOOST_CHECK(x != ev.depth_writemask);
# endif
# ifdef GL_DOUBLEBUFFER
	BOOST_CHECK(x != ev.doublebuffer);
# endif
# ifdef GL_DRAW_BUFFER
	BOOST_CHECK(x != ev.draw_buffer);
# endif
# ifdef GL_FRAGMENT_SHADER_DERIVATIVE_HINT
	BOOST_CHECK(x != ev.fragment_shader_derivative_hint);
# endif
# ifdef GL_IMPLEMENTATION_COLOR_READ_FORMAT
	BOOST_CHECK(x != ev.implementation_color_read_format);
# endif
# ifdef GL_IMPLEMENTATION_COLOR_READ_TYPE
	BOOST_CHECK(x != ev.implementation_color_read_type);
# endif
# ifdef GL_LAYER_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.layer_provoking_vertex);
# endif
# ifdef GL_LINE_SMOOTH_HINT
	BOOST_CHECK(x != ev.line_smooth_hint);
# endif
# ifdef GL_LINE_WIDTH
	BOOST_CHECK(x != ev.line_width);
# endif
# ifdef GL_LOGIC_OP_MODE
	BOOST_CHECK(x != ev.logic_op_mode);
# endif
# ifdef GL_NUM_COMPRESSED_TEXTURE_FORMATS
	BOOST_CHECK(x != ev.num_compressed_texture_formats);
# endif
# ifdef GL_NUM_EXTENSIONS
	BOOST_CHECK(x != ev.num_extensions);
# endif
# ifdef GL_NUM_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.num_program_binary_formats);
# endif
# ifdef GL_NUM_SHADER_BINARY_FORMATS
	BOOST_CHECK(x != ev.num_shader_binary_formats);
# endif
# ifdef GL_PACK_ALIGNMENT
	BOOST_CHECK(x != ev.pack_alignment);
# endif
# ifdef GL_PACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.pack_image_height);
# endif
# ifdef GL_PACK_LSB_FIRST
	BOOST_CHECK(x != ev.pack_lsb_first);
# endif
# ifdef GL_PACK_ROW_LENGTH
	BOOST_CHECK(x != ev.pack_row_length);
# endif
# ifdef GL_PACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.pack_skip_images);
# endif
# ifdef GL_PACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.pack_skip_pixels);
# endif
# ifdef GL_PACK_SKIP_ROWS
	BOOST_CHECK(x != ev.pack_skip_rows);
# endif
# ifdef GL_PACK_SWAP_BYTES
	BOOST_CHECK(x != ev.pack_swap_bytes);
# endif
# ifdef GL_POINT_FADE_THRESHOLD_SIZE
	BOOST_CHECK(x != ev.point_fade_threshold_size);
# endif
# ifdef GL_POINT_SIZE
	BOOST_CHECK(x != ev.point_size);
# endif
# ifdef GL_POINT_SIZE_GRANULARITY
	BOOST_CHECK(x != ev.point_size_granularity);
# endif
# ifdef GL_POINT_SIZE_RANGE
	BOOST_CHECK(x != ev.point_size_range);
# endif
# ifdef GL_POLYGON_OFFSET_FACTOR
	BOOST_CHECK(x != ev.polygon_offset_factor);
# endif
# ifdef GL_POLYGON_OFFSET_UNITS
	BOOST_CHECK(x != ev.polygon_offset_units);
# endif
# ifdef GL_POLYGON_SMOOTH_HINT
	BOOST_CHECK(x != ev.polygon_smooth_hint);
# endif
# ifdef GL_PRIMITIVE_RESTART_INDEX
	BOOST_CHECK(x != ev.primitive_restart_index);
# endif
# ifdef GL_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.program_binary_formats);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.provoking_vertex);
# endif
# ifdef GL_READ_BUFFER
	BOOST_CHECK(x != ev.read_buffer);
# endif
# ifdef GL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef GL_SAMPLE_COVERAGE_INVERT
	BOOST_CHECK(x != ev.sample_coverage_invert);
# endif
# ifdef GL_SAMPLE_COVERAGE_VALUE
	BOOST_CHECK(x != ev.sample_coverage_value);
# endif
# ifdef GL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef GL_SCISSOR_BOX
	BOOST_CHECK(x != ev.scissor_box);
# endif
# ifdef GL_SHADER_COMPILER
	BOOST_CHECK(x != ev.shader_compiler);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.shader_storage_buffer_offset_alignment);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_SIZE
	BOOST_CHECK(x != ev.shader_storage_buffer_size);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_START
	BOOST_CHECK(x != ev.shader_storage_buffer_start);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	BOOST_CHECK(x != ev.smooth_line_width_granularity);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	BOOST_CHECK(x != ev.smooth_line_width_range);
# endif
# ifdef GL_STENCIL_BACK_FAIL
	BOOST_CHECK(x != ev.stencil_back_fail);
# endif
# ifdef GL_STENCIL_BACK_FUNC
	BOOST_CHECK(x != ev.stencil_back_func);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_BLEND_COLOR
	x = ev.blend_color;
	BOOST_CHECK(x == ev.blend_color);
# ifdef GL_BLEND_DST_ALPHA
	BOOST_CHECK(x != ev.blend_dst_alpha);
# endif
# ifdef GL_BLEND_DST_RGB
	BOOST_CHECK(x != ev.blend_dst_rgb);
# endif
# ifdef GL_BLEND_EQUATION_ALPHA
	BOOST_CHECK(x != ev.blend_equation_alpha);
# endif
# ifdef GL_BLEND_EQUATION_RGB
	BOOST_CHECK(x != ev.blend_equation_rgb);
# endif
# ifdef GL_BLEND_SRC_ALPHA
	BOOST_CHECK(x != ev.blend_src_alpha);
# endif
# ifdef GL_BLEND_SRC_RGB
	BOOST_CHECK(x != ev.blend_src_rgb);
# endif
# ifdef GL_COLOR_CLEAR_VALUE
	BOOST_CHECK(x != ev.color_clear_value);
# endif
# ifdef GL_COLOR_WRITEMASK
	BOOST_CHECK(x != ev.color_writemask);
# endif
# ifdef GL_COMPRESSED_TEXTURE_FORMATS
	BOOST_CHECK(x != ev.compressed_texture_formats);
# endif
# ifdef GL_CONTEXT_FLAGS
	BOOST_CHECK(x != ev.context_flags);
# endif
# ifdef GL_DEBUG_GROUP_STACK_DEPTH
	BOOST_CHECK(x != ev.debug_group_stack_depth);
# endif
# ifdef GL_DEPTH_CLEAR_VALUE
	BOOST_CHECK(x != ev.depth_clear_value);
# endif
# ifdef GL_DEPTH_FUNC
	BOOST_CHECK(x != ev.depth_func);
# endif
# ifdef GL_DEPTH_RANGE
	BOOST_CHECK(x != ev.depth_range);
# endif
# ifdef GL_DEPTH_WRITEMASK
	BOOST_CHECK(x != ev.depth_writemask);
# endif
# ifdef GL_DOUBLEBUFFER
	BOOST_CHECK(x != ev.doublebuffer);
# endif
# ifdef GL_DRAW_BUFFER
	BOOST_CHECK(x != ev.draw_buffer);
# endif
# ifdef GL_FRAGMENT_SHADER_DERIVATIVE_HINT
	BOOST_CHECK(x != ev.fragment_shader_derivative_hint);
# endif
# ifdef GL_IMPLEMENTATION_COLOR_READ_FORMAT
	BOOST_CHECK(x != ev.implementation_color_read_format);
# endif
# ifdef GL_IMPLEMENTATION_COLOR_READ_TYPE
	BOOST_CHECK(x != ev.implementation_color_read_type);
# endif
# ifdef GL_LAYER_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.layer_provoking_vertex);
# endif
# ifdef GL_LINE_SMOOTH_HINT
	BOOST_CHECK(x != ev.line_smooth_hint);
# endif
# ifdef GL_LINE_WIDTH
	BOOST_CHECK(x != ev.line_width);
# endif
# ifdef GL_LOGIC_OP_MODE
	BOOST_CHECK(x != ev.logic_op_mode);
# endif
# ifdef GL_NUM_COMPRESSED_TEXTURE_FORMATS
	BOOST_CHECK(x != ev.num_compressed_texture_formats);
# endif
# ifdef GL_NUM_EXTENSIONS
	BOOST_CHECK(x != ev.num_extensions);
# endif
# ifdef GL_NUM_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.num_program_binary_formats);
# endif
# ifdef GL_NUM_SHADER_BINARY_FORMATS
	BOOST_CHECK(x != ev.num_shader_binary_formats);
# endif
# ifdef GL_PACK_ALIGNMENT
	BOOST_CHECK(x != ev.pack_alignment);
# endif
# ifdef GL_PACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.pack_image_height);
# endif
# ifdef GL_PACK_LSB_FIRST
	BOOST_CHECK(x != ev.pack_lsb_first);
# endif
# ifdef GL_PACK_ROW_LENGTH
	BOOST_CHECK(x != ev.pack_row_length);
# endif
# ifdef GL_PACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.pack_skip_images);
# endif
# ifdef GL_PACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.pack_skip_pixels);
# endif
# ifdef GL_PACK_SKIP_ROWS
	BOOST_CHECK(x != ev.pack_skip_rows);
# endif
# ifdef GL_PACK_SWAP_BYTES
	BOOST_CHECK(x != ev.pack_swap_bytes);
# endif
# ifdef GL_POINT_FADE_THRESHOLD_SIZE
	BOOST_CHECK(x != ev.point_fade_threshold_size);
# endif
# ifdef GL_POINT_SIZE
	BOOST_CHECK(x != ev.point_size);
# endif
# ifdef GL_POINT_SIZE_GRANULARITY
	BOOST_CHECK(x != ev.point_size_granularity);
# endif
# ifdef GL_POINT_SIZE_RANGE
	BOOST_CHECK(x != ev.point_size_range);
# endif
# ifdef GL_POLYGON_OFFSET_FACTOR
	BOOST_CHECK(x != ev.polygon_offset_factor);
# endif
# ifdef GL_POLYGON_OFFSET_UNITS
	BOOST_CHECK(x != ev.polygon_offset_units);
# endif
# ifdef GL_POLYGON_SMOOTH_HINT
	BOOST_CHECK(x != ev.polygon_smooth_hint);
# endif
# ifdef GL_PRIMITIVE_RESTART_INDEX
	BOOST_CHECK(x != ev.primitive_restart_index);
# endif
# ifdef GL_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.program_binary_formats);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.provoking_vertex);
# endif
# ifdef GL_READ_BUFFER
	BOOST_CHECK(x != ev.read_buffer);
# endif
# ifdef GL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef GL_SAMPLE_COVERAGE_INVERT
	BOOST_CHECK(x != ev.sample_coverage_invert);
# endif
# ifdef GL_SAMPLE_COVERAGE_VALUE
	BOOST_CHECK(x != ev.sample_coverage_value);
# endif
# ifdef GL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef GL_SCISSOR_BOX
	BOOST_CHECK(x != ev.scissor_box);
# endif
# ifdef GL_SHADER_COMPILER
	BOOST_CHECK(x != ev.shader_compiler);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.shader_storage_buffer_offset_alignment);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_SIZE
	BOOST_CHECK(x != ev.shader_storage_buffer_size);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_START
	BOOST_CHECK(x != ev.shader_storage_buffer_start);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	BOOST_CHECK(x != ev.smooth_line_width_granularity);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	BOOST_CHECK(x != ev.smooth_line_width_range);
# endif
# ifdef GL_STENCIL_BACK_FAIL
	BOOST_CHECK(x != ev.stencil_back_fail);
# endif
# ifdef GL_STENCIL_BACK_FUNC
	BOOST_CHECK(x != ev.stencil_back_func);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_BLEND_DST_ALPHA
	x = ev.blend_dst_alpha;
	BOOST_CHECK(x == ev.blend_dst_alpha);
# ifdef GL_BLEND_DST_RGB
	BOOST_CHECK(x != ev.blend_dst_rgb);
# endif
# ifdef GL_BLEND_EQUATION_ALPHA
	BOOST_CHECK(x != ev.blend_equation_alpha);
# endif
# ifdef GL_BLEND_EQUATION_RGB
	BOOST_CHECK(x != ev.blend_equation_rgb);
# endif
# ifdef GL_BLEND_SRC_ALPHA
	BOOST_CHECK(x != ev.blend_src_alpha);
# endif
# ifdef GL_BLEND_SRC_RGB
	BOOST_CHECK(x != ev.blend_src_rgb);
# endif
# ifdef GL_COLOR_CLEAR_VALUE
	BOOST_CHECK(x != ev.color_clear_value);
# endif
# ifdef GL_COLOR_WRITEMASK
	BOOST_CHECK(x != ev.color_writemask);
# endif
# ifdef GL_COMPRESSED_TEXTURE_FORMATS
	BOOST_CHECK(x != ev.compressed_texture_formats);
# endif
# ifdef GL_CONTEXT_FLAGS
	BOOST_CHECK(x != ev.context_flags);
# endif
# ifdef GL_DEBUG_GROUP_STACK_DEPTH
	BOOST_CHECK(x != ev.debug_group_stack_depth);
# endif
# ifdef GL_DEPTH_CLEAR_VALUE
	BOOST_CHECK(x != ev.depth_clear_value);
# endif
# ifdef GL_DEPTH_FUNC
	BOOST_CHECK(x != ev.depth_func);
# endif
# ifdef GL_DEPTH_RANGE
	BOOST_CHECK(x != ev.depth_range);
# endif
# ifdef GL_DEPTH_WRITEMASK
	BOOST_CHECK(x != ev.depth_writemask);
# endif
# ifdef GL_DOUBLEBUFFER
	BOOST_CHECK(x != ev.doublebuffer);
# endif
# ifdef GL_DRAW_BUFFER
	BOOST_CHECK(x != ev.draw_buffer);
# endif
# ifdef GL_FRAGMENT_SHADER_DERIVATIVE_HINT
	BOOST_CHECK(x != ev.fragment_shader_derivative_hint);
# endif
# ifdef GL_IMPLEMENTATION_COLOR_READ_FORMAT
	BOOST_CHECK(x != ev.implementation_color_read_format);
# endif
# ifdef GL_IMPLEMENTATION_COLOR_READ_TYPE
	BOOST_CHECK(x != ev.implementation_color_read_type);
# endif
# ifdef GL_LAYER_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.layer_provoking_vertex);
# endif
# ifdef GL_LINE_SMOOTH_HINT
	BOOST_CHECK(x != ev.line_smooth_hint);
# endif
# ifdef GL_LINE_WIDTH
	BOOST_CHECK(x != ev.line_width);
# endif
# ifdef GL_LOGIC_OP_MODE
	BOOST_CHECK(x != ev.logic_op_mode);
# endif
# ifdef GL_NUM_COMPRESSED_TEXTURE_FORMATS
	BOOST_CHECK(x != ev.num_compressed_texture_formats);
# endif
# ifdef GL_NUM_EXTENSIONS
	BOOST_CHECK(x != ev.num_extensions);
# endif
# ifdef GL_NUM_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.num_program_binary_formats);
# endif
# ifdef GL_NUM_SHADER_BINARY_FORMATS
	BOOST_CHECK(x != ev.num_shader_binary_formats);
# endif
# ifdef GL_PACK_ALIGNMENT
	BOOST_CHECK(x != ev.pack_alignment);
# endif
# ifdef GL_PACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.pack_image_height);
# endif
# ifdef GL_PACK_LSB_FIRST
	BOOST_CHECK(x != ev.pack_lsb_first);
# endif
# ifdef GL_PACK_ROW_LENGTH
	BOOST_CHECK(x != ev.pack_row_length);
# endif
# ifdef GL_PACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.pack_skip_images);
# endif
# ifdef GL_PACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.pack_skip_pixels);
# endif
# ifdef GL_PACK_SKIP_ROWS
	BOOST_CHECK(x != ev.pack_skip_rows);
# endif
# ifdef GL_PACK_SWAP_BYTES
	BOOST_CHECK(x != ev.pack_swap_bytes);
# endif
# ifdef GL_POINT_FADE_THRESHOLD_SIZE
	BOOST_CHECK(x != ev.point_fade_threshold_size);
# endif
# ifdef GL_POINT_SIZE
	BOOST_CHECK(x != ev.point_size);
# endif
# ifdef GL_POINT_SIZE_GRANULARITY
	BOOST_CHECK(x != ev.point_size_granularity);
# endif
# ifdef GL_POINT_SIZE_RANGE
	BOOST_CHECK(x != ev.point_size_range);
# endif
# ifdef GL_POLYGON_OFFSET_FACTOR
	BOOST_CHECK(x != ev.polygon_offset_factor);
# endif
# ifdef GL_POLYGON_OFFSET_UNITS
	BOOST_CHECK(x != ev.polygon_offset_units);
# endif
# ifdef GL_POLYGON_SMOOTH_HINT
	BOOST_CHECK(x != ev.polygon_smooth_hint);
# endif
# ifdef GL_PRIMITIVE_RESTART_INDEX
	BOOST_CHECK(x != ev.primitive_restart_index);
# endif
# ifdef GL_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.program_binary_formats);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.provoking_vertex);
# endif
# ifdef GL_READ_BUFFER
	BOOST_CHECK(x != ev.read_buffer);
# endif
# ifdef GL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef GL_SAMPLE_COVERAGE_INVERT
	BOOST_CHECK(x != ev.sample_coverage_invert);
# endif
# ifdef GL_SAMPLE_COVERAGE_VALUE
	BOOST_CHECK(x != ev.sample_coverage_value);
# endif
# ifdef GL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef GL_SCISSOR_BOX
	BOOST_CHECK(x != ev.scissor_box);
# endif
# ifdef GL_SHADER_COMPILER
	BOOST_CHECK(x != ev.shader_compiler);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.shader_storage_buffer_offset_alignment);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_SIZE
	BOOST_CHECK(x != ev.shader_storage_buffer_size);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_START
	BOOST_CHECK(x != ev.shader_storage_buffer_start);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	BOOST_CHECK(x != ev.smooth_line_width_granularity);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	BOOST_CHECK(x != ev.smooth_line_width_range);
# endif
# ifdef GL_STENCIL_BACK_FAIL
	BOOST_CHECK(x != ev.stencil_back_fail);
# endif
# ifdef GL_STENCIL_BACK_FUNC
	BOOST_CHECK(x != ev.stencil_back_func);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_BLEND_DST_RGB
	x = ev.blend_dst_rgb;
	BOOST_CHECK(x == ev.blend_dst_rgb);
# ifdef GL_BLEND_EQUATION_ALPHA
	BOOST_CHECK(x != ev.blend_equation_alpha);
# endif
# ifdef GL_BLEND_EQUATION_RGB
	BOOST_CHECK(x != ev.blend_equation_rgb);
# endif
# ifdef GL_BLEND_SRC_ALPHA
	BOOST_CHECK(x != ev.blend_src_alpha);
# endif
# ifdef GL_BLEND_SRC_RGB
	BOOST_CHECK(x != ev.blend_src_rgb);
# endif
# ifdef GL_COLOR_CLEAR_VALUE
	BOOST_CHECK(x != ev.color_clear_value);
# endif
# ifdef GL_COLOR_WRITEMASK
	BOOST_CHECK(x != ev.color_writemask);
# endif
# ifdef GL_COMPRESSED_TEXTURE_FORMATS
	BOOST_CHECK(x != ev.compressed_texture_formats);
# endif
# ifdef GL_CONTEXT_FLAGS
	BOOST_CHECK(x != ev.context_flags);
# endif
# ifdef GL_DEBUG_GROUP_STACK_DEPTH
	BOOST_CHECK(x != ev.debug_group_stack_depth);
# endif
# ifdef GL_DEPTH_CLEAR_VALUE
	BOOST_CHECK(x != ev.depth_clear_value);
# endif
# ifdef GL_DEPTH_FUNC
	BOOST_CHECK(x != ev.depth_func);
# endif
# ifdef GL_DEPTH_RANGE
	BOOST_CHECK(x != ev.depth_range);
# endif
# ifdef GL_DEPTH_WRITEMASK
	BOOST_CHECK(x != ev.depth_writemask);
# endif
# ifdef GL_DOUBLEBUFFER
	BOOST_CHECK(x != ev.doublebuffer);
# endif
# ifdef GL_DRAW_BUFFER
	BOOST_CHECK(x != ev.draw_buffer);
# endif
# ifdef GL_FRAGMENT_SHADER_DERIVATIVE_HINT
	BOOST_CHECK(x != ev.fragment_shader_derivative_hint);
# endif
# ifdef GL_IMPLEMENTATION_COLOR_READ_FORMAT
	BOOST_CHECK(x != ev.implementation_color_read_format);
# endif
# ifdef GL_IMPLEMENTATION_COLOR_READ_TYPE
	BOOST_CHECK(x != ev.implementation_color_read_type);
# endif
# ifdef GL_LAYER_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.layer_provoking_vertex);
# endif
# ifdef GL_LINE_SMOOTH_HINT
	BOOST_CHECK(x != ev.line_smooth_hint);
# endif
# ifdef GL_LINE_WIDTH
	BOOST_CHECK(x != ev.line_width);
# endif
# ifdef GL_LOGIC_OP_MODE
	BOOST_CHECK(x != ev.logic_op_mode);
# endif
# ifdef GL_NUM_COMPRESSED_TEXTURE_FORMATS
	BOOST_CHECK(x != ev.num_compressed_texture_formats);
# endif
# ifdef GL_NUM_EXTENSIONS
	BOOST_CHECK(x != ev.num_extensions);
# endif
# ifdef GL_NUM_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.num_program_binary_formats);
# endif
# ifdef GL_NUM_SHADER_BINARY_FORMATS
	BOOST_CHECK(x != ev.num_shader_binary_formats);
# endif
# ifdef GL_PACK_ALIGNMENT
	BOOST_CHECK(x != ev.pack_alignment);
# endif
# ifdef GL_PACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.pack_image_height);
# endif
# ifdef GL_PACK_LSB_FIRST
	BOOST_CHECK(x != ev.pack_lsb_first);
# endif
# ifdef GL_PACK_ROW_LENGTH
	BOOST_CHECK(x != ev.pack_row_length);
# endif
# ifdef GL_PACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.pack_skip_images);
# endif
# ifdef GL_PACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.pack_skip_pixels);
# endif
# ifdef GL_PACK_SKIP_ROWS
	BOOST_CHECK(x != ev.pack_skip_rows);
# endif
# ifdef GL_PACK_SWAP_BYTES
	BOOST_CHECK(x != ev.pack_swap_bytes);
# endif
# ifdef GL_POINT_FADE_THRESHOLD_SIZE
	BOOST_CHECK(x != ev.point_fade_threshold_size);
# endif
# ifdef GL_POINT_SIZE
	BOOST_CHECK(x != ev.point_size);
# endif
# ifdef GL_POINT_SIZE_GRANULARITY
	BOOST_CHECK(x != ev.point_size_granularity);
# endif
# ifdef GL_POINT_SIZE_RANGE
	BOOST_CHECK(x != ev.point_size_range);
# endif
# ifdef GL_POLYGON_OFFSET_FACTOR
	BOOST_CHECK(x != ev.polygon_offset_factor);
# endif
# ifdef GL_POLYGON_OFFSET_UNITS
	BOOST_CHECK(x != ev.polygon_offset_units);
# endif
# ifdef GL_POLYGON_SMOOTH_HINT
	BOOST_CHECK(x != ev.polygon_smooth_hint);
# endif
# ifdef GL_PRIMITIVE_RESTART_INDEX
	BOOST_CHECK(x != ev.primitive_restart_index);
# endif
# ifdef GL_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.program_binary_formats);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.provoking_vertex);
# endif
# ifdef GL_READ_BUFFER
	BOOST_CHECK(x != ev.read_buffer);
# endif
# ifdef GL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef GL_SAMPLE_COVERAGE_INVERT
	BOOST_CHECK(x != ev.sample_coverage_invert);
# endif
# ifdef GL_SAMPLE_COVERAGE_VALUE
	BOOST_CHECK(x != ev.sample_coverage_value);
# endif
# ifdef GL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef GL_SCISSOR_BOX
	BOOST_CHECK(x != ev.scissor_box);
# endif
# ifdef GL_SHADER_COMPILER
	BOOST_CHECK(x != ev.shader_compiler);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.shader_storage_buffer_offset_alignment);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_SIZE
	BOOST_CHECK(x != ev.shader_storage_buffer_size);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_START
	BOOST_CHECK(x != ev.shader_storage_buffer_start);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	BOOST_CHECK(x != ev.smooth_line_width_granularity);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	BOOST_CHECK(x != ev.smooth_line_width_range);
# endif
# ifdef GL_STENCIL_BACK_FAIL
	BOOST_CHECK(x != ev.stencil_back_fail);
# endif
# ifdef GL_STENCIL_BACK_FUNC
	BOOST_CHECK(x != ev.stencil_back_func);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_BLEND_EQUATION_ALPHA
	x = ev.blend_equation_alpha;
	BOOST_CHECK(x == ev.blend_equation_alpha);
# ifdef GL_BLEND_EQUATION_RGB
	BOOST_CHECK(x != ev.blend_equation_rgb);
# endif
# ifdef GL_BLEND_SRC_ALPHA
	BOOST_CHECK(x != ev.blend_src_alpha);
# endif
# ifdef GL_BLEND_SRC_RGB
	BOOST_CHECK(x != ev.blend_src_rgb);
# endif
# ifdef GL_COLOR_CLEAR_VALUE
	BOOST_CHECK(x != ev.color_clear_value);
# endif
# ifdef GL_COLOR_WRITEMASK
	BOOST_CHECK(x != ev.color_writemask);
# endif
# ifdef GL_COMPRESSED_TEXTURE_FORMATS
	BOOST_CHECK(x != ev.compressed_texture_formats);
# endif
# ifdef GL_CONTEXT_FLAGS
	BOOST_CHECK(x != ev.context_flags);
# endif
# ifdef GL_DEBUG_GROUP_STACK_DEPTH
	BOOST_CHECK(x != ev.debug_group_stack_depth);
# endif
# ifdef GL_DEPTH_CLEAR_VALUE
	BOOST_CHECK(x != ev.depth_clear_value);
# endif
# ifdef GL_DEPTH_FUNC
	BOOST_CHECK(x != ev.depth_func);
# endif
# ifdef GL_DEPTH_RANGE
	BOOST_CHECK(x != ev.depth_range);
# endif
# ifdef GL_DEPTH_WRITEMASK
	BOOST_CHECK(x != ev.depth_writemask);
# endif
# ifdef GL_DOUBLEBUFFER
	BOOST_CHECK(x != ev.doublebuffer);
# endif
# ifdef GL_DRAW_BUFFER
	BOOST_CHECK(x != ev.draw_buffer);
# endif
# ifdef GL_FRAGMENT_SHADER_DERIVATIVE_HINT
	BOOST_CHECK(x != ev.fragment_shader_derivative_hint);
# endif
# ifdef GL_IMPLEMENTATION_COLOR_READ_FORMAT
	BOOST_CHECK(x != ev.implementation_color_read_format);
# endif
# ifdef GL_IMPLEMENTATION_COLOR_READ_TYPE
	BOOST_CHECK(x != ev.implementation_color_read_type);
# endif
# ifdef GL_LAYER_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.layer_provoking_vertex);
# endif
# ifdef GL_LINE_SMOOTH_HINT
	BOOST_CHECK(x != ev.line_smooth_hint);
# endif
# ifdef GL_LINE_WIDTH
	BOOST_CHECK(x != ev.line_width);
# endif
# ifdef GL_LOGIC_OP_MODE
	BOOST_CHECK(x != ev.logic_op_mode);
# endif
# ifdef GL_NUM_COMPRESSED_TEXTURE_FORMATS
	BOOST_CHECK(x != ev.num_compressed_texture_formats);
# endif
# ifdef GL_NUM_EXTENSIONS
	BOOST_CHECK(x != ev.num_extensions);
# endif
# ifdef GL_NUM_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.num_program_binary_formats);
# endif
# ifdef GL_NUM_SHADER_BINARY_FORMATS
	BOOST_CHECK(x != ev.num_shader_binary_formats);
# endif
# ifdef GL_PACK_ALIGNMENT
	BOOST_CHECK(x != ev.pack_alignment);
# endif
# ifdef GL_PACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.pack_image_height);
# endif
# ifdef GL_PACK_LSB_FIRST
	BOOST_CHECK(x != ev.pack_lsb_first);
# endif
# ifdef GL_PACK_ROW_LENGTH
	BOOST_CHECK(x != ev.pack_row_length);
# endif
# ifdef GL_PACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.pack_skip_images);
# endif
# ifdef GL_PACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.pack_skip_pixels);
# endif
# ifdef GL_PACK_SKIP_ROWS
	BOOST_CHECK(x != ev.pack_skip_rows);
# endif
# ifdef GL_PACK_SWAP_BYTES
	BOOST_CHECK(x != ev.pack_swap_bytes);
# endif
# ifdef GL_POINT_FADE_THRESHOLD_SIZE
	BOOST_CHECK(x != ev.point_fade_threshold_size);
# endif
# ifdef GL_POINT_SIZE
	BOOST_CHECK(x != ev.point_size);
# endif
# ifdef GL_POINT_SIZE_GRANULARITY
	BOOST_CHECK(x != ev.point_size_granularity);
# endif
# ifdef GL_POINT_SIZE_RANGE
	BOOST_CHECK(x != ev.point_size_range);
# endif
# ifdef GL_POLYGON_OFFSET_FACTOR
	BOOST_CHECK(x != ev.polygon_offset_factor);
# endif
# ifdef GL_POLYGON_OFFSET_UNITS
	BOOST_CHECK(x != ev.polygon_offset_units);
# endif
# ifdef GL_POLYGON_SMOOTH_HINT
	BOOST_CHECK(x != ev.polygon_smooth_hint);
# endif
# ifdef GL_PRIMITIVE_RESTART_INDEX
	BOOST_CHECK(x != ev.primitive_restart_index);
# endif
# ifdef GL_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.program_binary_formats);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.provoking_vertex);
# endif
# ifdef GL_READ_BUFFER
	BOOST_CHECK(x != ev.read_buffer);
# endif
# ifdef GL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef GL_SAMPLE_COVERAGE_INVERT
	BOOST_CHECK(x != ev.sample_coverage_invert);
# endif
# ifdef GL_SAMPLE_COVERAGE_VALUE
	BOOST_CHECK(x != ev.sample_coverage_value);
# endif
# ifdef GL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef GL_SCISSOR_BOX
	BOOST_CHECK(x != ev.scissor_box);
# endif
# ifdef GL_SHADER_COMPILER
	BOOST_CHECK(x != ev.shader_compiler);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.shader_storage_buffer_offset_alignment);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_SIZE
	BOOST_CHECK(x != ev.shader_storage_buffer_size);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_START
	BOOST_CHECK(x != ev.shader_storage_buffer_start);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	BOOST_CHECK(x != ev.smooth_line_width_granularity);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	BOOST_CHECK(x != ev.smooth_line_width_range);
# endif
# ifdef GL_STENCIL_BACK_FAIL
	BOOST_CHECK(x != ev.stencil_back_fail);
# endif
# ifdef GL_STENCIL_BACK_FUNC
	BOOST_CHECK(x != ev.stencil_back_func);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_BLEND_EQUATION_RGB
	x = ev.blend_equation_rgb;
	BOOST_CHECK(x == ev.blend_equation_rgb);
# ifdef GL_BLEND_SRC_ALPHA
	BOOST_CHECK(x != ev.blend_src_alpha);
# endif
# ifdef GL_BLEND_SRC_RGB
	BOOST_CHECK(x != ev.blend_src_rgb);
# endif
# ifdef GL_COLOR_CLEAR_VALUE
	BOOST_CHECK(x != ev.color_clear_value);
# endif
# ifdef GL_COLOR_WRITEMASK
	BOOST_CHECK(x != ev.color_writemask);
# endif
# ifdef GL_COMPRESSED_TEXTURE_FORMATS
	BOOST_CHECK(x != ev.compressed_texture_formats);
# endif
# ifdef GL_CONTEXT_FLAGS
	BOOST_CHECK(x != ev.context_flags);
# endif
# ifdef GL_DEBUG_GROUP_STACK_DEPTH
	BOOST_CHECK(x != ev.debug_group_stack_depth);
# endif
# ifdef GL_DEPTH_CLEAR_VALUE
	BOOST_CHECK(x != ev.depth_clear_value);
# endif
# ifdef GL_DEPTH_FUNC
	BOOST_CHECK(x != ev.depth_func);
# endif
# ifdef GL_DEPTH_RANGE
	BOOST_CHECK(x != ev.depth_range);
# endif
# ifdef GL_DEPTH_WRITEMASK
	BOOST_CHECK(x != ev.depth_writemask);
# endif
# ifdef GL_DOUBLEBUFFER
	BOOST_CHECK(x != ev.doublebuffer);
# endif
# ifdef GL_DRAW_BUFFER
	BOOST_CHECK(x != ev.draw_buffer);
# endif
# ifdef GL_FRAGMENT_SHADER_DERIVATIVE_HINT
	BOOST_CHECK(x != ev.fragment_shader_derivative_hint);
# endif
# ifdef GL_IMPLEMENTATION_COLOR_READ_FORMAT
	BOOST_CHECK(x != ev.implementation_color_read_format);
# endif
# ifdef GL_IMPLEMENTATION_COLOR_READ_TYPE
	BOOST_CHECK(x != ev.implementation_color_read_type);
# endif
# ifdef GL_LAYER_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.layer_provoking_vertex);
# endif
# ifdef GL_LINE_SMOOTH_HINT
	BOOST_CHECK(x != ev.line_smooth_hint);
# endif
# ifdef GL_LINE_WIDTH
	BOOST_CHECK(x != ev.line_width);
# endif
# ifdef GL_LOGIC_OP_MODE
	BOOST_CHECK(x != ev.logic_op_mode);
# endif
# ifdef GL_NUM_COMPRESSED_TEXTURE_FORMATS
	BOOST_CHECK(x != ev.num_compressed_texture_formats);
# endif
# ifdef GL_NUM_EXTENSIONS
	BOOST_CHECK(x != ev.num_extensions);
# endif
# ifdef GL_NUM_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.num_program_binary_formats);
# endif
# ifdef GL_NUM_SHADER_BINARY_FORMATS
	BOOST_CHECK(x != ev.num_shader_binary_formats);
# endif
# ifdef GL_PACK_ALIGNMENT
	BOOST_CHECK(x != ev.pack_alignment);
# endif
# ifdef GL_PACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.pack_image_height);
# endif
# ifdef GL_PACK_LSB_FIRST
	BOOST_CHECK(x != ev.pack_lsb_first);
# endif
# ifdef GL_PACK_ROW_LENGTH
	BOOST_CHECK(x != ev.pack_row_length);
# endif
# ifdef GL_PACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.pack_skip_images);
# endif
# ifdef GL_PACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.pack_skip_pixels);
# endif
# ifdef GL_PACK_SKIP_ROWS
	BOOST_CHECK(x != ev.pack_skip_rows);
# endif
# ifdef GL_PACK_SWAP_BYTES
	BOOST_CHECK(x != ev.pack_swap_bytes);
# endif
# ifdef GL_POINT_FADE_THRESHOLD_SIZE
	BOOST_CHECK(x != ev.point_fade_threshold_size);
# endif
# ifdef GL_POINT_SIZE
	BOOST_CHECK(x != ev.point_size);
# endif
# ifdef GL_POINT_SIZE_GRANULARITY
	BOOST_CHECK(x != ev.point_size_granularity);
# endif
# ifdef GL_POINT_SIZE_RANGE
	BOOST_CHECK(x != ev.point_size_range);
# endif
# ifdef GL_POLYGON_OFFSET_FACTOR
	BOOST_CHECK(x != ev.polygon_offset_factor);
# endif
# ifdef GL_POLYGON_OFFSET_UNITS
	BOOST_CHECK(x != ev.polygon_offset_units);
# endif
# ifdef GL_POLYGON_SMOOTH_HINT
	BOOST_CHECK(x != ev.polygon_smooth_hint);
# endif
# ifdef GL_PRIMITIVE_RESTART_INDEX
	BOOST_CHECK(x != ev.primitive_restart_index);
# endif
# ifdef GL_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.program_binary_formats);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.provoking_vertex);
# endif
# ifdef GL_READ_BUFFER
	BOOST_CHECK(x != ev.read_buffer);
# endif
# ifdef GL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef GL_SAMPLE_COVERAGE_INVERT
	BOOST_CHECK(x != ev.sample_coverage_invert);
# endif
# ifdef GL_SAMPLE_COVERAGE_VALUE
	BOOST_CHECK(x != ev.sample_coverage_value);
# endif
# ifdef GL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef GL_SCISSOR_BOX
	BOOST_CHECK(x != ev.scissor_box);
# endif
# ifdef GL_SHADER_COMPILER
	BOOST_CHECK(x != ev.shader_compiler);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.shader_storage_buffer_offset_alignment);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_SIZE
	BOOST_CHECK(x != ev.shader_storage_buffer_size);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_START
	BOOST_CHECK(x != ev.shader_storage_buffer_start);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	BOOST_CHECK(x != ev.smooth_line_width_granularity);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	BOOST_CHECK(x != ev.smooth_line_width_range);
# endif
# ifdef GL_STENCIL_BACK_FAIL
	BOOST_CHECK(x != ev.stencil_back_fail);
# endif
# ifdef GL_STENCIL_BACK_FUNC
	BOOST_CHECK(x != ev.stencil_back_func);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_BLEND_SRC_ALPHA
	x = ev.blend_src_alpha;
	BOOST_CHECK(x == ev.blend_src_alpha);
# ifdef GL_BLEND_SRC_RGB
	BOOST_CHECK(x != ev.blend_src_rgb);
# endif
# ifdef GL_COLOR_CLEAR_VALUE
	BOOST_CHECK(x != ev.color_clear_value);
# endif
# ifdef GL_COLOR_WRITEMASK
	BOOST_CHECK(x != ev.color_writemask);
# endif
# ifdef GL_COMPRESSED_TEXTURE_FORMATS
	BOOST_CHECK(x != ev.compressed_texture_formats);
# endif
# ifdef GL_CONTEXT_FLAGS
	BOOST_CHECK(x != ev.context_flags);
# endif
# ifdef GL_DEBUG_GROUP_STACK_DEPTH
	BOOST_CHECK(x != ev.debug_group_stack_depth);
# endif
# ifdef GL_DEPTH_CLEAR_VALUE
	BOOST_CHECK(x != ev.depth_clear_value);
# endif
# ifdef GL_DEPTH_FUNC
	BOOST_CHECK(x != ev.depth_func);
# endif
# ifdef GL_DEPTH_RANGE
	BOOST_CHECK(x != ev.depth_range);
# endif
# ifdef GL_DEPTH_WRITEMASK
	BOOST_CHECK(x != ev.depth_writemask);
# endif
# ifdef GL_DOUBLEBUFFER
	BOOST_CHECK(x != ev.doublebuffer);
# endif
# ifdef GL_DRAW_BUFFER
	BOOST_CHECK(x != ev.draw_buffer);
# endif
# ifdef GL_FRAGMENT_SHADER_DERIVATIVE_HINT
	BOOST_CHECK(x != ev.fragment_shader_derivative_hint);
# endif
# ifdef GL_IMPLEMENTATION_COLOR_READ_FORMAT
	BOOST_CHECK(x != ev.implementation_color_read_format);
# endif
# ifdef GL_IMPLEMENTATION_COLOR_READ_TYPE
	BOOST_CHECK(x != ev.implementation_color_read_type);
# endif
# ifdef GL_LAYER_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.layer_provoking_vertex);
# endif
# ifdef GL_LINE_SMOOTH_HINT
	BOOST_CHECK(x != ev.line_smooth_hint);
# endif
# ifdef GL_LINE_WIDTH
	BOOST_CHECK(x != ev.line_width);
# endif
# ifdef GL_LOGIC_OP_MODE
	BOOST_CHECK(x != ev.logic_op_mode);
# endif
# ifdef GL_NUM_COMPRESSED_TEXTURE_FORMATS
	BOOST_CHECK(x != ev.num_compressed_texture_formats);
# endif
# ifdef GL_NUM_EXTENSIONS
	BOOST_CHECK(x != ev.num_extensions);
# endif
# ifdef GL_NUM_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.num_program_binary_formats);
# endif
# ifdef GL_NUM_SHADER_BINARY_FORMATS
	BOOST_CHECK(x != ev.num_shader_binary_formats);
# endif
# ifdef GL_PACK_ALIGNMENT
	BOOST_CHECK(x != ev.pack_alignment);
# endif
# ifdef GL_PACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.pack_image_height);
# endif
# ifdef GL_PACK_LSB_FIRST
	BOOST_CHECK(x != ev.pack_lsb_first);
# endif
# ifdef GL_PACK_ROW_LENGTH
	BOOST_CHECK(x != ev.pack_row_length);
# endif
# ifdef GL_PACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.pack_skip_images);
# endif
# ifdef GL_PACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.pack_skip_pixels);
# endif
# ifdef GL_PACK_SKIP_ROWS
	BOOST_CHECK(x != ev.pack_skip_rows);
# endif
# ifdef GL_PACK_SWAP_BYTES
	BOOST_CHECK(x != ev.pack_swap_bytes);
# endif
# ifdef GL_POINT_FADE_THRESHOLD_SIZE
	BOOST_CHECK(x != ev.point_fade_threshold_size);
# endif
# ifdef GL_POINT_SIZE
	BOOST_CHECK(x != ev.point_size);
# endif
# ifdef GL_POINT_SIZE_GRANULARITY
	BOOST_CHECK(x != ev.point_size_granularity);
# endif
# ifdef GL_POINT_SIZE_RANGE
	BOOST_CHECK(x != ev.point_size_range);
# endif
# ifdef GL_POLYGON_OFFSET_FACTOR
	BOOST_CHECK(x != ev.polygon_offset_factor);
# endif
# ifdef GL_POLYGON_OFFSET_UNITS
	BOOST_CHECK(x != ev.polygon_offset_units);
# endif
# ifdef GL_POLYGON_SMOOTH_HINT
	BOOST_CHECK(x != ev.polygon_smooth_hint);
# endif
# ifdef GL_PRIMITIVE_RESTART_INDEX
	BOOST_CHECK(x != ev.primitive_restart_index);
# endif
# ifdef GL_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.program_binary_formats);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.provoking_vertex);
# endif
# ifdef GL_READ_BUFFER
	BOOST_CHECK(x != ev.read_buffer);
# endif
# ifdef GL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef GL_SAMPLE_COVERAGE_INVERT
	BOOST_CHECK(x != ev.sample_coverage_invert);
# endif
# ifdef GL_SAMPLE_COVERAGE_VALUE
	BOOST_CHECK(x != ev.sample_coverage_value);
# endif
# ifdef GL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef GL_SCISSOR_BOX
	BOOST_CHECK(x != ev.scissor_box);
# endif
# ifdef GL_SHADER_COMPILER
	BOOST_CHECK(x != ev.shader_compiler);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.shader_storage_buffer_offset_alignment);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_SIZE
	BOOST_CHECK(x != ev.shader_storage_buffer_size);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_START
	BOOST_CHECK(x != ev.shader_storage_buffer_start);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	BOOST_CHECK(x != ev.smooth_line_width_granularity);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	BOOST_CHECK(x != ev.smooth_line_width_range);
# endif
# ifdef GL_STENCIL_BACK_FAIL
	BOOST_CHECK(x != ev.stencil_back_fail);
# endif
# ifdef GL_STENCIL_BACK_FUNC
	BOOST_CHECK(x != ev.stencil_back_func);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_BLEND_SRC_RGB
	x = ev.blend_src_rgb;
	BOOST_CHECK(x == ev.blend_src_rgb);
# ifdef GL_COLOR_CLEAR_VALUE
	BOOST_CHECK(x != ev.color_clear_value);
# endif
# ifdef GL_COLOR_WRITEMASK
	BOOST_CHECK(x != ev.color_writemask);
# endif
# ifdef GL_COMPRESSED_TEXTURE_FORMATS
	BOOST_CHECK(x != ev.compressed_texture_formats);
# endif
# ifdef GL_CONTEXT_FLAGS
	BOOST_CHECK(x != ev.context_flags);
# endif
# ifdef GL_DEBUG_GROUP_STACK_DEPTH
	BOOST_CHECK(x != ev.debug_group_stack_depth);
# endif
# ifdef GL_DEPTH_CLEAR_VALUE
	BOOST_CHECK(x != ev.depth_clear_value);
# endif
# ifdef GL_DEPTH_FUNC
	BOOST_CHECK(x != ev.depth_func);
# endif
# ifdef GL_DEPTH_RANGE
	BOOST_CHECK(x != ev.depth_range);
# endif
# ifdef GL_DEPTH_WRITEMASK
	BOOST_CHECK(x != ev.depth_writemask);
# endif
# ifdef GL_DOUBLEBUFFER
	BOOST_CHECK(x != ev.doublebuffer);
# endif
# ifdef GL_DRAW_BUFFER
	BOOST_CHECK(x != ev.draw_buffer);
# endif
# ifdef GL_FRAGMENT_SHADER_DERIVATIVE_HINT
	BOOST_CHECK(x != ev.fragment_shader_derivative_hint);
# endif
# ifdef GL_IMPLEMENTATION_COLOR_READ_FORMAT
	BOOST_CHECK(x != ev.implementation_color_read_format);
# endif
# ifdef GL_IMPLEMENTATION_COLOR_READ_TYPE
	BOOST_CHECK(x != ev.implementation_color_read_type);
# endif
# ifdef GL_LAYER_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.layer_provoking_vertex);
# endif
# ifdef GL_LINE_SMOOTH_HINT
	BOOST_CHECK(x != ev.line_smooth_hint);
# endif
# ifdef GL_LINE_WIDTH
	BOOST_CHECK(x != ev.line_width);
# endif
# ifdef GL_LOGIC_OP_MODE
	BOOST_CHECK(x != ev.logic_op_mode);
# endif
# ifdef GL_NUM_COMPRESSED_TEXTURE_FORMATS
	BOOST_CHECK(x != ev.num_compressed_texture_formats);
# endif
# ifdef GL_NUM_EXTENSIONS
	BOOST_CHECK(x != ev.num_extensions);
# endif
# ifdef GL_NUM_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.num_program_binary_formats);
# endif
# ifdef GL_NUM_SHADER_BINARY_FORMATS
	BOOST_CHECK(x != ev.num_shader_binary_formats);
# endif
# ifdef GL_PACK_ALIGNMENT
	BOOST_CHECK(x != ev.pack_alignment);
# endif
# ifdef GL_PACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.pack_image_height);
# endif
# ifdef GL_PACK_LSB_FIRST
	BOOST_CHECK(x != ev.pack_lsb_first);
# endif
# ifdef GL_PACK_ROW_LENGTH
	BOOST_CHECK(x != ev.pack_row_length);
# endif
# ifdef GL_PACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.pack_skip_images);
# endif
# ifdef GL_PACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.pack_skip_pixels);
# endif
# ifdef GL_PACK_SKIP_ROWS
	BOOST_CHECK(x != ev.pack_skip_rows);
# endif
# ifdef GL_PACK_SWAP_BYTES
	BOOST_CHECK(x != ev.pack_swap_bytes);
# endif
# ifdef GL_POINT_FADE_THRESHOLD_SIZE
	BOOST_CHECK(x != ev.point_fade_threshold_size);
# endif
# ifdef GL_POINT_SIZE
	BOOST_CHECK(x != ev.point_size);
# endif
# ifdef GL_POINT_SIZE_GRANULARITY
	BOOST_CHECK(x != ev.point_size_granularity);
# endif
# ifdef GL_POINT_SIZE_RANGE
	BOOST_CHECK(x != ev.point_size_range);
# endif
# ifdef GL_POLYGON_OFFSET_FACTOR
	BOOST_CHECK(x != ev.polygon_offset_factor);
# endif
# ifdef GL_POLYGON_OFFSET_UNITS
	BOOST_CHECK(x != ev.polygon_offset_units);
# endif
# ifdef GL_POLYGON_SMOOTH_HINT
	BOOST_CHECK(x != ev.polygon_smooth_hint);
# endif
# ifdef GL_PRIMITIVE_RESTART_INDEX
	BOOST_CHECK(x != ev.primitive_restart_index);
# endif
# ifdef GL_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.program_binary_formats);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.provoking_vertex);
# endif
# ifdef GL_READ_BUFFER
	BOOST_CHECK(x != ev.read_buffer);
# endif
# ifdef GL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef GL_SAMPLE_COVERAGE_INVERT
	BOOST_CHECK(x != ev.sample_coverage_invert);
# endif
# ifdef GL_SAMPLE_COVERAGE_VALUE
	BOOST_CHECK(x != ev.sample_coverage_value);
# endif
# ifdef GL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef GL_SCISSOR_BOX
	BOOST_CHECK(x != ev.scissor_box);
# endif
# ifdef GL_SHADER_COMPILER
	BOOST_CHECK(x != ev.shader_compiler);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.shader_storage_buffer_offset_alignment);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_SIZE
	BOOST_CHECK(x != ev.shader_storage_buffer_size);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_START
	BOOST_CHECK(x != ev.shader_storage_buffer_start);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	BOOST_CHECK(x != ev.smooth_line_width_granularity);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	BOOST_CHECK(x != ev.smooth_line_width_range);
# endif
# ifdef GL_STENCIL_BACK_FAIL
	BOOST_CHECK(x != ev.stencil_back_fail);
# endif
# ifdef GL_STENCIL_BACK_FUNC
	BOOST_CHECK(x != ev.stencil_back_func);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_COLOR_CLEAR_VALUE
	x = ev.color_clear_value;
	BOOST_CHECK(x == ev.color_clear_value);
# ifdef GL_COLOR_WRITEMASK
	BOOST_CHECK(x != ev.color_writemask);
# endif
# ifdef GL_COMPRESSED_TEXTURE_FORMATS
	BOOST_CHECK(x != ev.compressed_texture_formats);
# endif
# ifdef GL_CONTEXT_FLAGS
	BOOST_CHECK(x != ev.context_flags);
# endif
# ifdef GL_DEBUG_GROUP_STACK_DEPTH
	BOOST_CHECK(x != ev.debug_group_stack_depth);
# endif
# ifdef GL_DEPTH_CLEAR_VALUE
	BOOST_CHECK(x != ev.depth_clear_value);
# endif
# ifdef GL_DEPTH_FUNC
	BOOST_CHECK(x != ev.depth_func);
# endif
# ifdef GL_DEPTH_RANGE
	BOOST_CHECK(x != ev.depth_range);
# endif
# ifdef GL_DEPTH_WRITEMASK
	BOOST_CHECK(x != ev.depth_writemask);
# endif
# ifdef GL_DOUBLEBUFFER
	BOOST_CHECK(x != ev.doublebuffer);
# endif
# ifdef GL_DRAW_BUFFER
	BOOST_CHECK(x != ev.draw_buffer);
# endif
# ifdef GL_FRAGMENT_SHADER_DERIVATIVE_HINT
	BOOST_CHECK(x != ev.fragment_shader_derivative_hint);
# endif
# ifdef GL_IMPLEMENTATION_COLOR_READ_FORMAT
	BOOST_CHECK(x != ev.implementation_color_read_format);
# endif
# ifdef GL_IMPLEMENTATION_COLOR_READ_TYPE
	BOOST_CHECK(x != ev.implementation_color_read_type);
# endif
# ifdef GL_LAYER_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.layer_provoking_vertex);
# endif
# ifdef GL_LINE_SMOOTH_HINT
	BOOST_CHECK(x != ev.line_smooth_hint);
# endif
# ifdef GL_LINE_WIDTH
	BOOST_CHECK(x != ev.line_width);
# endif
# ifdef GL_LOGIC_OP_MODE
	BOOST_CHECK(x != ev.logic_op_mode);
# endif
# ifdef GL_NUM_COMPRESSED_TEXTURE_FORMATS
	BOOST_CHECK(x != ev.num_compressed_texture_formats);
# endif
# ifdef GL_NUM_EXTENSIONS
	BOOST_CHECK(x != ev.num_extensions);
# endif
# ifdef GL_NUM_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.num_program_binary_formats);
# endif
# ifdef GL_NUM_SHADER_BINARY_FORMATS
	BOOST_CHECK(x != ev.num_shader_binary_formats);
# endif
# ifdef GL_PACK_ALIGNMENT
	BOOST_CHECK(x != ev.pack_alignment);
# endif
# ifdef GL_PACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.pack_image_height);
# endif
# ifdef GL_PACK_LSB_FIRST
	BOOST_CHECK(x != ev.pack_lsb_first);
# endif
# ifdef GL_PACK_ROW_LENGTH
	BOOST_CHECK(x != ev.pack_row_length);
# endif
# ifdef GL_PACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.pack_skip_images);
# endif
# ifdef GL_PACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.pack_skip_pixels);
# endif
# ifdef GL_PACK_SKIP_ROWS
	BOOST_CHECK(x != ev.pack_skip_rows);
# endif
# ifdef GL_PACK_SWAP_BYTES
	BOOST_CHECK(x != ev.pack_swap_bytes);
# endif
# ifdef GL_POINT_FADE_THRESHOLD_SIZE
	BOOST_CHECK(x != ev.point_fade_threshold_size);
# endif
# ifdef GL_POINT_SIZE
	BOOST_CHECK(x != ev.point_size);
# endif
# ifdef GL_POINT_SIZE_GRANULARITY
	BOOST_CHECK(x != ev.point_size_granularity);
# endif
# ifdef GL_POINT_SIZE_RANGE
	BOOST_CHECK(x != ev.point_size_range);
# endif
# ifdef GL_POLYGON_OFFSET_FACTOR
	BOOST_CHECK(x != ev.polygon_offset_factor);
# endif
# ifdef GL_POLYGON_OFFSET_UNITS
	BOOST_CHECK(x != ev.polygon_offset_units);
# endif
# ifdef GL_POLYGON_SMOOTH_HINT
	BOOST_CHECK(x != ev.polygon_smooth_hint);
# endif
# ifdef GL_PRIMITIVE_RESTART_INDEX
	BOOST_CHECK(x != ev.primitive_restart_index);
# endif
# ifdef GL_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.program_binary_formats);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.provoking_vertex);
# endif
# ifdef GL_READ_BUFFER
	BOOST_CHECK(x != ev.read_buffer);
# endif
# ifdef GL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef GL_SAMPLE_COVERAGE_INVERT
	BOOST_CHECK(x != ev.sample_coverage_invert);
# endif
# ifdef GL_SAMPLE_COVERAGE_VALUE
	BOOST_CHECK(x != ev.sample_coverage_value);
# endif
# ifdef GL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef GL_SCISSOR_BOX
	BOOST_CHECK(x != ev.scissor_box);
# endif
# ifdef GL_SHADER_COMPILER
	BOOST_CHECK(x != ev.shader_compiler);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.shader_storage_buffer_offset_alignment);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_SIZE
	BOOST_CHECK(x != ev.shader_storage_buffer_size);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_START
	BOOST_CHECK(x != ev.shader_storage_buffer_start);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	BOOST_CHECK(x != ev.smooth_line_width_granularity);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	BOOST_CHECK(x != ev.smooth_line_width_range);
# endif
# ifdef GL_STENCIL_BACK_FAIL
	BOOST_CHECK(x != ev.stencil_back_fail);
# endif
# ifdef GL_STENCIL_BACK_FUNC
	BOOST_CHECK(x != ev.stencil_back_func);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_COLOR_WRITEMASK
	x = ev.color_writemask;
	BOOST_CHECK(x == ev.color_writemask);
# ifdef GL_COMPRESSED_TEXTURE_FORMATS
	BOOST_CHECK(x != ev.compressed_texture_formats);
# endif
# ifdef GL_CONTEXT_FLAGS
	BOOST_CHECK(x != ev.context_flags);
# endif
# ifdef GL_DEBUG_GROUP_STACK_DEPTH
	BOOST_CHECK(x != ev.debug_group_stack_depth);
# endif
# ifdef GL_DEPTH_CLEAR_VALUE
	BOOST_CHECK(x != ev.depth_clear_value);
# endif
# ifdef GL_DEPTH_FUNC
	BOOST_CHECK(x != ev.depth_func);
# endif
# ifdef GL_DEPTH_RANGE
	BOOST_CHECK(x != ev.depth_range);
# endif
# ifdef GL_DEPTH_WRITEMASK
	BOOST_CHECK(x != ev.depth_writemask);
# endif
# ifdef GL_DOUBLEBUFFER
	BOOST_CHECK(x != ev.doublebuffer);
# endif
# ifdef GL_DRAW_BUFFER
	BOOST_CHECK(x != ev.draw_buffer);
# endif
# ifdef GL_FRAGMENT_SHADER_DERIVATIVE_HINT
	BOOST_CHECK(x != ev.fragment_shader_derivative_hint);
# endif
# ifdef GL_IMPLEMENTATION_COLOR_READ_FORMAT
	BOOST_CHECK(x != ev.implementation_color_read_format);
# endif
# ifdef GL_IMPLEMENTATION_COLOR_READ_TYPE
	BOOST_CHECK(x != ev.implementation_color_read_type);
# endif
# ifdef GL_LAYER_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.layer_provoking_vertex);
# endif
# ifdef GL_LINE_SMOOTH_HINT
	BOOST_CHECK(x != ev.line_smooth_hint);
# endif
# ifdef GL_LINE_WIDTH
	BOOST_CHECK(x != ev.line_width);
# endif
# ifdef GL_LOGIC_OP_MODE
	BOOST_CHECK(x != ev.logic_op_mode);
# endif
# ifdef GL_NUM_COMPRESSED_TEXTURE_FORMATS
	BOOST_CHECK(x != ev.num_compressed_texture_formats);
# endif
# ifdef GL_NUM_EXTENSIONS
	BOOST_CHECK(x != ev.num_extensions);
# endif
# ifdef GL_NUM_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.num_program_binary_formats);
# endif
# ifdef GL_NUM_SHADER_BINARY_FORMATS
	BOOST_CHECK(x != ev.num_shader_binary_formats);
# endif
# ifdef GL_PACK_ALIGNMENT
	BOOST_CHECK(x != ev.pack_alignment);
# endif
# ifdef GL_PACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.pack_image_height);
# endif
# ifdef GL_PACK_LSB_FIRST
	BOOST_CHECK(x != ev.pack_lsb_first);
# endif
# ifdef GL_PACK_ROW_LENGTH
	BOOST_CHECK(x != ev.pack_row_length);
# endif
# ifdef GL_PACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.pack_skip_images);
# endif
# ifdef GL_PACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.pack_skip_pixels);
# endif
# ifdef GL_PACK_SKIP_ROWS
	BOOST_CHECK(x != ev.pack_skip_rows);
# endif
# ifdef GL_PACK_SWAP_BYTES
	BOOST_CHECK(x != ev.pack_swap_bytes);
# endif
# ifdef GL_POINT_FADE_THRESHOLD_SIZE
	BOOST_CHECK(x != ev.point_fade_threshold_size);
# endif
# ifdef GL_POINT_SIZE
	BOOST_CHECK(x != ev.point_size);
# endif
# ifdef GL_POINT_SIZE_GRANULARITY
	BOOST_CHECK(x != ev.point_size_granularity);
# endif
# ifdef GL_POINT_SIZE_RANGE
	BOOST_CHECK(x != ev.point_size_range);
# endif
# ifdef GL_POLYGON_OFFSET_FACTOR
	BOOST_CHECK(x != ev.polygon_offset_factor);
# endif
# ifdef GL_POLYGON_OFFSET_UNITS
	BOOST_CHECK(x != ev.polygon_offset_units);
# endif
# ifdef GL_POLYGON_SMOOTH_HINT
	BOOST_CHECK(x != ev.polygon_smooth_hint);
# endif
# ifdef GL_PRIMITIVE_RESTART_INDEX
	BOOST_CHECK(x != ev.primitive_restart_index);
# endif
# ifdef GL_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.program_binary_formats);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.provoking_vertex);
# endif
# ifdef GL_READ_BUFFER
	BOOST_CHECK(x != ev.read_buffer);
# endif
# ifdef GL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef GL_SAMPLE_COVERAGE_INVERT
	BOOST_CHECK(x != ev.sample_coverage_invert);
# endif
# ifdef GL_SAMPLE_COVERAGE_VALUE
	BOOST_CHECK(x != ev.sample_coverage_value);
# endif
# ifdef GL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef GL_SCISSOR_BOX
	BOOST_CHECK(x != ev.scissor_box);
# endif
# ifdef GL_SHADER_COMPILER
	BOOST_CHECK(x != ev.shader_compiler);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.shader_storage_buffer_offset_alignment);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_SIZE
	BOOST_CHECK(x != ev.shader_storage_buffer_size);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_START
	BOOST_CHECK(x != ev.shader_storage_buffer_start);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	BOOST_CHECK(x != ev.smooth_line_width_granularity);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	BOOST_CHECK(x != ev.smooth_line_width_range);
# endif
# ifdef GL_STENCIL_BACK_FAIL
	BOOST_CHECK(x != ev.stencil_back_fail);
# endif
# ifdef GL_STENCIL_BACK_FUNC
	BOOST_CHECK(x != ev.stencil_back_func);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_COMPRESSED_TEXTURE_FORMATS
	x = ev.compressed_texture_formats;
	BOOST_CHECK(x == ev.compressed_texture_formats);
# ifdef GL_CONTEXT_FLAGS
	BOOST_CHECK(x != ev.context_flags);
# endif
# ifdef GL_DEBUG_GROUP_STACK_DEPTH
	BOOST_CHECK(x != ev.debug_group_stack_depth);
# endif
# ifdef GL_DEPTH_CLEAR_VALUE
	BOOST_CHECK(x != ev.depth_clear_value);
# endif
# ifdef GL_DEPTH_FUNC
	BOOST_CHECK(x != ev.depth_func);
# endif
# ifdef GL_DEPTH_RANGE
	BOOST_CHECK(x != ev.depth_range);
# endif
# ifdef GL_DEPTH_WRITEMASK
	BOOST_CHECK(x != ev.depth_writemask);
# endif
# ifdef GL_DOUBLEBUFFER
	BOOST_CHECK(x != ev.doublebuffer);
# endif
# ifdef GL_DRAW_BUFFER
	BOOST_CHECK(x != ev.draw_buffer);
# endif
# ifdef GL_FRAGMENT_SHADER_DERIVATIVE_HINT
	BOOST_CHECK(x != ev.fragment_shader_derivative_hint);
# endif
# ifdef GL_IMPLEMENTATION_COLOR_READ_FORMAT
	BOOST_CHECK(x != ev.implementation_color_read_format);
# endif
# ifdef GL_IMPLEMENTATION_COLOR_READ_TYPE
	BOOST_CHECK(x != ev.implementation_color_read_type);
# endif
# ifdef GL_LAYER_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.layer_provoking_vertex);
# endif
# ifdef GL_LINE_SMOOTH_HINT
	BOOST_CHECK(x != ev.line_smooth_hint);
# endif
# ifdef GL_LINE_WIDTH
	BOOST_CHECK(x != ev.line_width);
# endif
# ifdef GL_LOGIC_OP_MODE
	BOOST_CHECK(x != ev.logic_op_mode);
# endif
# ifdef GL_NUM_COMPRESSED_TEXTURE_FORMATS
	BOOST_CHECK(x != ev.num_compressed_texture_formats);
# endif
# ifdef GL_NUM_EXTENSIONS
	BOOST_CHECK(x != ev.num_extensions);
# endif
# ifdef GL_NUM_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.num_program_binary_formats);
# endif
# ifdef GL_NUM_SHADER_BINARY_FORMATS
	BOOST_CHECK(x != ev.num_shader_binary_formats);
# endif
# ifdef GL_PACK_ALIGNMENT
	BOOST_CHECK(x != ev.pack_alignment);
# endif
# ifdef GL_PACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.pack_image_height);
# endif
# ifdef GL_PACK_LSB_FIRST
	BOOST_CHECK(x != ev.pack_lsb_first);
# endif
# ifdef GL_PACK_ROW_LENGTH
	BOOST_CHECK(x != ev.pack_row_length);
# endif
# ifdef GL_PACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.pack_skip_images);
# endif
# ifdef GL_PACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.pack_skip_pixels);
# endif
# ifdef GL_PACK_SKIP_ROWS
	BOOST_CHECK(x != ev.pack_skip_rows);
# endif
# ifdef GL_PACK_SWAP_BYTES
	BOOST_CHECK(x != ev.pack_swap_bytes);
# endif
# ifdef GL_POINT_FADE_THRESHOLD_SIZE
	BOOST_CHECK(x != ev.point_fade_threshold_size);
# endif
# ifdef GL_POINT_SIZE
	BOOST_CHECK(x != ev.point_size);
# endif
# ifdef GL_POINT_SIZE_GRANULARITY
	BOOST_CHECK(x != ev.point_size_granularity);
# endif
# ifdef GL_POINT_SIZE_RANGE
	BOOST_CHECK(x != ev.point_size_range);
# endif
# ifdef GL_POLYGON_OFFSET_FACTOR
	BOOST_CHECK(x != ev.polygon_offset_factor);
# endif
# ifdef GL_POLYGON_OFFSET_UNITS
	BOOST_CHECK(x != ev.polygon_offset_units);
# endif
# ifdef GL_POLYGON_SMOOTH_HINT
	BOOST_CHECK(x != ev.polygon_smooth_hint);
# endif
# ifdef GL_PRIMITIVE_RESTART_INDEX
	BOOST_CHECK(x != ev.primitive_restart_index);
# endif
# ifdef GL_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.program_binary_formats);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.provoking_vertex);
# endif
# ifdef GL_READ_BUFFER
	BOOST_CHECK(x != ev.read_buffer);
# endif
# ifdef GL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef GL_SAMPLE_COVERAGE_INVERT
	BOOST_CHECK(x != ev.sample_coverage_invert);
# endif
# ifdef GL_SAMPLE_COVERAGE_VALUE
	BOOST_CHECK(x != ev.sample_coverage_value);
# endif
# ifdef GL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef GL_SCISSOR_BOX
	BOOST_CHECK(x != ev.scissor_box);
# endif
# ifdef GL_SHADER_COMPILER
	BOOST_CHECK(x != ev.shader_compiler);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.shader_storage_buffer_offset_alignment);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_SIZE
	BOOST_CHECK(x != ev.shader_storage_buffer_size);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_START
	BOOST_CHECK(x != ev.shader_storage_buffer_start);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	BOOST_CHECK(x != ev.smooth_line_width_granularity);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	BOOST_CHECK(x != ev.smooth_line_width_range);
# endif
# ifdef GL_STENCIL_BACK_FAIL
	BOOST_CHECK(x != ev.stencil_back_fail);
# endif
# ifdef GL_STENCIL_BACK_FUNC
	BOOST_CHECK(x != ev.stencil_back_func);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_CONTEXT_FLAGS
	x = ev.context_flags;
	BOOST_CHECK(x == ev.context_flags);
# ifdef GL_DEBUG_GROUP_STACK_DEPTH
	BOOST_CHECK(x != ev.debug_group_stack_depth);
# endif
# ifdef GL_DEPTH_CLEAR_VALUE
	BOOST_CHECK(x != ev.depth_clear_value);
# endif
# ifdef GL_DEPTH_FUNC
	BOOST_CHECK(x != ev.depth_func);
# endif
# ifdef GL_DEPTH_RANGE
	BOOST_CHECK(x != ev.depth_range);
# endif
# ifdef GL_DEPTH_WRITEMASK
	BOOST_CHECK(x != ev.depth_writemask);
# endif
# ifdef GL_DOUBLEBUFFER
	BOOST_CHECK(x != ev.doublebuffer);
# endif
# ifdef GL_DRAW_BUFFER
	BOOST_CHECK(x != ev.draw_buffer);
# endif
# ifdef GL_FRAGMENT_SHADER_DERIVATIVE_HINT
	BOOST_CHECK(x != ev.fragment_shader_derivative_hint);
# endif
# ifdef GL_IMPLEMENTATION_COLOR_READ_FORMAT
	BOOST_CHECK(x != ev.implementation_color_read_format);
# endif
# ifdef GL_IMPLEMENTATION_COLOR_READ_TYPE
	BOOST_CHECK(x != ev.implementation_color_read_type);
# endif
# ifdef GL_LAYER_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.layer_provoking_vertex);
# endif
# ifdef GL_LINE_SMOOTH_HINT
	BOOST_CHECK(x != ev.line_smooth_hint);
# endif
# ifdef GL_LINE_WIDTH
	BOOST_CHECK(x != ev.line_width);
# endif
# ifdef GL_LOGIC_OP_MODE
	BOOST_CHECK(x != ev.logic_op_mode);
# endif
# ifdef GL_NUM_COMPRESSED_TEXTURE_FORMATS
	BOOST_CHECK(x != ev.num_compressed_texture_formats);
# endif
# ifdef GL_NUM_EXTENSIONS
	BOOST_CHECK(x != ev.num_extensions);
# endif
# ifdef GL_NUM_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.num_program_binary_formats);
# endif
# ifdef GL_NUM_SHADER_BINARY_FORMATS
	BOOST_CHECK(x != ev.num_shader_binary_formats);
# endif
# ifdef GL_PACK_ALIGNMENT
	BOOST_CHECK(x != ev.pack_alignment);
# endif
# ifdef GL_PACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.pack_image_height);
# endif
# ifdef GL_PACK_LSB_FIRST
	BOOST_CHECK(x != ev.pack_lsb_first);
# endif
# ifdef GL_PACK_ROW_LENGTH
	BOOST_CHECK(x != ev.pack_row_length);
# endif
# ifdef GL_PACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.pack_skip_images);
# endif
# ifdef GL_PACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.pack_skip_pixels);
# endif
# ifdef GL_PACK_SKIP_ROWS
	BOOST_CHECK(x != ev.pack_skip_rows);
# endif
# ifdef GL_PACK_SWAP_BYTES
	BOOST_CHECK(x != ev.pack_swap_bytes);
# endif
# ifdef GL_POINT_FADE_THRESHOLD_SIZE
	BOOST_CHECK(x != ev.point_fade_threshold_size);
# endif
# ifdef GL_POINT_SIZE
	BOOST_CHECK(x != ev.point_size);
# endif
# ifdef GL_POINT_SIZE_GRANULARITY
	BOOST_CHECK(x != ev.point_size_granularity);
# endif
# ifdef GL_POINT_SIZE_RANGE
	BOOST_CHECK(x != ev.point_size_range);
# endif
# ifdef GL_POLYGON_OFFSET_FACTOR
	BOOST_CHECK(x != ev.polygon_offset_factor);
# endif
# ifdef GL_POLYGON_OFFSET_UNITS
	BOOST_CHECK(x != ev.polygon_offset_units);
# endif
# ifdef GL_POLYGON_SMOOTH_HINT
	BOOST_CHECK(x != ev.polygon_smooth_hint);
# endif
# ifdef GL_PRIMITIVE_RESTART_INDEX
	BOOST_CHECK(x != ev.primitive_restart_index);
# endif
# ifdef GL_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.program_binary_formats);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.provoking_vertex);
# endif
# ifdef GL_READ_BUFFER
	BOOST_CHECK(x != ev.read_buffer);
# endif
# ifdef GL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef GL_SAMPLE_COVERAGE_INVERT
	BOOST_CHECK(x != ev.sample_coverage_invert);
# endif
# ifdef GL_SAMPLE_COVERAGE_VALUE
	BOOST_CHECK(x != ev.sample_coverage_value);
# endif
# ifdef GL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef GL_SCISSOR_BOX
	BOOST_CHECK(x != ev.scissor_box);
# endif
# ifdef GL_SHADER_COMPILER
	BOOST_CHECK(x != ev.shader_compiler);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.shader_storage_buffer_offset_alignment);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_SIZE
	BOOST_CHECK(x != ev.shader_storage_buffer_size);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_START
	BOOST_CHECK(x != ev.shader_storage_buffer_start);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	BOOST_CHECK(x != ev.smooth_line_width_granularity);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	BOOST_CHECK(x != ev.smooth_line_width_range);
# endif
# ifdef GL_STENCIL_BACK_FAIL
	BOOST_CHECK(x != ev.stencil_back_fail);
# endif
# ifdef GL_STENCIL_BACK_FUNC
	BOOST_CHECK(x != ev.stencil_back_func);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_DEBUG_GROUP_STACK_DEPTH
	x = ev.debug_group_stack_depth;
	BOOST_CHECK(x == ev.debug_group_stack_depth);
# ifdef GL_DEPTH_CLEAR_VALUE
	BOOST_CHECK(x != ev.depth_clear_value);
# endif
# ifdef GL_DEPTH_FUNC
	BOOST_CHECK(x != ev.depth_func);
# endif
# ifdef GL_DEPTH_RANGE
	BOOST_CHECK(x != ev.depth_range);
# endif
# ifdef GL_DEPTH_WRITEMASK
	BOOST_CHECK(x != ev.depth_writemask);
# endif
# ifdef GL_DOUBLEBUFFER
	BOOST_CHECK(x != ev.doublebuffer);
# endif
# ifdef GL_DRAW_BUFFER
	BOOST_CHECK(x != ev.draw_buffer);
# endif
# ifdef GL_FRAGMENT_SHADER_DERIVATIVE_HINT
	BOOST_CHECK(x != ev.fragment_shader_derivative_hint);
# endif
# ifdef GL_IMPLEMENTATION_COLOR_READ_FORMAT
	BOOST_CHECK(x != ev.implementation_color_read_format);
# endif
# ifdef GL_IMPLEMENTATION_COLOR_READ_TYPE
	BOOST_CHECK(x != ev.implementation_color_read_type);
# endif
# ifdef GL_LAYER_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.layer_provoking_vertex);
# endif
# ifdef GL_LINE_SMOOTH_HINT
	BOOST_CHECK(x != ev.line_smooth_hint);
# endif
# ifdef GL_LINE_WIDTH
	BOOST_CHECK(x != ev.line_width);
# endif
# ifdef GL_LOGIC_OP_MODE
	BOOST_CHECK(x != ev.logic_op_mode);
# endif
# ifdef GL_NUM_COMPRESSED_TEXTURE_FORMATS
	BOOST_CHECK(x != ev.num_compressed_texture_formats);
# endif
# ifdef GL_NUM_EXTENSIONS
	BOOST_CHECK(x != ev.num_extensions);
# endif
# ifdef GL_NUM_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.num_program_binary_formats);
# endif
# ifdef GL_NUM_SHADER_BINARY_FORMATS
	BOOST_CHECK(x != ev.num_shader_binary_formats);
# endif
# ifdef GL_PACK_ALIGNMENT
	BOOST_CHECK(x != ev.pack_alignment);
# endif
# ifdef GL_PACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.pack_image_height);
# endif
# ifdef GL_PACK_LSB_FIRST
	BOOST_CHECK(x != ev.pack_lsb_first);
# endif
# ifdef GL_PACK_ROW_LENGTH
	BOOST_CHECK(x != ev.pack_row_length);
# endif
# ifdef GL_PACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.pack_skip_images);
# endif
# ifdef GL_PACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.pack_skip_pixels);
# endif
# ifdef GL_PACK_SKIP_ROWS
	BOOST_CHECK(x != ev.pack_skip_rows);
# endif
# ifdef GL_PACK_SWAP_BYTES
	BOOST_CHECK(x != ev.pack_swap_bytes);
# endif
# ifdef GL_POINT_FADE_THRESHOLD_SIZE
	BOOST_CHECK(x != ev.point_fade_threshold_size);
# endif
# ifdef GL_POINT_SIZE
	BOOST_CHECK(x != ev.point_size);
# endif
# ifdef GL_POINT_SIZE_GRANULARITY
	BOOST_CHECK(x != ev.point_size_granularity);
# endif
# ifdef GL_POINT_SIZE_RANGE
	BOOST_CHECK(x != ev.point_size_range);
# endif
# ifdef GL_POLYGON_OFFSET_FACTOR
	BOOST_CHECK(x != ev.polygon_offset_factor);
# endif
# ifdef GL_POLYGON_OFFSET_UNITS
	BOOST_CHECK(x != ev.polygon_offset_units);
# endif
# ifdef GL_POLYGON_SMOOTH_HINT
	BOOST_CHECK(x != ev.polygon_smooth_hint);
# endif
# ifdef GL_PRIMITIVE_RESTART_INDEX
	BOOST_CHECK(x != ev.primitive_restart_index);
# endif
# ifdef GL_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.program_binary_formats);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.provoking_vertex);
# endif
# ifdef GL_READ_BUFFER
	BOOST_CHECK(x != ev.read_buffer);
# endif
# ifdef GL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef GL_SAMPLE_COVERAGE_INVERT
	BOOST_CHECK(x != ev.sample_coverage_invert);
# endif
# ifdef GL_SAMPLE_COVERAGE_VALUE
	BOOST_CHECK(x != ev.sample_coverage_value);
# endif
# ifdef GL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef GL_SCISSOR_BOX
	BOOST_CHECK(x != ev.scissor_box);
# endif
# ifdef GL_SHADER_COMPILER
	BOOST_CHECK(x != ev.shader_compiler);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.shader_storage_buffer_offset_alignment);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_SIZE
	BOOST_CHECK(x != ev.shader_storage_buffer_size);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_START
	BOOST_CHECK(x != ev.shader_storage_buffer_start);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	BOOST_CHECK(x != ev.smooth_line_width_granularity);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	BOOST_CHECK(x != ev.smooth_line_width_range);
# endif
# ifdef GL_STENCIL_BACK_FAIL
	BOOST_CHECK(x != ev.stencil_back_fail);
# endif
# ifdef GL_STENCIL_BACK_FUNC
	BOOST_CHECK(x != ev.stencil_back_func);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_DEPTH_CLEAR_VALUE
	x = ev.depth_clear_value;
	BOOST_CHECK(x == ev.depth_clear_value);
# ifdef GL_DEPTH_FUNC
	BOOST_CHECK(x != ev.depth_func);
# endif
# ifdef GL_DEPTH_RANGE
	BOOST_CHECK(x != ev.depth_range);
# endif
# ifdef GL_DEPTH_WRITEMASK
	BOOST_CHECK(x != ev.depth_writemask);
# endif
# ifdef GL_DOUBLEBUFFER
	BOOST_CHECK(x != ev.doublebuffer);
# endif
# ifdef GL_DRAW_BUFFER
	BOOST_CHECK(x != ev.draw_buffer);
# endif
# ifdef GL_FRAGMENT_SHADER_DERIVATIVE_HINT
	BOOST_CHECK(x != ev.fragment_shader_derivative_hint);
# endif
# ifdef GL_IMPLEMENTATION_COLOR_READ_FORMAT
	BOOST_CHECK(x != ev.implementation_color_read_format);
# endif
# ifdef GL_IMPLEMENTATION_COLOR_READ_TYPE
	BOOST_CHECK(x != ev.implementation_color_read_type);
# endif
# ifdef GL_LAYER_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.layer_provoking_vertex);
# endif
# ifdef GL_LINE_SMOOTH_HINT
	BOOST_CHECK(x != ev.line_smooth_hint);
# endif
# ifdef GL_LINE_WIDTH
	BOOST_CHECK(x != ev.line_width);
# endif
# ifdef GL_LOGIC_OP_MODE
	BOOST_CHECK(x != ev.logic_op_mode);
# endif
# ifdef GL_NUM_COMPRESSED_TEXTURE_FORMATS
	BOOST_CHECK(x != ev.num_compressed_texture_formats);
# endif
# ifdef GL_NUM_EXTENSIONS
	BOOST_CHECK(x != ev.num_extensions);
# endif
# ifdef GL_NUM_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.num_program_binary_formats);
# endif
# ifdef GL_NUM_SHADER_BINARY_FORMATS
	BOOST_CHECK(x != ev.num_shader_binary_formats);
# endif
# ifdef GL_PACK_ALIGNMENT
	BOOST_CHECK(x != ev.pack_alignment);
# endif
# ifdef GL_PACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.pack_image_height);
# endif
# ifdef GL_PACK_LSB_FIRST
	BOOST_CHECK(x != ev.pack_lsb_first);
# endif
# ifdef GL_PACK_ROW_LENGTH
	BOOST_CHECK(x != ev.pack_row_length);
# endif
# ifdef GL_PACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.pack_skip_images);
# endif
# ifdef GL_PACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.pack_skip_pixels);
# endif
# ifdef GL_PACK_SKIP_ROWS
	BOOST_CHECK(x != ev.pack_skip_rows);
# endif
# ifdef GL_PACK_SWAP_BYTES
	BOOST_CHECK(x != ev.pack_swap_bytes);
# endif
# ifdef GL_POINT_FADE_THRESHOLD_SIZE
	BOOST_CHECK(x != ev.point_fade_threshold_size);
# endif
# ifdef GL_POINT_SIZE
	BOOST_CHECK(x != ev.point_size);
# endif
# ifdef GL_POINT_SIZE_GRANULARITY
	BOOST_CHECK(x != ev.point_size_granularity);
# endif
# ifdef GL_POINT_SIZE_RANGE
	BOOST_CHECK(x != ev.point_size_range);
# endif
# ifdef GL_POLYGON_OFFSET_FACTOR
	BOOST_CHECK(x != ev.polygon_offset_factor);
# endif
# ifdef GL_POLYGON_OFFSET_UNITS
	BOOST_CHECK(x != ev.polygon_offset_units);
# endif
# ifdef GL_POLYGON_SMOOTH_HINT
	BOOST_CHECK(x != ev.polygon_smooth_hint);
# endif
# ifdef GL_PRIMITIVE_RESTART_INDEX
	BOOST_CHECK(x != ev.primitive_restart_index);
# endif
# ifdef GL_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.program_binary_formats);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.provoking_vertex);
# endif
# ifdef GL_READ_BUFFER
	BOOST_CHECK(x != ev.read_buffer);
# endif
# ifdef GL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef GL_SAMPLE_COVERAGE_INVERT
	BOOST_CHECK(x != ev.sample_coverage_invert);
# endif
# ifdef GL_SAMPLE_COVERAGE_VALUE
	BOOST_CHECK(x != ev.sample_coverage_value);
# endif
# ifdef GL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef GL_SCISSOR_BOX
	BOOST_CHECK(x != ev.scissor_box);
# endif
# ifdef GL_SHADER_COMPILER
	BOOST_CHECK(x != ev.shader_compiler);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.shader_storage_buffer_offset_alignment);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_SIZE
	BOOST_CHECK(x != ev.shader_storage_buffer_size);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_START
	BOOST_CHECK(x != ev.shader_storage_buffer_start);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	BOOST_CHECK(x != ev.smooth_line_width_granularity);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	BOOST_CHECK(x != ev.smooth_line_width_range);
# endif
# ifdef GL_STENCIL_BACK_FAIL
	BOOST_CHECK(x != ev.stencil_back_fail);
# endif
# ifdef GL_STENCIL_BACK_FUNC
	BOOST_CHECK(x != ev.stencil_back_func);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_DEPTH_FUNC
	x = ev.depth_func;
	BOOST_CHECK(x == ev.depth_func);
# ifdef GL_DEPTH_RANGE
	BOOST_CHECK(x != ev.depth_range);
# endif
# ifdef GL_DEPTH_WRITEMASK
	BOOST_CHECK(x != ev.depth_writemask);
# endif
# ifdef GL_DOUBLEBUFFER
	BOOST_CHECK(x != ev.doublebuffer);
# endif
# ifdef GL_DRAW_BUFFER
	BOOST_CHECK(x != ev.draw_buffer);
# endif
# ifdef GL_FRAGMENT_SHADER_DERIVATIVE_HINT
	BOOST_CHECK(x != ev.fragment_shader_derivative_hint);
# endif
# ifdef GL_IMPLEMENTATION_COLOR_READ_FORMAT
	BOOST_CHECK(x != ev.implementation_color_read_format);
# endif
# ifdef GL_IMPLEMENTATION_COLOR_READ_TYPE
	BOOST_CHECK(x != ev.implementation_color_read_type);
# endif
# ifdef GL_LAYER_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.layer_provoking_vertex);
# endif
# ifdef GL_LINE_SMOOTH_HINT
	BOOST_CHECK(x != ev.line_smooth_hint);
# endif
# ifdef GL_LINE_WIDTH
	BOOST_CHECK(x != ev.line_width);
# endif
# ifdef GL_LOGIC_OP_MODE
	BOOST_CHECK(x != ev.logic_op_mode);
# endif
# ifdef GL_NUM_COMPRESSED_TEXTURE_FORMATS
	BOOST_CHECK(x != ev.num_compressed_texture_formats);
# endif
# ifdef GL_NUM_EXTENSIONS
	BOOST_CHECK(x != ev.num_extensions);
# endif
# ifdef GL_NUM_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.num_program_binary_formats);
# endif
# ifdef GL_NUM_SHADER_BINARY_FORMATS
	BOOST_CHECK(x != ev.num_shader_binary_formats);
# endif
# ifdef GL_PACK_ALIGNMENT
	BOOST_CHECK(x != ev.pack_alignment);
# endif
# ifdef GL_PACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.pack_image_height);
# endif
# ifdef GL_PACK_LSB_FIRST
	BOOST_CHECK(x != ev.pack_lsb_first);
# endif
# ifdef GL_PACK_ROW_LENGTH
	BOOST_CHECK(x != ev.pack_row_length);
# endif
# ifdef GL_PACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.pack_skip_images);
# endif
# ifdef GL_PACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.pack_skip_pixels);
# endif
# ifdef GL_PACK_SKIP_ROWS
	BOOST_CHECK(x != ev.pack_skip_rows);
# endif
# ifdef GL_PACK_SWAP_BYTES
	BOOST_CHECK(x != ev.pack_swap_bytes);
# endif
# ifdef GL_POINT_FADE_THRESHOLD_SIZE
	BOOST_CHECK(x != ev.point_fade_threshold_size);
# endif
# ifdef GL_POINT_SIZE
	BOOST_CHECK(x != ev.point_size);
# endif
# ifdef GL_POINT_SIZE_GRANULARITY
	BOOST_CHECK(x != ev.point_size_granularity);
# endif
# ifdef GL_POINT_SIZE_RANGE
	BOOST_CHECK(x != ev.point_size_range);
# endif
# ifdef GL_POLYGON_OFFSET_FACTOR
	BOOST_CHECK(x != ev.polygon_offset_factor);
# endif
# ifdef GL_POLYGON_OFFSET_UNITS
	BOOST_CHECK(x != ev.polygon_offset_units);
# endif
# ifdef GL_POLYGON_SMOOTH_HINT
	BOOST_CHECK(x != ev.polygon_smooth_hint);
# endif
# ifdef GL_PRIMITIVE_RESTART_INDEX
	BOOST_CHECK(x != ev.primitive_restart_index);
# endif
# ifdef GL_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.program_binary_formats);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.provoking_vertex);
# endif
# ifdef GL_READ_BUFFER
	BOOST_CHECK(x != ev.read_buffer);
# endif
# ifdef GL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef GL_SAMPLE_COVERAGE_INVERT
	BOOST_CHECK(x != ev.sample_coverage_invert);
# endif
# ifdef GL_SAMPLE_COVERAGE_VALUE
	BOOST_CHECK(x != ev.sample_coverage_value);
# endif
# ifdef GL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef GL_SCISSOR_BOX
	BOOST_CHECK(x != ev.scissor_box);
# endif
# ifdef GL_SHADER_COMPILER
	BOOST_CHECK(x != ev.shader_compiler);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.shader_storage_buffer_offset_alignment);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_SIZE
	BOOST_CHECK(x != ev.shader_storage_buffer_size);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_START
	BOOST_CHECK(x != ev.shader_storage_buffer_start);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	BOOST_CHECK(x != ev.smooth_line_width_granularity);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	BOOST_CHECK(x != ev.smooth_line_width_range);
# endif
# ifdef GL_STENCIL_BACK_FAIL
	BOOST_CHECK(x != ev.stencil_back_fail);
# endif
# ifdef GL_STENCIL_BACK_FUNC
	BOOST_CHECK(x != ev.stencil_back_func);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_DEPTH_RANGE
	x = ev.depth_range;
	BOOST_CHECK(x == ev.depth_range);
# ifdef GL_DEPTH_WRITEMASK
	BOOST_CHECK(x != ev.depth_writemask);
# endif
# ifdef GL_DOUBLEBUFFER
	BOOST_CHECK(x != ev.doublebuffer);
# endif
# ifdef GL_DRAW_BUFFER
	BOOST_CHECK(x != ev.draw_buffer);
# endif
# ifdef GL_FRAGMENT_SHADER_DERIVATIVE_HINT
	BOOST_CHECK(x != ev.fragment_shader_derivative_hint);
# endif
# ifdef GL_IMPLEMENTATION_COLOR_READ_FORMAT
	BOOST_CHECK(x != ev.implementation_color_read_format);
# endif
# ifdef GL_IMPLEMENTATION_COLOR_READ_TYPE
	BOOST_CHECK(x != ev.implementation_color_read_type);
# endif
# ifdef GL_LAYER_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.layer_provoking_vertex);
# endif
# ifdef GL_LINE_SMOOTH_HINT
	BOOST_CHECK(x != ev.line_smooth_hint);
# endif
# ifdef GL_LINE_WIDTH
	BOOST_CHECK(x != ev.line_width);
# endif
# ifdef GL_LOGIC_OP_MODE
	BOOST_CHECK(x != ev.logic_op_mode);
# endif
# ifdef GL_NUM_COMPRESSED_TEXTURE_FORMATS
	BOOST_CHECK(x != ev.num_compressed_texture_formats);
# endif
# ifdef GL_NUM_EXTENSIONS
	BOOST_CHECK(x != ev.num_extensions);
# endif
# ifdef GL_NUM_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.num_program_binary_formats);
# endif
# ifdef GL_NUM_SHADER_BINARY_FORMATS
	BOOST_CHECK(x != ev.num_shader_binary_formats);
# endif
# ifdef GL_PACK_ALIGNMENT
	BOOST_CHECK(x != ev.pack_alignment);
# endif
# ifdef GL_PACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.pack_image_height);
# endif
# ifdef GL_PACK_LSB_FIRST
	BOOST_CHECK(x != ev.pack_lsb_first);
# endif
# ifdef GL_PACK_ROW_LENGTH
	BOOST_CHECK(x != ev.pack_row_length);
# endif
# ifdef GL_PACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.pack_skip_images);
# endif
# ifdef GL_PACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.pack_skip_pixels);
# endif
# ifdef GL_PACK_SKIP_ROWS
	BOOST_CHECK(x != ev.pack_skip_rows);
# endif
# ifdef GL_PACK_SWAP_BYTES
	BOOST_CHECK(x != ev.pack_swap_bytes);
# endif
# ifdef GL_POINT_FADE_THRESHOLD_SIZE
	BOOST_CHECK(x != ev.point_fade_threshold_size);
# endif
# ifdef GL_POINT_SIZE
	BOOST_CHECK(x != ev.point_size);
# endif
# ifdef GL_POINT_SIZE_GRANULARITY
	BOOST_CHECK(x != ev.point_size_granularity);
# endif
# ifdef GL_POINT_SIZE_RANGE
	BOOST_CHECK(x != ev.point_size_range);
# endif
# ifdef GL_POLYGON_OFFSET_FACTOR
	BOOST_CHECK(x != ev.polygon_offset_factor);
# endif
# ifdef GL_POLYGON_OFFSET_UNITS
	BOOST_CHECK(x != ev.polygon_offset_units);
# endif
# ifdef GL_POLYGON_SMOOTH_HINT
	BOOST_CHECK(x != ev.polygon_smooth_hint);
# endif
# ifdef GL_PRIMITIVE_RESTART_INDEX
	BOOST_CHECK(x != ev.primitive_restart_index);
# endif
# ifdef GL_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.program_binary_formats);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.provoking_vertex);
# endif
# ifdef GL_READ_BUFFER
	BOOST_CHECK(x != ev.read_buffer);
# endif
# ifdef GL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef GL_SAMPLE_COVERAGE_INVERT
	BOOST_CHECK(x != ev.sample_coverage_invert);
# endif
# ifdef GL_SAMPLE_COVERAGE_VALUE
	BOOST_CHECK(x != ev.sample_coverage_value);
# endif
# ifdef GL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef GL_SCISSOR_BOX
	BOOST_CHECK(x != ev.scissor_box);
# endif
# ifdef GL_SHADER_COMPILER
	BOOST_CHECK(x != ev.shader_compiler);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.shader_storage_buffer_offset_alignment);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_SIZE
	BOOST_CHECK(x != ev.shader_storage_buffer_size);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_START
	BOOST_CHECK(x != ev.shader_storage_buffer_start);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	BOOST_CHECK(x != ev.smooth_line_width_granularity);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	BOOST_CHECK(x != ev.smooth_line_width_range);
# endif
# ifdef GL_STENCIL_BACK_FAIL
	BOOST_CHECK(x != ev.stencil_back_fail);
# endif
# ifdef GL_STENCIL_BACK_FUNC
	BOOST_CHECK(x != ev.stencil_back_func);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_DEPTH_WRITEMASK
	x = ev.depth_writemask;
	BOOST_CHECK(x == ev.depth_writemask);
# ifdef GL_DOUBLEBUFFER
	BOOST_CHECK(x != ev.doublebuffer);
# endif
# ifdef GL_DRAW_BUFFER
	BOOST_CHECK(x != ev.draw_buffer);
# endif
# ifdef GL_FRAGMENT_SHADER_DERIVATIVE_HINT
	BOOST_CHECK(x != ev.fragment_shader_derivative_hint);
# endif
# ifdef GL_IMPLEMENTATION_COLOR_READ_FORMAT
	BOOST_CHECK(x != ev.implementation_color_read_format);
# endif
# ifdef GL_IMPLEMENTATION_COLOR_READ_TYPE
	BOOST_CHECK(x != ev.implementation_color_read_type);
# endif
# ifdef GL_LAYER_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.layer_provoking_vertex);
# endif
# ifdef GL_LINE_SMOOTH_HINT
	BOOST_CHECK(x != ev.line_smooth_hint);
# endif
# ifdef GL_LINE_WIDTH
	BOOST_CHECK(x != ev.line_width);
# endif
# ifdef GL_LOGIC_OP_MODE
	BOOST_CHECK(x != ev.logic_op_mode);
# endif
# ifdef GL_NUM_COMPRESSED_TEXTURE_FORMATS
	BOOST_CHECK(x != ev.num_compressed_texture_formats);
# endif
# ifdef GL_NUM_EXTENSIONS
	BOOST_CHECK(x != ev.num_extensions);
# endif
# ifdef GL_NUM_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.num_program_binary_formats);
# endif
# ifdef GL_NUM_SHADER_BINARY_FORMATS
	BOOST_CHECK(x != ev.num_shader_binary_formats);
# endif
# ifdef GL_PACK_ALIGNMENT
	BOOST_CHECK(x != ev.pack_alignment);
# endif
# ifdef GL_PACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.pack_image_height);
# endif
# ifdef GL_PACK_LSB_FIRST
	BOOST_CHECK(x != ev.pack_lsb_first);
# endif
# ifdef GL_PACK_ROW_LENGTH
	BOOST_CHECK(x != ev.pack_row_length);
# endif
# ifdef GL_PACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.pack_skip_images);
# endif
# ifdef GL_PACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.pack_skip_pixels);
# endif
# ifdef GL_PACK_SKIP_ROWS
	BOOST_CHECK(x != ev.pack_skip_rows);
# endif
# ifdef GL_PACK_SWAP_BYTES
	BOOST_CHECK(x != ev.pack_swap_bytes);
# endif
# ifdef GL_POINT_FADE_THRESHOLD_SIZE
	BOOST_CHECK(x != ev.point_fade_threshold_size);
# endif
# ifdef GL_POINT_SIZE
	BOOST_CHECK(x != ev.point_size);
# endif
# ifdef GL_POINT_SIZE_GRANULARITY
	BOOST_CHECK(x != ev.point_size_granularity);
# endif
# ifdef GL_POINT_SIZE_RANGE
	BOOST_CHECK(x != ev.point_size_range);
# endif
# ifdef GL_POLYGON_OFFSET_FACTOR
	BOOST_CHECK(x != ev.polygon_offset_factor);
# endif
# ifdef GL_POLYGON_OFFSET_UNITS
	BOOST_CHECK(x != ev.polygon_offset_units);
# endif
# ifdef GL_POLYGON_SMOOTH_HINT
	BOOST_CHECK(x != ev.polygon_smooth_hint);
# endif
# ifdef GL_PRIMITIVE_RESTART_INDEX
	BOOST_CHECK(x != ev.primitive_restart_index);
# endif
# ifdef GL_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.program_binary_formats);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.provoking_vertex);
# endif
# ifdef GL_READ_BUFFER
	BOOST_CHECK(x != ev.read_buffer);
# endif
# ifdef GL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef GL_SAMPLE_COVERAGE_INVERT
	BOOST_CHECK(x != ev.sample_coverage_invert);
# endif
# ifdef GL_SAMPLE_COVERAGE_VALUE
	BOOST_CHECK(x != ev.sample_coverage_value);
# endif
# ifdef GL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef GL_SCISSOR_BOX
	BOOST_CHECK(x != ev.scissor_box);
# endif
# ifdef GL_SHADER_COMPILER
	BOOST_CHECK(x != ev.shader_compiler);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.shader_storage_buffer_offset_alignment);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_SIZE
	BOOST_CHECK(x != ev.shader_storage_buffer_size);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_START
	BOOST_CHECK(x != ev.shader_storage_buffer_start);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	BOOST_CHECK(x != ev.smooth_line_width_granularity);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	BOOST_CHECK(x != ev.smooth_line_width_range);
# endif
# ifdef GL_STENCIL_BACK_FAIL
	BOOST_CHECK(x != ev.stencil_back_fail);
# endif
# ifdef GL_STENCIL_BACK_FUNC
	BOOST_CHECK(x != ev.stencil_back_func);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_DOUBLEBUFFER
	x = ev.doublebuffer;
	BOOST_CHECK(x == ev.doublebuffer);
# ifdef GL_DRAW_BUFFER
	BOOST_CHECK(x != ev.draw_buffer);
# endif
# ifdef GL_FRAGMENT_SHADER_DERIVATIVE_HINT
	BOOST_CHECK(x != ev.fragment_shader_derivative_hint);
# endif
# ifdef GL_IMPLEMENTATION_COLOR_READ_FORMAT
	BOOST_CHECK(x != ev.implementation_color_read_format);
# endif
# ifdef GL_IMPLEMENTATION_COLOR_READ_TYPE
	BOOST_CHECK(x != ev.implementation_color_read_type);
# endif
# ifdef GL_LAYER_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.layer_provoking_vertex);
# endif
# ifdef GL_LINE_SMOOTH_HINT
	BOOST_CHECK(x != ev.line_smooth_hint);
# endif
# ifdef GL_LINE_WIDTH
	BOOST_CHECK(x != ev.line_width);
# endif
# ifdef GL_LOGIC_OP_MODE
	BOOST_CHECK(x != ev.logic_op_mode);
# endif
# ifdef GL_NUM_COMPRESSED_TEXTURE_FORMATS
	BOOST_CHECK(x != ev.num_compressed_texture_formats);
# endif
# ifdef GL_NUM_EXTENSIONS
	BOOST_CHECK(x != ev.num_extensions);
# endif
# ifdef GL_NUM_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.num_program_binary_formats);
# endif
# ifdef GL_NUM_SHADER_BINARY_FORMATS
	BOOST_CHECK(x != ev.num_shader_binary_formats);
# endif
# ifdef GL_PACK_ALIGNMENT
	BOOST_CHECK(x != ev.pack_alignment);
# endif
# ifdef GL_PACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.pack_image_height);
# endif
# ifdef GL_PACK_LSB_FIRST
	BOOST_CHECK(x != ev.pack_lsb_first);
# endif
# ifdef GL_PACK_ROW_LENGTH
	BOOST_CHECK(x != ev.pack_row_length);
# endif
# ifdef GL_PACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.pack_skip_images);
# endif
# ifdef GL_PACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.pack_skip_pixels);
# endif
# ifdef GL_PACK_SKIP_ROWS
	BOOST_CHECK(x != ev.pack_skip_rows);
# endif
# ifdef GL_PACK_SWAP_BYTES
	BOOST_CHECK(x != ev.pack_swap_bytes);
# endif
# ifdef GL_POINT_FADE_THRESHOLD_SIZE
	BOOST_CHECK(x != ev.point_fade_threshold_size);
# endif
# ifdef GL_POINT_SIZE
	BOOST_CHECK(x != ev.point_size);
# endif
# ifdef GL_POINT_SIZE_GRANULARITY
	BOOST_CHECK(x != ev.point_size_granularity);
# endif
# ifdef GL_POINT_SIZE_RANGE
	BOOST_CHECK(x != ev.point_size_range);
# endif
# ifdef GL_POLYGON_OFFSET_FACTOR
	BOOST_CHECK(x != ev.polygon_offset_factor);
# endif
# ifdef GL_POLYGON_OFFSET_UNITS
	BOOST_CHECK(x != ev.polygon_offset_units);
# endif
# ifdef GL_POLYGON_SMOOTH_HINT
	BOOST_CHECK(x != ev.polygon_smooth_hint);
# endif
# ifdef GL_PRIMITIVE_RESTART_INDEX
	BOOST_CHECK(x != ev.primitive_restart_index);
# endif
# ifdef GL_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.program_binary_formats);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.provoking_vertex);
# endif
# ifdef GL_READ_BUFFER
	BOOST_CHECK(x != ev.read_buffer);
# endif
# ifdef GL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef GL_SAMPLE_COVERAGE_INVERT
	BOOST_CHECK(x != ev.sample_coverage_invert);
# endif
# ifdef GL_SAMPLE_COVERAGE_VALUE
	BOOST_CHECK(x != ev.sample_coverage_value);
# endif
# ifdef GL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef GL_SCISSOR_BOX
	BOOST_CHECK(x != ev.scissor_box);
# endif
# ifdef GL_SHADER_COMPILER
	BOOST_CHECK(x != ev.shader_compiler);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.shader_storage_buffer_offset_alignment);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_SIZE
	BOOST_CHECK(x != ev.shader_storage_buffer_size);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_START
	BOOST_CHECK(x != ev.shader_storage_buffer_start);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	BOOST_CHECK(x != ev.smooth_line_width_granularity);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	BOOST_CHECK(x != ev.smooth_line_width_range);
# endif
# ifdef GL_STENCIL_BACK_FAIL
	BOOST_CHECK(x != ev.stencil_back_fail);
# endif
# ifdef GL_STENCIL_BACK_FUNC
	BOOST_CHECK(x != ev.stencil_back_func);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_DRAW_BUFFER
	x = ev.draw_buffer;
	BOOST_CHECK(x == ev.draw_buffer);
# ifdef GL_FRAGMENT_SHADER_DERIVATIVE_HINT
	BOOST_CHECK(x != ev.fragment_shader_derivative_hint);
# endif
# ifdef GL_IMPLEMENTATION_COLOR_READ_FORMAT
	BOOST_CHECK(x != ev.implementation_color_read_format);
# endif
# ifdef GL_IMPLEMENTATION_COLOR_READ_TYPE
	BOOST_CHECK(x != ev.implementation_color_read_type);
# endif
# ifdef GL_LAYER_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.layer_provoking_vertex);
# endif
# ifdef GL_LINE_SMOOTH_HINT
	BOOST_CHECK(x != ev.line_smooth_hint);
# endif
# ifdef GL_LINE_WIDTH
	BOOST_CHECK(x != ev.line_width);
# endif
# ifdef GL_LOGIC_OP_MODE
	BOOST_CHECK(x != ev.logic_op_mode);
# endif
# ifdef GL_NUM_COMPRESSED_TEXTURE_FORMATS
	BOOST_CHECK(x != ev.num_compressed_texture_formats);
# endif
# ifdef GL_NUM_EXTENSIONS
	BOOST_CHECK(x != ev.num_extensions);
# endif
# ifdef GL_NUM_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.num_program_binary_formats);
# endif
# ifdef GL_NUM_SHADER_BINARY_FORMATS
	BOOST_CHECK(x != ev.num_shader_binary_formats);
# endif
# ifdef GL_PACK_ALIGNMENT
	BOOST_CHECK(x != ev.pack_alignment);
# endif
# ifdef GL_PACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.pack_image_height);
# endif
# ifdef GL_PACK_LSB_FIRST
	BOOST_CHECK(x != ev.pack_lsb_first);
# endif
# ifdef GL_PACK_ROW_LENGTH
	BOOST_CHECK(x != ev.pack_row_length);
# endif
# ifdef GL_PACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.pack_skip_images);
# endif
# ifdef GL_PACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.pack_skip_pixels);
# endif
# ifdef GL_PACK_SKIP_ROWS
	BOOST_CHECK(x != ev.pack_skip_rows);
# endif
# ifdef GL_PACK_SWAP_BYTES
	BOOST_CHECK(x != ev.pack_swap_bytes);
# endif
# ifdef GL_POINT_FADE_THRESHOLD_SIZE
	BOOST_CHECK(x != ev.point_fade_threshold_size);
# endif
# ifdef GL_POINT_SIZE
	BOOST_CHECK(x != ev.point_size);
# endif
# ifdef GL_POINT_SIZE_GRANULARITY
	BOOST_CHECK(x != ev.point_size_granularity);
# endif
# ifdef GL_POINT_SIZE_RANGE
	BOOST_CHECK(x != ev.point_size_range);
# endif
# ifdef GL_POLYGON_OFFSET_FACTOR
	BOOST_CHECK(x != ev.polygon_offset_factor);
# endif
# ifdef GL_POLYGON_OFFSET_UNITS
	BOOST_CHECK(x != ev.polygon_offset_units);
# endif
# ifdef GL_POLYGON_SMOOTH_HINT
	BOOST_CHECK(x != ev.polygon_smooth_hint);
# endif
# ifdef GL_PRIMITIVE_RESTART_INDEX
	BOOST_CHECK(x != ev.primitive_restart_index);
# endif
# ifdef GL_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.program_binary_formats);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.provoking_vertex);
# endif
# ifdef GL_READ_BUFFER
	BOOST_CHECK(x != ev.read_buffer);
# endif
# ifdef GL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef GL_SAMPLE_COVERAGE_INVERT
	BOOST_CHECK(x != ev.sample_coverage_invert);
# endif
# ifdef GL_SAMPLE_COVERAGE_VALUE
	BOOST_CHECK(x != ev.sample_coverage_value);
# endif
# ifdef GL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef GL_SCISSOR_BOX
	BOOST_CHECK(x != ev.scissor_box);
# endif
# ifdef GL_SHADER_COMPILER
	BOOST_CHECK(x != ev.shader_compiler);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.shader_storage_buffer_offset_alignment);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_SIZE
	BOOST_CHECK(x != ev.shader_storage_buffer_size);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_START
	BOOST_CHECK(x != ev.shader_storage_buffer_start);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	BOOST_CHECK(x != ev.smooth_line_width_granularity);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	BOOST_CHECK(x != ev.smooth_line_width_range);
# endif
# ifdef GL_STENCIL_BACK_FAIL
	BOOST_CHECK(x != ev.stencil_back_fail);
# endif
# ifdef GL_STENCIL_BACK_FUNC
	BOOST_CHECK(x != ev.stencil_back_func);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_FRAGMENT_SHADER_DERIVATIVE_HINT
	x = ev.fragment_shader_derivative_hint;
	BOOST_CHECK(x == ev.fragment_shader_derivative_hint);
# ifdef GL_IMPLEMENTATION_COLOR_READ_FORMAT
	BOOST_CHECK(x != ev.implementation_color_read_format);
# endif
# ifdef GL_IMPLEMENTATION_COLOR_READ_TYPE
	BOOST_CHECK(x != ev.implementation_color_read_type);
# endif
# ifdef GL_LAYER_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.layer_provoking_vertex);
# endif
# ifdef GL_LINE_SMOOTH_HINT
	BOOST_CHECK(x != ev.line_smooth_hint);
# endif
# ifdef GL_LINE_WIDTH
	BOOST_CHECK(x != ev.line_width);
# endif
# ifdef GL_LOGIC_OP_MODE
	BOOST_CHECK(x != ev.logic_op_mode);
# endif
# ifdef GL_NUM_COMPRESSED_TEXTURE_FORMATS
	BOOST_CHECK(x != ev.num_compressed_texture_formats);
# endif
# ifdef GL_NUM_EXTENSIONS
	BOOST_CHECK(x != ev.num_extensions);
# endif
# ifdef GL_NUM_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.num_program_binary_formats);
# endif
# ifdef GL_NUM_SHADER_BINARY_FORMATS
	BOOST_CHECK(x != ev.num_shader_binary_formats);
# endif
# ifdef GL_PACK_ALIGNMENT
	BOOST_CHECK(x != ev.pack_alignment);
# endif
# ifdef GL_PACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.pack_image_height);
# endif
# ifdef GL_PACK_LSB_FIRST
	BOOST_CHECK(x != ev.pack_lsb_first);
# endif
# ifdef GL_PACK_ROW_LENGTH
	BOOST_CHECK(x != ev.pack_row_length);
# endif
# ifdef GL_PACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.pack_skip_images);
# endif
# ifdef GL_PACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.pack_skip_pixels);
# endif
# ifdef GL_PACK_SKIP_ROWS
	BOOST_CHECK(x != ev.pack_skip_rows);
# endif
# ifdef GL_PACK_SWAP_BYTES
	BOOST_CHECK(x != ev.pack_swap_bytes);
# endif
# ifdef GL_POINT_FADE_THRESHOLD_SIZE
	BOOST_CHECK(x != ev.point_fade_threshold_size);
# endif
# ifdef GL_POINT_SIZE
	BOOST_CHECK(x != ev.point_size);
# endif
# ifdef GL_POINT_SIZE_GRANULARITY
	BOOST_CHECK(x != ev.point_size_granularity);
# endif
# ifdef GL_POINT_SIZE_RANGE
	BOOST_CHECK(x != ev.point_size_range);
# endif
# ifdef GL_POLYGON_OFFSET_FACTOR
	BOOST_CHECK(x != ev.polygon_offset_factor);
# endif
# ifdef GL_POLYGON_OFFSET_UNITS
	BOOST_CHECK(x != ev.polygon_offset_units);
# endif
# ifdef GL_POLYGON_SMOOTH_HINT
	BOOST_CHECK(x != ev.polygon_smooth_hint);
# endif
# ifdef GL_PRIMITIVE_RESTART_INDEX
	BOOST_CHECK(x != ev.primitive_restart_index);
# endif
# ifdef GL_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.program_binary_formats);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.provoking_vertex);
# endif
# ifdef GL_READ_BUFFER
	BOOST_CHECK(x != ev.read_buffer);
# endif
# ifdef GL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef GL_SAMPLE_COVERAGE_INVERT
	BOOST_CHECK(x != ev.sample_coverage_invert);
# endif
# ifdef GL_SAMPLE_COVERAGE_VALUE
	BOOST_CHECK(x != ev.sample_coverage_value);
# endif
# ifdef GL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef GL_SCISSOR_BOX
	BOOST_CHECK(x != ev.scissor_box);
# endif
# ifdef GL_SHADER_COMPILER
	BOOST_CHECK(x != ev.shader_compiler);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.shader_storage_buffer_offset_alignment);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_SIZE
	BOOST_CHECK(x != ev.shader_storage_buffer_size);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_START
	BOOST_CHECK(x != ev.shader_storage_buffer_start);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	BOOST_CHECK(x != ev.smooth_line_width_granularity);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	BOOST_CHECK(x != ev.smooth_line_width_range);
# endif
# ifdef GL_STENCIL_BACK_FAIL
	BOOST_CHECK(x != ev.stencil_back_fail);
# endif
# ifdef GL_STENCIL_BACK_FUNC
	BOOST_CHECK(x != ev.stencil_back_func);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_IMPLEMENTATION_COLOR_READ_FORMAT
	x = ev.implementation_color_read_format;
	BOOST_CHECK(x == ev.implementation_color_read_format);
# ifdef GL_IMPLEMENTATION_COLOR_READ_TYPE
	BOOST_CHECK(x != ev.implementation_color_read_type);
# endif
# ifdef GL_LAYER_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.layer_provoking_vertex);
# endif
# ifdef GL_LINE_SMOOTH_HINT
	BOOST_CHECK(x != ev.line_smooth_hint);
# endif
# ifdef GL_LINE_WIDTH
	BOOST_CHECK(x != ev.line_width);
# endif
# ifdef GL_LOGIC_OP_MODE
	BOOST_CHECK(x != ev.logic_op_mode);
# endif
# ifdef GL_NUM_COMPRESSED_TEXTURE_FORMATS
	BOOST_CHECK(x != ev.num_compressed_texture_formats);
# endif
# ifdef GL_NUM_EXTENSIONS
	BOOST_CHECK(x != ev.num_extensions);
# endif
# ifdef GL_NUM_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.num_program_binary_formats);
# endif
# ifdef GL_NUM_SHADER_BINARY_FORMATS
	BOOST_CHECK(x != ev.num_shader_binary_formats);
# endif
# ifdef GL_PACK_ALIGNMENT
	BOOST_CHECK(x != ev.pack_alignment);
# endif
# ifdef GL_PACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.pack_image_height);
# endif
# ifdef GL_PACK_LSB_FIRST
	BOOST_CHECK(x != ev.pack_lsb_first);
# endif
# ifdef GL_PACK_ROW_LENGTH
	BOOST_CHECK(x != ev.pack_row_length);
# endif
# ifdef GL_PACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.pack_skip_images);
# endif
# ifdef GL_PACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.pack_skip_pixels);
# endif
# ifdef GL_PACK_SKIP_ROWS
	BOOST_CHECK(x != ev.pack_skip_rows);
# endif
# ifdef GL_PACK_SWAP_BYTES
	BOOST_CHECK(x != ev.pack_swap_bytes);
# endif
# ifdef GL_POINT_FADE_THRESHOLD_SIZE
	BOOST_CHECK(x != ev.point_fade_threshold_size);
# endif
# ifdef GL_POINT_SIZE
	BOOST_CHECK(x != ev.point_size);
# endif
# ifdef GL_POINT_SIZE_GRANULARITY
	BOOST_CHECK(x != ev.point_size_granularity);
# endif
# ifdef GL_POINT_SIZE_RANGE
	BOOST_CHECK(x != ev.point_size_range);
# endif
# ifdef GL_POLYGON_OFFSET_FACTOR
	BOOST_CHECK(x != ev.polygon_offset_factor);
# endif
# ifdef GL_POLYGON_OFFSET_UNITS
	BOOST_CHECK(x != ev.polygon_offset_units);
# endif
# ifdef GL_POLYGON_SMOOTH_HINT
	BOOST_CHECK(x != ev.polygon_smooth_hint);
# endif
# ifdef GL_PRIMITIVE_RESTART_INDEX
	BOOST_CHECK(x != ev.primitive_restart_index);
# endif
# ifdef GL_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.program_binary_formats);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.provoking_vertex);
# endif
# ifdef GL_READ_BUFFER
	BOOST_CHECK(x != ev.read_buffer);
# endif
# ifdef GL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef GL_SAMPLE_COVERAGE_INVERT
	BOOST_CHECK(x != ev.sample_coverage_invert);
# endif
# ifdef GL_SAMPLE_COVERAGE_VALUE
	BOOST_CHECK(x != ev.sample_coverage_value);
# endif
# ifdef GL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef GL_SCISSOR_BOX
	BOOST_CHECK(x != ev.scissor_box);
# endif
# ifdef GL_SHADER_COMPILER
	BOOST_CHECK(x != ev.shader_compiler);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.shader_storage_buffer_offset_alignment);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_SIZE
	BOOST_CHECK(x != ev.shader_storage_buffer_size);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_START
	BOOST_CHECK(x != ev.shader_storage_buffer_start);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	BOOST_CHECK(x != ev.smooth_line_width_granularity);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	BOOST_CHECK(x != ev.smooth_line_width_range);
# endif
# ifdef GL_STENCIL_BACK_FAIL
	BOOST_CHECK(x != ev.stencil_back_fail);
# endif
# ifdef GL_STENCIL_BACK_FUNC
	BOOST_CHECK(x != ev.stencil_back_func);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_IMPLEMENTATION_COLOR_READ_TYPE
	x = ev.implementation_color_read_type;
	BOOST_CHECK(x == ev.implementation_color_read_type);
# ifdef GL_LAYER_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.layer_provoking_vertex);
# endif
# ifdef GL_LINE_SMOOTH_HINT
	BOOST_CHECK(x != ev.line_smooth_hint);
# endif
# ifdef GL_LINE_WIDTH
	BOOST_CHECK(x != ev.line_width);
# endif
# ifdef GL_LOGIC_OP_MODE
	BOOST_CHECK(x != ev.logic_op_mode);
# endif
# ifdef GL_NUM_COMPRESSED_TEXTURE_FORMATS
	BOOST_CHECK(x != ev.num_compressed_texture_formats);
# endif
# ifdef GL_NUM_EXTENSIONS
	BOOST_CHECK(x != ev.num_extensions);
# endif
# ifdef GL_NUM_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.num_program_binary_formats);
# endif
# ifdef GL_NUM_SHADER_BINARY_FORMATS
	BOOST_CHECK(x != ev.num_shader_binary_formats);
# endif
# ifdef GL_PACK_ALIGNMENT
	BOOST_CHECK(x != ev.pack_alignment);
# endif
# ifdef GL_PACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.pack_image_height);
# endif
# ifdef GL_PACK_LSB_FIRST
	BOOST_CHECK(x != ev.pack_lsb_first);
# endif
# ifdef GL_PACK_ROW_LENGTH
	BOOST_CHECK(x != ev.pack_row_length);
# endif
# ifdef GL_PACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.pack_skip_images);
# endif
# ifdef GL_PACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.pack_skip_pixels);
# endif
# ifdef GL_PACK_SKIP_ROWS
	BOOST_CHECK(x != ev.pack_skip_rows);
# endif
# ifdef GL_PACK_SWAP_BYTES
	BOOST_CHECK(x != ev.pack_swap_bytes);
# endif
# ifdef GL_POINT_FADE_THRESHOLD_SIZE
	BOOST_CHECK(x != ev.point_fade_threshold_size);
# endif
# ifdef GL_POINT_SIZE
	BOOST_CHECK(x != ev.point_size);
# endif
# ifdef GL_POINT_SIZE_GRANULARITY
	BOOST_CHECK(x != ev.point_size_granularity);
# endif
# ifdef GL_POINT_SIZE_RANGE
	BOOST_CHECK(x != ev.point_size_range);
# endif
# ifdef GL_POLYGON_OFFSET_FACTOR
	BOOST_CHECK(x != ev.polygon_offset_factor);
# endif
# ifdef GL_POLYGON_OFFSET_UNITS
	BOOST_CHECK(x != ev.polygon_offset_units);
# endif
# ifdef GL_POLYGON_SMOOTH_HINT
	BOOST_CHECK(x != ev.polygon_smooth_hint);
# endif
# ifdef GL_PRIMITIVE_RESTART_INDEX
	BOOST_CHECK(x != ev.primitive_restart_index);
# endif
# ifdef GL_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.program_binary_formats);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.provoking_vertex);
# endif
# ifdef GL_READ_BUFFER
	BOOST_CHECK(x != ev.read_buffer);
# endif
# ifdef GL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef GL_SAMPLE_COVERAGE_INVERT
	BOOST_CHECK(x != ev.sample_coverage_invert);
# endif
# ifdef GL_SAMPLE_COVERAGE_VALUE
	BOOST_CHECK(x != ev.sample_coverage_value);
# endif
# ifdef GL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef GL_SCISSOR_BOX
	BOOST_CHECK(x != ev.scissor_box);
# endif
# ifdef GL_SHADER_COMPILER
	BOOST_CHECK(x != ev.shader_compiler);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.shader_storage_buffer_offset_alignment);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_SIZE
	BOOST_CHECK(x != ev.shader_storage_buffer_size);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_START
	BOOST_CHECK(x != ev.shader_storage_buffer_start);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	BOOST_CHECK(x != ev.smooth_line_width_granularity);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	BOOST_CHECK(x != ev.smooth_line_width_range);
# endif
# ifdef GL_STENCIL_BACK_FAIL
	BOOST_CHECK(x != ev.stencil_back_fail);
# endif
# ifdef GL_STENCIL_BACK_FUNC
	BOOST_CHECK(x != ev.stencil_back_func);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_LAYER_PROVOKING_VERTEX
	x = ev.layer_provoking_vertex;
	BOOST_CHECK(x == ev.layer_provoking_vertex);
# ifdef GL_LINE_SMOOTH_HINT
	BOOST_CHECK(x != ev.line_smooth_hint);
# endif
# ifdef GL_LINE_WIDTH
	BOOST_CHECK(x != ev.line_width);
# endif
# ifdef GL_LOGIC_OP_MODE
	BOOST_CHECK(x != ev.logic_op_mode);
# endif
# ifdef GL_NUM_COMPRESSED_TEXTURE_FORMATS
	BOOST_CHECK(x != ev.num_compressed_texture_formats);
# endif
# ifdef GL_NUM_EXTENSIONS
	BOOST_CHECK(x != ev.num_extensions);
# endif
# ifdef GL_NUM_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.num_program_binary_formats);
# endif
# ifdef GL_NUM_SHADER_BINARY_FORMATS
	BOOST_CHECK(x != ev.num_shader_binary_formats);
# endif
# ifdef GL_PACK_ALIGNMENT
	BOOST_CHECK(x != ev.pack_alignment);
# endif
# ifdef GL_PACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.pack_image_height);
# endif
# ifdef GL_PACK_LSB_FIRST
	BOOST_CHECK(x != ev.pack_lsb_first);
# endif
# ifdef GL_PACK_ROW_LENGTH
	BOOST_CHECK(x != ev.pack_row_length);
# endif
# ifdef GL_PACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.pack_skip_images);
# endif
# ifdef GL_PACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.pack_skip_pixels);
# endif
# ifdef GL_PACK_SKIP_ROWS
	BOOST_CHECK(x != ev.pack_skip_rows);
# endif
# ifdef GL_PACK_SWAP_BYTES
	BOOST_CHECK(x != ev.pack_swap_bytes);
# endif
# ifdef GL_POINT_FADE_THRESHOLD_SIZE
	BOOST_CHECK(x != ev.point_fade_threshold_size);
# endif
# ifdef GL_POINT_SIZE
	BOOST_CHECK(x != ev.point_size);
# endif
# ifdef GL_POINT_SIZE_GRANULARITY
	BOOST_CHECK(x != ev.point_size_granularity);
# endif
# ifdef GL_POINT_SIZE_RANGE
	BOOST_CHECK(x != ev.point_size_range);
# endif
# ifdef GL_POLYGON_OFFSET_FACTOR
	BOOST_CHECK(x != ev.polygon_offset_factor);
# endif
# ifdef GL_POLYGON_OFFSET_UNITS
	BOOST_CHECK(x != ev.polygon_offset_units);
# endif
# ifdef GL_POLYGON_SMOOTH_HINT
	BOOST_CHECK(x != ev.polygon_smooth_hint);
# endif
# ifdef GL_PRIMITIVE_RESTART_INDEX
	BOOST_CHECK(x != ev.primitive_restart_index);
# endif
# ifdef GL_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.program_binary_formats);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.provoking_vertex);
# endif
# ifdef GL_READ_BUFFER
	BOOST_CHECK(x != ev.read_buffer);
# endif
# ifdef GL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef GL_SAMPLE_COVERAGE_INVERT
	BOOST_CHECK(x != ev.sample_coverage_invert);
# endif
# ifdef GL_SAMPLE_COVERAGE_VALUE
	BOOST_CHECK(x != ev.sample_coverage_value);
# endif
# ifdef GL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef GL_SCISSOR_BOX
	BOOST_CHECK(x != ev.scissor_box);
# endif
# ifdef GL_SHADER_COMPILER
	BOOST_CHECK(x != ev.shader_compiler);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.shader_storage_buffer_offset_alignment);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_SIZE
	BOOST_CHECK(x != ev.shader_storage_buffer_size);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_START
	BOOST_CHECK(x != ev.shader_storage_buffer_start);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	BOOST_CHECK(x != ev.smooth_line_width_granularity);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	BOOST_CHECK(x != ev.smooth_line_width_range);
# endif
# ifdef GL_STENCIL_BACK_FAIL
	BOOST_CHECK(x != ev.stencil_back_fail);
# endif
# ifdef GL_STENCIL_BACK_FUNC
	BOOST_CHECK(x != ev.stencil_back_func);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_LINE_SMOOTH_HINT
	x = ev.line_smooth_hint;
	BOOST_CHECK(x == ev.line_smooth_hint);
# ifdef GL_LINE_WIDTH
	BOOST_CHECK(x != ev.line_width);
# endif
# ifdef GL_LOGIC_OP_MODE
	BOOST_CHECK(x != ev.logic_op_mode);
# endif
# ifdef GL_NUM_COMPRESSED_TEXTURE_FORMATS
	BOOST_CHECK(x != ev.num_compressed_texture_formats);
# endif
# ifdef GL_NUM_EXTENSIONS
	BOOST_CHECK(x != ev.num_extensions);
# endif
# ifdef GL_NUM_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.num_program_binary_formats);
# endif
# ifdef GL_NUM_SHADER_BINARY_FORMATS
	BOOST_CHECK(x != ev.num_shader_binary_formats);
# endif
# ifdef GL_PACK_ALIGNMENT
	BOOST_CHECK(x != ev.pack_alignment);
# endif
# ifdef GL_PACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.pack_image_height);
# endif
# ifdef GL_PACK_LSB_FIRST
	BOOST_CHECK(x != ev.pack_lsb_first);
# endif
# ifdef GL_PACK_ROW_LENGTH
	BOOST_CHECK(x != ev.pack_row_length);
# endif
# ifdef GL_PACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.pack_skip_images);
# endif
# ifdef GL_PACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.pack_skip_pixels);
# endif
# ifdef GL_PACK_SKIP_ROWS
	BOOST_CHECK(x != ev.pack_skip_rows);
# endif
# ifdef GL_PACK_SWAP_BYTES
	BOOST_CHECK(x != ev.pack_swap_bytes);
# endif
# ifdef GL_POINT_FADE_THRESHOLD_SIZE
	BOOST_CHECK(x != ev.point_fade_threshold_size);
# endif
# ifdef GL_POINT_SIZE
	BOOST_CHECK(x != ev.point_size);
# endif
# ifdef GL_POINT_SIZE_GRANULARITY
	BOOST_CHECK(x != ev.point_size_granularity);
# endif
# ifdef GL_POINT_SIZE_RANGE
	BOOST_CHECK(x != ev.point_size_range);
# endif
# ifdef GL_POLYGON_OFFSET_FACTOR
	BOOST_CHECK(x != ev.polygon_offset_factor);
# endif
# ifdef GL_POLYGON_OFFSET_UNITS
	BOOST_CHECK(x != ev.polygon_offset_units);
# endif
# ifdef GL_POLYGON_SMOOTH_HINT
	BOOST_CHECK(x != ev.polygon_smooth_hint);
# endif
# ifdef GL_PRIMITIVE_RESTART_INDEX
	BOOST_CHECK(x != ev.primitive_restart_index);
# endif
# ifdef GL_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.program_binary_formats);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.provoking_vertex);
# endif
# ifdef GL_READ_BUFFER
	BOOST_CHECK(x != ev.read_buffer);
# endif
# ifdef GL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef GL_SAMPLE_COVERAGE_INVERT
	BOOST_CHECK(x != ev.sample_coverage_invert);
# endif
# ifdef GL_SAMPLE_COVERAGE_VALUE
	BOOST_CHECK(x != ev.sample_coverage_value);
# endif
# ifdef GL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef GL_SCISSOR_BOX
	BOOST_CHECK(x != ev.scissor_box);
# endif
# ifdef GL_SHADER_COMPILER
	BOOST_CHECK(x != ev.shader_compiler);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.shader_storage_buffer_offset_alignment);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_SIZE
	BOOST_CHECK(x != ev.shader_storage_buffer_size);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_START
	BOOST_CHECK(x != ev.shader_storage_buffer_start);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	BOOST_CHECK(x != ev.smooth_line_width_granularity);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	BOOST_CHECK(x != ev.smooth_line_width_range);
# endif
# ifdef GL_STENCIL_BACK_FAIL
	BOOST_CHECK(x != ev.stencil_back_fail);
# endif
# ifdef GL_STENCIL_BACK_FUNC
	BOOST_CHECK(x != ev.stencil_back_func);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_LINE_WIDTH
	x = ev.line_width;
	BOOST_CHECK(x == ev.line_width);
# ifdef GL_LOGIC_OP_MODE
	BOOST_CHECK(x != ev.logic_op_mode);
# endif
# ifdef GL_NUM_COMPRESSED_TEXTURE_FORMATS
	BOOST_CHECK(x != ev.num_compressed_texture_formats);
# endif
# ifdef GL_NUM_EXTENSIONS
	BOOST_CHECK(x != ev.num_extensions);
# endif
# ifdef GL_NUM_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.num_program_binary_formats);
# endif
# ifdef GL_NUM_SHADER_BINARY_FORMATS
	BOOST_CHECK(x != ev.num_shader_binary_formats);
# endif
# ifdef GL_PACK_ALIGNMENT
	BOOST_CHECK(x != ev.pack_alignment);
# endif
# ifdef GL_PACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.pack_image_height);
# endif
# ifdef GL_PACK_LSB_FIRST
	BOOST_CHECK(x != ev.pack_lsb_first);
# endif
# ifdef GL_PACK_ROW_LENGTH
	BOOST_CHECK(x != ev.pack_row_length);
# endif
# ifdef GL_PACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.pack_skip_images);
# endif
# ifdef GL_PACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.pack_skip_pixels);
# endif
# ifdef GL_PACK_SKIP_ROWS
	BOOST_CHECK(x != ev.pack_skip_rows);
# endif
# ifdef GL_PACK_SWAP_BYTES
	BOOST_CHECK(x != ev.pack_swap_bytes);
# endif
# ifdef GL_POINT_FADE_THRESHOLD_SIZE
	BOOST_CHECK(x != ev.point_fade_threshold_size);
# endif
# ifdef GL_POINT_SIZE
	BOOST_CHECK(x != ev.point_size);
# endif
# ifdef GL_POINT_SIZE_GRANULARITY
	BOOST_CHECK(x != ev.point_size_granularity);
# endif
# ifdef GL_POINT_SIZE_RANGE
	BOOST_CHECK(x != ev.point_size_range);
# endif
# ifdef GL_POLYGON_OFFSET_FACTOR
	BOOST_CHECK(x != ev.polygon_offset_factor);
# endif
# ifdef GL_POLYGON_OFFSET_UNITS
	BOOST_CHECK(x != ev.polygon_offset_units);
# endif
# ifdef GL_POLYGON_SMOOTH_HINT
	BOOST_CHECK(x != ev.polygon_smooth_hint);
# endif
# ifdef GL_PRIMITIVE_RESTART_INDEX
	BOOST_CHECK(x != ev.primitive_restart_index);
# endif
# ifdef GL_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.program_binary_formats);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.provoking_vertex);
# endif
# ifdef GL_READ_BUFFER
	BOOST_CHECK(x != ev.read_buffer);
# endif
# ifdef GL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef GL_SAMPLE_COVERAGE_INVERT
	BOOST_CHECK(x != ev.sample_coverage_invert);
# endif
# ifdef GL_SAMPLE_COVERAGE_VALUE
	BOOST_CHECK(x != ev.sample_coverage_value);
# endif
# ifdef GL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef GL_SCISSOR_BOX
	BOOST_CHECK(x != ev.scissor_box);
# endif
# ifdef GL_SHADER_COMPILER
	BOOST_CHECK(x != ev.shader_compiler);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.shader_storage_buffer_offset_alignment);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_SIZE
	BOOST_CHECK(x != ev.shader_storage_buffer_size);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_START
	BOOST_CHECK(x != ev.shader_storage_buffer_start);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	BOOST_CHECK(x != ev.smooth_line_width_granularity);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	BOOST_CHECK(x != ev.smooth_line_width_range);
# endif
# ifdef GL_STENCIL_BACK_FAIL
	BOOST_CHECK(x != ev.stencil_back_fail);
# endif
# ifdef GL_STENCIL_BACK_FUNC
	BOOST_CHECK(x != ev.stencil_back_func);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_LOGIC_OP_MODE
	x = ev.logic_op_mode;
	BOOST_CHECK(x == ev.logic_op_mode);
# ifdef GL_NUM_COMPRESSED_TEXTURE_FORMATS
	BOOST_CHECK(x != ev.num_compressed_texture_formats);
# endif
# ifdef GL_NUM_EXTENSIONS
	BOOST_CHECK(x != ev.num_extensions);
# endif
# ifdef GL_NUM_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.num_program_binary_formats);
# endif
# ifdef GL_NUM_SHADER_BINARY_FORMATS
	BOOST_CHECK(x != ev.num_shader_binary_formats);
# endif
# ifdef GL_PACK_ALIGNMENT
	BOOST_CHECK(x != ev.pack_alignment);
# endif
# ifdef GL_PACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.pack_image_height);
# endif
# ifdef GL_PACK_LSB_FIRST
	BOOST_CHECK(x != ev.pack_lsb_first);
# endif
# ifdef GL_PACK_ROW_LENGTH
	BOOST_CHECK(x != ev.pack_row_length);
# endif
# ifdef GL_PACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.pack_skip_images);
# endif
# ifdef GL_PACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.pack_skip_pixels);
# endif
# ifdef GL_PACK_SKIP_ROWS
	BOOST_CHECK(x != ev.pack_skip_rows);
# endif
# ifdef GL_PACK_SWAP_BYTES
	BOOST_CHECK(x != ev.pack_swap_bytes);
# endif
# ifdef GL_POINT_FADE_THRESHOLD_SIZE
	BOOST_CHECK(x != ev.point_fade_threshold_size);
# endif
# ifdef GL_POINT_SIZE
	BOOST_CHECK(x != ev.point_size);
# endif
# ifdef GL_POINT_SIZE_GRANULARITY
	BOOST_CHECK(x != ev.point_size_granularity);
# endif
# ifdef GL_POINT_SIZE_RANGE
	BOOST_CHECK(x != ev.point_size_range);
# endif
# ifdef GL_POLYGON_OFFSET_FACTOR
	BOOST_CHECK(x != ev.polygon_offset_factor);
# endif
# ifdef GL_POLYGON_OFFSET_UNITS
	BOOST_CHECK(x != ev.polygon_offset_units);
# endif
# ifdef GL_POLYGON_SMOOTH_HINT
	BOOST_CHECK(x != ev.polygon_smooth_hint);
# endif
# ifdef GL_PRIMITIVE_RESTART_INDEX
	BOOST_CHECK(x != ev.primitive_restart_index);
# endif
# ifdef GL_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.program_binary_formats);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.provoking_vertex);
# endif
# ifdef GL_READ_BUFFER
	BOOST_CHECK(x != ev.read_buffer);
# endif
# ifdef GL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef GL_SAMPLE_COVERAGE_INVERT
	BOOST_CHECK(x != ev.sample_coverage_invert);
# endif
# ifdef GL_SAMPLE_COVERAGE_VALUE
	BOOST_CHECK(x != ev.sample_coverage_value);
# endif
# ifdef GL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef GL_SCISSOR_BOX
	BOOST_CHECK(x != ev.scissor_box);
# endif
# ifdef GL_SHADER_COMPILER
	BOOST_CHECK(x != ev.shader_compiler);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.shader_storage_buffer_offset_alignment);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_SIZE
	BOOST_CHECK(x != ev.shader_storage_buffer_size);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_START
	BOOST_CHECK(x != ev.shader_storage_buffer_start);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	BOOST_CHECK(x != ev.smooth_line_width_granularity);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	BOOST_CHECK(x != ev.smooth_line_width_range);
# endif
# ifdef GL_STENCIL_BACK_FAIL
	BOOST_CHECK(x != ev.stencil_back_fail);
# endif
# ifdef GL_STENCIL_BACK_FUNC
	BOOST_CHECK(x != ev.stencil_back_func);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_NUM_COMPRESSED_TEXTURE_FORMATS
	x = ev.num_compressed_texture_formats;
	BOOST_CHECK(x == ev.num_compressed_texture_formats);
# ifdef GL_NUM_EXTENSIONS
	BOOST_CHECK(x != ev.num_extensions);
# endif
# ifdef GL_NUM_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.num_program_binary_formats);
# endif
# ifdef GL_NUM_SHADER_BINARY_FORMATS
	BOOST_CHECK(x != ev.num_shader_binary_formats);
# endif
# ifdef GL_PACK_ALIGNMENT
	BOOST_CHECK(x != ev.pack_alignment);
# endif
# ifdef GL_PACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.pack_image_height);
# endif
# ifdef GL_PACK_LSB_FIRST
	BOOST_CHECK(x != ev.pack_lsb_first);
# endif
# ifdef GL_PACK_ROW_LENGTH
	BOOST_CHECK(x != ev.pack_row_length);
# endif
# ifdef GL_PACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.pack_skip_images);
# endif
# ifdef GL_PACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.pack_skip_pixels);
# endif
# ifdef GL_PACK_SKIP_ROWS
	BOOST_CHECK(x != ev.pack_skip_rows);
# endif
# ifdef GL_PACK_SWAP_BYTES
	BOOST_CHECK(x != ev.pack_swap_bytes);
# endif
# ifdef GL_POINT_FADE_THRESHOLD_SIZE
	BOOST_CHECK(x != ev.point_fade_threshold_size);
# endif
# ifdef GL_POINT_SIZE
	BOOST_CHECK(x != ev.point_size);
# endif
# ifdef GL_POINT_SIZE_GRANULARITY
	BOOST_CHECK(x != ev.point_size_granularity);
# endif
# ifdef GL_POINT_SIZE_RANGE
	BOOST_CHECK(x != ev.point_size_range);
# endif
# ifdef GL_POLYGON_OFFSET_FACTOR
	BOOST_CHECK(x != ev.polygon_offset_factor);
# endif
# ifdef GL_POLYGON_OFFSET_UNITS
	BOOST_CHECK(x != ev.polygon_offset_units);
# endif
# ifdef GL_POLYGON_SMOOTH_HINT
	BOOST_CHECK(x != ev.polygon_smooth_hint);
# endif
# ifdef GL_PRIMITIVE_RESTART_INDEX
	BOOST_CHECK(x != ev.primitive_restart_index);
# endif
# ifdef GL_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.program_binary_formats);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.provoking_vertex);
# endif
# ifdef GL_READ_BUFFER
	BOOST_CHECK(x != ev.read_buffer);
# endif
# ifdef GL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef GL_SAMPLE_COVERAGE_INVERT
	BOOST_CHECK(x != ev.sample_coverage_invert);
# endif
# ifdef GL_SAMPLE_COVERAGE_VALUE
	BOOST_CHECK(x != ev.sample_coverage_value);
# endif
# ifdef GL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef GL_SCISSOR_BOX
	BOOST_CHECK(x != ev.scissor_box);
# endif
# ifdef GL_SHADER_COMPILER
	BOOST_CHECK(x != ev.shader_compiler);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.shader_storage_buffer_offset_alignment);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_SIZE
	BOOST_CHECK(x != ev.shader_storage_buffer_size);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_START
	BOOST_CHECK(x != ev.shader_storage_buffer_start);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	BOOST_CHECK(x != ev.smooth_line_width_granularity);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	BOOST_CHECK(x != ev.smooth_line_width_range);
# endif
# ifdef GL_STENCIL_BACK_FAIL
	BOOST_CHECK(x != ev.stencil_back_fail);
# endif
# ifdef GL_STENCIL_BACK_FUNC
	BOOST_CHECK(x != ev.stencil_back_func);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_NUM_EXTENSIONS
	x = ev.num_extensions;
	BOOST_CHECK(x == ev.num_extensions);
# ifdef GL_NUM_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.num_program_binary_formats);
# endif
# ifdef GL_NUM_SHADER_BINARY_FORMATS
	BOOST_CHECK(x != ev.num_shader_binary_formats);
# endif
# ifdef GL_PACK_ALIGNMENT
	BOOST_CHECK(x != ev.pack_alignment);
# endif
# ifdef GL_PACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.pack_image_height);
# endif
# ifdef GL_PACK_LSB_FIRST
	BOOST_CHECK(x != ev.pack_lsb_first);
# endif
# ifdef GL_PACK_ROW_LENGTH
	BOOST_CHECK(x != ev.pack_row_length);
# endif
# ifdef GL_PACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.pack_skip_images);
# endif
# ifdef GL_PACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.pack_skip_pixels);
# endif
# ifdef GL_PACK_SKIP_ROWS
	BOOST_CHECK(x != ev.pack_skip_rows);
# endif
# ifdef GL_PACK_SWAP_BYTES
	BOOST_CHECK(x != ev.pack_swap_bytes);
# endif
# ifdef GL_POINT_FADE_THRESHOLD_SIZE
	BOOST_CHECK(x != ev.point_fade_threshold_size);
# endif
# ifdef GL_POINT_SIZE
	BOOST_CHECK(x != ev.point_size);
# endif
# ifdef GL_POINT_SIZE_GRANULARITY
	BOOST_CHECK(x != ev.point_size_granularity);
# endif
# ifdef GL_POINT_SIZE_RANGE
	BOOST_CHECK(x != ev.point_size_range);
# endif
# ifdef GL_POLYGON_OFFSET_FACTOR
	BOOST_CHECK(x != ev.polygon_offset_factor);
# endif
# ifdef GL_POLYGON_OFFSET_UNITS
	BOOST_CHECK(x != ev.polygon_offset_units);
# endif
# ifdef GL_POLYGON_SMOOTH_HINT
	BOOST_CHECK(x != ev.polygon_smooth_hint);
# endif
# ifdef GL_PRIMITIVE_RESTART_INDEX
	BOOST_CHECK(x != ev.primitive_restart_index);
# endif
# ifdef GL_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.program_binary_formats);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.provoking_vertex);
# endif
# ifdef GL_READ_BUFFER
	BOOST_CHECK(x != ev.read_buffer);
# endif
# ifdef GL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef GL_SAMPLE_COVERAGE_INVERT
	BOOST_CHECK(x != ev.sample_coverage_invert);
# endif
# ifdef GL_SAMPLE_COVERAGE_VALUE
	BOOST_CHECK(x != ev.sample_coverage_value);
# endif
# ifdef GL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef GL_SCISSOR_BOX
	BOOST_CHECK(x != ev.scissor_box);
# endif
# ifdef GL_SHADER_COMPILER
	BOOST_CHECK(x != ev.shader_compiler);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.shader_storage_buffer_offset_alignment);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_SIZE
	BOOST_CHECK(x != ev.shader_storage_buffer_size);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_START
	BOOST_CHECK(x != ev.shader_storage_buffer_start);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	BOOST_CHECK(x != ev.smooth_line_width_granularity);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	BOOST_CHECK(x != ev.smooth_line_width_range);
# endif
# ifdef GL_STENCIL_BACK_FAIL
	BOOST_CHECK(x != ev.stencil_back_fail);
# endif
# ifdef GL_STENCIL_BACK_FUNC
	BOOST_CHECK(x != ev.stencil_back_func);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_NUM_PROGRAM_BINARY_FORMATS
	x = ev.num_program_binary_formats;
	BOOST_CHECK(x == ev.num_program_binary_formats);
# ifdef GL_NUM_SHADER_BINARY_FORMATS
	BOOST_CHECK(x != ev.num_shader_binary_formats);
# endif
# ifdef GL_PACK_ALIGNMENT
	BOOST_CHECK(x != ev.pack_alignment);
# endif
# ifdef GL_PACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.pack_image_height);
# endif
# ifdef GL_PACK_LSB_FIRST
	BOOST_CHECK(x != ev.pack_lsb_first);
# endif
# ifdef GL_PACK_ROW_LENGTH
	BOOST_CHECK(x != ev.pack_row_length);
# endif
# ifdef GL_PACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.pack_skip_images);
# endif
# ifdef GL_PACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.pack_skip_pixels);
# endif
# ifdef GL_PACK_SKIP_ROWS
	BOOST_CHECK(x != ev.pack_skip_rows);
# endif
# ifdef GL_PACK_SWAP_BYTES
	BOOST_CHECK(x != ev.pack_swap_bytes);
# endif
# ifdef GL_POINT_FADE_THRESHOLD_SIZE
	BOOST_CHECK(x != ev.point_fade_threshold_size);
# endif
# ifdef GL_POINT_SIZE
	BOOST_CHECK(x != ev.point_size);
# endif
# ifdef GL_POINT_SIZE_GRANULARITY
	BOOST_CHECK(x != ev.point_size_granularity);
# endif
# ifdef GL_POINT_SIZE_RANGE
	BOOST_CHECK(x != ev.point_size_range);
# endif
# ifdef GL_POLYGON_OFFSET_FACTOR
	BOOST_CHECK(x != ev.polygon_offset_factor);
# endif
# ifdef GL_POLYGON_OFFSET_UNITS
	BOOST_CHECK(x != ev.polygon_offset_units);
# endif
# ifdef GL_POLYGON_SMOOTH_HINT
	BOOST_CHECK(x != ev.polygon_smooth_hint);
# endif
# ifdef GL_PRIMITIVE_RESTART_INDEX
	BOOST_CHECK(x != ev.primitive_restart_index);
# endif
# ifdef GL_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.program_binary_formats);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.provoking_vertex);
# endif
# ifdef GL_READ_BUFFER
	BOOST_CHECK(x != ev.read_buffer);
# endif
# ifdef GL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef GL_SAMPLE_COVERAGE_INVERT
	BOOST_CHECK(x != ev.sample_coverage_invert);
# endif
# ifdef GL_SAMPLE_COVERAGE_VALUE
	BOOST_CHECK(x != ev.sample_coverage_value);
# endif
# ifdef GL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef GL_SCISSOR_BOX
	BOOST_CHECK(x != ev.scissor_box);
# endif
# ifdef GL_SHADER_COMPILER
	BOOST_CHECK(x != ev.shader_compiler);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.shader_storage_buffer_offset_alignment);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_SIZE
	BOOST_CHECK(x != ev.shader_storage_buffer_size);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_START
	BOOST_CHECK(x != ev.shader_storage_buffer_start);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	BOOST_CHECK(x != ev.smooth_line_width_granularity);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	BOOST_CHECK(x != ev.smooth_line_width_range);
# endif
# ifdef GL_STENCIL_BACK_FAIL
	BOOST_CHECK(x != ev.stencil_back_fail);
# endif
# ifdef GL_STENCIL_BACK_FUNC
	BOOST_CHECK(x != ev.stencil_back_func);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_NUM_SHADER_BINARY_FORMATS
	x = ev.num_shader_binary_formats;
	BOOST_CHECK(x == ev.num_shader_binary_formats);
# ifdef GL_PACK_ALIGNMENT
	BOOST_CHECK(x != ev.pack_alignment);
# endif
# ifdef GL_PACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.pack_image_height);
# endif
# ifdef GL_PACK_LSB_FIRST
	BOOST_CHECK(x != ev.pack_lsb_first);
# endif
# ifdef GL_PACK_ROW_LENGTH
	BOOST_CHECK(x != ev.pack_row_length);
# endif
# ifdef GL_PACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.pack_skip_images);
# endif
# ifdef GL_PACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.pack_skip_pixels);
# endif
# ifdef GL_PACK_SKIP_ROWS
	BOOST_CHECK(x != ev.pack_skip_rows);
# endif
# ifdef GL_PACK_SWAP_BYTES
	BOOST_CHECK(x != ev.pack_swap_bytes);
# endif
# ifdef GL_POINT_FADE_THRESHOLD_SIZE
	BOOST_CHECK(x != ev.point_fade_threshold_size);
# endif
# ifdef GL_POINT_SIZE
	BOOST_CHECK(x != ev.point_size);
# endif
# ifdef GL_POINT_SIZE_GRANULARITY
	BOOST_CHECK(x != ev.point_size_granularity);
# endif
# ifdef GL_POINT_SIZE_RANGE
	BOOST_CHECK(x != ev.point_size_range);
# endif
# ifdef GL_POLYGON_OFFSET_FACTOR
	BOOST_CHECK(x != ev.polygon_offset_factor);
# endif
# ifdef GL_POLYGON_OFFSET_UNITS
	BOOST_CHECK(x != ev.polygon_offset_units);
# endif
# ifdef GL_POLYGON_SMOOTH_HINT
	BOOST_CHECK(x != ev.polygon_smooth_hint);
# endif
# ifdef GL_PRIMITIVE_RESTART_INDEX
	BOOST_CHECK(x != ev.primitive_restart_index);
# endif
# ifdef GL_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.program_binary_formats);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.provoking_vertex);
# endif
# ifdef GL_READ_BUFFER
	BOOST_CHECK(x != ev.read_buffer);
# endif
# ifdef GL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef GL_SAMPLE_COVERAGE_INVERT
	BOOST_CHECK(x != ev.sample_coverage_invert);
# endif
# ifdef GL_SAMPLE_COVERAGE_VALUE
	BOOST_CHECK(x != ev.sample_coverage_value);
# endif
# ifdef GL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef GL_SCISSOR_BOX
	BOOST_CHECK(x != ev.scissor_box);
# endif
# ifdef GL_SHADER_COMPILER
	BOOST_CHECK(x != ev.shader_compiler);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.shader_storage_buffer_offset_alignment);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_SIZE
	BOOST_CHECK(x != ev.shader_storage_buffer_size);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_START
	BOOST_CHECK(x != ev.shader_storage_buffer_start);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	BOOST_CHECK(x != ev.smooth_line_width_granularity);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	BOOST_CHECK(x != ev.smooth_line_width_range);
# endif
# ifdef GL_STENCIL_BACK_FAIL
	BOOST_CHECK(x != ev.stencil_back_fail);
# endif
# ifdef GL_STENCIL_BACK_FUNC
	BOOST_CHECK(x != ev.stencil_back_func);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_PACK_ALIGNMENT
	x = ev.pack_alignment;
	BOOST_CHECK(x == ev.pack_alignment);
# ifdef GL_PACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.pack_image_height);
# endif
# ifdef GL_PACK_LSB_FIRST
	BOOST_CHECK(x != ev.pack_lsb_first);
# endif
# ifdef GL_PACK_ROW_LENGTH
	BOOST_CHECK(x != ev.pack_row_length);
# endif
# ifdef GL_PACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.pack_skip_images);
# endif
# ifdef GL_PACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.pack_skip_pixels);
# endif
# ifdef GL_PACK_SKIP_ROWS
	BOOST_CHECK(x != ev.pack_skip_rows);
# endif
# ifdef GL_PACK_SWAP_BYTES
	BOOST_CHECK(x != ev.pack_swap_bytes);
# endif
# ifdef GL_POINT_FADE_THRESHOLD_SIZE
	BOOST_CHECK(x != ev.point_fade_threshold_size);
# endif
# ifdef GL_POINT_SIZE
	BOOST_CHECK(x != ev.point_size);
# endif
# ifdef GL_POINT_SIZE_GRANULARITY
	BOOST_CHECK(x != ev.point_size_granularity);
# endif
# ifdef GL_POINT_SIZE_RANGE
	BOOST_CHECK(x != ev.point_size_range);
# endif
# ifdef GL_POLYGON_OFFSET_FACTOR
	BOOST_CHECK(x != ev.polygon_offset_factor);
# endif
# ifdef GL_POLYGON_OFFSET_UNITS
	BOOST_CHECK(x != ev.polygon_offset_units);
# endif
# ifdef GL_POLYGON_SMOOTH_HINT
	BOOST_CHECK(x != ev.polygon_smooth_hint);
# endif
# ifdef GL_PRIMITIVE_RESTART_INDEX
	BOOST_CHECK(x != ev.primitive_restart_index);
# endif
# ifdef GL_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.program_binary_formats);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.provoking_vertex);
# endif
# ifdef GL_READ_BUFFER
	BOOST_CHECK(x != ev.read_buffer);
# endif
# ifdef GL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef GL_SAMPLE_COVERAGE_INVERT
	BOOST_CHECK(x != ev.sample_coverage_invert);
# endif
# ifdef GL_SAMPLE_COVERAGE_VALUE
	BOOST_CHECK(x != ev.sample_coverage_value);
# endif
# ifdef GL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef GL_SCISSOR_BOX
	BOOST_CHECK(x != ev.scissor_box);
# endif
# ifdef GL_SHADER_COMPILER
	BOOST_CHECK(x != ev.shader_compiler);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.shader_storage_buffer_offset_alignment);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_SIZE
	BOOST_CHECK(x != ev.shader_storage_buffer_size);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_START
	BOOST_CHECK(x != ev.shader_storage_buffer_start);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	BOOST_CHECK(x != ev.smooth_line_width_granularity);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	BOOST_CHECK(x != ev.smooth_line_width_range);
# endif
# ifdef GL_STENCIL_BACK_FAIL
	BOOST_CHECK(x != ev.stencil_back_fail);
# endif
# ifdef GL_STENCIL_BACK_FUNC
	BOOST_CHECK(x != ev.stencil_back_func);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_PACK_IMAGE_HEIGHT
	x = ev.pack_image_height;
	BOOST_CHECK(x == ev.pack_image_height);
# ifdef GL_PACK_LSB_FIRST
	BOOST_CHECK(x != ev.pack_lsb_first);
# endif
# ifdef GL_PACK_ROW_LENGTH
	BOOST_CHECK(x != ev.pack_row_length);
# endif
# ifdef GL_PACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.pack_skip_images);
# endif
# ifdef GL_PACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.pack_skip_pixels);
# endif
# ifdef GL_PACK_SKIP_ROWS
	BOOST_CHECK(x != ev.pack_skip_rows);
# endif
# ifdef GL_PACK_SWAP_BYTES
	BOOST_CHECK(x != ev.pack_swap_bytes);
# endif
# ifdef GL_POINT_FADE_THRESHOLD_SIZE
	BOOST_CHECK(x != ev.point_fade_threshold_size);
# endif
# ifdef GL_POINT_SIZE
	BOOST_CHECK(x != ev.point_size);
# endif
# ifdef GL_POINT_SIZE_GRANULARITY
	BOOST_CHECK(x != ev.point_size_granularity);
# endif
# ifdef GL_POINT_SIZE_RANGE
	BOOST_CHECK(x != ev.point_size_range);
# endif
# ifdef GL_POLYGON_OFFSET_FACTOR
	BOOST_CHECK(x != ev.polygon_offset_factor);
# endif
# ifdef GL_POLYGON_OFFSET_UNITS
	BOOST_CHECK(x != ev.polygon_offset_units);
# endif
# ifdef GL_POLYGON_SMOOTH_HINT
	BOOST_CHECK(x != ev.polygon_smooth_hint);
# endif
# ifdef GL_PRIMITIVE_RESTART_INDEX
	BOOST_CHECK(x != ev.primitive_restart_index);
# endif
# ifdef GL_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.program_binary_formats);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.provoking_vertex);
# endif
# ifdef GL_READ_BUFFER
	BOOST_CHECK(x != ev.read_buffer);
# endif
# ifdef GL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef GL_SAMPLE_COVERAGE_INVERT
	BOOST_CHECK(x != ev.sample_coverage_invert);
# endif
# ifdef GL_SAMPLE_COVERAGE_VALUE
	BOOST_CHECK(x != ev.sample_coverage_value);
# endif
# ifdef GL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef GL_SCISSOR_BOX
	BOOST_CHECK(x != ev.scissor_box);
# endif
# ifdef GL_SHADER_COMPILER
	BOOST_CHECK(x != ev.shader_compiler);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.shader_storage_buffer_offset_alignment);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_SIZE
	BOOST_CHECK(x != ev.shader_storage_buffer_size);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_START
	BOOST_CHECK(x != ev.shader_storage_buffer_start);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	BOOST_CHECK(x != ev.smooth_line_width_granularity);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	BOOST_CHECK(x != ev.smooth_line_width_range);
# endif
# ifdef GL_STENCIL_BACK_FAIL
	BOOST_CHECK(x != ev.stencil_back_fail);
# endif
# ifdef GL_STENCIL_BACK_FUNC
	BOOST_CHECK(x != ev.stencil_back_func);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_PACK_LSB_FIRST
	x = ev.pack_lsb_first;
	BOOST_CHECK(x == ev.pack_lsb_first);
# ifdef GL_PACK_ROW_LENGTH
	BOOST_CHECK(x != ev.pack_row_length);
# endif
# ifdef GL_PACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.pack_skip_images);
# endif
# ifdef GL_PACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.pack_skip_pixels);
# endif
# ifdef GL_PACK_SKIP_ROWS
	BOOST_CHECK(x != ev.pack_skip_rows);
# endif
# ifdef GL_PACK_SWAP_BYTES
	BOOST_CHECK(x != ev.pack_swap_bytes);
# endif
# ifdef GL_POINT_FADE_THRESHOLD_SIZE
	BOOST_CHECK(x != ev.point_fade_threshold_size);
# endif
# ifdef GL_POINT_SIZE
	BOOST_CHECK(x != ev.point_size);
# endif
# ifdef GL_POINT_SIZE_GRANULARITY
	BOOST_CHECK(x != ev.point_size_granularity);
# endif
# ifdef GL_POINT_SIZE_RANGE
	BOOST_CHECK(x != ev.point_size_range);
# endif
# ifdef GL_POLYGON_OFFSET_FACTOR
	BOOST_CHECK(x != ev.polygon_offset_factor);
# endif
# ifdef GL_POLYGON_OFFSET_UNITS
	BOOST_CHECK(x != ev.polygon_offset_units);
# endif
# ifdef GL_POLYGON_SMOOTH_HINT
	BOOST_CHECK(x != ev.polygon_smooth_hint);
# endif
# ifdef GL_PRIMITIVE_RESTART_INDEX
	BOOST_CHECK(x != ev.primitive_restart_index);
# endif
# ifdef GL_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.program_binary_formats);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.provoking_vertex);
# endif
# ifdef GL_READ_BUFFER
	BOOST_CHECK(x != ev.read_buffer);
# endif
# ifdef GL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef GL_SAMPLE_COVERAGE_INVERT
	BOOST_CHECK(x != ev.sample_coverage_invert);
# endif
# ifdef GL_SAMPLE_COVERAGE_VALUE
	BOOST_CHECK(x != ev.sample_coverage_value);
# endif
# ifdef GL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef GL_SCISSOR_BOX
	BOOST_CHECK(x != ev.scissor_box);
# endif
# ifdef GL_SHADER_COMPILER
	BOOST_CHECK(x != ev.shader_compiler);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.shader_storage_buffer_offset_alignment);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_SIZE
	BOOST_CHECK(x != ev.shader_storage_buffer_size);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_START
	BOOST_CHECK(x != ev.shader_storage_buffer_start);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	BOOST_CHECK(x != ev.smooth_line_width_granularity);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	BOOST_CHECK(x != ev.smooth_line_width_range);
# endif
# ifdef GL_STENCIL_BACK_FAIL
	BOOST_CHECK(x != ev.stencil_back_fail);
# endif
# ifdef GL_STENCIL_BACK_FUNC
	BOOST_CHECK(x != ev.stencil_back_func);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_PACK_ROW_LENGTH
	x = ev.pack_row_length;
	BOOST_CHECK(x == ev.pack_row_length);
# ifdef GL_PACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.pack_skip_images);
# endif
# ifdef GL_PACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.pack_skip_pixels);
# endif
# ifdef GL_PACK_SKIP_ROWS
	BOOST_CHECK(x != ev.pack_skip_rows);
# endif
# ifdef GL_PACK_SWAP_BYTES
	BOOST_CHECK(x != ev.pack_swap_bytes);
# endif
# ifdef GL_POINT_FADE_THRESHOLD_SIZE
	BOOST_CHECK(x != ev.point_fade_threshold_size);
# endif
# ifdef GL_POINT_SIZE
	BOOST_CHECK(x != ev.point_size);
# endif
# ifdef GL_POINT_SIZE_GRANULARITY
	BOOST_CHECK(x != ev.point_size_granularity);
# endif
# ifdef GL_POINT_SIZE_RANGE
	BOOST_CHECK(x != ev.point_size_range);
# endif
# ifdef GL_POLYGON_OFFSET_FACTOR
	BOOST_CHECK(x != ev.polygon_offset_factor);
# endif
# ifdef GL_POLYGON_OFFSET_UNITS
	BOOST_CHECK(x != ev.polygon_offset_units);
# endif
# ifdef GL_POLYGON_SMOOTH_HINT
	BOOST_CHECK(x != ev.polygon_smooth_hint);
# endif
# ifdef GL_PRIMITIVE_RESTART_INDEX
	BOOST_CHECK(x != ev.primitive_restart_index);
# endif
# ifdef GL_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.program_binary_formats);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.provoking_vertex);
# endif
# ifdef GL_READ_BUFFER
	BOOST_CHECK(x != ev.read_buffer);
# endif
# ifdef GL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef GL_SAMPLE_COVERAGE_INVERT
	BOOST_CHECK(x != ev.sample_coverage_invert);
# endif
# ifdef GL_SAMPLE_COVERAGE_VALUE
	BOOST_CHECK(x != ev.sample_coverage_value);
# endif
# ifdef GL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef GL_SCISSOR_BOX
	BOOST_CHECK(x != ev.scissor_box);
# endif
# ifdef GL_SHADER_COMPILER
	BOOST_CHECK(x != ev.shader_compiler);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.shader_storage_buffer_offset_alignment);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_SIZE
	BOOST_CHECK(x != ev.shader_storage_buffer_size);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_START
	BOOST_CHECK(x != ev.shader_storage_buffer_start);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	BOOST_CHECK(x != ev.smooth_line_width_granularity);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	BOOST_CHECK(x != ev.smooth_line_width_range);
# endif
# ifdef GL_STENCIL_BACK_FAIL
	BOOST_CHECK(x != ev.stencil_back_fail);
# endif
# ifdef GL_STENCIL_BACK_FUNC
	BOOST_CHECK(x != ev.stencil_back_func);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_PACK_SKIP_IMAGES
	x = ev.pack_skip_images;
	BOOST_CHECK(x == ev.pack_skip_images);
# ifdef GL_PACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.pack_skip_pixels);
# endif
# ifdef GL_PACK_SKIP_ROWS
	BOOST_CHECK(x != ev.pack_skip_rows);
# endif
# ifdef GL_PACK_SWAP_BYTES
	BOOST_CHECK(x != ev.pack_swap_bytes);
# endif
# ifdef GL_POINT_FADE_THRESHOLD_SIZE
	BOOST_CHECK(x != ev.point_fade_threshold_size);
# endif
# ifdef GL_POINT_SIZE
	BOOST_CHECK(x != ev.point_size);
# endif
# ifdef GL_POINT_SIZE_GRANULARITY
	BOOST_CHECK(x != ev.point_size_granularity);
# endif
# ifdef GL_POINT_SIZE_RANGE
	BOOST_CHECK(x != ev.point_size_range);
# endif
# ifdef GL_POLYGON_OFFSET_FACTOR
	BOOST_CHECK(x != ev.polygon_offset_factor);
# endif
# ifdef GL_POLYGON_OFFSET_UNITS
	BOOST_CHECK(x != ev.polygon_offset_units);
# endif
# ifdef GL_POLYGON_SMOOTH_HINT
	BOOST_CHECK(x != ev.polygon_smooth_hint);
# endif
# ifdef GL_PRIMITIVE_RESTART_INDEX
	BOOST_CHECK(x != ev.primitive_restart_index);
# endif
# ifdef GL_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.program_binary_formats);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.provoking_vertex);
# endif
# ifdef GL_READ_BUFFER
	BOOST_CHECK(x != ev.read_buffer);
# endif
# ifdef GL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef GL_SAMPLE_COVERAGE_INVERT
	BOOST_CHECK(x != ev.sample_coverage_invert);
# endif
# ifdef GL_SAMPLE_COVERAGE_VALUE
	BOOST_CHECK(x != ev.sample_coverage_value);
# endif
# ifdef GL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef GL_SCISSOR_BOX
	BOOST_CHECK(x != ev.scissor_box);
# endif
# ifdef GL_SHADER_COMPILER
	BOOST_CHECK(x != ev.shader_compiler);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.shader_storage_buffer_offset_alignment);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_SIZE
	BOOST_CHECK(x != ev.shader_storage_buffer_size);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_START
	BOOST_CHECK(x != ev.shader_storage_buffer_start);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	BOOST_CHECK(x != ev.smooth_line_width_granularity);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	BOOST_CHECK(x != ev.smooth_line_width_range);
# endif
# ifdef GL_STENCIL_BACK_FAIL
	BOOST_CHECK(x != ev.stencil_back_fail);
# endif
# ifdef GL_STENCIL_BACK_FUNC
	BOOST_CHECK(x != ev.stencil_back_func);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_PACK_SKIP_PIXELS
	x = ev.pack_skip_pixels;
	BOOST_CHECK(x == ev.pack_skip_pixels);
# ifdef GL_PACK_SKIP_ROWS
	BOOST_CHECK(x != ev.pack_skip_rows);
# endif
# ifdef GL_PACK_SWAP_BYTES
	BOOST_CHECK(x != ev.pack_swap_bytes);
# endif
# ifdef GL_POINT_FADE_THRESHOLD_SIZE
	BOOST_CHECK(x != ev.point_fade_threshold_size);
# endif
# ifdef GL_POINT_SIZE
	BOOST_CHECK(x != ev.point_size);
# endif
# ifdef GL_POINT_SIZE_GRANULARITY
	BOOST_CHECK(x != ev.point_size_granularity);
# endif
# ifdef GL_POINT_SIZE_RANGE
	BOOST_CHECK(x != ev.point_size_range);
# endif
# ifdef GL_POLYGON_OFFSET_FACTOR
	BOOST_CHECK(x != ev.polygon_offset_factor);
# endif
# ifdef GL_POLYGON_OFFSET_UNITS
	BOOST_CHECK(x != ev.polygon_offset_units);
# endif
# ifdef GL_POLYGON_SMOOTH_HINT
	BOOST_CHECK(x != ev.polygon_smooth_hint);
# endif
# ifdef GL_PRIMITIVE_RESTART_INDEX
	BOOST_CHECK(x != ev.primitive_restart_index);
# endif
# ifdef GL_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.program_binary_formats);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.provoking_vertex);
# endif
# ifdef GL_READ_BUFFER
	BOOST_CHECK(x != ev.read_buffer);
# endif
# ifdef GL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef GL_SAMPLE_COVERAGE_INVERT
	BOOST_CHECK(x != ev.sample_coverage_invert);
# endif
# ifdef GL_SAMPLE_COVERAGE_VALUE
	BOOST_CHECK(x != ev.sample_coverage_value);
# endif
# ifdef GL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef GL_SCISSOR_BOX
	BOOST_CHECK(x != ev.scissor_box);
# endif
# ifdef GL_SHADER_COMPILER
	BOOST_CHECK(x != ev.shader_compiler);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.shader_storage_buffer_offset_alignment);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_SIZE
	BOOST_CHECK(x != ev.shader_storage_buffer_size);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_START
	BOOST_CHECK(x != ev.shader_storage_buffer_start);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	BOOST_CHECK(x != ev.smooth_line_width_granularity);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	BOOST_CHECK(x != ev.smooth_line_width_range);
# endif
# ifdef GL_STENCIL_BACK_FAIL
	BOOST_CHECK(x != ev.stencil_back_fail);
# endif
# ifdef GL_STENCIL_BACK_FUNC
	BOOST_CHECK(x != ev.stencil_back_func);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_PACK_SKIP_ROWS
	x = ev.pack_skip_rows;
	BOOST_CHECK(x == ev.pack_skip_rows);
# ifdef GL_PACK_SWAP_BYTES
	BOOST_CHECK(x != ev.pack_swap_bytes);
# endif
# ifdef GL_POINT_FADE_THRESHOLD_SIZE
	BOOST_CHECK(x != ev.point_fade_threshold_size);
# endif
# ifdef GL_POINT_SIZE
	BOOST_CHECK(x != ev.point_size);
# endif
# ifdef GL_POINT_SIZE_GRANULARITY
	BOOST_CHECK(x != ev.point_size_granularity);
# endif
# ifdef GL_POINT_SIZE_RANGE
	BOOST_CHECK(x != ev.point_size_range);
# endif
# ifdef GL_POLYGON_OFFSET_FACTOR
	BOOST_CHECK(x != ev.polygon_offset_factor);
# endif
# ifdef GL_POLYGON_OFFSET_UNITS
	BOOST_CHECK(x != ev.polygon_offset_units);
# endif
# ifdef GL_POLYGON_SMOOTH_HINT
	BOOST_CHECK(x != ev.polygon_smooth_hint);
# endif
# ifdef GL_PRIMITIVE_RESTART_INDEX
	BOOST_CHECK(x != ev.primitive_restart_index);
# endif
# ifdef GL_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.program_binary_formats);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.provoking_vertex);
# endif
# ifdef GL_READ_BUFFER
	BOOST_CHECK(x != ev.read_buffer);
# endif
# ifdef GL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef GL_SAMPLE_COVERAGE_INVERT
	BOOST_CHECK(x != ev.sample_coverage_invert);
# endif
# ifdef GL_SAMPLE_COVERAGE_VALUE
	BOOST_CHECK(x != ev.sample_coverage_value);
# endif
# ifdef GL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef GL_SCISSOR_BOX
	BOOST_CHECK(x != ev.scissor_box);
# endif
# ifdef GL_SHADER_COMPILER
	BOOST_CHECK(x != ev.shader_compiler);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.shader_storage_buffer_offset_alignment);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_SIZE
	BOOST_CHECK(x != ev.shader_storage_buffer_size);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_START
	BOOST_CHECK(x != ev.shader_storage_buffer_start);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	BOOST_CHECK(x != ev.smooth_line_width_granularity);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	BOOST_CHECK(x != ev.smooth_line_width_range);
# endif
# ifdef GL_STENCIL_BACK_FAIL
	BOOST_CHECK(x != ev.stencil_back_fail);
# endif
# ifdef GL_STENCIL_BACK_FUNC
	BOOST_CHECK(x != ev.stencil_back_func);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_PACK_SWAP_BYTES
	x = ev.pack_swap_bytes;
	BOOST_CHECK(x == ev.pack_swap_bytes);
# ifdef GL_POINT_FADE_THRESHOLD_SIZE
	BOOST_CHECK(x != ev.point_fade_threshold_size);
# endif
# ifdef GL_POINT_SIZE
	BOOST_CHECK(x != ev.point_size);
# endif
# ifdef GL_POINT_SIZE_GRANULARITY
	BOOST_CHECK(x != ev.point_size_granularity);
# endif
# ifdef GL_POINT_SIZE_RANGE
	BOOST_CHECK(x != ev.point_size_range);
# endif
# ifdef GL_POLYGON_OFFSET_FACTOR
	BOOST_CHECK(x != ev.polygon_offset_factor);
# endif
# ifdef GL_POLYGON_OFFSET_UNITS
	BOOST_CHECK(x != ev.polygon_offset_units);
# endif
# ifdef GL_POLYGON_SMOOTH_HINT
	BOOST_CHECK(x != ev.polygon_smooth_hint);
# endif
# ifdef GL_PRIMITIVE_RESTART_INDEX
	BOOST_CHECK(x != ev.primitive_restart_index);
# endif
# ifdef GL_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.program_binary_formats);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.provoking_vertex);
# endif
# ifdef GL_READ_BUFFER
	BOOST_CHECK(x != ev.read_buffer);
# endif
# ifdef GL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef GL_SAMPLE_COVERAGE_INVERT
	BOOST_CHECK(x != ev.sample_coverage_invert);
# endif
# ifdef GL_SAMPLE_COVERAGE_VALUE
	BOOST_CHECK(x != ev.sample_coverage_value);
# endif
# ifdef GL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef GL_SCISSOR_BOX
	BOOST_CHECK(x != ev.scissor_box);
# endif
# ifdef GL_SHADER_COMPILER
	BOOST_CHECK(x != ev.shader_compiler);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.shader_storage_buffer_offset_alignment);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_SIZE
	BOOST_CHECK(x != ev.shader_storage_buffer_size);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_START
	BOOST_CHECK(x != ev.shader_storage_buffer_start);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	BOOST_CHECK(x != ev.smooth_line_width_granularity);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	BOOST_CHECK(x != ev.smooth_line_width_range);
# endif
# ifdef GL_STENCIL_BACK_FAIL
	BOOST_CHECK(x != ev.stencil_back_fail);
# endif
# ifdef GL_STENCIL_BACK_FUNC
	BOOST_CHECK(x != ev.stencil_back_func);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_POINT_FADE_THRESHOLD_SIZE
	x = ev.point_fade_threshold_size;
	BOOST_CHECK(x == ev.point_fade_threshold_size);
# ifdef GL_POINT_SIZE
	BOOST_CHECK(x != ev.point_size);
# endif
# ifdef GL_POINT_SIZE_GRANULARITY
	BOOST_CHECK(x != ev.point_size_granularity);
# endif
# ifdef GL_POINT_SIZE_RANGE
	BOOST_CHECK(x != ev.point_size_range);
# endif
# ifdef GL_POLYGON_OFFSET_FACTOR
	BOOST_CHECK(x != ev.polygon_offset_factor);
# endif
# ifdef GL_POLYGON_OFFSET_UNITS
	BOOST_CHECK(x != ev.polygon_offset_units);
# endif
# ifdef GL_POLYGON_SMOOTH_HINT
	BOOST_CHECK(x != ev.polygon_smooth_hint);
# endif
# ifdef GL_PRIMITIVE_RESTART_INDEX
	BOOST_CHECK(x != ev.primitive_restart_index);
# endif
# ifdef GL_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.program_binary_formats);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.provoking_vertex);
# endif
# ifdef GL_READ_BUFFER
	BOOST_CHECK(x != ev.read_buffer);
# endif
# ifdef GL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef GL_SAMPLE_COVERAGE_INVERT
	BOOST_CHECK(x != ev.sample_coverage_invert);
# endif
# ifdef GL_SAMPLE_COVERAGE_VALUE
	BOOST_CHECK(x != ev.sample_coverage_value);
# endif
# ifdef GL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef GL_SCISSOR_BOX
	BOOST_CHECK(x != ev.scissor_box);
# endif
# ifdef GL_SHADER_COMPILER
	BOOST_CHECK(x != ev.shader_compiler);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.shader_storage_buffer_offset_alignment);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_SIZE
	BOOST_CHECK(x != ev.shader_storage_buffer_size);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_START
	BOOST_CHECK(x != ev.shader_storage_buffer_start);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	BOOST_CHECK(x != ev.smooth_line_width_granularity);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	BOOST_CHECK(x != ev.smooth_line_width_range);
# endif
# ifdef GL_STENCIL_BACK_FAIL
	BOOST_CHECK(x != ev.stencil_back_fail);
# endif
# ifdef GL_STENCIL_BACK_FUNC
	BOOST_CHECK(x != ev.stencil_back_func);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_POINT_SIZE
	x = ev.point_size;
	BOOST_CHECK(x == ev.point_size);
# ifdef GL_POINT_SIZE_GRANULARITY
	BOOST_CHECK(x != ev.point_size_granularity);
# endif
# ifdef GL_POINT_SIZE_RANGE
	BOOST_CHECK(x != ev.point_size_range);
# endif
# ifdef GL_POLYGON_OFFSET_FACTOR
	BOOST_CHECK(x != ev.polygon_offset_factor);
# endif
# ifdef GL_POLYGON_OFFSET_UNITS
	BOOST_CHECK(x != ev.polygon_offset_units);
# endif
# ifdef GL_POLYGON_SMOOTH_HINT
	BOOST_CHECK(x != ev.polygon_smooth_hint);
# endif
# ifdef GL_PRIMITIVE_RESTART_INDEX
	BOOST_CHECK(x != ev.primitive_restart_index);
# endif
# ifdef GL_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.program_binary_formats);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.provoking_vertex);
# endif
# ifdef GL_READ_BUFFER
	BOOST_CHECK(x != ev.read_buffer);
# endif
# ifdef GL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef GL_SAMPLE_COVERAGE_INVERT
	BOOST_CHECK(x != ev.sample_coverage_invert);
# endif
# ifdef GL_SAMPLE_COVERAGE_VALUE
	BOOST_CHECK(x != ev.sample_coverage_value);
# endif
# ifdef GL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef GL_SCISSOR_BOX
	BOOST_CHECK(x != ev.scissor_box);
# endif
# ifdef GL_SHADER_COMPILER
	BOOST_CHECK(x != ev.shader_compiler);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.shader_storage_buffer_offset_alignment);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_SIZE
	BOOST_CHECK(x != ev.shader_storage_buffer_size);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_START
	BOOST_CHECK(x != ev.shader_storage_buffer_start);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	BOOST_CHECK(x != ev.smooth_line_width_granularity);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	BOOST_CHECK(x != ev.smooth_line_width_range);
# endif
# ifdef GL_STENCIL_BACK_FAIL
	BOOST_CHECK(x != ev.stencil_back_fail);
# endif
# ifdef GL_STENCIL_BACK_FUNC
	BOOST_CHECK(x != ev.stencil_back_func);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_POINT_SIZE_GRANULARITY
	x = ev.point_size_granularity;
	BOOST_CHECK(x == ev.point_size_granularity);
# ifdef GL_POINT_SIZE_RANGE
	BOOST_CHECK(x != ev.point_size_range);
# endif
# ifdef GL_POLYGON_OFFSET_FACTOR
	BOOST_CHECK(x != ev.polygon_offset_factor);
# endif
# ifdef GL_POLYGON_OFFSET_UNITS
	BOOST_CHECK(x != ev.polygon_offset_units);
# endif
# ifdef GL_POLYGON_SMOOTH_HINT
	BOOST_CHECK(x != ev.polygon_smooth_hint);
# endif
# ifdef GL_PRIMITIVE_RESTART_INDEX
	BOOST_CHECK(x != ev.primitive_restart_index);
# endif
# ifdef GL_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.program_binary_formats);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.provoking_vertex);
# endif
# ifdef GL_READ_BUFFER
	BOOST_CHECK(x != ev.read_buffer);
# endif
# ifdef GL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef GL_SAMPLE_COVERAGE_INVERT
	BOOST_CHECK(x != ev.sample_coverage_invert);
# endif
# ifdef GL_SAMPLE_COVERAGE_VALUE
	BOOST_CHECK(x != ev.sample_coverage_value);
# endif
# ifdef GL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef GL_SCISSOR_BOX
	BOOST_CHECK(x != ev.scissor_box);
# endif
# ifdef GL_SHADER_COMPILER
	BOOST_CHECK(x != ev.shader_compiler);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.shader_storage_buffer_offset_alignment);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_SIZE
	BOOST_CHECK(x != ev.shader_storage_buffer_size);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_START
	BOOST_CHECK(x != ev.shader_storage_buffer_start);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	BOOST_CHECK(x != ev.smooth_line_width_granularity);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	BOOST_CHECK(x != ev.smooth_line_width_range);
# endif
# ifdef GL_STENCIL_BACK_FAIL
	BOOST_CHECK(x != ev.stencil_back_fail);
# endif
# ifdef GL_STENCIL_BACK_FUNC
	BOOST_CHECK(x != ev.stencil_back_func);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_POINT_SIZE_RANGE
	x = ev.point_size_range;
	BOOST_CHECK(x == ev.point_size_range);
# ifdef GL_POLYGON_OFFSET_FACTOR
	BOOST_CHECK(x != ev.polygon_offset_factor);
# endif
# ifdef GL_POLYGON_OFFSET_UNITS
	BOOST_CHECK(x != ev.polygon_offset_units);
# endif
# ifdef GL_POLYGON_SMOOTH_HINT
	BOOST_CHECK(x != ev.polygon_smooth_hint);
# endif
# ifdef GL_PRIMITIVE_RESTART_INDEX
	BOOST_CHECK(x != ev.primitive_restart_index);
# endif
# ifdef GL_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.program_binary_formats);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.provoking_vertex);
# endif
# ifdef GL_READ_BUFFER
	BOOST_CHECK(x != ev.read_buffer);
# endif
# ifdef GL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef GL_SAMPLE_COVERAGE_INVERT
	BOOST_CHECK(x != ev.sample_coverage_invert);
# endif
# ifdef GL_SAMPLE_COVERAGE_VALUE
	BOOST_CHECK(x != ev.sample_coverage_value);
# endif
# ifdef GL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef GL_SCISSOR_BOX
	BOOST_CHECK(x != ev.scissor_box);
# endif
# ifdef GL_SHADER_COMPILER
	BOOST_CHECK(x != ev.shader_compiler);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.shader_storage_buffer_offset_alignment);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_SIZE
	BOOST_CHECK(x != ev.shader_storage_buffer_size);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_START
	BOOST_CHECK(x != ev.shader_storage_buffer_start);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	BOOST_CHECK(x != ev.smooth_line_width_granularity);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	BOOST_CHECK(x != ev.smooth_line_width_range);
# endif
# ifdef GL_STENCIL_BACK_FAIL
	BOOST_CHECK(x != ev.stencil_back_fail);
# endif
# ifdef GL_STENCIL_BACK_FUNC
	BOOST_CHECK(x != ev.stencil_back_func);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_POLYGON_OFFSET_FACTOR
	x = ev.polygon_offset_factor;
	BOOST_CHECK(x == ev.polygon_offset_factor);
# ifdef GL_POLYGON_OFFSET_UNITS
	BOOST_CHECK(x != ev.polygon_offset_units);
# endif
# ifdef GL_POLYGON_SMOOTH_HINT
	BOOST_CHECK(x != ev.polygon_smooth_hint);
# endif
# ifdef GL_PRIMITIVE_RESTART_INDEX
	BOOST_CHECK(x != ev.primitive_restart_index);
# endif
# ifdef GL_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.program_binary_formats);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.provoking_vertex);
# endif
# ifdef GL_READ_BUFFER
	BOOST_CHECK(x != ev.read_buffer);
# endif
# ifdef GL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef GL_SAMPLE_COVERAGE_INVERT
	BOOST_CHECK(x != ev.sample_coverage_invert);
# endif
# ifdef GL_SAMPLE_COVERAGE_VALUE
	BOOST_CHECK(x != ev.sample_coverage_value);
# endif
# ifdef GL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef GL_SCISSOR_BOX
	BOOST_CHECK(x != ev.scissor_box);
# endif
# ifdef GL_SHADER_COMPILER
	BOOST_CHECK(x != ev.shader_compiler);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.shader_storage_buffer_offset_alignment);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_SIZE
	BOOST_CHECK(x != ev.shader_storage_buffer_size);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_START
	BOOST_CHECK(x != ev.shader_storage_buffer_start);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	BOOST_CHECK(x != ev.smooth_line_width_granularity);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	BOOST_CHECK(x != ev.smooth_line_width_range);
# endif
# ifdef GL_STENCIL_BACK_FAIL
	BOOST_CHECK(x != ev.stencil_back_fail);
# endif
# ifdef GL_STENCIL_BACK_FUNC
	BOOST_CHECK(x != ev.stencil_back_func);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_POLYGON_OFFSET_UNITS
	x = ev.polygon_offset_units;
	BOOST_CHECK(x == ev.polygon_offset_units);
# ifdef GL_POLYGON_SMOOTH_HINT
	BOOST_CHECK(x != ev.polygon_smooth_hint);
# endif
# ifdef GL_PRIMITIVE_RESTART_INDEX
	BOOST_CHECK(x != ev.primitive_restart_index);
# endif
# ifdef GL_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.program_binary_formats);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.provoking_vertex);
# endif
# ifdef GL_READ_BUFFER
	BOOST_CHECK(x != ev.read_buffer);
# endif
# ifdef GL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef GL_SAMPLE_COVERAGE_INVERT
	BOOST_CHECK(x != ev.sample_coverage_invert);
# endif
# ifdef GL_SAMPLE_COVERAGE_VALUE
	BOOST_CHECK(x != ev.sample_coverage_value);
# endif
# ifdef GL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef GL_SCISSOR_BOX
	BOOST_CHECK(x != ev.scissor_box);
# endif
# ifdef GL_SHADER_COMPILER
	BOOST_CHECK(x != ev.shader_compiler);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.shader_storage_buffer_offset_alignment);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_SIZE
	BOOST_CHECK(x != ev.shader_storage_buffer_size);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_START
	BOOST_CHECK(x != ev.shader_storage_buffer_start);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	BOOST_CHECK(x != ev.smooth_line_width_granularity);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	BOOST_CHECK(x != ev.smooth_line_width_range);
# endif
# ifdef GL_STENCIL_BACK_FAIL
	BOOST_CHECK(x != ev.stencil_back_fail);
# endif
# ifdef GL_STENCIL_BACK_FUNC
	BOOST_CHECK(x != ev.stencil_back_func);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_POLYGON_SMOOTH_HINT
	x = ev.polygon_smooth_hint;
	BOOST_CHECK(x == ev.polygon_smooth_hint);
# ifdef GL_PRIMITIVE_RESTART_INDEX
	BOOST_CHECK(x != ev.primitive_restart_index);
# endif
# ifdef GL_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.program_binary_formats);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.provoking_vertex);
# endif
# ifdef GL_READ_BUFFER
	BOOST_CHECK(x != ev.read_buffer);
# endif
# ifdef GL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef GL_SAMPLE_COVERAGE_INVERT
	BOOST_CHECK(x != ev.sample_coverage_invert);
# endif
# ifdef GL_SAMPLE_COVERAGE_VALUE
	BOOST_CHECK(x != ev.sample_coverage_value);
# endif
# ifdef GL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef GL_SCISSOR_BOX
	BOOST_CHECK(x != ev.scissor_box);
# endif
# ifdef GL_SHADER_COMPILER
	BOOST_CHECK(x != ev.shader_compiler);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.shader_storage_buffer_offset_alignment);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_SIZE
	BOOST_CHECK(x != ev.shader_storage_buffer_size);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_START
	BOOST_CHECK(x != ev.shader_storage_buffer_start);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	BOOST_CHECK(x != ev.smooth_line_width_granularity);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	BOOST_CHECK(x != ev.smooth_line_width_range);
# endif
# ifdef GL_STENCIL_BACK_FAIL
	BOOST_CHECK(x != ev.stencil_back_fail);
# endif
# ifdef GL_STENCIL_BACK_FUNC
	BOOST_CHECK(x != ev.stencil_back_func);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_PRIMITIVE_RESTART_INDEX
	x = ev.primitive_restart_index;
	BOOST_CHECK(x == ev.primitive_restart_index);
# ifdef GL_PROGRAM_BINARY_FORMATS
	BOOST_CHECK(x != ev.program_binary_formats);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.provoking_vertex);
# endif
# ifdef GL_READ_BUFFER
	BOOST_CHECK(x != ev.read_buffer);
# endif
# ifdef GL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef GL_SAMPLE_COVERAGE_INVERT
	BOOST_CHECK(x != ev.sample_coverage_invert);
# endif
# ifdef GL_SAMPLE_COVERAGE_VALUE
	BOOST_CHECK(x != ev.sample_coverage_value);
# endif
# ifdef GL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef GL_SCISSOR_BOX
	BOOST_CHECK(x != ev.scissor_box);
# endif
# ifdef GL_SHADER_COMPILER
	BOOST_CHECK(x != ev.shader_compiler);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.shader_storage_buffer_offset_alignment);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_SIZE
	BOOST_CHECK(x != ev.shader_storage_buffer_size);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_START
	BOOST_CHECK(x != ev.shader_storage_buffer_start);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	BOOST_CHECK(x != ev.smooth_line_width_granularity);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	BOOST_CHECK(x != ev.smooth_line_width_range);
# endif
# ifdef GL_STENCIL_BACK_FAIL
	BOOST_CHECK(x != ev.stencil_back_fail);
# endif
# ifdef GL_STENCIL_BACK_FUNC
	BOOST_CHECK(x != ev.stencil_back_func);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_PROGRAM_BINARY_FORMATS
	x = ev.program_binary_formats;
	BOOST_CHECK(x == ev.program_binary_formats);
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.provoking_vertex);
# endif
# ifdef GL_READ_BUFFER
	BOOST_CHECK(x != ev.read_buffer);
# endif
# ifdef GL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef GL_SAMPLE_COVERAGE_INVERT
	BOOST_CHECK(x != ev.sample_coverage_invert);
# endif
# ifdef GL_SAMPLE_COVERAGE_VALUE
	BOOST_CHECK(x != ev.sample_coverage_value);
# endif
# ifdef GL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef GL_SCISSOR_BOX
	BOOST_CHECK(x != ev.scissor_box);
# endif
# ifdef GL_SHADER_COMPILER
	BOOST_CHECK(x != ev.shader_compiler);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.shader_storage_buffer_offset_alignment);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_SIZE
	BOOST_CHECK(x != ev.shader_storage_buffer_size);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_START
	BOOST_CHECK(x != ev.shader_storage_buffer_start);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	BOOST_CHECK(x != ev.smooth_line_width_granularity);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	BOOST_CHECK(x != ev.smooth_line_width_range);
# endif
# ifdef GL_STENCIL_BACK_FAIL
	BOOST_CHECK(x != ev.stencil_back_fail);
# endif
# ifdef GL_STENCIL_BACK_FUNC
	BOOST_CHECK(x != ev.stencil_back_func);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_PROGRAM_POINT_SIZE
	x = ev.program_point_size;
	BOOST_CHECK(x == ev.program_point_size);
# ifdef GL_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.provoking_vertex);
# endif
# ifdef GL_READ_BUFFER
	BOOST_CHECK(x != ev.read_buffer);
# endif
# ifdef GL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef GL_SAMPLE_COVERAGE_INVERT
	BOOST_CHECK(x != ev.sample_coverage_invert);
# endif
# ifdef GL_SAMPLE_COVERAGE_VALUE
	BOOST_CHECK(x != ev.sample_coverage_value);
# endif
# ifdef GL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef GL_SCISSOR_BOX
	BOOST_CHECK(x != ev.scissor_box);
# endif
# ifdef GL_SHADER_COMPILER
	BOOST_CHECK(x != ev.shader_compiler);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.shader_storage_buffer_offset_alignment);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_SIZE
	BOOST_CHECK(x != ev.shader_storage_buffer_size);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_START
	BOOST_CHECK(x != ev.shader_storage_buffer_start);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	BOOST_CHECK(x != ev.smooth_line_width_granularity);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	BOOST_CHECK(x != ev.smooth_line_width_range);
# endif
# ifdef GL_STENCIL_BACK_FAIL
	BOOST_CHECK(x != ev.stencil_back_fail);
# endif
# ifdef GL_STENCIL_BACK_FUNC
	BOOST_CHECK(x != ev.stencil_back_func);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_PROVOKING_VERTEX
	x = ev.provoking_vertex;
	BOOST_CHECK(x == ev.provoking_vertex);
# ifdef GL_READ_BUFFER
	BOOST_CHECK(x != ev.read_buffer);
# endif
# ifdef GL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef GL_SAMPLE_COVERAGE_INVERT
	BOOST_CHECK(x != ev.sample_coverage_invert);
# endif
# ifdef GL_SAMPLE_COVERAGE_VALUE
	BOOST_CHECK(x != ev.sample_coverage_value);
# endif
# ifdef GL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef GL_SCISSOR_BOX
	BOOST_CHECK(x != ev.scissor_box);
# endif
# ifdef GL_SHADER_COMPILER
	BOOST_CHECK(x != ev.shader_compiler);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.shader_storage_buffer_offset_alignment);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_SIZE
	BOOST_CHECK(x != ev.shader_storage_buffer_size);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_START
	BOOST_CHECK(x != ev.shader_storage_buffer_start);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	BOOST_CHECK(x != ev.smooth_line_width_granularity);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	BOOST_CHECK(x != ev.smooth_line_width_range);
# endif
# ifdef GL_STENCIL_BACK_FAIL
	BOOST_CHECK(x != ev.stencil_back_fail);
# endif
# ifdef GL_STENCIL_BACK_FUNC
	BOOST_CHECK(x != ev.stencil_back_func);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_READ_BUFFER
	x = ev.read_buffer;
	BOOST_CHECK(x == ev.read_buffer);
# ifdef GL_SAMPLE_BUFFERS
	BOOST_CHECK(x != ev.sample_buffers);
# endif
# ifdef GL_SAMPLE_COVERAGE_INVERT
	BOOST_CHECK(x != ev.sample_coverage_invert);
# endif
# ifdef GL_SAMPLE_COVERAGE_VALUE
	BOOST_CHECK(x != ev.sample_coverage_value);
# endif
# ifdef GL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef GL_SCISSOR_BOX
	BOOST_CHECK(x != ev.scissor_box);
# endif
# ifdef GL_SHADER_COMPILER
	BOOST_CHECK(x != ev.shader_compiler);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.shader_storage_buffer_offset_alignment);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_SIZE
	BOOST_CHECK(x != ev.shader_storage_buffer_size);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_START
	BOOST_CHECK(x != ev.shader_storage_buffer_start);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	BOOST_CHECK(x != ev.smooth_line_width_granularity);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	BOOST_CHECK(x != ev.smooth_line_width_range);
# endif
# ifdef GL_STENCIL_BACK_FAIL
	BOOST_CHECK(x != ev.stencil_back_fail);
# endif
# ifdef GL_STENCIL_BACK_FUNC
	BOOST_CHECK(x != ev.stencil_back_func);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_SAMPLE_BUFFERS
	x = ev.sample_buffers;
	BOOST_CHECK(x == ev.sample_buffers);
# ifdef GL_SAMPLE_COVERAGE_INVERT
	BOOST_CHECK(x != ev.sample_coverage_invert);
# endif
# ifdef GL_SAMPLE_COVERAGE_VALUE
	BOOST_CHECK(x != ev.sample_coverage_value);
# endif
# ifdef GL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef GL_SCISSOR_BOX
	BOOST_CHECK(x != ev.scissor_box);
# endif
# ifdef GL_SHADER_COMPILER
	BOOST_CHECK(x != ev.shader_compiler);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.shader_storage_buffer_offset_alignment);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_SIZE
	BOOST_CHECK(x != ev.shader_storage_buffer_size);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_START
	BOOST_CHECK(x != ev.shader_storage_buffer_start);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	BOOST_CHECK(x != ev.smooth_line_width_granularity);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	BOOST_CHECK(x != ev.smooth_line_width_range);
# endif
# ifdef GL_STENCIL_BACK_FAIL
	BOOST_CHECK(x != ev.stencil_back_fail);
# endif
# ifdef GL_STENCIL_BACK_FUNC
	BOOST_CHECK(x != ev.stencil_back_func);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_SAMPLE_COVERAGE_INVERT
	x = ev.sample_coverage_invert;
	BOOST_CHECK(x == ev.sample_coverage_invert);
# ifdef GL_SAMPLE_COVERAGE_VALUE
	BOOST_CHECK(x != ev.sample_coverage_value);
# endif
# ifdef GL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef GL_SCISSOR_BOX
	BOOST_CHECK(x != ev.scissor_box);
# endif
# ifdef GL_SHADER_COMPILER
	BOOST_CHECK(x != ev.shader_compiler);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.shader_storage_buffer_offset_alignment);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_SIZE
	BOOST_CHECK(x != ev.shader_storage_buffer_size);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_START
	BOOST_CHECK(x != ev.shader_storage_buffer_start);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	BOOST_CHECK(x != ev.smooth_line_width_granularity);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	BOOST_CHECK(x != ev.smooth_line_width_range);
# endif
# ifdef GL_STENCIL_BACK_FAIL
	BOOST_CHECK(x != ev.stencil_back_fail);
# endif
# ifdef GL_STENCIL_BACK_FUNC
	BOOST_CHECK(x != ev.stencil_back_func);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_SAMPLE_COVERAGE_VALUE
	x = ev.sample_coverage_value;
	BOOST_CHECK(x == ev.sample_coverage_value);
# ifdef GL_SAMPLES
	BOOST_CHECK(x != ev.samples);
# endif
# ifdef GL_SCISSOR_BOX
	BOOST_CHECK(x != ev.scissor_box);
# endif
# ifdef GL_SHADER_COMPILER
	BOOST_CHECK(x != ev.shader_compiler);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.shader_storage_buffer_offset_alignment);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_SIZE
	BOOST_CHECK(x != ev.shader_storage_buffer_size);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_START
	BOOST_CHECK(x != ev.shader_storage_buffer_start);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	BOOST_CHECK(x != ev.smooth_line_width_granularity);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	BOOST_CHECK(x != ev.smooth_line_width_range);
# endif
# ifdef GL_STENCIL_BACK_FAIL
	BOOST_CHECK(x != ev.stencil_back_fail);
# endif
# ifdef GL_STENCIL_BACK_FUNC
	BOOST_CHECK(x != ev.stencil_back_func);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_SAMPLES
	x = ev.samples;
	BOOST_CHECK(x == ev.samples);
# ifdef GL_SCISSOR_BOX
	BOOST_CHECK(x != ev.scissor_box);
# endif
# ifdef GL_SHADER_COMPILER
	BOOST_CHECK(x != ev.shader_compiler);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.shader_storage_buffer_offset_alignment);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_SIZE
	BOOST_CHECK(x != ev.shader_storage_buffer_size);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_START
	BOOST_CHECK(x != ev.shader_storage_buffer_start);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	BOOST_CHECK(x != ev.smooth_line_width_granularity);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	BOOST_CHECK(x != ev.smooth_line_width_range);
# endif
# ifdef GL_STENCIL_BACK_FAIL
	BOOST_CHECK(x != ev.stencil_back_fail);
# endif
# ifdef GL_STENCIL_BACK_FUNC
	BOOST_CHECK(x != ev.stencil_back_func);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_SCISSOR_BOX
	x = ev.scissor_box;
	BOOST_CHECK(x == ev.scissor_box);
# ifdef GL_SHADER_COMPILER
	BOOST_CHECK(x != ev.shader_compiler);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.shader_storage_buffer_offset_alignment);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_SIZE
	BOOST_CHECK(x != ev.shader_storage_buffer_size);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_START
	BOOST_CHECK(x != ev.shader_storage_buffer_start);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	BOOST_CHECK(x != ev.smooth_line_width_granularity);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	BOOST_CHECK(x != ev.smooth_line_width_range);
# endif
# ifdef GL_STENCIL_BACK_FAIL
	BOOST_CHECK(x != ev.stencil_back_fail);
# endif
# ifdef GL_STENCIL_BACK_FUNC
	BOOST_CHECK(x != ev.stencil_back_func);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_SHADER_COMPILER
	x = ev.shader_compiler;
	BOOST_CHECK(x == ev.shader_compiler);
# ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.shader_storage_buffer_offset_alignment);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_SIZE
	BOOST_CHECK(x != ev.shader_storage_buffer_size);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_START
	BOOST_CHECK(x != ev.shader_storage_buffer_start);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	BOOST_CHECK(x != ev.smooth_line_width_granularity);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	BOOST_CHECK(x != ev.smooth_line_width_range);
# endif
# ifdef GL_STENCIL_BACK_FAIL
	BOOST_CHECK(x != ev.stencil_back_fail);
# endif
# ifdef GL_STENCIL_BACK_FUNC
	BOOST_CHECK(x != ev.stencil_back_func);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
	x = ev.shader_storage_buffer_offset_alignment;
	BOOST_CHECK(x == ev.shader_storage_buffer_offset_alignment);
# ifdef GL_SHADER_STORAGE_BUFFER_SIZE
	BOOST_CHECK(x != ev.shader_storage_buffer_size);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER_START
	BOOST_CHECK(x != ev.shader_storage_buffer_start);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	BOOST_CHECK(x != ev.smooth_line_width_granularity);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	BOOST_CHECK(x != ev.smooth_line_width_range);
# endif
# ifdef GL_STENCIL_BACK_FAIL
	BOOST_CHECK(x != ev.stencil_back_fail);
# endif
# ifdef GL_STENCIL_BACK_FUNC
	BOOST_CHECK(x != ev.stencil_back_func);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_SHADER_STORAGE_BUFFER_SIZE
	x = ev.shader_storage_buffer_size;
	BOOST_CHECK(x == ev.shader_storage_buffer_size);
# ifdef GL_SHADER_STORAGE_BUFFER_START
	BOOST_CHECK(x != ev.shader_storage_buffer_start);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	BOOST_CHECK(x != ev.smooth_line_width_granularity);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	BOOST_CHECK(x != ev.smooth_line_width_range);
# endif
# ifdef GL_STENCIL_BACK_FAIL
	BOOST_CHECK(x != ev.stencil_back_fail);
# endif
# ifdef GL_STENCIL_BACK_FUNC
	BOOST_CHECK(x != ev.stencil_back_func);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_SHADER_STORAGE_BUFFER_START
	x = ev.shader_storage_buffer_start;
	BOOST_CHECK(x == ev.shader_storage_buffer_start);
# ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	BOOST_CHECK(x != ev.smooth_line_width_granularity);
# endif
# ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	BOOST_CHECK(x != ev.smooth_line_width_range);
# endif
# ifdef GL_STENCIL_BACK_FAIL
	BOOST_CHECK(x != ev.stencil_back_fail);
# endif
# ifdef GL_STENCIL_BACK_FUNC
	BOOST_CHECK(x != ev.stencil_back_func);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	x = ev.smooth_line_width_granularity;
	BOOST_CHECK(x == ev.smooth_line_width_granularity);
# ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	BOOST_CHECK(x != ev.smooth_line_width_range);
# endif
# ifdef GL_STENCIL_BACK_FAIL
	BOOST_CHECK(x != ev.stencil_back_fail);
# endif
# ifdef GL_STENCIL_BACK_FUNC
	BOOST_CHECK(x != ev.stencil_back_func);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	x = ev.smooth_line_width_range;
	BOOST_CHECK(x == ev.smooth_line_width_range);
# ifdef GL_STENCIL_BACK_FAIL
	BOOST_CHECK(x != ev.stencil_back_fail);
# endif
# ifdef GL_STENCIL_BACK_FUNC
	BOOST_CHECK(x != ev.stencil_back_func);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_STENCIL_BACK_FAIL
	x = ev.stencil_back_fail;
	BOOST_CHECK(x == ev.stencil_back_fail);
# ifdef GL_STENCIL_BACK_FUNC
	BOOST_CHECK(x != ev.stencil_back_func);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_STENCIL_BACK_FUNC
	x = ev.stencil_back_func;
	BOOST_CHECK(x == ev.stencil_back_func);
# ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_back_pass_depth_fail);
# endif
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	x = ev.stencil_back_pass_depth_fail;
	BOOST_CHECK(x == ev.stencil_back_pass_depth_fail);
# ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_back_pass_depth_pass);
# endif
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	x = ev.stencil_back_pass_depth_pass;
	BOOST_CHECK(x == ev.stencil_back_pass_depth_pass);
# ifdef GL_STENCIL_BACK_REF
	BOOST_CHECK(x != ev.stencil_back_ref);
# endif
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_STENCIL_BACK_REF
	x = ev.stencil_back_ref;
	BOOST_CHECK(x == ev.stencil_back_ref);
# ifdef GL_STENCIL_BACK_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_back_value_mask);
# endif
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_STENCIL_BACK_VALUE_MASK
	x = ev.stencil_back_value_mask;
	BOOST_CHECK(x == ev.stencil_back_value_mask);
# ifdef GL_STENCIL_BACK_WRITEMASK
	BOOST_CHECK(x != ev.stencil_back_writemask);
# endif
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_STENCIL_BACK_WRITEMASK
	x = ev.stencil_back_writemask;
	BOOST_CHECK(x == ev.stencil_back_writemask);
# ifdef GL_STENCIL_CLEAR_VALUE
	BOOST_CHECK(x != ev.stencil_clear_value);
# endif
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_STENCIL_CLEAR_VALUE
	x = ev.stencil_clear_value;
	BOOST_CHECK(x == ev.stencil_clear_value);
# ifdef GL_STENCIL_FAIL
	BOOST_CHECK(x != ev.stencil_fail);
# endif
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_STENCIL_FAIL
	x = ev.stencil_fail;
	BOOST_CHECK(x == ev.stencil_fail);
# ifdef GL_STENCIL_FUNC
	BOOST_CHECK(x != ev.stencil_func);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_STENCIL_FUNC
	x = ev.stencil_func;
	BOOST_CHECK(x == ev.stencil_func);
# ifdef GL_STENCIL_PASS_DEPTH_FAIL
	BOOST_CHECK(x != ev.stencil_pass_depth_fail);
# endif
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_STENCIL_PASS_DEPTH_FAIL
	x = ev.stencil_pass_depth_fail;
	BOOST_CHECK(x == ev.stencil_pass_depth_fail);
# ifdef GL_STENCIL_PASS_DEPTH_PASS
	BOOST_CHECK(x != ev.stencil_pass_depth_pass);
# endif
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_STENCIL_PASS_DEPTH_PASS
	x = ev.stencil_pass_depth_pass;
	BOOST_CHECK(x == ev.stencil_pass_depth_pass);
# ifdef GL_STENCIL_REF
	BOOST_CHECK(x != ev.stencil_ref);
# endif
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_STENCIL_REF
	x = ev.stencil_ref;
	BOOST_CHECK(x == ev.stencil_ref);
# ifdef GL_STENCIL_VALUE_MASK
	BOOST_CHECK(x != ev.stencil_value_mask);
# endif
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_STENCIL_VALUE_MASK
	x = ev.stencil_value_mask;
	BOOST_CHECK(x == ev.stencil_value_mask);
# ifdef GL_STENCIL_WRITEMASK
	BOOST_CHECK(x != ev.stencil_writemask);
# endif
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_STENCIL_WRITEMASK
	x = ev.stencil_writemask;
	BOOST_CHECK(x == ev.stencil_writemask);
# ifdef GL_STEREO
	BOOST_CHECK(x != ev.stereo);
# endif
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_STEREO
	x = ev.stereo;
	BOOST_CHECK(x == ev.stereo);
# ifdef GL_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.subpixel_bits);
# endif
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_SUBPIXEL_BITS
	x = ev.subpixel_bits;
	BOOST_CHECK(x == ev.subpixel_bits);
# ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.texture_buffer_offset_alignment);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	x = ev.texture_buffer_offset_alignment;
	BOOST_CHECK(x == ev.texture_buffer_offset_alignment);
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_TEXTURE_COMPRESSION_HINT
	x = ev.texture_compression_hint;
	BOOST_CHECK(x == ev.texture_compression_hint);
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_TIMESTAMP
	x = ev.timestamp;
	BOOST_CHECK(x == ev.timestamp);
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	BOOST_CHECK(x != ev.transform_feedback_buffer_size);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	x = ev.transform_feedback_buffer_size;
	BOOST_CHECK(x == ev.transform_feedback_buffer_size);
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	BOOST_CHECK(x != ev.transform_feedback_buffer_start);
# endif
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	x = ev.transform_feedback_buffer_start;
	BOOST_CHECK(x == ev.transform_feedback_buffer_start);
# ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	BOOST_CHECK(x != ev.uniform_buffer_offset_alignment);
# endif
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	x = ev.uniform_buffer_offset_alignment;
	BOOST_CHECK(x == ev.uniform_buffer_offset_alignment);
# ifdef GL_UNIFORM_BUFFER_SIZE
	BOOST_CHECK(x != ev.uniform_buffer_size);
# endif
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_UNIFORM_BUFFER_SIZE
	x = ev.uniform_buffer_size;
	BOOST_CHECK(x == ev.uniform_buffer_size);
# ifdef GL_UNIFORM_BUFFER_START
	BOOST_CHECK(x != ev.uniform_buffer_start);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_UNIFORM_BUFFER_START
	x = ev.uniform_buffer_start;
	BOOST_CHECK(x == ev.uniform_buffer_start);
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_UNPACK_ALIGNMENT
	x = ev.unpack_alignment;
	BOOST_CHECK(x == ev.unpack_alignment);
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_UNPACK_IMAGE_HEIGHT
	x = ev.unpack_image_height;
	BOOST_CHECK(x == ev.unpack_image_height);
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_UNPACK_LSB_FIRST
	x = ev.unpack_lsb_first;
	BOOST_CHECK(x == ev.unpack_lsb_first);
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_UNPACK_ROW_LENGTH
	x = ev.unpack_row_length;
	BOOST_CHECK(x == ev.unpack_row_length);
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_UNPACK_SKIP_IMAGES
	x = ev.unpack_skip_images;
	BOOST_CHECK(x == ev.unpack_skip_images);
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_UNPACK_SKIP_PIXELS
	x = ev.unpack_skip_pixels;
	BOOST_CHECK(x == ev.unpack_skip_pixels);
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_UNPACK_SKIP_ROWS
	x = ev.unpack_skip_rows;
	BOOST_CHECK(x == ev.unpack_skip_rows);
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_UNPACK_SWAP_BYTES
	x = ev.unpack_swap_bytes;
	BOOST_CHECK(x == ev.unpack_swap_bytes);
# ifdef GL_VIEWPORT
	BOOST_CHECK(x != ev.viewport);
# endif
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_VIEWPORT
	x = ev.viewport;
	BOOST_CHECK(x == ev.viewport);
# ifdef GL_VIEWPORT_BOUNDS_RANGE
	BOOST_CHECK(x != ev.viewport_bounds_range);
# endif
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_VIEWPORT_BOUNDS_RANGE
	x = ev.viewport_bounds_range;
	BOOST_CHECK(x == ev.viewport_bounds_range);
# ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	BOOST_CHECK(x != ev.viewport_index_provoking_vertex);
# endif
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	x = ev.viewport_index_provoking_vertex;
	BOOST_CHECK(x == ev.viewport_index_provoking_vertex);
# ifdef GL_VIEWPORT_SUBPIXEL_BITS
	BOOST_CHECK(x != ev.viewport_subpixel_bits);
# endif
#endif

#ifdef GL_VIEWPORT_SUBPIXEL_BITS
	x = ev.viewport_subpixel_bits;
	BOOST_CHECK(x == ev.viewport_subpixel_bits);
#endif
}

BOOST_AUTO_TEST_CASE(enum_numeric_query_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	numeric_query x;
	(void)x;

#ifdef GL_ALIASED_LINE_WIDTH_RANGE
	x = ev.aliased_line_width_range;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ALIASED_LINE_WIDTH_RANGE"
	) == 0);
#endif

#ifdef GL_BLEND_COLOR
	x = ev.blend_color;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"BLEND_COLOR"
	) == 0);
#endif

#ifdef GL_BLEND_DST_ALPHA
	x = ev.blend_dst_alpha;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"BLEND_DST_ALPHA"
	) == 0);
#endif

#ifdef GL_BLEND_DST_RGB
	x = ev.blend_dst_rgb;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"BLEND_DST_RGB"
	) == 0);
#endif

#ifdef GL_BLEND_EQUATION_ALPHA
	x = ev.blend_equation_alpha;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"BLEND_EQUATION_ALPHA"
	) == 0);
#endif

#ifdef GL_BLEND_EQUATION_RGB
	x = ev.blend_equation_rgb;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"BLEND_EQUATION_RGB"
	) == 0);
#endif

#ifdef GL_BLEND_SRC_ALPHA
	x = ev.blend_src_alpha;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"BLEND_SRC_ALPHA"
	) == 0);
#endif

#ifdef GL_BLEND_SRC_RGB
	x = ev.blend_src_rgb;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"BLEND_SRC_RGB"
	) == 0);
#endif

#ifdef GL_COLOR_CLEAR_VALUE
	x = ev.color_clear_value;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"COLOR_CLEAR_VALUE"
	) == 0);
#endif

#ifdef GL_COLOR_WRITEMASK
	x = ev.color_writemask;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"COLOR_WRITEMASK"
	) == 0);
#endif

#ifdef GL_COMPRESSED_TEXTURE_FORMATS
	x = ev.compressed_texture_formats;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"COMPRESSED_TEXTURE_FORMATS"
	) == 0);
#endif

#ifdef GL_CONTEXT_FLAGS
	x = ev.context_flags;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"CONTEXT_FLAGS"
	) == 0);
#endif

#ifdef GL_DEBUG_GROUP_STACK_DEPTH
	x = ev.debug_group_stack_depth;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DEBUG_GROUP_STACK_DEPTH"
	) == 0);
#endif

#ifdef GL_DEPTH_CLEAR_VALUE
	x = ev.depth_clear_value;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DEPTH_CLEAR_VALUE"
	) == 0);
#endif

#ifdef GL_DEPTH_FUNC
	x = ev.depth_func;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DEPTH_FUNC"
	) == 0);
#endif

#ifdef GL_DEPTH_RANGE
	x = ev.depth_range;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DEPTH_RANGE"
	) == 0);
#endif

#ifdef GL_DEPTH_WRITEMASK
	x = ev.depth_writemask;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DEPTH_WRITEMASK"
	) == 0);
#endif

#ifdef GL_DOUBLEBUFFER
	x = ev.doublebuffer;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DOUBLEBUFFER"
	) == 0);
#endif

#ifdef GL_DRAW_BUFFER
	x = ev.draw_buffer;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DRAW_BUFFER"
	) == 0);
#endif

#ifdef GL_FRAGMENT_SHADER_DERIVATIVE_HINT
	x = ev.fragment_shader_derivative_hint;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"FRAGMENT_SHADER_DERIVATIVE_HINT"
	) == 0);
#endif

#ifdef GL_IMPLEMENTATION_COLOR_READ_FORMAT
	x = ev.implementation_color_read_format;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"IMPLEMENTATION_COLOR_READ_FORMAT"
	) == 0);
#endif

#ifdef GL_IMPLEMENTATION_COLOR_READ_TYPE
	x = ev.implementation_color_read_type;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"IMPLEMENTATION_COLOR_READ_TYPE"
	) == 0);
#endif

#ifdef GL_LAYER_PROVOKING_VERTEX
	x = ev.layer_provoking_vertex;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"LAYER_PROVOKING_VERTEX"
	) == 0);
#endif

#ifdef GL_LINE_SMOOTH_HINT
	x = ev.line_smooth_hint;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"LINE_SMOOTH_HINT"
	) == 0);
#endif

#ifdef GL_LINE_WIDTH
	x = ev.line_width;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"LINE_WIDTH"
	) == 0);
#endif

#ifdef GL_LOGIC_OP_MODE
	x = ev.logic_op_mode;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"LOGIC_OP_MODE"
	) == 0);
#endif

#ifdef GL_NUM_COMPRESSED_TEXTURE_FORMATS
	x = ev.num_compressed_texture_formats;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"NUM_COMPRESSED_TEXTURE_FORMATS"
	) == 0);
#endif

#ifdef GL_NUM_EXTENSIONS
	x = ev.num_extensions;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"NUM_EXTENSIONS"
	) == 0);
#endif

#ifdef GL_NUM_PROGRAM_BINARY_FORMATS
	x = ev.num_program_binary_formats;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"NUM_PROGRAM_BINARY_FORMATS"
	) == 0);
#endif

#ifdef GL_NUM_SHADER_BINARY_FORMATS
	x = ev.num_shader_binary_formats;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"NUM_SHADER_BINARY_FORMATS"
	) == 0);
#endif

#ifdef GL_PACK_ALIGNMENT
	x = ev.pack_alignment;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PACK_ALIGNMENT"
	) == 0);
#endif

#ifdef GL_PACK_IMAGE_HEIGHT
	x = ev.pack_image_height;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PACK_IMAGE_HEIGHT"
	) == 0);
#endif

#ifdef GL_PACK_LSB_FIRST
	x = ev.pack_lsb_first;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PACK_LSB_FIRST"
	) == 0);
#endif

#ifdef GL_PACK_ROW_LENGTH
	x = ev.pack_row_length;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PACK_ROW_LENGTH"
	) == 0);
#endif

#ifdef GL_PACK_SKIP_IMAGES
	x = ev.pack_skip_images;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PACK_SKIP_IMAGES"
	) == 0);
#endif

#ifdef GL_PACK_SKIP_PIXELS
	x = ev.pack_skip_pixels;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PACK_SKIP_PIXELS"
	) == 0);
#endif

#ifdef GL_PACK_SKIP_ROWS
	x = ev.pack_skip_rows;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PACK_SKIP_ROWS"
	) == 0);
#endif

#ifdef GL_PACK_SWAP_BYTES
	x = ev.pack_swap_bytes;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PACK_SWAP_BYTES"
	) == 0);
#endif

#ifdef GL_POINT_FADE_THRESHOLD_SIZE
	x = ev.point_fade_threshold_size;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"POINT_FADE_THRESHOLD_SIZE"
	) == 0);
#endif

#ifdef GL_POINT_SIZE
	x = ev.point_size;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"POINT_SIZE"
	) == 0);
#endif

#ifdef GL_POINT_SIZE_GRANULARITY
	x = ev.point_size_granularity;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"POINT_SIZE_GRANULARITY"
	) == 0);
#endif

#ifdef GL_POINT_SIZE_RANGE
	x = ev.point_size_range;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"POINT_SIZE_RANGE"
	) == 0);
#endif

#ifdef GL_POLYGON_OFFSET_FACTOR
	x = ev.polygon_offset_factor;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"POLYGON_OFFSET_FACTOR"
	) == 0);
#endif

#ifdef GL_POLYGON_OFFSET_UNITS
	x = ev.polygon_offset_units;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"POLYGON_OFFSET_UNITS"
	) == 0);
#endif

#ifdef GL_POLYGON_SMOOTH_HINT
	x = ev.polygon_smooth_hint;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"POLYGON_SMOOTH_HINT"
	) == 0);
#endif

#ifdef GL_PRIMITIVE_RESTART_INDEX
	x = ev.primitive_restart_index;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PRIMITIVE_RESTART_INDEX"
	) == 0);
#endif

#ifdef GL_PROGRAM_BINARY_FORMATS
	x = ev.program_binary_formats;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PROGRAM_BINARY_FORMATS"
	) == 0);
#endif

#ifdef GL_PROGRAM_POINT_SIZE
	x = ev.program_point_size;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PROGRAM_POINT_SIZE"
	) == 0);
#endif

#ifdef GL_PROVOKING_VERTEX
	x = ev.provoking_vertex;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PROVOKING_VERTEX"
	) == 0);
#endif

#ifdef GL_READ_BUFFER
	x = ev.read_buffer;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"READ_BUFFER"
	) == 0);
#endif

#ifdef GL_SAMPLE_BUFFERS
	x = ev.sample_buffers;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SAMPLE_BUFFERS"
	) == 0);
#endif

#ifdef GL_SAMPLE_COVERAGE_INVERT
	x = ev.sample_coverage_invert;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SAMPLE_COVERAGE_INVERT"
	) == 0);
#endif

#ifdef GL_SAMPLE_COVERAGE_VALUE
	x = ev.sample_coverage_value;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SAMPLE_COVERAGE_VALUE"
	) == 0);
#endif

#ifdef GL_SAMPLES
	x = ev.samples;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SAMPLES"
	) == 0);
#endif

#ifdef GL_SCISSOR_BOX
	x = ev.scissor_box;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SCISSOR_BOX"
	) == 0);
#endif

#ifdef GL_SHADER_COMPILER
	x = ev.shader_compiler;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SHADER_COMPILER"
	) == 0);
#endif

#ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
	x = ev.shader_storage_buffer_offset_alignment;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT"
	) == 0);
#endif

#ifdef GL_SHADER_STORAGE_BUFFER_SIZE
	x = ev.shader_storage_buffer_size;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SHADER_STORAGE_BUFFER_SIZE"
	) == 0);
#endif

#ifdef GL_SHADER_STORAGE_BUFFER_START
	x = ev.shader_storage_buffer_start;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SHADER_STORAGE_BUFFER_START"
	) == 0);
#endif

#ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	x = ev.smooth_line_width_granularity;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SMOOTH_LINE_WIDTH_GRANULARITY"
	) == 0);
#endif

#ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	x = ev.smooth_line_width_range;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SMOOTH_LINE_WIDTH_RANGE"
	) == 0);
#endif

#ifdef GL_STENCIL_BACK_FAIL
	x = ev.stencil_back_fail;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"STENCIL_BACK_FAIL"
	) == 0);
#endif

#ifdef GL_STENCIL_BACK_FUNC
	x = ev.stencil_back_func;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"STENCIL_BACK_FUNC"
	) == 0);
#endif

#ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	x = ev.stencil_back_pass_depth_fail;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"STENCIL_BACK_PASS_DEPTH_FAIL"
	) == 0);
#endif

#ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	x = ev.stencil_back_pass_depth_pass;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"STENCIL_BACK_PASS_DEPTH_PASS"
	) == 0);
#endif

#ifdef GL_STENCIL_BACK_REF
	x = ev.stencil_back_ref;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"STENCIL_BACK_REF"
	) == 0);
#endif

#ifdef GL_STENCIL_BACK_VALUE_MASK
	x = ev.stencil_back_value_mask;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"STENCIL_BACK_VALUE_MASK"
	) == 0);
#endif

#ifdef GL_STENCIL_BACK_WRITEMASK
	x = ev.stencil_back_writemask;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"STENCIL_BACK_WRITEMASK"
	) == 0);
#endif

#ifdef GL_STENCIL_CLEAR_VALUE
	x = ev.stencil_clear_value;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"STENCIL_CLEAR_VALUE"
	) == 0);
#endif

#ifdef GL_STENCIL_FAIL
	x = ev.stencil_fail;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"STENCIL_FAIL"
	) == 0);
#endif

#ifdef GL_STENCIL_FUNC
	x = ev.stencil_func;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"STENCIL_FUNC"
	) == 0);
#endif

#ifdef GL_STENCIL_PASS_DEPTH_FAIL
	x = ev.stencil_pass_depth_fail;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"STENCIL_PASS_DEPTH_FAIL"
	) == 0);
#endif

#ifdef GL_STENCIL_PASS_DEPTH_PASS
	x = ev.stencil_pass_depth_pass;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"STENCIL_PASS_DEPTH_PASS"
	) == 0);
#endif

#ifdef GL_STENCIL_REF
	x = ev.stencil_ref;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"STENCIL_REF"
	) == 0);
#endif

#ifdef GL_STENCIL_VALUE_MASK
	x = ev.stencil_value_mask;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"STENCIL_VALUE_MASK"
	) == 0);
#endif

#ifdef GL_STENCIL_WRITEMASK
	x = ev.stencil_writemask;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"STENCIL_WRITEMASK"
	) == 0);
#endif

#ifdef GL_STEREO
	x = ev.stereo;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"STEREO"
	) == 0);
#endif

#ifdef GL_SUBPIXEL_BITS
	x = ev.subpixel_bits;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SUBPIXEL_BITS"
	) == 0);
#endif

#ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	x = ev.texture_buffer_offset_alignment;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_BUFFER_OFFSET_ALIGNMENT"
	) == 0);
#endif

#ifdef GL_TEXTURE_COMPRESSION_HINT
	x = ev.texture_compression_hint;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_COMPRESSION_HINT"
	) == 0);
#endif

#ifdef GL_TIMESTAMP
	x = ev.timestamp;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TIMESTAMP"
	) == 0);
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	x = ev.transform_feedback_buffer_size;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TRANSFORM_FEEDBACK_BUFFER_SIZE"
	) == 0);
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	x = ev.transform_feedback_buffer_start;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TRANSFORM_FEEDBACK_BUFFER_START"
	) == 0);
#endif

#ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	x = ev.uniform_buffer_offset_alignment;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"UNIFORM_BUFFER_OFFSET_ALIGNMENT"
	) == 0);
#endif

#ifdef GL_UNIFORM_BUFFER_SIZE
	x = ev.uniform_buffer_size;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"UNIFORM_BUFFER_SIZE"
	) == 0);
#endif

#ifdef GL_UNIFORM_BUFFER_START
	x = ev.uniform_buffer_start;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"UNIFORM_BUFFER_START"
	) == 0);
#endif

#ifdef GL_UNPACK_ALIGNMENT
	x = ev.unpack_alignment;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"UNPACK_ALIGNMENT"
	) == 0);
#endif

#ifdef GL_UNPACK_IMAGE_HEIGHT
	x = ev.unpack_image_height;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"UNPACK_IMAGE_HEIGHT"
	) == 0);
#endif

#ifdef GL_UNPACK_LSB_FIRST
	x = ev.unpack_lsb_first;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"UNPACK_LSB_FIRST"
	) == 0);
#endif

#ifdef GL_UNPACK_ROW_LENGTH
	x = ev.unpack_row_length;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"UNPACK_ROW_LENGTH"
	) == 0);
#endif

#ifdef GL_UNPACK_SKIP_IMAGES
	x = ev.unpack_skip_images;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"UNPACK_SKIP_IMAGES"
	) == 0);
#endif

#ifdef GL_UNPACK_SKIP_PIXELS
	x = ev.unpack_skip_pixels;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"UNPACK_SKIP_PIXELS"
	) == 0);
#endif

#ifdef GL_UNPACK_SKIP_ROWS
	x = ev.unpack_skip_rows;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"UNPACK_SKIP_ROWS"
	) == 0);
#endif

#ifdef GL_UNPACK_SWAP_BYTES
	x = ev.unpack_swap_bytes;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"UNPACK_SWAP_BYTES"
	) == 0);
#endif

#ifdef GL_VIEWPORT
	x = ev.viewport;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"VIEWPORT"
	) == 0);
#endif

#ifdef GL_VIEWPORT_BOUNDS_RANGE
	x = ev.viewport_bounds_range;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"VIEWPORT_BOUNDS_RANGE"
	) == 0);
#endif

#ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	x = ev.viewport_index_provoking_vertex;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"VIEWPORT_INDEX_PROVOKING_VERTEX"
	) == 0);
#endif

#ifdef GL_VIEWPORT_SUBPIXEL_BITS
	x = ev.viewport_subpixel_bits;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"VIEWPORT_SUBPIXEL_BITS"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_numeric_query_range)
{
	using namespace oglplus;
	auto count = enum_value_range<numeric_query>().size();

#ifdef GL_ALIASED_LINE_WIDTH_RANGE
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_ALIASED_LINE_WIDTH_RANGE)
	) != r.end());
}
#endif

#ifdef GL_BLEND_COLOR
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_BLEND_COLOR)
	) != r.end());
}
#endif

#ifdef GL_BLEND_DST_ALPHA
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_BLEND_DST_ALPHA)
	) != r.end());
}
#endif

#ifdef GL_BLEND_DST_RGB
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_BLEND_DST_RGB)
	) != r.end());
}
#endif

#ifdef GL_BLEND_EQUATION_ALPHA
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_BLEND_EQUATION_ALPHA)
	) != r.end());
}
#endif

#ifdef GL_BLEND_EQUATION_RGB
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_BLEND_EQUATION_RGB)
	) != r.end());
}
#endif

#ifdef GL_BLEND_SRC_ALPHA
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_BLEND_SRC_ALPHA)
	) != r.end());
}
#endif

#ifdef GL_BLEND_SRC_RGB
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_BLEND_SRC_RGB)
	) != r.end());
}
#endif

#ifdef GL_COLOR_CLEAR_VALUE
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_COLOR_CLEAR_VALUE)
	) != r.end());
}
#endif

#ifdef GL_COLOR_WRITEMASK
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_COLOR_WRITEMASK)
	) != r.end());
}
#endif

#ifdef GL_COMPRESSED_TEXTURE_FORMATS
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_COMPRESSED_TEXTURE_FORMATS)
	) != r.end());
}
#endif

#ifdef GL_CONTEXT_FLAGS
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_CONTEXT_FLAGS)
	) != r.end());
}
#endif

#ifdef GL_DEBUG_GROUP_STACK_DEPTH
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_DEBUG_GROUP_STACK_DEPTH)
	) != r.end());
}
#endif

#ifdef GL_DEPTH_CLEAR_VALUE
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_DEPTH_CLEAR_VALUE)
	) != r.end());
}
#endif

#ifdef GL_DEPTH_FUNC
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_DEPTH_FUNC)
	) != r.end());
}
#endif

#ifdef GL_DEPTH_RANGE
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_DEPTH_RANGE)
	) != r.end());
}
#endif

#ifdef GL_DEPTH_WRITEMASK
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_DEPTH_WRITEMASK)
	) != r.end());
}
#endif

#ifdef GL_DOUBLEBUFFER
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_DOUBLEBUFFER)
	) != r.end());
}
#endif

#ifdef GL_DRAW_BUFFER
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_DRAW_BUFFER)
	) != r.end());
}
#endif

#ifdef GL_FRAGMENT_SHADER_DERIVATIVE_HINT
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_FRAGMENT_SHADER_DERIVATIVE_HINT)
	) != r.end());
}
#endif

#ifdef GL_IMPLEMENTATION_COLOR_READ_FORMAT
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_IMPLEMENTATION_COLOR_READ_FORMAT)
	) != r.end());
}
#endif

#ifdef GL_IMPLEMENTATION_COLOR_READ_TYPE
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_IMPLEMENTATION_COLOR_READ_TYPE)
	) != r.end());
}
#endif

#ifdef GL_LAYER_PROVOKING_VERTEX
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_LAYER_PROVOKING_VERTEX)
	) != r.end());
}
#endif

#ifdef GL_LINE_SMOOTH_HINT
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_LINE_SMOOTH_HINT)
	) != r.end());
}
#endif

#ifdef GL_LINE_WIDTH
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_LINE_WIDTH)
	) != r.end());
}
#endif

#ifdef GL_LOGIC_OP_MODE
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_LOGIC_OP_MODE)
	) != r.end());
}
#endif

#ifdef GL_NUM_COMPRESSED_TEXTURE_FORMATS
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_NUM_COMPRESSED_TEXTURE_FORMATS)
	) != r.end());
}
#endif

#ifdef GL_NUM_EXTENSIONS
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_NUM_EXTENSIONS)
	) != r.end());
}
#endif

#ifdef GL_NUM_PROGRAM_BINARY_FORMATS
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_NUM_PROGRAM_BINARY_FORMATS)
	) != r.end());
}
#endif

#ifdef GL_NUM_SHADER_BINARY_FORMATS
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_NUM_SHADER_BINARY_FORMATS)
	) != r.end());
}
#endif

#ifdef GL_PACK_ALIGNMENT
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_PACK_ALIGNMENT)
	) != r.end());
}
#endif

#ifdef GL_PACK_IMAGE_HEIGHT
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_PACK_IMAGE_HEIGHT)
	) != r.end());
}
#endif

#ifdef GL_PACK_LSB_FIRST
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_PACK_LSB_FIRST)
	) != r.end());
}
#endif

#ifdef GL_PACK_ROW_LENGTH
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_PACK_ROW_LENGTH)
	) != r.end());
}
#endif

#ifdef GL_PACK_SKIP_IMAGES
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_PACK_SKIP_IMAGES)
	) != r.end());
}
#endif

#ifdef GL_PACK_SKIP_PIXELS
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_PACK_SKIP_PIXELS)
	) != r.end());
}
#endif

#ifdef GL_PACK_SKIP_ROWS
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_PACK_SKIP_ROWS)
	) != r.end());
}
#endif

#ifdef GL_PACK_SWAP_BYTES
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_PACK_SWAP_BYTES)
	) != r.end());
}
#endif

#ifdef GL_POINT_FADE_THRESHOLD_SIZE
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_POINT_FADE_THRESHOLD_SIZE)
	) != r.end());
}
#endif

#ifdef GL_POINT_SIZE
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_POINT_SIZE)
	) != r.end());
}
#endif

#ifdef GL_POINT_SIZE_GRANULARITY
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_POINT_SIZE_GRANULARITY)
	) != r.end());
}
#endif

#ifdef GL_POINT_SIZE_RANGE
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_POINT_SIZE_RANGE)
	) != r.end());
}
#endif

#ifdef GL_POLYGON_OFFSET_FACTOR
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_POLYGON_OFFSET_FACTOR)
	) != r.end());
}
#endif

#ifdef GL_POLYGON_OFFSET_UNITS
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_POLYGON_OFFSET_UNITS)
	) != r.end());
}
#endif

#ifdef GL_POLYGON_SMOOTH_HINT
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_POLYGON_SMOOTH_HINT)
	) != r.end());
}
#endif

#ifdef GL_PRIMITIVE_RESTART_INDEX
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_PRIMITIVE_RESTART_INDEX)
	) != r.end());
}
#endif

#ifdef GL_PROGRAM_BINARY_FORMATS
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_PROGRAM_BINARY_FORMATS)
	) != r.end());
}
#endif

#ifdef GL_PROGRAM_POINT_SIZE
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_PROGRAM_POINT_SIZE)
	) != r.end());
}
#endif

#ifdef GL_PROVOKING_VERTEX
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_PROVOKING_VERTEX)
	) != r.end());
}
#endif

#ifdef GL_READ_BUFFER
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_READ_BUFFER)
	) != r.end());
}
#endif

#ifdef GL_SAMPLE_BUFFERS
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_SAMPLE_BUFFERS)
	) != r.end());
}
#endif

#ifdef GL_SAMPLE_COVERAGE_INVERT
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_SAMPLE_COVERAGE_INVERT)
	) != r.end());
}
#endif

#ifdef GL_SAMPLE_COVERAGE_VALUE
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_SAMPLE_COVERAGE_VALUE)
	) != r.end());
}
#endif

#ifdef GL_SAMPLES
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_SAMPLES)
	) != r.end());
}
#endif

#ifdef GL_SCISSOR_BOX
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_SCISSOR_BOX)
	) != r.end());
}
#endif

#ifdef GL_SHADER_COMPILER
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_SHADER_COMPILER)
	) != r.end());
}
#endif

#ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT)
	) != r.end());
}
#endif

#ifdef GL_SHADER_STORAGE_BUFFER_SIZE
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_SHADER_STORAGE_BUFFER_SIZE)
	) != r.end());
}
#endif

#ifdef GL_SHADER_STORAGE_BUFFER_START
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_SHADER_STORAGE_BUFFER_START)
	) != r.end());
}
#endif

#ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_SMOOTH_LINE_WIDTH_GRANULARITY)
	) != r.end());
}
#endif

#ifdef GL_SMOOTH_LINE_WIDTH_RANGE
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_SMOOTH_LINE_WIDTH_RANGE)
	) != r.end());
}
#endif

#ifdef GL_STENCIL_BACK_FAIL
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_STENCIL_BACK_FAIL)
	) != r.end());
}
#endif

#ifdef GL_STENCIL_BACK_FUNC
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_STENCIL_BACK_FUNC)
	) != r.end());
}
#endif

#ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_STENCIL_BACK_PASS_DEPTH_FAIL)
	) != r.end());
}
#endif

#ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_STENCIL_BACK_PASS_DEPTH_PASS)
	) != r.end());
}
#endif

#ifdef GL_STENCIL_BACK_REF
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_STENCIL_BACK_REF)
	) != r.end());
}
#endif

#ifdef GL_STENCIL_BACK_VALUE_MASK
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_STENCIL_BACK_VALUE_MASK)
	) != r.end());
}
#endif

#ifdef GL_STENCIL_BACK_WRITEMASK
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_STENCIL_BACK_WRITEMASK)
	) != r.end());
}
#endif

#ifdef GL_STENCIL_CLEAR_VALUE
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_STENCIL_CLEAR_VALUE)
	) != r.end());
}
#endif

#ifdef GL_STENCIL_FAIL
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_STENCIL_FAIL)
	) != r.end());
}
#endif

#ifdef GL_STENCIL_FUNC
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_STENCIL_FUNC)
	) != r.end());
}
#endif

#ifdef GL_STENCIL_PASS_DEPTH_FAIL
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_STENCIL_PASS_DEPTH_FAIL)
	) != r.end());
}
#endif

#ifdef GL_STENCIL_PASS_DEPTH_PASS
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_STENCIL_PASS_DEPTH_PASS)
	) != r.end());
}
#endif

#ifdef GL_STENCIL_REF
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_STENCIL_REF)
	) != r.end());
}
#endif

#ifdef GL_STENCIL_VALUE_MASK
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_STENCIL_VALUE_MASK)
	) != r.end());
}
#endif

#ifdef GL_STENCIL_WRITEMASK
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_STENCIL_WRITEMASK)
	) != r.end());
}
#endif

#ifdef GL_STEREO
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_STEREO)
	) != r.end());
}
#endif

#ifdef GL_SUBPIXEL_BITS
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_SUBPIXEL_BITS)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_COMPRESSION_HINT
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_TEXTURE_COMPRESSION_HINT)
	) != r.end());
}
#endif

#ifdef GL_TIMESTAMP
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_TIMESTAMP)
	) != r.end());
}
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_TRANSFORM_FEEDBACK_BUFFER_SIZE)
	) != r.end());
}
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_TRANSFORM_FEEDBACK_BUFFER_START)
	) != r.end());
}
#endif

#ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT)
	) != r.end());
}
#endif

#ifdef GL_UNIFORM_BUFFER_SIZE
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_UNIFORM_BUFFER_SIZE)
	) != r.end());
}
#endif

#ifdef GL_UNIFORM_BUFFER_START
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_UNIFORM_BUFFER_START)
	) != r.end());
}
#endif

#ifdef GL_UNPACK_ALIGNMENT
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_UNPACK_ALIGNMENT)
	) != r.end());
}
#endif

#ifdef GL_UNPACK_IMAGE_HEIGHT
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_UNPACK_IMAGE_HEIGHT)
	) != r.end());
}
#endif

#ifdef GL_UNPACK_LSB_FIRST
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_UNPACK_LSB_FIRST)
	) != r.end());
}
#endif

#ifdef GL_UNPACK_ROW_LENGTH
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_UNPACK_ROW_LENGTH)
	) != r.end());
}
#endif

#ifdef GL_UNPACK_SKIP_IMAGES
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_UNPACK_SKIP_IMAGES)
	) != r.end());
}
#endif

#ifdef GL_UNPACK_SKIP_PIXELS
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_UNPACK_SKIP_PIXELS)
	) != r.end());
}
#endif

#ifdef GL_UNPACK_SKIP_ROWS
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_UNPACK_SKIP_ROWS)
	) != r.end());
}
#endif

#ifdef GL_UNPACK_SWAP_BYTES
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_UNPACK_SWAP_BYTES)
	) != r.end());
}
#endif

#ifdef GL_VIEWPORT
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_VIEWPORT)
	) != r.end());
}
#endif

#ifdef GL_VIEWPORT_BOUNDS_RANGE
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_VIEWPORT_BOUNDS_RANGE)
	) != r.end());
}
#endif

#ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_VIEWPORT_INDEX_PROVOKING_VERTEX)
	) != r.end());
}
#endif

#ifdef GL_VIEWPORT_SUBPIXEL_BITS
{
	--count;
	auto r = enum_value_range<numeric_query>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		numeric_query(GL_VIEWPORT_SUBPIXEL_BITS)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_numeric_query_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	numeric_query x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_ALIASED_LINE_WIDTH_RANGE
	x = ev.aliased_line_width_range;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.aliased_line_width_range);
#endif

#ifdef GL_BLEND_COLOR
	x = ev.blend_color;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.blend_color);
#endif

#ifdef GL_BLEND_DST_ALPHA
	x = ev.blend_dst_alpha;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.blend_dst_alpha);
#endif

#ifdef GL_BLEND_DST_RGB
	x = ev.blend_dst_rgb;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.blend_dst_rgb);
#endif

#ifdef GL_BLEND_EQUATION_ALPHA
	x = ev.blend_equation_alpha;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.blend_equation_alpha);
#endif

#ifdef GL_BLEND_EQUATION_RGB
	x = ev.blend_equation_rgb;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.blend_equation_rgb);
#endif

#ifdef GL_BLEND_SRC_ALPHA
	x = ev.blend_src_alpha;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.blend_src_alpha);
#endif

#ifdef GL_BLEND_SRC_RGB
	x = ev.blend_src_rgb;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.blend_src_rgb);
#endif

#ifdef GL_COLOR_CLEAR_VALUE
	x = ev.color_clear_value;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.color_clear_value);
#endif

#ifdef GL_COLOR_WRITEMASK
	x = ev.color_writemask;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.color_writemask);
#endif

#ifdef GL_COMPRESSED_TEXTURE_FORMATS
	x = ev.compressed_texture_formats;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.compressed_texture_formats);
#endif

#ifdef GL_CONTEXT_FLAGS
	x = ev.context_flags;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.context_flags);
#endif

#ifdef GL_DEBUG_GROUP_STACK_DEPTH
	x = ev.debug_group_stack_depth;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.debug_group_stack_depth);
#endif

#ifdef GL_DEPTH_CLEAR_VALUE
	x = ev.depth_clear_value;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.depth_clear_value);
#endif

#ifdef GL_DEPTH_FUNC
	x = ev.depth_func;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.depth_func);
#endif

#ifdef GL_DEPTH_RANGE
	x = ev.depth_range;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.depth_range);
#endif

#ifdef GL_DEPTH_WRITEMASK
	x = ev.depth_writemask;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.depth_writemask);
#endif

#ifdef GL_DOUBLEBUFFER
	x = ev.doublebuffer;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.doublebuffer);
#endif

#ifdef GL_DRAW_BUFFER
	x = ev.draw_buffer;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.draw_buffer);
#endif

#ifdef GL_FRAGMENT_SHADER_DERIVATIVE_HINT
	x = ev.fragment_shader_derivative_hint;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.fragment_shader_derivative_hint);
#endif

#ifdef GL_IMPLEMENTATION_COLOR_READ_FORMAT
	x = ev.implementation_color_read_format;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.implementation_color_read_format);
#endif

#ifdef GL_IMPLEMENTATION_COLOR_READ_TYPE
	x = ev.implementation_color_read_type;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.implementation_color_read_type);
#endif

#ifdef GL_LAYER_PROVOKING_VERTEX
	x = ev.layer_provoking_vertex;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.layer_provoking_vertex);
#endif

#ifdef GL_LINE_SMOOTH_HINT
	x = ev.line_smooth_hint;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.line_smooth_hint);
#endif

#ifdef GL_LINE_WIDTH
	x = ev.line_width;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.line_width);
#endif

#ifdef GL_LOGIC_OP_MODE
	x = ev.logic_op_mode;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.logic_op_mode);
#endif

#ifdef GL_NUM_COMPRESSED_TEXTURE_FORMATS
	x = ev.num_compressed_texture_formats;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.num_compressed_texture_formats);
#endif

#ifdef GL_NUM_EXTENSIONS
	x = ev.num_extensions;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.num_extensions);
#endif

#ifdef GL_NUM_PROGRAM_BINARY_FORMATS
	x = ev.num_program_binary_formats;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.num_program_binary_formats);
#endif

#ifdef GL_NUM_SHADER_BINARY_FORMATS
	x = ev.num_shader_binary_formats;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.num_shader_binary_formats);
#endif

#ifdef GL_PACK_ALIGNMENT
	x = ev.pack_alignment;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.pack_alignment);
#endif

#ifdef GL_PACK_IMAGE_HEIGHT
	x = ev.pack_image_height;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.pack_image_height);
#endif

#ifdef GL_PACK_LSB_FIRST
	x = ev.pack_lsb_first;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.pack_lsb_first);
#endif

#ifdef GL_PACK_ROW_LENGTH
	x = ev.pack_row_length;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.pack_row_length);
#endif

#ifdef GL_PACK_SKIP_IMAGES
	x = ev.pack_skip_images;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.pack_skip_images);
#endif

#ifdef GL_PACK_SKIP_PIXELS
	x = ev.pack_skip_pixels;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.pack_skip_pixels);
#endif

#ifdef GL_PACK_SKIP_ROWS
	x = ev.pack_skip_rows;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.pack_skip_rows);
#endif

#ifdef GL_PACK_SWAP_BYTES
	x = ev.pack_swap_bytes;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.pack_swap_bytes);
#endif

#ifdef GL_POINT_FADE_THRESHOLD_SIZE
	x = ev.point_fade_threshold_size;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.point_fade_threshold_size);
#endif

#ifdef GL_POINT_SIZE
	x = ev.point_size;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.point_size);
#endif

#ifdef GL_POINT_SIZE_GRANULARITY
	x = ev.point_size_granularity;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.point_size_granularity);
#endif

#ifdef GL_POINT_SIZE_RANGE
	x = ev.point_size_range;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.point_size_range);
#endif

#ifdef GL_POLYGON_OFFSET_FACTOR
	x = ev.polygon_offset_factor;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.polygon_offset_factor);
#endif

#ifdef GL_POLYGON_OFFSET_UNITS
	x = ev.polygon_offset_units;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.polygon_offset_units);
#endif

#ifdef GL_POLYGON_SMOOTH_HINT
	x = ev.polygon_smooth_hint;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.polygon_smooth_hint);
#endif

#ifdef GL_PRIMITIVE_RESTART_INDEX
	x = ev.primitive_restart_index;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.primitive_restart_index);
#endif

#ifdef GL_PROGRAM_BINARY_FORMATS
	x = ev.program_binary_formats;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.program_binary_formats);
#endif

#ifdef GL_PROGRAM_POINT_SIZE
	x = ev.program_point_size;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.program_point_size);
#endif

#ifdef GL_PROVOKING_VERTEX
	x = ev.provoking_vertex;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.provoking_vertex);
#endif

#ifdef GL_READ_BUFFER
	x = ev.read_buffer;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.read_buffer);
#endif

#ifdef GL_SAMPLE_BUFFERS
	x = ev.sample_buffers;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.sample_buffers);
#endif

#ifdef GL_SAMPLE_COVERAGE_INVERT
	x = ev.sample_coverage_invert;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.sample_coverage_invert);
#endif

#ifdef GL_SAMPLE_COVERAGE_VALUE
	x = ev.sample_coverage_value;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.sample_coverage_value);
#endif

#ifdef GL_SAMPLES
	x = ev.samples;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.samples);
#endif

#ifdef GL_SCISSOR_BOX
	x = ev.scissor_box;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.scissor_box);
#endif

#ifdef GL_SHADER_COMPILER
	x = ev.shader_compiler;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.shader_compiler);
#endif

#ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
	x = ev.shader_storage_buffer_offset_alignment;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.shader_storage_buffer_offset_alignment);
#endif

#ifdef GL_SHADER_STORAGE_BUFFER_SIZE
	x = ev.shader_storage_buffer_size;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.shader_storage_buffer_size);
#endif

#ifdef GL_SHADER_STORAGE_BUFFER_START
	x = ev.shader_storage_buffer_start;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.shader_storage_buffer_start);
#endif

#ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	x = ev.smooth_line_width_granularity;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.smooth_line_width_granularity);
#endif

#ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	x = ev.smooth_line_width_range;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.smooth_line_width_range);
#endif

#ifdef GL_STENCIL_BACK_FAIL
	x = ev.stencil_back_fail;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.stencil_back_fail);
#endif

#ifdef GL_STENCIL_BACK_FUNC
	x = ev.stencil_back_func;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.stencil_back_func);
#endif

#ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	x = ev.stencil_back_pass_depth_fail;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.stencil_back_pass_depth_fail);
#endif

#ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	x = ev.stencil_back_pass_depth_pass;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.stencil_back_pass_depth_pass);
#endif

#ifdef GL_STENCIL_BACK_REF
	x = ev.stencil_back_ref;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.stencil_back_ref);
#endif

#ifdef GL_STENCIL_BACK_VALUE_MASK
	x = ev.stencil_back_value_mask;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.stencil_back_value_mask);
#endif

#ifdef GL_STENCIL_BACK_WRITEMASK
	x = ev.stencil_back_writemask;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.stencil_back_writemask);
#endif

#ifdef GL_STENCIL_CLEAR_VALUE
	x = ev.stencil_clear_value;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.stencil_clear_value);
#endif

#ifdef GL_STENCIL_FAIL
	x = ev.stencil_fail;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.stencil_fail);
#endif

#ifdef GL_STENCIL_FUNC
	x = ev.stencil_func;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.stencil_func);
#endif

#ifdef GL_STENCIL_PASS_DEPTH_FAIL
	x = ev.stencil_pass_depth_fail;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.stencil_pass_depth_fail);
#endif

#ifdef GL_STENCIL_PASS_DEPTH_PASS
	x = ev.stencil_pass_depth_pass;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.stencil_pass_depth_pass);
#endif

#ifdef GL_STENCIL_REF
	x = ev.stencil_ref;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.stencil_ref);
#endif

#ifdef GL_STENCIL_VALUE_MASK
	x = ev.stencil_value_mask;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.stencil_value_mask);
#endif

#ifdef GL_STENCIL_WRITEMASK
	x = ev.stencil_writemask;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.stencil_writemask);
#endif

#ifdef GL_STEREO
	x = ev.stereo;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.stereo);
#endif

#ifdef GL_SUBPIXEL_BITS
	x = ev.subpixel_bits;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.subpixel_bits);
#endif

#ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	x = ev.texture_buffer_offset_alignment;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_buffer_offset_alignment);
#endif

#ifdef GL_TEXTURE_COMPRESSION_HINT
	x = ev.texture_compression_hint;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_compression_hint);
#endif

#ifdef GL_TIMESTAMP
	x = ev.timestamp;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.timestamp);
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	x = ev.transform_feedback_buffer_size;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.transform_feedback_buffer_size);
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	x = ev.transform_feedback_buffer_start;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.transform_feedback_buffer_start);
#endif

#ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	x = ev.uniform_buffer_offset_alignment;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.uniform_buffer_offset_alignment);
#endif

#ifdef GL_UNIFORM_BUFFER_SIZE
	x = ev.uniform_buffer_size;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.uniform_buffer_size);
#endif

#ifdef GL_UNIFORM_BUFFER_START
	x = ev.uniform_buffer_start;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.uniform_buffer_start);
#endif

#ifdef GL_UNPACK_ALIGNMENT
	x = ev.unpack_alignment;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.unpack_alignment);
#endif

#ifdef GL_UNPACK_IMAGE_HEIGHT
	x = ev.unpack_image_height;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.unpack_image_height);
#endif

#ifdef GL_UNPACK_LSB_FIRST
	x = ev.unpack_lsb_first;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.unpack_lsb_first);
#endif

#ifdef GL_UNPACK_ROW_LENGTH
	x = ev.unpack_row_length;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.unpack_row_length);
#endif

#ifdef GL_UNPACK_SKIP_IMAGES
	x = ev.unpack_skip_images;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.unpack_skip_images);
#endif

#ifdef GL_UNPACK_SKIP_PIXELS
	x = ev.unpack_skip_pixels;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.unpack_skip_pixels);
#endif

#ifdef GL_UNPACK_SKIP_ROWS
	x = ev.unpack_skip_rows;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.unpack_skip_rows);
#endif

#ifdef GL_UNPACK_SWAP_BYTES
	x = ev.unpack_swap_bytes;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.unpack_swap_bytes);
#endif

#ifdef GL_VIEWPORT
	x = ev.viewport;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.viewport);
#endif

#ifdef GL_VIEWPORT_BOUNDS_RANGE
	x = ev.viewport_bounds_range;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.viewport_bounds_range);
#endif

#ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	x = ev.viewport_index_provoking_vertex;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.viewport_index_provoking_vertex);
#endif

#ifdef GL_VIEWPORT_SUBPIXEL_BITS
	x = ev.viewport_subpixel_bits;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.viewport_subpixel_bits);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
