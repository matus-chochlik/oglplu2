/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/buffer_size.hpp>
#define BOOST_TEST_MODULE EAGINE_buffer_size
#include "../unit_test_begin.inl"

#include <eagine/span.hpp>

BOOST_AUTO_TEST_SUITE(buffer_size_tests)

static eagine::test_random_generator rg;

static inline auto get_n() {
    return rg.get<eagine::span_size_t>(0, 1000000);
}

template <typename T>
static inline auto sz() {
    return eagine::span_size_t(sizeof(T));
}

BOOST_AUTO_TEST_CASE(buffer_size_1) {
    using namespace eagine;

    buffer_size<int> s0;
    BOOST_CHECK_EQUAL(int(s0), 0);
    BOOST_CHECK_EQUAL(long(s0), 0l);
    BOOST_CHECK_EQUAL(std::size_t(s0), 0u);

    buffer_size<int> s1(12345);
    BOOST_CHECK_EQUAL(int(s1), 12345);
    BOOST_CHECK_EQUAL(long(s1), 12345l);
    BOOST_CHECK_EQUAL(std::size_t(s1), 12345u);
}

BOOST_AUTO_TEST_CASE(buffer_size_2) {
    using namespace eagine;
    span_size_t n;
    {
        n = get_n();
        buffer_size<int> st(identity<char>(), n);
        BOOST_CHECK_EQUAL(st.get(), int(sz<char>() * n));
        BOOST_CHECK_EQUAL(int(st), int(sz<char>() * n));
    }
    {
        n = get_n();
        buffer_size<int> st(identity<short>(), n);
        BOOST_CHECK_EQUAL(st.get(), int(sz<short>() * n));
        BOOST_CHECK_EQUAL(int(st), int(sz<short>() * n));
    }
    {
        n = get_n();
        buffer_size<int> st(identity<unsigned>(), n);
        BOOST_CHECK_EQUAL(st.get(), int(sz<unsigned>() * n));
        BOOST_CHECK_EQUAL(int(st), int(sz<unsigned>() * n));
    }
    {
        n = get_n();
        buffer_size<int> st(identity<long>(), n);
        BOOST_CHECK_EQUAL(st.get(), int(sz<long>() * n));
        BOOST_CHECK_EQUAL(int(st), int(sz<long>() * n));
    }
    {
        n = get_n();
        buffer_size<int> st(identity<float>(), n);
        BOOST_CHECK_EQUAL(st.get(), int(sz<float>() * n));
        BOOST_CHECK_EQUAL(int(st), int(sz<float>() * n));
    }
}

BOOST_AUTO_TEST_CASE(buffer_size_3) {
    using namespace eagine;
    span_size_t n;
    {
        n = get_n();
        buffer_size<unsigned> st(identity<char>(), n);
        BOOST_CHECK_EQUAL(unsigned(st), unsigned(sz<char>() * n));
    }
    {
        n = get_n();
        buffer_size<unsigned> st(identity<short>(), n);
        BOOST_CHECK_EQUAL(unsigned(st), unsigned(sz<short>() * n));
    }
    {
        n = get_n();
        buffer_size<unsigned> st(identity<int>(), n);
        BOOST_CHECK_EQUAL(unsigned(st), unsigned(sz<int>() * n));
    }
    {
        n = get_n();
        buffer_size<unsigned> st(identity<long>(), n);
        BOOST_CHECK_EQUAL(unsigned(st), unsigned(sz<long>() * n));
    }
    {
        n = get_n();
        buffer_size<unsigned> st(identity<float>(), n);
        BOOST_CHECK_EQUAL(unsigned(st), unsigned(sz<float>() * n));
    }
}

BOOST_AUTO_TEST_CASE(buffer_size_4) {
    using namespace eagine;
    {
        const char bla[4] = "bla";
        buffer_size<int> st(make_span(bla));
        BOOST_CHECK_EQUAL(st.get(), int(sz<char>() * 4));
        BOOST_CHECK_EQUAL(int(st), int(sz<char>() * 4));
    }
    {
        const unsigned short csv[7] = {1, 2, 3, 4, 5, 6, 7};
        buffer_size<long> st(make_span(csv));
        BOOST_CHECK_EQUAL(st.get(), long(sz<short>() * 7));
        BOOST_CHECK_EQUAL(long(st), long(sz<short>() * 7));
    }
    {
        const int civ[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        buffer_size<unsigned> st(make_span(civ));
        BOOST_CHECK_EQUAL(st.get(), unsigned(sz<int>() * 10));
        BOOST_CHECK_EQUAL(unsigned(st), unsigned(sz<int>() * 10));
    }
}

// TODO

BOOST_AUTO_TEST_SUITE_END()

#include "../unit_test_end.inl"
