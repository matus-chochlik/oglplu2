/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_all_are_same
#include <boost/test/unit_test.hpp>

#include <eagine/all_are_same.hpp>

struct A { };
struct B : A { };
struct C : A { };
struct D : B { };
struct E : C { };

BOOST_AUTO_TEST_SUITE(all_are_same_tests)

template <typename T1, typename T2, typename T3, typename T4>
void test_all_are_same_1T(void)
{
	using eagine::all_are_same;

	BOOST_CHECK(all_are_same<T1>::value);
	BOOST_CHECK(all_are_same<T2>::value);
	BOOST_CHECK(all_are_same<T3>::value);
	BOOST_CHECK(all_are_same<T4>::value);

	BOOST_CHECK_EQUAL((
		all_are_same<T1, T3>::value),(
		std::is_same<T1, T3>::value
	));

	BOOST_CHECK_EQUAL((
		all_are_same<T4, T3, T2, T1>::value),(
		std::is_same<T2, T1>::value &&
		std::is_same<T1, T3>::value &&
		std::is_same<T3, T4>::value
	));

	BOOST_CHECK_EQUAL((
		all_are_same<T1, T2, T3, T4>::value),(
		std::is_same<T1, T2>::value &&
		std::is_same<T1, T3>::value &&
		std::is_same<T1, T4>::value
	));
}

template <typename T1, typename T2, typename T3, typename T4>
void test_all_are_same_1(void)
{
	test_all_are_same_1T<T1, T1, T1, T1>();
	test_all_are_same_1T<T2, T2, T2, T2>();
	test_all_are_same_1T<T3, T3, T3, T3>();
	test_all_are_same_1T<T4, T4, T4, T4>();

	test_all_are_same_1T<T1, T1, T2, T2>();
	test_all_are_same_1T<T3, T4, T4, T3>();

	test_all_are_same_1T<T1, T2, T3, T4>();
	test_all_are_same_1T<T4, T2, T1, T3>();
}

BOOST_AUTO_TEST_CASE(all_are_same_1)
{
	test_all_are_same_1<bool, float, double, unsigned>();
	test_all_are_same_1<char, short, int, long>();
	test_all_are_same_1<A, B, C, D>();
}

template <typename T1, typename T2, typename T3, typename T4>
void test_all_are_derived_from_1T(void)
{
	using eagine::all_are_derived_from;

	BOOST_CHECK(all_are_derived_from<T1>::value);
	BOOST_CHECK(all_are_derived_from<T2>::value);
	BOOST_CHECK(all_are_derived_from<T3>::value);
	BOOST_CHECK(all_are_derived_from<T4>::value);

	BOOST_CHECK_EQUAL((
		all_are_derived_from<T1, T3>::value),(
		std::is_base_of<T1, T3>::value
	));

	BOOST_CHECK_EQUAL((
		all_are_derived_from<T1, T2, T3, T4>::value),(
		std::is_base_of<T1, T2>::value &&
		std::is_base_of<T1, T3>::value &&
		std::is_base_of<T1, T4>::value
	));

	BOOST_CHECK_EQUAL((
		all_are_derived_from<T2, T1, T3, T4>::value),(
		std::is_base_of<T2, T1>::value &&
		std::is_base_of<T2, T3>::value &&
		std::is_base_of<T2, T4>::value
	));
}

template <typename T1, typename T2, typename T3, typename T4>
void test_all_are_derived_from_1(void)
{
	test_all_are_derived_from_1T<T1, T1, T1, T1>();
	test_all_are_derived_from_1T<T2, T2, T2, T2>();
	test_all_are_derived_from_1T<T3, T3, T3, T3>();
	test_all_are_derived_from_1T<T4, T4, T4, T4>();

	test_all_are_derived_from_1T<T1, T1, T2, T2>();
	test_all_are_derived_from_1T<T3, T4, T4, T3>();

	test_all_are_derived_from_1T<T1, T2, T3, T4>();
	test_all_are_derived_from_1T<T4, T2, T1, T3>();
}

BOOST_AUTO_TEST_CASE(all_are_derived_from_1)
{
	test_all_are_derived_from_1<char, short, int, long>();
	test_all_are_derived_from_1<A, B, C, D>();
	test_all_are_derived_from_1<B, C, D, E>();
}

template <typename T1, typename T2, typename T3, typename T4>
void test_all_are_convertible_to_1T(void)
{
	using eagine::all_are_convertible_to;

	BOOST_CHECK(all_are_convertible_to<T1>::value);
	BOOST_CHECK(all_are_convertible_to<T2>::value);
	BOOST_CHECK(all_are_convertible_to<T3>::value);
	BOOST_CHECK(all_are_convertible_to<T4>::value);

	BOOST_CHECK_EQUAL((
		all_are_convertible_to<T1, T3>::value),(
		std::is_convertible<T3, T1>::value
	));

	BOOST_CHECK_EQUAL((
		all_are_convertible_to<T1, T2, T3, T4>::value),(
		std::is_convertible<T2, T1>::value &&
		std::is_convertible<T3, T1>::value &&
		std::is_convertible<T4, T1>::value
	));

	BOOST_CHECK_EQUAL((
		all_are_convertible_to<T2, T1, T3, T4>::value),(
		std::is_convertible<T1, T2>::value &&
		std::is_convertible<T3, T2>::value &&
		std::is_convertible<T4, T2>::value
	));
}

template <typename T1, typename T2, typename T3, typename T4>
void test_all_are_convertible_to_1(void)
{
	test_all_are_convertible_to_1T<T1, T1, T1, T1>();
	test_all_are_convertible_to_1T<T2, T2, T2, T2>();
	test_all_are_convertible_to_1T<T3, T3, T3, T3>();
	test_all_are_convertible_to_1T<T4, T4, T4, T4>();

	test_all_are_convertible_to_1T<T1, T1, T2, T2>();
	test_all_are_convertible_to_1T<T3, T4, T4, T3>();

	test_all_are_convertible_to_1T<T1, T2, T3, T4>();
	test_all_are_convertible_to_1T<T4, T2, T1, T3>();
}

BOOST_AUTO_TEST_CASE(all_are_convertible_to_1)
{
	test_all_are_convertible_to_1<char, short, int, long>();
	test_all_are_convertible_to_1<bool, B, C, D>();
	test_all_are_convertible_to_1<A, B, C, long>();
	test_all_are_convertible_to_1<A, B, C, D>();
	test_all_are_convertible_to_1<B, C, D, E>();
}

BOOST_AUTO_TEST_SUITE_END()
