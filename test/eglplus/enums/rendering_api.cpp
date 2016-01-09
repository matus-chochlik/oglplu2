//  File test/eglplus/enums/rendering_api.cpp
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
#define BOOST_TEST_MODULE EGLPLUS_rendering_api

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_rendering_api_tests)

BOOST_AUTO_TEST_CASE(enum_rendering_api_values)
{
	using namespace eglplus;
	enum_values ev;
	(void)ev;
	rendering_api x;
	(void)x;

#ifdef EGL_NONE
	x = ev.none;
	BOOST_CHECK(x == ev.none);
# ifdef EGL_OPENGL_API
	BOOST_CHECK(x != ev.opengl_api);
# endif
# ifdef EGL_OPENGL_ES_API
	BOOST_CHECK(x != ev.opengl_es_api);
# endif
# ifdef EGL_OPENVG_API
	BOOST_CHECK(x != ev.openvg_api);
# endif
#endif

#ifdef EGL_OPENGL_API
	x = ev.opengl_api;
	BOOST_CHECK(x == ev.opengl_api);
# ifdef EGL_OPENGL_ES_API
	BOOST_CHECK(x != ev.opengl_es_api);
# endif
# ifdef EGL_OPENVG_API
	BOOST_CHECK(x != ev.openvg_api);
# endif
#endif

#ifdef EGL_OPENGL_ES_API
	x = ev.opengl_es_api;
	BOOST_CHECK(x == ev.opengl_es_api);
# ifdef EGL_OPENVG_API
	BOOST_CHECK(x != ev.openvg_api);
# endif
#endif

#ifdef EGL_OPENVG_API
	x = ev.openvg_api;
	BOOST_CHECK(x == ev.openvg_api);
#endif
}

BOOST_AUTO_TEST_CASE(enum_rendering_api_names)
{
	using namespace eglplus;
	enum_values ev;
	(void)ev;
	rendering_api x;
	(void)x;

#ifdef EGL_NONE
	x = ev.none;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"NONE"
	) == 0);
#endif

#ifdef EGL_OPENGL_API
	x = ev.opengl_api;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"OPENGL_API"
	) == 0);
#endif

#ifdef EGL_OPENGL_ES_API
	x = ev.opengl_es_api;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"OPENGL_ES_API"
	) == 0);
#endif

#ifdef EGL_OPENVG_API
	x = ev.openvg_api;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"OPENVG_API"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_rendering_api_range)
{
	using namespace eglplus;
	auto count = enum_value_range<rendering_api>().size();

#ifdef EGL_NONE
{
	--count;
	auto r = enum_value_range<rendering_api>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		rendering_api(EGL_NONE)
	) != r.end());
}
#endif

#ifdef EGL_OPENGL_API
{
	--count;
	auto r = enum_value_range<rendering_api>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		rendering_api(EGL_OPENGL_API)
	) != r.end());
}
#endif

#ifdef EGL_OPENGL_ES_API
{
	--count;
	auto r = enum_value_range<rendering_api>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		rendering_api(EGL_OPENGL_ES_API)
	) != r.end());
}
#endif

#ifdef EGL_OPENVG_API
{
	--count;
	auto r = enum_value_range<rendering_api>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		rendering_api(EGL_OPENVG_API)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_rendering_api_any)
{
	using namespace eglplus;
	enum_values ev;
	(void)ev;
	rendering_api x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef EGL_NONE
	x = ev.none;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.none);
#endif

#ifdef EGL_OPENGL_API
	x = ev.opengl_api;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.opengl_api);
#endif

#ifdef EGL_OPENGL_ES_API
	x = ev.opengl_es_api;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.opengl_es_api);
#endif

#ifdef EGL_OPENVG_API
	x = ev.openvg_api;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.openvg_api);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
