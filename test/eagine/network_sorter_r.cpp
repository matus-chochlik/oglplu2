/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_network_sorter
#include <boost/test/unit_test.hpp>

#include <eagine/network_sorter.hpp>
#include <cstdlib>
#include <algorithm>

BOOST_AUTO_TEST_SUITE(network_sorter_tests)

template <typename T, std::size_t N, typename Cmp>
void test_network_sorter_1_TNC(int n)
{
	using namespace eagine;

	for(int i=0; i<n; ++i)
	{
		std::array<T, N> a;
		for(T& e : a)
		{
			e = T(std::rand() % 1000000)/T(100);
		}

		network_sorter<T, N, Cmp> s{a};
		const std::array<T, N>& r = s();

		BOOST_CHECK(std::is_sorted(r.begin(), r.end(), Cmp()));
	}
}

template <typename T, std::size_t N>
void test_network_sorter_1_TN(int n)
{
	test_network_sorter_1_TNC<T, N, std::less<T>>(n);
	test_network_sorter_1_TNC<T, N, std::greater<T>>(n);
}

template <std::size_t N>
void test_network_sorter_1_N(int n)
{
	test_network_sorter_1_TN<int, N>(n);
	test_network_sorter_1_TN<float, N>(n);
	test_network_sorter_1_TN<double, N>(n);
	test_network_sorter_1_TN<unsigned, N>(n);
}

BOOST_AUTO_TEST_CASE(network_sorter_1_1)
{
	test_network_sorter_1_N<1>(1000);
	test_network_sorter_1_N<2>(1000);
	test_network_sorter_1_N<3>(1000);
	test_network_sorter_1_N<4>(1000);
	test_network_sorter_1_N<5>(1000);
	test_network_sorter_1_N<6>(1000);
	test_network_sorter_1_N<7>(900);
	test_network_sorter_1_N<8>(800);
	test_network_sorter_1_N<9>(700);
	// TODO
}

BOOST_AUTO_TEST_CASE(network_sorter_1_2)
{
	test_network_sorter_1_N<10>(700);
	test_network_sorter_1_N<11>(700);
	test_network_sorter_1_N<16>(600);
	test_network_sorter_1_N<32>(400);
	test_network_sorter_1_N<64>(200);
	// TODO
}

BOOST_AUTO_TEST_CASE(network_sorter_1_3)
{
	test_network_sorter_1_N<128>(100);
	test_network_sorter_1_N<256>(70);
	// TODO
}

BOOST_AUTO_TEST_SUITE_END()
