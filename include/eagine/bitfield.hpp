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
      : _bits(0) {}

    constexpr explicit bitfield(BF bits) noexcept
      : _bits(bits) {}

    constexpr bitfield(Bit _bit) noexcept
      : _bits(BF(_bit)) {}

    constexpr bitfield(Bit _bit_a, Bit _bit_b) noexcept
      : _bits(BF(_bit_a) | BF(_bit_b)) {}

    explicit constexpr inline operator bool() const noexcept {
        return _bits != BF(0);
    }

    explicit constexpr inline operator value_type() const noexcept {
        return _bits;
    }

    constexpr inline auto bits() const noexcept -> value_type {
        return _bits;
    }

    constexpr inline auto is_empty() const noexcept {
        return _bits == BF(0);
    }

    constexpr inline auto has(Bit bit) const noexcept {
        return (_bits & BF(bit)) == BF(bit);
    }

    constexpr inline auto has_only(Bit bit) const noexcept {
        return _bits == BF(bit);
    }

    constexpr inline auto has_at_most(Bit bit) const noexcept {
        return is_empty() || has_only(bit);
    }

    friend constexpr inline auto operator==(bitfield a, bitfield b) noexcept {
        return a._bits == b._bits;
    }

    friend constexpr inline auto operator!=(bitfield a, bitfield b) noexcept {
        return a._bits != b._bits;
    }

    friend constexpr inline auto operator|(bitfield a, bitfield b) noexcept
      -> bitfield {
        return bitfield(a._bits | b._bits);
    }

    auto operator|=(bitfield b) noexcept -> bitfield& {
        _bits |= b._bits;
        return *this;
    }

    friend constexpr inline auto operator&(bitfield a, bitfield b) noexcept
      -> bitfield {
        return bitfield(a._bits & b._bits);
    }

    auto operator&=(bitfield b) noexcept -> bitfield& {
        _bits &= b._bits;
        return *this;
    }

    friend constexpr inline auto operator~(bitfield b) noexcept -> bitfield {
        return bitfield{BF(~b._bits)};
    }

    auto clear(Bit b) noexcept -> bitfield& {
        _bits &= ~BF(b);
        return *this;
    }
};

} // namespace eagine

#endif // EAGINE_BITFIELD_HPP
