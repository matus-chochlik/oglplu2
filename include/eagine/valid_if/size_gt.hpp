/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_VALID_IF_SIZE_GT_HPP
#define EAGINE_VALID_IF_SIZE_GT_HPP

#include "in_class.hpp"

namespace eagine {

/// @brief Policy class for containers valid if their size is larger than specified number.
/// @ingroup valid_if
template <typename C, typename T>
struct valid_if_size_gt_policy {

    /// @brief Indicates value validity, true if c.size() > s.
    auto operator()(const C& c, T s) const {
        return c.size() > s;
    }

    struct do_log {
        template <typename X, typename = disable_if_same_t<X, do_log>>
        constexpr do_log(X&&) noexcept {}

        template <typename Log>
        void operator()(Log& log, const C& c, const T& s) const {
            log << "Size " << c.size() << ", "
                << "not greater than value " << s << " is invalid";
        }
    };
};

/// @brief Specialization of valid_if, for values valid if they contain more than n items.
/// @ingroup valid_if
/// @see valid_if_not_empty
template <typename C, typename T>
using valid_if_size_gt = in_class_valid_if<C, T, valid_if_size_gt_policy<C, T>>;

} // namespace eagine

#endif // EAGINE_VALID_IF_SIZE_GT_HPP
