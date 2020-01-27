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

namespace eagine {
namespace msgbus {
//------------------------------------------------------------------------------
enum class connection_kind : std::uint8_t {
    in_process = 1 << 0,
    local_interprocess = 1 << 1,
    remote_interprocess = 1 << 2
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
struct connection_info {
    virtual ~connection_info() noexcept = default;
    connection_info() noexcept = default;
    connection_info(connection_info&&) noexcept = default;
    connection_info(const connection_info&) = delete;
    connection_info& operator=(connection_info&&) = delete;
    connection_info& operator=(const connection_info&) = delete;

    virtual connection_kind kind() = 0;

    virtual identifier type_id() = 0;
};
//------------------------------------------------------------------------------
struct connection : connection_info {

    using fetch_handler =
      callable_ref<bool(identifier_t, identifier_t, const message_view&)>;

    virtual void update() {
    }

    virtual bool is_usable() {
        return true;
    }

    virtual valid_if_positive<span_size_t> max_data_size() {
        return {0};
    }

    virtual bool send(
      identifier_t class_id, identifier_t method_id, const message_view&) = 0;

    template <identifier_t ClassId, identifier_t MethodId>
    bool send(message_id<ClassId, MethodId>, const message_view& msg) {
        return send(ClassId, MethodId, msg);
    }

    virtual void fetch_messages(fetch_handler handler) = 0;
};
//------------------------------------------------------------------------------
struct connection_user {
    virtual ~connection_user() noexcept = default;
    connection_user() noexcept = default;
    connection_user(connection_user&&) noexcept = default;
    connection_user(const connection_user&) = delete;
    connection_user& operator=(connection_user&&) = delete;
    connection_user& operator=(const connection&) = delete;

    virtual bool add_connection(std::unique_ptr<connection> a_connection) = 0;
};
//------------------------------------------------------------------------------
} // namespace msgbus
} // namespace eagine

#endif // EAGINE_MESSAGE_BUS_CONNECTION_HPP

