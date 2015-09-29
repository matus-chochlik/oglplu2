//  File test/oglplus/enums/query_target.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_query_target

#include <boost/test/unit_test.hpp>
#include "common.hpp"

BOOST_AUTO_TEST_SUITE(enum_query_target)

BOOST_AUTO_TEST_CASE(enum_query_target_values)
{
	using namespace oglplus;
	enum_values ev;
	query_target x;

#ifdef GL_ANY_SAMPLES_PASSED
	x = ev.any_samples_passed;
	BOOST_CHECK(x == ev.any_samples_passed);
# ifdef GL_CLIPPING_INPUT_PRIMITIVES_ARB
	BOOST_CHECK(x != ev.clipping_input_primitives);
# endif
# ifdef GL_CLIPPING_OUTPUT_PRIMITIVES_ARB
	BOOST_CHECK(x != ev.clipping_output_primitives);
# endif
# ifdef GL_COMPUTE_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.compute_shader_invocations);
# endif
# ifdef GL_FRAGMENT_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.fragment_shader_invocations);
# endif
# ifdef GL_GEOMETRY_SHADER_INVOCATIONS
	BOOST_CHECK(x != ev.geometry_shader_invocations);
# endif
# ifdef GL_GEOMETRY_SHADER_PRIMITIVES_EMITTED_ARB
	BOOST_CHECK(x != ev.geometry_shader_primitives_emitted);
# endif
# ifdef GL_PRIMITIVES_GENERATED
	BOOST_CHECK(x != ev.primitives_generated);
# endif
# ifdef GL_PRIMITIVES_SUBMITTED_ARB
	BOOST_CHECK(x != ev.primitives_submitted);
# endif
# ifdef GL_SAMPLES_PASSED
	BOOST_CHECK(x != ev.samples_passed);
# endif
# ifdef GL_TESS_CONTROL_SHADER_PATCHES_ARB
	BOOST_CHECK(x != ev.tess_control_shader_patches);
# endif
# ifdef GL_TESS_EVALUATION_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.tess_evaluation_shader_invocations);
# endif
# ifdef GL_TIME_ELAPSED
	BOOST_CHECK(x != ev.time_elapsed);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_OVERFLOW_ARB
	BOOST_CHECK(x != ev.transform_feedback_overflow);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN
	BOOST_CHECK(x != ev.transform_feedback_primitives_written);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_STREAM_OVERFLOW_ARB
	BOOST_CHECK(x != ev.transform_feedback_stream_overflow);
# endif
# ifdef GL_VERTEX_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.vertex_shader_invocations);
# endif
# ifdef GL_VERTICES_SUBMITTED_ARB
	BOOST_CHECK(x != ev.vertices_submitted);
# endif
#endif

#ifdef GL_CLIPPING_INPUT_PRIMITIVES_ARB
	x = ev.clipping_input_primitives;
# ifdef GL_ANY_SAMPLES_PASSED
	BOOST_CHECK(x != ev.any_samples_passed);
# endif
	BOOST_CHECK(x == ev.clipping_input_primitives);
# ifdef GL_CLIPPING_OUTPUT_PRIMITIVES_ARB
	BOOST_CHECK(x != ev.clipping_output_primitives);
# endif
# ifdef GL_COMPUTE_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.compute_shader_invocations);
# endif
# ifdef GL_FRAGMENT_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.fragment_shader_invocations);
# endif
# ifdef GL_GEOMETRY_SHADER_INVOCATIONS
	BOOST_CHECK(x != ev.geometry_shader_invocations);
# endif
# ifdef GL_GEOMETRY_SHADER_PRIMITIVES_EMITTED_ARB
	BOOST_CHECK(x != ev.geometry_shader_primitives_emitted);
# endif
# ifdef GL_PRIMITIVES_GENERATED
	BOOST_CHECK(x != ev.primitives_generated);
# endif
# ifdef GL_PRIMITIVES_SUBMITTED_ARB
	BOOST_CHECK(x != ev.primitives_submitted);
# endif
# ifdef GL_SAMPLES_PASSED
	BOOST_CHECK(x != ev.samples_passed);
# endif
# ifdef GL_TESS_CONTROL_SHADER_PATCHES_ARB
	BOOST_CHECK(x != ev.tess_control_shader_patches);
# endif
# ifdef GL_TESS_EVALUATION_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.tess_evaluation_shader_invocations);
# endif
# ifdef GL_TIME_ELAPSED
	BOOST_CHECK(x != ev.time_elapsed);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_OVERFLOW_ARB
	BOOST_CHECK(x != ev.transform_feedback_overflow);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN
	BOOST_CHECK(x != ev.transform_feedback_primitives_written);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_STREAM_OVERFLOW_ARB
	BOOST_CHECK(x != ev.transform_feedback_stream_overflow);
# endif
# ifdef GL_VERTEX_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.vertex_shader_invocations);
# endif
# ifdef GL_VERTICES_SUBMITTED_ARB
	BOOST_CHECK(x != ev.vertices_submitted);
# endif
#endif

#ifdef GL_CLIPPING_OUTPUT_PRIMITIVES_ARB
	x = ev.clipping_output_primitives;
# ifdef GL_ANY_SAMPLES_PASSED
	BOOST_CHECK(x != ev.any_samples_passed);
# endif
# ifdef GL_CLIPPING_INPUT_PRIMITIVES_ARB
	BOOST_CHECK(x != ev.clipping_input_primitives);
# endif
	BOOST_CHECK(x == ev.clipping_output_primitives);
# ifdef GL_COMPUTE_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.compute_shader_invocations);
# endif
# ifdef GL_FRAGMENT_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.fragment_shader_invocations);
# endif
# ifdef GL_GEOMETRY_SHADER_INVOCATIONS
	BOOST_CHECK(x != ev.geometry_shader_invocations);
# endif
# ifdef GL_GEOMETRY_SHADER_PRIMITIVES_EMITTED_ARB
	BOOST_CHECK(x != ev.geometry_shader_primitives_emitted);
# endif
# ifdef GL_PRIMITIVES_GENERATED
	BOOST_CHECK(x != ev.primitives_generated);
# endif
# ifdef GL_PRIMITIVES_SUBMITTED_ARB
	BOOST_CHECK(x != ev.primitives_submitted);
# endif
# ifdef GL_SAMPLES_PASSED
	BOOST_CHECK(x != ev.samples_passed);
# endif
# ifdef GL_TESS_CONTROL_SHADER_PATCHES_ARB
	BOOST_CHECK(x != ev.tess_control_shader_patches);
# endif
# ifdef GL_TESS_EVALUATION_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.tess_evaluation_shader_invocations);
# endif
# ifdef GL_TIME_ELAPSED
	BOOST_CHECK(x != ev.time_elapsed);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_OVERFLOW_ARB
	BOOST_CHECK(x != ev.transform_feedback_overflow);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN
	BOOST_CHECK(x != ev.transform_feedback_primitives_written);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_STREAM_OVERFLOW_ARB
	BOOST_CHECK(x != ev.transform_feedback_stream_overflow);
# endif
# ifdef GL_VERTEX_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.vertex_shader_invocations);
# endif
# ifdef GL_VERTICES_SUBMITTED_ARB
	BOOST_CHECK(x != ev.vertices_submitted);
# endif
#endif

#ifdef GL_COMPUTE_SHADER_INVOCATIONS_ARB
	x = ev.compute_shader_invocations;
# ifdef GL_ANY_SAMPLES_PASSED
	BOOST_CHECK(x != ev.any_samples_passed);
# endif
# ifdef GL_CLIPPING_INPUT_PRIMITIVES_ARB
	BOOST_CHECK(x != ev.clipping_input_primitives);
# endif
# ifdef GL_CLIPPING_OUTPUT_PRIMITIVES_ARB
	BOOST_CHECK(x != ev.clipping_output_primitives);
# endif
	BOOST_CHECK(x == ev.compute_shader_invocations);
# ifdef GL_FRAGMENT_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.fragment_shader_invocations);
# endif
# ifdef GL_GEOMETRY_SHADER_INVOCATIONS
	BOOST_CHECK(x != ev.geometry_shader_invocations);
# endif
# ifdef GL_GEOMETRY_SHADER_PRIMITIVES_EMITTED_ARB
	BOOST_CHECK(x != ev.geometry_shader_primitives_emitted);
# endif
# ifdef GL_PRIMITIVES_GENERATED
	BOOST_CHECK(x != ev.primitives_generated);
# endif
# ifdef GL_PRIMITIVES_SUBMITTED_ARB
	BOOST_CHECK(x != ev.primitives_submitted);
# endif
# ifdef GL_SAMPLES_PASSED
	BOOST_CHECK(x != ev.samples_passed);
# endif
# ifdef GL_TESS_CONTROL_SHADER_PATCHES_ARB
	BOOST_CHECK(x != ev.tess_control_shader_patches);
# endif
# ifdef GL_TESS_EVALUATION_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.tess_evaluation_shader_invocations);
# endif
# ifdef GL_TIME_ELAPSED
	BOOST_CHECK(x != ev.time_elapsed);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_OVERFLOW_ARB
	BOOST_CHECK(x != ev.transform_feedback_overflow);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN
	BOOST_CHECK(x != ev.transform_feedback_primitives_written);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_STREAM_OVERFLOW_ARB
	BOOST_CHECK(x != ev.transform_feedback_stream_overflow);
# endif
# ifdef GL_VERTEX_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.vertex_shader_invocations);
# endif
# ifdef GL_VERTICES_SUBMITTED_ARB
	BOOST_CHECK(x != ev.vertices_submitted);
# endif
#endif

#ifdef GL_FRAGMENT_SHADER_INVOCATIONS_ARB
	x = ev.fragment_shader_invocations;
# ifdef GL_ANY_SAMPLES_PASSED
	BOOST_CHECK(x != ev.any_samples_passed);
# endif
# ifdef GL_CLIPPING_INPUT_PRIMITIVES_ARB
	BOOST_CHECK(x != ev.clipping_input_primitives);
# endif
# ifdef GL_CLIPPING_OUTPUT_PRIMITIVES_ARB
	BOOST_CHECK(x != ev.clipping_output_primitives);
# endif
# ifdef GL_COMPUTE_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.compute_shader_invocations);
# endif
	BOOST_CHECK(x == ev.fragment_shader_invocations);
# ifdef GL_GEOMETRY_SHADER_INVOCATIONS
	BOOST_CHECK(x != ev.geometry_shader_invocations);
# endif
# ifdef GL_GEOMETRY_SHADER_PRIMITIVES_EMITTED_ARB
	BOOST_CHECK(x != ev.geometry_shader_primitives_emitted);
# endif
# ifdef GL_PRIMITIVES_GENERATED
	BOOST_CHECK(x != ev.primitives_generated);
# endif
# ifdef GL_PRIMITIVES_SUBMITTED_ARB
	BOOST_CHECK(x != ev.primitives_submitted);
# endif
# ifdef GL_SAMPLES_PASSED
	BOOST_CHECK(x != ev.samples_passed);
# endif
# ifdef GL_TESS_CONTROL_SHADER_PATCHES_ARB
	BOOST_CHECK(x != ev.tess_control_shader_patches);
# endif
# ifdef GL_TESS_EVALUATION_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.tess_evaluation_shader_invocations);
# endif
# ifdef GL_TIME_ELAPSED
	BOOST_CHECK(x != ev.time_elapsed);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_OVERFLOW_ARB
	BOOST_CHECK(x != ev.transform_feedback_overflow);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN
	BOOST_CHECK(x != ev.transform_feedback_primitives_written);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_STREAM_OVERFLOW_ARB
	BOOST_CHECK(x != ev.transform_feedback_stream_overflow);
# endif
# ifdef GL_VERTEX_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.vertex_shader_invocations);
# endif
# ifdef GL_VERTICES_SUBMITTED_ARB
	BOOST_CHECK(x != ev.vertices_submitted);
# endif
#endif

#ifdef GL_GEOMETRY_SHADER_INVOCATIONS
	x = ev.geometry_shader_invocations;
# ifdef GL_ANY_SAMPLES_PASSED
	BOOST_CHECK(x != ev.any_samples_passed);
# endif
# ifdef GL_CLIPPING_INPUT_PRIMITIVES_ARB
	BOOST_CHECK(x != ev.clipping_input_primitives);
# endif
# ifdef GL_CLIPPING_OUTPUT_PRIMITIVES_ARB
	BOOST_CHECK(x != ev.clipping_output_primitives);
# endif
# ifdef GL_COMPUTE_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.compute_shader_invocations);
# endif
# ifdef GL_FRAGMENT_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.fragment_shader_invocations);
# endif
	BOOST_CHECK(x == ev.geometry_shader_invocations);
# ifdef GL_GEOMETRY_SHADER_PRIMITIVES_EMITTED_ARB
	BOOST_CHECK(x != ev.geometry_shader_primitives_emitted);
# endif
# ifdef GL_PRIMITIVES_GENERATED
	BOOST_CHECK(x != ev.primitives_generated);
# endif
# ifdef GL_PRIMITIVES_SUBMITTED_ARB
	BOOST_CHECK(x != ev.primitives_submitted);
# endif
# ifdef GL_SAMPLES_PASSED
	BOOST_CHECK(x != ev.samples_passed);
# endif
# ifdef GL_TESS_CONTROL_SHADER_PATCHES_ARB
	BOOST_CHECK(x != ev.tess_control_shader_patches);
# endif
# ifdef GL_TESS_EVALUATION_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.tess_evaluation_shader_invocations);
# endif
# ifdef GL_TIME_ELAPSED
	BOOST_CHECK(x != ev.time_elapsed);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_OVERFLOW_ARB
	BOOST_CHECK(x != ev.transform_feedback_overflow);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN
	BOOST_CHECK(x != ev.transform_feedback_primitives_written);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_STREAM_OVERFLOW_ARB
	BOOST_CHECK(x != ev.transform_feedback_stream_overflow);
# endif
# ifdef GL_VERTEX_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.vertex_shader_invocations);
# endif
# ifdef GL_VERTICES_SUBMITTED_ARB
	BOOST_CHECK(x != ev.vertices_submitted);
# endif
#endif

#ifdef GL_GEOMETRY_SHADER_PRIMITIVES_EMITTED_ARB
	x = ev.geometry_shader_primitives_emitted;
# ifdef GL_ANY_SAMPLES_PASSED
	BOOST_CHECK(x != ev.any_samples_passed);
# endif
# ifdef GL_CLIPPING_INPUT_PRIMITIVES_ARB
	BOOST_CHECK(x != ev.clipping_input_primitives);
# endif
# ifdef GL_CLIPPING_OUTPUT_PRIMITIVES_ARB
	BOOST_CHECK(x != ev.clipping_output_primitives);
# endif
# ifdef GL_COMPUTE_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.compute_shader_invocations);
# endif
# ifdef GL_FRAGMENT_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.fragment_shader_invocations);
# endif
# ifdef GL_GEOMETRY_SHADER_INVOCATIONS
	BOOST_CHECK(x != ev.geometry_shader_invocations);
# endif
	BOOST_CHECK(x == ev.geometry_shader_primitives_emitted);
# ifdef GL_PRIMITIVES_GENERATED
	BOOST_CHECK(x != ev.primitives_generated);
# endif
# ifdef GL_PRIMITIVES_SUBMITTED_ARB
	BOOST_CHECK(x != ev.primitives_submitted);
# endif
# ifdef GL_SAMPLES_PASSED
	BOOST_CHECK(x != ev.samples_passed);
# endif
# ifdef GL_TESS_CONTROL_SHADER_PATCHES_ARB
	BOOST_CHECK(x != ev.tess_control_shader_patches);
# endif
# ifdef GL_TESS_EVALUATION_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.tess_evaluation_shader_invocations);
# endif
# ifdef GL_TIME_ELAPSED
	BOOST_CHECK(x != ev.time_elapsed);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_OVERFLOW_ARB
	BOOST_CHECK(x != ev.transform_feedback_overflow);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN
	BOOST_CHECK(x != ev.transform_feedback_primitives_written);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_STREAM_OVERFLOW_ARB
	BOOST_CHECK(x != ev.transform_feedback_stream_overflow);
# endif
# ifdef GL_VERTEX_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.vertex_shader_invocations);
# endif
# ifdef GL_VERTICES_SUBMITTED_ARB
	BOOST_CHECK(x != ev.vertices_submitted);
# endif
#endif

#ifdef GL_PRIMITIVES_GENERATED
	x = ev.primitives_generated;
# ifdef GL_ANY_SAMPLES_PASSED
	BOOST_CHECK(x != ev.any_samples_passed);
# endif
# ifdef GL_CLIPPING_INPUT_PRIMITIVES_ARB
	BOOST_CHECK(x != ev.clipping_input_primitives);
# endif
# ifdef GL_CLIPPING_OUTPUT_PRIMITIVES_ARB
	BOOST_CHECK(x != ev.clipping_output_primitives);
# endif
# ifdef GL_COMPUTE_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.compute_shader_invocations);
# endif
# ifdef GL_FRAGMENT_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.fragment_shader_invocations);
# endif
# ifdef GL_GEOMETRY_SHADER_INVOCATIONS
	BOOST_CHECK(x != ev.geometry_shader_invocations);
# endif
# ifdef GL_GEOMETRY_SHADER_PRIMITIVES_EMITTED_ARB
	BOOST_CHECK(x != ev.geometry_shader_primitives_emitted);
# endif
	BOOST_CHECK(x == ev.primitives_generated);
# ifdef GL_PRIMITIVES_SUBMITTED_ARB
	BOOST_CHECK(x != ev.primitives_submitted);
# endif
# ifdef GL_SAMPLES_PASSED
	BOOST_CHECK(x != ev.samples_passed);
# endif
# ifdef GL_TESS_CONTROL_SHADER_PATCHES_ARB
	BOOST_CHECK(x != ev.tess_control_shader_patches);
# endif
# ifdef GL_TESS_EVALUATION_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.tess_evaluation_shader_invocations);
# endif
# ifdef GL_TIME_ELAPSED
	BOOST_CHECK(x != ev.time_elapsed);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_OVERFLOW_ARB
	BOOST_CHECK(x != ev.transform_feedback_overflow);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN
	BOOST_CHECK(x != ev.transform_feedback_primitives_written);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_STREAM_OVERFLOW_ARB
	BOOST_CHECK(x != ev.transform_feedback_stream_overflow);
# endif
# ifdef GL_VERTEX_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.vertex_shader_invocations);
# endif
# ifdef GL_VERTICES_SUBMITTED_ARB
	BOOST_CHECK(x != ev.vertices_submitted);
# endif
#endif

#ifdef GL_PRIMITIVES_SUBMITTED_ARB
	x = ev.primitives_submitted;
# ifdef GL_ANY_SAMPLES_PASSED
	BOOST_CHECK(x != ev.any_samples_passed);
# endif
# ifdef GL_CLIPPING_INPUT_PRIMITIVES_ARB
	BOOST_CHECK(x != ev.clipping_input_primitives);
# endif
# ifdef GL_CLIPPING_OUTPUT_PRIMITIVES_ARB
	BOOST_CHECK(x != ev.clipping_output_primitives);
# endif
# ifdef GL_COMPUTE_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.compute_shader_invocations);
# endif
# ifdef GL_FRAGMENT_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.fragment_shader_invocations);
# endif
# ifdef GL_GEOMETRY_SHADER_INVOCATIONS
	BOOST_CHECK(x != ev.geometry_shader_invocations);
# endif
# ifdef GL_GEOMETRY_SHADER_PRIMITIVES_EMITTED_ARB
	BOOST_CHECK(x != ev.geometry_shader_primitives_emitted);
# endif
# ifdef GL_PRIMITIVES_GENERATED
	BOOST_CHECK(x != ev.primitives_generated);
# endif
	BOOST_CHECK(x == ev.primitives_submitted);
# ifdef GL_SAMPLES_PASSED
	BOOST_CHECK(x != ev.samples_passed);
# endif
# ifdef GL_TESS_CONTROL_SHADER_PATCHES_ARB
	BOOST_CHECK(x != ev.tess_control_shader_patches);
# endif
# ifdef GL_TESS_EVALUATION_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.tess_evaluation_shader_invocations);
# endif
# ifdef GL_TIME_ELAPSED
	BOOST_CHECK(x != ev.time_elapsed);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_OVERFLOW_ARB
	BOOST_CHECK(x != ev.transform_feedback_overflow);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN
	BOOST_CHECK(x != ev.transform_feedback_primitives_written);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_STREAM_OVERFLOW_ARB
	BOOST_CHECK(x != ev.transform_feedback_stream_overflow);
# endif
# ifdef GL_VERTEX_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.vertex_shader_invocations);
# endif
# ifdef GL_VERTICES_SUBMITTED_ARB
	BOOST_CHECK(x != ev.vertices_submitted);
# endif
#endif

#ifdef GL_SAMPLES_PASSED
	x = ev.samples_passed;
# ifdef GL_ANY_SAMPLES_PASSED
	BOOST_CHECK(x != ev.any_samples_passed);
# endif
# ifdef GL_CLIPPING_INPUT_PRIMITIVES_ARB
	BOOST_CHECK(x != ev.clipping_input_primitives);
# endif
# ifdef GL_CLIPPING_OUTPUT_PRIMITIVES_ARB
	BOOST_CHECK(x != ev.clipping_output_primitives);
# endif
# ifdef GL_COMPUTE_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.compute_shader_invocations);
# endif
# ifdef GL_FRAGMENT_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.fragment_shader_invocations);
# endif
# ifdef GL_GEOMETRY_SHADER_INVOCATIONS
	BOOST_CHECK(x != ev.geometry_shader_invocations);
# endif
# ifdef GL_GEOMETRY_SHADER_PRIMITIVES_EMITTED_ARB
	BOOST_CHECK(x != ev.geometry_shader_primitives_emitted);
# endif
# ifdef GL_PRIMITIVES_GENERATED
	BOOST_CHECK(x != ev.primitives_generated);
# endif
# ifdef GL_PRIMITIVES_SUBMITTED_ARB
	BOOST_CHECK(x != ev.primitives_submitted);
# endif
	BOOST_CHECK(x == ev.samples_passed);
# ifdef GL_TESS_CONTROL_SHADER_PATCHES_ARB
	BOOST_CHECK(x != ev.tess_control_shader_patches);
# endif
# ifdef GL_TESS_EVALUATION_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.tess_evaluation_shader_invocations);
# endif
# ifdef GL_TIME_ELAPSED
	BOOST_CHECK(x != ev.time_elapsed);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_OVERFLOW_ARB
	BOOST_CHECK(x != ev.transform_feedback_overflow);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN
	BOOST_CHECK(x != ev.transform_feedback_primitives_written);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_STREAM_OVERFLOW_ARB
	BOOST_CHECK(x != ev.transform_feedback_stream_overflow);
# endif
# ifdef GL_VERTEX_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.vertex_shader_invocations);
# endif
# ifdef GL_VERTICES_SUBMITTED_ARB
	BOOST_CHECK(x != ev.vertices_submitted);
# endif
#endif

#ifdef GL_TESS_CONTROL_SHADER_PATCHES_ARB
	x = ev.tess_control_shader_patches;
# ifdef GL_ANY_SAMPLES_PASSED
	BOOST_CHECK(x != ev.any_samples_passed);
# endif
# ifdef GL_CLIPPING_INPUT_PRIMITIVES_ARB
	BOOST_CHECK(x != ev.clipping_input_primitives);
# endif
# ifdef GL_CLIPPING_OUTPUT_PRIMITIVES_ARB
	BOOST_CHECK(x != ev.clipping_output_primitives);
# endif
# ifdef GL_COMPUTE_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.compute_shader_invocations);
# endif
# ifdef GL_FRAGMENT_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.fragment_shader_invocations);
# endif
# ifdef GL_GEOMETRY_SHADER_INVOCATIONS
	BOOST_CHECK(x != ev.geometry_shader_invocations);
# endif
# ifdef GL_GEOMETRY_SHADER_PRIMITIVES_EMITTED_ARB
	BOOST_CHECK(x != ev.geometry_shader_primitives_emitted);
# endif
# ifdef GL_PRIMITIVES_GENERATED
	BOOST_CHECK(x != ev.primitives_generated);
# endif
# ifdef GL_PRIMITIVES_SUBMITTED_ARB
	BOOST_CHECK(x != ev.primitives_submitted);
# endif
# ifdef GL_SAMPLES_PASSED
	BOOST_CHECK(x != ev.samples_passed);
# endif
	BOOST_CHECK(x == ev.tess_control_shader_patches);
# ifdef GL_TESS_EVALUATION_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.tess_evaluation_shader_invocations);
# endif
# ifdef GL_TIME_ELAPSED
	BOOST_CHECK(x != ev.time_elapsed);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_OVERFLOW_ARB
	BOOST_CHECK(x != ev.transform_feedback_overflow);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN
	BOOST_CHECK(x != ev.transform_feedback_primitives_written);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_STREAM_OVERFLOW_ARB
	BOOST_CHECK(x != ev.transform_feedback_stream_overflow);
# endif
# ifdef GL_VERTEX_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.vertex_shader_invocations);
# endif
# ifdef GL_VERTICES_SUBMITTED_ARB
	BOOST_CHECK(x != ev.vertices_submitted);
# endif
#endif

#ifdef GL_TESS_EVALUATION_SHADER_INVOCATIONS_ARB
	x = ev.tess_evaluation_shader_invocations;
# ifdef GL_ANY_SAMPLES_PASSED
	BOOST_CHECK(x != ev.any_samples_passed);
# endif
# ifdef GL_CLIPPING_INPUT_PRIMITIVES_ARB
	BOOST_CHECK(x != ev.clipping_input_primitives);
# endif
# ifdef GL_CLIPPING_OUTPUT_PRIMITIVES_ARB
	BOOST_CHECK(x != ev.clipping_output_primitives);
# endif
# ifdef GL_COMPUTE_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.compute_shader_invocations);
# endif
# ifdef GL_FRAGMENT_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.fragment_shader_invocations);
# endif
# ifdef GL_GEOMETRY_SHADER_INVOCATIONS
	BOOST_CHECK(x != ev.geometry_shader_invocations);
# endif
# ifdef GL_GEOMETRY_SHADER_PRIMITIVES_EMITTED_ARB
	BOOST_CHECK(x != ev.geometry_shader_primitives_emitted);
# endif
# ifdef GL_PRIMITIVES_GENERATED
	BOOST_CHECK(x != ev.primitives_generated);
# endif
# ifdef GL_PRIMITIVES_SUBMITTED_ARB
	BOOST_CHECK(x != ev.primitives_submitted);
# endif
# ifdef GL_SAMPLES_PASSED
	BOOST_CHECK(x != ev.samples_passed);
# endif
# ifdef GL_TESS_CONTROL_SHADER_PATCHES_ARB
	BOOST_CHECK(x != ev.tess_control_shader_patches);
# endif
	BOOST_CHECK(x == ev.tess_evaluation_shader_invocations);
# ifdef GL_TIME_ELAPSED
	BOOST_CHECK(x != ev.time_elapsed);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_OVERFLOW_ARB
	BOOST_CHECK(x != ev.transform_feedback_overflow);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN
	BOOST_CHECK(x != ev.transform_feedback_primitives_written);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_STREAM_OVERFLOW_ARB
	BOOST_CHECK(x != ev.transform_feedback_stream_overflow);
# endif
# ifdef GL_VERTEX_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.vertex_shader_invocations);
# endif
# ifdef GL_VERTICES_SUBMITTED_ARB
	BOOST_CHECK(x != ev.vertices_submitted);
# endif
#endif

#ifdef GL_TIME_ELAPSED
	x = ev.time_elapsed;
# ifdef GL_ANY_SAMPLES_PASSED
	BOOST_CHECK(x != ev.any_samples_passed);
# endif
# ifdef GL_CLIPPING_INPUT_PRIMITIVES_ARB
	BOOST_CHECK(x != ev.clipping_input_primitives);
# endif
# ifdef GL_CLIPPING_OUTPUT_PRIMITIVES_ARB
	BOOST_CHECK(x != ev.clipping_output_primitives);
# endif
# ifdef GL_COMPUTE_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.compute_shader_invocations);
# endif
# ifdef GL_FRAGMENT_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.fragment_shader_invocations);
# endif
# ifdef GL_GEOMETRY_SHADER_INVOCATIONS
	BOOST_CHECK(x != ev.geometry_shader_invocations);
# endif
# ifdef GL_GEOMETRY_SHADER_PRIMITIVES_EMITTED_ARB
	BOOST_CHECK(x != ev.geometry_shader_primitives_emitted);
# endif
# ifdef GL_PRIMITIVES_GENERATED
	BOOST_CHECK(x != ev.primitives_generated);
# endif
# ifdef GL_PRIMITIVES_SUBMITTED_ARB
	BOOST_CHECK(x != ev.primitives_submitted);
# endif
# ifdef GL_SAMPLES_PASSED
	BOOST_CHECK(x != ev.samples_passed);
# endif
# ifdef GL_TESS_CONTROL_SHADER_PATCHES_ARB
	BOOST_CHECK(x != ev.tess_control_shader_patches);
# endif
# ifdef GL_TESS_EVALUATION_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.tess_evaluation_shader_invocations);
# endif
	BOOST_CHECK(x == ev.time_elapsed);
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_OVERFLOW_ARB
	BOOST_CHECK(x != ev.transform_feedback_overflow);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN
	BOOST_CHECK(x != ev.transform_feedback_primitives_written);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_STREAM_OVERFLOW_ARB
	BOOST_CHECK(x != ev.transform_feedback_stream_overflow);
# endif
# ifdef GL_VERTEX_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.vertex_shader_invocations);
# endif
# ifdef GL_VERTICES_SUBMITTED_ARB
	BOOST_CHECK(x != ev.vertices_submitted);
# endif
#endif

#ifdef GL_TIMESTAMP
	x = ev.timestamp;
# ifdef GL_ANY_SAMPLES_PASSED
	BOOST_CHECK(x != ev.any_samples_passed);
# endif
# ifdef GL_CLIPPING_INPUT_PRIMITIVES_ARB
	BOOST_CHECK(x != ev.clipping_input_primitives);
# endif
# ifdef GL_CLIPPING_OUTPUT_PRIMITIVES_ARB
	BOOST_CHECK(x != ev.clipping_output_primitives);
# endif
# ifdef GL_COMPUTE_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.compute_shader_invocations);
# endif
# ifdef GL_FRAGMENT_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.fragment_shader_invocations);
# endif
# ifdef GL_GEOMETRY_SHADER_INVOCATIONS
	BOOST_CHECK(x != ev.geometry_shader_invocations);
# endif
# ifdef GL_GEOMETRY_SHADER_PRIMITIVES_EMITTED_ARB
	BOOST_CHECK(x != ev.geometry_shader_primitives_emitted);
# endif
# ifdef GL_PRIMITIVES_GENERATED
	BOOST_CHECK(x != ev.primitives_generated);
# endif
# ifdef GL_PRIMITIVES_SUBMITTED_ARB
	BOOST_CHECK(x != ev.primitives_submitted);
# endif
# ifdef GL_SAMPLES_PASSED
	BOOST_CHECK(x != ev.samples_passed);
# endif
# ifdef GL_TESS_CONTROL_SHADER_PATCHES_ARB
	BOOST_CHECK(x != ev.tess_control_shader_patches);
# endif
# ifdef GL_TESS_EVALUATION_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.tess_evaluation_shader_invocations);
# endif
# ifdef GL_TIME_ELAPSED
	BOOST_CHECK(x != ev.time_elapsed);
# endif
	BOOST_CHECK(x == ev.timestamp);
# ifdef GL_TRANSFORM_FEEDBACK_OVERFLOW_ARB
	BOOST_CHECK(x != ev.transform_feedback_overflow);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN
	BOOST_CHECK(x != ev.transform_feedback_primitives_written);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_STREAM_OVERFLOW_ARB
	BOOST_CHECK(x != ev.transform_feedback_stream_overflow);
# endif
# ifdef GL_VERTEX_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.vertex_shader_invocations);
# endif
# ifdef GL_VERTICES_SUBMITTED_ARB
	BOOST_CHECK(x != ev.vertices_submitted);
# endif
#endif

#ifdef GL_TRANSFORM_FEEDBACK_OVERFLOW_ARB
	x = ev.transform_feedback_overflow;
# ifdef GL_ANY_SAMPLES_PASSED
	BOOST_CHECK(x != ev.any_samples_passed);
# endif
# ifdef GL_CLIPPING_INPUT_PRIMITIVES_ARB
	BOOST_CHECK(x != ev.clipping_input_primitives);
# endif
# ifdef GL_CLIPPING_OUTPUT_PRIMITIVES_ARB
	BOOST_CHECK(x != ev.clipping_output_primitives);
# endif
# ifdef GL_COMPUTE_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.compute_shader_invocations);
# endif
# ifdef GL_FRAGMENT_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.fragment_shader_invocations);
# endif
# ifdef GL_GEOMETRY_SHADER_INVOCATIONS
	BOOST_CHECK(x != ev.geometry_shader_invocations);
# endif
# ifdef GL_GEOMETRY_SHADER_PRIMITIVES_EMITTED_ARB
	BOOST_CHECK(x != ev.geometry_shader_primitives_emitted);
# endif
# ifdef GL_PRIMITIVES_GENERATED
	BOOST_CHECK(x != ev.primitives_generated);
# endif
# ifdef GL_PRIMITIVES_SUBMITTED_ARB
	BOOST_CHECK(x != ev.primitives_submitted);
# endif
# ifdef GL_SAMPLES_PASSED
	BOOST_CHECK(x != ev.samples_passed);
# endif
# ifdef GL_TESS_CONTROL_SHADER_PATCHES_ARB
	BOOST_CHECK(x != ev.tess_control_shader_patches);
# endif
# ifdef GL_TESS_EVALUATION_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.tess_evaluation_shader_invocations);
# endif
# ifdef GL_TIME_ELAPSED
	BOOST_CHECK(x != ev.time_elapsed);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
	BOOST_CHECK(x == ev.transform_feedback_overflow);
# ifdef GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN
	BOOST_CHECK(x != ev.transform_feedback_primitives_written);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_STREAM_OVERFLOW_ARB
	BOOST_CHECK(x != ev.transform_feedback_stream_overflow);
# endif
# ifdef GL_VERTEX_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.vertex_shader_invocations);
# endif
# ifdef GL_VERTICES_SUBMITTED_ARB
	BOOST_CHECK(x != ev.vertices_submitted);
# endif
#endif

#ifdef GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN
	x = ev.transform_feedback_primitives_written;
# ifdef GL_ANY_SAMPLES_PASSED
	BOOST_CHECK(x != ev.any_samples_passed);
# endif
# ifdef GL_CLIPPING_INPUT_PRIMITIVES_ARB
	BOOST_CHECK(x != ev.clipping_input_primitives);
# endif
# ifdef GL_CLIPPING_OUTPUT_PRIMITIVES_ARB
	BOOST_CHECK(x != ev.clipping_output_primitives);
# endif
# ifdef GL_COMPUTE_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.compute_shader_invocations);
# endif
# ifdef GL_FRAGMENT_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.fragment_shader_invocations);
# endif
# ifdef GL_GEOMETRY_SHADER_INVOCATIONS
	BOOST_CHECK(x != ev.geometry_shader_invocations);
# endif
# ifdef GL_GEOMETRY_SHADER_PRIMITIVES_EMITTED_ARB
	BOOST_CHECK(x != ev.geometry_shader_primitives_emitted);
# endif
# ifdef GL_PRIMITIVES_GENERATED
	BOOST_CHECK(x != ev.primitives_generated);
# endif
# ifdef GL_PRIMITIVES_SUBMITTED_ARB
	BOOST_CHECK(x != ev.primitives_submitted);
# endif
# ifdef GL_SAMPLES_PASSED
	BOOST_CHECK(x != ev.samples_passed);
# endif
# ifdef GL_TESS_CONTROL_SHADER_PATCHES_ARB
	BOOST_CHECK(x != ev.tess_control_shader_patches);
# endif
# ifdef GL_TESS_EVALUATION_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.tess_evaluation_shader_invocations);
# endif
# ifdef GL_TIME_ELAPSED
	BOOST_CHECK(x != ev.time_elapsed);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_OVERFLOW_ARB
	BOOST_CHECK(x != ev.transform_feedback_overflow);
# endif
	BOOST_CHECK(x == ev.transform_feedback_primitives_written);
# ifdef GL_TRANSFORM_FEEDBACK_STREAM_OVERFLOW_ARB
	BOOST_CHECK(x != ev.transform_feedback_stream_overflow);
# endif
# ifdef GL_VERTEX_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.vertex_shader_invocations);
# endif
# ifdef GL_VERTICES_SUBMITTED_ARB
	BOOST_CHECK(x != ev.vertices_submitted);
# endif
#endif

#ifdef GL_TRANSFORM_FEEDBACK_STREAM_OVERFLOW_ARB
	x = ev.transform_feedback_stream_overflow;
# ifdef GL_ANY_SAMPLES_PASSED
	BOOST_CHECK(x != ev.any_samples_passed);
# endif
# ifdef GL_CLIPPING_INPUT_PRIMITIVES_ARB
	BOOST_CHECK(x != ev.clipping_input_primitives);
# endif
# ifdef GL_CLIPPING_OUTPUT_PRIMITIVES_ARB
	BOOST_CHECK(x != ev.clipping_output_primitives);
# endif
# ifdef GL_COMPUTE_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.compute_shader_invocations);
# endif
# ifdef GL_FRAGMENT_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.fragment_shader_invocations);
# endif
# ifdef GL_GEOMETRY_SHADER_INVOCATIONS
	BOOST_CHECK(x != ev.geometry_shader_invocations);
# endif
# ifdef GL_GEOMETRY_SHADER_PRIMITIVES_EMITTED_ARB
	BOOST_CHECK(x != ev.geometry_shader_primitives_emitted);
# endif
# ifdef GL_PRIMITIVES_GENERATED
	BOOST_CHECK(x != ev.primitives_generated);
# endif
# ifdef GL_PRIMITIVES_SUBMITTED_ARB
	BOOST_CHECK(x != ev.primitives_submitted);
# endif
# ifdef GL_SAMPLES_PASSED
	BOOST_CHECK(x != ev.samples_passed);
# endif
# ifdef GL_TESS_CONTROL_SHADER_PATCHES_ARB
	BOOST_CHECK(x != ev.tess_control_shader_patches);
# endif
# ifdef GL_TESS_EVALUATION_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.tess_evaluation_shader_invocations);
# endif
# ifdef GL_TIME_ELAPSED
	BOOST_CHECK(x != ev.time_elapsed);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_OVERFLOW_ARB
	BOOST_CHECK(x != ev.transform_feedback_overflow);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN
	BOOST_CHECK(x != ev.transform_feedback_primitives_written);
# endif
	BOOST_CHECK(x == ev.transform_feedback_stream_overflow);
# ifdef GL_VERTEX_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.vertex_shader_invocations);
# endif
# ifdef GL_VERTICES_SUBMITTED_ARB
	BOOST_CHECK(x != ev.vertices_submitted);
# endif
#endif

#ifdef GL_VERTEX_SHADER_INVOCATIONS_ARB
	x = ev.vertex_shader_invocations;
# ifdef GL_ANY_SAMPLES_PASSED
	BOOST_CHECK(x != ev.any_samples_passed);
# endif
# ifdef GL_CLIPPING_INPUT_PRIMITIVES_ARB
	BOOST_CHECK(x != ev.clipping_input_primitives);
# endif
# ifdef GL_CLIPPING_OUTPUT_PRIMITIVES_ARB
	BOOST_CHECK(x != ev.clipping_output_primitives);
# endif
# ifdef GL_COMPUTE_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.compute_shader_invocations);
# endif
# ifdef GL_FRAGMENT_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.fragment_shader_invocations);
# endif
# ifdef GL_GEOMETRY_SHADER_INVOCATIONS
	BOOST_CHECK(x != ev.geometry_shader_invocations);
# endif
# ifdef GL_GEOMETRY_SHADER_PRIMITIVES_EMITTED_ARB
	BOOST_CHECK(x != ev.geometry_shader_primitives_emitted);
# endif
# ifdef GL_PRIMITIVES_GENERATED
	BOOST_CHECK(x != ev.primitives_generated);
# endif
# ifdef GL_PRIMITIVES_SUBMITTED_ARB
	BOOST_CHECK(x != ev.primitives_submitted);
# endif
# ifdef GL_SAMPLES_PASSED
	BOOST_CHECK(x != ev.samples_passed);
# endif
# ifdef GL_TESS_CONTROL_SHADER_PATCHES_ARB
	BOOST_CHECK(x != ev.tess_control_shader_patches);
# endif
# ifdef GL_TESS_EVALUATION_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.tess_evaluation_shader_invocations);
# endif
# ifdef GL_TIME_ELAPSED
	BOOST_CHECK(x != ev.time_elapsed);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_OVERFLOW_ARB
	BOOST_CHECK(x != ev.transform_feedback_overflow);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN
	BOOST_CHECK(x != ev.transform_feedback_primitives_written);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_STREAM_OVERFLOW_ARB
	BOOST_CHECK(x != ev.transform_feedback_stream_overflow);
# endif
	BOOST_CHECK(x == ev.vertex_shader_invocations);
# ifdef GL_VERTICES_SUBMITTED_ARB
	BOOST_CHECK(x != ev.vertices_submitted);
# endif
#endif

#ifdef GL_VERTICES_SUBMITTED_ARB
	x = ev.vertices_submitted;
# ifdef GL_ANY_SAMPLES_PASSED
	BOOST_CHECK(x != ev.any_samples_passed);
# endif
# ifdef GL_CLIPPING_INPUT_PRIMITIVES_ARB
	BOOST_CHECK(x != ev.clipping_input_primitives);
# endif
# ifdef GL_CLIPPING_OUTPUT_PRIMITIVES_ARB
	BOOST_CHECK(x != ev.clipping_output_primitives);
# endif
# ifdef GL_COMPUTE_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.compute_shader_invocations);
# endif
# ifdef GL_FRAGMENT_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.fragment_shader_invocations);
# endif
# ifdef GL_GEOMETRY_SHADER_INVOCATIONS
	BOOST_CHECK(x != ev.geometry_shader_invocations);
# endif
# ifdef GL_GEOMETRY_SHADER_PRIMITIVES_EMITTED_ARB
	BOOST_CHECK(x != ev.geometry_shader_primitives_emitted);
# endif
# ifdef GL_PRIMITIVES_GENERATED
	BOOST_CHECK(x != ev.primitives_generated);
# endif
# ifdef GL_PRIMITIVES_SUBMITTED_ARB
	BOOST_CHECK(x != ev.primitives_submitted);
# endif
# ifdef GL_SAMPLES_PASSED
	BOOST_CHECK(x != ev.samples_passed);
# endif
# ifdef GL_TESS_CONTROL_SHADER_PATCHES_ARB
	BOOST_CHECK(x != ev.tess_control_shader_patches);
# endif
# ifdef GL_TESS_EVALUATION_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.tess_evaluation_shader_invocations);
# endif
# ifdef GL_TIME_ELAPSED
	BOOST_CHECK(x != ev.time_elapsed);
# endif
# ifdef GL_TIMESTAMP
	BOOST_CHECK(x != ev.timestamp);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_OVERFLOW_ARB
	BOOST_CHECK(x != ev.transform_feedback_overflow);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN
	BOOST_CHECK(x != ev.transform_feedback_primitives_written);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_STREAM_OVERFLOW_ARB
	BOOST_CHECK(x != ev.transform_feedback_stream_overflow);
# endif
# ifdef GL_VERTEX_SHADER_INVOCATIONS_ARB
	BOOST_CHECK(x != ev.vertex_shader_invocations);
# endif
	BOOST_CHECK(x == ev.vertices_submitted);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
