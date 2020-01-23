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
namespace msgbus {
//------------------------------------------------------------------------------
class friend_of_endpoint;
//------------------------------------------------------------------------------
class endpoint {
public:
    static constexpr identifier_t invalid_id() noexcept {
        return {0U};
    }

    static constexpr bool is_valid_id(identifier_t id) noexcept {
        return id != invalid_id();
    }

private:
    friend class friend_of_endpoint;

    identifier_t _id{invalid_id()};

    std::vector<std::unique_ptr<connection>> _connections;

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

    connection::fetch_handler _store_handler{};

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

    explicit endpoint(connection::fetch_handler store_message) noexcept
      : _store_handler{std::move(store_message)} {
    }

    inline bool _handle_special(
      identifier_t class_id,
      identifier_t method_id,
      const message_view& message) noexcept {
        if(EAGINE_UNLIKELY(EAGINE_MSG_ID(eagiMsgBus, assignId)
                             .matches(class_id, method_id))) {
            if(!has_id()) {
                _id = message.target_id;
            }
            return true;
        }
        return false;
    }

    bool _store_message(
      identifier_t class_id,
      identifier_t method_id,
      const message_view& message) {
        if(!_handle_special(class_id, method_id, message)) {
            if((message.target_id == _id) || !is_valid_id(message.target_id)) {
                auto pos = _incoming.find(_make_key(class_id, method_id));
                if(pos != _incoming.end()) {
                    _get_queue(pos).push(message);
                    return true;
                }
            }
        }
        return false;
    }

    bool _accept_message(
      identifier_t class_id,
      identifier_t method_id,
      const message_view& message) {
        if(_handle_special(class_id, method_id, message)) {
            return true;
        }
        auto pos = _incoming.find(_make_key(class_id, method_id));
        if(pos != _incoming.end()) {
            if((message.target_id == _id) || !is_valid_id(message.target_id)) {
                _get_queue(pos).push(message);
            }
            return true;
        }
        return false;
    }

public:
    endpoint() noexcept
      : _store_handler{this, EAGINE_MEM_FUNC_C(endpoint, _store_message)} {
    }

    endpoint& set_id(identifier id) {
        _id = id.value();
        return *this;
    }

    bool add_connection(std::unique_ptr<connection> conn) {
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

    void flush_outbox() {
        if(has_id()) {
            _outgoing.fetch_all(message_storage::fetch_handler{
              this, EAGINE_MEM_FUNC_C(endpoint, _handle_send)});
        }
    }

    void update() {

        const bool had_id = has_id();

        for(auto& connection : _connections) {
            EAGINE_ASSERT(connection);
            connection->update();
            connection->fetch_messages(_store_handler);
        }

        // if processing the messages assigned the endpoint id
        if(EAGINE_UNLIKELY(has_id() && !had_id)) {
            // send the endpoint id through all connections
            _do_send(EAGINE_MSG_ID(eagiMsgBus, announceId), {});
        }

        // if we have a valid id and we have messages in outbox
        if(EAGINE_UNLIKELY(has_id() && !_outgoing.empty())) {
            _outgoing.fetch_all(message_storage::fetch_handler{
              this, EAGINE_MEM_FUNC_C(endpoint, _handle_send)});
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

    void post(
      identifier_t class_id, identifier_t method_id, message_view message) {
        _outgoing.push(class_id, method_id, message);
    }

    template <identifier_t ClassId, identifier_t MethodId>
    void post(message_id<ClassId, MethodId>, message_view message) {
        post(ClassId, MethodId, std::move(message));
    }

    template <typename T>
    bool post_value(
      identifier_t class_id,
      identifier_t method_id,
      T& value,
      const message_info& info = {}) {
        if(auto opt_size = max_data_size()) {
            return _outgoing.push_if(
              [this, class_id, method_id, &info, &value](
                identifier_t& dst_class_id,
                identifier_t& dst_method_id,
                stored_message& message) {
                  block_data_sink sink(cover(message.data));
                  default_serializer_backend backend(sink);
                  auto errors = serialize(value, backend);
                  if(!errors) {
                      dst_class_id = class_id;
                      dst_method_id = method_id;
                      message.assign(info).set_serializer_id(backend.type_id());
                      message.data.resize(sink.done().size());
                      return true;
                  }
                  return false;
              },
              extract(opt_size));
        }
        return false;
    }

    template <identifier_t ClassId, identifier_t MethodId, typename T>
    bool post_value(
      message_id<ClassId, MethodId>, T& value, const message_info& info = {}) {
        return post_value(ClassId, MethodId, value, info);
    }

    bool send(
      identifier_t class_id, identifier_t method_id, message_view message) {
        if(has_id()) {
            return _do_send(class_id, method_id, message);
        } else {
            post(class_id, method_id, message);
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

    bool say_bye() {
        return send(EAGINE_MSG_ID(eagiMsgBus, byeBye));
    }

    template <identifier_t ClassId, identifier_t MethodId>
    void post_meta_message(
      message_id<ClassId, MethodId> meta_msg_id,
      identifier_t class_id,
      identifier_t method_id) {
        auto msg_id{
          std::make_tuple(identifier(class_id), identifier(method_id))};
        std::array<byte, 64> temp{};
        if(auto serialized = default_serialize(msg_id, cover(temp))) {
            post(meta_msg_id, message_view(extract(serialized)));
        }
    }

    void say_subscribes_to(identifier_t class_id, identifier_t method_id) {
        post_meta_message(
          EAGINE_MSG_ID(eagiMsgBus, subscribTo), class_id, method_id);
    }

    template <identifier_t ClassId, identifier_t MethodId>
    void say_subscribes_to(message_id<ClassId, MethodId>) {
        say_subscribes_to(ClassId, MethodId);
    }

    void say_unsubscribes_from(identifier_t class_id, identifier_t method_id) {
        post_meta_message(
          EAGINE_MSG_ID(eagiMsgBus, unsubFrom), class_id, method_id);
    }

    template <identifier_t ClassId, identifier_t MethodId>
    void say_unsubscribes_from(message_id<ClassId, MethodId>) {
        say_unsubscribes_from(ClassId, MethodId);
    }

    void clear_blacklist() {
        post(EAGINE_MSG_ID(eagiMsgBus, clrBlkList), {});
    }

    void blacklist_message_type(identifier_t class_id, identifier_t method_id) {
        post_meta_message(
          EAGINE_MSG_ID(eagiMsgBus, msgBlkList), class_id, method_id);
    }

    template <identifier_t ClassId, identifier_t MethodId>
    void blacklist_message_type(message_id<ClassId, MethodId>) {
        blacklist_message_type(ClassId, MethodId);
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
class friend_of_endpoint {
protected:
    static auto _make_endpoint(
      connection::fetch_handler store_message) noexcept {
        return endpoint{store_message};
    }

    inline bool _accept_message(
      endpoint& ep,
      identifier_t class_id,
      identifier_t method_id,
      const message_view& message) {
        return ep._accept_message(class_id, method_id, message);
    }
};
//------------------------------------------------------------------------------
} // namespace msgbus
} // namespace eagine

#endif // EAGINE_MESSAGE_BUS_ENDPOINT_HPP

