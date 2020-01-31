/**
 *  @file eagine/message_bus/actor.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MESSAGE_BUS_ACTOR_HPP
#define EAGINE_MESSAGE_BUS_ACTOR_HPP

#include "subscriber.hpp"

namespace eagine {
namespace msgbus {
//------------------------------------------------------------------------------
template <std::size_t N, template <std::size_t> class Subscriber = subscriber>
class actor
  : public connection_user
  , public friend_of_endpoint {
    using friend_of_endpoint::_accept_message;
    using friend_of_endpoint::_make_endpoint;
    using friend_of_endpoint::_move_endpoint;

protected:
    bool _process_message(
      identifier_t class_id,
      identifier_t method_id,
      const message_view& message) {
        if(!_accept_message(_endpoint, class_id, method_id, message)) {
            if(!EAGINE_ID(eagiMsgBus).matches(class_id)) {
                _endpoint.blacklist_message_type(class_id, method_id);
            }
        }
        return true;
    }

    template <
      typename Class,
      typename... MsgMaps,
      typename = std::enable_if_t<sizeof...(MsgMaps) == N>>
    actor(Class* instance, MsgMaps... msg_maps)
      : _endpoint{_make_endpoint(
          {this, EAGINE_MEM_FUNC_C(actor, _process_message)})}
      , _subscriber{_endpoint, instance, msg_maps...} {
        _endpoint.say_not_a_router();
        _subscriber.announce_subscriptions();
    }

    template <
      typename Derived,
      typename Class,
      typename... MsgMaps,
      typename = std::enable_if_t<
        (sizeof...(MsgMaps) == N) && std::is_base_of_v<actor, Derived>>>
    actor(Derived&& temp, Class* instance, MsgMaps... msg_maps) noexcept
      : _endpoint{_move_endpoint(
          std::move(temp._endpoint),
          {this, EAGINE_MEM_FUNC_C(actor, _process_message)})}
      , _subscriber{_endpoint, instance, msg_maps...} {
    }

    actor(actor&&) noexcept = default;
    actor(const actor&) = delete;
    actor& operator=(actor&&) = delete;
    actor& operator=(const actor&) = delete;

    ~actor() noexcept override {
        try {
            _subscriber.retract_subscriptions();
            _endpoint.say_bye();
            _endpoint.flush_outbox();
        } catch(...) {
        }
    }

public:
    endpoint& bus() noexcept {
        return _endpoint;
    }

    bool add_connection(std::unique_ptr<connection> conn) final {
        return _endpoint.add_connection(std::move(conn));
    }

    void process_one() {
        _endpoint.update();
        _subscriber.process_one();
    }

    void process_all() {
        _endpoint.update();
        _subscriber.process_all();
    }

private:
    endpoint _endpoint;
    Subscriber<N> _subscriber;
};
//------------------------------------------------------------------------------
} // namespace msgbus
} // namespace eagine

#endif // EAGINE_MESSAGE_BUS_ACTOR_HPP

