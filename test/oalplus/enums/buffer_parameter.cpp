//  File test/oalplus/enums/buffer_parameter.cpp
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
#define BOOST_TEST_MODULE OALPLUS_buffer_parameter

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_buffer_parameter_tests)

BOOST_AUTO_TEST_CASE(enum_buffer_parameter_values)
{
	using namespace oalplus;
	enum_values ev;
	(void)ev;
	buffer_parameter x;
	(void)x;

#ifdef AL_BITS
	x = ev.bits;
	BOOST_CHECK(x == ev.bits);
# ifdef AL_CHANNELS
	BOOST_CHECK(x != ev.channels);
# endif
# ifdef AL_FREQUENCY
	BOOST_CHECK(x != ev.frequency);
# endif
# ifdef AL_SIZE
	BOOST_CHECK(x != ev.size);
# endif
#endif

#ifdef AL_CHANNELS
	x = ev.channels;
	BOOST_CHECK(x == ev.channels);
# ifdef AL_FREQUENCY
	BOOST_CHECK(x != ev.frequency);
# endif
# ifdef AL_SIZE
	BOOST_CHECK(x != ev.size);
# endif
#endif

#ifdef AL_FREQUENCY
	x = ev.frequency;
	BOOST_CHECK(x == ev.frequency);
# ifdef AL_SIZE
	BOOST_CHECK(x != ev.size);
# endif
#endif

#ifdef AL_SIZE
	x = ev.size;
	BOOST_CHECK(x == ev.size);
#endif
}

BOOST_AUTO_TEST_CASE(enum_buffer_parameter_names)
{
	using namespace oalplus;
	enum_values ev;
	(void)ev;
	buffer_parameter x;
	(void)x;

#ifdef AL_BITS
	x = ev.bits;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"BITS"
	) == 0);
#endif

#ifdef AL_CHANNELS
	x = ev.channels;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"CHANNELS"
	) == 0);
#endif

#ifdef AL_FREQUENCY
	x = ev.frequency;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"FREQUENCY"
	) == 0);
#endif

#ifdef AL_SIZE
	x = ev.size;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SIZE"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_buffer_parameter_range)
{
	using namespace oalplus;
	auto count = enum_value_range<buffer_parameter>().size();

#ifdef AL_BITS
{
	--count;
	auto r = enum_value_range<buffer_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		buffer_parameter(AL_BITS)
	) != r.end());
}
#endif

#ifdef AL_CHANNELS
{
	--count;
	auto r = enum_value_range<buffer_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		buffer_parameter(AL_CHANNELS)
	) != r.end());
}
#endif

#ifdef AL_FREQUENCY
{
	--count;
	auto r = enum_value_range<buffer_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		buffer_parameter(AL_FREQUENCY)
	) != r.end());
}
#endif

#ifdef AL_SIZE
{
	--count;
	auto r = enum_value_range<buffer_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		buffer_parameter(AL_SIZE)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_buffer_parameter_any)
{
	using namespace oalplus;
	enum_values ev;
	(void)ev;
	buffer_parameter x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef AL_BITS
	x = ev.bits;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.bits);
#endif

#ifdef AL_CHANNELS
	x = ev.channels;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.channels);
#endif

#ifdef AL_FREQUENCY
	x = ev.frequency;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.frequency);
#endif

#ifdef AL_SIZE
	x = ev.size;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.size);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
