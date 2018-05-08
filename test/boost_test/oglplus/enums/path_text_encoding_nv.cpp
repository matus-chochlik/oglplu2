//  File test/boost_test/oglplus/enums/path_text_encoding_nv.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_path_text_encoding_nv

#include "../../unit_test_begin.inl"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_path_text_encoding_nv_tests)

BOOST_AUTO_TEST_CASE(enum_path_text_encoding_nv_values) {
    using namespace oglplus;
    enum_values ev;
    EAGINE_MAYBE_UNUSED(ev);
    path_text_encoding_nv x;
    EAGINE_MAYBE_UNUSED(x);

#ifdef GL_UTF16_NV
    x = ev.utf16_nv;
    BOOST_CHECK(x == ev.utf16_nv);
#ifdef GL_UTF8_NV
    BOOST_CHECK(x != ev.utf8_nv);
#endif
#endif

#ifdef GL_UTF8_NV
    x = ev.utf8_nv;
    BOOST_CHECK(x == ev.utf8_nv);
#endif
}

BOOST_AUTO_TEST_CASE(enum_path_text_encoding_nv_names) {
    using namespace oglplus;
    enum_values ev;
    EAGINE_MAYBE_UNUSED(ev);
    path_text_encoding_nv x;
    EAGINE_MAYBE_UNUSED(x);

#ifdef GL_UTF16_NV
    x = ev.utf16_nv;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(std::strcmp(enum_value_name(x).data(), "UTF16_NV") == 0);
#endif

#ifdef GL_UTF8_NV
    x = ev.utf8_nv;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(std::strcmp(enum_value_name(x).data(), "UTF8_NV") == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_path_text_encoding_nv_range) {
    using namespace oglplus;
    auto count = enum_value_range<path_text_encoding_nv>().size();

#ifdef GL_UTF16_NV
    {
	--count;
	auto r = enum_value_range<path_text_encoding_nv>();
	BOOST_CHECK(
	  std::find(r.begin(), r.end(), path_text_encoding_nv(GL_UTF16_NV))
	  != r.end());
    }
#endif

#ifdef GL_UTF8_NV
    {
	--count;
	auto r = enum_value_range<path_text_encoding_nv>();
	BOOST_CHECK(
	  std::find(r.begin(), r.end(), path_text_encoding_nv(GL_UTF8_NV))
	  != r.end());
    }
#endif
    BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_path_text_encoding_nv_any) {
    using namespace oglplus;
    enum_values ev;
    EAGINE_MAYBE_UNUSED(ev);
    path_text_encoding_nv x, y;
    EAGINE_MAYBE_UNUSED(x);
    EAGINE_MAYBE_UNUSED(y);
    any_enum_value a;
    EAGINE_MAYBE_UNUSED(a);

#ifdef GL_UTF16_NV
    x = ev.utf16_nv;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.utf16_nv);
#endif

#ifdef GL_UTF8_NV
    x = ev.utf8_nv;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.utf8_nv);
#endif
}

BOOST_AUTO_TEST_SUITE_END()

#include "../../unit_test_end.inl"
