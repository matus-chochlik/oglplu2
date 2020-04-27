/**
 *  .file oglplus/example/context.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
// clang-format off
#include <oglplus/gl.hpp>
#include <oglplus/gl_api.hpp>
// clang-format on
#include <eagine/branch_predict.hpp>
#include "context.hpp"
#include "state.hpp"
#include <iostream>

namespace eagine {
//------------------------------------------------------------------------------
static void example_context_gl_debug_message(
  oglp::gl_types::enum_type source,
  oglp::gl_types::enum_type type,
  oglp::gl_types::uint_type id,
  oglp::gl_types::enum_type severity,
  oglp::gl_types::sizei_type length,
  const oglp::gl_types::char_type* message,
  oglp::gl_types::const_void_ptr_type user_param) {
    if(EAGINE_LIKELY(user_param)) {
        auto log = *const_cast<logger*>(static_cast<const logger*>(user_param));

        log.debug(string_view(message, span_size(length)))
          .arg(EAGINE_ID(type), oglp::debug_output_type(type))
          .arg(EAGINE_ID(source), oglp::debug_output_source(source))
          .arg(EAGINE_ID(severity), oglp::debug_output_severity(severity))
          .arg(EAGINE_ID(id), id);
    }
}
//------------------------------------------------------------------------------
static inline auto init_gl_api(example_run_context&) {
    return std::make_shared<oglp::gl_api>();
}
//------------------------------------------------------------------------------
example_context::example_context(example_run_context& erc)
  : _log_root(EAGINE_ID(Example), erc.args.args())
  , _erc{erc}
  , _random{make_example_random_generator(_erc)}
  , _gl_ptr{init_gl_api(_erc)} {
    _cleanup.reserve(16);

    log().debug("created example context");
    if(erc.params.debugging_context()) {
        log().trace("installing GL debug handler");
        if(gl().DebugMessageCallback) {
            gl().DebugMessageCallback(
              example_context_gl_debug_message,
              static_cast<logger*>(&_log_root));
        }
    }
}
//------------------------------------------------------------------------------
example_context::~example_context() noexcept {
    if(_gl_ptr) {
        log().debug("destroying example context");
    }
}
//------------------------------------------------------------------------------
const example_state_view& example_context::state() const noexcept {
    return _erc.state;
}
//------------------------------------------------------------------------------
oglp::gl_api& example_context::gl() const noexcept {
    EAGINE_ASSERT(_gl_ptr);
    return *_gl_ptr;
}
//------------------------------------------------------------------------------
} // namespace eagine
