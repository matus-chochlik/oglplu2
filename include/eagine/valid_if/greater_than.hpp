/**
 *  @file eagine/valid_if/greater_than.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_VALID_IF_GREATER_THAN_HPP
#define EAGINE_VALID_IF_GREATER_THAN_HPP

#include "decl.hpp"

namespace eagine {

// greater-than
template <typename T, T Cmp>
struct valid_if_gt_policy {
    constexpr bool operator()(T value) const noexcept {
        return value > Cmp;
    }

    struct do_log {
        template <typename X, typename = disable_if_same_t<X, do_log>>
        constexpr inline do_log(X&&) noexcept {
        }

        template <typename Log>
        void operator()(Log& log, const T& v) const {
            log << "Value " << v << ", "
                << "less then or equal to " << Cmp << " "
                << "is invalid";
        }
    };
};

template <typename T, T Cmp>
using valid_if_greater_than = valid_if<T, valid_if_gt_policy<T, Cmp>>;

} // namespace eagine

#endif // EAGINE_VALID_IF_GREATER_THAN_HPP
