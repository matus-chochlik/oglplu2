/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_SERIALIZE_DATA_SOURCE_HPP
#define EAGINE_SERIALIZE_DATA_SOURCE_HPP

#include "../interface.hpp"
#include "../memory/buffer.hpp"
#include "../memory/span_algo.hpp"
#include "../string_span.hpp"
#include "../valid_if/nonnegative.hpp"
#include "../valid_if/positive.hpp"

namespace eagine {
//------------------------------------------------------------------------------
struct deserializer_data_source : interface<deserializer_data_source> {

    virtual auto top(span_size_t size) -> memory::const_block = 0;

    virtual void pop(span_size_t size) = 0;

    template <typename Function>
    auto scan_until(
      Function predicate,
      const valid_if_positive<span_size_t>& max,
      const valid_if_positive<span_size_t>& step = {256})
      -> valid_if_nonnegative<span_size_t> {
        const auto inc{extract(step)};
        span_size_t start{0};
        span_size_t total{inc};
        while(auto blk = top(total)) {
            if(auto found = find_element_if(skip(blk, start), predicate)) {
                return {start + extract(found)};
            }
            if(blk.size() < total) {
                break;
            }
            if(extract(max) < total) {
                return extract(max);
            }
            start += inc;
            total += inc;
        }
        return {-1};
    }

    auto scan_for(
      byte what,
      const valid_if_positive<span_size_t>& max,
      const valid_if_positive<span_size_t>& step = {256})
      -> valid_if_nonnegative<span_size_t> {
        return scan_until([what](byte b) { return b == what; }, max, step);
    }

    void fetch_all(
      memory::buffer& dst,
      valid_if_positive<span_size_t> step = {256}) {
        span_size_t offs{dst.size()};
        while(auto blk = top(extract(step))) {
            dst.enlarge_by(blk.size());
            copy(blk, skip(cover(dst), offs));
            offs += blk.size();
            pop(blk.size());
        }
    }
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_SERIALIZE_DATA_SOURCE_HPP
