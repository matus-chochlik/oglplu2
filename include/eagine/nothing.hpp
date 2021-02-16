/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_NOTHING_HPP
#define EAGINE_NOTHING_HPP

namespace eagine {

/// @brief Class representing "none" / "nothing" values.
/// @ingroup type_utils
/// @see nothing
struct nothing_t {

    /// @brief Type alias to self.
    using type = nothing_t;

    /// @brief Constructible from any number and types of arguments.
    template <typename... T>
    constexpr nothing_t(T...) noexcept {}
};

/// @brief Constant of nothing_t type.
/// @ingroup type_utils
/// @see nothing_t
static constexpr nothing_t nothing = {};

} // namespace eagine

#endif // EAGINE_NOTHING_HPP
