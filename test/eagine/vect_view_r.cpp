/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE eagine_vect_view
#include <boost/test/unit_test.hpp>

#include <eagine/vect/view.hpp>
#include <cstdlib>

BOOST_AUTO_TEST_SUITE(vect_view_tests)

template <typename T, int N, bool V>
void test_vect_view_TNV(void)
{
	typename eagine::vect::data<T, N, V>::type v = {};

	for(int i=0; i<N; ++i)
	{
		T n = std::rand()%10000 / T(2);
		v[i] = n;
	}

	auto vv = eagine::vect::view<T, N, V>::apply(v);
	eagine::span<const T> av = vv;

	for(int i=0; i<N; ++i)
	{
		BOOST_CHECK_EQUAL(av[i], v[i]);
	}
}

template <typename T, bool V>
void test_vect_view_TV(void)
{
	test_vect_view_TNV<T, 2, V>();
	test_vect_view_TNV<T, 3, V>();
	test_vect_view_TNV<T, 4, V>();
	test_vect_view_TNV<T, 5, V>();
	test_vect_view_TNV<T, 6, V>();
	test_vect_view_TNV<T, 7, V>();
	test_vect_view_TNV<T, 8, V>();

	test_vect_view_TNV<T, 11, V>();
	test_vect_view_TNV<T, 17, V>();
	test_vect_view_TNV<T, 23, V>();
}

template <typename T>
void test_vect_view_T(void)
{
	test_vect_view_TV<T, true>();
	test_vect_view_TV<T,false>();
}

BOOST_AUTO_TEST_CASE(vect_view_apply_int)
{
	test_vect_view_T<int>();
}

BOOST_AUTO_TEST_CASE(vect_view_apply_float)
{
	test_vect_view_T<float>();
}

BOOST_AUTO_TEST_CASE(vect_view_apply_double)
{
	test_vect_view_T<double>();
}

BOOST_AUTO_TEST_SUITE_END()
