//  File test/oglplus/enums/debug_output_source.cpp
//
//  Automatically generated file, DO NOT modify manually.
//  Edit the enumeration source files in 'source/enums/oglplus'
//  or the 'source/enums/make_enum.py' script instead.
//
//  Copyright Matus Chochlik.
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//   http://www.boost.org/LICENSE_1_0.txt
//
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE OGLPLUS_debug_output_source

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_debug_output_source_tests)

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
	BOOST_CHECK(x == ev.debug_source_window_system);
# ifdef GL_DONT_CARE
	BOOST_CHECK(x != ev.dont_care);
# endif
#endif

#ifdef GL_DONT_CARE
	x = ev.dont_care;
	BOOST_CHECK(x == ev.dont_care);
#endif
}

BOOST_AUTO_TEST_CASE(enum_debug_output_source_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	debug_output_source x;
	(void)x;

#ifdef GL_DEBUG_SOURCE_API
	x = ev.debug_source_api;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DEBUG_SOURCE_API"
	) == 0);
#endif

#ifdef GL_DEBUG_SOURCE_APPLICATION
	x = ev.debug_source_application;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DEBUG_SOURCE_APPLICATION"
	) == 0);
#endif

#ifdef GL_DEBUG_SOURCE_OTHER
	x = ev.debug_source_other;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DEBUG_SOURCE_OTHER"
	) == 0);
#endif

#ifdef GL_DEBUG_SOURCE_SHADER_COMPILER
	x = ev.debug_source_shader_compiler;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DEBUG_SOURCE_SHADER_COMPILER"
	) == 0);
#endif

#ifdef GL_DEBUG_SOURCE_THIRD_PARTY
	x = ev.debug_source_third_party;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DEBUG_SOURCE_THIRD_PARTY"
	) == 0);
#endif

#ifdef GL_DEBUG_SOURCE_WINDOW_SYSTEM
	x = ev.debug_source_window_system;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DEBUG_SOURCE_WINDOW_SYSTEM"
	) == 0);
#endif

#ifdef GL_DONT_CARE
	x = ev.dont_care;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DONT_CARE"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_debug_output_source_range)
{
	using namespace oglplus;
	auto count = enum_value_range<debug_output_source>().size();

#ifdef GL_DEBUG_SOURCE_API
{
	--count;
	auto r = enum_value_range<debug_output_source>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		debug_output_source(GL_DEBUG_SOURCE_API)
	) != r.end());
}
#endif

#ifdef GL_DEBUG_SOURCE_APPLICATION
{
	--count;
	auto r = enum_value_range<debug_output_source>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		debug_output_source(GL_DEBUG_SOURCE_APPLICATION)
	) != r.end());
}
#endif

#ifdef GL_DEBUG_SOURCE_OTHER
{
	--count;
	auto r = enum_value_range<debug_output_source>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		debug_output_source(GL_DEBUG_SOURCE_OTHER)
	) != r.end());
}
#endif

#ifdef GL_DEBUG_SOURCE_SHADER_COMPILER
{
	--count;
	auto r = enum_value_range<debug_output_source>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		debug_output_source(GL_DEBUG_SOURCE_SHADER_COMPILER)
	) != r.end());
}
#endif

#ifdef GL_DEBUG_SOURCE_THIRD_PARTY
{
	--count;
	auto r = enum_value_range<debug_output_source>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		debug_output_source(GL_DEBUG_SOURCE_THIRD_PARTY)
	) != r.end());
}
#endif

#ifdef GL_DEBUG_SOURCE_WINDOW_SYSTEM
{
	--count;
	auto r = enum_value_range<debug_output_source>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		debug_output_source(GL_DEBUG_SOURCE_WINDOW_SYSTEM)
	) != r.end());
}
#endif

#ifdef GL_DONT_CARE
{
	--count;
	auto r = enum_value_range<debug_output_source>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		debug_output_source(GL_DONT_CARE)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_debug_output_source_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	debug_output_source x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_DEBUG_SOURCE_API
	x = ev.debug_source_api;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.debug_source_api);
#endif

#ifdef GL_DEBUG_SOURCE_APPLICATION
	x = ev.debug_source_application;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.debug_source_application);
#endif

#ifdef GL_DEBUG_SOURCE_OTHER
	x = ev.debug_source_other;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.debug_source_other);
#endif

#ifdef GL_DEBUG_SOURCE_SHADER_COMPILER
	x = ev.debug_source_shader_compiler;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.debug_source_shader_compiler);
#endif

#ifdef GL_DEBUG_SOURCE_THIRD_PARTY
	x = ev.debug_source_third_party;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.debug_source_third_party);
#endif

#ifdef GL_DEBUG_SOURCE_WINDOW_SYSTEM
	x = ev.debug_source_window_system;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.debug_source_window_system);
#endif

#ifdef GL_DONT_CARE
	x = ev.dont_care;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.dont_care);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
