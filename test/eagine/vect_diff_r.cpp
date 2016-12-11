/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_vect_diff
#include <boost/test/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>
#include "../random.hpp"

#include <eagine/vect/diff.hpp>
#include <eagine/vect/esum.hpp>

BOOST_AUTO_TEST_SUITE(vect_diff_tests)

static eagine::test_random_generator rg;

template <typename T, int N, bool V>
void test_vect_diff_TNV_1(void)
{
	for(int k=0; k<1000; ++k)
	{
		T a[N];

		typename eagine::vect::data<T, N, V>::type u = {}, v = {};

		for(int i=0; i<N; ++i)
		{
			a[i] = rg.get(-10000,+10000);
			u[i] = a[i];
			v[i] = a[i];
		}

		typedef eagine::vect::diff<T, N, V> _diff;
		typedef eagine::vect::esum<T, N, V> _esum;

		BOOST_CHECK_EQUAL(_esum::apply(_diff::apply(u, u)), T(0));
		BOOST_CHECK_EQUAL(_esum::apply(_diff::apply(v, u)), T(0));
		BOOST_CHECK_EQUAL(_esum::apply(_diff::apply(u, v)), T(0));
		BOOST_CHECK_EQUAL(_esum::apply(_diff::apply(v, v)), T(0));
	}
}

template <typename T, bool V>
void test_vect_diff_TV_1(void)
{
	test_vect_diff_TNV_1<T, 2, V>();
	test_vect_diff_TNV_1<T, 3, V>();
	test_vect_diff_TNV_1<T, 4, V>();
	test_vect_diff_TNV_1<T, 5, V>();
	test_vect_diff_TNV_1<T, 7, V>();
	test_vect_diff_TNV_1<T, 8, V>();
	test_vect_diff_TNV_1<T,11, V>();
	test_vect_diff_TNV_1<T,15, V>();
	test_vect_diff_TNV_1<T,19, V>();
}

template <typename T>
void test_vect_diff_T_1(void)
{
	test_vect_diff_TV_1<T, true>();
	test_vect_diff_TV_1<T,false>();
}

BOOST_AUTO_TEST_CASE(vect_data_diff_TNV_1)
{
	test_vect_diff_T_1<int>();
	test_vect_diff_T_1<float>();
	test_vect_diff_T_1<double>();
}

// TODO

BOOST_AUTO_TEST_SUITE_END()
