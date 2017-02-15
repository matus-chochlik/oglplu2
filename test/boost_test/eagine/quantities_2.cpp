/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/quantities.hpp>
#include <eagine/units/unit/si/angle.hpp>
#define BOOST_TEST_MODULE EAGINE_quantities_2
#include "../unit_test.inl"

BOOST_AUTO_TEST_SUITE(quantities_tests_2)

static eagine::test_random_generator rg;

template <typename T>
void eagine_test_angles_1(void)
{
	using namespace eagine;

	BOOST_CHECK_SMALL(sin(radians_(0)), 0.0001);
	BOOST_CHECK_SMALL(sin(degrees_(0)), 0.0001);
	BOOST_CHECK_CLOSE(sin(degrees_(90)), 1, 0.0001);
	BOOST_CHECK_SMALL(sin(degrees_(180)), 0.0001);
	BOOST_CHECK_CLOSE(sin(degrees_(270)),-1, 0.0001);
	BOOST_CHECK_SMALL(sin(degrees_(360)), 0.0001);

	BOOST_CHECK_CLOSE(cos(radians_(0)), 1, 0.0001);
	BOOST_CHECK_CLOSE(cos(degrees_(0)), 1, 0.0001);
	BOOST_CHECK_SMALL(cos(degrees_(90)), 0.0001);
	BOOST_CHECK_CLOSE(cos(degrees_(180)),-1, 0.0001);
	BOOST_CHECK_SMALL(cos(degrees_(270)), 0.0001);
	BOOST_CHECK_CLOSE(cos(degrees_(360)), 1, 0.0001);
}

BOOST_AUTO_TEST_CASE(quantities_1)
{
	eagine_test_angles_1<float>();
	eagine_test_angles_1<double>();
}

template <typename T>
void eagine_test_angles_2(void)
{
	using namespace eagine;

	for(int i=0; i<100; ++i)
	{
		T x = rg.get<T>(-1000, 1000);

		BOOST_CHECK_CLOSE(sin(radians_(x)), std::sin(x), 0.0001);
		BOOST_CHECK_CLOSE(cos(radians_(x)), std::cos(x), 0.0001);
		BOOST_CHECK_CLOSE(tan(radians_(x)), std::tan(x), 0.0001);
	}
}

BOOST_AUTO_TEST_CASE(quantities_2)
{
	eagine_test_angles_2<float>();
	eagine_test_angles_2<double>();
}

// TODO

BOOST_AUTO_TEST_SUITE_END()
