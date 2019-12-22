/**
 *  example oalplus/004_context.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include <oalplus/al.hpp>
#include <oalplus/al_api.hpp>
#include <oalplus/alc_api.hpp>
#include <iostream>

int main() {
    using namespace eagine;
    using namespace eagine::oalp;

    alc_api alc;

    if(auto open_dev_res = alc.open_device()) {
        auto& device = eagine::extract(open_dev_res);
        auto cleanup_dev = alc.close_device_raii(device);

        if(auto crt_ctx_res = alc.create_context(device)) {
            auto& context = extract(crt_ctx_res);
            auto cleanup_ctx = alc.destroy_context_raii(device, context);

            alc.MakeContextCurrent(context);

            al_api al;

            if(auto opt_info = al.get_string(al.vendor)) {
                std::cout << "Vendor: " << extract(opt_info) << std::endl;
            }

            if(auto opt_info = al.get_string(al.renderer)) {
                std::cout << "Renderer: " << extract(opt_info) << std::endl;
            }

            if(auto opt_info = al.get_string(al.version)) {
                std::cout << "Version: " << extract(opt_info) << std::endl;
            }
        }
    }

    return 0;
}
