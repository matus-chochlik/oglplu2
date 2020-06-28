/**
 *  @file eagine/base64.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_BASE64_HPP
#define EAGINE_BASE64_HPP

#include "bit_density.hpp"
#include "optional_ref.hpp"
#include "span.hpp"
#include "valid_if/always.hpp"

namespace eagine {
//------------------------------------------------------------------------------
static constexpr inline auto make_base64_encode_transform() {
    return [](byte b) -> always_valid<char> {
        const auto i = int(b);
        if(i < 26) {
            return {char('A' + i)};
        }
        if(i < 52) {
            return {char('a' + i - 26)};
        }
        if(i < 62) {
            return {char('0' + i - 52)};
        }
        if(i == 62) {
            return {'+'};
        }
        if(i == 63) {
            return {'/'};
        }
        return {'='};
    };
}
//------------------------------------------------------------------------------
static constexpr inline auto make_base64_decode_transform() {
    return [](char c) -> optionally_valid<byte> {
        if((c >= 'A') && (c <= 'Z')) {
            return {byte(c - 'A'), true};
        }
        if((c >= 'a') && (c <= 'z')) {
            return {byte(c - 'a' + 26), true};
        }
        if((c >= '0') && (c <= '9')) {
            return {byte(c - '0' + 52), true};
        }
        if(c == '+') {
            return {byte(62), true};
        }
        if(c == '/') {
            return {byte(63), true};
        }
        return {};
    };
}
//------------------------------------------------------------------------------
template <typename P, typename S, typename Dst>
static inline optional_reference_wrapper<Dst> base64_encode(
  memory::basic_span<const byte, P, S> src, Dst& dst) {
    using Ds = typename Dst::size_type;
    dst.resize(Ds(dissolved_bits_length(src.size(), 6)));
    span_size_t i = 0;
    span_size_t o = 0;

    if(do_dissolve_bits(
         make_span_getter(i, src),
         make_span_putter(o, dst, make_base64_encode_transform()),
         6)) {
        dst.resize(Ds(o));
        return {dst};
    }
    return {nothing};
}
//------------------------------------------------------------------------------
template <typename P, typename S, typename Dst>
static inline optional_reference_wrapper<Dst> base64_decode(
  memory::basic_span<const char, P, S> src, Dst& dst) {
    using Ds = typename Dst::size_type;
    dst.resize(Ds(concentrated_bits_length(src.size(), 6)));
    span_size_t i = 0;
    span_size_t o = 0;

    if(do_concentrate_bits(
         make_span_getter(i, src, make_base64_decode_transform()),
         make_span_putter(o, dst),
         6)) {
        dst.resize(Ds(o));
        return {dst};
    }
    return {nothing};
}
//------------------------------------------------------------------------------
} // namespace eagine
#endif // EAGINE_BASE64_HPP

