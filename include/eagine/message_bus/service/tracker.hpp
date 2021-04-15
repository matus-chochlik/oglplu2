/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MESSAGE_BUS_SERVICE_TRACKER_HPP
#define EAGINE_MESSAGE_BUS_SERVICE_TRACKER_HPP

#include "../remote_node.hpp"
#include "../serialize.hpp"
#include "../subscriber.hpp"
#include "build_info.hpp"
#include "discovery.hpp"
#include "endpoint_info.hpp"
#include "host_info.hpp"
#include "ping_pong.hpp"
#include "system_info.hpp"
#include "topology.hpp"

namespace eagine::msgbus {
//------------------------------------------------------------------------------
template <typename Base>
using node_tracker_base =
  pinger<system_info_consumer<host_info_consumer<build_info_consumer<
    endpoint_info_consumer<network_topology<subscriber_discovery<Base>>>>>>>;
//------------------------------------------------------------------------------
template <typename Base = subscriber>
class node_tracker : public node_tracker_base<Base> {

    using This = node_tracker;
    using base = node_tracker_base<Base>;

public:
    signal<void(remote_node&, remote_node_changes)> node_changed;

protected:
    node_tracker(endpoint& bus)
      : base{bus} {
        this->reported_alive.connect({this, EAGINE_THIS_MEM_FUNC_C(is_alive)});
        this->subscribed.connect({this, EAGINE_THIS_MEM_FUNC_C(on_subscribed)});
        this->unsubscribed.connect(
          {this, EAGINE_THIS_MEM_FUNC_C(on_unsubscribed)});
        this->not_subscribed.connect(
          {this, EAGINE_THIS_MEM_FUNC_C(on_not_subscribed)});
        this->host_id_received.connect(
          {this, EAGINE_THIS_MEM_FUNC_C(on_host_id_received)});
        this->hostname_received.connect(
          {this, EAGINE_THIS_MEM_FUNC_C(on_hostname_received)});
        this->router_appeared.connect(
          {this, EAGINE_THIS_MEM_FUNC_C(on_router_appeared)});
        this->bridge_appeared.connect(
          {this, EAGINE_THIS_MEM_FUNC_C(on_bridge_appeared)});
        this->endpoint_appeared.connect(
          {this, EAGINE_THIS_MEM_FUNC_C(on_endpoint_appeared)});
        this->endpoint_info_received.connect(
          {this, EAGINE_THIS_MEM_FUNC_C(on_endpoint_info_received)});
        this->build_info_received.connect(
          {this, EAGINE_THIS_MEM_FUNC_C(on_build_info_received)});
        this->cpu_concurrent_threads_received.connect(
          {this, EAGINE_THIS_MEM_FUNC_C(on_cpu_concurrent_threads_received)});
        this->short_average_load_received.connect(
          {this, EAGINE_THIS_MEM_FUNC_C(on_short_average_load_received)});
        this->long_average_load_received.connect(
          {this, EAGINE_THIS_MEM_FUNC_C(on_long_average_load_received)});
        this->free_ram_size_received.connect(
          {this, EAGINE_THIS_MEM_FUNC_C(on_free_ram_size_received)});
        this->total_ram_size_received.connect(
          {this, EAGINE_THIS_MEM_FUNC_C(on_total_ram_size_received)});
        this->free_swap_size_received.connect(
          {this, EAGINE_THIS_MEM_FUNC_C(on_free_swap_size_received)});
        this->total_swap_size_received.connect(
          {this, EAGINE_THIS_MEM_FUNC_C(on_total_swap_size_received)});
    }

    void add_methods() {
        base::add_methods();
    }

    auto update() -> bool {
        some_true something_done{};
        something_done(base::update());

        if(_should_query_topology) {
            this->discover_topology();
            something_done();
        }

        const bool should_query_info{_should_query_info};

        _tracker.for_each_node_state([&](auto node_id, auto& node) {
            if(should_query_info) {
                if(!node.host_id()) {
                    this->query_host_id(node_id);
                }
                if(!node.has_endpoint_info()) {
                    this->query_endpoint_info(node_id);
                }
                if(!node.instance().build()) {
                    this->query_build_info(node_id);
                }
                if(node.is_responsive()) {
                    if(auto host = node.host_state()) {
                        if(!host.name()) {
                            this->query_hostname(node_id);
                        }
                        if(!host.cpu_concurrent_threads()) {
                            this->query_cpu_concurrent_threads(node_id);
                        }
                        if(!host.total_ram_size()) {
                            this->query_total_ram_size(node_id);
                        }
                        if(!host.total_swap_size()) {
                            this->query_total_swap_size(node_id);
                        }
                        const bool should_query_sensors =
                          host.should_query_sensors();
                        if(should_query_sensors) {
                            this->query_short_average_load(node_id);
                            this->query_long_average_load(node_id);
                            this->query_free_ram_size(node_id);
                            this->query_free_swap_size(node_id);
                            host.sensors_queried();
                        }
                    }
                }
            }

            if(node.is_pingable()) {
                const auto [should_ping, max_time] = node.should_ping();
                if(should_ping) {
                    this->ping(node_id, max_time);
                    node.pinged();
                    something_done();
                }
            }
            _handle_node_change(node_id, node);
        });

        return something_done;
    }

    template <typename Function>
    void for_each_node(Function function) {
        _tracker.for_each_node(std::move(function));
    }

private:
    resetting_timeout _should_query_topology{std::chrono::seconds{15}, nothing};
    resetting_timeout _should_query_info{std::chrono::seconds{10}};

    remote_node_tracker _tracker{};

    auto _get_host(identifier_t id) -> remote_host_state& {
        return _tracker.get_host(id);
    }

    auto _get_instance(identifier_t id) -> remote_instance_state& {
        return _tracker.get_instance(id);
    }

    auto _get_node(identifier_t id) -> remote_node_state& {
        return _tracker.get_node(id);
    }

    auto _get_connection(identifier_t id1, identifier_t id2)
      -> node_connection_state& {
        return _tracker.get_connection(id1, id2);
    }

    void _handle_node_change(identifier_t node_id, remote_node_state& node) {
        if(const auto changes{node.changes()}) {
            node_changed(node, changes);
            if(EAGINE_UNLIKELY(changes.new_instance())) {
                this->query_endpoint_info(node_id);
                this->query_host_id(node_id);
                this->query_hostname(node_id);
                this->query_subscriptions_of(node_id);
            }
        }
    }

    void is_alive(const subscriber_info& info) {
        _tracker.notice_instance(info.endpoint_id, info.instance_id);
    }

    void on_subscribed(const subscriber_info& info, message_id msg_id) {
        _tracker.notice_instance(info.endpoint_id, info.instance_id)
          .add_subscription(msg_id);
    }

    void on_unsubscribed(const subscriber_info& info, message_id msg_id) {
        _tracker.notice_instance(info.endpoint_id, info.instance_id)
          .remove_subscription(msg_id);
    }

    void on_not_subscribed(const subscriber_info& info, message_id msg_id) {
        _tracker.notice_instance(info.endpoint_id, info.instance_id)
          .remove_subscription(msg_id);
    }

    void on_router_appeared(const router_topology_info& info) {
        _tracker.notice_instance(info.router_id, info.instance_id)
          .assign(node_kind::router);
        if(info.remote_id) {
            _get_connection(info.router_id, info.remote_id)
              .set_kind(info.connect_kind);
        }
    }

    void on_bridge_appeared(const bridge_topology_info& info) {
        _tracker.notice_instance(info.bridge_id, info.instance_id)
          .assign(node_kind::bridge);
        if(info.opposite_id) {
            _get_connection(info.bridge_id, info.opposite_id)
              .set_kind(connection_kind::remote_interprocess);
        }
    }

    void on_endpoint_appeared(const endpoint_topology_info& info) {
        _tracker.notice_instance(info.endpoint_id, info.instance_id)
          .assign(node_kind::endpoint);
    }

    void on_endpoint_info_received(
      const result_context& ctx,
      const endpoint_info& info) {
        _get_node(ctx.source_id()).assign(info).notice_alive();
    }

    void on_host_id_received(
      const result_context& ctx,
      const valid_if_positive<host_id_t>& host_id) {
        if(host_id) {
            _get_node(ctx.source_id())
              .set_host_id(extract(host_id))
              .notice_alive();
        }
    }

    void on_hostname_received(
      const result_context& ctx,
      const valid_if_not_empty<std::string>& hostname) {
        if(hostname) {
            auto& node = _get_node(ctx.source_id());
            if(auto host_id{node.host_id()}) {
                auto& host = _get_host(extract(host_id));
                host.set_hostname(extract(hostname)).notice_alive();
                _tracker.for_each_host_node_state(
                  extract(host_id), [&](auto, auto& host_node) {
                      host_node.add_change(remote_node_change::host_info);
                  });
            }
        }
    }

    void
    on_build_info_received(const result_context& ctx, const build_info& info) {
        auto& node = _get_node(ctx.source_id()).notice_alive();
        if(auto inst_id{node.instance_id()}) {
            auto& inst = _get_instance(extract(inst_id));
            inst.assign(info);
            _tracker.for_each_host_node_state(
              extract(inst_id), [&](auto, auto& inst_node) {
                  inst_node.add_change(remote_node_change::build_info);
              });
        }
    }

    void on_cpu_concurrent_threads_received(
      const result_context& ctx,
      const valid_if_positive<span_size_t>& opt_value) {
        if(opt_value) {
            auto& node = _get_node(ctx.source_id()).notice_alive();
            if(auto host_id{node.host_id()}) {
                auto& host = _get_host(extract(host_id)).notice_alive();
                host.set_cpu_concurrent_threads(extract(opt_value));
                _tracker.for_each_host_node_state(
                  extract(host_id), [&](auto, auto& host_node) {
                      host_node.add_change(remote_node_change::hardware_config);
                  });
            }
        }
    }

    void on_short_average_load_received(
      const result_context& ctx,
      const valid_if_nonnegative<float>& opt_value) {
        if(opt_value) {
            auto& node = _get_node(ctx.source_id()).notice_alive();
            if(auto host_id{node.host_id()}) {
                auto& host = _get_host(extract(host_id)).notice_alive();
                host.set_short_average_load(extract(opt_value));
                _tracker.for_each_host_node_state(
                  extract(host_id), [&](auto, auto& host_node) {
                      host_node.add_change(remote_node_change::sensor_values);
                  });
            }
        }
    }

    void on_long_average_load_received(
      const result_context& ctx,
      const valid_if_nonnegative<float>& opt_value) {
        if(opt_value) {
            auto& node = _get_node(ctx.source_id()).notice_alive();
            if(auto host_id{node.host_id()}) {
                auto& host = _get_host(extract(host_id)).notice_alive();
                host.set_long_average_load(extract(opt_value));
                _tracker.for_each_host_node_state(
                  extract(host_id), [&](auto, auto& host_node) {
                      host_node.add_change(remote_node_change::sensor_values);
                  });
            }
        }
    }

    void on_free_ram_size_received(
      const result_context& ctx,
      const valid_if_positive<span_size_t>& opt_value) {
        if(opt_value) {
            auto& node = _get_node(ctx.source_id()).notice_alive();
            if(auto host_id{node.host_id()}) {
                auto& host = _get_host(extract(host_id)).notice_alive();
                host.set_free_ram_size(extract(opt_value));
                _tracker.for_each_host_node_state(
                  extract(host_id), [&](auto, auto& host_node) {
                      host_node.add_change(remote_node_change::sensor_values);
                  });
            }
        }
    }

    void on_total_ram_size_received(
      const result_context& ctx,
      const valid_if_positive<span_size_t>& opt_value) {
        if(opt_value) {
            auto& node = _get_node(ctx.source_id()).notice_alive();
            if(auto host_id{node.host_id()}) {
                auto& host = _get_host(extract(host_id)).notice_alive();
                host.set_total_ram_size(extract(opt_value));
                _tracker.for_each_host_node_state(
                  extract(host_id), [&](auto, auto& host_node) {
                      host_node.add_change(remote_node_change::hardware_config);
                  });
            }
        }
    }

    void on_free_swap_size_received(
      const result_context& ctx,
      const valid_if_nonnegative<span_size_t>& opt_value) {
        if(opt_value) {
            auto& node = _get_node(ctx.source_id()).notice_alive();
            if(auto host_id{node.host_id()}) {
                auto& host = _get_host(extract(host_id)).notice_alive();
                host.set_free_swap_size(extract(opt_value));
                _tracker.for_each_host_node_state(
                  extract(host_id), [&](auto, auto& host_node) {
                      host_node.add_change(remote_node_change::sensor_values);
                  });
            }
        }
    }

    void on_total_swap_size_received(
      const result_context& ctx,
      const valid_if_nonnegative<span_size_t>& opt_value) {
        if(opt_value) {
            auto& node = _get_node(ctx.source_id()).notice_alive();
            if(auto host_id{node.host_id()}) {
                auto& host = _get_host(extract(host_id)).notice_alive();
                host.set_total_swap_size(extract(opt_value));
                _tracker.for_each_host_node_state(
                  extract(host_id), [&](auto, auto& host_node) {
                      host_node.add_change(remote_node_change::hardware_config);
                  });
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
