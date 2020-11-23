/**
 *  @file eagine/animated_value.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_ANIMATED_VALUE_HPP
#define EAGINE_ANIMATED_VALUE_HPP

#include "math/functions.hpp"
#include "valid_if/positive.hpp"
#include <type_traits>

namespace eagine {
//------------------------------------------------------------------------------
template <typename T, typename F, typename S = float>
class animated_value {
public:
    animated_value() = default;

    animated_value(const T& initial)
      : _curr{initial}
      , _next{initial} {}

    auto set(T value, valid_if_positive<F> duration, S slope) -> auto& {
        _curr = _next;
        _next = value;
        _duration = extract(duration);
        _phase = F(0);
        _slope = slope;
        return *this;
    }

    auto set(T value, valid_if_positive<F> duration) -> auto& {
        return set(value, duration, 2);
    }

    auto get() const -> T {
        return math::blend(
          _next,
          _curr,
          math::sigmoid01(math::clamp(_phase / _duration, 0, 1), _slope));
    }

    auto update(F deltaT) -> auto& {
        _phase += deltaT;
        return *this;
    }

    auto is_done() const noexcept -> bool {
        return _phase >= _duration;
    }

private:
    T _curr{0};
    T _next{0};
    F _duration{1};
    F _phase{_duration};
    S _slope{2};
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif
