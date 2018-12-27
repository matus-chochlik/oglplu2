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

namespace eagine {
namespace math {
//------------------------------------------------------------------------------
template <typename T>
class sign {
public:
    using type = sign;

    using value_type = T;

    constexpr sign() noexcept = default;

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

    sign flipped() noexcept {
        return {!_positive};
    }

    sign operator!() const noexcept {
        return flipped();
    }

private:
    constexpr sign(bool pos) noexcept
      : _positive{pos} {
    }

    bool _positive{true};
};
//------------------------------------------------------------------------------
} // namespace math
} // namespace eagine

#endif // EAGINE_MATH_SIGN_HPP
