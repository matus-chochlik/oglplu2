/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MESSAGE_BUS_SERVICE_STATISTICS_HPP
#define EAGINE_MESSAGE_BUS_SERVICE_STATISTICS_HPP

#include "../serialize.hpp"
#include "../signal.hpp"
#include "../subscriber.hpp"
#include "../types.hpp"

namespace eagine::msgbus {
//------------------------------------------------------------------------------
/// @brief Service observing message bus node network statistics.
/// @ingroup msgbus
/// @see service_composition
template <typename Base = subscriber>
class statistics_consumer : public Base {
    using This = statistics_consumer;

public:
    /// @brief Queries the statistics information of the specified bus node.
    /// @see discover_statistics
    void query_statistics(identifier_t node_id) {
        message_view message{};
        message.set_target_id(node_id);
        const auto msg_id{EAGINE_MSGBUS_ID(statsQuery)};
        this->bus_node().post(msg_id, message);
    }

    /// @brief Broadcasts network statistics query to all message bus nodes.
    /// @see query_statistics
    void discover_statistics() {
        query_statistics(broadcast_endpoint_id());
    }

    /// @brief Triggered on receipt of router node statistics information.
    /// @see router_disappeared
    /// @see bridge_stats_received
    /// @see endpoint_stats_received
    /// @see connection_stats_received
    signal<void(identifier_t, const router_statistics&)> router_stats_received;

    /// @brief Triggered on receipt of bridge node statistics information.
    /// @see bridge_disappeared
    /// @see router_stats_received
    /// @see endpoint_stats_received
    /// @see connection_stats_received
    signal<void(identifier_t, const bridge_statistics&)> bridge_stats_received;

    /// @brief Triggered on receipt of endpoint node statistics information.
    /// @see endpoint_disappeared
    /// @see router_stats_received
    /// @see bridge_stats_received
    /// @see connection_stats_received
    signal<void(identifier_t, const endpoint_statistics&)>
      endpoint_stats_received;

    /// @brief Triggered on receipt of connection statistics information.
    /// @see router_stats_received
    /// @see bridge_stats_received
    /// @see endpoint_stats_received
    signal<void(const connection_statistics&)> connection_stats_received;

protected:
    using Base::Base;

    void add_methods() {
        Base::add_methods();
        Base::add_method(
          this, EAGINE_MSG_MAP(eagiMsgBus, statsRutr, This, _handle_router));
        Base::add_method(
          this, EAGINE_MSG_MAP(eagiMsgBus, statsBrdg, This, _handle_bridge));
        Base::add_method(
          this, EAGINE_MSG_MAP(eagiMsgBus, statsEndpt, This, _handle_endpoint));
    }

private:
    auto _handle_router(const message_context&, stored_message& message)
      -> bool {
        router_statistics stats{};
        if(default_deserialize(stats, message.content())) {
            router_stats_received(message.source_id, stats);
        }
        return true;
    }

    auto _handle_bridge(const message_context&, stored_message& message)
      -> bool {
        bridge_statistics stats{};
        if(default_deserialize(stats, message.content())) {
            bridge_stats_received(message.source_id, stats);
        }
        return true;
    }

    auto _handle_endpoint(const message_context&, stored_message& message)
      -> bool {
        endpoint_statistics stats{};
        if(default_deserialize(stats, message.content())) {
            endpoint_stats_received(message.source_id, stats);
        }
        return true;
    }

    auto _handle_connection(const message_context&, stored_message& message)
      -> bool {
        connection_statistics stats{};
        if(default_deserialize(stats, message.content())) {
            connection_stats_received(stats);
        }
        return true;
    }
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_SERVICE_STATISTICS_HPP
