/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_SERIALIZE_BLOCK_SINK_HPP
#define EAGINE_SERIALIZE_BLOCK_SINK_HPP

#include "../memory/span_algo.hpp"
#include "data_sink.hpp"
#include <type_traits>
#include <vector>

namespace eagine {
//------------------------------------------------------------------------------
/// @brief Serialization data sink backed by a pre-allocated memory block.
/// @ingroup serialization
/// @see block_data_source
/// @see packed_block_data_sink
class block_data_sink : public serializer_data_sink {
public:
    /// @brief Default constructor.
    /// @post free().empty()
    constexpr block_data_sink() noexcept = default;

    /// @brief Constructor setting the backing block.
    block_data_sink(memory::block dst) noexcept
      : _dst{dst} {}

    /// @brief Resets the backing block.
    /// @see replace_with
    void reset(memory::block dst) {
        _dst = dst;
        _done = 0;
        _save_points.clear();
    }

    /// @brief Returns the part of the backing block already written to.
    /// @see free
    auto done() const noexcept -> memory::block {
        return head(_dst, _done);
    }

    /// @brief Returns the free part of the backing block.
    /// @see done
    /// @see remaining_size
    auto free() const noexcept -> memory::block {
        return skip(_dst, _done);
    }

    /// @brief Returns the free part of the backing block and marks it as used.
    /// @see done
    /// @see remaining_size
    /// @see free
    auto mark_used(span_size_t size) noexcept -> auto& {
        EAGINE_ASSERT(size <= remaining_size());
        _done += size;
        return *this;
    }

    /// @brief Returns the size of the free part of the backing block.
    /// @see free
    /// @see done
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

    /// @brief Replaces the content of the backing block with the content of the argument.
    /// @see reset
    auto replace_with(memory::const_block blk) -> serialization_errors {
        if(_dst.size() < blk.size()) {
            return {serialization_error_code::too_much_data};
        }
        copy(blk, _dst);
        _done = blk.size();
        return {};
    }

    auto begin_work() -> transaction_handle final {
        _save_points.push_back(_done);
        return transaction_handle(_save_points.size());
    }

    void commit(transaction_handle th) final {
        EAGINE_ASSERT(th == transaction_handle(_save_points.size()));
        EAGINE_MAYBE_UNUSED(th);
        _save_points.pop_back();
    }

    void rollback(transaction_handle th) final {
        EAGINE_ASSERT(th == transaction_handle(_save_points.size()));
        EAGINE_MAYBE_UNUSED(th);
        _done = _save_points.back();
        _save_points.pop_back();
    }

    auto finalize() -> serialization_errors override {
        return {};
    }

private:
    memory::block _dst{};
    span_size_t _done{0};
    std::vector<span_size_t> _save_points{};
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_SERIALIZE_BLOCK_SINK_HPP
