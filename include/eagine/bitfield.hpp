/**
 *  @file eagine/bitfield.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_BITFIELD_1509260923_HPP
#define EAGINE_BITFIELD_1509260923_HPP

#include "std/type_traits.hpp"

namespace eagine {

template <typename Bit>
class bitfield {
private:
    typedef std::underlying_type_t<Bit> BF;
    BF _bits;

public:
    typedef BF value_type;

    constexpr bitfield(void) noexcept
      : _bits(0) {
    }

    constexpr explicit bitfield(BF bits) noexcept
      : _bits(bits) {
    }

    constexpr bitfield(Bit _bit) noexcept
      : _bits(BF(_bit)) {
    }

    constexpr bitfield(Bit _bit_a, Bit _bit_b) noexcept
      : _bits(BF(_bit_a) | BF(_bit_b)) {
    }

    explicit constexpr inline operator bool(void) const noexcept {
        return _bits != BF(0);
    }

    constexpr inline bool operator!(void) const noexcept {
        return _bits == BF(0);
    }

    explicit constexpr inline operator value_type(void) const noexcept {
        return _bits;
    }

    constexpr inline bool has(Bit bit) const noexcept {
        return (_bits & BF(bit)) == BF(bit);
    }

    friend constexpr inline bool operator==(bitfield a, bitfield b) noexcept {
        return a._bits == b._bits;
    }

    friend constexpr inline bool operator!=(bitfield a, bitfield b) noexcept {
        return a._bits != b._bits;
    }

    friend constexpr inline bitfield operator|(
      bitfield a, bitfield b) noexcept {
        return bitfield(BF{a._bits} | BF{b._bits});
    }

    bitfield& operator|=(bitfield b) noexcept {
        _bits |= b._bits;
        return *this;
    }

    friend constexpr inline bitfield operator&(
      bitfield a, bitfield b) noexcept {
        return bitfield{a._bits & b._bits};
    }

    bitfield& operator&=(bitfield b) noexcept {
        _bits &= b._bits;
        return *this;
    }

    friend constexpr inline bitfield operator~(bitfield b) noexcept {
        return bitfield{~b._bits};
    }
};

} // namespace eagine

#endif // include guard
