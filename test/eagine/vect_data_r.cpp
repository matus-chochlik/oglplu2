/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_vect_data
#include <boost/test/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>

#include <eagine/vect/data.hpp>
#include <eagine/vect/sdiv.hpp>

#include <eagine/identity.hpp>

#include <cstdlib>

BOOST_AUTO_TEST_SUITE(vect_data_tests)

static inline
void _check_close(int a, int b, eagine::identity<int>)
{
	BOOST_CHECK_EQUAL(a, b);
}

static inline
void _check_close(float a, float b, eagine::identity<float>)
{
	BOOST_CHECK_CLOSE(a, b, 0.1f);
}

static inline
void _check_close(double a, double b, eagine::identity<double>)
{
	BOOST_CHECK_CLOSE(a, b, 0.001);
}

template <typename T>
static inline
void _check_close(T a, T b)
{
	_check_close(a, b, eagine::identity<T>());
}

template <typename T, bool V>
void test_vect_data_default_construct_TV(void)
{
	typename eagine::vect::data<T, 1, V>::type v1;
	typename eagine::vect::data<T, 2, V>::type v2;
	typename eagine::vect::data<T, 3, V>::type v3;
	typename eagine::vect::data<T, 4, V>::type v4;
	typename eagine::vect::data<T, 5, V>::type v5;
	typename eagine::vect::data<T, 6, V>::type v6;
	typename eagine::vect::data<T, 7, V>::type v7;
	typename eagine::vect::data<T, 8, V>::type v8;

	(void)v1;
	(void)v2;
	(void)v3;
	(void)v4;
	(void)v5;
	(void)v6;
	(void)v7;
	(void)v8;
}

template <typename T>
void test_vect_data_default_construct_T(void)
{
	test_vect_data_default_construct_TV<T, true>();
	test_vect_data_default_construct_TV<T,false>();
}

BOOST_AUTO_TEST_CASE(vect_data_default_construct)
{
	test_vect_data_default_construct_T<int>();
	test_vect_data_default_construct_T<float>();
	test_vect_data_default_construct_T<double>();
}

template <typename T, bool V>
void test_vect_data_initialization_TV(void)
{
	typename eagine::vect::data<T, 1, V>::type v1 =
		{T(1)};
	typename eagine::vect::data<T, 2, V>::type v2 =
		{T(1), T(2)};
	typename eagine::vect::data<T, 3, V>::type v3 =
		{T(1), T(2), T(3)};
	typename eagine::vect::data<T, 4, V>::type v4 =
		{T(1), T(2), T(3), T(4)};
	typename eagine::vect::data<T, 5, V>::type v5 =
		{T(1), T(2), T(3), T(4), T(5)};
	typename eagine::vect::data<T, 6, V>::type v6 =
		{T(1), T(2), T(3), T(4), T(5), T(6)};
	typename eagine::vect::data<T, 7, V>::type v7 =
		{T(1), T(2), T(3), T(4), T(5), T(6), T(7)};
	typename eagine::vect::data<T, 8, V>::type v8 =
		{T(1), T(2), T(3), T(4), T(5), T(6), T(7), T(8)};

	(void)v1;
	(void)v2;
	(void)v3;
	(void)v4;
	(void)v5;
	(void)v6;
	(void)v7;
	(void)v8;
}

template <typename T>
void test_vect_data_initialization_T(void)
{
	test_vect_data_initialization_TV<T, true>();
	test_vect_data_initialization_TV<T,false>();
}

BOOST_AUTO_TEST_CASE(vect_data_initialization)
{
	test_vect_data_initialization_T<int>();
	test_vect_data_initialization_T<float>();
	test_vect_data_initialization_T<double>();
}

template <typename T, bool V1, bool V2>
void test_vect_data_copy_construct_TV(void)
{
	typename eagine::vect::data<T, 1, V1>::type v1 = { };
	typename eagine::vect::data<T, 1, V2>::type v1c = v1;
	typename eagine::vect::data<T, 2, V1>::type v2 = { };
	typename eagine::vect::data<T, 2, V2>::type v2c = v2;
	typename eagine::vect::data<T, 3, V1>::type v3 = { };
	typename eagine::vect::data<T, 3, V2>::type v3c = v3;
	typename eagine::vect::data<T, 4, V1>::type v4 = { };
	typename eagine::vect::data<T, 4, V2>::type v4c = v4;
	typename eagine::vect::data<T, 5, V1>::type v5 = { };
	typename eagine::vect::data<T, 5, V2>::type v5c = v5;
	typename eagine::vect::data<T, 6, V1>::type v6 = { };
	typename eagine::vect::data<T, 6, V2>::type v6c = v6;
	typename eagine::vect::data<T, 7, V1>::type v7 = { };
	typename eagine::vect::data<T, 7, V2>::type v7c = v7;
	typename eagine::vect::data<T, 8, V1>::type v8 = { };
	typename eagine::vect::data<T, 8, V2>::type v8c = v8;

	(void)v1c;
	(void)v2c;
	(void)v3c;
	(void)v4c;
	(void)v5c;
	(void)v6c;
	(void)v7c;
	(void)v8c;
}

template <typename T>
void test_vect_data_copy_construct_T(void)
{
	test_vect_data_copy_construct_TV<T, true, true>();
	test_vect_data_copy_construct_TV<T,false,false>();
}

BOOST_AUTO_TEST_CASE(vect_data_copy_construct)
{
	test_vect_data_copy_construct_T<int>();
	test_vect_data_copy_construct_T<float>();
	test_vect_data_copy_construct_T<double>();
}

template <typename T, bool V>
void test_vect_data_elements_TV(void)
{
	typename eagine::vect::data<T, 1, V>::type v1 =
		{T(1)};
	BOOST_CHECK_EQUAL(v1[0], T(1));

	typename eagine::vect::data<T, 2, V>::type v2 =
		{T(1), T(2)};
	BOOST_CHECK_EQUAL(v2[0], T(1));
	BOOST_CHECK_EQUAL(v2[1], T(2));

	typename eagine::vect::data<T, 3, V>::type v3 =
		{T(2), T(3), T(4)};
	BOOST_CHECK_EQUAL(v3[0], T(2));
	BOOST_CHECK_EQUAL(v3[1], T(3));
	BOOST_CHECK_EQUAL(v3[2], T(4));

	typename eagine::vect::data<T, 4, V>::type v4 =
		{T(3), T(4), T(5), T(6)};
	BOOST_CHECK_EQUAL(v4[0], T(3));
	BOOST_CHECK_EQUAL(v4[1], T(4));
	BOOST_CHECK_EQUAL(v4[2], T(5));
	BOOST_CHECK_EQUAL(v4[3], T(6));

	typename eagine::vect::data<T, 7, V>::type v7 =
		{T(4), T(5), T(6), T(7), T(8), T(9), T(0)};
	BOOST_CHECK_EQUAL(v7[0], T(4));
	BOOST_CHECK_EQUAL(v7[1], T(5));
	BOOST_CHECK_EQUAL(v7[2], T(6));
	BOOST_CHECK_EQUAL(v7[3], T(7));
	BOOST_CHECK_EQUAL(v7[4], T(8));
	BOOST_CHECK_EQUAL(v7[5], T(9));
	BOOST_CHECK_EQUAL(v7[6], T(0));

	typename eagine::vect::data<T, 8, V>::type v8 =
		{T(5), T(6), T(7), T(8), T(9), T(0), T(1), T(2)};
	BOOST_CHECK_EQUAL(v8[0], T(5));
	BOOST_CHECK_EQUAL(v8[1], T(6));
	BOOST_CHECK_EQUAL(v8[2], T(7));
	BOOST_CHECK_EQUAL(v8[3], T(8));
	BOOST_CHECK_EQUAL(v8[4], T(9));
	BOOST_CHECK_EQUAL(v8[5], T(0));
	BOOST_CHECK_EQUAL(v8[6], T(1));
	BOOST_CHECK_EQUAL(v8[7], T(2));
}

template <typename T>
void test_vect_data_elements_T(void)
{
	test_vect_data_elements_TV<T, true>();
	test_vect_data_elements_TV<T,false>();
}

BOOST_AUTO_TEST_CASE(vect_data_elements)
{
	test_vect_data_elements_T<int>();
	test_vect_data_elements_T<float>();
	test_vect_data_elements_T<double>();
}

template <typename T, unsigned N, bool V>
void test_vect_data_plus_TNV(void)
{
	for(unsigned k=0; k<1000; ++k)
	{
		T a[N], b[N];
		for(unsigned i=0; i<N; ++i)
		{
			a[i] = std::rand() / T(2);
			b[i] = std::rand() / T(2);
		}

		typename eagine::vect::data<T, N, V>::type vNa = {};
		typename eagine::vect::data<T, N, V>::type vNb = {};

		for(unsigned i=0; i<N; ++i)
		{
			vNa[i] = a[i];
			vNb[i] = b[i];
		}

		typename eagine::vect::data<T, N, V>::type vNc = vNa + vNb;
		typename eagine::vect::data<T, N, V>::type vNd = vNb + vNa;

		for(unsigned i=0; i<N; ++i)
		{
			_check_close<T>(vNc[i], vNd[i]);
			_check_close<T>(vNc[i], a[i] + b[i]);
			_check_close<T>(vNd[i], b[i] + a[i]);
		}
	}
}

template <typename T, bool V>
void test_vect_data_plus_TV(void)
{
	test_vect_data_plus_TNV<T, 1, V>();
	test_vect_data_plus_TNV<T, 2, V>();
	test_vect_data_plus_TNV<T, 3, V>();
	test_vect_data_plus_TNV<T, 4, V>();
	test_vect_data_plus_TNV<T, 5, V>();
	test_vect_data_plus_TNV<T, 6, V>();
	test_vect_data_plus_TNV<T, 7, V>();
	test_vect_data_plus_TNV<T, 8, V>();
}

template <typename T>
void test_vect_data_plus_T(void)
{
	test_vect_data_plus_TV<T, true>();
	test_vect_data_plus_TV<T,false>();
}

BOOST_AUTO_TEST_CASE(vect_data_plus)
{
	test_vect_data_plus_T<int>();
	test_vect_data_plus_T<float>();
	test_vect_data_plus_T<double>();
}

template <typename T, unsigned N, bool V>
void test_vect_data_minus_TNV(void)
{
	for(unsigned k=0; k<1000; ++k)
	{
		T a[N], b[N];
		for(unsigned i=0; i<N; ++i)
		{
			a[i] = std::rand() / T(2);
			b[i] = std::rand() / T(2);
		}

		typename eagine::vect::data<T, N, V>::type vNa = {};
		typename eagine::vect::data<T, N, V>::type vNb = {};

		for(unsigned i=0; i<N; ++i)
		{
			vNa[i] = a[i];
			vNb[i] = b[i];
		}

		typename eagine::vect::data<T, N, V>::type vNc = vNa - vNb;
		typename eagine::vect::data<T, N, V>::type vNd = vNb - vNa;

		for(unsigned i=0; i<N; ++i)
		{
			_check_close<T>(vNc[i], a[i] - b[i]);
			_check_close<T>(vNd[i], b[i] - a[i]);
		}
	}
}

template <typename T, bool V>
void test_vect_data_minus_TV(void)
{
	test_vect_data_minus_TNV<T, 1, V>();
	test_vect_data_minus_TNV<T, 2, V>();
	test_vect_data_minus_TNV<T, 3, V>();
	test_vect_data_minus_TNV<T, 4, V>();
	test_vect_data_minus_TNV<T, 5, V>();
	test_vect_data_minus_TNV<T, 6, V>();
	test_vect_data_minus_TNV<T, 7, V>();
	test_vect_data_minus_TNV<T, 8, V>();
}

template <typename T>
void test_vect_data_minus_T(void)
{
	test_vect_data_minus_TV<T, true>();
	test_vect_data_minus_TV<T,false>();
}

BOOST_AUTO_TEST_CASE(vect_data_minus)
{
	test_vect_data_minus_T<int>();
	test_vect_data_minus_T<float>();
	test_vect_data_minus_T<double>();
}

template <typename T, unsigned N, bool V>
void test_vect_data_multiply_TNV(void)
{
	for(unsigned k=0; k<1000; ++k)
	{
		T a[N], b[N];
		for(unsigned i=0; i<N; ++i)
		{
			a[i] = std::rand() % 10000;
			b[i] = std::rand() % 10000;
		}

		typename eagine::vect::data<T, N, V>::type vNa = {};
		typename eagine::vect::data<T, N, V>::type vNb = {};

		for(unsigned i=0; i<N; ++i)
		{
			vNa[i] = a[i];
			vNb[i] = b[i];
		}

		typename eagine::vect::data<T, N, V>::type vNc = vNa * vNb;
		typename eagine::vect::data<T, N, V>::type vNd = vNb * vNa;

		for(unsigned i=0; i<N; ++i)
		{
			_check_close<T>(vNc[i], vNd[i]);
			_check_close<T>(vNc[i], a[i] * b[i]);
			_check_close<T>(vNd[i], b[i] * a[i]);
		}
	}
}

template <typename T, bool V>
void test_vect_data_multiply_TV(void)
{
	test_vect_data_multiply_TNV<T, 1, V>();
	test_vect_data_multiply_TNV<T, 2, V>();
	test_vect_data_multiply_TNV<T, 3, V>();
	test_vect_data_multiply_TNV<T, 4, V>();
	test_vect_data_multiply_TNV<T, 5, V>();
	test_vect_data_multiply_TNV<T, 6, V>();
	test_vect_data_multiply_TNV<T, 7, V>();
	test_vect_data_multiply_TNV<T, 8, V>();
}

template <typename T>
void test_vect_data_multiply_T(void)
{
	test_vect_data_multiply_TV<T, true>();
	test_vect_data_multiply_TV<T,false>();
}

BOOST_AUTO_TEST_CASE(vect_data_multiply)
{
	test_vect_data_multiply_T<int>();
	test_vect_data_multiply_T<float>();
	test_vect_data_multiply_T<double>();
}

template <typename T, unsigned N, bool V>
void test_vect_data_divide_TNV(void)
{
	for(unsigned k=0; k<1000; ++k)
	{
		T a[N], b[N];
		for(unsigned i=0; i<N; ++i)
		{
			a[i] = 1 + std::rand() % 10000;
			b[i] = 1 + std::rand() % 10000;
		}

		typename eagine::vect::data<T, N, V>::type vNa = {};
		typename eagine::vect::data<T, N, V>::type vNb = {};

		for(unsigned i=0; i<N; ++i)
		{
			vNa[i] = a[i];
			vNb[i] = b[i];
		}

		typename eagine::vect::data<T, N, V>::type vNc =
			eagine::vect::sdiv<T, N, V>::apply(vNa, vNb);
		typename eagine::vect::data<T, N, V>::type vNd =
			eagine::vect::sdiv<T, N, V>::apply(vNb, vNa);

		for(unsigned i=0; i<N; ++i)
		{
			_check_close<T>(vNc[i], a[i] / b[i]);
			_check_close<T>(vNd[i], b[i] / a[i]);
		}
	}
}

template <typename T, bool V>
void test_vect_data_divide_TV(void)
{
	test_vect_data_divide_TNV<T, 1, V>();
	test_vect_data_divide_TNV<T, 2, V>();
	test_vect_data_divide_TNV<T, 3, V>();
	test_vect_data_divide_TNV<T, 4, V>();
	test_vect_data_divide_TNV<T, 5, V>();
	test_vect_data_divide_TNV<T, 6, V>();
	test_vect_data_divide_TNV<T, 7, V>();
	test_vect_data_divide_TNV<T, 8, V>();
}

template <typename T>
void test_vect_data_divide_T(void)
{
	test_vect_data_divide_TV<T, true>();
	test_vect_data_divide_TV<T,false>();
}

BOOST_AUTO_TEST_CASE(vect_data_divide)
{
	test_vect_data_divide_T<int>();
	test_vect_data_divide_T<float>();
	test_vect_data_divide_T<double>();
}

// TODO

BOOST_AUTO_TEST_SUITE_END()
