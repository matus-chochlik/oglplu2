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
#include <array>
#include <type_traits>

namespace eagine {
namespace msgbus {
//------------------------------------------------------------------------------
template <typename MessageId, typename MemFuncConst>
struct message_handler_map {};
//------------------------------------------------------------------------------
#define EAGINE_MSG_MAP(CLASS_ID, METHOD_ID, CLASS, METHOD) \
    eagine::msgbus::message_handler_map<                   \
      EAGINE_MSG_TYPE(CLASS_ID, METHOD_ID),                \
      EAGINE_MEM_FUNC_T(CLASS, METHOD)>()
//------------------------------------------------------------------------------
class subscriber_base {
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

protected:
    using handler_type = typename endpoint::handler_type;
    using handler_entry = std::tuple<identifier_t, identifier_t, handler_type>;

    ~subscriber_base() noexcept = default;
    constexpr subscriber_base() noexcept = default;
    constexpr subscriber_base(endpoint& bus) noexcept
      : _endpoint{&bus} {
    }
    subscriber_base(subscriber_base&& temp) noexcept
      : _endpoint{temp._endpoint} {
        temp._endpoint = nullptr;
    }
    subscriber_base(const subscriber_base&) = delete;
    subscriber_base& operator=(subscriber_base&&) = delete;
    subscriber_base& operator=(const subscriber_base&) = delete;

    inline void _subscribe_to(span<const handler_entry> msg_handlers) const {
        if(EAGINE_LIKELY(_endpoint)) {
            for(auto& [class_id, method_id, unused] : msg_handlers) {
                EAGINE_MAYBE_UNUSED(unused);
                _endpoint->subscribe(class_id, method_id);
            }
        }
    }

    inline void _unsubscribe_from(span<const handler_entry> msg_handlers) const
      noexcept {
        if(_endpoint) {
            for(auto& [class_id, method_id, unused] : msg_handlers) {
                try {
                    EAGINE_MAYBE_UNUSED(unused);
                    _endpoint->unsubscribe(class_id, method_id);
                } catch(...) {
                }
            }
        }
    }

    inline void _announce_subscriptions(
      span<const handler_entry> msg_handlers) const {
        if(EAGINE_LIKELY(_endpoint)) {
            for(auto& [class_id, method_id, unused] : msg_handlers) {
                EAGINE_MAYBE_UNUSED(unused);
                _endpoint->say_subscribes_to(class_id, method_id);
            }
        }
    }

    inline void _allow_subscriptions(
      span<const handler_entry> msg_handlers) const {
        if(EAGINE_LIKELY(_endpoint)) {
            for(auto& [class_id, method_id, unused] : msg_handlers) {
                EAGINE_MAYBE_UNUSED(unused);
                _endpoint->allow_message_type(class_id, method_id);
            }
        }
    }

    inline void _retract_subscriptions(
      span<const handler_entry> msg_handlers) const {
        if(EAGINE_LIKELY(_endpoint)) {
            for(auto& [class_id, method_id, unused] : msg_handlers) {
                EAGINE_MAYBE_UNUSED(unused);
                _endpoint->say_unsubscribes_from(class_id, method_id);
            }
        }
    }

    bool _process_one(span<const handler_entry> msg_handlers) {
        for(auto& [class_id, method_id, handler] : msg_handlers) {
            if(bus().process_one(class_id, method_id, handler)) {
                return true;
            }
        }
        return false;
    }

    span_size_t _process_all(span<const handler_entry> msg_handlers) {
        span_size_t result{0};
        for(auto& [class_id, method_id, handler] : msg_handlers) {
            result += bus().process_all(class_id, method_id, handler);
        }
        return result;
    }

private:
    endpoint* _endpoint{nullptr};
};
//------------------------------------------------------------------------------
template <std::size_t N>
class static_subscriber : public subscriber_base {
public:
    using handler_type = typename endpoint::handler_type;

protected:
    template <
      identifier_t ClassId,
      identifier_t MethodId,
      typename Class,
      bool (Class::*HandlerFunc)(stored_message&)>
    static constexpr inline std::tuple<identifier_t, identifier_t, handler_type>
    as_tuple(
      Class* instance,
      message_handler_map<
        message_id<ClassId, MethodId>,
        member_function_constant<
          bool (Class::*)(stored_message&),
          HandlerFunc>>) noexcept {
        return {ClassId,
                MethodId,
                handler_type{instance,
                             member_function_constant<
                               bool (Class::*)(stored_message&),
                               HandlerFunc>{}}};
    }

    template <
      identifier_t ClassId,
      identifier_t MethodId,
      typename Class,
      bool (Class::*HandlerFunc)(stored_message&) const>
    static constexpr inline std::tuple<identifier_t, identifier_t, handler_type>
    as_tuple(
      const Class* instance,
      message_handler_map<
        message_id<ClassId, MethodId>,
        member_function_constant<
          bool (Class::*)(stored_message&) const,
          HandlerFunc>>) noexcept {
        return {ClassId,
                MethodId,
                handler_type{instance,
                             member_function_constant<
                               bool (Class::*)(stored_message&) const,
                               HandlerFunc>{}}};
    }

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
      : static_subscriber(bus, as_tuple(instance, msg_maps)...) {
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

    void announce_subscriptions() {
        this->_announce_subscriptions(view(_msg_handlers));
    }

    void allow_subscriptions() {
        this->_allow_subscriptions(view(_msg_handlers));
    }

    void retract_subscriptions() {
        this->_retract_subscriptions(view(_msg_handlers));
    }

private:
    std::array<const std::tuple<identifier_t, identifier_t, handler_type>, N>
      _msg_handlers;
};
//------------------------------------------------------------------------------
} // namespace msgbus
} // namespace eagine

#endif // EAGINE_MESSAGE_BUS_SUBSCRIBER_HPP

