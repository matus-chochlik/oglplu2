/**
 *  @file eagine/msg_bus/subscriber.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MSG_BUS_SUBSCRIBER_HPP
#define EAGINE_MSG_BUS_SUBSCRIBER_HPP

#include "../maybe_unused.hpp"
#include "endpoint.hpp"
#include <array>
#include <type_traits>

namespace eagine {
//------------------------------------------------------------------------------
template <typename MessageId, typename MemFuncConst>
struct message_handler_map {};
//------------------------------------------------------------------------------
template <std::size_t N>
class message_bus_subscriber {
public:
    using handler_type = typename message_bus_endpoint::handler_type;

    message_bus_subscriber(message_bus_subscriber&& temp) = delete;
    message_bus_subscriber(const message_bus_subscriber&) = delete;
    message_bus_subscriber& operator=(message_bus_subscriber&&) = delete;
    message_bus_subscriber& operator=(const message_bus_subscriber&) = delete;

    ~message_bus_subscriber() noexcept {
        _unsubscribe();
    }

    explicit operator bool() noexcept {
        return _endpoint != nullptr;
    }

    bool operator!() noexcept {
        return _endpoint == nullptr;
    }

    message_bus_endpoint& endpoint() noexcept {
        EAGINE_ASSERT(_endpoint != nullptr);
        return *_endpoint;
    }

    const message_bus_endpoint& endpoint() const noexcept {
        EAGINE_ASSERT(_endpoint != nullptr);
        return *_endpoint;
    }

    bool process_one() {
        for(auto& [class_id, method_id, handler] : _msg_handlers) {
            if(endpoint().process_one(class_id, method_id, handler)) {
                return true;
            }
        }
        return false;
    }

protected:
    template <
      typename Class,
      typename... MsgMaps,
      typename = std::enable_if_t<sizeof...(MsgMaps) == N>>
    message_bus_subscriber(
      message_bus_endpoint& endpoint, Class* instance, MsgMaps... msg_maps)
      : _endpoint{&endpoint}
      , _msg_handlers{{as_tuple(instance, msg_maps)...}} {
        _subscribe();
    }

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

private:
    unsigned _padding{0};
    message_bus_endpoint* const _endpoint{nullptr};
    std::array<const std::tuple<identifier_t, identifier_t, handler_type>, N>
      _msg_handlers;

    void _subscribe() {
        if(_endpoint) {
            for(auto& [class_id, method_id, unused] : _msg_handlers) {
                EAGINE_MAYBE_UNUSED(class_id);
                EAGINE_MAYBE_UNUSED(method_id);
                EAGINE_MAYBE_UNUSED(unused);
                _endpoint->subscribe(class_id, method_id);
            }
            for(auto& [class_id, method_id, unused] : _msg_handlers) {
                EAGINE_MAYBE_UNUSED(class_id);
                EAGINE_MAYBE_UNUSED(method_id);
                EAGINE_MAYBE_UNUSED(unused);
            }
        }
    }

    void _unsubscribe() noexcept {
        if(_endpoint) {
            for(auto& [class_id, method_id, unused] : _msg_handlers) {
                try {
                    EAGINE_MAYBE_UNUSED(unused);
                    _endpoint->unsubscribe(class_id, method_id);
                } catch(...) {
                }
            }
        }
    }
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_MSG_BUS_SUBSCRIBER_HPP

