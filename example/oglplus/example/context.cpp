/**
 *  .file oglplus/example/camera.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
// clang-format off
#include <oglplus/gl.hpp>
#include <oglplus/debug_output.hpp>
// clang-format on
#include "context.hpp"
#include "state.hpp"
#include <iostream>

namespace oglplus {
//------------------------------------------------------------------------------
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
//------------------------------------------------------------------------------
static inline std::shared_ptr<debug_output> make_debug_output(
  example_args&, example_params& params, example_state&) {
    if(params.debugging_context()) {
        return std::make_shared<debug_output>(&print_debug_message);
    }
    return {};
}
//------------------------------------------------------------------------------
example_context::example_context(
  example_args& args, example_params& params, example_state& state)
  : _params{params}
  , _state{state}
  , _debug{make_debug_output(args, params, state)} {
    if(_debug) {
        _debug->set_notification_marker("created example context");
    }
}
//------------------------------------------------------------------------------
example_context::~example_context() noexcept {
    if(_debug) {
        _debug->set_notification_marker("destroying example context");
    }
}
//------------------------------------------------------------------------------
const example_state_view& example_context::state() const noexcept {
    return _state;
}
//------------------------------------------------------------------------------
const example_context& example_context::debug_notification(
  string_view message) const {
    if(_debug) {
        _debug->set_notification_marker(message);
    }
    return *this;
}
//------------------------------------------------------------------------------
} // namespace oglplus
