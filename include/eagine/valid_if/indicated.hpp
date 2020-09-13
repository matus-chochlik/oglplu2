/**
 *  @file eagine/valid_if/indicated.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_VALID_IF_INDICATED_HPP
#define EAGINE_VALID_IF_INDICATED_HPP

#include "decl.hpp"

namespace eagine {
//------------------------------------------------------------------------------
template <typename Indicator, typename Comparable, Comparable Value>
struct valid_if_indicated_policy {
    Indicator _indicator{};

    constexpr valid_if_indicated_policy() noexcept = default;

    constexpr valid_if_indicated_policy(Indicator indicator) noexcept
      : _indicator(indicator) {}

    template <typename T>
    bool operator()(const T&) const noexcept {
        return Comparable(_indicator) == Value;
    }

    struct do_log {
        template <typename X>
        constexpr inline do_log(X) noexcept {}

        template <typename Log, typename T>
        void operator()(Log& log, const T&) const {
            log << "indicator is " << Value;
        }
    };
};
//------------------------------------------------------------------------------
template <
  typename T,
  typename Indicator,
  typename Comparable = bool,
  Comparable Value = true>
using valid_if_indicated =
  valid_if<T, valid_if_indicated_policy<Indicator, Comparable, Value>>;
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_VALID_IF_INDICATED_HPP
