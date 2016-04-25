/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_identity
#include <boost/test/unit_test.hpp>

#include <eagine/identity.hpp>
#include <cstdlib>

BOOST_AUTO_TEST_SUITE(identity_tests)

BOOST_AUTO_TEST_CASE(identity_1)
{
	using namespace eagine;

	for(int k=0; k<1000; ++k)
	{
		identity<int> i;
		int r = std::rand();

		BOOST_CHECK_EQUAL(i(r), r);
	}
}

BOOST_AUTO_TEST_SUITE_END()
