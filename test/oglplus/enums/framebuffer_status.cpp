//  File test/oglplus/enums/framebuffer_status.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_framebuffer_status

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_framebuffer_status_tests)

BOOST_AUTO_TEST_CASE(enum_framebuffer_status_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	framebuffer_status x;
	(void)x;

#ifdef GL_FRAMEBUFFER_COMPLETE
	x = ev.framebuffer_complete;
	BOOST_CHECK(x == ev.framebuffer_complete);
# ifdef GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT
	BOOST_CHECK(x != ev.framebuffer_incomplete_attachment);
# endif
# ifdef GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS
	BOOST_CHECK(x != ev.framebuffer_incomplete_layer_targets);
# endif
# ifdef GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT
	BOOST_CHECK(x != ev.framebuffer_incomplete_missing_attachment);
# endif
# ifdef GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE
	BOOST_CHECK(x != ev.framebuffer_incomplete_multisample);
# endif
# ifdef GL_FRAMEBUFFER_UNDEFINED
	BOOST_CHECK(x != ev.framebuffer_undefined);
# endif
# ifdef GL_FRAMEBUFFER_UNSUPPORTED
	BOOST_CHECK(x != ev.framebuffer_unsupported);
# endif
#endif

#ifdef GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT
	x = ev.framebuffer_incomplete_attachment;
	BOOST_CHECK(x == ev.framebuffer_incomplete_attachment);
# ifdef GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS
	BOOST_CHECK(x != ev.framebuffer_incomplete_layer_targets);
# endif
# ifdef GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT
	BOOST_CHECK(x != ev.framebuffer_incomplete_missing_attachment);
# endif
# ifdef GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE
	BOOST_CHECK(x != ev.framebuffer_incomplete_multisample);
# endif
# ifdef GL_FRAMEBUFFER_UNDEFINED
	BOOST_CHECK(x != ev.framebuffer_undefined);
# endif
# ifdef GL_FRAMEBUFFER_UNSUPPORTED
	BOOST_CHECK(x != ev.framebuffer_unsupported);
# endif
#endif

#ifdef GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS
	x = ev.framebuffer_incomplete_layer_targets;
	BOOST_CHECK(x == ev.framebuffer_incomplete_layer_targets);
# ifdef GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT
	BOOST_CHECK(x != ev.framebuffer_incomplete_missing_attachment);
# endif
# ifdef GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE
	BOOST_CHECK(x != ev.framebuffer_incomplete_multisample);
# endif
# ifdef GL_FRAMEBUFFER_UNDEFINED
	BOOST_CHECK(x != ev.framebuffer_undefined);
# endif
# ifdef GL_FRAMEBUFFER_UNSUPPORTED
	BOOST_CHECK(x != ev.framebuffer_unsupported);
# endif
#endif

#ifdef GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT
	x = ev.framebuffer_incomplete_missing_attachment;
	BOOST_CHECK(x == ev.framebuffer_incomplete_missing_attachment);
# ifdef GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE
	BOOST_CHECK(x != ev.framebuffer_incomplete_multisample);
# endif
# ifdef GL_FRAMEBUFFER_UNDEFINED
	BOOST_CHECK(x != ev.framebuffer_undefined);
# endif
# ifdef GL_FRAMEBUFFER_UNSUPPORTED
	BOOST_CHECK(x != ev.framebuffer_unsupported);
# endif
#endif

#ifdef GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE
	x = ev.framebuffer_incomplete_multisample;
	BOOST_CHECK(x == ev.framebuffer_incomplete_multisample);
# ifdef GL_FRAMEBUFFER_UNDEFINED
	BOOST_CHECK(x != ev.framebuffer_undefined);
# endif
# ifdef GL_FRAMEBUFFER_UNSUPPORTED
	BOOST_CHECK(x != ev.framebuffer_unsupported);
# endif
#endif

#ifdef GL_FRAMEBUFFER_UNDEFINED
	x = ev.framebuffer_undefined;
	BOOST_CHECK(x == ev.framebuffer_undefined);
# ifdef GL_FRAMEBUFFER_UNSUPPORTED
	BOOST_CHECK(x != ev.framebuffer_unsupported);
# endif
#endif

#ifdef GL_FRAMEBUFFER_UNSUPPORTED
	x = ev.framebuffer_unsupported;
	BOOST_CHECK(x == ev.framebuffer_unsupported);
#endif
}

BOOST_AUTO_TEST_CASE(enum_framebuffer_status_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	framebuffer_status x;
	(void)x;

#ifdef GL_FRAMEBUFFER_COMPLETE
	x = ev.framebuffer_complete;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"FRAMEBUFFER_COMPLETE"
	) == 0);
#endif

#ifdef GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT
	x = ev.framebuffer_incomplete_attachment;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"FRAMEBUFFER_INCOMPLETE_ATTACHMENT"
	) == 0);
#endif

#ifdef GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS
	x = ev.framebuffer_incomplete_layer_targets;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS"
	) == 0);
#endif

#ifdef GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT
	x = ev.framebuffer_incomplete_missing_attachment;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT"
	) == 0);
#endif

#ifdef GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE
	x = ev.framebuffer_incomplete_multisample;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"FRAMEBUFFER_INCOMPLETE_MULTISAMPLE"
	) == 0);
#endif

#ifdef GL_FRAMEBUFFER_UNDEFINED
	x = ev.framebuffer_undefined;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"FRAMEBUFFER_UNDEFINED"
	) == 0);
#endif

#ifdef GL_FRAMEBUFFER_UNSUPPORTED
	x = ev.framebuffer_unsupported;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"FRAMEBUFFER_UNSUPPORTED"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_framebuffer_status_range)
{
	using namespace oglplus;
	auto count = enum_value_range<framebuffer_status>().size();

#ifdef GL_FRAMEBUFFER_COMPLETE
{
	--count;
	auto r = enum_value_range<framebuffer_status>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		framebuffer_status(GL_FRAMEBUFFER_COMPLETE)
	) != r.end());
}
#endif

#ifdef GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT
{
	--count;
	auto r = enum_value_range<framebuffer_status>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		framebuffer_status(GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT)
	) != r.end());
}
#endif

#ifdef GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS
{
	--count;
	auto r = enum_value_range<framebuffer_status>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		framebuffer_status(GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS)
	) != r.end());
}
#endif

#ifdef GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT
{
	--count;
	auto r = enum_value_range<framebuffer_status>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		framebuffer_status(GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT)
	) != r.end());
}
#endif

#ifdef GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE
{
	--count;
	auto r = enum_value_range<framebuffer_status>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		framebuffer_status(GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE)
	) != r.end());
}
#endif

#ifdef GL_FRAMEBUFFER_UNDEFINED
{
	--count;
	auto r = enum_value_range<framebuffer_status>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		framebuffer_status(GL_FRAMEBUFFER_UNDEFINED)
	) != r.end());
}
#endif

#ifdef GL_FRAMEBUFFER_UNSUPPORTED
{
	--count;
	auto r = enum_value_range<framebuffer_status>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		framebuffer_status(GL_FRAMEBUFFER_UNSUPPORTED)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_framebuffer_status_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	framebuffer_status x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_FRAMEBUFFER_COMPLETE
	x = ev.framebuffer_complete;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.framebuffer_complete);
#endif

#ifdef GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT
	x = ev.framebuffer_incomplete_attachment;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.framebuffer_incomplete_attachment);
#endif

#ifdef GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS
	x = ev.framebuffer_incomplete_layer_targets;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.framebuffer_incomplete_layer_targets);
#endif

#ifdef GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT
	x = ev.framebuffer_incomplete_missing_attachment;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.framebuffer_incomplete_missing_attachment);
#endif

#ifdef GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE
	x = ev.framebuffer_incomplete_multisample;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.framebuffer_incomplete_multisample);
#endif

#ifdef GL_FRAMEBUFFER_UNDEFINED
	x = ev.framebuffer_undefined;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.framebuffer_undefined);
#endif

#ifdef GL_FRAMEBUFFER_UNSUPPORTED
	x = ev.framebuffer_unsupported;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.framebuffer_unsupported);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
