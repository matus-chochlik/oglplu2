//  File test/eglplus/enums/error_code.cpp
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
#define BOOST_TEST_MODULE EGLPLUS_error_code

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_error_code)

BOOST_AUTO_TEST_CASE(enum_error_code_values)
{
	using namespace eglplus;
	enum_values ev;
	(void)ev;
	error_code x;
	(void)x;

#ifdef EGL_BAD_ACCESS
	x = ev.bad_access;
	BOOST_CHECK(x == ev.bad_access);
# ifdef EGL_BAD_ALLOC
	BOOST_CHECK(x != ev.bad_alloc);
# endif
# ifdef EGL_BAD_ATTRIBUTE
	BOOST_CHECK(x != ev.bad_attribute);
# endif
# ifdef EGL_BAD_CONFIG
	BOOST_CHECK(x != ev.bad_config);
# endif
# ifdef EGL_BAD_CONTEXT
	BOOST_CHECK(x != ev.bad_context);
# endif
# ifdef EGL_BAD_CURRENT_SURFACE
	BOOST_CHECK(x != ev.bad_current_surface);
# endif
# ifdef EGL_BAD_DISPLAY
	BOOST_CHECK(x != ev.bad_display);
# endif
# ifdef EGL_BAD_MATCH
	BOOST_CHECK(x != ev.bad_match);
# endif
# ifdef EGL_BAD_NATIVE_PIXMAP
	BOOST_CHECK(x != ev.bad_native_pixmap);
# endif
# ifdef EGL_BAD_NATIVE_WINDOW
	BOOST_CHECK(x != ev.bad_native_window);
# endif
# ifdef EGL_BAD_PARAMETER
	BOOST_CHECK(x != ev.bad_parameter);
# endif
# ifdef EGL_BAD_SURFACE
	BOOST_CHECK(x != ev.bad_surface);
# endif
# ifdef EGL_CONTEXT_LOST
	BOOST_CHECK(x != ev.context_lost);
# endif
# ifdef EGL_NOT_INITIALIZED
	BOOST_CHECK(x != ev.not_initialized);
# endif
#endif

#ifdef EGL_BAD_ALLOC
	x = ev.bad_alloc;
# ifdef EGL_BAD_ACCESS
	BOOST_CHECK(x != ev.bad_access);
# endif
	BOOST_CHECK(x == ev.bad_alloc);
# ifdef EGL_BAD_ATTRIBUTE
	BOOST_CHECK(x != ev.bad_attribute);
# endif
# ifdef EGL_BAD_CONFIG
	BOOST_CHECK(x != ev.bad_config);
# endif
# ifdef EGL_BAD_CONTEXT
	BOOST_CHECK(x != ev.bad_context);
# endif
# ifdef EGL_BAD_CURRENT_SURFACE
	BOOST_CHECK(x != ev.bad_current_surface);
# endif
# ifdef EGL_BAD_DISPLAY
	BOOST_CHECK(x != ev.bad_display);
# endif
# ifdef EGL_BAD_MATCH
	BOOST_CHECK(x != ev.bad_match);
# endif
# ifdef EGL_BAD_NATIVE_PIXMAP
	BOOST_CHECK(x != ev.bad_native_pixmap);
# endif
# ifdef EGL_BAD_NATIVE_WINDOW
	BOOST_CHECK(x != ev.bad_native_window);
# endif
# ifdef EGL_BAD_PARAMETER
	BOOST_CHECK(x != ev.bad_parameter);
# endif
# ifdef EGL_BAD_SURFACE
	BOOST_CHECK(x != ev.bad_surface);
# endif
# ifdef EGL_CONTEXT_LOST
	BOOST_CHECK(x != ev.context_lost);
# endif
# ifdef EGL_NOT_INITIALIZED
	BOOST_CHECK(x != ev.not_initialized);
# endif
#endif

#ifdef EGL_BAD_ATTRIBUTE
	x = ev.bad_attribute;
# ifdef EGL_BAD_ACCESS
	BOOST_CHECK(x != ev.bad_access);
# endif
# ifdef EGL_BAD_ALLOC
	BOOST_CHECK(x != ev.bad_alloc);
# endif
	BOOST_CHECK(x == ev.bad_attribute);
# ifdef EGL_BAD_CONFIG
	BOOST_CHECK(x != ev.bad_config);
# endif
# ifdef EGL_BAD_CONTEXT
	BOOST_CHECK(x != ev.bad_context);
# endif
# ifdef EGL_BAD_CURRENT_SURFACE
	BOOST_CHECK(x != ev.bad_current_surface);
# endif
# ifdef EGL_BAD_DISPLAY
	BOOST_CHECK(x != ev.bad_display);
# endif
# ifdef EGL_BAD_MATCH
	BOOST_CHECK(x != ev.bad_match);
# endif
# ifdef EGL_BAD_NATIVE_PIXMAP
	BOOST_CHECK(x != ev.bad_native_pixmap);
# endif
# ifdef EGL_BAD_NATIVE_WINDOW
	BOOST_CHECK(x != ev.bad_native_window);
# endif
# ifdef EGL_BAD_PARAMETER
	BOOST_CHECK(x != ev.bad_parameter);
# endif
# ifdef EGL_BAD_SURFACE
	BOOST_CHECK(x != ev.bad_surface);
# endif
# ifdef EGL_CONTEXT_LOST
	BOOST_CHECK(x != ev.context_lost);
# endif
# ifdef EGL_NOT_INITIALIZED
	BOOST_CHECK(x != ev.not_initialized);
# endif
#endif

#ifdef EGL_BAD_CONFIG
	x = ev.bad_config;
# ifdef EGL_BAD_ACCESS
	BOOST_CHECK(x != ev.bad_access);
# endif
# ifdef EGL_BAD_ALLOC
	BOOST_CHECK(x != ev.bad_alloc);
# endif
# ifdef EGL_BAD_ATTRIBUTE
	BOOST_CHECK(x != ev.bad_attribute);
# endif
	BOOST_CHECK(x == ev.bad_config);
# ifdef EGL_BAD_CONTEXT
	BOOST_CHECK(x != ev.bad_context);
# endif
# ifdef EGL_BAD_CURRENT_SURFACE
	BOOST_CHECK(x != ev.bad_current_surface);
# endif
# ifdef EGL_BAD_DISPLAY
	BOOST_CHECK(x != ev.bad_display);
# endif
# ifdef EGL_BAD_MATCH
	BOOST_CHECK(x != ev.bad_match);
# endif
# ifdef EGL_BAD_NATIVE_PIXMAP
	BOOST_CHECK(x != ev.bad_native_pixmap);
# endif
# ifdef EGL_BAD_NATIVE_WINDOW
	BOOST_CHECK(x != ev.bad_native_window);
# endif
# ifdef EGL_BAD_PARAMETER
	BOOST_CHECK(x != ev.bad_parameter);
# endif
# ifdef EGL_BAD_SURFACE
	BOOST_CHECK(x != ev.bad_surface);
# endif
# ifdef EGL_CONTEXT_LOST
	BOOST_CHECK(x != ev.context_lost);
# endif
# ifdef EGL_NOT_INITIALIZED
	BOOST_CHECK(x != ev.not_initialized);
# endif
#endif

#ifdef EGL_BAD_CONTEXT
	x = ev.bad_context;
# ifdef EGL_BAD_ACCESS
	BOOST_CHECK(x != ev.bad_access);
# endif
# ifdef EGL_BAD_ALLOC
	BOOST_CHECK(x != ev.bad_alloc);
# endif
# ifdef EGL_BAD_ATTRIBUTE
	BOOST_CHECK(x != ev.bad_attribute);
# endif
# ifdef EGL_BAD_CONFIG
	BOOST_CHECK(x != ev.bad_config);
# endif
	BOOST_CHECK(x == ev.bad_context);
# ifdef EGL_BAD_CURRENT_SURFACE
	BOOST_CHECK(x != ev.bad_current_surface);
# endif
# ifdef EGL_BAD_DISPLAY
	BOOST_CHECK(x != ev.bad_display);
# endif
# ifdef EGL_BAD_MATCH
	BOOST_CHECK(x != ev.bad_match);
# endif
# ifdef EGL_BAD_NATIVE_PIXMAP
	BOOST_CHECK(x != ev.bad_native_pixmap);
# endif
# ifdef EGL_BAD_NATIVE_WINDOW
	BOOST_CHECK(x != ev.bad_native_window);
# endif
# ifdef EGL_BAD_PARAMETER
	BOOST_CHECK(x != ev.bad_parameter);
# endif
# ifdef EGL_BAD_SURFACE
	BOOST_CHECK(x != ev.bad_surface);
# endif
# ifdef EGL_CONTEXT_LOST
	BOOST_CHECK(x != ev.context_lost);
# endif
# ifdef EGL_NOT_INITIALIZED
	BOOST_CHECK(x != ev.not_initialized);
# endif
#endif

#ifdef EGL_BAD_CURRENT_SURFACE
	x = ev.bad_current_surface;
# ifdef EGL_BAD_ACCESS
	BOOST_CHECK(x != ev.bad_access);
# endif
# ifdef EGL_BAD_ALLOC
	BOOST_CHECK(x != ev.bad_alloc);
# endif
# ifdef EGL_BAD_ATTRIBUTE
	BOOST_CHECK(x != ev.bad_attribute);
# endif
# ifdef EGL_BAD_CONFIG
	BOOST_CHECK(x != ev.bad_config);
# endif
# ifdef EGL_BAD_CONTEXT
	BOOST_CHECK(x != ev.bad_context);
# endif
	BOOST_CHECK(x == ev.bad_current_surface);
# ifdef EGL_BAD_DISPLAY
	BOOST_CHECK(x != ev.bad_display);
# endif
# ifdef EGL_BAD_MATCH
	BOOST_CHECK(x != ev.bad_match);
# endif
# ifdef EGL_BAD_NATIVE_PIXMAP
	BOOST_CHECK(x != ev.bad_native_pixmap);
# endif
# ifdef EGL_BAD_NATIVE_WINDOW
	BOOST_CHECK(x != ev.bad_native_window);
# endif
# ifdef EGL_BAD_PARAMETER
	BOOST_CHECK(x != ev.bad_parameter);
# endif
# ifdef EGL_BAD_SURFACE
	BOOST_CHECK(x != ev.bad_surface);
# endif
# ifdef EGL_CONTEXT_LOST
	BOOST_CHECK(x != ev.context_lost);
# endif
# ifdef EGL_NOT_INITIALIZED
	BOOST_CHECK(x != ev.not_initialized);
# endif
#endif

#ifdef EGL_BAD_DISPLAY
	x = ev.bad_display;
# ifdef EGL_BAD_ACCESS
	BOOST_CHECK(x != ev.bad_access);
# endif
# ifdef EGL_BAD_ALLOC
	BOOST_CHECK(x != ev.bad_alloc);
# endif
# ifdef EGL_BAD_ATTRIBUTE
	BOOST_CHECK(x != ev.bad_attribute);
# endif
# ifdef EGL_BAD_CONFIG
	BOOST_CHECK(x != ev.bad_config);
# endif
# ifdef EGL_BAD_CONTEXT
	BOOST_CHECK(x != ev.bad_context);
# endif
# ifdef EGL_BAD_CURRENT_SURFACE
	BOOST_CHECK(x != ev.bad_current_surface);
# endif
	BOOST_CHECK(x == ev.bad_display);
# ifdef EGL_BAD_MATCH
	BOOST_CHECK(x != ev.bad_match);
# endif
# ifdef EGL_BAD_NATIVE_PIXMAP
	BOOST_CHECK(x != ev.bad_native_pixmap);
# endif
# ifdef EGL_BAD_NATIVE_WINDOW
	BOOST_CHECK(x != ev.bad_native_window);
# endif
# ifdef EGL_BAD_PARAMETER
	BOOST_CHECK(x != ev.bad_parameter);
# endif
# ifdef EGL_BAD_SURFACE
	BOOST_CHECK(x != ev.bad_surface);
# endif
# ifdef EGL_CONTEXT_LOST
	BOOST_CHECK(x != ev.context_lost);
# endif
# ifdef EGL_NOT_INITIALIZED
	BOOST_CHECK(x != ev.not_initialized);
# endif
#endif

#ifdef EGL_BAD_MATCH
	x = ev.bad_match;
# ifdef EGL_BAD_ACCESS
	BOOST_CHECK(x != ev.bad_access);
# endif
# ifdef EGL_BAD_ALLOC
	BOOST_CHECK(x != ev.bad_alloc);
# endif
# ifdef EGL_BAD_ATTRIBUTE
	BOOST_CHECK(x != ev.bad_attribute);
# endif
# ifdef EGL_BAD_CONFIG
	BOOST_CHECK(x != ev.bad_config);
# endif
# ifdef EGL_BAD_CONTEXT
	BOOST_CHECK(x != ev.bad_context);
# endif
# ifdef EGL_BAD_CURRENT_SURFACE
	BOOST_CHECK(x != ev.bad_current_surface);
# endif
# ifdef EGL_BAD_DISPLAY
	BOOST_CHECK(x != ev.bad_display);
# endif
	BOOST_CHECK(x == ev.bad_match);
# ifdef EGL_BAD_NATIVE_PIXMAP
	BOOST_CHECK(x != ev.bad_native_pixmap);
# endif
# ifdef EGL_BAD_NATIVE_WINDOW
	BOOST_CHECK(x != ev.bad_native_window);
# endif
# ifdef EGL_BAD_PARAMETER
	BOOST_CHECK(x != ev.bad_parameter);
# endif
# ifdef EGL_BAD_SURFACE
	BOOST_CHECK(x != ev.bad_surface);
# endif
# ifdef EGL_CONTEXT_LOST
	BOOST_CHECK(x != ev.context_lost);
# endif
# ifdef EGL_NOT_INITIALIZED
	BOOST_CHECK(x != ev.not_initialized);
# endif
#endif

#ifdef EGL_BAD_NATIVE_PIXMAP
	x = ev.bad_native_pixmap;
# ifdef EGL_BAD_ACCESS
	BOOST_CHECK(x != ev.bad_access);
# endif
# ifdef EGL_BAD_ALLOC
	BOOST_CHECK(x != ev.bad_alloc);
# endif
# ifdef EGL_BAD_ATTRIBUTE
	BOOST_CHECK(x != ev.bad_attribute);
# endif
# ifdef EGL_BAD_CONFIG
	BOOST_CHECK(x != ev.bad_config);
# endif
# ifdef EGL_BAD_CONTEXT
	BOOST_CHECK(x != ev.bad_context);
# endif
# ifdef EGL_BAD_CURRENT_SURFACE
	BOOST_CHECK(x != ev.bad_current_surface);
# endif
# ifdef EGL_BAD_DISPLAY
	BOOST_CHECK(x != ev.bad_display);
# endif
# ifdef EGL_BAD_MATCH
	BOOST_CHECK(x != ev.bad_match);
# endif
	BOOST_CHECK(x == ev.bad_native_pixmap);
# ifdef EGL_BAD_NATIVE_WINDOW
	BOOST_CHECK(x != ev.bad_native_window);
# endif
# ifdef EGL_BAD_PARAMETER
	BOOST_CHECK(x != ev.bad_parameter);
# endif
# ifdef EGL_BAD_SURFACE
	BOOST_CHECK(x != ev.bad_surface);
# endif
# ifdef EGL_CONTEXT_LOST
	BOOST_CHECK(x != ev.context_lost);
# endif
# ifdef EGL_NOT_INITIALIZED
	BOOST_CHECK(x != ev.not_initialized);
# endif
#endif

#ifdef EGL_BAD_NATIVE_WINDOW
	x = ev.bad_native_window;
# ifdef EGL_BAD_ACCESS
	BOOST_CHECK(x != ev.bad_access);
# endif
# ifdef EGL_BAD_ALLOC
	BOOST_CHECK(x != ev.bad_alloc);
# endif
# ifdef EGL_BAD_ATTRIBUTE
	BOOST_CHECK(x != ev.bad_attribute);
# endif
# ifdef EGL_BAD_CONFIG
	BOOST_CHECK(x != ev.bad_config);
# endif
# ifdef EGL_BAD_CONTEXT
	BOOST_CHECK(x != ev.bad_context);
# endif
# ifdef EGL_BAD_CURRENT_SURFACE
	BOOST_CHECK(x != ev.bad_current_surface);
# endif
# ifdef EGL_BAD_DISPLAY
	BOOST_CHECK(x != ev.bad_display);
# endif
# ifdef EGL_BAD_MATCH
	BOOST_CHECK(x != ev.bad_match);
# endif
# ifdef EGL_BAD_NATIVE_PIXMAP
	BOOST_CHECK(x != ev.bad_native_pixmap);
# endif
	BOOST_CHECK(x == ev.bad_native_window);
# ifdef EGL_BAD_PARAMETER
	BOOST_CHECK(x != ev.bad_parameter);
# endif
# ifdef EGL_BAD_SURFACE
	BOOST_CHECK(x != ev.bad_surface);
# endif
# ifdef EGL_CONTEXT_LOST
	BOOST_CHECK(x != ev.context_lost);
# endif
# ifdef EGL_NOT_INITIALIZED
	BOOST_CHECK(x != ev.not_initialized);
# endif
#endif

#ifdef EGL_BAD_PARAMETER
	x = ev.bad_parameter;
# ifdef EGL_BAD_ACCESS
	BOOST_CHECK(x != ev.bad_access);
# endif
# ifdef EGL_BAD_ALLOC
	BOOST_CHECK(x != ev.bad_alloc);
# endif
# ifdef EGL_BAD_ATTRIBUTE
	BOOST_CHECK(x != ev.bad_attribute);
# endif
# ifdef EGL_BAD_CONFIG
	BOOST_CHECK(x != ev.bad_config);
# endif
# ifdef EGL_BAD_CONTEXT
	BOOST_CHECK(x != ev.bad_context);
# endif
# ifdef EGL_BAD_CURRENT_SURFACE
	BOOST_CHECK(x != ev.bad_current_surface);
# endif
# ifdef EGL_BAD_DISPLAY
	BOOST_CHECK(x != ev.bad_display);
# endif
# ifdef EGL_BAD_MATCH
	BOOST_CHECK(x != ev.bad_match);
# endif
# ifdef EGL_BAD_NATIVE_PIXMAP
	BOOST_CHECK(x != ev.bad_native_pixmap);
# endif
# ifdef EGL_BAD_NATIVE_WINDOW
	BOOST_CHECK(x != ev.bad_native_window);
# endif
	BOOST_CHECK(x == ev.bad_parameter);
# ifdef EGL_BAD_SURFACE
	BOOST_CHECK(x != ev.bad_surface);
# endif
# ifdef EGL_CONTEXT_LOST
	BOOST_CHECK(x != ev.context_lost);
# endif
# ifdef EGL_NOT_INITIALIZED
	BOOST_CHECK(x != ev.not_initialized);
# endif
#endif

#ifdef EGL_BAD_SURFACE
	x = ev.bad_surface;
# ifdef EGL_BAD_ACCESS
	BOOST_CHECK(x != ev.bad_access);
# endif
# ifdef EGL_BAD_ALLOC
	BOOST_CHECK(x != ev.bad_alloc);
# endif
# ifdef EGL_BAD_ATTRIBUTE
	BOOST_CHECK(x != ev.bad_attribute);
# endif
# ifdef EGL_BAD_CONFIG
	BOOST_CHECK(x != ev.bad_config);
# endif
# ifdef EGL_BAD_CONTEXT
	BOOST_CHECK(x != ev.bad_context);
# endif
# ifdef EGL_BAD_CURRENT_SURFACE
	BOOST_CHECK(x != ev.bad_current_surface);
# endif
# ifdef EGL_BAD_DISPLAY
	BOOST_CHECK(x != ev.bad_display);
# endif
# ifdef EGL_BAD_MATCH
	BOOST_CHECK(x != ev.bad_match);
# endif
# ifdef EGL_BAD_NATIVE_PIXMAP
	BOOST_CHECK(x != ev.bad_native_pixmap);
# endif
# ifdef EGL_BAD_NATIVE_WINDOW
	BOOST_CHECK(x != ev.bad_native_window);
# endif
# ifdef EGL_BAD_PARAMETER
	BOOST_CHECK(x != ev.bad_parameter);
# endif
	BOOST_CHECK(x == ev.bad_surface);
# ifdef EGL_CONTEXT_LOST
	BOOST_CHECK(x != ev.context_lost);
# endif
# ifdef EGL_NOT_INITIALIZED
	BOOST_CHECK(x != ev.not_initialized);
# endif
#endif

#ifdef EGL_CONTEXT_LOST
	x = ev.context_lost;
# ifdef EGL_BAD_ACCESS
	BOOST_CHECK(x != ev.bad_access);
# endif
# ifdef EGL_BAD_ALLOC
	BOOST_CHECK(x != ev.bad_alloc);
# endif
# ifdef EGL_BAD_ATTRIBUTE
	BOOST_CHECK(x != ev.bad_attribute);
# endif
# ifdef EGL_BAD_CONFIG
	BOOST_CHECK(x != ev.bad_config);
# endif
# ifdef EGL_BAD_CONTEXT
	BOOST_CHECK(x != ev.bad_context);
# endif
# ifdef EGL_BAD_CURRENT_SURFACE
	BOOST_CHECK(x != ev.bad_current_surface);
# endif
# ifdef EGL_BAD_DISPLAY
	BOOST_CHECK(x != ev.bad_display);
# endif
# ifdef EGL_BAD_MATCH
	BOOST_CHECK(x != ev.bad_match);
# endif
# ifdef EGL_BAD_NATIVE_PIXMAP
	BOOST_CHECK(x != ev.bad_native_pixmap);
# endif
# ifdef EGL_BAD_NATIVE_WINDOW
	BOOST_CHECK(x != ev.bad_native_window);
# endif
# ifdef EGL_BAD_PARAMETER
	BOOST_CHECK(x != ev.bad_parameter);
# endif
# ifdef EGL_BAD_SURFACE
	BOOST_CHECK(x != ev.bad_surface);
# endif
	BOOST_CHECK(x == ev.context_lost);
# ifdef EGL_NOT_INITIALIZED
	BOOST_CHECK(x != ev.not_initialized);
# endif
#endif

#ifdef EGL_NOT_INITIALIZED
	x = ev.not_initialized;
# ifdef EGL_BAD_ACCESS
	BOOST_CHECK(x != ev.bad_access);
# endif
# ifdef EGL_BAD_ALLOC
	BOOST_CHECK(x != ev.bad_alloc);
# endif
# ifdef EGL_BAD_ATTRIBUTE
	BOOST_CHECK(x != ev.bad_attribute);
# endif
# ifdef EGL_BAD_CONFIG
	BOOST_CHECK(x != ev.bad_config);
# endif
# ifdef EGL_BAD_CONTEXT
	BOOST_CHECK(x != ev.bad_context);
# endif
# ifdef EGL_BAD_CURRENT_SURFACE
	BOOST_CHECK(x != ev.bad_current_surface);
# endif
# ifdef EGL_BAD_DISPLAY
	BOOST_CHECK(x != ev.bad_display);
# endif
# ifdef EGL_BAD_MATCH
	BOOST_CHECK(x != ev.bad_match);
# endif
# ifdef EGL_BAD_NATIVE_PIXMAP
	BOOST_CHECK(x != ev.bad_native_pixmap);
# endif
# ifdef EGL_BAD_NATIVE_WINDOW
	BOOST_CHECK(x != ev.bad_native_window);
# endif
# ifdef EGL_BAD_PARAMETER
	BOOST_CHECK(x != ev.bad_parameter);
# endif
# ifdef EGL_BAD_SURFACE
	BOOST_CHECK(x != ev.bad_surface);
# endif
# ifdef EGL_CONTEXT_LOST
	BOOST_CHECK(x != ev.context_lost);
# endif
	BOOST_CHECK(x == ev.not_initialized);
#endif
}

BOOST_AUTO_TEST_CASE(enum_error_code_names)
{
	using namespace eglplus;
	enum_values ev;
	(void)ev;
	error_code x;
	(void)x;

#ifdef EGL_BAD_ACCESS
	x = ev.bad_access;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"BAD_ACCESS"
	) == 0);
#endif

#ifdef EGL_BAD_ALLOC
	x = ev.bad_alloc;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"BAD_ALLOC"
	) == 0);
#endif

#ifdef EGL_BAD_ATTRIBUTE
	x = ev.bad_attribute;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"BAD_ATTRIBUTE"
	) == 0);
#endif

#ifdef EGL_BAD_CONFIG
	x = ev.bad_config;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"BAD_CONFIG"
	) == 0);
#endif

#ifdef EGL_BAD_CONTEXT
	x = ev.bad_context;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"BAD_CONTEXT"
	) == 0);
#endif

#ifdef EGL_BAD_CURRENT_SURFACE
	x = ev.bad_current_surface;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"BAD_CURRENT_SURFACE"
	) == 0);
#endif

#ifdef EGL_BAD_DISPLAY
	x = ev.bad_display;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"BAD_DISPLAY"
	) == 0);
#endif

#ifdef EGL_BAD_MATCH
	x = ev.bad_match;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"BAD_MATCH"
	) == 0);
#endif

#ifdef EGL_BAD_NATIVE_PIXMAP
	x = ev.bad_native_pixmap;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"BAD_NATIVE_PIXMAP"
	) == 0);
#endif

#ifdef EGL_BAD_NATIVE_WINDOW
	x = ev.bad_native_window;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"BAD_NATIVE_WINDOW"
	) == 0);
#endif

#ifdef EGL_BAD_PARAMETER
	x = ev.bad_parameter;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"BAD_PARAMETER"
	) == 0);
#endif

#ifdef EGL_BAD_SURFACE
	x = ev.bad_surface;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"BAD_SURFACE"
	) == 0);
#endif

#ifdef EGL_CONTEXT_LOST
	x = ev.context_lost;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"CONTEXT_LOST"
	) == 0);
#endif

#ifdef EGL_NOT_INITIALIZED
	x = ev.not_initialized;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"NOT_INITIALIZED"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_error_code_range)
{
	using namespace eglplus;
	error_code x;
	(void)x;
	auto count = enum_value_range(x).size();

#ifdef EGL_BAD_ACCESS
{
	--count;
	array_view<const EGLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		EGL_BAD_ACCESS
	) != r.end());
}
#endif

#ifdef EGL_BAD_ALLOC
{
	--count;
	array_view<const EGLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		EGL_BAD_ALLOC
	) != r.end());
}
#endif

#ifdef EGL_BAD_ATTRIBUTE
{
	--count;
	array_view<const EGLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		EGL_BAD_ATTRIBUTE
	) != r.end());
}
#endif

#ifdef EGL_BAD_CONFIG
{
	--count;
	array_view<const EGLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		EGL_BAD_CONFIG
	) != r.end());
}
#endif

#ifdef EGL_BAD_CONTEXT
{
	--count;
	array_view<const EGLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		EGL_BAD_CONTEXT
	) != r.end());
}
#endif

#ifdef EGL_BAD_CURRENT_SURFACE
{
	--count;
	array_view<const EGLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		EGL_BAD_CURRENT_SURFACE
	) != r.end());
}
#endif

#ifdef EGL_BAD_DISPLAY
{
	--count;
	array_view<const EGLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		EGL_BAD_DISPLAY
	) != r.end());
}
#endif

#ifdef EGL_BAD_MATCH
{
	--count;
	array_view<const EGLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		EGL_BAD_MATCH
	) != r.end());
}
#endif

#ifdef EGL_BAD_NATIVE_PIXMAP
{
	--count;
	array_view<const EGLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		EGL_BAD_NATIVE_PIXMAP
	) != r.end());
}
#endif

#ifdef EGL_BAD_NATIVE_WINDOW
{
	--count;
	array_view<const EGLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		EGL_BAD_NATIVE_WINDOW
	) != r.end());
}
#endif

#ifdef EGL_BAD_PARAMETER
{
	--count;
	array_view<const EGLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		EGL_BAD_PARAMETER
	) != r.end());
}
#endif

#ifdef EGL_BAD_SURFACE
{
	--count;
	array_view<const EGLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		EGL_BAD_SURFACE
	) != r.end());
}
#endif

#ifdef EGL_CONTEXT_LOST
{
	--count;
	array_view<const EGLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		EGL_CONTEXT_LOST
	) != r.end());
}
#endif

#ifdef EGL_NOT_INITIALIZED
{
	--count;
	array_view<const EGLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		EGL_NOT_INITIALIZED
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_error_code_any)
{
	using namespace eglplus;
	enum_values ev;
	(void)ev;
	error_code x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef EGL_BAD_ACCESS
	x = ev.bad_access;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.bad_access);
#endif

#ifdef EGL_BAD_ALLOC
	x = ev.bad_alloc;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.bad_alloc);
#endif

#ifdef EGL_BAD_ATTRIBUTE
	x = ev.bad_attribute;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.bad_attribute);
#endif

#ifdef EGL_BAD_CONFIG
	x = ev.bad_config;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.bad_config);
#endif

#ifdef EGL_BAD_CONTEXT
	x = ev.bad_context;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.bad_context);
#endif

#ifdef EGL_BAD_CURRENT_SURFACE
	x = ev.bad_current_surface;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.bad_current_surface);
#endif

#ifdef EGL_BAD_DISPLAY
	x = ev.bad_display;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.bad_display);
#endif

#ifdef EGL_BAD_MATCH
	x = ev.bad_match;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.bad_match);
#endif

#ifdef EGL_BAD_NATIVE_PIXMAP
	x = ev.bad_native_pixmap;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.bad_native_pixmap);
#endif

#ifdef EGL_BAD_NATIVE_WINDOW
	x = ev.bad_native_window;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.bad_native_window);
#endif

#ifdef EGL_BAD_PARAMETER
	x = ev.bad_parameter;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.bad_parameter);
#endif

#ifdef EGL_BAD_SURFACE
	x = ev.bad_surface;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.bad_surface);
#endif

#ifdef EGL_CONTEXT_LOST
	x = ev.context_lost;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.context_lost);
#endif

#ifdef EGL_NOT_INITIALIZED
	x = ev.not_initialized;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.not_initialized);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
