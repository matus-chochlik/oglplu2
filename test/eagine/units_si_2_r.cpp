/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_units_si_2
#include <boost/test/unit_test.hpp>

#include <eagine/units/dim/area.hpp>
#include <eagine/units/dim/volume.hpp>

#include <eagine/units/unit/si/information.hpp>
#include <eagine/units/unit/si/angle.hpp>
#include <eagine/units/unit/si/solid_angle.hpp>
#include <eagine/units/unit/si/mass.hpp>
#include <eagine/units/unit/si/length.hpp>
#include <eagine/units/unit/si/time.hpp>
#include <eagine/units/unit/si/temperature.hpp>
#include <eagine/units/unit/si/luminous_intensity.hpp>
#include <eagine/units/unit/si/amount_of_substance.hpp>
#include <eagine/units/unit/si/frequency.hpp>

#include <eagine/tagged_quantity.hpp>

#include <cstdlib>

BOOST_AUTO_TEST_SUITE(units_si_test_2)

template <typename T>
T get(void)
{
	return (1 + std::rand() % 10000) / T(100);
}

template <typename T>
void test_units_si_1(void)
{
	using eagine::tagged_quantity;
	using namespace eagine::units;

	T l1 = get<T>();
	T l2 = get<T>();
	T l3 = get<T>();

	tagged_quantity<T, meter> ql1(l1);
	tagged_quantity<T, meter> ql2(l2);
	tagged_quantity<T, meter> ql3(l3);

	tagged_quantity<T, unit<area, si>> qa12 = ql1*ql2;
	tagged_quantity<T, unit<area, si>> qa13 = ql1*ql3;
	tagged_quantity<T, unit<area, si>> qa23 = ql2*ql3;

	tagged_quantity<T, unit<volume, si>> qv123 = ql1*ql2*ql3;

	BOOST_CHECK_CLOSE(
		value(ql1)*value(ql2),
		value(qa12), 0.001
	);

	BOOST_CHECK_CLOSE(
		value(ql1)*value(ql3),
		value(qa13), 0.001
	);

	BOOST_CHECK_CLOSE(
		value(ql2)*value(ql3),
		value(qa23), 0.001
	);

	BOOST_CHECK_CLOSE(
		value(ql1)*value(ql2)*value(ql3),
		value(qv123), 0.001
	);

	BOOST_CHECK_CLOSE(
		value(qa12)*value(ql3),
		value(qv123), 0.001
	);

	BOOST_CHECK_CLOSE(
		value(qa13)*value(ql2),
		value(qv123), 0.001
	);

	BOOST_CHECK_CLOSE(
		value(ql1)*value(qa23),
		value(qv123), 0.001
	);

	BOOST_CHECK_CLOSE(
		value(qa12)/value(ql2),
		value(ql1), 0.001
	);

	BOOST_CHECK_CLOSE(
		value(qa23)/value(ql3),
		value(ql2), 0.001
	);

	BOOST_CHECK_CLOSE(
		value(qv123)/value(ql3),
		value(qa12), 0.001
	);

	BOOST_CHECK_CLOSE(
		value(qv123)/value(qa13),
		value(ql2), 0.001
	);
}

BOOST_AUTO_TEST_CASE(units_si_1)
{
	for(int i=0; i<100; ++i)
	{
		test_units_si_1<float>();
	}
}

//TODO

BOOST_AUTO_TEST_SUITE_END()
