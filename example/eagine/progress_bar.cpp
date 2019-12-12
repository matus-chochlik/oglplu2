/**
 *  @example eagine/progress_bar.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/progress_bar.hpp>
#include <cmath>
#include <iostream>
#include <thread>

int main() {
    using namespace eagine;

    float x = 0.f;

    progress_bar pb;
    while(true) {
        std::cout << pb.update(std::sin(x)).reformat().get() << std::endl;
        x += 0.01f + 0.05f * (std::sin(1.618f * x) + 1.f);
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }

    return 0;
}
