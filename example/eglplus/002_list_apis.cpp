/**
 *  example eglplus/002_list_extensions.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include <eglplus/egl.hpp>
#include <eglplus/egl_api.hpp>
#include <iostream>

int main() {
    using namespace eagine;
    using namespace eagine::eglp;

    egl_api egl;

    if(egl.get_display) {
        if(ok display = egl.get_display()) {
            if(auto init_res = egl.initialize(display)) {
                auto do_cleanup = egl.terminate.raii(display);

                std::cout << "Supported APIs:" << std::endl;

                if(ok apis = egl.get_client_apis(display)) {
                    for(auto name : apis) {
                        std::cout << "  " << name << std::endl;
                    }
                } else {
                    std::cerr << "failed to get API list: " << (!apis).message()
                              << std::endl;
                }
            } else {
                std::cout << "missing required API function." << std::endl;
            }
        }
    }
    return 0;
}
