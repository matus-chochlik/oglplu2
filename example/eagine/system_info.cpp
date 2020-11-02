/**
 *  @example eagine/system_info.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/main.hpp>
#include <eagine/system_info.hpp>
#include <iostream>

namespace eagine {

auto main(main_ctx& ctx) -> int {
    const std::string na{"N/A"};

    std::cout << "hostname: " << extract_or(ctx.system().hostname(), na)
              << std::endl;
    std::cout << "number of CPU cores: "
              << extract_or(ctx.system().cpu_concurrent_threads(), 0)
              << std::endl;

    std::cout << "short time average load: "
              << extract_or(ctx.system().short_average_load(), 0.0F)
              << std::endl;
    std::cout << "long time average load: "
              << extract_or(ctx.system().long_average_load(), 0.0F)
              << std::endl;

    std::cout << "memory page size: "
              << extract_or(ctx.system().memory_page_size(), 0) << std::endl;

    std::cout << "free RAM size: "
              << extract_or(ctx.system().free_ram_size(), 0) << std::endl;
    std::cout << "total RAM size: "
              << extract_or(ctx.system().total_ram_size(), 0) << std::endl;

    std::cout << "free swap size: "
              << extract_or(ctx.system().free_swap_size(), 0) << std::endl;
    std::cout << "total swap size: "
              << extract_or(ctx.system().total_swap_size(), 0) << std::endl;

    std::cout
      << "CPU temperature [K]: "
      << extract_or(ctx.system().cpu_temperature(), kelvins_(0.F)).value()
      << std::endl;

    return 0;
}

} // namespace eagine
