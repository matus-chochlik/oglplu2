/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <eagine/vect/axis.hpp>
#define BOOST_TEST_MODULE EAGINE_vect_axis
#include "../unit_test_begin.inl"

BOOST_AUTO_TEST_SUITE(vect_axis_tests)

static eagine::test_random_generator rg;

template <typename T, int I, int N, bool V>
void test_vect_axis_apply_TINV() {
    for(int k = 0; k < 1000; ++k) {
        T a = rg.get_any<T>();

        typename eagine::vect::data<T, N, V>::type v =
          eagine::vect::axis<T, N, I, V>::apply(a);

        for(int i = 0; i < N; ++i) {
            BOOST_CHECK_EQUAL(v[i], T(i == I ? a : 0));
        }
    }
}

template <typename T, bool V>
void test_vect_axis_apply_TV() {
    test_vect_axis_apply_TINV<T, 0, 2, V>();
    test_vect_axis_apply_TINV<T, 1, 2, V>();
    test_vect_axis_apply_TINV<T, 2, 2, V>();

    test_vect_axis_apply_TINV<T, 0, 3, V>();
    test_vect_axis_apply_TINV<T, 1, 3, V>();
    test_vect_axis_apply_TINV<T, 2, 3, V>();
    test_vect_axis_apply_TINV<T, 3, 3, V>();

    test_vect_axis_apply_TINV<T, 0, 4, V>();
    test_vect_axis_apply_TINV<T, 1, 4, V>();
    test_vect_axis_apply_TINV<T, 2, 4, V>();
    test_vect_axis_apply_TINV<T, 3, 4, V>();
    test_vect_axis_apply_TINV<T, 4, 4, V>();

    test_vect_axis_apply_TINV<T, 0, 5, V>();
    test_vect_axis_apply_TINV<T, 1, 5, V>();
    test_vect_axis_apply_TINV<T, 2, 5, V>();
    test_vect_axis_apply_TINV<T, 3, 5, V>();
    test_vect_axis_apply_TINV<T, 4, 5, V>();
    test_vect_axis_apply_TINV<T, 5, 5, V>();

    test_vect_axis_apply_TINV<T, 0, 6, V>();
    test_vect_axis_apply_TINV<T, 1, 6, V>();
    test_vect_axis_apply_TINV<T, 2, 6, V>();
    test_vect_axis_apply_TINV<T, 3, 6, V>();
    test_vect_axis_apply_TINV<T, 4, 6, V>();
    test_vect_axis_apply_TINV<T, 5, 6, V>();
    test_vect_axis_apply_TINV<T, 6, 6, V>();

    test_vect_axis_apply_TINV<T, 0, 7, V>();
    test_vect_axis_apply_TINV<T, 1, 7, V>();
    test_vect_axis_apply_TINV<T, 2, 7, V>();
    test_vect_axis_apply_TINV<T, 3, 7, V>();
    test_vect_axis_apply_TINV<T, 4, 7, V>();
    test_vect_axis_apply_TINV<T, 5, 7, V>();
    test_vect_axis_apply_TINV<T, 6, 7, V>();
    test_vect_axis_apply_TINV<T, 7, 7, V>();

    test_vect_axis_apply_TINV<T, 0, 8, V>();
    test_vect_axis_apply_TINV<T, 1, 8, V>();
    test_vect_axis_apply_TINV<T, 2, 8, V>();
    test_vect_axis_apply_TINV<T, 3, 8, V>();
    test_vect_axis_apply_TINV<T, 4, 8, V>();
    test_vect_axis_apply_TINV<T, 5, 8, V>();
    test_vect_axis_apply_TINV<T, 6, 8, V>();
    test_vect_axis_apply_TINV<T, 7, 8, V>();
    test_vect_axis_apply_TINV<T, 8, 8, V>();
}

template <typename T>
void test_vect_axis_apply_T() {
    test_vect_axis_apply_TV<T, true>();
    test_vect_axis_apply_TV<T, false>();
}

BOOST_AUTO_TEST_CASE(vect_axis_apply) {
    test_vect_axis_apply_T<int>();
    test_vect_axis_apply_T<float>();
    test_vect_axis_apply_T<double>();
}

BOOST_AUTO_TEST_SUITE_END()

#include "../unit_test_end.inl"
