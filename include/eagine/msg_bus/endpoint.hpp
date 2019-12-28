/**
 *  @file eagine/msg_bus/endpoint.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MSG_BUS_ENDPOINT_HPP
#define EAGINE_MSG_BUS_ENDPOINT_HPP

#include "connection.hpp"
#include <map>
#include <vector>

namespace eagine {
//------------------------------------------------------------------------------
class message_bus_endpoint {

    std::vector<std::unique_ptr<message_bus_connection>> _connections;

    std::map<
      std::tuple<identifier_t, identifier_t>,
      std::tuple<span_size_t, message_priority_queue>>
      _messages;

    static inline auto _make_key(
      identifier_t class_id, identifier_t method_id) noexcept {
        return std::make_tuple(class_id, method_id);
    }

    template <typename Iter>
    static inline auto& _get_counter(Iter& iter) {
        return std::get<0>(std::get<1>(*iter));
    }

    template <typename Iter>
    static inline auto& _get_queue(Iter& iter) {
        return std::get<1>(std::get<1>(*iter));
    }

    bool _store_message(
      identifier_t class_id,
      identifier_t method_id,
      const message_view& message) {
        auto pos = _messages.find(_make_key(class_id, method_id));
        if(pos != _messages.end()) {
            _get_queue(pos).push(message);
            return true;
        }
        return false;
    }

public:
    bool add_connection(std::unique_ptr<message_bus_connection> conn) {
        if(conn) {
            _connections.emplace_back(std::move(conn));
            return true;
        }
        return false;
    }

    bool is_usable() const {
        for(auto& connection : _connections) {
            EAGINE_ASSERT(connection);
            if(connection->is_usable()) {
                return true;
            }
        }
        return false;
    }

    void update() {
        message_bus_connection::fetch_handler handler{
          this, EAGINE_MEM_FUNC_C(message_bus_endpoint, _store_message)};

        for(auto& connection : _connections) {
            EAGINE_ASSERT(connection);
            connection->update();
            connection->fetch_messages(handler);
        }
    }

    void subscribe(identifier_t class_id, identifier_t method_id) {
        auto key = _make_key(class_id, method_id);
        auto pos = _messages.find(key);
        if(pos == _messages.end()) {
            std::get<0>(_messages[key]) = 0;
        }
        ++_get_counter(pos);
    }

    template <identifier_t ClassId, identifier_t MethodId>
    void subscribe(message_id<ClassId, MethodId>) {
        subscribe(ClassId, MethodId);
    }

    void unsubscribe(identifier_t class_id, identifier_t method_id) {
        auto pos = _messages.find(_make_key(class_id, method_id));
        if(pos != _messages.end()) {
            if(--_get_counter(pos) <= 0) {
                _messages.erase(pos);
            }
        }
    }

    template <identifier_t ClassId, identifier_t MethodId>
    void unsubscribe(message_id<ClassId, MethodId>) {
        unsubscribe(ClassId, MethodId);
    }

    template <identifier_t ClassId, identifier_t MethodId>
    void send(message_id<ClassId, MethodId>, const message_view& message) {
        for(auto& connection : _connections) {
            EAGINE_ASSERT(connection);
            connection->send(ClassId, MethodId, message);
        }
    }

    using handler_type = callable_ref<bool(stored_message&)>;

    template <identifier_t ClassId, identifier_t MethodId>
    void process_one(
      message_id<ClassId, MethodId>, const handler_type& handler) {
        auto pos = _messages.find(_make_key(ClassId, MethodId));
        if(pos != _messages.end()) {
            _get_queue(pos).fetch_one(handler);
        }
    }

    template <
      identifier_t ClassId,
      identifier_t MethodId,
      typename Class,
      bool (Class::*MemFnPtr)(stored_message&)>
    void process_one(
      message_id<ClassId, MethodId> mid,
      member_function_constant<bool (Class::*)(stored_message&), MemFnPtr>
        method,
      Class* instance) {
        process_one(mid, {instance, method});
    }
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_MSG_BUS_ENDPOINT_HPP

