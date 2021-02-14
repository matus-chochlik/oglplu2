/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_VALID_IF_NEVER_HPP
#define EAGINE_VALID_IF_NEVER_HPP

#include "decl.hpp"

namespace eagine {

/// @brief Policy for never-valid values.
/// @ingroup valid_if
struct never_valid_policy {

    /// @brief Indicates value validity. Always returns false.
    template <typename T>
    constexpr auto operator()(const T&) const noexcept {
        return false;
    }

    struct do_log {
        template <typename X, typename = disable_if_same_t<X, do_log>>
        constexpr do_log(X&&) noexcept {}

        template <typename Log, typename T>
        void operator()(Log& log, const T&) const {
            log << "value is not valid";
        }
    };
};

/// @brief Specialization of valid_if, for never-valid values.
/// @ingroup valid_if
/// @see always_valid
template <typename T>
using never_valid = valid_if<T, never_valid_policy>;

} // namespace eagine

#endif // EAGINE_VALID_IF_NEVER_HPP
