/**
 *  @example eagine/signal_switch.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/signal_switch.hpp>
#include <iostream>
#include <thread>

auto main() -> int {
    using namespace eagine;

    signal_switch done;

    int i = 0;

    std::cout << "wait 10 seconds or send INT or TERM signal to exit"
              << std::endl;

    while(!done) {
        std::this_thread::sleep_for(std::chrono::seconds(1));

        if(i++ >= 10) {
            std::raise(SIGINT);
        }
    }

    std::cout << "done" << std::endl;

    return 0;
}
