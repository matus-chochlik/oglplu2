//  File test/boost_test/oglplus/enums/framebuffer_parameter.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_framebuffer_parameter

#include "../../unit_test_begin.inl"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_framebuffer_parameter_tests)

BOOST_AUTO_TEST_CASE(enum_framebuffer_parameter_values) {
    using namespace oglplus;
    enum_values ev;
    EAGINE_MAYBE_UNUSED(ev);
    framebuffer_parameter x;
    EAGINE_MAYBE_UNUSED(x);

#ifdef GL_FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS
    x = ev.framebuffer_default_fixed_sample_locations;
    BOOST_CHECK(x == ev.framebuffer_default_fixed_sample_locations);
#ifdef GL_FRAMEBUFFER_DEFAULT_HEIGHT
    BOOST_CHECK(x != ev.framebuffer_default_height);
#endif
#ifdef GL_FRAMEBUFFER_DEFAULT_LAYERS
    BOOST_CHECK(x != ev.framebuffer_default_layers);
#endif
#ifdef GL_FRAMEBUFFER_DEFAULT_SAMPLES
    BOOST_CHECK(x != ev.framebuffer_default_samples);
#endif
#ifdef GL_FRAMEBUFFER_DEFAULT_WIDTH
    BOOST_CHECK(x != ev.framebuffer_default_width);
#endif
#endif

#ifdef GL_FRAMEBUFFER_DEFAULT_HEIGHT
    x = ev.framebuffer_default_height;
    BOOST_CHECK(x == ev.framebuffer_default_height);
#ifdef GL_FRAMEBUFFER_DEFAULT_LAYERS
    BOOST_CHECK(x != ev.framebuffer_default_layers);
#endif
#ifdef GL_FRAMEBUFFER_DEFAULT_SAMPLES
    BOOST_CHECK(x != ev.framebuffer_default_samples);
#endif
#ifdef GL_FRAMEBUFFER_DEFAULT_WIDTH
    BOOST_CHECK(x != ev.framebuffer_default_width);
#endif
#endif

#ifdef GL_FRAMEBUFFER_DEFAULT_LAYERS
    x = ev.framebuffer_default_layers;
    BOOST_CHECK(x == ev.framebuffer_default_layers);
#ifdef GL_FRAMEBUFFER_DEFAULT_SAMPLES
    BOOST_CHECK(x != ev.framebuffer_default_samples);
#endif
#ifdef GL_FRAMEBUFFER_DEFAULT_WIDTH
    BOOST_CHECK(x != ev.framebuffer_default_width);
#endif
#endif

#ifdef GL_FRAMEBUFFER_DEFAULT_SAMPLES
    x = ev.framebuffer_default_samples;
    BOOST_CHECK(x == ev.framebuffer_default_samples);
#ifdef GL_FRAMEBUFFER_DEFAULT_WIDTH
    BOOST_CHECK(x != ev.framebuffer_default_width);
#endif
#endif

#ifdef GL_FRAMEBUFFER_DEFAULT_WIDTH
    x = ev.framebuffer_default_width;
    BOOST_CHECK(x == ev.framebuffer_default_width);
#endif
}

BOOST_AUTO_TEST_CASE(enum_framebuffer_parameter_names) {
    using namespace oglplus;
    enum_values ev;
    EAGINE_MAYBE_UNUSED(ev);
    framebuffer_parameter x;
    EAGINE_MAYBE_UNUSED(x);

#ifdef GL_FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS
    x = ev.framebuffer_default_fixed_sample_locations;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(
        enum_value_name(x).data(),
        "FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS") == 0);
#endif

#ifdef GL_FRAMEBUFFER_DEFAULT_HEIGHT
    x = ev.framebuffer_default_height;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "FRAMEBUFFER_DEFAULT_HEIGHT") ==
      0);
#endif

#ifdef GL_FRAMEBUFFER_DEFAULT_LAYERS
    x = ev.framebuffer_default_layers;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "FRAMEBUFFER_DEFAULT_LAYERS") ==
      0);
#endif

#ifdef GL_FRAMEBUFFER_DEFAULT_SAMPLES
    x = ev.framebuffer_default_samples;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "FRAMEBUFFER_DEFAULT_SAMPLES") ==
      0);
#endif

#ifdef GL_FRAMEBUFFER_DEFAULT_WIDTH
    x = ev.framebuffer_default_width;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "FRAMEBUFFER_DEFAULT_WIDTH") == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_framebuffer_parameter_range) {
    using namespace oglplus;
    auto count = enum_value_range<framebuffer_parameter>().size();

#ifdef GL_FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS
    {
        --count;
        auto r = enum_value_range<framebuffer_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            framebuffer_parameter(
              GL_FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS)) != r.end());
    }
#endif

#ifdef GL_FRAMEBUFFER_DEFAULT_HEIGHT
    {
        --count;
        auto r = enum_value_range<framebuffer_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            framebuffer_parameter(GL_FRAMEBUFFER_DEFAULT_HEIGHT)) != r.end());
    }
#endif

#ifdef GL_FRAMEBUFFER_DEFAULT_LAYERS
    {
        --count;
        auto r = enum_value_range<framebuffer_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            framebuffer_parameter(GL_FRAMEBUFFER_DEFAULT_LAYERS)) != r.end());
    }
#endif

#ifdef GL_FRAMEBUFFER_DEFAULT_SAMPLES
    {
        --count;
        auto r = enum_value_range<framebuffer_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            framebuffer_parameter(GL_FRAMEBUFFER_DEFAULT_SAMPLES)) != r.end());
    }
#endif

#ifdef GL_FRAMEBUFFER_DEFAULT_WIDTH
    {
        --count;
        auto r = enum_value_range<framebuffer_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            framebuffer_parameter(GL_FRAMEBUFFER_DEFAULT_WIDTH)) != r.end());
    }
#endif
    BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_framebuffer_parameter_any) {
    using namespace oglplus;
    enum_values ev;
    EAGINE_MAYBE_UNUSED(ev);
    framebuffer_parameter x, y;
    EAGINE_MAYBE_UNUSED(x);
    EAGINE_MAYBE_UNUSED(y);
    any_enum_value a;
    EAGINE_MAYBE_UNUSED(a);

#ifdef GL_FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS
    x = ev.framebuffer_default_fixed_sample_locations;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.framebuffer_default_fixed_sample_locations);
#endif

#ifdef GL_FRAMEBUFFER_DEFAULT_HEIGHT
    x = ev.framebuffer_default_height;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.framebuffer_default_height);
#endif

#ifdef GL_FRAMEBUFFER_DEFAULT_LAYERS
    x = ev.framebuffer_default_layers;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.framebuffer_default_layers);
#endif

#ifdef GL_FRAMEBUFFER_DEFAULT_SAMPLES
    x = ev.framebuffer_default_samples;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.framebuffer_default_samples);
#endif

#ifdef GL_FRAMEBUFFER_DEFAULT_WIDTH
    x = ev.framebuffer_default_width;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.framebuffer_default_width);
#endif
}

BOOST_AUTO_TEST_SUITE_END()

#include "../../unit_test_end.inl"
