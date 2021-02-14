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
struct pending_blob {
    message_id msg_id{};
    identifier_t source_id{0U};
    identifier_t target_id{0U};
    std::uint64_t blob_id{0U};
    memory::buffer blob{};
    memory::const_split_block current{};
    // TODO: recycle the done parts vectors?
    double_buffer<std::vector<std::tuple<span_size_t, span_size_t>>>
      done_parts{};
    timeout max_time{};
    message_priority priority{message_priority::normal};

    void init();
    auto done_size() const noexcept -> span_size_t;
    auto total_size() const noexcept -> span_size_t {
        return blob.size();
    }

    auto age() const noexcept -> message_age {
        return std::chrono::duration_cast<message_age>(max_time.elapsed_time());
    }

    auto is_complete() const noexcept -> bool;
    auto merge_fragment(span_size_t offset, memory::const_block) -> bool;
};
//------------------------------------------------------------------------------
class blob_manipulator : main_ctx_object {
private:
    std::int64_t _max_blob_size{16 * 1024 * 1024};
    std::uint64_t _blob_id_sequence{0};
    memory::buffer _scratch_buffer{};
    memory::buffer_pool _buffers{};
    std::vector<pending_blob> _outgoing{};
    std::vector<pending_blob> _incoming{};

    auto _scratch_block(span_size_t size) -> memory::block;

public:
    blob_manipulator(main_ctx_parent parent)
      : main_ctx_object{EAGINE_ID(BlobManipl), parent} {}

    auto max_blob_size() const noexcept -> valid_if_positive<span_size_t> {
        return {span_size(_max_blob_size)};
    }

    auto message_size(const pending_blob&, span_size_t max_message_size)
      const noexcept -> span_size_t;

    auto cleanup() -> bool;

    void push_outgoing(
      message_id msg_id,
      identifier_t source_id,
      identifier_t target_id,
      memory::const_block blob,
      std::chrono::seconds max_time,
      message_priority priority);

    auto push_incoming_fragment(
      message_id msg_id,
      identifier_t source_id,
      identifier_t blob_id,
      std::int64_t offset,
      std::int64_t total,
      memory::const_block fragment,
      message_priority priority) -> bool;

    using filter_function = callable_ref<bool(message_id)>;

    auto process_incoming(filter_function, const message_view&) -> bool;

    using fetch_handler =
      callable_ref<bool(message_id, message_age, const message_view&)>;

    auto fetch_all(fetch_handler) -> span_size_t;

    using send_handler = callable_ref<bool(message_id, const message_view&)>;

    auto has_outgoing() const noexcept -> bool {
        return !_outgoing.empty();
    }
    auto process_outgoing(send_handler, span_size_t max_data_size) -> bool;
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/message_bus/blobs.inl>
#endif
#endif // EAGINE_MESSAGE_BUS_BLOBS_HPP
