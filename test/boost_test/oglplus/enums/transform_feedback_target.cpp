//  File test/boost_test/oglplus/enums/transform_feedback_target.cpp
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
#include "common.hpp"
#define BOOST_TEST_MODULE OGLPLUS_transform_feedback_target

#include "../../unit_test_begin.inl"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_transform_feedback_target_tests)

BOOST_AUTO_TEST_CASE(enum_transform_feedback_target_values) {
    using namespace oglplus;
    enum_values ev;
    EAGINE_MAYBE_UNUSED(ev);
    transform_feedback_target x;
    EAGINE_MAYBE_UNUSED(x);

#ifdef GL_TRANSFORM_FEEDBACK
    x = ev.transform_feedback;
    BOOST_CHECK(x == ev.transform_feedback);
#endif
}

BOOST_AUTO_TEST_CASE(enum_transform_feedback_target_names) {
    using namespace oglplus;
    enum_values ev;
    EAGINE_MAYBE_UNUSED(ev);
    transform_feedback_target x;
    EAGINE_MAYBE_UNUSED(x);

#ifdef GL_TRANSFORM_FEEDBACK
    x = ev.transform_feedback;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "TRANSFORM_FEEDBACK") == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_transform_feedback_target_range) {
    using namespace oglplus;
    auto count = enum_value_range<transform_feedback_target>().size();

#ifdef GL_TRANSFORM_FEEDBACK
    {
	--count;
	auto r = enum_value_range<transform_feedback_target>();
	BOOST_CHECK(std::find(r.begin(),
		      r.end(),
		      transform_feedback_target(GL_TRANSFORM_FEEDBACK))
		    != r.end());
    }
#endif
    BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_transform_feedback_target_any) {
    using namespace oglplus;
    enum_values ev;
    EAGINE_MAYBE_UNUSED(ev);
    transform_feedback_target x, y;
    EAGINE_MAYBE_UNUSED(x);
    EAGINE_MAYBE_UNUSED(y);
    any_enum_value a;
    EAGINE_MAYBE_UNUSED(a);

#ifdef GL_TRANSFORM_FEEDBACK
    x = ev.transform_feedback;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.transform_feedback);
#endif
}

BOOST_AUTO_TEST_SUITE_END()

#include "../../unit_test_end.inl"
