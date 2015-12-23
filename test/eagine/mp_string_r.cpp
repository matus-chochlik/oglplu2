/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_mp_string_test
#include <boost/test/unit_test.hpp>

#include <eagine/mp_string.hpp>
#include <cstring>

BOOST_AUTO_TEST_SUITE(mp_string_test)

BOOST_AUTO_TEST_CASE(mp_string_empty)
{
	using namespace eagine;

	typedef mp_string<'\0'> s;
	BOOST_CHECK_EQUAL(std::strlen(s::value), 0);
	BOOST_CHECK(std::strcmp(s::value, "") == 0);
}

BOOST_AUTO_TEST_CASE(mp_string_chars)
{
	using namespace eagine;

	typedef mp_string<'m','p','_','s','t','r','i','n','g','\0'> s;
	BOOST_CHECK_EQUAL(std::strlen(s::value), std::strlen("mp_string"));
	BOOST_CHECK(std::strcmp(s::value, "mp_string") == 0);
}

struct mp_blah
{
	static constexpr const char mp_str[] = "blah";
};

BOOST_AUTO_TEST_CASE(mp_string_make)
{
	using namespace eagine;

	typedef mp_make_string<mp_blah> s;
	BOOST_CHECK_EQUAL(std::strlen(s::value), std::strlen("blah"));
	BOOST_CHECK(std::strcmp(s::value, "blah") == 0);
}

// TODO

BOOST_AUTO_TEST_SUITE_END()
