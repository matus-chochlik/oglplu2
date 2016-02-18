/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_key_val_list
#include <boost/test/unit_test.hpp>

#include <eagine/key_val_list.hpp>

struct mock_kv_list_traits
{
	typedef char key_type;
	typedef int conv_type;
	typedef int value_type;

	static constexpr
	int terminator(void)
	{
		return -1;
	}
};

template <std::size_t N>
using test_key_val_list = eagine::key_value_list<mock_kv_list_traits, N>;

using test_kv = eagine::key_value_list_element<mock_kv_list_traits>;

BOOST_AUTO_TEST_SUITE(key_val_list_tests)

BOOST_AUTO_TEST_CASE(key_val_list_1)
{
	using namespace eagine;

	test_key_val_list<0> l0;
	BOOST_CHECK_EQUAL(l0.size(), 1);

	test_key_val_list<2> l2 = l0.append(test_kv('0',1));
	BOOST_CHECK_EQUAL(l2.size(), 3);
	BOOST_CHECK_EQUAL(l2.data()[0], 0+'0');
	BOOST_CHECK_EQUAL(l2.data()[1], 1);
	BOOST_CHECK_EQUAL(l2.data()[2],-1);

	test_key_val_list<4> l4 = l2.append(test_kv('2',3));
	BOOST_CHECK_EQUAL(l4.size(), 5);
	BOOST_CHECK_EQUAL(l4.data()[0], 0+'0');
	BOOST_CHECK_EQUAL(l4.data()[1], 1);
	BOOST_CHECK_EQUAL(l4.data()[2], 2+'0');
	BOOST_CHECK_EQUAL(l4.data()[3], 3);
	BOOST_CHECK_EQUAL(l4.data()[4],-1);

	test_key_val_list<6> l6 = l4.append(test_kv('4',5));
	BOOST_CHECK_EQUAL(l6.size(), 7);
	BOOST_CHECK_EQUAL(l6.data()[0], 0+'0');
	BOOST_CHECK_EQUAL(l6.data()[1], 1);
	BOOST_CHECK_EQUAL(l6.data()[2], 2+'0');
	BOOST_CHECK_EQUAL(l6.data()[3], 3);
	BOOST_CHECK_EQUAL(l6.data()[4], 4+'0');
	BOOST_CHECK_EQUAL(l6.data()[5], 5);
	BOOST_CHECK_EQUAL(l6.data()[6],-1);

	test_key_val_list<8> l8 = l6.append(test_kv('6',7));
	BOOST_CHECK_EQUAL(l8.size(), 9);
	BOOST_CHECK_EQUAL(l8.data()[0], 0+'0');
	BOOST_CHECK_EQUAL(l8.data()[1], 1);
	BOOST_CHECK_EQUAL(l8.data()[2], 2+'0');
	BOOST_CHECK_EQUAL(l8.data()[3], 3);
	BOOST_CHECK_EQUAL(l8.data()[4], 4+'0');
	BOOST_CHECK_EQUAL(l8.data()[5], 5);
	BOOST_CHECK_EQUAL(l8.data()[6], 6+'0');
	BOOST_CHECK_EQUAL(l8.data()[7], 7);
	BOOST_CHECK_EQUAL(l8.data()[8],-1);
}

BOOST_AUTO_TEST_CASE(key_val_list_2)
{
	using namespace eagine;

	test_key_val_list<0> l0;
	typedef test_kv kv;

	test_key_val_list<2> l2 = l0+kv('A',1);
	BOOST_CHECK_EQUAL(l2.size(), 3);
	BOOST_CHECK_EQUAL(l2.data()[0], 'A');
	BOOST_CHECK_EQUAL(l2.data()[1], 1);
	BOOST_CHECK_EQUAL(l2.data()[2],-1);

	test_key_val_list<4> l4 = l0+kv('A',1)+kv('B',3);
	BOOST_CHECK_EQUAL(l4.size(), 5);
	BOOST_CHECK_EQUAL(l4.data()[0], 'A');
	BOOST_CHECK_EQUAL(l4.data()[1], 1);
	BOOST_CHECK_EQUAL(l4.data()[2], 'B');
	BOOST_CHECK_EQUAL(l4.data()[3], 3);
	BOOST_CHECK_EQUAL(l4.data()[4],-1);

	test_key_val_list<6> l6 = l0+kv('A',1)+kv('B',3)+kv('C',5);
	BOOST_CHECK_EQUAL(l6.size(), 7);
	BOOST_CHECK_EQUAL(l6.data()[0], 'A');
	BOOST_CHECK_EQUAL(l6.data()[1], 1);
	BOOST_CHECK_EQUAL(l6.data()[2], 'B');
	BOOST_CHECK_EQUAL(l6.data()[3], 3);
	BOOST_CHECK_EQUAL(l6.data()[4], 'C');
	BOOST_CHECK_EQUAL(l6.data()[5], 5);
	BOOST_CHECK_EQUAL(l6.data()[6],-1);

	test_key_val_list<8> l8 = l0+kv('A',1)+kv('B',3)+kv('C',5)+kv('D',7);
	BOOST_CHECK_EQUAL(l8.size(), 9);
	BOOST_CHECK_EQUAL(l8.data()[0], 'A');
	BOOST_CHECK_EQUAL(l8.data()[1], 1);
	BOOST_CHECK_EQUAL(l8.data()[2], 'B');
	BOOST_CHECK_EQUAL(l8.data()[3], 3);
	BOOST_CHECK_EQUAL(l8.data()[4], 'C');
	BOOST_CHECK_EQUAL(l8.data()[5], 5);
	BOOST_CHECK_EQUAL(l8.data()[6], 'D');
	BOOST_CHECK_EQUAL(l8.data()[7], 7);
	BOOST_CHECK_EQUAL(l8.data()[8],-1);
}

BOOST_AUTO_TEST_CASE(key_val_list_3)
{
	using namespace eagine;

	typedef test_kv kv;

	test_key_val_list<2> l2 = kv('0',1);
	BOOST_CHECK_EQUAL(l2.size(), 3);
	BOOST_CHECK_EQUAL(l2.data()[0], 0+'0');
	BOOST_CHECK_EQUAL(l2.data()[1], 1);
	BOOST_CHECK_EQUAL(l2.data()[2],-1);

	test_key_val_list<4> l4 = kv('0',1)+kv('2',3);
	BOOST_CHECK_EQUAL(l4.size(), 5);
	BOOST_CHECK_EQUAL(l4.data()[0], 0+'0');
	BOOST_CHECK_EQUAL(l4.data()[1], 1);
	BOOST_CHECK_EQUAL(l4.data()[2], 2+'0');
	BOOST_CHECK_EQUAL(l4.data()[3], 3);
	BOOST_CHECK_EQUAL(l4.data()[4],-1);

	test_key_val_list<6> l6 = kv('0',1)+kv('2',3)+kv('4',5);
	BOOST_CHECK_EQUAL(l6.size(), 7);
	BOOST_CHECK_EQUAL(l6.data()[0], 0+'0');
	BOOST_CHECK_EQUAL(l6.data()[1], 1);
	BOOST_CHECK_EQUAL(l6.data()[2], 2+'0');
	BOOST_CHECK_EQUAL(l6.data()[3], 3);
	BOOST_CHECK_EQUAL(l6.data()[4], 4+'0');
	BOOST_CHECK_EQUAL(l6.data()[5], 5);
	BOOST_CHECK_EQUAL(l6.data()[6],-1);

	test_key_val_list<8> l8 = kv('0',1)+kv('2',3)+kv('4',5)+kv('6',7);
	BOOST_CHECK_EQUAL(l8.size(), 9);
	BOOST_CHECK_EQUAL(l8.data()[0], 0+'0');
	BOOST_CHECK_EQUAL(l8.data()[1], 1);
	BOOST_CHECK_EQUAL(l8.data()[2], 2+'0');
	BOOST_CHECK_EQUAL(l8.data()[3], 3);
	BOOST_CHECK_EQUAL(l8.data()[4], 4+'0');
	BOOST_CHECK_EQUAL(l8.data()[5], 5);
	BOOST_CHECK_EQUAL(l8.data()[6], 6+'0');
	BOOST_CHECK_EQUAL(l8.data()[7], 7);
	BOOST_CHECK_EQUAL(l8.data()[8],-1);
}

BOOST_AUTO_TEST_SUITE_END()
