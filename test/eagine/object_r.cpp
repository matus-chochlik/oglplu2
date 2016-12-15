/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_object
#include <boost/test/unit_test.hpp>
#include "../random.hpp"

#include "helper/mock_object.hpp"
#include "helper/object_c.hpp"

BOOST_AUTO_TEST_SUITE(object_tests)

static eagine::test_random_generator rg;

BOOST_AUTO_TEST_CASE(object_name)
{
	using namespace eagine;
	eagine_object_name_test<mock_object_name>();
}

BOOST_AUTO_TEST_CASE(object_1)
{
	using namespace eagine;
	eagine_object_test<mock_object>();
}

BOOST_AUTO_TEST_CASE(object_any)
{
	using namespace eagine;

	unsigned n = rg.get_uint(1, 10000);

	mock_object_name mon1(n);
	any_object_name<unsigned, unsigned, ~unsigned(0), 0> aon(mon1);
	mock_object_name mon2(aon);

	BOOST_CHECK_EQUAL(get_raw_name(mon2), n);
}

BOOST_AUTO_TEST_SUITE_END()
