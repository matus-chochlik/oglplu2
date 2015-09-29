//  File test/oglplus/enums/program_pipeline_stage.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_program_pipeline_stage

#include <boost/test/unit_test.hpp>
#include "common.hpp"

BOOST_AUTO_TEST_SUITE(enum_program_pipeline_stage)

BOOST_AUTO_TEST_CASE(enum_program_pipeline_stage_values)
{
	using namespace oglplus;
	enum_values ev;
	program_pipeline_stage x;

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
# ifdef GL_ALL_SHADER_BITS
	BOOST_CHECK(x != ev.all_shader_bits);
# endif
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
# ifdef GL_ALL_SHADER_BITS
	BOOST_CHECK(x != ev.all_shader_bits);
# endif
# ifdef GL_COMPUTE_SHADER_BIT
	BOOST_CHECK(x != ev.compute_shader_bit);
# endif
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
# ifdef GL_ALL_SHADER_BITS
	BOOST_CHECK(x != ev.all_shader_bits);
# endif
# ifdef GL_COMPUTE_SHADER_BIT
	BOOST_CHECK(x != ev.compute_shader_bit);
# endif
# ifdef GL_FRAGMENT_SHADER_BIT
	BOOST_CHECK(x != ev.fragment_shader_bit);
# endif
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
# ifdef GL_ALL_SHADER_BITS
	BOOST_CHECK(x != ev.all_shader_bits);
# endif
# ifdef GL_COMPUTE_SHADER_BIT
	BOOST_CHECK(x != ev.compute_shader_bit);
# endif
# ifdef GL_FRAGMENT_SHADER_BIT
	BOOST_CHECK(x != ev.fragment_shader_bit);
# endif
# ifdef GL_GEOMETRY_SHADER_BIT
	BOOST_CHECK(x != ev.geometry_shader_bit);
# endif
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
# ifdef GL_ALL_SHADER_BITS
	BOOST_CHECK(x != ev.all_shader_bits);
# endif
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
	BOOST_CHECK(x == ev.tess_evaluation_shader_bit);
# ifdef GL_VERTEX_SHADER_BIT
	BOOST_CHECK(x != ev.vertex_shader_bit);
# endif
#endif

#ifdef GL_VERTEX_SHADER_BIT
	x = ev.vertex_shader_bit;
# ifdef GL_ALL_SHADER_BITS
	BOOST_CHECK(x != ev.all_shader_bits);
# endif
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
	BOOST_CHECK(x == ev.vertex_shader_bit);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
