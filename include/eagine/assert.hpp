/**
 *  @file eagine/assert.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_ASSERT_HPP
#define EAGINE_ASSERT_HPP

#include "branch_predict.hpp"
#include "config/basic.hpp"
#include "maybe_unused.hpp"
#include <cassert>

#ifndef EAGINE_CHECK_LIMIT_CAST
#if EAGINE_LOW_PROFILE
#define EAGINE_CHECK_LIMIT_CAST 0
#else
#define EAGINE_CHECK_LIMIT_CAST 1
#endif
#endif

// clang-format off
#define EAGINE_ASSERT(EXPR) \
    assert(EXPR) // NOLINT(cert-dcl03-c,hicpp-static-assert,hicpp-no-array-decay)
// clang-format on

#if EAGINE_CHECK_LIMIT_CAST
#define EAGINE_CONSTEXPR_ASSERT(UNUSED, RESULT) \
    (EAGINE_MAYBE_UNUSED(UNUSED), RESULT)
#else
#define EAGINE_CONSTEXPR_ASSERT(CHECK, RESULT)                        \
    ((EAGINE_LIKELY(CHECK) ? void(0)                                  \
                           : [] { EAGINE_ASSERT(!bool(#CHECK)); }()), \
     RESULT)
#endif

#define EAGINE_ABORT(MSG) EAGINE_ASSERT(!bool(MSG))
#define EAGINE_UNREACHABLE(MSG) EAGINE_ABORT(MSG)

#endif // EAGINE_ASSERT_HPP
