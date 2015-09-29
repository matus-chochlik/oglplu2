/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_mp_list
#include <boost/test/unit_test.hpp>

#include <eagine/mp_list.hpp>

struct type_A { };
struct type_B { };
struct type_C { };
struct type_D { };

BOOST_AUTO_TEST_SUITE(mp_list)

BOOST_AUTO_TEST_CASE(mp_list_contains)
{
	using namespace eagine;
	typedef eagine::mp_list<type_A, type_B, type_C> lABC;
	typedef eagine::mp_list<type_D, type_C, type_B> lDCB;

	BOOST_CHECK(( mp_contains<lABC, type_A>::value));
	BOOST_CHECK(( mp_contains<lABC, type_B>::value));
	BOOST_CHECK(( mp_contains<lABC, type_C>::value));
	BOOST_CHECK((!mp_contains<lABC, type_D>::value));

	BOOST_CHECK(( mp_contains<lDCB, type_D>::value));
	BOOST_CHECK(( mp_contains<lDCB, type_C>::value));
	BOOST_CHECK(( mp_contains<lDCB, type_B>::value));
	BOOST_CHECK((!mp_contains<lDCB, type_A>::value));
}

BOOST_AUTO_TEST_CASE(mp_list_1)
{
	using namespace eagine;
	typedef eagine::mp_list<type_A, type_B, type_C> lABC;
	typedef eagine::mp_list<type_D, type_C, type_B> lDCB;

	typedef mp_union_t<lABC, lDCB> lBC;

	BOOST_CHECK((!mp_contains<lBC, type_A>::value));
	BOOST_CHECK(( mp_contains<lBC, type_B>::value));
	BOOST_CHECK(( mp_contains<lBC, type_C>::value));
	BOOST_CHECK((!mp_contains<lBC, type_D>::value));
}

BOOST_AUTO_TEST_SUITE_END()
