/**
 *  @file eagine/message_bus/loopback.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MESSAGE_BUS_LOOPBACK_HPP
#define EAGINE_MESSAGE_BUS_LOOPBACK_HPP

#include "connection.hpp"
#include <mutex>

namespace eagine::msgbus {
//------------------------------------------------------------------------------
class loopback_connection : public connection {
public:
    connection_kind kind() final {
        return connection_kind::in_process;
    }

    connection_addr_kind addr_kind() final {
        return connection_addr_kind::none;
    }

    identifier type_id() final {
        return EAGINE_ID(Loopback);
    }

    bool send(message_id msg_id, const message_view& message) final {
        std::unique_lock lock{_mutex};
        _messages.push(msg_id, message);
        return true;
    }

    bool fetch_messages(connection::fetch_handler handler) final {
        std::unique_lock lock{_mutex};
        return _messages.fetch_all(handler);
    }

private:
    std::mutex _mutex;
    message_storage _messages;
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_LOOPBACK_HPP
