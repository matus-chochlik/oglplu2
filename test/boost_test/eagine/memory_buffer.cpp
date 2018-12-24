/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/memory/buffer.hpp>
#define BOOST_TEST_MODULE EAGINE_memory_buffer
#include "../unit_test_begin.inl"

BOOST_AUTO_TEST_SUITE(memory_buffer_tests)

static eagine::test_random_generator rg;

BOOST_AUTO_TEST_CASE(memory_buffer_0) {
    using namespace eagine;

    memory::buffer buf;

    BOOST_CHECK_EQUAL(buf.size(), 0);
    BOOST_CHECK_EQUAL(buf.capacity(), 0);

    memory::block blk = buf;

    BOOST_CHECK(!bool(blk));
    BOOST_CHECK(!blk);
    BOOST_CHECK(blk.empty());
    BOOST_CHECK(blk.size() == 0);
    BOOST_CHECK(blk.begin() == blk.end());
}

BOOST_AUTO_TEST_CASE(memory_buffer_1) {
    using namespace eagine;

    memory::buffer buf;

    int r = 0;

    for(int i = 0; i < 1000; ++i) {
        span_size_t s = span_size_t(r * r);

        buf.resize(s);

        BOOST_CHECK_EQUAL(buf.size(), s);
        BOOST_CHECK(buf.capacity() >= s);

        memory::block blk = buf;

        if(buf.size() > 0) {
            BOOST_CHECK(bool(blk));
            BOOST_CHECK(!!blk);
            BOOST_CHECK(!blk.empty());
            BOOST_CHECK(blk.begin() != blk.end());
            BOOST_CHECK_EQUAL(blk.size(), buf.size());
        } else {
            BOOST_CHECK(!bool(blk));
            BOOST_CHECK(!blk);
            BOOST_CHECK(blk.empty());
            BOOST_CHECK(blk.size() == 0);
            BOOST_CHECK(blk.begin() == blk.end());
        }

        r = rg.get_int(0, 1000);
    }
}

// TODO

BOOST_AUTO_TEST_SUITE_END()

#include "../unit_test_end.inl"
