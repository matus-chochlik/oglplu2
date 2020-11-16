/**
 *  @file eagine/message_bus/router.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MESSAGE_BUS_ROUTER_HPP
#define EAGINE_MESSAGE_BUS_ROUTER_HPP

#include "../flat_map.hpp"
#include "../logging/logger.hpp"
#include "../timeout.hpp"
#include "../valid_if/positive.hpp"
#include "acceptor.hpp"
#include "blobs.hpp"
#include "context_fwd.hpp"
#include <map>
#include <vector>

namespace eagine::msgbus {
//------------------------------------------------------------------------------
struct router_pending {

    router_pending(std::unique_ptr<connection> a_connection)
      : the_connection{std::move(a_connection)} {}

    std::chrono::steady_clock::time_point create_time{
      std::chrono::steady_clock::now()};

    std::unique_ptr<connection> the_connection{};

    auto age() const {
        return std::chrono::steady_clock::now() - create_time;
    }
};
//------------------------------------------------------------------------------
struct routed_endpoint {
    std::unique_ptr<connection> the_connection{};
    std::vector<message_id> message_block_list{};
    std::vector<message_id> message_allow_list{};
    bool maybe_router{true};
    bool do_disconnect{false};

    routed_endpoint();
    routed_endpoint(routed_endpoint&&) noexcept = default;
    routed_endpoint(const routed_endpoint&) = delete;
    auto operator=(routed_endpoint&&) noexcept -> routed_endpoint& = default;
    auto operator=(const routed_endpoint&) -> routed_endpoint& = delete;
    ~routed_endpoint() noexcept = default;

    void block_message(message_id);
    void allow_message(message_id);

    auto is_allowed(message_id) const noexcept -> bool;

    auto send(logger& log, message_id, message_view) const -> bool;
};
//------------------------------------------------------------------------------
struct parent_router {
    std::unique_ptr<connection> the_connection{};
    identifier_t confirmed_id{0};
    timeout confirm_id_timeout{std::chrono::seconds(2), nothing};

    void reset(std::unique_ptr<connection>);

    auto update(logger&, identifier_t id_base) -> bool;

    template <typename Handler>
    auto fetch_messages(logger&, const Handler&) -> bool;

    auto send(logger& log, message_id, message_view) const -> bool;
};
//------------------------------------------------------------------------------
class router
  : public acceptor_user
  , public connection_user {
public:
    router() = default;

    router(logger& parent) noexcept
      : _log{EAGINE_ID(MsgBusRutr), parent}
      , _context{make_context(_log)} {}

    router(logger& parent, application_config& cfg) noexcept
      : _log{EAGINE_ID(MsgBusRutr), parent}
      , _context{make_context(_log, cfg)} {
        _setup_from_config(cfg);
    }

    void add_certificate_pem(memory::const_block blk);
    void add_ca_certificate_pem(memory::const_block blk);

    auto add_acceptor(std::shared_ptr<acceptor>) -> bool final;
    auto add_connection(std::unique_ptr<connection>) -> bool final;

    auto do_maintenance() -> bool;
    auto do_work() -> bool;

    auto update(const valid_if_positive<int>& count) -> bool;
    auto update() -> bool {
        return update(2);
    }

    auto no_connection_timeout() const noexcept -> auto& {
        return _no_connection_timeout;
    }

    auto is_done() const noexcept -> bool {
        return bool(no_connection_timeout());
    }

    void post_blob(
      message_id msg_id,
      identifier_t source_id,
      identifier_t target_id,
      memory::const_block blob,
      std::chrono::seconds max_time,
      message_priority priority) {
        _blobs.push_outgoing(
          msg_id, source_id, target_id, blob, max_time, priority);
    }

private:
    void _setup_from_config(application_config&);

    auto _handle_accept() -> bool;
    auto _handle_pending() -> bool;
    auto _remove_timeouted() -> bool;
    auto _remove_disconnected() -> bool;
    void _assign_id(std::unique_ptr<connection>& conn);
    void _handle_connection(std::unique_ptr<connection> conn);

    auto _cleanup_blobs() -> bool;
    auto _process_blobs() -> bool;
    auto _do_allow_blob(message_id) -> bool;
    auto _handle_blob(message_id, message_age, const message_view&) -> bool;

    auto _handle_special(
      message_id msg_id,
      identifier_t incoming_id,
      routed_endpoint&,
      const message_view&) -> bool;

    auto _do_route_message(
      message_id msg_id,
      identifier_t incoming_id,
      message_view message) -> bool;

    auto _route_messages() -> bool;
    auto _update_connections() -> bool;

    logger _log{};
    shared_context _context{};
    const std::chrono::seconds _pending_timeout{30};
    timeout _no_connection_timeout{std::chrono::seconds{30}};
    identifier_t _id_base{0};
    identifier_t _id_sequence{0};
    std::chrono::steady_clock::time_point _forwarded_since{
      std::chrono::steady_clock::now()};
    std::intmax_t _forwarded_messages{0};
    parent_router _parent_router;
    std::vector<std::shared_ptr<acceptor>> _acceptors;
    std::vector<router_pending> _pending;
    flat_map<identifier_t, routed_endpoint> _endpoints;
    blob_manipulator _blobs{};
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/message_bus/router.inl>
#endif

#endif // EAGINE_MESSAGE_BUS_ROUTER_HPP
