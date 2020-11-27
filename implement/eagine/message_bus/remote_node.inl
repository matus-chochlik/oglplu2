/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/branch_predict.hpp>
#include <eagine/flat_map.hpp>
#include <eagine/timeout.hpp>

namespace eagine::msgbus {
//------------------------------------------------------------------------------
class remote_host_impl {
public:
    std::string hostname;
};
//------------------------------------------------------------------------------
class remote_node_impl {
public:
    remote_host host;

    timeout should_ping{std::chrono::seconds{15}};
    span_size_t pings_sent{0};
    span_size_t pings_responded{0};
    span_size_t pings_timeouted{0};
    std::chrono::microseconds last_ping_age{};

    auto get_sub(message_id msg_id) -> tribool& {
        auto pos = _subscriptions.find(msg_id);
        if(pos == _subscriptions.end()) {
            pos = _subscriptions.emplace(msg_id, indeterminate).first;
        }
        return pos->second;
    }

private:
    flat_map<message_id, tribool> _subscriptions;
};
//------------------------------------------------------------------------------
// remote_host
//------------------------------------------------------------------------------
inline auto remote_host::_impl() noexcept -> remote_host_impl* {
    try {
        if(EAGINE_UNLIKELY(!_pimpl)) {
            _pimpl = std::make_shared<remote_host_impl>();
        }
        return _pimpl.get();
    } catch(...) {
    }
    return nullptr;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_host::hostname() noexcept -> valid_if_not_empty<string_view> {
    if(auto impl{_impl()}) {
        return {extract(impl).hostname};
    }
    return {};
}
//------------------------------------------------------------------------------
// remote_node
//------------------------------------------------------------------------------
inline auto remote_node::_impl() noexcept -> remote_node_impl* {
    try {
        if(EAGINE_UNLIKELY(!_pimpl)) {
            _pimpl = std::make_shared<remote_node_impl>();
        }
        return _pimpl.get();
    } catch(...) {
    }
    return _pimpl.get();
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_node::host_id() noexcept -> valid_if_not_zero<identifier_t> {
    if(auto impl{_impl()}) {
        return extract(impl).host.id();
    }
    return {0U};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_node::host() noexcept -> remote_host {
    if(auto impl{_impl()}) {
        return extract(impl).host;
    }
    return {};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_node::subscribes_to(message_id msg_id) noexcept -> tribool {
    if(auto impl{_impl()}) {
        try {
            return extract(impl).get_sub(msg_id);
        } catch(...) {
        }
    }
    return indeterminate;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void remote_node::set_ping_interval(std::chrono::milliseconds ms) noexcept {
    if(auto impl{_impl()}) {
        extract(impl).should_ping.reset(ms, nothing);
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_node::ping_success_rate() noexcept -> valid_if_between_0_1<float> {
    if(auto impl{_impl()}) {
        if(extract(impl).pings_sent > 0) {
            return {
              float(extract(impl).pings_responded) /
              float(extract(impl).pings_sent)};
        }
    }
    return {-1.F};
}
//------------------------------------------------------------------------------
// remote_node_state
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void remote_node_state::assign(remote_host host) {
    if(auto impl{_impl()}) {
        extract(impl).host = std::move(host);
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void remote_node_state::add_subscription(message_id msg_id) {
    if(auto impl{_impl()}) {
        extract(impl).get_sub(msg_id) = true;
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void remote_node_state::remove_subscription(message_id msg_id) {
    if(auto impl{_impl()}) {
        extract(impl).get_sub(msg_id) = false;
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_node_state::should_ping() noexcept
  -> std::tuple<bool, std::chrono::milliseconds> {
    if(auto impl{_impl()}) {
        auto& to = extract(impl).should_ping;
        return {
          to.is_expired(),
          std::chrono::duration_cast<std::chrono::milliseconds>(
            to.period() / 4)};
    }
    return {false, {}};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void remote_node_state::pinged() noexcept {
    if(auto impl{_impl()}) {
        extract(impl).should_ping.reset();
        ++extract(impl).pings_sent;
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void remote_node_state::ping_response(
  message_sequence_t,
  std::chrono::microseconds age) {
    if(auto impl{_impl()}) {
        extract(impl).last_ping_age = age;
        ++extract(impl).pings_responded;
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void remote_node_state::ping_timeout(
  message_sequence_t,
  std::chrono::microseconds) {
    if(auto impl{_impl()}) {
        ++extract(impl).pings_timeouted;
    }
}
//------------------------------------------------------------------------------
// remote_host_state
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void remote_host_state::set_hostname(std::string hn) {
    try {
        if(auto impl{_impl()}) {
            extract(impl).hostname = std::move(hn);
        }
    } catch(...) {
    }
}
//------------------------------------------------------------------------------
} // namespace eagine::msgbus
