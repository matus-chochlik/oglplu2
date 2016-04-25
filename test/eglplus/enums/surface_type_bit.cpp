//  File test/eglplus/enums/surface_type_bit.cpp
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
#define BOOST_TEST_MODULE EGLPLUS_surface_type_bit

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_surface_type_bit_tests)

BOOST_AUTO_TEST_CASE(enum_surface_type_bit_values)
{
	using namespace eglplus;
	enum_values ev;
	(void)ev;
	surface_type_bit x;
	(void)x;

#ifdef EGL_MULTISAMPLE_RESOLVE_BOX_BIT
	x = ev.multisample_resolve_box_bit;
	BOOST_CHECK(x == ev.multisample_resolve_box_bit);
# ifdef EGL_PBUFFER_BIT
	BOOST_CHECK(x != ev.pbuffer_bit);
# endif
# ifdef EGL_PIXMAP_BIT
	BOOST_CHECK(x != ev.pixmap_bit);
# endif
# ifdef EGL_SWAP_BEHAVIOR_PRESERVED_BIT
	BOOST_CHECK(x != ev.swap_behavior_preserved_bit);
# endif
# ifdef EGL_VG_ALPHA_FORMAT_PRE_BIT
	BOOST_CHECK(x != ev.vg_alpha_format_pre_bit);
# endif
# ifdef EGL_VG_COLORSPACE_LINEAR_BIT
	BOOST_CHECK(x != ev.vg_colorspace_linear_bit);
# endif
# ifdef EGL_WINDOW_BIT
	BOOST_CHECK(x != ev.window_bit);
# endif
#endif

#ifdef EGL_PBUFFER_BIT
	x = ev.pbuffer_bit;
	BOOST_CHECK(x == ev.pbuffer_bit);
# ifdef EGL_PIXMAP_BIT
	BOOST_CHECK(x != ev.pixmap_bit);
# endif
# ifdef EGL_SWAP_BEHAVIOR_PRESERVED_BIT
	BOOST_CHECK(x != ev.swap_behavior_preserved_bit);
# endif
# ifdef EGL_VG_ALPHA_FORMAT_PRE_BIT
	BOOST_CHECK(x != ev.vg_alpha_format_pre_bit);
# endif
# ifdef EGL_VG_COLORSPACE_LINEAR_BIT
	BOOST_CHECK(x != ev.vg_colorspace_linear_bit);
# endif
# ifdef EGL_WINDOW_BIT
	BOOST_CHECK(x != ev.window_bit);
# endif
#endif

#ifdef EGL_PIXMAP_BIT
	x = ev.pixmap_bit;
	BOOST_CHECK(x == ev.pixmap_bit);
# ifdef EGL_SWAP_BEHAVIOR_PRESERVED_BIT
	BOOST_CHECK(x != ev.swap_behavior_preserved_bit);
# endif
# ifdef EGL_VG_ALPHA_FORMAT_PRE_BIT
	BOOST_CHECK(x != ev.vg_alpha_format_pre_bit);
# endif
# ifdef EGL_VG_COLORSPACE_LINEAR_BIT
	BOOST_CHECK(x != ev.vg_colorspace_linear_bit);
# endif
# ifdef EGL_WINDOW_BIT
	BOOST_CHECK(x != ev.window_bit);
# endif
#endif

#ifdef EGL_SWAP_BEHAVIOR_PRESERVED_BIT
	x = ev.swap_behavior_preserved_bit;
	BOOST_CHECK(x == ev.swap_behavior_preserved_bit);
# ifdef EGL_VG_ALPHA_FORMAT_PRE_BIT
	BOOST_CHECK(x != ev.vg_alpha_format_pre_bit);
# endif
# ifdef EGL_VG_COLORSPACE_LINEAR_BIT
	BOOST_CHECK(x != ev.vg_colorspace_linear_bit);
# endif
# ifdef EGL_WINDOW_BIT
	BOOST_CHECK(x != ev.window_bit);
# endif
#endif

#ifdef EGL_VG_ALPHA_FORMAT_PRE_BIT
	x = ev.vg_alpha_format_pre_bit;
	BOOST_CHECK(x == ev.vg_alpha_format_pre_bit);
# ifdef EGL_VG_COLORSPACE_LINEAR_BIT
	BOOST_CHECK(x != ev.vg_colorspace_linear_bit);
# endif
# ifdef EGL_WINDOW_BIT
	BOOST_CHECK(x != ev.window_bit);
# endif
#endif

#ifdef EGL_VG_COLORSPACE_LINEAR_BIT
	x = ev.vg_colorspace_linear_bit;
	BOOST_CHECK(x == ev.vg_colorspace_linear_bit);
# ifdef EGL_WINDOW_BIT
	BOOST_CHECK(x != ev.window_bit);
# endif
#endif

#ifdef EGL_WINDOW_BIT
	x = ev.window_bit;
	BOOST_CHECK(x == ev.window_bit);
#endif
}

BOOST_AUTO_TEST_CASE(enum_surface_type_bit_names)
{
	using namespace eglplus;
	enum_values ev;
	(void)ev;
	surface_type_bit x;
	(void)x;

#ifdef EGL_MULTISAMPLE_RESOLVE_BOX_BIT
	x = ev.multisample_resolve_box_bit;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MULTISAMPLE_RESOLVE_BOX_BIT"
	) == 0);
#endif

#ifdef EGL_PBUFFER_BIT
	x = ev.pbuffer_bit;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PBUFFER_BIT"
	) == 0);
#endif

#ifdef EGL_PIXMAP_BIT
	x = ev.pixmap_bit;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PIXMAP_BIT"
	) == 0);
#endif

#ifdef EGL_SWAP_BEHAVIOR_PRESERVED_BIT
	x = ev.swap_behavior_preserved_bit;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SWAP_BEHAVIOR_PRESERVED_BIT"
	) == 0);
#endif

#ifdef EGL_VG_ALPHA_FORMAT_PRE_BIT
	x = ev.vg_alpha_format_pre_bit;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"VG_ALPHA_FORMAT_PRE_BIT"
	) == 0);
#endif

#ifdef EGL_VG_COLORSPACE_LINEAR_BIT
	x = ev.vg_colorspace_linear_bit;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"VG_COLORSPACE_LINEAR_BIT"
	) == 0);
#endif

#ifdef EGL_WINDOW_BIT
	x = ev.window_bit;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"WINDOW_BIT"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_surface_type_bit_range)
{
	using namespace eglplus;
	auto count = enum_value_range<surface_type_bit>().size();

#ifdef EGL_MULTISAMPLE_RESOLVE_BOX_BIT
{
	--count;
	auto r = enum_value_range<surface_type_bit>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		surface_type_bit(EGL_MULTISAMPLE_RESOLVE_BOX_BIT)
	) != r.end());
}
#endif

#ifdef EGL_PBUFFER_BIT
{
	--count;
	auto r = enum_value_range<surface_type_bit>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		surface_type_bit(EGL_PBUFFER_BIT)
	) != r.end());
}
#endif

#ifdef EGL_PIXMAP_BIT
{
	--count;
	auto r = enum_value_range<surface_type_bit>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		surface_type_bit(EGL_PIXMAP_BIT)
	) != r.end());
}
#endif

#ifdef EGL_SWAP_BEHAVIOR_PRESERVED_BIT
{
	--count;
	auto r = enum_value_range<surface_type_bit>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		surface_type_bit(EGL_SWAP_BEHAVIOR_PRESERVED_BIT)
	) != r.end());
}
#endif

#ifdef EGL_VG_ALPHA_FORMAT_PRE_BIT
{
	--count;
	auto r = enum_value_range<surface_type_bit>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		surface_type_bit(EGL_VG_ALPHA_FORMAT_PRE_BIT)
	) != r.end());
}
#endif

#ifdef EGL_VG_COLORSPACE_LINEAR_BIT
{
	--count;
	auto r = enum_value_range<surface_type_bit>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		surface_type_bit(EGL_VG_COLORSPACE_LINEAR_BIT)
	) != r.end());
}
#endif

#ifdef EGL_WINDOW_BIT
{
	--count;
	auto r = enum_value_range<surface_type_bit>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		surface_type_bit(EGL_WINDOW_BIT)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_surface_type_bit_any)
{
	using namespace eglplus;
	enum_values ev;
	(void)ev;
	surface_type_bit x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef EGL_MULTISAMPLE_RESOLVE_BOX_BIT
	x = ev.multisample_resolve_box_bit;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.multisample_resolve_box_bit);
#endif

#ifdef EGL_PBUFFER_BIT
	x = ev.pbuffer_bit;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.pbuffer_bit);
#endif

#ifdef EGL_PIXMAP_BIT
	x = ev.pixmap_bit;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.pixmap_bit);
#endif

#ifdef EGL_SWAP_BEHAVIOR_PRESERVED_BIT
	x = ev.swap_behavior_preserved_bit;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.swap_behavior_preserved_bit);
#endif

#ifdef EGL_VG_ALPHA_FORMAT_PRE_BIT
	x = ev.vg_alpha_format_pre_bit;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.vg_alpha_format_pre_bit);
#endif

#ifdef EGL_VG_COLORSPACE_LINEAR_BIT
	x = ev.vg_colorspace_linear_bit;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.vg_colorspace_linear_bit);
#endif

#ifdef EGL_WINDOW_BIT
	x = ev.window_bit;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.window_bit);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
