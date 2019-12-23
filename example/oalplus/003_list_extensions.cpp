/**
 *  example oalplus/002_list_extensions.cpp
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
        if(auto get_result = alc.get_default_device_specifier()) {
            std::cout << "Default device: " << extract(get_result) << std::endl;
        }
    }

    if(alc.open_device && alc.close_device) {
        if(auto open_res = alc.open_device()) {
            auto& device = eagine::extract(open_res);
            // closes the device when going out of scope
            auto cleanup_dev = alc.close_device.raii(device);

            if(auto get_result = alc.get_extensions(device)) {
                for(auto name : extract(get_result)) {
                    std::cout << "  " << name << std::endl;
                }
            } else {
                std::cerr << "failed to get extension list: "
                          << get_result.message() << std::endl;
            }
        } else {
            std::cout << "missing required API function." << std::endl;
        }
    }
    return 0;
}
