/**
 *  @file eagine/message_bus/direct.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MESSAGE_BUS_DIRECT_HPP
#define EAGINE_MESSAGE_BUS_DIRECT_HPP

#include "../branch_predict.hpp"
#include "../logging/logger.hpp"
#include "conn_factory.hpp"
#include <map>
#include <mutex>

namespace eagine {
namespace msgbus {
//------------------------------------------------------------------------------
class direct_connection_state {
private:
    logger _log{};
    std::mutex _mutex;
    message_storage _server_to_client;
    message_storage _client_to_server;

public:
    direct_connection_state(logger& parent)
      : _log{EAGINE_ID(DrctConnSt), parent} {
    }

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

    void fetch_from_client(connection::fetch_handler handler) noexcept {
        std::unique_lock lock{_mutex};
        _client_to_server.fetch_all(handler);
    }

    void fetch_from_server(connection::fetch_handler handler) noexcept {
        std::unique_lock lock{_mutex};
        _server_to_client.fetch_all(handler);
    }
};
//------------------------------------------------------------------------------
class direct_connection_address {
public:
    using shared_state = std::shared_ptr<direct_connection_state>;
    using process_handler = callable_ref<void(shared_state&)>;

private:
    logger _log{};
    std::vector<shared_state> _pending;

public:
    direct_connection_address(logger& parent)
      : _log{EAGINE_ID(DrctConnAd), parent} {
    }

    shared_state connect() {
        auto state = std::make_shared<direct_connection_state>(_log);
        _pending.push_back(state);
        return state;
    }

    void process_all(process_handler handler) {
        for(auto& state : _pending) {
            handler(state);
        }
        _pending.clear();
    }
};
//------------------------------------------------------------------------------
template <typename Base>
class direct_connection_info : public Base {
public:
    using Base::Base;

    connection_kind kind() final {
        return connection_kind::in_process;
    }

    identifier type_id() final {
        return EAGINE_ID(Direct);
    }
};
//------------------------------------------------------------------------------
class direct_client_connection : public direct_connection_info<connection> {

private:
    std::weak_ptr<direct_connection_address> _weak_address;
    std::shared_ptr<direct_connection_state> _state;

    inline void _checkup() {
        if(EAGINE_UNLIKELY(!_state)) {
            if(auto address = _weak_address.lock()) {
                _state = address->connect();
            }
        }
    }

public:
    direct_client_connection(
      std::shared_ptr<direct_connection_address>& address) noexcept
      : _weak_address{address}
      , _state{address->connect()} {
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

    void fetch_messages(connection::fetch_handler handler) final {
        _checkup();
        if(EAGINE_LIKELY(_state)) {
            _state->fetch_from_server(handler);
        }
    }
};
//------------------------------------------------------------------------------
class direct_server_connection : public direct_connection_info<connection> {
private:
    std::weak_ptr<direct_connection_state> _weak_state;

public:
    direct_server_connection(std::shared_ptr<direct_connection_state>& state)
      : _weak_state{state} {
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

    void fetch_messages(connection::fetch_handler handler) final {
        if(auto state = _weak_state.lock()) {
            state->fetch_from_client(handler);
        }
    }
};
//------------------------------------------------------------------------------
class direct_acceptor : public acceptor {
    using shared_state = std::shared_ptr<direct_connection_state>;

private:
    logger _log{};
    std::shared_ptr<direct_connection_address> _address;

public:
    direct_acceptor(
      logger& parent,
      std::shared_ptr<direct_connection_address> address) noexcept
      : _log{EAGINE_ID(DrctAccptr), parent}
      , _address{std::move(address)} {
    }

    direct_acceptor(logger& parent)
      : _log{EAGINE_ID(DrctAccptr), parent}
      , _address{std::make_shared<direct_connection_address>(_log)} {
    }

    direct_acceptor()
      : _address{std::make_shared<direct_connection_address>(_log)} {
    }

    void process_accepted(const accept_handler& handler) final {
        if(_address) {
            auto wrapped_handler = [&handler](shared_state& state) {
                handler(std::unique_ptr<connection>{
                  std::make_unique<direct_server_connection>(state)});
            };
            _address->process_all(
              direct_connection_address::process_handler{wrapped_handler});
        }
    }

    std::unique_ptr<connection> make_connection() {
        if(_address) {
            return std::unique_ptr<connection>{
              std::make_unique<direct_client_connection>(_address)};
        }
        return {};
    }
};
//------------------------------------------------------------------------------
class direct_connection_factory
  : public direct_connection_info<connection_factory> {
private:
    logger _log{};
    std::shared_ptr<direct_connection_address> _default_addr;
    std::map<
      std::string,
      std::shared_ptr<direct_connection_address>,
      basic_str_view_less<std::string, string_view>>
      _addrs;

    auto _make_addr() {
        return std::make_shared<direct_connection_address>(_log);
    }

    auto& _get(string_view addr_str) {
        auto pos = _addrs.find(addr_str);
        if(pos == _addrs.end()) {
            pos = _addrs.emplace(to_string(addr_str), _make_addr()).first;
        }
        EAGINE_ASSERT(pos != _addrs.end());
        return pos->second;
    }

public:
    using connection_factory::make_acceptor;
    using connection_factory::make_connector;

    direct_connection_factory(logger& parent)
      : _log{EAGINE_ID(DrctConnFc), parent}
      , _default_addr{_make_addr()} {
    }

    std::unique_ptr<acceptor> make_acceptor(string_view addr_str) final {
        if(addr_str) {
            return std::make_unique<direct_acceptor>(_log, _get(addr_str));
        }
        return std::make_unique<direct_acceptor>(_log, _default_addr);
    }

    std::unique_ptr<connection> make_connector(string_view addr_str) final {
        if(addr_str) {
            return std::make_unique<direct_client_connection>(_get(addr_str));
        }
        return std::make_unique<direct_client_connection>(_default_addr);
    }
};
//------------------------------------------------------------------------------
} // namespace msgbus
} // namespace eagine

#endif // EAGINE_MESSAGE_BUS_DIRECT_HPP

