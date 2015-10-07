/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_object
#include <boost/test/unit_test.hpp>

#include "helper/mock_object.hpp"
#include "helper/object_c.hpp"

BOOST_AUTO_TEST_SUITE(object)

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

BOOST_AUTO_TEST_SUITE_END()
