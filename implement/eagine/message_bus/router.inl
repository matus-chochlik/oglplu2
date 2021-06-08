/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <eagine/application_config.hpp>
#include <eagine/branch_predict.hpp>
#include <eagine/main_ctx.hpp>
#include <eagine/message_bus/context.hpp>
#include <eagine/message_bus/serialize.hpp>
#include <eagine/system_info.hpp>
#include <thread>

namespace eagine::msgbus {
//------------------------------------------------------------------------------
// routed_node
//------------------------------------------------------------------------------
static inline auto message_id_list_contains(
  const std::vector<message_id>& list,
  const message_id& entry) noexcept -> bool {
    return std::find(list.begin(), list.end(), entry) != list.end();
}
//------------------------------------------------------------------------------
static inline void message_id_list_add(
  std::vector<message_id>& list,
  const message_id& entry) noexcept {
    if(!message_id_list_contains(list, entry)) {
        list.push_back(entry);
    }
}
//------------------------------------------------------------------------------
static inline void message_id_list_remove(
  std::vector<message_id>& list,
  const message_id& entry) noexcept {
    const auto pos = std::find(list.begin(), list.end(), entry);
    if(pos != list.end()) {
        list.erase(pos);
    }
}
//------------------------------------------------------------------------------
routed_node::routed_node() {
    message_block_list.reserve(8);
    message_allow_list.reserve(8);
}
//------------------------------------------------------------------------------
auto routed_node::is_allowed(message_id msg_id) const noexcept -> bool {
    if(EAGINE_UNLIKELY(is_special_message(msg_id))) {
        return true;
    }
    if(!message_allow_list.empty()) {
        return message_id_list_contains(message_allow_list, msg_id);
    }
    if(!message_block_list.empty()) {
        return !message_id_list_contains(message_block_list, msg_id);
    }
    return true;
}
//------------------------------------------------------------------------------
auto routed_node::send(
  main_ctx_object& user,
  message_id msg_id,
  const message_view& message) const -> bool {
    if(EAGINE_LIKELY(the_connection)) {
        if(EAGINE_UNLIKELY(!the_connection->send(msg_id, message))) {
            user.log_debug("failed to send message to connected node");
            return false;
        }
    } else {
        user.log_debug("missing or unusable node connection");
        return false;
    }
    return true;
}
//------------------------------------------------------------------------------
void routed_node::block_message(message_id msg_id) {
    message_id_list_add(message_block_list, msg_id);
}
//------------------------------------------------------------------------------
void routed_node::allow_message(message_id msg_id) {
    message_id_list_add(message_allow_list, msg_id);
}
//------------------------------------------------------------------------------
// parent_router
//------------------------------------------------------------------------------
inline void parent_router::reset(std::unique_ptr<connection> a_connection) {
    the_connection = std::move(a_connection);
    confirmed_id = 0;
}
//------------------------------------------------------------------------------
inline auto parent_router::update(main_ctx_object& user, identifier_t id_base)
  -> work_done {
    some_true something_done{};

    if(the_connection) {
        something_done(the_connection->update());
        if(the_connection->is_usable()) {
            if(EAGINE_UNLIKELY(!confirmed_id)) {
                if(confirm_id_timeout) {
                    message_view announcement{};
                    announcement.set_source_id(id_base);
                    the_connection->send(
                      EAGINE_MSGBUS_ID(announceId), announcement);
                    confirm_id_timeout.reset();
                    something_done();

                    user.log_debug("announcing id ${id} to parent router")
                      .arg(EAGINE_ID(id), id_base);
                }
            }
            something_done(the_connection->update());
        } else {
            if(EAGINE_UNLIKELY(confirmed_id)) {
                confirmed_id = 0;
                something_done();
                user.log_debug("lost connection to parent router");
            }
        }
    }
    return something_done;
}
//------------------------------------------------------------------------------
template <typename Handler>
inline auto
parent_router::fetch_messages(main_ctx_object& user, const Handler& handler)
  -> work_done {
    some_true something_done;

    if(the_connection) {
        auto wrapped = [&](
                         message_id msg_id,
                         message_age msg_age,
                         const message_view& message) -> bool {
            if(msg_id == EAGINE_MSGBUS_ID(confirmId)) {
                confirmed_id = message.target_id;
                user.log_debug("confirmed id ${id} by parent router ${source}")
                  .arg(EAGINE_ID(id), message.target_id)
                  .arg(EAGINE_ID(source), message.source_id);
            } else if(
              msg_id.has_method(EAGINE_ID(byeByeEndp)) ||
              msg_id.has_method(EAGINE_ID(byeByeRutr)) ||
              msg_id.has_method(EAGINE_ID(byeByeBrdg))) {
                user
                  .log_debug(
                    "received bye-bye (${method}) from node ${source} "
                    "from parent router")
                  .arg(EAGINE_ID(method), msg_id.method())
                  .arg(EAGINE_ID(source), message.source_id);
            } else {
                return handler(msg_id, msg_age, message);
            }
            return true;
        };
        something_done(
          the_connection->fetch_messages({construct_from, wrapped}));
    }
    return something_done;
}
//------------------------------------------------------------------------------
auto parent_router::send(
  main_ctx_object& user,
  message_id msg_id,
  const message_view& message) const -> bool {
    if(the_connection) {
        if(EAGINE_UNLIKELY(!the_connection->send(msg_id, message))) {
            user.log_debug("failed to send message to parent router");
            return false;
        }
    }
    return true;
}
//------------------------------------------------------------------------------
// router
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto router::_uptime_seconds() -> std::int64_t {
    return std::chrono::duration_cast<std::chrono::seconds>(
             std::chrono::steady_clock::now() - _startup_time)
      .count();
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void router::add_certificate_pem(memory::const_block blk) {
    if(_context) {
        _context->add_own_certificate_pem(blk);
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void router::add_ca_certificate_pem(memory::const_block blk) {
    if(_context) {
        _context->add_ca_certificate_pem(blk);
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto router::add_acceptor(std::shared_ptr<acceptor> an_acceptor) -> bool {
    if(an_acceptor) {
        log_info("adding connection acceptor")
          .arg(EAGINE_ID(kind), an_acceptor->kind())
          .arg(EAGINE_ID(type), an_acceptor->type_id());
        _acceptors.emplace_back(std::move(an_acceptor));
        return true;
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto router::add_connection(std::unique_ptr<connection> a_connection) -> bool {
    if(a_connection) {
        log_info("assigning parent router connection")
          .arg(EAGINE_ID(kind), a_connection->kind())
          .arg(EAGINE_ID(type), a_connection->type_id());
        _parent_router.reset(std::move(a_connection));
        return true;
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void router::_setup_from_config() {

    const auto id_count = extract_or(
      app_config().get<host_id_t>("msg_bus.router.id_count"), 1U << 12U);

    const auto host_id =
      identifier_t(extract_or(main_context().system().host_id(), 0U));

    _id_base =
      extract_or(
        app_config().get<identifier_t>("msg_bus.router.id_major"),
        host_id << 32U) +
      extract_or(app_config().get<identifier_t>("msg_bus.router.id_minor"), 0U);

    if(_id_base) {
        _id_end = _id_base + id_count;
    } else {
        _id_base = 1;
        _id_end = id_count;
    }
    _id_sequence = _id_base + 1;

    log_info("using router id range ${base} - ${end} (${count})")
      .arg(EAGINE_ID(count), id_count)
      .arg(EAGINE_ID(base), _id_base)
      .arg(EAGINE_ID(end), _id_end);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto router::_handle_accept() -> work_done {
    some_true something_done{};

    if(EAGINE_LIKELY(!_acceptors.empty())) {
        acceptor::accept_handler handler{
          this, EAGINE_THIS_MEM_FUNC_C(_handle_connection)};
        for(auto& an_acceptor : _acceptors) {
            EAGINE_ASSERT(an_acceptor);
            something_done(an_acceptor->update());
            something_done(an_acceptor->process_accepted(handler));
        }
    }
    return something_done;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto router::_handle_pending() -> work_done {
    some_true something_done{};

    if(!_pending.empty()) {
        identifier_t id = 0;
        bool maybe_router = true;
        auto handler =
          [&](message_id msg_id, message_age, const message_view& msg) {
              // this is a special message requesting endpoint id assignment
              if(msg_id == EAGINE_MSGBUS_ID(requestId)) {
                  id = ~id;
                  return true;
              }
              // this is a special message containing endpoint id
              if(msg_id == EAGINE_MSGBUS_ID(annEndptId)) {
                  id = msg.source_id;
                  maybe_router = false;
                  this->log_debug("received endpoint id ${id}")
                    .arg(EAGINE_ID(id), id);
                  return true;
              }
              // this is a special message containing non-endpoint id
              if(msg_id == EAGINE_MSGBUS_ID(announceId)) {
                  id = msg.source_id;
                  this->log_debug("received id ${id}").arg(EAGINE_ID(id), id);
                  return true;
              }
              return false;
          };

        std::size_t idx = 0;
        while(idx < _pending.size()) {
            id = 0;
            auto& pending = _pending[idx];

            something_done(pending.the_connection->update());
            something_done(pending.the_connection->fetch_messages(
              {construct_from, handler}));
            something_done(pending.the_connection->update());
            // if we got the endpoint id message from the connection
            if(~id == 0) {
                _assign_id(pending.the_connection);
            } else if(id != 0) {
                log_info("adopting pending connection from ${cnterpart} ${id}")
                  .arg(EAGINE_ID(kind), pending.the_connection->kind())
                  .arg(EAGINE_ID(type), pending.the_connection->type_id())
                  .arg(EAGINE_ID(id), id)
                  .arg(
                    EAGINE_ID(cnterpart),
                    maybe_router ? string_view("non-endpoint")
                                 : string_view("endpoint"));

                // send the special message confirming assigned endpoint id
                message_view confirmation{};
                confirmation.set_source_id(_id_base).set_target_id(id);
                pending.the_connection->send(
                  EAGINE_MSGBUS_ID(confirmId), confirmation);

                auto pos = _nodes.find(id);
                if(pos == _nodes.end()) {
                    pos = _nodes.try_emplace(id).first;
                }
                pos->second.the_connection = std::move(pending.the_connection);
                pos->second.maybe_router = maybe_router;
                _pending.erase(_pending.begin() + idx);
                _recently_disconnected.erase(id);
                something_done();
            } else {
                ++idx;
            }
        }
    }
    return something_done;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto router::_remove_timeouted() -> work_done {
    some_true something_done{};

    _pending.erase(
      std::remove_if(
        _pending.begin(),
        _pending.end(),
        [this, &something_done](auto& pending) {
            if(pending.age() > this->_pending_timeout) {
                something_done();
                log_warning("removing timeouted pending ${type} connection")
                  .arg(EAGINE_ID(type), pending.the_connection->type_id())
                  .arg(EAGINE_ID(age), pending.age());
                return true;
            }
            return false;
        }),
      _pending.end());

    _endpoint_infos.erase_if([this](auto& entry) {
        auto& [endpoint_id, info] = entry;
        if(info.is_outdated) {
            _endpoint_idx.erase(endpoint_id);
            _mark_disconnected(endpoint_id);
            return true;
        }
        return false;
    });

    return something_done;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto router::_is_disconnected(identifier_t endpoint_id) -> bool {
    auto pos = _recently_disconnected.find(endpoint_id);
    if(pos != _recently_disconnected.end()) {
        if(pos->second.is_expired()) {
            _recently_disconnected.erase(pos);
        } else {
            return true;
        }
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto router::_mark_disconnected(identifier_t endpoint_id) -> void {
    _recently_disconnected.erase_if(
      [](auto& p) { return std::get<1>(p).is_expired(); });
    _recently_disconnected.emplace(endpoint_id, std::chrono::seconds{15});
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto router::_remove_disconnected() -> work_done {
    some_true something_done{};

    for(auto& [endpoint_id, node] : _nodes) {
        auto& conn = node.the_connection;
        if(EAGINE_UNLIKELY(node.do_disconnect)) {
            if(conn) {
                conn->cleanup();
            }
            conn.reset();
        } else {
            if(EAGINE_UNLIKELY(!conn->is_usable())) {
                log_debug("removing disconnected connection");
                if(conn) {
                    conn->cleanup();
                }
                conn.reset();
            }
        }
    }
    something_done(_nodes.erase_if([this](auto& p) {
        if(!p.second.the_connection) {
            _mark_disconnected(p.first);
            return true;
        }
        return false;
    }) > 0);
    return something_done;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void router::_assign_id(std::unique_ptr<connection>& conn) {
    EAGINE_ASSERT(conn);
    // find a currently unused endpoint id value
    const auto seq_orig = _id_sequence;
    while(_nodes.find(_id_sequence) != _nodes.end()) {
        if(EAGINE_UNLIKELY(++_id_sequence >= _id_end)) {
            _id_sequence = _id_base + 1;
        } else if(EAGINE_UNLIKELY(_id_sequence == seq_orig)) {
            return;
        }
    }
    //
    log_debug("assigning id ${id} to accepted ${type} connection")
      .arg(EAGINE_ID(type), conn->type_id())
      .arg(EAGINE_ID(id), _id_sequence);
    // send the special message assigning the endpoint id
    message_view msg{};
    msg.set_target_id(_id_sequence++);
    conn->send(EAGINE_MSGBUS_ID(assignId), msg);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void router::_handle_connection(std::unique_ptr<connection> a_connection) {
    EAGINE_ASSERT(a_connection);
    log_info("accepted pending connection")
      .arg(EAGINE_ID(kind), a_connection->kind())
      .arg(EAGINE_ID(type), a_connection->type_id());
    _pending.emplace_back(std::move(a_connection));
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto router::_process_blobs() -> work_done {
    some_true something_done{};
    auto resend_request = [&](message_id msg_id, message_view request) -> bool {
        return this->_do_route_message(msg_id, _id_base, request);
    };
    something_done(_blobs.update({construct_from, resend_request}));

    if(_blobs.has_outgoing()) {
        for(auto& nd : _nodes) {
            const auto node_id = std::get<0>(nd);
            const auto& conn = std::get<1>(nd).the_connection;
            if(EAGINE_LIKELY(conn && conn->is_usable())) {
                if(auto opt_max_size{conn->max_data_size()}) {
                    auto handle_send = [node_id, &conn](
                                         message_id msg_id,
                                         const message_view& message) {
                        if(node_id == message.target_id) {
                            return conn->send(msg_id, message);
                        }
                        return false;
                    };
                    if(_blobs.process_outgoing(
                         {construct_from, handle_send},
                         extract(opt_max_size))) {
                        something_done();
                    }
                }
            }
        }
    }
    return something_done;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto router::_do_get_blob_io(
  message_id msg_id,
  span_size_t size,
  blob_manipulator& blobs) -> std::unique_ptr<blob_io> {
    if(is_special_message(msg_id)) {
        if(msg_id.has_method(EAGINE_ID(eptCertPem))) {
            return blobs.make_io(size);
        }
    }
    return {};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto router::_handle_blob(
  message_id msg_id,
  message_age,
  const message_view& message) -> bool {
    // TODO: use message age
    if(is_special_message(msg_id)) {
        if(msg_id.has_method(EAGINE_ID(eptCertPem))) {
            log_trace("received endpoint certificate")
              .arg(EAGINE_ID(source), message.source_id)
              .arg(EAGINE_ID(pem), message.content());
            auto pos = _nodes.find(message.source_id);
            if(pos != _nodes.end()) {
                if(_context->add_remote_certificate_pem(
                     message.source_id, message.content())) {
                    log_debug("verified and stored endpoint certificate")
                      .arg(EAGINE_ID(source), message.source_id);
                }
            }
            if(message.target_id) {
                post_blob(
                  EAGINE_MSGBUS_ID(eptCertPem),
                  message.source_id,
                  message.target_id,
                  message.sequence_no,
                  message.content(),
                  adjusted_duration(std::chrono::seconds(30)),
                  message_priority::high);
            }
        }
    }
    return true;
}
//------------------------------------------------------------------------------
auto router::_update_endpoint_info(
  identifier_t incoming_id,
  const message_view& message) -> router_endpoint_info& {
    _endpoint_idx[message.source_id] = incoming_id;
    auto& info = _endpoint_infos[message.source_id];
    // sequence_no is the instance id in this message type
    info.assign_instance_id(message);
    return info;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto router::_handle_ping(const message_view& message)
  -> message_handling_result {
    if(message.target_id == _id_base) {
        message_view response{};
        response.setup_response(message);
        response.set_source_id(_id_base);
        this->_do_route_message(EAGINE_MSGBUS_ID(pong), _id_base, response);
        return was_handled;
    }
    return should_be_forwarded;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto router::_handle_subscribed(
  identifier_t incoming_id,
  const message_view& message) -> message_handling_result {
    message_id sub_msg_id{};
    if(default_deserialize_message_type(sub_msg_id, message.content())) {
        log_debug("endpoint ${source} subscribes to ${message}")
          .arg(EAGINE_ID(source), message.source_id)
          .arg(EAGINE_ID(message), sub_msg_id);

        auto& info = _update_endpoint_info(incoming_id, message);
        message_id_list_add(info.subscriptions, sub_msg_id);
        message_id_list_remove(info.unsubscriptions, sub_msg_id);
    }
    return should_be_forwarded;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto router::_handle_not_subscribed(
  identifier_t incoming_id,
  const message_view& message) -> message_handling_result {
    message_id sub_msg_id{};
    if(default_deserialize_message_type(sub_msg_id, message.content())) {
        log_debug("endpoint ${source} unsubscribes from ${message}")
          .arg(EAGINE_ID(source), message.source_id)
          .arg(EAGINE_ID(message), sub_msg_id);

        auto& info = _update_endpoint_info(incoming_id, message);
        message_id_list_remove(info.subscriptions, sub_msg_id);
        message_id_list_add(info.unsubscriptions, sub_msg_id);
    }
    return should_be_forwarded;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto router::_handle_subscribers_query(const message_view& message)
  -> message_handling_result {
    const auto pos = _endpoint_infos.find(message.target_id);
    if(pos != _endpoint_infos.end()) {
        auto& info = pos->second;
        if(info.instance_id) {
            message_id sub_msg_id{};
            if(default_deserialize_message_type(
                 sub_msg_id, message.content())) {
                // if we have the information cached, then respond
                if(message_id_list_contains(info.subscriptions, sub_msg_id)) {
                    message_view response{message.data()};
                    response.setup_response(message);
                    response.set_source_id(message.target_id);
                    response.set_sequence_no(info.instance_id);
                    this->_do_route_message(
                      EAGINE_MSGBUS_ID(subscribTo), _id_base, response);
                }
                if(message_id_list_contains(info.unsubscriptions, sub_msg_id)) {
                    message_view response{message.data()};
                    response.setup_response(message);
                    response.set_source_id(message.target_id);
                    response.set_sequence_no(info.instance_id);
                    this->_do_route_message(
                      EAGINE_MSGBUS_ID(notSubTo), _id_base, response);
                }
            }
        }
    }

    return should_be_forwarded;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto router::_handle_subscriptions_query(const message_view& message)
  -> message_handling_result {
    const auto pos = _endpoint_infos.find(message.target_id);
    if(pos != _endpoint_infos.end()) {
        auto& info = pos->second;
        if(info.instance_id) {
            for(auto& sub_msg_id : info.subscriptions) {
                auto temp{default_serialize_buffer_for(sub_msg_id)};
                if(auto serialized{
                     default_serialize_message_type(sub_msg_id, cover(temp))}) {
                    message_view response{extract(serialized)};
                    response.setup_response(message);
                    response.set_source_id(message.target_id);
                    response.set_sequence_no(info.instance_id);
                    this->_do_route_message(
                      EAGINE_MSGBUS_ID(subscribTo), _id_base, response);
                }
            }
        }
    }
    return should_be_forwarded;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto router::_handle_router_certificate_query(const message_view& message)
  -> message_handling_result {
    post_blob(
      EAGINE_MSGBUS_ID(rtrCertPem),
      0U,
      message.source_id,
      message.sequence_no,
      _context->get_own_certificate_pem(),
      adjusted_duration(std::chrono::seconds{30}),
      message_priority::high);
    return was_handled;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto router::_handle_endpoint_certificate_query(const message_view& message)
  -> message_handling_result {
    if(auto cert_pem{_context->get_remote_certificate_pem(message.target_id)}) {
        post_blob(
          EAGINE_MSGBUS_ID(eptCertPem),
          message.target_id,
          message.source_id,
          message.sequence_no,
          cert_pem,
          adjusted_duration(std::chrono::seconds{30}),
          message_priority::high);
        return was_handled;
    }
    return should_be_forwarded;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto router::_handle_topology_query(const message_view& message)
  -> message_handling_result {
    router_topology_info info{};

    auto temp{default_serialize_buffer_for(info)};
    auto respond = [&](identifier_t remote_id, const auto& conn) {
        info.router_id = _id_base;
        info.remote_id = remote_id;
        info.instance_id = _instance_id;
        info.connect_kind = conn->kind();
        if(auto serialized{default_serialize(info, cover(temp))}) {
            message_view response{extract(serialized)};
            response.setup_response(message);
            response.set_source_id(_id_base);
            this->_do_route_message(
              EAGINE_MSGBUS_ID(topoRutrCn), _id_base, response);
        }
    };

    for(auto& [nd_id, nd] : this->_nodes) {
        respond(nd_id, nd.the_connection);
    }
    if(_parent_router.confirmed_id) {
        respond(_parent_router.confirmed_id, _parent_router.the_connection);
    }
    return should_be_forwarded;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto router::_update_stats() -> work_done {
    some_true something_done;

    const auto now = std::chrono::steady_clock::now();
    const std::chrono::duration<float> seconds{now - _forwarded_since_stat};
    if(EAGINE_UNLIKELY(seconds.count() >= 15.F)) {
        _forwarded_since_stat = now;

        _stats.messages_per_second = static_cast<std::int32_t>(
          float(_stats.forwarded_messages - _prev_forwarded_messages) /
          seconds.count());
        _prev_forwarded_messages = _stats.forwarded_messages;

        const auto avg_msg_age_us = static_cast<std::int32_t>(
          (1000000.F * _message_age_sum) /
          float(_stats.forwarded_messages + _stats.dropped_messages + 1));
        const auto avg_msg_age_ms = avg_msg_age_us / 1000;

        _stats.message_age_us = avg_msg_age_us;

        const bool flow_info_changed =
          _flow_info.avg_msg_age_ms != avg_msg_age_ms;
        _flow_info.avg_msg_age_ms = avg_msg_age_ms;

        if(EAGINE_UNLIKELY(flow_info_changed)) {
            auto send_info = [&](identifier_t remote_id, const auto& conn) {
                auto buf{default_serialize_buffer_for(_flow_info)};
                if(auto serialized{default_serialize(_flow_info, cover(buf))}) {
                    message_view response{extract(serialized)};
                    response.set_source_id(_id_base);
                    response.set_target_id(remote_id);
                    response.set_priority(message_priority::high);
                    conn->send(EAGINE_MSGBUS_ID(msgFlowInf), response);
                    something_done();
                }
            };

            for(auto& [nd_id, nd] : this->_nodes) {
                send_info(nd_id, nd.the_connection);
            }
        }
    }
    _stats.uptime_seconds = _uptime_seconds();

    return something_done;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto router::_handle_stats_query(const message_view& message)
  -> message_handling_result {
    _update_stats();

    auto rs_buf{default_serialize_buffer_for(_stats)};
    if(auto serialized{default_serialize(_stats, cover(rs_buf))}) {
        message_view response{extract(serialized)};
        response.setup_response(message);
        response.set_source_id(_id_base);
        this->_do_route_message(
          EAGINE_MSGBUS_ID(statsRutr), _id_base, response);
    }

    auto respond = [&](identifier_t remote_id, const auto& conn) {
        connection_statistics conn_stats{};
        conn_stats.local_id = _id_base;
        conn_stats.remote_id = remote_id;
        if(conn->query_statistics(conn_stats)) {
            auto cs_buf{default_serialize_buffer_for(conn_stats)};
            if(auto serialized{default_serialize(conn_stats, cover(cs_buf))}) {
                message_view response{extract(serialized)};
                response.setup_response(message);
                response.set_source_id(_id_base);
                this->_do_route_message(
                  EAGINE_MSGBUS_ID(statsConn), _id_base, response);
            }
        }
    };

    for(auto& [nd_id, nd] : this->_nodes) {
        respond(nd_id, nd.the_connection);
    }
    if(_parent_router.confirmed_id) {
        respond(_parent_router.confirmed_id, _parent_router.the_connection);
    }
    return should_be_forwarded;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto router::_handle_blob_fragment(const message_view& message)
  -> message_handling_result {
    if(_blobs.process_incoming(
         EAGINE_THIS_MEM_FUNC_REF(_do_get_blob_io), message)) {
        _blobs.fetch_all(EAGINE_THIS_MEM_FUNC_REF(_handle_blob));
    }
    return (message.target_id == _id_base) ? was_handled : should_be_forwarded;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto router::_handle_blob_resend(const message_view& message)
  -> message_handling_result {
    if(message.target_id == _id_base) {
        _blobs.process_resend(message);
        return was_handled;
    }
    return should_be_forwarded;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto router::_handle_special_common(
  message_id msg_id,
  identifier_t incoming_id,
  const message_view& message) -> message_handling_result {

    if(msg_id.has_method(EAGINE_ID(ping))) {
        return _handle_ping(message);
    } else if(msg_id.has_method(EAGINE_ID(pong))) {
        return should_be_forwarded;
    } else if(msg_id.has_method(EAGINE_ID(subscribTo))) {
        return _handle_subscribed(incoming_id, message);
    } else if(
      msg_id.has_method(EAGINE_ID(unsubFrom)) ||
      msg_id.has_method(EAGINE_ID(notSubTo))) {
        return _handle_not_subscribed(incoming_id, message);
    } else if(msg_id.has_method(EAGINE_ID(qrySubscrb))) {
        return _handle_subscribers_query(message);
    } else if(msg_id.has_method(EAGINE_ID(qrySubscrp))) {
        return _handle_subscriptions_query(message);
    } else if(msg_id.has_method(EAGINE_ID(blobFrgmnt))) {
        return _handle_blob_fragment(message);
    } else if(msg_id.has_method(EAGINE_ID(blobResend))) {
        return _handle_blob_resend(message);
    } else if(msg_id.has_method(EAGINE_ID(rtrCertQry))) {
        return _handle_router_certificate_query(message);
    } else if(msg_id.has_method(EAGINE_ID(eptCertQry))) {
        return _handle_endpoint_certificate_query(message);
    } else if(msg_id.has_method(EAGINE_ID(requestId))) {
        return was_handled;
    } else if(msg_id.has_method(EAGINE_ID(topoQuery))) {
        return _handle_topology_query(message);
    } else if(msg_id.has_method(EAGINE_ID(statsQuery))) {
        return _handle_stats_query(message);
    } else if(
      msg_id.has_method(EAGINE_ID(msgFlowInf)) ||
      msg_id.has_method(EAGINE_ID(topoRutrCn)) ||
      msg_id.has_method(EAGINE_ID(topoBrdgCn)) ||
      msg_id.has_method(EAGINE_ID(topoEndpt)) ||
      msg_id.has_method(EAGINE_ID(statsRutr)) ||
      msg_id.has_method(EAGINE_ID(statsBrdg)) ||
      msg_id.has_method(EAGINE_ID(statsEndpt)) ||
      msg_id.has_method(EAGINE_ID(statsConn))) {
        return should_be_forwarded;
    } else if(msg_id.has_method(EAGINE_ID(annEndptId))) {
        return was_handled;
    } else {
        log_warning("unhandled special message ${message} from ${source}")
          .arg(EAGINE_ID(message), msg_id)
          .arg(EAGINE_ID(source), message.source_id)
          .arg(EAGINE_ID(data), message.data());
    }
    return should_be_forwarded;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto router::_handle_special(
  message_id msg_id,
  identifier_t incoming_id,
  const message_view& message) -> message_handling_result {
    if(EAGINE_UNLIKELY(is_special_message(msg_id))) {
        log_debug("router handling special message ${message} from parent")
          .arg(EAGINE_ID(router), _id_base)
          .arg(EAGINE_ID(message), msg_id)
          .arg(EAGINE_ID(target), message.target_id)
          .arg(EAGINE_ID(source), message.source_id);

        if(msg_id.has_method(EAGINE_ID(stillAlive))) {
            _update_endpoint_info(incoming_id, message);
            return should_be_forwarded;
        } else {
            return _handle_special_common(msg_id, incoming_id, message);
        }
    }
    return should_be_forwarded;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto router::_handle_special(
  message_id msg_id,
  identifier_t incoming_id,
  routed_node& node,
  const message_view& message) -> message_handling_result {
    if(EAGINE_UNLIKELY(is_special_message(msg_id))) {
        log_debug("router handling special message ${message} from node")
          .arg(EAGINE_ID(router), _id_base)
          .arg(EAGINE_ID(message), msg_id)
          .arg(EAGINE_ID(target), message.target_id)
          .arg(EAGINE_ID(source), message.source_id);

        if(msg_id.has_method(EAGINE_ID(notARouter))) {
            if(incoming_id == message.source_id) {
                node.maybe_router = false;
                log_debug("node ${source} is not a router")
                  .arg(EAGINE_ID(source), message.source_id);
            }
            return was_handled;
        } else if(msg_id.has_method(EAGINE_ID(clrBlkList))) {
            log_debug("clearing router block_list");
            node.message_block_list.clear();
            return was_handled;
        } else if(msg_id.has_method(EAGINE_ID(clrAlwList))) {
            log_debug("clearing router allow_list");
            node.message_allow_list.clear();
            return was_handled;
        } else if(msg_id.has_method(EAGINE_ID(msgBlkList))) {
            message_id blk_msg_id{};
            if(default_deserialize_message_type(
                 blk_msg_id, message.content())) {
                if(!is_special_message(msg_id)) {
                    log_debug("node ${source} blocking message ${message}")
                      .arg(EAGINE_ID(message), blk_msg_id)
                      .arg(EAGINE_ID(source), message.source_id);
                    node.block_message(blk_msg_id);
                    _update_endpoint_info(incoming_id, message);
                    return was_handled;
                }
            }
        } else if(msg_id.has_method(EAGINE_ID(msgAlwList))) {
            message_id alw_msg_id{};
            if(default_deserialize_message_type(
                 alw_msg_id, message.content())) {
                log_debug("node ${source} allowing message ${message}")
                  .arg(EAGINE_ID(message), alw_msg_id)
                  .arg(EAGINE_ID(source), message.source_id);
                node.allow_message(alw_msg_id);
                _update_endpoint_info(incoming_id, message);
                return was_handled;
            }
        } else if(msg_id.has_method(EAGINE_ID(stillAlive))) {
            _update_endpoint_info(incoming_id, message);

            return should_be_forwarded;
        } else if(
          msg_id.has_method(EAGINE_ID(byeByeEndp)) ||
          msg_id.has_method(EAGINE_ID(byeByeRutr)) ||
          msg_id.has_method(EAGINE_ID(byeByeBrdg))) {
            log_debug("received bye-bye (${method}) from node ${source}")
              .arg(EAGINE_ID(method), msg_id.method())
              .arg(EAGINE_ID(source), message.source_id);
            if(!node.maybe_router) {
                node.do_disconnect = true;
            }
            _endpoint_idx.erase(message.source_id);
            _endpoint_infos.erase(message.source_id);

            return should_be_forwarded;
        } else {
            return _handle_special_common(msg_id, incoming_id, message);
        }
    }
    return should_be_forwarded;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto router::_do_route_message(
  message_id msg_id,
  identifier_t incoming_id,
  message_view& message) -> bool {

    bool result = true;
    if(EAGINE_UNLIKELY(message.too_many_hops())) {
        log_warning("message ${message} discarded after too many hops")
          .arg(EAGINE_ID(message), msg_id);
        ++_stats.dropped_messages;
    } else {
        const auto& nodes = this->_nodes;
        message.add_hop();
        const bool is_targeted = (message.target_id != broadcast_endpoint_id());

        const auto forward_to = [&](auto& node_out) {
            if(EAGINE_UNLIKELY(++_stats.forwarded_messages % 1000000 == 0)) {
                const auto now{std::chrono::steady_clock::now()};
                const std::chrono::duration<float> interval{
                  now - _forwarded_since_log};

                if(EAGINE_LIKELY(interval > decltype(interval)::zero())) {
                    const auto msgs_per_sec{1000000.F / interval.count()};

                    log_chart_sample(EAGINE_ID(msgsPerSec), msgs_per_sec);
                    log_stat("forwarded ${count} messages")
                      .arg(EAGINE_ID(count), _stats.forwarded_messages)
                      .arg(EAGINE_ID(dropped), _stats.dropped_messages)
                      .arg(EAGINE_ID(interval), interval)
                      .arg(
                        EAGINE_ID(avgMsgAge),
                        std::chrono::microseconds(_stats.message_age_us))
                      .arg(EAGINE_ID(msgsPerSec), msgs_per_sec);
                }

                _forwarded_since_log = now;
            }
            return node_out.send(*this, msg_id, message);
        };

        if(is_targeted) {
            bool has_routed = false;
            auto pos = _endpoint_idx.find(message.target_id);
            if(pos != _endpoint_idx.end()) {
                // if the message should go through the parent router
                if(pos->second == _id_base) {
                    has_routed |= _parent_router.send(*this, msg_id, message);
                } else {
                    auto node_pos = nodes.find(pos->second);
                    if(node_pos != nodes.end()) {
                        auto& node_out = node_pos->second;
                        if(node_out.is_allowed(msg_id)) {
                            has_routed = forward_to(node_out);
                        }
                    }
                }
            }

            if(!has_routed) {
                for(const auto& [outgoing_id, node_out] : nodes) {
                    if(outgoing_id == message.target_id) {
                        if(node_out.is_allowed(msg_id)) {
                            has_routed = forward_to(node_out);
                        }
                    }
                }
            }

            if(EAGINE_LIKELY(!_is_disconnected(message.target_id))) {
                if(!has_routed) {
                    for(const auto& [outgoing_id, node_out] : nodes) {
                        if(node_out.maybe_router) {
                            if(incoming_id != outgoing_id) {
                                has_routed |= forward_to(node_out);
                            }
                        }
                    }
                    // if the message didn't come from the parent router
                    if(incoming_id != _id_base) {
                        has_routed |=
                          _parent_router.send(*this, msg_id, message);
                    }
                }
            }
            result &= has_routed;
        } else {
            for(const auto& [outgoing_id, node_out] : nodes) {
                if(incoming_id != outgoing_id) {
                    if(node_out.is_allowed(msg_id)) {
                        result |= forward_to(node_out);
                    }
                }
            }
            if(incoming_id != _id_base) {
                result |= _parent_router.send(*this, msg_id, message);
            }
        }
    }
    return result;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto router::_route_messages() -> work_done {
    some_true something_done{};
    const auto now = std::chrono::steady_clock::now();
    const auto message_age_inc =
      std::chrono::duration<float>{now - _prev_route_time}.count();
    _prev_route_time = now;

    for(auto& nd : _nodes) {
        auto handler =
          [&](message_id msg_id, message_age msg_age, message_view message) {
              auto& [incoming_id, node_in] = nd;
              _message_age_sum +=
                message.add_age(msg_age).age().count() + message_age_inc;
              if(
                this->_handle_special(msg_id, incoming_id, node_in, message) ==
                was_handled) {
                  return true;
              }
              if(EAGINE_UNLIKELY(message.too_old())) {
                  ++_stats.dropped_messages;
                  return true;
              }
              return this->_do_route_message(msg_id, incoming_id, message);
          };

        const auto& conn_in = std::get<1>(nd).the_connection;
        if(EAGINE_LIKELY(conn_in && conn_in->is_usable())) {
            something_done(conn_in->fetch_messages({construct_from, handler}));
        }
    }

    auto handler =
      [&](message_id msg_id, message_age msg_age, message_view message) {
          _message_age_sum +=
            message.add_age(msg_age).age().count() + message_age_inc;
          if(
            this->_handle_special(
              msg_id, _parent_router.confirmed_id, message) == was_handled) {
              return true;
          }
          if(EAGINE_UNLIKELY(message.too_old())) {
              ++_stats.dropped_messages;
              return true;
          }
          return this->_do_route_message(msg_id, _id_base, message);
      };
    something_done(_parent_router.fetch_messages(*this, handler));

    return something_done;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto router::_update_connections() -> work_done {
    some_true something_done{};

    for(auto& [id, node] : _nodes) {
        EAGINE_MAYBE_UNUSED(id);
        const auto& conn = node.the_connection;
        if(EAGINE_LIKELY(conn)) {
            something_done(conn->update());
        }
    }

    something_done(_parent_router.update(*this, _id_base));

    if(_nodes.empty() && _pending.empty()) {
        std::this_thread::yield();
    } else {
        _no_connection_timeout.reset();
    }
    return something_done;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto router::do_maintenance() -> work_done {
    some_true something_done{};

    something_done(_update_stats());
    something_done(_process_blobs());
    something_done(_remove_timeouted());
    something_done(_remove_disconnected());

    return something_done;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto router::do_work() -> work_done {
    some_true something_done{};

    something_done(_handle_pending());
    something_done(_handle_accept());
    something_done(_route_messages());
    something_done(_update_connections());

    return something_done;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto router::update(const valid_if_positive<int>& count) -> work_done {
    some_true something_done{};

    something_done(do_maintenance());

    int n = extract_or(count, 2);
    do {
        something_done(do_work());
    } while((n-- > 0) && something_done);

    return something_done;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void router::say_bye() {
    const auto msgid = EAGINE_MSGBUS_ID(byeByeRutr);
    message_view msg{};
    msg.set_source_id(_id_base);
    for(auto& [id, node] : _nodes) {
        EAGINE_MAYBE_UNUSED(id);
        const auto& conn = node.the_connection;
        if(conn) {
            conn->send(msgid, msg);
            conn->update();
        }
    }

    _parent_router.send(*this, msgid, msg);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void router::cleanup() {
    for(auto& [id, node] : _nodes) {
        EAGINE_MAYBE_UNUSED(id);
        const auto& conn = node.the_connection;
        if(conn) {
            conn->cleanup();
        }
    }

    log_stat("forwarded ${count} messages in total")
      .arg(EAGINE_ID(count), _stats.forwarded_messages)
      .arg(EAGINE_ID(dropped), _stats.dropped_messages)
      .arg(
        EAGINE_ID(avgMsgAge), std::chrono::microseconds(_stats.message_age_us));
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void router::finish() {
    say_bye();
    timeout too_long{adjusted_duration(std::chrono::seconds{1})};
    while(!too_long) {
        update(8);
    }
    cleanup();
}
//------------------------------------------------------------------------------
} // namespace eagine::msgbus
