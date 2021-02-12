/// @file eagine/indexed_enum.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_INDEXED_ENUM_HPP
#define EAGINE_INDEXED_ENUM_HPP

#include "assert.hpp"

namespace eagine {

template <typename T, T Base, unsigned LibId>
struct indexed_enum_base {};

template <typename T, unsigned LibId>
struct any_indexed_enum_value;

template <typename T, T Base, unsigned LibId>
struct indexed_enum_value {
    using value_type = T;
    static constexpr const unsigned lib_id = LibId;
    static constexpr const T base_value = Base;

    unsigned _index;

    indexed_enum_value() = default;

    constexpr indexed_enum_value(indexed_enum_base<T, Base, LibId>) noexcept
      : _index(0u) {}

    constexpr indexed_enum_value(
      const any_indexed_enum_value<T, LibId>& aiev) noexcept
      : _index(aiev._index) {
        EAGINE_ASSERT(aiev._base_id == Base);
    }

    // this constructor is used by the operator+(indexed_enum_value, index)
    constexpr indexed_enum_value(unsigned idx, int) noexcept
      : _index(idx) {}

    explicit constexpr indexed_enum_value(T value) noexcept
      : _index(unsigned(value - Base)) {}

    explicit constexpr operator value_type() const noexcept {
        return value_type(Base + _index);
    }

    friend constexpr bool
    operator==(indexed_enum_value a, indexed_enum_value b) noexcept {
        return a._index == b._index;
    }

    friend constexpr bool
    operator!=(indexed_enum_value a, indexed_enum_value b) noexcept {
        return a._index != b._index;
    }

    friend constexpr bool
    operator<(indexed_enum_value a, indexed_enum_value b) noexcept {
        return a._index < b._index;
    }

    static constexpr T base() noexcept {
        return Base;
    }

    constexpr unsigned index() const noexcept {
        return _index;
    }
};

template <typename T, T Base, unsigned LibId>
static inline indexed_enum_value<T, Base, LibId>
operator+(indexed_enum_base<T, Base, LibId>, unsigned index) noexcept {
    return indexed_enum_value<T, Base, LibId>{index, 0};
}

template <typename T, unsigned LibId>
struct any_indexed_enum_value {
    unsigned _index{0u};
    T _base_id;

    constexpr any_indexed_enum_value() noexcept
      : _base_id(~T(0)) {}

    template <T Base>
    constexpr any_indexed_enum_value(
      indexed_enum_value<T, Base, LibId> iec) noexcept
      : _index(iec._index)
      , _base_id(Base) {}

    explicit constexpr operator bool() const noexcept {
        return _base_id != ~T(0);
    }

    friend constexpr bool
    operator==(any_indexed_enum_value a, any_indexed_enum_value b) noexcept {
        return (a._index == b._index) && (a._base_id == b._base_id);
    }

    friend constexpr bool
    operator!=(any_indexed_enum_value a, any_indexed_enum_value b) noexcept {
        return (a._index != b._index) || (a._base_id |= b._base_id);
    }

    constexpr T base() const noexcept {
        return _base_id;
    }

    constexpr unsigned index() const noexcept {
        return _index;
    }
};

template <typename T, unsigned LibId>
static constexpr bool same_enum_class(
  any_indexed_enum_value<T, LibId> a,
  any_indexed_enum_value<T, LibId> b) noexcept {
    return a._base_id == b._base_id;
}

} // namespace eagine

#endif // EAGINE_INDEXED_ENUM_HPP
