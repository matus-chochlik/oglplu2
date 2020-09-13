/**
 *  @file eagine/message_bus/service/topology.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MESSAGE_BUS_SERVICE_TOPOLOGY_HPP
#define EAGINE_MESSAGE_BUS_SERVICE_TOPOLOGY_HPP

#include "../serialize.hpp"
#include "../subscriber.hpp"

namespace eagine::msgbus {
//------------------------------------------------------------------------------
template <typename Base = subscriber>
class network_topology : public Base {
    using This = network_topology;

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
    }

public:
    void discover_topology() {
        message_view message{};
        message.set_target_id(broadcast_endpoint_id());
        auto msg_id{EAGINE_MSG_ID(eagiMsgBus, topoQuery)};
        this->bus().post(msg_id, message);
    }

    virtual void router_appeared(const router_topology_info& info) = 0;
    virtual void bridge_appeared(const bridge_topology_info& info) = 0;
    virtual void endpoint_appeared(const endpoint_topology_info& info) = 0;

private:
    bool _handle_router(stored_message& message) {
        router_topology_info info{};
        if(default_deserialize(info, message.content())) {
            router_appeared(info);
        }
        return true;
    }

    bool _handle_bridge(stored_message& message) {
        bridge_topology_info info{};
        if(default_deserialize(info, message.content())) {
            bridge_appeared(info);
        }
        return true;
    }

    bool _handle_endpoint(stored_message& message) {
        endpoint_topology_info info{};
        if(default_deserialize(info, message.content())) {
            endpoint_appeared(info);
        }
        return true;
    }
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_SERVICE_TOPOLOGY_HPP
