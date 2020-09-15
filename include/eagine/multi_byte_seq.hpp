/**
 *  @file eagine/multi_byte_seq.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MULTI_BYTE_SEQ_HPP
#define EAGINE_MULTI_BYTE_SEQ_HPP

#include "span.hpp"
#include "string_span.hpp"
#include "types.hpp"
#include "valid_if/always.hpp"
#include "valid_if/between.hpp"
#include "valid_if/le_size_ge0.hpp"
#include "valid_if/less_than.hpp"
#include "valid_if/not_empty.hpp"
#include "valid_if/not_zero.hpp"
#include "valid_if/size_gt.hpp"
#include <cstdint>
#include <string>

namespace eagine {
namespace mbs {
//------------------------------------------------------------------------------
using code_point_t = std::uint32_t;
static constexpr code_point_t invalid_code_point = 0x7FFFFFFFU;
using code_point = valid_if_less_than<code_point_t, 0x7FFFFFFFU>;
//------------------------------------------------------------------------------
using valid_sequence_length = valid_if_between<span_size_t, 1, 6>;
using valid_byte_span = valid_if_size_gt<span<byte>, span_size_t>;
//------------------------------------------------------------------------------
static inline auto make_byte_span(span<byte> s) noexcept -> valid_byte_span {
    return {s};
}
//------------------------------------------------------------------------------
static inline auto make_byte_span(span<char> s) noexcept -> valid_byte_span {
    return {memory::accomodate<byte>(s)};
}
//------------------------------------------------------------------------------
using valid_cbyte_span = valid_if_size_gt<span<const byte>, span_size_t>;
//------------------------------------------------------------------------------
static inline auto make_cbyte_span(span<const byte> s) noexcept
  -> valid_cbyte_span {
    return {s};
}
//------------------------------------------------------------------------------
static inline auto make_cbyte_span(span<const char> s) noexcept
  -> valid_cbyte_span {
    return {memory::accomodate<const byte>(s)};
}
//------------------------------------------------------------------------------
static constexpr inline auto
max_code_point(const valid_sequence_length& len) noexcept
  -> valid_if_not_zero<code_point_t> {
    return len == 1 ? 0x0000007F :           //  7b
             len == 2 ? 0x000007FF :         // 11b
               len == 3 ? 0x0000FFFF :       // 16b
                 len == 4 ? 0x001FFFFF :     // 21b
                   len == 5 ? 0x03FFFFFF :   // 26b
                     len == 6 ? 0x7FFFFFFF : // 31b
                       0x00000000;
}
//------------------------------------------------------------------------------
static constexpr inline auto head_data_bitshift(
  const valid_sequence_length& len) noexcept -> valid_span_size {
    return {len.is_valid() ? (extract(len) - 1) * 6 : -1};
}
//------------------------------------------------------------------------------
static constexpr inline auto tail_data_bitshift(
  const valid_sequence_length& idx,
  const valid_sequence_length& len) noexcept -> valid_span_size {
    return {
      (idx.is_valid() && len.is_valid()) ? (extract(len) - extract(idx) - 1) * 6
                                         : -1};
}
//------------------------------------------------------------------------------
static constexpr inline auto head_code_mask(
  const valid_sequence_length& len) noexcept -> valid_if_not_zero<byte> {
    return len == 1
             ? 0x80
             : len == 2
                 ? 0xE0
                 : len == 3
                     ? 0xF0
                     : len == 4 ? 0xF8
                                : len == 5 ? 0xFC : len == 6 ? 0xFE : 0x00;
}
//------------------------------------------------------------------------------
template <typename P>
static constexpr inline auto inverted_byte(const valid_if<byte, P> b) noexcept
  -> optionally_valid<byte> {
    return {byte(~b.value_anyway()), b.is_valid()};
}
//------------------------------------------------------------------------------
static constexpr inline auto head_data_mask(
  const valid_sequence_length& len) noexcept -> optionally_valid<byte> {
    return inverted_byte(head_code_mask(len));
}
//------------------------------------------------------------------------------
static constexpr inline auto tail_code_mask() noexcept -> always_valid<byte> {
    return 0xC0;
}
//------------------------------------------------------------------------------
static constexpr inline auto tail_data_mask() noexcept -> always_valid<byte> {
    return 0x3F;
}
//------------------------------------------------------------------------------
template <typename P>
static constexpr inline auto
head_code_from_mask(const valid_if<byte, P> mask) noexcept
  -> optionally_valid<byte> {
    // NOLINTNEXTLINE(hicpp-signed-bitwise)
    return {byte((mask.value_anyway() << 1) & 0xFF), mask.is_valid()};
}
//------------------------------------------------------------------------------
static constexpr inline auto
head_code(const valid_sequence_length& len) noexcept -> optionally_valid<byte> {
    return head_code_from_mask(head_code_mask(len));
}
//------------------------------------------------------------------------------
static constexpr inline auto tail_code() noexcept -> always_valid<byte> {
    return 0x80;
}
//------------------------------------------------------------------------------
template <typename P1, typename P2>
static constexpr inline auto is_valid_masked_code(
  const byte b,
  const valid_if<byte, P1> mask,
  const valid_if<byte, P2> code) noexcept -> bool {
    return (mask.is_valid() && code.is_valid())
             ? (b & extract(mask)) == extract(code)
             : false;
}
//------------------------------------------------------------------------------
static constexpr inline auto
is_valid_head_byte(const byte b, const valid_sequence_length& l) noexcept
  -> bool {
    return is_valid_masked_code(b, head_code_mask(l), head_code(l));
}
//------------------------------------------------------------------------------
static constexpr inline auto is_valid_head_byte(const byte b) noexcept -> bool {
    return is_valid_head_byte(b, 1) || is_valid_head_byte(b, 2) ||
           is_valid_head_byte(b, 3) || is_valid_head_byte(b, 4) ||
           is_valid_head_byte(b, 5) || is_valid_head_byte(b, 6);
}
//------------------------------------------------------------------------------
static constexpr inline auto is_valid_tail_byte(
  const byte b,
  const valid_sequence_length&,
  const valid_sequence_length&) noexcept -> bool {
    return is_valid_masked_code(b, tail_code_mask(), tail_code());
}
//------------------------------------------------------------------------------
static constexpr inline auto required_sequence_length(
  const code_point_t cp) noexcept -> valid_sequence_length {
    return (max_code_point(1) > cp)
             ? 1
             : (max_code_point(2) > cp)
                 ? 2
                 : (max_code_point(3) > cp)
                     ? 3
                     : (max_code_point(4) > cp)
                         ? 4
                         : (max_code_point(5) > cp)
                             ? 5
                             : (max_code_point(6) > cp) ? 6 : 0;
}
//------------------------------------------------------------------------------
valid_sequence_length do_decode_sequence_length(const byte b) noexcept;
//------------------------------------------------------------------------------
static inline auto decode_sequence_length(const valid_cbyte_span& seq) noexcept
  -> valid_sequence_length {
    return do_decode_sequence_length(byte(seq.value(0)[0]));
}
//------------------------------------------------------------------------------
auto is_valid_encoding(const valid_cbyte_span& vseq) noexcept -> bool;
//------------------------------------------------------------------------------
auto do_decode_code_point(
  const valid_cbyte_span& vsrc,
  const valid_sequence_length& vl) noexcept -> code_point;
//------------------------------------------------------------------------------
static inline auto decode_code_point(const valid_cbyte_span& src) noexcept
  -> code_point {
    return do_decode_code_point(src, decode_sequence_length(src));
}
//------------------------------------------------------------------------------
auto do_encode_code_point(
  const code_point& cp,
  const valid_byte_span& vdest,
  const valid_sequence_length& vl) noexcept -> bool;
//------------------------------------------------------------------------------
auto encode_code_point(
  const code_point& cp,
  const valid_byte_span& dest) noexcept -> valid_sequence_length;
//------------------------------------------------------------------------------
auto encode_code_point(const code_point& cp) -> valid_if_not_empty<std::string>;
//------------------------------------------------------------------------------
auto encoding_bytes_required(span<const code_point_t> cps) noexcept
  -> optionally_valid<span_size_t>;
//------------------------------------------------------------------------------
auto encoding_bytes_required(span<const code_point> cps) noexcept
  -> optionally_valid<span_size_t>;
//------------------------------------------------------------------------------
auto decoding_code_points_required(const valid_cbyte_span& bytes) noexcept
  -> optionally_valid<span_size_t>;
//------------------------------------------------------------------------------
auto encode_code_points(
  span<const code_point> cps,
  const valid_byte_span& bytes) noexcept -> bool;
//------------------------------------------------------------------------------
auto decode_code_points(const valid_cbyte_span& bytes, span<code_point> cps)
  -> bool;
//------------------------------------------------------------------------------
} // namespace mbs
} // namespace eagine

#include <eagine/multi_byte_seq.inl>

#endif // EAGINE_MULTI_BYTE_SEQ_HPP
