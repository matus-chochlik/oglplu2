/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_quantities
#include <boost/test/unit_test.hpp>

#include <eagine/quantities.hpp>
#include <cstdlib>

BOOST_AUTO_TEST_SUITE(test_quantities)

template <typename T>
void eagine_test_quantities_1(void)
{
	using namespace eagine;

	T r = T(std::rand() % 100000);
	degrees_t<T> v = degrees(r);
	BOOST_CHECK(!(T(v) > r));
	BOOST_CHECK(!(T(v) < r));
}

BOOST_AUTO_TEST_CASE(quantities_1)
{
	eagine_test_quantities_1<int>();
	eagine_test_quantities_1<float>();
	eagine_test_quantities_1<double>();
}


BOOST_AUTO_TEST_SUITE_END()
