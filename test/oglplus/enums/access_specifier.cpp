//  File test/oglplus/enums/access_specifier.cpp
//
//  Automatically generated file, DO NOT modify manually.
//  Edit the enumeration source files in 'source/enums/oglplus'
//  or the 'source/enums/make_enum.py' script instead.
//
//  Copyright Matus Chochlik.
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt
//
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE OGLPLUS_access_specifier

#include <boost/test/unit_test.hpp>
#include "common.hpp"

BOOST_AUTO_TEST_SUITE(enum_access_specifier)

BOOST_AUTO_TEST_CASE(enum_access_specifier_values)
{
	using namespace oglplus;
	enum_values ev;
	access_specifier x;

#ifdef GL_READ_ONLY
	x = ev.read_only;
	BOOST_CHECK(x == ev.read_only);
# ifdef GL_READ_WRITE
	BOOST_CHECK(x != ev.read_write);
# endif
# ifdef GL_WRITE_ONLY
	BOOST_CHECK(x != ev.write_only);
# endif
#endif

#ifdef GL_READ_WRITE
	x = ev.read_write;
# ifdef GL_READ_ONLY
	BOOST_CHECK(x != ev.read_only);
# endif
	BOOST_CHECK(x == ev.read_write);
# ifdef GL_WRITE_ONLY
	BOOST_CHECK(x != ev.write_only);
# endif
#endif

#ifdef GL_WRITE_ONLY
	x = ev.write_only;
# ifdef GL_READ_ONLY
	BOOST_CHECK(x != ev.read_only);
# endif
# ifdef GL_READ_WRITE
	BOOST_CHECK(x != ev.read_write);
# endif
	BOOST_CHECK(x == ev.write_only);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
