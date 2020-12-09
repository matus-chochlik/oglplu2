/**
 *  @file eagine/application/main.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_APPLICATION_MAIN_HPP
#define EAGINE_APPLICATION_MAIN_HPP

#include "../main.hpp"
#include "context.hpp"

namespace eagine {

auto main(main_ctx& ctx) -> int {
    return application::execution_context(ctx)
      .prepare(application::establish(ctx))
      .run()
      .result();
}

} // namespace eagine

#endif
