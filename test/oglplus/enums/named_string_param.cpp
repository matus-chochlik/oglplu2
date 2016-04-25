//  File test/oglplus/enums/named_string_param.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_named_string_param

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_named_string_param_tests)

BOOST_AUTO_TEST_CASE(enum_named_string_param_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	named_string_param x;
	(void)x;

#ifdef GL_NAMED_STRING_LENGTH_ARB
	x = ev.named_string_length;
	BOOST_CHECK(x == ev.named_string_length);
# ifdef GL_NAMED_STRING_TYPE_ARB
	BOOST_CHECK(x != ev.named_string_type);
# endif
#endif

#ifdef GL_NAMED_STRING_TYPE_ARB
	x = ev.named_string_type;
	BOOST_CHECK(x == ev.named_string_type);
#endif
}

BOOST_AUTO_TEST_CASE(enum_named_string_param_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	named_string_param x;
	(void)x;

#ifdef GL_NAMED_STRING_LENGTH_ARB
	x = ev.named_string_length;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"NAMED_STRING_LENGTH_ARB"
	) == 0);
#endif

#ifdef GL_NAMED_STRING_TYPE_ARB
	x = ev.named_string_type;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"NAMED_STRING_TYPE_ARB"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_named_string_param_range)
{
	using namespace oglplus;
	auto count = enum_value_range<named_string_param>().size();

#ifdef GL_NAMED_STRING_LENGTH_ARB
{
	--count;
	auto r = enum_value_range<named_string_param>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		named_string_param(GL_NAMED_STRING_LENGTH_ARB)
	) != r.end());
}
#endif

#ifdef GL_NAMED_STRING_TYPE_ARB
{
	--count;
	auto r = enum_value_range<named_string_param>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		named_string_param(GL_NAMED_STRING_TYPE_ARB)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_named_string_param_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	named_string_param x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_NAMED_STRING_LENGTH_ARB
	x = ev.named_string_length;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.named_string_length);
#endif

#ifdef GL_NAMED_STRING_TYPE_ARB
	x = ev.named_string_type;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.named_string_type);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
