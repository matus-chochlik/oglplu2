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
enum class remote_node_change : std::uint16_t {
    /// @brief The node kind has appeared or changed.
    /// @see node_kind
    kind = 1U << 0U,
    /// @brief The host identifier has appeared or changed.
    host_id = 1U << 1U,
    /// @brief The host information has appeared or changed.
    host_info = 1U << 2U,
    /// @brief The build information has appeared or changed.
    build_info = 1U << 3U,
    /// @brief The endpoint information has appeared or changed.
    endpoint_info = 1U << 4U,
    /// @brief New remotly callable methods have been added.
    methods_added = 1U << 5U,
    /// @brief New remotly callable methods have been removed.
    methods_removed = 1U << 6U,
    /// @brief Node started responding to pings.
    started_responding = 1U << 7U,
    /// @brief Node stopped responding to pings.
    stopped_responding = 1U << 8U,
    /// @brief The hardware configuration information has appeared or changed.
    hardware_config = 1U << 9U,
    /// @brief New sensor values have appeared or changed.
    sensor_values = 1U << 10U,
    /// @brief The bus connection information has appeared or changed.
    connection_info = 1U << 11U,
    /// @brief The endpoint instance id has changed.
    instance_id = 1U << 12U
};
//------------------------------------------------------------------------------
template <typename Selector>
constexpr auto
enumerator_mapping(type_identity<remote_node_change>, Selector) noexcept {
    return enumerator_map_type<remote_node_change, 13>{
      {{"kind", remote_node_change::kind},
       {"host_id", remote_node_change::host_id},
       {"host_info", remote_node_change::host_info},
       {"build_info", remote_node_change::build_info},
       {"endpoint_info", remote_node_change::endpoint_info},
       {"methods_added", remote_node_change::methods_added},
       {"methods_removed", remote_node_change::methods_removed},
       {"started_responding", remote_node_change::started_responding},
       {"stopped_responding", remote_node_change::stopped_responding},
       {"hardware_config", remote_node_change::hardware_config},
       {"sensor_values", remote_node_change::sensor_values},
       {"connection_info", remote_node_change::connection_info},
       {"instance_id", remote_node_change::instance_id}}};
}
//------------------------------------------------------------------------------
/// @brief Class providin and manipulating information about remote node changes.
/// @ingroup msgbus
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
    auto get_node(identifier_t node_id) -> remote_node_state&;

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
    template <typename Function>
    void for_each_host_state(Function func);

    /// @brief Calls a function on each tracked remote bus node.
    /// @see remote_node
    /// @see for_each_node_state
    /// @see for_each_host
    ///
    /// The function is called with (host_id_t, const remote_node_state&) as arguments.
    template <typename Function>
    void for_each_node(Function func);

    /// @brief Calls a function on each tracked remote bus node.
    /// @see remote_node_state
    /// @see for_each_node
    /// @see for_each_host
    ///
    /// The function is called with (host_id_t, const remote_node_state&) as arguments.
    template <typename Function>
    void for_each_node_state(Function func);

    /// @brief Calls a function on tracked remote bus nodes of an instance (process).
    /// @see remote_node_state
    /// @see for_each_node_state
    /// @see for_each_host_node_state
    ///
    /// The function is called with (host_id_t, const remote_node_state&) as arguments.
    template <typename Function>
    void
    for_each_instance_node_state(process_instance_id_t inst_id, Function func);

    /// @brief Calls a function on tracked remote bus nodes of a remote host.
    /// @see remote_node_state
    /// @see for_each_node_state
    /// @see for_each_instance_node_state
    ///
    /// The function is called with (host_id_t, const remote_node_state&) as arguments.
    template <typename Function>
    void for_each_host_node_state(host_id_t host_id, Function func);

    template <typename Function>
    void for_each_connection(Function func);

    /// @brief Calls a function on tracked connections between bus nodes.
    /// @see node_connection_state
    /// @see for_each_node_state
    ///
    /// The function is called with (const node_connection_state&) as argument.
    template <typename Function>
    void for_each_connection(Function func) const;

private:
    friend class node_connections;

    auto _get_nodes() noexcept -> flat_map<identifier_t, remote_node_state>&;
    auto _get_hosts() noexcept -> flat_map<host_id_t, remote_host_state>&;
    auto _get_connections() noexcept -> std::vector<node_connection_state>&;
    auto _get_connections() const noexcept
      -> const std::vector<node_connection_state>&;

    std::shared_ptr<remote_node_tracker_impl> _pimpl{};
};
//------------------------------------------------------------------------------
class remote_host {
public:
    remote_host() noexcept = default;
    remote_host(host_id_t host_id) noexcept
      : _host_id{host_id} {}

    explicit operator bool() const noexcept {
        return bool(_pimpl);
    }

    auto id() const noexcept -> valid_if_not_zero<host_id_t> {
        return {_host_id};
    }

    auto is_alive() const noexcept -> bool;

    auto name() const noexcept -> valid_if_not_empty<string_view>;

    auto cpu_concurrent_threads() const noexcept
      -> valid_if_positive<span_size_t>;
    auto short_average_load() const noexcept -> valid_if_nonnegative<float>;
    auto long_average_load() const noexcept -> valid_if_nonnegative<float>;
    auto total_ram_size() const noexcept -> valid_if_positive<span_size_t>;
    auto free_ram_size() const noexcept -> valid_if_positive<span_size_t>;
    auto ram_usage() const noexcept -> valid_if_nonnegative<float> {
        if(const auto total{total_ram_size()}) {
            if(const auto free{free_ram_size()}) {
                return 1.F - float(extract(free)) / float(extract(total));
            }
        }
        return {-1.F};
    }
    auto total_swap_size() const noexcept -> valid_if_positive<span_size_t>;
    auto free_swap_size() const noexcept -> valid_if_nonnegative<span_size_t>;
    auto swap_usage() const noexcept -> valid_if_nonnegative<float> {
        if(const auto total{total_swap_size()}) {
            if(const auto free{free_swap_size()}) {
                return 1.F - float(extract(free)) / float(extract(total));
            }
        }
        return {-1.F};
    }

private:
    host_id_t _host_id{0U};
    std::shared_ptr<remote_host_impl> _pimpl{};

protected:
    auto _impl() const noexcept -> const remote_host_impl*;
    auto _impl() noexcept -> remote_host_impl*;
};
//------------------------------------------------------------------------------
class remote_host_state : public remote_host {
public:
    using remote_host::remote_host;

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
class remote_instance {
public:
    remote_instance() noexcept = default;
    remote_instance(
      process_instance_id_t inst_id,
      remote_node_tracker tracker) noexcept
      : _inst_id{inst_id}
      , _tracker{std::move(tracker)} {}

    explicit operator bool() const noexcept {
        return bool(_pimpl);
    }

    auto id() const noexcept -> valid_if_not_zero<process_instance_id_t> {
        return {_inst_id};
    }

    auto is_alive() const noexcept -> bool;

    auto host() const noexcept -> remote_host;

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
class remote_instance_state : public remote_instance {
public:
    using remote_instance::remote_instance;

    auto notice_alive() -> remote_instance_state&;
    auto set_host_id(host_id_t) -> remote_instance_state&;
    auto assign(build_info) -> remote_instance_state&;
};
//------------------------------------------------------------------------------
class remote_node {
public:
    remote_node() noexcept = default;
    remote_node(identifier_t node_id, remote_node_tracker tracker) noexcept
      : _node_id{node_id}
      , _tracker{std::move(tracker)} {}

    explicit operator bool() const noexcept {
        return bool(_pimpl);
    }

    auto id() const noexcept -> valid_if_not_zero<identifier_t> {
        return {_node_id};
    }

    auto instance_id() const noexcept
      -> valid_if_not_zero<process_instance_id_t>;

    auto host_id() const noexcept -> valid_if_not_zero<host_id_t>;

    auto kind() const noexcept -> node_kind;

    auto has_endpoint_info() const noexcept -> bool;
    auto app_name() const noexcept -> valid_if_not_empty<string_view>;
    auto display_name() const noexcept -> valid_if_not_empty<string_view>;
    auto description() const noexcept -> valid_if_not_empty<string_view>;
    auto is_router_node() const noexcept -> tribool;
    auto is_bridge_node() const noexcept -> tribool;

    auto subscribes_to(message_id msg_id) const noexcept -> tribool;

    auto is_pingable() const noexcept -> tribool;
    void set_ping_interval(std::chrono::milliseconds) noexcept;
    auto ping_success_rate() const noexcept -> valid_if_between_0_1<float>;
    auto is_responsive() const noexcept -> tribool;

    auto host() const noexcept -> remote_host;
    auto instance() const noexcept -> remote_instance;
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
/// @brief Class representing the state of a remote message bus node.
/// @ingroup msgbus
/// @see remote_node_tracker
class remote_node_state : public remote_node {
public:
    using remote_node::remote_node;

    auto clear() noexcept -> remote_node_state&;

    auto host_state() const noexcept -> remote_host_state;

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

    explicit operator bool() const noexcept {
        return bool(_pimpl);
    }

    auto connects(identifier_t id) const noexcept {
        return (_id1 == id) || (_id2 == id);
    }

    auto connects(identifier_t id1, identifier_t id2) const noexcept {
        return ((_id1 == id1) && (_id2 == id2)) ||
               ((_id1 == id2) && (_id2 == id1));
    }

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
class node_connection_state : public node_connection {
public:
    using node_connection::node_connection;

    auto set_kind(connection_kind) -> node_connection_state&;
};
//------------------------------------------------------------------------------
class node_connections {
public:
    node_connections(
      identifier_t origin_id,
      std::vector<identifier_t> remote_ids,
      remote_node_tracker tracker) noexcept
      : _origin_id{origin_id}
      , _remote_ids{std::move(remote_ids)}
      , _tracker{std::move(tracker)} {}

    auto origin() -> remote_node {
        return _tracker.get_node(_origin_id);
    }

    auto count() const noexcept -> span_size_t {
        return span_size(_remote_ids.size());
    }

    auto get(span_size_t index) -> node_connection {
        EAGINE_ASSERT((index >= 0) && (index < count()));
        return _tracker.get_connection(
          _origin_id, _remote_ids[std_size(index)]);
    }

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
