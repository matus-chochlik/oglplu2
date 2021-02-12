/**
 *  @file eagine/enum_bitfield.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_ENUM_BITFIELD_HPP
#define EAGINE_ENUM_BITFIELD_HPP

#include "enum_class.hpp"

namespace eagine {
//------------------------------------------------------------------------------
template <typename T, typename ClassList>
struct enum_bits;

template <typename T, typename... Classes>
struct enum_bits<T, mp_list<Classes...>> {
    T _bits{0};

    explicit constexpr enum_bits(T bits) noexcept
      : _bits(bits) {}
};

template <
  typename T,
  typename TL1,
  typename TL2,
  typename = std::enable_if_t<!mp_is_empty_v<mp_union_t<TL1, TL2>>>>
static constexpr auto
operator|(enum_value<T, TL1> a, enum_value<T, TL2> b) noexcept {
    // NOLINTNEXTLINE(hicpp-signed-bitwise)
    return enum_bits<T, mp_union_t<TL1, TL2>>{a.value | b.value};
}

template <
  typename T,
  typename TL1,
  typename TL2,
  typename = std::enable_if_t<!mp_is_empty_v<mp_union_t<TL1, TL2>>>>
static constexpr auto
operator|(enum_bits<T, TL1> eb, enum_value<T, TL2> ev) noexcept {
    return enum_bits<T, mp_union_t<TL1, TL2>>{eb._bits | ev.value};
}
//------------------------------------------------------------------------------
template <typename EnumClass>
struct enum_bitfield {
    using value_type = typename EnumClass::value_type;

    value_type _value{0};

    constexpr enum_bitfield() noexcept = default;

    explicit constexpr enum_bitfield(value_type value) noexcept
      : _value{value} {}

    constexpr enum_bitfield(EnumClass e) noexcept
      : _value{e._value} {}

    template <
      typename Classes,
      typename = std::enable_if_t<mp_contains_v<Classes, EnumClass>>>
    constexpr enum_bitfield(enum_value<value_type, Classes> ev) noexcept
      : _value{ev.value} {}

    template <
      typename Classes,
      typename = std::enable_if_t<mp_contains_v<Classes, EnumClass>>>
    constexpr enum_bitfield(enum_bits<value_type, Classes> eb) noexcept
      : _value{eb._bits} {}

    explicit constexpr operator value_type() const noexcept {
        return _value;
    }

    auto add(EnumClass ev) noexcept -> auto& {
        _value |= ev._value; // NOLINT(hicpp-signed-bitwise)
        return *this;
    }

    auto clear(EnumClass ev) noexcept -> auto& {
        _value &= ~ev._value; // NOLINT(hicpp-signed-bitwise)
        return *this;
    }

    constexpr auto has(EnumClass ev) const noexcept -> bool {
        // NOLINTNEXTLINE(hicpp-signed-bitwise)
        return (_value & ev._value) == ev._value;
    }

    friend constexpr auto operator==(enum_bitfield a, enum_bitfield b) noexcept {
        return a._value == b._value;
    }

    friend constexpr auto operator!=(enum_bitfield a, enum_bitfield b) noexcept {
        return a._value != b._value;
    }

    friend constexpr auto operator|(enum_bitfield a, enum_bitfield b) noexcept {
        return enum_bitfield{value_type(a._value) | value_type(b._value)};
    }

    friend constexpr auto operator&(enum_bitfield a, enum_bitfield b) noexcept {
        return enum_bitfield{value_type(a._value) & value_type(b._value)};
    }
};

} // namespace eagine

#endif // EAGINE_ENUM_BITFIELD_HPP
