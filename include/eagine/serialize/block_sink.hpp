/**
 *  @file eagine/serialize/block_sink.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_SERIALIZE_BLOCK_SINK_HPP
#define EAGINE_SERIALIZE_BLOCK_SINK_HPP

#include "../memory/span_algo.hpp"
#include "data_sink.hpp"
#include <stack>

namespace eagine {
//------------------------------------------------------------------------------
class block_data_sink : public serializer_data_sink {
public:
    block_data_sink(memory::block dst) noexcept
      : _dst{dst} {}

    auto done() const noexcept -> memory::block {
        return head(_dst, _done);
    }

    auto free() const noexcept -> memory::block {
        return skip(_dst, _done);
    }

    auto remaining_size() -> span_size_t final {
        return free().size();
    }

    using serializer_data_sink::write;

    auto write(memory::const_block blk) -> serialization_errors final {
        auto dst = free();
        if(dst.size() < blk.size()) {
            copy(head(blk, dst.size()), dst);
            _done += dst.size();
            return {serialization_error_code::incomplete_write};
        }
        copy(blk, dst);
        _done += blk.size();
        return {};
    }

    auto begin_work() -> transaction_handle final {
        _save_points.push(_done);
        return transaction_handle(_save_points.size());
    }

    void commit(transaction_handle th) final {
        EAGINE_ASSERT(th == transaction_handle(_save_points.size()));
        EAGINE_MAYBE_UNUSED(th);
        _save_points.pop();
    }

    void rollback(transaction_handle th) final {
        EAGINE_ASSERT(th == transaction_handle(_save_points.size()));
        EAGINE_MAYBE_UNUSED(th);
        _done = _save_points.top();
        _save_points.pop();
    }

private:
    memory::block _dst;
    span_size_t _done{0};
    std::stack<span_size_t> _save_points;
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_SERIALIZE_BLOCK_SINK_HPP
