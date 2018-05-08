/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/vect/abs.hpp>
#define BOOST_TEST_MODULE EAGINE_vect_abs
#include "../unit_test_begin.inl"

#include <cmath>

BOOST_AUTO_TEST_SUITE(vect_abs_tests)

static eagine::test_random_generator rg;

template <typename T, int N, bool V>
void
test_vect_abs_TNV_1(void) {
    for(int k = 0; k < 1000; ++k) {
	T a[N];

	typename eagine::vect::data<T, N, V>::type u = {};

	for(int i = 0; i < N; ++i) {
	    a[i] = rg.get<T>(-1000, 1000);
	    u[i] = a[i];
	}

	typename eagine::vect::data<T, N, V>::type v =
	  eagine::vect::abs<T, N, V>::apply(u);

	for(int i = 0; i < N; ++i) {
	    using std::abs;
	    BOOST_CHECK(!(v[i] < T(0)));
	    BOOST_CHECK_EQUAL(v[i], abs(a[i]));
	    BOOST_CHECK_EQUAL(v[i], abs(u[i]));
	}
    }
}

template <typename T, bool V>
void
test_vect_abs_TV_1(void) {
    test_vect_abs_TNV_1<T, 2, V>();
    test_vect_abs_TNV_1<T, 3, V>();
    test_vect_abs_TNV_1<T, 4, V>();
    test_vect_abs_TNV_1<T, 5, V>();
    test_vect_abs_TNV_1<T, 7, V>();
    test_vect_abs_TNV_1<T, 8, V>();
    test_vect_abs_TNV_1<T, 11, V>();
    test_vect_abs_TNV_1<T, 15, V>();
    test_vect_abs_TNV_1<T, 19, V>();
}

template <typename T>
void
test_vect_abs_T_1(void) {
    test_vect_abs_TV_1<T, true>();
    test_vect_abs_TV_1<T, false>();
}

BOOST_AUTO_TEST_CASE(vect_data_abs_TNV_1) {
    test_vect_abs_T_1<int>();
    test_vect_abs_T_1<float>();
    test_vect_abs_T_1<double>();
}

BOOST_AUTO_TEST_SUITE_END()

#include "../unit_test_end.inl"
