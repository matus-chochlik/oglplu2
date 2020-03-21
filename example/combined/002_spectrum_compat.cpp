/**
 *  example oglplus/002_spectrum_compat.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

// clang-format off
#include <oglplus/gl.hpp>
#include <oglplus/gl_api.hpp>

#include "example.hpp"
// clang-format on
#include <iostream>

namespace eagine {
namespace oglp {
//------------------------------------------------------------------------------
class example_spectrum : public example {

public:
    example_spectrum(const example_context& ctx);

    void resize(const example_context& ctx) final;

    void render(const example_context& ctx) final;
};
//------------------------------------------------------------------------------
example_spectrum::example_spectrum(const example_context& ctx) {
    const auto& gl = ctx.gl();
    gl.clear_color(0.4f, 0.4f, 0.4f, 0.0f);
}
//------------------------------------------------------------------------------
void example_spectrum::resize(const example_context& ctx) {
    const auto& state = ctx.state();
    const auto& [gl, GL] = ctx.gl();

    gl.viewport(state.width(), state.height());

    const auto h = GL.double_(2);
    const auto w = h * GL.double_(state.aspect());

    gl.matrix_mode(GL.projection);
    gl.load_identity();
    gl.ortho(-w, +w, -h, +h, 0, 1);
}
//------------------------------------------------------------------------------
void example_spectrum::render(const example_context& ctx) {
    const auto& [gl, GL] = ctx.gl();
    gl.clear(GL.color_buffer_bit);

    gl.matrix_mode(GL.modelview);
    gl.load_identity();
    gl.rotate_f(degrees_(ctx.state().exec_time().value() * 90), 0, 0, 1);

    gl.begin(GL.triangle_fan);

    gl.color3f(0.5f, 0.5f, 0.5f);
    gl.vertex2f(0.000f, 0.000f);

    gl.color3f(1.0f, 0.0f, 0.0f);
    gl.vertex2f(0.000f, 1.000f);

    gl.color3f(1.0f, 0.7f, 0.0f);
    gl.vertex2f(0.707f, 0.707f);

    gl.color3f(0.7f, 1.0f, 0.0f);
    gl.vertex2f(1.000f, 0.000f);

    gl.color3f(0.0f, 1.0f, 0.0f);
    gl.vertex2f(0.707f, -0.707f);

    gl.color3f(0.0f, 1.0f, 0.7f);
    gl.vertex2f(0.000f, -1.000f);

    gl.color3f(0.0f, 0.7f, 1.0f);
    gl.vertex2f(-0.707f, -0.707f);

    gl.color3f(0.0f, 0.0f, 1.0f);
    gl.vertex2f(-1.000f, 0.000f);

    gl.color3f(0.7f, 0.0f, 0.7f);
    gl.vertex2f(-0.707f, 0.707f);

    gl.color3f(1.0f, 0.0f, 0.0f);
    gl.vertex2f(0.000f, 1.000f);

    gl.end();

    gl.begin(GL.line_loop);

    gl.color3f(0, 0, 0);

    gl.vertex2f(0.000f, 1.000f);
    gl.vertex2f(0.707f, 0.707f);
    gl.vertex2f(1.000f, 0.000f);
    gl.vertex2f(0.707f, -0.707f);
    gl.vertex2f(0.000f, -1.000f);
    gl.vertex2f(-0.707f, -0.707f);
    gl.vertex2f(-1.000f, 0.000f);
    gl.vertex2f(-0.707f, 0.707f);
    gl.vertex2f(0.000f, 1.000f);

    gl.end();
}
//------------------------------------------------------------------------------
std::unique_ptr<example> make_example(
  const example_args&, const example_context& ctx) {
    return std::make_unique<example_spectrum>(ctx);
}
//------------------------------------------------------------------------------
void adjust_params(example_params& params) {
    params.compatibility_context(true);
    params.depth_buffer(false);
    params.stencil_buffer(false);
}
//------------------------------------------------------------------------------
bool is_example_param(const example_arg&) {
    return false;
}
//------------------------------------------------------------------------------
} // namespace oglp
} // namespace eagine