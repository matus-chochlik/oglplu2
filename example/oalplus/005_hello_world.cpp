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
#include <oalplus/alc_api/context_attribs.hpp>
#include <oalplus/alut_api.hpp>
#include <iostream>
#include <thread>

auto main(int argc, char** argv) -> int {
    using namespace eagine;
    using namespace eagine::oalp;

    alc_api alc;

    if(ok device{alc.open_device()}) {
        auto cleanup_dev = alc.close_device.raii(device);

        const auto context_attribs = (alc.mono_sources | 1) +
                                     (alc.stereo_sources | 1) +
                                     (alc.sync | false);

        if(ok context{alc.create_context(device, context_attribs.get())}) {
            auto cleanup_ctx = alc.destroy_context.raii(device, context);

            alc.make_context_current(context);
            auto reset_ctx = alc.make_context_current.raii();

            al_api al;
            alut_api alut;

            if(alut.init(&argc, argv)) {
                auto do_exit = alut.exit.raii();
                auto opt_src = al.gen_sources();
                auto del_src = al.delete_sources.raii_opt(opt_src);
                auto opt_buf = alut.create_buffer_hello_world();
                auto del_buf = al.delete_buffers.raii_opt(opt_buf);

                if(opt_src && opt_buf) {
                    source_name src = extract(opt_src);
                    buffer_name buf = extract(opt_buf);

                    al.listener_i(al.position, 0, 0, 0);
                    al.listener_i(al.velocity, 0, 0, 0);
                    al.listener_f(al.gain, 5.F);

                    al.source_f(src, al.position, 0.F, 0.F, 1.F);
                    al.source_f(src, al.velocity, 0.F, 0.F, 0.F);

                    al.source_queue_buffers(src, buf);
                    al.source_play(src);
                    std::this_thread::sleep_for(std::chrono::seconds(2));

                    al.source_unqueue_buffers(src, buf);
                }
            }
        }
    }

    return 0;
}
