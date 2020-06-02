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

namespace eagine {
namespace msgbus {
//------------------------------------------------------------------------------
// routed_endpoint
//------------------------------------------------------------------------------
static inline bool routed_endpoint_list_contains(
  const std::vector<message_id_tuple>& list,
  const message_id_tuple& entry) noexcept {
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
bool routed_endpoint::is_allowed(
  identifier_t class_id, identifier_t method_id) const noexcept {
    if(EAGINE_UNLIKELY(EAGINE_ID(eagiMsgBus).matches(class_id))) {
        return true;
    }
    const message_id_tuple entry{class_id, method_id};
    if(!message_allow_list.empty()) {
        return routed_endpoint_list_contains(message_allow_list, entry);
    }
    if(!message_block_list.empty()) {
        return !routed_endpoint_list_contains(message_block_list, entry);
    }
    return true;
}
//------------------------------------------------------------------------------
void routed_endpoint::block_message(
  identifier_t class_id, identifier_t method_id) {
    const message_id_tuple entry{class_id, method_id};
    if(!routed_endpoint_list_contains(message_block_list, entry)) {
        message_block_list.push_back(entry);
    }
}
//------------------------------------------------------------------------------
void routed_endpoint::allow_message(
  identifier_t class_id, identifier_t method_id) {
    const message_id_tuple entry{class_id, method_id};
    if(!routed_endpoint_list_contains(message_allow_list, entry)) {
        message_allow_list.push_back(entry);
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
        if(arg.next().parse(_id_sequence, _log.error_stream())) {
            _log.debug("parsed router id base ${base}")
              .arg(EAGINE_ID(base), _id_sequence);
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
        auto handler = [this, &id](
                         identifier_t class_id,
                         identifier_t method_id,
                         const message_view& msg) {
            // this is a special message containing endpoint id
            if(EAGINE_MSG_ID(eagiMsgBus, announceId)
                 .matches(class_id, method_id)) {
                id = msg.source_id;
                this->_log.debug("received endpoint id ${id}")
                  .arg(EAGINE_ID(id), id);
                return true;
            }
            return false;
        };

        std::size_t pos = 0;
        while(pos < _pending.size()) {
            id = 0;
            auto& pending = _pending[pos];
            something_done(pending.the_connection->update());
            something_done(pending.the_connection->fetch_messages(
              connection::fetch_handler(handler)));
            // if we got the endpoint id message from the connection
            if(id != 0) {
                _log
                  .debug(
                    "adopting pending ${type} connection from endpoint "
                    "${id}")
                  .arg(EAGINE_ID(type), pending.the_connection->type_id())
                  .arg(EAGINE_ID(id), id);
                _endpoints[id].connections.emplace_back(
                  std::move(pending.the_connection));
                _pending.erase(_pending.begin() + pos);
                something_done();
            } else {
                ++pos;
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
    auto it = _endpoints.begin();
    while(it != _endpoints.end()) {
        if(it->second.connections.empty()) {
            _endpoints.erase(it++);
            something_done();
        } else {
            ++it;
        }
    }
    return something_done;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void router::_handle_connection(std::unique_ptr<connection> conn) {
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
    conn->send(EAGINE_MSG_ID(eagiMsgBus, assignId), msg);
    conn->update();
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
                                             identifier_t class_id,
                                             identifier_t method_id,
                                             const message_view& message) {
                            if(endpoint_id == message.target_id) {
                                return conn->send(class_id, method_id, message);
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
bool router::_do_allow_blob(message_id_tuple msg_id) {
    if(EAGINE_UNLIKELY(EAGINE_ID(eagiMsgBus).matches(msg_id.class_id()))) {
        if(EAGINE_ID(eptCertPem).matches(msg_id.method_id())) {
            return true;
        }
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool router::_handle_blob(
  identifier_t class_id, identifier_t method_id, const message_view& message) {
    if(EAGINE_UNLIKELY(EAGINE_ID(eagiMsgBus).matches(class_id))) {
        if(EAGINE_ID(eptCertPem).matches(method_id)) {
            _log.trace("received endpoint certificate")
              .arg(EAGINE_ID(source), message.source_id)
              .arg(EAGINE_ID(pem), message.data);
            // TODO: store/verify endpoint cert
        }
    }
    return true;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool router::_handle_special(
  identifier_t class_id,
  identifier_t method_id,
  identifier_t incoming_id,
  routed_endpoint& endpoint,
  const message_view& message) {
    const auto emb_id = EAGINE_ID(eagiMsgBus);
    if(EAGINE_UNLIKELY(emb_id.matches(class_id))) {
        _log.debug("handling special message ${message}")
          .arg(EAGINE_ID(message), message_id_tuple(class_id, method_id))
          .arg(EAGINE_ID(source), message.source_id);

        if(EAGINE_ID(notARouter).matches(method_id)) {
            if(incoming_id == message.source_id) {
                endpoint.maybe_router = false;
                _log.debug("endpoint ${source} is not a router")
                  .arg(EAGINE_ID(source), message.source_id);
                return true;
            }
        } else if(EAGINE_ID(clrBlkList).matches(method_id)) {
            _log.debug("clearing router block_list");
            endpoint.message_block_list.clear();
            return true;
        } else if(EAGINE_ID(clrAlwList).matches(method_id)) {
            _log.debug("clearing router allow_list");
            endpoint.message_allow_list.clear();
            return true;
        } else if(EAGINE_ID(msgBlkList).matches(method_id)) {
            identifier_t blk_class_id{};
            identifier_t blk_method_id{};
            if(default_deserialize_message_type(
                 blk_class_id, blk_method_id, message.data)) {
                if(!emb_id.matches(blk_class_id)) {
                    _log.debug("endpoint ${source} blocking message ${message}")
                      .arg(
                        EAGINE_ID(message),
                        message_id_tuple(blk_class_id, blk_method_id))
                      .arg(EAGINE_ID(source), message.source_id);
                    endpoint.block_message(blk_class_id, blk_method_id);
                    return true;
                }
            }
        } else if(EAGINE_ID(msgAlwList).matches(method_id)) {
            identifier_t alw_class_id{};
            identifier_t alw_method_id{};
            if(default_deserialize_message_type(
                 alw_class_id, alw_method_id, message.data)) {
                _log.debug("endpoint ${source} allowing message ${message}")
                  .arg(
                    EAGINE_ID(message),
                    message_id_tuple(alw_class_id, alw_method_id))
                  .arg(EAGINE_ID(source), message.source_id);
                endpoint.allow_message(alw_class_id, alw_method_id);
                return true;
            }
        } else if(EAGINE_ID(byeBye).matches(method_id)) {
            _log.debug("received bye-bye from endpoint ${source}")
              .arg(EAGINE_ID(source), message.source_id);
            endpoint.do_disconnect = true;
            return true;
        } else if(EAGINE_ID(subscribTo).matches(method_id)) {
            identifier_t sub_class_id{};
            identifier_t sub_method_id{};
            if(default_deserialize_message_type(
                 sub_class_id, sub_method_id, message.data)) {
                _log.debug("endpoint ${source} subscribes to ${message}")
                  .arg(EAGINE_ID(source), message.source_id)
                  .arg(
                    EAGINE_ID(message),
                    message_id_tuple(sub_class_id, sub_method_id));
                // this should be routed
                return false;
            }
        } else if(EAGINE_ID(unsubFrom).matches(method_id)) {
            identifier_t sub_class_id{};
            identifier_t sub_method_id{};
            if(default_deserialize_message_type(
                 sub_class_id, sub_method_id, message.data)) {
                _log.debug("endpoint ${source} unsubscribes from ${message}")
                  .arg(EAGINE_ID(source), message.source_id)
                  .arg(
                    EAGINE_ID(message),
                    message_id_tuple(sub_class_id, sub_method_id));
                // this should be routed
                return false;
            }
        } else if(EAGINE_ID(blobFrgmnt).matches(method_id)) {
            if(_blobs.process_incoming(
                 blob_manipulator::filter_function(
                   this, EAGINE_MEM_FUNC_C(router, _do_allow_blob)),
                 message)) {
                _blobs.fetch_all(blob_manipulator::fetch_handler(
                  this, EAGINE_MEM_FUNC_C(router, _handle_blob)));
            }
            // this should be routed
            return false;
        } else if(EAGINE_ID(rtrCertReq).matches(method_id)) {
            post_blob(
              EAGINE_MSG_ID(eagiMsgBus, rtrCertPem),
              incoming_id,
              _context->get_own_certificate_pem(),
              std::chrono::seconds(30),
              message_priority::high);
            return true;
        } else if(EAGINE_ID(eptCertReq).matches(method_id)) {
            // TODO: try to find and send he certificate here
            // and route only if not found
            return false;
        }
        _log.warning("unhandled special message ${message} from ${source}")
          .arg(EAGINE_ID(message), message_id_tuple(class_id, method_id))
          .arg(EAGINE_ID(source), message.source_id)
          .arg(EAGINE_ID(data), message.data);
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool router::_do_route_message(
  identifier_t class_id,
  identifier_t method_id,
  identifier_t incoming_id,
  message_view message) {
    if(EAGINE_UNLIKELY(message.too_many_hops())) {
        _log.warning("message ${message} discarded after too many hops")
          .arg(EAGINE_ID(message), message_id_tuple(class_id, method_id));
    } else {
        message.add_hop();
        for(auto& [outgoing_id, endpoint_out] : this->_endpoints) {
            bool should_forward = (incoming_id != outgoing_id);
            should_forward &=
              (endpoint_out.maybe_router ||
               (outgoing_id == message.target_id) || !message.target_id);
            should_forward &= endpoint_out.is_allowed(class_id, method_id);
            if(should_forward) {
                if(EAGINE_UNLIKELY(++_forwarded_messages % 100000 == 0)) {
                    _log.stat("forwarded ${count} messages")
                      .arg(EAGINE_ID(count), _forwarded_messages);
                }
                for(auto& conn_out : endpoint_out.connections) {
                    if(EAGINE_LIKELY(conn_out && conn_out->is_usable())) {
                        if(conn_out->send(class_id, method_id, message)) {
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
                         identifier_t class_id,
                         identifier_t method_id,
                         const message_view& message) {
            auto& [incoming_id, endpoint_in] = ep;
            if(this->_handle_special(
                 class_id, method_id, incoming_id, endpoint_in, message)) {
                return true;
            }
            return this->_do_route_message(
              class_id, method_id, incoming_id, message);
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
} // namespace msgbus
} // namespace eagine

