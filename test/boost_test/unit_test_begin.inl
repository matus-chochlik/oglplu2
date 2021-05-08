/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#define BOOST_TEST_DYN_LINK
#include "../random.hpp"
#include <eagine/diagnostic.hpp>
#include <eagine/interop/valgrind.hpp>
#include <eagine/main_ctx_object.hpp>
#include <eagine/maybe_unused.hpp>

#ifdef __clang__
EAGINE_DIAG_PUSH()
EAGINE_DIAG_OFF(disabled-macro-expansion)
#endif

#include <boost/test/tools/floating_point_comparison.hpp>
#include <boost/test/unit_test.hpp>

namespace eagine {
//------------------------------------------------------------------------------
template <typename T>
static inline T test_repeats(T min, T max) noexcept {
    return running_on_valgrind() ? min : max;
}
//------------------------------------------------------------------------------
class test_main_ctx_object_parent_info : public main_ctx_object_parent_info {
public:
    test_main_ctx_object_parent_info() noexcept
      : main_ctx_object_parent_info{} {}
};
//------------------------------------------------------------------------------
class test_main_ctx_object : public main_ctx_object {
public:
    test_main_ctx_object()
      : main_ctx_object(
          EAGINE_ID(TestObject),
          test_main_ctx_object_parent_info{}) {}
};
//------------------------------------------------------------------------------
} // namespace eagine
