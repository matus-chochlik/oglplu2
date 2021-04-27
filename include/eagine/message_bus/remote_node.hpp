/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MESSAGE_BUS_REMOTE_NODE_HPP
#define EAGINE_MESSAGE_BUS_REMOTE_NODE_HPP

#include "../bitfield.hpp"
#include "../build_info.hpp"
#include "../callable_ref.hpp"
#include "../flat_map.hpp"
#include "../identifier_t.hpp"
#include "../message_id.hpp"
#include "../optional_ref.hpp"
#include "../tribool.hpp"
#include "../types.hpp"
#include "../valid_if/ge0_le1.hpp"
#include "../valid_if/nonnegative.hpp"
#include "../valid_if/not_empty.hpp"
#include "../valid_if/not_zero.hpp"
#include "../valid_if/positive.hpp"
#include "node_kind.hpp"
#include "types.hpp"
#include <chrono>
#include <memory>

namespace eagine::msgbus {
//------------------------------------------------------------------------------
/// @brief Enumeration of changes tracked about remote message bus nodes.
/// @ingroup msgbus
/// @see remote_node_changes
/// @see remote_host_change
enum class remote_node_change : std::uint16_t {
    /// @brief The node kind has appeared or changed.
    /// @see node_kind
    kind = 1U << 0U,
    /// @brief The endpoint instance id has changed.
    instance_id = 1U << 1U,
    /// @brief The host identifier has appeared or changed.
    host_id = 1U << 2U,
    /// @brief The host information has appeared or changed.
    host_info = 1U << 3U,
    /// @brief The build information has appeared or changed.
    build_info = 1U << 4U,
    /// @brief The application information has appeared or changed.
    application_info = 1U << 5U,
    /// @brief The endpoint information has appeared or changed.
    endpoint_info = 1U << 6U,
    /// @brief New remotly callable methods have been added.
    methods_added = 1U << 7U,
    /// @brief New remotly callable methods have been removed.
    methods_removed = 1U << 8U,
    /// @brief Node started responding to pings.
    started_responding = 1U << 9U,
    /// @brief Node stopped responding to pings.
    stopped_responding = 1U << 10U,
    /// @brief Node ping response rate.
    response_rate = 1U << 11U,
    /// @brief The hardware configuration information has appeared or changed.
    hardware_config = 1U << 12U,
    /// @brief New sensor values have appeared or changed.
    sensor_values = 1U << 13U,
    /// @brief The bus connection information has appeared or changed.
    connection_info = 1U << 14U
};
//------------------------------------------------------------------------------
template <typename Selector>
constexpr auto
enumerator_mapping(type_identity<remote_node_change>, Selector) noexcept {
    return enumerator_map_type<remote_node_change, 15>{
      {{"kind", remote_node_change::kind},
       {"host_id", remote_node_change::host_id},
       {"host_info", remote_node_change::host_info},
       {"build_info", remote_node_change::build_info},
       {"application_info", remote_node_change::application_info},
       {"endpoint_info", remote_node_change::endpoint_info},
       {"methods_added", remote_node_change::methods_added},
       {"methods_removed", remote_node_change::methods_removed},
       {"started_responding", remote_node_change::started_responding},
       {"stopped_responding", remote_node_change::stopped_responding},
       {"response_rate", remote_node_change::response_rate},
       {"hardware_config", remote_node_change::hardware_config},
       {"sensor_values", remote_node_change::sensor_values},
       {"connection_info", remote_node_change::connection_info},
       {"instance_id", remote_node_change::instance_id}}};
}
//------------------------------------------------------------------------------
/// @brief Class providing and manipulating information about remote node changes.
/// @ingroup msgbus
/// @see remote_host_changes
/// @see remote_instance_changes
struct remote_node_changes : bitfield<remote_node_change> {
    using base = bitfield<remote_node_change>;
    using base::base;

    /// @brief Remote node responsivity has changed.
    auto responsivity() const noexcept -> bool {
        return has_any(
          remote_node_change::started_responding,
          remote_node_change::stopped_responding);
    }

    /// @brief Remote node instance id has changed.
    auto new_instance() const noexcept -> bool {
        return has(remote_node_change::instance_id);
    }
};

static inline auto operator|(remote_node_change l, remote_node_change r) noexcept
  -> remote_node_changes {
    return {l, r};
}
//------------------------------------------------------------------------------
/// @brief Enumeration of changes tracked about remote message bus instances.
/// @ingroup msgbus
/// @see remote_instance_changes
/// @see remote_node_change
enum class remote_instance_change : std::uint16_t {
    /// @brief The host identifier has appeared or changed.
    host_id = 1U << 0U,
    /// @brief Instance started responding.
    started_responding = 1U << 1U,
    /// @brief Instance stopped responding.
    stopped_responding = 1U << 2U,
    /// @brief The build information has appeared or changed.
    build_info = 1U << 3U,
    /// @brief The application information has appeared or changed.
    application_info = 1U << 4U,
    /// @brief New statistics have appeared or changed.
    statistics = 1U << 5U
};
//------------------------------------------------------------------------------
template <typename Selector>
constexpr auto
enumerator_mapping(type_identity<remote_instance_change>, Selector) noexcept {
    return enumerator_map_type<remote_instance_change, 5>{
      {{"host_id", remote_instance_change::host_id},
       {"started_responding", remote_instance_change::started_responding},
       {"stopped_responding", remote_instance_change::stopped_responding},
       {"application_info", remote_instance_change::application_info},
       {"statistics", remote_instance_change::statistics}}};
}
//------------------------------------------------------------------------------
/// @brief Class providing and manipulating information about remote instance changes.
/// @ingroup msgbus
/// @see remote_node_changes
/// @see remote_host_changes
struct remote_instance_changes : bitfield<remote_instance_change> {
    using base = bitfield<remote_instance_change>;
    using base::base;

    /// @brief Remote instance responsivity has changed.
    auto responsivity() const noexcept -> bool {
        return has_any(
          remote_instance_change::started_responding,
          remote_instance_change::stopped_responding);
    }
};

static inline auto
operator|(remote_instance_change l, remote_instance_change r) noexcept
  -> remote_instance_changes {
    return {l, r};
}
//------------------------------------------------------------------------------
/// @brief Enumeration of changes tracked about remote message bus hosts.
/// @ingroup msgbus
/// @see remote_host_changes
/// @see remote_node_change
enum class remote_host_change : std::uint16_t {
    /// @brief The host name has appeared or changed.
    hostname = 1U << 0U,
    /// @brief Host started responding.
    started_responding = 1U << 1U,
    /// @brief Host stopped responding.
    stopped_responding = 1U << 2U,
    /// @brief The hardware configuration information has appeared or changed.
    hardware_config = 1U << 3U,
    /// @brief New sensor values have appeared or changed.
    sensor_values = 1U << 4U
};
//------------------------------------------------------------------------------
template <typename Selector>
constexpr auto
enumerator_mapping(type_identity<remote_host_change>, Selector) noexcept {
    return enumerator_map_type<remote_host_change, 5>{
      {{"hostname", remote_host_change::hostname},
       {"started_responding", remote_host_change::started_responding},
       {"stopped_responding", remote_host_change::stopped_responding},
       {"hardware_config", remote_host_change::hardware_config},
       {"sensor_values", remote_host_change::sensor_values}}};
}
//------------------------------------------------------------------------------
/// @brief Class providing and manipulating information about remote host changes.
/// @ingroup msgbus
/// @see remote_node_changes
/// @see remote_instance_changes
struct remote_host_changes : bitfield<remote_host_change> {
    using base = bitfield<remote_host_change>;
    using base::base;

    /// @brief Remote host responsivity has changed.
    auto responsivity() const noexcept -> bool {
        return has_any(
          remote_host_change::started_responding,
          remote_host_change::stopped_responding);
    }
};

static inline auto operator|(remote_host_change l, remote_host_change r) noexcept
  -> remote_host_changes {
    return {l, r};
}
//------------------------------------------------------------------------------
class remote_node_tracker_impl;
class remote_host_impl;
class remote_host;
class remote_instance_impl;
class remote_instance;
class remote_instance_state;
class remote_host_state;
class remote_node_impl;
class remote_node;
class remote_node_state;
class node_connection_impl;
class node_connection;
class node_connection_state;
class node_connections;
//------------------------------------------------------------------------------
/// @brief Class tracking the state of remote message bus nodes.
/// @ingroup msgbus
/// @see remote_node_changes
/// @see remote_host_changes
class remote_node_tracker {
public:
    /// @brief Default constructor.
    remote_node_tracker();

    remote_node_tracker(nothing_t) noexcept
      : _pimpl{} {}

    remote_node_tracker(std::shared_ptr<remote_node_tracker_impl> pimpl) noexcept
      : _pimpl{std::move(pimpl)} {}

    auto cached(const std::string&) -> string_view;

    /// @brief Finds and returns the state information about a remote bus node.
    /// @see get_host
    /// @see get_instance
    /// @see get_connection
    /// @see for_each_node
    /// @see remove_node
    auto get_node(identifier_t node_id) -> remote_node_state&;

    /// @brief Removes tracked node with the specified id.
    /// @see get_node
    auto remove_node(identifier_t node_id) -> bool;

    /// @brief Finds and returns the state information about a remote host.
    /// @see get_node
    /// @see get_instance
    /// @see get_connection
    /// @see for_each_host
    auto get_host(host_id_t) -> remote_host_state&;

    /// @brief Finds and returns the state information about a remote host.
    /// @see get_node
    /// @see get_instance
    /// @see get_connection
    /// @see for_each_host
    auto get_host(host_id_t) const -> remote_host_state;

    /// @brief Finds and returns the information about a remote instance (process).
    /// @see get_node
    /// @see get_host
    /// @see get_connection
    auto get_instance(host_id_t) -> remote_instance_state&;

    /// @brief Finds and returns the information about a remote instance (process).
    /// @see get_node
    /// @see get_host
    /// @see get_connection
    auto get_instance(host_id_t) const -> remote_instance_state;

    /// @brief Finds and returns the information about remote node connections.
    /// @see get_node
    /// @see get_host
    /// @see get_instance
    /// @see for_each_connection
    auto get_connection(identifier_t node_id1, identifier_t node_id2)
      -> node_connection_state&;

    /// @brief Finds and returns the information about remote node connections.
    /// @see get_node
    /// @see get_host
    /// @see get_instance
    /// @see for_each_connection
    auto get_connection(identifier_t node_id1, identifier_t node_id2) const
      -> node_connection_state;

    auto notice_instance(identifier_t node_id, process_instance_id_t)
      -> remote_node_state&;

    /// @brief Calls a function on each tracked remote host.
    /// @see remote_host
    /// @see for_each_host_state
    /// @see for_each_node
    ///
    /// The function is called with (host_id_t, const remote_host&) as arguments.
    template <typename Function>
    void for_each_host(Function func);

    /// @brief Calls a function on each tracked remote host.
    /// @see remote_host_state
    /// @see for_each_host
    /// @see for_each_node
    ///
    /// The function is called with (host_id_t, const remote_host_state&) as arguments.
    /// This function is subject to change without notice. Prefer using for_each_host.
    template <typename Function>
    void for_each_host_state(Function func);

    /// @brief Calls a function on each tracked remote bus node.
    /// @see remote_node
    /// @see for_each_node_state
    /// @see for_each_host
    ///
    /// The function is called with (host_id_t, const remote_node&) as arguments.
    template <typename Function>
    void for_each_node(Function func);

    /// @brief Calls a function on each tracked remote bus node.
    /// @see remote_node_state
    /// @see for_each_node
    /// @see for_each_host
    ///
    /// The function is called with (host_id_t, const remote_node_state&) as arguments.
    /// This function is subject to change without notice. Prefer using for_each_node.
    template <typename Function>
    void for_each_node_state(Function func);

    /// @brief Calls a function on each tracked remote bus instance.
    /// @see remote_instance_state
    /// @see for_each_node_state
    /// @see for_each_host_state
    ///
    /// The function is called with (process_instance_id_t, const remote_instance_state&)
    /// as arguments. This function is subject to change without notice.
    template <typename Function>
    void for_each_instance_state(Function func);

    /// @brief Calls a function on tracked remote bus nodes of an instance (process).
    /// @see remote_node_state
    /// @see for_each_node_state
    /// @see for_each_host_node_state
    ///
    /// The function is called with (host_id_t, const remote_node_state&) as arguments.
    /// This function is subject to change without notice. Prefer using for_each_node.
    template <typename Function>
    void
    for_each_instance_node_state(process_instance_id_t inst_id, Function func);

    /// @brief Calls a function on tracked remote bus nodes of a remote host.
    /// @see remote_node_state
    /// @see for_each_node_state
    /// @see for_each_instance_node_state
    ///
    /// The function is called with (host_id_t, const remote_node_state&) as arguments.
    /// This function is subject to change without notice. Prefer using for_each_node.
    template <typename Function>
    void for_each_host_node_state(host_id_t host_id, Function func);

    template <typename Function>
    void for_each_connection(Function func);

    /// @brief Calls a function on tracked connections between bus nodes.
    /// @see node_connection_state
    /// @see for_each_node_state
    ///
    /// The function is called with (const node_connection&) as argument.
    template <typename Function>
    void for_each_connection(Function func) const;

private:
    friend class node_connections;

    auto _get_nodes() noexcept -> flat_map<identifier_t, remote_node_state>&;
    auto _get_instances() noexcept
      -> flat_map<process_instance_id_t, remote_instance_state>&;
    auto _get_hosts() noexcept -> flat_map<host_id_t, remote_host_state>&;
    auto _get_connections() noexcept -> std::vector<node_connection_state>&;
    auto _get_connections() const noexcept
      -> const std::vector<node_connection_state>&;

    std::shared_ptr<remote_node_tracker_impl> _pimpl{};
};
//------------------------------------------------------------------------------
/// @brief Class providing information about a remote host of bus nodes.
/// @ingroup msgbus
/// @see remote_node_tracker
/// @see remote_node
/// @see remote_instance
/// @see node_connection
class remote_host {
public:
    remote_host() noexcept = default;
    remote_host(host_id_t host_id) noexcept
      : _host_id{host_id} {}

    /// @brief Indicates if this is not-empty and has actual information.
    explicit operator bool() const noexcept {
        return bool(_pimpl);
    }

    /// @brief Returns the unique host id.
    auto id() const noexcept -> valid_if_not_zero<host_id_t> {
        return {_host_id};
    }

    /// @brief Indicates if the remote host is reachable/alive.
    auto is_alive() const noexcept -> bool;

    /// @brief Returns the name of the remote host.
    auto name() const noexcept -> valid_if_not_empty<string_view>;

    /// @brief Returns the number of concurrent threads supported at the host.
    auto cpu_concurrent_threads() const noexcept
      -> valid_if_positive<span_size_t>;

    /// @brief Returns the short average load on the remote host.
    /// @see long_average_load
    /// @see short_average_load_change
    /// @see system_info::short_average_load
    auto short_average_load() const noexcept -> valid_if_nonnegative<float>;

    /// @brief Returns the change in short average load on the remote host.
    /// @see short_average_load
    auto short_average_load_change() const noexcept -> optionally_valid<float>;

    /// @brief Returns the long average load on the remote host.
    /// @see short_average_load
    /// @see system_info::long_average_load
    auto long_average_load() const noexcept -> valid_if_nonnegative<float>;

    /// @brief Returns the change in long average load on the remote host.
    /// @see long_average_load
    auto long_average_load_change() const noexcept -> optionally_valid<float>;

    /// @brief Returns the total RAM size on the remote host.
    /// @see free_ram_size
    /// @see total_swap_size
    /// @see ram_usage
    /// @see system_info::total_ram_size
    auto total_ram_size() const noexcept -> valid_if_positive<span_size_t>;

    /// @brief Returns the free RAM size on the remote host.
    /// @see total_ram_size
    /// @see free_swap_size
    /// @see free_ram_size_change
    /// @see ram_usage
    /// @see system_info::free_ram_size
    auto free_ram_size() const noexcept -> valid_if_positive<span_size_t>;

    /// @brief Returns the change in free RAM size on the remote host.
    /// @see free_ram_size
    auto free_ram_size_change() const noexcept -> optionally_valid<span_size_t>;

    /// @brief Returns the RAM usage on the remote host (0.0, 1.0).
    /// @see ram_usage_change
    /// @see total_ram_size
    /// @see free_ram_size
    auto ram_usage() const noexcept -> valid_if_nonnegative<float> {
        if(const auto total{total_ram_size()}) {
            if(const auto free{free_ram_size()}) {
                return {1.F - float(extract(free)) / float(extract(total))};
            }
        }
        return {-1.F};
    }

    /// @brief Returns the change in RAM usage on the remote host (-1.0, 1.0).
    /// @see ram_usage
    auto ram_usage_change() const noexcept -> optionally_valid<float> {
        if(const auto total{total_ram_size()}) {
            if(const auto change{free_ram_size_change()}) {
                return {-float(extract(change)) / float(extract(total)), true};
            }
        }
        return {};
    }

    /// @brief Returns the total swap size on the remote host.
    /// @see free_swap_size
    /// @see total_ram_size
    /// @see free_swap_size_change
    /// @see ram_usage
    /// @see swap_usage
    /// @see system_info::total_swap_size
    auto total_swap_size() const noexcept -> valid_if_positive<span_size_t>;

    /// @brief Returns the free swap size on the remote host.
    /// @see total_swap_size
    /// @see free_ram_size
    /// @see free_swap_size_change
    /// @see swap_usage
    /// @see system_info::total_ram_size
    auto free_swap_size() const noexcept -> valid_if_nonnegative<span_size_t>;

    /// @brief Returns the change in free swap size on the remote host.
    /// @see free_swap_size
    auto free_swap_size_change() const noexcept
      -> optionally_valid<span_size_t>;

    /// @brief Returns the swap usage on the remote host (0.0, 1.0).
    /// @see total_swap_size
    /// @see free_swap_size
    auto swap_usage() const noexcept -> valid_if_nonnegative<float> {
        if(const auto total{total_swap_size()}) {
            if(const auto free{free_swap_size()}) {
                return {1.F - float(extract(free)) / float(extract(total))};
            }
        }
        return {-1.F};
    }

    /// @brief Returns the change in swap usage on the remote host (-1.0, 1.0).
    /// @see swap_usage
    auto swap_usage_change() const noexcept -> optionally_valid<float> {
        if(const auto total{total_swap_size()}) {
            if(const auto change{free_swap_size_change()}) {
                return {-float(extract(change)) / float(extract(total)), true};
            }
        }
        return {};
    }

protected:
    auto _impl() const noexcept -> const remote_host_impl*;
    auto _impl() noexcept -> remote_host_impl*;

private:
    host_id_t _host_id{0U};
    std::shared_ptr<remote_host_impl> _pimpl{};
};
//------------------------------------------------------------------------------
/// @brief Class manipulating information about a remote host of bus nodes.
/// @ingroup msgbus
/// @see remote_node_tracker
/// @see remote_node
/// @note Do not use directly. Use remote_host instead.
class remote_host_state : public remote_host {
public:
    using remote_host::remote_host;

    auto update() -> remote_host_state&;
    auto changes() -> remote_host_changes;
    auto add_change(remote_host_change) -> remote_host_state&;

    auto should_query_sensors() -> bool;
    auto sensors_queried() -> remote_host_state&;

    auto notice_alive() -> remote_host_state&;
    auto set_hostname(std::string) -> remote_host_state&;
    auto set_cpu_concurrent_threads(span_size_t) -> remote_host_state&;
    auto set_short_average_load(float) -> remote_host_state&;
    auto set_long_average_load(float) -> remote_host_state&;
    auto set_total_ram_size(span_size_t) -> remote_host_state&;
    auto set_total_swap_size(span_size_t) -> remote_host_state&;
    auto set_free_ram_size(span_size_t) -> remote_host_state&;
    auto set_free_swap_size(span_size_t) -> remote_host_state&;
};
//------------------------------------------------------------------------------
/// @brief Class providing information about a remote instance running bus nodes.
/// @ingroup msgbus
/// @see remote_node_tracker
/// @see remote_node
/// @see remote_host
/// @see node_connection
class remote_instance {
public:
    remote_instance() noexcept = default;
    remote_instance(
      process_instance_id_t inst_id,
      remote_node_tracker tracker) noexcept
      : _inst_id{inst_id}
      , _tracker{std::move(tracker)} {}

    /// @brief Indicates if this is not-empty and has actual information.
    explicit operator bool() const noexcept {
        return bool(_pimpl);
    }

    /// @brief Returns the id of the instance unique in the host scope.
    auto id() const noexcept -> valid_if_not_zero<process_instance_id_t> {
        return {_inst_id};
    }

    /// @brief Indicates if the remote instance (process) is alive and responsive.
    auto is_alive() const noexcept -> bool;

    /// @brief Returns the information about the host where the instance is running.
    auto host() const noexcept -> remote_host;

    /// @brief Returns the application name of this instance.
    auto application_name() const noexcept -> valid_if_not_empty<string_view>;

    /// @brief Returns the build information about the program running in the instance.
    auto build() const noexcept -> optional_reference_wrapper<const build_info>;

private:
    process_instance_id_t _inst_id{0U};
    std::shared_ptr<remote_instance_impl> _pimpl{};

protected:
    remote_node_tracker _tracker{nothing};
    auto _impl() const noexcept -> const remote_instance_impl*;
    auto _impl() noexcept -> remote_instance_impl*;
};
//------------------------------------------------------------------------------
/// @brief Class manipulating information about a remote instance running bus nodes.
/// @ingroup msgbus
/// @see remote_node_tracker
/// @see remote_instance
/// @note Do not use directly. Use remote_host instead.
class remote_instance_state : public remote_instance {
public:
    using remote_instance::remote_instance;

    auto update() -> remote_instance_state&;
    auto changes() -> remote_instance_changes;
    auto add_change(remote_instance_change) -> remote_instance_state&;

    auto notice_alive() -> remote_instance_state&;
    auto set_host_id(host_id_t) -> remote_instance_state&;
    auto set_app_name(const std::string&) -> remote_instance_state&;
    auto assign(build_info) -> remote_instance_state&;
};
//------------------------------------------------------------------------------
/// @brief Class providing information about a remote bus node.
/// @ingroup msgbus
/// @see remote_node_tracker
/// @see remote_host
/// @see remote_instance
/// @see node_connection
class remote_node {
public:
    remote_node() noexcept = default;
    remote_node(identifier_t node_id, remote_node_tracker tracker) noexcept
      : _node_id{node_id}
      , _tracker{std::move(tracker)} {}

    /// @brief Indicates if this is not-empty and has actual information.
    explicit operator bool() const noexcept {
        return bool(_pimpl);
    }

    /// @brief Returns the unique id of the remote bus node.
    auto id() const noexcept -> valid_if_not_zero<identifier_t> {
        return {_node_id};
    }

    /// @brief Returns the id of the instance in which the node is running.
    auto instance_id() const noexcept
      -> valid_if_not_zero<process_instance_id_t>;

    /// @brief Returns the id of the host on which the node is running.
    auto host_id() const noexcept -> valid_if_not_zero<host_id_t>;

    /// @brief Returns the kind of the remote node.
    /// @see has_known_kind
    /// @see is_router_node
    /// @see is_bridge_node
    auto kind() const noexcept -> node_kind;

    /// @brief Indicates if the kind of the remote node is known.
    /// @see kind
    /// @see is_router_node
    /// @see is_bridge_node
    auto has_known_kind() const noexcept -> bool {
        return kind() != node_kind::unknown;
    }

    /// @brief Returns if the remote node is a router control node.
    /// @see is_bridge_node
    /// @see kind
    auto is_router_node() const noexcept -> tribool;

    /// @brief Returns if the remote node is a router control node.
    /// @see is_bridge_node
    /// @see kind
    auto is_bridge_node() const noexcept -> tribool;

    /// @brief Indicates if endpoint information is available.
    auto has_endpoint_info() const noexcept -> bool;

    /// @brief Returns the user-readable display name of the application.
    auto display_name() const noexcept -> valid_if_not_empty<string_view>;

    /// @brief Returns the user-readable description of the application.
    auto description() const noexcept -> valid_if_not_empty<string_view>;

    /// @brief Indicates if the remote node subscribes to the specified message type.
    auto subscribes_to(message_id msg_id) const noexcept -> tribool;

    /// @brief Indicates if the remote node is pingable.
    /// @see set_ping_interval
    /// @see is_responsive
    auto is_pingable() const noexcept -> tribool;

    /// @brief Sets the ping interval for the remote node.
    /// @see is_pingable
    void set_ping_interval(std::chrono::milliseconds) noexcept;

    /// @brief Returns the ping success rate for the remote node (0.0, 1.0).
    /// @see is_responsive
    /// @see is_pingable
    auto ping_success_rate() const noexcept -> valid_if_between_0_1<float>;

    /// @brief Indicates if the remote node is responsive.
    /// @see ping_success_rate
    auto is_responsive() const noexcept -> tribool;

    /// @brief Returns information about the host where the node is running.
    /// @see instance
    /// @see connections
    auto host() const noexcept -> remote_host;

    /// @brief Returns information about the instance in which the node is running.
    /// @see host
    /// @see connections
    auto instance() const noexcept -> remote_instance;

    /// @brief Return information about the connections of this node.
    /// @see host
    /// @see instance
    auto connections() const noexcept -> node_connections;

private:
    identifier_t _node_id{0U};
    std::shared_ptr<remote_node_impl> _pimpl{};

protected:
    remote_node_tracker _tracker{nothing};
    auto _impl() const noexcept -> const remote_node_impl*;
    auto _impl() noexcept -> remote_node_impl*;
};
//------------------------------------------------------------------------------
/// @brief Class manipulating information about a remote bus node.
/// @ingroup msgbus
/// @see remote_node_tracker
/// @see remote_node
/// @note Do not use directly. Use remote_node instead
class remote_node_state : public remote_node {
public:
    using remote_node::remote_node;

    auto clear() noexcept -> remote_node_state&;

    auto host_state() const noexcept -> remote_host_state;
    auto instance_state() const noexcept -> remote_instance_state;

    auto update() -> remote_node_state&;
    auto changes() -> remote_node_changes;
    auto add_change(remote_node_change) -> remote_node_state&;

    auto set_instance_id(process_instance_id_t) -> remote_node_state&;
    auto set_host_id(host_id_t) -> remote_node_state&;

    auto assign(node_kind) -> remote_node_state&;
    auto assign(const endpoint_info&) -> remote_node_state&;

    auto add_subscription(message_id) -> remote_node_state&;
    auto remove_subscription(message_id) -> remote_node_state&;

    auto should_ping() -> std::tuple<bool, std::chrono::milliseconds>;
    auto notice_alive() -> remote_node_state&;
    auto pinged() -> remote_node_state&;
    auto ping_response(message_sequence_t, std::chrono::microseconds age)
      -> remote_node_state&;
    auto ping_timeout(message_sequence_t, std::chrono::microseconds age)
      -> remote_node_state&;
};
//------------------------------------------------------------------------------
/// @brief Class providing information about connection between bus nodes.
/// @ingroup msgbus
/// @see remote_node_tracker
/// @see remote_node
/// @see remote_host
/// @see remote_instance
/// @see node_connections
class node_connection {
public:
    node_connection() noexcept = default;
    node_connection(
      identifier_t id1,
      identifier_t id2,
      remote_node_tracker tracker) noexcept
      : _id1{id1}
      , _id2{id2}
      , _tracker{std::move(tracker)} {}

    /// @brief Indicates if this is not-empty and has actual information.
    explicit operator bool() const noexcept {
        return bool(_pimpl);
    }

    /// @brief Indicates if the connection connects node with the specified id.
    /// @see opposite_id
    auto connects(identifier_t id) const noexcept {
        return (_id1 == id) || (_id2 == id);
    }

    /// @brief Indicates if the connection connects nodes with the specified id.
    /// @see opposite_id
    auto connects(identifier_t id1, identifier_t id2) const noexcept {
        return ((_id1 == id1) && (_id2 == id2)) ||
               ((_id1 == id2) && (_id2 == id1));
    }

    /// @brief Returns the id of the node opposite to the node with id in argument.
    /// @see connects
    auto opposite_id(identifier_t id) const noexcept
      -> valid_if_not_zero<identifier_t> {
        if(_id1 == id) {
            return {_id2};
        }
        if(_id2 == id) {
            return {_id1};
        }
        return {0U};
    }

    /// @brief Returns the connection kind.
    auto kind() const noexcept -> connection_kind;

private:
    std::shared_ptr<node_connection_impl> _pimpl{};

protected:
    identifier_t _id1{0U};
    identifier_t _id2{0U};
    remote_node_tracker _tracker{nothing};
    auto _impl() const noexcept -> const node_connection_impl*;
    auto _impl() noexcept -> node_connection_impl*;
};
//------------------------------------------------------------------------------
/// @brief Class manipulating information about connection between bus nodes.
/// @ingroup msgbus
/// @see remote_node_tracker
/// @see remote_node
/// @see remote_host
/// @see remote_instance
/// @note Do not use directly. Use node_connection instead.
class node_connection_state : public node_connection {
public:
    using node_connection::node_connection;

    auto set_kind(connection_kind) -> node_connection_state&;
};
//------------------------------------------------------------------------------
/// @brief Class providing information about connections from the perspective of a node.
/// @ingroup msgbus
/// @see remote_node_tracker
/// @see remote_node
/// @see remote_host
/// @see remote_instance
/// @see node_connection
class node_connections {
public:
    node_connections(
      identifier_t origin_id,
      std::vector<identifier_t> remote_ids,
      remote_node_tracker tracker) noexcept
      : _origin_id{origin_id}
      , _remote_ids{std::move(remote_ids)}
      , _tracker{std::move(tracker)} {}

    /// @brief Returns the origin node connected by the listed connections.
    auto origin() -> remote_node {
        return _tracker.get_node(_origin_id);
    }

    /// @brief Returns the number of adjacent connections of the origin node.
    /// @see get
    /// @see remote
    auto count() const noexcept -> span_size_t {
        return span_size(_remote_ids.size());
    }

    /// @brief Returns the i-th connection of the origin node.
    /// @see count
    /// @see remote
    /// @pre index >= 0 && index < count()
    auto get(span_size_t index) -> node_connection {
        EAGINE_ASSERT((index >= 0) && (index < count()));
        return _tracker.get_connection(
          _origin_id, _remote_ids[std_size(index)]);
    }

    /// @brief Returns the node connected through the i-th connection.
    /// @see count
    /// @see get
    /// @pre index >= 0 && index < count()
    auto remote(span_size_t index) -> remote_node {
        EAGINE_ASSERT((index >= 0) && (index < count()));
        return _tracker.get_node(_remote_ids[std_size(index)]);
    }

private:
    identifier_t _origin_id{0U};
    std::vector<identifier_t> _remote_ids{};
    remote_node_tracker _tracker{nothing};
};
//------------------------------------------------------------------------------
template <typename Function>
void remote_node_tracker::for_each_host(Function func) {
    if(EAGINE_LIKELY(_pimpl)) {
        for(auto& [host_id, host] : _get_hosts()) {
            func(host_id, static_cast<remote_host&>(host));
        }
    }
}
//------------------------------------------------------------------------------
template <typename Function>
void remote_node_tracker::for_each_host_state(Function func) {
    if(EAGINE_LIKELY(_pimpl)) {
        for(auto& [host_id, host] : _get_hosts()) {
            func(host_id, host);
        }
    }
}
//------------------------------------------------------------------------------
template <typename Function>
void remote_node_tracker::for_each_node(Function func) {
    if(EAGINE_LIKELY(_pimpl)) {
        for(auto& [node_id, node] : _get_nodes()) {
            func(node_id, static_cast<remote_node&>(node));
        }
    }
}
//------------------------------------------------------------------------------
template <typename Function>
void remote_node_tracker::for_each_node_state(Function func) {
    if(EAGINE_LIKELY(_pimpl)) {
        for(auto& [node_id, node] : _get_nodes()) {
            func(node_id, node);
        }
    }
}
//------------------------------------------------------------------------------
template <typename Function>
void remote_node_tracker::for_each_instance_state(Function func) {
    if(EAGINE_LIKELY(_pimpl)) {
        for(auto& [inst_id, inst] : _get_instances()) {
            func(inst_id, inst);
        }
    }
}
//------------------------------------------------------------------------------
template <typename Function>
void remote_node_tracker::for_each_instance_node_state(
  process_instance_id_t inst_id,
  Function func) {
    if(EAGINE_LIKELY(_pimpl)) {
        for(auto& [node_id, node] : _get_nodes()) {
            if(node.instance_id() == inst_id) {
                func(node_id, node);
            }
        }
    }
}
//------------------------------------------------------------------------------
template <typename Function>
void remote_node_tracker::for_each_host_node_state(
  host_id_t host_id,
  Function func) {
    if(EAGINE_LIKELY(_pimpl)) {
        for(auto& [node_id, node] : _get_nodes()) {
            if(node.host_id() == host_id) {
                func(node_id, node);
            }
        }
    }
}
//------------------------------------------------------------------------------
template <typename Function>
void remote_node_tracker::for_each_connection(Function func) {
    if(EAGINE_LIKELY(_pimpl)) {
        for(auto& conn : _get_connections()) {
            func(conn);
        }
    }
}
//------------------------------------------------------------------------------
template <typename Function>
void remote_node_tracker::for_each_connection(Function func) const {
    if(EAGINE_LIKELY(_pimpl)) {
        for(const auto& conn : _get_connections()) {
            func(conn);
        }
    }
}
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/message_bus/remote_node.inl>
#endif

#endif // EAGINE_MESSAGE_BUS_REMOTE_NODE_HPP
