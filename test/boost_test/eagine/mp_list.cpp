/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/mp_list.hpp>
#define BOOST_TEST_MODULE EAGINE_mp_list
#include "../unit_test_begin.inl"

struct type_A {};
struct type_B {};
struct type_C {};
struct type_D {};

BOOST_AUTO_TEST_SUITE(mp_list_tests)

BOOST_AUTO_TEST_CASE(mp_list_contains) {
    using namespace eagine;
    using lABC = mp_list<type_A, type_B, type_C>;
    using lDCB = mp_list<type_D, type_C, type_B>;

    BOOST_CHECK((mp_contains_v<lABC, type_A>));
    BOOST_CHECK((mp_contains_v<lABC, type_B>));
    BOOST_CHECK((mp_contains_v<lABC, type_C>));
    BOOST_CHECK((!mp_contains_v<lABC, type_D>));

    BOOST_CHECK((mp_contains_v<lDCB, type_D>));
    BOOST_CHECK((mp_contains_v<lDCB, type_C>));
    BOOST_CHECK((mp_contains_v<lDCB, type_B>));
    BOOST_CHECK((!mp_contain_vs<lDCB, type_A>));
}

BOOST_AUTO_TEST_CASE(mp_list_1) {
    using namespace eagine;
    using lABC = mp_list<type_A, type_B, type_C>;
    using lDCB = mp_list<type_D, type_C, type_B>;

    using lBC = mp_union_t<lABC, lDCB>;

    BOOST_CHECK((!mp_contains_v<lBC, type_A>));
    BOOST_CHECK((mp_contains_v<lBC, type_B>));
    BOOST_CHECK((mp_contains_v<lBC, type_C>));
    BOOST_CHECK((!mp_contains_v<lBC, type_D>));
}

BOOST_AUTO_TEST_SUITE_END()

#include "../unit_test_end.inl"
