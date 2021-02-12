/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <eagine/zip_iterator.hpp>
#define BOOST_TEST_MODULE EAGINE_zip_iterator
#include "../unit_test_begin.inl"

#include <array>
#include <vector>

BOOST_AUTO_TEST_SUITE(zip_iterator_tests)

static eagine::test_random_generator rg;

BOOST_AUTO_TEST_CASE(zip_iterator_1) {
    using namespace eagine;

    std::vector<int> v1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> v2{0, 1, 4, 9, 16, 25, 36, 49, 64, 81};

    auto i = zip_iters(v1.begin(), v2.begin());
    auto e = zip_iters(v1.end(), v2.end());

    int k = 0;

    while(i != e) {
        BOOST_CHECK(!(i == e));
        BOOST_CHECK_EQUAL(std::get<0>(*i), k);
        BOOST_CHECK_EQUAL(std::get<1>(*i), k * k);
        ++i;
        ++k;
    }
    BOOST_CHECK(!(i != e));
}

BOOST_AUTO_TEST_CASE(zip_iterator_2) {
    using namespace eagine;

    std::vector<int> v1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::array<int, 10> a1{{0, 1, 4, 9, 16, 25, 36, 49, 64, 81}};

    auto i = zip_iters(v1.begin(), a1.begin());
    auto e = zip_iters(v1.end(), a1.end());

    int k = 0;

    while(i != e) {
        BOOST_CHECK(!(i == e));
        BOOST_CHECK_EQUAL(std::get<0>(*i), k);
        BOOST_CHECK_EQUAL(std::get<1>(*i), k * k);
        ++i;
        ++k;
    }
    BOOST_CHECK(!(i != e));
}

BOOST_AUTO_TEST_CASE(zip_range_1) {
    using namespace eagine;

    std::vector<int> v1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::array<int, 10> a1{{0, 1, 4, 9, 16, 25, 36, 49, 64, 81}};

    for(auto t : zip_ranges(v1, a1)) {
        BOOST_CHECK_EQUAL(std::get<0>(t) * std::get<0>(t), std::get<1>(t));
    }
}

BOOST_AUTO_TEST_CASE(zip_range_2) {
    using namespace eagine;

    for(int i = 0; i < 100; ++i) {

        std::vector<float> v1(rg.get_std_size(10, 100));
        std::vector<int> v2(v1.size());
        std::vector<short> v3(v1.size());

        rg.fill(v1, -100.f, 100.f);

        for(auto t : zip_ranges(v1, v2, v3)) {
            std::get<1>(t) = int(std::get<0>(t));
            std::get<2>(t) = std::get<1>(t) % 4;
        }

        for(auto t : zip_ranges(v1, v2, v3)) {
            BOOST_CHECK_EQUAL(int(std::get<0>(t)), std::get<1>(t));
            BOOST_CHECK_EQUAL(std::get<1>(t) % 4, std::get<2>(t));
        }
    }
}

BOOST_AUTO_TEST_CASE(zip_range_3) {
    using namespace eagine;

    for(int i = 0; i < 100; ++i) {

        std::vector<float> v1(rg.get_std_size(10, 100));
        std::vector<int> v2(v1.size());
        std::vector<short> v3(v1.size());

        rg.fill(v1, -100.f, 100.f);

        zip_ranges(v1, v2, v3).for_each([](float& e1, int& e2, short& e3) {
            e2 = int(e1);
            e3 = e2 % 4;
        });

        zip_ranges(v1, v2, v3).for_each([](float& e1, int& e2, short& e3) {
            BOOST_CHECK_EQUAL(int(e1), e2);
            BOOST_CHECK_EQUAL(e2 % 4, e3);
        });
    }
}

BOOST_AUTO_TEST_SUITE_END()

#include "../unit_test_end.inl"
