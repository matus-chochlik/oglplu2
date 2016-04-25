/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_vararray
#include <boost/test/unit_test.hpp>

#include <eagine/vararray.hpp>
#include <string>
#include <cstring>


BOOST_AUTO_TEST_SUITE(vararray_tests)

template <typename T, typename S, S N>
void test_vararray_1_TSN(void)
{
	using namespace eagine;

	basic_vararray_store<T, S, N> vas;
	basic_vararray<T, S>& va = vas;

	BOOST_CHECK_EQUAL(va.instance_size(), sizeof(vas));

	BOOST_CHECK_EQUAL(va.size(), N);

	int v = 0;

	for(T& x : va)
	{
		x = T(v++);
	}

	BOOST_CHECK_EQUAL(va.size(), v);

	v = 0;

	for(auto i=va.begin(); i!=va.end(); ++i)
	{
		BOOST_CHECK_EQUAL(*i, T(v++));
	}

	BOOST_CHECK_EQUAL(va.size(), v);
}

template <typename T, typename S>
void test_vararray_1_TS(void)
{
	test_vararray_1_TSN<T, S,  1>();
	test_vararray_1_TSN<T, S,  2>();
	test_vararray_1_TSN<T, S,  5>();
	test_vararray_1_TSN<T, S,  7>();
	test_vararray_1_TSN<T, S, 11>();
	test_vararray_1_TSN<T, S, 19>();
	test_vararray_1_TSN<T, S, 40>();
	test_vararray_1_TSN<T, S,101>();
}

template <typename T>
void test_vararray_1_T(void)
{
	test_vararray_1_TS<T, std::size_t>();
	test_vararray_1_TS<T, unsigned short>();
}

BOOST_AUTO_TEST_CASE(vararray_1)
{
	test_vararray_1_T<char>();
	test_vararray_1_T<short>();
	test_vararray_1_T<int>();
	test_vararray_1_T<double>();
}

// TODO
BOOST_AUTO_TEST_SUITE_END()
