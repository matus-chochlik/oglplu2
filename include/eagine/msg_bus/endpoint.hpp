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
#include <tuple>
#include <vector>

namespace eagine {
//------------------------------------------------------------------------------
class message_bus_endpoint {
    identifier_t _id{0};

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
        // this is a special message requesting/assigning endpoint id
        if(EAGINE_UNLIKELY(class_id == 0)) {
            if(!has_id()) {
                _id = method_id;
            }
            return true;
        }
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

    bool has_id() const {
        return _id != 0;
    }

    void update() {

        const bool had_id = has_id();
        message_bus_connection::fetch_handler handler{
          this, EAGINE_MEM_FUNC_C(message_bus_endpoint, _store_message)};

        for(auto& connection : _connections) {
            EAGINE_ASSERT(connection);
            connection->update();
            connection->fetch_messages(handler);
        }

        // if processing the messages assigned the endpoint id
        if(EAGINE_UNLIKELY(has_id() && !had_id)) {
            // send the endpoint id through all connections
            send(0, _id, {});
        }
    }

    void subscribe(identifier_t class_id, identifier_t method_id) {
        auto key = _make_key(class_id, method_id);
        auto [pos, newone] = _messages.try_emplace(key);
        if(newone) {
            _get_counter(pos) = 0;
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

    void send(
      identifier_t class_id,
      identifier_t method_id,
      const message_view& message) const {
        for(auto& connection : _connections) {
            EAGINE_ASSERT(connection);
            if(connection->send(class_id, method_id, message)) {
                break;
            }
        }
    }

    template <identifier_t ClassId, identifier_t MethodId>
    void send(
      message_id<ClassId, MethodId>, const message_view& message) const {
        send(ClassId, MethodId, message);
    }

    using handler_type = callable_ref<bool(stored_message&)>;

    bool process_one(
      identifier_t class_id,
      identifier_t method_id,
      const handler_type& handler) {
        auto pos = _messages.find(_make_key(class_id, method_id));
        if(pos != _messages.end()) {
            return _get_queue(pos).process_one(handler);
        }
        return false;
    }

    span_size_t process_all(
      identifier_t class_id,
      identifier_t method_id,
      const handler_type& handler) {
        auto pos = _messages.find(_make_key(class_id, method_id));
        if(pos != _messages.end()) {
            return _get_queue(pos).process_all(handler);
        }
        return 0;
    }

    template <identifier_t ClassId, identifier_t MethodId>
    inline bool process_one(
      message_id<ClassId, MethodId>, const handler_type& handler) {
        return process_one(ClassId, MethodId, handler);
    }

    template <identifier_t ClassId, identifier_t MethodId>
    inline span_size_t process_all(
      message_id<ClassId, MethodId>, const handler_type& handler) {
        return process_all(ClassId, MethodId, handler);
    }

    template <
      identifier_t ClassId,
      identifier_t MethodId,
      typename Class,
      bool (Class::*MemFnPtr)(stored_message&)>
    inline bool process_one(
      message_id<ClassId, MethodId> mid,
      member_function_constant<bool (Class::*)(stored_message&), MemFnPtr>
        method,
      Class* instance) {
        return process_one(mid, {instance, method});
    }
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_MSG_BUS_ENDPOINT_HPP

