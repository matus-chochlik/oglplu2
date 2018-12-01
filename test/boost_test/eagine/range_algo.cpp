/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/range_algo.hpp>
#define BOOST_TEST_MODULE EAGINE_range_algo
#include "../unit_test_begin.inl"

#include <vector>
#include <eagine/cstr_ref.hpp>
#include <eagine/span.hpp>

BOOST_AUTO_TEST_SUITE(range_algo_tests)

static eagine::test_random_generator rg;

template <typename T>
void
test_range_equal_1(eagine::span<T> rng1, eagine::span<T> rng2) {
    using namespace eagine;

    bool are_equal = (rng1.size() == rng2.size());

    for(span_size_t i = 0; i < rng1.size(); ++i) {
        are_equal &= (rng1[i] == rng2[i]);
    }

    BOOST_CHECK_EQUAL(ranges::equal(rng1, rng2), are_equal);
}

template <typename T>
void
test_range_equal_1(T min, T max, bool are) {
    std::vector<T> v1(rg.get_std_size(20, 100));
    std::vector<T> v2(v1.size());

    for(typename std::vector<T>::size_type i = 0; i < v1.size(); ++i) {
        v1[i] = rg.get<T>(min, max);
        if(are)
            v2[i] = v1[i];
        else
            v2[i] = rg.get<T>(min, max);
    }

    test_range_equal_1<T>(eagine::make_span(v1), eagine::make_span(v2));
}

template <typename T>
void
test_range_equal_1(T min, T max) {
    test_range_equal_1(min, max, true);
    test_range_equal_1(min, max, false);

    for(int i = 0; i < 10; ++i) {
        test_range_equal_1(min, max, rg.get_bool());
    }
}

BOOST_AUTO_TEST_CASE(range_algo_equal_1) {
    test_range_equal_1<char>('A', 'Z');
    test_range_equal_1<int>(-100000, 100000);
}

template <typename T>
void
test_range_slice_r_p_s_1(
  eagine::span<T> rng, eagine::span_size_t p, eagine::span_size_t s) {
    using namespace eagine;

    span<T> slc = ranges::slice(rng, p, s);

    span_size_t n = slc.size();

    BOOST_CHECK(slc.size() <= rng.size());
    BOOST_CHECK(slc.size() <= s);

    for(span_size_t i = 0; i < n; ++i) {
        BOOST_CHECK_EQUAL(rng[p + i], slc[i]);
    }
}

template <typename T>
void
test_range_slice_r_p_s_1(eagine::span<T> rng) {
    using namespace eagine;

    test_range_slice_r_p_s_1(rng, 0, 0);
    test_range_slice_r_p_s_1(rng, 0, rng.size() / 2);
    test_range_slice_r_p_s_1(rng, 0, rng.size());
    test_range_slice_r_p_s_1(rng, 0, rng.size() * 2);

    test_range_slice_r_p_s_1(rng, rng.size() / 2, 0);
    test_range_slice_r_p_s_1(rng, rng.size() / 2, rng.size() / 2);
    test_range_slice_r_p_s_1(rng, rng.size() / 2, rng.size());
    test_range_slice_r_p_s_1(rng, rng.size() / 2, rng.size() * 2);

    test_range_slice_r_p_s_1(rng, rng.size() * 2, 0);
    test_range_slice_r_p_s_1(rng, rng.size() * 2, rng.size() / 2);
    test_range_slice_r_p_s_1(rng, rng.size() * 2, rng.size());
    test_range_slice_r_p_s_1(rng, rng.size() * 2, rng.size() * 2);

    for(int i = 0; i < 100; ++i) {
        test_range_slice_r_p_s_1(
          rng,
          rg.get_span_size(0, rng.size() * 2),
          rg.get_span_size(0, rng.size() * 2));
    }
}

template <typename T>
void
test_range_slice_r_p_s_1(T min, T max) {
    for(int i = 0; i < 10; ++i) {
        std::vector<T> v(rg.get_std_size(20, 100));
        for(T& x : v) {
            x = rg.get<T>(min, max);
        }
        test_range_slice_r_p_s_1(eagine::make_span(v));
    }
}

BOOST_AUTO_TEST_CASE(range_algo_slice_r_p_s_1) {
    test_range_slice_r_p_s_1<char>('A', 'Z');
    test_range_slice_r_p_s_1<int>(-100000, 100000);
}

template <typename T>
void
test_range_slice_r_p_1(eagine::span<T> rng, eagine::span_size_t p) {
    using namespace eagine;

    span<T> slc = ranges::slice(rng, p);

    span_size_t n = slc.size();

    BOOST_CHECK(slc.size() <= rng.size());

    for(span_size_t i = 0; i < n; ++i) {
        BOOST_CHECK_EQUAL(rng[p + i], slc[i]);
    }
}

template <typename T>
void
test_range_slice_r_p_1(eagine::span<T> rng) {
    using namespace eagine;

    test_range_slice_r_p_1(rng, 0);
    test_range_slice_r_p_1(rng, rng.size() / 2);
    test_range_slice_r_p_1(rng, rng.size());
    test_range_slice_r_p_1(rng, rng.size() * 2);

    for(int i = 0; i < 100; ++i) {
        test_range_slice_r_p_1(rng, rg.get_span_size(0, rng.size() * 2));
    }
}

template <typename T>
void
test_range_slice_r_p_1(T min, T max) {
    for(int i = 0; i < 10; ++i) {
        std::vector<T> v(rg.get_std_size(20, 100));
        for(T& x : v) {
            x = rg.get<T>(min, max);
        }
        test_range_slice_r_p_1(eagine::make_span(v));
    }
}

BOOST_AUTO_TEST_CASE(range_algo_slice_r_p_1) {
    test_range_slice_r_p_1<char>('A', 'Z');
    test_range_slice_r_p_1<int>(-100000, 100000);
}

template <typename T>
void
test_range_head_1(eagine::span<T> rng, eagine::span_size_t l) {
    using namespace eagine;

    span<T> rng2 = ranges::head(rng, l);

    span_size_t n = rng2.size();

    BOOST_CHECK(rng2.size() <= rng.size());

    for(span_size_t i = 0; i < n; ++i) {
        BOOST_CHECK_EQUAL(rng[i], rng2[i]);
    }
}

template <typename T>
void
test_range_head_1(eagine::span<T> rng) {
    using namespace eagine;

    test_range_head_1(rng, 0);
    test_range_head_1(rng, rng.size() / 2);
    test_range_head_1(rng, rng.size());
    test_range_head_1(rng, rng.size() * 2);

    for(int i = 0; i < 100; ++i) {
        test_range_head_1(rng, rg.get_span_size(0, rng.size() * 2));
    }
}

template <typename T>
void
test_range_head_1(T min, T max) {
    for(int i = 0; i < 10; ++i) {
        std::vector<T> v(rg.get_std_size(20, 100));
        for(T& x : v) {
            x = rg.get<T>(min, max);
        }
        test_range_head_1(eagine::make_span(v));
    }
}

BOOST_AUTO_TEST_CASE(range_algo_head_1) {
    test_range_head_1<char>('A', 'Z');
    test_range_head_1<int>(-100000, 100000);
}

template <typename T>
void
test_range_tail_1(eagine::span<T> rng, eagine::span_size_t l) {
    using namespace eagine;

    span<T> rng2 = ranges::tail(rng, l);

    span_size_t n = rng2.size();

    BOOST_CHECK(rng2.size() <= rng.size());

    span_size_t p = rng.size() - l;
    if(p < 0)
        p = 0;

    for(span_size_t i = 0; i < n; ++i) {
        BOOST_CHECK_EQUAL(rng[p + i], rng2[i]);
    }
}

template <typename T>
void
test_range_tail_1(eagine::span<T> rng) {
    using namespace eagine;

    test_range_tail_1(rng, 0);
    test_range_tail_1(rng, rng.size() / 2);
    test_range_tail_1(rng, rng.size());
    test_range_tail_1(rng, rng.size() * 2);

    for(int i = 0; i < 100; ++i) {
        test_range_tail_1(rng, rg.get_span_size(0, rng.size() * 2));
    }
}

template <typename T>
void
test_range_tail_1(T min, T max) {
    for(int i = 0; i < 10; ++i) {
        std::vector<T> v(rg.get_std_size(20, 100));
        for(T& x : v) {
            x = rg.get<T>(min, max);
        }
        test_range_tail_1(eagine::make_span(v));
    }
}

BOOST_AUTO_TEST_CASE(range_algo_tail_1) {
    test_range_tail_1<char>('A', 'Z');
    test_range_tail_1<int>(-100000, 100000);
}

template <typename T>
void
test_range_starts_with_1(eagine::span<T> rng1, eagine::span<T> rng2) {
    using namespace eagine;

    span_size_t n = rng2.size();

    bool equal = true;

    for(span_size_t i = 0; i < n; ++i) {
        equal &= (rng1[i] == rng2[i]);
    }

    BOOST_CHECK_EQUAL(ranges::starts_with(rng1, rng2), equal);
}

template <typename T>
void
test_range_starts_with_1(T min, T max, bool does) {
    std::vector<T> v1(rg.get_std_size(20, 100));
    std::vector<T> v2(rg.get_std_size(0, v1.size()));

    typename std::vector<T>::size_type i = 0;

    while(i < v2.size()) {
        v1[i] = rg.get<T>(min, max);
        if(does)
            v2[i] = v1[i];
        else
            v2[i] = rg.get<T>(min, max);
        ++i;
    }

    while(i < v1.size()) {
        v1[i] = rg.get<T>(min, max);
        ++i;
    }

    test_range_starts_with_1(eagine::make_span(v1), eagine::make_span(v2));
}

template <typename T>
void
test_range_starts_with_1(T min, T max) {
    test_range_starts_with_1<T>(min, max, false);
    test_range_starts_with_1<T>(min, max, true);

    for(int i = 0; i < 10; ++i) {
        test_range_starts_with_1<T>(min, max, rg.get_bool());
    }
}

BOOST_AUTO_TEST_CASE(range_algo_starts_with_1) {
    test_range_starts_with_1<char>('A', 'Z');
    test_range_starts_with_1<int>(-100000, 100000);
}

template <typename T>
void
test_range_ends_with_1(eagine::span<T> rng1, eagine::span<T> rng2) {
    using namespace eagine;

    span_size_t n = rng2.size();

    span_size_t p = rng1.size() - n;

    bool equal = true;

    for(span_size_t i = 0; i < n; ++i) {
        equal &= (rng1[p + i] == rng2[i]);
    }

    BOOST_CHECK_EQUAL(ranges::ends_with(rng1, rng2), equal);
}

template <typename T>
void
test_range_ends_with_1(T min, T max, bool does) {
    std::vector<T> v1(rg.get_std_size(20, 100));
    std::vector<T> v2(rg.get_std_size(0, v1.size()));

    typename std::vector<T>::size_type i = 0;
    typename std::vector<T>::size_type p = v1.size() - v2.size();

    while(i < p) {
        v1[i] = rg.get<T>(min, max);
        ++i;
    }

    while(i < v1.size()) {
        v1[i] = rg.get<T>(min, max);
        if(does)
            v2[i - p] = v1[i];
        else
            v2[i - p] = rg.get<T>(min, max);
        ++i;
    }

    test_range_ends_with_1(eagine::make_span(v1), eagine::make_span(v2));
}

template <typename T>
void
test_range_ends_with_1(T min, T max) {
    test_range_ends_with_1<T>(min, max, false);
    test_range_ends_with_1<T>(min, max, true);

    for(int i = 0; i < 10; ++i) {
        test_range_ends_with_1<T>(min, max, rg.get_bool());
    }
}

BOOST_AUTO_TEST_CASE(range_algo_ends_with_1) {
    test_range_ends_with_1<char>('A', 'Z');
    test_range_ends_with_1<int>(-100000, 100000);
}

template <typename T>
void
test_range_find_pos_1(eagine::span<T> rng1, eagine::span<T> rng2) {
    using namespace eagine;

    if(auto f = ranges::find_pos(rng1, rng2)) {
        span_size_t p = f.value();
        span_size_t n = rng2.size();

        bool equal = true;

        for(span_size_t i = 0; i < n; ++i) {
            equal &= (rng1[p + i] == rng2[i]);
        }

        BOOST_CHECK(equal);
        BOOST_CHECK(ranges::contains(rng1, rng2));
    } else if(rng2.size() > 0) {
        BOOST_CHECK(!ranges::contains(rng1, rng2));
    }
}

template <typename T>
void
test_range_find_pos_1(T min, T max, bool has) {
    typedef typename std::vector<T>::size_type sz_t;

    sz_t l1 = rg.get<sz_t>(20, 100);
    sz_t l2 = rg.get<sz_t>(0, l1);
    sz_t p2 = rg.get<sz_t>(0, l1 - l2);
    sz_t i = 0;

    assert(p2 + l2 <= l1);

    std::vector<T> v1(l1);
    std::vector<T> v2(l2);

    while(i < p2) {
        v1[i] = rg.get<T>(min, max);
        ++i;
    }

    while(i < p2 + l2) {
        v1[i] = rg.get<T>(min, max);
        if(has)
            v2[i - p2] = v1[i];
        else
            v2[i - p2] = rg.get<T>(min, max);
        ++i;
    }

    while(i < l1) {
        v1[i] = rg.get<T>(min, max);
        ++i;
    }

    test_range_find_pos_1(eagine::make_span(v1), eagine::make_span(v2));
}

template <typename T>
void
test_range_find_pos_1(T min, T max) {
    test_range_find_pos_1(min, max, true);
    test_range_find_pos_1(min, max, false);

    for(int i = 0; i < 10; ++i) {
        test_range_find_pos_1(min, max, rg.get_bool());
    }
}

BOOST_AUTO_TEST_CASE(range_algo_find_pos_1) {
    test_range_find_pos_1<char>('A', 'Z');
    test_range_find_pos_1<int>(-100000, 100000);
}

template <typename T>
void
test_range_rfind_pos_1(eagine::span<T> rng1, eagine::span<T> rng2) {
    using namespace eagine;

    if(auto f = ranges::rfind_pos(rng1, rng2)) {
        span_size_t p = f.value();
        span_size_t n = rng2.size();

        bool equal = true;

        for(span_size_t i = 0; i < n; ++i) {
            equal &= (rng1[p + i] == rng2[i]);
        }

        BOOST_CHECK(equal);
        BOOST_CHECK(ranges::contains(rng1, rng2));
    } else if(rng2.size() > 0) {
        BOOST_CHECK(!ranges::contains(rng1, rng2));
    }
}

template <typename T>
void
test_range_rfind_pos_1(T min, T max, bool has) {
    typedef typename std::vector<T>::size_type sz_t;

    sz_t l1 = rg.get<sz_t>(20, 100);
    sz_t l2 = rg.get<sz_t>(0, l1);
    sz_t p2 = rg.get<sz_t>(0, l1 - l2);
    sz_t i = 0;

    assert(p2 + l2 <= l1);

    std::vector<T> v1(l1);
    std::vector<T> v2(l2);

    while(i < p2) {
        v1[i] = rg.get<T>(min, max);
        ++i;
    }

    while(i < p2 + l2) {
        v1[i] = rg.get<T>(min, max);
        if(has)
            v2[i - p2] = v1[i];
        else
            v2[i - p2] = rg.get<T>(min, max);
        ++i;
    }

    while(i < l1) {
        v1[i] = rg.get<T>(min, max);
        ++i;
    }

    test_range_rfind_pos_1(eagine::make_span(v1), eagine::make_span(v2));
}

template <typename T>
void
test_range_rfind_pos_1(T min, T max) {
    test_range_rfind_pos_1(min, max, true);
    test_range_rfind_pos_1(min, max, false);

    for(int i = 0; i < 10; ++i) {
        test_range_rfind_pos_1(min, max, rg.get_bool());
    }
}

BOOST_AUTO_TEST_CASE(range_algo_rfind_pos_1) {
    test_range_rfind_pos_1<char>('A', 'Z');
    test_range_rfind_pos_1<int>(-100000, 100000);
}

template <typename T>
void
test_range_find_1(eagine::span<T> rng1, eagine::span<T> rng2) {
    using namespace eagine;

    eagine::span<T> rng3 = ranges::find(rng1, rng2);
    if(rng3.size() > 0) {
        BOOST_ASSERT(rng2.size() <= rng3.size());

        span_size_t n = rng2.size();

        bool equal = true;

        for(span_size_t i = 0; i < n; ++i) {
            equal &= (rng2[i] == rng3[i]);
        }

        BOOST_CHECK(equal);
    }
}

template <typename T>
void
test_range_find_1(T min, T max, bool has) {
    typedef typename std::vector<T>::size_type sz_t;

    sz_t l1 = rg.get<sz_t>(20, 100);
    sz_t l2 = rg.get<sz_t>(0, l1);
    sz_t p2 = rg.get<sz_t>(0, l1 - l2);
    sz_t i = 0;

    assert(p2 + l2 <= l1);

    std::vector<T> v1(l1);
    std::vector<T> v2(l2);

    while(i < p2) {
        v1[i] = rg.get<T>(min, max);
        ++i;
    }

    while(i < p2 + l2) {
        v1[i] = rg.get<T>(min, max);
        if(has)
            v2[i - p2] = v1[i];
        else
            v2[i - p2] = rg.get<T>(min, max);
        ++i;
    }

    while(i < l1) {
        v1[i] = rg.get<T>(min, max);
        ++i;
    }

    test_range_find_1(eagine::make_span(v1), eagine::make_span(v2));
}

template <typename T>
void
test_range_find_1(T min, T max) {
    test_range_find_1(min, max, true);
    test_range_find_1(min, max, false);

    for(int i = 0; i < 10; ++i) {
        test_range_find_1(min, max, rg.get_bool());
    }
}

BOOST_AUTO_TEST_CASE(range_algo_find_1) {
    test_range_find_1<char>('A', 'Z');
    test_range_find_1<int>(-100000, 100000);
}

template <typename T>
void
test_range_strip_prefix_1(eagine::span<T> rng1, eagine::span<T> rng2) {
    using namespace eagine;

    bool empty_prefix = rng2.empty();
    bool had_prefix = ranges::starts_with(rng1, rng2);

    eagine::span<T> rng3 = ranges::strip_prefix(rng1, rng2);

    bool has_prefix =
      (rng3.size() == rng1.size()) && ranges::starts_with(rng3, rng2);

    if(had_prefix) {
        BOOST_CHECK(!has_prefix || empty_prefix);
        BOOST_CHECK_EQUAL(rng1.size(), rng2.size() + rng3.size());
    } else {
        BOOST_CHECK(!has_prefix);
        BOOST_CHECK_EQUAL(rng1.size(), rng3.size());
    }
}

template <typename T>
void
test_range_strip_prefix_1(T min, T max, bool has) {
    std::vector<T> v1(rg.get_std_size(20, 100));
    std::vector<T> v2(rg.get_std_size(0, v1.size()));

    typename std::vector<T>::size_type i = 0;

    while(i < v2.size()) {
        v1[i] = rg.get<T>(min, max);
        if(has)
            v2[i] = v1[i];
        else
            v2[i] = rg.get<T>(min, max);
        ++i;
    }

    while(i < v1.size()) {
        v1[i] = rg.get<T>(min, max);
        ++i;
    }

    test_range_strip_prefix_1(eagine::make_span(v1), eagine::make_span(v2));
}

template <typename T>
void
test_range_strip_prefix_1(T min, T max) {
    test_range_strip_prefix_1(min, max, true);
    test_range_strip_prefix_1(min, max, false);

    for(int i = 0; i < 10; ++i) {
        test_range_strip_prefix_1(min, max, rg.get_bool());
    }
}

BOOST_AUTO_TEST_CASE(range_algo_strip_prefix_1) {
    test_range_strip_prefix_1<char>('A', 'Z');
    test_range_strip_prefix_1<int>(-100000, 100000);
}

template <typename T>
void
test_range_strip_suffix_1(eagine::span<T> rng1, eagine::span<T> rng2) {
    using namespace eagine;

    bool empty_suffix = rng2.empty();
    bool had_suffix = ranges::ends_with(rng1, rng2);

    eagine::span<T> rng3 = ranges::strip_suffix(rng1, rng2);

    bool has_suffix =
      (rng3.size() == rng1.size()) && ranges::ends_with(rng3, rng2);

    if(had_suffix) {
        BOOST_CHECK(!has_suffix || empty_suffix);
        BOOST_CHECK_EQUAL(rng1.size(), rng2.size() + rng3.size());
    } else {
        BOOST_CHECK(!has_suffix);
        BOOST_CHECK_EQUAL(rng1.size(), rng3.size());
    }
}

template <typename T>
void
test_range_strip_suffix_1(T min, T max, bool has) {
    std::vector<T> v1(rg.get_std_size(20, 100));
    std::vector<T> v2(rg.get_std_size(0, v1.size()));

    typename std::vector<T>::size_type i = 0;
    typename std::vector<T>::size_type p = v1.size() - v2.size();

    while(i < p) {
        v1[i] = rg.get<T>(min, max);
        ++i;
    }

    while(i < v1.size()) {
        v1[i] = rg.get<T>(min, max);
        if(has)
            v2[i - p] = v1[i];
        else
            v2[i - p] = rg.get<T>(min, max);
        ++i;
    }

    test_range_strip_suffix_1(eagine::make_span(v1), eagine::make_span(v2));
}

template <typename T>
void
test_range_strip_suffix_1(T min, T max) {
    test_range_strip_suffix_1(min, max, true);
    test_range_strip_suffix_1(min, max, false);

    for(int i = 0; i < 10; ++i) {
        test_range_strip_suffix_1(min, max, rg.get_bool());
    }
}

BOOST_AUTO_TEST_CASE(range_algo_strip_suffix_1) {
    test_range_strip_suffix_1<char>('A', 'Z');
    test_range_strip_suffix_1<int>(-100000, 100000);
}

// TODO

BOOST_AUTO_TEST_SUITE_END()

#include "../unit_test_end.inl"
