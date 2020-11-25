/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/application_config.hpp>
#include <eagine/bool_aggregate.hpp>
#include <eagine/branch_predict.hpp>
#include <eagine/main_ctx.hpp>
#include <eagine/message_bus/context.hpp>
#include <eagine/message_bus/serialize.hpp>
#include <thread>

namespace eagine::msgbus {
//------------------------------------------------------------------------------
// routed_endpoint
//------------------------------------------------------------------------------
static inline auto routed_endpoint_list_contains(
  const std::vector<message_id>& list,
  const message_id& entry) noexcept -> bool {
    return std::find(list.begin(), list.end(), entry) != list.end();
}
//------------------------------------------------------------------------------
routed_endpoint::routed_endpoint() {
    message_block_list.reserve(8);
    message_allow_list.reserve(8);
}
//------------------------------------------------------------------------------
auto routed_endpoint::is_allowed(message_id msg_id) const noexcept -> bool {
    if(EAGINE_UNLIKELY(is_special_message(msg_id))) {
        return true;
    }
    if(!message_allow_list.empty()) {
        return routed_endpoint_list_contains(message_allow_list, msg_id);
    }
    if(!message_block_list.empty()) {
        return !routed_endpoint_list_contains(message_block_list, msg_id);
    }
    return true;
}
//------------------------------------------------------------------------------
auto routed_endpoint::send(
  main_ctx_object& user,
  message_id msg_id,
  message_view message) const -> bool {
    if(EAGINE_LIKELY(the_connection)) {
        if(EAGINE_UNLIKELY(!the_connection->send(msg_id, message))) {
            user.log_debug("failed to send message to endpoint");
            return false;
        }
    } else {
        user.log_debug("missing or unusable endpoint connection");
        return false;
    }
    return true;
}
//------------------------------------------------------------------------------
void routed_endpoint::block_message(message_id msg_id) {
    if(!routed_endpoint_list_contains(message_block_list, msg_id)) {
        message_block_list.push_back(msg_id);
    }
}
//------------------------------------------------------------------------------
void routed_endpoint::allow_message(message_id msg_id) {
    if(!routed_endpoint_list_contains(message_allow_list, msg_id)) {
        message_allow_list.push_back(msg_id);
    }
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
  -> bool {
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
  -> bool {

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
            } else if(msg_id.has_method(EAGINE_ID(byeBye))) {
                user.log_debug("received bye-bye from parent router ${source}")
                  .arg(EAGINE_ID(source), message.source_id);
            } else {
                return handler(msg_id, msg_age, message);
            }
            return true;
        };
        return the_connection->fetch_messages(
          connection::fetch_handler{wrapped});
    }
    return false;
}
//------------------------------------------------------------------------------
auto parent_router::send(
  main_ctx_object& user,
  message_id msg_id,
  message_view message) const -> bool {
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
      app_config().get<system_info::host_id_type>("msg_bus.router.id_count"),
      1U << 12U);

    const auto host_id =
      identifier_t(extract_or(main_context().system().host_id(), 0U));

    _id_base =
      extract_or(
        app_config().get<identifier_t>("msg_bus.router.id_major"),
        host_id << 32U) +
      extract_or(app_config().get<identifier_t>("msg_bus.router.id_minor"), 0U);

    _id_end = _id_base + id_count;

    log_info("using router id range ${base} - ${end} (${count})")
      .arg(EAGINE_ID(count), id_count)
      .arg(EAGINE_ID(base), _id_base)
      .arg(EAGINE_ID(end), _id_end);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto router::_handle_accept() -> bool {
    some_true something_done{};

    if(EAGINE_LIKELY(!_acceptors.empty())) {
        acceptor::accept_handler handler{
          this, EAGINE_MEM_FUNC_C(router, _handle_connection)};
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
auto router::_handle_pending() -> bool {
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
              connection::fetch_handler(handler)));
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

                auto pos = _endpoints.find(id);
                if(pos == _endpoints.end()) {
                    pos = _endpoints.try_emplace(id).first;
                }
                pos->second.the_connection = std::move(pending.the_connection);
                pos->second.maybe_router = maybe_router;
                _pending.erase(_pending.begin() + idx);
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
auto router::_remove_timeouted() -> bool {
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
    return something_done;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto router::_remove_disconnected() -> bool {
    some_true something_done{};

    for(auto& p : _endpoints) {
        auto& rep = std::get<1>(p);
        auto& conn = rep.the_connection;
        if(EAGINE_UNLIKELY(rep.do_disconnect)) {
            conn.reset();
        } else {
            if(EAGINE_UNLIKELY(!conn->is_usable())) {
                log_debug("removing disconnected connection");
                conn.reset();
            }
        }
    }
    something_done(_endpoints.erase_if([](auto& p) {
        return !p.second.the_connection;
    }) > 0);
    return something_done;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void router::_assign_id(std::unique_ptr<connection>& conn) {
    EAGINE_ASSERT(conn);
    // find a currently unused endpoint id value
    identifier_t id_sequence = _id_base + 1;
    while(_endpoints.find(id_sequence) != _endpoints.end()) {
        if(++id_sequence >= _id_end) {
            return;
        }
    }
    //
    log_debug("assigning id ${id} to accepted ${type} connection")
      .arg(EAGINE_ID(type), conn->type_id())
      .arg(EAGINE_ID(id), id_sequence);
    // send the special message assigning the endpoint id
    message_view msg{};
    msg.set_target_id(id_sequence);
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
auto router::_cleanup_blobs() -> bool {
    return _blobs.cleanup();
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto router::_process_blobs() -> bool {
    some_true something_done{};

    if(_blobs.has_outgoing()) {
        for(auto& ep : _endpoints) {
            const auto endpoint_id = std::get<0>(ep);
            const auto& conn = std::get<1>(ep).the_connection;
            if(EAGINE_LIKELY(conn && conn->is_usable())) {
                if(auto opt_max_size{conn->max_data_size()}) {
                    auto handle_send = [endpoint_id, &conn](
                                         message_id msg_id,
                                         const message_view& message) {
                        if(endpoint_id == message.target_id) {
                            return conn->send(msg_id, message);
                        }
                        return false;
                    };
                    if(_blobs.process_outgoing(
                         blob_manipulator::send_handler{handle_send},
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
auto router::_do_allow_blob(message_id msg_id) -> bool {
    if(is_special_message(msg_id)) {
        if(msg_id.has_method(EAGINE_ID(eptCertPem))) {
            return true;
        }
    }
    return false;
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
              .arg(EAGINE_ID(pem), message.data);
            auto pos = _endpoints.find(message.source_id);
            if(pos != _endpoints.end()) {
                if(_context->add_remote_certificate_pem(
                     message.source_id, message.data)) {
                    log_debug("verified and stored endpoint certificate")
                      .arg(EAGINE_ID(source), message.source_id);
                }
            }
            if(message.target_id) {
                post_blob(
                  EAGINE_MSGBUS_ID(eptCertPem),
                  message.source_id,
                  message.target_id,
                  message.data,
                  std::chrono::seconds(30),
                  message_priority::high);
            }
        }
    }
    return true;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto router::_handle_special(
  message_id msg_id,
  identifier_t incoming_id,
  routed_endpoint& endpoint,
  const message_view& message) -> bool {
    if(EAGINE_UNLIKELY(is_special_message(msg_id))) {
        log_debug("router handling special message ${message}")
          .arg(EAGINE_ID(router), _id_base)
          .arg(EAGINE_ID(message), msg_id)
          .arg(EAGINE_ID(target), message.target_id)
          .arg(EAGINE_ID(source), message.source_id);

        if(msg_id.has_method(EAGINE_ID(notARouter))) {
            if(incoming_id == message.source_id) {
                endpoint.maybe_router = false;
                log_debug("endpoint ${source} is not a router")
                  .arg(EAGINE_ID(source), message.source_id);
            }
            return true;
        } else if(msg_id.has_method(EAGINE_ID(clrBlkList))) {
            log_debug("clearing router block_list");
            endpoint.message_block_list.clear();
            return true;
        } else if(msg_id.has_method(EAGINE_ID(clrAlwList))) {
            log_debug("clearing router allow_list");
            endpoint.message_allow_list.clear();
            return true;
        } else if(msg_id.has_method(EAGINE_ID(msgBlkList))) {
            message_id blk_msg_id{};
            if(default_deserialize_message_type(blk_msg_id, message.data)) {
                if(!is_special_message(msg_id)) {
                    log_debug("endpoint ${source} blocking message ${message}")
                      .arg(EAGINE_ID(message), blk_msg_id)
                      .arg(EAGINE_ID(source), message.source_id);
                    endpoint.block_message(blk_msg_id);
                    return true;
                }
            }
        } else if(msg_id.has_method(EAGINE_ID(msgAlwList))) {
            message_id alw_msg_id{};
            if(default_deserialize_message_type(alw_msg_id, message.data)) {
                log_debug("endpoint ${source} allowing message ${message}")
                  .arg(EAGINE_ID(message), alw_msg_id)
                  .arg(EAGINE_ID(source), message.source_id);
                endpoint.allow_message(alw_msg_id);
                return true;
            }
        } else if(msg_id.has_method(EAGINE_ID(byeBye))) {
            log_debug("received bye-bye from endpoint ${source}")
              .arg(EAGINE_ID(source), message.source_id);
            endpoint.do_disconnect = true;
            return true;
        } else if(msg_id.has_method(EAGINE_ID(subscribTo))) {
            message_id sub_msg_id{};
            if(default_deserialize_message_type(sub_msg_id, message.data)) {
                log_debug("endpoint ${source} subscribes to ${message}")
                  .arg(EAGINE_ID(source), message.source_id)
                  .arg(EAGINE_ID(message), sub_msg_id);
                // this should be routed
                return false;
            }
        } else if(msg_id.has_method(EAGINE_ID(unsubFrom))) {
            message_id sub_msg_id{};
            if(default_deserialize_message_type(sub_msg_id, message.data)) {
                log_debug("endpoint ${source} unsubscribes from ${message}")
                  .arg(EAGINE_ID(source), message.source_id)
                  .arg(EAGINE_ID(message), sub_msg_id);
                // this should be routed
                return false;
            }
        } else if(msg_id.has_method(EAGINE_ID(qrySubscrb))) {
            // this should be routed
            return false;
        } else if(msg_id.has_method(EAGINE_ID(blobFrgmnt))) {
            if(_blobs.process_incoming(
                 blob_manipulator::filter_function(
                   this, EAGINE_MEM_FUNC_C(router, _do_allow_blob)),
                 message)) {
                _blobs.fetch_all(blob_manipulator::fetch_handler(
                  this, EAGINE_MEM_FUNC_C(router, _handle_blob)));
            }
            // this should be routed
            return false;
        } else if(msg_id.has_method(EAGINE_ID(rtrCertQry))) {
            post_blob(
              EAGINE_MSGBUS_ID(rtrCertPem),
              0U,
              incoming_id,
              _context->get_own_certificate_pem(),
              std::chrono::seconds(30),
              message_priority::high);
            return true;
        } else if(msg_id.has_method(EAGINE_ID(eptCertQry))) {
            if(auto cert_pem{
                 _context->get_remote_certificate_pem(message.target_id)}) {
                post_blob(
                  EAGINE_MSGBUS_ID(eptCertPem),
                  message.target_id,
                  incoming_id,
                  cert_pem,
                  std::chrono::seconds(30),
                  message_priority::high);
                return true;
            }
            return false;
        } else if(msg_id.has_method(EAGINE_ID(requestId))) {
            return true;
        } else if(msg_id.has_method(EAGINE_ID(topoQuery))) {
            std::array<byte, 256> temp{};
            router_topology_info info{};
            for(auto& [ep_id, ep] : this->_endpoints) {
                info.router_id = _id_base;
                info.remote_id = ep_id;
                if(auto serialized{default_serialize(info, cover(temp))}) {
                    message_view response{extract(serialized)};
                    response.setup_response(message);
                    response.set_source_id(_id_base);
                    this->_do_route_message(
                      EAGINE_MSGBUS_ID(topoRutrCn), _id_base, response);
                }
            }
            return false;
        } else if(
          msg_id.has_method(EAGINE_ID(topoRutrCn)) ||
          msg_id.has_method(EAGINE_ID(topoBrdgCn)) ||
          msg_id.has_method(EAGINE_ID(topoEndpt))) {
            // this should be forwarded
            return false;
        } else if(msg_id.has_method(EAGINE_ID(annEndptId))) {
            return true;
        }
        log_warning("unhandled special message ${message} from ${source}")
          .arg(EAGINE_ID(message), msg_id)
          .arg(EAGINE_ID(source), message.source_id)
          .arg(EAGINE_ID(data), message.data);
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto router::_do_route_message(
  message_id msg_id,
  identifier_t incoming_id,
  message_view message) -> bool {

    bool result = true;
    if(EAGINE_UNLIKELY(message.too_many_hops())) {
        log_warning("message ${message} discarded after too many hops")
          .arg(EAGINE_ID(message), msg_id);
    } else {
        const auto& epts = this->_endpoints;
        message.add_hop();
        const bool is_targeted = (message.target_id != broadcast_endpoint_id());

        const auto forward_to = [&](auto& endpoint_out) {
            if(EAGINE_UNLIKELY(++_forwarded_messages % 100000 == 0)) {
                const auto now{std::chrono::steady_clock::now()};
                const std::chrono::duration<float> interval{
                  now - _forwarded_since};

                if(EAGINE_LIKELY(interval > decltype(interval)::zero())) {
                    const auto msgs_per_sec{100000.F / interval.count()};

                    log_chart_sample(EAGINE_ID(msgsPerSec), msgs_per_sec);
                    log_stat("forwarded ${count} messages")
                      .arg(EAGINE_ID(count), _forwarded_messages)
                      .arg(EAGINE_ID(interval), interval)
                      .arg(EAGINE_ID(msgsPerSec), msgs_per_sec);
                }

                _forwarded_since = now;
            }
            return endpoint_out.send(*this, msg_id, message);
        };

        if(is_targeted) {
            bool has_routed = false;
            for(const auto& [outgoing_id, endpoint_out] : epts) {
                if(outgoing_id == message.target_id) {
                    if(endpoint_out.is_allowed(msg_id)) {
                        has_routed = forward_to(endpoint_out);
                    }
                }
            }
            if(!has_routed) {
                for(const auto& [outgoing_id, endpoint_out] : epts) {
                    if(endpoint_out.maybe_router) {
                        if(incoming_id != outgoing_id) {
                            has_routed |= forward_to(endpoint_out);
                        }
                    }
                }
                // if the message didn't come from the parent router
                if(incoming_id != _id_base) {
                    has_routed |= _parent_router.send(*this, msg_id, message);
                }
            }
            result &= has_routed;
        } else {
            for(const auto& [outgoing_id, endpoint_out] : epts) {
                if(incoming_id != outgoing_id) {
                    if(endpoint_out.is_allowed(msg_id)) {
                        result |= forward_to(endpoint_out);
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
auto router::_route_messages() -> bool {
    some_true something_done{};

    for(auto& ep : _endpoints) {
        auto handler = [this, &ep](
                         message_id msg_id,
                         message_age msg_age,
                         const message_view& message) {
            auto& [incoming_id, endpoint_in] = ep;
            if(this->_handle_special(
                 msg_id, incoming_id, endpoint_in, message)) {
                return true;
            }
            if(EAGINE_LIKELY(msg_age < std::chrono::seconds(30))) {
                return this->_do_route_message(msg_id, incoming_id, message);
            }
            return true;
        };

        const auto& conn_in = std::get<1>(ep).the_connection;
        if(EAGINE_LIKELY(conn_in && conn_in->is_usable())) {
            something_done(
              conn_in->fetch_messages(connection::fetch_handler(handler)));
        }
    }

    auto handler =
      [&](message_id msg_id, message_age msg_age, const message_view& message) {
          if(EAGINE_LIKELY(msg_age < std::chrono::seconds(30))) {
              return this->_do_route_message(msg_id, _id_base, message);
          }
          return true;
      };
    something_done(_parent_router.fetch_messages(*this, handler));

    return something_done;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto router::_update_connections() -> bool {
    some_true something_done{};

    for(auto& [id, endpoint] : _endpoints) {
        EAGINE_MAYBE_UNUSED(id);
        const auto& conn = endpoint.the_connection;
        if(EAGINE_LIKELY(conn)) {
            something_done(conn->update());
        }
    }

    something_done(_parent_router.update(*this, _id_base));

    if(_endpoints.empty() && _pending.empty()) {
        std::this_thread::yield();
    } else {
        _no_connection_timeout.reset();
    }
    return something_done;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto router::do_maintenance() -> bool {
    some_true something_done{};

    something_done(_cleanup_blobs());
    something_done(_process_blobs());
    something_done(_remove_timeouted());
    something_done(_remove_disconnected());

    return something_done;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto router::do_work() -> bool {
    some_true something_done{};

    something_done(_handle_pending());
    something_done(_handle_accept());
    something_done(_route_messages());
    something_done(_update_connections());

    return something_done;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto router::update(const valid_if_positive<int>& count) -> bool {
    some_true something_done{};

    something_done(do_maintenance());

    int n = extract_or(count, 2);
    do {
        something_done(do_work());
    } while((n-- > 0) && something_done);

    return something_done;
}
//------------------------------------------------------------------------------
} // namespace eagine::msgbus
