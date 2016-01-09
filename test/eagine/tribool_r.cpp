/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_tribool
#include <boost/test/unit_test.hpp>

#include <eagine/tribool.hpp>

BOOST_AUTO_TEST_SUITE(tribool_tests)

BOOST_AUTO_TEST_CASE(tribool_default_construction)
{
	eagine::tribool b;
	(void)b;
}

BOOST_AUTO_TEST_CASE(tribool_copy_construction)
{
	eagine::tribool b1;
	eagine::tribool b2(b1);
	(void)b2;
}

BOOST_AUTO_TEST_CASE(tribool_initialization)
{
	eagine::tribool t(true);
	eagine::tribool f(false);
	eagine::tribool i(eagine::indeterminate);

	(void)t;
	(void)f;
	(void)i;
}

BOOST_AUTO_TEST_CASE(tribool_ops)
{
	eagine::tribool a = true;
	eagine::tribool b = false;
	eagine::tribool c = eagine::indeterminate;

	BOOST_CHECK(bool(a));
	BOOST_CHECK(!!a);
	BOOST_CHECK(!*a);
	BOOST_CHECK(~a);
	BOOST_CHECK(!!~a);
	BOOST_CHECK(a == a);
	BOOST_CHECK(true == a);
	BOOST_CHECK(!bool(b));
	BOOST_CHECK(!b);
	BOOST_CHECK(!*b);
	BOOST_CHECK(!bool(~b));
	BOOST_CHECK(!~b);
	BOOST_CHECK(b == b);
	BOOST_CHECK(b == false);
	BOOST_CHECK(false == b);
	BOOST_CHECK(!(a == b));
	BOOST_CHECK(!(b == a));
	BOOST_CHECK(!bool(c));
	BOOST_CHECK(!!c);
	BOOST_CHECK(*c);
	BOOST_CHECK(bool(~c));
	BOOST_CHECK(!~c);

	BOOST_CHECK(a != false);
	BOOST_CHECK(false != a);
	BOOST_CHECK(b != true);
	BOOST_CHECK(!(b != false));
	BOOST_CHECK(!(a != a));
	BOOST_CHECK(!(b != b));
	BOOST_CHECK(a != b);
	BOOST_CHECK(b != a);

	BOOST_CHECK(!!(a == c));
	BOOST_CHECK(!!(b == c));
	BOOST_CHECK(!!(c == c));
	BOOST_CHECK(!!(c == a));
	BOOST_CHECK(!!(c == b));

	BOOST_CHECK(bool(~(a == c)));
	BOOST_CHECK(bool(~(b == c)));
	BOOST_CHECK(bool(~(c == c)));
	BOOST_CHECK(bool(~(c == a)));
	BOOST_CHECK(bool(~(c == b)));

	BOOST_CHECK(bool(~(a != c)));
	BOOST_CHECK(bool(~(b != c)));
	BOOST_CHECK(bool(~(c != c)));
	BOOST_CHECK(bool(~(c != a)));
	BOOST_CHECK(bool(~(c != b)));

	BOOST_CHECK(a && a);
	BOOST_CHECK(!(a && b));
	BOOST_CHECK(!(b && a));
	BOOST_CHECK(!(b && b));
	BOOST_CHECK(*(a && c));
	BOOST_CHECK(!(b && c));
	BOOST_CHECK(*(c && c));
	BOOST_CHECK(*(c && a));
	BOOST_CHECK(!(c && b));

	BOOST_CHECK(a || a);
	BOOST_CHECK(a || b);
	BOOST_CHECK(a || c);
	BOOST_CHECK(b || a);
	BOOST_CHECK(c || a);
	BOOST_CHECK(!(b || b));
	BOOST_CHECK(*(c || b));
	BOOST_CHECK(*(b || c));
	BOOST_CHECK(*(c || c));
}

BOOST_AUTO_TEST_SUITE_END()
