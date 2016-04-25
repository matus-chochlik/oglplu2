/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_hexdump
#include <boost/test/unit_test.hpp>

#include <eagine/hexdump.hpp>
#include <sstream>

BOOST_AUTO_TEST_SUITE(hexdump_tests)

BOOST_AUTO_TEST_CASE(hexdump_1)
{
	using namespace eagine;

	const char buf[] = "hexdump test 1234567890";

	std::stringstream out;

	out << hexdump(memory_block_of(buf));

	BOOST_CHECK(!out.str().empty());
}

BOOST_AUTO_TEST_SUITE_END()
