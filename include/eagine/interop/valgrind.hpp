/**
 *  @file eagine/interop/valgrind.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_INTEROP_VALGRIND_HPP
#define EAGINE_INTEROP_VALGRIND_HPP

#include "../tribool.hpp"

#if defined(__GNUC__) || defined(__clang__)
// clang-format off
#if __has_include(<valgrind/valgrind.h>)
// clang-format on
#include <valgrind/valgrind.h>
#endif
#endif

namespace eagine {

static inline auto running_on_valgrind() noexcept -> tribool {
#if defined(RUNNING_ON_VALGRIND)
    return bool(RUNNING_ON_VALGRIND); // NOLINT(hicpp-no-assembler)
#else
    return indeterminate;
#endif
}
} // namespace eagine

#endif // EAGINE_INTEROP_VALGRIND_HPP
