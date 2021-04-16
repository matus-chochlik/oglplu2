/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MESSAGE_BUS_CONN_FACTORY_HPP
#define EAGINE_MESSAGE_BUS_CONN_FACTORY_HPP

#include "acceptor.hpp"
#include "connection.hpp"
#include <memory>

namespace eagine::msgbus {
//------------------------------------------------------------------------------
/// @brief Interface for message bus connection and acceptor factories.
/// @ingroup msgbus
struct connection_factory : connection_info {

    /// @brief Make a new acceptor listening on the specified address.
    /// @see make_connector
    [[nodiscard]] virtual auto make_acceptor(string_view address)
      -> std::unique_ptr<acceptor> = 0;

    /// @brief Make a new connector connecting to the specified address.
    /// @see make_acceptor
    [[nodiscard]] virtual auto make_connector(string_view address)
      -> std::unique_ptr<connection> = 0;

    /// @brief Make a new acceptor listening on a default address.
    /// @see make_connector
    [[nodiscard]] auto make_acceptor() {
        return make_acceptor(string_view{});
    }

    /// @brief Make a new connector connecting to the specified address.
    /// @see make_acceptor
    [[nodiscard]] auto make_connector() {
        return make_connector(string_view{});
    }

    /// @brief Make a new acceptor listening on the specified address.
    /// @see make_connector
    [[nodiscard]] auto make_acceptor(identifier id) {
        return make_acceptor(id.name());
    }

    /// @brief Make a new connector connecting to the specified address.
    /// @see make_acceptor
    [[nodiscard]] auto make_connector(identifier id) {
        return make_connector(id.name());
    }
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_CONN_FACTORY_HPP
