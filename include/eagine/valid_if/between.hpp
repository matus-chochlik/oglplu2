/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_VALID_IF_BETWEEN_HPP
#define EAGINE_VALID_IF_BETWEEN_HPP

#include "decl.hpp"

namespace eagine {

/// @brief Policy for values valid if between Min and Max.
/// @tparam T the checked value type must be convertible to @p C.
/// @tparam C the Min and Max constant type.
/// @tparam Min the minimal valid value.
/// @tparam Max the maximal valid value.
/// @ingroup valid_if
template <typename T, typename C, C Min, C Max>
struct valid_if_btwn_policy {

    /// @brief Indicates @p value validity, true if between Min and Max.
    constexpr auto operator()(T value) const noexcept {
        return (T(Min) <= value) && (value <= T(Max));
    }

    struct do_log {
        template <typename X, typename = disable_if_same_t<X, do_log>>
        constexpr do_log(X&&) noexcept {}

        template <typename Log>
        void operator()(Log& log, const T& v) const {
            log << "Value " << v << ", not between " << Min << " and " << Max
                << " is invalid";
        }
    };
};

/// @brief Specialization of valid_if, for values valid if between Min and Max.
/// @ingroup valid_if
template <typename T, typename C, C Min, C Max>
using valid_if_between_c = valid_if<T, valid_if_btwn_policy<T, C, Min, Max>>;

/// @brief Specialization of valid_if, for values valid if between Min and Max.
/// @ingroup valid_if
/// @see valid_if_between_0_1
/// @see valid_if_less_than
/// @see valid_if_within_limits
template <typename T, T Min, T Max>
using valid_if_between = valid_if_between_c<T, T, Min, Max>;

} // namespace eagine

#endif // EAGINE_VALID_IF_BETWEEN_HPP
