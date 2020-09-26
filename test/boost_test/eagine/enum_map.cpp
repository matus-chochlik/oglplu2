/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/enum_map.hpp>
#define BOOST_TEST_MODULE EAGINE_enum_map
#include "../unit_test_begin.inl"

#include <eagine/count.hpp>

namespace eagine {

enum class test_enum {
    value_a = 1 << 0,
    value_b = 1 << 1,
    value_c = 1 << 2,
    value_d = 1 << 3,
    value_e = 1 << 4,
    value_f = 1 << 5
};

using test_bits = bitfield<test_enum>;

static inline test_bits operator|(test_enum a, test_enum b) noexcept {
    return {a, b};
}

template <test_enum>
using test_enum_map_counter = count_t<std::size_t>;

static inline void enum_map_test_1(std::size_t n) {
    static_enum_map<
      test_enum,
      test_enum_map_counter,
      test_enum::value_a,
      test_enum::value_b,
      test_enum::value_c,
      test_enum::value_d,
      test_enum::value_e>
      counters;

    auto incr = [](auto, auto& ctr) {
        ctr();
    };

    for(std::size_t i = 0; i < n; ++i) {
        BOOST_CHECK(counters.visit(test_enum::value_d, incr));
        BOOST_CHECK(counters.visit(test_enum::value_a, incr));
        BOOST_CHECK(counters.visit(test_enum::value_c, incr));
        BOOST_CHECK(counters.visit(test_enum::value_e, incr));
        BOOST_CHECK(counters.visit(test_enum::value_b, incr));
        BOOST_CHECK(!counters.visit(test_enum::value_f, incr));
    }

    const auto& ccounters = counters;

    BOOST_CHECK_EQUAL(ccounters.get<test_enum::value_a>().value(), n);
    BOOST_CHECK_EQUAL(ccounters.get<test_enum::value_b>().value(), n);
    BOOST_CHECK_EQUAL(ccounters.get<test_enum::value_c>().value(), n);
    BOOST_CHECK_EQUAL(ccounters.get<test_enum::value_d>().value(), n);
    BOOST_CHECK_EQUAL(ccounters.get<test_enum::value_e>().value(), n);
}

static inline void enum_map_test_2(std::size_t n) {
    static_enum_map<
      test_enum,
      test_enum_map_counter,
      test_enum::value_a,
      test_enum::value_b,
      test_enum::value_c,
      test_enum::value_d,
      test_enum::value_e>
      counters;

    for(std::size_t i = 0; i < n; ++i) {
        counters.get<test_enum::value_a>()();
        counters.get<test_enum::value_b>()();
        counters.get<test_enum::value_c>()();
        counters.get<test_enum::value_d>()();
        counters.get<test_enum::value_e>()();
    }

    const auto& ccounters = counters;

    auto chk_value = [&](auto, const auto& ctr) {
        BOOST_CHECK_EQUAL(ctr.value(), n);
    };

    BOOST_CHECK(ccounters.visit(test_enum::value_a, chk_value));
    BOOST_CHECK(ccounters.visit(test_enum::value_b, chk_value));
    BOOST_CHECK(ccounters.visit(test_enum::value_c, chk_value));
    BOOST_CHECK(ccounters.visit(test_enum::value_d, chk_value));
    BOOST_CHECK(ccounters.visit(test_enum::value_e, chk_value));
    BOOST_CHECK(!ccounters.visit(test_enum::value_f, chk_value));
}

static inline void enum_map_test_3(std::size_t n) {
    static_enum_map<
      test_enum,
      test_enum_map_counter,
      test_enum::value_a,
      test_enum::value_b,
      test_enum::value_c,
      test_enum::value_d,
      test_enum::value_e>
      counters;

    auto incr = [](auto, auto& ctr) {
        ctr();
    };

    for(std::size_t i = 0; i < n; ++i) {
        BOOST_CHECK(counters.visit(test_enum::value_a, incr));
    }

    for(std::size_t i = 0; i < n; ++i) {
        BOOST_CHECK(
          counters.visit(test_enum::value_a | test_enum::value_b, incr));
    }

    for(std::size_t i = 0; i < n; ++i) {
        BOOST_CHECK(counters.visit(
          test_enum::value_a | test_enum::value_b | test_enum::value_c, incr));
    }

    for(std::size_t i = 0; i < n; ++i) {
        BOOST_CHECK(counters.visit(
          test_enum::value_a | test_enum::value_b | test_enum::value_c |
            test_enum::value_d,
          incr));
    }

    for(std::size_t i = 0; i < n; ++i) {
        BOOST_CHECK(counters.visit(
          test_enum::value_a | test_enum::value_b | test_enum::value_c |
            test_enum::value_d | test_enum::value_e,
          incr));
    }

    const auto& ccounters = counters;

    BOOST_CHECK_EQUAL(ccounters.get<test_enum::value_a>().value(), n * 5);
    BOOST_CHECK_EQUAL(ccounters.get<test_enum::value_b>().value(), n * 4);
    BOOST_CHECK_EQUAL(ccounters.get<test_enum::value_c>().value(), n * 3);
    BOOST_CHECK_EQUAL(ccounters.get<test_enum::value_d>().value(), n * 2);
    BOOST_CHECK_EQUAL(ccounters.get<test_enum::value_e>().value(), n * 1);
}

template <test_enum>
using test_enum_map_value_counter = std::tuple<test_enum, std::size_t>;

static inline void enum_map_test_4(std::size_t n) {
    static_enum_map<
      test_enum,
      test_enum_map_value_counter,
      test_enum::value_a,
      test_enum::value_b,
      test_enum::value_c,
      test_enum::value_d,
      test_enum::value_e>
      counters;

    auto init = [](auto val, auto& tup) {
        std::get<0>(tup) = val;
        std::get<1>(tup) = 1;
    };

    BOOST_CHECK(counters.visit_all(init));

    auto incr = [](auto, auto& tup) {
        std::get<1>(tup)++;
    };

    for(std::size_t i = 0; i < n; ++i) {
        BOOST_CHECK(counters.visit(test_enum::value_d, incr));
        BOOST_CHECK(counters.visit(test_enum::value_a, incr));
        BOOST_CHECK(counters.visit(test_enum::value_c, incr));
        BOOST_CHECK(counters.visit(test_enum::value_e, incr));
        BOOST_CHECK(counters.visit(test_enum::value_b, incr));
        BOOST_CHECK(!counters.visit(test_enum::value_f, incr));
    }

    const auto& ccounters = counters;

    BOOST_CHECK(
      std::get<0>(ccounters.get<test_enum::value_a>()) == test_enum::value_a);
    BOOST_CHECK(
      std::get<0>(ccounters.get<test_enum::value_b>()) == test_enum::value_b);
    BOOST_CHECK(
      std::get<0>(ccounters.get<test_enum::value_c>()) == test_enum::value_c);
    BOOST_CHECK(
      std::get<0>(ccounters.get<test_enum::value_d>()) == test_enum::value_d);
    BOOST_CHECK(
      std::get<0>(ccounters.get<test_enum::value_e>()) == test_enum::value_e);

    auto chk_tuple = [&](auto value, const auto& tup) {
        BOOST_CHECK(std::get<0>(tup) == value);
        BOOST_CHECK(std::get<1>(tup) == n + 1);
    };

    BOOST_CHECK(ccounters.visit(test_enum::value_a, chk_tuple));
    BOOST_CHECK(ccounters.visit(test_enum::value_b, chk_tuple));
    BOOST_CHECK(ccounters.visit(test_enum::value_c, chk_tuple));
    BOOST_CHECK(ccounters.visit(test_enum::value_d, chk_tuple));
    BOOST_CHECK(ccounters.visit(test_enum::value_e, chk_tuple));
    BOOST_CHECK(!ccounters.visit(test_enum::value_f, chk_tuple));
}

} // namespace eagine

BOOST_AUTO_TEST_SUITE(enum_map_tests)

BOOST_AUTO_TEST_CASE(enum_map_1) {
    using namespace eagine;

    enum_map_test_1(1000);
}

BOOST_AUTO_TEST_CASE(enum_map_2) {
    using namespace eagine;

    enum_map_test_2(1000);
}

BOOST_AUTO_TEST_CASE(enum_map_3) {
    using namespace eagine;

    enum_map_test_3(1000);
}

BOOST_AUTO_TEST_CASE(enum_map_4) {
    using namespace eagine;

    enum_map_test_4(1000);
}

BOOST_AUTO_TEST_SUITE_END()

#include "../unit_test_end.inl"
