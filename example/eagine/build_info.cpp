/// @example eagine/build_info.cpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <eagine/main.hpp>
#include <iostream>

namespace eagine {

auto main(main_ctx& ctx) -> int {
    const std::string na{"N/A"};

    auto& compiler = ctx.compiler();
    auto& build = ctx.build();

    std::cout << "architecture: " << either_or(compiler.architecture_name(), na)
              << std::endl;
    std::cout << "compiler name: " << either_or(compiler.name(), na)
              << std::endl;
    std::cout << "compiler version major: "
              << either_or(compiler.version_major(), na) << std::endl;
    std::cout << "compiler version minor: "
              << either_or(compiler.version_minor(), na) << std::endl;
    std::cout << "compiler version patch: "
              << either_or(compiler.version_patch(), na) << std::endl;

    std::cout << "version major: " << either_or(build.version_major(), na)
              << std::endl;
    std::cout << "version minor: " << either_or(build.version_minor(), na)
              << std::endl;
    std::cout << "version patch: " << either_or(build.version_patch(), na)
              << std::endl;

    return 0;
}

} // namespace eagine

