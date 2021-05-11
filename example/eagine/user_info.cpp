/// @example eagine/user_info.cpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <eagine/main.hpp>
#include <eagine/user_info.hpp>
#include <iostream>

namespace eagine {

auto main(main_ctx& ctx) -> int {
    const std::string na{"N/A"};

    auto& usr = ctx.user();

    std::cout << "login name: " << extract_or(usr.login_name(), na)
              << std::endl;
    std::cout << "home dir: " << extract_or(usr.home_dir_path(), na)
              << std::endl;

    return 0;
}

} // namespace eagine
