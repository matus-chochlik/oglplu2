//  File test/oalplus/enums/distance_model.cpp
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
#define BOOST_TEST_MODULE OALPLUS_distance_model

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_distance_model_tests)

BOOST_AUTO_TEST_CASE(enum_distance_model_values)
{
	using namespace oalplus;
	enum_values ev;
	(void)ev;
	distance_model x;
	(void)x;

#ifdef AL_EXPONENT_DISTANCE
	x = ev.exponent_distance;
	BOOST_CHECK(x == ev.exponent_distance);
# ifdef AL_EXPONENT_DISTANCE_CLAMPED
	BOOST_CHECK(x != ev.exponent_distance_clamped);
# endif
# ifdef AL_INVERSE_DISTANCE
	BOOST_CHECK(x != ev.inverse_distance);
# endif
# ifdef AL_INVERSE_DISTANCE_CLAMPED
	BOOST_CHECK(x != ev.inverse_distance_clamped);
# endif
# ifdef AL_LINEAR_DISTANCE
	BOOST_CHECK(x != ev.linear_distance);
# endif
# ifdef AL_LINEAR_DISTANCE_CLAMPED
	BOOST_CHECK(x != ev.linear_distance_clamped);
# endif
# ifdef AL_NONE
	BOOST_CHECK(x != ev.none);
# endif
#endif

#ifdef AL_EXPONENT_DISTANCE_CLAMPED
	x = ev.exponent_distance_clamped;
	BOOST_CHECK(x == ev.exponent_distance_clamped);
# ifdef AL_INVERSE_DISTANCE
	BOOST_CHECK(x != ev.inverse_distance);
# endif
# ifdef AL_INVERSE_DISTANCE_CLAMPED
	BOOST_CHECK(x != ev.inverse_distance_clamped);
# endif
# ifdef AL_LINEAR_DISTANCE
	BOOST_CHECK(x != ev.linear_distance);
# endif
# ifdef AL_LINEAR_DISTANCE_CLAMPED
	BOOST_CHECK(x != ev.linear_distance_clamped);
# endif
# ifdef AL_NONE
	BOOST_CHECK(x != ev.none);
# endif
#endif

#ifdef AL_INVERSE_DISTANCE
	x = ev.inverse_distance;
	BOOST_CHECK(x == ev.inverse_distance);
# ifdef AL_INVERSE_DISTANCE_CLAMPED
	BOOST_CHECK(x != ev.inverse_distance_clamped);
# endif
# ifdef AL_LINEAR_DISTANCE
	BOOST_CHECK(x != ev.linear_distance);
# endif
# ifdef AL_LINEAR_DISTANCE_CLAMPED
	BOOST_CHECK(x != ev.linear_distance_clamped);
# endif
# ifdef AL_NONE
	BOOST_CHECK(x != ev.none);
# endif
#endif

#ifdef AL_INVERSE_DISTANCE_CLAMPED
	x = ev.inverse_distance_clamped;
	BOOST_CHECK(x == ev.inverse_distance_clamped);
# ifdef AL_LINEAR_DISTANCE
	BOOST_CHECK(x != ev.linear_distance);
# endif
# ifdef AL_LINEAR_DISTANCE_CLAMPED
	BOOST_CHECK(x != ev.linear_distance_clamped);
# endif
# ifdef AL_NONE
	BOOST_CHECK(x != ev.none);
# endif
#endif

#ifdef AL_LINEAR_DISTANCE
	x = ev.linear_distance;
	BOOST_CHECK(x == ev.linear_distance);
# ifdef AL_LINEAR_DISTANCE_CLAMPED
	BOOST_CHECK(x != ev.linear_distance_clamped);
# endif
# ifdef AL_NONE
	BOOST_CHECK(x != ev.none);
# endif
#endif

#ifdef AL_LINEAR_DISTANCE_CLAMPED
	x = ev.linear_distance_clamped;
	BOOST_CHECK(x == ev.linear_distance_clamped);
# ifdef AL_NONE
	BOOST_CHECK(x != ev.none);
# endif
#endif

#ifdef AL_NONE
	x = ev.none;
	BOOST_CHECK(x == ev.none);
#endif
}

BOOST_AUTO_TEST_CASE(enum_distance_model_names)
{
	using namespace oalplus;
	enum_values ev;
	(void)ev;
	distance_model x;
	(void)x;

#ifdef AL_EXPONENT_DISTANCE
	x = ev.exponent_distance;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"EXPONENT_DISTANCE"
	) == 0);
#endif

#ifdef AL_EXPONENT_DISTANCE_CLAMPED
	x = ev.exponent_distance_clamped;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"EXPONENT_DISTANCE_CLAMPED"
	) == 0);
#endif

#ifdef AL_INVERSE_DISTANCE
	x = ev.inverse_distance;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"INVERSE_DISTANCE"
	) == 0);
#endif

#ifdef AL_INVERSE_DISTANCE_CLAMPED
	x = ev.inverse_distance_clamped;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"INVERSE_DISTANCE_CLAMPED"
	) == 0);
#endif

#ifdef AL_LINEAR_DISTANCE
	x = ev.linear_distance;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"LINEAR_DISTANCE"
	) == 0);
#endif

#ifdef AL_LINEAR_DISTANCE_CLAMPED
	x = ev.linear_distance_clamped;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"LINEAR_DISTANCE_CLAMPED"
	) == 0);
#endif

#ifdef AL_NONE
	x = ev.none;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"NONE"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_distance_model_range)
{
	using namespace oalplus;
	auto count = enum_value_range<distance_model>().size();

#ifdef AL_EXPONENT_DISTANCE
{
	--count;
	auto r = enum_value_range<distance_model>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		distance_model(AL_EXPONENT_DISTANCE)
	) != r.end());
}
#endif

#ifdef AL_EXPONENT_DISTANCE_CLAMPED
{
	--count;
	auto r = enum_value_range<distance_model>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		distance_model(AL_EXPONENT_DISTANCE_CLAMPED)
	) != r.end());
}
#endif

#ifdef AL_INVERSE_DISTANCE
{
	--count;
	auto r = enum_value_range<distance_model>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		distance_model(AL_INVERSE_DISTANCE)
	) != r.end());
}
#endif

#ifdef AL_INVERSE_DISTANCE_CLAMPED
{
	--count;
	auto r = enum_value_range<distance_model>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		distance_model(AL_INVERSE_DISTANCE_CLAMPED)
	) != r.end());
}
#endif

#ifdef AL_LINEAR_DISTANCE
{
	--count;
	auto r = enum_value_range<distance_model>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		distance_model(AL_LINEAR_DISTANCE)
	) != r.end());
}
#endif

#ifdef AL_LINEAR_DISTANCE_CLAMPED
{
	--count;
	auto r = enum_value_range<distance_model>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		distance_model(AL_LINEAR_DISTANCE_CLAMPED)
	) != r.end());
}
#endif

#ifdef AL_NONE
{
	--count;
	auto r = enum_value_range<distance_model>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		distance_model(AL_NONE)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_distance_model_any)
{
	using namespace oalplus;
	enum_values ev;
	(void)ev;
	distance_model x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef AL_EXPONENT_DISTANCE
	x = ev.exponent_distance;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.exponent_distance);
#endif

#ifdef AL_EXPONENT_DISTANCE_CLAMPED
	x = ev.exponent_distance_clamped;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.exponent_distance_clamped);
#endif

#ifdef AL_INVERSE_DISTANCE
	x = ev.inverse_distance;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.inverse_distance);
#endif

#ifdef AL_INVERSE_DISTANCE_CLAMPED
	x = ev.inverse_distance_clamped;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.inverse_distance_clamped);
#endif

#ifdef AL_LINEAR_DISTANCE
	x = ev.linear_distance;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.linear_distance);
#endif

#ifdef AL_LINEAR_DISTANCE_CLAMPED
	x = ev.linear_distance_clamped;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.linear_distance_clamped);
#endif

#ifdef AL_NONE
	x = ev.none;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.none);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
