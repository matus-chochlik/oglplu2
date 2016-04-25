/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_random_bytes
#include <boost/test/unit_test.hpp>

#include <eagine/random_bytes.hpp>
#include <climits>
#include <vector>

BOOST_AUTO_TEST_SUITE(random_bytes_tests)

BOOST_AUTO_TEST_CASE(random_bytes_1)
{
	using namespace eagine;

	const std::size_t n = 1024*1024*16;
	const std::size_t s = 1 << CHAR_BIT;
	const std::size_t m = n / s;

	std::vector<unsigned char> bytes(n);
	std::vector<std::size_t> counts(s, 0);


	fill_with_random_bytes(bytes);

	for(auto b : bytes)
	{
		++counts[b];
	}

	for(auto c : counts)
	{
		double x = (int(c)-int(m))/double(m);
		BOOST_CHECK_SMALL(x, 0.05);
	}
}

// TODO

BOOST_AUTO_TEST_SUITE_END()
