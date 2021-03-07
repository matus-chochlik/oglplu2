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
/// @brief Abstract base class for deserialization data sources.
/// @ingroup serialization
/// @see data_sink
/// @see deserializer_backend
struct deserializer_data_source : interface<deserializer_data_source> {

    /// @brief Returns a block covering the specified amount of data of the top.
    /// @see pop
    /// @see scan_until
    /// @see scan_for
    virtual auto top(span_size_t size) -> memory::const_block = 0;

    /// @brief Returns the specified amount of data of the top of the source.
    /// @see top
    virtual void pop(span_size_t size) = 0;

    /// @brief Returns the position of the first byte where predicate is true.
    /// @see scan_for
    /// @param predicate the function indicating where to stop the scan.
    /// @param max the maximum number of bytes from the top to scan.
    /// @param step how much data should be fetched per scan iteration.
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

    /// @brief Returns the position of the first occurrence of the specified byte.
    /// @see scan_until
    /// @param what the searched value.
    /// @param max the maximum number of bytes from the top to scan.
    /// @param step how much data should be fetched per scan iteration.
    auto scan_for(
      byte what,
      const valid_if_positive<span_size_t>& max,
      const valid_if_positive<span_size_t>& step = {256})
      -> valid_if_nonnegative<span_size_t> {
        return scan_until([what](byte b) { return b == what; }, max, step);
    }

    /// @brief Fetches all the remaining data into a buffer.
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
