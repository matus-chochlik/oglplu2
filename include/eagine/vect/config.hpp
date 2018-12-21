/**
 *  @file eagine/vect/config.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_VECT_CONFIG_HPP
#define EAGINE_VECT_CONFIG_HPP

#ifndef EAGINE_USE_SIMD

#if defined(__clang__) || defined(__GNUC__)
#define EAGINE_USE_SIMD __SSE__
#else
#define EAGINE_USE_SIMD 1
#endif

#endif

#ifndef EAGINE_VECT_OPTS
#define EAGINE_VECT_OPTS 1
#endif

#endif // EAGINE_VECT_CONFIG_HPP
