//  File test/eglplus/enums/renderable_type_bit.cpp
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
#define BOOST_TEST_MODULE EGLPLUS_renderable_type_bit

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_renderable_type_bit_tests)

BOOST_AUTO_TEST_CASE(enum_renderable_type_bit_values)
{
	using namespace eglplus;
	enum_values ev;
	(void)ev;
	renderable_type_bit x;
	(void)x;

#ifdef EGL_OPENGL_BIT
	x = ev.opengl_bit;
	BOOST_CHECK(x == ev.opengl_bit);
# ifdef EGL_OPENGL_ES2_BIT
	BOOST_CHECK(x != ev.opengl_es2_bit);
# endif
# ifdef EGL_OPENGL_ES3_BIT
	BOOST_CHECK(x != ev.opengl_es3_bit);
# endif
# ifdef EGL_OPENGL_ES_BIT
	BOOST_CHECK(x != ev.opengl_es_bit);
# endif
# ifdef EGL_OPENVG_BIT
	BOOST_CHECK(x != ev.openvg_bit);
# endif
#endif

#ifdef EGL_OPENGL_ES2_BIT
	x = ev.opengl_es2_bit;
	BOOST_CHECK(x == ev.opengl_es2_bit);
# ifdef EGL_OPENGL_ES3_BIT
	BOOST_CHECK(x != ev.opengl_es3_bit);
# endif
# ifdef EGL_OPENGL_ES_BIT
	BOOST_CHECK(x != ev.opengl_es_bit);
# endif
# ifdef EGL_OPENVG_BIT
	BOOST_CHECK(x != ev.openvg_bit);
# endif
#endif

#ifdef EGL_OPENGL_ES3_BIT
	x = ev.opengl_es3_bit;
	BOOST_CHECK(x == ev.opengl_es3_bit);
# ifdef EGL_OPENGL_ES_BIT
	BOOST_CHECK(x != ev.opengl_es_bit);
# endif
# ifdef EGL_OPENVG_BIT
	BOOST_CHECK(x != ev.openvg_bit);
# endif
#endif

#ifdef EGL_OPENGL_ES_BIT
	x = ev.opengl_es_bit;
	BOOST_CHECK(x == ev.opengl_es_bit);
# ifdef EGL_OPENVG_BIT
	BOOST_CHECK(x != ev.openvg_bit);
# endif
#endif

#ifdef EGL_OPENVG_BIT
	x = ev.openvg_bit;
	BOOST_CHECK(x == ev.openvg_bit);
#endif
}

BOOST_AUTO_TEST_CASE(enum_renderable_type_bit_names)
{
	using namespace eglplus;
	enum_values ev;
	(void)ev;
	renderable_type_bit x;
	(void)x;

#ifdef EGL_OPENGL_BIT
	x = ev.opengl_bit;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"OPENGL_BIT"
	) == 0);
#endif

#ifdef EGL_OPENGL_ES2_BIT
	x = ev.opengl_es2_bit;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"OPENGL_ES2_BIT"
	) == 0);
#endif

#ifdef EGL_OPENGL_ES3_BIT
	x = ev.opengl_es3_bit;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"OPENGL_ES3_BIT"
	) == 0);
#endif

#ifdef EGL_OPENGL_ES_BIT
	x = ev.opengl_es_bit;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"OPENGL_ES_BIT"
	) == 0);
#endif

#ifdef EGL_OPENVG_BIT
	x = ev.openvg_bit;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"OPENVG_BIT"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_renderable_type_bit_range)
{
	using namespace eglplus;
	auto count = enum_value_range<renderable_type_bit>().size();

#ifdef EGL_OPENGL_BIT
{
	--count;
	auto r = enum_value_range<renderable_type_bit>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		renderable_type_bit(EGL_OPENGL_BIT)
	) != r.end());
}
#endif

#ifdef EGL_OPENGL_ES2_BIT
{
	--count;
	auto r = enum_value_range<renderable_type_bit>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		renderable_type_bit(EGL_OPENGL_ES2_BIT)
	) != r.end());
}
#endif

#ifdef EGL_OPENGL_ES3_BIT
{
	--count;
	auto r = enum_value_range<renderable_type_bit>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		renderable_type_bit(EGL_OPENGL_ES3_BIT)
	) != r.end());
}
#endif

#ifdef EGL_OPENGL_ES_BIT
{
	--count;
	auto r = enum_value_range<renderable_type_bit>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		renderable_type_bit(EGL_OPENGL_ES_BIT)
	) != r.end());
}
#endif

#ifdef EGL_OPENVG_BIT
{
	--count;
	auto r = enum_value_range<renderable_type_bit>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		renderable_type_bit(EGL_OPENVG_BIT)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_renderable_type_bit_any)
{
	using namespace eglplus;
	enum_values ev;
	(void)ev;
	renderable_type_bit x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef EGL_OPENGL_BIT
	x = ev.opengl_bit;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.opengl_bit);
#endif

#ifdef EGL_OPENGL_ES2_BIT
	x = ev.opengl_es2_bit;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.opengl_es2_bit);
#endif

#ifdef EGL_OPENGL_ES3_BIT
	x = ev.opengl_es3_bit;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.opengl_es3_bit);
#endif

#ifdef EGL_OPENGL_ES_BIT
	x = ev.opengl_es_bit;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.opengl_es_bit);
#endif

#ifdef EGL_OPENVG_BIT
	x = ev.openvg_bit;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.openvg_bit);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
