/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef EAGINE_MATH_SIGN_HPP
#define EAGINE_MATH_SIGN_HPP

#include <type_traits>

namespace eagine::math {
//------------------------------------------------------------------------------
/// @brief Class representing a positive or negative numeric sign.
/// @ingroup math
///
/// Instances of this class can be multiplied to values of type @p T.
template <typename T>
class sign {
public:
    /// @brief Alias for sign class.
    using type = sign;

    /// @brief Alias for the value type @p T.
    using value_type = T;

    /// @brief Default constructor (constructs a positive sign).
    constexpr sign() noexcept = default;

    /// @brief Construction with explicit specitication of the sign.
    constexpr explicit sign(bool pos) noexcept
      : _positive{pos} {}

    /// @brief Construction taking the sign from the specified numeric @p value.
    template <
      typename X,
      typename = std::enable_if_t<!std::is_same_v<X, sign<T>>>>
    constexpr explicit sign(const X& value) noexcept
      : _positive{value >= X(0)} {}

    /// @brief Assignment taking the sign from the specified numeric @p value.
    template <
      typename X,
      typename = std::enable_if_t<!std::is_same_v<X, sign<T>>>>
    auto operator=(const X& value) noexcept -> auto& {
        _positive = (value >= X(0));
        return *this;
    }

    /// @brief Constructs a positive sign (plus).
    /// @see minus
    static constexpr auto plus() noexcept -> sign {
        return {true};
    }

    /// @brief Constructs a negative sign (minus).
    /// @see plus
    static constexpr auto minus() noexcept -> sign {
        return {false};
    }

    /// @brief Returns either 1 if this sign is positive or -1 if negative.
    operator T() const noexcept {
        return _positive ? T{1} : T{-1};
    }

    /// @brief Flip this sign from positive to negative or vice-versa.
    /// @see flipped
    auto flip() noexcept -> auto& {
        _positive = !_positive;
        return *this;
    }

    /// @brief Returns a new sign opposite to this sign.
    /// @see flip
    auto flipped() const noexcept -> sign {
        return {!_positive};
    }

    /// @brief Returns a new sign opposite to this sign.
    /// @see flipped
    /// @see flip
    auto operator-() const noexcept -> sign {
        return flipped();
    }

    /// @brief Returns a new sign opposite to this sign.
    /// @see flipped
    /// @see flip
    auto operator!() const noexcept -> sign {
        return flipped();
    }

private:
    bool _positive{true};
};
//------------------------------------------------------------------------------
} // namespace eagine::math

#endif // EAGINE_MATH_SIGN_HPP
