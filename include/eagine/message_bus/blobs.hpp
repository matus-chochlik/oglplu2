/**
 *  @file eagine/message_bus/blobs.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MESSAGE_BUS_BLOBS_HPP
#define EAGINE_MESSAGE_BUS_BLOBS_HPP

#include "../callable_ref.hpp"
#include "../double_buffer.hpp"
#include "../logging/logger.hpp"
#include "../memory/buffer_pool.hpp"
#include "../memory/split_block.hpp"
#include "../timeout.hpp"
#include "../valid_if/positive.hpp"
#include "message.hpp"
#include <cstdint>
#include <vector>

namespace eagine {
namespace msgbus {
//------------------------------------------------------------------------------
struct pending_blob {
    identifier_t class_id{0U};
    identifier_t method_id{0U};
    identifier_t endpoint_id{0U};
    std::uint64_t blob_id{0U};
    memory::buffer blob{};
    memory::const_split_block current{};
    // TODO: recycle the done parts vectors?
    double_buffer<std::vector<std::tuple<span_size_t, span_size_t>>>
      done_parts{};
    timeout max_time{};
    message_priority priority{message_priority::normal};

    void init();
    span_size_t done_size() const noexcept;
    span_size_t total_size() const noexcept {
        return blob.size();
    }

    bool is_complete() const noexcept;
    bool merge_fragment(span_size_t offset, memory::const_block fragment);
};
//------------------------------------------------------------------------------
class blob_manipulator {
private:
    logger _log{};
    std::int64_t _max_blob_size{16 * 1024 * 1024};
    std::uint64_t _blob_id_sequence{0};
    memory::buffer _scratch_buffer{};
    memory::buffer_pool _buffers{};
    std::vector<pending_blob> _outgoing{};
    std::vector<pending_blob> _incoming{};

    memory::block _scratch_block(span_size_t size);

public:
    blob_manipulator() = default;
    blob_manipulator(logger& parent)
      : _log{EAGINE_ID(BlobManipl), parent} {
    }

    valid_if_positive<span_size_t> max_blob_size() const noexcept {
        return {span_size(_max_blob_size)};
    }

    span_size_t message_size(
      const pending_blob&, span_size_t max_message_size) const noexcept;

    bool cleanup();

    void push_outgoing(
      identifier_t class_id,
      identifier_t method_id,
      identifier_t target_id,
      memory::const_block blob,
      std::chrono::seconds max_time,
      message_priority priority);

    bool push_incoming_fragment(
      identifier_t class_id,
      identifier_t method_id,
      identifier_t source_id,
      identifier_t blob_id,
      std::int64_t offset,
      std::int64_t total,
      memory::const_block fragment,
      message_priority priority);

    using filter_function = callable_ref<bool(message_id_tuple)>;

    bool process_incoming(filter_function, const message_view&);

    using fetch_handler =
      callable_ref<bool(identifier_t, identifier_t, const message_view&)>;

    span_size_t fetch_all(fetch_handler);

    using send_handler =
      callable_ref<bool(identifier_t, identifier_t, const message_view&)>;

    bool process_outgoing(send_handler, span_size_t max_data_size);
};
//------------------------------------------------------------------------------
} // namespace msgbus
} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/message_bus/blobs.inl>
#endif
#endif // EAGINE_MESSAGE_BUS_BLOBS_HPP

