//  File test/oglplus/enums/shader_type.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_shader_type

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_shader_type_tests)

BOOST_AUTO_TEST_CASE(enum_shader_type_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	shader_type x;
	(void)x;

#ifdef GL_COMPUTE_SHADER
	x = ev.compute_shader;
	BOOST_CHECK(x == ev.compute_shader);
# ifdef GL_FRAGMENT_SHADER
	BOOST_CHECK(x != ev.fragment_shader);
# endif
# ifdef GL_GEOMETRY_SHADER
	BOOST_CHECK(x != ev.geometry_shader);
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

BOOST_AUTO_TEST_CASE(enum_shader_type_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	shader_type x;
	(void)x;

#ifdef GL_COMPUTE_SHADER
	x = ev.compute_shader;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"COMPUTE_SHADER"
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

BOOST_AUTO_TEST_CASE(enum_shader_type_range)
{
	using namespace oglplus;
	auto count = enum_value_range<shader_type>().size();

#ifdef GL_COMPUTE_SHADER
{
	--count;
	auto r = enum_value_range<shader_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		shader_type(GL_COMPUTE_SHADER)
	) != r.end());
}
#endif

#ifdef GL_FRAGMENT_SHADER
{
	--count;
	auto r = enum_value_range<shader_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		shader_type(GL_FRAGMENT_SHADER)
	) != r.end());
}
#endif

#ifdef GL_GEOMETRY_SHADER
{
	--count;
	auto r = enum_value_range<shader_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		shader_type(GL_GEOMETRY_SHADER)
	) != r.end());
}
#endif

#ifdef GL_TESS_CONTROL_SHADER
{
	--count;
	auto r = enum_value_range<shader_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		shader_type(GL_TESS_CONTROL_SHADER)
	) != r.end());
}
#endif

#ifdef GL_TESS_EVALUATION_SHADER
{
	--count;
	auto r = enum_value_range<shader_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		shader_type(GL_TESS_EVALUATION_SHADER)
	) != r.end());
}
#endif

#ifdef GL_VERTEX_SHADER
{
	--count;
	auto r = enum_value_range<shader_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		shader_type(GL_VERTEX_SHADER)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_shader_type_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	shader_type x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_COMPUTE_SHADER
	x = ev.compute_shader;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.compute_shader);
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
