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
// type at least twice the size of byte
using double_byte = std::conditional_t<
  (CHAR_BIT > 8),
  uint_fast16_t,
  std::conditional_t<(CHAR_BIT > 16), uint_fast32_t, uint_fast64_t>>;
//------------------------------------------------------------------------------
static constexpr inline auto byte_bits() noexcept {
    return span_size_t(CHAR_BIT);
}
//------------------------------------------------------------------------------
static constexpr inline auto
dissolved_bits_length(span_size_t original_length, span_size_t bits) noexcept
  -> span_size_t {
    return EAGINE_CONSTEXPR_ASSERT(
      (bits >= 1) and (bits <= byte_bits()),
      (((original_length * byte_bits()) / bits) +
       (((original_length * byte_bits()) % bits) ? 1 : 0)));
}
//------------------------------------------------------------------------------
static constexpr inline auto
concentrated_bits_length(span_size_t original_length, span_size_t bits) noexcept
  -> span_size_t {
    return EAGINE_CONSTEXPR_ASSERT(
      (bits >= 1) and (bits <= byte_bits()),
      (((original_length * bits) / byte_bits()) +
       (((original_length * bits) % byte_bits()) ? 1 : 0)));
}
//------------------------------------------------------------------------------
template <typename Getter, typename Putter>
static inline auto
do_dissolve_bits(Getter get, Putter put, span_size_t bits) noexcept -> bool {

    EAGINE_ASSERT(bits >= 1);
    EAGINE_ASSERT(bits <= byte_bits());

    span_size_t r = 0;
    double_byte w = 0U;
    const auto m = byte((1U << bits) - 1U); // NOLINT(hicpp-signed-bitwise)

    auto push = [&]() -> bool {
        while(r >= bits) {
            if(!put(byte(w >> double_byte(r - bits)) & m)) {
                return false;
            }
            r -= bits;
        }
        return true;
    };

    while(true) {
        if(r < bits) {
            if(auto src = get()) {
                w <<= byte_bits(); // NOLINT(hicpp-signed-bitwise)
                w |= double_byte(extract(src));
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
        if(!put(byte(w << double_byte(bits - r)) & m)) {
            return false;
        }
    }
    return true;
}
//------------------------------------------------------------------------------
template <typename Getter, typename Putter>
static inline auto
do_concentrate_bits(Getter get, Putter put, span_size_t bits) noexcept -> bool {
    EAGINE_ASSERT(bits >= 1);
    EAGINE_ASSERT(bits <= byte_bits());

    span_size_t r = 0;
    double_byte w = 0U;
    const double_byte m = (1U << bits) - 1U; // NOLINT(hicpp-signed-bitwise)

    bool done = false;

    while(!done) {
        while(r < byte_bits()) {
            if(auto src = get()) {
                w <<= bits; // NOLINT(hicpp-signed-bitwise)
                // NOLINTNEXTLINE(hicpp-signed-bitwise)
                w = (w & ~m) | (double_byte(extract(src)) & m);
                r += bits;
            } else {
                done = true;
                break;
            }
        }
        if(r >= byte_bits()) {
            if(!put(byte(w >> double_byte(r - byte_bits())))) {
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
