//  File test/eglplus/enums/config_caveat.cpp
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
#define BOOST_TEST_MODULE EGLPLUS_config_caveat

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_config_caveat_tests)

BOOST_AUTO_TEST_CASE(enum_config_caveat_values)
{
	using namespace eglplus;
	enum_values ev;
	(void)ev;
	config_caveat x;
	(void)x;

#ifdef EGL_NON_CONFORMANT_CONFIG
	x = ev.non_conformant_config;
	BOOST_CHECK(x == ev.non_conformant_config);
# ifdef EGL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef EGL_SLOW_CONFIG
	BOOST_CHECK(x != ev.slow_config);
# endif
#endif

#ifdef EGL_NONE
	x = ev.none;
	BOOST_CHECK(x == ev.none);
# ifdef EGL_SLOW_CONFIG
	BOOST_CHECK(x != ev.slow_config);
# endif
#endif

#ifdef EGL_SLOW_CONFIG
	x = ev.slow_config;
	BOOST_CHECK(x == ev.slow_config);
#endif
}

BOOST_AUTO_TEST_CASE(enum_config_caveat_names)
{
	using namespace eglplus;
	enum_values ev;
	(void)ev;
	config_caveat x;
	(void)x;

#ifdef EGL_NON_CONFORMANT_CONFIG
	x = ev.non_conformant_config;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"NON_CONFORMANT_CONFIG"
	) == 0);
#endif

#ifdef EGL_NONE
	x = ev.none;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"NONE"
	) == 0);
#endif

#ifdef EGL_SLOW_CONFIG
	x = ev.slow_config;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SLOW_CONFIG"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_config_caveat_range)
{
	using namespace eglplus;
	auto count = enum_value_range<config_caveat>().size();

#ifdef EGL_NON_CONFORMANT_CONFIG
{
	--count;
	auto r = enum_value_range<config_caveat>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		config_caveat(EGL_NON_CONFORMANT_CONFIG)
	) != r.end());
}
#endif

#ifdef EGL_NONE
{
	--count;
	auto r = enum_value_range<config_caveat>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		config_caveat(EGL_NONE)
	) != r.end());
}
#endif

#ifdef EGL_SLOW_CONFIG
{
	--count;
	auto r = enum_value_range<config_caveat>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		config_caveat(EGL_SLOW_CONFIG)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_config_caveat_any)
{
	using namespace eglplus;
	enum_values ev;
	(void)ev;
	config_caveat x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef EGL_NON_CONFORMANT_CONFIG
	x = ev.non_conformant_config;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.non_conformant_config);
#endif

#ifdef EGL_NONE
	x = ev.none;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.none);
#endif

#ifdef EGL_SLOW_CONFIG
	x = ev.slow_config;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.slow_config);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
