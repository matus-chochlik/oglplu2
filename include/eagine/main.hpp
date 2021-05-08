/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef EAGINE_MAIN_HPP
#define EAGINE_MAIN_HPP

#include "config/basic.hpp"
#include "main_ctx.hpp"
#include "main_fwd.hpp"

#ifndef EAGINE_IMPLEMENTING_LIBRARY
// NOLINTNEXTLINE(misc-definitions-in-headers)
auto main(int argc, const char** argv) -> int {
    eagine::main_ctx_options options;
    return eagine::main_impl(argc, argv, options);
}
#endif

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/main.inl>
#endif

#endif // EAGINE_MAIN_HPP
