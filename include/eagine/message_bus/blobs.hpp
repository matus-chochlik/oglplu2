/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MESSAGE_BUS_BLOBS_HPP
#define EAGINE_MESSAGE_BUS_BLOBS_HPP

#include "../callable_ref.hpp"
#include "../double_buffer.hpp"
#include "../interface.hpp"
#include "../main_ctx_object.hpp"
#include "../memory/buffer_pool.hpp"
#include "../memory/split_block.hpp"
#include "../timeout.hpp"
#include "../valid_if/positive.hpp"
#include "message.hpp"
#include <cstdint>
#include <vector>

namespace eagine::msgbus {
//------------------------------------------------------------------------------
struct blob_io : interface<blob_io> {

    virtual auto is_at_eod(span_size_t offs) -> bool = 0;
    virtual auto total_size() -> span_size_t = 0;

    virtual auto fetch_fragment(span_size_t offs, memory::block dst)
      -> span_size_t = 0;
    virtual auto store_fragment(span_size_t offs, memory::const_block src)
      -> bool = 0;
    virtual auto check_stored(span_size_t offs, memory::const_block src)
      -> bool = 0;
};
//------------------------------------------------------------------------------
struct finishing_blob_io : blob_io {
    virtual void
    handle_finished(message_id, message_age, const message_info&) = 0;
};
//------------------------------------------------------------------------------
class buffer_blob_io : public blob_io {
public:
    buffer_blob_io(memory::buffer buf) noexcept;

    buffer_blob_io(memory::buffer buf, memory::const_block src);

    auto is_at_eod(span_size_t offs) -> bool final;
    auto total_size() -> span_size_t final;

    auto fetch_fragment(span_size_t offs, memory::block) -> span_size_t final;
    auto store_fragment(span_size_t offs, memory::const_block) -> bool final;
    auto check_stored(span_size_t offs, memory::const_block) -> bool final;

    auto release_buffer() noexcept -> memory::buffer;

private:
    memory::buffer _buf;
};
//------------------------------------------------------------------------------
struct pending_blob {
    message_id msg_id{};
    identifier_t source_id{0U};
    identifier_t target_id{0U};
    std::unique_ptr<blob_io> io{};
    span_size_t current_position{0};
    // TODO: recycle the done parts vectors?
    double_buffer<std::vector<std::tuple<span_size_t, span_size_t>>>
      done_parts{};
    timeout max_time{};
    std::uint32_t blob_id{0U};
    message_priority priority{message_priority::normal};

    auto done_size() const noexcept -> span_size_t;
    auto total_size() const noexcept -> span_size_t {
        EAGINE_ASSERT(io);
        return io->total_size();
    }

    auto buffer_io() noexcept -> buffer_blob_io* {
        return dynamic_cast<buffer_blob_io*>(io.get());
    }

    auto finish_io() noexcept -> finishing_blob_io* {
        return dynamic_cast<finishing_blob_io*>(io.get());
    }

    auto is_at_eod() {
        EAGINE_ASSERT(io);
        return io->is_at_eod(current_position);
    }

    auto fetch(span_size_t offs, memory::block dst) {
        EAGINE_ASSERT(io);
        return io->fetch_fragment(offs, dst);
    }

    auto store(span_size_t offs, memory::const_block src) {
        EAGINE_ASSERT(io);
        return io->store_fragment(offs, src);
    }

    auto check(span_size_t offs, memory::const_block blk) {
        EAGINE_ASSERT(io);
        return io->check_stored(offs, blk);
    }

    auto age() const noexcept -> message_age {
        return std::chrono::duration_cast<message_age>(max_time.elapsed_time());
    }

    auto is_complete() const noexcept -> bool;
    auto merge_fragment(span_size_t offset, memory::const_block) -> bool;
};
//------------------------------------------------------------------------------
class blob_manipulator : main_ctx_object {
public:
    blob_manipulator(main_ctx_parent parent)
      : main_ctx_object{EAGINE_ID(BlobManipl), parent} {}

    auto max_blob_size() const noexcept -> valid_if_positive<span_size_t> {
        return {span_size(_max_blob_size)};
    }

    auto message_size(const pending_blob&, span_size_t max_message_size)
      const noexcept -> span_size_t;

    using io_getter = callable_ref<std::unique_ptr<blob_io>(span_size_t)>;

    auto default_io_getter() noexcept -> io_getter {
        return EAGINE_THIS_MEM_FUNC_REF(_make_io);
    }

    auto cleanup() -> bool;

    auto push_outgoing(
      message_id msg_id,
      identifier_t source_id,
      identifier_t target_id,
      std::unique_ptr<blob_io> io,
      std::chrono::seconds max_time,
      message_priority priority) -> message_sequence_t;

    auto push_outgoing(
      message_id msg_id,
      identifier_t source_id,
      identifier_t target_id,
      memory::const_block src,
      std::chrono::seconds max_time,
      message_priority priority) -> message_sequence_t;

    auto push_incoming_fragment(
      message_id msg_id,
      identifier_t source_id,
      std::uint32_t blob_id,
      std::int64_t offset,
      std::int64_t total,
      io_getter get_io,
      memory::const_block fragment,
      message_priority priority) -> bool;

    using filter_function = callable_ref<bool(message_id)>;

    auto process_incoming(
      filter_function filter,
      io_getter get_io,
      const message_view& message) -> bool;

    auto process_incoming(filter_function filter, const message_view& message)
      -> bool {
        return process_incoming(filter, default_io_getter(), message);
    }

    using fetch_handler =
      callable_ref<bool(message_id, message_age, const message_view&)>;

    auto fetch_all(fetch_handler) -> span_size_t;

    using send_handler = callable_ref<bool(message_id, const message_view&)>;

    auto has_outgoing() const noexcept -> bool {
        return !_outgoing.empty();
    }
    auto process_outgoing(send_handler, span_size_t max_data_size) -> bool;

private:
    std::int64_t _max_blob_size{1024 * 1024 * 1024};
    std::uint32_t _blob_id_sequence{0};
    memory::buffer _scratch_buffer{};
    memory::buffer_pool _buffers{};
    std::vector<pending_blob> _outgoing{};
    std::vector<pending_blob> _incoming{};

    auto _make_io(span_size_t total_size) -> std::unique_ptr<blob_io>;
    auto _scratch_block(span_size_t size) -> memory::block;
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/message_bus/blobs.inl>
#endif
#endif // EAGINE_MESSAGE_BUS_BLOBS_HPP
