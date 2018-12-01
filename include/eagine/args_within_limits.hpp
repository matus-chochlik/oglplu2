/**
 *  @file eagine/args_within_limits.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <algorithm>
#include "is_within_limits.hpp"
#include "std/type_traits.hpp"
#include "valid_if/decl.hpp"

#ifndef EAGINE_ARGS_WITHIN_LIMITS_1509260923_HPP
#define EAGINE_ARGS_WITHIN_LIMITS_1509260923_HPP

namespace eagine {
//------------------------------------------------------------------------------
template <typename... Params, typename... Args>
static constexpr inline std::enable_if_t<sizeof...(Params) == sizeof...(Args),
  bool>
args_within_limits_of(const Args&... args) noexcept {
    return (... && is_within_limits<std::decay_t<Params>>(args));
}
//------------------------------------------------------------------------------
template <typename RV, typename... Params, typename... Args>
static inline bool
args_within_limits(RV (*)(Params...), const Args&... args) noexcept {
    return args_within_limits_of<Params...>(args...);
}
//------------------------------------------------------------------------------
template <typename RV, typename Cls, typename... Params, typename... Args>
static inline bool
args_within_limits(RV (Cls::*)(Params...), const Args&... args) noexcept {
    return args_within_limits_of<Params...>(args...);
}
//------------------------------------------------------------------------------
template <typename RV, typename Cls, typename... Params, typename... Args>
static inline bool
args_within_limits(RV (Cls::*)(Params...) const, const Args&... args) noexcept {
    return args_within_limits_of<Params...>(args...);
}
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_ARGS_WITHIN_LIMITS_1509260923_HPP
