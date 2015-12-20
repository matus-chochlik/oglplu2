/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_bitfield
#include <boost/test/unit_test.hpp>

#include <eagine/bitfield.hpp>

namespace eagine {

enum class test_ec
{
	test_ev1 = 1 << 0,
	test_ev2 = 1 << 1,
	test_ev3 = 1 << 2,
	test_ev4 = 1 << 3,
	test_ev5 = 1 << 4
};

} // namespace eagine

BOOST_AUTO_TEST_SUITE(bitfield_test)

BOOST_AUTO_TEST_CASE(bitfield_test_0)
{
	using namespace eagine;

	bitfield<test_ec> bf0;

	BOOST_CHECK(!bool(bf0));
	BOOST_CHECK(!bf0);

	BOOST_CHECK(!bf0.has(test_ec::test_ev1));
	BOOST_CHECK(!bf0.has(test_ec::test_ev2));
	BOOST_CHECK(!bf0.has(test_ec::test_ev3));
	BOOST_CHECK(!bf0.has(test_ec::test_ev4));
	BOOST_CHECK(!bf0.has(test_ec::test_ev5));

	bitfield<test_ec> bfc = bf0;

	BOOST_CHECK(bf0 == bfc);
	BOOST_CHECK(!(bf0 != bfc));
}

BOOST_AUTO_TEST_CASE(bitfield_test_1)
{
	using namespace eagine;

	bitfield<test_ec> bf1(test_ec::test_ev3);

	BOOST_CHECK(bool(bf1));
	BOOST_CHECK(!!bf1);

	BOOST_CHECK(!bf1.has(test_ec::test_ev1));
	BOOST_CHECK(!bf1.has(test_ec::test_ev2));
	BOOST_CHECK( bf1.has(test_ec::test_ev3));
	BOOST_CHECK(!bf1.has(test_ec::test_ev4));
	BOOST_CHECK(!bf1.has(test_ec::test_ev5));

	bitfield<test_ec> bf2(test_ec::test_ev1, test_ec::test_ev5);

	BOOST_CHECK( bf2.has(test_ec::test_ev1));
	BOOST_CHECK(!bf2.has(test_ec::test_ev2));
	BOOST_CHECK(!bf2.has(test_ec::test_ev3));
	BOOST_CHECK(!bf2.has(test_ec::test_ev4));
	BOOST_CHECK( bf2.has(test_ec::test_ev5));

	bitfield<test_ec> bf3 = bf2 | test_ec::test_ev3;

	BOOST_CHECK( bf3.has(test_ec::test_ev1));
	BOOST_CHECK(!bf3.has(test_ec::test_ev2));
	BOOST_CHECK( bf3.has(test_ec::test_ev3));
	BOOST_CHECK(!bf3.has(test_ec::test_ev4));
	BOOST_CHECK( bf3.has(test_ec::test_ev5));

	BOOST_CHECK(!(bf1 == bf2));
	BOOST_CHECK(!(bf1 == bf3));
	BOOST_CHECK(bf1 != bf2);
	BOOST_CHECK(bf1 != bf3);

	bitfield<test_ec> bf4 = bf1 | bf2;

	BOOST_CHECK( bf4.has(test_ec::test_ev1));
	BOOST_CHECK(!bf4.has(test_ec::test_ev2));
	BOOST_CHECK( bf4.has(test_ec::test_ev3));
	BOOST_CHECK(!bf4.has(test_ec::test_ev4));
	BOOST_CHECK( bf4.has(test_ec::test_ev5));

	BOOST_CHECK(!bool(bf1 & bf2));
	BOOST_CHECK(!(bf1 & bf2));

	bitfield<test_ec> bf5 = bf1 & bf2;

	BOOST_CHECK(!bf5.has(test_ec::test_ev1));
	BOOST_CHECK(!bf5.has(test_ec::test_ev2));
	BOOST_CHECK(!bf5.has(test_ec::test_ev3));
	BOOST_CHECK(!bf5.has(test_ec::test_ev4));
	BOOST_CHECK(!bf5.has(test_ec::test_ev5));

	BOOST_CHECK(bool(bf1 & bf3));
	BOOST_CHECK(!!(bf1 & bf3));

	bitfield<test_ec> bf6 = bf1 & bf3;

	BOOST_CHECK(!bf6.has(test_ec::test_ev1));
	BOOST_CHECK(!bf6.has(test_ec::test_ev2));
	BOOST_CHECK( bf6.has(test_ec::test_ev3));
	BOOST_CHECK(!bf6.has(test_ec::test_ev4));
	BOOST_CHECK(!bf6.has(test_ec::test_ev5));
}

BOOST_AUTO_TEST_CASE(bitfield_test_2)
{
	using namespace eagine;

	bitfield<test_ec> bf0;

	BOOST_CHECK(!bf0.has(test_ec::test_ev1));
	BOOST_CHECK(!bf0.has(test_ec::test_ev2));
	BOOST_CHECK(!bf0.has(test_ec::test_ev3));
	BOOST_CHECK(!bf0.has(test_ec::test_ev4));
	BOOST_CHECK(!bf0.has(test_ec::test_ev5));

	bf0 |= test_ec::test_ev3;

	BOOST_CHECK(!bf0.has(test_ec::test_ev1));
	BOOST_CHECK(!bf0.has(test_ec::test_ev2));
	BOOST_CHECK( bf0.has(test_ec::test_ev3));
	BOOST_CHECK(!bf0.has(test_ec::test_ev4));
	BOOST_CHECK(!bf0.has(test_ec::test_ev5));

	bf0 |= test_ec::test_ev1;

	BOOST_CHECK( bf0.has(test_ec::test_ev1));
	BOOST_CHECK(!bf0.has(test_ec::test_ev2));
	BOOST_CHECK( bf0.has(test_ec::test_ev3));
	BOOST_CHECK(!bf0.has(test_ec::test_ev4));
	BOOST_CHECK(!bf0.has(test_ec::test_ev5));

	bf0 |= test_ec::test_ev5;

	BOOST_CHECK( bf0.has(test_ec::test_ev1));
	BOOST_CHECK(!bf0.has(test_ec::test_ev2));
	BOOST_CHECK( bf0.has(test_ec::test_ev3));
	BOOST_CHECK(!bf0.has(test_ec::test_ev4));
	BOOST_CHECK( bf0.has(test_ec::test_ev5));

	bf0 |= test_ec::test_ev2;
	bf0 |= test_ec::test_ev4;

	BOOST_CHECK( bf0.has(test_ec::test_ev1));
	BOOST_CHECK( bf0.has(test_ec::test_ev2));
	BOOST_CHECK( bf0.has(test_ec::test_ev3));
	BOOST_CHECK( bf0.has(test_ec::test_ev4));
	BOOST_CHECK( bf0.has(test_ec::test_ev5));

	bf0 &= test_ec::test_ev3;

	BOOST_CHECK(!bf0.has(test_ec::test_ev1));
	BOOST_CHECK(!bf0.has(test_ec::test_ev2));
	BOOST_CHECK( bf0.has(test_ec::test_ev3));
	BOOST_CHECK(!bf0.has(test_ec::test_ev4));
	BOOST_CHECK(!bf0.has(test_ec::test_ev5));
}

BOOST_AUTO_TEST_CASE(bitfield_test_3)
{
	using namespace eagine;

	bitfield<test_ec> bf0(test_ec::test_ev2, test_ec::test_ev4);

	BOOST_CHECK(!bf0.has(test_ec::test_ev1));
	BOOST_CHECK( bf0.has(test_ec::test_ev2));
	BOOST_CHECK(!bf0.has(test_ec::test_ev3));
	BOOST_CHECK( bf0.has(test_ec::test_ev4));
	BOOST_CHECK(!bf0.has(test_ec::test_ev5));

	bitfield<test_ec> bf1 = ~bf0;

	BOOST_CHECK( bf1.has(test_ec::test_ev1));
	BOOST_CHECK(!bf1.has(test_ec::test_ev2));
	BOOST_CHECK( bf1.has(test_ec::test_ev3));
	BOOST_CHECK(!bf1.has(test_ec::test_ev4));
	BOOST_CHECK( bf1.has(test_ec::test_ev5));

	bitfield<test_ec> bfo = bf0 | bf1;

	BOOST_CHECK( bfo.has(test_ec::test_ev1));
	BOOST_CHECK( bfo.has(test_ec::test_ev2));
	BOOST_CHECK( bfo.has(test_ec::test_ev3));
	BOOST_CHECK( bfo.has(test_ec::test_ev4));
	BOOST_CHECK( bfo.has(test_ec::test_ev5));

	bitfield<test_ec> bfa = bf0 & bf1;

	BOOST_CHECK(!bfa.has(test_ec::test_ev1));
	BOOST_CHECK(!bfa.has(test_ec::test_ev2));
	BOOST_CHECK(!bfa.has(test_ec::test_ev3));
	BOOST_CHECK(!bfa.has(test_ec::test_ev4));
	BOOST_CHECK(!bfa.has(test_ec::test_ev5));

}

BOOST_AUTO_TEST_SUITE_END()
