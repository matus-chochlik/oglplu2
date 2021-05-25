/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MESSAGE_BUS_SERVICE_SHUTDOWN_HPP
#define EAGINE_MESSAGE_BUS_SERVICE_SHUTDOWN_HPP

#include "../serialize.hpp"
#include "../signal.hpp"
#include "../subscriber.hpp"
#include <chrono>

namespace eagine::msgbus {
//------------------------------------------------------------------------------
// TODO replace with utc clock when available
using shutdown_service_clock = std::chrono::system_clock;
using shutdown_service_duration =
  std::chrono::duration<std::int64_t, std::milli>;
//------------------------------------------------------------------------------
/// @brief Service allowing an endpoint to be shut down over the message bus.
/// @ingroup msgbus
/// @see service_composition
/// @see shutdown_invoker
template <typename Base = subscriber>
class shutdown_target
  : public Base
  , protected shutdown_service_clock {
    using This = shutdown_target;

public:
    /// @brief Triggered when a shutdown request is received.
    signal<void(
      std::chrono::milliseconds age,
      identifier_t source_id,
      verification_bits verified)>
      shutdown_requested;

protected:
    using Base::Base;

    void add_methods() {
        Base::add_methods();
        Base::add_method(
          this, EAGINE_MSG_MAP(Shutdown, shutdown, This, _handle_shutdown));
    }

private:
    auto _handle_shutdown(const message_context&, stored_message& message)
      -> bool {
        typename shutdown_service_duration::rep count{0};
        if(default_deserialize(count, message.content())) {
            const shutdown_service_duration ticks{count};
            const typename shutdown_service_clock::time_point ts{ticks};
            const auto age{this->now() - ts};
            shutdown_requested(
              std::chrono::duration_cast<std::chrono::milliseconds>(age),
              message.source_id,
              this->verify_bits(message));
        }
        return true;
    }
};
//------------------------------------------------------------------------------
/// @brief Service allowing to shut down other endpoints over the message bus.
/// @ingroup msgbus
/// @see service_composition
/// @see shutdown_target
template <typename Base = subscriber>
class shutdown_invoker
  : public Base
  , protected shutdown_service_clock {

    using This = shutdown_invoker;

public:
    /// @brief Sends shutdown request to the specified target endpoint.
    void shutdown_one(identifier_t target_id) {
        std::array<byte, 32> temp{};
        const auto ts{this->now()};
        const auto ticks{std::chrono::duration_cast<shutdown_service_duration>(
          ts.time_since_epoch())};
        const auto count{ticks.count()};
        auto serialized{default_serialize(count, cover(temp))};
        EAGINE_ASSERT(serialized);

        message_view message{extract(serialized)};
        message.set_target_id(target_id);
        this->bus_node().post_signed(
          EAGINE_MSG_ID(Shutdown, shutdown), message);
    }

protected:
    using Base::Base;
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_SERVICE_SHUTDOWN_HPP
