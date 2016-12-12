/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_math_vector_ops
#include <boost/test/unit_test.hpp>
#include "../random.hpp"

#include <eagine/math/vector.hpp>

BOOST_AUTO_TEST_SUITE(math_vector_op_tests)

static eagine::test_random_generator rg;

template <typename T, int N, bool V>
void test_math_vector_dimension_TNV(void)
{
	eagine::math::vector<T, N, V> v;
	BOOST_CHECK_EQUAL(dimension(v), N);
}

template <typename T, bool V>
void test_math_vector_dimension_TV(void)
{
	test_math_vector_dimension_TNV<T, 1, V>();
	test_math_vector_dimension_TNV<T, 2, V>();
	test_math_vector_dimension_TNV<T, 3, V>();
	test_math_vector_dimension_TNV<T, 4, V>();
	test_math_vector_dimension_TNV<T, 5, V>();
	test_math_vector_dimension_TNV<T, 6, V>();
	test_math_vector_dimension_TNV<T, 7, V>();
	test_math_vector_dimension_TNV<T, 8, V>();
	test_math_vector_dimension_TNV<T,13, V>();
	test_math_vector_dimension_TNV<T,17, V>();
}

template <typename T>
void test_math_vector_dimension_T(void)
{
	test_math_vector_dimension_TV<T, true>();
	test_math_vector_dimension_TV<T,false>();
}

BOOST_AUTO_TEST_CASE(math_vector_dimension)
{
	test_math_vector_dimension_T<int>();
	test_math_vector_dimension_T<float>();
	test_math_vector_dimension_T<double>();
}

template <typename T, int N, bool V>
void test_math_vector_dot_TNV(void)
{
	T a[N], b[N];
	T d = T(0);

	for(int i=0; i<N; ++i)
	{
		a[i] = rg.get<T>(0, 5000);
		b[i] = rg.get<T>(0, 5000);
		d += a[i]*b[i];
	}

	auto u = eagine::math::vector<T, N, V>::from(a, N);
	auto v = eagine::math::vector<T, N, V>::from(b, N);

	BOOST_CHECK_EQUAL(dot(u, v), d);
	BOOST_CHECK_EQUAL(dot(u, v), dot(v, u));
}

template <typename T, bool V>
void test_math_vector_dot_TV(void)
{
	test_math_vector_dot_TNV<T, 1, V>();
	test_math_vector_dot_TNV<T, 2, V>();
	test_math_vector_dot_TNV<T, 3, V>();
	test_math_vector_dot_TNV<T, 4, V>();
	test_math_vector_dot_TNV<T, 5, V>();
	test_math_vector_dot_TNV<T, 6, V>();
	test_math_vector_dot_TNV<T, 7, V>();
	test_math_vector_dot_TNV<T, 8, V>();
	test_math_vector_dot_TNV<T,13, V>();
	test_math_vector_dot_TNV<T,17, V>();
}

template <typename T>
void test_math_vector_dot_T(void)
{
	test_math_vector_dot_TV<T, true>();
	test_math_vector_dot_TV<T,false>();
}

BOOST_AUTO_TEST_CASE(math_vector_dot)
{
	test_math_vector_dot_T<int>();
	test_math_vector_dot_T<float>();
	test_math_vector_dot_T<double>();
}

template <typename T, int N, bool V>
void test_math_vector_magnitude_TNV(void)
{
	T a[N];
	T m = T(0);

	for(int i=0; i<N; ++i)
	{
		a[i] = rg.get<T>(0, 5000);
		m += a[i]*a[i];
	}

	auto v = eagine::math::vector<T, N, V>::from(a, N);

	using std::sqrt;
	BOOST_CHECK_EQUAL(magnitude(v), sqrt(m));
}

template <typename T, bool V>
void test_math_vector_magnitude_TV(void)
{
	test_math_vector_magnitude_TNV<T, 1, V>();
	test_math_vector_magnitude_TNV<T, 2, V>();
	test_math_vector_magnitude_TNV<T, 3, V>();
	test_math_vector_magnitude_TNV<T, 4, V>();
	test_math_vector_magnitude_TNV<T, 5, V>();
	test_math_vector_magnitude_TNV<T, 6, V>();
	test_math_vector_magnitude_TNV<T, 7, V>();
	test_math_vector_magnitude_TNV<T, 8, V>();
	test_math_vector_magnitude_TNV<T,13, V>();
	test_math_vector_magnitude_TNV<T,17, V>();
}

template <typename T>
void test_math_vector_magnitude_T(void)
{
	test_math_vector_magnitude_TV<T, true>();
	test_math_vector_magnitude_TV<T,false>();
}

BOOST_AUTO_TEST_CASE(math_vector_magnitude)
{
	test_math_vector_magnitude_T<float>();
	test_math_vector_magnitude_T<double>();
}

//TODO

BOOST_AUTO_TEST_SUITE_END()
