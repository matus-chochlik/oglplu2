//  File test/oglplus/enums/pixel_data_internal_format.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_pixel_data_internal_format

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_pixel_data_internal_format_tests)

BOOST_AUTO_TEST_CASE(enum_pixel_data_internal_format_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	pixel_data_internal_format x;
	(void)x;

#ifdef GL_COMPRESSED_R11_EAC
	x = ev.compressed_r11_eac;
	BOOST_CHECK(x == ev.compressed_r11_eac);
# ifdef GL_COMPRESSED_RED
	BOOST_CHECK(x != ev.compressed_red);
# endif
# ifdef GL_COMPRESSED_RED_RGTC1
	BOOST_CHECK(x != ev.compressed_red_rgtc1);
# endif
# ifdef GL_COMPRESSED_RG
	BOOST_CHECK(x != ev.compressed_rg);
# endif
# ifdef GL_COMPRESSED_RG11_EAC
	BOOST_CHECK(x != ev.compressed_rg11_eac);
# endif
# ifdef GL_COMPRESSED_RG_RGTC2
	BOOST_CHECK(x != ev.compressed_rg_rgtc2);
# endif
# ifdef GL_COMPRESSED_RGB
	BOOST_CHECK(x != ev.compressed_rgb);
# endif
# ifdef GL_COMPRESSED_RGB8_ETC2
	BOOST_CHECK(x != ev.compressed_rgb8_etc2);
# endif
# ifdef GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2
	BOOST_CHECK(x != ev.compressed_rgb8_punchthrough_alpha1_etc2);
# endif
# ifdef GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT
	BOOST_CHECK(x != ev.compressed_rgb_bptc_signed_float);
# endif
# ifdef GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT
	BOOST_CHECK(x != ev.compressed_rgb_bptc_unsigned_float);
# endif
# ifdef GL_COMPRESSED_RGBA
	BOOST_CHECK(x != ev.compressed_rgba);
# endif
# ifdef GL_COMPRESSED_RGBA8_ETC2_EAC
	BOOST_CHECK(x != ev.compressed_rgba8_etc2_eac);
# endif
# ifdef GL_COMPRESSED_RGBA_BPTC_UNORM
	BOOST_CHECK(x != ev.compressed_rgba_bptc_unorm);
# endif
# ifdef GL_COMPRESSED_SIGNED_R11_EAC
	BOOST_CHECK(x != ev.compressed_signed_r11_eac);
# endif
# ifdef GL_COMPRESSED_SIGNED_RED_RGTC1
	BOOST_CHECK(x != ev.compressed_signed_red_rgtc1);
# endif
# ifdef GL_COMPRESSED_SIGNED_RG11_EAC
	BOOST_CHECK(x != ev.compressed_signed_rg11_eac);
# endif
# ifdef GL_COMPRESSED_SIGNED_RG_RGTC2
	BOOST_CHECK(x != ev.compressed_signed_rg_rgtc2);
# endif
# ifdef GL_COMPRESSED_SRGB
	BOOST_CHECK(x != ev.compressed_srgb);
# endif
# ifdef GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC
	BOOST_CHECK(x != ev.compressed_srgb8_alpha8_etc2_eac);
# endif
# ifdef GL_COMPRESSED_SRGB8_ETC2
	BOOST_CHECK(x != ev.compressed_srgb8_etc2);
# endif
# ifdef GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2
	BOOST_CHECK(x != ev.compressed_srgb8_punchthrough_alpha1_etc2);
# endif
# ifdef GL_COMPRESSED_SRGB_ALPHA
	BOOST_CHECK(x != ev.compressed_srgb_alpha);
# endif
# ifdef GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM
	BOOST_CHECK(x != ev.compressed_srgb_alpha_bptc_unorm);
# endif
# ifdef GL_DEPTH24_STENCIL8
	BOOST_CHECK(x != ev.depth24_stencil8);
# endif
# ifdef GL_DEPTH32F_STENCIL8
	BOOST_CHECK(x != ev.depth32f_stencil8);
# endif
# ifdef GL_DEPTH_COMPONENT
	BOOST_CHECK(x != ev.depth_component);
# endif
# ifdef GL_DEPTH_COMPONENT16
	BOOST_CHECK(x != ev.depth_component16);
# endif
# ifdef GL_DEPTH_COMPONENT24
	BOOST_CHECK(x != ev.depth_component24);
# endif
# ifdef GL_DEPTH_COMPONENT32
	BOOST_CHECK(x != ev.depth_component32);
# endif
# ifdef GL_DEPTH_COMPONENT32F
	BOOST_CHECK(x != ev.depth_component32f);
# endif
# ifdef GL_DEPTH_STENCIL
	BOOST_CHECK(x != ev.depth_stencil);
# endif
# ifdef GL_R11F_G11F_B10F
	BOOST_CHECK(x != ev.r11f_g11f_b10f);
# endif
# ifdef GL_R16
	BOOST_CHECK(x != ev.r16);
# endif
# ifdef GL_R16_SNORM
	BOOST_CHECK(x != ev.r16_snorm);
# endif
# ifdef GL_R16F
	BOOST_CHECK(x != ev.r16f);
# endif
# ifdef GL_R16I
	BOOST_CHECK(x != ev.r16i);
# endif
# ifdef GL_R16UI
	BOOST_CHECK(x != ev.r16ui);
# endif
# ifdef GL_R32F
	BOOST_CHECK(x != ev.r32f);
# endif
# ifdef GL_R32I
	BOOST_CHECK(x != ev.r32i);
# endif
# ifdef GL_R32UI
	BOOST_CHECK(x != ev.r32ui);
# endif
# ifdef GL_R3_G3_B2
	BOOST_CHECK(x != ev.r3_g3_b2);
# endif
# ifdef GL_R8
	BOOST_CHECK(x != ev.r8);
# endif
# ifdef GL_R8_SNORM
	BOOST_CHECK(x != ev.r8_snorm);
# endif
# ifdef GL_R8I
	BOOST_CHECK(x != ev.r8i);
# endif
# ifdef GL_R8UI
	BOOST_CHECK(x != ev.r8ui);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG16
	BOOST_CHECK(x != ev.rg16);
# endif
# ifdef GL_RG16_SNORM
	BOOST_CHECK(x != ev.rg16_snorm);
# endif
# ifdef GL_RG16F
	BOOST_CHECK(x != ev.rg16f);
# endif
# ifdef GL_RG16I
	BOOST_CHECK(x != ev.rg16i);
# endif
# ifdef GL_RG16UI
	BOOST_CHECK(x != ev.rg16ui);
# endif
# ifdef GL_RG32F
	BOOST_CHECK(x != ev.rg32f);
# endif
# ifdef GL_RG32I
	BOOST_CHECK(x != ev.rg32i);
# endif
# ifdef GL_RG32UI
	BOOST_CHECK(x != ev.rg32ui);
# endif
# ifdef GL_RG8
	BOOST_CHECK(x != ev.rg8);
# endif
# ifdef GL_RG8_SNORM
	BOOST_CHECK(x != ev.rg8_snorm);
# endif
# ifdef GL_RG8I
	BOOST_CHECK(x != ev.rg8i);
# endif
# ifdef GL_RG8UI
	BOOST_CHECK(x != ev.rg8ui);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB10
	BOOST_CHECK(x != ev.rgb10);
# endif
# ifdef GL_RGB10_A2
	BOOST_CHECK(x != ev.rgb10_a2);
# endif
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_COMPRESSED_RED
	x = ev.compressed_red;
	BOOST_CHECK(x == ev.compressed_red);
# ifdef GL_COMPRESSED_RED_RGTC1
	BOOST_CHECK(x != ev.compressed_red_rgtc1);
# endif
# ifdef GL_COMPRESSED_RG
	BOOST_CHECK(x != ev.compressed_rg);
# endif
# ifdef GL_COMPRESSED_RG11_EAC
	BOOST_CHECK(x != ev.compressed_rg11_eac);
# endif
# ifdef GL_COMPRESSED_RG_RGTC2
	BOOST_CHECK(x != ev.compressed_rg_rgtc2);
# endif
# ifdef GL_COMPRESSED_RGB
	BOOST_CHECK(x != ev.compressed_rgb);
# endif
# ifdef GL_COMPRESSED_RGB8_ETC2
	BOOST_CHECK(x != ev.compressed_rgb8_etc2);
# endif
# ifdef GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2
	BOOST_CHECK(x != ev.compressed_rgb8_punchthrough_alpha1_etc2);
# endif
# ifdef GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT
	BOOST_CHECK(x != ev.compressed_rgb_bptc_signed_float);
# endif
# ifdef GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT
	BOOST_CHECK(x != ev.compressed_rgb_bptc_unsigned_float);
# endif
# ifdef GL_COMPRESSED_RGBA
	BOOST_CHECK(x != ev.compressed_rgba);
# endif
# ifdef GL_COMPRESSED_RGBA8_ETC2_EAC
	BOOST_CHECK(x != ev.compressed_rgba8_etc2_eac);
# endif
# ifdef GL_COMPRESSED_RGBA_BPTC_UNORM
	BOOST_CHECK(x != ev.compressed_rgba_bptc_unorm);
# endif
# ifdef GL_COMPRESSED_SIGNED_R11_EAC
	BOOST_CHECK(x != ev.compressed_signed_r11_eac);
# endif
# ifdef GL_COMPRESSED_SIGNED_RED_RGTC1
	BOOST_CHECK(x != ev.compressed_signed_red_rgtc1);
# endif
# ifdef GL_COMPRESSED_SIGNED_RG11_EAC
	BOOST_CHECK(x != ev.compressed_signed_rg11_eac);
# endif
# ifdef GL_COMPRESSED_SIGNED_RG_RGTC2
	BOOST_CHECK(x != ev.compressed_signed_rg_rgtc2);
# endif
# ifdef GL_COMPRESSED_SRGB
	BOOST_CHECK(x != ev.compressed_srgb);
# endif
# ifdef GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC
	BOOST_CHECK(x != ev.compressed_srgb8_alpha8_etc2_eac);
# endif
# ifdef GL_COMPRESSED_SRGB8_ETC2
	BOOST_CHECK(x != ev.compressed_srgb8_etc2);
# endif
# ifdef GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2
	BOOST_CHECK(x != ev.compressed_srgb8_punchthrough_alpha1_etc2);
# endif
# ifdef GL_COMPRESSED_SRGB_ALPHA
	BOOST_CHECK(x != ev.compressed_srgb_alpha);
# endif
# ifdef GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM
	BOOST_CHECK(x != ev.compressed_srgb_alpha_bptc_unorm);
# endif
# ifdef GL_DEPTH24_STENCIL8
	BOOST_CHECK(x != ev.depth24_stencil8);
# endif
# ifdef GL_DEPTH32F_STENCIL8
	BOOST_CHECK(x != ev.depth32f_stencil8);
# endif
# ifdef GL_DEPTH_COMPONENT
	BOOST_CHECK(x != ev.depth_component);
# endif
# ifdef GL_DEPTH_COMPONENT16
	BOOST_CHECK(x != ev.depth_component16);
# endif
# ifdef GL_DEPTH_COMPONENT24
	BOOST_CHECK(x != ev.depth_component24);
# endif
# ifdef GL_DEPTH_COMPONENT32
	BOOST_CHECK(x != ev.depth_component32);
# endif
# ifdef GL_DEPTH_COMPONENT32F
	BOOST_CHECK(x != ev.depth_component32f);
# endif
# ifdef GL_DEPTH_STENCIL
	BOOST_CHECK(x != ev.depth_stencil);
# endif
# ifdef GL_R11F_G11F_B10F
	BOOST_CHECK(x != ev.r11f_g11f_b10f);
# endif
# ifdef GL_R16
	BOOST_CHECK(x != ev.r16);
# endif
# ifdef GL_R16_SNORM
	BOOST_CHECK(x != ev.r16_snorm);
# endif
# ifdef GL_R16F
	BOOST_CHECK(x != ev.r16f);
# endif
# ifdef GL_R16I
	BOOST_CHECK(x != ev.r16i);
# endif
# ifdef GL_R16UI
	BOOST_CHECK(x != ev.r16ui);
# endif
# ifdef GL_R32F
	BOOST_CHECK(x != ev.r32f);
# endif
# ifdef GL_R32I
	BOOST_CHECK(x != ev.r32i);
# endif
# ifdef GL_R32UI
	BOOST_CHECK(x != ev.r32ui);
# endif
# ifdef GL_R3_G3_B2
	BOOST_CHECK(x != ev.r3_g3_b2);
# endif
# ifdef GL_R8
	BOOST_CHECK(x != ev.r8);
# endif
# ifdef GL_R8_SNORM
	BOOST_CHECK(x != ev.r8_snorm);
# endif
# ifdef GL_R8I
	BOOST_CHECK(x != ev.r8i);
# endif
# ifdef GL_R8UI
	BOOST_CHECK(x != ev.r8ui);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG16
	BOOST_CHECK(x != ev.rg16);
# endif
# ifdef GL_RG16_SNORM
	BOOST_CHECK(x != ev.rg16_snorm);
# endif
# ifdef GL_RG16F
	BOOST_CHECK(x != ev.rg16f);
# endif
# ifdef GL_RG16I
	BOOST_CHECK(x != ev.rg16i);
# endif
# ifdef GL_RG16UI
	BOOST_CHECK(x != ev.rg16ui);
# endif
# ifdef GL_RG32F
	BOOST_CHECK(x != ev.rg32f);
# endif
# ifdef GL_RG32I
	BOOST_CHECK(x != ev.rg32i);
# endif
# ifdef GL_RG32UI
	BOOST_CHECK(x != ev.rg32ui);
# endif
# ifdef GL_RG8
	BOOST_CHECK(x != ev.rg8);
# endif
# ifdef GL_RG8_SNORM
	BOOST_CHECK(x != ev.rg8_snorm);
# endif
# ifdef GL_RG8I
	BOOST_CHECK(x != ev.rg8i);
# endif
# ifdef GL_RG8UI
	BOOST_CHECK(x != ev.rg8ui);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB10
	BOOST_CHECK(x != ev.rgb10);
# endif
# ifdef GL_RGB10_A2
	BOOST_CHECK(x != ev.rgb10_a2);
# endif
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_COMPRESSED_RED_RGTC1
	x = ev.compressed_red_rgtc1;
	BOOST_CHECK(x == ev.compressed_red_rgtc1);
# ifdef GL_COMPRESSED_RG
	BOOST_CHECK(x != ev.compressed_rg);
# endif
# ifdef GL_COMPRESSED_RG11_EAC
	BOOST_CHECK(x != ev.compressed_rg11_eac);
# endif
# ifdef GL_COMPRESSED_RG_RGTC2
	BOOST_CHECK(x != ev.compressed_rg_rgtc2);
# endif
# ifdef GL_COMPRESSED_RGB
	BOOST_CHECK(x != ev.compressed_rgb);
# endif
# ifdef GL_COMPRESSED_RGB8_ETC2
	BOOST_CHECK(x != ev.compressed_rgb8_etc2);
# endif
# ifdef GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2
	BOOST_CHECK(x != ev.compressed_rgb8_punchthrough_alpha1_etc2);
# endif
# ifdef GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT
	BOOST_CHECK(x != ev.compressed_rgb_bptc_signed_float);
# endif
# ifdef GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT
	BOOST_CHECK(x != ev.compressed_rgb_bptc_unsigned_float);
# endif
# ifdef GL_COMPRESSED_RGBA
	BOOST_CHECK(x != ev.compressed_rgba);
# endif
# ifdef GL_COMPRESSED_RGBA8_ETC2_EAC
	BOOST_CHECK(x != ev.compressed_rgba8_etc2_eac);
# endif
# ifdef GL_COMPRESSED_RGBA_BPTC_UNORM
	BOOST_CHECK(x != ev.compressed_rgba_bptc_unorm);
# endif
# ifdef GL_COMPRESSED_SIGNED_R11_EAC
	BOOST_CHECK(x != ev.compressed_signed_r11_eac);
# endif
# ifdef GL_COMPRESSED_SIGNED_RED_RGTC1
	BOOST_CHECK(x != ev.compressed_signed_red_rgtc1);
# endif
# ifdef GL_COMPRESSED_SIGNED_RG11_EAC
	BOOST_CHECK(x != ev.compressed_signed_rg11_eac);
# endif
# ifdef GL_COMPRESSED_SIGNED_RG_RGTC2
	BOOST_CHECK(x != ev.compressed_signed_rg_rgtc2);
# endif
# ifdef GL_COMPRESSED_SRGB
	BOOST_CHECK(x != ev.compressed_srgb);
# endif
# ifdef GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC
	BOOST_CHECK(x != ev.compressed_srgb8_alpha8_etc2_eac);
# endif
# ifdef GL_COMPRESSED_SRGB8_ETC2
	BOOST_CHECK(x != ev.compressed_srgb8_etc2);
# endif
# ifdef GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2
	BOOST_CHECK(x != ev.compressed_srgb8_punchthrough_alpha1_etc2);
# endif
# ifdef GL_COMPRESSED_SRGB_ALPHA
	BOOST_CHECK(x != ev.compressed_srgb_alpha);
# endif
# ifdef GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM
	BOOST_CHECK(x != ev.compressed_srgb_alpha_bptc_unorm);
# endif
# ifdef GL_DEPTH24_STENCIL8
	BOOST_CHECK(x != ev.depth24_stencil8);
# endif
# ifdef GL_DEPTH32F_STENCIL8
	BOOST_CHECK(x != ev.depth32f_stencil8);
# endif
# ifdef GL_DEPTH_COMPONENT
	BOOST_CHECK(x != ev.depth_component);
# endif
# ifdef GL_DEPTH_COMPONENT16
	BOOST_CHECK(x != ev.depth_component16);
# endif
# ifdef GL_DEPTH_COMPONENT24
	BOOST_CHECK(x != ev.depth_component24);
# endif
# ifdef GL_DEPTH_COMPONENT32
	BOOST_CHECK(x != ev.depth_component32);
# endif
# ifdef GL_DEPTH_COMPONENT32F
	BOOST_CHECK(x != ev.depth_component32f);
# endif
# ifdef GL_DEPTH_STENCIL
	BOOST_CHECK(x != ev.depth_stencil);
# endif
# ifdef GL_R11F_G11F_B10F
	BOOST_CHECK(x != ev.r11f_g11f_b10f);
# endif
# ifdef GL_R16
	BOOST_CHECK(x != ev.r16);
# endif
# ifdef GL_R16_SNORM
	BOOST_CHECK(x != ev.r16_snorm);
# endif
# ifdef GL_R16F
	BOOST_CHECK(x != ev.r16f);
# endif
# ifdef GL_R16I
	BOOST_CHECK(x != ev.r16i);
# endif
# ifdef GL_R16UI
	BOOST_CHECK(x != ev.r16ui);
# endif
# ifdef GL_R32F
	BOOST_CHECK(x != ev.r32f);
# endif
# ifdef GL_R32I
	BOOST_CHECK(x != ev.r32i);
# endif
# ifdef GL_R32UI
	BOOST_CHECK(x != ev.r32ui);
# endif
# ifdef GL_R3_G3_B2
	BOOST_CHECK(x != ev.r3_g3_b2);
# endif
# ifdef GL_R8
	BOOST_CHECK(x != ev.r8);
# endif
# ifdef GL_R8_SNORM
	BOOST_CHECK(x != ev.r8_snorm);
# endif
# ifdef GL_R8I
	BOOST_CHECK(x != ev.r8i);
# endif
# ifdef GL_R8UI
	BOOST_CHECK(x != ev.r8ui);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG16
	BOOST_CHECK(x != ev.rg16);
# endif
# ifdef GL_RG16_SNORM
	BOOST_CHECK(x != ev.rg16_snorm);
# endif
# ifdef GL_RG16F
	BOOST_CHECK(x != ev.rg16f);
# endif
# ifdef GL_RG16I
	BOOST_CHECK(x != ev.rg16i);
# endif
# ifdef GL_RG16UI
	BOOST_CHECK(x != ev.rg16ui);
# endif
# ifdef GL_RG32F
	BOOST_CHECK(x != ev.rg32f);
# endif
# ifdef GL_RG32I
	BOOST_CHECK(x != ev.rg32i);
# endif
# ifdef GL_RG32UI
	BOOST_CHECK(x != ev.rg32ui);
# endif
# ifdef GL_RG8
	BOOST_CHECK(x != ev.rg8);
# endif
# ifdef GL_RG8_SNORM
	BOOST_CHECK(x != ev.rg8_snorm);
# endif
# ifdef GL_RG8I
	BOOST_CHECK(x != ev.rg8i);
# endif
# ifdef GL_RG8UI
	BOOST_CHECK(x != ev.rg8ui);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB10
	BOOST_CHECK(x != ev.rgb10);
# endif
# ifdef GL_RGB10_A2
	BOOST_CHECK(x != ev.rgb10_a2);
# endif
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_COMPRESSED_RG
	x = ev.compressed_rg;
	BOOST_CHECK(x == ev.compressed_rg);
# ifdef GL_COMPRESSED_RG11_EAC
	BOOST_CHECK(x != ev.compressed_rg11_eac);
# endif
# ifdef GL_COMPRESSED_RG_RGTC2
	BOOST_CHECK(x != ev.compressed_rg_rgtc2);
# endif
# ifdef GL_COMPRESSED_RGB
	BOOST_CHECK(x != ev.compressed_rgb);
# endif
# ifdef GL_COMPRESSED_RGB8_ETC2
	BOOST_CHECK(x != ev.compressed_rgb8_etc2);
# endif
# ifdef GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2
	BOOST_CHECK(x != ev.compressed_rgb8_punchthrough_alpha1_etc2);
# endif
# ifdef GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT
	BOOST_CHECK(x != ev.compressed_rgb_bptc_signed_float);
# endif
# ifdef GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT
	BOOST_CHECK(x != ev.compressed_rgb_bptc_unsigned_float);
# endif
# ifdef GL_COMPRESSED_RGBA
	BOOST_CHECK(x != ev.compressed_rgba);
# endif
# ifdef GL_COMPRESSED_RGBA8_ETC2_EAC
	BOOST_CHECK(x != ev.compressed_rgba8_etc2_eac);
# endif
# ifdef GL_COMPRESSED_RGBA_BPTC_UNORM
	BOOST_CHECK(x != ev.compressed_rgba_bptc_unorm);
# endif
# ifdef GL_COMPRESSED_SIGNED_R11_EAC
	BOOST_CHECK(x != ev.compressed_signed_r11_eac);
# endif
# ifdef GL_COMPRESSED_SIGNED_RED_RGTC1
	BOOST_CHECK(x != ev.compressed_signed_red_rgtc1);
# endif
# ifdef GL_COMPRESSED_SIGNED_RG11_EAC
	BOOST_CHECK(x != ev.compressed_signed_rg11_eac);
# endif
# ifdef GL_COMPRESSED_SIGNED_RG_RGTC2
	BOOST_CHECK(x != ev.compressed_signed_rg_rgtc2);
# endif
# ifdef GL_COMPRESSED_SRGB
	BOOST_CHECK(x != ev.compressed_srgb);
# endif
# ifdef GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC
	BOOST_CHECK(x != ev.compressed_srgb8_alpha8_etc2_eac);
# endif
# ifdef GL_COMPRESSED_SRGB8_ETC2
	BOOST_CHECK(x != ev.compressed_srgb8_etc2);
# endif
# ifdef GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2
	BOOST_CHECK(x != ev.compressed_srgb8_punchthrough_alpha1_etc2);
# endif
# ifdef GL_COMPRESSED_SRGB_ALPHA
	BOOST_CHECK(x != ev.compressed_srgb_alpha);
# endif
# ifdef GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM
	BOOST_CHECK(x != ev.compressed_srgb_alpha_bptc_unorm);
# endif
# ifdef GL_DEPTH24_STENCIL8
	BOOST_CHECK(x != ev.depth24_stencil8);
# endif
# ifdef GL_DEPTH32F_STENCIL8
	BOOST_CHECK(x != ev.depth32f_stencil8);
# endif
# ifdef GL_DEPTH_COMPONENT
	BOOST_CHECK(x != ev.depth_component);
# endif
# ifdef GL_DEPTH_COMPONENT16
	BOOST_CHECK(x != ev.depth_component16);
# endif
# ifdef GL_DEPTH_COMPONENT24
	BOOST_CHECK(x != ev.depth_component24);
# endif
# ifdef GL_DEPTH_COMPONENT32
	BOOST_CHECK(x != ev.depth_component32);
# endif
# ifdef GL_DEPTH_COMPONENT32F
	BOOST_CHECK(x != ev.depth_component32f);
# endif
# ifdef GL_DEPTH_STENCIL
	BOOST_CHECK(x != ev.depth_stencil);
# endif
# ifdef GL_R11F_G11F_B10F
	BOOST_CHECK(x != ev.r11f_g11f_b10f);
# endif
# ifdef GL_R16
	BOOST_CHECK(x != ev.r16);
# endif
# ifdef GL_R16_SNORM
	BOOST_CHECK(x != ev.r16_snorm);
# endif
# ifdef GL_R16F
	BOOST_CHECK(x != ev.r16f);
# endif
# ifdef GL_R16I
	BOOST_CHECK(x != ev.r16i);
# endif
# ifdef GL_R16UI
	BOOST_CHECK(x != ev.r16ui);
# endif
# ifdef GL_R32F
	BOOST_CHECK(x != ev.r32f);
# endif
# ifdef GL_R32I
	BOOST_CHECK(x != ev.r32i);
# endif
# ifdef GL_R32UI
	BOOST_CHECK(x != ev.r32ui);
# endif
# ifdef GL_R3_G3_B2
	BOOST_CHECK(x != ev.r3_g3_b2);
# endif
# ifdef GL_R8
	BOOST_CHECK(x != ev.r8);
# endif
# ifdef GL_R8_SNORM
	BOOST_CHECK(x != ev.r8_snorm);
# endif
# ifdef GL_R8I
	BOOST_CHECK(x != ev.r8i);
# endif
# ifdef GL_R8UI
	BOOST_CHECK(x != ev.r8ui);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG16
	BOOST_CHECK(x != ev.rg16);
# endif
# ifdef GL_RG16_SNORM
	BOOST_CHECK(x != ev.rg16_snorm);
# endif
# ifdef GL_RG16F
	BOOST_CHECK(x != ev.rg16f);
# endif
# ifdef GL_RG16I
	BOOST_CHECK(x != ev.rg16i);
# endif
# ifdef GL_RG16UI
	BOOST_CHECK(x != ev.rg16ui);
# endif
# ifdef GL_RG32F
	BOOST_CHECK(x != ev.rg32f);
# endif
# ifdef GL_RG32I
	BOOST_CHECK(x != ev.rg32i);
# endif
# ifdef GL_RG32UI
	BOOST_CHECK(x != ev.rg32ui);
# endif
# ifdef GL_RG8
	BOOST_CHECK(x != ev.rg8);
# endif
# ifdef GL_RG8_SNORM
	BOOST_CHECK(x != ev.rg8_snorm);
# endif
# ifdef GL_RG8I
	BOOST_CHECK(x != ev.rg8i);
# endif
# ifdef GL_RG8UI
	BOOST_CHECK(x != ev.rg8ui);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB10
	BOOST_CHECK(x != ev.rgb10);
# endif
# ifdef GL_RGB10_A2
	BOOST_CHECK(x != ev.rgb10_a2);
# endif
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_COMPRESSED_RG11_EAC
	x = ev.compressed_rg11_eac;
	BOOST_CHECK(x == ev.compressed_rg11_eac);
# ifdef GL_COMPRESSED_RG_RGTC2
	BOOST_CHECK(x != ev.compressed_rg_rgtc2);
# endif
# ifdef GL_COMPRESSED_RGB
	BOOST_CHECK(x != ev.compressed_rgb);
# endif
# ifdef GL_COMPRESSED_RGB8_ETC2
	BOOST_CHECK(x != ev.compressed_rgb8_etc2);
# endif
# ifdef GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2
	BOOST_CHECK(x != ev.compressed_rgb8_punchthrough_alpha1_etc2);
# endif
# ifdef GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT
	BOOST_CHECK(x != ev.compressed_rgb_bptc_signed_float);
# endif
# ifdef GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT
	BOOST_CHECK(x != ev.compressed_rgb_bptc_unsigned_float);
# endif
# ifdef GL_COMPRESSED_RGBA
	BOOST_CHECK(x != ev.compressed_rgba);
# endif
# ifdef GL_COMPRESSED_RGBA8_ETC2_EAC
	BOOST_CHECK(x != ev.compressed_rgba8_etc2_eac);
# endif
# ifdef GL_COMPRESSED_RGBA_BPTC_UNORM
	BOOST_CHECK(x != ev.compressed_rgba_bptc_unorm);
# endif
# ifdef GL_COMPRESSED_SIGNED_R11_EAC
	BOOST_CHECK(x != ev.compressed_signed_r11_eac);
# endif
# ifdef GL_COMPRESSED_SIGNED_RED_RGTC1
	BOOST_CHECK(x != ev.compressed_signed_red_rgtc1);
# endif
# ifdef GL_COMPRESSED_SIGNED_RG11_EAC
	BOOST_CHECK(x != ev.compressed_signed_rg11_eac);
# endif
# ifdef GL_COMPRESSED_SIGNED_RG_RGTC2
	BOOST_CHECK(x != ev.compressed_signed_rg_rgtc2);
# endif
# ifdef GL_COMPRESSED_SRGB
	BOOST_CHECK(x != ev.compressed_srgb);
# endif
# ifdef GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC
	BOOST_CHECK(x != ev.compressed_srgb8_alpha8_etc2_eac);
# endif
# ifdef GL_COMPRESSED_SRGB8_ETC2
	BOOST_CHECK(x != ev.compressed_srgb8_etc2);
# endif
# ifdef GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2
	BOOST_CHECK(x != ev.compressed_srgb8_punchthrough_alpha1_etc2);
# endif
# ifdef GL_COMPRESSED_SRGB_ALPHA
	BOOST_CHECK(x != ev.compressed_srgb_alpha);
# endif
# ifdef GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM
	BOOST_CHECK(x != ev.compressed_srgb_alpha_bptc_unorm);
# endif
# ifdef GL_DEPTH24_STENCIL8
	BOOST_CHECK(x != ev.depth24_stencil8);
# endif
# ifdef GL_DEPTH32F_STENCIL8
	BOOST_CHECK(x != ev.depth32f_stencil8);
# endif
# ifdef GL_DEPTH_COMPONENT
	BOOST_CHECK(x != ev.depth_component);
# endif
# ifdef GL_DEPTH_COMPONENT16
	BOOST_CHECK(x != ev.depth_component16);
# endif
# ifdef GL_DEPTH_COMPONENT24
	BOOST_CHECK(x != ev.depth_component24);
# endif
# ifdef GL_DEPTH_COMPONENT32
	BOOST_CHECK(x != ev.depth_component32);
# endif
# ifdef GL_DEPTH_COMPONENT32F
	BOOST_CHECK(x != ev.depth_component32f);
# endif
# ifdef GL_DEPTH_STENCIL
	BOOST_CHECK(x != ev.depth_stencil);
# endif
# ifdef GL_R11F_G11F_B10F
	BOOST_CHECK(x != ev.r11f_g11f_b10f);
# endif
# ifdef GL_R16
	BOOST_CHECK(x != ev.r16);
# endif
# ifdef GL_R16_SNORM
	BOOST_CHECK(x != ev.r16_snorm);
# endif
# ifdef GL_R16F
	BOOST_CHECK(x != ev.r16f);
# endif
# ifdef GL_R16I
	BOOST_CHECK(x != ev.r16i);
# endif
# ifdef GL_R16UI
	BOOST_CHECK(x != ev.r16ui);
# endif
# ifdef GL_R32F
	BOOST_CHECK(x != ev.r32f);
# endif
# ifdef GL_R32I
	BOOST_CHECK(x != ev.r32i);
# endif
# ifdef GL_R32UI
	BOOST_CHECK(x != ev.r32ui);
# endif
# ifdef GL_R3_G3_B2
	BOOST_CHECK(x != ev.r3_g3_b2);
# endif
# ifdef GL_R8
	BOOST_CHECK(x != ev.r8);
# endif
# ifdef GL_R8_SNORM
	BOOST_CHECK(x != ev.r8_snorm);
# endif
# ifdef GL_R8I
	BOOST_CHECK(x != ev.r8i);
# endif
# ifdef GL_R8UI
	BOOST_CHECK(x != ev.r8ui);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG16
	BOOST_CHECK(x != ev.rg16);
# endif
# ifdef GL_RG16_SNORM
	BOOST_CHECK(x != ev.rg16_snorm);
# endif
# ifdef GL_RG16F
	BOOST_CHECK(x != ev.rg16f);
# endif
# ifdef GL_RG16I
	BOOST_CHECK(x != ev.rg16i);
# endif
# ifdef GL_RG16UI
	BOOST_CHECK(x != ev.rg16ui);
# endif
# ifdef GL_RG32F
	BOOST_CHECK(x != ev.rg32f);
# endif
# ifdef GL_RG32I
	BOOST_CHECK(x != ev.rg32i);
# endif
# ifdef GL_RG32UI
	BOOST_CHECK(x != ev.rg32ui);
# endif
# ifdef GL_RG8
	BOOST_CHECK(x != ev.rg8);
# endif
# ifdef GL_RG8_SNORM
	BOOST_CHECK(x != ev.rg8_snorm);
# endif
# ifdef GL_RG8I
	BOOST_CHECK(x != ev.rg8i);
# endif
# ifdef GL_RG8UI
	BOOST_CHECK(x != ev.rg8ui);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB10
	BOOST_CHECK(x != ev.rgb10);
# endif
# ifdef GL_RGB10_A2
	BOOST_CHECK(x != ev.rgb10_a2);
# endif
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_COMPRESSED_RG_RGTC2
	x = ev.compressed_rg_rgtc2;
	BOOST_CHECK(x == ev.compressed_rg_rgtc2);
# ifdef GL_COMPRESSED_RGB
	BOOST_CHECK(x != ev.compressed_rgb);
# endif
# ifdef GL_COMPRESSED_RGB8_ETC2
	BOOST_CHECK(x != ev.compressed_rgb8_etc2);
# endif
# ifdef GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2
	BOOST_CHECK(x != ev.compressed_rgb8_punchthrough_alpha1_etc2);
# endif
# ifdef GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT
	BOOST_CHECK(x != ev.compressed_rgb_bptc_signed_float);
# endif
# ifdef GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT
	BOOST_CHECK(x != ev.compressed_rgb_bptc_unsigned_float);
# endif
# ifdef GL_COMPRESSED_RGBA
	BOOST_CHECK(x != ev.compressed_rgba);
# endif
# ifdef GL_COMPRESSED_RGBA8_ETC2_EAC
	BOOST_CHECK(x != ev.compressed_rgba8_etc2_eac);
# endif
# ifdef GL_COMPRESSED_RGBA_BPTC_UNORM
	BOOST_CHECK(x != ev.compressed_rgba_bptc_unorm);
# endif
# ifdef GL_COMPRESSED_SIGNED_R11_EAC
	BOOST_CHECK(x != ev.compressed_signed_r11_eac);
# endif
# ifdef GL_COMPRESSED_SIGNED_RED_RGTC1
	BOOST_CHECK(x != ev.compressed_signed_red_rgtc1);
# endif
# ifdef GL_COMPRESSED_SIGNED_RG11_EAC
	BOOST_CHECK(x != ev.compressed_signed_rg11_eac);
# endif
# ifdef GL_COMPRESSED_SIGNED_RG_RGTC2
	BOOST_CHECK(x != ev.compressed_signed_rg_rgtc2);
# endif
# ifdef GL_COMPRESSED_SRGB
	BOOST_CHECK(x != ev.compressed_srgb);
# endif
# ifdef GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC
	BOOST_CHECK(x != ev.compressed_srgb8_alpha8_etc2_eac);
# endif
# ifdef GL_COMPRESSED_SRGB8_ETC2
	BOOST_CHECK(x != ev.compressed_srgb8_etc2);
# endif
# ifdef GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2
	BOOST_CHECK(x != ev.compressed_srgb8_punchthrough_alpha1_etc2);
# endif
# ifdef GL_COMPRESSED_SRGB_ALPHA
	BOOST_CHECK(x != ev.compressed_srgb_alpha);
# endif
# ifdef GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM
	BOOST_CHECK(x != ev.compressed_srgb_alpha_bptc_unorm);
# endif
# ifdef GL_DEPTH24_STENCIL8
	BOOST_CHECK(x != ev.depth24_stencil8);
# endif
# ifdef GL_DEPTH32F_STENCIL8
	BOOST_CHECK(x != ev.depth32f_stencil8);
# endif
# ifdef GL_DEPTH_COMPONENT
	BOOST_CHECK(x != ev.depth_component);
# endif
# ifdef GL_DEPTH_COMPONENT16
	BOOST_CHECK(x != ev.depth_component16);
# endif
# ifdef GL_DEPTH_COMPONENT24
	BOOST_CHECK(x != ev.depth_component24);
# endif
# ifdef GL_DEPTH_COMPONENT32
	BOOST_CHECK(x != ev.depth_component32);
# endif
# ifdef GL_DEPTH_COMPONENT32F
	BOOST_CHECK(x != ev.depth_component32f);
# endif
# ifdef GL_DEPTH_STENCIL
	BOOST_CHECK(x != ev.depth_stencil);
# endif
# ifdef GL_R11F_G11F_B10F
	BOOST_CHECK(x != ev.r11f_g11f_b10f);
# endif
# ifdef GL_R16
	BOOST_CHECK(x != ev.r16);
# endif
# ifdef GL_R16_SNORM
	BOOST_CHECK(x != ev.r16_snorm);
# endif
# ifdef GL_R16F
	BOOST_CHECK(x != ev.r16f);
# endif
# ifdef GL_R16I
	BOOST_CHECK(x != ev.r16i);
# endif
# ifdef GL_R16UI
	BOOST_CHECK(x != ev.r16ui);
# endif
# ifdef GL_R32F
	BOOST_CHECK(x != ev.r32f);
# endif
# ifdef GL_R32I
	BOOST_CHECK(x != ev.r32i);
# endif
# ifdef GL_R32UI
	BOOST_CHECK(x != ev.r32ui);
# endif
# ifdef GL_R3_G3_B2
	BOOST_CHECK(x != ev.r3_g3_b2);
# endif
# ifdef GL_R8
	BOOST_CHECK(x != ev.r8);
# endif
# ifdef GL_R8_SNORM
	BOOST_CHECK(x != ev.r8_snorm);
# endif
# ifdef GL_R8I
	BOOST_CHECK(x != ev.r8i);
# endif
# ifdef GL_R8UI
	BOOST_CHECK(x != ev.r8ui);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG16
	BOOST_CHECK(x != ev.rg16);
# endif
# ifdef GL_RG16_SNORM
	BOOST_CHECK(x != ev.rg16_snorm);
# endif
# ifdef GL_RG16F
	BOOST_CHECK(x != ev.rg16f);
# endif
# ifdef GL_RG16I
	BOOST_CHECK(x != ev.rg16i);
# endif
# ifdef GL_RG16UI
	BOOST_CHECK(x != ev.rg16ui);
# endif
# ifdef GL_RG32F
	BOOST_CHECK(x != ev.rg32f);
# endif
# ifdef GL_RG32I
	BOOST_CHECK(x != ev.rg32i);
# endif
# ifdef GL_RG32UI
	BOOST_CHECK(x != ev.rg32ui);
# endif
# ifdef GL_RG8
	BOOST_CHECK(x != ev.rg8);
# endif
# ifdef GL_RG8_SNORM
	BOOST_CHECK(x != ev.rg8_snorm);
# endif
# ifdef GL_RG8I
	BOOST_CHECK(x != ev.rg8i);
# endif
# ifdef GL_RG8UI
	BOOST_CHECK(x != ev.rg8ui);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB10
	BOOST_CHECK(x != ev.rgb10);
# endif
# ifdef GL_RGB10_A2
	BOOST_CHECK(x != ev.rgb10_a2);
# endif
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_COMPRESSED_RGB
	x = ev.compressed_rgb;
	BOOST_CHECK(x == ev.compressed_rgb);
# ifdef GL_COMPRESSED_RGB8_ETC2
	BOOST_CHECK(x != ev.compressed_rgb8_etc2);
# endif
# ifdef GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2
	BOOST_CHECK(x != ev.compressed_rgb8_punchthrough_alpha1_etc2);
# endif
# ifdef GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT
	BOOST_CHECK(x != ev.compressed_rgb_bptc_signed_float);
# endif
# ifdef GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT
	BOOST_CHECK(x != ev.compressed_rgb_bptc_unsigned_float);
# endif
# ifdef GL_COMPRESSED_RGBA
	BOOST_CHECK(x != ev.compressed_rgba);
# endif
# ifdef GL_COMPRESSED_RGBA8_ETC2_EAC
	BOOST_CHECK(x != ev.compressed_rgba8_etc2_eac);
# endif
# ifdef GL_COMPRESSED_RGBA_BPTC_UNORM
	BOOST_CHECK(x != ev.compressed_rgba_bptc_unorm);
# endif
# ifdef GL_COMPRESSED_SIGNED_R11_EAC
	BOOST_CHECK(x != ev.compressed_signed_r11_eac);
# endif
# ifdef GL_COMPRESSED_SIGNED_RED_RGTC1
	BOOST_CHECK(x != ev.compressed_signed_red_rgtc1);
# endif
# ifdef GL_COMPRESSED_SIGNED_RG11_EAC
	BOOST_CHECK(x != ev.compressed_signed_rg11_eac);
# endif
# ifdef GL_COMPRESSED_SIGNED_RG_RGTC2
	BOOST_CHECK(x != ev.compressed_signed_rg_rgtc2);
# endif
# ifdef GL_COMPRESSED_SRGB
	BOOST_CHECK(x != ev.compressed_srgb);
# endif
# ifdef GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC
	BOOST_CHECK(x != ev.compressed_srgb8_alpha8_etc2_eac);
# endif
# ifdef GL_COMPRESSED_SRGB8_ETC2
	BOOST_CHECK(x != ev.compressed_srgb8_etc2);
# endif
# ifdef GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2
	BOOST_CHECK(x != ev.compressed_srgb8_punchthrough_alpha1_etc2);
# endif
# ifdef GL_COMPRESSED_SRGB_ALPHA
	BOOST_CHECK(x != ev.compressed_srgb_alpha);
# endif
# ifdef GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM
	BOOST_CHECK(x != ev.compressed_srgb_alpha_bptc_unorm);
# endif
# ifdef GL_DEPTH24_STENCIL8
	BOOST_CHECK(x != ev.depth24_stencil8);
# endif
# ifdef GL_DEPTH32F_STENCIL8
	BOOST_CHECK(x != ev.depth32f_stencil8);
# endif
# ifdef GL_DEPTH_COMPONENT
	BOOST_CHECK(x != ev.depth_component);
# endif
# ifdef GL_DEPTH_COMPONENT16
	BOOST_CHECK(x != ev.depth_component16);
# endif
# ifdef GL_DEPTH_COMPONENT24
	BOOST_CHECK(x != ev.depth_component24);
# endif
# ifdef GL_DEPTH_COMPONENT32
	BOOST_CHECK(x != ev.depth_component32);
# endif
# ifdef GL_DEPTH_COMPONENT32F
	BOOST_CHECK(x != ev.depth_component32f);
# endif
# ifdef GL_DEPTH_STENCIL
	BOOST_CHECK(x != ev.depth_stencil);
# endif
# ifdef GL_R11F_G11F_B10F
	BOOST_CHECK(x != ev.r11f_g11f_b10f);
# endif
# ifdef GL_R16
	BOOST_CHECK(x != ev.r16);
# endif
# ifdef GL_R16_SNORM
	BOOST_CHECK(x != ev.r16_snorm);
# endif
# ifdef GL_R16F
	BOOST_CHECK(x != ev.r16f);
# endif
# ifdef GL_R16I
	BOOST_CHECK(x != ev.r16i);
# endif
# ifdef GL_R16UI
	BOOST_CHECK(x != ev.r16ui);
# endif
# ifdef GL_R32F
	BOOST_CHECK(x != ev.r32f);
# endif
# ifdef GL_R32I
	BOOST_CHECK(x != ev.r32i);
# endif
# ifdef GL_R32UI
	BOOST_CHECK(x != ev.r32ui);
# endif
# ifdef GL_R3_G3_B2
	BOOST_CHECK(x != ev.r3_g3_b2);
# endif
# ifdef GL_R8
	BOOST_CHECK(x != ev.r8);
# endif
# ifdef GL_R8_SNORM
	BOOST_CHECK(x != ev.r8_snorm);
# endif
# ifdef GL_R8I
	BOOST_CHECK(x != ev.r8i);
# endif
# ifdef GL_R8UI
	BOOST_CHECK(x != ev.r8ui);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG16
	BOOST_CHECK(x != ev.rg16);
# endif
# ifdef GL_RG16_SNORM
	BOOST_CHECK(x != ev.rg16_snorm);
# endif
# ifdef GL_RG16F
	BOOST_CHECK(x != ev.rg16f);
# endif
# ifdef GL_RG16I
	BOOST_CHECK(x != ev.rg16i);
# endif
# ifdef GL_RG16UI
	BOOST_CHECK(x != ev.rg16ui);
# endif
# ifdef GL_RG32F
	BOOST_CHECK(x != ev.rg32f);
# endif
# ifdef GL_RG32I
	BOOST_CHECK(x != ev.rg32i);
# endif
# ifdef GL_RG32UI
	BOOST_CHECK(x != ev.rg32ui);
# endif
# ifdef GL_RG8
	BOOST_CHECK(x != ev.rg8);
# endif
# ifdef GL_RG8_SNORM
	BOOST_CHECK(x != ev.rg8_snorm);
# endif
# ifdef GL_RG8I
	BOOST_CHECK(x != ev.rg8i);
# endif
# ifdef GL_RG8UI
	BOOST_CHECK(x != ev.rg8ui);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB10
	BOOST_CHECK(x != ev.rgb10);
# endif
# ifdef GL_RGB10_A2
	BOOST_CHECK(x != ev.rgb10_a2);
# endif
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_COMPRESSED_RGB8_ETC2
	x = ev.compressed_rgb8_etc2;
	BOOST_CHECK(x == ev.compressed_rgb8_etc2);
# ifdef GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2
	BOOST_CHECK(x != ev.compressed_rgb8_punchthrough_alpha1_etc2);
# endif
# ifdef GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT
	BOOST_CHECK(x != ev.compressed_rgb_bptc_signed_float);
# endif
# ifdef GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT
	BOOST_CHECK(x != ev.compressed_rgb_bptc_unsigned_float);
# endif
# ifdef GL_COMPRESSED_RGBA
	BOOST_CHECK(x != ev.compressed_rgba);
# endif
# ifdef GL_COMPRESSED_RGBA8_ETC2_EAC
	BOOST_CHECK(x != ev.compressed_rgba8_etc2_eac);
# endif
# ifdef GL_COMPRESSED_RGBA_BPTC_UNORM
	BOOST_CHECK(x != ev.compressed_rgba_bptc_unorm);
# endif
# ifdef GL_COMPRESSED_SIGNED_R11_EAC
	BOOST_CHECK(x != ev.compressed_signed_r11_eac);
# endif
# ifdef GL_COMPRESSED_SIGNED_RED_RGTC1
	BOOST_CHECK(x != ev.compressed_signed_red_rgtc1);
# endif
# ifdef GL_COMPRESSED_SIGNED_RG11_EAC
	BOOST_CHECK(x != ev.compressed_signed_rg11_eac);
# endif
# ifdef GL_COMPRESSED_SIGNED_RG_RGTC2
	BOOST_CHECK(x != ev.compressed_signed_rg_rgtc2);
# endif
# ifdef GL_COMPRESSED_SRGB
	BOOST_CHECK(x != ev.compressed_srgb);
# endif
# ifdef GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC
	BOOST_CHECK(x != ev.compressed_srgb8_alpha8_etc2_eac);
# endif
# ifdef GL_COMPRESSED_SRGB8_ETC2
	BOOST_CHECK(x != ev.compressed_srgb8_etc2);
# endif
# ifdef GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2
	BOOST_CHECK(x != ev.compressed_srgb8_punchthrough_alpha1_etc2);
# endif
# ifdef GL_COMPRESSED_SRGB_ALPHA
	BOOST_CHECK(x != ev.compressed_srgb_alpha);
# endif
# ifdef GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM
	BOOST_CHECK(x != ev.compressed_srgb_alpha_bptc_unorm);
# endif
# ifdef GL_DEPTH24_STENCIL8
	BOOST_CHECK(x != ev.depth24_stencil8);
# endif
# ifdef GL_DEPTH32F_STENCIL8
	BOOST_CHECK(x != ev.depth32f_stencil8);
# endif
# ifdef GL_DEPTH_COMPONENT
	BOOST_CHECK(x != ev.depth_component);
# endif
# ifdef GL_DEPTH_COMPONENT16
	BOOST_CHECK(x != ev.depth_component16);
# endif
# ifdef GL_DEPTH_COMPONENT24
	BOOST_CHECK(x != ev.depth_component24);
# endif
# ifdef GL_DEPTH_COMPONENT32
	BOOST_CHECK(x != ev.depth_component32);
# endif
# ifdef GL_DEPTH_COMPONENT32F
	BOOST_CHECK(x != ev.depth_component32f);
# endif
# ifdef GL_DEPTH_STENCIL
	BOOST_CHECK(x != ev.depth_stencil);
# endif
# ifdef GL_R11F_G11F_B10F
	BOOST_CHECK(x != ev.r11f_g11f_b10f);
# endif
# ifdef GL_R16
	BOOST_CHECK(x != ev.r16);
# endif
# ifdef GL_R16_SNORM
	BOOST_CHECK(x != ev.r16_snorm);
# endif
# ifdef GL_R16F
	BOOST_CHECK(x != ev.r16f);
# endif
# ifdef GL_R16I
	BOOST_CHECK(x != ev.r16i);
# endif
# ifdef GL_R16UI
	BOOST_CHECK(x != ev.r16ui);
# endif
# ifdef GL_R32F
	BOOST_CHECK(x != ev.r32f);
# endif
# ifdef GL_R32I
	BOOST_CHECK(x != ev.r32i);
# endif
# ifdef GL_R32UI
	BOOST_CHECK(x != ev.r32ui);
# endif
# ifdef GL_R3_G3_B2
	BOOST_CHECK(x != ev.r3_g3_b2);
# endif
# ifdef GL_R8
	BOOST_CHECK(x != ev.r8);
# endif
# ifdef GL_R8_SNORM
	BOOST_CHECK(x != ev.r8_snorm);
# endif
# ifdef GL_R8I
	BOOST_CHECK(x != ev.r8i);
# endif
# ifdef GL_R8UI
	BOOST_CHECK(x != ev.r8ui);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG16
	BOOST_CHECK(x != ev.rg16);
# endif
# ifdef GL_RG16_SNORM
	BOOST_CHECK(x != ev.rg16_snorm);
# endif
# ifdef GL_RG16F
	BOOST_CHECK(x != ev.rg16f);
# endif
# ifdef GL_RG16I
	BOOST_CHECK(x != ev.rg16i);
# endif
# ifdef GL_RG16UI
	BOOST_CHECK(x != ev.rg16ui);
# endif
# ifdef GL_RG32F
	BOOST_CHECK(x != ev.rg32f);
# endif
# ifdef GL_RG32I
	BOOST_CHECK(x != ev.rg32i);
# endif
# ifdef GL_RG32UI
	BOOST_CHECK(x != ev.rg32ui);
# endif
# ifdef GL_RG8
	BOOST_CHECK(x != ev.rg8);
# endif
# ifdef GL_RG8_SNORM
	BOOST_CHECK(x != ev.rg8_snorm);
# endif
# ifdef GL_RG8I
	BOOST_CHECK(x != ev.rg8i);
# endif
# ifdef GL_RG8UI
	BOOST_CHECK(x != ev.rg8ui);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB10
	BOOST_CHECK(x != ev.rgb10);
# endif
# ifdef GL_RGB10_A2
	BOOST_CHECK(x != ev.rgb10_a2);
# endif
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2
	x = ev.compressed_rgb8_punchthrough_alpha1_etc2;
	BOOST_CHECK(x == ev.compressed_rgb8_punchthrough_alpha1_etc2);
# ifdef GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT
	BOOST_CHECK(x != ev.compressed_rgb_bptc_signed_float);
# endif
# ifdef GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT
	BOOST_CHECK(x != ev.compressed_rgb_bptc_unsigned_float);
# endif
# ifdef GL_COMPRESSED_RGBA
	BOOST_CHECK(x != ev.compressed_rgba);
# endif
# ifdef GL_COMPRESSED_RGBA8_ETC2_EAC
	BOOST_CHECK(x != ev.compressed_rgba8_etc2_eac);
# endif
# ifdef GL_COMPRESSED_RGBA_BPTC_UNORM
	BOOST_CHECK(x != ev.compressed_rgba_bptc_unorm);
# endif
# ifdef GL_COMPRESSED_SIGNED_R11_EAC
	BOOST_CHECK(x != ev.compressed_signed_r11_eac);
# endif
# ifdef GL_COMPRESSED_SIGNED_RED_RGTC1
	BOOST_CHECK(x != ev.compressed_signed_red_rgtc1);
# endif
# ifdef GL_COMPRESSED_SIGNED_RG11_EAC
	BOOST_CHECK(x != ev.compressed_signed_rg11_eac);
# endif
# ifdef GL_COMPRESSED_SIGNED_RG_RGTC2
	BOOST_CHECK(x != ev.compressed_signed_rg_rgtc2);
# endif
# ifdef GL_COMPRESSED_SRGB
	BOOST_CHECK(x != ev.compressed_srgb);
# endif
# ifdef GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC
	BOOST_CHECK(x != ev.compressed_srgb8_alpha8_etc2_eac);
# endif
# ifdef GL_COMPRESSED_SRGB8_ETC2
	BOOST_CHECK(x != ev.compressed_srgb8_etc2);
# endif
# ifdef GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2
	BOOST_CHECK(x != ev.compressed_srgb8_punchthrough_alpha1_etc2);
# endif
# ifdef GL_COMPRESSED_SRGB_ALPHA
	BOOST_CHECK(x != ev.compressed_srgb_alpha);
# endif
# ifdef GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM
	BOOST_CHECK(x != ev.compressed_srgb_alpha_bptc_unorm);
# endif
# ifdef GL_DEPTH24_STENCIL8
	BOOST_CHECK(x != ev.depth24_stencil8);
# endif
# ifdef GL_DEPTH32F_STENCIL8
	BOOST_CHECK(x != ev.depth32f_stencil8);
# endif
# ifdef GL_DEPTH_COMPONENT
	BOOST_CHECK(x != ev.depth_component);
# endif
# ifdef GL_DEPTH_COMPONENT16
	BOOST_CHECK(x != ev.depth_component16);
# endif
# ifdef GL_DEPTH_COMPONENT24
	BOOST_CHECK(x != ev.depth_component24);
# endif
# ifdef GL_DEPTH_COMPONENT32
	BOOST_CHECK(x != ev.depth_component32);
# endif
# ifdef GL_DEPTH_COMPONENT32F
	BOOST_CHECK(x != ev.depth_component32f);
# endif
# ifdef GL_DEPTH_STENCIL
	BOOST_CHECK(x != ev.depth_stencil);
# endif
# ifdef GL_R11F_G11F_B10F
	BOOST_CHECK(x != ev.r11f_g11f_b10f);
# endif
# ifdef GL_R16
	BOOST_CHECK(x != ev.r16);
# endif
# ifdef GL_R16_SNORM
	BOOST_CHECK(x != ev.r16_snorm);
# endif
# ifdef GL_R16F
	BOOST_CHECK(x != ev.r16f);
# endif
# ifdef GL_R16I
	BOOST_CHECK(x != ev.r16i);
# endif
# ifdef GL_R16UI
	BOOST_CHECK(x != ev.r16ui);
# endif
# ifdef GL_R32F
	BOOST_CHECK(x != ev.r32f);
# endif
# ifdef GL_R32I
	BOOST_CHECK(x != ev.r32i);
# endif
# ifdef GL_R32UI
	BOOST_CHECK(x != ev.r32ui);
# endif
# ifdef GL_R3_G3_B2
	BOOST_CHECK(x != ev.r3_g3_b2);
# endif
# ifdef GL_R8
	BOOST_CHECK(x != ev.r8);
# endif
# ifdef GL_R8_SNORM
	BOOST_CHECK(x != ev.r8_snorm);
# endif
# ifdef GL_R8I
	BOOST_CHECK(x != ev.r8i);
# endif
# ifdef GL_R8UI
	BOOST_CHECK(x != ev.r8ui);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG16
	BOOST_CHECK(x != ev.rg16);
# endif
# ifdef GL_RG16_SNORM
	BOOST_CHECK(x != ev.rg16_snorm);
# endif
# ifdef GL_RG16F
	BOOST_CHECK(x != ev.rg16f);
# endif
# ifdef GL_RG16I
	BOOST_CHECK(x != ev.rg16i);
# endif
# ifdef GL_RG16UI
	BOOST_CHECK(x != ev.rg16ui);
# endif
# ifdef GL_RG32F
	BOOST_CHECK(x != ev.rg32f);
# endif
# ifdef GL_RG32I
	BOOST_CHECK(x != ev.rg32i);
# endif
# ifdef GL_RG32UI
	BOOST_CHECK(x != ev.rg32ui);
# endif
# ifdef GL_RG8
	BOOST_CHECK(x != ev.rg8);
# endif
# ifdef GL_RG8_SNORM
	BOOST_CHECK(x != ev.rg8_snorm);
# endif
# ifdef GL_RG8I
	BOOST_CHECK(x != ev.rg8i);
# endif
# ifdef GL_RG8UI
	BOOST_CHECK(x != ev.rg8ui);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB10
	BOOST_CHECK(x != ev.rgb10);
# endif
# ifdef GL_RGB10_A2
	BOOST_CHECK(x != ev.rgb10_a2);
# endif
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT
	x = ev.compressed_rgb_bptc_signed_float;
	BOOST_CHECK(x == ev.compressed_rgb_bptc_signed_float);
# ifdef GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT
	BOOST_CHECK(x != ev.compressed_rgb_bptc_unsigned_float);
# endif
# ifdef GL_COMPRESSED_RGBA
	BOOST_CHECK(x != ev.compressed_rgba);
# endif
# ifdef GL_COMPRESSED_RGBA8_ETC2_EAC
	BOOST_CHECK(x != ev.compressed_rgba8_etc2_eac);
# endif
# ifdef GL_COMPRESSED_RGBA_BPTC_UNORM
	BOOST_CHECK(x != ev.compressed_rgba_bptc_unorm);
# endif
# ifdef GL_COMPRESSED_SIGNED_R11_EAC
	BOOST_CHECK(x != ev.compressed_signed_r11_eac);
# endif
# ifdef GL_COMPRESSED_SIGNED_RED_RGTC1
	BOOST_CHECK(x != ev.compressed_signed_red_rgtc1);
# endif
# ifdef GL_COMPRESSED_SIGNED_RG11_EAC
	BOOST_CHECK(x != ev.compressed_signed_rg11_eac);
# endif
# ifdef GL_COMPRESSED_SIGNED_RG_RGTC2
	BOOST_CHECK(x != ev.compressed_signed_rg_rgtc2);
# endif
# ifdef GL_COMPRESSED_SRGB
	BOOST_CHECK(x != ev.compressed_srgb);
# endif
# ifdef GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC
	BOOST_CHECK(x != ev.compressed_srgb8_alpha8_etc2_eac);
# endif
# ifdef GL_COMPRESSED_SRGB8_ETC2
	BOOST_CHECK(x != ev.compressed_srgb8_etc2);
# endif
# ifdef GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2
	BOOST_CHECK(x != ev.compressed_srgb8_punchthrough_alpha1_etc2);
# endif
# ifdef GL_COMPRESSED_SRGB_ALPHA
	BOOST_CHECK(x != ev.compressed_srgb_alpha);
# endif
# ifdef GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM
	BOOST_CHECK(x != ev.compressed_srgb_alpha_bptc_unorm);
# endif
# ifdef GL_DEPTH24_STENCIL8
	BOOST_CHECK(x != ev.depth24_stencil8);
# endif
# ifdef GL_DEPTH32F_STENCIL8
	BOOST_CHECK(x != ev.depth32f_stencil8);
# endif
# ifdef GL_DEPTH_COMPONENT
	BOOST_CHECK(x != ev.depth_component);
# endif
# ifdef GL_DEPTH_COMPONENT16
	BOOST_CHECK(x != ev.depth_component16);
# endif
# ifdef GL_DEPTH_COMPONENT24
	BOOST_CHECK(x != ev.depth_component24);
# endif
# ifdef GL_DEPTH_COMPONENT32
	BOOST_CHECK(x != ev.depth_component32);
# endif
# ifdef GL_DEPTH_COMPONENT32F
	BOOST_CHECK(x != ev.depth_component32f);
# endif
# ifdef GL_DEPTH_STENCIL
	BOOST_CHECK(x != ev.depth_stencil);
# endif
# ifdef GL_R11F_G11F_B10F
	BOOST_CHECK(x != ev.r11f_g11f_b10f);
# endif
# ifdef GL_R16
	BOOST_CHECK(x != ev.r16);
# endif
# ifdef GL_R16_SNORM
	BOOST_CHECK(x != ev.r16_snorm);
# endif
# ifdef GL_R16F
	BOOST_CHECK(x != ev.r16f);
# endif
# ifdef GL_R16I
	BOOST_CHECK(x != ev.r16i);
# endif
# ifdef GL_R16UI
	BOOST_CHECK(x != ev.r16ui);
# endif
# ifdef GL_R32F
	BOOST_CHECK(x != ev.r32f);
# endif
# ifdef GL_R32I
	BOOST_CHECK(x != ev.r32i);
# endif
# ifdef GL_R32UI
	BOOST_CHECK(x != ev.r32ui);
# endif
# ifdef GL_R3_G3_B2
	BOOST_CHECK(x != ev.r3_g3_b2);
# endif
# ifdef GL_R8
	BOOST_CHECK(x != ev.r8);
# endif
# ifdef GL_R8_SNORM
	BOOST_CHECK(x != ev.r8_snorm);
# endif
# ifdef GL_R8I
	BOOST_CHECK(x != ev.r8i);
# endif
# ifdef GL_R8UI
	BOOST_CHECK(x != ev.r8ui);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG16
	BOOST_CHECK(x != ev.rg16);
# endif
# ifdef GL_RG16_SNORM
	BOOST_CHECK(x != ev.rg16_snorm);
# endif
# ifdef GL_RG16F
	BOOST_CHECK(x != ev.rg16f);
# endif
# ifdef GL_RG16I
	BOOST_CHECK(x != ev.rg16i);
# endif
# ifdef GL_RG16UI
	BOOST_CHECK(x != ev.rg16ui);
# endif
# ifdef GL_RG32F
	BOOST_CHECK(x != ev.rg32f);
# endif
# ifdef GL_RG32I
	BOOST_CHECK(x != ev.rg32i);
# endif
# ifdef GL_RG32UI
	BOOST_CHECK(x != ev.rg32ui);
# endif
# ifdef GL_RG8
	BOOST_CHECK(x != ev.rg8);
# endif
# ifdef GL_RG8_SNORM
	BOOST_CHECK(x != ev.rg8_snorm);
# endif
# ifdef GL_RG8I
	BOOST_CHECK(x != ev.rg8i);
# endif
# ifdef GL_RG8UI
	BOOST_CHECK(x != ev.rg8ui);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB10
	BOOST_CHECK(x != ev.rgb10);
# endif
# ifdef GL_RGB10_A2
	BOOST_CHECK(x != ev.rgb10_a2);
# endif
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT
	x = ev.compressed_rgb_bptc_unsigned_float;
	BOOST_CHECK(x == ev.compressed_rgb_bptc_unsigned_float);
# ifdef GL_COMPRESSED_RGBA
	BOOST_CHECK(x != ev.compressed_rgba);
# endif
# ifdef GL_COMPRESSED_RGBA8_ETC2_EAC
	BOOST_CHECK(x != ev.compressed_rgba8_etc2_eac);
# endif
# ifdef GL_COMPRESSED_RGBA_BPTC_UNORM
	BOOST_CHECK(x != ev.compressed_rgba_bptc_unorm);
# endif
# ifdef GL_COMPRESSED_SIGNED_R11_EAC
	BOOST_CHECK(x != ev.compressed_signed_r11_eac);
# endif
# ifdef GL_COMPRESSED_SIGNED_RED_RGTC1
	BOOST_CHECK(x != ev.compressed_signed_red_rgtc1);
# endif
# ifdef GL_COMPRESSED_SIGNED_RG11_EAC
	BOOST_CHECK(x != ev.compressed_signed_rg11_eac);
# endif
# ifdef GL_COMPRESSED_SIGNED_RG_RGTC2
	BOOST_CHECK(x != ev.compressed_signed_rg_rgtc2);
# endif
# ifdef GL_COMPRESSED_SRGB
	BOOST_CHECK(x != ev.compressed_srgb);
# endif
# ifdef GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC
	BOOST_CHECK(x != ev.compressed_srgb8_alpha8_etc2_eac);
# endif
# ifdef GL_COMPRESSED_SRGB8_ETC2
	BOOST_CHECK(x != ev.compressed_srgb8_etc2);
# endif
# ifdef GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2
	BOOST_CHECK(x != ev.compressed_srgb8_punchthrough_alpha1_etc2);
# endif
# ifdef GL_COMPRESSED_SRGB_ALPHA
	BOOST_CHECK(x != ev.compressed_srgb_alpha);
# endif
# ifdef GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM
	BOOST_CHECK(x != ev.compressed_srgb_alpha_bptc_unorm);
# endif
# ifdef GL_DEPTH24_STENCIL8
	BOOST_CHECK(x != ev.depth24_stencil8);
# endif
# ifdef GL_DEPTH32F_STENCIL8
	BOOST_CHECK(x != ev.depth32f_stencil8);
# endif
# ifdef GL_DEPTH_COMPONENT
	BOOST_CHECK(x != ev.depth_component);
# endif
# ifdef GL_DEPTH_COMPONENT16
	BOOST_CHECK(x != ev.depth_component16);
# endif
# ifdef GL_DEPTH_COMPONENT24
	BOOST_CHECK(x != ev.depth_component24);
# endif
# ifdef GL_DEPTH_COMPONENT32
	BOOST_CHECK(x != ev.depth_component32);
# endif
# ifdef GL_DEPTH_COMPONENT32F
	BOOST_CHECK(x != ev.depth_component32f);
# endif
# ifdef GL_DEPTH_STENCIL
	BOOST_CHECK(x != ev.depth_stencil);
# endif
# ifdef GL_R11F_G11F_B10F
	BOOST_CHECK(x != ev.r11f_g11f_b10f);
# endif
# ifdef GL_R16
	BOOST_CHECK(x != ev.r16);
# endif
# ifdef GL_R16_SNORM
	BOOST_CHECK(x != ev.r16_snorm);
# endif
# ifdef GL_R16F
	BOOST_CHECK(x != ev.r16f);
# endif
# ifdef GL_R16I
	BOOST_CHECK(x != ev.r16i);
# endif
# ifdef GL_R16UI
	BOOST_CHECK(x != ev.r16ui);
# endif
# ifdef GL_R32F
	BOOST_CHECK(x != ev.r32f);
# endif
# ifdef GL_R32I
	BOOST_CHECK(x != ev.r32i);
# endif
# ifdef GL_R32UI
	BOOST_CHECK(x != ev.r32ui);
# endif
# ifdef GL_R3_G3_B2
	BOOST_CHECK(x != ev.r3_g3_b2);
# endif
# ifdef GL_R8
	BOOST_CHECK(x != ev.r8);
# endif
# ifdef GL_R8_SNORM
	BOOST_CHECK(x != ev.r8_snorm);
# endif
# ifdef GL_R8I
	BOOST_CHECK(x != ev.r8i);
# endif
# ifdef GL_R8UI
	BOOST_CHECK(x != ev.r8ui);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG16
	BOOST_CHECK(x != ev.rg16);
# endif
# ifdef GL_RG16_SNORM
	BOOST_CHECK(x != ev.rg16_snorm);
# endif
# ifdef GL_RG16F
	BOOST_CHECK(x != ev.rg16f);
# endif
# ifdef GL_RG16I
	BOOST_CHECK(x != ev.rg16i);
# endif
# ifdef GL_RG16UI
	BOOST_CHECK(x != ev.rg16ui);
# endif
# ifdef GL_RG32F
	BOOST_CHECK(x != ev.rg32f);
# endif
# ifdef GL_RG32I
	BOOST_CHECK(x != ev.rg32i);
# endif
# ifdef GL_RG32UI
	BOOST_CHECK(x != ev.rg32ui);
# endif
# ifdef GL_RG8
	BOOST_CHECK(x != ev.rg8);
# endif
# ifdef GL_RG8_SNORM
	BOOST_CHECK(x != ev.rg8_snorm);
# endif
# ifdef GL_RG8I
	BOOST_CHECK(x != ev.rg8i);
# endif
# ifdef GL_RG8UI
	BOOST_CHECK(x != ev.rg8ui);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB10
	BOOST_CHECK(x != ev.rgb10);
# endif
# ifdef GL_RGB10_A2
	BOOST_CHECK(x != ev.rgb10_a2);
# endif
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_COMPRESSED_RGBA
	x = ev.compressed_rgba;
	BOOST_CHECK(x == ev.compressed_rgba);
# ifdef GL_COMPRESSED_RGBA8_ETC2_EAC
	BOOST_CHECK(x != ev.compressed_rgba8_etc2_eac);
# endif
# ifdef GL_COMPRESSED_RGBA_BPTC_UNORM
	BOOST_CHECK(x != ev.compressed_rgba_bptc_unorm);
# endif
# ifdef GL_COMPRESSED_SIGNED_R11_EAC
	BOOST_CHECK(x != ev.compressed_signed_r11_eac);
# endif
# ifdef GL_COMPRESSED_SIGNED_RED_RGTC1
	BOOST_CHECK(x != ev.compressed_signed_red_rgtc1);
# endif
# ifdef GL_COMPRESSED_SIGNED_RG11_EAC
	BOOST_CHECK(x != ev.compressed_signed_rg11_eac);
# endif
# ifdef GL_COMPRESSED_SIGNED_RG_RGTC2
	BOOST_CHECK(x != ev.compressed_signed_rg_rgtc2);
# endif
# ifdef GL_COMPRESSED_SRGB
	BOOST_CHECK(x != ev.compressed_srgb);
# endif
# ifdef GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC
	BOOST_CHECK(x != ev.compressed_srgb8_alpha8_etc2_eac);
# endif
# ifdef GL_COMPRESSED_SRGB8_ETC2
	BOOST_CHECK(x != ev.compressed_srgb8_etc2);
# endif
# ifdef GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2
	BOOST_CHECK(x != ev.compressed_srgb8_punchthrough_alpha1_etc2);
# endif
# ifdef GL_COMPRESSED_SRGB_ALPHA
	BOOST_CHECK(x != ev.compressed_srgb_alpha);
# endif
# ifdef GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM
	BOOST_CHECK(x != ev.compressed_srgb_alpha_bptc_unorm);
# endif
# ifdef GL_DEPTH24_STENCIL8
	BOOST_CHECK(x != ev.depth24_stencil8);
# endif
# ifdef GL_DEPTH32F_STENCIL8
	BOOST_CHECK(x != ev.depth32f_stencil8);
# endif
# ifdef GL_DEPTH_COMPONENT
	BOOST_CHECK(x != ev.depth_component);
# endif
# ifdef GL_DEPTH_COMPONENT16
	BOOST_CHECK(x != ev.depth_component16);
# endif
# ifdef GL_DEPTH_COMPONENT24
	BOOST_CHECK(x != ev.depth_component24);
# endif
# ifdef GL_DEPTH_COMPONENT32
	BOOST_CHECK(x != ev.depth_component32);
# endif
# ifdef GL_DEPTH_COMPONENT32F
	BOOST_CHECK(x != ev.depth_component32f);
# endif
# ifdef GL_DEPTH_STENCIL
	BOOST_CHECK(x != ev.depth_stencil);
# endif
# ifdef GL_R11F_G11F_B10F
	BOOST_CHECK(x != ev.r11f_g11f_b10f);
# endif
# ifdef GL_R16
	BOOST_CHECK(x != ev.r16);
# endif
# ifdef GL_R16_SNORM
	BOOST_CHECK(x != ev.r16_snorm);
# endif
# ifdef GL_R16F
	BOOST_CHECK(x != ev.r16f);
# endif
# ifdef GL_R16I
	BOOST_CHECK(x != ev.r16i);
# endif
# ifdef GL_R16UI
	BOOST_CHECK(x != ev.r16ui);
# endif
# ifdef GL_R32F
	BOOST_CHECK(x != ev.r32f);
# endif
# ifdef GL_R32I
	BOOST_CHECK(x != ev.r32i);
# endif
# ifdef GL_R32UI
	BOOST_CHECK(x != ev.r32ui);
# endif
# ifdef GL_R3_G3_B2
	BOOST_CHECK(x != ev.r3_g3_b2);
# endif
# ifdef GL_R8
	BOOST_CHECK(x != ev.r8);
# endif
# ifdef GL_R8_SNORM
	BOOST_CHECK(x != ev.r8_snorm);
# endif
# ifdef GL_R8I
	BOOST_CHECK(x != ev.r8i);
# endif
# ifdef GL_R8UI
	BOOST_CHECK(x != ev.r8ui);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG16
	BOOST_CHECK(x != ev.rg16);
# endif
# ifdef GL_RG16_SNORM
	BOOST_CHECK(x != ev.rg16_snorm);
# endif
# ifdef GL_RG16F
	BOOST_CHECK(x != ev.rg16f);
# endif
# ifdef GL_RG16I
	BOOST_CHECK(x != ev.rg16i);
# endif
# ifdef GL_RG16UI
	BOOST_CHECK(x != ev.rg16ui);
# endif
# ifdef GL_RG32F
	BOOST_CHECK(x != ev.rg32f);
# endif
# ifdef GL_RG32I
	BOOST_CHECK(x != ev.rg32i);
# endif
# ifdef GL_RG32UI
	BOOST_CHECK(x != ev.rg32ui);
# endif
# ifdef GL_RG8
	BOOST_CHECK(x != ev.rg8);
# endif
# ifdef GL_RG8_SNORM
	BOOST_CHECK(x != ev.rg8_snorm);
# endif
# ifdef GL_RG8I
	BOOST_CHECK(x != ev.rg8i);
# endif
# ifdef GL_RG8UI
	BOOST_CHECK(x != ev.rg8ui);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB10
	BOOST_CHECK(x != ev.rgb10);
# endif
# ifdef GL_RGB10_A2
	BOOST_CHECK(x != ev.rgb10_a2);
# endif
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_COMPRESSED_RGBA8_ETC2_EAC
	x = ev.compressed_rgba8_etc2_eac;
	BOOST_CHECK(x == ev.compressed_rgba8_etc2_eac);
# ifdef GL_COMPRESSED_RGBA_BPTC_UNORM
	BOOST_CHECK(x != ev.compressed_rgba_bptc_unorm);
# endif
# ifdef GL_COMPRESSED_SIGNED_R11_EAC
	BOOST_CHECK(x != ev.compressed_signed_r11_eac);
# endif
# ifdef GL_COMPRESSED_SIGNED_RED_RGTC1
	BOOST_CHECK(x != ev.compressed_signed_red_rgtc1);
# endif
# ifdef GL_COMPRESSED_SIGNED_RG11_EAC
	BOOST_CHECK(x != ev.compressed_signed_rg11_eac);
# endif
# ifdef GL_COMPRESSED_SIGNED_RG_RGTC2
	BOOST_CHECK(x != ev.compressed_signed_rg_rgtc2);
# endif
# ifdef GL_COMPRESSED_SRGB
	BOOST_CHECK(x != ev.compressed_srgb);
# endif
# ifdef GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC
	BOOST_CHECK(x != ev.compressed_srgb8_alpha8_etc2_eac);
# endif
# ifdef GL_COMPRESSED_SRGB8_ETC2
	BOOST_CHECK(x != ev.compressed_srgb8_etc2);
# endif
# ifdef GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2
	BOOST_CHECK(x != ev.compressed_srgb8_punchthrough_alpha1_etc2);
# endif
# ifdef GL_COMPRESSED_SRGB_ALPHA
	BOOST_CHECK(x != ev.compressed_srgb_alpha);
# endif
# ifdef GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM
	BOOST_CHECK(x != ev.compressed_srgb_alpha_bptc_unorm);
# endif
# ifdef GL_DEPTH24_STENCIL8
	BOOST_CHECK(x != ev.depth24_stencil8);
# endif
# ifdef GL_DEPTH32F_STENCIL8
	BOOST_CHECK(x != ev.depth32f_stencil8);
# endif
# ifdef GL_DEPTH_COMPONENT
	BOOST_CHECK(x != ev.depth_component);
# endif
# ifdef GL_DEPTH_COMPONENT16
	BOOST_CHECK(x != ev.depth_component16);
# endif
# ifdef GL_DEPTH_COMPONENT24
	BOOST_CHECK(x != ev.depth_component24);
# endif
# ifdef GL_DEPTH_COMPONENT32
	BOOST_CHECK(x != ev.depth_component32);
# endif
# ifdef GL_DEPTH_COMPONENT32F
	BOOST_CHECK(x != ev.depth_component32f);
# endif
# ifdef GL_DEPTH_STENCIL
	BOOST_CHECK(x != ev.depth_stencil);
# endif
# ifdef GL_R11F_G11F_B10F
	BOOST_CHECK(x != ev.r11f_g11f_b10f);
# endif
# ifdef GL_R16
	BOOST_CHECK(x != ev.r16);
# endif
# ifdef GL_R16_SNORM
	BOOST_CHECK(x != ev.r16_snorm);
# endif
# ifdef GL_R16F
	BOOST_CHECK(x != ev.r16f);
# endif
# ifdef GL_R16I
	BOOST_CHECK(x != ev.r16i);
# endif
# ifdef GL_R16UI
	BOOST_CHECK(x != ev.r16ui);
# endif
# ifdef GL_R32F
	BOOST_CHECK(x != ev.r32f);
# endif
# ifdef GL_R32I
	BOOST_CHECK(x != ev.r32i);
# endif
# ifdef GL_R32UI
	BOOST_CHECK(x != ev.r32ui);
# endif
# ifdef GL_R3_G3_B2
	BOOST_CHECK(x != ev.r3_g3_b2);
# endif
# ifdef GL_R8
	BOOST_CHECK(x != ev.r8);
# endif
# ifdef GL_R8_SNORM
	BOOST_CHECK(x != ev.r8_snorm);
# endif
# ifdef GL_R8I
	BOOST_CHECK(x != ev.r8i);
# endif
# ifdef GL_R8UI
	BOOST_CHECK(x != ev.r8ui);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG16
	BOOST_CHECK(x != ev.rg16);
# endif
# ifdef GL_RG16_SNORM
	BOOST_CHECK(x != ev.rg16_snorm);
# endif
# ifdef GL_RG16F
	BOOST_CHECK(x != ev.rg16f);
# endif
# ifdef GL_RG16I
	BOOST_CHECK(x != ev.rg16i);
# endif
# ifdef GL_RG16UI
	BOOST_CHECK(x != ev.rg16ui);
# endif
# ifdef GL_RG32F
	BOOST_CHECK(x != ev.rg32f);
# endif
# ifdef GL_RG32I
	BOOST_CHECK(x != ev.rg32i);
# endif
# ifdef GL_RG32UI
	BOOST_CHECK(x != ev.rg32ui);
# endif
# ifdef GL_RG8
	BOOST_CHECK(x != ev.rg8);
# endif
# ifdef GL_RG8_SNORM
	BOOST_CHECK(x != ev.rg8_snorm);
# endif
# ifdef GL_RG8I
	BOOST_CHECK(x != ev.rg8i);
# endif
# ifdef GL_RG8UI
	BOOST_CHECK(x != ev.rg8ui);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB10
	BOOST_CHECK(x != ev.rgb10);
# endif
# ifdef GL_RGB10_A2
	BOOST_CHECK(x != ev.rgb10_a2);
# endif
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_COMPRESSED_RGBA_BPTC_UNORM
	x = ev.compressed_rgba_bptc_unorm;
	BOOST_CHECK(x == ev.compressed_rgba_bptc_unorm);
# ifdef GL_COMPRESSED_SIGNED_R11_EAC
	BOOST_CHECK(x != ev.compressed_signed_r11_eac);
# endif
# ifdef GL_COMPRESSED_SIGNED_RED_RGTC1
	BOOST_CHECK(x != ev.compressed_signed_red_rgtc1);
# endif
# ifdef GL_COMPRESSED_SIGNED_RG11_EAC
	BOOST_CHECK(x != ev.compressed_signed_rg11_eac);
# endif
# ifdef GL_COMPRESSED_SIGNED_RG_RGTC2
	BOOST_CHECK(x != ev.compressed_signed_rg_rgtc2);
# endif
# ifdef GL_COMPRESSED_SRGB
	BOOST_CHECK(x != ev.compressed_srgb);
# endif
# ifdef GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC
	BOOST_CHECK(x != ev.compressed_srgb8_alpha8_etc2_eac);
# endif
# ifdef GL_COMPRESSED_SRGB8_ETC2
	BOOST_CHECK(x != ev.compressed_srgb8_etc2);
# endif
# ifdef GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2
	BOOST_CHECK(x != ev.compressed_srgb8_punchthrough_alpha1_etc2);
# endif
# ifdef GL_COMPRESSED_SRGB_ALPHA
	BOOST_CHECK(x != ev.compressed_srgb_alpha);
# endif
# ifdef GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM
	BOOST_CHECK(x != ev.compressed_srgb_alpha_bptc_unorm);
# endif
# ifdef GL_DEPTH24_STENCIL8
	BOOST_CHECK(x != ev.depth24_stencil8);
# endif
# ifdef GL_DEPTH32F_STENCIL8
	BOOST_CHECK(x != ev.depth32f_stencil8);
# endif
# ifdef GL_DEPTH_COMPONENT
	BOOST_CHECK(x != ev.depth_component);
# endif
# ifdef GL_DEPTH_COMPONENT16
	BOOST_CHECK(x != ev.depth_component16);
# endif
# ifdef GL_DEPTH_COMPONENT24
	BOOST_CHECK(x != ev.depth_component24);
# endif
# ifdef GL_DEPTH_COMPONENT32
	BOOST_CHECK(x != ev.depth_component32);
# endif
# ifdef GL_DEPTH_COMPONENT32F
	BOOST_CHECK(x != ev.depth_component32f);
# endif
# ifdef GL_DEPTH_STENCIL
	BOOST_CHECK(x != ev.depth_stencil);
# endif
# ifdef GL_R11F_G11F_B10F
	BOOST_CHECK(x != ev.r11f_g11f_b10f);
# endif
# ifdef GL_R16
	BOOST_CHECK(x != ev.r16);
# endif
# ifdef GL_R16_SNORM
	BOOST_CHECK(x != ev.r16_snorm);
# endif
# ifdef GL_R16F
	BOOST_CHECK(x != ev.r16f);
# endif
# ifdef GL_R16I
	BOOST_CHECK(x != ev.r16i);
# endif
# ifdef GL_R16UI
	BOOST_CHECK(x != ev.r16ui);
# endif
# ifdef GL_R32F
	BOOST_CHECK(x != ev.r32f);
# endif
# ifdef GL_R32I
	BOOST_CHECK(x != ev.r32i);
# endif
# ifdef GL_R32UI
	BOOST_CHECK(x != ev.r32ui);
# endif
# ifdef GL_R3_G3_B2
	BOOST_CHECK(x != ev.r3_g3_b2);
# endif
# ifdef GL_R8
	BOOST_CHECK(x != ev.r8);
# endif
# ifdef GL_R8_SNORM
	BOOST_CHECK(x != ev.r8_snorm);
# endif
# ifdef GL_R8I
	BOOST_CHECK(x != ev.r8i);
# endif
# ifdef GL_R8UI
	BOOST_CHECK(x != ev.r8ui);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG16
	BOOST_CHECK(x != ev.rg16);
# endif
# ifdef GL_RG16_SNORM
	BOOST_CHECK(x != ev.rg16_snorm);
# endif
# ifdef GL_RG16F
	BOOST_CHECK(x != ev.rg16f);
# endif
# ifdef GL_RG16I
	BOOST_CHECK(x != ev.rg16i);
# endif
# ifdef GL_RG16UI
	BOOST_CHECK(x != ev.rg16ui);
# endif
# ifdef GL_RG32F
	BOOST_CHECK(x != ev.rg32f);
# endif
# ifdef GL_RG32I
	BOOST_CHECK(x != ev.rg32i);
# endif
# ifdef GL_RG32UI
	BOOST_CHECK(x != ev.rg32ui);
# endif
# ifdef GL_RG8
	BOOST_CHECK(x != ev.rg8);
# endif
# ifdef GL_RG8_SNORM
	BOOST_CHECK(x != ev.rg8_snorm);
# endif
# ifdef GL_RG8I
	BOOST_CHECK(x != ev.rg8i);
# endif
# ifdef GL_RG8UI
	BOOST_CHECK(x != ev.rg8ui);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB10
	BOOST_CHECK(x != ev.rgb10);
# endif
# ifdef GL_RGB10_A2
	BOOST_CHECK(x != ev.rgb10_a2);
# endif
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_COMPRESSED_SIGNED_R11_EAC
	x = ev.compressed_signed_r11_eac;
	BOOST_CHECK(x == ev.compressed_signed_r11_eac);
# ifdef GL_COMPRESSED_SIGNED_RED_RGTC1
	BOOST_CHECK(x != ev.compressed_signed_red_rgtc1);
# endif
# ifdef GL_COMPRESSED_SIGNED_RG11_EAC
	BOOST_CHECK(x != ev.compressed_signed_rg11_eac);
# endif
# ifdef GL_COMPRESSED_SIGNED_RG_RGTC2
	BOOST_CHECK(x != ev.compressed_signed_rg_rgtc2);
# endif
# ifdef GL_COMPRESSED_SRGB
	BOOST_CHECK(x != ev.compressed_srgb);
# endif
# ifdef GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC
	BOOST_CHECK(x != ev.compressed_srgb8_alpha8_etc2_eac);
# endif
# ifdef GL_COMPRESSED_SRGB8_ETC2
	BOOST_CHECK(x != ev.compressed_srgb8_etc2);
# endif
# ifdef GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2
	BOOST_CHECK(x != ev.compressed_srgb8_punchthrough_alpha1_etc2);
# endif
# ifdef GL_COMPRESSED_SRGB_ALPHA
	BOOST_CHECK(x != ev.compressed_srgb_alpha);
# endif
# ifdef GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM
	BOOST_CHECK(x != ev.compressed_srgb_alpha_bptc_unorm);
# endif
# ifdef GL_DEPTH24_STENCIL8
	BOOST_CHECK(x != ev.depth24_stencil8);
# endif
# ifdef GL_DEPTH32F_STENCIL8
	BOOST_CHECK(x != ev.depth32f_stencil8);
# endif
# ifdef GL_DEPTH_COMPONENT
	BOOST_CHECK(x != ev.depth_component);
# endif
# ifdef GL_DEPTH_COMPONENT16
	BOOST_CHECK(x != ev.depth_component16);
# endif
# ifdef GL_DEPTH_COMPONENT24
	BOOST_CHECK(x != ev.depth_component24);
# endif
# ifdef GL_DEPTH_COMPONENT32
	BOOST_CHECK(x != ev.depth_component32);
# endif
# ifdef GL_DEPTH_COMPONENT32F
	BOOST_CHECK(x != ev.depth_component32f);
# endif
# ifdef GL_DEPTH_STENCIL
	BOOST_CHECK(x != ev.depth_stencil);
# endif
# ifdef GL_R11F_G11F_B10F
	BOOST_CHECK(x != ev.r11f_g11f_b10f);
# endif
# ifdef GL_R16
	BOOST_CHECK(x != ev.r16);
# endif
# ifdef GL_R16_SNORM
	BOOST_CHECK(x != ev.r16_snorm);
# endif
# ifdef GL_R16F
	BOOST_CHECK(x != ev.r16f);
# endif
# ifdef GL_R16I
	BOOST_CHECK(x != ev.r16i);
# endif
# ifdef GL_R16UI
	BOOST_CHECK(x != ev.r16ui);
# endif
# ifdef GL_R32F
	BOOST_CHECK(x != ev.r32f);
# endif
# ifdef GL_R32I
	BOOST_CHECK(x != ev.r32i);
# endif
# ifdef GL_R32UI
	BOOST_CHECK(x != ev.r32ui);
# endif
# ifdef GL_R3_G3_B2
	BOOST_CHECK(x != ev.r3_g3_b2);
# endif
# ifdef GL_R8
	BOOST_CHECK(x != ev.r8);
# endif
# ifdef GL_R8_SNORM
	BOOST_CHECK(x != ev.r8_snorm);
# endif
# ifdef GL_R8I
	BOOST_CHECK(x != ev.r8i);
# endif
# ifdef GL_R8UI
	BOOST_CHECK(x != ev.r8ui);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG16
	BOOST_CHECK(x != ev.rg16);
# endif
# ifdef GL_RG16_SNORM
	BOOST_CHECK(x != ev.rg16_snorm);
# endif
# ifdef GL_RG16F
	BOOST_CHECK(x != ev.rg16f);
# endif
# ifdef GL_RG16I
	BOOST_CHECK(x != ev.rg16i);
# endif
# ifdef GL_RG16UI
	BOOST_CHECK(x != ev.rg16ui);
# endif
# ifdef GL_RG32F
	BOOST_CHECK(x != ev.rg32f);
# endif
# ifdef GL_RG32I
	BOOST_CHECK(x != ev.rg32i);
# endif
# ifdef GL_RG32UI
	BOOST_CHECK(x != ev.rg32ui);
# endif
# ifdef GL_RG8
	BOOST_CHECK(x != ev.rg8);
# endif
# ifdef GL_RG8_SNORM
	BOOST_CHECK(x != ev.rg8_snorm);
# endif
# ifdef GL_RG8I
	BOOST_CHECK(x != ev.rg8i);
# endif
# ifdef GL_RG8UI
	BOOST_CHECK(x != ev.rg8ui);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB10
	BOOST_CHECK(x != ev.rgb10);
# endif
# ifdef GL_RGB10_A2
	BOOST_CHECK(x != ev.rgb10_a2);
# endif
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_COMPRESSED_SIGNED_RED_RGTC1
	x = ev.compressed_signed_red_rgtc1;
	BOOST_CHECK(x == ev.compressed_signed_red_rgtc1);
# ifdef GL_COMPRESSED_SIGNED_RG11_EAC
	BOOST_CHECK(x != ev.compressed_signed_rg11_eac);
# endif
# ifdef GL_COMPRESSED_SIGNED_RG_RGTC2
	BOOST_CHECK(x != ev.compressed_signed_rg_rgtc2);
# endif
# ifdef GL_COMPRESSED_SRGB
	BOOST_CHECK(x != ev.compressed_srgb);
# endif
# ifdef GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC
	BOOST_CHECK(x != ev.compressed_srgb8_alpha8_etc2_eac);
# endif
# ifdef GL_COMPRESSED_SRGB8_ETC2
	BOOST_CHECK(x != ev.compressed_srgb8_etc2);
# endif
# ifdef GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2
	BOOST_CHECK(x != ev.compressed_srgb8_punchthrough_alpha1_etc2);
# endif
# ifdef GL_COMPRESSED_SRGB_ALPHA
	BOOST_CHECK(x != ev.compressed_srgb_alpha);
# endif
# ifdef GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM
	BOOST_CHECK(x != ev.compressed_srgb_alpha_bptc_unorm);
# endif
# ifdef GL_DEPTH24_STENCIL8
	BOOST_CHECK(x != ev.depth24_stencil8);
# endif
# ifdef GL_DEPTH32F_STENCIL8
	BOOST_CHECK(x != ev.depth32f_stencil8);
# endif
# ifdef GL_DEPTH_COMPONENT
	BOOST_CHECK(x != ev.depth_component);
# endif
# ifdef GL_DEPTH_COMPONENT16
	BOOST_CHECK(x != ev.depth_component16);
# endif
# ifdef GL_DEPTH_COMPONENT24
	BOOST_CHECK(x != ev.depth_component24);
# endif
# ifdef GL_DEPTH_COMPONENT32
	BOOST_CHECK(x != ev.depth_component32);
# endif
# ifdef GL_DEPTH_COMPONENT32F
	BOOST_CHECK(x != ev.depth_component32f);
# endif
# ifdef GL_DEPTH_STENCIL
	BOOST_CHECK(x != ev.depth_stencil);
# endif
# ifdef GL_R11F_G11F_B10F
	BOOST_CHECK(x != ev.r11f_g11f_b10f);
# endif
# ifdef GL_R16
	BOOST_CHECK(x != ev.r16);
# endif
# ifdef GL_R16_SNORM
	BOOST_CHECK(x != ev.r16_snorm);
# endif
# ifdef GL_R16F
	BOOST_CHECK(x != ev.r16f);
# endif
# ifdef GL_R16I
	BOOST_CHECK(x != ev.r16i);
# endif
# ifdef GL_R16UI
	BOOST_CHECK(x != ev.r16ui);
# endif
# ifdef GL_R32F
	BOOST_CHECK(x != ev.r32f);
# endif
# ifdef GL_R32I
	BOOST_CHECK(x != ev.r32i);
# endif
# ifdef GL_R32UI
	BOOST_CHECK(x != ev.r32ui);
# endif
# ifdef GL_R3_G3_B2
	BOOST_CHECK(x != ev.r3_g3_b2);
# endif
# ifdef GL_R8
	BOOST_CHECK(x != ev.r8);
# endif
# ifdef GL_R8_SNORM
	BOOST_CHECK(x != ev.r8_snorm);
# endif
# ifdef GL_R8I
	BOOST_CHECK(x != ev.r8i);
# endif
# ifdef GL_R8UI
	BOOST_CHECK(x != ev.r8ui);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG16
	BOOST_CHECK(x != ev.rg16);
# endif
# ifdef GL_RG16_SNORM
	BOOST_CHECK(x != ev.rg16_snorm);
# endif
# ifdef GL_RG16F
	BOOST_CHECK(x != ev.rg16f);
# endif
# ifdef GL_RG16I
	BOOST_CHECK(x != ev.rg16i);
# endif
# ifdef GL_RG16UI
	BOOST_CHECK(x != ev.rg16ui);
# endif
# ifdef GL_RG32F
	BOOST_CHECK(x != ev.rg32f);
# endif
# ifdef GL_RG32I
	BOOST_CHECK(x != ev.rg32i);
# endif
# ifdef GL_RG32UI
	BOOST_CHECK(x != ev.rg32ui);
# endif
# ifdef GL_RG8
	BOOST_CHECK(x != ev.rg8);
# endif
# ifdef GL_RG8_SNORM
	BOOST_CHECK(x != ev.rg8_snorm);
# endif
# ifdef GL_RG8I
	BOOST_CHECK(x != ev.rg8i);
# endif
# ifdef GL_RG8UI
	BOOST_CHECK(x != ev.rg8ui);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB10
	BOOST_CHECK(x != ev.rgb10);
# endif
# ifdef GL_RGB10_A2
	BOOST_CHECK(x != ev.rgb10_a2);
# endif
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_COMPRESSED_SIGNED_RG11_EAC
	x = ev.compressed_signed_rg11_eac;
	BOOST_CHECK(x == ev.compressed_signed_rg11_eac);
# ifdef GL_COMPRESSED_SIGNED_RG_RGTC2
	BOOST_CHECK(x != ev.compressed_signed_rg_rgtc2);
# endif
# ifdef GL_COMPRESSED_SRGB
	BOOST_CHECK(x != ev.compressed_srgb);
# endif
# ifdef GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC
	BOOST_CHECK(x != ev.compressed_srgb8_alpha8_etc2_eac);
# endif
# ifdef GL_COMPRESSED_SRGB8_ETC2
	BOOST_CHECK(x != ev.compressed_srgb8_etc2);
# endif
# ifdef GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2
	BOOST_CHECK(x != ev.compressed_srgb8_punchthrough_alpha1_etc2);
# endif
# ifdef GL_COMPRESSED_SRGB_ALPHA
	BOOST_CHECK(x != ev.compressed_srgb_alpha);
# endif
# ifdef GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM
	BOOST_CHECK(x != ev.compressed_srgb_alpha_bptc_unorm);
# endif
# ifdef GL_DEPTH24_STENCIL8
	BOOST_CHECK(x != ev.depth24_stencil8);
# endif
# ifdef GL_DEPTH32F_STENCIL8
	BOOST_CHECK(x != ev.depth32f_stencil8);
# endif
# ifdef GL_DEPTH_COMPONENT
	BOOST_CHECK(x != ev.depth_component);
# endif
# ifdef GL_DEPTH_COMPONENT16
	BOOST_CHECK(x != ev.depth_component16);
# endif
# ifdef GL_DEPTH_COMPONENT24
	BOOST_CHECK(x != ev.depth_component24);
# endif
# ifdef GL_DEPTH_COMPONENT32
	BOOST_CHECK(x != ev.depth_component32);
# endif
# ifdef GL_DEPTH_COMPONENT32F
	BOOST_CHECK(x != ev.depth_component32f);
# endif
# ifdef GL_DEPTH_STENCIL
	BOOST_CHECK(x != ev.depth_stencil);
# endif
# ifdef GL_R11F_G11F_B10F
	BOOST_CHECK(x != ev.r11f_g11f_b10f);
# endif
# ifdef GL_R16
	BOOST_CHECK(x != ev.r16);
# endif
# ifdef GL_R16_SNORM
	BOOST_CHECK(x != ev.r16_snorm);
# endif
# ifdef GL_R16F
	BOOST_CHECK(x != ev.r16f);
# endif
# ifdef GL_R16I
	BOOST_CHECK(x != ev.r16i);
# endif
# ifdef GL_R16UI
	BOOST_CHECK(x != ev.r16ui);
# endif
# ifdef GL_R32F
	BOOST_CHECK(x != ev.r32f);
# endif
# ifdef GL_R32I
	BOOST_CHECK(x != ev.r32i);
# endif
# ifdef GL_R32UI
	BOOST_CHECK(x != ev.r32ui);
# endif
# ifdef GL_R3_G3_B2
	BOOST_CHECK(x != ev.r3_g3_b2);
# endif
# ifdef GL_R8
	BOOST_CHECK(x != ev.r8);
# endif
# ifdef GL_R8_SNORM
	BOOST_CHECK(x != ev.r8_snorm);
# endif
# ifdef GL_R8I
	BOOST_CHECK(x != ev.r8i);
# endif
# ifdef GL_R8UI
	BOOST_CHECK(x != ev.r8ui);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG16
	BOOST_CHECK(x != ev.rg16);
# endif
# ifdef GL_RG16_SNORM
	BOOST_CHECK(x != ev.rg16_snorm);
# endif
# ifdef GL_RG16F
	BOOST_CHECK(x != ev.rg16f);
# endif
# ifdef GL_RG16I
	BOOST_CHECK(x != ev.rg16i);
# endif
# ifdef GL_RG16UI
	BOOST_CHECK(x != ev.rg16ui);
# endif
# ifdef GL_RG32F
	BOOST_CHECK(x != ev.rg32f);
# endif
# ifdef GL_RG32I
	BOOST_CHECK(x != ev.rg32i);
# endif
# ifdef GL_RG32UI
	BOOST_CHECK(x != ev.rg32ui);
# endif
# ifdef GL_RG8
	BOOST_CHECK(x != ev.rg8);
# endif
# ifdef GL_RG8_SNORM
	BOOST_CHECK(x != ev.rg8_snorm);
# endif
# ifdef GL_RG8I
	BOOST_CHECK(x != ev.rg8i);
# endif
# ifdef GL_RG8UI
	BOOST_CHECK(x != ev.rg8ui);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB10
	BOOST_CHECK(x != ev.rgb10);
# endif
# ifdef GL_RGB10_A2
	BOOST_CHECK(x != ev.rgb10_a2);
# endif
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_COMPRESSED_SIGNED_RG_RGTC2
	x = ev.compressed_signed_rg_rgtc2;
	BOOST_CHECK(x == ev.compressed_signed_rg_rgtc2);
# ifdef GL_COMPRESSED_SRGB
	BOOST_CHECK(x != ev.compressed_srgb);
# endif
# ifdef GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC
	BOOST_CHECK(x != ev.compressed_srgb8_alpha8_etc2_eac);
# endif
# ifdef GL_COMPRESSED_SRGB8_ETC2
	BOOST_CHECK(x != ev.compressed_srgb8_etc2);
# endif
# ifdef GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2
	BOOST_CHECK(x != ev.compressed_srgb8_punchthrough_alpha1_etc2);
# endif
# ifdef GL_COMPRESSED_SRGB_ALPHA
	BOOST_CHECK(x != ev.compressed_srgb_alpha);
# endif
# ifdef GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM
	BOOST_CHECK(x != ev.compressed_srgb_alpha_bptc_unorm);
# endif
# ifdef GL_DEPTH24_STENCIL8
	BOOST_CHECK(x != ev.depth24_stencil8);
# endif
# ifdef GL_DEPTH32F_STENCIL8
	BOOST_CHECK(x != ev.depth32f_stencil8);
# endif
# ifdef GL_DEPTH_COMPONENT
	BOOST_CHECK(x != ev.depth_component);
# endif
# ifdef GL_DEPTH_COMPONENT16
	BOOST_CHECK(x != ev.depth_component16);
# endif
# ifdef GL_DEPTH_COMPONENT24
	BOOST_CHECK(x != ev.depth_component24);
# endif
# ifdef GL_DEPTH_COMPONENT32
	BOOST_CHECK(x != ev.depth_component32);
# endif
# ifdef GL_DEPTH_COMPONENT32F
	BOOST_CHECK(x != ev.depth_component32f);
# endif
# ifdef GL_DEPTH_STENCIL
	BOOST_CHECK(x != ev.depth_stencil);
# endif
# ifdef GL_R11F_G11F_B10F
	BOOST_CHECK(x != ev.r11f_g11f_b10f);
# endif
# ifdef GL_R16
	BOOST_CHECK(x != ev.r16);
# endif
# ifdef GL_R16_SNORM
	BOOST_CHECK(x != ev.r16_snorm);
# endif
# ifdef GL_R16F
	BOOST_CHECK(x != ev.r16f);
# endif
# ifdef GL_R16I
	BOOST_CHECK(x != ev.r16i);
# endif
# ifdef GL_R16UI
	BOOST_CHECK(x != ev.r16ui);
# endif
# ifdef GL_R32F
	BOOST_CHECK(x != ev.r32f);
# endif
# ifdef GL_R32I
	BOOST_CHECK(x != ev.r32i);
# endif
# ifdef GL_R32UI
	BOOST_CHECK(x != ev.r32ui);
# endif
# ifdef GL_R3_G3_B2
	BOOST_CHECK(x != ev.r3_g3_b2);
# endif
# ifdef GL_R8
	BOOST_CHECK(x != ev.r8);
# endif
# ifdef GL_R8_SNORM
	BOOST_CHECK(x != ev.r8_snorm);
# endif
# ifdef GL_R8I
	BOOST_CHECK(x != ev.r8i);
# endif
# ifdef GL_R8UI
	BOOST_CHECK(x != ev.r8ui);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG16
	BOOST_CHECK(x != ev.rg16);
# endif
# ifdef GL_RG16_SNORM
	BOOST_CHECK(x != ev.rg16_snorm);
# endif
# ifdef GL_RG16F
	BOOST_CHECK(x != ev.rg16f);
# endif
# ifdef GL_RG16I
	BOOST_CHECK(x != ev.rg16i);
# endif
# ifdef GL_RG16UI
	BOOST_CHECK(x != ev.rg16ui);
# endif
# ifdef GL_RG32F
	BOOST_CHECK(x != ev.rg32f);
# endif
# ifdef GL_RG32I
	BOOST_CHECK(x != ev.rg32i);
# endif
# ifdef GL_RG32UI
	BOOST_CHECK(x != ev.rg32ui);
# endif
# ifdef GL_RG8
	BOOST_CHECK(x != ev.rg8);
# endif
# ifdef GL_RG8_SNORM
	BOOST_CHECK(x != ev.rg8_snorm);
# endif
# ifdef GL_RG8I
	BOOST_CHECK(x != ev.rg8i);
# endif
# ifdef GL_RG8UI
	BOOST_CHECK(x != ev.rg8ui);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB10
	BOOST_CHECK(x != ev.rgb10);
# endif
# ifdef GL_RGB10_A2
	BOOST_CHECK(x != ev.rgb10_a2);
# endif
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_COMPRESSED_SRGB
	x = ev.compressed_srgb;
	BOOST_CHECK(x == ev.compressed_srgb);
# ifdef GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC
	BOOST_CHECK(x != ev.compressed_srgb8_alpha8_etc2_eac);
# endif
# ifdef GL_COMPRESSED_SRGB8_ETC2
	BOOST_CHECK(x != ev.compressed_srgb8_etc2);
# endif
# ifdef GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2
	BOOST_CHECK(x != ev.compressed_srgb8_punchthrough_alpha1_etc2);
# endif
# ifdef GL_COMPRESSED_SRGB_ALPHA
	BOOST_CHECK(x != ev.compressed_srgb_alpha);
# endif
# ifdef GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM
	BOOST_CHECK(x != ev.compressed_srgb_alpha_bptc_unorm);
# endif
# ifdef GL_DEPTH24_STENCIL8
	BOOST_CHECK(x != ev.depth24_stencil8);
# endif
# ifdef GL_DEPTH32F_STENCIL8
	BOOST_CHECK(x != ev.depth32f_stencil8);
# endif
# ifdef GL_DEPTH_COMPONENT
	BOOST_CHECK(x != ev.depth_component);
# endif
# ifdef GL_DEPTH_COMPONENT16
	BOOST_CHECK(x != ev.depth_component16);
# endif
# ifdef GL_DEPTH_COMPONENT24
	BOOST_CHECK(x != ev.depth_component24);
# endif
# ifdef GL_DEPTH_COMPONENT32
	BOOST_CHECK(x != ev.depth_component32);
# endif
# ifdef GL_DEPTH_COMPONENT32F
	BOOST_CHECK(x != ev.depth_component32f);
# endif
# ifdef GL_DEPTH_STENCIL
	BOOST_CHECK(x != ev.depth_stencil);
# endif
# ifdef GL_R11F_G11F_B10F
	BOOST_CHECK(x != ev.r11f_g11f_b10f);
# endif
# ifdef GL_R16
	BOOST_CHECK(x != ev.r16);
# endif
# ifdef GL_R16_SNORM
	BOOST_CHECK(x != ev.r16_snorm);
# endif
# ifdef GL_R16F
	BOOST_CHECK(x != ev.r16f);
# endif
# ifdef GL_R16I
	BOOST_CHECK(x != ev.r16i);
# endif
# ifdef GL_R16UI
	BOOST_CHECK(x != ev.r16ui);
# endif
# ifdef GL_R32F
	BOOST_CHECK(x != ev.r32f);
# endif
# ifdef GL_R32I
	BOOST_CHECK(x != ev.r32i);
# endif
# ifdef GL_R32UI
	BOOST_CHECK(x != ev.r32ui);
# endif
# ifdef GL_R3_G3_B2
	BOOST_CHECK(x != ev.r3_g3_b2);
# endif
# ifdef GL_R8
	BOOST_CHECK(x != ev.r8);
# endif
# ifdef GL_R8_SNORM
	BOOST_CHECK(x != ev.r8_snorm);
# endif
# ifdef GL_R8I
	BOOST_CHECK(x != ev.r8i);
# endif
# ifdef GL_R8UI
	BOOST_CHECK(x != ev.r8ui);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG16
	BOOST_CHECK(x != ev.rg16);
# endif
# ifdef GL_RG16_SNORM
	BOOST_CHECK(x != ev.rg16_snorm);
# endif
# ifdef GL_RG16F
	BOOST_CHECK(x != ev.rg16f);
# endif
# ifdef GL_RG16I
	BOOST_CHECK(x != ev.rg16i);
# endif
# ifdef GL_RG16UI
	BOOST_CHECK(x != ev.rg16ui);
# endif
# ifdef GL_RG32F
	BOOST_CHECK(x != ev.rg32f);
# endif
# ifdef GL_RG32I
	BOOST_CHECK(x != ev.rg32i);
# endif
# ifdef GL_RG32UI
	BOOST_CHECK(x != ev.rg32ui);
# endif
# ifdef GL_RG8
	BOOST_CHECK(x != ev.rg8);
# endif
# ifdef GL_RG8_SNORM
	BOOST_CHECK(x != ev.rg8_snorm);
# endif
# ifdef GL_RG8I
	BOOST_CHECK(x != ev.rg8i);
# endif
# ifdef GL_RG8UI
	BOOST_CHECK(x != ev.rg8ui);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB10
	BOOST_CHECK(x != ev.rgb10);
# endif
# ifdef GL_RGB10_A2
	BOOST_CHECK(x != ev.rgb10_a2);
# endif
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC
	x = ev.compressed_srgb8_alpha8_etc2_eac;
	BOOST_CHECK(x == ev.compressed_srgb8_alpha8_etc2_eac);
# ifdef GL_COMPRESSED_SRGB8_ETC2
	BOOST_CHECK(x != ev.compressed_srgb8_etc2);
# endif
# ifdef GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2
	BOOST_CHECK(x != ev.compressed_srgb8_punchthrough_alpha1_etc2);
# endif
# ifdef GL_COMPRESSED_SRGB_ALPHA
	BOOST_CHECK(x != ev.compressed_srgb_alpha);
# endif
# ifdef GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM
	BOOST_CHECK(x != ev.compressed_srgb_alpha_bptc_unorm);
# endif
# ifdef GL_DEPTH24_STENCIL8
	BOOST_CHECK(x != ev.depth24_stencil8);
# endif
# ifdef GL_DEPTH32F_STENCIL8
	BOOST_CHECK(x != ev.depth32f_stencil8);
# endif
# ifdef GL_DEPTH_COMPONENT
	BOOST_CHECK(x != ev.depth_component);
# endif
# ifdef GL_DEPTH_COMPONENT16
	BOOST_CHECK(x != ev.depth_component16);
# endif
# ifdef GL_DEPTH_COMPONENT24
	BOOST_CHECK(x != ev.depth_component24);
# endif
# ifdef GL_DEPTH_COMPONENT32
	BOOST_CHECK(x != ev.depth_component32);
# endif
# ifdef GL_DEPTH_COMPONENT32F
	BOOST_CHECK(x != ev.depth_component32f);
# endif
# ifdef GL_DEPTH_STENCIL
	BOOST_CHECK(x != ev.depth_stencil);
# endif
# ifdef GL_R11F_G11F_B10F
	BOOST_CHECK(x != ev.r11f_g11f_b10f);
# endif
# ifdef GL_R16
	BOOST_CHECK(x != ev.r16);
# endif
# ifdef GL_R16_SNORM
	BOOST_CHECK(x != ev.r16_snorm);
# endif
# ifdef GL_R16F
	BOOST_CHECK(x != ev.r16f);
# endif
# ifdef GL_R16I
	BOOST_CHECK(x != ev.r16i);
# endif
# ifdef GL_R16UI
	BOOST_CHECK(x != ev.r16ui);
# endif
# ifdef GL_R32F
	BOOST_CHECK(x != ev.r32f);
# endif
# ifdef GL_R32I
	BOOST_CHECK(x != ev.r32i);
# endif
# ifdef GL_R32UI
	BOOST_CHECK(x != ev.r32ui);
# endif
# ifdef GL_R3_G3_B2
	BOOST_CHECK(x != ev.r3_g3_b2);
# endif
# ifdef GL_R8
	BOOST_CHECK(x != ev.r8);
# endif
# ifdef GL_R8_SNORM
	BOOST_CHECK(x != ev.r8_snorm);
# endif
# ifdef GL_R8I
	BOOST_CHECK(x != ev.r8i);
# endif
# ifdef GL_R8UI
	BOOST_CHECK(x != ev.r8ui);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG16
	BOOST_CHECK(x != ev.rg16);
# endif
# ifdef GL_RG16_SNORM
	BOOST_CHECK(x != ev.rg16_snorm);
# endif
# ifdef GL_RG16F
	BOOST_CHECK(x != ev.rg16f);
# endif
# ifdef GL_RG16I
	BOOST_CHECK(x != ev.rg16i);
# endif
# ifdef GL_RG16UI
	BOOST_CHECK(x != ev.rg16ui);
# endif
# ifdef GL_RG32F
	BOOST_CHECK(x != ev.rg32f);
# endif
# ifdef GL_RG32I
	BOOST_CHECK(x != ev.rg32i);
# endif
# ifdef GL_RG32UI
	BOOST_CHECK(x != ev.rg32ui);
# endif
# ifdef GL_RG8
	BOOST_CHECK(x != ev.rg8);
# endif
# ifdef GL_RG8_SNORM
	BOOST_CHECK(x != ev.rg8_snorm);
# endif
# ifdef GL_RG8I
	BOOST_CHECK(x != ev.rg8i);
# endif
# ifdef GL_RG8UI
	BOOST_CHECK(x != ev.rg8ui);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB10
	BOOST_CHECK(x != ev.rgb10);
# endif
# ifdef GL_RGB10_A2
	BOOST_CHECK(x != ev.rgb10_a2);
# endif
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_COMPRESSED_SRGB8_ETC2
	x = ev.compressed_srgb8_etc2;
	BOOST_CHECK(x == ev.compressed_srgb8_etc2);
# ifdef GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2
	BOOST_CHECK(x != ev.compressed_srgb8_punchthrough_alpha1_etc2);
# endif
# ifdef GL_COMPRESSED_SRGB_ALPHA
	BOOST_CHECK(x != ev.compressed_srgb_alpha);
# endif
# ifdef GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM
	BOOST_CHECK(x != ev.compressed_srgb_alpha_bptc_unorm);
# endif
# ifdef GL_DEPTH24_STENCIL8
	BOOST_CHECK(x != ev.depth24_stencil8);
# endif
# ifdef GL_DEPTH32F_STENCIL8
	BOOST_CHECK(x != ev.depth32f_stencil8);
# endif
# ifdef GL_DEPTH_COMPONENT
	BOOST_CHECK(x != ev.depth_component);
# endif
# ifdef GL_DEPTH_COMPONENT16
	BOOST_CHECK(x != ev.depth_component16);
# endif
# ifdef GL_DEPTH_COMPONENT24
	BOOST_CHECK(x != ev.depth_component24);
# endif
# ifdef GL_DEPTH_COMPONENT32
	BOOST_CHECK(x != ev.depth_component32);
# endif
# ifdef GL_DEPTH_COMPONENT32F
	BOOST_CHECK(x != ev.depth_component32f);
# endif
# ifdef GL_DEPTH_STENCIL
	BOOST_CHECK(x != ev.depth_stencil);
# endif
# ifdef GL_R11F_G11F_B10F
	BOOST_CHECK(x != ev.r11f_g11f_b10f);
# endif
# ifdef GL_R16
	BOOST_CHECK(x != ev.r16);
# endif
# ifdef GL_R16_SNORM
	BOOST_CHECK(x != ev.r16_snorm);
# endif
# ifdef GL_R16F
	BOOST_CHECK(x != ev.r16f);
# endif
# ifdef GL_R16I
	BOOST_CHECK(x != ev.r16i);
# endif
# ifdef GL_R16UI
	BOOST_CHECK(x != ev.r16ui);
# endif
# ifdef GL_R32F
	BOOST_CHECK(x != ev.r32f);
# endif
# ifdef GL_R32I
	BOOST_CHECK(x != ev.r32i);
# endif
# ifdef GL_R32UI
	BOOST_CHECK(x != ev.r32ui);
# endif
# ifdef GL_R3_G3_B2
	BOOST_CHECK(x != ev.r3_g3_b2);
# endif
# ifdef GL_R8
	BOOST_CHECK(x != ev.r8);
# endif
# ifdef GL_R8_SNORM
	BOOST_CHECK(x != ev.r8_snorm);
# endif
# ifdef GL_R8I
	BOOST_CHECK(x != ev.r8i);
# endif
# ifdef GL_R8UI
	BOOST_CHECK(x != ev.r8ui);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG16
	BOOST_CHECK(x != ev.rg16);
# endif
# ifdef GL_RG16_SNORM
	BOOST_CHECK(x != ev.rg16_snorm);
# endif
# ifdef GL_RG16F
	BOOST_CHECK(x != ev.rg16f);
# endif
# ifdef GL_RG16I
	BOOST_CHECK(x != ev.rg16i);
# endif
# ifdef GL_RG16UI
	BOOST_CHECK(x != ev.rg16ui);
# endif
# ifdef GL_RG32F
	BOOST_CHECK(x != ev.rg32f);
# endif
# ifdef GL_RG32I
	BOOST_CHECK(x != ev.rg32i);
# endif
# ifdef GL_RG32UI
	BOOST_CHECK(x != ev.rg32ui);
# endif
# ifdef GL_RG8
	BOOST_CHECK(x != ev.rg8);
# endif
# ifdef GL_RG8_SNORM
	BOOST_CHECK(x != ev.rg8_snorm);
# endif
# ifdef GL_RG8I
	BOOST_CHECK(x != ev.rg8i);
# endif
# ifdef GL_RG8UI
	BOOST_CHECK(x != ev.rg8ui);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB10
	BOOST_CHECK(x != ev.rgb10);
# endif
# ifdef GL_RGB10_A2
	BOOST_CHECK(x != ev.rgb10_a2);
# endif
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2
	x = ev.compressed_srgb8_punchthrough_alpha1_etc2;
	BOOST_CHECK(x == ev.compressed_srgb8_punchthrough_alpha1_etc2);
# ifdef GL_COMPRESSED_SRGB_ALPHA
	BOOST_CHECK(x != ev.compressed_srgb_alpha);
# endif
# ifdef GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM
	BOOST_CHECK(x != ev.compressed_srgb_alpha_bptc_unorm);
# endif
# ifdef GL_DEPTH24_STENCIL8
	BOOST_CHECK(x != ev.depth24_stencil8);
# endif
# ifdef GL_DEPTH32F_STENCIL8
	BOOST_CHECK(x != ev.depth32f_stencil8);
# endif
# ifdef GL_DEPTH_COMPONENT
	BOOST_CHECK(x != ev.depth_component);
# endif
# ifdef GL_DEPTH_COMPONENT16
	BOOST_CHECK(x != ev.depth_component16);
# endif
# ifdef GL_DEPTH_COMPONENT24
	BOOST_CHECK(x != ev.depth_component24);
# endif
# ifdef GL_DEPTH_COMPONENT32
	BOOST_CHECK(x != ev.depth_component32);
# endif
# ifdef GL_DEPTH_COMPONENT32F
	BOOST_CHECK(x != ev.depth_component32f);
# endif
# ifdef GL_DEPTH_STENCIL
	BOOST_CHECK(x != ev.depth_stencil);
# endif
# ifdef GL_R11F_G11F_B10F
	BOOST_CHECK(x != ev.r11f_g11f_b10f);
# endif
# ifdef GL_R16
	BOOST_CHECK(x != ev.r16);
# endif
# ifdef GL_R16_SNORM
	BOOST_CHECK(x != ev.r16_snorm);
# endif
# ifdef GL_R16F
	BOOST_CHECK(x != ev.r16f);
# endif
# ifdef GL_R16I
	BOOST_CHECK(x != ev.r16i);
# endif
# ifdef GL_R16UI
	BOOST_CHECK(x != ev.r16ui);
# endif
# ifdef GL_R32F
	BOOST_CHECK(x != ev.r32f);
# endif
# ifdef GL_R32I
	BOOST_CHECK(x != ev.r32i);
# endif
# ifdef GL_R32UI
	BOOST_CHECK(x != ev.r32ui);
# endif
# ifdef GL_R3_G3_B2
	BOOST_CHECK(x != ev.r3_g3_b2);
# endif
# ifdef GL_R8
	BOOST_CHECK(x != ev.r8);
# endif
# ifdef GL_R8_SNORM
	BOOST_CHECK(x != ev.r8_snorm);
# endif
# ifdef GL_R8I
	BOOST_CHECK(x != ev.r8i);
# endif
# ifdef GL_R8UI
	BOOST_CHECK(x != ev.r8ui);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG16
	BOOST_CHECK(x != ev.rg16);
# endif
# ifdef GL_RG16_SNORM
	BOOST_CHECK(x != ev.rg16_snorm);
# endif
# ifdef GL_RG16F
	BOOST_CHECK(x != ev.rg16f);
# endif
# ifdef GL_RG16I
	BOOST_CHECK(x != ev.rg16i);
# endif
# ifdef GL_RG16UI
	BOOST_CHECK(x != ev.rg16ui);
# endif
# ifdef GL_RG32F
	BOOST_CHECK(x != ev.rg32f);
# endif
# ifdef GL_RG32I
	BOOST_CHECK(x != ev.rg32i);
# endif
# ifdef GL_RG32UI
	BOOST_CHECK(x != ev.rg32ui);
# endif
# ifdef GL_RG8
	BOOST_CHECK(x != ev.rg8);
# endif
# ifdef GL_RG8_SNORM
	BOOST_CHECK(x != ev.rg8_snorm);
# endif
# ifdef GL_RG8I
	BOOST_CHECK(x != ev.rg8i);
# endif
# ifdef GL_RG8UI
	BOOST_CHECK(x != ev.rg8ui);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB10
	BOOST_CHECK(x != ev.rgb10);
# endif
# ifdef GL_RGB10_A2
	BOOST_CHECK(x != ev.rgb10_a2);
# endif
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_COMPRESSED_SRGB_ALPHA
	x = ev.compressed_srgb_alpha;
	BOOST_CHECK(x == ev.compressed_srgb_alpha);
# ifdef GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM
	BOOST_CHECK(x != ev.compressed_srgb_alpha_bptc_unorm);
# endif
# ifdef GL_DEPTH24_STENCIL8
	BOOST_CHECK(x != ev.depth24_stencil8);
# endif
# ifdef GL_DEPTH32F_STENCIL8
	BOOST_CHECK(x != ev.depth32f_stencil8);
# endif
# ifdef GL_DEPTH_COMPONENT
	BOOST_CHECK(x != ev.depth_component);
# endif
# ifdef GL_DEPTH_COMPONENT16
	BOOST_CHECK(x != ev.depth_component16);
# endif
# ifdef GL_DEPTH_COMPONENT24
	BOOST_CHECK(x != ev.depth_component24);
# endif
# ifdef GL_DEPTH_COMPONENT32
	BOOST_CHECK(x != ev.depth_component32);
# endif
# ifdef GL_DEPTH_COMPONENT32F
	BOOST_CHECK(x != ev.depth_component32f);
# endif
# ifdef GL_DEPTH_STENCIL
	BOOST_CHECK(x != ev.depth_stencil);
# endif
# ifdef GL_R11F_G11F_B10F
	BOOST_CHECK(x != ev.r11f_g11f_b10f);
# endif
# ifdef GL_R16
	BOOST_CHECK(x != ev.r16);
# endif
# ifdef GL_R16_SNORM
	BOOST_CHECK(x != ev.r16_snorm);
# endif
# ifdef GL_R16F
	BOOST_CHECK(x != ev.r16f);
# endif
# ifdef GL_R16I
	BOOST_CHECK(x != ev.r16i);
# endif
# ifdef GL_R16UI
	BOOST_CHECK(x != ev.r16ui);
# endif
# ifdef GL_R32F
	BOOST_CHECK(x != ev.r32f);
# endif
# ifdef GL_R32I
	BOOST_CHECK(x != ev.r32i);
# endif
# ifdef GL_R32UI
	BOOST_CHECK(x != ev.r32ui);
# endif
# ifdef GL_R3_G3_B2
	BOOST_CHECK(x != ev.r3_g3_b2);
# endif
# ifdef GL_R8
	BOOST_CHECK(x != ev.r8);
# endif
# ifdef GL_R8_SNORM
	BOOST_CHECK(x != ev.r8_snorm);
# endif
# ifdef GL_R8I
	BOOST_CHECK(x != ev.r8i);
# endif
# ifdef GL_R8UI
	BOOST_CHECK(x != ev.r8ui);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG16
	BOOST_CHECK(x != ev.rg16);
# endif
# ifdef GL_RG16_SNORM
	BOOST_CHECK(x != ev.rg16_snorm);
# endif
# ifdef GL_RG16F
	BOOST_CHECK(x != ev.rg16f);
# endif
# ifdef GL_RG16I
	BOOST_CHECK(x != ev.rg16i);
# endif
# ifdef GL_RG16UI
	BOOST_CHECK(x != ev.rg16ui);
# endif
# ifdef GL_RG32F
	BOOST_CHECK(x != ev.rg32f);
# endif
# ifdef GL_RG32I
	BOOST_CHECK(x != ev.rg32i);
# endif
# ifdef GL_RG32UI
	BOOST_CHECK(x != ev.rg32ui);
# endif
# ifdef GL_RG8
	BOOST_CHECK(x != ev.rg8);
# endif
# ifdef GL_RG8_SNORM
	BOOST_CHECK(x != ev.rg8_snorm);
# endif
# ifdef GL_RG8I
	BOOST_CHECK(x != ev.rg8i);
# endif
# ifdef GL_RG8UI
	BOOST_CHECK(x != ev.rg8ui);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB10
	BOOST_CHECK(x != ev.rgb10);
# endif
# ifdef GL_RGB10_A2
	BOOST_CHECK(x != ev.rgb10_a2);
# endif
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM
	x = ev.compressed_srgb_alpha_bptc_unorm;
	BOOST_CHECK(x == ev.compressed_srgb_alpha_bptc_unorm);
# ifdef GL_DEPTH24_STENCIL8
	BOOST_CHECK(x != ev.depth24_stencil8);
# endif
# ifdef GL_DEPTH32F_STENCIL8
	BOOST_CHECK(x != ev.depth32f_stencil8);
# endif
# ifdef GL_DEPTH_COMPONENT
	BOOST_CHECK(x != ev.depth_component);
# endif
# ifdef GL_DEPTH_COMPONENT16
	BOOST_CHECK(x != ev.depth_component16);
# endif
# ifdef GL_DEPTH_COMPONENT24
	BOOST_CHECK(x != ev.depth_component24);
# endif
# ifdef GL_DEPTH_COMPONENT32
	BOOST_CHECK(x != ev.depth_component32);
# endif
# ifdef GL_DEPTH_COMPONENT32F
	BOOST_CHECK(x != ev.depth_component32f);
# endif
# ifdef GL_DEPTH_STENCIL
	BOOST_CHECK(x != ev.depth_stencil);
# endif
# ifdef GL_R11F_G11F_B10F
	BOOST_CHECK(x != ev.r11f_g11f_b10f);
# endif
# ifdef GL_R16
	BOOST_CHECK(x != ev.r16);
# endif
# ifdef GL_R16_SNORM
	BOOST_CHECK(x != ev.r16_snorm);
# endif
# ifdef GL_R16F
	BOOST_CHECK(x != ev.r16f);
# endif
# ifdef GL_R16I
	BOOST_CHECK(x != ev.r16i);
# endif
# ifdef GL_R16UI
	BOOST_CHECK(x != ev.r16ui);
# endif
# ifdef GL_R32F
	BOOST_CHECK(x != ev.r32f);
# endif
# ifdef GL_R32I
	BOOST_CHECK(x != ev.r32i);
# endif
# ifdef GL_R32UI
	BOOST_CHECK(x != ev.r32ui);
# endif
# ifdef GL_R3_G3_B2
	BOOST_CHECK(x != ev.r3_g3_b2);
# endif
# ifdef GL_R8
	BOOST_CHECK(x != ev.r8);
# endif
# ifdef GL_R8_SNORM
	BOOST_CHECK(x != ev.r8_snorm);
# endif
# ifdef GL_R8I
	BOOST_CHECK(x != ev.r8i);
# endif
# ifdef GL_R8UI
	BOOST_CHECK(x != ev.r8ui);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG16
	BOOST_CHECK(x != ev.rg16);
# endif
# ifdef GL_RG16_SNORM
	BOOST_CHECK(x != ev.rg16_snorm);
# endif
# ifdef GL_RG16F
	BOOST_CHECK(x != ev.rg16f);
# endif
# ifdef GL_RG16I
	BOOST_CHECK(x != ev.rg16i);
# endif
# ifdef GL_RG16UI
	BOOST_CHECK(x != ev.rg16ui);
# endif
# ifdef GL_RG32F
	BOOST_CHECK(x != ev.rg32f);
# endif
# ifdef GL_RG32I
	BOOST_CHECK(x != ev.rg32i);
# endif
# ifdef GL_RG32UI
	BOOST_CHECK(x != ev.rg32ui);
# endif
# ifdef GL_RG8
	BOOST_CHECK(x != ev.rg8);
# endif
# ifdef GL_RG8_SNORM
	BOOST_CHECK(x != ev.rg8_snorm);
# endif
# ifdef GL_RG8I
	BOOST_CHECK(x != ev.rg8i);
# endif
# ifdef GL_RG8UI
	BOOST_CHECK(x != ev.rg8ui);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB10
	BOOST_CHECK(x != ev.rgb10);
# endif
# ifdef GL_RGB10_A2
	BOOST_CHECK(x != ev.rgb10_a2);
# endif
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_DEPTH24_STENCIL8
	x = ev.depth24_stencil8;
	BOOST_CHECK(x == ev.depth24_stencil8);
# ifdef GL_DEPTH32F_STENCIL8
	BOOST_CHECK(x != ev.depth32f_stencil8);
# endif
# ifdef GL_DEPTH_COMPONENT
	BOOST_CHECK(x != ev.depth_component);
# endif
# ifdef GL_DEPTH_COMPONENT16
	BOOST_CHECK(x != ev.depth_component16);
# endif
# ifdef GL_DEPTH_COMPONENT24
	BOOST_CHECK(x != ev.depth_component24);
# endif
# ifdef GL_DEPTH_COMPONENT32
	BOOST_CHECK(x != ev.depth_component32);
# endif
# ifdef GL_DEPTH_COMPONENT32F
	BOOST_CHECK(x != ev.depth_component32f);
# endif
# ifdef GL_DEPTH_STENCIL
	BOOST_CHECK(x != ev.depth_stencil);
# endif
# ifdef GL_R11F_G11F_B10F
	BOOST_CHECK(x != ev.r11f_g11f_b10f);
# endif
# ifdef GL_R16
	BOOST_CHECK(x != ev.r16);
# endif
# ifdef GL_R16_SNORM
	BOOST_CHECK(x != ev.r16_snorm);
# endif
# ifdef GL_R16F
	BOOST_CHECK(x != ev.r16f);
# endif
# ifdef GL_R16I
	BOOST_CHECK(x != ev.r16i);
# endif
# ifdef GL_R16UI
	BOOST_CHECK(x != ev.r16ui);
# endif
# ifdef GL_R32F
	BOOST_CHECK(x != ev.r32f);
# endif
# ifdef GL_R32I
	BOOST_CHECK(x != ev.r32i);
# endif
# ifdef GL_R32UI
	BOOST_CHECK(x != ev.r32ui);
# endif
# ifdef GL_R3_G3_B2
	BOOST_CHECK(x != ev.r3_g3_b2);
# endif
# ifdef GL_R8
	BOOST_CHECK(x != ev.r8);
# endif
# ifdef GL_R8_SNORM
	BOOST_CHECK(x != ev.r8_snorm);
# endif
# ifdef GL_R8I
	BOOST_CHECK(x != ev.r8i);
# endif
# ifdef GL_R8UI
	BOOST_CHECK(x != ev.r8ui);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG16
	BOOST_CHECK(x != ev.rg16);
# endif
# ifdef GL_RG16_SNORM
	BOOST_CHECK(x != ev.rg16_snorm);
# endif
# ifdef GL_RG16F
	BOOST_CHECK(x != ev.rg16f);
# endif
# ifdef GL_RG16I
	BOOST_CHECK(x != ev.rg16i);
# endif
# ifdef GL_RG16UI
	BOOST_CHECK(x != ev.rg16ui);
# endif
# ifdef GL_RG32F
	BOOST_CHECK(x != ev.rg32f);
# endif
# ifdef GL_RG32I
	BOOST_CHECK(x != ev.rg32i);
# endif
# ifdef GL_RG32UI
	BOOST_CHECK(x != ev.rg32ui);
# endif
# ifdef GL_RG8
	BOOST_CHECK(x != ev.rg8);
# endif
# ifdef GL_RG8_SNORM
	BOOST_CHECK(x != ev.rg8_snorm);
# endif
# ifdef GL_RG8I
	BOOST_CHECK(x != ev.rg8i);
# endif
# ifdef GL_RG8UI
	BOOST_CHECK(x != ev.rg8ui);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB10
	BOOST_CHECK(x != ev.rgb10);
# endif
# ifdef GL_RGB10_A2
	BOOST_CHECK(x != ev.rgb10_a2);
# endif
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_DEPTH32F_STENCIL8
	x = ev.depth32f_stencil8;
	BOOST_CHECK(x == ev.depth32f_stencil8);
# ifdef GL_DEPTH_COMPONENT
	BOOST_CHECK(x != ev.depth_component);
# endif
# ifdef GL_DEPTH_COMPONENT16
	BOOST_CHECK(x != ev.depth_component16);
# endif
# ifdef GL_DEPTH_COMPONENT24
	BOOST_CHECK(x != ev.depth_component24);
# endif
# ifdef GL_DEPTH_COMPONENT32
	BOOST_CHECK(x != ev.depth_component32);
# endif
# ifdef GL_DEPTH_COMPONENT32F
	BOOST_CHECK(x != ev.depth_component32f);
# endif
# ifdef GL_DEPTH_STENCIL
	BOOST_CHECK(x != ev.depth_stencil);
# endif
# ifdef GL_R11F_G11F_B10F
	BOOST_CHECK(x != ev.r11f_g11f_b10f);
# endif
# ifdef GL_R16
	BOOST_CHECK(x != ev.r16);
# endif
# ifdef GL_R16_SNORM
	BOOST_CHECK(x != ev.r16_snorm);
# endif
# ifdef GL_R16F
	BOOST_CHECK(x != ev.r16f);
# endif
# ifdef GL_R16I
	BOOST_CHECK(x != ev.r16i);
# endif
# ifdef GL_R16UI
	BOOST_CHECK(x != ev.r16ui);
# endif
# ifdef GL_R32F
	BOOST_CHECK(x != ev.r32f);
# endif
# ifdef GL_R32I
	BOOST_CHECK(x != ev.r32i);
# endif
# ifdef GL_R32UI
	BOOST_CHECK(x != ev.r32ui);
# endif
# ifdef GL_R3_G3_B2
	BOOST_CHECK(x != ev.r3_g3_b2);
# endif
# ifdef GL_R8
	BOOST_CHECK(x != ev.r8);
# endif
# ifdef GL_R8_SNORM
	BOOST_CHECK(x != ev.r8_snorm);
# endif
# ifdef GL_R8I
	BOOST_CHECK(x != ev.r8i);
# endif
# ifdef GL_R8UI
	BOOST_CHECK(x != ev.r8ui);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG16
	BOOST_CHECK(x != ev.rg16);
# endif
# ifdef GL_RG16_SNORM
	BOOST_CHECK(x != ev.rg16_snorm);
# endif
# ifdef GL_RG16F
	BOOST_CHECK(x != ev.rg16f);
# endif
# ifdef GL_RG16I
	BOOST_CHECK(x != ev.rg16i);
# endif
# ifdef GL_RG16UI
	BOOST_CHECK(x != ev.rg16ui);
# endif
# ifdef GL_RG32F
	BOOST_CHECK(x != ev.rg32f);
# endif
# ifdef GL_RG32I
	BOOST_CHECK(x != ev.rg32i);
# endif
# ifdef GL_RG32UI
	BOOST_CHECK(x != ev.rg32ui);
# endif
# ifdef GL_RG8
	BOOST_CHECK(x != ev.rg8);
# endif
# ifdef GL_RG8_SNORM
	BOOST_CHECK(x != ev.rg8_snorm);
# endif
# ifdef GL_RG8I
	BOOST_CHECK(x != ev.rg8i);
# endif
# ifdef GL_RG8UI
	BOOST_CHECK(x != ev.rg8ui);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB10
	BOOST_CHECK(x != ev.rgb10);
# endif
# ifdef GL_RGB10_A2
	BOOST_CHECK(x != ev.rgb10_a2);
# endif
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_DEPTH_COMPONENT
	x = ev.depth_component;
	BOOST_CHECK(x == ev.depth_component);
# ifdef GL_DEPTH_COMPONENT16
	BOOST_CHECK(x != ev.depth_component16);
# endif
# ifdef GL_DEPTH_COMPONENT24
	BOOST_CHECK(x != ev.depth_component24);
# endif
# ifdef GL_DEPTH_COMPONENT32
	BOOST_CHECK(x != ev.depth_component32);
# endif
# ifdef GL_DEPTH_COMPONENT32F
	BOOST_CHECK(x != ev.depth_component32f);
# endif
# ifdef GL_DEPTH_STENCIL
	BOOST_CHECK(x != ev.depth_stencil);
# endif
# ifdef GL_R11F_G11F_B10F
	BOOST_CHECK(x != ev.r11f_g11f_b10f);
# endif
# ifdef GL_R16
	BOOST_CHECK(x != ev.r16);
# endif
# ifdef GL_R16_SNORM
	BOOST_CHECK(x != ev.r16_snorm);
# endif
# ifdef GL_R16F
	BOOST_CHECK(x != ev.r16f);
# endif
# ifdef GL_R16I
	BOOST_CHECK(x != ev.r16i);
# endif
# ifdef GL_R16UI
	BOOST_CHECK(x != ev.r16ui);
# endif
# ifdef GL_R32F
	BOOST_CHECK(x != ev.r32f);
# endif
# ifdef GL_R32I
	BOOST_CHECK(x != ev.r32i);
# endif
# ifdef GL_R32UI
	BOOST_CHECK(x != ev.r32ui);
# endif
# ifdef GL_R3_G3_B2
	BOOST_CHECK(x != ev.r3_g3_b2);
# endif
# ifdef GL_R8
	BOOST_CHECK(x != ev.r8);
# endif
# ifdef GL_R8_SNORM
	BOOST_CHECK(x != ev.r8_snorm);
# endif
# ifdef GL_R8I
	BOOST_CHECK(x != ev.r8i);
# endif
# ifdef GL_R8UI
	BOOST_CHECK(x != ev.r8ui);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG16
	BOOST_CHECK(x != ev.rg16);
# endif
# ifdef GL_RG16_SNORM
	BOOST_CHECK(x != ev.rg16_snorm);
# endif
# ifdef GL_RG16F
	BOOST_CHECK(x != ev.rg16f);
# endif
# ifdef GL_RG16I
	BOOST_CHECK(x != ev.rg16i);
# endif
# ifdef GL_RG16UI
	BOOST_CHECK(x != ev.rg16ui);
# endif
# ifdef GL_RG32F
	BOOST_CHECK(x != ev.rg32f);
# endif
# ifdef GL_RG32I
	BOOST_CHECK(x != ev.rg32i);
# endif
# ifdef GL_RG32UI
	BOOST_CHECK(x != ev.rg32ui);
# endif
# ifdef GL_RG8
	BOOST_CHECK(x != ev.rg8);
# endif
# ifdef GL_RG8_SNORM
	BOOST_CHECK(x != ev.rg8_snorm);
# endif
# ifdef GL_RG8I
	BOOST_CHECK(x != ev.rg8i);
# endif
# ifdef GL_RG8UI
	BOOST_CHECK(x != ev.rg8ui);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB10
	BOOST_CHECK(x != ev.rgb10);
# endif
# ifdef GL_RGB10_A2
	BOOST_CHECK(x != ev.rgb10_a2);
# endif
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_DEPTH_COMPONENT16
	x = ev.depth_component16;
	BOOST_CHECK(x == ev.depth_component16);
# ifdef GL_DEPTH_COMPONENT24
	BOOST_CHECK(x != ev.depth_component24);
# endif
# ifdef GL_DEPTH_COMPONENT32
	BOOST_CHECK(x != ev.depth_component32);
# endif
# ifdef GL_DEPTH_COMPONENT32F
	BOOST_CHECK(x != ev.depth_component32f);
# endif
# ifdef GL_DEPTH_STENCIL
	BOOST_CHECK(x != ev.depth_stencil);
# endif
# ifdef GL_R11F_G11F_B10F
	BOOST_CHECK(x != ev.r11f_g11f_b10f);
# endif
# ifdef GL_R16
	BOOST_CHECK(x != ev.r16);
# endif
# ifdef GL_R16_SNORM
	BOOST_CHECK(x != ev.r16_snorm);
# endif
# ifdef GL_R16F
	BOOST_CHECK(x != ev.r16f);
# endif
# ifdef GL_R16I
	BOOST_CHECK(x != ev.r16i);
# endif
# ifdef GL_R16UI
	BOOST_CHECK(x != ev.r16ui);
# endif
# ifdef GL_R32F
	BOOST_CHECK(x != ev.r32f);
# endif
# ifdef GL_R32I
	BOOST_CHECK(x != ev.r32i);
# endif
# ifdef GL_R32UI
	BOOST_CHECK(x != ev.r32ui);
# endif
# ifdef GL_R3_G3_B2
	BOOST_CHECK(x != ev.r3_g3_b2);
# endif
# ifdef GL_R8
	BOOST_CHECK(x != ev.r8);
# endif
# ifdef GL_R8_SNORM
	BOOST_CHECK(x != ev.r8_snorm);
# endif
# ifdef GL_R8I
	BOOST_CHECK(x != ev.r8i);
# endif
# ifdef GL_R8UI
	BOOST_CHECK(x != ev.r8ui);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG16
	BOOST_CHECK(x != ev.rg16);
# endif
# ifdef GL_RG16_SNORM
	BOOST_CHECK(x != ev.rg16_snorm);
# endif
# ifdef GL_RG16F
	BOOST_CHECK(x != ev.rg16f);
# endif
# ifdef GL_RG16I
	BOOST_CHECK(x != ev.rg16i);
# endif
# ifdef GL_RG16UI
	BOOST_CHECK(x != ev.rg16ui);
# endif
# ifdef GL_RG32F
	BOOST_CHECK(x != ev.rg32f);
# endif
# ifdef GL_RG32I
	BOOST_CHECK(x != ev.rg32i);
# endif
# ifdef GL_RG32UI
	BOOST_CHECK(x != ev.rg32ui);
# endif
# ifdef GL_RG8
	BOOST_CHECK(x != ev.rg8);
# endif
# ifdef GL_RG8_SNORM
	BOOST_CHECK(x != ev.rg8_snorm);
# endif
# ifdef GL_RG8I
	BOOST_CHECK(x != ev.rg8i);
# endif
# ifdef GL_RG8UI
	BOOST_CHECK(x != ev.rg8ui);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB10
	BOOST_CHECK(x != ev.rgb10);
# endif
# ifdef GL_RGB10_A2
	BOOST_CHECK(x != ev.rgb10_a2);
# endif
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_DEPTH_COMPONENT24
	x = ev.depth_component24;
	BOOST_CHECK(x == ev.depth_component24);
# ifdef GL_DEPTH_COMPONENT32
	BOOST_CHECK(x != ev.depth_component32);
# endif
# ifdef GL_DEPTH_COMPONENT32F
	BOOST_CHECK(x != ev.depth_component32f);
# endif
# ifdef GL_DEPTH_STENCIL
	BOOST_CHECK(x != ev.depth_stencil);
# endif
# ifdef GL_R11F_G11F_B10F
	BOOST_CHECK(x != ev.r11f_g11f_b10f);
# endif
# ifdef GL_R16
	BOOST_CHECK(x != ev.r16);
# endif
# ifdef GL_R16_SNORM
	BOOST_CHECK(x != ev.r16_snorm);
# endif
# ifdef GL_R16F
	BOOST_CHECK(x != ev.r16f);
# endif
# ifdef GL_R16I
	BOOST_CHECK(x != ev.r16i);
# endif
# ifdef GL_R16UI
	BOOST_CHECK(x != ev.r16ui);
# endif
# ifdef GL_R32F
	BOOST_CHECK(x != ev.r32f);
# endif
# ifdef GL_R32I
	BOOST_CHECK(x != ev.r32i);
# endif
# ifdef GL_R32UI
	BOOST_CHECK(x != ev.r32ui);
# endif
# ifdef GL_R3_G3_B2
	BOOST_CHECK(x != ev.r3_g3_b2);
# endif
# ifdef GL_R8
	BOOST_CHECK(x != ev.r8);
# endif
# ifdef GL_R8_SNORM
	BOOST_CHECK(x != ev.r8_snorm);
# endif
# ifdef GL_R8I
	BOOST_CHECK(x != ev.r8i);
# endif
# ifdef GL_R8UI
	BOOST_CHECK(x != ev.r8ui);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG16
	BOOST_CHECK(x != ev.rg16);
# endif
# ifdef GL_RG16_SNORM
	BOOST_CHECK(x != ev.rg16_snorm);
# endif
# ifdef GL_RG16F
	BOOST_CHECK(x != ev.rg16f);
# endif
# ifdef GL_RG16I
	BOOST_CHECK(x != ev.rg16i);
# endif
# ifdef GL_RG16UI
	BOOST_CHECK(x != ev.rg16ui);
# endif
# ifdef GL_RG32F
	BOOST_CHECK(x != ev.rg32f);
# endif
# ifdef GL_RG32I
	BOOST_CHECK(x != ev.rg32i);
# endif
# ifdef GL_RG32UI
	BOOST_CHECK(x != ev.rg32ui);
# endif
# ifdef GL_RG8
	BOOST_CHECK(x != ev.rg8);
# endif
# ifdef GL_RG8_SNORM
	BOOST_CHECK(x != ev.rg8_snorm);
# endif
# ifdef GL_RG8I
	BOOST_CHECK(x != ev.rg8i);
# endif
# ifdef GL_RG8UI
	BOOST_CHECK(x != ev.rg8ui);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB10
	BOOST_CHECK(x != ev.rgb10);
# endif
# ifdef GL_RGB10_A2
	BOOST_CHECK(x != ev.rgb10_a2);
# endif
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_DEPTH_COMPONENT32
	x = ev.depth_component32;
	BOOST_CHECK(x == ev.depth_component32);
# ifdef GL_DEPTH_COMPONENT32F
	BOOST_CHECK(x != ev.depth_component32f);
# endif
# ifdef GL_DEPTH_STENCIL
	BOOST_CHECK(x != ev.depth_stencil);
# endif
# ifdef GL_R11F_G11F_B10F
	BOOST_CHECK(x != ev.r11f_g11f_b10f);
# endif
# ifdef GL_R16
	BOOST_CHECK(x != ev.r16);
# endif
# ifdef GL_R16_SNORM
	BOOST_CHECK(x != ev.r16_snorm);
# endif
# ifdef GL_R16F
	BOOST_CHECK(x != ev.r16f);
# endif
# ifdef GL_R16I
	BOOST_CHECK(x != ev.r16i);
# endif
# ifdef GL_R16UI
	BOOST_CHECK(x != ev.r16ui);
# endif
# ifdef GL_R32F
	BOOST_CHECK(x != ev.r32f);
# endif
# ifdef GL_R32I
	BOOST_CHECK(x != ev.r32i);
# endif
# ifdef GL_R32UI
	BOOST_CHECK(x != ev.r32ui);
# endif
# ifdef GL_R3_G3_B2
	BOOST_CHECK(x != ev.r3_g3_b2);
# endif
# ifdef GL_R8
	BOOST_CHECK(x != ev.r8);
# endif
# ifdef GL_R8_SNORM
	BOOST_CHECK(x != ev.r8_snorm);
# endif
# ifdef GL_R8I
	BOOST_CHECK(x != ev.r8i);
# endif
# ifdef GL_R8UI
	BOOST_CHECK(x != ev.r8ui);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG16
	BOOST_CHECK(x != ev.rg16);
# endif
# ifdef GL_RG16_SNORM
	BOOST_CHECK(x != ev.rg16_snorm);
# endif
# ifdef GL_RG16F
	BOOST_CHECK(x != ev.rg16f);
# endif
# ifdef GL_RG16I
	BOOST_CHECK(x != ev.rg16i);
# endif
# ifdef GL_RG16UI
	BOOST_CHECK(x != ev.rg16ui);
# endif
# ifdef GL_RG32F
	BOOST_CHECK(x != ev.rg32f);
# endif
# ifdef GL_RG32I
	BOOST_CHECK(x != ev.rg32i);
# endif
# ifdef GL_RG32UI
	BOOST_CHECK(x != ev.rg32ui);
# endif
# ifdef GL_RG8
	BOOST_CHECK(x != ev.rg8);
# endif
# ifdef GL_RG8_SNORM
	BOOST_CHECK(x != ev.rg8_snorm);
# endif
# ifdef GL_RG8I
	BOOST_CHECK(x != ev.rg8i);
# endif
# ifdef GL_RG8UI
	BOOST_CHECK(x != ev.rg8ui);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB10
	BOOST_CHECK(x != ev.rgb10);
# endif
# ifdef GL_RGB10_A2
	BOOST_CHECK(x != ev.rgb10_a2);
# endif
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_DEPTH_COMPONENT32F
	x = ev.depth_component32f;
	BOOST_CHECK(x == ev.depth_component32f);
# ifdef GL_DEPTH_STENCIL
	BOOST_CHECK(x != ev.depth_stencil);
# endif
# ifdef GL_R11F_G11F_B10F
	BOOST_CHECK(x != ev.r11f_g11f_b10f);
# endif
# ifdef GL_R16
	BOOST_CHECK(x != ev.r16);
# endif
# ifdef GL_R16_SNORM
	BOOST_CHECK(x != ev.r16_snorm);
# endif
# ifdef GL_R16F
	BOOST_CHECK(x != ev.r16f);
# endif
# ifdef GL_R16I
	BOOST_CHECK(x != ev.r16i);
# endif
# ifdef GL_R16UI
	BOOST_CHECK(x != ev.r16ui);
# endif
# ifdef GL_R32F
	BOOST_CHECK(x != ev.r32f);
# endif
# ifdef GL_R32I
	BOOST_CHECK(x != ev.r32i);
# endif
# ifdef GL_R32UI
	BOOST_CHECK(x != ev.r32ui);
# endif
# ifdef GL_R3_G3_B2
	BOOST_CHECK(x != ev.r3_g3_b2);
# endif
# ifdef GL_R8
	BOOST_CHECK(x != ev.r8);
# endif
# ifdef GL_R8_SNORM
	BOOST_CHECK(x != ev.r8_snorm);
# endif
# ifdef GL_R8I
	BOOST_CHECK(x != ev.r8i);
# endif
# ifdef GL_R8UI
	BOOST_CHECK(x != ev.r8ui);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG16
	BOOST_CHECK(x != ev.rg16);
# endif
# ifdef GL_RG16_SNORM
	BOOST_CHECK(x != ev.rg16_snorm);
# endif
# ifdef GL_RG16F
	BOOST_CHECK(x != ev.rg16f);
# endif
# ifdef GL_RG16I
	BOOST_CHECK(x != ev.rg16i);
# endif
# ifdef GL_RG16UI
	BOOST_CHECK(x != ev.rg16ui);
# endif
# ifdef GL_RG32F
	BOOST_CHECK(x != ev.rg32f);
# endif
# ifdef GL_RG32I
	BOOST_CHECK(x != ev.rg32i);
# endif
# ifdef GL_RG32UI
	BOOST_CHECK(x != ev.rg32ui);
# endif
# ifdef GL_RG8
	BOOST_CHECK(x != ev.rg8);
# endif
# ifdef GL_RG8_SNORM
	BOOST_CHECK(x != ev.rg8_snorm);
# endif
# ifdef GL_RG8I
	BOOST_CHECK(x != ev.rg8i);
# endif
# ifdef GL_RG8UI
	BOOST_CHECK(x != ev.rg8ui);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB10
	BOOST_CHECK(x != ev.rgb10);
# endif
# ifdef GL_RGB10_A2
	BOOST_CHECK(x != ev.rgb10_a2);
# endif
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_DEPTH_STENCIL
	x = ev.depth_stencil;
	BOOST_CHECK(x == ev.depth_stencil);
# ifdef GL_R11F_G11F_B10F
	BOOST_CHECK(x != ev.r11f_g11f_b10f);
# endif
# ifdef GL_R16
	BOOST_CHECK(x != ev.r16);
# endif
# ifdef GL_R16_SNORM
	BOOST_CHECK(x != ev.r16_snorm);
# endif
# ifdef GL_R16F
	BOOST_CHECK(x != ev.r16f);
# endif
# ifdef GL_R16I
	BOOST_CHECK(x != ev.r16i);
# endif
# ifdef GL_R16UI
	BOOST_CHECK(x != ev.r16ui);
# endif
# ifdef GL_R32F
	BOOST_CHECK(x != ev.r32f);
# endif
# ifdef GL_R32I
	BOOST_CHECK(x != ev.r32i);
# endif
# ifdef GL_R32UI
	BOOST_CHECK(x != ev.r32ui);
# endif
# ifdef GL_R3_G3_B2
	BOOST_CHECK(x != ev.r3_g3_b2);
# endif
# ifdef GL_R8
	BOOST_CHECK(x != ev.r8);
# endif
# ifdef GL_R8_SNORM
	BOOST_CHECK(x != ev.r8_snorm);
# endif
# ifdef GL_R8I
	BOOST_CHECK(x != ev.r8i);
# endif
# ifdef GL_R8UI
	BOOST_CHECK(x != ev.r8ui);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG16
	BOOST_CHECK(x != ev.rg16);
# endif
# ifdef GL_RG16_SNORM
	BOOST_CHECK(x != ev.rg16_snorm);
# endif
# ifdef GL_RG16F
	BOOST_CHECK(x != ev.rg16f);
# endif
# ifdef GL_RG16I
	BOOST_CHECK(x != ev.rg16i);
# endif
# ifdef GL_RG16UI
	BOOST_CHECK(x != ev.rg16ui);
# endif
# ifdef GL_RG32F
	BOOST_CHECK(x != ev.rg32f);
# endif
# ifdef GL_RG32I
	BOOST_CHECK(x != ev.rg32i);
# endif
# ifdef GL_RG32UI
	BOOST_CHECK(x != ev.rg32ui);
# endif
# ifdef GL_RG8
	BOOST_CHECK(x != ev.rg8);
# endif
# ifdef GL_RG8_SNORM
	BOOST_CHECK(x != ev.rg8_snorm);
# endif
# ifdef GL_RG8I
	BOOST_CHECK(x != ev.rg8i);
# endif
# ifdef GL_RG8UI
	BOOST_CHECK(x != ev.rg8ui);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB10
	BOOST_CHECK(x != ev.rgb10);
# endif
# ifdef GL_RGB10_A2
	BOOST_CHECK(x != ev.rgb10_a2);
# endif
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_R11F_G11F_B10F
	x = ev.r11f_g11f_b10f;
	BOOST_CHECK(x == ev.r11f_g11f_b10f);
# ifdef GL_R16
	BOOST_CHECK(x != ev.r16);
# endif
# ifdef GL_R16_SNORM
	BOOST_CHECK(x != ev.r16_snorm);
# endif
# ifdef GL_R16F
	BOOST_CHECK(x != ev.r16f);
# endif
# ifdef GL_R16I
	BOOST_CHECK(x != ev.r16i);
# endif
# ifdef GL_R16UI
	BOOST_CHECK(x != ev.r16ui);
# endif
# ifdef GL_R32F
	BOOST_CHECK(x != ev.r32f);
# endif
# ifdef GL_R32I
	BOOST_CHECK(x != ev.r32i);
# endif
# ifdef GL_R32UI
	BOOST_CHECK(x != ev.r32ui);
# endif
# ifdef GL_R3_G3_B2
	BOOST_CHECK(x != ev.r3_g3_b2);
# endif
# ifdef GL_R8
	BOOST_CHECK(x != ev.r8);
# endif
# ifdef GL_R8_SNORM
	BOOST_CHECK(x != ev.r8_snorm);
# endif
# ifdef GL_R8I
	BOOST_CHECK(x != ev.r8i);
# endif
# ifdef GL_R8UI
	BOOST_CHECK(x != ev.r8ui);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG16
	BOOST_CHECK(x != ev.rg16);
# endif
# ifdef GL_RG16_SNORM
	BOOST_CHECK(x != ev.rg16_snorm);
# endif
# ifdef GL_RG16F
	BOOST_CHECK(x != ev.rg16f);
# endif
# ifdef GL_RG16I
	BOOST_CHECK(x != ev.rg16i);
# endif
# ifdef GL_RG16UI
	BOOST_CHECK(x != ev.rg16ui);
# endif
# ifdef GL_RG32F
	BOOST_CHECK(x != ev.rg32f);
# endif
# ifdef GL_RG32I
	BOOST_CHECK(x != ev.rg32i);
# endif
# ifdef GL_RG32UI
	BOOST_CHECK(x != ev.rg32ui);
# endif
# ifdef GL_RG8
	BOOST_CHECK(x != ev.rg8);
# endif
# ifdef GL_RG8_SNORM
	BOOST_CHECK(x != ev.rg8_snorm);
# endif
# ifdef GL_RG8I
	BOOST_CHECK(x != ev.rg8i);
# endif
# ifdef GL_RG8UI
	BOOST_CHECK(x != ev.rg8ui);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB10
	BOOST_CHECK(x != ev.rgb10);
# endif
# ifdef GL_RGB10_A2
	BOOST_CHECK(x != ev.rgb10_a2);
# endif
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_R16
	x = ev.r16;
	BOOST_CHECK(x == ev.r16);
# ifdef GL_R16_SNORM
	BOOST_CHECK(x != ev.r16_snorm);
# endif
# ifdef GL_R16F
	BOOST_CHECK(x != ev.r16f);
# endif
# ifdef GL_R16I
	BOOST_CHECK(x != ev.r16i);
# endif
# ifdef GL_R16UI
	BOOST_CHECK(x != ev.r16ui);
# endif
# ifdef GL_R32F
	BOOST_CHECK(x != ev.r32f);
# endif
# ifdef GL_R32I
	BOOST_CHECK(x != ev.r32i);
# endif
# ifdef GL_R32UI
	BOOST_CHECK(x != ev.r32ui);
# endif
# ifdef GL_R3_G3_B2
	BOOST_CHECK(x != ev.r3_g3_b2);
# endif
# ifdef GL_R8
	BOOST_CHECK(x != ev.r8);
# endif
# ifdef GL_R8_SNORM
	BOOST_CHECK(x != ev.r8_snorm);
# endif
# ifdef GL_R8I
	BOOST_CHECK(x != ev.r8i);
# endif
# ifdef GL_R8UI
	BOOST_CHECK(x != ev.r8ui);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG16
	BOOST_CHECK(x != ev.rg16);
# endif
# ifdef GL_RG16_SNORM
	BOOST_CHECK(x != ev.rg16_snorm);
# endif
# ifdef GL_RG16F
	BOOST_CHECK(x != ev.rg16f);
# endif
# ifdef GL_RG16I
	BOOST_CHECK(x != ev.rg16i);
# endif
# ifdef GL_RG16UI
	BOOST_CHECK(x != ev.rg16ui);
# endif
# ifdef GL_RG32F
	BOOST_CHECK(x != ev.rg32f);
# endif
# ifdef GL_RG32I
	BOOST_CHECK(x != ev.rg32i);
# endif
# ifdef GL_RG32UI
	BOOST_CHECK(x != ev.rg32ui);
# endif
# ifdef GL_RG8
	BOOST_CHECK(x != ev.rg8);
# endif
# ifdef GL_RG8_SNORM
	BOOST_CHECK(x != ev.rg8_snorm);
# endif
# ifdef GL_RG8I
	BOOST_CHECK(x != ev.rg8i);
# endif
# ifdef GL_RG8UI
	BOOST_CHECK(x != ev.rg8ui);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB10
	BOOST_CHECK(x != ev.rgb10);
# endif
# ifdef GL_RGB10_A2
	BOOST_CHECK(x != ev.rgb10_a2);
# endif
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_R16_SNORM
	x = ev.r16_snorm;
	BOOST_CHECK(x == ev.r16_snorm);
# ifdef GL_R16F
	BOOST_CHECK(x != ev.r16f);
# endif
# ifdef GL_R16I
	BOOST_CHECK(x != ev.r16i);
# endif
# ifdef GL_R16UI
	BOOST_CHECK(x != ev.r16ui);
# endif
# ifdef GL_R32F
	BOOST_CHECK(x != ev.r32f);
# endif
# ifdef GL_R32I
	BOOST_CHECK(x != ev.r32i);
# endif
# ifdef GL_R32UI
	BOOST_CHECK(x != ev.r32ui);
# endif
# ifdef GL_R3_G3_B2
	BOOST_CHECK(x != ev.r3_g3_b2);
# endif
# ifdef GL_R8
	BOOST_CHECK(x != ev.r8);
# endif
# ifdef GL_R8_SNORM
	BOOST_CHECK(x != ev.r8_snorm);
# endif
# ifdef GL_R8I
	BOOST_CHECK(x != ev.r8i);
# endif
# ifdef GL_R8UI
	BOOST_CHECK(x != ev.r8ui);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG16
	BOOST_CHECK(x != ev.rg16);
# endif
# ifdef GL_RG16_SNORM
	BOOST_CHECK(x != ev.rg16_snorm);
# endif
# ifdef GL_RG16F
	BOOST_CHECK(x != ev.rg16f);
# endif
# ifdef GL_RG16I
	BOOST_CHECK(x != ev.rg16i);
# endif
# ifdef GL_RG16UI
	BOOST_CHECK(x != ev.rg16ui);
# endif
# ifdef GL_RG32F
	BOOST_CHECK(x != ev.rg32f);
# endif
# ifdef GL_RG32I
	BOOST_CHECK(x != ev.rg32i);
# endif
# ifdef GL_RG32UI
	BOOST_CHECK(x != ev.rg32ui);
# endif
# ifdef GL_RG8
	BOOST_CHECK(x != ev.rg8);
# endif
# ifdef GL_RG8_SNORM
	BOOST_CHECK(x != ev.rg8_snorm);
# endif
# ifdef GL_RG8I
	BOOST_CHECK(x != ev.rg8i);
# endif
# ifdef GL_RG8UI
	BOOST_CHECK(x != ev.rg8ui);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB10
	BOOST_CHECK(x != ev.rgb10);
# endif
# ifdef GL_RGB10_A2
	BOOST_CHECK(x != ev.rgb10_a2);
# endif
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_R16F
	x = ev.r16f;
	BOOST_CHECK(x == ev.r16f);
# ifdef GL_R16I
	BOOST_CHECK(x != ev.r16i);
# endif
# ifdef GL_R16UI
	BOOST_CHECK(x != ev.r16ui);
# endif
# ifdef GL_R32F
	BOOST_CHECK(x != ev.r32f);
# endif
# ifdef GL_R32I
	BOOST_CHECK(x != ev.r32i);
# endif
# ifdef GL_R32UI
	BOOST_CHECK(x != ev.r32ui);
# endif
# ifdef GL_R3_G3_B2
	BOOST_CHECK(x != ev.r3_g3_b2);
# endif
# ifdef GL_R8
	BOOST_CHECK(x != ev.r8);
# endif
# ifdef GL_R8_SNORM
	BOOST_CHECK(x != ev.r8_snorm);
# endif
# ifdef GL_R8I
	BOOST_CHECK(x != ev.r8i);
# endif
# ifdef GL_R8UI
	BOOST_CHECK(x != ev.r8ui);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG16
	BOOST_CHECK(x != ev.rg16);
# endif
# ifdef GL_RG16_SNORM
	BOOST_CHECK(x != ev.rg16_snorm);
# endif
# ifdef GL_RG16F
	BOOST_CHECK(x != ev.rg16f);
# endif
# ifdef GL_RG16I
	BOOST_CHECK(x != ev.rg16i);
# endif
# ifdef GL_RG16UI
	BOOST_CHECK(x != ev.rg16ui);
# endif
# ifdef GL_RG32F
	BOOST_CHECK(x != ev.rg32f);
# endif
# ifdef GL_RG32I
	BOOST_CHECK(x != ev.rg32i);
# endif
# ifdef GL_RG32UI
	BOOST_CHECK(x != ev.rg32ui);
# endif
# ifdef GL_RG8
	BOOST_CHECK(x != ev.rg8);
# endif
# ifdef GL_RG8_SNORM
	BOOST_CHECK(x != ev.rg8_snorm);
# endif
# ifdef GL_RG8I
	BOOST_CHECK(x != ev.rg8i);
# endif
# ifdef GL_RG8UI
	BOOST_CHECK(x != ev.rg8ui);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB10
	BOOST_CHECK(x != ev.rgb10);
# endif
# ifdef GL_RGB10_A2
	BOOST_CHECK(x != ev.rgb10_a2);
# endif
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_R16I
	x = ev.r16i;
	BOOST_CHECK(x == ev.r16i);
# ifdef GL_R16UI
	BOOST_CHECK(x != ev.r16ui);
# endif
# ifdef GL_R32F
	BOOST_CHECK(x != ev.r32f);
# endif
# ifdef GL_R32I
	BOOST_CHECK(x != ev.r32i);
# endif
# ifdef GL_R32UI
	BOOST_CHECK(x != ev.r32ui);
# endif
# ifdef GL_R3_G3_B2
	BOOST_CHECK(x != ev.r3_g3_b2);
# endif
# ifdef GL_R8
	BOOST_CHECK(x != ev.r8);
# endif
# ifdef GL_R8_SNORM
	BOOST_CHECK(x != ev.r8_snorm);
# endif
# ifdef GL_R8I
	BOOST_CHECK(x != ev.r8i);
# endif
# ifdef GL_R8UI
	BOOST_CHECK(x != ev.r8ui);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG16
	BOOST_CHECK(x != ev.rg16);
# endif
# ifdef GL_RG16_SNORM
	BOOST_CHECK(x != ev.rg16_snorm);
# endif
# ifdef GL_RG16F
	BOOST_CHECK(x != ev.rg16f);
# endif
# ifdef GL_RG16I
	BOOST_CHECK(x != ev.rg16i);
# endif
# ifdef GL_RG16UI
	BOOST_CHECK(x != ev.rg16ui);
# endif
# ifdef GL_RG32F
	BOOST_CHECK(x != ev.rg32f);
# endif
# ifdef GL_RG32I
	BOOST_CHECK(x != ev.rg32i);
# endif
# ifdef GL_RG32UI
	BOOST_CHECK(x != ev.rg32ui);
# endif
# ifdef GL_RG8
	BOOST_CHECK(x != ev.rg8);
# endif
# ifdef GL_RG8_SNORM
	BOOST_CHECK(x != ev.rg8_snorm);
# endif
# ifdef GL_RG8I
	BOOST_CHECK(x != ev.rg8i);
# endif
# ifdef GL_RG8UI
	BOOST_CHECK(x != ev.rg8ui);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB10
	BOOST_CHECK(x != ev.rgb10);
# endif
# ifdef GL_RGB10_A2
	BOOST_CHECK(x != ev.rgb10_a2);
# endif
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_R16UI
	x = ev.r16ui;
	BOOST_CHECK(x == ev.r16ui);
# ifdef GL_R32F
	BOOST_CHECK(x != ev.r32f);
# endif
# ifdef GL_R32I
	BOOST_CHECK(x != ev.r32i);
# endif
# ifdef GL_R32UI
	BOOST_CHECK(x != ev.r32ui);
# endif
# ifdef GL_R3_G3_B2
	BOOST_CHECK(x != ev.r3_g3_b2);
# endif
# ifdef GL_R8
	BOOST_CHECK(x != ev.r8);
# endif
# ifdef GL_R8_SNORM
	BOOST_CHECK(x != ev.r8_snorm);
# endif
# ifdef GL_R8I
	BOOST_CHECK(x != ev.r8i);
# endif
# ifdef GL_R8UI
	BOOST_CHECK(x != ev.r8ui);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG16
	BOOST_CHECK(x != ev.rg16);
# endif
# ifdef GL_RG16_SNORM
	BOOST_CHECK(x != ev.rg16_snorm);
# endif
# ifdef GL_RG16F
	BOOST_CHECK(x != ev.rg16f);
# endif
# ifdef GL_RG16I
	BOOST_CHECK(x != ev.rg16i);
# endif
# ifdef GL_RG16UI
	BOOST_CHECK(x != ev.rg16ui);
# endif
# ifdef GL_RG32F
	BOOST_CHECK(x != ev.rg32f);
# endif
# ifdef GL_RG32I
	BOOST_CHECK(x != ev.rg32i);
# endif
# ifdef GL_RG32UI
	BOOST_CHECK(x != ev.rg32ui);
# endif
# ifdef GL_RG8
	BOOST_CHECK(x != ev.rg8);
# endif
# ifdef GL_RG8_SNORM
	BOOST_CHECK(x != ev.rg8_snorm);
# endif
# ifdef GL_RG8I
	BOOST_CHECK(x != ev.rg8i);
# endif
# ifdef GL_RG8UI
	BOOST_CHECK(x != ev.rg8ui);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB10
	BOOST_CHECK(x != ev.rgb10);
# endif
# ifdef GL_RGB10_A2
	BOOST_CHECK(x != ev.rgb10_a2);
# endif
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_R32F
	x = ev.r32f;
	BOOST_CHECK(x == ev.r32f);
# ifdef GL_R32I
	BOOST_CHECK(x != ev.r32i);
# endif
# ifdef GL_R32UI
	BOOST_CHECK(x != ev.r32ui);
# endif
# ifdef GL_R3_G3_B2
	BOOST_CHECK(x != ev.r3_g3_b2);
# endif
# ifdef GL_R8
	BOOST_CHECK(x != ev.r8);
# endif
# ifdef GL_R8_SNORM
	BOOST_CHECK(x != ev.r8_snorm);
# endif
# ifdef GL_R8I
	BOOST_CHECK(x != ev.r8i);
# endif
# ifdef GL_R8UI
	BOOST_CHECK(x != ev.r8ui);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG16
	BOOST_CHECK(x != ev.rg16);
# endif
# ifdef GL_RG16_SNORM
	BOOST_CHECK(x != ev.rg16_snorm);
# endif
# ifdef GL_RG16F
	BOOST_CHECK(x != ev.rg16f);
# endif
# ifdef GL_RG16I
	BOOST_CHECK(x != ev.rg16i);
# endif
# ifdef GL_RG16UI
	BOOST_CHECK(x != ev.rg16ui);
# endif
# ifdef GL_RG32F
	BOOST_CHECK(x != ev.rg32f);
# endif
# ifdef GL_RG32I
	BOOST_CHECK(x != ev.rg32i);
# endif
# ifdef GL_RG32UI
	BOOST_CHECK(x != ev.rg32ui);
# endif
# ifdef GL_RG8
	BOOST_CHECK(x != ev.rg8);
# endif
# ifdef GL_RG8_SNORM
	BOOST_CHECK(x != ev.rg8_snorm);
# endif
# ifdef GL_RG8I
	BOOST_CHECK(x != ev.rg8i);
# endif
# ifdef GL_RG8UI
	BOOST_CHECK(x != ev.rg8ui);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB10
	BOOST_CHECK(x != ev.rgb10);
# endif
# ifdef GL_RGB10_A2
	BOOST_CHECK(x != ev.rgb10_a2);
# endif
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_R32I
	x = ev.r32i;
	BOOST_CHECK(x == ev.r32i);
# ifdef GL_R32UI
	BOOST_CHECK(x != ev.r32ui);
# endif
# ifdef GL_R3_G3_B2
	BOOST_CHECK(x != ev.r3_g3_b2);
# endif
# ifdef GL_R8
	BOOST_CHECK(x != ev.r8);
# endif
# ifdef GL_R8_SNORM
	BOOST_CHECK(x != ev.r8_snorm);
# endif
# ifdef GL_R8I
	BOOST_CHECK(x != ev.r8i);
# endif
# ifdef GL_R8UI
	BOOST_CHECK(x != ev.r8ui);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG16
	BOOST_CHECK(x != ev.rg16);
# endif
# ifdef GL_RG16_SNORM
	BOOST_CHECK(x != ev.rg16_snorm);
# endif
# ifdef GL_RG16F
	BOOST_CHECK(x != ev.rg16f);
# endif
# ifdef GL_RG16I
	BOOST_CHECK(x != ev.rg16i);
# endif
# ifdef GL_RG16UI
	BOOST_CHECK(x != ev.rg16ui);
# endif
# ifdef GL_RG32F
	BOOST_CHECK(x != ev.rg32f);
# endif
# ifdef GL_RG32I
	BOOST_CHECK(x != ev.rg32i);
# endif
# ifdef GL_RG32UI
	BOOST_CHECK(x != ev.rg32ui);
# endif
# ifdef GL_RG8
	BOOST_CHECK(x != ev.rg8);
# endif
# ifdef GL_RG8_SNORM
	BOOST_CHECK(x != ev.rg8_snorm);
# endif
# ifdef GL_RG8I
	BOOST_CHECK(x != ev.rg8i);
# endif
# ifdef GL_RG8UI
	BOOST_CHECK(x != ev.rg8ui);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB10
	BOOST_CHECK(x != ev.rgb10);
# endif
# ifdef GL_RGB10_A2
	BOOST_CHECK(x != ev.rgb10_a2);
# endif
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_R32UI
	x = ev.r32ui;
	BOOST_CHECK(x == ev.r32ui);
# ifdef GL_R3_G3_B2
	BOOST_CHECK(x != ev.r3_g3_b2);
# endif
# ifdef GL_R8
	BOOST_CHECK(x != ev.r8);
# endif
# ifdef GL_R8_SNORM
	BOOST_CHECK(x != ev.r8_snorm);
# endif
# ifdef GL_R8I
	BOOST_CHECK(x != ev.r8i);
# endif
# ifdef GL_R8UI
	BOOST_CHECK(x != ev.r8ui);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG16
	BOOST_CHECK(x != ev.rg16);
# endif
# ifdef GL_RG16_SNORM
	BOOST_CHECK(x != ev.rg16_snorm);
# endif
# ifdef GL_RG16F
	BOOST_CHECK(x != ev.rg16f);
# endif
# ifdef GL_RG16I
	BOOST_CHECK(x != ev.rg16i);
# endif
# ifdef GL_RG16UI
	BOOST_CHECK(x != ev.rg16ui);
# endif
# ifdef GL_RG32F
	BOOST_CHECK(x != ev.rg32f);
# endif
# ifdef GL_RG32I
	BOOST_CHECK(x != ev.rg32i);
# endif
# ifdef GL_RG32UI
	BOOST_CHECK(x != ev.rg32ui);
# endif
# ifdef GL_RG8
	BOOST_CHECK(x != ev.rg8);
# endif
# ifdef GL_RG8_SNORM
	BOOST_CHECK(x != ev.rg8_snorm);
# endif
# ifdef GL_RG8I
	BOOST_CHECK(x != ev.rg8i);
# endif
# ifdef GL_RG8UI
	BOOST_CHECK(x != ev.rg8ui);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB10
	BOOST_CHECK(x != ev.rgb10);
# endif
# ifdef GL_RGB10_A2
	BOOST_CHECK(x != ev.rgb10_a2);
# endif
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_R3_G3_B2
	x = ev.r3_g3_b2;
	BOOST_CHECK(x == ev.r3_g3_b2);
# ifdef GL_R8
	BOOST_CHECK(x != ev.r8);
# endif
# ifdef GL_R8_SNORM
	BOOST_CHECK(x != ev.r8_snorm);
# endif
# ifdef GL_R8I
	BOOST_CHECK(x != ev.r8i);
# endif
# ifdef GL_R8UI
	BOOST_CHECK(x != ev.r8ui);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG16
	BOOST_CHECK(x != ev.rg16);
# endif
# ifdef GL_RG16_SNORM
	BOOST_CHECK(x != ev.rg16_snorm);
# endif
# ifdef GL_RG16F
	BOOST_CHECK(x != ev.rg16f);
# endif
# ifdef GL_RG16I
	BOOST_CHECK(x != ev.rg16i);
# endif
# ifdef GL_RG16UI
	BOOST_CHECK(x != ev.rg16ui);
# endif
# ifdef GL_RG32F
	BOOST_CHECK(x != ev.rg32f);
# endif
# ifdef GL_RG32I
	BOOST_CHECK(x != ev.rg32i);
# endif
# ifdef GL_RG32UI
	BOOST_CHECK(x != ev.rg32ui);
# endif
# ifdef GL_RG8
	BOOST_CHECK(x != ev.rg8);
# endif
# ifdef GL_RG8_SNORM
	BOOST_CHECK(x != ev.rg8_snorm);
# endif
# ifdef GL_RG8I
	BOOST_CHECK(x != ev.rg8i);
# endif
# ifdef GL_RG8UI
	BOOST_CHECK(x != ev.rg8ui);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB10
	BOOST_CHECK(x != ev.rgb10);
# endif
# ifdef GL_RGB10_A2
	BOOST_CHECK(x != ev.rgb10_a2);
# endif
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_R8
	x = ev.r8;
	BOOST_CHECK(x == ev.r8);
# ifdef GL_R8_SNORM
	BOOST_CHECK(x != ev.r8_snorm);
# endif
# ifdef GL_R8I
	BOOST_CHECK(x != ev.r8i);
# endif
# ifdef GL_R8UI
	BOOST_CHECK(x != ev.r8ui);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG16
	BOOST_CHECK(x != ev.rg16);
# endif
# ifdef GL_RG16_SNORM
	BOOST_CHECK(x != ev.rg16_snorm);
# endif
# ifdef GL_RG16F
	BOOST_CHECK(x != ev.rg16f);
# endif
# ifdef GL_RG16I
	BOOST_CHECK(x != ev.rg16i);
# endif
# ifdef GL_RG16UI
	BOOST_CHECK(x != ev.rg16ui);
# endif
# ifdef GL_RG32F
	BOOST_CHECK(x != ev.rg32f);
# endif
# ifdef GL_RG32I
	BOOST_CHECK(x != ev.rg32i);
# endif
# ifdef GL_RG32UI
	BOOST_CHECK(x != ev.rg32ui);
# endif
# ifdef GL_RG8
	BOOST_CHECK(x != ev.rg8);
# endif
# ifdef GL_RG8_SNORM
	BOOST_CHECK(x != ev.rg8_snorm);
# endif
# ifdef GL_RG8I
	BOOST_CHECK(x != ev.rg8i);
# endif
# ifdef GL_RG8UI
	BOOST_CHECK(x != ev.rg8ui);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB10
	BOOST_CHECK(x != ev.rgb10);
# endif
# ifdef GL_RGB10_A2
	BOOST_CHECK(x != ev.rgb10_a2);
# endif
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_R8_SNORM
	x = ev.r8_snorm;
	BOOST_CHECK(x == ev.r8_snorm);
# ifdef GL_R8I
	BOOST_CHECK(x != ev.r8i);
# endif
# ifdef GL_R8UI
	BOOST_CHECK(x != ev.r8ui);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG16
	BOOST_CHECK(x != ev.rg16);
# endif
# ifdef GL_RG16_SNORM
	BOOST_CHECK(x != ev.rg16_snorm);
# endif
# ifdef GL_RG16F
	BOOST_CHECK(x != ev.rg16f);
# endif
# ifdef GL_RG16I
	BOOST_CHECK(x != ev.rg16i);
# endif
# ifdef GL_RG16UI
	BOOST_CHECK(x != ev.rg16ui);
# endif
# ifdef GL_RG32F
	BOOST_CHECK(x != ev.rg32f);
# endif
# ifdef GL_RG32I
	BOOST_CHECK(x != ev.rg32i);
# endif
# ifdef GL_RG32UI
	BOOST_CHECK(x != ev.rg32ui);
# endif
# ifdef GL_RG8
	BOOST_CHECK(x != ev.rg8);
# endif
# ifdef GL_RG8_SNORM
	BOOST_CHECK(x != ev.rg8_snorm);
# endif
# ifdef GL_RG8I
	BOOST_CHECK(x != ev.rg8i);
# endif
# ifdef GL_RG8UI
	BOOST_CHECK(x != ev.rg8ui);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB10
	BOOST_CHECK(x != ev.rgb10);
# endif
# ifdef GL_RGB10_A2
	BOOST_CHECK(x != ev.rgb10_a2);
# endif
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_R8I
	x = ev.r8i;
	BOOST_CHECK(x == ev.r8i);
# ifdef GL_R8UI
	BOOST_CHECK(x != ev.r8ui);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG16
	BOOST_CHECK(x != ev.rg16);
# endif
# ifdef GL_RG16_SNORM
	BOOST_CHECK(x != ev.rg16_snorm);
# endif
# ifdef GL_RG16F
	BOOST_CHECK(x != ev.rg16f);
# endif
# ifdef GL_RG16I
	BOOST_CHECK(x != ev.rg16i);
# endif
# ifdef GL_RG16UI
	BOOST_CHECK(x != ev.rg16ui);
# endif
# ifdef GL_RG32F
	BOOST_CHECK(x != ev.rg32f);
# endif
# ifdef GL_RG32I
	BOOST_CHECK(x != ev.rg32i);
# endif
# ifdef GL_RG32UI
	BOOST_CHECK(x != ev.rg32ui);
# endif
# ifdef GL_RG8
	BOOST_CHECK(x != ev.rg8);
# endif
# ifdef GL_RG8_SNORM
	BOOST_CHECK(x != ev.rg8_snorm);
# endif
# ifdef GL_RG8I
	BOOST_CHECK(x != ev.rg8i);
# endif
# ifdef GL_RG8UI
	BOOST_CHECK(x != ev.rg8ui);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB10
	BOOST_CHECK(x != ev.rgb10);
# endif
# ifdef GL_RGB10_A2
	BOOST_CHECK(x != ev.rgb10_a2);
# endif
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_R8UI
	x = ev.r8ui;
	BOOST_CHECK(x == ev.r8ui);
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG16
	BOOST_CHECK(x != ev.rg16);
# endif
# ifdef GL_RG16_SNORM
	BOOST_CHECK(x != ev.rg16_snorm);
# endif
# ifdef GL_RG16F
	BOOST_CHECK(x != ev.rg16f);
# endif
# ifdef GL_RG16I
	BOOST_CHECK(x != ev.rg16i);
# endif
# ifdef GL_RG16UI
	BOOST_CHECK(x != ev.rg16ui);
# endif
# ifdef GL_RG32F
	BOOST_CHECK(x != ev.rg32f);
# endif
# ifdef GL_RG32I
	BOOST_CHECK(x != ev.rg32i);
# endif
# ifdef GL_RG32UI
	BOOST_CHECK(x != ev.rg32ui);
# endif
# ifdef GL_RG8
	BOOST_CHECK(x != ev.rg8);
# endif
# ifdef GL_RG8_SNORM
	BOOST_CHECK(x != ev.rg8_snorm);
# endif
# ifdef GL_RG8I
	BOOST_CHECK(x != ev.rg8i);
# endif
# ifdef GL_RG8UI
	BOOST_CHECK(x != ev.rg8ui);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB10
	BOOST_CHECK(x != ev.rgb10);
# endif
# ifdef GL_RGB10_A2
	BOOST_CHECK(x != ev.rgb10_a2);
# endif
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_RED
	x = ev.red;
	BOOST_CHECK(x == ev.red);
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG16
	BOOST_CHECK(x != ev.rg16);
# endif
# ifdef GL_RG16_SNORM
	BOOST_CHECK(x != ev.rg16_snorm);
# endif
# ifdef GL_RG16F
	BOOST_CHECK(x != ev.rg16f);
# endif
# ifdef GL_RG16I
	BOOST_CHECK(x != ev.rg16i);
# endif
# ifdef GL_RG16UI
	BOOST_CHECK(x != ev.rg16ui);
# endif
# ifdef GL_RG32F
	BOOST_CHECK(x != ev.rg32f);
# endif
# ifdef GL_RG32I
	BOOST_CHECK(x != ev.rg32i);
# endif
# ifdef GL_RG32UI
	BOOST_CHECK(x != ev.rg32ui);
# endif
# ifdef GL_RG8
	BOOST_CHECK(x != ev.rg8);
# endif
# ifdef GL_RG8_SNORM
	BOOST_CHECK(x != ev.rg8_snorm);
# endif
# ifdef GL_RG8I
	BOOST_CHECK(x != ev.rg8i);
# endif
# ifdef GL_RG8UI
	BOOST_CHECK(x != ev.rg8ui);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB10
	BOOST_CHECK(x != ev.rgb10);
# endif
# ifdef GL_RGB10_A2
	BOOST_CHECK(x != ev.rgb10_a2);
# endif
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_RG
	x = ev.rg;
	BOOST_CHECK(x == ev.rg);
# ifdef GL_RG16
	BOOST_CHECK(x != ev.rg16);
# endif
# ifdef GL_RG16_SNORM
	BOOST_CHECK(x != ev.rg16_snorm);
# endif
# ifdef GL_RG16F
	BOOST_CHECK(x != ev.rg16f);
# endif
# ifdef GL_RG16I
	BOOST_CHECK(x != ev.rg16i);
# endif
# ifdef GL_RG16UI
	BOOST_CHECK(x != ev.rg16ui);
# endif
# ifdef GL_RG32F
	BOOST_CHECK(x != ev.rg32f);
# endif
# ifdef GL_RG32I
	BOOST_CHECK(x != ev.rg32i);
# endif
# ifdef GL_RG32UI
	BOOST_CHECK(x != ev.rg32ui);
# endif
# ifdef GL_RG8
	BOOST_CHECK(x != ev.rg8);
# endif
# ifdef GL_RG8_SNORM
	BOOST_CHECK(x != ev.rg8_snorm);
# endif
# ifdef GL_RG8I
	BOOST_CHECK(x != ev.rg8i);
# endif
# ifdef GL_RG8UI
	BOOST_CHECK(x != ev.rg8ui);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB10
	BOOST_CHECK(x != ev.rgb10);
# endif
# ifdef GL_RGB10_A2
	BOOST_CHECK(x != ev.rgb10_a2);
# endif
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_RG16
	x = ev.rg16;
	BOOST_CHECK(x == ev.rg16);
# ifdef GL_RG16_SNORM
	BOOST_CHECK(x != ev.rg16_snorm);
# endif
# ifdef GL_RG16F
	BOOST_CHECK(x != ev.rg16f);
# endif
# ifdef GL_RG16I
	BOOST_CHECK(x != ev.rg16i);
# endif
# ifdef GL_RG16UI
	BOOST_CHECK(x != ev.rg16ui);
# endif
# ifdef GL_RG32F
	BOOST_CHECK(x != ev.rg32f);
# endif
# ifdef GL_RG32I
	BOOST_CHECK(x != ev.rg32i);
# endif
# ifdef GL_RG32UI
	BOOST_CHECK(x != ev.rg32ui);
# endif
# ifdef GL_RG8
	BOOST_CHECK(x != ev.rg8);
# endif
# ifdef GL_RG8_SNORM
	BOOST_CHECK(x != ev.rg8_snorm);
# endif
# ifdef GL_RG8I
	BOOST_CHECK(x != ev.rg8i);
# endif
# ifdef GL_RG8UI
	BOOST_CHECK(x != ev.rg8ui);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB10
	BOOST_CHECK(x != ev.rgb10);
# endif
# ifdef GL_RGB10_A2
	BOOST_CHECK(x != ev.rgb10_a2);
# endif
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_RG16_SNORM
	x = ev.rg16_snorm;
	BOOST_CHECK(x == ev.rg16_snorm);
# ifdef GL_RG16F
	BOOST_CHECK(x != ev.rg16f);
# endif
# ifdef GL_RG16I
	BOOST_CHECK(x != ev.rg16i);
# endif
# ifdef GL_RG16UI
	BOOST_CHECK(x != ev.rg16ui);
# endif
# ifdef GL_RG32F
	BOOST_CHECK(x != ev.rg32f);
# endif
# ifdef GL_RG32I
	BOOST_CHECK(x != ev.rg32i);
# endif
# ifdef GL_RG32UI
	BOOST_CHECK(x != ev.rg32ui);
# endif
# ifdef GL_RG8
	BOOST_CHECK(x != ev.rg8);
# endif
# ifdef GL_RG8_SNORM
	BOOST_CHECK(x != ev.rg8_snorm);
# endif
# ifdef GL_RG8I
	BOOST_CHECK(x != ev.rg8i);
# endif
# ifdef GL_RG8UI
	BOOST_CHECK(x != ev.rg8ui);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB10
	BOOST_CHECK(x != ev.rgb10);
# endif
# ifdef GL_RGB10_A2
	BOOST_CHECK(x != ev.rgb10_a2);
# endif
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_RG16F
	x = ev.rg16f;
	BOOST_CHECK(x == ev.rg16f);
# ifdef GL_RG16I
	BOOST_CHECK(x != ev.rg16i);
# endif
# ifdef GL_RG16UI
	BOOST_CHECK(x != ev.rg16ui);
# endif
# ifdef GL_RG32F
	BOOST_CHECK(x != ev.rg32f);
# endif
# ifdef GL_RG32I
	BOOST_CHECK(x != ev.rg32i);
# endif
# ifdef GL_RG32UI
	BOOST_CHECK(x != ev.rg32ui);
# endif
# ifdef GL_RG8
	BOOST_CHECK(x != ev.rg8);
# endif
# ifdef GL_RG8_SNORM
	BOOST_CHECK(x != ev.rg8_snorm);
# endif
# ifdef GL_RG8I
	BOOST_CHECK(x != ev.rg8i);
# endif
# ifdef GL_RG8UI
	BOOST_CHECK(x != ev.rg8ui);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB10
	BOOST_CHECK(x != ev.rgb10);
# endif
# ifdef GL_RGB10_A2
	BOOST_CHECK(x != ev.rgb10_a2);
# endif
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_RG16I
	x = ev.rg16i;
	BOOST_CHECK(x == ev.rg16i);
# ifdef GL_RG16UI
	BOOST_CHECK(x != ev.rg16ui);
# endif
# ifdef GL_RG32F
	BOOST_CHECK(x != ev.rg32f);
# endif
# ifdef GL_RG32I
	BOOST_CHECK(x != ev.rg32i);
# endif
# ifdef GL_RG32UI
	BOOST_CHECK(x != ev.rg32ui);
# endif
# ifdef GL_RG8
	BOOST_CHECK(x != ev.rg8);
# endif
# ifdef GL_RG8_SNORM
	BOOST_CHECK(x != ev.rg8_snorm);
# endif
# ifdef GL_RG8I
	BOOST_CHECK(x != ev.rg8i);
# endif
# ifdef GL_RG8UI
	BOOST_CHECK(x != ev.rg8ui);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB10
	BOOST_CHECK(x != ev.rgb10);
# endif
# ifdef GL_RGB10_A2
	BOOST_CHECK(x != ev.rgb10_a2);
# endif
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_RG16UI
	x = ev.rg16ui;
	BOOST_CHECK(x == ev.rg16ui);
# ifdef GL_RG32F
	BOOST_CHECK(x != ev.rg32f);
# endif
# ifdef GL_RG32I
	BOOST_CHECK(x != ev.rg32i);
# endif
# ifdef GL_RG32UI
	BOOST_CHECK(x != ev.rg32ui);
# endif
# ifdef GL_RG8
	BOOST_CHECK(x != ev.rg8);
# endif
# ifdef GL_RG8_SNORM
	BOOST_CHECK(x != ev.rg8_snorm);
# endif
# ifdef GL_RG8I
	BOOST_CHECK(x != ev.rg8i);
# endif
# ifdef GL_RG8UI
	BOOST_CHECK(x != ev.rg8ui);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB10
	BOOST_CHECK(x != ev.rgb10);
# endif
# ifdef GL_RGB10_A2
	BOOST_CHECK(x != ev.rgb10_a2);
# endif
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_RG32F
	x = ev.rg32f;
	BOOST_CHECK(x == ev.rg32f);
# ifdef GL_RG32I
	BOOST_CHECK(x != ev.rg32i);
# endif
# ifdef GL_RG32UI
	BOOST_CHECK(x != ev.rg32ui);
# endif
# ifdef GL_RG8
	BOOST_CHECK(x != ev.rg8);
# endif
# ifdef GL_RG8_SNORM
	BOOST_CHECK(x != ev.rg8_snorm);
# endif
# ifdef GL_RG8I
	BOOST_CHECK(x != ev.rg8i);
# endif
# ifdef GL_RG8UI
	BOOST_CHECK(x != ev.rg8ui);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB10
	BOOST_CHECK(x != ev.rgb10);
# endif
# ifdef GL_RGB10_A2
	BOOST_CHECK(x != ev.rgb10_a2);
# endif
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_RG32I
	x = ev.rg32i;
	BOOST_CHECK(x == ev.rg32i);
# ifdef GL_RG32UI
	BOOST_CHECK(x != ev.rg32ui);
# endif
# ifdef GL_RG8
	BOOST_CHECK(x != ev.rg8);
# endif
# ifdef GL_RG8_SNORM
	BOOST_CHECK(x != ev.rg8_snorm);
# endif
# ifdef GL_RG8I
	BOOST_CHECK(x != ev.rg8i);
# endif
# ifdef GL_RG8UI
	BOOST_CHECK(x != ev.rg8ui);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB10
	BOOST_CHECK(x != ev.rgb10);
# endif
# ifdef GL_RGB10_A2
	BOOST_CHECK(x != ev.rgb10_a2);
# endif
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_RG32UI
	x = ev.rg32ui;
	BOOST_CHECK(x == ev.rg32ui);
# ifdef GL_RG8
	BOOST_CHECK(x != ev.rg8);
# endif
# ifdef GL_RG8_SNORM
	BOOST_CHECK(x != ev.rg8_snorm);
# endif
# ifdef GL_RG8I
	BOOST_CHECK(x != ev.rg8i);
# endif
# ifdef GL_RG8UI
	BOOST_CHECK(x != ev.rg8ui);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB10
	BOOST_CHECK(x != ev.rgb10);
# endif
# ifdef GL_RGB10_A2
	BOOST_CHECK(x != ev.rgb10_a2);
# endif
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_RG8
	x = ev.rg8;
	BOOST_CHECK(x == ev.rg8);
# ifdef GL_RG8_SNORM
	BOOST_CHECK(x != ev.rg8_snorm);
# endif
# ifdef GL_RG8I
	BOOST_CHECK(x != ev.rg8i);
# endif
# ifdef GL_RG8UI
	BOOST_CHECK(x != ev.rg8ui);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB10
	BOOST_CHECK(x != ev.rgb10);
# endif
# ifdef GL_RGB10_A2
	BOOST_CHECK(x != ev.rgb10_a2);
# endif
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_RG8_SNORM
	x = ev.rg8_snorm;
	BOOST_CHECK(x == ev.rg8_snorm);
# ifdef GL_RG8I
	BOOST_CHECK(x != ev.rg8i);
# endif
# ifdef GL_RG8UI
	BOOST_CHECK(x != ev.rg8ui);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB10
	BOOST_CHECK(x != ev.rgb10);
# endif
# ifdef GL_RGB10_A2
	BOOST_CHECK(x != ev.rgb10_a2);
# endif
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_RG8I
	x = ev.rg8i;
	BOOST_CHECK(x == ev.rg8i);
# ifdef GL_RG8UI
	BOOST_CHECK(x != ev.rg8ui);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB10
	BOOST_CHECK(x != ev.rgb10);
# endif
# ifdef GL_RGB10_A2
	BOOST_CHECK(x != ev.rgb10_a2);
# endif
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_RG8UI
	x = ev.rg8ui;
	BOOST_CHECK(x == ev.rg8ui);
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB10
	BOOST_CHECK(x != ev.rgb10);
# endif
# ifdef GL_RGB10_A2
	BOOST_CHECK(x != ev.rgb10_a2);
# endif
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_RGB
	x = ev.rgb;
	BOOST_CHECK(x == ev.rgb);
# ifdef GL_RGB10
	BOOST_CHECK(x != ev.rgb10);
# endif
# ifdef GL_RGB10_A2
	BOOST_CHECK(x != ev.rgb10_a2);
# endif
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_RGB10
	x = ev.rgb10;
	BOOST_CHECK(x == ev.rgb10);
# ifdef GL_RGB10_A2
	BOOST_CHECK(x != ev.rgb10_a2);
# endif
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_RGB10_A2
	x = ev.rgb10_a2;
	BOOST_CHECK(x == ev.rgb10_a2);
# ifdef GL_RGB10_A2UI
	BOOST_CHECK(x != ev.rgb10_a2ui);
# endif
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_RGB10_A2UI
	x = ev.rgb10_a2ui;
	BOOST_CHECK(x == ev.rgb10_a2ui);
# ifdef GL_RGB12
	BOOST_CHECK(x != ev.rgb12);
# endif
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_RGB12
	x = ev.rgb12;
	BOOST_CHECK(x == ev.rgb12);
# ifdef GL_RGB16
	BOOST_CHECK(x != ev.rgb16);
# endif
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_RGB16
	x = ev.rgb16;
	BOOST_CHECK(x == ev.rgb16);
# ifdef GL_RGB16_SNORM
	BOOST_CHECK(x != ev.rgb16_snorm);
# endif
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_RGB16_SNORM
	x = ev.rgb16_snorm;
	BOOST_CHECK(x == ev.rgb16_snorm);
# ifdef GL_RGB16F
	BOOST_CHECK(x != ev.rgb16f);
# endif
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_RGB16F
	x = ev.rgb16f;
	BOOST_CHECK(x == ev.rgb16f);
# ifdef GL_RGB16I
	BOOST_CHECK(x != ev.rgb16i);
# endif
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_RGB16I
	x = ev.rgb16i;
	BOOST_CHECK(x == ev.rgb16i);
# ifdef GL_RGB16UI
	BOOST_CHECK(x != ev.rgb16ui);
# endif
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_RGB16UI
	x = ev.rgb16ui;
	BOOST_CHECK(x == ev.rgb16ui);
# ifdef GL_RGB32F
	BOOST_CHECK(x != ev.rgb32f);
# endif
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_RGB32F
	x = ev.rgb32f;
	BOOST_CHECK(x == ev.rgb32f);
# ifdef GL_RGB32I
	BOOST_CHECK(x != ev.rgb32i);
# endif
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_RGB32I
	x = ev.rgb32i;
	BOOST_CHECK(x == ev.rgb32i);
# ifdef GL_RGB32UI
	BOOST_CHECK(x != ev.rgb32ui);
# endif
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_RGB32UI
	x = ev.rgb32ui;
	BOOST_CHECK(x == ev.rgb32ui);
# ifdef GL_RGB4
	BOOST_CHECK(x != ev.rgb4);
# endif
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_RGB4
	x = ev.rgb4;
	BOOST_CHECK(x == ev.rgb4);
# ifdef GL_RGB5
	BOOST_CHECK(x != ev.rgb5);
# endif
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_RGB5
	x = ev.rgb5;
	BOOST_CHECK(x == ev.rgb5);
# ifdef GL_RGB5_A1
	BOOST_CHECK(x != ev.rgb5_a1);
# endif
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_RGB5_A1
	x = ev.rgb5_a1;
	BOOST_CHECK(x == ev.rgb5_a1);
# ifdef GL_RGB8
	BOOST_CHECK(x != ev.rgb8);
# endif
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_RGB8
	x = ev.rgb8;
	BOOST_CHECK(x == ev.rgb8);
# ifdef GL_RGB8_SNORM
	BOOST_CHECK(x != ev.rgb8_snorm);
# endif
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_RGB8_SNORM
	x = ev.rgb8_snorm;
	BOOST_CHECK(x == ev.rgb8_snorm);
# ifdef GL_RGB8I
	BOOST_CHECK(x != ev.rgb8i);
# endif
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_RGB8I
	x = ev.rgb8i;
	BOOST_CHECK(x == ev.rgb8i);
# ifdef GL_RGB8UI
	BOOST_CHECK(x != ev.rgb8ui);
# endif
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_RGB8UI
	x = ev.rgb8ui;
	BOOST_CHECK(x == ev.rgb8ui);
# ifdef GL_RGB9_E5
	BOOST_CHECK(x != ev.rgb9_e5);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_RGB9_E5
	x = ev.rgb9_e5;
	BOOST_CHECK(x == ev.rgb9_e5);
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_RGBA
	x = ev.rgba;
	BOOST_CHECK(x == ev.rgba);
# ifdef GL_RGBA12
	BOOST_CHECK(x != ev.rgba12);
# endif
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_RGBA12
	x = ev.rgba12;
	BOOST_CHECK(x == ev.rgba12);
# ifdef GL_RGBA16
	BOOST_CHECK(x != ev.rgba16);
# endif
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_RGBA16
	x = ev.rgba16;
	BOOST_CHECK(x == ev.rgba16);
# ifdef GL_RGBA16_SNORM
	BOOST_CHECK(x != ev.rgba16_snorm);
# endif
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_RGBA16_SNORM
	x = ev.rgba16_snorm;
	BOOST_CHECK(x == ev.rgba16_snorm);
# ifdef GL_RGBA16F
	BOOST_CHECK(x != ev.rgba16f);
# endif
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_RGBA16F
	x = ev.rgba16f;
	BOOST_CHECK(x == ev.rgba16f);
# ifdef GL_RGBA16I
	BOOST_CHECK(x != ev.rgba16i);
# endif
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_RGBA16I
	x = ev.rgba16i;
	BOOST_CHECK(x == ev.rgba16i);
# ifdef GL_RGBA16UI
	BOOST_CHECK(x != ev.rgba16ui);
# endif
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_RGBA16UI
	x = ev.rgba16ui;
	BOOST_CHECK(x == ev.rgba16ui);
# ifdef GL_RGBA2
	BOOST_CHECK(x != ev.rgba2);
# endif
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_RGBA2
	x = ev.rgba2;
	BOOST_CHECK(x == ev.rgba2);
# ifdef GL_RGBA32F
	BOOST_CHECK(x != ev.rgba32f);
# endif
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_RGBA32F
	x = ev.rgba32f;
	BOOST_CHECK(x == ev.rgba32f);
# ifdef GL_RGBA32I
	BOOST_CHECK(x != ev.rgba32i);
# endif
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_RGBA32I
	x = ev.rgba32i;
	BOOST_CHECK(x == ev.rgba32i);
# ifdef GL_RGBA32UI
	BOOST_CHECK(x != ev.rgba32ui);
# endif
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_RGBA32UI
	x = ev.rgba32ui;
	BOOST_CHECK(x == ev.rgba32ui);
# ifdef GL_RGBA4
	BOOST_CHECK(x != ev.rgba4);
# endif
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_RGBA4
	x = ev.rgba4;
	BOOST_CHECK(x == ev.rgba4);
# ifdef GL_RGBA8
	BOOST_CHECK(x != ev.rgba8);
# endif
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_RGBA8
	x = ev.rgba8;
	BOOST_CHECK(x == ev.rgba8);
# ifdef GL_RGBA8_SNORM
	BOOST_CHECK(x != ev.rgba8_snorm);
# endif
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_RGBA8_SNORM
	x = ev.rgba8_snorm;
	BOOST_CHECK(x == ev.rgba8_snorm);
# ifdef GL_RGBA8I
	BOOST_CHECK(x != ev.rgba8i);
# endif
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_RGBA8I
	x = ev.rgba8i;
	BOOST_CHECK(x == ev.rgba8i);
# ifdef GL_RGBA8UI
	BOOST_CHECK(x != ev.rgba8ui);
# endif
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_RGBA8UI
	x = ev.rgba8ui;
	BOOST_CHECK(x == ev.rgba8ui);
# ifdef GL_SRGB8
	BOOST_CHECK(x != ev.srgb8);
# endif
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_SRGB8
	x = ev.srgb8;
	BOOST_CHECK(x == ev.srgb8);
# ifdef GL_SRGB8_ALPHA8
	BOOST_CHECK(x != ev.srgb8_alpha8);
# endif
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_SRGB8_ALPHA8
	x = ev.srgb8_alpha8;
	BOOST_CHECK(x == ev.srgb8_alpha8);
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_STENCIL_INDEX8
	x = ev.stencil_index8;
	BOOST_CHECK(x == ev.stencil_index8);
#endif
}

BOOST_AUTO_TEST_CASE(enum_pixel_data_internal_format_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	pixel_data_internal_format x;
	(void)x;

#ifdef GL_COMPRESSED_R11_EAC
	x = ev.compressed_r11_eac;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"COMPRESSED_R11_EAC"
	) == 0);
#endif

#ifdef GL_COMPRESSED_RED
	x = ev.compressed_red;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"COMPRESSED_RED"
	) == 0);
#endif

#ifdef GL_COMPRESSED_RED_RGTC1
	x = ev.compressed_red_rgtc1;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"COMPRESSED_RED_RGTC1"
	) == 0);
#endif

#ifdef GL_COMPRESSED_RG
	x = ev.compressed_rg;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"COMPRESSED_RG"
	) == 0);
#endif

#ifdef GL_COMPRESSED_RG11_EAC
	x = ev.compressed_rg11_eac;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"COMPRESSED_RG11_EAC"
	) == 0);
#endif

#ifdef GL_COMPRESSED_RG_RGTC2
	x = ev.compressed_rg_rgtc2;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"COMPRESSED_RG_RGTC2"
	) == 0);
#endif

#ifdef GL_COMPRESSED_RGB
	x = ev.compressed_rgb;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"COMPRESSED_RGB"
	) == 0);
#endif

#ifdef GL_COMPRESSED_RGB8_ETC2
	x = ev.compressed_rgb8_etc2;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"COMPRESSED_RGB8_ETC2"
	) == 0);
#endif

#ifdef GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2
	x = ev.compressed_rgb8_punchthrough_alpha1_etc2;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2"
	) == 0);
#endif

#ifdef GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT
	x = ev.compressed_rgb_bptc_signed_float;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"COMPRESSED_RGB_BPTC_SIGNED_FLOAT"
	) == 0);
#endif

#ifdef GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT
	x = ev.compressed_rgb_bptc_unsigned_float;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT"
	) == 0);
#endif

#ifdef GL_COMPRESSED_RGBA
	x = ev.compressed_rgba;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"COMPRESSED_RGBA"
	) == 0);
#endif

#ifdef GL_COMPRESSED_RGBA8_ETC2_EAC
	x = ev.compressed_rgba8_etc2_eac;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"COMPRESSED_RGBA8_ETC2_EAC"
	) == 0);
#endif

#ifdef GL_COMPRESSED_RGBA_BPTC_UNORM
	x = ev.compressed_rgba_bptc_unorm;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"COMPRESSED_RGBA_BPTC_UNORM"
	) == 0);
#endif

#ifdef GL_COMPRESSED_SIGNED_R11_EAC
	x = ev.compressed_signed_r11_eac;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"COMPRESSED_SIGNED_R11_EAC"
	) == 0);
#endif

#ifdef GL_COMPRESSED_SIGNED_RED_RGTC1
	x = ev.compressed_signed_red_rgtc1;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"COMPRESSED_SIGNED_RED_RGTC1"
	) == 0);
#endif

#ifdef GL_COMPRESSED_SIGNED_RG11_EAC
	x = ev.compressed_signed_rg11_eac;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"COMPRESSED_SIGNED_RG11_EAC"
	) == 0);
#endif

#ifdef GL_COMPRESSED_SIGNED_RG_RGTC2
	x = ev.compressed_signed_rg_rgtc2;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"COMPRESSED_SIGNED_RG_RGTC2"
	) == 0);
#endif

#ifdef GL_COMPRESSED_SRGB
	x = ev.compressed_srgb;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"COMPRESSED_SRGB"
	) == 0);
#endif

#ifdef GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC
	x = ev.compressed_srgb8_alpha8_etc2_eac;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"COMPRESSED_SRGB8_ALPHA8_ETC2_EAC"
	) == 0);
#endif

#ifdef GL_COMPRESSED_SRGB8_ETC2
	x = ev.compressed_srgb8_etc2;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"COMPRESSED_SRGB8_ETC2"
	) == 0);
#endif

#ifdef GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2
	x = ev.compressed_srgb8_punchthrough_alpha1_etc2;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2"
	) == 0);
#endif

#ifdef GL_COMPRESSED_SRGB_ALPHA
	x = ev.compressed_srgb_alpha;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"COMPRESSED_SRGB_ALPHA"
	) == 0);
#endif

#ifdef GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM
	x = ev.compressed_srgb_alpha_bptc_unorm;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"COMPRESSED_SRGB_ALPHA_BPTC_UNORM"
	) == 0);
#endif

#ifdef GL_DEPTH24_STENCIL8
	x = ev.depth24_stencil8;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DEPTH24_STENCIL8"
	) == 0);
#endif

#ifdef GL_DEPTH32F_STENCIL8
	x = ev.depth32f_stencil8;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DEPTH32F_STENCIL8"
	) == 0);
#endif

#ifdef GL_DEPTH_COMPONENT
	x = ev.depth_component;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DEPTH_COMPONENT"
	) == 0);
#endif

#ifdef GL_DEPTH_COMPONENT16
	x = ev.depth_component16;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DEPTH_COMPONENT16"
	) == 0);
#endif

#ifdef GL_DEPTH_COMPONENT24
	x = ev.depth_component24;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DEPTH_COMPONENT24"
	) == 0);
#endif

#ifdef GL_DEPTH_COMPONENT32
	x = ev.depth_component32;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DEPTH_COMPONENT32"
	) == 0);
#endif

#ifdef GL_DEPTH_COMPONENT32F
	x = ev.depth_component32f;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DEPTH_COMPONENT32F"
	) == 0);
#endif

#ifdef GL_DEPTH_STENCIL
	x = ev.depth_stencil;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DEPTH_STENCIL"
	) == 0);
#endif

#ifdef GL_R11F_G11F_B10F
	x = ev.r11f_g11f_b10f;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"R11F_G11F_B10F"
	) == 0);
#endif

#ifdef GL_R16
	x = ev.r16;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"R16"
	) == 0);
#endif

#ifdef GL_R16_SNORM
	x = ev.r16_snorm;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"R16_SNORM"
	) == 0);
#endif

#ifdef GL_R16F
	x = ev.r16f;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"R16F"
	) == 0);
#endif

#ifdef GL_R16I
	x = ev.r16i;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"R16I"
	) == 0);
#endif

#ifdef GL_R16UI
	x = ev.r16ui;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"R16UI"
	) == 0);
#endif

#ifdef GL_R32F
	x = ev.r32f;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"R32F"
	) == 0);
#endif

#ifdef GL_R32I
	x = ev.r32i;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"R32I"
	) == 0);
#endif

#ifdef GL_R32UI
	x = ev.r32ui;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"R32UI"
	) == 0);
#endif

#ifdef GL_R3_G3_B2
	x = ev.r3_g3_b2;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"R3_G3_B2"
	) == 0);
#endif

#ifdef GL_R8
	x = ev.r8;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"R8"
	) == 0);
#endif

#ifdef GL_R8_SNORM
	x = ev.r8_snorm;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"R8_SNORM"
	) == 0);
#endif

#ifdef GL_R8I
	x = ev.r8i;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"R8I"
	) == 0);
#endif

#ifdef GL_R8UI
	x = ev.r8ui;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"R8UI"
	) == 0);
#endif

#ifdef GL_RED
	x = ev.red;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RED"
	) == 0);
#endif

#ifdef GL_RG
	x = ev.rg;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RG"
	) == 0);
#endif

#ifdef GL_RG16
	x = ev.rg16;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RG16"
	) == 0);
#endif

#ifdef GL_RG16_SNORM
	x = ev.rg16_snorm;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RG16_SNORM"
	) == 0);
#endif

#ifdef GL_RG16F
	x = ev.rg16f;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RG16F"
	) == 0);
#endif

#ifdef GL_RG16I
	x = ev.rg16i;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RG16I"
	) == 0);
#endif

#ifdef GL_RG16UI
	x = ev.rg16ui;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RG16UI"
	) == 0);
#endif

#ifdef GL_RG32F
	x = ev.rg32f;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RG32F"
	) == 0);
#endif

#ifdef GL_RG32I
	x = ev.rg32i;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RG32I"
	) == 0);
#endif

#ifdef GL_RG32UI
	x = ev.rg32ui;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RG32UI"
	) == 0);
#endif

#ifdef GL_RG8
	x = ev.rg8;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RG8"
	) == 0);
#endif

#ifdef GL_RG8_SNORM
	x = ev.rg8_snorm;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RG8_SNORM"
	) == 0);
#endif

#ifdef GL_RG8I
	x = ev.rg8i;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RG8I"
	) == 0);
#endif

#ifdef GL_RG8UI
	x = ev.rg8ui;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RG8UI"
	) == 0);
#endif

#ifdef GL_RGB
	x = ev.rgb;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RGB"
	) == 0);
#endif

#ifdef GL_RGB10
	x = ev.rgb10;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RGB10"
	) == 0);
#endif

#ifdef GL_RGB10_A2
	x = ev.rgb10_a2;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RGB10_A2"
	) == 0);
#endif

#ifdef GL_RGB10_A2UI
	x = ev.rgb10_a2ui;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RGB10_A2UI"
	) == 0);
#endif

#ifdef GL_RGB12
	x = ev.rgb12;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RGB12"
	) == 0);
#endif

#ifdef GL_RGB16
	x = ev.rgb16;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RGB16"
	) == 0);
#endif

#ifdef GL_RGB16_SNORM
	x = ev.rgb16_snorm;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RGB16_SNORM"
	) == 0);
#endif

#ifdef GL_RGB16F
	x = ev.rgb16f;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RGB16F"
	) == 0);
#endif

#ifdef GL_RGB16I
	x = ev.rgb16i;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RGB16I"
	) == 0);
#endif

#ifdef GL_RGB16UI
	x = ev.rgb16ui;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RGB16UI"
	) == 0);
#endif

#ifdef GL_RGB32F
	x = ev.rgb32f;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RGB32F"
	) == 0);
#endif

#ifdef GL_RGB32I
	x = ev.rgb32i;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RGB32I"
	) == 0);
#endif

#ifdef GL_RGB32UI
	x = ev.rgb32ui;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RGB32UI"
	) == 0);
#endif

#ifdef GL_RGB4
	x = ev.rgb4;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RGB4"
	) == 0);
#endif

#ifdef GL_RGB5
	x = ev.rgb5;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RGB5"
	) == 0);
#endif

#ifdef GL_RGB5_A1
	x = ev.rgb5_a1;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RGB5_A1"
	) == 0);
#endif

#ifdef GL_RGB8
	x = ev.rgb8;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RGB8"
	) == 0);
#endif

#ifdef GL_RGB8_SNORM
	x = ev.rgb8_snorm;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RGB8_SNORM"
	) == 0);
#endif

#ifdef GL_RGB8I
	x = ev.rgb8i;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RGB8I"
	) == 0);
#endif

#ifdef GL_RGB8UI
	x = ev.rgb8ui;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RGB8UI"
	) == 0);
#endif

#ifdef GL_RGB9_E5
	x = ev.rgb9_e5;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RGB9_E5"
	) == 0);
#endif

#ifdef GL_RGBA
	x = ev.rgba;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RGBA"
	) == 0);
#endif

#ifdef GL_RGBA12
	x = ev.rgba12;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RGBA12"
	) == 0);
#endif

#ifdef GL_RGBA16
	x = ev.rgba16;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RGBA16"
	) == 0);
#endif

#ifdef GL_RGBA16_SNORM
	x = ev.rgba16_snorm;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RGBA16_SNORM"
	) == 0);
#endif

#ifdef GL_RGBA16F
	x = ev.rgba16f;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RGBA16F"
	) == 0);
#endif

#ifdef GL_RGBA16I
	x = ev.rgba16i;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RGBA16I"
	) == 0);
#endif

#ifdef GL_RGBA16UI
	x = ev.rgba16ui;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RGBA16UI"
	) == 0);
#endif

#ifdef GL_RGBA2
	x = ev.rgba2;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RGBA2"
	) == 0);
#endif

#ifdef GL_RGBA32F
	x = ev.rgba32f;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RGBA32F"
	) == 0);
#endif

#ifdef GL_RGBA32I
	x = ev.rgba32i;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RGBA32I"
	) == 0);
#endif

#ifdef GL_RGBA32UI
	x = ev.rgba32ui;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RGBA32UI"
	) == 0);
#endif

#ifdef GL_RGBA4
	x = ev.rgba4;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RGBA4"
	) == 0);
#endif

#ifdef GL_RGBA8
	x = ev.rgba8;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RGBA8"
	) == 0);
#endif

#ifdef GL_RGBA8_SNORM
	x = ev.rgba8_snorm;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RGBA8_SNORM"
	) == 0);
#endif

#ifdef GL_RGBA8I
	x = ev.rgba8i;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RGBA8I"
	) == 0);
#endif

#ifdef GL_RGBA8UI
	x = ev.rgba8ui;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RGBA8UI"
	) == 0);
#endif

#ifdef GL_SRGB8
	x = ev.srgb8;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SRGB8"
	) == 0);
#endif

#ifdef GL_SRGB8_ALPHA8
	x = ev.srgb8_alpha8;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SRGB8_ALPHA8"
	) == 0);
#endif

#ifdef GL_STENCIL_INDEX8
	x = ev.stencil_index8;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"STENCIL_INDEX8"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_pixel_data_internal_format_range)
{
	using namespace oglplus;
	auto count = enum_value_range<pixel_data_internal_format>().size();

#ifdef GL_COMPRESSED_R11_EAC
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_COMPRESSED_R11_EAC)
	) != r.end());
}
#endif

#ifdef GL_COMPRESSED_RED
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_COMPRESSED_RED)
	) != r.end());
}
#endif

#ifdef GL_COMPRESSED_RED_RGTC1
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_COMPRESSED_RED_RGTC1)
	) != r.end());
}
#endif

#ifdef GL_COMPRESSED_RG
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_COMPRESSED_RG)
	) != r.end());
}
#endif

#ifdef GL_COMPRESSED_RG11_EAC
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_COMPRESSED_RG11_EAC)
	) != r.end());
}
#endif

#ifdef GL_COMPRESSED_RG_RGTC2
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_COMPRESSED_RG_RGTC2)
	) != r.end());
}
#endif

#ifdef GL_COMPRESSED_RGB
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_COMPRESSED_RGB)
	) != r.end());
}
#endif

#ifdef GL_COMPRESSED_RGB8_ETC2
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_COMPRESSED_RGB8_ETC2)
	) != r.end());
}
#endif

#ifdef GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2)
	) != r.end());
}
#endif

#ifdef GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT)
	) != r.end());
}
#endif

#ifdef GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT)
	) != r.end());
}
#endif

#ifdef GL_COMPRESSED_RGBA
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_COMPRESSED_RGBA)
	) != r.end());
}
#endif

#ifdef GL_COMPRESSED_RGBA8_ETC2_EAC
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_COMPRESSED_RGBA8_ETC2_EAC)
	) != r.end());
}
#endif

#ifdef GL_COMPRESSED_RGBA_BPTC_UNORM
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_COMPRESSED_RGBA_BPTC_UNORM)
	) != r.end());
}
#endif

#ifdef GL_COMPRESSED_SIGNED_R11_EAC
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_COMPRESSED_SIGNED_R11_EAC)
	) != r.end());
}
#endif

#ifdef GL_COMPRESSED_SIGNED_RED_RGTC1
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_COMPRESSED_SIGNED_RED_RGTC1)
	) != r.end());
}
#endif

#ifdef GL_COMPRESSED_SIGNED_RG11_EAC
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_COMPRESSED_SIGNED_RG11_EAC)
	) != r.end());
}
#endif

#ifdef GL_COMPRESSED_SIGNED_RG_RGTC2
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_COMPRESSED_SIGNED_RG_RGTC2)
	) != r.end());
}
#endif

#ifdef GL_COMPRESSED_SRGB
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_COMPRESSED_SRGB)
	) != r.end());
}
#endif

#ifdef GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC)
	) != r.end());
}
#endif

#ifdef GL_COMPRESSED_SRGB8_ETC2
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_COMPRESSED_SRGB8_ETC2)
	) != r.end());
}
#endif

#ifdef GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2)
	) != r.end());
}
#endif

#ifdef GL_COMPRESSED_SRGB_ALPHA
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_COMPRESSED_SRGB_ALPHA)
	) != r.end());
}
#endif

#ifdef GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM)
	) != r.end());
}
#endif

#ifdef GL_DEPTH24_STENCIL8
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_DEPTH24_STENCIL8)
	) != r.end());
}
#endif

#ifdef GL_DEPTH32F_STENCIL8
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_DEPTH32F_STENCIL8)
	) != r.end());
}
#endif

#ifdef GL_DEPTH_COMPONENT
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_DEPTH_COMPONENT)
	) != r.end());
}
#endif

#ifdef GL_DEPTH_COMPONENT16
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_DEPTH_COMPONENT16)
	) != r.end());
}
#endif

#ifdef GL_DEPTH_COMPONENT24
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_DEPTH_COMPONENT24)
	) != r.end());
}
#endif

#ifdef GL_DEPTH_COMPONENT32
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_DEPTH_COMPONENT32)
	) != r.end());
}
#endif

#ifdef GL_DEPTH_COMPONENT32F
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_DEPTH_COMPONENT32F)
	) != r.end());
}
#endif

#ifdef GL_DEPTH_STENCIL
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_DEPTH_STENCIL)
	) != r.end());
}
#endif

#ifdef GL_R11F_G11F_B10F
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_R11F_G11F_B10F)
	) != r.end());
}
#endif

#ifdef GL_R16
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_R16)
	) != r.end());
}
#endif

#ifdef GL_R16_SNORM
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_R16_SNORM)
	) != r.end());
}
#endif

#ifdef GL_R16F
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_R16F)
	) != r.end());
}
#endif

#ifdef GL_R16I
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_R16I)
	) != r.end());
}
#endif

#ifdef GL_R16UI
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_R16UI)
	) != r.end());
}
#endif

#ifdef GL_R32F
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_R32F)
	) != r.end());
}
#endif

#ifdef GL_R32I
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_R32I)
	) != r.end());
}
#endif

#ifdef GL_R32UI
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_R32UI)
	) != r.end());
}
#endif

#ifdef GL_R3_G3_B2
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_R3_G3_B2)
	) != r.end());
}
#endif

#ifdef GL_R8
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_R8)
	) != r.end());
}
#endif

#ifdef GL_R8_SNORM
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_R8_SNORM)
	) != r.end());
}
#endif

#ifdef GL_R8I
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_R8I)
	) != r.end());
}
#endif

#ifdef GL_R8UI
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_R8UI)
	) != r.end());
}
#endif

#ifdef GL_RED
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_RED)
	) != r.end());
}
#endif

#ifdef GL_RG
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_RG)
	) != r.end());
}
#endif

#ifdef GL_RG16
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_RG16)
	) != r.end());
}
#endif

#ifdef GL_RG16_SNORM
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_RG16_SNORM)
	) != r.end());
}
#endif

#ifdef GL_RG16F
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_RG16F)
	) != r.end());
}
#endif

#ifdef GL_RG16I
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_RG16I)
	) != r.end());
}
#endif

#ifdef GL_RG16UI
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_RG16UI)
	) != r.end());
}
#endif

#ifdef GL_RG32F
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_RG32F)
	) != r.end());
}
#endif

#ifdef GL_RG32I
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_RG32I)
	) != r.end());
}
#endif

#ifdef GL_RG32UI
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_RG32UI)
	) != r.end());
}
#endif

#ifdef GL_RG8
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_RG8)
	) != r.end());
}
#endif

#ifdef GL_RG8_SNORM
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_RG8_SNORM)
	) != r.end());
}
#endif

#ifdef GL_RG8I
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_RG8I)
	) != r.end());
}
#endif

#ifdef GL_RG8UI
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_RG8UI)
	) != r.end());
}
#endif

#ifdef GL_RGB
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_RGB)
	) != r.end());
}
#endif

#ifdef GL_RGB10
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_RGB10)
	) != r.end());
}
#endif

#ifdef GL_RGB10_A2
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_RGB10_A2)
	) != r.end());
}
#endif

#ifdef GL_RGB10_A2UI
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_RGB10_A2UI)
	) != r.end());
}
#endif

#ifdef GL_RGB12
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_RGB12)
	) != r.end());
}
#endif

#ifdef GL_RGB16
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_RGB16)
	) != r.end());
}
#endif

#ifdef GL_RGB16_SNORM
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_RGB16_SNORM)
	) != r.end());
}
#endif

#ifdef GL_RGB16F
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_RGB16F)
	) != r.end());
}
#endif

#ifdef GL_RGB16I
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_RGB16I)
	) != r.end());
}
#endif

#ifdef GL_RGB16UI
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_RGB16UI)
	) != r.end());
}
#endif

#ifdef GL_RGB32F
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_RGB32F)
	) != r.end());
}
#endif

#ifdef GL_RGB32I
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_RGB32I)
	) != r.end());
}
#endif

#ifdef GL_RGB32UI
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_RGB32UI)
	) != r.end());
}
#endif

#ifdef GL_RGB4
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_RGB4)
	) != r.end());
}
#endif

#ifdef GL_RGB5
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_RGB5)
	) != r.end());
}
#endif

#ifdef GL_RGB5_A1
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_RGB5_A1)
	) != r.end());
}
#endif

#ifdef GL_RGB8
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_RGB8)
	) != r.end());
}
#endif

#ifdef GL_RGB8_SNORM
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_RGB8_SNORM)
	) != r.end());
}
#endif

#ifdef GL_RGB8I
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_RGB8I)
	) != r.end());
}
#endif

#ifdef GL_RGB8UI
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_RGB8UI)
	) != r.end());
}
#endif

#ifdef GL_RGB9_E5
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_RGB9_E5)
	) != r.end());
}
#endif

#ifdef GL_RGBA
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_RGBA)
	) != r.end());
}
#endif

#ifdef GL_RGBA12
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_RGBA12)
	) != r.end());
}
#endif

#ifdef GL_RGBA16
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_RGBA16)
	) != r.end());
}
#endif

#ifdef GL_RGBA16_SNORM
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_RGBA16_SNORM)
	) != r.end());
}
#endif

#ifdef GL_RGBA16F
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_RGBA16F)
	) != r.end());
}
#endif

#ifdef GL_RGBA16I
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_RGBA16I)
	) != r.end());
}
#endif

#ifdef GL_RGBA16UI
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_RGBA16UI)
	) != r.end());
}
#endif

#ifdef GL_RGBA2
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_RGBA2)
	) != r.end());
}
#endif

#ifdef GL_RGBA32F
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_RGBA32F)
	) != r.end());
}
#endif

#ifdef GL_RGBA32I
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_RGBA32I)
	) != r.end());
}
#endif

#ifdef GL_RGBA32UI
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_RGBA32UI)
	) != r.end());
}
#endif

#ifdef GL_RGBA4
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_RGBA4)
	) != r.end());
}
#endif

#ifdef GL_RGBA8
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_RGBA8)
	) != r.end());
}
#endif

#ifdef GL_RGBA8_SNORM
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_RGBA8_SNORM)
	) != r.end());
}
#endif

#ifdef GL_RGBA8I
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_RGBA8I)
	) != r.end());
}
#endif

#ifdef GL_RGBA8UI
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_RGBA8UI)
	) != r.end());
}
#endif

#ifdef GL_SRGB8
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_SRGB8)
	) != r.end());
}
#endif

#ifdef GL_SRGB8_ALPHA8
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_SRGB8_ALPHA8)
	) != r.end());
}
#endif

#ifdef GL_STENCIL_INDEX8
{
	--count;
	auto r = enum_value_range<pixel_data_internal_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_internal_format(GL_STENCIL_INDEX8)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_pixel_data_internal_format_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	pixel_data_internal_format x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_COMPRESSED_R11_EAC
	x = ev.compressed_r11_eac;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.compressed_r11_eac);
#endif

#ifdef GL_COMPRESSED_RED
	x = ev.compressed_red;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.compressed_red);
#endif

#ifdef GL_COMPRESSED_RED_RGTC1
	x = ev.compressed_red_rgtc1;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.compressed_red_rgtc1);
#endif

#ifdef GL_COMPRESSED_RG
	x = ev.compressed_rg;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.compressed_rg);
#endif

#ifdef GL_COMPRESSED_RG11_EAC
	x = ev.compressed_rg11_eac;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.compressed_rg11_eac);
#endif

#ifdef GL_COMPRESSED_RG_RGTC2
	x = ev.compressed_rg_rgtc2;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.compressed_rg_rgtc2);
#endif

#ifdef GL_COMPRESSED_RGB
	x = ev.compressed_rgb;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.compressed_rgb);
#endif

#ifdef GL_COMPRESSED_RGB8_ETC2
	x = ev.compressed_rgb8_etc2;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.compressed_rgb8_etc2);
#endif

#ifdef GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2
	x = ev.compressed_rgb8_punchthrough_alpha1_etc2;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.compressed_rgb8_punchthrough_alpha1_etc2);
#endif

#ifdef GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT
	x = ev.compressed_rgb_bptc_signed_float;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.compressed_rgb_bptc_signed_float);
#endif

#ifdef GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT
	x = ev.compressed_rgb_bptc_unsigned_float;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.compressed_rgb_bptc_unsigned_float);
#endif

#ifdef GL_COMPRESSED_RGBA
	x = ev.compressed_rgba;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.compressed_rgba);
#endif

#ifdef GL_COMPRESSED_RGBA8_ETC2_EAC
	x = ev.compressed_rgba8_etc2_eac;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.compressed_rgba8_etc2_eac);
#endif

#ifdef GL_COMPRESSED_RGBA_BPTC_UNORM
	x = ev.compressed_rgba_bptc_unorm;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.compressed_rgba_bptc_unorm);
#endif

#ifdef GL_COMPRESSED_SIGNED_R11_EAC
	x = ev.compressed_signed_r11_eac;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.compressed_signed_r11_eac);
#endif

#ifdef GL_COMPRESSED_SIGNED_RED_RGTC1
	x = ev.compressed_signed_red_rgtc1;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.compressed_signed_red_rgtc1);
#endif

#ifdef GL_COMPRESSED_SIGNED_RG11_EAC
	x = ev.compressed_signed_rg11_eac;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.compressed_signed_rg11_eac);
#endif

#ifdef GL_COMPRESSED_SIGNED_RG_RGTC2
	x = ev.compressed_signed_rg_rgtc2;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.compressed_signed_rg_rgtc2);
#endif

#ifdef GL_COMPRESSED_SRGB
	x = ev.compressed_srgb;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.compressed_srgb);
#endif

#ifdef GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC
	x = ev.compressed_srgb8_alpha8_etc2_eac;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.compressed_srgb8_alpha8_etc2_eac);
#endif

#ifdef GL_COMPRESSED_SRGB8_ETC2
	x = ev.compressed_srgb8_etc2;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.compressed_srgb8_etc2);
#endif

#ifdef GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2
	x = ev.compressed_srgb8_punchthrough_alpha1_etc2;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.compressed_srgb8_punchthrough_alpha1_etc2);
#endif

#ifdef GL_COMPRESSED_SRGB_ALPHA
	x = ev.compressed_srgb_alpha;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.compressed_srgb_alpha);
#endif

#ifdef GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM
	x = ev.compressed_srgb_alpha_bptc_unorm;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.compressed_srgb_alpha_bptc_unorm);
#endif

#ifdef GL_DEPTH24_STENCIL8
	x = ev.depth24_stencil8;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.depth24_stencil8);
#endif

#ifdef GL_DEPTH32F_STENCIL8
	x = ev.depth32f_stencil8;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.depth32f_stencil8);
#endif

#ifdef GL_DEPTH_COMPONENT
	x = ev.depth_component;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.depth_component);
#endif

#ifdef GL_DEPTH_COMPONENT16
	x = ev.depth_component16;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.depth_component16);
#endif

#ifdef GL_DEPTH_COMPONENT24
	x = ev.depth_component24;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.depth_component24);
#endif

#ifdef GL_DEPTH_COMPONENT32
	x = ev.depth_component32;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.depth_component32);
#endif

#ifdef GL_DEPTH_COMPONENT32F
	x = ev.depth_component32f;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.depth_component32f);
#endif

#ifdef GL_DEPTH_STENCIL
	x = ev.depth_stencil;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.depth_stencil);
#endif

#ifdef GL_R11F_G11F_B10F
	x = ev.r11f_g11f_b10f;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.r11f_g11f_b10f);
#endif

#ifdef GL_R16
	x = ev.r16;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.r16);
#endif

#ifdef GL_R16_SNORM
	x = ev.r16_snorm;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.r16_snorm);
#endif

#ifdef GL_R16F
	x = ev.r16f;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.r16f);
#endif

#ifdef GL_R16I
	x = ev.r16i;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.r16i);
#endif

#ifdef GL_R16UI
	x = ev.r16ui;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.r16ui);
#endif

#ifdef GL_R32F
	x = ev.r32f;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.r32f);
#endif

#ifdef GL_R32I
	x = ev.r32i;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.r32i);
#endif

#ifdef GL_R32UI
	x = ev.r32ui;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.r32ui);
#endif

#ifdef GL_R3_G3_B2
	x = ev.r3_g3_b2;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.r3_g3_b2);
#endif

#ifdef GL_R8
	x = ev.r8;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.r8);
#endif

#ifdef GL_R8_SNORM
	x = ev.r8_snorm;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.r8_snorm);
#endif

#ifdef GL_R8I
	x = ev.r8i;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.r8i);
#endif

#ifdef GL_R8UI
	x = ev.r8ui;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.r8ui);
#endif

#ifdef GL_RED
	x = ev.red;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.red);
#endif

#ifdef GL_RG
	x = ev.rg;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.rg);
#endif

#ifdef GL_RG16
	x = ev.rg16;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.rg16);
#endif

#ifdef GL_RG16_SNORM
	x = ev.rg16_snorm;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.rg16_snorm);
#endif

#ifdef GL_RG16F
	x = ev.rg16f;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.rg16f);
#endif

#ifdef GL_RG16I
	x = ev.rg16i;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.rg16i);
#endif

#ifdef GL_RG16UI
	x = ev.rg16ui;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.rg16ui);
#endif

#ifdef GL_RG32F
	x = ev.rg32f;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.rg32f);
#endif

#ifdef GL_RG32I
	x = ev.rg32i;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.rg32i);
#endif

#ifdef GL_RG32UI
	x = ev.rg32ui;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.rg32ui);
#endif

#ifdef GL_RG8
	x = ev.rg8;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.rg8);
#endif

#ifdef GL_RG8_SNORM
	x = ev.rg8_snorm;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.rg8_snorm);
#endif

#ifdef GL_RG8I
	x = ev.rg8i;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.rg8i);
#endif

#ifdef GL_RG8UI
	x = ev.rg8ui;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.rg8ui);
#endif

#ifdef GL_RGB
	x = ev.rgb;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.rgb);
#endif

#ifdef GL_RGB10
	x = ev.rgb10;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.rgb10);
#endif

#ifdef GL_RGB10_A2
	x = ev.rgb10_a2;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.rgb10_a2);
#endif

#ifdef GL_RGB10_A2UI
	x = ev.rgb10_a2ui;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.rgb10_a2ui);
#endif

#ifdef GL_RGB12
	x = ev.rgb12;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.rgb12);
#endif

#ifdef GL_RGB16
	x = ev.rgb16;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.rgb16);
#endif

#ifdef GL_RGB16_SNORM
	x = ev.rgb16_snorm;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.rgb16_snorm);
#endif

#ifdef GL_RGB16F
	x = ev.rgb16f;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.rgb16f);
#endif

#ifdef GL_RGB16I
	x = ev.rgb16i;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.rgb16i);
#endif

#ifdef GL_RGB16UI
	x = ev.rgb16ui;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.rgb16ui);
#endif

#ifdef GL_RGB32F
	x = ev.rgb32f;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.rgb32f);
#endif

#ifdef GL_RGB32I
	x = ev.rgb32i;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.rgb32i);
#endif

#ifdef GL_RGB32UI
	x = ev.rgb32ui;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.rgb32ui);
#endif

#ifdef GL_RGB4
	x = ev.rgb4;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.rgb4);
#endif

#ifdef GL_RGB5
	x = ev.rgb5;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.rgb5);
#endif

#ifdef GL_RGB5_A1
	x = ev.rgb5_a1;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.rgb5_a1);
#endif

#ifdef GL_RGB8
	x = ev.rgb8;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.rgb8);
#endif

#ifdef GL_RGB8_SNORM
	x = ev.rgb8_snorm;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.rgb8_snorm);
#endif

#ifdef GL_RGB8I
	x = ev.rgb8i;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.rgb8i);
#endif

#ifdef GL_RGB8UI
	x = ev.rgb8ui;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.rgb8ui);
#endif

#ifdef GL_RGB9_E5
	x = ev.rgb9_e5;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.rgb9_e5);
#endif

#ifdef GL_RGBA
	x = ev.rgba;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.rgba);
#endif

#ifdef GL_RGBA12
	x = ev.rgba12;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.rgba12);
#endif

#ifdef GL_RGBA16
	x = ev.rgba16;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.rgba16);
#endif

#ifdef GL_RGBA16_SNORM
	x = ev.rgba16_snorm;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.rgba16_snorm);
#endif

#ifdef GL_RGBA16F
	x = ev.rgba16f;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.rgba16f);
#endif

#ifdef GL_RGBA16I
	x = ev.rgba16i;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.rgba16i);
#endif

#ifdef GL_RGBA16UI
	x = ev.rgba16ui;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.rgba16ui);
#endif

#ifdef GL_RGBA2
	x = ev.rgba2;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.rgba2);
#endif

#ifdef GL_RGBA32F
	x = ev.rgba32f;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.rgba32f);
#endif

#ifdef GL_RGBA32I
	x = ev.rgba32i;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.rgba32i);
#endif

#ifdef GL_RGBA32UI
	x = ev.rgba32ui;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.rgba32ui);
#endif

#ifdef GL_RGBA4
	x = ev.rgba4;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.rgba4);
#endif

#ifdef GL_RGBA8
	x = ev.rgba8;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.rgba8);
#endif

#ifdef GL_RGBA8_SNORM
	x = ev.rgba8_snorm;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.rgba8_snorm);
#endif

#ifdef GL_RGBA8I
	x = ev.rgba8i;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.rgba8i);
#endif

#ifdef GL_RGBA8UI
	x = ev.rgba8ui;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.rgba8ui);
#endif

#ifdef GL_SRGB8
	x = ev.srgb8;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.srgb8);
#endif

#ifdef GL_SRGB8_ALPHA8
	x = ev.srgb8_alpha8;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.srgb8_alpha8);
#endif

#ifdef GL_STENCIL_INDEX8
	x = ev.stencil_index8;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.stencil_index8);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
