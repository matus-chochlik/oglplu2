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
	BOOST_CHECK_EQUAL(e.native(), "");
}

BOOST_AUTO_TEST_CASE(filesystem_2)
{
	std::filesystem::path p("/usr/local/bin");
	BOOST_CHECK(!p.empty());
	std::string s = p;
	BOOST_CHECK_EQUAL(s, "/usr/local/bin");
	BOOST_CHECK_EQUAL(s, p.native());
}

BOOST_AUTO_TEST_CASE(filesystem_3)
{
	std::filesystem::path e;
	std::filesystem::path p("/usr/local/bin");
	std::filesystem::path q("/etc");
	BOOST_CHECK( e.empty());
	BOOST_CHECK(!p.empty());

	std::filesystem::path f = e.parent_path();
	std::filesystem::path r = p.parent_path();
	std::filesystem::path s = q.parent_path();

	BOOST_CHECK( f.empty());
	BOOST_CHECK(!r.empty());
	BOOST_CHECK(!s.empty());

	BOOST_CHECK_EQUAL(r.native(), "/usr/local");
	BOOST_CHECK_EQUAL(s.native(), "/");
}


BOOST_AUTO_TEST_SUITE_END()
