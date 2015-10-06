//  File test/oglplus/enums/texture_min_filter.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_texture_min_filter

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_texture_min_filter)

BOOST_AUTO_TEST_CASE(enum_texture_min_filter_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	texture_min_filter x;
	(void)x;

#ifdef GL_LINEAR
	x = ev.linear;
	BOOST_CHECK(x == ev.linear);
# ifdef GL_LINEAR_MIPMAP_LINEAR
	BOOST_CHECK(x != ev.linear_mipmap_linear);
# endif
# ifdef GL_LINEAR_MIPMAP_NEAREST
	BOOST_CHECK(x != ev.linear_mipmap_nearest);
# endif
# ifdef GL_NEAREST
	BOOST_CHECK(x != ev.nearest);
# endif
# ifdef GL_NEAREST_MIPMAP_LINEAR
	BOOST_CHECK(x != ev.nearest_mipmap_linear);
# endif
# ifdef GL_NEAREST_MIPMAP_NEAREST
	BOOST_CHECK(x != ev.nearest_mipmap_nearest);
# endif
#endif

#ifdef GL_LINEAR_MIPMAP_LINEAR
	x = ev.linear_mipmap_linear;
# ifdef GL_LINEAR
	BOOST_CHECK(x != ev.linear);
# endif
	BOOST_CHECK(x == ev.linear_mipmap_linear);
# ifdef GL_LINEAR_MIPMAP_NEAREST
	BOOST_CHECK(x != ev.linear_mipmap_nearest);
# endif
# ifdef GL_NEAREST
	BOOST_CHECK(x != ev.nearest);
# endif
# ifdef GL_NEAREST_MIPMAP_LINEAR
	BOOST_CHECK(x != ev.nearest_mipmap_linear);
# endif
# ifdef GL_NEAREST_MIPMAP_NEAREST
	BOOST_CHECK(x != ev.nearest_mipmap_nearest);
# endif
#endif

#ifdef GL_LINEAR_MIPMAP_NEAREST
	x = ev.linear_mipmap_nearest;
# ifdef GL_LINEAR
	BOOST_CHECK(x != ev.linear);
# endif
# ifdef GL_LINEAR_MIPMAP_LINEAR
	BOOST_CHECK(x != ev.linear_mipmap_linear);
# endif
	BOOST_CHECK(x == ev.linear_mipmap_nearest);
# ifdef GL_NEAREST
	BOOST_CHECK(x != ev.nearest);
# endif
# ifdef GL_NEAREST_MIPMAP_LINEAR
	BOOST_CHECK(x != ev.nearest_mipmap_linear);
# endif
# ifdef GL_NEAREST_MIPMAP_NEAREST
	BOOST_CHECK(x != ev.nearest_mipmap_nearest);
# endif
#endif

#ifdef GL_NEAREST
	x = ev.nearest;
# ifdef GL_LINEAR
	BOOST_CHECK(x != ev.linear);
# endif
# ifdef GL_LINEAR_MIPMAP_LINEAR
	BOOST_CHECK(x != ev.linear_mipmap_linear);
# endif
# ifdef GL_LINEAR_MIPMAP_NEAREST
	BOOST_CHECK(x != ev.linear_mipmap_nearest);
# endif
	BOOST_CHECK(x == ev.nearest);
# ifdef GL_NEAREST_MIPMAP_LINEAR
	BOOST_CHECK(x != ev.nearest_mipmap_linear);
# endif
# ifdef GL_NEAREST_MIPMAP_NEAREST
	BOOST_CHECK(x != ev.nearest_mipmap_nearest);
# endif
#endif

#ifdef GL_NEAREST_MIPMAP_LINEAR
	x = ev.nearest_mipmap_linear;
# ifdef GL_LINEAR
	BOOST_CHECK(x != ev.linear);
# endif
# ifdef GL_LINEAR_MIPMAP_LINEAR
	BOOST_CHECK(x != ev.linear_mipmap_linear);
# endif
# ifdef GL_LINEAR_MIPMAP_NEAREST
	BOOST_CHECK(x != ev.linear_mipmap_nearest);
# endif
# ifdef GL_NEAREST
	BOOST_CHECK(x != ev.nearest);
# endif
	BOOST_CHECK(x == ev.nearest_mipmap_linear);
# ifdef GL_NEAREST_MIPMAP_NEAREST
	BOOST_CHECK(x != ev.nearest_mipmap_nearest);
# endif
#endif

#ifdef GL_NEAREST_MIPMAP_NEAREST
	x = ev.nearest_mipmap_nearest;
# ifdef GL_LINEAR
	BOOST_CHECK(x != ev.linear);
# endif
# ifdef GL_LINEAR_MIPMAP_LINEAR
	BOOST_CHECK(x != ev.linear_mipmap_linear);
# endif
# ifdef GL_LINEAR_MIPMAP_NEAREST
	BOOST_CHECK(x != ev.linear_mipmap_nearest);
# endif
# ifdef GL_NEAREST
	BOOST_CHECK(x != ev.nearest);
# endif
# ifdef GL_NEAREST_MIPMAP_LINEAR
	BOOST_CHECK(x != ev.nearest_mipmap_linear);
# endif
	BOOST_CHECK(x == ev.nearest_mipmap_nearest);
#endif
}

BOOST_AUTO_TEST_CASE(enum_texture_min_filter_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	texture_min_filter x;
	(void)x;

#ifdef GL_LINEAR
	x = ev.linear;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"LINEAR"
	) == 0);
#endif

#ifdef GL_LINEAR_MIPMAP_LINEAR
	x = ev.linear_mipmap_linear;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"LINEAR_MIPMAP_LINEAR"
	) == 0);
#endif

#ifdef GL_LINEAR_MIPMAP_NEAREST
	x = ev.linear_mipmap_nearest;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"LINEAR_MIPMAP_NEAREST"
	) == 0);
#endif

#ifdef GL_NEAREST
	x = ev.nearest;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"NEAREST"
	) == 0);
#endif

#ifdef GL_NEAREST_MIPMAP_LINEAR
	x = ev.nearest_mipmap_linear;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"NEAREST_MIPMAP_LINEAR"
	) == 0);
#endif

#ifdef GL_NEAREST_MIPMAP_NEAREST
	x = ev.nearest_mipmap_nearest;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"NEAREST_MIPMAP_NEAREST"
	) == 0);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
