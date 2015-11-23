/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_base_tribool
#include <boost/test/unit_test.hpp>

#include <eagine/tribool.hpp>

BOOST_AUTO_TEST_SUITE(base_tribool)

BOOST_AUTO_TEST_CASE(base_tribool_default_construction)
{
	eagine::tribool b;
	(void)b;
}

BOOST_AUTO_TEST_CASE(base_tribool_copy_construction)
{
	eagine::tribool b1;
	eagine::tribool b2(b1);
	(void)b2;
}

BOOST_AUTO_TEST_CASE(base_tribool_initialization)
{
	eagine::tribool t(true);
	eagine::tribool f(false);
	eagine::tribool i(eagine::indeterminate);

	(void)t;
	(void)f;
	(void)i;
}

BOOST_AUTO_TEST_CASE(base_tribool_ops)
{
	eagine::tribool a = true;
	eagine::tribool b = false;
	eagine::tribool c = eagine::indeterminate;

	BOOST_ASSERT(bool(a));
	BOOST_ASSERT(!!a);
	BOOST_ASSERT(!*a);
	BOOST_ASSERT(~a);
	BOOST_ASSERT(!!~a);
	BOOST_ASSERT(a == a);
	BOOST_ASSERT(true == a);
	BOOST_ASSERT(!bool(b));
	BOOST_ASSERT(!b);
	BOOST_ASSERT(!*b);
	BOOST_ASSERT(!bool(~b));
	BOOST_ASSERT(!~b);
	BOOST_ASSERT(b == b);
	BOOST_ASSERT(b == false);
	BOOST_ASSERT(false == b);
	BOOST_ASSERT(!(a == b));
	BOOST_ASSERT(!(b == a));
	BOOST_ASSERT(!bool(c));
	BOOST_ASSERT(!!c);
	BOOST_ASSERT(*c);
	BOOST_ASSERT(~c);
	BOOST_ASSERT(!~c);

	BOOST_ASSERT(a != false);
	BOOST_ASSERT(false != a);
	BOOST_ASSERT(b != true);
	BOOST_ASSERT(!(b != false));
	BOOST_ASSERT(!(a != a));
	BOOST_ASSERT(!(b != b));
	BOOST_ASSERT(a != b);
	BOOST_ASSERT(b != a);

	BOOST_ASSERT(!!(a == c));
	BOOST_ASSERT(!!(b == c));
	BOOST_ASSERT(!!(c == c));
	BOOST_ASSERT(!!(c == a));
	BOOST_ASSERT(!!(c == b));

	BOOST_ASSERT(~(a == c));
	BOOST_ASSERT(~(b == c));
	BOOST_ASSERT(~(c == c));
	BOOST_ASSERT(~(c == a));
	BOOST_ASSERT(~(c == b));

	BOOST_ASSERT(~(a != c));
	BOOST_ASSERT(~(b != c));
	BOOST_ASSERT(~(c != c));
	BOOST_ASSERT(~(c != a));
	BOOST_ASSERT(~(c != b));

	BOOST_ASSERT(a && a);
	BOOST_ASSERT(!(a && b));
	BOOST_ASSERT(!(b && a));
	BOOST_ASSERT(!(b && b));
	BOOST_ASSERT(*(a && c));
	BOOST_ASSERT(!(b && c));
	BOOST_ASSERT(*(c && c));
	BOOST_ASSERT(*(c && a));
	BOOST_ASSERT(!(c && b));

	BOOST_ASSERT(a || a);
	BOOST_ASSERT(a || b);
	BOOST_ASSERT(a || c);
	BOOST_ASSERT(b || a);
	BOOST_ASSERT(c || a);
	BOOST_ASSERT(!(b || b));
	BOOST_ASSERT(*(c || b));
	BOOST_ASSERT(*(b || c));
	BOOST_ASSERT(*(c || c));
}

BOOST_AUTO_TEST_SUITE_END()
