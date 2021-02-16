/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_VALID_IF_ALWAYS_HPP
#define EAGINE_VALID_IF_ALWAYS_HPP

#include "decl.hpp"

namespace eagine {

/// @brief Policy for always valid values.
/// @ingroup valid_if
struct always_valid_policy {

    /// @brief Indicates value validity. Always returns true.
    template <typename T>
    constexpr auto operator()(const T&) const noexcept {
        return true;
    }

    struct do_log {
        template <typename X, typename = disable_if_same_t<X, do_log>>
        constexpr do_log(X&&) noexcept {}

        template <typename Log, typename T>
        void operator()(Log&, const T&) const {}
    };
};

/// @brief Specialization of valid_if, for always valid values.
/// @ingroup valid_if
/// @see never_valid
template <typename T>
using always_valid = valid_if<T, always_valid_policy>;

} // namespace eagine

#endif // EAGINE_VALID_IF_ALWAYS_HPP
