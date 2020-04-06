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
#include "context.hpp"
#include "state.hpp"
#include <iostream>

namespace eagine {
//------------------------------------------------------------------------------
/* TODO
static inline void print_debug_message(
  debug_output_source,
  debug_output_type,
  GLuint source_id,
  debug_output_severity,
  string_view message) {
    // TODO: prettier output
    std::cerr << source_id << ": ";
    std::cerr << '"' << message << '"';
    std::cerr << std::endl;
}
*/
//------------------------------------------------------------------------------
static inline auto init_gl_api(example_args&, example_params&, example_state&) {
    return std::make_shared<oglp::gl_api>();
}
//------------------------------------------------------------------------------
example_context::example_context(
  example_args& args, example_params& params, example_state& state)
  : _params{params}
  , _state{state}
  , _random{make_example_random_generator(args, params)}
  , _gl_ptr{init_gl_api(args, params, state)} {
    _cleanup.reserve(16);
    /* TODO
  if(_debug) {
      _debug->set_notification_marker("created example context");
  }
  */
}
//------------------------------------------------------------------------------
example_context::~example_context() noexcept {
    if(_gl_ptr) {
        /*
        if(_debug) {
            _debug->set_notification_marker("destroying example context");
        }
        */
    }
}
//------------------------------------------------------------------------------
const example_state_view& example_context::state() const noexcept {
    return _state;
}
//------------------------------------------------------------------------------
oglp::gl_api& example_context::gl() const noexcept {
    EAGINE_ASSERT(_gl_ptr);
    return *_gl_ptr;
}
//------------------------------------------------------------------------------
const example_context& example_context::debug_notification(
  string_view message) const {
    (void)message;
    /* TODO
    if(_debug) {
        _debug->set_notification_marker(message);
    }
    */
    return *this;
}
//------------------------------------------------------------------------------
} // namespace eagine
