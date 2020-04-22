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

#include "../branch_predict.hpp"
#include "../is_within_limits.hpp"
#include "../memory/span_algo.hpp"
#include "../multi_byte_seq.hpp"

namespace eagine {
//------------------------------------------------------------------------------
static inline memory::block store_data_with_size(
  memory::const_block src, memory::block dst) noexcept {

    const auto opt_size_cp = limit_cast<mbs::code_point>(src.size());
    if(EAGINE_LIKELY(opt_size_cp)) {
        const auto size_cp = extract(opt_size_cp);
        const auto opt_size_len = mbs::required_sequence_length(size_cp);
        if(EAGINE_LIKELY(opt_size_len)) {
            if(extract(opt_size_len) + src.size() <= dst.size()) {
                const auto opt_skip_len = mbs::encode_code_point(size_cp, dst);
                if(EAGINE_LIKELY(opt_skip_len)) {
                    const auto skip_len =
                      limit_cast<span_size_t>(extract(opt_skip_len));
                    copy(src, skip(dst, skip_len));
                    return head(dst, skip_len + src.size());
                }
            }
        }
    }

    return {};
}
//------------------------------------------------------------------------------
static inline memory::const_block get_data_with_size(
  memory::const_block src) noexcept {

    const auto opt_skip_len = mbs::decode_sequence_length(src);
    if(const auto opt_data_len = mbs::do_decode_code_point(src, opt_skip_len)) {
        return head(
          skip(src, extract(opt_skip_len)),
          limit_cast<span_size_t>(extract(opt_data_len)));
    }
    return {};
}
//------------------------------------------------------------------------------
template <typename Function>
static inline void for_each_data_with_size(
  memory::const_block src, Function function) noexcept {
    while(src) {
        const auto opt_skip_len = mbs::decode_sequence_length(src);
        if(
          const auto opt_data_len =
            mbs::do_decode_code_point(src, opt_skip_len)) {
            const auto skip_len = extract(opt_skip_len);
            const auto data_len = extract(opt_data_len);
            if(data_len > 0) {
                function(
                  head(skip(src, skip_len), limit_cast<span_size_t>(data_len)));
                src = skip(src, skip_len + data_len);
            } else {
                break;
            }
        } else {
            break;
        }
    }
}
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_SERIALIZE_SIZE_AND_DATA_HPP

