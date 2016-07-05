/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_fixed_size_str
#include <boost/test/unit_test.hpp>

#include <eagine/fixed_size_str.hpp>

BOOST_AUTO_TEST_SUITE(fixed_size_string_tests)

BOOST_AUTO_TEST_CASE(fixed_size_string_default)
{
	using namespace eagine;

	fixed_size_string<1> s;
	BOOST_CHECK(s.empty());
	BOOST_CHECK_EQUAL(s.size(), 0);
	BOOST_CHECK(s.begin() == s.end());
	BOOST_ASSERT(s.c_str() != nullptr);
	BOOST_CHECK(s.c_str()[0] == '\0');

	eagine::cstring_span v = s;
	BOOST_CHECK_EQUAL(v.size(), 0);
	BOOST_CHECK(v.begin() == v.end());
}

BOOST_AUTO_TEST_CASE(fixed_size_string_chars)
{
	using namespace eagine;

	fixed_size_string<4> s('a','b','c','\0');
	BOOST_CHECK(!s.empty());
	BOOST_CHECK_EQUAL(s.size(), 3);
	BOOST_CHECK(s.begin() != s.end());
	BOOST_CHECK(s.c_str() != nullptr);
	BOOST_ASSERT(std::strcmp(s.c_str(), "abc") == 0);
	BOOST_CHECK(s.c_str()[s.size()] == '\0');

	eagine::cstring_span v = s;
	BOOST_CHECK_EQUAL(v.size(), std::strlen("abc"));
	BOOST_CHECK(v.begin() != v.end());
}

BOOST_AUTO_TEST_CASE(fixed_size_string_literal)
{
	using namespace eagine;

	const char l[] = "literal";

	auto s = make_fixed_size_string(l);
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

BOOST_AUTO_TEST_CASE(fixed_size_string_concat)
{
	using namespace eagine;

	const char one[] = "one";
	const char two[] = "two";
	const char three[] = "three";
	const char four[] = "four";

	auto s =make_fixed_size_string(one)+
		make_fixed_size_string(two)+
		make_fixed_size_string(three)+
		make_fixed_size_string(four);

	BOOST_CHECK(!s.empty());
	BOOST_ASSERT(std::strcmp(s.c_str(), "onetwothreefour") == 0);
	BOOST_CHECK(s.c_str()[s.size()] == '\0');

	eagine::cstring_span v = s;
	BOOST_CHECK_EQUAL(v.size(), std::strlen("onetwothreefour"));
	BOOST_CHECK(v.begin() != v.end());
}

BOOST_AUTO_TEST_CASE(fixed_size_string_int)
{
	using namespace eagine;

	BOOST_CHECK(std::strcmp(
		to_fixed_size_string(int_constant<0>()).c_str(),
		"0"
	) == 0);

	BOOST_CHECK(std::strcmp(
		to_fixed_size_string(int_constant<1>()).c_str(),
		"1"
	) == 0);

	BOOST_CHECK(std::strcmp(
		to_fixed_size_string(int_constant<-1>()).c_str(),
		"-1"
	) == 0);

	BOOST_CHECK(std::strcmp(
		to_fixed_size_string(int_constant<9>()).c_str(),
		"9"
	) == 0);

	BOOST_CHECK(std::strcmp(
		to_fixed_size_string(int_constant<-9>()).c_str(),
		"-9"
	) == 0);

	BOOST_CHECK(std::strcmp(
		to_fixed_size_string(int_constant<10>()).c_str(),
		"10"
	) == 0);

	BOOST_CHECK(std::strcmp(
		to_fixed_size_string(int_constant<-10>()).c_str(),
		"-10"
	) == 0);

	BOOST_CHECK(std::strcmp(
		to_fixed_size_string(int_constant<1234567890>()).c_str(),
		"1234567890"
	) == 0);

	BOOST_CHECK(std::strcmp(
		to_fixed_size_string(int_constant<-1234567890>()).c_str(),
		"-1234567890"
	) == 0);

}

// TODO

BOOST_AUTO_TEST_SUITE_END()
