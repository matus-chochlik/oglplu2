/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_VALUE_WITH_HISTORY_HPP
#define EAGINE_VALUE_WITH_HISTORY_HPP

#include "compare.hpp"
#include "integer_range.hpp"
#include "valid_if/decl.hpp"
#include <algorithm>
#include <array>
#include <cmath>
#include <utility>

namespace eagine {
//------------------------------------------------------------------------------
template <typename T>
static constexpr auto
value_with_history_changed(const T& a, const T& b) noexcept -> bool {
    return !are_equal(a, b);
}

template <typename T>
static constexpr auto
value_with_history_delta(const T& new_value, const T& old_value) noexcept {
    return new_value - old_value;
}

static constexpr auto
value_with_history_delta(bool new_value, bool old_value) noexcept -> int {
    return int(new_value) - int(old_value);
}

template <typename T>
static constexpr auto
value_with_history_distance(const T& new_value, const T& old_value) noexcept {
    using std::abs;
    return abs(value_with_history_delta(new_value, old_value));
}
//------------------------------------------------------------------------------
/// @brief Base storage class for values and variables with history.
/// @tparam T the type of the value
/// @tparam N the number of latest historical revisions of the stored value.
/// @ingroup value_history
/// @see value_with_history
/// @note Do not use this class directly.
///       Use value_with_history or variable_with_history.
template <typename T, std::size_t N>
class value_with_history_storage {
public:
    /// @brief Default constructor.
    constexpr value_with_history_storage() = default;

    /// @brief Initializes the individual revisions of the value.
    template <typename... I, typename = std::enable_if_t<sizeof...(I) == N>>
    constexpr value_with_history_storage(I&&... initial)
      : _values{T(initial)...} {}

    /// @brief Initializes all revisions with the same initial value.
    constexpr value_with_history_storage(const T& initial) noexcept {
        std::fill(_values.begin(), _values.end(), initial);
    }

    /// @brief Returns an iterator to the first (newest) value.
    auto begin() const noexcept {
        return _values.begin();
    }

    /// @brief Returns an iterator past the last (oldest) value.
    auto end() const noexcept {
        return _values.end();
    }

    /// @brief Returns the i-th revision of the stored value (0 = current value).
    constexpr auto get(std::size_t i) const noexcept -> const T& {
        EAGINE_ASSERT(i < N);
        return _values[i];
    }

    /// @brief Sets the i-th revision of the stored value (0 = current value).
    void set(std::size_t i, const T& value) noexcept {
        EAGINE_ASSERT(i < N);
        _values[i] = value;
    }

    /// @brief Move the stored revisions by one, to make place for new value.
    /// @see sync
    void make_history() noexcept {
        for(const auto i : integer_range(1U, N)) {
            _values[N - i] = std::move(_values[N - i - 1]);
        }
    }

    /// @brief Synchronize the historic revisions to the current value.
    /// @see make_history
    void sync() noexcept {
        std::fill(_values.begin() + 1, _values.end(), _values.front());
    }

private:
    std::array<T, N> _values{};
};
//------------------------------------------------------------------------------
template <typename Transform, typename... T, std::size_t N>
static inline auto transform_stored_values(
  Transform transform_op,
  const value_with_history_storage<T, N>&... v) {
    value_with_history_storage<
      decltype(std::declval<Transform>()(std::declval<T>()...)),
      N>
      result;

    for(const auto i : integer_range(N)) {
        result.set(i, transform_op(v.get(i)...));
    }
    return result;
}
//------------------------------------------------------------------------------
template <typename Delta, typename T, std::size_t N>
static inline auto differentiate_stored_values(
  Delta delta_op,
  const value_with_history_storage<T, N>& v) {
    value_with_history_storage<
      decltype(std::declval<Delta>()(std::declval<T>(), std::declval<T>())),
      N - 1>
      result;

    for(const auto i : integer_range(1U, N)) {
        result.set(i - 1, delta_op(v.get(i - 1), v.get(i)));
    }
    return result;
}
//------------------------------------------------------------------------------
template <typename U, typename T, std::size_t N>
static inline auto
convert_stored_values(const value_with_history_storage<T, N>& storage) {
    return transform_stored_values([](const T& v) { return U(v); }, storage);
}
//------------------------------------------------------------------------------
/// @brief Class for read-only values with history.
/// @tparam T the type of the value
/// @tparam N the number of latest historical revisions of the stored value.
/// @ingroup value_history
template <typename T, std::size_t N>
class value_with_history {
public:
    explicit value_with_history(const value_with_history_storage<T, N>& storage)
      : _values{storage} {}

    /// @brief Initialized the individual revisions of this value.
    template <typename... I>
    constexpr value_with_history(I&&... initial)
      : _values{std::forward<I>(initial)...} {}

    /// @brief Returns a reference to the value storage.
    auto values() const noexcept -> const value_with_history_storage<T, N>& {
        return _values;
    }

    /// @brief Returns an iterator to the first (newest) value.
    auto begin() const noexcept {
        return values().begin();
    }

    /// @brief Returns an iterator past the last (oldest) value.
    auto end() const noexcept {
        return values().end();
    }

    /// @brief Returns the current revision of the value.
    /// @see value
    auto get() const noexcept {
        return values().get(0);
    }

    /// @brief Returns the current revision of the value.
    /// @see get
    /// @see old_value
    auto value() const noexcept {
        return values().get(0);
    }

    /// @brief Returns the previous revision of the value.
    /// @see get
    /// @see value
    auto old_value() const noexcept {
        return values().get(1);
    }

    /// @brief Returns the current or previous revision of the value.
    /// @see value
    /// @see old_value
    auto value(bool old) const noexcept {
        return old ? old_value() : value();
    }

    /// @brief Returns the current revision of the value.
    /// @see value
    operator T() const noexcept {
        return value();
    }

    template <typename U, typename... P>
    operator valid_if<U, P...>() const noexcept {
        return {U(value())};
    }

    /// @brief Returns the difference between the current and the previous revision.
    auto delta() const noexcept {
        return value_with_history_delta(value(), old_value());
    }

    /// @brief Returns the differences between the adjacent revisions.
    auto deltas() const noexcept {
        return value_with_history<decltype(delta()), N - 1>(
          differentiate_stored_values(
            [](const T& n, const T& o) {
                return value_with_history_delta(n, o);
            },
            values()));
    }

    /// @brief Returns the distance between the current and the previous revisions.
    auto distance() const noexcept {
        return value_with_history_distance(value(), old_value());
    }

    /// @brief Indicates if the current and previous revisions differ.
    auto changed() const noexcept -> bool {
        return value_with_history_changed(old_value(), value());
    }

    /// @brief Returns this with the values cast to new type @p U.
    template <typename U>
    auto as() const {
        return value_with_history<U, N>(convert_stored_values<U>(values()));
    }

    /// @brief Synchronize the historic revisions to the current value.
    /// @see make_history
    void sync() {
        this->values().sync();
    }

protected:
    auto values() noexcept -> value_with_history_storage<T, N>& {
        return _values;
    }

    auto _update_value(const T& new_value) noexcept -> bool {

        if(value_with_history_changed(values().get(0), new_value)) {
            values().make_history();
            values().set(0, new_value);
            return true;
        }
        return false;
    }

    auto _advance_value(const T& delta_value) noexcept -> bool {
        values().make_history();
        values().set(0, values().get(0) + delta_value);
        return true;
    }

    value_with_history() = default;

    explicit value_with_history(const T& initial) noexcept
      : _values(initial) {}

private:
    static_assert(N >= 2, "at least two values are required");
    value_with_history_storage<T, N> _values;
};
//------------------------------------------------------------------------------
template <typename Transform, typename... T, std::size_t N>
static inline auto
transform(Transform transform_op, const value_with_history<T, N>&... v) {
    return value_with_history<
      decltype(std::declval<Transform>()(std::declval<T>()...)),
      N>(transform_stored_values(transform_op, v.values()...));
}
//------------------------------------------------------------------------------
template <typename T1, typename T2, std::size_t N>
static inline auto operator*(
  const value_with_history<T1, N>& v1,
  const value_with_history<T2, N>& v2) noexcept {
    return transform(
      [](const T1& t1, const T2& t2) { return t1 * t2; }, v1, v2);
}
//------------------------------------------------------------------------------
template <typename T1, typename T2, std::size_t N>
static inline auto operator/(
  const value_with_history<T1, N>& v1,
  const value_with_history<T2, N>& v2) noexcept {
    return transform(
      [](const T1& t1, const T2& t2) { return t1 / t2; }, v1, v2);
}
//------------------------------------------------------------------------------
/// @brief Class for mutable variables with history.
/// @tparam T the type of the value
/// @tparam N the number of latest historical revisions of the stored value.
/// @ingroup value_history
template <typename T, std::size_t N>
class variable_with_history : public value_with_history<T, N> {
public:
    /// @brief Default constructor.
    constexpr variable_with_history() noexcept = default;

    /// @brief Initialize the all revisions to the initial value.
    constexpr variable_with_history(const T& initial) noexcept
      : value_with_history<T, N>(initial) {}

    /// @brief Returns this as a const reference to the base value with history.
    auto as_value() const noexcept -> const value_with_history<T, N>& {
        return *this;
    }

    /// @brief Shifts the revisions and assigns a new value.
    auto assign(const T& new_value) -> bool {
        return this->_update_value(new_value);
    }

    /// @brief Shifts the revisions and assigns a new value.
    auto operator=(const T& new_value) -> auto& {
        assign(new_value);
        return *this;
    }

    /// @brief Shifts the revisions and advanced the current value by given delta.
    auto advance(const T& delta_value) -> bool {
        return this->_advance_value(delta_value);
    }
};
//------------------------------------------------------------------------------
template <typename T, typename... P, std::size_t N>
class variable_with_history<valid_if<T, P...>, N>
  : public value_with_history<T, N> {
public:
    constexpr variable_with_history(const valid_if<T, P...>& initial) noexcept
      : value_with_history<T, N>(initial.value()) {}

    auto assign(const valid_if<T, P...>& new_value) -> bool {
        return this->_update_value(new_value.value());
    }

    auto operator=(const T& new_value) -> auto& {
        assign(new_value);
        return *this;
    }

    auto advance(const valid_if<T, P...>& delta_value) -> bool {
        return this->_advance_value(delta_value.value());
    }
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_VALUE_WITH_HISTORY_HPP
