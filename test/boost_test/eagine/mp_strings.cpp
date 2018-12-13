/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/mp_strings.hpp>
#define BOOST_TEST_MODULE EAGINE_mp_strings_test
#include "../unit_test_begin.inl"

#include <cstring>

BOOST_AUTO_TEST_SUITE(mp_strings_tests)

BOOST_AUTO_TEST_CASE(mp_strings_subscript) {
    using namespace eagine;

    using d = mp_int_to_string_t<-1234567890>;
    using s = mp_translate_t<d, mp_subscript>;

    BOOST_CHECK(std::strcmp(s::value, "₋₁₂₃₄₅₆₇₈₉₀") == 0);
}

BOOST_AUTO_TEST_CASE(mp_strings_superscript) {
    using namespace eagine;

    using d = mp_int_to_string_t<-1234567890>;
    using x =
      mp_concat_t<mp_string<'n', '1', '=', '('>, d, mp_string<')', '+', 'i'>>;
    using s = mp_translate_t<x, mp_superscript>;

    BOOST_CHECK(std::strcmp(s::value, "ⁿ¹⁼⁽⁻¹²³⁴⁵⁶⁷⁸⁹⁰⁾⁺ⁱ") == 0);
}

// TODO

BOOST_AUTO_TEST_SUITE_END()

#include "../unit_test_end.inl"
