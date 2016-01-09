//  File test/eglplus/enums/context_attrib.cpp
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
#define BOOST_TEST_MODULE EGLPLUS_context_attrib

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_context_attrib_tests)

BOOST_AUTO_TEST_CASE(enum_context_attrib_values)
{
	using namespace eglplus;
	enum_values ev;
	(void)ev;
	context_attrib x;
	(void)x;

#ifdef EGL_CONTEXT_FLAGS
	x = ev.context_flags;
	BOOST_CHECK(x == ev.context_flags);
# ifdef EGL_CONTEXT_MAJOR_VERSION
	BOOST_CHECK(x != ev.context_major_version);
# endif
# ifdef EGL_CONTEXT_MINOR_VERSION
	BOOST_CHECK(x != ev.context_minor_version);
# endif
# ifdef EGL_CONTEXT_OPENGL_PROFILE_MASK
	BOOST_CHECK(x != ev.context_opengl_profile_mask);
# endif
# ifdef EGL_CONTEXT_OPENGL_RESET_NOTIFICATION_STRATEGY
	BOOST_CHECK(x != ev.context_opengl_reset_notification_strategy);
# endif
#endif

#ifdef EGL_CONTEXT_MAJOR_VERSION
	x = ev.context_major_version;
	BOOST_CHECK(x == ev.context_major_version);
# ifdef EGL_CONTEXT_MINOR_VERSION
	BOOST_CHECK(x != ev.context_minor_version);
# endif
# ifdef EGL_CONTEXT_OPENGL_PROFILE_MASK
	BOOST_CHECK(x != ev.context_opengl_profile_mask);
# endif
# ifdef EGL_CONTEXT_OPENGL_RESET_NOTIFICATION_STRATEGY
	BOOST_CHECK(x != ev.context_opengl_reset_notification_strategy);
# endif
#endif

#ifdef EGL_CONTEXT_MINOR_VERSION
	x = ev.context_minor_version;
	BOOST_CHECK(x == ev.context_minor_version);
# ifdef EGL_CONTEXT_OPENGL_PROFILE_MASK
	BOOST_CHECK(x != ev.context_opengl_profile_mask);
# endif
# ifdef EGL_CONTEXT_OPENGL_RESET_NOTIFICATION_STRATEGY
	BOOST_CHECK(x != ev.context_opengl_reset_notification_strategy);
# endif
#endif

#ifdef EGL_CONTEXT_OPENGL_PROFILE_MASK
	x = ev.context_opengl_profile_mask;
	BOOST_CHECK(x == ev.context_opengl_profile_mask);
# ifdef EGL_CONTEXT_OPENGL_RESET_NOTIFICATION_STRATEGY
	BOOST_CHECK(x != ev.context_opengl_reset_notification_strategy);
# endif
#endif

#ifdef EGL_CONTEXT_OPENGL_RESET_NOTIFICATION_STRATEGY
	x = ev.context_opengl_reset_notification_strategy;
	BOOST_CHECK(x == ev.context_opengl_reset_notification_strategy);
#endif
}

BOOST_AUTO_TEST_CASE(enum_context_attrib_names)
{
	using namespace eglplus;
	enum_values ev;
	(void)ev;
	context_attrib x;
	(void)x;

#ifdef EGL_CONTEXT_FLAGS
	x = ev.context_flags;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"CONTEXT_FLAGS"
	) == 0);
#endif

#ifdef EGL_CONTEXT_MAJOR_VERSION
	x = ev.context_major_version;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"CONTEXT_MAJOR_VERSION"
	) == 0);
#endif

#ifdef EGL_CONTEXT_MINOR_VERSION
	x = ev.context_minor_version;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"CONTEXT_MINOR_VERSION"
	) == 0);
#endif

#ifdef EGL_CONTEXT_OPENGL_PROFILE_MASK
	x = ev.context_opengl_profile_mask;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"CONTEXT_OPENGL_PROFILE_MASK"
	) == 0);
#endif

#ifdef EGL_CONTEXT_OPENGL_RESET_NOTIFICATION_STRATEGY
	x = ev.context_opengl_reset_notification_strategy;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"CONTEXT_OPENGL_RESET_NOTIFICATION_STRATEGY"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_context_attrib_range)
{
	using namespace eglplus;
	auto count = enum_value_range<context_attrib>().size();

#ifdef EGL_CONTEXT_FLAGS
{
	--count;
	auto r = enum_value_range<context_attrib>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		context_attrib(EGL_CONTEXT_FLAGS)
	) != r.end());
}
#endif

#ifdef EGL_CONTEXT_MAJOR_VERSION
{
	--count;
	auto r = enum_value_range<context_attrib>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		context_attrib(EGL_CONTEXT_MAJOR_VERSION)
	) != r.end());
}
#endif

#ifdef EGL_CONTEXT_MINOR_VERSION
{
	--count;
	auto r = enum_value_range<context_attrib>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		context_attrib(EGL_CONTEXT_MINOR_VERSION)
	) != r.end());
}
#endif

#ifdef EGL_CONTEXT_OPENGL_PROFILE_MASK
{
	--count;
	auto r = enum_value_range<context_attrib>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		context_attrib(EGL_CONTEXT_OPENGL_PROFILE_MASK)
	) != r.end());
}
#endif

#ifdef EGL_CONTEXT_OPENGL_RESET_NOTIFICATION_STRATEGY
{
	--count;
	auto r = enum_value_range<context_attrib>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		context_attrib(EGL_CONTEXT_OPENGL_RESET_NOTIFICATION_STRATEGY)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_context_attrib_any)
{
	using namespace eglplus;
	enum_values ev;
	(void)ev;
	context_attrib x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef EGL_CONTEXT_FLAGS
	x = ev.context_flags;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.context_flags);
#endif

#ifdef EGL_CONTEXT_MAJOR_VERSION
	x = ev.context_major_version;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.context_major_version);
#endif

#ifdef EGL_CONTEXT_MINOR_VERSION
	x = ev.context_minor_version;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.context_minor_version);
#endif

#ifdef EGL_CONTEXT_OPENGL_PROFILE_MASK
	x = ev.context_opengl_profile_mask;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.context_opengl_profile_mask);
#endif

#ifdef EGL_CONTEXT_OPENGL_RESET_NOTIFICATION_STRATEGY
	x = ev.context_opengl_reset_notification_strategy;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.context_opengl_reset_notification_strategy);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
