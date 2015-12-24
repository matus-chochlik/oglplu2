/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_units_dimension
#include <boost/test/unit_test.hpp>

#include <eagine/units/dimension.hpp>
#include <eagine/units/dimensionless.hpp>
#include <type_traits>

BOOST_AUTO_TEST_SUITE(units_dimension_test)

template <typename Dimension, typename BaseDim, typename TestedBD>
void test_units_dimension_pow1_d_bd(void)
{
	BOOST_CHECK_EQUAL(get_pow_of_dim(
		TestedBD(),
		Dimension() 
	), (std::is_same<BaseDim, TestedBD>::value?1:0));
}

template <typename TestedBD>
void test_units_dimension_pow1(void)
{
	using namespace eagine;

	test_units_dimension_pow1_d_bd<
		units::angle,
		units::base::angle,
		TestedBD
	>();
	test_units_dimension_pow1_d_bd<
		units::solid_angle,
		units::base::solid_angle,
		TestedBD
	>();
	test_units_dimension_pow1_d_bd<
		units::length,
		units::base::length,
		TestedBD
	>();
	test_units_dimension_pow1_d_bd<
		units::mass,
		units::base::mass,
		TestedBD
	>();
	test_units_dimension_pow1_d_bd<
		units::time,
		units::base::time,
		TestedBD
	>();
	test_units_dimension_pow1_d_bd<
		units::temperature,
		units::base::temperature,
		TestedBD
	>();
	test_units_dimension_pow1_d_bd<
		units::electric_current,
		units::base::electric_current,
		TestedBD
	>();
	test_units_dimension_pow1_d_bd<
		units::number_of_cycles,
		units::base::number_of_cycles,
		TestedBD
	>();
	test_units_dimension_pow1_d_bd<
		units::number_of_decays,
		units::base::number_of_decays,
		TestedBD
	>();
	test_units_dimension_pow1_d_bd<
		units::luminous_intensity,
		units::base::luminous_intensity,
		TestedBD
	>();
	test_units_dimension_pow1_d_bd<
		units::amount_of_substance,
		units::base::amount_of_substance,
		TestedBD
	>();
}

BOOST_AUTO_TEST_CASE(units_dimension_power1)
{
	using namespace eagine::units;

	test_units_dimension_pow1<base::angle>();
	test_units_dimension_pow1<base::solid_angle>();
	test_units_dimension_pow1<base::length>();
	test_units_dimension_pow1<base::mass>();
	test_units_dimension_pow1<base::time>();
	test_units_dimension_pow1<base::temperature>();
	test_units_dimension_pow1<base::electric_current>();
	test_units_dimension_pow1<base::number_of_cycles>();
	test_units_dimension_pow1<base::number_of_decays>();
	test_units_dimension_pow1<base::luminous_intensity>();
	test_units_dimension_pow1<base::amount_of_substance>();
}

//TODO

BOOST_AUTO_TEST_SUITE_END()
