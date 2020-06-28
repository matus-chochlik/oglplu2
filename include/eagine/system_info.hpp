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
#include "types.hpp"
#include "valid_if/nonnegative.hpp"
#include "valid_if/positive.hpp"
#include <chrono>
#include <thread>

namespace eagine {

class system_info {
public:
    std::chrono::duration<float> uptime() const noexcept;

    valid_if_positive<span_size_t> cpu_concurrent_threads() const noexcept {
        return {span_size(std::thread::hardware_concurrency())};
    }

    valid_if_nonnegative<float> short_average_load() const noexcept;
    valid_if_nonnegative<float> long_average_load() const noexcept;

    valid_if_positive<span_size_t> memory_page_size() const noexcept;

    valid_if_positive<span_size_t> free_ram_size() const noexcept;
    valid_if_positive<span_size_t> total_ram_size() const noexcept;
};

} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/system_info.inl>
#endif

#endif // EAGINE_SYSTEM_INFO_HPP
