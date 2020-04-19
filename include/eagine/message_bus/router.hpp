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

#include "../branch_predict.hpp"
#include "../logging/logger.hpp"
#include "../program_args.hpp"
#include "../timeout.hpp"
#include "acceptor.hpp"
#include "serialize.hpp"
#include <map>
#include <set>
#include <thread>
#include <vector>

namespace eagine {
namespace msgbus {
//------------------------------------------------------------------------------
struct router_pending {

    router_pending(std::unique_ptr<connection> a_connection)
      : the_connection{std::move(a_connection)} {
    }

    std::chrono::steady_clock::time_point create_time{
      std::chrono::steady_clock::now()};

    std::unique_ptr<connection> the_connection;

    auto age() const {
        return std::chrono::steady_clock::now() - create_time;
    }
};
//------------------------------------------------------------------------------
struct routed_endpoint {
    std::vector<std::unique_ptr<connection>> connections;
    std::set<std::tuple<identifier_t, identifier_t>> message_blacklist;
    bool maybe_router{true};
    bool do_disconnect{false};

    bool is_blacklisted(identifier_t class_id, identifier_t method_id) {
        return message_blacklist.find(std::make_tuple(class_id, method_id)) !=
               message_blacklist.end();
    }
};
//------------------------------------------------------------------------------
class router : public acceptor_user {
public:
    router() noexcept = default;

    router(logger& parent) noexcept
      : _log(EAGINE_ID(MsgBusRutr), parent) {
    }

    router(logger& parent, const program_args& args) noexcept
      : _log(EAGINE_ID(MsgBusRutr), parent) {
        _setup_from_args(args);
    }

    bool add_acceptor(std::unique_ptr<acceptor> an_acceptor) final {
        if(an_acceptor) {
            _log.info("adding connection acceptor");
            _acceptors.emplace_back(std::move(an_acceptor));
            return true;
        }
        return false;
    }

    void update() {
        _remove_timeouted();
        _remove_disconnected();
        _handle_pending();
        _handle_accept();
        _route_messages();
        _update_connections();
    }

    auto& no_connection_timeout() const noexcept {
        return _no_connection_timeout;
    }

    bool is_done() const noexcept {
        return bool(no_connection_timeout());
    }

private:
    void _setup_from_args(const program_args&) {
        // TODO
    }

    void _handle_accept() {
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

    void _handle_pending() {

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

    void _remove_timeouted() {
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

    void _remove_disconnected() {
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
                            this->_log.debug(
                              "removing disconnected connection");
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

    void _handle_connection(std::unique_ptr<connection> conn) {
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

    bool _handle_special(
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

    bool _do_route_message(
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
                should_forward &=
                  !endpoint_out.is_blacklisted(class_id, method_id);
                if(should_forward) {
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

    void _route_messages() {
        for(auto& [incoming_id, endpoint_in] : _endpoints) {
            auto handler = [this, incoming_id, &endpoint_in](
                             identifier_t class_id,
                             identifier_t method_id,
                             const message_view& message) {
                if(this->_handle_special(
                     class_id, method_id, incoming_id, endpoint_in, message)) {
                    return true;
                }
                return this->_do_route_message(
                  class_id, method_id, incoming_id, message);
            };

            for(auto& conn_in : endpoint_in.connections) {
                if(EAGINE_LIKELY(conn_in && conn_in->is_usable())) {
                    conn_in->fetch_messages(connection::fetch_handler(handler));
                }
            }
        }
    }

    void _update_connections() {
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

    logger _log{};
    const std::chrono::seconds _pending_timeout{30};
    timeout _no_connection_timeout{std::chrono::seconds{30}};
    identifier_t _id_sequence{0};
    std::vector<std::unique_ptr<acceptor>> _acceptors;
    std::vector<router_pending> _pending;
    std::map<identifier_t, routed_endpoint> _endpoints;
};
//------------------------------------------------------------------------------
} // namespace msgbus
} // namespace eagine

#endif // EAGINE_MESSAGE_BUS_ROUTER_HPP

