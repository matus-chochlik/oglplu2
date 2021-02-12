/// @file eagine/message_bus/service/discovery.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MESSAGE_BUS_SERVICE_DISCOVERY_HPP
#define EAGINE_MESSAGE_BUS_SERVICE_DISCOVERY_HPP

#include "../serialize.hpp"
#include "../subscriber.hpp"

namespace eagine::msgbus {
//------------------------------------------------------------------------------
struct subscriber_info {
    identifier_t endpoint_id{0U};
    process_instance_id_t instance_id{0U};
};
//------------------------------------------------------------------------------
template <typename Base = subscriber>
class subscriber_discovery : public Base {
    using This = subscriber_discovery;

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

public:
    virtual void is_alive(const subscriber_info&) = 0;
    virtual void on_subscribed(const subscriber_info&, message_id) = 0;
    virtual void on_unsubscribed(const subscriber_info&, message_id) = 0;
    virtual void not_subscribed(const subscriber_info&, message_id) = 0;

private:
    auto _handle_alive(const message_context&, stored_message& message)
      -> bool {
        subscriber_info info{};
        info.endpoint_id = message.source_id;
        info.instance_id = message.sequence_no;
        is_alive(info);
        return true;
    }

    auto _handle_subscribed(const message_context&, stored_message& message)
      -> bool {
        message_id sub_msg_id{};
        if(default_deserialize_message_type(sub_msg_id, message.content())) {
            subscriber_info info{};
            info.endpoint_id = message.source_id;
            info.instance_id = message.sequence_no;
            on_subscribed(info, sub_msg_id);
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
            on_unsubscribed(info, sub_msg_id);
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
