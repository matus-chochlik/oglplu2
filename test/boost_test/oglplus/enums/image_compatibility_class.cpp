//  File test/boost_test/oglplus/enums/image_compatibility_class.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_image_compatibility_class

#include "../../unit_test_begin.inl"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_image_compatibility_class_tests)

BOOST_AUTO_TEST_CASE(enum_image_compatibility_class_values) {
    using namespace oglplus;
    enum_values ev;
    EAGINE_MAYBE_UNUSED(ev);
    image_compatibility_class x;
    EAGINE_MAYBE_UNUSED(x);

#ifdef GL_IMAGE_CLASS_10_10_10_2
    x = ev.image_class_10_10_10_2;
    BOOST_CHECK(x == ev.image_class_10_10_10_2);
#ifdef GL_IMAGE_CLASS_11_11_10
    BOOST_CHECK(x != ev.image_class_11_11_10);
#endif
#ifdef GL_IMAGE_CLASS_1_X_16
    BOOST_CHECK(x != ev.image_class_1_x_16);
#endif
#ifdef GL_IMAGE_CLASS_1_X_32
    BOOST_CHECK(x != ev.image_class_1_x_32);
#endif
#ifdef GL_IMAGE_CLASS_1_X_8
    BOOST_CHECK(x != ev.image_class_1_x_8);
#endif
#ifdef GL_IMAGE_CLASS_2_X_16
    BOOST_CHECK(x != ev.image_class_2_x_16);
#endif
#ifdef GL_IMAGE_CLASS_2_X_32
    BOOST_CHECK(x != ev.image_class_2_x_32);
#endif
#ifdef GL_IMAGE_CLASS_2_X_8
    BOOST_CHECK(x != ev.image_class_2_x_8);
#endif
#ifdef GL_IMAGE_CLASS_4_X_16
    BOOST_CHECK(x != ev.image_class_4_x_16);
#endif
#ifdef GL_IMAGE_CLASS_4_X_32
    BOOST_CHECK(x != ev.image_class_4_x_32);
#endif
#ifdef GL_IMAGE_CLASS_4_X_8
    BOOST_CHECK(x != ev.image_class_4_x_8);
#endif
#endif

#ifdef GL_IMAGE_CLASS_11_11_10
    x = ev.image_class_11_11_10;
    BOOST_CHECK(x == ev.image_class_11_11_10);
#ifdef GL_IMAGE_CLASS_1_X_16
    BOOST_CHECK(x != ev.image_class_1_x_16);
#endif
#ifdef GL_IMAGE_CLASS_1_X_32
    BOOST_CHECK(x != ev.image_class_1_x_32);
#endif
#ifdef GL_IMAGE_CLASS_1_X_8
    BOOST_CHECK(x != ev.image_class_1_x_8);
#endif
#ifdef GL_IMAGE_CLASS_2_X_16
    BOOST_CHECK(x != ev.image_class_2_x_16);
#endif
#ifdef GL_IMAGE_CLASS_2_X_32
    BOOST_CHECK(x != ev.image_class_2_x_32);
#endif
#ifdef GL_IMAGE_CLASS_2_X_8
    BOOST_CHECK(x != ev.image_class_2_x_8);
#endif
#ifdef GL_IMAGE_CLASS_4_X_16
    BOOST_CHECK(x != ev.image_class_4_x_16);
#endif
#ifdef GL_IMAGE_CLASS_4_X_32
    BOOST_CHECK(x != ev.image_class_4_x_32);
#endif
#ifdef GL_IMAGE_CLASS_4_X_8
    BOOST_CHECK(x != ev.image_class_4_x_8);
#endif
#endif

#ifdef GL_IMAGE_CLASS_1_X_16
    x = ev.image_class_1_x_16;
    BOOST_CHECK(x == ev.image_class_1_x_16);
#ifdef GL_IMAGE_CLASS_1_X_32
    BOOST_CHECK(x != ev.image_class_1_x_32);
#endif
#ifdef GL_IMAGE_CLASS_1_X_8
    BOOST_CHECK(x != ev.image_class_1_x_8);
#endif
#ifdef GL_IMAGE_CLASS_2_X_16
    BOOST_CHECK(x != ev.image_class_2_x_16);
#endif
#ifdef GL_IMAGE_CLASS_2_X_32
    BOOST_CHECK(x != ev.image_class_2_x_32);
#endif
#ifdef GL_IMAGE_CLASS_2_X_8
    BOOST_CHECK(x != ev.image_class_2_x_8);
#endif
#ifdef GL_IMAGE_CLASS_4_X_16
    BOOST_CHECK(x != ev.image_class_4_x_16);
#endif
#ifdef GL_IMAGE_CLASS_4_X_32
    BOOST_CHECK(x != ev.image_class_4_x_32);
#endif
#ifdef GL_IMAGE_CLASS_4_X_8
    BOOST_CHECK(x != ev.image_class_4_x_8);
#endif
#endif

#ifdef GL_IMAGE_CLASS_1_X_32
    x = ev.image_class_1_x_32;
    BOOST_CHECK(x == ev.image_class_1_x_32);
#ifdef GL_IMAGE_CLASS_1_X_8
    BOOST_CHECK(x != ev.image_class_1_x_8);
#endif
#ifdef GL_IMAGE_CLASS_2_X_16
    BOOST_CHECK(x != ev.image_class_2_x_16);
#endif
#ifdef GL_IMAGE_CLASS_2_X_32
    BOOST_CHECK(x != ev.image_class_2_x_32);
#endif
#ifdef GL_IMAGE_CLASS_2_X_8
    BOOST_CHECK(x != ev.image_class_2_x_8);
#endif
#ifdef GL_IMAGE_CLASS_4_X_16
    BOOST_CHECK(x != ev.image_class_4_x_16);
#endif
#ifdef GL_IMAGE_CLASS_4_X_32
    BOOST_CHECK(x != ev.image_class_4_x_32);
#endif
#ifdef GL_IMAGE_CLASS_4_X_8
    BOOST_CHECK(x != ev.image_class_4_x_8);
#endif
#endif

#ifdef GL_IMAGE_CLASS_1_X_8
    x = ev.image_class_1_x_8;
    BOOST_CHECK(x == ev.image_class_1_x_8);
#ifdef GL_IMAGE_CLASS_2_X_16
    BOOST_CHECK(x != ev.image_class_2_x_16);
#endif
#ifdef GL_IMAGE_CLASS_2_X_32
    BOOST_CHECK(x != ev.image_class_2_x_32);
#endif
#ifdef GL_IMAGE_CLASS_2_X_8
    BOOST_CHECK(x != ev.image_class_2_x_8);
#endif
#ifdef GL_IMAGE_CLASS_4_X_16
    BOOST_CHECK(x != ev.image_class_4_x_16);
#endif
#ifdef GL_IMAGE_CLASS_4_X_32
    BOOST_CHECK(x != ev.image_class_4_x_32);
#endif
#ifdef GL_IMAGE_CLASS_4_X_8
    BOOST_CHECK(x != ev.image_class_4_x_8);
#endif
#endif

#ifdef GL_IMAGE_CLASS_2_X_16
    x = ev.image_class_2_x_16;
    BOOST_CHECK(x == ev.image_class_2_x_16);
#ifdef GL_IMAGE_CLASS_2_X_32
    BOOST_CHECK(x != ev.image_class_2_x_32);
#endif
#ifdef GL_IMAGE_CLASS_2_X_8
    BOOST_CHECK(x != ev.image_class_2_x_8);
#endif
#ifdef GL_IMAGE_CLASS_4_X_16
    BOOST_CHECK(x != ev.image_class_4_x_16);
#endif
#ifdef GL_IMAGE_CLASS_4_X_32
    BOOST_CHECK(x != ev.image_class_4_x_32);
#endif
#ifdef GL_IMAGE_CLASS_4_X_8
    BOOST_CHECK(x != ev.image_class_4_x_8);
#endif
#endif

#ifdef GL_IMAGE_CLASS_2_X_32
    x = ev.image_class_2_x_32;
    BOOST_CHECK(x == ev.image_class_2_x_32);
#ifdef GL_IMAGE_CLASS_2_X_8
    BOOST_CHECK(x != ev.image_class_2_x_8);
#endif
#ifdef GL_IMAGE_CLASS_4_X_16
    BOOST_CHECK(x != ev.image_class_4_x_16);
#endif
#ifdef GL_IMAGE_CLASS_4_X_32
    BOOST_CHECK(x != ev.image_class_4_x_32);
#endif
#ifdef GL_IMAGE_CLASS_4_X_8
    BOOST_CHECK(x != ev.image_class_4_x_8);
#endif
#endif

#ifdef GL_IMAGE_CLASS_2_X_8
    x = ev.image_class_2_x_8;
    BOOST_CHECK(x == ev.image_class_2_x_8);
#ifdef GL_IMAGE_CLASS_4_X_16
    BOOST_CHECK(x != ev.image_class_4_x_16);
#endif
#ifdef GL_IMAGE_CLASS_4_X_32
    BOOST_CHECK(x != ev.image_class_4_x_32);
#endif
#ifdef GL_IMAGE_CLASS_4_X_8
    BOOST_CHECK(x != ev.image_class_4_x_8);
#endif
#endif

#ifdef GL_IMAGE_CLASS_4_X_16
    x = ev.image_class_4_x_16;
    BOOST_CHECK(x == ev.image_class_4_x_16);
#ifdef GL_IMAGE_CLASS_4_X_32
    BOOST_CHECK(x != ev.image_class_4_x_32);
#endif
#ifdef GL_IMAGE_CLASS_4_X_8
    BOOST_CHECK(x != ev.image_class_4_x_8);
#endif
#endif

#ifdef GL_IMAGE_CLASS_4_X_32
    x = ev.image_class_4_x_32;
    BOOST_CHECK(x == ev.image_class_4_x_32);
#ifdef GL_IMAGE_CLASS_4_X_8
    BOOST_CHECK(x != ev.image_class_4_x_8);
#endif
#endif

#ifdef GL_IMAGE_CLASS_4_X_8
    x = ev.image_class_4_x_8;
    BOOST_CHECK(x == ev.image_class_4_x_8);
#endif
}

BOOST_AUTO_TEST_CASE(enum_image_compatibility_class_names) {
    using namespace oglplus;
    enum_values ev;
    EAGINE_MAYBE_UNUSED(ev);
    image_compatibility_class x;
    EAGINE_MAYBE_UNUSED(x);

#ifdef GL_IMAGE_CLASS_10_10_10_2
    x = ev.image_class_10_10_10_2;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "IMAGE_CLASS_10_10_10_2") == 0);
#endif

#ifdef GL_IMAGE_CLASS_11_11_10
    x = ev.image_class_11_11_10;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "IMAGE_CLASS_11_11_10") == 0);
#endif

#ifdef GL_IMAGE_CLASS_1_X_16
    x = ev.image_class_1_x_16;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "IMAGE_CLASS_1_X_16") == 0);
#endif

#ifdef GL_IMAGE_CLASS_1_X_32
    x = ev.image_class_1_x_32;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "IMAGE_CLASS_1_X_32") == 0);
#endif

#ifdef GL_IMAGE_CLASS_1_X_8
    x = ev.image_class_1_x_8;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "IMAGE_CLASS_1_X_8") == 0);
#endif

#ifdef GL_IMAGE_CLASS_2_X_16
    x = ev.image_class_2_x_16;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "IMAGE_CLASS_2_X_16") == 0);
#endif

#ifdef GL_IMAGE_CLASS_2_X_32
    x = ev.image_class_2_x_32;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "IMAGE_CLASS_2_X_32") == 0);
#endif

#ifdef GL_IMAGE_CLASS_2_X_8
    x = ev.image_class_2_x_8;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "IMAGE_CLASS_2_X_8") == 0);
#endif

#ifdef GL_IMAGE_CLASS_4_X_16
    x = ev.image_class_4_x_16;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "IMAGE_CLASS_4_X_16") == 0);
#endif

#ifdef GL_IMAGE_CLASS_4_X_32
    x = ev.image_class_4_x_32;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "IMAGE_CLASS_4_X_32") == 0);
#endif

#ifdef GL_IMAGE_CLASS_4_X_8
    x = ev.image_class_4_x_8;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "IMAGE_CLASS_4_X_8") == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_image_compatibility_class_range) {
    using namespace oglplus;
    auto count = enum_value_range<image_compatibility_class>().size();

#ifdef GL_IMAGE_CLASS_10_10_10_2
    {
        --count;
        auto r = enum_value_range<image_compatibility_class>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            image_compatibility_class(GL_IMAGE_CLASS_10_10_10_2)) != r.end());
    }
#endif

#ifdef GL_IMAGE_CLASS_11_11_10
    {
        --count;
        auto r = enum_value_range<image_compatibility_class>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            image_compatibility_class(GL_IMAGE_CLASS_11_11_10)) != r.end());
    }
#endif

#ifdef GL_IMAGE_CLASS_1_X_16
    {
        --count;
        auto r = enum_value_range<image_compatibility_class>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            image_compatibility_class(GL_IMAGE_CLASS_1_X_16)) != r.end());
    }
#endif

#ifdef GL_IMAGE_CLASS_1_X_32
    {
        --count;
        auto r = enum_value_range<image_compatibility_class>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            image_compatibility_class(GL_IMAGE_CLASS_1_X_32)) != r.end());
    }
#endif

#ifdef GL_IMAGE_CLASS_1_X_8
    {
        --count;
        auto r = enum_value_range<image_compatibility_class>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            image_compatibility_class(GL_IMAGE_CLASS_1_X_8)) != r.end());
    }
#endif

#ifdef GL_IMAGE_CLASS_2_X_16
    {
        --count;
        auto r = enum_value_range<image_compatibility_class>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            image_compatibility_class(GL_IMAGE_CLASS_2_X_16)) != r.end());
    }
#endif

#ifdef GL_IMAGE_CLASS_2_X_32
    {
        --count;
        auto r = enum_value_range<image_compatibility_class>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            image_compatibility_class(GL_IMAGE_CLASS_2_X_32)) != r.end());
    }
#endif

#ifdef GL_IMAGE_CLASS_2_X_8
    {
        --count;
        auto r = enum_value_range<image_compatibility_class>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            image_compatibility_class(GL_IMAGE_CLASS_2_X_8)) != r.end());
    }
#endif

#ifdef GL_IMAGE_CLASS_4_X_16
    {
        --count;
        auto r = enum_value_range<image_compatibility_class>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            image_compatibility_class(GL_IMAGE_CLASS_4_X_16)) != r.end());
    }
#endif

#ifdef GL_IMAGE_CLASS_4_X_32
    {
        --count;
        auto r = enum_value_range<image_compatibility_class>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            image_compatibility_class(GL_IMAGE_CLASS_4_X_32)) != r.end());
    }
#endif

#ifdef GL_IMAGE_CLASS_4_X_8
    {
        --count;
        auto r = enum_value_range<image_compatibility_class>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            image_compatibility_class(GL_IMAGE_CLASS_4_X_8)) != r.end());
    }
#endif
    BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_image_compatibility_class_any) {
    using namespace oglplus;
    enum_values ev;
    EAGINE_MAYBE_UNUSED(ev);
    image_compatibility_class x, y;
    EAGINE_MAYBE_UNUSED(x);
    EAGINE_MAYBE_UNUSED(y);
    any_enum_value a;
    EAGINE_MAYBE_UNUSED(a);

#ifdef GL_IMAGE_CLASS_10_10_10_2
    x = ev.image_class_10_10_10_2;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.image_class_10_10_10_2);
#endif

#ifdef GL_IMAGE_CLASS_11_11_10
    x = ev.image_class_11_11_10;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.image_class_11_11_10);
#endif

#ifdef GL_IMAGE_CLASS_1_X_16
    x = ev.image_class_1_x_16;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.image_class_1_x_16);
#endif

#ifdef GL_IMAGE_CLASS_1_X_32
    x = ev.image_class_1_x_32;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.image_class_1_x_32);
#endif

#ifdef GL_IMAGE_CLASS_1_X_8
    x = ev.image_class_1_x_8;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.image_class_1_x_8);
#endif

#ifdef GL_IMAGE_CLASS_2_X_16
    x = ev.image_class_2_x_16;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.image_class_2_x_16);
#endif

#ifdef GL_IMAGE_CLASS_2_X_32
    x = ev.image_class_2_x_32;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.image_class_2_x_32);
#endif

#ifdef GL_IMAGE_CLASS_2_X_8
    x = ev.image_class_2_x_8;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.image_class_2_x_8);
#endif

#ifdef GL_IMAGE_CLASS_4_X_16
    x = ev.image_class_4_x_16;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.image_class_4_x_16);
#endif

#ifdef GL_IMAGE_CLASS_4_X_32
    x = ev.image_class_4_x_32;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.image_class_4_x_32);
#endif

#ifdef GL_IMAGE_CLASS_4_X_8
    x = ev.image_class_4_x_8;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.image_class_4_x_8);
#endif
}

BOOST_AUTO_TEST_SUITE_END()

#include "../../unit_test_end.inl"
