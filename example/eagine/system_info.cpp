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
#include <eagine/units/unit/si/temperature.hpp>
#include <iostream>

namespace eagine {

auto main(main_ctx& ctx) -> int {
    const std::string na{"N/A"};

    auto& sys = ctx.system();

    std::cout << "hostname: " << extract_or(sys.hostname(), na) << std::endl;
    std::cout << "number of CPU cores: "
              << extract_or(sys.cpu_concurrent_threads(), 0) << std::endl;

    std::cout << "short time average load: "
              << extract_or(sys.short_average_load(), 0.0F) << std::endl;
    std::cout << "long time average load: "
              << extract_or(sys.long_average_load(), 0.0F) << std::endl;

    std::cout << "memory page size: " << extract_or(sys.memory_page_size(), 0)
              << std::endl;

    std::cout << "free RAM size: " << extract_or(sys.free_ram_size(), 0)
              << std::endl;
    std::cout << "total RAM size: " << extract_or(sys.total_ram_size(), 0)
              << std::endl;

    std::cout << "free swap size: " << extract_or(sys.free_swap_size(), 0)
              << std::endl;
    std::cout << "total swap size: " << extract_or(sys.total_swap_size(), 0)
              << std::endl;

    std::cout << "temperatures from " << sys.thermal_sensor_count()
              << " sensors: " << std::endl;

    for(span_size_t i = 0, n = sys.thermal_sensor_count(); i < n; ++i) {
        std::cout << "  " << i << ": ";
        if(auto opt_t_kelvin{sys.sensor_temperature(i)}) {
            const auto t_k{extract(opt_t_kelvin)};

            tagged_quantity<float, units::degree_celsius> t_c{t_k};
            std::cout << t_c.value() << "[°C], ";

            tagged_quantity<float, units::degree_fahrenheit> t_f{t_k};
            std::cout << t_f.value() << "[°F], ";

            std::cout << t_k.value() << "[K]";
        } else {
            std::cout << "N/A";
        }
        std::cout << std::endl;
    }

    std::cout << "state of " << sys.cooling_device_count()
              << " cooling devices: " << std::endl;

    for(span_size_t i = 0, n = sys.cooling_device_count(); i < n; ++i) {
        std::cout << "  " << i << ": ";
        if(auto opt_val{sys.cooling_device_state(i)}) {

            std::cout << extract(opt_val) * 100.F << "%";
        } else {
            std::cout << "N/A";
        }
        std::cout << std::endl;
    }

    return 0;
}

} // namespace eagine
