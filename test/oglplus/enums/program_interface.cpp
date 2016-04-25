//  File test/oglplus/enums/program_interface.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_program_interface

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_program_interface_tests)

BOOST_AUTO_TEST_CASE(enum_program_interface_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	program_interface x;
	(void)x;

#ifdef GL_ATOMIC_COUNTER_BUFFER
	x = ev.atomic_counter_buffer;
	BOOST_CHECK(x == ev.atomic_counter_buffer);
# ifdef GL_BUFFER_VARIABLE
	BOOST_CHECK(x != ev.buffer_variable);
# endif
# ifdef GL_COMPUTE_SUBROUTINE
	BOOST_CHECK(x != ev.compute_subroutine);
# endif
# ifdef GL_COMPUTE_SUBROUTINE_UNIFORM
	BOOST_CHECK(x != ev.compute_subroutine_uniform);
# endif
# ifdef GL_FRAGMENT_SUBROUTINE
	BOOST_CHECK(x != ev.fragment_subroutine);
# endif
# ifdef GL_FRAGMENT_SUBROUTINE_UNIFORM
	BOOST_CHECK(x != ev.fragment_subroutine_uniform);
# endif
# ifdef GL_GEOMETRY_SUBROUTINE
	BOOST_CHECK(x != ev.geometry_subroutine);
# endif
# ifdef GL_GEOMETRY_SUBROUTINE_UNIFORM
	BOOST_CHECK(x != ev.geometry_subroutine_uniform);
# endif
# ifdef GL_PROGRAM_INPUT
	BOOST_CHECK(x != ev.program_input);
# endif
# ifdef GL_PROGRAM_OUTPUT
	BOOST_CHECK(x != ev.program_output);
# endif
# ifdef GL_SHADER_STORAGE_BLOCK
	BOOST_CHECK(x != ev.shader_storage_block);
# endif
# ifdef GL_TESS_CONTROL_SUBROUTINE
	BOOST_CHECK(x != ev.tess_control_subroutine);
# endif
# ifdef GL_TESS_CONTROL_SUBROUTINE_UNIFORM
	BOOST_CHECK(x != ev.tess_control_subroutine_uniform);
# endif
# ifdef GL_TESS_EVALUATION_SUBROUTINE
	BOOST_CHECK(x != ev.tess_evaluation_subroutine);
# endif
# ifdef GL_TESS_EVALUATION_SUBROUTINE_UNIFORM
	BOOST_CHECK(x != ev.tess_evaluation_subroutine_uniform);
# endif
# ifdef GL_TRANSFORM_FEEDEBACK_VARYING
	BOOST_CHECK(x != ev.transform_feedeback_varying);
# endif
# ifdef GL_UNIFORM
	BOOST_CHECK(x != ev.uniform);
# endif
# ifdef GL_UNIFORM_BLOCK
	BOOST_CHECK(x != ev.uniform_block);
# endif
# ifdef GL_VERTEX_SUBROUTINE
	BOOST_CHECK(x != ev.vertex_subroutine);
# endif
# ifdef GL_VERTEX_SUBROUTINE_UNIFORM
	BOOST_CHECK(x != ev.vertex_subroutine_uniform);
# endif
#endif

#ifdef GL_BUFFER_VARIABLE
	x = ev.buffer_variable;
	BOOST_CHECK(x == ev.buffer_variable);
# ifdef GL_COMPUTE_SUBROUTINE
	BOOST_CHECK(x != ev.compute_subroutine);
# endif
# ifdef GL_COMPUTE_SUBROUTINE_UNIFORM
	BOOST_CHECK(x != ev.compute_subroutine_uniform);
# endif
# ifdef GL_FRAGMENT_SUBROUTINE
	BOOST_CHECK(x != ev.fragment_subroutine);
# endif
# ifdef GL_FRAGMENT_SUBROUTINE_UNIFORM
	BOOST_CHECK(x != ev.fragment_subroutine_uniform);
# endif
# ifdef GL_GEOMETRY_SUBROUTINE
	BOOST_CHECK(x != ev.geometry_subroutine);
# endif
# ifdef GL_GEOMETRY_SUBROUTINE_UNIFORM
	BOOST_CHECK(x != ev.geometry_subroutine_uniform);
# endif
# ifdef GL_PROGRAM_INPUT
	BOOST_CHECK(x != ev.program_input);
# endif
# ifdef GL_PROGRAM_OUTPUT
	BOOST_CHECK(x != ev.program_output);
# endif
# ifdef GL_SHADER_STORAGE_BLOCK
	BOOST_CHECK(x != ev.shader_storage_block);
# endif
# ifdef GL_TESS_CONTROL_SUBROUTINE
	BOOST_CHECK(x != ev.tess_control_subroutine);
# endif
# ifdef GL_TESS_CONTROL_SUBROUTINE_UNIFORM
	BOOST_CHECK(x != ev.tess_control_subroutine_uniform);
# endif
# ifdef GL_TESS_EVALUATION_SUBROUTINE
	BOOST_CHECK(x != ev.tess_evaluation_subroutine);
# endif
# ifdef GL_TESS_EVALUATION_SUBROUTINE_UNIFORM
	BOOST_CHECK(x != ev.tess_evaluation_subroutine_uniform);
# endif
# ifdef GL_TRANSFORM_FEEDEBACK_VARYING
	BOOST_CHECK(x != ev.transform_feedeback_varying);
# endif
# ifdef GL_UNIFORM
	BOOST_CHECK(x != ev.uniform);
# endif
# ifdef GL_UNIFORM_BLOCK
	BOOST_CHECK(x != ev.uniform_block);
# endif
# ifdef GL_VERTEX_SUBROUTINE
	BOOST_CHECK(x != ev.vertex_subroutine);
# endif
# ifdef GL_VERTEX_SUBROUTINE_UNIFORM
	BOOST_CHECK(x != ev.vertex_subroutine_uniform);
# endif
#endif

#ifdef GL_COMPUTE_SUBROUTINE
	x = ev.compute_subroutine;
	BOOST_CHECK(x == ev.compute_subroutine);
# ifdef GL_COMPUTE_SUBROUTINE_UNIFORM
	BOOST_CHECK(x != ev.compute_subroutine_uniform);
# endif
# ifdef GL_FRAGMENT_SUBROUTINE
	BOOST_CHECK(x != ev.fragment_subroutine);
# endif
# ifdef GL_FRAGMENT_SUBROUTINE_UNIFORM
	BOOST_CHECK(x != ev.fragment_subroutine_uniform);
# endif
# ifdef GL_GEOMETRY_SUBROUTINE
	BOOST_CHECK(x != ev.geometry_subroutine);
# endif
# ifdef GL_GEOMETRY_SUBROUTINE_UNIFORM
	BOOST_CHECK(x != ev.geometry_subroutine_uniform);
# endif
# ifdef GL_PROGRAM_INPUT
	BOOST_CHECK(x != ev.program_input);
# endif
# ifdef GL_PROGRAM_OUTPUT
	BOOST_CHECK(x != ev.program_output);
# endif
# ifdef GL_SHADER_STORAGE_BLOCK
	BOOST_CHECK(x != ev.shader_storage_block);
# endif
# ifdef GL_TESS_CONTROL_SUBROUTINE
	BOOST_CHECK(x != ev.tess_control_subroutine);
# endif
# ifdef GL_TESS_CONTROL_SUBROUTINE_UNIFORM
	BOOST_CHECK(x != ev.tess_control_subroutine_uniform);
# endif
# ifdef GL_TESS_EVALUATION_SUBROUTINE
	BOOST_CHECK(x != ev.tess_evaluation_subroutine);
# endif
# ifdef GL_TESS_EVALUATION_SUBROUTINE_UNIFORM
	BOOST_CHECK(x != ev.tess_evaluation_subroutine_uniform);
# endif
# ifdef GL_TRANSFORM_FEEDEBACK_VARYING
	BOOST_CHECK(x != ev.transform_feedeback_varying);
# endif
# ifdef GL_UNIFORM
	BOOST_CHECK(x != ev.uniform);
# endif
# ifdef GL_UNIFORM_BLOCK
	BOOST_CHECK(x != ev.uniform_block);
# endif
# ifdef GL_VERTEX_SUBROUTINE
	BOOST_CHECK(x != ev.vertex_subroutine);
# endif
# ifdef GL_VERTEX_SUBROUTINE_UNIFORM
	BOOST_CHECK(x != ev.vertex_subroutine_uniform);
# endif
#endif

#ifdef GL_COMPUTE_SUBROUTINE_UNIFORM
	x = ev.compute_subroutine_uniform;
	BOOST_CHECK(x == ev.compute_subroutine_uniform);
# ifdef GL_FRAGMENT_SUBROUTINE
	BOOST_CHECK(x != ev.fragment_subroutine);
# endif
# ifdef GL_FRAGMENT_SUBROUTINE_UNIFORM
	BOOST_CHECK(x != ev.fragment_subroutine_uniform);
# endif
# ifdef GL_GEOMETRY_SUBROUTINE
	BOOST_CHECK(x != ev.geometry_subroutine);
# endif
# ifdef GL_GEOMETRY_SUBROUTINE_UNIFORM
	BOOST_CHECK(x != ev.geometry_subroutine_uniform);
# endif
# ifdef GL_PROGRAM_INPUT
	BOOST_CHECK(x != ev.program_input);
# endif
# ifdef GL_PROGRAM_OUTPUT
	BOOST_CHECK(x != ev.program_output);
# endif
# ifdef GL_SHADER_STORAGE_BLOCK
	BOOST_CHECK(x != ev.shader_storage_block);
# endif
# ifdef GL_TESS_CONTROL_SUBROUTINE
	BOOST_CHECK(x != ev.tess_control_subroutine);
# endif
# ifdef GL_TESS_CONTROL_SUBROUTINE_UNIFORM
	BOOST_CHECK(x != ev.tess_control_subroutine_uniform);
# endif
# ifdef GL_TESS_EVALUATION_SUBROUTINE
	BOOST_CHECK(x != ev.tess_evaluation_subroutine);
# endif
# ifdef GL_TESS_EVALUATION_SUBROUTINE_UNIFORM
	BOOST_CHECK(x != ev.tess_evaluation_subroutine_uniform);
# endif
# ifdef GL_TRANSFORM_FEEDEBACK_VARYING
	BOOST_CHECK(x != ev.transform_feedeback_varying);
# endif
# ifdef GL_UNIFORM
	BOOST_CHECK(x != ev.uniform);
# endif
# ifdef GL_UNIFORM_BLOCK
	BOOST_CHECK(x != ev.uniform_block);
# endif
# ifdef GL_VERTEX_SUBROUTINE
	BOOST_CHECK(x != ev.vertex_subroutine);
# endif
# ifdef GL_VERTEX_SUBROUTINE_UNIFORM
	BOOST_CHECK(x != ev.vertex_subroutine_uniform);
# endif
#endif

#ifdef GL_FRAGMENT_SUBROUTINE
	x = ev.fragment_subroutine;
	BOOST_CHECK(x == ev.fragment_subroutine);
# ifdef GL_FRAGMENT_SUBROUTINE_UNIFORM
	BOOST_CHECK(x != ev.fragment_subroutine_uniform);
# endif
# ifdef GL_GEOMETRY_SUBROUTINE
	BOOST_CHECK(x != ev.geometry_subroutine);
# endif
# ifdef GL_GEOMETRY_SUBROUTINE_UNIFORM
	BOOST_CHECK(x != ev.geometry_subroutine_uniform);
# endif
# ifdef GL_PROGRAM_INPUT
	BOOST_CHECK(x != ev.program_input);
# endif
# ifdef GL_PROGRAM_OUTPUT
	BOOST_CHECK(x != ev.program_output);
# endif
# ifdef GL_SHADER_STORAGE_BLOCK
	BOOST_CHECK(x != ev.shader_storage_block);
# endif
# ifdef GL_TESS_CONTROL_SUBROUTINE
	BOOST_CHECK(x != ev.tess_control_subroutine);
# endif
# ifdef GL_TESS_CONTROL_SUBROUTINE_UNIFORM
	BOOST_CHECK(x != ev.tess_control_subroutine_uniform);
# endif
# ifdef GL_TESS_EVALUATION_SUBROUTINE
	BOOST_CHECK(x != ev.tess_evaluation_subroutine);
# endif
# ifdef GL_TESS_EVALUATION_SUBROUTINE_UNIFORM
	BOOST_CHECK(x != ev.tess_evaluation_subroutine_uniform);
# endif
# ifdef GL_TRANSFORM_FEEDEBACK_VARYING
	BOOST_CHECK(x != ev.transform_feedeback_varying);
# endif
# ifdef GL_UNIFORM
	BOOST_CHECK(x != ev.uniform);
# endif
# ifdef GL_UNIFORM_BLOCK
	BOOST_CHECK(x != ev.uniform_block);
# endif
# ifdef GL_VERTEX_SUBROUTINE
	BOOST_CHECK(x != ev.vertex_subroutine);
# endif
# ifdef GL_VERTEX_SUBROUTINE_UNIFORM
	BOOST_CHECK(x != ev.vertex_subroutine_uniform);
# endif
#endif

#ifdef GL_FRAGMENT_SUBROUTINE_UNIFORM
	x = ev.fragment_subroutine_uniform;
	BOOST_CHECK(x == ev.fragment_subroutine_uniform);
# ifdef GL_GEOMETRY_SUBROUTINE
	BOOST_CHECK(x != ev.geometry_subroutine);
# endif
# ifdef GL_GEOMETRY_SUBROUTINE_UNIFORM
	BOOST_CHECK(x != ev.geometry_subroutine_uniform);
# endif
# ifdef GL_PROGRAM_INPUT
	BOOST_CHECK(x != ev.program_input);
# endif
# ifdef GL_PROGRAM_OUTPUT
	BOOST_CHECK(x != ev.program_output);
# endif
# ifdef GL_SHADER_STORAGE_BLOCK
	BOOST_CHECK(x != ev.shader_storage_block);
# endif
# ifdef GL_TESS_CONTROL_SUBROUTINE
	BOOST_CHECK(x != ev.tess_control_subroutine);
# endif
# ifdef GL_TESS_CONTROL_SUBROUTINE_UNIFORM
	BOOST_CHECK(x != ev.tess_control_subroutine_uniform);
# endif
# ifdef GL_TESS_EVALUATION_SUBROUTINE
	BOOST_CHECK(x != ev.tess_evaluation_subroutine);
# endif
# ifdef GL_TESS_EVALUATION_SUBROUTINE_UNIFORM
	BOOST_CHECK(x != ev.tess_evaluation_subroutine_uniform);
# endif
# ifdef GL_TRANSFORM_FEEDEBACK_VARYING
	BOOST_CHECK(x != ev.transform_feedeback_varying);
# endif
# ifdef GL_UNIFORM
	BOOST_CHECK(x != ev.uniform);
# endif
# ifdef GL_UNIFORM_BLOCK
	BOOST_CHECK(x != ev.uniform_block);
# endif
# ifdef GL_VERTEX_SUBROUTINE
	BOOST_CHECK(x != ev.vertex_subroutine);
# endif
# ifdef GL_VERTEX_SUBROUTINE_UNIFORM
	BOOST_CHECK(x != ev.vertex_subroutine_uniform);
# endif
#endif

#ifdef GL_GEOMETRY_SUBROUTINE
	x = ev.geometry_subroutine;
	BOOST_CHECK(x == ev.geometry_subroutine);
# ifdef GL_GEOMETRY_SUBROUTINE_UNIFORM
	BOOST_CHECK(x != ev.geometry_subroutine_uniform);
# endif
# ifdef GL_PROGRAM_INPUT
	BOOST_CHECK(x != ev.program_input);
# endif
# ifdef GL_PROGRAM_OUTPUT
	BOOST_CHECK(x != ev.program_output);
# endif
# ifdef GL_SHADER_STORAGE_BLOCK
	BOOST_CHECK(x != ev.shader_storage_block);
# endif
# ifdef GL_TESS_CONTROL_SUBROUTINE
	BOOST_CHECK(x != ev.tess_control_subroutine);
# endif
# ifdef GL_TESS_CONTROL_SUBROUTINE_UNIFORM
	BOOST_CHECK(x != ev.tess_control_subroutine_uniform);
# endif
# ifdef GL_TESS_EVALUATION_SUBROUTINE
	BOOST_CHECK(x != ev.tess_evaluation_subroutine);
# endif
# ifdef GL_TESS_EVALUATION_SUBROUTINE_UNIFORM
	BOOST_CHECK(x != ev.tess_evaluation_subroutine_uniform);
# endif
# ifdef GL_TRANSFORM_FEEDEBACK_VARYING
	BOOST_CHECK(x != ev.transform_feedeback_varying);
# endif
# ifdef GL_UNIFORM
	BOOST_CHECK(x != ev.uniform);
# endif
# ifdef GL_UNIFORM_BLOCK
	BOOST_CHECK(x != ev.uniform_block);
# endif
# ifdef GL_VERTEX_SUBROUTINE
	BOOST_CHECK(x != ev.vertex_subroutine);
# endif
# ifdef GL_VERTEX_SUBROUTINE_UNIFORM
	BOOST_CHECK(x != ev.vertex_subroutine_uniform);
# endif
#endif

#ifdef GL_GEOMETRY_SUBROUTINE_UNIFORM
	x = ev.geometry_subroutine_uniform;
	BOOST_CHECK(x == ev.geometry_subroutine_uniform);
# ifdef GL_PROGRAM_INPUT
	BOOST_CHECK(x != ev.program_input);
# endif
# ifdef GL_PROGRAM_OUTPUT
	BOOST_CHECK(x != ev.program_output);
# endif
# ifdef GL_SHADER_STORAGE_BLOCK
	BOOST_CHECK(x != ev.shader_storage_block);
# endif
# ifdef GL_TESS_CONTROL_SUBROUTINE
	BOOST_CHECK(x != ev.tess_control_subroutine);
# endif
# ifdef GL_TESS_CONTROL_SUBROUTINE_UNIFORM
	BOOST_CHECK(x != ev.tess_control_subroutine_uniform);
# endif
# ifdef GL_TESS_EVALUATION_SUBROUTINE
	BOOST_CHECK(x != ev.tess_evaluation_subroutine);
# endif
# ifdef GL_TESS_EVALUATION_SUBROUTINE_UNIFORM
	BOOST_CHECK(x != ev.tess_evaluation_subroutine_uniform);
# endif
# ifdef GL_TRANSFORM_FEEDEBACK_VARYING
	BOOST_CHECK(x != ev.transform_feedeback_varying);
# endif
# ifdef GL_UNIFORM
	BOOST_CHECK(x != ev.uniform);
# endif
# ifdef GL_UNIFORM_BLOCK
	BOOST_CHECK(x != ev.uniform_block);
# endif
# ifdef GL_VERTEX_SUBROUTINE
	BOOST_CHECK(x != ev.vertex_subroutine);
# endif
# ifdef GL_VERTEX_SUBROUTINE_UNIFORM
	BOOST_CHECK(x != ev.vertex_subroutine_uniform);
# endif
#endif

#ifdef GL_PROGRAM_INPUT
	x = ev.program_input;
	BOOST_CHECK(x == ev.program_input);
# ifdef GL_PROGRAM_OUTPUT
	BOOST_CHECK(x != ev.program_output);
# endif
# ifdef GL_SHADER_STORAGE_BLOCK
	BOOST_CHECK(x != ev.shader_storage_block);
# endif
# ifdef GL_TESS_CONTROL_SUBROUTINE
	BOOST_CHECK(x != ev.tess_control_subroutine);
# endif
# ifdef GL_TESS_CONTROL_SUBROUTINE_UNIFORM
	BOOST_CHECK(x != ev.tess_control_subroutine_uniform);
# endif
# ifdef GL_TESS_EVALUATION_SUBROUTINE
	BOOST_CHECK(x != ev.tess_evaluation_subroutine);
# endif
# ifdef GL_TESS_EVALUATION_SUBROUTINE_UNIFORM
	BOOST_CHECK(x != ev.tess_evaluation_subroutine_uniform);
# endif
# ifdef GL_TRANSFORM_FEEDEBACK_VARYING
	BOOST_CHECK(x != ev.transform_feedeback_varying);
# endif
# ifdef GL_UNIFORM
	BOOST_CHECK(x != ev.uniform);
# endif
# ifdef GL_UNIFORM_BLOCK
	BOOST_CHECK(x != ev.uniform_block);
# endif
# ifdef GL_VERTEX_SUBROUTINE
	BOOST_CHECK(x != ev.vertex_subroutine);
# endif
# ifdef GL_VERTEX_SUBROUTINE_UNIFORM
	BOOST_CHECK(x != ev.vertex_subroutine_uniform);
# endif
#endif

#ifdef GL_PROGRAM_OUTPUT
	x = ev.program_output;
	BOOST_CHECK(x == ev.program_output);
# ifdef GL_SHADER_STORAGE_BLOCK
	BOOST_CHECK(x != ev.shader_storage_block);
# endif
# ifdef GL_TESS_CONTROL_SUBROUTINE
	BOOST_CHECK(x != ev.tess_control_subroutine);
# endif
# ifdef GL_TESS_CONTROL_SUBROUTINE_UNIFORM
	BOOST_CHECK(x != ev.tess_control_subroutine_uniform);
# endif
# ifdef GL_TESS_EVALUATION_SUBROUTINE
	BOOST_CHECK(x != ev.tess_evaluation_subroutine);
# endif
# ifdef GL_TESS_EVALUATION_SUBROUTINE_UNIFORM
	BOOST_CHECK(x != ev.tess_evaluation_subroutine_uniform);
# endif
# ifdef GL_TRANSFORM_FEEDEBACK_VARYING
	BOOST_CHECK(x != ev.transform_feedeback_varying);
# endif
# ifdef GL_UNIFORM
	BOOST_CHECK(x != ev.uniform);
# endif
# ifdef GL_UNIFORM_BLOCK
	BOOST_CHECK(x != ev.uniform_block);
# endif
# ifdef GL_VERTEX_SUBROUTINE
	BOOST_CHECK(x != ev.vertex_subroutine);
# endif
# ifdef GL_VERTEX_SUBROUTINE_UNIFORM
	BOOST_CHECK(x != ev.vertex_subroutine_uniform);
# endif
#endif

#ifdef GL_SHADER_STORAGE_BLOCK
	x = ev.shader_storage_block;
	BOOST_CHECK(x == ev.shader_storage_block);
# ifdef GL_TESS_CONTROL_SUBROUTINE
	BOOST_CHECK(x != ev.tess_control_subroutine);
# endif
# ifdef GL_TESS_CONTROL_SUBROUTINE_UNIFORM
	BOOST_CHECK(x != ev.tess_control_subroutine_uniform);
# endif
# ifdef GL_TESS_EVALUATION_SUBROUTINE
	BOOST_CHECK(x != ev.tess_evaluation_subroutine);
# endif
# ifdef GL_TESS_EVALUATION_SUBROUTINE_UNIFORM
	BOOST_CHECK(x != ev.tess_evaluation_subroutine_uniform);
# endif
# ifdef GL_TRANSFORM_FEEDEBACK_VARYING
	BOOST_CHECK(x != ev.transform_feedeback_varying);
# endif
# ifdef GL_UNIFORM
	BOOST_CHECK(x != ev.uniform);
# endif
# ifdef GL_UNIFORM_BLOCK
	BOOST_CHECK(x != ev.uniform_block);
# endif
# ifdef GL_VERTEX_SUBROUTINE
	BOOST_CHECK(x != ev.vertex_subroutine);
# endif
# ifdef GL_VERTEX_SUBROUTINE_UNIFORM
	BOOST_CHECK(x != ev.vertex_subroutine_uniform);
# endif
#endif

#ifdef GL_TESS_CONTROL_SUBROUTINE
	x = ev.tess_control_subroutine;
	BOOST_CHECK(x == ev.tess_control_subroutine);
# ifdef GL_TESS_CONTROL_SUBROUTINE_UNIFORM
	BOOST_CHECK(x != ev.tess_control_subroutine_uniform);
# endif
# ifdef GL_TESS_EVALUATION_SUBROUTINE
	BOOST_CHECK(x != ev.tess_evaluation_subroutine);
# endif
# ifdef GL_TESS_EVALUATION_SUBROUTINE_UNIFORM
	BOOST_CHECK(x != ev.tess_evaluation_subroutine_uniform);
# endif
# ifdef GL_TRANSFORM_FEEDEBACK_VARYING
	BOOST_CHECK(x != ev.transform_feedeback_varying);
# endif
# ifdef GL_UNIFORM
	BOOST_CHECK(x != ev.uniform);
# endif
# ifdef GL_UNIFORM_BLOCK
	BOOST_CHECK(x != ev.uniform_block);
# endif
# ifdef GL_VERTEX_SUBROUTINE
	BOOST_CHECK(x != ev.vertex_subroutine);
# endif
# ifdef GL_VERTEX_SUBROUTINE_UNIFORM
	BOOST_CHECK(x != ev.vertex_subroutine_uniform);
# endif
#endif

#ifdef GL_TESS_CONTROL_SUBROUTINE_UNIFORM
	x = ev.tess_control_subroutine_uniform;
	BOOST_CHECK(x == ev.tess_control_subroutine_uniform);
# ifdef GL_TESS_EVALUATION_SUBROUTINE
	BOOST_CHECK(x != ev.tess_evaluation_subroutine);
# endif
# ifdef GL_TESS_EVALUATION_SUBROUTINE_UNIFORM
	BOOST_CHECK(x != ev.tess_evaluation_subroutine_uniform);
# endif
# ifdef GL_TRANSFORM_FEEDEBACK_VARYING
	BOOST_CHECK(x != ev.transform_feedeback_varying);
# endif
# ifdef GL_UNIFORM
	BOOST_CHECK(x != ev.uniform);
# endif
# ifdef GL_UNIFORM_BLOCK
	BOOST_CHECK(x != ev.uniform_block);
# endif
# ifdef GL_VERTEX_SUBROUTINE
	BOOST_CHECK(x != ev.vertex_subroutine);
# endif
# ifdef GL_VERTEX_SUBROUTINE_UNIFORM
	BOOST_CHECK(x != ev.vertex_subroutine_uniform);
# endif
#endif

#ifdef GL_TESS_EVALUATION_SUBROUTINE
	x = ev.tess_evaluation_subroutine;
	BOOST_CHECK(x == ev.tess_evaluation_subroutine);
# ifdef GL_TESS_EVALUATION_SUBROUTINE_UNIFORM
	BOOST_CHECK(x != ev.tess_evaluation_subroutine_uniform);
# endif
# ifdef GL_TRANSFORM_FEEDEBACK_VARYING
	BOOST_CHECK(x != ev.transform_feedeback_varying);
# endif
# ifdef GL_UNIFORM
	BOOST_CHECK(x != ev.uniform);
# endif
# ifdef GL_UNIFORM_BLOCK
	BOOST_CHECK(x != ev.uniform_block);
# endif
# ifdef GL_VERTEX_SUBROUTINE
	BOOST_CHECK(x != ev.vertex_subroutine);
# endif
# ifdef GL_VERTEX_SUBROUTINE_UNIFORM
	BOOST_CHECK(x != ev.vertex_subroutine_uniform);
# endif
#endif

#ifdef GL_TESS_EVALUATION_SUBROUTINE_UNIFORM
	x = ev.tess_evaluation_subroutine_uniform;
	BOOST_CHECK(x == ev.tess_evaluation_subroutine_uniform);
# ifdef GL_TRANSFORM_FEEDEBACK_VARYING
	BOOST_CHECK(x != ev.transform_feedeback_varying);
# endif
# ifdef GL_UNIFORM
	BOOST_CHECK(x != ev.uniform);
# endif
# ifdef GL_UNIFORM_BLOCK
	BOOST_CHECK(x != ev.uniform_block);
# endif
# ifdef GL_VERTEX_SUBROUTINE
	BOOST_CHECK(x != ev.vertex_subroutine);
# endif
# ifdef GL_VERTEX_SUBROUTINE_UNIFORM
	BOOST_CHECK(x != ev.vertex_subroutine_uniform);
# endif
#endif

#ifdef GL_TRANSFORM_FEEDEBACK_VARYING
	x = ev.transform_feedeback_varying;
	BOOST_CHECK(x == ev.transform_feedeback_varying);
# ifdef GL_UNIFORM
	BOOST_CHECK(x != ev.uniform);
# endif
# ifdef GL_UNIFORM_BLOCK
	BOOST_CHECK(x != ev.uniform_block);
# endif
# ifdef GL_VERTEX_SUBROUTINE
	BOOST_CHECK(x != ev.vertex_subroutine);
# endif
# ifdef GL_VERTEX_SUBROUTINE_UNIFORM
	BOOST_CHECK(x != ev.vertex_subroutine_uniform);
# endif
#endif

#ifdef GL_UNIFORM
	x = ev.uniform;
	BOOST_CHECK(x == ev.uniform);
# ifdef GL_UNIFORM_BLOCK
	BOOST_CHECK(x != ev.uniform_block);
# endif
# ifdef GL_VERTEX_SUBROUTINE
	BOOST_CHECK(x != ev.vertex_subroutine);
# endif
# ifdef GL_VERTEX_SUBROUTINE_UNIFORM
	BOOST_CHECK(x != ev.vertex_subroutine_uniform);
# endif
#endif

#ifdef GL_UNIFORM_BLOCK
	x = ev.uniform_block;
	BOOST_CHECK(x == ev.uniform_block);
# ifdef GL_VERTEX_SUBROUTINE
	BOOST_CHECK(x != ev.vertex_subroutine);
# endif
# ifdef GL_VERTEX_SUBROUTINE_UNIFORM
	BOOST_CHECK(x != ev.vertex_subroutine_uniform);
# endif
#endif

#ifdef GL_VERTEX_SUBROUTINE
	x = ev.vertex_subroutine;
	BOOST_CHECK(x == ev.vertex_subroutine);
# ifdef GL_VERTEX_SUBROUTINE_UNIFORM
	BOOST_CHECK(x != ev.vertex_subroutine_uniform);
# endif
#endif

#ifdef GL_VERTEX_SUBROUTINE_UNIFORM
	x = ev.vertex_subroutine_uniform;
	BOOST_CHECK(x == ev.vertex_subroutine_uniform);
#endif
}

BOOST_AUTO_TEST_CASE(enum_program_interface_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	program_interface x;
	(void)x;

#ifdef GL_ATOMIC_COUNTER_BUFFER
	x = ev.atomic_counter_buffer;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ATOMIC_COUNTER_BUFFER"
	) == 0);
#endif

#ifdef GL_BUFFER_VARIABLE
	x = ev.buffer_variable;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"BUFFER_VARIABLE"
	) == 0);
#endif

#ifdef GL_COMPUTE_SUBROUTINE
	x = ev.compute_subroutine;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"COMPUTE_SUBROUTINE"
	) == 0);
#endif

#ifdef GL_COMPUTE_SUBROUTINE_UNIFORM
	x = ev.compute_subroutine_uniform;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"COMPUTE_SUBROUTINE_UNIFORM"
	) == 0);
#endif

#ifdef GL_FRAGMENT_SUBROUTINE
	x = ev.fragment_subroutine;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"FRAGMENT_SUBROUTINE"
	) == 0);
#endif

#ifdef GL_FRAGMENT_SUBROUTINE_UNIFORM
	x = ev.fragment_subroutine_uniform;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"FRAGMENT_SUBROUTINE_UNIFORM"
	) == 0);
#endif

#ifdef GL_GEOMETRY_SUBROUTINE
	x = ev.geometry_subroutine;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"GEOMETRY_SUBROUTINE"
	) == 0);
#endif

#ifdef GL_GEOMETRY_SUBROUTINE_UNIFORM
	x = ev.geometry_subroutine_uniform;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"GEOMETRY_SUBROUTINE_UNIFORM"
	) == 0);
#endif

#ifdef GL_PROGRAM_INPUT
	x = ev.program_input;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PROGRAM_INPUT"
	) == 0);
#endif

#ifdef GL_PROGRAM_OUTPUT
	x = ev.program_output;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PROGRAM_OUTPUT"
	) == 0);
#endif

#ifdef GL_SHADER_STORAGE_BLOCK
	x = ev.shader_storage_block;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SHADER_STORAGE_BLOCK"
	) == 0);
#endif

#ifdef GL_TESS_CONTROL_SUBROUTINE
	x = ev.tess_control_subroutine;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TESS_CONTROL_SUBROUTINE"
	) == 0);
#endif

#ifdef GL_TESS_CONTROL_SUBROUTINE_UNIFORM
	x = ev.tess_control_subroutine_uniform;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TESS_CONTROL_SUBROUTINE_UNIFORM"
	) == 0);
#endif

#ifdef GL_TESS_EVALUATION_SUBROUTINE
	x = ev.tess_evaluation_subroutine;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TESS_EVALUATION_SUBROUTINE"
	) == 0);
#endif

#ifdef GL_TESS_EVALUATION_SUBROUTINE_UNIFORM
	x = ev.tess_evaluation_subroutine_uniform;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TESS_EVALUATION_SUBROUTINE_UNIFORM"
	) == 0);
#endif

#ifdef GL_TRANSFORM_FEEDEBACK_VARYING
	x = ev.transform_feedeback_varying;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TRANSFORM_FEEDEBACK_VARYING"
	) == 0);
#endif

#ifdef GL_UNIFORM
	x = ev.uniform;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"UNIFORM"
	) == 0);
#endif

#ifdef GL_UNIFORM_BLOCK
	x = ev.uniform_block;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"UNIFORM_BLOCK"
	) == 0);
#endif

#ifdef GL_VERTEX_SUBROUTINE
	x = ev.vertex_subroutine;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"VERTEX_SUBROUTINE"
	) == 0);
#endif

#ifdef GL_VERTEX_SUBROUTINE_UNIFORM
	x = ev.vertex_subroutine_uniform;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"VERTEX_SUBROUTINE_UNIFORM"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_program_interface_range)
{
	using namespace oglplus;
	auto count = enum_value_range<program_interface>().size();

#ifdef GL_ATOMIC_COUNTER_BUFFER
{
	--count;
	auto r = enum_value_range<program_interface>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		program_interface(GL_ATOMIC_COUNTER_BUFFER)
	) != r.end());
}
#endif

#ifdef GL_BUFFER_VARIABLE
{
	--count;
	auto r = enum_value_range<program_interface>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		program_interface(GL_BUFFER_VARIABLE)
	) != r.end());
}
#endif

#ifdef GL_COMPUTE_SUBROUTINE
{
	--count;
	auto r = enum_value_range<program_interface>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		program_interface(GL_COMPUTE_SUBROUTINE)
	) != r.end());
}
#endif

#ifdef GL_COMPUTE_SUBROUTINE_UNIFORM
{
	--count;
	auto r = enum_value_range<program_interface>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		program_interface(GL_COMPUTE_SUBROUTINE_UNIFORM)
	) != r.end());
}
#endif

#ifdef GL_FRAGMENT_SUBROUTINE
{
	--count;
	auto r = enum_value_range<program_interface>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		program_interface(GL_FRAGMENT_SUBROUTINE)
	) != r.end());
}
#endif

#ifdef GL_FRAGMENT_SUBROUTINE_UNIFORM
{
	--count;
	auto r = enum_value_range<program_interface>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		program_interface(GL_FRAGMENT_SUBROUTINE_UNIFORM)
	) != r.end());
}
#endif

#ifdef GL_GEOMETRY_SUBROUTINE
{
	--count;
	auto r = enum_value_range<program_interface>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		program_interface(GL_GEOMETRY_SUBROUTINE)
	) != r.end());
}
#endif

#ifdef GL_GEOMETRY_SUBROUTINE_UNIFORM
{
	--count;
	auto r = enum_value_range<program_interface>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		program_interface(GL_GEOMETRY_SUBROUTINE_UNIFORM)
	) != r.end());
}
#endif

#ifdef GL_PROGRAM_INPUT
{
	--count;
	auto r = enum_value_range<program_interface>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		program_interface(GL_PROGRAM_INPUT)
	) != r.end());
}
#endif

#ifdef GL_PROGRAM_OUTPUT
{
	--count;
	auto r = enum_value_range<program_interface>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		program_interface(GL_PROGRAM_OUTPUT)
	) != r.end());
}
#endif

#ifdef GL_SHADER_STORAGE_BLOCK
{
	--count;
	auto r = enum_value_range<program_interface>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		program_interface(GL_SHADER_STORAGE_BLOCK)
	) != r.end());
}
#endif

#ifdef GL_TESS_CONTROL_SUBROUTINE
{
	--count;
	auto r = enum_value_range<program_interface>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		program_interface(GL_TESS_CONTROL_SUBROUTINE)
	) != r.end());
}
#endif

#ifdef GL_TESS_CONTROL_SUBROUTINE_UNIFORM
{
	--count;
	auto r = enum_value_range<program_interface>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		program_interface(GL_TESS_CONTROL_SUBROUTINE_UNIFORM)
	) != r.end());
}
#endif

#ifdef GL_TESS_EVALUATION_SUBROUTINE
{
	--count;
	auto r = enum_value_range<program_interface>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		program_interface(GL_TESS_EVALUATION_SUBROUTINE)
	) != r.end());
}
#endif

#ifdef GL_TESS_EVALUATION_SUBROUTINE_UNIFORM
{
	--count;
	auto r = enum_value_range<program_interface>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		program_interface(GL_TESS_EVALUATION_SUBROUTINE_UNIFORM)
	) != r.end());
}
#endif

#ifdef GL_TRANSFORM_FEEDEBACK_VARYING
{
	--count;
	auto r = enum_value_range<program_interface>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		program_interface(GL_TRANSFORM_FEEDEBACK_VARYING)
	) != r.end());
}
#endif

#ifdef GL_UNIFORM
{
	--count;
	auto r = enum_value_range<program_interface>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		program_interface(GL_UNIFORM)
	) != r.end());
}
#endif

#ifdef GL_UNIFORM_BLOCK
{
	--count;
	auto r = enum_value_range<program_interface>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		program_interface(GL_UNIFORM_BLOCK)
	) != r.end());
}
#endif

#ifdef GL_VERTEX_SUBROUTINE
{
	--count;
	auto r = enum_value_range<program_interface>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		program_interface(GL_VERTEX_SUBROUTINE)
	) != r.end());
}
#endif

#ifdef GL_VERTEX_SUBROUTINE_UNIFORM
{
	--count;
	auto r = enum_value_range<program_interface>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		program_interface(GL_VERTEX_SUBROUTINE_UNIFORM)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_program_interface_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	program_interface x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_ATOMIC_COUNTER_BUFFER
	x = ev.atomic_counter_buffer;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.atomic_counter_buffer);
#endif

#ifdef GL_BUFFER_VARIABLE
	x = ev.buffer_variable;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.buffer_variable);
#endif

#ifdef GL_COMPUTE_SUBROUTINE
	x = ev.compute_subroutine;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.compute_subroutine);
#endif

#ifdef GL_COMPUTE_SUBROUTINE_UNIFORM
	x = ev.compute_subroutine_uniform;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.compute_subroutine_uniform);
#endif

#ifdef GL_FRAGMENT_SUBROUTINE
	x = ev.fragment_subroutine;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.fragment_subroutine);
#endif

#ifdef GL_FRAGMENT_SUBROUTINE_UNIFORM
	x = ev.fragment_subroutine_uniform;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.fragment_subroutine_uniform);
#endif

#ifdef GL_GEOMETRY_SUBROUTINE
	x = ev.geometry_subroutine;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.geometry_subroutine);
#endif

#ifdef GL_GEOMETRY_SUBROUTINE_UNIFORM
	x = ev.geometry_subroutine_uniform;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.geometry_subroutine_uniform);
#endif

#ifdef GL_PROGRAM_INPUT
	x = ev.program_input;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.program_input);
#endif

#ifdef GL_PROGRAM_OUTPUT
	x = ev.program_output;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.program_output);
#endif

#ifdef GL_SHADER_STORAGE_BLOCK
	x = ev.shader_storage_block;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.shader_storage_block);
#endif

#ifdef GL_TESS_CONTROL_SUBROUTINE
	x = ev.tess_control_subroutine;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.tess_control_subroutine);
#endif

#ifdef GL_TESS_CONTROL_SUBROUTINE_UNIFORM
	x = ev.tess_control_subroutine_uniform;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.tess_control_subroutine_uniform);
#endif

#ifdef GL_TESS_EVALUATION_SUBROUTINE
	x = ev.tess_evaluation_subroutine;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.tess_evaluation_subroutine);
#endif

#ifdef GL_TESS_EVALUATION_SUBROUTINE_UNIFORM
	x = ev.tess_evaluation_subroutine_uniform;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.tess_evaluation_subroutine_uniform);
#endif

#ifdef GL_TRANSFORM_FEEDEBACK_VARYING
	x = ev.transform_feedeback_varying;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.transform_feedeback_varying);
#endif

#ifdef GL_UNIFORM
	x = ev.uniform;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.uniform);
#endif

#ifdef GL_UNIFORM_BLOCK
	x = ev.uniform_block;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.uniform_block);
#endif

#ifdef GL_VERTEX_SUBROUTINE
	x = ev.vertex_subroutine;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.vertex_subroutine);
#endif

#ifdef GL_VERTEX_SUBROUTINE_UNIFORM
	x = ev.vertex_subroutine_uniform;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.vertex_subroutine_uniform);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
