/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_enum_class
#include <boost/test/unit_test.hpp>

#include <eagine/enum_class.hpp>

namespace eagine {

struct ec_A
 : enum_class<ec_A, unsigned, 0, 0>
{ using enum_class<ec_A, unsigned, 0, 0>::enum_class; };

struct ec_B
 : enum_class<ec_B, unsigned, 0, 1>
{ using enum_class<ec_B, unsigned, 0, 1>::enum_class; };

struct ec_C
 : enum_class<ec_C, unsigned, 0, 2>
{ using enum_class<ec_C, unsigned, 0, 2>::enum_class; };

struct ec_D
 : enum_class<ec_D, unsigned, 0, 3>
{ using enum_class<ec_D, unsigned, 0, 3>::enum_class; };

static constexpr const enum_value<unsigned, mp_list<ec_A>> ev_1 = {1};
static constexpr const enum_value<unsigned, mp_list<ec_A, ec_B>> ev_2 = {2};
static constexpr const enum_value<unsigned, mp_list<ec_A, ec_B, ec_C>> ev_3 = {3};
static constexpr const enum_value<unsigned, mp_list<ec_B, ec_C, ec_D>> ev_4 = {4};
static constexpr const enum_value<unsigned, mp_list<ec_B, ec_D>> ev_5 = {5};
static constexpr const enum_value<unsigned, mp_list<ec_D>> ev_6 = {6};

} // namespace eagine

BOOST_AUTO_TEST_SUITE(enum_class_tests)

BOOST_AUTO_TEST_CASE(enum_class_1)
{
	using namespace eagine;

	ec_A a = ev_1;
	BOOST_CHECK((a == ev_1));
	BOOST_CHECK((a != ev_2));
	BOOST_CHECK((a != ev_3));
	a = ev_2;
	BOOST_CHECK((a != ev_1));
	BOOST_CHECK((a == ev_2));
	BOOST_CHECK((a != ev_3));
	a = ev_3;
	BOOST_CHECK((a != ev_1));
	BOOST_CHECK((a != ev_2));
	BOOST_CHECK((a == ev_3));

	ec_B b = ev_2;
	BOOST_CHECK((b == ev_2));
	BOOST_CHECK((b != ev_3));
	BOOST_CHECK((b != ev_4));
	BOOST_CHECK((b != ev_5));
	b = ev_3;
	BOOST_CHECK((b != ev_2));
	BOOST_CHECK((b == ev_3));
	BOOST_CHECK((b != ev_4));
	BOOST_CHECK((b != ev_5));
	b = ev_4;
	BOOST_CHECK((b != ev_2));
	BOOST_CHECK((b != ev_3));
	BOOST_CHECK((b == ev_4));
	BOOST_CHECK((b != ev_5));
	b = ev_5;
	BOOST_CHECK((b != ev_2));
	BOOST_CHECK((b != ev_3));
	BOOST_CHECK((b != ev_4));
	BOOST_CHECK((b == ev_5));

	ec_C c = ev_3;
	BOOST_CHECK((c == ev_3));
	BOOST_CHECK((c != ev_4));
	c = ev_4;
	BOOST_CHECK((c != ev_3));
	BOOST_CHECK((c == ev_4));

	ec_D d = ev_5;
	BOOST_CHECK((d == ev_5));
	BOOST_CHECK((d != ev_6));
	d = ev_6;
	BOOST_CHECK((d != ev_5));
	BOOST_CHECK((d == ev_6));
}

BOOST_AUTO_TEST_CASE(enum_class_2)
{
	using namespace eagine;

	ec_A a = ev_1;
	BOOST_CHECK(unsigned(a) == unsigned(ev_1));
	BOOST_CHECK(unsigned(a) != unsigned(ev_2));
	BOOST_CHECK(unsigned(a) != unsigned(ev_3));

	a = ev_2;
	BOOST_CHECK(unsigned(a) != unsigned(ev_1));
	BOOST_CHECK(unsigned(a) == unsigned(ev_2));
	BOOST_CHECK(unsigned(a) != unsigned(ev_3));

	a = ev_3;
	BOOST_CHECK(unsigned(a) != unsigned(ev_1));
	BOOST_CHECK(unsigned(a) != unsigned(ev_2));
	BOOST_CHECK(unsigned(a) == unsigned(ev_3));
}

BOOST_AUTO_TEST_CASE(enum_class_3)
{
	using namespace eagine;

	ec_A a = ev_1;

	any_enum_value<0> aev = a;

	(void)aev;
}

BOOST_AUTO_TEST_SUITE_END()
