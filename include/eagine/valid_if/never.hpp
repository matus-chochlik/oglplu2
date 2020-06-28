/**
 *  @file eagine/valid_if/never.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_VALID_IF_NEVER_HPP
#define EAGINE_VALID_IF_NEVER_HPP

#include "decl.hpp"

namespace eagine {

// never
struct never_valid_policy {
    template <typename T>
    constexpr inline bool operator()(T) const noexcept {
        return false;
    }

    struct do_log {
        template <typename X, typename = disable_if_same_t<X, do_log>>
        constexpr inline do_log(X&&) noexcept {
        }

        template <typename Log, typename T>
        void operator()(Log& log, const T&) const {
            log << "value is not valid";
        }
    };
};

template <typename T>
using never_valid = valid_if<T, never_valid_policy>;

} // namespace eagine

#endif // EAGINE_VALID_IF_NEVER_HPP
