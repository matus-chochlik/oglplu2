/// @file eagine/value_tracker.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_VALUE_TRACKER_HPP
#define EAGINE_VALUE_TRACKER_HPP

#include <type_traits>

namespace eagine {
//------------------------------------------------------------------------------
template <typename T, T D>
struct value_change_divider {
    auto operator()(const T& value) noexcept -> T {
        return T(value / D);
    }
};
//------------------------------------------------------------------------------
template <typename T, typename Transform>
class value_change_tracker : Transform {
    static_assert(std::is_arithmetic_v<T>);

    auto _transform() noexcept -> Transform& {
        return *this;
    }

public:
    value_change_tracker() noexcept = default;

    value_change_tracker(T initial) noexcept
      : _prev{std::move(initial)} {}

    value_change_tracker(T initial, Transform transf) noexcept
      : Transform(std::move(transf))
      , _prev{std::move(initial)} {}

    auto transform(const T& value) noexcept {
        return _transform()(value);
    }

    auto get() const noexcept -> const T& {
        return _prev;
    }

    auto has_changed(const T& next) noexcept -> bool {
        if(transform(_prev) != transform(next)) {
            _prev = next;
            return true;
        }
        return false;
    }

private:
    T _prev{0};
};
//------------------------------------------------------------------------------
template <typename T, T D>
using value_change_div_tracker =
  value_change_tracker<T, value_change_divider<T, D>>;
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_VALUE_TRACKER_HPP
