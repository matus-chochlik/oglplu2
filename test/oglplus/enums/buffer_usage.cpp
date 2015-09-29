//  File test/oglplus/enums/buffer_usage.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_buffer_usage

#include <boost/test/unit_test.hpp>
#include "common.hpp"

BOOST_AUTO_TEST_SUITE(enum_buffer_usage)

BOOST_AUTO_TEST_CASE(enum_buffer_usage_values)
{
	using namespace oglplus;
	enum_values ev;
	buffer_usage x;

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
# ifdef GL_DYNAMIC_COPY
	BOOST_CHECK(x != ev.dynamic_copy);
# endif
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
# ifdef GL_DYNAMIC_COPY
	BOOST_CHECK(x != ev.dynamic_copy);
# endif
# ifdef GL_DYNAMIC_DRAW
	BOOST_CHECK(x != ev.dynamic_draw);
# endif
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
# ifdef GL_DYNAMIC_COPY
	BOOST_CHECK(x != ev.dynamic_copy);
# endif
# ifdef GL_DYNAMIC_DRAW
	BOOST_CHECK(x != ev.dynamic_draw);
# endif
# ifdef GL_DYNAMIC_READ
	BOOST_CHECK(x != ev.dynamic_read);
# endif
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
# ifdef GL_DYNAMIC_COPY
	BOOST_CHECK(x != ev.dynamic_copy);
# endif
# ifdef GL_DYNAMIC_DRAW
	BOOST_CHECK(x != ev.dynamic_draw);
# endif
# ifdef GL_DYNAMIC_READ
	BOOST_CHECK(x != ev.dynamic_read);
# endif
# ifdef GL_STATIC_COPY
	BOOST_CHECK(x != ev.static_copy);
# endif
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
# ifdef GL_DYNAMIC_COPY
	BOOST_CHECK(x != ev.dynamic_copy);
# endif
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
# ifdef GL_DYNAMIC_COPY
	BOOST_CHECK(x != ev.dynamic_copy);
# endif
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
# ifdef GL_DYNAMIC_COPY
	BOOST_CHECK(x != ev.dynamic_copy);
# endif
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
	BOOST_CHECK(x == ev.stream_draw);
# ifdef GL_STREAM_READ
	BOOST_CHECK(x != ev.stream_read);
# endif
#endif

#ifdef GL_STREAM_READ
	x = ev.stream_read;
# ifdef GL_DYNAMIC_COPY
	BOOST_CHECK(x != ev.dynamic_copy);
# endif
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
	BOOST_CHECK(x == ev.stream_read);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
