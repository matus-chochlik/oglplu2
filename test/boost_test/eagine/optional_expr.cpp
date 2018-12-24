/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/optional_expr.hpp>
#include <eagine/valid_if/not_zero.hpp>
#define BOOST_TEST_MODULE EAGINE_optional_expr
#include "../unit_test_begin.inl"

BOOST_AUTO_TEST_SUITE(optional_expr_tests)

static eagine::test_random_generator rg;

BOOST_AUTO_TEST_CASE(optional_expr_div_test) {
    using namespace eagine;

    for(int i = 0; i < 1000; ++i) {
        int n = rg.get_int(0, 100);
        int d = rg.get_int(0, 10);

        auto r = n / nonzero(d);

        BOOST_CHECK_EQUAL(r.is_valid(), d != 0);
        BOOST_CHECK_EQUAL(bool(r), d != 0);
        BOOST_CHECK_EQUAL(!r, d == 0);

        BOOST_CHECK_EQUAL(r.value_or(n), d ? n / d : n);
        if(r.is_valid()) {
            BOOST_CHECK_EQUAL(r.value(), n / d);
        }
    }
}

// TODO

BOOST_AUTO_TEST_SUITE_END()

#include "../unit_test_end.inl"
