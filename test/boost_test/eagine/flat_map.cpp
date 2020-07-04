/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/flat_map.hpp>
#define BOOST_TEST_MODULE EAGINE_flat_map
#include "../unit_test_begin.inl"

#include <functional>
#include <map>

BOOST_AUTO_TEST_SUITE(flat_map_tests)

static eagine::test_random_generator rg;

BOOST_AUTO_TEST_CASE(flat_map_1) {
    using namespace eagine;

    std::map<int, std::size_t> sm;

    using p_t = std::pair<const int, std::size_t>;

    std::vector<p_t> d;

    std::hash<int> h;

    for(int i = 0; i < test_repeats(1000, 10000); ++i) {
        int k = rg.get_any<int>();
        std::size_t v = h(k + k);

        sm.insert(p_t(k, v));
        d.push_back(p_t(k, v));
    }

    flat_map<int, std::size_t> fm(d);

    BOOST_CHECK_EQUAL(sm.empty(), fm.empty());
    BOOST_CHECK_EQUAL(sm.size(), fm.size());

    auto smi = sm.begin();
    auto fmi = fm.begin();

    while((smi != sm.end()) && (fmi != fm.end())) {
        BOOST_CHECK_EQUAL(smi->first, fmi->first);
        BOOST_CHECK_EQUAL(smi->second, fmi->second);
        ++smi;
        ++fmi;
    }

    BOOST_CHECK(smi == sm.end());
    BOOST_CHECK(fmi == fm.end());
}

BOOST_AUTO_TEST_CASE(flat_map_2) {
    using namespace eagine;

    std::map<int, std::size_t> sm;
    flat_map<int, std::size_t> fm;

    using p_t = std::pair<const int, std::size_t>;

    std::hash<int> h;

    for(int i = 0; i < test_repeats(1000, 10000); ++i) {
        int k = rg.get_any<int>();
        std::size_t v = h(k + k);

        sm.insert(p_t(k, v));
        fm.insert(p_t(k, v));
    }

    BOOST_CHECK_EQUAL(sm.empty(), fm.empty());
    BOOST_CHECK_EQUAL(sm.size(), fm.size());

    auto smi = sm.begin();
    auto fmi = fm.begin();

    while((smi != sm.end()) && (fmi != fm.end())) {
        BOOST_CHECK_EQUAL(smi->first, fmi->first);
        BOOST_CHECK_EQUAL(smi->second, fmi->second);
        ++smi;
        ++fmi;
    }

    BOOST_CHECK(smi == sm.end());
    BOOST_CHECK(fmi == fm.end());
}

BOOST_AUTO_TEST_CASE(flat_map_3) {
    using namespace eagine;

    std::map<int, std::size_t> sm;
    flat_map<int, std::size_t> fm;

    using p_t = std::pair<const int, std::size_t>;

    std::hash<int> h;

    for(int i = 0; i < test_repeats(1000, 10000); ++i) {
        int k = rg.get_any<int>();
        std::size_t v = h(k + k);

        sm.insert(sm.begin(), p_t(k, v));
        fm.insert(fm.begin(), p_t(k, v));
    }

    BOOST_CHECK_EQUAL(sm.empty(), fm.empty());
    BOOST_CHECK_EQUAL(sm.size(), fm.size());

    auto smi = sm.begin();
    auto fmi = fm.begin();

    while((smi != sm.end()) && (fmi != fm.end())) {
        BOOST_CHECK_EQUAL(smi->first, fmi->first);
        BOOST_CHECK_EQUAL(smi->second, fmi->second);
        ++smi;
        ++fmi;
    }

    BOOST_CHECK(smi == sm.end());
    BOOST_CHECK(fmi == fm.end());
}

BOOST_AUTO_TEST_CASE(flat_map_4) {
    using namespace eagine;

    std::map<int, std::size_t> sm;
    flat_map<int, std::size_t> fm;

    using p_t = std::pair<const int, std::size_t>;

    std::hash<int> h;

    for(int i = 0; i < test_repeats(1000, 10000); ++i) {
        int k = rg.get_any<int>();
        std::size_t v = h(k + k);

        sm.insert(sm.end(), p_t(k, v));
        fm.insert(fm.end(), p_t(k, v));
    }

    BOOST_CHECK_EQUAL(sm.empty(), fm.empty());
    BOOST_CHECK_EQUAL(sm.size(), fm.size());

    auto smi = sm.begin();
    auto fmi = fm.begin();

    while((smi != sm.end()) && (fmi != fm.end())) {
        BOOST_CHECK_EQUAL(smi->first, fmi->first);
        BOOST_CHECK_EQUAL(smi->second, fmi->second);
        ++smi;
        ++fmi;
    }

    BOOST_CHECK(smi == sm.end());
    BOOST_CHECK(fmi == fm.end());
}

BOOST_AUTO_TEST_CASE(flat_map_5) {
    using namespace eagine;

    std::map<int, std::size_t> sm;
    flat_map<int, std::size_t> fm;

    using p_t = std::pair<const int, std::size_t>;

    std::hash<int> h;

    for(int i = 0; i < test_repeats(1000, 10000); ++i) {
        int k = rg.get_any<int>();
        std::size_t v = h(k + k);

        sm.insert(sm.lower_bound(k), p_t(k, v));
        fm.insert(fm.lower_bound(k), p_t(k, v));
    }

    BOOST_CHECK_EQUAL(sm.empty(), fm.empty());
    BOOST_CHECK_EQUAL(sm.size(), fm.size());

    std::map<int, std::size_t>::iterator smi = sm.begin();
    flat_map<int, std::size_t>::iterator fmi = fm.begin();

    while((smi != sm.end()) && (fmi != fm.end())) {
        BOOST_CHECK_EQUAL(smi->first, fmi->first);
        BOOST_CHECK_EQUAL(smi->second, fmi->second);
        ++smi;
        ++fmi;
    }

    BOOST_CHECK(smi == sm.end());
    BOOST_CHECK(fmi == fm.end());
}

BOOST_AUTO_TEST_CASE(flat_map_6) {
    using namespace eagine;

    std::map<int, std::size_t> sm;
    flat_map<int, std::size_t> fm;

    using p_t = std::pair<const int, std::size_t>;
    std::vector<int> ks;

    std::hash<int> h;

    for(int i = 0; i < test_repeats(1000, 10000); ++i) {
        int k = rg.get_any<int>();
        std::size_t v = h(k + k);
        ks.push_back(k);

        sm.insert(p_t(k, v));
        fm.insert(p_t(k, v));
    }

    BOOST_CHECK_EQUAL(sm.empty(), fm.empty());
    BOOST_CHECK_EQUAL(sm.size(), fm.size());

    for(int k : ks) {
        auto smi = sm.find(k);
        auto fmi = fm.find(k);

        BOOST_ASSERT(smi != sm.end());
        BOOST_ASSERT(fmi != fm.end());

        BOOST_CHECK_EQUAL(smi->first, fmi->first);
        BOOST_CHECK_EQUAL(smi->second, fmi->second);

        const auto esmc = sm.erase(k);
        const auto efmc = fm.erase(k);

        BOOST_CHECK_EQUAL(sm.size(), fm.size());
        BOOST_CHECK_EQUAL(esmc, efmc);
    }

    for(int k : ks) {
        auto smi = sm.find(k);
        auto fmi = fm.find(k);

        BOOST_ASSERT(smi == sm.end());
        BOOST_ASSERT(fmi == fm.end());
    }
}

BOOST_AUTO_TEST_CASE(flat_map_7) {
    using namespace eagine;

    std::map<int, std::size_t> sm;
    flat_map<int, std::size_t> fm;

    using p_t = std::pair<const int, std::size_t>;

    std::hash<int> h;

    for(int i = 0; i < test_repeats(1000, 10000); ++i) {
        int k = rg.get_any<int>();
        std::size_t v = h(k + k);

        const bool ism = sm.emplace(k, v).second;
        const bool ifm = fm.emplace(k, v).second;

        BOOST_CHECK_EQUAL(ism, ifm);
    }

    BOOST_CHECK_EQUAL(sm.empty(), fm.empty());
    BOOST_CHECK_EQUAL(sm.size(), fm.size());

    auto smi = sm.begin();
    auto fmi = fm.begin();

    while((smi != sm.end()) && (fmi != fm.end())) {
        BOOST_CHECK_EQUAL(smi->first, fmi->first);
        BOOST_CHECK_EQUAL(smi->second, fmi->second);
        ++smi;
        ++fmi;
    }

    BOOST_CHECK(smi == sm.end());
    BOOST_CHECK(fmi == fm.end());
}

BOOST_AUTO_TEST_SUITE_END()

#include "../unit_test_end.inl"
