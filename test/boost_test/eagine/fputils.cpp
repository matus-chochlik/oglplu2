/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/serialize/fputils.hpp>
#define BOOST_TEST_MODULE EAGINE_fputils
#include "../unit_test_begin.inl"

BOOST_AUTO_TEST_SUITE(fputils_tests)

static eagine::test_random_generator rg;

template <typename F>
void test_fputils_1() {
    using namespace eagine::fputils;

    const auto pnan = F(0) / F(0);
    const auto pinf = F(1) / F(0);
    const auto ninf = -F(1) / F(0);

    BOOST_CHECK(std::isnan(compose<F>(decompose(pnan))));
    BOOST_CHECK(std::isinf(compose<F>(decompose(pinf))));
    BOOST_CHECK(std::isinf(compose<F>(decompose(ninf))));
}

BOOST_AUTO_TEST_CASE(fputils_1) {
    test_fputils_1<float>();
    test_fputils_1<double>();
}

template <typename F>
void test_fputils_2() {
    using namespace eagine;

    for(int i = 0; i < test_repeats(1000, 1000000); ++i) {
        const auto f = rg.get<F>(-F(1000), F(1000));
        const auto dfp = fputils::decompose(f);
        const auto g = fputils::compose<F>(dfp);

        BOOST_CHECK_CLOSE(f, g, 0.0001);
    }
}

BOOST_AUTO_TEST_CASE(fputils_2) {
    test_fputils_2<float>();
    test_fputils_2<double>();
    test_fputils_2<long double>();
}

template <typename F>
void test_fputils_3() {
    using namespace eagine;

    for(int i = 0; i < test_repeats(1000, 1000000); ++i) {
        const auto f = rg.get_any<F>();
        const auto dfp = fputils::decompose(f);
        const auto g = fputils::compose<F>(dfp);

        BOOST_CHECK_CLOSE(f, g, 0.01);
    }
}

BOOST_AUTO_TEST_CASE(fputils_3) {
    test_fputils_3<float>();
    test_fputils_3<double>();
}

BOOST_AUTO_TEST_SUITE_END()

#include "../unit_test_end.inl"
