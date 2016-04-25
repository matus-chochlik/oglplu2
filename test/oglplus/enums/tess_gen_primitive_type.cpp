//  File test/oglplus/enums/tess_gen_primitive_type.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_tess_gen_primitive_type

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_tess_gen_primitive_type_tests)

BOOST_AUTO_TEST_CASE(enum_tess_gen_primitive_type_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	tess_gen_primitive_type x;
	(void)x;

#ifdef GL_ISOLINES
	x = ev.isolines;
	BOOST_CHECK(x == ev.isolines);
# ifdef GL_QUADS
	BOOST_CHECK(x != ev.quads);
# endif
# ifdef GL_TRIANGLES
	BOOST_CHECK(x != ev.triangles);
# endif
#endif

#ifdef GL_QUADS
	x = ev.quads;
	BOOST_CHECK(x == ev.quads);
# ifdef GL_TRIANGLES
	BOOST_CHECK(x != ev.triangles);
# endif
#endif

#ifdef GL_TRIANGLES
	x = ev.triangles;
	BOOST_CHECK(x == ev.triangles);
#endif
}

BOOST_AUTO_TEST_CASE(enum_tess_gen_primitive_type_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	tess_gen_primitive_type x;
	(void)x;

#ifdef GL_ISOLINES
	x = ev.isolines;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ISOLINES"
	) == 0);
#endif

#ifdef GL_QUADS
	x = ev.quads;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"QUADS"
	) == 0);
#endif

#ifdef GL_TRIANGLES
	x = ev.triangles;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TRIANGLES"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_tess_gen_primitive_type_range)
{
	using namespace oglplus;
	auto count = enum_value_range<tess_gen_primitive_type>().size();

#ifdef GL_ISOLINES
{
	--count;
	auto r = enum_value_range<tess_gen_primitive_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		tess_gen_primitive_type(GL_ISOLINES)
	) != r.end());
}
#endif

#ifdef GL_QUADS
{
	--count;
	auto r = enum_value_range<tess_gen_primitive_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		tess_gen_primitive_type(GL_QUADS)
	) != r.end());
}
#endif

#ifdef GL_TRIANGLES
{
	--count;
	auto r = enum_value_range<tess_gen_primitive_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		tess_gen_primitive_type(GL_TRIANGLES)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_tess_gen_primitive_type_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	tess_gen_primitive_type x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_ISOLINES
	x = ev.isolines;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.isolines);
#endif

#ifdef GL_QUADS
	x = ev.quads;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.quads);
#endif

#ifdef GL_TRIANGLES
	x = ev.triangles;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.triangles);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
