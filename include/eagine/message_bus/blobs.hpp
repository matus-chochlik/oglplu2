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
#include "../logging/logger.hpp"
#include "../memory/buffer_pool.hpp"
#include "../memory/split_block.hpp"
#include "../timeout.hpp"
#include "message.hpp"
#include <cstdint>

namespace eagine {
namespace msgbus {
//------------------------------------------------------------------------------
struct pending_blob {
    identifier_t class_id{0U};
    identifier_t method_id{0U};
    identifier_t target_id{0U};
    std::uint64_t blob_id{0U};
    memory::buffer blob{};
    memory::const_split_block current{};
    timeout max_time{};
    message_priority priority{message_priority::normal};
};
//------------------------------------------------------------------------------
class blob_manipulator {
private:
    std::uint64_t _blob_id_sequence{0};
    memory::buffer_pool _buffers{};
    std::vector<pending_blob> _outgoing{};
    std::vector<pending_blob> _incoming{};

public:
    bool cleanup();

    void push_outgoing(
      identifier_t class_id,
      identifier_t method_id,
      identifier_t target_id,
      memory::const_block blob,
      std::chrono::seconds max_time,
      message_priority priority);

    using handler = callable_ref<void(pending_blob&)>;

    void for_each_outgoing(handler);

    using send_handler =
      callable_ref<bool(identifier_t, identifier_t, const message_view&)>;

    bool process_outgoing(send_handler, span_size_t message_size, logger&);
};
//------------------------------------------------------------------------------
} // namespace msgbus
} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/message_bus/blobs.inl>
#endif
#endif // EAGINE_MESSAGE_BUS_BLOBS_HPP

