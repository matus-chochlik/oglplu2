/**
 *  @file eagine/msg_bus/connection.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MSG_BUS_CONNECTION_HPP
#define EAGINE_MSG_BUS_CONNECTION_HPP

#include "../callable_ref.hpp"
#include "../message_id.hpp"
#include "message.hpp"
#include <limits>

namespace eagine {
//------------------------------------------------------------------------------
struct message_bus_connection {
    virtual ~message_bus_connection() noexcept = default;
    message_bus_connection() noexcept = default;
    message_bus_connection(message_bus_connection&&) noexcept = default;
    message_bus_connection(const message_bus_connection&) = delete;
    message_bus_connection& operator=(message_bus_connection&&) = delete;
    message_bus_connection& operator=(const message_bus_connection&) = delete;

    using fetch_handler =
      callable_ref<bool(identifier_t, identifier_t, const message_view&)>;

    virtual void update() {
    }

    virtual bool is_usable() {
        return true;
    }

    virtual span_size_t max_data_size() {
        return std::numeric_limits<span_size_t>::max();
    }

    virtual void send(
      identifier_t class_id, identifier_t method_id, const message_view&) = 0;

    virtual void fetch_messages(fetch_handler handler) = 0;
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_MSG_BUS_CONNECTION_HPP

