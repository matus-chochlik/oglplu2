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
    T _bits;

    explicit constexpr inline enum_bits(T bits) noexcept
      : _bits(bits) {}
};

template <
  typename T,
  typename TL1,
  typename TL2,
  typename = std::enable_if_t<!mp_is_empty_v<mp_union_t<TL1, TL2>>>>
static constexpr inline enum_bits<T, mp_union_t<TL1, TL2>>
operator|(enum_value<T, TL1> a, enum_value<T, TL2> b) noexcept {
    return enum_bits<T, mp_union_t<TL1, TL2>>{a.value | b.value};
}

template <
  typename T,
  typename TL1,
  typename TL2,
  typename = std::enable_if_t<!mp_is_empty_v<mp_union_t<TL1, TL2>>>>
static constexpr inline enum_bits<T, mp_union_t<TL1, TL2>>
operator|(enum_bits<T, TL1> eb, enum_value<T, TL2> ev) noexcept {
    return enum_bits<T, mp_union_t<TL1, TL2>>{eb._bits | ev.value};
}
//------------------------------------------------------------------------------
template <typename EnumClass>
struct enum_bitfield {
    using value_type = typename EnumClass::value_type;

    value_type _value;

    constexpr inline enum_bitfield() noexcept
      : _value(0) {}

    explicit constexpr inline enum_bitfield(value_type value) noexcept
      : _value(value) {}

    constexpr inline enum_bitfield(EnumClass e) noexcept
      : _value(e._value) {}

    template <
      typename Classes,
      typename = std::enable_if_t<mp_contains_v<Classes, EnumClass>>>
    constexpr inline enum_bitfield(enum_value<value_type, Classes> ev) noexcept
      : _value(ev.value) {}

    template <
      typename Classes,
      typename = std::enable_if_t<mp_contains_v<Classes, EnumClass>>>
    constexpr inline enum_bitfield(enum_bits<value_type, Classes> eb) noexcept
      : _value(eb._bits) {}

    explicit constexpr inline operator value_type() const noexcept {
        return _value;
    }

    template <typename Classes>
    constexpr inline bool
    has(enum_value<value_type, Classes> ev) const noexcept {
        return (_value & ev.value) == ev.value;
    }

    friend constexpr inline bool
    operator==(enum_bitfield a, enum_bitfield b) noexcept {
        return a._value == b._value;
    }

    friend constexpr inline bool
    operator!=(enum_bitfield a, enum_bitfield b) noexcept {
        return a._value != b._value;
    }

    friend constexpr inline enum_bitfield
    operator|(enum_bitfield a, enum_bitfield b) noexcept {
        return enum_bitfield{a._value | b._value};
    }

    friend constexpr inline enum_bitfield
    operator&(enum_bitfield a, enum_bitfield b) noexcept {
        return enum_bitfield{a._value & b._value};
    }
};

} // namespace eagine

#endif // EAGINE_ENUM_BITFIELD_HPP
