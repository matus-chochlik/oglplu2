/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_COUNT_HPP
#define EAGINE_COUNT_HPP

namespace eagine {

/// @brief Class counting invocation of its call operator.
/// @ingroup functional
template <typename Int = int>
class count_t {
public:
    /// @brief The value type alias.
    using value_type = Int;

    /// @brief Default construction, initializes counter to zero.
    constexpr count_t() noexcept = default;

    /// @brief Returns the current value on the counter.
    constexpr value_type value() const noexcept {
        return _c;
    }

    /// @brief Implicit conversion to value type, returns counter value.
    /// @see value
    constexpr operator value_type() const noexcept {
        return _c;
    }

    /// @brief Call operator incrementing the counter state.
    /// @see value
    template <typename... P>
    constexpr void operator()(const P&...) noexcept {
        ++_c;
    }

private:
    Int _c{Int(0)};
};

} // namespace eagine

#endif // EAGINE_COUNT_HPP
