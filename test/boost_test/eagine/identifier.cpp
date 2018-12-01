/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/identifier.hpp>
#define BOOST_TEST_MODULE EAGINE_identifier
#include "../unit_test_begin.inl"

BOOST_AUTO_TEST_SUITE(identifier_tests)

static eagine::test_random_generator rg;

static void
test_gen_ident(char* str, eagine::span_size_t n) {

    for(eagine::span_size_t i = 0; i < n; ++i) {
        str[i] = rg.get_char_from(eagine::identifier::encoding::chars());
    }
    str[n] = '\0';
}

BOOST_AUTO_TEST_CASE(identifier_tag_1) {
    using namespace eagine;

    BOOST_CHECK_EQUAL(EAGINE_ID(A).str(), "A");
    BOOST_CHECK_EQUAL(EAGINE_ID(BC).str(), "BC");
    BOOST_CHECK_EQUAL(EAGINE_ID(CDE).str(), "CDE");
    BOOST_CHECK_EQUAL(EAGINE_ID(DEFG).str(), "DEFG");
    BOOST_CHECK_EQUAL(EAGINE_ID(EFGHI).str(), "EFGHI");
    BOOST_CHECK_EQUAL(EAGINE_ID(FGHIJK).str(), "FGHIJK");
    BOOST_CHECK_EQUAL(EAGINE_ID(GHIJKLM).str(), "GHIJKLM");
    BOOST_CHECK_EQUAL(EAGINE_ID(HIJKLMNO).str(), "HIJKLMNO");
    BOOST_CHECK_EQUAL(EAGINE_ID(IJKLMNOPQ).str(), "IJKLMNOPQ");
    BOOST_CHECK_EQUAL(EAGINE_ID(JKLMNOPQRS).str(), "JKLMNOPQRS");
}

BOOST_AUTO_TEST_CASE(identifier_1) {
    using eagine::span_size_t;
    using eagine::std_size;

    for(int k = 0; k < 1000; ++k) {
        const span_size_t l = eagine::identifier::max_size();
        char name[l + 1];

        const span_size_t n = rg.get_span_size(0, l - 1);
        test_gen_ident(name, n);

        const eagine::identifier id{name};
        const std::string s1(name, std_size(n));
        const std::string s2 = id.str();

        BOOST_CHECK_EQUAL(s1, s2);
    }
}

BOOST_AUTO_TEST_SUITE_END()

#include "../unit_test_end.inl"
