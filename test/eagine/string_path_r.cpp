/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_string_path
#include <boost/test/unit_test.hpp>

#include <eagine/string_path.hpp>
#include <eagine/hexdump.hpp>
#include <stack>
#include <string>

BOOST_AUTO_TEST_SUITE(string_path_tests)

BOOST_AUTO_TEST_CASE(string_path_1)
{
	using namespace eagine;

	basic_string_path bsp;

	for(int i=0; i<100; ++i)
	{
		std::size_t s = 0;

		for(int j=0, k=10+std::rand()%100; j<k; ++j)
		{
			std::string n(
				std::string::size_type(std::rand()%8196),
				char('A'+std::rand()%('Z'-'A'))
			);
			bsp.push_back(as_span(n));
			++s;

			BOOST_CHECK_EQUAL(bsp.size(), s);
			BOOST_CHECK(bsp.back() == as_span(n));

			if((std::rand()%10 == 0) && !bsp.empty())
			{
				bsp.pop_back();
				--s;
			}
			BOOST_CHECK_EQUAL(bsp.size(), s);
		}

		bsp = bsp+bsp;

		BOOST_CHECK_EQUAL(bsp.size(), 2*s);

		while(!bsp.empty()) bsp.pop_back();

		BOOST_CHECK_EQUAL(bsp.size(), 0);
	}
}

BOOST_AUTO_TEST_CASE(string_path_2)
{
	using namespace eagine;

	for(int i=0; i<200; ++i)
	{
		basic_string_path bsp;

		for(int j=0, k=std::rand()%30; j<k; ++j)
		{
			std::string::size_type n(std::rand()%512);
			char c('A'+std::rand()%('Z'-'A'));
			std::string s(n, c);
			bsp.push_back(as_span(s));

			BOOST_CHECK(bsp.back() == as_span(s));
			BOOST_CHECK(!bsp.empty());
		}

		std::stack<std::string> stk;
		bsp.for_each([&stk](basic_string_path::value_type s)
		{
			stk.push(std::string(s.begin(), s.end()));
			BOOST_CHECK(s == as_span(stk.top()));
		});

		BOOST_CHECK_EQUAL(bsp.size(), stk.size());

		bsp.rev_for_each([&stk](basic_string_path::value_type s)
		{
			BOOST_ASSERT(!stk.empty());
			BOOST_CHECK(s == as_span(stk.top()));
			stk.pop();
		});

		BOOST_CHECK(stk.empty());
	}
}

BOOST_AUTO_TEST_CASE(string_path_3)
{
	using namespace eagine;

	for(int i=0; i<200; ++i)
	{
		basic_string_path bsp;

		for(int j=0, k=std::rand()%30; j<k; ++j)
		{
			std::string::size_type n(std::rand()%512);
			char c('A'+std::rand()%('Z'-'A'));
			std::string s(n, c);
			bsp.push_back(as_span(s));

			BOOST_CHECK(bsp.back() == as_span(s));
			BOOST_CHECK(!bsp.empty());
		}

		std::stack<std::string> stk;
		for(auto p = bsp.begin(); p!=bsp.end(); ++p)
		{
			stk.push(std::string((*p).begin(), p->end()));
			BOOST_CHECK(*p == as_span(stk.top()));
		}

		BOOST_CHECK_EQUAL(bsp.size(), stk.size());

		for(auto p = bsp.rbegin(); p!=bsp.rend(); ++p)
		{
			BOOST_ASSERT(!stk.empty());
			BOOST_CHECK(*p == as_span(stk.top()));
			stk.pop();
		}
		BOOST_CHECK(stk.empty());
	}
}

BOOST_AUTO_TEST_SUITE_END()
