//  File test/boost_test/oglplus/enums/support_level.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_support_level

#include <cstring>
#include "../../unit_test_begin.inl"

BOOST_AUTO_TEST_SUITE(enum_support_level_tests)

BOOST_AUTO_TEST_CASE(enum_support_level_values) {
    using namespace oglplus;
    enum_values ev;
    EAGINE_MAYBE_UNUSED(ev);
    support_level x;
    EAGINE_MAYBE_UNUSED(x);

#ifdef GL_CAVEAT_SUPPORT
    x = ev.caveat_support;
    BOOST_CHECK(x == ev.caveat_support);
#ifdef GL_FULL_SUPPORT
    BOOST_CHECK(x != ev.full_support);
#endif
#ifdef GL_NONE
    BOOST_CHECK(x != ev.none);
#endif
#endif

#ifdef GL_FULL_SUPPORT
    x = ev.full_support;
    BOOST_CHECK(x == ev.full_support);
#ifdef GL_NONE
    BOOST_CHECK(x != ev.none);
#endif
#endif

#ifdef GL_NONE
    x = ev.none;
    BOOST_CHECK(x == ev.none);
#endif
}

BOOST_AUTO_TEST_CASE(enum_support_level_names) {
    using namespace oglplus;
    enum_values ev;
    EAGINE_MAYBE_UNUSED(ev);
    support_level x;
    EAGINE_MAYBE_UNUSED(x);

#ifdef GL_CAVEAT_SUPPORT
    x = ev.caveat_support;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(std::strcmp(enum_value_name(x).data(), "CAVEAT_SUPPORT") == 0);
#endif

#ifdef GL_FULL_SUPPORT
    x = ev.full_support;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(std::strcmp(enum_value_name(x).data(), "FULL_SUPPORT") == 0);
#endif

#ifdef GL_NONE
    x = ev.none;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(std::strcmp(enum_value_name(x).data(), "NONE") == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_support_level_range) {
    using namespace oglplus;
    auto count = enum_value_range<support_level>().size();

#ifdef GL_CAVEAT_SUPPORT
    {
        --count;
        auto r = enum_value_range<support_level>();
        BOOST_CHECK(
          std::find(r.begin(), r.end(), support_level(GL_CAVEAT_SUPPORT)) !=
          r.end());
    }
#endif

#ifdef GL_FULL_SUPPORT
    {
        --count;
        auto r = enum_value_range<support_level>();
        BOOST_CHECK(
          std::find(r.begin(), r.end(), support_level(GL_FULL_SUPPORT)) !=
          r.end());
    }
#endif

#ifdef GL_NONE
    {
        --count;
        auto r = enum_value_range<support_level>();
        BOOST_CHECK(
          std::find(r.begin(), r.end(), support_level(GL_NONE)) != r.end());
    }
#endif
    BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_support_level_any) {
    using namespace oglplus;
    enum_values ev;
    EAGINE_MAYBE_UNUSED(ev);
    support_level x, y;
    EAGINE_MAYBE_UNUSED(x);
    EAGINE_MAYBE_UNUSED(y);
    any_enum_value a;
    EAGINE_MAYBE_UNUSED(a);

#ifdef GL_CAVEAT_SUPPORT
    x = ev.caveat_support;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.caveat_support);
#endif

#ifdef GL_FULL_SUPPORT
    x = ev.full_support;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.full_support);
#endif

#ifdef GL_NONE
    x = ev.none;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.none);
#endif
}

BOOST_AUTO_TEST_SUITE_END()

#include "../../unit_test_end.inl"
