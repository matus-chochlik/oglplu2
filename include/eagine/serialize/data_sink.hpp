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
/// @brief Abstract base class for serialization data sinks.
/// @ingroup serialization
/// @see data_source
/// @see serializer_backend
struct serializer_data_sink : abstract<serializer_data_sink> {

    /// @brief Alias for the operation result type.
    using result = serialization_errors;

    /// @brief Returns the remaining available size for data in this sink.
    virtual auto remaining_size() -> span_size_t = 0;

    /// @brief Writes a block of data into this sink.
    virtual auto write(memory::const_block data) -> result = 0;

    /// @brief Writes a single string character into this sink.
    auto write(char chr) -> result {
        return this->write(as_bytes(view_one(chr)));
    }

    /// @brief Writes a string view into this sink.
    auto write(string_view str) -> result {
        return this->write(as_bytes(str));
    }

    /// @brief Writes as much as possible from a split data block.
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

    /// @brief Alias for type indentifying sink transaction that can be rolled back.
    using transaction_handle = std::uintptr_t;

    /// @brief Begins a write transaction on this data sink.
    /// @see commit
    /// @see rollback
    virtual auto begin_work() -> transaction_handle = 0;

    /// @brief Commits writes done as a part of transaction identified by argument.
    /// @see begin_work
    /// @see rollback
    virtual void commit(transaction_handle) = 0;

    /// @brief Rolls-back writes done as a part of transaction identified by argument.
    /// @see begin_work
    /// @see commit
    virtual void rollback(transaction_handle) = 0;

    /// @brief Does additional finalization, like compression after serialization operation.
    virtual auto finalize() -> result = 0;
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_SERIALIZE_DATA_SINK_HPP
