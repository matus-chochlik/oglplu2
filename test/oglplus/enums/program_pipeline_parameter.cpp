//  File test/oglplus/enums/program_pipeline_parameter.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_program_pipeline_parameter

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_program_pipeline_parameter_tests)

BOOST_AUTO_TEST_CASE(enum_program_pipeline_parameter_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	program_pipeline_parameter x;
	(void)x;

#ifdef GL_ACTIVE_PROGRAM
	x = ev.active_program;
	BOOST_CHECK(x == ev.active_program);
# ifdef GL_FRAGMENT_SHADER
	BOOST_CHECK(x != ev.fragment_shader);
# endif
# ifdef GL_GEOMETRY_SHADER
	BOOST_CHECK(x != ev.geometry_shader);
# endif
# ifdef GL_INFO_LOG_LENGTH
	BOOST_CHECK(x != ev.info_log_length);
# endif
# ifdef GL_TESS_CONTROL_SHADER
	BOOST_CHECK(x != ev.tess_control_shader);
# endif
# ifdef GL_TESS_EVALUATION_SHADER
	BOOST_CHECK(x != ev.tess_evaluation_shader);
# endif
# ifdef GL_VERTEX_SHADER
	BOOST_CHECK(x != ev.vertex_shader);
# endif
#endif

#ifdef GL_FRAGMENT_SHADER
	x = ev.fragment_shader;
	BOOST_CHECK(x == ev.fragment_shader);
# ifdef GL_GEOMETRY_SHADER
	BOOST_CHECK(x != ev.geometry_shader);
# endif
# ifdef GL_INFO_LOG_LENGTH
	BOOST_CHECK(x != ev.info_log_length);
# endif
# ifdef GL_TESS_CONTROL_SHADER
	BOOST_CHECK(x != ev.tess_control_shader);
# endif
# ifdef GL_TESS_EVALUATION_SHADER
	BOOST_CHECK(x != ev.tess_evaluation_shader);
# endif
# ifdef GL_VERTEX_SHADER
	BOOST_CHECK(x != ev.vertex_shader);
# endif
#endif

#ifdef GL_GEOMETRY_SHADER
	x = ev.geometry_shader;
	BOOST_CHECK(x == ev.geometry_shader);
# ifdef GL_INFO_LOG_LENGTH
	BOOST_CHECK(x != ev.info_log_length);
# endif
# ifdef GL_TESS_CONTROL_SHADER
	BOOST_CHECK(x != ev.tess_control_shader);
# endif
# ifdef GL_TESS_EVALUATION_SHADER
	BOOST_CHECK(x != ev.tess_evaluation_shader);
# endif
# ifdef GL_VERTEX_SHADER
	BOOST_CHECK(x != ev.vertex_shader);
# endif
#endif

#ifdef GL_INFO_LOG_LENGTH
	x = ev.info_log_length;
	BOOST_CHECK(x == ev.info_log_length);
# ifdef GL_TESS_CONTROL_SHADER
	BOOST_CHECK(x != ev.tess_control_shader);
# endif
# ifdef GL_TESS_EVALUATION_SHADER
	BOOST_CHECK(x != ev.tess_evaluation_shader);
# endif
# ifdef GL_VERTEX_SHADER
	BOOST_CHECK(x != ev.vertex_shader);
# endif
#endif

#ifdef GL_TESS_CONTROL_SHADER
	x = ev.tess_control_shader;
	BOOST_CHECK(x == ev.tess_control_shader);
# ifdef GL_TESS_EVALUATION_SHADER
	BOOST_CHECK(x != ev.tess_evaluation_shader);
# endif
# ifdef GL_VERTEX_SHADER
	BOOST_CHECK(x != ev.vertex_shader);
# endif
#endif

#ifdef GL_TESS_EVALUATION_SHADER
	x = ev.tess_evaluation_shader;
	BOOST_CHECK(x == ev.tess_evaluation_shader);
# ifdef GL_VERTEX_SHADER
	BOOST_CHECK(x != ev.vertex_shader);
# endif
#endif

#ifdef GL_VERTEX_SHADER
	x = ev.vertex_shader;
	BOOST_CHECK(x == ev.vertex_shader);
#endif
}

BOOST_AUTO_TEST_CASE(enum_program_pipeline_parameter_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	program_pipeline_parameter x;
	(void)x;

#ifdef GL_ACTIVE_PROGRAM
	x = ev.active_program;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ACTIVE_PROGRAM"
	) == 0);
#endif

#ifdef GL_FRAGMENT_SHADER
	x = ev.fragment_shader;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"FRAGMENT_SHADER"
	) == 0);
#endif

#ifdef GL_GEOMETRY_SHADER
	x = ev.geometry_shader;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"GEOMETRY_SHADER"
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

#ifdef GL_TESS_CONTROL_SHADER
	x = ev.tess_control_shader;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TESS_CONTROL_SHADER"
	) == 0);
#endif

#ifdef GL_TESS_EVALUATION_SHADER
	x = ev.tess_evaluation_shader;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TESS_EVALUATION_SHADER"
	) == 0);
#endif

#ifdef GL_VERTEX_SHADER
	x = ev.vertex_shader;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"VERTEX_SHADER"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_program_pipeline_parameter_range)
{
	using namespace oglplus;
	auto count = enum_value_range<program_pipeline_parameter>().size();

#ifdef GL_ACTIVE_PROGRAM
{
	--count;
	auto r = enum_value_range<program_pipeline_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		program_pipeline_parameter(GL_ACTIVE_PROGRAM)
	) != r.end());
}
#endif

#ifdef GL_FRAGMENT_SHADER
{
	--count;
	auto r = enum_value_range<program_pipeline_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		program_pipeline_parameter(GL_FRAGMENT_SHADER)
	) != r.end());
}
#endif

#ifdef GL_GEOMETRY_SHADER
{
	--count;
	auto r = enum_value_range<program_pipeline_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		program_pipeline_parameter(GL_GEOMETRY_SHADER)
	) != r.end());
}
#endif

#ifdef GL_INFO_LOG_LENGTH
{
	--count;
	auto r = enum_value_range<program_pipeline_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		program_pipeline_parameter(GL_INFO_LOG_LENGTH)
	) != r.end());
}
#endif

#ifdef GL_TESS_CONTROL_SHADER
{
	--count;
	auto r = enum_value_range<program_pipeline_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		program_pipeline_parameter(GL_TESS_CONTROL_SHADER)
	) != r.end());
}
#endif

#ifdef GL_TESS_EVALUATION_SHADER
{
	--count;
	auto r = enum_value_range<program_pipeline_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		program_pipeline_parameter(GL_TESS_EVALUATION_SHADER)
	) != r.end());
}
#endif

#ifdef GL_VERTEX_SHADER
{
	--count;
	auto r = enum_value_range<program_pipeline_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		program_pipeline_parameter(GL_VERTEX_SHADER)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_program_pipeline_parameter_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	program_pipeline_parameter x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_ACTIVE_PROGRAM
	x = ev.active_program;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.active_program);
#endif

#ifdef GL_FRAGMENT_SHADER
	x = ev.fragment_shader;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.fragment_shader);
#endif

#ifdef GL_GEOMETRY_SHADER
	x = ev.geometry_shader;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.geometry_shader);
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

#ifdef GL_TESS_CONTROL_SHADER
	x = ev.tess_control_shader;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.tess_control_shader);
#endif

#ifdef GL_TESS_EVALUATION_SHADER
	x = ev.tess_evaluation_shader;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.tess_evaluation_shader);
#endif

#ifdef GL_VERTEX_SHADER
	x = ev.vertex_shader;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.vertex_shader);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
