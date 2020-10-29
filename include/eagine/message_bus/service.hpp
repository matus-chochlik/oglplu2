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

#include "invoker.hpp"
#include "serialize.hpp"
#include "skeleton.hpp"
#include "subscriber.hpp"

namespace eagine::msgbus {
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
    auto _handle_sub_query(stored_message& message) -> bool {
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
    auto operator=(service_composition&&) = delete;
    auto operator=(const service_composition&) = delete;

    ~service_composition() noexcept override {
        this->retract_subscriptions();
        this->finish();
    }

    auto add_connection(std::unique_ptr<connection> conn) -> bool final {
        return this->bus().add_connection(std::move(conn));
    }
};
//------------------------------------------------------------------------------
template <typename Signature, std::size_t MaxDataSize = 8192 - 128>
using default_callback_invoker = callback_invoker<
  Signature,
  default_serializer_backend,
  default_deserializer_backend,
  MaxDataSize>;
//------------------------------------------------------------------------------
template <typename Signature, std::size_t MaxDataSize = 8192 - 128>
using default_invoker = invoker<
  Signature,
  default_serializer_backend,
  default_deserializer_backend,
  MaxDataSize>;
//------------------------------------------------------------------------------
template <typename Signature, std::size_t MaxDataSize = 8192 - 128>
using default_skeleton = skeleton<
  Signature,
  default_serializer_backend,
  default_deserializer_backend,
  MaxDataSize>;
//------------------------------------------------------------------------------
template <typename Signature, std::size_t MaxDataSize = 8192 - 128>
using default_lazy_skeleton = lazy_skeleton<
  Signature,
  default_serializer_backend,
  default_deserializer_backend,
  MaxDataSize>;
//------------------------------------------------------------------------------
template <typename Signature, std::size_t MaxDataSize = 8192 - 128>
using default_async_skeleton = async_skeleton<
  Signature,
  default_serializer_backend,
  default_deserializer_backend,
  MaxDataSize>;
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_SERVICE_HPP
