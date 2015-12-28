/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_units_si
#include <boost/test/unit_test.hpp>

#include <eagine/tagged_quantity.hpp>
#include <eagine/units/si/mass.hpp>
#include <eagine/units/si/length.hpp>
#include <cstdlib>

BOOST_AUTO_TEST_SUITE(units_si_test)

BOOST_AUTO_TEST_CASE(units_si_mass_1)
{
	using namespace eagine;
	using namespace eagine::units;

	typedef tagged_quantity<float, gram> q_g;
	typedef tagged_quantity<float, milligram> q_mg;
	typedef tagged_quantity<float, kilogram> q_kg;
	typedef tagged_quantity<float, tonne> q_t;

	BOOST_CHECK_CLOSE(value(q_mg(1)), value(q_mg(q_g(1)/1000)), 0.01);
	BOOST_CHECK_CLOSE(value(q_kg(1)), value(q_kg(q_g(1)*1000)), 0.01);
	BOOST_CHECK_CLOSE(value(q_kg(1)), value(q_kg(q_t(1)/1000)), 0.01);

	BOOST_CHECK_CLOSE(value(q_t(1)), value(q_t(q_mg(1000)*1000*1000)),0.01);
	BOOST_CHECK_CLOSE(value(q_mg(1)), value(q_mg(q_kg(0.001f)/1000)), 0.01);
}

BOOST_AUTO_TEST_CASE(units_si_length_1)
{
	using namespace eagine;
	using namespace eagine::units;

	typedef tagged_quantity<float, meter> q_m;
	typedef tagged_quantity<float, millimeter> q_mm;
	typedef tagged_quantity<float, centimeter> q_cm;
	typedef tagged_quantity<float, kilometer> q_km;

	BOOST_CHECK_CLOSE(value(q_mm(1)), value(q_mm(q_m(1)/1000)), 0.01);
	BOOST_CHECK_CLOSE(value(q_m(1)), value(q_m(q_km(1)/1000)), 0.01);
	BOOST_CHECK_CLOSE(value(q_km(1)), value(q_km(q_m(1)*1000)), 0.01);
	BOOST_CHECK_CLOSE(value(q_m(1)), value(q_m(q_mm(1)*1000)), 0.01);

	BOOST_CHECK_CLOSE(value(q_cm(1)), value(q_cm(q_m(1)/100)), 0.01);
	BOOST_CHECK_CLOSE(value(q_mm(1)), value(q_mm(q_cm(1)/10)), 0.01);
	BOOST_CHECK_CLOSE(value(q_cm(1)), value(q_cm(q_mm(1)*10)), 0.01);
	BOOST_CHECK_CLOSE(value(q_m(1)), value(q_m(q_cm(1)*100)), 0.01);

	BOOST_CHECK_CLOSE(value(q_mm(1)), value(q_mm(q_km(0.001f)/1000)), 0.01);
	BOOST_CHECK_CLOSE(value(q_km(1)), value(q_km(q_mm(1000)*1000)), 0.01);
}

template <typename U1, typename U2>
void test_units_unit_si_2(double r)
{
	using namespace eagine;

	for(int i=0; i<100; ++i)
	{
		double x = (10 - std::rand() % 20) / 3.0;

		typedef tagged_quantity<double, U1> q_U1;
		typedef tagged_quantity<double, U2> q_U2;

		q_U1 q1(x);
		q_U2 q2(x/r);

		BOOST_CHECK((q1 >  q2) != (q1 <= q2));
		BOOST_CHECK((q1 >= q2) != (q1 <  q2));

		BOOST_CHECK_CLOSE(value(q1), value(q_U1(q2)), 0.01);
		BOOST_CHECK_CLOSE(value(q_U2(q1)), value(q2), 0.01);
	}
}

BOOST_AUTO_TEST_CASE(units_si_2)
{
	using namespace eagine::units;

	// mass
	test_units_unit_si_2<milligram, gram>(1000);
	test_units_unit_si_2<gram, kilogram>(1000);
	test_units_unit_si_2<kilogram, tonne>(1000);
	test_units_unit_si_2<gram, milligram>(0.001);
	test_units_unit_si_2<kilogram, gram>(0.001);
	test_units_unit_si_2<tonne, kilogram>(0.001);
	test_units_unit_si_2<milligram, kilogram>(1000000);
	test_units_unit_si_2<milligram, tonne>(1000000000);

	// length
	test_units_unit_si_2<millimeter, meter>(1000);
	test_units_unit_si_2<meter, millimeter>(0.001);
}

//TODO

BOOST_AUTO_TEST_SUITE_END()
