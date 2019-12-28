/**
 *  @file eagine/msg_bus/subscriber.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MSG_BUS_SUBSCRIBER_HPP
#define EAGINE_MSG_BUS_SUBSCRIBER_HPP

#include "endpoint.hpp"
#include <array>

namespace eagine {
//------------------------------------------------------------------------------
template <std::size_t N>
class message_bus_subscriber_base {
public:
    message_bus_subscriber_base(message_bus_subscriber_base&& temp) noexcept
      : _endpoint{temp.endpoint}
      , _msg_ids{temp._msg_ids} {
        temp._endpoint = nullptr;
    }

    message_bus_subscriber_base(const message_bus_subscriber_base& that)
      : _endpoint{that.endpoint}
      , _msg_ids{that._msg_ids} {
        _subscribe();
    }

    message_bus_subscriber_base& operator=(message_bus_subscriber_base&&) =
      delete;
    message_bus_subscriber_base& operator=(const message_bus_subscriber_base&) =
      delete;

    ~message_bus_subscriber_base() noexcept {
        _unsubscribe();
    }

    explicit operator bool() noexcept {
        return _endpoint != nullptr;
    }

    bool operator!() noexcept {
        return _endpoint == nullptr;
    }

    message_bus_endpoint& endpoint() noexcept {
        EAGINE_ASSERT(_endpoint != nullptr);
        return *_endpoint;
    }

protected:
    template <typename... MsgIds>
    message_bus_subscriber_base(message_bus_endpoint& endpoint, MsgIds...)
      : _endpoint{&endpoint}
      , _msg_ids{{MsgIds::as_tuple()...}} {
        _subscribe();
    }

private:
    message_bus_endpoint* _endpoint{nullptr};
    std::array<std::tuple<identifier_t, identifier_t>, N> _msg_ids;

    void _subscribe() {
        if(_endpoint) {
            for(auto& [class_id, method_id] : _msg_ids) {
                _endpoint->subscribe(class_id, method_id);
            }
        }
    }

    void _unsubscribe() noexcept {
        if(_endpoint) {
            for(auto& [class_id, method_id] : _msg_ids) {
                try {
                    _endpoint->unsubscribe(class_id, method_id);
                } catch(...) {
                }
            }
        }
    }
};
//------------------------------------------------------------------------------
template <typename... MsgIds>
class message_bus_subscriber
  : public message_bus_subscriber_base<sizeof...(MsgIds)> {
    using base = message_bus_subscriber_base<sizeof...(MsgIds)>;

public:
    message_bus_subscriber(message_bus_endpoint& endpoint)
      : base{endpoint, MsgIds()...} {
    }
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_MSG_BUS_SUBSCRIBER_HPP

