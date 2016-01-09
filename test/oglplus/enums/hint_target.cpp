//  File test/oglplus/enums/hint_target.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_hint_target

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_hint_target_tests)

BOOST_AUTO_TEST_CASE(enum_hint_target_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	hint_target x;
	(void)x;

#ifdef GL_FRAGMENT_SHADER_DERIVATIVE_HINT
	x = ev.fragment_shader_derivative_hint;
	BOOST_CHECK(x == ev.fragment_shader_derivative_hint);
# ifdef GL_LINE_SMOOTH_HINT
	BOOST_CHECK(x != ev.line_smooth_hint);
# endif
# ifdef GL_POLYGON_SMOOTH_HINT
	BOOST_CHECK(x != ev.polygon_smooth_hint);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
#endif

#ifdef GL_LINE_SMOOTH_HINT
	x = ev.line_smooth_hint;
	BOOST_CHECK(x == ev.line_smooth_hint);
# ifdef GL_POLYGON_SMOOTH_HINT
	BOOST_CHECK(x != ev.polygon_smooth_hint);
# endif
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
#endif

#ifdef GL_POLYGON_SMOOTH_HINT
	x = ev.polygon_smooth_hint;
	BOOST_CHECK(x == ev.polygon_smooth_hint);
# ifdef GL_TEXTURE_COMPRESSION_HINT
	BOOST_CHECK(x != ev.texture_compression_hint);
# endif
#endif

#ifdef GL_TEXTURE_COMPRESSION_HINT
	x = ev.texture_compression_hint;
	BOOST_CHECK(x == ev.texture_compression_hint);
#endif
}

BOOST_AUTO_TEST_CASE(enum_hint_target_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	hint_target x;
	(void)x;

#ifdef GL_FRAGMENT_SHADER_DERIVATIVE_HINT
	x = ev.fragment_shader_derivative_hint;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"FRAGMENT_SHADER_DERIVATIVE_HINT"
	) == 0);
#endif

#ifdef GL_LINE_SMOOTH_HINT
	x = ev.line_smooth_hint;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"LINE_SMOOTH_HINT"
	) == 0);
#endif

#ifdef GL_POLYGON_SMOOTH_HINT
	x = ev.polygon_smooth_hint;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"POLYGON_SMOOTH_HINT"
	) == 0);
#endif

#ifdef GL_TEXTURE_COMPRESSION_HINT
	x = ev.texture_compression_hint;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_COMPRESSION_HINT"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_hint_target_range)
{
	using namespace oglplus;
	auto count = enum_value_range<hint_target>().size();

#ifdef GL_FRAGMENT_SHADER_DERIVATIVE_HINT
{
	--count;
	auto r = enum_value_range<hint_target>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		hint_target(GL_FRAGMENT_SHADER_DERIVATIVE_HINT)
	) != r.end());
}
#endif

#ifdef GL_LINE_SMOOTH_HINT
{
	--count;
	auto r = enum_value_range<hint_target>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		hint_target(GL_LINE_SMOOTH_HINT)
	) != r.end());
}
#endif

#ifdef GL_POLYGON_SMOOTH_HINT
{
	--count;
	auto r = enum_value_range<hint_target>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		hint_target(GL_POLYGON_SMOOTH_HINT)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_COMPRESSION_HINT
{
	--count;
	auto r = enum_value_range<hint_target>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		hint_target(GL_TEXTURE_COMPRESSION_HINT)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_hint_target_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	hint_target x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_FRAGMENT_SHADER_DERIVATIVE_HINT
	x = ev.fragment_shader_derivative_hint;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.fragment_shader_derivative_hint);
#endif

#ifdef GL_LINE_SMOOTH_HINT
	x = ev.line_smooth_hint;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.line_smooth_hint);
#endif

#ifdef GL_POLYGON_SMOOTH_HINT
	x = ev.polygon_smooth_hint;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.polygon_smooth_hint);
#endif

#ifdef GL_TEXTURE_COMPRESSION_HINT
	x = ev.texture_compression_hint;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_compression_hint);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
