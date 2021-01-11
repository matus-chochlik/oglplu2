/**
 *  example eglplus/003_list_extensions.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include <eglplus/egl.hpp>
#include <eglplus/egl_api.hpp>
#include <iostream>
#include <vector>

auto main() -> int {
    using namespace eagine;
    using namespace eagine::eglp;

    egl_api egl;

    std::cout << "Device extensions: " << std::endl;
    if(ok dev_count{egl.query_devices.count()}) {
        std::vector<egl_types::device_type> devices;
        const auto n = std_size(dev_count.get());
        devices.resize(n);
        if(egl.query_devices(cover(devices))) {
            for(std::size_t d = 0; d < n; ++d) {
                std::cout << "  Device: " << d << std::endl;
                if(ok extensions = egl.get_device_extensions(devices[d])) {
                    for(auto name : extensions) {
                        std::cout << "    " << name << std::endl;
                    }
                } else {
                    std::cerr << "failed to get device extension list: "
                              << (!extensions).message() << std::endl;
                }
            }
        }
    }

    std::cout << std::endl;

    std::cout << "Generic extensions: " << std::endl;

    if(ok extensions = egl.get_extensions()) {
        for(auto name : extensions) {
            std::cout << "  " << name << std::endl;
        }
    } else {
        std::cerr << "failed to get extension list: " << (!extensions).message()
                  << std::endl;
    }

    std::cout << std::endl;

    if(egl.get_display) {
        if(ok display = egl.get_display()) {
            if(auto init_res = egl.initialize(display)) {
                auto do_cleanup = egl.terminate.raii(display);

                if(ok vendor = egl.query_string(display, egl.vendor)) {
                    std::cout << "Vendor:  " << vendor << std::endl;
                }

                if(ok version = egl.query_string(display, egl.version)) {
                    std::cout << "Version: " << version << std::endl;
                }

                std::cout << "Display extensions: " << std::endl;

                if(ok extensions = egl.get_extensions(display)) {
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
    }
    return 0;
}
