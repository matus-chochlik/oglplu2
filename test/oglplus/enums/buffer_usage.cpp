//  File test/oglplus/enums/buffer_usage.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_buffer_usage

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_buffer_usage_tests)

BOOST_AUTO_TEST_CASE(enum_buffer_usage_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	buffer_usage x;
	(void)x;

#ifdef GL_DYNAMIC_COPY
	x = ev.dynamic_copy;
	BOOST_CHECK(x == ev.dynamic_copy);
# ifdef GL_DYNAMIC_DRAW
	BOOST_CHECK(x != ev.dynamic_draw);
# endif
# ifdef GL_DYNAMIC_READ
	BOOST_CHECK(x != ev.dynamic_read);
# endif
# ifdef GL_STATIC_COPY
	BOOST_CHECK(x != ev.static_copy);
# endif
# ifdef GL_STATIC_DRAW
	BOOST_CHECK(x != ev.static_draw);
# endif
# ifdef GL_STATIC_READ
	BOOST_CHECK(x != ev.static_read);
# endif
# ifdef GL_STREAM_COPY
	BOOST_CHECK(x != ev.stream_copy);
# endif
# ifdef GL_STREAM_DRAW
	BOOST_CHECK(x != ev.stream_draw);
# endif
# ifdef GL_STREAM_READ
	BOOST_CHECK(x != ev.stream_read);
# endif
#endif

#ifdef GL_DYNAMIC_DRAW
	x = ev.dynamic_draw;
	BOOST_CHECK(x == ev.dynamic_draw);
# ifdef GL_DYNAMIC_READ
	BOOST_CHECK(x != ev.dynamic_read);
# endif
# ifdef GL_STATIC_COPY
	BOOST_CHECK(x != ev.static_copy);
# endif
# ifdef GL_STATIC_DRAW
	BOOST_CHECK(x != ev.static_draw);
# endif
# ifdef GL_STATIC_READ
	BOOST_CHECK(x != ev.static_read);
# endif
# ifdef GL_STREAM_COPY
	BOOST_CHECK(x != ev.stream_copy);
# endif
# ifdef GL_STREAM_DRAW
	BOOST_CHECK(x != ev.stream_draw);
# endif
# ifdef GL_STREAM_READ
	BOOST_CHECK(x != ev.stream_read);
# endif
#endif

#ifdef GL_DYNAMIC_READ
	x = ev.dynamic_read;
	BOOST_CHECK(x == ev.dynamic_read);
# ifdef GL_STATIC_COPY
	BOOST_CHECK(x != ev.static_copy);
# endif
# ifdef GL_STATIC_DRAW
	BOOST_CHECK(x != ev.static_draw);
# endif
# ifdef GL_STATIC_READ
	BOOST_CHECK(x != ev.static_read);
# endif
# ifdef GL_STREAM_COPY
	BOOST_CHECK(x != ev.stream_copy);
# endif
# ifdef GL_STREAM_DRAW
	BOOST_CHECK(x != ev.stream_draw);
# endif
# ifdef GL_STREAM_READ
	BOOST_CHECK(x != ev.stream_read);
# endif
#endif

#ifdef GL_STATIC_COPY
	x = ev.static_copy;
	BOOST_CHECK(x == ev.static_copy);
# ifdef GL_STATIC_DRAW
	BOOST_CHECK(x != ev.static_draw);
# endif
# ifdef GL_STATIC_READ
	BOOST_CHECK(x != ev.static_read);
# endif
# ifdef GL_STREAM_COPY
	BOOST_CHECK(x != ev.stream_copy);
# endif
# ifdef GL_STREAM_DRAW
	BOOST_CHECK(x != ev.stream_draw);
# endif
# ifdef GL_STREAM_READ
	BOOST_CHECK(x != ev.stream_read);
# endif
#endif

#ifdef GL_STATIC_DRAW
	x = ev.static_draw;
	BOOST_CHECK(x == ev.static_draw);
# ifdef GL_STATIC_READ
	BOOST_CHECK(x != ev.static_read);
# endif
# ifdef GL_STREAM_COPY
	BOOST_CHECK(x != ev.stream_copy);
# endif
# ifdef GL_STREAM_DRAW
	BOOST_CHECK(x != ev.stream_draw);
# endif
# ifdef GL_STREAM_READ
	BOOST_CHECK(x != ev.stream_read);
# endif
#endif

#ifdef GL_STATIC_READ
	x = ev.static_read;
	BOOST_CHECK(x == ev.static_read);
# ifdef GL_STREAM_COPY
	BOOST_CHECK(x != ev.stream_copy);
# endif
# ifdef GL_STREAM_DRAW
	BOOST_CHECK(x != ev.stream_draw);
# endif
# ifdef GL_STREAM_READ
	BOOST_CHECK(x != ev.stream_read);
# endif
#endif

#ifdef GL_STREAM_COPY
	x = ev.stream_copy;
	BOOST_CHECK(x == ev.stream_copy);
# ifdef GL_STREAM_DRAW
	BOOST_CHECK(x != ev.stream_draw);
# endif
# ifdef GL_STREAM_READ
	BOOST_CHECK(x != ev.stream_read);
# endif
#endif

#ifdef GL_STREAM_DRAW
	x = ev.stream_draw;
	BOOST_CHECK(x == ev.stream_draw);
# ifdef GL_STREAM_READ
	BOOST_CHECK(x != ev.stream_read);
# endif
#endif

#ifdef GL_STREAM_READ
	x = ev.stream_read;
	BOOST_CHECK(x == ev.stream_read);
#endif
}

BOOST_AUTO_TEST_CASE(enum_buffer_usage_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	buffer_usage x;
	(void)x;

#ifdef GL_DYNAMIC_COPY
	x = ev.dynamic_copy;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DYNAMIC_COPY"
	) == 0);
#endif

#ifdef GL_DYNAMIC_DRAW
	x = ev.dynamic_draw;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DYNAMIC_DRAW"
	) == 0);
#endif

#ifdef GL_DYNAMIC_READ
	x = ev.dynamic_read;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DYNAMIC_READ"
	) == 0);
#endif

#ifdef GL_STATIC_COPY
	x = ev.static_copy;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"STATIC_COPY"
	) == 0);
#endif

#ifdef GL_STATIC_DRAW
	x = ev.static_draw;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"STATIC_DRAW"
	) == 0);
#endif

#ifdef GL_STATIC_READ
	x = ev.static_read;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"STATIC_READ"
	) == 0);
#endif

#ifdef GL_STREAM_COPY
	x = ev.stream_copy;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"STREAM_COPY"
	) == 0);
#endif

#ifdef GL_STREAM_DRAW
	x = ev.stream_draw;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"STREAM_DRAW"
	) == 0);
#endif

#ifdef GL_STREAM_READ
	x = ev.stream_read;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"STREAM_READ"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_buffer_usage_range)
{
	using namespace oglplus;
	auto count = enum_value_range<buffer_usage>().size();

#ifdef GL_DYNAMIC_COPY
{
	--count;
	auto r = enum_value_range<buffer_usage>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		buffer_usage(GL_DYNAMIC_COPY)
	) != r.end());
}
#endif

#ifdef GL_DYNAMIC_DRAW
{
	--count;
	auto r = enum_value_range<buffer_usage>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		buffer_usage(GL_DYNAMIC_DRAW)
	) != r.end());
}
#endif

#ifdef GL_DYNAMIC_READ
{
	--count;
	auto r = enum_value_range<buffer_usage>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		buffer_usage(GL_DYNAMIC_READ)
	) != r.end());
}
#endif

#ifdef GL_STATIC_COPY
{
	--count;
	auto r = enum_value_range<buffer_usage>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		buffer_usage(GL_STATIC_COPY)
	) != r.end());
}
#endif

#ifdef GL_STATIC_DRAW
{
	--count;
	auto r = enum_value_range<buffer_usage>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		buffer_usage(GL_STATIC_DRAW)
	) != r.end());
}
#endif

#ifdef GL_STATIC_READ
{
	--count;
	auto r = enum_value_range<buffer_usage>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		buffer_usage(GL_STATIC_READ)
	) != r.end());
}
#endif

#ifdef GL_STREAM_COPY
{
	--count;
	auto r = enum_value_range<buffer_usage>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		buffer_usage(GL_STREAM_COPY)
	) != r.end());
}
#endif

#ifdef GL_STREAM_DRAW
{
	--count;
	auto r = enum_value_range<buffer_usage>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		buffer_usage(GL_STREAM_DRAW)
	) != r.end());
}
#endif

#ifdef GL_STREAM_READ
{
	--count;
	auto r = enum_value_range<buffer_usage>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		buffer_usage(GL_STREAM_READ)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_buffer_usage_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	buffer_usage x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_DYNAMIC_COPY
	x = ev.dynamic_copy;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.dynamic_copy);
#endif

#ifdef GL_DYNAMIC_DRAW
	x = ev.dynamic_draw;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.dynamic_draw);
#endif

#ifdef GL_DYNAMIC_READ
	x = ev.dynamic_read;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.dynamic_read);
#endif

#ifdef GL_STATIC_COPY
	x = ev.static_copy;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.static_copy);
#endif

#ifdef GL_STATIC_DRAW
	x = ev.static_draw;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.static_draw);
#endif

#ifdef GL_STATIC_READ
	x = ev.static_read;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.static_read);
#endif

#ifdef GL_STREAM_COPY
	x = ev.stream_copy;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.stream_copy);
#endif

#ifdef GL_STREAM_DRAW
	x = ev.stream_draw;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.stream_draw);
#endif

#ifdef GL_STREAM_READ
	x = ev.stream_read;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.stream_read);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
