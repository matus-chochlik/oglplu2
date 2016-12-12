/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_vect_shuffle
#include <boost/test/unit_test.hpp>
#include "../random.hpp"

#include <eagine/vect/shuffle.hpp>
#include <array>

BOOST_AUTO_TEST_SUITE(vect_shuffle_tests)

static eagine::test_random_generator rg;

template <typename T, int N, bool V, int ... I>
void test_vect_shuffle_TNVI(void)
{
	std::array<int, N> n = {{I...}};

	for(int k=0; k<10; ++k)
	{
		T a[N];

		typename eagine::vect::data<T, N, V>::type v = {};
		typename eagine::vect::shuffle_mask<I...> m = {};

		for(int i=0; i<N; ++i)
		{
			a[i] = rg.get_any<T>();
			v[i] = a[i];
		}

		typename eagine::vect::data<T, N, V>::type u =
			eagine::vect::shuffle<T, N, V>::apply(v, m);

		for(int i=0; i<N; ++i)
		{
			BOOST_CHECK_EQUAL(u[i], a[n[size_t(i)]]);
		}
	}
}

template <typename T, bool V>
void test_vect_shuffle_TV(void)
{
	test_vect_shuffle_TNVI<T, 2, V, 0, 0>();
	test_vect_shuffle_TNVI<T, 2, V, 0, 1>();
	test_vect_shuffle_TNVI<T, 2, V, 1, 0>();
	test_vect_shuffle_TNVI<T, 2, V, 1, 1>();

	test_vect_shuffle_TNVI<T, 3, V, 0, 1, 2>();
	test_vect_shuffle_TNVI<T, 3, V, 1, 0, 2>();
	test_vect_shuffle_TNVI<T, 3, V, 1, 2, 0>();
	test_vect_shuffle_TNVI<T, 3, V, 0, 2, 1>();
	test_vect_shuffle_TNVI<T, 3, V, 2, 0, 1>();
	test_vect_shuffle_TNVI<T, 3, V, 2, 1, 0>();

	test_vect_shuffle_TNVI<T, 4, V, 0, 1, 2, 3>();
	test_vect_shuffle_TNVI<T, 4, V, 1, 0, 2, 3>();
	test_vect_shuffle_TNVI<T, 4, V, 1, 2, 0, 3>();
	test_vect_shuffle_TNVI<T, 4, V, 1, 2, 3, 0>();
	test_vect_shuffle_TNVI<T, 4, V, 0, 2, 1, 3>();
	test_vect_shuffle_TNVI<T, 4, V, 2, 0, 1, 3>();
	test_vect_shuffle_TNVI<T, 4, V, 2, 1, 0, 3>();
	test_vect_shuffle_TNVI<T, 4, V, 2, 1, 3, 0>();
	test_vect_shuffle_TNVI<T, 4, V, 0, 2, 3, 1>();
	test_vect_shuffle_TNVI<T, 4, V, 2, 0, 3, 1>();
	test_vect_shuffle_TNVI<T, 4, V, 2, 3, 0, 1>();
	test_vect_shuffle_TNVI<T, 4, V, 2, 3, 1, 0>();
	test_vect_shuffle_TNVI<T, 4, V, 0, 1, 3, 2>();
	test_vect_shuffle_TNVI<T, 4, V, 1, 0, 3, 2>();
	test_vect_shuffle_TNVI<T, 4, V, 1, 3, 0, 2>();
	test_vect_shuffle_TNVI<T, 4, V, 1, 3, 2, 0>();
	test_vect_shuffle_TNVI<T, 4, V, 0, 3, 1, 2>();
	test_vect_shuffle_TNVI<T, 4, V, 3, 0, 1, 2>();
	test_vect_shuffle_TNVI<T, 4, V, 3, 1, 0, 2>();
	test_vect_shuffle_TNVI<T, 4, V, 3, 1, 2, 0>();
	test_vect_shuffle_TNVI<T, 4, V, 0, 3, 2, 1>();
	test_vect_shuffle_TNVI<T, 4, V, 3, 0, 2, 1>();
	test_vect_shuffle_TNVI<T, 4, V, 3, 2, 0, 1>();
	test_vect_shuffle_TNVI<T, 4, V, 3, 2, 1, 0>();

	test_vect_shuffle_TNVI<T, 5, V, 0, 1, 2, 3, 4>();
	test_vect_shuffle_TNVI<T, 5, V, 1, 0, 2, 3, 4>();
	test_vect_shuffle_TNVI<T, 5, V, 1, 2, 0, 3, 4>();
	test_vect_shuffle_TNVI<T, 5, V, 1, 2, 3, 0, 4>();
	test_vect_shuffle_TNVI<T, 5, V, 1, 2, 3, 4, 0>();
	test_vect_shuffle_TNVI<T, 5, V, 0, 2, 1, 3, 4>();
	test_vect_shuffle_TNVI<T, 5, V, 2, 0, 1, 3, 4>();
	test_vect_shuffle_TNVI<T, 5, V, 2, 1, 0, 3, 4>();
	test_vect_shuffle_TNVI<T, 5, V, 2, 1, 3, 0, 4>();
	test_vect_shuffle_TNVI<T, 5, V, 2, 1, 3, 4, 0>();
	test_vect_shuffle_TNVI<T, 5, V, 0, 2, 3, 1, 4>();
	test_vect_shuffle_TNVI<T, 5, V, 2, 0, 3, 1, 4>();
	test_vect_shuffle_TNVI<T, 5, V, 2, 3, 0, 1, 4>();
	test_vect_shuffle_TNVI<T, 5, V, 2, 3, 1, 0, 4>();
	test_vect_shuffle_TNVI<T, 5, V, 2, 3, 1, 4, 0>();
	test_vect_shuffle_TNVI<T, 5, V, 0, 2, 3, 4, 1>();
	test_vect_shuffle_TNVI<T, 5, V, 2, 0, 3, 4, 1>();
	test_vect_shuffle_TNVI<T, 5, V, 2, 3, 0, 4, 1>();
	test_vect_shuffle_TNVI<T, 5, V, 2, 3, 4, 0, 1>();
	test_vect_shuffle_TNVI<T, 5, V, 2, 3, 4, 1, 0>();
	test_vect_shuffle_TNVI<T, 5, V, 0, 1, 3, 2, 4>();
	test_vect_shuffle_TNVI<T, 5, V, 1, 0, 3, 2, 4>();
	test_vect_shuffle_TNVI<T, 5, V, 1, 3, 0, 2, 4>();
	test_vect_shuffle_TNVI<T, 5, V, 1, 3, 2, 0, 4>();
	test_vect_shuffle_TNVI<T, 5, V, 1, 3, 2, 4, 0>();
	test_vect_shuffle_TNVI<T, 5, V, 0, 3, 1, 2, 4>();
	test_vect_shuffle_TNVI<T, 5, V, 3, 0, 1, 2, 4>();
	test_vect_shuffle_TNVI<T, 5, V, 3, 1, 0, 2, 4>();
	test_vect_shuffle_TNVI<T, 5, V, 3, 1, 2, 0, 4>();
	test_vect_shuffle_TNVI<T, 5, V, 3, 1, 2, 4, 0>();
	test_vect_shuffle_TNVI<T, 5, V, 0, 3, 2, 1, 4>();
	test_vect_shuffle_TNVI<T, 5, V, 3, 0, 2, 1, 4>();
	test_vect_shuffle_TNVI<T, 5, V, 3, 2, 0, 1, 4>();
	test_vect_shuffle_TNVI<T, 5, V, 3, 2, 1, 0, 4>();
	test_vect_shuffle_TNVI<T, 5, V, 3, 2, 1, 4, 0>();
	test_vect_shuffle_TNVI<T, 5, V, 0, 3, 2, 4, 1>();
	test_vect_shuffle_TNVI<T, 5, V, 3, 0, 2, 4, 1>();
	test_vect_shuffle_TNVI<T, 5, V, 3, 2, 0, 4, 1>();
	test_vect_shuffle_TNVI<T, 5, V, 3, 2, 4, 0, 1>();
	test_vect_shuffle_TNVI<T, 5, V, 3, 2, 4, 1, 0>();
	test_vect_shuffle_TNVI<T, 5, V, 0, 1, 3, 4, 2>();
	test_vect_shuffle_TNVI<T, 5, V, 1, 0, 3, 4, 2>();
	test_vect_shuffle_TNVI<T, 5, V, 1, 3, 0, 4, 2>();
	test_vect_shuffle_TNVI<T, 5, V, 1, 3, 4, 0, 2>();
	test_vect_shuffle_TNVI<T, 5, V, 1, 3, 4, 2, 0>();
	test_vect_shuffle_TNVI<T, 5, V, 0, 3, 1, 4, 2>();
	test_vect_shuffle_TNVI<T, 5, V, 3, 0, 1, 4, 2>();
	test_vect_shuffle_TNVI<T, 5, V, 3, 1, 0, 4, 2>();
	test_vect_shuffle_TNVI<T, 5, V, 3, 1, 4, 0, 2>();
	test_vect_shuffle_TNVI<T, 5, V, 3, 1, 4, 2, 0>();
	test_vect_shuffle_TNVI<T, 5, V, 0, 3, 4, 1, 2>();
	test_vect_shuffle_TNVI<T, 5, V, 3, 0, 4, 1, 2>();
	test_vect_shuffle_TNVI<T, 5, V, 3, 4, 0, 1, 2>();
	test_vect_shuffle_TNVI<T, 5, V, 3, 4, 1, 0, 2>();
	test_vect_shuffle_TNVI<T, 5, V, 3, 4, 1, 2, 0>();
	test_vect_shuffle_TNVI<T, 5, V, 0, 3, 4, 2, 1>();
	test_vect_shuffle_TNVI<T, 5, V, 3, 0, 4, 2, 1>();
	test_vect_shuffle_TNVI<T, 5, V, 3, 4, 0, 2, 1>();
	test_vect_shuffle_TNVI<T, 5, V, 3, 4, 2, 0, 1>();
	test_vect_shuffle_TNVI<T, 5, V, 3, 4, 2, 1, 0>();
	test_vect_shuffle_TNVI<T, 5, V, 0, 1, 2, 4, 3>();
	test_vect_shuffle_TNVI<T, 5, V, 1, 0, 2, 4, 3>();
	test_vect_shuffle_TNVI<T, 5, V, 1, 2, 0, 4, 3>();
	test_vect_shuffle_TNVI<T, 5, V, 1, 2, 4, 0, 3>();
	test_vect_shuffle_TNVI<T, 5, V, 1, 2, 4, 3, 0>();
	test_vect_shuffle_TNVI<T, 5, V, 0, 2, 1, 4, 3>();
	test_vect_shuffle_TNVI<T, 5, V, 2, 0, 1, 4, 3>();
	test_vect_shuffle_TNVI<T, 5, V, 2, 1, 0, 4, 3>();
	test_vect_shuffle_TNVI<T, 5, V, 2, 1, 4, 0, 3>();
	test_vect_shuffle_TNVI<T, 5, V, 2, 1, 4, 3, 0>();
	test_vect_shuffle_TNVI<T, 5, V, 0, 2, 4, 1, 3>();
	test_vect_shuffle_TNVI<T, 5, V, 2, 0, 4, 1, 3>();
	test_vect_shuffle_TNVI<T, 5, V, 2, 4, 0, 1, 3>();
	test_vect_shuffle_TNVI<T, 5, V, 2, 4, 1, 0, 3>();
	test_vect_shuffle_TNVI<T, 5, V, 2, 4, 1, 3, 0>();
	test_vect_shuffle_TNVI<T, 5, V, 0, 2, 4, 3, 1>();
	test_vect_shuffle_TNVI<T, 5, V, 2, 0, 4, 3, 1>();
	test_vect_shuffle_TNVI<T, 5, V, 2, 4, 0, 3, 1>();
	test_vect_shuffle_TNVI<T, 5, V, 2, 4, 3, 0, 1>();
	test_vect_shuffle_TNVI<T, 5, V, 2, 4, 3, 1, 0>();
	test_vect_shuffle_TNVI<T, 5, V, 0, 1, 4, 2, 3>();
	test_vect_shuffle_TNVI<T, 5, V, 1, 0, 4, 2, 3>();
	test_vect_shuffle_TNVI<T, 5, V, 1, 4, 0, 2, 3>();
	test_vect_shuffle_TNVI<T, 5, V, 1, 4, 2, 0, 3>();
	test_vect_shuffle_TNVI<T, 5, V, 1, 4, 2, 3, 0>();
	test_vect_shuffle_TNVI<T, 5, V, 0, 4, 1, 2, 3>();
	test_vect_shuffle_TNVI<T, 5, V, 4, 0, 1, 2, 3>();
	test_vect_shuffle_TNVI<T, 5, V, 4, 1, 0, 2, 3>();
	test_vect_shuffle_TNVI<T, 5, V, 4, 1, 2, 0, 3>();
	test_vect_shuffle_TNVI<T, 5, V, 4, 1, 2, 3, 0>();
	test_vect_shuffle_TNVI<T, 5, V, 0, 4, 2, 1, 3>();
	test_vect_shuffle_TNVI<T, 5, V, 4, 0, 2, 1, 3>();
	test_vect_shuffle_TNVI<T, 5, V, 4, 2, 0, 1, 3>();
	test_vect_shuffle_TNVI<T, 5, V, 4, 2, 1, 0, 3>();
	test_vect_shuffle_TNVI<T, 5, V, 4, 2, 1, 3, 0>();
	test_vect_shuffle_TNVI<T, 5, V, 0, 4, 2, 3, 1>();
	test_vect_shuffle_TNVI<T, 5, V, 4, 0, 2, 3, 1>();
	test_vect_shuffle_TNVI<T, 5, V, 4, 2, 0, 3, 1>();
	test_vect_shuffle_TNVI<T, 5, V, 4, 2, 3, 0, 1>();
	test_vect_shuffle_TNVI<T, 5, V, 4, 2, 3, 1, 0>();
	test_vect_shuffle_TNVI<T, 5, V, 0, 1, 4, 3, 2>();
	test_vect_shuffle_TNVI<T, 5, V, 1, 0, 4, 3, 2>();
	test_vect_shuffle_TNVI<T, 5, V, 1, 4, 0, 3, 2>();
	test_vect_shuffle_TNVI<T, 5, V, 1, 4, 3, 0, 2>();
	test_vect_shuffle_TNVI<T, 5, V, 1, 4, 3, 2, 0>();
	test_vect_shuffle_TNVI<T, 5, V, 0, 4, 1, 3, 2>();
	test_vect_shuffle_TNVI<T, 5, V, 4, 0, 1, 3, 2>();
	test_vect_shuffle_TNVI<T, 5, V, 4, 1, 0, 3, 2>();
	test_vect_shuffle_TNVI<T, 5, V, 4, 1, 3, 0, 2>();
	test_vect_shuffle_TNVI<T, 5, V, 4, 1, 3, 2, 0>();
	test_vect_shuffle_TNVI<T, 5, V, 0, 4, 3, 1, 2>();
	test_vect_shuffle_TNVI<T, 5, V, 4, 0, 3, 1, 2>();
	test_vect_shuffle_TNVI<T, 5, V, 4, 3, 0, 1, 2>();
	test_vect_shuffle_TNVI<T, 5, V, 4, 3, 1, 0, 2>();
	test_vect_shuffle_TNVI<T, 5, V, 4, 3, 1, 2, 0>();
	test_vect_shuffle_TNVI<T, 5, V, 0, 4, 3, 2, 1>();
	test_vect_shuffle_TNVI<T, 5, V, 4, 0, 3, 2, 1>();
	test_vect_shuffle_TNVI<T, 5, V, 4, 3, 0, 2, 1>();
	test_vect_shuffle_TNVI<T, 5, V, 4, 3, 2, 0, 1>();
	test_vect_shuffle_TNVI<T, 5, V, 4, 3, 2, 1, 0>();
}

template <typename T>
void test_vect_shuffle_T(void)
{
	test_vect_shuffle_TV<T, true>();
	test_vect_shuffle_TV<T,false>();
}

BOOST_AUTO_TEST_CASE(vect_shuffle_int)
{
	test_vect_shuffle_T<int>();
}

BOOST_AUTO_TEST_CASE(vect_shuffle_float)
{
	test_vect_shuffle_T<float>();
}

BOOST_AUTO_TEST_CASE(vect_shuffle_double)
{
	test_vect_shuffle_T<double>();
}

template <typename T, int N, bool V, int ... I>
void test_vect_shuffle2_TNVI(void)
{
	std::array<int, N> n = {{I...}};

	for(int k=0; k<10; ++k)
	{
		T a[N*2];

		typename eagine::vect::data<T, N, V>::type v = {}, u = {};
		typename eagine::vect::shuffle_mask<I...> m = {};

		for(int i=0; i<N*2; ++i)
		{
			a[i] = rg.get_any<T>();
		}
		for(int i=0; i<N; ++i)
		{
			v[i] = a[0+i];
			u[i] = a[N+i];
		}

		typename eagine::vect::data<T, N, V>::type w =
			eagine::vect::shuffle2<T, N, V>::apply(v, u, m);

		for(int i=0; i<N; ++i)
		{
			BOOST_CHECK_EQUAL(w[i], a[n[size_t(i)]]);
		}
	}
}

template <typename T, bool V>
void test_vect_shuffle2_TV(void)
{
	test_vect_shuffle2_TNVI<T, 2, V, 0, 2>();
	test_vect_shuffle2_TNVI<T, 2, V, 1, 2>();
	test_vect_shuffle2_TNVI<T, 2, V, 1, 0>();
	test_vect_shuffle2_TNVI<T, 2, V, 1, 3>();
	test_vect_shuffle2_TNVI<T, 2, V, 0, 1>();
	test_vect_shuffle2_TNVI<T, 2, V, 2, 1>();
	test_vect_shuffle2_TNVI<T, 2, V, 2, 0>();
	test_vect_shuffle2_TNVI<T, 2, V, 2, 3>();
	test_vect_shuffle2_TNVI<T, 2, V, 0, 3>();
	test_vect_shuffle2_TNVI<T, 2, V, 2, 3>();
	test_vect_shuffle2_TNVI<T, 2, V, 2, 1>();
	test_vect_shuffle2_TNVI<T, 2, V, 0, 3>();
	test_vect_shuffle2_TNVI<T, 2, V, 1, 3>();
	test_vect_shuffle2_TNVI<T, 2, V, 1, 0>();
	test_vect_shuffle2_TNVI<T, 2, V, 1, 2>();
	test_vect_shuffle2_TNVI<T, 2, V, 0, 1>();
	test_vect_shuffle2_TNVI<T, 2, V, 3, 1>();
	test_vect_shuffle2_TNVI<T, 2, V, 3, 0>();
	test_vect_shuffle2_TNVI<T, 2, V, 3, 2>();
	test_vect_shuffle2_TNVI<T, 2, V, 0, 2>();
	test_vect_shuffle2_TNVI<T, 2, V, 3, 2>();
	test_vect_shuffle2_TNVI<T, 2, V, 3, 0>();
	test_vect_shuffle2_TNVI<T, 2, V, 3, 1>();

	test_vect_shuffle2_TNVI<T, 3, V, 0, 2, 4>();
	test_vect_shuffle2_TNVI<T, 3, V, 1, 3, 5>();
	test_vect_shuffle2_TNVI<T, 3, V, 5, 4, 3>();
	test_vect_shuffle2_TNVI<T, 3, V, 1, 2, 3>();
	test_vect_shuffle2_TNVI<T, 3, V, 1, 1, 1>();
	test_vect_shuffle2_TNVI<T, 3, V, 4, 4, 4>();
	test_vect_shuffle2_TNVI<T, 3, V, 2, 3, 1>();
	test_vect_shuffle2_TNVI<T, 3, V, 0, 1, 2>();
	test_vect_shuffle2_TNVI<T, 3, V, 3, 4, 5>();

	test_vect_shuffle2_TNVI<T, 4, V, 0, 2, 4, 6>();
	test_vect_shuffle2_TNVI<T, 4, V, 1, 3, 5, 7>();
	test_vect_shuffle2_TNVI<T, 4, V, 1, 1, 1, 1>();
	test_vect_shuffle2_TNVI<T, 4, V, 1, 1, 2, 2>();
	test_vect_shuffle2_TNVI<T, 4, V, 4, 4, 5, 5>();
	test_vect_shuffle2_TNVI<T, 4, V, 5, 5, 5, 5>();
	test_vect_shuffle2_TNVI<T, 4, V, 3, 2, 1, 0>();
	test_vect_shuffle2_TNVI<T, 4, V, 7, 6, 5, 4>();
	test_vect_shuffle2_TNVI<T, 4, V, 6, 2, 4, 0>();
	test_vect_shuffle2_TNVI<T, 4, V, 7, 1, 5, 3>();

	test_vect_shuffle2_TNVI<T, 5, V, 0, 2, 4, 6, 8>();
	test_vect_shuffle2_TNVI<T, 5, V, 1, 3, 5, 7, 9>();
	test_vect_shuffle2_TNVI<T, 5, V, 8, 6, 4, 2, 0>();
	test_vect_shuffle2_TNVI<T, 5, V, 9, 7, 5, 3, 1>();
	test_vect_shuffle2_TNVI<T, 5, V, 0, 1, 2, 3, 4>();
	test_vect_shuffle2_TNVI<T, 5, V, 5, 6, 7, 8, 9>();
	test_vect_shuffle2_TNVI<T, 5, V, 2, 3, 4, 5, 6>();
	test_vect_shuffle2_TNVI<T, 5, V, 0, 1, 2, 7, 9>();
	test_vect_shuffle2_TNVI<T, 5, V, 2, 2, 2, 2, 2>();
	test_vect_shuffle2_TNVI<T, 5, V, 7, 7, 7, 7, 7>();
}

template <typename T>
void test_vect_shuffle2_T(void)
{
	test_vect_shuffle2_TV<T, true>();
	test_vect_shuffle2_TV<T,false>();
}

BOOST_AUTO_TEST_CASE(vect_shuffle2_int)
{
	test_vect_shuffle2_T<int>();
}

BOOST_AUTO_TEST_CASE(vect_shuffle2_float)
{
	test_vect_shuffle2_T<float>();
}

BOOST_AUTO_TEST_CASE(vect_shuffle2_double)
{
	test_vect_shuffle2_T<double>();
}

BOOST_AUTO_TEST_SUITE_END()
