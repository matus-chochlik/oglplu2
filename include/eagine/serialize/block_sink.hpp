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
#include <ostream>

namespace eagine {
//------------------------------------------------------------------------------
class block_data_sink : public serializer_data_sink {
public:
    block_data_sink(memory::block dst) noexcept
      : _dst{dst} {
    }

    memory::block done() const noexcept {
        return head(_dst, _done);
    }

    memory::block free() const noexcept {
        return skip(_dst, _done);
    }

    span_size_t remaining_size() final {
        return free().size();
    }

    serialization_errors write(memory::const_block blk) {
        auto dst = free();
        if(dst.size() < blk.size()) {
            return {serialization_error_code::too_much_data};
        }
        copy(blk, dst);
        _done += blk.size();
        return {};
    }

private:
    memory::block _dst;
    span_size_t _done{0};
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_SERIALIZE_BLOCK_SINK_HPP

