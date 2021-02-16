/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef EAGINE_INTEGER_HASH_HPP
#define EAGINE_INTEGER_HASH_HPP

#include "int_constant.hpp"
#include "type_identity.hpp"
#include <cstdint>

namespace eagine {
//------------------------------------------------------------------------------
template <std::size_t N, typename I>
constexpr auto
integer_rotate_right(I x, type_identity<I> = {}, size_constant<N> = {}) noexcept
  -> I {
    static_assert(N < sizeof(I) * 8);
    return I(x << N) | I(x >> (-N & (sizeof(I) * 8U - 1U)));
}
//------------------------------------------------------------------------------
template <typename H>
constexpr auto
integer_hash_init(H x, type_identity<H> = {}, type_identity<H> = {}) noexcept
  -> H {
    return x;
}
//------------------------------------------------------------------------------
template <typename H, typename I>
constexpr auto integer_hash_init(
  I x,
  type_identity<H> hid = {},
  type_identity<I> = {}) noexcept -> H {
    using std::is_same_v;

    if constexpr(is_same_v<I, std::uint16_t>) {
        if constexpr(is_same_v<H, std::uint32_t>) {
            return H(x) ^ (H(x) << 16U);
        }
        if constexpr(is_same_v<H, std::uint64_t>) {
            return H(x) ^ (H(x) << 16U) ^ (H(x) << 32U) ^ (H(x) << 48U);
        }
    }
    if constexpr(is_same_v<I, std::uint32_t>) {
        if constexpr(is_same_v<H, std::uint16_t>) {
            return H(x ^ (x >> 16U));
        }
        if constexpr(is_same_v<H, std::uint64_t>) {
            return H(x) ^ (H(x) << 32U);
        }
    }
    if constexpr(is_same_v<I, std::uint64_t>) {
        if constexpr(is_same_v<H, std::uint16_t>) {
            return H(x ^ (x >> 16U) ^ (x >> 32U) ^ (x >> 48U));
        }
        if constexpr(is_same_v<H, std::uint32_t>) {
            return H(x ^ (x >> 32U));
        }
    }

    using UI = std::make_unsigned_t<I>;
    return integer_hash_init(UI(x), hid, type_identity<UI>());
}
//------------------------------------------------------------------------------
template <typename H, typename I>
inline auto
integer_hash(I x, type_identity<H> hid = {}, type_identity<I> iid = {}) -> H {
    using std::is_same_v;
    if constexpr(std::is_unsigned_v<H>) {
        auto h = integer_hash_init(x, hid, iid);
        if constexpr(is_same_v<H, std::uint16_t>) {
            h ^= integer_rotate_right<9U>(h, hid);
            h *= 0xff51;
            h ^= integer_rotate_right<9U>(h, hid);
            h *= 0xafd7;
            h ^= integer_rotate_right<9U>(h, hid);
            h *= 0xed55;
            h ^= integer_rotate_right<9U>(h, hid);
            h *= 0x8ccd;
            h ^= integer_rotate_right<9U>(h, hid);
            h *= 0xc4ce;
            h ^= integer_rotate_right<9U>(h, hid);
            h *= 0xb9fe;
            h ^= integer_rotate_right<9U>(h, hid);
            h *= 0x1a85;
            h ^= integer_rotate_right<9U>(h, hid);
            h *= 0xec53;
            h ^= integer_rotate_right<9U>(h, hid);
        }
        if constexpr(is_same_v<H, std::uint32_t>) {
            h ^= integer_rotate_right<17U>(h, hid);
            h *= 0xff51afd7;
            h ^= integer_rotate_right<17U>(h, hid);
            h *= 0xed558ccd;
            h ^= integer_rotate_right<17U>(h, hid);
            h *= 0xc4ceb9fe;
            h ^= integer_rotate_right<17U>(h, hid);
            h *= 0x1a85ec53;
            h ^= integer_rotate_right<17U>(h, hid);
        }
        if constexpr(is_same_v<H, std::uint64_t>) {
            h ^= integer_rotate_right<33U>(h, hid);
            h *= 0xff51afd7ed558ccd;
            h ^= integer_rotate_right<33U>(h, hid);
            h *= 0xed558ccdff51afd7;
            h ^= integer_rotate_right<33U>(h, hid);
            h *= 0xc4ceb9fe1a85ec53;
            h ^= integer_rotate_right<33U>(h, hid);
            h *= 0x1a85ec53c4ceb9fe;
            h ^= integer_rotate_right<33U>(h, hid);
        }
        return h;
    }

    using UH = std::make_unsigned_t<H>;
    return H(integer_hash<UH>(x));
}
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_INTEGER_HASH_HPP
