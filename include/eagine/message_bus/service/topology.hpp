/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MESSAGE_BUS_SERVICE_TOPOLOGY_HPP
#define EAGINE_MESSAGE_BUS_SERVICE_TOPOLOGY_HPP

#include "../serialize.hpp"
#include "../signal.hpp"
#include "../subscriber.hpp"

namespace eagine::msgbus {
//------------------------------------------------------------------------------
/// @brief Service observing message bus node network topology.
/// @ingroup msgbus
/// @see service_composition
template <typename Base = subscriber>
class network_topology : public Base {
    using This = network_topology;

public:
    /// @brief Queries the topology information of the specified bus node.
    /// @see discover_topology
    void query_topology(identifier_t node_id) {
        message_view message{};
        message.set_target_id(node_id);
        const auto msg_id{EAGINE_MSGBUS_ID(topoQuery)};
        this->bus_node().post(msg_id, message);
    }

    /// @brief Broadcasts network topology query to all message bus nodes.
    /// @see query_topology
    void discover_topology() {
        query_topology(broadcast_endpoint_id());
    }

    /// @brief Triggered on receipt of router node topology information.
    /// @see router_disappeared
    /// @see bridge_appeared
    /// @see endpoint_appeared
    signal<void(const router_topology_info&)> router_appeared;

    /// @brief Triggered on receipt of bridge node topology information.
    /// @see bridge_disappeared
    /// @see router_appeared
    /// @see endpoint_appeared
    signal<void(const bridge_topology_info&)> bridge_appeared;

    /// @brief Triggered on receipt of endpoint node topology information.
    /// @see endpoint_disappeared
    /// @see router_appeared
    /// @see bridge_appeared
    signal<void(const endpoint_topology_info&)> endpoint_appeared;

    /// @brief Triggered on receipt of bye-bye message from a router node.
    /// @see router_appeared
    /// @see bridge_disappeared
    /// @see endpoint_disappeared
    signal<void(identifier_t)> router_disappeared;

    /// @brief Triggered on receipt of bye-bye message from a bridge node.
    /// @see bridge_appeared
    /// @see router_disappeared
    /// @see endpoint_disappeared
    signal<void(identifier_t)> bridge_disappeared;

    /// @brief Triggered on receipt of bye-bye message from an endpoint node.
    /// @see endpoint_appeared
    /// @see router_disappeared
    /// @see bridge_disappeared
    signal<void(identifier_t)> endpoint_disappeared;

protected:
    using Base::Base;

    void add_methods() {
        Base::add_methods();
        Base::add_method(
          this, EAGINE_MSG_MAP(eagiMsgBus, topoRutrCn, This, _handle_router));
        Base::add_method(
          this, EAGINE_MSG_MAP(eagiMsgBus, topoBrdgCn, This, _handle_bridge));
        Base::add_method(
          this, EAGINE_MSG_MAP(eagiMsgBus, topoEndpt, This, _handle_endpoint));
        Base::add_method(
          this,
          EAGINE_MSG_MAP(eagiMsgBus, byeByeRutr, This, _handle_router_bye));
        Base::add_method(
          this,
          EAGINE_MSG_MAP(eagiMsgBus, byeByeBrdg, This, _handle_bridge_bye));
        Base::add_method(
          this,
          EAGINE_MSG_MAP(eagiMsgBus, byeByeEndp, This, _handle_endpoint_bye));
    }

private:
    auto _handle_router(const message_context&, stored_message& message)
      -> bool {
        router_topology_info info{};
        if(default_deserialize(info, message.content())) {
            router_appeared(info);
        }
        return true;
    }

    auto _handle_bridge(const message_context&, stored_message& message)
      -> bool {
        bridge_topology_info info{};
        if(default_deserialize(info, message.content())) {
            bridge_appeared(info);
        }
        return true;
    }

    auto _handle_endpoint(const message_context&, stored_message& message)
      -> bool {
        endpoint_topology_info info{};
        if(default_deserialize(info, message.content())) {
            endpoint_appeared(info);
        }
        return true;
    }

    auto _handle_router_bye(const message_context&, stored_message& message)
      -> bool {
        router_disappeared(message.source_id);
        return true;
    }

    auto _handle_bridge_bye(const message_context&, stored_message& message)
      -> bool {
        bridge_disappeared(message.source_id);
        return true;
    }

    auto _handle_endpoint_bye(const message_context&, stored_message& message)
      -> bool {
        endpoint_disappeared(message.source_id);
        return true;
    }
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_SERVICE_TOPOLOGY_HPP
