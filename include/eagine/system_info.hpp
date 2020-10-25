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
#include "valid_if/not_empty.hpp"
#include "valid_if/positive.hpp"
#include <chrono>
#include <string>
#include <thread>

namespace eagine {

class system_info {
public:
    auto hostname() const -> valid_if_not_empty<std::string>;

    auto uptime() const noexcept -> std::chrono::duration<float>;

    auto cpu_concurrent_threads() const noexcept
      -> valid_if_positive<span_size_t> {
        return {span_size(std::thread::hardware_concurrency())};
    }

    auto short_average_load() const noexcept -> valid_if_nonnegative<float>;
    auto long_average_load() const noexcept -> valid_if_nonnegative<float>;

    auto memory_page_size() const noexcept -> valid_if_positive<span_size_t>;

    auto free_ram_size() const noexcept -> valid_if_positive<span_size_t>;
    auto total_ram_size() const noexcept -> valid_if_positive<span_size_t>;
};

} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/system_info.inl>
#endif

#endif // EAGINE_SYSTEM_INFO_HPP
