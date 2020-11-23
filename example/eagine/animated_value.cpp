/**
 *  @example eagine/animated_value.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/animated_value.hpp>
#include <eagine/progress_bar.hpp>
#include <chrono>
#include <iostream>
#include <random>
#include <thread>

auto main() -> int {
    using namespace eagine;

    std::mt19937 gen{std::random_device()()};
    std::uniform_real_distribution<float> dis{0.F, 1.F};
    std::normal_distribution<float> nrm{0.5F, 1.5F};

    animated_value<float, std::chrono::duration<float>> a, b;
    progress_bar pba, pbb;
    pba.set_min(0.F).set_max(1.F).set_width(20);
    pbb.set_min(0.F).set_max(1.F).set_width(20);

    using step_t = std::chrono::duration<float>;
    step_t step{0.020F};

    while(true) {
        if(a.is_done()) {
            a.set(dis(gen), step_t(math::clamp(nrm(gen), 0.5F, 1.5F)));
        }
        if(b.is_done()) {
            b.set(dis(gen), step_t(math::clamp(nrm(gen), 0.5F, 1.5F)));
        }
        std::cout << pba.update(a.update(step).get()).reformat().get()
                  << pbb.update(b.update(step).get()).reformat().get()
                  << std::endl;
        std::this_thread::sleep_for(step);
    }

    return 0;
}
