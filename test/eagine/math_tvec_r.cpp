/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_math_tvec
#include <boost/test/unit_test.hpp>

#include <eagine/math/tvec.hpp>
#include <cstdlib>

BOOST_AUTO_TEST_SUITE(math_tvec_tests)

template <typename T, unsigned N, bool V>
void test_math_tvec_default_ctr_TNV(void)
{
	eagine::math::tvec<T, N, V> v;
	for(unsigned i=0; i<N; ++i)
	{
		BOOST_CHECK_EQUAL(v[i], T(0));
	}
}

template <typename T, bool V>
void test_math_tvec_default_ctr_TV(void)
{
	test_math_tvec_default_ctr_TNV<T, 1, V>();
	test_math_tvec_default_ctr_TNV<T, 2, V>();
	test_math_tvec_default_ctr_TNV<T, 3, V>();
	test_math_tvec_default_ctr_TNV<T, 4, V>();
	test_math_tvec_default_ctr_TNV<T, 5, V>();
	test_math_tvec_default_ctr_TNV<T, 6, V>();
	test_math_tvec_default_ctr_TNV<T, 7, V>();
	test_math_tvec_default_ctr_TNV<T, 8, V>();
	test_math_tvec_default_ctr_TNV<T,11, V>();
	test_math_tvec_default_ctr_TNV<T,13, V>();
	test_math_tvec_default_ctr_TNV<T,19, V>();
	test_math_tvec_default_ctr_TNV<T,23, V>();
}

template <typename T>
void test_math_tvec_default_ctr_T(void)
{
	test_math_tvec_default_ctr_TV<T, true>();
	test_math_tvec_default_ctr_TV<T,false>();
}

BOOST_AUTO_TEST_CASE(math_tvec_default_ctr)
{
	test_math_tvec_default_ctr_T<int>();
	test_math_tvec_default_ctr_T<float>();
	test_math_tvec_default_ctr_T<double>();
}

template <typename T, unsigned N, bool V>
void test_math_tvec_fill_ctr_TNV(void)
{
	T r = T(std::rand() % 10000);
	eagine::math::tvec<T, N, V> v(r);
	for(unsigned i=0; i<N; ++i)
	{
		BOOST_CHECK_EQUAL(v[i], r);
	}
}

template <typename T, bool V>
void test_math_tvec_fill_ctr_TV(void)
{
	test_math_tvec_fill_ctr_TNV<T, 1, V>();
	test_math_tvec_fill_ctr_TNV<T, 2, V>();
	test_math_tvec_fill_ctr_TNV<T, 3, V>();
	test_math_tvec_fill_ctr_TNV<T, 4, V>();
	test_math_tvec_fill_ctr_TNV<T, 5, V>();
	test_math_tvec_fill_ctr_TNV<T, 6, V>();
	test_math_tvec_fill_ctr_TNV<T, 7, V>();
	test_math_tvec_fill_ctr_TNV<T, 8, V>();
	test_math_tvec_fill_ctr_TNV<T,11, V>();
	test_math_tvec_fill_ctr_TNV<T,13, V>();
	test_math_tvec_fill_ctr_TNV<T,19, V>();
	test_math_tvec_fill_ctr_TNV<T,23, V>();
}

template <typename T>
void test_math_tvec_fill_ctr_T(void)
{
	test_math_tvec_fill_ctr_TV<T, true>();
	test_math_tvec_fill_ctr_TV<T,false>();
}

BOOST_AUTO_TEST_CASE(math_tvec_fill_ctr)
{
	test_math_tvec_fill_ctr_T<int>();
	test_math_tvec_fill_ctr_T<float>();
	test_math_tvec_fill_ctr_T<double>();
}

template <typename T, unsigned N, bool V>
void test_math_tvec_vector_ctr_TNV(void)
{
	T r = T(std::rand() % 10000);
	eagine::math::tvec<T, N, V> v(eagine::math::vector<T, N, V>::fill(r));
	for(unsigned i=0; i<N; ++i)
	{
		BOOST_CHECK_EQUAL(v[i], r);
	}
}

template <typename T, bool V>
void test_math_tvec_vector_ctr_TV(void)
{
	test_math_tvec_vector_ctr_TNV<T, 1, V>();
	test_math_tvec_vector_ctr_TNV<T, 2, V>();
	test_math_tvec_vector_ctr_TNV<T, 3, V>();
	test_math_tvec_vector_ctr_TNV<T, 4, V>();
	test_math_tvec_vector_ctr_TNV<T, 5, V>();
	test_math_tvec_vector_ctr_TNV<T, 6, V>();
	test_math_tvec_vector_ctr_TNV<T, 7, V>();
	test_math_tvec_vector_ctr_TNV<T, 8, V>();
	test_math_tvec_vector_ctr_TNV<T,11, V>();
	test_math_tvec_vector_ctr_TNV<T,13, V>();
	test_math_tvec_vector_ctr_TNV<T,19, V>();
	test_math_tvec_vector_ctr_TNV<T,23, V>();
}

template <typename T>
void test_math_tvec_vector_ctr_T(void)
{
	test_math_tvec_vector_ctr_TV<T, true>();
	test_math_tvec_vector_ctr_TV<T,false>();
}

BOOST_AUTO_TEST_CASE(math_tvec_vector_ctr)
{
	test_math_tvec_vector_ctr_T<int>();
	test_math_tvec_vector_ctr_T<float>();
	test_math_tvec_vector_ctr_T<double>();
}

template <typename T, unsigned N, bool V>
void test_math_tvec_cary_ctr_TNV(void)
{
	T a[N];

	for(unsigned i=0; i<N; ++i)
	{
		a[i] = T(std::rand()%10000);
	}

	eagine::math::tvec<T, N, V> v(a);

	for(unsigned i=0; i<N; ++i)
	{
		BOOST_CHECK_EQUAL(v[i], a[i]);
	}
}

template <typename T, bool V>
void test_math_tvec_cary_ctr_TV(void)
{
	test_math_tvec_cary_ctr_TNV<T, 1, V>();
	test_math_tvec_cary_ctr_TNV<T, 2, V>();
	test_math_tvec_cary_ctr_TNV<T, 3, V>();
	test_math_tvec_cary_ctr_TNV<T, 4, V>();
	test_math_tvec_cary_ctr_TNV<T, 5, V>();
	test_math_tvec_cary_ctr_TNV<T, 6, V>();
	test_math_tvec_cary_ctr_TNV<T, 7, V>();
	test_math_tvec_cary_ctr_TNV<T, 8, V>();
	test_math_tvec_cary_ctr_TNV<T,11, V>();
	test_math_tvec_cary_ctr_TNV<T,13, V>();
	test_math_tvec_cary_ctr_TNV<T,19, V>();
	test_math_tvec_cary_ctr_TNV<T,23, V>();
}

template <typename T>
void test_math_tvec_cary_ctr_T(void)
{
	test_math_tvec_cary_ctr_TV<T, true>();
	test_math_tvec_cary_ctr_TV<T,false>();
}

BOOST_AUTO_TEST_CASE(math_tvec_cary_ctr)
{
	test_math_tvec_cary_ctr_T<int>();
	test_math_tvec_cary_ctr_T<float>();
	test_math_tvec_cary_ctr_T<double>();
}

template <typename T, bool V>
void test_math_tvec_pack_ctr_TV(void)
{
	T r1 = T(std::rand()%10000);
	eagine::math::tvec<T, 1, V> v1(r1);
	BOOST_CHECK_EQUAL(v1[0], r1);

	T r2 = T(std::rand()%10000);
	eagine::math::tvec<T, 2, V> v2(r1, r2);
	BOOST_CHECK_EQUAL(v2[0], r1);
	BOOST_CHECK_EQUAL(v2[1], r2);

	T r3 = T(std::rand()%10000);
	eagine::math::tvec<T, 3, V> v3(r1, r2, r3);
	BOOST_CHECK_EQUAL(v3[0], r1);
	BOOST_CHECK_EQUAL(v3[1], r2);
	BOOST_CHECK_EQUAL(v3[2], r3);

	T r4 = T(std::rand()%10000);
	eagine::math::tvec<T, 4, V> v4(r1, r2, r3, r4);
	BOOST_CHECK_EQUAL(v4[0], r1);
	BOOST_CHECK_EQUAL(v4[1], r2);
	BOOST_CHECK_EQUAL(v4[2], r3);
	BOOST_CHECK_EQUAL(v4[3], r4);

	T r5 = T(std::rand()%10000);
	eagine::math::tvec<T, 5, V> v5(r1, r2, r3, r4, r5);
	BOOST_CHECK_EQUAL(v5[0], r1);
	BOOST_CHECK_EQUAL(v5[1], r2);
	BOOST_CHECK_EQUAL(v5[2], r3);
	BOOST_CHECK_EQUAL(v5[3], r4);
	BOOST_CHECK_EQUAL(v5[4], r5);

	T r6 = T(std::rand()%10000);
	eagine::math::tvec<T, 6, V> v6(r1, r2, r3, r4, r5, r6);
	BOOST_CHECK_EQUAL(v6[0], r1);
	BOOST_CHECK_EQUAL(v6[1], r2);
	BOOST_CHECK_EQUAL(v6[2], r3);
	BOOST_CHECK_EQUAL(v6[3], r4);
	BOOST_CHECK_EQUAL(v6[4], r5);
	BOOST_CHECK_EQUAL(v6[5], r6);
}

template <typename T>
void test_math_tvec_pack_ctr_T(void)
{
	test_math_tvec_pack_ctr_TV<T, true>();
	test_math_tvec_pack_ctr_TV<T,false>();
}

BOOST_AUTO_TEST_CASE(math_tvec_pack_ctr)
{
	test_math_tvec_pack_ctr_T<int>();
	test_math_tvec_pack_ctr_T<float>();
	test_math_tvec_pack_ctr_T<double>();
}

template <typename T, bool V>
void test_math_tvec_vec_val_ctr_TV(void)
{
	T r1 = T(std::rand()%10000);
	eagine::math::tvec<T, 1, V> v10(r1);
	BOOST_CHECK_EQUAL(v10[0], r1);

	T r2 = T(std::rand()%10000);
	eagine::math::tvec<T, 2, V> v21(v10, r2);
	BOOST_CHECK_EQUAL(v21[0], r1);
	BOOST_CHECK_EQUAL(v21[1], r2);

	T r3 = T(std::rand()%10000);
	eagine::math::tvec<T, 3, V> v31(v10, r3);
	BOOST_CHECK_EQUAL(v31[0], r1);
	BOOST_CHECK_EQUAL(v31[1], r3);
	BOOST_CHECK_EQUAL(v31[2], r3);

	eagine::math::tvec<T, 3, V> v32(v21, r3);
	BOOST_CHECK_EQUAL(v32[0], r1);
	BOOST_CHECK_EQUAL(v32[1], r2);
	BOOST_CHECK_EQUAL(v32[2], r3);

	T r4 = T(std::rand()%10000);
	eagine::math::tvec<T, 4, V> v41(v10, r4);
	BOOST_CHECK_EQUAL(v41[0], r1);
	BOOST_CHECK_EQUAL(v41[1], r4);
	BOOST_CHECK_EQUAL(v41[2], r4);
	BOOST_CHECK_EQUAL(v41[3], r4);

	eagine::math::tvec<T, 4, V> v42(v21, r4);
	BOOST_CHECK_EQUAL(v42[0], r1);
	BOOST_CHECK_EQUAL(v42[1], r2);
	BOOST_CHECK_EQUAL(v42[2], r4);
	BOOST_CHECK_EQUAL(v42[3], r4);

	eagine::math::tvec<T, 4, V> v43(v32, r4);
	BOOST_CHECK_EQUAL(v43[0], r1);
	BOOST_CHECK_EQUAL(v43[1], r2);
	BOOST_CHECK_EQUAL(v43[2], r3);
	BOOST_CHECK_EQUAL(v43[3], r4);

	T r5 = T(std::rand()%10000);
	eagine::math::tvec<T, 5, V> v51(v10, r5);
	BOOST_CHECK_EQUAL(v51[0], r1);
	BOOST_CHECK_EQUAL(v51[1], r5);
	BOOST_CHECK_EQUAL(v51[2], r5);
	BOOST_CHECK_EQUAL(v51[3], r5);
	BOOST_CHECK_EQUAL(v51[4], r5);

	eagine::math::tvec<T, 5, V> v52(v21, r5);
	BOOST_CHECK_EQUAL(v52[0], r1);
	BOOST_CHECK_EQUAL(v52[1], r2);
	BOOST_CHECK_EQUAL(v52[2], r5);
	BOOST_CHECK_EQUAL(v52[3], r5);
	BOOST_CHECK_EQUAL(v52[4], r5);

	eagine::math::tvec<T, 5, V> v53(v32, r5);
	BOOST_CHECK_EQUAL(v53[0], r1);
	BOOST_CHECK_EQUAL(v53[1], r2);
	BOOST_CHECK_EQUAL(v53[2], r3);
	BOOST_CHECK_EQUAL(v53[3], r5);
	BOOST_CHECK_EQUAL(v53[4], r5);

	eagine::math::tvec<T, 5, V> v54(v43, r5);
	BOOST_CHECK_EQUAL(v54[0], r1);
	BOOST_CHECK_EQUAL(v54[1], r2);
	BOOST_CHECK_EQUAL(v54[2], r3);
	BOOST_CHECK_EQUAL(v54[3], r4);
	BOOST_CHECK_EQUAL(v54[4], r5);
}

template <typename T>
void test_math_tvec_vec_val_ctr_T(void)
{
	test_math_tvec_vec_val_ctr_TV<T, true>();
	test_math_tvec_vec_val_ctr_TV<T,false>();
}

BOOST_AUTO_TEST_CASE(math_tvec_vec_val_ctr)
{
	test_math_tvec_vec_val_ctr_T<int>();
	test_math_tvec_vec_val_ctr_T<float>();
	test_math_tvec_vec_val_ctr_T<double>();
}

template <typename T, bool V>
void test_math_tvec_vec_vec_ctr_TV(void)
{
	T ra = T(std::rand()%10000);
	eagine::math::tvec<T, 1, V> va(ra);
	BOOST_CHECK_EQUAL(va[0], ra);

	T rb = T(std::rand()%10000);
	eagine::math::tvec<T, 1, V> vb(rb);
	BOOST_CHECK_EQUAL(vb[0], rb);

	eagine::math::tvec<T, 2, V> vaa(va, va);
	BOOST_CHECK_EQUAL(vaa[0], ra);
	BOOST_CHECK_EQUAL(vaa[1], ra);

	eagine::math::tvec<T, 2, V> vab(va, vb);
	BOOST_CHECK_EQUAL(vab[0], ra);
	BOOST_CHECK_EQUAL(vab[1], rb);

	eagine::math::tvec<T, 2, V> vbb(vb, vb);
	BOOST_CHECK_EQUAL(vbb[0], rb);
	BOOST_CHECK_EQUAL(vbb[1], rb);

	eagine::math::tvec<T, 3, V> vaba(vab, va);
	BOOST_CHECK_EQUAL(vaba[0], ra);
	BOOST_CHECK_EQUAL(vaba[1], rb);
	BOOST_CHECK_EQUAL(vaba[2], ra);

	eagine::math::tvec<T, 3, V> vbab(vb, vab);
	BOOST_CHECK_EQUAL(vbab[0], rb);
	BOOST_CHECK_EQUAL(vbab[1], ra);
	BOOST_CHECK_EQUAL(vbab[2], rb);

	eagine::math::tvec<T, 4, V> vabab(vaba, vb);
	BOOST_CHECK_EQUAL(vabab[0], ra);
	BOOST_CHECK_EQUAL(vabab[1], rb);
	BOOST_CHECK_EQUAL(vabab[2], ra);
	BOOST_CHECK_EQUAL(vabab[3], rb);

	eagine::math::tvec<T, 4, V> vaabb(vaa, vbb);
	BOOST_CHECK_EQUAL(vaabb[0], ra);
	BOOST_CHECK_EQUAL(vaabb[1], ra);
	BOOST_CHECK_EQUAL(vaabb[2], rb);
	BOOST_CHECK_EQUAL(vaabb[3], rb);

	eagine::math::tvec<T, 5, V> vababa(vabab, va);
	BOOST_CHECK_EQUAL(vababa[0], ra);
	BOOST_CHECK_EQUAL(vababa[1], rb);
	BOOST_CHECK_EQUAL(vababa[2], ra);
	BOOST_CHECK_EQUAL(vababa[3], rb);
	BOOST_CHECK_EQUAL(vababa[4], ra);

	eagine::math::tvec<T, 5, V> vababb(vaba, vbb);
	BOOST_CHECK_EQUAL(vababb[0], ra);
	BOOST_CHECK_EQUAL(vababb[1], rb);
	BOOST_CHECK_EQUAL(vababb[2], ra);
	BOOST_CHECK_EQUAL(vababb[3], rb);
	BOOST_CHECK_EQUAL(vababb[4], rb);

	eagine::math::tvec<T, 5, V> vaabab(vaa, vbab);
	BOOST_CHECK_EQUAL(vaabab[0], ra);
	BOOST_CHECK_EQUAL(vaabab[1], ra);
	BOOST_CHECK_EQUAL(vaabab[2], rb);
	BOOST_CHECK_EQUAL(vaabab[3], ra);
	BOOST_CHECK_EQUAL(vaabab[4], rb);

	eagine::math::tvec<T, 5, V> vbabab(vb, vabab);
	BOOST_CHECK_EQUAL(vbabab[0], rb);
	BOOST_CHECK_EQUAL(vbabab[1], ra);
	BOOST_CHECK_EQUAL(vbabab[2], rb);
	BOOST_CHECK_EQUAL(vbabab[3], ra);
	BOOST_CHECK_EQUAL(vbabab[4], rb);
}

template <typename T>
void test_math_tvec_vec_vec_ctr_T(void)
{
	test_math_tvec_vec_vec_ctr_TV<T, true>();
	test_math_tvec_vec_vec_ctr_TV<T,false>();
}

BOOST_AUTO_TEST_CASE(math_tvec_vec_vec_ctr)
{
	test_math_tvec_vec_vec_ctr_T<int>();
	test_math_tvec_vec_vec_ctr_T<float>();
	test_math_tvec_vec_vec_ctr_T<double>();
}

BOOST_AUTO_TEST_SUITE_END()
