//  File test/oglplus/enums/shader_parameter.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_shader_parameter

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_shader_parameter_tests)

BOOST_AUTO_TEST_CASE(enum_shader_parameter_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	shader_parameter x;
	(void)x;

#ifdef GL_COMPILE_STATUS
	x = ev.compile_status;
	BOOST_CHECK(x == ev.compile_status);
# ifdef GL_DELETE_STATUS
	BOOST_CHECK(x != ev.delete_status);
# endif
# ifdef GL_INFO_LOG_LENGTH
	BOOST_CHECK(x != ev.info_log_length);
# endif
# ifdef GL_SHADER_SOURCE_LENGTH
	BOOST_CHECK(x != ev.shader_source_length);
# endif
# ifdef GL_SHADER_TYPE
	BOOST_CHECK(x != ev.shader_type);
# endif
#endif

#ifdef GL_DELETE_STATUS
	x = ev.delete_status;
	BOOST_CHECK(x == ev.delete_status);
# ifdef GL_INFO_LOG_LENGTH
	BOOST_CHECK(x != ev.info_log_length);
# endif
# ifdef GL_SHADER_SOURCE_LENGTH
	BOOST_CHECK(x != ev.shader_source_length);
# endif
# ifdef GL_SHADER_TYPE
	BOOST_CHECK(x != ev.shader_type);
# endif
#endif

#ifdef GL_INFO_LOG_LENGTH
	x = ev.info_log_length;
	BOOST_CHECK(x == ev.info_log_length);
# ifdef GL_SHADER_SOURCE_LENGTH
	BOOST_CHECK(x != ev.shader_source_length);
# endif
# ifdef GL_SHADER_TYPE
	BOOST_CHECK(x != ev.shader_type);
# endif
#endif

#ifdef GL_SHADER_SOURCE_LENGTH
	x = ev.shader_source_length;
	BOOST_CHECK(x == ev.shader_source_length);
# ifdef GL_SHADER_TYPE
	BOOST_CHECK(x != ev.shader_type);
# endif
#endif

#ifdef GL_SHADER_TYPE
	x = ev.shader_type;
	BOOST_CHECK(x == ev.shader_type);
#endif
}

BOOST_AUTO_TEST_CASE(enum_shader_parameter_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	shader_parameter x;
	(void)x;

#ifdef GL_COMPILE_STATUS
	x = ev.compile_status;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"COMPILE_STATUS"
	) == 0);
#endif

#ifdef GL_DELETE_STATUS
	x = ev.delete_status;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DELETE_STATUS"
	) == 0);
#endif

#ifdef GL_INFO_LOG_LENGTH
	x = ev.info_log_length;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"INFO_LOG_LENGTH"
	) == 0);
#endif

#ifdef GL_SHADER_SOURCE_LENGTH
	x = ev.shader_source_length;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SHADER_SOURCE_LENGTH"
	) == 0);
#endif

#ifdef GL_SHADER_TYPE
	x = ev.shader_type;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SHADER_TYPE"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_shader_parameter_range)
{
	using namespace oglplus;
	auto count = enum_value_range<shader_parameter>().size();

#ifdef GL_COMPILE_STATUS
{
	--count;
	auto r = enum_value_range<shader_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		shader_parameter(GL_COMPILE_STATUS)
	) != r.end());
}
#endif

#ifdef GL_DELETE_STATUS
{
	--count;
	auto r = enum_value_range<shader_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		shader_parameter(GL_DELETE_STATUS)
	) != r.end());
}
#endif

#ifdef GL_INFO_LOG_LENGTH
{
	--count;
	auto r = enum_value_range<shader_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		shader_parameter(GL_INFO_LOG_LENGTH)
	) != r.end());
}
#endif

#ifdef GL_SHADER_SOURCE_LENGTH
{
	--count;
	auto r = enum_value_range<shader_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		shader_parameter(GL_SHADER_SOURCE_LENGTH)
	) != r.end());
}
#endif

#ifdef GL_SHADER_TYPE
{
	--count;
	auto r = enum_value_range<shader_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		shader_parameter(GL_SHADER_TYPE)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_shader_parameter_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	shader_parameter x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_COMPILE_STATUS
	x = ev.compile_status;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.compile_status);
#endif

#ifdef GL_DELETE_STATUS
	x = ev.delete_status;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.delete_status);
#endif

#ifdef GL_INFO_LOG_LENGTH
	x = ev.info_log_length;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.info_log_length);
#endif

#ifdef GL_SHADER_SOURCE_LENGTH
	x = ev.shader_source_length;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.shader_source_length);
#endif

#ifdef GL_SHADER_TYPE
	x = ev.shader_type;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.shader_type);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
