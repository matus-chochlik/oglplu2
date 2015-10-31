/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_type_to_value
#include <boost/test/unit_test.hpp>

#include <eagine/type_to_value.hpp>
#include <type_traits>

BOOST_AUTO_TEST_SUITE(type_to_value)

struct test_sizeof_getter
{
	template <typename T>
	std::size_t
	operator()(eagine::identity<T>) const
	{
		return sizeof(T);
	}
};

struct test_zero_getter
{
	template <typename T>
	std::size_t
	operator()(eagine::identity<T>) const
	{
		return 0;
	}
};


BOOST_AUTO_TEST_CASE(type_to_value_1)
{
	using namespace eagine;

	type_to_value<std::size_t, char, short, int, long> ttv1(
		sizeof(char),
		sizeof(short),
		sizeof(int),
		sizeof(long)
	);

	BOOST_CHECK(ttv1.size() == 4);
	
	BOOST_CHECK(ttv1.ref<char>() == ttv1.ref(0));
	BOOST_CHECK(ttv1.ref<short>() == ttv1.ref(1));
	BOOST_CHECK(ttv1.ref<int>() == ttv1.ref(2));
	BOOST_CHECK(ttv1.ref<long>() == ttv1.ref(3));

	type_to_value<std::size_t, char, short, int, long> ttv2((
		test_sizeof_getter()
	));

	BOOST_CHECK(ttv1 == ttv2);
	BOOST_CHECK(!(ttv1 != ttv2));

	for(std::size_t s : ttv2)
	{
		BOOST_CHECK(s > 0);
	}

	type_to_value<std::size_t, char, short, int, long> ttv3((
		test_zero_getter()
	));

	BOOST_CHECK(ttv1 != ttv3);
	BOOST_CHECK(!(ttv1 == ttv3));

	for(std::size_t s : ttv3)
	{
		BOOST_CHECK(s == 0);
	}
}


BOOST_AUTO_TEST_SUITE_END()
