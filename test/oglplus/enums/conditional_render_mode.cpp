//  File test/oglplus/enums/conditional_render_mode.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_conditional_render_mode

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_conditional_render_mode_tests)

BOOST_AUTO_TEST_CASE(enum_conditional_render_mode_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	conditional_render_mode x;
	(void)x;

#ifdef GL_QUERY_BY_REGION_NO_WAIT
	x = ev.query_by_region_no_wait;
	BOOST_CHECK(x == ev.query_by_region_no_wait);
# ifdef GL_QUERY_BY_REGION_NO_WAIT_INVERTED
	BOOST_CHECK(x != ev.query_by_region_no_wait_inverted);
# endif
# ifdef GL_QUERY_BY_REGION_WAIT
	BOOST_CHECK(x != ev.query_by_region_wait);
# endif
# ifdef GL_QUERY_BY_REGION_WAIT_INVERTED
	BOOST_CHECK(x != ev.query_by_region_wait_inverted);
# endif
# ifdef GL_QUERY_NO_WAIT
	BOOST_CHECK(x != ev.query_no_wait);
# endif
# ifdef GL_QUERY_NO_WAIT_INVERTED
	BOOST_CHECK(x != ev.query_no_wait_inverted);
# endif
# ifdef GL_QUERY_WAIT
	BOOST_CHECK(x != ev.query_wait);
# endif
# ifdef GL_QUERY_WAIT_INVERTED
	BOOST_CHECK(x != ev.query_wait_inverted);
# endif
#endif

#ifdef GL_QUERY_BY_REGION_NO_WAIT_INVERTED
	x = ev.query_by_region_no_wait_inverted;
	BOOST_CHECK(x == ev.query_by_region_no_wait_inverted);
# ifdef GL_QUERY_BY_REGION_WAIT
	BOOST_CHECK(x != ev.query_by_region_wait);
# endif
# ifdef GL_QUERY_BY_REGION_WAIT_INVERTED
	BOOST_CHECK(x != ev.query_by_region_wait_inverted);
# endif
# ifdef GL_QUERY_NO_WAIT
	BOOST_CHECK(x != ev.query_no_wait);
# endif
# ifdef GL_QUERY_NO_WAIT_INVERTED
	BOOST_CHECK(x != ev.query_no_wait_inverted);
# endif
# ifdef GL_QUERY_WAIT
	BOOST_CHECK(x != ev.query_wait);
# endif
# ifdef GL_QUERY_WAIT_INVERTED
	BOOST_CHECK(x != ev.query_wait_inverted);
# endif
#endif

#ifdef GL_QUERY_BY_REGION_WAIT
	x = ev.query_by_region_wait;
	BOOST_CHECK(x == ev.query_by_region_wait);
# ifdef GL_QUERY_BY_REGION_WAIT_INVERTED
	BOOST_CHECK(x != ev.query_by_region_wait_inverted);
# endif
# ifdef GL_QUERY_NO_WAIT
	BOOST_CHECK(x != ev.query_no_wait);
# endif
# ifdef GL_QUERY_NO_WAIT_INVERTED
	BOOST_CHECK(x != ev.query_no_wait_inverted);
# endif
# ifdef GL_QUERY_WAIT
	BOOST_CHECK(x != ev.query_wait);
# endif
# ifdef GL_QUERY_WAIT_INVERTED
	BOOST_CHECK(x != ev.query_wait_inverted);
# endif
#endif

#ifdef GL_QUERY_BY_REGION_WAIT_INVERTED
	x = ev.query_by_region_wait_inverted;
	BOOST_CHECK(x == ev.query_by_region_wait_inverted);
# ifdef GL_QUERY_NO_WAIT
	BOOST_CHECK(x != ev.query_no_wait);
# endif
# ifdef GL_QUERY_NO_WAIT_INVERTED
	BOOST_CHECK(x != ev.query_no_wait_inverted);
# endif
# ifdef GL_QUERY_WAIT
	BOOST_CHECK(x != ev.query_wait);
# endif
# ifdef GL_QUERY_WAIT_INVERTED
	BOOST_CHECK(x != ev.query_wait_inverted);
# endif
#endif

#ifdef GL_QUERY_NO_WAIT
	x = ev.query_no_wait;
	BOOST_CHECK(x == ev.query_no_wait);
# ifdef GL_QUERY_NO_WAIT_INVERTED
	BOOST_CHECK(x != ev.query_no_wait_inverted);
# endif
# ifdef GL_QUERY_WAIT
	BOOST_CHECK(x != ev.query_wait);
# endif
# ifdef GL_QUERY_WAIT_INVERTED
	BOOST_CHECK(x != ev.query_wait_inverted);
# endif
#endif

#ifdef GL_QUERY_NO_WAIT_INVERTED
	x = ev.query_no_wait_inverted;
	BOOST_CHECK(x == ev.query_no_wait_inverted);
# ifdef GL_QUERY_WAIT
	BOOST_CHECK(x != ev.query_wait);
# endif
# ifdef GL_QUERY_WAIT_INVERTED
	BOOST_CHECK(x != ev.query_wait_inverted);
# endif
#endif

#ifdef GL_QUERY_WAIT
	x = ev.query_wait;
	BOOST_CHECK(x == ev.query_wait);
# ifdef GL_QUERY_WAIT_INVERTED
	BOOST_CHECK(x != ev.query_wait_inverted);
# endif
#endif

#ifdef GL_QUERY_WAIT_INVERTED
	x = ev.query_wait_inverted;
	BOOST_CHECK(x == ev.query_wait_inverted);
#endif
}

BOOST_AUTO_TEST_CASE(enum_conditional_render_mode_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	conditional_render_mode x;
	(void)x;

#ifdef GL_QUERY_BY_REGION_NO_WAIT
	x = ev.query_by_region_no_wait;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"QUERY_BY_REGION_NO_WAIT"
	) == 0);
#endif

#ifdef GL_QUERY_BY_REGION_NO_WAIT_INVERTED
	x = ev.query_by_region_no_wait_inverted;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"QUERY_BY_REGION_NO_WAIT_INVERTED"
	) == 0);
#endif

#ifdef GL_QUERY_BY_REGION_WAIT
	x = ev.query_by_region_wait;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"QUERY_BY_REGION_WAIT"
	) == 0);
#endif

#ifdef GL_QUERY_BY_REGION_WAIT_INVERTED
	x = ev.query_by_region_wait_inverted;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"QUERY_BY_REGION_WAIT_INVERTED"
	) == 0);
#endif

#ifdef GL_QUERY_NO_WAIT
	x = ev.query_no_wait;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"QUERY_NO_WAIT"
	) == 0);
#endif

#ifdef GL_QUERY_NO_WAIT_INVERTED
	x = ev.query_no_wait_inverted;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"QUERY_NO_WAIT_INVERTED"
	) == 0);
#endif

#ifdef GL_QUERY_WAIT
	x = ev.query_wait;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"QUERY_WAIT"
	) == 0);
#endif

#ifdef GL_QUERY_WAIT_INVERTED
	x = ev.query_wait_inverted;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"QUERY_WAIT_INVERTED"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_conditional_render_mode_range)
{
	using namespace oglplus;
	auto count = enum_value_range<conditional_render_mode>().size();

#ifdef GL_QUERY_BY_REGION_NO_WAIT
{
	--count;
	auto r = enum_value_range<conditional_render_mode>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		conditional_render_mode(GL_QUERY_BY_REGION_NO_WAIT)
	) != r.end());
}
#endif

#ifdef GL_QUERY_BY_REGION_NO_WAIT_INVERTED
{
	--count;
	auto r = enum_value_range<conditional_render_mode>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		conditional_render_mode(GL_QUERY_BY_REGION_NO_WAIT_INVERTED)
	) != r.end());
}
#endif

#ifdef GL_QUERY_BY_REGION_WAIT
{
	--count;
	auto r = enum_value_range<conditional_render_mode>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		conditional_render_mode(GL_QUERY_BY_REGION_WAIT)
	) != r.end());
}
#endif

#ifdef GL_QUERY_BY_REGION_WAIT_INVERTED
{
	--count;
	auto r = enum_value_range<conditional_render_mode>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		conditional_render_mode(GL_QUERY_BY_REGION_WAIT_INVERTED)
	) != r.end());
}
#endif

#ifdef GL_QUERY_NO_WAIT
{
	--count;
	auto r = enum_value_range<conditional_render_mode>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		conditional_render_mode(GL_QUERY_NO_WAIT)
	) != r.end());
}
#endif

#ifdef GL_QUERY_NO_WAIT_INVERTED
{
	--count;
	auto r = enum_value_range<conditional_render_mode>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		conditional_render_mode(GL_QUERY_NO_WAIT_INVERTED)
	) != r.end());
}
#endif

#ifdef GL_QUERY_WAIT
{
	--count;
	auto r = enum_value_range<conditional_render_mode>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		conditional_render_mode(GL_QUERY_WAIT)
	) != r.end());
}
#endif

#ifdef GL_QUERY_WAIT_INVERTED
{
	--count;
	auto r = enum_value_range<conditional_render_mode>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		conditional_render_mode(GL_QUERY_WAIT_INVERTED)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_conditional_render_mode_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	conditional_render_mode x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_QUERY_BY_REGION_NO_WAIT
	x = ev.query_by_region_no_wait;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.query_by_region_no_wait);
#endif

#ifdef GL_QUERY_BY_REGION_NO_WAIT_INVERTED
	x = ev.query_by_region_no_wait_inverted;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.query_by_region_no_wait_inverted);
#endif

#ifdef GL_QUERY_BY_REGION_WAIT
	x = ev.query_by_region_wait;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.query_by_region_wait);
#endif

#ifdef GL_QUERY_BY_REGION_WAIT_INVERTED
	x = ev.query_by_region_wait_inverted;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.query_by_region_wait_inverted);
#endif

#ifdef GL_QUERY_NO_WAIT
	x = ev.query_no_wait;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.query_no_wait);
#endif

#ifdef GL_QUERY_NO_WAIT_INVERTED
	x = ev.query_no_wait_inverted;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.query_no_wait_inverted);
#endif

#ifdef GL_QUERY_WAIT
	x = ev.query_wait;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.query_wait);
#endif

#ifdef GL_QUERY_WAIT_INVERTED
	x = ev.query_wait_inverted;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.query_wait_inverted);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
