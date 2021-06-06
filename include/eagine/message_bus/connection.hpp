/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MESSAGE_BUS_CONNECTION_HPP
#define EAGINE_MESSAGE_BUS_CONNECTION_HPP

#include "../bool_aggregate.hpp"
#include "../callable_ref.hpp"
#include "../interface.hpp"
#include "../message_id.hpp"
#include "../type_identity.hpp"
#include "../valid_if/positive.hpp"
#include "connection_kind.hpp"
#include "message.hpp"
#include <type_traits>

namespace eagine::msgbus {
//------------------------------------------------------------------------------
/// @brief The minimum guaranteed block size that can be sent through bus connections.
/// @ingroup msgbus
constexpr const span_size_t min_connection_data_size = 4096;
//------------------------------------------------------------------------------
/// @brief Message bus connection address kind enumeration.
/// @ingroup msgbus
/// @see connection_addr_kind_tag
enum class connection_addr_kind {
    /// @brief No public address.
    none,
    /// @brief Filesystem path.
    filepath,
    /// @brief PIv4 address.
    ipv4
};

template <typename Selector>
constexpr auto
enumerator_mapping(type_identity<connection_addr_kind>, Selector) noexcept {
    return enumerator_map_type<connection_addr_kind, 3>{
      {{"none", connection_addr_kind::none},
       {"filepath", connection_addr_kind::filepath},
       {"ipv4", connection_addr_kind::ipv4}}};
}

/// @brief Tag template alias for specifying connection address kind.
/// @ingroup msgbus
template <connection_addr_kind Kind>
using connection_addr_kind_tag =
  std::integral_constant<connection_addr_kind, Kind>;
//------------------------------------------------------------------------------
/// @brief Message bus connection protocol.
/// @ingroup msgbus
/// @see connection_protocol_tag
enum class connection_protocol {
    /// @brief Reliable stream protocol.
    stream,
    /// @brief Datagram protocol.
    datagram,
    /// @brief Message protocol.
    message
};

template <typename Selector>
constexpr auto
enumerator_mapping(type_identity<connection_protocol>, Selector) noexcept {
    return enumerator_map_type<connection_protocol, 3>{
      {{"stream", connection_protocol::stream},
       {"datagram", connection_protocol::datagram},
       {"message", connection_protocol::message}}};
}

/// @brief Tag template alias for specifying connection protocol kind.
/// @ingroup msgbus
/// @see stream_protocol_tag
/// @see datagram_protocol_tag
template <connection_protocol Proto>
using connection_protocol_tag =
  std::integral_constant<connection_protocol, Proto>;

/// @brief Tag type for specifying stream connection protocols.
/// @ingroup msgbus
/// @see datagram_protocol_tag
using stream_protocol_tag =
  connection_protocol_tag<connection_protocol::stream>;

/// @brief Tag type for specifying datagram connection protocols.
/// @ingroup msgbus
/// @see stream_protocol_tag
using datagram_protocol_tag =
  connection_protocol_tag<connection_protocol::datagram>;
//------------------------------------------------------------------------------
/// @brief Basic interface for retrieving message bus connection information.
/// @ingroup msgbus
/// @see connection
struct connection_info : interface<connection_info> {

    /// @brief Returns the connection kind.
    virtual auto kind() -> connection_kind = 0;

    /// @brief Returns the connection address kind.
    virtual auto addr_kind() -> connection_addr_kind = 0;

    /// @brief Returns a description identifier of the implementation.
    virtual auto type_id() -> identifier = 0;
};
//------------------------------------------------------------------------------
/// @brief Interface for message bus connections.
/// @ingroup msgbus
/// @see connection_user
/// @see acceptor
struct connection : connection_info {

    /// @brief Alias for fetch handler callable reference type.
    using fetch_handler =
      callable_ref<bool(message_id, message_age, const message_view&)>;

    /// @brief Updates the internal state of the connection (called repeatedly).
    /// @see send
    /// @see fetch_messages
    virtual auto update() -> work_done {
        return {};
    }

    /// @brief Cleans up the connection before destroying it.
    virtual void cleanup() {}

    /// @brief Checks if the connection is in usable state.
    virtual auto is_usable() -> bool {
        return true;
    }

    /// @brief Returns the maximum data block size in bytes that can be sent.
    virtual auto max_data_size() -> valid_if_positive<span_size_t> {
        return {0};
    }

    /// @brief Sent a message with the specified id.
    /// @see fetch_messages
    /// @see update
    virtual auto send(message_id msg_id, const message_view&) -> bool = 0;

    /// @brief Fetch all enqueued messages that have been received since last fetch.
    /// @see send
    /// @see update
    virtual auto fetch_messages(fetch_handler handler) -> work_done = 0;

    /// @brief Fill in the available statistics information for this connection.
    virtual auto query_statistics(connection_statistics&) -> bool = 0;
};
//------------------------------------------------------------------------------
/// @brief Interface for classes that can use message bus connections.
/// @ingroup msgbus
/// @see connection
/// @see acceptor_user
struct connection_user : interface<connection_user> {

    /// @brief Adds the specified message bus connection.
    /// Result indicates if the connection was used or discarded.
    virtual auto add_connection(std::unique_ptr<connection>) -> bool = 0;
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_CONNECTION_HPP
