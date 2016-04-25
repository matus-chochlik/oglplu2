//  File test/oglplus/enums/provoke_mode.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_provoke_mode

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_provoke_mode_tests)

BOOST_AUTO_TEST_CASE(enum_provoke_mode_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	provoke_mode x;
	(void)x;

#ifdef GL_FIRST_VERTEX_CONVENTION
	x = ev.first_vertex_convention;
	BOOST_CHECK(x == ev.first_vertex_convention);
# ifdef GL_LAST_VERTEX_CONVENTION
	BOOST_CHECK(x != ev.last_vertex_convention);
# endif
#endif

#ifdef GL_LAST_VERTEX_CONVENTION
	x = ev.last_vertex_convention;
	BOOST_CHECK(x == ev.last_vertex_convention);
#endif
}

BOOST_AUTO_TEST_CASE(enum_provoke_mode_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	provoke_mode x;
	(void)x;

#ifdef GL_FIRST_VERTEX_CONVENTION
	x = ev.first_vertex_convention;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"FIRST_VERTEX_CONVENTION"
	) == 0);
#endif

#ifdef GL_LAST_VERTEX_CONVENTION
	x = ev.last_vertex_convention;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"LAST_VERTEX_CONVENTION"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_provoke_mode_range)
{
	using namespace oglplus;
	auto count = enum_value_range<provoke_mode>().size();

#ifdef GL_FIRST_VERTEX_CONVENTION
{
	--count;
	auto r = enum_value_range<provoke_mode>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		provoke_mode(GL_FIRST_VERTEX_CONVENTION)
	) != r.end());
}
#endif

#ifdef GL_LAST_VERTEX_CONVENTION
{
	--count;
	auto r = enum_value_range<provoke_mode>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		provoke_mode(GL_LAST_VERTEX_CONVENTION)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_provoke_mode_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	provoke_mode x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_FIRST_VERTEX_CONVENTION
	x = ev.first_vertex_convention;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.first_vertex_convention);
#endif

#ifdef GL_LAST_VERTEX_CONVENTION
	x = ev.last_vertex_convention;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.last_vertex_convention);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
