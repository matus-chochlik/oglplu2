/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MESSAGE_BUS_SERVICE_ABILITY_HPP
#define EAGINE_MESSAGE_BUS_SERVICE_ABILITY_HPP

#include "../serialize.hpp"
#include "../subscriber.hpp"

namespace eagine::msgbus {
//------------------------------------------------------------------------------
/// @brief Service providing information about message types handled by endpoint.
/// @ingroup msgbus
/// @see service_composition
/// @see ability_tester
template <typename Base = subscriber>
class ability_provider : public Base {
    using This = ability_provider;

public:
    /// @brief Indicates if the given message type is handled by the endpoint.
    virtual auto can_handle(message_id) -> bool = 0;

protected:
    using Base::Base;

    void add_methods() {
        Base::add_methods();
        Base::add_method(
          this, EAGINE_MSG_MAP(Ability, query, This, _handle_query));
    }

private:
    auto _handle_query(const message_context& msg_ctx, stored_message& message)
      -> bool {
        message_id msg_id{};
        if(default_deserialize_message_type(msg_id, message.content())) {
            if(can_handle()) {
                msg_ctx.bus_node().respond_to(
                  message,
                  EAGINE_MSG_ID(Ability, response),
                  {message.content()});
            }
        }
        return true;
    }
};
//------------------------------------------------------------------------------
/// @brief Service consuming information about message types handled by endpoint.
/// @ingroup msgbus
/// @see service_composition
/// @see ability_provider
template <typename Base = subscriber>
class ability_tester : public Base {

    using This = ability_tester;

public:
    /// @brief Sends a query to endpoints if they handle the specified message type.
    /// @see handler_found
    void find_handler(message_id msg_id) {
        std::array<byte, 32> temp{};
        auto serialized{default_serialize(msg_id, cover(temp))};
        EAGINE_ASSERT(serialized);

        message_view message{extract(serialized)};
        this->bus_node().broadcast(EAGINE_MSG_ID(Ability, query), message);
    }

    /// @brief Triggered on receipt of response about message handling by endpoint.
    /// @see find_handler
    signal<void(identifier_t target_id, message_id)> handler_found;

protected:
    using Base::Base;

    void add_methods() {
        Base::add_methods();
        Base::add_method(
          this, EAGINE_MSG_MAP(Ability, response, This, _handle_response));
    }

private:
    auto _handle_response(const message_context&, stored_message& message)
      -> bool {
        message_id msg_id{};
        if(default_deserialize_message_type(msg_id, message.content())) {
            handler_found(message.source_id, msg_id);
        }
        return true;
    }
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_SERVICE_ABILITY_HPP
