//  File test/oglplus/enums/hint_option.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_hint_option

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_hint_option_tests)

BOOST_AUTO_TEST_CASE(enum_hint_option_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	hint_option x;
	(void)x;

#ifdef GL_DONT_CARE
	x = ev.dont_care;
	BOOST_CHECK(x == ev.dont_care);
# ifdef GL_FASTEST
	BOOST_CHECK(x != ev.fastest);
# endif
# ifdef GL_NICEST
	BOOST_CHECK(x != ev.nicest);
# endif
#endif

#ifdef GL_FASTEST
	x = ev.fastest;
	BOOST_CHECK(x == ev.fastest);
# ifdef GL_NICEST
	BOOST_CHECK(x != ev.nicest);
# endif
#endif

#ifdef GL_NICEST
	x = ev.nicest;
	BOOST_CHECK(x == ev.nicest);
#endif
}

BOOST_AUTO_TEST_CASE(enum_hint_option_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	hint_option x;
	(void)x;

#ifdef GL_DONT_CARE
	x = ev.dont_care;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DONT_CARE"
	) == 0);
#endif

#ifdef GL_FASTEST
	x = ev.fastest;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"FASTEST"
	) == 0);
#endif

#ifdef GL_NICEST
	x = ev.nicest;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"NICEST"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_hint_option_range)
{
	using namespace oglplus;
	auto count = enum_value_range<hint_option>().size();

#ifdef GL_DONT_CARE
{
	--count;
	auto r = enum_value_range<hint_option>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		hint_option(GL_DONT_CARE)
	) != r.end());
}
#endif

#ifdef GL_FASTEST
{
	--count;
	auto r = enum_value_range<hint_option>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		hint_option(GL_FASTEST)
	) != r.end());
}
#endif

#ifdef GL_NICEST
{
	--count;
	auto r = enum_value_range<hint_option>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		hint_option(GL_NICEST)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_hint_option_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	hint_option x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_DONT_CARE
	x = ev.dont_care;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.dont_care);
#endif

#ifdef GL_FASTEST
	x = ev.fastest;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.fastest);
#endif

#ifdef GL_NICEST
	x = ev.nicest;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.nicest);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
