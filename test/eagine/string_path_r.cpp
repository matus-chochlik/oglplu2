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
	}

}

BOOST_AUTO_TEST_SUITE_END()
