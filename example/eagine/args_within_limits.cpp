/**
 *  @example eagine/args_within_limits.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/args_within_limits.hpp>
#include <iostream>

static inline auto add(short l, short r) {
    return l + r;
}

struct mul {
    inline auto apply(int l, int r) const noexcept {
        return l * r;
    }
};

auto main() -> int {
    using namespace eagine;

    if(args_within_limits(&add, 123, 456)) {
        std::cout << "can call function" << std::endl;
    }

    if(!args_within_limits(&add, 123456, 789)) {
        std::cout << "arguments out of range" << std::endl;
    }

    if(args_within_limits(&mul::apply, 123456, 789012)) {
        std::cout << "can call function" << std::endl;
    }

    if(!args_within_limits(&mul::apply, 12345678901234L, 789012)) {
        std::cout << "arguments out of range" << std::endl;
    }

    return 0;
}
