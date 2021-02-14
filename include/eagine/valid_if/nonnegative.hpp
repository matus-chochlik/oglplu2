/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_VALID_IF_NONNEGATIVE_HPP
#define EAGINE_VALID_IF_NONNEGATIVE_HPP

#include "decl.hpp"

namespace eagine {

/// @brief Policy class for values valid when they are non-negative.
/// @ingroup valid_if
template <typename T>
struct valid_if_nonneg_policy {

    /// @brief Indicates value validity, true if 0 <= value.
    constexpr auto operator()(T value) const noexcept {
        return value >= T(0);
    }

    struct do_log {
        template <typename X, typename = disable_if_same_t<X, do_log>>
        constexpr do_log(X&&) noexcept {}

        template <typename Log>
        void operator()(Log& log, const T& v) const {
            log << "Value " << v << ", "
                << "less then zero "
                << "is invalid";
        }
    };
};

/// @brief Specialization of valid_if, for values valid if non-negative.
/// @ingroup valid_if
/// @see valid_if_positive
/// @see valid_if_less_than
template <typename T>
using valid_if_nonnegative = valid_if<T, valid_if_nonneg_policy<T>>;

} // namespace eagine

#endif // EAGINE_VALID_IF_NONNEGATIVE_HPP
