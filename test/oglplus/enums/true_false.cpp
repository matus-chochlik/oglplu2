//  File test/oglplus/enums/true_false.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_true_false

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_true_false_tests)

BOOST_AUTO_TEST_CASE(enum_true_false_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	true_false x;
	(void)x;

#ifdef GL_FALSE
	x = ev.false_;
	BOOST_CHECK(x == ev.false_);
# ifdef GL_TRUE
	BOOST_CHECK(x != ev.true_);
# endif
#endif

#ifdef GL_TRUE
	x = ev.true_;
	BOOST_CHECK(x == ev.true_);
#endif
}

BOOST_AUTO_TEST_CASE(enum_true_false_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	true_false x;
	(void)x;

#ifdef GL_FALSE
	x = ev.false_;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"FALSE"
	) == 0);
#endif

#ifdef GL_TRUE
	x = ev.true_;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TRUE"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_true_false_range)
{
	using namespace oglplus;
	auto count = enum_value_range<true_false>().size();

#ifdef GL_FALSE
{
	--count;
	auto r = enum_value_range<true_false>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		true_false(GL_FALSE)
	) != r.end());
}
#endif

#ifdef GL_TRUE
{
	--count;
	auto r = enum_value_range<true_false>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		true_false(GL_TRUE)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_true_false_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	true_false x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_FALSE
	x = ev.false_;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.false_);
#endif

#ifdef GL_TRUE
	x = ev.true_;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.true_);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
