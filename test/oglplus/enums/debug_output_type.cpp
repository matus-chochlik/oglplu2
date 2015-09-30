//  File test/oglplus/enums/debug_output_type.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_debug_output_type

#include <boost/test/unit_test.hpp>
#include "common.hpp"

BOOST_AUTO_TEST_SUITE(enum_debug_output_type)

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
# ifdef GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR
	BOOST_CHECK(x != ev.debug_type_deprecated_behavior);
# endif
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
# ifdef GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR
	BOOST_CHECK(x != ev.debug_type_deprecated_behavior);
# endif
# ifdef GL_DEBUG_TYPE_ERROR
	BOOST_CHECK(x != ev.debug_type_error);
# endif
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
# ifdef GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR
	BOOST_CHECK(x != ev.debug_type_deprecated_behavior);
# endif
# ifdef GL_DEBUG_TYPE_ERROR
	BOOST_CHECK(x != ev.debug_type_error);
# endif
# ifdef GL_DEBUG_TYPE_MARKER
	BOOST_CHECK(x != ev.debug_type_marker);
# endif
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
# ifdef GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR
	BOOST_CHECK(x != ev.debug_type_deprecated_behavior);
# endif
# ifdef GL_DEBUG_TYPE_ERROR
	BOOST_CHECK(x != ev.debug_type_error);
# endif
# ifdef GL_DEBUG_TYPE_MARKER
	BOOST_CHECK(x != ev.debug_type_marker);
# endif
# ifdef GL_DEBUG_TYPE_OTHER
	BOOST_CHECK(x != ev.debug_type_other);
# endif
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
# ifdef GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR
	BOOST_CHECK(x != ev.debug_type_deprecated_behavior);
# endif
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
# ifdef GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR
	BOOST_CHECK(x != ev.debug_type_deprecated_behavior);
# endif
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
# ifdef GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR
	BOOST_CHECK(x != ev.debug_type_deprecated_behavior);
# endif
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
# ifdef GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR
	BOOST_CHECK(x != ev.debug_type_deprecated_behavior);
# endif
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
	BOOST_CHECK(x == ev.debug_type_undefined_behavior);
# ifdef GL_DONT_CARE
	BOOST_CHECK(x != ev.dont_care);
# endif
#endif

#ifdef GL_DONT_CARE
	x = ev.dont_care;
# ifdef GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR
	BOOST_CHECK(x != ev.debug_type_deprecated_behavior);
# endif
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
	BOOST_CHECK(x == ev.dont_care);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
