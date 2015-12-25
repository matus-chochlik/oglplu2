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

#include <eagine/units/dim/area.hpp>
#include <eagine/units/dim/volume.hpp>
#include <eagine/units/dim/velocity.hpp>
#include <eagine/units/dim/acceleration.hpp>
#include <eagine/units/dim/momentum.hpp>

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

struct units_dimension_pow_tester
{
	template <typename TestedBD>
	void operator()(TestedBD)
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
};

BOOST_AUTO_TEST_CASE(units_fundamental_dimension_power1)
{
	using namespace eagine::units;

	base::for_each_dim(units_dimension_pow_tester());
};

struct area_base_dim_tester
{
	template <typename BD>
	void operator()(BD) const
	{
		BOOST_CHECK(
			get_pow_of_dim(BD(), eagine::units::area()) ==
			get_pow_of_dim(BD(), eagine::units::length())+
			get_pow_of_dim(BD(), eagine::units::length())
		);
	}
};

BOOST_AUTO_TEST_CASE(unit_dimensions_area)
{
	using namespace eagine::units;

	base::for_each_dim(area_base_dim_tester());
}

struct volume_base_dim_tester
{
	template <typename BD>
	void operator()(BD) const
	{
		BOOST_CHECK(
			get_pow_of_dim(BD(), eagine::units::volume()) ==
			get_pow_of_dim(BD(), eagine::units::length())+
			get_pow_of_dim(BD(), eagine::units::length())+
			get_pow_of_dim(BD(), eagine::units::length())
		);
	}
};

BOOST_AUTO_TEST_CASE(unit_dimensions_volume)
{
	using namespace eagine::units;

	base::for_each_dim(volume_base_dim_tester());
}

struct velocity_base_dim_tester
{
	template <typename BD>
	void operator()(BD) const
	{
		BOOST_CHECK(
			get_pow_of_dim(BD(), eagine::units::velocity()) ==
			get_pow_of_dim(BD(), eagine::units::length())-
			get_pow_of_dim(BD(), eagine::units::time())
		);
	}
};

BOOST_AUTO_TEST_CASE(unit_dimensions_velocity)
{
	using namespace eagine::units;

	base::for_each_dim(velocity_base_dim_tester());
}

struct acceleration_base_dim_tester
{
	template <typename BD>
	void operator()(BD) const
	{
		BOOST_CHECK(
			get_pow_of_dim(BD(), eagine::units::acceleration()) ==
			get_pow_of_dim(BD(), eagine::units::velocity())-
			get_pow_of_dim(BD(), eagine::units::time())
		);
	}
};

BOOST_AUTO_TEST_CASE(unit_dimensions_acceleration)
{
	using namespace eagine::units;

	base::for_each_dim(acceleration_base_dim_tester());
}

struct momentum_base_dim_tester
{
	template <typename BD>
	void operator()(BD) const
	{
		BOOST_CHECK(
			get_pow_of_dim(BD(), eagine::units::momentum()) ==
			get_pow_of_dim(BD(), eagine::units::velocity())+
			get_pow_of_dim(BD(), eagine::units::mass())
		);
	}
};

BOOST_AUTO_TEST_CASE(unit_dimensions_momentum)
{
	using namespace eagine::units;

	base::for_each_dim(momentum_base_dim_tester());
}

//TODO

BOOST_AUTO_TEST_SUITE_END()
