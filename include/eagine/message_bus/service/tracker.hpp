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
#include "../service_requirements.hpp"
#include "../subscriber.hpp"
#include "common_info.hpp"
#include "discovery.hpp"
#include "host_info.hpp"
#include "ping_pong.hpp"
#include "statistics.hpp"
#include "system_info.hpp"
#include "topology.hpp"

namespace eagine::msgbus {
//------------------------------------------------------------------------------
/// @brief Alias for base service composition for the message bus node tracker.
/// @ingroup msgbus
/// @see node_tracker
/// @see service_composition
template <typename Base>
using node_tracker_base = require_services<
  Base,
  pinger,
  system_info_consumer,
  common_info_consumers,
  statistics_consumer,
  network_topology,
  subscriber_discovery>;
//------------------------------------------------------------------------------
/// @brief Service that consumes bus topology information and provides it via an API.
/// @ingroup msgbus
/// @see service_composition
///
/// This class subscribes to the signals inherited from the node_tracker_base
/// and tracks the information about the message bus topology, routers, bridges
/// and endpoints, etc.
template <typename Base = subscriber>
class node_tracker : public node_tracker_base<Base> {

    using This = node_tracker;
    using base = node_tracker_base<Base>;

public:
    /// @brief Triggered when message bus host information changes.
    signal<void(remote_host&, remote_host_changes)> host_changed;

    /// @brief Triggered when message bus instance information changes.
    signal<void(remote_instance&, remote_instance_changes)> instance_changed;

    /// @brief Triggered when message bus node information changes.
    signal<void(remote_node&, remote_node_changes)> node_changed;

    /// @brief Returns handler for the node alive message.
    auto on_alive() noexcept {
        return EAGINE_THIS_MEM_FUNC_REF(_handle_alive);
    }

    /// @brief Returns handler for the endpoint subscribed message.
    auto on_subscribed() noexcept {
        return EAGINE_THIS_MEM_FUNC_REF(_handle_subscribed);
    }

    /// @brief Returns handler for the endpoint unsubscribed message.
    auto on_unsubscribed() noexcept {
        return EAGINE_THIS_MEM_FUNC_REF(_handle_unsubscribed);
    }

    /// @brief Returns handler for the endpoint not subscribed message.
    auto on_not_subscribed() noexcept {
        return EAGINE_THIS_MEM_FUNC_REF(_handle_not_subscribed);
    }

    /// @brief Returns handler for the host id message.
    auto on_host_id_received() noexcept {
        return EAGINE_THIS_MEM_FUNC_REF(_handle_host_id_received);
    }

    /// @brief Returns handler for the host name message.
    auto on_hostname_received() noexcept {
        return EAGINE_THIS_MEM_FUNC_REF(_handle_hostname_received);
    }

    /// @brief Returns handler for the router appeared message.
    auto on_router_appeared() noexcept {
        return EAGINE_THIS_MEM_FUNC_REF(_handle_router_appeared);
    }

    /// @brief Returns handler for the bridge appeared message.
    auto on_bridge_appeared() noexcept {
        return EAGINE_THIS_MEM_FUNC_REF(_handle_bridge_appeared);
    }

    /// @brief Returns handler for the endpoint appeared message.
    auto on_endpoint_appeared() noexcept {
        return EAGINE_THIS_MEM_FUNC_REF(_handle_endpoint_appeared);
    }

    /// @brief Returns handler for the router bye message.
    auto on_router_disappeared() noexcept {
        return EAGINE_THIS_MEM_FUNC_REF(_handle_router_disappeared);
    }

    /// @brief Returns handler for the bridge bye message.
    auto on_bridge_disappeared() noexcept {
        return EAGINE_THIS_MEM_FUNC_REF(_handle_bridge_disappeared);
    }

    /// @brief Returns handler for the endpoint bye message.
    auto on_endpoint_disappeared() noexcept {
        return EAGINE_THIS_MEM_FUNC_REF(_handle_endpoint_disappeared);
    }

    /// @brief Returns handler for the router statistics message.
    auto on_router_stats_received() noexcept {
        return EAGINE_THIS_MEM_FUNC_REF(_handle_router_stats_received);
    }

    /// @brief Returns handler for the bridge statistics message.
    auto on_bridge_stats_received() noexcept {
        return EAGINE_THIS_MEM_FUNC_REF(_handle_bridge_stats_received);
    }

    /// @brief Returns handler for the endpoint statistics message.
    auto on_endpoint_stats_received() noexcept {
        return EAGINE_THIS_MEM_FUNC_REF(_handle_endpoint_stats_received);
    }

    /// @brief Returns handler for the connection statistics message.
    auto on_connection_stats_received() noexcept {
        return EAGINE_THIS_MEM_FUNC_REF(_handle_connection_stats_received);
    }

    /// @brief Returns handler for the application name message.
    auto on_application_name_received() noexcept {
        return EAGINE_THIS_MEM_FUNC_REF(_handle_application_name_received);
    }

    /// @brief Returns handler for the endpoint info message.
    auto on_endpoint_info_received() noexcept {
        return EAGINE_THIS_MEM_FUNC_REF(_handle_endpoint_info_received);
    }

    /// @brief Returns handler for the compiler info message.
    auto on_compiler_info_received() noexcept {
        return EAGINE_THIS_MEM_FUNC_REF(_handle_compiler_info_received);
    }

    /// @brief Returns handler for the build info message.
    auto on_build_info_received() noexcept {
        return EAGINE_THIS_MEM_FUNC_REF(_handle_build_info_received);
    }

    /// @brief Returns handler for the CPU concurent threads message.
    auto on_cpu_concurrent_threads_received() noexcept {
        return EAGINE_THIS_MEM_FUNC_REF(
          _handle_cpu_concurrent_threads_received);
    }

    /// @brief Returns handler for the host short load message.
    auto on_short_average_load_received() noexcept {
        return EAGINE_THIS_MEM_FUNC_REF(_handle_short_average_load_received);
    }

    /// @brief Returns handler for the host long load message.
    auto on_long_average_load_received() noexcept {
        return EAGINE_THIS_MEM_FUNC_REF(_handle_long_average_load_received);
    }

    /// @brief Returns handler for the free ram size message.
    auto on_free_ram_size_received() noexcept {
        return EAGINE_THIS_MEM_FUNC_REF(_handle_free_ram_size_received);
    }

    /// @brief Returns handler for the total ram size message.
    auto on_total_ram_size_received() noexcept {
        return EAGINE_THIS_MEM_FUNC_REF(_handle_total_ram_size_received);
    }

    /// @brief Returns handler for the free swap size message.
    auto on_free_swap_size_received() noexcept {
        return EAGINE_THIS_MEM_FUNC_REF(_handle_free_swap_size_received);
    }

    /// @brief Returns handler for the total swap size message.
    auto on_total_swap_size_received() noexcept {
        return EAGINE_THIS_MEM_FUNC_REF(_handle_total_swap_size_received);
    }

    /// @brief Returns handler for the temperature min/max message.
    auto on_temperature_min_max_received() noexcept {
        return EAGINE_THIS_MEM_FUNC_REF(_handle_temperature_min_max_received);
    }

    /// @brief Returns handler for the power supply kind message.
    auto on_power_supply_kind_received() noexcept {
        return EAGINE_THIS_MEM_FUNC_REF(_handle_power_supply_kind_received);
    }

    /// @brief Returns handler for the ping response message.
    auto on_ping_response() noexcept {
        return EAGINE_THIS_MEM_FUNC_REF(_handle_ping_response);
    }

    /// @brief Returns handler for the ping timeout event.
    auto on_ping_timeout() noexcept {
        return EAGINE_THIS_MEM_FUNC_REF(_handle_ping_timeout);
    }

    auto update() -> work_done {
        some_true something_done{};
        something_done(base::update());

        if(_should_query_topology) {
            this->discover_topology();
            something_done();
        }

        if(_should_query_stats) {
            this->discover_statistics();
            something_done();
        }

        const bool should_query_info{_should_query_info};

        _tracker.for_each_host_state([&](auto host_id, auto& host) {
            _handle_host_change(host_id, host);
        });

        _tracker.for_each_instance_state([&](auto inst_id, auto& inst) {
            _handle_inst_change(inst_id, inst);
        });

        _tracker.for_each_node_state([&](auto node_id, auto& node) {
            if(should_query_info) {
                if(!node.has_known_kind()) {
                    this->query_topology(node_id);
                }
                if(!node.host_id()) {
                    this->query_host_id(node_id);
                }
                if(!node.has_endpoint_info()) {
                    this->query_endpoint_info(node_id);
                }
                if(!node.instance().compiler()) {
                    this->query_compiler_info(node_id);
                }
                if(!node.instance().build()) {
                    this->query_build_info(node_id);
                }
                if(node.is_responsive()) {
                    if(auto inst{node.instance_state()}) {
                        if(!inst.application_name()) {
                            this->query_application_name(node_id);
                        }
                    }
                    if(auto host{node.host_state()}) {
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

                        if(node.can_query_system_info()) {
                            if(host.should_query_sensors()) {
                                this->query_sensors(node_id);
                                host.sensors_queried();
                            }
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

    /// @brief Calls the specified function for each tracked node.
    template <typename Function>
    void for_each_node(Function function) {
        _tracker.for_each_node(std::move(function));
    }

    /// @brief Returns information about a host with the specified id.
    auto get_host(identifier_t id) -> const remote_host& {
        return _tracker.get_host(id);
    }

    /// @brief Returns information about an instance with the specified id.
    auto get_instance(identifier_t id) -> const remote_instance& {
        return _tracker.get_instance(id);
    }

    /// @brief Returns information about a node with the specified id.
    auto get_node(identifier_t id) -> const remote_node& {
        return _tracker.get_node(id);
    }

protected:
    using base::base;

    void init() {
        base::init();

        this->reported_alive.connect(on_alive());
        this->subscribed.connect(on_subscribed());
        this->unsubscribed.connect(on_unsubscribed());
        this->not_subscribed.connect(on_not_subscribed());
        this->host_id_received.connect(on_host_id_received());
        this->hostname_received.connect(on_hostname_received());
        this->router_appeared.connect(on_router_appeared());
        this->bridge_appeared.connect(on_bridge_appeared());
        this->endpoint_appeared.connect(on_endpoint_appeared());
        this->router_disappeared.connect(on_router_disappeared());
        this->bridge_disappeared.connect(on_bridge_disappeared());
        this->endpoint_disappeared.connect(on_endpoint_disappeared());
        this->router_stats_received.connect(on_router_stats_received());
        this->bridge_stats_received.connect(on_bridge_stats_received());
        this->endpoint_stats_received.connect(on_endpoint_stats_received());
        this->application_name_received.connect(on_application_name_received());
        this->endpoint_info_received.connect(on_endpoint_info_received());
        this->compiler_info_received.connect(on_compiler_info_received());
        this->build_info_received.connect(on_build_info_received());
        this->cpu_concurrent_threads_received.connect(
          on_cpu_concurrent_threads_received());
        this->short_average_load_received.connect(
          on_short_average_load_received());
        this->long_average_load_received.connect(
          on_long_average_load_received());
        this->free_ram_size_received.connect(on_free_ram_size_received());
        this->total_ram_size_received.connect(on_total_ram_size_received());
        this->free_swap_size_received.connect(on_free_swap_size_received());
        this->total_swap_size_received.connect(on_total_swap_size_received());
        this->temperature_min_max_received.connect(
          on_temperature_min_max_received());
        this->power_supply_kind_received.connect(
          on_power_supply_kind_received());
        this->ping_responded.connect(on_ping_response());
        this->ping_timeouted.connect(on_ping_timeout());
    }

    void add_methods() {
        base::add_methods();
    }

private:
    resetting_timeout _should_query_topology{std::chrono::seconds{15}, nothing};
    resetting_timeout _should_query_stats{std::chrono::seconds{30}, nothing};
    resetting_timeout _should_query_info{std::chrono::seconds{5}};

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

    void _handle_host_change(identifier_t, remote_host_state& host) {
        if(const auto changes{host.update().changes()}) {
            host_changed(host, changes);
        }
    }

    void _handle_inst_change(identifier_t, remote_instance_state& inst) {
        if(const auto changes{inst.update().changes()}) {
            instance_changed(inst, changes);
        }
    }

    void _handle_node_change(identifier_t node_id, remote_node_state& node) {
        if(const auto changes{node.update().changes()}) {
            node_changed(node, changes);
            if(EAGINE_UNLIKELY(changes.new_instance())) {
                this->query_endpoint_info(node_id);
                this->query_host_id(node_id);
                this->query_hostname(node_id);
                this->query_subscriptions_of(node_id);
            }
        }
    }

    void _handle_alive(const subscriber_info& info) {
        _tracker.notice_instance(info.endpoint_id, info.instance_id)
          .assign(node_kind::endpoint);
    }

    void _handle_subscribed(const subscriber_info& info, message_id msg_id) {
        _tracker.notice_instance(info.endpoint_id, info.instance_id)
          .add_subscription(msg_id);
    }

    void _handle_unsubscribed(const subscriber_info& info, message_id msg_id) {
        _tracker.notice_instance(info.endpoint_id, info.instance_id)
          .remove_subscription(msg_id);
    }

    void _handle_not_subscribed(const subscriber_info& info, message_id msg_id) {
        _tracker.notice_instance(info.endpoint_id, info.instance_id)
          .remove_subscription(msg_id);
    }

    void _handle_router_appeared(const router_topology_info& info) {
        _tracker.notice_instance(info.router_id, info.instance_id)
          .assign(node_kind::router);
        if(info.remote_id) {
            _get_connection(info.router_id, info.remote_id)
              .set_kind(info.connect_kind);
        }
    }

    void _handle_bridge_appeared(const bridge_topology_info& info) {
        _tracker.notice_instance(info.bridge_id, info.instance_id)
          .assign(node_kind::bridge);
        if(info.opposite_id) {
            _get_connection(info.bridge_id, info.opposite_id)
              .set_kind(connection_kind::remote_interprocess);
        }
    }

    void _handle_endpoint_appeared(const endpoint_topology_info& info) {
        _tracker.notice_instance(info.endpoint_id, info.instance_id)
          .assign(node_kind::endpoint);
    }

    void _handle_router_disappeared(identifier_t router_id) {
        _tracker.remove_node(router_id);
    }

    void _handle_bridge_disappeared(identifier_t bridge_id) {
        _tracker.remove_node(bridge_id);
    }

    void _handle_endpoint_disappeared(identifier_t endpoint_id) {
        _tracker.remove_node(endpoint_id);
    }

    void _handle_router_stats_received(
      identifier_t router_id,
      const router_statistics& stats) {
        _get_node(router_id).assign(stats).notice_alive();
    }

    void _handle_bridge_stats_received(
      identifier_t bridge_id,
      const bridge_statistics& stats) {
        _get_node(bridge_id).assign(stats).notice_alive();
    }

    void _handle_endpoint_stats_received(
      identifier_t endpoint_id,
      const endpoint_statistics& stats) {
        _get_node(endpoint_id).assign(stats).notice_alive();
    }

    void _handle_connection_stats_received(const connection_statistics& stats) {
        _get_connection(stats.local_id, stats.remote_id);
    }

    void _handle_application_name_received(
      const result_context& ctx,
      const valid_if_not_empty<std::string>& app_name) {
        if(app_name) {
            auto& node = _get_node(ctx.source_id());
            if(auto inst_id{node.instance_id()}) {
                auto& inst = _get_instance(extract(inst_id));
                inst.set_app_name(extract(app_name)).notice_alive();
                _tracker.for_each_instance_node_state(
                  extract(inst_id), [&](auto, auto& inst_node) {
                      inst_node.add_change(
                        remote_node_change::application_info);
                  });
            }
        }
    }

    void _handle_endpoint_info_received(
      const result_context& ctx,
      const endpoint_info& info) {
        _get_node(ctx.source_id()).assign(info).notice_alive();
    }

    void _handle_host_id_received(
      const result_context& ctx,
      const valid_if_positive<host_id_t>& host_id) {
        if(host_id) {
            _get_node(ctx.source_id())
              .set_host_id(extract(host_id))
              .notice_alive();
        }
    }

    void _handle_hostname_received(
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

    void _handle_compiler_info_received(
      const result_context& ctx,
      const compiler_info& info) {
        auto& node = _get_node(ctx.source_id()).notice_alive();
        if(auto inst_id{node.instance_id()}) {
            auto& inst = _get_instance(extract(inst_id));
            inst.assign(info);
            _tracker.for_each_instance_node_state(
              extract(inst_id), [&](auto, auto& inst_node) {
                  inst_node.add_change(remote_node_change::build_info);
              });
        }
    }

    void _handle_build_info_received(
      const result_context& ctx,
      const build_info& info) {
        auto& node = _get_node(ctx.source_id()).notice_alive();
        if(auto inst_id{node.instance_id()}) {
            auto& inst = _get_instance(extract(inst_id));
            inst.assign(info);
            _tracker.for_each_instance_node_state(
              extract(inst_id), [&](auto, auto& inst_node) {
                  inst_node.add_change(remote_node_change::build_info);
              });
        }
    }

    void _handle_cpu_concurrent_threads_received(
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

    void _handle_short_average_load_received(
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

    void _handle_long_average_load_received(
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

    void _handle_free_ram_size_received(
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

    void _handle_total_ram_size_received(
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

    void _handle_free_swap_size_received(
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

    void _handle_total_swap_size_received(
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

    void _handle_temperature_min_max_received(
      const result_context& ctx,
      const std::tuple<
        valid_if_positive<kelvins_t<float>>,
        valid_if_positive<kelvins_t<float>>>& value) {
        const auto& [min, max] = value;
        if(min && max) {
            auto& node = _get_node(ctx.source_id()).notice_alive();
            if(auto host_id{node.host_id()}) {
                auto& host = _get_host(extract(host_id)).notice_alive();
                host.set_temperature_min_max(extract(min), extract(max));
                _tracker.for_each_host_node_state(
                  extract(host_id), [&](auto, auto& host_node) {
                      host_node.add_change(remote_node_change::sensor_values);
                  });
            }
        }
    }

    void _handle_power_supply_kind_received(
      const result_context& ctx,
      power_supply_kind value) {
        auto& node = _get_node(ctx.source_id()).notice_alive();
        if(auto host_id{node.host_id()}) {
            auto& host = _get_host(extract(host_id)).notice_alive();
            host.set_power_supply(value);
            _tracker.for_each_host_node_state(
              extract(host_id), [&](auto, auto& host_node) {
                  host_node.add_change(remote_node_change::sensor_values);
              });
        }
    }

    void _handle_ping_response(
      identifier_t node_id,
      message_sequence_t sequence_no,
      std::chrono::microseconds age,
      verification_bits) {
        _get_node(node_id).ping_response(sequence_no, age);
    }

    void _handle_ping_timeout(
      identifier_t node_id,
      message_sequence_t sequence_no,
      std::chrono::microseconds age) {
        _get_node(node_id).ping_timeout(sequence_no, age);
    }
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_SERVICE_TRACKER_HPP
