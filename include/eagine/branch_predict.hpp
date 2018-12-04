/**
 *  @file eagine/branch_predict.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_BRANCH_PREDICT_HPP
#define EAGINE_BRANCH_PREDICT_HPP

#if defined __GNUC__
#define EAGINE_LIKELY(EXPR) __builtin_expect(!!(EXPR), 1)
#else
#define EAGINE_LIKELY(EXPR) (!!(EXPR))
#endif

#endif // EAGINE_BRANCH_PREDICT_HPP
