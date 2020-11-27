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
#include "../tribool.hpp"
#include "../types.hpp"
#include "../valid_if/ge0_le1.hpp"
#include "../valid_if/not_empty.hpp"
#include "../valid_if/not_zero.hpp"
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

    auto hostname() noexcept -> valid_if_not_empty<string_view>;

private:
    identifier_t _host_id{0};
    std::shared_ptr<remote_host_impl> _pimpl{};

protected:
    auto _impl() noexcept -> remote_host_impl*;
};
//------------------------------------------------------------------------------
class remote_host_state : public remote_host {
public:
    using remote_host::remote_host;

    void set_hostname(std::string);
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

    auto host_id() noexcept -> valid_if_not_zero<identifier_t>;

    auto host() noexcept -> remote_host;

    auto subscribes_to(message_id msg_id) noexcept -> tribool;

    void set_ping_interval(std::chrono::milliseconds) noexcept;
    auto ping_success_rate() noexcept -> valid_if_between_0_1<float>;

private:
    identifier_t _node_id{0U};
    std::shared_ptr<remote_node_impl> _pimpl{};

protected:
    auto _impl() noexcept -> remote_node_impl*;
};
//------------------------------------------------------------------------------
class remote_node_state : public remote_node {
public:
    using remote_node::remote_node;

    void assign(remote_host);

    void add_subscription(message_id);
    void remove_subscription(message_id);

    auto should_ping() noexcept -> std::tuple<bool, std::chrono::milliseconds>;
    void pinged() noexcept;
    void ping_response(message_sequence_t, std::chrono::microseconds age);
    void ping_timeout(message_sequence_t, std::chrono::microseconds age);
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/message_bus/remote_node.inl>
#endif

#endif // EAGINE_MESSAGE_BUS_REMOTE_NODE_HPP
