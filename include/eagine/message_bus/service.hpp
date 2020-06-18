/**
 *  @file eagine/message_bus/service.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MESSAGE_BUS_SERVICE_HPP
#define EAGINE_MESSAGE_BUS_SERVICE_HPP

#include "subscriber.hpp"

namespace eagine {
namespace msgbus {
//------------------------------------------------------------------------------
template <typename Base = subscriber>
class service_composition
  : public Base
  , public connection_user {

    using This = service_composition;

protected:
    void add_methods() {
        Base::add_methods();
        Base::add_method(
          this,
          EAGINE_MSG_MAP(eagiMsgBus, qrySubscrb, This, _handle_sub_query));
    }

private:
    bool _handle_sub_query(stored_message& message) {
        message_id sub_msg_id{};
        if(default_deserialize_message_type(sub_msg_id, message.content())) {
            this->respond_to_subscription_query(message.source_id, sub_msg_id);
        }
        return true;
    }

    void _init() {
        this->add_methods();
        this->init();
        this->announce_subscriptions();
    }

public:
    service_composition(endpoint& bus)
      : Base{bus} {
        _init();
    }

    // NOLINTNEXTLINE(hicpp-noexcept-move,performance-noexcept-move-constructor)
    service_composition(service_composition&& that)
      : Base{static_cast<Base&&>(that)} {
        _init();
    }
    service_composition(const service_composition&) = delete;
    service_composition& operator=(service_composition&&) = delete;
    service_composition& operator=(const service_composition&) = delete;

    ~service_composition() noexcept override {
        this->retract_subscriptions();
        this->finish();
    }

    bool add_connection(std::unique_ptr<connection> conn) final {
        return this->bus().add_connection(std::move(conn));
    }
};
//------------------------------------------------------------------------------
} // namespace msgbus
} // namespace eagine

#endif // EAGINE_MESSAGE_BUS_SERVICE_HPP
