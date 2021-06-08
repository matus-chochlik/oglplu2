/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MESSAGE_BUS_ACCEPTOR_HPP
#define EAGINE_MESSAGE_BUS_ACCEPTOR_HPP

#include "connection.hpp"

namespace eagine::msgbus {
//------------------------------------------------------------------------------
/// @brief Interface for message bus connection acceptors.
/// @ingroup msgbus
/// @see acceptor_user
/// @see connection
struct acceptor : connection_info {

    /// @brief Alias for accepted connection handler callable reference type.
    using accept_handler = callable_ref<void(std::unique_ptr<connection>)>;

    /// @brief Updates the internal state of the acceptor (called repeatedly).
    virtual auto update() -> work_done {
        return {};
    }

    /// @brief Lets the handler process the pending accepted connections.
    virtual auto process_accepted(const accept_handler& handler)
      -> work_done = 0;
};
//------------------------------------------------------------------------------
/// @brief Interface for classes that can use message bus connection acceptors.
/// @ingroup msgbus
/// @see acceptor
/// @see connection_user
struct acceptor_user : interface<acceptor_user> {

    /// @brief Adds the specified message bus connection acceptor.
    /// Result indicates if the acceptor was used or discarded.
    virtual auto add_acceptor(std::shared_ptr<acceptor> an_acceptor)
      -> bool = 0;
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_ACCEPTOR_HPP
