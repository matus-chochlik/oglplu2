/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MESSAGE_BUS_CONNECTION_HPP
#define EAGINE_MESSAGE_BUS_CONNECTION_HPP

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
constexpr const span_size_t min_connection_data_size = 1024;
//------------------------------------------------------------------------------
enum class connection_addr_kind { none, filepath, ipv4 };

template <typename Selector>
constexpr auto
enumerator_mapping(type_identity<connection_addr_kind>, Selector) noexcept {
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
constexpr auto
enumerator_mapping(type_identity<connection_protocol>, Selector) noexcept {
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
struct connection_info : interface<connection_info> {

    virtual auto kind() -> connection_kind = 0;

    virtual auto addr_kind() -> connection_addr_kind = 0;

    virtual auto type_id() -> identifier = 0;
};
//------------------------------------------------------------------------------
struct connection : connection_info {

    using fetch_handler =
      callable_ref<bool(message_id, message_age, const message_view&)>;

    virtual auto update() -> bool {
        return false;
    }

    virtual void cleanup() {}

    virtual auto is_usable() -> bool {
        return true;
    }

    virtual auto max_data_size() -> valid_if_positive<span_size_t> {
        return {0};
    }

    virtual auto send(message_id msg_id, const message_view&) -> bool = 0;

    virtual auto fetch_messages(fetch_handler handler) -> bool = 0;
};
//------------------------------------------------------------------------------
struct connection_user : interface<connection_user> {

    virtual auto add_connection(std::unique_ptr<connection>) -> bool = 0;
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_CONNECTION_HPP
