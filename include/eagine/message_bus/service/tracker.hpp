/**
 *  @file eagine/message_bus/service/tracker.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MESSAGE_BUS_SERVICE_TRACKER_HPP
#define EAGINE_MESSAGE_BUS_SERVICE_TRACKER_HPP

#include "../remote_node.hpp"
#include "../serialize.hpp"
#include "../subscriber.hpp"
#include "discovery.hpp"
#include "host_info.hpp"
#include "ping_pong.hpp"
#include "topology.hpp"

namespace eagine::msgbus {
//------------------------------------------------------------------------------
template <typename Base = subscriber>
class node_tracker
  : public pinger<
      host_info_consumer<network_topology<subscriber_discovery<Base>>>> {

    using This = node_tracker;
    using base =
      pinger<host_info_consumer<network_topology<subscriber_discovery<Base>>>>;

protected:
    using base::base;

    void add_methods() {
        base::add_methods();
    }

public:
    auto update() -> bool {
        some_true something_done{};
        something_done(base::update());

        if(_should_query_topology) {
            this->discover_topology();
            something_done();
        }

        for(auto& [node_id, node] : _nodes) {

            if(node.subscribes_to(this->ping_msg_id())) {
                const auto [should_ping, max_time] = node.should_ping();
                if(should_ping) {
                    this->ping(node_id, max_time);
                    node.pinged();
                    something_done();
                }
            }
        }

        return something_done;
    }

    template <typename Function>
    void for_each_node(Function function) {
        for(auto& [node_id, node] : _nodes) {
            function(node_id, node);
        }
    }

    virtual void on_node_change(remote_node& node) = 0;
    virtual void on_node_host_change(remote_node& node, remote_host& host) = 0;

private:
    // TODO: longer interval
    resetting_timeout _should_query_topology{std::chrono::seconds{5}, nothing};

    flat_map<identifier_t, remote_node_state> _nodes{};

    auto _get_node(identifier_t id) -> remote_node_state& {
        auto pos = _nodes.find(id);
        if(pos == _nodes.end()) {
            pos = _nodes.emplace(id, id).first;
        }
        EAGINE_ASSERT(pos->second.id() == id);
        return pos->second;
    }

    flat_map<identifier_t, remote_host_state> _hosts{};

    auto _get_host(identifier_t id) -> remote_host_state& {
        auto pos = _hosts.find(id);
        if(pos == _hosts.end()) {
            pos = _hosts.emplace(id, id).first;
        }
        EAGINE_ASSERT(pos->second.id() == id);
        return pos->second;
    }

    void on_subscribed(identifier_t node_id, message_id msg_id) final {
        on_node_change(_get_node(node_id).add_subscription(msg_id));
    }

    void on_unsubscribed(identifier_t node_id, message_id msg_id) final {
        on_node_change(_get_node(node_id).remove_subscription(msg_id));
    }

    void not_subscribed(identifier_t node_id, message_id msg_id) final {
        on_node_change(_get_node(node_id).remove_subscription(msg_id));
    }

    void router_appeared(const router_topology_info& info) final {
        on_node_change(_get_node(info.router_id).assign(node_kind::router));
    }

    void bridge_appeared(const bridge_topology_info& info) final {
        on_node_change(_get_node(info.bridge_id).assign(node_kind::bridge));
    }

    void endpoint_appeared(const endpoint_topology_info& info) final {
        on_node_change(_get_node(info.endpoint_id).assign(node_kind::endpoint));
    }

    void on_host_id_received(
      const result_context& ctx,
      valid_if_positive<system_info::host_id_type>&& host_id) final {
        if(host_id) {
            on_node_change(
              _get_node(ctx.source_id()).assign(_get_host(extract(host_id))));
        }
    }

    void on_hostname_received(
      const result_context& ctx,
      valid_if_not_empty<std::string>&& hostname) final {
        if(hostname) {
            auto& node = _get_node(ctx.source_id());
            if(auto host_id{node.host_id()}) {
                auto& host = _get_host(extract(host_id));
                host.set_hostname(std::move(extract(hostname)));
                for(auto& entry : _nodes) {
                    if(std::get<1>(entry).host_id() == extract(host_id)) {
                        on_node_host_change(node, host);
                    }
                }
            }
        }
    }

    void on_ping_response(
      identifier_t node_id,
      message_sequence_t sequence_no,
      std::chrono::microseconds age,
      verification_bits) final {
        _get_node(node_id).ping_response(sequence_no, age);
    }

    void on_ping_timeout(
      identifier_t node_id,
      message_sequence_t sequence_no,
      std::chrono::microseconds age) final {
        _get_node(node_id).ping_timeout(sequence_no, age);
    }
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_SERVICE_TRACKER_HPP
