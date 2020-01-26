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

enum class test_enum { value_a, value_b, value_c, value_d, value_e, value_f };

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

    auto incr = [](auto& ctr) { ctr(); };

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

    auto chk_value = [&](const auto& ctr) {
        BOOST_CHECK_EQUAL(ctr.value(), n);
    };

    BOOST_CHECK(ccounters.visit(test_enum::value_a, chk_value));
    BOOST_CHECK(ccounters.visit(test_enum::value_b, chk_value));
    BOOST_CHECK(ccounters.visit(test_enum::value_c, chk_value));
    BOOST_CHECK(ccounters.visit(test_enum::value_d, chk_value));
    BOOST_CHECK(ccounters.visit(test_enum::value_e, chk_value));
    BOOST_CHECK(!ccounters.visit(test_enum::value_f, chk_value));
}

} // namespace eagine

BOOST_AUTO_TEST_SUITE(enum_map_tests)

BOOST_AUTO_TEST_CASE(enum_map_1) {
    using namespace eagine;

    enum_map_test_1(1000);
}

BOOST_AUTO_TEST_SUITE_END()

#include "../unit_test_end.inl"
