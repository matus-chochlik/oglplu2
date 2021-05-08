/// @example eagine/dyn_lib_lookup.cpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#include <eagine/dynamic_library.hpp>
#include <eagine/logging/logger.hpp>
#include <eagine/main.hpp>
#include <iostream>

namespace eagine {

auto main(main_ctx& ctx) -> int {

    if(string_view lib_path{ctx.args().find("--library").next()}) {
        if(shared_executable_module module{lib_path}) {
            if(string_view sym_name{ctx.args().find("--symbol").next()}) {
                if(module.exports(sym_name)) {
                    std::cout << "symbol found" << std::endl;
                } else {
                    std::cout << "symbol not found" << std::endl;
                }
            } else {
                ctx.log().error("missing symbol name argument");
            }
        } else {
            ctx.log()
              .error("failed to open ${lib}: ${message}")
              .arg(EAGINE_ID(lib), lib_path)
              .arg(EAGINE_ID(message), module.error_message());
        }
    } else {
        ctx.log().error("missing library path argument");
    }

    return 0;
}

} // namespace eagine
