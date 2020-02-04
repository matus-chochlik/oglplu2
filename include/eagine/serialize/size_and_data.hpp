/**
 *  @file eagine/serialize/size_and_data.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_SERIALIZE_SIZE_AND_DATA_HPP
#define EAGINE_SERIALIZE_SIZE_AND_DATA_HPP

#include "../is_within_limits.hpp"
#include "../memory/span_algo.hpp"
#include "../multi_byte_seq.hpp"

namespace eagine {
//------------------------------------------------------------------------------
static inline memory::block store_data_with_size(
  memory::const_block src, memory::block dst) noexcept {
    if(
      const auto opt_skip_len =
        mbs::encode_code_point(limit_cast<mbs::code_point>(src.size()), dst)) {

        const auto skip_len = limit_cast<span_size_t>(extract(opt_skip_len));
        copy(src, skip(dst, skip_len));
        return head(dst, skip_len + src.size());
    }

    return {};
}
//------------------------------------------------------------------------------
static inline memory::const_block get_data_with_size(
  memory::const_block src) noexcept {

    const auto skip_len = mbs::decode_sequence_length(src);
    if(const auto data_len = mbs::do_decode_code_point(src, skip_len)) {
        return head(
          skip(src, extract(skip_len)),
          limit_cast<span_size_t>(extract(data_len)));
    }
    return {};
}
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_SERIALIZE_SIZE_AND_DATA_HPP

