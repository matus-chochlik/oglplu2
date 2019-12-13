/**
 *  @file eagine/eat_anything.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_EAT_ANYTHING_HPP
#define EAGINE_EAT_ANYTHING_HPP

namespace eagine {

struct eat_anything {
    constexpr eat_anything() noexcept = default;
    constexpr eat_anything(eat_anything&&) noexcept = default;
    constexpr eat_anything(const eat_anything&) noexcept = default;
    eat_anything& operator=(eat_anything&&) noexcept = default;
    eat_anything& operator=(const eat_anything&) noexcept = default;
    ~eat_anything() noexcept = default;

    template <typename Unused>
    constexpr eat_anything(const Unused&) noexcept {
    }
};

} // namespace eagine

#endif // EAGINE_EAT_ANYTHING_HPP
