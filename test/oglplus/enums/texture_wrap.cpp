//  File test/oglplus/enums/texture_wrap.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_texture_wrap

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_texture_wrap)

BOOST_AUTO_TEST_CASE(enum_texture_wrap_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	texture_wrap x;
	(void)x;

#ifdef GL_CLAMP_TO_BORDER
	x = ev.clamp_to_border;
	BOOST_CHECK(x == ev.clamp_to_border);
# ifdef GL_CLAMP_TO_EDGE
	BOOST_CHECK(x != ev.clamp_to_edge);
# endif
# ifdef GL_MIRROR_CLAMP_TO_EDGE
	BOOST_CHECK(x != ev.mirror_clamp_to_edge);
# endif
# ifdef GL_MIRRORED_REPEAT
	BOOST_CHECK(x != ev.mirrored_repeat);
# endif
# ifdef GL_REPEAT
	BOOST_CHECK(x != ev.repeat);
# endif
#endif

#ifdef GL_CLAMP_TO_EDGE
	x = ev.clamp_to_edge;
# ifdef GL_CLAMP_TO_BORDER
	BOOST_CHECK(x != ev.clamp_to_border);
# endif
	BOOST_CHECK(x == ev.clamp_to_edge);
# ifdef GL_MIRROR_CLAMP_TO_EDGE
	BOOST_CHECK(x != ev.mirror_clamp_to_edge);
# endif
# ifdef GL_MIRRORED_REPEAT
	BOOST_CHECK(x != ev.mirrored_repeat);
# endif
# ifdef GL_REPEAT
	BOOST_CHECK(x != ev.repeat);
# endif
#endif

#ifdef GL_MIRROR_CLAMP_TO_EDGE
	x = ev.mirror_clamp_to_edge;
# ifdef GL_CLAMP_TO_BORDER
	BOOST_CHECK(x != ev.clamp_to_border);
# endif
# ifdef GL_CLAMP_TO_EDGE
	BOOST_CHECK(x != ev.clamp_to_edge);
# endif
	BOOST_CHECK(x == ev.mirror_clamp_to_edge);
# ifdef GL_MIRRORED_REPEAT
	BOOST_CHECK(x != ev.mirrored_repeat);
# endif
# ifdef GL_REPEAT
	BOOST_CHECK(x != ev.repeat);
# endif
#endif

#ifdef GL_MIRRORED_REPEAT
	x = ev.mirrored_repeat;
# ifdef GL_CLAMP_TO_BORDER
	BOOST_CHECK(x != ev.clamp_to_border);
# endif
# ifdef GL_CLAMP_TO_EDGE
	BOOST_CHECK(x != ev.clamp_to_edge);
# endif
# ifdef GL_MIRROR_CLAMP_TO_EDGE
	BOOST_CHECK(x != ev.mirror_clamp_to_edge);
# endif
	BOOST_CHECK(x == ev.mirrored_repeat);
# ifdef GL_REPEAT
	BOOST_CHECK(x != ev.repeat);
# endif
#endif

#ifdef GL_REPEAT
	x = ev.repeat;
# ifdef GL_CLAMP_TO_BORDER
	BOOST_CHECK(x != ev.clamp_to_border);
# endif
# ifdef GL_CLAMP_TO_EDGE
	BOOST_CHECK(x != ev.clamp_to_edge);
# endif
# ifdef GL_MIRROR_CLAMP_TO_EDGE
	BOOST_CHECK(x != ev.mirror_clamp_to_edge);
# endif
# ifdef GL_MIRRORED_REPEAT
	BOOST_CHECK(x != ev.mirrored_repeat);
# endif
	BOOST_CHECK(x == ev.repeat);
#endif
}

BOOST_AUTO_TEST_CASE(enum_texture_wrap_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	texture_wrap x;
	(void)x;

#ifdef GL_CLAMP_TO_BORDER
	x = ev.clamp_to_border;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"CLAMP_TO_BORDER"
	) == 0);
#endif

#ifdef GL_CLAMP_TO_EDGE
	x = ev.clamp_to_edge;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"CLAMP_TO_EDGE"
	) == 0);
#endif

#ifdef GL_MIRROR_CLAMP_TO_EDGE
	x = ev.mirror_clamp_to_edge;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MIRROR_CLAMP_TO_EDGE"
	) == 0);
#endif

#ifdef GL_MIRRORED_REPEAT
	x = ev.mirrored_repeat;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MIRRORED_REPEAT"
	) == 0);
#endif

#ifdef GL_REPEAT
	x = ev.repeat;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"REPEAT"
	) == 0);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
