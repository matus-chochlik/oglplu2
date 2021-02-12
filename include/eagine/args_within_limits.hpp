/**
 *  @file eagine/args_within_limits.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_ARGS_WITHIN_LIMITS_HPP
#define EAGINE_ARGS_WITHIN_LIMITS_HPP

#include "is_within_limits.hpp"
#include <algorithm>

namespace eagine {
//------------------------------------------------------------------------------
template <typename... Params, typename... Args>
static constexpr auto args_within_limits_of(const Args&... args) noexcept
  -> std::enable_if_t<sizeof...(Params) == sizeof...(Args), bool> {
    return (... && is_within_limits<std::decay_t<Params>>(args));
}
//------------------------------------------------------------------------------
template <typename RV, typename... Params, typename... Args>
static constexpr auto
args_within_limits(RV (*)(Params...), const Args&... args) noexcept -> bool {
    return args_within_limits_of<Params...>(args...);
}
//------------------------------------------------------------------------------
template <typename RV, typename Cls, typename... Params, typename... Args>
static constexpr auto
args_within_limits(RV (Cls::*)(Params...), const Args&... args) noexcept
  -> bool {
    return args_within_limits_of<Params...>(args...);
}
//------------------------------------------------------------------------------
template <typename RV, typename Cls, typename... Params, typename... Args>
static constexpr auto args_within_limits(
  RV (Cls::*)(Params...) noexcept,
  const Args&... args) noexcept -> bool {
    return args_within_limits_of<Params...>(args...);
}
//------------------------------------------------------------------------------
template <typename RV, typename Cls, typename... Params, typename... Args>
static constexpr auto
args_within_limits(RV (Cls::*)(Params...) const, const Args&... args) noexcept
  -> bool {
    return args_within_limits_of<Params...>(args...);
}
//------------------------------------------------------------------------------
template <typename RV, typename Cls, typename... Params, typename... Args>
static constexpr auto args_within_limits(
  RV (Cls::*)(Params...) const noexcept,
  const Args&... args) noexcept -> bool {
    return args_within_limits_of<Params...>(args...);
}
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_ARGS_WITHIN_LIMITS_HPP
