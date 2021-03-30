/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MESSAGE_BUS_LOOPBACK_HPP
#define EAGINE_MESSAGE_BUS_LOOPBACK_HPP

#include "connection.hpp"
#include <mutex>

namespace eagine::msgbus {
//------------------------------------------------------------------------------
/// @brief Loopback implementation of connection. Used mainly for testing and development.
/// @ingroup msgbus
class loopback_connection : public connection {
public:
    auto kind() -> connection_kind final {
        return connection_kind::in_process;
    }

    auto addr_kind() -> connection_addr_kind final {
        return connection_addr_kind::none;
    }

    auto type_id() -> identifier final {
        return EAGINE_ID(Loopback);
    }

    auto send(message_id msg_id, const message_view& message) -> bool final {
        std::unique_lock lock{_mutex};
        _messages.push(msg_id, message);
        return true;
    }

    auto fetch_messages(connection::fetch_handler handler) -> bool final {
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
