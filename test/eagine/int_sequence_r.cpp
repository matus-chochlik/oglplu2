/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_int_sequence
#include <boost/test/unit_test.hpp>

#include <eagine/int_sequence.hpp>

BOOST_AUTO_TEST_SUITE(int_sequence_tests)

template <typename Int, Int ... I>
void test_int_sequence_1I(std::integer_sequence<Int, I...>)
{
	const Int a[sizeof...(I)] = {I...};

	for(std::size_t i=0; i<sizeof...(I); ++i)
	{
		BOOST_CHECK_EQUAL(Int(i), a[i]);
	}
}

template <typename Int>
void test_int_sequence_1(void)
{
	test_int_sequence_1I(std::make_integer_sequence<Int, 1>());
	test_int_sequence_1I(std::make_integer_sequence<Int, 2>());
	test_int_sequence_1I(std::make_integer_sequence<Int, 3>());
	test_int_sequence_1I(std::make_integer_sequence<Int, 4>());
	test_int_sequence_1I(std::make_integer_sequence<Int, 5>());
	test_int_sequence_1I(std::make_integer_sequence<Int, 7>());
	test_int_sequence_1I(std::make_integer_sequence<Int, 9>());
	test_int_sequence_1I(std::make_integer_sequence<Int,11>());
	test_int_sequence_1I(std::make_integer_sequence<Int,13>());
	test_int_sequence_1I(std::make_integer_sequence<Int,17>());
	test_int_sequence_1I(std::make_integer_sequence<Int,23>());
}

BOOST_AUTO_TEST_CASE(int_sequence_1)
{
	test_int_sequence_1<short>();
	test_int_sequence_1<int>();
	test_int_sequence_1<long>();

	test_int_sequence_1<unsigned short>();
	test_int_sequence_1<unsigned int>();
	test_int_sequence_1<unsigned long>();
}

template <std::size_t ... I>
void test_int_sequence_2I(std::index_sequence<I...>)
{
	const std::size_t a[sizeof...(I)] = {I...};

	for(std::size_t i=0; i<sizeof...(I); ++i)
	{
		BOOST_CHECK_EQUAL(i, a[i]);
	}
}

BOOST_AUTO_TEST_CASE(int_sequence_2)
{
	test_int_sequence_2I(std::make_index_sequence<1>());
	test_int_sequence_2I(std::make_index_sequence<2>());
	test_int_sequence_2I(std::make_index_sequence<3>());
	test_int_sequence_2I(std::make_index_sequence<4>());
	test_int_sequence_2I(std::make_index_sequence<5>());
	test_int_sequence_2I(std::make_index_sequence<7>());
	test_int_sequence_2I(std::make_index_sequence<9>());
	test_int_sequence_2I(std::make_index_sequence<11>());
	test_int_sequence_2I(std::make_index_sequence<13>());
	test_int_sequence_2I(std::make_index_sequence<17>());
	test_int_sequence_2I(std::make_index_sequence<23>());
}

BOOST_AUTO_TEST_SUITE_END()
