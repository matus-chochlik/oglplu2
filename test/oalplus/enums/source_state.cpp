//  File test/oalplus/enums/source_state.cpp
//
//  Automatically generated file, DO NOT modify manually.
//  Edit the enumeration source files in 'source/enums/oalplus'
//  or the 'source/enums/make_enum.py' script instead.
//
//  Copyright Matus Chochlik.
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//   http://www.boost.org/LICENSE_1_0.txt
//
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE OALPLUS_source_state

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_source_state_tests)

BOOST_AUTO_TEST_CASE(enum_source_state_values)
{
	using namespace oalplus;
	enum_values ev;
	(void)ev;
	source_state x;
	(void)x;

#ifdef AL_INITIAL
	x = ev.initial;
	BOOST_CHECK(x == ev.initial);
# ifdef AL_PAUSED
	BOOST_CHECK(x != ev.paused);
# endif
# ifdef AL_PLAYING
	BOOST_CHECK(x != ev.playing);
# endif
# ifdef AL_STOPPED
	BOOST_CHECK(x != ev.stopped);
# endif
#endif

#ifdef AL_PAUSED
	x = ev.paused;
	BOOST_CHECK(x == ev.paused);
# ifdef AL_PLAYING
	BOOST_CHECK(x != ev.playing);
# endif
# ifdef AL_STOPPED
	BOOST_CHECK(x != ev.stopped);
# endif
#endif

#ifdef AL_PLAYING
	x = ev.playing;
	BOOST_CHECK(x == ev.playing);
# ifdef AL_STOPPED
	BOOST_CHECK(x != ev.stopped);
# endif
#endif

#ifdef AL_STOPPED
	x = ev.stopped;
	BOOST_CHECK(x == ev.stopped);
#endif
}

BOOST_AUTO_TEST_CASE(enum_source_state_names)
{
	using namespace oalplus;
	enum_values ev;
	(void)ev;
	source_state x;
	(void)x;

#ifdef AL_INITIAL
	x = ev.initial;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"INITIAL"
	) == 0);
#endif

#ifdef AL_PAUSED
	x = ev.paused;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PAUSED"
	) == 0);
#endif

#ifdef AL_PLAYING
	x = ev.playing;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PLAYING"
	) == 0);
#endif

#ifdef AL_STOPPED
	x = ev.stopped;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"STOPPED"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_source_state_range)
{
	using namespace oalplus;
	auto count = enum_value_range<source_state>().size();

#ifdef AL_INITIAL
{
	--count;
	auto r = enum_value_range<source_state>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		source_state(AL_INITIAL)
	) != r.end());
}
#endif

#ifdef AL_PAUSED
{
	--count;
	auto r = enum_value_range<source_state>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		source_state(AL_PAUSED)
	) != r.end());
}
#endif

#ifdef AL_PLAYING
{
	--count;
	auto r = enum_value_range<source_state>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		source_state(AL_PLAYING)
	) != r.end());
}
#endif

#ifdef AL_STOPPED
{
	--count;
	auto r = enum_value_range<source_state>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		source_state(AL_STOPPED)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_source_state_any)
{
	using namespace oalplus;
	enum_values ev;
	(void)ev;
	source_state x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef AL_INITIAL
	x = ev.initial;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.initial);
#endif

#ifdef AL_PAUSED
	x = ev.paused;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.paused);
#endif

#ifdef AL_PLAYING
	x = ev.playing;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.playing);
#endif

#ifdef AL_STOPPED
	x = ev.stopped;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.stopped);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
