/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_vect_compare
#include <boost/test/unit_test.hpp>

#include <eagine/vect/fill.hpp>
#include <eagine/vect/compare.hpp>
#include <cstdlib>

BOOST_AUTO_TEST_SUITE(vect_compare)

template <typename T, unsigned N, bool V>
void test_vect_is_zero_apply_TNV(void)
{
	for(unsigned k=0; k<1000; ++k)
	{
		bool gen_zero = std::rand()%10==0;
		T a = gen_zero?0:std::rand() / T(3);

		typename eagine::vect::data<T, N, V>::type v =
			eagine::vect::fill<T, N, V>::apply(a);

		bool is_zero = eagine::vect::is_zero<T, N, V>::apply(v);

		BOOST_CHECK_EQUAL(gen_zero, is_zero);
	}
}

template <typename T, bool V>
void test_vect_is_zero_apply_TV(void)
{
	test_vect_is_zero_apply_TNV<T, 2, V>();
	test_vect_is_zero_apply_TNV<T, 3, V>();
	test_vect_is_zero_apply_TNV<T, 4, V>();
	test_vect_is_zero_apply_TNV<T, 5, V>();
	test_vect_is_zero_apply_TNV<T, 6, V>();
	test_vect_is_zero_apply_TNV<T, 7, V>();
	test_vect_is_zero_apply_TNV<T, 8, V>();
}

template <typename T>
void test_vect_is_zero_apply_T(void)
{
	test_vect_is_zero_apply_TV<T, true>();
	test_vect_is_zero_apply_TV<T,false>();
}

BOOST_AUTO_TEST_CASE(vect_is_zero_apply)
{
	test_vect_is_zero_apply_T<int>();
	test_vect_is_zero_apply_T<float>();
	test_vect_is_zero_apply_T<double>();
}


BOOST_AUTO_TEST_SUITE_END()
