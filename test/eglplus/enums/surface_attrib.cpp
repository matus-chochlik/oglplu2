//  File test/eglplus/enums/surface_attrib.cpp
//
//  Automatically generated file, DO NOT modify manually.
//  Edit the enumeration source files in 'source/enums/eglplus'
//  or the 'source/enums/make_enum.py' script instead.
//
//  Copyright Matus Chochlik.
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//   http://www.boost.org/LICENSE_1_0.txt
//
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EGLPLUS_surface_attrib

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_surface_attrib_tests)

BOOST_AUTO_TEST_CASE(enum_surface_attrib_values)
{
	using namespace eglplus;
	enum_values ev;
	(void)ev;
	surface_attrib x;
	(void)x;

#ifdef EGL_CONFIG_ID
	x = ev.config_id;
	BOOST_CHECK(x == ev.config_id);
# ifdef EGL_GL_COLORSPACE
	BOOST_CHECK(x != ev.gl_colorspace);
# endif
# ifdef EGL_HEIGHT
	BOOST_CHECK(x != ev.height);
# endif
# ifdef EGL_HORIZONTAL_RESOLUTION
	BOOST_CHECK(x != ev.horizontal_resolution);
# endif
# ifdef EGL_LARGEST_PBUFFER
	BOOST_CHECK(x != ev.largest_pbuffer);
# endif
# ifdef EGL_MIPMAP_LEVEL
	BOOST_CHECK(x != ev.mipmap_level);
# endif
# ifdef EGL_MIPMAP_TEXTURE
	BOOST_CHECK(x != ev.mipmap_texture);
# endif
# ifdef EGL_MULTISAMPLE_RESOLVE
	BOOST_CHECK(x != ev.multisample_resolve);
# endif
# ifdef EGL_PIXEL_ASPECT_RATIO
	BOOST_CHECK(x != ev.pixel_aspect_ratio);
# endif
# ifdef EGL_RENDER_BUFFER
	BOOST_CHECK(x != ev.render_buffer);
# endif
# ifdef EGL_SWAP_BEHAVIOR
	BOOST_CHECK(x != ev.swap_behavior);
# endif
# ifdef EGL_TEXTURE_FORMAT
	BOOST_CHECK(x != ev.texture_format);
# endif
# ifdef EGL_TEXTURE_TARGET
	BOOST_CHECK(x != ev.texture_target);
# endif
# ifdef EGL_VERTICAL_RESOLUTION
	BOOST_CHECK(x != ev.vertical_resolution);
# endif
# ifdef EGL_VG_ALPHA_FORMAT
	BOOST_CHECK(x != ev.vg_alpha_format);
# endif
# ifdef EGL_VG_COLORSPACE
	BOOST_CHECK(x != ev.vg_colorspace);
# endif
# ifdef EGL_WIDTH
	BOOST_CHECK(x != ev.width);
# endif
#endif

#ifdef EGL_GL_COLORSPACE
	x = ev.gl_colorspace;
	BOOST_CHECK(x == ev.gl_colorspace);
# ifdef EGL_HEIGHT
	BOOST_CHECK(x != ev.height);
# endif
# ifdef EGL_HORIZONTAL_RESOLUTION
	BOOST_CHECK(x != ev.horizontal_resolution);
# endif
# ifdef EGL_LARGEST_PBUFFER
	BOOST_CHECK(x != ev.largest_pbuffer);
# endif
# ifdef EGL_MIPMAP_LEVEL
	BOOST_CHECK(x != ev.mipmap_level);
# endif
# ifdef EGL_MIPMAP_TEXTURE
	BOOST_CHECK(x != ev.mipmap_texture);
# endif
# ifdef EGL_MULTISAMPLE_RESOLVE
	BOOST_CHECK(x != ev.multisample_resolve);
# endif
# ifdef EGL_PIXEL_ASPECT_RATIO
	BOOST_CHECK(x != ev.pixel_aspect_ratio);
# endif
# ifdef EGL_RENDER_BUFFER
	BOOST_CHECK(x != ev.render_buffer);
# endif
# ifdef EGL_SWAP_BEHAVIOR
	BOOST_CHECK(x != ev.swap_behavior);
# endif
# ifdef EGL_TEXTURE_FORMAT
	BOOST_CHECK(x != ev.texture_format);
# endif
# ifdef EGL_TEXTURE_TARGET
	BOOST_CHECK(x != ev.texture_target);
# endif
# ifdef EGL_VERTICAL_RESOLUTION
	BOOST_CHECK(x != ev.vertical_resolution);
# endif
# ifdef EGL_VG_ALPHA_FORMAT
	BOOST_CHECK(x != ev.vg_alpha_format);
# endif
# ifdef EGL_VG_COLORSPACE
	BOOST_CHECK(x != ev.vg_colorspace);
# endif
# ifdef EGL_WIDTH
	BOOST_CHECK(x != ev.width);
# endif
#endif

#ifdef EGL_HEIGHT
	x = ev.height;
	BOOST_CHECK(x == ev.height);
# ifdef EGL_HORIZONTAL_RESOLUTION
	BOOST_CHECK(x != ev.horizontal_resolution);
# endif
# ifdef EGL_LARGEST_PBUFFER
	BOOST_CHECK(x != ev.largest_pbuffer);
# endif
# ifdef EGL_MIPMAP_LEVEL
	BOOST_CHECK(x != ev.mipmap_level);
# endif
# ifdef EGL_MIPMAP_TEXTURE
	BOOST_CHECK(x != ev.mipmap_texture);
# endif
# ifdef EGL_MULTISAMPLE_RESOLVE
	BOOST_CHECK(x != ev.multisample_resolve);
# endif
# ifdef EGL_PIXEL_ASPECT_RATIO
	BOOST_CHECK(x != ev.pixel_aspect_ratio);
# endif
# ifdef EGL_RENDER_BUFFER
	BOOST_CHECK(x != ev.render_buffer);
# endif
# ifdef EGL_SWAP_BEHAVIOR
	BOOST_CHECK(x != ev.swap_behavior);
# endif
# ifdef EGL_TEXTURE_FORMAT
	BOOST_CHECK(x != ev.texture_format);
# endif
# ifdef EGL_TEXTURE_TARGET
	BOOST_CHECK(x != ev.texture_target);
# endif
# ifdef EGL_VERTICAL_RESOLUTION
	BOOST_CHECK(x != ev.vertical_resolution);
# endif
# ifdef EGL_VG_ALPHA_FORMAT
	BOOST_CHECK(x != ev.vg_alpha_format);
# endif
# ifdef EGL_VG_COLORSPACE
	BOOST_CHECK(x != ev.vg_colorspace);
# endif
# ifdef EGL_WIDTH
	BOOST_CHECK(x != ev.width);
# endif
#endif

#ifdef EGL_HORIZONTAL_RESOLUTION
	x = ev.horizontal_resolution;
	BOOST_CHECK(x == ev.horizontal_resolution);
# ifdef EGL_LARGEST_PBUFFER
	BOOST_CHECK(x != ev.largest_pbuffer);
# endif
# ifdef EGL_MIPMAP_LEVEL
	BOOST_CHECK(x != ev.mipmap_level);
# endif
# ifdef EGL_MIPMAP_TEXTURE
	BOOST_CHECK(x != ev.mipmap_texture);
# endif
# ifdef EGL_MULTISAMPLE_RESOLVE
	BOOST_CHECK(x != ev.multisample_resolve);
# endif
# ifdef EGL_PIXEL_ASPECT_RATIO
	BOOST_CHECK(x != ev.pixel_aspect_ratio);
# endif
# ifdef EGL_RENDER_BUFFER
	BOOST_CHECK(x != ev.render_buffer);
# endif
# ifdef EGL_SWAP_BEHAVIOR
	BOOST_CHECK(x != ev.swap_behavior);
# endif
# ifdef EGL_TEXTURE_FORMAT
	BOOST_CHECK(x != ev.texture_format);
# endif
# ifdef EGL_TEXTURE_TARGET
	BOOST_CHECK(x != ev.texture_target);
# endif
# ifdef EGL_VERTICAL_RESOLUTION
	BOOST_CHECK(x != ev.vertical_resolution);
# endif
# ifdef EGL_VG_ALPHA_FORMAT
	BOOST_CHECK(x != ev.vg_alpha_format);
# endif
# ifdef EGL_VG_COLORSPACE
	BOOST_CHECK(x != ev.vg_colorspace);
# endif
# ifdef EGL_WIDTH
	BOOST_CHECK(x != ev.width);
# endif
#endif

#ifdef EGL_LARGEST_PBUFFER
	x = ev.largest_pbuffer;
	BOOST_CHECK(x == ev.largest_pbuffer);
# ifdef EGL_MIPMAP_LEVEL
	BOOST_CHECK(x != ev.mipmap_level);
# endif
# ifdef EGL_MIPMAP_TEXTURE
	BOOST_CHECK(x != ev.mipmap_texture);
# endif
# ifdef EGL_MULTISAMPLE_RESOLVE
	BOOST_CHECK(x != ev.multisample_resolve);
# endif
# ifdef EGL_PIXEL_ASPECT_RATIO
	BOOST_CHECK(x != ev.pixel_aspect_ratio);
# endif
# ifdef EGL_RENDER_BUFFER
	BOOST_CHECK(x != ev.render_buffer);
# endif
# ifdef EGL_SWAP_BEHAVIOR
	BOOST_CHECK(x != ev.swap_behavior);
# endif
# ifdef EGL_TEXTURE_FORMAT
	BOOST_CHECK(x != ev.texture_format);
# endif
# ifdef EGL_TEXTURE_TARGET
	BOOST_CHECK(x != ev.texture_target);
# endif
# ifdef EGL_VERTICAL_RESOLUTION
	BOOST_CHECK(x != ev.vertical_resolution);
# endif
# ifdef EGL_VG_ALPHA_FORMAT
	BOOST_CHECK(x != ev.vg_alpha_format);
# endif
# ifdef EGL_VG_COLORSPACE
	BOOST_CHECK(x != ev.vg_colorspace);
# endif
# ifdef EGL_WIDTH
	BOOST_CHECK(x != ev.width);
# endif
#endif

#ifdef EGL_MIPMAP_LEVEL
	x = ev.mipmap_level;
	BOOST_CHECK(x == ev.mipmap_level);
# ifdef EGL_MIPMAP_TEXTURE
	BOOST_CHECK(x != ev.mipmap_texture);
# endif
# ifdef EGL_MULTISAMPLE_RESOLVE
	BOOST_CHECK(x != ev.multisample_resolve);
# endif
# ifdef EGL_PIXEL_ASPECT_RATIO
	BOOST_CHECK(x != ev.pixel_aspect_ratio);
# endif
# ifdef EGL_RENDER_BUFFER
	BOOST_CHECK(x != ev.render_buffer);
# endif
# ifdef EGL_SWAP_BEHAVIOR
	BOOST_CHECK(x != ev.swap_behavior);
# endif
# ifdef EGL_TEXTURE_FORMAT
	BOOST_CHECK(x != ev.texture_format);
# endif
# ifdef EGL_TEXTURE_TARGET
	BOOST_CHECK(x != ev.texture_target);
# endif
# ifdef EGL_VERTICAL_RESOLUTION
	BOOST_CHECK(x != ev.vertical_resolution);
# endif
# ifdef EGL_VG_ALPHA_FORMAT
	BOOST_CHECK(x != ev.vg_alpha_format);
# endif
# ifdef EGL_VG_COLORSPACE
	BOOST_CHECK(x != ev.vg_colorspace);
# endif
# ifdef EGL_WIDTH
	BOOST_CHECK(x != ev.width);
# endif
#endif

#ifdef EGL_MIPMAP_TEXTURE
	x = ev.mipmap_texture;
	BOOST_CHECK(x == ev.mipmap_texture);
# ifdef EGL_MULTISAMPLE_RESOLVE
	BOOST_CHECK(x != ev.multisample_resolve);
# endif
# ifdef EGL_PIXEL_ASPECT_RATIO
	BOOST_CHECK(x != ev.pixel_aspect_ratio);
# endif
# ifdef EGL_RENDER_BUFFER
	BOOST_CHECK(x != ev.render_buffer);
# endif
# ifdef EGL_SWAP_BEHAVIOR
	BOOST_CHECK(x != ev.swap_behavior);
# endif
# ifdef EGL_TEXTURE_FORMAT
	BOOST_CHECK(x != ev.texture_format);
# endif
# ifdef EGL_TEXTURE_TARGET
	BOOST_CHECK(x != ev.texture_target);
# endif
# ifdef EGL_VERTICAL_RESOLUTION
	BOOST_CHECK(x != ev.vertical_resolution);
# endif
# ifdef EGL_VG_ALPHA_FORMAT
	BOOST_CHECK(x != ev.vg_alpha_format);
# endif
# ifdef EGL_VG_COLORSPACE
	BOOST_CHECK(x != ev.vg_colorspace);
# endif
# ifdef EGL_WIDTH
	BOOST_CHECK(x != ev.width);
# endif
#endif

#ifdef EGL_MULTISAMPLE_RESOLVE
	x = ev.multisample_resolve;
	BOOST_CHECK(x == ev.multisample_resolve);
# ifdef EGL_PIXEL_ASPECT_RATIO
	BOOST_CHECK(x != ev.pixel_aspect_ratio);
# endif
# ifdef EGL_RENDER_BUFFER
	BOOST_CHECK(x != ev.render_buffer);
# endif
# ifdef EGL_SWAP_BEHAVIOR
	BOOST_CHECK(x != ev.swap_behavior);
# endif
# ifdef EGL_TEXTURE_FORMAT
	BOOST_CHECK(x != ev.texture_format);
# endif
# ifdef EGL_TEXTURE_TARGET
	BOOST_CHECK(x != ev.texture_target);
# endif
# ifdef EGL_VERTICAL_RESOLUTION
	BOOST_CHECK(x != ev.vertical_resolution);
# endif
# ifdef EGL_VG_ALPHA_FORMAT
	BOOST_CHECK(x != ev.vg_alpha_format);
# endif
# ifdef EGL_VG_COLORSPACE
	BOOST_CHECK(x != ev.vg_colorspace);
# endif
# ifdef EGL_WIDTH
	BOOST_CHECK(x != ev.width);
# endif
#endif

#ifdef EGL_PIXEL_ASPECT_RATIO
	x = ev.pixel_aspect_ratio;
	BOOST_CHECK(x == ev.pixel_aspect_ratio);
# ifdef EGL_RENDER_BUFFER
	BOOST_CHECK(x != ev.render_buffer);
# endif
# ifdef EGL_SWAP_BEHAVIOR
	BOOST_CHECK(x != ev.swap_behavior);
# endif
# ifdef EGL_TEXTURE_FORMAT
	BOOST_CHECK(x != ev.texture_format);
# endif
# ifdef EGL_TEXTURE_TARGET
	BOOST_CHECK(x != ev.texture_target);
# endif
# ifdef EGL_VERTICAL_RESOLUTION
	BOOST_CHECK(x != ev.vertical_resolution);
# endif
# ifdef EGL_VG_ALPHA_FORMAT
	BOOST_CHECK(x != ev.vg_alpha_format);
# endif
# ifdef EGL_VG_COLORSPACE
	BOOST_CHECK(x != ev.vg_colorspace);
# endif
# ifdef EGL_WIDTH
	BOOST_CHECK(x != ev.width);
# endif
#endif

#ifdef EGL_RENDER_BUFFER
	x = ev.render_buffer;
	BOOST_CHECK(x == ev.render_buffer);
# ifdef EGL_SWAP_BEHAVIOR
	BOOST_CHECK(x != ev.swap_behavior);
# endif
# ifdef EGL_TEXTURE_FORMAT
	BOOST_CHECK(x != ev.texture_format);
# endif
# ifdef EGL_TEXTURE_TARGET
	BOOST_CHECK(x != ev.texture_target);
# endif
# ifdef EGL_VERTICAL_RESOLUTION
	BOOST_CHECK(x != ev.vertical_resolution);
# endif
# ifdef EGL_VG_ALPHA_FORMAT
	BOOST_CHECK(x != ev.vg_alpha_format);
# endif
# ifdef EGL_VG_COLORSPACE
	BOOST_CHECK(x != ev.vg_colorspace);
# endif
# ifdef EGL_WIDTH
	BOOST_CHECK(x != ev.width);
# endif
#endif

#ifdef EGL_SWAP_BEHAVIOR
	x = ev.swap_behavior;
	BOOST_CHECK(x == ev.swap_behavior);
# ifdef EGL_TEXTURE_FORMAT
	BOOST_CHECK(x != ev.texture_format);
# endif
# ifdef EGL_TEXTURE_TARGET
	BOOST_CHECK(x != ev.texture_target);
# endif
# ifdef EGL_VERTICAL_RESOLUTION
	BOOST_CHECK(x != ev.vertical_resolution);
# endif
# ifdef EGL_VG_ALPHA_FORMAT
	BOOST_CHECK(x != ev.vg_alpha_format);
# endif
# ifdef EGL_VG_COLORSPACE
	BOOST_CHECK(x != ev.vg_colorspace);
# endif
# ifdef EGL_WIDTH
	BOOST_CHECK(x != ev.width);
# endif
#endif

#ifdef EGL_TEXTURE_FORMAT
	x = ev.texture_format;
	BOOST_CHECK(x == ev.texture_format);
# ifdef EGL_TEXTURE_TARGET
	BOOST_CHECK(x != ev.texture_target);
# endif
# ifdef EGL_VERTICAL_RESOLUTION
	BOOST_CHECK(x != ev.vertical_resolution);
# endif
# ifdef EGL_VG_ALPHA_FORMAT
	BOOST_CHECK(x != ev.vg_alpha_format);
# endif
# ifdef EGL_VG_COLORSPACE
	BOOST_CHECK(x != ev.vg_colorspace);
# endif
# ifdef EGL_WIDTH
	BOOST_CHECK(x != ev.width);
# endif
#endif

#ifdef EGL_TEXTURE_TARGET
	x = ev.texture_target;
	BOOST_CHECK(x == ev.texture_target);
# ifdef EGL_VERTICAL_RESOLUTION
	BOOST_CHECK(x != ev.vertical_resolution);
# endif
# ifdef EGL_VG_ALPHA_FORMAT
	BOOST_CHECK(x != ev.vg_alpha_format);
# endif
# ifdef EGL_VG_COLORSPACE
	BOOST_CHECK(x != ev.vg_colorspace);
# endif
# ifdef EGL_WIDTH
	BOOST_CHECK(x != ev.width);
# endif
#endif

#ifdef EGL_VERTICAL_RESOLUTION
	x = ev.vertical_resolution;
	BOOST_CHECK(x == ev.vertical_resolution);
# ifdef EGL_VG_ALPHA_FORMAT
	BOOST_CHECK(x != ev.vg_alpha_format);
# endif
# ifdef EGL_VG_COLORSPACE
	BOOST_CHECK(x != ev.vg_colorspace);
# endif
# ifdef EGL_WIDTH
	BOOST_CHECK(x != ev.width);
# endif
#endif

#ifdef EGL_VG_ALPHA_FORMAT
	x = ev.vg_alpha_format;
	BOOST_CHECK(x == ev.vg_alpha_format);
# ifdef EGL_VG_COLORSPACE
	BOOST_CHECK(x != ev.vg_colorspace);
# endif
# ifdef EGL_WIDTH
	BOOST_CHECK(x != ev.width);
# endif
#endif

#ifdef EGL_VG_COLORSPACE
	x = ev.vg_colorspace;
	BOOST_CHECK(x == ev.vg_colorspace);
# ifdef EGL_WIDTH
	BOOST_CHECK(x != ev.width);
# endif
#endif

#ifdef EGL_WIDTH
	x = ev.width;
	BOOST_CHECK(x == ev.width);
#endif
}

BOOST_AUTO_TEST_CASE(enum_surface_attrib_names)
{
	using namespace eglplus;
	enum_values ev;
	(void)ev;
	surface_attrib x;
	(void)x;

#ifdef EGL_CONFIG_ID
	x = ev.config_id;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"CONFIG_ID"
	) == 0);
#endif

#ifdef EGL_GL_COLORSPACE
	x = ev.gl_colorspace;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"GL_COLORSPACE"
	) == 0);
#endif

#ifdef EGL_HEIGHT
	x = ev.height;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"HEIGHT"
	) == 0);
#endif

#ifdef EGL_HORIZONTAL_RESOLUTION
	x = ev.horizontal_resolution;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"HORIZONTAL_RESOLUTION"
	) == 0);
#endif

#ifdef EGL_LARGEST_PBUFFER
	x = ev.largest_pbuffer;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"LARGEST_PBUFFER"
	) == 0);
#endif

#ifdef EGL_MIPMAP_LEVEL
	x = ev.mipmap_level;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MIPMAP_LEVEL"
	) == 0);
#endif

#ifdef EGL_MIPMAP_TEXTURE
	x = ev.mipmap_texture;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MIPMAP_TEXTURE"
	) == 0);
#endif

#ifdef EGL_MULTISAMPLE_RESOLVE
	x = ev.multisample_resolve;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MULTISAMPLE_RESOLVE"
	) == 0);
#endif

#ifdef EGL_PIXEL_ASPECT_RATIO
	x = ev.pixel_aspect_ratio;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PIXEL_ASPECT_RATIO"
	) == 0);
#endif

#ifdef EGL_RENDER_BUFFER
	x = ev.render_buffer;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RENDER_BUFFER"
	) == 0);
#endif

#ifdef EGL_SWAP_BEHAVIOR
	x = ev.swap_behavior;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SWAP_BEHAVIOR"
	) == 0);
#endif

#ifdef EGL_TEXTURE_FORMAT
	x = ev.texture_format;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_FORMAT"
	) == 0);
#endif

#ifdef EGL_TEXTURE_TARGET
	x = ev.texture_target;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_TARGET"
	) == 0);
#endif

#ifdef EGL_VERTICAL_RESOLUTION
	x = ev.vertical_resolution;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"VERTICAL_RESOLUTION"
	) == 0);
#endif

#ifdef EGL_VG_ALPHA_FORMAT
	x = ev.vg_alpha_format;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"VG_ALPHA_FORMAT"
	) == 0);
#endif

#ifdef EGL_VG_COLORSPACE
	x = ev.vg_colorspace;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"VG_COLORSPACE"
	) == 0);
#endif

#ifdef EGL_WIDTH
	x = ev.width;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"WIDTH"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_surface_attrib_range)
{
	using namespace eglplus;
	auto count = enum_value_range<surface_attrib>().size();

#ifdef EGL_CONFIG_ID
{
	--count;
	auto r = enum_value_range<surface_attrib>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		surface_attrib(EGL_CONFIG_ID)
	) != r.end());
}
#endif

#ifdef EGL_GL_COLORSPACE
{
	--count;
	auto r = enum_value_range<surface_attrib>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		surface_attrib(EGL_GL_COLORSPACE)
	) != r.end());
}
#endif

#ifdef EGL_HEIGHT
{
	--count;
	auto r = enum_value_range<surface_attrib>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		surface_attrib(EGL_HEIGHT)
	) != r.end());
}
#endif

#ifdef EGL_HORIZONTAL_RESOLUTION
{
	--count;
	auto r = enum_value_range<surface_attrib>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		surface_attrib(EGL_HORIZONTAL_RESOLUTION)
	) != r.end());
}
#endif

#ifdef EGL_LARGEST_PBUFFER
{
	--count;
	auto r = enum_value_range<surface_attrib>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		surface_attrib(EGL_LARGEST_PBUFFER)
	) != r.end());
}
#endif

#ifdef EGL_MIPMAP_LEVEL
{
	--count;
	auto r = enum_value_range<surface_attrib>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		surface_attrib(EGL_MIPMAP_LEVEL)
	) != r.end());
}
#endif

#ifdef EGL_MIPMAP_TEXTURE
{
	--count;
	auto r = enum_value_range<surface_attrib>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		surface_attrib(EGL_MIPMAP_TEXTURE)
	) != r.end());
}
#endif

#ifdef EGL_MULTISAMPLE_RESOLVE
{
	--count;
	auto r = enum_value_range<surface_attrib>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		surface_attrib(EGL_MULTISAMPLE_RESOLVE)
	) != r.end());
}
#endif

#ifdef EGL_PIXEL_ASPECT_RATIO
{
	--count;
	auto r = enum_value_range<surface_attrib>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		surface_attrib(EGL_PIXEL_ASPECT_RATIO)
	) != r.end());
}
#endif

#ifdef EGL_RENDER_BUFFER
{
	--count;
	auto r = enum_value_range<surface_attrib>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		surface_attrib(EGL_RENDER_BUFFER)
	) != r.end());
}
#endif

#ifdef EGL_SWAP_BEHAVIOR
{
	--count;
	auto r = enum_value_range<surface_attrib>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		surface_attrib(EGL_SWAP_BEHAVIOR)
	) != r.end());
}
#endif

#ifdef EGL_TEXTURE_FORMAT
{
	--count;
	auto r = enum_value_range<surface_attrib>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		surface_attrib(EGL_TEXTURE_FORMAT)
	) != r.end());
}
#endif

#ifdef EGL_TEXTURE_TARGET
{
	--count;
	auto r = enum_value_range<surface_attrib>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		surface_attrib(EGL_TEXTURE_TARGET)
	) != r.end());
}
#endif

#ifdef EGL_VERTICAL_RESOLUTION
{
	--count;
	auto r = enum_value_range<surface_attrib>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		surface_attrib(EGL_VERTICAL_RESOLUTION)
	) != r.end());
}
#endif

#ifdef EGL_VG_ALPHA_FORMAT
{
	--count;
	auto r = enum_value_range<surface_attrib>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		surface_attrib(EGL_VG_ALPHA_FORMAT)
	) != r.end());
}
#endif

#ifdef EGL_VG_COLORSPACE
{
	--count;
	auto r = enum_value_range<surface_attrib>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		surface_attrib(EGL_VG_COLORSPACE)
	) != r.end());
}
#endif

#ifdef EGL_WIDTH
{
	--count;
	auto r = enum_value_range<surface_attrib>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		surface_attrib(EGL_WIDTH)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_surface_attrib_any)
{
	using namespace eglplus;
	enum_values ev;
	(void)ev;
	surface_attrib x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef EGL_CONFIG_ID
	x = ev.config_id;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.config_id);
#endif

#ifdef EGL_GL_COLORSPACE
	x = ev.gl_colorspace;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.gl_colorspace);
#endif

#ifdef EGL_HEIGHT
	x = ev.height;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.height);
#endif

#ifdef EGL_HORIZONTAL_RESOLUTION
	x = ev.horizontal_resolution;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.horizontal_resolution);
#endif

#ifdef EGL_LARGEST_PBUFFER
	x = ev.largest_pbuffer;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.largest_pbuffer);
#endif

#ifdef EGL_MIPMAP_LEVEL
	x = ev.mipmap_level;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.mipmap_level);
#endif

#ifdef EGL_MIPMAP_TEXTURE
	x = ev.mipmap_texture;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.mipmap_texture);
#endif

#ifdef EGL_MULTISAMPLE_RESOLVE
	x = ev.multisample_resolve;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.multisample_resolve);
#endif

#ifdef EGL_PIXEL_ASPECT_RATIO
	x = ev.pixel_aspect_ratio;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.pixel_aspect_ratio);
#endif

#ifdef EGL_RENDER_BUFFER
	x = ev.render_buffer;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.render_buffer);
#endif

#ifdef EGL_SWAP_BEHAVIOR
	x = ev.swap_behavior;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.swap_behavior);
#endif

#ifdef EGL_TEXTURE_FORMAT
	x = ev.texture_format;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_format);
#endif

#ifdef EGL_TEXTURE_TARGET
	x = ev.texture_target;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_target);
#endif

#ifdef EGL_VERTICAL_RESOLUTION
	x = ev.vertical_resolution;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.vertical_resolution);
#endif

#ifdef EGL_VG_ALPHA_FORMAT
	x = ev.vg_alpha_format;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.vg_alpha_format);
#endif

#ifdef EGL_VG_COLORSPACE
	x = ev.vg_colorspace;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.vg_colorspace);
#endif

#ifdef EGL_WIDTH
	x = ev.width;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.width);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
