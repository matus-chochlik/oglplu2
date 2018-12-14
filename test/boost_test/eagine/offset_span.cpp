/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/memory/offset_span.hpp>
#include <eagine/string_span.hpp>
#define BOOST_TEST_MODULE EAGINE_offset_span
#include "../unit_test_begin.inl"

#include <cstring>
#include <string>

BOOST_AUTO_TEST_SUITE(offset_span_tests)

BOOST_AUTO_TEST_CASE(offset_span_default_ctr) {
    using namespace eagine;

    memory::offset_span<long> a0;

    BOOST_CHECK(a0.data() == nullptr);
    BOOST_CHECK(a0.addr() == memory::const_address());
    BOOST_CHECK(a0.size() == 0);
    BOOST_CHECK(a0.begin() == a0.end());
}

BOOST_AUTO_TEST_CASE(offset_span_2) {
    using namespace eagine;

    double da[10] = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};

    memory::offset_span<double> ad(da, 10);

    BOOST_CHECK(ad.data() == da);
    BOOST_CHECK(ad.addr() == memory::const_address(da));
    BOOST_CHECK(ad.size() == 10);
    BOOST_CHECK(ad.begin() != ad.end());

    memory::offset_span<double>::size_type i = 0;
    for(double d : ad) {
        BOOST_CHECK_EQUAL(d, i);
        ++i;
    }

    for(i = 0; i < 10; ++i) {
        BOOST_CHECK_EQUAL(ad[i], i);
    }
}

BOOST_AUTO_TEST_CASE(offset_span_3) {
    using namespace eagine;

    const char* cstr = "FooBarBazBlah";

    memory::offset_span<const char> acc(cstr, span_size(std::strlen(cstr)));

    BOOST_CHECK(acc.data() == cstr);
    BOOST_CHECK(acc.addr() == memory::const_address(cstr));
    BOOST_CHECK(acc.size() == span_size(std::strlen(cstr)));
    BOOST_CHECK(acc.begin() != acc.end());

    memory::offset_span<double>::size_type i = 0;
    for(char c : acc) {
        BOOST_CHECK_EQUAL(c, cstr[i]);
        ++i;
    }

    for(i = 0; i < acc.size(); ++i) {
        BOOST_CHECK_EQUAL(acc[i], cstr[i]);
    }
}

BOOST_AUTO_TEST_CASE(offset_span_4) {
    using namespace eagine;

    int ia[20] = {
      1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

    const memory::offset_span<int> cai(ia, 20);

    BOOST_CHECK(cai.data() == ia);
    BOOST_CHECK(cai.addr() == memory::const_address(ia));
    BOOST_CHECK(cai.size() == 20);
    BOOST_CHECK(cai.begin() != cai.end());

    memory::offset_span<double>::size_type i = 0;
    for(int x : cai) {
        BOOST_CHECK_EQUAL(x, ++i);
    }

    for(i = 0; i < cai.size(); ++i) {
        BOOST_CHECK_EQUAL(cai[i], ia[i]);
    }
}

BOOST_AUTO_TEST_CASE(offset_span_5) {
    using namespace eagine;

    string_view str = "FooBarBazBlah";

    memory::offset_span<const char> acc(str);

    BOOST_CHECK(acc.data() == str.data());
    BOOST_CHECK(acc.addr() == memory::const_address(str.data()));
    BOOST_CHECK(acc.size() == str.size());
    BOOST_CHECK(acc.begin() != acc.end());

    memory::offset_span<const char>::size_type i = 0;
    for(char c : acc) {
        BOOST_CHECK_EQUAL(c, str[i]);
        ++i;
    }

    for(i = 0; i < acc.size(); ++i) {
        BOOST_CHECK_EQUAL(acc[i], str[i]);
    }
}

BOOST_AUTO_TEST_CASE(offset_span_6) {
    using namespace eagine;

    int ia[20] = {
      1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

    span<int> is = cover(ia);

    const memory::offset_span<int> cai(is);

    BOOST_CHECK(cai.data() == is.data());
    BOOST_CHECK(cai.addr() == memory::const_address(is.data()));
    BOOST_CHECK(cai.size() == 20);
    BOOST_CHECK(cai.begin() != cai.end());

    memory::offset_span<double>::size_type i = 0;
    for(int x : cai) {
        BOOST_CHECK_EQUAL(x, ++i);
    }

    for(i = 0; i < cai.size(); ++i) {
        BOOST_CHECK_EQUAL(cai[i], is[i]);
    }
}

// TODO
BOOST_AUTO_TEST_SUITE_END()

#include "../unit_test_end.inl"
