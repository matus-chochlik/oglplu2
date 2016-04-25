//  File test/oglplus/enums/renderbuffer_parameter.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_renderbuffer_parameter

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_renderbuffer_parameter_tests)

BOOST_AUTO_TEST_CASE(enum_renderbuffer_parameter_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	renderbuffer_parameter x;
	(void)x;

#ifdef GL_RENDERBUFFER_ALPHA_SIZE
	x = ev.renderbuffer_alpha_size;
	BOOST_CHECK(x == ev.renderbuffer_alpha_size);
# ifdef GL_RENDERBUFFER_BLUE_SIZE
	BOOST_CHECK(x != ev.renderbuffer_blue_size);
# endif
# ifdef GL_RENDERBUFFER_DEPTH_SIZE
	BOOST_CHECK(x != ev.renderbuffer_depth_size);
# endif
# ifdef GL_RENDERBUFFER_GREEN_SIZE
	BOOST_CHECK(x != ev.renderbuffer_green_size);
# endif
# ifdef GL_RENDERBUFFER_HEIGHT
	BOOST_CHECK(x != ev.renderbuffer_height);
# endif
# ifdef GL_RENDERBUFFER_INTERNAL_FORMAT
	BOOST_CHECK(x != ev.renderbuffer_internal_format);
# endif
# ifdef GL_RENDERBUFFER_RED_SIZE
	BOOST_CHECK(x != ev.renderbuffer_red_size);
# endif
# ifdef GL_RENDERBUFFER_SAMPLES
	BOOST_CHECK(x != ev.renderbuffer_samples);
# endif
# ifdef GL_RENDERBUFFER_STENCIL_SIZE
	BOOST_CHECK(x != ev.renderbuffer_stencil_size);
# endif
# ifdef GL_RENDERBUFFER_WIDTH
	BOOST_CHECK(x != ev.renderbuffer_width);
# endif
#endif

#ifdef GL_RENDERBUFFER_BLUE_SIZE
	x = ev.renderbuffer_blue_size;
	BOOST_CHECK(x == ev.renderbuffer_blue_size);
# ifdef GL_RENDERBUFFER_DEPTH_SIZE
	BOOST_CHECK(x != ev.renderbuffer_depth_size);
# endif
# ifdef GL_RENDERBUFFER_GREEN_SIZE
	BOOST_CHECK(x != ev.renderbuffer_green_size);
# endif
# ifdef GL_RENDERBUFFER_HEIGHT
	BOOST_CHECK(x != ev.renderbuffer_height);
# endif
# ifdef GL_RENDERBUFFER_INTERNAL_FORMAT
	BOOST_CHECK(x != ev.renderbuffer_internal_format);
# endif
# ifdef GL_RENDERBUFFER_RED_SIZE
	BOOST_CHECK(x != ev.renderbuffer_red_size);
# endif
# ifdef GL_RENDERBUFFER_SAMPLES
	BOOST_CHECK(x != ev.renderbuffer_samples);
# endif
# ifdef GL_RENDERBUFFER_STENCIL_SIZE
	BOOST_CHECK(x != ev.renderbuffer_stencil_size);
# endif
# ifdef GL_RENDERBUFFER_WIDTH
	BOOST_CHECK(x != ev.renderbuffer_width);
# endif
#endif

#ifdef GL_RENDERBUFFER_DEPTH_SIZE
	x = ev.renderbuffer_depth_size;
	BOOST_CHECK(x == ev.renderbuffer_depth_size);
# ifdef GL_RENDERBUFFER_GREEN_SIZE
	BOOST_CHECK(x != ev.renderbuffer_green_size);
# endif
# ifdef GL_RENDERBUFFER_HEIGHT
	BOOST_CHECK(x != ev.renderbuffer_height);
# endif
# ifdef GL_RENDERBUFFER_INTERNAL_FORMAT
	BOOST_CHECK(x != ev.renderbuffer_internal_format);
# endif
# ifdef GL_RENDERBUFFER_RED_SIZE
	BOOST_CHECK(x != ev.renderbuffer_red_size);
# endif
# ifdef GL_RENDERBUFFER_SAMPLES
	BOOST_CHECK(x != ev.renderbuffer_samples);
# endif
# ifdef GL_RENDERBUFFER_STENCIL_SIZE
	BOOST_CHECK(x != ev.renderbuffer_stencil_size);
# endif
# ifdef GL_RENDERBUFFER_WIDTH
	BOOST_CHECK(x != ev.renderbuffer_width);
# endif
#endif

#ifdef GL_RENDERBUFFER_GREEN_SIZE
	x = ev.renderbuffer_green_size;
	BOOST_CHECK(x == ev.renderbuffer_green_size);
# ifdef GL_RENDERBUFFER_HEIGHT
	BOOST_CHECK(x != ev.renderbuffer_height);
# endif
# ifdef GL_RENDERBUFFER_INTERNAL_FORMAT
	BOOST_CHECK(x != ev.renderbuffer_internal_format);
# endif
# ifdef GL_RENDERBUFFER_RED_SIZE
	BOOST_CHECK(x != ev.renderbuffer_red_size);
# endif
# ifdef GL_RENDERBUFFER_SAMPLES
	BOOST_CHECK(x != ev.renderbuffer_samples);
# endif
# ifdef GL_RENDERBUFFER_STENCIL_SIZE
	BOOST_CHECK(x != ev.renderbuffer_stencil_size);
# endif
# ifdef GL_RENDERBUFFER_WIDTH
	BOOST_CHECK(x != ev.renderbuffer_width);
# endif
#endif

#ifdef GL_RENDERBUFFER_HEIGHT
	x = ev.renderbuffer_height;
	BOOST_CHECK(x == ev.renderbuffer_height);
# ifdef GL_RENDERBUFFER_INTERNAL_FORMAT
	BOOST_CHECK(x != ev.renderbuffer_internal_format);
# endif
# ifdef GL_RENDERBUFFER_RED_SIZE
	BOOST_CHECK(x != ev.renderbuffer_red_size);
# endif
# ifdef GL_RENDERBUFFER_SAMPLES
	BOOST_CHECK(x != ev.renderbuffer_samples);
# endif
# ifdef GL_RENDERBUFFER_STENCIL_SIZE
	BOOST_CHECK(x != ev.renderbuffer_stencil_size);
# endif
# ifdef GL_RENDERBUFFER_WIDTH
	BOOST_CHECK(x != ev.renderbuffer_width);
# endif
#endif

#ifdef GL_RENDERBUFFER_INTERNAL_FORMAT
	x = ev.renderbuffer_internal_format;
	BOOST_CHECK(x == ev.renderbuffer_internal_format);
# ifdef GL_RENDERBUFFER_RED_SIZE
	BOOST_CHECK(x != ev.renderbuffer_red_size);
# endif
# ifdef GL_RENDERBUFFER_SAMPLES
	BOOST_CHECK(x != ev.renderbuffer_samples);
# endif
# ifdef GL_RENDERBUFFER_STENCIL_SIZE
	BOOST_CHECK(x != ev.renderbuffer_stencil_size);
# endif
# ifdef GL_RENDERBUFFER_WIDTH
	BOOST_CHECK(x != ev.renderbuffer_width);
# endif
#endif

#ifdef GL_RENDERBUFFER_RED_SIZE
	x = ev.renderbuffer_red_size;
	BOOST_CHECK(x == ev.renderbuffer_red_size);
# ifdef GL_RENDERBUFFER_SAMPLES
	BOOST_CHECK(x != ev.renderbuffer_samples);
# endif
# ifdef GL_RENDERBUFFER_STENCIL_SIZE
	BOOST_CHECK(x != ev.renderbuffer_stencil_size);
# endif
# ifdef GL_RENDERBUFFER_WIDTH
	BOOST_CHECK(x != ev.renderbuffer_width);
# endif
#endif

#ifdef GL_RENDERBUFFER_SAMPLES
	x = ev.renderbuffer_samples;
	BOOST_CHECK(x == ev.renderbuffer_samples);
# ifdef GL_RENDERBUFFER_STENCIL_SIZE
	BOOST_CHECK(x != ev.renderbuffer_stencil_size);
# endif
# ifdef GL_RENDERBUFFER_WIDTH
	BOOST_CHECK(x != ev.renderbuffer_width);
# endif
#endif

#ifdef GL_RENDERBUFFER_STENCIL_SIZE
	x = ev.renderbuffer_stencil_size;
	BOOST_CHECK(x == ev.renderbuffer_stencil_size);
# ifdef GL_RENDERBUFFER_WIDTH
	BOOST_CHECK(x != ev.renderbuffer_width);
# endif
#endif

#ifdef GL_RENDERBUFFER_WIDTH
	x = ev.renderbuffer_width;
	BOOST_CHECK(x == ev.renderbuffer_width);
#endif
}

BOOST_AUTO_TEST_CASE(enum_renderbuffer_parameter_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	renderbuffer_parameter x;
	(void)x;

#ifdef GL_RENDERBUFFER_ALPHA_SIZE
	x = ev.renderbuffer_alpha_size;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RENDERBUFFER_ALPHA_SIZE"
	) == 0);
#endif

#ifdef GL_RENDERBUFFER_BLUE_SIZE
	x = ev.renderbuffer_blue_size;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RENDERBUFFER_BLUE_SIZE"
	) == 0);
#endif

#ifdef GL_RENDERBUFFER_DEPTH_SIZE
	x = ev.renderbuffer_depth_size;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RENDERBUFFER_DEPTH_SIZE"
	) == 0);
#endif

#ifdef GL_RENDERBUFFER_GREEN_SIZE
	x = ev.renderbuffer_green_size;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RENDERBUFFER_GREEN_SIZE"
	) == 0);
#endif

#ifdef GL_RENDERBUFFER_HEIGHT
	x = ev.renderbuffer_height;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RENDERBUFFER_HEIGHT"
	) == 0);
#endif

#ifdef GL_RENDERBUFFER_INTERNAL_FORMAT
	x = ev.renderbuffer_internal_format;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RENDERBUFFER_INTERNAL_FORMAT"
	) == 0);
#endif

#ifdef GL_RENDERBUFFER_RED_SIZE
	x = ev.renderbuffer_red_size;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RENDERBUFFER_RED_SIZE"
	) == 0);
#endif

#ifdef GL_RENDERBUFFER_SAMPLES
	x = ev.renderbuffer_samples;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RENDERBUFFER_SAMPLES"
	) == 0);
#endif

#ifdef GL_RENDERBUFFER_STENCIL_SIZE
	x = ev.renderbuffer_stencil_size;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RENDERBUFFER_STENCIL_SIZE"
	) == 0);
#endif

#ifdef GL_RENDERBUFFER_WIDTH
	x = ev.renderbuffer_width;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RENDERBUFFER_WIDTH"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_renderbuffer_parameter_range)
{
	using namespace oglplus;
	auto count = enum_value_range<renderbuffer_parameter>().size();

#ifdef GL_RENDERBUFFER_ALPHA_SIZE
{
	--count;
	auto r = enum_value_range<renderbuffer_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		renderbuffer_parameter(GL_RENDERBUFFER_ALPHA_SIZE)
	) != r.end());
}
#endif

#ifdef GL_RENDERBUFFER_BLUE_SIZE
{
	--count;
	auto r = enum_value_range<renderbuffer_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		renderbuffer_parameter(GL_RENDERBUFFER_BLUE_SIZE)
	) != r.end());
}
#endif

#ifdef GL_RENDERBUFFER_DEPTH_SIZE
{
	--count;
	auto r = enum_value_range<renderbuffer_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		renderbuffer_parameter(GL_RENDERBUFFER_DEPTH_SIZE)
	) != r.end());
}
#endif

#ifdef GL_RENDERBUFFER_GREEN_SIZE
{
	--count;
	auto r = enum_value_range<renderbuffer_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		renderbuffer_parameter(GL_RENDERBUFFER_GREEN_SIZE)
	) != r.end());
}
#endif

#ifdef GL_RENDERBUFFER_HEIGHT
{
	--count;
	auto r = enum_value_range<renderbuffer_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		renderbuffer_parameter(GL_RENDERBUFFER_HEIGHT)
	) != r.end());
}
#endif

#ifdef GL_RENDERBUFFER_INTERNAL_FORMAT
{
	--count;
	auto r = enum_value_range<renderbuffer_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		renderbuffer_parameter(GL_RENDERBUFFER_INTERNAL_FORMAT)
	) != r.end());
}
#endif

#ifdef GL_RENDERBUFFER_RED_SIZE
{
	--count;
	auto r = enum_value_range<renderbuffer_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		renderbuffer_parameter(GL_RENDERBUFFER_RED_SIZE)
	) != r.end());
}
#endif

#ifdef GL_RENDERBUFFER_SAMPLES
{
	--count;
	auto r = enum_value_range<renderbuffer_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		renderbuffer_parameter(GL_RENDERBUFFER_SAMPLES)
	) != r.end());
}
#endif

#ifdef GL_RENDERBUFFER_STENCIL_SIZE
{
	--count;
	auto r = enum_value_range<renderbuffer_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		renderbuffer_parameter(GL_RENDERBUFFER_STENCIL_SIZE)
	) != r.end());
}
#endif

#ifdef GL_RENDERBUFFER_WIDTH
{
	--count;
	auto r = enum_value_range<renderbuffer_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		renderbuffer_parameter(GL_RENDERBUFFER_WIDTH)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_renderbuffer_parameter_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	renderbuffer_parameter x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_RENDERBUFFER_ALPHA_SIZE
	x = ev.renderbuffer_alpha_size;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.renderbuffer_alpha_size);
#endif

#ifdef GL_RENDERBUFFER_BLUE_SIZE
	x = ev.renderbuffer_blue_size;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.renderbuffer_blue_size);
#endif

#ifdef GL_RENDERBUFFER_DEPTH_SIZE
	x = ev.renderbuffer_depth_size;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.renderbuffer_depth_size);
#endif

#ifdef GL_RENDERBUFFER_GREEN_SIZE
	x = ev.renderbuffer_green_size;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.renderbuffer_green_size);
#endif

#ifdef GL_RENDERBUFFER_HEIGHT
	x = ev.renderbuffer_height;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.renderbuffer_height);
#endif

#ifdef GL_RENDERBUFFER_INTERNAL_FORMAT
	x = ev.renderbuffer_internal_format;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.renderbuffer_internal_format);
#endif

#ifdef GL_RENDERBUFFER_RED_SIZE
	x = ev.renderbuffer_red_size;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.renderbuffer_red_size);
#endif

#ifdef GL_RENDERBUFFER_SAMPLES
	x = ev.renderbuffer_samples;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.renderbuffer_samples);
#endif

#ifdef GL_RENDERBUFFER_STENCIL_SIZE
	x = ev.renderbuffer_stencil_size;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.renderbuffer_stencil_size);
#endif

#ifdef GL_RENDERBUFFER_WIDTH
	x = ev.renderbuffer_width;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.renderbuffer_width);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
