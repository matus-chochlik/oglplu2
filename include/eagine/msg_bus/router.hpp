/**
 *  @file eagine/msg_bus/router.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MSG_BUS_ROUTER_HPP
#define EAGINE_MSG_BUS_ROUTER_HPP

#include "../branch_predict.hpp"
#include "acceptor.hpp"
#include <map>
#include <vector>

namespace eagine {
//------------------------------------------------------------------------------
struct message_bus_router_pending {

    message_bus_router_pending(std::unique_ptr<message_bus_connection> conn)
      : connection{std::move(conn)} {
    }

    std::chrono::steady_clock::time_point create_time{
      std::chrono::steady_clock::now()};
    std::unique_ptr<message_bus_connection> connection;

    auto age() const {
        return std::chrono::steady_clock::now() - create_time;
    }
};
//------------------------------------------------------------------------------
struct message_bus_routed_endpoint {
    std::vector<std::unique_ptr<message_bus_connection>> connections;
    bool maybe_router{true};
};
//------------------------------------------------------------------------------
class message_bus_router {
public:
    bool add_acceptor(std::unique_ptr<message_bus_acceptor> acceptor) {
        if(acceptor) {
            _acceptors.emplace_back(std::move(acceptor));
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

private:
    void _handle_accept() {
        if(EAGINE_LIKELY(!_acceptors.empty())) {
            message_bus_acceptor::accept_handler handler{
              this, EAGINE_MEM_FUNC_C(message_bus_router, _handle_connection)};
            for(auto& acceptor : _acceptors) {
                EAGINE_ASSERT(acceptor);
                acceptor->process_accepted(handler);
            }
        }
    }

    void _handle_pending() {

        if(!_pending.empty()) {
            identifier_t id = 0;
            auto handler = [&id](
                             identifier_t class_id,
                             identifier_t method_id,
                             const message_view& msg) {
                // this is a special message containing endpoint id
                if(EAGINE_MSG_ID(eagiMsgBus, announceId)
                     .matches(class_id, method_id)) {
                    id = msg.source_id;
                    return true;
                }
                return false;
            };

            std::size_t pos = 0;
            while(pos < _pending.size()) {
                id = 0;
                auto& pending = _pending[pos];
                pending.connection->update();
                pending.connection->fetch_messages(
                  message_bus_connection::fetch_handler(handler));
                // if we got the endpoint id message from the connection
                if(id != 0) {
                    _endpoints[id].connections.emplace_back(
                      std::move(pending.connection));
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
                return pending.age() > this->_pending_timeout;
            }),
          _pending.end());
    }

    void _remove_disconnected() {
        for(auto& p : _endpoints) {
            auto& conns = std::get<1>(p).connections;
            conns.erase(
              std::remove_if(
                conns.begin(),
                conns.end(),
                [](auto& conn) { return !conn || !conn->is_usable(); }),
              conns.end());
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

    void _handle_connection(std::unique_ptr<message_bus_connection> conn) {
        EAGINE_ASSERT(conn);
        // find a currently unused endpoint id value
        ++_id_sequence;
        while(!_id_sequence ||
              (_endpoints.find(_id_sequence) != _endpoints.end())) {
            ++_id_sequence;
        }
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
      message_bus_routed_endpoint& endpoint,
      const message_view& message) {
        if(EAGINE_UNLIKELY(EAGINE_ID(eagiMsgBus).matches(class_id))) {
            if(EAGINE_ID(notARouter).matches(method_id)) {
                if(incoming_id == message.source_id) {
                    endpoint.maybe_router = false;
                    return true;
                }
            }
        }
        return false;
    }

    bool _do_route_message(
      identifier_t class_id,
      identifier_t method_id,
      identifier_t incoming_id,
      const message_view& message) {
        for(auto& [outgoing_id, endpoint_out] : this->_endpoints) {
            bool should_forward = (incoming_id != outgoing_id);
            should_forward &=
              (endpoint_out.maybe_router || (outgoing_id == message.target_id));
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
                    conn_in->fetch_messages(
                      message_bus_connection::fetch_handler(handler));
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
    }

    const std::chrono::seconds _pending_timeout{30};
    identifier_t _id_sequence{0};
    std::vector<std::unique_ptr<message_bus_acceptor>> _acceptors;
    std::vector<message_bus_router_pending> _pending;
    std::map<identifier_t, message_bus_routed_endpoint> _endpoints;
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_MSG_BUS_ROUTER_HPP

