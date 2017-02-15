/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/array_size.hpp>
#define BOOST_TEST_MODULE EAGINE_array_size
#include "../unit_test.inl"

BOOST_AUTO_TEST_SUITE(array_size_tests)

BOOST_AUTO_TEST_CASE(array_size_1)
{
	using namespace eagine;

	float f3[] = {1.f, 2.f, 3.f};
	int i5[] = {1,2,3,4,5};
	int i9[] = {1,2,3,4,5,6,7,8,9};
	const char* s7[] = {"A", "B", "C", "D", "E", "F", "G"};

	BOOST_CHECK_EQUAL(array_size(f3), 3);
	BOOST_CHECK_EQUAL(array_size(i5), 5);
	BOOST_CHECK_EQUAL(array_size(s7), 7);
	BOOST_CHECK_EQUAL(array_size(i9), 9);
}

BOOST_AUTO_TEST_SUITE_END()
