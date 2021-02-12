/// @file eagine/valid_if/within_limits.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_VALID_IF_WITHIN_LIMITS_HPP
#define EAGINE_VALID_IF_WITHIN_LIMITS_HPP

#include "../is_within_limits.hpp"
#include "decl.hpp"

namespace eagine {

// is withing limits
template <typename Dst, typename Src>
struct valid_if_within_limits_policy {
    constexpr auto operator()(Src value) const noexcept {
        return is_within_limits<Dst>(value);
    }

    struct do_log {
        template <typename X, typename = disable_if_same_t<X, do_log>>
        constexpr do_log(X&&) noexcept {}

        template <typename Log>
        void operator()(Log& log, const Src& v) const {
            log << "Value " << v << ", "
                << "not within limits of destination type "
                << "is invalid";
        }
    };
};

template <typename Dst, typename Src>
using valid_if_within_limits =
  valid_if<Src, valid_if_within_limits_policy<Dst, Src>>;

} // namespace eagine

#endif // EAGINE_VALID_IF_WITHIN_LIMITS_HPP
