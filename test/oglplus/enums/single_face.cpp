//  File test/oglplus/enums/single_face.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_single_face

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_single_face)

BOOST_AUTO_TEST_CASE(enum_single_face_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	single_face x;
	(void)x;

#ifdef GL_BACK
	x = ev.back;
	BOOST_CHECK(x == ev.back);
# ifdef GL_FRONT
	BOOST_CHECK(x != ev.front);
# endif
#endif

#ifdef GL_FRONT
	x = ev.front;
# ifdef GL_BACK
	BOOST_CHECK(x != ev.back);
# endif
	BOOST_CHECK(x == ev.front);
#endif
}

BOOST_AUTO_TEST_CASE(enum_single_face_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	single_face x;
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
}

BOOST_AUTO_TEST_SUITE_END()
