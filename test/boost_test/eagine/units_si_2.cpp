/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/units/dim/area.hpp>
#include <eagine/units/dim/volume.hpp>
#include <eagine/units/dim/velocity.hpp>
#include <eagine/units/dim/acceleration.hpp>

#include <eagine/units/unit/si/information.hpp>
#include <eagine/units/unit/si/angle.hpp>
#include <eagine/units/unit/si/solid_angle.hpp>
#include <eagine/units/unit/si/mass.hpp>
#include <eagine/units/unit/si/length.hpp>
#include <eagine/units/unit/si/time.hpp>
#include <eagine/units/unit/si/time.hpp>
#include <eagine/units/unit/si/luminous_intensity.hpp>
#include <eagine/units/unit/si/amount_of_substance.hpp>
#include <eagine/units/unit/si/frequency.hpp>
#include <eagine/units/unit/si/radioactivity.hpp>
#include <eagine/units/unit/si/force.hpp>
#include <eagine/units/unit/si/pressure.hpp>
#include <eagine/units/unit/si/energy.hpp>
#include <eagine/units/unit/si/power.hpp>
#include <eagine/units/unit/si/electric_current.hpp>
#include <eagine/units/unit/si/electric_charge.hpp>
#include <eagine/units/unit/si/electric_tension.hpp>
#include <eagine/units/unit/si/electrical_capacitance.hpp>
#include <eagine/units/unit/si/electrical_conductance.hpp>
#include <eagine/units/unit/si/electrical_resistance.hpp>
#include <eagine/units/unit/si/magnetic_flux.hpp>
#include <eagine/units/unit/si/magnetic_field_strength.hpp>
#include <eagine/units/unit/si/inductance.hpp>

#include <eagine/tagged_quantity.hpp>
#define BOOST_TEST_MODULE EAGINE_units_si_2
#include "../unit_test_begin.inl"

BOOST_AUTO_TEST_SUITE(units_si_tests_2)

static eagine::test_random_generator rg;

template <typename T>
T get(void)
{
	return rg.get<T>(1, 100);
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
	tagged_quantity<T, unit<area, si>> qa23_m2 = ql2_cm*ql3_mm;

	tagged_quantity<T, unit<volume, si>> qv123_m3 = ql1_m*ql2_cm*ql3_mm;

	BOOST_CHECK_CLOSE(
		value(ql2_cm)*value(ql2_cm)/10000,
		value(qa22_m2), 0.001
	);

	BOOST_CHECK_CLOSE(
		value(ql2_cm)*value(ql2_cm),
		value(ql2_cm*ql2_cm), 0.001
	);

	BOOST_CHECK_CLOSE(
		value(ql1_m)*value(ql2_cm)/100,
		value(qa12_m2), 0.001
	);

	BOOST_CHECK_CLOSE(
		value(ql1_m)*value(ql1_m),
		value(ql1_m*ql1_m), 0.001
	);

	BOOST_CHECK_CLOSE(
		value(ql1_m)*value(ql3_mm)/1000,
		value(qa13_m2), 0.001
	);

	BOOST_CHECK_CLOSE(
		value(ql3_mm)*value(ql3_mm),
		value(ql3_mm*ql3_mm), 0.001
	);

	BOOST_CHECK_CLOSE(
		value(ql1_m)*value(ql2_cm)*value(ql3_mm)/100000,
		value(qv123_m3), 0.001
	);

	BOOST_CHECK_CLOSE(
		value(qv123_m3)/value(ql1_m),
		value(qa23_m2), 0.001
	);

	BOOST_CHECK_CLOSE(
		value(qv123_m3)/(value(ql2_cm)/100),
		value(qa13_m2), 0.001
	);

	BOOST_CHECK_CLOSE(
		value(qv123_m3)/(value(ql3_mm)/1000),
		value(qa12_m2), 0.001
	);

	BOOST_CHECK_CLOSE(
		value(qv123_m3)/value(qa12_m2),
		value(ql3_mm)/1000, 0.001
	);

	BOOST_CHECK_CLOSE(
		value(qv123_m3)/value(qa13_m2),
		value(ql2_cm)/100, 0.001
	);

	BOOST_CHECK_CLOSE(
		value(qv123_m3)/value(qa23_m2),
		value(ql1_m), 0.001
	);
}

BOOST_AUTO_TEST_CASE(units_si_2)
{
	for(int i=0; i<100; ++i)
	{
		test_units_si_2<float>();
	}
}

template <typename T>
void test_units_si_3(void)
{
	using eagine::tagged_quantity;
	using namespace eagine::units;

	T t1 = get<T>();
	T t2 = get<T>();
	T l1 = get<T>();
	T l2 = get<T>();
	T m1 = get<T>();

	tagged_quantity<T, meter> ql1_m(l1);
	tagged_quantity<T, kilometer> ql2_km(l2);
	tagged_quantity<T, second> qt1_s(t1);
	tagged_quantity<T, hour> qt2_h(t2);
	tagged_quantity<T, kilogram> qm1_kg(m1);
	tagged_quantity<T, unit<velocity, si>> qv1_m_s = ql1_m / qt1_s;
	tagged_quantity<T, unit<velocity, si>> qv2_m_s = ql2_km / qt1_s;
	tagged_quantity<T, unit<velocity, si>> qv3_m_s = ql2_km / qt2_h;
	tagged_quantity<T, unit<acceleration, si>> qa1_m_s2 = qv1_m_s / qt1_s;
	tagged_quantity<T, newton> qF1_N = qm1_kg * qa1_m_s2;
	tagged_quantity<T, pascal> qp1_Pa = qF1_N / (ql1_m * ql1_m);
	tagged_quantity<T, kilonewton> qF2_kN(qF1_N);
	tagged_quantity<T, joule> qE1_J(qF1_N * ql2_km);
	tagged_quantity<T, kilojoule> qE2_kJ(qm1_kg * qa1_m_s2 * ql2_km);
	tagged_quantity<T, watt> qP1_W(qE1_J / qt2_h);
	tagged_quantity<T, kilowatt> qP2_kW(qE2_kJ / qt2_h);
	tagged_quantity<T, megawatt> qP3_MW(qm1_kg * qa1_m_s2 * ql2_km / qt2_h);

	BOOST_CHECK_CLOSE(
		value(ql1_m)/value(qt1_s),
		value(qv1_m_s), 0.001
	);

	BOOST_CHECK_CLOSE(
		value(ql2_km)/value(qt1_s),
		value(qv2_m_s)/1000, 0.001
	);

	BOOST_CHECK_CLOSE(
		value(ql2_km)/value(qt2_h),
		value(qv3_m_s)*3600/1000, 0.001
	);

	BOOST_CHECK_CLOSE(
		value(ql2_km)/value(qt2_h),
		value(ql2_km/qt2_h), 0.001
	);

	BOOST_CHECK_CLOSE(
		value(ql1_m)/value(qt1_s)/value(qt1_s),
		value(qa1_m_s2), 0.001
	);

	BOOST_CHECK_CLOSE(
		value(qm1_kg)*value(qv1_m_s)/value(qt1_s),
		value(qF1_N), 0.001
	);

	BOOST_CHECK_CLOSE(
		value(qm1_kg)/(value(qt1_s)*value(qt1_s)*value(ql1_m)),
		value(qp1_Pa), 0.001
	);

	BOOST_CHECK_CLOSE(
		(value(ql2_km)*1000)*value(qm1_kg)*value(qv1_m_s)/value(qt1_s),
		value(qE1_J), 0.001
	);

	BOOST_CHECK_CLOSE(
		value(qE2_kJ)*1000,
		value(qE1_J), 0.001
	);

	BOOST_CHECK_CLOSE(
		value(qF1_N)*(value(ql2_km)*1000)/(value(qt2_h)*3600),
		value(qP1_W), 0.001
	);

	BOOST_CHECK_CLOSE(
		value(qP2_kW)*1000,
		value(qP1_W), 0.001
	);

	BOOST_CHECK_CLOSE(
		value(qP3_MW)*1000000,
		value(qP1_W), 0.001
	);
}

BOOST_AUTO_TEST_CASE(units_si_3)
{
	for(int i=0; i<100; ++i)
	{
		test_units_si_3<float>();
	}
}


template <typename T>
void test_units_si_4(void)
{
	using eagine::tagged_quantity;
	using namespace eagine::units;

	T t1 = get<T>();
	T cc1 = get<T>();

	tagged_quantity<T, second> qt1_s(t1);
	tagged_quantity<T, hertz> qf1_Hz(cc1/t1);
	tagged_quantity<T, kilohertz> qf2_kHz(qf1_Hz);

	BOOST_CHECK_CLOSE(
		value(qf1_Hz*qt1_s),
		cc1, 0.001
	);

	BOOST_CHECK_CLOSE(
		value(qf1_Hz)/1000,
		value(qf2_kHz), 0.001
	);

	BOOST_CHECK_CLOSE(
		value(qf2_kHz)*value(qt1_s),
		cc1/1000, 0.001
	);
}

BOOST_AUTO_TEST_CASE(units_si_4)
{
	for(int i=0; i<100; ++i)
	{
		test_units_si_4<float>();
	}
}


template <typename T>
void test_units_si_5(void)
{
	using eagine::tagged_quantity;
	using namespace eagine::units;

	T t1 = get<T>();
	T dc1 = get<T>();

	tagged_quantity<T, second> qt1_s(t1);
	tagged_quantity<T, becquerel> qr1_Bq(dc1/t1);
	tagged_quantity<T, megabecquerel> qr2_MBq(qr1_Bq);
	tagged_quantity<T, unit<number_of_decays, si>> qnod1(qr2_MBq*qt1_s);

	BOOST_CHECK_CLOSE(
		value(qr1_Bq*qt1_s),
		dc1, 0.001
	);

	BOOST_CHECK_CLOSE(
		value(qr1_Bq)/1000000,
		value(qr2_MBq), 0.001
	);

	BOOST_CHECK_CLOSE(
		value(qr2_MBq)*value(qt1_s),
		dc1/1000000, 0.001
	);

	BOOST_CHECK_CLOSE(
		value(qnod1),
		dc1, 0.001
	);
}

BOOST_AUTO_TEST_CASE(units_si_5)
{
	for(int i=0; i<100; ++i)
	{
		test_units_si_5<float>();
	}
}

template <typename T>
void test_units_si_6(void)
{
	using eagine::tagged_quantity;
	using namespace eagine::units;

	T l1 = get<T>();
	T t1 = get<T>();
	T I1 = get<T>();
	T E1 = get<T>();

	tagged_quantity<T, meter> ql1_m(l1);
	tagged_quantity<T, second> qt1_s(t1);
	tagged_quantity<T, hour> qt2_h(t1 / 3600);
	tagged_quantity<T, ampere> qI1_A(I1);
	tagged_quantity<T, coulomb> qQ1_C = qI1_A * qt1_s;
	tagged_quantity<T, kiloampere> qI1_kA = qQ1_C / qt2_h;
	tagged_quantity<T, milliampere> qI1_mA = qI1_A;
	tagged_quantity<T, joule> qE1_J(E1);
	tagged_quantity<T, volt> qU1_V(qE1_J / qQ1_C);
	tagged_quantity<T, watt> qP1_W(qU1_V * qI1_kA);
	tagged_quantity<T, millifarad> qC1_mF(qQ1_C / qU1_V);
	tagged_quantity<T, millisiemens> qG1_mS(qI1_mA / qU1_V);
	tagged_quantity<T, kiloohm> qR1_kO(qU1_V / qI1_mA);
	tagged_quantity<T, weber> qPhi1_Wb(qE1_J / qI1_kA);
	tagged_quantity<T, tesla> qB1_T(qPhi1_Wb / (ql1_m * ql1_m));
	tagged_quantity<T, millihenry> qL1_mH(qPhi1_Wb / qI1_kA);

	BOOST_CHECK_CLOSE(
		value(qI1_A)/1000,
		value(qI1_kA), 0.001
	);

	BOOST_CHECK_CLOSE(
		value(qI1_kA)*1000000,
		value(qI1_mA), 0.001
	);

	BOOST_CHECK_CLOSE(
		value(qE1_J)/value(qQ1_C),
		value(qU1_V), 0.001
	);

	BOOST_CHECK_CLOSE(
		value(qE1_J)/value(qt1_s),
		value(qP1_W), 0.001
	);

	BOOST_CHECK_CLOSE(
		1/value(qG1_mS),
		value(qR1_kO), 0.001
	);

	BOOST_CHECK_CLOSE(
		value(qt1_s)*value(qG1_mS),
		value(qC1_mF), 0.001
	);

	BOOST_CHECK_CLOSE(
		value(qt1_s)/value(qR1_kO),
		value(qC1_mF), 0.001
	);

	BOOST_CHECK_CLOSE(
		value(qU1_V)*value(qt1_s),
		value(qPhi1_Wb), 0.001
	);

	BOOST_CHECK_CLOSE(
		value(qE1_J)/value(qI1_A),
		value(qPhi1_Wb), 0.001
	);

	BOOST_CHECK_CLOSE(
		value(qU1_V)*value(qt1_s)/(value(ql1_m)*value(ql1_m)),
		value(qB1_T), 0.001
	);

	BOOST_CHECK_CLOSE(
		value(qPhi1_Wb)/value(qI1_kA),
		value(qL1_mH), 0.001
	);
}

BOOST_AUTO_TEST_CASE(units_si_6)
{
	for(int i=0; i<100; ++i)
	{
		test_units_si_6<float>();
	}
}

//TODO

BOOST_AUTO_TEST_SUITE_END()

#include "../unit_test_end.inl"
