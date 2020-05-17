/**
 *  @file eagine/message_bus/service/ping_pong.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MESSAGE_BUS_SERVICE_PING_PONG_HPP
#define EAGINE_MESSAGE_BUS_SERVICE_PING_PONG_HPP

#include "../../maybe_unused.hpp"
#include "../serialize.hpp"
#include "../subscriber.hpp"
#include <chrono>
#include <vector>

namespace eagine {
namespace msgbus {
//------------------------------------------------------------------------------
template <typename Base = subscriber>
class pingable : public Base {
    using This = pingable;

protected:
    using Base::Base;

    void add_methods() {
        Base::add_methods();
        Base::add_method(
          this, EAGINE_MSG_MAP(eagiPing, ping, This, _handle_ping));
    }

public:
    virtual bool respond_to_ping(
      identifier_t pinger_id, message_sequence_t, verification_bits) = 0;

private:
    bool _handle_ping(stored_message& message) {
        if(respond_to_ping(
             message.source_id,
             message.sequence_no,
             this->verify_bits(message))) {
            this->bus().respond_signed_to(
              message, EAGINE_MSG_ID(eagiPing, pong), {});
        }
        return true;
    }
};
//------------------------------------------------------------------------------
template <typename Base = subscriber>
class pinger
  : public Base
  , protected std::chrono::steady_clock {

    using This = pinger;

    std::vector<std::tuple<identifier_t, message_sequence_t, timeout>>
      _pending{};

protected:
    using Base::Base;

    void add_methods() {
        Base::add_methods();
        Base::add_method(
          this, EAGINE_MSG_MAP(eagiPing, pong, This, _handle_pong));
    }

public:
    void ping(
      identifier_t pingable_id, std::chrono::milliseconds max_time = {5000}) {
        message_view message{};
        auto msg_id{EAGINE_MSG_ID(eagiPing, ping)};
        message.set_target_id(pingable_id);
        this->bus().set_next_sequence_id(msg_id, message);
        this->bus().send_signed(msg_id, message);
        _pending.emplace_back(message.target_id, message.sequence_no, max_time);
    }

    bool update() {
        some_true something_done{};
        something_done(Base::update());

        _pending.erase(
          std::remove_if(
            _pending.begin(),
            _pending.end(),
            [this, &something_done](auto& entry) {
                auto& [pingable_id, sequence_no, ping_time] = entry;
                if(ping_time.is_elapsed()) {
                    on_ping_timeout(
                      pingable_id,
                      sequence_no,
                      std::chrono::duration_cast<std::chrono::microseconds>(
                        ping_time.elapsed_time()));
                    something_done();
                    return true;
                }
                return false;
            }),
          _pending.end());
        return something_done;
    }

    bool has_pending_pings() const noexcept {
        return !_pending.empty();
    }

    virtual void on_ping_response(
      identifier_t pingable_id,
      message_sequence_t sequence_no,
      std::chrono::microseconds age,
      verification_bits) = 0;

    virtual void on_ping_timeout(
      identifier_t pingable_id,
      message_sequence_t sequence_no,
      std::chrono::microseconds age) = 0;

private:
    bool _handle_pong(stored_message& message) {
        _pending.erase(
          std::remove_if(
            _pending.begin(),
            _pending.end(),
            [this, &message](auto& entry) {
                auto& [pingable_id, sequence_no, ping_time] = entry;
                const bool is_response = (message.source_id == pingable_id) &&
                                         (message.sequence_no == sequence_no);
                if(is_response) {
                    on_ping_response(
                      message.source_id,
                      message.sequence_no,
                      std::chrono::duration_cast<std::chrono::microseconds>(
                        ping_time.elapsed_time()),
                      this->verify_bits(message));
                    return true;
                }
                return false;
            }),
          _pending.end());
        return true;
    }
};
//------------------------------------------------------------------------------
} // namespace msgbus
} // namespace eagine

#endif // EAGINE_MESSAGE_BUS_SERVICE_SHUTDOWN_HPP

