/// @file
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
/// @brief Class tracking the changes in a potentially transformed value.
/// @ingroup functional
template <typename T, typename Transform>
class value_change_tracker : Transform {
    static_assert(std::is_arithmetic_v<T>);

public:
    /// @brief Default constructor.
    value_change_tracker() noexcept = default;

    /// @brief Constructor setting the initial value.
    value_change_tracker(T initial) noexcept
      : _prev{std::move(initial)} {}

    /// @brief Constructor setting the initial value and the transform.
    value_change_tracker(T initial, Transform transf) noexcept
      : Transform(std::move(transf))
      , _prev{std::move(initial)} {}

    /// @brief Transforms the specified value.
    auto transform(const T& value) noexcept {
        return _transform()(value);
    }

    /// @brief Returns the currently stored value.
    auto get() const noexcept -> const T& {
        return _prev;
    }

    /// @brief If the transformed current and values are different, stores next.
    auto has_changed(const T& next) noexcept -> bool {
        if(transform(_prev) != transform(next)) {
            _prev = next;
            return true;
        }
        return false;
    }

private:
    auto _transform() noexcept -> Transform& {
        return *this;
    }

    T _prev{0};
};
//------------------------------------------------------------------------------
/// @brief Transform class for value_change_tracker, dividing by the specified amount.
/// @ingroup functional
/// @relates value_change_tracker
template <typename T, T D>
struct value_change_divider {
    auto operator()(const T& value) noexcept -> T {
        return T(value / D);
    }
};
//------------------------------------------------------------------------------
/// @brief Alias for value tracker tracking changes by amount specified by @c D.
/// @ingroup functional
template <typename T, T D>
using value_change_div_tracker =
  value_change_tracker<T, value_change_divider<T, D>>;
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_VALUE_TRACKER_HPP
