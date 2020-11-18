/**
 *  @file eagine/main_ctx_object.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/main_ctx.hpp>

namespace eagine {
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
main_ctx_log_backend_getter::main_ctx_log_backend_getter() noexcept
  : _backend{main_ctx::get().log().backend()} {}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto main_ctx_object::context() const noexcept -> main_ctx& {
    return main_ctx::get();
}
//------------------------------------------------------------------------------
} // namespace eagine
