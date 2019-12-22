/**
 *  example oalplus/003_list_devices.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include <oalplus/al.hpp>
#include <oalplus/alc_api.hpp>
#include <iostream>

int main() {
    using namespace eagine;
    using namespace eagine::oalp;

    alc_api alc;

    if(alc.get_string) {
        std::cout << "Playback devices:" << std::endl;
        if(auto get_result = alc.get_device_specifiers()) {
            for(auto name : extract(get_result)) {
                std::cout << "  " << name << std::endl;
            }
        } else {
            std::cerr << "failed to list playback devices: "
                      << get_result.message() << std::endl;
        }
    } else {
        std::cout << "missing required API function: " << alc.get_string.name()
                  << std::endl;
    }

    if(alc.get_string) {
        std::cout << "Capture devices:" << std::endl;
        if(auto get_result = alc.get_capture_device_specifiers()) {
            for(auto name : extract(get_result)) {
                std::cout << "  " << name << std::endl;
            }
        } else {
            std::cerr << "failed to list capture devices: "
                      << get_result.message() << std::endl;
        }
        std::cout << "missing required API function: " << alc.get_string.name()
                  << std::endl;
    }

    return 0;
}
