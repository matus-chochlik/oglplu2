/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_attrib_list
#include <boost/test/unit_test.hpp>

#include <eagine/attrib_list.hpp>

struct mock_attr_list_traits
{
	typedef int value_type;

	static constexpr
	int terminator(void)
	{
		return -1;
	}
};

template <std::size_t N>
using test_attrib_list = eagine::attribute_list<mock_attr_list_traits, N>;

using test_kv = eagine::attribute_list_key_value<mock_attr_list_traits>;

BOOST_AUTO_TEST_SUITE(attrib_list_tests)

BOOST_AUTO_TEST_CASE(attrib_list_1)
{
	using namespace eagine;

	test_attrib_list<0> l0;
	BOOST_CHECK_EQUAL(l0.size(), 1);

	test_attrib_list<2> l2 = l0.append(test_kv(0,1));
	BOOST_CHECK_EQUAL(l2.size(), 3);
	BOOST_CHECK_EQUAL(l2.data()[0], 0);
	BOOST_CHECK_EQUAL(l2.data()[1], 1);
	BOOST_CHECK_EQUAL(l2.data()[2],-1);

	test_attrib_list<4> l4 = l2.append(test_kv(2,3));
	BOOST_CHECK_EQUAL(l4.size(), 5);
	BOOST_CHECK_EQUAL(l4.data()[0], 0);
	BOOST_CHECK_EQUAL(l4.data()[1], 1);
	BOOST_CHECK_EQUAL(l4.data()[2], 2);
	BOOST_CHECK_EQUAL(l4.data()[3], 3);
	BOOST_CHECK_EQUAL(l4.data()[4],-1);

	test_attrib_list<6> l6 = l4.append(test_kv(4,5));
	BOOST_CHECK_EQUAL(l6.size(), 7);
	BOOST_CHECK_EQUAL(l6.data()[0], 0);
	BOOST_CHECK_EQUAL(l6.data()[1], 1);
	BOOST_CHECK_EQUAL(l6.data()[2], 2);
	BOOST_CHECK_EQUAL(l6.data()[3], 3);
	BOOST_CHECK_EQUAL(l6.data()[4], 4);
	BOOST_CHECK_EQUAL(l6.data()[5], 5);
	BOOST_CHECK_EQUAL(l6.data()[6],-1);

	test_attrib_list<8> l8 = l6.append(test_kv(6,7));
	BOOST_CHECK_EQUAL(l8.size(), 9);
	BOOST_CHECK_EQUAL(l8.data()[0], 0);
	BOOST_CHECK_EQUAL(l8.data()[1], 1);
	BOOST_CHECK_EQUAL(l8.data()[2], 2);
	BOOST_CHECK_EQUAL(l8.data()[3], 3);
	BOOST_CHECK_EQUAL(l8.data()[4], 4);
	BOOST_CHECK_EQUAL(l8.data()[5], 5);
	BOOST_CHECK_EQUAL(l8.data()[6], 6);
	BOOST_CHECK_EQUAL(l8.data()[7], 7);
	BOOST_CHECK_EQUAL(l8.data()[8],-1);
}

BOOST_AUTO_TEST_SUITE_END()
