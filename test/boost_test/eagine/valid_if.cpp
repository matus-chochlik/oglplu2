/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/valid_if.hpp>
#define BOOST_TEST_MODULE EAGINE_valid_if
#include "../unit_test_begin.inl"

#include <eagine/type_identity.hpp>

BOOST_AUTO_TEST_SUITE(valid_if_tests)

static eagine::test_random_generator rg;

BOOST_AUTO_TEST_CASE(valid_if_not_zero_test) {
    using namespace eagine;

    type_identity<float> id;
    auto tw = [](float x) {
        return x * 2;
    };

    for(int i = 0; i < 1000; ++i) {
        int v = (rg.get_int(0, 9) == 0) ? 0 : rg.get_int(0, 1000);

        valid_if_not_zero<float> x(v);

        BOOST_CHECK_EQUAL(x.is_valid(), v != 0);
        BOOST_CHECK_EQUAL(bool(x), v != 0);
        BOOST_CHECK_EQUAL(!x, v == 0);

        BOOST_CHECK_EQUAL(x.value_or(v), v);
        if(x.is_valid()) {
            BOOST_CHECK_EQUAL(x.value(), v);
        }
        BOOST_CHECK_EQUAL(x.then(id).value_or(v), v);
        BOOST_CHECK_EQUAL(x.then(tw).value_or(v * 2), v * 2);
        BOOST_CHECK_EQUAL(x.is_valid(), x.then(id).is_valid());
    }
}

BOOST_AUTO_TEST_CASE(valid_if_not_test) {
    using namespace eagine;

    for(int i = 0; i < 1000; ++i) {
        int v = (rg.get_int(0, 9) == 0) ? 123 : rg.get_int(0, 1000);

        valid_if_not<int, 123> x(v);

        BOOST_CHECK_EQUAL(x.is_valid(), v != 123);
        BOOST_CHECK_EQUAL(bool(x), v != 123);
        BOOST_CHECK_EQUAL(!x, v == 123);

        BOOST_CHECK_EQUAL(x.value_or(v), v);
        if(x.is_valid()) {
            BOOST_CHECK_EQUAL(x.value(), v);
        }
    }
}

BOOST_AUTO_TEST_CASE(valid_if_greater_than_test) {
    using namespace eagine;

    for(int i = 0; i < 1000; ++i) {
        int v = (rg.get_int(0, 9) == 0) ? 123 : rg.get_int(0, 1000);

        valid_if_greater_than<int, 123> x(v);

        BOOST_CHECK_EQUAL(x.is_valid(), v > 123);
        BOOST_CHECK_EQUAL(bool(x), v > 123);
        BOOST_CHECK_EQUAL(!x, v <= 123);

        BOOST_CHECK_EQUAL(x.value_or(v), v);
        if(x.is_valid()) {
            BOOST_CHECK_EQUAL(x.value(), v);
        }
    }
}

BOOST_AUTO_TEST_CASE(valid_if_cmp_test_1) {
    using namespace eagine;

    for(int i = 0; i < 1000; ++i) {
        int v = (rg.get_int(0, 9) == 0) ? 123 : rg.get_int(0, 1000);

        valid_if_not_zero<int> x(v);

        if(v == 0) {
            BOOST_CHECK((x == 0).is(indeterminate));
            BOOST_CHECK((x != 0).is(indeterminate));
            BOOST_CHECK((x < 0).is(indeterminate));
            BOOST_CHECK((x > 0).is(indeterminate));
            BOOST_CHECK((x <= 0).is(indeterminate));
            BOOST_CHECK((x >= 0).is(indeterminate));
        } else {
            BOOST_CHECK((x == v));
            BOOST_CHECK(!(x == 0));
            BOOST_CHECK(!(x != v));
            BOOST_CHECK((x != 0));
            BOOST_CHECK(!(x < v));
            BOOST_CHECK((x < v + 1));
            BOOST_CHECK(!(x > v));
            BOOST_CHECK((x > v - 1));
            BOOST_CHECK((x <= v));
            BOOST_CHECK((x <= v + 1));
            BOOST_CHECK((x >= v));
            BOOST_CHECK((x >= v - 1));
        }
    }
}

BOOST_AUTO_TEST_CASE(valid_if_cmp_test_2) {
    using namespace eagine;

    for(int i = 0; i < 1000; ++i) {
        int v = rg.get_int(-10, 10);
        int w = rg.get_int(-10, 10);

        valid_if_greater_than<int, 0> x(v);
        valid_if_less_than<int, 9> y(w);

        if(!((v > 0) && (w < 9))) {
            BOOST_CHECK((x == y).is(indeterminate));
            BOOST_CHECK((x != y).is(indeterminate));
            BOOST_CHECK((x < y).is(indeterminate));
            BOOST_CHECK((x > y).is(indeterminate));
            BOOST_CHECK((x <= y).is(indeterminate));
            BOOST_CHECK((x >= y).is(indeterminate));
        } else {
            BOOST_CHECK_EQUAL(bool(x == y), v == w);
            BOOST_CHECK_EQUAL(bool(x != y), v != w);
            BOOST_CHECK_EQUAL(bool(x < y), v < w);
            BOOST_CHECK_EQUAL(bool(x > y), v > w);
            BOOST_CHECK_EQUAL(bool(x <= y), v <= w);
            BOOST_CHECK_EQUAL(bool(x >= y), v >= w);
        }
    }
}

// TODO

BOOST_AUTO_TEST_SUITE_END()

#include "../unit_test_end.inl"
