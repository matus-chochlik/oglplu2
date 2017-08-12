/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/bindump.hpp>
#define BOOST_TEST_MODULE EAGINE_bindump
#include "../unit_test_begin.inl"

#include <sstream>

BOOST_AUTO_TEST_SUITE(bindump_tests)

BOOST_AUTO_TEST_CASE(bindump_1)
{
	using namespace eagine;

	const char buf[] = "bindump test 1234567890";

	std::stringstream out;

	out << bindump(memory_block_of(buf));

	BOOST_CHECK(!out.str().empty());
}

BOOST_AUTO_TEST_SUITE_END()

#include "../unit_test_end.inl"
