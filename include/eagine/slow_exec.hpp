/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_SLOW_EXEC_HPP
#define EAGINE_SLOW_EXEC_HPP

#include "branch_predict.hpp"
#include "config/basic.hpp"
#include "interop/valgrind.hpp"

namespace eagine {

/// @brief Enumeration indicating (estimated) memory access rate.
enum class memory_access_rate {
    /// @brief Minimal to none memory access.
    minimal,
    /// @brief Low memory access rate.
    low,
    /// @brief Average access rate.
    medium,
    /// @brief Above average to high access rate.
    high,
    /// @brief  Very high access rate.
    very_high
};

#if EAGINE_DEBUG && defined(RUNNING_ON_VALGRIND)
static inline auto temporal_slowdown_factor(
  memory_access_rate mem_access = memory_access_rate::medium) noexcept -> int {
    if(EAGINE_UNLIKELY(running_on_valgrind())) {
        switch(mem_access) {
            case memory_access_rate::minimal:
                return 5;
            case memory_access_rate::low:
                return 7;
            case memory_access_rate::medium:
                return 12;
            case memory_access_rate::high:
                return 25;
            case memory_access_rate::very_high:
                return 45;
        }
    }
    return 1;
}
#else
static constexpr auto temporal_slowdown_factor(
  memory_access_rate = memory_access_rate::medium) noexcept -> int {
    return 1;
}
#endif

} // namespace eagine

#endif // EAGINE_SLOW_EXEC_HPP
