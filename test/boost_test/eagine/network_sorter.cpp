/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/network_sorter.hpp>
#define BOOST_TEST_MODULE EAGINE_network_sorter
#include "../unit_test_begin.inl"

#include <algorithm>

BOOST_AUTO_TEST_SUITE(network_sorter_tests)

static eagine::test_random_generator rg;

template <typename T, std::size_t N, typename Cmp>
void test_network_sorter_1_TNC(int n) {
    using namespace eagine;

    for(int i = 0; i < n; ++i) {
        std::array<T, N> a;
        for(T& e : a) {
            e = rg.get_any<T>();
        }

        network_sorter<T, N, Cmp> s{a};
        const std::array<T, N>& r = s();

        BOOST_CHECK(std::is_sorted(r.begin(), r.end(), Cmp()));
    }

    for(int i = 0; i < n; ++i) {
        std::array<T, N> a;
        for(T& e : a) {
            e = rg.get_any<T>();
        }

        network_sort<N, Cmp>(cover(a));

        BOOST_CHECK(std::is_sorted(a.begin(), a.end(), Cmp()));
    }
}

template <typename T, std::size_t N>
void test_network_sorter_1_TN(int n) {
    test_network_sorter_1_TNC<T, N, std::less<T>>(n);
    test_network_sorter_1_TNC<T, N, std::greater<T>>(n);
}

template <std::size_t N>
void test_network_sorter_1_N(int n) {
    test_network_sorter_1_TN<int, N>(n);
    test_network_sorter_1_TN<float, N>(n);
    test_network_sorter_1_TN<double, N>(n);
    test_network_sorter_1_TN<unsigned, N>(n);
}

BOOST_AUTO_TEST_CASE(network_sorter_1_1) {
    test_network_sorter_1_N<1>(eagine::test_repeats(250, 1000));
    test_network_sorter_1_N<2>(eagine::test_repeats(250, 1000));
    test_network_sorter_1_N<3>(eagine::test_repeats(250, 1000));
    test_network_sorter_1_N<4>(eagine::test_repeats(250, 1000));
    test_network_sorter_1_N<5>(eagine::test_repeats(250, 1000));
    test_network_sorter_1_N<6>(eagine::test_repeats(250, 1000));
    test_network_sorter_1_N<7>(eagine::test_repeats(200, 900));
    test_network_sorter_1_N<8>(eagine::test_repeats(200, 800));
    test_network_sorter_1_N<9>(eagine::test_repeats(200, 700));
    // TODO
}

BOOST_AUTO_TEST_CASE(network_sorter_1_2) {
    test_network_sorter_1_N<10>(eagine::test_repeats(170, 700));
    test_network_sorter_1_N<11>(eagine::test_repeats(170, 700));
    test_network_sorter_1_N<12>(eagine::test_repeats(170, 700));
    test_network_sorter_1_N<14>(eagine::test_repeats(150, 650));
    test_network_sorter_1_N<16>(eagine::test_repeats(150, 600));
    test_network_sorter_1_N<32>(eagine::test_repeats(100, 400));
    test_network_sorter_1_N<64>(eagine::test_repeats(100, 200));
    // TODO
}

BOOST_AUTO_TEST_CASE(network_sorter_1_3) {
    test_network_sorter_1_N<128>(eagine::test_repeats(40, 100));
    test_network_sorter_1_N<256>(eagine::test_repeats(30, 70));
    // TODO
}

BOOST_AUTO_TEST_SUITE_END()

#include "../unit_test_end.inl"
