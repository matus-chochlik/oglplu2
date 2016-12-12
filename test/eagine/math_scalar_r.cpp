/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_math_scalar
#include <boost/test/unit_test.hpp>

#include <eagine/math/scalar.hpp>

BOOST_AUTO_TEST_SUITE(math_scalar_tests)

template <typename T, bool V>
void test_math_scalar_default_ctr_TV(void)
{
	eagine::math::scalar<T, 1, V> s1; (void)s1;
	eagine::math::scalar<T, 2, V> s2; (void)s2;
	eagine::math::scalar<T, 3, V> s3; (void)s3;
	eagine::math::scalar<T, 4, V> s4; (void)s4;
	eagine::math::scalar<T, 5, V> s5; (void)s5;
	eagine::math::scalar<T, 6, V> s6; (void)s6;
	eagine::math::scalar<T, 7, V> s7; (void)s7;
	eagine::math::scalar<T, 8, V> s8; (void)s8;
	eagine::math::scalar<T,11, V> s11; (void)s11;
	eagine::math::scalar<T,17, V> s17; (void)s17;
	eagine::math::scalar<T,23, V> s23; (void)s23;

}

template <typename T>
void test_math_scalar_default_ctr_T(void)
{
	test_math_scalar_default_ctr_TV<T, true>();
	test_math_scalar_default_ctr_TV<T,false>();
}

BOOST_AUTO_TEST_CASE(math_scalar_default_ctr)
{
	test_math_scalar_default_ctr_T<int>();
	test_math_scalar_default_ctr_T<float>();
	test_math_scalar_default_ctr_T<double>();
}

template <typename T, bool V>
void test_math_scalar_make_and_conv_TV(void)
{
	auto s1  = eagine::math::scalar<T, 1, V>::make(1);
	T s1v = s1;
	BOOST_CHECK_EQUAL(s1v, T(1));

	auto s2  = eagine::math::scalar<T, 2, V>::make(2);
	T s2v = s2;
	BOOST_CHECK_EQUAL(s2v, T(2));

	auto s3  = eagine::math::scalar<T, 3, V>::make(3);
	T s3v = s3;
	BOOST_CHECK_EQUAL(s3v, T(3));

	auto s4  = eagine::math::scalar<T, 4, V>::make(4);
	T s4v = s4;
	BOOST_CHECK_EQUAL(s4v, T(4));

	auto s5  = eagine::math::scalar<T, 5, V>::make(5);
	T s5v = s5;
	BOOST_CHECK_EQUAL(s5v, T(5));

	auto s6  = eagine::math::scalar<T, 6, V>::make(6);
	T s6v = s6;
	BOOST_CHECK_EQUAL(s6v, T(6));

	auto s7  = eagine::math::scalar<T, 7, V>::make(7);
	T s7v = s7;
	BOOST_CHECK_EQUAL(s7v, T(7));

	auto s8  = eagine::math::scalar<T, 8, V>::make(8);
	T s8v = s8;
	BOOST_CHECK_EQUAL(s8v, T(8));

	auto s11 = eagine::math::scalar<T,11, V>::make(11);
	T s11v = s11;
	BOOST_CHECK_EQUAL(s11v, T(11));

	auto s17 = eagine::math::scalar<T,17, V>::make(17);
	T s17v = s17;
	BOOST_CHECK_EQUAL(s17v, T(17));

	auto s23  = eagine::math::scalar<T,23, V>::make(23);
	T s23v = s23;
	BOOST_CHECK_EQUAL(s23v, T(23));
}

template <typename T>
void test_math_scalar_make_and_conv_T(void)
{
	test_math_scalar_make_and_conv_TV<T, true>();
	test_math_scalar_make_and_conv_TV<T,false>();
}

BOOST_AUTO_TEST_CASE(math_scalar_make_and_conv)
{
	test_math_scalar_make_and_conv_T<int>();
	test_math_scalar_make_and_conv_T<float>();
	test_math_scalar_make_and_conv_T<double>();
}

template <typename T, bool V>
void test_math_scalar_copy_ctr_TV(void)
{
	auto s1 = eagine::math::scalar<T, 1, V>::make(1);
	eagine::math::scalar<T, 1, V> s1c = s1;
	BOOST_CHECK_EQUAL(s1c, T(1));

	auto s2 = eagine::math::scalar<T, 2, V>::make(2);
	eagine::math::scalar<T, 2, V> s2c = s2;
	BOOST_CHECK_EQUAL(s2c, T(2));

	auto s3 = eagine::math::scalar<T, 3, V>::make(3);
	eagine::math::scalar<T, 3, V> s3c = s3;
	BOOST_CHECK_EQUAL(s3c, T(3));

	auto s4 = eagine::math::scalar<T, 4, V>::make(4);
	eagine::math::scalar<T, 4, V> s4c = s4;
	BOOST_CHECK_EQUAL(s4c, T(4));

	auto s5 = eagine::math::scalar<T, 5, V>::make(5);
	eagine::math::scalar<T, 5, V> s5c = s5;
	BOOST_CHECK_EQUAL(s5c, T(5));

	auto s6 = eagine::math::scalar<T, 6, V>::make(6);
	eagine::math::scalar<T, 6, V> s6c = s6;
	BOOST_CHECK_EQUAL(s6c, T(6));

	auto s7 = eagine::math::scalar<T, 7, V>::make(7);
	eagine::math::scalar<T, 7, V> s7c = s7;
	BOOST_CHECK_EQUAL(s7c, T(7));

	auto s8 = eagine::math::scalar<T, 8, V>::make(8);
	eagine::math::scalar<T, 8, V> s8c = s8;
	BOOST_CHECK_EQUAL(s8c, T(8));

	auto s11 = eagine::math::scalar<T,11, V>::make(11);
	eagine::math::scalar<T,11, V> s11c = s11;
	BOOST_CHECK_EQUAL(s11c, T(11));

	auto s17 = eagine::math::scalar<T,17, V>::make(17);
	eagine::math::scalar<T,17, V> s17c = s17;
	BOOST_CHECK_EQUAL(s17c, T(17));

	auto s23 = eagine::math::scalar<T,23, V>::make(23);
	eagine::math::scalar<T,23, V> s23c = s23;
	BOOST_CHECK_EQUAL(s23c, T(23));
}

template <typename T>
void test_math_scalar_copy_ctr_T(void)
{
	test_math_scalar_copy_ctr_TV<T, true>();
	test_math_scalar_copy_ctr_TV<T,false>();
}

BOOST_AUTO_TEST_CASE(math_scalar_copy_ctr)
{
	test_math_scalar_copy_ctr_T<int>();
	test_math_scalar_copy_ctr_T<float>();
	test_math_scalar_copy_ctr_T<double>();
}
//TODO

BOOST_AUTO_TEST_SUITE_END()
