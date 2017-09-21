//  File test/boost_test/eglplus/enums/vg_colorspace.cpp
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
#include "common.hpp"
#define BOOST_TEST_MODULE EGLPLUS_vg_colorspace

#include "../../unit_test_begin.inl"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_vg_colorspace_tests)

BOOST_AUTO_TEST_CASE(enum_vg_colorspace_values)
{
	using namespace eglplus;
	enum_values ev;
	EAGINE_MAYBE_UNUSED(ev);
	vg_colorspace x;
	EAGINE_MAYBE_UNUSED(x);

#ifdef EGL_VG_COLORSPACE_LINEAR
	x = ev.vg_colorspace_linear;
	BOOST_CHECK(x == ev.vg_colorspace_linear);
# ifdef EGL_VG_COLORSPACE_sRGB
	BOOST_CHECK(x != ev.vg_colorspace_srgb);
# endif
#endif

#ifdef EGL_VG_COLORSPACE_sRGB
	x = ev.vg_colorspace_srgb;
	BOOST_CHECK(x == ev.vg_colorspace_srgb);
#endif
}

BOOST_AUTO_TEST_CASE(enum_vg_colorspace_names)
{
	using namespace eglplus;
	enum_values ev;
	EAGINE_MAYBE_UNUSED(ev);
	vg_colorspace x;
	EAGINE_MAYBE_UNUSED(x);

#ifdef EGL_VG_COLORSPACE_LINEAR
	x = ev.vg_colorspace_linear;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"VG_COLORSPACE_LINEAR"
	) == 0);
#endif

#ifdef EGL_VG_COLORSPACE_sRGB
	x = ev.vg_colorspace_srgb;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"VG_COLORSPACE_sRGB"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_vg_colorspace_range)
{
	using namespace eglplus;
	auto count = enum_value_range<vg_colorspace>().size();

#ifdef EGL_VG_COLORSPACE_LINEAR
{
	--count;
	auto r = enum_value_range<vg_colorspace>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		vg_colorspace(EGL_VG_COLORSPACE_LINEAR)
	) != r.end());
}
#endif

#ifdef EGL_VG_COLORSPACE_sRGB
{
	--count;
	auto r = enum_value_range<vg_colorspace>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		vg_colorspace(EGL_VG_COLORSPACE_sRGB)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_vg_colorspace_any)
{
	using namespace eglplus;
	enum_values ev;
	EAGINE_MAYBE_UNUSED(ev);
	vg_colorspace x, y;
	EAGINE_MAYBE_UNUSED(x);
	EAGINE_MAYBE_UNUSED(y);
	any_enum_value a;
	EAGINE_MAYBE_UNUSED(a);

#ifdef EGL_VG_COLORSPACE_LINEAR
	x = ev.vg_colorspace_linear;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.vg_colorspace_linear);
#endif

#ifdef EGL_VG_COLORSPACE_sRGB
	x = ev.vg_colorspace_srgb;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.vg_colorspace_srgb);
#endif
}

BOOST_AUTO_TEST_SUITE_END()

#include "../../unit_test_end.inl"
