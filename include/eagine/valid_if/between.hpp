/**
 *  @file eagine/valid_if/between.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_VALID_IF_BETWEEN_HPP
#define EAGINE_VALID_IF_BETWEEN_HPP

#include "decl.hpp"

namespace eagine {

// between [min, max]
template <typename T, T Min, T Max>
struct valid_if_btwn_policy {
    constexpr auto operator()(T value) const noexcept {
        return (Min <= value) && (value <= Max);
    }

    struct do_log {
        template <typename X, typename = disable_if_same_t<X, do_log>>
        constexpr inline do_log(X&&) noexcept {}

        template <typename Log>
        void operator()(Log& log, const T& v) const {
            log << "Value " << v << ", not between " << Min << " and " << Max
                << " is invalid";
        }
    };
};

template <typename T, T Min, T Max>
using valid_if_between = valid_if<T, valid_if_btwn_policy<T, Min, Max>>;

} // namespace eagine

#endif // EAGINE_VALID_IF_BETWEEN_HPP
