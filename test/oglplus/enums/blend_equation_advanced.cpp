//  File test/oglplus/enums/blend_equation_advanced.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_blend_equation_advanced

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_blend_equation_advanced)

BOOST_AUTO_TEST_CASE(enum_blend_equation_advanced_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	blend_equation_advanced x;
	(void)x;

#ifdef GL_COLORBURN_KHR
	x = ev.colorburn_khr;
	BOOST_CHECK(x == ev.colorburn_khr);
# ifdef GL_COLORDODGE_KHR
	BOOST_CHECK(x != ev.colordodge_khr);
# endif
# ifdef GL_DARKEN_KHR
	BOOST_CHECK(x != ev.darken_khr);
# endif
# ifdef GL_DIFFERENCE_KHR
	BOOST_CHECK(x != ev.difference_khr);
# endif
# ifdef GL_EXCLUSION_KHR
	BOOST_CHECK(x != ev.exclusion_khr);
# endif
# ifdef GL_HARDLIGHT_KHR
	BOOST_CHECK(x != ev.hardlight_khr);
# endif
# ifdef GL_HSL_COLOR_KHR
	BOOST_CHECK(x != ev.hsl_color_khr);
# endif
# ifdef GL_HSL_HUE_KHR
	BOOST_CHECK(x != ev.hsl_hue_khr);
# endif
# ifdef GL_HSL_LUMINOSITY_KHR
	BOOST_CHECK(x != ev.hsl_luminosity_khr);
# endif
# ifdef GL_HSL_SATURATION_KHR
	BOOST_CHECK(x != ev.hsl_saturation_khr);
# endif
# ifdef GL_LIGHTEN_KHR
	BOOST_CHECK(x != ev.lighten_khr);
# endif
# ifdef GL_MULTIPLY_KHR
	BOOST_CHECK(x != ev.multiply_khr);
# endif
# ifdef GL_OVERLAY_KHR
	BOOST_CHECK(x != ev.overlay_khr);
# endif
# ifdef GL_SCREEN_KHR
	BOOST_CHECK(x != ev.screen_khr);
# endif
# ifdef GL_SOFTLIGHT_KHR
	BOOST_CHECK(x != ev.softlight_khr);
# endif
#endif

#ifdef GL_COLORDODGE_KHR
	x = ev.colordodge_khr;
# ifdef GL_COLORBURN_KHR
	BOOST_CHECK(x != ev.colorburn_khr);
# endif
	BOOST_CHECK(x == ev.colordodge_khr);
# ifdef GL_DARKEN_KHR
	BOOST_CHECK(x != ev.darken_khr);
# endif
# ifdef GL_DIFFERENCE_KHR
	BOOST_CHECK(x != ev.difference_khr);
# endif
# ifdef GL_EXCLUSION_KHR
	BOOST_CHECK(x != ev.exclusion_khr);
# endif
# ifdef GL_HARDLIGHT_KHR
	BOOST_CHECK(x != ev.hardlight_khr);
# endif
# ifdef GL_HSL_COLOR_KHR
	BOOST_CHECK(x != ev.hsl_color_khr);
# endif
# ifdef GL_HSL_HUE_KHR
	BOOST_CHECK(x != ev.hsl_hue_khr);
# endif
# ifdef GL_HSL_LUMINOSITY_KHR
	BOOST_CHECK(x != ev.hsl_luminosity_khr);
# endif
# ifdef GL_HSL_SATURATION_KHR
	BOOST_CHECK(x != ev.hsl_saturation_khr);
# endif
# ifdef GL_LIGHTEN_KHR
	BOOST_CHECK(x != ev.lighten_khr);
# endif
# ifdef GL_MULTIPLY_KHR
	BOOST_CHECK(x != ev.multiply_khr);
# endif
# ifdef GL_OVERLAY_KHR
	BOOST_CHECK(x != ev.overlay_khr);
# endif
# ifdef GL_SCREEN_KHR
	BOOST_CHECK(x != ev.screen_khr);
# endif
# ifdef GL_SOFTLIGHT_KHR
	BOOST_CHECK(x != ev.softlight_khr);
# endif
#endif

#ifdef GL_DARKEN_KHR
	x = ev.darken_khr;
# ifdef GL_COLORBURN_KHR
	BOOST_CHECK(x != ev.colorburn_khr);
# endif
# ifdef GL_COLORDODGE_KHR
	BOOST_CHECK(x != ev.colordodge_khr);
# endif
	BOOST_CHECK(x == ev.darken_khr);
# ifdef GL_DIFFERENCE_KHR
	BOOST_CHECK(x != ev.difference_khr);
# endif
# ifdef GL_EXCLUSION_KHR
	BOOST_CHECK(x != ev.exclusion_khr);
# endif
# ifdef GL_HARDLIGHT_KHR
	BOOST_CHECK(x != ev.hardlight_khr);
# endif
# ifdef GL_HSL_COLOR_KHR
	BOOST_CHECK(x != ev.hsl_color_khr);
# endif
# ifdef GL_HSL_HUE_KHR
	BOOST_CHECK(x != ev.hsl_hue_khr);
# endif
# ifdef GL_HSL_LUMINOSITY_KHR
	BOOST_CHECK(x != ev.hsl_luminosity_khr);
# endif
# ifdef GL_HSL_SATURATION_KHR
	BOOST_CHECK(x != ev.hsl_saturation_khr);
# endif
# ifdef GL_LIGHTEN_KHR
	BOOST_CHECK(x != ev.lighten_khr);
# endif
# ifdef GL_MULTIPLY_KHR
	BOOST_CHECK(x != ev.multiply_khr);
# endif
# ifdef GL_OVERLAY_KHR
	BOOST_CHECK(x != ev.overlay_khr);
# endif
# ifdef GL_SCREEN_KHR
	BOOST_CHECK(x != ev.screen_khr);
# endif
# ifdef GL_SOFTLIGHT_KHR
	BOOST_CHECK(x != ev.softlight_khr);
# endif
#endif

#ifdef GL_DIFFERENCE_KHR
	x = ev.difference_khr;
# ifdef GL_COLORBURN_KHR
	BOOST_CHECK(x != ev.colorburn_khr);
# endif
# ifdef GL_COLORDODGE_KHR
	BOOST_CHECK(x != ev.colordodge_khr);
# endif
# ifdef GL_DARKEN_KHR
	BOOST_CHECK(x != ev.darken_khr);
# endif
	BOOST_CHECK(x == ev.difference_khr);
# ifdef GL_EXCLUSION_KHR
	BOOST_CHECK(x != ev.exclusion_khr);
# endif
# ifdef GL_HARDLIGHT_KHR
	BOOST_CHECK(x != ev.hardlight_khr);
# endif
# ifdef GL_HSL_COLOR_KHR
	BOOST_CHECK(x != ev.hsl_color_khr);
# endif
# ifdef GL_HSL_HUE_KHR
	BOOST_CHECK(x != ev.hsl_hue_khr);
# endif
# ifdef GL_HSL_LUMINOSITY_KHR
	BOOST_CHECK(x != ev.hsl_luminosity_khr);
# endif
# ifdef GL_HSL_SATURATION_KHR
	BOOST_CHECK(x != ev.hsl_saturation_khr);
# endif
# ifdef GL_LIGHTEN_KHR
	BOOST_CHECK(x != ev.lighten_khr);
# endif
# ifdef GL_MULTIPLY_KHR
	BOOST_CHECK(x != ev.multiply_khr);
# endif
# ifdef GL_OVERLAY_KHR
	BOOST_CHECK(x != ev.overlay_khr);
# endif
# ifdef GL_SCREEN_KHR
	BOOST_CHECK(x != ev.screen_khr);
# endif
# ifdef GL_SOFTLIGHT_KHR
	BOOST_CHECK(x != ev.softlight_khr);
# endif
#endif

#ifdef GL_EXCLUSION_KHR
	x = ev.exclusion_khr;
# ifdef GL_COLORBURN_KHR
	BOOST_CHECK(x != ev.colorburn_khr);
# endif
# ifdef GL_COLORDODGE_KHR
	BOOST_CHECK(x != ev.colordodge_khr);
# endif
# ifdef GL_DARKEN_KHR
	BOOST_CHECK(x != ev.darken_khr);
# endif
# ifdef GL_DIFFERENCE_KHR
	BOOST_CHECK(x != ev.difference_khr);
# endif
	BOOST_CHECK(x == ev.exclusion_khr);
# ifdef GL_HARDLIGHT_KHR
	BOOST_CHECK(x != ev.hardlight_khr);
# endif
# ifdef GL_HSL_COLOR_KHR
	BOOST_CHECK(x != ev.hsl_color_khr);
# endif
# ifdef GL_HSL_HUE_KHR
	BOOST_CHECK(x != ev.hsl_hue_khr);
# endif
# ifdef GL_HSL_LUMINOSITY_KHR
	BOOST_CHECK(x != ev.hsl_luminosity_khr);
# endif
# ifdef GL_HSL_SATURATION_KHR
	BOOST_CHECK(x != ev.hsl_saturation_khr);
# endif
# ifdef GL_LIGHTEN_KHR
	BOOST_CHECK(x != ev.lighten_khr);
# endif
# ifdef GL_MULTIPLY_KHR
	BOOST_CHECK(x != ev.multiply_khr);
# endif
# ifdef GL_OVERLAY_KHR
	BOOST_CHECK(x != ev.overlay_khr);
# endif
# ifdef GL_SCREEN_KHR
	BOOST_CHECK(x != ev.screen_khr);
# endif
# ifdef GL_SOFTLIGHT_KHR
	BOOST_CHECK(x != ev.softlight_khr);
# endif
#endif

#ifdef GL_HARDLIGHT_KHR
	x = ev.hardlight_khr;
# ifdef GL_COLORBURN_KHR
	BOOST_CHECK(x != ev.colorburn_khr);
# endif
# ifdef GL_COLORDODGE_KHR
	BOOST_CHECK(x != ev.colordodge_khr);
# endif
# ifdef GL_DARKEN_KHR
	BOOST_CHECK(x != ev.darken_khr);
# endif
# ifdef GL_DIFFERENCE_KHR
	BOOST_CHECK(x != ev.difference_khr);
# endif
# ifdef GL_EXCLUSION_KHR
	BOOST_CHECK(x != ev.exclusion_khr);
# endif
	BOOST_CHECK(x == ev.hardlight_khr);
# ifdef GL_HSL_COLOR_KHR
	BOOST_CHECK(x != ev.hsl_color_khr);
# endif
# ifdef GL_HSL_HUE_KHR
	BOOST_CHECK(x != ev.hsl_hue_khr);
# endif
# ifdef GL_HSL_LUMINOSITY_KHR
	BOOST_CHECK(x != ev.hsl_luminosity_khr);
# endif
# ifdef GL_HSL_SATURATION_KHR
	BOOST_CHECK(x != ev.hsl_saturation_khr);
# endif
# ifdef GL_LIGHTEN_KHR
	BOOST_CHECK(x != ev.lighten_khr);
# endif
# ifdef GL_MULTIPLY_KHR
	BOOST_CHECK(x != ev.multiply_khr);
# endif
# ifdef GL_OVERLAY_KHR
	BOOST_CHECK(x != ev.overlay_khr);
# endif
# ifdef GL_SCREEN_KHR
	BOOST_CHECK(x != ev.screen_khr);
# endif
# ifdef GL_SOFTLIGHT_KHR
	BOOST_CHECK(x != ev.softlight_khr);
# endif
#endif

#ifdef GL_HSL_COLOR_KHR
	x = ev.hsl_color_khr;
# ifdef GL_COLORBURN_KHR
	BOOST_CHECK(x != ev.colorburn_khr);
# endif
# ifdef GL_COLORDODGE_KHR
	BOOST_CHECK(x != ev.colordodge_khr);
# endif
# ifdef GL_DARKEN_KHR
	BOOST_CHECK(x != ev.darken_khr);
# endif
# ifdef GL_DIFFERENCE_KHR
	BOOST_CHECK(x != ev.difference_khr);
# endif
# ifdef GL_EXCLUSION_KHR
	BOOST_CHECK(x != ev.exclusion_khr);
# endif
# ifdef GL_HARDLIGHT_KHR
	BOOST_CHECK(x != ev.hardlight_khr);
# endif
	BOOST_CHECK(x == ev.hsl_color_khr);
# ifdef GL_HSL_HUE_KHR
	BOOST_CHECK(x != ev.hsl_hue_khr);
# endif
# ifdef GL_HSL_LUMINOSITY_KHR
	BOOST_CHECK(x != ev.hsl_luminosity_khr);
# endif
# ifdef GL_HSL_SATURATION_KHR
	BOOST_CHECK(x != ev.hsl_saturation_khr);
# endif
# ifdef GL_LIGHTEN_KHR
	BOOST_CHECK(x != ev.lighten_khr);
# endif
# ifdef GL_MULTIPLY_KHR
	BOOST_CHECK(x != ev.multiply_khr);
# endif
# ifdef GL_OVERLAY_KHR
	BOOST_CHECK(x != ev.overlay_khr);
# endif
# ifdef GL_SCREEN_KHR
	BOOST_CHECK(x != ev.screen_khr);
# endif
# ifdef GL_SOFTLIGHT_KHR
	BOOST_CHECK(x != ev.softlight_khr);
# endif
#endif

#ifdef GL_HSL_HUE_KHR
	x = ev.hsl_hue_khr;
# ifdef GL_COLORBURN_KHR
	BOOST_CHECK(x != ev.colorburn_khr);
# endif
# ifdef GL_COLORDODGE_KHR
	BOOST_CHECK(x != ev.colordodge_khr);
# endif
# ifdef GL_DARKEN_KHR
	BOOST_CHECK(x != ev.darken_khr);
# endif
# ifdef GL_DIFFERENCE_KHR
	BOOST_CHECK(x != ev.difference_khr);
# endif
# ifdef GL_EXCLUSION_KHR
	BOOST_CHECK(x != ev.exclusion_khr);
# endif
# ifdef GL_HARDLIGHT_KHR
	BOOST_CHECK(x != ev.hardlight_khr);
# endif
# ifdef GL_HSL_COLOR_KHR
	BOOST_CHECK(x != ev.hsl_color_khr);
# endif
	BOOST_CHECK(x == ev.hsl_hue_khr);
# ifdef GL_HSL_LUMINOSITY_KHR
	BOOST_CHECK(x != ev.hsl_luminosity_khr);
# endif
# ifdef GL_HSL_SATURATION_KHR
	BOOST_CHECK(x != ev.hsl_saturation_khr);
# endif
# ifdef GL_LIGHTEN_KHR
	BOOST_CHECK(x != ev.lighten_khr);
# endif
# ifdef GL_MULTIPLY_KHR
	BOOST_CHECK(x != ev.multiply_khr);
# endif
# ifdef GL_OVERLAY_KHR
	BOOST_CHECK(x != ev.overlay_khr);
# endif
# ifdef GL_SCREEN_KHR
	BOOST_CHECK(x != ev.screen_khr);
# endif
# ifdef GL_SOFTLIGHT_KHR
	BOOST_CHECK(x != ev.softlight_khr);
# endif
#endif

#ifdef GL_HSL_LUMINOSITY_KHR
	x = ev.hsl_luminosity_khr;
# ifdef GL_COLORBURN_KHR
	BOOST_CHECK(x != ev.colorburn_khr);
# endif
# ifdef GL_COLORDODGE_KHR
	BOOST_CHECK(x != ev.colordodge_khr);
# endif
# ifdef GL_DARKEN_KHR
	BOOST_CHECK(x != ev.darken_khr);
# endif
# ifdef GL_DIFFERENCE_KHR
	BOOST_CHECK(x != ev.difference_khr);
# endif
# ifdef GL_EXCLUSION_KHR
	BOOST_CHECK(x != ev.exclusion_khr);
# endif
# ifdef GL_HARDLIGHT_KHR
	BOOST_CHECK(x != ev.hardlight_khr);
# endif
# ifdef GL_HSL_COLOR_KHR
	BOOST_CHECK(x != ev.hsl_color_khr);
# endif
# ifdef GL_HSL_HUE_KHR
	BOOST_CHECK(x != ev.hsl_hue_khr);
# endif
	BOOST_CHECK(x == ev.hsl_luminosity_khr);
# ifdef GL_HSL_SATURATION_KHR
	BOOST_CHECK(x != ev.hsl_saturation_khr);
# endif
# ifdef GL_LIGHTEN_KHR
	BOOST_CHECK(x != ev.lighten_khr);
# endif
# ifdef GL_MULTIPLY_KHR
	BOOST_CHECK(x != ev.multiply_khr);
# endif
# ifdef GL_OVERLAY_KHR
	BOOST_CHECK(x != ev.overlay_khr);
# endif
# ifdef GL_SCREEN_KHR
	BOOST_CHECK(x != ev.screen_khr);
# endif
# ifdef GL_SOFTLIGHT_KHR
	BOOST_CHECK(x != ev.softlight_khr);
# endif
#endif

#ifdef GL_HSL_SATURATION_KHR
	x = ev.hsl_saturation_khr;
# ifdef GL_COLORBURN_KHR
	BOOST_CHECK(x != ev.colorburn_khr);
# endif
# ifdef GL_COLORDODGE_KHR
	BOOST_CHECK(x != ev.colordodge_khr);
# endif
# ifdef GL_DARKEN_KHR
	BOOST_CHECK(x != ev.darken_khr);
# endif
# ifdef GL_DIFFERENCE_KHR
	BOOST_CHECK(x != ev.difference_khr);
# endif
# ifdef GL_EXCLUSION_KHR
	BOOST_CHECK(x != ev.exclusion_khr);
# endif
# ifdef GL_HARDLIGHT_KHR
	BOOST_CHECK(x != ev.hardlight_khr);
# endif
# ifdef GL_HSL_COLOR_KHR
	BOOST_CHECK(x != ev.hsl_color_khr);
# endif
# ifdef GL_HSL_HUE_KHR
	BOOST_CHECK(x != ev.hsl_hue_khr);
# endif
# ifdef GL_HSL_LUMINOSITY_KHR
	BOOST_CHECK(x != ev.hsl_luminosity_khr);
# endif
	BOOST_CHECK(x == ev.hsl_saturation_khr);
# ifdef GL_LIGHTEN_KHR
	BOOST_CHECK(x != ev.lighten_khr);
# endif
# ifdef GL_MULTIPLY_KHR
	BOOST_CHECK(x != ev.multiply_khr);
# endif
# ifdef GL_OVERLAY_KHR
	BOOST_CHECK(x != ev.overlay_khr);
# endif
# ifdef GL_SCREEN_KHR
	BOOST_CHECK(x != ev.screen_khr);
# endif
# ifdef GL_SOFTLIGHT_KHR
	BOOST_CHECK(x != ev.softlight_khr);
# endif
#endif

#ifdef GL_LIGHTEN_KHR
	x = ev.lighten_khr;
# ifdef GL_COLORBURN_KHR
	BOOST_CHECK(x != ev.colorburn_khr);
# endif
# ifdef GL_COLORDODGE_KHR
	BOOST_CHECK(x != ev.colordodge_khr);
# endif
# ifdef GL_DARKEN_KHR
	BOOST_CHECK(x != ev.darken_khr);
# endif
# ifdef GL_DIFFERENCE_KHR
	BOOST_CHECK(x != ev.difference_khr);
# endif
# ifdef GL_EXCLUSION_KHR
	BOOST_CHECK(x != ev.exclusion_khr);
# endif
# ifdef GL_HARDLIGHT_KHR
	BOOST_CHECK(x != ev.hardlight_khr);
# endif
# ifdef GL_HSL_COLOR_KHR
	BOOST_CHECK(x != ev.hsl_color_khr);
# endif
# ifdef GL_HSL_HUE_KHR
	BOOST_CHECK(x != ev.hsl_hue_khr);
# endif
# ifdef GL_HSL_LUMINOSITY_KHR
	BOOST_CHECK(x != ev.hsl_luminosity_khr);
# endif
# ifdef GL_HSL_SATURATION_KHR
	BOOST_CHECK(x != ev.hsl_saturation_khr);
# endif
	BOOST_CHECK(x == ev.lighten_khr);
# ifdef GL_MULTIPLY_KHR
	BOOST_CHECK(x != ev.multiply_khr);
# endif
# ifdef GL_OVERLAY_KHR
	BOOST_CHECK(x != ev.overlay_khr);
# endif
# ifdef GL_SCREEN_KHR
	BOOST_CHECK(x != ev.screen_khr);
# endif
# ifdef GL_SOFTLIGHT_KHR
	BOOST_CHECK(x != ev.softlight_khr);
# endif
#endif

#ifdef GL_MULTIPLY_KHR
	x = ev.multiply_khr;
# ifdef GL_COLORBURN_KHR
	BOOST_CHECK(x != ev.colorburn_khr);
# endif
# ifdef GL_COLORDODGE_KHR
	BOOST_CHECK(x != ev.colordodge_khr);
# endif
# ifdef GL_DARKEN_KHR
	BOOST_CHECK(x != ev.darken_khr);
# endif
# ifdef GL_DIFFERENCE_KHR
	BOOST_CHECK(x != ev.difference_khr);
# endif
# ifdef GL_EXCLUSION_KHR
	BOOST_CHECK(x != ev.exclusion_khr);
# endif
# ifdef GL_HARDLIGHT_KHR
	BOOST_CHECK(x != ev.hardlight_khr);
# endif
# ifdef GL_HSL_COLOR_KHR
	BOOST_CHECK(x != ev.hsl_color_khr);
# endif
# ifdef GL_HSL_HUE_KHR
	BOOST_CHECK(x != ev.hsl_hue_khr);
# endif
# ifdef GL_HSL_LUMINOSITY_KHR
	BOOST_CHECK(x != ev.hsl_luminosity_khr);
# endif
# ifdef GL_HSL_SATURATION_KHR
	BOOST_CHECK(x != ev.hsl_saturation_khr);
# endif
# ifdef GL_LIGHTEN_KHR
	BOOST_CHECK(x != ev.lighten_khr);
# endif
	BOOST_CHECK(x == ev.multiply_khr);
# ifdef GL_OVERLAY_KHR
	BOOST_CHECK(x != ev.overlay_khr);
# endif
# ifdef GL_SCREEN_KHR
	BOOST_CHECK(x != ev.screen_khr);
# endif
# ifdef GL_SOFTLIGHT_KHR
	BOOST_CHECK(x != ev.softlight_khr);
# endif
#endif

#ifdef GL_OVERLAY_KHR
	x = ev.overlay_khr;
# ifdef GL_COLORBURN_KHR
	BOOST_CHECK(x != ev.colorburn_khr);
# endif
# ifdef GL_COLORDODGE_KHR
	BOOST_CHECK(x != ev.colordodge_khr);
# endif
# ifdef GL_DARKEN_KHR
	BOOST_CHECK(x != ev.darken_khr);
# endif
# ifdef GL_DIFFERENCE_KHR
	BOOST_CHECK(x != ev.difference_khr);
# endif
# ifdef GL_EXCLUSION_KHR
	BOOST_CHECK(x != ev.exclusion_khr);
# endif
# ifdef GL_HARDLIGHT_KHR
	BOOST_CHECK(x != ev.hardlight_khr);
# endif
# ifdef GL_HSL_COLOR_KHR
	BOOST_CHECK(x != ev.hsl_color_khr);
# endif
# ifdef GL_HSL_HUE_KHR
	BOOST_CHECK(x != ev.hsl_hue_khr);
# endif
# ifdef GL_HSL_LUMINOSITY_KHR
	BOOST_CHECK(x != ev.hsl_luminosity_khr);
# endif
# ifdef GL_HSL_SATURATION_KHR
	BOOST_CHECK(x != ev.hsl_saturation_khr);
# endif
# ifdef GL_LIGHTEN_KHR
	BOOST_CHECK(x != ev.lighten_khr);
# endif
# ifdef GL_MULTIPLY_KHR
	BOOST_CHECK(x != ev.multiply_khr);
# endif
	BOOST_CHECK(x == ev.overlay_khr);
# ifdef GL_SCREEN_KHR
	BOOST_CHECK(x != ev.screen_khr);
# endif
# ifdef GL_SOFTLIGHT_KHR
	BOOST_CHECK(x != ev.softlight_khr);
# endif
#endif

#ifdef GL_SCREEN_KHR
	x = ev.screen_khr;
# ifdef GL_COLORBURN_KHR
	BOOST_CHECK(x != ev.colorburn_khr);
# endif
# ifdef GL_COLORDODGE_KHR
	BOOST_CHECK(x != ev.colordodge_khr);
# endif
# ifdef GL_DARKEN_KHR
	BOOST_CHECK(x != ev.darken_khr);
# endif
# ifdef GL_DIFFERENCE_KHR
	BOOST_CHECK(x != ev.difference_khr);
# endif
# ifdef GL_EXCLUSION_KHR
	BOOST_CHECK(x != ev.exclusion_khr);
# endif
# ifdef GL_HARDLIGHT_KHR
	BOOST_CHECK(x != ev.hardlight_khr);
# endif
# ifdef GL_HSL_COLOR_KHR
	BOOST_CHECK(x != ev.hsl_color_khr);
# endif
# ifdef GL_HSL_HUE_KHR
	BOOST_CHECK(x != ev.hsl_hue_khr);
# endif
# ifdef GL_HSL_LUMINOSITY_KHR
	BOOST_CHECK(x != ev.hsl_luminosity_khr);
# endif
# ifdef GL_HSL_SATURATION_KHR
	BOOST_CHECK(x != ev.hsl_saturation_khr);
# endif
# ifdef GL_LIGHTEN_KHR
	BOOST_CHECK(x != ev.lighten_khr);
# endif
# ifdef GL_MULTIPLY_KHR
	BOOST_CHECK(x != ev.multiply_khr);
# endif
# ifdef GL_OVERLAY_KHR
	BOOST_CHECK(x != ev.overlay_khr);
# endif
	BOOST_CHECK(x == ev.screen_khr);
# ifdef GL_SOFTLIGHT_KHR
	BOOST_CHECK(x != ev.softlight_khr);
# endif
#endif

#ifdef GL_SOFTLIGHT_KHR
	x = ev.softlight_khr;
# ifdef GL_COLORBURN_KHR
	BOOST_CHECK(x != ev.colorburn_khr);
# endif
# ifdef GL_COLORDODGE_KHR
	BOOST_CHECK(x != ev.colordodge_khr);
# endif
# ifdef GL_DARKEN_KHR
	BOOST_CHECK(x != ev.darken_khr);
# endif
# ifdef GL_DIFFERENCE_KHR
	BOOST_CHECK(x != ev.difference_khr);
# endif
# ifdef GL_EXCLUSION_KHR
	BOOST_CHECK(x != ev.exclusion_khr);
# endif
# ifdef GL_HARDLIGHT_KHR
	BOOST_CHECK(x != ev.hardlight_khr);
# endif
# ifdef GL_HSL_COLOR_KHR
	BOOST_CHECK(x != ev.hsl_color_khr);
# endif
# ifdef GL_HSL_HUE_KHR
	BOOST_CHECK(x != ev.hsl_hue_khr);
# endif
# ifdef GL_HSL_LUMINOSITY_KHR
	BOOST_CHECK(x != ev.hsl_luminosity_khr);
# endif
# ifdef GL_HSL_SATURATION_KHR
	BOOST_CHECK(x != ev.hsl_saturation_khr);
# endif
# ifdef GL_LIGHTEN_KHR
	BOOST_CHECK(x != ev.lighten_khr);
# endif
# ifdef GL_MULTIPLY_KHR
	BOOST_CHECK(x != ev.multiply_khr);
# endif
# ifdef GL_OVERLAY_KHR
	BOOST_CHECK(x != ev.overlay_khr);
# endif
# ifdef GL_SCREEN_KHR
	BOOST_CHECK(x != ev.screen_khr);
# endif
	BOOST_CHECK(x == ev.softlight_khr);
#endif
}

BOOST_AUTO_TEST_CASE(enum_blend_equation_advanced_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	blend_equation_advanced x;
	(void)x;

#ifdef GL_COLORBURN_KHR
	x = ev.colorburn_khr;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"COLORBURN_KHR"
	) == 0);
#endif

#ifdef GL_COLORDODGE_KHR
	x = ev.colordodge_khr;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"COLORDODGE_KHR"
	) == 0);
#endif

#ifdef GL_DARKEN_KHR
	x = ev.darken_khr;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DARKEN_KHR"
	) == 0);
#endif

#ifdef GL_DIFFERENCE_KHR
	x = ev.difference_khr;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DIFFERENCE_KHR"
	) == 0);
#endif

#ifdef GL_EXCLUSION_KHR
	x = ev.exclusion_khr;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"EXCLUSION_KHR"
	) == 0);
#endif

#ifdef GL_HARDLIGHT_KHR
	x = ev.hardlight_khr;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"HARDLIGHT_KHR"
	) == 0);
#endif

#ifdef GL_HSL_COLOR_KHR
	x = ev.hsl_color_khr;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"HSL_COLOR_KHR"
	) == 0);
#endif

#ifdef GL_HSL_HUE_KHR
	x = ev.hsl_hue_khr;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"HSL_HUE_KHR"
	) == 0);
#endif

#ifdef GL_HSL_LUMINOSITY_KHR
	x = ev.hsl_luminosity_khr;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"HSL_LUMINOSITY_KHR"
	) == 0);
#endif

#ifdef GL_HSL_SATURATION_KHR
	x = ev.hsl_saturation_khr;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"HSL_SATURATION_KHR"
	) == 0);
#endif

#ifdef GL_LIGHTEN_KHR
	x = ev.lighten_khr;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"LIGHTEN_KHR"
	) == 0);
#endif

#ifdef GL_MULTIPLY_KHR
	x = ev.multiply_khr;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MULTIPLY_KHR"
	) == 0);
#endif

#ifdef GL_OVERLAY_KHR
	x = ev.overlay_khr;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"OVERLAY_KHR"
	) == 0);
#endif

#ifdef GL_SCREEN_KHR
	x = ev.screen_khr;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SCREEN_KHR"
	) == 0);
#endif

#ifdef GL_SOFTLIGHT_KHR
	x = ev.softlight_khr;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SOFTLIGHT_KHR"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_blend_equation_advanced_range)
{
	using namespace oglplus;
	blend_equation_advanced x;
	(void)x;
	auto count = enum_value_range(x).size();

#ifdef GL_COLORBURN_KHR
{
	--count;
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_COLORBURN_KHR
	) != r.end());
}
#endif

#ifdef GL_COLORDODGE_KHR
{
	--count;
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_COLORDODGE_KHR
	) != r.end());
}
#endif

#ifdef GL_DARKEN_KHR
{
	--count;
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_DARKEN_KHR
	) != r.end());
}
#endif

#ifdef GL_DIFFERENCE_KHR
{
	--count;
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_DIFFERENCE_KHR
	) != r.end());
}
#endif

#ifdef GL_EXCLUSION_KHR
{
	--count;
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_EXCLUSION_KHR
	) != r.end());
}
#endif

#ifdef GL_HARDLIGHT_KHR
{
	--count;
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_HARDLIGHT_KHR
	) != r.end());
}
#endif

#ifdef GL_HSL_COLOR_KHR
{
	--count;
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_HSL_COLOR_KHR
	) != r.end());
}
#endif

#ifdef GL_HSL_HUE_KHR
{
	--count;
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_HSL_HUE_KHR
	) != r.end());
}
#endif

#ifdef GL_HSL_LUMINOSITY_KHR
{
	--count;
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_HSL_LUMINOSITY_KHR
	) != r.end());
}
#endif

#ifdef GL_HSL_SATURATION_KHR
{
	--count;
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_HSL_SATURATION_KHR
	) != r.end());
}
#endif

#ifdef GL_LIGHTEN_KHR
{
	--count;
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_LIGHTEN_KHR
	) != r.end());
}
#endif

#ifdef GL_MULTIPLY_KHR
{
	--count;
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_MULTIPLY_KHR
	) != r.end());
}
#endif

#ifdef GL_OVERLAY_KHR
{
	--count;
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_OVERLAY_KHR
	) != r.end());
}
#endif

#ifdef GL_SCREEN_KHR
{
	--count;
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_SCREEN_KHR
	) != r.end());
}
#endif

#ifdef GL_SOFTLIGHT_KHR
{
	--count;
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_SOFTLIGHT_KHR
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_SUITE_END()
