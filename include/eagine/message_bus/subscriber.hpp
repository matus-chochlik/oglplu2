/**
 *  @file eagine/message_bus/subscriber.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MESSAGE_BUS_SUBSCRIBER_HPP
#define EAGINE_MESSAGE_BUS_SUBSCRIBER_HPP

#include "../maybe_unused.hpp"
#include "../span.hpp"
#include "endpoint.hpp"
#include "verification.hpp"
#include <array>
#include <type_traits>
#include <vector>

namespace eagine::msgbus {
//------------------------------------------------------------------------------
template <typename MessageId, typename MemFuncConst>
struct message_handler_map {
    static constexpr inline MessageId msg_id() noexcept {
        return {};
    }

    static constexpr inline MemFuncConst method() noexcept {
        return {};
    }
};
//------------------------------------------------------------------------------
#define EAGINE_MSG_MAP(CLASS_ID, METHOD_ID, CLASS, METHOD) \
    eagine::msgbus::message_handler_map<                   \
      EAGINE_MSG_TYPE(CLASS_ID, METHOD_ID),                \
      EAGINE_MEM_FUNC_T(CLASS, METHOD)>()
//------------------------------------------------------------------------------
class subscriber_base {
    endpoint* _endpoint{nullptr};

public:
    explicit operator bool() noexcept {
        return _endpoint != nullptr;
    }

    bool operator!() noexcept {
        return _endpoint == nullptr;
    }

    endpoint& bus() noexcept {
        EAGINE_ASSERT(_endpoint != nullptr);
        return *_endpoint;
    }

    const endpoint& bus() const noexcept {
        EAGINE_ASSERT(_endpoint != nullptr);
        return *_endpoint;
    }

    bool update() const noexcept {
        if(EAGINE_LIKELY(_endpoint)) {
            return _endpoint->update();
        }
        return false;
    }

    verification_bits verify_bits(
      const stored_message& message) const noexcept {
        if(EAGINE_LIKELY(_endpoint)) {
            return message.verify_bits(_endpoint->ctx(), _endpoint->log());
        }
        return {};
    }

    void query_subscribers_of(message_id sub_msg) {

        if(EAGINE_LIKELY(_endpoint)) {
            _endpoint->query_subscribers_of(sub_msg);
        }
    }

    subscriber_base(const subscriber_base&) = delete;
    subscriber_base& operator=(subscriber_base&&) = delete;
    subscriber_base& operator=(const subscriber_base&) = delete;

protected:
    using method_handler = typename endpoint::method_handler;
    struct handler_entry {
        message_id msg_id{};
        method_handler handler{};

        constexpr handler_entry() noexcept = default;

        constexpr handler_entry(message_id id, method_handler hndlr) noexcept
          : msg_id{std::move(id)}
          , handler{std::move(hndlr)} {
        }

        template <
          identifier_t ClassId,
          identifier_t MethodId,
          typename Class,
          bool (Class::*HandlerFunc)(stored_message&)>
        handler_entry(
          Class* instance,
          message_handler_map<
            static_message_id<ClassId, MethodId>,
            member_function_constant<
              bool (Class::*)(stored_message&),
              HandlerFunc>> msg_map) noexcept
          : msg_id{ClassId, MethodId}
          , handler{instance, msg_map.method()} {
        }

        template <
          identifier_t ClassId,
          identifier_t MethodId,
          typename Class,
          bool (Class::*HandlerFunc)(stored_message&)>
        handler_entry(
          Class* instance,
          message_handler_map<
            static_message_id<ClassId, MethodId>,
            member_function_constant<
              bool (Class::*)(stored_message&) const,
              HandlerFunc>> msg_map) noexcept
          : msg_id{ClassId, MethodId}
          , handler{instance, msg_map.method()} {
        }
    };

    ~subscriber_base() noexcept = default;
    constexpr subscriber_base() noexcept = default;
    constexpr subscriber_base(endpoint& bus) noexcept
      : _endpoint{&bus} {
    }
    subscriber_base(subscriber_base&& temp) noexcept
      : _endpoint{temp._endpoint} {
        temp._endpoint = nullptr;
    }

    inline void _subscribe_to(span<const handler_entry> msg_handlers) const {
        if(EAGINE_LIKELY(_endpoint)) {
            for(auto& entry : msg_handlers) {
                _endpoint->subscribe(entry.msg_id);
            }
        }
    }

    inline void _unsubscribe_from(
      span<const handler_entry> msg_handlers) const noexcept {
        if(_endpoint) {
            for(auto& entry : msg_handlers) {
                try {
                    _endpoint->unsubscribe(entry.msg_id);
                } catch(...) {
                }
            }
        }
    }

    inline void _announce_subscriptions(
      span<const handler_entry> msg_handlers) const {
        if(EAGINE_LIKELY(_endpoint)) {
            for(auto& entry : msg_handlers) {
                _endpoint->say_subscribes_to(entry.msg_id);
            }
        }
    }

    inline void _allow_subscriptions(
      span<const handler_entry> msg_handlers) const {
        if(EAGINE_LIKELY(_endpoint)) {
            for(auto& entry : msg_handlers) {
                _endpoint->allow_message_type(entry.msg_id);
            }
        }
    }

    inline void _retract_subscriptions(
      span<const handler_entry> msg_handlers) const noexcept {
        if(EAGINE_LIKELY(_endpoint)) {
            for(auto& entry : msg_handlers) {
                try {
                    _endpoint->say_unsubscribes_from(entry.msg_id);
                } catch(...) {
                }
            }
        }
    }

    inline void _respond_to_subscription_query(
      identifier_t source_id,
      message_id sub_msg,
      span<const handler_entry> msg_handlers) const {
        if(EAGINE_LIKELY(_endpoint)) {
            for(auto& entry : msg_handlers) {
                if(entry.msg_id == sub_msg) {
                    _endpoint->say_subscribes_to(source_id, entry.msg_id);
                    break;
                }
            }
        }
    }

    bool _process_one(span<const handler_entry> msg_handlers) {
        for(auto& entry : msg_handlers) {
            if(bus().process_one(entry.msg_id, entry.handler)) {
                return true;
            }
        }
        return false;
    }

    span_size_t _process_all(span<const handler_entry> msg_handlers) {
        span_size_t result{0};
        for(auto& entry : msg_handlers) {
            result += bus().process_all(entry.msg_id, entry.handler);
        }
        return result;
    }

    void _finish() noexcept {
        if(EAGINE_LIKELY(_endpoint)) {
            try {
                _endpoint->finish();
            } catch(...) {
            }
        }
    }
};
//------------------------------------------------------------------------------
template <std::size_t N>
class static_subscriber : public subscriber_base {
public:
    using method_handler = typename endpoint::method_handler;

protected:
    using handler_entry = typename subscriber_base::handler_entry;

public:
    template <
      typename... MsgHandlers,
      typename = std::enable_if_t<sizeof...(MsgHandlers) == N>>
    static_subscriber(endpoint& bus, MsgHandlers&&... msg_handlers)
      : subscriber_base{bus}
      , _msg_handlers{{std::forward<MsgHandlers>(msg_handlers)...}} {
        this->_subscribe_to(view(_msg_handlers));
    }

    template <
      typename Class,
      typename... MsgMaps,
      typename = std::enable_if_t<sizeof...(MsgMaps) == N>>
    static_subscriber(endpoint& bus, Class* instance, MsgMaps... msg_maps)
      : static_subscriber(bus, handler_entry(instance, msg_maps)...) {
    }

    static_subscriber(static_subscriber&& temp) = delete;
    static_subscriber(const static_subscriber&) = delete;
    static_subscriber& operator=(static_subscriber&&) = delete;
    static_subscriber& operator=(const static_subscriber&) = delete;

    ~static_subscriber() noexcept {
        this->_unsubscribe_from(view(_msg_handlers));
    }

    bool process_one() {
        return this->_process_one(view(_msg_handlers));
    }

    span_size_t process_all() {
        return this->_process_all(view(_msg_handlers));
    }

    void announce_subscriptions() const {
        this->_announce_subscriptions(view(_msg_handlers));
    }

    void allow_subscriptions() const {
        this->_allow_subscriptions(view(_msg_handlers));
    }

    void retract_subscriptions() const noexcept {
        this->_retract_subscriptions(view(_msg_handlers));
    }

    void respond_to_subscription_query(
      identifier_t source_id, message_id sub_msg) const noexcept {
        this->_respond_to_subscription_query(
          source_id, sub_msg, view(_msg_handlers));
    }

private:
    std::array<handler_entry, N> _msg_handlers;
};
//------------------------------------------------------------------------------
class subscriber : public subscriber_base {
public:
    using handler_entry = subscriber_base::handler_entry;
    using method_handler = callable_ref<bool(stored_message&)>;

    virtual ~subscriber() noexcept = default;
    subscriber() noexcept = default;
    subscriber(endpoint& bus) noexcept
      : subscriber_base{bus} {
    }
    subscriber(subscriber&&) noexcept = default;
    subscriber(const subscriber&) = delete;
    subscriber& operator=(subscriber&&) = delete;
    subscriber& operator=(const subscriber&) = delete;

    template <typename Class, bool (Class::*Method)(stored_message&)>
    void add_method(
      Class* instance,
      message_id msg_id,
      member_function_constant<bool (Class::*)(stored_message&), Method>
        method) {
        _msg_handlers.emplace_back(msg_id, method_handler{instance, method});
    }

    template <
      typename Class,
      bool (Class::*Method)(stored_message&),
      identifier_t ClassId,
      identifier_t MethodId>
    void add_method(
      Class* instance,
      message_handler_map<
        static_message_id<ClassId, MethodId>,
        member_function_constant<bool (Class::*)(stored_message&), Method>>
        msg_map) noexcept {
        add_method(instance, msg_map.msg_id(), msg_map.method());
    }

    bool process_one() {
        return this->_process_one(view(_msg_handlers));
    }

    span_size_t process_all() {
        return this->_process_all(view(_msg_handlers));
    }

    void announce_subscriptions() const {
        this->_announce_subscriptions(view(_msg_handlers));
    }

    void allow_subscriptions() const {
        this->_allow_subscriptions(view(_msg_handlers));
    }

    void retract_subscriptions() const noexcept {
        this->_retract_subscriptions(view(_msg_handlers));
    }

    void respond_to_subscription_query(
      identifier_t source_id, message_id sub_msg) const noexcept {
        this->_respond_to_subscription_query(
          source_id, sub_msg, view(_msg_handlers));
    }

protected:
    void add_methods() {
    }

    void init() {
        this->_subscribe_to(view(_msg_handlers));
    }

    void finish() noexcept {
        this->_unsubscribe_from(view(_msg_handlers));
        this->_finish();
    }

private:
    std::vector<handler_entry> _msg_handlers;
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_SUBSCRIBER_HPP

