/**
 *  @file eagine/bit_density.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_BIT_DENSITY_HPP
#define EAGINE_BIT_DENSITY_HPP

#include "assert.hpp"
#include "types.hpp"
#include "valid_if/decl.hpp"
#include <climits>

namespace eagine {
//------------------------------------------------------------------------------
static constexpr inline span_size_t byte_bits() noexcept {
    return span_size_t(CHAR_BIT);
}
//------------------------------------------------------------------------------
static constexpr inline span_size_t dissolved_bits_length(
  span_size_t original_length, span_size_t bits) noexcept {
    return EAGINE_CONSTEXPR_ASSERT(
      (bits >= 1) and (bits <= byte_bits()),
      (((original_length * byte_bits()) / bits) +
       (((original_length * byte_bits()) % bits) ? 1 : 0)));
}
//------------------------------------------------------------------------------
static constexpr inline span_size_t concentrated_bits_length(
  span_size_t original_length, span_size_t bits) noexcept {
    return EAGINE_CONSTEXPR_ASSERT(
      (bits >= 1) and (bits <= byte_bits()),
      (((original_length * bits) / byte_bits()) +
       (((original_length * bits) % byte_bits()) ? 1 : 0)));
}
//------------------------------------------------------------------------------
template <typename Getter, typename Putter>
static inline bool do_dissolve_bits(
  Getter get, Putter put, span_size_t bits) noexcept {

    EAGINE_ASSERT(bits >= 1);
    EAGINE_ASSERT(bits <= byte_bits());

    using B = unsigned char;
    using W = std::uint16_t;

    span_size_t r = 0;
    W w = 0U;
    const B m = B((1U << bits) - 1U);

    auto push = [&]() -> bool {
        while(r >= bits) {
            if(!put(B(w >> W(r - bits)) & m)) {
                return false;
            }
            r -= bits;
        }
        return true;
    };

    while(true) {
        if(r < bits) {
            if(auto src = get()) {
                w <<= byte_bits();
                w |= W(src.value());
                r += byte_bits();
            } else {
                break;
            }
        }
        if(!push()) {
            return false;
        }
    }

    if(r > 0) {
        EAGINE_ASSERT(r < bits);
        if(!put(B(w << W(bits - r)) & m)) {
            return false;
        }
    }
    return true;
}
//------------------------------------------------------------------------------
template <typename Getter, typename Putter>
static inline bool do_concentrate_bits(
  Getter get, Putter put, span_size_t bits) noexcept {
    EAGINE_ASSERT(bits >= 1);
    EAGINE_ASSERT(bits <= byte_bits());

    using B = unsigned char;
    using W = std::uint16_t;

    span_size_t r = 0;
    W w = 0U;
    const W m = (1U << bits) - 1U;

    bool done = false;

    while(!done) {
        while(r < byte_bits()) {
            if(auto src = get()) {
                w <<= bits;
                w = (w & ~m) |
                    (W(src.value()) & m); // NOLINT(hicpp-signed-bitwise)
                r += bits;
            } else {
                done = true;
                break;
            }
        }
        if(r >= byte_bits()) {
            if(!put(B(w >> W(r - byte_bits())))) {
                return false;
            }
            r -= byte_bits();
        }
    }
    return true;
}
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_BIT_DENSITY_HPP
