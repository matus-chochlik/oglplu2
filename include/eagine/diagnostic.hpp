/**
 *  @file eagine/diagnostic.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_DIAGNOSTIC_HPP
#define EAGINE_DIAGNOSTIC_HPP

#include "preprocessor.hpp"

#if defined(__clang__)
#define EAGINE_DIAG_PRAGMA(EXPR) EAGINE_PRAGMA(clang diagnostic EXPR)
#elif defined(__GNUC__)
#define EAGINE_DIAG_PRAGMA(EXPR) EAGINE_PRAGMA(GCC diagnostic EXPR)
#endif

#if defined(__clang__) || defined(__GNUC__)

#define EAGINE_DIAG_OFF(EXPR) \
    EAGINE_DIAG_PRAGMA(ignored EAGINE_STRINGIFY(EAGINE_JOIN(-W, EXPR)))

#define EAGINE_DIAG_PUSH() EAGINE_DIAG_PRAGMA(push)
#define EAGINE_DIAG_POP() EAGINE_DIAG_PRAGMA(pop)

#endif

#endif // EAGINE_DIAGNOSTIC_HPP
