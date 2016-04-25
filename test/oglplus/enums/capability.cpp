//  File test/oglplus/enums/capability.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_capability

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_capability_tests)

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
	BOOST_CHECK(x == ev.stream_rasterization);
# ifdef GL_TEXTURE_CUBE_MAP_SEAMLESS
	BOOST_CHECK(x != ev.texture_cube_map_seamless);
# endif
#endif

#ifdef GL_TEXTURE_CUBE_MAP_SEAMLESS
	x = ev.texture_cube_map_seamless;
	BOOST_CHECK(x == ev.texture_cube_map_seamless);
#endif
}

BOOST_AUTO_TEST_CASE(enum_capability_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	capability x;
	(void)x;

#ifdef GL_BLEND
	x = ev.blend;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"BLEND"
	) == 0);
#endif

#ifdef GL_BLEND_ADVANCED_COHERENT_KHR
	x = ev.blend_advanced_coherent;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"BLEND_ADVANCED_COHERENT_KHR"
	) == 0);
#endif

#ifdef GL_COLOR_LOGIC_OP
	x = ev.color_logic_op;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"COLOR_LOGIC_OP"
	) == 0);
#endif

#ifdef GL_CULL_FACE
	x = ev.cull_face;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"CULL_FACE"
	) == 0);
#endif

#ifdef GL_DEBUG_OUTPUT_SYNCHRONOUS
	x = ev.debug_output_synchronous;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DEBUG_OUTPUT_SYNCHRONOUS"
	) == 0);
#endif

#ifdef GL_DEPTH_TEST
	x = ev.depth_test;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DEPTH_TEST"
	) == 0);
#endif

#ifdef GL_DITHER
	x = ev.dither;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DITHER"
	) == 0);
#endif

#ifdef GL_FRAGMENT_COVERAGE_TO_COLOR_NV
	x = ev.fragment_coverage_to_color;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"FRAGMENT_COVERAGE_TO_COLOR_NV"
	) == 0);
#endif

#ifdef GL_FRAMEBUFFER_SRGB
	x = ev.framebuffer_srgb;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"FRAMEBUFFER_SRGB"
	) == 0);
#endif

#ifdef GL_LINE_SMOOTH
	x = ev.line_smooth;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"LINE_SMOOTH"
	) == 0);
#endif

#ifdef GL_MULTISAMPLE
	x = ev.multisample;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MULTISAMPLE"
	) == 0);
#endif

#ifdef GL_POLYGON_OFFSET_FILL
	x = ev.polygon_offset_fill;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"POLYGON_OFFSET_FILL"
	) == 0);
#endif

#ifdef GL_POLYGON_OFFSET_LINE
	x = ev.polygon_offset_line;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"POLYGON_OFFSET_LINE"
	) == 0);
#endif

#ifdef GL_POLYGON_OFFSET_POINT
	x = ev.polygon_offset_point;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"POLYGON_OFFSET_POINT"
	) == 0);
#endif

#ifdef GL_POLYGON_SMOOTH
	x = ev.polygon_smooth;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"POLYGON_SMOOTH"
	) == 0);
#endif

#ifdef GL_PRIMITIVE_RESTART
	x = ev.primitive_restart;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PRIMITIVE_RESTART"
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

#ifdef GL_RASTERIZER_DISCARD
	x = ev.rasterizer_discard;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RASTERIZER_DISCARD"
	) == 0);
#endif

#ifdef GL_SAMPLE_ALPHA_TO_COVERAGE
	x = ev.sample_alpha_to_coverage;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SAMPLE_ALPHA_TO_COVERAGE"
	) == 0);
#endif

#ifdef GL_SAMPLE_ALPHA_TO_ONE
	x = ev.sample_alpha_to_one;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SAMPLE_ALPHA_TO_ONE"
	) == 0);
#endif

#ifdef GL_SAMPLE_COVERAGE
	x = ev.sample_coverage;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SAMPLE_COVERAGE"
	) == 0);
#endif

#ifdef GL_SAMPLE_MASK
	x = ev.sample_mask;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SAMPLE_MASK"
	) == 0);
#endif

#ifdef GL_SAMPLE_SHADING
	x = ev.sample_shading;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SAMPLE_SHADING"
	) == 0);
#endif

#ifdef GL_SCISSOR_TEST
	x = ev.scissor_test;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SCISSOR_TEST"
	) == 0);
#endif

#ifdef GL_STENCIL_TEST
	x = ev.stencil_test;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"STENCIL_TEST"
	) == 0);
#endif

#ifdef GL_STREAM_RASTERIZATION_AMD
	x = ev.stream_rasterization;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"STREAM_RASTERIZATION_AMD"
	) == 0);
#endif

#ifdef GL_TEXTURE_CUBE_MAP_SEAMLESS
	x = ev.texture_cube_map_seamless;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_CUBE_MAP_SEAMLESS"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_capability_range)
{
	using namespace oglplus;
	auto count = enum_value_range<capability>().size();

#ifdef GL_BLEND
{
	--count;
	auto r = enum_value_range<capability>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		capability(GL_BLEND)
	) != r.end());
}
#endif

#ifdef GL_BLEND_ADVANCED_COHERENT_KHR
{
	--count;
	auto r = enum_value_range<capability>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		capability(GL_BLEND_ADVANCED_COHERENT_KHR)
	) != r.end());
}
#endif

#ifdef GL_COLOR_LOGIC_OP
{
	--count;
	auto r = enum_value_range<capability>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		capability(GL_COLOR_LOGIC_OP)
	) != r.end());
}
#endif

#ifdef GL_CULL_FACE
{
	--count;
	auto r = enum_value_range<capability>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		capability(GL_CULL_FACE)
	) != r.end());
}
#endif

#ifdef GL_DEBUG_OUTPUT_SYNCHRONOUS
{
	--count;
	auto r = enum_value_range<capability>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		capability(GL_DEBUG_OUTPUT_SYNCHRONOUS)
	) != r.end());
}
#endif

#ifdef GL_DEPTH_TEST
{
	--count;
	auto r = enum_value_range<capability>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		capability(GL_DEPTH_TEST)
	) != r.end());
}
#endif

#ifdef GL_DITHER
{
	--count;
	auto r = enum_value_range<capability>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		capability(GL_DITHER)
	) != r.end());
}
#endif

#ifdef GL_FRAGMENT_COVERAGE_TO_COLOR_NV
{
	--count;
	auto r = enum_value_range<capability>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		capability(GL_FRAGMENT_COVERAGE_TO_COLOR_NV)
	) != r.end());
}
#endif

#ifdef GL_FRAMEBUFFER_SRGB
{
	--count;
	auto r = enum_value_range<capability>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		capability(GL_FRAMEBUFFER_SRGB)
	) != r.end());
}
#endif

#ifdef GL_LINE_SMOOTH
{
	--count;
	auto r = enum_value_range<capability>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		capability(GL_LINE_SMOOTH)
	) != r.end());
}
#endif

#ifdef GL_MULTISAMPLE
{
	--count;
	auto r = enum_value_range<capability>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		capability(GL_MULTISAMPLE)
	) != r.end());
}
#endif

#ifdef GL_POLYGON_OFFSET_FILL
{
	--count;
	auto r = enum_value_range<capability>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		capability(GL_POLYGON_OFFSET_FILL)
	) != r.end());
}
#endif

#ifdef GL_POLYGON_OFFSET_LINE
{
	--count;
	auto r = enum_value_range<capability>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		capability(GL_POLYGON_OFFSET_LINE)
	) != r.end());
}
#endif

#ifdef GL_POLYGON_OFFSET_POINT
{
	--count;
	auto r = enum_value_range<capability>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		capability(GL_POLYGON_OFFSET_POINT)
	) != r.end());
}
#endif

#ifdef GL_POLYGON_SMOOTH
{
	--count;
	auto r = enum_value_range<capability>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		capability(GL_POLYGON_SMOOTH)
	) != r.end());
}
#endif

#ifdef GL_PRIMITIVE_RESTART
{
	--count;
	auto r = enum_value_range<capability>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		capability(GL_PRIMITIVE_RESTART)
	) != r.end());
}
#endif

#ifdef GL_PROGRAM_POINT_SIZE
{
	--count;
	auto r = enum_value_range<capability>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		capability(GL_PROGRAM_POINT_SIZE)
	) != r.end());
}
#endif

#ifdef GL_RASTERIZER_DISCARD
{
	--count;
	auto r = enum_value_range<capability>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		capability(GL_RASTERIZER_DISCARD)
	) != r.end());
}
#endif

#ifdef GL_SAMPLE_ALPHA_TO_COVERAGE
{
	--count;
	auto r = enum_value_range<capability>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		capability(GL_SAMPLE_ALPHA_TO_COVERAGE)
	) != r.end());
}
#endif

#ifdef GL_SAMPLE_ALPHA_TO_ONE
{
	--count;
	auto r = enum_value_range<capability>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		capability(GL_SAMPLE_ALPHA_TO_ONE)
	) != r.end());
}
#endif

#ifdef GL_SAMPLE_COVERAGE
{
	--count;
	auto r = enum_value_range<capability>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		capability(GL_SAMPLE_COVERAGE)
	) != r.end());
}
#endif

#ifdef GL_SAMPLE_MASK
{
	--count;
	auto r = enum_value_range<capability>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		capability(GL_SAMPLE_MASK)
	) != r.end());
}
#endif

#ifdef GL_SAMPLE_SHADING
{
	--count;
	auto r = enum_value_range<capability>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		capability(GL_SAMPLE_SHADING)
	) != r.end());
}
#endif

#ifdef GL_SCISSOR_TEST
{
	--count;
	auto r = enum_value_range<capability>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		capability(GL_SCISSOR_TEST)
	) != r.end());
}
#endif

#ifdef GL_STENCIL_TEST
{
	--count;
	auto r = enum_value_range<capability>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		capability(GL_STENCIL_TEST)
	) != r.end());
}
#endif

#ifdef GL_STREAM_RASTERIZATION_AMD
{
	--count;
	auto r = enum_value_range<capability>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		capability(GL_STREAM_RASTERIZATION_AMD)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_CUBE_MAP_SEAMLESS
{
	--count;
	auto r = enum_value_range<capability>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		capability(GL_TEXTURE_CUBE_MAP_SEAMLESS)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_capability_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	capability x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_BLEND
	x = ev.blend;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.blend);
#endif

#ifdef GL_BLEND_ADVANCED_COHERENT_KHR
	x = ev.blend_advanced_coherent;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.blend_advanced_coherent);
#endif

#ifdef GL_COLOR_LOGIC_OP
	x = ev.color_logic_op;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.color_logic_op);
#endif

#ifdef GL_CULL_FACE
	x = ev.cull_face;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.cull_face);
#endif

#ifdef GL_DEBUG_OUTPUT_SYNCHRONOUS
	x = ev.debug_output_synchronous;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.debug_output_synchronous);
#endif

#ifdef GL_DEPTH_TEST
	x = ev.depth_test;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.depth_test);
#endif

#ifdef GL_DITHER
	x = ev.dither;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.dither);
#endif

#ifdef GL_FRAGMENT_COVERAGE_TO_COLOR_NV
	x = ev.fragment_coverage_to_color;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.fragment_coverage_to_color);
#endif

#ifdef GL_FRAMEBUFFER_SRGB
	x = ev.framebuffer_srgb;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.framebuffer_srgb);
#endif

#ifdef GL_LINE_SMOOTH
	x = ev.line_smooth;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.line_smooth);
#endif

#ifdef GL_MULTISAMPLE
	x = ev.multisample;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.multisample);
#endif

#ifdef GL_POLYGON_OFFSET_FILL
	x = ev.polygon_offset_fill;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.polygon_offset_fill);
#endif

#ifdef GL_POLYGON_OFFSET_LINE
	x = ev.polygon_offset_line;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.polygon_offset_line);
#endif

#ifdef GL_POLYGON_OFFSET_POINT
	x = ev.polygon_offset_point;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.polygon_offset_point);
#endif

#ifdef GL_POLYGON_SMOOTH
	x = ev.polygon_smooth;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.polygon_smooth);
#endif

#ifdef GL_PRIMITIVE_RESTART
	x = ev.primitive_restart;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.primitive_restart);
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

#ifdef GL_RASTERIZER_DISCARD
	x = ev.rasterizer_discard;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.rasterizer_discard);
#endif

#ifdef GL_SAMPLE_ALPHA_TO_COVERAGE
	x = ev.sample_alpha_to_coverage;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.sample_alpha_to_coverage);
#endif

#ifdef GL_SAMPLE_ALPHA_TO_ONE
	x = ev.sample_alpha_to_one;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.sample_alpha_to_one);
#endif

#ifdef GL_SAMPLE_COVERAGE
	x = ev.sample_coverage;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.sample_coverage);
#endif

#ifdef GL_SAMPLE_MASK
	x = ev.sample_mask;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.sample_mask);
#endif

#ifdef GL_SAMPLE_SHADING
	x = ev.sample_shading;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.sample_shading);
#endif

#ifdef GL_SCISSOR_TEST
	x = ev.scissor_test;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.scissor_test);
#endif

#ifdef GL_STENCIL_TEST
	x = ev.stencil_test;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.stencil_test);
#endif

#ifdef GL_STREAM_RASTERIZATION_AMD
	x = ev.stream_rasterization;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.stream_rasterization);
#endif

#ifdef GL_TEXTURE_CUBE_MAP_SEAMLESS
	x = ev.texture_cube_map_seamless;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_cube_map_seamless);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
