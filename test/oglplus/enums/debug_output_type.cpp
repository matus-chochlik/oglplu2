//  File test/oglplus/enums/debug_output_type.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_debug_output_type

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_debug_output_type_tests)

BOOST_AUTO_TEST_CASE(enum_debug_output_type_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	debug_output_type x;
	(void)x;

#ifdef GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR
	x = ev.debug_type_deprecated_behavior;
	BOOST_CHECK(x == ev.debug_type_deprecated_behavior);
# ifdef GL_DEBUG_TYPE_ERROR
	BOOST_CHECK(x != ev.debug_type_error);
# endif
# ifdef GL_DEBUG_TYPE_MARKER
	BOOST_CHECK(x != ev.debug_type_marker);
# endif
# ifdef GL_DEBUG_TYPE_OTHER
	BOOST_CHECK(x != ev.debug_type_other);
# endif
# ifdef GL_DEBUG_TYPE_PERFORMANCE
	BOOST_CHECK(x != ev.debug_type_performance);
# endif
# ifdef GL_DEBUG_TYPE_POP_GROUP
	BOOST_CHECK(x != ev.debug_type_pop_group);
# endif
# ifdef GL_DEBUG_TYPE_PORTABILITY
	BOOST_CHECK(x != ev.debug_type_portability);
# endif
# ifdef GL_DEBUG_TYPE_PUSH_GROUP
	BOOST_CHECK(x != ev.debug_type_push_group);
# endif
# ifdef GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR
	BOOST_CHECK(x != ev.debug_type_undefined_behavior);
# endif
# ifdef GL_DONT_CARE
	BOOST_CHECK(x != ev.dont_care);
# endif
#endif

#ifdef GL_DEBUG_TYPE_ERROR
	x = ev.debug_type_error;
	BOOST_CHECK(x == ev.debug_type_error);
# ifdef GL_DEBUG_TYPE_MARKER
	BOOST_CHECK(x != ev.debug_type_marker);
# endif
# ifdef GL_DEBUG_TYPE_OTHER
	BOOST_CHECK(x != ev.debug_type_other);
# endif
# ifdef GL_DEBUG_TYPE_PERFORMANCE
	BOOST_CHECK(x != ev.debug_type_performance);
# endif
# ifdef GL_DEBUG_TYPE_POP_GROUP
	BOOST_CHECK(x != ev.debug_type_pop_group);
# endif
# ifdef GL_DEBUG_TYPE_PORTABILITY
	BOOST_CHECK(x != ev.debug_type_portability);
# endif
# ifdef GL_DEBUG_TYPE_PUSH_GROUP
	BOOST_CHECK(x != ev.debug_type_push_group);
# endif
# ifdef GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR
	BOOST_CHECK(x != ev.debug_type_undefined_behavior);
# endif
# ifdef GL_DONT_CARE
	BOOST_CHECK(x != ev.dont_care);
# endif
#endif

#ifdef GL_DEBUG_TYPE_MARKER
	x = ev.debug_type_marker;
	BOOST_CHECK(x == ev.debug_type_marker);
# ifdef GL_DEBUG_TYPE_OTHER
	BOOST_CHECK(x != ev.debug_type_other);
# endif
# ifdef GL_DEBUG_TYPE_PERFORMANCE
	BOOST_CHECK(x != ev.debug_type_performance);
# endif
# ifdef GL_DEBUG_TYPE_POP_GROUP
	BOOST_CHECK(x != ev.debug_type_pop_group);
# endif
# ifdef GL_DEBUG_TYPE_PORTABILITY
	BOOST_CHECK(x != ev.debug_type_portability);
# endif
# ifdef GL_DEBUG_TYPE_PUSH_GROUP
	BOOST_CHECK(x != ev.debug_type_push_group);
# endif
# ifdef GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR
	BOOST_CHECK(x != ev.debug_type_undefined_behavior);
# endif
# ifdef GL_DONT_CARE
	BOOST_CHECK(x != ev.dont_care);
# endif
#endif

#ifdef GL_DEBUG_TYPE_OTHER
	x = ev.debug_type_other;
	BOOST_CHECK(x == ev.debug_type_other);
# ifdef GL_DEBUG_TYPE_PERFORMANCE
	BOOST_CHECK(x != ev.debug_type_performance);
# endif
# ifdef GL_DEBUG_TYPE_POP_GROUP
	BOOST_CHECK(x != ev.debug_type_pop_group);
# endif
# ifdef GL_DEBUG_TYPE_PORTABILITY
	BOOST_CHECK(x != ev.debug_type_portability);
# endif
# ifdef GL_DEBUG_TYPE_PUSH_GROUP
	BOOST_CHECK(x != ev.debug_type_push_group);
# endif
# ifdef GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR
	BOOST_CHECK(x != ev.debug_type_undefined_behavior);
# endif
# ifdef GL_DONT_CARE
	BOOST_CHECK(x != ev.dont_care);
# endif
#endif

#ifdef GL_DEBUG_TYPE_PERFORMANCE
	x = ev.debug_type_performance;
	BOOST_CHECK(x == ev.debug_type_performance);
# ifdef GL_DEBUG_TYPE_POP_GROUP
	BOOST_CHECK(x != ev.debug_type_pop_group);
# endif
# ifdef GL_DEBUG_TYPE_PORTABILITY
	BOOST_CHECK(x != ev.debug_type_portability);
# endif
# ifdef GL_DEBUG_TYPE_PUSH_GROUP
	BOOST_CHECK(x != ev.debug_type_push_group);
# endif
# ifdef GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR
	BOOST_CHECK(x != ev.debug_type_undefined_behavior);
# endif
# ifdef GL_DONT_CARE
	BOOST_CHECK(x != ev.dont_care);
# endif
#endif

#ifdef GL_DEBUG_TYPE_POP_GROUP
	x = ev.debug_type_pop_group;
	BOOST_CHECK(x == ev.debug_type_pop_group);
# ifdef GL_DEBUG_TYPE_PORTABILITY
	BOOST_CHECK(x != ev.debug_type_portability);
# endif
# ifdef GL_DEBUG_TYPE_PUSH_GROUP
	BOOST_CHECK(x != ev.debug_type_push_group);
# endif
# ifdef GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR
	BOOST_CHECK(x != ev.debug_type_undefined_behavior);
# endif
# ifdef GL_DONT_CARE
	BOOST_CHECK(x != ev.dont_care);
# endif
#endif

#ifdef GL_DEBUG_TYPE_PORTABILITY
	x = ev.debug_type_portability;
	BOOST_CHECK(x == ev.debug_type_portability);
# ifdef GL_DEBUG_TYPE_PUSH_GROUP
	BOOST_CHECK(x != ev.debug_type_push_group);
# endif
# ifdef GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR
	BOOST_CHECK(x != ev.debug_type_undefined_behavior);
# endif
# ifdef GL_DONT_CARE
	BOOST_CHECK(x != ev.dont_care);
# endif
#endif

#ifdef GL_DEBUG_TYPE_PUSH_GROUP
	x = ev.debug_type_push_group;
	BOOST_CHECK(x == ev.debug_type_push_group);
# ifdef GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR
	BOOST_CHECK(x != ev.debug_type_undefined_behavior);
# endif
# ifdef GL_DONT_CARE
	BOOST_CHECK(x != ev.dont_care);
# endif
#endif

#ifdef GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR
	x = ev.debug_type_undefined_behavior;
	BOOST_CHECK(x == ev.debug_type_undefined_behavior);
# ifdef GL_DONT_CARE
	BOOST_CHECK(x != ev.dont_care);
# endif
#endif

#ifdef GL_DONT_CARE
	x = ev.dont_care;
	BOOST_CHECK(x == ev.dont_care);
#endif
}

BOOST_AUTO_TEST_CASE(enum_debug_output_type_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	debug_output_type x;
	(void)x;

#ifdef GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR
	x = ev.debug_type_deprecated_behavior;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DEBUG_TYPE_DEPRECATED_BEHAVIOR"
	) == 0);
#endif

#ifdef GL_DEBUG_TYPE_ERROR
	x = ev.debug_type_error;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DEBUG_TYPE_ERROR"
	) == 0);
#endif

#ifdef GL_DEBUG_TYPE_MARKER
	x = ev.debug_type_marker;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DEBUG_TYPE_MARKER"
	) == 0);
#endif

#ifdef GL_DEBUG_TYPE_OTHER
	x = ev.debug_type_other;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DEBUG_TYPE_OTHER"
	) == 0);
#endif

#ifdef GL_DEBUG_TYPE_PERFORMANCE
	x = ev.debug_type_performance;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DEBUG_TYPE_PERFORMANCE"
	) == 0);
#endif

#ifdef GL_DEBUG_TYPE_POP_GROUP
	x = ev.debug_type_pop_group;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DEBUG_TYPE_POP_GROUP"
	) == 0);
#endif

#ifdef GL_DEBUG_TYPE_PORTABILITY
	x = ev.debug_type_portability;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DEBUG_TYPE_PORTABILITY"
	) == 0);
#endif

#ifdef GL_DEBUG_TYPE_PUSH_GROUP
	x = ev.debug_type_push_group;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DEBUG_TYPE_PUSH_GROUP"
	) == 0);
#endif

#ifdef GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR
	x = ev.debug_type_undefined_behavior;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DEBUG_TYPE_UNDEFINED_BEHAVIOR"
	) == 0);
#endif

#ifdef GL_DONT_CARE
	x = ev.dont_care;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DONT_CARE"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_debug_output_type_range)
{
	using namespace oglplus;
	auto count = enum_value_range<debug_output_type>().size();

#ifdef GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR
{
	--count;
	auto r = enum_value_range<debug_output_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		debug_output_type(GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR)
	) != r.end());
}
#endif

#ifdef GL_DEBUG_TYPE_ERROR
{
	--count;
	auto r = enum_value_range<debug_output_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		debug_output_type(GL_DEBUG_TYPE_ERROR)
	) != r.end());
}
#endif

#ifdef GL_DEBUG_TYPE_MARKER
{
	--count;
	auto r = enum_value_range<debug_output_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		debug_output_type(GL_DEBUG_TYPE_MARKER)
	) != r.end());
}
#endif

#ifdef GL_DEBUG_TYPE_OTHER
{
	--count;
	auto r = enum_value_range<debug_output_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		debug_output_type(GL_DEBUG_TYPE_OTHER)
	) != r.end());
}
#endif

#ifdef GL_DEBUG_TYPE_PERFORMANCE
{
	--count;
	auto r = enum_value_range<debug_output_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		debug_output_type(GL_DEBUG_TYPE_PERFORMANCE)
	) != r.end());
}
#endif

#ifdef GL_DEBUG_TYPE_POP_GROUP
{
	--count;
	auto r = enum_value_range<debug_output_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		debug_output_type(GL_DEBUG_TYPE_POP_GROUP)
	) != r.end());
}
#endif

#ifdef GL_DEBUG_TYPE_PORTABILITY
{
	--count;
	auto r = enum_value_range<debug_output_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		debug_output_type(GL_DEBUG_TYPE_PORTABILITY)
	) != r.end());
}
#endif

#ifdef GL_DEBUG_TYPE_PUSH_GROUP
{
	--count;
	auto r = enum_value_range<debug_output_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		debug_output_type(GL_DEBUG_TYPE_PUSH_GROUP)
	) != r.end());
}
#endif

#ifdef GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR
{
	--count;
	auto r = enum_value_range<debug_output_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		debug_output_type(GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR)
	) != r.end());
}
#endif

#ifdef GL_DONT_CARE
{
	--count;
	auto r = enum_value_range<debug_output_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		debug_output_type(GL_DONT_CARE)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_debug_output_type_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	debug_output_type x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR
	x = ev.debug_type_deprecated_behavior;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.debug_type_deprecated_behavior);
#endif

#ifdef GL_DEBUG_TYPE_ERROR
	x = ev.debug_type_error;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.debug_type_error);
#endif

#ifdef GL_DEBUG_TYPE_MARKER
	x = ev.debug_type_marker;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.debug_type_marker);
#endif

#ifdef GL_DEBUG_TYPE_OTHER
	x = ev.debug_type_other;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.debug_type_other);
#endif

#ifdef GL_DEBUG_TYPE_PERFORMANCE
	x = ev.debug_type_performance;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.debug_type_performance);
#endif

#ifdef GL_DEBUG_TYPE_POP_GROUP
	x = ev.debug_type_pop_group;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.debug_type_pop_group);
#endif

#ifdef GL_DEBUG_TYPE_PORTABILITY
	x = ev.debug_type_portability;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.debug_type_portability);
#endif

#ifdef GL_DEBUG_TYPE_PUSH_GROUP
	x = ev.debug_type_push_group;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.debug_type_push_group);
#endif

#ifdef GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR
	x = ev.debug_type_undefined_behavior;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.debug_type_undefined_behavior);
#endif

#ifdef GL_DONT_CARE
	x = ev.dont_care;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.dont_care);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
