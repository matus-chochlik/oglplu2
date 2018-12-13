/**
 *  @file eagine/combined_enum.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_COMBINED_ENUM_1509260923_HPP
#define EAGINE_COMBINED_ENUM_1509260923_HPP

#include "enum_class.hpp"
#include "indexed_enum.hpp"
#include "std/type_traits.hpp"

namespace eagine {

template <typename Enum, typename IndexedEnum>
struct combined_enum_value {
private:
    static_assert(
      Enum::lib_id == IndexedEnum::lib_id &&
        std::is_same_v<
          typename Enum::value_type,
          typename IndexedEnum::value_type>,
      "");

public:
    using value_type = typename Enum::value_type;
    static constexpr const unsigned lib_id = Enum::lib_id;
    static constexpr const value_type base_value = IndexedEnum::base_value;

    value_type _value;

    combined_enum_value() = default;

    template <
      typename Classes,
      typename = std::enable_if_t<mp_contains<Classes, Enum>::value>>
    constexpr inline combined_enum_value(
      enum_value<value_type, Classes> ev) noexcept
      : _value(ev.value) {
    }

    constexpr inline combined_enum_value(
      indexed_enum_base<value_type, base_value, lib_id>) noexcept
      : _value(base_value) {
    }

    constexpr inline combined_enum_value(
      indexed_enum_value<value_type, base_value, lib_id> v) noexcept
      : _value(value_type(base_value + v._index)) {
    }

    explicit constexpr inline combined_enum_value(value_type value) noexcept
      : _value(value) {
    }

    explicit constexpr inline operator value_type() const noexcept {
        return _value;
    }

    explicit operator Enum() const noexcept {
        return Enum(_value);
    }

    explicit operator IndexedEnum() const noexcept {
        return IndexedEnum(_value);
    }

    friend constexpr inline bool operator==(
      combined_enum_value a, combined_enum_value b) noexcept {
        return a._value == b._value;
    }

    friend constexpr inline bool operator!=(
      combined_enum_value a, combined_enum_value b) noexcept {
        return a._value != b._value;
    }

    friend constexpr inline bool operator<(
      combined_enum_value a, combined_enum_value b) noexcept {
        return a._value < b._value;
    }
};

} // namespace eagine

#endif // include guard
