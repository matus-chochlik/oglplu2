/**
 *  @file eagine/main.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_MAIN_HPP
#define EAGINE_MAIN_HPP

#include "main_ctx.hpp"

namespace eagine {

int main(main_ctx& ctx);

} // namespace eagine

// NOLINTNEXTLINE(misc-definitions-in-headers)
int main(int argc, const char** argv) {
    eagine::main_ctx ctx{argc, argv};
    return eagine::main(ctx);
}

#endif // EAGINE_MAIN_HPP
