/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_std_variant
#include <boost/test/unit_test.hpp>
#include "../random.hpp"

#include <eagine/std/variant.hpp>
#include <string>
#include <tuple>

BOOST_AUTO_TEST_SUITE(std_variant_tests)

static eagine::test_random_generator rg;

BOOST_AUTO_TEST_CASE(monostate_cmp)
{
	std::monostate ms1, ms2;

	BOOST_CHECK_EQUAL(ms1 != ms2, false);
	BOOST_CHECK_EQUAL(ms1 == ms2, true);
	BOOST_CHECK_EQUAL(ms1 <  ms2, false);
	BOOST_CHECK_EQUAL(ms1 <= ms2, true);
	BOOST_CHECK_EQUAL(ms1 >  ms2, false);
	BOOST_CHECK_EQUAL(ms1 >= ms2, true);
}

BOOST_AUTO_TEST_SUITE_END()
