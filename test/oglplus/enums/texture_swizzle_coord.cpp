//  File test/oglplus/enums/texture_swizzle_coord.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_texture_swizzle_coord

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_texture_swizzle_coord)

BOOST_AUTO_TEST_CASE(enum_texture_swizzle_coord_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	texture_swizzle_coord x;
	(void)x;

#ifdef GL_TEXTURE_SWIZZLE_A
	x = ev.texture_swizzle_a;
	BOOST_CHECK(x == ev.texture_swizzle_a);
# ifdef GL_TEXTURE_SWIZZLE_B
	BOOST_CHECK(x != ev.texture_swizzle_b);
# endif
# ifdef GL_TEXTURE_SWIZZLE_G
	BOOST_CHECK(x != ev.texture_swizzle_g);
# endif
# ifdef GL_TEXTURE_SWIZZLE_R
	BOOST_CHECK(x != ev.texture_swizzle_r);
# endif
# ifdef GL_TEXTURE_SWIZZLE_RGBA
	BOOST_CHECK(x != ev.texture_swizzle_rgba);
# endif
#endif

#ifdef GL_TEXTURE_SWIZZLE_B
	x = ev.texture_swizzle_b;
# ifdef GL_TEXTURE_SWIZZLE_A
	BOOST_CHECK(x != ev.texture_swizzle_a);
# endif
	BOOST_CHECK(x == ev.texture_swizzle_b);
# ifdef GL_TEXTURE_SWIZZLE_G
	BOOST_CHECK(x != ev.texture_swizzle_g);
# endif
# ifdef GL_TEXTURE_SWIZZLE_R
	BOOST_CHECK(x != ev.texture_swizzle_r);
# endif
# ifdef GL_TEXTURE_SWIZZLE_RGBA
	BOOST_CHECK(x != ev.texture_swizzle_rgba);
# endif
#endif

#ifdef GL_TEXTURE_SWIZZLE_G
	x = ev.texture_swizzle_g;
# ifdef GL_TEXTURE_SWIZZLE_A
	BOOST_CHECK(x != ev.texture_swizzle_a);
# endif
# ifdef GL_TEXTURE_SWIZZLE_B
	BOOST_CHECK(x != ev.texture_swizzle_b);
# endif
	BOOST_CHECK(x == ev.texture_swizzle_g);
# ifdef GL_TEXTURE_SWIZZLE_R
	BOOST_CHECK(x != ev.texture_swizzle_r);
# endif
# ifdef GL_TEXTURE_SWIZZLE_RGBA
	BOOST_CHECK(x != ev.texture_swizzle_rgba);
# endif
#endif

#ifdef GL_TEXTURE_SWIZZLE_R
	x = ev.texture_swizzle_r;
# ifdef GL_TEXTURE_SWIZZLE_A
	BOOST_CHECK(x != ev.texture_swizzle_a);
# endif
# ifdef GL_TEXTURE_SWIZZLE_B
	BOOST_CHECK(x != ev.texture_swizzle_b);
# endif
# ifdef GL_TEXTURE_SWIZZLE_G
	BOOST_CHECK(x != ev.texture_swizzle_g);
# endif
	BOOST_CHECK(x == ev.texture_swizzle_r);
# ifdef GL_TEXTURE_SWIZZLE_RGBA
	BOOST_CHECK(x != ev.texture_swizzle_rgba);
# endif
#endif

#ifdef GL_TEXTURE_SWIZZLE_RGBA
	x = ev.texture_swizzle_rgba;
# ifdef GL_TEXTURE_SWIZZLE_A
	BOOST_CHECK(x != ev.texture_swizzle_a);
# endif
# ifdef GL_TEXTURE_SWIZZLE_B
	BOOST_CHECK(x != ev.texture_swizzle_b);
# endif
# ifdef GL_TEXTURE_SWIZZLE_G
	BOOST_CHECK(x != ev.texture_swizzle_g);
# endif
# ifdef GL_TEXTURE_SWIZZLE_R
	BOOST_CHECK(x != ev.texture_swizzle_r);
# endif
	BOOST_CHECK(x == ev.texture_swizzle_rgba);
#endif
}

BOOST_AUTO_TEST_CASE(enum_texture_swizzle_coord_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	texture_swizzle_coord x;
	(void)x;

#ifdef GL_TEXTURE_SWIZZLE_A
	x = ev.texture_swizzle_a;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_SWIZZLE_A"
	) == 0);
#endif

#ifdef GL_TEXTURE_SWIZZLE_B
	x = ev.texture_swizzle_b;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_SWIZZLE_B"
	) == 0);
#endif

#ifdef GL_TEXTURE_SWIZZLE_G
	x = ev.texture_swizzle_g;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_SWIZZLE_G"
	) == 0);
#endif

#ifdef GL_TEXTURE_SWIZZLE_R
	x = ev.texture_swizzle_r;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_SWIZZLE_R"
	) == 0);
#endif

#ifdef GL_TEXTURE_SWIZZLE_RGBA
	x = ev.texture_swizzle_rgba;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_SWIZZLE_RGBA"
	) == 0);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
