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

namespace eagine {
namespace math {
//------------------------------------------------------------------------------
template <typename T>
class sign {
public:
    using type = sign;

    using value_type = T;

    constexpr sign() noexcept = default;

    constexpr sign(bool pos) noexcept
      : _positive{pos} {
    }

    template <
      typename X,
      typename = std::enable_if_t<std::is_same_v<X, sign<T>>>>
    constexpr sign(const X& value) noexcept
      : _positive{value >= X(0)} {
    }

    static constexpr inline sign plus() noexcept {
        return {true};
    }

    static constexpr inline sign minus() noexcept {
        return {false};
    }

    operator T() const noexcept {
        return _positive ? T{1} : T{-1};
    }

    sign& flip() noexcept {
        _positive = !_positive;
        return *this;
    }

    sign flipped() const noexcept {
        return {!_positive};
    }

    sign operator-() const noexcept {
        return flipped();
    }

    sign operator!() const noexcept {
        return flipped();
    }

private:
    bool _positive{true};
};
//------------------------------------------------------------------------------
} // namespace math
} // namespace eagine

#endif // EAGINE_MATH_SIGN_HPP
