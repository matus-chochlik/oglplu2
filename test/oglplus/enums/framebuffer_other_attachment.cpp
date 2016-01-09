//  File test/oglplus/enums/framebuffer_other_attachment.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_framebuffer_other_attachment

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_framebuffer_other_attachment_tests)

BOOST_AUTO_TEST_CASE(enum_framebuffer_other_attachment_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	framebuffer_other_attachment x;
	(void)x;

#ifdef GL_DEPTH_ATTACHMENT
	x = ev.depth_attachment;
	BOOST_CHECK(x == ev.depth_attachment);
# ifdef GL_DEPTH_STENCIL_ATTACHMENT
	BOOST_CHECK(x != ev.depth_stencil_attachment);
# endif
# ifdef GL_STENCIL_ATTACHMENT
	BOOST_CHECK(x != ev.stencil_attachment);
# endif
#endif

#ifdef GL_DEPTH_STENCIL_ATTACHMENT
	x = ev.depth_stencil_attachment;
	BOOST_CHECK(x == ev.depth_stencil_attachment);
# ifdef GL_STENCIL_ATTACHMENT
	BOOST_CHECK(x != ev.stencil_attachment);
# endif
#endif

#ifdef GL_STENCIL_ATTACHMENT
	x = ev.stencil_attachment;
	BOOST_CHECK(x == ev.stencil_attachment);
#endif
}

BOOST_AUTO_TEST_CASE(enum_framebuffer_other_attachment_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	framebuffer_other_attachment x;
	(void)x;

#ifdef GL_DEPTH_ATTACHMENT
	x = ev.depth_attachment;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DEPTH_ATTACHMENT"
	) == 0);
#endif

#ifdef GL_DEPTH_STENCIL_ATTACHMENT
	x = ev.depth_stencil_attachment;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DEPTH_STENCIL_ATTACHMENT"
	) == 0);
#endif

#ifdef GL_STENCIL_ATTACHMENT
	x = ev.stencil_attachment;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"STENCIL_ATTACHMENT"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_framebuffer_other_attachment_range)
{
	using namespace oglplus;
	auto count = enum_value_range<framebuffer_other_attachment>().size();

#ifdef GL_DEPTH_ATTACHMENT
{
	--count;
	auto r = enum_value_range<framebuffer_other_attachment>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		framebuffer_other_attachment(GL_DEPTH_ATTACHMENT)
	) != r.end());
}
#endif

#ifdef GL_DEPTH_STENCIL_ATTACHMENT
{
	--count;
	auto r = enum_value_range<framebuffer_other_attachment>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		framebuffer_other_attachment(GL_DEPTH_STENCIL_ATTACHMENT)
	) != r.end());
}
#endif

#ifdef GL_STENCIL_ATTACHMENT
{
	--count;
	auto r = enum_value_range<framebuffer_other_attachment>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		framebuffer_other_attachment(GL_STENCIL_ATTACHMENT)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_framebuffer_other_attachment_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	framebuffer_other_attachment x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_DEPTH_ATTACHMENT
	x = ev.depth_attachment;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.depth_attachment);
#endif

#ifdef GL_DEPTH_STENCIL_ATTACHMENT
	x = ev.depth_stencil_attachment;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.depth_stencil_attachment);
#endif

#ifdef GL_STENCIL_ATTACHMENT
	x = ev.stencil_attachment;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.stencil_attachment);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
