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

#include "../logging/logger.hpp"
#include "connection.hpp"
#include "context_fwd.hpp"
#include "serialize.hpp"
#include <map>
#include <tuple>
#include <vector>

namespace eagine {
namespace msgbus {
//------------------------------------------------------------------------------
class friend_of_endpoint;
//------------------------------------------------------------------------------
class endpoint : public connection_user {
public:
    static constexpr identifier_t invalid_id() noexcept {
        return 0U;
    }

    static constexpr bool is_valid_id(identifier_t id) noexcept {
        return id != invalid_id();
    }

private:
    friend class friend_of_endpoint;

    logger _log{};

    shared_context _context{};

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

    bool _do_send(identifier_t class_id, identifier_t method_id, message_view);

    template <identifier_t ClassId, identifier_t MethodId>
    bool _do_send(message_id<ClassId, MethodId>, const message_view& message) {
        return _do_send(ClassId, MethodId, message);
    }

    bool _handle_send(
      identifier_t class_id,
      identifier_t method_id,
      const message_view& message) {
        return _do_send(class_id, method_id, message);
    }

    bool _handle_special(
      identifier_t class_id,
      identifier_t method_id,
      const message_view&) noexcept;

    bool _store_message(
      identifier_t class_id, identifier_t method_id, const message_view&);

    bool _accept_message(
      identifier_t class_id, identifier_t method_id, const message_view&);

    explicit endpoint(
      logger log, connection::fetch_handler store_message) noexcept
      : _log{std::move(log)}
      , _store_handler{store_message} {
    }

    endpoint(endpoint&& temp) noexcept
      : _log{std::move(temp._log)}
      , _context{std::move(temp._context)}
      , _id{temp._id}
      , _connections{std::move(temp._connections)}
      , _outgoing{std::move(temp._outgoing)}
      , _incoming{std::move(temp._incoming)}
      , _store_handler{this, EAGINE_MEM_FUNC_C(endpoint, _store_message)} {
        temp._id = invalid_id();
    }

    endpoint(endpoint&& temp, connection::fetch_handler store_message) noexcept
      : _log{std::move(temp._log)}
      , _context{std::move(temp._context)}
      , _id{temp._id}
      , _connections{std::move(temp._connections)}
      , _outgoing{std::move(temp._outgoing)}
      , _incoming{std::move(temp._incoming)}
      , _store_handler{store_message} {
        temp._id = invalid_id();
    }

public:
    endpoint() noexcept
      : _store_handler{this, EAGINE_MEM_FUNC_C(endpoint, _store_message)} {
    }

    endpoint(logger log) noexcept
      : _log{std::move(log)}
      , _context{make_context(_log)}
      , _store_handler{this, EAGINE_MEM_FUNC_C(endpoint, _store_message)} {
    }

    endpoint(logger log, const program_args& args) noexcept
      : _log{std::move(log)}
      , _context{make_context(_log, args)}
      , _store_handler{this, EAGINE_MEM_FUNC_C(endpoint, _store_message)} {
    }

    endpoint(const endpoint&) = delete;
    endpoint& operator=(endpoint&&) = delete;
    endpoint& operator=(const endpoint&) = delete;

    logger& log() noexcept {
        return _log;
    }

    ~endpoint() noexcept override = default;

    endpoint& set_id(identifier id) {
        _id = id.value();
        return *this;
    }

    bool add_connection(std::unique_ptr<connection> conn) final;

    bool is_usable() const;

    valid_if_positive<span_size_t> max_data_size() const;

    bool has_id() const noexcept {
        return is_valid_id(_id);
    }

    void flush_outbox();

    bool update();

    void subscribe(identifier_t class_id, identifier_t method_id);

    template <identifier_t ClassId, identifier_t MethodId>
    void subscribe(message_id<ClassId, MethodId>) {
        subscribe(ClassId, MethodId);
    }

    void unsubscribe(identifier_t class_id, identifier_t method_id);

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
        post(ClassId, MethodId, message);
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
        return send(ClassId, MethodId, message);
    }

    template <identifier_t ClassId, identifier_t MethodId>
    bool send(message_id<ClassId, MethodId>) {
        return send(ClassId, MethodId, {});
    }

    bool send_signed(
      identifier_t class_id, identifier_t method_id, message_view message) {
        // TODO: add signatures
        return send(class_id, method_id, message);
    }

    template <identifier_t ClassId, identifier_t MethodId>
    bool send_signed(message_id<ClassId, MethodId>, message_view message) {
        return send_signed(ClassId, MethodId, message);
    }

    bool say_not_a_router();
    bool say_bye();

    void post_meta_message(
      identifier_t meta_class_id,
      identifier_t meta_method_id,
      identifier_t class_id,
      identifier_t method_id);

    template <identifier_t ClassId, identifier_t MethodId>
    void post_meta_message(
      message_id<ClassId, MethodId>,
      identifier_t class_id,
      identifier_t method_id) {
        post_meta_message(ClassId, MethodId, class_id, method_id);
    }

    void say_subscribes_to(identifier_t class_id, identifier_t method_id);

    template <identifier_t ClassId, identifier_t MethodId>
    void say_subscribes_to(message_id<ClassId, MethodId>) {
        say_subscribes_to(ClassId, MethodId);
    }

    void say_unsubscribes_from(identifier_t class_id, identifier_t method_id);

    template <identifier_t ClassId, identifier_t MethodId>
    void say_unsubscribes_from(message_id<ClassId, MethodId>) {
        say_unsubscribes_from(ClassId, MethodId);
    }

    void clear_block_list();
    void block_message_type(identifier_t class_id, identifier_t method_id);

    template <identifier_t ClassId, identifier_t MethodId>
    void block_message_type(message_id<ClassId, MethodId>) {
        block_message_type(ClassId, MethodId);
    }

    void clear_allow_list();
    void allow_message_type(identifier_t class_id, identifier_t method_id);

    template <identifier_t ClassId, identifier_t MethodId>
    void allow_message_type(message_id<ClassId, MethodId>) {
        allow_message_type(ClassId, MethodId);
    }

    bool respond_to(
      const message_info& info,
      identifier_t class_id,
      identifier_t method_id,
      message_view message) {
        message.setup_response(info);
        return send(class_id, method_id, message);
    }

    template <identifier_t ClassId, identifier_t MethodId>
    bool respond_to(
      const message_info& info,
      message_id<ClassId, MethodId>,
      message_view message) {
        return respond_to(info, ClassId, MethodId, message);
    }

    template <identifier_t ClassId, identifier_t MethodId>
    bool respond_to(const message_info& info, message_id<ClassId, MethodId>) {
        return respond_to(info, ClassId, MethodId, {});
    }

    bool respond_signed_to(
      const message_info& info,
      identifier_t class_id,
      identifier_t method_id,
      message_view message) {
        // TODO: add signatures
        return respond_to(info, class_id, method_id, message);
    }

    template <identifier_t ClassId, identifier_t MethodId>
    bool respond_signed_to(
      const message_info& info,
      message_id<ClassId, MethodId>,
      message_view message) {
        return respond_signed_to(info, ClassId, MethodId, message);
    }

    using handler_type = callable_ref<bool(stored_message&)>;

    bool process_one(
      identifier_t class_id,
      identifier_t method_id,
      const handler_type& handler);

    span_size_t process_all(
      identifier_t class_id,
      identifier_t method_id,
      const handler_type& handler);

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
      logger log, connection::fetch_handler store_message) noexcept {
        return endpoint{std::move(log), store_message};
    }

    static auto _move_endpoint(
      endpoint&& bus, connection::fetch_handler store_message) noexcept {
        return endpoint{std::move(bus), store_message};
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

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/message_bus/endpoint.inl>
#endif

#endif // EAGINE_MESSAGE_BUS_ENDPOINT_HPP

