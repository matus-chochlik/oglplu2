/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdisabled-macro-expansion"
#endif

#define BOOST_TEST_DYN_LINK
#include "../random.hpp"
#include <eagine/interop/valgrind.hpp>
#include <eagine/maybe_unused.hpp>
#include <boost/test/tools/floating_point_comparison.hpp>
#include <boost/test/unit_test.hpp>

namespace eagine {
//------------------------------------------------------------------------------
template <typename T>
static inline T test_repeats(T min, T max) noexcept {
    return running_on_valgrind() ? min : max;
}
//------------------------------------------------------------------------------
} // namespace eagine
