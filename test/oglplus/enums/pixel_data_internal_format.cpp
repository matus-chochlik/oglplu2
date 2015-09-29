//  File test/oglplus/enums/pixel_data_internal_format.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_pixel_data_internal_format

#include <boost/test/unit_test.hpp>
#include "common.hpp"

BOOST_AUTO_TEST_SUITE(enum_pixel_data_internal_format)

BOOST_AUTO_TEST_CASE(enum_pixel_data_internal_format_values)
{
	using namespace oglplus;
	enum_values ev;
	pixel_data_internal_format x;

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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
# ifdef GL_COMPRESSED_RED
	BOOST_CHECK(x != ev.compressed_red);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
# ifdef GL_COMPRESSED_RED
	BOOST_CHECK(x != ev.compressed_red);
# endif
# ifdef GL_COMPRESSED_RED_RGTC1
	BOOST_CHECK(x != ev.compressed_red_rgtc1);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
# ifdef GL_COMPRESSED_RED
	BOOST_CHECK(x != ev.compressed_red);
# endif
# ifdef GL_COMPRESSED_RED_RGTC1
	BOOST_CHECK(x != ev.compressed_red_rgtc1);
# endif
# ifdef GL_COMPRESSED_RG
	BOOST_CHECK(x != ev.compressed_rg);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
	BOOST_CHECK(x == ev.srgb8_alpha8);
# ifdef GL_STENCIL_INDEX8
	BOOST_CHECK(x != ev.stencil_index8);
# endif
#endif

#ifdef GL_STENCIL_INDEX8
	x = ev.stencil_index8;
# ifdef GL_COMPRESSED_R11_EAC
	BOOST_CHECK(x != ev.compressed_r11_eac);
# endif
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
	BOOST_CHECK(x == ev.stencil_index8);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
