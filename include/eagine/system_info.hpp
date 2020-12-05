/**
 *  @file eagine/system_info.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_SYSTEM_INFO_HPP
#define EAGINE_SYSTEM_INFO_HPP

#include "config/basic.hpp"
#include "config/platform.hpp"
#include "main_ctx_object.hpp"
#include "quantities.hpp"
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

class system_info : public main_ctx_object {
public:
    system_info(main_ctx_parent parent) noexcept
      : main_ctx_object{EAGINE_ID(SystemInfo), parent} {}

    auto preinitialize() noexcept -> system_info&;

    using host_id_type = std::uint32_t;

    auto host_id() noexcept -> valid_if_positive<host_id_type>;

    auto hostname() noexcept -> valid_if_not_empty<std::string>;

    auto uptime() noexcept -> std::chrono::duration<float>;

    auto cpu_concurrent_threads() noexcept -> valid_if_positive<span_size_t> {
        return {span_size(std::thread::hardware_concurrency())};
    }

    auto current_processes() noexcept -> valid_if_positive<span_size_t>;

    auto short_average_load() noexcept -> valid_if_nonnegative<float>;
    auto long_average_load() noexcept -> valid_if_nonnegative<float>;

    auto memory_page_size() noexcept -> valid_if_positive<span_size_t>;

    auto free_ram_size() noexcept -> valid_if_positive<span_size_t>;
    auto total_ram_size() noexcept -> valid_if_positive<span_size_t>;

    auto free_swap_size() noexcept -> valid_if_nonnegative<span_size_t>;
    auto total_swap_size() noexcept -> valid_if_nonnegative<span_size_t>;

    auto thermal_sensor_count() noexcept -> span_size_t;
    auto sensor_temperature(span_size_t) noexcept
      -> valid_if_positive<kelvins_t<float>>;
    auto cpu_temperature() noexcept -> valid_if_positive<kelvins_t<float>>;
    auto gpu_temperature() noexcept -> valid_if_positive<kelvins_t<float>>;

    auto cooling_device_count() noexcept -> span_size_t;
    auto cooling_device_state(span_size_t) noexcept
      -> valid_if_between_0_1<float>;

    auto battery_count() noexcept -> span_size_t;
    auto battery_capacity(span_size_t) noexcept -> valid_if_between_0_1<float>;

private:
    std::shared_ptr<system_info_impl> _pimpl;
    auto _impl() noexcept -> system_info_impl*;
};

} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/system_info.inl>
#endif

#endif // EAGINE_SYSTEM_INFO_HPP
