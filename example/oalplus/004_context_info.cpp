/// @example oalplus/004_context.cpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#include <oalplus/al.hpp>
#include <oalplus/al_api.hpp>
#include <oalplus/alc_api.hpp>
#include <iostream>

auto main() -> int {
    using namespace eagine;
    using namespace eagine::oalp;

    alc_api alc;

    if(ok device{alc.open_device()}) {
        auto cleanup_dev = alc.close_device.raii(device);

        if(ok context{alc.create_context(device)}) {
            auto cleanup_ctx = alc.destroy_context.raii(device, context);

            alc.MakeContextCurrent(context);

            al_api al;

            if(ok info{al.get_string(al.vendor)}) {
                std::cout << "Vendor: " << extract(info) << std::endl;
            }

            if(ok info{al.get_string(al.renderer)}) {
                std::cout << "Renderer: " << extract(info) << std::endl;
            }

            if(ok info{al.get_string(al.version)}) {
                std::cout << "Version: " << extract(info) << std::endl;
            }
        }
    }

    return 0;
}
