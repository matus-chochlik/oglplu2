/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef EAGINE_MAIN_CTX_FWD_HPP
#define EAGINE_MAIN_CTX_FWD_HPP

#include "logging/fwd.hpp"

namespace eagine {

class application_config;
class master_ctx;
class main_ctx;
class main_ctx_log_backend_getter;
class main_ctx_object;
class main_ctx_object_parent_info;

using main_ctx_parent = const main_ctx_object_parent_info&;

} // namespace eagine

#endif // EAGINE_MAIN_CTX_FWD_HPP
