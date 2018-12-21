/**
 *  @file eagine/valid_if/not_equal.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_VALID_IF_NOT_EQUAL_HPP
#define EAGINE_VALID_IF_NOT_EQUAL_HPP

#include "decl.hpp"

namespace eagine {

// not-equal
template <typename T, T Cmp>
struct valid_if_ne_policy {
    constexpr bool operator()(T value) const noexcept {
        return value != Cmp;
    }

    struct do_log {
        template <typename X>
        constexpr inline do_log(X&&) noexcept {
        }

        template <typename Log>
        void operator()(Log& log, const T&) const {
            log << "Value equal to " << Cmp << " is invalid";
        }
    };
};

template <typename T, T Cmp>
using valid_if_not = valid_if<T, valid_if_ne_policy<T, Cmp>>;

} // namespace eagine

#endif // EAGINE_VALID_IF_NOT_EQUAL_HPP
