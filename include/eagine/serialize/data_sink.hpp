/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_SERIALIZE_DATA_SINK_HPP
#define EAGINE_SERIALIZE_DATA_SINK_HPP

#include "../interface.hpp"
#include "../memory/split_block.hpp"
#include "../span.hpp"
#include "../string_span.hpp"
#include "result.hpp"

namespace eagine {
//------------------------------------------------------------------------------
struct serializer_data_sink : abstract<serializer_data_sink> {

    using result = serialization_errors;

    virtual auto remaining_size() -> span_size_t = 0;

    virtual auto write(memory::const_block data) -> result = 0;

    auto write(char chr) -> result {
        return this->write(as_bytes(view_one(chr)));
    }

    auto write(string_view str) -> result {
        return this->write(as_bytes(str));
    }

    auto write_some(memory::const_split_block data)
      -> serialization_result<memory::const_split_block> {
        const auto before{remaining_size()};
        const auto errors{write(data.tail())};
        if(!errors) {
            return {data.skip_to_end()};
        }
        if(errors.has_at_most(serialization_error_code::incomplete_write)) {
            return {data.advance(before)};
        }
        return {data, errors};
    }

    using transaction_handle = std::uintptr_t;

    virtual auto begin_work() -> transaction_handle = 0;

    virtual void commit(transaction_handle) = 0;

    virtual void rollback(transaction_handle) = 0;

    virtual auto finalize() -> result = 0;
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_SERIALIZE_DATA_SINK_HPP
