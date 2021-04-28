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

    std::cout << "architecture: "
              << extract_or(compiler.architecture_name(), na) << std::endl;
    std::cout << "compiler name: " << extract_or(compiler.name(), na)
              << std::endl;
    std::cout << "compiler version major: "
              << extract_or(compiler.version_major(), 0) << std::endl;
    std::cout << "compiler version minor: "
              << extract_or(compiler.version_minor(), 0) << std::endl;
    std::cout << "compiler version patch: "
              << extract_or(compiler.version_patch(), 0) << std::endl;

    std::cout << "version major: " << extract_or(build.version_major(), 0)
              << std::endl;
    std::cout << "version minor: " << extract_or(build.version_minor(), 0)
              << std::endl;
    std::cout << "version patch: " << extract_or(build.version_patch(), 0)
              << std::endl;

    return 0;
}

} // namespace eagine

