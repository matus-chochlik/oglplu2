/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/vect/fill.hpp>
#define BOOST_TEST_MODULE EAGINE_vect_fill
#include "../unit_test.inl"


BOOST_AUTO_TEST_SUITE(vect_fill_tests)

static eagine::test_random_generator rg;

template <typename T, int N, bool V>
void test_vect_fill_apply_TNV(void)
{
	for(int k=0; k<1000; ++k)
	{
		T a = rg.get_any<T>();

		typename eagine::vect::data<T, N, V>::type v =
			eagine::vect::fill<T, N, V>::apply(a);

		for(int i=0; i<N; ++i)
		{
			BOOST_CHECK_EQUAL(v[i], a);
		}
	}
}

template <typename T, bool V>
void test_vect_fill_apply_TV(void)
{
	test_vect_fill_apply_TNV<T, 2, V>();
	test_vect_fill_apply_TNV<T, 3, V>();
	test_vect_fill_apply_TNV<T, 4, V>();
	test_vect_fill_apply_TNV<T, 5, V>();
	test_vect_fill_apply_TNV<T, 6, V>();
	test_vect_fill_apply_TNV<T, 7, V>();
	test_vect_fill_apply_TNV<T, 8, V>();
}

template <typename T>
void test_vect_fill_apply_T(void)
{
	test_vect_fill_apply_TV<T, true>();
	test_vect_fill_apply_TV<T,false>();
}

BOOST_AUTO_TEST_CASE(vect_fill_apply)
{
	test_vect_fill_apply_T<int>();
	test_vect_fill_apply_T<float>();
	test_vect_fill_apply_T<double>();
}


BOOST_AUTO_TEST_SUITE_END()
