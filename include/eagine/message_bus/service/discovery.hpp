/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MESSAGE_BUS_SERVICE_DISCOVERY_HPP
#define EAGINE_MESSAGE_BUS_SERVICE_DISCOVERY_HPP

#include "../serialize.hpp"
#include "../signal.hpp"
#include "../subscriber.hpp"

namespace eagine::msgbus {
//------------------------------------------------------------------------------
/// @brief Structure containing basic information about a message bus endpoint.
struct subscriber_info {
    /// @brief The endpoint id.
    identifier_t endpoint_id{0U};
    /// @brief The endpoint's instance (process) id.
    process_instance_id_t instance_id{0U};
};
//------------------------------------------------------------------------------
/// @brief Service discovering information about endpoint status and subscriptions.
/// @ingroup msgbus
/// @see service_composition
/// @see subscriber_info
template <typename Base = subscriber>
class subscriber_discovery : public Base {
    using This = subscriber_discovery;

public:
    /// @brief Triggered on receipt of notification that an endpoint is alive.
    signal<void(const subscriber_info&)> reported_alive;

    /// @brief Triggered on receipt of info that endpoint subscribes to message.
    signal<void(const subscriber_info&, message_id)> subscribed;

    /// @brief Triggered on receipt of info that endpoint unsubscribes from message.
    signal<void(const subscriber_info&, message_id)> unsubscribed;

    /// @brief Triggered on receipt of info that endpoint doesn't handle message type.
    signal<void(const subscriber_info&, message_id)> not_subscribed;

protected:
    using Base::Base;

    void add_methods() {
        Base::add_methods();
        Base::add_method(
          this, EAGINE_MSG_MAP(eagiMsgBus, stillAlive, This, _handle_alive));
        Base::add_method(
          this,
          EAGINE_MSG_MAP(eagiMsgBus, subscribTo, This, _handle_subscribed));
        Base::add_method(
          this,
          EAGINE_MSG_MAP(eagiMsgBus, unsubFrom, This, _handle_unsubscribed));
        Base::add_method(
          this,
          EAGINE_MSG_MAP(eagiMsgBus, notSubTo, This, _handle_not_subscribed));
    }

private:
    auto _handle_alive(const message_context&, stored_message& message)
      -> bool {
        subscriber_info info{};
        info.endpoint_id = message.source_id;
        info.instance_id = message.sequence_no;
        reported_alive(info);
        return true;
    }

    auto _handle_subscribed(const message_context&, stored_message& message)
      -> bool {
        message_id sub_msg_id{};
        if(default_deserialize_message_type(sub_msg_id, message.content())) {
            subscriber_info info{};
            info.endpoint_id = message.source_id;
            info.instance_id = message.sequence_no;
            subscribed(info, sub_msg_id);
        }
        return true;
    }

    auto _handle_unsubscribed(const message_context&, stored_message& message)
      -> bool {
        message_id sub_msg_id{};
        if(default_deserialize_message_type(sub_msg_id, message.content())) {
            subscriber_info info{};
            info.endpoint_id = message.source_id;
            info.instance_id = message.sequence_no;
            unsubscribed(info, sub_msg_id);
        }
        return true;
    }

    auto _handle_not_subscribed(const message_context&, stored_message& message)
      -> bool {
        message_id sub_msg_id{};
        if(default_deserialize_message_type(sub_msg_id, message.content())) {
            subscriber_info info{};
            info.endpoint_id = message.source_id;
            info.instance_id = message.sequence_no;
            not_subscribed(info, sub_msg_id);
        }
        return true;
    }
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_SERVICE_DISCOVERY_HPP
