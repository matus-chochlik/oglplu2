/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/cstr_ref.hpp>
#define BOOST_TEST_MODULE EAGINE_cstr_ref
#include "../unit_test_begin.inl"

#include <cstring>
#include <string>
#include <array>

BOOST_AUTO_TEST_SUITE(cstr_ref_tests)

BOOST_AUTO_TEST_CASE(cstr_ref_default)
{
	using namespace eagine;

	cstr_ref s;
	BOOST_CHECK(s.empty());
	BOOST_CHECK_EQUAL(s.size(), 0);
	BOOST_CHECK(s.begin() == s.end());
	BOOST_ASSERT(s.c_str() != nullptr);
	BOOST_CHECK(s.c_str()[0] == '\0');

	eagine::cstring_span v = s;
	BOOST_CHECK_EQUAL(v.size(), 0);
	BOOST_CHECK(v.begin() == v.end());
}

BOOST_AUTO_TEST_CASE(cstr_ref_literal)
{
	using namespace eagine;

	const char l[] = "literal";

	cstr_ref s(l);
	BOOST_CHECK(!s.empty());
	BOOST_CHECK_EQUAL(s.size(), std::strlen(l));
	BOOST_CHECK(s.begin() != s.end());
	BOOST_CHECK(s.c_str() != nullptr);
	BOOST_ASSERT(std::strcmp(s.c_str(),  l) == 0);
	BOOST_CHECK(s.c_str()[s.size()] == '\0');

	eagine::cstring_span v = s;
	BOOST_CHECK_EQUAL(v.size(), std::strlen(l));
	BOOST_CHECK(v.begin() != v.end());
}

BOOST_AUTO_TEST_CASE(cstr_ref_c_string)
{
	using namespace eagine;

	const char* cs = "c-string";

	cstr_ref s(cs);
	BOOST_CHECK(!s.empty());
	BOOST_CHECK_EQUAL(s.size(), std::strlen(cs));
	BOOST_CHECK(s.begin() != s.end());
	BOOST_CHECK(s.c_str() != nullptr);
	BOOST_ASSERT(std::strcmp(s.c_str(),  cs) == 0);
	BOOST_CHECK(s.c_str()[s.size()] == '\0');

	eagine::cstring_span v = s;
	BOOST_CHECK_EQUAL(v.size(), std::strlen(cs));
	BOOST_CHECK(v.begin() != v.end());
}

BOOST_AUTO_TEST_CASE(cstr_ref_std_string)
{
	using namespace eagine;

	std::string ss = "std::string";

	cstr_ref s(ss);
	BOOST_CHECK(!s.empty());
	BOOST_CHECK_EQUAL(s.size(), ss.length());
	BOOST_CHECK(s.begin() != s.end());
	BOOST_CHECK(s.c_str() != nullptr);
	BOOST_ASSERT(std::strcmp(s.c_str(),  ss.c_str()) == 0);
	BOOST_CHECK(s.c_str()[s.size()] == '\0');

	eagine::cstring_span v = s;
	BOOST_CHECK_EQUAL(v.size(), ss.size());
	BOOST_CHECK(v.begin() != v.end());
}

BOOST_AUTO_TEST_CASE(cstr_ref_std_array)
{
	using namespace eagine;

	std::array<char, 11> sa = {{'s','t','d',':',':','a','r','r','a','y','\0'}};

	cstr_ref s(sa);
	BOOST_CHECK(!s.empty());
	BOOST_CHECK(s.size()+1 == sa.size());
	BOOST_CHECK_EQUAL(s.size(), std::strlen(sa.data()));
	BOOST_CHECK(s.begin() != s.end());
	BOOST_CHECK(s.c_str() != nullptr);
	BOOST_ASSERT(std::strcmp(s.c_str(),  sa.data()) == 0);
	BOOST_CHECK(s.c_str()[s.size()] == '\0');

	eagine::cstring_span v = s;
	BOOST_CHECK(v.size()+1 == sa.size());
	BOOST_CHECK(v.begin() != v.end());
}

// TODO

BOOST_AUTO_TEST_SUITE_END()

#include "../unit_test_end.inl"
