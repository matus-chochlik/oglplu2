/**
 *  @file eagine/message_bus/bridge.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MESSAGE_BUS_BRIDGE_HPP
#define EAGINE_MESSAGE_BUS_BRIDGE_HPP

#include "../logging/logger.hpp"
#include "../program_args.hpp"
#include "../timeout.hpp"
#include "connection.hpp"
#include "context_fwd.hpp"
#include <memory>

namespace eagine {
namespace msgbus {
//------------------------------------------------------------------------------
class bridge_state;
class bridge : public connection_user {
public:
    bridge(logger& parent) noexcept
      : _log(EAGINE_ID(MsgBusBrdg), parent)
      , _context{make_context(_log)} {
    }

    bridge(logger& parent, const program_args& args) noexcept
      : _log(EAGINE_ID(MsgBusRutr), parent)
      , _context{make_context(_log, args)} {
        _setup_from_args(args);
    }

    bool add_connection(std::unique_ptr<connection>) final;

    bool update();

    auto& no_connection_timeout() const noexcept {
        return _no_connection_timeout;
    }

    bool is_done() const noexcept {
        return bool(no_connection_timeout());
    }

private:
    void _setup_from_args(const program_args&);

    bool _check_state();
    bool _update_connections();
    bool _handle_special(identifier_t, identifier_t, message_view);
    bool _do_forward_message(identifier_t, identifier_t, message_view);
    bool _forward_messages();

    logger _log{};
    shared_context _context{};
    std::shared_ptr<bridge_state> _state{};
    timeout _no_connection_timeout{std::chrono::seconds{30}};
    std::vector<std::unique_ptr<connection>> _connections{};
};
//------------------------------------------------------------------------------
} // namespace msgbus
} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/message_bus/bridge.inl>
#endif

#endif // EAGINE_MESSAGE_BUS_BRIDGE_HPP
