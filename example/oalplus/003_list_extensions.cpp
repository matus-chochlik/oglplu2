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
        if(ok name{alc.get_default_device_specifier()}) {
            std::cout << "Default device: " << name.get() << std::endl;
        }
    }

    if(alc.open_device && alc.close_device) {
        if(ok device{alc.open_device()}) {
            // closes the device when going out of scope
            auto cleanup_dev = alc.close_device.raii(device);

            if(ok extensions{alc.get_extensions(device)}) {
                for(auto name : extensions) {
                    std::cout << "  " << name << std::endl;
                }
            } else {
                std::cerr << "failed to get extension list: "
                          << (!extensions).message() << std::endl;
            }
        } else {
            std::cout << "missing required API function." << std::endl;
        }
    }
    return 0;
}
