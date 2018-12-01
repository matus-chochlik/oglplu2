/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/std/functional.hpp>
#define BOOST_TEST_MODULE EAGINE_std_invoke
#include "../unit_test_begin.inl"

#include <string>

BOOST_AUTO_TEST_SUITE(std_invoke_tests)

static eagine::test_random_generator rg;

BOOST_AUTO_TEST_CASE(invoke_1) {
    auto add2 = [](auto x, auto y) { return x + y; };
    auto add3 = [](auto x, auto y, auto z) { return x + y + z; };

    for(int r = 0; r < 100; ++r) {
        switch(rg.get_int(0, 3)) {
            default: { break; }
            case 0: {
                const auto x = rg.get_int(-1000, 1000);
                const auto y = rg.get_int(-1000, 1000);

                BOOST_CHECK_EQUAL(std::invoke(add2, x, y), add2(x, y));
                break;
            }
            case 1: {
                const auto x = rg.get_int(-1000, 1000);
                const auto y = rg.get_int(-1000, 1000);
                const auto z = rg.get_int(-1000, 1000);

                BOOST_CHECK_EQUAL(std::invoke(add3, x, y, z), add3(x, y, z));
                break;
            }
            case 2: {
                const auto x = rg.get_float(-10.f, 10.f);
                const auto y = rg.get_short(-1000, 1000);

                BOOST_CHECK_EQUAL(std::invoke(add2, x, y), add2(x, y));
                break;
            }
            case 3: {
                const auto x = rg.get_string(0, 11);
                const auto y = rg.get_string(0, 13);

                BOOST_CHECK_EQUAL(std::invoke(add2, x, y), add2(x, y));
                break;
            }
        }
    }
}

BOOST_AUTO_TEST_CASE(invoke_2) {
    auto fsub2 = [](auto x, auto y) { return x - y; };
    auto fsub3 = [](auto x, auto y, auto z) { return x - y - z; };

    auto rsub2 = std::ref(fsub2);
    auto rsub3 = std::ref(fsub3);

    for(int r = 0; r < 100; ++r) {
        switch(rg.get_int(0, 2)) {
            default: { break; }
            case 0: {
                const auto x = rg.get_int(-1000, 1000);
                const auto y = rg.get_int(-1000, 1000);

                BOOST_CHECK_EQUAL(std::invoke(rsub2, x, y), rsub2.get()(x, y));
                break;
            }
            case 1: {
                const auto x = rg.get_int(-1000, 1000);
                const auto y = rg.get_int(-1000, 1000);
                const auto z = rg.get_int(-1000, 1000);

                BOOST_CHECK_EQUAL(
                  std::invoke(rsub3, x, y, z), rsub3.get()(x, y, z));
                break;
            }
            case 2: {
                const auto x = rg.get_short(-1000, 1000);
                const auto y = rg.get_float(-10.f, 10.f);

                BOOST_CHECK_EQUAL(std::invoke(rsub2, x, y), rsub2.get()(x, y));
                break;
            }
        }
    }
}

struct invk_test_3 {
    int x;

    auto foo(int y) const {
        return (x - y);
    }

    auto bar(int y, int z) const {
        return (x + y) * z;
    }

    auto baz(void) const {
        return -x;
    }
};

BOOST_AUTO_TEST_CASE(invoke_3) {
    for(int r = 0; r < 100; ++r) {
        switch(rg.get_int(0, 2)) {
            default: { break; }
            case 0: {
                const invk_test_3 t{rg.get_int(-100, 100)};
                const auto y = rg.get_int(-100, 100);

                BOOST_CHECK_EQUAL(
                  std::invoke(&invk_test_3::foo, t, y), t.foo(y));
                break;
            }
            case 1: {
                const invk_test_3 t{rg.get_int(-100, 100)};
                const auto y = rg.get_int(-100, 100);
                const auto z = rg.get_int(-100, 100);

                BOOST_CHECK_EQUAL(
                  std::invoke(&invk_test_3::bar, t, y, z), t.bar(y, z));
                break;
            }
            case 2: {
                const invk_test_3 t{rg.get_int(-100, 100)};

                BOOST_CHECK_EQUAL(std::invoke(&invk_test_3::baz, t), t.baz());
                break;
            }
        }
    }
}

BOOST_AUTO_TEST_SUITE_END()

#include "../unit_test_end.inl"
