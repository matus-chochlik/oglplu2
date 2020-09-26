/**
 *  @file eagine/math/sign.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_MATH_SIGN_HPP
#define EAGINE_MATH_SIGN_HPP

#include <type_traits>

namespace eagine::math {
//------------------------------------------------------------------------------
template <typename T>
class sign {
public:
    using type = sign;

    using value_type = T;

    constexpr sign() noexcept = default;

    constexpr explicit sign(bool pos) noexcept
      : _positive{pos} {}

    template <
      typename X,
      typename = std::enable_if_t<!std::is_same_v<X, sign<T>>>>
    constexpr explicit sign(const X& value) noexcept
      : _positive{value >= X(0)} {}

    static constexpr auto plus() noexcept -> sign {
        return {true};
    }

    static constexpr auto minus() noexcept -> sign {
        return {false};
    }

    template <
      typename X,
      typename = std::enable_if_t<!std::is_same_v<X, sign<T>>>>
    auto operator=(const X& value) noexcept -> auto& {
        _positive = (value >= X(0));
        return *this;
    }

    operator T() const noexcept {
        return _positive ? T{1} : T{-1};
    }

    auto flip() noexcept -> auto& {
        _positive = !_positive;
        return *this;
    }

    auto flipped() const noexcept -> sign {
        return {!_positive};
    }

    auto operator-() const noexcept -> sign {
        return flipped();
    }

    auto operator!() const noexcept -> sign {
        return flipped();
    }

private:
    bool _positive{true};
};
//------------------------------------------------------------------------------
} // namespace eagine::math

#endif // EAGINE_MATH_SIGN_HPP
