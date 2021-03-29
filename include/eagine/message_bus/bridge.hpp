/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MESSAGE_BUS_BRIDGE_HPP
#define EAGINE_MESSAGE_BUS_BRIDGE_HPP

#include "../main_ctx_object.hpp"
#include "../timeout.hpp"
#include "connection.hpp"
#include "context_fwd.hpp"
#include <memory>

namespace eagine::msgbus {
//------------------------------------------------------------------------------
class bridge_state;
class bridge
  : public main_ctx_object
  , public connection_user {

    static constexpr auto invalid_id() noexcept -> identifier_t {
        return 0U;
    }

    static constexpr auto is_valid_id(identifier_t id) noexcept -> bool {
        return id != invalid_id();
    }

public:
    bridge(main_ctx_parent parent) noexcept
      : main_ctx_object(EAGINE_ID(MsgBusBrdg), parent)
      , _context{make_context(*this)} {
        _setup_from_config();
    }

    void add_certificate_pem(memory::const_block blk);
    void add_ca_certificate_pem(memory::const_block blk);

    auto add_connection(std::unique_ptr<connection>) -> bool final;

    auto has_id() const noexcept -> bool {
        return is_valid_id(_id);
    }

    auto update() -> bool;
    auto is_done() const noexcept -> bool;
    void cleanup();

    auto no_connection_timeout() const noexcept -> auto& {
        return _no_connection_timeout;
    }

private:
    void _setup_from_config();

    auto _check_state() -> bool;
    auto _update_connections() -> bool;

    auto _do_send(message_id, message_view) -> bool;
    auto _send(message_id, message_view) -> bool;
    auto _handle_special(message_id, message_view, bool) -> bool;
    auto _do_push(message_id, message_view) -> bool;
    auto _forward_messages() -> bool;

    shared_context _context{};

    const process_instance_id_t _instance_id{process_instance_id()};
    identifier_t _id{invalid_id()};
    timeout _no_id_timeout{std::chrono::seconds{2}, nothing};

    std::chrono::steady_clock::time_point _forwarded_since_i2c{
      std::chrono::steady_clock::now()};
    std::chrono::steady_clock::time_point _forwarded_since_c2o{
      std::chrono::steady_clock::now()};
    std::intmax_t _forwarded_messages_i2c{0};
    std::intmax_t _forwarded_messages_c2o{0};
    std::intmax_t _dropped_messages_i2c{0};
    std::intmax_t _dropped_messages_c2o{0};

    std::shared_ptr<bridge_state> _state{};
    timeout _no_connection_timeout{std::chrono::seconds{30}};
    std::unique_ptr<connection> _connection{};
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/message_bus/bridge.inl>
#endif

#endif // EAGINE_MESSAGE_BUS_BRIDGE_HPP
