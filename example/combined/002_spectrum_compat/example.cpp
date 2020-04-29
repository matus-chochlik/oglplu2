/**
 *  example combined/002_spectrum_compat/example.cpp
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
class example_spectrum : public example {

public:
    bool check_requirements(const example_context& ctx) final;
    void init(example_context& ctx) final;
    void resize(const example_context& ctx) final;
    void render(const example_context& ctx) final;
};
//------------------------------------------------------------------------------
// example_spectrum
//------------------------------------------------------------------------------
bool example_spectrum::check_requirements(const example_context& ctx) {
    const auto& [gl, GL] = ctx.gl();
    auto r = ctx.req_mark();

    return r(gl.viewport) && r(gl.clear_color) && r(gl.clear) &&
           r(GL.color_buffer_bit) && r(gl.load_identity) && r(gl.ortho) &&
           r(gl.rotate_f) && r(gl.begin) && r(gl.end) && r(gl.vertex2f) &&
           r(gl.color3f) && r(GL.modelview) && r(GL.projection) &&
           r(GL.triangle_fan) && r(GL.line_loop);
}
//------------------------------------------------------------------------------
void example_spectrum::init(example_context& ctx) {
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
  const example_args&, const example_context&) {
    return std::make_unique<example_spectrum>();
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
} // namespace eagine
