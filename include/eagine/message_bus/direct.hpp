/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

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
/// @brief Common shared state for a direct connection.
/// @ingroup msgbus
/// @note Implementation detail. Do not use directly.
///
/// Connectors and acceptors sharing the same shared state object are "connected".
class direct_connection_state : public main_ctx_object {
public:
    /// @brief Construction from a parent main context object.
    direct_connection_state(main_ctx_parent parent)
      : main_ctx_object{EAGINE_ID(DrctConnSt), parent} {}

    /// @brief Says that the client has connected.
    auto client_connect() {
        std::unique_lock lock{_c2s_mutex};
        _client_connected = true;
    }

    /// @brief Says that the client has disconnected.
    auto client_disconnect() {
        std::unique_lock lock{_c2s_mutex};
        _client_connected = false;
    }

    /// @brief Checks if the connection is usable.
    auto is_usable() {
        std::unique_lock lock{_c2s_mutex};
        return _client_connected || !_client_to_server.empty();
    }

    /// @brief Sends a message to the server counterpart.
    void send_to_server(message_id msg_id, const message_view& message) {
        std::unique_lock lock{_c2s_mutex};
        _client_to_server.push(msg_id, message);
    }

    /// @brief Sends a message to the client counterpart.
    auto send_to_client(message_id msg_id, const message_view& message)
      -> bool {
        std::unique_lock lock{_s2c_mutex};
        if(_client_connected) {
            _server_to_client.push(msg_id, message);
            return true;
        }
        return false;
    }

    /// @brief Fetches received messages from the client counterpart.
    auto fetch_from_client(connection::fetch_handler handler) noexcept
      -> std::tuple<bool, bool> {
        std::unique_lock lock{_c2s_mutex};
        return {_client_to_server.fetch_all(handler), _client_connected};
    }

    /// @brief Fetches received messages from the service counterpart.
    auto fetch_from_server(connection::fetch_handler handler) noexcept -> bool {
        std::unique_lock lock{_s2c_mutex};
        return _server_to_client.fetch_all(handler);
    }

    void log_message_counts() noexcept {
        if constexpr(is_log_level_enabled_v<log_event_severity::stat>) {
            {
                std::unique_lock lock{_s2c_mutex};
                if(_s2c_count.has_changed(_server_to_client.count())) {
                    this->log_chart_sample(
                      EAGINE_ID(s2cMsgCnt), float(_s2c_count.get()));
                }
            }

            {
                std::unique_lock lock{_c2s_mutex};
                if(_c2s_count.has_changed(_client_to_server.count())) {
                    this->log_chart_sample(
                      EAGINE_ID(c2sMsgCnt), float(_c2s_count.get()));
                }
            }
        }
    }

private:
    std::mutex _s2c_mutex;
    std::mutex _c2s_mutex;
    message_storage _server_to_client;
    message_storage _client_to_server;
    value_change_div_tracker<span_size_t, 16> _s2c_count{0};
    value_change_div_tracker<span_size_t, 16> _c2s_count{0};
    bool _client_connected{false};
};
//------------------------------------------------------------------------------
/// @brief Class acting as the "address" of a direct connection.
/// @ingroup msgbus
/// @see direct_acceptor
/// @see direct_client_connection
/// @see direct_server_connection
/// @see direct_connection_factory
///
class direct_connection_address : public main_ctx_object {
public:
    /// @brief Alias for shared pointer to direct state type.
    using shared_state = std::shared_ptr<direct_connection_state>;

    /// @brief Alias for shared state accept handler callable.
    /// @see process_all
    using process_handler = callable_ref<void(shared_state&)>;

    /// @brief Construction from a parent main context object.
    direct_connection_address(main_ctx_parent parent)
      : main_ctx_object{EAGINE_ID(DrctConnAd), parent} {}

    /// @brief Creates and returns the shared state for a new client connection.
    /// @see process_all
    auto connect() -> shared_state {
        auto state{std::make_shared<direct_connection_state>(*this)};
        _pending.push_back(state);
        return state;
    }

    /// @brief Handles the pending server counterparts for created client connections.
    /// @see connect
    auto process_all(process_handler handler) -> bool {
        some_true something_done{};
        for(auto& state : _pending) {
            handler(state);
            something_done();
        }
        _pending.clear();
        return something_done;
    }

private:
    std::vector<shared_state> _pending;
};
//------------------------------------------------------------------------------
/// @brief Implementation of the connection_info interface for direct connections.
/// @ingroup msgbus
/// @see direct_client_connection
/// @see direct_server_connection
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
/// @brief Implementation of client-side direct connection.
/// @ingroup msgbus
/// @see direct_server_connection
/// @see direct_acceptor
/// @see direct_connection_factory
class direct_client_connection : public direct_connection_info<connection> {
public:
    direct_client_connection(
      std::shared_ptr<direct_connection_address>& address) noexcept
      : _weak_address{address}
      , _state{address->connect()} {
        if(EAGINE_LIKELY(_state)) {
            _state->client_connect();
        }
    }

    direct_client_connection(direct_client_connection&&) = delete;
    direct_client_connection(const direct_client_connection&) = delete;
    auto operator=(direct_client_connection&&) = delete;
    auto operator=(const direct_client_connection&) = delete;

    ~direct_client_connection() noexcept final {
        if(EAGINE_LIKELY(_state)) {
            _state->client_disconnect();
        }
    }

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

    auto query_statistics(connection_statistics& stats) -> bool final {
        stats.block_usage_ratio = 1.F;
        return true;
    }

    void cleanup() final {
        if(EAGINE_LIKELY(_state)) {
            _state->log_message_counts();
        }
    }

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
};
//------------------------------------------------------------------------------
/// @brief Implementation of server-side direct connection.
/// @ingroup msgbus
/// @see direct_client_connection
/// @see direct_acceptor
/// @see direct_connection_factory
class direct_server_connection : public direct_connection_info<connection> {
public:
    direct_server_connection(std::shared_ptr<direct_connection_state>& state)
      : _state{state} {}

    auto is_usable() -> bool final {
        if(EAGINE_LIKELY(_state)) {
            if(EAGINE_LIKELY(_is_usable)) {
                return true;
            }
            _state.reset();
        }
        return false;
    }

    auto send(message_id msg_id, const message_view& message) -> bool final {
        if(EAGINE_LIKELY(_state)) {
            return _state->send_to_client(msg_id, message);
        }
        return false;
    }

    auto fetch_messages(connection::fetch_handler handler) -> bool final {
        bool result = false;
        if(EAGINE_LIKELY(_state)) {
            std::tie(result, _is_usable) = _state->fetch_from_client(handler);
        }
        return result;
    }

    auto query_statistics(connection_statistics&) -> bool final {
        return false;
    }

private:
    std::shared_ptr<direct_connection_state> _state;
    bool _is_usable{true};
};
//------------------------------------------------------------------------------
/// @brief Implementation of acceptor for direct connections.
/// @ingroup msgbus
/// @see direct_connection_factory
class direct_acceptor
  : public direct_connection_info<acceptor>
  , public main_ctx_object {
    using shared_state = std::shared_ptr<direct_connection_state>;

public:
    /// @brief Construction from a parent main context object and an address object.
    direct_acceptor(
      main_ctx_parent parent,
      std::shared_ptr<direct_connection_address> address) noexcept
      : main_ctx_object{EAGINE_ID(DrctAccptr), parent}
      , _address{std::move(address)} {}

    /// @brief Construction from a parent main context object with implicit address.
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

    /// @brief Makes a new client-side direct connection.
    auto make_connection() -> std::unique_ptr<connection> {
        if(_address) {
            return std::unique_ptr<connection>{
              std::make_unique<direct_client_connection>(_address)};
        }
        return {};
    }

private:
    std::shared_ptr<direct_connection_address> _address{};
};
//------------------------------------------------------------------------------
/// @brief Implementation of connection_factory for direct connections.
/// @ingroup msgbus
/// @see direct_acceptor
class direct_connection_factory
  : public direct_connection_info<connection_factory>
  , public main_ctx_object {
public:
    using connection_factory::make_acceptor;
    using connection_factory::make_connector;

    /// @brief Construction from a parent main context object with implicit address.
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

private:
    std::shared_ptr<direct_connection_address> _default_addr;
    std::map<
      std::string,
      std::shared_ptr<direct_connection_address>,
      basic_str_view_less<std::string, string_view>>
      _addrs;

    auto _make_addr() -> std::shared_ptr<direct_connection_address> {
        return std::make_shared<direct_connection_address>(*this);
    }

    auto _get(string_view addr_str)
      -> std::shared_ptr<direct_connection_address>& {
        auto pos = _addrs.find(addr_str);
        if(pos == _addrs.end()) {
            pos = _addrs.emplace(to_string(addr_str), _make_addr()).first;
        }
        EAGINE_ASSERT(pos != _addrs.end());
        return pos->second;
    }
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_DIRECT_HPP
