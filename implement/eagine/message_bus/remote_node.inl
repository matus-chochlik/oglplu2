/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <eagine/branch_predict.hpp>
#include <eagine/timeout.hpp>
#include <set>

namespace eagine::msgbus {
//------------------------------------------------------------------------------
class remote_instance_impl {
public:
    timeout is_alive{std::chrono::seconds{180}};
    optionally_valid<build_info> bld_info;
    host_id_t host_id{0U};
};
//------------------------------------------------------------------------------
class remote_host_impl {
public:
    timeout is_alive{std::chrono::seconds{300}};
    timeout should_query_sensors{std::chrono::seconds{30}};
    std::string hostname;
    span_size_t cpu_concurrent_threads{-1};
    float short_average_load{-1.F};
    float long_average_load{-1.F};
    span_size_t total_ram_size{-1};
    span_size_t free_ram_size{-1};
    span_size_t total_swap_size{-1};
    span_size_t free_swap_size{-1};

    remote_host_changes changes{};
};
//------------------------------------------------------------------------------
class remote_node_impl {
public:
    process_instance_id_t instance_id{0U};
    string_view app_name;
    string_view display_name;
    string_view description;
    tribool is_router_node{indeterminate};
    tribool is_bridge_node{indeterminate};
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

    void clear() noexcept {
        *this = remote_node_impl();
    }

private:
    flat_map<message_id, tribool> _subscriptions;
};
//------------------------------------------------------------------------------
class node_connection_impl {
public:
    connection_kind kind{connection_kind::unknown};
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
auto remote_instance::is_alive() const noexcept -> bool {
    if(auto impl{_impl()}) {
        return !extract(impl).is_alive.is_expired();
    }
    return false;
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
auto remote_instance_state::notice_alive() -> remote_instance_state& {
    if(auto impl{_impl()}) {
        extract(impl).is_alive.reset();
    }
    return *this;
}
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
auto remote_host_state::changes() -> remote_host_changes {
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
auto remote_host_state::add_change(remote_host_change change)
  -> remote_host_state& {
    if(auto impl{_impl()}) {
        extract(impl).changes |= change;
    }
    return *this;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_host::is_alive() const noexcept -> bool {
    if(auto impl{_impl()}) {
        return !extract(impl).is_alive.is_expired();
    }
    return false;
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
EAGINE_LIB_FUNC
auto remote_host::cpu_concurrent_threads() const noexcept
  -> valid_if_positive<span_size_t> {
    if(auto impl{_impl()}) {
        return {extract(impl).cpu_concurrent_threads};
    }
    return {};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_host::short_average_load() const noexcept
  -> valid_if_nonnegative<float> {
    if(auto impl{_impl()}) {
        return {extract(impl).short_average_load};
    }
    return {};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_host::long_average_load() const noexcept
  -> valid_if_nonnegative<float> {
    if(auto impl{_impl()}) {
        return {extract(impl).long_average_load};
    }
    return {};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_host::total_ram_size() const noexcept
  -> valid_if_positive<span_size_t> {
    if(auto impl{_impl()}) {
        return {extract(impl).total_ram_size};
    }
    return {-1};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_host::free_ram_size() const noexcept
  -> valid_if_positive<span_size_t> {
    if(auto impl{_impl()}) {
        return {extract(impl).free_ram_size};
    }
    return {-1};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_host::total_swap_size() const noexcept
  -> valid_if_positive<span_size_t> {
    if(auto impl{_impl()}) {
        return {extract(impl).total_swap_size};
    }
    return {-1};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_host::free_swap_size() const noexcept
  -> valid_if_nonnegative<span_size_t> {
    if(auto impl{_impl()}) {
        return {extract(impl).free_swap_size};
    }
    return {-1};
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
auto remote_node::has_endpoint_info() const noexcept -> bool {
    if(auto impl{_impl()}) {
        auto& i = extract(impl);
        return !i.app_name.empty() && !i.display_name.empty() &&
               !i.is_router_node.is(indeterminate) &&
               !i.is_bridge_node.is(indeterminate);
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_node::app_name() const noexcept -> valid_if_not_empty<string_view> {
    if(auto impl{_impl()}) {
        return extract(impl).app_name;
    }
    return {};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_node::display_name() const noexcept
  -> valid_if_not_empty<string_view> {
    if(auto impl{_impl()}) {
        return extract(impl).display_name;
    }
    return {};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_node::description() const noexcept
  -> valid_if_not_empty<string_view> {
    if(auto impl{_impl()}) {
        return extract(impl).description;
    }
    return {};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_node::is_router_node() const noexcept -> tribool {
    if(auto impl{_impl()}) {
        auto& i = extract(impl);
        const auto k = i.kind;
        if((k == node_kind::router) || (k == node_kind::bridge)) {
            return false;
        }
        return i.is_router_node;
    }
    return indeterminate;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_node::is_bridge_node() const noexcept -> tribool {
    if(auto impl{_impl()}) {
        auto& i = extract(impl);
        const auto k = i.kind;
        if((k == node_kind::router) || (k == node_kind::bridge)) {
            return false;
        }
        return i.is_bridge_node;
    }
    return indeterminate;
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
auto remote_node::connections() const noexcept -> node_connections {
    std::vector<identifier_t> remote_ids;
    _tracker.for_each_connection([&](const auto& conn) {
        if(auto remote_id{conn.opposite_id(_node_id)}) {
            remote_ids.push_back(extract(remote_id));
        }
    });
    return {_node_id, std::move(remote_ids), _tracker};
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
auto remote_node_state::clear() noexcept -> remote_node_state& {
    if(auto impl{_impl()}) {
        extract(impl).clear();
    }
    return *this;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_node_state::host_state() const noexcept -> remote_host_state {
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
            i.changes |= remote_node_change::host_id;
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
auto remote_node_state::assign(const endpoint_info& info)
  -> remote_node_state& {
    if(auto impl{_impl()}) {
        auto& i = extract(impl);
        auto app_name = _tracker.cached(info.app_name);
        if(!are_equal(app_name, i.app_name)) {
            i.app_name = app_name;
            i.changes |= remote_node_change::endpoint_info;
        }
        auto display_name = _tracker.cached(info.display_name);
        if(!are_equal(display_name, i.display_name)) {
            i.display_name = display_name;
            i.changes |= remote_node_change::endpoint_info;
        }
        auto description = _tracker.cached(info.description);
        if(!are_equal(description, i.description)) {
            i.description = description;
            i.changes |= remote_node_change::endpoint_info;
        }
        if(i.is_router_node.is(indeterminate)) {
            i.is_router_node = info.is_router_node;
            i.changes |= remote_node_change::endpoint_info;
        }
        if(i.is_bridge_node.is(indeterminate)) {
            i.is_bridge_node = info.is_bridge_node;
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
            to.period() * 2)};
    }
    return {false, {}};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_node_state::notice_alive() -> remote_node_state& {
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
        ++i.pings_sent;
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
        ++i.pings_sent;
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
auto remote_host_state::should_query_sensors() -> bool {
    if(auto impl{_impl()}) {
        return extract(impl).should_query_sensors.is_expired();
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_host_state::sensors_queried() -> remote_host_state& {
    if(auto impl{_impl()}) {
        extract(impl).should_query_sensors.reset();
    }
    return *this;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_host_state::notice_alive() -> remote_host_state& {
    if(auto impl{_impl()}) {
        extract(impl).is_alive.reset();
    }
    return *this;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_host_state::set_hostname(std::string hn) -> remote_host_state& {
    if(auto impl{_impl()}) {
        auto& i = extract(impl);
        i.hostname = std::move(hn);
        i.changes |= remote_host_change::hostname;
    }
    return *this;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_host_state::set_cpu_concurrent_threads(span_size_t value)
  -> remote_host_state& {
    if(auto impl{_impl()}) {
        auto& i = extract(impl);
        i.cpu_concurrent_threads = value;
        i.changes |= remote_host_change::hardware_config;
    }
    return *this;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_host_state::set_short_average_load(float value)
  -> remote_host_state& {
    if(auto impl{_impl()}) {
        auto& i = extract(impl);
        i.short_average_load = value;
        i.changes |= remote_host_change::sensor_values;
    }
    return *this;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_host_state::set_long_average_load(float value)
  -> remote_host_state& {
    if(auto impl{_impl()}) {
        auto& i = extract(impl);
        i.long_average_load = value;
        i.changes |= remote_host_change::sensor_values;
    }
    return *this;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_host_state::set_total_ram_size(span_size_t value)
  -> remote_host_state& {
    if(auto impl{_impl()}) {
        auto& i = extract(impl);
        i.total_ram_size = value;
        i.changes |= remote_host_change::hardware_config;
    }
    return *this;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_host_state::set_total_swap_size(span_size_t value)
  -> remote_host_state& {
    if(auto impl{_impl()}) {
        auto& i = extract(impl);
        i.total_swap_size = value;
        i.changes |= remote_host_change::hardware_config;
    }
    return *this;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_host_state::set_free_ram_size(span_size_t value)
  -> remote_host_state& {
    if(auto impl{_impl()}) {
        auto& i = extract(impl);
        i.free_ram_size = value;
        i.changes |= remote_host_change::sensor_values;
    }
    return *this;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_host_state::set_free_swap_size(span_size_t value)
  -> remote_host_state& {
    if(auto impl{_impl()}) {
        auto& i = extract(impl);
        i.free_swap_size = value;
        i.changes |= remote_host_change::sensor_values;
    }
    return *this;
}
//------------------------------------------------------------------------------
// node_connection
//------------------------------------------------------------------------------
inline auto node_connection::_impl() const noexcept
  -> const node_connection_impl* {
    return _pimpl.get();
}
//------------------------------------------------------------------------------
inline auto node_connection::_impl() noexcept -> node_connection_impl* {
    try {
        if(EAGINE_UNLIKELY(!_pimpl)) {
            _pimpl = std::make_shared<node_connection_impl>();
        }
        return _pimpl.get();
    } catch(...) {
    }
    return nullptr;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto node_connection::kind() const noexcept -> connection_kind {
    if(auto impl{_impl()}) {
        return extract(impl).kind;
    }
    return connection_kind::unknown;
}
//------------------------------------------------------------------------------
// node_connection_state
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto node_connection_state::set_kind(connection_kind kind)
  -> node_connection_state& {
    if(auto impl{_impl()}) {
        auto& i = extract(impl);
        if(i.kind != kind) {
            i.kind = kind;
            _tracker.get_node(_id1).add_change(
              remote_node_change::connection_info);
            _tracker.get_node(_id2).add_change(
              remote_node_change::connection_info);
        }
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
    std::vector<node_connection_state> connections;

    auto cached(const std::string& s) -> string_view {
        auto pos = _string_cache.find(s);
        if(pos == _string_cache.end()) {
            pos = _string_cache.insert(s).first;
        }
        return {*pos};
    }

private:
    std::set<std::string> _string_cache;
};
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
remote_node_tracker::remote_node_tracker()
  : _pimpl{std::make_shared<remote_node_tracker_impl>()} {}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_node_tracker::cached(const std::string& s) -> string_view {
    EAGINE_ASSERT(_pimpl);
    return _pimpl->cached(s);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_node_tracker::_get_nodes() noexcept
  -> flat_map<identifier_t, remote_node_state>& {
    EAGINE_ASSERT(_pimpl);
    return _pimpl->nodes;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_node_tracker::_get_hosts() noexcept
  -> flat_map<host_id_t, remote_host_state>& {
    EAGINE_ASSERT(_pimpl);
    return _pimpl->hosts;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_node_tracker::_get_connections() noexcept
  -> std::vector<node_connection_state>& {
    EAGINE_ASSERT(_pimpl);
    return _pimpl->connections;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_node_tracker::_get_connections() const noexcept
  -> const std::vector<node_connection_state>& {
    EAGINE_ASSERT(_pimpl);
    return _pimpl->connections;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_node_tracker::get_node(identifier_t node_id) -> remote_node_state& {
    EAGINE_ASSERT(_pimpl);
    EAGINE_ASSERT(node_id != 0U);
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
    if(_pimpl) {
        auto pos = _pimpl->hosts.find(host_id);
        if(pos != _pimpl->hosts.end()) {
            return pos->second;
        }
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
    if(_pimpl) {
        auto pos = _pimpl->instances.find(instance_id);
        if(pos != _pimpl->instances.end()) {
            return pos->second;
        }
    }
    return {};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_node_tracker::get_connection(
  identifier_t node_id1,
  identifier_t node_id2) -> node_connection_state& {
    EAGINE_ASSERT(_pimpl);
    for(auto& conn : _pimpl->connections) {
        if(conn.connects(node_id1, node_id2)) {
            return conn;
        }
    }
    _pimpl->connections.emplace_back(node_id1, node_id2, _pimpl);
    get_node(node_id1).add_change(remote_node_change::connection_info);
    get_node(node_id2).add_change(remote_node_change::connection_info);
    return _pimpl->connections.back();
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_node_tracker::get_connection(
  identifier_t node_id1,
  identifier_t node_id2) const -> node_connection_state {
    if(_pimpl) {
        for(auto& conn : _pimpl->connections) {
            if(conn.connects(node_id1, node_id2)) {
                return conn;
            }
        }
    }
    return {};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto remote_node_tracker::notice_instance(
  identifier_t node_id,
  process_instance_id_t instance_id) -> remote_node_state& {
    auto& node = get_node(node_id);
    if(const auto node_inst{node.instance_id()}) {
        // if node instance changed
        if(extract(node_inst) != instance_id) {
            // clear the node state
            node.clear();
            // remove connection info
            auto& connections = _get_connections();
            connections.erase(
              std::remove_if(
                connections.begin(),
                connections.end(),
                [=](const auto& conn) { return conn.connects(node_id); }),
              connections.end());
        } else {
            get_instance(instance_id).notice_alive();
        }
    } else {
        node.set_instance_id(instance_id);
    }
    return node.notice_alive();
}
//------------------------------------------------------------------------------
} // namespace eagine::msgbus
