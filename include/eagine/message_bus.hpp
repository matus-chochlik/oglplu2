/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MESSAGE_BUS_HPP
#define EAGINE_MESSAGE_BUS_HPP

#include "main_ctx_object.hpp"
#include "message_bus/conn_setup.hpp"
#include "message_bus/router_address.hpp"

namespace eagine {

class message_bus_impl;

/// @brief Class providing access to basic message bus functionality.
/// @ingroup main_context
class message_bus : public main_ctx_object {
public:
    message_bus(main_ctx_parent parent) noexcept
      : main_ctx_object{EAGINE_ID(MessageBus), parent}
      , _addr{parent, nothing}
      , _setup{parent, nothing} {}

    void configure(application_config& config) {
        _addr.configure(config);
        _setup.configure(config);
    }

    void setup_acceptors(msgbus::acceptor_user& target) {
        _setup.setup_acceptors(target, _addr);
    }

    void setup_connectors(msgbus::connection_user& target) {
        _setup.setup_connectors(target, _addr);
    }

private:
    msgbus::router_address _addr;
    msgbus::connection_setup _setup;
};

} // namespace eagine

#endif // EAGINE_MESSAGE_BUS_HPP
