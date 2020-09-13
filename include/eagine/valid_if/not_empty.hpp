/**
 *  @file eagine/valid_if/not_empty.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_VALID_IF_NOT_EMPTY_HPP
#define EAGINE_VALID_IF_NOT_EMPTY_HPP

#include "decl.hpp"

namespace eagine {

// not empty
template <typename T>
struct valid_if_not_empty_policy {
    constexpr auto operator()(const T& range) const noexcept {
        return !range.empty();
    }

    struct do_log {
        template <typename X, typename = disable_if_same_t<X, do_log>>
        constexpr inline do_log(X&&) noexcept {}

        template <typename Log>
        void operator()(Log& log, const T&) const {
            log << "Empty range, string or container is invalid";
        }
    };
};

template <typename T>
using valid_if_not_empty = valid_if<T, valid_if_not_empty_policy<T>>;

} // namespace eagine

#endif // EAGINE_VALID_IF_NOT_EMPTY_HPP
