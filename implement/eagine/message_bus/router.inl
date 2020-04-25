/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/branch_predict.hpp>
#include <eagine/message_bus/serialize.hpp>
#include <thread>

namespace eagine {
namespace msgbus {
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
void router::_setup_from_args(const program_args&) {
    // TODO
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void router::_handle_accept() {
    if(EAGINE_LIKELY(!_acceptors.empty())) {
        acceptor::accept_handler handler{
          this, EAGINE_MEM_FUNC_C(router, _handle_connection)};
        for(auto& an_acceptor : _acceptors) {
            EAGINE_ASSERT(an_acceptor);
            an_acceptor->update();
            an_acceptor->process_accepted(handler);
        }
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void router::_handle_pending() {

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
            pending.the_connection->update();
            pending.the_connection->fetch_messages(
              connection::fetch_handler(handler));
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
            } else {
                ++pos;
            }
        }
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void router::_remove_timeouted() {
    _pending.erase(
      std::remove_if(
        _pending.begin(),
        _pending.end(),
        [this](auto& pending) {
            if(pending.age() > this->_pending_timeout) {
                this->_log
                  .warning("removing timeouted pending ${type} connection")
                  .arg(EAGINE_ID(type), pending.the_connection->type_id())
                  .arg(EAGINE_ID(age), pending.age());
                return true;
            }
            return false;
        }),
      _pending.end());
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void router::_remove_disconnected() {
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
        } else {
            ++it;
        }
    }
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
bool router::_handle_special(
  identifier_t class_id,
  identifier_t method_id,
  identifier_t incoming_id,
  routed_endpoint& endpoint,
  const message_view& message) {
    const auto emb_id = EAGINE_ID(eagiMsgBus);
    if(EAGINE_UNLIKELY(emb_id.matches(class_id))) {
        if(EAGINE_ID(notARouter).matches(method_id)) {
            if(incoming_id == message.source_id) {
                endpoint.maybe_router = false;
                _log.debug("endpoint ${source} is not a router")
                  .arg(EAGINE_ID(source), message.source_id);
                return true;
            }
        } else if(EAGINE_ID(clrBlkList).matches(method_id)) {
            _log.debug("clearing router blacklist");
            endpoint.message_blacklist.clear();
            return true;
        } else if(EAGINE_ID(msgBlkList).matches(method_id)) {
            identifier_t blk_class_id{0};
            identifier_t blk_method_id{0};
            auto blk_msg_id = std::tie(blk_class_id, blk_method_id);
            if(default_deserialize(blk_msg_id, message.data)) {
                // messages with eagiMsgBus class cannot be blacklisted
                if(!emb_id.matches(blk_class_id)) {
                    _log
                      .debug(
                        "blacklisting message ${message} from "
                        "endpoint ${source}")
                      .arg(
                        EAGINE_ID(message),
                        message_id_tuple(class_id, method_id))
                      .arg(EAGINE_ID(source), message.source_id);
                    endpoint.message_blacklist.insert(blk_msg_id);
                }
            }
            return true;
        } else if(EAGINE_ID(byeBye).matches(method_id)) {
            _log.debug("received bye-bye from endpoint ${source}")
              .arg(EAGINE_ID(source), message.source_id);
            endpoint.do_disconnect = true;
            return true;
        }
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
    if(!message.too_many_hops()) {
        message.add_hop();
        for(auto& [outgoing_id, endpoint_out] : this->_endpoints) {
            bool should_forward = (incoming_id != outgoing_id);
            should_forward &=
              (endpoint_out.maybe_router ||
               (outgoing_id == message.target_id) || !message.target_id);
            should_forward &= !endpoint_out.is_blacklisted(class_id, method_id);
            if(should_forward) {
                if(EAGINE_UNLIKELY(++_forwarded_messages % 100000 == 0)) {
                    _log.info("forwarded ${count} messages")
                      .arg(EAGINE_ID(count), _forwarded_messages);
                }
                for(auto& conn_out : endpoint_out.connections) {
                    if(EAGINE_LIKELY(conn_out && conn_out->is_usable())) {
                        if(conn_out->send(class_id, method_id, message)) {
                            break;
                        }
                    }
                }
            }
        }
    } else {
        _log.warning("message ${message} discarded after too many hops")
          .arg(EAGINE_ID(message), message_id_tuple(class_id, method_id));
    }
    return true;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void router::_route_messages() {
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
                conn_in->fetch_messages(connection::fetch_handler(handler));
            }
        }
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void router::_update_connections() {
    for(auto& [id, endpoint] : _endpoints) {
        EAGINE_MAYBE_UNUSED(id);
        for(auto& conn : endpoint.connections) {
            if(EAGINE_LIKELY(conn)) {
                conn->update();
            }
        }
    }
    if(_endpoints.empty() && _pending.empty()) {
        std::this_thread::yield();
    } else {
        _no_connection_timeout.reset();
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void router::update(const valid_if_positive<int>& count) {
    _remove_timeouted();
    _remove_disconnected();

    int n = extract_or(count, 2);
    while(n-- > 0) {
        _handle_pending();
        _handle_accept();
        _route_messages();
        _update_connections();
    }
}
//------------------------------------------------------------------------------
} // namespace msgbus
} // namespace eagine

