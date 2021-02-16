/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_VALID_IF_GE0_LE1_HPP
#define EAGINE_VALID_IF_GE0_LE1_HPP

#include "decl.hpp"

namespace eagine {

/// @brief Policy for values valid if between zero and one.
/// @ingroup valid_if
template <typename T>
struct valid_if_ge0_le1_policy {

    /// @brief Indicates value validity, true if 0 <= value <= 1.
    constexpr auto operator()(T value) const noexcept {
        return (T(0) <= value) && (value <= T(1));
    }

    struct do_log {
        template <typename X, typename = disable_if_same_t<X, do_log>>
        constexpr do_log(X&&) noexcept {}

        template <typename Log>
        void operator()(Log& log, const T& v) const {
            log << "Value " << v << ", "
                << "outside of interval [0,1] is invalid";
        }
    };
};

/// @brief Specialization of valid_if, for values valid if 0 <= value <= 1.
/// @ingroup valid_if
/// @see valid_if_between
/// @see valid_if_ge0_lt1
template <typename T>
using valid_if_between_0_1 = valid_if<T, valid_if_ge0_le1_policy<T>>;

} // namespace eagine

#endif // EAGINE_VALID_IF_GE0_LE1_HPP
