//  File test/boost_test/oglplus/enums/texture_compare_mode.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_texture_compare_mode

#include "../../unit_test_begin.inl"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_texture_compare_mode_tests)

BOOST_AUTO_TEST_CASE(enum_texture_compare_mode_values) {
    using namespace oglplus;
    enum_values ev;
    EAGINE_MAYBE_UNUSED(ev);
    texture_compare_mode x;
    EAGINE_MAYBE_UNUSED(x);

#ifdef GL_COMPARE_REF_TO_TEXTURE
    x = ev.compare_ref_to_texture;
    BOOST_CHECK(x == ev.compare_ref_to_texture);
#ifdef GL_NONE
    BOOST_CHECK(x != ev.none);
#endif
#endif

#ifdef GL_NONE
    x = ev.none;
    BOOST_CHECK(x == ev.none);
#endif
}

BOOST_AUTO_TEST_CASE(enum_texture_compare_mode_names) {
    using namespace oglplus;
    enum_values ev;
    EAGINE_MAYBE_UNUSED(ev);
    texture_compare_mode x;
    EAGINE_MAYBE_UNUSED(x);

#ifdef GL_COMPARE_REF_TO_TEXTURE
    x = ev.compare_ref_to_texture;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "COMPARE_REF_TO_TEXTURE") == 0);
#endif

#ifdef GL_NONE
    x = ev.none;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(std::strcmp(enum_value_name(x).data(), "NONE") == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_texture_compare_mode_range) {
    using namespace oglplus;
    auto count = enum_value_range<texture_compare_mode>().size();

#ifdef GL_COMPARE_REF_TO_TEXTURE
    {
	--count;
	auto r = enum_value_range<texture_compare_mode>();
	BOOST_CHECK(
	  std::find(
	    r.begin(), r.end(), texture_compare_mode(GL_COMPARE_REF_TO_TEXTURE))
	  != r.end());
    }
#endif

#ifdef GL_NONE
    {
	--count;
	auto r = enum_value_range<texture_compare_mode>();
	BOOST_CHECK(std::find(r.begin(), r.end(), texture_compare_mode(GL_NONE))
		    != r.end());
    }
#endif
    BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_texture_compare_mode_any) {
    using namespace oglplus;
    enum_values ev;
    EAGINE_MAYBE_UNUSED(ev);
    texture_compare_mode x, y;
    EAGINE_MAYBE_UNUSED(x);
    EAGINE_MAYBE_UNUSED(y);
    any_enum_value a;
    EAGINE_MAYBE_UNUSED(a);

#ifdef GL_COMPARE_REF_TO_TEXTURE
    x = ev.compare_ref_to_texture;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.compare_ref_to_texture);
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
