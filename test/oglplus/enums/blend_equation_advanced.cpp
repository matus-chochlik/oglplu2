//  File test/oglplus/enums/blend_equation_advanced.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_blend_equation_advanced

#include <boost/test/unit_test.hpp>
#include "common.hpp"

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

BOOST_AUTO_TEST_SUITE_END()
