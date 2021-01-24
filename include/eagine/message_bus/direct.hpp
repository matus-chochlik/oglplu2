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

#include "../bool_aggregate.hpp"
#include "../branch_predict.hpp"
#include "../main_ctx_object.hpp"
#include "../value_tracker.hpp"
#include "conn_factory.hpp"
#include <map>
#include <mutex>

namespace eagine::msgbus {
//------------------------------------------------------------------------------
class direct_connection_state : public main_ctx_object {
private:
    std::mutex _s2c_mutex;
    std::mutex _c2s_mutex;
    message_storage _server_to_client;
    message_storage _client_to_server;
    value_change_div_tracker<span_size_t, 16> _s2c_count{0};
    value_change_div_tracker<span_size_t, 16> _c2s_count{0};

public:
    direct_connection_state(main_ctx_parent parent)
      : main_ctx_object{EAGINE_ID(DrctConnSt), parent} {}

    void send_to_server(message_id msg_id, const message_view& message) {
        std::unique_lock lock{_c2s_mutex};
        _client_to_server.push(msg_id, message);
    }

    void send_to_client(message_id msg_id, const message_view& message) {
        std::unique_lock lock{_s2c_mutex};
        _server_to_client.push(msg_id, message);
    }

    auto fetch_from_client(connection::fetch_handler handler) noexcept -> bool {
        std::unique_lock lock{_c2s_mutex};
        return _client_to_server.fetch_all(handler);
    }

    auto fetch_from_server(connection::fetch_handler handler) noexcept -> bool {
        std::unique_lock lock{_s2c_mutex};
        return _server_to_client.fetch_all(handler);
    }

    void log_message_counts() noexcept {
        if constexpr(is_log_level_enabled_v<log_event_severity::stat>) {
            {
                std::unique_lock lock{_s2c_mutex};
                if(_s2c_count.has_changed(_server_to_client.size())) {
                    this->log_chart_sample(
                      EAGINE_ID(s2cMsgCnt), float(_s2c_count.get()));
                }
            }

            {
                std::unique_lock lock{_c2s_mutex};
                if(_c2s_count.has_changed(_client_to_server.size())) {
                    this->log_chart_sample(
                      EAGINE_ID(c2sMsgCnt), float(_c2s_count.get()));
                }
            }
        }
    }
};
//------------------------------------------------------------------------------
class direct_connection_address : public main_ctx_object {
public:
    using shared_state = std::shared_ptr<direct_connection_state>;
    using process_handler = callable_ref<void(shared_state&)>;

private:
    std::vector<shared_state> _pending;

public:
    direct_connection_address(main_ctx_parent parent)
      : main_ctx_object{EAGINE_ID(DrctConnAd), parent} {}

    auto connect() -> shared_state {
        auto state{std::make_shared<direct_connection_state>(*this)};
        _pending.push_back(state);
        return state;
    }

    auto process_all(process_handler handler) -> bool {
        some_true something_done{};
        for(auto& state : _pending) {
            handler(state);
            something_done();
        }
        _pending.clear();
        return something_done;
    }
};
//------------------------------------------------------------------------------
template <typename Base>
class direct_connection_info : public Base {
public:
    using Base::Base;

    auto kind() -> connection_kind final {
        return connection_kind::in_process;
    }

    auto addr_kind() -> connection_addr_kind final {
        return connection_addr_kind::none;
    }

    auto type_id() -> identifier final {
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
            if(auto address{_weak_address.lock()}) {
                _state = address->connect();
            }
        }
    }

public:
    direct_client_connection(
      std::shared_ptr<direct_connection_address>& address) noexcept
      : _weak_address{address}
      , _state{address->connect()} {}

    auto is_usable() -> bool final {
        _checkup();
        return bool(_state);
    }

    auto update() -> bool final {
        if(EAGINE_LIKELY(_state)) {
            _state->log_message_counts();
        }
        return false;
    }

    auto send(message_id msg_id, const message_view& message) -> bool final {
        _checkup();
        if(EAGINE_LIKELY(_state)) {
            _state->send_to_server(msg_id, message);
            return true;
        }
        return false;
    }

    auto fetch_messages(connection::fetch_handler handler) -> bool final {
        _checkup();
        if(EAGINE_LIKELY(_state)) {
            return _state->fetch_from_server(handler);
        }
        return false;
    }

    void cleanup() final {
        if(EAGINE_LIKELY(_state)) {
            _state->log_message_counts();
        }
    }
};
//------------------------------------------------------------------------------
class direct_server_connection : public direct_connection_info<connection> {
private:
    std::weak_ptr<direct_connection_state> _weak_state;

public:
    direct_server_connection(std::shared_ptr<direct_connection_state>& state)
      : _weak_state{state} {}

    auto send(message_id msg_id, const message_view& message) -> bool final {
        if(auto state{_weak_state.lock()}) {
            state->send_to_client(msg_id, message);
            return true;
        }
        return false;
    }

    auto fetch_messages(connection::fetch_handler handler) -> bool final {
        if(auto state{_weak_state.lock()}) {
            return state->fetch_from_client(handler);
        }
        return false;
    }
};
//------------------------------------------------------------------------------
class direct_acceptor
  : public direct_connection_info<acceptor>
  , public main_ctx_object {
    using shared_state = std::shared_ptr<direct_connection_state>;

private:
    std::shared_ptr<direct_connection_address> _address{};

public:
    direct_acceptor(
      main_ctx_parent parent,
      std::shared_ptr<direct_connection_address> address) noexcept
      : main_ctx_object{EAGINE_ID(DrctAccptr), parent}
      , _address{std::move(address)} {}

    direct_acceptor(main_ctx_parent parent)
      : main_ctx_object{EAGINE_ID(DrctAccptr), parent}
      , _address{std::make_shared<direct_connection_address>(*this)} {}

    auto process_accepted(const accept_handler& handler) -> bool final {
        some_true something_done{};
        if(_address) {
            auto wrapped_handler = [&handler](shared_state& state) {
                handler(std::unique_ptr<connection>{
                  std::make_unique<direct_server_connection>(state)});
            };
            something_done(
              _address->process_all({construct_from, wrapped_handler}));
        }
        return something_done;
    }

    auto make_connection() -> std::unique_ptr<connection> {
        if(_address) {
            return std::unique_ptr<connection>{
              std::make_unique<direct_client_connection>(_address)};
        }
        return {};
    }
};
//------------------------------------------------------------------------------
class direct_connection_factory
  : public direct_connection_info<connection_factory>
  , public main_ctx_object {
private:
    std::shared_ptr<direct_connection_address> _default_addr;
    std::map<
      std::string,
      std::shared_ptr<direct_connection_address>,
      basic_str_view_less<std::string, string_view>>
      _addrs;

    auto _make_addr() {
        return std::make_shared<direct_connection_address>(*this);
    }

    auto _get(string_view addr_str) -> auto& {
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

    direct_connection_factory(main_ctx_parent parent)
      : main_ctx_object{EAGINE_ID(DrctConnFc), parent}
      , _default_addr{_make_addr()} {}

    auto make_acceptor(string_view addr_str)
      -> std::unique_ptr<acceptor> final {
        if(addr_str) {
            return std::make_unique<direct_acceptor>(*this, _get(addr_str));
        }
        return std::make_unique<direct_acceptor>(*this, _default_addr);
    }

    auto make_connector(string_view addr_str)
      -> std::unique_ptr<connection> final {
        if(addr_str) {
            return std::make_unique<direct_client_connection>(_get(addr_str));
        }
        return std::make_unique<direct_client_connection>(_default_addr);
    }
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_DIRECT_HPP
