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
class subscriber_topology : public Base {
    using This = subscriber_topology;

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
    virtual void process_router(const router_topology_info& info) = 0;

private:
    bool _handle_router(stored_message& message) {
        router_topology_info info{};
        if(default_deserialize(info, message.content())) {
            process_router(info);
        }
        return true;
    }

    bool _handle_bridge(stored_message&) {
        // TODO
        return true;
    }

    bool _handle_endpoint(stored_message&) {
        // TODO
        return true;
    }
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_SERVICE_TOPOLOGY_HPP

