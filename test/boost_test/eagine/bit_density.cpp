/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/bit_density.hpp>
#define BOOST_TEST_MODULE EAGINE_biteset
#include "../unit_test_begin.inl"

#include <eagine/memory/span_algo.hpp>
#include <eagine/span.hpp>

BOOST_AUTO_TEST_SUITE(bit_density_tests)

static eagine::test_random_generator rg;

BOOST_AUTO_TEST_CASE(bit_density_length_trip) {
    using namespace eagine;

    for(int i = 0; i < 1000; ++i) {
        for(span_size_t bits = 1; bits <= byte_bits(); ++bits) {

            const auto orig_size = rg.get<span_size_t>(0, 10000);
            const auto thin_size = dissolved_bits_length(orig_size, bits);
            const auto comp_size = concentrated_bits_length(thin_size, bits);

            BOOST_CHECK(thin_size >= 0);
            BOOST_CHECK(comp_size - orig_size >= 0);
            BOOST_CHECK(comp_size - orig_size <= 1);
        }
    }
}

BOOST_AUTO_TEST_CASE(bit_density_trip) {
    using namespace eagine;

    std::vector<byte> orig;
    std::vector<byte> thin;
    std::vector<byte> comp;
    bool res = false;

    for(int i = 0; i < 1000; ++i) {
        orig.resize(rg.get<std::size_t>(0, 10000));
        rg.fill(orig);
        for(span_size_t bits = 1; bits <= byte_bits(); ++bits) {
            thin.resize(std::size_t(
              dissolved_bits_length(span_size_t(orig.size()), bits)));

            span_size_t inp = 0;
            span_size_t out = 0;

            res = do_dissolve_bits(
              make_span_getter(inp, view(orig)),
              make_span_putter(out, cover(thin)),
              bits);

            BOOST_CHECK(res);
            if(res) {
                comp.resize(std::size_t(
                  concentrated_bits_length(span_size_t(thin.size()), bits)));

                inp = 0;
                out = 0;

                res = do_concentrate_bits(
                  make_span_getter(inp, view(thin)),
                  make_span_putter(out, cover(comp)),
                  bits);
                BOOST_CHECK(res);
                if(res) {
                    BOOST_CHECK(are_equal(view(orig), head(view(comp), out)));
                }
            }
        }
    }
}

BOOST_AUTO_TEST_SUITE_END()

#include "../unit_test_end.inl"
