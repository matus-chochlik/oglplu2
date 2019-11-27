/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/bit_density.hpp>
#define BOOST_TEST_MODULE EAGINE_biteset
#include "../unit_test_begin.inl"

BOOST_AUTO_TEST_SUITE(bit_density_tests)

static eagine::test_random_generator rg;

BOOST_AUTO_TEST_CASE(bit_density_length_trip) {
    using namespace eagine;

    for(int i; i < 1000; ++i) {
        const auto bits = rg.get<span_size_t>(1, byte_bits());

        const auto orig_size = rg.get<span_size_t>(0, 10000);
        const auto thin_size = dissolved_bits_length(orig_size, bits);
        const auto comp_size = concentrated_bits_length(thin_size, bits);

        BOOST_CHECK_EQUAL(orig_size, comp_size);
    }
}

BOOST_AUTO_TEST_SUITE_END()

#include "../unit_test_end.inl"
