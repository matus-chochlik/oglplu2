/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef EAGINE_MAIN_FWD_HPP
#define EAGINE_MAIN_FWD_HPP

#include "main_ctx_fwd.hpp"

namespace eagine {

struct main_ctx_options;

#if !EAGINE_IMPLEMENTING_LIBRARY
extern auto main_impl(int, const char**, const main_ctx_options&) -> int;
#endif

} // namespace eagine

#endif // EAGINE_MAIN_FWD_HPP
