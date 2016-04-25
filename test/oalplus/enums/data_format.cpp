//  File test/oalplus/enums/data_format.cpp
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
#define BOOST_TEST_MODULE OALPLUS_data_format

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_data_format_tests)

BOOST_AUTO_TEST_CASE(enum_data_format_values)
{
	using namespace oalplus;
	enum_values ev;
	(void)ev;
	data_format x;
	(void)x;

#ifdef AL_FORMAT_MONO16
	x = ev.format_mono16;
	BOOST_CHECK(x == ev.format_mono16);
# ifdef AL_FORMAT_MONO8
	BOOST_CHECK(x != ev.format_mono8);
# endif
# ifdef AL_FORMAT_STEREO16
	BOOST_CHECK(x != ev.format_stereo16);
# endif
# ifdef AL_FORMAT_STEREO8
	BOOST_CHECK(x != ev.format_stereo8);
# endif
#endif

#ifdef AL_FORMAT_MONO8
	x = ev.format_mono8;
	BOOST_CHECK(x == ev.format_mono8);
# ifdef AL_FORMAT_STEREO16
	BOOST_CHECK(x != ev.format_stereo16);
# endif
# ifdef AL_FORMAT_STEREO8
	BOOST_CHECK(x != ev.format_stereo8);
# endif
#endif

#ifdef AL_FORMAT_STEREO16
	x = ev.format_stereo16;
	BOOST_CHECK(x == ev.format_stereo16);
# ifdef AL_FORMAT_STEREO8
	BOOST_CHECK(x != ev.format_stereo8);
# endif
#endif

#ifdef AL_FORMAT_STEREO8
	x = ev.format_stereo8;
	BOOST_CHECK(x == ev.format_stereo8);
#endif
}

BOOST_AUTO_TEST_CASE(enum_data_format_names)
{
	using namespace oalplus;
	enum_values ev;
	(void)ev;
	data_format x;
	(void)x;

#ifdef AL_FORMAT_MONO16
	x = ev.format_mono16;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"FORMAT_MONO16"
	) == 0);
#endif

#ifdef AL_FORMAT_MONO8
	x = ev.format_mono8;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"FORMAT_MONO8"
	) == 0);
#endif

#ifdef AL_FORMAT_STEREO16
	x = ev.format_stereo16;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"FORMAT_STEREO16"
	) == 0);
#endif

#ifdef AL_FORMAT_STEREO8
	x = ev.format_stereo8;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"FORMAT_STEREO8"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_data_format_range)
{
	using namespace oalplus;
	auto count = enum_value_range<data_format>().size();

#ifdef AL_FORMAT_MONO16
{
	--count;
	auto r = enum_value_range<data_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		data_format(AL_FORMAT_MONO16)
	) != r.end());
}
#endif

#ifdef AL_FORMAT_MONO8
{
	--count;
	auto r = enum_value_range<data_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		data_format(AL_FORMAT_MONO8)
	) != r.end());
}
#endif

#ifdef AL_FORMAT_STEREO16
{
	--count;
	auto r = enum_value_range<data_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		data_format(AL_FORMAT_STEREO16)
	) != r.end());
}
#endif

#ifdef AL_FORMAT_STEREO8
{
	--count;
	auto r = enum_value_range<data_format>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		data_format(AL_FORMAT_STEREO8)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_data_format_any)
{
	using namespace oalplus;
	enum_values ev;
	(void)ev;
	data_format x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef AL_FORMAT_MONO16
	x = ev.format_mono16;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.format_mono16);
#endif

#ifdef AL_FORMAT_MONO8
	x = ev.format_mono8;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.format_mono8);
#endif

#ifdef AL_FORMAT_STEREO16
	x = ev.format_stereo16;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.format_stereo16);
#endif

#ifdef AL_FORMAT_STEREO8
	x = ev.format_stereo8;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.format_stereo8);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
