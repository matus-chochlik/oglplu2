/// @example eglplus/005_list_configs.cpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#include <eglplus/egl.hpp>
#include <eglplus/egl_api.hpp>
#include <iomanip>
#include <iostream>
#include <vector>

auto main() -> int {
    using namespace eagine;
    using namespace eagine::eglp;

    egl_api egl;

    if(egl.get_display) {
        if(ok display = egl.get_display()) {
            if(auto init_res = egl.initialize(display)) {
                auto do_cleanup = egl.terminate.raii(display);

                if(ok count = egl.get_configs.count(display)) {

                    std::vector<egl_api::config_type> configs(count);

                    std::cout << "found " << configs.size()
                              << " configs:" << std::endl;

                    for(auto config : extract_or(
                          egl.get_configs(display, cover(configs)),
                          span<egl_api::config_type>{})) {

                        auto print_info =
                          [&](const char* pref, auto attr, const char* suff) {
                              std::cout << pref << std::setw(2)
                                        << extract_or(
                                             egl.get_config_attrib(
                                               display, config, attr),
                                             -1)
                                        << suff;
                          };
                        print_info("  ", egl.config_id, ": ");
                        print_info("R:", egl.red_size, "|");
                        print_info("G:", egl.green_size, "|");
                        print_info("B:", egl.blue_size, "|");
                        print_info("A:", egl.alpha_size, "|");
                        print_info("L:", egl.luminance_size, "|");
                        print_info("D:", egl.depth_size, "|");
                        print_info("S:", egl.stencil_size, "|");
                        print_info("Sam:", egl.samples, "|");

                        std::cout << std::endl;
                    }
                }
            }
        }
    } else {
        std::cerr << "missing required API" << std::endl;
    }
    return 0;
}
