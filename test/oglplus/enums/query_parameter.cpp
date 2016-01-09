//  File test/oglplus/enums/query_parameter.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_query_parameter

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_query_parameter_tests)

BOOST_AUTO_TEST_CASE(enum_query_parameter_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	query_parameter x;
	(void)x;

#ifdef GL_QUERY_RESULT
	x = ev.query_result;
	BOOST_CHECK(x == ev.query_result);
# ifdef GL_QUERY_RESULT_AVAILABLE
	BOOST_CHECK(x != ev.query_result_available);
# endif
#endif

#ifdef GL_QUERY_RESULT_AVAILABLE
	x = ev.query_result_available;
	BOOST_CHECK(x == ev.query_result_available);
#endif
}

BOOST_AUTO_TEST_CASE(enum_query_parameter_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	query_parameter x;
	(void)x;

#ifdef GL_QUERY_RESULT
	x = ev.query_result;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"QUERY_RESULT"
	) == 0);
#endif

#ifdef GL_QUERY_RESULT_AVAILABLE
	x = ev.query_result_available;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"QUERY_RESULT_AVAILABLE"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_query_parameter_range)
{
	using namespace oglplus;
	auto count = enum_value_range<query_parameter>().size();

#ifdef GL_QUERY_RESULT
{
	--count;
	auto r = enum_value_range<query_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		query_parameter(GL_QUERY_RESULT)
	) != r.end());
}
#endif

#ifdef GL_QUERY_RESULT_AVAILABLE
{
	--count;
	auto r = enum_value_range<query_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		query_parameter(GL_QUERY_RESULT_AVAILABLE)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_query_parameter_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	query_parameter x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_QUERY_RESULT
	x = ev.query_result;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.query_result);
#endif

#ifdef GL_QUERY_RESULT_AVAILABLE
	x = ev.query_result_available;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.query_result_available);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
