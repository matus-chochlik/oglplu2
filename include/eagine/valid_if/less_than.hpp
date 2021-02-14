/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_VALID_IF_LESS_THAN_HPP
#define EAGINE_VALID_IF_LESS_THAN_HPP

#include "decl.hpp"

namespace eagine {

/// @brief Policy class for values valid if less than Cmp.
/// @ingroup valid_if
template <typename T, T Cmp>
struct valid_if_lt_policy {

    /// @brief Indicates value validity, true if value < Cmp.
    constexpr auto operator()(T value) const noexcept {
        return value < Cmp;
    }

    struct do_log {
        template <typename X, typename = disable_if_same_t<X, do_log>>
        constexpr do_log(X&&) noexcept {}

        template <typename Log>
        void operator()(Log& log, const T& v) const {
            log << "Value " << v << ", "
                << "greater then or equal to " << Cmp << " "
                << "is invalid";
        }
    };
};

/// @brief Specialization of valid_if, for values valid if less than Cmp.
/// @ingroup valid_if
/// @see valid_if_between
/// @see valid_if_lt_size
template <typename T, T Cmp>
using valid_if_less_than = valid_if<T, valid_if_lt_policy<T, Cmp>>;

} // namespace eagine

#endif // EAGINE_VALID_IF_LESS_THAN_HPP
