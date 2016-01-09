//  File test/oglplus/enums/access_specifier.cpp
//
//  Automatically generated file, DO NOT modify manually.
//  Edit the enumeration source files in 'source/enums/oglplus'
//  or the 'source/enums/make_enum.py' script instead.
//
//  Copyright Matus Chochlik.
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//   http://www.boost.org/LICENSE_1_0.txt
//
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE OGLPLUS_access_specifier

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_access_specifier_tests)

BOOST_AUTO_TEST_CASE(enum_access_specifier_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	access_specifier x;
	(void)x;

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
	BOOST_CHECK(x == ev.read_write);
# ifdef GL_WRITE_ONLY
	BOOST_CHECK(x != ev.write_only);
# endif
#endif

#ifdef GL_WRITE_ONLY
	x = ev.write_only;
	BOOST_CHECK(x == ev.write_only);
#endif
}

BOOST_AUTO_TEST_CASE(enum_access_specifier_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	access_specifier x;
	(void)x;

#ifdef GL_READ_ONLY
	x = ev.read_only;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"READ_ONLY"
	) == 0);
#endif

#ifdef GL_READ_WRITE
	x = ev.read_write;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"READ_WRITE"
	) == 0);
#endif

#ifdef GL_WRITE_ONLY
	x = ev.write_only;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"WRITE_ONLY"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_access_specifier_range)
{
	using namespace oglplus;
	auto count = enum_value_range<access_specifier>().size();

#ifdef GL_READ_ONLY
{
	--count;
	auto r = enum_value_range<access_specifier>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		access_specifier(GL_READ_ONLY)
	) != r.end());
}
#endif

#ifdef GL_READ_WRITE
{
	--count;
	auto r = enum_value_range<access_specifier>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		access_specifier(GL_READ_WRITE)
	) != r.end());
}
#endif

#ifdef GL_WRITE_ONLY
{
	--count;
	auto r = enum_value_range<access_specifier>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		access_specifier(GL_WRITE_ONLY)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_access_specifier_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	access_specifier x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_READ_ONLY
	x = ev.read_only;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.read_only);
#endif

#ifdef GL_READ_WRITE
	x = ev.read_write;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.read_write);
#endif

#ifdef GL_WRITE_ONLY
	x = ev.write_only;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.write_only);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
