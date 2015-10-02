/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_scope_exit
#include <boost/test/unit_test.hpp>

#include <eagine/scope_exit.hpp>
#include <type_traits>
#include <exception>

BOOST_AUTO_TEST_SUITE(scope_exit)

BOOST_AUTO_TEST_CASE(scope_exit_f)
{
	using namespace eagine;
	
	int i = 10, passed = 0;
	auto inc_i = [&i](void) { ++i; };

	{
		BOOST_CHECK_EQUAL(i, 10);
		on_scope_exit<std::false_type> se(inc_i);
		BOOST_CHECK_EQUAL(i, 10);
		++passed;
	}
	BOOST_CHECK_EQUAL(i, 11);
	try
	{
		BOOST_CHECK_EQUAL(i, 11);
		on_scope_exit<std::false_type> se(inc_i);
		BOOST_CHECK_EQUAL(i, 11);
		++passed;

		throw std::exception();
	}
	catch(std::exception&)
	{
		BOOST_CHECK_EQUAL(i, 11);
		++passed;
	}
	BOOST_CHECK_EQUAL(passed,3);
}

BOOST_AUTO_TEST_CASE(scope_exit_t)
{
	using namespace eagine;
	
	int i = 11, passed = 0;
	auto inc_i = [&i](void) { ++i; };

	{
		BOOST_CHECK_EQUAL(i, 11);
		on_scope_exit<std::true_type> se(inc_i);
		BOOST_CHECK_EQUAL(i, 11);
		++passed;
	}
	BOOST_CHECK_EQUAL(i, 11);
	try
	{
		BOOST_CHECK_EQUAL(i, 11);
		on_scope_exit<std::true_type> se(inc_i);
		BOOST_CHECK_EQUAL(i, 11);
		++passed;

		throw std::exception();
	}
	catch(std::exception&)
	{
		BOOST_CHECK_EQUAL(i, 12);
		++passed;
	}

	BOOST_CHECK_EQUAL(passed,3);
}

BOOST_AUTO_TEST_CASE(scope_exit_n)
{
	using namespace eagine;
	
	int i = 41, passed = 0;
	auto inc_i = [&i](void) { ++i; };

	{
		BOOST_CHECK_EQUAL(i, 41);
		on_scope_exit<nothing_t> se(inc_i);
		BOOST_CHECK_EQUAL(i, 41);
		++passed;
	}
	BOOST_CHECK_EQUAL(i, 42);
	try
	{
		BOOST_CHECK_EQUAL(i, 42);
		on_scope_exit<nothing_t> se(inc_i);
		BOOST_CHECK_EQUAL(i, 42);
		++passed;

		throw std::exception();
	}
	catch(std::exception&)
	{
		BOOST_CHECK_EQUAL(i, 43);
		++passed;
	}

	BOOST_CHECK_EQUAL(passed,3);
}

BOOST_AUTO_TEST_SUITE_END()
