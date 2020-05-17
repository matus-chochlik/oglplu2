/**
 *  @file eagine/message_bus/service/shutdown.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MESSAGE_BUS_SERVICE_SHUTDOWN_HPP
#define EAGINE_MESSAGE_BUS_SERVICE_SHUTDOWN_HPP

#include "../serialize.hpp"
#include "../subscriber.hpp"
#include <chrono>

namespace eagine {
namespace msgbus {
//------------------------------------------------------------------------------
// TODO replace with utc clock when available
using shutdown_service_clock = std::chrono::system_clock;
using shutdown_service_duration =
  std::chrono::duration<std::int64_t, std::milli>;
//------------------------------------------------------------------------------
template <typename Base = subscriber>
class shutdown_target
  : public Base
  , protected shutdown_service_clock {
    using This = shutdown_target;

protected:
    using Base::Base;

    void add_methods() {
        Base::add_methods();
        Base::add_method(
          this, EAGINE_MSG_MAP(Shutdown, shutdown, This, _handle_shutdown));
    }

public:
    virtual void on_shutdown(
      std::chrono::milliseconds age,
      identifier_t source,
      verification_bits) = 0;

private:
    bool _handle_shutdown(stored_message& message) {
        typename shutdown_service_duration::rep count{0};
        if(default_deserialize(count, message.data)) {
            const shutdown_service_duration ticks{count};
            const typename shutdown_service_clock::time_point ts{ticks};
            const auto age{this->now() - ts};
            on_shutdown(
              std::chrono::duration_cast<std::chrono::milliseconds>(age),
              message.source_id,
              this->verify_bits(message));
        }
        return true;
    }
};
//------------------------------------------------------------------------------
template <typename Base = subscriber>
class shutdown_invoker
  : public Base
  , protected shutdown_service_clock {

    using This = shutdown_invoker;

protected:
    using Base::Base;

public:
    void shutdown_one(identifier_t target_id) {
        std::array<byte, 32> temp{};
        const auto ts{this->now()};
        const auto ticks{std::chrono::duration_cast<shutdown_service_duration>(
          ts.time_since_epoch())};
        const auto count{ticks.count()};
        auto serialized{default_serialize(count, cover(temp))};
        EAGINE_ASSERT(serialized);

        message_view message{extract(serialized)};
        message.target_id = target_id;
        this->bus().send_signed(EAGINE_MSG_ID(Shutdown, shutdown), message);
    }
};
//------------------------------------------------------------------------------
} // namespace msgbus
} // namespace eagine

#endif // EAGINE_MESSAGE_BUS_SERVICE_SHUTDOWN_HPP

