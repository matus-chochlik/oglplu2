//  File test/boost_test/eglplus/enums/vg_alpha_format.cpp
//
//  Automatically generated file, DO NOT modify manually.
//  Edit the enumeration source files in 'source/enums/eglplus'
//  or the 'source/enums/make_enum.py' script instead.
//
//  Copyright Matus Chochlik.
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//   http://www.boost.org/LICENSE_1_0.txt
//
#include "common.hpp"
#define BOOST_TEST_MODULE EGLPLUS_vg_alpha_format

#include <cstring>
#include "../../unit_test_begin.inl"

BOOST_AUTO_TEST_SUITE(enum_vg_alpha_format_tests)

BOOST_AUTO_TEST_CASE(enum_vg_alpha_format_values) {
    using namespace eglplus;
    enum_values ev;
    EAGINE_MAYBE_UNUSED(ev);
    vg_alpha_format x;
    EAGINE_MAYBE_UNUSED(x);

#ifdef EGL_VG_ALPHA_FORMAT_NONPRE
    x = ev.vg_alpha_format_nonpre;
    BOOST_CHECK(x == ev.vg_alpha_format_nonpre);
#ifdef EGL_VG_ALPHA_FORMAT_PRE
    BOOST_CHECK(x != ev.vg_alpha_format_pre);
#endif
#endif

#ifdef EGL_VG_ALPHA_FORMAT_PRE
    x = ev.vg_alpha_format_pre;
    BOOST_CHECK(x == ev.vg_alpha_format_pre);
#endif
}

BOOST_AUTO_TEST_CASE(enum_vg_alpha_format_names) {
    using namespace eglplus;
    enum_values ev;
    EAGINE_MAYBE_UNUSED(ev);
    vg_alpha_format x;
    EAGINE_MAYBE_UNUSED(x);

#ifdef EGL_VG_ALPHA_FORMAT_NONPRE
    x = ev.vg_alpha_format_nonpre;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "VG_ALPHA_FORMAT_NONPRE") == 0);
#endif

#ifdef EGL_VG_ALPHA_FORMAT_PRE
    x = ev.vg_alpha_format_pre;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "VG_ALPHA_FORMAT_PRE") == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_vg_alpha_format_range) {
    using namespace eglplus;
    auto count = enum_value_range<vg_alpha_format>().size();

#ifdef EGL_VG_ALPHA_FORMAT_NONPRE
    {
        --count;
        auto r = enum_value_range<vg_alpha_format>();
        BOOST_CHECK(
          std::find(
            r.begin(), r.end(), vg_alpha_format(EGL_VG_ALPHA_FORMAT_NONPRE)) !=
          r.end());
    }
#endif

#ifdef EGL_VG_ALPHA_FORMAT_PRE
    {
        --count;
        auto r = enum_value_range<vg_alpha_format>();
        BOOST_CHECK(
          std::find(
            r.begin(), r.end(), vg_alpha_format(EGL_VG_ALPHA_FORMAT_PRE)) !=
          r.end());
    }
#endif
    BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_vg_alpha_format_any) {
    using namespace eglplus;
    enum_values ev;
    EAGINE_MAYBE_UNUSED(ev);
    vg_alpha_format x, y;
    EAGINE_MAYBE_UNUSED(x);
    EAGINE_MAYBE_UNUSED(y);
    any_enum_value a;
    EAGINE_MAYBE_UNUSED(a);

#ifdef EGL_VG_ALPHA_FORMAT_NONPRE
    x = ev.vg_alpha_format_nonpre;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.vg_alpha_format_nonpre);
#endif

#ifdef EGL_VG_ALPHA_FORMAT_PRE
    x = ev.vg_alpha_format_pre;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.vg_alpha_format_pre);
#endif
}

BOOST_AUTO_TEST_SUITE_END()

#include "../../unit_test_end.inl"
