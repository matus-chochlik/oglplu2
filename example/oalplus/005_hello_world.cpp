/**
 *  example oalplus/005_hello_world.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include <oalplus/al.hpp>
#include <oalplus/al_api.hpp>
#include <oalplus/alc_api.hpp>
#include <oalplus/alut_api.hpp>
#include <iostream>

int main(int argc, char** argv) {
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
            alut_api alut;

            if(alut.init(&argc, argv)) {
                auto do_exit = alut.exit_raii();
                if(auto opt_hello = alut.create_buffer_hello_world()) {
                    // TODO: finish this
                    std::cerr << "this example is work in progress."
                              << std::endl;

                    al.delete_buffers(extract(opt_hello));
                }
            }
        }
    }

    return 0;
}
