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

BOOST_AUTO_TEST_SUITE(enum_index_type_tests)

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
	BOOST_CHECK(x == ev.unsigned_int);
# ifdef GL_UNSIGNED_SHORT
	BOOST_CHECK(x != ev.unsigned_short);
# endif
#endif

#ifdef GL_UNSIGNED_SHORT
	x = ev.unsigned_short;
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
	auto count = enum_value_range<index_type>().size();

#ifdef GL_UNSIGNED_BYTE
{
	--count;
	auto r = enum_value_range<index_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		index_type(GL_UNSIGNED_BYTE)
	) != r.end());
}
#endif

#ifdef GL_UNSIGNED_INT
{
	--count;
	auto r = enum_value_range<index_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		index_type(GL_UNSIGNED_INT)
	) != r.end());
}
#endif

#ifdef GL_UNSIGNED_SHORT
{
	--count;
	auto r = enum_value_range<index_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		index_type(GL_UNSIGNED_SHORT)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_index_type_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	index_type x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_UNSIGNED_BYTE
	x = ev.unsigned_byte;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.unsigned_byte);
#endif

#ifdef GL_UNSIGNED_INT
	x = ev.unsigned_int;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.unsigned_int);
#endif

#ifdef GL_UNSIGNED_SHORT
	x = ev.unsigned_short;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.unsigned_short);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
