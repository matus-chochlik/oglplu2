/**
 *  @file eagine/msg_bus/loopback.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MSG_BUS_LOOPBACK_HPP
#define EAGINE_MSG_BUS_LOOPBACK_HPP

#include "connection.hpp"
#include <mutex>

namespace eagine {
//------------------------------------------------------------------------------
class message_bus_loopback_connection : public message_bus_connection {
public:
    void send(
      identifier_t class_id,
      identifier_t method_id,
      const message_view& message) {
        std::unique_lock lock{_mutex};
        _messages.push(class_id, method_id, message);
    }

    void fetch_messages(
      message_bus_connection::fetch_handler handler) noexcept {
        std::unique_lock lock{_mutex};
        _messages.fetch_all(handler);
    }

private:
    std::mutex _mutex;
    message_storage _messages;
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_MSG_BUS_LOOPBACK_HPP

