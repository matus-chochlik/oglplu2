/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/iterator.hpp>
#define BOOST_TEST_MODULE EAGINE_iterator
#include "../unit_test_begin.inl"

#include <functional>
#include <string>

using int_iterator = eagine::selfref_iterator<int>;

using strint_iterator = eagine::transforming_iterator<
  int_iterator,
  std::string,
  std::string,
  std::function<std::string(int)>>;

BOOST_AUTO_TEST_SUITE(iterator_tests)

static eagine::test_random_generator rg;

BOOST_AUTO_TEST_CASE(iterator_1) {
    const int bi = rg.get_int(0, 9);
    const int ei = bi + 1 + rg.get_int(0, 9);
    int ii = bi;

    const int_iterator b{bi};
    const int_iterator e{ei};
    int_iterator i = b;

    BOOST_CHECK(b == i);
    BOOST_CHECK(e != i);

    while(i < e) {
        BOOST_CHECK(b <= i);

        BOOST_CHECK_EQUAL(i - b, ii - bi);
        BOOST_CHECK_EQUAL(e - i, ei - ii);

        BOOST_CHECK(int_iterator(ii++) == i++);

        BOOST_CHECK_EQUAL(i - b, ii - bi);
        BOOST_CHECK_EQUAL(e - i, ei - ii);

        BOOST_CHECK(e >= i);
    }

    BOOST_CHECK(b != i);
    BOOST_CHECK(e == i);

    while(i > b) {
        BOOST_CHECK(e >= i);

        BOOST_CHECK_EQUAL(i - b, ii - bi);
        BOOST_CHECK_EQUAL(e - i, ei - ii);

        BOOST_CHECK(int_iterator(ii--) == i--);

        BOOST_CHECK_EQUAL(i - b, ii - bi);
        BOOST_CHECK_EQUAL(e - i, ei - ii);

        BOOST_CHECK(i >= b);
    }

    BOOST_CHECK(b == i);
    BOOST_CHECK(e != i);

    while(i < e) {
        BOOST_CHECK(++ii == *(++i));
    }

    BOOST_CHECK(b != i);
    BOOST_CHECK(e == i);

    while(b < i) {
        BOOST_CHECK(--ii == *(--i));
    }
}

BOOST_AUTO_TEST_CASE(iterator_2) {
    const int bi = rg.get_int(0, 1000);
    const int ei = bi + 1 + rg.get_int(0, 1000);
    int ii = bi;
    std::function<std::string(int)> test_transform(
      static_cast<std::string (*)(int)>(&std::to_string));

    const strint_iterator b(bi, test_transform);
    const strint_iterator e(ei, test_transform);
    strint_iterator i = b;

    BOOST_CHECK(b == i);
    BOOST_CHECK(e != i);

    while(i < e) {
        BOOST_CHECK(b <= i);

        BOOST_CHECK_EQUAL(i - b, ii - bi);
        BOOST_CHECK_EQUAL(e - i, ei - ii);

        BOOST_CHECK(int_iterator(ii++) == i++);

        BOOST_CHECK_EQUAL(i - b, ii - bi);
        BOOST_CHECK_EQUAL(e - i, ei - ii);

        BOOST_CHECK(e >= i);
    }

    BOOST_CHECK(b != i);
    BOOST_CHECK(e == i);

    while(i > b) {
        BOOST_CHECK(e >= i);

        BOOST_CHECK_EQUAL(i - b, ii - bi);
        BOOST_CHECK_EQUAL(e - i, ei - ii);

        BOOST_CHECK(int_iterator(ii--) == i--);

        BOOST_CHECK_EQUAL(i - b, ii - bi);
        BOOST_CHECK_EQUAL(e - i, ei - ii);

        BOOST_CHECK(b <= i);
    }

    BOOST_CHECK(b == i);
    BOOST_CHECK(e != i);

    while(i < e) {
        BOOST_CHECK(std::to_string(++ii) == *(++i));
    }

    BOOST_CHECK(b != i);
    BOOST_CHECK(e == i);

    while(b < i) {
        BOOST_CHECK(std::to_string(--ii) == *(--i));
    }
}

BOOST_AUTO_TEST_SUITE_END()

#include "../unit_test_end.inl"
