/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_math_matrix_2
#include <boost/test/unit_test.hpp>
#include "../random.hpp"

#include <eagine/math/matrix.hpp>

BOOST_AUTO_TEST_SUITE(math_matrix_tests_3)

static eagine::test_random_generator rg;

template <typename T, int M, int N, int K, bool RM1, bool RM2, bool V>
void test_math_matrix_mult_TCRRMV(void)
{
	T d1[M*N];

	for(int i=0; i<(M*N); ++i)
	{
		d1[i] = rg.get<T>(0, 10000);
	}

	T d2[N*K];

	for(int i=0; i<(N*K); ++i)
	{
		d2[i] = rg.get<T>(0, 10000);
	}

	auto m1 = eagine::math::matrix<T, N, M, RM1, V>::from(d1, M*N);
	auto m2 = eagine::math::matrix<T, K, N, RM2, V>::from(d2, N*K);

	eagine::math::matrix<T, K, M, RM1, V> m = multiply(m1, m2);
	(void)m;

	for(int i=0; i<M; ++i)
	for(int j=0; j<K; ++j)
	{
		T e = T(0);

		for(int k=0; k<N; ++k)
		{
			e += row(m1, i)[k]*column(m2, j)[k];
		}

		BOOST_CHECK_EQUAL(get_cm(m, j, i), e);
		BOOST_CHECK_EQUAL(get_rm(m, i, j), e);
	}
}

template <typename T, bool RM1, bool RM2, bool V>
void test_math_matrix_mult_TRM1RM2V(void)
{
	test_math_matrix_mult_TCRRMV<T, 1, 1, 1, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 1, 1, 2, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 1, 1, 3, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 1, 1, 4, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 1, 1, 5, RM1, RM2, V>();

	test_math_matrix_mult_TCRRMV<T, 1, 2, 1, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 1, 2, 2, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 1, 2, 3, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 1, 2, 4, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 1, 2, 5, RM1, RM2, V>();

	test_math_matrix_mult_TCRRMV<T, 1, 3, 1, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 1, 3, 2, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 1, 3, 3, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 1, 3, 4, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 1, 3, 5, RM1, RM2, V>();

	test_math_matrix_mult_TCRRMV<T, 1, 4, 1, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 1, 4, 2, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 1, 4, 3, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 1, 4, 4, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 1, 4, 5, RM1, RM2, V>();

	test_math_matrix_mult_TCRRMV<T, 1, 5, 1, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 1, 5, 2, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 1, 5, 3, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 1, 5, 4, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 1, 5, 5, RM1, RM2, V>();

	test_math_matrix_mult_TCRRMV<T, 2, 1, 1, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 2, 1, 2, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 2, 1, 3, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 2, 1, 4, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 2, 1, 5, RM1, RM2, V>();

	test_math_matrix_mult_TCRRMV<T, 2, 2, 1, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 2, 2, 2, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 2, 2, 3, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 2, 2, 4, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 2, 2, 5, RM1, RM2, V>();

	test_math_matrix_mult_TCRRMV<T, 2, 3, 1, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 2, 3, 2, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 2, 3, 3, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 2, 3, 4, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 2, 3, 5, RM1, RM2, V>();

	test_math_matrix_mult_TCRRMV<T, 2, 4, 1, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 2, 4, 2, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 2, 4, 3, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 2, 4, 4, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 2, 4, 5, RM1, RM2, V>();

	test_math_matrix_mult_TCRRMV<T, 2, 5, 1, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 2, 5, 2, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 2, 5, 3, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 2, 5, 4, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 2, 5, 5, RM1, RM2, V>();

	test_math_matrix_mult_TCRRMV<T, 3, 1, 1, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 3, 1, 2, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 3, 1, 3, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 3, 1, 4, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 3, 1, 5, RM1, RM2, V>();

	test_math_matrix_mult_TCRRMV<T, 3, 2, 1, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 3, 2, 2, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 3, 2, 3, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 3, 2, 4, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 3, 2, 5, RM1, RM2, V>();

	test_math_matrix_mult_TCRRMV<T, 3, 3, 1, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 3, 3, 2, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 3, 3, 3, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 3, 3, 4, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 3, 3, 5, RM1, RM2, V>();

	test_math_matrix_mult_TCRRMV<T, 3, 4, 1, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 3, 4, 2, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 3, 4, 3, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 3, 4, 4, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 3, 4, 5, RM1, RM2, V>();

	test_math_matrix_mult_TCRRMV<T, 3, 5, 1, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 3, 5, 2, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 3, 5, 3, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 3, 5, 4, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 3, 5, 5, RM1, RM2, V>();

	test_math_matrix_mult_TCRRMV<T, 4, 1, 1, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 4, 1, 2, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 4, 1, 3, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 4, 1, 4, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 4, 1, 5, RM1, RM2, V>();

	test_math_matrix_mult_TCRRMV<T, 4, 2, 1, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 4, 2, 2, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 4, 2, 3, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 4, 2, 4, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 4, 2, 5, RM1, RM2, V>();

	test_math_matrix_mult_TCRRMV<T, 4, 3, 1, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 4, 3, 2, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 4, 3, 3, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 4, 3, 4, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 4, 3, 5, RM1, RM2, V>();

	test_math_matrix_mult_TCRRMV<T, 4, 4, 1, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 4, 4, 2, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 4, 4, 3, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 4, 4, 4, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 4, 4, 5, RM1, RM2, V>();

	test_math_matrix_mult_TCRRMV<T, 4, 5, 1, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 4, 5, 2, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 4, 5, 3, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 4, 5, 4, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 4, 5, 5, RM1, RM2, V>();

	test_math_matrix_mult_TCRRMV<T, 5, 1, 1, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 5, 1, 2, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 5, 1, 3, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 5, 1, 4, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 5, 1, 5, RM1, RM2, V>();

	test_math_matrix_mult_TCRRMV<T, 5, 2, 1, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 5, 2, 2, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 5, 2, 3, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 5, 2, 4, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 5, 2, 5, RM1, RM2, V>();

	test_math_matrix_mult_TCRRMV<T, 5, 3, 1, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 5, 3, 2, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 5, 3, 3, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 5, 3, 4, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 5, 3, 5, RM1, RM2, V>();

	test_math_matrix_mult_TCRRMV<T, 5, 4, 1, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 5, 4, 2, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 5, 4, 3, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 5, 4, 4, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 5, 4, 5, RM1, RM2, V>();

	test_math_matrix_mult_TCRRMV<T, 5, 5, 1, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 5, 5, 2, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 5, 5, 3, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 5, 5, 4, RM1, RM2, V>();
	test_math_matrix_mult_TCRRMV<T, 5, 5, 5, RM1, RM2, V>();
}

template <typename T, bool RM, bool V>
void test_math_matrix_mult_TRMV(void)
{
	test_math_matrix_mult_TRM1RM2V<T, RM, true, V>();
	test_math_matrix_mult_TRM1RM2V<T, RM,false, V>();
}

template <typename T>
void test_math_matrix_mult_T(void)
{
	test_math_matrix_mult_TRMV<T, true, true>();
	test_math_matrix_mult_TRMV<T, true,false>();
	test_math_matrix_mult_TRMV<T,false, true>();
	test_math_matrix_mult_TRMV<T,false,false>();
}

BOOST_AUTO_TEST_CASE(math_matrix_mult)
{
	test_math_matrix_mult_T<float>();
	test_math_matrix_mult_T<double>();
}

BOOST_AUTO_TEST_SUITE_END()
