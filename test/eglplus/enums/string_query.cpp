//  File test/eglplus/enums/string_query.cpp
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
#define BOOST_TEST_MODULE EGLPLUS_string_query

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_string_query)

BOOST_AUTO_TEST_CASE(enum_string_query_values)
{
	using namespace eglplus;
	enum_values ev;
	(void)ev;
	string_query x;
	(void)x;

#ifdef EGL_CLIENT_APIS
	x = ev.client_apis;
	BOOST_CHECK(x == ev.client_apis);
# ifdef EGL_EXTENSIONS
	BOOST_CHECK(x != ev.extensions);
# endif
# ifdef EGL_VENDOR
	BOOST_CHECK(x != ev.vendor);
# endif
# ifdef EGL_VERSION
	BOOST_CHECK(x != ev.version);
# endif
#endif

#ifdef EGL_EXTENSIONS
	x = ev.extensions;
# ifdef EGL_CLIENT_APIS
	BOOST_CHECK(x != ev.client_apis);
# endif
	BOOST_CHECK(x == ev.extensions);
# ifdef EGL_VENDOR
	BOOST_CHECK(x != ev.vendor);
# endif
# ifdef EGL_VERSION
	BOOST_CHECK(x != ev.version);
# endif
#endif

#ifdef EGL_VENDOR
	x = ev.vendor;
# ifdef EGL_CLIENT_APIS
	BOOST_CHECK(x != ev.client_apis);
# endif
# ifdef EGL_EXTENSIONS
	BOOST_CHECK(x != ev.extensions);
# endif
	BOOST_CHECK(x == ev.vendor);
# ifdef EGL_VERSION
	BOOST_CHECK(x != ev.version);
# endif
#endif

#ifdef EGL_VERSION
	x = ev.version;
# ifdef EGL_CLIENT_APIS
	BOOST_CHECK(x != ev.client_apis);
# endif
# ifdef EGL_EXTENSIONS
	BOOST_CHECK(x != ev.extensions);
# endif
# ifdef EGL_VENDOR
	BOOST_CHECK(x != ev.vendor);
# endif
	BOOST_CHECK(x == ev.version);
#endif
}

BOOST_AUTO_TEST_CASE(enum_string_query_names)
{
	using namespace eglplus;
	enum_values ev;
	(void)ev;
	string_query x;
	(void)x;

#ifdef EGL_CLIENT_APIS
	x = ev.client_apis;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"CLIENT_APIS"
	) == 0);
#endif

#ifdef EGL_EXTENSIONS
	x = ev.extensions;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"EXTENSIONS"
	) == 0);
#endif

#ifdef EGL_VENDOR
	x = ev.vendor;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"VENDOR"
	) == 0);
#endif

#ifdef EGL_VERSION
	x = ev.version;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"VERSION"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_string_query_range)
{
	using namespace eglplus;
	string_query x;
	(void)x;
	auto count = enum_value_range(x).size();

#ifdef EGL_CLIENT_APIS
{
	--count;
	array_view<const EGLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		EGL_CLIENT_APIS
	) != r.end());
}
#endif

#ifdef EGL_EXTENSIONS
{
	--count;
	array_view<const EGLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		EGL_EXTENSIONS
	) != r.end());
}
#endif

#ifdef EGL_VENDOR
{
	--count;
	array_view<const EGLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		EGL_VENDOR
	) != r.end());
}
#endif

#ifdef EGL_VERSION
{
	--count;
	array_view<const EGLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		EGL_VERSION
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_string_query_any)
{
	using namespace eglplus;
	enum_values ev;
	(void)ev;
	string_query x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef EGL_CLIENT_APIS
	x = ev.client_apis;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.client_apis);
#endif

#ifdef EGL_EXTENSIONS
	x = ev.extensions;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.extensions);
#endif

#ifdef EGL_VENDOR
	x = ev.vendor;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.vendor);
#endif

#ifdef EGL_VERSION
	x = ev.version;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.version);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
