/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/branch_predict.hpp>
#include <eagine/timeout.hpp>

namespace eagine::msgbus {
//------------------------------------------------------------------------------
class remote_instance_impl {
public:
    optionally_valid<build_info> bld_info;
    host_id_t host_id{0U};
};
//------------------------------------------------------------------------------
class remote_host_impl {
public:
    std::string hostname;
};
//------------------------------------------------------------------------------
class remote_node_impl {
public:
    process_instance_id_t instance_id{0U};
    optionally_valid<endpoint_info> ept_info;
    host_id_t host_id{0U};

    timeout should_ping{std::chrono::seconds{15}};
    span_size_t pings_sent{0};
    span_size_t pings_responded{0};
    span_size_t pings_timeouted{0};
    std::chrono::microseconds last_ping_time{};
    std::chrono::microseconds last_ping_timeout{};
    std::uint8_t ping_bits{0};
    node_kind kind{node_kind::unknown};

    remote_node_changes changes{};

    auto get_sub(message_id msg_id) const noexcept -> tribool {
        auto pos = _subscriptions.find(msg_id);
        if(pos != _subscriptions.end()) {
            return pos->second;
        }
        return indeterminate;
    }

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
// remote_instance
//------------------------------------------------------------------------------
inline auto remote_instance::_impl() const noexcept
  -> const remote_instance_impl* {
    return _pimpl.get();
}
//------------------------------------------------------------------------------
inline auto remote_instance::_impl() noexcept -> remote_instance_impl* {
    try {
        if(EAGINE_UNLIKELY(!_pimpl)) {
            _pimpl = std::make_shared<remote_instance_impl>();
        }
        return _pimpl.get();
    } catch(...) {
    }
    return nullptr;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_instance::host() const noexcept -> remote_host {
    if(auto impl{_impl()}) {
        auto& i = extract(impl);
        if(i.host_id) {
            return _tracker.get_host(i.host_id);
        }
    }
    return {};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_instance::build() const noexcept
  -> optional_reference_wrapper<const build_info> {
    if(auto impl{_impl()}) {
        auto& i = extract(impl);
        if(i.bld_info) {
            return {extract(i.bld_info)};
        }
    }
    return {nothing};
}
//------------------------------------------------------------------------------
// remote_instance_state
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_instance_state::set_host_id(host_id_t host_id)
  -> remote_instance_state& {
    if(auto impl{_impl()}) {
        auto& i = extract(impl);
        if(i.host_id != host_id) {
            i.host_id = host_id;
        }
    }
    return *this;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_instance_state::assign(build_info info) -> remote_instance_state& {
    if(auto impl{_impl()}) {
        auto& i = extract(impl);
        if(!i.bld_info) {
            i.bld_info = {std::move(info), true};
        }
    }
    return *this;
}
//------------------------------------------------------------------------------
// remote_host
//------------------------------------------------------------------------------
inline auto remote_host::_impl() const noexcept -> const remote_host_impl* {
    return _pimpl.get();
}
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
auto remote_host::name() const noexcept -> valid_if_not_empty<string_view> {
    if(auto impl{_impl()}) {
        return {extract(impl).hostname};
    }
    return {};
}
//------------------------------------------------------------------------------
// remote_node
//------------------------------------------------------------------------------
inline auto remote_node::_impl() const noexcept -> const remote_node_impl* {
    return _pimpl.get();
}
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
auto remote_node::instance_id() const noexcept
  -> valid_if_not_zero<process_instance_id_t> {
    if(auto impl{_impl()}) {
        return {extract(impl).instance_id};
    }
    return {0U};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_node::kind() const noexcept -> node_kind {
    if(auto impl{_impl()}) {
        return extract(impl).kind;
    }
    return node_kind::unknown;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_node::info() const noexcept
  -> optional_reference_wrapper<const endpoint_info> {
    if(auto impl{_impl()}) {
        auto& i = extract(impl);
        if(i.ept_info) {
            return {extract(i.ept_info)};
        }
    }
    return {nothing};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_node::host_id() const noexcept -> valid_if_not_zero<host_id_t> {
    if(auto impl{_impl()}) {
        return extract(impl).host_id;
    }
    return {0U};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_node::host() const noexcept -> remote_host {
    if(auto impl{_impl()}) {
        auto& i = extract(impl);
        if(i.host_id) {
            return _tracker.get_host(i.host_id);
        }
        if(auto inst{instance()}) {
            return inst.host();
        }
    }
    return {};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_node::instance() const noexcept -> remote_instance {
    if(auto impl{_impl()}) {
        return _tracker.get_instance(extract(impl).instance_id);
    }
    return {};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_node::subscribes_to(message_id msg_id) const noexcept -> tribool {
    if(auto impl{_impl()}) {
        return extract(impl).get_sub(msg_id);
    }
    return indeterminate;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_node::is_pingable() const noexcept -> tribool {
    if(auto impl{_impl()}) {
        auto& i = extract(impl);
        if(i.kind == node_kind::router || i.kind == node_kind::bridge) {
            return true;
        }
        return extract(impl).get_sub(EAGINE_MSGBUS_ID(ping));
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
auto remote_node::ping_success_rate() const noexcept
  -> valid_if_between_0_1<float> {
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
EAGINE_LIB_FUNC
auto remote_node::is_responsive() const noexcept -> tribool {
    if(auto impl{_impl()}) {
        return bool(extract(impl).ping_bits);
    }
    return indeterminate;
}
//------------------------------------------------------------------------------
// remote_node_state
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_node_state::changes() -> remote_node_changes {
    if(auto impl{_impl()}) {
        auto& i = extract(impl);
        const auto result = i.changes;
        i.changes.clear();
        return result;
    }
    return {};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_node_state::add_change(remote_node_change change)
  -> remote_node_state& {
    if(auto impl{_impl()}) {
        extract(impl).changes |= change;
    }
    return *this;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_node_state::set_instance_id(process_instance_id_t instance_id)
  -> remote_node_state& {
    if(auto impl{_impl()}) {
        auto& i = extract(impl);
        if(i.instance_id != instance_id) {
            i.instance_id = instance_id;
            i.changes |= remote_node_change::instance_id;
        }
    }
    return *this;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_node_state::set_host_id(host_id_t host_id) -> remote_node_state& {
    if(auto impl{_impl()}) {
        auto& i = extract(impl);
        if(i.host_id != host_id) {
            i.host_id = host_id;
            i.changes |= remote_node_change::host_info;
            if(i.instance_id) {
                _tracker.get_instance(i.instance_id).set_host_id(host_id);
            }
        }
    }
    return *this;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_node_state::assign(node_kind kind) -> remote_node_state& {
    if(auto impl{_impl()}) {
        auto& i = extract(impl);
        if(i.kind != kind) {
            i.kind = kind;
            i.changes |= remote_node_change::kind;
        }
    }
    return *this;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_node_state::assign(endpoint_info info) -> remote_node_state& {
    if(auto impl{_impl()}) {
        auto& i = extract(impl);
        if(!i.ept_info || extract(i.ept_info) != info) {
            i.ept_info = {std::move(info), true};
            i.changes |= remote_node_change::endpoint_info;
        }
    }
    return *this;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_node_state::add_subscription(message_id msg_id)
  -> remote_node_state& {
    if(auto impl{_impl()}) {
        auto& i = extract(impl);
        auto& s = i.get_sub(msg_id);
        if(!s.is(true)) {
            s = true;
            i.changes |= remote_node_change::methods_added;
        }
    }
    return *this;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_node_state::remove_subscription(message_id msg_id)
  -> remote_node_state& {
    if(auto impl{_impl()}) {
        auto& i = extract(impl);
        auto& s = i.get_sub(msg_id);
        if(!s.is(false)) {
            s = false;
            i.changes |= remote_node_change::methods_removed;
        }
    }
    return *this;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_node_state::should_ping()
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
auto remote_node_state::is_alive() -> remote_node_state& {
    if(auto impl{_impl()}) {
        auto& i = extract(impl);
        const auto was_responsive = bool(i.ping_bits);
        i.ping_bits <<= 1U;
        i.ping_bits |= 1U;
        if(was_responsive != bool(i.ping_bits)) {
            i.changes |= remote_node_change::started_responding;
        }
    }
    return *this;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_node_state::pinged() -> remote_node_state& {
    if(auto impl{_impl()}) {
        auto& i = extract(impl);
        i.should_ping.reset();
        ++i.pings_sent;
    }
    return *this;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_node_state::ping_response(
  message_sequence_t,
  std::chrono::microseconds age) -> remote_node_state& {
    if(auto impl{_impl()}) {
        auto& i = extract(impl);
        const auto was_responsive = bool(i.ping_bits);
        i.last_ping_time = age;
        i.ping_bits <<= 1U;
        i.ping_bits |= 1U;
        ++i.pings_responded;
        if(was_responsive != bool(i.ping_bits)) {
            i.changes |= remote_node_change::started_responding;
        }
    }
    return *this;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_node_state::ping_timeout(
  message_sequence_t,
  std::chrono::microseconds age) -> remote_node_state& {
    if(auto impl{_impl()}) {
        auto& i = extract(impl);
        const auto was_responsive = bool(i.ping_bits);
        i.last_ping_timeout = age;
        i.ping_bits <<= 1U;
        ++i.pings_timeouted;
        if(was_responsive != bool(i.ping_bits)) {
            i.changes |= remote_node_change::stopped_responding;
        }
    }
    return *this;
}
//------------------------------------------------------------------------------
// remote_host_state
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_host_state::set_hostname(std::string hn) -> remote_host_state& {
    try {
        if(auto impl{_impl()}) {
            extract(impl).hostname = std::move(hn);
        }
    } catch(...) {
    }
    return *this;
}
//------------------------------------------------------------------------------
// remote_node_tracker
//------------------------------------------------------------------------------
class remote_node_tracker_impl {
public:
    flat_map<identifier_t, remote_node_state> nodes;
    flat_map<process_instance_id_t, remote_instance_state> instances;
    flat_map<host_id_t, remote_host_state> hosts;
};
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
remote_node_tracker::remote_node_tracker()
  : _pimpl{std::make_shared<remote_node_tracker_impl>()} {}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_node_tracker::get_nodes() noexcept
  -> flat_map<identifier_t, remote_node_state>& {
    EAGINE_ASSERT(_pimpl);
    return _pimpl->nodes;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_node_tracker::get_hosts() noexcept
  -> flat_map<host_id_t, remote_host_state>& {
    EAGINE_ASSERT(_pimpl);
    return _pimpl->hosts;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_node_tracker::get_node(identifier_t node_id) -> remote_node_state& {
    EAGINE_ASSERT(_pimpl);
    auto pos = _pimpl->nodes.find(node_id);
    if(pos == _pimpl->nodes.end()) {
        pos = _pimpl->nodes.emplace(node_id, node_id, _pimpl).first;
    }
    EAGINE_ASSERT(pos->second.id() == node_id);
    return pos->second;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_node_tracker::get_host(host_id_t host_id) -> remote_host_state& {
    EAGINE_ASSERT(_pimpl);
    auto pos = _pimpl->hosts.find(host_id);
    if(pos == _pimpl->hosts.end()) {
        pos = _pimpl->hosts.emplace(host_id, host_id).first;
    }
    EAGINE_ASSERT(pos->second.id() == host_id);
    return pos->second;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_node_tracker::get_host(host_id_t host_id) const
  -> remote_host_state {
    EAGINE_ASSERT(_pimpl);
    auto pos = _pimpl->hosts.find(host_id);
    if(pos != _pimpl->hosts.end()) {
        return pos->second;
    }
    return {};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_node_tracker::get_instance(process_instance_id_t instance_id)
  -> remote_instance_state& {
    EAGINE_ASSERT(_pimpl);
    auto pos = _pimpl->instances.find(instance_id);
    if(pos == _pimpl->instances.end()) {
        pos = _pimpl->instances.emplace(instance_id, instance_id, _pimpl).first;
    }
    EAGINE_ASSERT(pos->second.id() == instance_id);
    return pos->second;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_node_tracker::get_instance(process_instance_id_t instance_id) const
  -> remote_instance_state {
    EAGINE_ASSERT(_pimpl);
    auto pos = _pimpl->instances.find(instance_id);
    if(pos != _pimpl->instances.end()) {
        return pos->second;
    }
    return {};
}
//------------------------------------------------------------------------------
} // namespace eagine::msgbus
