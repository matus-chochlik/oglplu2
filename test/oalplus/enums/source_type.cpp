//  File test/oalplus/enums/source_type.cpp
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
#define BOOST_TEST_MODULE OALPLUS_source_type

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_source_type_tests)

BOOST_AUTO_TEST_CASE(enum_source_type_values)
{
	using namespace oalplus;
	enum_values ev;
	(void)ev;
	source_type x;
	(void)x;

#ifdef AL_STATIC
	x = ev.static_;
	BOOST_CHECK(x == ev.static_);
# ifdef AL_STREAMING
	BOOST_CHECK(x != ev.streaming);
# endif
# ifdef AL_UNDETERMINED
	BOOST_CHECK(x != ev.undetermined);
# endif
#endif

#ifdef AL_STREAMING
	x = ev.streaming;
	BOOST_CHECK(x == ev.streaming);
# ifdef AL_UNDETERMINED
	BOOST_CHECK(x != ev.undetermined);
# endif
#endif

#ifdef AL_UNDETERMINED
	x = ev.undetermined;
	BOOST_CHECK(x == ev.undetermined);
#endif
}

BOOST_AUTO_TEST_CASE(enum_source_type_names)
{
	using namespace oalplus;
	enum_values ev;
	(void)ev;
	source_type x;
	(void)x;

#ifdef AL_STATIC
	x = ev.static_;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"STATIC"
	) == 0);
#endif

#ifdef AL_STREAMING
	x = ev.streaming;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"STREAMING"
	) == 0);
#endif

#ifdef AL_UNDETERMINED
	x = ev.undetermined;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"UNDETERMINED"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_source_type_range)
{
	using namespace oalplus;
	auto count = enum_value_range<source_type>().size();

#ifdef AL_STATIC
{
	--count;
	auto r = enum_value_range<source_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		source_type(AL_STATIC)
	) != r.end());
}
#endif

#ifdef AL_STREAMING
{
	--count;
	auto r = enum_value_range<source_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		source_type(AL_STREAMING)
	) != r.end());
}
#endif

#ifdef AL_UNDETERMINED
{
	--count;
	auto r = enum_value_range<source_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		source_type(AL_UNDETERMINED)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_source_type_any)
{
	using namespace oalplus;
	enum_values ev;
	(void)ev;
	source_type x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef AL_STATIC
	x = ev.static_;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.static_);
#endif

#ifdef AL_STREAMING
	x = ev.streaming;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.streaming);
#endif

#ifdef AL_UNDETERMINED
	x = ev.undetermined;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.undetermined);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
