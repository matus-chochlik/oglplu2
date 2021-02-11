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

/// @brief Type that can by constructed from single argument of any other type.
struct anything {
    /// @brief Default constructor.
    constexpr anything() noexcept = default;

    /// @brief Move constructor.
    constexpr anything(anything&&) noexcept = default;

    /// @brief Copy constructor.
    constexpr anything(const anything&) noexcept = default;

    /// @brief Move assignment operator.
    auto operator=(anything&&) noexcept -> anything& = default;

    /// @brief Copy assignment operator.
    auto operator=(const anything&) noexcept -> anything& = default;

    ~anything() noexcept = default;

    /// @brief Construction from any other type.
    template <typename Unused>
    constexpr anything(const Unused&) noexcept {}
};

} // namespace eagine

#endif // EAGINE_ANYTHING_HPP
