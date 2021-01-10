/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/overloaded.hpp>
#define BOOST_TEST_MODULE EAGINE_overloaded
#include "../unit_test_begin.inl"

#include <cstring>

BOOST_AUTO_TEST_SUITE(overloaded_tests)

BOOST_AUTO_TEST_CASE(overloaded_foo_1) {
    using namespace eagine;

    auto func = overloaded(
      [](int) { return "int"; },
      [](float) { return "float"; },
      [](double) { return "double"; },
      [](auto) { return "other"; });

    BOOST_CHECK_EQUAL(std::strcmp(func(100), "int"), 0);
    BOOST_CHECK_EQUAL(std::strcmp(func(2.f), "float"), 0);
    BOOST_CHECK_EQUAL(std::strcmp(func(3.0), "double"), 0);
    BOOST_CHECK_EQUAL(std::strcmp(func("x"), "other"), 0);
}

BOOST_AUTO_TEST_SUITE_END()

#include "../unit_test_end.inl"
