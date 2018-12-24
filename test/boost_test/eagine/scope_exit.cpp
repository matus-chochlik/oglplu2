/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/scope_exit.hpp>
#define BOOST_TEST_MODULE EAGINE_scope_exit
#include "../unit_test_begin.inl"

#include <exception>
#include <type_traits>

BOOST_AUTO_TEST_SUITE(scope_exit_tests)

BOOST_AUTO_TEST_CASE(scope_exit_f) {
    using namespace eagine;

    int i = 10, passed = 0;
    auto inc_i = [&i]() { ++i; };

    {
        BOOST_CHECK_EQUAL(i, 10);
        on_scope_exit<std::false_type> se(inc_i);
        BOOST_CHECK_EQUAL(i, 10);
        ++passed;
    }
    BOOST_CHECK_EQUAL(i, 11);
    {
        BOOST_CHECK_EQUAL(i, 11);
        on_scope_exit<std::false_type> se(inc_i);
        BOOST_CHECK_EQUAL(i, 11);
        ++passed;
        se.cancel();
    }
    try {
        BOOST_CHECK_EQUAL(i, 11);
        on_scope_exit<std::false_type> se(inc_i);
        BOOST_CHECK_EQUAL(i, 11);
        ++passed;

        throw std::exception();
    } catch(std::exception&) {
        BOOST_CHECK_EQUAL(i, 11);
        ++passed;
    }
    BOOST_CHECK_EQUAL(passed, 4);
}

BOOST_AUTO_TEST_CASE(scope_exit_t) {
    using namespace eagine;

    int i = 11, passed = 0;
    auto inc_i = [&i]() { ++i; };

    {
        BOOST_CHECK_EQUAL(i, 11);
        on_scope_exit<std::true_type> se(inc_i);
        BOOST_CHECK_EQUAL(i, 11);
        ++passed;
    }
    BOOST_CHECK_EQUAL(i, 11);
    try {
        BOOST_CHECK_EQUAL(i, 11);
        on_scope_exit<std::true_type> se(inc_i);
        BOOST_CHECK_EQUAL(i, 11);
        ++passed;

        throw std::exception();
    } catch(std::exception&) {
        BOOST_CHECK_EQUAL(i, 12);
        ++passed;
    }
    try {
        BOOST_CHECK_EQUAL(i, 12);
        on_scope_exit<std::true_type> se(inc_i);
        BOOST_CHECK_EQUAL(i, 12);
        ++passed;
        se.cancel();

        throw std::exception();
    } catch(std::exception&) {
        BOOST_CHECK_EQUAL(i, 12);
        ++passed;
    }

    BOOST_CHECK_EQUAL(passed, 5);
}

BOOST_AUTO_TEST_CASE(scope_exit_n) {
    using namespace eagine;

    int i = 41, passed = 0;
    auto inc_i = [&i]() { ++i; };

    {
        BOOST_CHECK_EQUAL(i, 41);
        on_scope_exit<nothing_t> se(inc_i);
        BOOST_CHECK_EQUAL(i, 41);
        ++passed;
    }
    BOOST_CHECK_EQUAL(i, 42);
    {
        BOOST_CHECK_EQUAL(i, 42);
        on_scope_exit<nothing_t> se(inc_i);
        BOOST_CHECK_EQUAL(i, 42);
        ++passed;
        se.cancel();
    }
    BOOST_CHECK_EQUAL(i, 42);
    try {
        BOOST_CHECK_EQUAL(i, 42);
        on_scope_exit<nothing_t> se(inc_i);
        BOOST_CHECK_EQUAL(i, 42);
        ++passed;

        throw std::exception();
    } catch(std::exception&) {
        BOOST_CHECK_EQUAL(i, 43);
        ++passed;
    }
    try {
        BOOST_CHECK_EQUAL(i, 43);
        on_scope_exit<nothing_t> se(inc_i);
        BOOST_CHECK_EQUAL(i, 43);
        ++passed;
        se.cancel();

        throw std::exception();
    } catch(std::exception&) {
        BOOST_CHECK_EQUAL(i, 43);
        ++passed;
    }

    BOOST_CHECK_EQUAL(passed, 6);
}

BOOST_AUTO_TEST_CASE(func_on_scope_exit) {
    using namespace eagine;

    int i = 41, passed = 0;

    {
        BOOST_CHECK_EQUAL(i, 41);
        auto fse = finally([&i]() { i += 2; });
        BOOST_CHECK_EQUAL(i, 41);
        ++passed;
    }
    BOOST_CHECK_EQUAL(i, 43);
    {
        BOOST_CHECK_EQUAL(i, 43);
        auto fse = finally([&i]() { i += 2; });
        BOOST_CHECK_EQUAL(i, 43);
        ++passed;
        fse.cancel();
    }
    BOOST_CHECK_EQUAL(i, 43);
    try {
        BOOST_CHECK_EQUAL(i, 43);
        auto fse = finally([&i]() { --i; });
        BOOST_CHECK_EQUAL(i, 43);
        ++passed;

        throw std::exception();
    } catch(std::exception&) {
        BOOST_CHECK_EQUAL(i, 42);
        ++passed;
    }
    try {
        BOOST_CHECK_EQUAL(i, 42);
        auto fse = finally([&i]() { --i; });
        BOOST_CHECK_EQUAL(i, 42);
        ++passed;
        fse.cancel();

        throw std::exception();
    } catch(std::exception&) {
        BOOST_CHECK_EQUAL(i, 42);
        ++passed;
    }

    BOOST_CHECK_EQUAL(passed, 6);
}

BOOST_AUTO_TEST_SUITE_END()

#include "../unit_test_end.inl"
