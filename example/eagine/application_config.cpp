/**
 *  @example eagine/application_config.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/application_config.hpp>
#include <eagine/main.hpp>
#include <iostream>

namespace eagine {

auto main(main_ctx& ctx) -> int {
    const std::string na{"N/A"};

    auto& cfg = ctx.config();
    std::string s;
    int i;

    if(cfg.fetch("value_1", s)) {
        std::cout << "string: " << s << std::endl;
    }

    if(cfg.fetch("value_2", s)) {
        std::cout << "string: " << s << std::endl;
    }

    if(cfg.fetch("section_a.subsection_b.value_c", i)) {
        std::cout << "integer: " << i << std::endl;
    }

    return 0;
}

} // namespace eagine
