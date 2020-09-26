/**
 *  @file eagine/valid_if/lt_size_ge0.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_VALID_IF_LT_SIZE_GE0_HPP
#define EAGINE_VALID_IF_LT_SIZE_GE0_HPP

#include "in_class.hpp"

namespace eagine {

// valid if greater than or equal to 0 and less than container.size()
template <typename T, typename C>
struct valid_if_lt_size_ge0_policy {
    auto operator()(T x, const C& c) const {
        return (T(0) <= x) && (x < c.size());
    }

    auto operator()(T x, const C& c, T o) const {
        return (T(0) <= x) && (x < c.size() - o);
    }

    struct do_log {
        template <typename X, typename = disable_if_same_t<X, do_log>>
        constexpr inline do_log(X&&) noexcept {}

        template <typename Log>
        void operator()(Log& log, const T& v, const C& c) const {
            log << "Value " << v << ", less than zero or "
                << "not less than c.size() = " << c.size() << " is invalid";
        }
    };
};

template <typename C, typename T>
using valid_if_lt_size_ge0 =
  in_class_valid_if<T, C, valid_if_lt_size_ge0_policy<T, C>>;

} // namespace eagine

#endif // EAGINE_VALID_IF_LT_SIZE_GE0_HPP
