//  File test/oglplus/enums/indexed_value_base.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_indexed_value_base

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_indexed_value_base_tests)

BOOST_AUTO_TEST_CASE(enum_indexed_value_base_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	indexed_value_base x;
	(void)x;

#ifdef GL_CLIP_DISTANCE0
	x = ev.clip_distance0;
	BOOST_CHECK(x == ev.clip_distance0);
# ifdef GL_COLOR_ATTACHMENT0
	BOOST_CHECK(x != ev.color_attachment0);
# endif
# ifdef GL_DRAW_BUFFER0
	BOOST_CHECK(x != ev.draw_buffer0);
# endif
# ifdef GL_TEXTURE0
	BOOST_CHECK(x != ev.texture0);
# endif
#endif

#ifdef GL_COLOR_ATTACHMENT0
	x = ev.color_attachment0;
	BOOST_CHECK(x == ev.color_attachment0);
# ifdef GL_DRAW_BUFFER0
	BOOST_CHECK(x != ev.draw_buffer0);
# endif
# ifdef GL_TEXTURE0
	BOOST_CHECK(x != ev.texture0);
# endif
#endif

#ifdef GL_DRAW_BUFFER0
	x = ev.draw_buffer0;
	BOOST_CHECK(x == ev.draw_buffer0);
# ifdef GL_TEXTURE0
	BOOST_CHECK(x != ev.texture0);
# endif
#endif

#ifdef GL_TEXTURE0
	x = ev.texture0;
	BOOST_CHECK(x == ev.texture0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_indexed_value_base_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	indexed_value_base x;
	(void)x;

#ifdef GL_CLIP_DISTANCE0
	x = ev.clip_distance0;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"CLIP_DISTANCE0"
	) == 0);
#endif

#ifdef GL_COLOR_ATTACHMENT0
	x = ev.color_attachment0;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"COLOR_ATTACHMENT0"
	) == 0);
#endif

#ifdef GL_DRAW_BUFFER0
	x = ev.draw_buffer0;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DRAW_BUFFER0"
	) == 0);
#endif

#ifdef GL_TEXTURE0
	x = ev.texture0;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE0"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_indexed_value_base_range)
{
	using namespace oglplus;
	auto count = enum_value_range<indexed_value_base>().size();

#ifdef GL_CLIP_DISTANCE0
{
	--count;
	auto r = enum_value_range<indexed_value_base>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		indexed_value_base(GL_CLIP_DISTANCE0)
	) != r.end());
}
#endif

#ifdef GL_COLOR_ATTACHMENT0
{
	--count;
	auto r = enum_value_range<indexed_value_base>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		indexed_value_base(GL_COLOR_ATTACHMENT0)
	) != r.end());
}
#endif

#ifdef GL_DRAW_BUFFER0
{
	--count;
	auto r = enum_value_range<indexed_value_base>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		indexed_value_base(GL_DRAW_BUFFER0)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE0
{
	--count;
	auto r = enum_value_range<indexed_value_base>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		indexed_value_base(GL_TEXTURE0)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_indexed_value_base_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	indexed_value_base x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_CLIP_DISTANCE0
	x = ev.clip_distance0;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.clip_distance0);
#endif

#ifdef GL_COLOR_ATTACHMENT0
	x = ev.color_attachment0;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.color_attachment0);
#endif

#ifdef GL_DRAW_BUFFER0
	x = ev.draw_buffer0;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.draw_buffer0);
#endif

#ifdef GL_TEXTURE0
	x = ev.texture0;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture0);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
