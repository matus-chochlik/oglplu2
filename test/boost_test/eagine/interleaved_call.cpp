/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/interleaved_call.hpp>
#define BOOST_TEST_MODULE EAGINE_interleaved_call
#include "../unit_test_begin.inl"

BOOST_AUTO_TEST_SUITE(interleaved_call_tests)

static eagine::test_random_generator rg;

BOOST_AUTO_TEST_CASE(interleaved_call_1) {
    using namespace eagine;

    for(int i = 0; i < 100; ++i) {
        std::string s1, s2;
        const std::string sep = rg.get_string(1, 5);

        auto fn = interleaved_call(
          [&s1](const std::string& s) { s1.append(s); },
          [&s1, &sep]() { s1.append(sep); });

        for(int j = 0, n = rg.get_int(1, 100); j < n; ++j) {
            const std::string s = rg.get_string(1, 10);

            fn(s);

            if(j > 0) {
                s2.append(sep);
            }
            s2.append(s);
        }

        BOOST_CHECK_EQUAL(s1, s2);
    }
}

BOOST_AUTO_TEST_SUITE_END()

#include "../unit_test_end.inl"
