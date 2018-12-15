/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/memory/block.hpp>
#define BOOST_TEST_MODULE EAGINE_memory_block
#include "../unit_test_begin.inl"

#include <vector>

BOOST_AUTO_TEST_SUITE(memory_block_tests)

static eagine::test_random_generator rg;

template <bool is_const>
void eagine_test_memory_block_0() {
    using namespace eagine;

    memory::basic_block<is_const> bmb;

    BOOST_CHECK(!bool(bmb));
    BOOST_CHECK(!bmb);
    BOOST_CHECK(bmb.empty());
    BOOST_CHECK(bmb.size() == 0);
    BOOST_CHECK(bmb.begin() == bmb.end());
}

BOOST_AUTO_TEST_CASE(memory_block_0) {
    using namespace eagine;

    eagine_test_memory_block_0<true>();
    eagine_test_memory_block_0<false>();
}

template <bool is_const>
void eagine_test_memory_block_1() {
    using namespace eagine;

    memory::basic_block<false> bmb1;
    memory::basic_block<is_const> bmb2 = bmb1;

    BOOST_CHECK(!bool(bmb2));
    BOOST_CHECK(!bmb2);
    BOOST_CHECK(bmb2.empty());
    BOOST_CHECK(bmb2.size() == 0);
    BOOST_CHECK(bmb2.begin() == bmb2.end());
}

BOOST_AUTO_TEST_CASE(memory_block_1) {
    using namespace eagine;

    eagine_test_memory_block_1<true>();
    eagine_test_memory_block_1<false>();
}

template <bool is_const>
void eagine_test_memory_block_2() {
    using namespace eagine;

    int x;

    memory::basic_block<is_const> bmb = as_bytes(coverOne(x));

    BOOST_CHECK(bool(bmb));
    BOOST_CHECK(!!bmb);
    BOOST_CHECK(!bmb.empty());
    BOOST_CHECK_EQUAL(bmb.size(), sizeof(x));
    BOOST_CHECK(bmb.begin() != bmb.end());

    span_size_t s = 0;

    for(byte b : bmb) {
        ++s;
        EAGINE_MAYBE_UNUSED(b);
    }

    BOOST_CHECK(bmb.size() == s);
}

BOOST_AUTO_TEST_CASE(memory_block_2) {
    using namespace eagine;

    eagine_test_memory_block_2<true>();
    eagine_test_memory_block_2<false>();
}

template <bool is_const>
void eagine_test_memory_block_3() {
    using namespace eagine;

    double x[42];

    memory::basic_block<is_const> bmb = as_bytes(cover(x));

    BOOST_CHECK(bool(bmb));
    BOOST_CHECK(!!bmb);
    BOOST_CHECK(!bmb.empty());
    BOOST_CHECK(bmb.size() == sizeof(x));
    BOOST_CHECK(bmb.begin() != bmb.end());

    span_size_t s = 0;

    for(byte b : bmb) {
        ++s;
        EAGINE_MAYBE_UNUSED(b);
    }

    BOOST_CHECK(bmb.size() == s);
}

BOOST_AUTO_TEST_CASE(memory_block_3) {
    using namespace eagine;

    eagine_test_memory_block_3<true>();
    eagine_test_memory_block_3<false>();
}

template <bool is_const>
void eagine_test_memory_block_4() {
    using namespace eagine;

    double x[42];

    memory::basic_block<is_const> bmb = as_bytes(memory::cover(x));

    BOOST_CHECK(bool(bmb));
    BOOST_CHECK(!!bmb);
    BOOST_CHECK(!bmb.empty());
    BOOST_CHECK(bmb.size() == sizeof(x));
    BOOST_CHECK(bmb.begin() != bmb.end());

    span_size_t s = 0;

    for(byte b : bmb) {
        ++s;
        EAGINE_MAYBE_UNUSED(b);
    }

    BOOST_CHECK(bmb.size() == s);
}

BOOST_AUTO_TEST_CASE(memory_block_4) {
    using namespace eagine;

    eagine_test_memory_block_4<true>();
    eagine_test_memory_block_4<false>();
}

template <bool is_const>
void eagine_test_memory_block_5() {
    using namespace eagine;

    byte x[256];

    for(byte& b : x) {
        b = rg.get<byte>(0x00, 0xFF);
    }

    memory::basic_block<is_const> bmb = as_bytes(memory::cover(x));

    BOOST_CHECK(bool(bmb));
    BOOST_CHECK(!!bmb);
    BOOST_CHECK(!bmb.empty());
    BOOST_ASSERT(bmb.size() == sizeof(x));

    for(span_size_t i = 0; i < bmb.size(); ++i) {
        BOOST_CHECK_EQUAL(bmb.data()[i], x[i]);
    }
}

BOOST_AUTO_TEST_CASE(memory_block_5) {
    using namespace eagine;

    eagine_test_memory_block_5<true>();
    eagine_test_memory_block_5<false>();
}

template <bool is_const>
void eagine_test_memory_block_6() {
    using namespace eagine;

    unsigned x[10];

    memory::basic_block<is_const> bmb1 = as_bytes(memory::cover(x));

    BOOST_CHECK(bool(bmb1));
    BOOST_CHECK(!!bmb1);
    BOOST_CHECK(!bmb1.empty());

    memory::basic_block<is_const> bmb2(std::move(bmb1));

    BOOST_CHECK(!bmb2.empty());

    memory::basic_block<is_const> bmb3;

    BOOST_CHECK(bmb3.empty());

    bmb3 = std::move(bmb2);

    BOOST_CHECK(!bmb3.empty());

    memory::basic_block<is_const> bmb4 = as_bytes(cover(x));

    BOOST_CHECK((are_equal(bmb1, bmb2)));
    BOOST_CHECK((are_equal(bmb3, bmb4)));
}

BOOST_AUTO_TEST_CASE(memory_block_6) {
    using namespace eagine;

    eagine_test_memory_block_6<true>();
    eagine_test_memory_block_6<false>();
}

template <typename T>
void eagine_test_memory_block_7() {
    using namespace eagine;

    std::vector<unsigned char> x(rg.get<std::size_t>(100, 1000));

    memory::block b(x.data(), span_size(x.size()));

    span<T> s = eagine::memory::accomodate<T>(b);

    BOOST_CHECK_EQUAL(s.size(), x.size() / sizeof(T));
}

BOOST_AUTO_TEST_CASE(memory_block_7) {
    for(int i = 0; i < 100; ++i) {
        eagine_test_memory_block_7<char>();
        eagine_test_memory_block_7<short>();
        eagine_test_memory_block_7<float>();
        eagine_test_memory_block_7<int>();
        eagine_test_memory_block_7<long>();
        eagine_test_memory_block_7<double>();
    }
}

template <typename T>
void eagine_test_memory_block_8() {
    using namespace eagine;

    std::vector<T> x(rg.get<std::size_t>(100, 1000));

    memory::block b = as_bytes(eagine::memory::cover(x));

    BOOST_CHECK_EQUAL(b.size(), x.size() * sizeof(T));
}

BOOST_AUTO_TEST_CASE(memory_block_8) {
    for(int i = 0; i < 100; ++i) {
        eagine_test_memory_block_8<char>();
        eagine_test_memory_block_8<short>();
        eagine_test_memory_block_8<float>();
        eagine_test_memory_block_8<int>();
        eagine_test_memory_block_8<long>();
        eagine_test_memory_block_8<double>();
    }
}

// TODO

BOOST_AUTO_TEST_SUITE_END()

#include "../unit_test_end.inl"
