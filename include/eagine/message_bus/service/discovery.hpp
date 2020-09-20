/**
 *  @file eagine/message_bus/service/discovery.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MESSAGE_BUS_SERVICE_DISCOVERY_HPP
#define EAGINE_MESSAGE_BUS_SERVICE_DISCOVERY_HPP

#include "../serialize.hpp"
#include "../subscriber.hpp"

namespace eagine::msgbus {
//------------------------------------------------------------------------------
template <typename Base = subscriber>
class subscriber_discovery : public Base {
    using This = subscriber_discovery;

protected:
    using Base::Base;

    void add_methods() {
        Base::add_methods();
        Base::add_method(
          this,
          EAGINE_MSG_MAP(eagiMsgBus, subscribTo, This, _handle_subscribed));
        Base::add_method(
          this,
          EAGINE_MSG_MAP(eagiMsgBus, unsubFrom, This, _handle_unsubscribed));
    }

public:
    virtual void on_subscribed(identifier_t subscriber_id, message_id) = 0;
    virtual void on_unsubscribed(identifier_t subscriber_id, message_id) = 0;

private:
    auto _handle_subscribed(stored_message& message) -> bool {
        message_id sub_msg_id{};
        if(default_deserialize_message_type(sub_msg_id, message.content())) {
            on_subscribed(message.source_id, sub_msg_id);
        }
        return true;
    }

    auto _handle_unsubscribed(stored_message& message) -> bool {
        message_id sub_msg_id{};
        if(default_deserialize_message_type(sub_msg_id, message.content())) {
            on_unsubscribed(message.source_id, sub_msg_id);
        }
        return true;
    }
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_SERVICE_DISCOVERY_HPP
