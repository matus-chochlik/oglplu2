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

} // namespace eagine

#endif // EAGINE_BIT_DENSITY_HPP
