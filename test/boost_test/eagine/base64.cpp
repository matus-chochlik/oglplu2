/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/base64.hpp>
#define BOOST_TEST_MODULE EAGINE_biteset
#include "../unit_test_begin.inl"

#include <eagine/memory/span_algo.hpp>
#include <eagine/span.hpp>

BOOST_AUTO_TEST_SUITE(base64_tests)

static eagine::test_random_generator rg;

BOOST_AUTO_TEST_CASE(base64_trip) {
    using namespace eagine;

    for(int i = 0; i < 10000; ++i) {
        const auto orig = rg.get_string(0, 10000);
        std::vector<byte> enco;
        auto res = bool(base64_encode(view(orig), enco));
        BOOST_CHECK(res);
        if(res) {
            std::string deco;
            res = bool(base64_decode(view(enco), deco));
            BOOST_CHECK(res);
            if(res) {
                BOOST_CHECK_EQUAL(orig, deco);
            }
        }
    }
}

BOOST_AUTO_TEST_SUITE_END()

#include "../unit_test_end.inl"
