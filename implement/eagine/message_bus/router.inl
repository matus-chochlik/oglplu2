/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/bool_aggregate.hpp>
#include <eagine/branch_predict.hpp>
#include <eagine/message_bus/context.hpp>
#include <eagine/message_bus/serialize.hpp>
#include <thread>

namespace eagine::msgbus {
//------------------------------------------------------------------------------
// routed_endpoint
//------------------------------------------------------------------------------
static inline bool routed_endpoint_list_contains(
  const std::vector<message_id>& list,
  const message_id& entry) noexcept {
    return std::find(list.begin(), list.end(), entry) != list.end();
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
routed_endpoint::routed_endpoint() {
    message_block_list.reserve(8);
    message_allow_list.reserve(8);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool routed_endpoint::is_allowed(message_id msg_id) const noexcept {
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
bool router::add_acceptor(std::unique_ptr<acceptor> an_acceptor) {
    if(an_acceptor) {
        _log.info("adding connection acceptor");
        _acceptors.emplace_back(std::move(an_acceptor));
        return true;
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool router::add_connection(std::unique_ptr<connection> a_connection) {
    if(a_connection) {
        _log.info("adding connection");
        _connectors.emplace_back(std::move(a_connection));
        return true;
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void router::_setup_from_args(const program_args& args) {
    if(auto arg = args.find("--msg-bus-router-id-base")) {
        if(arg.next().parse(_id_base, _log.error_stream())) {
            _id_sequence = _id_base;
            _log.debug("parsed router id base ${base}")
              .arg(EAGINE_ID(base), _id_base);
        }
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool router::_handle_accept() {
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
bool router::_handle_pending() {
    some_true something_done{};

    if(!_pending.empty()) {
        identifier_t id = 0;
        auto handler =
          [this, &id](message_id msg_id, message_age, const message_view& msg) {
              // this is a special message requesting endpoint id assignment
              if(msg_id == EAGINE_MSGBUS_ID(requestId)) {
                  id = ~id;
                  return true;
              }
              // this is a special message containing endpoint id
              if(msg_id == EAGINE_MSGBUS_ID(announceId)) {
                  id = msg.source_id;
                  this->_log.debug("received endpoint id ${id}")
                    .arg(EAGINE_ID(id), id);
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
                _log.debug("adopting pending connection from endpoint ${id}")
                  .arg(EAGINE_ID(type), pending.the_connection->type_id())
                  .arg(EAGINE_ID(id), id);
                auto pos = _endpoints.find(id);
                if(pos == _endpoints.end()) {
                    pos = _endpoints.try_emplace(id).first;
                }
                pos->second.connections.emplace_back(
                  std::move(pending.the_connection));
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
bool router::_remove_timeouted() {
    some_true something_done{};

    _pending.erase(
      std::remove_if(
        _pending.begin(),
        _pending.end(),
        [this, &something_done](auto& pending) {
            if(pending.age() > this->_pending_timeout) {
                something_done();
                this->_log
                  .warning("removing timeouted pending ${type} connection")
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
bool router::_remove_disconnected() {
    some_true something_done{};

    for(auto& p : _endpoints) {
        auto& rep = std::get<1>(p);
        auto& conns = rep.connections;
        if(EAGINE_UNLIKELY(rep.do_disconnect)) {
            conns.clear();
        } else {
            conns.erase(
              std::remove_if(
                conns.begin(),
                conns.end(),
                [this](auto& conn) {
                    if(!conn || !conn->is_usable()) {
                        this->_log.debug("removing disconnected connection");
                        return true;
                    }
                    return false;
                }),
              conns.end());
        }
    }
    something_done(_endpoints.erase_if([](auto& p) {
        return p.second.connections.empty();
    }) > 0);
    return something_done;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void router::_assign_id(std::unique_ptr<connection>& conn) {
    EAGINE_ASSERT(conn);
    // find a currently unused endpoint id value
    ++_id_sequence;
    while(!_id_sequence ||
          (_endpoints.find(_id_sequence) != _endpoints.end())) {
        ++_id_sequence;
    }
    //
    _log.debug("assigning id ${id} to accepted ${type} connection")
      .arg(EAGINE_ID(type), conn->type_id())
      .arg(EAGINE_ID(id), _id_sequence);
    // send the special message assigning the endpoint id
    message_view msg{};
    msg.set_target_id(_id_sequence);
    conn->send(EAGINE_MSGBUS_ID(assignId), msg);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void router::_handle_connection(std::unique_ptr<connection> conn) {
    EAGINE_ASSERT(conn);
    _pending.emplace_back(std::move(conn));
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool router::_cleanup_blobs() {
    return _blobs.cleanup();
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool router::_process_blobs() {
    some_true something_done{};

    if(_blobs.has_outgoing()) {
        for(auto& ep : _endpoints) {
            const auto endpoint_id = std::get<0>(ep);
            for(auto& conn : std::get<1>(ep).connections) {
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
                            break;
                        }
                    }
                }
            }
        }
    }
    return something_done;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool router::_do_allow_blob(message_id msg_id) {
    if(is_special_message(msg_id)) {
        if(msg_id.has_method(EAGINE_ID(eptCertPem))) {
            return true;
        }
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool router::_handle_blob(
  message_id msg_id,
  message_age,
  const message_view& message) {
    // TODO: use message age
    if(is_special_message(msg_id)) {
        if(msg_id.has_method(EAGINE_ID(eptCertPem))) {
            _log.trace("received endpoint certificate")
              .arg(EAGINE_ID(source), message.source_id)
              .arg(EAGINE_ID(pem), message.data);
            auto pos = _endpoints.find(message.source_id);
            if(pos != _endpoints.end()) {
                if(_context->add_remote_certificate_pem(
                     message.source_id, message.data)) {
                    _log.debug("verified and stored endpoint certificate")
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
bool router::_handle_special(
  message_id msg_id,
  identifier_t incoming_id,
  routed_endpoint& endpoint,
  const message_view& message) {
    if(EAGINE_UNLIKELY(is_special_message(msg_id))) {
        _log.debug("router handling special message ${message}")
          .arg(EAGINE_ID(message), msg_id)
          .arg(EAGINE_ID(target), message.target_id)
          .arg(EAGINE_ID(source), message.source_id);

        if(msg_id.has_method(EAGINE_ID(notARouter))) {
            if(incoming_id == message.source_id) {
                endpoint.maybe_router = false;
                _log.debug("endpoint ${source} is not a router")
                  .arg(EAGINE_ID(source), message.source_id);
                return true;
            }
        } else if(msg_id.has_method(EAGINE_ID(clrBlkList))) {
            _log.debug("clearing router block_list");
            endpoint.message_block_list.clear();
            return true;
        } else if(msg_id.has_method(EAGINE_ID(clrAlwList))) {
            _log.debug("clearing router allow_list");
            endpoint.message_allow_list.clear();
            return true;
        } else if(msg_id.has_method(EAGINE_ID(msgBlkList))) {
            message_id blk_msg_id{};
            if(default_deserialize_message_type(blk_msg_id, message.data)) {
                if(!is_special_message(msg_id)) {
                    _log.debug("endpoint ${source} blocking message ${message}")
                      .arg(EAGINE_ID(message), blk_msg_id)
                      .arg(EAGINE_ID(source), message.source_id);
                    endpoint.block_message(blk_msg_id);
                    return true;
                }
            }
        } else if(msg_id.has_method(EAGINE_ID(msgAlwList))) {
            message_id alw_msg_id{};
            if(default_deserialize_message_type(alw_msg_id, message.data)) {
                _log.debug("endpoint ${source} allowing message ${message}")
                  .arg(EAGINE_ID(message), alw_msg_id)
                  .arg(EAGINE_ID(source), message.source_id);
                endpoint.allow_message(alw_msg_id);
                return true;
            }
        } else if(msg_id.has_method(EAGINE_ID(byeBye))) {
            _log.debug("received bye-bye from endpoint ${source}")
              .arg(EAGINE_ID(source), message.source_id);
            endpoint.do_disconnect = true;
            return true;
        } else if(msg_id.has_method(EAGINE_ID(subscribTo))) {
            message_id sub_msg_id{};
            if(default_deserialize_message_type(sub_msg_id, message.data)) {
                _log.debug("endpoint ${source} subscribes to ${message}")
                  .arg(EAGINE_ID(source), message.source_id)
                  .arg(EAGINE_ID(message), sub_msg_id);
                // this should be routed
                return false;
            }
        } else if(msg_id.has_method(EAGINE_ID(unsubFrom))) {
            message_id sub_msg_id{};
            if(default_deserialize_message_type(sub_msg_id, message.data)) {
                _log.debug("endpoint ${source} unsubscribes from ${message}")
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
                    response.set_target_id(incoming_id);
                    for(auto& conn_out : endpoint.connections) {
                        if(EAGINE_LIKELY(conn_out && conn_out->is_usable())) {
                            if(conn_out->send(
                                 EAGINE_MSGBUS_ID(topoRoutCn), response)) {
                                break;
                            }
                        }
                    }
                }
            }
            return false;
        } else if(
          msg_id.has_method(EAGINE_ID(topoRoutCn)) ||
          msg_id.has_method(EAGINE_ID(topoBrdgCn)) ||
          msg_id.has_method(EAGINE_ID(topoEndpt))) {
            // this should be forwarded
            return false;
        }
        _log.warning("unhandled special message ${message} from ${source}")
          .arg(EAGINE_ID(message), msg_id)
          .arg(EAGINE_ID(source), message.source_id)
          .arg(EAGINE_ID(data), message.data);
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool router::_do_route_message(
  message_id msg_id,
  identifier_t incoming_id,
  message_view message) {
    if(EAGINE_UNLIKELY(message.too_many_hops())) {
        _log.warning("message ${message} discarded after too many hops")
          .arg(EAGINE_ID(message), msg_id);
    } else {
        message.add_hop();
        for(auto& [outgoing_id, endpoint_out] : this->_endpoints) {
            bool should_forward = (incoming_id != outgoing_id);
            should_forward &=
              (endpoint_out.maybe_router ||
               (outgoing_id == message.target_id) || !message.target_id);
            should_forward &= endpoint_out.is_allowed(msg_id);
            if(should_forward) {
                if(EAGINE_UNLIKELY(++_forwarded_messages % 100000 == 0)) {
                    _log.stat("forwarded ${count} messages")
                      .arg(EAGINE_ID(count), _forwarded_messages);
                }
                for(auto& conn_out : endpoint_out.connections) {
                    if(EAGINE_LIKELY(conn_out && conn_out->is_usable())) {
                        if(conn_out->send(msg_id, message)) {
                            return true;
                        }
                    } else {
                        _log.debug("missing or unusable connection");
                    }
                }
                return false;
            }
        }
    }
    return true;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool router::_route_messages() {
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

        for(auto& conn_in : std::get<1>(ep).connections) {
            if(EAGINE_LIKELY(conn_in && conn_in->is_usable())) {
                something_done(
                  conn_in->fetch_messages(connection::fetch_handler(handler)));
            }
        }
    }
    return something_done;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool router::_update_connections() {
    some_true something_done{};

    for(auto& [id, endpoint] : _endpoints) {
        EAGINE_MAYBE_UNUSED(id);
        for(auto& conn : endpoint.connections) {
            if(EAGINE_LIKELY(conn)) {
                something_done(conn->update());
            }
        }
    }
    if(_endpoints.empty() && _pending.empty()) {
        std::this_thread::yield();
    } else {
        _no_connection_timeout.reset();
    }
    return something_done;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool router::update(const valid_if_positive<int>& count) {
    some_true something_done{};

    something_done(_cleanup_blobs());
    something_done(_process_blobs());

    something_done(_remove_timeouted());
    something_done(_remove_disconnected());

    int n = extract_or(count, 2);
    do {
        something_done(_handle_pending());
        something_done(_handle_accept());
        something_done(_route_messages());
        something_done(_update_connections());
    } while((n-- > 0) && something_done);
    return something_done;
}
//------------------------------------------------------------------------------
} // namespace eagine::msgbus
