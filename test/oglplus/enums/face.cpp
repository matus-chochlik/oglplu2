//  File test/oglplus/enums/face.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_face

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_face)

BOOST_AUTO_TEST_CASE(enum_face_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	face x;
	(void)x;

#ifdef GL_BACK
	x = ev.back;
	BOOST_CHECK(x == ev.back);
# ifdef GL_FRONT
	BOOST_CHECK(x != ev.front);
# endif
# ifdef GL_FRONT_AND_BACK
	BOOST_CHECK(x != ev.front_and_back);
# endif
#endif

#ifdef GL_FRONT
	x = ev.front;
# ifdef GL_BACK
	BOOST_CHECK(x != ev.back);
# endif
	BOOST_CHECK(x == ev.front);
# ifdef GL_FRONT_AND_BACK
	BOOST_CHECK(x != ev.front_and_back);
# endif
#endif

#ifdef GL_FRONT_AND_BACK
	x = ev.front_and_back;
# ifdef GL_BACK
	BOOST_CHECK(x != ev.back);
# endif
# ifdef GL_FRONT
	BOOST_CHECK(x != ev.front);
# endif
	BOOST_CHECK(x == ev.front_and_back);
#endif
}

BOOST_AUTO_TEST_CASE(enum_face_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	face x;
	(void)x;

#ifdef GL_BACK
	x = ev.back;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"BACK"
	) == 0);
#endif

#ifdef GL_FRONT
	x = ev.front;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"FRONT"
	) == 0);
#endif

#ifdef GL_FRONT_AND_BACK
	x = ev.front_and_back;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"FRONT_AND_BACK"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_face_range)
{
	using namespace oglplus;
	face x;
	(void)x;
	auto count = enum_value_range(x).size();

#ifdef GL_BACK
{
	--count;
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_BACK
	) != r.end());
}
#endif

#ifdef GL_FRONT
{
	--count;
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_FRONT
	) != r.end());
}
#endif

#ifdef GL_FRONT_AND_BACK
{
	--count;
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_FRONT_AND_BACK
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_SUITE_END()
