//  File test/oglplus/enums/program_pipeline_stage.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_program_pipeline_stage

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_program_pipeline_stage_tests)

BOOST_AUTO_TEST_CASE(enum_program_pipeline_stage_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	program_pipeline_stage x;
	(void)x;

#ifdef GL_ALL_SHADER_BITS
	x = ev.all_shader_bits;
	BOOST_CHECK(x == ev.all_shader_bits);
# ifdef GL_COMPUTE_SHADER_BIT
	BOOST_CHECK(x != ev.compute_shader_bit);
# endif
# ifdef GL_FRAGMENT_SHADER_BIT
	BOOST_CHECK(x != ev.fragment_shader_bit);
# endif
# ifdef GL_GEOMETRY_SHADER_BIT
	BOOST_CHECK(x != ev.geometry_shader_bit);
# endif
# ifdef GL_TESS_CONTROL_SHADER_BIT
	BOOST_CHECK(x != ev.tess_control_shader_bit);
# endif
# ifdef GL_TESS_EVALUATION_SHADER_BIT
	BOOST_CHECK(x != ev.tess_evaluation_shader_bit);
# endif
# ifdef GL_VERTEX_SHADER_BIT
	BOOST_CHECK(x != ev.vertex_shader_bit);
# endif
#endif

#ifdef GL_COMPUTE_SHADER_BIT
	x = ev.compute_shader_bit;
	BOOST_CHECK(x == ev.compute_shader_bit);
# ifdef GL_FRAGMENT_SHADER_BIT
	BOOST_CHECK(x != ev.fragment_shader_bit);
# endif
# ifdef GL_GEOMETRY_SHADER_BIT
	BOOST_CHECK(x != ev.geometry_shader_bit);
# endif
# ifdef GL_TESS_CONTROL_SHADER_BIT
	BOOST_CHECK(x != ev.tess_control_shader_bit);
# endif
# ifdef GL_TESS_EVALUATION_SHADER_BIT
	BOOST_CHECK(x != ev.tess_evaluation_shader_bit);
# endif
# ifdef GL_VERTEX_SHADER_BIT
	BOOST_CHECK(x != ev.vertex_shader_bit);
# endif
#endif

#ifdef GL_FRAGMENT_SHADER_BIT
	x = ev.fragment_shader_bit;
	BOOST_CHECK(x == ev.fragment_shader_bit);
# ifdef GL_GEOMETRY_SHADER_BIT
	BOOST_CHECK(x != ev.geometry_shader_bit);
# endif
# ifdef GL_TESS_CONTROL_SHADER_BIT
	BOOST_CHECK(x != ev.tess_control_shader_bit);
# endif
# ifdef GL_TESS_EVALUATION_SHADER_BIT
	BOOST_CHECK(x != ev.tess_evaluation_shader_bit);
# endif
# ifdef GL_VERTEX_SHADER_BIT
	BOOST_CHECK(x != ev.vertex_shader_bit);
# endif
#endif

#ifdef GL_GEOMETRY_SHADER_BIT
	x = ev.geometry_shader_bit;
	BOOST_CHECK(x == ev.geometry_shader_bit);
# ifdef GL_TESS_CONTROL_SHADER_BIT
	BOOST_CHECK(x != ev.tess_control_shader_bit);
# endif
# ifdef GL_TESS_EVALUATION_SHADER_BIT
	BOOST_CHECK(x != ev.tess_evaluation_shader_bit);
# endif
# ifdef GL_VERTEX_SHADER_BIT
	BOOST_CHECK(x != ev.vertex_shader_bit);
# endif
#endif

#ifdef GL_TESS_CONTROL_SHADER_BIT
	x = ev.tess_control_shader_bit;
	BOOST_CHECK(x == ev.tess_control_shader_bit);
# ifdef GL_TESS_EVALUATION_SHADER_BIT
	BOOST_CHECK(x != ev.tess_evaluation_shader_bit);
# endif
# ifdef GL_VERTEX_SHADER_BIT
	BOOST_CHECK(x != ev.vertex_shader_bit);
# endif
#endif

#ifdef GL_TESS_EVALUATION_SHADER_BIT
	x = ev.tess_evaluation_shader_bit;
	BOOST_CHECK(x == ev.tess_evaluation_shader_bit);
# ifdef GL_VERTEX_SHADER_BIT
	BOOST_CHECK(x != ev.vertex_shader_bit);
# endif
#endif

#ifdef GL_VERTEX_SHADER_BIT
	x = ev.vertex_shader_bit;
	BOOST_CHECK(x == ev.vertex_shader_bit);
#endif
}

BOOST_AUTO_TEST_CASE(enum_program_pipeline_stage_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	program_pipeline_stage x;
	(void)x;

#ifdef GL_ALL_SHADER_BITS
	x = ev.all_shader_bits;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ALL_SHADER_BITS"
	) == 0);
#endif

#ifdef GL_COMPUTE_SHADER_BIT
	x = ev.compute_shader_bit;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"COMPUTE_SHADER_BIT"
	) == 0);
#endif

#ifdef GL_FRAGMENT_SHADER_BIT
	x = ev.fragment_shader_bit;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"FRAGMENT_SHADER_BIT"
	) == 0);
#endif

#ifdef GL_GEOMETRY_SHADER_BIT
	x = ev.geometry_shader_bit;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"GEOMETRY_SHADER_BIT"
	) == 0);
#endif

#ifdef GL_TESS_CONTROL_SHADER_BIT
	x = ev.tess_control_shader_bit;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TESS_CONTROL_SHADER_BIT"
	) == 0);
#endif

#ifdef GL_TESS_EVALUATION_SHADER_BIT
	x = ev.tess_evaluation_shader_bit;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TESS_EVALUATION_SHADER_BIT"
	) == 0);
#endif

#ifdef GL_VERTEX_SHADER_BIT
	x = ev.vertex_shader_bit;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"VERTEX_SHADER_BIT"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_program_pipeline_stage_range)
{
	using namespace oglplus;
	auto count = enum_value_range<program_pipeline_stage>().size();

#ifdef GL_ALL_SHADER_BITS
{
	--count;
	auto r = enum_value_range<program_pipeline_stage>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		program_pipeline_stage(GL_ALL_SHADER_BITS)
	) != r.end());
}
#endif

#ifdef GL_COMPUTE_SHADER_BIT
{
	--count;
	auto r = enum_value_range<program_pipeline_stage>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		program_pipeline_stage(GL_COMPUTE_SHADER_BIT)
	) != r.end());
}
#endif

#ifdef GL_FRAGMENT_SHADER_BIT
{
	--count;
	auto r = enum_value_range<program_pipeline_stage>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		program_pipeline_stage(GL_FRAGMENT_SHADER_BIT)
	) != r.end());
}
#endif

#ifdef GL_GEOMETRY_SHADER_BIT
{
	--count;
	auto r = enum_value_range<program_pipeline_stage>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		program_pipeline_stage(GL_GEOMETRY_SHADER_BIT)
	) != r.end());
}
#endif

#ifdef GL_TESS_CONTROL_SHADER_BIT
{
	--count;
	auto r = enum_value_range<program_pipeline_stage>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		program_pipeline_stage(GL_TESS_CONTROL_SHADER_BIT)
	) != r.end());
}
#endif

#ifdef GL_TESS_EVALUATION_SHADER_BIT
{
	--count;
	auto r = enum_value_range<program_pipeline_stage>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		program_pipeline_stage(GL_TESS_EVALUATION_SHADER_BIT)
	) != r.end());
}
#endif

#ifdef GL_VERTEX_SHADER_BIT
{
	--count;
	auto r = enum_value_range<program_pipeline_stage>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		program_pipeline_stage(GL_VERTEX_SHADER_BIT)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_program_pipeline_stage_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	program_pipeline_stage x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_ALL_SHADER_BITS
	x = ev.all_shader_bits;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.all_shader_bits);
#endif

#ifdef GL_COMPUTE_SHADER_BIT
	x = ev.compute_shader_bit;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.compute_shader_bit);
#endif

#ifdef GL_FRAGMENT_SHADER_BIT
	x = ev.fragment_shader_bit;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.fragment_shader_bit);
#endif

#ifdef GL_GEOMETRY_SHADER_BIT
	x = ev.geometry_shader_bit;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.geometry_shader_bit);
#endif

#ifdef GL_TESS_CONTROL_SHADER_BIT
	x = ev.tess_control_shader_bit;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.tess_control_shader_bit);
#endif

#ifdef GL_TESS_EVALUATION_SHADER_BIT
	x = ev.tess_evaluation_shader_bit;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.tess_evaluation_shader_bit);
#endif

#ifdef GL_VERTEX_SHADER_BIT
	x = ev.vertex_shader_bit;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.vertex_shader_bit);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
