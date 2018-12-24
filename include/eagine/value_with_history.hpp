/**
 *  @file eagine/value_with_history.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_VALUE_WITH_HISTORY_HPP
#define EAGINE_VALUE_WITH_HISTORY_HPP

#include "valid_if/decl.hpp"
#include <cmath>
#include <utility>

namespace eagine {

template <typename T>
static constexpr inline bool value_with_history_changed(
  const T& a, const T& b) noexcept {
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wfloat-equal"
#endif
    return a != b;
#ifdef __clang__
#pragma clang diagnostic pop
#endif
}

template <typename T>
static constexpr inline auto value_with_history_delta(
  const T& new_value, const T& old_value) noexcept {
    return new_value - old_value;
}

static constexpr inline int value_with_history_delta(
  bool new_value, bool old_value) noexcept {
    return int(new_value) - int(old_value);
}

template <typename T>
static constexpr inline auto value_with_history_distance(
  const T& new_value, const T& old_value) noexcept {
    using std::abs;
    return abs(value_with_history_delta(new_value, old_value));
}

template <typename T, std::size_t N>
class value_with_history_storage {
private:
    T _values[N];

public:
    constexpr inline value_with_history_storage() = default;

    template <typename... I>
    constexpr inline value_with_history_storage(I&&... initial)
      : _values{T(initial)...} {
    }

    value_with_history_storage(const T& initial) noexcept {
        for(std::size_t i = 0; i < N; ++i) {
            _values[i] = initial;
        }
    }

    constexpr inline const T& get(std::size_t i) const noexcept {
        return _values[i];
    }

    inline void set(std::size_t i, const T& value) noexcept {
        _values[i] = value;
    }

    void make_history() noexcept {
        for(std::size_t i = 1; i < N; ++i) {
            _values[N - i] = _values[N - i - 1];
        }
    }

    void sync() noexcept {
        for(std::size_t i = 1; i < N; ++i) {
            _values[i] = _values[0];
        }
    }
};

template <typename Transform, typename... T, std::size_t N>
static inline auto transform_stored_values(
  Transform transform_op, const value_with_history_storage<T, N>&... v) {
    value_with_history_storage<
      decltype(std::declval<Transform>()(std::declval<T>()...)),
      N>
      result;

    for(std::size_t i = 0; i < N; ++i) {
        result.set(i, transform_op(v.get(i)...));
    }
    return result;
}

template <typename Delta, typename T, std::size_t N>
static inline auto differentiate_stored_values(
  Delta delta_op, const value_with_history_storage<T, N>& v) {
    value_with_history_storage<
      decltype(std::declval<Delta>()(std::declval<T>(), std::declval<T>())),
      N - 1>
      result;

    for(std::size_t i = 1; i < N; ++i) {
        result.set(i - 1, delta_op(v.get(i - 1), v.get(i)));
    }
    return result;
}

template <typename U, typename T, std::size_t N>
static inline auto convert_stored_values(
  const value_with_history_storage<T, N>& storage) {
    return transform_stored_values([](const T& v) { return U(v); }, storage);
}

template <typename T, std::size_t N>
class value_with_history {
private:
    static_assert(N >= 2, "at least two values are required");
    value_with_history_storage<T, N> _values;

protected:
    value_with_history_storage<T, N>& values() noexcept {
        return _values;
    }

    bool _update_value(const T& new_value) noexcept {
        values().make_history();

        if(value_with_history_changed(values().get(0), new_value)) {
            values().set(0, new_value);
            return true;
        }
        return false;
    }

    bool _advance_value(const T& delta_value) noexcept {
        values().make_history();
        values().set(0, values().get(0) + delta_value);
        return true;
    }

    value_with_history() = default;

    inline explicit value_with_history(const T& initial) noexcept
      : _values(initial) {
    }

public:
    inline explicit value_with_history(
      const value_with_history_storage<T, N>& storage)
      : _values(storage) {
    }

    template <typename... I>
    constexpr inline value_with_history(I&&... initial)
      : _values{std::forward<I>(initial)...} {
    }

    const value_with_history_storage<T, N>& values() const noexcept {
        return _values;
    }

    auto get() const noexcept {
        return values().get(0);
    }

    auto value() const noexcept {
        return values().get(0);
    }

    auto old_value() const noexcept {
        return values().get(1);
    }

    auto value(bool old) const noexcept {
        return old ? old_value() : value();
    }

    operator T() const noexcept {
        return value();
    }

    template <typename U, typename... P>
    operator valid_if<U, P...>() const noexcept {
        return {U(value())};
    }

    auto delta() const noexcept {
        return value_with_history_delta(value(), old_value());
    }

    auto deltas() const noexcept {
        return value_with_history<decltype(delta()), N - 1>(
          differentiate_stored_values(
            [](const T& n, const T& o) {
                return value_with_history_delta(n, o);
            },
            values()));
    }

    auto distance() const noexcept {
        return value_with_history_distance(value(), old_value());
    }

    bool changed() const noexcept {
        return value_with_history_changed(old_value(), value());
    }

    template <typename U>
    auto as() const {
        return value_with_history<U, N>(convert_stored_values<U>(values()));
    }

    void sync() {
        this->values().sync();
    }
};

template <typename Transform, typename... T, std::size_t N>
static inline auto transform(
  Transform transform_op, const value_with_history<T, N>&... v) {
    return value_with_history<
      decltype(std::declval<Transform>()(std::declval<T>()...)),
      N>(transform_stored_values(transform_op, v.values()...));
}

template <typename T1, typename T2, std::size_t N>
static inline auto operator*(
  const value_with_history<T1, N>& v1,
  const value_with_history<T2, N>& v2) noexcept {
    return transform(
      [](const T1& t1, const T2& t2) { return t1 * t2; }, v1, v2);
}

template <typename T1, typename T2, std::size_t N>
static inline auto operator/(
  const value_with_history<T1, N>& v1,
  const value_with_history<T2, N>& v2) noexcept {
    return transform(
      [](const T1& t1, const T2& t2) { return t1 / t2; }, v1, v2);
}

template <typename T, std::size_t N>
class variable_with_history : public value_with_history<T, N> {
public:
    constexpr inline variable_with_history(const T& initial) noexcept
      : value_with_history<T, N>(initial) {
    }

    bool assign(const T& new_value) {
        return this->_update_value(new_value);
    }

    bool advance(const T& delta_value) {
        return this->_advance_value(delta_value);
    }
};

template <typename T, typename... P, std::size_t N>
class variable_with_history<valid_if<T, P...>, N>
  : public value_with_history<T, N> {
public:
    constexpr inline variable_with_history(
      const valid_if<T, P...>& initial) noexcept
      : value_with_history<T, N>(initial.value()) {
    }

    bool assign(const valid_if<T, P...>& new_value) {
        return this->_update_value(new_value.value());
    }

    bool advance(const valid_if<T, P...>& delta_value) {
        return this->_advance_value(delta_value.value());
    }
};

} // namespace eagine

#endif // EAGINE_VALUE_WITH_HISTORY_HPP
