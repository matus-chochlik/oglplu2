/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_quantities_1
#include <boost/test/unit_test.hpp>

#include <eagine/quantities.hpp>
#include <cstdlib>

BOOST_AUTO_TEST_SUITE(test_quantities_1)

template <typename T>
void eagine_test_quantities_1(void)
{
	using namespace eagine;

	T r1 = T((std::rand() % 10000) / 100);
	T r2 = T((std::rand() % 10000) / 100);

	degrees_t<T> v1 = degrees_(r1);
	degrees_t<T> v2 = degrees_(r2);
	degrees_t<T> v3 = v1+v2;
	degrees_t<T> v4 = v1-v2;

	BOOST_CHECK(!(T(v1) > r1));
	BOOST_CHECK(!(T(v1) < r1));
	BOOST_CHECK(!(T(v2) > r2));
	BOOST_CHECK(!(T(v2) < r2));
	BOOST_CHECK(!(T(v3) > r1+r2));
	BOOST_CHECK(!(T(v3) < r1+r2));
	BOOST_CHECK(!(T(v4) > r1-r2));
	BOOST_CHECK(!(T(v4) < r1-r2));

	BOOST_CHECK(!(T(+v1) > +r1));
	BOOST_CHECK(!(T(+v1) < +r1));
	BOOST_CHECK(!(T(-v2) > -r2));
	BOOST_CHECK(!(T(-v2) < -r2));

	BOOST_CHECK_EQUAL(v1 >  v2, r1 >  r2);
	BOOST_CHECK_EQUAL(v1 <  v2, r1 <  r2);
	BOOST_CHECK_EQUAL(v1 >= v2, r1 >= r2);
	BOOST_CHECK_EQUAL(v1 <= v2, r1 <= r2);
}

BOOST_AUTO_TEST_CASE(quantities_1)
{
	eagine_test_quantities_1<int>();
	eagine_test_quantities_1<float>();
	eagine_test_quantities_1<double>();
}

// TODO

BOOST_AUTO_TEST_SUITE_END()
