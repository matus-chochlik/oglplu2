/**
 *  @file eagine/diagnostic.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_PREPROCESSOR_HPP
#define EAGINE_PREPROCESSOR_HPP

#define EAGINE_STRINGIFY(EXPR) EAGINE_DO_STRINGIFY(EXPR)
#define EAGINE_DO_STRINGIFY(EXPR) #EXPR

#define EAGINE_JOIN(L, R) EAGINE_DO_JOIN(L, R)
#define EAGINE_DO_JOIN(L, R) EAGINE_DO_JOIN2(L, R)
#define EAGINE_DO_JOIN2(L, R) L##R

#if defined(__clang__) || defined(__GNUC__)

#define EAGINE_PRAGMA(x) _Pragma(EAGINE_STRINGIFY(x))

#elif defined(_MSC_VER)

#define RAPIDJSON_PRAGMA(x) __pragma(x)

#endif

#endif // EAGINE_PREPROCESSOR_HPP
