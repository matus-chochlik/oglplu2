//  File test/oglplus/enums/object_type.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_object_type

#include <boost/test/unit_test.hpp>
#include "common.hpp"

BOOST_AUTO_TEST_SUITE(enum_object_type)

BOOST_AUTO_TEST_CASE(enum_object_type_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	object_type x;
	(void)x;

#ifdef GL_BUFFER
	x = ev.buffer;
	BOOST_CHECK(x == ev.buffer);
# ifdef GL_FRAMEBUFFER
	BOOST_CHECK(x != ev.framebuffer);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_PROGRAM
	BOOST_CHECK(x != ev.program);
# endif
# ifdef GL_PROGRAM_PIPELINE
	BOOST_CHECK(x != ev.program_pipeline);
# endif
# ifdef GL_QUERY
	BOOST_CHECK(x != ev.query);
# endif
# ifdef GL_RENDERBUFFER
	BOOST_CHECK(x != ev.renderbuffer);
# endif
# ifdef GL_SAMPLER
	BOOST_CHECK(x != ev.sampler);
# endif
# ifdef GL_SHADER
	BOOST_CHECK(x != ev.shader);
# endif
# ifdef GL_TEXTURE
	BOOST_CHECK(x != ev.texture);
# endif
# ifdef GL_TRANSFORM_FEEDBACK
	BOOST_CHECK(x != ev.transform_feedback);
# endif
# ifdef GL_VERTEX_ARRAY
	BOOST_CHECK(x != ev.vertex_array);
# endif
#endif

#ifdef GL_FRAMEBUFFER
	x = ev.framebuffer;
# ifdef GL_BUFFER
	BOOST_CHECK(x != ev.buffer);
# endif
	BOOST_CHECK(x == ev.framebuffer);
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_PROGRAM
	BOOST_CHECK(x != ev.program);
# endif
# ifdef GL_PROGRAM_PIPELINE
	BOOST_CHECK(x != ev.program_pipeline);
# endif
# ifdef GL_QUERY
	BOOST_CHECK(x != ev.query);
# endif
# ifdef GL_RENDERBUFFER
	BOOST_CHECK(x != ev.renderbuffer);
# endif
# ifdef GL_SAMPLER
	BOOST_CHECK(x != ev.sampler);
# endif
# ifdef GL_SHADER
	BOOST_CHECK(x != ev.shader);
# endif
# ifdef GL_TEXTURE
	BOOST_CHECK(x != ev.texture);
# endif
# ifdef GL_TRANSFORM_FEEDBACK
	BOOST_CHECK(x != ev.transform_feedback);
# endif
# ifdef GL_VERTEX_ARRAY
	BOOST_CHECK(x != ev.vertex_array);
# endif
#endif

#ifdef GL_NONE
	x = ev.none;
# ifdef GL_BUFFER
	BOOST_CHECK(x != ev.buffer);
# endif
# ifdef GL_FRAMEBUFFER
	BOOST_CHECK(x != ev.framebuffer);
# endif
	BOOST_CHECK(x == ev.none);
# ifdef GL_PROGRAM
	BOOST_CHECK(x != ev.program);
# endif
# ifdef GL_PROGRAM_PIPELINE
	BOOST_CHECK(x != ev.program_pipeline);
# endif
# ifdef GL_QUERY
	BOOST_CHECK(x != ev.query);
# endif
# ifdef GL_RENDERBUFFER
	BOOST_CHECK(x != ev.renderbuffer);
# endif
# ifdef GL_SAMPLER
	BOOST_CHECK(x != ev.sampler);
# endif
# ifdef GL_SHADER
	BOOST_CHECK(x != ev.shader);
# endif
# ifdef GL_TEXTURE
	BOOST_CHECK(x != ev.texture);
# endif
# ifdef GL_TRANSFORM_FEEDBACK
	BOOST_CHECK(x != ev.transform_feedback);
# endif
# ifdef GL_VERTEX_ARRAY
	BOOST_CHECK(x != ev.vertex_array);
# endif
#endif

#ifdef GL_PROGRAM
	x = ev.program;
# ifdef GL_BUFFER
	BOOST_CHECK(x != ev.buffer);
# endif
# ifdef GL_FRAMEBUFFER
	BOOST_CHECK(x != ev.framebuffer);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
	BOOST_CHECK(x == ev.program);
# ifdef GL_PROGRAM_PIPELINE
	BOOST_CHECK(x != ev.program_pipeline);
# endif
# ifdef GL_QUERY
	BOOST_CHECK(x != ev.query);
# endif
# ifdef GL_RENDERBUFFER
	BOOST_CHECK(x != ev.renderbuffer);
# endif
# ifdef GL_SAMPLER
	BOOST_CHECK(x != ev.sampler);
# endif
# ifdef GL_SHADER
	BOOST_CHECK(x != ev.shader);
# endif
# ifdef GL_TEXTURE
	BOOST_CHECK(x != ev.texture);
# endif
# ifdef GL_TRANSFORM_FEEDBACK
	BOOST_CHECK(x != ev.transform_feedback);
# endif
# ifdef GL_VERTEX_ARRAY
	BOOST_CHECK(x != ev.vertex_array);
# endif
#endif

#ifdef GL_PROGRAM_PIPELINE
	x = ev.program_pipeline;
# ifdef GL_BUFFER
	BOOST_CHECK(x != ev.buffer);
# endif
# ifdef GL_FRAMEBUFFER
	BOOST_CHECK(x != ev.framebuffer);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_PROGRAM
	BOOST_CHECK(x != ev.program);
# endif
	BOOST_CHECK(x == ev.program_pipeline);
# ifdef GL_QUERY
	BOOST_CHECK(x != ev.query);
# endif
# ifdef GL_RENDERBUFFER
	BOOST_CHECK(x != ev.renderbuffer);
# endif
# ifdef GL_SAMPLER
	BOOST_CHECK(x != ev.sampler);
# endif
# ifdef GL_SHADER
	BOOST_CHECK(x != ev.shader);
# endif
# ifdef GL_TEXTURE
	BOOST_CHECK(x != ev.texture);
# endif
# ifdef GL_TRANSFORM_FEEDBACK
	BOOST_CHECK(x != ev.transform_feedback);
# endif
# ifdef GL_VERTEX_ARRAY
	BOOST_CHECK(x != ev.vertex_array);
# endif
#endif

#ifdef GL_QUERY
	x = ev.query;
# ifdef GL_BUFFER
	BOOST_CHECK(x != ev.buffer);
# endif
# ifdef GL_FRAMEBUFFER
	BOOST_CHECK(x != ev.framebuffer);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_PROGRAM
	BOOST_CHECK(x != ev.program);
# endif
# ifdef GL_PROGRAM_PIPELINE
	BOOST_CHECK(x != ev.program_pipeline);
# endif
	BOOST_CHECK(x == ev.query);
# ifdef GL_RENDERBUFFER
	BOOST_CHECK(x != ev.renderbuffer);
# endif
# ifdef GL_SAMPLER
	BOOST_CHECK(x != ev.sampler);
# endif
# ifdef GL_SHADER
	BOOST_CHECK(x != ev.shader);
# endif
# ifdef GL_TEXTURE
	BOOST_CHECK(x != ev.texture);
# endif
# ifdef GL_TRANSFORM_FEEDBACK
	BOOST_CHECK(x != ev.transform_feedback);
# endif
# ifdef GL_VERTEX_ARRAY
	BOOST_CHECK(x != ev.vertex_array);
# endif
#endif

#ifdef GL_RENDERBUFFER
	x = ev.renderbuffer;
# ifdef GL_BUFFER
	BOOST_CHECK(x != ev.buffer);
# endif
# ifdef GL_FRAMEBUFFER
	BOOST_CHECK(x != ev.framebuffer);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_PROGRAM
	BOOST_CHECK(x != ev.program);
# endif
# ifdef GL_PROGRAM_PIPELINE
	BOOST_CHECK(x != ev.program_pipeline);
# endif
# ifdef GL_QUERY
	BOOST_CHECK(x != ev.query);
# endif
	BOOST_CHECK(x == ev.renderbuffer);
# ifdef GL_SAMPLER
	BOOST_CHECK(x != ev.sampler);
# endif
# ifdef GL_SHADER
	BOOST_CHECK(x != ev.shader);
# endif
# ifdef GL_TEXTURE
	BOOST_CHECK(x != ev.texture);
# endif
# ifdef GL_TRANSFORM_FEEDBACK
	BOOST_CHECK(x != ev.transform_feedback);
# endif
# ifdef GL_VERTEX_ARRAY
	BOOST_CHECK(x != ev.vertex_array);
# endif
#endif

#ifdef GL_SAMPLER
	x = ev.sampler;
# ifdef GL_BUFFER
	BOOST_CHECK(x != ev.buffer);
# endif
# ifdef GL_FRAMEBUFFER
	BOOST_CHECK(x != ev.framebuffer);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_PROGRAM
	BOOST_CHECK(x != ev.program);
# endif
# ifdef GL_PROGRAM_PIPELINE
	BOOST_CHECK(x != ev.program_pipeline);
# endif
# ifdef GL_QUERY
	BOOST_CHECK(x != ev.query);
# endif
# ifdef GL_RENDERBUFFER
	BOOST_CHECK(x != ev.renderbuffer);
# endif
	BOOST_CHECK(x == ev.sampler);
# ifdef GL_SHADER
	BOOST_CHECK(x != ev.shader);
# endif
# ifdef GL_TEXTURE
	BOOST_CHECK(x != ev.texture);
# endif
# ifdef GL_TRANSFORM_FEEDBACK
	BOOST_CHECK(x != ev.transform_feedback);
# endif
# ifdef GL_VERTEX_ARRAY
	BOOST_CHECK(x != ev.vertex_array);
# endif
#endif

#ifdef GL_SHADER
	x = ev.shader;
# ifdef GL_BUFFER
	BOOST_CHECK(x != ev.buffer);
# endif
# ifdef GL_FRAMEBUFFER
	BOOST_CHECK(x != ev.framebuffer);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_PROGRAM
	BOOST_CHECK(x != ev.program);
# endif
# ifdef GL_PROGRAM_PIPELINE
	BOOST_CHECK(x != ev.program_pipeline);
# endif
# ifdef GL_QUERY
	BOOST_CHECK(x != ev.query);
# endif
# ifdef GL_RENDERBUFFER
	BOOST_CHECK(x != ev.renderbuffer);
# endif
# ifdef GL_SAMPLER
	BOOST_CHECK(x != ev.sampler);
# endif
	BOOST_CHECK(x == ev.shader);
# ifdef GL_TEXTURE
	BOOST_CHECK(x != ev.texture);
# endif
# ifdef GL_TRANSFORM_FEEDBACK
	BOOST_CHECK(x != ev.transform_feedback);
# endif
# ifdef GL_VERTEX_ARRAY
	BOOST_CHECK(x != ev.vertex_array);
# endif
#endif

#ifdef GL_TEXTURE
	x = ev.texture;
# ifdef GL_BUFFER
	BOOST_CHECK(x != ev.buffer);
# endif
# ifdef GL_FRAMEBUFFER
	BOOST_CHECK(x != ev.framebuffer);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_PROGRAM
	BOOST_CHECK(x != ev.program);
# endif
# ifdef GL_PROGRAM_PIPELINE
	BOOST_CHECK(x != ev.program_pipeline);
# endif
# ifdef GL_QUERY
	BOOST_CHECK(x != ev.query);
# endif
# ifdef GL_RENDERBUFFER
	BOOST_CHECK(x != ev.renderbuffer);
# endif
# ifdef GL_SAMPLER
	BOOST_CHECK(x != ev.sampler);
# endif
# ifdef GL_SHADER
	BOOST_CHECK(x != ev.shader);
# endif
	BOOST_CHECK(x == ev.texture);
# ifdef GL_TRANSFORM_FEEDBACK
	BOOST_CHECK(x != ev.transform_feedback);
# endif
# ifdef GL_VERTEX_ARRAY
	BOOST_CHECK(x != ev.vertex_array);
# endif
#endif

#ifdef GL_TRANSFORM_FEEDBACK
	x = ev.transform_feedback;
# ifdef GL_BUFFER
	BOOST_CHECK(x != ev.buffer);
# endif
# ifdef GL_FRAMEBUFFER
	BOOST_CHECK(x != ev.framebuffer);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_PROGRAM
	BOOST_CHECK(x != ev.program);
# endif
# ifdef GL_PROGRAM_PIPELINE
	BOOST_CHECK(x != ev.program_pipeline);
# endif
# ifdef GL_QUERY
	BOOST_CHECK(x != ev.query);
# endif
# ifdef GL_RENDERBUFFER
	BOOST_CHECK(x != ev.renderbuffer);
# endif
# ifdef GL_SAMPLER
	BOOST_CHECK(x != ev.sampler);
# endif
# ifdef GL_SHADER
	BOOST_CHECK(x != ev.shader);
# endif
# ifdef GL_TEXTURE
	BOOST_CHECK(x != ev.texture);
# endif
	BOOST_CHECK(x == ev.transform_feedback);
# ifdef GL_VERTEX_ARRAY
	BOOST_CHECK(x != ev.vertex_array);
# endif
#endif

#ifdef GL_VERTEX_ARRAY
	x = ev.vertex_array;
# ifdef GL_BUFFER
	BOOST_CHECK(x != ev.buffer);
# endif
# ifdef GL_FRAMEBUFFER
	BOOST_CHECK(x != ev.framebuffer);
# endif
# ifdef GL_NONE
	BOOST_CHECK(x != ev.none);
# endif
# ifdef GL_PROGRAM
	BOOST_CHECK(x != ev.program);
# endif
# ifdef GL_PROGRAM_PIPELINE
	BOOST_CHECK(x != ev.program_pipeline);
# endif
# ifdef GL_QUERY
	BOOST_CHECK(x != ev.query);
# endif
# ifdef GL_RENDERBUFFER
	BOOST_CHECK(x != ev.renderbuffer);
# endif
# ifdef GL_SAMPLER
	BOOST_CHECK(x != ev.sampler);
# endif
# ifdef GL_SHADER
	BOOST_CHECK(x != ev.shader);
# endif
# ifdef GL_TEXTURE
	BOOST_CHECK(x != ev.texture);
# endif
# ifdef GL_TRANSFORM_FEEDBACK
	BOOST_CHECK(x != ev.transform_feedback);
# endif
	BOOST_CHECK(x == ev.vertex_array);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
