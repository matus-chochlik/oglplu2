//  File test/oglplus/enums/pixel_data_format.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_pixel_data_format

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_pixel_data_format)

BOOST_AUTO_TEST_CASE(enum_pixel_data_format_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	pixel_data_format x;
	(void)x;

#ifdef GL_BGR
	x = ev.bgr;
	BOOST_CHECK(x == ev.bgr);
# ifdef GL_BGR_INTEGER
	BOOST_CHECK(x != ev.bgr_integer);
# endif
# ifdef GL_BGRA
	BOOST_CHECK(x != ev.bgra);
# endif
# ifdef GL_BGRA_INTEGER
	BOOST_CHECK(x != ev.bgra_integer);
# endif
# ifdef GL_BLUE
	BOOST_CHECK(x != ev.blue);
# endif
# ifdef GL_BLUE_INTEGER
	BOOST_CHECK(x != ev.blue_integer);
# endif
# ifdef GL_DEPTH_COMPONENT
	BOOST_CHECK(x != ev.depth_component);
# endif
# ifdef GL_DEPTH_STENCIL
	BOOST_CHECK(x != ev.depth_stencil);
# endif
# ifdef GL_GREEN
	BOOST_CHECK(x != ev.green);
# endif
# ifdef GL_GREEN_INTEGER
	BOOST_CHECK(x != ev.green_integer);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RED_INTEGER
	BOOST_CHECK(x != ev.red_integer);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG_INTEGER
	BOOST_CHECK(x != ev.rg_integer);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB_INTEGER
	BOOST_CHECK(x != ev.rgb_integer);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA_INTEGER
	BOOST_CHECK(x != ev.rgba_integer);
# endif
# ifdef GL_STENCIL_INDEX
	BOOST_CHECK(x != ev.stencil_index);
# endif
#endif

#ifdef GL_BGR_INTEGER
	x = ev.bgr_integer;
# ifdef GL_BGR
	BOOST_CHECK(x != ev.bgr);
# endif
	BOOST_CHECK(x == ev.bgr_integer);
# ifdef GL_BGRA
	BOOST_CHECK(x != ev.bgra);
# endif
# ifdef GL_BGRA_INTEGER
	BOOST_CHECK(x != ev.bgra_integer);
# endif
# ifdef GL_BLUE
	BOOST_CHECK(x != ev.blue);
# endif
# ifdef GL_BLUE_INTEGER
	BOOST_CHECK(x != ev.blue_integer);
# endif
# ifdef GL_DEPTH_COMPONENT
	BOOST_CHECK(x != ev.depth_component);
# endif
# ifdef GL_DEPTH_STENCIL
	BOOST_CHECK(x != ev.depth_stencil);
# endif
# ifdef GL_GREEN
	BOOST_CHECK(x != ev.green);
# endif
# ifdef GL_GREEN_INTEGER
	BOOST_CHECK(x != ev.green_integer);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RED_INTEGER
	BOOST_CHECK(x != ev.red_integer);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG_INTEGER
	BOOST_CHECK(x != ev.rg_integer);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB_INTEGER
	BOOST_CHECK(x != ev.rgb_integer);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA_INTEGER
	BOOST_CHECK(x != ev.rgba_integer);
# endif
# ifdef GL_STENCIL_INDEX
	BOOST_CHECK(x != ev.stencil_index);
# endif
#endif

#ifdef GL_BGRA
	x = ev.bgra;
# ifdef GL_BGR
	BOOST_CHECK(x != ev.bgr);
# endif
# ifdef GL_BGR_INTEGER
	BOOST_CHECK(x != ev.bgr_integer);
# endif
	BOOST_CHECK(x == ev.bgra);
# ifdef GL_BGRA_INTEGER
	BOOST_CHECK(x != ev.bgra_integer);
# endif
# ifdef GL_BLUE
	BOOST_CHECK(x != ev.blue);
# endif
# ifdef GL_BLUE_INTEGER
	BOOST_CHECK(x != ev.blue_integer);
# endif
# ifdef GL_DEPTH_COMPONENT
	BOOST_CHECK(x != ev.depth_component);
# endif
# ifdef GL_DEPTH_STENCIL
	BOOST_CHECK(x != ev.depth_stencil);
# endif
# ifdef GL_GREEN
	BOOST_CHECK(x != ev.green);
# endif
# ifdef GL_GREEN_INTEGER
	BOOST_CHECK(x != ev.green_integer);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RED_INTEGER
	BOOST_CHECK(x != ev.red_integer);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG_INTEGER
	BOOST_CHECK(x != ev.rg_integer);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB_INTEGER
	BOOST_CHECK(x != ev.rgb_integer);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA_INTEGER
	BOOST_CHECK(x != ev.rgba_integer);
# endif
# ifdef GL_STENCIL_INDEX
	BOOST_CHECK(x != ev.stencil_index);
# endif
#endif

#ifdef GL_BGRA_INTEGER
	x = ev.bgra_integer;
# ifdef GL_BGR
	BOOST_CHECK(x != ev.bgr);
# endif
# ifdef GL_BGR_INTEGER
	BOOST_CHECK(x != ev.bgr_integer);
# endif
# ifdef GL_BGRA
	BOOST_CHECK(x != ev.bgra);
# endif
	BOOST_CHECK(x == ev.bgra_integer);
# ifdef GL_BLUE
	BOOST_CHECK(x != ev.blue);
# endif
# ifdef GL_BLUE_INTEGER
	BOOST_CHECK(x != ev.blue_integer);
# endif
# ifdef GL_DEPTH_COMPONENT
	BOOST_CHECK(x != ev.depth_component);
# endif
# ifdef GL_DEPTH_STENCIL
	BOOST_CHECK(x != ev.depth_stencil);
# endif
# ifdef GL_GREEN
	BOOST_CHECK(x != ev.green);
# endif
# ifdef GL_GREEN_INTEGER
	BOOST_CHECK(x != ev.green_integer);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RED_INTEGER
	BOOST_CHECK(x != ev.red_integer);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG_INTEGER
	BOOST_CHECK(x != ev.rg_integer);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB_INTEGER
	BOOST_CHECK(x != ev.rgb_integer);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA_INTEGER
	BOOST_CHECK(x != ev.rgba_integer);
# endif
# ifdef GL_STENCIL_INDEX
	BOOST_CHECK(x != ev.stencil_index);
# endif
#endif

#ifdef GL_BLUE
	x = ev.blue;
# ifdef GL_BGR
	BOOST_CHECK(x != ev.bgr);
# endif
# ifdef GL_BGR_INTEGER
	BOOST_CHECK(x != ev.bgr_integer);
# endif
# ifdef GL_BGRA
	BOOST_CHECK(x != ev.bgra);
# endif
# ifdef GL_BGRA_INTEGER
	BOOST_CHECK(x != ev.bgra_integer);
# endif
	BOOST_CHECK(x == ev.blue);
# ifdef GL_BLUE_INTEGER
	BOOST_CHECK(x != ev.blue_integer);
# endif
# ifdef GL_DEPTH_COMPONENT
	BOOST_CHECK(x != ev.depth_component);
# endif
# ifdef GL_DEPTH_STENCIL
	BOOST_CHECK(x != ev.depth_stencil);
# endif
# ifdef GL_GREEN
	BOOST_CHECK(x != ev.green);
# endif
# ifdef GL_GREEN_INTEGER
	BOOST_CHECK(x != ev.green_integer);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RED_INTEGER
	BOOST_CHECK(x != ev.red_integer);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG_INTEGER
	BOOST_CHECK(x != ev.rg_integer);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB_INTEGER
	BOOST_CHECK(x != ev.rgb_integer);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA_INTEGER
	BOOST_CHECK(x != ev.rgba_integer);
# endif
# ifdef GL_STENCIL_INDEX
	BOOST_CHECK(x != ev.stencil_index);
# endif
#endif

#ifdef GL_BLUE_INTEGER
	x = ev.blue_integer;
# ifdef GL_BGR
	BOOST_CHECK(x != ev.bgr);
# endif
# ifdef GL_BGR_INTEGER
	BOOST_CHECK(x != ev.bgr_integer);
# endif
# ifdef GL_BGRA
	BOOST_CHECK(x != ev.bgra);
# endif
# ifdef GL_BGRA_INTEGER
	BOOST_CHECK(x != ev.bgra_integer);
# endif
# ifdef GL_BLUE
	BOOST_CHECK(x != ev.blue);
# endif
	BOOST_CHECK(x == ev.blue_integer);
# ifdef GL_DEPTH_COMPONENT
	BOOST_CHECK(x != ev.depth_component);
# endif
# ifdef GL_DEPTH_STENCIL
	BOOST_CHECK(x != ev.depth_stencil);
# endif
# ifdef GL_GREEN
	BOOST_CHECK(x != ev.green);
# endif
# ifdef GL_GREEN_INTEGER
	BOOST_CHECK(x != ev.green_integer);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RED_INTEGER
	BOOST_CHECK(x != ev.red_integer);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG_INTEGER
	BOOST_CHECK(x != ev.rg_integer);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB_INTEGER
	BOOST_CHECK(x != ev.rgb_integer);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA_INTEGER
	BOOST_CHECK(x != ev.rgba_integer);
# endif
# ifdef GL_STENCIL_INDEX
	BOOST_CHECK(x != ev.stencil_index);
# endif
#endif

#ifdef GL_DEPTH_COMPONENT
	x = ev.depth_component;
# ifdef GL_BGR
	BOOST_CHECK(x != ev.bgr);
# endif
# ifdef GL_BGR_INTEGER
	BOOST_CHECK(x != ev.bgr_integer);
# endif
# ifdef GL_BGRA
	BOOST_CHECK(x != ev.bgra);
# endif
# ifdef GL_BGRA_INTEGER
	BOOST_CHECK(x != ev.bgra_integer);
# endif
# ifdef GL_BLUE
	BOOST_CHECK(x != ev.blue);
# endif
# ifdef GL_BLUE_INTEGER
	BOOST_CHECK(x != ev.blue_integer);
# endif
	BOOST_CHECK(x == ev.depth_component);
# ifdef GL_DEPTH_STENCIL
	BOOST_CHECK(x != ev.depth_stencil);
# endif
# ifdef GL_GREEN
	BOOST_CHECK(x != ev.green);
# endif
# ifdef GL_GREEN_INTEGER
	BOOST_CHECK(x != ev.green_integer);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RED_INTEGER
	BOOST_CHECK(x != ev.red_integer);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG_INTEGER
	BOOST_CHECK(x != ev.rg_integer);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB_INTEGER
	BOOST_CHECK(x != ev.rgb_integer);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA_INTEGER
	BOOST_CHECK(x != ev.rgba_integer);
# endif
# ifdef GL_STENCIL_INDEX
	BOOST_CHECK(x != ev.stencil_index);
# endif
#endif

#ifdef GL_DEPTH_STENCIL
	x = ev.depth_stencil;
# ifdef GL_BGR
	BOOST_CHECK(x != ev.bgr);
# endif
# ifdef GL_BGR_INTEGER
	BOOST_CHECK(x != ev.bgr_integer);
# endif
# ifdef GL_BGRA
	BOOST_CHECK(x != ev.bgra);
# endif
# ifdef GL_BGRA_INTEGER
	BOOST_CHECK(x != ev.bgra_integer);
# endif
# ifdef GL_BLUE
	BOOST_CHECK(x != ev.blue);
# endif
# ifdef GL_BLUE_INTEGER
	BOOST_CHECK(x != ev.blue_integer);
# endif
# ifdef GL_DEPTH_COMPONENT
	BOOST_CHECK(x != ev.depth_component);
# endif
	BOOST_CHECK(x == ev.depth_stencil);
# ifdef GL_GREEN
	BOOST_CHECK(x != ev.green);
# endif
# ifdef GL_GREEN_INTEGER
	BOOST_CHECK(x != ev.green_integer);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RED_INTEGER
	BOOST_CHECK(x != ev.red_integer);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG_INTEGER
	BOOST_CHECK(x != ev.rg_integer);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB_INTEGER
	BOOST_CHECK(x != ev.rgb_integer);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA_INTEGER
	BOOST_CHECK(x != ev.rgba_integer);
# endif
# ifdef GL_STENCIL_INDEX
	BOOST_CHECK(x != ev.stencil_index);
# endif
#endif

#ifdef GL_GREEN
	x = ev.green;
# ifdef GL_BGR
	BOOST_CHECK(x != ev.bgr);
# endif
# ifdef GL_BGR_INTEGER
	BOOST_CHECK(x != ev.bgr_integer);
# endif
# ifdef GL_BGRA
	BOOST_CHECK(x != ev.bgra);
# endif
# ifdef GL_BGRA_INTEGER
	BOOST_CHECK(x != ev.bgra_integer);
# endif
# ifdef GL_BLUE
	BOOST_CHECK(x != ev.blue);
# endif
# ifdef GL_BLUE_INTEGER
	BOOST_CHECK(x != ev.blue_integer);
# endif
# ifdef GL_DEPTH_COMPONENT
	BOOST_CHECK(x != ev.depth_component);
# endif
# ifdef GL_DEPTH_STENCIL
	BOOST_CHECK(x != ev.depth_stencil);
# endif
	BOOST_CHECK(x == ev.green);
# ifdef GL_GREEN_INTEGER
	BOOST_CHECK(x != ev.green_integer);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RED_INTEGER
	BOOST_CHECK(x != ev.red_integer);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG_INTEGER
	BOOST_CHECK(x != ev.rg_integer);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB_INTEGER
	BOOST_CHECK(x != ev.rgb_integer);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA_INTEGER
	BOOST_CHECK(x != ev.rgba_integer);
# endif
# ifdef GL_STENCIL_INDEX
	BOOST_CHECK(x != ev.stencil_index);
# endif
#endif

#ifdef GL_GREEN_INTEGER
	x = ev.green_integer;
# ifdef GL_BGR
	BOOST_CHECK(x != ev.bgr);
# endif
# ifdef GL_BGR_INTEGER
	BOOST_CHECK(x != ev.bgr_integer);
# endif
# ifdef GL_BGRA
	BOOST_CHECK(x != ev.bgra);
# endif
# ifdef GL_BGRA_INTEGER
	BOOST_CHECK(x != ev.bgra_integer);
# endif
# ifdef GL_BLUE
	BOOST_CHECK(x != ev.blue);
# endif
# ifdef GL_BLUE_INTEGER
	BOOST_CHECK(x != ev.blue_integer);
# endif
# ifdef GL_DEPTH_COMPONENT
	BOOST_CHECK(x != ev.depth_component);
# endif
# ifdef GL_DEPTH_STENCIL
	BOOST_CHECK(x != ev.depth_stencil);
# endif
# ifdef GL_GREEN
	BOOST_CHECK(x != ev.green);
# endif
	BOOST_CHECK(x == ev.green_integer);
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RED_INTEGER
	BOOST_CHECK(x != ev.red_integer);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG_INTEGER
	BOOST_CHECK(x != ev.rg_integer);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB_INTEGER
	BOOST_CHECK(x != ev.rgb_integer);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA_INTEGER
	BOOST_CHECK(x != ev.rgba_integer);
# endif
# ifdef GL_STENCIL_INDEX
	BOOST_CHECK(x != ev.stencil_index);
# endif
#endif

#ifdef GL_RED
	x = ev.red;
# ifdef GL_BGR
	BOOST_CHECK(x != ev.bgr);
# endif
# ifdef GL_BGR_INTEGER
	BOOST_CHECK(x != ev.bgr_integer);
# endif
# ifdef GL_BGRA
	BOOST_CHECK(x != ev.bgra);
# endif
# ifdef GL_BGRA_INTEGER
	BOOST_CHECK(x != ev.bgra_integer);
# endif
# ifdef GL_BLUE
	BOOST_CHECK(x != ev.blue);
# endif
# ifdef GL_BLUE_INTEGER
	BOOST_CHECK(x != ev.blue_integer);
# endif
# ifdef GL_DEPTH_COMPONENT
	BOOST_CHECK(x != ev.depth_component);
# endif
# ifdef GL_DEPTH_STENCIL
	BOOST_CHECK(x != ev.depth_stencil);
# endif
# ifdef GL_GREEN
	BOOST_CHECK(x != ev.green);
# endif
# ifdef GL_GREEN_INTEGER
	BOOST_CHECK(x != ev.green_integer);
# endif
	BOOST_CHECK(x == ev.red);
# ifdef GL_RED_INTEGER
	BOOST_CHECK(x != ev.red_integer);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG_INTEGER
	BOOST_CHECK(x != ev.rg_integer);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB_INTEGER
	BOOST_CHECK(x != ev.rgb_integer);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA_INTEGER
	BOOST_CHECK(x != ev.rgba_integer);
# endif
# ifdef GL_STENCIL_INDEX
	BOOST_CHECK(x != ev.stencil_index);
# endif
#endif

#ifdef GL_RED_INTEGER
	x = ev.red_integer;
# ifdef GL_BGR
	BOOST_CHECK(x != ev.bgr);
# endif
# ifdef GL_BGR_INTEGER
	BOOST_CHECK(x != ev.bgr_integer);
# endif
# ifdef GL_BGRA
	BOOST_CHECK(x != ev.bgra);
# endif
# ifdef GL_BGRA_INTEGER
	BOOST_CHECK(x != ev.bgra_integer);
# endif
# ifdef GL_BLUE
	BOOST_CHECK(x != ev.blue);
# endif
# ifdef GL_BLUE_INTEGER
	BOOST_CHECK(x != ev.blue_integer);
# endif
# ifdef GL_DEPTH_COMPONENT
	BOOST_CHECK(x != ev.depth_component);
# endif
# ifdef GL_DEPTH_STENCIL
	BOOST_CHECK(x != ev.depth_stencil);
# endif
# ifdef GL_GREEN
	BOOST_CHECK(x != ev.green);
# endif
# ifdef GL_GREEN_INTEGER
	BOOST_CHECK(x != ev.green_integer);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
	BOOST_CHECK(x == ev.red_integer);
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG_INTEGER
	BOOST_CHECK(x != ev.rg_integer);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB_INTEGER
	BOOST_CHECK(x != ev.rgb_integer);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA_INTEGER
	BOOST_CHECK(x != ev.rgba_integer);
# endif
# ifdef GL_STENCIL_INDEX
	BOOST_CHECK(x != ev.stencil_index);
# endif
#endif

#ifdef GL_RG
	x = ev.rg;
# ifdef GL_BGR
	BOOST_CHECK(x != ev.bgr);
# endif
# ifdef GL_BGR_INTEGER
	BOOST_CHECK(x != ev.bgr_integer);
# endif
# ifdef GL_BGRA
	BOOST_CHECK(x != ev.bgra);
# endif
# ifdef GL_BGRA_INTEGER
	BOOST_CHECK(x != ev.bgra_integer);
# endif
# ifdef GL_BLUE
	BOOST_CHECK(x != ev.blue);
# endif
# ifdef GL_BLUE_INTEGER
	BOOST_CHECK(x != ev.blue_integer);
# endif
# ifdef GL_DEPTH_COMPONENT
	BOOST_CHECK(x != ev.depth_component);
# endif
# ifdef GL_DEPTH_STENCIL
	BOOST_CHECK(x != ev.depth_stencil);
# endif
# ifdef GL_GREEN
	BOOST_CHECK(x != ev.green);
# endif
# ifdef GL_GREEN_INTEGER
	BOOST_CHECK(x != ev.green_integer);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RED_INTEGER
	BOOST_CHECK(x != ev.red_integer);
# endif
	BOOST_CHECK(x == ev.rg);
# ifdef GL_RG_INTEGER
	BOOST_CHECK(x != ev.rg_integer);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB_INTEGER
	BOOST_CHECK(x != ev.rgb_integer);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA_INTEGER
	BOOST_CHECK(x != ev.rgba_integer);
# endif
# ifdef GL_STENCIL_INDEX
	BOOST_CHECK(x != ev.stencil_index);
# endif
#endif

#ifdef GL_RG_INTEGER
	x = ev.rg_integer;
# ifdef GL_BGR
	BOOST_CHECK(x != ev.bgr);
# endif
# ifdef GL_BGR_INTEGER
	BOOST_CHECK(x != ev.bgr_integer);
# endif
# ifdef GL_BGRA
	BOOST_CHECK(x != ev.bgra);
# endif
# ifdef GL_BGRA_INTEGER
	BOOST_CHECK(x != ev.bgra_integer);
# endif
# ifdef GL_BLUE
	BOOST_CHECK(x != ev.blue);
# endif
# ifdef GL_BLUE_INTEGER
	BOOST_CHECK(x != ev.blue_integer);
# endif
# ifdef GL_DEPTH_COMPONENT
	BOOST_CHECK(x != ev.depth_component);
# endif
# ifdef GL_DEPTH_STENCIL
	BOOST_CHECK(x != ev.depth_stencil);
# endif
# ifdef GL_GREEN
	BOOST_CHECK(x != ev.green);
# endif
# ifdef GL_GREEN_INTEGER
	BOOST_CHECK(x != ev.green_integer);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RED_INTEGER
	BOOST_CHECK(x != ev.red_integer);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
	BOOST_CHECK(x == ev.rg_integer);
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB_INTEGER
	BOOST_CHECK(x != ev.rgb_integer);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA_INTEGER
	BOOST_CHECK(x != ev.rgba_integer);
# endif
# ifdef GL_STENCIL_INDEX
	BOOST_CHECK(x != ev.stencil_index);
# endif
#endif

#ifdef GL_RGB
	x = ev.rgb;
# ifdef GL_BGR
	BOOST_CHECK(x != ev.bgr);
# endif
# ifdef GL_BGR_INTEGER
	BOOST_CHECK(x != ev.bgr_integer);
# endif
# ifdef GL_BGRA
	BOOST_CHECK(x != ev.bgra);
# endif
# ifdef GL_BGRA_INTEGER
	BOOST_CHECK(x != ev.bgra_integer);
# endif
# ifdef GL_BLUE
	BOOST_CHECK(x != ev.blue);
# endif
# ifdef GL_BLUE_INTEGER
	BOOST_CHECK(x != ev.blue_integer);
# endif
# ifdef GL_DEPTH_COMPONENT
	BOOST_CHECK(x != ev.depth_component);
# endif
# ifdef GL_DEPTH_STENCIL
	BOOST_CHECK(x != ev.depth_stencil);
# endif
# ifdef GL_GREEN
	BOOST_CHECK(x != ev.green);
# endif
# ifdef GL_GREEN_INTEGER
	BOOST_CHECK(x != ev.green_integer);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RED_INTEGER
	BOOST_CHECK(x != ev.red_integer);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG_INTEGER
	BOOST_CHECK(x != ev.rg_integer);
# endif
	BOOST_CHECK(x == ev.rgb);
# ifdef GL_RGB_INTEGER
	BOOST_CHECK(x != ev.rgb_integer);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA_INTEGER
	BOOST_CHECK(x != ev.rgba_integer);
# endif
# ifdef GL_STENCIL_INDEX
	BOOST_CHECK(x != ev.stencil_index);
# endif
#endif

#ifdef GL_RGB_INTEGER
	x = ev.rgb_integer;
# ifdef GL_BGR
	BOOST_CHECK(x != ev.bgr);
# endif
# ifdef GL_BGR_INTEGER
	BOOST_CHECK(x != ev.bgr_integer);
# endif
# ifdef GL_BGRA
	BOOST_CHECK(x != ev.bgra);
# endif
# ifdef GL_BGRA_INTEGER
	BOOST_CHECK(x != ev.bgra_integer);
# endif
# ifdef GL_BLUE
	BOOST_CHECK(x != ev.blue);
# endif
# ifdef GL_BLUE_INTEGER
	BOOST_CHECK(x != ev.blue_integer);
# endif
# ifdef GL_DEPTH_COMPONENT
	BOOST_CHECK(x != ev.depth_component);
# endif
# ifdef GL_DEPTH_STENCIL
	BOOST_CHECK(x != ev.depth_stencil);
# endif
# ifdef GL_GREEN
	BOOST_CHECK(x != ev.green);
# endif
# ifdef GL_GREEN_INTEGER
	BOOST_CHECK(x != ev.green_integer);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RED_INTEGER
	BOOST_CHECK(x != ev.red_integer);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG_INTEGER
	BOOST_CHECK(x != ev.rg_integer);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
	BOOST_CHECK(x == ev.rgb_integer);
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA_INTEGER
	BOOST_CHECK(x != ev.rgba_integer);
# endif
# ifdef GL_STENCIL_INDEX
	BOOST_CHECK(x != ev.stencil_index);
# endif
#endif

#ifdef GL_RGBA
	x = ev.rgba;
# ifdef GL_BGR
	BOOST_CHECK(x != ev.bgr);
# endif
# ifdef GL_BGR_INTEGER
	BOOST_CHECK(x != ev.bgr_integer);
# endif
# ifdef GL_BGRA
	BOOST_CHECK(x != ev.bgra);
# endif
# ifdef GL_BGRA_INTEGER
	BOOST_CHECK(x != ev.bgra_integer);
# endif
# ifdef GL_BLUE
	BOOST_CHECK(x != ev.blue);
# endif
# ifdef GL_BLUE_INTEGER
	BOOST_CHECK(x != ev.blue_integer);
# endif
# ifdef GL_DEPTH_COMPONENT
	BOOST_CHECK(x != ev.depth_component);
# endif
# ifdef GL_DEPTH_STENCIL
	BOOST_CHECK(x != ev.depth_stencil);
# endif
# ifdef GL_GREEN
	BOOST_CHECK(x != ev.green);
# endif
# ifdef GL_GREEN_INTEGER
	BOOST_CHECK(x != ev.green_integer);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RED_INTEGER
	BOOST_CHECK(x != ev.red_integer);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG_INTEGER
	BOOST_CHECK(x != ev.rg_integer);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB_INTEGER
	BOOST_CHECK(x != ev.rgb_integer);
# endif
	BOOST_CHECK(x == ev.rgba);
# ifdef GL_RGBA_INTEGER
	BOOST_CHECK(x != ev.rgba_integer);
# endif
# ifdef GL_STENCIL_INDEX
	BOOST_CHECK(x != ev.stencil_index);
# endif
#endif

#ifdef GL_RGBA_INTEGER
	x = ev.rgba_integer;
# ifdef GL_BGR
	BOOST_CHECK(x != ev.bgr);
# endif
# ifdef GL_BGR_INTEGER
	BOOST_CHECK(x != ev.bgr_integer);
# endif
# ifdef GL_BGRA
	BOOST_CHECK(x != ev.bgra);
# endif
# ifdef GL_BGRA_INTEGER
	BOOST_CHECK(x != ev.bgra_integer);
# endif
# ifdef GL_BLUE
	BOOST_CHECK(x != ev.blue);
# endif
# ifdef GL_BLUE_INTEGER
	BOOST_CHECK(x != ev.blue_integer);
# endif
# ifdef GL_DEPTH_COMPONENT
	BOOST_CHECK(x != ev.depth_component);
# endif
# ifdef GL_DEPTH_STENCIL
	BOOST_CHECK(x != ev.depth_stencil);
# endif
# ifdef GL_GREEN
	BOOST_CHECK(x != ev.green);
# endif
# ifdef GL_GREEN_INTEGER
	BOOST_CHECK(x != ev.green_integer);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RED_INTEGER
	BOOST_CHECK(x != ev.red_integer);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG_INTEGER
	BOOST_CHECK(x != ev.rg_integer);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB_INTEGER
	BOOST_CHECK(x != ev.rgb_integer);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
	BOOST_CHECK(x == ev.rgba_integer);
# ifdef GL_STENCIL_INDEX
	BOOST_CHECK(x != ev.stencil_index);
# endif
#endif

#ifdef GL_STENCIL_INDEX
	x = ev.stencil_index;
# ifdef GL_BGR
	BOOST_CHECK(x != ev.bgr);
# endif
# ifdef GL_BGR_INTEGER
	BOOST_CHECK(x != ev.bgr_integer);
# endif
# ifdef GL_BGRA
	BOOST_CHECK(x != ev.bgra);
# endif
# ifdef GL_BGRA_INTEGER
	BOOST_CHECK(x != ev.bgra_integer);
# endif
# ifdef GL_BLUE
	BOOST_CHECK(x != ev.blue);
# endif
# ifdef GL_BLUE_INTEGER
	BOOST_CHECK(x != ev.blue_integer);
# endif
# ifdef GL_DEPTH_COMPONENT
	BOOST_CHECK(x != ev.depth_component);
# endif
# ifdef GL_DEPTH_STENCIL
	BOOST_CHECK(x != ev.depth_stencil);
# endif
# ifdef GL_GREEN
	BOOST_CHECK(x != ev.green);
# endif
# ifdef GL_GREEN_INTEGER
	BOOST_CHECK(x != ev.green_integer);
# endif
# ifdef GL_RED
	BOOST_CHECK(x != ev.red);
# endif
# ifdef GL_RED_INTEGER
	BOOST_CHECK(x != ev.red_integer);
# endif
# ifdef GL_RG
	BOOST_CHECK(x != ev.rg);
# endif
# ifdef GL_RG_INTEGER
	BOOST_CHECK(x != ev.rg_integer);
# endif
# ifdef GL_RGB
	BOOST_CHECK(x != ev.rgb);
# endif
# ifdef GL_RGB_INTEGER
	BOOST_CHECK(x != ev.rgb_integer);
# endif
# ifdef GL_RGBA
	BOOST_CHECK(x != ev.rgba);
# endif
# ifdef GL_RGBA_INTEGER
	BOOST_CHECK(x != ev.rgba_integer);
# endif
	BOOST_CHECK(x == ev.stencil_index);
#endif
}

BOOST_AUTO_TEST_CASE(enum_pixel_data_format_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	pixel_data_format x;
	(void)x;

#ifdef GL_BGR
	x = ev.bgr;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"BGR"
	) == 0);
#endif

#ifdef GL_BGR_INTEGER
	x = ev.bgr_integer;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"BGR_INTEGER"
	) == 0);
#endif

#ifdef GL_BGRA
	x = ev.bgra;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"BGRA"
	) == 0);
#endif

#ifdef GL_BGRA_INTEGER
	x = ev.bgra_integer;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"BGRA_INTEGER"
	) == 0);
#endif

#ifdef GL_BLUE
	x = ev.blue;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"BLUE"
	) == 0);
#endif

#ifdef GL_BLUE_INTEGER
	x = ev.blue_integer;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"BLUE_INTEGER"
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

#ifdef GL_DEPTH_STENCIL
	x = ev.depth_stencil;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DEPTH_STENCIL"
	) == 0);
#endif

#ifdef GL_GREEN
	x = ev.green;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"GREEN"
	) == 0);
#endif

#ifdef GL_GREEN_INTEGER
	x = ev.green_integer;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"GREEN_INTEGER"
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

#ifdef GL_RED_INTEGER
	x = ev.red_integer;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RED_INTEGER"
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

#ifdef GL_RG_INTEGER
	x = ev.rg_integer;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RG_INTEGER"
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

#ifdef GL_RGB_INTEGER
	x = ev.rgb_integer;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RGB_INTEGER"
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

#ifdef GL_RGBA_INTEGER
	x = ev.rgba_integer;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RGBA_INTEGER"
	) == 0);
#endif

#ifdef GL_STENCIL_INDEX
	x = ev.stencil_index;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"STENCIL_INDEX"
	) == 0);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
