/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/math/matrix.hpp>
#include <utility>
#define BOOST_TEST_MODULE EAGINE_math_matrix_2
#include "../unit_test_begin.inl"

BOOST_AUTO_TEST_SUITE(math_matrix_tests_2)

template <typename T, int N, bool V, int K, int... I>
static eagine::vect::data_t<T, N, V> get_test_math_matrix_vec(
  std::integral_constant<int, K>, std::integer_sequence<int, I...>) {
    return eagine::vect::data_t<T, N, V>{T(K + I)...};
}

template <typename T, int C, int R, bool RM, bool V, int... J, int... I>
void test_math_matrix_init_TCRRMVJI(
  std::integer_sequence<int, J...>, std::integer_sequence<int, I...>) {
    using M = eagine::math::matrix<T, C, R, RM, V>;

    M m = {{get_test_math_matrix_vec < T,
            RM ? C : R,
            V > (std::integral_constant<int, J>(),
                 std::integer_sequence<int, I...>())...}};

    for(int i = 0; i < (RM ? R : C); ++i)
        for(int j = 0; j < (RM ? C : R); ++j) {
            BOOST_CHECK_EQUAL(m[i][j], i + j);
        }
}

template <typename T, int C, int R, bool RM, bool V>
void test_math_matrix_init_TCRRMV() {
    test_math_matrix_init_TCRRMVJI<T, C, R, RM, V>(
      std::make_integer_sequence < int,
      RM ? R : C > (),
      std::make_integer_sequence < int,
      RM ? C : R > ());
}

template <typename T, bool RM, bool V>
void test_math_matrix_init_TRMV() {
    test_math_matrix_init_TCRRMV<T, 1, 1, RM, V>();
    test_math_matrix_init_TCRRMV<T, 1, 2, RM, V>();
    test_math_matrix_init_TCRRMV<T, 1, 3, RM, V>();
    test_math_matrix_init_TCRRMV<T, 1, 4, RM, V>();
    test_math_matrix_init_TCRRMV<T, 1, 5, RM, V>();

    test_math_matrix_init_TCRRMV<T, 2, 1, RM, V>();
    test_math_matrix_init_TCRRMV<T, 2, 2, RM, V>();
    test_math_matrix_init_TCRRMV<T, 2, 3, RM, V>();
    test_math_matrix_init_TCRRMV<T, 2, 4, RM, V>();
    test_math_matrix_init_TCRRMV<T, 2, 5, RM, V>();

    test_math_matrix_init_TCRRMV<T, 3, 1, RM, V>();
    test_math_matrix_init_TCRRMV<T, 3, 2, RM, V>();
    test_math_matrix_init_TCRRMV<T, 3, 3, RM, V>();
    test_math_matrix_init_TCRRMV<T, 3, 4, RM, V>();
    test_math_matrix_init_TCRRMV<T, 3, 5, RM, V>();

    test_math_matrix_init_TCRRMV<T, 4, 1, RM, V>();
    test_math_matrix_init_TCRRMV<T, 4, 2, RM, V>();
    test_math_matrix_init_TCRRMV<T, 4, 3, RM, V>();
    test_math_matrix_init_TCRRMV<T, 4, 4, RM, V>();
    test_math_matrix_init_TCRRMV<T, 4, 5, RM, V>();

    test_math_matrix_init_TCRRMV<T, 5, 1, RM, V>();
    test_math_matrix_init_TCRRMV<T, 5, 2, RM, V>();
    test_math_matrix_init_TCRRMV<T, 5, 3, RM, V>();
    test_math_matrix_init_TCRRMV<T, 5, 4, RM, V>();
    test_math_matrix_init_TCRRMV<T, 5, 5, RM, V>();
}

template <typename T>
void test_math_matrix_init_T() {
    test_math_matrix_init_TRMV<T, true, true>();
    test_math_matrix_init_TRMV<T, true, false>();
    test_math_matrix_init_TRMV<T, false, true>();
    test_math_matrix_init_TRMV<T, false, false>();
}

BOOST_AUTO_TEST_CASE(math_matrix_default_ctr) {
    test_math_matrix_init_T<float>();
    test_math_matrix_init_T<double>();
}

BOOST_AUTO_TEST_SUITE_END()

#include "../unit_test_end.inl"
