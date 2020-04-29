/**
 *  example combined/001_clear/example.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include <oglplus/gl.hpp>
#include <oglplus/gl_api.hpp>

#include "../example.hpp"

namespace eagine {
//------------------------------------------------------------------------------
class example_clear : public example {
public:
    bool check_requirements(const example_context& ctx) final;
    void resize(const example_context& ctx) final;
    void render(const example_context& ctx) final;
};
//------------------------------------------------------------------------------
// example_clear
//------------------------------------------------------------------------------
bool example_clear::check_requirements(const example_context& ctx) {
    const auto& [gl, GL] = ctx.gl();
    auto r = ctx.req_mark();

    return r(gl.viewport) && r(gl.clear_color) && r(gl.clear) &&
           r(GL.color_buffer_bit);
}
//------------------------------------------------------------------------------
void example_clear::resize(const example_context& ctx) {
    ctx.gl().viewport(ctx.state().width(), ctx.state().height());
}
//------------------------------------------------------------------------------
void example_clear::render(const example_context& ctx) {
    const auto& [gl, GL] = ctx.gl();

    int sec = int(ctx.state().exec_time());

    gl.clear_color(
      (sec % 3 == 0) ? 1.f : 0.f,
      (sec % 3 == 1) ? 1.f : 0.f,
      (sec % 3 == 2) ? 1.f : 0.f,
      0.0f);

    gl.clear(GL.color_buffer_bit);
}
//------------------------------------------------------------------------------
std::unique_ptr<example> make_example(
  const example_args&, const example_context&) {
    return {std::make_unique<example_clear>()};
}
//------------------------------------------------------------------------------
void adjust_params(example_params& params) {
    params.depth_buffer(false);
    params.stencil_buffer(false);
}
//------------------------------------------------------------------------------
bool is_example_param(const example_arg&) {
    return false;
}
//------------------------------------------------------------------------------
} // namespace eagine

