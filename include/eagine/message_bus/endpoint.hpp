/**
 *  @file eagine/message_bus/endpoint.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MESSAGE_BUS_ENDPOINT_HPP
#define EAGINE_MESSAGE_BUS_ENDPOINT_HPP

#include "connection.hpp"
#include "serialize.hpp"
#include <map>
#include <tuple>
#include <vector>

namespace eagine {
//------------------------------------------------------------------------------
class message_bus_endpoint {
public:
    static constexpr identifier_t invalid_id() noexcept {
        return {0U};
    }

    static constexpr bool is_valid_id(identifier_t id) noexcept {
        return id != invalid_id();
    }

private:
    identifier_t _id{invalid_id()};

    std::vector<std::unique_ptr<message_bus_connection>> _connections;

    message_storage _outgoing;

    // TODO: flat map
    std::map<
      std::tuple<identifier_t, identifier_t>,
      std::tuple<span_size_t, message_priority_queue>>
      _incoming;

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
        if(EAGINE_UNLIKELY(EAGINE_MSG_ID(eagiMsgBus, assignId)
                             .matches(class_id, method_id))) {
            if(!has_id()) {
                _id = message.target_id;
            }
            return true;
        }
        if((message.target_id == _id) || !is_valid_id(message.target_id)) {
            auto pos = _incoming.find(_make_key(class_id, method_id));
            if(pos != _incoming.end()) {
                _get_queue(pos).push(message);
                return true;
            }
        }
        return false;
    }

    bool _do_send(
      identifier_t class_id,
      identifier_t method_id,
      message_view message) const {
        EAGINE_ASSERT(has_id());
        message.set_source_id(_id);
        for(auto& connection : _connections) {
            EAGINE_ASSERT(connection);
            if(connection->send(class_id, method_id, message)) {
                return true;
            }
        }
        return false;
    }

    template <identifier_t ClassId, identifier_t MethodId>
    bool _do_send(
      message_id<ClassId, MethodId>, const message_view& message) const {
        return _do_send(ClassId, MethodId, message);
    }

    bool _handle_send(
      identifier_t class_id,
      identifier_t method_id,
      const message_view& message) const {
        return _do_send(class_id, method_id, message);
    }

public:
    message_bus_endpoint& set_id(identifier id) {
        _id = id.value();
        return *this;
    }

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

    valid_if_positive<span_size_t> max_data_size() const {
        span_size_t result{0};
        for(auto& connection : _connections) {
            EAGINE_ASSERT(connection);
            if(connection->is_usable()) {
                if(const auto opt_max_size = connection->max_data_size()) {
                    const auto max_size = extract(opt_max_size);
                    if(result > 0) {
                        if(result > max_size) {
                            result = max_size;
                        }
                    } else {
                        result = max_size;
                    }
                }
            }
        }
        return {result};
    }

    bool has_id() const noexcept {
        return is_valid_id(_id);
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
            _do_send(EAGINE_MSG_ID(eagiMsgBus, announceId), {});
        }

        // if we have a valid id and we have messages in outbox
        if(EAGINE_UNLIKELY(has_id() && !_outgoing.empty())) {
            _outgoing.fetch_all(message_storage::fetch_handler{
              this, EAGINE_MEM_FUNC_C(message_bus_endpoint, _handle_send)});
        }
    }

    void subscribe(identifier_t class_id, identifier_t method_id) {
        auto key = _make_key(class_id, method_id);
        auto [pos, newone] = _incoming.try_emplace(key);
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
        auto pos = _incoming.find(_make_key(class_id, method_id));
        if(pos != _incoming.end()) {
            if(--_get_counter(pos) <= 0) {
                _incoming.erase(pos);
            }
        }
    }

    template <identifier_t ClassId, identifier_t MethodId>
    void unsubscribe(message_id<ClassId, MethodId>) {
        unsubscribe(ClassId, MethodId);
    }

    bool send(
      identifier_t class_id, identifier_t method_id, message_view message) {
        if(has_id()) {
            return _do_send(class_id, method_id, message);
        } else {
            _outgoing.push(class_id, method_id, message);
        }
        return false;
    }

    template <identifier_t ClassId, identifier_t MethodId>
    bool send(message_id<ClassId, MethodId>, message_view message) {
        return send(ClassId, MethodId, std::move(message));
    }

    template <identifier_t ClassId, identifier_t MethodId>
    bool send(message_id<ClassId, MethodId>) {
        return send(ClassId, MethodId, {});
    }

    bool say_not_a_router() {
        return send(EAGINE_MSG_ID(eagiMsgBus, notARouter));
    }

    bool clear_blacklist() {
        return send(EAGINE_MSG_ID(eagiMsgBus, clrBlkList));
    }

    bool blacklist_message_type(std::tuple<identifier_t, identifier_t> msg_id) {
        std::array<byte, 64> temp{};
        if(
          auto serialized =
            message_bus_default_serialize(msg_id, cover(temp))) {
            return send(
              EAGINE_MSG_ID(eagiMsgBus, msgBlkList),
              message_view(extract(serialized)));
        }
        return false;
    }

    bool blacklist_message_type(identifier_t class_id, identifier_t method_id) {
        return blacklist_message_type(std::make_tuple(class_id, method_id));
    }

    template <identifier_t ClassId, identifier_t MethodId>
    bool blacklist_message_type(message_id<ClassId, MethodId>) {
        return blacklist_message_type(ClassId, MethodId);
    }

    bool respond_to(
      const message_info& info,
      identifier_t class_id,
      identifier_t method_id,
      message_view message) {
        message.setup_response(info);
        return send(class_id, method_id, std::move(message));
    }

    template <identifier_t ClassId, identifier_t MethodId>
    bool respond_to(
      const message_info& info,
      message_id<ClassId, MethodId>,
      message_view message) {
        return respond_to(info, ClassId, MethodId, std::move(message));
    }

    template <identifier_t ClassId, identifier_t MethodId>
    bool respond_to(const message_info& info, message_id<ClassId, MethodId>) {
        return respond_to(info, ClassId, MethodId, {});
    }

    using handler_type = callable_ref<bool(stored_message&)>;

    bool process_one(
      identifier_t class_id,
      identifier_t method_id,
      const handler_type& handler) {
        auto pos = _incoming.find(_make_key(class_id, method_id));
        if(pos != _incoming.end()) {
            return _get_queue(pos).process_one(handler);
        }
        return false;
    }

    span_size_t process_all(
      identifier_t class_id,
      identifier_t method_id,
      const handler_type& handler) {
        auto pos = _incoming.find(_make_key(class_id, method_id));
        if(pos != _incoming.end()) {
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

#endif // EAGINE_MESSAGE_BUS_ENDPOINT_HPP

