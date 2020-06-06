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
#include "blobs.hpp"
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

    using fetch_handler = connection::fetch_handler;
    using blob_filter_function = blob_manipulator::filter_function;

private:
    friend class friend_of_endpoint;

    logger _log{};

    shared_context _context{make_context(_log)};

    identifier_t _id{invalid_id()};

    std::vector<std::unique_ptr<connection>> _connections{};

    message_storage _outgoing{};

    // TODO: flat map
    std::map<message_id, std::tuple<span_size_t, message_priority_queue>>
      _incoming{};

    template <typename Entry>
    static inline auto& _get_counter(Entry& entry) {
        return std::get<0>(std::get<1>(entry));
    }

    template <typename Entry>
    static inline auto& _get_queue(Entry& entry) {
        return std::get<1>(std::get<1>(entry));
    }

    blob_manipulator _blobs{_log};
    blob_manipulator::filter_function _allow_blob{};

    bool _cleanup_blobs();
    bool _process_blobs();
    bool _do_allow_blob(message_id);

    fetch_handler _default_store_handler() noexcept {
        return fetch_handler{this, EAGINE_MEM_FUNC_C(endpoint, _store_message)};
    }
    fetch_handler _store_handler{_default_store_handler()};

    bool _do_send(message_id msg_id, message_view);

    bool _handle_send(message_id msg_id, const message_view& message) {
        return _do_send(msg_id, message);
    }

    bool _handle_post(message_id msg_id, const message_view& message) {
        return post(msg_id, message);
    }

    bool _handle_special(message_id msg_id, const message_view&) noexcept;

    bool _store_message(message_id msg_id, const message_view&);

    bool _accept_message(message_id msg_id, const message_view&);

    explicit endpoint(logger log, fetch_handler store_message) noexcept
      : _log{std::move(log)}
      , _store_handler{store_message} {
    }

    explicit endpoint(
      logger log,
      blob_filter_function allow_blob,
      fetch_handler store_message) noexcept
      : _log{std::move(log)}
      , _allow_blob{allow_blob}
      , _store_handler{store_message} {
    }

    endpoint(endpoint&& temp) noexcept
      : _log{std::move(temp._log)}
      , _context{std::move(temp._context)}
      , _id{temp._id}
      , _connections{std::move(temp._connections)}
      , _outgoing{std::move(temp._outgoing)}
      , _incoming{std::move(temp._incoming)}
      , _blobs{std::move(temp._blobs)} {
        temp._id = invalid_id();
    }

    endpoint(
      endpoint&& temp,
      blob_filter_function allow_blob,
      fetch_handler store_message) noexcept
      : _log{std::move(temp._log)}
      , _context{std::move(temp._context)}
      , _id{temp._id}
      , _connections{std::move(temp._connections)}
      , _outgoing{std::move(temp._outgoing)}
      , _incoming{std::move(temp._incoming)}
      , _blobs{std::move(temp._blobs)}
      , _allow_blob{allow_blob}
      , _store_handler{store_message} {
        temp._id = invalid_id();
    }

public:
    endpoint() = default;

    endpoint(logger log) noexcept
      : _log{std::move(log)} {
    }

    explicit endpoint(logger log, blob_filter_function allow_blob) noexcept
      : _log{std::move(log)}
      , _allow_blob{allow_blob} {
    }

    endpoint(logger log, const program_args& args) noexcept
      : _log{std::move(log)}
      , _context{make_context(_log, args)} {
    }

    endpoint(const endpoint&) = delete;
    endpoint& operator=(endpoint&&) = delete;
    endpoint& operator=(const endpoint&) = delete;

    context& ctx() noexcept {
        EAGINE_ASSERT(_context);
        return *_context;
    }

    logger& log() noexcept {
        return _log;
    }

    ~endpoint() noexcept override = default;

    endpoint& set_id(identifier id) {
        _id = id.value();
        return *this;
    }

    void add_certificate_pem(memory::const_block blk);
    void add_ca_certificate_pem(memory::const_block blk);

    bool add_connection(std::unique_ptr<connection> conn) final;

    bool is_usable() const;

    valid_if_positive<span_size_t> max_data_size() const;

    bool has_id() const noexcept {
        return is_valid_id(_id);
    }

    void flush_outbox();

    bool update();

    void finish() {
        say_bye();
        flush_outbox();
    }

    void subscribe(message_id);
    void unsubscribe(message_id);

    bool set_next_sequence_id(message_id, message_info&);

    bool post(message_id msg_id, message_view message) {
        _outgoing.push(msg_id, message);
        return true;
    }

    bool post_signed(message_id, message_view message);

    template <typename T>
    bool post_value(
      message_id msg_id, T& value, const message_info& info = {}) {
        if(const auto opt_size = max_data_size()) {
            const auto max_size = extract(opt_size);
            return _outgoing.push_if(
              [this, msg_id, &info, &value, max_size](
                message_id& dst_msg_id, stored_message& message) {
                  if(message.store_value(value, max_size)) {
                      message.assign(info);
                      dst_msg_id = msg_id;
                      return true;
                  }
                  return false;
              },
              max_size);
        }
        return false;
    }

    bool post_blob(
      message_id msg_id,
      identifier_t target_id,
      memory::const_block blob,
      std::chrono::seconds max_time,
      message_priority priority) {
        _blobs.push_outgoing(msg_id, _id, target_id, blob, max_time, priority);
        return true;
    }

    bool broadcast_blob(
      message_id msg_id,
      memory::const_block blob,
      std::chrono::seconds max_time,
      message_priority priority) {
        return post_blob(msg_id, invalid_id(), blob, max_time, priority);
    }

    bool broadcast_blob(
      message_id msg_id,
      memory::const_block blob,
      std::chrono::seconds max_time) {
        return broadcast_blob(msg_id, blob, max_time, message_priority::normal);
    }

    bool post_certificate(identifier_t target_id);
    bool broadcast_certificate();

    bool send(message_id msg_id, message_view message) {
        if(has_id()) {
            return _do_send(msg_id, message);
        } else {
            post(msg_id, message);
        }
        return false;
    }

    bool send(message_id msg_id) {
        return send(msg_id, {});
    }

    bool say_not_a_router();
    bool say_bye();

    void post_meta_message(message_id meta_msg_id, message_id msg_id);

    void say_subscribes_to(message_id);
    void say_unsubscribes_from(message_id);

    void clear_block_list();
    void block_message_type(message_id);

    void clear_allow_list();
    void allow_message_type(message_id);

    void query_certificate_of(identifier_t endpoint_id);

    bool respond_to(
      const message_info& info, message_id msg_id, message_view message) {
        message.setup_response(info);
        return send(msg_id, message);
    }

    bool respond_to(const message_info& info, message_id msg_id) {
        return respond_to(info, msg_id, {});
    }

    using method_handler = callable_ref<bool(stored_message&)>;

    bool process_one(message_id msg_id, method_handler handler);

    template <typename Class, bool (Class::*MemFnPtr)(stored_message&)>
    inline bool process_one(
      message_id msg_id,
      member_function_constant<bool (Class::*)(stored_message&), MemFnPtr>
        method,
      Class* instance) {
        return process_one(msg_id, {instance, method});
    }

    span_size_t process_all(message_id msg_id, method_handler handler);

    using generic_handler = callable_ref<bool(message_id, stored_message&)>;

    span_size_t process_everything(generic_handler handler);
};
//------------------------------------------------------------------------------
class friend_of_endpoint {
protected:
    static auto _make_endpoint(
      logger log, endpoint::fetch_handler store_message) noexcept {
        return endpoint{std::move(log), store_message};
    }

    static auto _make_endpoint(
      logger log,
      endpoint::blob_filter_function allow_blob,
      endpoint::fetch_handler store_message) noexcept {
        return endpoint{std::move(log), allow_blob, store_message};
    }

    static auto _move_endpoint(
      endpoint&& bus, endpoint::fetch_handler store_message) noexcept {
        return endpoint{std::move(bus), {}, store_message};
    }

    static auto _move_endpoint(
      endpoint&& bus,
      endpoint::blob_filter_function allow_blob,
      endpoint::fetch_handler store_message) noexcept {
        return endpoint{std::move(bus), allow_blob, store_message};
    }

    inline bool _accept_message(
      endpoint& ep, message_id msg_id, const message_view& message) {
        return ep._accept_message(msg_id, message);
    }
};
//------------------------------------------------------------------------------
} // namespace msgbus
} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/message_bus/endpoint.inl>
#endif

#endif // EAGINE_MESSAGE_BUS_ENDPOINT_HPP

