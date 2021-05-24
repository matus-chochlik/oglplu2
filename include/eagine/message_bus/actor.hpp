/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MESSAGE_BUS_ACTOR_HPP
#define EAGINE_MESSAGE_BUS_ACTOR_HPP

#include "subscriber.hpp"

namespace eagine::msgbus {
//------------------------------------------------------------------------------
/// @brief Base class for message bus actors with fixed number of message handlers.
/// @ingroup msgbus
/// @see static_subscriber
/// @see subscriber
/// @see endpoint
template <
  std::size_t N,
  template <std::size_t> class Subscriber = static_subscriber>
class actor
  : public connection_user
  , public friend_of_endpoint {
    using friend_of_endpoint::_accept_message;
    using friend_of_endpoint::_make_endpoint;
    using friend_of_endpoint::_move_endpoint;

public:
    /// @brief Not move constructible.
    actor(actor&&) = delete;

    /// @brief Not copy constructible.
    actor(const actor&) = delete;

    /// @brief Not moved assignable.
    auto operator=(actor&&) = delete;

    /// @brief Not copy assignable.
    auto operator=(const actor&) = delete;

    /// @brief Returns a reference to the associated endpoint.
    auto bus_node() noexcept -> endpoint& {
        return _endpoint;
    }

    /// @brief Adds a connection to the associated endpoint.
    auto add_connection(std::unique_ptr<connection> conn) -> bool final {
        return _endpoint.add_connection(std::move(conn));
    }

    void allow_subscriptions() {
        _subscriber.allow_subscriptions();
    }

    /// @brief Processes a single enqueued message for which there is a handler.
    /// @see process_all
    auto process_one() {
        _endpoint.update();
        return _subscriber.process_one();
    }

    /// @brief Processes all enqueued messages for which there are handlers.
    /// @see process_one
    auto process_all() {
        _endpoint.update();
        return _subscriber.process_all();
    }

protected:
    auto _process_message(
      message_id msg_id,
      message_age,
      const message_view& message) -> bool {
        // TODO: use message age
        if(!_accept_message(_endpoint, msg_id, message)) {
            if(!is_special_message(msg_id)) {
                _endpoint.block_message_type(msg_id);
            }
        }
        return true;
    }

    /// @brief Constructor usable from derived classes
    template <
      typename Class,
      typename... MsgMaps,
      typename = std::enable_if_t<sizeof...(MsgMaps) == N>>
    actor(
      main_ctx_object obj, // NOLINT(performance-unnecessary-value-param)
      Class* instance,
      MsgMaps... msg_maps)
      : _endpoint{_make_endpoint(
          std::move(obj),
          EAGINE_THIS_MEM_FUNC_REF(_process_message))}
      , _subscriber{_endpoint, instance, msg_maps...} {
        _subscriber.announce_subscriptions();
    }

    /// @brief Constructor usable from derived classes
    template <
      typename Derived,
      typename Class,
      typename... MsgMaps,
      typename = std::enable_if_t<
        (sizeof...(MsgMaps) == N) && std::is_base_of_v<actor, Derived>>>
    actor(Derived&& temp, Class* instance, MsgMaps... msg_maps) noexcept
      : _endpoint{_move_endpoint(
          std::move(temp._endpoint),
          EAGINE_THIS_MEM_FUNC_REF(_process_message))}
      , _subscriber{_endpoint, instance, msg_maps...} {}

    ~actor() noexcept override {
        try {
            _subscriber.retract_subscriptions();
            _endpoint.finish();
        } catch(...) {
        }
    }

private:
    endpoint _endpoint;
    Subscriber<N> _subscriber;
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_ACTOR_HPP
