/**
 *  @file eagine/msg_bus/direct.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MSG_BUS_DIRECT_HPP
#define EAGINE_MSG_BUS_DIRECT_HPP

#include "../branch_predict.hpp"
#include "connection.hpp"
#include <mutex>

namespace eagine {
//------------------------------------------------------------------------------
class message_bus_direct_connection_state {
public:
    void send_to_server(
      identifier_t class_id,
      identifier_t method_id,
      const message_view& message) {
        std::unique_lock lock{_mutex};
        _client_to_server.push(class_id, method_id, message);
    }

    void send_to_client(
      identifier_t class_id,
      identifier_t method_id,
      const message_view& message) {
        std::unique_lock lock{_mutex};
        _server_to_client.push(class_id, method_id, message);
    }

    void fetch_from_client(
      message_bus_connection::fetch_handler handler) noexcept {
        std::unique_lock lock{_mutex};
        _client_to_server.fetch_all(handler);
    }

    void fetch_from_server(
      message_bus_connection::fetch_handler handler) noexcept {
        std::unique_lock lock{_mutex};
        _server_to_client.fetch_all(handler);
    }

public:
    std::mutex _mutex;
    message_storage _server_to_client;
    message_storage _client_to_server;
};
//------------------------------------------------------------------------------
class message_bus_direct_connection_address {
public:
    using shared_state = std::shared_ptr<message_bus_direct_connection_state>;
    using process_handler = callable_ref<void(shared_state&)>;

    shared_state connect() {
        auto state = std::make_shared<message_bus_direct_connection_state>();
        _pending.push_back(state);
        return state;
    }

    void process_all(process_handler handler) {
        for(auto& state : _pending) {
            handler(state);
        }
        _pending.clear();
    }

private:
    std::vector<shared_state> _pending;
};
//------------------------------------------------------------------------------
class message_bus_direct_client_connection : public message_bus_connection {

public:
    message_bus_direct_client_connection(
      std::shared_ptr<message_bus_direct_connection_address>& address) noexcept
      : _weak_address{address}
      , _state{address->connect()} {
    }

    identifier type_id() final {
        return EAGINE_ID(Direct);
    }

    bool is_usable() final {
        _checkup();
        return bool(_state);
    }

    bool send(
      identifier_t class_id,
      identifier_t method_id,
      const message_view& message) final {
        _checkup();
        if(EAGINE_LIKELY(_state)) {
            _state->send_to_server(class_id, method_id, message);
            return true;
        }
        return false;
    }

    void fetch_messages(message_bus_connection::fetch_handler handler) final {
        _checkup();
        if(EAGINE_LIKELY(_state)) {
            _state->fetch_from_server(handler);
        }
    }

private:
    inline void _checkup() {
        if(EAGINE_UNLIKELY(!_state)) {
            if(auto address = _weak_address.lock()) {
                _state = address->connect();
            }
        }
    }

    std::weak_ptr<message_bus_direct_connection_address> _weak_address;
    std::shared_ptr<message_bus_direct_connection_state> _state;
};
//------------------------------------------------------------------------------
class message_bus_direct_server_connection : public message_bus_connection {
public:
    message_bus_direct_server_connection(
      std::shared_ptr<message_bus_direct_connection_state>& state)
      : _weak_state{state} {
    }

    identifier type_id() final {
        return EAGINE_ID(Direct);
    }

    bool send(
      identifier_t class_id,
      identifier_t method_id,
      const message_view& message) final {
        if(auto state = _weak_state.lock()) {
            state->send_to_client(class_id, method_id, message);
            return true;
        }
        return false;
    }

    void fetch_messages(message_bus_connection::fetch_handler handler) final {
        if(auto state = _weak_state.lock()) {
            state->fetch_from_client(handler);
        }
    }

private:
    std::weak_ptr<message_bus_direct_connection_state> _weak_state;
};
//------------------------------------------------------------------------------
class message_bus_direct_acceptor : public message_bus_acceptor {
    using shared_state = std::shared_ptr<message_bus_direct_connection_state>;

public:
    message_bus_direct_acceptor(
      std::shared_ptr<message_bus_direct_connection_address> address) noexcept
      : _address{std::move(address)} {
    }

    message_bus_direct_acceptor()
      : message_bus_direct_acceptor(
          std::make_shared<message_bus_direct_connection_address>()) {
    }

    void process_accepted(const accept_handler& handler) final {
        if(_address) {
            auto wrapped_handler = [this, &handler](shared_state& state) {
                handler(std::unique_ptr<message_bus_connection>{
                  std::make_unique<message_bus_direct_server_connection>(
                    state)});
            };
            _address->process_all(
              message_bus_direct_connection_address::process_handler{
                wrapped_handler});
        }
    }

    std::unique_ptr<message_bus_connection> make_connection() {
        if(_address) {
            return std::unique_ptr<message_bus_connection>{
              std::make_unique<message_bus_direct_client_connection>(_address)};
        }
        return {};
    }

private:
    std::shared_ptr<message_bus_direct_connection_address> _address;
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_MSG_BUS_DIRECT_HPP

