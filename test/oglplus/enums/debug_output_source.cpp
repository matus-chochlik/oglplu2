//  File test/oglplus/enums/debug_output_source.cpp
//
//  Automatically generated file, DO NOT modify manually.
//  Edit the enumeration source files in 'source/enums/oglplus'
//  or the 'source/enums/make_enum.py' script instead.
//
//  Copyright Matus Chochlik.
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt
//
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE OGLPLUS_debug_output_source

#include <boost/test/unit_test.hpp>
#include "common.hpp"

BOOST_AUTO_TEST_SUITE(enum_debug_output_source)

BOOST_AUTO_TEST_CASE(enum_debug_output_source_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	debug_output_source x;
	(void)x;

#ifdef GL_DEBUG_SOURCE_API
	x = ev.debug_source_api;
	BOOST_CHECK(x == ev.debug_source_api);
# ifdef GL_DEBUG_SOURCE_APPLICATION
	BOOST_CHECK(x != ev.debug_source_application);
# endif
# ifdef GL_DEBUG_SOURCE_OTHER
	BOOST_CHECK(x != ev.debug_source_other);
# endif
# ifdef GL_DEBUG_SOURCE_SHADER_COMPILER
	BOOST_CHECK(x != ev.debug_source_shader_compiler);
# endif
# ifdef GL_DEBUG_SOURCE_THIRD_PARTY
	BOOST_CHECK(x != ev.debug_source_third_party);
# endif
# ifdef GL_DEBUG_SOURCE_WINDOW_SYSTEM
	BOOST_CHECK(x != ev.debug_source_window_system);
# endif
# ifdef GL_DONT_CARE
	BOOST_CHECK(x != ev.dont_care);
# endif
#endif

#ifdef GL_DEBUG_SOURCE_APPLICATION
	x = ev.debug_source_application;
# ifdef GL_DEBUG_SOURCE_API
	BOOST_CHECK(x != ev.debug_source_api);
# endif
	BOOST_CHECK(x == ev.debug_source_application);
# ifdef GL_DEBUG_SOURCE_OTHER
	BOOST_CHECK(x != ev.debug_source_other);
# endif
# ifdef GL_DEBUG_SOURCE_SHADER_COMPILER
	BOOST_CHECK(x != ev.debug_source_shader_compiler);
# endif
# ifdef GL_DEBUG_SOURCE_THIRD_PARTY
	BOOST_CHECK(x != ev.debug_source_third_party);
# endif
# ifdef GL_DEBUG_SOURCE_WINDOW_SYSTEM
	BOOST_CHECK(x != ev.debug_source_window_system);
# endif
# ifdef GL_DONT_CARE
	BOOST_CHECK(x != ev.dont_care);
# endif
#endif

#ifdef GL_DEBUG_SOURCE_OTHER
	x = ev.debug_source_other;
# ifdef GL_DEBUG_SOURCE_API
	BOOST_CHECK(x != ev.debug_source_api);
# endif
# ifdef GL_DEBUG_SOURCE_APPLICATION
	BOOST_CHECK(x != ev.debug_source_application);
# endif
	BOOST_CHECK(x == ev.debug_source_other);
# ifdef GL_DEBUG_SOURCE_SHADER_COMPILER
	BOOST_CHECK(x != ev.debug_source_shader_compiler);
# endif
# ifdef GL_DEBUG_SOURCE_THIRD_PARTY
	BOOST_CHECK(x != ev.debug_source_third_party);
# endif
# ifdef GL_DEBUG_SOURCE_WINDOW_SYSTEM
	BOOST_CHECK(x != ev.debug_source_window_system);
# endif
# ifdef GL_DONT_CARE
	BOOST_CHECK(x != ev.dont_care);
# endif
#endif

#ifdef GL_DEBUG_SOURCE_SHADER_COMPILER
	x = ev.debug_source_shader_compiler;
# ifdef GL_DEBUG_SOURCE_API
	BOOST_CHECK(x != ev.debug_source_api);
# endif
# ifdef GL_DEBUG_SOURCE_APPLICATION
	BOOST_CHECK(x != ev.debug_source_application);
# endif
# ifdef GL_DEBUG_SOURCE_OTHER
	BOOST_CHECK(x != ev.debug_source_other);
# endif
	BOOST_CHECK(x == ev.debug_source_shader_compiler);
# ifdef GL_DEBUG_SOURCE_THIRD_PARTY
	BOOST_CHECK(x != ev.debug_source_third_party);
# endif
# ifdef GL_DEBUG_SOURCE_WINDOW_SYSTEM
	BOOST_CHECK(x != ev.debug_source_window_system);
# endif
# ifdef GL_DONT_CARE
	BOOST_CHECK(x != ev.dont_care);
# endif
#endif

#ifdef GL_DEBUG_SOURCE_THIRD_PARTY
	x = ev.debug_source_third_party;
# ifdef GL_DEBUG_SOURCE_API
	BOOST_CHECK(x != ev.debug_source_api);
# endif
# ifdef GL_DEBUG_SOURCE_APPLICATION
	BOOST_CHECK(x != ev.debug_source_application);
# endif
# ifdef GL_DEBUG_SOURCE_OTHER
	BOOST_CHECK(x != ev.debug_source_other);
# endif
# ifdef GL_DEBUG_SOURCE_SHADER_COMPILER
	BOOST_CHECK(x != ev.debug_source_shader_compiler);
# endif
	BOOST_CHECK(x == ev.debug_source_third_party);
# ifdef GL_DEBUG_SOURCE_WINDOW_SYSTEM
	BOOST_CHECK(x != ev.debug_source_window_system);
# endif
# ifdef GL_DONT_CARE
	BOOST_CHECK(x != ev.dont_care);
# endif
#endif

#ifdef GL_DEBUG_SOURCE_WINDOW_SYSTEM
	x = ev.debug_source_window_system;
# ifdef GL_DEBUG_SOURCE_API
	BOOST_CHECK(x != ev.debug_source_api);
# endif
# ifdef GL_DEBUG_SOURCE_APPLICATION
	BOOST_CHECK(x != ev.debug_source_application);
# endif
# ifdef GL_DEBUG_SOURCE_OTHER
	BOOST_CHECK(x != ev.debug_source_other);
# endif
# ifdef GL_DEBUG_SOURCE_SHADER_COMPILER
	BOOST_CHECK(x != ev.debug_source_shader_compiler);
# endif
# ifdef GL_DEBUG_SOURCE_THIRD_PARTY
	BOOST_CHECK(x != ev.debug_source_third_party);
# endif
	BOOST_CHECK(x == ev.debug_source_window_system);
# ifdef GL_DONT_CARE
	BOOST_CHECK(x != ev.dont_care);
# endif
#endif

#ifdef GL_DONT_CARE
	x = ev.dont_care;
# ifdef GL_DEBUG_SOURCE_API
	BOOST_CHECK(x != ev.debug_source_api);
# endif
# ifdef GL_DEBUG_SOURCE_APPLICATION
	BOOST_CHECK(x != ev.debug_source_application);
# endif
# ifdef GL_DEBUG_SOURCE_OTHER
	BOOST_CHECK(x != ev.debug_source_other);
# endif
# ifdef GL_DEBUG_SOURCE_SHADER_COMPILER
	BOOST_CHECK(x != ev.debug_source_shader_compiler);
# endif
# ifdef GL_DEBUG_SOURCE_THIRD_PARTY
	BOOST_CHECK(x != ev.debug_source_third_party);
# endif
# ifdef GL_DEBUG_SOURCE_WINDOW_SYSTEM
	BOOST_CHECK(x != ev.debug_source_window_system);
# endif
	BOOST_CHECK(x == ev.dont_care);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
