//  File test/eglplus/enums/multisample_resolve.cpp
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
#define BOOST_TEST_MODULE EGLPLUS_multisample_resolve

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_multisample_resolve_tests)

BOOST_AUTO_TEST_CASE(enum_multisample_resolve_values)
{
	using namespace eglplus;
	enum_values ev;
	(void)ev;
	multisample_resolve x;
	(void)x;

#ifdef EGL_MULTISAMPLE_RESOLVE_BOX
	x = ev.multisample_resolve_box;
	BOOST_CHECK(x == ev.multisample_resolve_box);
# ifdef EGL_MULTISAMPLE_RESOLVE_DEFAULT
	BOOST_CHECK(x != ev.multisample_resolve_default);
# endif
#endif

#ifdef EGL_MULTISAMPLE_RESOLVE_DEFAULT
	x = ev.multisample_resolve_default;
	BOOST_CHECK(x == ev.multisample_resolve_default);
#endif
}

BOOST_AUTO_TEST_CASE(enum_multisample_resolve_names)
{
	using namespace eglplus;
	enum_values ev;
	(void)ev;
	multisample_resolve x;
	(void)x;

#ifdef EGL_MULTISAMPLE_RESOLVE_BOX
	x = ev.multisample_resolve_box;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MULTISAMPLE_RESOLVE_BOX"
	) == 0);
#endif

#ifdef EGL_MULTISAMPLE_RESOLVE_DEFAULT
	x = ev.multisample_resolve_default;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MULTISAMPLE_RESOLVE_DEFAULT"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_multisample_resolve_range)
{
	using namespace eglplus;
	auto count = enum_value_range<multisample_resolve>().size();

#ifdef EGL_MULTISAMPLE_RESOLVE_BOX
{
	--count;
	auto r = enum_value_range<multisample_resolve>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		multisample_resolve(EGL_MULTISAMPLE_RESOLVE_BOX)
	) != r.end());
}
#endif

#ifdef EGL_MULTISAMPLE_RESOLVE_DEFAULT
{
	--count;
	auto r = enum_value_range<multisample_resolve>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		multisample_resolve(EGL_MULTISAMPLE_RESOLVE_DEFAULT)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_multisample_resolve_any)
{
	using namespace eglplus;
	enum_values ev;
	(void)ev;
	multisample_resolve x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef EGL_MULTISAMPLE_RESOLVE_BOX
	x = ev.multisample_resolve_box;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.multisample_resolve_box);
#endif

#ifdef EGL_MULTISAMPLE_RESOLVE_DEFAULT
	x = ev.multisample_resolve_default;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.multisample_resolve_default);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
