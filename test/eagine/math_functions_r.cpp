/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_math_functions
#include <boost/test/unit_test.hpp>

#include <eagine/math/functions.hpp>
#include <cstdlib>

BOOST_AUTO_TEST_SUITE(math_functions)

BOOST_AUTO_TEST_CASE(math_functions_factorial)
{
	using namespace eagine::math;

	BOOST_CHECK_EQUAL(factorial(-2),   1);
	BOOST_CHECK_EQUAL(factorial(-1),   1);

	BOOST_CHECK_EQUAL(factorial(0),   1);
	BOOST_CHECK_EQUAL(factorial(1),   1);
	BOOST_CHECK_EQUAL(factorial(2),   2);
	BOOST_CHECK_EQUAL(factorial(3),   6);
	BOOST_CHECK_EQUAL(factorial(4),  24);
	BOOST_CHECK_EQUAL(factorial(5), 120);
	BOOST_CHECK_EQUAL(factorial(6), 720);
	BOOST_CHECK_EQUAL(factorial(7),5040);

	BOOST_CHECK_EQUAL(factorial(12), 479001600);
}

BOOST_AUTO_TEST_CASE(math_functions_binomial)
{
	using namespace eagine::math;

	BOOST_CHECK_EQUAL(binomial(0, 0), 1);

	for(int n=1; n<12; ++n)
	{
		BOOST_CHECK_EQUAL(binomial(n, 0), 1);
		
		for(int k=1; k<n; ++k)
		{
			BOOST_CHECK_EQUAL(
				binomial(n, k),
				binomial(n-1, k-1)+
				binomial(n-1, k)
			);
		}
		
		BOOST_CHECK_EQUAL(binomial(n, n), 1);
	}
}

//TODO

BOOST_AUTO_TEST_SUITE_END()
