/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/identity.hpp>
#define BOOST_TEST_MODULE EAGINE_identity
#include "../unit_test_begin.inl"

BOOST_AUTO_TEST_SUITE(identity_tests)

static eagine::test_random_generator rg;

BOOST_AUTO_TEST_CASE(identity_1) {
    using namespace eagine;

    for(int k = 0; k < 1000; ++k) {
        identity<int> i;
        int r = rg.get_any<int>();

        BOOST_CHECK_EQUAL(i(r), r);
    }
}

BOOST_AUTO_TEST_SUITE_END()

#include "../unit_test_end.inl"
