/**
 *  @file eagine/anything.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_ANYTHING_HPP
#define EAGINE_ANYTHING_HPP

namespace eagine {

struct anything {
    constexpr anything() noexcept = default;
    constexpr anything(anything&&) noexcept = default;
    constexpr anything(const anything&) noexcept = default;
    anything& operator=(anything&&) noexcept = default;
    anything& operator=(const anything&) noexcept = default;
    ~anything() noexcept = default;

    template <typename Unused>
    constexpr anything(const Unused&) noexcept {}
};

} // namespace eagine

#endif // EAGINE_ANYTHING_HPP
