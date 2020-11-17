/**
 *  @example eagine/version.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/main.hpp>
#include <iostream>

namespace eagine {

auto main(main_ctx& ctx) -> int {

    if(auto opt_version{ctx.version()}) {
        const auto [major, minor, patch, commit] = extract(opt_version);

        std::cout << "version " << major << '.' << minor << '.' << patch << '-'
                  << commit << std::endl;
    }

    if(ctx.version_at_least(0, 37, 2, 15)) {
        std::cout << "version recent enough" << std::endl;
    }

    return 0;
}

} // namespace eagine
