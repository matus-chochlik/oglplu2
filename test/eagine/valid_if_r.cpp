/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_valid_if
#include <boost/test/unit_test.hpp>

#include <eagine/valid_if.hpp>
#include <cstdlib>

BOOST_AUTO_TEST_SUITE(valid_if_tests)

BOOST_AUTO_TEST_CASE(valid_if_not_zero_test)
{
	using namespace eagine;

	for(int i=0; i<1000; ++i)
	{
		int v = (std::rand()%10==0)?0:std::rand()%1000;

		valid_if_not_zero<float> x(v);

		BOOST_CHECK_EQUAL(x.is_valid(), v != 0);
		BOOST_CHECK_EQUAL(bool(x), v != 0);
		BOOST_CHECK_EQUAL(!x, v == 0);

		BOOST_CHECK_EQUAL(x.value_or(v), v);
		if(x.is_valid())
		{
			BOOST_CHECK_EQUAL(x.value(), v);
		}
	}
}

BOOST_AUTO_TEST_CASE(valid_if_not_test)
{
	using namespace eagine;

	for(int i=0; i<1000; ++i)
	{
		int v = (std::rand()%10==0)?123:std::rand();

		valid_if_not<int, 123> x(v);

		BOOST_CHECK_EQUAL(x.is_valid(), v != 123);
		BOOST_CHECK_EQUAL(bool(x), v != 123);
		BOOST_CHECK_EQUAL(!x, v == 123);

		BOOST_CHECK_EQUAL(x.value_or(v), v);
		if(x.is_valid())
		{
			BOOST_CHECK_EQUAL(x.value(), v);
		}
	}
}

BOOST_AUTO_TEST_CASE(valid_if_greater_than_test)
{
	using namespace eagine;

	for(int i=0; i<1000; ++i)
	{
		int v = (std::rand()%10==0)?123:(std::rand()%1000);

		valid_if_greater_than<int, 123> x(v);

		BOOST_CHECK_EQUAL(x.is_valid(), v > 123);
		BOOST_CHECK_EQUAL(bool(x), v > 123);
		BOOST_CHECK_EQUAL(!x, v <= 123);

		BOOST_CHECK_EQUAL(x.value_or(v), v);
		if(x.is_valid())
		{
			BOOST_CHECK_EQUAL(x.value(), v);
		}
	}
}

// TODO

BOOST_AUTO_TEST_SUITE_END()
