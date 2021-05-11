/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef EAGINE_SYSTEM_INFO_HPP
#define EAGINE_SYSTEM_INFO_HPP

#include "config/basic.hpp"
#include "config/platform.hpp"
#include "integer_range.hpp"
#include "main_ctx_object.hpp"
#include "power_supply_kind.hpp"
#include "quantities.hpp"
#include "tribool.hpp"
#include "types.hpp"
#include "valid_if/ge0_le1.hpp"
#include "valid_if/nonnegative.hpp"
#include "valid_if/not_empty.hpp"
#include "valid_if/positive.hpp"
#include <chrono>
#include <cstdint>
#include <memory>
#include <string>
#include <thread>

namespace eagine {

class system_info_impl;

/// @brief Class providing basic system information.
/// @ingroup main_context
class system_info : public main_ctx_object {
public:
    /// @brief Alias for host id type.
    using host_id_type = std::uint32_t;

    system_info(main_ctx_parent parent) noexcept
      : main_ctx_object{EAGINE_ID(SystemInfo), parent} {}

    /// @brief Do potentially expensive pre-initialization and caching.
    auto preinitialize() noexcept -> system_info&;

    /// @brief Returns a unique numeric id of this host computer.
    auto host_id() noexcept -> valid_if_positive<host_id_type>;

    /// @brief Returns the hostname.
    auto hostname() noexcept -> valid_if_not_empty<std::string>;

    /// @brief Returns the system uptime.
    auto uptime() noexcept -> std::chrono::duration<float>;

    /// @brief Returns the number of threads that can run concurrently.
    auto cpu_concurrent_threads() noexcept -> valid_if_positive<span_size_t> {
        return {span_size(std::thread::hardware_concurrency())};
    }

    /// @brief Returns the number of running processes.
    auto current_processes() noexcept -> valid_if_positive<span_size_t>;

    /// @brief Returns the short-term average system load in range (0.0, 1.0).
    auto short_average_load() noexcept -> valid_if_nonnegative<float>;

    /// @brief Returns the long-term average system load in range (0.0, 1.0).
    auto long_average_load() noexcept -> valid_if_nonnegative<float>;

    /// @brief Returns the memory page size on this system.
    auto memory_page_size() noexcept -> valid_if_positive<span_size_t>;

    /// @brief Returns free RAM size.
    auto free_ram_size() noexcept -> valid_if_positive<span_size_t>;

    /// @brief Returns total RAM size.
    auto total_ram_size() noexcept -> valid_if_positive<span_size_t>;

    /// @brief Returns free swap size.
    auto free_swap_size() noexcept -> valid_if_nonnegative<span_size_t>;

    /// @brief Returns total swap size.
    auto total_swap_size() noexcept -> valid_if_nonnegative<span_size_t>;

    /// @brief Returns the number of system thermal sensors.
    auto thermal_sensor_count() noexcept -> span_size_t;

    /// @brief Returns the temperature on the i-th thermal sensor.
    auto sensor_temperature(span_size_t) noexcept
      -> valid_if_positive<kelvins_t<float>>;

    /// @brief Returns the temperature on the CPU thermal sensor if present.
    auto cpu_temperature() noexcept -> valid_if_positive<kelvins_t<float>>;

    /// @brief Returns the temperature on the GPU thermal sensor if present.
    auto gpu_temperature() noexcept -> valid_if_positive<kelvins_t<float>>;

    /// @brief Returns the number of cooling devices.
    auto cooling_device_count() noexcept -> span_size_t;

    /// @brief Returns the state of the i-th cooling device.
    auto cooling_device_state(span_size_t) noexcept
      -> valid_if_between_0_1<float>;

    /// @brief Returns the count of batteries in the system.
    auto battery_count() noexcept -> span_size_t;

    /// @brief Returns the capacity of the i-th battery.
    auto battery_capacity(span_size_t) noexcept -> valid_if_between_0_1<float>;

    /// @brief Returns the count of AC power supplies in the system.
    auto ac_supply_count() noexcept -> span_size_t;

    /// @brief Indicates whether the i-th power supply is online
    auto ac_supply_online(span_size_t) noexcept -> tribool;

    /// @brief Returns the currently user power supply kind.
    auto power_supply() noexcept -> power_supply_kind {
        for(const auto i : integer_range(ac_supply_count())) {
            if(ac_supply_online(i)) {
                return power_supply_kind::ac_supply;
            }
        }
        for(const auto i : integer_range(battery_count())) {
            if(battery_capacity(i) > 0.F) {
                return power_supply_kind::battery;
            }
        }
        return power_supply_kind::unknown;
    }

private:
    std::shared_ptr<system_info_impl> _pimpl;
    auto _impl() noexcept -> system_info_impl*;
};

} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/system_info.inl>
#endif

#endif // EAGINE_SYSTEM_INFO_HPP
