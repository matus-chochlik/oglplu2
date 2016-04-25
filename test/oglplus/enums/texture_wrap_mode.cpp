//  File test/oglplus/enums/texture_wrap_mode.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_texture_wrap_mode

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_texture_wrap_mode_tests)

BOOST_AUTO_TEST_CASE(enum_texture_wrap_mode_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	texture_wrap_mode x;
	(void)x;

#ifdef GL_CLAMP_TO_BORDER
	x = ev.clamp_to_border;
	BOOST_CHECK(x == ev.clamp_to_border);
# ifdef GL_CLAMP_TO_EDGE
	BOOST_CHECK(x != ev.clamp_to_edge);
# endif
# ifdef GL_MIRROR_CLAMP_TO_EDGE
	BOOST_CHECK(x != ev.mirror_clamp_to_edge);
# endif
# ifdef GL_MIRRORED_REPEAT
	BOOST_CHECK(x != ev.mirrored_repeat);
# endif
# ifdef GL_REPEAT
	BOOST_CHECK(x != ev.repeat);
# endif
#endif

#ifdef GL_CLAMP_TO_EDGE
	x = ev.clamp_to_edge;
	BOOST_CHECK(x == ev.clamp_to_edge);
# ifdef GL_MIRROR_CLAMP_TO_EDGE
	BOOST_CHECK(x != ev.mirror_clamp_to_edge);
# endif
# ifdef GL_MIRRORED_REPEAT
	BOOST_CHECK(x != ev.mirrored_repeat);
# endif
# ifdef GL_REPEAT
	BOOST_CHECK(x != ev.repeat);
# endif
#endif

#ifdef GL_MIRROR_CLAMP_TO_EDGE
	x = ev.mirror_clamp_to_edge;
	BOOST_CHECK(x == ev.mirror_clamp_to_edge);
# ifdef GL_MIRRORED_REPEAT
	BOOST_CHECK(x != ev.mirrored_repeat);
# endif
# ifdef GL_REPEAT
	BOOST_CHECK(x != ev.repeat);
# endif
#endif

#ifdef GL_MIRRORED_REPEAT
	x = ev.mirrored_repeat;
	BOOST_CHECK(x == ev.mirrored_repeat);
# ifdef GL_REPEAT
	BOOST_CHECK(x != ev.repeat);
# endif
#endif

#ifdef GL_REPEAT
	x = ev.repeat;
	BOOST_CHECK(x == ev.repeat);
#endif
}

BOOST_AUTO_TEST_CASE(enum_texture_wrap_mode_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	texture_wrap_mode x;
	(void)x;

#ifdef GL_CLAMP_TO_BORDER
	x = ev.clamp_to_border;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"CLAMP_TO_BORDER"
	) == 0);
#endif

#ifdef GL_CLAMP_TO_EDGE
	x = ev.clamp_to_edge;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"CLAMP_TO_EDGE"
	) == 0);
#endif

#ifdef GL_MIRROR_CLAMP_TO_EDGE
	x = ev.mirror_clamp_to_edge;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MIRROR_CLAMP_TO_EDGE"
	) == 0);
#endif

#ifdef GL_MIRRORED_REPEAT
	x = ev.mirrored_repeat;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MIRRORED_REPEAT"
	) == 0);
#endif

#ifdef GL_REPEAT
	x = ev.repeat;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"REPEAT"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_texture_wrap_mode_range)
{
	using namespace oglplus;
	auto count = enum_value_range<texture_wrap_mode>().size();

#ifdef GL_CLAMP_TO_BORDER
{
	--count;
	auto r = enum_value_range<texture_wrap_mode>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		texture_wrap_mode(GL_CLAMP_TO_BORDER)
	) != r.end());
}
#endif

#ifdef GL_CLAMP_TO_EDGE
{
	--count;
	auto r = enum_value_range<texture_wrap_mode>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		texture_wrap_mode(GL_CLAMP_TO_EDGE)
	) != r.end());
}
#endif

#ifdef GL_MIRROR_CLAMP_TO_EDGE
{
	--count;
	auto r = enum_value_range<texture_wrap_mode>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		texture_wrap_mode(GL_MIRROR_CLAMP_TO_EDGE)
	) != r.end());
}
#endif

#ifdef GL_MIRRORED_REPEAT
{
	--count;
	auto r = enum_value_range<texture_wrap_mode>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		texture_wrap_mode(GL_MIRRORED_REPEAT)
	) != r.end());
}
#endif

#ifdef GL_REPEAT
{
	--count;
	auto r = enum_value_range<texture_wrap_mode>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		texture_wrap_mode(GL_REPEAT)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_texture_wrap_mode_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	texture_wrap_mode x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_CLAMP_TO_BORDER
	x = ev.clamp_to_border;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.clamp_to_border);
#endif

#ifdef GL_CLAMP_TO_EDGE
	x = ev.clamp_to_edge;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.clamp_to_edge);
#endif

#ifdef GL_MIRROR_CLAMP_TO_EDGE
	x = ev.mirror_clamp_to_edge;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.mirror_clamp_to_edge);
#endif

#ifdef GL_MIRRORED_REPEAT
	x = ev.mirrored_repeat;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.mirrored_repeat);
#endif

#ifdef GL_REPEAT
	x = ev.repeat;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.repeat);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
