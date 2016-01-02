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

	tagged_quantity<T, meter> ql1_m(l1);
	tagged_quantity<T, meter> ql2_m(l2);
	tagged_quantity<T, meter> ql3_m(l3);

	tagged_quantity<T, unit<area, si>> qa12_m2 = ql1_m*ql2_m;
	tagged_quantity<T, unit<area, si>> qa13_m2 = ql1_m*ql3_m;
	tagged_quantity<T, unit<area, si>> qa23_m2 = ql2_m*ql3_m;

	tagged_quantity<T, unit<volume, si>> qv123_m3 = ql1_m*ql2_m*ql3_m;

	BOOST_CHECK_CLOSE(
		value(ql1_m)*value(ql2_m),
		value(qa12_m2), 0.001
	);

	BOOST_CHECK_CLOSE(
		value(ql1_m)*value(ql3_m),
		value(qa13_m2), 0.001
	);

	BOOST_CHECK_CLOSE(
		value(ql2_m)*value(ql3_m),
		value(qa23_m2), 0.001
	);

	BOOST_CHECK_CLOSE(
		value(ql1_m)*value(ql2_m)*value(ql3_m),
		value(qv123_m3), 0.001
	);

	BOOST_CHECK_CLOSE(
		value(qa12_m2)*value(ql3_m),
		value(qv123_m3), 0.001
	);

	BOOST_CHECK_CLOSE(
		value(qa13_m2)*value(ql2_m),
		value(qv123_m3), 0.001
	);

	BOOST_CHECK_CLOSE(
		value(ql1_m)*value(qa23_m2),
		value(qv123_m3), 0.001
	);

	BOOST_CHECK_CLOSE(
		value(qa12_m2)/value(ql2_m),
		value(ql1_m), 0.001
	);

	BOOST_CHECK_CLOSE(
		value(qa23_m2)/value(ql3_m),
		value(ql2_m), 0.001
	);

	BOOST_CHECK_CLOSE(
		value(qv123_m3)/value(ql3_m),
		value(qa12_m2), 0.001
	);

	BOOST_CHECK_CLOSE(
		value(qv123_m3)/value(qa13_m2),
		value(ql2_m), 0.001
	);
}

BOOST_AUTO_TEST_CASE(units_si_1)
{
	for(int i=0; i<100; ++i)
	{
		test_units_si_1<float>();
	}
}

template <typename T>
void test_units_si_2(void)
{
	using eagine::tagged_quantity;
	using namespace eagine::units;

	T l1 = get<T>();
	T l2 = get<T>();
	T l3 = get<T>();

	tagged_quantity<T, meter> ql1_m(l1);
	tagged_quantity<T, centimeter> ql2_cm(l2);
	tagged_quantity<T, millimeter> ql3_mm(l3);

	tagged_quantity<T, unit<area, si>> qa22_m2 = ql2_cm*ql2_cm;
	tagged_quantity<T, unit<area, si>> qa12_m2 = ql1_m*ql2_cm;
	tagged_quantity<T, unit<area, si>> qa13_m2 = ql1_m*ql3_mm;

	//tagged_quantity<T, unit<volume, si>> qv123_m3 = ql1_m*ql2_m*ql3_m;

	BOOST_CHECK_CLOSE(
		value(ql2_cm)*value(ql2_cm)/10000,
		value(qa22_m2), 0.001
	);

	BOOST_CHECK_CLOSE(
		value(ql1_m)*value(ql2_cm)/100,
		value(qa12_m2), 0.001
	);

	BOOST_CHECK_CLOSE(
		value(ql1_m)*value(ql3_mm)/1000,
		value(qa13_m2), 0.001
	);
}

BOOST_AUTO_TEST_CASE(units_si_2)
{
	for(int i=0; i<100; ++i)
	{
		test_units_si_2<float>();
	}
}

//TODO

BOOST_AUTO_TEST_SUITE_END()
