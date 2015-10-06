//  File test/oglplus/enums/index_type.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_index_type

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_index_type)

BOOST_AUTO_TEST_CASE(enum_index_type_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	index_type x;
	(void)x;

#ifdef GL_UNSIGNED_BYTE
	x = ev.unsigned_byte;
	BOOST_CHECK(x == ev.unsigned_byte);
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_SHORT
	BOOST_CHECK(x != ev.unsigned_short);
# endif
#endif

#ifdef GL_UNSIGNED_INT
	x = ev.unsigned_int;
# ifdef GL_UNSIGNED_BYTE
	BOOST_CHECK(x != ev.unsigned_byte);
# endif
	BOOST_CHECK(x == ev.unsigned_int);
# ifdef GL_UNSIGNED_SHORT
	BOOST_CHECK(x != ev.unsigned_short);
# endif
#endif

#ifdef GL_UNSIGNED_SHORT
	x = ev.unsigned_short;
# ifdef GL_UNSIGNED_BYTE
	BOOST_CHECK(x != ev.unsigned_byte);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
	BOOST_CHECK(x == ev.unsigned_short);
#endif
}

BOOST_AUTO_TEST_CASE(enum_index_type_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	index_type x;
	(void)x;

#ifdef GL_UNSIGNED_BYTE
	x = ev.unsigned_byte;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"UNSIGNED_BYTE"
	) == 0);
#endif

#ifdef GL_UNSIGNED_INT
	x = ev.unsigned_int;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"UNSIGNED_INT"
	) == 0);
#endif

#ifdef GL_UNSIGNED_SHORT
	x = ev.unsigned_short;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"UNSIGNED_SHORT"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_index_type_range)
{
	using namespace oglplus;
	index_type x;
	(void)x;
	auto count = enum_value_range(x).size();

#ifdef GL_UNSIGNED_BYTE
{
	--count;
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_UNSIGNED_BYTE
	) != r.end());
}
#endif

#ifdef GL_UNSIGNED_INT
{
	--count;
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_UNSIGNED_INT
	) != r.end());
}
#endif

#ifdef GL_UNSIGNED_SHORT
{
	--count;
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_UNSIGNED_SHORT
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_SUITE_END()
