/**
 *  @example eagine/uptime.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/main.hpp>
#include <iostream>

namespace eagine {

int main(main_ctx& ctx) {

    const string_view n_a("N/A");
    auto& sys = ctx.system();
    ctx.log()
      .stat("system stats")
      .arg(
        EAGINE_ID(shtLoadAvg),
        EAGINE_ID(Ratio),
        either_or(sys.short_average_load(), n_a))
      .arg(
        EAGINE_ID(lngLoadAvg),
        EAGINE_ID(Ratio),
        either_or(sys.long_average_load(), n_a))
      .arg(EAGINE_ID(uptime), sys.uptime());

    return 0;
}

} // namespace eagine
