/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_math_vector
#include <boost/test/unit_test.hpp>

#include <eagine/math/vector.hpp>
#include <cstdlib>

BOOST_AUTO_TEST_SUITE(math_vector_tests)

template <typename T, bool V>
void test_math_vector_default_ctr_TV(void)
{
	eagine::math::vector<T, 1, V> v1; (void)v1;
	eagine::math::vector<T, 2, V> v2; (void)v2;
	eagine::math::vector<T, 3, V> v3; (void)v3;
	eagine::math::vector<T, 4, V> v4; (void)v4;
	eagine::math::vector<T, 5, V> v5; (void)v5;
	eagine::math::vector<T, 6, V> v6; (void)v6;
	eagine::math::vector<T, 7, V> v7; (void)v7;
	eagine::math::vector<T, 8, V> v8; (void)v8;
	eagine::math::vector<T,11, V> v11; (void)v11;
	eagine::math::vector<T,17, V> v17; (void)v17;
	eagine::math::vector<T,23, V> v23; (void)v23;

}

template <typename T>
void test_math_vector_default_ctr_T(void)
{
	test_math_vector_default_ctr_TV<T, true>();
	test_math_vector_default_ctr_TV<T,false>();
}

BOOST_AUTO_TEST_CASE(math_vector_default_ctr)
{
	test_math_vector_default_ctr_T<int>();
	test_math_vector_default_ctr_T<float>();
	test_math_vector_default_ctr_T<double>();
}

template <typename T, unsigned N, bool V>
void test_math_vector_zero_TNV(void)
{
	auto v = eagine::math::vector<T, N, V>::zero();
	for(unsigned i=0; i<N; ++i)
	{
		BOOST_CHECK_EQUAL(v[i], T(0));
	}
}

template <typename T, bool V>
void test_math_vector_zero_TV(void)
{
	test_math_vector_zero_TNV<T, 1, V>();
	test_math_vector_zero_TNV<T, 2, V>();
	test_math_vector_zero_TNV<T, 3, V>();
	test_math_vector_zero_TNV<T, 4, V>();
	test_math_vector_zero_TNV<T, 5, V>();
	test_math_vector_zero_TNV<T, 6, V>();
	test_math_vector_zero_TNV<T, 7, V>();
	test_math_vector_zero_TNV<T, 8, V>();
	test_math_vector_zero_TNV<T,11, V>();
	test_math_vector_zero_TNV<T,17, V>();
	test_math_vector_zero_TNV<T,31, V>();
}

template <typename T>
void test_math_vector_zero_T(void)
{
	test_math_vector_zero_TV<T, true>();
	test_math_vector_zero_TV<T,false>();
}

BOOST_AUTO_TEST_CASE(math_vector_zero)
{
	test_math_vector_zero_T<int>();
	test_math_vector_zero_T<float>();
	test_math_vector_zero_T<double>();
}

template <typename T, unsigned N, bool V>
void test_math_vector_fill_TNV(void)
{
	T r = T(std::rand() % 10000);
	auto v = eagine::math::vector<T, N, V>::fill(r);
	for(unsigned i=0; i<N; ++i)
	{
		BOOST_CHECK_EQUAL(v[i], r);
	}
}

template <typename T, bool V>
void test_math_vector_fill_TV(void)
{
	test_math_vector_fill_TNV<T, 1, V>();
	test_math_vector_fill_TNV<T, 2, V>();
	test_math_vector_fill_TNV<T, 3, V>();
	test_math_vector_fill_TNV<T, 4, V>();
	test_math_vector_fill_TNV<T, 5, V>();
	test_math_vector_fill_TNV<T, 6, V>();
	test_math_vector_fill_TNV<T, 7, V>();
	test_math_vector_fill_TNV<T, 8, V>();
	test_math_vector_fill_TNV<T,11, V>();
	test_math_vector_fill_TNV<T,17, V>();
	test_math_vector_fill_TNV<T,31, V>();
}

template <typename T>
void test_math_vector_fill_T(void)
{
	test_math_vector_fill_TV<T, true>();
	test_math_vector_fill_TV<T,false>();
}

BOOST_AUTO_TEST_CASE(math_vector_fill)
{
	test_math_vector_fill_T<int>();
	test_math_vector_fill_T<float>();
	test_math_vector_fill_T<double>();
}

template <typename T, unsigned N, bool V>
void test_math_vector_axis_TNV(void)
{
	for(unsigned j=0; j<N; ++j)
	{
		T r = T(std::rand() % 10000);
		auto v = eagine::math::vector<T, N, V>::axis(j, r);
		for(unsigned i=0; i<N; ++i)
		{
			BOOST_CHECK_EQUAL(v[i], j==i?r:T(0));
		}
	}
}

template <typename T, bool V>
void test_math_vector_axis_TV(void)
{
	test_math_vector_axis_TNV<T, 1, V>();
	test_math_vector_axis_TNV<T, 2, V>();
	test_math_vector_axis_TNV<T, 3, V>();
	test_math_vector_axis_TNV<T, 4, V>();
	test_math_vector_axis_TNV<T, 5, V>();
	test_math_vector_axis_TNV<T, 6, V>();
	test_math_vector_axis_TNV<T, 7, V>();
	test_math_vector_axis_TNV<T, 8, V>();
	test_math_vector_axis_TNV<T,11, V>();
	test_math_vector_axis_TNV<T,17, V>();
	test_math_vector_axis_TNV<T,31, V>();
}

template <typename T>
void test_math_vector_axis_T(void)
{
	test_math_vector_axis_TV<T, true>();
	test_math_vector_axis_TV<T,false>();
}

BOOST_AUTO_TEST_CASE(math_vector_axis_i)
{
	test_math_vector_axis_T<int>();
	test_math_vector_axis_T<float>();
	test_math_vector_axis_T<double>();
}

template <typename T, unsigned I, unsigned N, bool V>
void test_math_vector_axis_TINV(void)
{
	T r = T(std::rand() % 10000);

	auto v = eagine::math::vector<T, N, V>::template axis<I>(r);
	for(unsigned i=0; i<N; ++i)
	{
		BOOST_CHECK_EQUAL(v[i], i==I?r:T(0));
	}
}

template <typename T, bool V>
void test_math_vector_axis_TV_I(void)
{
	test_math_vector_axis_TINV<T, 0, 1, V>();

	test_math_vector_axis_TINV<T, 0, 2, V>();
	test_math_vector_axis_TINV<T, 1, 2, V>();

	test_math_vector_axis_TINV<T, 0, 3, V>();
	test_math_vector_axis_TINV<T, 1, 3, V>();
	test_math_vector_axis_TINV<T, 2, 3, V>();

	test_math_vector_axis_TINV<T, 0, 4, V>();
	test_math_vector_axis_TINV<T, 1, 4, V>();
	test_math_vector_axis_TINV<T, 2, 4, V>();
	test_math_vector_axis_TINV<T, 3, 4, V>();

	test_math_vector_axis_TINV<T, 0, 5, V>();
	test_math_vector_axis_TINV<T, 1, 5, V>();
	test_math_vector_axis_TINV<T, 2, 5, V>();
	test_math_vector_axis_TINV<T, 3, 5, V>();
	test_math_vector_axis_TINV<T, 4, 5, V>();

	test_math_vector_axis_TINV<T, 0, 6, V>();
	test_math_vector_axis_TINV<T, 1, 6, V>();
	test_math_vector_axis_TINV<T, 2, 6, V>();
	test_math_vector_axis_TINV<T, 3, 6, V>();
	test_math_vector_axis_TINV<T, 4, 6, V>();
	test_math_vector_axis_TINV<T, 5, 6, V>();

	test_math_vector_axis_TINV<T, 0, 7, V>();
	test_math_vector_axis_TINV<T, 1, 7, V>();
	test_math_vector_axis_TINV<T, 2, 6, V>();
	test_math_vector_axis_TINV<T, 3, 7, V>();
	test_math_vector_axis_TINV<T, 4, 7, V>();
	test_math_vector_axis_TINV<T, 5, 7, V>();
	test_math_vector_axis_TINV<T, 6, 7, V>();

	test_math_vector_axis_TINV<T, 0, 8, V>();
	test_math_vector_axis_TINV<T, 1, 8, V>();
	test_math_vector_axis_TINV<T, 2, 8, V>();
	test_math_vector_axis_TINV<T, 3, 8, V>();
	test_math_vector_axis_TINV<T, 4, 8, V>();
	test_math_vector_axis_TINV<T, 5, 8, V>();
	test_math_vector_axis_TINV<T, 6, 8, V>();
	test_math_vector_axis_TINV<T, 7, 8, V>();
}

template <typename T>
void test_math_vector_axis_T_I(void)
{
	test_math_vector_axis_TV_I<T, true>();
	test_math_vector_axis_TV_I<T,false>();
}

BOOST_AUTO_TEST_CASE(math_vector_axis_I)
{
	test_math_vector_axis_T_I<int>();
	test_math_vector_axis_T_I<float>();
	test_math_vector_axis_T_I<double>();
}

template <typename T, bool V>
void test_math_vector_make_and_elem_TV(void)
{
	T r1 = T(std::rand()%10000);
	auto v1 = eagine::math::vector<T, 1, V>::make(r1);
	BOOST_CHECK_EQUAL(v1[0], r1);

	T r2 = T(std::rand()%10000);
	auto v2 = eagine::math::vector<T, 2, V>::make(r2, r1);
	BOOST_CHECK_EQUAL(v2[0], r2);
	BOOST_CHECK_EQUAL(v2[1], r1);

	T r3 = T(std::rand()%10000);
	auto v3 = eagine::math::vector<T, 3, V>::make(r3, r2, r1);
	BOOST_CHECK_EQUAL(v3[0], r3);
	BOOST_CHECK_EQUAL(v3[1], r2);
	BOOST_CHECK_EQUAL(v3[2], r1);

	T r4 = T(std::rand()%10000);
	auto v4 = eagine::math::vector<T, 4, V>::make(r4, r3, r2, r1);
	BOOST_CHECK_EQUAL(v4[0], r4);
	BOOST_CHECK_EQUAL(v4[1], r3);
	BOOST_CHECK_EQUAL(v4[2], r2);
	BOOST_CHECK_EQUAL(v4[3], r1);

	T r5 = T(std::rand()%10000);
	auto v5 = eagine::math::vector<T, 5, V>::make(r5, r4, r3, r2, r1);
	BOOST_CHECK_EQUAL(v5[0], r5);
	BOOST_CHECK_EQUAL(v5[1], r4);
	BOOST_CHECK_EQUAL(v5[2], r3);
	BOOST_CHECK_EQUAL(v5[3], r2);
	BOOST_CHECK_EQUAL(v5[4], r1);

	T r6 = T(std::rand()%10000);
	auto v6 = eagine::math::vector<T, 6, V>::make(r6, r5, r4, r3, r2, r1);
	BOOST_CHECK_EQUAL(v6[0], r6);
	BOOST_CHECK_EQUAL(v6[1], r5);
	BOOST_CHECK_EQUAL(v6[2], r4);
	BOOST_CHECK_EQUAL(v6[3], r3);
	BOOST_CHECK_EQUAL(v6[4], r2);
	BOOST_CHECK_EQUAL(v6[5], r1);

	T r7 = T(std::rand()%10000);
	auto v7 = eagine::math::vector<T, 7, V>::make(r7, r6, r5, r4, r3, r2, r1);
	BOOST_CHECK_EQUAL(v7[0], r7);
	BOOST_CHECK_EQUAL(v7[1], r6);
	BOOST_CHECK_EQUAL(v7[2], r5);
	BOOST_CHECK_EQUAL(v7[3], r4);
	BOOST_CHECK_EQUAL(v7[4], r3);
	BOOST_CHECK_EQUAL(v7[5], r2);
	BOOST_CHECK_EQUAL(v7[6], r1);

	T r8 = T(std::rand()%10000);
	auto v8 = eagine::math::vector<T, 8, V>::make(r8, r7, r6, r5, r4, r3, r2, r1);
	BOOST_CHECK_EQUAL(v8[0], r8);
	BOOST_CHECK_EQUAL(v8[1], r7);
	BOOST_CHECK_EQUAL(v8[2], r6);
	BOOST_CHECK_EQUAL(v8[3], r5);
	BOOST_CHECK_EQUAL(v8[4], r4);
	BOOST_CHECK_EQUAL(v8[5], r3);
	BOOST_CHECK_EQUAL(v8[6], r2);
	BOOST_CHECK_EQUAL(v8[7], r1);
}

template <typename T>
void test_math_vector_make_and_elem_T(void)
{
	test_math_vector_make_and_elem_TV<T, true>();
	test_math_vector_make_and_elem_TV<T,false>();
}

BOOST_AUTO_TEST_CASE(math_vector_make_and_elem)
{
	test_math_vector_make_and_elem_T<int>();
	test_math_vector_make_and_elem_T<float>();
	test_math_vector_make_and_elem_T<double>();
}

template <typename T, bool V>
void test_math_vector_from_and_elem_TV(void)
{
	T r1 = T(std::rand()%10000);
	auto v10 = eagine::math::vector<T, 1, V>::make(r1);
	BOOST_CHECK_EQUAL(v10[0], r1);

	T r2 = T(std::rand()%10000);
	auto v21 = eagine::math::vector<T, 2, V>::from(v10, r2);
	BOOST_CHECK_EQUAL(v21[0], r1);
	BOOST_CHECK_EQUAL(v21[1], r2);

	T r3 = T(std::rand()%10000);
	auto v32 = eagine::math::vector<T, 3, V>::from(v21, r3);
	BOOST_CHECK_EQUAL(v32[0], r1);
	BOOST_CHECK_EQUAL(v32[1], r2);
	BOOST_CHECK_EQUAL(v32[2], r3);

	auto v31 = eagine::math::vector<T, 3, V>::from(v10, r3);
	BOOST_CHECK_EQUAL(v31[0], r1);
	BOOST_CHECK_EQUAL(v31[1], r3);
	BOOST_CHECK_EQUAL(v31[2], r3);

	T r4 = T(std::rand()%10000);
	auto v43 = eagine::math::vector<T, 4, V>::from(v32, r4);
	BOOST_CHECK_EQUAL(v43[0], r1);
	BOOST_CHECK_EQUAL(v43[1], r2);
	BOOST_CHECK_EQUAL(v43[2], r3);
	BOOST_CHECK_EQUAL(v43[3], r4);

	auto v42 = eagine::math::vector<T, 4, V>::from(v21, r4);
	BOOST_CHECK_EQUAL(v42[0], r1);
	BOOST_CHECK_EQUAL(v42[1], r2);
	BOOST_CHECK_EQUAL(v42[2], r4);
	BOOST_CHECK_EQUAL(v42[3], r4);

	auto v41 = eagine::math::vector<T, 4, V>::from(v10, r4);
	BOOST_CHECK_EQUAL(v41[0], r1);
	BOOST_CHECK_EQUAL(v41[1], r4);
	BOOST_CHECK_EQUAL(v41[2], r4);
	BOOST_CHECK_EQUAL(v41[3], r4);

	T r5 = T(std::rand()%10000);
	auto v54 = eagine::math::vector<T, 5, V>::from(v43, r5);
	BOOST_CHECK_EQUAL(v54[0], r1);
	BOOST_CHECK_EQUAL(v54[1], r2);
	BOOST_CHECK_EQUAL(v54[2], r3);
	BOOST_CHECK_EQUAL(v54[3], r4);
	BOOST_CHECK_EQUAL(v54[4], r5);

	auto v53 = eagine::math::vector<T, 5, V>::from(v32, r5);
	BOOST_CHECK_EQUAL(v53[0], r1);
	BOOST_CHECK_EQUAL(v53[1], r2);
	BOOST_CHECK_EQUAL(v53[2], r3);
	BOOST_CHECK_EQUAL(v53[3], r5);
	BOOST_CHECK_EQUAL(v53[3], r5);

	auto v52 = eagine::math::vector<T, 5, V>::from(v21, r5);
	BOOST_CHECK_EQUAL(v52[0], r1);
	BOOST_CHECK_EQUAL(v52[1], r2);
	BOOST_CHECK_EQUAL(v52[2], r5);
	BOOST_CHECK_EQUAL(v52[3], r5);
	BOOST_CHECK_EQUAL(v52[4], r5);

	auto v51 = eagine::math::vector<T, 5, V>::from(v10, r5);
	BOOST_CHECK_EQUAL(v51[0], r1);
	BOOST_CHECK_EQUAL(v51[1], r5);
	BOOST_CHECK_EQUAL(v51[2], r5);
	BOOST_CHECK_EQUAL(v51[3], r5);
	BOOST_CHECK_EQUAL(v51[4], r5);
}

template <typename T>
void test_math_vector_from_and_elem_T(void)
{
	test_math_vector_from_and_elem_TV<T, true>();
	test_math_vector_from_and_elem_TV<T,false>();
}

BOOST_AUTO_TEST_CASE(math_vector_from_and_elem)
{
	test_math_vector_from_and_elem_T<int>();
	test_math_vector_from_and_elem_T<float>();
	test_math_vector_from_and_elem_T<double>();
}

template <typename T, bool V>
void test_math_vector_from2_and_elem_TV(void)
{
	T ra = T(std::rand()%10000);
	auto v1a = eagine::math::vector<T, 1, V>::make(ra);
	BOOST_CHECK_EQUAL(v1a[0], ra);

	T rb = T(std::rand()%10000);
	auto v1b = eagine::math::vector<T, 1, V>::make(rb);
	BOOST_CHECK_EQUAL(v1b[0], rb);

	auto v2aa = eagine::math::vector<T, 2, V>::from(v1a, v1a);
	BOOST_CHECK_EQUAL(v2aa[0], ra);
	BOOST_CHECK_EQUAL(v2aa[1], ra);

	auto v2ab = eagine::math::vector<T, 2, V>::from(v1a, v1b);
	BOOST_CHECK_EQUAL(v2ab[0], ra);
	BOOST_CHECK_EQUAL(v2ab[1], rb);

	auto v2bb = eagine::math::vector<T, 2, V>::from(v1b, v1b);
	BOOST_CHECK_EQUAL(v2bb[0], rb);
	BOOST_CHECK_EQUAL(v2bb[1], rb);

	auto v3aba = eagine::math::vector<T, 3, V>::from(v2ab, v1a);
	BOOST_CHECK_EQUAL(v3aba[0], ra);
	BOOST_CHECK_EQUAL(v3aba[1], rb);
	BOOST_CHECK_EQUAL(v3aba[2], ra);

	auto v3bab = eagine::math::vector<T, 3, V>::from(v1b, v2ab);
	BOOST_CHECK_EQUAL(v3bab[0], rb);
	BOOST_CHECK_EQUAL(v3bab[1], ra);
	BOOST_CHECK_EQUAL(v3bab[2], rb);

	auto v4abab = eagine::math::vector<T, 4, V>::from(v1a, v3bab);
	BOOST_CHECK_EQUAL(v4abab[0], ra);
	BOOST_CHECK_EQUAL(v4abab[1], rb);
	BOOST_CHECK_EQUAL(v4abab[2], ra);
	BOOST_CHECK_EQUAL(v4abab[3], rb);

	auto v4aabb = eagine::math::vector<T, 4, V>::from(v2aa, v2bb);
	BOOST_CHECK_EQUAL(v4aabb[0], ra);
	BOOST_CHECK_EQUAL(v4aabb[1], ra);
	BOOST_CHECK_EQUAL(v4aabb[2], rb);
	BOOST_CHECK_EQUAL(v4aabb[3], rb);

	auto v4baba = eagine::math::vector<T, 4, V>::from(v3bab, v1a);
	BOOST_CHECK_EQUAL(v4baba[0], rb);
	BOOST_CHECK_EQUAL(v4baba[1], ra);
	BOOST_CHECK_EQUAL(v4baba[2], rb);
	BOOST_CHECK_EQUAL(v4baba[3], ra);

	auto v5ababa = eagine::math::vector<T, 5, V>::from(v1a, v4baba);
	BOOST_CHECK_EQUAL(v5ababa[0], ra);
	BOOST_CHECK_EQUAL(v5ababa[1], rb);
	BOOST_CHECK_EQUAL(v5ababa[2], ra);
	BOOST_CHECK_EQUAL(v5ababa[3], rb);
	BOOST_CHECK_EQUAL(v5ababa[4], ra);

	auto v5aabab = eagine::math::vector<T, 5, V>::from(v2aa, v3bab);
	BOOST_CHECK_EQUAL(v5aabab[0], ra);
	BOOST_CHECK_EQUAL(v5aabab[1], ra);
	BOOST_CHECK_EQUAL(v5aabab[2], rb);
	BOOST_CHECK_EQUAL(v5aabab[3], ra);
	BOOST_CHECK_EQUAL(v5aabab[4], rb);

	auto v5ababb = eagine::math::vector<T, 5, V>::from(v3aba, v2bb);
	BOOST_CHECK_EQUAL(v5ababb[0], ra);
	BOOST_CHECK_EQUAL(v5ababb[1], rb);
	BOOST_CHECK_EQUAL(v5ababb[2], ra);
	BOOST_CHECK_EQUAL(v5ababb[3], rb);
	BOOST_CHECK_EQUAL(v5ababb[4], rb);

	auto v5babab = eagine::math::vector<T, 5, V>::from(v4baba, v1b);
	BOOST_CHECK_EQUAL(v5babab[0], rb);
	BOOST_CHECK_EQUAL(v5babab[1], ra);
	BOOST_CHECK_EQUAL(v5babab[2], rb);
	BOOST_CHECK_EQUAL(v5babab[3], ra);
	BOOST_CHECK_EQUAL(v5babab[4], rb);
}

template <typename T>
void test_math_vector_from2_and_elem_T(void)
{
	test_math_vector_from2_and_elem_TV<T, true>();
	test_math_vector_from2_and_elem_TV<T,false>();
}

BOOST_AUTO_TEST_CASE(math_vector_from2_and_elem)
{
	test_math_vector_from2_and_elem_T<int>();
	test_math_vector_from2_and_elem_T<float>();
	test_math_vector_from2_and_elem_T<double>();
}

template <typename T, unsigned N, bool V>
void test_math_vector_from3_and_elem_TNV(void)
{
	T a[N];
	for(unsigned i=0; i<N; ++i)
	{
		a[i] = T(std::rand()%10000);
	}

	auto v = eagine::math::vector<T, N, V>::from(a, N);

	for(unsigned i=0; i<N; ++i)
	{
		BOOST_CHECK_EQUAL(v[i], a[i]);
	}
}

template <typename T, bool V>
void test_math_vector_from3_and_elem_TV(void)
{
	test_math_vector_from3_and_elem_TNV<T, 1, V>();
	test_math_vector_from3_and_elem_TNV<T, 2, V>();
	test_math_vector_from3_and_elem_TNV<T, 3, V>();
	test_math_vector_from3_and_elem_TNV<T, 4, V>();
	test_math_vector_from3_and_elem_TNV<T, 5, V>();
	test_math_vector_from3_and_elem_TNV<T, 6, V>();
	test_math_vector_from3_and_elem_TNV<T, 7, V>();
	test_math_vector_from3_and_elem_TNV<T, 8, V>();
	test_math_vector_from3_and_elem_TNV<T, 12, V>();
	test_math_vector_from3_and_elem_TNV<T, 15, V>();
	test_math_vector_from3_and_elem_TNV<T, 20, V>();
}

template <typename T>
void test_math_vector_from3_and_elem_T(void)
{
	test_math_vector_from3_and_elem_TV<T, true>();
	test_math_vector_from3_and_elem_TV<T,false>();
}

BOOST_AUTO_TEST_CASE(math_vector_from3_and_elem)
{
	test_math_vector_from3_and_elem_T<int>();
	test_math_vector_from3_and_elem_T<float>();
	test_math_vector_from3_and_elem_T<double>();
}

template <typename T, unsigned N, bool V>
void test_math_vector_from4_and_elem_TNV(void)
{
	for(unsigned j=0; j<N; ++j)
	{
		T a[N];
		for(unsigned i=0; i<N-j; ++i)
		{
			a[i] = T(std::rand()%10000);
		}

		T r = T(std::rand()%10000);

		auto v = eagine::math::vector<T, N, V>::from(a, N-j, r);

		for(unsigned i=0; i<N-j; ++i)
		{
			BOOST_CHECK_EQUAL(v[i], a[i]);
		}

		for(unsigned i=N-j; i<N; ++i)
		{
			BOOST_CHECK_EQUAL(v[i], r);
		}
	}
}

template <typename T, bool V>
void test_math_vector_from4_and_elem_TV(void)
{
	test_math_vector_from4_and_elem_TNV<T, 1, V>();
	test_math_vector_from4_and_elem_TNV<T, 2, V>();
	test_math_vector_from4_and_elem_TNV<T, 3, V>();
	test_math_vector_from4_and_elem_TNV<T, 4, V>();
	test_math_vector_from4_and_elem_TNV<T, 5, V>();
	test_math_vector_from4_and_elem_TNV<T, 6, V>();
	test_math_vector_from4_and_elem_TNV<T, 7, V>();
	test_math_vector_from4_and_elem_TNV<T, 8, V>();
	test_math_vector_from4_and_elem_TNV<T, 13, V>();
	test_math_vector_from4_and_elem_TNV<T, 16, V>();
	test_math_vector_from4_and_elem_TNV<T, 22, V>();
}

template <typename T>
void test_math_vector_from4_and_elem_T(void)
{
	test_math_vector_from4_and_elem_TV<T, true>();
	test_math_vector_from4_and_elem_TV<T,false>();
}

BOOST_AUTO_TEST_CASE(math_vector_from4_and_elem)
{
	test_math_vector_from4_and_elem_T<int>();
	test_math_vector_from4_and_elem_T<float>();
	test_math_vector_from4_and_elem_T<double>();
}

//TODO

BOOST_AUTO_TEST_SUITE_END()
