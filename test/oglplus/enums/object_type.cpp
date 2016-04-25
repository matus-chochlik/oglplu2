//  File test/oglplus/enums/object_type.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_object_type

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_object_type_tests)

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
	BOOST_CHECK(x == ev.transform_feedback);
# ifdef GL_VERTEX_ARRAY
	BOOST_CHECK(x != ev.vertex_array);
# endif
#endif

#ifdef GL_VERTEX_ARRAY
	x = ev.vertex_array;
	BOOST_CHECK(x == ev.vertex_array);
#endif
}

BOOST_AUTO_TEST_CASE(enum_object_type_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	object_type x;
	(void)x;

#ifdef GL_BUFFER
	x = ev.buffer;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"BUFFER"
	) == 0);
#endif

#ifdef GL_FRAMEBUFFER
	x = ev.framebuffer;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"FRAMEBUFFER"
	) == 0);
#endif

#ifdef GL_NONE
	x = ev.none;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"NONE"
	) == 0);
#endif

#ifdef GL_PROGRAM
	x = ev.program;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PROGRAM"
	) == 0);
#endif

#ifdef GL_PROGRAM_PIPELINE
	x = ev.program_pipeline;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PROGRAM_PIPELINE"
	) == 0);
#endif

#ifdef GL_QUERY
	x = ev.query;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"QUERY"
	) == 0);
#endif

#ifdef GL_RENDERBUFFER
	x = ev.renderbuffer;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RENDERBUFFER"
	) == 0);
#endif

#ifdef GL_SAMPLER
	x = ev.sampler;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SAMPLER"
	) == 0);
#endif

#ifdef GL_SHADER
	x = ev.shader;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SHADER"
	) == 0);
#endif

#ifdef GL_TEXTURE
	x = ev.texture;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE"
	) == 0);
#endif

#ifdef GL_TRANSFORM_FEEDBACK
	x = ev.transform_feedback;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TRANSFORM_FEEDBACK"
	) == 0);
#endif

#ifdef GL_VERTEX_ARRAY
	x = ev.vertex_array;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"VERTEX_ARRAY"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_object_type_range)
{
	using namespace oglplus;
	auto count = enum_value_range<object_type>().size();

#ifdef GL_BUFFER
{
	--count;
	auto r = enum_value_range<object_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		object_type(GL_BUFFER)
	) != r.end());
}
#endif

#ifdef GL_FRAMEBUFFER
{
	--count;
	auto r = enum_value_range<object_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		object_type(GL_FRAMEBUFFER)
	) != r.end());
}
#endif

#ifdef GL_NONE
{
	--count;
	auto r = enum_value_range<object_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		object_type(GL_NONE)
	) != r.end());
}
#endif

#ifdef GL_PROGRAM
{
	--count;
	auto r = enum_value_range<object_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		object_type(GL_PROGRAM)
	) != r.end());
}
#endif

#ifdef GL_PROGRAM_PIPELINE
{
	--count;
	auto r = enum_value_range<object_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		object_type(GL_PROGRAM_PIPELINE)
	) != r.end());
}
#endif

#ifdef GL_QUERY
{
	--count;
	auto r = enum_value_range<object_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		object_type(GL_QUERY)
	) != r.end());
}
#endif

#ifdef GL_RENDERBUFFER
{
	--count;
	auto r = enum_value_range<object_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		object_type(GL_RENDERBUFFER)
	) != r.end());
}
#endif

#ifdef GL_SAMPLER
{
	--count;
	auto r = enum_value_range<object_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		object_type(GL_SAMPLER)
	) != r.end());
}
#endif

#ifdef GL_SHADER
{
	--count;
	auto r = enum_value_range<object_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		object_type(GL_SHADER)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE
{
	--count;
	auto r = enum_value_range<object_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		object_type(GL_TEXTURE)
	) != r.end());
}
#endif

#ifdef GL_TRANSFORM_FEEDBACK
{
	--count;
	auto r = enum_value_range<object_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		object_type(GL_TRANSFORM_FEEDBACK)
	) != r.end());
}
#endif

#ifdef GL_VERTEX_ARRAY
{
	--count;
	auto r = enum_value_range<object_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		object_type(GL_VERTEX_ARRAY)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_object_type_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	object_type x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_BUFFER
	x = ev.buffer;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.buffer);
#endif

#ifdef GL_FRAMEBUFFER
	x = ev.framebuffer;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.framebuffer);
#endif

#ifdef GL_NONE
	x = ev.none;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.none);
#endif

#ifdef GL_PROGRAM
	x = ev.program;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.program);
#endif

#ifdef GL_PROGRAM_PIPELINE
	x = ev.program_pipeline;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.program_pipeline);
#endif

#ifdef GL_QUERY
	x = ev.query;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.query);
#endif

#ifdef GL_RENDERBUFFER
	x = ev.renderbuffer;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.renderbuffer);
#endif

#ifdef GL_SAMPLER
	x = ev.sampler;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.sampler);
#endif

#ifdef GL_SHADER
	x = ev.shader;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.shader);
#endif

#ifdef GL_TEXTURE
	x = ev.texture;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture);
#endif

#ifdef GL_TRANSFORM_FEEDBACK
	x = ev.transform_feedback;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.transform_feedback);
#endif

#ifdef GL_VERTEX_ARRAY
	x = ev.vertex_array;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.vertex_array);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
