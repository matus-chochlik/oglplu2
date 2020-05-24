/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/multi_byte_seq.hpp>
#define BOOST_TEST_MODULE EAGINE_multi_byte_seq
#include "../unit_test_begin.inl"

#include <vector>

BOOST_AUTO_TEST_SUITE(multi_byte_seq_tests)

static eagine::test_random_generator rg;

BOOST_AUTO_TEST_CASE(multi_byte_seq_1) {
    using namespace eagine;

    std::vector<byte> bytes;

    mbs::code_point_t cp = 0, cp2;

    for(span_size_t l = 1; l <= 6; ++l) {

        bytes.resize(std_size(l));
        while(cp < mbs::max_code_point(l).value()) {

            BOOST_CHECK(mbs::encode_code_point(cp, cover(bytes)));
            BOOST_CHECK(
              mbs::is_valid_encoding(mbs::make_cbyte_span(view(bytes))));

            cp2 =
              mbs::decode_code_point(mbs::make_cbyte_span(view(bytes))).value();

            BOOST_CHECK_EQUAL(cp, cp2);

            cp +=
              rg.get<mbs::code_point_t>(1, mbs::code_point_t(l * l * l * l));
        }
    }
}

BOOST_AUTO_TEST_CASE(multi_byte_seq_2) {
    using namespace eagine;

    std::vector<mbs::code_point> cps, cps2;
    std::vector<byte> bytes;

    for(int i = 0; i < test_repeats(200, 10000); ++i) {

        std::size_t len = rg.get<std::size_t>(1, 100);
        cps.resize(len);

        for(mbs::code_point& cp : cps) {
            do {
                cp = rg.get_any<mbs::code_point_t>();
            } while(!cp.is_valid());
        }

        bytes.resize(std_size(mbs::encoding_bytes_required(view(cps)).value()));

        BOOST_CHECK(mbs::encode_code_points(view(cps), cover(bytes)));

        BOOST_ASSERT(mbs::is_valid_encoding(mbs::make_cbyte_span(view(bytes))));

        cps2.resize(std_size(
          mbs::decoding_code_points_required(mbs::make_cbyte_span(view(bytes)))
            .value()));

        BOOST_ASSERT(cps.size() == cps2.size());

        BOOST_CHECK(mbs::decode_code_points(
          mbs::make_cbyte_span(view(bytes)), cover(cps2)));

        BOOST_CHECK(are_equal(view(cps), view(cps2)));
    }
}

BOOST_AUTO_TEST_SUITE_END()

#include "../unit_test_end.inl"
