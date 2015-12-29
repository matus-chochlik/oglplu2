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
#include <eagine/units/si/angle.hpp>
#include <eagine/units/si/mass.hpp>
#include <eagine/units/si/length.hpp>
#include <eagine/units/si/time.hpp>
#include <eagine/units/si/temperature.hpp>
#include <cstdlib>

BOOST_AUTO_TEST_SUITE(units_si_test)

BOOST_AUTO_TEST_CASE(units_si_angle_1)
{
	using namespace eagine;
	using namespace eagine::units;

	typedef tagged_quantity<float, pi_rad> q_pi_rad;
	typedef tagged_quantity<float, radian> q_rad;
	typedef tagged_quantity<float, degree> q_deg;
	typedef tagged_quantity<float, gradian> q_grad;
	typedef tagged_quantity<float, quarter> q_Q;
	typedef tagged_quantity<float, turn> q_T;

#ifdef M_PI
	static const auto pi = M_PI;
#else
	static const auto pi = 3.14159265358979323846;
#endif

	BOOST_CHECK_CLOSE(value(q_deg(1)), value(q_deg(q_T(1)/360)), 0.01);
	BOOST_CHECK_CLOSE(value(q_deg(1)), value(q_deg(q_Q(1)/90)), 0.01);
	BOOST_CHECK_CLOSE(value(q_grad(1)), value(q_grad(q_T(1)/400)), 0.01);
	BOOST_CHECK_CLOSE(value(q_grad(1)), value(q_grad(q_Q(1)/100)), 0.01);
	BOOST_CHECK_CLOSE(value(q_Q(1)), value(q_Q(q_T(1)/4)), 0.01);
	BOOST_CHECK_CLOSE(value(q_T(1)), value(q_T(q_Q(1)*4)), 0.01);
	BOOST_CHECK_CLOSE(value(q_T(1)), value(q_T(q_pi_rad(1)*2)), 0.01);
	BOOST_CHECK_CLOSE(value(q_grad(1)), value(q_grad(q_deg(1)*360/400)), 0.01);
	BOOST_CHECK_CLOSE(value(q_deg(1)), value(q_deg(q_grad(1)*400/360)), 0.01);
	BOOST_CHECK_CLOSE(value(q_rad(1)), value(q_rad(q_pi_rad(1)/pi)), 0.01);
	BOOST_CHECK_CLOSE(value(q_rad(1)), value(q_rad(q_deg(1)*180/pi)), 0.01);
	BOOST_CHECK_CLOSE(value(q_deg(1)), value(q_deg(q_rad(1)*pi/180)), 0.01);
}

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

BOOST_AUTO_TEST_CASE(units_si_time_1)
{
	using namespace eagine;
	using namespace eagine::units;

	typedef tagged_quantity<float, millisecond> q_ms;
	typedef tagged_quantity<float, second> q_s;
	typedef tagged_quantity<float, minute> q_min;
	typedef tagged_quantity<float, hour> q_hr;
	typedef tagged_quantity<float, day> q_D;

	BOOST_CHECK_CLOSE(value(q_ms(1)), value(q_ms(q_s(1)/1000)), 0.01);
	BOOST_CHECK_CLOSE(value(q_s(1)), value(q_s(q_min(1)/60)), 0.01);
	BOOST_CHECK_CLOSE(value(q_min(1)), value(q_min(q_hr(1)/60)), 0.01);
	BOOST_CHECK_CLOSE(value(q_s(1)), value(q_s(q_hr(1)/3600)), 0.01);
	BOOST_CHECK_CLOSE(value(q_hr(1)), value(q_hr(q_D(1)/24)), 0.01);
	BOOST_CHECK_CLOSE(value(q_min(1)), value(q_min(q_D(1)/1440)), 0.01);
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

#ifdef M_PI
	static const auto pi = M_PI;
#else
	static const auto pi = 3.14159265358979323846;
#endif

	// angle
	test_units_unit_si_2<pi_rad, turn>(2);
	test_units_unit_si_2<quarter, turn>(4);
	test_units_unit_si_2<degree, turn>(360);
	test_units_unit_si_2<degree, quarter>(90);
	test_units_unit_si_2<degree, pi_rad>(180);
	test_units_unit_si_2<gradian, turn>(400);
	test_units_unit_si_2<gradian, quarter>(100);
	test_units_unit_si_2<gradian, pi_rad>(200);
	test_units_unit_si_2<radian, pi_rad>(pi);
	test_units_unit_si_2<pi_rad, radian>(1/pi);

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
	test_units_unit_si_2<meter, kilometer>(1000);
	test_units_unit_si_2<centimeter, meter>(100);
	test_units_unit_si_2<centimeter, decimeter>(10);
	test_units_unit_si_2<millimeter, centimeter>(10);
	test_units_unit_si_2<decimeter, meter>(10);
	test_units_unit_si_2<meter, millimeter>(0.001);
	test_units_unit_si_2<kilometer, meter>(0.001);
	test_units_unit_si_2<meter, centimeter>(0.01);
	test_units_unit_si_2<centimeter, millimeter>(0.1);
	test_units_unit_si_2<decimeter, centimeter>(0.1);

	// time
	test_units_unit_si_2<millisecond, second>(1000);
	test_units_unit_si_2<second, minute>(60);
	test_units_unit_si_2<second, hour>(60*60);
	test_units_unit_si_2<minute, hour>(60);
	test_units_unit_si_2<second, day>(24*60*60);
	test_units_unit_si_2<minute, day>(24*60);
	test_units_unit_si_2<hour, day>(24);
	test_units_unit_si_2<second, millisecond>(0.001);
	test_units_unit_si_2<minute, second>(1/60.0);
	test_units_unit_si_2<hour, minute>(1/60.0);
	test_units_unit_si_2<day, hour>(1/24.0);
}

//TODO

BOOST_AUTO_TEST_SUITE_END()
