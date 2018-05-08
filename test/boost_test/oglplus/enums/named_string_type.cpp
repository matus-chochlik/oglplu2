//  File test/boost_test/oglplus/enums/named_string_type.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_named_string_type

#include "../../unit_test_begin.inl"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_named_string_type_tests)

BOOST_AUTO_TEST_CASE(enum_named_string_type_values) {
    using namespace oglplus;
    enum_values ev;
    EAGINE_MAYBE_UNUSED(ev);
    named_string_type x;
    EAGINE_MAYBE_UNUSED(x);

#ifdef GL_SHADER_INCLUDE_ARB
    x = ev.shader_include;
    BOOST_CHECK(x == ev.shader_include);
#endif
}

BOOST_AUTO_TEST_CASE(enum_named_string_type_names) {
    using namespace oglplus;
    enum_values ev;
    EAGINE_MAYBE_UNUSED(ev);
    named_string_type x;
    EAGINE_MAYBE_UNUSED(x);

#ifdef GL_SHADER_INCLUDE_ARB
    x = ev.shader_include;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "SHADER_INCLUDE_ARB") == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_named_string_type_range) {
    using namespace oglplus;
    auto count = enum_value_range<named_string_type>().size();

#ifdef GL_SHADER_INCLUDE_ARB
    {
	--count;
	auto r = enum_value_range<named_string_type>();
	BOOST_CHECK(
	  std::find(
	    r.begin(), r.end(), named_string_type(GL_SHADER_INCLUDE_ARB))
	  != r.end());
    }
#endif
    BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_named_string_type_any) {
    using namespace oglplus;
    enum_values ev;
    EAGINE_MAYBE_UNUSED(ev);
    named_string_type x, y;
    EAGINE_MAYBE_UNUSED(x);
    EAGINE_MAYBE_UNUSED(y);
    any_enum_value a;
    EAGINE_MAYBE_UNUSED(a);

#ifdef GL_SHADER_INCLUDE_ARB
    x = ev.shader_include;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.shader_include);
#endif
}

BOOST_AUTO_TEST_SUITE_END()

#include "../../unit_test_end.inl"
