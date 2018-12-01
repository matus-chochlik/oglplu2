//  File test/boost_test/oglplus/enums/clamp_color_target.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_clamp_color_target

#include <cstring>
#include "../../unit_test_begin.inl"

BOOST_AUTO_TEST_SUITE(enum_clamp_color_target_tests)

BOOST_AUTO_TEST_CASE(enum_clamp_color_target_values) {
    using namespace oglplus;
    enum_values ev;
    EAGINE_MAYBE_UNUSED(ev);
    clamp_color_target x;
    EAGINE_MAYBE_UNUSED(x);

#ifdef GL_CLAMP_READ_COLOR
    x = ev.clamp_read_color;
    BOOST_CHECK(x == ev.clamp_read_color);
#endif
}

BOOST_AUTO_TEST_CASE(enum_clamp_color_target_names) {
    using namespace oglplus;
    enum_values ev;
    EAGINE_MAYBE_UNUSED(ev);
    clamp_color_target x;
    EAGINE_MAYBE_UNUSED(x);

#ifdef GL_CLAMP_READ_COLOR
    x = ev.clamp_read_color;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "CLAMP_READ_COLOR") == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_clamp_color_target_range) {
    using namespace oglplus;
    auto count = enum_value_range<clamp_color_target>().size();

#ifdef GL_CLAMP_READ_COLOR
    {
        --count;
        auto r = enum_value_range<clamp_color_target>();
        BOOST_CHECK(
          std::find(
            r.begin(), r.end(), clamp_color_target(GL_CLAMP_READ_COLOR)) !=
          r.end());
    }
#endif
    BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_clamp_color_target_any) {
    using namespace oglplus;
    enum_values ev;
    EAGINE_MAYBE_UNUSED(ev);
    clamp_color_target x, y;
    EAGINE_MAYBE_UNUSED(x);
    EAGINE_MAYBE_UNUSED(y);
    any_enum_value a;
    EAGINE_MAYBE_UNUSED(a);

#ifdef GL_CLAMP_READ_COLOR
    x = ev.clamp_read_color;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.clamp_read_color);
#endif
}

BOOST_AUTO_TEST_SUITE_END()

#include "../../unit_test_end.inl"
