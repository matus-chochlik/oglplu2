/**
 *  @file eagine/msg_bus/acceptor.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MSG_BUS_ACCEPTOR_HPP
#define EAGINE_MSG_BUS_ACCEPTOR_HPP

#include "connection.hpp"

namespace eagine {
//------------------------------------------------------------------------------
struct message_bus_acceptor {
    virtual ~message_bus_acceptor() noexcept = default;
    message_bus_acceptor() noexcept = default;
    message_bus_acceptor(message_bus_acceptor&&) noexcept = default;
    message_bus_acceptor(const message_bus_acceptor&) = delete;
    message_bus_acceptor& operator=(message_bus_acceptor&&) = delete;
    message_bus_acceptor& operator=(const message_bus_acceptor&) = delete;

    using accept_handler =
      callable_ref<void(std::unique_ptr<message_bus_connection>)>;

    virtual void process_accepted(const accept_handler& handler) = 0;
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_MSG_BUS_ACCEPTOR_HPP

