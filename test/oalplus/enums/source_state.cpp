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

BOOST_AUTO_TEST_SUITE(enum_source_state)

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
# ifdef AL_INITIAL
	BOOST_CHECK(x != ev.initial);
# endif
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
# ifdef AL_INITIAL
	BOOST_CHECK(x != ev.initial);
# endif
# ifdef AL_PAUSED
	BOOST_CHECK(x != ev.paused);
# endif
	BOOST_CHECK(x == ev.playing);
# ifdef AL_STOPPED
	BOOST_CHECK(x != ev.stopped);
# endif
#endif

#ifdef AL_STOPPED
	x = ev.stopped;
# ifdef AL_INITIAL
	BOOST_CHECK(x != ev.initial);
# endif
# ifdef AL_PAUSED
	BOOST_CHECK(x != ev.paused);
# endif
# ifdef AL_PLAYING
	BOOST_CHECK(x != ev.playing);
# endif
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
	source_state x;
	(void)x;
	auto count = enum_value_range(x).size();

#ifdef AL_INITIAL
{
	--count;
	array_view<const ALenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		AL_INITIAL
	) != r.end());
}
#endif

#ifdef AL_PAUSED
{
	--count;
	array_view<const ALenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		AL_PAUSED
	) != r.end());
}
#endif

#ifdef AL_PLAYING
{
	--count;
	array_view<const ALenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		AL_PLAYING
	) != r.end());
}
#endif

#ifdef AL_STOPPED
{
	--count;
	array_view<const ALenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		AL_STOPPED
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
