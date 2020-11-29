/**
 *  @file eagine/message_bus/remote_node.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MESSAGE_BUS_REMOTE_NODE_HPP
#define EAGINE_MESSAGE_BUS_REMOTE_NODE_HPP

#include "../identifier_t.hpp"
#include "../message_id.hpp"
#include "../process.hpp"
#include "../tribool.hpp"
#include "../types.hpp"
#include "../valid_if/ge0_le1.hpp"
#include "../valid_if/not_empty.hpp"
#include "../valid_if/not_zero.hpp"
#include "node_kind.hpp"
#include "types.hpp"
#include <chrono>
#include <memory>

namespace eagine::msgbus {
//------------------------------------------------------------------------------
class remote_host_impl;
class remote_host {
public:
    remote_host() noexcept = default;
    remote_host(identifier_t host_id) noexcept
      : _host_id{host_id} {}

    auto id() const noexcept -> valid_if_not_zero<identifier_t> {
        return {_host_id};
    }

    auto name() const noexcept -> valid_if_not_empty<string_view>;

    friend auto operator==(const remote_host& l, const remote_host& r) noexcept
      -> bool {
        return l._host_id == r._host_id;
    }

    friend auto operator!=(const remote_host& l, const remote_host& r) noexcept
      -> bool {
        return l._host_id != r._host_id;
    }

private:
    identifier_t _host_id{0U};
    std::shared_ptr<remote_host_impl> _pimpl{};

protected:
    auto _impl() const noexcept -> const remote_host_impl*;
    auto _impl() noexcept -> remote_host_impl*;
};
//------------------------------------------------------------------------------
class remote_host_state : public remote_host {
public:
    using remote_host::remote_host;

    auto set_hostname(std::string) -> remote_host_state&;
};
//------------------------------------------------------------------------------
class remote_node_impl;
class remote_node {
public:
    remote_node() noexcept = default;

    remote_node(identifier_t node_id) noexcept
      : _node_id{node_id} {}

    auto id() const noexcept -> valid_if_not_zero<identifier_t> {
        return {_node_id};
    }

    auto instance_id() const noexcept
      -> valid_if_not_zero<process_instance_id_t>;

    auto kind() const noexcept -> node_kind;

    auto display_name() const noexcept -> valid_if_not_empty<string_view>;
    auto description() const noexcept -> valid_if_not_empty<string_view>;

    auto is_router_node() const noexcept -> tribool;
    auto is_bridge_node() const noexcept -> tribool;

    auto host_id() const noexcept -> valid_if_not_zero<identifier_t>;
    auto host() const noexcept -> remote_host;

    auto subscribes_to(message_id msg_id) const noexcept -> tribool;

    void set_ping_interval(std::chrono::milliseconds) noexcept;
    auto ping_success_rate() const noexcept -> valid_if_between_0_1<float>;
    auto is_responsive() const noexcept -> tribool;

private:
    identifier_t _node_id{0U};
    std::shared_ptr<remote_node_impl> _pimpl{};

protected:
    auto _impl() const noexcept -> const remote_node_impl*;
    auto _impl() noexcept -> remote_node_impl*;
};
//------------------------------------------------------------------------------
class remote_node_state : public remote_node {
public:
    using remote_node::remote_node;

    auto set_instance_id(process_instance_id_t) -> remote_node_state&;

    auto assign(node_kind) -> remote_node_state&;
    auto assign(endpoint_info) -> remote_node_state&;
    auto assign(remote_host) -> remote_node_state&;

    auto add_subscription(message_id) -> remote_node_state&;
    auto remove_subscription(message_id) -> remote_node_state&;

    auto instance_changed() -> bool;
    auto something_changed() -> bool;

    auto should_ping() -> std::tuple<bool, std::chrono::milliseconds>;
    auto is_alive() -> remote_node_state&;
    auto pinged() -> remote_node_state&;
    auto ping_response(message_sequence_t, std::chrono::microseconds age)
      -> remote_node_state&;
    auto ping_timeout(message_sequence_t, std::chrono::microseconds age)
      -> remote_node_state&;
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/message_bus/remote_node.inl>
#endif

#endif // EAGINE_MESSAGE_BUS_REMOTE_NODE_HPP
