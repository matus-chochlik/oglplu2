/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_units_scaled_unit
#include <boost/test/unit_test.hpp>

#include <eagine/units/scaled_unit.hpp>
#include <eagine/units/dimension.hpp>
#include <cstdlib>

namespace eagine {
namespace units {
namespace base {

template <typename BD>
struct mock_unit
 : unit<BD, mock_unit<BD>>
{ };

} // namespace base

struct mock_system
{
	template <typename BaseDim>
	struct base_unit;
};

template <typename BD>
struct mock_system::base_unit : base::mock_unit<BD> { };

} // namespace units
} // namespace eagine

BOOST_AUTO_TEST_SUITE(units_scaled_unit_test)

template <template <class, class, class> class Tester>
void do_units_arith_tests(void)
{
	using namespace eagine::units;

	base::for_each_dim(Tester<scales::one, scales::one, mock_system>());
	base::for_each_dim(Tester<scales::one, scales::kilo, mock_system>());
	base::for_each_dim(Tester<scales::kilo, scales::milli, mock_system>());
}

template <typename Sc1, typename Sc2, typename System>
struct units_scaled_unit_add_tester
{
	template <typename BD>
	void operator()(BD) const
	{
		using namespace eagine::units;

		typedef dimension<BD, 1> D;

		typedef typename System::template base_unit<BD>::type BU;

		typedef unit<D, System> U;

		typedef scaled_dim_unit<
			D,
			bits::unit_scales<
				bits::uni_sca<BU, Sc1>,
				eagine::nothing_t
			>, System
		> S1U;

		typedef scaled_dim_unit<
			D,
			bits::unit_scales<
				bits::uni_sca<BU, Sc2>,
				eagine::nothing_t
			>, System
		> S2U;

		U a, b;
		S1U s1a, s1b;
		S2U s2b;

		U ca1b = a + s1b;
		(void)ca1b;

		U c1ab = s1a + b;
		(void)c1ab;

		S1U s1c = s1a + s1b;
		(void)s1c;

		auto s12c = s1a + s2b;
		(void)s12c;
	}
};

BOOST_AUTO_TEST_CASE(units_scaled_unit_add)
{
	do_units_arith_tests<units_scaled_unit_add_tester>();
}

template <typename Sc1, typename Sc2, typename System>
struct units_scaled_unit_sub_tester
{
	template <typename BD>
	void operator()(BD) const
	{
		using namespace eagine::units;

		typedef dimension<BD, 1> D;

		typedef typename System::template base_unit<BD>::type BU;

		typedef unit<D, System> U;

		typedef scaled_dim_unit<
			D,
			bits::unit_scales<
				bits::uni_sca<BU, Sc1>,
				eagine::nothing_t
			>, System
		> S1U;

		typedef scaled_dim_unit<
			D,
			bits::unit_scales<
				bits::uni_sca<BU, Sc2>,
				eagine::nothing_t
			>, System
		> S2U;

		U a, b;
		S1U s1a, s1b;
		S2U s2b;

		U ca1b = a - s1b;
		(void)ca1b;

		U c1ab = s1a - b;
		(void)c1ab;

		S1U s1c = s1a - s1b;
		(void)s1c;

		auto s12c = s1a - s2b;
		(void)s12c;
	}
};

BOOST_AUTO_TEST_CASE(units_scaled_unit_sub)
{
	using namespace eagine::units;

	do_units_arith_tests<units_scaled_unit_sub_tester>();
}

template <typename BD1>
struct units_scaled_unit_mul_tester
{
template <typename Sc1, typename Sc2, typename System>
struct impl
{
	template <typename BD2>
	void operator()(BD2) const
	{
		using namespace eagine::units;

		typedef dimension<BD1, 1> D1;
		typedef dimension<BD2, 1> D2;

		typedef typename System::template base_unit<BD1>::type BU1;
		typedef typename System::template base_unit<BD2>::type BU2;

		typedef unit<D1, System> U1;
		typedef unit<D2, System> U2;

		typedef scaled_dim_unit<
			D1,
			bits::unit_scales<
				bits::uni_sca<BU1, Sc1>,
				eagine::nothing_t
			>, System
		> S1U1;

		typedef scaled_dim_unit<
			D2,
			bits::unit_scales<
				bits::uni_sca<BU2, Sc2>,
				eagine::nothing_t
			>, System
		> S2U2;

		U1 a;
		U2 b;
		S1U1 s1a, s1b;
		S2U2 s2b;

		auto ca1b = a * s1b;
		(void)ca1b;

		auto c1ab = s1a * b;
		(void)c1ab;

		auto s1c = s1a * s1b;
		(void)s1c;

		auto s12c = s1a * s2b;
		(void)s12c;
	}
};
};

struct units_scaled_unit_mul_hlp_tester
{
	template <typename BD>
	void operator()(BD) const
	{
		using namespace eagine::units;

		do_units_arith_tests<units_scaled_unit_mul_tester<BD>
			::template impl
		>();
	}
};

BOOST_AUTO_TEST_CASE(units_scaled_unit_mul)
{
	using namespace eagine::units;

	base::for_each_dim(units_scaled_unit_mul_hlp_tester());
}

template <typename BD1>
struct units_scaled_unit_div_tester
{
template <typename Sc1, typename Sc2, typename System>
struct impl
{
	template <typename BD2>
	void operator()(BD2) const
	{
		using namespace eagine::units;

		typedef dimension<BD1, 1> D1;
		typedef dimension<BD2, 1> D2;

		typedef typename System::template base_unit<BD1>::type BU1;
		typedef typename System::template base_unit<BD2>::type BU2;

		typedef unit<D1, System> U1;
		typedef unit<D2, System> U2;

		typedef scaled_dim_unit<
			D1,
			bits::unit_scales<
				bits::uni_sca<BU1, Sc1>,
				eagine::nothing_t
			>, System
		> S1U1;

		typedef scaled_dim_unit<
			D2,
			bits::unit_scales<
				bits::uni_sca<BU2, Sc2>,
				eagine::nothing_t
			>, System
		> S2U2;

		U1 a;
		U2 b;
		S1U1 s1a, s1b;
		S2U2 s2b;

		auto ca1b = a / s1b;
		(void)ca1b;

		auto c1ab = s1a / b;
		(void)c1ab;

		auto s1c = s1a / s1b;
		(void)s1c;

		auto s12c = s1a / s2b;
		(void)s12c;
	}
};
};

struct units_scaled_unit_div_hlp_tester
{
	template <typename BD>
	void operator()(BD) const
	{
		using namespace eagine::units;

		do_units_arith_tests<units_scaled_unit_div_tester<BD>
			::template impl
		>();
	}
};

BOOST_AUTO_TEST_CASE(units_scaled_unit_div)
{
	using namespace eagine::units;

	base::for_each_dim(units_scaled_unit_div_hlp_tester());
}


//TODO

BOOST_AUTO_TEST_SUITE_END()
