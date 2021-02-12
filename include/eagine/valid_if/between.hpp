/// @file eagine/valid_if/between.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_VALID_IF_BETWEEN_HPP
#define EAGINE_VALID_IF_BETWEEN_HPP

#include "decl.hpp"

namespace eagine {

// between [min, max]
template <typename T, typename C, C Min, C Max>
struct valid_if_btwn_policy {
    constexpr auto operator()(T value) const noexcept {
        return (T(Min) <= value) && (value <= T(Max));
    }

    struct do_log {
        template <typename X, typename = disable_if_same_t<X, do_log>>
        constexpr do_log(X&&) noexcept {}

        template <typename Log>
        void operator()(Log& log, const T& v) const {
            log << "Value " << v << ", not between " << Min << " and " << Max
                << " is invalid";
        }
    };
};

template <typename T, typename C, C Min, C Max>
using valid_if_between_c = valid_if<T, valid_if_btwn_policy<T, C, Min, Max>>;

template <typename T, T Min, T Max>
using valid_if_between = valid_if_between_c<T, T, Min, Max>;

} // namespace eagine

#endif // EAGINE_VALID_IF_BETWEEN_HPP
