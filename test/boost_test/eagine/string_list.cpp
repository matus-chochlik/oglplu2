/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/string_list.hpp>
#define BOOST_TEST_MODULE EAGINE_string_list
#include "../unit_test_begin.inl"

#include <string>

BOOST_AUTO_TEST_SUITE(string_list_tests)

static eagine::test_random_generator rg;

BOOST_AUTO_TEST_CASE(string_list_elem_0) {
    using namespace eagine;

    const char s0[2] = {0x00, 0x00};
    string_list::element e0(s0, 2);

    BOOST_CHECK_EQUAL(e0.size(), 2);
    BOOST_CHECK_EQUAL(e0.header_size(), 1);
    BOOST_CHECK_EQUAL(e0.footer_size(), 1);
    BOOST_CHECK_EQUAL(e0.value_size(), 0);
}

BOOST_AUTO_TEST_CASE(string_list_elem_1) {
    using namespace eagine;

    const char s1[3] = {0x01, 'A', 0x01};
    string_list::element e1(s1, 3);

    BOOST_CHECK_EQUAL(e1.size(), 3);
    BOOST_CHECK_EQUAL(e1.header_size(), 1);
    BOOST_CHECK_EQUAL(e1.footer_size(), 1);
    BOOST_CHECK_EQUAL(e1.value_size(), 1);
    BOOST_CHECK(e1.value() == cstring_span("A"));
}

BOOST_AUTO_TEST_CASE(string_list_elem_2) {
    using namespace eagine;

    const char s2[18] = {0x10,
                         'A',
                         'B',
                         'C',
                         'D',
                         'E',
                         'F',
                         'G',
                         'H',
                         'I',
                         'J',
                         'K',
                         'L',
                         'M',
                         'N',
                         'O',
                         'P',
                         0x10};
    string_list::element e2(s2, 18);

    BOOST_CHECK_EQUAL(e2.size(), 18);
    BOOST_CHECK_EQUAL(e2.header_size(), 1);
    BOOST_CHECK_EQUAL(e2.footer_size(), 1);
    BOOST_CHECK_EQUAL(e2.value_size(), 16);
    BOOST_CHECK(e2.value() == cstring_span("ABCDEFGHIJKLMNOP"));
}

BOOST_AUTO_TEST_CASE(string_list_elem_3) {
    using namespace eagine;

    const char s3[132] = {
      char(0xC2), char(0x80), 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x',
      'x',        'x',        'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x',
      'x',        'x',        'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x',
      'x',        'x',        'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x',
      'x',        'x',        'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x',
      'x',        'x',        'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x',
      'x',        'x',        'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x',
      'x',        'x',        'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x',
      'x',        'x',        'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x',
      'x',        'x',        'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x',
      'x',        'x',        'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x',
      'x',        'x',        'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x',
      'x',        'x',        'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x',
      char(0xC2), char(0x80)};
    string_list::element e3(s3, 132);

    BOOST_CHECK_EQUAL(e3.size(), 132);
    BOOST_CHECK_EQUAL(e3.header_size(), 2);
    BOOST_CHECK_EQUAL(e3.footer_size(), 2);
    BOOST_CHECK_EQUAL(e3.value_size(), 128);

    std::string ss3(128, 'x');
    BOOST_CHECK(e3.value() == cstring_span(ss3));
}

BOOST_AUTO_TEST_CASE(string_list_for_each_elem_1) {
    using namespace eagine;

    const char s1[25] = {0x01, 'A', 0x01, 0x02, 'b', 'C', 0x02, 0x03, 'D',
                         'e',  'F', 0x03, 0x04, 'g', 'H', 'i',  'J',  0x04,
                         0x05, 'K', 'l',  'M',  'n', 'O', 0x05};
    const cstring_span ss1(s1, 25);

    int i = 1;
    string_list::for_each_elem(ss1, [&i](string_list::element e, bool first) {
        BOOST_CHECK_EQUAL(first, i == 1);
        BOOST_CHECK_EQUAL(e.value_size(), i++);
    });

    std::string ts;
    string_list::for_each_elem(ss1, [&ts](string_list::element e, bool) {
        ts.append(e.value().data(), std_size(e.value().size()));
    });
    BOOST_CHECK_EQUAL(ts, "AbCDeFgHiJKlMnO");
}

BOOST_AUTO_TEST_CASE(string_list_rev_for_each_elem_1) {
    using namespace eagine;

    const char s1[25] = {0x01, 'A', 0x01, 0x02, 'b', 'C', 0x02, 0x03, 'D',
                         'e',  'F', 0x03, 0x04, 'g', 'H', 'i',  'J',  0x04,
                         0x05, 'K', 'l',  'M',  'n', 'O', 0x05};
    const cstring_span ss1(s1, 25);

    int i = 5;
    string_list::rev_for_each_elem(
      ss1, [&i](string_list::element e, bool first) {
          BOOST_CHECK_EQUAL(first, i == 5);
          BOOST_CHECK_EQUAL(e.value_size(), i--);
      });

    std::string ts;
    string_list::rev_for_each_elem(ss1, [&ts](string_list::element e, bool) {
        ts.append(e.value().data(), std_size(e.value().size()));
    });
    BOOST_CHECK_EQUAL(ts, "KlMnOgHiJDeFbCA");
}

BOOST_AUTO_TEST_CASE(string_list_for_each_1) {
    using namespace eagine;

    const char s1[25] = {0x01, 'a', 0x01, 0x02, 'B', 'c', 0x02, 0x03, 'd',
                         'E',  'f', 0x03, 0x04, 'G', 'h', 'I',  'j',  0x04,
                         0x05, 'k', 'L',  'm',  'N', 'o', 0x05};
    const cstring_span ss1(s1, 25);

    int i = 1;
    string_list::for_each(
      ss1, [&i](cstring_span s) { BOOST_CHECK_EQUAL(s.size(), i++); });

    std::string ts;
    string_list::for_each(
      ss1, [&ts](cstring_span s) { ts.append(s.data(), std_size(s.size())); });
    BOOST_CHECK_EQUAL(ts, "aBcdEfGhIjkLmNo");
}

BOOST_AUTO_TEST_CASE(string_list_rev_for_each_1) {
    using namespace eagine;

    const char s1[25] = {0x01, 'a', 0x01, 0x02, 'B', 'c', 0x02, 0x03, 'd',
                         'E',  'f', 0x03, 0x04, 'G', 'h', 'I',  'j',  0x04,
                         0x05, 'k', 'L',  'm',  'N', 'o', 0x05};
    const cstring_span ss1(s1, 25);

    int i = 5;
    string_list::rev_for_each(
      ss1, [&i](cstring_span s) { BOOST_CHECK_EQUAL(s.size(), i--); });

    std::string ts;
    string_list::rev_for_each(
      ss1, [&ts](cstring_span s) { ts.append(s.data(), std_size(s.size())); });
    BOOST_CHECK_EQUAL(ts, "kLmNoGhIjdEfBca");
}

BOOST_AUTO_TEST_CASE(string_list_join_1) {
    using namespace eagine;

    const char s1[25] = {0x01, 'A', 0x01, 0x02, 'B', 'C', 0x02, 0x03, 'D',
                         'E',  'F', 0x03, 0x04, 'G', 'H', 'I',  'J',  0x04,
                         0x05, 'K', 'L',  'M',  'N', 'O', 0x05};
    const cstring_span ss1(s1, 25);
    const cstring_span sep("");

    BOOST_CHECK_EQUAL(string_list::join(ss1, sep), "ABCDEFGHIJKLMNO");
}

BOOST_AUTO_TEST_CASE(string_list_join_2) {
    using namespace eagine;

    const char s1[25] = {0x01, 'A', 0x01, 0x02, 'B', 'C', 0x02, 0x03, 'D',
                         'E',  'F', 0x03, 0x04, 'G', 'H', 'I',  'J',  0x04,
                         0x05, 'K', 'L',  'M',  'N', 'O', 0x05};
    const cstring_span ss1(s1, 25);
    const cstring_span sep("/");

    BOOST_CHECK_EQUAL(
      string_list::join(ss1, sep, true), "A/BC/DEF/GHIJ/KLMNO/");
}

BOOST_AUTO_TEST_CASE(string_list_join_3) {
    using namespace eagine;

    const char s1[25] = {0x01, 'A', 0x01, 0x02, 'B', 'C', 0x02, 0x03, 'D',
                         'E',  'F', 0x03, 0x04, 'G', 'H', 'I',  'J',  0x04,
                         0x05, 'K', 'L',  'M',  'N', 'O', 0x05};
    const cstring_span ss1(s1, 25);
    const cstring_span sep("...");

    BOOST_CHECK_EQUAL(
      string_list::join(ss1, sep, false), "A...BC...DEF...GHIJ...KLMNO");
}

BOOST_AUTO_TEST_SUITE_END()

#include "../unit_test_end.inl"
