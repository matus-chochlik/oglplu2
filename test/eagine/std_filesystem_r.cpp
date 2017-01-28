/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_std_filesystem
#include <boost/test/unit_test.hpp>

#include <eagine/std/filesystem.hpp>

BOOST_AUTO_TEST_SUITE(std_filesystem_tests)

BOOST_AUTO_TEST_CASE(filesystem_1)
{
	std::filesystem::path e;
	BOOST_CHECK(e.empty());
}

BOOST_AUTO_TEST_CASE(filesystem_2)
{
	std::filesystem::path e("/usr/local/bin");
	BOOST_CHECK(!e.empty());
}

BOOST_AUTO_TEST_SUITE_END()
