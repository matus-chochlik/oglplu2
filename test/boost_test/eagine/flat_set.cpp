/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/flat_set.hpp>
#define BOOST_TEST_MODULE EAGINE_flat_set
#include "../unit_test_begin.inl"

#include <functional>
#include <set>

BOOST_AUTO_TEST_SUITE(flat_set_tests)

static eagine::test_random_generator rg;

BOOST_AUTO_TEST_CASE(flat_set_1) {
    using namespace eagine;

    std::set<int> ss;
    std::vector<int> d;

    for(int i = 0; i < test_repeats(1000, 10000); ++i) {
        int k = rg.get_any<int>();
        ss.insert(k);
        d.push_back(k);
    }

    flat_set<int> fs(d);

    BOOST_CHECK_EQUAL(ss.empty(), fs.empty());
    BOOST_CHECK_EQUAL(ss.size(), fs.size());

    auto ssi = ss.begin();
    auto fsi = fs.begin();

    while((ssi != ss.end()) && (fsi != fs.end())) {
        BOOST_CHECK_EQUAL(*ssi, *fsi);
        ++ssi;
        ++fsi;
    }

    BOOST_CHECK(ssi == ss.end());
    BOOST_CHECK(fsi == fs.end());
}

BOOST_AUTO_TEST_CASE(flat_set_2) {
    using namespace eagine;

    std::set<int> ss;
    flat_set<int> fs;

    for(int i = 0; i < test_repeats(1000, 10000); ++i) {
        int k = rg.get_any<int>();
        ss.insert(k);
        fs.insert(k);
    }

    BOOST_CHECK_EQUAL(ss.empty(), fs.empty());
    BOOST_CHECK_EQUAL(ss.size(), fs.size());

    auto ssi = ss.begin();
    auto fsi = fs.begin();

    while((ssi != ss.end()) && (fsi != fs.end())) {
        BOOST_CHECK_EQUAL(*ssi, *fsi);
        ++ssi;
        ++fsi;
    }

    BOOST_CHECK(ssi == ss.end());
    BOOST_CHECK(fsi == fs.end());
}

BOOST_AUTO_TEST_CASE(flat_set_3) {
    using namespace eagine;

    std::set<int> ss;
    flat_set<int> fs;

    for(int i = 0; i < test_repeats(1000, 10000); ++i) {
        int k = rg.get_any<int>();

        ss.insert(ss.begin(), k);
        fs.insert(fs.begin(), k);
    }

    BOOST_CHECK_EQUAL(ss.empty(), fs.empty());
    BOOST_CHECK_EQUAL(ss.size(), fs.size());

    auto ssi = ss.begin();
    auto fsi = fs.begin();

    while((ssi != ss.end()) && (fsi != fs.end())) {
        BOOST_CHECK_EQUAL(*ssi, *fsi);
        ++ssi;
        ++fsi;
    }

    BOOST_CHECK(ssi == ss.end());
    BOOST_CHECK(fsi == fs.end());
}

BOOST_AUTO_TEST_CASE(flat_set_4) {
    using namespace eagine;

    std::set<int> ss;
    flat_set<int> fs;

    for(int i = 0; i < test_repeats(1000, 10000); ++i) {
        int k = rg.get_any<int>();

        ss.insert(ss.end(), k);
        fs.insert(fs.end(), k);
    }

    BOOST_CHECK_EQUAL(ss.empty(), fs.empty());
    BOOST_CHECK_EQUAL(ss.size(), fs.size());

    auto ssi = ss.begin();
    auto fsi = fs.begin();

    while((ssi != ss.end()) && (fsi != fs.end())) {
        BOOST_CHECK_EQUAL(*ssi, *fsi);
        ++ssi;
        ++fsi;
    }

    BOOST_CHECK(ssi == ss.end());
    BOOST_CHECK(fsi == fs.end());
}

BOOST_AUTO_TEST_CASE(flat_set_5) {
    using namespace eagine;

    std::set<int> ss;
    flat_set<int> fs;

    for(int i = 0; i < test_repeats(1000, 10000); ++i) {
        int k = rg.get_any<int>();

        ss.insert(ss.lower_bound(k), k);
        fs.insert(fs.lower_bound(k), k);
    }

    BOOST_CHECK_EQUAL(ss.empty(), fs.empty());
    BOOST_CHECK_EQUAL(ss.size(), fs.size());

    std::set<int>::iterator ssi = ss.begin();
    flat_set<int>::iterator fsi = fs.begin();

    while((ssi != ss.end()) && (fsi != fs.end())) {
        BOOST_CHECK_EQUAL(*ssi, *fsi);
        ++ssi;
        ++fsi;
    }

    BOOST_CHECK(ssi == ss.end());
    BOOST_CHECK(fsi == fs.end());
}

BOOST_AUTO_TEST_CASE(flat_set_6) {
    using namespace eagine;

    std::set<int> ss;
    flat_set<int> fs;

    std::vector<int> ks;

    for(int i = 0; i < test_repeats(1000, 10000); ++i) {
        int k = rg.get_any<int>();
        ks.push_back(k);

        ss.insert(k);
        fs.insert(k);
    }

    BOOST_CHECK_EQUAL(ss.empty(), fs.empty());
    BOOST_CHECK_EQUAL(ss.size(), fs.size());

    for(int k : ks) {
        auto ssi = ss.find(k);
        auto fsi = fs.find(k);

        BOOST_ASSERT(ssi != ss.end());
        BOOST_ASSERT(fsi != fs.end());
        BOOST_ASSERT(fs.contains(k));

        BOOST_CHECK_EQUAL(*ssi, *fsi);

        const auto esmc = ss.erase(k);
        const auto efmc = fs.erase(k);

        BOOST_CHECK_EQUAL(ss.size(), fs.size());
        BOOST_CHECK_EQUAL(esmc, efmc);
    }

    for(int k : ks) {
        auto ssi = ss.find(k);
        auto fsi = fs.find(k);

        BOOST_ASSERT(ssi == ss.end());
        BOOST_ASSERT(fsi == fs.end());
        BOOST_ASSERT(!fs.contains(k));
    }
}

BOOST_AUTO_TEST_SUITE_END()

#include "../unit_test_end.inl"
