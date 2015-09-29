//  File test/oglplus/enums/string_query.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_string_query

#include <boost/test/unit_test.hpp>
#include "common.hpp"

BOOST_AUTO_TEST_SUITE(enum_string_query)

BOOST_AUTO_TEST_CASE(enum_string_query_values)
{
	using namespace oglplus;
	enum_values ev;
	string_query x;

#ifdef GL_RENDERER
	x = ev.renderer;
	BOOST_CHECK(x == ev.renderer);
# ifdef GL_SHADING_LANGUAGE_VERSION
	BOOST_CHECK(x != ev.shading_language_version);
# endif
# ifdef GL_VENDOR
	BOOST_CHECK(x != ev.vendor);
# endif
# ifdef GL_VERSION
	BOOST_CHECK(x != ev.version);
# endif
#endif

#ifdef GL_SHADING_LANGUAGE_VERSION
	x = ev.shading_language_version;
# ifdef GL_RENDERER
	BOOST_CHECK(x != ev.renderer);
# endif
	BOOST_CHECK(x == ev.shading_language_version);
# ifdef GL_VENDOR
	BOOST_CHECK(x != ev.vendor);
# endif
# ifdef GL_VERSION
	BOOST_CHECK(x != ev.version);
# endif
#endif

#ifdef GL_VENDOR
	x = ev.vendor;
# ifdef GL_RENDERER
	BOOST_CHECK(x != ev.renderer);
# endif
# ifdef GL_SHADING_LANGUAGE_VERSION
	BOOST_CHECK(x != ev.shading_language_version);
# endif
	BOOST_CHECK(x == ev.vendor);
# ifdef GL_VERSION
	BOOST_CHECK(x != ev.version);
# endif
#endif

#ifdef GL_VERSION
	x = ev.version;
# ifdef GL_RENDERER
	BOOST_CHECK(x != ev.renderer);
# endif
# ifdef GL_SHADING_LANGUAGE_VERSION
	BOOST_CHECK(x != ev.shading_language_version);
# endif
# ifdef GL_VENDOR
	BOOST_CHECK(x != ev.vendor);
# endif
	BOOST_CHECK(x == ev.version);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
