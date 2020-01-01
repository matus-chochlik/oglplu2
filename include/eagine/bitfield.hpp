/**
 *  @file eagine/bitfield.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_BITFIELD_HPP
#define EAGINE_BITFIELD_HPP

#include <type_traits>

namespace eagine {

template <typename Bit>
class bitfield {
private:
    using BF = std::make_unsigned_t<std::underlying_type_t<Bit>>;
    BF _bits;

public:
    using value_type = BF;

    constexpr bitfield() noexcept
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

    explicit constexpr inline operator bool() const noexcept {
        return _bits != BF(0);
    }

    constexpr inline bool operator!() const noexcept {
        return _bits == BF(0);
    }

    explicit constexpr inline operator value_type() const noexcept {
        return _bits;
    }

    constexpr inline bool is_empty() const noexcept {
        return _bits == BF(0);
    }

    constexpr inline bool has(Bit bit) const noexcept {
        return (_bits & BF(bit)) == BF(bit);
    }

    constexpr inline bool has_only(Bit bit) const noexcept {
        return _bits == BF(bit);
    }

    constexpr inline bool has_at_most(Bit bit) const noexcept {
        return is_empty() || has_only(bit);
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

#endif // EAGINE_BITFIELD_HPP
