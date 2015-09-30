//  File test/oglplus/enums/capability.cpp
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
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE OGLPLUS_capability

#include <boost/test/unit_test.hpp>
#include "common.hpp"

BOOST_AUTO_TEST_SUITE(enum_capability)

BOOST_AUTO_TEST_CASE(enum_capability_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	capability x;
	(void)x;

#ifdef GL_BLEND
	x = ev.blend;
	BOOST_CHECK(x == ev.blend);
# ifdef GL_BLEND_ADVANCED_COHERENT_KHR
	BOOST_CHECK(x != ev.blend_advanced_coherent);
# endif
# ifdef GL_COLOR_LOGIC_OP
	BOOST_CHECK(x != ev.color_logic_op);
# endif
# ifdef GL_CULL_FACE
	BOOST_CHECK(x != ev.cull_face);
# endif
# ifdef GL_DEBUG_OUTPUT_SYNCHRONOUS
	BOOST_CHECK(x != ev.debug_output_synchronous);
# endif
# ifdef GL_DEPTH_TEST
	BOOST_CHECK(x != ev.depth_test);
# endif
# ifdef GL_DITHER
	BOOST_CHECK(x != ev.dither);
# endif
# ifdef GL_FRAGMENT_COVERAGE_TO_COLOR_NV
	BOOST_CHECK(x != ev.fragment_coverage_to_color);
# endif
# ifdef GL_FRAMEBUFFER_SRGB
	BOOST_CHECK(x != ev.framebuffer_srgb);
# endif
# ifdef GL_LINE_SMOOTH
	BOOST_CHECK(x != ev.line_smooth);
# endif
# ifdef GL_MULTISAMPLE
	BOOST_CHECK(x != ev.multisample);
# endif
# ifdef GL_POLYGON_OFFSET_FILL
	BOOST_CHECK(x != ev.polygon_offset_fill);
# endif
# ifdef GL_POLYGON_OFFSET_LINE
	BOOST_CHECK(x != ev.polygon_offset_line);
# endif
# ifdef GL_POLYGON_OFFSET_POINT
	BOOST_CHECK(x != ev.polygon_offset_point);
# endif
# ifdef GL_POLYGON_SMOOTH
	BOOST_CHECK(x != ev.polygon_smooth);
# endif
# ifdef GL_PRIMITIVE_RESTART
	BOOST_CHECK(x != ev.primitive_restart);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_RASTERIZER_DISCARD
	BOOST_CHECK(x != ev.rasterizer_discard);
# endif
# ifdef GL_SAMPLE_ALPHA_TO_COVERAGE
	BOOST_CHECK(x != ev.sample_alpha_to_coverage);
# endif
# ifdef GL_SAMPLE_ALPHA_TO_ONE
	BOOST_CHECK(x != ev.sample_alpha_to_one);
# endif
# ifdef GL_SAMPLE_COVERAGE
	BOOST_CHECK(x != ev.sample_coverage);
# endif
# ifdef GL_SAMPLE_MASK
	BOOST_CHECK(x != ev.sample_mask);
# endif
# ifdef GL_SAMPLE_SHADING
	BOOST_CHECK(x != ev.sample_shading);
# endif
# ifdef GL_SCISSOR_TEST
	BOOST_CHECK(x != ev.scissor_test);
# endif
# ifdef GL_STENCIL_TEST
	BOOST_CHECK(x != ev.stencil_test);
# endif
# ifdef GL_STREAM_RASTERIZATION_AMD
	BOOST_CHECK(x != ev.stream_rasterization);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_SEAMLESS
	BOOST_CHECK(x != ev.texture_cube_map_seamless);
# endif
#endif

#ifdef GL_BLEND_ADVANCED_COHERENT_KHR
	x = ev.blend_advanced_coherent;
# ifdef GL_BLEND
	BOOST_CHECK(x != ev.blend);
# endif
	BOOST_CHECK(x == ev.blend_advanced_coherent);
# ifdef GL_COLOR_LOGIC_OP
	BOOST_CHECK(x != ev.color_logic_op);
# endif
# ifdef GL_CULL_FACE
	BOOST_CHECK(x != ev.cull_face);
# endif
# ifdef GL_DEBUG_OUTPUT_SYNCHRONOUS
	BOOST_CHECK(x != ev.debug_output_synchronous);
# endif
# ifdef GL_DEPTH_TEST
	BOOST_CHECK(x != ev.depth_test);
# endif
# ifdef GL_DITHER
	BOOST_CHECK(x != ev.dither);
# endif
# ifdef GL_FRAGMENT_COVERAGE_TO_COLOR_NV
	BOOST_CHECK(x != ev.fragment_coverage_to_color);
# endif
# ifdef GL_FRAMEBUFFER_SRGB
	BOOST_CHECK(x != ev.framebuffer_srgb);
# endif
# ifdef GL_LINE_SMOOTH
	BOOST_CHECK(x != ev.line_smooth);
# endif
# ifdef GL_MULTISAMPLE
	BOOST_CHECK(x != ev.multisample);
# endif
# ifdef GL_POLYGON_OFFSET_FILL
	BOOST_CHECK(x != ev.polygon_offset_fill);
# endif
# ifdef GL_POLYGON_OFFSET_LINE
	BOOST_CHECK(x != ev.polygon_offset_line);
# endif
# ifdef GL_POLYGON_OFFSET_POINT
	BOOST_CHECK(x != ev.polygon_offset_point);
# endif
# ifdef GL_POLYGON_SMOOTH
	BOOST_CHECK(x != ev.polygon_smooth);
# endif
# ifdef GL_PRIMITIVE_RESTART
	BOOST_CHECK(x != ev.primitive_restart);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_RASTERIZER_DISCARD
	BOOST_CHECK(x != ev.rasterizer_discard);
# endif
# ifdef GL_SAMPLE_ALPHA_TO_COVERAGE
	BOOST_CHECK(x != ev.sample_alpha_to_coverage);
# endif
# ifdef GL_SAMPLE_ALPHA_TO_ONE
	BOOST_CHECK(x != ev.sample_alpha_to_one);
# endif
# ifdef GL_SAMPLE_COVERAGE
	BOOST_CHECK(x != ev.sample_coverage);
# endif
# ifdef GL_SAMPLE_MASK
	BOOST_CHECK(x != ev.sample_mask);
# endif
# ifdef GL_SAMPLE_SHADING
	BOOST_CHECK(x != ev.sample_shading);
# endif
# ifdef GL_SCISSOR_TEST
	BOOST_CHECK(x != ev.scissor_test);
# endif
# ifdef GL_STENCIL_TEST
	BOOST_CHECK(x != ev.stencil_test);
# endif
# ifdef GL_STREAM_RASTERIZATION_AMD
	BOOST_CHECK(x != ev.stream_rasterization);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_SEAMLESS
	BOOST_CHECK(x != ev.texture_cube_map_seamless);
# endif
#endif

#ifdef GL_COLOR_LOGIC_OP
	x = ev.color_logic_op;
# ifdef GL_BLEND
	BOOST_CHECK(x != ev.blend);
# endif
# ifdef GL_BLEND_ADVANCED_COHERENT_KHR
	BOOST_CHECK(x != ev.blend_advanced_coherent);
# endif
	BOOST_CHECK(x == ev.color_logic_op);
# ifdef GL_CULL_FACE
	BOOST_CHECK(x != ev.cull_face);
# endif
# ifdef GL_DEBUG_OUTPUT_SYNCHRONOUS
	BOOST_CHECK(x != ev.debug_output_synchronous);
# endif
# ifdef GL_DEPTH_TEST
	BOOST_CHECK(x != ev.depth_test);
# endif
# ifdef GL_DITHER
	BOOST_CHECK(x != ev.dither);
# endif
# ifdef GL_FRAGMENT_COVERAGE_TO_COLOR_NV
	BOOST_CHECK(x != ev.fragment_coverage_to_color);
# endif
# ifdef GL_FRAMEBUFFER_SRGB
	BOOST_CHECK(x != ev.framebuffer_srgb);
# endif
# ifdef GL_LINE_SMOOTH
	BOOST_CHECK(x != ev.line_smooth);
# endif
# ifdef GL_MULTISAMPLE
	BOOST_CHECK(x != ev.multisample);
# endif
# ifdef GL_POLYGON_OFFSET_FILL
	BOOST_CHECK(x != ev.polygon_offset_fill);
# endif
# ifdef GL_POLYGON_OFFSET_LINE
	BOOST_CHECK(x != ev.polygon_offset_line);
# endif
# ifdef GL_POLYGON_OFFSET_POINT
	BOOST_CHECK(x != ev.polygon_offset_point);
# endif
# ifdef GL_POLYGON_SMOOTH
	BOOST_CHECK(x != ev.polygon_smooth);
# endif
# ifdef GL_PRIMITIVE_RESTART
	BOOST_CHECK(x != ev.primitive_restart);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_RASTERIZER_DISCARD
	BOOST_CHECK(x != ev.rasterizer_discard);
# endif
# ifdef GL_SAMPLE_ALPHA_TO_COVERAGE
	BOOST_CHECK(x != ev.sample_alpha_to_coverage);
# endif
# ifdef GL_SAMPLE_ALPHA_TO_ONE
	BOOST_CHECK(x != ev.sample_alpha_to_one);
# endif
# ifdef GL_SAMPLE_COVERAGE
	BOOST_CHECK(x != ev.sample_coverage);
# endif
# ifdef GL_SAMPLE_MASK
	BOOST_CHECK(x != ev.sample_mask);
# endif
# ifdef GL_SAMPLE_SHADING
	BOOST_CHECK(x != ev.sample_shading);
# endif
# ifdef GL_SCISSOR_TEST
	BOOST_CHECK(x != ev.scissor_test);
# endif
# ifdef GL_STENCIL_TEST
	BOOST_CHECK(x != ev.stencil_test);
# endif
# ifdef GL_STREAM_RASTERIZATION_AMD
	BOOST_CHECK(x != ev.stream_rasterization);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_SEAMLESS
	BOOST_CHECK(x != ev.texture_cube_map_seamless);
# endif
#endif

#ifdef GL_CULL_FACE
	x = ev.cull_face;
# ifdef GL_BLEND
	BOOST_CHECK(x != ev.blend);
# endif
# ifdef GL_BLEND_ADVANCED_COHERENT_KHR
	BOOST_CHECK(x != ev.blend_advanced_coherent);
# endif
# ifdef GL_COLOR_LOGIC_OP
	BOOST_CHECK(x != ev.color_logic_op);
# endif
	BOOST_CHECK(x == ev.cull_face);
# ifdef GL_DEBUG_OUTPUT_SYNCHRONOUS
	BOOST_CHECK(x != ev.debug_output_synchronous);
# endif
# ifdef GL_DEPTH_TEST
	BOOST_CHECK(x != ev.depth_test);
# endif
# ifdef GL_DITHER
	BOOST_CHECK(x != ev.dither);
# endif
# ifdef GL_FRAGMENT_COVERAGE_TO_COLOR_NV
	BOOST_CHECK(x != ev.fragment_coverage_to_color);
# endif
# ifdef GL_FRAMEBUFFER_SRGB
	BOOST_CHECK(x != ev.framebuffer_srgb);
# endif
# ifdef GL_LINE_SMOOTH
	BOOST_CHECK(x != ev.line_smooth);
# endif
# ifdef GL_MULTISAMPLE
	BOOST_CHECK(x != ev.multisample);
# endif
# ifdef GL_POLYGON_OFFSET_FILL
	BOOST_CHECK(x != ev.polygon_offset_fill);
# endif
# ifdef GL_POLYGON_OFFSET_LINE
	BOOST_CHECK(x != ev.polygon_offset_line);
# endif
# ifdef GL_POLYGON_OFFSET_POINT
	BOOST_CHECK(x != ev.polygon_offset_point);
# endif
# ifdef GL_POLYGON_SMOOTH
	BOOST_CHECK(x != ev.polygon_smooth);
# endif
# ifdef GL_PRIMITIVE_RESTART
	BOOST_CHECK(x != ev.primitive_restart);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_RASTERIZER_DISCARD
	BOOST_CHECK(x != ev.rasterizer_discard);
# endif
# ifdef GL_SAMPLE_ALPHA_TO_COVERAGE
	BOOST_CHECK(x != ev.sample_alpha_to_coverage);
# endif
# ifdef GL_SAMPLE_ALPHA_TO_ONE
	BOOST_CHECK(x != ev.sample_alpha_to_one);
# endif
# ifdef GL_SAMPLE_COVERAGE
	BOOST_CHECK(x != ev.sample_coverage);
# endif
# ifdef GL_SAMPLE_MASK
	BOOST_CHECK(x != ev.sample_mask);
# endif
# ifdef GL_SAMPLE_SHADING
	BOOST_CHECK(x != ev.sample_shading);
# endif
# ifdef GL_SCISSOR_TEST
	BOOST_CHECK(x != ev.scissor_test);
# endif
# ifdef GL_STENCIL_TEST
	BOOST_CHECK(x != ev.stencil_test);
# endif
# ifdef GL_STREAM_RASTERIZATION_AMD
	BOOST_CHECK(x != ev.stream_rasterization);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_SEAMLESS
	BOOST_CHECK(x != ev.texture_cube_map_seamless);
# endif
#endif

#ifdef GL_DEBUG_OUTPUT_SYNCHRONOUS
	x = ev.debug_output_synchronous;
# ifdef GL_BLEND
	BOOST_CHECK(x != ev.blend);
# endif
# ifdef GL_BLEND_ADVANCED_COHERENT_KHR
	BOOST_CHECK(x != ev.blend_advanced_coherent);
# endif
# ifdef GL_COLOR_LOGIC_OP
	BOOST_CHECK(x != ev.color_logic_op);
# endif
# ifdef GL_CULL_FACE
	BOOST_CHECK(x != ev.cull_face);
# endif
	BOOST_CHECK(x == ev.debug_output_synchronous);
# ifdef GL_DEPTH_TEST
	BOOST_CHECK(x != ev.depth_test);
# endif
# ifdef GL_DITHER
	BOOST_CHECK(x != ev.dither);
# endif
# ifdef GL_FRAGMENT_COVERAGE_TO_COLOR_NV
	BOOST_CHECK(x != ev.fragment_coverage_to_color);
# endif
# ifdef GL_FRAMEBUFFER_SRGB
	BOOST_CHECK(x != ev.framebuffer_srgb);
# endif
# ifdef GL_LINE_SMOOTH
	BOOST_CHECK(x != ev.line_smooth);
# endif
# ifdef GL_MULTISAMPLE
	BOOST_CHECK(x != ev.multisample);
# endif
# ifdef GL_POLYGON_OFFSET_FILL
	BOOST_CHECK(x != ev.polygon_offset_fill);
# endif
# ifdef GL_POLYGON_OFFSET_LINE
	BOOST_CHECK(x != ev.polygon_offset_line);
# endif
# ifdef GL_POLYGON_OFFSET_POINT
	BOOST_CHECK(x != ev.polygon_offset_point);
# endif
# ifdef GL_POLYGON_SMOOTH
	BOOST_CHECK(x != ev.polygon_smooth);
# endif
# ifdef GL_PRIMITIVE_RESTART
	BOOST_CHECK(x != ev.primitive_restart);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_RASTERIZER_DISCARD
	BOOST_CHECK(x != ev.rasterizer_discard);
# endif
# ifdef GL_SAMPLE_ALPHA_TO_COVERAGE
	BOOST_CHECK(x != ev.sample_alpha_to_coverage);
# endif
# ifdef GL_SAMPLE_ALPHA_TO_ONE
	BOOST_CHECK(x != ev.sample_alpha_to_one);
# endif
# ifdef GL_SAMPLE_COVERAGE
	BOOST_CHECK(x != ev.sample_coverage);
# endif
# ifdef GL_SAMPLE_MASK
	BOOST_CHECK(x != ev.sample_mask);
# endif
# ifdef GL_SAMPLE_SHADING
	BOOST_CHECK(x != ev.sample_shading);
# endif
# ifdef GL_SCISSOR_TEST
	BOOST_CHECK(x != ev.scissor_test);
# endif
# ifdef GL_STENCIL_TEST
	BOOST_CHECK(x != ev.stencil_test);
# endif
# ifdef GL_STREAM_RASTERIZATION_AMD
	BOOST_CHECK(x != ev.stream_rasterization);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_SEAMLESS
	BOOST_CHECK(x != ev.texture_cube_map_seamless);
# endif
#endif

#ifdef GL_DEPTH_TEST
	x = ev.depth_test;
# ifdef GL_BLEND
	BOOST_CHECK(x != ev.blend);
# endif
# ifdef GL_BLEND_ADVANCED_COHERENT_KHR
	BOOST_CHECK(x != ev.blend_advanced_coherent);
# endif
# ifdef GL_COLOR_LOGIC_OP
	BOOST_CHECK(x != ev.color_logic_op);
# endif
# ifdef GL_CULL_FACE
	BOOST_CHECK(x != ev.cull_face);
# endif
# ifdef GL_DEBUG_OUTPUT_SYNCHRONOUS
	BOOST_CHECK(x != ev.debug_output_synchronous);
# endif
	BOOST_CHECK(x == ev.depth_test);
# ifdef GL_DITHER
	BOOST_CHECK(x != ev.dither);
# endif
# ifdef GL_FRAGMENT_COVERAGE_TO_COLOR_NV
	BOOST_CHECK(x != ev.fragment_coverage_to_color);
# endif
# ifdef GL_FRAMEBUFFER_SRGB
	BOOST_CHECK(x != ev.framebuffer_srgb);
# endif
# ifdef GL_LINE_SMOOTH
	BOOST_CHECK(x != ev.line_smooth);
# endif
# ifdef GL_MULTISAMPLE
	BOOST_CHECK(x != ev.multisample);
# endif
# ifdef GL_POLYGON_OFFSET_FILL
	BOOST_CHECK(x != ev.polygon_offset_fill);
# endif
# ifdef GL_POLYGON_OFFSET_LINE
	BOOST_CHECK(x != ev.polygon_offset_line);
# endif
# ifdef GL_POLYGON_OFFSET_POINT
	BOOST_CHECK(x != ev.polygon_offset_point);
# endif
# ifdef GL_POLYGON_SMOOTH
	BOOST_CHECK(x != ev.polygon_smooth);
# endif
# ifdef GL_PRIMITIVE_RESTART
	BOOST_CHECK(x != ev.primitive_restart);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_RASTERIZER_DISCARD
	BOOST_CHECK(x != ev.rasterizer_discard);
# endif
# ifdef GL_SAMPLE_ALPHA_TO_COVERAGE
	BOOST_CHECK(x != ev.sample_alpha_to_coverage);
# endif
# ifdef GL_SAMPLE_ALPHA_TO_ONE
	BOOST_CHECK(x != ev.sample_alpha_to_one);
# endif
# ifdef GL_SAMPLE_COVERAGE
	BOOST_CHECK(x != ev.sample_coverage);
# endif
# ifdef GL_SAMPLE_MASK
	BOOST_CHECK(x != ev.sample_mask);
# endif
# ifdef GL_SAMPLE_SHADING
	BOOST_CHECK(x != ev.sample_shading);
# endif
# ifdef GL_SCISSOR_TEST
	BOOST_CHECK(x != ev.scissor_test);
# endif
# ifdef GL_STENCIL_TEST
	BOOST_CHECK(x != ev.stencil_test);
# endif
# ifdef GL_STREAM_RASTERIZATION_AMD
	BOOST_CHECK(x != ev.stream_rasterization);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_SEAMLESS
	BOOST_CHECK(x != ev.texture_cube_map_seamless);
# endif
#endif

#ifdef GL_DITHER
	x = ev.dither;
# ifdef GL_BLEND
	BOOST_CHECK(x != ev.blend);
# endif
# ifdef GL_BLEND_ADVANCED_COHERENT_KHR
	BOOST_CHECK(x != ev.blend_advanced_coherent);
# endif
# ifdef GL_COLOR_LOGIC_OP
	BOOST_CHECK(x != ev.color_logic_op);
# endif
# ifdef GL_CULL_FACE
	BOOST_CHECK(x != ev.cull_face);
# endif
# ifdef GL_DEBUG_OUTPUT_SYNCHRONOUS
	BOOST_CHECK(x != ev.debug_output_synchronous);
# endif
# ifdef GL_DEPTH_TEST
	BOOST_CHECK(x != ev.depth_test);
# endif
	BOOST_CHECK(x == ev.dither);
# ifdef GL_FRAGMENT_COVERAGE_TO_COLOR_NV
	BOOST_CHECK(x != ev.fragment_coverage_to_color);
# endif
# ifdef GL_FRAMEBUFFER_SRGB
	BOOST_CHECK(x != ev.framebuffer_srgb);
# endif
# ifdef GL_LINE_SMOOTH
	BOOST_CHECK(x != ev.line_smooth);
# endif
# ifdef GL_MULTISAMPLE
	BOOST_CHECK(x != ev.multisample);
# endif
# ifdef GL_POLYGON_OFFSET_FILL
	BOOST_CHECK(x != ev.polygon_offset_fill);
# endif
# ifdef GL_POLYGON_OFFSET_LINE
	BOOST_CHECK(x != ev.polygon_offset_line);
# endif
# ifdef GL_POLYGON_OFFSET_POINT
	BOOST_CHECK(x != ev.polygon_offset_point);
# endif
# ifdef GL_POLYGON_SMOOTH
	BOOST_CHECK(x != ev.polygon_smooth);
# endif
# ifdef GL_PRIMITIVE_RESTART
	BOOST_CHECK(x != ev.primitive_restart);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_RASTERIZER_DISCARD
	BOOST_CHECK(x != ev.rasterizer_discard);
# endif
# ifdef GL_SAMPLE_ALPHA_TO_COVERAGE
	BOOST_CHECK(x != ev.sample_alpha_to_coverage);
# endif
# ifdef GL_SAMPLE_ALPHA_TO_ONE
	BOOST_CHECK(x != ev.sample_alpha_to_one);
# endif
# ifdef GL_SAMPLE_COVERAGE
	BOOST_CHECK(x != ev.sample_coverage);
# endif
# ifdef GL_SAMPLE_MASK
	BOOST_CHECK(x != ev.sample_mask);
# endif
# ifdef GL_SAMPLE_SHADING
	BOOST_CHECK(x != ev.sample_shading);
# endif
# ifdef GL_SCISSOR_TEST
	BOOST_CHECK(x != ev.scissor_test);
# endif
# ifdef GL_STENCIL_TEST
	BOOST_CHECK(x != ev.stencil_test);
# endif
# ifdef GL_STREAM_RASTERIZATION_AMD
	BOOST_CHECK(x != ev.stream_rasterization);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_SEAMLESS
	BOOST_CHECK(x != ev.texture_cube_map_seamless);
# endif
#endif

#ifdef GL_FRAGMENT_COVERAGE_TO_COLOR_NV
	x = ev.fragment_coverage_to_color;
# ifdef GL_BLEND
	BOOST_CHECK(x != ev.blend);
# endif
# ifdef GL_BLEND_ADVANCED_COHERENT_KHR
	BOOST_CHECK(x != ev.blend_advanced_coherent);
# endif
# ifdef GL_COLOR_LOGIC_OP
	BOOST_CHECK(x != ev.color_logic_op);
# endif
# ifdef GL_CULL_FACE
	BOOST_CHECK(x != ev.cull_face);
# endif
# ifdef GL_DEBUG_OUTPUT_SYNCHRONOUS
	BOOST_CHECK(x != ev.debug_output_synchronous);
# endif
# ifdef GL_DEPTH_TEST
	BOOST_CHECK(x != ev.depth_test);
# endif
# ifdef GL_DITHER
	BOOST_CHECK(x != ev.dither);
# endif
	BOOST_CHECK(x == ev.fragment_coverage_to_color);
# ifdef GL_FRAMEBUFFER_SRGB
	BOOST_CHECK(x != ev.framebuffer_srgb);
# endif
# ifdef GL_LINE_SMOOTH
	BOOST_CHECK(x != ev.line_smooth);
# endif
# ifdef GL_MULTISAMPLE
	BOOST_CHECK(x != ev.multisample);
# endif
# ifdef GL_POLYGON_OFFSET_FILL
	BOOST_CHECK(x != ev.polygon_offset_fill);
# endif
# ifdef GL_POLYGON_OFFSET_LINE
	BOOST_CHECK(x != ev.polygon_offset_line);
# endif
# ifdef GL_POLYGON_OFFSET_POINT
	BOOST_CHECK(x != ev.polygon_offset_point);
# endif
# ifdef GL_POLYGON_SMOOTH
	BOOST_CHECK(x != ev.polygon_smooth);
# endif
# ifdef GL_PRIMITIVE_RESTART
	BOOST_CHECK(x != ev.primitive_restart);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_RASTERIZER_DISCARD
	BOOST_CHECK(x != ev.rasterizer_discard);
# endif
# ifdef GL_SAMPLE_ALPHA_TO_COVERAGE
	BOOST_CHECK(x != ev.sample_alpha_to_coverage);
# endif
# ifdef GL_SAMPLE_ALPHA_TO_ONE
	BOOST_CHECK(x != ev.sample_alpha_to_one);
# endif
# ifdef GL_SAMPLE_COVERAGE
	BOOST_CHECK(x != ev.sample_coverage);
# endif
# ifdef GL_SAMPLE_MASK
	BOOST_CHECK(x != ev.sample_mask);
# endif
# ifdef GL_SAMPLE_SHADING
	BOOST_CHECK(x != ev.sample_shading);
# endif
# ifdef GL_SCISSOR_TEST
	BOOST_CHECK(x != ev.scissor_test);
# endif
# ifdef GL_STENCIL_TEST
	BOOST_CHECK(x != ev.stencil_test);
# endif
# ifdef GL_STREAM_RASTERIZATION_AMD
	BOOST_CHECK(x != ev.stream_rasterization);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_SEAMLESS
	BOOST_CHECK(x != ev.texture_cube_map_seamless);
# endif
#endif

#ifdef GL_FRAMEBUFFER_SRGB
	x = ev.framebuffer_srgb;
# ifdef GL_BLEND
	BOOST_CHECK(x != ev.blend);
# endif
# ifdef GL_BLEND_ADVANCED_COHERENT_KHR
	BOOST_CHECK(x != ev.blend_advanced_coherent);
# endif
# ifdef GL_COLOR_LOGIC_OP
	BOOST_CHECK(x != ev.color_logic_op);
# endif
# ifdef GL_CULL_FACE
	BOOST_CHECK(x != ev.cull_face);
# endif
# ifdef GL_DEBUG_OUTPUT_SYNCHRONOUS
	BOOST_CHECK(x != ev.debug_output_synchronous);
# endif
# ifdef GL_DEPTH_TEST
	BOOST_CHECK(x != ev.depth_test);
# endif
# ifdef GL_DITHER
	BOOST_CHECK(x != ev.dither);
# endif
# ifdef GL_FRAGMENT_COVERAGE_TO_COLOR_NV
	BOOST_CHECK(x != ev.fragment_coverage_to_color);
# endif
	BOOST_CHECK(x == ev.framebuffer_srgb);
# ifdef GL_LINE_SMOOTH
	BOOST_CHECK(x != ev.line_smooth);
# endif
# ifdef GL_MULTISAMPLE
	BOOST_CHECK(x != ev.multisample);
# endif
# ifdef GL_POLYGON_OFFSET_FILL
	BOOST_CHECK(x != ev.polygon_offset_fill);
# endif
# ifdef GL_POLYGON_OFFSET_LINE
	BOOST_CHECK(x != ev.polygon_offset_line);
# endif
# ifdef GL_POLYGON_OFFSET_POINT
	BOOST_CHECK(x != ev.polygon_offset_point);
# endif
# ifdef GL_POLYGON_SMOOTH
	BOOST_CHECK(x != ev.polygon_smooth);
# endif
# ifdef GL_PRIMITIVE_RESTART
	BOOST_CHECK(x != ev.primitive_restart);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_RASTERIZER_DISCARD
	BOOST_CHECK(x != ev.rasterizer_discard);
# endif
# ifdef GL_SAMPLE_ALPHA_TO_COVERAGE
	BOOST_CHECK(x != ev.sample_alpha_to_coverage);
# endif
# ifdef GL_SAMPLE_ALPHA_TO_ONE
	BOOST_CHECK(x != ev.sample_alpha_to_one);
# endif
# ifdef GL_SAMPLE_COVERAGE
	BOOST_CHECK(x != ev.sample_coverage);
# endif
# ifdef GL_SAMPLE_MASK
	BOOST_CHECK(x != ev.sample_mask);
# endif
# ifdef GL_SAMPLE_SHADING
	BOOST_CHECK(x != ev.sample_shading);
# endif
# ifdef GL_SCISSOR_TEST
	BOOST_CHECK(x != ev.scissor_test);
# endif
# ifdef GL_STENCIL_TEST
	BOOST_CHECK(x != ev.stencil_test);
# endif
# ifdef GL_STREAM_RASTERIZATION_AMD
	BOOST_CHECK(x != ev.stream_rasterization);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_SEAMLESS
	BOOST_CHECK(x != ev.texture_cube_map_seamless);
# endif
#endif

#ifdef GL_LINE_SMOOTH
	x = ev.line_smooth;
# ifdef GL_BLEND
	BOOST_CHECK(x != ev.blend);
# endif
# ifdef GL_BLEND_ADVANCED_COHERENT_KHR
	BOOST_CHECK(x != ev.blend_advanced_coherent);
# endif
# ifdef GL_COLOR_LOGIC_OP
	BOOST_CHECK(x != ev.color_logic_op);
# endif
# ifdef GL_CULL_FACE
	BOOST_CHECK(x != ev.cull_face);
# endif
# ifdef GL_DEBUG_OUTPUT_SYNCHRONOUS
	BOOST_CHECK(x != ev.debug_output_synchronous);
# endif
# ifdef GL_DEPTH_TEST
	BOOST_CHECK(x != ev.depth_test);
# endif
# ifdef GL_DITHER
	BOOST_CHECK(x != ev.dither);
# endif
# ifdef GL_FRAGMENT_COVERAGE_TO_COLOR_NV
	BOOST_CHECK(x != ev.fragment_coverage_to_color);
# endif
# ifdef GL_FRAMEBUFFER_SRGB
	BOOST_CHECK(x != ev.framebuffer_srgb);
# endif
	BOOST_CHECK(x == ev.line_smooth);
# ifdef GL_MULTISAMPLE
	BOOST_CHECK(x != ev.multisample);
# endif
# ifdef GL_POLYGON_OFFSET_FILL
	BOOST_CHECK(x != ev.polygon_offset_fill);
# endif
# ifdef GL_POLYGON_OFFSET_LINE
	BOOST_CHECK(x != ev.polygon_offset_line);
# endif
# ifdef GL_POLYGON_OFFSET_POINT
	BOOST_CHECK(x != ev.polygon_offset_point);
# endif
# ifdef GL_POLYGON_SMOOTH
	BOOST_CHECK(x != ev.polygon_smooth);
# endif
# ifdef GL_PRIMITIVE_RESTART
	BOOST_CHECK(x != ev.primitive_restart);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_RASTERIZER_DISCARD
	BOOST_CHECK(x != ev.rasterizer_discard);
# endif
# ifdef GL_SAMPLE_ALPHA_TO_COVERAGE
	BOOST_CHECK(x != ev.sample_alpha_to_coverage);
# endif
# ifdef GL_SAMPLE_ALPHA_TO_ONE
	BOOST_CHECK(x != ev.sample_alpha_to_one);
# endif
# ifdef GL_SAMPLE_COVERAGE
	BOOST_CHECK(x != ev.sample_coverage);
# endif
# ifdef GL_SAMPLE_MASK
	BOOST_CHECK(x != ev.sample_mask);
# endif
# ifdef GL_SAMPLE_SHADING
	BOOST_CHECK(x != ev.sample_shading);
# endif
# ifdef GL_SCISSOR_TEST
	BOOST_CHECK(x != ev.scissor_test);
# endif
# ifdef GL_STENCIL_TEST
	BOOST_CHECK(x != ev.stencil_test);
# endif
# ifdef GL_STREAM_RASTERIZATION_AMD
	BOOST_CHECK(x != ev.stream_rasterization);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_SEAMLESS
	BOOST_CHECK(x != ev.texture_cube_map_seamless);
# endif
#endif

#ifdef GL_MULTISAMPLE
	x = ev.multisample;
# ifdef GL_BLEND
	BOOST_CHECK(x != ev.blend);
# endif
# ifdef GL_BLEND_ADVANCED_COHERENT_KHR
	BOOST_CHECK(x != ev.blend_advanced_coherent);
# endif
# ifdef GL_COLOR_LOGIC_OP
	BOOST_CHECK(x != ev.color_logic_op);
# endif
# ifdef GL_CULL_FACE
	BOOST_CHECK(x != ev.cull_face);
# endif
# ifdef GL_DEBUG_OUTPUT_SYNCHRONOUS
	BOOST_CHECK(x != ev.debug_output_synchronous);
# endif
# ifdef GL_DEPTH_TEST
	BOOST_CHECK(x != ev.depth_test);
# endif
# ifdef GL_DITHER
	BOOST_CHECK(x != ev.dither);
# endif
# ifdef GL_FRAGMENT_COVERAGE_TO_COLOR_NV
	BOOST_CHECK(x != ev.fragment_coverage_to_color);
# endif
# ifdef GL_FRAMEBUFFER_SRGB
	BOOST_CHECK(x != ev.framebuffer_srgb);
# endif
# ifdef GL_LINE_SMOOTH
	BOOST_CHECK(x != ev.line_smooth);
# endif
	BOOST_CHECK(x == ev.multisample);
# ifdef GL_POLYGON_OFFSET_FILL
	BOOST_CHECK(x != ev.polygon_offset_fill);
# endif
# ifdef GL_POLYGON_OFFSET_LINE
	BOOST_CHECK(x != ev.polygon_offset_line);
# endif
# ifdef GL_POLYGON_OFFSET_POINT
	BOOST_CHECK(x != ev.polygon_offset_point);
# endif
# ifdef GL_POLYGON_SMOOTH
	BOOST_CHECK(x != ev.polygon_smooth);
# endif
# ifdef GL_PRIMITIVE_RESTART
	BOOST_CHECK(x != ev.primitive_restart);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_RASTERIZER_DISCARD
	BOOST_CHECK(x != ev.rasterizer_discard);
# endif
# ifdef GL_SAMPLE_ALPHA_TO_COVERAGE
	BOOST_CHECK(x != ev.sample_alpha_to_coverage);
# endif
# ifdef GL_SAMPLE_ALPHA_TO_ONE
	BOOST_CHECK(x != ev.sample_alpha_to_one);
# endif
# ifdef GL_SAMPLE_COVERAGE
	BOOST_CHECK(x != ev.sample_coverage);
# endif
# ifdef GL_SAMPLE_MASK
	BOOST_CHECK(x != ev.sample_mask);
# endif
# ifdef GL_SAMPLE_SHADING
	BOOST_CHECK(x != ev.sample_shading);
# endif
# ifdef GL_SCISSOR_TEST
	BOOST_CHECK(x != ev.scissor_test);
# endif
# ifdef GL_STENCIL_TEST
	BOOST_CHECK(x != ev.stencil_test);
# endif
# ifdef GL_STREAM_RASTERIZATION_AMD
	BOOST_CHECK(x != ev.stream_rasterization);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_SEAMLESS
	BOOST_CHECK(x != ev.texture_cube_map_seamless);
# endif
#endif

#ifdef GL_POLYGON_OFFSET_FILL
	x = ev.polygon_offset_fill;
# ifdef GL_BLEND
	BOOST_CHECK(x != ev.blend);
# endif
# ifdef GL_BLEND_ADVANCED_COHERENT_KHR
	BOOST_CHECK(x != ev.blend_advanced_coherent);
# endif
# ifdef GL_COLOR_LOGIC_OP
	BOOST_CHECK(x != ev.color_logic_op);
# endif
# ifdef GL_CULL_FACE
	BOOST_CHECK(x != ev.cull_face);
# endif
# ifdef GL_DEBUG_OUTPUT_SYNCHRONOUS
	BOOST_CHECK(x != ev.debug_output_synchronous);
# endif
# ifdef GL_DEPTH_TEST
	BOOST_CHECK(x != ev.depth_test);
# endif
# ifdef GL_DITHER
	BOOST_CHECK(x != ev.dither);
# endif
# ifdef GL_FRAGMENT_COVERAGE_TO_COLOR_NV
	BOOST_CHECK(x != ev.fragment_coverage_to_color);
# endif
# ifdef GL_FRAMEBUFFER_SRGB
	BOOST_CHECK(x != ev.framebuffer_srgb);
# endif
# ifdef GL_LINE_SMOOTH
	BOOST_CHECK(x != ev.line_smooth);
# endif
# ifdef GL_MULTISAMPLE
	BOOST_CHECK(x != ev.multisample);
# endif
	BOOST_CHECK(x == ev.polygon_offset_fill);
# ifdef GL_POLYGON_OFFSET_LINE
	BOOST_CHECK(x != ev.polygon_offset_line);
# endif
# ifdef GL_POLYGON_OFFSET_POINT
	BOOST_CHECK(x != ev.polygon_offset_point);
# endif
# ifdef GL_POLYGON_SMOOTH
	BOOST_CHECK(x != ev.polygon_smooth);
# endif
# ifdef GL_PRIMITIVE_RESTART
	BOOST_CHECK(x != ev.primitive_restart);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_RASTERIZER_DISCARD
	BOOST_CHECK(x != ev.rasterizer_discard);
# endif
# ifdef GL_SAMPLE_ALPHA_TO_COVERAGE
	BOOST_CHECK(x != ev.sample_alpha_to_coverage);
# endif
# ifdef GL_SAMPLE_ALPHA_TO_ONE
	BOOST_CHECK(x != ev.sample_alpha_to_one);
# endif
# ifdef GL_SAMPLE_COVERAGE
	BOOST_CHECK(x != ev.sample_coverage);
# endif
# ifdef GL_SAMPLE_MASK
	BOOST_CHECK(x != ev.sample_mask);
# endif
# ifdef GL_SAMPLE_SHADING
	BOOST_CHECK(x != ev.sample_shading);
# endif
# ifdef GL_SCISSOR_TEST
	BOOST_CHECK(x != ev.scissor_test);
# endif
# ifdef GL_STENCIL_TEST
	BOOST_CHECK(x != ev.stencil_test);
# endif
# ifdef GL_STREAM_RASTERIZATION_AMD
	BOOST_CHECK(x != ev.stream_rasterization);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_SEAMLESS
	BOOST_CHECK(x != ev.texture_cube_map_seamless);
# endif
#endif

#ifdef GL_POLYGON_OFFSET_LINE
	x = ev.polygon_offset_line;
# ifdef GL_BLEND
	BOOST_CHECK(x != ev.blend);
# endif
# ifdef GL_BLEND_ADVANCED_COHERENT_KHR
	BOOST_CHECK(x != ev.blend_advanced_coherent);
# endif
# ifdef GL_COLOR_LOGIC_OP
	BOOST_CHECK(x != ev.color_logic_op);
# endif
# ifdef GL_CULL_FACE
	BOOST_CHECK(x != ev.cull_face);
# endif
# ifdef GL_DEBUG_OUTPUT_SYNCHRONOUS
	BOOST_CHECK(x != ev.debug_output_synchronous);
# endif
# ifdef GL_DEPTH_TEST
	BOOST_CHECK(x != ev.depth_test);
# endif
# ifdef GL_DITHER
	BOOST_CHECK(x != ev.dither);
# endif
# ifdef GL_FRAGMENT_COVERAGE_TO_COLOR_NV
	BOOST_CHECK(x != ev.fragment_coverage_to_color);
# endif
# ifdef GL_FRAMEBUFFER_SRGB
	BOOST_CHECK(x != ev.framebuffer_srgb);
# endif
# ifdef GL_LINE_SMOOTH
	BOOST_CHECK(x != ev.line_smooth);
# endif
# ifdef GL_MULTISAMPLE
	BOOST_CHECK(x != ev.multisample);
# endif
# ifdef GL_POLYGON_OFFSET_FILL
	BOOST_CHECK(x != ev.polygon_offset_fill);
# endif
	BOOST_CHECK(x == ev.polygon_offset_line);
# ifdef GL_POLYGON_OFFSET_POINT
	BOOST_CHECK(x != ev.polygon_offset_point);
# endif
# ifdef GL_POLYGON_SMOOTH
	BOOST_CHECK(x != ev.polygon_smooth);
# endif
# ifdef GL_PRIMITIVE_RESTART
	BOOST_CHECK(x != ev.primitive_restart);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_RASTERIZER_DISCARD
	BOOST_CHECK(x != ev.rasterizer_discard);
# endif
# ifdef GL_SAMPLE_ALPHA_TO_COVERAGE
	BOOST_CHECK(x != ev.sample_alpha_to_coverage);
# endif
# ifdef GL_SAMPLE_ALPHA_TO_ONE
	BOOST_CHECK(x != ev.sample_alpha_to_one);
# endif
# ifdef GL_SAMPLE_COVERAGE
	BOOST_CHECK(x != ev.sample_coverage);
# endif
# ifdef GL_SAMPLE_MASK
	BOOST_CHECK(x != ev.sample_mask);
# endif
# ifdef GL_SAMPLE_SHADING
	BOOST_CHECK(x != ev.sample_shading);
# endif
# ifdef GL_SCISSOR_TEST
	BOOST_CHECK(x != ev.scissor_test);
# endif
# ifdef GL_STENCIL_TEST
	BOOST_CHECK(x != ev.stencil_test);
# endif
# ifdef GL_STREAM_RASTERIZATION_AMD
	BOOST_CHECK(x != ev.stream_rasterization);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_SEAMLESS
	BOOST_CHECK(x != ev.texture_cube_map_seamless);
# endif
#endif

#ifdef GL_POLYGON_OFFSET_POINT
	x = ev.polygon_offset_point;
# ifdef GL_BLEND
	BOOST_CHECK(x != ev.blend);
# endif
# ifdef GL_BLEND_ADVANCED_COHERENT_KHR
	BOOST_CHECK(x != ev.blend_advanced_coherent);
# endif
# ifdef GL_COLOR_LOGIC_OP
	BOOST_CHECK(x != ev.color_logic_op);
# endif
# ifdef GL_CULL_FACE
	BOOST_CHECK(x != ev.cull_face);
# endif
# ifdef GL_DEBUG_OUTPUT_SYNCHRONOUS
	BOOST_CHECK(x != ev.debug_output_synchronous);
# endif
# ifdef GL_DEPTH_TEST
	BOOST_CHECK(x != ev.depth_test);
# endif
# ifdef GL_DITHER
	BOOST_CHECK(x != ev.dither);
# endif
# ifdef GL_FRAGMENT_COVERAGE_TO_COLOR_NV
	BOOST_CHECK(x != ev.fragment_coverage_to_color);
# endif
# ifdef GL_FRAMEBUFFER_SRGB
	BOOST_CHECK(x != ev.framebuffer_srgb);
# endif
# ifdef GL_LINE_SMOOTH
	BOOST_CHECK(x != ev.line_smooth);
# endif
# ifdef GL_MULTISAMPLE
	BOOST_CHECK(x != ev.multisample);
# endif
# ifdef GL_POLYGON_OFFSET_FILL
	BOOST_CHECK(x != ev.polygon_offset_fill);
# endif
# ifdef GL_POLYGON_OFFSET_LINE
	BOOST_CHECK(x != ev.polygon_offset_line);
# endif
	BOOST_CHECK(x == ev.polygon_offset_point);
# ifdef GL_POLYGON_SMOOTH
	BOOST_CHECK(x != ev.polygon_smooth);
# endif
# ifdef GL_PRIMITIVE_RESTART
	BOOST_CHECK(x != ev.primitive_restart);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_RASTERIZER_DISCARD
	BOOST_CHECK(x != ev.rasterizer_discard);
# endif
# ifdef GL_SAMPLE_ALPHA_TO_COVERAGE
	BOOST_CHECK(x != ev.sample_alpha_to_coverage);
# endif
# ifdef GL_SAMPLE_ALPHA_TO_ONE
	BOOST_CHECK(x != ev.sample_alpha_to_one);
# endif
# ifdef GL_SAMPLE_COVERAGE
	BOOST_CHECK(x != ev.sample_coverage);
# endif
# ifdef GL_SAMPLE_MASK
	BOOST_CHECK(x != ev.sample_mask);
# endif
# ifdef GL_SAMPLE_SHADING
	BOOST_CHECK(x != ev.sample_shading);
# endif
# ifdef GL_SCISSOR_TEST
	BOOST_CHECK(x != ev.scissor_test);
# endif
# ifdef GL_STENCIL_TEST
	BOOST_CHECK(x != ev.stencil_test);
# endif
# ifdef GL_STREAM_RASTERIZATION_AMD
	BOOST_CHECK(x != ev.stream_rasterization);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_SEAMLESS
	BOOST_CHECK(x != ev.texture_cube_map_seamless);
# endif
#endif

#ifdef GL_POLYGON_SMOOTH
	x = ev.polygon_smooth;
# ifdef GL_BLEND
	BOOST_CHECK(x != ev.blend);
# endif
# ifdef GL_BLEND_ADVANCED_COHERENT_KHR
	BOOST_CHECK(x != ev.blend_advanced_coherent);
# endif
# ifdef GL_COLOR_LOGIC_OP
	BOOST_CHECK(x != ev.color_logic_op);
# endif
# ifdef GL_CULL_FACE
	BOOST_CHECK(x != ev.cull_face);
# endif
# ifdef GL_DEBUG_OUTPUT_SYNCHRONOUS
	BOOST_CHECK(x != ev.debug_output_synchronous);
# endif
# ifdef GL_DEPTH_TEST
	BOOST_CHECK(x != ev.depth_test);
# endif
# ifdef GL_DITHER
	BOOST_CHECK(x != ev.dither);
# endif
# ifdef GL_FRAGMENT_COVERAGE_TO_COLOR_NV
	BOOST_CHECK(x != ev.fragment_coverage_to_color);
# endif
# ifdef GL_FRAMEBUFFER_SRGB
	BOOST_CHECK(x != ev.framebuffer_srgb);
# endif
# ifdef GL_LINE_SMOOTH
	BOOST_CHECK(x != ev.line_smooth);
# endif
# ifdef GL_MULTISAMPLE
	BOOST_CHECK(x != ev.multisample);
# endif
# ifdef GL_POLYGON_OFFSET_FILL
	BOOST_CHECK(x != ev.polygon_offset_fill);
# endif
# ifdef GL_POLYGON_OFFSET_LINE
	BOOST_CHECK(x != ev.polygon_offset_line);
# endif
# ifdef GL_POLYGON_OFFSET_POINT
	BOOST_CHECK(x != ev.polygon_offset_point);
# endif
	BOOST_CHECK(x == ev.polygon_smooth);
# ifdef GL_PRIMITIVE_RESTART
	BOOST_CHECK(x != ev.primitive_restart);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_RASTERIZER_DISCARD
	BOOST_CHECK(x != ev.rasterizer_discard);
# endif
# ifdef GL_SAMPLE_ALPHA_TO_COVERAGE
	BOOST_CHECK(x != ev.sample_alpha_to_coverage);
# endif
# ifdef GL_SAMPLE_ALPHA_TO_ONE
	BOOST_CHECK(x != ev.sample_alpha_to_one);
# endif
# ifdef GL_SAMPLE_COVERAGE
	BOOST_CHECK(x != ev.sample_coverage);
# endif
# ifdef GL_SAMPLE_MASK
	BOOST_CHECK(x != ev.sample_mask);
# endif
# ifdef GL_SAMPLE_SHADING
	BOOST_CHECK(x != ev.sample_shading);
# endif
# ifdef GL_SCISSOR_TEST
	BOOST_CHECK(x != ev.scissor_test);
# endif
# ifdef GL_STENCIL_TEST
	BOOST_CHECK(x != ev.stencil_test);
# endif
# ifdef GL_STREAM_RASTERIZATION_AMD
	BOOST_CHECK(x != ev.stream_rasterization);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_SEAMLESS
	BOOST_CHECK(x != ev.texture_cube_map_seamless);
# endif
#endif

#ifdef GL_PRIMITIVE_RESTART
	x = ev.primitive_restart;
# ifdef GL_BLEND
	BOOST_CHECK(x != ev.blend);
# endif
# ifdef GL_BLEND_ADVANCED_COHERENT_KHR
	BOOST_CHECK(x != ev.blend_advanced_coherent);
# endif
# ifdef GL_COLOR_LOGIC_OP
	BOOST_CHECK(x != ev.color_logic_op);
# endif
# ifdef GL_CULL_FACE
	BOOST_CHECK(x != ev.cull_face);
# endif
# ifdef GL_DEBUG_OUTPUT_SYNCHRONOUS
	BOOST_CHECK(x != ev.debug_output_synchronous);
# endif
# ifdef GL_DEPTH_TEST
	BOOST_CHECK(x != ev.depth_test);
# endif
# ifdef GL_DITHER
	BOOST_CHECK(x != ev.dither);
# endif
# ifdef GL_FRAGMENT_COVERAGE_TO_COLOR_NV
	BOOST_CHECK(x != ev.fragment_coverage_to_color);
# endif
# ifdef GL_FRAMEBUFFER_SRGB
	BOOST_CHECK(x != ev.framebuffer_srgb);
# endif
# ifdef GL_LINE_SMOOTH
	BOOST_CHECK(x != ev.line_smooth);
# endif
# ifdef GL_MULTISAMPLE
	BOOST_CHECK(x != ev.multisample);
# endif
# ifdef GL_POLYGON_OFFSET_FILL
	BOOST_CHECK(x != ev.polygon_offset_fill);
# endif
# ifdef GL_POLYGON_OFFSET_LINE
	BOOST_CHECK(x != ev.polygon_offset_line);
# endif
# ifdef GL_POLYGON_OFFSET_POINT
	BOOST_CHECK(x != ev.polygon_offset_point);
# endif
# ifdef GL_POLYGON_SMOOTH
	BOOST_CHECK(x != ev.polygon_smooth);
# endif
	BOOST_CHECK(x == ev.primitive_restart);
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_RASTERIZER_DISCARD
	BOOST_CHECK(x != ev.rasterizer_discard);
# endif
# ifdef GL_SAMPLE_ALPHA_TO_COVERAGE
	BOOST_CHECK(x != ev.sample_alpha_to_coverage);
# endif
# ifdef GL_SAMPLE_ALPHA_TO_ONE
	BOOST_CHECK(x != ev.sample_alpha_to_one);
# endif
# ifdef GL_SAMPLE_COVERAGE
	BOOST_CHECK(x != ev.sample_coverage);
# endif
# ifdef GL_SAMPLE_MASK
	BOOST_CHECK(x != ev.sample_mask);
# endif
# ifdef GL_SAMPLE_SHADING
	BOOST_CHECK(x != ev.sample_shading);
# endif
# ifdef GL_SCISSOR_TEST
	BOOST_CHECK(x != ev.scissor_test);
# endif
# ifdef GL_STENCIL_TEST
	BOOST_CHECK(x != ev.stencil_test);
# endif
# ifdef GL_STREAM_RASTERIZATION_AMD
	BOOST_CHECK(x != ev.stream_rasterization);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_SEAMLESS
	BOOST_CHECK(x != ev.texture_cube_map_seamless);
# endif
#endif

#ifdef GL_PROGRAM_POINT_SIZE
	x = ev.program_point_size;
# ifdef GL_BLEND
	BOOST_CHECK(x != ev.blend);
# endif
# ifdef GL_BLEND_ADVANCED_COHERENT_KHR
	BOOST_CHECK(x != ev.blend_advanced_coherent);
# endif
# ifdef GL_COLOR_LOGIC_OP
	BOOST_CHECK(x != ev.color_logic_op);
# endif
# ifdef GL_CULL_FACE
	BOOST_CHECK(x != ev.cull_face);
# endif
# ifdef GL_DEBUG_OUTPUT_SYNCHRONOUS
	BOOST_CHECK(x != ev.debug_output_synchronous);
# endif
# ifdef GL_DEPTH_TEST
	BOOST_CHECK(x != ev.depth_test);
# endif
# ifdef GL_DITHER
	BOOST_CHECK(x != ev.dither);
# endif
# ifdef GL_FRAGMENT_COVERAGE_TO_COLOR_NV
	BOOST_CHECK(x != ev.fragment_coverage_to_color);
# endif
# ifdef GL_FRAMEBUFFER_SRGB
	BOOST_CHECK(x != ev.framebuffer_srgb);
# endif
# ifdef GL_LINE_SMOOTH
	BOOST_CHECK(x != ev.line_smooth);
# endif
# ifdef GL_MULTISAMPLE
	BOOST_CHECK(x != ev.multisample);
# endif
# ifdef GL_POLYGON_OFFSET_FILL
	BOOST_CHECK(x != ev.polygon_offset_fill);
# endif
# ifdef GL_POLYGON_OFFSET_LINE
	BOOST_CHECK(x != ev.polygon_offset_line);
# endif
# ifdef GL_POLYGON_OFFSET_POINT
	BOOST_CHECK(x != ev.polygon_offset_point);
# endif
# ifdef GL_POLYGON_SMOOTH
	BOOST_CHECK(x != ev.polygon_smooth);
# endif
# ifdef GL_PRIMITIVE_RESTART
	BOOST_CHECK(x != ev.primitive_restart);
# endif
	BOOST_CHECK(x == ev.program_point_size);
# ifdef GL_RASTERIZER_DISCARD
	BOOST_CHECK(x != ev.rasterizer_discard);
# endif
# ifdef GL_SAMPLE_ALPHA_TO_COVERAGE
	BOOST_CHECK(x != ev.sample_alpha_to_coverage);
# endif
# ifdef GL_SAMPLE_ALPHA_TO_ONE
	BOOST_CHECK(x != ev.sample_alpha_to_one);
# endif
# ifdef GL_SAMPLE_COVERAGE
	BOOST_CHECK(x != ev.sample_coverage);
# endif
# ifdef GL_SAMPLE_MASK
	BOOST_CHECK(x != ev.sample_mask);
# endif
# ifdef GL_SAMPLE_SHADING
	BOOST_CHECK(x != ev.sample_shading);
# endif
# ifdef GL_SCISSOR_TEST
	BOOST_CHECK(x != ev.scissor_test);
# endif
# ifdef GL_STENCIL_TEST
	BOOST_CHECK(x != ev.stencil_test);
# endif
# ifdef GL_STREAM_RASTERIZATION_AMD
	BOOST_CHECK(x != ev.stream_rasterization);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_SEAMLESS
	BOOST_CHECK(x != ev.texture_cube_map_seamless);
# endif
#endif

#ifdef GL_RASTERIZER_DISCARD
	x = ev.rasterizer_discard;
# ifdef GL_BLEND
	BOOST_CHECK(x != ev.blend);
# endif
# ifdef GL_BLEND_ADVANCED_COHERENT_KHR
	BOOST_CHECK(x != ev.blend_advanced_coherent);
# endif
# ifdef GL_COLOR_LOGIC_OP
	BOOST_CHECK(x != ev.color_logic_op);
# endif
# ifdef GL_CULL_FACE
	BOOST_CHECK(x != ev.cull_face);
# endif
# ifdef GL_DEBUG_OUTPUT_SYNCHRONOUS
	BOOST_CHECK(x != ev.debug_output_synchronous);
# endif
# ifdef GL_DEPTH_TEST
	BOOST_CHECK(x != ev.depth_test);
# endif
# ifdef GL_DITHER
	BOOST_CHECK(x != ev.dither);
# endif
# ifdef GL_FRAGMENT_COVERAGE_TO_COLOR_NV
	BOOST_CHECK(x != ev.fragment_coverage_to_color);
# endif
# ifdef GL_FRAMEBUFFER_SRGB
	BOOST_CHECK(x != ev.framebuffer_srgb);
# endif
# ifdef GL_LINE_SMOOTH
	BOOST_CHECK(x != ev.line_smooth);
# endif
# ifdef GL_MULTISAMPLE
	BOOST_CHECK(x != ev.multisample);
# endif
# ifdef GL_POLYGON_OFFSET_FILL
	BOOST_CHECK(x != ev.polygon_offset_fill);
# endif
# ifdef GL_POLYGON_OFFSET_LINE
	BOOST_CHECK(x != ev.polygon_offset_line);
# endif
# ifdef GL_POLYGON_OFFSET_POINT
	BOOST_CHECK(x != ev.polygon_offset_point);
# endif
# ifdef GL_POLYGON_SMOOTH
	BOOST_CHECK(x != ev.polygon_smooth);
# endif
# ifdef GL_PRIMITIVE_RESTART
	BOOST_CHECK(x != ev.primitive_restart);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
	BOOST_CHECK(x == ev.rasterizer_discard);
# ifdef GL_SAMPLE_ALPHA_TO_COVERAGE
	BOOST_CHECK(x != ev.sample_alpha_to_coverage);
# endif
# ifdef GL_SAMPLE_ALPHA_TO_ONE
	BOOST_CHECK(x != ev.sample_alpha_to_one);
# endif
# ifdef GL_SAMPLE_COVERAGE
	BOOST_CHECK(x != ev.sample_coverage);
# endif
# ifdef GL_SAMPLE_MASK
	BOOST_CHECK(x != ev.sample_mask);
# endif
# ifdef GL_SAMPLE_SHADING
	BOOST_CHECK(x != ev.sample_shading);
# endif
# ifdef GL_SCISSOR_TEST
	BOOST_CHECK(x != ev.scissor_test);
# endif
# ifdef GL_STENCIL_TEST
	BOOST_CHECK(x != ev.stencil_test);
# endif
# ifdef GL_STREAM_RASTERIZATION_AMD
	BOOST_CHECK(x != ev.stream_rasterization);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_SEAMLESS
	BOOST_CHECK(x != ev.texture_cube_map_seamless);
# endif
#endif

#ifdef GL_SAMPLE_ALPHA_TO_COVERAGE
	x = ev.sample_alpha_to_coverage;
# ifdef GL_BLEND
	BOOST_CHECK(x != ev.blend);
# endif
# ifdef GL_BLEND_ADVANCED_COHERENT_KHR
	BOOST_CHECK(x != ev.blend_advanced_coherent);
# endif
# ifdef GL_COLOR_LOGIC_OP
	BOOST_CHECK(x != ev.color_logic_op);
# endif
# ifdef GL_CULL_FACE
	BOOST_CHECK(x != ev.cull_face);
# endif
# ifdef GL_DEBUG_OUTPUT_SYNCHRONOUS
	BOOST_CHECK(x != ev.debug_output_synchronous);
# endif
# ifdef GL_DEPTH_TEST
	BOOST_CHECK(x != ev.depth_test);
# endif
# ifdef GL_DITHER
	BOOST_CHECK(x != ev.dither);
# endif
# ifdef GL_FRAGMENT_COVERAGE_TO_COLOR_NV
	BOOST_CHECK(x != ev.fragment_coverage_to_color);
# endif
# ifdef GL_FRAMEBUFFER_SRGB
	BOOST_CHECK(x != ev.framebuffer_srgb);
# endif
# ifdef GL_LINE_SMOOTH
	BOOST_CHECK(x != ev.line_smooth);
# endif
# ifdef GL_MULTISAMPLE
	BOOST_CHECK(x != ev.multisample);
# endif
# ifdef GL_POLYGON_OFFSET_FILL
	BOOST_CHECK(x != ev.polygon_offset_fill);
# endif
# ifdef GL_POLYGON_OFFSET_LINE
	BOOST_CHECK(x != ev.polygon_offset_line);
# endif
# ifdef GL_POLYGON_OFFSET_POINT
	BOOST_CHECK(x != ev.polygon_offset_point);
# endif
# ifdef GL_POLYGON_SMOOTH
	BOOST_CHECK(x != ev.polygon_smooth);
# endif
# ifdef GL_PRIMITIVE_RESTART
	BOOST_CHECK(x != ev.primitive_restart);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_RASTERIZER_DISCARD
	BOOST_CHECK(x != ev.rasterizer_discard);
# endif
	BOOST_CHECK(x == ev.sample_alpha_to_coverage);
# ifdef GL_SAMPLE_ALPHA_TO_ONE
	BOOST_CHECK(x != ev.sample_alpha_to_one);
# endif
# ifdef GL_SAMPLE_COVERAGE
	BOOST_CHECK(x != ev.sample_coverage);
# endif
# ifdef GL_SAMPLE_MASK
	BOOST_CHECK(x != ev.sample_mask);
# endif
# ifdef GL_SAMPLE_SHADING
	BOOST_CHECK(x != ev.sample_shading);
# endif
# ifdef GL_SCISSOR_TEST
	BOOST_CHECK(x != ev.scissor_test);
# endif
# ifdef GL_STENCIL_TEST
	BOOST_CHECK(x != ev.stencil_test);
# endif
# ifdef GL_STREAM_RASTERIZATION_AMD
	BOOST_CHECK(x != ev.stream_rasterization);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_SEAMLESS
	BOOST_CHECK(x != ev.texture_cube_map_seamless);
# endif
#endif

#ifdef GL_SAMPLE_ALPHA_TO_ONE
	x = ev.sample_alpha_to_one;
# ifdef GL_BLEND
	BOOST_CHECK(x != ev.blend);
# endif
# ifdef GL_BLEND_ADVANCED_COHERENT_KHR
	BOOST_CHECK(x != ev.blend_advanced_coherent);
# endif
# ifdef GL_COLOR_LOGIC_OP
	BOOST_CHECK(x != ev.color_logic_op);
# endif
# ifdef GL_CULL_FACE
	BOOST_CHECK(x != ev.cull_face);
# endif
# ifdef GL_DEBUG_OUTPUT_SYNCHRONOUS
	BOOST_CHECK(x != ev.debug_output_synchronous);
# endif
# ifdef GL_DEPTH_TEST
	BOOST_CHECK(x != ev.depth_test);
# endif
# ifdef GL_DITHER
	BOOST_CHECK(x != ev.dither);
# endif
# ifdef GL_FRAGMENT_COVERAGE_TO_COLOR_NV
	BOOST_CHECK(x != ev.fragment_coverage_to_color);
# endif
# ifdef GL_FRAMEBUFFER_SRGB
	BOOST_CHECK(x != ev.framebuffer_srgb);
# endif
# ifdef GL_LINE_SMOOTH
	BOOST_CHECK(x != ev.line_smooth);
# endif
# ifdef GL_MULTISAMPLE
	BOOST_CHECK(x != ev.multisample);
# endif
# ifdef GL_POLYGON_OFFSET_FILL
	BOOST_CHECK(x != ev.polygon_offset_fill);
# endif
# ifdef GL_POLYGON_OFFSET_LINE
	BOOST_CHECK(x != ev.polygon_offset_line);
# endif
# ifdef GL_POLYGON_OFFSET_POINT
	BOOST_CHECK(x != ev.polygon_offset_point);
# endif
# ifdef GL_POLYGON_SMOOTH
	BOOST_CHECK(x != ev.polygon_smooth);
# endif
# ifdef GL_PRIMITIVE_RESTART
	BOOST_CHECK(x != ev.primitive_restart);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_RASTERIZER_DISCARD
	BOOST_CHECK(x != ev.rasterizer_discard);
# endif
# ifdef GL_SAMPLE_ALPHA_TO_COVERAGE
	BOOST_CHECK(x != ev.sample_alpha_to_coverage);
# endif
	BOOST_CHECK(x == ev.sample_alpha_to_one);
# ifdef GL_SAMPLE_COVERAGE
	BOOST_CHECK(x != ev.sample_coverage);
# endif
# ifdef GL_SAMPLE_MASK
	BOOST_CHECK(x != ev.sample_mask);
# endif
# ifdef GL_SAMPLE_SHADING
	BOOST_CHECK(x != ev.sample_shading);
# endif
# ifdef GL_SCISSOR_TEST
	BOOST_CHECK(x != ev.scissor_test);
# endif
# ifdef GL_STENCIL_TEST
	BOOST_CHECK(x != ev.stencil_test);
# endif
# ifdef GL_STREAM_RASTERIZATION_AMD
	BOOST_CHECK(x != ev.stream_rasterization);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_SEAMLESS
	BOOST_CHECK(x != ev.texture_cube_map_seamless);
# endif
#endif

#ifdef GL_SAMPLE_COVERAGE
	x = ev.sample_coverage;
# ifdef GL_BLEND
	BOOST_CHECK(x != ev.blend);
# endif
# ifdef GL_BLEND_ADVANCED_COHERENT_KHR
	BOOST_CHECK(x != ev.blend_advanced_coherent);
# endif
# ifdef GL_COLOR_LOGIC_OP
	BOOST_CHECK(x != ev.color_logic_op);
# endif
# ifdef GL_CULL_FACE
	BOOST_CHECK(x != ev.cull_face);
# endif
# ifdef GL_DEBUG_OUTPUT_SYNCHRONOUS
	BOOST_CHECK(x != ev.debug_output_synchronous);
# endif
# ifdef GL_DEPTH_TEST
	BOOST_CHECK(x != ev.depth_test);
# endif
# ifdef GL_DITHER
	BOOST_CHECK(x != ev.dither);
# endif
# ifdef GL_FRAGMENT_COVERAGE_TO_COLOR_NV
	BOOST_CHECK(x != ev.fragment_coverage_to_color);
# endif
# ifdef GL_FRAMEBUFFER_SRGB
	BOOST_CHECK(x != ev.framebuffer_srgb);
# endif
# ifdef GL_LINE_SMOOTH
	BOOST_CHECK(x != ev.line_smooth);
# endif
# ifdef GL_MULTISAMPLE
	BOOST_CHECK(x != ev.multisample);
# endif
# ifdef GL_POLYGON_OFFSET_FILL
	BOOST_CHECK(x != ev.polygon_offset_fill);
# endif
# ifdef GL_POLYGON_OFFSET_LINE
	BOOST_CHECK(x != ev.polygon_offset_line);
# endif
# ifdef GL_POLYGON_OFFSET_POINT
	BOOST_CHECK(x != ev.polygon_offset_point);
# endif
# ifdef GL_POLYGON_SMOOTH
	BOOST_CHECK(x != ev.polygon_smooth);
# endif
# ifdef GL_PRIMITIVE_RESTART
	BOOST_CHECK(x != ev.primitive_restart);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_RASTERIZER_DISCARD
	BOOST_CHECK(x != ev.rasterizer_discard);
# endif
# ifdef GL_SAMPLE_ALPHA_TO_COVERAGE
	BOOST_CHECK(x != ev.sample_alpha_to_coverage);
# endif
# ifdef GL_SAMPLE_ALPHA_TO_ONE
	BOOST_CHECK(x != ev.sample_alpha_to_one);
# endif
	BOOST_CHECK(x == ev.sample_coverage);
# ifdef GL_SAMPLE_MASK
	BOOST_CHECK(x != ev.sample_mask);
# endif
# ifdef GL_SAMPLE_SHADING
	BOOST_CHECK(x != ev.sample_shading);
# endif
# ifdef GL_SCISSOR_TEST
	BOOST_CHECK(x != ev.scissor_test);
# endif
# ifdef GL_STENCIL_TEST
	BOOST_CHECK(x != ev.stencil_test);
# endif
# ifdef GL_STREAM_RASTERIZATION_AMD
	BOOST_CHECK(x != ev.stream_rasterization);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_SEAMLESS
	BOOST_CHECK(x != ev.texture_cube_map_seamless);
# endif
#endif

#ifdef GL_SAMPLE_MASK
	x = ev.sample_mask;
# ifdef GL_BLEND
	BOOST_CHECK(x != ev.blend);
# endif
# ifdef GL_BLEND_ADVANCED_COHERENT_KHR
	BOOST_CHECK(x != ev.blend_advanced_coherent);
# endif
# ifdef GL_COLOR_LOGIC_OP
	BOOST_CHECK(x != ev.color_logic_op);
# endif
# ifdef GL_CULL_FACE
	BOOST_CHECK(x != ev.cull_face);
# endif
# ifdef GL_DEBUG_OUTPUT_SYNCHRONOUS
	BOOST_CHECK(x != ev.debug_output_synchronous);
# endif
# ifdef GL_DEPTH_TEST
	BOOST_CHECK(x != ev.depth_test);
# endif
# ifdef GL_DITHER
	BOOST_CHECK(x != ev.dither);
# endif
# ifdef GL_FRAGMENT_COVERAGE_TO_COLOR_NV
	BOOST_CHECK(x != ev.fragment_coverage_to_color);
# endif
# ifdef GL_FRAMEBUFFER_SRGB
	BOOST_CHECK(x != ev.framebuffer_srgb);
# endif
# ifdef GL_LINE_SMOOTH
	BOOST_CHECK(x != ev.line_smooth);
# endif
# ifdef GL_MULTISAMPLE
	BOOST_CHECK(x != ev.multisample);
# endif
# ifdef GL_POLYGON_OFFSET_FILL
	BOOST_CHECK(x != ev.polygon_offset_fill);
# endif
# ifdef GL_POLYGON_OFFSET_LINE
	BOOST_CHECK(x != ev.polygon_offset_line);
# endif
# ifdef GL_POLYGON_OFFSET_POINT
	BOOST_CHECK(x != ev.polygon_offset_point);
# endif
# ifdef GL_POLYGON_SMOOTH
	BOOST_CHECK(x != ev.polygon_smooth);
# endif
# ifdef GL_PRIMITIVE_RESTART
	BOOST_CHECK(x != ev.primitive_restart);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_RASTERIZER_DISCARD
	BOOST_CHECK(x != ev.rasterizer_discard);
# endif
# ifdef GL_SAMPLE_ALPHA_TO_COVERAGE
	BOOST_CHECK(x != ev.sample_alpha_to_coverage);
# endif
# ifdef GL_SAMPLE_ALPHA_TO_ONE
	BOOST_CHECK(x != ev.sample_alpha_to_one);
# endif
# ifdef GL_SAMPLE_COVERAGE
	BOOST_CHECK(x != ev.sample_coverage);
# endif
	BOOST_CHECK(x == ev.sample_mask);
# ifdef GL_SAMPLE_SHADING
	BOOST_CHECK(x != ev.sample_shading);
# endif
# ifdef GL_SCISSOR_TEST
	BOOST_CHECK(x != ev.scissor_test);
# endif
# ifdef GL_STENCIL_TEST
	BOOST_CHECK(x != ev.stencil_test);
# endif
# ifdef GL_STREAM_RASTERIZATION_AMD
	BOOST_CHECK(x != ev.stream_rasterization);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_SEAMLESS
	BOOST_CHECK(x != ev.texture_cube_map_seamless);
# endif
#endif

#ifdef GL_SAMPLE_SHADING
	x = ev.sample_shading;
# ifdef GL_BLEND
	BOOST_CHECK(x != ev.blend);
# endif
# ifdef GL_BLEND_ADVANCED_COHERENT_KHR
	BOOST_CHECK(x != ev.blend_advanced_coherent);
# endif
# ifdef GL_COLOR_LOGIC_OP
	BOOST_CHECK(x != ev.color_logic_op);
# endif
# ifdef GL_CULL_FACE
	BOOST_CHECK(x != ev.cull_face);
# endif
# ifdef GL_DEBUG_OUTPUT_SYNCHRONOUS
	BOOST_CHECK(x != ev.debug_output_synchronous);
# endif
# ifdef GL_DEPTH_TEST
	BOOST_CHECK(x != ev.depth_test);
# endif
# ifdef GL_DITHER
	BOOST_CHECK(x != ev.dither);
# endif
# ifdef GL_FRAGMENT_COVERAGE_TO_COLOR_NV
	BOOST_CHECK(x != ev.fragment_coverage_to_color);
# endif
# ifdef GL_FRAMEBUFFER_SRGB
	BOOST_CHECK(x != ev.framebuffer_srgb);
# endif
# ifdef GL_LINE_SMOOTH
	BOOST_CHECK(x != ev.line_smooth);
# endif
# ifdef GL_MULTISAMPLE
	BOOST_CHECK(x != ev.multisample);
# endif
# ifdef GL_POLYGON_OFFSET_FILL
	BOOST_CHECK(x != ev.polygon_offset_fill);
# endif
# ifdef GL_POLYGON_OFFSET_LINE
	BOOST_CHECK(x != ev.polygon_offset_line);
# endif
# ifdef GL_POLYGON_OFFSET_POINT
	BOOST_CHECK(x != ev.polygon_offset_point);
# endif
# ifdef GL_POLYGON_SMOOTH
	BOOST_CHECK(x != ev.polygon_smooth);
# endif
# ifdef GL_PRIMITIVE_RESTART
	BOOST_CHECK(x != ev.primitive_restart);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_RASTERIZER_DISCARD
	BOOST_CHECK(x != ev.rasterizer_discard);
# endif
# ifdef GL_SAMPLE_ALPHA_TO_COVERAGE
	BOOST_CHECK(x != ev.sample_alpha_to_coverage);
# endif
# ifdef GL_SAMPLE_ALPHA_TO_ONE
	BOOST_CHECK(x != ev.sample_alpha_to_one);
# endif
# ifdef GL_SAMPLE_COVERAGE
	BOOST_CHECK(x != ev.sample_coverage);
# endif
# ifdef GL_SAMPLE_MASK
	BOOST_CHECK(x != ev.sample_mask);
# endif
	BOOST_CHECK(x == ev.sample_shading);
# ifdef GL_SCISSOR_TEST
	BOOST_CHECK(x != ev.scissor_test);
# endif
# ifdef GL_STENCIL_TEST
	BOOST_CHECK(x != ev.stencil_test);
# endif
# ifdef GL_STREAM_RASTERIZATION_AMD
	BOOST_CHECK(x != ev.stream_rasterization);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_SEAMLESS
	BOOST_CHECK(x != ev.texture_cube_map_seamless);
# endif
#endif

#ifdef GL_SCISSOR_TEST
	x = ev.scissor_test;
# ifdef GL_BLEND
	BOOST_CHECK(x != ev.blend);
# endif
# ifdef GL_BLEND_ADVANCED_COHERENT_KHR
	BOOST_CHECK(x != ev.blend_advanced_coherent);
# endif
# ifdef GL_COLOR_LOGIC_OP
	BOOST_CHECK(x != ev.color_logic_op);
# endif
# ifdef GL_CULL_FACE
	BOOST_CHECK(x != ev.cull_face);
# endif
# ifdef GL_DEBUG_OUTPUT_SYNCHRONOUS
	BOOST_CHECK(x != ev.debug_output_synchronous);
# endif
# ifdef GL_DEPTH_TEST
	BOOST_CHECK(x != ev.depth_test);
# endif
# ifdef GL_DITHER
	BOOST_CHECK(x != ev.dither);
# endif
# ifdef GL_FRAGMENT_COVERAGE_TO_COLOR_NV
	BOOST_CHECK(x != ev.fragment_coverage_to_color);
# endif
# ifdef GL_FRAMEBUFFER_SRGB
	BOOST_CHECK(x != ev.framebuffer_srgb);
# endif
# ifdef GL_LINE_SMOOTH
	BOOST_CHECK(x != ev.line_smooth);
# endif
# ifdef GL_MULTISAMPLE
	BOOST_CHECK(x != ev.multisample);
# endif
# ifdef GL_POLYGON_OFFSET_FILL
	BOOST_CHECK(x != ev.polygon_offset_fill);
# endif
# ifdef GL_POLYGON_OFFSET_LINE
	BOOST_CHECK(x != ev.polygon_offset_line);
# endif
# ifdef GL_POLYGON_OFFSET_POINT
	BOOST_CHECK(x != ev.polygon_offset_point);
# endif
# ifdef GL_POLYGON_SMOOTH
	BOOST_CHECK(x != ev.polygon_smooth);
# endif
# ifdef GL_PRIMITIVE_RESTART
	BOOST_CHECK(x != ev.primitive_restart);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_RASTERIZER_DISCARD
	BOOST_CHECK(x != ev.rasterizer_discard);
# endif
# ifdef GL_SAMPLE_ALPHA_TO_COVERAGE
	BOOST_CHECK(x != ev.sample_alpha_to_coverage);
# endif
# ifdef GL_SAMPLE_ALPHA_TO_ONE
	BOOST_CHECK(x != ev.sample_alpha_to_one);
# endif
# ifdef GL_SAMPLE_COVERAGE
	BOOST_CHECK(x != ev.sample_coverage);
# endif
# ifdef GL_SAMPLE_MASK
	BOOST_CHECK(x != ev.sample_mask);
# endif
# ifdef GL_SAMPLE_SHADING
	BOOST_CHECK(x != ev.sample_shading);
# endif
	BOOST_CHECK(x == ev.scissor_test);
# ifdef GL_STENCIL_TEST
	BOOST_CHECK(x != ev.stencil_test);
# endif
# ifdef GL_STREAM_RASTERIZATION_AMD
	BOOST_CHECK(x != ev.stream_rasterization);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_SEAMLESS
	BOOST_CHECK(x != ev.texture_cube_map_seamless);
# endif
#endif

#ifdef GL_STENCIL_TEST
	x = ev.stencil_test;
# ifdef GL_BLEND
	BOOST_CHECK(x != ev.blend);
# endif
# ifdef GL_BLEND_ADVANCED_COHERENT_KHR
	BOOST_CHECK(x != ev.blend_advanced_coherent);
# endif
# ifdef GL_COLOR_LOGIC_OP
	BOOST_CHECK(x != ev.color_logic_op);
# endif
# ifdef GL_CULL_FACE
	BOOST_CHECK(x != ev.cull_face);
# endif
# ifdef GL_DEBUG_OUTPUT_SYNCHRONOUS
	BOOST_CHECK(x != ev.debug_output_synchronous);
# endif
# ifdef GL_DEPTH_TEST
	BOOST_CHECK(x != ev.depth_test);
# endif
# ifdef GL_DITHER
	BOOST_CHECK(x != ev.dither);
# endif
# ifdef GL_FRAGMENT_COVERAGE_TO_COLOR_NV
	BOOST_CHECK(x != ev.fragment_coverage_to_color);
# endif
# ifdef GL_FRAMEBUFFER_SRGB
	BOOST_CHECK(x != ev.framebuffer_srgb);
# endif
# ifdef GL_LINE_SMOOTH
	BOOST_CHECK(x != ev.line_smooth);
# endif
# ifdef GL_MULTISAMPLE
	BOOST_CHECK(x != ev.multisample);
# endif
# ifdef GL_POLYGON_OFFSET_FILL
	BOOST_CHECK(x != ev.polygon_offset_fill);
# endif
# ifdef GL_POLYGON_OFFSET_LINE
	BOOST_CHECK(x != ev.polygon_offset_line);
# endif
# ifdef GL_POLYGON_OFFSET_POINT
	BOOST_CHECK(x != ev.polygon_offset_point);
# endif
# ifdef GL_POLYGON_SMOOTH
	BOOST_CHECK(x != ev.polygon_smooth);
# endif
# ifdef GL_PRIMITIVE_RESTART
	BOOST_CHECK(x != ev.primitive_restart);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_RASTERIZER_DISCARD
	BOOST_CHECK(x != ev.rasterizer_discard);
# endif
# ifdef GL_SAMPLE_ALPHA_TO_COVERAGE
	BOOST_CHECK(x != ev.sample_alpha_to_coverage);
# endif
# ifdef GL_SAMPLE_ALPHA_TO_ONE
	BOOST_CHECK(x != ev.sample_alpha_to_one);
# endif
# ifdef GL_SAMPLE_COVERAGE
	BOOST_CHECK(x != ev.sample_coverage);
# endif
# ifdef GL_SAMPLE_MASK
	BOOST_CHECK(x != ev.sample_mask);
# endif
# ifdef GL_SAMPLE_SHADING
	BOOST_CHECK(x != ev.sample_shading);
# endif
# ifdef GL_SCISSOR_TEST
	BOOST_CHECK(x != ev.scissor_test);
# endif
	BOOST_CHECK(x == ev.stencil_test);
# ifdef GL_STREAM_RASTERIZATION_AMD
	BOOST_CHECK(x != ev.stream_rasterization);
# endif
# ifdef GL_TEXTURE_CUBE_MAP_SEAMLESS
	BOOST_CHECK(x != ev.texture_cube_map_seamless);
# endif
#endif

#ifdef GL_STREAM_RASTERIZATION_AMD
	x = ev.stream_rasterization;
# ifdef GL_BLEND
	BOOST_CHECK(x != ev.blend);
# endif
# ifdef GL_BLEND_ADVANCED_COHERENT_KHR
	BOOST_CHECK(x != ev.blend_advanced_coherent);
# endif
# ifdef GL_COLOR_LOGIC_OP
	BOOST_CHECK(x != ev.color_logic_op);
# endif
# ifdef GL_CULL_FACE
	BOOST_CHECK(x != ev.cull_face);
# endif
# ifdef GL_DEBUG_OUTPUT_SYNCHRONOUS
	BOOST_CHECK(x != ev.debug_output_synchronous);
# endif
# ifdef GL_DEPTH_TEST
	BOOST_CHECK(x != ev.depth_test);
# endif
# ifdef GL_DITHER
	BOOST_CHECK(x != ev.dither);
# endif
# ifdef GL_FRAGMENT_COVERAGE_TO_COLOR_NV
	BOOST_CHECK(x != ev.fragment_coverage_to_color);
# endif
# ifdef GL_FRAMEBUFFER_SRGB
	BOOST_CHECK(x != ev.framebuffer_srgb);
# endif
# ifdef GL_LINE_SMOOTH
	BOOST_CHECK(x != ev.line_smooth);
# endif
# ifdef GL_MULTISAMPLE
	BOOST_CHECK(x != ev.multisample);
# endif
# ifdef GL_POLYGON_OFFSET_FILL
	BOOST_CHECK(x != ev.polygon_offset_fill);
# endif
# ifdef GL_POLYGON_OFFSET_LINE
	BOOST_CHECK(x != ev.polygon_offset_line);
# endif
# ifdef GL_POLYGON_OFFSET_POINT
	BOOST_CHECK(x != ev.polygon_offset_point);
# endif
# ifdef GL_POLYGON_SMOOTH
	BOOST_CHECK(x != ev.polygon_smooth);
# endif
# ifdef GL_PRIMITIVE_RESTART
	BOOST_CHECK(x != ev.primitive_restart);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_RASTERIZER_DISCARD
	BOOST_CHECK(x != ev.rasterizer_discard);
# endif
# ifdef GL_SAMPLE_ALPHA_TO_COVERAGE
	BOOST_CHECK(x != ev.sample_alpha_to_coverage);
# endif
# ifdef GL_SAMPLE_ALPHA_TO_ONE
	BOOST_CHECK(x != ev.sample_alpha_to_one);
# endif
# ifdef GL_SAMPLE_COVERAGE
	BOOST_CHECK(x != ev.sample_coverage);
# endif
# ifdef GL_SAMPLE_MASK
	BOOST_CHECK(x != ev.sample_mask);
# endif
# ifdef GL_SAMPLE_SHADING
	BOOST_CHECK(x != ev.sample_shading);
# endif
# ifdef GL_SCISSOR_TEST
	BOOST_CHECK(x != ev.scissor_test);
# endif
# ifdef GL_STENCIL_TEST
	BOOST_CHECK(x != ev.stencil_test);
# endif
	BOOST_CHECK(x == ev.stream_rasterization);
# ifdef GL_TEXTURE_CUBE_MAP_SEAMLESS
	BOOST_CHECK(x != ev.texture_cube_map_seamless);
# endif
#endif

#ifdef GL_TEXTURE_CUBE_MAP_SEAMLESS
	x = ev.texture_cube_map_seamless;
# ifdef GL_BLEND
	BOOST_CHECK(x != ev.blend);
# endif
# ifdef GL_BLEND_ADVANCED_COHERENT_KHR
	BOOST_CHECK(x != ev.blend_advanced_coherent);
# endif
# ifdef GL_COLOR_LOGIC_OP
	BOOST_CHECK(x != ev.color_logic_op);
# endif
# ifdef GL_CULL_FACE
	BOOST_CHECK(x != ev.cull_face);
# endif
# ifdef GL_DEBUG_OUTPUT_SYNCHRONOUS
	BOOST_CHECK(x != ev.debug_output_synchronous);
# endif
# ifdef GL_DEPTH_TEST
	BOOST_CHECK(x != ev.depth_test);
# endif
# ifdef GL_DITHER
	BOOST_CHECK(x != ev.dither);
# endif
# ifdef GL_FRAGMENT_COVERAGE_TO_COLOR_NV
	BOOST_CHECK(x != ev.fragment_coverage_to_color);
# endif
# ifdef GL_FRAMEBUFFER_SRGB
	BOOST_CHECK(x != ev.framebuffer_srgb);
# endif
# ifdef GL_LINE_SMOOTH
	BOOST_CHECK(x != ev.line_smooth);
# endif
# ifdef GL_MULTISAMPLE
	BOOST_CHECK(x != ev.multisample);
# endif
# ifdef GL_POLYGON_OFFSET_FILL
	BOOST_CHECK(x != ev.polygon_offset_fill);
# endif
# ifdef GL_POLYGON_OFFSET_LINE
	BOOST_CHECK(x != ev.polygon_offset_line);
# endif
# ifdef GL_POLYGON_OFFSET_POINT
	BOOST_CHECK(x != ev.polygon_offset_point);
# endif
# ifdef GL_POLYGON_SMOOTH
	BOOST_CHECK(x != ev.polygon_smooth);
# endif
# ifdef GL_PRIMITIVE_RESTART
	BOOST_CHECK(x != ev.primitive_restart);
# endif
# ifdef GL_PROGRAM_POINT_SIZE
	BOOST_CHECK(x != ev.program_point_size);
# endif
# ifdef GL_RASTERIZER_DISCARD
	BOOST_CHECK(x != ev.rasterizer_discard);
# endif
# ifdef GL_SAMPLE_ALPHA_TO_COVERAGE
	BOOST_CHECK(x != ev.sample_alpha_to_coverage);
# endif
# ifdef GL_SAMPLE_ALPHA_TO_ONE
	BOOST_CHECK(x != ev.sample_alpha_to_one);
# endif
# ifdef GL_SAMPLE_COVERAGE
	BOOST_CHECK(x != ev.sample_coverage);
# endif
# ifdef GL_SAMPLE_MASK
	BOOST_CHECK(x != ev.sample_mask);
# endif
# ifdef GL_SAMPLE_SHADING
	BOOST_CHECK(x != ev.sample_shading);
# endif
# ifdef GL_SCISSOR_TEST
	BOOST_CHECK(x != ev.scissor_test);
# endif
# ifdef GL_STENCIL_TEST
	BOOST_CHECK(x != ev.stencil_test);
# endif
# ifdef GL_STREAM_RASTERIZATION_AMD
	BOOST_CHECK(x != ev.stream_rasterization);
# endif
	BOOST_CHECK(x == ev.texture_cube_map_seamless);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
