/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/deep_copy_ptr.hpp>
#define BOOST_TEST_MODULE EAGINE_deep_copy_ptr
#include "../unit_test_begin.inl"

#include <vector>

template <typename T>
struct test_copyable {
    T value;

    using this_class = test_copyable;

    test_copyable(T v)
      : value(v) {
    }

    std::unique_ptr<test_copyable> copy() {
        return new test_copyable(value);
    }

    friend bool operator==(const this_class& a, const this_class& b) {
        return a.value == b.value;
    }
};

template <typename T>
struct test_copyable_intf {
    using this_class = test_copyable_intf;

    test_copyable_intf() = default;
    test_copyable_intf(const test_copyable_intf&) = default;
    virtual ~test_copyable_intf() = default;

    virtual std::unique_ptr<test_copyable_intf<T>> copy() = 0;

    virtual bool equal(const test_copyable_intf&) const = 0;

    friend bool operator==(const this_class& a, const this_class& b) {
        return a.equal(b);
    }
};

template <typename T>
struct test_copyable_impl : test_copyable_intf<T> {
    T value;

    test_copyable_impl(T v)
      : value(v) {
    }

    std::unique_ptr<test_copyable_intf<T>> copy() override {
        return std::unique_ptr<test_copyable_intf<T>>(
          new test_copyable_impl(value));
    }

    bool equal(const test_copyable_intf<T>& intf) const override {
        return value == dynamic_cast<const test_copyable_impl&>(intf).value;
    }
};

BOOST_AUTO_TEST_SUITE(deep_copy_ptr_tests)

static eagine::test_random_generator rg;

template <typename I, typename T>
void test_deep_copy_ptr_1() {
    using namespace eagine;

    for(unsigned r = 0; r < 10; ++r) {
        deep_copy_ptr<I> val = make_deep_copy_ptr<T>(rg.get_int(0, 10000));

        std::vector<deep_copy_ptr<I>> vec;

        const unsigned n = 100;
        for(unsigned i = 0; i < n; ++i) {
            vec.push_back(val);
        }

        for(unsigned i = 0; i < n; ++i) {
            BOOST_CHECK(bool(val.get()));
            BOOST_CHECK(bool(vec[i].get()));
            BOOST_CHECK(val.get() != vec[i].get());
            BOOST_CHECK(*val == *vec[i]);
        }
    }
}

BOOST_AUTO_TEST_CASE(deep_copy_ptr_1) {
    using namespace eagine;

    test_deep_copy_ptr_1<int, int>();
    test_deep_copy_ptr_1<test_copyable<int>, test_copyable<int>>();
    test_deep_copy_ptr_1<test_copyable_intf<int>, test_copyable_impl<int>>();
}

BOOST_AUTO_TEST_SUITE_END()

#include "../unit_test_end.inl"
