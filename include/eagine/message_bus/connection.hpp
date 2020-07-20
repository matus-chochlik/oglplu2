/**
 *  @file eagine/message_bus/connection.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MESSAGE_BUS_CONNECTION_HPP
#define EAGINE_MESSAGE_BUS_CONNECTION_HPP

#include "../bitfield.hpp"
#include "../callable_ref.hpp"
#include "../identity.hpp"
#include "../message_id.hpp"
#include "../valid_if/positive.hpp"
#include "message.hpp"
#include <type_traits>

namespace eagine::msgbus {
//------------------------------------------------------------------------------
constexpr const span_size_t min_connection_data_size = 1024;
//------------------------------------------------------------------------------
enum class connection_kind : std::uint8_t {
    in_process = 1U << 0U,
    local_interprocess = 1U << 1U,
    remote_interprocess = 1U << 2U
};
//------------------------------------------------------------------------------
template <typename Selector>
constexpr auto enumerator_mapping(
  identity<connection_kind>, Selector) noexcept {
    return enumerator_map_type<connection_kind, 3>{
      {{"in_process", connection_kind::in_process},
       {"local_interprocess", connection_kind::local_interprocess},
       {"remote_interprocess", connection_kind::remote_interprocess}}};
}
//------------------------------------------------------------------------------
using connection_kinds = bitfield<connection_kind>;

static inline connection_kinds operator|(
  connection_kind l, connection_kind r) noexcept {
    return {l, r};
}
//------------------------------------------------------------------------------
enum class connection_addr_kind { none, filepath, ipv4 };

template <typename Selector>
constexpr auto enumerator_mapping(
  identity<connection_addr_kind>, Selector) noexcept {
    return enumerator_map_type<connection_addr_kind, 3>{
      {{"none", connection_addr_kind::none},
       {"filepath", connection_addr_kind::filepath},
       {"ipv4", connection_addr_kind::ipv4}}};
}

template <connection_addr_kind Kind>
using connection_addr_kind_tag =
  std::integral_constant<connection_addr_kind, Kind>;
//------------------------------------------------------------------------------
enum class connection_protocol { stream, datagram, message };

template <typename Selector>
constexpr auto enumerator_mapping(
  identity<connection_protocol>, Selector) noexcept {
    return enumerator_map_type<connection_protocol, 3>{
      {{"stream", connection_protocol::stream},
       {"datagram", connection_protocol::datagram},
       {"message", connection_protocol::message}}};
}

template <connection_protocol Proto>
using connection_protocol_tag =
  std::integral_constant<connection_protocol, Proto>;

using stream_protocol_tag =
  connection_protocol_tag<connection_protocol::stream>;
using datagram_protocol_tag =
  connection_protocol_tag<connection_protocol::datagram>;
//------------------------------------------------------------------------------
struct connection_info {
    virtual ~connection_info() noexcept = default;
    connection_info() noexcept = default;
    connection_info(connection_info&&) noexcept = default;
    connection_info(const connection_info&) = delete;
    connection_info& operator=(connection_info&&) = delete;
    connection_info& operator=(const connection_info&) = delete;

    virtual connection_kind kind() = 0;

    virtual connection_addr_kind addr_kind() = 0;

    virtual identifier type_id() = 0;
};
//------------------------------------------------------------------------------
struct connection : connection_info {

    using fetch_handler = callable_ref<bool(message_id, const message_view&)>;

    virtual bool update() {
        return false;
    }

    virtual void cleanup() {
    }

    virtual bool is_usable() {
        return true;
    }

    virtual valid_if_positive<span_size_t> max_data_size() {
        return {0};
    }

    virtual bool send(message_id msg_id, const message_view&) = 0;

    virtual bool fetch_messages(fetch_handler handler) = 0;
};
//------------------------------------------------------------------------------
struct connection_user {
    virtual ~connection_user() noexcept = default;
    connection_user() noexcept = default;
    connection_user(connection_user&&) noexcept = default;
    connection_user(const connection_user&) = delete;
    connection_user& operator=(connection_user&&) = delete;
    connection_user& operator=(const connection_user&) = delete;

    virtual bool add_connection(std::unique_ptr<connection> a_connection) = 0;
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_CONNECTION_HPP

